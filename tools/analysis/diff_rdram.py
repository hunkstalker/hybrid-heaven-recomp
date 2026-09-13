#!/usr/bin/env python3
"""diff_rdram.py <port_dump> <emu_dump> [base_hex size_hex]

Compara dos volcados de RDRAM (ambos word-swapped, tal como los produce el port
y r64dump) y resume las diferencias por bloques de 64 KB. Con base/size opcionales
limita el rango (por defecto toda la RDRAM).
"""
import sys
import numpy as np


def load(path):
    return np.fromfile(path, dtype=np.uint32)


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    p = load(sys.argv[1])
    e = load(sys.argv[2])
    n = min(len(p), len(e))
    if len(sys.argv) >= 5:
        base = int(sys.argv[3], 16) & 0x7FFFFFFF
        size = int(sys.argv[4], 16)
        o = base // 4
        n = min(n, o + size // 4)
        p = p[o:n]
        e = e[o:n]
        start = base
    else:
        start = 0
        p = p[:n]
        e = e[:n]

    diff = p != e
    total = int(diff.sum())
    print(f"rango 0x{0x80000000+start:08X}..: {len(p):,} palabras, {total:,} distintas ({100*total/len(p):.2f}%)")
    if total == 0:
        return 0

    idx = np.nonzero(diff)[0]
    # resumen por bloques de 64 KB
    blocks = np.bincount(idx * 4 // 0x10000)
    print("bloques de 64KB con diferencias:")
    for b in np.argsort(blocks)[::-1]:
        if blocks[b] == 0:
            break
        print(f"  0x{0x80000000+start+b*0x10000:08X}: {blocks[b]:,} palabras")
    print("primeras 16 diferencias:")
    for i in idx[:16]:
        print(f"  0x{0x80000000+start+i*4:08X}: port=0x{p[i]:08X} emu=0x{e[i]:08X}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
