# Herramientas del proyecto

Todo el proyecto vive en la raíz de este repo (ver `PROYECTO.md` §8). No usar carpetas temporales
del sistema para nada del proyecto: se borran entre sesiones.

## Estructura rápida

| Ruta | Contenido |
|---|---|
| `tools/rommy.py` | Extracción/compresión de la tabla de archivos Konami **Nisitenma-Ichigo** (konami_fs) |
| `tools/lzkn64/lzkn64.py` | Implementación Python pura `lzkn64` (API `decompress`/`compress`). El wheel pip (Rust/PyO3) requiere Python ≤3.13; este shim evita Rust. Se importa como paquete `lzkn64` con `PYTHONPATH=tools` |
| `tools/analysis/` | Scripts de análisis de ROM: `analyze_rom.py` (densidad MIPS), `detect_lzkn64.py`, `scan_lzkn64_strict.py`, `test_lzkn64.py`, `textseg.py` |
| `work/roms/` | ROMs del usuario descomprimidas (`us_dec.z64`, `eu_dec.z64`) — gitignored |
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

Requisitos: JDK 21 (`/usr/lib/jvm/java-21-openjdk`) ya detectado por Ghidra; la extensión
N64LoaderWV está instalada a nivel de usuario
(`~/.config/ghidra/ghidra_12.1.3_PUBLIC/Extensions/N64LoaderWV`).

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

Opciones del loader relevantes (ver README de N64LoaderWV):
`-loader-rdram <dump>` (overlays ya cargados en RAM, must be 4/8 MiB),
`-loader-signature <n64sym>`, `-loader-pif`, `-loader-modem`.

### Notas
- El venv se puede recrear con `python3 -m venv toolchain/venv && toolchain/venv/bin/pip install pyyaml`.
- Los repos de toolchain se clonan/actualizan por su URL canónica; no son fuente del proyecto.