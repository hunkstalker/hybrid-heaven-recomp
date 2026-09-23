// hh_menu_overlay — overlay A2 del menú de título (render hook de RT64).
//
// NO reimplementa el menú del juego: el handler original (func_801C1DB8) sigue ejecutándose (el
// texto y la lógica del juego quedan visibles/intactos). Este módulo lee el estado REAL del menú
// (etiquetas y selección) de la RDRAM y publica un frame de overlay encima, para poder alinear
// nuestros textos con los del juego y, más adelante, sustituir la presentación.
//
// Visibilidad: F6 (ver src/subsystems/input.cpp). Diagnóstico de alineación: HH_OVERLAY_X /
// HH_OVERLAY_Y (offset en unidades virtuales del overlay).
//
// Ver RETOMAR.md (A2) y notes/2026-09-23-a2-overlay-primer-paso.md.

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "hh.h"
#include "hh/overlay.h"

namespace hh::menu_overlay {
namespace {

constexpr uint32_t kMod23Src = 0x5F1190;   // ROM del módulo 23
constexpr uint32_t kMod23Size = 0xAD36;
// Etiquetas del menú de título: 0x801CEBB4 + 16*idx en el enlace del módulo 23 (base 0x801BF1A0).
constexpr uint32_t kTitleLabelOff = 0x801CEBB4u - 0x801BF1A0u;   // 0xFA14
constexpr int kTitleEntries = 5;           // idx 1..5 (idx 0 = caja de cursor)
// Y de la primera entrada (0x76) y paso entre entradas (10) en el espacio del juego.
constexpr float kTitleY0 = 0x76;
constexpr float kTitleDy = 10.0f;

bool g_visible = true;
// Offset de alineación del overlay sobre el texto del juego, en unidades virtuales 320x240. La
// proyección es uniforme (píxel cuadrado) y centra el área 4:3, así que el glifo va a tamaño nativo
// (scale 1.0) y estas coordenadas son las del juego. Ajustables: HH_OVERLAY_X / HH_OVERLAY_Y.
float g_offset_x = 112.0f;
float g_offset_y = 5.0f;
// Escala del texto: 1.0 = tamaño nativo (el glifo 8x8 del juego, sin estirar). Ajustable: HH_OVERLAY_SX/SY.
float g_scale_x = 1.0f;
float g_scale_y = 1.0f;
bool g_offsets_loaded = false;

// El handler del menú de título se ejecuta en el hilo del juego; `tick` en el de render. El
// contador permite ocultar el overlay cuando el menú deja de publicarlo (p. ej. al salir del título).
std::atomic<uint64_t> g_publish_counter{ 0 };

void load_offsets_once() {
    if (g_offsets_loaded) return;
    g_offsets_loaded = true;
    if (const char* x = std::getenv("HH_OVERLAY_X")) g_offset_x = static_cast<float>(std::atof(x));
    if (const char* y = std::getenv("HH_OVERLAY_Y")) g_offset_y = static_cast<float>(std::atof(y));
    if (const char* sx = std::getenv("HH_OVERLAY_SX")) g_scale_x = static_cast<float>(std::atof(sx));
    if (const char* sy = std::getenv("HH_OVERLAY_SY")) g_scale_y = static_cast<float>(std::atof(sy));
}

// Lee una cadena ASCII del guest (bytes con XOR 3) hasta NUL o `max`.
std::string read_guest_string(uint8_t* rdram, uint32_t addr, size_t max) {
    std::string s;
    s.reserve(max);
    for (size_t i = 0; i < max; ++i) {
        const char c = static_cast<char>(rdram[((addr + i) - 0x80000000u) ^ 3u]);
        if (c == '\0') break;
        s.push_back(c);
    }
    return s;
}

bool printable(const std::string& s) {
    for (unsigned char c : s) {
        if (c < 0x20 || c > 0x7E) return false;
    }
    return !s.empty();
}

}  // namespace

bool visible() { return g_visible; }
void toggle() { g_visible = !g_visible; }

// Calibracion en vivo (Ctrl+flechas, ver src/subsystems/input.cpp). Escribe los valores en hh.log.
void adjust(float dx, float dy, float dsx, float dsy) {
    load_offsets_once();
    g_offset_x += dx;
    g_offset_y += dy;
    g_scale_x = std::clamp(g_scale_x + dsx, 0.25f, 3.0f);
    g_scale_y = std::clamp(g_scale_y + dsy, 0.25f, 3.0f);
    hh::log("[overlay] calib x=%.2f y=%.2f sx=%.3f sy=%.3f\n", g_offset_x, g_offset_y, g_scale_x,
            g_scale_y);
}

// Se llama desde el handler del menú de título (hh_title_menu_hook) DESPUÉS del original.
void title_update(uint8_t* rdram) {
    if (!g_visible || rdram == nullptr) {
        return;
    }
    load_offsets_once();

    const uint32_t base = hh_trans_dst_for(kMod23Src, kMod23Size);
    if (base == 0) {
        return;
    }

    // Índice seleccionado (0..4): byte en 0x801CC8C4 (módulo 23).
    const unsigned sel = rdram[((0x801CC8C4u - 0x80000000u) ^ 3u)];

    hh::overlay::Frame frame;
    frame.visible = true;

    static const bool trace = [] {
        const char* e = std::getenv("HH_MENU_TRACE");
        return e != nullptr && *e != '\0' && *e != '0';
    }();
    static bool traced = false;

    for (int e = 0; e < kTitleEntries; ++e) {
        const int idx = e + 1;   // idx 1..5
        const std::string label = read_guest_string(rdram, base + kTitleLabelOff + 16u * idx, 15);
        if (trace && !traced) {
            hh::log("[overlay] title idx=%d base=%08X label='%s'\n", idx, base, label.c_str());
        }
        if (!printable(label)) {
            continue;
        }
        const float y = kTitleY0 + kTitleDy * static_cast<float>(e) + g_offset_y;
        const uint32_t color = (static_cast<unsigned>(e) == sel)
                                   ? hh::overlay::rgba(255, 220, 64, 255)
                                   : hh::overlay::rgba(255, 255, 255, 255);
        frame.texts.push_back({ g_offset_x, y, g_scale_x, g_scale_y, color, label });
    }
    traced = true;

    g_publish_counter.fetch_add(1, std::memory_order_relaxed);
    hh::overlay::publish(std::move(frame));
}

// Render thread: si el menú de título dejó de publicar (salimos de él), oculta el overlay.
void tick() {
    static uint64_t last_counter = 0;
    static int stale_ticks = 0;
    const uint64_t counter = g_publish_counter.load(std::memory_order_relaxed);
    if (counter != last_counter) {
        last_counter = counter;
        stale_ticks = 0;
        return;
    }
    if (++stale_ticks == 30) {   // ~0.3 s sin publicaciones
        hh::overlay::publish(hh::overlay::Frame{});
    }
}

}  // namespace hh::menu_overlay
