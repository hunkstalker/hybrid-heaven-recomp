# Herramientas del proyecto

Todo el proyecto vive en la raíz de este repo (ver `PROYECTO.md` §8). No usar carpetas temporales
del sistema para nada del proyecto: se borran entre sesiones.

## Estructura rápida

| Ruta | Contenido |
|---|---|
| `tools/rommy.py` | Extracción/compresión de la tabla de archivos Konami **Nisitenma-Ichigo** (konami_fs) |
| `tools/lzkn64/lzkn64.py` | Implementación Python pura `lzkn64` (API `decompress`/`compress`). El wheel pip (Rust/PyO3) requiere Python ≤3.13; este shim evita Rust. Se importa como paquete `lzkn64` con `PYTHONPATH=tools` |
| `tools/regenerate.py` | **Pipeline per-file completo** desde la ROM (dependencia de mantenedor): manifiesto → extracción → Ghidra → syms → N64Recomp → `work/recomp/RecompiledFuncs` + `file_table.h`. Ver `docs/workflows.md` §1 |
| `tools/analyze_code_files.py` | **Pipeline per-file**: enumera la tabla Nisitenma + VRAM y clasifica los **91 code files** → `recomp/code_files.json` + `recomp/code_files.overlays.txt` |
| `tools/ghidra_sections.py` | **Pipeline per-file**: por fichero (Ghidra → syms `.file_NN`), construye el ROM combinado y agrega `work/scratch/code_files.syms.toml` |
| `tools/gen_file_table.py` | `include/hh/file_table.h` (`id→{vram,size}`) en orden de `code_files.overlays.txt` |
| `tools/ghidra_headless.sh` | Wrapper de `analyzeHeadless` (Ghidra es dep. de **desarrollo**) |
| `tools/install_ghidra.sh` | Instala JDK 21 + Ghidra + N64LoaderWV en `toolchain/ghidra/` |
| `tools/analysis/ghidra_code/` | Scripts Ghidra del pipeline: `FindIndirectFunctions`, `SeedFunctionStarts`, `ExportSectionSyms` |
| `tools/analysis/` | Scripts de análisis de ROM: `analyze_rom.py` (densidad MIPS), `validate_syms.py`, etc. |
| `work/roms/` | ROMs del usuario descomprimidas (`us_dec.z64`, `eu_dec.z64`) — gitignored |
| `work/scratch/code_files/`, `work/scratch/syms/`, `work/scratch/code_combined.z64` | Extracción y syms por fichero (generado, gitignored) |
| `work/ghidra/proj/` | Proyecto Ghidra `HH` con `baserom.us.z64` importado (N64LoaderWV) — gitignored |
| `toolchain/ghidra/` | Ghidra 12.1.3 (instalado + zip) — gitignored |
| `toolchain/venv/` | Virtualenv Python (PyYAML y dependencias) — gitignored |
| `toolchain/ext/` | N64LoaderWV (zip + fuente) — gitignored |

## Uso

### Extraer la ROM (Nisitenma-Ichigo)

```sh
PYTHONPATH=tools toolchain/venv/bin/python tools/rommy.py decompress \
    -i rom/baserom.us.z64 -o work/roms/us_dec.z64 -m work/roms/us_manifest.yaml
```

Salidas: ROM descomprimida (assets expandidos) + manifest (`notes/` guarda copia).

### Ghidra (análisis headless)

Ghidra es una **dependencia de desarrollo** (regenerar símbolos), **no** de build/uso del port.
Instalación reproducible:

```sh
tools/install_ghidra.sh            # JDK 21 + Ghidra 12.1.3 + N64LoaderWV en toolchain/ghidra/
tools/ghidra_headless.sh -help     # wrapper (usa JAVA_HOME del JDK 21)
```

```sh
G=toolchain/ghidra/ghidra_12.1.3_PUBLIC
P=work/ghidra/proj

# Importar una ROM (ya hecho para baserom.us.z64)
$G/support/analyzeHeadless $P HH -import rom/baserom.us.z64 \
    -loader N64LoaderWVLoader -overwrite

# Re-procesar/reejecutar scripts sobre el programa ya importado
$G/support/analyzeHeadless $P HH -process baserom.us.z64 -noanalysis \
    [-scriptPath ...] [-postScript ...]
```

Pipeline **per-file** (todos los code files como secciones `.file_NN`):

```sh
python3 tools/analyze_code_files.py work/roms/us_retail.z64 --extract work/scratch/code_files
python3 tools/ghidra_sections.py --only 57     # o --all
```

Opciones del loader relevantes (ver README de N64LoaderWV):
`-loader-rdram <dump>` (overlays ya cargados en RAM, must be 4/8 MiB),
`-loader-signature <n64sym>`, `-loader-pif`, `-loader-modem`.

### Notas
- El venv se puede recrear con `python3 -m venv toolchain/venv && toolchain/venv/bin/pip install pyyaml`.
- Los repos de toolchain se clonan/actualizan por su URL canónica; no son fuente del proyecto.