// hh_font — backend_game (A2 Fase A): fuente del juego -> atlas RGBA8 host (sin GBI).
// Ver include/hh/font.h y notes/2026-09-23-b-fuente-formato-y-gaiji.md.

#include "hh.h"
#include "hh/font.h"
#include "hh/menu_marks.h"

#include <cstdint>
#include <fstream>
#include <string>

namespace hh::font::game {
namespace {

// Fichero color0 de la fuente (Nisitenma idx 107) en la ROM US: offset y tamano del manifiesto.
constexpr uint32_t kFontRomOffset = 0x6E3CD6;
constexpr uint32_t kFontRomSize = 4096;

constexpr unsigned kGlyphW = 8;
constexpr unsigned kGlyphH = 8;
constexpr unsigned kBlockStride = 32;   // dos glifos 8x8 2bpp por bloque
constexpr unsigned kMaxValue = 64;      // valores 0..63 (letras + espacio)
constexpr unsigned kAtlasCols = 16;
constexpr unsigned kAtlasWidth = kAtlasCols * kGlyphW;                 // 128
constexpr unsigned kAtlasHeight = (kMaxValue / kAtlasCols) * kGlyphH;  // 32 (letras)

// Region de MARCAS (menu): sprites recortados, celda 8x12, debajo de las letras.
constexpr unsigned kMarkTop = kAtlasHeight;
constexpr unsigned kMarkW = kGlyphW;                     // celda ancha de una marca
constexpr unsigned kMarkH = hh::kMenuGlyphH;             // 12
constexpr unsigned kMarkCols = kAtlasWidth / kMarkW;     // 16
constexpr unsigned kMarkRows = (hh::kMenuMarkCount + kMarkCols - 1) / kMarkCols;
constexpr unsigned kFullHeight = kMarkTop + kMarkRows * kMarkH;

uint8_t g_atlas[kAtlasWidth * kFullHeight * 4];
bool g_ready = false;
bool g_tried = false;

void bake_atlas(const uint8_t* font) {
    for (unsigned v = 0; v < kMaxValue; ++v) {
        const unsigned block = v >> 1;
        const unsigned parity = v & 1u;
        const uint8_t* g = font + block * kBlockStride;
        const unsigned gx = (v % kAtlasCols) * kGlyphW;
        const unsigned gy = (v / kAtlasCols) * kGlyphH;
        for (unsigned y = 0; y < kGlyphH; ++y) {
            for (unsigned x = 0; x < kGlyphW; ++x) {
                const unsigned i = y * kGlyphW + x;   // pixel del glifo (fila a fila)
                const uint8_t byte = g[i >> 1];
                const uint8_t nibble = (i & 1u) ? (byte & 0x0Fu) : ((byte >> 4) & 0x0Fu);
                const unsigned lvl = (parity == 0) ? ((nibble >> 2) & 3u) : (nibble & 3u);
                const unsigned p = ((gy + y) * kAtlasWidth + (gx + x)) * 4;
                // Nivel 1 = glifo principal (texto); nivel >=2 = sombra (copia desplazada abajo-
                // derecha, como en el motor). R=255 -> color de vertice; R=0 -> negro (sombra).
                // A = cobertura (solida).
                g_atlas[p + 0] = (lvl == 1) ? 255u : 0u;    // R = tinta (1) / sombra (>=2)
                g_atlas[p + 1] = 255;                       // G
                g_atlas[p + 2] = 255;                       // B
                g_atlas[p + 3] = (lvl != 0) ? 255u : 0u;    // A = cobertura
            }
        }
    }
    // Marcas del menu (sprites recortados) en la region inferior del atlas.
    for (unsigned m = 0; m < hh::kMenuMarkCount; ++m) {
        const hh::MenuMark& mk = hh::kMenuMarks[m];
        const unsigned cx = (m % kMarkCols) * kMarkW;
        const unsigned cy = kMarkTop + (m / kMarkCols) * kMarkH;
        for (unsigned y = 0; y < mk.h; ++y) {
            for (unsigned x = 0; x < mk.w; ++x) {
                const unsigned lvl = mk.pix[y * mk.w + x];
                if (lvl == 0) continue;
                const unsigned p = ((cy + y) * kAtlasWidth + (cx + x)) * 4;
                g_atlas[p + 0] = (lvl == 1) ? 255u : 0u;
                g_atlas[p + 1] = 255;
                g_atlas[p + 2] = 255;
                g_atlas[p + 3] = 255;
            }
        }
    }
}

}  // namespace

bool init() {
    if (g_ready) return true;
    if (g_tried) return false;
    g_tried = true;

    const std::filesystem::path rom = hh::get_rom_path();
    if (rom.empty()) {
        hh::log("[font] ROM no encontrada; fuente del juego no disponible\n");
        return false;
    }
    std::ifstream f(rom, std::ios::binary);
    if (!f) {
        hh::log("[font] no se pudo abrir la ROM: %s\n", rom.string().c_str());
        return false;
    }
    std::string data(kFontRomSize, '\0');
    f.seekg(kFontRomOffset);
    f.read(data.data(), kFontRomSize);
    if (f.gcount() != static_cast<std::streamsize>(kFontRomSize)) {
        hh::log("[font] ROM corta al leer la fuente color0 (%lld B)\n",
                static_cast<long long>(f.gcount()));
        return false;
    }

    bake_atlas(reinterpret_cast<const uint8_t*>(data.data()));
    g_ready = true;
    hh::log("[font] atlas RGBA8 color0: %ux%u (%u B; letras %ux%u + marcas %ux%u)\n",
            kAtlasWidth, kFullHeight, kAtlasWidth * kFullHeight * 4,
            kAtlasWidth, kAtlasHeight, kAtlasWidth, kMarkRows * kMarkH);
    return true;
}

bool ready() { return g_ready; }
const uint8_t* atlas_rgba8() { return g_atlas; }
unsigned atlas_width() { return kAtlasWidth; }
unsigned atlas_height() { return kFullHeight; }
unsigned char_width() { return kGlyphW; }
unsigned char_height() { return kGlyphH; }

bool glyph_value(unsigned char c, unsigned& value) {
    if (c == ' ') { value = 0; return true; }
    if (c >= '0' && c <= '9') { value = 1u + (c - '0'); return true; }   // '0' -> 1 ... '9' -> 10
    if (c >= 'A' && c <= 'Z') { value = 37u + (c - 'A'); return true; }
    if (c >= 'a' && c <= 'z') { value = 11u + (c - 'a'); return true; }
    return false;
}

bool value_uv(unsigned value, unsigned& x, unsigned& y) {
    if (value >= kMaxValue) return false;
    x = (value % kAtlasCols) * kGlyphW;
    y = (value / kAtlasCols) * kGlyphH;
    return true;
}

bool glyph_uv(unsigned char c, unsigned& x, unsigned& y) {
    unsigned v = 0;
    if (!glyph_value(c, v)) return false;
    return value_uv(v, x, y);
}

bool menu_char(unsigned cp, unsigned& value, int& mark) {
    for (unsigned i = 0; i < hh::kMenuCharCount; ++i) {
        if (hh::kMenuChars[i].cp == cp) {
            value = hh::kMenuChars[i].base_value;
            mark = static_cast<int>(hh::kMenuChars[i].mark);
            return true;
        }
    }
    return false;
}

bool mark_info(int mark, unsigned& x, unsigned& y, unsigned& w, unsigned& h, int& dy) {
    if (mark < 0 || static_cast<unsigned>(mark) >= hh::kMenuMarkCount) return false;
    const hh::MenuMark& mk = hh::kMenuMarks[static_cast<unsigned>(mark)];
    x = (static_cast<unsigned>(mark) % kMarkCols) * kMarkW;
    y = kMarkTop + (static_cast<unsigned>(mark) / kMarkCols) * kMarkH;
    w = mk.w;
    h = mk.h;
    dy = mk.dy;
    return true;
}

int glyph_left_bearing(unsigned char c) {
    unsigned v = 0;
    if (!glyph_value(c, v) || v >= kMaxValue) return -1;
    const unsigned gx = (v % kAtlasCols) * kGlyphW;
    const unsigned gy = (v / kAtlasCols) * kGlyphH;
    for (unsigned x = 0; x < kGlyphW; ++x) {
        for (unsigned y = 0; y < kGlyphH; ++y) {
            const unsigned p = ((gy + y) * kAtlasWidth + (gx + x)) * 4;
            if (g_atlas[p + 0] != 0) {   // R != 0 => tinta del glifo principal (nivel 1)
                return static_cast<int>(x);
            }
        }
    }
    return -1;   // glifo vacio (p. ej. el espacio)
}

}  // namespace hh::font::game
