#!/usr/bin/env python3
"""
validate_syms.py — valida los límites de función de una syms contra la ROM.

Detecta las clases de bug que rompen la recompilación estática:
  1) DELAY-SLOT CORTADO: un `jr $ra` cuyo delay-slot queda fuera del rango de la función
     (p. ej. FUN_80003db4 con size 0x88).
  2) RAMA CRUZADA: una rama PC-relativa cuyo destino cae dentro de OTRA función
     (indica un split incorrecto; p. ej. FUN_80001454 -> 0x8000161C).
  3) OVERLAP / tamaño inválido.
  4) SOSPECHA DE DATOS: muchas instrucciones no decodificables.

NOTA (modelo de módulos): el análisis es **por sección**. Varios módulos pueden compartir la misma
base de VRAM (bases reutilizadas: p.ej. idx 24 sobre la base de idx 23), así que mezclar todas las
funciones en un mapa global resuelve mal las ramas. Cada sección se valida contra su blob.

Uso:
  python3 tools/analysis/validate_syms.py config/us_ghidra.syms.toml \
      [--rom work/roms/us_retail.z64] \
      [--fix --out config/us_ghidra.fixed.syms.toml]

Exit != 0 si hay errores (delay-slot / rama cruzada). Con --fix --out escribe una syms corregida
(extiende sizes de delay-slots y fusiona splits seguros; las funciones llamadas por jal/j no se
eliminan).
"""

import argparse
import bisect
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
    sys.exit("Se requiere capstone (pip install capstone).")

MD = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_BIG_ENDIAN)

BRANCHES = {
    "beq", "bne", "blez", "bgtz", "bltz", "bgez", "bltzal", "bgezal",
    "beql", "bnel", "blezl", "bgtzl", "bltzl", "bgezl", "bltzall", "bgezall",
    "b", "bal", "bc1f", "bc1t", "bc1fl", "bc1tl",
}
FUNC_RE = re.compile(
    r'\{\s*name\s*=\s*"(\w+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)\s*,\s*size\s*=\s*(0x[0-9A-Fa-f]+)\s*\}')


def load_syms(path: Path):
    data = tomllib.loads(path.read_text())
    sections = []
    for sec in data.get("section", []):
        funcs = []
        for f in sec.get("functions", []):
            funcs.append({"name": f["name"], "vram": f["vram"], "size": f["size"],
                          "rom_base": sec["rom"], "sec_vram": sec["vram"]})
        funcs.sort(key=lambda f: f["vram"])
        sections.append({"name": sec.get("name", ""), "rom": sec["rom"],
                         "vram": sec["vram"], "size": sec.get("size", 0), "funcs": funcs})
    return sections


def _disasm(f, rom):
    start = f["rom_base"] + (f["vram"] - f["sec_vram"])
    return list(MD.disasm(rom[start:start + f["size"]], f["vram"]))


def _containing(funcs, vrams, addr):
    i = bisect.bisect_right(vrams, addr) - 1
    if i >= 0 and funcs[i]["vram"] <= addr < funcs[i]["vram"] + funcs[i]["size"]:
        return i
    return None


def _branch_target(insn):
    try:
        return int(insn.op_str.split(",")[-1].strip(), 16)
    except ValueError:
        return None


def validate(sections, rom, keep=frozenset()):
    delay, cross, badsize, suspect = [], [], [], []
    jal_targets = set()
    data_names_global = set()

    # Pase 1: targets de jal/j (absolutos) para proteger funciones de las fusiones.
    for sec in sections:
        for f in sec["funcs"]:
            for i in _disasm(f, rom):
                if i.mnemonic in ("jal", "j"):
                    try:
                        jal_targets.add(int(i.op_str, 16))
                    except ValueError:
                        pass

    # Pase 2: chequeo por sección (las bases de módulos pueden solapar).
    for sec in sections:
        funcs = sec["funcs"]
        if not funcs:
            continue
        vrams = [f["vram"] for f in funcs]
        data_names = set()
        cache = {}
        for f in funcs:
            insns = _disasm(f, rom)
            cache[f["name"]] = insns
            covered = sum(i.size for i in insns)
            if f["size"] and (f["size"] - covered) > f["size"] * 0.5:
                suspect.append((f, f["size"] - covered))
                data_names.add(f["name"])
        for idx, f in enumerate(funcs):
            if f["size"] <= 0 or f["size"] % 4 != 0:
                badsize.append(f)
            if f["name"] in data_names:      # disasm no fiable en datos
                continue
            end = f["vram"] + f["size"]
            for i in cache[f["name"]]:
                if i.mnemonic == "jr" and i.op_str == "$ra" and i.address + 4 >= end:
                    delay.append((f, i.address))
                elif i.mnemonic in BRANCHES:
                    t = _branch_target(i)
                    if t is None:
                        continue
                    j = _containing(funcs, vrams, t)
                    if (j is not None and j != idx and funcs[j]["name"] not in data_names
                            and t != funcs[j]["vram"] and funcs[j]["vram"] not in keep):
                        cross.append((f, 0, i.address, funcs[j], t))
        data_names_global |= data_names

    return {"delay": delay, "cross": cross, "badsize": badsize,
            "suspect": suspect, "jal_targets": jal_targets, "data_names": data_names_global}


def _find_cross(funcs, rom, data_names):
    vrams = [f["vram"] for f in funcs]
    pairs = []
    for idx, f in enumerate(funcs):
        if f["name"] in data_names:
            continue
        for i in _disasm(f, rom):
            if i.mnemonic in BRANCHES:
                t = _branch_target(i)
                if t is None:
                    continue
                j = _containing(funcs, vrams, t)
                if (j is not None and j != idx and funcs[j]["name"] not in data_names
                        and t != funcs[j]["vram"]):
                    pairs.append((idx, j))
    return pairs


def fix(sections, rom, report, keep=frozenset()):
    """Corrige por sección. Devuelve size/removed keyed por (sec_index, name)."""
    size = {}
    removed = set()
    jal = report["jal_targets"]

    for sec_idx, sec in enumerate(sections):
        funcs = sec["funcs"]
        for f in funcs:
            size[(sec_idx, f["name"])] = f["size"]

        # 1) delay-slots: +4 si no solapa
        order = sorted(funcs, key=lambda f: f["vram"])
        for i, f in enumerate(order):
            if any(c[0]["name"] == f["name"] and c[0]["vram"] == f["vram"] for c in report["delay"]):
                end_next = order[i + 1]["vram"] if i + 1 < len(order) else None
                ns = size[(sec_idx, f["name"])] + 4
                if end_next is None or f["vram"] + ns <= end_next:
                    size[(sec_idx, f["name"])] = ns

        # 2) ramas cruzadas: fusionar en la de menor vram (si la otra no es jal/j target)
        stuck = set()
        for _ in range(500):
            cur = [dict(f, size=size[(sec_idx, f["name"])]) for f in funcs
                   if (sec_idx, f["name"]) not in removed]
            cur.sort(key=lambda f: f["vram"])
            pairs = _find_cross(cur, rom, report["data_names"])
            if not pairs:
                break
            did = False
            for i, j in pairs:
                lo, hi = (cur[i], cur[j]) if cur[i]["vram"] < cur[j]["vram"] else (cur[j], cur[i])
                key = (lo["name"], hi["name"], lo["vram"], hi["vram"])
                if key in stuck or hi["vram"] in jal or hi["vram"] in keep:
                    stuck.add(key)
                    continue
                lo_end = lo["vram"] + size[(sec_idx, lo["name"])]
                hi_end = hi["vram"] + size[(sec_idx, hi["name"])]
                size[(sec_idx, lo["name"])] = max(lo_end, hi_end) - lo["vram"]
                removed.add((sec_idx, hi["name"]))
                did = True
                break
            if not did:
                break
    return {"size": size, "removed": removed, "stuck": stuck}


def write_fixed(src: Path, dst: Path, size, removed):
    lines = src.read_text().split("\n")
    out = []
    sec_idx = -1
    for ln in lines:
        if ln.strip() == "[[section]]":
            sec_idx += 1
        m = FUNC_RE.search(ln)
        if m:
            name, vram, sz = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
            key = (sec_idx, name)
            if key in removed:
                out.append(f"    # [validate_syms] {name} fusionada (split incorrecto)")
                continue
            ns = size.get(key, sz)
            if ns != sz:
                ln = ln[:m.start()] + \
                    f'{{ name = "{name}", vram = 0x{vram:08X}, size = 0x{ns:X} }}' + ln[m.end():]
        out.append(ln)
    dst.write_text("\n".join(out))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("syms", type=Path)
    ap.add_argument("--rom", type=Path, default=Path("work/roms/us_retail.z64"))
    ap.add_argument("--fix", action="store_true")
    ap.add_argument("--out", type=Path)
    ap.add_argument("--keep", default="",
                    help="direcciones (hex, separadas por comas) cuyas funciones no se fusionan "
                         "(entradas indirectas legítimas)")
    ap.add_argument("--keep-file", type=Path,
                    help="fichero con direcciones hex (una por línea o separadas por comas)")
    args = ap.parse_args()

    keep = set()
    if args.keep:
        keep |= {int(x, 16) for x in args.keep.split(",") if x.strip()}
    if args.keep_file and args.keep_file.exists():
        for line in args.keep_file.read_text().split("\n"):
            line = line.split("#")[0].strip()
            for tok in line.replace(",", " ").split():
                if tok:
                    keep.add(int(tok, 16))

    rom = args.rom.read_bytes()
    sections = load_syms(args.syms)
    total = sum(len(s["funcs"]) for s in sections)
    print(f"syms: {args.syms}  secciones: {len(sections)}  funciones: {total}")
    rep = validate(sections, rom, keep)

    if rep["delay"]:
        print(f"\n[ERROR] delay-slot cortado ({len(rep['delay'])}) — size += 4:")
        for f, a in rep["delay"][:40]:
            print(f"   {f['name']} vram=0x{f['vram']:08X} size=0x{f['size']:X}  "
                  f"jr_ra@0x{a:08X} -> size=0x{f['size'] + 4:X}")
    if rep["cross"]:
        print(f"\n[ERROR] ramas cruzadas ({len(rep['cross'])}) — posible split (fusionar):")
        seen = set()
        for f, _, a, g, t in rep["cross"]:
            k = (f["name"], g["name"])
            if k in seen:
                continue
            seen.add(k)
            print(f"   {f['name']}: rama @0x{a:08X} -> 0x{t:08X} (dentro de {g['name']})")
    if rep["badsize"]:
        print(f"\n[WARN] tamaño inválido ({len(rep['badsize'])}): " +
              ", ".join(f"{f['name']}(0x{f['size']:X})" for f in rep["badsize"][:10]))
    if rep["suspect"]:
        print(f"\n[WARN] sospecha de datos ({len(rep['suspect'])}):")
        for f, und in rep["suspect"][:15]:
            print(f"   {f['name']} vram=0x{f['vram']:08X} no_decodificado={und}/{f['size']}")

    if not (rep["delay"] or rep["cross"]):
        print("\nOK: sin errores de límites (delay-slot / rama cruzada).")

    rc = 1 if (rep["delay"] or rep["cross"]) else 0

    if args.fix:
        res = fix(sections, rom, rep, keep)
        out = args.out or args.syms.with_suffix(".fixed.syms.toml")
        write_fixed(args.syms, out, res["size"], res["removed"])
        print(f"\n[fix] escrito {out}: fusionadas {len(res['removed'])}, "
              f"sin resolver {len(res['stuck'])}")
        if res["stuck"]:
            print("[fix] revisar manualmente: " +
                  ", ".join(f"{a}+{b}" for a, b, _, _ in sorted(res["stuck"])[:10]))

    return rc


if __name__ == "__main__":
    raise SystemExit(main())
