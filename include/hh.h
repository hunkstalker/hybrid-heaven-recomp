#pragma once

#include <cstdint>
#include <cstddef>
#include <filesystem>
#include <memory>
#include <string>

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/renderer_context.hpp"

#include "librecomp/rsp.hpp"

struct SDL_Window;

namespace hh {
    const char* get_version_string();

    void register_overlays();
    // Hooks de loader (add_loaded_function): deben registrarse en on_init, no antes.
    void register_runtime_functions();

    extern "C" {
        void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);
    }

    // Callback de init del runtime: guarda la RDRAM para leer el estado de UI (menus) en la capa
    // de input (perfiles de mando) y para los volcados de crash. Ver src/game/input.cpp.
    void on_game_init(uint8_t* rdram, recomp_context* ctx);
    uint8_t* get_game_rdram();

    std::filesystem::path get_app_folder_path();
    std::filesystem::path get_rom_path();

    void log(const char* fmt, ...);
    void error_box(const char* msg);
    std::string get_game_thread_name(const OSThread* t);
    void set_window_icon(SDL_Window* window);

    // Graphics callbacks.
    ultramodern::gfx_callbacks_t::gfx_data_t create_gfx();
    ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t gfx_data);
    void update_gfx(ultramodern::gfx_callbacks_t::gfx_data_t gfx_data);

    // Audio callbacks.
    void init_audio();                // inicializa SDL_INIT_AUDIO antes de reset_audio
    bool reset_audio(uint32_t output_freq);
    void queue_samples(int16_t* audio_data, size_t sample_count);
    size_t get_frames_remaining();
    void set_frequency(uint32_t freq);

    // Input callbacks.
    void poll_input();
    bool get_input(int controller_num, uint16_t* buttons, float* x, float* y);
    void set_rumble(int controller_num, bool rumble);
    ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num);

    // RSP microcode dispatch.
    RspUcodeFunc* get_rsp_microcode(const OSTask* task);

    // Renderer.
    std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(
        uint8_t* rdram,
        ultramodern::renderer::WindowHandle window_handle,
        bool developer_mode
    );

    // Config de video (config.ini [video]): resolucion nativa, aspecto, MSAA y ventana.
    struct VideoConfig {
        std::string wm = "borderless";   // borderless | windowed
        std::string res = "auto";        // auto | original | 2x | <n> | 8k
        std::string aspect = "auto";     // auto | original | expand | 4:3 | 16:9 | <float>
        std::string msaa = "8x";         // off | 2x | 4x | 8x
        double aspect_target = 0.0;      // ratio para aspect manual
    };
    const VideoConfig& video_config();
    VideoConfig& video_config_mutable();
    int desktop_height();                // alto del monitor principal (para res=auto)
    void video_apply_config();           // fija GraphicsConfig desde [video] (antes de crear el contexto)
    void video_toggle_fullscreen();      // Alt+Enter
    void video_cycle_aspect();           // F1
    void video_cycle_msaa();             // F2

    // Widescreen: snap del scissor de overscan a full-frame (adaptado de la referencia, Phase 07).
    bool full_frame_enabled();
    void snap_overscan(uint8_t* rdram, uint32_t list_address);
}

// Defined in RecompiledFuncs/lookup.cpp (C++ linkage).
gpr get_entrypoint_address();