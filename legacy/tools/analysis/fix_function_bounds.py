#!/usr/bin/env python3
"""
fix_function_bounds.py — corrige límites de función de una syms por análisis de flujo (CFG).

Problema: Ghidra omite inicios de función (típicamente funciones sin prólogo que siguen a un
`jr $ra`). Al hacer las funciones contiguas, la anterior "se come" a la siguiente. Un split
ingenuo por `jr $ra` parte funciones con returns tempranos.

Solución determinista: **reachability**. Para cada función F se calcula el conjunto de
direcciones alcanzables desde su entrada (siguiendo ramas, sin caer tras un terminador). Lo que
quede dentro del rango declarado pero NO sea alcanzable pertenece a otra función. Un inicio
candidato se acepta solo si:
  - no es alcanzable desde F (no es un return temprano), y
  - tiene evidencia (destino de salto/jal, o va justo tras un terminador), y
  - su propio CFG es sano (termina en terminador, tamaño razonable).

Puertas de calidad (externas): validate_syms.py, N64Recomp recompila, boot smoke.

Uso:
  python3 tools/analysis/fix_function_bounds.py <syms> --rom <rom> --out <out> [--report-only]
"""

import argparse
import re
import sys
from pathlib import Path

try:
    import tomllib
except ImportError:
    sys.exit("Se requiere Python 3.11+ (tomllib).")
try:
    import capstone
except ImportError:
    sys.exit("Se requiere capstone.")

MD = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_BIG_ENDIAN)
MD.skipdata = True

COND = {"beq", "bne", "blez", "bgtz", "bltz", "bgez", "beql", "bnel", "blezl", "bgtzl",
        "bltzl", "bgezl", "bltzall", "bgezall", "bc1f", "bc1t", "bc1fl", "bc1tl"}
UNCOND = {"b", "j"}
CALL = {"jal", "bal", "jalx"}
INDIRECT = {"jr", "jalr"}
N_RE = re.compile(r'\{\s*name\s*=\s*"(\w+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)\s*,\s*size\s*=\s*(0x[0-9A-Fa-f]+)\s*\}')


def load_syms(path: Path):
    data = tomllib.loads(path.read_text())
    return [{"name": s.get("name", ""), "rom": s["rom"], "vram": s["vram"], "size": s["size"],
             "functions": [{"name": f["name"], "vram": f["vram"], "size": f["size"]}
                           for f in s.get("functions", [])]}
            for s in data.get("section", [])]


def insn_at(rom, sec, addr, limit):
    if not (sec["vram"] <= addr < limit):
        return None
    off = sec["rom"] + (addr - sec["vram"])
    if off + 4 > len(rom):
        return None
    for i in MD.disasm(rom[off:off + 4], addr):
        return i
    return None


def target_of(ins):
    try:
        return int(ins.op_str.split(",")[-1].strip(), 16)
    except ValueError:
        return None


def is_term(ins):
    return ins is not None and (ins.mnemonic in UNCOND or ins.mnemonic == "jr")


def reachable(rom, sec, entry, limit, stop=0x40000):
    """Direcciones alcanzables desde `entry` (CFG; no cae tras terminadores; no cruza `limit`)."""
    reach, work, steps = set(), [entry], 0
    while work:
        a = work.pop()
        while True:
            if a in reach or not (entry <= a < limit) or steps > stop:
                break
            steps += 1
            ins = insn_at(rom, sec, a, limit)
            if ins is None:
                break
            reach.add(a)
            m = ins.mnemonic
            if m in COND or m in UNCOND or m in CALL or m in INDIRECT:
                d = a + 4
                if entry <= d < limit:
                    reach.add(d)
                after = d + 4
            else:
                after = a + 4
            if m in CALL or (m == "jalr" and ins.op_str.startswith("$ra")):
                a = after
                continue
            if m == "jr" or m == "jalr":
                break
            if m in UNCOND:
                t = target_of(ins)
                if t is not None and entry <= t < limit:
                    work.append(t)
                break
            if m in COND:
                t = target_of(ins)
                if t is not None and entry <= t < limit:
                    work.append(t)
                a = after
                continue
            a = after
    return reach


def referenced_targets(rom, sec):
    limit = sec["vram"] + sec["size"]
    tgts = set()
    for i in MD.disasm(rom[sec["rom"]:sec["rom"] + sec["size"]], sec["vram"]):
        if i.id == 0:
            continue
        if i.mnemonic in COND or i.mnemonic in UNCOND or i.mnemonic in CALL:
            t = target_of(i)
            if t is not None and sec["vram"] <= t < limit:
                tgts.add(t)
    return tgts


def valid_function(rom, sec, entry, limit):
    """CFG sano: tiene terminador y tamaño razonable. Devuelve el reach o None."""
    r = reachable(rom, sec, entry, limit)
    if not r:
        return None
    if not any(is_term(insn_at(rom, sec, a, limit)) for a in r):
        return None
    size = max(r) + 4 - entry
    return r if 0 < size <= 0x20000 else None


def process_section(rom, sec, report):
    limit = sec["vram"] + sec["size"]
    funcs = sorted(sec["functions"], key=lambda f: f["vram"])
    refs = referenced_targets(rom, sec)
    entries = {f["vram"] for f in funcs}

    # Regiones a analizar: rango declarado de cada función + huecos no cubiertos.
    regions = [(f["vram"], f["vram"] + f["size"]) for f in funcs]
    cur = sec["vram"]
    for f in funcs:
        if f["vram"] > cur:
            regions.append((cur, f["vram"]))
        cur = max(cur, f["vram"] + f["size"])
    if cur < limit:
        regions.append((cur, limit))

    for r0, r1 in regions:
        reach = reachable(rom, sec, r0, r1) if any(f["vram"] == r0 for f in funcs) else set()
        a = r0
        while a < r1:
            if a not in entries and a not in reach:
                ev = (a in refs) or is_term(insn_at(rom, sec, a - 4, limit))
                if ev:
                    r = valid_function(rom, sec, a, r1)
                    if r:
                        entries.add(a)
                        report.append((a, r0, "gap" if not reach else "absorbida"))
                        a = max(r) + 4
                        continue
            a += 4

    ents = sorted(entries)
    return [{"name": next((f["name"] for f in funcs if f["vram"] == a), f"FUN_{a:08x}"),
             "vram": a,
             "size": (ents[k + 1] if k + 1 < len(ents) else limit) - a}
            for k, a in enumerate(ents)]


def write_syms(src: Path, dst: Path, secs, new_funcs):
    parts = re.split(r'(?m)^\[\[section\]\]\s*$', src.read_text())
    out = [parts[0].rstrip("\n"), ""]
    for idx in range(len(secs)):
        out.append("[[section]]")
        out.append(f'name = "{secs[idx]["name"]}"')
        out.append(f'rom = 0x{secs[idx]["rom"]:X}')
        out.append(f'vram = 0x{secs[idx]["vram"]:08X}')
        out.append(f'size = 0x{secs[idx]["size"]:X}')
        out.append("")
        out.append("functions = [")
        for f in new_funcs[idx]:
            out.append(f'    {{ name = "{f["name"]}", vram = 0x{f["vram"]:08X}, size = 0x{f["size"]:X} }},')
        out.append("]")
        out.append("")
    dst.write_text("\n".join(out).rstrip("\n") + "\n")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("syms", type=Path)
    ap.add_argument("--rom", type=Path, default=Path("work/roms/us_retail.z64"))
    ap.add_argument("--out", type=Path)
    ap.add_argument("--report-only", action="store_true")
    args = ap.parse_args()

    rom = args.rom.read_bytes()
    secs = load_syms(args.syms)
    report = []
    new = [process_section(rom, s, report) for s in secs]

    old_n = sum(len(s["functions"]) for s in secs)
    new_n = sum(len(x) for x in new)
    print(f"syms: {args.syms}  secciones: {len(secs)}")
    print(f"funciones: {old_n} -> {new_n}  (añadidas {new_n - old_n})")
    for a, cont, why in report[:50]:
        print(f"   + 0x{a:08X}  ({why}, contenedor 0x{cont:08X})")
    if len(report) > 50:
        print(f"   ... y {len(report) - 50} más")

    if not args.report_only:
        out = args.out or args.syms.with_suffix(".fixed.syms.toml")
        write_syms(args.syms, out, secs, new)
        print(f"escrito: {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
