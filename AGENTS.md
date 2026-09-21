# AGENTS.md — arranque de sesión

Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux +
Steam Deck. Fase actual (**2026-09-21**): **recompilación por ELF/splat** (ADR 0011;
`tools/regenerate.py`); el C recompilado **no se versiona** (obra derivada; ADR 0009) → `build/recomp/`.
Hitos previos (detalle en `notes/`): arranque completo (4 MB RDRAM, ADR 0002/0003); menús, Controller
Pak y audio `aspMain`; perfiles de mando (`config.ini`). Retomada: **`RETOMAR.md`** (estado, tarea
actual, pasos exactos, instrumentación y bats).

**Validado en Windows**: START → menú → GAME START → gameplay, primer NPC, **primer CaC**, ~30 min
hasta el 6º combate sin cuelgues; mando y guardado OK (bloqueante del CaC resuelto). Pendiente: **M5**
(saneamiento: `recomp/tools`, docs, purga `HH_*`) y **M4c** (SEGV al salir). Ver `TODO.md` y
`notes/2026-09-21-migracion-via-referencia-elf.md`.

Estructura: port en la raíz (`CMakeLists.txt`, `src/{platform,hooks,subsystems}`, `include/`, `assets/`,
`rsp/`, `lib/`), pipeline en `recomp/`, tooling en `tools/`, builds (gitignored) en `build/`.

## Forma de trabajo (por defecto)

- **Recomendar, no preguntar**: primero una **recomendación única** (el siguiente paso), luego
  alternativas opcionales `a)`, `b)`…, explicando por qué. Sé conciso.
- Ejecuta la recomendación sin esperar confirmación salvo que sea destructiva, irreversible o toque
  ROMs/forks/push. El **plan establecido** (`RETOMAR.md`/`TODO.md`/Fases) es la opción por defecto;
  apartarse requiere avisarlo explícitamente.

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

**Push** (orden: los forks primero, porque `runtime.lock` los pinea):

1. **N64Recomp** (fork) — `git -C lib/N64ModernRuntime/N64Recomp push origin hybrid-heaven`
2. **N64ModernRuntime** (fork) — `git -C lib/N64ModernRuntime push fork hybrid-heaven`
3. **Main repo** — **requiere `--force`** (el remoto conserva la historia per-file pre-reescritura y
   diverge de la local): `git fetch origin && git tag backup-per-file origin/main &&
   git push --force-with-lease origin main` (tag de seguridad opcional: `git push origin backup-per-file`).

Los gitlinks de `lib/` (y el pin `runtime.lock`) solo valen **tras** pushear los forks (si no, un clon
nuevo no inicializa el submódulo; usa `build_windows.local.bat`).

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
  recurrente van en `tools/` (o la raíz para build/run) y se documentan. Borrar builds locales que no se usen (`.vs`, builds
  obsoletos) antes de dar por cerrada una tanda.

## Comandos, workflows y oráculo

Ver **`docs/workflows.md`** (recompilar, build, run headless, protocolo de imágenes) y su **§6**
(oráculo con emulador: `emu_ref.sh`, trazas `HH_CALLTRACE`/`HH_JALTRACE`, `diff_rdram.py`, rebuild de
`N64Recomp` con `--target N64RecompCLI`).

## Inventario

- `PROYECTO.md`, `TODO.md`, `AGENTS.md` — docs vivos. · `docs/` (architecture, workflows,
  documentation) y `docs/adr/` — técnico/decisiones.
- `recomp/` — config del pipeline (versionada): `hybrid-heaven.us.{yaml,toml}`, `overlays.txt`,
  `macro.inc`, `symbol_addrs.txt`, `auto_funcs.txt`, `code_files.json`+`code_files.overlays.txt`
  (manifiesto/orden de secciones), `n64recomp_changes/`, `rsp_hh_aspMain.toml` y `recomp/tools/`
  (pipeline: splat/ELF/N64Recomp).
- `./` — port (CMake, `src/{platform,hooks,subsystems}`, `include/`, `assets/`, `rsp/`, builds).
  `lib/rt64` y `lib/N64ModernRuntime` son **submódulos git** (fork propio; `.gitmodules`, ADR 0010).
- `build/` — intermedios y salidas (gitignored): `build/recomp/{asm,build-elf,elf,RecompiledFuncs}`
  (el C recompilado: **directorio real**, no symlink —Windows no los resuelve—; `regenerate.py` lo
  materializa desde `work/recomp_elf/`) y `build/{linux,windows}` (el port).
- `tools/` — scripts propios (`regenerate.py`, `build_linux.sh`, `analysis/`, `diag/`, `lzkn64/`,
  `rommy.py`) · `notes/` — histórico (no editar). · `work/`, `toolchain/` — gitignored.
