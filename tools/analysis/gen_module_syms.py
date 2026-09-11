#!/usr/bin/env python3
"""
gen_module_syms.py — genera la syms de un blob de módulo MIPS (big-endian) por detección
de funciones con capstone:
  - inicio del blob,
  - prólogos `addiu $sp, $sp, -N`,
  - destinos de `jal`/`bal` internos,
  - dirección siguiente al delay-slot de cada `jr $ra` (fin de función → posible nueva).

Uso:
  python3 tools/analysis/gen_module_syms.py <blob_be.bin> --vram 0x80107830 \
      --rom 0x1000000 --out config/us_module7.syms.toml
"""

import argparse
from pathlib import Path

import capstone

MD = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_BIG_ENDIAN)
MD.skipdata = True


def detect_functions(blob: bytes, vram: int):
    end = vram + len(blob)
    entries = {vram}
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
    ents = sorted(a for a in entries if vram <= a < end)
    return ents


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("blob", type=Path)
    ap.add_argument("--vram", type=lambda s: int(s, 16), default=0x80107830)
    ap.add_argument("--rom", type=lambda s: int(s, 16), default=0x0)
    ap.add_argument("--name", default=".module")
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()

    blob = args.blob.read_bytes()
    ents = detect_functions(blob, args.vram)
    lines = [f"# Módulo: {args.blob} — funciones por prólogo+jal+jr-ra.",
             "[[section]]", f'name = "{args.name}"',
             f"rom = 0x{args.rom:X}", f"vram = 0x{args.vram:08X}", f"size = 0x{len(blob):X}", "",
             "functions = ["]
    for k, a in enumerate(ents):
        end = ents[k + 1] if k + 1 < len(ents) else args.vram + len(blob)
        lines.append(f'    {{ name = "FUN_{a:08x}", vram = 0x{a:08X}, size = 0x{end - a:X} }},')
    lines.append("]")
    args.out.write_text("\n".join(lines) + "\n")
    print(f"{args.out}: {len(ents)} funciones")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
