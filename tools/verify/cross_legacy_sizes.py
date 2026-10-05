#!/usr/bin/env python3
"""Cruce de tamanos de funcion: syms legacy (Ghidra) vs extents del ELF actual.

Solo lectura. Busca la clase del #14/veneno: funciones cuyo `size` se perdio en la
migracion a splat/ELF, de modo que splat las corto y dejo los bytes sobrantes como
funciones aparte. Es un aviso de bugs latentes del mismo tipo.

Uso: python3 work/verify/cross_sizes.py
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
        name, vram, size = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
        out[vram] = (name, size)
    return out

def parse_elf():
    txt = subprocess.run(["llvm-readelf", "-sW", str(ELF)], capture_output=True, text=True, check=True).stdout
    out = {}
    for line in txt.splitlines():
        parts = line.split()
        if len(parts) < 8 or parts[3] != "FUNC":
            continue
        try:
            vram = int(parts[1], 16)
            size = int(parts[2])
        except ValueError:
            continue
        if vram == 0 or size == 0:
            continue
        out.setdefault(vram, (parts[7], size))
    return out

def main():
    legacy = parse_legacy()
    elf = parse_elf()
    common = sorted(set(legacy) & set(elf))
    only_legacy = sorted(set(legacy) - set(elf))
    only_elf = sorted(set(elf) - set(legacy))

    mism = []
    for v in common:
        ln, ls = legacy[v]
        en, es = elf[v]
        if ls != es:
            mism.append((v, ln, ls, en, es))

    # Clasifica los mismatches: contiguos en el ELF a partir de v (la funcion partida).
    splits = []
    others = []
    elf_sorted = sorted(elf)
    for v, ln, ls, en, es in mism:
        acc = 0
        try:
            i = elf_sorted.index(v)
        except ValueError:
            i = None
        if i is not None:
            for w in elf_sorted[i:]:
                if w >= v + ls:
                    break
                acc += elf[w][1]
            if acc == ls and es < ls:
                splits.append((v, ln, ls, en, es))
                continue
        others.append((v, ln, ls, en, es))

    print("legacy funcs : %d" % len(legacy))
    print("ELF    funcs : %d" % len(elf))
    print("coinciden por vram: %d" % len(common))
    print("solo legacy : %d" % len(only_legacy))
    print("solo ELF    : %d" % len(only_elf))
    print("mismatch de size: %d  (split: %d, otros: %d)" % (len(mism), len(splits), len(others)))
    print()
    print("== clases 'split' (Ghidra >= ELF; los bytes que faltan son funciones contiguas): muestras ==")
    for v, ln, ls, en, es in sorted(splits, key=lambda x: -(x[2] - x[4]))[:25]:
        print("  0x%08X legacy %-24s 0x%X  |  ELF %-24s 0x%X (faltan 0x%X)"
              % (v, ln, ls, en, es, ls - es))
    if len(splits) > 25:
        print("  ... y %d mas" % (len(splits) - 25))
    print()
    print("== mismatches no-split (revisar aparte) ==")
    for v, ln, ls, en, es in sorted(others)[:20]:
        print("  0x%08X legacy %-24s 0x%X  |  ELF %-24s 0x%X" % (v, ln, ls, en, es))
    if len(others) > 20:
        print("  ... y %d mas" % (len(others) - 20))
    return 0

if __name__ == "__main__":
    sys.exit(main())
