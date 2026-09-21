#!/usr/bin/env python3
"""
add_missing_funcs.py — añade funciones que faltan en la syms a partir de un log de boot.

La detección estática es poco fiable en este binario (jump-tables → falsos positivos). La fuente
fiable es la evidencia en runtime: `Failed to find function at 0xXXXXXXXX`. Esta herramienta:
  - parsea esas direcciones del log,
  - para cada una, la añade a la syms (dividiendo la función que la contiene si aplica),
  - escribe la syms corregida.

Es determinista, idempotente y precisa: solo añade lo que el juego realmente llama.

Uso:
  python3 tools/analysis/add_missing_funcs.py --syms <syms> --log <boot.log> [--out <out>]
  (repite: regenerar → build → run → add_missing_funcs, hasta que no haya fallos)
"""

import argparse
import re
import sys
from pathlib import Path

try:
    import tomllib
except ImportError:
    sys.exit("Se requiere Python 3.11+ (tomllib).")

ADDR_RE = re.compile(r"Failed to find function at 0x([0-9A-Fa-f]+)")
FUNC_RE = re.compile(
    r'\{\s*name\s*=\s*"(\w+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)\s*,\s*size\s*=\s*(0x[0-9A-Fa-f]+)\s*\}')


def load_syms(path: Path):
    data = tomllib.loads(path.read_text())
    return [{"name": s.get("name", ""), "rom": s["rom"], "vram": s["vram"], "size": s["size"],
             "functions": [dict(f) for f in s.get("functions", [])]}
            for s in data.get("section", [])]


def add_address(funcs, addr):
    """Añade `addr` como función; si está dentro de otra, la divide. Devuelve True si cambió."""
    if any(f["vram"] == addr for f in funcs):
        return False
    # contenedor
    cont = next((f for f in funcs if f["vram"] < addr < f["vram"] + f["size"]), None)
    if cont is not None:
        cont["size"] = addr - cont["vram"]
    # siguiente inicio para dimensionar
    starts = sorted(f["vram"] for f in funcs) + [addr]
    nxt = min((s for s in starts if s > addr), default=None)
    size = (nxt - addr) if nxt is not None else 4
    funcs.append({"name": f"FUN_{addr:08x}", "vram": addr, "size": size})
    funcs.sort(key=lambda f: f["vram"])
    return True


def write_syms(src: Path, dst: Path, secs):
    parts = re.split(r"(?m)^\[\[section\]\]\s*$", src.read_text())
    out = [parts[0].rstrip("\n"), ""]
    for idx, s in enumerate(secs):
        out += ["[[section]]", f'name = "{s["name"]}"', f'rom = 0x{s["rom"]:X}',
                f'vram = 0x{s["vram"]:08X}', f'size = 0x{s["size"]:X}', "", "functions = ["]
        for f in s["functions"]:
            out.append(f'    {{ name = "{f["name"]}", vram = 0x{f["vram"]:08X}, size = 0x{f["size"]:X} }},')
        out += ["]", ""]
    dst.write_text("\n".join(out).rstrip("\n") + "\n")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--syms", type=Path, required=True)
    ap.add_argument("--log", type=Path, required=True)
    ap.add_argument("--out", type=Path)
    args = ap.parse_args()

    addrs = sorted({int(m, 16) for m in ADDR_RE.findall(args.log.read_text(errors="replace"))})
    secs = load_syms(args.syms)
    added = []
    for a in addrs:
        sec = next((s for s in secs if s["vram"] <= a < s["vram"] + s["size"]), None)
        if sec is None:
            print(f"  (fuera de sección) 0x{a:08X}")
            continue
        if add_address(sec["functions"], a):
            added.append(a)

    print(f"log: {args.log}  direcciones: {len(addrs)}  añadidas: {len(added)}")
    for a in added:
        print(f"   + 0x{a:08X}")
    if added:
        out = args.out or args.syms
        write_syms(args.syms, out, secs)
        print(f"escrito: {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
