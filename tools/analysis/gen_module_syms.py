#!/usr/bin/env python3
"""
gen_module_syms.py — genera la syms de un blob de módulo MIPS (big-endian) por detección
de funciones con capstone:
  - inicio del blob,
  - prólogos `addiu $sp, $sp, -N`,
  - destinos de `jal`/`bal` internos,
  - dirección siguiente al delay-slot de cada `jr $ra` (fin de función → posible nueva).

`--extra` añade funciones no detectables estáticamente (destinos de punteros de función en datos),
obtenidas por evidencia runtime (`Failed to find function at 0x...`).

Además, **fusiona los `switch`/jump-tables**: el detector `jr $ra` sobre-parte las funciones con
`switch` (cada `case` acaba en `jr $ra`), y N64Recomp exige que TODAS las entradas de la tabla caigan
dentro de la función que contiene el `jr`. Se detectan las tablas (`lui/addu/lw/jr`) y se fusiona la
función de dispatch con todos sus `case` (y la que la precede si ramifica hacia ella).

Uso:
  python3 tools/analysis/gen_module_syms.py <blob_be.bin> --vram 0x80107830 \
      --rom 0x1000000 --out config/us_module7.syms.toml [--extra 0x80383D00,...]
"""

import argparse
import bisect
import struct
from pathlib import Path

import capstone

MD = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_BIG_ENDIAN)
MD.skipdata = True

MD_D = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_BIG_ENDIAN)
MD_D.detail = True
MD_D.skipdata = True

# Ramas directas no-enlazadas (las que unen bloques de una misma función).
BRANCHES = {
    "b", "beq", "bne", "blez", "bgtz", "bltz", "bgez",
    "beql", "bnel", "blezl", "bgtzl", "bltzl", "bgezl",
    "bc1f", "bc1t", "bc1fl", "bc1tl",
}
# Ramas con enlace (llamadas locales): NO unen funciones.
BRANCH_LINK = {"bal", "bltzal", "bgezal", "bltzall", "bgezall"}


def _s16(value: int) -> int:
    value &= 0xFFFF
    return value - 0x10000 if value >= 0x8000 else value


def detect_functions(blob: bytes, vram: int, extra=()):
    end = vram + len(blob)
    entries = {vram}
    for a in extra:
        if vram <= a < end:
            entries.add(a)
    for i in MD.disasm(blob, vram):
        if i.address > vram and i.mnemonic == "addiu" and i.op_str.startswith("$sp, $sp, -"):
            entries.add(i.address)
        elif i.mnemonic in ("jal", "bal"):
            try:
                t = int(i.op_str, 16)
            except ValueError:
                continue
            if vram < t < end:
                entries.add(t)
        elif i.mnemonic == "jr" and i.op_str == "$ra":
            nxt = i.address + 8
            if vram < nxt < end:
                entries.add(nxt)
    return sorted(a for a in entries if vram <= a < end)


def detect_jump_tables(blob: bytes, vram: int):
    """Devuelve [(jr_vram, table_vram, [targets])] para cada `jr $reg` con tabla de salto.

    El número de entradas se acota por la **siguiente tabla** (como hace N64Recomp), no solo por
    la primera entrada inválida: así no se absorben casos de otras funciones contiguas.
    """
    end = vram + len(blob)
    insns = list(MD_D.disasm(blob, vram))
    raw = []
    for k, i in enumerate(insns):
        if i.mnemonic != "jr" or len(i.operands) != 1:
            continue
        op = i.operands[0]
        if op.type != capstone.CS_OP_REG:
            continue
        reg = i.reg_name(op.reg)
        if reg == "ra":
            continue
        tabaddr = None
        for j in range(k - 1, max(-1, k - 10), -1):
            p = insns[j]
            if (p.mnemonic == "lw" and len(p.operands) >= 2
                    and p.operands[0].type == capstone.CS_OP_REG
                    and p.reg_name(p.operands[0].reg) == reg):
                mem = p.operands[1]
                if mem.type == capstone.CS_OP_MEM:
                    basereg = p.reg_name(mem.mem.base)
                    lo = _s16(mem.mem.disp)
                    for m in range(j - 1, max(-1, j - 7), -1):
                        q = insns[m]
                        if (q.mnemonic == "lui" and len(q.operands) >= 2
                                and q.operands[0].type == capstone.CS_OP_REG
                                and q.reg_name(q.operands[0].reg) == basereg):
                            tabaddr = (q.operands[1].imm << 16) + lo
                            break
                break
        if tabaddr is not None and vram <= tabaddr < end:
            raw.append((i.address, tabaddr))

    tab_addrs = sorted({t for _, t in raw})
    tables = []
    for jr, tabaddr in raw:
        i = bisect.bisect_right(tab_addrs, tabaddr)
        bound = tab_addrs[i] if i < len(tab_addrs) else end
        off = tabaddr - vram
        targets = []
        while off + 4 <= len(blob) and (vram + off) < bound:
            w = struct.unpack(">I", blob[off:off + 4])[0]
            if not (vram <= w < end):
                break
            targets.append(w)
            off += 4
        if targets:
            tables.append((jr, tabaddr, targets))
    return tables


def _branches_into(blob: bytes, vram: int, start: int, end: int, lo: int, hi: int) -> bool:
    off = start - vram
    for i in MD_D.disasm(blob[off:off + (end - start)], start):
        if i.mnemonic in BRANCHES and i.operands and i.operands[-1].type == capstone.CS_OP_IMM:
            if lo <= i.operands[-1].imm < hi:
                return True
    return False


def merge_jump_tables(ents, blob: bytes, vram: int):
    """Fusiona las funciones que participan en cada jump-table. Devuelve (starts, size_override)."""
    end = vram + len(blob)
    tables = detect_jump_tables(blob, vram)
    starts = set(ents)
    override = {}
    if not tables:
        return sorted(starts), override

    def cur_size(s: int) -> int:
        if s in override:
            return override[s]
        ss = sorted(starts)
        i = bisect.bisect_right(ss, s)
        return (ss[i] if i < len(ss) else end) - s

    for jr, _tab, targets in tables:
        cands = [s for s in starts if s <= jr]
        if not cands:
            continue
        lo = max(cands)
        hi = lo + cur_size(lo)
        changed, guard = True, 0
        while changed and guard < 200:
            changed, guard = False, guard + 1
            # absorber funciones que solapan el rango
            for s in [x for x in starts if lo < x < hi]:
                hi = max(hi, s + cur_size(s))
                changed = True
            # absorber las funciones que contienen cada destino de la tabla
            for t in targets:
                c = [s for s in starts if s <= t]
                if not c:
                    continue
                f = max(c)
                if f < lo:
                    lo = f
                    changed = True
                fe = f + cur_size(f)
                if fe > hi:
                    hi = fe
                    changed = True
            # absorber la función anterior si ramifica hacia dentro del rango
            prev = [s for s in starts if s < lo]
            if prev:
                p = max(prev)
                if _branches_into(blob, vram, p, p + cur_size(p), lo, hi):
                    lo = p
                    changed = True
        for s in [x for x in starts if lo < x < hi]:
            starts.discard(s)
        override[lo] = hi - lo

    return sorted(starts), override


def _plausible_code(blob: bytes, vram: int, addr: int, n: int = 16) -> bool:
    """Heurística anti-datos: la ventana debe decodificar casi entera y sin patrones de data
    (`...($zero)` con offset, `mfc0 $zero`, ...)."""
    off = addr - vram
    insns = list(MD.disasm(blob[off:off + 4 * n], addr))
    if len(insns) < 4:
        return False
    invalid = 0
    bad = 0
    for i in insns:
        if (i.mnemonic.startswith("invalid") or i.mnemonic.startswith("unknown")
                or i.mnemonic in (".byte", ".word", ".long", ".short", ".dword")):
            invalid += 1
            continue
        if "($zero)" in i.op_str:
            imm = i.op_str.split("(")[0].split(",")[-1].strip()
            try:
                if int(imm, 16) != 0:
                    bad += 1
            except ValueError:
                pass
        if i.mnemonic in ("mfc0", "mfc2", "cfc1", "cfc2") and i.op_str.startswith("$zero"):
            bad += 1
    return invalid <= 1 and bad == 0


def self_pointer_mid_entries(blob: bytes, vram: int, ents, override):
    """Direcciones dentro de funciones a las que apunta algún word del propio blob.

    Son candidatas a entradas indirectas (jump-tables, callbacks) que el detector estático no ve;
    el juego las llama con `jalr` y el port necesita una función recompilada en esa dirección."""
    end = vram + len(blob)
    ranges = []
    for k, a in enumerate(ents):
        nxt = ents[k + 1] if k + 1 < len(ents) else end
        ranges.append((a, a + override.get(a, nxt - a)))
    out = set()
    for off in range(0, len(blob) - 3, 4):
        v = struct.unpack_from(">I", blob, off)[0]
        if not (vram <= v < end) or (v - vram) % 4 != 0:
            continue
        for a, hi in ranges:
            if a < v < hi:
                if _plausible_code(blob, vram, v):
                    out.add(v)
                break
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("blob", type=Path)
    ap.add_argument("--vram", type=lambda s: int(s, 16), default=0x80107830)
    ap.add_argument("--rom", type=lambda s: int(s, 16), default=0x0)
    ap.add_argument("--name", default=".module")
    ap.add_argument("--prefix", default="",
                    help="prefijo de los nombres de función (evita colisiones C entre módulos "
                         "que comparten base de VRAM)")
    ap.add_argument("--extra", default="",
                    help="start(s) extra en hex separadas por comas (evidencia runtime)")
    ap.add_argument("--self-pointer-mid-entries", action="store_true",
                    help="añade como entradas los destinos de punteros del blob dentro de funciones "
                         "(jump-tables/callbacks); escribe <out>.keep con las entradas protegidas")
    ap.add_argument("--out", type=Path, required=True)
    ap.add_argument("--filter-data", action="store_true",
                    help="descarta entradas detectadas que no parecen codigo (evita decodificar "
                         "constant pools/datos y fallos de compilacion del C generado)")
    args = ap.parse_args()

    extra = {int(x, 16) for x in args.extra.split(",") if x.strip()}
    blob = args.blob.read_bytes()
    ents = detect_functions(blob, args.vram, extra)
    ents, override = merge_jump_tables(ents, blob, args.vram)
    if args.self_pointer_mid_entries:
        mid = self_pointer_mid_entries(blob, args.vram, ents, override)
        if mid:
            extra |= mid
            ents = detect_functions(blob, args.vram, extra)
            ents, override = merge_jump_tables(ents, blob, args.vram)
        # Lista de entradas protegidas (manuales + auto) para validate_syms --keep-file.
        Path(str(args.out) + ".keep").write_text(
            "\n".join(f"0x{a:08X}" for a in sorted(extra)) + "\n")
    if args.filter_data:
        before = len(ents)
        ents = [a for a in ents
                if a == args.vram or a in extra or _plausible_code(blob, args.vram, a)]
        ents = sorted(ents)
        print(f"  filtro datos: {before - len(ents)} entradas descartadas")
    extra = sorted(extra)
    lines = ["# Módulo: %s — funciones por prólogo+jal+jr-ra; jump-tables fusionadas."
             % args.blob,
             "[[section]]", f'name = "{args.name}"',
             f"rom = 0x{args.rom:X}", f"vram = 0x{args.vram:08X}", f"size = 0x{len(blob):X}", "",
             "functions = ["]
    for k, a in enumerate(ents):
        nxt = ents[k + 1] if k + 1 < len(ents) else args.vram + len(blob)
        size = override.get(a, nxt - a)
        lines.append(f'    {{ name = "{args.prefix}FUN_{a:08x}", vram = 0x{a:08X}, size = 0x{size:X} }},')
    lines.append("]")
    args.out.write_text("\n".join(lines) + "\n")
    print(f"{args.out}: {len(ents)} funciones ({len(override)} con jump-table fusionada)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
