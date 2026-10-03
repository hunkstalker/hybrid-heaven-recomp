#!/usr/bin/env python3
"""Empaqueta los datos de runtime del port junto al ejecutable (fuente unica CI/local).

CMake copia estos mismos datos (`assets/lang`, `assets/sounds/*.wav`, `assets/logos/*.png`,
`licences/OFL.txt`, `saves/templates`) junto al ejecutable en el POST_BUILD (ver CMakeLists.txt
~211-259). El build local por tanto los tiene, pero el empaquetado de CI/release no los incluia:
la release v0.6.1 salio sin traducciones, logos HD, SFX de menu ni plantillas de guardado. Este
script materializa exactamente ese subconjunto en el directorio de distribucion para que CI y el
build local sirvan los mismos datos.

Uso:
  windows:  python3 tools/package_release.py --platform windows \
                --bin-dir build/windows/bin/Release --out dist
  linux:    python3 tools/package_release.py --platform linux --bin /tmp/hh-bin \
                --out dist/HybridHeavenRecomp-Linux

No genera el archivo (zip/tar); lo hace el paso de CI que corresponda.
"""

from __future__ import annotations

import argparse
import shutil
import sys
from pathlib import Path


def copy_glob(src: Path, pattern: str, dst: Path, required: bool = True) -> int:
    if not src.is_dir():
        if required:
            raise SystemExit(f"ERROR: no existe el directorio de datos {src}")
        return 0
    files = sorted(p for p in src.glob(pattern) if p.is_file())
    if required and not files:
        raise SystemExit(f"ERROR: no hay ficheros '{pattern}' en {src}")
    dst.mkdir(parents=True, exist_ok=True)
    for f in files:
        shutil.copy2(f, dst / f.name)
    return len(files)


def copy_file(src: Path, dst: Path) -> None:
    if not src.is_file():
        raise SystemExit(f"ERROR: falta {src}")
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)


def stage_binaries(args: argparse.Namespace, out: Path) -> None:
    if args.platform == "windows":
        if not args.bin_dir:
            raise SystemExit("ERROR: --bin-dir es obligatorio para windows")
        bd = Path(args.bin_dir).resolve()
        exe = bd / "Hybrid Heaven Recomp.exe"
        copy_file(exe, out / exe.name)
        dlls = sorted(p for p in bd.glob("*.dll") if p.is_file())
        if not dlls:
            raise SystemExit(f"ERROR: no hay DLLs en {bd}")
        for dll in dlls:
            shutil.copy2(dll, out / dll.name)
    else:
        if not args.bin:
            raise SystemExit("ERROR: --bin es obligatorio para linux")
        copy_file(Path(args.bin).resolve(), out / "Hybrid Heaven Recomp")


def stage_data(root: Path, platform: str, out: Path) -> None:
    # Los mismos datos que copia el POST_BUILD de CMake.
    copy_glob(root / "assets" / "lang", "*.txt", out / "assets" / "lang")
    copy_glob(root / "assets" / "sounds", "*.wav", out / "assets" / "sounds")
    copy_glob(root / "assets" / "logos", "*.png", out / "assets" / "logos")
    copy_glob(root / "assets" / "saves" / "templates", "*", out / "saves" / "templates")
    # Licencia de la fuente embebida (Work Sans, OFL-1.1): la exige la licencia.
    copy_file(root / "assets" / "fonts" / "OFL.txt", out / "licences" / "OFL.txt")

    # Documentacion del port.
    copy_file(root / "docs" / f"BUILDING_{platform}.md", out / "LEEME.txt")
    copy_file(root / "CREDITS.md", out / "CREDITOS.md")
    copy_file(root / "LICENSE", out / "LICENCIA.txt")

    # Carpeta guia para la ROM del usuario (el juego no la incluye).
    rom = out / "rom"
    rom.mkdir(parents=True, exist_ok=True)
    sep = "\\" if platform == "windows" else "/"
    (rom / "PON_AQUI_LA_ROM.txt").write_text(
        "Coloca aqui tu ROM de Hybrid Heaven (USA, NHVE, 16 MB).\n"
        "\n"
        f"  Nombre esperado:  rom{sep}baserom.us.z64\n"
        "\n"
        "El juego NO incluye la ROM (copyright de Konami): la aporta cada usuario.\n"
        "Ver LEEME.txt para mas detalles.\n",
        encoding="utf-8",
    )


def main() -> int:
    root_default = Path(__file__).resolve().parents[1]
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--platform", choices=["windows", "linux"], required=True)
    ap.add_argument("--out", required=True, help="directorio de distribucion")
    ap.add_argument("--root", default=str(root_default), help="raiz del repo (por defecto)")
    ap.add_argument("--bin", help="binario ya compilado (linux)")
    ap.add_argument("--bin-dir", help="directorio con el .exe y *.dll (windows)")
    args = ap.parse_args()

    root = Path(args.root).resolve()
    out = Path(args.out).resolve()
    out.mkdir(parents=True, exist_ok=True)

    stage_binaries(args, out)
    stage_data(root, args.platform, out)
    print(f"Empaquetado {args.platform} -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
