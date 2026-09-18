#!/usr/bin/env python3
"""Compara dos volcados RDRAM (port vs emulador) en el mismo VI.

Uso:
    python3 tools/analysis/diff_state_at_vi.py <port.bin> <emu.bin> [--blocks N] [--all]

Muestra:
  - Campos clave del CaC/transicion (modulo 24, flags, objeto 0x801FDA70, colas).
  - Directorio de modulos 0x8008DFC0 (ids/bases que difieran).
  - Opcional: resumen de bloques de 4 KB con diferencias.

Convencion de volcado (port y r64dump): palabra guest almacenada byte-revertida; leer u32 LE del
fichero da el valor guest. u16 guest(A) = (>H) en offset (A^2)&0x7FFFFF.
"""
import argparse
import struct
import sys

KEYS = [
    (0x80089478, "flags entrada (bit 0x1000 alto = START edge)"),
    (0x8008DFC4, "dir[0].base"),
    (0x8008DFC8, "dir[1] id/base"),
    (0x801D8CE4, "mod24 tl"),
    (0x801D8CE8, "mod24 g2 (periodo)"),
    (0x801D8DA8, "mod24 cnt30"),
    (0x801D8D00, "mod24 d00"),
    (0x801D8CFC, "mod24 cfc (cambio escena)"),
    (0x801D8D80, "mod24 epoch hi"),
    (0x801D8D84, "mod24 epoch lo"),
    (0x801D8CF0, "mod24 ctr entrada"),
    (0x801FDA70, "obj transicion +0x00"),
    (0x801FDA8C, "obj transicion +0x1C"),
    (0x8024A990, "obj CaC +0x00"),
    (0x8024A9AC, "obj CaC +0x1C (callback)"),
    (0x8005C4B0 + 0x888, "cola tid17 head"),
    (0x8005C4F0, "mq tid5/tid17"),
    (0x8005C268, "mq loader"),
]


def ld(path):
    with open(path, "rb") as f:
        return f.read()


def w32(d, a):
    o = (a - 0x80000000) & 0x7FFFFF
    return struct.unpack("<I", d[o:o + 4])[0]


def h16(d, a):
    o = ((a - 0x80000000) & 0x7FFFFF) ^ 2
    return struct.unpack(">H", d[o:o + 2])[0]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("port")
    ap.add_argument("emu")
    ap.add_argument("--blocks", type=int, default=0, help="N bloques 4KB con mas diferencias")
    args = ap.parse_args()

    a = ld(args.port)
    b = ld(args.emu)
    if len(a) < 0x400000 or len(b) < 0x400000:
        print("aviso: volcados < 4 MB", file=sys.stderr)

    print(f"{'dir':>4} {'addr':>10} {'port':>10} {'emu':>10}  campo")
    for addr, name in KEYS:
        va, vb = w32(a, addr), w32(b, addr)
        mark = "" if va == vb else "   <<< DIFF"
        print(f"{'':>4} 0x{addr:08X} {va:08X} {vb:08X}  {name}{mark}")

    # directorio de modulos: 0x100 entradas {u32 id<<16, u32 base}
    print("\n-- directorio 0x8008DFC0 (solo filas que difieren) --")
    ndiff = 0
    for i in range(0x100):
        addr = 0x8008DFC0 + i * 8
        ia, ib = w32(a, addr), w32(b, addr)
        ba, bb = w32(a, addr + 4), w32(b, addr + 4)
        if ia != ib or ba != bb:
            print(f"  slot{i:03d}: port id={ia >> 16:04X} base={ba:08X} | emu id={ib >> 16:04X} base={bb:08X}")
            ndiff += 1
            if ndiff > 24:
                print("  ...")
                break
    if ndiff == 0:
        print("  (identico)")

    if args.blocks:
        print(f"\n-- bloques 4KB con mas diferencias (top {args.blocks}) --")
        rows = []
        for base in range(0, 0x400000, 0x1000):
            if a[base:base + 0x1000] != b[base:base + 0x1000]:
                c = sum(1 for k in range(0, 0x1000, 4) if a[base + k:base + k + 4] != b[base + k:base + k + 4])
                rows.append((c, base))
        rows.sort(reverse=True)
        total = sum(c for c, _ in rows)
        print(f"  bloques distintos={len(rows)} palabras distintas={total}")
        for c, base in rows[:args.blocks]:
            print(f"  0x{0x80000000 + base:08X}: {c} palabras")


if __name__ == "__main__":
    sys.exit(main())
