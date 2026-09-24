// hh_menu — modelo del menú inicial del port (A2, paso 1: SOLO ESTADO).
//
// Implementa el árbol y la navegación descritos en include/hh/menu.h y RETOMAR.md §Menú. No dibuja,
// no lee input y no persiste: es una máquina de estados pura y testeable.

#include "hh/menu.h"

#include <cstdio>

namespace hh::menu {
namespace {

std::vector<Screen> g_screens;      // todas las pantallas (el estado vive aquí y se conserva)
std::vector<ScreenId> g_stack;      // camino activo; el tope es la pantalla visible
Layout g_layout;

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

Entry make_option(const char* label, bool marked = false) {
    Entry e;
    e.label = label;
    e.kind = Kind::Option;
    e.marked = marked;
    return e;
}

Screen make_screen(ScreenId id, ScreenKind kind, bool applies, std::vector<Entry> entries) {
    Screen s;
    s.id = id;
    s.kind = kind;
    s.applies = applies;
    s.entries = std::move(entries);
    return s;
}

// Rellena g_screens con el árbol acordado (orden de arriba a abajo).
void build_tree() {
    g_screens.clear();

    g_screens.push_back(make_screen(ScreenId::Root, ScreenKind::Menu, false, {
        make_item("CONTINUAR", Action::Continue),
        make_submenu("NUEVA PARTIDA", Action::OpenNewGame),
        make_submenu("MODO COMBATE", Action::BattleMode, /*enabled=*/false),
        make_submenu("AJUSTES", Action::OpenSettings),
    }));

    g_screens.push_back(make_screen(ScreenId::NewGame, ScreenKind::Menu, false, {
        make_submenu("AJUSTES EXPERIENCIA MODERNA", Action::OpenExperience),
        make_item("EMPEZAR PARTIDA", Action::StartGame),
        make_submenu("DIFICULTAD", Action::OpenDifficulty),
    }));

    // AJUSTES EXPERIENCIA MODERNA: selectores laterales (propuestas por decidir; el valor real se
    // enganchará en el paso 6).
    g_screens.push_back(make_screen(ScreenId::Experience, ScreenKind::Menu, true, {
        make_selector("CÁMARA LIBRE", {"NO", "SÍ"}),
        make_selector("APUNTADO LIBRE", {"NO", "SÍ"}),
    }));

    // DIFICULTAD: lista (A marca, X aplica). El valor activo vendrá de la config (paso 6).
    g_screens.push_back(make_screen(ScreenId::Difficulty, ScreenKind::List, true, {
        make_option("SUPREMO"),
        make_option("DIFÍCIL"),
        make_option("NORMAL"),
    }));

    // MODO COMBATE: por definir; la entrada de la raíz sale deshabilitada.
    g_screens.push_back(make_screen(ScreenId::BattleMode, ScreenKind::Menu, false, {}));

    g_screens.push_back(make_screen(ScreenId::Settings, ScreenKind::Menu, false, {
        make_submenu("IDIOMA", Action::OpenLanguage),
        make_submenu("GRÁFICOS", Action::OpenGraphics),
        make_submenu("SONIDO", Action::OpenSound),
    }));

    // IDIOMA: lista, de INGLÉS (arriba) a JAPONÉS (abajo). El activo vendrá del idioma actual (A1).
    g_screens.push_back(make_screen(ScreenId::Language, ScreenKind::List, true, {
        make_option("INGLÉS"),
        make_option("ESPAÑOL"),
        make_option("CATALÁN"),
        make_option("FRANCÉS"),
        make_option("ALEMÁN"),
        make_option("JAPONÉS"),
    }));

    g_screens.push_back(make_screen(ScreenId::Graphics, ScreenKind::Menu, true, {
        make_submenu("RESOLUCIÓN", Action::OpenResolution),
        make_selector("ANTIALIASING", {"x0", "x2", "x4", "x8"}),
        make_selector("VSYNC", {"NO", "SÍ"}),
        make_selector("LÍMITE DE FPS", {"0", "30", "60", "120", "144", "160"}),
        make_selector("MOSTRAR FPS", {"NO", "SÍ"}),
    }));

    // SONIDO: lista (ya era así en el vanilla).
    g_screens.push_back(make_screen(ScreenId::Sound, ScreenKind::List, true, {
        make_option("ESTÉREO"),
        make_option("MONO"),
    }));

    // RESOLUCIÓN: lista larga. Se rellenará con las resoluciones reales de RT64 en el paso 6.
    g_screens.push_back(make_screen(ScreenId::Resolution, ScreenKind::List, true, {}));
}

Screen* find_screen(ScreenId id) {
    for (Screen& s : g_screens) {
        if (s.id == id) {
            return &s;
        }
    }
    return nullptr;
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
        case Action::OpenExperience: out = ScreenId::Experience; return true;
        case Action::OpenDifficulty: out = ScreenId::Difficulty; return true;
        case Action::OpenSettings:   out = ScreenId::Settings;   return true;
        case Action::OpenLanguage:   out = ScreenId::Language;   return true;
        case Action::OpenGraphics:   out = ScreenId::Graphics;   return true;
        case Action::OpenSound:      out = ScreenId::Sound;      return true;
        case Action::OpenResolution: out = ScreenId::Resolution; return true;
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

Event apply() {
    ensure();
    Screen* s = top();
    if (s == nullptr || !s->applies || g_stack.size() <= 1) {
        return Event::None;
    }
    g_stack.pop_back();
    return Event::Applied;
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
    if (screen_id < 0 || screen_id > static_cast<int>(ScreenId::Resolution)) {
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
                      " cursor=" + std::to_string(s->cursor) +
                      " applies=" + (s->applies ? "1" : "0") + "\n";
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
