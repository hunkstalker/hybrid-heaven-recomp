# AGENTS.md — arranque de sesión

Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + Steam Deck.
Fase actual: **arranque/carga**. Dos causas raíz ya resueltas: (1) el juego exige **4 MB de RDRAM**
(`osGetMemSize=0x400000`; fix en `recomp.cpp`) y (2) el port tenía **stubeada la init de libultra**
(des-stubbing del toolchain, ver **ADR 0002**). El port ya no aborta y su cadena de boot coincide con
el emulador. **Loader y directorio Nisitenma descartados** (idénticos al emulador; el port sí carga
idx54 vía `FUN_801079B0`). **Resuelto el bloqueo VI (ADR 0003)**: VI libultra del ROM + runtime leyendo registros MMIO; gate
de tareas RSP reabierto (dispatcher 430/45 s, loader 10 módulos, 1359 DLs a RT64, 0 símbolos
faltantes). Sigue `fase=0`: los callbacks de progreso del módulo 23 (`FUN_801CBDC0`/`FUN_801CBE88`/
`FUN_801CBE90`, que avanzan `0x801CFE00/02`) no se ejecutan (nodo de boot `+0x1C=0x801BF1CC`).
Detalle: `notes/2026-09-13-vi-opcion-a-implementada.md` y `TODO.md` #14. **Para retomar, leer el
work order `notes/2026-09-13-workorder-gate-rsp.md`** (autocontenido).

## Persistencia y entorno (CRÍTICO)

- **Todo artefacto persistente debe vivir bajo `/app`** (idealmente en `hybrid-heaven-recomp/`, p. ej.
  `work/debug/`). **`/tmp` no persiste entre sesiones** y además contaminaba al usuario: no usar `/tmp`
  para logs, trazas, dumps ni scripts. Si una herramienta externa escribe a `/tmp`, copiar el resultado
  al proyecto al terminar.
- El entorno Linux puede resetearse a una **Alpine mínima** sin toolchain. Es **todo reinstalable** con
  `apk`:
  - Build: `apk add build-base cmake ninja python3 gdb py3-numpy`
  - Runtime del port: `apk add sdl2 gtk+3.0 vulkan-loader mesa-vulkan-swrast xvfb xauth libx11 libxtst imagemagick`
  - Dev del build: `apk add sdl2-dev vulkan-loader-dev mesa-dev libx11-dev gtk+3.0-dev`
  - Tras reinstalar, reconfigurar CMake en `build_dbg` (`cmake .`) por si cambian rutas.
- Los artefactos ya construidos (`work/*.so`, `work/r64dump`, binario del port, `toolchain/`) sobreviven
  en `/app` y no hay que regenerarlos.

## Lee esto (y solo esto) al empezar

1. **`docs/documentation.md`** — cómo documentar (normativo; leer cada sesión).
2. **`PROYECTO.md`** — contexto y estado (corto).
3. **`TODO.md`** — qué toca ahora.
4. **`docs/architecture.md`** — modelo técnico (memoria, `trans`, runtime).
5. Bajo demanda: `docs/workflows.md` (procedimientos), `docs/adr/`, `notes/` (evidencia), `notes/archive/`.
6. Índice completo de la documentación (generado): **`docs/INDEX.md`**. Regenerar/validar:
   `python3 tools/analysis/docs_index.py` (`--check` valida enlaces y tamaños sin escribir).

## Al cerrar sesión

Sigue el checklist de `docs/documentation.md` §3: actualizar `TODO.md` y `PROYECTO.md`, escribir una
nota fechada en `notes/`, y crear un ADR si hubo decisión estructural. No commitear salvo petición.

## Calibración crítica

- **Visión disponible** (verificado 2026-09-11; modelo DeepSeek V4.1 Flash): puedo leer imágenes.
  Aun así el usuario **no ve adjuntos del chat** → los PNG se guardan en archivo y él los abre desde
  su filesystem. Usar la visión con criterio (cada imagen consume contexto); para análisis masivo de
  frames preferir representaciones baratas (ASCII/estadísticas). Si cambia el modelo, re-verificar.
- **Imágenes por lotes**: triaje con `tools/analysis/triage_screenshots.py` y lectura en lotes de
  2-3 volcando cada imagen a texto. Ver `docs/workflows.md` §3.
- Dumps RDRAM del harness Linux vienen **word-swapped** → bswap32. En BizHawk leer CPU BE.
- Regla de oro: **nunca editar a mano el C generado** (`RecompiledFuncs/`). Todo fix va a
  `config/*.syms.toml`, a la lista de reimplementadas del toolchain (ver ADR 0002) o al runtime.
- Tras regenerar: `python3 tools/analysis/fix_fallthroughs.py` y añadir `osYieldThread_recomp` a `funcs.h` si falta.
- No commitear sin pedirlo. No tocar ROMs ni `work/*.so` sin pedirlo.

## Referencia de comportamiento (emulador que progresa)

- **`tools/analysis/emu_ref.sh <prefix> <secs> [dumps]`**: ejecuta `r64dump` con 4 MB + input +
  RSP-HLE + **vídeo real rice/GLX** (Xvfb :99 con GLX). Es la única configuración que progresa como
  BizHawk. Requiere `apk add mesa-dri-gallium libsamplerate` y `r64dump` recompilado con rutas del
  proyecto (`MU64_CFGDIR`/`MU64_DATADIR` → `work/debug/mupen*`; config `DisableExtraMem=1`).
- **Escritores en el emulador**: `work/libmupen64plus-wplog.so` + `HH_WPLOG=1 HH_WPLO=<hex>
  HH_WPHI=<hex>` loguea escrituras (con PC) en ese rango físico. Fuente: `work/mupen-src` (rebuild:
  `make -C projects/unix all OSD=0 VULKAN=0 DEBUGGER=1`; requiere `binutils-dev`).
- **Trazas**: `HH_CALLTRACE` (port, solo indirectas) y `HH_JALTRACE` (emu, todos los saltos, incluye
  IPL3; **no** dispatches de hilo). **No alinear por posición**: comparar ventanas o por subsecuencia.
- **Diff de RDRAM**: `tools/analysis/diff_rdram.py <port> <emu> [base size]` (resumen por bloques).
- **Recompilador**: el ejecutable es `toolchain/src/N64Recomp/build_recomp/N64Recomp` (OUTPUT_NAME de
  `N64RecompCLI`). Rebuild con **`--target N64RecompCLI`**; `--target N64Recomp` **no** relinkea
  (causa de “el cambio no se aplica”). Tras tocar `symbol_lists.cpp`: rebuild del tool →
  `python3 tools/recomp.py --config config/game_combined.toml --build`.

## Comandos y workflows

Ver **`docs/workflows.md`** (recompilar, build, run headless, protocolo de imágenes).

## Inventario

- `PROYECTO.md`, `TODO.md`, `AGENTS.md` — docs vivos. · `docs/` (architecture, workflows,
  documentation) y `docs/adr/` — técnico/decisiones.
- `config/` — `game_combined.toml` (activa, multi-módulo), `us_combined.syms.toml`, `us_ghidra.syms.toml`, `RecompiledFuncs_combined/`.
- `port/HybridHeavenRecomp/` — port (CMake, `RecompiledFuncs/`, `src/`, `lib/`, builds).
- `tools/` — scripts propios. · `notes/` — histórico (no editar). · `work/`, `toolchain/` — gitignored.
