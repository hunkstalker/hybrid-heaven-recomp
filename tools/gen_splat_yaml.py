#!/usr/bin/env python3
"""gen_splat_yaml.py — escribe `recomp/hybrid-heaven.us.yaml` (config de splat) desde
`work/scratch/expanded/segments.json`.

Reglas de segmento (vía ELF, ADR 0011):
- `resident` (imagen de boot) y `file_008` (motor, cargado una vez en una dirección que nada más
  usa) son **globales**: el resto ve sus símbolos.
- El resto de code files comparten `exclusive_ram_id: overlay`: ocupan las mismas direcciones y una
  referencia de un fichero a la ventana de otro solo se resuelve en runtime; con un id compartido,
  splat no la ata a un fichero concreto (queda indefinida y va por lookup al recompilar).
- Por fichero: texto hasta justo tras el último `jr $ra`, luego datos, luego bss hasta el fin de su
  rango de vram.
- `asm_data_macro: dlabel` / `asm_jtbl_label_macro: jlabel`: datos y jump-tables no se tipan como
  funciones (N64Recomp tomaría todo FUNC como código).

Uso:  python3 tools/gen_splat_yaml.py
"""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SEGMENTS = ROOT / "work/scratch/expanded/segments.json"
YAML = ROOT / "recomp/hybrid-heaven.us.yaml"
GLOBAL_FILES = {8}

HEADER = """\
# Config de splat para Hybrid Heaven (USA), NHVE.
# GENERADO por tools/gen_splat_yaml.py desde work/scratch/expanded/segments.json.
# No hay decompilacion: cada frontera se midio (tools/unpack_rom.py).
# Divide work/scratch/expanded/hh.expanded.z64 (no el cartucho): los code files estan
# descomprimidos en offsets sinteticos >16 MB.

name: Hybrid Heaven (USA)

options:
  basename: hybrid-heaven
  target_path: work/scratch/expanded/hh.expanded.z64
  base_path: ..
  platform: n64
  compiler: GCC

  asm_path: asm
  data_path: asm/data
  src_path: src_unused
  build_path: build-elf
  asset_path: work/scratch/expanded/assets

  create_c_files: False
  create_asm_dependencies: False
  migrate_rodata_to_functions: False
  disassemble_all: True

  symbol_name_format: $VRAM_$ROM
  symbol_name_format_no_rom: $VRAM_$SEG

  ld_script_path: recomp/hybrid-heaven.us.ld
  symbol_addrs_path:
    - recomp/symbol_addrs.txt
    - recomp/auto_funcs.txt
  undefined_funcs_auto_path: recomp/undefined_funcs_auto.txt
  undefined_syms_auto_path: recomp/undefined_syms_auto.txt

  asm_function_macro: glabel
  asm_data_macro: dlabel
  asm_jtbl_label_macro: jlabel

  find_file_boundaries: False
  use_legacy_include_asm: False
  asm_inc_header: ""

segments:
  - name: header
    type: header
    start: 0x0

  - name: ipl3
    type: bin
    start: 0x40
"""


def main() -> int:
    if not SEGMENTS.exists():
        sys.exit("run tools/unpack_rom.py first")
    seg = json.loads(SEGMENTS.read_text())
    r = seg["resident"]
    out = [HEADER]
    out.append("""
  - name: resident
    type: code
    start: 0x%X
    vram: 0x%08X
    bss_size: 0x%X
    subsegments:
      - [0x%X, asm, resident]
      - [0x%X, data, resident_data]
      - { start: 0x%X, type: bss, vram: 0x%08X, name: resident_bss }

  - name: gap
    type: bin
    start: 0x%X
""" % (r["rom"], r["vram"], r["bss_size"],
       r["rom"], r["rom"] + r["text_size"],
       r["rom"] + r["size"], r["vram"] + r["size"],
       r["rom"] + r["size"]))

    for f in seg["files"]:
        name = "file_%03d" % f["id"]
        exclusive = "" if f["id"] in GLOBAL_FILES else "    exclusive_ram_id: overlay\n"
        subs = ["      - [0x%X, asm, %s]" % (f["rom"], name)] if f["text_size"] else []
        if f["size"] > f["text_size"]:
            subs.append("      - [0x%X, data, %s_data]" % (f["rom"] + f["text_size"], name))
        if f["bss_size"]:
            subs.append("      - { start: 0x%X, type: bss, vram: 0x%08X, name: %s_bss }" % (
                f["rom"] + f["size"], f["vram"] + f["size"], name))
        out.append("""
  - name: %s
    type: code
    start: 0x%X
    vram: 0x%08X
    bss_size: 0x%X
%s    subsegments:
%s
""" % (name, f["rom"], f["vram"], f["bss_size"], exclusive, "\n".join(subs)))

    last = seg["files"][-1]
    end = (last["rom"] + last["size"] + 15) & ~15
    out.append("\n  - [0x%X]\n" % end)

    YAML.write_text("".join(out), newline="\n")
    print("wrote %s: resident + %d code files" % (YAML.relative_to(ROOT), len(seg["files"])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
