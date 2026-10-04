#!/usr/bin/env python3
"""Decodifica un volcado de texturas de RT64 (HH_TEXDUMP / Inspector) a PNG.

RT64 escribe, por cada textura: <hash>.vN.tmem, <hash>.vN.tile.json (formato/dimensiones),
<hash>.vN.rice.rdram (+ .rice.json) y, si es CI, <hash>.vN.rice.palette.rdram.
Este script lee el `.tile.json` (fmt/siz/line/width/height/tlut) y el `.rice.rdram`, y escribe un
PNG RGBA8 por textura. Sirve para localizar/extraer assets (p. ej. los logos de la intro).

Formatos soportados:
  fmt=0 (RGBA): siz=2 -> RGBA16 (5551), siz=3 -> RGBA32
  fmt=2 (CI):   siz=0 -> CI4, siz=1 -> CI8   (usa .rice.palette.rdram, RGBA16)
  fmt=3 (IA):   siz=1 -> IA8 (usado por muchos sprites)

Uso:
  python3 tools/analysis/decode_texdump.py <dir> [--out <dir>] [--only <hash>] [--upscale N]
"""

import argparse
import glob
import json
import os
import struct
import sys
import zlib

try:
    import numpy as np
except ImportError:
    np = None


G_TT_RGBA16, G_TT_IA16 = 2, 0
G_IM_FMT_RGBA, G_IM_FMT_CI, G_IM_FMT_IA, G_IM_FMT_I = 0, 2, 3, 4
G_IM_SIZ_4b, G_IM_SIZ_8b, G_IM_SIZ_16b, G_IM_SIZ_32b = 0, 1, 2, 3


def write_png(path, w, h, rgba):
    raw = bytearray()
    for y in range(h):
        raw.append(0)
        raw += bytes(rgba[y * w * 4:(y + 1) * w * 4])

    def chunk(typ, data):
        return struct.pack('>I', len(data)) + typ + data + struct.pack('>I', zlib.crc32(typ + data) & 0xffffffff)

    ihdr = struct.pack('>IIBBBBB', w, h, 8, 6, 0, 0, 0)
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', ihdr) + chunk(b'IDAT', zlib.compress(bytes(raw), 9)) + chunk(b'IEND', b''))


def rgba5551(v):
    r = ((v >> 11) & 0x1F) << 3
    g = ((v >> 6) & 0x1F) << 3
    b = (v & 0x1F) << 3
    return (r | r >> 5, g | g >> 5, b | b >> 5, 255)


def decode(tile, data, w, h, pal):
    fmt, siz, line = tile['fmt'], tile['siz'], tile['line']
    bpr = max(line * 8, 1)
    px = bytearray(w * h * 4)
    idx = 0
    for y in range(h):
        row = data[y * bpr:(y + 1) * bpr]
        for x in range(w):
            if fmt == G_IM_FMT_RGBA and siz == G_IM_SIZ_16b:
                o = x * 2
                v = struct.unpack('>H', row[o:o + 2])[0] if o + 2 <= len(row) else 0
                c = rgba5551(v)
            elif fmt == G_IM_FMT_RGBA and siz == G_IM_SIZ_32b:
                o = x * 4
                c = struct.unpack('>4B', row[o:o + 4]) if o + 4 <= len(row) else (0, 0, 0, 0)
            elif fmt == G_IM_FMT_IA and siz == G_IM_SIZ_16b:
                o = x * 2
                v = struct.unpack('>H', row[o:o + 2])[0] if o + 2 <= len(row) else 0
                i = (v >> 8) & 0xFF
                a = v & 0xFF
                c = (i, i, i, a)
            elif fmt == G_IM_FMT_IA and siz == G_IM_SIZ_8b:
                o = x
                b = row[o] if o < len(row) else 0
                i = (b >> 4) & 0xF
                a = b & 0xF
                i = i << 4 | i
                a = a << 4 | a
                c = (i, i, i, a)
            elif fmt == G_IM_FMT_CI:
                ci = 0
                if siz == G_IM_SIZ_4b:
                    o = x // 2
                    b = row[o] if o < len(row) else 0
                    ci = (b >> 4) if x % 2 == 0 else (b & 0xF)
                elif siz == G_IM_SIZ_8b:
                    o = x
                    ci = row[o] if o < len(row) else 0
                c = pal[ci] if ci < len(pal) else (255, 0, 255, 255)
            else:
                c = (255, 0, 0, 255)
            px[idx:idx + 4] = bytes(c)
            idx += 4
    return px


def upscale(rgba, w, h, s):
    out = bytearray(w * s * h * s * 4)
    W = w * s
    for y in range(h * s):
        for x in range(W):
            si = (x // s) + (y // s) * w
            o = (x + y * W) * 4
            out[o:o + 4] = rgba[si * 4:si * 4 + 4]
    return W, h * s, out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('dir')
    ap.add_argument('--out', default=None)
    ap.add_argument('--only', default=None, help='subcadena del hash')
    ap.add_argument('--upscale', type=int, default=1)
    args = ap.parse_args()

    outdir = args.out or os.path.join(args.dir, 'png')
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for tj in sorted(glob.glob(os.path.join(args.dir, '*.tile.json'))):
        base = tj[:-len('.tile.json')]
        h = os.path.basename(base).split('.')[0]
        if args.only and args.only not in h:
            continue
        t = json.load(open(tj))
        w, hh = t['width'], t['height']
        rd = base + '.rice.rdram'
        if not os.path.exists(rd):
            continue
        data = open(rd, 'rb').read()
        pal = []
        palp = base + '.rice.palette.rdram'
        if os.path.exists(palp):
            pd = open(palp, 'rb').read()
            pal = [rgba5551(struct.unpack('>H', pd[i:i + 2])[0]) for i in range(0, min(len(pd), 512), 2)]
        px = decode(t['tile'], data, w, hh, pal)
        if args.upscale > 1:
            W, H, px = upscale(px, w, hh, args.upscale)
        else:
            W, H = w, hh
        write_png(os.path.join(outdir, h + '.png'), W, H, px)
        n += 1
    print(f"decodificadas {n} texturas -> {outdir}")


if __name__ == '__main__':
    main()
