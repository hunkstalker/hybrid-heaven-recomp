#!/usr/bin/env python3
"""diff_battle_watch.py <watchA.log> <watchB.log>

Compara dos `hh_battle_watch.log` (traza de combate, `run_battle_trace.bat`) para localizar el flag
de SORPRESA. Como la traza registra la PRIMERA variacion de cada palabra, lo interesante es:

  - direcciones que cambiaron en UNA traza y no en la otra (candidato directo: p. ej. el enemigo te
    detecta en el combate normal y no en el de espalda);
  - direcciones presentes en ambas con valor nuevo distinto.

Formato de linea:  vi=<n> addr=<hex> <old>-><new>   (valores guest big-endian, 32 bits)

Uso:
    python tools/analysis/diff_battle_watch.py normal.log sorpresa.log
"""
import re
import sys

LINE = re.compile(r"vi=(\d+)\s+addr=([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})->([0-9A-Fa-f]{8})")


def load(path):
    out = {}
    with open(path, "r", errors="ignore") as f:
        for line in f:
            m = LINE.search(line)
            if not m:
                continue
            vi = int(m.group(1))
            addr = int(m.group(2), 16)
            old = int(m.group(3), 16)
            new = int(m.group(4), 16)
            if addr not in out:
                out[addr] = (vi, old, new)   # se conserva la PRIMERA variacion de cada palabra
    return out


def val(v):
    # Marca valores pequenos (candidatos a flag) y floats razonables.
    if v <= 0x10:
        return f"{v} (flag?)"
    return f"{v}"


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    a = load(sys.argv[1])
    b = load(sys.argv[2])
    only_a = sorted(set(a) - set(b))
    only_b = sorted(set(b) - set(a))
    both = sorted(set(a) & set(b))

    print(f"A={len(a)} B={len(b)} palabras; solo_A={len(only_a)} solo_B={len(only_b)} comunes={len(both)}")

    print("\n--- solo en A (normal) ---")
    for addr in only_a[:80]:
        vi, old, new = a[addr]
        print(f"  {addr:08X}  vi={vi}  {old:08X}->{new:08X}  new={val(new)}")
    if len(only_a) > 80:
        print(f"  ... y {len(only_a)-80} mas")

    print("\n--- solo en B (sorpresa) ---")
    for addr in only_b[:80]:
        vi, old, new = b[addr]
        print(f"  {addr:08X}  vi={vi}  {old:08X}->{new:08X}  new={val(new)}")
    if len(only_b) > 80:
        print(f"  ... y {len(only_b)-80} mas")

    print("\n--- comunes con valor nuevo distinto (candidatos menos limpios) ---")
    n = 0
    for addr in both:
        if a[addr][2] != b[addr][2]:
            n += 1
            if n <= 80:
                print(f"  {addr:08X}  A: {a[addr][1]:08X}->{a[addr][2]:08X}   "
                      f"B: {b[addr][1]:08X}->{b[addr][2]:08X}")
    print(f"  total: {n}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
