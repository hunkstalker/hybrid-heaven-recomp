// A2 — Menú PC in-game (ADR 0008). Convierte la entrada "SOUND" del menú de título en "AJUSTES",
// que abre una pantalla propia con dos entradas: IDIOMA y SONIDO.
//   - SONIDO -> ejecuta el submenú de sonido ORIGINAL (func_801C4960) con STEREO/MONAURAL.
//   - IDIOMA -> lista de idiomas; al confirmar, cambia el idioma en vivo.
//
// Overrides de funciones del módulo 23 (add_loaded_function; el port usa
// use_lookup_for_all_function_calls). No se toca el C generado:
//   0x801C4960 (setup submenú sonido)     -> hh_pc_ajustes
//   0x801C4AA8 (input submenú sonido)     -> hh_pc_ajustes_input
//   0x801C5108 (setup submenú resolución) -> hh_pc_idioma
//   0x801C5378 (input submenú resolución) -> hh_pc_idioma_input
//
// Etiquetas: se reutilizan los campos de texto del PROPIO submenú de resolución/sonido (16-20 B,
// ya usados por el motor para HIGH NORMAL/LOW/STEREO/MONAURAL) -> no se corrompe nada. Ver
// notes/2026-09-23-a2-plan-menu-ajustes-idioma.md.

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "librecomp/overlays.hpp"

#include "../../build/recomp/RecompiledFuncs/funcs.h"
#include "hh.h"

#if defined(_MSC_VER)
#define MY_NOINLINE __declspec(noinline)
#else
#define MY_NOINLINE __attribute__((noinline))
#endif

namespace {

constexpr uint32_t kMod23Src = 0x5F1190;   // ROM del módulo 23
constexpr uint32_t kMod23Size = 0xAD36;

bool trace_enabled() {
    static const bool on = [] {
        const char* e = std::getenv("HH_MENU_TRACE");
        return e != nullptr && *e != '\0' && *e != '0';
    }();
    return on;
}

extern "C" void func_801C4960_11BE430(uint8_t*, recomp_context*);   // setup sonido (delegate)
extern "C" void func_801C5108_11BEBD8(uint8_t*, recomp_context*);   // setup resolución (delegate)
extern "C" void func_801C1340_11BAE10(uint8_t*, recomp_context*);   // lee botones
extern "C" void func_8001B204_1BE04(uint8_t*, recomp_context*);     // registra/actualiza entrada
extern "C" void func_800058DC_64DC(uint8_t*, recomp_context*);      // programa pantalla siguiente

uint32_t g_mod_base = 0;
uint32_t g_mod_end = 0;

void ensure_mod_base() {
    if (g_mod_base != 0) return;
    g_mod_base = hh_trans_dst_for(kMod23Src, kMod23Size);
    g_mod_end = g_mod_base + kMod23Size;
}

// Campos de texto del módulo (offsets dentro del módulo) que el motor ya usa para sus rótulos.
// Los reutilizamos como etiquetas de IDIOMA: son buffers de texto válidos y renderizables.
// 0xFE68, 0xFE94, 0xFEC0 = "HIGH LETTERBOX" (18 B); 0xFE7C, 0xFEA8, 0xFED4 = "LOW" (5 B);
// 0xFEE4... Reutilizamos un juego contiguo de campos del submenú de resolución.
struct LabelSlot {
    uint32_t off;
};
constexpr uint32_t kLabelSlots[] = {
    0x0FE68,  // HIGH LETTERBOX
    0x0FE7C,  // LOW
    0x0FE94,  // HIGH LETTERBOX
    0x0FEA8,  // LOW
    0x0FEC0,  // HIGH LETTERBOX
    0x0FED4,  // LOW
};
constexpr int kNumLabels = sizeof(kLabelSlots) / sizeof(kLabelSlots[0]);

uint32_t label_addr(int i) { return g_mod_base + kLabelSlots[i]; }

// Escribe una etiqueta respetando el campo (espacios de relleno + NUL), en ASCII (1 byte/char).
void write_label(uint8_t* rdram, int i, const char* text) {
    const uint32_t addr = label_addr(i);
    const size_t len = std::strlen(text);
    for (size_t k = 0; k < len; k++) {
        rdram[((addr + k) - 0x80000000u) ^ 3u] = static_cast<uint8_t>(text[k]);
    }
    rdram[((addr + len) - 0x80000000u) ^ 3u] = 0;
}

struct LangItem {
    const char* code;
    int slot;
};
constexpr LangItem kLangs[] = {
    {"en", 0}, {"es", 1}, {"ca", 2}, {"fr", 3}, {"de", 4}, {"ja", 5},
};
constexpr int kLangCount = sizeof(kLangs) / sizeof(kLangs[0]);

int current_lang_index() {
    const std::string& cur = hh::text_current_language();
    for (int i = 0; i < kLangCount; i++) {
        if (cur == kLangs[i].code) return i;
    }
    return 0;
}

// Registra una entrada del menú replicando el prólogo real (resta de pila + guardado de ra/args)
// para que el 5.º argumento (por sp+0x10) llegue como en el original.
MY_NOINLINE void call_entry(uint8_t* rdram, recomp_context* ctx, uint32_t idx, uint32_t a1,
                            uint32_t y, uint32_t text_addr, uint32_t sel) {
    recomp_context t = *ctx;
    t.r29 = ctx->r29 - 0x20;
    MEM_W(0x1C, t.r29) = ctx->r31;
    MEM_W(0x20, t.r29) = ctx->r4;
    MEM_W(0x24, t.r29) = ctx->r5;
    t.r4 = idx;
    t.r5 = a1;
    t.r6 = y;
    t.r7 = text_addr;
    MEM_W(0x10, t.r29) = sel;
    func_8001B204_1BE04(rdram, &t);
}

MY_NOINLINE void goto_screen(uint8_t* rdram, recomp_context* ctx, uint32_t screen) {
    recomp_context t = *ctx;
    t.r4 = static_cast<uint32_t>(ctx->r4);
    t.r5 = screen;
    func_800058DC_64DC(rdram, &t);
}

// --- AJUSTES ------------------------------------------------------------------------------------
// Sustituye al setup del submenú de sonido (func_801C4960).
extern "C" void hh_pc_ajustes(uint8_t* rdram, recomp_context* ctx) {
    ensure_mod_base();
    if (trace_enabled()) {
        hh::log("[menu] AJUSTES setup obj=%08X base=%08X\n", static_cast<uint32_t>(ctx->r4),
                g_mod_base);
    }
    if (g_mod_base == 0) {
        func_801C4960_11BE430(rdram, ctx);
        return;
    }
    // Etiquetas: idx1 = IDIOMA, idx2 = SONIDO.
    write_label(rdram, 0, "IDIOMA");
    write_label(rdram, 1, "SONIDO");
    // Patrón del setup de sonido original: idx0 = caja de cursor (Y=0x76), idx1 y idx2 = entradas.
    call_entry(rdram, ctx, 0, 0x7D0, 0x76, 0x801CEE74, 0x7D0);
    call_entry(rdram, ctx, 1, 0x7D0, 0x8A, label_addr(0), 0x7D0);
    call_entry(rdram, ctx, 2, 0x7D0, 0x94, label_addr(1), 0x7D0);
    goto_screen(rdram, ctx, 0x801C4AA8);  // hh_pc_ajustes_input
}

extern "C" void hh_pc_ajustes_input(uint8_t* rdram, recomp_context* ctx) {
    recomp_context tb = *ctx;
    func_801C1340_11BAE10(rdram, &tb);
    const uint32_t btn = static_cast<uint32_t>(tb.r2);
    // Índice de AJUSTES (1=IDIOMA, 2=SONIDO) en 0x801D0000-0x373C.
    uint8_t& sel = *reinterpret_cast<uint8_t*>(rdram + (((0x801D0000u - 0x373Cu) - 0x80000000u) ^ 3u));
    if (trace_enabled() && btn != 0) {
        hh::log("[menu] AJUSTES input btn=%04X sel=%u\n", btn, sel);
    }
    if (btn & 0x800) {          // UP
        sel = (sel <= 1) ? 2 : sel - 1;
    } else if (btn & 0x400) {   // DOWN
        sel = (sel >= 2) ? 1 : sel + 1;
    } else if (btn & 0xB000) {  // A
        if (sel == 1) {
            if (trace_enabled()) hh::log("[menu] AJUSTES -> IDIOMA\n");
            goto_screen(rdram, ctx, 0x801C5108);
            return;
        }
        if (trace_enabled()) hh::log("[menu] AJUSTES -> SONIDO\n");
        func_801C4960_11BE430(rdram, ctx);
        return;
    } else if (btn & 0x4000) {  // B
        goto_screen(rdram, ctx, 0x801C1DB8);
        return;
    }
    write_label(rdram, 0, "IDIOMA");
    write_label(rdram, 1, "SONIDO");
    call_entry(rdram, ctx, 0, 0x7D0, 0x76, 0x801CEE74, 0x7D0);
    call_entry(rdram, ctx, 1, 0x7D0, 0x8A, label_addr(0), 0x7D0);
    call_entry(rdram, ctx, 2, 0x7D0, 0x94, label_addr(1), 0x7D0);
}

// --- IDIOMA -------------------------------------------------------------------------------------
// Sustituye al setup del submenú de resolución (func_801C5108).
extern "C" void hh_pc_idioma(uint8_t* rdram, recomp_context* ctx) {
    ensure_mod_base();
    if (trace_enabled()) {
        hh::log("[menu] IDIOMA setup obj=%08X base=%08X cur=%s\n", static_cast<uint32_t>(ctx->r4),
                g_mod_base, hh::text_current_language().c_str());
    }
    if (g_mod_base == 0) {
        func_801C5108_11BEBD8(rdram, ctx);
        return;
    }
    const int cur = current_lang_index();
    static const char* kNames[kLangCount] = {"ENGLISH", "ESPANOL", "CATALA",
                                             "FRANCAIS", "DEUTSCH", "JAPONES"};
    for (int i = 0; i < kLangCount; i++) {
        write_label(rdram, i, kNames[i]);
        call_entry(rdram, ctx, static_cast<uint32_t>(i), i == cur ? 0x6Bu : 0x73u,
                   static_cast<uint32_t>(0x8A + 0x0A * i), label_addr(i), 0x7D0);
    }
    goto_screen(rdram, ctx, 0x801C5378);  // hh_pc_idioma_input
}

extern "C" void hh_pc_idioma_input(uint8_t* rdram, recomp_context* ctx) {
    static int sel = 0;
    static bool inited = false;
    if (!inited) {
        sel = current_lang_index();
        inited = true;
    }
    recomp_context tb = *ctx;
    func_801C1340_11BAE10(rdram, &tb);
    const uint32_t btn = static_cast<uint32_t>(tb.r2);
    if (!trace_enabled()) inited = false;

    if (btn & 0x800) {
        sel = (sel <= 0) ? kLangCount - 1 : sel - 1;
    } else if (btn & 0x400) {
        sel = (sel + 1) % kLangCount;
    } else if (btn & 0xB000) {
        if (trace_enabled()) hh::log("[menu] IDIOMA -> set '%s'\n", kLangs[sel].code);
        hh::text_set_language(kLangs[sel].code);
        goto_screen(rdram, ctx, 0x801C5108);
        return;
    } else if (btn & 0x4000) {
        goto_screen(rdram, ctx, 0x801C4960);
        return;
    }
    static const char* kNames[kLangCount] = {"ENGLISH", "ESPANOL", "CATALA",
                                             "FRANCAIS", "DEUTSCH", "JAPONES"};
    for (int i = 0; i < kLangCount; i++) {
        write_label(rdram, i, kNames[i]);
        call_entry(rdram, ctx, static_cast<uint32_t>(i), i == sel ? 0x6Bu : 0x73u,
                   static_cast<uint32_t>(0x8A + 0x0A * i), label_addr(i), 0x7D0);
    }
}

}  // namespace

// Se re-registra tras cada carga de módulo (load_overlay_by_id reescribe func_map y puede borrar
// estos overrides si solapan su base). Ver src/hooks/sections.cpp.
extern "C" void hh_pc_menu_register() {
    recomp::overlays::add_loaded_function(0x801C4960, hh_pc_ajustes);
    recomp::overlays::add_loaded_function(0x801C4AA8, hh_pc_ajustes_input);
    recomp::overlays::add_loaded_function(0x801C5108, hh_pc_idioma);
    recomp::overlays::add_loaded_function(0x801C5378, hh_pc_idioma_input);
}
