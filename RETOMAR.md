# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`.
> Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 4 líneas

- Se **juega** en Windows (menús → GAME START → escenas 3D y combate, mando Xbox, audio 43200 Hz,
  Controller Pak emulado). Fixes previos validados: **guardado en cápsula**, cuelgue por daño del
  robot, objeto del NPC y regresión de las escaleras (ver `TODO.md` → "Hecho" y `notes/`).
- **Sesión actual**: **B físico = atrás en menús** (VALIDADO por el usuario) y **mid-entry
  `M55_FUN_8037948C`** (crash al iniciar CaC). Detalle:
  `notes/2026-09-16-sesion-b-menus-combate-corrupcion.md`.
- **BLOQUEANTE**: al entrar en **combate cuerpo a cuerpo** el juego **corrompe estructuras**
  (objeto `0x8024A990` con callback basura `0xFFFF84CD`→bit23 perdido; lista de broadcast
  `[struct+0x888]` recorrida fuera de rango). No es un símbolo ausente. El runtime tiene
  mitigaciones **locales** (no publicadas) que evitan el crash pero el combate se atasca.
- **Runtime (fork) con cambios LOCALES sin push** (`e9a178f`, `efc5f17`, `0806e19`), por encima del
  pin publicado `feae2d5`. En Windows usar **`port\build_windows.local.bat`** (no `--force-libs`,
  que resetea `lib\` al pin y perdería las mitigaciones).

## TU TAREA AHORA (pasos exactos)

> Contexto completo de esta sesión: `notes/2026-09-16-sesion-b-menus-combate-corrupcion.md`.
> Notas del bloqueo: `notes/2026-09-16-crash-combate-centinela-ff7f84cd.md` y
> `notes/2026-09-16-combate-corrupcion-estado-8024a990.md`.

1. **[usuario] Validar en Windows** con `port\build_windows.local.bat` + `port\run_windows.bat`:
   - **B en menús**: en el menú principal el B físico debe ir atrás (en juego sigue = agacharse).
   - **`0x8037948C`**: iniciar combate y aguantar sin el `Failed to find function`.
2. **[BLOQUEANTE] Corrupción al entrar en CaC**. Ya acotada pero sin causa raíz:
   - El objeto `0x8024A990` acaba con `+0x1C=0xFFFF84CD` (bit23 perdido → `0xFF7F84CD`) y el
     dispatcher `FUN_80005270` intenta llamarlo. El **emulador** tiene `+0x1C=0x80135320` válido.
   - La escritura que corrompe **no pasa por `MEM_*`**: `do_send` escribe el mensaje directo en
     RDRAM. La "lista de colas" de `FUN_80000774`→`FUN_80000a0c` (`[struct+0x888]`) se recorre fuera
     de rango (nodos con floats → terminador pisado).
   - Vías: (a) **comparar con el emulador en el mismo frame** (alinear por VI y diff de RDRAM);
     (b) cazar el **wild write** con watchpoints sobre la estructura (el `struct` es dinámico).
3. **Decidir publicación del runtime**: las mitigaciones son locales; publicarlas requiere push al
   fork (orden N64Recomp → NMR → main) + subir el pin de `port/runtime.lock`.
4. **Pendientes varios**: teardown SEGV al cerrar, limpieza de instrumentación y botón **X** de los
   menús de combate (`TODO.md`).
5. Si crashea con `Failed to find function at 0x...` (dirección **válida**): `python3
   tools/analysis/add_mid_entry.py 0xADDR` + `tools/recomp.py --config config/game_combined.toml
   --force` (el guardián `check_syms_overrides.py` aborta si se pierde un override; la herramienta
   rechaza delay slots y switches fusionados).

## Cómo leer los logs

- `hh_sched.log`: `queue`/`next`/`signal`/`park`/`wake`/`rntw`/`swap` de cada hilo. Un `park tid=N`
  sin `next/wake tid=N` posterior = hilo encolado que nunca corre.
- `hh_mq.log`: eventos de la cola del loader (`0x8005C268`): `send-in`, `send-wake`, `recv-in`,
  `recv-block`, `recv-ok` con `tid`, `sender`, `valid` y `blockedHead`.
- `hh_state.log`: si `polls` se congela con `audio` subiendo, hay hilo(s) de juego aparcados.
- `hh_pi.log`: `tid=` por DMA; `mq=8005C268` es la cola del helper síncrono del loader.
- `hh_ovl.log`: qué overlay/módulo se carga y cuándo.
- `hh_crash.log`: crash con registros host/guest y **backtrace host** (`bt[i] exe+0x...`); mapear con
  `build_win/HybridHeavenRecomp-Release.map`.
- `hh_badlookup.log` (nuevo): al fallar un lookup, volcado del objeto del llamante (`s0`) y dónde
  aparece el valor malo.
- `hh_watch.log` (watchpoint, `run_watch.bat`): accesos a un rango; ahora incluye `val=` y admite
  `HH_WATCH_SIZE`. **Ojo**: no ve las escrituras directas del runtime (p. ej. `do_send`).

## Entorno / git

- **Repo principal**: `git push origin main` es fast-forward (publica el fix del B y el mid-entry).
  No he hecho push.
- **Fork del runtime** (rama `hybrid-heaven`, con `main` = upstream): commits locales de esta sesión
  `e9a178f`, `efc5f17`, `0806e19` **sin push**. `port/runtime.lock` sigue en `feae2d5`.
  Flujo: editar `lib/N64ModernRuntime` → commit → push al fork → actualizar el SHA del lock.
  `N64Recomp` es submódulo (fork propio) del runtime.
- Bats: `build_windows.bat` (clona/actualiza por lock), **`build_windows.local.bat`** (compila `lib\`
  tal cual, sin git; no versionado), `run_windows.bat` (admite `noaudio`/`audlog`), `run_mqlog.bat`
  (traza + s0fix) y `run_watch.bat` (watchpoint; ahora en `0x8024A9A8` tamaño `0x80`).
- Docs vivos: `AGENTS.md` (arranque) · `TODO.md` · `PROYECTO.md` · `notes/` (evidencia por ronda).
