#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstdlib>

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
    application->userConfig.graphicsAPI = to_rt64_graphics_api(config.api_option);
    application->userConfig.developerMode = config.developer_mode;

    // HH: el runtime no persiste GraphicsConfig (useConfigurationFile=false), así que el default
    // real es Original (240p escalado). Forzamos Auto (escalado entero a la ventana) por defecto,
    // configurable con HH_RES=original|2x|<n>.
    const char* res_env = getenv("HH_RES");
    std::string res = res_env != nullptr ? res_env : "auto";
    if (res == "original") {
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Original;
    }
    else if (!res.empty() && res.back() == 'x') {
        res.pop_back();
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = std::max(atoi(res.c_str()), 1);
    }
    else if (!res.empty() && res.find_first_not_of("0123456789") == std::string::npos) {
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = std::max(atoi(res.c_str()), 1);
    }
    else {
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
    }
}

static bool configs_equivalent(const ultramodern::renderer::GraphicsConfig& lhs, const ultramodern::renderer::GraphicsConfig& rhs) {
    return lhs == rhs;
}

hh::RT64Context::RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    // Set up the RT64 application core fields.
    RT64::Application::Core appCore{};
#if defined(_WIN32)
    appCore.window = window_handle.window;
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

    // Set the application's fullscreen state.
    app->setFullScreen(cur_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
}

hh::RT64Context::~RT64Context() = default;

bool hh::RT64Context::valid() {
    return app != nullptr;
}

void hh::RT64Context::send_dl(const OSTask* task) {
    hh::log("RT64: send_dl ucode=0x%x data_ptr=0x%x\n", task->t.ucode, task->t.data_ptr);
    app->state->rsp->reset();
    app->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
    app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
    last_dl_address = task->t.data_ptr;
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
    app->updateScreen();
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