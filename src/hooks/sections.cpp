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
extern "C" void func_800023A8_2FA8(uint8_t* rdram, recomp_context* ctx);  // rama CONTINUE nativa
extern "C" void func_80020718_21318(uint8_t* rdram, recomp_context* ctx); // rama CONTINUE nativa
extern "C" void func_8001BFE4_1CBE4(uint8_t* rdram, recomp_context* ctx);  // carga bitmap de glifo
extern "C" void func_8001D394_1DF94(uint8_t* rdram, recomp_context* ctx);  // código EUC -> slot
extern "C" void func_801C1340_11BAE10(uint8_t* rdram, recomp_context* ctx);  // lee botones (direcciones)
extern "C" void func_801C1334_11BAE04(uint8_t* rdram, recomp_context* ctx);  // lee botones (A/START)
extern "C" void func_80232D08_10FCC28(uint8_t* rdram, recomp_context* ctx);  // aplica el daño por parte
extern "C" void func_8013D520_1035CF0(uint8_t* rdram, recomp_context* ctx);  // suma/resta cantidad de item
extern "C" void func_80144E68_103D638(uint8_t* rdram, recomp_context* ctx);  // deserializa el personaje
extern "C" void func_80152240_104AA10(uint8_t* rdram, recomp_context* ctx);  // load: tablas de runtime
extern "C" void func_80379F04_1303514(uint8_t* rdram, recomp_context* ctx);  // dano fuera de combate
extern "C" void func_803771A4_13007B4(uint8_t* rdram, recomp_context* ctx);  // update del DATA SAVE (capsula)
extern "C" void func_80377140_1300750(uint8_t* rdram, recomp_context* ctx);  // setup del DATA SAVE (capsula)
extern "C" void func_80142778_103AF48(uint8_t* rdram, recomp_context* ctx);  // compositor del titulo DATA SAVE
extern "C" void func_80142570_103AD40(uint8_t* rdram, recomp_context* ctx);  // VACIA las 0x1C ranuras de texto
extern "C" void func_80002A94_3694(uint8_t* rdram, recomp_context* ctx);       // rama de salida del DATA SAVE
extern "C" void func_801C3D84_11BD854(uint8_t* rdram, recomp_context* ctx);    // update file-select (envuelto)
extern "C" void func_801426B0_103AE80(uint8_t* rdram, recomp_context* ctx);    // setup del DATA LOAD
extern "C" bool hh_input_button_down(const char* action_key);   // binding real (mando+teclado) pulsado
extern "C" void hh_save_menu_hook(uint8_t* rdram, recomp_context* ctx);       // UI de cargar encima del save
extern "C" void hh_save_setup_hook(uint8_t* rdram, recomp_context* ctx);      // setup del save (activa categoria)
extern "C" void hh_pc_menu_register();  // src/hooks/hh_menu.cpp
extern "C" void hh_accent_register();   // src/hooks/text_glyphs.cpp
extern "C" void load_overlay_by_id(uint32_t id, uint32_t ram_addr);
extern "C" void unload_overlay_by_id(uint32_t id);
extern "C" void hh_title_menu_hook(uint8_t* rdram, recomp_context* ctx);   // definido abajo
extern "C" void hh_battle_menu_hook(uint8_t* rdram, recomp_context* ctx);  // definido abajo
extern "C" void hh_battle_creature_hook(uint8_t* rdram, recomp_context* ctx);  // definido abajo
extern "C" void hh_battle_frame_hook(uint8_t* rdram, recomp_context* ctx);  // traza de combate
extern "C" void hh_file_select_hook(uint8_t* rdram, recomp_context* ctx);   // Fase 3: file-select CARGAR
extern "C" void hh_box_draw_hook(uint8_t* rdram, recomp_context* ctx);       // cajas nativas (func_8001A804)
extern "C" void hh_pak_message_hook(uint8_t* rdram, recomp_context* ctx);    // mensaje Controller Pak
extern "C" void func_80002BE0_37E0(uint8_t* rdram, recomp_context* ctx);     // clasificador de accesorio (pak)
extern "C" void hh_pak_detect_hook(uint8_t* rdram, recomp_context* ctx);     // desacoplo vibracion <-> controller pak
extern "C" void func_801C3F48_11BDA18(uint8_t* rdram, recomp_context* ctx);  // callback titulo del Area
extern "C" void func_801C4018_11BDAE8(uint8_t* rdram, recomp_context* ctx);  // callback espera (input)
extern "C" void func_801C4074_11BDB44(uint8_t* rdram, recomp_context* ctx);  // callback transicion escena
extern "C" void func_8013EA54_1037224(uint8_t* rdram, recomp_context* ctx);  // indice de escena del slot
extern "C" void hh_area_title_hook(uint8_t* rdram, recomp_context* ctx);     // titulo Area (fade)
extern "C" void hh_area_wait_hook(uint8_t* rdram, recomp_context* ctx);      // titulo Area (espera)
extern "C" void hh_area_trans_hook(uint8_t* rdram, recomp_context* ctx);     // titulo Area (transicion)
extern "C" void hh_area_scene_idx_hook(uint8_t* rdram, recomp_context* ctx); // diagnostico indice escena

namespace hh::menu_overlay {
void publish_area_title(int area_num, const std::string& name, int alpha);
std::string area_title_name(int area_num);
void set_area_title_lock(bool on);
void begin_area_title_fadeout(int ms);
}  // namespace hh::menu_overlay

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

// ANTI-REBOTE de entrada al (re)entrar al menú de título. El menú abre con START ("PRESS START") y
// ese START puede seguir MANTENIDO en el primer frame en que corre `feed_menu_navigation`; con
// `prev=0` (o sin START) contaría como flanco y, al aceptar también START (entrar en menús), se
// colaría una acción (p. ej. CONTINUAR) sin querer. `hh_title_menu_hook` lo marca tras un hueco real
// (reentrada) y `feed_menu_navigation` traga el estado mantenido un frame (siembra `prev`). Ver
// docs/releases/v0.6.0.md.
std::atomic<bool> g_menu_seed_input{false};

// NOTA (2026-10-01): se probó a cargar por la MÁQUINA NATIVA del file-select (inyectarle A y dejar
// que corra state 2→3→4). Está BLOQUEADO: el state machine se congela en state 3 mientras el
// subsistema de mensajes no limpie `D_8008EE78` (`func_800178E8` → 0), y en el port el mensaje
// avanza una vez y se queda. Por eso la carga sigue siendo directa (`hh_do_load_game`, rama de ÉXITO
// replicada). Ver `RETOMAR.md` / nota del título del Área.

// ¿Estamos en la TRANSICIÓN del menú de título al file-select de CARGAR? Se activa al pulsar
// CONTINUAR y la consume el primer frame de `hh_file_select_hook`. Mientras dura, el handler del
// TÍTULO no debe apagar la categoría FILE-SELECT (el callback nativo puede seguir siendo el del título
// 1-2 frames) ni republicar el frame de la raíz (evita el parpadeo/retardo al aparecer la UI de carga).
bool g_load_enter = false;
// Contador de frames de la transición a CARGAR (solo para la traza: mide el hueco CONTINUAR->UI).
long g_load_enter_frame = 0;

// TÍTULO DEL ÁREA por OVERLAY (idiomas != inglés): el nombre nativo es un gráfico; con overlay lo
// dibujamos nosotros (AREA N + nombre traducido con Work Sans). `g_area_title_active` dura desde que
// se compone el título hasta que arranca la transición de escena.
bool g_area_title_active = false;
bool g_area_title_in_transition = false;   // ya se alcanzó func_801C4074 (transición)
long long g_area_title_trans_ms = 0;       // instante (steady ms) de la transición
int g_area_title_num = 0;
long g_area_title_frames = 0;          // frames desde el inicio del título (diagnóstico)
long long g_area_title_start_ms = 0;   // instante (steady ms) del inicio del título (fade por TIEMPO)
// Alfa del fade-in del título. El original (`func_801C3F48`) funde con `alpha += 8/frame`, pero eso
// depende del ritmo de frames del port, así que aquí se hace por TIEMPO para poder cuadrarlo 1:1 con el
// original a ojo: `HH_TITLE_FADE_MS` (por defecto 2000 ms). Solo se funde el TEXTO: el telón negro va
// opaco (si se transparentara se colaría el título nativo de detrás). Ver `publish_area_title`.
int area_title_alpha() {
    static const long long fade_ms = [] {
        const char* e = std::getenv("HH_TITLE_FADE_MS");
        const long long v = (e != nullptr && *e != '\0') ? std::atoll(e) : 2000LL;
        return v > 0 ? v : 1LL;
    }();
    if (g_area_title_start_ms == 0) return 0;
    const long long now = std::chrono::duration_cast<std::chrono::milliseconds>(
                              std::chrono::steady_clock::now().time_since_epoch())
                              .count();
    const long long a = (now - g_area_title_start_ms) * 255 / fade_ms;
    return a > 255 ? 255 : static_cast<int>(a);
}

// Contador global de frames (lo incrementan los hooks de título/file-select): permite medir cuántos
// frames reales pasan entre CONTINUAR y la primera UI de carga. Solo diagnóstico.
long g_hook_frame = 0;

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
// MODO HEAVEN (EXTRAS): modo GLOBAL (no depende de la partida ni del editor). Efectos gateados por
// `hh::menu::heaven_enabled()` (config.ini [extras].heaven):
//   - AL CARGAR PARTIDA: tras deserializar el personaje (`func_80144E68`) o montar las tablas de
//     runtime (`func_80152240`, CONTINUE / partida nueva) se aplica `hh::save::apply_heaven_runtime`:
//     ATRIBUTOS y ESTADO al máximo + las 86 habilidades. El save del juego serializa ese mismo
//     personaje (`func_80144C40`), así que el estado queda persistido al guardar.
//   - Invulnerabilidad: `func_80232D08` es la UNICA funcion que resta el daño ya resuelto de las
//     partes del cuerpo (`+0x2B8+part*2`); su unico llamador es la resolucion de golpe
//     `func_80232E94`. Si el ente dañado (`a0`) es la PARTIDA del jugador (`0x801BC03C`), daño 0.
//   - Items que no se gastan: `func_8013D520` suma/resta la cantidad de un item (u8, tope 99) segun
//     `a1` (delta con signo). Con MODO HEAVEN se anula la RESTA (`a1=0`), asi el contador no baja.
//   - Daño fuera de combate: `func_80379F04` resta el daño de campo al jugador; con HEAVEN se anula.
//   - PODER/RESISTENCIA INFINITOS (`hh_battle_frame_hook`): pinnea ambos gauges a su max cada frame.
//     **NO** incluye la VENTAJA (con el PODER infinito es redundante): la ventaja es solo su toggle.
//
// [DIRECCIONES MEDIDAS del C recompilado (0x8017DC40 es el struct del personaje: lo deserializa
// `func_80144E68`, lo serializa `func_80144C40` y lo leen `func_80378D84/E3C`); efectos pendientes de
// validar en Windows: ver RETOMAR.md]
constexpr uint32_t kPlayerPartyAddr = 0x801BC03Cu;

extern "C" void hh_heaven_damage_hook(uint8_t* rdram, recomp_context* ctx) {
    if (hh::menu::heaven_enabled() && static_cast<uint32_t>(ctx->r4) == kPlayerPartyAddr) {
        ctx->r5 = 0;   // daño 0 al jugador
    }
    func_80232D08_10FCC28(rdram, ctx);
}

extern "C" void hh_heaven_item_hook(uint8_t* rdram, recomp_context* ctx) {
    if (hh::menu::heaven_enabled() && static_cast<int8_t>(ctx->r5 & 0xFFu) < 0) {
        ctx->r5 = 0;   // no consumir el item
    }
    func_8013D520_1035CF0(rdram, ctx);
}

// DANO FUERA DE COMBATE (robots): `func_80379F04` aplica `0x8017DC40+0x2 (HP del jugador) = HP -
// *(s16*)0x80388A68`; el a0 de ENTRADA es el atacante, pero la funcion fija `a0 = 0x8017DC40` para el
// store del HP, asi que es una funcion (unica) de "el enemigo golpea al jugador". Con MODO HEAVEN se
// pone el scratch de dano a 0 durante la llamada (y se restaura) -> el jugador no pierde vida.
// [MEDIDO con HH_WATCH]
constexpr uint32_t kFieldDamageScratch = 0x80388A68u;

extern "C" void hh_heaven_field_damage_hook(uint8_t* rdram, recomp_context* ctx) {
    if (!hh::menu::heaven_enabled()) {
        func_80379F04_1303514(rdram, ctx);
        return;
    }
    auto* dmg = reinterpret_cast<uint16_t*>(&rdram[(kFieldDamageScratch ^ 2u) & 0x7FFFFFu]);
    const uint16_t saved = *dmg;
    if (saved != 0) {
        hh::log("[heaven] dano de campo anulado (dmg=%u)\n", saved);
    }
    *dmg = 0;
    func_80379F04_1303514(rdram, ctx);
    *dmg = saved;
}

// Carga de partida: tras deserializar el personaje en `0x8017DC40`, aplicar el máximo.
extern "C" void hh_heaven_char_hook(uint8_t* rdram, recomp_context* ctx) {
    func_80144E68_103D638(rdram, ctx);
    if (hh::menu::heaven_enabled()) hh::save::apply_heaven_runtime(rdram);
}

// Carga de partida: tras montar las tablas de runtime (técnicas/items), reaplicar el máximo (cubre
// partida nueva y cualquier recomposición posterior del personaje). Ademas marca "partida cargada"
// para el submenu EXTRAS -> ELEGIR NIVEL (habilita IR A NIVEL).
extern "C" void hh_heaven_load_hook(uint8_t* rdram, recomp_context* ctx) {
    func_80152240_104AA10(rdram, ctx);
    hh::menu::set_game_loaded(true);
    if (hh::menu::heaven_enabled()) hh::save::apply_heaven_runtime(rdram);
    // IR A NIVEL sin partida cargada: la plantilla se cargo y ahora toca el warp pedido.
    uint16_t idx = 0;
    if (hh::menu::take_pending_warp(idx)) {
        recomp_context t = *ctx;
        t.r4 = 15;
        t.r5 = idx;
        t.r6 = 1;
        t.r7 = 6;
        hh::log("[elegir-nivel] warp pendiente tras cargar plantilla: idx=%u\n", idx);
        func_8012FE50_1028620(rdram, &t);
    }
    // La plantilla lleva 1 Code Key (id 38, item) para no quedarse bloqueado en puertas de areas
    // avanzadas; si se carga la escena 1-0 (idx 0) se quita (una partida nueva no la debe tener).
    // El indice de escena cargado esta en `0x801BBBF0[+4]` (u16 BE del guest).
    {
        const uint16_t scene = static_cast<uint16_t>(
            (static_cast<uint16_t>(rdram[(0x801BBBF4u - 0x80000000u) ^ 3u]) << 8) |
            rdram[(0x801BBBF5u - 0x80000000u) ^ 3u]);
        if (scene == 0) {
            hh::save::clear_code_key_runtime(rdram);
        }
    }
}

// DIAGNOSTICO (HH_SAVEEDIT_DUMP=1): al deserializar un slot (`func_80141D08(a0=buffer 0xD00)`)
// volcar el buffer entrante y, tras el original, los bloques de estado (0x801BBBF0 / 0x801BED38) y la
// tabla de escenas. Ver hh::save::dump_runtime / dump_slot_buffer.
extern "C" void hh_saveedit_load_hook(uint8_t* rdram, recomp_context* ctx) {
    const char* dump = std::getenv("HH_SAVEEDIT_DUMP");
    const bool on = dump != nullptr && *dump != '\0' && *dump != '0';
    if (on) hh::save::dump_slot_buffer(rdram, static_cast<uint32_t>(ctx->r4), "load");
    func_80141D08_103A4D8(rdram, ctx);
    if (on) hh::save::dump_runtime(rdram, "load");
}

// TRAZA DE ESCENA (HH_SCENE_TRACE=1): loguea las transiciones `func_8012FE50(tipo, valor, ...)` (a1 =
// valor de progreso `N*10+P`) y las cargas de escena `func_80125968(idx, flags)`. Con esto se ve el
// valor EXACTO que el juego usa al cargar un slot y de que campo sale. Ver plan 2026-09-29.
extern "C" void hh_scene_transition_hook(uint8_t* rdram, recomp_context* ctx) {
    const char* tr = std::getenv("HH_SCENE_TRACE");
    if (tr != nullptr && *tr != '\0' && *tr != '0') {
        auto rh16 = [&](uint32_t a) -> uint16_t {
            return *reinterpret_cast<uint16_t*>(&rdram[(a ^ 2u) & 0x7FFFFFu]);
        };
        hh::trace_log("[scene] transicion func_8012FE50 tipo=%u valor=%u (N=%u P=%u) | glob 0x801BBBF0 "
                "[+2]=%u [+4]=%u [+6]=%u | buf? a2=%u a3=%u\n",
                (unsigned)(ctx->r4 & 0xFF), (unsigned)(ctx->r5 & 0xFFFF),
                (unsigned)((ctx->r5 & 0xFFFF) / 10), (unsigned)((ctx->r5 & 0xFFFF) % 10),
                (unsigned)rh16(0x801BBBF2u), (unsigned)rh16(0x801BBBF4u), (unsigned)rh16(0x801BBBF6u),
                (unsigned)(ctx->r6 & 0xFF), (unsigned)(ctx->r7 & 0xFF));
    }
    func_8012FE50_1028620(rdram, ctx);
}

extern "C" void hh_scene_load_hook(uint8_t* rdram, recomp_context* ctx) {
    const char* tr = std::getenv("HH_SCENE_TRACE");
    if (tr != nullptr && *tr != '\0' && *tr != '0') {
        hh::trace_log("[scene] carga func_80125968 idx=%u (N=%u P=%u) flags(a1)=%u\n",
                (unsigned)(ctx->r4 & 0xFFFF), (unsigned)((ctx->r4 & 0xFFFF) / 10),
                (unsigned)((ctx->r4 & 0xFFFF) % 10), (unsigned)(ctx->r5 & 0xFFFF));
    }
    func_80125968_101E138(rdram, ctx);
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
    return (hh::get_app_folder_path() / "assets" / "logos" / name).string();
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
    // Fase 3 (menú de carga): envuelve el UPDATE del file-select DATA LOAD (func_801C3D84, file_024)
    // para ocultar el nativo, mutear su input y publicar nuestra LoadGame al dar a CONTINUAR.
    recomp::overlays::add_loaded_function(0x801C3D84, hh_file_select_hook);
    // GUARDAR (cápsula): la vía nativa del DATA SAVE usa OTRO callback en el módulo de gameplay
    // (0x803771A4 -> 0x8013EB2C), NO el file-select 0x801C3D84. Se envuelve su update para publicar la
    // COPIA de la UI de cargar ENCIMA del DATA SAVE nativo (sin ocultarlo: comparación 1:1).
    recomp::overlays::add_loaded_function(0x803771A4, hh_save_menu_hook);
    // SETUP del DATA SAVE (0x80377140): activa la categoria FILE-SELECT ANTES de que se componga el
    // titulo (para que F8 lo oculte igual que en CARGAR).
    recomp::overlays::add_loaded_function(0x80377140, hh_save_setup_hook);
    // Cajas nativas (func_8001A804, residente): se saltan cuando la categoría file-select está activa
    // y el nativo oculto (suppress_box_draw()).
    recomp::overlays::add_loaded_function(0x8001A804, hh_box_draw_hook);
    // Mensaje del Controller Pak (func_800179B0): se salta entero con el file-select oculto (ver hook).
    recomp::overlays::add_loaded_function(0x800179B0, hh_pak_message_hook);
    // DESACOPLO VIBRACIÓN <-> CONTROLLER PAK: `func_80002BE0` (residente) clasifica el accesorio y
    // prioriza el Rumble Pak; con VIBRACIÓN=SÍ el juego concluye "no hay Controller Pak" y no guarda.
    // El hook fuerza la rama "Controller Pak OK" sin dejar de inicializar el motor (ver definición).
    recomp::overlays::add_loaded_function(0x80002BE0, hh_pak_detect_hook);
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
    // TÍTULO DEL ÁREA al cargar: `func_801C3F48` (fade) y `func_801C4018` (espera de input) se
    // envuelven SIEMPRE: publican el overlay del título (idiomas != inglés) y, además, hh_area_title_hook
    // lleva la traza de diagnóstico (gated por HH_LOAD_TRACE).
    recomp::overlays::add_loaded_function(0x801C3F48, hh_area_title_hook);
    recomp::overlays::add_loaded_function(0x801C4018, hh_area_wait_hook);
    recomp::overlays::add_loaded_function(0x801C4074, hh_area_trans_hook);
    // `func_8013EA54` (índice de escena del Área): se envuelve SIEMPRE para capturar su retorno, que
    // es el que usan `func_801C3E24`/`func_801C3F48` para indexar `D_801CCAE0` (nº de Área). Su
    // logging va gated por HH_LOAD_TRACE/HH_FONT_TRACE.
    recomp::overlays::add_loaded_function(0x8013EA54, hh_area_scene_idx_hook);
    // Paso 5: lectores de botones del handler nativo (direcciones y A/B/START), muteables.
    recomp::overlays::add_loaded_function(0x801C1340, hh_native_dir_input);
    recomp::overlays::add_loaded_function(0x801C1334, hh_native_ab_input);
    // MODO HEAVEN (EXTRAS): modo global. Al cargar partida se aplica el máximo al personaje vivo
    // (ATRIBUTOS/ESTADO + habilidades) y en runtime invulnerabilidad + items no consumibles. Los
    // hooks consultan `hh::menu::heaven_enabled()` y se re-registran aquí en cada carga de módulo.
    recomp::overlays::add_loaded_function(0x80144E68, hh_heaven_char_hook);
    recomp::overlays::add_loaded_function(0x80152240, hh_heaven_load_hook);
    // DIAGNOSTICO/EXPERIMENTOS: estas envolturas (deserializador de slot, transicion y carga de
    // escena) SOLO se registran cuando el experimento esta pedido por entorno. Registrarlas siempre
    // engancha funciones residentes/de boot y rompe la intro/arranque normal (la intro se autoarranca
    // y el menu no responde). Ver notes/2026-09-29-editor-area-parte-plan.md.
    {
        const char* dump = std::getenv("HH_SAVEEDIT_DUMP");
        if (dump != nullptr && *dump != '\0' && *dump != '0')
            recomp::overlays::add_loaded_function(0x80141D08, hh_saveedit_load_hook);
        const char* tr = std::getenv("HH_SCENE_TRACE");
        if (tr != nullptr && *tr != '\0' && *tr != '0') {
            recomp::overlays::add_loaded_function(0x8012FE50, hh_scene_transition_hook);
            recomp::overlays::add_loaded_function(0x80125968, hh_scene_load_hook);
        }
    }
    recomp::overlays::add_loaded_function(0x80232D08, hh_heaven_damage_hook);
    recomp::overlays::add_loaded_function(0x8013D520, hh_heaven_item_hook);
    recomp::overlays::add_loaded_function(0x80379F04, hh_heaven_field_damage_hook);
    // Traza de combate (F12 / HH_BATTLE_TRACE): reloj por frame para el registro de cambios. Barato
    // y no-op si la traza esta apagada.
    recomp::overlays::add_loaded_function(0x800021B4, hh_battle_frame_hook);
}

bool env_set(const char* name) {
    const char* v = std::getenv(name);
    return v != nullptr && *v != '\0' && *v != '0';
}

// ---------------------------------------------------------------------------------------------
// TRAZA DE COMBATE (F12 o HH_BATTLE_TRACE=1): localizar el estado de SORPRESA (entrar en combate a
// la espalda del enemigo) para integrarlo en MODO HEAVEN.
//
// La sorpresa es un EVENTO puntual de ANTES del combate, asi que no vale hacer fotos periodicas:
// mientras la traza esta activa se registra la **PRIMERA variacion de cada palabra** de las zonas de
// campo/objetos y de estado de batalla/party en `hh_battle_watch.log` (`vi addr host_old->new` ->
// valor guest big-endian). Asi, un combate normal registra el cambio del flag del enemigo al
// detectarte y uno por la espalda NO (o al reves): la direccion que aparece en una traza y no en la
// otra es la del flag; luego se busca quien la escribe en el C recompilado. Ver RETOMAR.md.
struct BattleWatchRange { uint32_t addr; uint32_t size; bool all = false; };
constexpr BattleWatchRange kBattleWatchRanges[] = {
    { 0x801B5520u, 0xD80u },          // objetos de campo (16 x 0xD8): estado/deteccion del enemigo
    { 0x801BBBF0u, 0x2000u },         // bloque de progresion/estado de batalla
    // Struct del personaje y party: TODAS las transiciones (para ver el daño de campo, que baja la
    // vida viva; la meta es anular tambien ese daño bajo MODO HEAVEN).
    { 0x8017DC40u, 0x100u, true },
    { 0x801BC03Cu, 0x40u, true },
    { 0x801BC3D8u, 0x40u, true },
    // Bytes de estado de la transicion a combate (0x801BBBF0+0x1030..): todas las transiciones.
    { 0x801BCC20u, 0x20u, true },
};
constexpr size_t kBattleWatchCount = sizeof(kBattleWatchRanges) / sizeof(kBattleWatchRanges[0]);
std::vector<uint8_t> g_battle_watch_shadow[kBattleWatchCount];
std::vector<uint8_t> g_battle_watch_seen[kBattleWatchCount];   // 1 byte por palabra ya registrada (1.er cambio)
FILE* g_battle_watch_fp = nullptr;
unsigned g_battle_watch_lines = 0;
unsigned g_battle_watch_seq = 0;   // cada activacion (F12 ON) -> hh_battle_watch_<seq>.log
std::atomic<bool> g_battle_trace{ false };
std::atomic<bool> g_battle_trace_inited{ false };
std::atomic<bool> g_battle_watch_reinit{ false };   // pide recapturar sombras (lo hace el hilo de juego)

bool battle_trace_active() {
    if (!g_battle_trace_inited.exchange(true)) {
        if (env_set("HH_BATTLE_TRACE")) g_battle_trace.store(true);
    }
    return g_battle_trace.load();
}

// (Re)captura las sombras al activar la traza: la primera comparacion posible es la del frame siguiente.
void battle_watch_capture() {
    uint8_t* base = hh::get_game_rdram();
    if (base == nullptr) return;
    for (size_t i = 0; i < kBattleWatchCount; ++i) {
        const uint32_t o = kBattleWatchRanges[i].addr - 0x80000000u;
        const uint32_t n = kBattleWatchRanges[i].size;
        g_battle_watch_shadow[i].assign(base + o, base + o + n);
        g_battle_watch_seen[i].assign(n / 4u, 0);
    }
}

// Media palabra guest (mismo criterio que MEM_H: `(reg+off)^2`). `addr` es la direccion GUEST ya
// sumada, p. ej. 0x801BC042 = base 0x801BBBF0 + 0x452. Sirve para leer/escribir gauges de combate.
static inline uint16_t& guest_h16(uint8_t* rdram, uint32_t addr) {
    return *reinterpret_cast<uint16_t*>(&rdram[(addr ^ 2u) & 0x7FFFFFu]);
}

// DIAGNOSTICO de TIME (HH_SAVE_TIME_TRACE=1): el header de guardado lleva AREA/LEVEL/TIME; el
// descriptor nativo (`func_80141268`) saca el TIME de `[0x801BBBF0+0xA]` (por eso se escribe aqui el
// candidato). Se registran tambien vecinos del bloque y el nivel, con el contador VI (reloj monotono)
// para identificar, en una run, CUAL de los valores avanza como un cronometro. No es codigo de juego.
static void hh_time_trace(uint8_t* rdram, const char* tag) {
    static const bool on = env_set("HH_SAVE_TIME_TRACE");
    if (!on) {
        return;
    }
    auto h = [&](uint32_t addr) -> uint16_t { return guest_h16(rdram, addr); };
    const uint32_t base = 0x801BBBF0u;
    // Todo el bloque 0x801BBBF0+0x00..0x3E como u16 (una linea): permite ver, en la run, que campo
    // avanza como cronometro. Se añaden el nivel (DC88) y el struct del personaje.
    char buf[512];
    size_t n = 0;
    for (uint32_t o = 0; o <= 0x3E && n + 16 < sizeof(buf); o += 2u) {
        n += static_cast<size_t>(std::snprintf(buf + n, sizeof(buf) - n, " %02X:%u", o, h(base + o)));
    }
    buf[sizeof(buf) - 1] = '\0';
    hh::log("[time-trace][%s] vi=%llu |%s | DC88=%u DC40+48=%u\n", tag,
            static_cast<unsigned long long>(hh_get_vi_count()), buf, h(0x8017DC88u),
            h(0x8017DC40u + 0x48u));
}

// Reloj por frame (poll de input func_800021B4): registra la primera variacion de cada palabra vigilada.
extern "C" void func_800021B4_2DB4(uint8_t* rdram, recomp_context* ctx);
// CICLO DE PUNTOS (diagnóstico): ejecuta un paso del recorrido de índices de escena. Carga la
// plantilla si no hay partida + dispara el CONTINUAR nativo, y deja el warp pendiente al índice
// actual. Si ya hay partida, warpea directo. Se llama desde el hook por-frame (con rdram/ctx).
static void run_cycle_step(uint8_t* rdram, recomp_context* ctx) {
    int idx = hh::menu::cycle_index();
    if (idx < 0) idx = 0;   // el indice arranca en -10 hasta la primera pulsacion; no ejecutar negativo
    if (hh::menu::cycle_skipped(idx)) {
        hh::log("[ciclo] idx=%d esta en la lista de saltos (cuelga): no se ejecuta\n", idx);
        return;
    }
    hh::log("[ciclo] punto idx=%d (fila=%d col=%d)\n", idx, idx / 10, idx % 10);
    if (hh::menu::game_loaded()) {
        recomp_context t = *ctx;
        t.r4 = 15; t.r5 = static_cast<uint32_t>(idx); t.r6 = 1; t.r7 = 6;
        func_8012FE50_1028620(rdram, &t);
    } else {
        int tslot = 0;
        for (int s = 0; s < hh::save::kSlots; ++s) {
            if (!hh::save::slot_used(s)) { tslot = s; break; }
        }
        hh::menu::request_warp(static_cast<uint16_t>(idx));
        if (hh::save::load_template(tslot)) hh::save::save(tslot, rdram, ctx);
        rdram[(0x801CC8C4u - 0x80000000u) ^ 3u] = 1;   // sel = CONTINUE
        g_inject_native_a = true;
    }
}

extern "C" void hh_battle_frame_hook(uint8_t* rdram, recomp_context* ctx) {
    func_800021B4_2DB4(rdram, ctx);
    // DIAGNOSTICO de TIME (HH_SAVE_TIME_TRACE=1): 1 muestra cada ~0.5 s (a ~60 Hz) durante la run.
    if (env_set("HH_SAVE_TIME_TRACE")) {
        static uint32_t tt = 0;
        if ((tt++ % 30u) == 0u) {
            hh_time_trace(rdram, "run");
        }
    }
    // CICLO DE PUNTOS: consume la petición de las teclas de ciclo (diagnóstico de mapeo de escenas).
    // El índice ya se movió en `cycle_step`; aquí se ejecuta la carga/warp.
    if (hh::menu::request_cycle()) {
        run_cycle_step(rdram, ctx);
    }
    // PODER / RESISTENCIA INFINITOS [MEDIDO con la traza F12]: gauges de la entidad del jugador en
    // el bloque de batalla (base 0x801BBBF0, entidad 0x801BC03C):
    //   0x801BC040: alta = PODER max   / baja = PODER actual (arranca a 0, sube al atacar)
    //   0x801BC044: alta = RESIS. max  / baja = RESIS. actual (llena, baja al atacar y regenera)
    // Poner `actual = max` cada frame = no se gasta (misma operacion que hace la ventaja con PODER:
    // `[0x801BC042] = [0x801BC040]`). O(1): dos lecturas + dos escrituras con chequeo de rango; no-op
    // fuera de combate (max = 0). MODO HEAVEN los incluye (condicion superior a la ventaja).
    // HH_NO_INF_GAUGES=1: desactiva SOLO este pinning (para instrumentar el combo sin el PODER
    // congelado, ya que la barra de combo parece ir ligada al PODER). Solo para diagnostico.
    const bool inf_gauges = !env_set("HH_NO_INF_GAUGES");
    if (inf_gauges && (hh::menu::heaven_enabled() || hh::menu::infinite_power_enabled())) {
        const uint16_t pmax = guest_h16(rdram, 0x801BC040u);
        if (pmax >= 1u && pmax <= 9999u) guest_h16(rdram, 0x801BC042u) = pmax;
    }
    if (inf_gauges && (hh::menu::heaven_enabled() || hh::menu::infinite_stamina_enabled())) {
        const uint16_t smax = guest_h16(rdram, 0x801BC044u);
        if (smax >= 1u && smax <= 9999u) guest_h16(rdram, 0x801BC046u) = smax;
    }
    // VENTAJA ("back attack"): ya NO la incluye MODO HEAVEN (con HEAVEN el PODER es infinito, que es
    // superior; forzar la ventaja ademas seria redundante). Solo se fuerza con VENTAJA = SI.
    if (hh::menu::advantage_enabled()) {
        // SORPRESA/ventaja ("back attack") siempre [VALIDADO funcionalmente]: el byte de estado
        // 0x801BBBF0+0x1034 (0x801BCC24) pasa a 2 en un combate con ventaja; al forzarlo la pelea
        // empieza con el POWER al máximo desde el inicio. Si esta en 0/1 lo forzamos.
        uint8_t* b = &rdram[((0x801BCC24u - 0x80000000u) ^ 3u)];
        if (*b < 2u) {
            *b = 2u;
        }
    }
    if (!battle_trace_active()) return;
    if (g_battle_watch_reinit.exchange(false)) {
        battle_watch_capture();
        // Cada activacion (F12 ON) escribe su propio fichero: hh_battle_watch_<seq>.log. Asi no hay
        // que copiar/renombrar a mano: el 1.er ON (combate normal) es _0 y el 2.º (sorpresa) es _1.
        if (g_battle_watch_fp != nullptr) { std::fclose(g_battle_watch_fp); g_battle_watch_fp = nullptr; }
        char name[64];
        std::snprintf(name, sizeof name, "hh_battle_watch_%u.log", g_battle_watch_seq++);
        g_battle_watch_fp = std::fopen(name, "w");
        g_battle_watch_lines = 0;
        hh::log("[battle] watch log -> %s\n", name);
        return;
    }
    uint8_t* base = hh::get_game_rdram();
    if (base == nullptr) return;
    // Puntero al struct VIVO del jugador (*(0x801BBCCC)) y vigilancia de sus primeros 0x40 bytes:
    // la vida de campo (robots) vive ahí, no en la party de combate.
    {
        uint32_t live = 0;
        std::memcpy(&live, base + (0x801BBCCCu - 0x80000000u), 4);   // MEM_W: ya es el valor guest
        static uint32_t last_live = 0;
        static uint8_t live_shadow[0x100];
        static bool live_valid = false;
        if (live != last_live && live >= 0x80000000u && live < 0x80400000u) {
            last_live = live;
            std::memcpy(live_shadow, base + (live - 0x80000000u), sizeof(live_shadow));
            live_valid = true;
            hh::log("[battle] live_ptr=%08X\n", live);
        } else if (live_valid) {
            uint8_t* p = base + (live - 0x80000000u);
            if (g_battle_watch_fp == nullptr) g_battle_watch_fp = std::fopen("hh_battle_watch.log", "w");
            for (uint32_t b = 0; b + 4 <= sizeof(live_shadow); b += 4) {
                uint32_t now, old;
                std::memcpy(&now, p + b, 4);
                std::memcpy(&old, live_shadow + b, 4);
                if (now != old) {
                    if (g_battle_watch_fp != nullptr && g_battle_watch_lines < 200000) {
                        g_battle_watch_lines++;
                        std::fprintf(g_battle_watch_fp, "LIVE vi=%llu addr=%08X %08X->%08X\n",
                                     (unsigned long long)hh_get_vi_count(), live + b, old, now);
                        std::fflush(g_battle_watch_fp);
                    }
                    std::memcpy(live_shadow + b, &now, 4);
                }
            }
        }
    }
    const uint64_t vi = hh_get_vi_count();
    for (size_t i = 0; i < kBattleWatchCount; ++i) {
        const uint32_t o = kBattleWatchRanges[i].addr - 0x80000000u;
        const uint32_t n = kBattleWatchRanges[i].size;
        auto& sh = g_battle_watch_shadow[i];
        auto& seen = g_battle_watch_seen[i];
        if (sh.size() != n || seen.size() != n / 4u) { battle_watch_capture(); return; }
        uint8_t* p = base + o;
        for (uint32_t b = 0; b + 4 <= n; b += 4) {
            uint32_t now, old;
            std::memcpy(&now, p + b, 4);
            std::memcpy(&old, sh.data() + b, 4);
            if (now == old) continue;
            // Rango "all": registra cada transicion (hasta 64 por palabra); el resto, solo la primera.
            bool do_log;
            if (kBattleWatchRanges[i].all) {
                do_log = seen[b / 4u] < 64u;
                if (do_log) seen[b / 4u]++;
            } else {
                do_log = (seen[b / 4u] == 0);
                if (do_log) seen[b / 4u] = 1;
            }
            if (do_log) {
                if (g_battle_watch_fp == nullptr) g_battle_watch_fp = std::fopen("hh_battle_watch.log", "w");
                if (g_battle_watch_fp != nullptr && g_battle_watch_lines < 200000) {
                    g_battle_watch_lines++;
                    // La palabra guest se lee directa (MEM_W = *(int32_t*)); sin bswap.
                    std::fprintf(g_battle_watch_fp, "%svi=%llu addr=%08X %08X->%08X\n",
                                 kBattleWatchRanges[i].all ? "STATE " : "",
                                 (unsigned long long)vi, kBattleWatchRanges[i].addr + b,
                                 old, now);
                    std::fflush(g_battle_watch_fp);
                }
            }
            std::memcpy(sh.data() + b, &now, 4);
        }
    }
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

// F12: activa/desactiva la traza de combate (registro de cambios). Al activarla se captura el estado
// actual como sombra para que la primera comparacion sea la del frame siguiente.
void hh::battle_trace_toggle() {
    (void)battle_trace_active();   // inicializa desde HH_BATTLE_TRACE si es la primera vez
    const bool on = !g_battle_trace.load();
    g_battle_trace.store(on);
    if (on) {
        // La recaptura la hace el hilo de juego (evita tocar las sombras desde el hilo de input).
        g_battle_watch_reinit.store(true);
    }
    hh::log("[battle] watch %s\n", on ? "ON" : "OFF");
}

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
    // Test headless (HH_SAVEEDIT_LOADTEST=1): llama a la carga nativa de un slot (func_801423C8) para
    // poblar los globals (y disparar el volcado si HH_SAVEEDIT_DUMP=1). Slot en HH_SAVEEDIT_SLOT.
    static const bool loadtest = env_set("HH_SAVEEDIT_LOADTEST");
    if (loadtest) {
        static bool done = false;
        if (!done) {
            done = true;
            int slot = 0;
            if (const char* s = std::getenv("HH_SAVEEDIT_SLOT")) slot = std::atoi(s);
            hh::log("[save-edit][loadtest] cargando slot %d via func_801423C8\n", slot);
            ctx->r4 = 0;
            ctx->r5 = static_cast<uint32_t>(slot);
            func_801423C8_103AB98(rdram, ctx);
            hh::log("[save-edit][loadtest] hecho\n");
        }
        return;
    }
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
    // Estado de input MANTENIDO (lo escribe el poll del juego, func_800021B4, con s0=0x80089474):
    //   +0x2 = muestra cruda (A/B/START + D-pad)   -> 0x80089476
    //   +0xA = procesado (solo stick->D-pad, arranca de 0) -> 0x8008947E
    // Las funciones 801C1340/801C1334 leen los registros de FLANCOS (+0xC/+0x4), NO el mantenido: con
    // ellas `dir` se anulaba al frame siguiente y el repeat nunca disparaba. OR de ambos = mantenido
    // completo (botones + direcciones de D-pad y de stick).
    auto rh16 = [&](uint32_t a) -> uint16_t {
        return *reinterpret_cast<uint16_t*>(&rdram[(a ^ 2u) & 0x7FFFFFu]);
    };
    const uint32_t btn = rh16(0x80089476u) | rh16(0x8008947Eu);
    static uint32_t prev = 0;
    // ANTI-REBOTE (ver `g_menu_seed_input`): primer frame tras (re)entrar al menú -> traga el estado
    // mantenido (siembra `prev`) y no navega, para que el START que abrió el menú no dispare una acción.
    if (g_menu_seed_input.exchange(false)) {
        prev = btn;
        return;
    }
    // CONTROLES: mientras se captura un input para reasignar, se consume el frame y NO se navega
    // (el input va a la captura; ESC cancela). El handler nativo sigue corriendo (muteado).
    // Se RE-LEE el estado TRAS `pad_capture_poll` (que puede haber ASIGNADO el input): el nuevo
    // binding entra asi en `prev` y no genera un flanco falso (p. ej. al asignar la tecla de
    // "atras", que si no volveria un menu).
    if (hh::pad_capture_active()) {
        hh::pad_capture_poll();
        prev = rh16(0x80089476u) | rh16(0x8008947Eu);   // el nuevo binding entra en `prev`
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
    // Direcciones (up/down 0x800/0x400, left/right 0x200/0x100) tomadas del estado MANTENIDO (`btn`),
    // no del flanco: el FLANCO es la primera vez que `dir != held` (mueve al instante) y el REPEAT
    // (mantener) emite pasos extra tras ~0.4 s, acelerando (0.10 s -> 0.03 s). Con `pressed` el repeat
    // NO funcionaba: la direccion se anulaba al frame siguiente (no habia flanco).
    uint32_t dir = btn & (0x800u | 0x400u | 0x200u | 0x100u);
    // ¿cambió un valor con izquierda/derecha en ESTE frame (flanco o repeat)? -> hay que ejecutar la
    // accion del selector (izq/der cambian valor; el repeat antes no la ejecutaba).
    bool moved_h = false;
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
            else if (dir & 0x200u) { ev = hh::menu::move_left(); moved_h = true; }
            else if (dir & 0x100u) { ev = hh::menu::move_right(); moved_h = true; }
            emitted = (ev != hh::menu::Event::None);
        }
    }
    // Aceptar = A (0x8000) o START (0x1000). En PC el START por defecto es Enter; en el original
    // tambien se entra en los menus con Start. Ver docs/releases/v0.6.0.md.
    if (!nav_block && (pressed & (0x8000u | 0x1000u))) ev = hh::menu::confirm();   // A/Start: entra / marca
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
        (moved_h || (pressed & (0x8000u | 0x1000u)))) {
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
            } else if (cur.action == hh::menu::Action::ToggleHeavenMode) {
                // MODO HEAVEN: modo GLOBAL (no depende de la partida ni del editor). Persiste el flag;
                // los efectos de runtime (invulnerabilidad + items no consumibles) y la aplicación de
                // ATRIBUTOS/ESTADO al cargar partida los hacen los hooks, gateados por
                // `hh::menu::heaven_enabled()`. No toca el `.pak` (eso es EDICIÓN DE PARTIDA).
                hh::menu::set_heaven_enabled(cur.value != 0);
                hh::log("[heaven] MODO HEAVEN %s\n", cur.value != 0 ? "SI (global)" : "NO");
            } else if (cur.action == hh::menu::Action::ToggleAdvantage) {
                // VENTAJA: ventaja de combate ("back attack") siempre, INDEPENDIENTE de MODO HEAVEN.
                // Persiste el flag; el forzado por-frame lo hace `hh_battle_frame_hook` si HEAVEN o
                // VENTAJA estan en SI. No toca el `.pak`.
                hh::menu::set_advantage_enabled(cur.value != 0);
                hh::log("[heaven] VENTAJA %s\n", cur.value != 0 ? "SI" : "NO");
            } else if (cur.action == hh::menu::Action::ToggleInfinitePower) {
                // PODER ∞: `hh_battle_frame_hook` pinnea el PODER (0x801BC042) a su max (0x801BC040)
                // cada frame -> no se gasta. Independiente de MODO HEAVEN/VENTAJA.
                hh::menu::set_infinite_power_enabled(cur.value != 0);
                hh::log("[heaven] PODER infinito %s\n", cur.value != 0 ? "SI" : "NO");
            } else if (cur.action == hh::menu::Action::ToggleInfiniteStamina) {
                // RESIS. ∞: pinnea la RESISTENCIA (0x801BC046) a su max (0x801BC044) cada frame.
                hh::menu::set_infinite_stamina_enabled(cur.value != 0);
                hh::log("[heaven] RESISTENCIA infinita %s\n", cur.value != 0 ? "SI" : "NO");
            } else if (cur.action == hh::menu::Action::ToggleDebugLevels) {
                // DEBUG NIVELES: activa los atajos del ciclo de puntos y el indicador `idx=`.
                hh::menu::set_debug_levels_enabled(cur.value != 0);
                hh::log("[ciclo] DEBUG NIVELES %s\n", cur.value != 0 ? "SI" : "NO");
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
                hh::save::set_level_of(hh::menu::save_edit_slot(), static_cast<uint16_t>(cur.value + 1));
            } else if (cur.action == hh::menu::Action::SaveEditBodyState) {
                hh::menu::set_save_edit_body_state(cur.value);
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditAttrLevel) {
                // NIVEL de un atributo: aplica la tabla real (stat += incremento[nivel]) y recalcula el
                // nivel global. `cur.value` es el nivel objetivo; aplicamos la diferencia con el actual.
                const int slot = hh::menu::save_edit_slot();
                const int delta = cur.value - static_cast<int>(hh::save::part_level_of(slot, cur.index));
                if (delta != 0) {
                    hh::save::add_part_levels(slot, cur.index, delta);
                    hh::menu::refresh_save_edit();
                }
            } else if (cur.action == hh::menu::Action::SaveEditAttrBulk) {
                // TODOS: fija los 6 atributos al nivel `cur.value` (0..99).
                const int slot = hh::menu::save_edit_slot();
                for (int p = 0; p < hh::save::kParts; ++p) {
                    const int d = cur.value - static_cast<int>(hh::save::part_level_of(slot, p));
                    if (d != 0) hh::save::add_part_levels(slot, p, d);
                }
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditBodyBulk) {
                // TODOS de ESTADO: fija las 6 partes del eje activo (OFENSIVO/DEFENSIVO) a `cur.value`.
                const int slot = hh::menu::save_edit_slot();
                const int kind = hh::menu::save_edit_body_state();
                for (int part = 0; part < hh::save::kParts; ++part)
                    hh::save::set_body_stat_of(slot, part, kind, static_cast<uint16_t>(cur.value));
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditBodyValue) {
                hh::save::set_body_stat_of(hh::menu::save_edit_slot(), cur.index, hh::menu::save_edit_body_state(),
                                        static_cast<uint16_t>(cur.value));
            } else if (cur.action == hh::menu::Action::SaveEditBodyLevel) {
                // NIVEL de la parte: aplica la tabla real (stat += incremento[nivel]) y recalcula el
                // nivel global. `cur.value` es el nivel objetivo; aplicamos la diferencia.
                const int slot = hh::menu::save_edit_slot();
                const int delta = cur.value - static_cast<int>(hh::save::part_level_of(slot, cur.index));
                if (delta != 0) {
                    hh::save::add_part_levels(slot, cur.index, delta);
                    hh::menu::refresh_save_edit();
                }
            } else if (cur.action == hh::menu::Action::SaveEditBodyProgress) {
                hh::save::set_part_progress_of(hh::menu::save_edit_slot(), cur.index,
                                               static_cast<uint16_t>(cur.value));
            } else if (cur.action == hh::menu::Action::SaveEditItem) {
                hh::save::set_item_count_of(hh::menu::save_edit_slot(), cur.index, static_cast<uint8_t>(cur.value));
            } else if (cur.action == hh::menu::Action::SaveEditStat) {
                hh::save::set_global_stat_of(hh::menu::save_edit_slot(), cur.index, static_cast<uint16_t>(cur.value));
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
            } else if (cur.action == hh::menu::Action::SaveEditDelete) {
                // ELIMINAR: A sobre el selector borra en memoria el slot elegido. Queda efectivo al
                // GUARDAR (que recalcula checksums y reescribe el `.pak`). `cur.value` es el indice
                // del selector (0-based); el target se guarda 1-based -> +1 (si no, off-by-one: no
                // borraba el ultimo slot y borraba el anterior).
                hh::menu::set_save_edit_delete_target(cur.value + 1);
                const int dslot = hh::menu::save_edit_delete_slot();
                hh::save::delete_slot(dslot);
                hh::save::flush();   // persiste YA (sin re-marcar la cabecera del slot borrado)
                hh::log("[save-edit] ELIMINAR slot %d (persistido)\n", dslot);
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::SaveEditRestore) {
                // RESTAURAR: descarta los cambios en memoria del slot (vuelve al estado al cargar).
                hh::save::restore_slot(hh::menu::save_edit_slot());
                hh::menu::refresh_save_edit();
            } else if (cur.action == hh::menu::Action::WarpToLevel) {
                // IR A NIVEL: teletransporta al Area-Parte seleccionada inyectando la transicion del
                // juego (func_8012FE50(tipo=15, idx)). Si hay partida cargada, warp directo. Si no,
                // se escribe la PLANTILLA base en un slot temporal y se dispara la carga nativa; el
                // hook de carga (hh_heaven_load_hook) consume el warp pendiente. Ver plan 2026-09-29.
                const uint16_t idx = hh::menu::warp_value_at(cur.value);
                if (hh::menu::game_loaded()) {
                    recomp_context t = *ctx;
                    t.r4 = 15; t.r5 = idx; t.r6 = 1; t.r7 = 6;
                    hh::log("[elegir-nivel] IR A NIVEL (directo) idx=%u\n", idx);
                    func_8012FE50_1028620(rdram, &t);
                } else {
                    // Slot temporal: el primer hueco libre (lo mas bajo vacio) o el 0.
                    int tslot = 0;
                    for (int s = 0; s < hh::save::kSlots; ++s) {
                        if (!hh::save::slot_used(s)) { tslot = s; break; }
                    }
                    hh::log("[elegir-nivel] IR A NIVEL sin partida: plantilla -> slot %d, warp idx=%u\n",
                            tslot, idx);
                    hh::menu::request_warp(idx);
                    if (hh::save::load_template(tslot)) {
                        hh::save::save(tslot, rdram, ctx);       // escribe el .pak + recarga el pak
                    }
                    // Dispara el CONTINUAR NATIVO (fija sel=CONTINUE + A) para montar la partida.
                    rdram[(0x801CC8C4u - 0x80000000u) ^ 3u] = 1;
                    g_inject_native_a = true;
                }
            }
        }
    }
    // CONTINUAR (raiz): monta la rama NATIVA de CONTINUE llamando DIRECTAMENTE a su callback
    // (`func_801C3CDC`), replicando la rama `sel=1` del jump table del menú de título
    // (`jtbl_801CF264[1]` -> 0x801C1F30: func_800023A8(0) + func_80020718(8) + func_800058DC(obj,
    // func_801C3CDC)). NO se usa el patrón `sel`+A: el handler nativo RECALCULA `sel` desde su cursor
    // (D-pad) y pisaba nuestro 1, abriendo otra rama (p. ej. MODO COMBATE -> BATTLE DATA LOAD). Ver
    // notes 2026-09-30. Solo con el overlay controlando.
    if (ev == hh::menu::Event::Accept && same_screen && hh::overlay::enabled()) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size()) &&
            s.entries[s.cursor].action == hh::menu::Action::Continue) {
            // Al elegir CONTINUAR ya sabemos que vamos al file-select: activa YA su categoría de
            // ocultado para que su SETUP (que compone título/`CONTROLLER PAK`/caja) se blankee aunque
            // no enganchemos `func_801C3D50` (su dirección la comparte otro módulo -> colgaba).
            // `g_load_enter` mantiene la categoría activa mientras dura la transición (el callback
            // nativo puede seguir siendo el del TÍTULO 1-2 frames; ver hh_title_menu_hook).
            hh::menu_overlay::set_file_select_active(true);
            g_load_enter = true;
            g_load_enter_frame = g_hook_frame;
            // NO publicamos todavía: en el original el TÍTULO se ve hasta que entra el DATA LOAD, y
            // publicar aquí dibujaría nuestra UI ENCIMA del título (logo/copyright) durante 1-2 frames.
            // `hh_title_menu_hook` conserva el frame del título durante `g_load_enter`; la UI de carga
            // aparece en cuanto el file-select toma el control (primer frame de `hh_file_select_hook`).
            if (env_set("HH_LOAD_TRACE")) {
                hh::log("[load-trace] CONTINUAR -> g_load_enter=1 frame=%ld\n", g_hook_frame);
            }
            recomp_context t0 = *ctx;
            t0.r4 = 0;
            func_800023A8_2FA8(rdram, &t0);          // (igual que la rama nativa)
            recomp_context t1 = *ctx;
            t1.r4 = 8;
            func_80020718_21318(rdram, &t1);
            recomp_context t2 = *ctx;
            t2.r4 = obj;
            t2.r5 = 0x801C3CDCu;                     // callback de CONTINUE (func_801C3CDC)
            func_800058DC_64DC(rdram, &t2);
            hh::log("[menu] CONTINUAR -> rama CONTINUE nativa (func_801C3CDC)\n");
        }
    }
    // CARGAR PARTIDA (menú propio de carga): el control del flujo vive en `feed_load_flow`, invocado
    // desde `hh_file_select_hook` (la pantalla `LoadGame` solo se alcanza ahí; este handler del título
    // no la procesa). Ver notes 2026-10-01.
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

extern "C" int g_font_all_countdown;   // definido abajo (ventana de volcado de glifos)

// DIAGNOSTICO (HH_LOAD_TRACE): indice de escena del slot que devuelve `func_8013EA54` (0xFF = cancelar).
static uint32_t g_area_last_scene_idx = 0xFFFFFFFFu;

extern "C" void hh_area_scene_idx_hook(uint8_t* rdram, recomp_context* ctx) {
    func_8013EA54_1037224(rdram, ctx);
    g_area_last_scene_idx = static_cast<uint32_t>(ctx->r2);
    if (env_set("HH_FONT_TRACE")) {
        // `func_8013EA54` se llama desde `func_801C3E24` ANTES de `func_80146208` (que puede cargar
        // los glifos del nombre). Activar aquí la ventana cubre esa llamada.
        g_font_all_countdown = 400;
    }
    if (env_set("HH_LOAD_TRACE")) {
        // `func_8013EA54` lee el cursor nativo del file-select (D_801BEC05) y la entrada D_801BEB80[cursor]
        // (8 B): si el campo +4 != 1 devuelve BASURA de pila (bug del original); si == 1 devuelve el
        // campo +6 (el indice que usan func_801C3E24/801C3F48 para indexar sus tablas). Lo registramos
        // todo para ver en el run real si el indice es valido.
        const unsigned cur = rdram[(0x801BEC05u - 0x80000000u) ^ 3u];
        const uint32_t ent = 0x801BEB80u + (static_cast<uint32_t>(cur) * 8u);
        char eb[40];
        for (int i = 0; i < 8; ++i) {
            std::snprintf(eb + i * 3, 4, "%02X ", rdram[((ent + i) - 0x80000000u) ^ 3u]);
        }
        hh::log("[load-trace] AREA func_8013EA54 ret=%u (st=%u cur=%u top=%u pak=%u ent[%02X]=%s)\n",
                g_area_last_scene_idx,
                rdram[(0x801BEBCCu - 0x80000000u) ^ 3u],   // estado nativo (2 = lista interactiva)
                cur, rdram[(0x801BEC04u - 0x80000000u) ^ 3u],
                rdram[(0x801BBF42u - 0x80000000u) ^ 3u],   // flag de arranque del pak
                ent & 0xFFFFFFu, eb);
    }
}

// DIAGNOSTICO (HH_LOAD_TRACE): envuelve el callback `func_801C3F48` (titulo del Area). Registra si
// corre, el `D_801CC8CC` y, tras el original, el byte `t0` de la tabla `D_801CCAE0[índice]` (si es 0
// el original NO llama al compositor `func_8001B204`).
extern "C" void hh_area_title_hook(uint8_t* rdram, recomp_context* ctx) {
    if (env_set("HH_LOAD_TRACE")) {
        hh::log("[load-trace] AREA TITLE callback enter obj=%08X D_801CC8CC=%u\n",
                static_cast<uint32_t>(ctx->r4),
                rdram[(0x801CC8CCu - 0x80000000u) ^ 3u]);
    }
    func_801C3F48_11BDA18(rdram, ctx);
    if (env_set("HH_LOAD_TRACE")) {
        uint8_t t0 = 0;
        const uint32_t idx = g_area_last_scene_idx;
        char tb[48];
        for (int i = 0; i < 12; ++i) {
            std::snprintf(tb + i * 3, 4, "%02X ", rdram[((0x801CCAE0u + i) - 0x80000000u) ^ 3u]);
        }
        if (idx < (0x800000u - (0x801CCAE0u - 0x80000000u))) {
            t0 = rdram[((0x801CCAE0u + idx) - 0x80000000u) ^ 3u];
        }
        const unsigned scene = (static_cast<unsigned>(rdram[(0x801BBBF4u - 0x80000000u) ^ 3u]) << 8) |
                               static_cast<unsigned>(rdram[(0x801BBBF5u - 0x80000000u) ^ 3u]);
        hh::log("[load-trace] AREA TITLE callback exit idx=%u t0=%u D_801CCAE0=[%s] "
                "D_801BBBF4=%u\n",
                idx, t0, tb, scene);
    }
    if (env_set("HH_FONT_TRACE")) {
        g_font_all_countdown = 400;   // ventana: volcar los glifos del título del Área
    }
    // Overlay traducido (idiomas != inglés): marca el título activo y lo publica cada frame del fade.
    // El NÚMERO DE ÁREA se deriva del VALOR DE ESCENA vivo `[0x801BBBF0+4]` (u16 BE), NO del índice
    // `func_8013EA54`/`D_801CCAE0`: ese índice es el campo `+6` del modelo de fila (`func_80108280>>8`,
    // un valor que avanza por PARTE de área: 0,2,10,20…), así que indexar `D_801CCAE0` (tabla de 12
    // entradas ÁREA 1..9) daba un título equivocado según la parte (1-2 salía Área 2; 6-1 salía Área 1).
    // `[0x801BBBF4]` es el mismo valor que usa `save_live` para la cabecera -> `area_sub_from_value`.
    if (hh::overlay::enabled() && hh::text_current_language() != "ja") {
        const uint16_t scene = static_cast<uint16_t>((rdram[(0x801BBBF4u - 0x80000000u) ^ 3u] << 8) |
                                                     rdram[(0x801BBBF5u - 0x80000000u) ^ 3u]);
        int area = 1, sub = 1;
        hh::menu::area_sub_from_value(scene, area, sub);
        const uint8_t t0 = static_cast<uint8_t>(area);
        if (env_set("HH_LOAD_TRACE")) {
            hh::log("[load-trace] AREA overlay: idx=%u scene=%u -> area=%d sub=%d\n",
                    g_area_last_scene_idx, scene, area, sub);
        }
        if (t0 >= 1 && t0 <= 9) {
            if (!g_area_title_active) {
                g_area_title_frames = 0;          // nuevo título: reinicia el fade
                g_area_title_in_transition = false;
                g_area_title_start_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                            std::chrono::steady_clock::now().time_since_epoch())
                                            .count();
            }
            g_area_title_num = t0;
            g_area_title_active = true;
            ++g_area_title_frames;
            hh::menu_overlay::publish_area_title(t0, hh::menu_overlay::area_title_name(t0),
                                                 area_title_alpha());
        }
    }
}

// Espera de input del título del Área (`func_801C4018`): sigue publicando el overlay traducido cada
// frame (el original espera A/espera para pasar a la transición de escena).
extern "C" void hh_area_wait_hook(uint8_t* rdram, recomp_context* ctx) {
    if (g_area_title_active) {
        ++g_area_title_frames;
        hh::menu_overlay::publish_area_title(g_area_title_num,
                                             hh::menu_overlay::area_title_name(g_area_title_num),
                                             area_title_alpha());
    }
    func_801C4018_11BDAE8(rdram, ctx);
}

// Transición de escena del título (`func_801C4074`): se sigue publicando el overlay para CUBRIR el
// nombre nativo (que persiste) hasta que arranca el gameplay. Se deja de dibujar cuando un goto
// posterior cambia el callback (ver hh_goto_hook).
extern "C" void hh_area_trans_hook(uint8_t* rdram, recomp_context* ctx) {
    if (g_area_title_active) {
        ++g_area_title_frames;
        hh::menu_overlay::publish_area_title(g_area_title_num,
                                             hh::menu_overlay::area_title_name(g_area_title_num),
                                             area_title_alpha());
    }
    func_801C4074_11BDB44(rdram, ctx);
}

// Overlay A2: envuelve la composición de texto (0x8001B204). Si el texto es del menú nativo y éste
// está oculto, lo blankea justo antes de que el original lo lea. Es la pieza que elimina el flash:
// cubre la PRIMERA composición (fase de fade-in), en la que el handler del menú aún no corre.
extern "C" void hh_entry_register_hook(uint8_t* rdram, recomp_context* ctx) {
    // File-select (DATA LOAD/SAVE) controlado por el overlay y nativo oculto: SALTAR el compositor
    // de texto por completo (no compone ni dibuja). Es la vía robusta (no depende de listar tablas,
    // que resultó incompleta). F8 (`native_visible`) restaura el nativo. Ver notes 2026-09-30.
    // `func_80142570` (lo llama el compositor) VACIA las 0x1C ranuras de texto componiendo cadenas
    // VACIAS via 0x8001B204 con `a3=0x8018F0F0`. Esas llamadas hay que DEJARLAS PASAR aunque el nativo
    // este oculto; si no, al ocultar (p. ej. F8-off) el texto ya compuesto no se borra y queda pegado.
    constexpr uint32_t kFileSelectClearStr = 0x8018F0F0u;
    // TÍTULO DEL ÁREA al CARGAR partida: `func_801C3F48` (callback de ÉXITO que fija `func_801C3E24`)
    // compone el nombre del Área por este compositor con `a3=0x801CED98` (ver nota
    // `notes/2026-10-01-titulo-area-carga.md`). Es texto del juego, NO del file-select: hay que
    // DEJARLO PASAR aunque la categoría FILE-SELECT siga activa, o el port muestra solo negro sin
    // título. No está en las tablas de blankeo, así que `filter_native_text` no lo toca.
    constexpr uint32_t kAreaTitleField = 0x801CED98u;
    const uint32_t a3 = static_cast<uint32_t>(ctx->r7);
    // DIAGNÓSTICO de la transición a CARGAR (HH_LOAD_TRACE): registra cada composición de texto con
    // su `a3` mientras `g_load_enter` está activo, para ver QUÉ texto se compone (y si se cuela) antes
    // de que nuestra UI de carga publique. `skip` = se habría saltado el compositor.
    if (env_set("HH_LOAD_TRACE") && g_load_enter) {
        // `skip=0` aquí significa que este texto NO se saltó: si es del file-select, se cuela.
        hh::log("[load-trace] entry compose a3=%08X skip=%d\n", a3,
                hh::menu_overlay::file_select_text_skip() ? 1 : 0);
    }
    // Título del Área (a3 = campo de enlace): el juego lo compone con la plantilla "%m%aAREA %d".
    //  - JAPONÉS o overlay desactivado: se deja pasar (el juego dibuja el título nativo).
    //  - Resto de idiomas (en/es/ca/fr/de): NO se compone (el nombre es un gráfico intraducible) y lo
    //    pinta NUESTRO overlay traducido (ver hh_area_title_hook / publish_area_title).
    if (a3 == kAreaTitleField) {
        const bool translate = hh::overlay::enabled() && hh::text_current_language() != "ja";
        if (env_set("HH_LOAD_TRACE")) {
            hh::log("[load-trace] AREA TITLE compose a3=%08X (%s)\n", a3,
                    translate ? "overlay" : "dejar pasar");
        }
        if (translate) {
            return;   // lo dibuja el overlay
        }
        func_8001B204_1BE04(rdram, ctx);
        return;
    }
    if (hh::menu_overlay::file_select_text_skip() &&
        a3 != kFileSelectClearStr) {
        if (env_set("HH_MENU_TRACE")) {
            hh::log("[entry] SKIP file-select a3=%08X\n", static_cast<uint32_t>(ctx->r7));
        }
        return;
    }
    if (env_set("HH_MENU_TRACE")) {
        // Cada `a3` (dirección del texto compuesto) distinto, una vez: sirve para mapear QUÉ tablas
        // de etiquetas pasa cada pantalla (p. ej. al entrar/salir de submenús).
        static std::vector<uint32_t> seen;
        static uint64_t n = 0;
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
    ++g_hook_frame;
    // ANTI-REBOTE: primer frame tras (re)entrar al menú (hueco real desde el frame anterior) -> ceba
    // el input para que el START que abrió el menú no dispare una acción (ver `g_menu_seed_input`).
    {
        static long last = -1;
        if (last < 0 || g_hook_frame - last > 1) {
            g_menu_seed_input.store(true);
        }
        last = g_hook_frame;
    }
    hh::overlay::set_screen_blackout(false);   // seguridad: el telon nunca tapa el menu
    // Al correr el handler del TÍTULO ya no estamos en el file-select: desactiva su categoría de
    // ocultado (si no, quedaría activa tras volver del DATA LOAD). EXCEPCIÓN: si venimos de pulsar
    // CONTINUAR (`g_load_enter`), el callback nativo aún puede ser el del título durante la
    // transición; mantener la categoría evita que se cuele el nativo del file-select.
    if (!g_load_enter) {
        hh::menu_overlay::set_file_select_active(false);
    } else if (env_set("HH_LOAD_TRACE")) {
        // Frames intermedios de la transición (callback nativo del TÍTULO aún activo). Aquí es donde
        // podría colarse/republicarse algo antes de que arranque el file-select.
        hh::log("[load-trace] title hook g_load_enter=1 frame=%ld (+%ld)\n", g_hook_frame,
                g_hook_frame - g_load_enter_frame);
    }
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
        // EXCEPCIÓN: durante la transición a CARGAR (`g_load_enter`) NO se procesa input del título: la
        // pila ya es [Root, LoadGame] y el input lo tomará `feed_load_flow` en el file-select.
        if (!g_load_enter) {
            feed_menu_navigation(rdram, ctx);
        }

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
    // EXCEPCIÓN: durante la transición a CARGAR (`g_load_enter`) NO publicamos: se conserva el frame
    // del TÍTULO (como el original) hasta que el file-select publica la UI de carga (frame siguiente).
    // Publicar aquí dibujaría la UI ENCIMA del logo/copyright del título.
    if (!screen_changed && !g_load_enter) {
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

// Overlay A2: envuelve el file-select DATA LOAD (setup `func_801C3D50` y update `func_801C3D84`,
// file_024 OVERLAY), el menú nativo de CARGAR partida al que llega CONTINUAR. Fase 3 del menú de
// carga/guardado: el nativo se OCULTA y su input se MUTEA (el file-select lee A/Z/Start en
// `0x80089478`), mientras publicamos NUESTRA pantalla LoadGame. Así no se ejecuta su máquina de
// estados (ni sus mensajes de Controller/Rumble Pak).
//
// El ocultado por CATEGORÍAS vive en `menu_overlay.cpp` (texto del título, texto del file-select y
// cajas); aquí solo se marca que la categoría FILE-SELECT está ACTIVA. La visibilidad la decide F8
// (`native_visible`), única fuente de verdad.
constexpr uint32_t kFileSelectInputAddr = 0x80089478u;   // +0x4 de 0x80089474 (A/Z/Start + D-pad)

// NOTA: NO se engancha el SETUP del file-select (`func_801C3D50`): esa dirección la comparte otro
// módulo (base solapada) y su hook colgaba el juego (medido). La categoría se activa desde el propio
// CONTINUAR (antes de inyectar A), que es quien sabe que vamos a entrar al file-select.

// Salir de CARGAR volviendo al MENÚ DE TÍTULO (NO a la cápsula; ese es el flujo del GUARDADO). Se
// replica la rama de CANCELAR nativa de `func_801C3D84` (ret==2): `func_80142570()` vacía el texto y
// `func_8012FE50(0x17, 0x73, 1, 1, 0)` + callback `func_801C40EC` vuelven al título.
static void hh_leave_load_game(uint8_t* rdram, recomp_context* ctx, uint32_t obj) {
    recomp_context t = *ctx;
    func_80142570_103AD40(rdram, &t);
    t = *ctx;
    t.r4 = 0x17;
    t.r5 = 0x73;
    t.r6 = 1;
    t.r7 = 1;
    t.r8 = 0;
    func_8012FE50_1028620(rdram, &t);
    t = *ctx;
    t.r4 = obj;
    t.r5 = 0x801C40ECu;   // callback de cancelar (vuelve al título)
    func_800058DC_64DC(rdram, &t);
    hh::menu_overlay::hide_now();
    hh::menu::close_load_game();
    // DESACTIVAR la categoría FILE-SELECT: sin esto `file_select_text_skip()`/`suppress_box_draw()`
    // siguen a true y BLANQUEAN el texto del MENÚ DE TÍTULO (que comparte el hook de composición)
    // -> título vacío/texto fantasma y, al agotar el idle, attract. El reseteo natural lo hace
    // `hh_title_menu_hook`, pero tarda varios frames en correr tras la transición.
    hh::menu_overlay::set_file_select_active(false);
    // Resetear el `sel` del menú de título (`0x801CC8C4`) a 0 (NEW GAME): al volver del file-select
    // debe quedar en el menú de título, no re-disparar CONTINUE (que era `sel=1`). La rama CONTINUE
    // del port llama directo al callback, pero la propia maquina nativa tambien lee `sel`.
    rdram[(0x801CC8C4u - 0x80000000u) ^ 3u] = 0;
    hh::log("[load] salir de CARGAR -> menu de titulo (rama nativa)\n");
}

// Confirmar la carga de `slot`: deserializa el slot y arranca la escena replicando la rama de ÉXITO
// nativa de `func_801C3D84` (ret==1): `func_80142570()` + `func_800179B0(0)` + `func_801C11BC(0xA)` +
// callback `func_801C3E24`. `func_801C11BC` monta la transición y `func_801C3E24` (con `D_801CC8CC=2`)
// ejecuta `func_8012FE50` con el ÍNDICE DE ESCENA deserializado (`D_801BBBF4`). Es el inverso del
// guardado (`save_live`) y no pasa por la cápsula.
static void hh_do_load_game(uint8_t* rdram, recomp_context* ctx, uint32_t obj, int slot) {
    hh::log("[load] CARGAR slot %d (%s)\n", slot, hh::save::slot_name(slot).c_str());
    recomp_context t = *ctx;
    t.r4 = 0;                        // canal 0
    t.r5 = static_cast<uint32_t>(slot);
    func_801423C8_103AB98(rdram, &t);   // lee el slot 0xD00 y deserializa a los globals
    if (env_set("HH_LOAD_TRACE")) {
        // Estado nativo del file-select EN EL MOMENTO de cargar: si `st`!=2 o las entradas del modelo
        // están a cero, `func_8013EA54` (que usa el cursor nativo) devolverá basura y no habrá título.
        const unsigned scene = (static_cast<unsigned>(rdram[(0x801BBBF4u - 0x80000000u) ^ 3u]) << 8) |
                               static_cast<unsigned>(rdram[(0x801BBBF5u - 0x80000000u) ^ 3u]);
        hh::log("[load-trace] AREA load slot=%d ncur=%u ntop=%u st=%u pak=%u scene=%u\n", slot,
                rdram[(0x801BEC05u - 0x80000000u) ^ 3u],
                rdram[(0x801BEC04u - 0x80000000u) ^ 3u],
                rdram[(0x801BEBCCu - 0x80000000u) ^ 3u],
                rdram[(0x801BBF42u - 0x80000000u) ^ 3u], scene);
    }
    // `func_801C3E24` solo ejecuta la transición si `D_801CC8CC == 2` (flag del flujo de carga).
    rdram[(0x801CC8CCu - 0x80000000u) ^ 3u] = 2;
    t = *ctx;
    func_80142570_103AD40(rdram, &t);   // vacía las 0x1C ranuras de texto
    t = *ctx;
    t.r4 = 0;
    func_800179B0_185B0(rdram, &t);
    t = *ctx;
    t.r4 = 0xA;
    func_801C11BC_11BAC8C(rdram, &t);   // monta el objeto de transición
    t = *ctx;
    t.r4 = obj;
    t.r5 = 0x801C3E24u;                 // callback de éxito (transición de escena)
    func_800058DC_64DC(rdram, &t);
    hh::menu_overlay::hide_now();
    hh::menu::close_load_game();
    // Carga OK: la escena arranca; desactivar la categoría FILE-SELECT (si no, blanquearía texto de
    // la siguiente pantalla). El gameplay no usa el compositor del título, pero es más seguro.
    hh::menu_overlay::set_file_select_active(false);
}

// Control del flujo de CARGAR (`hh::menu::LoadPhase`), análogo a `feed_save_flow`:
//   Browse        -> arriba/abajo mueven el cursor; A carga el slot; X borra (ConfirmDelete); B vuelve.
//   ConfirmDelete -> Yes/No; Yes borra -> Removed; No -> Browse.
//   Loaded        -> A sale (la escena ya se montó al cargar). Removed -> A vuelve a Browse.
// Devuelve true si el flujo salió (se disparó una transición): el hook NO debe seguir dibujando.
static bool feed_load_flow(uint8_t* rdram, recomp_context* ctx, uint32_t obj) {
    auto rh16 = [&](uint32_t a) -> uint16_t {
        return *reinterpret_cast<uint16_t*>(&rdram[(a ^ 2u) & 0x7FFFFFu]);
    };
    const uint32_t btn = rh16(0x80089476u) | rh16(0x8008947Eu);
    static uint32_t prev = 0;
    const uint32_t pressed = btn & ~prev;
    prev = btn;
    const bool sfx = hh::overlay::enabled();
    constexpr uint32_t kUp = 0x800u, kDown = 0x400u;
    const uint32_t dir = btn & (kUp | kDown);
    const hh::menu::LoadPhase phase = hh::menu::load_phase();
    const bool del_btn = hh_input_button_down("z");   // agacharse = boton X del mando / tecla H
    const bool acc_btn = hh_input_button_down("a");   // aceptar  = boton A del mando / tecla J

    // Prompts Yes/No (ConfirmDelete): arriba/abajo alternan, A confirma la resaltada.
    if (phase == hh::menu::LoadPhase::ConfirmDelete) {
        if (pressed & (kUp | kDown)) {
            hh::menu::set_load_yes_selected(!hh::menu::load_yes_selected());
            if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Move);
        }
        if (pressed & (0x8000u | 0x1000u)) {   // A o Start/Enter
            const bool yes = hh::menu::load_yes_selected();
            if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
            if (yes) {
                const int dslot = hh::menu::load_target_slot();
                if (dslot >= 0) {
                    hh::log("[load] BORRAR slot %d\n", dslot);
                    hh::save::delete_slot(dslot);
                    hh::save::flush();
                }
                hh::menu::set_load_yes_selected(true);
                hh::menu::refresh_load_game();
                hh::menu::set_load_phase(hh::menu::LoadPhase::Removed);
            } else {
                hh::menu::set_load_phase(hh::menu::LoadPhase::Browse);
            }
        }
        return false;
    }
    // Loaded: A sale (la escena ya está montada). Removed: A vuelve a Browse (NO sale).
    if (phase == hh::menu::LoadPhase::Loaded || phase == hh::menu::LoadPhase::Removed) {
        if (pressed & (0x8000u | 0x1000u)) {   // A o Start/Enter
            if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
            if (phase == hh::menu::LoadPhase::Removed) {
                hh::menu::set_load_phase(hh::menu::LoadPhase::Browse);
            } else {
                hh_leave_load_game(rdram, ctx, obj);   // sale al título (la escena ya cargó)
                return true;
            }
        }
        return false;
    }
    // Browse: B -> volver al MENÚ DE TÍTULO (rama de cancelar nativa; NO es la cápsula del guardado).
    if (pressed & 0x4000u) {
        hh_leave_load_game(rdram, ctx, obj);
        return true;
    }
    // Browse: si acabamos de entrar (bloqueo ~120 ms), se ignora el input de la transición.
    if (hh::menu::load_input_blocked()) {
        return false;
    }
    // Browse: arriba/abajo mueven el cursor de la lista (mismo repeat que feed_menu_navigation).
    {
        static uint32_t held = 0;
        static double dir_next = 0.0;
        static int dir_repeats = 0;
        static bool emitted = false;
        bool fire_up = false, fire_down = false;
        const double t = std::chrono::duration<double>(
                             std::chrono::steady_clock::now().time_since_epoch()).count();
        if (dir == 0) {
            held = 0;
            dir_repeats = 0;
            emitted = false;
        } else if (dir != held) {
            held = dir;
            dir_next = t + 0.40;
            dir_repeats = 0;
            emitted = false;
        } else if (t >= dir_next) {
            dir_repeats++;
            dir_next = t + std::max(0.03, 0.10 - 0.006 * dir_repeats);
            emitted = false;
        } else {
            emitted = true;
        }
        if (!emitted) {
            if (dir & kUp) fire_up = true;
            else if (dir & kDown) fire_down = true;
        }
        if (fire_up || fire_down) {
            const hh::menu::Event ev = fire_up ? hh::menu::move_up() : hh::menu::move_down();
            if (ev != hh::menu::Event::None && sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Move);
        }
    }
    // A/Start carga (solo slots con datos); X pide borrar (solo slots con datos). Bindings en vivo.
    if (acc_btn || (pressed & (0x8000u | 0x1000u))) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            if (cur.enabled && cur.index >= 0 && hh::save::slot_present(cur.index)) {
                if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
                hh::menu::set_load_target_slot(cur.index);
                // CARGA DIRECTA (rama de ÉXITO nativa replicada). Ver RETOMAR: la vía "dejar que la
                // máquina nativa haga state 2→3→4" está BLOQUEADA porque su gate de mensaje
                // (`D_8008EE78`) no se limpia en el port (medido 2026-10-01: se queda en state 3).
                hh_do_load_game(rdram, ctx, obj, cur.index);
                return true;
            }
        }
    } else if (del_btn) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            if (cur.index >= 0 && hh::save::slot_present(cur.index)) {
                if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
                hh::menu::set_load_target_slot(cur.index);
                hh::menu::set_load_yes_selected(true);
                hh::menu::set_load_phase(hh::menu::LoadPhase::ConfirmDelete);
            }
        }
    }
    return false;
}

// TRAZA DE CARGA (HH_LOAD_TRACE=1): registra QUIÉN mueve el cursor y el estado de ocultado. Para no
// ralentizar (cada log abre/escribe/hace fflush), SOLO escribe cuando cambia algún valor relevante.
// Vuelca: fase, cursor del modelo, cursor/top/estado/página NATIVOS del file-select
// (`D_801BEC05`/`D_801BEC04`/`D_801BEBCC`/`D_801BEC02`), flag de ocultado y `native_visible`.
static void hh_load_trace(uint8_t* rdram, const char* tag) {
    if (!env_set("HH_LOAD_TRACE")) return;
    const hh::menu::Screen& s = hh::menu::current_screen();
    auto rb = [&](uint32_t a) -> unsigned { return rdram[(a - 0x80000000u) ^ 3u]; };
    const unsigned ncur = rb(0x801BEC05u), ntop = rb(0x801BEC04u);
    const unsigned st = rb(0x801BEBCCu), page = rb(0x801BEC02u);
    const int fsa = hh::menu_overlay::file_select_text_skip() ? 1 : 0;
    const int vis = hh::menu_overlay::native_visible() ? 1 : 0;
    // Clave del estado: si no cambia y no es una línea "marcadora", no se escribe.
    static long last_key = -1;
    const long key = static_cast<long>(s.cursor) * 1000000 + static_cast<long>(ncur) * 10000 +
                     static_cast<long>(st) * 100 + static_cast<long>(page) * 10 + fsa;
    const bool marker = (tag[0] == 'C' || tag[0] == 'F');   // CONTINUAR/file-select: siempre
    if (!marker && key == last_key) return;
    last_key = key;
    hh::trace_log("[load-trace] %s phase=%d cursor=%d | native cur=%u top=%u st=%u page=%u | "
                  "fs_active=%d native_visible=%d entries=%zu\n",
                  tag, static_cast<int>(hh::menu::load_phase()), s.cursor, ncur, ntop, st, page, fsa,
                  vis, s.entries.size());
}

extern "C" void hh_file_select_hook(uint8_t* rdram, recomp_context* ctx) {
    hh::overlay::set_screen_blackout(false);
    // TRAZA (HH_LOAD_TRACE): cuenta CADA entrada al file-select. Si tras volver con B (cinemática) el
    // file-select se vuelve a invocar, aquí se ve la re-entrada (origen del "vuelve a la pantalla de
    // carga"). Se registra también el `sel` del menú de título (`0x801CC8C4`) para ver si quedó en 1.
    if (env_set("HH_LOAD_TRACE")) {
        static unsigned n_in = 0;
        hh::log("[load-trace] file-select ENTRADA #%u frame=%ld g_load_enter=%d sel=%u\n",
                ++n_in, g_hook_frame, g_load_enter ? 1 : 0,
                rdram[(0x801CC8C4u - 0x80000000u) ^ 3u]);
    }
    // Ya tomamos el control del file-select: la transición desde el título terminó.
    ++g_hook_frame;
    if (g_load_enter && env_set("HH_LOAD_TRACE")) {
        hh::log("[load-trace] file-select: primer frame g_load_enter=1 -> 0 frame=%ld (+%ld desde "
                "CONTINUAR)\n",
                g_hook_frame, g_hook_frame - g_load_enter_frame);
    }
    g_load_enter = false;
    // Objeto del menu (a0): lo necesita la transición de salida (func_800058DC) y la de carga.
    const uint32_t obj = static_cast<uint32_t>(ctx->r4);
    // La pantalla activa pasa a ser NUESTRA LoadGame (la pila del modelo).
    hh::menu::open_load_game();
    hh_load_trace(rdram, "pre");
    hh::menu_overlay::suppress_native(rdram);
    hh::menu_overlay::set_file_select_active(true);   // categoría FILE-SELECT activa (ocultado)
    const bool controlling = hh::overlay::enabled();
    // Control propio del flujo de carga. Si salimos (carga/volver), NO se corre el update nativo ni
    // se publica el overlay.
    const bool exited = controlling && feed_load_flow(rdram, ctx, obj);
    if (exited) {
        g_inject_native_a = false;
        return;
    }
    // Mutea la lectura de A/Z/Start del file-select mientras controlamos: sin esto el nativo
    // despacharía su rama al ver A (y mostraría sus mensajes). Se restaura el valor original.
    uint16_t* in = reinterpret_cast<uint16_t*>(&rdram[(kFileSelectInputAddr ^ 2u) & 0x7FFFFFu]);
    const uint16_t saved = *in;
    if (controlling) {
        *in = 0;
    }
    func_801C3D84_11BD854(rdram, ctx);   // update original del file-select, con su input neutralizado
    *in = saved;
    g_inject_native_a = false;           // la inyección (si la hubo) es de un solo frame
    hh_load_trace(rdram, "post");       // estado tras el update nativo (ver quién movió el cursor)
    // F8 sobre el DATA LOAD: el título/`CONTROLLER PAK`/mensaje se componen SOLO en el setup, así que
    // al alternar la visibilidad hay que re-componerlos (las filas se recomponen cada frame). Se
    // re-ejecuta el compositor del SETUP LOAD (`func_801426B0`, el mismo que corre el flujo nativo del
    // CONTINUE en `func_8013E7C0`): compone título `DATA LOAD` + `CONTROLLER PAK` + caja + mensaje.
    //
    // OJO: NO llamar a `func_80142840`. Aunque su nombre/comentario previo sugería "Select play
    // data...", en realidad compone el SETUP del **BATTLE DATA LOAD (MODO VS)**: su tabla
    // (`a3=0x8018F20C`/`0x8018F230`) es `ＢＡＴＴＬＥ　ＤＡＴＡ　ＬＯＡＤ` + `1P CONTROLLER` /
    // `2P CONTROLLER` (medido en el volcado RDRAM: ver nota 2026-09-30). Llamarlo pintaba la pantalla
    // equivocada (dos columnas) al pulsar F8. `func_80142778` es el setup del `ＤＡＴＡ　ＳＡＶＥ`.
    if (hh::menu_overlay::native_toggle_pending()) {
        recomp_context t = *ctx;
        func_801426B0_103AE80(rdram, &t);   // SETUP del DATA LOAD (CONTINUE): título + CONTROLLER PAK + caja
    }
    // Con el nativo OCULTO, vacia cada frame sus 0x1C ranuras de texto: el prompt `Please connect
    // Controller Pak…` (y el de Rumble Pak) se compone por una via distinta al compositor que
    // saltamos, asi que hay que limpiarlo aqui (si no, se cuela por detras de nuestra UI). Mismo
    // patron que el GUARDADO (feed_save_flow). `func_80142570` compone cadenas VACIAS en cada ranura.
    if (controlling && !hh::menu_overlay::native_visible()) {
        recomp_context ct = *ctx;
        func_80142570_103AD40(rdram, &ct);
    }
    // Publica NUESTRO overlay (la pantalla LoadGame en su sitio real, ocultando el nativo).
    hh::menu_overlay::title_update(rdram);
}

// GUARDAR (cápsula): la vía nativa del DATA SAVE es OTRA (módulo de gameplay): el callback del
// file-select de guardado es `0x803771A4` -> `func_8013EB2C`; NO pasa por `0x801C3D84`. Medido con
// `run_save_trace.bat`: `SAVE_setup 0x80377140 -> SAVE_compose 0x8013EA94 -> SAVE_title 0x80142778 ->
// SAVE_update 0x803771A4 + SAVE_state 0x8013EB2C` cada frame.
//
// Publica la COPIA de la UI de cargar (`SaveGame`) y OCULTA el DATA SAVE nativo por la MISMA categoria
// FILE-SELECT que CARGAR: **F8** alterna mostrar/ocultar (`g_native_visible`). Sin lógica de guardado.
extern "C" void hh_save_setup_hook(uint8_t* rdram, recomp_context* ctx) {
    // Activa la categoria ANTES de que el setup componga el titulo `DATA SAVE` (asi se salta igual que
    // en CARGAR, donde se activa antes de la transicion).
    if (env_set("HH_MENU_TRACE")) {
        static bool once = false;
        if (!once) { once = true; hh::log("[save] setup hook (0x80377140) corre\n"); }
    }
    hh::menu_overlay::set_file_select_active(true);
    func_80377140_1300750(rdram, ctx);
}

// Salir de la capsula replicando EXACTAMENTE la rama de salida NATIVA. El envoltorio del DATA SAVE
// (`func_803771A4`), cuando la maquina de estados (`func_8013EB2C`) devuelve 1, hace:
//   func_80142570()  +  func_800058DC(obj, func_80377478)
// y la maquina, en su estado 3, hace antes `func_80002A94(0)` + `func_800023A8(0)`. Antes se intento
// fijar el estado 3 y dejar que el update nativo la ejecutase, pero NO salia (la rama no se alcanza
// en este flujo); replicamos la secuencia directamente. `obj` = a0 del callback (lo captura el hook).
static void hh_leave_capsule(uint8_t* rdram, recomp_context* ctx, uint32_t obj) {
    recomp_context t = *ctx;
    t.r4 = 0;
    func_80002A94_3694(rdram, &t);
    t = *ctx;
    t.r4 = 0;
    func_800023A8_2FA8(rdram, &t);
    t = *ctx;
    func_80142570_103AD40(rdram, &t);
    t = *ctx;
    t.r4 = obj;
    t.r5 = 0x80377478u;   // callback de salida (restaura camara/estado de gameplay)
    func_800058DC_64DC(rdram, &t);
    hh::menu_overlay::hide_now();
    hh::menu::close_save_game();   // la próxima entrada en la cápsula reinicia el flujo
    // DESACTIVAR la categoría FILE-SELECT al salir de la cápsula. Sin esto se quedaba a true con el
    // nativo oculto -> `file_select_text_skip()`=true -> `hh_entry_register_hook` SALTABA la
    // composición de TODO texto (salvo el "clear") y los NOMBRES DE HABILIDADES desaparecían en todas
    // partes tras GUARDAR (volvían al recargar partida, que sí resetea esta categoría). Igual que en
    // `hh_do_load_game`/`hh_close_load_game`.
    hh::menu_overlay::set_file_select_active(false);
    hh::log("[save] salir de la capsula (secuencia nativa)\n");
}

// Control de TODO el flujo de guardado (fases en hh::menu::SavePhase):
//   Ask         -> "Save play data?" Yes/No; Yes -> lista; No -> ConfirmExit.
//   Select      -> "Select location..." + slots (arriba/abajo con repeat; A elige).
//   ConfirmHere -> "Saving current play data here." Yes/No; Yes guarda (serializa globals); No ->
//                  ConfirmExit.
//   ConfirmExit -> "Exit without saving?" Yes/No; Yes sale de la capsula; No vuelve a Select.
//   ConfirmDelete -> "Remove play data?" Yes/No (X/H en un slot); Yes borra -> Removed; No -> Select.
//   Completed   -> "Save completed." + flecha; A cierra y sale de la capsula.
//   Removed     -> "Remove completed." + flecha; A vuelve a Select (NO sale de la capsula).
static bool feed_save_flow(uint8_t* rdram, recomp_context* ctx, uint32_t obj) {
    auto rh16 = [&](uint32_t a) -> uint16_t {
        return *reinterpret_cast<uint16_t*>(&rdram[(a ^ 2u) & 0x7FFFFFu]);
    };
    const uint32_t btn = rh16(0x80089476u) | rh16(0x8008947Eu);
    static uint32_t prev = 0;
    const uint32_t pressed = btn & ~prev;
    prev = btn;
    const bool sfx = hh::overlay::enabled();
    constexpr uint32_t kUp = 0x800u, kDown = 0x400u;
    const uint32_t dir = btn & (kUp | kDown);
    const hh::menu::SavePhase phase = hh::menu::save_phase();
    // Bindings REALES de ACEPTAR (guardar) y AGACHARSE (borrar): se consultan en vivo para leer sus
    // botones/teclas actuales (remapeables). En headless el mando no existe, pero la tecla si.
    const bool del_btn = hh_input_button_down("z");   // agacharse = boton X del mando / tecla H
    const bool acc_btn = hh_input_button_down("a");   // aceptar  = boton A del mando / tecla J

    // Prompts Yes/No (Ask / ConfirmHere / ConfirmExit / ConfirmDelete): arriba/abajo alterna,
    // A confirma la resaltada.
    if (phase == hh::menu::SavePhase::Ask || phase == hh::menu::SavePhase::ConfirmHere ||
        phase == hh::menu::SavePhase::ConfirmExit || phase == hh::menu::SavePhase::ConfirmDelete) {
        if (pressed & (kUp | kDown)) {
            hh::menu::set_save_yes_selected(!hh::menu::save_yes_selected());
            if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Move);
        }
        if (pressed & (0x8000u | 0x1000u)) {   // A o Start/Enter
            const bool yes = hh::menu::save_yes_selected();
            if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
            // DIAGNOSTICO (HH_SAVE_TRACE=1): por que prompt se pulso A y a que fase se pasa.
            if (env_set("HH_SAVE_TRACE")) {
                hh::log("[save-flow] A phase=%d yes=%d -> ...\n", static_cast<int>(phase), yes ? 1 : 0);
            }
            if (phase == hh::menu::SavePhase::Ask) {
                if (yes) {
                    hh::menu::set_save_phase(hh::menu::SavePhase::Select);
                } else {
                    hh::menu::set_save_yes_selected(true);
                    hh::menu::set_save_phase(hh::menu::SavePhase::ConfirmExit);
                }
            } else if (phase == hh::menu::SavePhase::ConfirmHere) {
                if (yes) {
                    int slot = hh::menu::save_target_slot();
                    if (slot < 0) slot = hh::save::first_free_game_slot();   // NEW GAME
                    hh::log("[save] GUARDAR slot %d (serializa globals vivos)\n", slot);
                    hh_time_trace(rdram, "save");
                    if (hh::save::save_live(slot, rdram, ctx)) {
                        hh::menu::set_save_phase(hh::menu::SavePhase::Completed);
                    }
                } else {
                    hh::menu::set_save_yes_selected(true);
                    hh::menu::set_save_phase(hh::menu::SavePhase::ConfirmExit);
                }
            } else if (phase == hh::menu::SavePhase::ConfirmDelete) {
                if (yes) {
                    const int dslot = hh::menu::save_target_slot();
                    if (dslot >= 0) {
                        hh::log("[save] BORRAR slot %d\n", dslot);
                        hh::save::delete_slot(dslot);
                        hh::save::flush();
                    }
                    hh::menu::set_save_yes_selected(true);
                    hh::menu::refresh_load_game();
                    hh::menu::set_save_phase(hh::menu::SavePhase::Removed);
                } else {
                    hh::menu::set_save_phase(hh::menu::SavePhase::Select);
                }
            } else {   // ConfirmExit
                if (yes) {
                    hh_leave_capsule(rdram, ctx, obj);
                    return true;
                } else {
                    hh::menu::set_save_phase(hh::menu::SavePhase::Select);
                }
            }
        }
        return false;
    }
    // Completed: cualquier A cierra el mensaje y sale de la capsula. Removed: vuelve a Select (NO sale).
    if (phase == hh::menu::SavePhase::Completed || phase == hh::menu::SavePhase::Removed) {
        if (pressed & (0x8000u | 0x1000u)) {   // A o Start/Enter
            if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
            if (phase == hh::menu::SavePhase::Removed) {
                hh::menu::set_save_phase(hh::menu::SavePhase::Select);
            } else {
                hh_leave_capsule(rdram, ctx, obj);
                return true;
            }
        }
        return false;
    }

    // Select: si acabamos de entrar (bloqueo de ~120 ms), se ignora el input de la transicion.
    if (hh::menu::save_input_blocked()) {
        return false;
    }
    // Select: arriba/abajo mueven el cursor de slots (con el mismo repeat que feed_menu_navigation).
    bool fire_up = false, fire_down = false;
    {
        static uint32_t held = 0;
        static double dir_next = 0.0;
        static int dir_repeats = 0;
        static bool emitted = false;
        const double t = std::chrono::duration<double>(
                             std::chrono::steady_clock::now().time_since_epoch()).count();
        if (dir == 0) {
            held = 0;
            dir_repeats = 0;
            emitted = false;
        } else if (dir != held) {
            held = dir;
            dir_next = t + 0.40;
            dir_repeats = 0;
            emitted = false;
        } else if (t >= dir_next) {
            dir_repeats++;
            dir_next = t + std::max(0.03, 0.10 - 0.006 * dir_repeats);
            emitted = false;
        } else {
            emitted = true;
        }
        if (!emitted) {
            if (dir & kUp) fire_up = true;
            else if (dir & kDown) fire_down = true;
        }
    }
    if (fire_up || fire_down) {
        const hh::menu::Event ev = fire_up ? hh::menu::move_up() : hh::menu::move_down();
        if (ev != hh::menu::Event::None && sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Move);
    }
    // A (aceptar) SIEMPRE guarda; X (agacharse) BORRA solo si la fila es un slot con datos (no
    // `NEW GAME`). Los bindings se leen en vivo (remapeables). En headless solo hay teclado.
    if (acc_btn || (pressed & (0x8000u | 0x1000u))) {   // A o Start/Enter
        if (env_set("HH_SAVE_TRACE")) {
            hh::log("[save-flow] A/Start en Select -> ConfirmHere (acc_btn=%d pressed=%d)\n", acc_btn ? 1 : 0,
                    (pressed & (0x8000u | 0x1000u)) ? 1 : 0);
        }
        if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            hh::menu::set_save_target_slot(cur.index);   // -1 = NEW GAME
            hh::menu::set_save_yes_selected(true);
            hh::menu::set_save_phase(hh::menu::SavePhase::ConfirmHere);
        }
    } else if (del_btn) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            if (cur.index >= 0 && hh::save::slot_present(cur.index)) {   // solo slots con datos
                if (sfx) hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
                hh::menu::set_save_target_slot(cur.index);   // slot a borrar (fase ConfirmDelete)
                hh::menu::set_save_yes_selected(true);
                hh::menu::set_save_phase(hh::menu::SavePhase::ConfirmDelete);
            }
        }
    }
    return false;
}

extern "C" void hh_save_menu_hook(uint8_t* rdram, recomp_context* ctx) {
    hh::overlay::set_screen_blackout(false);
    // Objeto del menu (a0): lo necesita la transicion de salida (func_800058DC).
    const uint32_t obj = static_cast<uint32_t>(ctx->r4);
    // Pantalla activa = SaveGame (copia de LoadGame; `rebuild_load_game` la rellena con la lista).
    hh::menu::open_save_game();
    // Categoria FILE-SELECT activa: F8 (`g_native_visible`) oculta/muestra el DATA SAVE nativo.
    hh::menu_overlay::set_file_select_active(true);
    // F8 -> al re-MOSTRAR el nativo, recomponer el titulo `DATA SAVE` (se compone una sola vez; mientras
    // el nativo esta oculto, `file_select_text_skip()` salta el compositor).
    if (hh::menu_overlay::native_toggle_pending()) {
        recomp_context t = *ctx;
        func_80142778_103AF48(rdram, &t);
    }
    // Control propio + ANULACION del input nativo (el file-select lee A/Z/Start en `0x80089478`). Se
    // deja a 0 TODO el frame (no solo alrededor del update) porque el prompt `Save play data?` lo
    // maneja otra funcion de `file_008` que tambien lee esa direccion: asi el nativo NO puede avanzar
    // (no selecciona su Yes ni dispara el aviso de Controller Pak). El poll de input lo reescribe el
    // frame siguiente.
    const bool controlling = hh::overlay::enabled();
    if (controlling) {
        *reinterpret_cast<uint16_t*>(&rdram[(kFileSelectInputAddr ^ 2u) & 0x7FFFFFu]) = 0;
    }
    // Control propio de TODO el flujo de guardado (fases SavePhase). Si ya salimos de la capsula
    // (secuencia nativa disparada), NO se corre el update nativo ni se publica el overlay.
    const bool exited = feed_save_flow(rdram, ctx, obj);
    if (exited) {
        g_inject_native_a = false;
        return;
    }
    // Con el nativo OCULTO, vacia cada frame sus 0x1C ranuras de texto: el prompt `Save play data?` se
    // compone por una via distinta al compositor que saltamos, asi que hay que limpiarlo aqui (si no,
    // queda pegado por detras de nuestra UI). `func_80142570` compone cadenas VACIAS en cada ranura.
    if (controlling && !hh::menu_overlay::native_visible()) {
        recomp_context ct = *ctx;
        func_80142570_103AD40(rdram, &ct);
    }
    // Update del juego (dibuja su UI, oculta por la categoria; ya no ve input). Si la salida de la
    // capsula dispara una transicion (goto), NO se publica el overlay (evita parpadear el prompt).
    const uint32_t goto_before = g_goto_count.load(std::memory_order_relaxed);
    func_803771A4_13007B4(rdram, ctx);
    g_inject_native_a = false;
    const uint32_t goto_after = g_goto_count.load(std::memory_order_relaxed);
    if (goto_after == goto_before) {
        hh::menu_overlay::title_update(rdram);
    }
}

// Cajas del file-select: `func_8001A804` (residente) dibuja las cajas de muchos menús. Mientras la
// categoría FILE-SELECT está activa y el nativo oculto (`suppress_box_draw()`), se SALTA el original
// (no se dibujan las cajas nativas del DATA LOAD). En cualquier otro caso, se delega.
extern "C" void hh_box_draw_hook(uint8_t* rdram, recomp_context* ctx) {
    if (hh::menu_overlay::suppress_box_draw()) {
        return;
    }
    func_8001A804_1B404(rdram, ctx);
}

// Mensaje del Controller Pak: `func_800179B0` (residente) inicializa y dibuja el aviso
// "Please connect Controller Pak… / Do not remove…" (`D_8004CC90`) con `func_8001A804` (cajas) y
// `func_8001B204` (texto). Con la categoría FILE-SELECT activa y el nativo oculto se SALTA entero:
// así no compone ni dibuja ese mensaje (se colaba en la transición a CARGAR, medido 2026-10-01).
// En el GUARDADO se evitaba dejando el input a 0; aquí lo cortamos de raíz.
extern "C" void hh_pak_message_hook(uint8_t* rdram, recomp_context* ctx) {
    if (hh::menu_overlay::suppress_box_draw()) {
        return;
    }
    func_800179B0_185B0(rdram, ctx);
}

// DESACOPLO VIBRACIÓN <-> CONTROLLER PAK (2026-10-02).
// `func_80002BE0` (residente) es el clasificador de accesorio: llama a `osPfsInitPak` (Controller
// Pak), `osMotorInit` (Rumble Pak) y `osGbpakInit`, y DA PRIORIDAD al Rumble Pak: si `osMotorInit`
// tiene éxito devuelve 7. Como el port reporta `RumblePak` para que la vibración funcione
// (`get_connected_device_info`), con `CONTROLES -> VIBRACIÓN = SÍ` el juego devuelve 7 y cree que NO
// hay Controller Pak -> no guarda ni carga (aunque el PFS sea virtual).
//
// El Rumble no depende de este retorno: se arma por su propia vía (`func_80002A94` llama a
// `osMotorInit` y marca la tabla `0x80037780`, que `func_80002B44` consulta para el motor). Por eso:
//   1) ejecutamos el ORIGINAL -> deja el motor inicializado (`OSPfs::status |= PFS_MOTOR_INITIALIZED`)
//      y corre las ramas PFS/GB normales;
//   2) si la vibración está activa y el resultado fue 7 (Rumble Pak), forzamos 0 ("Controller Pak
//      OK", el valor que da en vanilla con la vibración apagada).
// Así memoria y vibración coexisten sin tocar el runtime, el enum `Pak` ni el PFS.
extern "C" void hh_pak_detect_hook(uint8_t* rdram, recomp_context* ctx) {
    func_80002BE0_37E0(rdram, ctx);
    const int ret = ctx->r2 & 0xFF;
    const bool vib = hh::input_vibration_enabled();
    if (vib && ret == 7) {
        ctx->r2 = 0;
    }
    if (env_set("HH_PAK_TRACE")) {
        hh::log("[vib] func_80002BE0 ch=%u vib=%d ret=%d -> %d\n", (unsigned)(ctx->r4 & 0xFF),
                vib ? 1 : 0, ret, (int)(ctx->r2 & 0xFF));
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

// DIAGNOSTICO: si `g_font_all_countdown > 0`, hh_font_trace_bfe4 registra TODOS los códigos de glifo
// (sin dedup) durante esa ventana. Sirve para volcar la secuencia exacta del título del Área.
extern "C" int g_font_all_countdown = 0;

extern "C" void hh_font_trace_bfe4(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned code = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    if (g_font_all_countdown > 0) {
        --g_font_all_countdown;
        hh::log("[fontall] color=%u code=%04X\n", color, code);
    }
    if (env_set("HH_FONT_LOWER") && code >= 1 && code <= 36) {
        static unsigned n = 0;
        if (n < 4000) {
            ++n;
            hh::log("[fontlower] color=%u code=%04X t=%ld\n", color, code, g_hook_frame);
        }
    }
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
    // Cualquier cambio de pantalla cierra la "sesión" de guardado: así, al volver a entrar en la
    // cápsula, el flujo se reinicia en `Ask` (no se queda la última fase). No-op si no estaba abierta.
    hh::menu::close_save_game();
    // Ídem para CARGAR: al volver a entrar en CONTINUAR el flujo se reinicia en `Browse`.
    // EXCEPCIÓN: durante la transición de entrada (`g_load_enter`) NO se cierra la sesión: los gotos
    // internos del setup/update del file-select (`0x801C3D50`, `0x801C3D84`) no deben reiniciarla.
    if (!g_load_enter) {
        hh::menu::close_load_game();
    }
    const uint32_t target = static_cast<uint32_t>(ctx->r5);
    // Título del Área: `func_801C4074` es la transición de escena. El nombre nativo PERSISTE durante
    // la carga de escena (que sigue en negro); se mantiene el overlay tapándolo hasta ~HH_TITLE_HOLD_MS
    // después de la transición (cuando ya arranca el gameplay) y entonces se retira.
    const long long now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                 std::chrono::steady_clock::now().time_since_epoch())
                                 .count();
    // Cuánto se mantiene el overlay del título tras arrancar la transición de escena (`func_801C4074`).
    // El original ya no recompone el título: lo tapa/arrastra su transición. Tunable `HH_TITLE_TRANS_MS`
    // (antes 900 ms fijos; el mantenedor lo notó largo). 0 = retirarlo al arrancar la transición.
    static const long long kTitleTransHoldMs = [] {
        const char* e = std::getenv("HH_TITLE_TRANS_MS");
        return (e != nullptr && *e != '\0') ? std::atoll(e) : 400LL;
    }();
    if (target == 0x801C4074u) {
        g_area_title_in_transition = true;
        g_area_title_trans_ms = now_ms;
    } else if (g_area_title_active && g_area_title_in_transition &&
               (now_ms - g_area_title_trans_ms) > kTitleTransHoldMs) {
        g_area_title_active = false;
        g_area_title_in_transition = false;
        // Fade-out final (funde fondo+texto a negro y luego oculta). Mantiene el candado hasta que
        // termina; `hh::menu_overlay::tick` lo suelta. Antes se ocultaba de golpe (`hide_now`).
        static const int kTitleFadeoutMs = [] {
            const char* e = std::getenv("HH_TITLE_FADEOUT_MS");
            return (e != nullptr && *e != '\0') ? std::atoi(e) : 1000;
        }();
        hh::menu_overlay::begin_area_title_fadeout(kTitleFadeoutMs);
    }
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
    // Traza de combate: registra el cambio de pantalla con su CALLER (ra) para localizar la
    // bifurcacion que decide la sorpresa. Ver `battle_trace_active`/`hh_battle_frame_hook`.
    if (battle_trace_active()) {
        hh::log("[battle] goto target=%08X obj=%08X ra=%08X\n", target,
                static_cast<uint32_t>(ctx->r4), static_cast<uint32_t>(ctx->r31));
    }
    // A2: cambio de pantalla -> oculta el overlay al instante (el handler nativo puede seguir
    // publicando el frame de la raíz durante la transición; ver menu_overlay::hide_now).
    // EXCEPCIÓN: durante la transición de entrada a CARGAR (`g_load_enter`) NO se oculta: ya estamos
    // publicando NUESTRA UI de carga y los gotos internos del file-select la ocultarían un frame
    // (parpadeo). El título no republica la raíz en esos frames (ver hh_title_menu_hook).
    // EXCEPCIÓN: mientras el título del Área está activo (overlay traducido) NO se oculta: el nombre
    // nativo persiste durante la transición y hay que seguir tapándolo (lo retira el bloque de arriba).
    if (!g_load_enter && !g_area_title_active) {
        hh::menu_overlay::hide_now();
    }
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
        // Placeholder de tabla vacia (MSVC no admite arrays de tamaño 0): ram_addr==0 se ignora.
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
