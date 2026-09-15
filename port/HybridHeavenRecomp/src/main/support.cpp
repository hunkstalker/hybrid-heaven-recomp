#include <cinttypes>
#include <chrono>
#include <cstdarg>
#include <cstdio>
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
    return std::filesystem::path("/proc/self/exe");
#endif
}

std::filesystem::path hh::get_app_folder_path() {
#ifdef _WIN32
    const char* appdata = std::getenv("APPDATA");
    std::filesystem::path base = (appdata != nullptr) ? std::filesystem::path(appdata) : std::filesystem::path(get_executable_path().parent_path());
    std::filesystem::path folder = base / "HybridHeavenRecomp";
    std::error_code ec;
    std::filesystem::create_directories(folder, ec);
    return folder;
#elif defined(__linux__) || defined(__APPLE__)
    std::filesystem::path base;
    if (const char* xdg = std::getenv("XDG_DATA_HOME"); xdg != nullptr && *xdg != '\0') {
        base = std::filesystem::path(xdg);
    }
    else if (const char* home = std::getenv("HOME"); home != nullptr) {
        base = std::filesystem::path(home) / ".local" / "share";
    }
    else {
        base = std::filesystem::path("/tmp");
    }
    std::filesystem::path folder = base / "HybridHeavenRecomp";
    std::error_code ec;
    std::filesystem::create_directories(folder, ec);
    return folder;
#else
#error "Unsupported platform"
#endif
}

static std::vector<std::filesystem::path> get_rom_candidates() {
    std::vector<std::filesystem::path> candidates;
    for (const std::string& name : { "baserom.us.z64" }) {
        candidates.emplace_back(std::filesystem::path(get_executable_path().parent_path()) / name);
        candidates.emplace_back(std::filesystem::path(std::filesystem::current_path()) / name);
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

static SDL_AudioCVT audio_convert;
static SDL_AudioDeviceID audio_device = 0;
static bool audio_cvt_needed = false;   // SDL_BuildAudioCVT: 1 = hay conversion, 0 = no hace falta

static uint32_t sample_rate = 48000;
static uint32_t output_sample_rate = 48000;
constexpr uint32_t input_channels = 2;
static uint32_t output_channels = 2;
constexpr uint32_t bytes_per_sample = input_channels * sizeof(int16_t);
static std::vector<uint8_t> audio_cvt_buffer;

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

void hh::queue_samples(int16_t* audio_data, size_t sample_count) {
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
    // HH: el runtime pasa `sample_count` en muestras int16 (byte_count / sizeof(int16_t)), no en
    // frames. El byte_len correcto es sample_count * sizeof(int16_t); usar bytes_per_sample (=4,
    // bytes por frame) copiaba el doble -> heap corruption al abrir dispositivo real (0xC0000374).
    // Límites de seguridad: evita allocaciones absurdas (wrap del juego) que corrompen el heap.
    constexpr size_t hh_max_samples = 1u << 18;  // 262144 muestras (~1 MB)
    if (sample_count == 0 || sample_count > hh_max_samples) {
        const char* hh_audlog = getenv("HH_AUDIOLOG");
        if (hh_audlog != nullptr && *hh_audlog != '\0') {
            fprintf(stderr, "[AUD] queue_samples ignorado: count=%zu\n", sample_count);
        }
        return;
    }
    const size_t byte_len = sample_count * sizeof(int16_t);
    const bool convert = audio_cvt_needed && audio_convert.len_ratio > 0.0f
                         && audio_convert.len_ratio <= 64.0f;
    const char* hh_audlog = getenv("HH_AUDIOLOG");
    if (hh_audlog != nullptr && *hh_audlog != '\0') {
        static int hh_aud_n = 0;
        if (hh_aud_n++ < 40) {
            fprintf(stderr, "[AUD] count=%zu bytes=%zu rate=%u out=%u ratio=%.3f conv=%d\n",
                    sample_count, byte_len, sample_rate, output_sample_rate,
                    audio_convert.len_ratio, (int)convert);
        }
    }
    // El buffer debe caber SIEMPRE la entrada (byte_len) y, si hay conversion, la salida.
    // Antes, con len_ratio < 1 (dispositivo a menos Hz que el juego) el buffer quedaba MAS
    // pequeno que byte_len y el memcpy desbordaba el heap (crash en ntdll).
    size_t needed = byte_len;
    if (convert) {
        const size_t conv_needed = static_cast<size_t>(byte_len * audio_convert.len_ratio) + 32;
        if (conv_needed > needed) {
            needed = conv_needed;
        }
    }
    if (audio_cvt_buffer.size() < needed) {
        audio_cvt_buffer.resize(needed);
    }

    // Backpressure: si ya hay mas de ~2 s encolados, descartar (evita crecimientos enormes).
    {
        const Uint32 queued = SDL_GetQueuedAudioSize(audio_device);
        const Uint32 limit = output_sample_rate * output_channels * sizeof(int16_t) * 2u;
        if (queued > limit) {
            if (getenv("HH_AUDIOLOG") != nullptr) {
                static int hh_drop_n = 0;
                if (hh_drop_n++ < 10) {
                    fprintf(stderr, "[AUD] cola llena (%u bytes): se descarta buffer\n", queued);
                }
            }
            return;
        }
    }

    std::memcpy(audio_cvt_buffer.data(), audio_data, byte_len);

    // Referencia (mismo motor Konami): goemon64recomp/Zelda64Recomp intercambian los CANALES
    // ("to correct for the address xor caused by endianness handling"); las muestras en si ya
    // estan en orden de host. Sin esto el audio suena a ruido/petardeo.
    if (input_channels >= 2) {
        int16_t* samples = reinterpret_cast<int16_t*>(audio_cvt_buffer.data());
        const size_t frame_count = byte_len / (input_channels * sizeof(int16_t));
        for (size_t f = 0; f < frame_count; f++) {
            int16_t* fr = samples + f * input_channels;
            for (uint32_t c = 1; c < input_channels; c += 2) {
                int16_t tmp = fr[c - 1];
                fr[c - 1] = fr[c];
                fr[c] = tmp;
            }
        }
    }

    if (!convert) {
        // Sin conversor valido: encolar tal cual (evita usar len_ratio=0).
        SDL_QueueAudio(audio_device, audio_cvt_buffer.data(), static_cast<Uint32>(byte_len));
        return;
    }

    audio_convert.buf = audio_cvt_buffer.data();
    audio_convert.len = static_cast<int>(byte_len);

    if (SDL_ConvertAudio(&audio_convert) < 0) {
        fprintf(stderr, "Error using SDL audio converter: %s\n", SDL_GetError());
        return;
    }

    SDL_QueueAudio(audio_device, audio_convert.buf, audio_convert.len_cvt);
}

size_t hh::get_frames_remaining() {
    if (audio_device == 0) {
        virtual_ai_drain();
        return static_cast<size_t>(virtual_frames);
    }
    const size_t queued = static_cast<size_t>(
        SDL_GetQueuedAudioSize(audio_device) / (input_channels * sizeof(int16_t)));
    // El N64 (y la formula del juego) solo maneja ~1-2 VI de cola: si reportamos mas, el juego
    // calcula un tamano negativo (wrap) y descarta audio. Se acota como en la via virtual.
    const size_t cap = static_cast<size_t>(sample_rate / 60);
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
    // Rangos sanos: valores absurdos (wrap del juego) romperian el CVT.
    if (freq < 4000 || freq > 192000) {
        fprintf(stderr, "[AUD] set_frequency ignorado: %u Hz\n", freq);
        return;
    }
    sample_rate = freq;

    int ret = SDL_BuildAudioCVT(
        &audio_convert,
        AUDIO_S16, static_cast<Uint8>(input_channels), static_cast<int>(sample_rate),
        AUDIO_S16, static_cast<Uint8>(output_channels), static_cast<int>(output_sample_rate)
    );

    // SDL: ret==0 => NO hace falta conversion (mismas tasa/formato); len_ratio puede quedar a 0.
    // Usar ret (no len_ratio) para decidir si convertir.
    audio_cvt_needed = (ret > 0);

    if (ret < 0) {
        fprintf(stderr, "Error creating SDL audio converter: %s\n", SDL_GetError());
        audio_cvt_needed = false;
    }
    fprintf(stderr, "[AUD] CVT: ret=%d needed=%d ratio=%.4f (%u -> %u Hz)\n",
            ret, (int)audio_cvt_needed, audio_convert.len_ratio, sample_rate, output_sample_rate);
}

bool hh::reset_audio(uint32_t output_freq) {
    // HH_NOAUDIO=1 fuerza el camino virtual (sin dispositivo): util para aislar crashes de audio.
    const char* hh_noaudio = getenv("HH_NOAUDIO");
    if (hh_noaudio != nullptr && *hh_noaudio != '\0') {
        fprintf(stderr, "HH_NOAUDIO=1: audio virtual (sin dispositivo)\n");
        audio_device = 0;
        return true;
    }
    SDL_AudioSpec spec_desired{};
    SDL_AudioSpec spec_obtained{};
    spec_desired.freq = static_cast<int>(output_freq);
    spec_desired.format = AUDIO_S16;
    spec_desired.channels = static_cast<Uint8>(output_channels);
    spec_desired.samples = 0x100;

    audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, &spec_obtained, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (audio_device == 0) {
        fprintf(stderr, "No audio device could be found: %s\n", SDL_GetError());
        return false;
    }

    SDL_PauseAudioDevice(audio_device, 0);

    // Usar el formato REAL que concede el dispositivo (no asumir 48k/2ch).
    output_sample_rate = spec_obtained.freq != 0 ? spec_obtained.freq : output_freq;
    output_channels = spec_obtained.channels != 0 ? spec_obtained.channels : output_channels;
    fprintf(stderr, "Audio device: %d Hz, %d ch\n", output_sample_rate, output_channels);
    hh::set_frequency(sample_rate);

    return true;
}

// Microcodigo de audio del ROM en 0x80036530 (ROM 0x37130), recompilado con RSPRecomp
// (config `config/rsp_hh_aspMain.toml`; texto 0xE98, base IMEM 0x1000). El motor de audio
// del juego es el que dispara la progresion del modulo (ver
// notes/2026-09-13-ucode-audio-gate-transicion.md).
extern RspExitReason hh_aspMain(uint8_t* rdram, uint32_t ucode_addr);

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
        return hh_aspMain;
    }
    // Tasks sin ucode registrado: el runtime las completa como no-op (dummy).
    hh::log("RSP ucode not registered: type=%" PRIu32 " (0x%08" PRIx32 ")\n", type, type);
    return nullptr;
}