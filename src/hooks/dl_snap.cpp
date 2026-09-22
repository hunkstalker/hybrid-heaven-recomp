// Adaptado del port de referencia (MIT; ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt):
// su Phase 07 (widescreen), `src/dlcensus.cpp`. Ver docs/BUILDING_windows.md ([video]).
//
// Snap del *scissor* de overscan a full-frame. El juego dibuja la escena 4:3 dentro de un
// G_SETSCISSOR de overscan (16,8..304,232 en low-res; 32,16..608,464 en hi-res); con RT64 en
// aspect=Expand a secas el 3D queda pillarboxed. Este paso recorre las display lists enviadas y
// reescribe esos dos rects exactos a 0,0..320,240 / 0,0..640,480 (conservando los bits de modo).
// La carta de letterbox no se toca. `HH_FULL_FRAME=0` lo desactiva (A/B).
//
// RDRAM de N64Recomp: los words de 32 bits se guardan en orden host (LE) en su offset fisico
// (MEM_W no hace XOR; solo MEM_H/MEM_B), asi que los commands se leen con un memcpy plano.

#include "hh.h"
#include "hh/hudid.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

namespace {
constexpr uint8_t kSetScissor = 0xED;
constexpr uint8_t kMoveWord   = 0xDB;
constexpr uint8_t kDl         = 0xDE;
constexpr uint8_t kEndDl      = 0xDF;
constexpr uint8_t kRdpHalf1   = 0xE1;
constexpr uint8_t kRdpHalf2   = 0xF1;
constexpr uint8_t kTexRect    = 0xE4;
constexpr uint8_t kTexRectFlip = 0xE5;
constexpr uint8_t kFillRect   = 0xF6;
constexpr uint8_t kSetFillColor = 0xF7;
constexpr uint8_t kSetTImg    = 0xFD;
constexpr uint8_t kSetCImg    = 0xFF;
constexpr uint8_t kMwSegment  = 0x06;   // G_MOVEWORD index

uint32_t dl_word(const uint8_t* rdram, uint32_t phys) {
    uint32_t v;
    std::memcpy(&v, rdram + (phys & 0x7FFFFC), sizeof v);
    return v;
}

// G_SETSCISSOR words en 10.2 fixed-point, tal como los emite el juego.
constexpr uint32_t scissor_w0(uint32_t ulx, uint32_t uly) {
    return (static_cast<uint32_t>(kSetScissor) << 24) | ((ulx * 4) << 12) | (uly * 4);
}
constexpr uint32_t scissor_w1(uint32_t lrx, uint32_t lry) {
    return ((lrx * 4) << 12) | (lry * 4);
}

struct Snap { uint32_t w0, w1, full_w0, full_w1; };
constexpr Snap kSnaps[] = {
    { scissor_w0(16, 8), scissor_w1(304, 232), scissor_w0(0, 0), scissor_w1(320, 240) },
    { scissor_w0(32, 16), scissor_w1(608, 464), scissor_w0(0, 0), scissor_w1(640, 480) },
};

struct Walker {
    uint8_t* rdram;
    uint32_t segments[16] = {};
    int snapped = 0;

    uint32_t physical(uint32_t address) const {
        const uint32_t seg = (address >> 24) & 0x0F;
        if ((address >> 24) >= 0x80) return address & 0x1FFFFFFF;
        return (segments[seg] + (address & 0x00FFFFFF)) & 0x1FFFFFFF;
    }

    void walk(uint32_t address, int depth) {
        if (depth > 12) return;
        uint32_t pc = physical(address);
        for (int guard = 0; guard < 200000; ++guard) {
            if (pc >= 0x800000) return;
            const uint32_t w0 = dl_word(rdram, pc);
            const uint32_t w1 = dl_word(rdram, pc + 4);
            const uint8_t op = static_cast<uint8_t>(w0 >> 24);
            // F3DEX2 no tiene comandos entre G_QUAD (0x07) y G_SPECIAL_3 (0xD3): llegar a uno
            // significa que el walk salio de la lista (segmento no visto).
            if (op > 0x07 && op < 0xD3) return;
            pc += 8;
            switch (op) {
                case kEndDl:
                    return;
                case kDl: {
                    const bool branch = ((w0 >> 16) & 0xFF) != 0;
                    if (branch) pc = physical(w1);
                    else walk(w1, depth + 1);
                    break;
                }
                case kMoveWord:
                    // F3DEX2: index en bits 16-23, offset (segmento * 4) en los 16 bajos.
                    if (((w0 >> 16) & 0xFF) == kMwSegment) {
                        segments[((w0 & 0xFFFF) / 4) & 0x0F] = w1 & 0x1FFFFFFF;
                    }
                    break;
                case kSetScissor:
                    for (const Snap& s : kSnaps) {
                        if (w0 == s.w0 && (w1 & 0x00FFFFFF) == s.w1) {
                            const uint32_t n0 = s.full_w0;
                            const uint32_t n1 = (w1 & 0xFF000000) | s.full_w1;
                            std::memcpy(rdram + ((pc - 8) & 0x7FFFFC), &n0, sizeof n0);
                            std::memcpy(rdram + ((pc - 4) & 0x7FFFFC), &n1, sizeof n1);
                            ++snapped;
                            break;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
};

// Trace temporal (HH_HUD_TRACE=1): recorre las listas como el snap, reconstruye el estado 2D
// (segmentos, imagen, color de relleno, ancho de framebuffer) y lista, UNA vez por identidad,
// los elementos `tex:`/`dl:`/`fill:` con su extension en 320x240. Sirve para re-derivar en
// NUESTRA build las identidades de la tabla fija (RETOMAR.md §3.1). No clasifica nada.
struct HudWalker {
    uint8_t* rdram;
    uint32_t segments[16] = {};
    uint32_t fb_width = 320;
    uint32_t image = 0;
    uint32_t fill_colour = 0;
    std::string texture_ident;
    // Estaticos: el trace vive en varias llamadas (una por lista enviada) y solo quiere cada
    // identidad una vez por sesion.
    static inline std::vector<std::string> seen_tex, seen_dl, seen_fill;

    uint32_t physical(uint32_t address) const {
        const uint32_t seg = (address >> 24) & 0x0F;
        if ((address >> 24) >= 0x80) return address & 0x1FFFFFFF;
        return (segments[seg] + (address & 0x00FFFFFF)) & 0x1FFFFFFF;
    }

    bool once(std::vector<std::string>& seen, const std::string& id) {
        for (const auto& s : seen) {
            if (s == id) return false;
        }
        if (seen.size() > 2000) return false;
        seen.push_back(id);
        return true;
    }

    void report(const std::string& id, float x0, float x1, float y0, float y1) {
        hh::log("[hh-hud] %s x %.0f..%.0f y %.0f..%.0f rect\n", id.c_str(), x0, x1, y0, y1);
    }

    void walk(uint32_t address, int depth) {
        if (depth > 12) return;
        uint32_t pc = physical(address);
        for (int guard = 0; guard < 200000; ++guard) {
            if (pc >= 0x800000) return;
            const uint32_t w0 = hh::hudid::read_word(rdram, pc);
            const uint32_t w1 = hh::hudid::read_word(rdram, pc + 4);
            const uint8_t op = static_cast<uint8_t>(w0 >> 24);
            if (op > 0x07 && op < 0xD3) return;
            pc += 8;
            switch (op) {
                case kEndDl:
                    return;
                case kDl: {
                    const bool branch = ((w0 >> 16) & 0xFF) != 0;
                    const uint32_t target = physical(w1);
                    const std::string id = hh::hudid::list(rdram, w1, target);
                    if (once(seen_dl, id)) {
                        hh::log("[hh-hud] %s %s phys 0x%08x\n", id.c_str(),
                                branch ? "branch" : "call", target);
                    }
                    if (branch) pc = target;
                    else walk(w1, depth + 1);
                    break;
                }
                case kMoveWord:
                    // F3DEX2: index en bits 16-23, offset (segmento * 4) en los 16 bajos.
                    if (((w0 >> 16) & 0xFF) == kMwSegment) {
                        segments[((w0 & 0xFFFF) / 4) & 0x0F] = w1 & 0x1FFFFFFF;
                    }
                    break;
                case kSetCImg:
                    fb_width = ((w1 & 0x00FFFFFF) == 0x00400000) ? 640 : 320;
                    break;
                case kSetTImg:
                    image = w1;
                    texture_ident = hh::hudid::texture(rdram, w1, physical(w1));
                    break;
                case kSetFillColor:
                    fill_colour = w1;
                    break;
                case kFillRect: {
                    const float to_320 = 320.0f / static_cast<float>(fb_width);
                    const std::string id = hh::hudid::fill(
                        fill_colour,
                        int((((w1 >> 12) & 0xFFF) / 4.0f) * to_320), int(((w1 & 0xFFF) / 4.0f) * to_320),
                        int((((w0 >> 12) & 0xFFF) / 4.0f) * to_320), int(((w0 & 0xFFF) / 4.0f) * to_320));
                    if (!id.empty() && once(seen_fill, id)) {
                        report(id, (((w1 >> 12) & 0xFFF) / 4.0f) * to_320, (((w0 >> 12) & 0xFFF) / 4.0f) * to_320,
                               ((w1 & 0xFFF) / 4.0f) * to_320, ((w0 & 0xFFF) / 4.0f) * to_320);
                    }
                    break;
                }
                case kTexRect:
                case kTexRectFlip: {
                    const float to_320 = 320.0f / static_cast<float>(fb_width);
                    if (once(seen_tex, texture_ident)) {
                        report(texture_ident, (((w1 >> 12) & 0xFFF) / 4.0f) * to_320,
                               (((w0 >> 12) & 0xFFF) / 4.0f) * to_320,
                               ((w1 & 0xFFF) / 4.0f) * to_320, ((w0 & 0xFFF) / 4.0f) * to_320);
                    }
                    // G_RDPHALF_1 (s,t) y G_RDPHALF_2 (dsdx,dtdy) siguen al rect.
                    if (static_cast<uint8_t>(hh::hudid::read_word(rdram, pc) >> 24) == kRdpHalf1) pc += 8;
                    if (static_cast<uint8_t>(hh::hudid::read_word(rdram, pc) >> 24) == kRdpHalf2) pc += 8;
                    break;
                }
                default:
                    break;
            }
        }
    }
};
}  // namespace

namespace hh {
bool full_frame_enabled() {
    static const bool on = [] {
        const char* e = getenv("HH_FULL_FRAME");
        return !(e != nullptr && *e != '\0' && strcmp(e, "0") == 0);  // por defecto ON
    }();
    return on;
}

void snap_overscan(uint8_t* rdram, uint32_t list_address) {
    // Con aspect=expand (o auto, que mapea a Expand): widescreen. El HUD no se re-ancla (queda en la
    // zona 4:3), pero tampoco se desmonta; ver docs/BUILDING_windows.md.
    const std::string& a = video_config().aspect;
    const bool expand = (a == "expand" || a == "auto");
    if (!expand || !full_frame_enabled() || rdram == nullptr) {
        return;
    }
    Walker w{ rdram };
    w.walk(list_address, 0);
    if (w.snapped > 0) {
        static bool reported = false;
        if (!reported) {
            reported = true;
            hh::log("HH_FULL_FRAME: overscan scissor snapped a full-frame (%d)\n", w.snapped);
            std::fprintf(stderr, "[VIDEO] HH_FULL_FRAME: scissor snap ON (%d)\n", w.snapped);
        }
    }
}

bool hud_trace_enabled() {
    static const bool on = [] {
        const char* e = getenv("HH_HUD_TRACE");
        return e != nullptr && *e != '\0' && strcmp(e, "0") != 0;
    }();
    return on;
}

void hud_trace(uint8_t* rdram, uint32_t list_address) {
    if (!hud_trace_enabled() || rdram == nullptr) return;
    HudWalker w{ rdram };
    w.walk(list_address, 0);
}
}  // namespace hh
