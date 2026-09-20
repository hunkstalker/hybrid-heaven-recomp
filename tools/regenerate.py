#!/usr/bin/env python3
"""regenerate.py — regenera el C recompilado del port desde TU ROM (tarea de mantenedor).

El C recompilado (`port/HybridHeavenRecomp/RecompiledFuncs/`) es **obra derivada del binario del
juego** y **no se versiona** (norma del ecosistema; ver `docs/adr/0009`). Quien clone el repo debe
regenerarlo una vez con su propia ROM antes de compilar el port.

Pipeline (per-file):
  1. `analyze_code_files.py`  -> manifiesto + extraccion de los 91 code files (ROM combinado).
  2. `ghidra_sections.py`     -> Ghidra por fichero: fronteras + syms `.file_NN`; agrega la syms.
  3. `validate_syms.py --fix` -> corrige delay-slots / ramas cruzadas.
  4. N64Recomp                -> `config/RecompiledFuncs_code/`.
  5. RSPRecomp                -> `rsp/hh_aspMain.cpp` si falta (microcodigo RSP).
  6. Copia a `work/recomp/RecompiledFuncs/` (destino del symlink `port/RecompiledFuncs`) +
     `fix_fallthroughs.py`.

Requiere: Python 3.11+, JDK 21 + Ghidra (dep. de desarrollo; ver `tools/install_ghidra.sh`),
N64Recomp (con `config/n64recomp_changes/`), RSPRecomp y la ROM del usuario en
`work/roms/us_retail.z64`.

Uso:
  python3 tools/regenerate.py                 # todo
  python3 tools/regenerate.py --rom ROM       # ROM explicita
  python3 tools/regenerate.py --skip-ghidra   # reutiliza work/scratch/syms (iterar N64Recomp)
  python3 tools/regenerate.py --skip-rsp      # no toca rsp/hh_aspMain.cpp
"""

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PORT = ROOT / "port/HybridHeavenRecomp"
RECOMP_OUT = ROOT / "config/RecompiledFuncs_code"
RECOMP_DEST = ROOT / "work/recomp/RecompiledFuncs"
COMBINED = ROOT / "work/scratch/code_combined.z64"
SYMS = ROOT / "work/scratch/code_files.fixed.syms.toml"
N64RECOMP = ROOT / "toolchain/src/N64Recomp/build_recomp/N64Recomp"
RSPRECOMP = ROOT / "toolchain/src/N64Recomp/build_recomp/RSPRecomp"
ASPMAIN = PORT / "rsp/hh_aspMain.cpp"
DEFAULT_ROM = ROOT / "work/roms/us_retail.z64"


def run(cmd, allow_fail=False):
    print("$", " ".join(str(c) for c in cmd), flush=True)
    rc = subprocess.call([str(c) for c in cmd])
    if rc != 0 and not allow_fail:
        sys.exit("fallo: %s (rc=%d)" % (cmd[0], rc))
    return rc


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--rom", type=Path, default=DEFAULT_ROM)
    ap.add_argument("--skip-ghidra", action="store_true",
                    help="no re-ejecuta Ghidra (usa work/scratch/syms existentes)")
    ap.add_argument("--skip-rsp", action="store_true")
    args = ap.parse_args()

    if not args.rom.exists():
        sys.exit("falta la ROM: %s (gitignored; la aporta el usuario)" % args.rom)

    # 1) manifiesto + extraccion
    run([sys.executable, ROOT / "tools/analyze_code_files.py", args.rom,
         "--extract", ROOT / "work/scratch/code_files"])

    # 2) Ghidra per-file (caro; se puede reutilizar)
    if args.skip_ghidra:
        run([sys.executable, ROOT / "tools/ghidra_sections.py", "--aggregate-only"])
    else:
        run([sys.executable, ROOT / "tools/ghidra_sections.py", "--all"])

    # 3) validar/corregir la syms agregada. rc != 0 solo avisa de ramas cruzadas/delay-slots
    #    pendientes; el fichero corregido se escribe igual (mismo criterio que setup_module.py).
    #    SIEMPRE se re-ejecuta (no reutilizar un .fixed viejo: las fronteras cambian).
    run([sys.executable, ROOT / "tools/analysis/validate_syms.py",
         ROOT / "work/scratch/code_files.syms.toml", "--rom", COMBINED,
         "--fix", "--out", SYMS], allow_fail=True)
    if not SYMS.exists():
        sys.exit("validate_syms no genero %s" % SYMS)

    # 4) N64Recomp (borra la salida antes: N64Recomp no limpia y deja ficheros rancios)
    if RECOMP_OUT.exists():
        shutil.rmtree(RECOMP_OUT)
    if not N64RECOMP.exists():
        sys.exit("falta N64Recomp en %s (compilalo; ver docs/workflows.md)" % N64RECOMP)
    run([N64RECOMP, ROOT / "config/game_code_files.toml"])

    # 5) RSPRecomp (aspMain): genera work/rsp/hh_aspMain.cpp; si falta en el port, se copia.
    if not args.skip_rsp:
        rsp_out = ROOT / "work/rsp/hh_aspMain.cpp"
        if not ASPMAIN.exists():
            if RSPRECOMP.exists():
                run([RSPRECOMP, ROOT / "config/rsp_hh_aspMain.toml"])
                if rsp_out.exists():
                    ASPMAIN.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copyfile(rsp_out, ASPMAIN)
            else:
                print("AVISO: falta %s y no hay RSPRecomp; el port no tendra audio RSP" % ASPMAIN)

    # 6) copiar al destino del symlink + fallthroughs
    if RECOMP_DEST.exists() or RECOMP_DEST.is_symlink():
        if RECOMP_DEST.is_symlink() or RECOMP_DEST.is_file():
            RECOMP_DEST.unlink()
        else:
            shutil.rmtree(RECOMP_DEST)
    RECOMP_DEST.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(RECOMP_OUT, RECOMP_DEST)

    if not (PORT / "RecompiledFuncs").exists():
        print("AVISO: falta el symlink port/HybridHeavenRecomp/RecompiledFuncs (recrea el repo)")
    run([sys.executable, ROOT / "tools/analysis/fix_fallthroughs.py",
         "--recomp-dir", str(RECOMP_DEST)])

    # 7) tabla id->{vram,size} del port (en el mismo orden que overlays.txt)
    run([sys.executable, ROOT / "tools/gen_file_table.py"])

    print("\n[regenerate] listo: %s" % RECOMP_DEST)
    print("  compila con: tools/build_linux.sh   (o port\\build_windows.bat en Windows)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
