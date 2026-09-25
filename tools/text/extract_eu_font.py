#!/usr/bin/env python3
"""Extrae la fuente EU (gaiji acentuados) y su mapeo EUC -> glifo.

Contexto (ver notes/2026-09-23-b-fuente-formato-y-gaiji.md):
- La fuente del juego son 6 ficheros (uno por color/estilo), 2bpp, con DOS glifos 8xH
  empaquetados por bloque (`valor par` -> bits 2-3 de cada nibble, `impar` -> bits 0-1).
- El fichero **color4** es el que lleva los acentos en la edicion PAL (EU): 48 B/bloque (8x12),
  **76 glifos** (US: 44). Es el unico que difiere US<->EU.
- Los offsets del manifiesto EU (`notes/eu_manifest.yaml`) para los ficheros de fuente estan
  **desfasados**: los ficheros reales se localizan por VECINDAD en el residente, junto al color0
  (byte-identico al US). Aqui se localizan por busqueda del color0 US y el hueco de color4.
- El motor EU mapea los codigos EUC `B0A1..B0C7` a slots `0x56..0x7C` (tabla de gaiji en
  `eu_dec.z64` @`0x1EA30`). El estilo/color4 de esos slots son los acentos reales.

Uso:
    python3 tools/text/extract_eu_font.py --preview work/fonts/eu_gaiji.png
    python3 tools/text/extract_eu_font.py --out include/hh/eu_glyphs.h
"""
import argparse
import os
import re
import struct
import zlib

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
US_ROM = os.path.join(REPO, "build", "linux", "baserom.us.z64")
EU_ROM = os.path.join(REPO, "work", "roms", "eu_dec.z64")
US_MANIFEST = os.path.join(REPO, "notes", "us_manifest.yaml")

# OJO: el dump runtime del motor muestra stride=32 (8x8, 32 B/glifo) para el estilo del menu, no 48.
# Este stride/altura queda como provisional hasta fijarlo con el oraculo del emulador (ROM EU).
W, H, STRIDE = 8, 12, 48   # PROVISIONAL (ver notes/2026-09-25-c-font-eu-color4-localizada.md)
N_US, N_EU = 44, 76
US_COLOR0_IDX = 107        # color0 US (byte-identico al EU) -> ancla de la vecindad
US_COLOR0_SIZE = 4096
EU_COLOR4_SIZE = 3648      # = N_EU * STRIDE / 2

# Tabla de gaiji EU en la ROM: entradas de 8 B `34 01 <EUC_BE> <props> <...> <slot_hi> <slot_lo>`.
EU_GAIJI_OFF = 0x1EA30


def _us_offset(idx):
    txt = open(US_MANIFEST).read()
    m = re.search(rf"- index: {idx}\n  compressed: \w+\n  original_offset: '(0x[0-9A-Fa-f]+)'", txt)
    return int(m.group(1), 16)


def locate_eu_color0(eu):
    """Offset del color0 EU: byte-identico al color0 US."""
    us = open(US_ROM, "rb").read()
    color0 = us[_us_offset(US_COLOR0_IDX):_us_offset(US_COLOR0_IDX) + US_COLOR0_SIZE]
    off = eu.find(color0)
    if off < 0:
        raise SystemExit("color0 EU no encontrado (¿ROM EU distinta?)")
    return off


def locate_eu_color4(eu):
    """color4 EU: justo tras el color0 EU (hueco de 3648 B), verificado por tamano."""
    c0 = locate_eu_color0(eu)
    cand = c0 + US_COLOR0_SIZE
    if eu[cand:cand + EU_COLOR4_SIZE] == b"\x00" * EU_COLOR4_SIZE:
        # Buscar el siguiente fichero de fuente (color1) para medir el hueco.
        pass
    return cand


# Sin desplazamiento. (Se probó un shift de 16 px asumiendo 48 B/12 filas; DESCARTADO: el motor
# usa stride=32 segun el dump runtime. El layout EU definitivo se fija con el oraculo del emulador.)
EU_SHIFT_PX = 0


def decode_glyph(data, value, w=W, h=H, shift=EU_SHIFT_PX):
    block = data[(value >> 1) * STRIDE:(value >> 1) * STRIDE + STRIDE]
    parity = value & 1
    pix = []
    for i in range(w * h):
        byte = block[i >> 1]
        nib = i & 1
        val = (byte >> 4) & 0xF if nib == 0 else byte & 0xF
        pix.append((val >> 2) & 3 if parity == 0 else val & 3)
    if shift:
        pix = pix[shift:] + [0] * shift
    return pix


def eu_gaiji_map(eu):
    """EUC (B0xx) -> slot del gaiji, de la tabla de la ROM EU."""
    m = {}
    off = EU_GAIJI_OFF
    for k in range(128):
        e = eu[off + k * 8:off + k * 8 + 8]
        if len(e) < 8:
            break
        props = e[4]
        code = (e[2] << 8) | e[3]
        slot = (e[6] << 8) | e[7]
        if props == 0x24 and 0xB000 <= code <= 0xB0FF:
            m[code] = slot
    return m


def png(path, glyphs, labels, percol=10, scale=11):
    cw, ch = W * scale, H * scale + 10
    rows = (len(glyphs) + percol - 1) // percol
    Wp, Hp = percol * (cw + 4) + 4, rows * (ch + 4) + 4
    img = [[255] * Wp for _ in range(Hp)]
    F = {
        "0": ["111", "101", "101", "101", "111"], "1": ["010", "110", "010", "010", "111"],
        "2": ["111", "001", "111", "100", "111"], "3": ["111", "001", "111", "001", "111"],
        "4": ["101", "101", "111", "001", "001"], "5": ["111", "100", "111", "001", "111"],
        "6": ["111", "100", "111", "101", "111"], "7": ["111", "001", "001", "001", "001"],
        "8": ["111", "101", "111", "101", "111"], "9": ["111", "101", "111", "001", "111"],
    }
    for i, (pix, lab) in enumerate(zip(glyphs, labels)):
        gx = (i % percol) * (cw + 4) + 4
        gy = (i // percol) * (ch + 4) + 4
        x = gx
        for c in lab:
            for ry, row in enumerate(F.get(c, [])):
                for rx, b in enumerate(row):
                    if b == "1" and gy + ry < Hp and x + rx < Wp:
                        img[gy + ry][x + rx] = 0
            x += 4
        for y in range(H):
            for xx in range(W):
                val = max(0, 255 - (pix[y * W + xx] * 255 // 3))
                for dy in range(scale):
                    for dx in range(scale):
                        if gy + 10 + y * scale + dy < Hp and gx + xx * scale + dx < Wp:
                            img[gy + 10 + y * scale + dy][gx + xx * scale + dx] = val
    raw = b"".join(b"\x00" + bytes(r) for r in img)

    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n"
                           + chunk(b"IHDR", struct.pack(">IIBBBBB", Wp, Hp, 8, 0, 0, 0, 0))
                           + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--preview")
    ap.add_argument("--out", default=os.path.join(REPO, "include", "hh", "eu_glyphs.h"))
    args = ap.parse_args()

    eu = open(EU_ROM, "rb").read()
    c4 = locate_eu_color4(eu)
    font = eu[c4:c4 + EU_COLOR4_SIZE]
    print(f"color4 EU @0x{c4:X} ({len(font)} B, {N_EU} glifos)")

    gaiji = eu_gaiji_map(eu)
    print(f"mapeo gaiji EU: {len(gaiji)} codigos B0xx -> slot")

    if args.preview:
        glyphs = [decode_glyph(font, v) for v in range(N_EU)]
        labels = [str(v) for v in range(N_EU)]
        png(args.preview, glyphs, labels)
        print("preview:", args.preview)

    # Header: EUC (B0xx) -> bloque (bytes) + valores; por ahora solo los gaiji mapeados.
    with open(args.out, "w") as f:
        f.write("// Generado por tools/text/extract_eu_font.py -- NO editar a mano.\n")
        f.write("#pragma once\n#include <cstdint>\n\n")
        f.write("namespace hh {\n")
        f.write("struct EuGlyph { uint16_t euc; uint16_t slot; uint8_t block[48]; };\n")
        f.write("inline constexpr EuGlyph kEuGlyphs[] = {\n")
        for code in sorted(gaiji):
            slot = gaiji[code]
            block = font[(slot >> 1) * STRIDE:(slot >> 1) * STRIDE + STRIDE]
            f.write("    {0x%04X, %d, {%s}},\n"
                    % (code, slot, ", ".join("0x%02X" % b for b in block)))
        f.write("};\n")
        f.write("inline constexpr unsigned kEuGlyphCount = sizeof(kEuGlyphs)/sizeof(kEuGlyphs[0]);\n")
        f.write("inline constexpr unsigned kEuGlyphStride = 48;\n")
        f.write("}  // namespace hh\n")
    print("header:", args.out)


if __name__ == "__main__":
    main()
