#!/usr/bin/env python3
"""Triaje de discrepancias de `size` legacy(Ghidra) vs ELF: dimensiona la deuda.

Salida: resumen por magnitud de delta, y para la clase 'split' lista los simbolos ELF
contiguos que absorbe cada uno (para ver si son stubs/case-bodies o funciones reales).

Solo lectura. Uso: python3 work/verify/triage_sizes.py
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
LEGACY = ROOT / "legacy/config/us_combined.syms.toml"
ELF = ROOT / "build/recomp/elf/hybrid-heaven.us.elf"
LEG_RE = re.compile(r'name\s*=\s*"([^"]+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)\s*,\s*size\s*=\s*(0x[0-9A-Fa-f]+)')

def parse_legacy():
    out = {}
    for m in LEG_RE.finditer(LEGACY.read_text()):
        out[int(m.group(2), 16)] = (m.group(1), int(m.group(3), 16))
    return out

def parse_elf():
    txt = subprocess.run(["llvm-readelf", "-sW", str(ELF)], capture_output=True, text=True, check=True).stdout
    out = {}
    for line in txt.splitlines():
        p = line.split()
        if len(p) < 8 or p[3] != "FUNC":
            continue
        try:
            v, s = int(p[1], 16), int(p[2])
        except ValueError:
            continue
        if v and s:
            out.setdefault(v, (p[7], s))
    return out

def main():
    legacy, elf = parse_legacy(), parse_elf()
    common = sorted(set(legacy) & set(elf))
    elf_sorted = sorted(elf)

    deltas = {}
    splits = []
    for v in common:
        ln, ls = legacy[v]
        en, es = elf[v]
        d = ls - es
        if d == 0:
            continue
        deltas[d] = deltas.get(d, 0) + 1
        if d > 0:
            acc, absorbed = 0, []
            try:
                i = elf_sorted.index(v)
            except ValueError:
                i = None
            if i is not None:
                for w in elf_sorted[i:]:
                    if w >= v + ls:
                        break
                    acc += elf[w][1]
                    absorbed.append((w, elf[w][0], elf[w][1]))
            if acc == ls:
                splits.append((v, ln, ls, absorbed))

    print("== distribucion de deltas (legacy - ELF), |delta| ==")
    for d in sorted(deltas, key=lambda x: -abs(x)):
        if abs(d) > 0x20:
            print("  %+6d : %d" % (d, deltas[d]))
    small = sum(c for d, c in deltas.items() if abs(d) <= 0x20)
    print("  (|delta| <= 0x20): %d" % small)
    print("  total mismatches: %d" % sum(deltas.values()))
    print()
    print("== splits exactos (legacy = suma de ELF contiguos): %d ==" % len(splits))
    for v, ln, ls, absorbed in sorted(splits, key=lambda x: -x[2]):
        parts = ", ".join("%s(0x%X)" % (n, s) for _, n, s in absorbed[:4])
        more = "" if len(absorbed) <= 4 else " +%d" % (len(absorbed) - 4)
        print("  0x%08X %-22s legacy 0x%-5X = %s%s" % (v, ln, ls, parts, more))
    return 0

if __name__ == "__main__":
    sys.exit(main())
