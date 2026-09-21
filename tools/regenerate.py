#!/usr/bin/env python3
# Adaptado del tooling del port de referencia (MIT); ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt.
"""regenerate.py — regenera el C recompilado desde TU ROM (via ELF/splat; ADR 0011).

El C recompilado es **obra derivada** del binario del juego y **no se versiona** (ADR 0009). Quien
clone el repo debe regenerarlo una vez con su propia ROM antes de compilar el port.

Pipeline:
  1. analyze_code_files  -> manifiesto (recomp/code_files.json) + overlays.
  2. unpack_rom          -> imagen expandida + segments.json + file_table.h.
  3. gen_splat_yaml      -> recomp/hybrid-heaven.us.yaml.
  4. splat split         -> build/recomp/asm (+ linker script, undefined_*).
  5. build_elf.sh        -> build/recomp/elf/hybrid-heaven.us.elf (gate: byte-identico a la imagen).
  6. N64Recomp (ELF mode) -> work/recomp_elf/RecompiledFuncs.
  7. RSPRecomp            -> build/recomp/rsp/hh_aspMain.cpp (microcodigo RSP ASCII).
  8. gen_reimplemented_decls + gen_runtime_func_table.
  9. copia a build/recomp/RecompiledFuncs (dir real) + gen_file_table.

Requiere (dev): Python 3.11+, splat+spimdisasm y LLVM MIPS (tools/install_splat.sh), N64Recomp +
RSPRecomp (con `recomp/n64recomp_changes/` aplicados), y la ROM en work/roms/us_retail.z64.

Uso:
  python3 tools/regenerate.py                 # todo
  python3 tools/regenerate.py --rom ROM
  python3 tools/regenerate.py --skip-splat    # reutiliza build/recomp/asm (iterar build_elf/N64Recomp)
  python3 tools/regenerate.py --skip-elf      # reutiliza build/recomp/elf (iterar N64Recomp)
  python3 tools/regenerate.py --build         # compila el port al final
"""

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PORT = ROOT
PORT_RECOMP = ROOT / "build/recomp/RecompiledFuncs"
RECOMP_OUT = ROOT / "work/recomp_elf/RecompiledFuncs"
ELF = ROOT / "build/recomp/elf/hybrid-heaven.us.elf"
TOML = ROOT / "recomp/hybrid-heaven.us.toml"
N64RECOMP = ROOT / "toolchain/src/N64Recomp/build_recomp/N64Recomp"
RSPRECOMP = ROOT / "toolchain/src/N64Recomp/build_recomp/RSPRecomp"
RSP_TOML = ROOT / "recomp/rsp_hh_aspMain.toml"
DEFAULT_ROM = ROOT / "work/roms/us_retail.z64"


def run(cmd):
    print("$", " ".join(str(c) for c in cmd), flush=True)
    rc = subprocess.call([str(c) for c in cmd])
    if rc != 0:
        sys.exit("fallo: %s (rc=%d)" % (cmd[0], rc))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--rom", type=Path, default=DEFAULT_ROM)
    ap.add_argument("--skip-splat", action="store_true")
    ap.add_argument("--skip-elf", action="store_true")
    ap.add_argument("--build", action="store_true")
    args = ap.parse_args()

    if not args.rom.exists():
        sys.exit("falta la ROM: %s (gitignored; la aporta el usuario)" % args.rom)

    run([sys.executable, ROOT / "recomp/tools/analyze_code_files.py", args.rom])
    run([sys.executable, ROOT / "recomp/tools/unpack_rom.py", args.rom])
    run([sys.executable, ROOT / "recomp/tools/gen_splat_yaml.py"])

    if not args.skip_splat:
        run([ROOT / "recomp/tools/splat_headless.sh", "split", ROOT / "recomp/hybrid-heaven.us.yaml"])
    if not args.skip_elf:
        run([ROOT / "recomp/tools/build_elf.sh"])

    if not N64RECOMP.exists():
        sys.exit("falta N64Recomp en %s (ver docs/workflows.md)" % N64RECOMP)
    if RECOMP_OUT.exists():
        shutil.rmtree(RECOMP_OUT)
    run([N64RECOMP, TOML])

    # Microcodigo RSP (aspMain) recompilado; tambien derivado -> generado, no versionado (ADR 0009).
    if not RSPRECOMP.exists():
        sys.exit("falta RSPRecomp en %s (se construye junto a N64Recomp; ver docs/workflows.md)" % RSPRECOMP)
    (ROOT / "build/recomp/rsp").mkdir(parents=True, exist_ok=True)
    run([RSPRECOMP, RSP_TOML])
    print("[regenerate] build/recomp/rsp/hh_aspMain.cpp generado")

    run([sys.executable, ROOT / "recomp/tools/gen_reimplemented_decls.py"])
    run([sys.executable, ROOT / "recomp/tools/gen_runtime_func_table.py"])

    if PORT_RECOMP.exists() or PORT_RECOMP.is_symlink():
        if PORT_RECOMP.is_symlink() or PORT_RECOMP.is_file():
            PORT_RECOMP.unlink()
        else:
            shutil.rmtree(PORT_RECOMP)
    shutil.copytree(RECOMP_OUT, PORT_RECOMP)
    print("[regenerate] build/recomp/RecompiledFuncs materializado (%d ficheros)" % len(list(PORT_RECOMP.glob("*"))))

    run([sys.executable, ROOT / "recomp/tools/gen_file_table.py"])

    if args.build:
        run([ROOT / "tools/build_linux.sh"])

    print("\n[regenerate] listo: %s" % RECOMP_OUT)
    print("  compila con: tools/build_linux.sh   (o build_windows.bat / build_windows.local.bat)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
