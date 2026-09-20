#!/usr/bin/env python3
"""gen_file_table.py — genera `include/hh/file_table.h` (id -> {vram,size}) desde el manifiesto.

`kCodeFiles[]` va en el **mismo orden que `config/code_files.overlays.txt`** (= orden de id), que es
tambien el orden de `overlay_sections_by_index` generado por N64Recomp. Ese invariante permite que
`load_overlay_by_id(i)` / `unload_overlay_by_id(i)` usen el indice de `kCodeFiles` directamente.

Uso:  python3 tools/gen_file_table.py [--out port/HybridHeavenRecomp/include/hh/file_table.h]
"""

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "config/code_files.json"
DEFAULT_OUT = ROOT / "port/HybridHeavenRecomp/include/hh/file_table.h"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--out", type=Path, default=DEFAULT_OUT)
    args = ap.parse_args()

    m = json.loads(MANIFEST.read_text())
    files = m["code_files"]
    lines = [
        "// Generado por tools/gen_file_table.py -- no editar a mano.",
        "// Code files del Nisitenma-Ichigo, en el MISMO orden que code_files.overlays.txt",
        "// (y por tanto que overlay_sections_by_index de N64Recomp). Ver docs/adr/0009.",
        "#pragma once",
        "#include <cstdint>",
        "",
        "namespace hh {",
        "",
        "struct CodeFile {",
        "    uint32_t id;     // id Nisitenma (1..0x270)",
        "    uint32_t vram;   // direccion de enlace (base de la seccion)",
        "    uint32_t size;   // tamano de la seccion (text+data+bss)",
        "};",
        "",
        "// Orden = orden de code_files.overlays.txt = orden de overlay_sections_by_index.",
        "static const CodeFile kCodeFiles[] = {",
    ]
    for c in files:
        lines.append("    { %3d, 0x%08X, 0x%X },  // %s (rom 0x%s)"
                     % (c["idx"], int(c["vram"], 16), c["size"], c["file"], c["src_rom"][2:]))
    lines += [
        "};",
        "",
        "static constexpr size_t kCodeFileCount = sizeof(kCodeFiles) / sizeof(kCodeFiles[0]);",
        "",
        "}  // namespace hh",
        "",
    ]
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("\n".join(lines))
    print("gen_file_table: %s (%d code files)" % (args.out, len(files)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
