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

extern "C" void func_8000469C_529C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80004838_5438(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_801C1DB8_11BB888(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_801C18FC_11BB3CC(uint8_t* rdram, recomp_context* ctx);
extern "C" void hh_title_ctor_hook(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001B204_1BE04(uint8_t* rdram, recomp_context* ctx);  // compone texto de menú
extern "C" void hh_entry_register_hook(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800058DC_64DC(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001BFE4_1CBE4(uint8_t* rdram, recomp_context* ctx);  // carga bitmap de glifo
extern "C" void func_8001D394_1DF94(uint8_t* rdram, recomp_context* ctx);  // código EUC -> slot
extern "C" void func_801C1340_11BAE10(uint8_t* rdram, recomp_context* ctx);  // lee botones (direcciones)
extern "C" void func_801C1334_11BAE04(uint8_t* rdram, recomp_context* ctx);  // lee botones (A/START)
extern "C" void hh_pc_menu_register();  // src/hooks/hh_menu.cpp
extern "C" void hh_accent_register();   // src/hooks/text_glyphs.cpp
extern "C" void load_overlay_by_id(uint32_t id, uint32_t ram_addr);
extern "C" void unload_overlay_by_id(uint32_t id);
extern "C" void hh_title_menu_hook(uint8_t* rdram, recomp_context* ctx);  // definido abajo

namespace {

constexpr uint32_t kFileLoadAddress = 0x8000469C;          // file_load(id, dest)
constexpr uint32_t kFileLoadStreamedAddress = 0x80004838;  // streamed(id, dest), pieza a pieza
constexpr size_t kFileCount = sizeof(hh::kCodeFiles) / sizeof(hh::kCodeFiles[0]);

// A2 (paso 5, control total): con nuestro overlay como UI del menú de título, el handler NATIVO se
// sigue ejecutando (mantiene el estado del juego) pero con su input NEUTRALIZADO: las dos funciones
// con las que lee los botones devuelven 0, así su cursor/pantalla no se mueven y no compiten con
// nuestra navegación. La bandera solo está activa durante esa llamada (ver hh_title_menu_hook).
bool g_mute_native_input = false;

extern "C" void hh_native_dir_input(uint8_t* rdram, recomp_context* ctx) {
    if (g_mute_native_input) {
        ctx->r2 = 0;
        return;
    }
    func_801C1340_11BAE10(rdram, ctx);
}

extern "C" void hh_native_ab_input(uint8_t* rdram, recomp_context* ctx) {
    if (g_mute_native_input) {
        ctx->r2 = 0;
        return;
    }
    func_801C1334_11BAE04(rdram, ctx);
}

// Overlay A2: (re)registra el handler del menú de título. El loader de un módulo reescribe func_map
// y borra los overrides de su rango, así que hay que re-aplicarlo tras cada carga (además del
// registro inicial en register_runtime_functions).
void register_title_menu_hook() {
    recomp::overlays::add_loaded_function(0x801C1DB8, hh_title_menu_hook);
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

// A2 (paso 5, control total): alimenta NUESTRO menú con el input del juego (los mismos botones que
// lee el handler nativo, que queda muteado). Arriba/abajo mueven el cursor; izq/der cambian el valor
// de un selector lateral; A marca/selecciona (entra en submenús) y B atrás. Los cambios son en vivo
// (sin X/"aplicar"); las ACCIONES llegan en el paso 6 (de momento, solo DEBUG engancha el modo
// desarrollador). La raíz no tiene "atrás" (el modelo lo ignora).
static void feed_menu_navigation(uint8_t* rdram, recomp_context* ctx) {
    recomp_context td = *ctx;
    func_801C1340_11BAE10(rdram, &td);   // direcciones
    recomp_context ta = *ctx;
    func_801C1334_11BAE04(rdram, &ta);   // A/B/START
    const uint32_t btn = static_cast<uint32_t>(td.r2) | static_cast<uint32_t>(ta.r2);
    static uint32_t prev = 0;
    const uint32_t pressed = btn & ~prev;   // flanco de pulsación (el juego repite al mantener)
    prev = btn;
    hh::menu::Event ev = hh::menu::Event::None;
    if (pressed & 0x800u) ev = hh::menu::move_up();
    if (pressed & 0x400u) ev = hh::menu::move_down();
    if (pressed & 0x200u) ev = hh::menu::move_left();
    if (pressed & 0x100u) ev = hh::menu::move_right();
    if (pressed & 0x8000u) ev = hh::menu::confirm();   // A: entra / marca
    if (pressed & 0x4000u) ev = hh::menu::back();      // B: atrás. (Sin X: los cambios son en vivo.)
    // Selectores con acción (DEBUG -> modo desarrollador de RT64, Inspector con F1). Solo al cambiar
    // el valor (izq/der) o al confirmar con A, no al pasar el cursor por encima.
    if (ev != hh::menu::Event::None && (pressed & (0x100u | 0x200u | 0x8000u))) {
        const hh::menu::Screen& s = hh::menu::current_screen();
        if (s.cursor >= 0 && s.cursor < static_cast<int>(s.entries.size())) {
            const hh::menu::Entry& cur = s.entries[s.cursor];
            if (cur.action == hh::menu::Action::ToggleDebug) {
                hh::set_developer_mode(cur.value != 0);
            }
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
    static const bool trace = env_set("HH_MENU_TRACE");
    static uint64_t calls = 0;
    if (trace && (calls++ % 30) == 0) {
        auto guest_byte = [&](uint32_t addr) -> unsigned {
            return rdram[(addr - 0x80000000u) ^ 3u];
        };
        hh::log("[menu] a0=%08X a1=%08X sel=%u g1=%u g2=%u\n",
                static_cast<uint32_t>(ctx->r4), static_cast<uint32_t>(ctx->r5),
                guest_byte(0x801CC8C4u), guest_byte(0x801BBD54u), guest_byte(0x801CC8A8u));
    }
    // ¿El handler nativo cambió de pantalla este frame? (p. ej. al seleccionar una opción). En ese
    // caso NO publicamos el frame del overlay (seguiría mostrando la raíz durante la transición).
    bool screen_changed = false;
    // SFX del menú por CAMBIO REAL (no por pulsación de botón):
    //   - cursor movido (selección 0x801CC8C4 cambia) -> move
    //   - pantalla cambiada (goto) -> accept/back según el botón que lo provocó
    // Así no suena si el botón no hace nada (p. ej. arriba en la primera entrada, o B sin "atrás").
    {
        auto guest_byte = [&](uint32_t addr) -> unsigned {
            return rdram[(addr - 0x80000000u) ^ 3u];
        };
        const uint32_t goto_before = g_goto_count.load(std::memory_order_relaxed);
        const uint32_t sel_before = guest_byte(0x801CC8C4u);

        // A2 (paso 5, terreno): mueve nuestro cursor con el input del juego.
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
            // 0, abandona el menú (goto 0x801C2050). Con el input muteado nunca se reinicia, así que
            // lo mantenemos a tope (antes y después de la llamada) mientras NUESTRO menú tiene el
            // control; si no, la pantalla se cerraría sola a los ~8-30 s. El valor 0x384 es el que
            // usa el propio handler al resetear.
            MEM_H(0x3C, obj) = 0x384;
        }
        g_mute_native_input = controlling;
        func_801C1DB8_11BB888(rdram, ctx);  // comportamiento original con input neutralizado
        g_mute_native_input = false;
        if (controlling) {
            MEM_H(0x3C, obj) = 0x384;
        }
        const uint32_t goto_after = g_goto_count.load(std::memory_order_relaxed);
        const uint32_t sel_after = guest_byte(0x801CC8C4u);
        screen_changed = (goto_after != goto_before);

        if (sel_after != sel_before) {
            hh::menu_sfx::play(hh::menu_sfx::Sfx::Move);
        } else if (screen_changed) {
            recomp_context ta = *ctx;
            func_801C1334_11BAE04(rdram, &ta);   // A/START
            recomp_context td = *ctx;
            func_801C1340_11BAE10(rdram, &td);   // direcciones
            const uint32_t btn = static_cast<uint32_t>(ta.r2) | static_cast<uint32_t>(td.r2);
            if (env_set("HH_MENU_TRACE")) {
                hh::log("[sfx] pantalla cambiada: btn=0x%04X\n", btn);
            }
            if (btn & 0xB000u) {
                hh::menu_sfx::play(hh::menu_sfx::Sfx::Accept);
            } else if (btn & 0x4000u) {
                hh::menu_sfx::play(hh::menu_sfx::Sfx::Back);
            }
        }
    }
    // Si la pantalla cambió (salimos de la raíz), no publicamos: `hide_now` ya la ocultó y el
    // siguiente frame lo decidirá el nuevo handler. Si seguimos en la raíz, publicamos normal.
    if (!screen_changed) {
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
    static unsigned seen_key[1024];
    static size_t seen = 0;
    const unsigned key = (color << 16) | code;
    bool dup = false;
    for (size_t i = 0; i < seen; ++i) {
        if (seen_key[i] == key) {
            dup = true;
            break;
        }
    }
    if (!dup && seen < 1024) {
        seen_key[seen++] = key;
        hh::log("[font] bfe4 color=%u code=%04X slot=%u stride=%u fileidx=%u\n", color, code,
                code >> 1, stride, fileidx);
    }
    func_8001BFE4_1CBE4(rdram, ctx);
}

// A2: contador de transiciones de pantalla (func_800058DC); definido arriba (antes del handler).

extern "C" void hh_goto_hook(uint8_t* rdram, recomp_context* ctx) {
    g_goto_count.fetch_add(1, std::memory_order_relaxed);
    if (env_set("HH_MENU_TRACE")) {
        hh::log("[menu] goto pantalla=%08X (obj=%08X)\n", static_cast<uint32_t>(ctx->r5),
                static_cast<uint32_t>(ctx->r4));
    }
    // A2: cambio de pantalla -> oculta el overlay al instante (el handler nativo puede seguir
    // publicando el frame de la raíz durante la transición; ver menu_overlay::hide_now).
    hh::menu_overlay::hide_now();
    func_800058DC_64DC(rdram, ctx);
}

// A2: la entrada SOUND (inutil en PC) pasa a ser AJUSTES; dentro viven IDIOMA y SONIDO.
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
    // A2: SOUND -> AJUSTES (pantalla propia con IDIOMA y SONIDO).
    // hh_pc_menu_register();  // DESACTIVADO: reemplazado por overlay propio
    std::fprintf(stderr, "[hh] %zu code files; loaders envueltos en 0x%08X y 0x%08X\n",
                 kFileCount, kFileLoadAddress, kFileLoadStreamedAddress);
    std::fflush(stderr);
}
