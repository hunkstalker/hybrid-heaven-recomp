// B (backend_game): inyeccion de glifos acentuados en el motor de texto del juego.
//
// La fuente es 2bpp con pares de glifos empaquetados por bloque (ver
// notes/2026-09-23-b-fuente-formato-y-gaiji.md): `func_8001BFE4` carga `stride` bytes en el buffer
// de trabajo 0x801077E0 y `func_8001C0B0` selecciona el glifo por el bit bajo del valor.
//
// Overrides (patron ADR 0002, sin tocar el C generado):
//   - func_8001D394 (color, codigo EUC) -> valor: para nuestros codigos devuelve un valor propio.
//   - func_8001BFE4 (color, valor) -> carga el bloque: para nuestros valores escribe nuestro bitmap.
//
// Los bitmaps (color0, 8x8) los genera tools/text/gen_accent_glyphs.py en include/hh/accent_glyphs.h.
#include <cstdint>

#include "librecomp/overlays.hpp"
#include "recomp.h"
#include "hh.h"
#include "hh/accent_glyphs.h"

extern "C" void func_8001D394_1DF94(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001BFE4_1CBE4(uint8_t* rdram, recomp_context* ctx);

namespace {

// Buffer de trabajo del motor (verificado por traza HH_FONT_TRACE en Windows/Linux).
constexpr uint32_t kGlyphScratch = 0x801077E0u;

int accent_by_code(unsigned code) {
    for (unsigned i = 0; i < hh::kAccentGlyphCount; ++i) {
        if (hh::kAccentGlyphs[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

int accent_by_value(unsigned value) {
    for (unsigned i = 0; i < hh::kAccentGlyphCount; ++i) {
        if (hh::kAccentGlyphs[i].value == value) return static_cast<int>(i);
    }
    return -1;
}

}  // namespace

// codigo EUC propio -> valor de glifo propio (si no es nuestro, comportamiento original).
extern "C" void hh_accent_d394(uint8_t* rdram, recomp_context* ctx) {
    const unsigned code = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    func_8001D394_1DF94(rdram, ctx);
    const int idx = accent_by_code(code);
    if (idx >= 0) {
        ctx->r2 = hh::kAccentGlyphs[idx].value;
    }
}

// valor propio -> escribir nuestro bloque en el buffer de trabajo.
extern "C" void hh_accent_bfe4(uint8_t* rdram, recomp_context* ctx) {
    const unsigned value = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    const int idx = accent_by_value(value);
    if (idx >= 0) {
        const hh::AccentGlyph& g = hh::kAccentGlyphs[idx];
        for (unsigned i = 0; i < hh::kAccentStride; ++i) {
            rdram[(kGlyphScratch + i - 0x80000000u) ^ 3u] = g.block[i];
        }
        return;
    }
    func_8001BFE4_1CBE4(rdram, ctx);
}

// Registro (llamado desde hh::register_runtime_functions).
extern "C" void hh_accent_register() {
    recomp::overlays::add_loaded_function(0x8001D394, hh_accent_d394);
    recomp::overlays::add_loaded_function(0x8001BFE4, hh_accent_bfe4);
    std::fprintf(stderr, "[hh] acentos: %u glifos inyectados (func_8001D394/BFE4)\n",
                 hh::kAccentGlyphCount);
}
