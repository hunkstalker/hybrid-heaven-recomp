#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
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

#include "ultramodern/input.hpp"
#include "ultramodern/ultramodern.hpp"

#include "hh.h"

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

    if (keyboard_state[SDL_SCANCODE_UP]) input |= DUP_BUTTON;
    if (keyboard_state[SDL_SCANCODE_DOWN]) input |= DDOWN_BUTTON;
    if (keyboard_state[SDL_SCANCODE_LEFT]) input |= DLEFT_BUTTON;
    if (keyboard_state[SDL_SCANCODE_RIGHT]) input |= DRIGHT_BUTTON;

    if (keyboard_state[SDL_SCANCODE_S]) input |= A_BUTTON;
    if (keyboard_state[SDL_SCANCODE_X]) input |= B_BUTTON;
    if (keyboard_state[SDL_SCANCODE_Z]) input |= Z_BUTTON;
    if (keyboard_state[SDL_SCANCODE_C]) input |= L_BUTTON;
    if (keyboard_state[SDL_SCANCODE_V]) input |= R_BUTTON;
    if (keyboard_state[SDL_SCANCODE_RETURN]) input |= START_BUTTON;

    if (keyboard_state[SDL_SCANCODE_I]) input |= CUP_BUTTON;
    if (keyboard_state[SDL_SCANCODE_K]) input |= CDOWN_BUTTON;
    if (keyboard_state[SDL_SCANCODE_J]) input |= CLEFT_BUTTON;
    if (keyboard_state[SDL_SCANCODE_L]) input |= CRIGHT_BUTTON;

    if (mouse_state & SDL_BUTTON_LMASK) input |= A_BUTTON;
    if (mouse_state & SDL_BUTTON_RMASK) input |= B_BUTTON;

    input |= hh_injected_buttons();

    return input;
}

static float controller_axis_to_float(Sint16 value) {
    return static_cast<float>(value) / 32768.0f;
}

void hh::poll_input() {
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                // Cierre ordenado: NO usar std::exit (destruiría std::threads joinable al
                // ejecutar destructores estáticos -> std::terminate). quit() activa la salida
                // limpia de recomp::start, que hace join de todos los hilos.
                ultramodern::quit();
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

static void hh_replay_apply(double elapsed, n64_button& buttons, float& x, float& y) {
    (void)elapsed;
    const std::vector<HHRec>& data = hh_replay_data();
    if (data.empty()) return;
    // Reproducción por ÍNDICE de poll (no por tiempo): el juego poll-ea una vez por frame, así que
    // la misma secuencia de muestras produce la misma entrada por frame (determinista).
    static size_t idx = 0;
    // Alineado por VI (frames). Si el fichero no trae contador, se estima vis=t*60.
    uint64_t cur = hh_get_vi_count();
    auto sample_vis = [&](const HHRec& r) -> uint64_t {
        return hh_replay_has_vis ? r.vis : (uint64_t)(r.t * 60.0 + 0.5);
    };
    while (idx + 1 < data.size() && sample_vis(data[idx + 1]) <= cur) idx++;
    size_t use = idx < data.size() ? idx : data.size() - 1;
    buttons = data[use].buttons;
    x = data[use].x;
    y = data[use].y;
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

bool hh::get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    static bool cfg_logged = false;
    if (!cfg_logged && controller_num == 0) {
        cfg_logged = true;
        const char* iy = getenv("HH_INVERT_Y");
        const char* res = getenv("HH_RES");
        fprintf(stderr, "[CFG] HH_INVERT_Y=%s HH_RES=%s\n", iy ? iy : "(no)", res ? res : "(auto)");
        fprintf(stderr, "[PAD] A=salto  B=agacharse(Z)  Back/Select=mapa(B)  Start=START  LB=L  RB=apuntar(R)  Y=C-Up(1a persona)  X=B (menus de combate)  stick-dcho=botones C  cruceta=D-pad\n");
    }
    n64_button input = 0;
    if (controller_num == 0) {
        input = read_input_button();
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
        // Mapeo moderno (decidido con el usuario 2026-09-15):
        //   A -> A (salto/accion), B -> Z (agacharse), Back/Select -> B (mapa),
        //   Start -> START, LB -> L, RB -> R (apuntar), cruceta -> D-pad.
        //   Los botones C del N64 se emulan con el STICK DERECHO (digital, umbral 0.5).
        input |= n64_button(
              SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) * A_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) * Z_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) * B_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) * START_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) * DUP_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) * DDOWN_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) * DLEFT_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) * DRIGHT_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) * L_BUTTON
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) * R_BUTTON
            // C-Up tambien en Y: es una accion puntual (vista en primera persona) y resulta mas
            // comoda en boton que "empujando" el stick derecho hacia arriba.
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) * CUP_BUTTON
            // X -> B del N64: en exploracion abre el mapa (duplicado con Select, inofensivo) y en
            // combate el juego usa ese mismo B para los menus de acciones cuerpo a cuerpo.
            | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) * B_BUTTON);

        axis_x = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX));
        // SDL: LEFTY positivo = abajo; N64: stick_y positivo = arriba -> negar.
        // HH_INVERT_Y=1 invierte el signo (por si el mando lo requiere al revés).
        float raw_y = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY));
        const char* hh_iy = getenv("HH_INVERT_Y");
        axis_y = (hh_iy != nullptr && *hh_iy != '\0') ? raw_y : -raw_y;

        // Stick derecho -> botones C (SDL: derecha/abajo positivos; N64 +y = arriba).
        constexpr float C_THRESHOLD = 0.5f;
        float cx = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX));
        float cy = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY));
        if (cx <= -C_THRESHOLD) input |= CLEFT_BUTTON;
        if (cx >= C_THRESHOLD) input |= CRIGHT_BUTTON;
        if (cy <= -C_THRESHOLD) input |= CUP_BUTTON;
        if (cy >= C_THRESHOLD) input |= CDOWN_BUTTON;
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

    return result;
}