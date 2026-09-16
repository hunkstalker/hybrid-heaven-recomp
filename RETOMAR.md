# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`.
> Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 3 líneas

- Se **juega** en Windows: menús → GAME START → escenas 3D y combate, con mando Xbox (`config.ini`),
  audio a 43200 Hz y Controller Pak emulado.
- **Foco abierto**: entrega del objeto del **NPC**. Dos causas raíz corregidas hoy:
  1. **Fallthrough sin encadenar** en módulo 55 (`M55_FUN_80379690` → `0x803796E4`): fugaba `0x48`
     de pila por frame y saltaba la animación del objeto. Fix en
     `tools/analysis/fix_fallthroughs.py` (decide por la **última** sentencia, exige
     `cont == última_instr + 4`; 1921 cadenas nuevas).
  2. **Mid-entry `0x80379954`** (y `0x80379798`/`0x803798D8`) sin registrar: el juego ya ejecuta la
     animación y pedía ese símbolo. Añadidos a `config/module_extras.json` (módulo 55) junto con
     `0x80380010`/`0x803800A0` (que se habían perdido al regenerar).
  Syms reconstruidos desde los `.obj` de la build previa del usuario (ver nota) para evitar un
  cascado de `auto_mid` que metía **datos** como funciones (`0 = cop0_register_read`). **Módulo 55 =
  overlay de la secuencia de objeto del NPC** (carga bajo demanda a t≈13 s; documentado en
  `docs/architecture.md` §2.2). Build Linux + smoke OK (`sp` constante en `hh_cmds.log`).
  **Importante**: si hay que recompilar, `tools/recomp.py ... --force` (el validador fusiona 2
  splits legítimos de epílogos compartidos). Detalle:
  `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`.
- Quedan **huecos conocidos** de `LOOKUP` sin registrar (5 delay slots en el módulo 55 + otros
  módulos y plana; lista en la nota). Si crashea con `Failed to find function at 0x...`, la vía
  rápida es `python3 tools/analysis/add_mid_entry.py 0xADDR` seguido de
  `tools/recomp.py --config config/game_combined.toml --force`. La herramienta **rechaza** delay
  slots y direcciones dentro de switches fusionados (romperlos causa regresiones como el crash de
  las escaleras del 2026-09-15: ver nota, "Ronda 10").
- **Teardown**: el cierre ordenado no se reproduce en Linux (rc=0) con el camino actual; hay hook de
  prueba `HH_AUTOQUIT=<segundos>` (solo si se define el env).

## TU TAREA AHORA (pasos exactos)

1. Recompilar: `port\build_windows.bat` (Release) — **sin** `--force-libs`.
   **Necesario ahora**: el exe actual tiene la regresión de las escaleras (ronda 10, ya corregida en
   el árbol).
2. Ejecutar `port\run_windows.bat` y comprobar: **bajar las escaleras** (antes crasheaba) y la
   **entrega del objeto del NPC** (debe seguir bien: escala, gira, el texto avanza).
3. Si crashea con `Failed to find function at 0x...`: pasarme la dirección; la registro con
   `tools/analysis/add_mid_entry.py` (rechaza delay slots y switches fusionados).
4. Siguiente hito: **abrir cajas de ítem** y seguir la partida.


## Cómo leer los logs

- `hh_sched.log`: `queue`/`next`/`signal`/`park`/`wake`/`rntw`/`swap` de cada hilo. Un `park tid=N`
  sin `next/wake tid=N` posterior = hilo encolado que nunca corre.
- `hh_mq.log`: eventos de la cola del loader (`0x8005C268`): `send-in`, `send-wake`, `recv-in`,
  `recv-block`, `recv-ok` con `tid`, `sender`, `valid` y `blockedHead`.
- `hh_state.log`: si `polls` se congela con `audio` subiendo, hay hilo(s) de juego aparcados.
- `hh_pi.log`: `tid=` por DMA; `mq=8005C268` es la cola del helper síncrono del loader.
- `hh_stub.log`: si aparece un `vram`, un símbolo mal acotado quedó en stub (vacío desde el fix M9).
- `hh_ovl.log`: qué overlay/módulo se carga y cuándo.
- `hh_crash.log`: crash con registros host/guest y **backtrace host** (`bt[i] exe+0x...`); mapear con
  `build_win/HybridHeavenRecomp-Release.map`.

## Entorno / git

- **Commits de la sesión (2026-09-15)**:
  - main repo: `1e97890` — *fix(mod55): encadenar fallthroughs y registrar mid-entries del objeto
    del NPC* (incluye `RecompiledFuncs/` regenerado, syms, docs y `tools/analysis/add_mid_entry.py`).
  - N64ModernRuntime (repo anidado, **detached HEAD** como venía siéndolo): `87acdbb` —
    *diag(runtime): instrumentacion del cuelgue del NPC y sombra host de scheduling*.
- **`port/windows_runtime_changes.patch` debe generarse SIEMPRE como diff desde la BASE**
  (`git -C <NMR> diff fd6b0d0 --ignore-submodules=all > port/windows_runtime_changes.patch`): el
  `build_windows.bat` hace `checkout fd6b0d0` + patch, así que un patch como "delta desde HEAD"
  deja el build con el runtime de base (le pasó al usuario tras commits locales del runtime).
  Verificar aplicándolo en un worktree limpio de `fd6b0d0`.
- Bats de apoyo: `run_windows.bat`, `run_noaudio.bat`, `run_audlog.bat`, `run_test_*` (regresión),
  `bisect_build.bat` (build de bisect), `run_watch.bat` (watchpoint + grabación de replay).
- Docs vivos: `AGENTS.md` (arranque) · `TODO.md` · `PROYECTO.md` · `notes/` (evidencia por ronda).
