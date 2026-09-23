#include <algorithm>
#include <cctype>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
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
#include "hh/hudrewrite.h"

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
        char line[512];
        while (fgets(line, sizeof(line), f) != nullptr) {
            std::string s(line);
            size_t cut = s.find_first_of("#;");
            if (cut != std::string::npos) s = s.substr(0, cut);
            s = hh_pad_trim(s);
            if (s.empty()) continue;
            if (s.front() == '[' && s.back() == ']') {
                std::string sec = hh_pad_trim(s.substr(1, s.size() - 2));
                cur = (sec == "menu") ? &hh_pad_menu : ((sec == "game") ? &hh_pad_game : nullptr);
                continue;
            }
            size_t eq = s.find('=');
            if (eq == std::string::npos || cur == nullptr) continue;
            std::string key = hh_pad_trim(s.substr(0, eq));
            std::string val = hh_pad_trim(s.substr(eq + 1));
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

    // D-pad por flechas (extra de teclado).
    if (keyboard_state[SDL_SCANCODE_UP]) input |= DUP_BUTTON;
    if (keyboard_state[SDL_SCANCODE_DOWN]) input |= DDOWN_BUTTON;
    if (keyboard_state[SDL_SCANCODE_LEFT]) input |= DLEFT_BUTTON;
    if (keyboard_state[SDL_SCANCODE_RIGHT]) input |= DRIGHT_BUTTON;

    // Layout de teclado (espejo del mando). WASD = stick izquierdo (se aplica en get_input).
    //   H = X fisico -> Z (agacharse); J = A; K = B (atras/mapa); L = Y -> C-Down;
    //   U/I = LB/RB -> L/R; O/P = LT/RT -> Z/R (alias); Enter = Start.
    if (keyboard_state[SDL_SCANCODE_H]) input |= Z_BUTTON;
    if (keyboard_state[SDL_SCANCODE_J]) input |= A_BUTTON;
    if (keyboard_state[SDL_SCANCODE_K]) input |= B_BUTTON;
    if (keyboard_state[SDL_SCANCODE_L]) input |= CDOWN_BUTTON;
    if (keyboard_state[SDL_SCANCODE_U]) input |= L_BUTTON;
    if (keyboard_state[SDL_SCANCODE_I]) input |= R_BUTTON;
    if (keyboard_state[SDL_SCANCODE_O]) input |= Z_BUTTON;
    if (keyboard_state[SDL_SCANCODE_P]) input |= R_BUTTON;
    if (keyboard_state[SDL_SCANCODE_RETURN]) input |= START_BUTTON;

    if (mouse_state & SDL_BUTTON_LMASK) input |= A_BUTTON;
    if (mouse_state & SDL_BUTTON_RMASK) input |= B_BUTTON;

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
                    SDL_GameControllerOpen(event.cdevice.which);
                }
                break;
            case SDL_CONTROLLERDEVICEREMOVED: {
                SDL_GameController* controller = SDL_GameControllerFromInstanceID(event.cdevice.which);
                if (controller != nullptr) {
                    SDL_GameControllerClose(controller);
                }
            } break;
            case SDL_KEYDOWN: {
                // Atajos de video en caliente (hasta que exista el menu in-game).
                const SDL_Keysym& k = event.key.keysym;
                // F1 queda libre: con `HH_DEVELOPER=1` RT64 abre su Inspector (FPS/frametimes) con F1.
                if (k.sym == SDLK_F2) {
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
                else if (k.sym == SDLK_F5) {
                    // Idioma: cicla entre los disponibles (base del selector, ADR 0008) y lo aplica
                    // en vivo a lo ya cargado. Se persiste en config.ini [lang].
                    hh::text_cycle_language();
                }
                else if (k.sym == SDLK_KP_PLUS || k.sym == SDLK_EQUALS) {
                    // Ajuste fino del recorte del mapa (fase 07b): +1 px por lado.
                    hh::hudrewrite::map_crop_add(+1);
                }
                else if (k.sym == SDLK_KP_MINUS || k.sym == SDLK_MINUS) {
                    hh::hudrewrite::map_crop_add(-1);
                }
                else if (k.sym == SDLK_F11) {
                    // Cierre rapido (comodo a pantalla completa, sin Alt+F4).
                    std::fprintf(stderr, "[HH] F11 -> ultramodern::quit()\n");
                    ultramodern::quit();
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

bool hh::get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    static bool cfg_logged = false;
    if (controller_num == 0) {
        hh_input_polls.fetch_add(1, std::memory_order_relaxed);
        // HH: diagnostico de cuantizacion de tick (hh_tick.log, 1 linea/s): cuantos ticks caen en
        // 1/2/3/4+ VI y el periodo maximo. Mide si la logica clava el presupuesto del original
        // (2 VI/tick = 30,0/s) o pierde el deadline (3 VI = 50 ms). Ver notas de pacing y §5e de
        // 2026-09-17-replay-mode-vi-vis-negativo.
        {
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

    // Handle cacheado: abrir el mando en cada poll filtraba handles (fuga) y ademas era costoso.
    // Se reintenta abrir como maximo una vez por segundo si no hay mando (hotplug).
    static SDL_GameController* controller = nullptr;
    static double controller_next_try = 0.0;
    if (controller != nullptr && !SDL_GameControllerGetAttached(controller)) {
        SDL_GameControllerClose(controller);
        controller = nullptr;
    }
    if (controller == nullptr && SDL_NumJoysticks() > 0) {
        const auto now = std::chrono::steady_clock::now();
        const double secs = std::chrono::duration<double>(now.time_since_epoch()).count();
        if (secs >= controller_next_try) {
            controller_next_try = secs + 1.0;
            controller = SDL_GameControllerOpen(0);
        }
    }
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

        axis_x = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX));
        // SDL: LEFTY positivo = abajo; N64: stick_y positivo = arriba -> negar.
        // HH_INVERT_Y=1 invierte el signo (por si el mando lo requiere al revés).
        float raw_y = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY));
        const char* hh_iy = getenv("HH_INVERT_Y");
        axis_y = (hh_iy != nullptr && *hh_iy != '\0') ? raw_y : -raw_y;

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

    // Teclado: WASD = stick izquierdo (movimiento). Convencion N64: +y = arriba.
    if (controller_num == 0) {
        const Uint8* kb = SDL_GetKeyboardState(nullptr);
        float kx = 0.0f, ky = 0.0f;
        if (kb[SDL_SCANCODE_W]) ky += 1.0f;
        if (kb[SDL_SCANCODE_S]) ky -= 1.0f;
        if (kb[SDL_SCANCODE_A]) kx -= 1.0f;
        if (kb[SDL_SCANCODE_D]) kx += 1.0f;
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

void hh::set_rumble(int controller_num, bool rumble) {
    (void)controller_num;
    (void)rumble;
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
        result.connected_pak = ultramodern::input::Pak::None;
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