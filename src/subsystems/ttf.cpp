// hh::ttf — rasteriza la fuente Work Sans embebida a un atlas RGBA8 (cobertura en R+A). Ver hh/ttf.h.

#include "hh/ttf.h"

#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <vector>

#include "hh.h"

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb/stb_truetype.h"

// Bytes del .ttf incrustado (generados por CMake desde assets/fonts/WorkSans-SemiBold.ttf).
extern const unsigned char kWorkSansTtf[];
extern const unsigned long kWorkSansTtfSize;

namespace hh::ttf {
namespace {

constexpr float kPixelHeight = 22.0f;   // tamano de rasterizado (px del atlas)
constexpr unsigned kAtlasW = 512;       // ancho del atlas (fijo)
constexpr unsigned kPad = 1;

struct State {
    bool built = false;
    bool ok = false;
    stbtt_fontinfo font{};
    std::vector<uint8_t> atlas;   // RGBA8
    unsigned atlas_h = 0;
    float scale = 1.0f;
    float ascent = 0.0f, descent = 0.0f, line_h = 0.0f;
    std::unordered_map<unsigned, Glyph> glyphs;
};

uint8_t* atlas_px(std::vector<uint8_t>& a, unsigned x, unsigned y, unsigned w) {
    return a.data() + (static_cast<size_t>(y) * w + x) * 4u;
}

State& state() {
    static State s;
    return s;
}

void build(State& s) {
    s.built = true;
    // Fuente: los bytes INCRUSTADOS (**SemiBold**, el único peso que usamos; ver CMakeLists). Para
    // iterar la tipografía sin recompilar se puede forzar un .ttf con `HH_TTF=<ruta>`.
    std::vector<uint8_t> file_bytes;
    const uint8_t* data = kWorkSansTtf;
    unsigned long size = kWorkSansTtfSize;
    std::filesystem::path path;
    if (const char* e = std::getenv("HH_TTF"); e != nullptr && *e != '\0') {
        path = e;
    }
    if (!path.empty()) {
        std::ifstream in(path, std::ios::binary);
        if (in) {
            file_bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
            if (!file_bytes.empty()) {
                data = file_bytes.data();
                size = static_cast<unsigned long>(file_bytes.size());
                hh::log("[ttf] fuente: %s (%lu B)\n", path.string().c_str(), size);
            }
        }
    }
    if (size == 0) return;
    if (!stbtt_InitFont(&s.font, data, stbtt_GetFontOffsetForIndex(data, 0))) {
        return;
    }
    s.scale = stbtt_ScaleForPixelHeight(&s.font, kPixelHeight);
    int a = 0, d = 0, g = 0;
    stbtt_GetFontVMetrics(&s.font, &a, &d, &g);
    s.ascent = static_cast<float>(a) * s.scale;
    s.descent = static_cast<float>(-d) * s.scale;
    s.line_h = static_cast<float>(a - d) * s.scale;

    // Charset: ASCII imprimible + Latin-1 (acentos para es/ca/fr/de).
    std::vector<unsigned> cps;
    for (unsigned c = 32; c <= 126; ++c) cps.push_back(c);
    for (unsigned c = 0xA0; c <= 0xFF; ++c) cps.push_back(c);

    // Puerto 1: calcular cajas y repartir en "estantes" (shelf packing) dentro de kAtlasW.
    struct Box { unsigned cp, w, h; int xoff, yoff; float adv; };
    std::vector<Box> boxes;
    unsigned total_h = 0, pen_x = kPad, pen_y = kPad, row_h = 0;
    const unsigned max_h = static_cast<unsigned>(s.line_h) + 4;
    for (unsigned cp : cps) {
        int adv = 0, lsb = 0;
        stbtt_GetCodepointHMetrics(&s.font, static_cast<int>(cp), &adv, &lsb);
        int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
        stbtt_GetCodepointBitmapBox(&s.font, static_cast<int>(cp), s.scale, s.scale, &x0, &y0, &x1,
                                    &y1);
        unsigned gw = static_cast<unsigned>(x1 - x0 > 0 ? x1 - x0 : 0);
        unsigned gh = static_cast<unsigned>(y1 - y0 > 0 ? y1 - y0 : 0);
        if (pen_x + gw + kPad > kAtlasW) { pen_x = kPad; pen_y += row_h + kPad; row_h = 0; }
        boxes.push_back({cp, gw, gh, x0, y0, static_cast<float>(adv) * s.scale});
        pen_x += gw + kPad;
        if (gh > row_h) row_h = gh;
        (void)max_h;
    }
    total_h = pen_y + row_h + kPad;
    if (total_h < 16) total_h = 16;

    s.atlas.assign(static_cast<size_t>(kAtlasW) * total_h * 4u, 0);
    s.atlas_h = total_h;

    // Puerto 2: rasterizar cada glifo en su caja.
    unsigned px = kPad, py = kPad, rh = 0;
    for (const Box& b : boxes) {
        if (px + b.w + kPad > kAtlasW) { px = kPad; py += rh + kPad; rh = 0; }
        Glyph gl;
        gl.x = static_cast<int>(px);
        gl.y = static_cast<int>(py);
        gl.w = static_cast<int>(b.w);
        gl.h = static_cast<int>(b.h);
        gl.xoff = static_cast<float>(b.xoff);
        gl.yoff = static_cast<float>(b.yoff);
        gl.advance = b.adv;
        if (b.w > 0 && b.h > 0) {
            std::vector<uint8_t> cov(static_cast<size_t>(b.w) * b.h, 0);
            stbtt_MakeCodepointBitmap(&s.font, cov.data(), static_cast<int>(b.w),
                                      static_cast<int>(b.h), static_cast<int>(b.w), s.scale, s.scale,
                                      static_cast<int>(b.cp));
            for (unsigned yy = 0; yy < b.h; ++yy) {
                for (unsigned xx = 0; xx < b.w; ++xx) {
                    const uint8_t c = cov[static_cast<size_t>(yy) * b.w + xx];
                    uint8_t* p = atlas_px(s.atlas, px + xx, py + yy, kAtlasW);
                    p[0] = c; p[1] = c; p[2] = c; p[3] = c;   // cobertura en R y A (mode 0)
                }
            }
            gl.ok = true;
        }
        s.glyphs[b.cp] = gl;
        px += b.w + kPad;
        if (b.h > rh) rh = b.h;
    }
    s.ok = true;
}

// Decodifica el siguiente codepoint UTF-8 desde `s[i]`.
unsigned utf8_next(const char* s, size_t& i) {
    const unsigned char c = static_cast<unsigned char>(s[i]);
    if (c < 0x80) { ++i; return c; }
    if ((c >> 5) == 0x6 && s[i + 1]) {
        unsigned v = ((c & 0x1Fu) << 6) | (static_cast<unsigned char>(s[i + 1]) & 0x3Fu);
        i += 2;
        return v;
    }
    if ((c >> 4) == 0xE && s[i + 1] && s[i + 2]) {
        unsigned v = ((c & 0x0Fu) << 12) | ((static_cast<unsigned char>(s[i + 1]) & 0x3Fu) << 6) |
                     (static_cast<unsigned char>(s[i + 2]) & 0x3Fu);
        i += 3;
        return v;
    }
    ++i;
    return '?';
}

}  // namespace

bool ready() {
    State& s = state();
    if (!s.built) build(s);
    return s.ok;
}

const uint8_t* atlas_rgba8() { return state().atlas.data(); }
unsigned atlas_width() { return kAtlasW; }
unsigned atlas_height() { return state().atlas_h; }
float ascent() { return state().ascent; }
float descent() { return state().descent; }
float line_height() { return state().line_h; }

Glyph glyph(unsigned cp) {
    State& s = state();
    if (!s.built) build(s);
    auto it = s.glyphs.find(cp);
    if (it == s.glyphs.end()) return Glyph{};
    return it->second;
}

float text_width(const char* str) {
    State& s = state();
    if (!s.built) build(s);
    float w = 0.0f;
    size_t i = 0;
    while (str != nullptr && str[i] != '\0') {
        const unsigned cp = utf8_next(str, i);
        auto it = s.glyphs.find(cp);
        if (it != s.glyphs.end()) w += it->second.advance;
    }
    return w;
}

}  // namespace hh::ttf
