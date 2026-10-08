// hh_font — backend_game (A2 Fase A): fuente del juego -> atlas RGBA8 host (sin GBI).
// Ver include/hh/font.h y notes/2026-09-23-b-fuente-formato-y-gaiji.md.

#include "hh.h"
#include "hh/font.h"
#include "hh/game_font_color4.h"
#include "hh/jp_kana.h"
#include "hh/menu_marks.h"

#include <cstdint>
#include <fstream>
#include <string>

namespace hh::font::game {
namespace {

// Fichero color0 de la fuente (Nisitenma idx 107) en la ROM US: offset y tamaño del manifiesto.
constexpr uint32_t kFontRomOffset = 0x6E3CD6;
constexpr uint32_t kFontRomSize = 4096;

constexpr unsigned kGlyphW = 8;
constexpr unsigned kGlyphH = 8;
constexpr unsigned kBlockStride = 32;   // dos glifos 8x8 2bpp por bloque
// Valores 0..255: 0..63 = latino (espacio/digitos/letras) y 64..255 = simbolos, KANA y kanji (el
// ROM JP y el US comparten este fichero color0; la kana esta tambien en el US). Ver jp_kana.h.
constexpr unsigned kMaxValue = 256;
constexpr unsigned kAtlasCols = 16;
constexpr unsigned kAtlasWidth = kAtlasCols * kGlyphW;                 // 128
constexpr unsigned kAtlasHeight = (kMaxValue / kAtlasCols) * kGlyphH;  // 128 (256 glifos)

// Region de MARCAS (menu): sprites recortados, celda 8x12, debajo de las letras.
constexpr unsigned kMarkTop = kAtlasHeight;
constexpr unsigned kMarkW = kGlyphW;                     // celda ancha de una marca
constexpr unsigned kMarkH = hh::kMenuGlyphH;             // 12
constexpr unsigned kMarkCols = kAtlasWidth / kMarkW;     // 16
constexpr unsigned kMarkRows = (hh::kMenuMarkCount + kMarkCols - 1) / kMarkCols;
constexpr unsigned kColor4Top = kMarkTop + kMarkRows * kMarkH;

// --- Fuente color4 (Nisitenma US idx 108, 8x12, stride 48): texto in-game y mensaje del DATA LOAD ---
constexpr uint32_t kColor4RomOffset = 0x6E4CD6;
constexpr uint32_t kColor4RomSize = 2112;
constexpr unsigned kColor4W = 8;
constexpr unsigned kColor4H = 12;
constexpr unsigned kColor4Stride = 48;
// 0..87: 0..63 ASCII (espacio/digitos/letras) + 64..87 puntuacion (., :, ?, !, ...) que la fuente SI
// tiene; el mapeo ASCII->valor medido del motor se aplica en `face_glyph_uv`/`color4_punct_value`.
constexpr unsigned kColor4Values = 88;
// Filas de la banda color4: 6 x 16 = 96 celdas (88 ASCII/puntuacion).
constexpr unsigned kColor4Rows = (kColor4Values + kAtlasCols - 1) / kAtlasCols;   // 6
// Los acentos latin-1 (0x80..0xFF = 128) NO caben en la banda color4. Se cocinan en una franja
// APARTE (8x12) tras ella, con las mismas dimensiones de celda; se buscan por codepoint, no por la
// formula `value = ...` de la parte mapeada.
constexpr unsigned kAccentTop = kColor4Top + kColor4Rows * kColor4H;
constexpr unsigned kAccentCols = kAtlasWidth / kColor4W;   // 16
constexpr unsigned kAccentCells = 128;                     // 0x80..0xFF
constexpr unsigned kAccentRows = (kAccentCells + kAccentCols - 1) / kAccentCols;

// --- Fuente color3 (Nisitenma US idx 106, 12x13, stride 78): titulo grande ("DATA LOAD") ---
constexpr uint32_t kColor3RomOffset = 0x6E1C86;
constexpr uint32_t kColor3RomSize = 8272;
constexpr unsigned kColor3W = 12;
constexpr unsigned kColor3H = 13;
constexpr unsigned kColor3Stride = 78;
// Celdas: 0 = espacio, 1..26 = 'A'..'Z'. El valor del motor es 'A'=0x76 (valor = 0x76 + (c-'A')).
// 12 px de ancho: caben 10 por fila (120 <= 128 del atlas).
constexpr unsigned kColor3Cells = 27;
constexpr unsigned kColor3Cols = kAtlasWidth / kColor3W;   // 10
constexpr unsigned kColor3Rows = (kColor3Cells + kColor3Cols - 1) / kColor3Cols;
constexpr unsigned kColor3Top = kAccentTop + kAccentRows * kColor4H;

// --- Fuente color1 (Nisitenma US idx 109, 10x10, stride 50): kana "grande" para el titulo JA ---
// Igual que color0, su fichero es byte-identico US<->JP y el port lo LEE DE LA ROM en runtime (no se
// guarda ningun asset). Mismo mapeo ASCII (glyph_value) y kana (jp_kana_value) que color0.
// 0..255 valores; 12 columnas (120 <= 128 del atlas) -> 22 filas.
constexpr uint32_t kColor1RomOffset = 0x6E5516;
constexpr uint32_t kColor1RomSize = 8000;
constexpr unsigned kColor1W = 10;
constexpr unsigned kColor1H = 10;
constexpr unsigned kColor1Stride = 50;
constexpr unsigned kColor1Values = 256;
constexpr unsigned kColor1Cols = kAtlasWidth / kColor1W;   // 12
constexpr unsigned kColor1Rows = (kColor1Values + kColor1Cols - 1) / kColor1Cols;
constexpr unsigned kColor1Top = kColor3Top + kColor3Rows * kColor3H;

// --- Banda de EXTRAS (> U+00FF, color4 8x12): œ/Œ/Ÿ (FR), ł/Ł/ś/Ś (PL)… generados en `kGameGlyphs`.
// Va al FINAL del atlas para NO desplazar ninguna banda existente (color0/marcas/color4/accentos/
// color3/color1 quedan idénticas). Se reservan `kExtraCells` celdas (2 filas = 32) para dejar huecos
// REALES a glifos futuros; se sirven por CODEPOINT (`face_glyph_cp_uv`), no por `cp-0x80` (no caben
// en 1 byte). Ver §7 de docs/fonts.md.
constexpr unsigned kExtraTop = kColor1Top + kColor1Rows * kColor1H;
constexpr unsigned kExtraCols = kAtlasWidth / kColor4W;    // 16
constexpr unsigned kExtraRows = 2;                         // capacidad reservada
constexpr unsigned kExtraCells = kExtraCols * kExtraRows;  // 32

constexpr unsigned kFullHeight = kExtraTop + kExtraRows * kColor4H;

uint8_t g_atlas[kAtlasWidth * kFullHeight * 4];
bool g_ready = false;
bool g_tried = false;

// Decodifica y pinta una fuente generica (formato motor 2bpp, DOS glifos por bloque, `stride` bytes).
// `values[i]` = valor de glifo del motor para la celda i del atlas (fila a fila). `keep_shadow`:
// conserva el nivel >=2 (sombra del propio fichero); false para fuentes sin sombra fiable.
void bake_face(const uint8_t* font, uint32_t stride, unsigned w, unsigned h, const unsigned* values,
               unsigned count, unsigned cols, unsigned top, bool keep_shadow) {
    for (unsigned i = 0; i < count; ++i) {
        const unsigned v = values[i];
        const unsigned block_num = v >> 1;
        const unsigned parity = v & 1u;
        const uint8_t* g = font + block_num * stride;
        const unsigned gx = (i % cols) * w;
        const unsigned gy = top + (i / cols) * h;
        for (unsigned y = 0; y < h; ++y) {
            for (unsigned x = 0; x < w; ++x) {
                const unsigned pi = y * w + x;
                const uint8_t byte = g[pi >> 1];
                const uint8_t nibble = (pi & 1u) ? (byte & 0x0Fu) : ((byte >> 4) & 0x0Fu);
                unsigned lvl = (parity == 0) ? ((nibble >> 2) & 3u) : (nibble & 3u);
                if (lvl >= 2 && !keep_shadow) lvl = 0;
                const unsigned p = ((gy + y) * kAtlasWidth + (gx + x)) * 4;
                // R = luminancia del pixel (el PS hace lerp de NEGRO al color del texto con R/255):
                //   nivel 1 = tinta (color pleno); nivel 2 = gris (sombra SUAVE del motor, ~140);
                //   nivel 3 = negro (sombra). El motor NO dibuja el nivel 2 en negro: eso hacia que el
                //   gancho superior de la 'l' (un unico pixel de nivel 2) se viera como un punto negro.
                g_atlas[p + 0] = (lvl == 1) ? 255u : (lvl == 2) ? 140u : 0u;
                g_atlas[p + 1] = 255;
                g_atlas[p + 2] = 255;
                g_atlas[p + 3] = (lvl != 0) ? 255u : 0u;
            }
        }
    }
}

// Hornea un glifo 8x12 de `kGameGlyphs` (color4 ya normalizado) en (gx,gy) del atlas. Mismo
// tratamiento que los acentos Latin-1: nivel 1 = tinta; resto = sombra NEGRA (no gris; ver 2026-10-02).
void bake_game_glyph(const hh::GameGlyph& ag, unsigned gx, unsigned gy) {
    for (unsigned y = 0; y < kColor4H; ++y) {
        for (unsigned x = 0; x < kColor4W; ++x) {
            const unsigned i = y * kColor4W + x;
            const uint8_t byte = ag.block[i >> 1];
            const uint8_t nibble = (i & 1u) ? (byte & 0x0Fu) : ((byte >> 4) & 0x0Fu);
            const unsigned lvl = (nibble >> 2) & 3u;   // valor PAR -> plano 0xCC (ver pack_even)
            const unsigned p = ((gy + y) * kAtlasWidth + (gx + x)) * 4;
            g_atlas[p + 0] = (lvl == 1) ? 255u : 0u;
            g_atlas[p + 1] = 255;
            g_atlas[p + 2] = 255;
            g_atlas[p + 3] = (lvl != 0) ? 255u : 0u;
        }
    }
}

void bake_atlas(const uint8_t* font, const uint8_t* font4, const uint8_t* font3,
                const uint8_t* font1) {
    for (unsigned v = 0; v < kMaxValue; ++v) {
        const unsigned block = v >> 1;
        const unsigned parity = v & 1u;
        const uint8_t* g = font + block * kBlockStride;
        // Niveles del glifo (0..3): 1 = tinta principal; >=2 = sombra (copia +1,+1, como el motor).
        unsigned lvl[kGlyphH][kGlyphW];
        for (unsigned y = 0; y < kGlyphH; ++y) {
            for (unsigned x = 0; x < kGlyphW; ++x) {
                const unsigned i = y * kGlyphW + x;   // pixel del glifo (fila a fila)
                const uint8_t byte = g[i >> 1];
                const uint8_t nibble = (i & 1u) ? (byte & 0x0Fu) : ((byte >> 4) & 0x0Fu);
                lvl[y][x] = (parity == 0) ? ((nibble >> 2) & 3u) : (nibble & 3u);
            }
        }
        // Los valores >=64 (simbolos/kana) **no** traen sombra fiable en la fuente (solo 25 de 192, y a
        // veces parcial), asi que en el atlas se dejan **sin sombra**: la del port se dibuja aparte, en
        // el overlay, como copia negra del glifo +1,+1 (ver `src/platform/overlay.cpp`). Hacerlo en el
        // atlas no vale: la kana con dakuten lleva la "comilla" en la columna 7 y la sombra se
        // recortaria al salir de la celda de 8 px. El latin (0..63) si trae su sombra y no se toca.
        if (v >= 64) {
            for (unsigned y = 0; y < kGlyphH; ++y)
                for (unsigned x = 0; x < kGlyphW; ++x)
                    if (lvl[y][x] >= 2) lvl[y][x] = 0;
        }
        const unsigned gx = (v % kAtlasCols) * kGlyphW;
        const unsigned gy = (v / kAtlasCols) * kGlyphH;
        for (unsigned y = 0; y < kGlyphH; ++y) {
            for (unsigned x = 0; x < kGlyphW; ++x) {
                const unsigned l = lvl[y][x];
                const unsigned p = ((gy + y) * kAtlasWidth + (gx + x)) * 4;
                // R = luminancia (el PS hace lerp de negro al color del texto): nivel 1 = tinta;
                // nivel 2 = gris (sombra suave del motor); nivel 3 = negro (sombra). Ver bake_face.
                g_atlas[p + 0] = (l == 1) ? 255u : (l == 2) ? 140u : 0u;
                g_atlas[p + 1] = 255;                       // G
                g_atlas[p + 2] = 255;                       // B
                g_atlas[p + 3] = (l != 0) ? 255u : 0u;      // A = cobertura
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
    // color4 (texto in-game/mensaje): valores base ASCII 0..63 en orden.
    {
        unsigned vals[kColor4Values];
        for (unsigned v = 0; v < kColor4Values; ++v) vals[v] = v;
        bake_face(font4, kColor4Stride, kColor4W, kColor4H, vals, kColor4Values, kAtlasCols,
                  kColor4Top, /*keep_shadow=*/true);
    }
    // Acentos/`¿`/`¡` (franja `kAccentTop`): la ROM US de color4 solo trae 88 glifos (sin acentos).
    // La MISMA tipografia color4 (8x12) con acentos ya existe en `hh::kGameGlyphs`: glifos REALES de
    // color4 EU + compuestos letra-base-8x12 + marca (`tools/text/build_font.py --style color4`). Aqui
    // se COCINAN por codepoint latin-1 en esta franja, con la celda 8x12 y los mismos niveles
    // (1=tinta, 2=gris, 3=negro) que el resto de color4, para que `face_glyph_uv` los sirva.
    for (unsigned a = 0; a < hh::kGameGlyphCount; ++a) {
        const hh::GameGlyph& ag = hh::kGameGlyphs[a];
        if (ag.cp < 0x80u || ag.cp > 0xFFu) continue;   // solo latin-1 (1 byte)
        const unsigned cell = ag.cp - 0x80u;
        bake_game_glyph(ag, (cell % kAccentCols) * kColor4W,
                        kAccentTop + (cell / kAccentCols) * kColor4H);
    }
    // EXTRAS > U+00FF (œ/Œ/Ÿ, ł/Ł/ś/Ś…): banda APARTE al final del atlas, en el MISMO orden que
    // `face_glyph_cp_uv` (que la sirve). No desplaza ninguna banda previa; deja libres las celdas no
    // usadas de las `kExtraCells` reservadas.
    {
        unsigned cell = 0;
        for (unsigned a = 0; a < hh::kGameGlyphCount && cell < kExtraCells; ++a) {
            const hh::GameGlyph& ag = hh::kGameGlyphs[a];
            if (ag.cp <= 0xFFu) continue;
            bake_game_glyph(ag, (cell % kExtraCols) * kColor4W,
                            kExtraTop + (cell / kExtraCols) * kColor4H);
            ++cell;
        }
    }
    // color3 (titulo): celda 0 = espacio (valor 0), celdas 1..26 = 'A'..'Z' (valor 0x76 + idx).
    {
        unsigned vals[kColor3Cells];
        vals[0] = 0;
        for (unsigned i = 0; i < 26; ++i) vals[1 + i] = 0x76u + i;
        bake_face(font3, kColor3Stride, kColor3W, kColor3H, vals, kColor3Cells, kColor3Cols,
                  kColor3Top, /*keep_shadow=*/true);
    }
    // color1 (kana "grande"): valores 0..255 en orden (ASCII + kana), como color0 pero celda 10x10.
    {
        unsigned vals[kColor1Values];
        for (unsigned v = 0; v < kColor1Values; ++v) vals[v] = v;
        bake_face(font1, kColor1Stride, kColor1W, kColor1H, vals, kColor1Values, kColor1Cols,
                  kColor1Top, /*keep_shadow=*/true);
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
    std::string data4(kColor4RomSize, '\0');
    f.seekg(kColor4RomOffset);
    f.read(data4.data(), kColor4RomSize);
    if (f.gcount() != static_cast<std::streamsize>(kColor4RomSize)) {
        hh::log("[font] ROM corta al leer color4 (%lld B)\n", static_cast<long long>(f.gcount()));
        return false;
    }
    std::string data3(kColor3RomSize, '\0');
    f.seekg(kColor3RomOffset);
    f.read(data3.data(), kColor3RomSize);
    if (f.gcount() != static_cast<std::streamsize>(kColor3RomSize)) {
        hh::log("[font] ROM corta al leer color3 (%lld B)\n", static_cast<long long>(f.gcount()));
        return false;
    }
    std::string data1(kColor1RomSize, '\0');
    f.seekg(kColor1RomOffset);
    f.read(data1.data(), kColor1RomSize);
    if (f.gcount() != static_cast<std::streamsize>(kColor1RomSize)) {
        hh::log("[font] ROM corta al leer color1 (%lld B)\n", static_cast<long long>(f.gcount()));
        return false;
    }

    bake_atlas(reinterpret_cast<const uint8_t*>(data.data()),
               reinterpret_cast<const uint8_t*>(data4.data()),
               reinterpret_cast<const uint8_t*>(data3.data()),
               reinterpret_cast<const uint8_t*>(data1.data()));
    g_ready = true;
    hh::log("[font] atlas RGBA8: %ux%u (%u B; color0 %ux%u + marcas %ux%u + color4 %ux%u + "
            "color3 %ux%u)\n",
            kAtlasWidth, kFullHeight, kAtlasWidth * kFullHeight * 4, kAtlasWidth, kAtlasHeight,
            kAtlasWidth, kMarkRows * kMarkH, kAtlasWidth, kColor4Rows * kColor4H, kAtlasWidth,
            kColor3Rows * kColor3H);
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
    // Puntuacion: valores medidos del propio motor (`func_8001D394`), IDENTICOS en color0 y color4.
    // Los simbolos que la fuente NO trae (comillas, corchetes, llaves, `^ _ \` ~`) devuelven false.
    switch (c) {
        case '!': value = 74; return true;
        case '#': value = 76; return true;
        case '$': value = 77; return true;
        case '%': value = 78; return true;
        case '&': value = 79; return true;
        case '(': value = 81; return true;
        case ')': value = 82; return true;
        case '*': value = 72; return true;
        case '+': value = 71; return true;
        case ',': value = 63; return true;
        case '-': value = 70; return true;
        case '.': value = 64; return true;
        case '/': value = 73; return true;
        case ':': value = 66; return true;
        case ';': value = 65; return true;
        case '<': value = 83; return true;
        case '=': value = 69; return true;
        case '>': value = 84; return true;
        case '?': value = 75; return true;
        case '@': value = 80; return true;
        default: return false;
    }
}

bool value_uv(unsigned value, unsigned& x, unsigned& y) {
    if (value >= kMaxValue) return false;
    x = (value % kAtlasCols) * kGlyphW;
    y = (value / kAtlasCols) * kGlyphH;
    return true;
}

bool face_value_uv(Face f, unsigned value, unsigned& x, unsigned& y) {
    if (f == Face::Color1) {
        if (value >= kColor1Values) return false;
        x = (value % kColor1Cols) * kColor1W;
        y = kColor1Top + (value / kColor1Cols) * kColor1H;
        return true;
    }
    if (f == Face::Color4) {
        if (value >= kColor4Values) return false;
        x = (value % kAtlasCols) * kColor4W;
        y = kColor4Top + (value / kAtlasCols) * kColor4H;
        return true;
    }
    return value_uv(value, x, y);   // Color0 (Color3 usa face_glyph_uv)
}

bool glyph_uv(unsigned char c, unsigned& x, unsigned& y) {
    unsigned v = 0;
    if (!glyph_value(c, v)) return false;
    return value_uv(v, x, y);
}

unsigned face_cell_w(Face f) {
    switch (f) {
        case Face::Color4: return kColor4W;
        case Face::Color3: return kColor3W;
        case Face::Color1: return kColor1W;
        case Face::Color0:
        default: return kGlyphW;
    }
}

unsigned face_cell_h(Face f) {
    switch (f) {
        case Face::Color4: return kColor4H;
        case Face::Color3: return kColor3H;
        case Face::Color1: return kColor1H;
        case Face::Color0:
        default: return kGlyphH;
    }
}

unsigned face_glyph_advance(Face f, unsigned char c) {
    // Avance del motor (`func_8001BD20`). color4 (texto in-game/mensaje) es la unica con correcciones
    // por caracter: el ESPACIO avanza 4 px (medido en la captura pareada: cada espacio del mensaje
    // nativo ocupa 4, no 8) y `f i j l r t` (EUC A3E6/A3E9/A3EA/A3EC/A3F2/A3F4) 6 px. El resto, 8.
    // color0 (8) y color3 (12) avanzan el ancho de celda. Ver docs/fonts.md §6.
    if (f == Face::Color4) {
        // Avances EXACTOS de `func_8001BD20` (tablas jtbl_8004CDF0/jtbl_8004CE2C, base 8 con
        // correcciones): espacio A1A1=-2, ',' A1A4=-2, '.' A1A5=-4, '\'' A1AD=-4, f i j l r t
        // (A3E6/A3E9/A3EA/A3EC/A3F2/A3F4)=-2. El resto, 8.
        switch (c) {
            case ' ': return 6;
            case ',': return 6;
            case '.': return 4;
            case '\'': return 4;
            case 'f': case 'i': case 'j': case 'l': case 'r': case 't': return 6;
            default: return 8;
        }
    }
    return face_cell_w(f);
}

bool face_glyph_uv(Face f, unsigned char c, unsigned& x, unsigned& y) {
    if (f == Face::Color0) {
        return glyph_uv(c, x, y);
    }
    if (f == Face::Color1) {
        unsigned v = 0;
        if (!glyph_value(c, v)) return false;
        return face_value_uv(Face::Color1, v, x, y);
    }
    if (f == Face::Color4) {
        unsigned v = 0;
        if (glyph_value(c, v) && v < kColor4Values) {
            x = (v % kAtlasCols) * kColor4W;
            y = kColor4Top + (v / kAtlasCols) * kColor4H;
            return true;
        }
        // Latin-1 (acentos/¿/¡): franja `kAccentTop` (ver `bake_atlas`).
        if (c >= 0x80u) {
            const unsigned cell = static_cast<unsigned>(c) - 0x80u;
            if (cell >= kAccentCells) return false;
            x = (cell % kAccentCols) * kColor4W;
            y = kAccentTop + (cell / kAccentCols) * kColor4H;
            return true;
        }
        return false;
    }
    // Color3: solo espacio + mayusculas A-Z (el titulo "DATA LOAD").
    unsigned cell = 0;
    if (c == ' ') {
        cell = 0;
    } else if (c >= 'A' && c <= 'Z') {
        cell = 1u + (c - 'A');
    } else {
        return false;
    }
    x = (cell % kColor3Cols) * kColor3W;
    y = kColor3Top + (cell / kColor3Cols) * kColor3H;
    return true;
}

// UV de un glifo color4 por CODEPOINT > U+00FF (banda de extras: œ/Œ/Ÿ, ł/Ł/ś/Ś…). Recorre
// `kGameGlyphs` en el MISMO orden que el horneado (`bake_atlas`). false si el codepoint no esta.
bool face_glyph_cp_uv(unsigned cp, unsigned& x, unsigned& y) {
    unsigned cell = 0;
    for (unsigned a = 0; a < hh::kGameGlyphCount && cell < kExtraCells; ++a) {
        const hh::GameGlyph& ag = hh::kGameGlyphs[a];
        if (ag.cp <= 0xFFu) continue;
        if (ag.cp == cp) {
            x = (cell % kExtraCols) * kColor4W;
            y = kExtraTop + (cell / kExtraCols) * kColor4H;
            return true;
        }
        ++cell;
    }
    return false;
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

bool jp_kana_value(unsigned cp, unsigned& value) {
    for (unsigned i = 0; i < hh::kJpKanaCount; ++i) {
        if (hh::kJpKana[i].cp == cp) {
            value = hh::kJpKana[i].value;
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
