#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <span>
#include <string>

#ifdef _WIN32
#define SDL_MAIN_HANDLED
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"

#include "librecomp/game.hpp"
#include "librecomp/overlays.hpp"
#include "librecomp/rsp.hpp"

#include "hh.h"
#include "hh_render.h"

#ifndef _WIN32
#include <csignal>
#include <cstring>
#include <unistd.h>
#include <unwind.h>
#include <dlfcn.h>
#include <cinttypes>

static _Unwind_Reason_Code unwind_cb(struct _Unwind_Context* ctx, void* arg) {
    FILE* f = (FILE*)arg;
    uintptr_t pc = _Unwind_GetIP(ctx);
    Dl_info info{};
    if (dladdr((void*)pc, &info) != 0 && info.dli_sname != nullptr) {
        fprintf(f, "  0x%" PRIxPTR "  %s (+0x%" PRIxPTR ")\n", pc, info.dli_sname, pc - (uintptr_t)info.dli_fbase);
    } else {
        fprintf(f, "  0x%" PRIxPTR "  <unknown> (+0x%" PRIxPTR ")\n", pc, pc);
    }
    return _URC_NO_REASON;
}

static uintptr_t get_main_image_base() {
    Dl_info info{};
    // unwind_cb is defined above, so it's visible here; any symbol in this image works.
    if (dladdr(reinterpret_cast<void*>(&unwind_cb), &info) != 0) {
        return (uintptr_t)info.dli_fbase;
    }
    return 0;
}

static void crash_dump(const char* what) {
    FILE* f = fopen("/tmp/hh_crash.log", "a");
    if (f) {
        uintptr_t base = get_main_image_base();
        fprintf(f, "=== %s (pid %d) main_base=0x%" PRIxPTR " ===\n", what, getpid(), base);
        _Unwind_Backtrace(unwind_cb, f);
        fflush(f);
        fclose(f);
    }
}

static void crash_handler(int sig, siginfo_t* info, void* ucontext_void) {
    FILE* f = fopen("/tmp/hh_crash.log", "a");
    if (f) {
        fprintf(f, "signal=%d", sig);
        if (info) {
            fprintf(f, " si_addr=0x%lx", (unsigned long)info->si_addr);
        }
        if (ucontext_void) {
            auto* uc = (ucontext_t*)ucontext_void;
            fprintf(f, " rip=0x%lx", (unsigned long)uc->uc_mcontext.gregs[REG_RIP]);
        }
        fprintf(f, "\n");
        fclose(f);
    }
    crash_dump("signal");
    _exit(128 + sig);
}

static void install_crash_handlers() {
    if (getenv("HH_CRASH_LOG") == nullptr) return;
    std::set_terminate([] {
        crash_dump("terminate");
        _exit(1);
    });
    struct sigaction sa{};
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = crash_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGSEGV, &sa, nullptr);
    sigaction(SIGABRT, &sa, nullptr);
}
#endif

int main(int argc, char** argv) {
    auto app_folder_path = hh::get_app_folder_path();
#ifndef _WIN32
    install_crash_handlers();
#endif

    recomp::Version version = recomp::Version(0, 1, 0);
    recomp::register_config_path(app_folder_path);

    hh::log("=== Hybrid Heaven Recomp starting ===\n");
    hh::log("version %s\n", hh::get_version_string());
    hh::log("app folder: %s\n", app_folder_path.string().c_str());
    hh::log("argc=%d argv0=%s\n", argc, argc > 0 ? argv[0] : "?");

    // Basic video game information.
    recomp::GameEntry game_entry{};
    game_entry.is_enabled = false;
    game_entry.rom_hash = 0x0F6A72F2C36A216DULL; // Hybrid Heaven (USA) retail 16MB (work/roms/us_retail.z64)
    game_entry.game_id = u8"hh.us";
    game_entry.mod_game_id = "";
    game_entry.internal_name = "Hybrid Heaven";
    game_entry.display_name = "Hybrid Heaven";
    game_entry.save_type = recomp::SaveType::None;
    game_entry.on_init_callback = nullptr;
    game_entry.entrypoint_address = get_entrypoint_address();
    game_entry.entrypoint = hh::recomp_entrypoint;
    game_entry.has_compressed_code = false;
    recomp::register_game(game_entry);

    std::u8string game_id = u8"hh.us";
    hh::log("rom path candidate: %s\n", hh::get_rom_path().string().c_str());
    recomp::RomValidationError err = recomp::select_rom(hh::get_rom_path(), game_id);
    hh::log("select_rom result: %d (0=Good)\n", static_cast<int>(err));
    if (err != recomp::RomValidationError::Good) {
        hh::error_box("Couldn't find a valid ROM.\nMake sure to place the Hybrid Heaven (USA) N64 ROM (baserom.us.z64) in the application folder or in the working directory.");
        hh::log("ROM validation FAILED\n");
        return 1;
    }
    hh::log("ROM validated OK\n");

    hh::register_overlays();
    hh::log("overlays registered\n");

    // Configure the audio.
    ultramodern::audio_callbacks_t audio_callbacks{};
    audio_callbacks.queue_samples = hh::queue_samples;
    audio_callbacks.get_frames_remaining = hh::get_frames_remaining;
    audio_callbacks.set_frequency = hh::set_frequency;

    // Configure the input.
    ultramodern::input::callbacks_t input_callbacks{};
    input_callbacks.poll_input = hh::poll_input;
    input_callbacks.get_input = hh::get_input;
    input_callbacks.set_rumble = hh::set_rumble;
    input_callbacks.get_connected_device_info = hh::get_connected_device_info;

    // Configure the graphics.
    ultramodern::gfx_callbacks_t gfx_callbacks{};
    gfx_callbacks.create_gfx = hh::create_gfx;
    gfx_callbacks.create_window = hh::create_window;
    gfx_callbacks.update_gfx = hh::update_gfx;

    // Configure the renderer.
    ultramodern::renderer::callbacks_t renderer_callbacks{};
    renderer_callbacks.create_render_context = hh::create_render_context;

    // Configure the game events.
    ultramodern::events::callbacks_t events_callbacks{};
    events_callbacks.vi_callback = nullptr;
    events_callbacks.gfx_init_callback = nullptr;

    // Configure error handling.
    ultramodern::error_handling::callbacks_t error_callbacks{};
    error_callbacks.message_box = hh::error_box;

    // Configure the threads.
    ultramodern::threads::callbacks_t threads_callbacks{};
    threads_callbacks.get_game_thread_name = hh::get_game_thread_name;

    // Configure the RSP.
    recomp::rsp::callbacks_t rsp_callbacks{};
    rsp_callbacks.get_rsp_microcode = hh::get_rsp_microcode;

    // Set up the configuration for the recomp runtime.
    recomp::Configuration configuration{};
    configuration.argc = argc;
    configuration.argv = argv;
    configuration.project_version = version;
    configuration.window_handle = {};
    configuration.rsp_callbacks = rsp_callbacks;
    configuration.renderer_callbacks = renderer_callbacks;
    configuration.audio_callbacks = audio_callbacks;
    configuration.input_callbacks = input_callbacks;
    configuration.gfx_callbacks = gfx_callbacks;
    configuration.events_callbacks = events_callbacks;
    configuration.error_handling_callbacks = error_callbacks;
    configuration.threads_callbacks = threads_callbacks;

    hh::reset_audio(48000);
    hh::log("audio reset done\n");

    // Set the game status to Running BEFORE recomp::start. The game thread created inside
    // recomp::start blocks until game_status != None, and recomp::start never returns (it sits
    // in a `while (!exited)` loop), so start_game must be issued beforehand for the boot to run.
    hh::log("calling recomp::start_game (before start)\n");
    recomp::start_game(game_id, "");
    hh::log("start_game issued\n");

    hh::log("calling recomp::start\n");
    recomp::start(configuration);
    hh::log("recomp::start returned\n");

    while (true) {
        SDL_Delay(100);
    }
}