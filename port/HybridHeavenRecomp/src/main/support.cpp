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

static uint32_t sample_rate = 48000;
static uint32_t output_sample_rate = 48000;
constexpr uint32_t input_channels = 2;
static uint32_t output_channels = 2;
constexpr uint32_t bytes_per_sample = input_channels * sizeof(int16_t);
static std::vector<uint8_t> audio_cvt_buffer;

void hh::queue_samples(int16_t* audio_data, size_t sample_count) {
    const size_t byte_len = sample_count * bytes_per_sample;
    const size_t needed = static_cast<size_t>(byte_len * audio_convert.len_ratio) + 1;
    if (audio_cvt_buffer.size() < needed) {
        audio_cvt_buffer.resize(needed);
    }

    std::memcpy(audio_cvt_buffer.data(), audio_data, byte_len);
    audio_convert.buf = audio_cvt_buffer.data();
    audio_convert.len = static_cast<int>(byte_len);

    if (SDL_ConvertAudio(&audio_convert) < 0) {
        fprintf(stderr, "Error using SDL audio converter: %s\n", SDL_GetError());
        return;
    }

    SDL_QueueAudio(audio_device, audio_convert.buf, audio_convert.len_cvt);
}

size_t hh::get_frames_remaining() {
    return static_cast<size_t>(SDL_GetQueuedAudioSize(audio_device) / (input_channels * sizeof(int16_t)));
}

void hh::set_frequency(uint32_t freq) {
    sample_rate = freq;

    int ret = SDL_BuildAudioCVT(
        &audio_convert,
        AUDIO_S16, static_cast<Uint8>(input_channels), static_cast<int>(sample_rate),
        AUDIO_S16, static_cast<Uint8>(output_channels), static_cast<int>(output_sample_rate)
    );

    if (ret < 0) {
        fprintf(stderr, "Error creating SDL audio converter: %s\n", SDL_GetError());
    }
}

bool hh::reset_audio(uint32_t output_freq) {
    SDL_AudioSpec spec_desired{};
    spec_desired.freq = static_cast<int>(output_freq);
    spec_desired.format = AUDIO_S16;
    spec_desired.channels = static_cast<Uint8>(output_channels);
    spec_desired.samples = 0x100;

    audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, nullptr, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (audio_device == 0) {
        fprintf(stderr, "No audio device could be found: %s\n", SDL_GetError());
        return false;
    }

    SDL_PauseAudioDevice(audio_device, 0);

    output_sample_rate = output_freq;
    hh::set_frequency(48000);

    return true;
}

RspUcodeFunc* hh::get_rsp_microcode(const OSTask* task) {
    // The audio (aspMain) RSP ucode has not been recompiled yet.
    uint32_t type = task->t.type;
    fprintf(stderr, "No registered RSP ucode for task type %" PRIu32 "\n", type);
    hh::log("RSP ucode not registered: type=%" PRIu32 " (0x%08" PRIx32 ")\n", type, type);
    return nullptr;
}