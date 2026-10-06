// B (backend_game): inyeccion de glifos acentuados en el motor de texto del juego.
//
// La fuente es 2bpp con pares de glifos empaquetados por bloque (ver
// notes/2026-09-23-b-fuente-formato-y-gaiji.md): `func_8001BFE4` carga `stride` bytes en el buffer
// de trabajo 0x801077E0 y `func_8001C0B0` selecciona el glifo por el bit bajo del valor.
//
// Overrides (patron ADR 0002, sin tocar el C generado):
//   - func_8001D394 (color, codigo EUC) -> valor: para nuestros codigos devuelve el `value` de un
//     **donante ASCII** (resuelto con el propio motor), no un valor inventado.
//   - func_8001BFE4 (color, valor) -> carga el bloque: sirve nuestro bitmap SOLO si el `value`
//     procede de nuestro `d394` (marca de origen), nunca por `value` a secas.
//
// Dos estilos, elegidos por el `stride` del color (tabla tblA en 0x80044624):
//   - color0 (8x8, stride 32): menus ASCII; glifos de `include/hh/accent_glyphs.h`.
//   - color4 (8x12, stride 48): **dialogos** (texto EUC); glifos de `include/hh/game_font_color4.h`
//     (misma tipografia que los subtitulos; ver notes/2026-10-06-dialogos-estructura-nodos-y-a-plus.md).
//
// Los codigos de cada estilo son sinteticos (B1xx) y **coinciden en el espacio**, pero el color
// (stride) los desambigua: el menu usa color0, el dialogo color4.
#include <cstdint>

#include "librecomp/overlays.hpp"
#include "recomp.h"
#include "hh.h"
#include "hh/accent_glyphs.h"      // color0 8x8
#include "hh/game_font_color4.h"   // color4 8x12

extern "C" void func_8001D394_1DF94(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001BFE4_1CBE4(uint8_t* rdram, recomp_context* ctx);

namespace {

// Buffer de trabajo del motor (verificado por traza HH_FONT_TRACE en Windows/Linux).
constexpr uint32_t kGlyphScratch = 0x801077E0u;
// tblA (0x80044624): bytes por glifo por color (32,50,60,78,48,78).
constexpr uint32_t kTblA = 0x80044624u;

// Donante ASCII: codigo EUC de '@' (tabla ASCII->EUC del motor). Se elige '@' porque es poco
// frecuente y da un `value` no nulo (con value 0 el motor no llamaria a `func_8001BFE4`).
constexpr unsigned kDonorCode = 0xA1F7u;

unsigned color_stride(uint8_t* rdram, unsigned color) {
    return rdram[(kTblA + color - 0x80000000u) ^ 3u];
}

int accent_by_code(unsigned code) {
    for (unsigned i = 0; i < hh::kAccentGlyphCount; ++i) {
        if (hh::kAccentGlyphs[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

int game_by_code(unsigned code) {
    for (unsigned i = 0; i < hh::kGameGlyphCount; ++i) {
        if (hh::kGameGlyphs[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

enum class Which { Color0, Color4 };

// Ultimo `d394` visto. Solo servimos el glifo en `bfe4` si procede de uno de los nuestros.
struct Pending {
    bool active = false;
    uint8_t color = 0;
    uint16_t value = 0;
    int index = -1;
    Which which = Which::Color0;
};
Pending g_pending;

// `value` del donante para este color, resuelto por el MISMO motor (d394 original). Cacheado.
uint16_t donor_value(uint8_t* rdram, const recomp_context* ctx, unsigned color) {
    static uint16_t cache[256] = {};
    static bool have[256] = {};
    if (!have[color]) {
        recomp_context tmp = *ctx;
        tmp.r4 = color;
        tmp.r5 = kDonorCode;
        func_8001D394_1DF94(rdram, &tmp);
        cache[color] = static_cast<uint16_t>(tmp.r2 & 0xFFFFu);
        have[color] = true;
    }
    return cache[color];
}

// Escribe el bloque (intercalado par) en el scratch; si el `value` es impar, traslada el glifo al
// plano impar (0x33) para que el compositor (`func_8001C0B0`) lo lea.
void store_block(uint8_t* rdram, const uint8_t* block, unsigned stride, bool odd) {
    for (unsigned i = 0; i < stride; ++i) {
        uint8_t b = block[i];
        if (odd) b = static_cast<uint8_t>((b >> 2) & 0x33u);
        rdram[(kGlyphScratch + i - 0x80000000u) ^ 3u] = b;
    }
}

}  // namespace

// codigo EUC propio -> value del donante (si no es nuestro, comportamiento original). El estilo lo
// fija el `stride` del color (color0 8x8 menus, color4 8x12 dialogos).
extern "C" void hh_accent_d394(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned code = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    const unsigned stride = color_stride(rdram, color);

    int idx = -1;
    Which which = Which::Color0;
    if (stride == hh::kGameGlyphStride) {
        idx = game_by_code(code);
        which = Which::Color4;
    } else if (stride == hh::kAccentStride) {
        idx = accent_by_code(code);
        which = Which::Color0;
    }
    if (idx >= 0) {
        const uint16_t value = donor_value(rdram, ctx, color);
        ctx->r2 = value;
        g_pending = {true, static_cast<uint8_t>(color), value, idx, which};
        return;
    }
    func_8001D394_1DF94(rdram, ctx);
    g_pending.active = false;   // cualquier glifo nativo invalida la marca de origen
}

// value del donante Y con marca de origen -> escribir nuestro bloque del estilo correspondiente.
extern "C" void hh_accent_bfe4(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned value = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    if (g_pending.active && g_pending.color == color && g_pending.value == value) {
        const int idx = g_pending.index;
        const Which which = g_pending.which;
        g_pending.active = false;   // consumido
        const unsigned stride = color_stride(rdram, color);
        const bool odd = (value & 1u) != 0;
        if (which == Which::Color4 && stride == hh::kGameGlyphStride) {
            store_block(rdram, hh::kGameGlyphs[idx].block, hh::kGameGlyphStride, odd);
            return;
        }
        if (which == Which::Color0 && stride == hh::kAccentStride) {
            store_block(rdram, hh::kAccentGlyphs[idx].block, hh::kAccentStride, odd);
            return;
        }
        // Otro color: no servimos un bloque de tamano distinto (evita corromper).
    }
    func_8001BFE4_1CBE4(rdram, ctx);
}

// Registro (llamado desde hh::register_runtime_functions).
extern "C" void hh_accent_register() {
    recomp::overlays::add_loaded_function(0x8001D394, hh_accent_d394);
    recomp::overlays::add_loaded_function(0x8001BFE4, hh_accent_bfe4);
    std::fprintf(stderr, "[hh] acentos: color0 %u + color4 %u glifos (donante+origen)\n",
                 hh::kAccentGlyphCount, hh::kGameGlyphCount);
}
