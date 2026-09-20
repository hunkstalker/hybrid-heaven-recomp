# Workflows operativos

> Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle
> histórico, a `../notes/`.

## 0. Primer setup (reconstruir los artefactos de los módulos desde la ROM)

Los módulos de código (boot: Nisitenma idx **7, 23, 54**) no están planos en la ROM (Konami los
comprime con **LZKN64**, tabla Nisitenma-Ichigo). Se reconstruyen **determinísticamente** desde la
ROM del usuario:

```sh
python3 tools/setup_module.py --build
# ROM -> blobs (lzkn64) -> config/us_module{7,23,54}.syms.toml
#     -> work/scratch/us_combined.z64 -> config/us_combined.syms.toml
#     -> recompila el set combinado y construye (--build)
```

Sin `--build`, solo regenera los artefactos; luego `recomp.py --config config/game_combined.toml --build`.
Requisito: ROM US retail en `work/roms/us_retail.z64` (gitignored; la aporta el usuario).

**Añadir un módulo** (al aparecer un `Failed to find function at 0x8...` en zona de módulo):
1. Medir su base: `break FUN_80003824` → `ctx->r4`(src RO)/`r5`(base RAM)/`r6`(size); confirmar que
   `src` es una entrada Nisitenma y que la base es estable en 2-3 runs.
2. Añadir la entrada a `MODULES` en `tools/setup_module.py` (idx, `vram`=base, `rom_off` libre, CRC
   del manifest). Si la función llamada **no** se detecta por prólogo/jal/jr, añadirla a `extra`.
3. `python3 tools/setup_module.py --build`.

**Nota (jump-tables)**: `gen_module_syms.py` fusiona los `switch` (el detector `jr $ra` los parte y
N64Recomp exige las tablas dentro de la función). No reordenar/eliminar ese paso.

`recomp.py` **limpia** `RecompiledFuncs/funcs_*.c` antes de copiar (el número de ficheros cambia).

## 1. Recompilar y construir (pipeline)

Un solo comando: valida syms → regenera (N64Recomp) → copia al port → `fix_fallthroughs` → build.

```sh
python3 tools/recomp.py                 # valida + regenera + copia + fixes
python3 tools/recomp.py --build         # + cmake build_dbg
python3 tools/recomp.py --fix-syms      # intenta corregir la syms si el validador falla
python3 tools/recomp.py --dry-run       # muestra los pasos sin ejecutar
```

Validador de símbolos (detecta **delay-slot cortado**, **ramas cruzadas** y **data-as-code**):

```sh
python3 tools/analysis/validate_syms.py config/us_ghidra.syms.toml
python3 tools/analysis/validate_syms.py config/us_ghidra.syms.toml --fix --out work/debug/fixed.syms.toml
```

Regla: **nunca editar a mano el C generado**. Todo fix va a `config/*.syms.toml` y el validador
lo propone (`--fix`). Windows (usuario): `cmake --build build --target HybridHeavenRecomp --config Debug`.

### 1.1 Build reproducible en Linux (script y Docker)

Para compilar el port **sin** regenerar syms (el C recompilado está versionado):

```sh
tools/build_linux.sh                 # clona deps (fork runtime + rt64) + CMake + build (Release)
tools/build_linux.sh --debug         # Debug
tools/build_linux.sh --force-libs    # re-clona/actualiza las deps
tools/build_linux.sh --help
```

- **Runtime y N64Recomp**: los cambios propios viven en **forks** (`hunkstalker/N64ModernRuntime` y
  `hunkstalker/N64Recomp`, rama `hybrid-heaven`; `main` = upstream). Los scripts clonan por **URL+SHA
  de `port/runtime.lock`** (submódulos incluidos: `N64Recomp` sale del fork, `thirdparty` de
  upstream). No hay patch. Si se añaden commits al runtime: push al fork y actualizar el SHA en
  `port/runtime.lock`. `rt64` se clona del upstream en su commit fijo (sin modificar).
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

La detección estática es poco fiable (jump-tables). La fuente fiable son los `Failed to find
function at 0x...`: el runtime **aborta** al encontrarlos (deja la dirección en consola y en
`hh_missing.log`). Bucle recomendado:

```sh
# 1) registrar la direccion (una sola orden; rechaza delay slots y switches fusionados)
python3 tools/analysis/add_mid_entry.py 0x80379954
# 2) recompilar (--force: el validador fusiona splits legitimas de epilogos compartidos)
python3 tools/recomp.py --config config/game_combined.toml --force
# 3) build (ver §1) y probar
```

- `add_mid_entry.py` edita **solo lo mínimo**: parte el símbolo contenedor en
  `config/us_moduleNN.syms.toml` y `config/us_combined.syms.toml`, y anota la dirección en
  `keep_syms.txt` + `module_extras.json`. **No** usar `setup_module.py` para esto: su detección
  automática (`auto_mid`) puede cascar y meter **datos como código** (rompe el build con
  `0 = cop0_register_read`). Ver `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`.
- **Overrides de tamaño**: los `0xADDR:0xSIZE` de `module_extras.json` deben sobrevivir a la edición.
  `tools/analysis/check_syms_overrides.py` lo verifica y `recomp.py` (paso 1b) **aborta** si falta
  alguno (perder `M9_FUN_802169AC:0x1C0` devolvía el símbolo a `0x4604` → stub `do_break` → cuelgue
  del NPC). Ver `notes/2026-09-16-crash-cinematica-midentry-m9-80203830.md`.
- `fix_fallthroughs.py` (paso automático del pipeline, §1) encadena además cuando la **última
  instrucción ROM** es una **rama condicional** (`beq/bne/beql/bnel/bgtz/...`): su fall-through cae
  al símbolo contiguo aunque la última sentencia C sea un `return`/`goto` dentro del `if` final
  (caso `M55_FUN_8037a6f4` → `0x8037A884`, fuga `0x38`/frame + lógica saltada. Ver
  `notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md`).
- **Nunca** partir dentro de un rango de jump-table fusionada: el switch pierde sus casos como
  etiquetas locales y pasa a `LOOKUP` (regresión real: crash de las escaleras con
  `0x8037C50C/0x8037C530` → `0x8037C8E4`). La herramienta lo detecta y rechaza.
- `HH_SOFT_LOOKUP=1` (solo para depurar símbolos) permite seguir con stub no-op; los stubs falsean
  la lógica del juego, no usar para validar.
- `tools/analysis/fix_function_bounds.py <syms> --rom <rom> --report-only`: asesor CFG (propone
  inicios; **no** auto-aplicar: sobre-parte).

## 5b. Recompilación per-file (en construcción)

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
