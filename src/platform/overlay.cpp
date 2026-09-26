// hh_overlay — render hook de RT64 (A2, Fase A). Ver include/hh/overlay.h.
//
// Dibuja el frame publicado por el menú: paneles solidos (textura 1x1 blanca) y texto con el atlas
// de la fuente del juego (`hh::font::game`, RGBA8 128x32). El overlay se presenta sobre el frame del
// juego ya compuesto por el VI renderer de RT64.
//
// Diagnostico: HH_OVERLAY=0 desactiva el overlay.

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

#include "rhi/rt64_render_hooks.h"

#include "hh.h"
#include "hh/font.h"
#include "hh/overlay.h"

#include "shaders/OverlayVS.hlsl.spirv.h"
#include "shaders/OverlayPS.hlsl.spirv.h"
#if defined(_WIN32)
#include "shaders/OverlayVS.hlsl.dxil.h"
#include "shaders/OverlayPS.hlsl.dxil.h"
#elif defined(__APPLE__)
#include "shaders/OverlayVS.hlsl.metal.h"
#include "shaders/OverlayPS.hlsl.metal.h"
#endif

#if defined(_WIN32)
#    define GET_SHADER_BLOB(name, format) \
        ((format) == RenderShaderFormat::SPIRV ? name##BlobSPIRV : \
        (format) == RenderShaderFormat::DXIL ? name##BlobDXIL : nullptr)
#    define GET_SHADER_SIZE(name, format) \
        ((format) == RenderShaderFormat::SPIRV ? std::size(name##BlobSPIRV) : \
        (format) == RenderShaderFormat::DXIL ? std::size(name##BlobDXIL) : 0)
#elif defined(__APPLE__)
#    define GET_SHADER_BLOB(name, format) \
        ((format) == RenderShaderFormat::SPIRV ? name##BlobSPIRV : \
        (format) == RenderShaderFormat::METAL ? name##BlobMSL : nullptr)
#    define GET_SHADER_SIZE(name, format) \
        ((format) == RenderShaderFormat::SPIRV ? std::size(name##BlobSPIRV) : \
        (format) == RenderShaderFormat::METAL ? std::size(name##BlobMSL) : 0)
#else
#    define GET_SHADER_BLOB(name, format) \
        ((format) == RenderShaderFormat::SPIRV ? name##BlobSPIRV : nullptr)
#    define GET_SHADER_SIZE(name, format) \
        ((format) == RenderShaderFormat::SPIRV ? std::size(name##BlobSPIRV) : 0)
#endif

namespace hh::overlay {
namespace {

using namespace plume;

// Decodifica el siguiente codepoint UTF-8 y avanza `i`. ASCII = 1 byte.
unsigned utf8_next_cp(const std::string& s, size_t& i) {
    unsigned c = static_cast<unsigned char>(s[i++]);
    if (c < 0x80) return c;
    const unsigned extra = (c >= 0xF0) ? 3u : (c >= 0xE0) ? 2u : 1u;
    unsigned cp = c & (0x3Fu >> extra);
    for (unsigned k = 0; k < extra && i < s.size(); ++k) {
        cp = (cp << 6) | (static_cast<unsigned char>(s[i++]) & 0x3Fu);
    }
    return cp;
}

constexpr RenderFormat kSwapChainFormat = RenderFormat::B8G8R8A8_UNORM;
constexpr RenderFormat kTextureFormat = RenderFormat::R8G8B8A8_UNORM;
constexpr uint32_t kMaxQuads = 1024;
constexpr uint32_t kMaxVertices = kMaxQuads * 4;
constexpr uint32_t kMaxIndices = kMaxQuads * 6;

// Vertice del overlay: posicion en unidades virtuales + color RGBA empaquetado + UV del atlas.
struct Vertex {
    float x, y;
    uint32_t color;
    float u, v;
};

// Push constant: xy = escala (clip/unidad virtual), zw = offset (clip). Proyeccion ortografica.
struct PushConstants {
    float scale_x, scale_y, offset_x, offset_y;
};

bool g_enabled = true;
std::mutex g_frame_mutex;
Frame g_frame;
// Indicador de FPS (capa independiente del frame del menú). Lo publica el hilo de render.
std::atomic<bool> g_fps_on{ false };
std::atomic<int> g_fps_value{ 0 };
// Frames realmente presentados (se incrementa una vez por draw del render hook).
std::atomic<uint64_t> g_presented_frames{ 0 };

RenderDevice* g_device = nullptr;
std::unique_ptr<RenderShader> g_vs;
std::unique_ptr<RenderShader> g_ps;
std::unique_ptr<RenderSampler> g_sampler;
std::unique_ptr<RenderDescriptorSet> g_sampler_set;
std::unique_ptr<RenderDescriptorSetBuilder> g_texture_set_builder;
uint32_t g_texture_index = 0;
std::unique_ptr<RenderPipelineLayout> g_layout;
std::unique_ptr<RenderPipeline> g_pipeline;
std::unique_ptr<RenderBuffer> g_vertex_buffer;
std::unique_ptr<RenderBuffer> g_index_buffer;
RenderInputSlot g_input_slot;
std::vector<RenderInputElement> g_input_elements;
std::unique_ptr<RenderCommandQueue> g_copy_queue;
std::unique_ptr<RenderCommandList> g_copy_list;
std::unique_ptr<RenderCommandFence> g_copy_fence;
std::unique_ptr<RenderTexture> g_white_texture;
std::unique_ptr<RenderDescriptorSet> g_white_set;
std::unique_ptr<RenderTexture> g_atlas_texture;
std::unique_ptr<RenderDescriptorSet> g_atlas_set;
float g_atlas_w = 0.0f;
float g_atlas_h = 0.0f;

void append_quad(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, float x, float y,
                 float w, float h, uint32_t color, float u0, float v0, float u1, float v1) {
    if (vertices.size() + 4 > kMaxVertices) {
        return;
    }
    const uint32_t base = static_cast<uint32_t>(vertices.size());
    vertices.push_back({ x, y, color, u0, v0 });
    vertices.push_back({ x + w, y, color, u1, v0 });
    vertices.push_back({ x + w, y + h, color, u1, v1 });
    vertices.push_back({ x, y + h, color, u0, v1 });
    indices.push_back(base + 0);
    indices.push_back(base + 1);
    indices.push_back(base + 2);
    indices.push_back(base + 0);
    indices.push_back(base + 2);
    indices.push_back(base + 3);
}

// Sube una textura RGBA8 (fila alineada a 256 B) por la cola de copia y la deja en SHADER_READ.
std::unique_ptr<RenderTexture> upload_texture(uint32_t width, uint32_t height, const uint8_t* pixels) {
    auto texture = g_device->createTexture(RenderTextureDesc::Texture2D(width, height, 1, kTextureFormat));
    const uint32_t row_pitch = width * 4;
    const uint32_t row_byte_width = (row_pitch + 255u) / 256u * 256u;
    const uint32_t row_width = row_byte_width / 4;
    const uint32_t uploaded_size = row_byte_width * height;
    auto buffer = g_device->createBuffer(RenderBufferDesc::UploadBuffer(uploaded_size));
    uint8_t* dst = static_cast<uint8_t*>(buffer->map());
    for (uint32_t y = 0; y < height; ++y) {
        std::memcpy(dst + y * row_byte_width, pixels + y * row_pitch, row_pitch);
    }
    buffer->unmap();

    g_copy_list->begin();
    g_copy_list->barriers(RenderBarrierStage::COPY, RenderTextureBarrier(texture.get(), RenderTextureLayout::COPY_DEST));
    g_copy_list->copyTextureRegion(
        RenderTextureCopyLocation::Subresource(texture.get()),
        RenderTextureCopyLocation::PlacedFootprint(buffer.get(), kTextureFormat, width, height, 1, row_width));
    g_copy_list->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(texture.get(), RenderTextureLayout::SHADER_READ));
    g_copy_list->end();
    g_copy_queue->executeCommandLists(g_copy_list.get(), g_copy_fence.get());
    g_copy_queue->waitForCommandFence(g_copy_fence.get());
    return texture;
}

std::unique_ptr<RenderDescriptorSet> make_texture_set(RenderTexture* texture) {
    auto set = g_texture_set_builder->create(g_device);
    set->setTexture(g_texture_index, texture, RenderTextureLayout::SHADER_READ);
    return set;
}

void init_hook(RenderInterface* rhi, RenderDevice* device) {
    g_device = device;

    const RenderShaderFormat shader_format = rhi->getCapabilities().shaderFormat;
    g_vs = device->createShader(GET_SHADER_BLOB(OverlayVS, shader_format), GET_SHADER_SIZE(OverlayVS, shader_format), "VSMain", shader_format);
    g_ps = device->createShader(GET_SHADER_BLOB(OverlayPS, shader_format), GET_SHADER_SIZE(OverlayPS, shader_format), "PSMain", shader_format);

    RenderSamplerDesc sampler_desc{};
    sampler_desc.minFilter = RenderFilter::NEAREST;
    sampler_desc.magFilter = RenderFilter::NEAREST;
    sampler_desc.addressU = RenderTextureAddressMode::CLAMP;
    sampler_desc.addressV = RenderTextureAddressMode::CLAMP;
    sampler_desc.addressW = RenderTextureAddressMode::CLAMP;
    g_sampler = device->createSampler(sampler_desc);

    // Set 0: sampler inmutable (+ constant buffer dummy por el workaround de D3D12 de Goemon/recompui).
    RenderDescriptorSetBuilder sampler_set_builder{};
    sampler_set_builder.begin();
    sampler_set_builder.addImmutableSampler(1, g_sampler.get());
    sampler_set_builder.addConstantBuffer(3, 1);
    sampler_set_builder.end();
    g_sampler_set = sampler_set_builder.create(device);

    // Set 1: textura (una por recurso; el indice lo fija el builder).
    g_texture_set_builder = std::make_unique<RenderDescriptorSetBuilder>();
    g_texture_set_builder->begin();
    g_texture_index = g_texture_set_builder->addTexture(2);
    g_texture_set_builder->end();

    RenderPipelineLayoutBuilder layout_builder{};
    layout_builder.begin(false, true);
    layout_builder.addPushConstant(0, 0, sizeof(PushConstants), RenderShaderStageFlag::VERTEX);
    layout_builder.addDescriptorSet(sampler_set_builder);
    layout_builder.addDescriptorSet(*g_texture_set_builder);
    layout_builder.end();
    g_layout = layout_builder.create(device);

    g_input_slot = RenderInputSlot(0, sizeof(Vertex));
    g_input_elements = {
        RenderInputElement("POSITION", 0, 0, RenderFormat::R32G32_FLOAT, 0, offsetof(Vertex, x)),
        RenderInputElement("COLOR", 0, 1, RenderFormat::R8G8B8A8_UNORM, 0, offsetof(Vertex, color)),
        RenderInputElement("TEXCOORD", 0, 2, RenderFormat::R32G32_FLOAT, 0, offsetof(Vertex, u)),
    };

    RenderGraphicsPipelineDesc pipeline_desc{};
    pipeline_desc.renderTargetBlend[0] = RenderBlendDesc::AlphaBlend();
    pipeline_desc.renderTargetFormat[0] = kSwapChainFormat;
    pipeline_desc.renderTargetCount = 1;
    pipeline_desc.cullMode = RenderCullMode::NONE;
    pipeline_desc.inputSlots = &g_input_slot;
    pipeline_desc.inputSlotsCount = 1;
    pipeline_desc.inputElements = g_input_elements.data();
    pipeline_desc.inputElementsCount = static_cast<uint32_t>(g_input_elements.size());
    pipeline_desc.pipelineLayout = g_layout.get();
    pipeline_desc.primitiveTopology = RenderPrimitiveTopology::TRIANGLE_LIST;
    pipeline_desc.vertexShader = g_vs.get();
    pipeline_desc.pixelShader = g_ps.get();
    g_pipeline = device->createGraphicsPipeline(pipeline_desc);

    g_vertex_buffer = device->createBuffer(RenderBufferDesc::VertexBuffer(kMaxVertices * sizeof(Vertex), RenderHeapType::UPLOAD));
    g_index_buffer = device->createBuffer(RenderBufferDesc::IndexBuffer(kMaxIndices * sizeof(uint32_t), RenderHeapType::UPLOAD));

    g_copy_queue = device->createCommandQueue(RenderCommandListType::COPY);
    g_copy_list = g_copy_queue->createCommandList();
    g_copy_fence = device->createCommandFence();

    // Textura 1x1 blanca para paneles solidos.
    const uint8_t white_pixel[4] = { 255, 255, 255, 255 };
    g_white_texture = upload_texture(1, 1, white_pixel);
    g_white_set = make_texture_set(g_white_texture.get());

    // Atlas de la fuente del juego (RGBA8 128x32).
    if (hh::font::game::init()) {
        g_atlas_w = static_cast<float>(hh::font::game::atlas_width());
        g_atlas_h = static_cast<float>(hh::font::game::atlas_height());
        g_atlas_texture = upload_texture(hh::font::game::atlas_width(), hh::font::game::atlas_height(),
                                         hh::font::game::atlas_rgba8());
        g_atlas_set = make_texture_set(g_atlas_texture.get());
    }

    hh::log("[overlay] init: shaderFormat=%d pipeline=%d atlas=%d (%.0fx%.0f)\n",
            static_cast<int>(shader_format), g_pipeline != nullptr, g_atlas_texture != nullptr,
            g_atlas_w, g_atlas_h);
}

void draw_range(RenderCommandList* list, RenderDescriptorSet* texture_set, uint32_t start_index,
                uint32_t index_count) {
    if (index_count == 0) {
        return;
    }
    list->setGraphicsDescriptorSet(texture_set, 1);
    const RenderVertexBufferView vertex_view(g_vertex_buffer.get(), kMaxVertices * sizeof(Vertex));
    list->setVertexBuffers(0, &vertex_view, 1, &g_input_slot);
    const RenderIndexBufferView index_view(g_index_buffer.get(), kMaxIndices * sizeof(uint32_t), RenderFormat::R32_UINT);
    list->setIndexBuffer(&index_view);
    list->drawIndexedInstanced(index_count, 1, start_index, 0, 0);
}

void draw_hook(RenderCommandList* list, RenderFramebuffer* swap_chain_framebuffer) {
    if (!g_enabled || g_pipeline == nullptr) {
        return;
    }
    // Cada draw del hook equivale a un frame presentado (incluidos los interpolados). Es la tasa
    // real de presentación, la que muestra el indicador de FPS.
    g_presented_frames.fetch_add(1, std::memory_order_relaxed);

    // Indicador de FPS: capa aparte, activa también sin menú (gameplay). Solo números, arriba-izq.
    const bool fps_on = g_fps_on.load(std::memory_order_relaxed);
    const int fps_value = g_fps_value.load(std::memory_order_relaxed);
    Frame frame;
    {
        const std::lock_guard<std::mutex> lock(g_frame_mutex);
        frame = g_frame;
    }
    if (!frame.visible && !fps_on) {
        return;
    }

    const uint32_t width = swap_chain_framebuffer->getWidth();
    const uint32_t height = swap_chain_framebuffer->getHeight();
    if (width == 0 || height == 0) {
        return;
    }

    // Construye TODA la geometria del frame en un unico buffer (subida unica). Los paneles y el
    // texto se dibujan por rangos de indices con distinta textura: escribir dos veces el mismo
    // buffer antes de que se ejecute la command list haria que ambos draws leyeran el ultimo dato.
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    vertices.reserve(kMaxVertices);
    indices.reserve(kMaxIndices);

    for (const Panel& p : frame.panels) {
        append_quad(vertices, indices, p.x, p.y, p.w, p.h, p.color, 0.5f, 0.5f, 0.5f, 0.5f);
    }
    // Puntuación que la fuente del juego no incluye (`:`, `.`): se dibuja con rectángulos del color
    // del texto (rango de paneles, textura blanca). El avance es monospace (8 px/char).
    {
        const float cw = static_cast<float>(hh::font::game::char_width());
        for (const Text& t : frame.texts) {
            float pen_x = t.x;
            size_t i = 0;
            while (i < t.text.size()) {
                const unsigned cp = utf8_next_cp(t.text, i);
                if (cp == ':') {
                    append_quad(vertices, indices, pen_x + 3.0f * t.scale_x, t.y + 1.0f * t.scale_y,
                                2.0f * t.scale_x, 2.0f * t.scale_y, t.color, 0.5f, 0.5f, 0.5f, 0.5f);
                    append_quad(vertices, indices, pen_x + 3.0f * t.scale_x, t.y + 4.0f * t.scale_y,
                                2.0f * t.scale_x, 2.0f * t.scale_y, t.color, 0.5f, 0.5f, 0.5f, 0.5f);
                }
                else if (cp == '.') {
                    append_quad(vertices, indices, pen_x + 3.0f * t.scale_x, t.y + 5.0f * t.scale_y,
                                2.0f * t.scale_x, 2.0f * t.scale_y, t.color, 0.5f, 0.5f, 0.5f, 0.5f);
                }
                else if (cp == '%') {
                    // Porcentaje (la fuente no lo tiene): dos puntos 2x2 y una barra diagonal de 1 px.
                    append_quad(vertices, indices, pen_x + 1.0f * t.scale_x, t.y + 1.0f * t.scale_y,
                                2.0f * t.scale_x, 2.0f * t.scale_y, t.color, 0.5f, 0.5f, 0.5f, 0.5f);
                    append_quad(vertices, indices, pen_x + 5.0f * t.scale_x, t.y + 4.0f * t.scale_y,
                                2.0f * t.scale_x, 2.0f * t.scale_y, t.color, 0.5f, 0.5f, 0.5f, 0.5f);
                    for (int row = 0; row < 5; ++row) {
                        append_quad(vertices, indices, pen_x + static_cast<float>(5 - row) * t.scale_x,
                                    t.y + static_cast<float>(1 + row) * t.scale_y, 1.0f * t.scale_x,
                                    1.0f * t.scale_y, t.color, 0.5f, 0.5f, 0.5f, 0.5f);
                    }
                }
                pen_x += cw * t.scale_x;
            }
        }
    }
    const uint32_t panel_index_count = static_cast<uint32_t>(indices.size());

    if (g_atlas_set != nullptr && g_atlas_w > 0.0f) {
        const float cw = static_cast<float>(hh::font::game::char_width());
        const float ch = static_cast<float>(hh::font::game::char_height());
        for (const Text& t : frame.texts) {
            float pen_x = t.x;
            size_t i = 0;
            while (i < t.text.size()) {
                const unsigned cp = utf8_next_cp(t.text, i);
                unsigned value = 0, gx = 0, gy = 0;
                int mark = -1;
                if (hh::font::game::menu_char(cp, value, mark)) {
                    // La MARCA se dibuja DEBAJO de la letra (z-order): así su sombra (+1,+1) no pisa
                    // los píxeles de la letra al proyectarse sobre ella. Primero la marca, luego la
                    // letra base (si la hay).
                    unsigned mx = 0, my = 0, mw = 0, mh = 0;
                    int dy = 0;
                    if (mark >= 0 &&
                        hh::font::game::mark_info(mark, mx, my, mw, mh, dy) && mw > 0 && mh > 0) {
                        const float dx = pen_x + (cw - static_cast<float>(mw)) * 0.5f * t.scale_x;
                        const float dyy = t.y + static_cast<float>(dy) * t.scale_y;
                        const float u0 = static_cast<float>(mx) / g_atlas_w;
                        const float v0 = static_cast<float>(my) / g_atlas_h;
                        const float u1 = static_cast<float>(mx + mw) / g_atlas_w;
                        const float v1 = static_cast<float>(my + mh) / g_atlas_h;
                        append_quad(vertices, indices, dx, dyy, static_cast<float>(mw) * t.scale_x,
                                    static_cast<float>(mh) * t.scale_y, t.color, u0, v0, u1, v1);
                    }
                    if (value != 0 && hh::font::game::value_uv(value, gx, gy)) {
                        const float u0 = static_cast<float>(gx) / g_atlas_w;
                        const float v0 = static_cast<float>(gy) / g_atlas_h;
                        const float u1 = static_cast<float>(gx) / g_atlas_w + cw / g_atlas_w;
                        const float v1 = static_cast<float>(gy) / g_atlas_h + ch / g_atlas_h;
                        append_quad(vertices, indices, pen_x, t.y, cw * t.scale_x, ch * t.scale_y,
                                    t.color, u0, v0, u1, v1);
                    }
                } else if (hh::font::game::glyph_value(static_cast<unsigned char>(cp), value) &&
                           hh::font::game::value_uv(value, gx, gy)) {
                    const float u0 = static_cast<float>(gx) / g_atlas_w;
                    const float v0 = static_cast<float>(gy) / g_atlas_h;
                    const float u1 = static_cast<float>(gx) / g_atlas_w + cw / g_atlas_w;
                    const float v1 = static_cast<float>(gy) / g_atlas_h + ch / g_atlas_h;
                    append_quad(vertices, indices, pen_x, t.y, cw * t.scale_x, ch * t.scale_y,
                                t.color, u0, v0, u1, v1);
                }
                pen_x += cw * t.scale_x;
            }
        }
    }
    const uint32_t text_index_count = static_cast<uint32_t>(indices.size()) - panel_index_count;
    const uint32_t menu_text_end = static_cast<uint32_t>(indices.size());

    // Indicador de FPS: se ancla a la esquina REAL del framebuffer del swapchain (no al area 4:3
    // centrada donde va el texto del juego), por lo que se dibuja con su propia proyeccion en
    // pixeles (origen arriba-izquierda). Mismo tamano aparente que el texto del menu.
    uint32_t fps_index_count = 0;
    if (fps_on && g_atlas_set != nullptr && g_atlas_w > 0.0f) {
        const float cw = static_cast<float>(hh::font::game::char_width());
        const float ch = static_cast<float>(hh::font::game::char_height());
        const float fscale = static_cast<float>(height) / kVirtualHeight;
        const std::string fps_text = std::to_string(fps_value);
        float pen_x = 2.0f;   // margen de 2 px desde el borde
        for (char c : fps_text) {
            unsigned gx = 0, gy = 0;
            if (hh::font::game::glyph_uv(static_cast<unsigned char>(c), gx, gy)) {
                const float u0 = static_cast<float>(gx) / g_atlas_w;
                const float v0 = static_cast<float>(gy) / g_atlas_h;
                const float u1 = static_cast<float>(gx) / g_atlas_w + cw / g_atlas_w;
                const float v1 = static_cast<float>(gy) / g_atlas_h + ch / g_atlas_h;
                append_quad(vertices, indices, pen_x, 2.0f, cw * fscale, ch * fscale, 0xFFFFFFFFu,
                            u0, v0, u1, v1);
            }
            pen_x += cw * fscale;
        }
        fps_index_count = static_cast<uint32_t>(indices.size()) - menu_text_end;
    }

    if (indices.empty()) {
        return;
    }
    std::memcpy(g_vertex_buffer->map(), vertices.data(), vertices.size() * sizeof(Vertex));
    g_vertex_buffer->unmap();
    std::memcpy(g_index_buffer->map(), indices.data(), indices.size() * sizeof(uint32_t));
    g_index_buffer->unmap();

    const RenderViewport viewport(0.0f, 0.0f, float(width), float(height));
    const RenderRect scissor(0, 0, static_cast<int32_t>(width), static_cast<int32_t>(height));
    list->setViewports(viewport);
    list->setScissors(scissor);

    list->setGraphicsPipelineLayout(g_layout.get());
    list->setPipeline(g_pipeline.get());
    list->setGraphicsDescriptorSet(g_sampler_set.get(), 0);

    // Proyeccion ortografica UNIFORME (pixel cuadrado): el espacio virtual 320x240 se dibuja a
    // escala uniforme k = alto/240 px por unidad y se CENTRA horizontalmente, como el texto 2D del
    // juego (que no va estirado a 16:9). Asi los glifos se dibujan a tamano nativo (scale 1.0).
    // Convencion D3D (y=+1 arriba); DXC anade -fvk-invert-y para Vulkan.
    const float k = static_cast<float>(height) / kVirtualHeight;
    const PushConstants pc{
        .scale_x = 2.0f * k / static_cast<float>(width),
        .scale_y = -2.0f * k / static_cast<float>(height),
        .offset_x = -(kVirtualWidth * k) / static_cast<float>(width),
        .offset_y = 1.0f,
    };
    list->setGraphicsPushConstants(0, &pc);

    // Paneles solidos (textura 1x1 blanca) y luego texto (atlas de la fuente del juego).
    draw_range(list, g_white_set.get(), 0, panel_index_count);
    draw_range(list, g_atlas_set.get(), panel_index_count, text_index_count);

    // Indicador de FPS con proyeccion en PIXELES (1 unidad = 1 px, origen arriba-izquierda).
    if (fps_index_count > 0) {
        const PushConstants pc_fps{
            .scale_x = 2.0f / static_cast<float>(width),
            .scale_y = -2.0f / static_cast<float>(height),
            .offset_x = -1.0f,
            .offset_y = 1.0f,
        };
        list->setGraphicsPushConstants(0, &pc_fps);
        draw_range(list, g_atlas_set.get(), menu_text_end, fps_index_count);
    }
}

void deinit_hook() {
    {
        const std::lock_guard<std::mutex> lock(g_frame_mutex);
        g_frame = Frame{};
    }
    g_atlas_set.reset();
    g_atlas_texture.reset();
    g_white_set.reset();
    g_white_texture.reset();
    g_copy_fence.reset();
    g_copy_list.reset();
    g_copy_queue.reset();
    g_index_buffer.reset();
    g_vertex_buffer.reset();
    g_pipeline.reset();
    g_layout.reset();
    g_texture_set_builder.reset();
    g_sampler_set.reset();
    g_sampler.reset();
    g_ps.reset();
    g_vs.reset();
    g_device = nullptr;
    hh::log("[overlay] deinit\n");
}

}  // namespace

bool enabled() { return g_enabled; }

void set_fps_indicator(bool enabled, int fps) {
    g_fps_on.store(enabled, std::memory_order_relaxed);
    g_fps_value.store(fps, std::memory_order_relaxed);
}

uint64_t presented_frames() {
    return g_presented_frames.load(std::memory_order_relaxed);
}

void publish(Frame frame) {
    const std::lock_guard<std::mutex> lock(g_frame_mutex);
    g_frame = std::move(frame);
}

void register_hooks() {
    const char* e = std::getenv("HH_OVERLAY");
    g_enabled = (e == nullptr || *e == '\0' || *e != '0');
    RT64::SetRenderHooks(init_hook, draw_hook, deinit_hook);
    hh::log("[overlay] render hooks registrados (enabled=%d)\n", g_enabled);
}

}  // namespace hh::overlay
