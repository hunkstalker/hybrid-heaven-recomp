# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`.
> Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 3 líneas

- Se **juega** en Windows: menús → GAME START → escenas 3D y combate, con mando Xbox (`config.ini`),
  audio a 43200 Hz y Controller Pak emulado.
- **Cuelgue por daño del robot: ARREGLADO y validado (2026-09-16)**, en dos capas:
  1. `s0` (r16) machacado por la cadena del frame → el dispatch frame/no-op del bucle principal se
     rompía: fix runtime `HH_S0FIX` (incondicional; repara en la entrada del work, log en
     `hh_s0fix.log`). Validado con auto-test (`HH_TEST_S0BUG`) y por el usuario.
  2. Ya caído, el personaje **no se levantaba** (y la pila fugaba `0x38`/frame): **fallthrough
     ausente al final de `M55_FUN_8037a6f4`** — la `beq` final (0x8037A880) cae a `0x8037A884`
     (delay slot) y a la continuación `0x8037A888`, que desemboca en el epílogo compartido
     `0x8037A94C`/`0x8037A950` (`sp += 0x38`). El port salía por `;}` (fuga + lógica de caída
     saltada). Corregido en `tools/analysis/fix_fallthroughs.py` (nueva regla: rama condicional
     como última instrucción ⇒ encadenar a la contigua si `cont == last_addr+4`). Detalle:
     `notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md`.
- También arreglados y validados antes: **objeto del NPC** (fallthrough M55 `M55_FUN_80379690` →
  `0x803796E4` + mid-entries; syms reconstruidos a mano) y **regresión de las escaleras** (partir un
  switch fusionado; revertida). **Módulo 55 = overlay de la secuencia de objeto del NPC**
  (`docs/architecture.md` §2.2). Si hay que recompilar: `tools/recomp.py ... --force`.
  Detalle: `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`.
- Quedan **huecos conocidos** de `LOOKUP` sin registrar (5 delay slots en el módulo 55 + otros
  módulos y plana; lista en la nota). Si crashea con `Failed to find function at 0x...`, la vía
  rápida es `python3 tools/analysis/add_mid_entry.py 0xADDR` seguido de
  `tools/recomp.py --config config/game_combined.toml --force`. La herramienta **rechaza** delay
  slots y direcciones dentro de switches fusionados (romperlos causa regresiones como el crash de
  las escaleras del 2026-09-15: ver nota, "Ronda 10").
- **Teardown**: el cierre ordenado no se reproduce en Linux (rc=0) con el camino actual; hay hook de
  prueba `HH_AUTOQUIT=<segundos>` (solo si se define el env).

## TU TAREA AHORA (pasos exactos)

1. Recompilar (si no lo has hecho ya con la ronda 15): `port\build_windows.bat` (Release) — **sin**
   `--force-libs`. El árbol ya trae: objeto del NPC, láser y caída arreglados.
2. Ejecutar `port\run_windows.bat` y probar el siguiente hito: **abrir cajas de ítem** y seguir la
   partida (y, de paso, re-verificar el ciclo del robot: daño → caída → levantarse).
3. Si crashea con `Failed to find function at 0x...`: pasarme la dirección; la registro con
   `tools/analysis/add_mid_entry.py` (rechaza delay slots y switches fusionados).
4. Después: teardown SEGV al cerrar, limpieza de instrumentación y mando de menús de combate
   (ver `TODO.md`).


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
- **Commits de la ronda 15 (2026-09-16)** (main repo): *fix(recomp): encadenar fallthrough
  M55_FUN_8037a6f4->8037a884 (fuga 0x38/frame en la caida)* y
  *docs: ronda 15 (fix de la caida validado; heuristica de ramas condicionales)*.
- **`port/windows_runtime_changes.patch` debe generarse SIEMPRE como diff desde la BASE**
  (`git -C <NMR> diff fd6b0d0 --ignore-submodules=all > port/windows_runtime_changes.patch`): el
  `build_windows.bat` hace `checkout fd6b0d0` + patch, así que un patch como "delta desde HEAD"
  deja el build con el runtime de base (le pasó al usuario tras commits locales del runtime).
  Verificar aplicándolo en un worktree limpio de `fd6b0d0`.
- Bats de apoyo: `run_windows.bat`, `run_noaudio.bat`, `run_audlog.bat`, `run_test_*` (regresión),
  `bisect_build.bat` (build de bisect), `run_watch.bat` (watchpoint + grabación de replay).
- Docs vivos: `AGENTS.md` (arranque) · `TODO.md` · `PROYECTO.md` · `notes/` (evidencia por ronda).
