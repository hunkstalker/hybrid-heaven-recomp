#!/usr/bin/env python3
"""Detección autoritativa de jump tables que CRUZAN a otra función.

Marca el patron exacto que emite el parche de N64Recomp cuando una entrada de jump
table apunta fuera de la función (tail call):

        case N:
        LOOKUP_FUNC(0xXXXXXXXX)(rdram, ctx);
    return;
        break;

Esa es la clase #14/veneno (frontera de función mal puesta). Para cada función
implicada lista: vram, size actual en el ELF, targets y la extensión que implicaria
absorberlos (candidato a `size:` en la base). Solo lectura.

Uso: python3 tools/verify/find_cross_jumptables.py
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FUNCS = ROOT / "build/recomp/RecompiledFuncs"
ELF = ROOT / "build/recomp/elf/hybrid-heaven.us.elf"

LK = re.compile(r'^\s*LOOKUP_FUNC\(0x([0-9A-Fa-f]+)\)\(rdram, ctx\);\s*$')
RET = re.compile(r'^\s*return;\s*$')
BRK = re.compile(r'^\s*break;\s*$')
FUNC_DEF = re.compile(r'^RECOMP_FUNC void (func_[0-9A-Fa-f]+)_([0-9A-Fa-f]+)\(uint8_t\* rdram')
# nombre con rom sintetico -> vram, y vram -> size desde el ELF
def elf_sizes():
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
    sizes = elf_sizes()
    owners = {}
    for f in sorted(FUNCS.glob("*.c")):
        cur_owner = None
        lines = f.read_text(encoding="utf-8", errors="replace").splitlines()
        for i, l in enumerate(lines):
            m = FUNC_DEF.match(l)
            if m:
                cur_owner = int(m.group(1).split("_")[1], 16)  # func_<VRAM>_...
            m = LK.match(l)
            if m and i + 2 < len(lines) and RET.match(lines[i + 1]) and BRK.match(lines[i + 2]):
                if cur_owner is not None:
                    owners.setdefault(cur_owner, set()).add(int(m.group(1), 16))

    print("funciones con jump table cross-function: %d" % len(owners))
    print("%-12s %-8s %-10s %-8s  %s" % ("owner", "cur_size", "merged?", "targets", "detalle"))
    total_cases = 0
    for v in sorted(owners):
        tg = sorted(owners[v])
        total_cases += len(tg)
        name, cur = sizes.get(v, ("?", 0))
        end = v + cur
        # extension si se absorbieran los targets: hasta el final del ultimo target conocido
        last_end = max((t + sizes.get(t, ("", 0))[1] for t in tg), default=v)
        merged = last_end - v
        print("%-12s 0x%-6X 0x%-8X %-8s  %s" % ("0x%08X" % v, cur, merged,
              "si" if merged > cur else "no", ", ".join("0x%08X" % t for t in tg)))
    print("\ntotal casos: %d" % total_cases)
    return 0

if __name__ == "__main__":
    sys.exit(main())
