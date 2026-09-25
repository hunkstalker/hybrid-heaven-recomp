#include <algorithm>
#include <atomic>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#define HLSL_CPU
#include "hle/rt64_application.h"

#if defined(__linux__)
#include "X11/Xlib.h"
// The bundled nativefiledialog (GTK) and SDL2 headers pull in Xlib, which defines the `None`
// macro that clashes with `ultramodern::input::Device::None`. Undo it before anything else.
#undef None
#endif

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"

#include "hh_render.h"
#include "hh.h"
#include "hh/hudrewrite.h"

#if defined(_WIN32)
// Para la captura de imagen (F10): HWND + GDI. Se incluye DESPUES de los headers de RT64 y SIN
// `WIN32_LEAN_AND_MEAN`: ese macro excluye las cabeceras COM (IUnknown/IStream/BSTR) que necesita
// `dxcapi.h` (que entra por los headers DirectX de RT64) -> errores C2504/C2061. `NOMINMAX` ya lo
// define el CMake del proyecto.
#include <windows.h>
#endif

static uint8_t DMEM[0x1000];
static uint8_t IMEM[0x1000];

unsigned int MI_INTR_REG = 0;

unsigned int DPC_START_REG = 0;
unsigned int DPC_END_REG = 0;
unsigned int DPC_CURRENT_REG = 0;
unsigned int DPC_STATUS_REG = 0;
unsigned int DPC_CLOCK_REG = 0;
unsigned int DPC_BUFBUSY_REG = 0;
unsigned int DPC_PIPEBUSY_REG = 0;
unsigned int DPC_TMEM_REG = 0;

static void dummy_check_interrupts() {}

namespace {
// HH_FPS=1: contadores para medir la tasa real de present (update_screen) y de display lists.
std::atomic<uint64_t> g_hh_dl_count{ 0 };

#if defined(_WIN32)
// Ventana nativa (HWND) para la captura de imagen pareada a la traza HUD (F10). Ver dl_snap.cpp.
void* g_capture_window = nullptr;

// BMP 32bpp sin compresion. `bgra_topdown` es la fila 0 = arriba; el BMP se escribe de abajo arriba.
bool write_bmp32(const char* path, int w, int h, const uint8_t* bgra_topdown) {
    if (w <= 0 || h <= 0 || bgra_topdown == nullptr) return false;
    const uint32_t row = static_cast<uint32_t>(w) * 4u;
    const uint32_t data = row * static_cast<uint32_t>(h);
    uint8_t hdr[54] = {0};
    hdr[0] = 'B'; hdr[1] = 'M';
    const uint32_t file_size = 54u + data;
    std::memcpy(hdr + 2, &file_size, 4);
    const uint32_t off = 54u;
    std::memcpy(hdr + 10, &off, 4);
    const uint32_t ih = 40u;
    std::memcpy(hdr + 14, &ih, 4);
    const int32_t sw = w, sh = h;
    std::memcpy(hdr + 18, &sw, 4);
    std::memcpy(hdr + 22, &sh, 4);
    const uint16_t planes = 1, bpp = 32;
    std::memcpy(hdr + 26, &planes, 2);
    std::memcpy(hdr + 28, &bpp, 2);
    std::memcpy(hdr + 34, &data, 4);
    std::FILE* f = std::fopen(path, "wb");
    if (f == nullptr) return false;
    std::fwrite(hdr, 1, sizeof hdr, f);
    for (int y = h - 1; y >= 0; --y) {
        std::fwrite(bgra_topdown + static_cast<size_t>(y) * row, 1, row, f);
    }
    std::fclose(f);
    return true;
}

// true si todos los pixeles son exactamente negros (captura fallida de una swapchain).
bool is_blank(const uint8_t* bgra, int w, int h) {
    const size_t n = static_cast<size_t>(w) * h;
    for (size_t i = 0; i < n; ++i) {
        const uint8_t* p = bgra + i * 4;
        if (p[0] | p[1] | p[2]) return false;
    }
    return true;
}

// Captura el area cliente de la ventana. Con swapchains D3D12/Vulkan, `PrintWindow` +
// PW_RENDERFULLCONTENT es lo que funciona; si devuelve negro, se reintenta con `BitBlt`.
bool capture_window_bmp(const char* path) {
    HWND hwnd = static_cast<HWND>(g_capture_window);
    if (hwnd == nullptr) return false;
    RECT rc{};
    if (!GetClientRect(hwnd, &rc)) return false;
    const int w = rc.right - rc.left, h = rc.bottom - rc.top;
    if (w <= 0 || h <= 0) return false;
    HDC wdc = GetDC(hwnd);
    if (wdc == nullptr) return false;
    HDC mdc = CreateCompatibleDC(wdc);
    BITMAPINFO bi{};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -h;   // top-down
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HBITMAP bmp = CreateDIBSection(wdc, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    bool ok = false;
    if (bmp != nullptr && mdc != nullptr && bits != nullptr) {
        HGDIOBJ old = SelectObject(mdc, bmp);
#ifndef PW_RENDERFULLCONTENT
#define PW_RENDERFULLCONTENT 0x00000002
#endif
        ok = PrintWindow(hwnd, mdc, PW_RENDERFULLCONTENT) != 0;
        if (!ok || is_blank(static_cast<const uint8_t*>(bits), w, h)) {
            std::memset(bits, 0, static_cast<size_t>(w) * h * 4u);
            ok = BitBlt(mdc, 0, 0, w, h, wdc, 0, 0, SRCCOPY) != 0;
        }
        SelectObject(mdc, old);
        if (ok) ok = write_bmp32(path, w, h, static_cast<const uint8_t*>(bits));
    }
    if (bmp != nullptr) DeleteObject(bmp);
    if (mdc != nullptr) DeleteDC(mdc);
    ReleaseDC(hwnd, wdc);
    return ok;
}
#endif  // _WIN32
}

static ultramodern::renderer::SetupResult map_setup_result(RT64::Application::SetupResult setup_result) {
    switch (setup_result) {
        case RT64::Application::SetupResult::Success:
            return ultramodern::renderer::SetupResult::Success;
        case RT64::Application::SetupResult::DynamicLibrariesNotFound:
            return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
        case RT64::Application::SetupResult::InvalidGraphicsAPI:
            return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
        case RT64::Application::SetupResult::GraphicsAPINotFound:
            return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
        case RT64::Application::SetupResult::GraphicsDeviceNotFound:
            return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
    }

    assert(false);
    std::exit(EXIT_FAILURE);
}

static ultramodern::renderer::GraphicsApi map_graphics_api(RT64::UserConfiguration::GraphicsAPI graphics_api) {
    switch (graphics_api) {
        case RT64::UserConfiguration::GraphicsAPI::D3D12:
            return ultramodern::renderer::GraphicsApi::D3D12;
        case RT64::UserConfiguration::GraphicsAPI::Vulkan:
            return ultramodern::renderer::GraphicsApi::Vulkan;
        case RT64::UserConfiguration::GraphicsAPI::Metal:
            return ultramodern::renderer::GraphicsApi::Metal;
        case RT64::UserConfiguration::GraphicsAPI::Automatic:
            return ultramodern::renderer::GraphicsApi::Auto;
    }

    fprintf(stderr, "Unhandled `RT64::UserConfiguration::GraphicsAPI` ?\n");
    assert(false);
    std::exit(EXIT_FAILURE);
}

static RT64::UserConfiguration::GraphicsAPI to_rt64_graphics_api(ultramodern::renderer::GraphicsApi graphics_api) {
    switch (graphics_api) {
        case ultramodern::renderer::GraphicsApi::D3D12:
            return RT64::UserConfiguration::GraphicsAPI::D3D12;
        case ultramodern::renderer::GraphicsApi::Vulkan:
            return RT64::UserConfiguration::GraphicsAPI::Vulkan;
        case ultramodern::renderer::GraphicsApi::Metal:
            return RT64::UserConfiguration::GraphicsAPI::Metal;
        case ultramodern::renderer::GraphicsApi::Auto:
            return RT64::UserConfiguration::GraphicsAPI::Automatic;
        default:
            return RT64::UserConfiguration::GraphicsAPI::Automatic;
    }
}

static void set_application_user_config(RT64::Application* application, const ultramodern::renderer::GraphicsConfig& config) {
    // API grafica: env HH_GRAPHICS_API=d3d12|vulkan|metal|auto (default: lo que diga la config).
    {
        const char* api = getenv("HH_GRAPHICS_API");
        if (api != nullptr && *api != '\0') {
            const std::string a = api;
            if (a == "d3d12")       application->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::D3D12;
            else if (a == "vulkan") application->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Vulkan;
            else if (a == "metal")  application->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Metal;
            else                    application->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic;
        }
        else {
            application->userConfig.graphicsAPI = to_rt64_graphics_api(config.api_option);
        }
    }
    application->userConfig.developerMode = config.developer_mode;
    // HH_DEVELOPER=1: habilita el modo desarrollador de RT64 -> Inspector (ImGui) con FPS/frametimes
    // y shortcuts F1-F4 (ojo: con dev-mode RT64 consume F1-F4 y el F1/F2/F3 del port no actuan).
    if (const char* dev = getenv("HH_DEVELOPER"); dev != nullptr && *dev != '\0' && *dev != '0') {
        application->userConfig.developerMode = true;
    }

    // Resolucion: HH_RES (env) > [video].res > auto (nativa del monitor: alto/240, tope 32).
    const hh::VideoConfig& v = hh::video_config();
    const char* res_env = getenv("HH_RES");
    std::string res = (res_env != nullptr && *res_env != '\0') ? res_env : v.res;
    auto manual_mult = [](int m) { return std::clamp(m, 1, 32); };
    if (res == "original") {
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Original;
    }
    else if (!res.empty() && (res.back() == 'k' || res.back() == 'K')) {
        const int k = std::max(atoi(res.c_str()), 1);   // "4k"->2160, "8k"->4320 de alto
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = manual_mult((k * 540) / 240);
    }
    else if (!res.empty() && res.back() == 'x') {
        res.pop_back();
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = manual_mult(std::max(atoi(res.c_str()), 1));
    }
    else if (!res.empty() && res.find_first_not_of("0123456789") == std::string::npos) {
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = manual_mult(std::max(atoi(res.c_str()), 1));
    }
    else {
        // auto: resolucion nativa del monitor (alto/240).
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = manual_mult(hh::desktop_height() / 240);
    }

    // Aspecto (Original/Expand/Manual+target).
    switch (config.ar_option) {
        case ultramodern::renderer::AspectRatio::Expand:
            application->userConfig.aspectRatio = RT64::UserConfiguration::AspectRatio::Expand;
            application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Expand;
            break;
        case ultramodern::renderer::AspectRatio::Manual: {
            const double t = (v.aspect_target > 0.0) ? v.aspect_target : (4.0 / 3.0);
            application->userConfig.aspectRatio = RT64::UserConfiguration::AspectRatio::Manual;
            application->userConfig.aspectTarget = t;
            application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Manual;
            application->userConfig.extAspectTarget = t;
            break;
        }
        case ultramodern::renderer::AspectRatio::Original:
        default:
            application->userConfig.aspectRatio = RT64::UserConfiguration::AspectRatio::Original;
            application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Original;
            break;
    }

    // Antialiasing (MSAA).
    switch (config.msaa_option) {
        case ultramodern::renderer::Antialiasing::None:
            application->userConfig.antialiasing = RT64::UserConfiguration::Antialiasing::None; break;
        case ultramodern::renderer::Antialiasing::MSAA2X:
            application->userConfig.antialiasing = RT64::UserConfiguration::Antialiasing::MSAA2X; break;
        case ultramodern::renderer::Antialiasing::MSAA4X:
            application->userConfig.antialiasing = RT64::UserConfiguration::Antialiasing::MSAA4X; break;
        case ultramodern::renderer::Antialiasing::MSAA8X:
        default:
            application->userConfig.antialiasing = RT64::UserConfiguration::Antialiasing::MSAA8X; break;
    }

    // Refresh Rate (RT64): Original = ritmo del juego (30 Hz); Display = al refresco del monitor
    // (RT64 interpola y presenta a esa tasa -> movimiento suave). Manual:<hz> = tasa fija.
    // Env: HH_REFRESH_RATE=original|display|manual:<hz>. Default: display (high frame rate).
    {
        const char* rr = getenv("HH_REFRESH_RATE");
        const std::string s = (rr != nullptr && *rr != '\0') ? rr : "display";
        if (s == "display") {
            application->userConfig.refreshRate = RT64::UserConfiguration::RefreshRate::Display;
        }
        else if (s.rfind("manual", 0) == 0) {
            const auto colon = s.find(':');
            const int hz = (colon != std::string::npos) ? atoi(s.c_str() + colon + 1) : 0;
            application->userConfig.refreshRate = RT64::UserConfiguration::RefreshRate::Manual;
            application->userConfig.refreshRateTarget = (hz > 0) ? hz : 60;
        }
        else {
            application->userConfig.refreshRate = RT64::UserConfiguration::RefreshRate::Original;
        }
        hh::log("RT64: refresh rate mode = %s\n", s.c_str());
    }

    // Diagnostico: valores REALES que quedan en RT64 (no solo la intencion).
    const uint32_t aa_samples = application->userConfig.msaaSampleCount();
    hh::log("RT64 userConfig: res=%s resolution=%d mult=%.2f aspectRatio=%d aspectTarget=%.3f"
            " extAspect=%d extAspectTarget=%.3f aa=%d samples=%u\n",
            res.c_str(), (int)application->userConfig.resolution,
            application->userConfig.resolutionMultiplier,
            (int)application->userConfig.aspectRatio, application->userConfig.aspectTarget,
            (int)application->userConfig.extAspectRatio, application->userConfig.extAspectTarget,
            (int)application->userConfig.antialiasing, (unsigned)aa_samples);
    fprintf(stderr, "[VIDEO] aplicado: resolution=%d mult=%.2f aspectRatio=%d (target %.3f) msaa=%d (%u samples)\n",
            (int)application->userConfig.resolution, application->userConfig.resolutionMultiplier,
            (int)application->userConfig.aspectRatio, application->userConfig.aspectTarget,
            (int)application->userConfig.antialiasing, (unsigned)aa_samples);
}

static bool configs_equivalent(const ultramodern::renderer::GraphicsConfig& lhs, const ultramodern::renderer::GraphicsConfig& rhs) {
    return lhs == rhs;
}

hh::RT64Context::RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    // Set up the RT64 application core fields.
    RT64::Application::Core appCore{};
#if defined(_WIN32)
    appCore.window = window_handle.window;
    g_capture_window = window_handle.window;   // HWND para la captura de imagen (F10)
#elif defined(__linux__) || defined(__ANDROID__)
    appCore.window = window_handle;
#elif defined(__APPLE__)
    appCore.window.window = window_handle.window;
    appCore.window.view = window_handle.view;
#endif

    appCore.checkInterrupts = dummy_check_interrupts;

    static unsigned char dummy_rom_header[0x40];

    appCore.HEADER = dummy_rom_header;
    appCore.RDRAM = rdram;
    appCore.DMEM = DMEM;
    appCore.IMEM = IMEM;

    appCore.MI_INTR_REG = &MI_INTR_REG;

    appCore.DPC_START_REG = &DPC_START_REG;
    appCore.DPC_END_REG = &DPC_END_REG;
    appCore.DPC_CURRENT_REG = &DPC_CURRENT_REG;
    appCore.DPC_STATUS_REG = &DPC_STATUS_REG;
    appCore.DPC_CLOCK_REG = &DPC_CLOCK_REG;
    appCore.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
    appCore.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
    appCore.DPC_TMEM_REG = &DPC_TMEM_REG;

    ultramodern::renderer::ViRegs* vi_regs = ultramodern::renderer::get_vi_regs();

    appCore.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
    appCore.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
    appCore.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
    appCore.VI_INTR_REG = &vi_regs->VI_INTR_REG;
    appCore.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
    appCore.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
    appCore.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
    appCore.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
    appCore.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
    appCore.VI_H_START_REG = &vi_regs->VI_H_START_REG;
    appCore.VI_V_START_REG = &vi_regs->VI_V_START_REG;
    appCore.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
    appCore.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
    appCore.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;

    // Set up the RT64 application configuration fields.
    RT64::ApplicationConfiguration appConfig{};
    appConfig.appId = "hybrid-heaven";
    appConfig.useConfigurationFile = false;

    // Create the RT64 application.
    app = std::make_unique<RT64::Application>(appCore, appConfig);

    // Set initial user config settings based on the current settings.
    const auto& cur_config = ultramodern::renderer::get_graphics_config();
    set_application_user_config(app.get(), cur_config);

    // Force gbi depth branches to prevent LODs from kicking in.
    app->enhancementConfig.f3dex.forceBranch = true;

    // Set up the RT64 application.
    uint32_t thread_id = 0;
#ifdef _WIN32
    thread_id = window_handle.thread_id;
#endif
    hh::log("RT64: calling app->setup(thread_id=%u)\n", thread_id);
    setup_result = map_setup_result(app->setup(thread_id));
    // Get the API that RT64 chose.
    chosen_api = map_graphics_api(app->chosenGraphicsAPI);
    hh::log("RT64: setup_result=%d chosen_api=%d\n", static_cast<int>(setup_result), static_cast<int>(chosen_api));

    if (setup_result != ultramodern::renderer::SetupResult::Success) {
        hh::log("RT64: setup FAILED\n");
        app = nullptr;
        return;
    }
    hh::log("RT64: setup SUCCESS\n");

    // High frame rate: presenta cada frame en cuanto se dibuja (menos latencia; como la referencia).
    // Default ON; `HH_PRESENT_EARLY=0` lo desactiva (comportamiento anterior).
    static const bool present_early = [] {
        const char* e = std::getenv("HH_PRESENT_EARLY");
        return e == nullptr || *e == '\0' || (*e != '0');
    }();
    if (present_early) {
        enable_instant_present();
        hh::log("RT64: PresentEarly ON\n");
    }

    // HH: el MSAA de RT64 requiere sample locations; si el dispositivo no las soporta,
    // updateMultisampling() no aplica nada. Se registra para diagnostico.
    hh::log("RT64: sampleLocations=%d\n", (int)app->device->getCapabilities().sampleLocations);

    // Set the application's fullscreen state.
    app->setFullScreen(cur_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
}

hh::RT64Context::~RT64Context() = default;

bool hh::RT64Context::valid() {
    return app != nullptr;
}

void hh::RT64Context::send_dl(const OSTask* task) {
    g_hh_dl_count.fetch_add(1, std::memory_order_relaxed);
    hh::log("RT64: send_dl ucode=0x%x data_ptr=0x%x\n", task->t.ucode, task->t.data_ptr);
    // Widescreen: reescribe el scissor de overscan a full-frame antes de que RT64 procese la lista.
    hh::snap_overscan(app->core.RDRAM, task->t.data_ptr);
    // Widescreen: trace temporal de identidades 2D (HH_HUD_TRACE=1).
    hh::hud_trace(app->core.RDRAM, task->t.data_ptr);
    // Widescreen: anclaje del HUD. Si hay elementos clasificados, envia la copia reescrita.
    uint32_t data_ptr = task->t.data_ptr;
    if (const uint32_t rewritten = hh::hudrewrite::rewrite(app->core.RDRAM, data_ptr)) {
        data_ptr = rewritten;
    }
    app->state->rsp->reset();
    app->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
    app->processDisplayLists(app->core.RDRAM, data_ptr & 0x3FFFFFF, 0, true);
    last_dl_address = data_ptr;
}

void hh::RT64Context::send_dummy_workload(uint32_t fb_address) {
    (void)fb_address;
    // A new framebuffer was set up without an associated display list (e.g. after a VI mode
    // change). Replay the last submitted display list so that the new framebuffer gets rendered
    // instead of leaving a stale/black image on screen.
    if (last_dl_address != 0) {
        app->state->rsp->reset();
        app->processDisplayLists(app->core.RDRAM, last_dl_address & 0x3FFFFFF, 0, true);
    }
}

void hh::RT64Context::update_screen() {
    // HH_FPS=1: registra 1 vez por segundo la tasa real de present (llamadas a update_screen) y
    // cuantas display lists se enviaron en ese intervalo. Sirve para medir sin overlay ni dev-mode.
    static const bool fps_log = [] {
        const char* e = std::getenv("HH_FPS");
        return e != nullptr && *e != '\0' && *e != '0';
    }();
    if (fps_log) {
        static uint64_t frames = 0, dl_last = 0;
        static auto t0 = std::chrono::steady_clock::now();
        ++frames;
        const auto now = std::chrono::steady_clock::now();
        const double secs = std::chrono::duration<double>(now - t0).count();
        if (secs >= 1.0) {
            const uint64_t dl = g_hh_dl_count.load(std::memory_order_relaxed);
            hh::log("[hh-fps] %.1f fps | %llu display lists | swapChainRate=%u refresh=%d (%.2fs)\n",
                    frames / secs, static_cast<unsigned long long>(dl - dl_last),
                    get_display_framerate(), static_cast<int>(app->userConfig.refreshRate), secs);
            frames = 0;
            dl_last = dl;
            t0 = now;
        }
    }
    app->updateScreen();

    // Captura pareada (F10): en el present que sigue a la traza, guardar la imagen de la ventana.
    // Junto con `hh_cap_<n>.log` (mismo instante) permite atar cada `box` del trace a lo que se ve.
    if (hh::hud_capture_pending()) {
        bool ok = false;
#if defined(_WIN32)
        ok = capture_window_bmp(hh::hud_capture_image_path());
#else
        (void)ok;
#endif
        hh::log("[hh-cap] imagen %s: %s\n", hh::hud_capture_image_path(), ok ? "ok" : "FALLO");
        hh::hud_capture_finish();
    }
}

void hh::RT64Context::shutdown() {
    if (app != nullptr) {
        app->end();
    }
}

bool hh::RT64Context::update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) {
    if (configs_equivalent(old_config, new_config)) {
        return false;
    }

    if (new_config.wm_option != old_config.wm_option) {
        app->setFullScreen(new_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
    }

    set_application_user_config(app.get(), new_config);

    app->updateUserConfig(true);

    if (new_config.msaa_option != old_config.msaa_option) {
        app->updateMultisampling();
    }
    return true;
}

void hh::RT64Context::enable_instant_present() {
    // Enable the present early presentation mode for minimal latency.
    app->enhancementConfig.presentation.mode = RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
    app->updateEnhancementConfig();
}

uint32_t hh::RT64Context::get_display_framerate() const {
    return app->presentQueue->ext.sharedResources->swapChainRate;
}

float hh::RT64Context::get_resolution_scale() const {
    constexpr int ReferenceHeight = 240;
    switch (app->userConfig.resolution) {
        case RT64::UserConfiguration::Resolution::WindowIntegerScale:
            if (app->sharedQueueResources->swapChainHeight > 0) {
                return std::max(float((app->sharedQueueResources->swapChainHeight + ReferenceHeight - 1) / ReferenceHeight), 1.0f);
            }
            return 1.0f;
        case RT64::UserConfiguration::Resolution::Manual:
            return float(app->userConfig.resolutionMultiplier);
        case RT64::UserConfiguration::Resolution::Original:
        default:
            return 1.0f;
    }
}

std::unique_ptr<ultramodern::renderer::RendererContext> hh::create_render_context(
    uint8_t* rdram,
    ultramodern::renderer::WindowHandle window_handle,
    bool developer_mode
) {
    return std::make_unique<hh::RT64Context>(rdram, window_handle, developer_mode);
}