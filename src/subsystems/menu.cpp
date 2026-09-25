// hh_menu — modelo del menú inicial del port (A2, paso 1: SOLO ESTADO).
//
// Implementa el árbol y la navegación descritos en include/hh/menu.h y RETOMAR.md §Menú. No dibuja,
// no lee input y no persiste: es una máquina de estados pura y testeable.

#include "hh/menu.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include "hh.h"   // VideoConfig/AudioConfig: valores iniciales de los selectores

namespace hh::menu {
namespace {

std::vector<Screen> g_screens;      // todas las pantallas (el estado vive aquí y se conserva)
std::vector<ScreenId> g_stack;      // camino activo; el tope es la pantalla visible
Layout g_layout;

// Traducciones de las etiquetas/opciones del menú. Clave = etiqueta canónica en ESPAÑOL (la del
// modelo). Columnas: en, ca, fr, de. El JAPONÉS de momento cae a INGLÉS (sus etiquetas en kana
// necesitan embeber la fuente JP; pendiente). Uppercase (la fuente del menú no tiene minúsculas
// acentuadas). Las tildes salen de las marcas del overlay (A/N/C).
struct MenuTr { const char* es; const char* en; const char* ca; const char* fr; const char* de; };
const MenuTr kMenuTr[] = {
    // Pantallas / entradas
    {"CONTINUAR", "CONTINUE", "CONTINUAR", "CONTINUER", "FORTSETZEN"},
    {"NUEVA PARTIDA", "NEW GAME", "NOVA PARTIDA", "NOUVELLE PARTIE", "NEUES SPIEL"},
    {"MODO COMBATE", "BATTLE MODE", "MODE COMBAT", "MODE COMBAT", "KAMPFMODUS"},
    {"AJUSTES", "SETTINGS", "AJUSTOS", "OPTIONS", "EINSTELLUNGEN"},
    {"EMPEZAR PARTIDA", "START GAME", "COMENÇAR PARTIDA", "COMMENCER", "SPIEL STARTEN"},
    {"DIFICULTAD", "DIFFICULTY", "DIFICULTAT", "DIFFICULTÉ", "SCHWIERIGKEIT"},
    {"IDIOMA", "LANGUAGE", "IDIOMA", "LANGUE", "SPRACHE"},
    {"GRÁFICOS", "GRAPHICS", "GRÀFICS", "GRAPHIQUES", "GRAFIK"},
    {"SONIDO", "SOUND", "SO", "SON", "TON"},
    {"DEBUG", "DEBUG", "DEBUG", "DEBUG", "DEBUG"},
    {"CÁMARA LIBRE", "FREE CAMERA", "CÀMERA LLIURE", "CAMÉRA LIBRE", "FREIE KAMERA"},
    {"APUNTADO LIBRE", "FREE AIM", "APUNTAT LLIURE", "VISÉE LIBRE", "FREIES ZIELEN"},
    {"RATIO", "RATIO", "RATIO", "RATIO", "RATIO"},
    {"RESOLUCIÓN", "RESOLUTION", "RESOLUCIÓ", "RÉSOLUTION", "AUFLÖSUNG"},
    {"P. COMPLETA", "FULLSCREEN", "P. COMPLETA", "PLEIN ÉCRAN", "VOLLBILD"},
    {"ANTIALIASING", "ANTIALIASING", "ANTIALIASING", "ANTIALIASING", "ANTIALIASING"},
    {"VSYNC", "VSYNC", "VSYNC", "VSYNC", "VSYNC"},
    {"LÍMITE DE FPS", "FPS LIMIT", "LÍMIT DE FPS", "LIMITE FPS", "FPS-LIMIT"},
    {"VENTANA DEBUG", "DEBUG WINDOW", "FINESTRA DEBUG", "FENÊTRE DEBUG", "DEBUG-FENSTER"},
    {"MOSTRAR FPS", "SHOW FPS", "MOSTRAR FPS", "AFFICHER FPS", "FPS ANZEIGEN"},
    {"VOLUMEN", "VOLUME", "VOLUM", "VOLUME", "LAUTSTÄRKE"},
    {"SALIDA", "OUTPUT", "SORTIDA", "SORTIE", "AUSGABE"},
    {"MENÚ SFX", "MENU SFX", "MENÚ SFX", "MENU SFX", "MENÜ-SFX"},
    // Opciones (mismos valores en todos los idiomas si no cambian)
    {"SÍ", "YES", "SÍ", "OUI", "JA"},
    {"NO", "NO", "NO", "NON", "NEIN"},
    {"AUTO", "AUTO", "AUTO", "AUTO", "AUTO"},
    {"ORIGINAL", "ORIGINAL", "ORIGINAL", "ORIGINAL", "ORIGINAL"},
    {"NATIVO", "NATIVE", "NATIU", "NATIF", "NATIV"},
    {"MONO", "MONO", "MONO", "MONO", "MONO"},
    {"ESTÉREO", "STEREO", "ESTÈREO", "STÉRÉO", "STEREO"},
    {"AURICULARES", "HEADPHONES", "AURICULARS", "CASQUE", "KOPFHÖRER"},
    {"DEFINITIVO", "ULTIMATE", "DEFINITIU", "SUPRÊME", "ULTIMATIV"},
    {"DIFÍCIL", "HARD", "DIFÍCIL", "DIFFICILE", "SCHWER"},
    {"NORMAL", "NORMAL", "NORMAL", "NORMAL", "NORMAL"},
};

// Endónimos de la lista IDIOMA: SIEMPRE en su propia lengua (no dependen del idioma activo). Clave =
// nombre canónico en español; valor = endónimo a mostrar. Uppercase (la fuente del menú no tiene
// minúsculas acentuadas: à/ñ/ç). JA en rōmaji (el endónimo real es 日本語, kanji, que color0 no
// dibuja; pendiente TTF).
struct Endonym { const char* es; const char* shown; };
const Endonym kEndonyms[] = {
    {"INGLÉS", "ENGLISH"},  {"ESPAÑOL", "ESPAÑOL"}, {"CATALÁN", "CATALÀ"},
    {"FRANCÉS", "FRANÇAIS"}, {"ALEMÁN", "DEUTSCH"}, {"JAPONÉS", "NIHONGO"},
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

Entry make_selector(const char* label, std::vector<std::string> options, int value = 0) {
    Entry e;
    e.label = label;
    e.kind = Kind::Selector;
    e.options = std::move(options);
    e.value = value;
    return e;
}

// Selector con acción (p. ej. DEBUG -> ToggleDebug): el valor cambia con izq/der y el enganche lee
// `action` para aplicar el efecto (ver feed_menu_navigation).
Entry make_selector_with_action(const char* label, std::vector<std::string> options, Action action,
                                int value = 0) {
    Entry e = make_selector(label, std::move(options), value);
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

// Rellena g_screens con el árbol acordado (orden de arriba a abajo).
void build_tree() {
    g_screens.clear();

    g_screens.push_back(make_screen(ScreenId::Root, ScreenKind::Menu, {
        make_item("CONTINUAR", Action::Continue),
        make_submenu("NUEVA PARTIDA", Action::OpenNewGame),
        make_submenu("MODO COMBATE", Action::BattleMode, /*enabled=*/false),
        make_submenu("AJUSTES", Action::OpenSettings),
    }));

    // NUEVA PARTIDA: iniciar, dificultad y los selectores de "experiencia moderna" (integrados aquí
    // en vez de un submenú: la etiqueta larga no cabía y se solapaba con los valores). El valor de
    // los selectores se cambia con izq/der y el real se enganchará en el paso 6.
    g_screens.push_back(make_screen(ScreenId::NewGame, ScreenKind::Menu, {
        make_item("EMPEZAR PARTIDA", Action::StartGame),
        make_submenu("DIFICULTAD", Action::OpenDifficulty),
        // IDIOMA va justo debajo de DIFICULTAD (decidido por el mantenedor).
        make_submenu("IDIOMA", Action::OpenLanguage),
        make_selector("CÁMARA LIBRE", {"NO", "SÍ"}),
        make_selector("APUNTADO LIBRE", {"NO", "SÍ"}),
    }));

    // DIFICULTAD: lista (A marca la aplicada; el resto sale en gris). La opción marcada es el valor
    // en memoria; vendrá de la config en el paso 6.
    g_screens.push_back(make_screen(ScreenId::Difficulty, ScreenKind::List, {
        make_option("DEFINITIVO"),
        make_option("DIFÍCIL"),
        make_option("NORMAL", /*marked=*/true),
    }));

    // MODO COMBATE: por definir; la entrada de la raíz sale deshabilitada.
    g_screens.push_back(make_screen(ScreenId::BattleMode, ScreenKind::Menu, {}));

    // AJUSTES: GRÁFICOS / SONIDO y DEBUG al final (submenú con las opciones de depuración).
    // IDIOMA se movió a NUEVA PARTIDA (debajo de DIFICULTAD).
    g_screens.push_back(make_screen(ScreenId::Settings, ScreenKind::Menu, {
        make_submenu("GRÁFICOS", Action::OpenGraphics),
        make_submenu("SONIDO", Action::OpenSound),
        make_submenu("DEBUG", Action::OpenDebug),
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
        make_selector_with_action("RESOLUCIÓN", {"AUTO", "ORIGINAL"}, Action::ResolutionSelect),
        // Los tres siguientes persisten en config.ini [video] y aplican en vivo (ver
        // feed_menu_navigation). El valor inicial sale de la config (default: borderless/SÍ/NATIVO).
        make_selector_with_action("P. COMPLETA", {"NO", "SÍ"}, Action::ToggleFullscreen,
                                  fullscreen_default()),
        make_selector_with_action("ANTIALIASING", {"x0", "x2", "x4", "x8"}, Action::MsaaSelect,
                                  msaa_default()),
        make_selector_with_action("VSYNC", {"NO", "SÍ"}, Action::ToggleVsync, vsync_default()),
        // NATIVO = refresco del monitor; un número = tasa fija (RT64 refreshRate). Orden ascendente;
        // incluye 40 (Steam Deck), 90 (Deck/VR) y 75 (monitores antiguos). Se recorta al monitor.
        make_selector_with_action("LÍMITE DE FPS",
                                  {"NATIVO", "30", "40", "60", "75", "90", "120", "144", "165", "240"},
                                  Action::FpsLimit, fps_limit_default()),
    }));

    // DEBUG: opciones de depuración (fuera de GRÁFICOS para no alargarlo).
    g_screens.push_back(make_screen(ScreenId::Debug, ScreenKind::Menu, {
        make_selector_with_action("VENTANA DEBUG", {"NO", "SÍ"}, Action::ToggleDebug,
                                  developer_default()),
        // Indicador de FPS del overlay; persiste en config.ini [video].showfps.
        make_selector_with_action("MOSTRAR FPS", {"NO", "SÍ"}, Action::ToggleShowFps,
                                  show_fps_default()),
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
        make_selector_with_action("VOLUMEN",
                                  {"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%",
                                   "90%", "100%"},
                                  Action::VolumeSelect, volume_default()),
        make_selector_with_action("SALIDA", {"MONO", "ESTÉREO", "AURICULARES"}, Action::OutputSelect,
                                  output_default()),
        make_selector_with_action("MENÚ SFX", {"NO", "SÍ"}, Action::MenuSfxToggle,
                                  menu_sfx_default()),
    }));
}

Screen* find_screen(ScreenId id) {
    for (Screen& s : g_screens) {
        if (s.id == id) {
            return &s;
        }
    }
    return nullptr;
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
        case Action::BattleMode:     out = ScreenId::BattleMode; return true;
        default:                     return false;
    }
}

}  // namespace

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

int depth() {
    ensure();
    return static_cast<int>(g_stack.size());
}

const Layout& layout() {
    return g_layout;
}

std::string localized(const std::string& label) {
    if (label.empty()) return label;
    // Endónimos de la lista IDIOMA: fijos (no se traducen).
    for (const Endonym& e : kEndonyms) {
        if (label == e.es) return e.shown;
    }
    const std::string& c = hh::text_current_language();
    int lang = 0;   // 0=es, 1=en, 2=ca, 3=fr, 4=de
    if (c == "en") lang = 1;
    else if (c == "ca") lang = 2;
    else if (c == "fr") lang = 3;
    else if (c == "de") lang = 4;
    else if (c == "ja") lang = 1;   // JA: de momento inglés (kana pendiente)
    for (const MenuTr& t : kMenuTr) {
        if (label != t.es) continue;
        switch (lang) {
            case 1: return t.en;
            case 2: return t.ca;
            case 3: return t.fr;
            case 4: return t.de;
            default: return t.es;
        }
    }
    return label;
}

Event move_up() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    const int n = static_cast<int>(s->entries.size());
    const int c = (s->cursor - 1 + n) % n;
    if (c == s->cursor) {
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
    const int n = static_cast<int>(s->entries.size());
    const int c = (s->cursor + 1) % n;
    if (c == s->cursor) {
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
    // Lista: A marca la opción resaltada (la activa pasa a ser esa).
    if (s->kind == ScreenKind::List) {
        for (Entry& x : s->entries) {
            x.marked = false;
        }
        e.marked = true;
        return Event::Accept;
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
    // Item (acción) y selector: el modelo solo lo señala; la ejecución es del paso 6.
    if (e.kind == Kind::Item || e.kind == Kind::Selector) {
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
    if (screen_id < 0 || screen_id > static_cast<int>(ScreenId::Debug)) {
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
    static const char* kKindName[] = {"Menu", "List"};
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
            if (!e.enabled) {
                out += " (gris)";
            }
            out += "\n";
        }
    }
    return out;
}

}  // namespace hh::menu
