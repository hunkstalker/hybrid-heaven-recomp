// Seccion de registro del recomp per-file: el port envuelve los DOS loaders del juego para decirle
// a librecomp que fichero de codigo ocupa que direccion AHORA (las llamadas van por direccion con
// use_lookup_for_all_function_calls y los overlays comparten/se intercambian bases de VRAM).
//
// Modelo (estilo del port de referencia, docs/adr/0009): `include/hh/file_table.h` lista los 91
// code files {id, vram, size} en el MISMO orden que `code_files.overlays.txt`
// (= overlay_sections_by_index de N64Recomp). `announce_load(id, dest)`:
//   1) evita lo que solape la base cargada (unload_overlay_by_id),
//   2) registra la seccion vigente (load_overlay_by_id).
// Los loaders del juego se envuelven por direccion con `add_loaded_function` (no se toca el C
// generado): FUN_8000469C (file_load) y FUN_80004838 (streamed, un trozo por llamada; el fichero
// 57 de combate solo carga por este).
//
// Sustituye a `module_sources.inc` / `load_module_by_source` (registro por offset de ROM retail).

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <atomic>
#include <mutex>
#include <vector>

#include "../../build/recomp/RecompiledFuncs/recomp_overlays.inl"
#include "../../build/recomp/RecompiledFuncs/runtime_funcs.inl"

#include "librecomp/overlays.hpp"
#include "hh.h"
#include "hh/file_table.h"
#include "hh/menu.h"
#include "hh/overlay.h"
#include "hh/save_edit.h"

extern "C" void func_8000469C_529C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80004838_5438(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_801C1DB8_11BB888(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_801C4200_11BDCD0(uint8_t* rdram, recomp_context* ctx);  // update submenú BATTLE MODE
extern "C" void func_801C44C4_11BDF94(uint8_t* rdram, recomp_context* ctx);  // update COMBATE DE CRIATURAS
extern "C" void func_801C1508_11BAFD8(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80383AD4_12F4B04(uint8_t* rdram, recomp_context* ctx);  // estado de logos de ARRANQUE (file 055)
extern "C" unsigned long long hh_get_vi_count(void);                          // diagnostico (VI)
extern "C" void func_801C18FC_11BB3CC(uint8_t* rdram, recomp_context* ctx);
extern "C" void hh_title_ctor_hook(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001B204_1BE04(uint8_t* rdram, recomp_context* ctx);  // compone texto de menú
extern "C" void hh_entry_register_hook(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800058DC_64DC(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80005670_6270(uint8_t* rdram, recomp_context* ctx);  // crea objeto de transición
extern "C" void func_8001BFE4_1CBE4(uint8_t* rdram, recomp_context* ctx);  // carga bitmap de glifo
extern "C" void func_8001D394_1DF94(uint8_t* rdram, recomp_context* ctx);  // código EUC -> slot
extern "C" void func_801C1340_11BAE10(uint8_t* rdram, recomp_context* ctx);  // lee botones (direcciones)
extern "C" void func_801C1334_11BAE04(uint8_t* rdram, recomp_context* ctx);  // lee botones (A/START)
extern "C" void hh_pc_menu_register();  // src/hooks/hh_menu.cpp
extern "C" void hh_accent_register();   // src/hooks/text_glyphs.cpp
extern "C" void load_overlay_by_id(uint32_t id, uint32_t ram_addr);
extern "C" void unload_overlay_by_id(uint32_t id);
extern "C" void hh_title_menu_hook(uint8_t* rdram, recomp_context* ctx);   // definido abajo
extern "C" void hh_battle_menu_hook(uint8_t* rdram, recomp_context* ctx);  // definido abajo
extern "C" void hh_battle_creature_hook(uint8_t* rdram, recomp_context* ctx);  // definido abajo

namespace {

constexpr uint32_t kFileLoadAddress = 0x8000469C;          // file_load(id, dest)
constexpr uint32_t kFileLoadStreamedAddress = 0x80004838;  // streamed(id, dest), pieza a pieza
constexpr size_t kFileCount = sizeof(hh::kCodeFiles) / sizeof(hh::kCodeFiles[0]);

// A2 (paso 5, control total): con nuestro overlay como UI del menú de título, el handler NATIVO se
// sigue ejecutando (mantiene el estado del juego) pero con su input NEUTRALIZADO: las dos funciones
// con las que lee los botones devuelven 0, así su cursor/pantalla no se mueven y no compiten con
// nuestra navegación. La bandera solo está activa durante esa llamada (ver hh_title_menu_hook).
bool g_mute_native_input = false;

// A2: cuando el overlay confirma una accion que debe ejecutar el JUEGO (p. ej. CONTINUAR), se
// reenvia al dispatch NATIVO del menu de titulo: se fija `sel` (0x801CC8C4) al indice nativo y se
// inyecta una pulsacion de A una sola vez, para que el handler corra su rama real (carga de
// partida). Ver `feed_menu_navigation` y `hh_title_menu_hook`.
bool g_inject_native_a = false;

// MODO COMBATE: cursor del submenú de batalla (byte global que usa func_801C4200; 0..3 =
// VS MODE / CREATURE BATTLE / DATA EDIT / EXIT). El overlay lo fija y reenvía A cuando confirma una
// entrada, igual que el `sel` de la raíz.
constexpr uint32_t kBattleCursorAddr = 0x801CC8C8u;

extern "C" void hh_native_dir_input(uint8_t* rdram, recomp_context* ctx) {
    if (g_mute_native_input) {
        ctx->r2 = 0;
        return;
    }
    func_801C1340_11BAE10(rdram, ctx);
}

extern "C" void hh_native_ab_input(uint8_t* rdram, recomp_context* ctx) {
    if (g_inject_native_a) {
        ctx->r2 = 0x8000;   // A: reenvia la accion del overlay al dispatch nativo (una vez)
        return;
    }
    if (g_mute_native_input) {
        ctx->r2 = 0;
        return;
    }
    func_801C1334_11BAE04(rdram, ctx);
}

// ---------------------------------------------------------------------------------------------
// Intro: logos HD (KONAMI/KCEO) + codigo Konami -> EXTRAS.
//
// Mientras el handler del titulo esta en el estado del logo KONAMI (func_801C1764) o KCEO
// (func_801C17C8) publicamos nuestra imagen HD (fondo blanco) por el overlay, ocultando el logo
// nativo (queda debajo). El input nativo se mutea: el skip con START lo gestionamos nosotros
// reenviando al estado de espera nativo (func_801C1A30). Durante el logo KONAMI escuchamos el codigo
// Konami (secuencia clasica); si se completa, suena el SFX de unlock y se desbloquea EXTRAS. Un
// timeout de ~2 s cancela la secuencia y deja que la intro siga por donde iba.
//
// NOTA: el `D_801CC8CC` (0x801CC8CC) es la bandera que el handler KONAMI lee: si == 0 pasa a KCEO.
// Mientras el codigo esta en curso la forzamos a != 0 para "congelar" el logo KONAMI (pausa).
// Ver notes/2026-09-26-h-logos-intro-hd-y-konami.md.

constexpr uint32_t kBootFlagHi = 0x801D0000;
constexpr int kKonamiTimeout = 120;   // ~2 s a 60 Hz

// Logos de la intro en HD (PNG en `<exe>/logos/`). El set MODERNO (fondo negro) se usa si EXTRAS se
// desbloqueo en esta sesion (codigo Konami) o si el ajuste EXTRAS -> LOGOS ORIGINALES esta en NO; si
// no, los CLASICOS (fondo blanco).
bool logo_is_modern(const std::string& name) {
    return name == "konami-2023.png" || name == "kceo-2000.png";
}
bool use_modern_logos() {
    return hh::menu::extras_code_unlocked() || hh::extras_config().original_logos != "si";
}
const char* konami_logo() {
    return use_modern_logos() ? "konami-2023.png" : "konami-1998.png";
}
const char* kceo_logo() {
    return use_modern_logos() ? "kceo-2000.png" : "kceo-1995.png";
}

constexpr uint32_t kBtnUp = 0x0800, kBtnDown = 0x0400, kBtnLeft = 0x0200, kBtnRight = 0x0100;
constexpr uint32_t kBtnB = 0x4000, kBtnA = 0x8000, kBtnStart = 0x1000;
// Secuencia clasica: ↑ ↑ ↓ ↓ ← → ← → B A.
constexpr uint32_t kKonamiSeq[10] = { kBtnUp, kBtnUp, kBtnDown, kBtnDown, kBtnLeft, kBtnRight,
                                      kBtnLeft, kBtnRight, kBtnB, kBtnA };

std::string g_logo_shown;                 // nombre del PNG publicado ("" = ninguno)
int g_konami_idx = 0;                      // progreso del codigo (0 = inactivo)
int g_konami_timeout = 0;                  // frames restantes sin pulsar
uint32_t g_logo_prev_dir = 0;              // flanco de direcciones
uint32_t g_logo_prev_ab = 0;               // flanco de A/B/START

std::string logo_path(const char* name) {
    return (hh::get_app_folder_path() / "logos" / name).string();
}

void show_logo(const char* name) {
    if (g_logo_shown == name) return;
    g_logo_shown = name;
    g_logo_prev_dir = 0;
    g_logo_prev_ab = 0;
    hh::overlay::set_screen_image(logo_path(name), logo_is_modern(name));
}

uint32_t read_raw_dir(uint8_t* rdram, recomp_context* ctx) {
    recomp_context t = *ctx;
    func_801C1340_11BAE10(rdram, &t);
    return static_cast<uint32_t>(t.r2) & 0xFFFFu;
}
uint32_t read_raw_ab(uint8_t* rdram, recomp_context* ctx) {
    recomp_context t = *ctx;
    func_801C1334_11BAE04(rdram, &t);
    return static_cast<uint32_t>(t.r2) & 0xFFFFu;
}

// Procesa el codigo Konami durante el logo KONAMI. `pdir`/`pab` son flancos de pulsacion.
void konami_tick(uint8_t* rdram, uint32_t pdir, uint32_t pab) {
    (void)rdram;
    static const bool trace = std::getenv("HH_MENU_TRACE") != nullptr;
    const uint32_t pressed = (pdir & (kBtnUp | kBtnDown | kBtnLeft | kBtnRight)) |
                             (pab & (kBtnB | kBtnA));
    if (pressed == 0) {
        if (g_konami_idx > 0 && --g_konami_timeout <= 0) {
            g_konami_idx = 0;
            if (trace) hh::log("[konami] timeout: secuencia cancelada\n");
        }
        return;
    }
    if (g_konami_idx == 0) {
        if (pressed == kBtnUp) {
            g_konami_idx = 1;
            g_konami_timeout = kKonamiTimeout;
            hh::menu_sfx::play(hh::menu_sfx::Sfx::KonamiCorrect);
            if (trace) hh::log("[konami] inicio (1/10)\n");
        }
        return;
    }
    if (pressed == kKonamiSeq[g_konami_idx]) {
        ++g_konami_idx;
        g_konami_timeout = kKonamiTimeout;
        if (g_konami_idx >= 10) {
            g_konami_idx = 0;
            hh::menu::unlock_extras();
            hh::menu_sfx::play(hh::menu_sfx::Sfx::KonamiUnlock);
            hh::overlay::flash_white(400);   // flash blanco al desbloquear (tapa el cambio a moderno)
            if (trace) hh::log("[konami] COMPLETADO: EXTRAS desbloqueado\n");
            return;
        }
        hh::menu_sfx::play(hh::menu_sfx::Sfx::KonamiCorrect);
        if (trace) hh::log("[konami] acierto (%d/10)\n", g_konami_idx);
    } else {
        hh::menu_sfx::play(hh::menu_sfx::Sfx::KonamiError);
        g_konami_idx = (pressed == kBtnUp) ? 1 : 0;   // reinicio (si fue ↑, arranca de nuevo)
        g_konami_timeout = (g_konami_idx > 0) ? kKonamiTimeout : 0;
        if (trace) hh::log("[konami] fallo: reinicio (idx=%d)\n", g_konami_idx);
    }
}

// NOTA: los handlers del modulo de TITULO (0x801C1624 / 0x801C1764 / 0x801C17C8) son el REPLAY del
// modo attract (mucho despues de la ciudad + HYBRID HEAVEN), NO la intro de arranque. La intro real
// la pinta el modulo file 055 (ver hh_boot_logo_hook mas abajo). Antes se envolvian para publicar el
// logo HD; se RETIRARON porque hacia aparecer KONAMI/KCEO otra vez durante el attract.

// Lee la bandera de arranque D_801CC8CC (la que decide crear la secuencia de logos).
uint8_t read_boot_flag(uint8_t* rdram) {
    gpr base = (gpr)(int32_t)kBootFlagHi;
    return static_cast<uint8_t>(MEM_BU(-0x3734, base));
}

// DIAGNOSTICO/PARIDAD: envuelve el bootstate (0x801C1508). Con HH_FORCE_INTRO=1 fuerza la bandera a
// 2 para crear la secuencia (en headless la carrera ptick/bootstate la deja en 1 y la salta). Con
// HH_MENU_TRACE=1 traza los cambios de bandera, para saber si el arranque llega a pedir los logos.
extern "C" void hh_force_intro_hook(uint8_t* rdram, recomp_context* ctx) {
    if (std::getenv("HH_MENU_TRACE") != nullptr) {
        static uint8_t last = 0xFF;
        const uint8_t now = read_boot_flag(rdram);
        if (now != last) {
            last = now;
            hh::log("[intro] bootstate flag=%u\n", now);
        }
    }
    if (std::getenv("HH_FORCE_INTRO") != nullptr) {
        gpr base = (gpr)(int32_t)kBootFlagHi;
        MEM_BU(-0x3734, base) = 2;   // D_801CC8CC = 2 -> func_801C1508 llama a func_801C1624
    }
    func_801C1508_11BAFD8(rdram, ctx);
}

// ---------------------------------------------------------------------------------------------
// Intro de ARRANQUE (file 055, `func_80383AD4`). Los logos KONAMI/KCEO que se ven AL ARRANCAR los
// pinta el modulo de arranque (base 0x803837E0), NO el modulo de titulo: los handlers 0x801C1624/
// 1764/17C8 son el replay del modo attract, que corre mucho despues (t~30 s) — por eso la intro HD
// salia tarde. `func_80383AD4` corre cada frame durante los logos reales y sus banderas de capa (en
// la data del propio modulo) dicen cual se ve:
//   0x8038DBD8 (0x8039-0x2428) == 1 -> KONAMI (activa ~t=2.1-9.8 s)
//   0x8038DBD0 (0x8039-0x2430) == 1 -> KCEO   (activa ~t=7.7 s -> fin)
// Reflejamos esos logos con los PNG HD sin tocar el timing nativo: el skip con START nativo sigue
// funcionando y nuestro overlay (fondo negro + lienzo blanco + logo) tapa el logo nativo.
//
// Composicion (encargo del mantenedor): NEGRO de base, una capa BLANCA encima (lienzo; tambien
// rellena los laterales que el logo 4:3 no cubre) y el logo encima. Fades imitando el ORIGINAL: en
// vez de inventar tiempos, copiamos sus ALFAS de capa, que suben y bajan:
//   - KONAMI: alfa en 0x8038DBC0 (0x2440), sube 0x0C->0xFF y baja 0xFF->0 (fade-in y fade-out).
//   - KCEO:   alfa en 0x8038DBD4 (0x242C), sube al entrar y BAJA al final.
// El lienzo blanco sube con KONAMI (para que casen los dos fades) y se queda lleno durante los dos
// logos; al final cae junto con el alfa de KCEO. La bandera de KCEO (0x8038DBD0) marca el cambio.
constexpr uint32_t kBootLayerKonami = 0x8038DBD8u;   // flag capa KONAMI
constexpr uint32_t kBootLayerKceo = 0x8038DBD0u;     // flag capa KCEO
constexpr uint32_t kBootAlphaKonami = 0x8038DBC0u;   // alfa capa KONAMI (byte)
constexpr uint32_t kBootAlphaKceo = 0x8038DBD4u;     // alfa capa KCEO (byte)
// State machine del file 055 (para congelar la intro mientras se teclea el codigo Konami):
constexpr uint32_t kBootState = 0x8038DBB8u;         // 0=fade-in, 1=hold KONAMI, 2=fade-out, 3=fin
constexpr uint32_t kBootCounter = 0x8038DBB4u;       // contador del hold
constexpr uint32_t kBootFadeState = 0x8038DBCCu;     // estado de KCEO (func_80383D08): 1=fade-in,
                                                     // 2=hold, 3=fade-out, 4=fin
// Duracion del fade-out final: el nativo baja su alfa a ~12/VI desde vi=710 hasta el fin; de 255 a
// 0 son ~21 VI (~0.35 s). Lo anima UN solo fade del render thread para que sea identico entre
// sesiones (no depender de cuando acabe de cargar el modulo de titulo).
constexpr int kBootFinalFadeMs = 350;

bool g_boot_intro_active = false;    // fase de logos de arranque en curso
bool g_boot_showing_kceo = false;    // imagen actual = KCEO
bool g_boot_out_started = false;     // fade-out final ya disparado (render thread manda)
bool g_boot_konami_hold = false;     // C0 llego a 255 (fin del fade-in; ya es crossfade de logo)
bool g_boot_paused = false;          // pausa nativa por el codigo Konami en curso
int g_boot_prev_kceo = 0;            // alfa de KCEO del frame anterior (para detectar la bajada)

bool boot_layer_on(uint8_t* rdram, uint32_t addr) {
    return MEM_W(0, (gpr)(int32_t)addr) != 0;
}

// Lee un ALFA de capa: el valor va en el byte alto del word (lbu -> shift 24).
int boot_alpha(uint8_t* rdram, uint32_t addr) {
    return static_cast<int>((static_cast<uint32_t>(MEM_W(0, (gpr)(int32_t)addr)) >> 24) & 0xFFu);
}

// Borra el registro del logo publicado SIN limpiar la imagen (deja que corra el fade-out de render).
void detach_logo() {
    g_logo_shown.clear();
    g_logo_prev_dir = 0;
    g_logo_prev_ab = 0;
}

// Entra en la fase de logos de arranque (la llama el goto a 0x80383AD4 y el propio hook).
void boot_intro_enter() {
    g_boot_intro_active = true;
    g_boot_showing_kceo = false;
    g_boot_out_started = false;
    g_boot_konami_hold = false;
    g_boot_paused = false;
    g_boot_prev_kceo = 0;
    g_konami_idx = 0;
    g_konami_timeout = 0;
    g_logo_prev_dir = 0;
    g_logo_prev_ab = 0;
    // El telon negro (que tapa los logos nativos del boot) va ENCIMA de todo: se retira al arrancar
    // la intro para que se vean NUESTROS logos (la tarjeta opaca + el velo ya cubren el nativo).
    hh::overlay::set_screen_blackout(false);
    // Arranca en negro (velo lleno) ANTES de mostrar la imagen: evita un frame a plena luz.
    hh::overlay::set_screen_image_alpha(255, 0);
    show_logo(konami_logo());
}

// Congela el state machine del file 055 en el hold de KONAMI (pausa del codigo Konami). Se aplica
// DESPUES del original, para que el proximo frame parta del hold lleno.
void boot_native_pause(uint8_t* rdram) {
    MEM_W(0, (gpr)(int32_t)kBootState) = 1;              // hold KONAMI
    MEM_W(0, (gpr)(int32_t)kBootCounter) = 0;            // no avanzar al fade-out
    MEM_B(0, (gpr)(int32_t)kBootAlphaKonami) = (int8_t)0xFF;
    MEM_B(0, (gpr)(int32_t)kBootAlphaKceo) = 0;
}

// Envuelve el estado de logos de arranque: publica KONAMI/KCEO en HD con los alfas NATIVOS y
// escucha el codigo Konami (con pausa).
extern "C" void hh_boot_logo_hook(uint8_t* rdram, recomp_context* ctx) {
    const bool kceo = boot_layer_on(rdram, kBootLayerKceo);
    const int a_konami = boot_alpha(rdram, kBootAlphaKonami);
    const int a_kceo = boot_alpha(rdram, kBootAlphaKceo);

    if (!g_boot_intro_active) {
        boot_intro_enter();
    }
    // Cambio nativo KONAMI -> KCEO: cambia la imagen (la tarjeta se mantiene).
    if (kceo && !g_boot_showing_kceo) {
        show_logo(kceo_logo());
        g_boot_showing_kceo = true;
    }
    // Mientras es KONAMI, reafirma la imagen: tras completar el codigo, `konami_logo()` pasa a la
    // version MODERNA (fondo negro) y show_logo la cambia (idempotente si no ha cambiado).
    if (!kceo) {
        show_logo(konami_logo());
    }
    // Fade-out final: el alfa nativo de KCEO empieza a bajar (punto determinista en tiempo de
    // juego). Disparamos UN fade fijo del render thread y ya NO tocamos los alfas desde aqui, para
    // que no dependa de cuando acabe de cargar el modulo de titulo ni compita con el render.
    if (!g_boot_out_started && a_kceo > 0 && a_kceo < g_boot_prev_kceo) {
        hh::overlay::fade_out_screen_image(kBootFinalFadeMs);
        g_boot_out_started = true;
    }
    g_boot_prev_kceo = a_kceo;

    int logo_alpha = 255;   // alfa del logo (crossfade KONAMI<->KCEO)
    int fade = 255;         // nivel del grupo (velo negro = 1 - fade)
    if (!g_boot_out_started) {
        if (kceo) {
            // KCEO: crossfade-in (D4 subiendo) y luego hold.
            logo_alpha = a_kceo;
        } else if (!g_boot_konami_hold) {
            // Fade-in inicial del GRUPO (tarjeta+logo) desde negro: lo lleva el velo. El logo va
            // opaco, asi NO se lava contra la tarjeta.
            fade = a_konami;
            logo_alpha = 255;
            if (a_konami >= 255) g_boot_konami_hold = true;
        } else {
            // Crossfade-out de KONAMI sobre la tarjeta (el grupo ya esta a fondo).
            logo_alpha = a_konami;
        }
        // Skip con START: el nativo solo avanza KCEO en su estado 2 (hold); durante el fade-in
        // (estado 1) ignora START. Forzamos el fin del logo en la pulsacion -> 1 Enter = 1 skip.
        if (kceo) {
            const uint32_t dir = read_raw_dir(rdram, ctx);
            const uint32_t ab = read_raw_ab(rdram, ctx);
            const uint32_t pab = ab & ~g_logo_prev_ab;
            g_logo_prev_dir = dir;
            g_logo_prev_ab = ab;
            if (pab & kBtnStart) {
                MEM_W(0, (gpr)(int32_t)kBootFadeState) = 3;
            }
        }
        // Codigo Konami durante el hold de KONAMI.
        else if (g_boot_konami_hold) {
            const uint32_t dir = read_raw_dir(rdram, ctx);
            const uint32_t ab = read_raw_ab(rdram, ctx);
            konami_tick(rdram, dir & ~g_logo_prev_dir, ab & ~g_logo_prev_ab);
            g_logo_prev_dir = dir;
            g_logo_prev_ab = ab;
        }
        g_boot_paused = (g_konami_idx > 0);
        if (g_boot_paused) {
            logo_alpha = 255;
            fade = 255;
        }
        hh::overlay::set_screen_image_alpha(logo_alpha, fade);
    }

    if (std::getenv("HH_MENU_TRACE") != nullptr) {
        static int n = 0;
        if ((n++ % 20) == 0) {
            hh::log("[intro] boot logo kceo=%d ak=%d ae=%d la=%d fade=%d pause=%d out=%d vi=%llu\n",
                    kceo ? 1 : 0, a_konami, a_kceo, logo_alpha, fade, g_boot_paused ? 1 : 0,
                    g_boot_out_started ? 1 : 0, hh_get_vi_count());
        }
    }

    func_80383AD4_12F4B04(rdram, ctx);
    if (g_boot_paused) {
        boot_native_pause(rdram);   // congela para el proximo frame
    }
}

// Overlay A2: (re)registra el handler del menú de título. El loader de un módulo reescribe func_map
// y borra los overrides de su rango, así que hay que re-aplicarlo tras cada carga (además del
// registro inicial en register_runtime_functions).
void register_title_menu_hook() {
    recomp::overlays::add_loaded_function(0x801C1DB8, hh_title_menu_hook);
    // MODO COMBATE: update del submenú de batalla (también en file_024), para pilotar nuestra
    // subpantalla y despachar las entradas por su cursor.
    recomp::overlays::add_loaded_function(0x801C4200, hh_battle_menu_hook);
    // COMBATE DE CRIATURAS: pantalla interna (5 COMBATES / SUPERVIVENCIA), mismo control.
    recomp::overlays::add_loaded_function(0x801C44C4, hh_battle_creature_hook);
    // DIAGNOSTICO TEMPORAL: fuerza la escena de logos en headless (HH_FORCE_INTRO=1).
    recomp::overlays::add_loaded_function(0x801C1508, hh_force_intro_hook);
    // NOTA: los handlers de logos del modulo de TITULO (0x801C1624/1764/17C8) NO se envuelven: son
    // el replay del attract y hacian reaparecer KONAMI/KCEO tras la ciudad. La intro real (file 055)
    // se maneja abajo.
    // Intro de ARRANQUE (file 055): refleja KONAMI/KCEO con HD mientras corre la fase de logos.
    recomp::overlays::add_loaded_function(0x80383AD4, hh_boot_logo_hook);
    // Update del menú: registra/compone las etiquetas nativas (una vez por entrada). Se envuelve
    // para ocultarlas por defecto y poder restaurarlas con F6.
    recomp::overlays::add_loaded_function(0x801C18FC, hh_title_ctor_hook);
    // Composición de texto (residente): blankea el texto del menú nativo justo antes de leerlo, de
    // modo que sale en blanco ya desde el primer frame (sin ventana visible).
    recomp::overlays::add_loaded_function(0x8001B204, hh_entry_register_hook);
    // Paso 5: lectores de botones del handler nativo (direcciones y A/B/START), muteables.
    recomp::overlays::add_loaded_function(0x801C1340, hh_native_dir_input);
    recomp::overlays::add_loaded_function(0x801C1334, hh_native_ab_input);
}

bool env_set(const char* name) {
    const char* v = std::getenv(name);
    return v != nullptr && *v != '\0' && *v != '0';
}

std::mutex g_load_mutex;
// Indice en kCodeFiles (= indice de seccion) -> direccion cargada, o 0.
std::vector<uint32_t> g_loaded_at(kFileCount, 0);

int code_file_index(uint32_t id) {
    for (size_t i = 0; i < kFileCount; ++i) {
        if (hh::kCodeFiles[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;  // fichero de datos; no hay seccion que registrar
}

void announce_load(uint32_t id, uint32_t dest) {
    const int index = code_file_index(id);
    if (index < 0) {
        return;
    }
    const hh::CodeFile& file = hh::kCodeFiles[index];
    if (dest != file.vram) {
        // El codigo recompilado lleva su direccion de enlace en cada puntero que construye: cargado
        // en otra base seria incorrecto en sitios lejanos. Avisar y registrar en la base de enlace.
        std::fprintf(stderr, "[hh] file %u cargado en 0x%08X, pero su codigo enlaza en 0x%08X"
                             " -- se registra en la base de enlace\n", id, dest, file.vram);
        std::fflush(stderr);
    }

    std::lock_guard<std::mutex> lock(g_load_mutex);
    const uint32_t lo = file.vram;
    const uint32_t hi = file.vram + file.size;
    size_t evicted = 0;
    for (size_t i = 0; i < kFileCount; ++i) {
        if (g_loaded_at[i] == 0) {
            continue;
        }
        const uint32_t olo = g_loaded_at[i];
        const uint32_t ohi = olo + hh::kCodeFiles[i].size;
        if (olo < hi && lo < ohi) {
            unload_overlay_by_id(static_cast<uint32_t>(i));
            g_loaded_at[i] = 0;
            ++evicted;
        }
    }
    load_overlay_by_id(static_cast<uint32_t>(index), file.vram);
    g_loaded_at[index] = file.vram;
    // A2: al cargar (o recargar) un modulo, su seccion vuelve a escribir func_map y borra los
    // overrides del menu PC si caen en su rango. Re-registrarlos aqui los mantiene vigentes.
    // hh_pc_menu_register();  // DESACTIVADO: reemplazado por overlay propio
    register_title_menu_hook();

    if (env_set("HH_DEBUG_LOADS") || dest != file.vram) {
        std::fprintf(stderr, "[hh-load] file %3u (idx %d) -> 0x%08X (0x%06X bytes, %zu evicted)\n",
                     id, index, dest, file.size, evicted);
        std::fflush(stderr);
    }
}

// Loader normal: registra el fichero y luego ejecuta el original (que descomprime en RDRAM).
// A2: tras la carga se oculta el menú nativo del título (si es ese módulo) ANTES de que el juego lo
// componga; de lo contrario se vería durante un frame. Es idempotente y barato.
void file_load_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t id = static_cast<uint32_t>(ctx->r4);
    const uint32_t dest = static_cast<uint32_t>(ctx->r5);
    announce_load(id, dest);
    func_8000469C_529C(rdram, ctx);
    if (env_set("HH_MENU_TRACE") && (id == 23 || id == 24)) {
        hh::log("[load] modulo titulo id=%u dest=%08X\n", id, dest);
    }
    hh::menu_overlay::suppress_native(rdram);
}

// Loader streamed: el fichero no esta completo hasta que r2 != 0; se anuncia en esa llamada.
void file_load_streamed_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t id = static_cast<uint32_t>(ctx->r4);
    const uint32_t dest = static_cast<uint32_t>(ctx->r5);
    func_80004838_5438(rdram, ctx);
    if (ctx->r2 != 0) {
        announce_load(id, dest);
        hh::menu_overlay::suppress_native(rdram);
    }
}

}  // namespace

void hh::register_overlays() {
    recomp::overlays::overlay_section_table_data_t sections{
        section_table,
        ARRLEN(section_table),
        num_sections,
    };
    recomp::overlays::overlays_by_index_t overlays{
        overlay_sections_by_index,
        ARRLEN(overlay_sections_by_index),
    };
    recomp::overlays::register_overlays(sections, overlays);

    // Coherencia tabla generada <-> file_table.h.
    if (ARRLEN(overlay_sections_by_index) != hh::kCodeFileCount) {
        std::fprintf(stderr, "[hh] overlay_sections_by_index=%zu entradas, kCodeFiles=%zu:"
                             " regenera el C y file_table.h (tools/regenerate.py)\n",
                     ARRLEN(overlay_sections_by_index), hh::kCodeFileCount);
        std::fflush(stderr);
        std::abort();
    }
}

// A2: contador de transiciones de pantalla (func_800058DC). El SFX del menú suena por CAMBIO REAL:
// cursor movido -> move; pantalla cambiada -> aceptar/atrás. Así no suena si el botón no hace nada.
static std::atomic<uint32_t> g_goto_count{ 0 };

// Dificultad de la partida nueva en su codificación NATIVA (byte global 0x801BBC0D):
// 0=NORMAL, 1=DIFÍCIL, 2=DEFINITIVO. La lista del overlay va en orden inverso
// (DEFINITIVO/DIFÍCIL/NORMAL), de ahí el mapeo. Por defecto NORMAL.
static int native_difficulty_value() {
    const hh::menu::Screen* d = hh::menu::screen(hh::menu::ScreenId::Difficulty);
    if (d == nullptr) return 0;
    for (size_t i = 0; i < d->entries.size(); ++i) {
        if (!d->entries[i].marked) continue;
        return (i == 0) ? 2 : (i == 1) ? 1 : 0;   // DEFINITIVO / DIFÍCIL / NORMAL
    }
    return 0;
}

// A2 (paso 5, control total): alimenta NUESTRO menú con el input del juego (los mismos botones que
// lee el handler nativo, que queda muteado). Arriba/abajo mueven el cursor; izq/der cambian el valor
// de un selector lateral; A marca/selecciona (entra en submenús) y B atrás. Los cambios son en vivo
// (sin X/"aplicar"); las ACCIONES llegan en el paso 6 (de momento, solo DEBUG engancha el modo
// desarrollador). La raíz no tiene "atrás" (el modelo lo ignora).
static void feed_menu_navigation(uint8_t* rdram, recomp_context* ctx) {
    // Test headless (HH_SAVEEDIT_TEST=1): carga el slot 0, fija progreso/nivel, guarda y verifica el
    // round-trip. Solo una vez. No requiere mando.
    static const bool saveedit_test = env_set("HH_SAVEEDIT_TEST");
    if (saveedit_test) {
        static bool done = false;
        if (!done) {
            done = true;
            // Prueba headless v3: abre el .pak, cambia progreso/nivel/técnica/item del slot 0, guarda
            // y reabre para comprobar el round-trip en el fichero.
            hh::save::load();
            hh::save::set_progress_of(0, 0x0A);   // 1-0
            hh::save::set_level_of(0, 0x12);      // 19 (mostrado 20 si +1)
            hh::save::set_tech_learned_of(0, 0, true);
            hh::save::set_item_count_of(0, 0, 7);
            hh::log("[save-edit][test] antes: prog=%u lvl=%u tech0=%d item0=%u\n",
                    (unsigned)hh::save::progress_of(0), (unsigned)hh::save::level_of(0),
                    hh::save::tech_learned_of(0, 0) ? 1 : 0, (unsigned)hh::save::item_count_of(0, 0));
            hh::save::save(0);
            hh::save::unload();
            hh::save::load();
            hh::log("[save-edit][test] despues: prog=%u lvl=%u tech0=%d item0=%u\n",
                    (unsigned)hh::save::progress_of(0), (unsigned)hh::save::level_of(0),
                    hh::save::tech_learned_of(0, 0) ? 1 : 0, (unsigned)hh::save::item_count_of(0, 0));
        }
        return;   // en modo test no se procesa input
    }
    // a0 del handler del menú de título = objeto del menú; lo necesita el disparo nativo de
    // GAME START (ver más abajo). Se lee ANTES de las copias que usa la lectura de botones.
    const uint32_t obj = static_cast<uint32_t>(ctx->r4);
    recomp_context td = *ctx;
    func_801C1340_11BAE10(rdram, &td);   // direcciones
    recomp_context ta = *ctx;
    func_801C1334_11BAE04(rdram, &ta);   // A/B/START
    const uint32_t btn = static_cast<uint32_t>(td.r2) | static_cast<uint32_t>(ta.r2);
    static uint32_t prev = 0;
    // CONTROLES: mientras se captura un input para reasignar, se consume el frame y NO se navega
    // (el input va a la captura; ESC cancela). El handler nativo sigue corriendo (muteado).
    // Se RE-LEE el estado TRAS `pad_capture_poll` (que puede haber ASIGNADO el input): el nuevo
    // binding entra asi en `prev` y no genera un flanco falso (p. ej. al asignar la tecla de
    // "atras", que si no volveria un menu).
    if (hh::pad_capture_active()) {
        hh::pad_capture_poll();
        recomp_context td2 = *ctx;
        func_801C1340_11BAE10(rdram, &td2);
        recomp_context ta2 = *ctx;
        func_801C1334_11BAE04(rdram, &ta2);
        prev = static_cast<uint32_t>(td2.r2) | static_cast<uint32_t>(ta2.r2);
        return;
    }
    const uint32_t pressed = btn & ~prev;   // flanco de pulsación (el juego repite al mantener)
    prev = btn;
    // Tras asignar/cancelar se bloquea 0.25 s SOLO aceptar/atras (no el resto del control): asi el
    // input de la asignacion (p. ej. la tecla de "atras") no ejecuta su accion mientras se suelta.
    const bool nav_block = hh::pad_capture_blocking();
    hh::menu::Event ev = hh::menu::Event::None;
    // Pantalla ANTES de procesar el boton: un mismo `Accept` que ENTRA en un submenu no debe
    // ejecutar acciones de la pantalla HIJA. Sin esto, entrar en IDIOMA aplicaba el idioma del
    // cursor (p. ej. al reentrar en IDIOMA tras senalarlo sin confirmar). Solo si seguimos en la
    // misma pantalla se aplican las acciones.
    const hh::menu::ScreenId screen_before = hh::menu::current_screen().id;
    // Direcciones (up/down 0x800/0x400, left/right 0x200/0x100). El FLANCO (pressed) mueve al
    // instante; el REPEAT (mantener) emite pasos extra tras ~0.4 s, acelerando (0.10 s -> 0.03 s).
    // Se resuelve en un unico sitio para no pisar el evento con otra direccion.
    uint32_t dir = pressed & (0x800u | 0x400u | 0x200u | 0x100u);
    {
        static uint32_t held = 0;
        static double dir_next = 0.0;
        static int dir_repeats = 0;
        static bool emitted = false;   // ¿ya se movio en este frame (flanco o repeat)?
        const double t = std::chrono::duration<double>(
                             std::chrono::steady_clock::now().time_since_epoch()).count();
        if (dir == 0) {
            held = 0;
            dir_repeats = 0;
            emitted = false;
        } else if (dir != held) {
            held = dir;               // direccion nueva: flanco inmediato
            dir_next = t + 0.40;
            dir_repeats = 0;
            emitted = false;
        } else if (t >= dir_next) {   // direccion mantenida: repetir
            dir_repeats++;
            dir_next = t + std::max(0.03, 0.10 - 0.006 * dir_repeats);
            emitted = false;
        } else {
            emitted = true;           // mantenida pero aun en el retardo: no emitir nada
        }
        if (!emitted) {
            if (dir & 0x800u) ev = hh::menu::move_up();
            else if (dir & 0x400u) ev = hh::menu::move_down();
            else if (dir & 0x200u) ev = hh::menu::move_left();
            else if (dir & 0x100u) ev = hh::menu::move_right();
            emitted = (ev != hh::menu::Event::None);
        }
    }
    if (!nav_block && (pressed & 0x8000u)) ev = hh::menu::confirm();   // A: entra / marca
    if (!nav_block && (pressed & 0x4000u)) ev = hh::menu::back();      // B: atras (en vivo, sin X)
    const bool same_screen = (hh::menu::current_screen().id == screen_before);
    // MODO COMBATE: al confirmar la entrada de la raiz arrancamos TAMBIEN el submenu NATIVO
    // (sel=2 + A inyectada) para que exista su estado (callback func_801C4200) y podamos despachar
    // cada opcion por su cursor. El overlay dibuja la subpantalla propia (rotulos traducidos).
    if (ev == hh::menu::Event::Accept && hh::overlay::enabled() &&
        hh::menu::current_screen().id == hh::menu::ScreenId::BattleMode &&
        screen_before == hh::menu::ScreenId::Root) {
        rdram[(0x801CC8C4u - 0x80000000u) ^ 3u] = 2;   // sel = BATTLE MODE
        g_inject_native_a = true;
    }
    // Selectores con acción: DEBUG (modo desarrollador de RT64, Inspector con F1), P. COMPLETA
    // (ventana borderless/windowed), VSYNC, LÍMITE DE FPS y MOSTRAR FPS. Todos persisten en
    // config.ini [video]. Solo al cambiar el valor (izq/der) o al confirmar con A, no al pasar el
    // cursor por encima.
    if (ev != hh::menu::Event::None && same_screen &&
        (pressed & (0x100u | 0x200u | 0x8000u))) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            if (cur.kind == hh::menu::Kind::Binding) {
                hh::pad_begin_capture(cur.remap_key);   // A sobre una fila -> capturar input
            } else if (cur.action == hh::menu::Action::ToggleDebug) {
                hh::video_set_developer_mode(cur.value != 0);
            } else if (cur.action == hh::menu::Action::ToggleFullscreen) {
                hh::video_set_fullscreen(cur.value != 0);
            } else if (cur.action == hh::menu::Action::ToggleVsync) {
                hh::video_set_vsync(cur.value != 0);
            } else if (cur.action == hh::menu::Action::FpsLimit) {
                const int hz = (cur.value > 0 && cur.value < static_cast<int>(cur.options.size()))
                                   ? std::atoi(cur.options[cur.value].c_str())
                                   : 0;
                hh::video_set_fps_limit(hz);
            } else if (cur.action == hh::menu::Action::ToggleShowFps) {
                hh::video_set_show_fps(cur.value != 0);
            } else if (cur.action == hh::menu::Action::MsaaSelect) {
                static const char* kMsaa[] = { "off", "2x", "4x", "8x" };
                const int n = static_cast<int>(sizeof(kMsaa) / sizeof(kMsaa[0]));
                hh::video_set_msaa(kMsaa[(cur.value >= 0 && cur.value < n) ? cur.value : 3]);
            } else if (cur.action == hh::menu::Action::VolumeSelect) {
                hh::audio_set_volume(std::clamp(cur.value, 0, 10) * 10);
            } else if (cur.action == hh::menu::Action::OutputSelect) {
                // Orden del selector: MONO, ESTÉREO, AURICULARES.
                static const char* kOut[] = { "mono", "estereo", "auriculares" };
                const int n = static_cast<int>(sizeof(kOut) / sizeof(kOut[0]));
                hh::audio_set_output(kOut[(cur.value >= 0 && cur.value < n) ? cur.value : 1]);
            } else if (cur.action == hh::menu::Action::MenuSfxToggle) {
                hh::audio_set_menu_sfx(cur.value != 0);
            } else if (cur.action == hh::menu::Action::ToggleVibration) {
                hh::input_set_vibration(cur.value != 0);
            } else if (cur.action == hh::menu::Action::ResetControls) {
                hh::pad_reset_defaults();
            } else if (cur.action == hh::menu::Action::ToggleExtrasPersist) {
                hh::extras_set_persist(cur.value != 0);
            } else if (cur.action == hh::menu::Action::ToggleOriginalLogos) {
                hh::extras_set_original_logos(cur.value != 0);
            } else if (cur.action == hh::menu::Action::ResolutionSelect) {
                if (cur.value >= 0 && cur.value < static_cast<int>(cur.options.size())) {
                    hh::video_set_resolution(cur.options[cur.value]);
                }
            } else if (cur.action == hh::menu::Action::RatioSelect) {
                static const char* kAspect[] = { "auto", "original", "4:3", "16:9", "16:10", "21:9" };
                static const double kTarget[] = { 0.0, 0.0, 4.0 / 3.0, 16.0 / 9.0, 16.0 / 10.0,
                                                  21.0 / 9.0 };
                const int n = static_cast<int>(sizeof(kAspect) / sizeof(kAspect[0]));
                const int idx = (cur.value >= 0 && cur.value < n) ? cur.value : 0;
                hh::video_set_aspect(kAspect[idx], kTarget[idx]);
                // RATIO filtra RESOLUCIÓN: aplicar tambien la resolucion resultante del nuevo ratio.
                for (const hh::menu::Entry& e : s.entries) {
                    if (e.action == hh::menu::Action::ResolutionSelect && !e.options.empty() &&
                        e.value >= 0 && e.value < static_cast<int>(e.options.size())) {
                        hh::video_set_resolution(e.options[e.value]);
                        break;
                    }
                }
            } else if (cur.action == hh::menu::Action::SaveEditSlot) {
                // CARGAR PARTIDA: cambia el slot que se edita y refresca (v3: se edita el .pak, no
                // los globals del juego, así que "cargar" es solo releer el fichero).
                hh::menu::set_save_edit_slot(cur.value);
                hh::log("[save-edit] CARGAR slot=%d\n", hh::menu::save_edit_slot());
                hh::menu::capture_tech_baseline();
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditProgress) {
                hh::save::set_progress_of(hh::menu::save_edit_slot(), hh::menu::save_edit_progress_value(cur.value));
            } else if (cur.action == hh::menu::Action::SaveEditLevel) {
                hh::save::set_level_of(hh::menu::save_edit_slot(), static_cast<uint8_t>(cur.value - 1));
            } else if (cur.action == hh::menu::Action::SaveEditBodyState) {
                hh::menu::set_save_edit_body_state(cur.value);
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditBodyValue) {
                hh::save::set_body_stat_of(hh::menu::save_edit_slot(), cur.index, hh::menu::save_edit_body_state(),
                                        static_cast<uint16_t>(cur.value));
            } else if (cur.action == hh::menu::Action::SaveEditItem) {
                hh::save::set_item_count_of(hh::menu::save_edit_slot(), cur.index, static_cast<uint8_t>(cur.value));
            }
        }
    }
    // EDICIÓN DE PARTIDA: HABILIDADES (toggle por fila), GUARDAR (serializa los globals al slot).
    if (ev == hh::menu::Event::Accept && same_screen) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            if (s.id == hh::menu::ScreenId::SaveEditAbilities &&
                cur.kind == hh::menu::Kind::Toggle) {
                hh::save::set_tech_learned_of(hh::menu::save_edit_slot(), cur.index, cur.marked);
            } else if (cur.action == hh::menu::Action::SaveEditAbilitiesBulk) {
                // 0 SIN CAMBIOS (restaura la copia de la carga), 1 TODO SÍ, 2 TODO NO. Se guarda el
                // estado en el modelo (g_edit_tech_bulk) para que el refresco no vuelva a SIN CAMBIOS.
                const int mode = cur.value;
                hh::menu::set_save_edit_tech_bulk(mode);
                for (int id = 0; id < hh::save::kTechCount; ++id) {
                    if (mode == 1) hh::save::set_tech_learned_of(hh::menu::save_edit_slot(), id, true);
                    else if (mode == 2) hh::save::set_tech_learned_of(hh::menu::save_edit_slot(), id, false);
                    else hh::menu::restore_tech_baseline(id);
                }
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditSave) {
                // GUARDAR PARTIDA: valor 0 = NUEVA PARTIDA (primer hueco libre), 1..N = slot concreto.
                hh::menu::set_save_edit_save_target(cur.value);
                const int sslot = hh::menu::save_edit_save_target_slot();
                hh::log("[save-edit] GUARDAR destino=%d slot=%d progress=%u level=%u\n", cur.value,
                        sslot, (unsigned)hh::save::progress_of(sslot),
                        (unsigned)hh::save::level_of(sslot));
                hh::save::save(sslot, rdram, ctx);
                hh::menu::refresh_save_edit();
            }
        }
    }
    // CONTINUAR (raiz): reenvia la accion al menu NATIVO. El indice de seleccion del juego
    // (`0x801CC8C4`) va 0..4 = NEW GAME / CONTINUE / BATTLE MODE / SOUND / RESOLUTION; se fija a
    // CONTINUE (1) y se inyecta A una vez, de modo que el handler nativo ejecute su rama real
    // (func_801C3CDC: desmonta el menu y carga la partida). Solo con el overlay controlando.
    if (ev == hh::menu::Event::Accept && same_screen && hh::overlay::enabled()) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size()) &&
            s.entries[s.cursor].action == hh::menu::Action::Continue) {
            rdram[(0x801CC8C4u - 0x80000000u) ^ 3u] = 1;   // sel = CONTINUE
            g_inject_native_a = true;
        }
    }
    // EMPEZAR PARTIDA (NUEVA PARTIDA): arranca la partida con la dificultad elegida, reutilizando el
    // flujo NATIVO de GAME START. La rama idx0 del submenú de NUEVA PARTIDA (func_801C3A40) hace
    // func_80005670(obj, 0x80044090) y fija el callback func_801C3BA4; a partir de ahí la cadena
    // nativa (func_801C3BA4 -> func_801C3BD8 -> func_801C3C14) crea la partida. NO se pasa por
    // func_801C3940: solo resetea la dificultad y registra las etiquetas del submenú (que el overlay
    // ya dibuja), y resetearía la dificultad que acabamos de fijar. Solo con el overlay controlando.
    if (ev == hh::menu::Event::Accept && same_screen && hh::overlay::enabled()) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size()) &&
            s.entries[s.cursor].action == hh::menu::Action::StartGame) {
            const int difficulty = native_difficulty_value();
            rdram[(0x801BBC0Du - 0x80000000u) ^ 3u] = static_cast<uint8_t>(difficulty);
            recomp_context t = *ctx;
            t.r4 = obj;
            t.r5 = 0x80044090u;             // descriptor de la transición (igual que el nativo)
            func_80005670_6270(rdram, &t);
            recomp_context u = *ctx;
            u.r4 = obj;
            u.r5 = 0x801C3BA4u;             // siguiente callback: GAME START nativo
            func_800058DC_64DC(rdram, &u);
            if (env_set("HH_MENU_TRACE")) {
                hh::log("[menu] EMPEZAR PARTIDA: difficulty=%d -> GAME START nativo\n", difficulty);
            }
        }
    }
    // SALIR (raíz): A cierra el port de forma ordenada (extra del port; ver docs/menu.md). Solo con
    // el overlay controlando el menú (con HH_OVERLAY=0 manda el nativo).
    if (ev == hh::menu::Event::Accept && same_screen && hh::overlay::enabled()) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size()) &&
            s.entries[s.cursor].action == hh::menu::Action::Exit) {
            hh::request_quit();
        }
    }
    // IDIOMA: A sobre una opción de la lista cambia el idioma (texto in-game + etiquetas del menú).
    // El confirm() del modelo ya marca la opción; aquí solo aplicamos el cambio. `same_screen` evita
    // aplicarlo al ENTRAR en el submenú (el Accept de entrar ya no cuenta como confirmación interna).
    if (ev == hh::menu::Event::Accept && same_screen && hh::overlay::enabled()) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.id == hh::menu::ScreenId::Language) {
            static const char* kLangCodes[] = { "en", "es", "ca", "fr", "de", "ja" };
            const int n = static_cast<int>(sizeof(kLangCodes) / sizeof(kLangCodes[0]));
            if (s.cursor >= 0 && s.cursor < n) {
                hh::text_set_language(kLangCodes[s.cursor]);
            }
        }
    }
    // MODO COMBATE: nuestra subpantalla reenvia la accion al submenu NATIVO fijando su cursor
    // (0x801CC8C8) y A inyectada, igual que el `sel` de la raiz. La delegacion la hace
    // hh_battle_menu_hook (envuelve func_801C4200). A = entrada resaltada; B = EXIT (cursor 3).
    if (hh::overlay::enabled() && screen_before == hh::menu::ScreenId::BattleMode) {
        int battle_idx = -1;
        hh::menu::Action act = hh::menu::Action::None;
        if (ev == hh::menu::Event::Back) {
            battle_idx = 3;   // EXIT (el original vuelve a la raiz)
        } else if (ev == hh::menu::Event::Accept && same_screen) {
            const hh::menu::Screen& s = hh::menu::current_screen();
            if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
                act = s.entries[s.cursor].action;
                switch (act) {
                    case hh::menu::Action::BattleModeVs:       battle_idx = 0; break;
                    case hh::menu::Action::BattleModeCreature: battle_idx = 1; break;
                    case hh::menu::Action::BattleModeDataEdit: battle_idx = 2; break;
                    default: break;
                }
            }
        }
        if (battle_idx >= 0) {
            rdram[(kBattleCursorAddr - 0x80000000u) ^ 3u] = static_cast<uint8_t>(battle_idx);
            g_inject_native_a = true;
            if (battle_idx == 3) {
                while (hh::menu::depth() > 1) {
                    hh::menu::back();   // nuestra pila vuelve a la raiz (el nativo sale via EXIT)
                }
            } else if (act == hh::menu::Action::BattleModeCreature) {
                hh::menu::push(hh::menu::ScreenId::BattleCreature);   // subpantalla interna
            }
            if (env_set("HH_MENU_TRACE")) {
                hh::log("[menu] MODO COMBATE: dispatch cursor=%d\n", battle_idx);
            }
        }
    }
    // COMBATE DE CRIATURAS: pantalla interna (5 COMBATES / SUPERVIVENCIA). A = cursor (0/1) + A
    // inyectada al nativo (func_801C44C4); B = vuelve a la RAIZ (el original va directo al titulo,
    // no al submenu de batalla). La delegacion la hace hh_battle_creature_hook.
    if (hh::overlay::enabled() && screen_before == hh::menu::ScreenId::BattleCreature) {
        if (ev == hh::menu::Event::Back) {
            recomp_context t = *ctx;
            t.r4 = obj;
            t.r5 = 0x801C56B8u;   // el original: func_800058DC(obj, 0x801C56B8) -> raiz
            func_800058DC_64DC(rdram, &t);
            while (hh::menu::depth() > 1) {
                hh::menu::back();
            }
        } else if (ev == hh::menu::Event::Accept && same_screen) {
            const hh::menu::Screen& s = hh::menu::current_screen();
            if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
                rdram[(kBattleCursorAddr - 0x80000000u) ^ 3u] = static_cast<uint8_t>(s.cursor);
                g_inject_native_a = true;
                if (env_set("HH_MENU_TRACE")) {
                    hh::log("[menu] COMBATE DE CRIATURAS: dispatch cursor=%d\n", s.cursor);
                }
            }
        }
    }
    // SFX del menu desde los EVENTOS del modelo (paso 7): move/accept/back. Al sonar por el evento,
    // no suena si la pulsacion no hace nada (arriba en la 1.a entrada, B en la raiz, opcion gris, o
    // izquierda/derecha donde no hay selector). Solo cuando el overlay controla el menu: con
    // HH_OVERLAY=0 manda el nativo, que ya trae su propio sonido.
    if (ev != hh::menu::Event::None && hh::overlay::enabled()) {
        switch (ev) {
            case hh::menu::Event::Move:   hh::menu_sfx::play(hh::menu_sfx::Sfx::Move);   break;
            case hh::menu::Event::Accept: hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept); break;
            case hh::menu::Event::Back:   hh::menu_sfx::play(hh::menu_sfx::Sfx::Back);   break;
            default: break;
        }
    }
    if (env_set("HH_MENU_TRACE") && ev != hh::menu::Event::None) {
        hh::log("[menu-nav] btn=0x%04X ev=%d depth=%d\n%s", btn, static_cast<int>(ev),
                hh::menu::depth(), hh::menu::describe_current().c_str());
    }
}

// Overlay A2: envuelve el update del menú de título (func_801C18FC), que registra/compone las
// etiquetas nativas. Se ocultan (por defecto) reescribiéndolas antes de delegar en el original.
extern "C" void hh_title_ctor_hook(uint8_t* rdram, recomp_context* ctx) {
    hh::menu_overlay::suppress_native(rdram);
    func_801C18FC_11BB3CC(rdram, ctx);
}

// Overlay A2: envuelve la composición de texto (0x8001B204). Si el texto es del menú nativo y éste
// está oculto, lo blankea justo antes de que el original lo lea. Es la pieza que elimina el flash:
// cubre la PRIMERA composición (fase de fade-in), en la que el handler del menú aún no corre.
extern "C" void hh_entry_register_hook(uint8_t* rdram, recomp_context* ctx) {
    if (env_set("HH_MENU_TRACE")) {
        // Cada `a3` (dirección del texto compuesto) distinto, una vez: sirve para mapear QUÉ tablas
        // de etiquetas pasa cada pantalla (p. ej. al entrar/salir de submenús).
        static std::vector<uint32_t> seen;
        static uint64_t n = 0;
        const uint32_t a3 = static_cast<uint32_t>(ctx->r7);
        bool dup = false;
        for (uint32_t v : seen) {
            if (v == a3) { dup = true; break; }
        }
        if (!dup && seen.size() < 512) {
            seen.push_back(a3);
            hh::log("[entry] 0x8001B204 #%llu a3=%08X (nuevo)\n",
                    static_cast<unsigned long long>(n), a3);
        }
        ++n;
    }
    hh::menu_overlay::filter_native_text(rdram, static_cast<uint32_t>(ctx->r7));
    func_8001B204_1BE04(rdram, ctx);
}

// Overlay A2: envuelve el handler del menú de título del módulo 23 (func_801C1DB8). Delega en el
// ORIGINAL (la lógica del juego sigue funcionando, pero su menú nativo queda oculto por defecto) y
// publica el frame del overlay del port. Con HH_MENU_TRACE=1 registra además la selección (0x801CC8C4).
extern "C" void hh_title_menu_hook(uint8_t* rdram, recomp_context* ctx) {
    hh::overlay::set_screen_blackout(false);   // seguridad: el telon nunca tapa el menu
    static const bool trace = env_set("HH_MENU_TRACE");
    static uint64_t calls = 0;
    if (trace && (calls++ % 30) == 0) {
        auto guest_byte = [&](uint32_t addr) -> unsigned {
            return rdram[(addr - 0x80000000u) ^ 3u];
        };
        const uint32_t obj_trace = static_cast<uint32_t>(ctx->r4);
        const unsigned idle = static_cast<unsigned>(
            (rdram[((obj_trace + 0x3Cu) - 0x80000000u) ^ 3u] << 8) |
            rdram[((obj_trace + 0x3Du) - 0x80000000u) ^ 3u]);
        hh::log("[menu] a0=%08X a1=%08X sel=%u idle=%u g1=%u g2=%u\n",
                static_cast<uint32_t>(ctx->r4), static_cast<uint32_t>(ctx->r5),
                guest_byte(0x801CC8C4u), idle, guest_byte(0x801BBD54u), guest_byte(0x801CC8A8u));
    }
    // ¿El handler nativo cambió de pantalla este frame? (p. ej. al seleccionar una opción). En ese
    // caso NO publicamos el frame del overlay (seguiría mostrando la raíz durante la transición).
    bool screen_changed = false;
    {
        const uint32_t goto_before = g_goto_count.load(std::memory_order_relaxed);

        // MODO COMBATE: si el handler de la RAIZ corre con nuestra pila en una subpantalla de batalla,
        // el nativo ya salio de ella por su cuenta (p. ej. B desde COMBATE DE CRIATURAS, que va
        // directo a la raiz): sincronizamos la UI volviendo a la raiz.
        if (hh::overlay::enabled()) {
            const hh::menu::ScreenId cur = hh::menu::current_screen().id;
            if (cur == hh::menu::ScreenId::BattleMode || cur == hh::menu::ScreenId::BattleCreature) {
                while (hh::menu::depth() > 1) {
                    hh::menu::back();
                }
            }
        }

        // A2 (paso 5, terreno): mueve nuestro cursor con el input del juego. Los SFX del menú suenan
        // dentro, desde los EVENTOS del modelo (paso 7); ver feed_menu_navigation.
        feed_menu_navigation(rdram, ctx);

        // A2: la COMPOSICIÓN del texto nativo se filtra en hh_entry_register_hook, así que el menú
        // sale en blanco desde el primer frame sin depender del handler. F6 solo necesita forzar un
        // re-registro inmediato (el texto ya compuesto no se relee por sí solo).
        const uint32_t obj = static_cast<uint32_t>(ctx->r4);   // el handler nativo clobbea ctx
        const uint32_t arg = static_cast<uint32_t>(ctx->r5);
        if (hh::menu_overlay::native_toggle_pending()) {
            recomp_context t = *ctx;
            MEM_H(0x3C, obj) = 0;          // fuerza el registro en func_801C18FC
            t.r4 = obj;
            t.r5 = arg;
            hh_title_ctor_hook(rdram, &t);
        }
        hh::menu_overlay::suppress_native(rdram);
        // Control total: el original corre con el input muteado (no mueve su cursor ni cambia de
        // pantalla). Sin overlay activo no se mutea, para no bloquear el menú nativo (diagnóstico).
        const bool controlling = hh::overlay::enabled();
        if (controlling) {
            // El handler nativo decrementa su temporizador de inactividad (obj+0x3C) y, al llegar a
            // 0, abandona el menu hacia el attract (goto 0x801C2050 -> func_801C5A00: intro/demos).
            // Como nosotros MUTEAMOS su input, el handler no lo reinicia al navegar; lo reiniciamos
            // aqui con la entrada REAL (0x384 = valor nativo). Antes se forzaba a 0x384 CADA frame,
            // lo que impedia que el timeout nativo disparara a su ritmo y el attract salia mas tarde
            // (bug reportado 2026-09-26). Ahora manda el timer nativo, igual que en el original.
            recomp_context td = *ctx;
            func_801C1340_11BAE10(rdram, &td);   // direcciones (entrada real)
            recomp_context ta = *ctx;
            func_801C1334_11BAE04(rdram, &ta);   // A/B/START (entrada real)
            const uint32_t held = static_cast<uint32_t>(td.r2) | static_cast<uint32_t>(ta.r2);
            if (held != 0) {
                MEM_H(0x3C, obj) = 0x384;
            }
        }
        g_mute_native_input = controlling;
        func_801C1DB8_11BB888(rdram, ctx);  // comportamiento original con input neutralizado
        g_mute_native_input = false;
        g_inject_native_a = false;          // la inyeccion (CONTINUAR) es de un solo frame
        const uint32_t goto_after = g_goto_count.load(std::memory_order_relaxed);
        screen_changed = (goto_after != goto_before);
    }
    // Si la pantalla cambió (salimos de la raíz), no publicamos: `hide_now` ya la ocultó y el
    // siguiente frame lo decidirá el nuevo handler. Si seguimos en la raíz, publicamos normal.
    if (!screen_changed) {
        hh::menu_overlay::title_update(rdram);
    }
}

// Overlay A2: envuelve el update del submenú MODO COMBATE (func_801C4200, file_024). La subpantalla
// es la NUESTRA (rótulos traducidos); el original corre con el input muteado y recibe el cursor
// (0x801CC8C8) + A inyectada que fija feed_menu_navigation para ejecutar su rama real (VS MODE /
// CREATURE BATTLE / DATA EDIT / EXIT). Al despachar, el callback cambia y nuestro hook deja de correr
// (la pantalla interna la dibuja el juego); al volver a la raíz, `hh_title_menu_hook` resincroniza.
extern "C" void hh_battle_menu_hook(uint8_t* rdram, recomp_context* ctx) {
    hh::overlay::set_screen_blackout(false);
    feed_menu_navigation(rdram, ctx);
    hh::menu_overlay::suppress_native(rdram);
    const bool controlling = hh::overlay::enabled();
    const uint32_t goto_before = g_goto_count.load(std::memory_order_relaxed);
    g_mute_native_input = controlling;
    func_801C4200_11BDCD0(rdram, ctx);   // comportamiento original con input neutralizado
    g_mute_native_input = false;
    g_inject_native_a = false;           // la inyeccion (cursor+A) es de un solo frame
    const uint32_t goto_after = g_goto_count.load(std::memory_order_relaxed);
    if (goto_after == goto_before) {
        hh::menu_overlay::title_update(rdram);
    }
}

// Overlay A2: envuelve el update de COMBATE DE CRIATURAS (func_801C44C4, file_024). Igual que el
// submenú de batalla: nuestra subpantalla (5 COMBATES / SUPERVIVENCIA) y el original recibe cursor
// (0x801CC8C8) + A inyectada. B lo gestiona feed_menu_navigation (vuelve a la raíz).
extern "C" void hh_battle_creature_hook(uint8_t* rdram, recomp_context* ctx) {
    hh::overlay::set_screen_blackout(false);
    feed_menu_navigation(rdram, ctx);
    hh::menu_overlay::suppress_native(rdram);
    const bool controlling = hh::overlay::enabled();
    const uint32_t goto_before = g_goto_count.load(std::memory_order_relaxed);
    g_mute_native_input = controlling;
    func_801C44C4_11BDF94(rdram, ctx);   // comportamiento original con input neutralizado
    g_mute_native_input = false;
    g_inject_native_a = false;
    const uint32_t goto_after = g_goto_count.load(std::memory_order_relaxed);
    if (goto_after == goto_before) {
        hh::menu_overlay::title_update(rdram);
    }
}

// Diagnostico B (fuente), gateado por HH_FONT_TRACE: envuelve el motor de texto residente para
// registrar EMPIRICAMENTE (sin adivinar) la tabla código EUC -> slot y el color/estilo activo.
// `func_8001D394(a0=código)->v0` da el valor que `func_8001BFE4` convierte en slot `v0>>1`;
// el color (índice de estilo/fuente) va en `func_8001BFE4(a0)`.
namespace {
inline uint16_t guest_u16(uint8_t* rdram, uint32_t addr) {
    return static_cast<uint16_t>((rdram[(addr - 0x80000000u) ^ 3u] << 8) |
                                 rdram[((addr + 1u) - 0x80000000u) ^ 3u]);
}
}  // namespace

extern "C" void hh_font_trace_d394(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned in = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;  // a1 = código EUC
    func_8001D394_1DF94(rdram, ctx);
    const unsigned out = static_cast<uint32_t>(ctx->r2) & 0xFFFFu;
    static unsigned seen_key[1024];
    static size_t seen = 0;
    const unsigned key = (color << 16) | in;
    bool dup = false;
    for (size_t i = 0; i < seen; ++i) {
        if (seen_key[i] == key) {
            dup = true;
            break;
        }
    }
    if (!dup && seen < 1024) {
        seen_key[seen++] = key;
        hh::log("[font] d394 color=%u code=%04X -> %u (slot %u)\n", color, in, out, out >> 1);
    }
}

extern "C" void hh_font_trace_bfe4(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned code = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    const unsigned stride = rdram[(0x80044624u + color - 0x80000000u) ^ 3u];
    const unsigned fileidx = guest_u16(rdram, 0x8004462Cu + color * 2u);
    func_8001BFE4_1CBE4(rdram, ctx);
    // Dump del BLOQUE cargado en el buffer de trabajo (0x801077E0, `stride` bytes). Fijar el layout
    // real de un estilo (p. ej. color4 8x12) sin adivinar: HH_FONT_DUMP_GLYPH=<color> vuelca cada
    // bloque una vez; HH_FONT_DUMP_ONLY=<valor> filtra por el valor del glifo.
    static const int dump_color = [] {
        const char* e = std::getenv("HH_FONT_DUMP_GLYPH");
        return (e != nullptr && *e != '\0') ? std::atoi(e) : -1;
    }();
    if (dump_color >= 0 && static_cast<int>(color) == dump_color) {
        static unsigned dump_seen[512];
        static size_t dump_n = 0;
        static const int only = [] {
            const char* e = std::getenv("HH_FONT_DUMP_ONLY");
            return (e != nullptr && *e != '\0') ? std::atoi(e) : -1;
        }();
        if (only >= 0 && static_cast<int>(code) != only) {
            goto report;
        }
        bool dup = false;
        for (size_t i = 0; i < dump_n; ++i) {
            if (dump_seen[i] == code) { dup = true; break; }
        }
        if (!dup && dump_n < 512) {
            dump_seen[dump_n++] = code;
            char hex[3 * 64 + 1];
            char* p = hex;
            for (unsigned i = 0; i < stride && i < 64; ++i) {
                const unsigned b = rdram[(0x801077E0u + i - 0x80000000u) ^ 3u];
                p += std::snprintf(p, 4, "%02X ", b);
            }
            *p = '\0';
            hh::log("[fontdump] color=%u code=%04X slot=%u stride=%u block=%s\n", color, code,
                    code >> 1, stride, hex);
        }
    }
report:
    // Diagnostico textual (HH_FONT_TRACE): mapeo color/codigo -> slot/stride/file.
    static unsigned seen_key[1024];
    static size_t seen = 0;
    const unsigned key = (color << 16) | code;
    bool dup = false;
    for (size_t i = 0; i < seen; ++i) {
        if (seen_key[i] == key) { dup = true; break; }
    }
    if (!dup && seen < 1024) {
        seen_key[seen++] = key;
        hh::log("[font] bfe4 color=%u code=%04X slot=%u stride=%u fileidx=%u\n", color, code,
                code >> 1, stride, fileidx);
    }
}

// A2: contador de transiciones de pantalla (func_800058DC); definido arriba (antes del handler).

extern "C" void hh_goto_hook(uint8_t* rdram, recomp_context* ctx) {
    g_goto_count.fetch_add(1, std::memory_order_relaxed);
    const uint32_t target = static_cast<uint32_t>(ctx->r5);
    // Intro de ARRANQUE (file 055): `0x80383AD4` es el estado que corre durante los logos nativos.
    // Al registrarlo entramos en la fase; cualquier otra pantalla la cierra -> retira el HD.
    if (target == 0x80383AD4u) {
        boot_intro_enter();
    } else if (g_boot_intro_active) {
        g_boot_intro_active = false;
        g_boot_paused = false;
        g_konami_idx = 0;
        detach_logo();
        hh::overlay::set_screen_blackout(false);   // la intro termino: destapa el juego
        // Si el fade-out final no habia empezado (p. ej. skip con START antes del final), lo
        // disparamos; si ya corria, se deja terminar (misma duracion siempre).
        if (!g_boot_out_started) {
            hh::overlay::fade_out_screen_image(kBootFinalFadeMs);
        }
    }
    if (env_set("HH_MENU_TRACE")) {
        hh::log("[menu] goto pantalla=%08X (obj=%08X)\n", static_cast<uint32_t>(ctx->r5),
                static_cast<uint32_t>(ctx->r4));
    }
    // A2: cambio de pantalla -> oculta el overlay al instante (el handler nativo puede seguir
    // publicando el frame de la raíz durante la transición; ver menu_overlay::hide_now).
    hh::menu_overlay::hide_now();
    func_800058DC_64DC(rdram, ctx);
}

// A2: la entrada SOUND (inutil en PC) pasa a ser CONFIGURACIÓN; dentro viven IDIOMA y SONIDO.
// (Implementacion en src/hooks/hh_menu.cpp; aqui solo se registran los overrides.)

// Debe correr en on_init, DESPUES de init_overlays(): init_overlays hace func_map.clear() y
// borraria los hooks si se registraran antes (register_overlays() si va antes, para las tablas).
void hh::register_runtime_functions() {
    // libultra que provee el runtime, en su direccion de cartucho: con use_lookup_for_all_function_calls
    // cada llamada es un lookup, y estas funciones no viven en ninguna tabla de seccion.
    for (const auto& entry : runtime_provided_funcs) {
        // Placeholder de tabla vacia (MSVC no admite arrays de tamano 0): ram_addr==0 se ignora.
        if (entry.ram_addr == 0) continue;
        recomp::overlays::add_loaded_function(static_cast<int32_t>(entry.ram_addr), entry.func);
    }
    recomp::overlays::add_loaded_function(static_cast<int32_t>(kFileLoadAddress), file_load_hook);
    recomp::overlays::add_loaded_function(static_cast<int32_t>(kFileLoadStreamedAddress),
                                          file_load_streamed_hook);
    // Overlay A2: handler del menú de título (delega en el original + publica el overlay).
    register_title_menu_hook();
    // A2: transiciones de pantalla (cuenta para el SFX por cambio real; traza con HH_MENU_TRACE).
    recomp::overlays::add_loaded_function(0x800058DC, hh_goto_hook);
    // Precarga el primer logo de la intro: asi el fade-in no se pierde decodificando el PNG.
    hh::overlay::preload_screen_image(logo_path(konami_logo()), logo_is_modern(konami_logo()));
    // Telon negro desde ya: tapa los logos NATIVOS del boot (file 8) que se pintan ANTES de que
    // arranque nuestra fase de logos (file 055). La intro lo retira al terminar.
    hh::overlay::set_screen_blackout(true);
    // Diagnostico B (opcional): mapea código->slot y color/estilo del motor de texto.
    if (env_set("HH_FONT_TRACE")) {
        recomp::overlays::add_loaded_function(0x8001D394, hh_font_trace_d394);
        recomp::overlays::add_loaded_function(0x8001BFE4, hh_font_trace_bfe4);
        std::fprintf(stderr, "[hh] HH_FONT_TRACE: función de mapeo y loader de glifo instrumentados\n");
    } else {
        // B: inyeccion de glifos acentuados (activa por defecto; HH_ACCENTS=0 la desactiva).
        const char* acc = std::getenv("HH_ACCENTS");
        if (acc == nullptr || (*acc != '\0' && *acc != '0')) {
            hh_accent_register();
        }
    }
    // A2: SOUND -> CONFIGURACIÓN (pantalla propia con IDIOMA y SONIDO).
    // hh_pc_menu_register();  // DESACTIVADO: reemplazado por overlay propio
    std::fprintf(stderr, "[hh] %zu code files; loaders envueltos en 0x%08X y 0x%08X\n",
                 kFileCount, kFileLoadAddress, kFileLoadStreamedAddress);
    std::fflush(stderr);
}
