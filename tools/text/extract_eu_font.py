#!/usr/bin/env python3
"""Extrae la fuente EU (acentos reales) en el formato EXACTO del motor.

Formato verificado (2026-09-25): el fichero de fuente "idioma"/color4 EU esta @`0x8C3298`
(localizado por vecindad del color0 US, byte-identico). Mismo formato que el US:
- 32 B por **par** de valores (`bloque = v >> 1`); paridad `v & 1` elige el plano.
- 8x8, 2bpp, 2 px/byte (nibble). US = 66 valores (2112 B); EU = 114 valores (3648 B).
- Validado: v1 = "1", v2 = "2"; los valores altos (66..113) son los acentos EU.

La tabla `EUC B0xx -> valor` esta en el codigo (`func_8001D394`), no en el fichero.

Uso:
    python3 tools/text/extract_eu_font.py --sheet work/fonts/eu_all.png
    python3 tools/text/extract_eu_font.py --out include/hh/eu_glyphs.h
"""
import argparse
import os
import struct
import zlib

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
US_ROM = os.path.join(REPO, "build", "linux", "baserom.us.z64")
EU_ROM = os.path.join(REPO, "work", "roms", "eu_dec.z64")
US108_OFF = 0x6E4CD6      # color4 "idioma" US (2112 B)
W, H, STRIDE, N_EU = 8, 8, 32, 114


def locate_eu_font(eu, us):
    """Localiza el fichero de fuente 'idioma' EU por el primer bloque del US108."""
    first = us[US108_OFF:US108_OFF + 32]
    j = eu.find(first)
    if j < 0:
        raise SystemExit("No se localiza la fuente EU (¿ROM EU distinta?)")
    return j


def decode(font, v):
    blk = font[(v >> 1) * STRIDE: ((v >> 1) + 1) * STRIDE]
    par = v & 1
    pix = []
    for i in range(W * H):
        b = blk[i >> 1]
        nb = i & 1
        val = (b >> 4) & 0xF if nb == 0 else b & 0xF
        pix.append((val >> 2) & 3 if par == 0 else val & 3)
    return pix


def sheet(path, font, sel, per=16, scale=7):
    rows = (len(sel) + per - 1) // per
    cw, ch = W * scale + 3, H * scale + 11
    Wp, Hp = per * cw + 3, rows * ch + 3
    img = [[255] * Wp for _ in range(Hp)]
    F = {"0": ["111", "101", "101", "101", "111"], "1": ["010", "110", "010", "010", "111"],
         "2": ["111", "001", "111", "100", "111"], "3": ["111", "001", "111", "001", "111"],
         "4": ["101", "101", "111", "001", "001"], "5": ["111", "100", "111", "001", "111"],
         "6": ["111", "100", "111", "101", "111"], "7": ["111", "001", "001", "001", "001"],
         "8": ["111", "101", "111", "101", "111"], "9": ["111", "101", "111", "001", "111"]}
    for i, v in enumerate(sel):
        gx, gy = (i % per) * cw + 3, (i // per) * ch + 3
        x = gx
        for c in str(v):
            for ry, row in enumerate(F.get(c, [])):
                for rx, b in enumerate(row):
                    if b == "1" and gy + ry < Hp and x + rx < Wp:
                        img[gy + ry][x + rx] = 0
            x += 4
        pix = decode(font, v)
        for y in range(H):
            for xx in range(W):
                val = 255 - pix[y * W + xx] * 255 // 3
                for dy in range(scale):
                    for dx in range(scale):
                        if gy + 11 + y * scale + dy < Hp and gx + xx * scale + dx < Wp:
                            img[gy + 11 + y * scale + dy][gx + xx * scale + dx] = val
    raw = b"".join(b"\x00" + bytes(r) for r in img)

    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n"
                           + chunk(b"IHDR", struct.pack(">IIBBBBB", Wp, Hp, 8, 0, 0, 0, 0))
                           + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sheet", help="PNG con los 114 glifos EU etiquetados por valor")
    ap.add_argument("--out", help="header C con los bloques (114 x 32 B)")
    args = ap.parse_args()

    eu = open(EU_ROM, "rb").read()
    us = open(US_ROM, "rb").read()
    base = locate_eu_font(eu, us)
    font = eu[base:base + N_EU * STRIDE]
    print(f"fuente EU @0x{base:X} ({N_EU} valores, {len(font)} B)")

    if args.sheet:
        sheet(args.sheet, font, list(range(N_EU)))
        print("sheet:", args.sheet)

    if args.out:
        with open(args.out, "w") as f:
            f.write("// Generado por tools/text/extract_eu_font.py -- NO editar a mano.\n")
            f.write("#pragma once\n#include <cstdint>\n\n")
            f.write("namespace hh {\n")
            f.write("// Bloques de la fuente EU 'idioma' (114 valores x 32 B, 8x8 2bpp).\n")
            f.write("inline constexpr uint8_t kEuFontBlocks[%d][%d] = {\n" % (N_EU, STRIDE))
            for v in range(N_EU):
                blk = font[(v >> 1) * STRIDE: ((v >> 1) + 1) * STRIDE]
                f.write("    {%s},\n" % ", ".join("0x%02X" % b for b in blk))
            f.write("};\n}  // namespace hh\n")
        print("header:", args.out)


if __name__ == "__main__":
    main()
