# AGENTS.md — arranque de sesión

Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + Steam Deck.
Fase actual: **gameplay** (menús → GAME START → escenas 3D y combate) con mando Xbox, audio a 43200 Hz y Controller Pak emulado. **Guardado en cápsula: VALIDADO en Windows (2026-09-16)**. **Foco actual (2026-09-18): SUAVIZADO** ("una N64 que nunca se ahoga"): live limpio a **30 ticks/s** (`d2=29 d3=1`) y replay fiel con **`HH_REPLAY_MODE=vi`**; corregidos el **AI** (FIFO fiel, `HH_AI_FIFO`) y el **pipeline de audio** (cola acotada) — sin retraso creciente ni el grueso del petardeo; `do_rom_read` en bloque. Instrumentación de tirones siempre activa (`hh_tick.log`, `hh_slow.log` con `guest_busy`). **Plan aprobado**: pasada de perfilado del mantenedor (`run_cac_profile.bat`, incluir la 1ª puerta) y **cache de assets** (reimplementar el loader LZKN64 + cache; la ROM solo la 1ª vez; ADR 0007). El **CaC/veneno queda en espera** (mecanismo documentado: `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`, `bizhawk-replay-freeze-con-rafaga.md`); con replay fiel y cadencia fina se reevalúa. **El test de juego del port nativo lo hace el mantenedor (usuario)**; dev solo pasadas headless. El runtime tiene cambios **locales** sin push (usar `port\build_windows.local.bat`). Detalle y siguiente paso exacto: `RETOMAR.md`, `TODO.md` y `notes/2026-09-18-suavizado-fase1-y-cache-loader.md`.

Hitos previos (detalle en `notes/`): arranque completo (4 MB RDRAM, des-stubbing libultra ADR 0002, VI del ROM ADR 0003); transición/burst (strict aliasing + registro dinámico de módulos); menús, Controller Pak y geometría/píxeles; audio `aspMain` del ROM recompilado; perfiles de mando por contexto (`config.ini`, flag de UI `0x802690D0`); diagnóstico automático de crashes y cuelgues.

## Retomada rápida

`RETOMAR.md` (raíz): estado sintetizado, **tarea actual y pasos exactos**, instrumentación de
diagnóstico y bats. Empezar por ahí; detalle en `TODO.md`, `PROYECTO.md` y la nota de handoff.

## Persistencia y entorno (CRÍTICO)

- **Lo importante vive dentro del repo, bien clasificado**: código, herramientas (`tools/`), documentación
  (`docs/`, `notes/`) y artefactos de desarrollo en sus carpetas. Lo temporal puede quedar fuera, pero
  **lo que deba conservarse se guarda en el repo**; no dejar logs, trazas, dumps ni scripts en carpetas
  temporales del sistema (se pierden entre sesiones). Si una herramienta externa escribe fuera del repo,
  copiar el resultado al proyecto al terminar.
- Las dependencias de desarrollo son **reinstalables** con el gestor de paquetes de la distribución
  (build, runtime del port y librerías de desarrollo). Si el entorno se recrea, reinstalar lo que falte
  y reconfigurar CMake en el build dir por si cambian rutas.
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

Si el remoto rechaza por historial reescrito: `--force-with-lease`. El pin de `port/runtime.lock` solo
es válido **después** de pushear los forks.

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
  `python3 tools/recomp.py --config config/game_combined.toml --build`.

## Comandos y workflows

Ver **`docs/workflows.md`** (recompilar, build, run headless, protocolo de imágenes).

## Inventario

- `PROYECTO.md`, `TODO.md`, `AGENTS.md` — docs vivos. · `docs/` (architecture, workflows,
  documentation) y `docs/adr/` — técnico/decisiones.
- `config/` — `game_combined.toml` (activa, multi-módulo), `us_combined.syms.toml`, `us_ghidra.syms.toml`, `RecompiledFuncs_combined/`.
- `port/HybridHeavenRecomp/` — port (CMake, `RecompiledFuncs/`, `src/`, `lib/`, builds).
- `tools/` — scripts propios. · `notes/` — histórico (no editar). · `work/`, `toolchain/` — gitignored.
