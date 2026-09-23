#pragma once

#include <cstdint>
#include <cstddef>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/renderer_context.hpp"

#include "librecomp/rsp.hpp"

struct SDL_Window;

namespace hh {
    // Version del port. FUENTE UNICA: editar SOLO aqui al publicar un release; de estos valores se
    // derivan el string del log (get_version_string) y el recomp::Version del runtime.
    inline constexpr int kVersionMajor = 0;
    inline constexpr int kVersionMinor = 4;
    inline constexpr int kVersionPatch = 0;

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
    uint32_t audio_output_rate();     // tasa real del dispositivo de audio (para resamplear SFX)
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
    void video_toggle_fullscreen();      // F3
    void video_cycle_aspect();           // F2
    void video_cycle_msaa();             // F4

    // UI de desarrollo: true si el Inspector de RT64 (`HH_DEVELOPER=1` + F1) esta abierto. El
    // input del port no mapea el raton a botones N64 mientras lo esta, para no meter clics en el
    // juego al usar el panel. Se publica desde el hilo de render (ver rt64_render_context.cpp).
    bool dev_panel_open();

    // Widescreen: snap del scissor de overscan a full-frame (adaptado de la referencia, Phase 07).
    bool full_frame_enabled();
    void snap_overscan(uint8_t* rdram, uint32_t list_address);

    // Widescreen: trace temporal de identidades 2D (HH_HUD_TRACE=1); ver RETOMAR.md §3.1.
    bool hud_trace_enabled();
    void hud_trace(uint8_t* rdram, uint32_t list_address);
    // Diagnostico (HH_MENUTRACE=1): vuelca la DL del menú (hh_menudl.log) para localizar el text-emit.
    void menu_trace(uint8_t* rdram, uint32_t list_address);

    // Traduccion en runtime (spike textos; HH_LANG=es). Ver src/subsystems/text.cpp.
    bool text_enabled();
    // Gestion de idioma (base del selector, ADR 0008). El idioma se persiste en config.ini [lang].
    std::vector<std::string> text_available_languages();
    const std::string& text_current_language();
    void text_set_language(const std::string& code);
    void text_cycle_language();
    // Diagnostico: HH_LANG_CYCLE_AT=<seg> cicla una vez el idioma tras N segundos (validar el
    // cambio en vivo sin input). Llamar por frame. Ver src/subsystems/text.cpp.
    void text_debug_tick();

    // Overlay A2 (render hook de RT64): el handler del menú de título publica el frame del overlay
    // (game thread); `tick` (render thread) lo oculta si el menú deja de actualizarlo. Ver
    // src/hooks/menu_overlay.cpp e include/hh/overlay.h.
    namespace menu_overlay {
        void title_update(uint8_t* rdram);   // desde el handler del menú de título
        void tick();                          // por frame desde update_screen
        bool visible();
        void toggle();                        // F6
        // Calibración en vivo (Ctrl+flechas/etc.): suma a offset/escala y lo escribe en hh.log.
        void adjust(float dx, float dy, float dsx, float dsy);
    }

    // Efectos de sonido del menú (move/accept/back). Se mezclan sobre el stream del juego; los WAV
    // se cargan de `<app>/sounds/*.wav`. Ver src/platform/menu_sfx.cpp.
    namespace menu_sfx {
        enum class Sfx { Move, Accept, Back };
        void init();
        void play(Sfx s);
        void mix(int16_t* samples, size_t sample_count);   // desde hh::queue_samples
    }
}

// Traduce in-place un buffer en orden guest (antes de escribirlo a RDRAM). Devuelve n.º de
// sustituciones. Definido en src/subsystems/text.cpp.
extern "C" int hh_text_translate_guest(uint8_t* buf, size_t len);

// Re-aplica el idioma activo a los modulos ya cargados (cambio en vivo). Definido en
// src/subsystems/trans_cache.cpp.
extern "C" void hh_trans_reapply_language(void);

// Base RAM cargada de un modulo por (src, size) de ROM; 0 si no esta cargado. Definido en
// src/subsystems/trans_cache.cpp.
extern "C" uint32_t hh_trans_dst_for(uint32_t src, uint32_t size);

// Defined in RecompiledFuncs/lookup.cpp (C++ linkage).
gpr get_entrypoint_address();