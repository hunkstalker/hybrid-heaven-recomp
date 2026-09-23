#!/usr/bin/env python3
"""Genera glifos acentuados para la fuente 2bpp del motor de texto (B / backend_game).

Formato de la fuente (ver notes/2026-09-23-b-fuente-formato-y-gaiji.md):
- 2 bits por pixel, `W x H`; cada bloque de `stride` bytes contiene DOS glifos empaquetados:
  - valor PAR  -> bits 2-3 de cada nibble (mascara 0xCC)
  - valor IMPAR-> bits 0-1 de cada nibble (mascara 0x33)
- `func_8001BFE4` carga el bloque `stride` bytes en 0x801077E0; `func_8001C0B0` selecciona por el
  bit bajo del valor y compone en la textura de trabajo.

Este util toma la letra base de la fuente US y le añade una marca de acento, generando el bloque de
32 B (color0, 8x8) que se inyecta en runtime. Emite `include/hh/accent_glyphs.h`.

Uso:
    python3 tools/text/gen_accent_glyphs.py                 # escribe el header
    python3 tools/text/gen_accent_glyphs.py --preview work/fonts/accent_preview.png
"""
import argparse
import os
import re
import struct
import zlib

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ROM = "/app/baserom.us.z64"
MANIFEST = os.path.join(REPO, "notes", "us_manifest.yaml")

# color0: 8x8, stride 32 (indice Nisitenma 107)
FONT_IDX = 107
W, H, STRIDE = 8, 8, 32

# Valor del glifo base (según el mapeo EUC->valor del motor; ver la nota).
BASE = {
    "a": 11, "e": 15, "i": 19, "o": 25, "u": 31, "n": 24, "c": 13, "s": 29,
    "A": 37, "E": 41, "I": 45, "O": 51, "U": 57, "N": 50, "C": 39, "S": 55,
    "?": 75, "!": 74,
}

# Marcas de acento en 2bpp (pares (fila, columna)). Ajustables a ojo.
MARKS = {
    "acute":   [(0, 4), (1, 3)],
    "grave":   [(0, 3), (1, 4)],
    "circ":    [(0, 3), (0, 4), (1, 2), (1, 5)],
    "diaer":   [(0, 3), (0, 5)],
    "tilde":   [(0, 3), (0, 4), (1, 4), (1, 5)],
    "cedilla": [(6, 3), (7, 3)],
}

# (codigo EUC propio, codepoint Unicode, letra base, marca)
ACCENTS = [
    (0xB1A1, 0x00E1, "a", "acute"),   # á
    (0xB1A2, 0x00E9, "e", "acute"),   # é
    (0xB1A3, 0x00ED, "i", "acute"),   # í
    (0xB1A4, 0x00F3, "o", "acute"),   # ó
    (0xB1A5, 0x00FA, "u", "acute"),   # ú
    (0xB1A6, 0x00FC, "u", "diaer"),   # ü
    (0xB1A7, 0x00F1, "n", "tilde"),   # ñ
    (0xB1A8, 0x00E7, "c", "cedilla"), # ç
    (0xB1A9, 0x00E0, "a", "grave"),   # à
    (0xB1AA, 0x00E8, "e", "grave"),   # è
    (0xB1AB, 0x00EA, "e", "circ"),    # ê
    (0xB1AC, 0x00E2, "a", "circ"),    # â
    (0xB1AD, 0x00E4, "a", "diaer"),   # ä
    (0xB1AE, 0x00F6, "o", "diaer"),   # ö
    (0xB1AF, 0x00DF, "s", "diaer"),   # ß (provisional: s+diaéresis)
    (0xB1B0, 0x00C1, "A", "acute"),   # Á
    (0xB1B1, 0x00C9, "E", "acute"),   # É
    (0xB1B2, 0x00CD, "I", "acute"),   # Í
    (0xB1B3, 0x00D3, "O", "acute"),   # Ó
    (0xB1B4, 0x00DA, "U", "acute"),   # Ú
    (0xB1B5, 0x00DC, "U", "diaer"),   # Ü
    (0xB1B6, 0x00D1, "N", "tilde"),   # Ñ
    (0xB1B7, 0x00C7, "C", "cedilla"), # Ç
    (0xB1B8, 0x00BF, "?", "none"),    # ¿ (invertida: se voltea)
    (0xB1B9, 0x00A1, "!", "none"),    # ¡ (invertida: se voltea)
]

# Valores propios (pares) en bloques libres (el motor no mapea más allá de ~75).
OUR_VALUE_BASE = 200


def load_font():
    txt = open(MANIFEST).read()
    m = re.search(rf"- index: {FONT_IDX}\n  compressed: \w+\n  original_offset: '(0x[0-9A-Fa-f]+)'", txt)
    off = int(m.group(1), 16)
    rom = open(ROM, "rb").read()
    return rom[off:off + 4096]


def deinterleave(block, parity):
    pix = []
    for b in block:
        for nb in ((b >> 4) & 0xF, b & 0xF):
            pix.append((nb >> 2) & 3 if parity == "even" else nb & 3)
    return pix


def interleave(pix, parity):
    """Empaqueta un glifo 2bpp en el plano indicado; el otro plano queda a 0."""
    out = bytearray(STRIDE)
    for i, v in enumerate(pix):
        byte = i // 2
        nib = i % 2
        if parity == "even":
            out[byte] |= (v & 3) << (4 if nib == 0 else 0) << 2
        else:
            out[byte] |= (v & 3) << (4 if nib == 0 else 0)
    return bytes(out)


def base_glyph(font, val):
    parity = "even" if val % 2 == 0 else "odd"
    return deinterleave(font[(val >> 1) * STRIDE:(val >> 1) * STRIDE + STRIDE], parity)


def compose(font, base, mark):
    pix = base_glyph(font, BASE[base])[:]
    if mark == "flipv":
        pix = [pix[(H - 1 - y) * W + x] for y in range(H) for x in range(W)]
    elif mark in MARKS:
        for (y, x) in MARKS[mark]:
            pix[y * W + x] = 3
    return pix


def png(path, glyphs, labels, percol=8, scale=12):
    pad = 4
    cw, ch = W * scale, H * scale + 10
    rows = (len(glyphs) + percol - 1) // percol
    Wp, Hp = percol * (cw + pad) + pad, rows * (ch + pad) + pad
    img = [[255] * Wp for _ in range(Hp)]
    F = {
        "0": ["111", "101", "101", "101", "111"], "1": ["010", "110", "010", "010", "111"],
        "2": ["111", "001", "111", "100", "111"], "3": ["111", "001", "111", "001", "111"],
        "4": ["101", "101", "111", "001", "001"], "5": ["111", "100", "111", "001", "111"],
        "6": ["111", "100", "111", "101", "111"], "7": ["111", "001", "001", "001", "001"],
        "8": ["111", "101", "111", "101", "111"], "9": ["111", "101", "111", "001", "111"],
    }
    for i, (pix, lab) in enumerate(zip(glyphs, labels)):
        gx = (i % percol) * (cw + pad) + pad
        gy = (i // percol) * (ch + pad) + pad
        for chx, c in enumerate(lab):
            for ry, row in enumerate(F.get(c, [])):
                for rx, b in enumerate(row):
                    if b == "1":
                        img[gy + ry][gx + chx * 4 + rx] = 0
        for y in range(H):
            for x in range(W):
                v = pix[y * W + x]
                val = max(0, 255 - (v * 255 // 3))
                for dy in range(scale):
                    for dx in range(scale):
                        img[gy + 10 + y * scale + dy][gx + x * scale + dx] = val
    raw = b"".join(b"\x00" + bytes(r) for r in img)

    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n"
                           + chunk(b"IHDR", struct.pack(">IIBBBBB", Wp, Hp, 8, 0, 0, 0, 0))
                           + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--preview")
    ap.add_argument("--out", default=os.path.join(REPO, "include", "hh", "accent_glyphs.h"))
    args = ap.parse_args()

    font = load_font()
    glyphs, labels, entries = [], [], []
    for i, (code, cp, base, mark) in enumerate(ACCENTS):
        if mark == "none":
            pix = compose(font, base, "flipv")
        else:
            pix = compose(font, base, mark)
        value = OUR_VALUE_BASE + 2 * i
        block = interleave(pix, "even")
        entries.append((code, value, block))
        glyphs.append(pix)
        labels.append(f"{i:02d}")

    if args.preview:
        png(args.preview, glyphs, labels)
        print("preview:", args.preview)

    with open(args.out, "w") as f:
        f.write("// Generado por tools/text/gen_accent_glyphs.py -- NO editar a mano.\n")
        f.write("#pragma once\n#include <cstdint>\n\n")
        f.write("namespace hh {\n")
        f.write("struct AccentGlyph { uint16_t code; uint32_t cp; uint16_t value; uint8_t block[%d]; };\n"
                % STRIDE)
        f.write("inline constexpr AccentGlyph kAccentGlyphs[] = {\n")
        for (code, cp, _b, _m), (_c, value, block) in zip(ACCENTS, entries):
            f.write("    {0x%04X, 0x%04X, %d, {%s}},\n"
                    % (code, cp, value, ", ".join("0x%02X" % b for b in block)))
        f.write("};\n")
        f.write("inline constexpr unsigned kAccentGlyphCount = sizeof(kAccentGlyphs)/sizeof(kAccentGlyphs[0]);\n")
        f.write("inline constexpr unsigned kAccentStride = %d;\n" % STRIDE)
        f.write("}  // namespace hh\n")
    print("header:", args.out, len(entries), "glifos")


if __name__ == "__main__":
    main()
