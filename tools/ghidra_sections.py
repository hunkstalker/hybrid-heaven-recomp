#!/usr/bin/env python3
"""ghidra_sections.py — pipeline per-file: fichero de código -> sección de símbolos.

Para cada code file del manifiesto (`config/code_files.json`):
  1. comprueba que el blob descomprimido existe (`work/scratch/code_files/file_NN.bin`,
     lo genera `tools/analyze_code_files.py --extract`).
  2. lo importa en Ghidra como binario MIPS big-endian en su `vram`, ejecuta el análisis,
     siembra inicios de función no alcanzados (`SeedFunctionStarts`) y exporta las
     fronteras (`ExportSectionSyms`) -> `work/scratch/syms/file_NN.toml`.
  3. agrega todas las secciones en `config/code_files.syms.toml`.

Además construye la imagen combinada `work/scratch/code_combined.z64` (ROM retail + cada
fichero descomprimido en un offset sintético estable) y `work/scratch/code_sections.json`
(mapea file -> rom_off).

Ghidra es dependencia de DESARROLLO: `tools/install_ghidra.sh` / `tools/ghidra_headless.sh`.

Uso:
  python3 tools/ghidra_sections.py --only 57            # un fichero (prueba)
  python3 tools/ghidra_sections.py --only 8,55,56,57
  python3 tools/ghidra_sections.py --all                # los 91 (lento)
  python3 tools/ghidra_sections.py --aggregate-only     # solo rehace el TOML agregado
"""

import argparse
import json
import struct
import subprocess
import sys
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CONFIG = ROOT / "config"
SCRATCH = ROOT / "work/scratch"
CODE_DIR = SCRATCH / "code_files"
SYMS_DIR = SCRATCH / "syms"
GHIDRA_PROJ = SCRATCH / "ghidra_proj"
COMBINED_ROM = SCRATCH / "code_combined.z64"
SECTIONS_JSON = SCRATCH / "code_sections.json"

MANIFEST = CONFIG / "code_files.json"
# Syms generadas: no se versionan (dependen de la ROM); ver docs/documentation.md.
OUT_SYMS = SCRATCH / "code_files.syms.toml"
FLAT_SYMS = CONFIG / "us_ghidra.syms.toml"

RETAIL_ROM = ROOT / "work/roms/us_retail.z64"
COMBINED_BASE = 0x1000000  # tras la ROM retail (0x1000000)
ALIGN = 0x10


def load_manifest():
    if not MANIFEST.exists():
        sys.exit("falta %s; ejecuta tools/analyze_code_files.py" % MANIFEST)
    return json.loads(MANIFEST.read_text())


def text_end(blob: bytes) -> int:
    """Fin del texto: tras el último `jr $ra` + delay, alineado a 16 (medido, fiable)."""
    last = None
    for i in range(0, len(blob) - 3, 4):
        if struct.unpack_from(">I", blob, i)[0] == 0x03E00008:
            last = i
    if last is None:
        return 0
    return ((last + 8 + (ALIGN - 1)) // ALIGN) * ALIGN


def assign_offsets(manifest):
    off = COMBINED_BASE
    combo = bytearray()
    sections = []
    for c in manifest["code_files"]:
        blob_path = CODE_DIR / (c["file"] + ".bin")
        blob = blob_path.read_bytes()
        rom_off = off
        combo += blob
        pad = (-len(combo)) % ALIGN
        combo += b"\x00" * pad
        off += len(blob) + pad
        sections.append({
            "idx": c["idx"], "file": c["file"], "vram": c["vram"],
            "size": c["size"], "src_rom": c["src_rom"], "rom_off": rom_off,
            "text_end": text_end(blob),
        })
    SECTIONS_JSON.write_text(json.dumps(sections, indent=2) + "\n")
    return sections


def build_combined_rom(sections):
    retail = RETAIL_ROM.read_bytes()
    if len(retail) != 0x1000000:
        sys.exit("ROM retail inesperada: %d" % len(retail))
    size = max(s["rom_off"] + s["size"] for s in sections)
    combo = bytearray(size)
    combo[0:len(retail)] = retail
    for s in sections:
        blob = (CODE_DIR / (s["file"] + ".bin")).read_bytes()
        combo[s["rom_off"]:s["rom_off"] + len(blob)] = blob
    COMBINED_ROM.write_bytes(combo)
    print("[combined] %s (%d bytes, %d code files)"
          % (COMBINED_ROM, len(combo), len(sections)))


def ghidra_one(sec):
    blob = CODE_DIR / (sec["file"] + ".bin")
    out = SYMS_DIR / (sec["file"] + ".toml")
    base = int(sec["vram"], 16)
    te = base + sec["text_end"]
    cmd = [
        str(ROOT / "tools/ghidra_headless.sh"),
        str(GHIDRA_PROJ), "HHSec",
        "-import", str(blob),
        "-loader", "BinaryLoader", "-loader-baseAddr", "0x%X" % base,
        "-processor", "MIPS:BE:32:default",
        "-scriptPath", str(ROOT / "tools/analysis/ghidra_code"),
        "-preScript", "FindIndirectFunctions.java", "0x%X" % base, "0x%X" % sec["size"],
        "-postScript", "SeedFunctionStarts.java", "0x%X" % base, "0x%X" % te,
        "-postScript", "ExportSectionSyms.java", ".file_%03d" % sec["idx"],
        "0x%X" % sec["rom_off"], "0x%X" % sec["size"], str(out),
        "-overwrite",
    ]
    print("[ghidra] %s vram=0x%X rom=0x%X text_end=0x%X"
          % (sec["file"], base, sec["rom_off"], te))
    r = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    ok = out.exists() and ("ExportSectionSyms:" in r.stdout)
    if not ok:
        sys.stderr.write(r.stdout[-4000:])
    return ok


def postprocess_one(sec):
    """Aplica fix_per_file_syms (delay-slot, terminadores, jump-tables) al syms de un fichero."""
    raw = SYMS_DIR / (sec["file"] + ".toml")
    if not raw.exists():
        return False
    fixed = SYMS_DIR / (sec["file"] + ".fixed.toml")
    cmd = [sys.executable, str(ROOT / "tools/analysis/fix_per_file_syms.py"),
           str(raw), str(CODE_DIR / (sec["file"] + ".bin")),
           "--vram", sec["vram"], "--text-end", "0x%X" % (int(sec["vram"], 16) + sec["text_end"]),
           "--out", str(fixed)]
    return subprocess.call(cmd) == 0


def aggregate(sections):
    lines = ["# Syms per-file: residente (.text) + 91 ficheros de código Nisitenma como secciones "
             "relocalizables.", "# Generado por tools/ghidra_sections.py -- no editar a mano.",
             "# Cada función se nombra func_<vram>_<rom_off> (único aunque compartan base de VRAM)."]

    # Residente: reutiliza la syms plana de Ghidra quitando lo que solapa cualquier overlay.
    ranges = [(int(s["vram"], 16), int(s["vram"], 16) + s["size"]) for s in sections]
    if FLAT_SYMS.exists():
        flat = tomllib.loads(FLAT_SYMS.read_text())["section"][0]
        kept = []
        for f in flat["functions"]:
            v, sz = f["vram"], f["size"]
            if not any(v < hi and (v + sz) > lo for lo, hi in ranges):
                kept.append(f)
        lines.append("")
        lines.append("# imagen residente (excluye todos los rangos de overlay)")
        lines += _section(".text", flat["rom"], flat["vram"], flat["size"], kept)
        print("[aggregate] residente: %d funciones (de %d)" % (len(kept), len(flat["functions"])))

    for s in sections:
        raw = SYMS_DIR / (s["file"] + ".toml")
        fixed = SYMS_DIR / (s["file"] + ".fixed.toml")
        p = fixed if fixed.exists() else raw
        if not p.exists():
            print("[aggregate] FALTA %s (¿no procesado?)" % raw.name)
            continue
        data = tomllib.loads(p.read_text())["section"][0]
        lines.append("")
        lines += _section(data["name"], s["rom_off"], int(s["vram"], 16), s["size"],
                         data["functions"], relocs=True)
    OUT_SYMS.write_text("\n".join(lines) + "\n")
    print("[aggregate] %s" % OUT_SYMS)


def _section(name, rom, vram, size, funcs, relocs=False):
    out = ["[[section]]", 'name = "%s"' % name, "rom = 0x%X" % rom,
           "vram = 0x%08X" % vram, "size = 0x%X" % size]
    if relocs:
        # N64Recomp en modo syms marca una sección como relocalizable si tiene `relocs`.
        # Un array vacío basta (las llamadas van por lookup con use_lookup_for_all_function_calls).
        out.append("relocs = []")
    out += ["", "functions = ["]
    for f in funcs:
        out.append('    { name = "%s", vram = 0x%08X, size = 0x%X },'
                   % (f["name"], f["vram"], f["size"]))
    out.append("]")
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--only", help="ids separados por comas (p.ej. 57 o 8,55,56,57)")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--aggregate-only", action="store_true")
    ap.add_argument("--skip-ghidra", action="store_true",
                    help="no re-ejecuta Ghidra (usa los file_NN.toml existentes)")
    ap.add_argument("--postprocess-only", action="store_true",
                    help="solo aplica fix_per_file_syms a los file_NN.toml existentes")
    args = ap.parse_args()

    manifest = load_manifest()
    sections = assign_offsets(manifest)
    if not args.aggregate_only:
        build_combined_rom(sections)

    SYMS_DIR.mkdir(parents=True, exist_ok=True)
    GHIDRA_PROJ.mkdir(parents=True, exist_ok=True)

    if args.postprocess_only:
        todo = [s for s in sections if (SYMS_DIR / (s["file"] + ".toml")).exists()]
        for s in todo:
            postprocess_one(s)
        aggregate(sections)
        return 0

    if not args.aggregate_only and not args.skip_ghidra:
        if args.all:
            todo = sections
        elif args.only:
            want = {int(x) for x in args.only.split(",")}
            todo = [s for s in sections if s["idx"] in want]
        else:
            sys.exit("especifica --all o --only <ids>")
        failed = []
        for i, s in enumerate(todo, 1):
            print("[%d/%d]" % (i, len(todo)), end=" ")
            if not ghidra_one(s):
                failed.append(s["file"])
            else:
                postprocess_one(s)
        if failed:
            print("[ghidra] FALLARON: %s" % ", ".join(failed))
            return 1

    aggregate(sections)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
