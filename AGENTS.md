# AGENTS.md — arranque de sesión

Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + Steam Deck.
Fase actual (**2026-09-20**): **reset de la recompilación a per-file** (causa raíz del freeze CaC: extracción
incompleta; `notes/2026-09-20-lecciones-recompilacion-per-file.md`). Pipeline **hecho** (91 code files, Ghidra por
fichero, N64Recomp rc=0) y **el C deja de versionarse** (obra derivada; ADR 0009) → `python3 tools/regenerate.py`.
**Bloqueante**: el build per-file no pasa de la fase temprana (solo carga `file_008`; el viejo `file_055` en
`vi≈77`); el código es idéntico, diverge el registro/estado de secciones. Detalle/siguiente paso: `RETOMAR.md`,
`TODO.md`, nota `2026-09-20-pipeline-per-file-estado.md`.

Hitos previos (detalle en `notes/`): arranque completo (4 MB RDRAM, ADR 0002/0003); menús, Controller Pak y audio `aspMain`; perfiles de mando (`config.ini`).

## Retomada rápida

`RETOMAR.md` (raíz): estado sintetizado, **tarea actual y pasos exactos**, instrumentación de
diagnóstico y bats. Empezar por ahí; detalle en `TODO.md`, `PROYECTO.md` y la nota de handoff.

## Forma de trabajo (por defecto)

- **Recomendar, no preguntar.** Al cerrar un análisis o antes de una decisión, **no** dejes al
  mantenedor eligiendo entre opciones. Da **primero una recomendación única y clara** (el siguiente
  paso que ejecutarás), **luego alternativas opcionales etiquetadas `a)`, `b)`, `c)`…**, y explica
  **por qué recomiendas esa** y **por qué cada alternativa es opcional**.
- Ejecuta la recomendación sin esperar confirmación salvo que sea destructiva, irreversible o toque
  ROMs/forks/push. Si el mantenedor quiere desviarse, lo dirá.
- **El plan establecido es la opción recomendada por defecto** (`RETOMAR.md`/`TODO.md`/Fases). Solo
  se recomienda otra vía si el contexto o el conocimiento de la sesión demuestran que es mejor; en
  ese caso, **avísalo explícitamente** (qué parte del plan se aparta y por qué).
- Sé conciso: recomendación → motivo → alternativas. Nada de menús de opciones equivalentes.

## Persistencia y entorno (CRÍTICO)

- **Lo importante vive dentro del repo, bien clasificado**: código, herramientas (`tools/`), documentación
  (`docs/`, `notes/`) y artefactos de desarrollo en sus carpetas. Lo temporal puede quedar fuera, pero
  **lo que deba conservarse se guarda en el repo**; no dejar logs, trazas, dumps ni scripts en carpetas
  temporales del sistema (se pierden entre sesiones). Si una herramienta externa escribe fuera del repo,
  copiar el resultado al proyecto al terminar.
- Las dependencias de desarrollo son **reinstalables** con el gestor de paquetes; si se recrea el entorno, reinstalar y reconfigurar CMake.
- Los artefactos ya construidos (`work/`, `toolchain/`, el binario del port) no se versionan y no hace
  falta regenerarlos salvo cambio.

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
nota fechada en `notes/`, y crear un ADR si hubo decisión estructural.

**Cuándo commitear** (indicación del mantenedor): **solo** cuando (a) el mantenedor pida **documentar**,
o (b) una tarea salga **exitosa/validada**. **No** commitear por cada nota ni por actualizaciones de
documentación rutinarias. Cuando se commitee una tarea validada, dejar el árbol limpio y listo para
push.

**Repos a pushear y orden** (los forks primero, porque `port/runtime.lock` los pinea; ver su
comentario). Orden obligatorio:

1. **N64Recomp** (fork) — `port/HybridHeavenRecomp/lib/N64ModernRuntime/N64Recomp`:
   `git push origin hybrid-heaven` → `https://github.com/hunkstalker/N64Recomp.git`
2. **N64ModernRuntime** (fork) — `port/HybridHeavenRecomp/lib/N64ModernRuntime`:
   `git push fork hybrid-heaven` → `https://github.com/hunkstalker/N64ModernRuntime.git`
3. **Main repo** — raíz del repo: `git push origin main` → `https://github.com/hunkstalker/hybrid-heaven-recomp.git`

Si el remoto rechaza por historial reescrito: `--force-with-lease`. Los submódulos de `lib/` (y el
pin de `port/runtime.lock`) solo son válidos **después** de pushear los forks: hasta entonces un clon
nuevo no podrá inicializar el submódulo (usa `build_windows.local.bat` para el árbol local).

## Calibración crítica

- **No concluir el estado de ejecución (freeze/cuelgue, qué se ve, dónde está el juego) solo desde
  logs headless.** Antes de afirmar "el juego se congela", ofrece al mantenedor que lo **valide
  visualmente** (build Windows/port) y espera su confirmación; el harness sin ventana puede engañar.
- **Visión disponible** (verificado 2026-09-11; modelo DeepSeek V4.1 Flash): puedo leer imágenes.
  Aun así el usuario **no ve adjuntos del chat** → los PNG se guardan en archivo y él los abre desde
  su filesystem. Usar la visión con criterio (cada imagen consume contexto); para análisis masivo de
  frames preferir representaciones baratas (ASCII/estadísticas). Si cambia el modelo, re-verificar.
- **Imágenes por lotes**: triaje con `tools/analysis/triage_screenshots.py` y lectura en lotes de
  2-3 volcando cada imagen a texto. Ver `docs/workflows.md` §3.
- Dumps RDRAM del harness Linux vienen **word-swapped** → bswap32. En BizHawk leer CPU BE.
- Regla de oro: **nunca editar a mano el C generado**. Se regenera con `tools/regenerate.py` desde la
  ROM (no se versiona; ADR 0009). Todo fix va a la config/syms, a la lista de reimplementadas del
  toolchain (ver ADR 0002) o al runtime.
- Tras regenerar: `python3 tools/analysis/fix_fallthroughs.py` y añadir `osYieldThread_recomp` a `funcs.h` si falta.
- Commitear cuando se valide una tarea o cuando haya que commitear documentación. No tocar ROMs ni
  `work/*.so` sin pedirlo.
- **Higiene**: scripts/bats **puntuales** se eliminan tras usarse (no dejar residuos); los de uso
  recurrente van en `port/` y se documentan. Borrar builds locales que no se usen (`.vs`, builds
  obsoletos) antes de dar por cerrada una tanda.

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
  `python3 tools/regenerate.py` (recompila el C per-file).

## Comandos y workflows

Ver **`docs/workflows.md`** (recompilar, build, run headless, protocolo de imágenes).

## Inventario

- `PROYECTO.md`, `TODO.md`, `AGENTS.md` — docs vivos. · `docs/` (architecture, workflows,
  documentation) y `docs/adr/` — técnico/decisiones.
- `config/` — `game_code_files.toml` (config per-file activa), `code_files.json` +
  `code_files.overlays.txt` (manifiesto/orden de secciones), `n64recomp_changes/`, `rsp_hh_aspMain.toml`.
- `port/HybridHeavenRecomp/` — port (CMake, `src/`, builds). `lib/rt64` y `lib/N64ModernRuntime`
  son **submódulos git** (fork propio; `.gitmodules`, ADR 0010); `RecompiledFuncs/` es un
  **directorio real** gitignored (generado; `regenerate.py` lo materializa desde `work/recomp/`; no
  symlink, Windows no los resuelve).
- `tools/` — scripts propios (`regenerate.py`, `analyze_code_files.py`, `ghidra_sections.py`…) ·
  `notes/` — histórico (no editar). · `work/`, `toolchain/` — gitignored.
