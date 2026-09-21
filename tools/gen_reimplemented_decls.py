#!/usr/bin/env python3
# Adaptado del tooling del port de referencia (MIT); ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt.
"""gen_reimplemented_decls.py — declara las funciones libultra que provee el runtime (vía ELF).

N64Recomp renombra a `<name>_recomp` las funciones de sus listas (reimplemented/ignored/renamed) y
delega en el runtime; el C generado las llama, pero funcs.h solo declara las recompiladas, así que sin
estas declaraciones el build falla por declaración implícita. La lista se lee del propio tool
(`toolchain/.../symbol_lists.cpp`), así no puede desincronizarse.

Escribe `work/recomp_elf/RecompiledFuncs/reimplemented_decls.h` (referenciado por `recomp_include` del
TOML). Uso: python3 tools/gen_reimplemented_decls.py
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "toolchain/src/N64Recomp/src/symbol_lists.cpp"
OUT = ROOT / "work/recomp_elf/RecompiledFuncs/reimplemented_decls.h"
CONFIG = ROOT / "recomp/hybrid-heaven.us.toml"
GUARD = "HH_REIMPLEMENTED_DECLS_H"


def main() -> int:
    if not SOURCE.exists():
        sys.exit("falta %s" % SOURCE)
    text = SOURCE.read_text(errors="replace")
    names = set()
    for list_name in ("reimplemented_funcs", "ignored_funcs", "renamed_funcs"):
        m = re.search(list_name + r"\s*\{(.*?)\n\};", text, re.S)
        if not m:
            sys.exit("no encuentro la lista %s" % list_name)
        found = re.findall(r'"([A-Za-z_]\w*)"', m.group(1))
        print("  %-22s %d" % (list_name, len(found)))
        names.update(found)
    names = sorted(names)
    if not names:
        sys.exit("listas de simbolos vacias")

    ours = []
    if CONFIG.exists():
        block = re.search(r"^ignored\s*=\s*\[(.*?)\]", CONFIG.read_text(), re.S | re.M)
        if block:
            ours = sorted(set(re.findall(r'"([A-Za-z_]\w*)"', block.group(1))))

    OUT.parent.mkdir(parents=True, exist_ok=True)
    lines = [
        "/* Generado por tools/gen_reimplemented_decls.py -- no editar. */\n",
        "#ifndef " + GUARD + "\n#define " + GUARD + "\n\n",
        '#include "recomp.h"\n\n',
        "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n",
    ]
    for name in names:
        lines.append("void %s_recomp(uint8_t* rdram, recomp_context* ctx);\n" % name)
    if ours:
        lines.append("\n/* Provistas por patches/, marcadas `ignored` en el TOML. */\n")
        for name in ours:
            lines.append("void %s(uint8_t* rdram, recomp_context* ctx);\n" % name)
    lines += ["\n#ifdef __cplusplus\n}\n#endif\n\n#endif\n"]
    OUT.write_text("".join(lines))
    print("wrote %s (%d declaraciones)" % (OUT.relative_to(ROOT), len(names)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
