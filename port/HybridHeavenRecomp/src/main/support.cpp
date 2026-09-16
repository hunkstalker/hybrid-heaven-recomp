#include <cinttypes>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <atomic>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
    return "0.1.0";
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

static std::vector<std::filesystem::path> get_rom_candidates() {
    // La ROM la aporta el usuario. Ubicación oficial: <carpeta del .exe>/rom/baserom.us.z64.
    // Una salvaguarda: <carpeta del .exe>/baserom.us.z64. NO se busca en el directorio de
    // lanzamiento (CWD): la carpeta del ejecutable es la referencia portable.
    const std::filesystem::path exe_dir = std::filesystem::path(get_executable_path()).parent_path();
    std::vector<std::filesystem::path> candidates;
    for (const std::string& name : { "baserom.us.z64" }) {
        candidates.emplace_back(exe_dir / "rom" / name);
        candidates.emplace_back(exe_dir / name);
    }
    return candidates;
}

std::filesystem::path hh::get_rom_path() {
    for (const auto& candidate : get_rom_candidates()) {
        std::error_code ec;
        if (std::filesystem::exists(candidate, ec)) {
            return candidate;
        }
    }
    return {};
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
    window = SDL_CreateWindow("Hybrid Heaven", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, flags);

    if (window == nullptr) {
        error_box(("Failed to create window: " + std::string(SDL_GetError())).c_str());
        std::exit(EXIT_FAILURE);
    }
    hh::log("create_window: window created OK\n");

    hh::set_window_icon(window);

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
    calls++;
    samples += sample_count;
    static const auto diag_t0 = std::chrono::steady_clock::now();
    const double now = std::chrono::duration<double>(
        std::chrono::steady_clock::now() - diag_t0).count();
    if (last_t < 0.0) { last_t = now; last_calls = 0; last_samples = 0; return; }
    if (now - last_t < 1.0) return;
    const double dt = now - last_t;
    const double fps_eq = (double)(samples - last_samples) / 2.0 / dt;
    if (FILE* f = fopen("hh_audio.log", "a")) {
        fprintf(f, "t=%.2f calls/s=%.1f frames/s=%.0f queued=%zu reported=%zu rate=%u dev=%u\n",
                now, (double)(calls - last_calls) / dt, fps_eq, queued_frames, reported_frames,
                sample_rate, device_rate);
        fclose(f);
    }
    last_t = now; last_calls = calls; last_samples = samples;
}

static std::atomic<unsigned long long> hh_audio_calls{0};

extern "C" unsigned long long hh_get_audio_calls() {
    return hh_audio_calls.load();
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
        if (virtual_frames > cap) {
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

    // Dump de audio siempre activo (acotado a 4 MB) en hh_audio_dump.bin del CWD, para poder
    // analizar la tasa/formato real desde fuera. HH_AUDIODUMP=<f> cambia la ruta.
    {
        const char* dump_env = getenv("HH_AUDIODUMP");
        const char* dump = (dump_env != nullptr && *dump_env != '\0') ? dump_env : "hh_audio_dump.bin";
        static FILE* df = nullptr;
        static size_t dtotal = 0;
        static const char* dpath = nullptr;
        if (dpath == nullptr) {
            dpath = dump;
            df = fopen(dpath, "wb");
            if (df != nullptr) fprintf(stderr, "[AUD] dump en %s\n", dpath);
        }
        if (df != nullptr && dtotal < (4u << 20)) {
            fwrite(audio_data, 1, byte_len, df);
            fflush(df);
            dtotal += byte_len;
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

    // Backpressure: si ya hay mas de ~1 s encolados, descartar (evita crecimientos enormes).
    {
        const Uint32 queued = SDL_GetQueuedAudioSize(audio_device);
        const Uint32 limit = sample_rate * bytes_per_frame;
        if (queued > limit) {
            if (hh_audlog != nullptr && *hh_audlog != '\0') {
                static int hh_drop_n = 0;
                if (hh_drop_n++ < 10) {
                    fprintf(stderr, "[AUD] cola llena (%u bytes): se descarta buffer\n", queued);
                }
            }
            return;
        }
    }

    // SDL convierte internamente al formato real del dispositivo.
    SDL_QueueAudio(audio_device, audio_data, static_cast<Uint32>(byte_len));

    {
        const size_t queued = static_cast<size_t>(
            SDL_GetQueuedAudioSize(audio_device) / bytes_per_frame);
        const size_t cap = static_cast<size_t>(sample_rate / 60);
        hh_audio_diag_log(sample_count, queued, queued < cap ? queued : cap);
    }
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
    const size_t cap = (qrep != nullptr && strcmp(qrep, "full") == 0)
                           ? static_cast<size_t>(-1)
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
// (config `config/rsp_hh_aspMain.toml`; texto 0xE98, base IMEM 0x1000). El motor de audio
// del juego es el que dispara la progresion del modulo (ver
// notes/2026-09-13-ucode-audio-gate-transicion.md).
extern RspExitReason hh_aspMain(uint8_t* rdram, uint32_t ucode_addr);

// Diagnostico: cuanto tarda la task de audio (RSP recompilado, en CPU). Si supera ~16.7 ms el
// driver del juego solo produce un buffer por VI de cada dos (audio a tirones). Se vuelca al
// fichero hh_rsp.log (CWD) cada 60 tasks para poder verlo tambien en la maquina del usuario.
static RspExitReason hh_aspMain_timed(uint8_t* rdram, uint32_t ucode_addr) {
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