#!/usr/bin/env python3
# Adaptado del tooling del port de referencia (MIT); ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt.
"""gen_runtime_func_table.py — registra las funciones libultra del runtime en su dirección de cartucho.

Con `use_lookup_for_all_function_calls`, cada llamada es un lookup por dirección; las funciones que
N64Recomp delega al runtime (`<name>_recomp`) no están en ninguna tabla de sección, así que hay que
registrarlas en la dirección que ocupaban en el cartucho (`add_loaded_function`). Si no, la primera
llamada es un lookup miss ("Failed to find function at ...").

Solo se registran las que tienen definición real (se escanean las fuentes del runtime), para no
referenciar nombres sin definición (error de enlace).

Escribe `work/recomp_elf/RecompiledFuncs/runtime_funcs.inl`.
Uso: python3 tools/gen_runtime_func_table.py
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "work/recomp_elf/RecompiledFuncs"
OUT = GENERATED / "runtime_funcs.inl"
ELF = "elf/hybrid-heaven.us.elf"
CONFIG = ROOT / "recomp/hybrid-heaven.us.toml"
RUNTIME_SRC = ROOT / "port/HybridHeavenRecomp/lib/N64ModernRuntime/librecomp/src"
PORT_SRC = ROOT / "port/HybridHeavenRecomp/src"


def defined_recomp_functions():
    names = set()
    pattern = re.compile(r"\bvoid\s+(\w+)_recomp\s*\(\s*(?:uint8_t\s*\*|RDRAM_ARG\b)")
    for src in list(RUNTIME_SRC.glob("*.cpp")) + list(PORT_SRC.rglob("*.cpp")):
        names.update(pattern.findall(src.read_text(errors="replace")))
    return names


def patched_functions():
    if not CONFIG.exists():
        return set()
    block = re.search(r"^ignored\s*=\s*\[(.*?)\]", CONFIG.read_text(), re.S | re.M)
    if not block:
        return set()
    ignored = set(re.findall(r'"([A-Za-z_]\w*)"', block.group(1)))
    defined = set()
    pattern = re.compile(r"\bvoid\s+(\w+)\s*\(\s*uint8_t\s*\*\s*rdram\s*,\s*recomp_context")
    for src in PORT_SRC.rglob("*.cpp"):
        defined.update(pattern.findall(src.read_text(errors="replace")))
    return ignored & defined


def symbol_addresses():
    out = subprocess.run(["llvm-readelf", "-sW", ELF], capture_output=True, text=True).stdout
    addresses = {}
    for line in out.splitlines():
        m = re.match(r"\s*\d+:\s+([0-9a-f]{8})\s+\d+\s+FUNC\s+\S+\s+\S+\s+\S+\s+(\S+)$", line)
        if m:
            addresses.setdefault(m.group(2), int(m.group(1), 16))
    return addresses


def main() -> int:
    if not GENERATED.exists():
        sys.exit("falta %s; recompila primero" % GENERATED)
    called = defined_recomp_functions()
    addresses = symbol_addresses()

    entries, unresolved = [], []
    for name in sorted(called):
        addr = addresses.get(name)
        if addr is None:
            unresolved.append(name)
        else:
            entries.append((addr, name))

    lines = [
        "/* Generado por tools/gen_runtime_func_table.py -- no editar. */\n",
        '#include "reimplemented_decls.h"\n\n',
        "static const struct { uint32_t ram_addr; recomp_func_t* func; }\n",
        "runtime_provided_funcs[] = {\n",
    ]
    for addr, name in entries:
        lines.append("    { 0x%08Xu, %s_recomp },\n" % (addr, name))
    lines.append("};\n")
    OUT.write_text("".join(lines))
    print("wrote %s" % OUT.relative_to(ROOT))
    print("  definiciones _recomp : %d" % len(called))
    print("  registradas          : %d" % len(entries))
    if unresolved:
        print("  sin direccion en ELF : %d" % len(unresolved))
        for n in unresolved[:8]:
            print("      %s" % n)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
