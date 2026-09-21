# Workflows operativos

> Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle
> histórico, a `../notes/`.

## 0. Primer setup (regenerar la recompilación desde la ROM)

El código del juego no está plano en la ROM (Konami lo comprime con **LZKN64**, tabla
Nisitenma-Ichigo). Se regenera **determinísticamente** desde la ROM del usuario con el pipeline
**per-file** (ver §1 y §5b). Requisito: ROM US retail en `work/roms/us_retail.z64` (gitignored; la
aporta el usuario). **El C recompilado no se versiona** (ADR 0009).

```sh
python3 tools/regenerate.py     # ROM -> manifiesto (91 code files) -> extracción -> Ghidra por
                                # fichero -> syms -> N64Recomp -> work/recomp/RecompiledFuncs
```

`sus` herramientas: `tools/analyze_code_files.py` (manifiesto + extracción), `tools/ghidra_sections.py`
(Ghidra per-file), `tools/gen_file_table.py` (`include/hh/file_table.h`). El pipeline antiguo por
módulos (`setup_module.py` + `module_sources.inc`) queda **obsoleto** (ver `legacy/`).

## 1. Regenerar la recompilación y construir

**El C recompilado no se versiona** (obra derivada; ADR 0009). Se regenera una vez desde la ROM con
**`tools/regenerate.py`** (dependencias de **desarrollo**: Python 3.11+, JDK 21 + Ghidra, N64Recomp,
RSPRecomp):

```sh
python3 tools/regenerate.py                 # ROM -> manifiesto -> extraccion -> Ghidra per-file
                                            #      -> syms -> N64Recomp -> fallthroughs -> build
python3 tools/regenerate.py --skip-ghidra   # reutiliza work/scratch/syms (iterar N64Recomp)
python3 tools/regenerate.py --rom ROM       # ROM explicita
```

Genera `work/recomp/RecompiledFuncs/` y lo **materializa como directorio real** en
`port/HybridHeavenRecomp/RecompiledFuncs/` (no symlink: Windows no los resuelve), más
`include/hh/file_table.h`. Luego compila con `tools/build_linux.sh` / `port\build_windows.bat`.

Validador de símbolos (detecta **delay-slot cortado**, **ramas cruzadas** y **data-as-code**), parte
del pipeline:

```sh
python3 tools/analysis/validate_syms.py work/scratch/code_files.syms.toml \
    --rom work/scratch/code_combined.z64 --fix --out work/scratch/code_files.fixed.syms.toml
```

Regla: **nunca editar a mano el C generado**; todo fix va a la config/syms y se regenera.

### 1.1 Build reproducible en Linux (script y Docker)

Antes de compilar hay que **regenerar el C** (§1). Después:

```sh
tools/build_linux.sh                 # clona deps (fork runtime + rt64) + CMake + build (Release)
tools/build_linux.sh --debug         # Debug
tools/build_linux.sh --force-libs    # re-clona/actualiza las deps
tools/build_linux.sh --help
```

- **Runtime y N64Recomp**: los cambios propios viven en **forks** (`hunkstalker/N64ModernRuntime` y
  `hunkstalker/N64Recomp`, rama `hybrid-heaven`; `main` = upstream). `lib/rt64` y
  `lib/N64ModernRuntime` son **submódulos git** (ADR 0010): los trae `git clone --recursive` /
  `git submodule update --init --recursive`. `rt64` es upstream en su commit fijo;
  `N64ModernRuntime` es el fork, con su `.gitmodules` anidado (`N64Recomp` del fork, thirdparty de
  upstream). Si se añaden commits al runtime: push al fork y **bump** del gitlink
  (`git -C lib/N64ModernRuntime checkout <sha> && git add` en el port). `port/runtime.lock` queda como
  referencia/fallback. Para iterar el fork local sin publicar: `build_windows.local.bat` (Windows) o
  `tools/build_linux.sh` sin `--force-libs` (si `lib/` ya existe, no toca git).
- **Docker** (`Dockerfile` multi-stage, Debian/glibc): `docker compose build run`. Clona las deps
  (rt64 + fork del runtime) por el lock; stages `deps` (también devcontainer) / `build` / `runtime`.
  Headless: `HH_HEADLESS=1 docker compose run --rm run` (Xvfb + lavapipe). GUI en host Linux:
  `--device /dev/dri` + socket X11 (ver `port/README_linux.md`).
- **CI / releases (un solo flujo de compilación)**: `ci.yml` compila en cada push/PR y sube
  **artefactos** (`HybridHeavenRecomp-Windows.zip`, `HybridHeavenRecomp-Linux.tar.gz`) + valida docs.
  `release.yml` **no recompila**: localiza el run de CI **verde** de ese commit, descarga sus
  artefactos, crea el Release (tag `v*` o manual con `version`) y monta la imagen `ghcr.io` desde el
  binario (`docker/Dockerfile.runtime`). El CI **no** ejecuta el juego: la ROM no se sube nunca.
- Detalle de la decisión: `adr/0005-build-reproducible-y-artefactos.md`.

## 2. Ejecutar headless (Linux)

```sh
cd port/HybridHeavenRecomp/build_dbg
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  timeout 60 "./Hybrid Heaven Recomp"
# Requiere Xvfb :99 (crear si falta) — ver note histórico de sesión.
```

## 3. Protocolo de imágenes (visión por lotes)

**Regla dura**: la plataforma limita a ~**4 imágenes por prompt**, y **cada imagen se queda en el
contexto**. Por eso NUNCA se adjunta un lote grande: se reduce a pocas y **se resume a texto**.

### Paso 1 — Triaje barato (sin visión)
```sh
python3 tools/analysis/triage_screenshots.py "work/gameplay screenshots" --recursive \
  --max 20 --batch 3 --out work/debug/triage
```
Genera:
- `triage.csv` — una fila por PNG: `ts, w, h, bytes, bright, hash, flag (selected/dup), dup_of, txt`.
- `triage.selection.txt` — rutas candidatas a visión.
- `triage.batches.txt` — selección troceada en lotes de `--batch`.

El script decodifica PNG (RGB/RGBA/paleta/gris, 8-bit) con `zlib`+`numpy`, sin ImageMagick.
Duplicados = dHash con distancia Hamming ≤ `--dup-threshold` (def. 6). Escena nueva = supera el
umbral (o cambio de brillo > `--bright-threshold`).

### Paso 2 — Visión en lotes pequeños
- Leer **2-3 imágenes por turno** (nunca >4), siguiendo `triage.batches.txt`.
- **Volcar cada imagen a texto inmediatamente** (una línea por archivo, p. ej. en la nota del día):
  qué se ve, HUD sí/no, menú/tipo de escena, texto legible.
- Ese texto es el artefacto duradero. **No re-adjuntar** la imagen en turnos posteriores.

### Paso 3 — Correlación PNG ↔ dumps
El tracker BizHawk nombra los PNG con wall-clock y escribe un `.txt` por captura; emparejar por
nombre base y por tiempo (`triage.csv` ya marca `txt=yes/no`). Así se ata overlay↔pantalla↔botones.

## 4. Cómo NO usar imágenes

- No adjuntar una carpeta entera ni "analiza estas 50 imágenes".
- No re-adjuntar lo ya resumido a texto.
- Para inspección masiva/de frames, preferir ASCII/estadísticas (barato) y reservar la visión a
  casos concretos.

## 5. Completar símbolos faltantes (evidencia runtime)

> **Obsoleto** con el pipeline per-file (ver §5b): las fronteras vienen de Ghidra por fichero y no se
> parchean a mano (`add_mid_entry`, `module_extras.json`, `keep_syms` → `legacy/`). `fix_fallthroughs.py`
> sigue usándose (lo invoca `tools/regenerate.py`).
- `HH_SOFT_LOOKUP=1` (solo para depurar símbolos) permite seguir con stub no-op; los stubs falsean
  la lógica del juego, no usar para validar.
- `tools/analysis/fix_function_bounds.py <syms> --rom <rom> --report-only`: asesor CFG (propone
  inicios; **no** auto-aplicar: sobre-parte).

## 5b. Recompilación per-file (pipeline activo)

Método correcto (sustituye a `setup_module.py` + `module_sources.inc`): **todos** los ficheros de
código como secciones relocalizables. Método/porqué en
`notes/2026-09-20-lecciones-recompilacion-per-file.md`; estado y bloqueos en
`notes/2026-09-20-pipeline-per-file-estado.md`.

```sh
# Ghidra es dep. de desarrollo (no de build)
tools/install_ghidra.sh

# 1) manifiesto de los 91 code files + extracción
python3 tools/analyze_code_files.py work/roms/us_retail.z64 --extract work/scratch/code_files

# 2) Ghidra por fichero -> work/scratch/syms/file_NN.toml + ROM combinado
python3 tools/ghidra_sections.py --only 57      # prueba de un fichero
python3 tools/ghidra_sections.py --all          # los 91

# 3) validar/corregir fronteras (delay-slots, ramas cruzadas)
python3 tools/analysis/validate_syms.py work/scratch/code_files.syms.toml \
    --rom work/scratch/code_combined.z64 --fix --out work/scratch/code_files.fixed.syms.toml

# 4) recompilar el set per-file
./toolchain/src/N64Recomp/build_recomp/N64Recomp config/game_code_files.toml
```

Artefactos: `config/code_files.json` + `config/code_files.overlays.txt` (set de ficheros);
`work/scratch/{code_files/,syms/,code_combined.z64,code_files.fixed.syms.toml}` (generado).
**Pendiente** (no cierra aún): jump-tables, funciones que acaban en `jal`/`jr` no-RA, residente
regenerado excluyendo overlays y los loaders `recomp_load_overlays`/`unload_overlays`.

> **EN MIGRACIÓN (2026-09-21, ADR 0011):** esta vía Ghidra-per-file se sustituye por **splat/ELF**
> (fronteras de imagen completa). Plan y fases: `../notes/2026-09-21-migracion-via-referencia-elf.md`.
> Toolchain de desarrollo: `tools/install_splat.sh` (venv con splat + spimdisasm) y ensamblador/
> enlazador MIPS por LLVM (`llvm-mc`/`ld.lld`). Wrapper: `tools/splat_headless.sh`.

## 5c. Recompilación por ELF + splat (vía nueva, en curso)

Sustituye a §5b (ADR 0011). Piezas:
1. `tools/analyze_code_files.py` → **imagen expandida** (`hh.expanded.z64`: ROM + cada code file
   descomprimido en offset sintético >16 MB) + `segments.json` + `file_table.h`.
2. `gen_splat_yaml` → config de **splat** (residente + `file_008` globales; resto
   `exclusive_ram_id: overlay`; `asm_data_macro: dlabel`, `asm_jtbl_label_macro: jlabel`).
3. `tools/splat_headless.sh split …` → `asm/`; ensamblar con `llvm-mc -triple=mips-linux-gnu` y
   enlazar con `ld.lld -m elf32btsmip` → `hybrid-heaven.us.elf`.
4. N64Recomp en **ELF mode** (`elf_path`, `use_lookup_for_all_function_calls`,
   `relocatable_sections_path`).
5. **Gates**: segmentos byte-idénticos a la imagen; `jal` 0 mid-function/nowhere; conteos
   reconciliados; sin datos-como-código.

## 6. Oráculo con emulador (comparar port vs juego real)

`work/r64dump` corre la ROM bajo `libmupen64plus` **headless** y vuelca RDRAM por la API de depuración.
Es la referencia para saber si una variable/flujo del port diverge. Requisitos: `SDL_AUDIODRIVER=dummy`.

```sh
# Dumps completos de 8 MB en t = 5,10,20,40 s
SDL_AUDIODRIVER=dummy CORE_SO=work/libmupen64plus-debug.so HH_DUMP_TIMES=5,10,20,40 \
  timeout 70 ./work/r64dump work/roms/us_retail.z64 work/debug/emu 55
# -> work/debug/emu.t0.bin, .t1.bin, ... (8 MB cada uno) + volcado final

# Watchpoint de escritura (rango de 1 KB en una vaddr); loguea PC+tiempo de cada write
SDL_AUDIODRIVER=dummy CORE_SO=work/libmupen64plus-debug.so \
  HB_RES_DIR=0x801CFE00 HH_WP_ARM=3 timeout 20 ./work/r64dump work/roms/us_retail.z64 work/debug/emu_wp 15
```

**Endianness (CRÍTICO)**: el buffer RDRAM (emulador y port) está **word-swapped**. Para leer el valor
CPU real:
- `u32(V)` = little-endian en offset `V & 0x1FFFFFFF`
- `u16(V)` = little-endian en offset `(V ^ 2) & 0x1FFFFFFF`  ← ojo al `^2`
- `u8(V)`  = byte crudo en offset `(V ^ 3) & 0x1FFFFFFF`

Para volcar la RDRAM del port: `dump binary memory <out> (char*)rdram (char*)rdram+0x800000` en gdb
(con `rdram` en scope). Comparar port vs `emu.tN.bin` en la misma vaddr.

> Nota: los watchpoints de la API de depuración solo ven **stores de CPU**. Los cambios hechos por
> **DMA/RSP** no se capturan; si una variable cambia sin write logueado, es DMA.

### 6.1 Volcado alineado y diff port↔emulador

Para hallar divergencias sin adivinar, se alinea un **evento** (p. ej. el write de un callback) y se
vuelca RDRAM en ambos lados:

```sh
# Emulador: volcado one-shot al primer write del watchpoint (tras HH_WP_ARM)
HB_RES_DIR=0x801D03DC HB_WP_SIZE=4 HH_WP_ARM=7.9 HB_DUMP_ON_WP=work/debug/emu_at.bin \
  SDL_AUDIODRIVER=dummy CORE_SO=work/libmupen64plus-debug.so timeout 25 \
  ./work/r64dump work/roms/us_retail.z64 work/debug/emu 20
```

```gdb
# Port: mismo evento (aquí, la copia de la tarea con dest=0x801D03C0) y dump de RDRAM
break FUN_80005b98 if (unsigned)ctx->r4 == 0x801D03C0u
commands
  silent
  dump binary memory work/debug/port_at.bin (char*)rdram (char*)rdram+0x800000
  quit
end
run
```

Diff (palabras de 32 bits, endianness del buffer = LE):

```python
a=open("emu_at.bin","rb").read(); b=open("port_at.bin","rb").read()
for off in range(0,0x800000,4):
    if a[off:off+4]!=b[off:off+4]: print(hex(off|0x80000000))
```

**Resultado medido (2026-09-11)**: código de módulos y tablas estáticas **idénticos**; la divergencia
está en **estado mutado** (el buffer scratch `0x8005BDB4`, estructuras de hilo, etc.), así que el diff
puntual es ruidoso → el siguiente refinamiento es un **write-trace diff** (traza de writes ordenada).

## 7. Documentación (índice y validación)

`docs/INDEX.md` es **generado** (no editar a mano): agrupa todos los `.md` del proyecto (raíz,
`docs/`, `notes/`) con título, resumen, líneas y fecha, y valida enlaces relativos y presupuestos de
tamaño de los docs vivos.

```sh
python3 tools/analysis/docs_index.py          # regenera docs/INDEX.md y valida
python3 tools/analysis/docs_index.py --check  # solo valida (útil como pre-commit/CI)
```

Reglas que aplica: `AGENTS`/`PROYECTO`/`TODO`/`documentation` tienen límite duro (si se supera, el
checker sale != 0); los `.md` vivos por encima de 250 líneas avisan. Si un doc vivo crece, recortar
y archivar según `documentation.md` §6.
