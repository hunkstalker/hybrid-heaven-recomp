#include <algorithm>
#include <cctype>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#ifdef _WIN32
#define SDL_MAIN_HANDLED
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#ifdef None
#undef None
#endif

#include "ultramodern/hh_paklog.hpp"
#include "ultramodern/input.hpp"
#include "ultramodern/ultramodern.hpp"

#include "hh.h"
#include "hh/config_ini.h"
#include "hh/hudrewrite.h"
#include "hh/menu.h"

// HH: reloj de juego esclavo del replay (runtime ultramodern/src/timer.cpp). Ver
// notes/2026-09-17-cac-timeline-modulo24-periodo.md §5.
extern "C" void hh_replay_clock_set(double t_seconds);
extern "C" bool hh_replay_clock_on();
extern "C" void hh_replay_set_sample(uint64_t idx);

using n64_button = uint16_t;

enum N64Buttons : n64_button {
    A_BUTTON = 0x8000,
    B_BUTTON = 0x4000,
    Z_BUTTON = 0x2000,
    START_BUTTON = 0x1000,
    DUP_BUTTON = 0x800,
    DDOWN_BUTTON = 0x400,
    DLEFT_BUTTON = 0x200,
    DRIGHT_BUTTON = 0x100,
    L_BUTTON = 0x20,
    R_BUTTON = 0x10,
    CUP_BUTTON = 0x8,
    CDOWN_BUTTON = 0x4,
    CLEFT_BUTTON = 0x2,
    CRIGHT_BUTTON = 0x1,
};

// ===== Perfiles de mando (config.ini) =====
// La traduccion mando fisico -> botones N64 vive en la capa de plataforma; la logica del juego no
// se toca. Hay dos contextos: "game" (exploracion/combate) y "menu" (menus del juego: pausa, mapa,
// combate...). El port detecta el contexto leyendo el flag de UI 0x802690D0 (1 = UI abierta),
// localizado comparando volcados de RDRAM de gameplay vs menu de pausa (mismo replay por VI).
static uint8_t* hh_game_rdram = nullptr;
static constexpr uint32_t HH_MENU_FLAG_ADDR = 0x2690D0;  // guest 0x802690D0

void hh::on_game_init(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    hh_game_rdram = rdram;
    // Aqui ya corrio init_overlays(): registrar los hooks de loader (add_loaded_function) ahora,
    // no en register_overlays() (init_overlays hace func_map.clear()).
    hh::register_runtime_functions();
}

uint8_t* hh::get_game_rdram() {
    return hh_game_rdram;
}

struct PadProfile {
    // Mapeo FIJO (sin remapeo por contexto): cada boton fisico envia SIEMPRE el mismo boton del N64.
    // Antes B cambiaba de funcion segun si habia un menu/mapa abierto -> variabilidad en la misma
    // partida; eliminado. La referencia (y Goemon, via recompinput) tambien usa mapeo fijo.
    //   B fisico -> N64 B (atras/mapa/cancelar)  [intuitivo]
    //   X fisico -> N64 Z (agacharse)            [X estaba libre; en combate se usa A]
    //   Y -> C-Down (1a persona, verificado); Back -> N64 B (alias); LB/RB -> L/R; cruceta -> D-pad.
    n64_button a = A_BUTTON, b = B_BUTTON, x = Z_BUTTON, y = CDOWN_BUTTON;
    n64_button lb = L_BUTTON, rb = R_BUTTON, back = B_BUTTON, start = START_BUTTON;
    n64_button dup = DUP_BUTTON, ddown = DDOWN_BUTTON, dleft = DLEFT_BUTTON, dright = DRIGHT_BUTTON;
    bool cstick = true;  // stick derecho -> botones C
};

static PadProfile hh_pad_game;
static PadProfile hh_pad_menu;  // identico a game: el contexto ya NO cambia los botones

// Teclado: mapeo por defecto (físico -> N64), espejo del mando. Lo usa `read_input_button` y la
// descripción de bindings del menú CONTROLES. `name` = etiqueta que se muestra en el menú.
struct HHKeyBind {
    SDL_Scancode sc;
    n64_button btn;
    const char* name;
};
static const HHKeyBind kHHDefaultKeys[] = {
    { SDL_SCANCODE_UP, DUP_BUTTON, "UP" },
    { SDL_SCANCODE_DOWN, DDOWN_BUTTON, "DOWN" },
    { SDL_SCANCODE_LEFT, DLEFT_BUTTON, "LEFT" },
    { SDL_SCANCODE_RIGHT, DRIGHT_BUTTON, "RIGHT" },
    { SDL_SCANCODE_H, Z_BUTTON, "H" },
    { SDL_SCANCODE_J, A_BUTTON, "J" },
    { SDL_SCANCODE_K, B_BUTTON, "K" },
    { SDL_SCANCODE_L, CDOWN_BUTTON, "L" },  // PRIMERA PERSONA (C-abajo)
    { SDL_SCANCODE_I, R_BUTTON, "I" },      // APUNTAR (N64 R)
    { SDL_SCANCODE_R, CUP_BUTTON, "R" },    // ALTURA CÁMARA (C-arriba)
    { SDL_SCANCODE_RETURN, START_BUTTON, "ENTER" },
};

// Teclado configurable: mapa scancode -> boton N64. Se inicializa con kHHDefaultKeys y se ajusta
// con la seccion `[keys]` de config.ini (al reasignar desde el menu CONTROLES). `name` del display
// sale de SDL_GetScancodeName.
static std::map<SDL_Scancode, n64_button> hh_key_map;
static bool hh_key_map_ready = false;

// Funciones definidas mas abajo (se usan en la captura/reset de CONTROLES).
static SDL_GameController* hh_pad_controller();
static void hh_pad_track(SDL_GameController* c);
static void hh_pad_untrack(SDL_GameController* c);
static void hh_key_save();
static float controller_axis_to_float(Sint16 value);

static SDL_Scancode hh_scancode_by_name(const std::string& name) {
    std::string want = name;
    for (char& c : want) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
        const char* n = SDL_GetScancodeName(static_cast<SDL_Scancode>(sc));
        if (n == nullptr || *n == '\0') continue;
        std::string have = n;
        for (char& c : have) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (have == want) return static_cast<SDL_Scancode>(sc);
    }
    return SDL_SCANCODE_UNKNOWN;
}

static std::string hh_scancode_display(SDL_Scancode sc) {
    const char* n = SDL_GetScancodeName(sc);
    std::string s = (n != nullptr) ? n : "";
    for (char& c : s) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    if (s == "RETURN" || s == "KP ENTER" || s == "KEYPAD ENTER") s = "ENTER";
    if (s == "ESCAPE") s = "ESC";
    return s;
}

// Ejes de movimiento (stick izquierdo). Solo el TECLADO es configurable; el mando es el stick.
enum HHAxis { HH_AXIS_UP = 0, HH_AXIS_DOWN, HH_AXIS_LEFT, HH_AXIS_RIGHT, HH_AXIS_COUNT };
static SDL_Scancode hh_axis_key[HH_AXIS_COUNT] = {
    SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D
};
static int hh_axis_by_name(const std::string& raw) {
    std::string n = raw;
    for (char& c : n) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    if (n == "axis_up") return HH_AXIS_UP;
    if (n == "axis_down") return HH_AXIS_DOWN;
    if (n == "axis_left") return HH_AXIS_LEFT;
    if (n == "axis_right") return HH_AXIS_RIGHT;
    return -1;
}

// Fuente de MANDO de un eje: direccion de un stick (izquierdo/derecho). Por defecto, stick izq.
enum {
    HH_AXGP_NONE = 0,
    HH_AXGP_LY_UP, HH_AXGP_LY_DOWN, HH_AXGP_LX_LEFT, HH_AXGP_LX_RIGHT,
    HH_AXGP_RY_UP, HH_AXGP_RY_DOWN, HH_AXGP_RX_LEFT, HH_AXGP_RX_RIGHT
};
static int hh_axis_gp[HH_AXIS_COUNT] = {
    HH_AXGP_LY_UP, HH_AXGP_LY_DOWN, HH_AXGP_LX_LEFT, HH_AXGP_LX_RIGHT
};
static const char* hh_axis_gp_name(int code) {
    switch (code) {
        case HH_AXGP_LY_UP: return "EJE Y+";
        case HH_AXGP_LY_DOWN: return "EJE Y-";
        case HH_AXGP_LX_LEFT: return "EJE X-";
        case HH_AXGP_LX_RIGHT: return "EJE X+";
        case HH_AXGP_RY_UP: return "EJE RY+";
        case HH_AXGP_RY_DOWN: return "EJE RY-";
        case HH_AXGP_RX_LEFT: return "EJE RX-";
        case HH_AXGP_RX_RIGHT: return "EJE RX+";
        default: return "-";
    }
}
static int hh_axis_gp_by_name(const std::string& raw) {
    std::string n = raw;
    for (char& c : n) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    if (n == "EJE Y+") return HH_AXGP_LY_UP;
    if (n == "EJE Y-") return HH_AXGP_LY_DOWN;
    if (n == "EJE X-") return HH_AXGP_LX_LEFT;
    if (n == "EJE X+") return HH_AXGP_LX_RIGHT;
    if (n == "EJE RY+") return HH_AXGP_RY_UP;
    if (n == "EJE RY-") return HH_AXGP_RY_DOWN;
    if (n == "EJE RX-") return HH_AXGP_RX_LEFT;
    if (n == "EJE RX+") return HH_AXGP_RX_RIGHT;
    return HH_AXGP_NONE;
}

static const char* hh_pad_button_name(n64_button b) {
    switch (b) {
        case A_BUTTON: return "A";
        case B_BUTTON: return "B";
        case Z_BUTTON: return "Z";
        case START_BUTTON: return "START";
        case L_BUTTON: return "L";
        case R_BUTTON: return "R";
        case CUP_BUTTON: return "CUP";
        case CDOWN_BUTTON: return "CDOWN";
        case CLEFT_BUTTON: return "CLEFT";
        case CRIGHT_BUTTON: return "CRIGHT";
        case DUP_BUTTON: return "DUP";
        case DDOWN_BUTTON: return "DDOWN";
        case DLEFT_BUTTON: return "DLEFT";
        case DRIGHT_BUTTON: return "DRIGHT";
        default: return "NONE";
    }
}

static n64_button hh_pad_button_by_name(const std::string& raw_name, bool& ok) {
    std::string name = raw_name;
    for (char& c : name) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    ok = true;
    if (name.empty() || name == "none" || name == "nada") return 0;
    if (name == "a") return A_BUTTON;
    if (name == "b") return B_BUTTON;
    if (name == "z") return Z_BUTTON;
    if (name == "start") return START_BUTTON;
    if (name == "l") return L_BUTTON;
    if (name == "r") return R_BUTTON;
    if (name == "cup") return CUP_BUTTON;
    if (name == "cdown") return CDOWN_BUTTON;
    if (name == "cleft") return CLEFT_BUTTON;
    if (name == "cright") return CRIGHT_BUTTON;
    if (name == "dup") return DUP_BUTTON;
    if (name == "ddown") return DDOWN_BUTTON;
    if (name == "dleft") return DLEFT_BUTTON;
    if (name == "dright") return DRIGHT_BUTTON;
    ok = false;
    return 0;
}

static void hh_pad_set(PadProfile& p, const std::string& key, const std::string& val, bool& ok) {
    ok = true;
    if (key == "cstick") {
        p.cstick = (val == "on" || val == "1" || val == "si" || val == "true");
        return;
    }
    n64_button btn = hh_pad_button_by_name(val, ok);
    if (!ok) return;
    if (key == "a") p.a = btn;
    else if (key == "b") p.b = btn;
    else if (key == "x") p.x = btn;
    else if (key == "y") p.y = btn;
    else if (key == "lb") p.lb = btn;
    else if (key == "rb") p.rb = btn;
    else if (key == "back") p.back = btn;
    else if (key == "start") p.start = btn;
    else if (key == "dup") p.dup = btn;
    else if (key == "ddown") p.ddown = btn;
    else if (key == "dleft") p.dleft = btn;
    else if (key == "dright") p.dright = btn;
    else ok = false;
}

static std::string hh_pad_trim(const std::string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return std::string();
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

static void hh_pad_write_template(FILE* f) {
    fprintf(f,
        "# Hybrid Heaven Recomp - mapeo de mando (editable; se relee en cada arranque)\n"
        "# Valores: A B Z START L R CUP CDOWN CLEFT CRIGHT DUP DDOWN DLEFT DRIGHT NONE\n"
        "# Mapeo FIJO (sin remapeo por contexto): B fisico = N64 B (atras/mapa), X = N64 Z\n"
        "# (agacharse), Y = CDOWN (1a persona), Back = B (alias), LB/RB = L/R, cruceta = D-pad.\n"
        "# [game] y [menu] son identicos; se mantienen por compatibilidad de formato.\n"
        "[game]\n"
        "a = A\n"
        "b = B\n"
        "x = Z\n"
        "y = CDOWN\n"
        "lb = L\n"
        "rb = R\n"
        "back = B\n"
        "start = START\n"
        "dup = DUP\n"
        "ddown = DDOWN\n"
        "dleft = DLEFT\n"
        "dright = DRIGHT\n"
        "cstick = on\n"
        "\n"
        "[menu]\n"
        "a = A\n"
        "b = B\n"
        "x = Z\n"
        "y = CDOWN\n"
        "lb = L\n"
        "rb = R\n"
        "back = B\n"
        "start = START\n"
        "dup = DUP\n"
        "ddown = DDOWN\n"
        "dleft = DLEFT\n"
        "dright = DRIGHT\n"
        "cstick = on\n"
        "\n"
        "[video]\n"
        "# Graficos. wm: borderless|windowed; res: auto|original|2x|<n>|4k|8k;\n"
        "# aspect: auto|original|expand|4:3|16:9|<float>; msaa: off|2x|4x|8x.\n"
        "# Atajos en caliente: Alt+Enter (ventana), F1 (aspecto), F2 (MSAA).\n"
        "wm = borderless\n"
        "res = auto\n"
        "aspect = auto\n"
        "msaa = 8x\n");
}

static void hh_pad_config_load() {
    static bool loaded = false;
    if (loaded) return;
    loaded = true;

    if (!hh_key_map_ready) {
        hh_key_map_ready = true;
        for (const HHKeyBind& k : kHHDefaultKeys) hh_key_map[k.sc] = k.btn;
    }

    const char* env = getenv("HH_PAD_CONFIG");
    std::string path = (env != nullptr && *env != '\0') ? env : "config.ini";
    FILE* f = fopen(path.c_str(), "rb");
    if (f == nullptr && env == nullptr) {
        FILE* t = fopen(path.c_str(), "wb");
        if (t != nullptr) {
            hh_pad_write_template(t);
            fclose(t);
            fprintf(stderr, "[PAD] config.ini no existia: creada plantilla con el mapeo por defecto\n");
            f = fopen(path.c_str(), "rb");
        }
    }
    if (f != nullptr) {
        PadProfile* cur = nullptr;
        bool in_keys = false;
        char line[512];
        while (fgets(line, sizeof(line), f) != nullptr) {
            std::string s(line);
            size_t cut = s.find_first_of("#;");
            if (cut != std::string::npos) s = s.substr(0, cut);
            s = hh_pad_trim(s);
            if (s.empty()) continue;
            if (s.front() == '[' && s.back() == ']') {
                std::string sec = hh_pad_trim(s.substr(1, s.size() - 2));
                in_keys = (sec == "keys");
                cur = (sec == "menu") ? &hh_pad_menu : ((sec == "game") ? &hh_pad_game : nullptr);
                continue;
            }
            size_t eq = s.find('=');
            if (eq == std::string::npos) continue;
            std::string key = hh_pad_trim(s.substr(0, eq));
            std::string val = hh_pad_trim(s.substr(eq + 1));
            if (in_keys) {
                // `[keys]`: nombre de tecla (SDL_GetScancodeName) = boton N64; o eje:
                // `axis_up = W` (tecla) y `axis_up_gp = EJE Y+` (fuente de mando del eje).
                if (key.size() > 3 && key.compare(key.size() - 3, 3, "_gp") == 0) {
                    const int ax = hh_axis_by_name(key.substr(0, key.size() - 3));
                    if (ax >= 0) {
                        const int code = hh_axis_gp_by_name(val);
                        if (code != HH_AXGP_NONE) hh_axis_gp[ax] = code;
                        continue;
                    }
                }
                const int axis = hh_axis_by_name(key);
                if (axis >= 0) {
                    SDL_Scancode sc = hh_scancode_by_name(val);
                    if (sc != SDL_SCANCODE_UNKNOWN) hh_axis_key[axis] = sc;
                    continue;
                }
                bool ok = false;
                n64_button btn = hh_pad_button_by_name(val, ok);
                if (ok) {
                    SDL_Scancode sc = hh_scancode_by_name(key);
                    if (sc != SDL_SCANCODE_UNKNOWN) hh_key_map[sc] = btn;
                }
                continue;
            }
            if (cur == nullptr) continue;
            bool ok = false;
            hh_pad_set(*cur, key, val, ok);
            if (!ok) fprintf(stderr, "[PAD] config.ini: entrada ignorada '%s=%s'\n", key.c_str(), val.c_str());
        }
        fclose(f);
        fprintf(stderr, "[PAD] config cargada: %s\n", path.c_str());
    }
    else {
        fprintf(stderr, "[PAD] config.ini no encontrada: mapeo por defecto\n");
    }
    fprintf(stderr, "[PAD] game: A=%s B=%s X=%s Y=%s LB=%s RB=%s Back=%s Start=%s cstick=%s\n",
            hh_pad_button_name(hh_pad_game.a), hh_pad_button_name(hh_pad_game.b),
            hh_pad_button_name(hh_pad_game.x), hh_pad_button_name(hh_pad_game.y),
            hh_pad_button_name(hh_pad_game.lb), hh_pad_button_name(hh_pad_game.rb),
            hh_pad_button_name(hh_pad_game.back), hh_pad_button_name(hh_pad_game.start),
            hh_pad_game.cstick ? "on" : "off");
    fprintf(stderr, "[PAD] menu: A=%s B=%s X=%s Y=%s LB=%s RB=%s Back=%s Start=%s cstick=%s\n",
            hh_pad_button_name(hh_pad_menu.a), hh_pad_button_name(hh_pad_menu.b),
            hh_pad_button_name(hh_pad_menu.x), hh_pad_button_name(hh_pad_menu.y),
            hh_pad_button_name(hh_pad_menu.lb), hh_pad_button_name(hh_pad_menu.rb),
            hh_pad_button_name(hh_pad_menu.back), hh_pad_button_name(hh_pad_menu.start),
            hh_pad_menu.cstick ? "on" : "off");
}

// HH: el flag de UI in-game (0x802690D0) se activa con pausa/mapa, pero NO en los menus previos al
// gameplay (titulo / menu principal). Para que el B fisico (=B del N64, atras) funcione tambien
// ahi, se detecta el front-end con el directorio de recursos del juego (guest 0x8008DFC0: 0x100
// entradas de 8 B, id16 + base32): en el front-end tiene pocas entradas; al entrar en gameplay
// (GAME START) sube a ~30. Una vez visto gameplay, se queda fijado (no vuelve al perfil de menú).
static constexpr uint32_t HH_OVERLAY_DIR_ADDR = 0x8DFC0;
static constexpr uint32_t HH_OVERLAY_DIR_ENTRIES = 0x100;
static constexpr unsigned HH_FRONTEND_DIR_MAX = 16;

static bool hh_frontend_menu() {
    static bool gameplay_seen = false;
    if (gameplay_seen || hh_game_rdram == nullptr) {
        return !gameplay_seen;
    }
    unsigned count = 0;
    for (uint32_t e = 0; e < HH_OVERLAY_DIR_ENTRIES && count < HH_FRONTEND_DIR_MAX; ++e) {
        uint32_t off = (HH_OVERLAY_DIR_ADDR + e * 8) ^ 2;  // id16 leido con el word-swap del buffer
        uint16_t id = *(uint16_t*)&hh_game_rdram[off & 0x1FFFFFFF];
        if (id != 0) {
            ++count;
        }
    }
    if (count >= HH_FRONTEND_DIR_MAX) {
        gameplay_seen = true;
    }
    return !gameplay_seen;
}

static bool hh_ui_menu_open() {
    return (hh_game_rdram != nullptr) && (*(uint32_t*)&hh_game_rdram[HH_MENU_FLAG_ADDR] != 0);
}

static const PadProfile& hh_active_profile() {
    // Override manual para pruebas/diagnostico: HH_PAD_CONTEXT=menu | juego.
    const char* ov = getenv("HH_PAD_CONTEXT");
    bool menu;
    if (ov != nullptr && (*ov == 'm' || *ov == 'M')) {
        menu = true;
    }
    else if (ov != nullptr && (*ov == 'g' || *ov == 'G' || *ov == 'j' || *ov == 'J')) {
        menu = false;
    }
    else {
        menu = hh_ui_menu_open() || hh_frontend_menu();
    }
    // HH: el cambio de contexto solo se imprime con HH_PADLOG=1 (por defecto es ruido en consola).
    static bool last_menu = false;
    static bool logged = false;
    static const bool hh_padlog = getenv("HH_PADLOG") != nullptr;
    if (hh_padlog && (!logged || menu != last_menu)) {
        logged = true;
        last_menu = menu;
        fprintf(stderr, "[PAD] contexto: %s\n", menu ? "menu" : "juego");
    }
    return menu ? hh_pad_menu : hh_pad_game;
}

// ===== Menu CONTROLES: descripción de bindings y Stick C =====
static void hh_pad_save() {
    auto sec = [](const PadProfile& p) {
        std::vector<std::pair<std::string, std::string>> kv;
        kv.emplace_back("a", hh_pad_button_name(p.a));
        kv.emplace_back("b", hh_pad_button_name(p.b));
        kv.emplace_back("x", hh_pad_button_name(p.x));
        kv.emplace_back("y", hh_pad_button_name(p.y));
        kv.emplace_back("lb", hh_pad_button_name(p.lb));
        kv.emplace_back("rb", hh_pad_button_name(p.rb));
        kv.emplace_back("back", hh_pad_button_name(p.back));
        kv.emplace_back("start", hh_pad_button_name(p.start));
        kv.emplace_back("dup", hh_pad_button_name(p.dup));
        kv.emplace_back("ddown", hh_pad_button_name(p.ddown));
        kv.emplace_back("dleft", hh_pad_button_name(p.dleft));
        kv.emplace_back("dright", hh_pad_button_name(p.dright));
        kv.emplace_back("cstick", p.cstick ? "on" : "off");
        return kv;
    };
    hh::config_ini_set("game", sec(hh_pad_game));
    hh::config_ini_set("menu", sec(hh_pad_menu));
}

bool hh::pad_cstick_enabled() {
    return hh_active_profile().cstick;
}

void hh::pad_set_cstick(bool enabled) {
    hh_pad_game.cstick = enabled;
    hh_pad_menu.cstick = enabled;
    hh_pad_save();
    fprintf(stderr, "[PAD] STICK C -> %s\n", enabled ? "on" : "off");
}

// CONTROLES -> RESET: restaura el mapeo por defecto (mando = PadProfile por defecto; teclado =
// kHHDefaultKeys) y lo persiste. Los valores por defecto tienen que coincidir con la config actual.
void hh::pad_reset_defaults() {
    hh_pad_config_load();  // asegura que el map esta inicializado antes de limpiarlo
    hh_pad_game = PadProfile{};
    hh_pad_menu = PadProfile{};
    hh_key_map.clear();
    for (const HHKeyBind& k : kHHDefaultKeys) hh_key_map[k.sc] = k.btn;
    hh_axis_key[HH_AXIS_UP] = SDL_SCANCODE_W;
    hh_axis_key[HH_AXIS_DOWN] = SDL_SCANCODE_S;
    hh_axis_key[HH_AXIS_LEFT] = SDL_SCANCODE_A;
    hh_axis_key[HH_AXIS_RIGHT] = SDL_SCANCODE_D;
    hh_axis_gp[HH_AXIS_UP] = HH_AXGP_LY_UP;
    hh_axis_gp[HH_AXIS_DOWN] = HH_AXGP_LY_DOWN;
    hh_axis_gp[HH_AXIS_LEFT] = HH_AXGP_LX_LEFT;
    hh_axis_gp[HH_AXIS_RIGHT] = HH_AXGP_LX_RIGHT;
    hh_key_save();
    hh_pad_save();
    fprintf(stderr, "[PAD] RESET: cup=%s/%s cdown=%s/%s\n",
            hh::pad_binding_gamepad("cup").c_str(), hh::pad_binding_key("cup").c_str(),
            hh::pad_binding_gamepad("cdown").c_str(), hh::pad_binding_key("cdown").c_str());
}

std::string hh::pad_binding_desc(const std::string& action_key) {
    hh_pad_config_load();  // asegura la config aunque el menu se construya antes del primer poll
    bool ok = false;
    const n64_button target = hh_pad_button_by_name(action_key, ok);
    if (!ok || target == 0) return "-";
    const PadProfile& p = hh_active_profile();
    std::string out;
    auto add = [&out](const char* n) {
        if (!out.empty()) out += " / ";
        out += n;
    };
    if (p.a == target) add("A");
    if (p.b == target) add("B");
    if (p.x == target) add("X");
    if (p.y == target) add("Y");
    if (p.lb == target) add("LB");
    if (p.rb == target) add("RB");
    if (p.back == target) add("BACK");
    if (p.start == target) add("START");
    if (p.dup == target) add("D-UP");
    if (p.ddown == target) add("D-DOWN");
    if (p.dleft == target) add("D-LEFT");
    if (p.dright == target) add("D-RIGHT");
    for (const auto& kv : hh_key_map) {
        if (kv.second == target) add(hh_scancode_display(kv.first).c_str());
    }
    return out.empty() ? std::string("-") : out;
}

// Binding PRIMARIO de MANDO de una accion (el primer campo del perfil que la tenga), o "-".
std::string hh::pad_binding_gamepad(const std::string& action_key) {
    hh_pad_config_load();
    const int axis = hh_axis_by_name(action_key);
    if (axis >= 0) return hh_axis_gp_name(hh_axis_gp[axis]);
    bool ok = false;
    const n64_button target = hh_pad_button_by_name(action_key, ok);
    if (!ok || target == 0) return "-";
    const PadProfile& p = hh_active_profile();
    if (p.a == target) return "A";
    if (p.b == target) return "B";
    if (p.x == target) return "X";
    if (p.y == target) return "Y";
    if (p.lb == target) return "LB";
    if (p.rb == target) return "RB";
    if (p.back == target) return "BACK";
    if (p.start == target) return "START";
    if (p.dup == target) return "D-UP";
    if (p.ddown == target) return "D-DOWN";
    if (p.dleft == target) return "D-LEFT";
    if (p.dright == target) return "D-RIGHT";
    // C-arriba/izq/der sin boton propio: los emula el STICK DERECHO (si STICK C esta en SI).
    // C-abajo es PRIMERA PERSONA (con boton propio) y no entra aqui.
    if (p.cstick) {
        if (target == CUP_BUTTON) return "C-ARRIBA";
        if (target == CLEFT_BUTTON) return "C-IZQ";
        if (target == CRIGHT_BUTTON) return "C-DER";
    }
    return "-";
}

// Binding PRIMARIO de TECLADO de una accion (el primer scancode mapeado), o "-".
std::string hh::pad_binding_key(const std::string& action_key) {
    hh_pad_config_load();
    const int axis = hh_axis_by_name(action_key);
    if (axis >= 0) return hh_scancode_display(hh_axis_key[axis]);
    bool ok = false;
    const n64_button target = hh_pad_button_by_name(action_key, ok);
    if (!ok || target == 0) return "-";
    for (const auto& kv : hh_key_map) {
        if (kv.second == target) return hh_scancode_display(kv.first);
    }
    return "-";
}

// ===== CONTROLES: reasignacion (captura del siguiente input fisico) =====
static std::string g_capture_action;
static bool g_prev_btn[SDL_CONTROLLER_BUTTON_MAX] = {};
static std::vector<uint8_t> g_prev_key(SDL_NUM_SCANCODES, 0);
// Tras asignar/cancelar se bloquea la navegacion 0.5 s para que el input de la asignacion (p. ej.
// la tecla de "atras") no ejecute su accion en los frames siguientes.
static std::chrono::steady_clock::time_point g_capture_block_until{};
constexpr int kCaptureBlockMs = 250;

static void hh_capture_end_block() {
    g_capture_block_until =
        std::chrono::steady_clock::now() + std::chrono::milliseconds(kCaptureBlockMs);
}

bool hh::pad_capture_blocking() {
    return std::chrono::steady_clock::now() < g_capture_block_until;
}

// Asigna `sc` a la accion `target`, quitando esa accion de cualquier OTRA tecla (1 tecla/accion).
static void hh_key_assign(SDL_Scancode sc, n64_button target) {
    for (auto it = hh_key_map.begin(); it != hh_key_map.end();) {
        if (it->second == target && it->first != sc) {
            it = hh_key_map.erase(it);
        } else {
            ++it;
        }
    }
    hh_key_map[sc] = target;
}

static void hh_key_save() {
    std::vector<std::pair<std::string, std::string>> kv;
    for (const auto& e : hh_key_map) {
        std::string name = SDL_GetScancodeName(e.first);
        if (name.empty()) continue;
        kv.emplace_back(name, hh_pad_button_name(e.second));
    }
    // Ejes de movimiento: `axis_up = W`, etc. (valor = nombre de tecla).
    static const char* kAxisName[HH_AXIS_COUNT] = { "axis_up", "axis_down", "axis_left", "axis_right" };
    for (int a = 0; a < HH_AXIS_COUNT; ++a) {
        const char* n = SDL_GetScancodeName(hh_axis_key[a]);
        if (n != nullptr && *n != '\0') kv.emplace_back(kAxisName[a], n);
        kv.emplace_back(std::string(kAxisName[a]) + "_gp", hh_axis_gp_name(hh_axis_gp[a]));
    }
    // Borra la seccion entera antes de reescribirla: si no, los bindings viejos (teclas que ya no
    // se usan) sobreviven y ganan al recargar (bug reportado: "MENU ..." volvia a VCAZ tras RESET).
    hh::config_ini_clear_section("keys");
    hh::config_ini_set("keys", kv);
}

// Quita la accion `target` de TODOS los campos del perfil (para que solo tenga 1 boton).
static void hh_pad_clear_action(PadProfile* p, n64_button target) {
    if (p->a == target) p->a = 0;
    if (p->b == target) p->b = 0;
    if (p->x == target) p->x = 0;
    if (p->y == target) p->y = 0;
    if (p->lb == target) p->lb = 0;
    if (p->rb == target) p->rb = 0;
    if (p->back == target) p->back = 0;
    if (p->start == target) p->start = 0;
    if (p->dup == target) p->dup = 0;
    if (p->ddown == target) p->ddown = 0;
    if (p->dleft == target) p->dleft = 0;
    if (p->dright == target) p->dright = 0;
}

// Asigna el boton fisico del mando `b` a la accion N64 `target` (en ambos perfiles), liberando el
// binding anterior de esa accion (un solo boton por accion).
static void hh_pad_set_button_field(SDL_GameControllerButton b, n64_button target) {
    for (PadProfile* p : { &hh_pad_game, &hh_pad_menu }) {
        hh_pad_clear_action(p, target);
        switch (b) {
            case SDL_CONTROLLER_BUTTON_A: p->a = target; break;
            case SDL_CONTROLLER_BUTTON_B: p->b = target; break;
            case SDL_CONTROLLER_BUTTON_X: p->x = target; break;
            case SDL_CONTROLLER_BUTTON_Y: p->y = target; break;
            case SDL_CONTROLLER_BUTTON_BACK: p->back = target; break;
            case SDL_CONTROLLER_BUTTON_START: p->start = target; break;
            case SDL_CONTROLLER_BUTTON_DPAD_UP: p->dup = target; break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN: p->ddown = target; break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT: p->dleft = target; break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: p->dright = target; break;
            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: p->lb = target; break;
            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: p->rb = target; break;
            default: break;
        }
    }
}

bool hh::pad_capture_active() {
    return !g_capture_action.empty();
}

const std::string& hh::pad_capture_action() {
    return g_capture_action;
}

void hh::pad_begin_capture(const std::string& action_key) {
    g_capture_action = action_key;
    // Snapshot del estado actual: no capturamos el input que inicio la captura (p. ej. A).
    const Uint8* kb = SDL_GetKeyboardState(nullptr);
    for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
        g_prev_key[static_cast<size_t>(sc)] = kb[sc] ? 1 : 0;
    }
    SDL_GameController* c = hh_pad_controller();
    for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; ++b) {
        g_prev_btn[b] = (c != nullptr) &&
                        (SDL_GameControllerGetButton(c, static_cast<SDL_GameControllerButton>(b)) != 0);
    }
    fprintf(stderr, "[PAD] captura para '%s' (ESC cancela)...\n", action_key.c_str());
}

void hh::pad_capture_poll() {
    if (g_capture_action.empty()) return;
    const Uint8* kb = SDL_GetKeyboardState(nullptr);
    if (kb[SDL_SCANCODE_ESCAPE]) {  // ESC cancela
        fprintf(stderr, "[PAD] captura cancelada\n");
        hh_capture_end_block();
        g_capture_action.clear();
        return;
    }
    // Ejes de movimiento: solo se reasigna el TECLADO (el mando es el stick izquierdo).
    const int axis = hh_axis_by_name(g_capture_action);
    if (axis >= 0) {
        for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
            const bool down = kb[sc] != 0;
            if (down && !g_prev_key[static_cast<size_t>(sc)]) {
                hh_axis_key[axis] = static_cast<SDL_Scancode>(sc);
                hh_key_save();
                fprintf(stderr, "[PAD] eje '%s' <- tecla %s\n", g_capture_action.c_str(),
                        hh_scancode_display(static_cast<SDL_Scancode>(sc)).c_str());
                hh_capture_end_block();
                g_capture_action.clear();
                return;
            }
        }
        // Mando: primera direccion de stick que supere el umbral (izq o der).
        SDL_GameController* c = hh_pad_controller();
        if (c != nullptr) {
            constexpr float TH = 0.6f;
            const float lx = controller_axis_to_float(
                SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX));
            const float ly = controller_axis_to_float(
                SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY));
            const float rx = controller_axis_to_float(
                SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_RIGHTX));
            const float ry = controller_axis_to_float(
                SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_RIGHTY));
            int code = HH_AXGP_NONE;
            if (ly <= -TH) code = HH_AXGP_LY_UP;       // SDL: LEFTY negativo = arriba
            else if (ly >= TH) code = HH_AXGP_LY_DOWN;
            else if (lx <= -TH) code = HH_AXGP_LX_LEFT;
            else if (lx >= TH) code = HH_AXGP_LX_RIGHT;
            else if (ry <= -TH) code = HH_AXGP_RY_UP;
            else if (ry >= TH) code = HH_AXGP_RY_DOWN;
            else if (rx <= -TH) code = HH_AXGP_RX_LEFT;
            else if (rx >= TH) code = HH_AXGP_RX_RIGHT;
            if (code != HH_AXGP_NONE) {
                hh_axis_gp[axis] = code;
                hh_key_save();
                fprintf(stderr, "[PAD] eje '%s' <- mando %s\n", g_capture_action.c_str(),
                        hh_axis_gp_name(code));
                hh_capture_end_block();
                g_capture_action.clear();
                return;
            }
        }
        for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
            g_prev_key[static_cast<size_t>(sc)] = kb[sc] ? 1 : 0;
        }
        return;
    }
    bool ok = false;
    const n64_button target = hh_pad_button_by_name(g_capture_action, ok);
    if (!ok || target == 0) {
        hh_capture_end_block();
        g_capture_action.clear();
        return;
    }
    // Teclado: primer scancode recien pulsado.
    for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
        const bool down = kb[sc] != 0;
        if (down && !g_prev_key[static_cast<size_t>(sc)]) {
            hh_key_assign(static_cast<SDL_Scancode>(sc), target);
            hh_key_save();
            fprintf(stderr, "[PAD] '%s' <- tecla %s\n", g_capture_action.c_str(),
                    hh_scancode_display(static_cast<SDL_Scancode>(sc)).c_str());
            hh_capture_end_block();
            g_capture_action.clear();
            return;
        }
    }
    // Mando: primer boton recien pulsado.
    SDL_GameController* c = hh_pad_controller();
    if (c != nullptr) {
        for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; ++b) {
            const bool down =
                SDL_GameControllerGetButton(c, static_cast<SDL_GameControllerButton>(b)) != 0;
            if (down && !g_prev_btn[b]) {
                hh_pad_set_button_field(static_cast<SDL_GameControllerButton>(b), target);
                hh_pad_save();
                fprintf(stderr, "[PAD] '%s' <- boton mando %d\n", g_capture_action.c_str(), b);
                hh_capture_end_block();
                g_capture_action.clear();
                return;
            }
        }
    }
    // Actualiza el estado previo para el siguiente frame.
    for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
        g_prev_key[static_cast<size_t>(sc)] = kb[sc] ? 1 : 0;
    }
    if (c != nullptr) {
        for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; ++b) {
            g_prev_btn[b] =
                SDL_GameControllerGetButton(c, static_cast<SDL_GameControllerButton>(b)) != 0;
        }
    }
}

// HH: inyeccion de input opt-in para runs headless (atravesar menus sin SDL/ventana).
//   HH_PRESS=start | HH_PRESS=a+start | HH_PRESS=0x1000   (mascara o nombres)
//   HH_PRESS_AT=segundos (inicio, por defecto 0), HH_PRESS_FOR=segundos (duracion, opcional)
//   HH_PRESS_SEQ="t1:botones,t2:-,..."  (cambios de estado; '-' suelta todo)
// Botones: a,b,z,start,dup,ddown,dleft,dright,l,r,cup,cdown,cleft,cright. Sin env: sin efecto.
struct HHPressEntry {
    double t;
    n64_button mask;
};

static n64_button hh_parse_buttons(const char* spec) {
    n64_button mask = 0;
    if (spec == nullptr || *spec == '\0' || (*spec == '-' && spec[1] == '\0')) {
        return 0;
    }
    if (spec[0] == '0' && (spec[1] == 'x' || spec[1] == 'X')) {
        return static_cast<n64_button>(strtoul(spec, nullptr, 16));
    }
    std::string names(spec);
    size_t pos = 0;
    while (pos <= names.size()) {
        size_t end = names.find('+', pos);
        if (end == std::string::npos) end = names.size();
        std::string name = names.substr(pos, end - pos);
        if (name == "a") mask |= A_BUTTON;
        else if (name == "b") mask |= B_BUTTON;
        else if (name == "z") mask |= Z_BUTTON;
        else if (name == "start") mask |= START_BUTTON;
        else if (name == "dup") mask |= DUP_BUTTON;
        else if (name == "ddown") mask |= DDOWN_BUTTON;
        else if (name == "dleft") mask |= DLEFT_BUTTON;
        else if (name == "dright") mask |= DRIGHT_BUTTON;
        else if (name == "l") mask |= L_BUTTON;
        else if (name == "r") mask |= R_BUTTON;
        else if (name == "cup") mask |= CUP_BUTTON;
        else if (name == "cdown") mask |= CDOWN_BUTTON;
        else if (name == "cleft") mask |= CLEFT_BUTTON;
        else if (name == "cright") mask |= CRIGHT_BUTTON;
        else fprintf(stderr, "[INJ] boton desconocido: %s\n", name.c_str());
        if (end == names.size()) break;
        pos = end + 1;
    }
    return mask;
}

static const std::vector<HHPressEntry>& hh_press_entries() {
    static const std::vector<HHPressEntry> entries = [] {
        std::vector<HHPressEntry> out;
        const char* seq = getenv("HH_PRESS_SEQ");
        if (seq != nullptr && *seq != '\0') {
            std::string s(seq);
            size_t pos = 0;
            while (pos <= s.size()) {
                size_t comma = s.find(',', pos);
                if (comma == std::string::npos) comma = s.size();
                std::string item = s.substr(pos, comma - pos);
                size_t colon = item.find(':');
                if (colon != std::string::npos) {
                    double t = strtod(item.substr(0, colon).c_str(), nullptr);
                    out.push_back({t, hh_parse_buttons(item.substr(colon + 1).c_str())});
                }
                if (comma == s.size()) break;
                pos = comma + 1;
            }
        }
        else {
            const char* press = getenv("HH_PRESS");
            if (press != nullptr && *press != '\0') {
                const char* at = getenv("HH_PRESS_AT");
                const char* dur = getenv("HH_PRESS_FOR");
                double at_s = (at != nullptr) ? strtod(at, nullptr) : 0.0;
                out.push_back({at_s, hh_parse_buttons(press)});
                if (dur != nullptr) out.push_back({at_s + strtod(dur, nullptr), 0});
            }
        }
        std::sort(out.begin(), out.end(), [](const HHPressEntry& a, const HHPressEntry& b) { return a.t < b.t; });
        return out;
    }();
    return entries;
}

static n64_button hh_injected_buttons() {
    const std::vector<HHPressEntry>& entries = hh_press_entries();
    if (entries.empty()) {
        return 0;
    }
    static const auto t0 = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
    n64_button mask = 0;
    for (const HHPressEntry& e : entries) {
        if (e.t <= elapsed) mask = e.mask;
        else break;
    }
    return mask;
}

static n64_button read_input_button() {
    n64_button input = 0;

    const Uint8* keyboard_state = SDL_GetKeyboardState(nullptr);
    const Uint32 mouse_state = SDL_GetMouseState(nullptr, nullptr);

    // Teclado (mapeo configurable: kHHDefaultKeys + overrides de [keys]). WASD = stick izquierdo
    // (se aplica en get_input). La tabla scancode->N64 la mantiene `hh_key_map`.
    for (const auto& kv : hh_key_map) {
        if (keyboard_state[kv.first]) input |= kv.second;
    }

    // Raton -> botones N64. Se desactiva SOLO mientras el Inspector de RT64 esta abierto, para que
    // los clics en su panel no entren al juego. (En el futuro, control teclado+raton: revisar.)
    if (!hh::dev_panel_open()) {
        if (mouse_state & SDL_BUTTON_LMASK) input |= A_BUTTON;
        if (mouse_state & SDL_BUTTON_RMASK) input |= B_BUTTON;
    }

    input |= hh_injected_buttons();

    return input;
}

static float controller_axis_to_float(Sint16 value) {
    return static_cast<float>(value) / 32768.0f;
}

void hh::poll_input() {
    // HH: cierre de prueba para validar el teardown sin interaccion (HH_AUTOQUIT=<segundos>).
    static const char* autquit = std::getenv("HH_AUTOQUIT");
    if (autquit != nullptr) {
        static const Uint32 t0 = SDL_GetTicks();
        Uint32 limite = (Uint32)std::atoi(autquit) * 1000u;
        if (SDL_GetTicks() - t0 >= limite) {
            std::fprintf(stderr, "[HH] HH_AUTOQUIT=%s -> ultramodern::quit()\n", autquit);
            hh::video_remember_window();  // recordar tamaño/posicion en [video]
            ultramodern::quit();
        }
    }
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                // Cierre ordenado: NO usar std::exit (destruiría std::threads joinable al
                // ejecutar destructores estáticos -> std::terminate). quit() activa la salida
                // limpia de recomp::start, que hace join de todos los hilos.
                hh::video_remember_window();  // recordar tamaño/posicion en [video]
                ultramodern::quit();
                break;
            case SDL_WINDOWEVENT:
                // Cursor oculto solo mientras la ventana del juego tiene el foco.
                if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
                    SDL_ShowCursor(SDL_DISABLE);
                }
                else if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                    SDL_ShowCursor(SDL_ENABLE);
                }
                break;
            case SDL_CONTROLLERDEVICEADDED:
                if (SDL_IsGameController(event.cdevice.which)) {
                    hh_pad_track(SDL_GameControllerOpen(event.cdevice.which));
                }
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                hh_pad_untrack(SDL_GameControllerFromInstanceID(event.cdevice.which));
                break;
            case SDL_KEYDOWN: {
                // Atajos de video en caliente (hasta que exista el menu in-game).
                const SDL_Keysym& k = event.key.keysym;
                // F1: Inspector de RT64. Lo gestiona RT64 si su hook estaba activo al arrancar
                // (`HH_DEVELOPER=1`/`[video] developer=si`); si VENTANA DEBUG se activó en caliente,
                // RT64 no instaló el hook y lo abre el port (hh::toggle_inspector).
                if (k.sym == SDLK_F1) {
                    if (hh::video_config().developer == "si" && !hh::rt64_handles_dev_keys()) {
                        hh::toggle_inspector();
                    }
                }
                else if (k.sym == SDLK_F2) {
                    // Widescreen: cicla el aspecto (expand / original / 4:3 ...).
                    hh::video_cycle_aspect();
                }
                else if (k.sym == SDLK_F3) {
                    // Ventana: borderless <-> windowed.
                    hh::video_toggle_fullscreen();
                }
                else if (k.sym == SDLK_F4) {
                    // MSAA (apenas notable a alta resolucion; por config suele bastar).
                    hh::video_cycle_msaa();
                }
                else if (k.sym == SDLK_F5 && hh::menu::debug_levels_enabled()) {
                    // CICLO DE PUNTOS (DEBUG NIVELES): punto de escena anterior.
                    hh::menu::cycle_step(-1);
                    std::fprintf(stderr, "[HH] F5 -> punto anterior\n");
                }
                else if (k.sym == SDLK_F6 && hh::menu::debug_levels_enabled()) {
                    // CICLO DE PUNTOS (DEBUG NIVELES): siguiente punto de escena.
                    hh::menu::cycle_step(+1);
                    std::fprintf(stderr, "[HH] F6 -> punto siguiente\n");
                }
                else if ((k.mod & KMOD_CTRL) && hh::menu_overlay::visible()) {
                    // A2 calibración en vivo del overlay (con el overlay visible):
                    //   Ctrl+←/→  mueve X       Ctrl+↑/↓  mueve Y
                    //   Ctrl+RePág/AvPág  escala Y   Ctrl+Inicio/Fin  escala X
                    float dx = 0.0f, dy = 0.0f, dsx = 0.0f, dsy = 0.0f;
                    if (k.sym == SDLK_LEFT)          dx  = -1.0f;
                    else if (k.sym == SDLK_RIGHT)    dx  =  1.0f;
                    else if (k.sym == SDLK_UP)       dy  = -1.0f;
                    else if (k.sym == SDLK_DOWN)     dy  =  1.0f;
                    else if (k.sym == SDLK_PAGEUP)   dsy =  0.01f;
                    else if (k.sym == SDLK_PAGEDOWN) dsy = -0.01f;
                    else if (k.sym == SDLK_HOME)     dsx = -0.01f;
                    else if (k.sym == SDLK_END)      dsx =  0.01f;
                    if (dx != 0.0f || dy != 0.0f || dsx != 0.0f || dsy != 0.0f) {
                        hh::menu_overlay::adjust(dx, dy, dsx, dsy);
                    }
                }
                else if (k.sym == SDLK_F7) {
                    // Captura pareada a demanda (widescreen fase 07b / issue #3): traza de identidades
                    // 2D de un frame -> `hh_cap_<n>.log` + imagen de la ventana -> `hh_cap_<n>.bmp`,
                    // en el mismo instante. Cada F7 abre una captura nueva; otro F7 la cancela.
                    hh::hud_capture_trigger();
                }
                else if (k.sym == SDLK_F8) {
                    // Mostrar/ocultar el MENÚ NATIVO (comparar nuestro overlay con el original). F6
                    // está ocupado por DEBUG NIVELES. Mientras el nativo está oculto el port blankea
                    // sus tablas de etiquetas (y el texto del file-select); F8 las restaura.
                    hh::menu_overlay::native_toggle();
                    std::fprintf(stderr, "[HH] F8 -> menu nativo %s\n",
                                 hh::menu_overlay::native_visible() ? "VISIBLE" : "oculto");
                }
                else if (k.sym == SDLK_KP_PLUS || k.sym == SDLK_EQUALS) {
                    // Ajuste fino del recorte del mapa (fase 07b): +1 px por lado.
                    hh::hudrewrite::map_crop_add(+1);
                }
                else if (k.sym == SDLK_KP_MINUS || k.sym == SDLK_MINUS) {
                    hh::hudrewrite::map_crop_add(-1);
                }
                else if (k.sym == SDLK_F12) {
                    // Traza de combate: activa/desactiva el registro de cambios de RDRAM para
                    // localizar el estado de SORPRESA (entrar en combate por la espalda).
                    hh::battle_trace_toggle();
                }
                else if (k.sym == SDLK_F11) {
                    // Cierre rapido (comodo a pantalla completa, sin Alt+F4).
                    std::fprintf(stderr, "[HH] F11 -> ultramodern::quit()\n");
                    hh::video_remember_window();  // recordar tamaño/posicion en [video]
                    ultramodern::quit();
                }
                else if (k.sym == SDLK_HOME && hh::menu::debug_levels_enabled()) {
                    // CICLO DE PUNTOS (DEBUG NIVELES): ejecuta el índice 0 (1-0).
                    hh::menu::cycle_reset();
                    std::fprintf(stderr, "[HH] Inicio -> punto 0\n");
                }
                else if (k.sym == SDLK_PAGEDOWN && hh::menu::debug_levels_enabled()) {
                    // CICLO DE PUNTOS (DEBUG NIVELES): +10 (siguiente bloque de área).
                    hh::menu::cycle_step_block(+1);
                    std::fprintf(stderr, "[HH] AvPag -> +10\n");
                }
                else if (k.sym == SDLK_PAGEUP && hh::menu::debug_levels_enabled()) {
                    // CICLO DE PUNTOS (DEBUG NIVELES): -10 (bloque anterior).
                    hh::menu::cycle_step_block(-1);
                    std::fprintf(stderr, "[HH] RePag -> -10\n");
                }
                else if (k.sym == SDLK_F10) {
                    // VOLVER AL MENÚ desde el gameplay (test): el idx 7 daba la intro/menú pero
                    // crashea; desactivado hasta encontrar la vía buena. Ver plan 2026-09-29.
                    std::fprintf(stderr, "[HH] F10 -> volver al menú (desactivado: idx 7 crashea)\n");
                }
            } break;
        }
    }
}


// --- Grabación/reproducción de input (HH_RECORD / HH_REPLAY) -------------------------------
// Formato de línea: <t> <buttons_hex> <x> <y>  (t = segundos desde el primer poll).
struct HHRec {
    double t;
    uint64_t vis;   // contador VI (frames de juego); 0 si el fichero es formato antiguo
    uint16_t buttons;
    float x;
    float y;
};

extern "C" uint64_t hh_get_vi_count(void);
// Diagnostico de ticks lentos (hh_slow.log): tiempos del ultimo trabajo del hilo de gfx y cola
// de mensajes externos pendientes. Ver notas de pacing / Fase 1 del plan de suavizado.
extern "C" double hh_gfx_last_send_dl_ms(void);
extern "C" double hh_gfx_last_update_ms(void);
extern "C" unsigned long long hh_get_pending_ext_msgs(void);
extern "C" unsigned long long hh_guest_busy_ms(void);
static bool hh_replay_has_vis = false;

static const std::vector<HHRec>& hh_replay_data() {
    static const std::vector<HHRec> data = [] {
        std::vector<HHRec> out;
        const char* path = getenv("HH_REPLAY");
        if (path == nullptr || *path == '\0') return out;
        std::ifstream in(path);
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream ss(line);
            HHRec r{};
            unsigned b = 0;
            uint64_t vis = 0;
            // Formato nuevo: <t> <vis> <buttons_hex> <x> <y>. Antiguo: <t> <buttons_hex> <x> <y>.
            if (ss >> r.t >> vis >> std::hex >> b >> std::dec >> r.x >> r.y) {
                r.vis = vis;
                r.buttons = static_cast<uint16_t>(b);
                hh_replay_has_vis = true;
                out.push_back(r);
            }
            else {
                std::istringstream ss2(line);
                if (ss2 >> r.t >> std::hex >> b >> std::dec >> r.x >> r.y) {
                    r.vis = 0;
                    r.buttons = static_cast<uint16_t>(b);
                    out.push_back(r);
                }
            }
        }
        fprintf(stderr, "[REPLAY] %zu muestras de %s\n", out.size(), path);
        return out;
    }();
    return data;
}

// HH: log opcional de las muestras aplicadas (HH_REPLAYLOG=1) -> hh_replay.log, para comparar 1:1
// con la grabacion (poll, VI actual, botones, x, y).
static void hh_replay_log_sample(size_t poll, uint64_t vi, const HHRec& r) {
    if (getenv("HH_REPLAYLOG") == nullptr) return;
    static FILE* f = nullptr;
    if (f == nullptr) {
        f = fopen("hh_replay.log", "w");
        if (f == nullptr) return;
    }
    fprintf(f, "%zu %llu %04X %.4f %.4f\n", poll, (unsigned long long)vi,
            (unsigned)r.buttons, r.x, r.y);
    fflush(f);
}

// HH: reproduccion de input.
//   HH_REPLAY_MODE=poll (DEFECTO): una muestra por poll (exacto por frame de juego; robusto al
//     jitter de timing porque no depende del VI).
//   HH_REPLAY_MODE=vi: elige la ultima muestra con vis <= VI actual (tolera maquinas distintas,
//     pero es sensible al jitter: un VI de diferencia aplica la muestra vecina).
//   HH_REPLAY_SYNC=vi (solo en modo poll): en el primer poll, salta al primer sample con
//     vis >= VI actual (sincroniza si el arranque consume distinto numero de polls/VI).
static void hh_replay_apply(double elapsed, n64_button& buttons, float& x, float& y) {
    (void)elapsed;
    const std::vector<HHRec>& data = hh_replay_data();
    if (data.empty()) return;
    static size_t idx = 0;
    static size_t polls = 0;
    static bool inited = false;
    static const bool mode_vi = [] {
        const char* m = getenv("HH_REPLAY_MODE");
        return m != nullptr && strcmp(m, "vi") == 0;
    }();
    static const bool sync_vi = [] {
        const char* s = getenv("HH_REPLAY_SYNC");
        return s != nullptr && strcmp(s, "vi") == 0;
    }();
    static const bool clock_mode = [] {
        const char* c = getenv("HH_REPLAY_CLOCK");
        return c != nullptr && *c != '\0' && strcmp(c, "0") != 0;
    }();
    uint64_t cur = hh_get_vi_count();
    auto sample_vis = [&](const HHRec& r) -> uint64_t {
        return hh_replay_has_vis ? r.vis : (uint64_t)(r.t * 60.0 + 0.5);
    };
    if (!inited) {
        inited = true;
        if (sync_vi && hh_replay_has_vis) {
            while (idx + 1 < data.size() && sample_vis(data[idx]) < cur) idx++;
        }
        fprintf(stderr, "[REPLAY] modo=%s sync=%d clock=%d muestras=%zu primer_vis=%llu primer_t=%.4f VI_actual=%llu\n",
                mode_vi ? "vi" : "poll", sync_vi ? 1 : 0, clock_mode ? 1 : 0, data.size(),
                (unsigned long long)sample_vis(data[0]), data[0].t, (unsigned long long)cur);
    }
    if (mode_vi) {
        while (idx + 1 < data.size() && sample_vis(data[idx + 1]) <= cur) idx++;
    }
    size_t use = idx < data.size() ? idx : data.size() - 1;
    hh_replay_set_sample((uint64_t)use);
    if (clock_mode) {
        // HH: el tiempo de juego sigue la marca temporal de la muestra grabada (fidelidad replay).
        hh_replay_clock_set(data[use].t);
    }
    // HH_REPLAY_PACE: marca el ritmo con la linea temporal grabada.
    //   1 / "wall": espera a que el reloj de pared alcance el `t` de la muestra. Fiel en tiempo
    //     real, pero en Windows el plus de espera (sub-VI) empuja el tick fuera de la ventana de
    //     2 VI -> 3 VI (50 ms) casi siempre -> 20 ticks/s y desvio (medido 2026-09-18).
    //   "vi": espera a que el contador VI del port alcance el `vis` grabado (el reloj propio del
    //     juego). Alinea el tick con la MISMA rejilla VI que la sesion original y no lo desplaza.
    static const int pace_mode = [] {
        const char* p = getenv("HH_REPLAY_PACE");
        if (p == nullptr || *p == '\0' || strcmp(p, "0") == 0) return 0;
        return (strcmp(p, "vi") == 0) ? 2 : 1;
    }();
    if (pace_mode == 2 && hh_replay_has_vis) {
        static int64_t vi_off = 0;
        static bool vi_off_set = false;
        static std::chrono::steady_clock::time_point t0;
        static bool t0_set = false;
        if (!t0_set) {
            t0_set = true;
            t0 = std::chrono::steady_clock::now();
        }
        if (!vi_off_set) {
            vi_off_set = true;
            // Offset CON SIGNO: el boot del replay puede terminar en menos VI que el de la sesion
            // original (cur_vi < vis0). Con offset 0 el primer tick esperaba los VIs que faltaban
            // (medido: 1,33 s de golpe). El objetivo es alinear el timeline RELATIVO al primer
            // poll: target_vi = vis_i + (cur_vi_0 - vis_0).
            vi_off = (int64_t)cur - (int64_t)sample_vis(data[0]);
            fprintf(stderr, "[PACE] primer ciclo: cur_vi=%llu vis0=%llu off=%lld\n",
                    (unsigned long long)cur, (unsigned long long)sample_vis(data[0]), (long long)vi_off);
        }
        const int64_t target_vi = (int64_t)sample_vis(data[use]) + vi_off;
        const auto wait_t0 = std::chrono::steady_clock::now();
        while ((int64_t)hh_get_vi_count() < target_vi) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        const double wait_ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - wait_t0).count();
        {
            const double t_now = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
            const double late = t_now - data[use].t;
            static FILE* pf = fopen("hh_pace.log", "w");
            static int n = 0, n_late = 0, n_adj = 0;
            static double acc = 0.0, mx = -1e9, last_log = 0.0;
            static double acc_wait = 0.0, acc_work = 0.0, last_call = 0.0;
            const double period = (last_call > 0.0) ? (t_now - last_call) : 0.0;
            if (period > 0.0) {
                acc_work += (period * 1000.0) - wait_ms;
            }
            acc_wait += wait_ms;
            last_call = t_now;
            n++;
            if (late > 0.005) {
                n_late++;
            }
            acc += late;
            if (late > mx) {
                mx = late;
            }
            if (t_now - last_log >= 1.0 && pf != nullptr) {
                // Correccion de fase (PLL suave): ajusta vi_off hasta que el desfase de pared
                // (late) quede cerca de 0. Sin esto, el primer tick largo del boot deja un
                // desplazamiento constante (~1 s) que adelanta los waits por tiempo.
                const double avg = acc / (double)n;
                int adj = (int)std::lround(avg * 60.0);
                if (adj > 5) {
                    adj = 5;
                }
                if (adj < -5) {
                    adj = -5;
                }
                // late > 0 = el replay va por detras del timeline grabado -> aplicar antes -> bajar
                // el offset (target_vi mas pequeno). late < 0 -> subirlo.
                vi_off -= adj;
                n_adj += (adj != 0) ? (adj > 0 ? 1 : -1) : 0;
                fprintf(pf, "t=%.1f ticks=%d late_avg=%.2fms late_max=%.2fms llegadas_tarde=%d vi_off=%lld adj=%d wait_avg=%.1fms work_avg=%.1fms\n",
                        t_now, n, avg * 1000.0, mx * 1000.0, n_late, (long long)vi_off, adj,
                        acc_wait / (double)n, acc_work / (double)n);
                fflush(pf);
                n = 0;
                n_late = 0;
                acc = 0.0;
                mx = -1e9;
                acc_wait = 0.0;
                acc_work = 0.0;
                last_log = t_now;
            }
        }
    }
    if (pace_mode == 1 && hh_replay_has_vis) {
        static std::chrono::steady_clock::time_point t0;
        static bool t0_set = false;
        const auto now = std::chrono::steady_clock::now();
        if (!t0_set) {
            t0_set = true;
            t0 = now;
        }
        const double target = data[use].t;
        const double since = std::chrono::duration<double>(now - t0).count();
        const bool arrived_late = since > target;
        if (target > since) {
            // HH: espera hibrida. En Windows sleep_for tiene granularidad ~15,6 ms: dormir el grueso
            // y girar el tramo final evita que el pacing se pase (~5-10 ms por tick -> el replay
            // corria a 22 ticks/s cuando la grabacion iba a 26, y la ruta divergia). Requiere
            // timeBeginPeriod(1) (main.cpp); sin el, el propio sleep se pasa del objetivo.
            const double remain = target - since;
            if (remain > 0.003) {
                std::this_thread::sleep_for(std::chrono::duration<double>(remain - 0.003));
            }
            while (std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count() < target) {
                // espera activa corta (precision de microsegundos)
            }
        }
        // Diagnostico del pacing (hh_pace.log, 1 linea/s): retraso por tick y cuantas veces el
        // tick llego ya tarde (work-bound). Sirve para ver en la maquina del mantenedor por que el
        // replay no sigue la grabacion.
        {
            const double after = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
            const double late = after - target;
            static FILE* pf = fopen("hh_pace.log", "w");
            static int n = 0, n_late = 0;
            static double acc = 0.0, mx = -1e9, last_log = 0.0;
            if (pf != nullptr) {
                n++;
                if (arrived_late) {
                    n_late++;
                }
                acc += late;
                if (late > mx) {
                    mx = late;
                }
                if (after - last_log >= 1.0) {
                    fprintf(pf, "t=%.1f ticks=%d late_avg=%.2fms late_max=%.2fms llegadas_tarde=%d\n",
                            after, n, acc / n * 1000.0, mx * 1000.0, n_late);
                    fflush(pf);
                    n = 0;
                    n_late = 0;
                    acc = 0.0;
                    mx = -1e9;
                    last_log = after;
                }
            }
        }
    }
    buttons = data[use].buttons;
    x = data[use].x;
    y = data[use].y;
    hh_replay_log_sample(polls, cur, data[use]);
    polls++;
    if (!mode_vi && idx + 1 < data.size()) idx++;
}

static void hh_record_write(double elapsed, n64_button buttons, float x, float y) {
    static FILE* fp = nullptr;
    static bool tried = false;
    if (!tried) {
        tried = true;
        const char* path = getenv("HH_RECORD");
        if (path == nullptr || *path == '\0') {
            fprintf(stderr, "[RECORD] HH_RECORD vacio: no se graba\n");
        }
        else {
            fp = fopen(path, "w");
            if (fp != nullptr) {
                fprintf(stderr, "[RECORD] grabando input en '%s'\n", path);
            }
            else {
                fprintf(stderr, "[RECORD] ERROR: no se pudo abrir '%s' (ruta invalida o sin permiso)\n", path);
            }
        }
    }
    if (fp != nullptr) {
        fprintf(fp, "%.4f %llu %04X %.4f %.4f\n", elapsed,
                (unsigned long long)hh_get_vi_count(), (unsigned)buttons, x, y);
        fflush(fp);
    }
}

static std::atomic<unsigned long long> hh_input_polls{0};

extern "C" unsigned long long hh_get_input_polls() {
    return hh_input_polls.load();
}

// HH: registro de TODOS los mandos SDL abiertos. Lo comparten el input (usa el primero, puerto 0) y
// la vibracion (rumba todos: J1 y J2). El hotplug se gestiona aqui (apertura perezosa del primero,
// con reintento 1/s) y en el bucle de eventos (CONTROLLERDEVICEADDED/REMOVED).
static std::vector<SDL_GameController*> g_pads;

static SDL_JoystickID hh_pad_instance(SDL_GameController* c) {
    SDL_Joystick* js = c != nullptr ? SDL_GameControllerGetJoystick(c) : nullptr;
    return js != nullptr ? SDL_JoystickInstanceID(js) : -1;
}

static void hh_pad_track(SDL_GameController* c) {
    if (c == nullptr) return;
    const SDL_JoystickID id = hh_pad_instance(c);
    for (SDL_GameController* p : g_pads) {
        if (p == c || (id >= 0 && hh_pad_instance(p) == id)) {
            SDL_GameControllerClose(c);   // ya seguido -> descartar el duplicado
            return;
        }
    }
    g_pads.push_back(c);
}

static void hh_pad_untrack(SDL_GameController* c) {
    for (auto it = g_pads.begin(); it != g_pads.end(); ++it) {
        if (*it == c) {
            SDL_GameControllerClose(*it);
            g_pads.erase(it);
            return;
        }
    }
}

// Handle del mando del puerto 0 (apertura perezosa, reintento 1/s para hotplug): el primero del
// registro. La captura/reasignacion de CONTROLES y el input normal usan este.
static SDL_GameController* hh_pad_controller() {
    static double controller_next_try = 0.0;
    for (auto it = g_pads.begin(); it != g_pads.end();) {
        if (!SDL_GameControllerGetAttached(*it)) {
            SDL_GameControllerClose(*it);
            it = g_pads.erase(it);
        } else {
            ++it;
        }
    }
    if (g_pads.empty() && SDL_NumJoysticks() > 0) {
        const auto now = std::chrono::steady_clock::now();
        const double secs = std::chrono::duration<double>(now.time_since_epoch()).count();
        if (secs >= controller_next_try) {
            controller_next_try = secs + 1.0;
            hh_pad_track(SDL_GameControllerOpen(0));
        }
    }
    return g_pads.empty() ? nullptr : g_pads.front();
}

bool hh::get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    static bool cfg_logged = false;
    if (controller_num == 0) {
        hh_input_polls.fetch_add(1, std::memory_order_relaxed);
        // HH: diagnostico de cuantizacion de tick (hh_tick.log, 1 linea/s; hh_slow.log en ticks
        // lentos). Opt-in con HH_DIAG=1: por defecto el .exe release no deja volcados. Mide si la
        // logica clava el presupuesto del original (2 VI/tick = 30,0/s) o pierde el deadline
        // (3 VI = 50 ms). Ver notas de pacing y §5e de 2026-09-17-replay-mode-vi-vis-negativo.
        if (getenv("HH_DIAG") != nullptr) {
            static FILE* tf = fopen("hh_tick.log", "w");
            if (tf != nullptr) {
                static uint64_t last_vi = 0;
                static bool vi_init = false;
                static uint64_t counts[5] = {0, 0, 0, 0, 0};
                static double max_dt = 0.0;
                static auto last_t = std::chrono::steady_clock::now();
                static auto last_log = std::chrono::steady_clock::now();
                static auto t0 = std::chrono::steady_clock::now();
                const uint64_t vi = hh_get_vi_count();
                const auto now = std::chrono::steady_clock::now();
                const double dt = std::chrono::duration<double, std::milli>(now - last_t).count();
                last_t = now;
                uint64_t d = 0;
                static unsigned long long last_busy = 0;
                if (vi_init) {
                    d = vi - last_vi;
                    counts[d < 4 ? (int)d : 4]++;
                    if (dt > max_dt) {
                        max_dt = dt;
                    }
                    // Tiempo guest ejecutado EN ESTE tick (delta respecto al tick anterior).
                    const unsigned long long busy = hh_guest_busy_ms();
                    const unsigned long long busy_tick = (last_busy != 0 && busy >= last_busy) ? (busy - last_busy) : 0;
                    last_busy = busy;
                    // Tick lento (>36 ms): desglose a hh_slow.log para saber si el tiempo se va en
                    // el hilo de gfx (send_dl/update_screen), en codigo guest o en esperas/colas.
                    if (dt > 36.0) {
                        static FILE* sf = fopen("hh_slow.log", "w");
                        if (sf != nullptr) {
                            const double t_slow = std::chrono::duration<double>(now - t0).count();
                            fprintf(sf, "t=%.1f dt=%.1fms dvi=%llu send_dl=%.1fms update_screen=%.1fms guest_busy=%llums pending_ext=%llu\n",
                                    t_slow, dt, (unsigned long long)d,
                                    hh_gfx_last_send_dl_ms(), hh_gfx_last_update_ms(),
                                    busy_tick, hh_get_pending_ext_msgs());
                            fflush(sf);
                        }
                    }
                }
                else {
                    vi_init = true;
                }
                last_vi = vi;
                const double since_log = std::chrono::duration<double>(now - last_log).count();
                if (since_log >= 1.0) {
                    const double t_log = std::chrono::duration<double>(now - t0).count();
                    const uint64_t n = counts[1] + counts[2] + counts[3] + counts[4];
                    fprintf(tf, "t=%.1f ticks=%llu d1=%llu d2=%llu d3=%llu d4+=%llu max_dt=%.1fms\n",
                            t_log, (unsigned long long)n,
                            (unsigned long long)counts[1], (unsigned long long)counts[2],
                            (unsigned long long)counts[3], (unsigned long long)counts[4], max_dt);
                    fflush(tf);
                    counts[1] = counts[2] = counts[3] = counts[4] = 0;
                    max_dt = 0.0;
                    last_log = now;
                }
            }
        }
        // HH: log de cadencia por frame de juego (HH_FRAMELOG=1) -> hh_framelog.log.
        // Formato: t_segundos dt_microsegundos vi_actual dvi guest_busy_ms (para ver si los frames
        // que se pasan de 33,3 ms consumen 3 VI en vez de 2 y cuanto tiempo guest llevan dentro;
        // ver notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md y port\run_stall_check.bat).
        if (getenv("HH_FRAMELOG") != nullptr) {
            static FILE* ff = fopen("hh_framelog.log", "w");
            if (ff != nullptr) {
                static auto t0 = std::chrono::high_resolution_clock::now();
                static auto tprev = t0;
                auto now = std::chrono::high_resolution_clock::now();
                double dus = std::chrono::duration<double, std::micro>(now - tprev).count();
                double t = std::chrono::duration<double>(now - t0).count();
                // HH: ademas del periodo, el avance de VI (dvi) y el tiempo guest ejecutado en el
                // tick (delta de hh_guest_busy_ms) para medir la alineacion frame<->VI.
                static uint64_t fl_last_vi = 0;
                static unsigned long long fl_last_busy = 0;
                const uint64_t vi = hh_get_vi_count();
                const unsigned long long busy = hh_guest_busy_ms();
                const uint64_t dvi = (fl_last_vi != 0 && vi >= fl_last_vi) ? (vi - fl_last_vi) : 0;
                const unsigned long long busy_tick =
                    (fl_last_busy != 0 && busy >= fl_last_busy) ? (busy - fl_last_busy) : 0;
                fl_last_vi = vi;
                fl_last_busy = busy;
                fprintf(ff, "%.4f %.1f %llu %llu %llu\n", t, dus, (unsigned long long)vi,
                        (unsigned long long)dvi, busy_tick);
                fflush(ff);
                tprev = now;
            }
        }
    }
    hh_pad_config_load();
    if (!cfg_logged && controller_num == 0) {
        cfg_logged = true;
        const char* iy = getenv("HH_INVERT_Y");
        const char* res = getenv("HH_RES");
        fprintf(stderr, "[CFG] HH_INVERT_Y=%s HH_RES=%s\n", iy ? iy : "(no)", res ? res : "(auto)");
    }
    n64_button input = 0;
    if (controller_num == 0) {
        input = read_input_button();
        // Lee/registra el contexto (juego/menu) aunque no haya mando conectado (tests headless).
        hh_active_profile();
    }

    float axis_x = 0.0f;
    float axis_y = 0.0f;

    SDL_GameController* controller = hh_pad_controller();
    if (controller != nullptr && controller_num == 0) {
        // Mapeo FIJO (config.ini [game]/[menu], identicos). Por defecto:
        //   A=A, B=B (atras/mapa/cancelar), X=Z (agacharse), Y=CDOWN (1a persona),
        //   Back=B (alias), Start=START, LB=L, RB=R (apuntar), cruceta=D-pad.
        // Los botones C del N64 se emulan con el STICK DERECHO (digital, umbral 0.5).
        const PadProfile& prof = hh_active_profile();
        input |= n64_button(
              SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) * prof.a
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) * prof.b
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) * prof.x
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) * prof.y
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) * prof.back
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) * prof.start
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) * prof.dup
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) * prof.ddown
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) * prof.dleft
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) * prof.dright
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) * prof.lb
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) * prof.rb);

        // Movimiento: se lee segun las FUENTES asignadas por eje (por defecto, stick izquierdo).
        {
            const float lx = controller_axis_to_float(
                SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX));
            const float lx_sdl = lx;
            const float ly_sdl = controller_axis_to_float(
                SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY));
            const float rx = controller_axis_to_float(
                SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX));
            const float ry_sdl = controller_axis_to_float(
                SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY));
            // SDL: LEFTY positivo = abajo; N64: +y = arriba. HH_INVERT_Y=1 invierte el signo.
            const char* hh_iy = getenv("HH_INVERT_Y");
            const float ly = (hh_iy != nullptr && *hh_iy != '\0') ? ly_sdl : -ly_sdl;
            const float ry = (hh_iy != nullptr && *hh_iy != '\0') ? ry_sdl : -ry_sdl;
            float gx = 0.0f, gy = 0.0f;
            for (int a = 0; a < HH_AXIS_COUNT; ++a) {
                switch (hh_axis_gp[a]) {
                    case HH_AXGP_LY_UP:    gy += std::max(0.0f, ly); break;
                    case HH_AXGP_LY_DOWN:  gy += std::min(0.0f, ly); break;
                    case HH_AXGP_LX_LEFT:  gx += std::min(0.0f, lx_sdl); break;
                    case HH_AXGP_LX_RIGHT: gx += std::max(0.0f, lx_sdl); break;
                    case HH_AXGP_RY_UP:    gy += std::max(0.0f, ry); break;
                    case HH_AXGP_RY_DOWN:  gy += std::min(0.0f, ry); break;
                    case HH_AXGP_RX_LEFT:  gx += std::min(0.0f, rx); break;
                    case HH_AXGP_RX_RIGHT: gx += std::max(0.0f, rx); break;
                    default: break;
                }
            }
            axis_x = std::clamp(gx, -1.0f, 1.0f);
            axis_y = std::clamp(gy, -1.0f, 1.0f);
        }

        // Stick derecho -> botones C (SDL: derecha/abajo positivos; N64 +y = arriba).
        // C-Down (vista en 1a persona) se deja SOLO en Y para no activarla sin querer con el stick.
        if (prof.cstick) {
            constexpr float C_THRESHOLD = 0.5f;
            float cx = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX));
            float cy = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY));
            if (cx <= -C_THRESHOLD) input |= CLEFT_BUTTON;
            if (cx >= C_THRESHOLD) input |= CRIGHT_BUTTON;
            if (cy <= -C_THRESHOLD) input |= CUP_BUTTON;
        }
    }

    // Teclado: ejes de movimiento configurables (por defecto W/S/A/D) -> stick izquierdo.
    // Convencion N64: +y = arriba.
    if (controller_num == 0) {
        const Uint8* kb = SDL_GetKeyboardState(nullptr);
        float kx = 0.0f, ky = 0.0f;
        if (kb[hh_axis_key[HH_AXIS_UP]]) ky += 1.0f;
        if (kb[hh_axis_key[HH_AXIS_DOWN]]) ky -= 1.0f;
        if (kb[hh_axis_key[HH_AXIS_LEFT]]) kx -= 1.0f;
        if (kb[hh_axis_key[HH_AXIS_RIGHT]]) kx += 1.0f;
        if (kx != 0.0f || ky != 0.0f) {
            axis_x = kx;
            axis_y = ky;
        }
    }

    // HH_STICK=x,y inyecta el stick analógico para runs headless (convención N64: +y = arriba).
    // HH_STICK_AT=<s> retrasa su aplicación (p. ej. hasta estar en gameplay, sin mover menús).
    if (controller_num == 0) {
        const char* st = getenv("HH_STICK");
            if (st != nullptr && *st != '\0') {
            bool active = true;
            if (const char* at = getenv("HH_STICK_AT")) {
                static const auto stick_t0 = std::chrono::steady_clock::now();
                double elapsed = std::chrono::duration<double>(
                    std::chrono::steady_clock::now() - stick_t0).count();
                active = elapsed >= strtod(at, nullptr);
            }
            float sx = 0.0f, sy = 0.0f;
            if (active && sscanf(st, "%f,%f", &sx, &sy) == 2) {
                axis_x = sx; axis_y = sy;
            }
        }
    }

    // HH_CSTICK=x,y inyecta el stick derecho (botones C) para runs headless, con el mismo umbral
    // digital que el mando (convención N64: +y = arriba).
    if (controller_num == 0) {
        const char* cs = getenv("HH_CSTICK");
        if (cs != nullptr && *cs != '\0') {
            float cx = 0.0f, cy = 0.0f;
            if (sscanf(cs, "%f,%f", &cx, &cy) == 2) {
                constexpr float C_THRESHOLD = 0.5f;
                if (cx <= -C_THRESHOLD) input |= CLEFT_BUTTON;
                if (cx >= C_THRESHOLD) input |= CRIGHT_BUTTON;
                if (cy >= C_THRESHOLD) input |= CUP_BUTTON;
                if (cy <= -C_THRESHOLD) input |= CDOWN_BUTTON;
            }
        }
    }

    // Reproducción/grabación de input (controller 0) para runs deterministas.
    static const auto hh_in_t0 = std::chrono::steady_clock::now();
    const double hh_elapsed = std::chrono::duration<double>(
        std::chrono::steady_clock::now() - hh_in_t0).count();
    if (controller_num == 0) {
        if (getenv("HH_REPLAY") != nullptr && *getenv("HH_REPLAY") != '\0') {
            hh_replay_apply(hh_elapsed, input, axis_x, axis_y);
        }
        else if (getenv("HH_RECORD") != nullptr && *getenv("HH_RECORD") != '\0') {
            hh_record_write(hh_elapsed, input, axis_x, axis_y);
        }
        // HH: diagnostico de causalidad del cambio de escena prematuro: enmascara el bit START
        // (0x1000) dentro de una ventana de VI (HH_MASK_START=lo:hi). Sirve para ver si, sin el
        // START que dispara la cadena en la transicion, el port llega al CaC y si sigue colgando.
        {
            static const char* ms = getenv("HH_MASK_START");
            static long mlo = -2, mhi = -2;
            if (ms != nullptr && *ms != '\0' && mlo == -2) {
                mlo = 0; mhi = 0;
                const char* c = strchr(ms, ':');
                if (c != nullptr) { mlo = strtol(ms, nullptr, 0); mhi = strtol(c + 1, nullptr, 0); }
            }
            if (mlo != -2 && (long)hh_get_vi_count() >= mlo && (long)hh_get_vi_count() <= mhi) {
                input = (n64_button)((unsigned)input & ~0x1000u);
            }
        }
    }

    // D-pad fisico -> stick izquierdo (por defecto ON; HH_DPAD_TO_STICK=0 lo desactiva): para
    // menus/UI que esperan el stick (el juego ignora el D-pad). Lee el D-pad fisico (mando +
    // flechas), no los bits N64.
    if (controller_num == 0) {
        static const bool hh_dpad_to_stick = [] {
            const char* e = getenv("HH_DPAD_TO_STICK");
            return !(e != nullptr && *e != '\0' && strcmp(e, "0") == 0);  // por defecto ON
        }();
        if (hh_dpad_to_stick) {
            const Uint8* kb = SDL_GetKeyboardState(nullptr);
            float dx = 0.0f, dy = 0.0f;
            if (controller != nullptr) {
                if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))    dy += 1.0f;
                if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN))  dy -= 1.0f;
                if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT))  dx -= 1.0f;
                if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) dx += 1.0f;
            }
            if (kb[SDL_SCANCODE_UP])    dy += 1.0f;
            if (kb[SDL_SCANCODE_DOWN])  dy -= 1.0f;
            if (kb[SDL_SCANCODE_LEFT])  dx -= 1.0f;
            if (kb[SDL_SCANCODE_RIGHT]) dx += 1.0f;
            if (dx != 0.0f || dy != 0.0f) { axis_x = dx; axis_y = dy; }
        }
    }

    // Stick izquierdo -> D-pad (para menus/UI): umbral 0.5. Desactivable con HH_STICK_TO_DPAD=0.
    // Si el juego ignora el D-pad no tiene efecto; si su UI lo usa, el stick tambien navega.
    if (controller_num == 0) {
        static const bool hh_stick_to_dpad = [] {
            const char* e = getenv("HH_STICK_TO_DPAD");
            return !(e != nullptr && *e != '\0' && strcmp(e, "0") == 0);
        }();
        if (hh_stick_to_dpad) {
            constexpr float DP_THRESHOLD = 0.5f;
            if (axis_y >= DP_THRESHOLD) input |= DUP_BUTTON;
            if (axis_y <= -DP_THRESHOLD) input |= DDOWN_BUTTON;
            if (axis_x >= DP_THRESHOLD) input |= DRIGHT_BUTTON;
            if (axis_x <= -DP_THRESHOLD) input |= DLEFT_BUTTON;
        }
    }

    if (controller_num == 0 && getenv("HH_INLOG") != nullptr && *getenv("HH_INLOG") != '\0') {
        static n64_button last_input = 0;
        static unsigned long input_calls = 0;
        static unsigned long ax_calls = 0;
        ++input_calls;
        bool changed = (input != last_input);
        if (changed || (++ax_calls % 128 == 0)) {
            last_input = input;
            fprintf(stderr, "[IN] ctrl=%d call=%lu buttons=0x%04X x=%.3f y=%.3f (stick fijado a x=%.3f y=%.3f)\n",
                    controller_num, input_calls, (unsigned)input, axis_x, axis_y, axis_x, axis_y);
        }
    }

    *buttons = input;
    *x = axis_x;
    *y = axis_y;

    // Only controller port 0 is populated. Reporting a response for every port made the
    // runtime mark absent controllers as connected (err_no == 0), which the game's boot
    // code reads to pick its initialization path. Match the original hardware/emulator:
    // the other ports report CONT_NO_RESPONSE_ERROR.
    return controller_num == 0;
}

extern "C" bool hh_input_button_down(const char* action_key) {
    if (action_key == nullptr) return false;
    hh_pad_config_load();
    bool ok = false;
    const n64_button target = hh_pad_button_by_name(action_key, ok);
    if (!ok || target == 0) return false;
    return (read_input_button() & target) != 0;
}

void hh::set_rumble(int controller_num, bool rumble) {
    // HH: la vibracion es GLOBAL: vibran todos los mandos conectados (J1 y J2 a la vez), tal como
    // se quiere en el modo local. `controller_num` se ignora a proposito; el registro de mandos lo
    // mantiene el bucle de eventos / hh_pad_controller (apertura perezosa del primero).
    (void)controller_num;
    hh_pad_controller();
    for (SDL_GameController* c : g_pads) {
        if (rumble) {
            // Duracion larga: el juego lo para con set_rumble(false) (osMotorStop).
            SDL_GameControllerRumble(c, 0xFFFF, 0xFFFF, 5000);
        } else {
            SDL_GameControllerRumble(c, 0, 0, 0);
        }
    }
}

ultramodern::input::connected_device_info_t hh::get_connected_device_info(int controller_num) {
    // Controller port 0 is always reported as a connected standard controller. This matches the
    // original hardware's boot state (and the reference emulator's input plugin): the game reads
    // the SI bit pattern during boot to decide its initialization path, and a missing controller
    // there sends it down a different branch. Physical input is still read via SDL in get_input.
    bool connected = (controller_num == 0);

    ultramodern::input::connected_device_info_t result{};
    result.connected_device = ultramodern::input::Device::None;
    result.connected_pak = ultramodern::input::Pak::None;

    if (connected) {
        result.connected_device = ultramodern::input::Device::Controller;
        // Rumble Pak si la vibracion esta activada (CONTROLES -> VIBRACION).
        result.connected_pak = hh::input_vibration_enabled() ? ultramodern::input::Pak::RumblePak
                                                             : ultramodern::input::Pak::None;
    }

    // HH: diagnostico de accesorios -> hh_pak.log (una linea por puerto; ver hh_paklog.hpp).
    {
        static bool logged[4] = {false, false, false, false};
        if (controller_num >= 0 && controller_num < 4 && !logged[controller_num]) {
            logged[controller_num] = true;
            hh_paklog("get_connected_device_info port=%d -> dev=%d pak=%d", controller_num,
                      (int)result.connected_device, (int)result.connected_pak);
        }
    }

    return result;
}