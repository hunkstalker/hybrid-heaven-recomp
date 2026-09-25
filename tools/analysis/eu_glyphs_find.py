#!/usr/bin/env python3
"""Analiza volcanes de RDRAM de la ROM EU (BizHawk) para fijar el buffer de glifos del motor.

Hallazgo (2026-09-25, sesion de captura con BizHawk): el motor de texto EU compone los glifos en la
textura de trabajo cerca de **`0x80109B60`** (8x8, 2bpp despaquetado; coincide en tamano/posicion con
la zona que cambia al cambiar el texto del menu). El texto de menu cambia entre frames/idiomas.

Entrada: carpeta con `eu_rdram_*.bin` (8 MB c/u) de `tools/analysis/bizhawk_eu_glyph_capture.lua`.

Uso:
    python3 tools/analysis/eu_glyphs_find.py work/eu_glyphs/ --buf 0x80109B60 --render
    python3 tools/analysis/eu_glyphs_find.py work/eu_glyphs/ --scan   # busca la ventana que cambia
"""
import argparse
import glob
import os
import struct
import zlib

RDRAM_SIZE = 0x800000
DEF_BUF = 0x80109B60     # textura de trabajo de glifos del menu EU (medida)


def load(path):
    d = open(path, "rb").read()
    if len(d) != RDRAM_SIZE:
        raise SystemExit(f"{path}: tamano {len(d)} != 8 MB")
    return d


def render_2bpp(d, addr, nglyph, bytes_per_glyph=16):
    """Dibuja glifos 8x8 2bpp despaquetados (1 byte = 4 px, MSB-first) desde `addr`."""
    off = addr - 0x80000000
    out = []
    for g in range(nglyph):
        blk = d[off + g * bytes_per_glyph: off + (g + 1) * bytes_per_glyph]
        rows = []
        for y in range(8):
            line = ""
            for x in range(8):
                b = blk[y * 2 + (x // 4)] if (y * 2 + x // 4) < len(blk) else 0
                v = (b >> (6 - 2 * (x % 4))) & 3
                line += " .:#"[v]
            rows.append(line)
        out.append(rows)
    return out


def png(path, tiles, percol=16, scale=6):
    W = H = 8
    cw, ch = W * scale + 2, H * scale + 2
    rows = (len(tiles) + percol - 1) // percol
    Wp, Hp = percol * cw + 2, rows * ch + 2
    img = [[255] * Wp for _ in range(Hp)]
    for i, pix in enumerate(tiles):
        gx = (i % percol) * cw + 2
        gy = (i // percol) * ch + 2
        for y in range(H):
            for x in range(W):
                val = 255 - (pix[y][x] != " ") * 0  # placeholder
        # pix es filas de caracteres; convertir
        for y in range(H):
            for x in range(W):
                v = " .:#".index(pix[y][x]) if pix[y][x] in " .:#" else 0
                val = 255 - v * 255 // 3
                for dy in range(scale):
                    for dx in range(scale):
                        if gy + y * scale + dy < Hp and gx + x * scale + dx < Wp:
                            img[gy + y * scale + dy][gx + x * scale + dx] = val
    raw = b"".join(b"\x00" + bytes(r) for r in img)

    def chunk(t, dd):
        return struct.pack(">I", len(dd)) + t + dd + struct.pack(">I", zlib.crc32(t + dd) & 0xFFFFFFFF)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n"
                           + chunk(b"IHDR", struct.pack(">IIBBBBB", Wp, Hp, 8, 0, 0, 0, 0))
                           + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


def scan(files):
    data = [load(f) for f in files]
    a, z = data[0], data[-1]
    WIN = 0x1000
    best = []
    for base in range(0, RDRAM_SIZE - WIN, WIN):
        diff = sum(1 for i in range(0, WIN, 4) if a[base + i] != z[base + i])
        best.append((diff, base))
    best.sort(reverse=True)
    print("ventanas mas cambiantes (frame0 vs ultimo):")
    for diff, base in best[:15]:
        print(f"  0x{base + 0x80000000:08X} diff={diff}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dir")
    ap.add_argument("--buf", type=lambda x: int(x, 0), default=DEF_BUF)
    ap.add_argument("--render", action="store_true", help="renderiza el buffer a PNG")
    ap.add_argument("--scan", action="store_true", help="busca la ventana que cambia")
    ap.add_argument("--frame", type=int, default=-1, help="indice de volcan (por defecto el ultimo)")
    args = ap.parse_args()

    files = sorted(glob.glob(os.path.join(args.dir, "eu_rdram_*.bin")))
    if not files:
        raise SystemExit("No hay eu_rdram_*.bin en " + args.dir)

    if args.scan:
        scan(files)
        return

    d = load(files[args.frame])
    tiles = render_2bpp(d, args.buf, 64)
    if args.render:
        out = os.path.join(args.dir, f"buf_{args.buf:08X}.png")
        png(out, tiles)
        print("render:", out)
    else:
        for i, rows in enumerate(tiles):
            if any(r.strip() for r in rows):
                print(f"--- glyph {i} ---")
                for r in rows:
                    print(r)


if __name__ == "__main__":
    main()
