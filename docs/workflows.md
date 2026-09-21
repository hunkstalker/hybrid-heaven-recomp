# Workflows operativos

> Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle
> histórico, a `../notes/`.

## 0. Primer setup (regenerar la recompilación desde la ROM)

El código del juego no está plano en la ROM (Konami lo comprime con **LZKN64**, tabla
Nisitenma-Ichigo). Se regenera **determinísticamente** desde la ROM del usuario con el pipeline
**ELF/splat** (ADR 0011; detalle en §5c). Requisito: ROM US retail en `work/roms/us_retail.z64`
(gitignored; la aporta el usuario). **El C recompilado no se versiona** (ADR 0009).

```sh
python3 tools/regenerate.py     # ROM -> imagen expandida -> splat -> asm -> ELF (gate byte a byte)
                                #      -> N64Recomp (ELF mode) -> build/recomp/RecompiledFuncs
```

Herramientas (todas en `recomp/tools/`): `analyze_code_files.py` (manifiesto de los 91 code files +
imagen expandida), `unpack_rom.py`, `gen_splat_yaml.py`, `splat_headless.sh`, `build_elf.sh`
(`llvm-mc` + `ld.lld`), `gen_link_syms.py`, `gen_reimplemented_decls.py`, `gen_runtime_func_table.py`,
`gen_file_table.py` (`include/hh/file_table.h`). El pipeline **per-file/Ghidra** (§5b) queda
**obsoleto** y archivado en `legacy/`.

## 1. Regenerar la recompilación y construir

**El C recompilado no se versiona** (obra derivada; ADR 0009). Se regenera una vez desde la ROM con
**`tools/regenerate.py`** (dependencias de **desarrollo**: Python 3.11+, splat+spimdisasm
—`recomp/tools/install_splat.sh`—, LLVM MIPS `llvm-mc`/`ld.lld`, N64Recomp, RSPRecomp):

```sh
python3 tools/regenerate.py                 # ROM -> splat -> asm -> ELF -> N64Recomp -> build/recomp
python3 tools/regenerate.py --skip-splat    # reutiliza build/recomp/asm (iterar build_elf/N64Recomp)
python3 tools/regenerate.py --skip-elf      # reutiliza build/recomp/elf (iterar N64Recomp)
python3 tools/regenerate.py --rom ROM       # ROM explicita
python3 tools/regenerate.py --build         # compila el port al final
```

Genera `work/recomp_elf/RecompiledFuncs/` y lo **materializa como directorio real** en
`build/recomp/RecompiledFuncs/` (no symlink: Windows no los resuelve), más
`include/hh/file_table.h`. Luego compila con `tools/build_linux.sh` / `build_windows.bat`.

Regla: **nunca editar a mano el C generado**; todo fix va a la config de splat/símbolos
(`recomp/*.yaml`, `recomp/symbol_addrs.txt`) o al toolchain, y se regenera.

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
  (`git -C lib/N64ModernRuntime checkout <sha> && git add` en el port). `runtime.lock` queda como
  referencia/fallback. Para iterar el fork local sin publicar: `build_windows.local.bat` (Windows) o
  `tools/build_linux.sh` sin `--force-libs` (si `lib/` ya existe, no toca git).
- **Docker** (`Dockerfile` multi-stage, Debian/glibc): `docker compose build run`. Clona las deps
  (rt64 + fork del runtime) por el lock; stages `deps` (también devcontainer) / `build` / `runtime`.
  Headless: `HH_HEADLESS=1 docker compose run --rm run` (Xvfb + lavapipe). GUI en host Linux:
  `--device /dev/dri` + socket X11 (ver `docs/BUILDING_linux.md`).
- **CI / releases (un solo flujo de compilación)**: `ci.yml` compila en cada push/PR y sube
  **artefactos** (`HybridHeavenRecomp-Windows.zip`, `HybridHeavenRecomp-Linux.tar.gz`) + valida docs.
  `release.yml` **no recompila**: localiza el run de CI **verde** de ese commit, descarga sus
  artefactos, crea el Release (tag `v*` o manual con `version`) y monta la imagen `ghcr.io` desde el
  binario (`docker/Dockerfile.runtime`). El CI **no** ejecuta el juego: la ROM no se sube nunca.
  **C recompilado (ADR 0009)**: no se versiona; como no cabe en un secret de Actions (límite 48 KB),
  el CI lo trae de un **repo privado de secretos** (patrón Goemon/Zelda64Recomp) clonado con un PAT:
  variable `HH_SECRETS_REPO` (por defecto `hunkstalker/hh-recomp-secrets`) + secreto `HH_SECRETS_PAT`
  (fine-grained, `Contents:Read`); copia `RecompiledFuncs/` y `rsp/hh_aspMain.cpp` a `build/recomp/`. **Sin el PAT, los
  builds se saltan** (CI verde) con un aviso. Publicar el `RecompiledFuncs` (y la ROM) a ese repo es
  paso manual del mantenedor (`tools/regenerate.py` + `git push`).
- Detalle de la decisión: `adr/0005-build-reproducible-y-artefactos.md` y
  `adr/0009-no-versionar-c-recompilado.md`.

## 2. Ejecutar headless (Linux)

```sh
cd build/linux
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

> **Obsoleto** con el pipeline ELF/splat (§5c): las fronteras vienen de la **imagen completa** y no se
> parchean a mano (`add_mid_entry`, `module_extras.json`, `keep_syms` → `legacy/`). Si tras regenerar
> quedan fallthroughs, `python3 tools/analysis/fix_fallthroughs.py` es un paso manual.
- `HH_SOFT_LOOKUP=1` (solo para depurar símbolos) permite seguir con stub no-op; los stubs falsean
  la lógica del juego, no usar para validar.
- `tools/analysis/fix_function_bounds.py <syms> --rom <rom> --report-only`: asesor CFG (propone
  inicios; **no** auto-aplicar: sobre-parte).

## 5b. Recompilación per-file (HISTÓRICO — sustituido por §5c)

Método mantenido solo como referencia histórica (fuente del enunciado del bloqueo del CaC, ya
resuelto). Los comandos originales (Ghidra por fichero, validación de syms, N64Recomp per-file) y sus
herramientas están en `legacy/tools/` y `legacy/config/`; el estado de aquel bloqueo, en
`../notes/2026-09-20-pipeline-per-file-estado.md`. Se sustituyó por **splat/ELF** (ADR 0011, §5c)
porque las fronteras de imagen completa eliminan los parcheos manuales.

## 5c. Recompilación por ELF + splat (pipeline activo, ADR 0011)

Sustituye a §5b (ADR 0011). Piezas (todas generan salida bajo `build/recomp/`, gitignored):
1. `recomp/tools/analyze_code_files.py` + `unpack_rom.py` → **imagen expandida**
   (`work/scratch/expanded/hh.expanded.z64`: ROM + cada code file descomprimido en offset sintético
   >16 MB) + `segments.json` + `include/hh/file_table.h`.
2. `gen_splat_yaml.py` → config de **splat** (`recomp/hybrid-heaven.us.yaml`: residente + `file_008`
   globales; resto `exclusive_ram_id: overlay`; `asm_data_macro: dlabel`, `asm_jtbl_label_macro: jlabel`).
3. `recomp/tools/splat_headless.sh split …` → `build/recomp/asm/`; `build_elf.sh` normaliza/ensambla con
   `llvm-mc -triple=mips -mcpu=mips3` y enlaza con `ld.lld` → `build/recomp/elf/hybrid-heaven.us.elf`.
4. N64Recomp en **ELF mode** (`recomp/hybrid-heaven.us.toml`: `elf_path`,
   `use_lookup_for_all_function_calls`, `relocatable_sections_path`).
5. **RSPRecomp** (`recomp/rsp_hh_aspMain.toml`) → `build/recomp/rsp/hh_aspMain.cpp` (ucode de audio;
   también derivado → generado, no versionado).
6. **Gates**: segmentos byte-idénticos a la imagen; `jal` 0 mid-function/nowhere; conteos
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

### 6.2 Instrumentación y rebuild del recompilador

- **`tools/analysis/emu_ref.sh <prefix> <secs> [dumps]`**: `r64dump` con 4 MB + input + RSP-HLE +
  **vídeo real rice/GLX** (Xvfb :99 con GLX). Única configuración que progresa como BizHawk. Requiere
  `apk add mesa-dri-gallium libsamplerate` y `r64dump` con rutas del proyecto
  (`MU64_CFGDIR`/`MU64_DATADIR` → `work/debug/mupen*`; config `DisableExtraMem=1`).
- **Escritores**: `work/libmupen64plus-wplog.so` + `HH_WPLOG=1 HH_WPLO=<hex> HH_WPHI=<hex>` (log con PC
  del rango físico). Fuente `work/mupen-src` (rebuild: `make -C projects/unix all OSD=0 VULKAN=0
  DEBUGGER=1`; requiere `binutils-dev`).
- **Trazas**: `HH_CALLTRACE` (port, indirectas) y `HH_JALTRACE` (emu, todos los saltos; no dispatches de
  hilo). **No alinear por posición**: comparar por ventanas o subsecuencia.
- **Diff**: `tools/analysis/diff_rdram.py <port> <emu> [base size]` (resumen por bloques).
- **Rebuild del recompilador**: binario `toolchain/src/N64Recomp/build_recomp/N64Recomp`; usar
  **`--target N64RecompCLI`** (`--target N64Recomp` no relinkea: “el cambio no se aplica”). Tras tocar
  `symbol_lists.cpp`: rebuild del tool → `python3 tools/regenerate.py`.

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
