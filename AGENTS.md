# AGENTS.md — arranque de sesión

Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux +
Steam Deck. Fase actual (**2026-09-21**): **recompilación por ELF/splat** (ADR 0011;
`tools/regenerate.py`); el C recompilado **no se versiona** (obra derivada; ADR 0009) → `build/recomp/`.
Hitos previos (detalle en `notes/`): arranque completo (4 MB RDRAM, ADR 0002/0003); menús, Controller
Pak y audio `aspMain`; perfiles de mando (`config.ini`). Retomada: **`RETOMAR.md`** (estado, tarea
actual, pasos exactos, instrumentación y bats).

**Validado en Windows**: primer nivel completo — START → menú → GAME START → gameplay, primer NPC,
CaC, combates, mando y guardado OK; sin bloqueantes conocidos (M5 y M4c hechos). Lo abierto son
artefactos visuales por la **interpolación de frames** (p. ej. una puerta que parpadea; ver
`RETOMAR.md` §Bugs abiertos). Ver `TODO.md` y `notes/2026-09-21-migracion-via-referencia-elf.md`.

Estructura: port en la raíz (`CMakeLists.txt`, `src/{platform,hooks,subsystems}`, `include/`, `assets/`,
`lib/`), pipeline en `recomp/`, tooling en `tools/`, builds (gitignored) en `build/`.

## Forma de trabajo (por defecto)

- **Recomendar, no preguntar**: primero una **recomendación única** (el siguiente paso), luego
  alternativas opcionales `a)`, `b)`…, explicando por qué. Sé conciso.
- Ejecuta la recomendación sin esperar confirmación salvo que sea destructiva, irreversible o toque
  ROMs/forks/push. El **plan establecido** (`RETOMAR.md`/`TODO.md`/Fases) es la opción por defecto;
  apartarse requiere avisarlo explícitamente.
- **No inventar UI**: el menú del overlay debe verse **como el nativo** (1:1, sin elementos extra). Si
  algo no está acordado, **confirmar antes de dibujar** (ver `docs/menu.md`).
- **Un tema = un commit.** No trocear una tarea en varios commits ni reescribir historia (`squash`)
  sin petición expresa.

## Persistencia y entorno (CRÍTICO)

- **Lo importante vive dentro del repo, bien clasificado** (código, `tools/`, `docs/`, `notes/`); lo
  temporal puede quedar fuera, pero **lo que deba conservarse se guarda en el repo** (nada de logs,
  dumps ni scripts en temporales del sistema). Si una herramienta externa escribe fuera, copiar el
  resultado al repo.
- Dependencias de desarrollo **reinstalables** con el gestor de paquetes; los artefactos ya construidos
  (`work/`, `toolchain/`, el binario) no se versionan ni hace falta regenerarlos salvo cambio.

## Lee esto (y solo esto) al empezar

1. **`docs/documentation.md`** — cómo documentar (normativo; leer cada sesión).
2. **`RETOMAR.md`** — handoff: estado y tarea de la sesión (handoff corto).
3. **`PROYECTO.md`** — contexto y estado (corto).
4. **`TODO.md`** — qué toca ahora.
5. **`docs/architecture.md`** — modelo técnico (memoria, `trans`, runtime).
6. Bajo demanda: `docs/workflows.md`, `docs/menu.md` (diseño del menú), `docs/adr/`, `notes/` (evidencia).
7. Índice completo de la documentación (generado): **`docs/INDEX.md`**. Regenerar/validar:
   `python3 tools/analysis/docs_index.py` (`--check` valida enlaces y el **presupuesto de arranque**).

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
3. **Main repo** — es **fast-forward** si `origin/main` es ancestro: `git fetch origin && git push origin main`
   (si divergiera: `git tag backup-per-file origin/main && git push --force-with-lease origin main`).

Los gitlinks de `lib/` (y `runtime.lock`) solo valen **tras** pushear los forks (usa `build_windows.local.bat`).

**Versionado / releases**: al subir versión (PATCH bugfix / MINOR feature; fuente única `include/hh.h`),
**propón título de release** (`vX.Y.Z - <área>: <qué>`) y crea `docs/releases/vX.Y.Z.md` con él en la
**primera línea** (`release.yml` lo usa). Propuesta: 1 recomendación + 2-3 alternativas, concisa.

## Calibración crítica

- **No concluir el estado de ejecución (freeze/cuelgue, qué se ve, dónde está el juego) solo desde
  logs headless.** Antes de afirmar "el juego se congela", ofrece al mantenedor que lo **valide
  visualmente** (build Windows/port) y espera su confirmación; el harness sin ventana puede engañar.
- **Distinguir SIEMPRE "medido" de "inferido"**: no afirmar timing ni comportamiento de ejecución sin
  evidencia; si es inferencia del código, decirlo. No mezclar cosas distintas (p. ej. componer texto
  ≠ cargar el módulo).
- **Visión disponible** (modelo DeepSeek V4.1 Flash): puedo leer imágenes, pero el usuario **no ve
  adjuntos del chat** → los PNG se guardan a archivo y él los abre. Usar con criterio (contexto);
  para análisis masivo, representaciones baratas (ASCII/estadísticas). Re-verificar si cambia el modelo.
- **Imágenes por lotes**: triaje con `tools/analysis/triage_screenshots.py` y lectura en lotes de
  2-3 volcando cada imagen a texto. Ver `docs/workflows.md` §3.
- Dumps RDRAM del harness Linux vienen **word-swapped** → bswap32. En BizHawk leer CPU BE.
- Regla de oro: **nunca editar a mano el C generado**; se regenera con `tools/regenerate.py` (no se
  versiona; ADR 0009). Todo fix va a config/syms, reimplementadas del toolchain (ADR 0002) o runtime.
- Tras regenerar: `python3 tools/analysis/fix_fallthroughs.py` y añadir `osYieldThread_recomp` a `funcs.h` si falta.
- Commitear cuando se valide una tarea o cuando haya que commitear documentación. No tocar ROMs ni
  `work/*.so` sin pedirlo.
- **Higiene**: scripts/bats puntuales se eliminan tras usarse; los recurrentes van a `tools/` (o la
  raíz para build/run) y se documentan. Borrar builds locales obsoletos al cerrar una tanda.

## Comandos, workflows y oráculo

Ver **`docs/workflows.md`** (recompilar, build, run headless, protocolo de imágenes) y su **§6**
(oráculo con emulador: `emu_ref.sh`, trazas `HH_CALLTRACE`/`HH_JALTRACE`, `diff_rdram.py`, rebuild de
`N64Recomp` con `--target N64RecompCLI`).

## Inventario

- `PROYECTO.md`, `TODO.md`, `AGENTS.md` — docs vivos. · `docs/` (architecture, workflows,
  documentation, menu) y `docs/adr/` — técnico/decisiones.
- `recomp/` — config del pipeline (versionada): `hybrid-heaven.us.{yaml,toml}`, `overlays.txt`,
  `symbol_addrs.txt`, `auto_funcs.txt`, `code_files.json`+`code_files.overlays.txt`, `n64recomp_changes/`,
  `rsp_hh_aspMain.toml` y `recomp/tools/` (pipeline splat/ELF/N64Recomp).
- `./` — port (CMake, `src/{platform,hooks,subsystems}`, `include/`, `assets/`, builds).
  `lib/rt64` y `lib/N64ModernRuntime` son **submódulos git** (fork propio; `.gitmodules`, ADR 0010).
- `build/` — intermedios y salidas (gitignored): `build/recomp/{asm,build-elf,elf,RecompiledFuncs}`
  (el C recompilado: **directorio real**, no symlink —Windows no los resuelve—; `regenerate.py` lo
  materializa desde `work/recomp_elf/`) y `build/{linux,windows}` (el port).
- `tools/` — scripts propios (`regenerate.py`, `build_linux.sh`, `analysis/`, `diag/`, `lzkn64/`,
  `rommy.py`) · `notes/` — histórico (no editar). · `work/`, `toolchain/` — gitignored.
