#!/usr/bin/env python3
"""
setup_module.py — regenera los artefactos de los módulos de código (Nisitenma) desde la ROM.

Los módulos de código no están planos en la ROM: Konami los comprime con **LZKN64** (tabla
Nisitenma-Ichigo). `lzkn64` los descomprime correctamente, así que la extracción es **determinista
y no requiere ejecutar el juego**.

Modelo (ADR 0001): cada módulo se pre-recompila como una **sección** con `vram` = su base
determinista. La base se mide con el port (dir `trans` en 0x8008DFC0) y es estable entre runs.

Pasos:
  1) Lee la tabla Nisitenma de la ROM (US @0x39BF0) y descomprime cada módulo con lzkn64
     → work/scratch/module<idx>_be.bin (MIPS big-endian).
  2) gen_module_syms.py → config/us_module<idx>.syms.toml (funciones por prólogo+jal+jr-ra).
  3) build ROM combinado: work/scratch/us_combined.z64 = ROM retail + blobs en sus offsets.
  4) validate_syms --fix sobre cada syms de módulo (contra el ROM combinado) → la corrige.
  5) merge (plana + secciones de módulos, excluyendo en la plana lo que solapa los módulos)
     → config/us_combined.syms.toml.
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
DEFAULT_ROM = ROOT / "work/roms/us_retail.z64"
COMBINED_ROM = SCRATCH / "us_combined.z64"
FLAT_SYMS = CONFIG / "us_ghidra.syms.toml"
COMBINED_SYMS = CONFIG / "us_combined.syms.toml"
MODULE_SOURCES_INC = ROOT / "port/HybridHeavenRecomp/src/main/module_sources.inc"
MODULE_EXTRAS = {}
KEEP_SYMS = CONFIG / "keep_syms.txt"
KEEP_SYMS_FLAT = CONFIG / "keep_syms_flat.txt"
FLAT_SECTION = {"name": ".text", "rom": 0x1000, "vram": 0x80000400, "size": 0x4E5B40}

# Módulos pre-recompilados: (índice Nisitenma, base RAM determinista, offset en el ROM combinado).
# `src_rom` = offset del blob comprimido en la ROM retail (lo que el juego pasa al loader
# `FUN_80003824` como a0); se usa para registrar la sección en su base de runtime (reutilización
# de bases: p.ej. idx 24 reemplaza a idx 23 en 0x801BF1A0).
# `extra`: funciones no detectables estáticamente (punteros de función), halladas por evidencia
# runtime (`Failed to find function at 0x...`). Ver `docs/workflows.md` §5.
MODULES = [
    {"index": 7,  "vram": 0x80107830, "rom_off": 0x1000000, "name": ".module7",
     "src_rom": 0x4E69A8, "crc": 0xA9213032, "extra": []},
    {"index": 23, "vram": 0x801BF1A0, "rom_off": 0x3000000, "name": ".module23",
     "src_rom": 0x5F1190, "crc": 0x17AE0EEF, "extra": [0x801C0C08]},
    {"index": 54, "vram": 0x803837E0, "rom_off": 0x2000000, "name": ".module54",
     "src_rom": 0x68BF26, "crc": 0x486A3F0F, "extra": [0x80383D00]},
    {"index": 24, "vram": 0x801BF1A0, "rom_off": 0x4000000, "name": ".module24",
     "src_rom": 0x5FBEC6, "crc": 0x0E9EA703, "extra": [0x801BF610, 0x801BF61C, 0x801CDBF0, 0x801C2420], "auto_mid": True},
    {"index": 25, "vram": 0x801E1BE0, "rom_off": 0x5000000, "name": ".module25",
     "src_rom": 0x60F476, "crc": 0xE0934827, "extra": [], "auto_mid": True},
    {"index": 99, "vram": 0x8038B7E0, "rom_off": 0x6000000, "name": ".module99",
     "src_rom": 0x6DCA78, "crc": 0x349278F3, "extra": [], "auto_mid": True},
    {"index": 8,  "vram": 0x801BF1A0, "rom_off": 0x7000000, "name": ".module8",
     "src_rom": 0x53C77C, "crc": 0xA5222066, "extra": [], "auto_mid": True, "filter_data": True},
    {"index": 9,  "vram": 0x801E4AA0, "rom_off": 0x8000000, "name": ".module9",
     "src_rom": 0x5557F4, "crc": 0xF0872236, "extra": [0x801FF260], "auto_mid": True, "filter_data": True},
    {"index": 10, "vram": 0x8021B150, "rom_off": 0x9000000, "name": ".module10",
     "src_rom": 0x57A3B2, "crc": 0x0F984BAB, "extra": [], "auto_mid": True, "filter_data": True},
    {"index": 12, "vram": 0x802408F0, "rom_off": 0xA000000, "name": ".module12",
     "src_rom": 0x599670, "crc": 0x49C1F652, "extra": [], "auto_mid": True, "filter_data": True},
    {"index": 55, "vram": 0x803757E0, "rom_off": 0xB000000, "name": ".module55",
     "src_rom": 0x68FF2C, "crc": 0x65E2C5AB, "extra": [], "auto_mid": True, "filter_data": True},
]


def run(cmd):
    print(f"$ {' '.join(str(c) for c in cmd)}")
    return subprocess.call([str(c) for c in cmd])


def read_file_table(rom: bytes):
    entries = []
    off = TABLE_OFFSET
    while True:
        v = struct.unpack(">I", rom[off:off + 4])[0]
        if v == 0:
            break
        entries.append((v & 0x7FFFFFFF, bool(v & 0x80000000)))
        off += 4
    return entries


def blob_path(mod):
    return SCRATCH / f"module{mod['index']}_be.bin"


def module_syms_path(mod):
    return CONFIG / f"us_module{mod['index']}.syms.toml"


def extract_blobs(rom_path: Path):
    import zlib
    sys.path.insert(0, str(ROOT / "tools"))
    import lzkn64  # shim del repo

    rom = rom_path.read_bytes()
    entries = read_file_table(rom)
    SCRATCH.mkdir(parents=True, exist_ok=True)
    for mod in MODULES:
        idx = mod["index"]
        start, compressed = entries[idx]
        end = entries[idx + 1][0]
        if not compressed:
            print(f"[setup] la entrada {idx} no está comprimida")
            return False
        blob = lzkn64.decompress(rom[start:end])
        crc = zlib.crc32(blob)
        if crc != mod["crc"]:
            print(f"[setup] blob idx {idx} inesperado: size={len(blob)} crc=0x{crc:08X} "
                  f"(esperado 0x{mod['crc']:08X})")
            return False
        blob_path(mod).write_bytes(blob)
        mod["size"] = len(blob)
        print(f"[setup] idx {idx} -> {blob_path(mod).name} "
              f"({len(blob)} bytes, CRC 0x{crc:08X}, base 0x{mod['vram']:08X})")
    return True


def build_combined_rom(rom_path: Path):
    rom = rom_path.read_bytes()
    if len(rom) != 0x1000000:
        print(f"[setup] ROM inesperada: {len(rom)} bytes")
        return False
    size = max(mod["rom_off"] + mod["size"] for mod in MODULES)
    combined = bytearray(size)
    combined[0:len(rom)] = rom
    for mod in MODULES:
        blob = blob_path(mod).read_bytes()
        combined[mod["rom_off"]:mod["rom_off"] + len(blob)] = blob
    COMBINED_ROM.write_bytes(combined)
    print(f"[setup] {COMBINED_ROM} ({len(combined)} bytes)")
    return True


def load_module_extras():
    """Extras derivados de la traza de saltos del emulador (config/module_extras.json).

    { "23": ["0x801C0C08", ...], ... } — target de jal/jalr observados dentro del módulo que no
    son entradas estáticas. Ver tools/analysis/gen_module_extras.py."""
    path = CONFIG / "module_extras.json"
    if not path.exists():
        return {}
    import json
    raw = json.loads(path.read_text())
    return {int(k): [int(x, 16) for x in v] for k, v in raw.items()}


def gen_module_syms(mod):
    extras = set(mod.get("extra", []))
    extras |= set(MODULE_EXTRAS.get(mod["index"], []))
    extra = ",".join(f"0x{a:X}" for a in sorted(extras))
    # Prefijo por módulo: varios módulos comparten base de VRAM, así que los nombres de función
    # deben ser únicos a nivel de símbolo C (`M24_FUN_...`).
    cmd = [sys.executable, ROOT / "tools/analysis/gen_module_syms.py", blob_path(mod),
           "--vram", f"0x{mod['vram']:X}", "--rom", f"0x{mod['rom_off']:X}",
           "--name", mod["name"], "--prefix", f"M{mod['index']}_",
           "--extra", extra,
           "--out", module_syms_path(mod)]
    if mod.get("auto_mid"):
        cmd.append("--self-pointer-mid-entries")
    if mod.get("filter_data"):
        cmd.append("--filter-data")
    return run(cmd) == 0


def fix_module_syms(mod):
    syms = module_syms_path(mod)
    fixed = syms.with_suffix(".fixed.syms.toml")
    # OJO: rc != 0 si el input tiene ramas cruzadas (esperado); lo que importa es el resultado.
    keep = ["--keep-file", KEEP_SYMS] if KEEP_SYMS.exists() else []
    run([sys.executable, ROOT / "tools/analysis/validate_syms.py", syms,
         "--rom", COMBINED_ROM, "--fix", "--out", fixed, *keep])
    if not fixed.exists():
        return False
    if run([sys.executable, ROOT / "tools/analysis/validate_syms.py", fixed,
            "--rom", COMBINED_ROM, *keep]) != 0:
        return False
    syms.write_bytes(fixed.read_bytes())
    print(f"[setup] módulo idx {mod['index']} validado/corregido -> {syms.name}")
    return True


def overlaps_module(f):
    for mod in MODULES:
        lo, hi = mod["vram"], mod["vram"] + mod["size"]
        if f["vram"] < hi and (f["vram"] + f["size"]) > lo:
            return True
    return False


def merge_syms():
    flat = tomllib.loads(FLAT_SYMS.read_text())["section"][0]
    ff = [f for f in flat["functions"] if not overlaps_module(f)]
    def sect(comment, name, rom, vram, size, funcs):
        out = [comment, "[[section]]", f'name = "{name}"', f"rom = 0x{rom:X}",
               f"vram = 0x{vram:08X}", f"size = 0x{size:X}", "", "functions = ["]
        out += [f'    {{ name = "{f["name"]}", vram = 0x{f["vram"]:08X}, size = 0x{f["size"]:X} }},'
                for f in funcs]
        out.append("]")
        return out

    lines = ["# Syms combinada: imagen plana + módulos de código (secciones). "
             "Generada por setup_module.py."]
    lines += sect("# plana (sin lo que solapa los módulos)", FLAT_SECTION["name"],
                  FLAT_SECTION["rom"], FLAT_SECTION["vram"], FLAT_SECTION["size"], ff)
    for mod in MODULES:
        mod_syms = tomllib.loads(module_syms_path(mod).read_text())["section"][0]
        lines.append("")
        lines += sect(f"# módulo Nisitenma idx {mod['index']}", mod["name"], mod["rom_off"],
                      mod["vram"], mod["size"], mod_syms["functions"])
    COMBINED_SYMS.write_text("\n".join(lines) + "\n")
    print(f"[setup] {COMBINED_SYMS.name}: plana {len(ff)} + " +
          " + ".join(f"{mod['name']} {len(tomllib.loads(module_syms_path(mod).read_text())['section'][0]['functions'])}"
                     for mod in MODULES))
    return True


def gen_keep_syms():
    """Direcciones de entradas indirectas legítimas: el validador no las fusiona.

    Las escribe `gen_module_syms.py` en `<syms>.keep` (extras manuales + auto-punteros)."""
    addrs = set()
    for mod in MODULES:
        addrs |= {int(a) for a in mod.get("extra", [])}
        addrs |= {int(a) for a in MODULE_EXTRAS.get(mod["index"], [])}
        keep = Path(str(module_syms_path(mod)) + ".keep")
        if keep.exists():
            addrs |= {int(l, 16) for l in keep.read_text().split() if l.strip()}
    if KEEP_SYMS_FLAT.exists():
        for line in KEEP_SYMS_FLAT.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                addrs.add(int(line, 16))
    KEEP_SYMS.write_text("\n".join(f"0x{a:08X}" for a in sorted(addrs)) + "\n")
    print(f"[setup] {KEEP_SYMS.name}: {len(addrs)} entradas protegidas")
    return True


def gen_module_sources_inc():
    """Mapa src_rom (offset ROM retail, a0 del loader) -> índice de sección en recomp_overlays.inl.

    El runtime lo usa para registrar la sección del módulo en la base de RAM que pide el juego
    (`load_module_by_source`), soportando la reutilización de bases entre módulos (idx 24 sobre
    la base de idx 23, idx 99 sobre la de idx 54, ...)."""
    lines = [
        "// Generado por tools/setup_module.py -- no editar a mano.",
        "// { src_rom (ROM retail, a0 del loader), rom_addr (seccion en el ROM combinado) }.",
    ]
    for i, mod in enumerate(MODULES, start=1):
        lines.append(f"{{ 0x{mod['src_rom']:08X}u, 0x{mod['rom_off']:08X}u }}, // {mod['name']} (idx {mod['index']})")
    MODULE_SOURCES_INC.write_text("\n".join(lines) + "\n")
    print(f"[setup] {MODULE_SOURCES_INC.name}: {len(MODULES)} módulos")
    return True


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", type=Path, default=DEFAULT_ROM)
    ap.add_argument("--build", action="store_true")
    args = ap.parse_args()

    if not args.rom.exists():
        print(f"[setup] falta la ROM: {args.rom}")
        return 1

    if not extract_blobs(args.rom):
        return 1
    if not build_combined_rom(args.rom):
        return 1
    global MODULE_EXTRAS
    MODULE_EXTRAS = load_module_extras()
    for mod in MODULES:
        if not gen_module_syms(mod):
            return 1
    if not gen_keep_syms():
        return 1
    for mod in MODULES:
        if not fix_module_syms(mod):
            return 1
    if not merge_syms():
        return 1
    if not gen_module_sources_inc():
        return 1

    print("\n[setup] listo. Para recompilar el set combinado y construir:")
    print("  python3 tools/recomp.py --config config/game_combined.toml --build")
    if args.build:
        return run([sys.executable, ROOT / "tools/recomp.py", "--config",
                    "config/game_combined.toml", "--build"])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
