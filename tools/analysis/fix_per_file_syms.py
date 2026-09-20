#!/usr/bin/env python3
"""fix_per_file_syms.py — corrige las fronteras de una syms per-file salida de Ghidra.

Ghidra da fronteras buenas pero:
  - **excluye el delay slot** del cuerpo (`getBody()` no lo cuenta) → `size += 4` al final;
  - **parte funciones con `switch`** (cada `case` acaba en `jr $ra`); N64Recomp exige que todas
    las entradas de la jump-table caigan dentro de la función que hace `jr $reg`;
  - **trunca funciones que acaban en `jal`/`jalr`** (la continuación quedó como otra función).

Este paso:
  1. hace las funciones **contiguas** dentro de `[vram, text_end)` (tamaño = siguiente inicio);
  2. **fusiona continuaciones**: mientras la última instrucción sea un branch con enlace
     (`jal`/`jalr`/`bal`), absorbe la función siguiente;
  3. ejecuta el merge de **jump-tables** de `gen_module_syms.py` (capstone);
  4. descarta inicios fuera de `text_end` (datos).

Uso:
  python3 tools/analysis/fix_per_file_syms.py <syms.toml> <blob.bin> \
      --vram 0x80358820 --text-end 0x803854D0 --out <fixed.toml>
"""

import argparse
import bisect
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import capstone  # noqa: E402
import gen_module_syms as gms  # noqa: E402

MD = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_BIG_ENDIAN)


def _last_is_link_branch(blob: bytes, vram: int, addr: int) -> bool:
    off = addr - vram
    if off < 0 or off + 4 > len(blob):
        return False
    ins = list(MD.disasm(blob[off:off + 4], addr))
    if not ins:
        return False
    m = ins[0].mnemonic
    return m in ("jal", "jalr", "bal", "jalx")


# Terminadores validos de una funcion (fin de bloque): si el limite NO acaba en uno de estos, la
# funcion cae (fall-through) en la contigua -> Ghidra la partio mal y hay que fusionarlas.
_TERMINATORS = {
    "jr", "j", "jal", "jalr", "jalx", "jr.hb", "j.hb",
    # ramas condicionales (tienen delay slot; el fall-through continua, pero N64Recomp las maneja)
    "b", "beq", "bne", "beqz", "bnez", "blez", "bgtz", "bltz", "bgez",
    "beql", "bnel", "beqzl", "bnezl", "blezl", "bgtzl", "bltzl", "bgezl",
    "bal", "bltzal", "bgezal", "bltzall", "bgezall",
    "bc1f", "bc1t", "bc1fl", "bc1tl",
    "syscall", "break",
}


def _last_is_non_terminator(blob: bytes, vram: int, addr: int) -> bool:
    """True si la funcion cae (fall-through) en la contigua: ni la ultima ni la penultima
    instruccion son terminador NI `nop` (padding de alineacion entre funciones).

    `lui; lhu` seguido de la continuacion = Ghidra partio a mitad -> fusionar.
    `jr ra; nop`, `nop; nop` (padding) = fin valido -> NO fusionar.
    """
    off = addr - vram
    if off - 8 < 0 or off > len(blob):
        return False
    ins = list(MD.disasm(blob[off - 8:off], addr - 8))
    if len(ins) < 2:
        return False
    for i in ins[-2:]:
        if i.mnemonic in _TERMINATORS or i.mnemonic == "nop":
            return False
    return True


def load_syms(path: Path):
    import tomllib
    sec = tomllib.loads(path.read_text())["section"][0]
    return sec


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("syms", type=Path)
    ap.add_argument("blob", type=Path)
    ap.add_argument("--vram", type=lambda s: int(s, 16), required=True)
    ap.add_argument("--text-end", type=lambda s: int(s, 16), required=True)
    ap.add_argument("--out", type=Path, required=True)
    ap.add_argument("--extra-targets", type=Path,
                    help="fichero con direcciones (0x...) que deben ser inicios de funcion "
                         "(destinos de jal cross-file; ver ghidra_sections.compute_jal_targets)")
    args = ap.parse_args()

    sec = load_syms(args.syms)
    blob = args.blob.read_bytes()
    vram = args.vram
    text_end = args.text_end

    starts = sorted({f["vram"] for f in sec["functions"] if vram <= f["vram"] < text_end})
    if not starts or starts[0] != vram:
        starts = sorted(set(starts) | {vram})
    # inicios extra (jal cross-file u otros): dentro de [vram, text_end). Son fronteras REALES
    # (alguien los llama); el merge no debe re-absorberlos.
    forced = set()
    if args.extra_targets and args.extra_targets.exists():
        for line in args.extra_targets.read_text().split():
            a = int(line, 16)
            if vram <= a < text_end:
                starts.append(a)
                forced.add(a)
    starts = sorted(set(starts))

    # 2) fusionar continuaciones de link branches (con tamaño contiguo provisional).
    changed = True
    while changed:
        changed = False
        new = list(starts)
        for i in range(len(starts) - 1):
            nxt = starts[i + 1]
            if nxt in forced:
                continue
            # link branch al final -> siempre es continuacion (la funcion no ha terminado).
            link_branch = _last_is_link_branch(blob, vram, nxt - 4)
            # split DIMINUTO sin terminador (<= 2 instrucciones): caso `lui; lhu` de Ghidra.
            tiny_split = (nxt - starts[i]) <= 8 and _last_is_non_terminator(blob, vram, nxt)
            if link_branch or tiny_split:
                new.remove(nxt)
                changed = True
                break
        starts = sorted(set(new))

    # 3) merge de jump-tables (también absorbe la función anterior que ramifica dentro).
    starts, override = gms.merge_jump_tables(starts, blob, vram)
    starts = sorted(set(starts) | {vram})

    # 1) tamaños contiguos (con override de las jump-table).
    out_lines = ["[[section]]", 'name = "%s"' % sec["name"],
                 "rom = 0x%X" % sec["rom"], "vram = 0x%08X" % vram,
                 "size = 0x%X" % sec["size"], "", "functions = ["]
    for k, a in enumerate(starts):
        nxt = starts[k + 1] if k + 1 < len(starts) else text_end
        size = override.get(a, nxt - a)
        out_lines.append('    { name = "func_%08X_%06X", vram = 0x%08X, size = 0x%X },'
                         % (a, sec["rom"], a, size))
    out_lines.append("]")
    args.out.write_text("\n".join(out_lines) + "\n")
    print("%s: %d -> %d funciones (%d jump-tables fusionadas)"
          % (args.out.name, len(sec["functions"]), len(starts), len(override)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
