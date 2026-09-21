#!/usr/bin/env python3
"""analyze_code_files.py — manifiesto de los ficheros de CÓDIGO del Nisitenma-Ichigo.

Enumera **todos** los ficheros de la tabla de assets del juego y clasifica cuáles son código,
sin lista hardcodeada. Es la base del pipeline de recompilación per-file:

  ROM -> manifiesto (idx, file, src_rom, vram, size, crc) -> extracción -> Ghidra por fichero
  -> syms por sección `.file_NN` -> N64Recomp.

Modelo (ver `docs/architecture.md` y la nota de método
`notes/2026-09-20-lecciones-recompilacion-per-file.md`):
  - Tabla de offsets "Nisitenma-Ichigo": `0x80038FE0` (ROM `0x39BE0`). Magic + u32 BE por id
    desde `+0x10`. `file id` abarca las entradas `id-1` y `id`. Bit 31 del inicio = LZKN64.
  - Tabla de VRAM `0x80037C5C`: 8 B por id, `{vram_start, vram_end}` (fin incluye bss).
  - Ids 1..0x270 (el loader `func_8000469C` rechaza 0 y >= 0x271).
  - "Es código" = >=3 `jr $ra` y >=3 prólogos `addiu $sp,$sp,-N` (heurística de densidad;
    ver `docs/GAME-INTERNALS.md` del port de referencia).

Fuente del formato: port de referencia `danielgomesvieira2000/hybrid-heaven-recomp`,
`tools/nisitenma.py` (solo el formato/medida; los datos se miden de la ROM del usuario).

Uso:
  python3 tools/analyze_code_files.py [ROM]                 resumen + escrito de artefactos
  python3 tools/analyze_code_files.py --list                una línea por fichero de código
  python3 tools/analyze_code_files.py --extract DIR         vuelca los ficheros descomprimidos

Salidas por defecto (versionables):
  recomp/code_files.json          manifiesto (todos los code files)
  recomp/code_files.overlays.txt  lista de secciones `.file_NN` para `relocatable_sections_path`
"""

import argparse
import json
import os
import struct
import sys
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

BOOT_VRAM = 0x80000400
BOOT_ROM = 0x1000
FILE_TABLE_VRAM = 0x80038FE0
VRAM_TABLE_VRAM = 0x80037C5C
FILE_COUNT = 0x270
COMPRESSED = 0x80000000
MAGIC = b"Nisitenma-Ichigo"

DEFAULT_ROM = ROOT / "work/roms/us_retail.z64"
DEFAULT_JSON = ROOT / "recomp/code_files.json"
DEFAULT_OVERLAYS = ROOT / "recomp/code_files.overlays.txt"


def v2r(vram: int) -> int:
    return vram - BOOT_VRAM + BOOT_ROM


def be32(buf: bytes, off: int) -> int:
    return struct.unpack_from(">I", buf, off)[0]


def decompress(data: bytes) -> bytes:
    sys.path.insert(0, str(ROOT / "tools"))
    import lzkn64  # shim local (Python puro)
    return lzkn64.decompress(data)


def looks_like_code(data: bytes):
    """(jr $ra, prólogos, es_código). Umbral: >=3 de cada uno."""
    n = len(data) & ~3
    words = struct.unpack_from(">%dI" % (n // 4), data, 0) if n else ()
    jr = sum(1 for w in words if w == 0x03E00008)
    prologue = sum(1 for w in words if (w & 0xFFFF8000) == 0x27BD8000)
    return jr, prologue, jr >= 3 and prologue >= 3


def read_files(rom: bytes):
    ft = v2r(FILE_TABLE_VRAM)
    vt = v2r(VRAM_TABLE_VRAM)
    if rom[ft:ft + len(MAGIC)] != MAGIC:
        sys.exit("magic Nisitenma-Ichigo no encontrado en ROM 0x%X (¿dump incorrecto?)" % ft)
    files = []
    for fid in range(1, FILE_COUNT + 1):
        start_word = be32(rom, ft + 0x10 + (fid - 1) * 4)
        end_word = be32(rom, ft + 0x14 + (fid - 1) * 4)
        start = start_word & 0x7FFFFFFF
        end = end_word & 0x7FFFFFFF
        vstart = be32(rom, vt + (fid - 1) * 8)
        vend = be32(rom, vt + (fid - 1) * 8 + 4)
        f = dict(id=fid, src_rom=start, src_end=end,
                 compressed=bool(start_word & COMPRESSED),
                 vram=vstart, vram_end=vend, data=b"", error="")
        if end > start:
            if f["compressed"]:
                try:
                    f["data"] = decompress(rom[start:end])
                except Exception as ex:  # noqa: BLE001 — se reporta y sigue
                    f["error"] = str(ex) or type(ex).__name__
            else:
                f["data"] = rom[start:end]
        f["jr"], f["prologue"], f["code"] = looks_like_code(f["data"])
        files.append(f)
    return files


def code_manifest(files):
    out = []
    for f in files:
        if not f["code"]:
            continue
        out.append({
            "idx": f["id"],
            "file": "file_%03d" % f["id"],
            "src_rom": "0x%08X" % f["src_rom"],
            "src_size": f["src_end"] - f["src_rom"],
            "compressed": f["compressed"],
            "vram": "0x%08X" % f["vram"],
            "vram_end": "0x%08X" % f["vram_end"],
            "size": len(f["data"]),
            "size_hex": "0x%X" % len(f["data"]),
            "crc32": "0x%08X" % (zlib.crc32(f["data"]) & 0xFFFFFFFF),
            "jr_ra": f["jr"],
            "prologues": f["prologue"],
        })
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("rom", nargs="?", type=Path, default=DEFAULT_ROM)
    ap.add_argument("--list", action="store_true", help="una línea por fichero de código")
    ap.add_argument("--json", type=Path, default=DEFAULT_JSON)
    ap.add_argument("--overlays", type=Path, default=DEFAULT_OVERLAYS)
    ap.add_argument("--extract", metavar="DIR", help="vuelca los code files descomprimidos")
    args = ap.parse_args()

    if not args.rom.exists():
        sys.exit("falta la ROM: %s (gitignored; la aporta el usuario)" % args.rom)
    rom = args.rom.read_bytes()
    if len(rom) != 0x1000000:
        sys.exit("ROM inesperada: %d bytes (se espera 0x1000000)" % len(rom))

    files = read_files(rom)
    code = code_manifest(files)
    failed = [f for f in files if f["error"]]

    total_bytes = sum(c["size"] for c in code)
    total_jr = sum(c["jr_ra"] for c in code)
    print("== tabla de ficheros (ROM 0x%X, %d ids) ==" % (v2r(FILE_TABLE_VRAM), FILE_COUNT))
    print("  errores de descompresión: %d" % len(failed))
    for f in failed:
        print("    id %d (vram %08X): %s" % (f["id"], f["vram"], f["error"]))
    print("  ficheros de código: %d, 0x%X bytes descomprimidos, %d 'jr $ra'"
          % (len(code), total_bytes, total_jr))

    oversize = [c for c in code if c["size"] > int(c["vram_end"], 16) - int(c["vram"], 16)]
    print("  code files mayores que su span de vram: %s"
          % (", ".join(c["file"] for c in oversize) if oversize else "ninguno"))

    if args.list:
        print("\n== code files ==")
        for c in code:
            print("  %-10s idx %3d  rom %s-%s %s  vram %s-%s  dec %8d  jr %4d  pro %4d"
                  % (c["file"], c["idx"], c["src_rom"],
                     "0x%08X" % (int(c["src_rom"], 16) + c["src_size"]),
                     "C" if c["compressed"] else "-", c["vram"], c["vram_end"],
                     c["size"], c["jr_ra"], c["prologues"]))

    args.json.parent.mkdir(parents=True, exist_ok=True)
    manifest = {
        "source": "Nisitenma-Ichigo file table + VRAM table, medido de la ROM",
        "rom": str(args.rom.relative_to(ROOT)) if args.rom.is_relative_to(ROOT) else str(args.rom),
        "rom_size": len(rom),
        "file_table_rom": "0x%X" % v2r(FILE_TABLE_VRAM),
        "vram_table_rom": "0x%X" % v2r(VRAM_TABLE_VRAM),
        "file_count": FILE_COUNT,
        "code_file_count": len(code),
        "code_bytes": total_bytes,
        "code_jr_ra": total_jr,
        "code_files": code,
    }
    args.json.write_text(json.dumps(manifest, indent=2) + "\n")
    print("\n[manifest] %s (%d code files)" % (args.json, len(code)))

    args.overlays.write_text("\n".join("." + c["file"] for c in code) + "\n")
    print("[overlays] %s" % args.overlays)

    if args.extract:
        out = Path(args.extract)
        out.mkdir(parents=True, exist_ok=True)
        by_id = {f["id"]: f for f in files}
        for c in code:
            (out / (c["file"] + ".bin")).write_bytes(by_id[c["idx"]]["data"])
        print("[extract] %d ficheros a %s (derivado de la ROM: no versionar)" % (len(code), out))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
