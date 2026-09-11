#!/usr/bin/env python3
"""
setup_module.py — regenera los artefactos del módulo de código Nisitenma idx 7 desde la ROM.

El módulo no está plano en la ROM: Konami lo comprime con **LZKN64** (tabla Nisitenma-Ichigo).
`lzkn64` lo descomprime correctamente a 564464 bytes (CRC32 0xA9213032), así que la extracción es
**determinista y no requiere ejecutar el juego**.

Pasos:
  1) Lee la tabla Nisitenma de la ROM (US @0x39BF0), toma la entrada idx 7 y descomprime con lzkn64
     → work/scratch/module7_be.bin (512 KB de MIPS big-endian).
  2) gen_module_syms.py → config/us_module7.syms.toml (funciones por prólogo+jal+jr-ra).
  3) build ROM combinado: work/scratch/us_combined.z64 = ROM retail + blob en 0x1000000.
  4) validate_syms --fix sobre la syms del módulo (necesita el ROM combinado) → la corrige.
  5) merge (plana + módulo, excluyendo el rango del módulo en la plana) → config/us_combined.syms.toml.
  6) Con --build: recomp.py --config config/game_combined.toml --build.

Uso:
  python3 tools/setup_module.py [--build] [--rom <path>]
"""

import argparse
import struct
import subprocess
import sys
from pathlib import Path

try:
    import tomllib
except ImportError:
    sys.exit("Se requiere Python 3.11+ (tomllib).")

ROOT = Path(__file__).resolve().parents[1]
CONFIG = ROOT / "config"
SCRATCH = ROOT / "work" / "scratch"

TABLE_OFFSET = 0x39BF0          # tabla Nisitenma-Ichigo (US)
MODULE_INDEX = 7                # índice del módulo de código de boot
MODULE_EXPECT_SIZE = 564464     # descomprimido (decompressed_size del manifest)
MODULE_EXPECT_CRC = 0xA9213032
MODULE_VRAM = 0x80107830
MODULE_ROM_OFF = 0x1000000      # offset del blob dentro del ROM combinado
DEFAULT_ROM = ROOT / "work/roms/us_retail.z64"
BLOB = SCRATCH / "module7_be.bin"
COMBINED_ROM = SCRATCH / "us_combined.z64"
FLAT_SYMS = CONFIG / "us_ghidra.syms.toml"
MODULE_SYMS = CONFIG / "us_module7.syms.toml"
COMBINED_SYMS = CONFIG / "us_combined.syms.toml"


def run(cmd):
    print(f"$ {' '.join(str(c) for c in cmd)}")
    return subprocess.call([str(c) for c in cmd])


def extract_blob(rom_path: Path):
    import zlib
    rom = rom_path.read_bytes()
    # tabla Nisitenma: 4 B BE por entrada (bits[0-30]=offset, bit31=comprimido), termina en 0.
    entries = []
    off = TABLE_OFFSET
    while True:
        v = struct.unpack(">I", rom[off:off + 4])[0]
        if v == 0:
            break
        entries.append((v & 0x7FFFFFFF, bool(v & 0x80000000)))
        off += 4
    start, compressed = entries[MODULE_INDEX]
    end = entries[MODULE_INDEX + 1][0]
    if not compressed:
        print(f"[setup] la entrada {MODULE_INDEX} no está comprimida")
        return False

    sys.path.insert(0, str(ROOT / "tools"))
    import lzkn64  # shim del repo
    blob = lzkn64.decompress(rom[start:end])
    crc = zlib.crc32(blob)
    if len(blob) != MODULE_EXPECT_SIZE or crc != MODULE_EXPECT_CRC:
        print(f"[setup] blob inesperado: size={len(blob)} crc=0x{crc:08X}")
        return False
    SCRATCH.mkdir(parents=True, exist_ok=True)
    BLOB.write_bytes(blob)
    print(f"[setup] blob -> {BLOB} ({len(blob)} bytes, CRC 0x{crc:08X})")
    return True


def gen_module_syms():
    return run([sys.executable, ROOT / "tools/analysis/gen_module_syms.py", BLOB,
                "--vram", f"0x{MODULE_VRAM:X}", "--rom", f"0x{MODULE_ROM_OFF:X}",
                "--name", ".module7", "--out", MODULE_SYMS]) == 0


def build_combined_rom(rom_path: Path):
    rom = rom_path.read_bytes()
    if len(rom) != 0x1000000:
        print(f"[setup] ROM inesperada: {len(rom)} bytes")
        return False
    COMBINED_ROM.write_bytes(rom + BLOB.read_bytes())
    print(f"[setup] {COMBINED_ROM} ({0x1000000 + BLOB.stat().st_size} bytes)")
    return True


def fix_module_syms():
    fixed = MODULE_SYMS.with_suffix(".fixed.syms.toml")
    # OJO: rc != 0 si el input tiene ramas cruzadas (esperado); lo que importa es el resultado.
    run([sys.executable, ROOT / "tools/analysis/validate_syms.py", MODULE_SYMS,
         "--rom", COMBINED_ROM, "--fix", "--out", fixed])
    if not fixed.exists():
        return False
    if run([sys.executable, ROOT / "tools/analysis/validate_syms.py", fixed, "--rom", COMBINED_ROM]) != 0:
        return False
    MODULE_SYMS.write_bytes(fixed.read_bytes())
    print(f"[setup] módulo validado/corregido -> {MODULE_SYMS}")
    return True


def merge_syms():
    flat = tomllib.loads(FLAT_SYMS.read_text())["section"][0]
    mod = tomllib.loads(MODULE_SYMS.read_text())["section"][0]
    lo, hi = MODULE_VRAM, MODULE_VRAM + BLOB.stat().st_size
    ff = [f for f in flat["functions"] if not (lo <= f["vram"] < hi)]

    def sect(comment, name, rom, vram, size, funcs):
        out = [comment, "[[section]]", f'name = "{name}"', f"rom = 0x{rom:X}",
               f"vram = 0x{vram:08X}", f"size = 0x{size:X}", "", "functions = ["]
        out += [f'    {{ name = "{f["name"]}", vram = 0x{f["vram"]:08X}, size = 0x{f["size"]:X} }},'
                for f in funcs]
        out.append("]")
        return out

    lines = ["# Syms combinada: imagen plana + módulo idx 7 (2ª sección). Generada por setup_module.py."]
    lines += sect("# plana (sin data-as-code del rango del módulo)", ".text", 0x1000, 0x80000400,
                  0x4E5B40, ff)
    lines.append("")
    lines += sect("# módulo Nisitenma idx 7", ".module7", MODULE_ROM_OFF, MODULE_VRAM,
                  BLOB.stat().st_size, mod["functions"])
    COMBINED_SYMS.write_text("\n".join(lines) + "\n")
    print(f"[setup] {COMBINED_SYMS} (plana {len(ff)} + módulo {len(mod['functions'])})")
    return True


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", type=Path, default=DEFAULT_ROM)
    ap.add_argument("--build", action="store_true")
    args = ap.parse_args()

    if not args.rom.exists():
        print(f"[setup] falta la ROM: {args.rom}")
        return 1

    if not extract_blob(args.rom):
        return 1
    if not build_combined_rom(args.rom):
        return 1
    if not gen_module_syms():
        return 1
    if not fix_module_syms():
        return 1
    if not merge_syms():
        return 1

    print("\n[setup] listo. Para recompilar el set combinado y construir:")
    print("  python3 tools/recomp.py --config config/game_combined.toml --build")
    if args.build:
        return run([sys.executable, ROOT / "tools/recomp.py", "--config",
                    "config/game_combined.toml", "--build"])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
