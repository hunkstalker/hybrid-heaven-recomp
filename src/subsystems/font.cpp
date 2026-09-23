// hh_font — backend_game (A2 Fase A): fuente del juego -> atlas RGBA8 host (sin GBI).
// Ver include/hh/font.h y notes/2026-09-23-b-fuente-formato-y-gaiji.md.

#include "hh.h"
#include "hh/font.h"

#include <cstdint>
#include <fstream>
#include <string>

namespace hh::font::game {
namespace {

// Fichero color0 de la fuente (Nisitenma idx 107) en la ROM US: offset y tamano del manifiesto.
constexpr uint32_t kFontRomOffset = 0x6E3CD6;
constexpr uint32_t kFontRomSize = 4096;

constexpr unsigned kGlyphW = 8;
constexpr unsigned kGlyphH = 8;
constexpr unsigned kBlockStride = 32;   // dos glifos 8x8 2bpp por bloque
constexpr unsigned kMaxValue = 64;      // valores 0..63 (letras + espacio)
constexpr unsigned kAtlasCols = 16;
constexpr unsigned kAtlasWidth = kAtlasCols * kGlyphW;                 // 128
constexpr unsigned kAtlasHeight = (kMaxValue / kAtlasCols) * kGlyphH;  // 32

uint8_t g_atlas[kAtlasWidth * kAtlasHeight * 4];
bool g_ready = false;
bool g_tried = false;

void bake_atlas(const uint8_t* font) {
    for (unsigned v = 0; v < kMaxValue; ++v) {
        const unsigned block = v >> 1;
        const unsigned parity = v & 1u;
        const uint8_t* g = font + block * kBlockStride;
        const unsigned gx = (v % kAtlasCols) * kGlyphW;
        const unsigned gy = (v / kAtlasCols) * kGlyphH;
        for (unsigned y = 0; y < kGlyphH; ++y) {
            for (unsigned x = 0; x < kGlyphW; ++x) {
                const unsigned i = y * kGlyphW + x;   // pixel del glifo (fila a fila)
                const uint8_t byte = g[i >> 1];
                const uint8_t nibble = (i & 1u) ? (byte & 0x0Fu) : ((byte >> 4) & 0x0Fu);
                const unsigned lvl = (parity == 0) ? ((nibble >> 2) & 3u) : (nibble & 3u);
                const unsigned p = ((gy + y) * kAtlasWidth + (gx + x)) * 4;
                // Nivel 1 = glifo principal (texto); nivel >=2 = sombra (copia desplazada abajo-
                // derecha, como en el motor). R=255 -> color de vertice; R=0 -> negro (sombra).
                // A = cobertura (solida).
                g_atlas[p + 0] = (lvl == 1) ? 255u : 0u;    // R = tinta (1) / sombra (>=2)
                g_atlas[p + 1] = 255;                       // G
                g_atlas[p + 2] = 255;                       // B
                g_atlas[p + 3] = (lvl != 0) ? 255u : 0u;    // A = cobertura
            }
        }
    }
}

}  // namespace

bool init() {
    if (g_ready) return true;
    if (g_tried) return false;
    g_tried = true;

    const std::filesystem::path rom = hh::get_rom_path();
    if (rom.empty()) {
        hh::log("[font] ROM no encontrada; fuente del juego no disponible\n");
        return false;
    }
    std::ifstream f(rom, std::ios::binary);
    if (!f) {
        hh::log("[font] no se pudo abrir la ROM: %s\n", rom.string().c_str());
        return false;
    }
    std::string data(kFontRomSize, '\0');
    f.seekg(kFontRomOffset);
    f.read(data.data(), kFontRomSize);
    if (f.gcount() != static_cast<std::streamsize>(kFontRomSize)) {
        hh::log("[font] ROM corta al leer la fuente color0 (%lld B)\n",
                static_cast<long long>(f.gcount()));
        return false;
    }

    bake_atlas(reinterpret_cast<const uint8_t*>(data.data()));
    g_ready = true;
    hh::log("[font] atlas RGBA8 color0: %ux%u (%u B)\n", kAtlasWidth, kAtlasHeight,
            kAtlasWidth * kAtlasHeight * 4);
    return true;
}

bool ready() { return g_ready; }
const uint8_t* atlas_rgba8() { return g_atlas; }
unsigned atlas_width() { return kAtlasWidth; }
unsigned atlas_height() { return kAtlasHeight; }
unsigned char_width() { return kGlyphW; }
unsigned char_height() { return kGlyphH; }

bool glyph_value(unsigned char c, unsigned& value) {
    if (c == ' ') { value = 0; return true; }
    if (c >= 'A' && c <= 'Z') { value = 37u + (c - 'A'); return true; }
    if (c >= 'a' && c <= 'z') { value = 11u + (c - 'a'); return true; }
    return false;
}

bool glyph_uv(unsigned char c, unsigned& x, unsigned& y) {
    unsigned v = 0;
    if (!glyph_value(c, v) || v >= kMaxValue) return false;
    x = (v % kAtlasCols) * kGlyphW;
    y = (v / kAtlasCols) * kGlyphH;
    return true;
}

}  // namespace hh::font::game
