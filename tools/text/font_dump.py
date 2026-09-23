#!/usr/bin/env python3
"""Volcado de las fuentes de mapa de bits de Hybrid Heaven (ROM).

El motor de texto del juego no usa una textura unica: carga **un bitmap por glifo**
desde 6 ficheros sin comprimir de la tabla Nisitenma (uno por "color"/estilo). Cada
glifo es un bloque de `stride` bytes; el tamano depende del estilo
(p. ej. estilo 4 = 8x12 px = 48 bytes).

OJO: el formato REAL del motor es **2bpp con DOS glifos empaquetados por bloque**
(valor par -> bits 2-3 de cada nibble, impar -> bits 0-1). Este script los lee como
**4bpp (un glifo por bloque)**, que es una vista comoda: cada celda muestra la **union
de los dos glifos empaquetados**. Sirve de inventario visual, no como referencia de
formato (el decode correcto esta en `src/subsystems/font.cpp`). Ver
`notes/2026-09-23-b-fuente-formato-y-gaiji.md`.

Ficheros de fuente (indices de la tabla Nisitenma):
    US: 106,107,108,109,110,111   (estilos 3,0,4,1,2,5 respectivamente)
    EU: 115,116,117,118,119,120   (mismos tamanos que US, salvo 117: 3648 vs 2112)

`font_dump.py` extrae esos ficheros, los corta en glifos y escribe hojas de contacto
PNG (sin dependencias externas) para inspeccion visual, ademas de diffs US<->EU.

Uso:
    python3 tools/text/font_dump.py --rom /app/baserom.us.z64 --region us --out work/fonts
    python3 tools/text/font_dump.py --rom /app/baserom.eu.z64 --region eu --out work/fonts
    python3 tools/text/font_dump.py --diff --out work/fonts   # compara US y EU

Notas:
- El indice Nisitenma (tabla en ROM 0x39BF0) es solo un listado de offset; el tamano
  se obtiene del manifiesto (`notes/us_manifest.yaml` / `eu_manifest.yaml`).
- En el estilo 4 (8x12) el glifo se dibuja en un margen de 8x12 con 4 bits por pixel.
"""
import argparse
import os
import re
import struct
import zlib

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
MANIFESTS = {
    "us": os.path.join(REPO, "notes", "us_manifest.yaml"),
    "eu": os.path.join(REPO, "notes", "eu_manifest.yaml"),
}
# (indice_nisitenma, ancho, alto) por estilo. El stride se deriva: w*h*bpp/8.
# Orden de estilos segun la tabla `tblB` del binario: color0..5 -> 107,109,110,106,108,111 (US)
FONTS = {
    "us": {
        "color0": (107, 8, 8, 4),
        "color1": (109, 10, 10, 4),
        "color2": (110, 10, 12, 4),
        "color3": (106, 12, 13, 4),
        "color4": (108, 8, 12, 4),
        "color5": (111, 12, 13, 4),
    },
    "eu": {
        "color0": (116, 8, 8, 4),
        "color1": (118, 10, 10, 4),
        "color2": (119, 10, 12, 4),
        "color3": (115, 12, 13, 4),
        "color4": (117, 8, 12, 4),
        "color5": (120, 12, 13, 4),
    },
}
DEFAULT_ROMS = {"us": "/app/baserom.us.z64", "eu": "/app/baserom.eu.z64"}


def load_manifest(region):
    entries = {}
    txt = open(MANIFESTS[region]).read()
    for m in re.finditer(
        r"- index: (\d+)\n  compressed: (\w+)\n  original_offset: '(0x[0-9A-Fa-f]+)'\n"
        r"  original_size: (\d+)\n  decompressed_size: (\d+)",
        txt,
    ):
        entries[int(m.group(1))] = (int(m.group(3), 16), int(m.group(4)))
    return entries


def png(path, W, H, gray):
    raw = b"".join(b"\x00" + bytes(row) for row in gray)

    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)

    data = (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", struct.pack(">IIBBBBB", W, H, 8, 0, 0, 0, 0))
        + chunk(b"IDAT", zlib.compress(raw, 9))
        + chunk(b"IEND", b"")
    )
    with open(path, "wb") as f:
        f.write(data)


def glyph_grid(data, gw, gh, bpp, index):
    rb = (gw * bpp + 7) // 8
    stride = rb * gh
    base = index * stride
    g = []
    for y in range(gh):
        row = 0
        for x in range(rb):
            row = (row << 8) | data[base + y * rb + x]
        bits = rb * 8
        g.append([(row >> (bits - bpp * (x + 1))) & ((1 << bpp) - 1) for x in range(gw)])
    return g


def contact_sheet(data, gw, gh, bpp, percol, scale, out):
    stride = ((gw * bpp + 7) // 8) * gh
    n = len(data) // stride
    rows = (n + percol - 1) // percol
    pad = 3
    W = percol * (gw * scale + pad) + pad
    H = rows * (gh * scale + pad) + pad
    img = [[255] * W for _ in range(H)]
    for i in range(n):
        gx = (i % percol) * (gw * scale + pad) + pad
        gy = (i // percol) * (gh * scale + pad) + pad
        g = glyph_grid(data, gw, gh, bpp, i)
        for y in range(gh):
            for x in range(gw):
                v = g[y][x]
                val = max(0, 255 - (v * 255 // max(1, (1 << bpp) - 1)))
                for dy in range(scale):
                    for dx in range(scale):
                        img[gy + y * scale + dy][gx + x * scale + dx] = val
    png(out, W, H, img)
    return n


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom")
    ap.add_argument("--region", choices=["us", "eu"], default="us")
    ap.add_argument("--out", default="work/fonts")
    ap.add_argument("--scale", type=int, default=6)
    ap.add_argument("--percol", type=int, default=16)
    ap.add_argument("--diff", action="store_true", help="compara ficheros US y EU")
    args = ap.parse_args()

    os.makedirs(args.out, exist_ok=True)
    if args.diff:
        for region in ("us", "eu"):
            rom = open(DEFAULT_ROMS[region], "rb").read()
            man = load_manifest(region)
            for name, (idx, gw, gh, bpp) in FONTS[region].items():
                off, _ = man[idx]
                stride = ((gw * bpp + 7) // 8) * gh
                # tamano real del modulo (hasta el siguiente offset)
                nxt = min(o for i, (o, _) in man.items() if o > off)
                size = nxt - off
                data = rom[off:off + size]
                n = contact_sheet(
                    data, gw, gh, bpp, args.percol, args.scale,
                    os.path.join(args.out, f"font_{region}_{name}_idx{idx}.png"),
                )
                print(f"{region} {name} idx {idx} {gw}x{gh} stride {stride} glifos {n}")
        # diff de tamanos estilo a estilo
        mus, meu = load_manifest("us"), load_manifest("eu")
        print("\nEstilo   US(idx,size)   EU(idx,size)   dif")
        for name in FONTS["us"]:
            iu = FONTS["us"][name][0]
            ie = FONTS["eu"][name][0]
            su = mus[iu][1]
            se = meu[ie][1]
            print(f"{name:7s} {iu:3d},{su:5d}     {ie:3d},{se:5d}     {se - su:+d}")
        return

    rom_path = args.rom or DEFAULT_ROMS[args.region]
    rom = open(rom_path, "rb").read()
    man = load_manifest(args.region)
    for name, (idx, gw, gh, bpp) in FONTS[args.region].items():
        off, _ = man[idx]
        nxt = min(o for i, (o, _) in man.items() if o > off)
        data = rom[off:off + (nxt - off)]
        n = contact_sheet(
            data, gw, gh, bpp, args.percol, args.scale,
            os.path.join(args.out, f"font_{args.region}_{name}_idx{idx}.png"),
        )
        print(f"{args.region} {name} idx {idx} {gw}x{gh} glifos {n}")


if __name__ == "__main__":
    main()
