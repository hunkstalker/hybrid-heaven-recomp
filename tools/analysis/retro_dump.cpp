// retro_dump.cpp: headless libretro harness to run an N64 core and dump RDRAM
// via retro_get_memory_data(RETRO_MEMORY_SYSTEM_RAM). No video/audio/GL needed.
//
// Build:
//   g++ -O2 tools/analysis/retro_dump.cpp -o work/retro_dump -ldl -lpthread

#include <dlfcn.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <chrono>
#include <thread>

// --- minimal libretro API (retro.h subset) ---
static const unsigned RETRO_DEVICE_JOYPAD = 1;
static const unsigned RETRO_MEMORY_SYSTEM_RAM = 2;

static const unsigned RETRO_ENVIRONMENT_GET_CAN_DUPE = 3;
static const unsigned RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY = 7;
static const unsigned RETRO_ENVIRONMENT_SET_PIXEL_FORMAT = 8;
static const unsigned RETRO_ENVIRONMENT_GET_VARIABLE = 13;
static const unsigned RETRO_ENVIRONMENT_SET_VARIABLES = 14;
static const unsigned RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE = 15;
static const unsigned RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME = 16;
static const unsigned RETRO_ENVIRONMENT_GET_LOG_INTERFACE = 27;
static const unsigned RETRO_ENVIRONMENT_GET_CORE_ASSETS_DIRECTORY = 30;
static const unsigned RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY = 31;
static const unsigned RETRO_ENVIRONMENT_SET_CONTROLLER_INFO = 35;
static const unsigned RETRO_ENVIRONMENT_SET_GEOMETRY = 37;

typedef bool (*retro_environment_t)(unsigned cmd, void *data);
typedef void (*retro_video_refresh_t)(const void *data, unsigned width, unsigned height, size_t pitch);
typedef void (*retro_audio_sample_t)(int16_t left, int16_t right);
typedef size_t (*retro_audio_sample_batch_t)(const int16_t *data, size_t frames);
typedef void (*retro_input_poll_t)(void);
typedef int16_t (*retro_input_state_t)(unsigned port, unsigned device, unsigned index, unsigned id);

typedef struct retro_game_info {
    const char *path;
    const void *data;
    size_t size;
    const char *meta;
} retro_game_info;

typedef struct retro_system_info {
    const char *library_name;
    const char *library_version;
    const char *valid_extensions;
    bool need_fullpath;
    bool block_extract;
} retro_system_info;

typedef struct retro_game_geometry {
    unsigned base_width, base_height, max_width, max_height;
    float aspect_ratio;
} retro_game_geometry;

typedef struct retro_system_timing {
    double fps;
    double sample_rate;
} retro_system_timing;

typedef struct retro_system_av_info {
    retro_game_geometry geometry;
    retro_system_timing timing;
} retro_system_av_info;

typedef struct retro_variable {
    const char *key;
    const char *value;
} retro_variable;

typedef struct retro_log_callback {
    void (*log)(unsigned level, const char *fmt, ...);
} retro_log_callback;

// --- core fn pointers ---
static void *core;
typedef void (*retro_set_environment_t)(retro_environment_t);
typedef void (*retro_set_video_refresh_t)(retro_video_refresh_t);
typedef void (*retro_set_audio_sample_t)(retro_audio_sample_t);
typedef void (*retro_set_audio_sample_batch_t)(retro_audio_sample_batch_t);
typedef void (*retro_set_input_poll_t)(retro_input_poll_t);
typedef void (*retro_set_input_state_t)(retro_input_state_t);
typedef void (*retro_set_controller_port_device_t)(unsigned, unsigned);
static retro_set_environment_t retro_set_environment;
static retro_set_video_refresh_t retro_set_video_refresh;
static retro_set_audio_sample_t retro_set_audio_sample;
static retro_set_audio_sample_batch_t retro_set_audio_sample_batch;
static retro_set_input_poll_t retro_set_input_poll;
static retro_set_input_state_t retro_set_input_state;
static retro_set_controller_port_device_t retro_set_controller_port_device;
static void (*retro_init)(void);
static void (*retro_deinit)(void);
static unsigned (*retro_api_version)(void);
static void (*retro_get_system_info)(retro_system_info *);
static void (*retro_get_system_av_info)(retro_system_av_info *);
static bool (*retro_load_game)(const retro_game_info *);
static void (*retro_run)(void);
static void *(*retro_get_memory_data)(unsigned id);
static size_t (*retro_get_memory_size)(unsigned id);
static bool (*retro_UNserialize)(const void *, size_t);
static size_t (*retro_serialize_size)(void);
static bool (*retro_serialize)(void *, size_t);
static void (*retro_reset)(void);

static void log_cb(unsigned level, const char *fmt, ...) { (void)level; (void)fmt; }

static bool env_cb(unsigned cmd, void *data) {
    fprintf(stderr, "[env] cmd %u\n", cmd);
    switch (cmd) {
        case RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY:
        case RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY:
        case RETRO_ENVIRONMENT_GET_CORE_ASSETS_DIRECTORY: {
            const char **d = (const char **)data;
            *d = "/tmp";
            return true;
        }
        case RETRO_ENVIRONMENT_SET_PIXEL_FORMAT:
            return true; // accept whatever the core wants (we discard frames)
        case RETRO_ENVIRONMENT_GET_CAN_DUPE: {
            bool *b = (bool *)data;
            *b = true;
            return true;
        }
        case RETRO_ENVIRONMENT_GET_VARIABLE: {
            retro_variable *v = (retro_variable *)data;
            if (v && v->key) {
                fprintf(stderr, "[var] key=%s\n", v->key);
                if (strcmp(v->key, "mupen64plus-rdp-plugin") == 0) {
                    v->value = "angrylion";
                    fprintf(stderr, "[var] rdp-plugin -> angrylion\n");
                } else if (strcmp(v->key, "mupen64plus-rsp-plugin") == 0) {
                    v->value = "parallel";
                    fprintf(stderr, "[var] rsp-plugin -> parallel\n");
                } else {
                    v->value = "";
                }
            }
            return true;
        }
        case RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE: {
            bool *b = (bool *)data;
            *b = false;
            return true;
        }
        case RETRO_ENVIRONMENT_GET_LOG_INTERFACE: {
            retro_log_callback *cb = (retro_log_callback *)data;
            cb->log = log_cb;
            return true;
        }
        case RETRO_ENVIRONMENT_SET_GEOMETRY:
        case RETRO_ENVIRONMENT_SET_VARIABLES:
        case RETRO_ENVIRONMENT_SET_CONTROLLER_INFO:
        case RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME:
            return true;
        default:
            return false; // unknown command: tell the core (do not fake data)
    }
}

static void video_cb(const void *data, unsigned w, unsigned h, size_t pitch) { (void)data;(void)w;(void)h;(void)pitch; }
static void audio_sb(int16_t l, int16_t r) { (void)l;(void)r; }
static size_t audio_batch_cb(const int16_t *data, size_t frames) { (void)data; return frames; }
static void input_poll_cb(void) {}
static int16_t input_state_cb(unsigned p, unsigned d, unsigned i, unsigned id) { (void)p;(void)d;(void)i;(void)id; return 0; }

#define SYM(x) do { x = (decltype(x))dlsym(core, #x); if (!x) { fprintf(stderr, "missing symbol %s\n", #x); return 1; } } while (0)

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc < 3) { fprintf(stderr, "usage: %s <rom> <out.rdram> [seconds]\n", argv[0]); return 1; }
    const char *rompath = argv[1];
    const char *out = argv[2];
    double secs = (argc > 3) ? atof(argv[3]) : 4.0;

    FILE *fr = fopen(rompath, "rb");
    if (!fr) { perror("rom open"); return 1; }
    fseek(fr, 0, SEEK_END); long n = ftell(fr); fseek(fr, 0, SEEK_SET);
    unsigned char *rom = (unsigned char *)malloc((size_t)n);
    if (fread(rom, 1, (size_t)n, fr) != (size_t)n) { perror("rom read"); return 1; }
    fclose(fr);

    core = dlopen("/usr/lib/libretro/mupen64plus_next_libretro.so", RTLD_NOW);
    if (!core) { fprintf(stderr, "core dlopen: %s\n", dlerror()); return 1; }
    SYM(retro_set_environment);
    SYM(retro_set_video_refresh);
    SYM(retro_set_audio_sample);
    SYM(retro_set_audio_sample_batch);
    SYM(retro_set_input_poll);
    SYM(retro_set_input_state);
    SYM(retro_set_controller_port_device);
    SYM(retro_init);
    SYM(retro_deinit);
    SYM(retro_api_version);
    SYM(retro_get_system_info);
    SYM(retro_get_system_av_info);
    SYM(retro_load_game);
    SYM(retro_run);
    SYM(retro_get_memory_data);
    SYM(retro_get_memory_size);
    SYM(retro_serialize_size);
    SYM(retro_serialize);

    retro_set_environment(env_cb);
    retro_set_video_refresh(video_cb);
    retro_set_audio_sample(audio_sb);
    retro_set_audio_sample_batch(audio_batch_cb);
    retro_set_input_poll(input_poll_cb);
    retro_set_input_state(input_state_cb);
    retro_set_controller_port_device(0, RETRO_DEVICE_JOYPAD);

    printf("libretro API version: %u\n", retro_api_version());
    retro_system_info si;
    retro_get_system_info(&si);
    printf("core: %s v%s\n", si.library_name ? si.library_name : "?", si.library_version ? si.library_version : "?");
    retro_init();

    retro_game_info gi;
    memset(&gi, 0, sizeof(gi));
    gi.path = rompath;
    gi.data = rom;
    gi.size = (size_t)n;
    if (!retro_load_game(&gi)) {
        fprintf(stderr, "retro_load_game FAILED\n");
        retro_deinit();
        return 2;
    }

    retro_system_av_info av;
    retro_get_system_av_info(&av);
    double fps = av.timing.fps > 0 ? av.timing.fps : 60.0;
    unsigned frames = (unsigned)(secs * fps);
    printf("fps=%.2f -> %u frames over %.1fs\n", fps, frames, secs);

    auto write_dump = [&](const char *path, const char *tag) -> bool {
        void *ram = retro_get_memory_data(RETRO_MEMORY_SYSTEM_RAM);
        size_t ramsz = retro_get_memory_size(RETRO_MEMORY_SYSTEM_RAM);
        fprintf(stderr, "[mem] ram=%p size=%zu (@%s)\n", ram, ramsz, tag);
        if (!ram || !ramsz) { fprintf(stderr, "RAM not exposed (@%s)\n", tag); return false; }
        FILE *f = fopen(path, "wb");
        if (!f) { perror(path); return false; }
        size_t w = fwrite(ram, 1, ramsz, f);
        fclose(f);
        printf("dumped %zu bytes -> %s (%s)\n", w, path, tag);
        return true;
    };

    write_dump(out, "post-load");            // before first retro_run

    size_t sersz = retro_serialize_size();
    fprintf(stderr, "[ser] size=%zu\n", sersz);
    std::vector<unsigned char> serbuf(sersz);
    auto write_ser = [&](const char *path, const char *tag) -> bool {
        if (retro_serialize(serbuf.data(), sersz)) {
            FILE *fs = fopen(path, "wb");
            if (!fs) { perror(path); return false; }
            fwrite(serbuf.data(), 1, sersz, fs);
            fclose(fs);
            printf("serialized %zu bytes -> %s (%s)\n", sersz, path, tag);
            return true;
        }
        fprintf(stderr, "serialize failed (@%s)\n", tag);
        return false;
    };

    write_ser("work/scratch/afterload.ser", "post-load");

    auto t0 = std::chrono::steady_clock::now();
    for (unsigned i = 0; i < frames; i++) {
        retro_run();
        if ((i & 0xFF) == 0) {
            fprintf(stderr, "frame %u\n", i);
            write_dump(out, "mid-run");
            write_ser("work/scratch/frame.ser", "mid-run");
            if ((std::chrono::steady_clock::now() - t0) > std::chrono::seconds(60)) {
                fprintf(stderr, "wall-clock limit hit at frame %u\n", i);
                break;
            }
        }
    }
    auto dt = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
    printf("ran %u frames in %.1fs wall (%.1f fps emu)\n", frames, dt, frames / (dt ? dt : 1.0));

    write_dump(out, "end-run");
    printf("END reached\n");

    retro_deinit();
    return 0;
}