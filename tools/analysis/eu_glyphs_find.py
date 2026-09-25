#!/usr/bin/env python3
"""Localiza el buffer de glifos en volcanes de RDRAM de la ROM EU (BizHawk) y prueba layouts.

Entrada: carpeta con `eu_rdram_*.bin` (8 MB c/u) producidos por
`tools/analysis/bizhawk_eu_glyphs_dump.lua`.

Heuristica: el buffer de glifos del motor es una zona de RDRAM pequena que CAMBIA cuando cambia el
texto en pantalla. Se busca la ventana de `WIN` bytes con mas variacion entre volcanes y se prueba a
decodificar glifos 2bpp (con/sin paridad, 8x8 y 8x12) para inspeccion visual.

Uso:
    python3 tools/analysis/eu_glyphs_find.py work/eu_glyphs/
"""
import argparse
import glob
import os
import struct
import zlib

RDRAM_SIZE = 0x800000
WIN = 0x200          # ventana a analizar (buffer de glifos + margen)
STEP = 0x10          # granularidad del barrido


def load(path):
    d = open(path, "rb").read()
    if len(d) != RDRAM_SIZE:
        raise SystemExit(f"{path}: tamano {len(d)} != 8 MB (¿word-swapped/otro dominio?)")
    return d


def diff_score(a, b):
    # nº de bytes distintos
    return sum(1 for x, y in zip(a, b) if x != y)


def find_changing_window(files):
    a = load(files[0])
    b = load(files[1])
    best = (0, -1)
    for base in range(0, RDRAM_SIZE - WIN, STEP):
        # submuestreo para ir rapido (1 de cada 4 bytes)
        s = 0
        for i in range(0, WIN, 4):
            if a[base + i] != b[base + i]:
                s += 1
        if s > best[1]:
            best = (base, s)
    return best


def decode_2bpp(buf, v, w, h, stride, parity_mode):
    block = buf[(v >> 1) * stride:(v >> 1) * stride + stride]
    parity = v & 1
    pix = []
    for i in range(w * h):
        byte = block[i >> 1]
        nib = i & 1
        val = (byte >> 4) & 0xF if nib == 0 else byte & 0xF
        if parity_mode == "hi":
            pix.append((val >> 2) & 3 if parity == 0 else val & 3)
        else:
            pix.append(val & 3)
    return pix


def show(pix, w, h):
    out = []
    for y in range(h):
        out.append("".join(" .:#"[pix[y * w + x]] for x in range(w)))
    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dir")
    ap.add_argument("--window", type=lambda x: int(x, 0), default=WIN)
    ap.add_argument("--perpix", type=int, default=10)
    args = ap.parse_args()

    files = sorted(glob.glob(os.path.join(args.dir, "eu_rdram_*.bin")))
    if len(files) < 2:
        raise SystemExit("Necesito >=2 volcanes eu_rdram_*.bin en " + args.dir)
    print(f"{len(files)} volcanes")

    base, score = find_changing_window(files)
    print(f"ventana mas cambiante: 0x{base:08X} (0x{base + 0x80000000:08X} vaddr), score={score}")
    print("volcado hex de la ventana (primer volcan):")
    a = load(files[0])
    for off in range(0, min(args.window, 0x100), 16):
        row = a[base + off:base + off + 16]
        print(f"  0x{base + off:08X}: {row.hex(' ')}")

    # Probar layouts sobre la ventana (asumiendo que empieza en un glifo).
    for w, h, stride in [(8, 8, 32), (8, 12, 48), (8, 8, 16), (8, 12, 24)]:
        for pm in ["hi", "lo"]:
            print(f"\n=== layout {w}x{h} stride={stride} paridad={pm} (valores 0..7) ===")
            try:
                for v in range(8):
                    pix = decode_2bpp(a[base:base + args.window], v, w, h, stride, pm)
                    print(f"--- v{v} ---")
                    print(show(pix, w, h))
            except Exception as e:  # noqa
                print("  fallo:", e)


if __name__ == "__main__":
    main()
