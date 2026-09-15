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
        FILE* f = fopen("/tmp/hh_crash.log", "a");
        if (f) {
            if (auto e = std::current_exception()) {
                try { std::rethrow_exception(e); }
                catch (const std::exception& ex) { fprintf(f, "exception: %s\n", ex.what()); }
                catch (...) { fprintf(f, "exception: unknown\n"); }
            } else {
                fprintf(f, "terminate (no current exception)\n");
            }
            fclose(f);
        }
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

// Simbolos del runtime para los volcados de crash (RSP DMEM, contador de VI y contexto MIPS del
// hilo de juego en ejecucion).
extern uint8_t dmem[0x1000];
extern "C" uint64_t hh_get_vi_count(void);
extern "C" recomp_context* hh_get_current_ctx(void);

static void hh_dump_guest_regs(FILE* f) {
    recomp_context* c = hh_get_current_ctx();
    if (c == nullptr) {
        fprintf(f, "[CRASH] guest ctx no disponible (hilo fuera del juego?)\n");
        return;
    }
    fprintf(f, "[CRASH] guest r31/ra=%08X r29/sp=%08X r30/fp=%08X r28/gp=%08X\n",
            (uint32_t)c->r31, (uint32_t)c->r29, (uint32_t)c->r30, (uint32_t)c->r28);
    fprintf(f, "[CRASH] guest r4=%08X r5=%08X r6=%08X r7=%08X r2=%08X r3=%08X\n",
            (uint32_t)c->r4, (uint32_t)c->r5, (uint32_t)c->r6, (uint32_t)c->r7,
            (uint32_t)c->r2, (uint32_t)c->r3);
    fprintf(f, "[CRASH] guest r8=%08X r9=%08X r10=%08X r11=%08X r12=%08X r13=%08X r14=%08X r15=%08X\n",
            (uint32_t)c->r8, (uint32_t)c->r9, (uint32_t)c->r10, (uint32_t)c->r11,
            (uint32_t)c->r12, (uint32_t)c->r13, (uint32_t)c->r14, (uint32_t)c->r15);
    fprintf(f, "[CRASH] guest r16=%08X r17=%08X r18=%08X r19=%08X r20=%08X r21=%08X r22=%08X r23=%08X\n",
            (uint32_t)c->r16, (uint32_t)c->r17, (uint32_t)c->r18, (uint32_t)c->r19,
            (uint32_t)c->r20, (uint32_t)c->r21, (uint32_t)c->r22, (uint32_t)c->r23);
    fprintf(f, "[CRASH] guest r24=%08X r25=%08X r26=%08X r27=%08X hi=%08X lo=%08X\n",
            (uint32_t)c->r24, (uint32_t)c->r25, (uint32_t)c->r26, (uint32_t)c->r27,
            (uint32_t)c->hi, (uint32_t)c->lo);
}

#ifndef _WIN32
#include <csignal>
#include <ucontext.h>
#include <dlfcn.h>
static void hh_segv_handler(int sig, siginfo_t* info, void* uctx) {
    ucontext_t* uc = (ucontext_t*)uctx;
    void* rip = (void*)uc->uc_mcontext.gregs[REG_RIP];
    Dl_info di{};
    if (dladdr(rip, &di) != 0) {
        fprintf(stderr, "\n[SEGV] signal=%d addr=%p rip=%p base=%p sym=%s+%td\n",
            sig, info ? info->si_addr : nullptr, rip, di.dli_fbase,
            di.dli_sname ? di.dli_sname : "?", (char*)rip - (char*)di.dli_saddr);
    } else {
        fprintf(stderr, "\n[SEGV] signal=%d addr=%p rip=%p (sin simbolo)\n",
            sig, info ? info->si_addr : nullptr, rip);
    }
    uint64_t* sp = (uint64_t*)uc->uc_mcontext.gregs[REG_RSP];
    fprintf(stderr, "[SEGV] stack (base=%p):", (void*)di.dli_fbase);
    for (int i = 0; i < 40; i++) {
        fprintf(stderr, " %llX", (unsigned long long)sp[i]);
    }
    fprintf(stderr, "\n");
    // Volcado para analisis offline (junto al ejecutable / CWD).
    {
        FILE* f = fopen("hh_crash.log", "a");
        if (f != nullptr) {
            fprintf(f, "=== HH crash signal=%d addr=%p rip=%p VI=%llu\n",
                    sig, info ? info->si_addr : nullptr, rip,
                    (unsigned long long)hh_get_vi_count());
            if (di.dli_fname != nullptr) fprintf(f, "[CRASH] modulo: %s +0x%llX\n", di.dli_fname,
                    (unsigned long long)((char*)rip - (char*)di.dli_fbase));
            hh_dump_guest_regs(f);
            fflush(f); fclose(f);
        }
        uint8_t* rdram = hh::get_game_rdram();
        if (rdram != nullptr) {
            FILE* d = fopen("hh_crash_rdram.bin", "wb");
            if (d != nullptr) { fwrite(rdram, 1, 8u * 1024u * 1024u, d); fclose(d); }
        }
        FILE* d2 = fopen("hh_crash_dmem.bin", "wb");
        if (d2 != nullptr) { fwrite(dmem, 1, 0x1000, d2); fclose(d2); }
    }
    _exit(139);
}
#else
#include <windows.h>
static LONG WINAPI hh_win_exc_handler(EXCEPTION_POINTERS* ep) {
    const DWORD code = ep && ep->ExceptionRecord ? ep->ExceptionRecord->ExceptionCode : 0;
    void* addr = (ep && ep->ExceptionRecord) ? ep->ExceptionRecord->ExceptionAddress : nullptr;
    void* fault = nullptr;
    if (ep && ep->ExceptionRecord && ep->ExceptionRecord->NumberParameters >= 2) {
        fault = (void*)ep->ExceptionRecord->ExceptionInformation[1];
    }
    CONTEXT* c = ep ? ep->ContextRecord : nullptr;
    fprintf(stderr, "\n[SEGV] code=%08lX addr=%p rip=%p\n", (unsigned long)code, fault, addr);
    HMODULE hm = nullptr;
    char mod[MAX_PATH] = {0};
    unsigned long long mod_off = 0;
    if (addr != nullptr &&
        GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                           GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                           reinterpret_cast<LPCSTR>(addr), &hm) && hm != nullptr &&
        GetModuleFileNameA(hm, mod, sizeof(mod)) != 0) {
        mod_off = (unsigned long long)(reinterpret_cast<uintptr_t>(addr) - reinterpret_cast<uintptr_t>(hm));
        fprintf(stderr, "[SEGV] rip en modulo: %s +0x%llX\n", mod, mod_off);
    }
    if (c != nullptr) {
        fprintf(stderr, "[SEGV] rax=%p rbx=%p rcx=%p rdx=%p rsp=%p rbp=%p rsi=%p rdi=%p\n",
            (void*)c->Rax, (void*)c->Rbx, (void*)c->Rcx, (void*)c->Rdx,
            (void*)c->Rsp, (void*)c->Rbp, (void*)c->Rsi, (void*)c->Rdi);
    }
    fflush(stderr);
    // Volcado para analisis offline: hh_crash.log + RDRAM (8 MB) + DMEM del RSP (4 KB) en el CWD.
    static volatile LONG hh_crash_busy = 0;
    if (InterlockedExchange(&hh_crash_busy, 1) == 0) {
        FILE* f = fopen("hh_crash.log", "a");
        if (f != nullptr) {
            fprintf(f, "=== HH crash code=%08lX fault=%p rip=%p VI=%llu ===\n",
                    (unsigned long)code, fault, addr, (unsigned long long)hh_get_vi_count());
            if (mod[0] != 0) fprintf(f, "[CRASH] modulo: %s +0x%llX\n", mod, mod_off);
            if (c != nullptr) {
                fprintf(f, "rip=%016llX rsp=%016llX rbp=%016llX\n",
                        (unsigned long long)c->Rip, (unsigned long long)c->Rsp, (unsigned long long)c->Rbp);
                fprintf(f, "rax=%016llX rbx=%016llX rcx=%016llX rdx=%016llX\n",
                        (unsigned long long)c->Rax, (unsigned long long)c->Rbx,
                        (unsigned long long)c->Rcx, (unsigned long long)c->Rdx);
                fprintf(f, "rsi=%016llX rdi=%016llX r8=%016llX r9=%016llX r10=%016llX r11=%016llX\n",
                        (unsigned long long)c->Rsi, (unsigned long long)c->Rdi,
                        (unsigned long long)c->R8, (unsigned long long)c->R9,
                        (unsigned long long)c->R10, (unsigned long long)c->R11);
                fprintf(f, "r12=%016llX r13=%016llX r14=%016llX r15=%016llX\n",
                        (unsigned long long)c->R12, (unsigned long long)c->R13,
                        (unsigned long long)c->R14, (unsigned long long)c->R15);
            }
            hh_dump_guest_regs(f);
            uint8_t* rdram = hh::get_game_rdram();
            if (rdram != nullptr) {
                // Volcado por trozos de 256 KB con flush por trozo: si la memoria del juego esta
                // tocada, se conserva todo lo valido (antes un unico fwrite de 8 MB podia quedar a 0).
                FILE* d = fopen("hh_crash_rdram.bin", "wb");
                size_t total = 0;
                if (d != nullptr) {
                    constexpr size_t kChunk = 256u * 1024u;
                    constexpr size_t kTotal = 8u * 1024u * 1024u;
                    for (size_t off = 0; off < kTotal; off += kChunk) {
                        __try {
                            fwrite(rdram + off, 1, kChunk, d);
                            fflush(d);
                            total += kChunk;
                        } __except (EXCEPTION_EXECUTE_HANDLER) {
                            fprintf(f, "[CRASH] rdram: fallo en offset 0x%zX\n", off);
                            break;
                        }
                    }
                    fclose(d);
                    fprintf(f, "[CRASH] hh_crash_rdram.bin escrito: %zu bytes\n", total);
                }
            } else {
                fprintf(f, "[CRASH] rdram no disponible (crash durante el arranque?)\n");
            }
            __try {
                FILE* d = fopen("hh_crash_dmem.bin", "wb");
                if (d != nullptr) { fwrite(dmem, 1, 0x1000, d); fclose(d); }
            } __except (EXCEPTION_EXECUTE_HANDLER) {}
            fflush(f);
            fclose(f);
        }
    }
    return EXCEPTION_EXECUTE_HANDLER;
}
#endif

int main(int argc, char** argv) {
#if !defined(__SANITIZE_ADDRESS__) && !defined(_WIN32)
    struct sigaction hh_sa{};
    hh_sa.sa_sigaction = hh_segv_handler;
    hh_sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &hh_sa, nullptr);
    sigaction(SIGBUS, &hh_sa, nullptr);
#elif !defined(__SANITIZE_ADDRESS__)
    SetUnhandledExceptionFilter(hh_win_exc_handler);
#endif
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
    game_entry.on_init_callback = hh::on_game_init;
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

    hh::init_audio();
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

    return 0;
}