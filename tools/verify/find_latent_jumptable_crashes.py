#!/usr/bin/env python3
"""Detección de crashes LATENTES en jump tables cruzadas.

Refina find_cross_jumptables.py: para cada case cross-function calcula
  - el bound del switch (de `sltiu $x, $y, N` antes del switch) -> alcanzable o no,
  - si el target tiene cuerpo/registro recompilado (func_<vram>_... emitido).

Veredicto:
  CRASH   target alcanzable y SIN cuerpo registrado -> get_function aborta en runtime.
  OK      target alcanzable y registrado  -> el parche (tail call) funciona.
  dead    case fuera del bound            -> inalcanzable (over-read), inocuo.

La lista CRASH es la deuda real que hay que arreglar. Solo lectura.
Uso: python3 tools/verify/find_latent_jumptable_crashes.py
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FUNCS = ROOT / "build/recomp/RecompiledFuncs"

FUNC_DEF = re.compile(r'^RECOMP_FUNC void (func_[0-9A-Fa-f]+)_[0-9A-Fa-f]+\(uint8_t\* rdram')
LK = re.compile(r'^\s*LOOKUP_FUNC\(0x([0-9A-Fa-f]+)\)\(rdram, ctx\);\s*$')
RET = re.compile(r'^\s*return;\s*$')
BRK = re.compile(r'^\s*break;\s*$')
CASE = re.compile(r'^\s*case\s+(\d+):')
SWITCH = re.compile(r'^\s*switch \(jr_addend_')
SLTIU = re.compile(r'//\s*0x[0-9A-Fa-f]+:\s*sltiu\s+\$\w+,\s*\$\w+,\s*0x([0-9A-Fa-f]+)')


def main():
    # vram -> tiene cuerpo emitido
    emitted = set()
    files = sorted(FUNCS.glob("*.c"))
    for f in files:
        for l in f.read_text(encoding="utf-8", errors="replace").splitlines():
            m = FUNC_DEF.match(l)
            if m:
                emitted.add(int(m.group(1).split("_")[1], 16))

    cases = []  # (owner, case_idx, target, bound)
    for f in files:
        cur = None
        bound = None
        lines = f.read_text(encoding="utf-8", errors="replace").splitlines()
        for i, l in enumerate(lines):
            m = FUNC_DEF.match(l)
            if m:
                cur = int(m.group(1).split("_")[1], 16)
                bound = None
            m = SLTIU.search(l)
            if m:
                bound = int(m.group(1), 16)
            if SWITCH.match(l):
                # recorrer los cases de este switch
                j = i + 1
                while j < len(lines):
                    cm = CASE.match(lines[j])
                    if cm:
                        idx = int(cm.group(1))
                        if (j + 2 < len(lines) and LK.match(lines[j + 1])
                                and RET.match(lines[j + 2]) and BRK.match(lines[j + 3])):
                            tgt = int(LK.match(lines[j + 1]).group(1), 16)
                            cases.append((cur, idx, tgt, bound))
                    if lines[j].strip() == "}" and "switch" not in lines[j]:
                        break
                    j += 1

    crash, ok, dead = [], [], []
    for owner, idx, tgt, bound in cases:
        if bound is not None and idx >= bound:
            dead.append((owner, idx, tgt))
        elif tgt in emitted:
            ok.append((owner, idx, tgt))
        else:
            crash.append((owner, idx, tgt))

    print("cases cross-function: %d  (CRASH %d, OK %d, dead %d)"
          % (len(cases), len(crash), len(ok), len(dead)))
    print()
    if crash:
        print("== CRASH LATENTE (case alcanzable -> target SIN cuerpo registrado) ==")
        for owner, idx, tgt in sorted(set(crash)):
            print("  owner func_%08X  case %-3d -> 0x%08X  (no registrado)" % (owner, idx, tgt))
    else:
        print("== sin crashes latentes: todo case alcanzable o tiene cuerpo, o es inalcanzable ==")
    print()
    print("== alcanzables OK (target registrado; parche tail-call) ==")
    for owner, idx, tgt in sorted(set(ok)):
        print("  owner func_%08X  case %-3d -> 0x%08X" % (owner, idx, tgt))
    return 0


if __name__ == "__main__":
    sys.exit(main())
