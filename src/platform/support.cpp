#include <cinttypes>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <atomic>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <string>
#include <vector>

#ifdef _WIN32
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_syswm.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
#endif

#ifdef None
#undef None
#endif

#include "ultramodern/ultramodern.hpp"

#include "librecomp/rsp.hpp"

#include "hh.h"
#include "hh/config_ini.h"

static FILE* g_log_file = nullptr;
static std::filesystem::path g_log_path;
static bool g_log_started = false;

static void ensure_log_open() {
    if (g_log_file == nullptr) {
        g_log_path = hh::get_app_folder_path() / "hh.log";
        // Truncate on first open so each run starts fresh.
        g_log_file = std::fopen(g_log_path.string().c_str(), "w");
    }
}

static void log_timestamp(FILE* f) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    char buf[32];
    std::strftime(buf, sizeof(buf), "%H:%M:%S", &tm);
    std::fprintf(f, "[%s.%03u] ", buf, (unsigned)ms.count());
}

void hh::log(const char* fmt, ...) {
    ensure_log_open();
    if (g_log_file == nullptr) {
        return;
    }
    log_timestamp(g_log_file);
    va_list args;
    va_start(args, fmt);
    std::vfprintf(g_log_file, fmt, args);
    va_end(args);
    std::fflush(g_log_file);
}

const char* hh::get_version_string() {
    static const std::string version =
        std::to_string(hh::kVersionMajor) + "." + std::to_string(hh::kVersionMinor) + "." +
        std::to_string(hh::kVersionPatch);
    return version.c_str();
}

static std::filesystem::path get_executable_path() {
#ifdef _WIN32
    wchar_t module_name[MAX_PATH];
    GetModuleFileNameW(NULL, module_name, MAX_PATH);
    return std::filesystem::path(module_name);
#else
    // OJO: "/proc/self/exe" es un enlace; hay que resolverlo para que parent_path() sea la carpeta
    // real del ejecutable (si no, parent_path() da "/proc/self" y cualquier sonda de escritura falla).
    std::error_code ec;
    std::filesystem::path resolved = std::filesystem::canonical("/proc/self/exe", ec);
    if (!ec && !resolved.empty()) {
        return resolved;
    }
    return std::filesystem::path("/proc/self/exe");
#endif
}

static bool hh_dir_writable(const std::filesystem::path& dir) {
    std::error_code ec;
    std::filesystem::create_directories(dir, ec);
    const std::filesystem::path probe = dir / ".hh_write_probe";
    if (FILE* f = std::fopen(probe.string().c_str(), "wb")) {
        std::fputc('x', f);
        std::fclose(f);
        std::filesystem::remove(probe, ec);
        return true;
    }
    return false;
}

// Carpeta de datos del port (saves/, hh.log, mods/ del runtime). **Portable por defecto**: junto al
// .exe, creando ahí `saves/`. Si esa carpeta no es escribible (p. ej. Program Files, un USB de solo
// lectura), cae a la carpeta de datos del usuario. HH_DATA_DIR=<ruta> lo fuerza.
std::filesystem::path hh::get_app_folder_path() {
    static const std::filesystem::path folder = []() -> std::filesystem::path {
        if (const char* env = std::getenv("HH_DATA_DIR"); env != nullptr && *env != '\0') {
            std::filesystem::path forced(env);
            std::error_code ec;
            std::filesystem::create_directories(forced, ec);
            return forced;
        }
        const std::filesystem::path exe_dir = std::filesystem::path(get_executable_path()).parent_path();
        if (!exe_dir.empty() && hh_dir_writable(exe_dir)) {
            return exe_dir;
        }
#ifdef _WIN32
        const char* appdata = std::getenv("APPDATA");
        std::filesystem::path base = (appdata != nullptr) ? std::filesystem::path(appdata) : exe_dir;
        std::filesystem::path fallback = base / "HybridHeavenRecomp";
#elif defined(__linux__) || defined(__APPLE__)
        std::filesystem::path base;
        if (const char* xdg = std::getenv("XDG_DATA_HOME"); xdg != nullptr && *xdg != '\0') {
            base = std::filesystem::path(xdg);
        }
        else if (const char* home = std::getenv("HOME"); home != nullptr) {
            base = std::filesystem::path(home) / ".local" / "share";
        }
        else {
            base = std::filesystem::temp_directory_path();
        }
        std::filesystem::path fallback = base / "HybridHeavenRecomp";
#else
#error "Unsupported platform"
#endif
        std::error_code ec;
        std::filesystem::create_directories(fallback, ec);
        return fallback;
    }();
    return folder;
}

static bool has_z64_extension(const std::filesystem::path& path) {
    std::string ext = path.extension().string();
    std::transform(ext.begin(), ext.end(), ext.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return ext == ".z64";
}

// ROMs candidatas: cualquier `*.z64` en `<carpeta del .exe>/rom/` (primero) y en la propia carpeta
// del .exe, ordenadas alfabéticamente. NO se busca en el directorio de lanzamiento (CWD): la carpeta
// del ejecutable es la referencia portable. El nombre da igual (se valida por hash al cargar).
static std::vector<std::filesystem::path> get_rom_candidates() {
    const std::filesystem::path exe_dir = std::filesystem::path(get_executable_path()).parent_path();
    std::vector<std::filesystem::path> candidates;
    for (const std::filesystem::path& dir : { exe_dir / "rom", exe_dir }) {
        std::error_code ec;
        if (!std::filesystem::is_directory(dir, ec)) {
            continue;
        }
        std::vector<std::filesystem::path> found;
        for (const auto& entry : std::filesystem::directory_iterator(dir, ec)) {
            if (entry.is_regular_file(ec) && has_z64_extension(entry.path())) {
                found.push_back(entry.path());
            }
        }
        std::sort(found.begin(), found.end());
        candidates.insert(candidates.end(), found.begin(), found.end());
    }
    return candidates;
}

std::vector<std::filesystem::path> hh::get_rom_paths() {
    return get_rom_candidates();
}

std::filesystem::path hh::get_rom_path() {
    const std::vector<std::filesystem::path> candidates = get_rom_candidates();
    return candidates.empty() ? std::filesystem::path{} : candidates.front();
}

SDL_Window* window;

void hh::error_box(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    if (window != nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Hybrid Heaven", msg, window);
    }
}

std::string hh::get_game_thread_name(const OSThread* t) {
    std::string name = "[Game] ";
    switch (t->id) {
        case 0:
            name += "KERNEL";
            break;
        case 1:
            name += "INIT";
            break;
        case 2:
            name += "MANAGER";
            break;
        default:
            name += std::to_string(t->id);
            break;
    }
    return name;
}

// HH: inicializa SOLO el subsistema de audio. Debe llamarse ANTES de hh::reset_audio(), que en
// main corre antes de recomp::start (y create_gfx se ejecuta dentro de recomp::start).
void hh::init_audio() {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "Aviso: audio SDL no inicializado (%s); el juego correra sin sonido\n",
                SDL_GetError());
    }
    else {
        fprintf(stdout, "SDL Audio Driver: %s\n", SDL_GetCurrentAudioDriver());
        fflush(stdout);
    }
}

// ===== Config de video (config.ini [video]) =====
// Lee [video] del mismo config.ini del mando (o HH_PAD_CONFIG). Defaults: borderless, resolucion
// nativa, aspecto auto, MSAA 8x. Atajos en caliente: Alt+Enter (ventana), F1 (aspecto), F2 (MSAA).
static std::string hh_video_trim(const std::string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return {};
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}
static std::string hh_video_lower(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

hh::VideoConfig& hh::video_config_mutable() {
    static hh::VideoConfig cfg = [] {
        hh::VideoConfig c;
        const char* env = getenv("HH_PAD_CONFIG");
        std::string path = (env != nullptr && *env != '\0') ? env : "config.ini";
        FILE* f = fopen(path.c_str(), "rb");
        if (f == nullptr) return c;
        char line[512];
        bool in_video = false;
        while (fgets(line, sizeof line, f) != nullptr) {
            std::string s = hh_video_trim(line);
            if (s.empty() || s[0] == '#' || s[0] == ';') continue;
            if (s[0] == '[') { in_video = (s.rfind("[video]", 0) == 0); continue; }
            if (!in_video) continue;
            size_t eq = s.find('=');
            if (eq == std::string::npos) continue;
            std::string k = hh_video_lower(hh_video_trim(s.substr(0, eq)));
            std::string v = hh_video_lower(hh_video_trim(s.substr(eq + 1)));
            if (k == "wm") c.wm = v;
            else if (k == "res") c.res = v;
            else if (k == "aspect") c.aspect = v;
            else if (k == "msaa") c.msaa = v;
            else if (k == "vsync") c.vsync = v;
            else if (k == "fps") c.fps = v;
            else if (k == "showfps") c.showfps = v;
        }
        fclose(f);
        return c;
    }();
    return cfg;
}
const hh::VideoConfig& hh::video_config() { return hh::video_config_mutable(); }

int hh::desktop_height() {
    SDL_DisplayMode dm{};
    if (SDL_GetDesktopDisplayMode(0, &dm) == 0 && dm.h > 0) return dm.h;
    if (SDL_GetCurrentDisplayMode(0, &dm) == 0 && dm.h > 0) return dm.h;
    return 1080;
}

static ultramodern::renderer::WindowMode hh_video_window_mode() {
    return (hh::video_config().wm == "windowed") ? ultramodern::renderer::WindowMode::Windowed
                                                 : ultramodern::renderer::WindowMode::Fullscreen;
}
static ultramodern::renderer::AspectRatio hh_video_aspect_mode() {
    const std::string& a = hh::video_config().aspect;
    if (a == "original") return ultramodern::renderer::AspectRatio::Original;
    if (a == "expand" || a == "auto") return ultramodern::renderer::AspectRatio::Expand;
    return ultramodern::renderer::AspectRatio::Manual;
}
static ultramodern::renderer::Antialiasing hh_video_msaa_mode() {
    const std::string& m = hh::video_config().msaa;
    if (m == "off" || m == "none" || m == "0") return ultramodern::renderer::Antialiasing::None;
    if (m == "2x") return ultramodern::renderer::Antialiasing::MSAA2X;
    if (m == "4x") return ultramodern::renderer::Antialiasing::MSAA4X;
    return ultramodern::renderer::Antialiasing::MSAA8X;
}
// LÍMITE DE FPS: "nativo" = refresco del monitor (Display); un número = tasa fija (Manual:<hz>).
static ultramodern::renderer::RefreshRate hh_video_refresh_mode(int& manual_hz) {
    const std::string& f = hh::video_config().fps;
    if (f.empty() || f == "nativo" || f == "native") return ultramodern::renderer::RefreshRate::Display;
    const int hz = std::atoi(f.c_str());
    if (hz <= 0) return ultramodern::renderer::RefreshRate::Display;
    manual_hz = hz;
    return ultramodern::renderer::RefreshRate::Manual;
}

void hh::video_apply_config() {
    ultramodern::renderer::GraphicsConfig cfg = ultramodern::renderer::get_graphics_config();
    cfg.wm_option = hh_video_window_mode();
    cfg.ar_option = hh_video_aspect_mode();
    cfg.msaa_option = hh_video_msaa_mode();
    int manual_hz = 0;
    cfg.rr_option = hh_video_refresh_mode(manual_hz);
    cfg.rr_manual_value = manual_hz;
    ultramodern::renderer::set_graphics_config(cfg);
    fprintf(stderr, "[VIDEO] wm=%s res=%s aspect=%s msaa=%s vsync=%s fps=%s\n",
            hh::video_config().wm.c_str(), hh::video_config().res.c_str(),
            hh::video_config().aspect.c_str(), hh::video_config().msaa.c_str(),
            hh::video_config().vsync.c_str(), hh::video_config().fps.c_str());
}

void hh::video_toggle_fullscreen() {
    ultramodern::renderer::GraphicsConfig cfg = ultramodern::renderer::get_graphics_config();
    cfg.wm_option = (cfg.wm_option == ultramodern::renderer::WindowMode::Fullscreen)
                        ? ultramodern::renderer::WindowMode::Windowed
                        : ultramodern::renderer::WindowMode::Fullscreen;
    hh::video_config_mutable().wm = (cfg.wm_option == ultramodern::renderer::WindowMode::Fullscreen)
                                        ? "borderless" : "windowed";
    ultramodern::renderer::set_graphics_config(cfg);
    fprintf(stderr, "[VIDEO] F3 -> wm=%s\n", hh::video_config().wm.c_str());
}

void hh::video_config_save() {
    const hh::VideoConfig& v = hh::video_config();
    hh::config_ini_set("video",
                       {{"wm", v.wm}, {"vsync", v.vsync}, {"fps", v.fps}, {"showfps", v.showfps}});
}

// Menu DEBUG -> MOSTRAR FPS: indicador de FPS del overlay (solo números, arriba-izquierda). El
// render hook lo lee de la config por frame (update_screen), así que solo hace falta persistir.
void hh::video_set_show_fps(bool enabled) {
    hh::video_config_mutable().showfps = enabled ? "si" : "no";
    hh::video_config_save();
    fprintf(stderr, "[VIDEO] MOSTRAR FPS -> %s\n", hh::video_config().showfps.c_str());
}

// Menu GRÁFICOS -> P. COMPLETA: fija el modo de ventana (borderless/windowed). El cambio se aplica
// en el hilo de render (set_graphics_config -> update_config), igual que los atajos F2/F3/F4.
void hh::video_set_fullscreen(bool enabled) {
    ultramodern::renderer::GraphicsConfig cfg = ultramodern::renderer::get_graphics_config();
    cfg.wm_option = enabled ? ultramodern::renderer::WindowMode::Fullscreen
                            : ultramodern::renderer::WindowMode::Windowed;
    hh::video_config_mutable().wm = enabled ? "borderless" : "windowed";
    ultramodern::renderer::set_graphics_config(cfg);
    hh::video_config_save();
    fprintf(stderr, "[VIDEO] P. COMPLETA -> wm=%s\n", hh::video_config().wm.c_str());
}

// Menu GRÁFICOS -> LÍMITE DE FPS: fija el refresh rate de RT64 ("nativo" = monitor; número = tasa).
void hh::video_set_fps_limit(int hz) {
    hh::video_config_mutable().fps = (hz > 0) ? std::to_string(hz) : std::string("nativo");
    ultramodern::renderer::GraphicsConfig cfg = ultramodern::renderer::get_graphics_config();
    int manual_hz = 0;
    cfg.rr_option = hh_video_refresh_mode(manual_hz);
    cfg.rr_manual_value = manual_hz;
    ultramodern::renderer::set_graphics_config(cfg);
    hh::video_config_save();
    fprintf(stderr, "[VIDEO] LÍMITE DE FPS -> %s\n", hh::video_config().fps.c_str());
}

void hh::video_cycle_aspect() {
    hh::VideoConfig& vc = hh::video_config_mutable();
    static const char* modes[] = { "original", "expand", "4:3", "21:9" };
    int idx = 0;
    for (int i = 0; i < 4; ++i) if (vc.aspect == modes[i]) { idx = i; break; }
    idx = (idx + 1) & 3;
    vc.aspect = modes[idx];
    if (idx == 2) vc.aspect_target = 4.0 / 3.0;
    else if (idx == 3) vc.aspect_target = 21.0 / 9.0;
    ultramodern::renderer::GraphicsConfig cfg = ultramodern::renderer::get_graphics_config();
    cfg.ar_option = (idx == 0) ? ultramodern::renderer::AspectRatio::Original
                  : (idx == 1) ? ultramodern::renderer::AspectRatio::Expand
                               : ultramodern::renderer::AspectRatio::Manual;
    ultramodern::renderer::set_graphics_config(cfg);
    fprintf(stderr, "[VIDEO] F1 -> aspect=%s\n", vc.aspect.c_str());
}

void hh::video_cycle_msaa() {
    hh::VideoConfig& vc = hh::video_config_mutable();
    static const char* modes[] = { "off", "2x", "4x", "8x" };
    int idx = 3;
    for (int i = 0; i < 4; ++i) if (vc.msaa == modes[i]) { idx = i; break; }
    idx = (idx + 1) & 3;
    vc.msaa = modes[idx];
    ultramodern::renderer::GraphicsConfig cfg = ultramodern::renderer::get_graphics_config();
    cfg.msaa_option = hh_video_msaa_mode();
    ultramodern::renderer::set_graphics_config(cfg);
    fprintf(stderr, "[VIDEO] F2 -> msaa=%s\n", vc.msaa.c_str());
}

ultramodern::gfx_callbacks_t::gfx_data_t hh::create_gfx() {
    hh::log("create_gfx: initializing SDL\n");
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK) != 0) {
        error_box(("Failed to initialize SDL2: " + std::string(SDL_GetError())).c_str());
        std::exit(EXIT_FAILURE);
    }


    fprintf(stdout, "SDL Video Driver: %s\n", SDL_GetCurrentVideoDriver());
    hh::log("create_gfx: SDL driver = %s\n", SDL_GetCurrentVideoDriver());

    return {};
}

ultramodern::renderer::WindowHandle hh::create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
    uint32_t flags = SDL_WINDOW_RESIZABLE;

#if defined(__APPLE__)
    flags |= SDL_WINDOW_METAL;
#elif defined(RT64_SDL_WINDOW_VULKAN)
    flags |= SDL_WINDOW_VULKAN;
#endif

    hh::log("create_window: creating SDL window\n");
    // HH: `wm=borderless` abre la ventana a tamano de escritorio y RT64 la pasa a fullscreen en el
    // constructor (`app->setFullScreen`); `wm=windowed` deja una ventana normal (no se puede pasar
    // a fullscreen porque el estado inicial de RT64 ya es "no fullscreen"). Antes se creaba SIEMPRE
    // a tamano de escritorio, asi que `windowed` parecia pantalla completa al arrancar.
    int win_w = 1280, win_h = 720;
    SDL_DisplayMode dm{};
    if (SDL_GetDesktopDisplayMode(0, &dm) == 0 && dm.w > 0 && dm.h > 0) {
        // Diagnostico de present rate: refresco del escritorio segun SDL (comparar con swapChainRate).
        hh::log("Video: desktop %dx%d @ %d Hz\n", dm.w, dm.h, dm.refresh_rate);
        if (hh::video_config().wm != "windowed") {
            win_w = dm.w;
            win_h = dm.h;
        }
    }
    window = SDL_CreateWindow("Hybrid Heaven", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, flags);

    if (window == nullptr) {
        error_box(("Failed to create window: " + std::string(SDL_GetError())).c_str());
        std::exit(EXIT_FAILURE);
    }
    hh::log("create_window: window created OK\n");

    hh::set_window_icon(window);

    // Oculta el cursor sobre la ventana del juego. Se vuelve a mostrar al perder el foco y se
    // oculta al recuperarlo (ver SDL_WINDOWEVENT en src/subsystems/input.cpp).
    SDL_ShowCursor(SDL_DISABLE);

    SDL_SysWMinfo wm_info;
    SDL_VERSION(&wm_info.version);
    if (!SDL_GetWindowWMInfo(window, &wm_info)) {
        error_box(("Failed to get window WM info: " + std::string(SDL_GetError())).c_str());
        std::exit(EXIT_FAILURE);
    }

#if defined(_WIN32)
    return ultramodern::renderer::WindowHandle{ wm_info.info.win.window, GetCurrentThreadId() };
#elif defined(__linux__)
    return ultramodern::renderer::WindowHandle{ window };
#elif defined(__APPLE__)
    SDL_MetalView view = SDL_Metal_CreateView(window);
    return ultramodern::renderer::WindowHandle{ wm_info.info.cocoa.window, SDL_Metal_GetLayer(view) };
#else
    static_assert(false && "Unimplemented platform");
#endif
}

void hh::update_gfx(ultramodern::gfx_callbacks_t::gfx_data_t gfx_data) {
    (void)gfx_data;
    hh::poll_input();
}

static SDL_AudioDeviceID audio_device = 0;

static uint32_t sample_rate = 44100;   // tasa del juego (44100 por defecto si el juego no la fija)
static uint32_t device_rate = 0;       // tasa con la que se abrio el dispositivo
constexpr uint32_t input_channels = 2; // el AI del N64 es estereo S16
constexpr uint32_t bytes_per_frame = input_channels * sizeof(int16_t);

// HH: sin dispositivo de audio (headless/CI) el AI del N64 debe seguir "reproduciendo": si
// osAiGetLength() devolviera 0 siempre, el pacing de audio del juego se degrada (nota
// 2026-09-13-audio-ai-length.md). Cola virtual drenada a tiempo real con la frecuencia del juego.
static double virtual_frames = 0.0;
static std::chrono::steady_clock::time_point virtual_clock = std::chrono::steady_clock::now();
static std::atomic<unsigned long long> hh_audio_drops{0};  // buffers descartados (salvaguarda dura)

static void virtual_ai_drain() {
    const auto now = std::chrono::steady_clock::now();
    const double elapsed = std::chrono::duration<double>(now - virtual_clock).count();
    virtual_clock = now;
    static const double ai_speed = [] {
        const char* s = getenv("HH_AI_SPEED");
        return s ? strtod(s, nullptr) : 1.0;
    }();
    virtual_frames -= elapsed * sample_rate * ai_speed;
    if (virtual_frames < 0.0) {
        virtual_frames = 0.0;
    }
}

// Abre (o reabre) el dispositivo a la tasa del juego. SDL_QueueAudio admite datos en el formato
// pedido y SDL los convierte internamente al formato real del dispositivo, asi que NO usamos
// SDL_AudioCVT (en algunos SDL2.dll len_ratio salia basura y el audio petardeaba).
static bool hh_open_audio_device(uint32_t freq) {
    if (audio_device != 0) {
        SDL_CloseAudioDevice(audio_device);
        audio_device = 0;
        device_rate = 0;
    }
    SDL_AudioSpec spec_desired{};
    SDL_AudioSpec spec_obtained{};
    spec_desired.freq = static_cast<int>(freq);
    spec_desired.format = AUDIO_S16;
    spec_desired.channels = static_cast<Uint8>(input_channels);
    spec_desired.samples = 0x400;

    // ALLOW_FREQUENCY_CHANGE: WASAPI suele fijar 48k; SDL abre a la suya y convierte el flujo
    // internamente (la app sigue enviando datos a sample_rate).
    audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, &spec_obtained,
                                       SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (audio_device == 0) {
        fprintf(stderr, "No audio device could be found: %s\n", SDL_GetError());
        return false;
    }
    device_rate = freq;
    SDL_PauseAudioDevice(audio_device, 0);
    fprintf(stderr, "Audio device: pedido %u Hz; obtenido %d Hz, %d ch\n",
            freq, spec_obtained.freq, spec_obtained.channels);
    return true;
}

// HH: diagnostico de audio siempre activo (ficheros en el CWD, tamano acotado). Permite ver
// desde fuera la tasa efectiva de produccion, la cola y el estado del dispositivo.
static void hh_audio_diag_log(size_t sample_count, size_t queued_frames, size_t reported_frames) {
    static unsigned long calls = 0;
    static unsigned long long samples = 0;
    static double last_t = -1.0;
    static unsigned long last_calls = 0;
    static unsigned long long last_samples = 0;
    static unsigned long long last_drops = 0;
    calls++;
    samples += sample_count;
    static const auto diag_t0 = std::chrono::steady_clock::now();
    const double now = std::chrono::duration<double>(
        std::chrono::steady_clock::now() - diag_t0).count();
    if (last_t < 0.0) { last_t = now; last_calls = 0; last_samples = 0; last_drops = hh_audio_drops.load(); return; }
    if (now - last_t < 1.0) return;
    const double dt = now - last_t;
    const double fps_eq = (double)(samples - last_samples) / 2.0 / dt;
    const unsigned long long drops = hh_audio_drops.load();
    if (FILE* f = fopen("hh_audio.log", "a")) {
        fprintf(f, "t=%.2f calls/s=%.1f frames/s=%.0f queued=%zu reported=%zu drops/s=%.1f rate=%u dev=%u\n",
                now, (double)(calls - last_calls) / dt, fps_eq, queued_frames, reported_frames,
                (double)(drops - last_drops) / dt, sample_rate, device_rate);
        fclose(f);
    }
    last_t = now; last_calls = calls; last_samples = samples; last_drops = drops;
}

static std::atomic<unsigned long long> hh_audio_calls{0};

extern "C" unsigned long long hh_get_audio_calls() {
    return hh_audio_calls.load();
}

// --- Resampler adaptativo (PLL de reloj de audio) ----------------------------------------------
// Sincroniza la produccion del juego con la reproduccion del dispositivo ajustando la tasa de
// salida +-HH_AI_MAXC (1% por defecto) segun el error de la cola respecto a HH_AI_TARGET_MS. Asi la
// cola se mantiene centrada SIN descartar buffers (los descartes del watermark producian clics
// periodicos). Estado continuo entre llamadas. Ver `notes/2026-09-18-suavizado-fase1-*.md` §2.
static double hh_rs_phase = 0.0;                    // fraccion entre la muestra previa y la actual
static int16_t hh_rs_last[input_channels] = {0};    // ultima muestra (frame) de la llamada previa
static std::vector<int16_t> hh_rs_out;              // buffer de salida reutilizado

// `step` = frames de entrada por frame de salida (>1 reduce, <1 amplía). Interpolacion lineal.
static void hh_queue_resampled(const int16_t* in, size_t in_frames, double step) {
    const size_t max_out = in_frames * 2 + 4;       // step en ~[0.99,1.01]: <=2 salidas por entrada
    hh_rs_out.resize(max_out * input_channels);
    size_t out_frames = 0;
    for (size_t i = 0; i < in_frames; ++i) {
        const int16_t* cur = in + i * input_channels;
        while (hh_rs_phase < 1.0) {
            if (out_frames >= max_out) break;
            int16_t* dst = &hh_rs_out[out_frames * input_channels];
            const double t = hh_rs_phase;
            for (uint32_t c = 0; c < input_channels; ++c) {
                const double a = static_cast<double>(hh_rs_last[c]);
                const double b = static_cast<double>(cur[c]);
                double v = a + (b - a) * t;
                if (v >= 32767.0) v = 32767.0;
                else if (v <= -32768.0) v = -32768.0;
                dst[c] = static_cast<int16_t>(v >= 0.0 ? v + 0.5 : v - 0.5);
            }
            ++out_frames;
            hh_rs_phase += step;
        }
        hh_rs_phase -= 1.0;
        for (uint32_t c = 0; c < input_channels; ++c) hh_rs_last[c] = cur[c];
    }
    if (out_frames > 0) {
        SDL_QueueAudio(audio_device, hh_rs_out.data(),
                       static_cast<Uint32>(out_frames * input_channels * sizeof(int16_t)));
    }
}

void hh::queue_samples(int16_t* audio_data, size_t sample_count) {
    hh_audio_calls.fetch_add(1, std::memory_order_relaxed);
    if (audio_device == 0) {
        virtual_ai_drain();
        virtual_frames += static_cast<double>(sample_count) / input_channels;
        // HH: cota de la cola virtual. El driver de audio del juego calcula el siguiente tamano
        // como (0x2E0 - osAiGetLength()/4 + 0x100) & 0xFFF0: si la cola reportada supera la
        // ventana 0x3E0 palabras, el calculo hace wrap (s16 negativo) y envenena osAiGetLength
        // (command lists runaway que pisan los contextos de voz). Con la reproduccion virtual
        // (headless) un burst de ticks puede superar la ventana; se acota a ~1 VI.
        const double cap = static_cast<double>(sample_rate) / 60.0;
        // HH_AI_NOCLAMP=1: experimento de fidelidad. El clamp de la cola virtual es un parche que
        // solo existe sin dispositivo; el camino con dispositivo (Windows/SDL) no lo tiene y por
        // eso su driver de audio/eventos progresa distinto. Con esto se puede comparar la ruta
        // virtual "sin clamp" contra la del dispositivo (ver notes/2026-09-17-replay-*).
        static const bool hh_no_clamp = [] {
            const char* e = getenv("HH_AI_NOCLAMP");
            return e != nullptr && *e != '\0' && strcmp(e, "0") != 0;
        }();
        if (!hh_no_clamp && virtual_frames > cap) {
            if (getenv("HH_VERBOSE") != nullptr) {
                static int hh_n = 0;
                if (hh_n++ < 20) fprintf(stderr, "[AI ] cola virtual acotada: %.0f -> %.0f frames\n", virtual_frames, cap);
            }
            virtual_frames = cap;
        }
        return;
    }
    // El runtime pasa `sample_count` en muestras int16 (byte_count / sizeof(int16_t)).
    constexpr size_t hh_max_samples = 1u << 18;  // 262144 muestras (~1 MB)
    if (sample_count == 0 || sample_count > hh_max_samples) {
        const char* hh_audlog = getenv("HH_AUDIOLOG");
        if (hh_audlog != nullptr && *hh_audlog != '\0') {
            fprintf(stderr, "[AUD] queue_samples ignorado: count=%zu\n", sample_count);
        }
        return;
    }
    const size_t byte_len = sample_count * sizeof(int16_t);

    // HH: los samples llegan con L/R INVERTIDOS. librecomp guarda la RDRAM byte-swapped (los macros
    // MEM_* hacen XOR) y `queue_samples` recibe un puntero crudo (TO_PTR) que salta ese XOR: cada
    // palabra de 4 B (L,R) queda como (R,L). Se des-swapea aqui (igual que la referencia).
    // `HH_AUDIO_NO_SWAP=1` lo desactiva (A/B). Ver notes/2026-09-21-audio-petardeo-ref-y-plan.md §3.4.
    static std::vector<int16_t> hh_unswapped;
    static const bool hh_swap_lr = [] {
        const char* e = getenv("HH_AUDIO_NO_SWAP");
        return !(e != nullptr && *e != '\0' && strcmp(e, "0") != 0);  // por defecto: SÍ des-swapear
    }();
    const int16_t* hh_pcm = audio_data;
    if (hh_swap_lr) {
        hh_unswapped.resize(sample_count);
        for (size_t i = 0; i + 1 < sample_count; i += 2) {
            hh_unswapped[i] = audio_data[i + 1];
            hh_unswapped[i + 1] = audio_data[i];
        }
        if (sample_count & 1) {
            hh_unswapped[sample_count - 1] = audio_data[sample_count - 1];
        }
        hh_pcm = hh_unswapped.data();
    }

    // SFX del menú: se mezclan sobre el stream del juego. `hh_pcm` puede apuntar a un buffer const
    // (audio_data), así que se trabaja sobre una copia mutable.
    static std::vector<int16_t> hh_mixed;
    hh_mixed.assign(hh_pcm, hh_pcm + sample_count);
    hh::menu_sfx::mix(hh_mixed.data(), sample_count);
    hh_pcm = hh_mixed.data();

    // Dump de audio OPT-IN: con HH_AUDIODUMP=<f> escribe hasta 4 MB de PCM en ese fichero (o
    // hh_audio_dump.bin). Por defecto NO se escribe: eran ~4 MB con fflush por buffer al arrancar
    // (I/O innecesario; el log textual hh_audio.log sigue activo siempre).
    {
        const char* dump_env = getenv("HH_AUDIODUMP");
        if (dump_env != nullptr && *dump_env != '\0') {
            static FILE* df = nullptr;
            static size_t dtotal = 0;
            static const char* dpath = nullptr;
            if (dpath == nullptr) {
                dpath = dump_env;
                df = fopen(dpath, "wb");
                if (df != nullptr) fprintf(stderr, "[AUD] dump en %s\n", dpath);
            }
            if (df != nullptr && dtotal < (4u << 20)) {
                fwrite(hh_pcm, 1, byte_len, df);
                fflush(df);
                dtotal += byte_len;
            }
        }
    }

    const char* hh_audlog = getenv("HH_AUDIOLOG");
    if (hh_audlog != nullptr && *hh_audlog != '\0') {
        static int hh_aud_n = 0;
        if (hh_aud_n++ < 40) {
            fprintf(stderr, "[AUD] count=%zu bytes=%zu rate=%u device=%u\n",
                    sample_count, byte_len, sample_rate, device_rate);
        }
    }

    // Sincronizacion de tasa por error de cola (PLL) + salvaguarda dura.
    // HH_AI_SYNC=0 vuelve al comportamiento antiguo (sin resamplear). HH_AI_TARGET_MS (50) fija el
    // objetivo de cola; HH_AI_MAXC (0.03) la correccion maxima; HH_AI_MAX_MS (150) la salvaguarda.
    // El tope debe SUPERAR el desajuste real (~1% medido) para poder drenar; si queda justo, la
    // cola se queda pegada al watermark y sigue descartando (petardeo).
    static const bool hh_sync = [] {
        const char* e = getenv("HH_AI_SYNC");
        return !(e != nullptr && *e != '\0' && strcmp(e, "0") == 0);
    }();
    static const double hh_target_ms = [] {
        const char* e = getenv("HH_AI_TARGET_MS");
        return (e != nullptr && *e != '\0') ? strtod(e, nullptr) : 50.0;
    }();
    static const double hh_maxc = [] {
        const char* e = getenv("HH_AI_MAXC");
        return (e != nullptr && *e != '\0') ? strtod(e, nullptr) : 0.03;
    }();

    // Salvaguarda DURA (deberia ser rara con el PLL): si la cola supera HH_AI_MAX_MS, descartar.
    {
        const char* mx = getenv("HH_AI_MAX_MS");
        const double max_ms = (mx != nullptr && *mx != '\0') ? strtod(mx, nullptr) : 150.0;
        const Uint32 queued = SDL_GetQueuedAudioSize(audio_device);
        const Uint32 limit = (Uint32)((double)sample_rate * bytes_per_frame * max_ms / 1000.0);
        if (queued > limit) {
            hh_audio_drops.fetch_add(1, std::memory_order_relaxed);
            if (hh_audlog != nullptr && *hh_audlog != '\0') {
                static int hh_drop_n = 0;
                if (hh_drop_n++ < 10) {
                    fprintf(stderr, "[AUD] cola llena (%u bytes): se descarta buffer\n", queued);
                }
            }
            return;
        }
    }

    if (hh_sync) {
        const double queued = (double)SDL_GetQueuedAudioSize(audio_device) / bytes_per_frame;
        const double target = (double)sample_rate * hh_target_ms / 1000.0;
        double corr = target > 0.0 ? (queued - target) / target : 0.0;
        if (corr > 1.0) corr = 1.0;
        else if (corr < -1.0) corr = -1.0;
        const double step = 1.0 + corr * hh_maxc;   // >1 => menos salida => drena la cola
        hh_queue_resampled(hh_pcm, sample_count / input_channels, step);
    } else {
        // SDL convierte internamente al formato real del dispositivo.
        SDL_QueueAudio(audio_device, hh_pcm, static_cast<Uint32>(byte_len));
    }

    {
        const size_t queued = static_cast<size_t>(
            SDL_GetQueuedAudioSize(audio_device) / bytes_per_frame);
        const size_t cap = static_cast<size_t>(sample_rate / 60);
        hh_audio_diag_log(sample_count, queued, queued < cap ? queued : cap);
    }
}

uint32_t hh::audio_output_rate() {
    return device_rate != 0 ? device_rate : sample_rate;
}

size_t hh::get_frames_remaining() {
    if (audio_device == 0) {
        virtual_ai_drain();
        return static_cast<size_t>(virtual_frames);
    }
    const size_t queued = static_cast<size_t>(
        SDL_GetQueuedAudioSize(audio_device) / bytes_per_frame);
    // Emulacion de hardware: el AI solo tiene UN buffer en vuelo (720-800 frames). El juego
    // decide si producir el siguiente con osAiGetLength: si reportamos la cola real de SDL
    // (varios buffers) cree que hay un backlog enorme y se frena (producia ~45 buffers/s en vez
    // de 60 -> huecos). Reportar como maximo un VI de frames replica el hardware.
    // HH_AI_QUEUE_REPORT=full restaura el comportamiento anterior (cola real sin cap) para
    // pruebas de regresion sin recompilar.
    const char* qrep = getenv("HH_AI_QUEUE_REPORT");
    const char* rsdl = getenv("HH_AI_REPORT_SDL");
    // Reporte de la cola REAL (sin cap) para el modelo de la referencia (por defecto; =0 revierte).
    const bool report_sdl = !(rsdl != nullptr && *rsdl != '\0' && strcmp(rsdl, "0") == 0);
    const bool full = (qrep != nullptr && strcmp(qrep, "full") == 0) || report_sdl;
    const size_t cap = full ? static_cast<size_t>(-1)
                            : static_cast<size_t>(sample_rate / 60);
    const size_t reported = queued < cap ? queued : cap;
    const char* qlog = getenv("HH_AUDIOLOG");
    if (qlog != nullptr && *qlog != '\0') {
        static unsigned long qn = 0;
        if ((qn++ & 0x3F) == 0) {
            fprintf(stderr, "[AUDQ] queued=%zu reported=%zu cap=%zu\n", queued, reported, cap);
        }
    }
    return reported;
}

void hh::set_frequency(uint32_t freq) {
    if (freq < 4000 || freq > 192000) {
        fprintf(stderr, "[AUD] set_frequency ignorado: %u Hz\n", freq);
        return;
    }
    if (freq == sample_rate) {
        return;
    }
    sample_rate = freq;
    // Si el dispositivo ya estaba abierto con otra tasa, reabrir a la nueva.
    if (audio_device != 0 && device_rate != freq) {
        hh_open_audio_device(freq);
    }
}

bool hh::reset_audio(uint32_t output_freq) {
    // HH_NOAUDIO=1 fuerza el camino virtual (sin dispositivo): util para aislar crashes de audio.
    const char* hh_noaudio = getenv("HH_NOAUDIO");
    if (hh_noaudio != nullptr && *hh_noaudio != '\0') {
        fprintf(stderr, "HH_NOAUDIO=1: audio virtual (sin dispositivo)\n");
        audio_device = 0;
        return true;
    }
    if (output_freq >= 4000 && output_freq <= 192000) {
        sample_rate = output_freq;
    }
    return hh_open_audio_device(sample_rate);
}

// Microcodigo de audio del ROM en 0x80036530 (ROM 0x37130), recompilado con RSPRecomp
// (config `recomp/rsp_hh_aspMain.toml`; texto 0xE98, base IMEM 0x1000). El motor de audio
// del juego es el que dispara la progresion del modulo (ver
// notes/2026-09-13-ucode-audio-gate-transicion.md).
extern RspExitReason hh_aspMain(uint8_t* rdram, uint32_t ucode_addr);

// HH: diagnostico del runtime (definido en recomp.cpp). Sin HH_DIAG=1 no se escribe hh_rsp.log.
extern "C" int hh_diag_enabled(void);

// Diagnostico: cuanto tarda la task de audio (RSP recompilado, en CPU). Si supera ~16.7 ms el
// driver del juego solo produce un buffer por VI de cada dos (audio a tirones). Se vuelca al
// fichero hh_rsp.log (CWD) cada 60 tasks para poder verlo tambien en la maquina del usuario.
// Gated por HH_DIAG=1 (el cronometro en si es barato, pero evita el I/O periodico por defecto).
static RspExitReason hh_aspMain_timed(uint8_t* rdram, uint32_t ucode_addr) {
    if (!hh_diag_enabled()) return hh_aspMain(rdram, ucode_addr);
    const auto t0 = std::chrono::steady_clock::now();
    RspExitReason r = hh_aspMain(rdram, ucode_addr);
    const double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
    static double acc = 0.0, mx = 0.0;
    static int n = 0;
    acc += ms; if (ms > mx) mx = ms; n++;
    if (n >= 60) {
        static FILE* f = fopen("hh_rsp.log", "w");
        if (f != nullptr) {
            fprintf(f, "audio tasks=%d avg=%.1fms max=%.1fms (limite 16.7ms)\n", n, acc / n, mx);
            fflush(f);
        }
        acc = 0.0; mx = 0.0; n = 0;
    }
    return r;
}

RspUcodeFunc* hh::get_rsp_microcode(const OSTask* task) {
    uint32_t type = task->t.type;
    if (type == M_AUDTASK) {
        if (getenv("HH_VERBOSE") != nullptr) {
            static const auto t0 = std::chrono::steady_clock::now();
            double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
            fprintf(stderr, "[AUD] t=%.0fms type=%u flags=%X boot=%08X/%X ucode=%08X/%X udata=%08X/%X stack=%08X/%X out=%08X/%X data=%08X/%X yield=%08X/%X\n", ms,
                type, task->t.flags,
                (unsigned)task->t.ucode_boot, task->t.ucode_boot_size,
                (unsigned)task->t.ucode, task->t.ucode_size,
                (unsigned)task->t.ucode_data, task->t.ucode_data_size,
                (unsigned)task->t.dram_stack, task->t.dram_stack_size,
                (unsigned)task->t.output_buff, (unsigned)task->t.output_buff_size,
                (unsigned)task->t.data_ptr, task->t.data_size,
                (unsigned)task->t.yield_data_ptr, task->t.yield_data_size);
        }
        return hh_aspMain_timed;
    }
    // Tasks sin ucode registrado: el runtime las completa como no-op (dummy).
    hh::log("RSP ucode not registered: type=%" PRIu32 " (0x%08" PRIx32 ")\n", type, type);
    return nullptr;
}