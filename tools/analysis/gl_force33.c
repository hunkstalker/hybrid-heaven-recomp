/* gl_force33.c: LD_PRELOAD shim so GL video plugins (glide64mk2 etc.) that manage
 * their own SDL_GL context get a GL 3.3 core context instead of the default 2.1,
 * fixing GLSL >= 1.30 features. Also no-ops SDL_GL_SetSwapInterval (harmless). */
#define _GNU_SOURCE
#include <SDL2/SDL.h>
#include <dlfcn.h>

static void (*real_SetAttr)(SDL_GLattr, int) = NULL;
static int injected = 0;

static void ensure_attrs(void) {
    if (injected) return;
    real_SetAttr = (void (*)(SDL_GLattr, int))dlsym(RTLD_NEXT, "SDL_GL_SetAttribute");
    if (!real_SetAttr) return;
    real_SetAttr(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    real_SetAttr(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    real_SetAttr(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    injected = 1;
}

int SDL_GL_SetAttribute(SDL_GLattr attr, int value) {
    int (*real)(SDL_GLattr, int) = (int (*)(SDL_GLattr, int))dlsym(RTLD_NEXT, "SDL_GL_SetAttribute");
    if (real) return real(attr, value);
    return -1;
}

SDL_GLContext SDL_GL_CreateContext(SDL_Window *window) {
    SDL_GLContext (*real)(SDL_Window *) = (SDL_GLContext (*)(SDL_Window *))dlsym(RTLD_NEXT, "SDL_GL_CreateContext");
    if (!real) return NULL;
    ensure_attrs();
    return real(window);
}

int SDL_GL_SetSwapInterval(int interval) {
    (void)interval;
    return 0;
}