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
// Medido (2026-10-02): la ventana del ordenador usa color3 (12x13, stride 78) y un glifo nativo con
// `value=200` (el mismo que usaramos para el acento `a`). El hook antiguo interceptaba por `value`
// a secas y escribia 32 B de color0 (8x8) donde color3 espera 78 B -> glifos corruptos. Con la marca
// de origen el `value` nativo pasa intacto; con la guarda de `stride` no se escribe un bloque de
// otro tamano. La kana de color0 (values 74..248, ver include/hh/jp_kana.h) tambien queda intacta.
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

// Tamano del bloque que servimos: color0 8x8 -> 32 B (tblA en 0x80044624; solo color0 es 32).
constexpr unsigned kAccentStride = hh::kAccentStride;

// Donante ASCII: codigo EUC de '@' (tabla ASCII->EUC del motor en 0x80044548). Se elige '@' porque
// es poco frecuente y la tabla de valores le da un valor NO nulo (80); con value 0 el motor no
// llamaria a `func_8001BFE4` y el acento no se serviria (p. ej. '~' -> 0).
constexpr unsigned kDonorCode = 0xA1F7u;

int accent_by_code(unsigned code) {
    for (unsigned i = 0; i < hh::kAccentGlyphCount; ++i) {
        if (hh::kAccentGlyphs[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

// Ultimo `d394` visto. Solo servimos el acento en `bfe4` si el glifo es uno de los nuestros.
struct Pending {
    bool active = false;
    uint8_t color = 0;
    uint16_t value = 0;
    int index = -1;
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

// Escribe el bloque acentuado (intercalado par) en el scratch; si el `value` es impar, traslada el
// glifo al plano impar (0x33) para que el compositor (`func_8001C0B0`) lo lea.
void store_block(uint8_t* rdram, const uint8_t* block, bool odd) {
    for (unsigned i = 0; i < kAccentStride; ++i) {
        uint8_t b = block[i];
        if (odd) b = static_cast<uint8_t>((b >> 2) & 0x33u);
        rdram[(kGlyphScratch + i - 0x80000000u) ^ 3u] = b;
    }
}

}  // namespace

// codigo EUC propio -> value del donante (si no es nuestro, comportamiento original).
extern "C" void hh_accent_d394(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned code = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    const int idx = accent_by_code(code);
    if (idx >= 0) {
        const uint16_t value = donor_value(rdram, ctx, color);
        ctx->r2 = value;
        g_pending = {true, static_cast<uint8_t>(color), value, idx};
        return;
    }
    func_8001D394_1DF94(rdram, ctx);
    g_pending.active = false;   // cualquier glifo nativo invalida la marca de origen
}

// value del donante Y con marca de origen -> escribir nuestro bloque (solo en color0, stride 32).
extern "C" void hh_accent_bfe4(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned value = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    if (g_pending.active && g_pending.color == color && g_pending.value == value) {
        const int idx = g_pending.index;
        g_pending.active = false;   // consumido
        const unsigned stride = rdram[(0x80044624u + color - 0x80000000u) ^ 3u];
        if (stride == kAccentStride) {
            store_block(rdram, hh::kAccentGlyphs[idx].block, (value & 1u) != 0);
            return;
        }
        // Otro color (p. ej. color3 12x13, stride 78): no servimos un bloque de 8x8 para no corromper.
    }
    func_8001BFE4_1CBE4(rdram, ctx);
}

// Registro (llamado desde hh::register_runtime_functions).
extern "C" void hh_accent_register() {
    recomp::overlays::add_loaded_function(0x8001D394, hh_accent_d394);
    recomp::overlays::add_loaded_function(0x8001BFE4, hh_accent_bfe4);
    std::fprintf(stderr, "[hh] acentos: %u glifos, donante+origen (func_8001D394/BFE4)\n",
                 hh::kAccentGlyphCount);
}
