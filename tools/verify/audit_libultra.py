#!/usr/bin/env python3
"""A1 — Auditoría de cobertura libultra.

Compara los nombres que N64Recomp conoce (ignored+reimplemented) contra:
  - los que nuestro ELF ya reconoce,
  - los que el runtime (librecomp) provee como `<name>_recomp`,
  - las direcciones disponibles en las syms legacy (Ghidra).
Salida: candidatos seguros de nombrar (runtime provee `_recomp`) y avisos.
Solo lectura. Uso: python3 tools/verify/audit_libultra.py
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SYMBOL_LISTS = ROOT / "toolchain/src/N64Recomp/src/symbol_lists.cpp"
ELF = ROOT / "build/recomp/elf/hybrid-heaven.us.elf"
LEGACY_GLOBS = ["legacy/config/*.syms.toml"]
OURLIST = ROOT / "recomp/symbol_addrs.txt"


def n64_lists():
    t = SYMBOL_LISTS.read_text(errors="replace")
    out = {}
    for n in ("reimplemented_funcs", "ignored_funcs", "renamed_funcs"):
        m = re.search(n + r"\s*\{(.*?)\n\};", t, re.S)
        out[n] = set(re.findall(r'"([^"]+)"', m.group(1))) if m else set()
    return out


def runtime_recomp():
    defs = set()
    for p in (ROOT / "lib/N64ModernRuntime/librecomp").rglob("*"):
        if p.suffix not in (".cpp", ".c", ".h"):
            continue
        try:
            s = p.read_text(errors="replace")
        except OSError:
            continue
        defs |= set(re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)_recomp\b", s))
    return defs


def legacy_addrs():
    out = {}
    for g in LEGACY_GLOBS:
        for f in ROOT.glob(g):
            for m in re.finditer(r'name\s*=\s*"([^"]+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)', f.read_text(errors="replace")):
                out.setdefault(m.group(1), int(m.group(2), 16))
    return out


def elf_funcs():
    txt = subprocess.run(["llvm-readelf", "-sW", str(ELF)], capture_output=True, text=True).stdout
    by_vram = {}
    names = set()
    for line in txt.splitlines():
        p = line.split()
        if len(p) >= 8 and p[3] == "FUNC":
            try:
                v = int(p[1], 16)
            except ValueError:
                continue
            names.add(p[7])
            if v:
                by_vram[v] = p[7]
    return by_vram, names


def main():
    lists = n64_lists()
    target = lists["ignored_funcs"] | lists["reimplemented_funcs"]
    recomp = runtime_recomp()
    legacy = legacy_addrs()
    by_vram, elf_names = elf_funcs()
    ours = set()
    for l in OURLIST.read_text().splitlines():
        s = l.split("=")[0].strip()
        if s:
            ours.add(s)

    safe = sorted(target & recomp)
    unsafe = sorted(target - recomp)
    safe_named = [n for n in safe if n in elf_names]
    safe_with_addr = [n for n in safe if n in legacy]
    safe_addr_in_elf = [n for n in safe if n in legacy and legacy[n] in by_vram]
    safe_no_addr = [n for n in safe if n not in legacy]

    print("== resumen ==")
    print("target (ignored+reimplemented): %d" % len(target))
    print("runtime provee _recomp        : %d" % len(recomp))
    print("SAFE (target & _recomp)       : %d" % len(safe))
    print("  ya reconocidos en ELF       : %d" % len(safe_named))
    print("  con direccion legacy        : %d" % len(safe_with_addr))
    print("  y esa direccion es FUNC ELF : %d" % len(safe_addr_in_elf))
    print("  sin direccion legacy        : %d" % len(safe_no_addr))
    print("UNSAFE (sin _recomp)          : %d" % len(unsafe))
    print()
    print("== SAFE sin reconocer, con direccion legacy válida (candidatos directos) ==")
    for n in safe:
        if n in elf_names:
            continue
        v = legacy.get(n)
        if v is not None and v in by_vram:
            print("  %-28s = 0x%08X" % (n, v))
    print()
    print("== SAFE sin reconocer ni direccion (necesitan fingerprint) ==")
    print("  " + ", ".join(safe_no_addr[:60]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
