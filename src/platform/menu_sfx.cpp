// hh_menu_sfx — efectos de sonido del menú (move/accept/back). Ver include/hh.h.
//
// Se **mezclan sobre el stream de audio del juego** (un único dispositivo SDL), así que no hace
// falta abrir un segundo dispositivo (falla en algunos drivers). Los WAV (48 kHz / S16 / estéreo) se
// cargan de `<app>/sounds/*.wav` (junto al ejecutable) y se resamplean a la tasa real del
// dispositivo. Sin dependencias nuevas (SDL2 ya está) y sin decodificador de mp3 (se versionan WAV).

#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <mutex>
#include <vector>

#include <SDL.h>

#include "hh.h"

namespace hh::menu_sfx {
namespace {

constexpr int kNumSfx = 3;
constexpr double kSrcRate = 48000.0;   // tasa de los WAV
constexpr int kChannels = 2;

std::vector<uint8_t> g_data[kNumSfx];
bool g_tried = false;

const char* kFiles[kNumSfx] = { "menu-move.wav", "menu-accept.wav", "menu-back.wav" };

// Instancia de un SFX sonando: referencia a su WAV y posición (en frames) con resample.
struct Instance {
    const std::vector<uint8_t>* data = nullptr;
    double pos = 0.0;
};

std::mutex g_mutex;
std::vector<Instance> g_active;

void init_once() {
    if (g_tried) return;
    g_tried = true;
    const std::filesystem::path dir = hh::get_app_folder_path() / "sounds";
    for (int i = 0; i < kNumSfx; ++i) {
        SDL_AudioSpec spec{};
        uint8_t* buf = nullptr;
        uint32_t len = 0;
        const std::filesystem::path p = dir / kFiles[i];
        if (SDL_LoadWAV(p.string().c_str(), &spec, &buf, &len) == nullptr) {
            hh::log("[sfx] no se pudo cargar '%s': %s\n", p.string().c_str(), SDL_GetError());
            continue;
        }
        if (spec.freq != static_cast<int>(kSrcRate) || spec.channels != kChannels ||
            spec.format != AUDIO_S16) {
            hh::log("[sfx] '%s' formato inesperado (freq=%d ch=%d fmt=0x%X)\n", kFiles[i],
                    spec.freq, spec.channels, spec.format);
            SDL_FreeWAV(buf);
            continue;
        }
        g_data[i].assign(buf, buf + len);
        SDL_FreeWAV(buf);
    }
    hh::log("[sfx] listo: move=%zuB accept=%zuB back=%zuB\n", g_data[0].size(), g_data[1].size(),
            g_data[2].size());
}

}  // namespace

void init() { init_once(); }

void play(Sfx s) {
    if (hh::audio_config().menusfx != "si") {
        return;   // MENÚ SFX desactivado
    }
    init_once();
    const int i = static_cast<int>(s);
    if (i < 0 || i >= kNumSfx || g_data[i].empty()) return;
    const std::lock_guard<std::mutex> lock(g_mutex);
    g_active.push_back(Instance{ &g_data[i], 0.0 });
}

// Mezcla los SFX activos sobre `samples` (estéreo entrelazado). Llamar desde hh::queue_samples.
void mix(int16_t* samples, size_t sample_count) {
    if (!g_tried) return;   // sin SFX cargados (p. ej. headless), no tocar el buffer
    const size_t frames = sample_count / kChannels;
    const double step = kSrcRate / static_cast<double>(hh::audio_output_rate());
    const std::lock_guard<std::mutex> lock(g_mutex);
    for (size_t f = 0; f < frames; ++f) {
        for (auto it = g_active.begin(); it != g_active.end();) {
            const std::vector<uint8_t>& d = *it->data;
            const size_t total = d.size() / (kChannels * sizeof(int16_t));
            const size_t idx = static_cast<size_t>(it->pos);
            if (idx >= total) {
                it = g_active.erase(it);
                continue;
            }
            const int16_t* pcm = reinterpret_cast<const int16_t*>(d.data());
            const int l = samples[f * kChannels + 0] + pcm[idx * kChannels + 0];
            const int r = samples[f * kChannels + 1] + pcm[idx * kChannels + 1];
            samples[f * kChannels + 0] = static_cast<int16_t>(std::clamp(l, -32768, 32767));
            samples[f * kChannels + 1] = static_cast<int16_t>(std::clamp(r, -32768, 32767));
            it->pos += step;
            ++it;
        }
    }
}

}  // namespace hh::menu_sfx
