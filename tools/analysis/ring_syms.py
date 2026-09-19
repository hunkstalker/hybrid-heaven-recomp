#!/usr/bin/env python3
"""Simboliza las lineas de anillo/pila de hh_hang.log y hh_slice.log.

Uso:
    python3 tools/analysis/ring_syms.py <log> [<log2> ...] [--all]

Lee `ultimas llamadas:` y `callring:` (hex) de los logs y mapea cada direccion a
`nombre+0xoffset` usando config/us_combined.syms.toml. Si varias funciones
contienen la direccion (modulos solapados), se lista la de menor tamano; con
--all se listan todas.

Salida pensada para pegar en notas: una linea por anillo.
"""
import re
import sys
from pathlib import Path

try:
    import tomllib
except ImportError:  # pragma: no cover
    tomllib = None

ROOT = Path(__file__).resolve().parents[2]
SYMS = ROOT / "config" / "us_combined.syms.toml"

RING_RE = re.compile(r"(?:ultimas llamadas|callring):\s*((?:[0-9A-Fa-f]{8}\s*)+)")


def load_syms(path: Path):
    funcs = []
    if tomllib is not None:
        with open(path, "rb") as f:
            data = tomllib.load(f)
        for section in data.get("section", []):
            for fn in section.get("functions", []):
                funcs.append((int(fn["vram"]), int(fn.get("size", 0)), str(fn["name"])))
    else:  # fallback regex
        text = path.read_text(encoding="utf-8", errors="replace")
        for m in re.finditer(
            r'\{\s*name\s*=\s*"([^"]+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)\s*,\s*size\s*=\s*(0x[0-9A-Fa-f]+)\s*\}',
            text,
        ):
            funcs.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
    return funcs


def symbolize(addr: int, funcs, show_all: bool = False):
    hits = []
    for vram, size, name in funcs:
        if size and vram <= addr < vram + size:
            hits.append((size, vram, name))
    if not hits:
        return "?"
    hits.sort()
    if show_all:
        return " | ".join(f"{name}+0x{addr - vram:X}" for _, vram, name in hits)
    size, vram, name = hits[0]
    return f"{name}+0x{addr - vram:X}"


def main(argv):
    show_all = "--all" in argv
    paths = [a for a in argv if not a.startswith("--")]
    if not paths:
        print(__doc__)
        return 1
    funcs = load_syms(SYMS)
    print(f"# syms: {SYMS.relative_to(ROOT)} ({len(funcs)} funciones)")
    for p in paths:
        path = Path(p)
        print(f"## {path}")
        for lineno, line in enumerate(path.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
            m = RING_RE.search(line)
            if not m:
                continue
            addrs = [int(tok, 16) for tok in m.group(1).split()]
            print(f"  L{lineno}:")
            for a in addrs:
                print(f"    {a:08X}  {symbolize(a, funcs, show_all)}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
