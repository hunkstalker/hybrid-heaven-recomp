#!/usr/bin/env python3
"""
recomp.py — pipeline reproducible de recompilación (Hybrid Heaven).

Pasos:
  1) Validar la syms con validate_syms.py (delay-slots, ramas cruzadas, data-as-code).
     Con --fix-syms, genera una syms corregida y la aplica (backup .bak).
  2) N64Recomp sobre el config (regenera RecompiledFuncs_*).
  3) Copiar salidas al port.
  4) fix_fallthroughs.py (re-encadena fallthroughs de N64Recomp).
  5) Asegurar declaraciones `*_recomp` faltantes en funcs.h.
  6) (--build) cmake --build build_dbg.

Uso:
  python3 tools/recomp.py [--config config/game_unified.toml] [--build]
                          [--fix-syms] [--no-validate] [--force] [--dry-run]
"""

import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path

try:
    import tomllib
except ImportError:
    sys.exit("Se requiere Python 3.11+ (tomllib).")

ROOT = Path(__file__).resolve().parents[1]
CONFIG_DIR = ROOT / "config"
N64RECOMP = ROOT / "toolchain/src/N64Recomp/build_recomp/N64Recomp"
PORT = ROOT / "port/HybridHeavenRecomp"
RECOMP_DIR = PORT / "RecompiledFuncs"
ROM = ROOT / "work/roms/us_retail.z64"
VALIDATOR = ROOT / "tools/analysis/validate_syms.py"
CHECK_OVERRIDES = ROOT / "tools/analysis/check_syms_overrides.py"
FIX_FT = ROOT / "tools/analysis/fix_fallthroughs.py"
KEEP_SYMS = CONFIG_DIR / "keep_syms.txt"


def run(cmd, cwd=None, dry=False):
    print(f"$ {' '.join(str(c) for c in cmd)}" + (f"   (cwd={cwd})" if cwd else ""))
    if dry:
        return 0
    return subprocess.call([str(c) for c in cmd], cwd=str(cwd) if cwd else None)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--config", default="config/game_unified.toml")
    ap.add_argument("--build", action="store_true")
    ap.add_argument("--fix-syms", action="store_true")
    ap.add_argument("--no-validate", action="store_true")
    ap.add_argument("--force", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    cfg_path = (ROOT / args.config) if not Path(args.config).is_absolute() else Path(args.config)
    cfg = tomllib.loads(cfg_path.read_text())
    inp = cfg["input"]
    out_name = inp["output_func_path"]
    syms_path = CONFIG_DIR / inp["symbols_file_path"]
    out_dir = CONFIG_DIR / out_name
    rom = (CONFIG_DIR / inp.get("rom_file_path", "../work/roms/us_retail.z64")).resolve()

    print(f"config  : {cfg_path.relative_to(ROOT)}")
    print(f"syms    : {syms_path.relative_to(ROOT)}")
    print(f"salida  : {out_dir.relative_to(ROOT)}")

    # 1) validar
    keep = ["--keep-file", KEEP_SYMS] if KEEP_SYMS.exists() else []
    if not args.no_validate:
        rc = run([sys.executable, VALIDATOR, syms_path, "--rom", rom, *keep], dry=args.dry_run)
        if rc != 0:
            if args.fix_syms:
                fixed = syms_path.with_suffix(".fixed.syms.toml")
                print("[recomp] syms con errores -> intentando --fix")
                run([sys.executable, VALIDATOR, syms_path, "--rom", rom, "--fix", "--out", fixed, *keep],
                    dry=args.dry_run)
                rc2 = run([sys.executable, VALIDATOR, fixed, "--rom", rom, *keep], dry=args.dry_run)
                if rc2 == 0 and not args.dry_run:
                    shutil.copy2(syms_path, syms_path.with_suffix(".syms.toml.bak"))
                    shutil.copy2(fixed, syms_path)
                    print(f"[recomp] syms corregida aplicada (backup en {syms_path.name}.bak)")
                else:
                    print("[recomp] el fix no deja la syms limpia; abortando")
                    return 1
            elif not args.force:
                print("[recomp] validación con errores (usa --fix-syms o --force); abortando")
                return 1

    # 1b) los overrides de tamano de module_extras.json deben seguir en las .syms (perderlos
    # revierte fixes ya hechos: M9_FUN_802169ac -> stub do_break -> cuelgue del NPC)
    if not args.dry_run:
        rc = run([sys.executable, CHECK_OVERRIDES], dry=args.dry_run)
        if rc != 0:
            print("[recomp] overrides de tamano perdidos en las .syms; abortando "
                  "(revisa el aviso de check_syms_overrides.py)")
            return 1

    # 2) regenerar (limpiar salida primero)
    if out_dir.exists() and not args.dry_run:
        shutil.rmtree(out_dir)
    rc = run([N64RECOMP, cfg_path.name], cwd=CONFIG_DIR, dry=args.dry_run)
    if rc != 0:
        print(f"[recomp] N64Recomp falló (rc={rc})")
        return rc

    # 3) copiar al port (limpiando los funcs_*.c previos: el número de ficheros puede bajar)
    if not args.dry_run:
        RECOMP_DIR.mkdir(parents=True, exist_ok=True)
        for old in RECOMP_DIR.glob("funcs_*.c"):
            old.unlink()
        for f in list(out_dir.glob("funcs_*.c")) + list(out_dir.glob("funcs.h")) + \
                 list(out_dir.glob("lookup.cpp")) + list(out_dir.glob("recomp_overlays.inl")):
            shutil.copy2(f, RECOMP_DIR / f.name)
        print(f"[recomp] copiados {len(list(out_dir.glob('funcs_*.c')))} funcs_*.c + headers")

    # 4) fix_fallthroughs
    run([sys.executable, FIX_FT], dry=args.dry_run)

    # 5) declaraciones _recomp faltantes
    if not args.dry_run:
        _ensure_recomp_decls()

    # 6) build
    if args.build:
        rc = run(["cmake", "--build", str(PORT / "build_dbg"), "-j"], dry=args.dry_run)
        if rc != 0:
            print(f"[recomp] build falló (rc={rc})")
            return rc

    print("[recomp] OK")
    return 0


def _ensure_recomp_decls():
    """Añade a funcs.h las declaraciones de *_recomp llamadas pero no declaradas."""
    funcs_h = RECOMP_DIR / "funcs.h"
    if not funcs_h.exists():
        return
    text = funcs_h.read_text()
    declared = set(re.findall(r"\b(\w+_recomp)\s*\(", text))
    called = set()
    for f in RECOMP_DIR.glob("funcs_*.c"):
        called |= set(re.findall(r"\b(\w+_recomp)\s*\(rdram, ctx\)", f.read_text()))
    missing = sorted(called - declared)
    if missing:
        block = "\n".join(f"void {n}(uint8_t* rdram, recomp_context* ctx);" for n in missing)
        funcs_h.write_text(text + f"\n/* auto: declaraciones _recomp faltantes */\n{block}\n")
        print(f"[recomp] añadidas {len(missing)} declaraciones a funcs.h: {', '.join(missing)}")


if __name__ == "__main__":
    raise SystemExit(main())
