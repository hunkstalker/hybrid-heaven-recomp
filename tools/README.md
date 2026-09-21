# Herramientas del proyecto

Todo el proyecto vive en la raíz del repo (ver `PROYECTO.md`). No usar carpetas temporales del
sistema para nada del proyecto. La referencia operativa completa está en `docs/workflows.md`.

## Estructura

| Ruta | Contenido |
|---|---|
| `tools/` | Scripts propios **vivos** (wrapper de build, pipeline, análisis). |
| `recomp/` | Configuración del pipeline de recompilación (versionada) + `recomp/tools/`. |
| `legacy/` | Vía antigua **Ghidra per-file** (histórico; no se usa). |
| `toolchain/`, `work/` | Dependencias descargables y artefactos (gitignored). |

### `tools/` (vivos)

| Ruta | Contenido |
|---|---|
| `tools/regenerate.py` | **Entrada única del pipeline**: regenera el C desde la ROM (invoca `recomp/tools/*` → `build/recomp/RecompiledFuncs`). Ver `docs/workflows.md` §1. |
| `tools/build_linux.sh` | Clona/actualiza las libs (`lib/`) + CMake + build (Release; `--debug`, `--force-libs`). |
| `tools/rommy.py` | Extracción/compresión de la tabla Konami **Nisitenma-Ichigo** (konami_fs). |
| `tools/lzkn64/lzkn64.py` | `lzkn64` en Python puro (`decompress`/`compress`); evita Rust. Se importa con `PYTHONPATH=tools`. |
| `tools/analysis/` | Análisis de ROM, oráculo de emulador, capturas e índice de docs. Ver abajo. |
| `tools/diag/` | Bats de diagnóstico (replay/watch) para el mantenedor. |

`tools/analysis/` (selección): `analyze_rom.py` (densidad MIPS), `validate_syms.py`,
`docs_index.py` (genera/valida `docs/INDEX.md`), `emu_ref.sh` / `r64dump.cpp` (oráculo con emulador,
`docs/workflows.md` §6), `diff_rdram.py`, `triage_screenshots.py`, `bizhawk_*`, `xshot`.

### `recomp/tools/` (pipeline ELF/splat, ADR 0011)

`analyze_code_files.py` (manifiesto de los 91 code files) · `unpack_rom.py` (imagen expandida +
`include/hh/file_table.h`) · `gen_splat_yaml.py` · `splat_headless.sh` · `build_elf.sh`
(`llvm-mc`+`ld.lld`, gate byte a byte) · `gen_link_syms.py` · `gen_reimplemented_decls.py` ·
`gen_runtime_func_table.py` · `gen_file_table.py`.

### `legacy/`

Vía antigua conservada como histórico: `legacy/tools/` (`ghidra_sections.py`, `install_ghidra.sh`,
`ghidra_headless.sh`, `setup_module.py`, `recomp.py`, `analysis/`) y `legacy/config/` (tomls y
syms por módulo/fichero). **No usar** para el pipeline vigente.

## Uso

```sh
python3 tools/regenerate.py                 # ROM -> pipeline ELF/splat -> build/recomp (ver §1)
python3 tools/regenerate.py --skip-splat    # reutiliza build/recomp/asm
python3 tools/regenerate.py --skip-elf      # reutiliza build/recomp/elf
tools/build_linux.sh                        # compila el port
python3 tools/analysis/docs_index.py        # regenera docs/INDEX.md (--check valida, CI)
```

## `toolchain/` y `work/` (gitignored)

- `toolchain/splat-venv/` — venv con **splat + spimdisasm** (dev; `recomp/tools/install_splat.sh`).
- `toolchain/src/N64Recomp/` — recompilador (fork; rebuild con `--target N64RecompCLI`).
- `toolchain/ghidra/` — JDK + Ghidra (solo vía legacy).
- `work/roms/` — ROMs del usuario; `work/scratch/` — extracción e imagen expandida; `work/debug/` —
  dumps y capturas; `work/recomp_elf/` — salida de N64Recomp antes de materializarse.
