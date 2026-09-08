// r64dump: runs a N64 ROM (user-provided) under libmupen64plus headless (no gfx/audio
// plugins) and dumps the emulated RDRAM via the core debugger API.
//
// Optional real window: if VIDEO_PLUGIN is set, a X11+GLX window is created with an
// unbuffered real vidext and the GL video plugin renders into it; frames are also
// captured (glReadPixels -> PPM) so the game is observable headless under Xvfb.
//
// Build:
//   g++ -O2 tools/analysis/r64dump.cpp -o work/r64dump -ldl -lpthread -lX11 -lGL
#include <dlfcn.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <mupen64plus/m64p_frontend.h>
#include <mupen64plus/m64p_common.h>
#include <mupen64plus/m64p_debugger.h>
#include <mupen64plus/m64p_types.h>

static int g_win_w = 640, g_win_h = 480;
static const char *g_cap_dir = "/app/work/scratch/frames";

static const char *g_cfgdir = "/root/.config/mupen64plus";
static const char *g_datadir = "/usr/share/mupen64plus";

static void dbg_cb(void *context, int level, const char *msg) {
    if (level <= M64MSG_VERBOSE) fprintf(stderr, "[core] %s\n", msg ? msg : "");
}
static void state_cb(void *context, m64p_core_param p, int v) {}

/* debugger UI callbacks: ui_update reports the R4300 PC whenever the machine
 * pauses/halts (e.g. after a breakpoint). We record it for watchdog analysis. */
static volatile unsigned g_halt_pc = 0;
static volatile int g_halt_seen = 0;
static uint32_t g_bp_paddr = 0;
static int g_bp_idx = -1;
static int g_bp_suspended = 0;      /* wp disabled to skip the boot dir-clear loop */
static double g_bp_reenable_at = 0;
static void ui_init_cb(void) {}
static void ui_update_cb(unsigned int pc) {
    g_halt_pc = pc;
    g_halt_seen = 1;
}
static void ui_vi_cb(void) {}

// --- video extension stubs (headless: no SDL/GL window) ---
static m64p_error vx_init(void) { return M64ERR_SUCCESS; }
static m64p_error vx_quit(void) { return M64ERR_SUCCESS; }
static m64p_error vx_listmodes(m64p_2d_size *s, int *n) { if (n) *n = 0; return M64ERR_SUCCESS; }
static m64p_error vx_listrates(m64p_2d_size s, int *n, int *a) { if (n) *n = 0; return M64ERR_SUCCESS; }
static m64p_error vx_setmode(int w, int h, int b, int m, int f) { return M64ERR_SUCCESS; }
static m64p_error vx_setmode2(int w, int h, int r, int b, int m, int f) { return M64ERR_SUCCESS; }
static void *vx_glproc(const char *s) { return NULL; }
static m64p_error vx_glsetattr(m64p_GLattr a, int v) { return M64ERR_SUCCESS; }
static m64p_error vx_glgetattr(m64p_GLattr a, int *v) { if (v) *v = 1; return M64ERR_SUCCESS; }
static m64p_error vx_glswap(void) { return M64ERR_SUCCESS; }
static m64p_error vx_caption(const char *s) { return M64ERR_SUCCESS; }
static m64p_error vx_togglefs(void) { return M64ERR_SUCCESS; }
static m64p_error vx_resize(int w, int h) { return M64ERR_SUCCESS; }
static uint32_t vx_fbo(void) { return 0; }

/* real vidext: forward decls */
static m64p_error vxg_init(void);
static m64p_error vxg_quit(void);
static m64p_error vxg_listmodes(m64p_2d_size *s, int *n);
static m64p_error vxg_listrates(m64p_2d_size s, int *n, int *a);
static m64p_error vxg_setmode(int w, int h, int b, int m, int f);
static m64p_error vxg_setmode2(int w, int h, int r, int b, int m, int f);
static void *vxg_glproc(const char *s);
static m64p_error vxg_glsetattr(m64p_GLattr a, int v);
static m64p_error vxg_glgetattr(m64p_GLattr a, int *v);
static m64p_error vxg_glswap(void);
static m64p_error vxg_caption(const char *s);
static m64p_error vxg_togglefs(void);
static m64p_error vxg_resize(int w, int h);
static uint32_t vxg_fbo(void);

static void override_vidext(ptr_CoreOverrideVidExt ov, int use_real) {
    m64p_video_extension_functions vx;
    memset(&vx, 0, sizeof(vx));
    vx.Functions = 14;
    vx.VidExtFuncInit = use_real ? vxg_init : vx_init;
    vx.VidExtFuncQuit = use_real ? vxg_quit : vx_quit;
    vx.VidExtFuncListModes = use_real ? vxg_listmodes : vx_listmodes;
    vx.VidExtFuncListRates = use_real ? vxg_listrates : vx_listrates;
    vx.VidExtFuncSetMode = use_real ? vxg_setmode : vx_setmode;
    vx.VidExtFuncSetModeWithRate = use_real ? vxg_setmode2 : vx_setmode2;
    vx.VidExtFuncGLGetProc = (m64p_function (*)(const char *))(use_real ? (void *)vxg_glproc : (void *)vx_glproc);
    vx.VidExtFuncGLSetAttr = use_real ? vxg_glsetattr : vx_glsetattr;
    vx.VidExtFuncGLGetAttr = use_real ? vxg_glgetattr : vx_glgetattr;
    vx.VidExtFuncGLSwapBuf = use_real ? vxg_glswap : vx_glswap;
    vx.VidExtFuncSetCaption = use_real ? vxg_caption : vx_caption;
    vx.VidExtFuncToggleFS = use_real ? vxg_togglefs : vx_togglefs;
    vx.VidExtFuncResizeWindow = use_real ? vxg_resize : vx_resize;
    vx.VidExtFuncGLGetDefaultFramebuffer = use_real ? vxg_fbo : vx_fbo;
    ov(&vx);
}

static void *exec_thread(void *arg) {
    ptr_CoreDoCommand CoreDoCommand = (ptr_CoreDoCommand)arg;
    CoreDoCommand(M64CMD_EXECUTE, 0, NULL);
    return NULL;
}

/* ------------------------------------------------------------------ */
/* real vidext: X11 + GLX window so GL video plugins can run under Xvfb */
static Display *g_dpy = NULL;
static Window g_win = 0;
static GLXContext g_ctx = NULL;
static XVisualInfo *g_vis = NULL;
static unsigned long g_frame = 0;
static unsigned long g_swapcnt = 0;
static int g_gl_ready = 0;

static m64p_error vxg_init(void) {
    g_dpy = XOpenDisplay(NULL);
    if (!g_dpy) { fprintf(stderr, "[vid] XOpenDisplay failed\n"); return M64ERR_SYSTEM_FAIL; }
    int screen = DefaultScreen(g_dpy);
    Window root = RootWindow(g_dpy, screen);
    XSetWindowAttributes wa;
    memset(&wa, 0, sizeof(wa));
    wa.background_pixel = 0;
    wa.border_pixel = 0;
    wa.event_mask = ExposureMask | StructureNotifyMask;

    /* try modern core-profile GL context via GLX_ARB_create_context */
    static int fbattrs[] = { GLX_DOUBLEBUFFER, True, GLX_DEPTH_SIZE, 16,
                             GLX_RED_SIZE, 8, GLX_GREEN_SIZE, 8, GLX_BLUE_SIZE, 8, None };
    int nfb = 0;
    GLXFBConfig *cfg = glXChooseFBConfig(g_dpy, screen, fbattrs, &nfb);
    typedef GLXContext (*create_ctx_attribs)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
    create_ctx_attribs glXCreateContextAttribsARB = NULL;
    if (cfg && nfb > 0) {
        glXCreateContextAttribsARB =
            (create_ctx_attribs)glXGetProcAddressARB((const GLubyte *)"glXCreateContextAttribsARB");
    }
    if (glXCreateContextAttribsARB) {
        int ctxattrs[] = {
            GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
            GLX_CONTEXT_MAJOR_VERSION_ARB, 4,
            GLX_CONTEXT_MINOR_VERSION_ARB, 5,
            None };
        g_ctx = glXCreateContextAttribsARB(g_dpy, cfg[0], NULL, True, ctxattrs);
        if (g_ctx) {
            XVisualInfo *vis = glXGetVisualFromFBConfig(g_dpy, cfg[0]);
            g_vis = vis;
            wa.colormap = XCreateColormap(g_dpy, root, vis->visual, AllocNone);
            g_win = XCreateWindow(g_dpy, root, 0, 0, (unsigned)g_win_w, (unsigned)g_win_h, 0,
                                  vis->depth, InputOutput, vis->visual,
                                  CWBackPixel | CWColormap | CWBorderPixel, &wa);
            fprintf(stderr, "[vid] core profile GL context created\n");
        } else {
            fprintf(stderr, "[vid] glXCreateContextAttribs (core 4.5) failed -- falling back\n");
        }
    } else {
        fprintf(stderr, "[vid] no glXCreateContextAttribsARB -- falling back\n");
    }

    if (!g_win) {
        int att[] = { GLX_RGBA, GLX_DOUBLEBUFFER, GLX_DEPTH_SIZE, 16, None };
        g_vis = glXChooseVisual(g_dpy, screen, att);
        if (!g_vis) { fprintf(stderr, "[vid] no GLX visual\n"); return M64ERR_SYSTEM_FAIL; }
        wa.colormap = XCreateColormap(g_dpy, root, g_vis->visual, AllocNone);
        g_win = XCreateWindow(g_dpy, root, 0, 0, (unsigned)g_win_w, (unsigned)g_win_h, 0,
                              g_vis->depth, InputOutput, g_vis->visual,
                              CWBackPixel | CWColormap | CWBorderPixel, &wa);
        g_ctx = glXCreateContext(g_dpy, g_vis, NULL, True);
        if (!g_ctx) { fprintf(stderr, "[vid] glXCreateContext failed\n"); return M64ERR_SYSTEM_FAIL; }
    }
    XStoreName(g_dpy, g_win, "r64dump");
    XMapWindow(g_dpy, g_win);
    glXMakeCurrent(g_dpy, g_win, g_ctx);
    const char *gv = (const char *)glGetString(GL_VERSION);
    fprintf(stderr, "[vid] GL version: %s\n", gv ? gv : "?");
    g_gl_ready = 1;
    return M64ERR_SUCCESS;
}

static m64p_error vxg_quit(void) {
    if (g_ctx) { glXMakeCurrent(g_dpy, None, NULL); glXDestroyContext(g_dpy, g_ctx); g_ctx = NULL; }
    if (g_win) { XDestroyWindow(g_dpy, g_win); g_win = 0; }
    if (g_dpy) { XCloseDisplay(g_dpy); g_dpy = NULL; }
    g_gl_ready = 0;
    return M64ERR_SUCCESS;
}

static m64p_error vxg_listmodes(m64p_2d_size *s, int *n) { if (n) *n = 1; if (s) { s[0].uiWidth=640; s[0].uiHeight=480; } return M64ERR_SUCCESS; }
static m64p_error vxg_listrates(m64p_2d_size s, int *n, int *a) { if (n) *n = 1; if (a) a[0] = 60; return M64ERR_SUCCESS; }
static m64p_error vxg_setmode(int w, int h, int b, int m, int f) { g_win_w = w; g_win_h = h; if (g_win) XResizeWindow(g_dpy, g_win, (unsigned)w, (unsigned)h); return M64ERR_SUCCESS; }
static m64p_error vxg_setmode2(int w, int h, int r, int b, int m, int f) { return vxg_setmode(w, h, b, m, f); }
static void *vxg_glproc(const char *s) { return (void *)glXGetProcAddressARB((const GLubyte *)s); }
static m64p_error vxg_glsetattr(m64p_GLattr a, int v) { (void)a; (void)v; return M64ERR_SUCCESS; }
static m64p_error vxg_glgetattr(m64p_GLattr a, int *v) {
    if (!v) return M64ERR_INVALID_STATE;
    switch (a) {
        case M64P_GL_DOUBLEBUFFER: *v = 1; break;
        case M64P_GL_BUFFER_SIZE: *v = 24; break;
        case M64P_GL_DEPTH_SIZE: *v = 16; break;
        case M64P_GL_RED_SIZE: *v = 8; break;
        case M64P_GL_GREEN_SIZE: *v = 8; break;
        case M64P_GL_BLUE_SIZE: *v = 8; break;
        case M64P_GL_ALPHA_SIZE: *v = 8; break;
        case M64P_GL_SWAP_CONTROL: *v = 0; break;
        default: *v = 1; break;
    }
    return M64ERR_SUCCESS;
}

static void vxg_capture(void) {
    if (!g_gl_ready || g_frame % 6 != 0) return;
    static int warned = 0;
    if (g_frame % 6 == 0) {
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
        glReadBuffer(GL_FRONT);
        int w = g_win_w, h = g_win_h;
        unsigned char *px = (unsigned char *)malloc((size_t)w * h * 3);
        if (px) {
            glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, px);
            char path[1024];
            static unsigned long snap = 0;
            snprintf(path, sizeof(path), "%s/s%08lu.ppm", g_cap_dir, snap++);
            FILE *f = fopen(path, "wb");
            if (f) {
                fprintf(f, "P6\n%d %d\n255\n", w, h);
                /* flip vertically (GL origin bottom-left) */
                for (int y = 0; y < h; y++)
                    fwrite(px + (size_t)(h - 1 - y) * w * 3, 1, (size_t)w * 3, f);
                fclose(f);
            }
            free(px);
            (void)warned;
        }
    }
}

static m64p_error vxg_glswap(void) {
    if (g_ctx && g_gl_ready) {
        glXSwapBuffers(g_dpy, g_win);
        g_frame++;
        vxg_capture();
    }
    return M64ERR_SUCCESS;
}
static m64p_error vxg_caption(const char *s) { (void)s; return M64ERR_SUCCESS; }
static m64p_error vxg_togglefs(void) { return M64ERR_SUCCESS; }
static m64p_error vxg_resize(int w, int h) { return vxg_setmode(w, h, 24, 0, 0); }
static uint32_t vxg_fbo(void) { return 0; }

// --- scripted keys: HH_SCHED="t:mask;t:mask;..."  (mask = N64 button bits, A=0x8000 hi byte first) ---
static uint16_t sched_mask_at(double t) {
    const char *s = getenv("HH_SCHED");
    uint16_t mask = 0;
    if (!s) return 0;
    char buf[512]; strncpy(buf, s, sizeof(buf)-1); buf[sizeof(buf)-1] = 0;
    char *tok = strtok(buf, ";");
    while (tok) {
        double t0; unsigned m;
        if (sscanf(tok, "%lf:%x", &t0, &m) == 2 && t0 <= t) mask = (uint16_t)m;
        tok = strtok(NULL, ";");
    }
    return mask;
}

static void write_keys(double t) {
    uint16_t m = sched_mask_at(t);
    unsigned char b[4] = { (unsigned char)(m >> 8), (unsigned char)(m & 0xFF), 0, 0 };
    FILE *f = fopen("/tmp/hh_keys.bin", "wb");
    if (f) { fwrite(b, 1, 4, f); fclose(f); }
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc < 3) { fprintf(stderr, "usage: %s <rom> <out.rdram> [seconds]\n", argv[0]); return 1; }
    const char *rompath = argv[1];
    const char *out = argv[2];
    double secs = (argc > 3) ? atof(argv[3]) : 30.0;

    FILE *fr = fopen(rompath, "rb");
    if (!fr) { perror("open rom"); return 1; }
    fseek(fr, 0, SEEK_END); long n = ftell(fr); fseek(fr, 0, SEEK_SET);
    unsigned char *rom = (unsigned char *)malloc((size_t)n);
    if (fread(rom, 1, (size_t)n, fr) != (size_t)n) { perror("read rom"); return 1; }
    fclose(fr);

    const char *somap = getenv("CORE_SO");
    void *core = dlopen(somap ? somap : "/usr/lib/libmupen64plus.so.2", RTLD_NOW);
    if (!core) { fprintf(stderr, "core dlopen failed: %s\n", dlerror()); return 1; }

    ptr_CoreGetAPIVersions CoreGetAPIVersions = (ptr_CoreGetAPIVersions)dlsym(core, "CoreGetAPIVersions");
    ptr_CoreStartup CoreStartup = (ptr_CoreStartup)dlsym(core, "CoreStartup");
    ptr_CoreShutdown CoreShutdown = (ptr_CoreShutdown)dlsym(core, "CoreShutdown");
    ptr_CoreAttachPlugin CoreAttachPlugin = (ptr_CoreAttachPlugin)dlsym(core, "CoreAttachPlugin");
    ptr_CoreDoCommand CoreDoCommand = (ptr_CoreDoCommand)dlsym(core, "CoreDoCommand");
    ptr_CoreOverrideVidExt CoreOverrideVidExtFn = (ptr_CoreOverrideVidExt)dlsym(core, "CoreOverrideVidExt");
    ptr_DebugGetState DebugGetState = (ptr_DebugGetState)dlsym(core, "DebugGetState");
    ptr_DebugMemGetPointer DebugMemGetPointer = (ptr_DebugMemGetPointer)dlsym(core, "DebugMemGetPointer");
    ptr_DebugSetRunState DebugSetRunState = (ptr_DebugSetRunState)dlsym(core, "DebugSetRunState");
    ptr_DebugMemRead32 DebugMemRead32 = (ptr_DebugMemRead32)dlsym(core, "DebugMemRead32");
    ptr_DebugSetCallbacks DebugSetCallbacks =
        (ptr_DebugSetCallbacks)dlsym(core, "DebugSetCallbacks");
    ptr_DebugBreakpointCommand DebugBreakpointCommand =
        (ptr_DebugBreakpointCommand)dlsym(core, "DebugBreakpointCommand");
    ptr_DebugVirtualToPhysical DebugVirtualToPhysical =
        (ptr_DebugVirtualToPhysical)dlsym(core, "DebugVirtualToPhysical");
    ptr_DebugGetCPUDataPtr DebugGetCPUDataPtr =
        (ptr_DebugGetCPUDataPtr)dlsym(core, "DebugGetCPUDataPtr");
    ptr_DebugBreakpointTriggeredBy DebugBreakpointTriggeredBy =
        (ptr_DebugBreakpointTriggeredBy)dlsym(core, "DebugBreakpointTriggeredBy");
    ptr_DebugStep DebugStep = (ptr_DebugStep)dlsym(core, "DebugStep");

    int a0 = 0, a1 = 0, a2 = 0;
    CoreGetAPIVersions(&a0, &a1, &a2, NULL);
    int api =
        ((a0 >> 16) & 0xFF) << 16 | ((a0 >> 8) & 0xFF) << 8 | (a0 & 0xFF);
    printf("core API encoded: 0x%06X\n", api);

    fprintf(stderr, "[step] calling CoreStartup\n");
    m64p_error r = CoreStartup(api, g_cfgdir, g_datadir, NULL, dbg_cb, NULL, state_cb);
    if (r != M64ERR_SUCCESS) { fprintf(stderr, "CoreStartup -> %d\n", r); return 1; }
    fprintf(stderr, "[step] CoreStartup OK\n");
    int use_real_vid = (getenv("VIDEO_PLUGIN") && *getenv("VIDEO_PLUGIN")) ? 1 : 0;
    if (use_real_vid) mkdir(g_cap_dir, 0755);
    if (CoreOverrideVidExtFn) override_vidext(CoreOverrideVidExtFn, use_real_vid);
    fprintf(stderr, "[step] vidext overridden (%s)\n", use_real_vid ? "real GLX" : "stubs");
    // force pure interpreter (0) to avoid the dynarec issue we hit (r4300=0xffffffff)
    // and enable the core debugger (requires DebugSetCallbacks before main_run).
    {
        void *core_so = core;
        m64p_error (*pOpenSec)(const char *, m64p_handle *) =
            (m64p_error (*)(const char *, m64p_handle *))dlsym(core_so, "ConfigOpenSection");
        m64p_error (*pSetP)(m64p_handle, const char *, m64p_type, const void *) =
            (m64p_error (*)(m64p_handle, const char *, m64p_type, const void *))dlsym(core_so, "ConfigSetParameter");
        if (pOpenSec && pSetP) {
            int emumode = 0, dbgon = 1;
            m64p_handle sec = NULL;
            if (pOpenSec("Core", &sec) == M64ERR_SUCCESS) {
                m64p_error sr = pSetP(sec, "R4300Emulator", M64TYPE_INT, &emumode);
                m64p_error dr = pSetP(sec, "EnableDebugger", M64TYPE_BOOL, &dbgon);
                fprintf(stderr, "[config] R4300Emulator=pure-interpreter -> %d, EnableDebugger=1 -> %d\n", (int)sr, (int)dr);
            } else fprintf(stderr, "[config] ConfigOpenSection(Core) failed\n");
        } else fprintf(stderr, "[config] config API missing in core\n");
    }
    printf("core started\n");

    fprintf(stderr, "[step] ROM_OPEN\n");
    r = CoreDoCommand(M64CMD_ROM_OPEN, (int)n, (void *)rom);
    if (r != M64ERR_SUCCESS) { fprintf(stderr, "ROM_OPEN -> %d (size %ld)\n", r, n); CoreShutdown(); return 1; }
    printf("rom open OK (%ld bytes)\n", n);

    // attach VIDEO plugin first if requested (real X11+GLX window created by vidext).
    void *gf_handle = NULL;
    const char *gf_plug = getenv("VIDEO_PLUGIN");
    if (gf_plug && *gf_plug) {
        gf_handle = dlopen(gf_plug, RTLD_NOW);
        if (!gf_handle) { fprintf(stderr, "video dlopen %s: %s\n", gf_plug, dlerror()); CoreShutdown(); return 1; }
        typedef m64p_error (*plugin_startup_fn)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *));
        plugin_startup_fn ps = (plugin_startup_fn)dlsym(gf_handle, "PluginStartup");
        if (ps) {
            m64p_error se = ps(core, NULL, dbg_cb);
            fprintf(stderr, "[step] video PluginStartup -> %d\n", (int)se);
        }
        m64p_error vr = CoreAttachPlugin(M64PLUGIN_GFX, gf_handle);
        fprintf(stderr, "[step] CoreAttachPlugin(GFX) -> %d\n", (int)vr);
        if (vr != M64ERR_SUCCESS) { CoreShutdown(); return 1; }
        usleep(300000);
    }

    // attach RSP / INPUT / AUDIO plugins AFTER ROM_OPEN (the core rejects attach
    // before ROM_OPEN with INVALID_STATE). RSP: real plugin if RSP_PLUGIN set,
    // else NULL -> dummy RSP (cannot run gfx/audio tasks).
    const char *rsp_plug = getenv("RSP_PLUGIN");
    void *rsp_handle = NULL;
    if (rsp_plug && *rsp_plug) {
        rsp_handle = dlopen(rsp_plug, RTLD_NOW);
        if (!rsp_handle) { fprintf(stderr, "rsp dlopen %s: %s\n", rsp_plug, dlerror()); CoreShutdown(); return 1; }
        // the reference frontend calls the plugin's PluginStartup() BEFORE
        // CoreAttachPlugin(); skipping it leaves the plugin's internal callbacks
        // NULL (crashes in InitiateRSP). Pass the CORE handle so the plugin can
        // resolve core funcs + a debug callback.
        typedef m64p_error (*plugin_startup_fn)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *));
        plugin_startup_fn ps = (plugin_startup_fn)dlsym(rsp_handle, "PluginStartup");
        if (ps) {
            m64p_error se = ps(core, NULL, dbg_cb);
            fprintf(stderr, "[step] rsp-hle PluginStartup -> %d\n", (int)se);
        } else {
            fprintf(stderr, "[warn] rsp plugin has no PluginStartup export\n");
        }
    }
    m64p_error pr = CoreAttachPlugin(M64PLUGIN_RSP, rsp_handle);
    fprintf(stderr, "[step] CoreAttachPlugin(RSP) handle=%p -> %d\n", (void *)rsp_handle, (int)pr);
    if (pr != M64ERR_SUCCESS) { CoreShutdown(); return 1; }

    // attach INPUT: real plugin if INPUT_PLUGIN set (dlopen + PluginStartup),
    // else NULL -> core disconnects input (game sees NO controller -> attract).
    // AUDIO: NULL -> core installs the dummy (populates audio func table),
    // needed so the core doesn't spam errors; audio-sdl real optional via AUDIO_PLUGIN.
    const char *in_plug = getenv("INPUT_PLUGIN");
    void *in_handle = NULL;
    if (in_plug && *in_plug) {
        in_handle = dlopen(in_plug, RTLD_NOW);
        if (!in_handle) { fprintf(stderr, "input dlopen %s: %s\n", in_plug, dlerror()); CoreShutdown(); return 1; }
        typedef m64p_error (*plugin_startup_fn)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *));
        plugin_startup_fn ps = (plugin_startup_fn)dlsym(in_handle, "PluginStartup");
        if (ps) {
            m64p_error se = ps(core, NULL, dbg_cb);
            fprintf(stderr, "[step] input PluginStartup -> %d\n", (int)se);
        }
        void (*cl)(int) = (void (*)(int))dlsym(in_handle, "SDL_KeyDown");
        (void)cl;
    }
    pr = CoreAttachPlugin(M64PLUGIN_INPUT, in_handle);
    fprintf(stderr, "[step] CoreAttachPlugin(INPUT %s) -> %d\n", in_handle ? "real" : "dummy->disconnect", (int)pr);
    if (pr != M64ERR_SUCCESS) { CoreShutdown(); return 1; }

    const char *au_plug = getenv("AUDIO_PLUGIN");
    void *au_handle = NULL;
    if (au_plug && *au_plug) {
        au_handle = dlopen(au_plug, RTLD_NOW);
        if (!au_handle) { fprintf(stderr, "audio dlopen %s: %s\n", au_plug, dlerror()); CoreShutdown(); return 1; }
        typedef m64p_error (*plugin_startup_fn)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *));
        plugin_startup_fn ps = (plugin_startup_fn)dlsym(au_handle, "PluginStartup");
        if (ps) {
            m64p_error se = ps(core, NULL, dbg_cb);
            fprintf(stderr, "[step] audio PluginStartup -> %d\n", (int)se);
        }
    }
    pr = CoreAttachPlugin(M64PLUGIN_AUDIO, au_handle);
    fprintf(stderr, "[step] CoreAttachPlugin(AUDIO %s) -> %d\n", au_handle ? "real" : "dummy", (int)pr);
    if (pr != M64ERR_SUCCESS) { CoreShutdown(); return 1; }

    fprintf(stderr, "[step] thread create\n");
    /* debugger setup MUST run before main_run (exec thread) so the debugger activates:
     * callbacks first.  Write breakpoints are added only AFTER the exec thread has
     * started and memory is initialized, because main_run()->init_device() zeroes the
     * bp_checks[] bitmap as part of memory init, silently disabling any pre-existing
     * memory-access breakpoint (the breakpoint list entry stays, but the gate is gone). */
    const char *bpaddr_env = getenv("HB_RES_DIR");
    const char *bpexec_env = getenv("HB_EXEC");
    int have_bp = 0;
    int want_wp = 0;
    uint32_t wp_vaddr = 0;
    if ((bpaddr_env && *bpaddr_env) || (bpexec_env && *bpexec_env)) {
        if (DebugSetCallbacks && DebugBreakpointCommand) {
            DebugSetCallbacks(ui_init_cb, ui_update_cb, ui_vi_cb);
            if (bpexec_env && *bpexec_env && DebugVirtualToPhysical) {
                uint32_t eaddr = (uint32_t)strtoul(bpexec_env, NULL, 0);
                int bc = DebugBreakpointCommand(M64P_BKP_CMD_ADD_ADDR, eaddr, NULL);
                fprintf(stderr, "[dbg] EXEC breakpoint @0x%X -> %d\n", (unsigned)eaddr, bc);
                have_bp = (bc >= 0);
                g_bp_paddr = eaddr;
            }
            if (bpaddr_env && *bpaddr_env) {
                want_wp = 1;
                wp_vaddr = (uint32_t)strtoul(bpaddr_env, NULL, 0);
            }
        } else {
            fprintf(stderr, "[dbg] debug API not found in core\n");
        }
    }
    pthread_t th;
    pthread_create(&th, NULL, exec_thread, (void *)CoreDoCommand);
    usleep(500000);
    fprintf(stderr, "[step] after 0.5s exec\n");
    printf("executing for %.1f s...\n", secs);
    /* the debugger halts the R4300 at the very first instruction (init_debugger
     * leaves runstate PAUSED); resume now that boot is up. */
    if ((have_bp || want_wp) && DebugSetRunState && DebugGetState) {
        if (DebugGetState(M64P_DBG_RUN_STATE) == M64P_DBG_RUNSTATE_PAUSED || g_halt_seen) {
            g_halt_seen = 0;
            DebugSetRunState(M64P_DBG_RUNSTATE_RUNNING);
            if (DebugStep) DebugStep();   /* exit update_debugger's semaphore wait */
            fprintf(stderr, "[dbg] resumed after boot halt\n");
        }
    }
    if (want_wp && DebugVirtualToPhysical && DebugBreakpointCommand) {
        uint32_t paddr = DebugVirtualToPhysical(wp_vaddr);
        fprintf(stderr, "[dbg] virt 0x%X -> phys 0x%X\n", (unsigned)wp_vaddr, (unsigned)paddr);
        m64p_breakpoint bp;
        memset(&bp, 0, sizeof(bp));
        bp.address = paddr;               /* whole 1KB directory: catches id/base writes */
        bp.endaddr = paddr + 0x3FF;
        bp.flags = M64P_BKP_FLAG_ENABLED | M64P_BKP_FLAG_WRITE;
        int bc = DebugBreakpointCommand(M64P_BKP_CMD_ADD_STRUCT, 0, &bp);
        fprintf(stderr, "[dbg] write breakpoint @0x%X..0x%X -> %d\n", (unsigned)paddr, (unsigned)(paddr+0x3FF), bc);
        have_bp = (bc >= 0);
        g_bp_paddr = paddr;
        g_bp_idx = bc;
        if (bc >= 0) {
            /* the dir zero-fill runs ~6-8s realtime (256 word-writes, dense): start
             * DISABLED and arm after it, so the machine free-runs through boot. */
            DebugBreakpointCommand(M64P_BKP_CMD_DISABLE, (unsigned)bc, NULL);
            g_bp_suspended = 1;
            const char *arm_e = getenv("HH_WP_ARM");
            g_bp_reenable_at = arm_e ? atof(arm_e) : 8.0;
            fprintf(stderr, "[dbg] wp added idx=%d DISABLED, arming at t=%.1fs\n", bc, g_bp_reenable_at);
        }
    }

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    double last_dump = -1;
    int dump_idx = 0;
    const char *dt = getenv("HH_DUMP_TIMES");
    double dump_times[64];
    int ndt = 0;
    if (dt) {
        char buf[512]; strncpy(buf, dt, sizeof(buf)-1); buf[sizeof(buf)-1] = 0;
        char *tok = strtok(buf, ",");
        while (tok && ndt < 64) { dump_times[ndt++] = atof(tok); tok = strtok(NULL, ","); }
    }
    while (true) {
        usleep(100000);
        clock_gettime(CLOCK_MONOTONIC, &t1);
        double el = (double)(t1.tv_sec - t0.tv_sec) + (double)(t1.tv_nsec - t0.tv_nsec) / 1e9;
        /* re-arm the watchpoint once we're past boot's dense dir-clear loop */
        if (g_bp_suspended && el >= g_bp_reenable_at) {
            g_bp_suspended = 0;
            int be = DebugBreakpointCommand(M64P_BKP_CMD_ENABLE, (unsigned)g_bp_idx, NULL);
            fprintf(stderr, "[dbg] wp re-armed idx=%d -> %d\n", g_bp_idx, be);
        }
        if (g_halt_seen && have_bp) {
            g_halt_seen = 0;
            /* dump-induced pauses also wake ui_update; only WRITE hits are real
             * memory-breakpoint stops. */
            uint32_t fw = 0, f_accessed = 0;
            if (DebugBreakpointTriggeredBy) DebugBreakpointTriggeredBy(&fw, &f_accessed);
            int is_real = (fw & M64P_BKP_FLAG_WRITE);
            fprintf(stderr, "[dbg] stop pc=0x%08X (t=%.2fs) runstate=%d valid=%s flags=0x%X wrote=0x%08X\n",
                    (unsigned)g_halt_pc, el, (int)DebugGetState(M64P_DBG_RUN_STATE),
                    is_real ? "YES" : "no", (unsigned)fw, (unsigned)f_accessed);
            if (is_real) {
                uint32_t hpc = (unsigned)g_halt_pc;
                /* boot's directory zero-fill loops at 0x80000414/0x80000418 and is
                 * dense; disable the watchpoint, free-run past it, re-arm later. */
                if (hpc == 0x80000414u || hpc == 0x80000418u) {
                    g_bp_suspended = 1;
                    g_bp_reenable_at = el + 2.0;
                    DebugBreakpointCommand(M64P_BKP_CMD_DISABLE, (unsigned)g_bp_idx, NULL);
                    fprintf(stderr, "[dbg] dir-clear loop: wp off until t=%.2fs\n", g_bp_reenable_at);
                } else {
                    if (DebugGetCPUDataPtr) {
                        uint32_t *pc = (uint32_t *)DebugGetCPUDataPtr((m64p_dbg_cpu_data)M64P_CPU_PC);
                        if (pc) fprintf(stderr, "[dbg] loader pc=0x%08X (wrote phys 0x%08X)\n", (unsigned)*pc, (unsigned)f_accessed);
                        uint32_t *gpr = (uint32_t *)DebugGetCPUDataPtr((m64p_dbg_cpu_data)M64P_CPU_REG_REG);
                        if (gpr) fprintf(stderr, "[dbg]   a0=0x%08X a1=0x%08X a2=0x%08X a3=0x%08X\n",
                                (unsigned)gpr[4], (unsigned)gpr[5], (unsigned)gpr[6], (unsigned)gpr[7]);
                    }
                    /* snapshot the resource directory for map derivation */
                    char dout[1024];
                    snprintf(dout, sizeof(dout), "%s.dir.bin", out);
                    void *dptr = DebugMemGetPointer(M64P_DBG_PTR_RDRAM);
                    if (dptr) {
                        FILE *df = fopen(dout, "wb");
                        if (df) { fwrite((char*)dptr + 0x8DFC0, 1, 0x400, df); fclose(df); }
                    }
                    fprintf(stderr, "[dbg] dir snapshot written (entry @ phys 0x%08X)\n", (unsigned)f_accessed);
                    /* leave the wp enabled to catch later registrations */
                }
            }
            DebugSetRunState(M64P_DBG_RUNSTATE_RUNNING);
            if (DebugStep) DebugStep();   /* unblock interpreter from paused sem */
        }
        if (getenv("HH_SCHED")) {
            write_keys(el);
        }
        if (dump_idx < ndt && el >= dump_times[dump_idx]) {
            char dout[1024];
            snprintf(dout, sizeof(dout), "%s.t%d.bin", out, dump_idx);
            DebugSetRunState(M64P_DBG_RUNSTATE_PAUSED);
            usleep(100000);
            void *dptr = DebugMemGetPointer(M64P_DBG_PTR_RDRAM);
            if (dptr) {
                FILE *df = fopen(dout, "wb");
                if (df) { fwrite(dptr, 1, 0x800000, df); fclose(df);
                          printf("intermediate dump @%.1fs -> %s\n", el, dout); }
            }
            DebugSetRunState(M64P_DBG_RUNSTATE_RUNNING);
            dump_idx++;
            last_dump = el;
        }
        if (el >= secs) break;
    }
    (void)last_dump;

    int runstate = DebugGetState(M64P_DBG_RUN_STATE);
    printf("debugger run state: %d (0=paused, 2=running)\n", (int)runstate);

    DebugSetRunState(M64P_DBG_RUNSTATE_PAUSED);
    usleep(300000);

    void *ptr = DebugMemGetPointer(M64P_DBG_PTR_RDRAM);
    if (!ptr) {
        fprintf(stderr, "DebugMemGetPointer(RDRAM) returned NULL -> debugger not compiled in core.\n");
        CoreShutdown();
        return 2;
    }
    printf("RDRAM[0x80000000]=0x%08X (expect boot instr)\n", (unsigned)DebugMemRead32(0x80000000u));

    // read VI registers so we know the current framebuffer geometry
    uint32_t vi_status = DebugMemRead32(0x04400000u);
    uint32_t vi_dram = DebugMemRead32(0x04400004u);   // DRAM_ADDR_REG (addr = << 8)
    uint32_t vi_hstart = DebugMemRead32(0x04400018u);
    uint32_t vi_width = DebugMemRead32(0x04400024u);
    uint32_t sp_status = DebugMemRead32(0x04040010u);
    uint32_t sp_pc = DebugMemRead32(0x04080004u);
    uint32_t dp_status = DebugMemRead32(0x0410000Cu);
    uint32_t dp_current = DebugMemRead32(0x04100004u);
    uint32_t mi_reg = DebugMemRead32(0x04300000u);
    printf("VI: status=0x%08X dram=0x%08X hstart=0x%08X width=0x%08X | SP: status=0x%08X pc=0x%08X | DP: status=0x%08X cur=0x%08X | MI=0x%08X\n",
           (unsigned)vi_status, (unsigned)vi_dram, (unsigned)vi_hstart, (unsigned)vi_width,
           (unsigned)sp_status, (unsigned)sp_pc, (unsigned)dp_status, (unsigned)dp_current, (unsigned)mi_reg);
    // dump framebuffer to a .ppm for visual confirmation (best-effort)
    {
        unsigned long fba = ((unsigned long)vi_dram & 0xFFFFFF) << 6;
        int w = (vi_width & 0x3FF);
        if (w > 0 && w <= 1024 && fba >= 0x800000 && fba + 1024 * 1024 <= 0x900000) {
            char fbp[1024], fbr[1024];
            snprintf(fbp, sizeof(fbp), "%s.vid.ppm", out);
            snprintf(fbr, sizeof(fbr), "%s.vid.raw", out);
            FILE *fraw = fopen(fbr, "wb");
            if (fraw) { fwrite((unsigned char *)ptr + (fba - 0x800000), 1, 1024 * 1024, fraw); fclose(fraw); }
            for (int fmt = 0; fmt < 2; fmt++) {
                int type5 = fmt ? 1 : 0; int z = fmt ? 1 : 0;   // fmt0: type=0(z=1), fmt1: type=1(z=1)
                char ftmp[1024]; snprintf(ftmp, sizeof(ftmp), "%s.vid%d.ppm", out, fmt);
                FILE *fp = fopen(ftmp, "w");
                if (fp) {
                    int h = 240;
                    fprintf(fp, "P6\n%d %d\n255\n", w, h);
                    unsigned char *fb = (unsigned char *)ptr + (fba - 0x800000);
                    static unsigned char px[4096 * 3];
                    for (int y = 0; y < h; y++) {
                        for (int x = 0; x < w; x++) {
                            const unsigned char *p = fb + (y * w + x) * 2;
                            uint16_t v = (p[0] << 8) | p[1];
                            unsigned r, g, b;
                            if (type5 == 0 && z == 1) { r = (v >> 11) & 0x1F; g = (v >> 6) & 0x1F; b = (v >> 1) & 0x1F; r <<= 3; g <<= 3; b <<= 3; }
                            else if (type5 == 0) { r = v >> 11; g = (v >> 6) & 0x1F; b = (v >> 1) & 0x1F; r *= 8; g *= 8; b *= 8; }
                            else { r = (v >> 8); g = (v >> 3) & 0x1F; b = v & 0x1F; g *= 8; b *= 8; }
                            px[x * 3] = r; px[x * 3 + 1] = g; px[x * 3 + 2] = b;
                        }
                        fwrite(px, 1, w * 3, fp);
                    }
                    fclose(fp);
                    printf("framebuffer %d x %d -> %s\n", w, h, ftmp);
                }
            }
        }
    }

    FILE *f = fopen(out, "wb");
    if (!f) { perror("fopen out"); CoreShutdown(); return 1; }
    size_t rdram_size = 0x800000;
    if (fwrite(ptr, 1, rdram_size, f) != rdram_size) perror("fwrite");
    fclose(f);
    printf("RDRAM dumped -> %s (%u bytes)\n", out, (unsigned)rdram_size);

    DebugSetRunState(M64P_DBG_RUNSTATE_RUNNING);
    CoreDoCommand(M64CMD_STOP, 0, NULL);
    pthread_join(th, NULL);
    CoreShutdown();
    printf("done\n");
    return 0;
}