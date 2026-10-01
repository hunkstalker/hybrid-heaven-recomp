// hh_menu — modelo del menú inicial del port (A2, paso 1: SOLO ESTADO).
//
// Implementa el árbol y la navegación descritos en include/hh/menu.h y RETOMAR.md §Menú. No dibuja,
// no lee input y no persiste: es una máquina de estados pura y testeable.

#include "hh/menu.h"

#include <algorithm>
#include <atomic>
#include <cctype>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <set>
#include <sstream>

#include "hh.h"   // VideoConfig/AudioConfig: valores iniciales de los selectores
#include "hh/save_edit.h"  // EDICIÓN DE PARTIDA

namespace hh::menu {
namespace {

std::vector<Screen> g_screens;      // todas las pantallas (el estado vive aquí y se conserva)
std::vector<ScreenId> g_stack;      // camino activo; el tope es la pantalla visible
Layout g_layout;

// EXTRAS: se muestra si se ha desbloqueado en esta sesion con el codigo Konami, o si hay algun
// ajuste de EXTRAS persistido distinto del valor por defecto (asi el menu no se pierde tras
// configurarlo). Al volver a los valores por defecto deja de estar persistido -> oculto al arrancar.
bool g_extras_unlocked_state = false;

// Endónimos de la lista IDIOMA: SIEMPRE en su propia lengua (no dependen del idioma activo; por eso
// viven en código y NO en assets/lang). Clave = nombre interno (en español, solo como identificador);
// valor = endónimo a mostrar. Uppercase (la fuente del menú no tiene minúsculas acentuadas: à/ñ/ç).
// JA en kana (ニホンゴ): color0 no tiene kanji (日本語 sería imposible), pero la kana sí (ver jp_kana.h).
struct Endonym { const char* es; const char* shown; };
const Endonym kEndonyms[] = {
    {"INGLÉS", "ENGLISH"},  {"ESPAÑOL", "ESPAÑOL"}, {"CATALÁN", "CATALÀ"},
    {"FRANCÉS", "FRANÇAIS"}, {"ALEMÁN", "DEUTSCH"}, {"JAPONÉS", "ニホンゴ"},
};

Entry make_item(const char* label, Action action, bool enabled = true) {
    Entry e;
    e.label = label;
    e.enabled = enabled;
    e.kind = Kind::Item;
    e.action = action;
    return e;
}

Entry make_submenu(const char* label, Action action, bool enabled = true) {
    Entry e = make_item(label, action, enabled);
    e.kind = Kind::Submenu;
    return e;
}

Entry make_selector(const char* label, std::vector<std::string> options, int value = 0,
                    bool enabled = true, bool stepper = false) {
    Entry e;
    e.label = label;
    e.enabled = enabled;
    e.kind = Kind::Selector;
    e.options = std::move(options);
    // Acota el valor al rango de opciones: un indice fuera de rango (p. ej. por un target mal puesto)
    // leia fuera de `options` y podia colgar el juego.
    e.value = (value >= 0 && value < static_cast<int>(e.options.size())) ? value : 0;
    e.stepper = stepper;   // fuerza el estilo < valor > (chevrons) aunque quepan todas las opciones
    return e;
}

// Selector con acción (p. ej. DEBUG -> ToggleDebug): el valor cambia con izq/der y el enganche lee
// `action` para aplicar el efecto (ver feed_menu_navigation).
Entry make_selector_with_action(const char* label, std::vector<std::string> options, Action action,
                                int value = 0, bool stepper = false) {
    Entry e = make_selector(label, std::move(options), value, true, stepper);
    e.action = action;
    return e;
}

// Valores iniciales de GRÁFICOS desde config.ini [video] (persistidos por las acciones del menú).
int fullscreen_default() { return hh::video_config().wm == "windowed" ? 0 : 1; }
int vsync_default() { return hh::video_config().vsync == "no" ? 0 : 1; }
int fps_limit_default() {
    const std::string& f = hh::video_config().fps;
    if (f.empty() || f == "nativo" || f == "native") return 0;
    switch (std::atoi(f.c_str())) {
        case 30:  return 1;
        case 40:  return 2;
        case 60:  return 3;
        case 75:  return 4;
        case 90:  return 5;
        case 120: return 6;
        case 144: return 7;
        case 165: return 8;
        case 240: return 9;
        default:  return 0;
    }
}
int show_fps_default() { return hh::video_config().showfps == "si" ? 1 : 0; }
int developer_default() { return hh::video_config().developer == "si" ? 1 : 0; }
// VOLUMEN: indice 0..10 (pasos de 10 %) según `[audio].volumen`.
int volume_default() { return std::clamp((hh::audio_config().volume + 5) / 10, 0, 10); }
// SALIDA: 0 MONO, 1 ESTÉREO, 2 AURICULARES según `[audio].salida` (orden MONO/ESTÉREO/AURICULARES).
int output_default() {
    const std::string& o = hh::audio_config().output;
    if (o == "mono") return 0;
    if (o == "auriculares" || o == "headphones" || o == "crossfeed") return 2;
    return 1;  // estereo (default)
}
int menu_sfx_default() { return hh::audio_config().menusfx == "no" ? 0 : 1; }
// CONTROLES -> VIBRACIÓN: Rumble Pak / vibración del mando (persiste en config.ini [input]).
int vibration_default() { return hh::input_vibration_enabled() ? 1 : 0; }
// EXTRAS -> LOGOS ORIGINALES: SÍ (1) = clasicos de fondo blanco; NO (0) = modernos de fondo negro.
int original_logos_default() { return hh::extras_config().original_logos == "si" ? 1 : 0; }
// EXTRAS -> MANTENER EXTRAS: SÍ (1) = el menu EXTRAS persiste entre arranques; NO (0) = solo tras
// teclear el codigo Konami.
int extras_persist_default() { return hh::extras_config().persist == "si" ? 1 : 0; }
// EXTRAS -> MODO HEAVEN: SÍ (1) = modo global activo (ATRIBUTOS/ESTADO máx + invulnerabilidad +
// items no consumibles). Persiste en config.ini [extras].heaven.
int heaven_default() { return hh::extras_config().heaven == "si" ? 1 : 0; }

// EXTRAS -> VENTAJA: SÍ (1) = ventaja de combate ("back attack") siempre, sin activar MODO HEAVEN.
// Persiste en config.ini [extras].advantage.
int advantage_default() { return hh::extras_config().advantage == "si" ? 1 : 0; }

// EXTRAS -> PODER ∞ / RESIS. ∞: SÍ (1) = el gauge correspondiente no se gasta (al max cada frame).
// Persisten en config.ini [extras].infinite_power / [extras].infinite_stamina.
int infinite_power_default() { return hh::extras_config().infinite_power == "si" ? 1 : 0; }
int infinite_stamina_default() { return hh::extras_config().infinite_stamina == "si" ? 1 : 0; }
// RATIO: índice en {"AUTO","ORIGINAL","4:3","16:9","16:10","21:9"} según `[video].aspect`.
int ratio_default() {
    const std::string a = hh::video_config().aspect;
    if (a == "original") return 1;
    if (a == "4:3") return 2;
    if (a == "16:9") return 3;
    if (a == "16:10") return 4;
    if (a == "21:9") return 5;
    return 0;  // auto / expand
}
// ANTIALIASING: x0/x2/x4/x8 según `[video].msaa`.
int msaa_default() {
    const std::string& m = hh::video_config().msaa;
    if (m == "off" || m == "none" || m == "0") return 0;
    if (m == "2x") return 1;
    if (m == "4x") return 2;
    return 3;  // 8x (default)
}

// Fila de mapeado (CONTROLES): etiqueta de la accion N64 + su binding actual a la derecha.
// `action_key` es el nombre de la accion (mismos que config.ini [game]: a,b,z,start,l,r,dup,...).
Entry make_binding(const char* label, const char* action_key) {
    Entry e;
    e.label = label;
    e.kind = Kind::Binding;
    e.binding = hh::pad_binding_desc(action_key);
    e.remap_key = action_key;
    return e;
}

Entry make_option(const char* label, bool marked = false) {
    Entry e;
    e.label = label;
    e.kind = Kind::Option;
    e.marked = marked;
    return e;
}

Screen make_screen(ScreenId id, ScreenKind kind, std::vector<Entry> entries) {
    Screen s;
    s.id = id;
    s.kind = kind;
    s.entries = std::move(entries);
    return s;
}

// Fila numérica (< valor >) y fila toggle (marca propia NO/SÍ) del editor de partida.
Entry make_number(const char* label, int min, int max, int value, int index, Action action) {
    Entry e;
    e.label = label;
    e.kind = Kind::Number;
    e.value = value;
    e.min = min;
    e.max = max;
    e.step = 1;
    e.index = index;
    e.action = action;
    return e;
}
Entry make_toggle(const char* label, bool marked, int index, Action action) {
    Entry e;
    e.label = label;
    e.kind = Kind::Toggle;
    e.marked = marked;
    e.index = index;
    e.action = action;
    return e;
}

// --- EDICIÓN DE PARTIDA: estado del editor y utilidades -------------------------------------------
int g_edit_slot = 0;        // 0..3
int g_edit_body_state = 0;  // ESTADO (nivel de parte): 0 OFENSIVO, 1 DEFENSIVO
int g_edit_tech_bulk = 0;   // HABILIDADES: 0 SIN CAMBIOS, 1 TODO SÍ, 2 TODO NO
int g_edit_save_target = 0; // GUARDAR: 0 = NUEVA PARTIDA (primer hueco libre), 1..4 = slot
int g_edit_delete_target = 1; // ELIMINAR: 1..4 = slot a borrar (valor del selector)
// Copia de las técnicas tal como estaban al CARGAR (para "SIN CAMBIOS").
uint8_t g_tech_baseline[hh::save::kTechCount];
bool g_tech_baseline_valid = false;

// Areas-Partes REALES del juego. `[MEDIDO 2026-09-29]`. El valor de escena (que el editor escribe en
// el slot en `0x564`, u16 LE) es `(area-1)*10 + (sub-1)*2` para los PUNTOS DE GUARDADO (1-1 -> 0,
// 1-2 -> 2, 2-1 -> 10). Los `N-0` (1-0, 2-0) son INICIOS de nivel: NO guardables (un slot nunca los
// registra; se llega a ellos por transicion `tipo=15`), pero SI destinos del warp `IR A NIVEL`, con
// `idx = (area-1)*10`. Ver notes/2026-09-29-editor-area-parte-plan.md.
struct AreaPart { int area; int sub; };   // area 1-based; sub 0 = inicio (N-0), 1.. = punto guardado
// Puntos de guardado (sub >= 1): los unicos que un slot puede registrar (selector PROGRESO).
static const AreaPart kAreaPartsSave[] = {
    {1, 1}, {1, 2},
    {2, 1},
    {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
    {4, 1}, {4, 2}, {4, 3},
    {5, 1}, {5, 2},
    {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7},
    {7, 1}, {7, 2}, {7, 3},
    {8, 1}, {8, 2}, {8, 3},
    {9, 1},
};
// `IR A NIVEL` (EXTRAS): SOLO los `N-0` (inicio de cada nivel), con su índice de escena MEDIDO
// (no todos siguen `(area-1)*10`: 7-0 = 75). Ver notes/2026-09-29-editor-area-parte-plan.md.
struct NamedPoint { const char* label; uint16_t idx; };
static const NamedPoint kStartPoints[] = {
    { "1-0", 0 }, { "2-0", 10 }, { "3-0", 20 }, { "4-0", 30 }, { "5-0", 40 },
    { "6-0", 50 }, { "7-0", 75 }, { "8-0", 80 }, { "9-0", 90 },
};
// Valor de escena para un destino de guardado: `(area-1)*10 + (sub-1)*2` (sub >= 1).
static uint16_t area_part_value(int area, int sub) {
    if (sub <= 0) return static_cast<uint16_t>((area - 1) * 10);
    return static_cast<uint16_t>((area - 1) * 10 + (sub - 1) * 2);
}
static std::vector<AreaPart> area_parts_save() {
    return std::vector<AreaPart>(std::begin(kAreaPartsSave), std::end(kAreaPartsSave));
}

std::vector<std::string> progress_options() {
    std::vector<std::string> out;
    for (const AreaPart& ap : area_parts_save()) {
        out.push_back(std::to_string(ap.area) + "-" + std::to_string(ap.sub));
    }
    if (out.empty()) out.push_back("1-1");
    return out;
}
int progress_index_of(uint16_t value) {
    const std::vector<AreaPart> aps = area_parts_save();
    for (int i = 0; i < static_cast<int>(aps.size()); ++i) {
        if (value == area_part_value(aps[i].area, aps[i].sub)) return i;
    }
    return 0;
}
// Valor del slot (`0x564`) del indice `slot` del selector PROGRESO.
uint16_t progress_value_at(int slot) {
    const std::vector<AreaPart> aps = area_parts_save();
    if (slot < 0 || slot >= static_cast<int>(aps.size())) return area_part_value(1, 1);   // 1-1
    return area_part_value(aps[slot].area, aps[slot].sub);
}
// Cadena "N-P" (area-punto de guardado). El valor guardado es `(area-1)*10+(sub-1)*2`, asi que NO se
// puede derivar por division; se busca en la lista. La fuente no tiene '-': el overlay dibuja el guion.
std::string progress_label(uint16_t value) {
    for (const AreaPart& ap : area_parts_save()) {
        if (value == area_part_value(ap.area, ap.sub)) {
            return std::to_string(ap.area) + "-" + std::to_string(ap.sub);
        }
    }
    return std::to_string(value / 10) + "-" + std::to_string(value % 10);
}

// IR A NIVEL (EXTRAS): SOLO los `N-0` (inicio de cada nivel), con su índice medido.
std::vector<std::string> warp_options() {
    std::vector<std::string> out;
    for (const NamedPoint& p : kStartPoints) out.push_back(p.label);
    return out;
}

// Orden de las partes como las muestra el port (mapa al orden del juego en el struct):
// CABEZA, CUERPO, BRAZO IZQ, BRAZO DER, PIERNA IZQ, PIERNA DER.
const int kPartIndex[6] = {0, 1, 3, 2, 5, 4};
const char* const kPartLabels[6] = {"HEAD", "BODY", "LEFT ARM", "RIGHT ARM", "LEFT LEG",
                                    "RIGHT LEG"};

void rebuild_save_edit();   // definida tras find_screen

// Resoluciones (sin AUTO/ORIGINAL) adecuadas a cada RATIO: AUTO/ORIGINAL(4:3)/4X3/16X9/16X10/21X9.
std::vector<std::string> ratio_resolutions(int ratio) {
    switch (ratio) {
        case 3:   // 16X9
            return {"1280x720", "1366x768", "1600x900", "1920x1080", "2560x1440", "3840x2160"};
        case 4:   // 16X10
            return {"1280x800", "1440x900", "1680x1050", "1920x1200", "2560x1600"};
        case 5:   // 21X9
            return {"2560x1080", "3440x1440", "3840x1600"};
        case 1:   // ORIGINAL (4:3 nativo)
        case 2:   // 4X3
            return {"640x480", "800x600", "1024x768", "1280x960", "1600x1200", "2048x1536"};
        default:  // AUTO: sin filtro -> unión
            return {"640x480", "800x600", "1024x768", "1280x960", "1600x1200", "2048x1536",
                    "1280x720", "1366x768", "1600x900", "1920x1080", "2560x1440", "3840x2160",
                    "1280x800", "1440x900", "1680x1050", "1920x1200", "2560x1600",
                    "2560x1080", "3440x1440", "3840x1600"};
    }
}

// Ajusta las opciones/valor de RESOLUCIÓN según el RATIO: AUTO -> AUTO, ORIGINAL -> ORIGINAL, y los
// ratios concretos dejan AUTO. Definida tras `find_screen`.
void sync_resolution();

// Rellena la pantalla CARGAR PARTIDA (definida tras rebuild_save_edit; build_tree la llama antes).
void rebuild_load_game();

// Rellena g_screens con el árbol acordado (orden de arriba a abajo).
void build_tree() {
    g_screens.clear();

    std::vector<Entry> root = {
        make_item("CONTINUE", Action::Continue),
        make_submenu("NEW GAME", Action::OpenNewGame),
        make_submenu("BATTLE MODE", Action::BattleMode),
        make_submenu("SETTINGS", Action::OpenSettings),
    };
    // EXTRAS: solo aparece si se ha desbloqueado con el codigo Konami (arriba de SALIR).
    if (extras_unlocked()) {
        root.push_back(make_submenu("EXTRAS", Action::OpenExtras));
    }
    // SALIR: extra del port (no existe en el nativo); cierra de forma ordenada. Decidido por el
    // mantenedor (2026-09-25); ver docs/menu.md.
    root.push_back(make_item("EXIT", Action::Exit));
    g_screens.push_back(make_screen(ScreenId::Root, ScreenKind::Menu, std::move(root)));

    // NUEVA PARTIDA: iniciar la partida y elegir dificultad.
    // CÁMARA LIBRE / APUNTADO LIBRE: OCULTOS (2026-09-27) hasta que el juego los soporte (requieren
    // modificar el juego); por ahora no se muestran. La maquinaria de entradas deshabilitadas
    // (`make_selector(..., enabled=false)` + el salto de `!enabled` en move_up/move_down) se conserva
    // por si se deshabilitan otras entradas en el futuro.
    g_screens.push_back(make_screen(ScreenId::NewGame, ScreenKind::Menu, {
        make_item("START GAME", Action::StartGame),
        make_submenu("DIFFICULTY", Action::OpenDifficulty),
    }));

    // DIFICULTAD: lista (A marca la aplicada; el resto sale en gris). La opción marcada es el valor
    // en memoria; vendrá de la config en el paso 6.
    g_screens.push_back(make_screen(ScreenId::Difficulty, ScreenKind::List, {
        make_option("ULTIMATE"),
        make_option("HARD"),
        make_option("NORMAL", /*marked=*/true),
    }));

    // MODO COMBATE: subpantalla recreada con nuestro menu (mismos rotulos que el original),
    // traduccida a todos los idiomas. El despacho nativo de cada entrada se cablea en el hook del
    // submenu de batalla (0x801C4200); ver docs/menu.md y notes/2026-09-27-battle-mode-recon.md.
    g_screens.push_back(make_screen(ScreenId::BattleMode, ScreenKind::Menu, {
        make_item("VS MODE", Action::BattleModeVs),
        make_item("CREATURE BATTLE", Action::BattleModeCreature),
        make_item("DATA EDIT", Action::BattleModeDataEdit),
    }));

    // COMBATE DE CRIATURAS: subpantalla interna (el original: 5 MATCHES / SURVIVAL, cursor 0x801CC8C8
    // en func_801C44C4). Se entra desde MODO COMBATE (nativo, cursor 1) y se sale con B (va a la raiz).
    g_screens.push_back(make_screen(ScreenId::BattleCreature, ScreenKind::Menu, {
        make_item("5 MATCHES", Action::BattleCreatureMatches),
        make_item("SURVIVAL", Action::BattleCreatureSurvival),
    }));

    // CONFIGURACIÓN: IDIOMA / GRÁFICOS / SONIDO y DEBUG al final (submenú con las opciones de depuración).
    g_screens.push_back(make_screen(ScreenId::Settings, ScreenKind::Menu, {
        make_submenu("LANGUAGE", Action::OpenLanguage),
        make_submenu("GRAPHICS", Action::OpenGraphics),
        make_submenu("SOUND", Action::OpenSound),
        make_submenu("CONTROLS", Action::OpenControls),
    }));

    // IDIOMA: lista (INGLÉS...JAPONÉS). La opción activa es el idioma actual (negrita/verde).
    {
        Screen lang = make_screen(ScreenId::Language, ScreenKind::List, {
            make_option("INGLÉS"), make_option("ESPAÑOL"), make_option("CATALÁN"),
            make_option("FRANCÉS"), make_option("ALEMÁN"), make_option("JAPONÉS"),
        });
        static const char* kCodes[] = { "en", "es", "ca", "fr", "de", "ja" };
        const std::string cur = hh::text_current_language();
        for (size_t i = 0; i < lang.entries.size() && i < 6; ++i) {
            lang.entries[i].marked = (cur == kCodes[i]);
        }
        g_screens.push_back(std::move(lang));
    }

    // GRÁFICOS: RATIO filtra las resoluciones de RESOLUCIÓN (ambos con AUTO/ORIGINAL). El paso 6
    // aplicará los valores a RT64. Por defecto RATIO=AUTO y RESOLUCIÓN=AUTO.
    g_screens.push_back(make_screen(ScreenId::Graphics, ScreenKind::Menu, {
        make_selector_with_action("RATIO", {"AUTO", "ORIGINAL", "4:3", "16:9", "16:10", "21:9"},
                                  Action::RatioSelect, ratio_default()),
        make_selector_with_action("RESOLUTION", {"AUTO", "ORIGINAL"}, Action::ResolutionSelect),
        // Los tres siguientes persisten en config.ini [video] y aplican en vivo (ver
        // feed_menu_navigation). El valor inicial sale de la config (default: borderless/SÍ/NATIVO).
        make_selector_with_action("FULLSCREEN", {"NO", "YES"}, Action::ToggleFullscreen,
                                  fullscreen_default()),
        // stepper=true: mostrar como < x2 > (solo el activo, con chevrons) en vez de x0/x2/x4/x8.
        make_selector_with_action("ANTIALIASING", {"x0", "x2", "x4", "x8"}, Action::MsaaSelect,
                                  msaa_default(), true),
        make_selector_with_action("VSYNC", {"NO", "YES"}, Action::ToggleVsync, vsync_default()),
        // NATIVO = refresco del monitor; un número = tasa fija (RT64 refreshRate). Orden ascendente;
        // incluye 40 (Steam Deck), 90 (Deck/VR) y 75 (monitores antiguos). Se recorta al monitor.
        make_selector_with_action("FPS LIMIT",
                                  {"NATIVE", "30", "40", "60", "75", "90", "120", "144", "165", "240"},
                                  Action::FpsLimit, fps_limit_default()),
        // Indicador de FPS del overlay; persiste en config.ini [video].showfps.
        make_selector_with_action("SHOW FPS", {"NO", "YES"}, Action::ToggleShowFps,
                                  show_fps_default()),
    }));

    // DEBUG: vacío por ahora (VENTANA DEBUG -> EXTRAS como DEBUG PANEL; MOSTRAR FPS -> GRÁFICOS).
    g_screens.push_back(make_screen(ScreenId::Debug, ScreenKind::Menu, {}));

    // EXTRAS: desbloqueado con el codigo Konami. MANTENER EXTRAS decide si el propio menu persiste
    // entre arranques; LOGOS ORIGINALES elige el set de logos de la intro por defecto. Ambos
    // persisten en config.ini [extras].
    g_screens.push_back(make_screen(ScreenId::Extras, ScreenKind::Menu, {
        // MODO HEAVEN: modo GLOBAL (no depende de la partida ni del editor). Al poner SÍ persiste y,
        // al cargar/empezar cualquier partida, se aplica al personaje vivo ATRIBUTOS/ESTADO al máx +
        // las 86 habilidades, y en runtime invulnerabilidad + items no consumibles (ver RETOMAR.md).
        make_selector_with_action("MODO HEAVEN", {"NO", "YES"}, Action::ToggleHeavenMode,
                                  heaven_default()),
        make_submenu("SAVE EDIT", Action::OpenSaveEdit),
        // DEBUG NIVELES: activa los atajos del CICLO DE PUNTOS (F5/F6, RePag/AvPag) + indicador
        // `idx=`, y da acceso a ELEGIR NIVEL. Persiste en config.ini [extras].debug_levels.
        make_selector_with_action("DEBUG LEVELS", {"NO", "YES"}, Action::ToggleDebugLevels,
                                  hh::extras_config().debug_levels == "si" ? 1 : 0),
        make_submenu("GO TO AREA", Action::OpenChooseLevel),
        // PODER ∞ / RESIS. ∞: el gauge de combate no se gasta (se pinnea a max por frame). El ∞ se
        // dibuja como simbolo vectorial (la fuente no lo trae). Persisten en config.ini [extras].
        make_selector_with_action("POWER ∞", {"NO", "YES"}, Action::ToggleInfinitePower,
                                  infinite_power_default()),
        make_selector_with_action("STAMINA ∞", {"NO", "YES"}, Action::ToggleInfiniteStamina,
                                  infinite_stamina_default()),
        // SIEMPRE EN VENTAJA (antes VENTAJA): independiente de MODO HEAVEN (permite la ventaja de
        // combate sola). Persiste en config.ini [extras].advantage.
        make_selector_with_action("ALWAYS ADVANTAGE", {"NO", "YES"}, Action::ToggleAdvantage,
                                  advantage_default()),
        make_selector_with_action("KEEP EXTRAS", {"NO", "YES"}, Action::ToggleExtrasPersist,
                                  extras_persist_default()),
        make_selector_with_action("ORIGINAL LOGOS", {"NO", "YES"}, Action::ToggleOriginalLogos,
                                  original_logos_default()),
        // DEBUG PANEL (antes VENTANA DEBUG, en el submenú DEBUG): habilita el Inspector de RT64 (F1).
        make_selector_with_action("DEBUG PANEL", {"NO", "YES"}, Action::ToggleDebug,
                                  developer_default()),
    }));

    // CONTROLES: Stick C + tabla del mapeado (accion N64 -> binding actual de mando/teclado). La
    // lista es larga; el overlay la hace scrollear cuando no cabe en pantalla.
    g_screens.push_back(make_screen(ScreenId::Controls, ScreenKind::Menu, {
        // MOVIMIENTO: direccion del stick y/o tecla (por defecto W/S/A/D).
        make_binding("UP/FORWARD", "axis_up"),
        make_binding("DOWN/BACK", "axis_down"),
        make_binding("LEFT", "axis_left"),
        make_binding("RIGHT", "axis_right"),
        // Etiquetas = ACCION del juego (no el boton N64); a la derecha, MANDO y TECLADO.
        make_binding("ACTION/ACCEPT", "a"),
        make_binding("MAP/BACK", "b"),
        make_binding("CROUCH", "z"),
        make_binding("FIRST PERSON", "cdown"),
        make_binding("MENU", "start"),
        make_binding("AIM", "r"),
        // C: solo C-arriba (altura de camara); C-abajo = PRIMERA PERSONA; C-izq/der no hacen nada.
        make_binding("CAMERA HEIGHT", "cup"),
        make_binding("MENU UP", "dup"),
        make_binding("MENU DOWN", "ddown"),
        make_binding("MENU LEFT", "dleft"),
        make_binding("MENU RIGHT", "dright"),
        // VIBRACIÓN (encima de RESET) y RESET (abajo del todo).
        make_selector_with_action("VIBRATION", {"NO", "YES"}, Action::ToggleVibration,
                                  vibration_default()),
        make_item("RESET", Action::ResetControls),
    }));

    sync_resolution();

    // RESOLUCIÓN: fijar el valor persistido ([video].res) si está entre las opciones del ratio.
    {
        const std::string want = hh::video_config().res;
        for (Screen& s : g_screens) {
            if (s.id != ScreenId::Graphics) continue;
            for (Entry& e : s.entries) {
                if (e.action != Action::ResolutionSelect) continue;
                for (size_t i = 0; i < e.options.size(); ++i) {
                    if (e.options[i] == want) { e.value = static_cast<int>(i); break; }
                }
            }
        }
    }

    // SONIDO: VOLUMEN general (0-100 % en pasos de 10) y SALIDA (ESTÉREO/MONO/AURICULARES). Antes
    // era la lista vanilla ESTÉREO/MONO; ahora es un menu de selectores. Ambos persisten en [audio].
    g_screens.push_back(make_screen(ScreenId::Sound, ScreenKind::Menu, {
        make_selector_with_action("VOLUME",
                                  {"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%",
                                   "90%", "100%"},
                                  Action::VolumeSelect, volume_default()),
        make_selector_with_action("OUTPUT", {"MONO", "STEREO", "HEADPHONES"}, Action::OutputSelect,
                                  output_default()),
        make_selector_with_action("MENU SFX", {"NO", "YES"}, Action::MenuSfxToggle,
                                  menu_sfx_default()),
    }));

    // EDICIÓN DE PARTIDA: pantallas propias (se rellenan en rebuild_save_edit con el .pak cargado y
    // los nombres de la ROM). Vacías aquí; el contenido depende del slot seleccionado.
    g_screens.push_back(make_screen(ScreenId::SaveEdit, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditAbilities, ScreenKind::Toggle, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditBody, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditItems, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditStats, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditCombatSim, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::ChooseLevel, ScreenKind::Menu, {}));
    // CARGAR PARTIDA (menú propio de carga): lista de las 45 partidas del `.pak`. Se rellena en
    // rebuild_load_game con los metadatos del trailer. Ver notes/...fase2-ui.md.
    g_screens.push_back(make_screen(ScreenId::LoadGame, ScreenKind::Menu, {}));
    // GUARDAR PARTIDA (copia 1:1 de la UI de cargar; se dibuja encima del DATA SAVE nativo). El
    // rebuild de carga rellena también esta pantalla con la misma lista. Ver open_save_game().
    g_screens.push_back(make_screen(ScreenId::SaveGame, ScreenKind::Menu, {}));
    rebuild_save_edit();
    rebuild_load_game();
}

Screen* find_screen(ScreenId id) {
    for (Screen& s : g_screens) {
        if (s.id == id) {
            return &s;
        }
    }
    return nullptr;
}

// Reconstruye las pantallas del editor con los valores ACTUALES de los globals (la partida cargada).
// Se llama al construir el árbol, al cambiar PARTIDA/ESTADO y tras GUARDAR (lo demás se refleja en el
// propio modelo). Cargar un slot en los globals lo hace `hh::save::load(slot)` (en las acciones).
void rebuild_save_edit() {
    hh::save::load();
    const int slot = g_edit_slot;

    if (Screen* s = find_screen(ScreenId::SaveEdit)) {
        std::vector<Entry> e;
        // CARGAR PARTIDA: selector < PARTIDA N >; al cambiar de valor se carga ese slot en los
        // globals (rápido: leer 0xD00 del PFS cacheado + deserializar; no arranca escena).
        // GUARDAR PARTIDA: selector < NUEVA PARTIDA / PARTIDA N >; NUEVA PARTIDA guarda en el primer
        // slot libre (al final de los usados). A ejecuta el guardado. Un hueco separa del resto.
        std::vector<std::string> slots;
        for (int i = 1; i <= hh::save::kSlots; ++i) slots.push_back("PARTIDA " + std::to_string(i));
        e.push_back(make_selector_with_action("CARGAR", slots, Action::SaveEditSlot, slot));
        std::vector<std::string> save_slots{"NEW GAME"};
        for (int i = 1; i <= hh::save::kSlots; ++i) save_slots.push_back("PARTIDA " + std::to_string(i));
        e.push_back(make_selector_with_action("SAVE", save_slots, Action::SaveEditSave,
                                              g_edit_save_target));
        // ELIMINAR: mismo selector de partidas; A borra el slot elegido (persiste al instante).
        // `g_edit_delete_target` es 1-based; el `value` del selector es el indice 0-based -> -1.
        e.push_back(make_selector_with_action("ELIMINAR", slots, Action::SaveEditDelete,
                                              g_edit_delete_target - 1));
        // RESTAURAR: backup del slot tal como estaba al abrir el `.pak` (estado vanilla). Descarta
        // TODOS los cambios en memoria de este slot. No escribe: hay que GUARDAR después.
        e.push_back(make_item("RESTAURAR", Action::SaveEditRestore));
        e.push_back(make_item("", Action::None));   // hueco visual (fila vacía)
        // PROGRESO: lista de N-P válidos; el guion lo dibuja el overlay (la fuente no tiene '-').
        e.push_back(make_selector_with_action("PROGRESS", progress_options(),
                                              Action::SaveEditProgress,
                                              progress_index_of(hh::save::progress_of(slot))));
        // NIVEL GLOBAL: DERIVADO de los niveles de las 6 partes (func_8037865C = media redondeada
        // +1). NO se puede editar: subirlo a mano no cambia ninguna stat (ver docs/stats-partes.md).
        // Solo lectura (cursor-able, sin acción).
        const int lvl = hh::save::global_level_of(slot);
        const std::string lvl_label = "NIVEL " + std::to_string(lvl >= 1 ? lvl : 1);
        e.push_back(make_item(lvl_label.c_str(), Action::None, /*enabled=*/true));
        e.push_back(make_submenu("ATRIBUTOS", Action::OpenSaveEditCombatSim));
        e.push_back(make_submenu("STATE", Action::OpenSaveEditBody));   // antes "BODY"
        e.push_back(make_submenu("ABILITIES", Action::OpenSaveEditAbilities));
        e.push_back(make_submenu("ITEMS", Action::OpenSaveEditItems));
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    // ELEGIR NIVEL (EXTRAS): controlar la partida (CARGAR/GUARDAR/ELIMINAR) + IR A NIVEL. IR A NIVEL
    // solo se habilita con partida cargada (gris y cursor no se posa si no la hay).
    if (Screen* s = find_screen(ScreenId::ChooseLevel)) {
        std::vector<Entry> e;
        std::vector<std::string> slots;
        for (int i = 1; i <= hh::save::kSlots; ++i) slots.push_back("PARTIDA " + std::to_string(i));
        e.push_back(make_selector_with_action("CARGAR", slots, Action::SaveEditSlot, slot));
        std::vector<std::string> save_slots{"NEW GAME"};
        for (int i = 1; i <= hh::save::kSlots; ++i) save_slots.push_back("PARTIDA " + std::to_string(i));
        e.push_back(make_selector_with_action("SAVE", save_slots, Action::SaveEditSave,
                                              g_edit_save_target));
        e.push_back(make_selector_with_action("ELIMINAR", slots, Action::SaveEditDelete,
                                              g_edit_delete_target - 1));
        e.push_back(make_item("", Action::None));   // separacion
        // IR A NIVEL: destino = Area-Parte (con inicios N-0). Con A se inyecta la transicion. Si no
        // hay partida cargada, el port carga la plantilla base de forma transparente y luego warpea.
        e.push_back(make_selector_with_action("AREA", warp_options(), Action::WarpToLevel, 0));
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditAbilities)) {
        std::vector<Entry> e;
        // Cabecera: selector lateral < RESET / TODO SÍ / TODO NO > (accion masiva sobre la lista;
        // RESET restaura las habilidades a como estaban al entrar, sin guardar).
        e.push_back(make_selector_with_action("ABILITIES", {"RESET", "TODO SÍ", "TODO NO"},
                                              Action::SaveEditAbilitiesBulk, g_edit_tech_bulk));
        e.push_back(make_item("", Action::None));   // hueco visual
        for (int id = 0; id < hh::save::kTechCount; ++id) {
            e.push_back(make_toggle(hh::save::tech_name(id).c_str(), hh::save::tech_learned_of(slot, id), id,
                                    Action::None));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditBody)) {
        std::vector<Entry> e;
        // ESTADO del cuerpo: SOLO los niveles de parte (OFENSIVO/DEFENSIVO), con `< NIVEL n >`. Fuera
        // HIT/DAMAGE (contadores de uso sin efecto util) y NIVEL/PROGRESO (son de ATRIBUTO, ya en
        // ATRIBUTOS). Los niveles de parte no tienen tabla: se editan en crudo.
        e.push_back(make_selector_with_action(
            "TIPO", {"OFFENSIVE", "DEFENSIVE"}, Action::SaveEditBodyState, g_edit_body_state));
        // TODOS: fija las 6 partes del eje activo al nivel elegido (0..99). El valor mostrado es el
        // nivel actual más alto; izq/der lo cambian y aplican a las 6.
        int maxp = 0;
        for (int i = 0; i < 6; ++i)
            maxp = std::max(maxp, static_cast<int>(hh::save::body_stat_of(slot, kPartIndex[i],
                                                                         g_edit_body_state)));
        Entry all = make_number("TODOS", 0, 99, maxp, -1, Action::SaveEditBodyBulk);
        all.prefix = "NIVEL ";
        e.push_back(std::move(all));
        for (int i = 0; i < 6; ++i) {
            const int part = kPartIndex[i];
            Entry n = make_number(kPartLabels[i], 0, 99,
                                  hh::save::body_stat_of(slot, part, g_edit_body_state), part,
                                  Action::SaveEditBodyValue);
            n.prefix = "NIVEL ";
            e.push_back(std::move(n));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditItems)) {
        std::vector<Entry> e;
        for (int id = 0; id < hh::save::kItemCount; ++id) {
            // El nombre se muestra en orden natural (S,M,L,X...); la cantidad vive en el slot de su
            // familia invertido (item_slot_of): el juego guarda S↔X, M↔L.
            const int slot_id = hh::save::item_slot_of(id);
            std::string nm = hh::save::item_name(id);   // el juego los guarda "Mayús Inicial"; a MAYÚS
            for (char& ch : nm) ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            e.push_back(make_number(nm.c_str(), 0, 99,
                                    hh::save::item_count_of(slot, slot_id), slot_id,
                                    Action::SaveEditItem));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditCombatSim)) {
        // ATRIBUTOS: cabecera NIVEL global (derivado, solo lectura); TODOS (nudge relativo ±1 a los 6
        // atributos, se resetea a 0); y una fila por atributo con `< NIVEL n >` editable (izq/der
        // aplican la tabla real, stat += incremento[nivel]) + el valor del stat (sin EXP).
        std::vector<Entry> e;
        const int gl = hh::save::global_level_of(slot);
        e.push_back(make_item(("NIVEL " + std::to_string(gl >= 1 ? gl : 1)).c_str(), Action::None,
                              /*enabled=*/true));
        e.push_back(make_item("", Action::None));   // hueco visual
        // TODOS: fija TODOS los atributos al nivel elegido (0..99). El valor mostrado es el nivel
        // actual más alto; izq/der lo cambian y aplican a los 6.
        {
            int maxl = 0;
            for (int p = 0; p < hh::save::kParts; ++p)
                maxl = std::max(maxl, static_cast<int>(hh::save::part_level_of(slot, p)));
            Entry all = make_number("TODOS", 0, hh::save::kPartLevelMax, maxl, -1,
                                    Action::SaveEditAttrBulk);
            all.prefix = "NIVEL ";
            e.push_back(std::move(all));
        }
        auto padl = [](const std::string& s, size_t n) {
            return std::string(n > s.size() ? n - s.size() : 0, ' ') + s;
        };
        struct Attr { const char* label; int part; int gstat; };
        static const Attr kAttrs[] = {
            {"HP", 0, hh::save::gHpMax},            {"RESISTENCIA", 1, hh::save::gStamina},
            {"OFENSA", 2, hh::save::gOffense},      {"DEFENSA", 3, hh::save::gDefense},
            {"REFLEJOS", 4, hh::save::gReflex},     {"VELOCIDAD", 5, hh::save::gSpeed},
        };
        for (const Attr& a : kAttrs) {
            Entry n = make_number(a.label, 0, hh::save::kPartLevelMax,
                                  hh::save::part_level_of(slot, a.part), a.part,
                                  Action::SaveEditAttrLevel);
            n.prefix = "NIVEL ";
            // Valor del stat, rellenado a la izquierda: el overlay lo dibuja en columna FIJA -> los
            // dígitos quedan alineados aunque el stat tenga 1/2/3/4 cifras.
            n.suffix = padl(std::to_string(hh::save::global_stat_of(slot, a.gstat)), 5);
            e.push_back(std::move(n));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }
}

// --- CARGAR PARTIDA (menú propio de carga; Fase 2) -----------------------------------------------
// Texto de cada fila de la lista, con el mismo contenido que el DATA LOAD nativo:
//   "ÁREA N-P   NIVEL <n>   TIEMPO M:SS"
// Mantenemos el texto PRE-FORMATEADO (lo dibuja el overlay tal cual) para poder alinearlo 1:1 sin que
// el overlay tenga que conocer el formato. `load_game_row_text` también sirve de diagnóstico.
std::vector<std::string> g_load_game_rows;

std::string format_time(uint16_t t) {
    // El nativo muestra "M:SS"; el tiempo guardado es un u16 (segundos).
    const unsigned m = t / 60u, s = t % 60u;
    char buf[16];
    std::snprintf(buf, sizeof(buf), "%u:%02u", m, s);
    return buf;
}

void rebuild_load_game() {
    if (!hh::save::loaded()) {
        hh::save::load();
    }
    g_load_game_rows.clear();
    g_load_game_rows.reserve(hh::save::game_slot_count());
    for (int i = 0; i < hh::save::game_slot_count(); ++i) {
        std::string row;
        if (hh::save::slot_present(i)) {
            const unsigned an = hh::save::meta_area_n(i);
            const unsigned ap = hh::save::meta_area_p(i);
            const unsigned lv = hh::save::meta_level(i);
            // Tres líneas separadas por '\n'; cada línea es `ETIQUETA\tVALOR` (el overlay alinea el
            // VALOR a la DERECHA, como el nativo). Rotulos NATIVOS en ingles (AREA/LEVEL/TIME), NO
            // traducidos: el DATA LOAD/SAVE original del ROM US los muestra asi.
            row = std::string("AREA\t") + std::to_string(an) + "-" + std::to_string(ap) + "\n" +
                  "LEVEL\t" + std::to_string(lv) + "\n" +
                  "TIME\t" + format_time(hh::save::meta_time(i));
        } else {
            row = hh::menu::localized("NO DATA");
        }
        g_load_game_rows.push_back(std::move(row));
    }
    // CARGAR: las 45 partidas (las vacias salen "NO DATA").
    if (Screen* s = find_screen(ScreenId::LoadGame)) {
        std::vector<Entry> e;
        for (int i = 0; i < static_cast<int>(g_load_game_rows.size()); ++i) {
            Entry it = make_item(g_load_game_rows[i].c_str(), Action::LoadGamePick,
                                 hh::save::slot_present(i));
            it.index = i;
            e.push_back(std::move(it));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
        for (int i = 0; i < static_cast<int>(s->entries.size()); ++i) {
            if (s->entries[i].enabled) { s->cursor = i; break; }
        }
    }
    // GUARDAR: primera opcion "NEW GAME" (guarda en el siguiente slot libre) + SOLO los slots CON
    // DATOS. Todos seleccionables (el cursor no salta ninguno).
    if (Screen* s = find_screen(ScreenId::SaveGame)) {
        const int keep = s->cursor;
        std::vector<Entry> e;
        {
            Entry it = make_item(localized("NEW GAME").c_str(), Action::SaveGameNew,
                                 /*enabled=*/true);
            it.index = -1;
            e.push_back(std::move(it));
        }
        for (int i = 0; i < static_cast<int>(g_load_game_rows.size()); ++i) {
            if (!hh::save::slot_present(i)) continue;
            // GUARDAR (a diferencia de CARGAR): A sobre una partida con datos la sobrescribe.
            Entry it = make_item(g_load_game_rows[i].c_str(), Action::SaveGamePick, /*enabled=*/true);
            it.index = i;
            e.push_back(std::move(it));
        }
        s->entries = std::move(e);
        s->cursor = (keep >= 0 && keep < static_cast<int>(s->entries.size())) ? keep : 0;
    }
}

const char* load_game_row_text(int index) {
    if (index < 0 || index >= static_cast<int>(g_load_game_rows.size())) return nullptr;
    return g_load_game_rows[index].c_str();
}

// Ajusta las opciones/valor de RESOLUCIÓN al RATIO: AUTO -> AUTO, ORIGINAL -> ORIGINAL, y los ratios
// concretos dejan las resoluciones de ese ratio con AUTO seleccionado.
void sync_resolution() {
    Screen* g = find_screen(ScreenId::Graphics);
    if (g == nullptr) {
        return;
    }
    Entry* ratio = nullptr;
    Entry* res = nullptr;
    for (Entry& e : g->entries) {
        if (e.action == Action::RatioSelect) {
            ratio = &e;
        }
        else if (e.action == Action::ResolutionSelect) {
            res = &e;
        }
    }
    if (ratio == nullptr || res == nullptr) {
        return;
    }
    std::vector<std::string> opts = {"AUTO", "ORIGINAL"};
    for (const std::string& v : ratio_resolutions(ratio->value)) {
        opts.push_back(v);
    }
    res->options = std::move(opts);
    // ORIGINAL -> ORIGINAL; AUTO -> AUTO; ratio concreto -> la resolución MÍNIMA de su lista (índice 2).
    res->value = (ratio->value == 1) ? 1 : (ratio->value == 0 ? 0 : 2);
}

Screen* top() {
    if (g_stack.empty()) {
        return nullptr;
    }
    return find_screen(g_stack.back());
}

// Índice de la entrada HABILITADA siguiente (dir=+1) o anterior (dir=-1) al cursor `from`,
// envolviendo. Salta las entradas `!enabled` (p. ej. CÁMARA/APUNTADO LIBRE). Devuelve -1 si no hay
// ninguna habilitada (guarda). Si solo hay una habilitada y es la actual, devuelve esa misma.
int step_enabled(const Screen& s, int from, int dir) {
    const int n = static_cast<int>(s.entries.size());
    if (n == 0) {
        return -1;
    }
    int i = from;
    for (int k = 0; k < n; ++k) {
        i += dir;
        if (i < 0) i = n - 1;
        if (i >= n) i = 0;
        const Entry& e = s.entries[i];
        if (e.enabled && !e.label.empty()) {   // salta deshabilitadas y filas-hueco (label vacío)
            return i;
        }
    }
    return -1;
}

void ensure() {
    if (g_screens.empty()) {
        reset();
    }
}

bool screen_for(Action action, ScreenId& out) {
    switch (action) {
        case Action::OpenNewGame:    out = ScreenId::NewGame;    return true;
        case Action::OpenDifficulty: out = ScreenId::Difficulty; return true;
        case Action::OpenSettings:   out = ScreenId::Settings;   return true;
        case Action::OpenLanguage:   out = ScreenId::Language;   return true;
        case Action::OpenGraphics:   out = ScreenId::Graphics;   return true;
        case Action::OpenSound:      out = ScreenId::Sound;      return true;
        case Action::OpenDebug:      out = ScreenId::Debug;      return true;
        case Action::OpenExtras:     out = ScreenId::Extras;     return true;
        case Action::OpenChooseLevel: out = ScreenId::ChooseLevel; return true;
        case Action::OpenControls:   out = ScreenId::Controls;   return true;
        case Action::OpenSaveEdit:          out = ScreenId::SaveEdit;          return true;
        case Action::OpenSaveEditAbilities: out = ScreenId::SaveEditAbilities; return true;
        case Action::OpenSaveEditBody:      out = ScreenId::SaveEditBody;      return true;
        case Action::OpenSaveEditItems:     out = ScreenId::SaveEditItems;     return true;
        case Action::OpenSaveEditStats:     out = ScreenId::SaveEditStats;     return true;
        case Action::OpenSaveEditCombatSim: out = ScreenId::SaveEditCombatSim; return true;
        case Action::OpenLoadGame:          out = ScreenId::LoadGame;          return true;
        case Action::BattleMode:     out = ScreenId::BattleMode; return true;
        default:                     return false;
    }
}

}  // namespace

// Reconstruye LoadGame/SaveGame desde el `.pak` (fuera del namespace anónimo: la usan los hooks).
void refresh_load_game() { rebuild_load_game(); }

// Área-Parte (N-P) de un valor de escena (misma enumeración que el selector PROGRESO). Fuera del
// namespace anónimo para exportarla (la usa `hh::save::save_live` para la cabecera del guardado).
void area_sub_from_value(uint16_t value, int& area, int& sub) {
    for (const AreaPart& ap : area_parts_save()) {
        if (value == area_part_value(ap.area, ap.sub)) {
            area = ap.area;
            sub = ap.sub;
            return;
        }
    }
    area = static_cast<int>(value / 10u) + 1;
    sub = static_cast<int>((value % 10u) / 2u) + 1;
}

void reset() {
    build_tree();
    g_stack.clear();
    g_stack.push_back(ScreenId::Root);
}

const Screen& current_screen() {
    ensure();
    const Screen* s = top();
    if (s == nullptr) {
        return g_screens.front();
    }
    return *s;
}

const Screen* screen(ScreenId id) {
    ensure();
    return find_screen(id);
}

void push(ScreenId id) {
    ensure();
    if (find_screen(id) == nullptr) {
        return;
    }
    g_stack.push_back(id);
}

// --- CARGAR PARTIDA: estado del flujo de fases (análogo al del GUARDADO) --------------------------
// La carga (CONTINUAR / DATA LOAD) es una copia estructural del guardado: `LoadPhase` con las fases
// del flujo propio. Se declara aquí (antes de open_load_game) para poder reiniciar la sesión al
// entrar. Las funciones de acceso están más abajo (junto a `localized`).
static LoadPhase g_load_phase = LoadPhase::Browse;
static bool g_load_yes = true;
static int g_load_target_slot = -1;
// Marca temporal al entrar en `Browse`/`Removed` para ignorar el input del frame de la transición.
static std::chrono::steady_clock::time_point g_load_ignore_input_tp{};
// ¿Sesión de carga activa? Se pone al abrir y se limpia en close_load_game() (al salir de CONTINUAR).
// Sirve para REINICIAR el flujo al reentrar aunque la pila siga siendo [Root, LoadGame].
static bool g_load_open = false;

// Fase 3: fija la pila a [Root, LoadGame] y refresca la lista. Idempotente. La llama el hook del
// file-select al dar CONTINUAR, para que la pantalla activa sea la nuestra.
void open_load_game() {
    ensure();
    // Ya está abierta: NO se reconstruye la lista. `rebuild_load_game()` fuerza el cursor al primer
    // slot con datos; llamarlo cada frame (el hook corre por frame) devolvía el cursor arriba tras
    // cada movimiento (bug "se mueve abajo y vuelve arriba"). La lista se refresca al (re)entrar.
    if (g_load_open && g_stack.size() == 2 && g_stack[0] == ScreenId::Root &&
        g_stack[1] == ScreenId::LoadGame) {
        return;
    }
    rebuild_load_game();
    if (!g_load_open) {
        // (Re)entrada en CONTINUAR: el flujo arranca en `Browse` (lista interactiva). Sin esto se
        // quedaría la última fase (p. ej. `Loaded`) y A solo saldría. El cursor va a la primera
        // partida con datos (rebuild_load_game ya lo coloca).
        g_load_phase = LoadPhase::Browse;
        g_load_yes = true;
        g_load_target_slot = -1;
        g_load_open = true;
    }
    g_stack.clear();
    g_stack.push_back(ScreenId::Root);
    g_stack.push_back(ScreenId::LoadGame);
}

// Al salir de CONTINUAR (transición de escena / B al título): marca la sesión como cerrada para que
// la próxima entrada reinicie el flujo en `Browse` y RETIRA la pantalla de carga de la pila. Sin el
// pop, la pila seguía siendo [Root, LoadGame]: al volver al TÍTULO, `title_update` publicaba
// `current_screen()` = LoadGame y se veía la pantalla de carga en vez del menú (bug 2026-10-01).
void close_load_game() {
    g_load_open = false;
    g_load_target_slot = -1;
    while (g_stack.size() > 1 && g_stack.back() == ScreenId::LoadGame) {
        g_stack.pop_back();
    }
}

// Fase del flujo de guardado (capsula). `g_save_yes` = opcion resaltada en el Yes/No activo.
// `g_save_target_slot` = slot de la FILA resaltada en `Select`, que la fase interpreta:
//   - ConfirmHere   -> slot a guardar (-1 = NEW GAME / siguiente libre);
//   - ConfirmDelete -> slot a borrar.
// Una sola variable basta: la fase ya distingue guardar de borrar.
// Ver open_save_game()/save_phase()/save_yes_selected().
static SavePhase g_save_phase = SavePhase::Ask;
static bool g_save_yes = true;
static int g_save_target_slot = -1;
// Marca temporal al entrar en `Select`/`Removed` para ignorar el input del frame de la transicion.
static std::chrono::steady_clock::time_point g_save_ignore_input_tp{};
// ¿Sesión de guardado activa? Se pone al abrir y se limpia en close_save_game() (al salir de la
// cápsula). Sirve para REINICIAR el flujo al reentrar aunque la pila siga siendo [Root, SaveGame].
static bool g_save_open = false;

// GUARDAR PARTIDA: fija la pila a [Root, SaveGame] (idempotente). La llama el hook de la vía de
// guardado (0x803771A4) para publicar la COPIA de la UI de cargar ENCIMA del DATA SAVE nativo. Como
// `rebuild_load_game()` rellena también SaveGame con la misma lista, aquí basta con el foco.
void open_save_game() {
    ensure();
    rebuild_load_game();
    if (!g_save_open) {
        // (Re)entrada en la cápsula: el flujo arranca en `Ask` (`Save play data?` Yes/No, slots
        // ocultos). Sin esto se quedaba la última fase (p. ej. `Completed`) y A solo salía.
        g_save_phase = SavePhase::Ask;
        g_save_yes = true;
        g_save_target_slot = -1;
        g_save_open = true;
        if (Screen* s = find_screen(ScreenId::SaveGame)) {
            s->cursor = 0;   // el cursor vuelve arriba (NEW GAME) en cada nuevo acceso
        }
    }
    if (g_stack.size() == 2 && g_stack[0] == ScreenId::Root && g_stack[1] == ScreenId::SaveGame) {
        return;   // ya está abierta
    }
    g_stack.clear();
    g_stack.push_back(ScreenId::Root);
    g_stack.push_back(ScreenId::SaveGame);
}

// Al salir de la cápsula: marca la sesión como cerrada para que la próxima entrada reinicie el flujo.
void close_save_game() { g_save_open = false; }

SavePhase save_phase() { return g_save_phase; }
void set_save_phase(SavePhase phase) {
    // Al entrar en `Select` (o `Removed`) se ignora el input de ESTE frame: la A que confirmo el
    // prompt anterior (o el `Removed`) no debe contar como seleccion de slot/guardado (si no, Select
    // pasa a ConfirmHere en el acto y el mensaje apenas se ve). Ver traza HH_SAVE_TRACE.
    if (phase == SavePhase::Select || phase == SavePhase::Removed) {
        g_save_ignore_input_tp = std::chrono::steady_clock::now();
    }
    g_save_phase = phase;
}
// true si la fase cambio hace menos de `ms` (para ignorar el input que la provoco).
bool save_input_blocked() {
    return (std::chrono::steady_clock::now() - g_save_ignore_input_tp) < std::chrono::milliseconds(120);
}
bool save_confirm() { return g_save_phase == SavePhase::Ask; }
void set_save_confirm(bool on) { set_save_phase(on ? SavePhase::Ask : SavePhase::Select); }
bool save_yes_selected() { return g_save_yes; }
void set_save_yes_selected(bool on) { g_save_yes = on; }
// Los slots aparecen en cuanto se entra en la lista (sin retardo): el retardo del nativo producia un
// frame intermedio con las cajas ocultas y el mensaje ya cambiado (parpadeo). En `Ask` no se muestran.
bool save_slots_ready() { return g_save_phase != SavePhase::Ask; }
int save_target_slot() { return g_save_target_slot; }
void set_save_target_slot(int slot) { g_save_target_slot = slot; }

int depth() {
    ensure();
    return static_cast<int>(g_stack.size());
}

const Layout& layout() {
    return g_layout;
}

// Mensaje de la fase `Select` del GUARDAR: SUSTITUYE al `Select location in which to save play data.`
// nativo insertando los bindings REALES de ACEPTAR (guardar) y AGACHARSE (eliminar): boton/tecla,
// p. ej. `A/J` y `X/H`. La CLAVE es el texto original en INGLES (con sus `\n`, entrada de
// assets/lang/*.txt); los `%s` se sustituyen DESPUES de traducir, sobre el texto traducido.
std::string save_select_message() {
    constexpr const char* kKey =
        "Select location in which to\nsave play data pressing %s or %s\nto remove.";
    const auto binding = [](const char* key) -> std::string {
        const std::string gp = hh::pad_binding_gamepad(key);
        const std::string kb = hh::pad_binding_key(key);
        if (gp == "-" || gp.empty()) return kb;
        if (kb == "-" || kb.empty() || kb == gp) return gp;
        return gp + "/" + kb;
    };
    char buf[256];
    std::snprintf(buf, sizeof(buf), localized(kKey).c_str(), binding("a").c_str(),
                  binding("z").c_str());
    return buf;
}

// --- CARGAR PARTIDA: funciones de acceso al flujo de fases (estado declarado arriba) --------------
// `Browse` = lista interactiva (A carga directo, X borra); el borrado reutiliza el patrón del guardado
// (Yes/No + `Removed`). La selección de una partida la ejecuta el handler (`hh_file_select_hook`),
// que además arranca la escena (transición nativa).
LoadPhase load_phase() { return g_load_phase; }
void set_load_phase(LoadPhase phase) {
    // Al entrar en `Browse` (o `Removed`) se ignora el input de ESTE frame: la A que confirmó el
    // prompt anterior (o el `Removed`) no debe contar como selección de slot/carga.
    if (phase == LoadPhase::Browse || phase == LoadPhase::Removed) {
        g_load_ignore_input_tp = std::chrono::steady_clock::now();
    }
    g_load_phase = phase;
}
bool load_yes_selected() { return g_load_yes; }
void set_load_yes_selected(bool on) { g_load_yes = on; }
int load_target_slot() { return g_load_target_slot; }
void set_load_target_slot(int slot) { g_load_target_slot = slot; }
bool load_input_blocked() {
    return (std::chrono::steady_clock::now() - g_load_ignore_input_tp) < std::chrono::milliseconds(120);
}
// Bindings REALES de ACEPTAR (cargar) y AGACHARSE (borrar): botón/tecla, p. ej. `A/J` y `X/H`. La
// CLAVE es el texto original en INGLES (con sus `\n`, entrada de assets/lang/*.txt); los `%s` se
// sustituyen DESPUÉS de traducir (mismo patrón que `save_select_message`).
std::string load_select_message() {
    constexpr const char* kKey =
        "Select play data to be loaded\npressing %s or %s\nto remove.";
    const auto binding = [](const char* key) -> std::string {
        const std::string gp = hh::pad_binding_gamepad(key);
        const std::string kb = hh::pad_binding_key(key);
        if (gp == "-" || gp.empty()) return kb;
        if (kb == "-" || kb.empty() || kb == gp) return gp;
        return gp + "/" + kb;
    };
    char buf[256];
    std::snprintf(buf, sizeof(buf), localized(kKey).c_str(), binding("a").c_str(),
                  binding("z").c_str());
    return buf;
}

// Traduce una CLAVE (texto original en inglés) al idioma activo. Delega en el único punto de
// traducción `hh::text::translate` (que usa la MISMA tabla que la sustitución nativa). Los endónimos
// del selector IDIOMA son la única excepción: se muestran siempre en su propia lengua (no se traducen)
// y viven en código (`kEndonyms`).
std::string localized(const std::string& label) {
    if (label.empty()) return label;
    for (const Endonym& e : kEndonyms) {
        if (label == e.es) return e.shown;
    }
    return hh::text::translate(label);
}

Event move_up() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    const int c = step_enabled(*s, s->cursor, -1);
    if (c < 0 || c == s->cursor) {
        return Event::None;
    }
    s->cursor = c;
    return Event::Move;
}

Event move_down() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    const int c = step_enabled(*s, s->cursor, +1);
    if (c < 0 || c == s->cursor) {
        return Event::None;
    }
    s->cursor = c;
    return Event::Move;
}

Event move_left() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    Entry& e = s->entries[s->cursor];
    if (e.kind == Kind::Number) {
        const int v = e.value - e.step;
        if (v < e.min || v == e.value) {
            return Event::None;
        }
        e.value = v;
        return Event::Move;
    }
    if (e.kind != Kind::Selector || e.options.empty()) {
        return Event::None;
    }
    const int n = static_cast<int>(e.options.size());
    const int v = (e.value - 1 + n) % n;
    if (v == e.value) {
        return Event::None;
    }
    e.value = v;
    if (e.action == Action::RatioSelect) {
        sync_resolution();
    }
    return Event::Move;
}

Event move_right() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    Entry& e = s->entries[s->cursor];
    if (e.kind == Kind::Number) {
        const int v = e.value + e.step;
        if (v > e.max || v == e.value) {
            return Event::None;
        }
        e.value = v;
        return Event::Move;
    }
    if (e.kind != Kind::Selector || e.options.empty()) {
        return Event::None;
    }
    const int n = static_cast<int>(e.options.size());
    const int v = (e.value + 1) % n;
    if (v == e.value) {
        return Event::None;
    }
    e.value = v;
    if (e.action == Action::RatioSelect) {
        sync_resolution();
    }
    return Event::Move;
}

Event confirm() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    Entry& e = s->entries[s->cursor];
    if (!e.enabled) {
        return Event::None;
    }
    // Lista de toggles (HABILIDADES): A alterna la marca de esa fila sin tocar las demás.
    if (s->kind == ScreenKind::Toggle) {
        e.marked = !e.marked;
        return Event::Accept;
    }
    // Lista: A marca la opción resaltada (la activa pasa a ser esa).
    if (s->kind == ScreenKind::List) {
        for (Entry& x : s->entries) {
            x.marked = false;
        }
        e.marked = true;
        return Event::Accept;
    }
    // Fila numérica: A incrementa (envuelve al llegar al máximo).
    if (e.kind == Kind::Number) {
        e.value = (e.value >= e.max) ? e.min : e.value + e.step;
        return Event::Move;
    }
    // Submenú: A entra.
    if (e.kind == Kind::Submenu) {
        ScreenId child;
        if (screen_for(e.action, child)) {
            g_stack.push_back(child);
            return Event::Accept;
        }
        return Event::None;
    }
    // Item (acción), selector y fila de mapeado: el modelo solo lo señala; la ejecución es del paso 6.
    if (e.kind == Kind::Item || e.kind == Kind::Selector || e.kind == Kind::Binding) {
        return Event::Accept;
    }
    return Event::None;
}

Event back() {
    ensure();
    if (g_stack.size() <= 1) {
        return Event::None;  // la raíz no tiene "atrás"
    }
    g_stack.pop_back();
    return Event::Back;
}

void debug_show(int screen_id) {
    ensure();
    if (screen_id < 0 || screen_id > static_cast<int>(ScreenId::SaveGame)) {
        return;
    }
    const ScreenId id = static_cast<ScreenId>(screen_id);
    g_stack.clear();
    g_stack.push_back(ScreenId::Root);
    if (id != ScreenId::Root) {
        g_stack.push_back(id);
    }
    if (Screen* s = find_screen(id)) {
        s->cursor = 0;
    }
}

std::string describe_current() {
    ensure();
    const Screen* s = top();
    if (s == nullptr) {
        return "(sin pantalla)";
    }
    static const char* kKindName[] = {"Menu", "List", "Toggle"};
    std::string out = "screen=" + std::to_string(static_cast<int>(s->id)) +
                      " kind=" + kKindName[static_cast<int>(s->kind)] +
                      " cursor=" + std::to_string(s->cursor) + "\n";
    for (size_t i = 0; i < s->entries.size(); ++i) {
        const Entry& e = s->entries[i];
        out += (static_cast<int>(i) == s->cursor) ? "> " : "  ";
        out += e.label;
        if (e.kind == Kind::Selector && !e.options.empty()) {
            out += " < " + e.options[e.value] + " >";
        }
        if (e.kind == Kind::Binding) {
            out += " : " + e.binding;
        }
        if (e.marked) {
            out += " [x]";
        }
        if (!e.enabled) {
            out += " (gris)";
        }
        out += "\n";
    }
    return out;
}

// Desbloqueo por CODIGO de la sesion (sin el ajuste MANTENER EXTRAS).
bool extras_code_unlocked() {
    return g_extras_unlocked_state;
}

// Visible si se tecleo el codigo en esta sesion o si MANTENER EXTRAS esta en SI (persistencia
// explicita). Tambien si MODO HEAVEN o VENTAJA estan activos: aunque MANTENER EXTRAS sea NO, el
// usuario debe poder volver a entrar a EXTRAS para apagarlos.
bool extras_unlocked() {
    return g_extras_unlocked_state || hh::extras_config().persist == "si" ||
           hh::extras_config().heaven == "si" || hh::extras_config().advantage == "si" ||
           hh::extras_config().infinite_power == "si" ||
           hh::extras_config().infinite_stamina == "si";
}

// Copia cacheada en atomico del flag MODO HEAVEN: los hooks de runtime lo consultan CADA frame (p.
// ej. el forzado de la ventaja), asi evitamos comparar la cadena de config en cada llamada. Se
// inicializa desde config la primera vez y se actualiza en set_heaven_enabled (toggle).
std::atomic<bool> g_heaven_cache{ false };
std::atomic<bool> g_heaven_cache_init{ false };

bool heaven_enabled() {
    if (!g_heaven_cache_init.exchange(true)) {
        g_heaven_cache.store(hh::extras_config().heaven == "si");
    }
    return g_heaven_cache.load();
}

void set_heaven_enabled(bool on) {
    g_heaven_cache.store(on);
    g_heaven_cache_init.store(true);
    hh::extras_set_heaven(on);
}

// Igual que MODO HEAVEN: cache atomico del flag VENTAJA (independiente). La ventaja de combate se
// aplica si HEAVEN **o** VENTAJA estan en SI, asi que no hay conflicto entre ambos.
std::atomic<bool> g_advantage_cache{ false };
std::atomic<bool> g_advantage_cache_init{ false };

bool advantage_enabled() {
    if (!g_advantage_cache_init.exchange(true)) {
        g_advantage_cache.store(hh::extras_config().advantage == "si");
    }
    return g_advantage_cache.load();
}

void set_advantage_enabled(bool on) {
    g_advantage_cache.store(on);
    g_advantage_cache_init.store(true);
    hh::extras_set_advantage(on);
}

// Igual que VENTAJA: caches atomicos de PODER ∞ / RESIS. ∞ (independientes entre si).
std::atomic<bool> g_inf_power_cache{ false };
std::atomic<bool> g_inf_power_cache_init{ false };
std::atomic<bool> g_inf_stamina_cache{ false };
std::atomic<bool> g_inf_stamina_cache_init{ false };

bool infinite_power_enabled() {
    if (!g_inf_power_cache_init.exchange(true)) {
        g_inf_power_cache.store(hh::extras_config().infinite_power == "si");
    }
    return g_inf_power_cache.load();
}

void set_infinite_power_enabled(bool on) {
    g_inf_power_cache.store(on);
    g_inf_power_cache_init.store(true);
    hh::extras_set_infinite_power(on);
}

bool infinite_stamina_enabled() {
    if (!g_inf_stamina_cache_init.exchange(true)) {
        g_inf_stamina_cache.store(hh::extras_config().infinite_stamina == "si");
    }
    return g_inf_stamina_cache.load();
}

void set_infinite_stamina_enabled(bool on) {
    g_inf_stamina_cache.store(on);
    g_inf_stamina_cache_init.store(true);
    hh::extras_set_infinite_stamina(on);
}

// EXTRAS -> DEBUG NIVELES: habilita los atajos del CICLO DE PUNTOS y el indicador `idx=`.
static std::atomic<bool> g_debug_levels_cache{ false };
static std::atomic<bool> g_debug_levels_init{ false };
bool debug_levels_enabled() {
    if (!g_debug_levels_init.exchange(true)) {
        g_debug_levels_cache.store(hh::extras_config().debug_levels == "si");
    }
    return g_debug_levels_cache.load();
}
void set_debug_levels_enabled(bool on) {
    g_debug_levels_cache.store(on);
    g_debug_levels_init.store(true);
    hh::extras_set_debug_levels(on);
}

void unlock_extras() {
    if (g_extras_unlocked_state) return;
    g_extras_unlocked_state = true;
    // Rehace la raiz para que aparezca la entrada EXTRAS (el arbol se construyo sin ella). Seguro:
    // el desbloqueo ocurre durante la intro, antes de usar el menu. El desbloqueo por codigo es de
    // sesion; si ADEMAS MANTENER EXTRAS esta en SI, el menu reaparece solo en el siguiente arranque.
    reset();
}

std::string describe_tree() {
    ensure();
    std::string out;
    for (const Screen& s : g_screens) {
        out += "== screen " + std::to_string(static_cast<int>(s.id)) + " ==\n";
        for (const Entry& e : s.entries) {
            out += "  " + e.label;
            if (e.kind == Kind::Selector && !e.options.empty()) {
                out += " < " + e.options[e.value] + " >";
            }
            if (e.kind == Kind::Binding) {
                out += " : " + e.binding;
            }
            if (!e.enabled) {
                out += " (gris)";
            }
            out += "\n";
        }
    }
    return out;
}

// --- ELEGIR NIVEL: estado de partida cargada ---------------------------------------------------------
static std::atomic<bool> g_game_loaded{ false };
bool game_loaded() { return g_game_loaded.load(); }
void set_game_loaded(bool on) {
    if (g_game_loaded.exchange(on) != on) {
        hh::log("[elegir-nivel] partida %s\n", on ? "cargada" : "no cargada");
    }
}
// IR A NIVEL: valor de escena (idx) del indice del selector. Publico (lo usa el hook del menu).
uint16_t warp_value_at(int index) {
    const int n = static_cast<int>(sizeof(kStartPoints) / sizeof(kStartPoints[0]));
    if (index < 0 || index >= n) return 0;
    return kStartPoints[index].idx;
}

// CICLO DE PUNTOS (diagnostico): indice actual y peticion de paso. Lo usa el hook del menu (con
// rdram) para cargar/transicionar al punto; el indice persiste entre cargas.
static std::atomic<int> g_cycle_index{ 0 };
static std::atomic<bool> g_cycle_first{ true };   // el primer paso ejecuta el indice actual (0 = 1-0)
static std::atomic<int> g_cycle_request{ 0 };
// Índices que NO son cargables (cuelgan o son inválidos): el ciclo los salta. `[MEDIDO 2026-09-29]`:
// 5, 6, 8 = cuelgan / negro ("opening"). Ampliar según se descubran más. 7 = Intro antes del menú
// (por eso NO se salta: sirve como "volver al menú").
// Lista de saltos cargada de `saves/skip_indices.txt`. Se relee cada vez que se
// consulta (barato: fichero pequeño) para poder editarla sin recompilar. Si falta, se crea con los
// índices por defecto. Formato: un índice por línea; `#` comenta; comas/espacios también separan.
static std::set<int> g_cycle_skip_cache;
static std::filesystem::file_time_type g_cycle_skip_mtime{};
static bool g_cycle_skip_loaded = false;

static void cycle_skip_load(bool force) {
    const std::filesystem::path path = hh::get_app_folder_path() / "saves" / "skip_indices.txt";
    std::error_code ec;
    std::filesystem::create_directories(path.parent_path(), ec);
    const bool exists = std::filesystem::exists(path, ec);
    if (exists) {
        const auto mt = std::filesystem::last_write_time(path, ec);
        if (!force && g_cycle_skip_loaded && !ec && mt == g_cycle_skip_mtime) return;   // sin cambios
        g_cycle_skip_mtime = mt;
    } else if (g_cycle_skip_loaded && !force) {
        return;
    }
    std::set<int> s;
    if (exists) {
        std::ifstream in(path);
        std::string line;
        while (std::getline(in, line)) {
            const size_t hash = line.find('#');
            if (hash != std::string::npos) line = line.substr(0, hash);
            for (char& c : line) if (c == ',') c = ' ';
            std::istringstream iss(line);
            int v;
            while (iss >> v) s.insert(v);
        }
    } else {
        // Lista por defecto [MEDIDO 2026-09-29]: indices del ciclo que cuelgan / no cargan.
        s = { 5, 6, 7, 8, 9, 28, 29, 38, 39, 57, 58, 59, 65, 66, 67, 68, 69, 73, 74,
              78, 79, 85, 86, 87, 88, 89, 98, 99 };
        std::ofstream out(path);
        if (out) {
            out << "# Indices del CICLO DE PUNTOS (F5/F6) que se SALTAN (cuelgan). Uno por linea.\n"
                << "# Editable sin recompilar; se relee al pulsar. Ver plan 2026-09-29.\n";
            for (int v : s) out << v << "\n";
        }
    }
    g_cycle_skip_cache = std::move(s);
    g_cycle_skip_loaded = true;
}

static bool cycle_skip(int i) {
    cycle_skip_load(false);
    return g_cycle_skip_cache.count(i) != 0;
}
bool cycle_skipped(int i) { return cycle_skip(i); }   // público: el hook no ejecuta índices saltados
// `mag` = magnitud del salto (1 = fino, 10 = bloque). El indice arranca en -mag para que la primera
// pulsacion de F6 ejecute el 0 (1-0). Los indices que cuelgan (cycle_skip) se saltan.
void cycle_step_mag(int delta, int mag) {
    // Primer paso: ejecuta el indice actual (0 = 1-0) sin mover (solo para F6/+1).
    if (g_cycle_first.load() && delta > 0) {
        g_cycle_first.store(false);
        g_cycle_index.store(0);
        g_cycle_request.store(1);
        return;
    }
    g_cycle_first.store(false);
    int v = g_cycle_index.load();
    if (delta == 0) delta = 1;
    if (mag < 1) mag = 1;
    const int lo = 0, hi = 99;   // tope 99; al pasar de 99 vuelve a 0 (y al bajar de 0, a 99)
    int step = (delta > 0 ? mag : -mag);
    for (int guard = 0; guard < 400; ++guard) {
        v += step;
        if (v > hi) v = lo;
        if (v < lo) v = hi;
        if (!cycle_skip(v)) break;
    }
    g_cycle_index.store(v);
    g_cycle_request.store(1);
}
void cycle_step(int delta) { cycle_step_mag(delta, 1); }       // F5/F6: 1 en 1 (fino)
void cycle_step_block(int delta) { cycle_step_mag(delta, 10); } // RePag/AvPag: 10 en 10
void cycle_reset() {
    g_cycle_index.store(0);
    g_cycle_first.store(false);
    g_cycle_request.store(1);   // ejecuta el 0 (1-0)
}
void cycle_goto(int idx) {
    if (idx < 0) idx = 0;
    if (idx > 299) idx = 299;
    g_cycle_index.store(idx);
    g_cycle_request.store(1);
}
bool request_cycle() {
    return g_cycle_request.exchange(0) != 0;
}
int cycle_index() { return g_cycle_index.load(); }

// Warp pendiente: IR A NIVEL sin partida cargada deja aqui el destino; al terminar de cargar la
// plantilla, el hook de carga lo consume y ejecuta la transicion. -1 = no hay pendiente.
static std::atomic<int> g_pending_warp{ -1 };
void request_warp(uint16_t idx) { g_pending_warp.store(static_cast<int>(idx)); }
bool take_pending_warp(uint16_t& idx) {
    const int v = g_pending_warp.exchange(-1);
    if (v < 0) return false;
    idx = static_cast<uint16_t>(v);
    return true;
}

// --- EDICIÓN DE PARTIDA: API pública -----------------------------------------------------------------
int save_edit_slot() { return g_edit_slot; }
void set_save_edit_slot(int slot) {
    g_edit_slot = (slot < 0 || slot >= hh::save::kSlots) ? 0 : slot;
}
int save_edit_save_target() { return g_edit_save_target; }
void set_save_edit_save_target(int t) {
    g_edit_save_target = (t < 0 || t > hh::save::kSlots) ? 0 : t;
}
int save_edit_delete_target() { return g_edit_delete_target; }
void set_save_edit_delete_target(int t) {
    g_edit_delete_target = (t < 1 || t > hh::save::kSlots) ? 1 : t;
}
int save_edit_delete_slot() { return g_edit_delete_target - 1; }   // slot real 0..N-1
// Slot real destino del guardado: target 0 (NUEVA PARTIDA) = primer hueco libre de PARTIDA, con la
// MISMA definición que la cápsula (`first_free_game_slot` = metadato `presente` a 0); target 1..N =
// ese slot. NO usar `slot_used` (progreso != 0): un save en 1-0 tiene progreso 0 y se pisaría.
int save_edit_save_target_slot() {
    if (g_edit_save_target >= 1 && g_edit_save_target <= hh::save::kSlots) {
        return g_edit_save_target - 1;
    }
    return hh::save::first_free_game_slot();
}
int save_edit_body_state() { return g_edit_body_state; }
void set_save_edit_body_state(int state) {
    g_edit_body_state = (state < 0 || state > 1) ? 0 : state;
}

uint16_t save_edit_progress_value(int index) { return progress_value_at(index); }
void capture_tech_baseline() {
    for (int id = 0; id < hh::save::kTechCount; ++id) {
        g_tech_baseline[id] = hh::save::tech_learned_of(g_edit_slot, id) ? 1 : 0;
    }
    g_tech_baseline_valid = true;
    g_edit_tech_bulk = 0;   // el selector vuelve a SIN CAMBIOS tras una carga
}
void restore_tech_baseline(int id) {
    if (!g_tech_baseline_valid || id < 0 || id >= hh::save::kTechCount) return;
    hh::save::set_tech_learned_of(g_edit_slot, id, g_tech_baseline[id] != 0);
}
void set_save_edit_tech_bulk(int mode) {
    g_edit_tech_bulk = (mode < 0 || mode > 2) ? 0 : mode;
}
void refresh_save_edit() { rebuild_save_edit(); }

}  // namespace hh::menu
