#include <cinttypes>
#include <chrono>
#include <atomic>
#include <thread>

// Necesarios antes de los handlers de crash (pid para nombres de volcado unicos).
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
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
extern "C" int hh_get_thread_ctxs(recomp_context** out, int max);
extern "C" unsigned long long hh_get_input_polls(void);
extern "C" uint64_t hh_get_vi_ticks(void);
extern "C" uint64_t hh_get_pending_ext_msgs(void);
extern "C" unsigned long long hh_get_audio_calls(void);

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

// Volcados grandes (RDRAM 8 MB y DMEM 4 KB). En Windows por trozos con SEH para tolerar memoria
// corrupta; en Linux de una vez. `base` = prefijo ("hh_crash" o "hh_hang").
static unsigned long hh_process_id() {
#ifdef _WIN32
    return (unsigned long)GetCurrentProcessId();
#else
    return (unsigned long)getpid();
#endif
}

static void hh_dump_rdram_dmem(FILE* f, const char* base) {
    // Nombre unico por volcado: si dos hilos crashean a la vez, el segundo truncaba a 0 el fichero
    // del primero (fopen "wb") y perdiamos el estado.
    static std::atomic<unsigned long> hh_dump_seq{0};
    char path_rdram[192];
    char path_dmem[192];
    const unsigned long seq = hh_dump_seq.fetch_add(1);
    snprintf(path_rdram, sizeof(path_rdram), "%s_rdram_%lu_%lu.bin", base, hh_process_id(), seq);
    snprintf(path_dmem, sizeof(path_dmem), "%s_dmem_%lu_%lu.bin", base, hh_process_id(), seq);
    uint8_t* rdram = hh::get_game_rdram();
    if (rdram != nullptr) {
#ifdef _WIN32
        FILE* d = fopen(path_rdram, "wb");
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
            fprintf(f, "[HH] %s escrito: %zu bytes\n", path_rdram, total);
        }
#else
        FILE* d = fopen(path_rdram, "wb");
        if (d != nullptr) {
            fwrite(rdram, 1, 8u * 1024u * 1024u, d);
            fclose(d);
            fprintf(f, "[HH] %s escrito\n", path_rdram);
        }
#endif
    } else {
        fprintf(f, "[CRASH] rdram no disponible (crash durante el arranque?)\n");
    }
    FILE* d2 = fopen(path_dmem, "wb");
    if (d2 != nullptr) { fwrite(dmem, 1, 0x1000, d2); fclose(d2); }
}

// Hook que llama el runtime cuando su SEH captura un crash del hilo principal (entrypoint):
// deja el mismo volcado que los crashes de otros hilos. n64_addr = direccion guest del acceso.
extern "C" int hh_get_thread_ctxs_tids(recomp_context** out, int* tids, int max);
extern "C" int hh_get_thread_ctxs_full(recomp_context** out, int* tids, uintptr_t* thrs, int max);
extern "C" int hh_thread_info(uintptr_t t, uint32_t* out);
extern "C" int hh_get_callring(recomp_context* c, uint32_t* out, int max);

// HH: pila de un hilo que esta CORRIENDO (busy-loop de codigo guest): palabras que parecen
// direcciones de codigo (RA guardadas) en [sp, sp+0x400). Ayuda a identificar el bucle culpable.
static void hh_dump_stack_scan(FILE* f, uint32_t sp) {
    uint8_t* rdram = hh::get_game_rdram();
    if (rdram == nullptr) return;
    fprintf(f, "[HANG]   stack-scan sp=%08X:", sp);
    int n = 0;
    for (uint32_t a = sp; a < sp + 0x400 && a + 4 <= 0x80800000u; a += 4) {
        uint32_t v = *(uint32_t*)(rdram + (a - 0x80000000u));
        if ((v >= 0x80000400u && v < 0x804E5F40u) || (v >= 0x80100000u && v < 0x80400000u)) {
            if ((n % 6) == 0) fprintf(f, "\n[HANG]    ");
            fprintf(f, " +%03X=%08X", a - sp, v);
            n++;
            if (n >= 24) break;
        }
    }
    fprintf(f, "\n");
}

extern "C" void hh_port_crash_dump(uint32_t n64_addr) {
    static volatile int busy = 0;
    if (busy != 0) return;
    busy = 1;
    FILE* f = fopen("hh_crash.log", "a");
    if (f == nullptr) return;
    fprintf(f, "=== HH crash (entrypoint SEH) n64_addr=0x%08X VI=%llu ===\n",
            n64_addr, (unsigned long long)hh_get_vi_count());
    hh_dump_guest_regs(f);
    fflush(f);
    hh_dump_rdram_dmem(f, "hh_crash");
    fflush(f);
    fclose(f);
}

// Volcado de los registros de un contexto de hilo de juego (una linea compacta).
static void hh_dump_ctx_regs(FILE* f, int idx, int tid, recomp_context* c) {
    fprintf(f, "[HANG] ctx%d tid=%d ra=%08X sp=%08X fp=%08X gp=%08X r2=%08X r3=%08X r4=%08X r5=%08X\n",
            idx, tid, (uint32_t)c->r31, (uint32_t)c->r29, (uint32_t)c->r30, (uint32_t)c->r28,
            (uint32_t)c->r2, (uint32_t)c->r3, (uint32_t)c->r4, (uint32_t)c->r5);
    fprintf(f, "[HANG]   r6=%08X r7=%08X r8=%08X r9=%08X r10=%08X r11=%08X r12=%08X r13=%08X\n",
            (uint32_t)c->r6, (uint32_t)c->r7, (uint32_t)c->r8, (uint32_t)c->r9,
            (uint32_t)c->r10, (uint32_t)c->r11, (uint32_t)c->r12, (uint32_t)c->r13);
    fprintf(f, "[HANG]   r14=%08X r15=%08X r16=%08X r17=%08X r18=%08X r19=%08X r20=%08X r21=%08X\n",
            (uint32_t)c->r14, (uint32_t)c->r15, (uint32_t)c->r16, (uint32_t)c->r17,
            (uint32_t)c->r18, (uint32_t)c->r19, (uint32_t)c->r20, (uint32_t)c->r21);
    fprintf(f, "[HANG]   r22=%08X r23=%08X r24=%08X r25=%08X r26=%08X r27=%08X hi=%08X lo=%08X\n",
            (uint32_t)c->r22, (uint32_t)c->r23, (uint32_t)c->r24, (uint32_t)c->r25,
            (uint32_t)c->r26, (uint32_t)c->r27, (uint32_t)c->hi, (uint32_t)c->lo);
}

// ===== Watchdog de cuelgue =====
// Si el juego deja de pedir input (latido real del hilo de juego; el VI es de reloj y avanza
// aunque el juego este colgado) durante N segundos (HH_HANG_SECS, por defecto 15), vuelca
// hh_hang.log (contexto MIPS de cada hilo: RA/SP = donde esta bloqueado) y hh_hang_rdram.bin.
// HH: diagnostico del livelock del dano: vigila el flag 0x80037748/0x8003774C y permite
// forzarlo (HH_TEST_FLAG=<segundos>) para reproducir el estado localmente.
static void hh_flag_watch() {
    static uint16_t prev48 = 0xFFFF, prev4c = 0xFFFF;
    static bool init = false;
    uint8_t* rdram = hh::get_game_rdram();
    if (rdram == nullptr) return;
    uint16_t f48 = *(uint16_t*)(rdram + 0x37748);
    uint16_t f4c = *(uint16_t*)(rdram + 0x3774c);
    if (!init) { prev48 = f48; prev4c = f4c; init = true; }
    const char* env = getenv("HH_TEST_FLAG");
    if (env != nullptr && *env != '\0') {
        static bool done = false;
        if (!done && std::chrono::duration<double>(std::chrono::steady_clock::now() - std::chrono::steady_clock::time_point{}).count() > 0) {
            static auto t0 = std::chrono::steady_clock::now();
            if (std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count() >= strtod(env, nullptr)) {
                done = true;
                *(uint16_t*)(rdram + 0x37748) = 1;
                *(uint16_t*)(rdram + 0x3774c) = 0;
                fprintf(stderr, "[FLAG] forzado flag 0x80037748=1\n");
                f48 = 1;
            }
        }
    }
    if (f48 != prev48 || f4c != prev4c) {
        FILE* f = fopen("hh_flag.log", "a");
        if (f != nullptr) {
            fprintf(f, "[FLAG] 0x80037748: %04X -> %04X   0x8003774C: %04X -> %04X (VI=%llu)\n",
                    prev48, f48, prev4c, f4c, (unsigned long long)hh_get_vi_count());
            fclose(f);
        }
        prev48 = f48; prev4c = f4c;
    }
}

static void hh_hang_watchdog() {
    const char* env = getenv("HH_HANG_SECS");
    const double limit = (env != nullptr && *env != '\0') ? strtod(env, nullptr) : 15.0;
    // HH_HANG_FORCE=<s>: vuelca una vez pasados s segundos aunque no haya cuelgue (prueba del watchdog).
    const char* fenv = getenv("HH_HANG_FORCE");
    const double force = (fenv != nullptr && *fenv != '\0') ? strtod(fenv, nullptr) : 0.0;
    // HH_STATE_SECS=<s>: snapshot periodico del estado de todos los hilos a hh_state.log (0 = off).
    // Sirve para cuelgues en los que el juego sigue pidiendo input/produciendo audio y el watchdog
    // clasico no dispara: el snapshot muestra donde esta cada hilo en el momento del atasco.
    const char* senv = getenv("HH_STATE_SECS");
    const double state_secs = (senv != nullptr && *senv != '\0') ? strtod(senv, nullptr) : 5.0;
    fprintf(stderr, "[HANG] watchdog activo (limite %.0fs%s); snapshots cada %.0fs\n", limit,
            force > 0.0 ? ", force-test" : "", state_secs);
    std::thread([limit, force, state_secs] {
        using namespace std::chrono_literals;
        const auto start = std::chrono::steady_clock::now();
        unsigned long long last_polls = hh_get_input_polls();
        unsigned long long last_audio = hh_get_audio_calls();
        auto last_change = start;
        auto last_audio_change = start;
        auto last_state = start;
        FILE* state_file = nullptr;
        long state_bytes = 0;
        bool dumped = false;
        bool forced_done = false;
        while (true) {
            std::this_thread::sleep_for(1s);
            hh_flag_watch();
            unsigned long long polls = hh_get_input_polls();
            unsigned long long audio = hh_get_audio_calls();
            unsigned long long vi = hh_get_vi_count();
            auto now = std::chrono::steady_clock::now();
            if (state_secs > 0.0 &&
                std::chrono::duration<double>(now - last_state).count() >= state_secs) {
                last_state = now;
                if (state_file == nullptr) {
                    state_file = fopen("hh_state.log", "w");
                    if (state_file != nullptr) fprintf(stderr, "[HANG] hh_state.log abierto\n");
                }
                if (state_file != nullptr && state_bytes < (8L * 1024 * 1024)) {
                    const double t = std::chrono::duration<double>(now - start).count();
                    fprintf(state_file,
                            "=== HH estado t=%.1f VI=%llu vi_ticks=%llu polls=%llu audio=%llu pending_ext=%llu ===\n",
                            t, (unsigned long long)vi, (unsigned long long)hh_get_vi_ticks(),
                            (unsigned long long)polls, (unsigned long long)audio,
                            (unsigned long long)hh_get_pending_ext_msgs());
                    recomp_context* ctxs[32];
                    int tids[32];
                    int n = hh_get_thread_ctxs_tids(ctxs, tids, 32);
                    fprintf(state_file, "[STATE] hilos de juego con contexto: %d\n", n);
                    for (int i = 0; i < n; i++) {
                        hh_dump_ctx_regs(state_file, i, tids[i], ctxs[i]);
                    }
                    fflush(state_file);
                    state_bytes += 320 + (long)n * 330;
                }
            }
            if (audio != last_audio) {
                last_audio = audio;
                last_audio_change = now;
            }
            if (force > 0.0 && !forced_done &&
                std::chrono::duration<double>(now - start).count() >= force) {
                forced_done = true;
                dumped = true;
                FILE* f = fopen("hh_hang.log", "a");
                if (f == nullptr) continue;
                fprintf(f, "=== HH cuelgue (forzado por HH_HANG_FORCE=%.0f) VI=%llu ===\n", force, vi);
                recomp_context* ctxs[32];
                int tids[32];
                uintptr_t thrs[32];
                int n = hh_get_thread_ctxs_full(ctxs, tids, thrs, 32);
                fprintf(f, "[HANG] hilos de juego con contexto: %d\n", n);
                for (int i = 0; i < n; i++) {
                    uint32_t info[4] = {0,0,0,0};
                    int ok = hh_thread_info(thrs[i], info);
                    fprintf(f, "[HANG] ctx%d tid=%d (sombra: id=%u state=%u queue=%08X sp=%08X) ctx_sp=%08X\n",
                            i, tids[i], ok ? info[0] : 0xFFFFFFFFu, ok ? info[1] : 0xFFFFFFFFu,
                            ok ? info[2] : 0, ok ? info[3] : 0, (uint32_t)ctxs[i]->r29);
                    hh_dump_ctx_regs(f, i, tids[i], ctxs[i]);
                    if (ok && info[1] == 2) {
                        hh_dump_stack_scan(f, (uint32_t)ctxs[i]->r29);
                    }
                    uint32_t ring[16];
                    int rn = hh_get_callring(ctxs[i], ring, 16);
                    if (rn > 0) {
                        fprintf(f, "[HANG]   ultimas llamadas:");
                        for (int k = 0; k < rn; k++) fprintf(f, " %08X", ring[k]);
                        fprintf(f, "\n");
                    }
                }
                fflush(f);
                hh_dump_rdram_dmem(f, "hh_hang");
                fflush(f);
                fclose(f);
                fprintf(stderr, "[HANG] volcado forzado escrito (VI=%llu)\n", vi);
                continue;
            }
            if (polls != last_polls) {
                last_polls = polls;
                last_change = now;
                dumped = false;
                continue;
            }
            // Dos senales de vida: polls de input y produccion de audio. Si el audio se para
            // (aunque el bucle siga pidiendo input) tambien volcamos.
            const double stuck = std::chrono::duration<double>(now - last_change).count();
            const double audio_stuck = std::chrono::duration<double>(now - last_audio_change).count();
            const bool audio_dead = (last_audio > 0) && (audio_stuck >= limit);
            if (!dumped && last_polls > 0 && (stuck >= limit || audio_dead)) {
                dumped = true;
                FILE* f = fopen("hh_hang.log", "a");
                if (f == nullptr) continue;
                fprintf(f, "=== HH cuelgue: polls parados %.1fs / audio parado %.1fs (VI=%llu) ===\n",
                        stuck, audio_stuck, vi);
                fprintf(f, "[HANG] vi_ticks=%llu pending_ext_msgs=%llu (si vi_ticks no sube: hilo VI del runtime parado)\n",
                        (unsigned long long)hh_get_vi_ticks(),
                        (unsigned long long)hh_get_pending_ext_msgs());
                recomp_context* ctxs[32];
                int tids[32];
                uintptr_t thrs[32];
                int n = hh_get_thread_ctxs_full(ctxs, tids, thrs, 32);
                fprintf(f, "[HANG] hilos de juego con contexto: %d\n", n);
                for (int i = 0; i < n; i++) {
                    uint32_t info[4] = {0,0,0,0};
                    int ok = hh_thread_info(thrs[i], info);
                    fprintf(f, "[HANG] ctx%d tid=%d (sombra: id=%u state=%u queue=%08X sp=%08X) ctx_sp=%08X\n",
                            i, tids[i], ok ? info[0] : 0xFFFFFFFFu, ok ? info[1] : 0xFFFFFFFFu,
                            ok ? info[2] : 0, ok ? info[3] : 0, (uint32_t)ctxs[i]->r29);
                    hh_dump_ctx_regs(f, i, tids[i], ctxs[i]);
                    if (ok && info[1] == 2 /*RUNNING*/) {
                        hh_dump_stack_scan(f, (uint32_t)ctxs[i]->r29);
                    }
                    uint32_t ring[16];
                    int rn = hh_get_callring(ctxs[i], ring, 16);
                    if (rn > 0) {
                        fprintf(f, "[HANG]   ultimas llamadas:");
                        for (int k = 0; k < rn; k++) fprintf(f, " %08X", ring[k]);
                        fprintf(f, "\n");
                    }
                }
                fflush(f);
                hh_dump_rdram_dmem(f, "hh_hang");
                fflush(f);
                fclose(f);
                fprintf(stderr, "[HANG] volcado escrito (polls %.1fs, audio %.1fs, VI=%llu)\n",
                        stuck, audio_stuck, vi);
            }
        }
    }).detach();
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
            fflush(f);
            hh_dump_rdram_dmem(f, "hh_crash");
            fclose(f);
        }
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
    // HH: pila host del hilo que crashea (traducir con el .map: exe+0x...). Ayuda cuando el
    // fallo esta en codigo del runtime/RT64 y no hay contexto guest.
    void* hh_bt[48];
    USHORT hh_nbt = CaptureStackBackTrace(0, 48, hh_bt, nullptr);
    for (USHORT i = 0; i < hh_nbt; i++) {
        unsigned long long off = (hm != nullptr) ? (unsigned long long)((uintptr_t)hh_bt[i] - (uintptr_t)hm) : 0;
        fprintf(stderr, "[SEGV] bt[%02u] %p%s+0x%llX\n", (unsigned)i, hh_bt[i],
                (hm != nullptr) ? " (exe)" : "", off);
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
            // HH: pila host (traducir con el .map: exe+0x...).
            fprintf(f, "[CRASH] host backtrace (%u frames):\n", (unsigned)hh_nbt);
            for (USHORT i = 0; i < hh_nbt; i++) {
                unsigned long long off = (hm != nullptr) ? (unsigned long long)((uintptr_t)hh_bt[i] - (uintptr_t)hm) : 0;
                fprintf(f, "  bt[%02u] %p (exe+0x%llX)\n", (unsigned)i, hh_bt[i], off);
            }
            hh_dump_rdram_dmem(f, "hh_crash");
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
    // HH: las lecturas PI del loader son sincronas (osEPiStartDma + osRecvMesg sobre una cola de
    // msgCount=1). Con requeue_pi=false, una completacion que llegue con la cola llena se DESCARTA
    // y el hilo que la espera queda colgado (hh_hang.log: ctx2 en osRecvMesg de 0x8005C268, cola
    // vacia). Reencolar garantiza la entrega: la drena el propio hilo bloqueado en osRecvMesg.
    configuration.message_queue_control.requeue_pi = true;

    hh::init_audio();
    hh::reset_audio(48000);
    hh::log("audio reset done\n");

    // Set the game status to Running BEFORE recomp::start. The game thread created inside
    // recomp::start blocks until game_status != None, and recomp::start never returns (it sits
    // in a `while (!exited)` loop), so start_game must be issued beforehand for the boot to run.
    hh::log("calling recomp::start_game (before start)\n");
    recomp::start_game(game_id, "");
    hh::log("start_game issued\n");

    hh_hang_watchdog();
    hh::log("calling recomp::start\n");
    recomp::start(configuration);
    hh::log("recomp::start returned\n");

    return 0;
}