# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`.
> Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 4 líneas

- Se **juega** en Windows (menús → GAME START → escenas 3D y combate, mando Xbox, audio 43200 Hz,
  Controller Pak emulado). Fixes previos validados: **guardado en cápsula**, cuelgue por daño del
  robot, objeto del NPC y regresión de las escaleras (ver `TODO.md` → "Hecho" y `notes/`).
- **Sesión actual (2026-09-17) — nuevo foco: PACING/CADENCIA**. El port ejecuta la **lógica** de
  juego a ~16–28/s con VI/audio a 60/s; el original (emulador) a ~32–70/s (ambiguo: resolver).
  Pista documentada: el gate `[0x8005CD4C]` (si `>=2`, `FUN_80001454` se salta el dispatcher).
  Work order: **`notes/2026-09-17-workorder-pacing-cadencia.md`**.
- **BLOQUEANTE de fondo (CaC)**: al entrar en combate el juego corrompe estructuras (objeto
  `0x8024A990`; callback `0xFFFF84CD`→`0xFF7F84CD`; lista de broadcast fuera de rango). Hipótesis
  nueva: la **cadencia divergente** hace que los state machines por-frame/temporizador no lleguen al
  estado que arma el combate (`M23_FUN_801c1dc0`, `case 2`). Plan:
  `notes/2026-09-17-plan-revision-bloqueo-cac.md`.
- **Runtime (fork) con cambios LOCALES sin push** (`e9a178f`, `efc5f17`, `0806e19`), por encima del
  pin publicado `feae2d5`. En Windows usar **`port\build_windows.local.bat`** (no `--force-libs`,
  que resetea `lib\` al pin y perdería las mitigaciones).

## TU TAREA AHORA (pasos exactos)

> Work order completo y autocontenido (mecanismo del gate, instrumentación, comandos):
> **`notes/2026-09-17-workorder-pacing-cadencia.md`**. Objetivo: cadencia y **ratio eventos/VI**
> **1:1 con el original** (subir a 60+ solo después, si acaso). Evidencia previa:
> `notes/2026-09-17-plan-revision-bloqueo-cac.md` (Parte A) y
> `notes/2026-09-13-cadena-boot-y-progreso-fe00.md` §5.

1. **[Fase 0 — referencia del original]** medir con hits/VI (independiente del throttling):
   `HB_TRACE_EXEC=0x80001454,0x80005270,0x80000ed0 tools/analysis/emu_ref.sh work/debug/emu_rate2 60 60`
   → contar hits por dirección + `[dbg] vi_count`. Resolver si HH corre a **30 o 60 fps lógicos**.
2. **[Fase 1 — limitador del port]** con `HH_VERBOSE=1 HH_GATELOG=1 HH_TBLTRACE=1 HH_MQLOG_ALL=1`
   (`hh_mq_all.log`, `hh_sched.log`): ¿en qué espera se va el tiempo entre frames?, ¿quién deja
   `[0x8005CD4C]` en 1–2?
3. **[Fase 2 — fix]** uno por pasada: (a) gate `0x8005CD4C`/completaciones SP-DP, (b) scheduler/lock
   single-CPU, (c) handshake audio/SP (`HH_SP_SHARED`, `HH_AI_QUEUE_REPORT=full`). Si no mueve la
   métrica de Fase 1, revertir.
4. **[Fase 3 — validar]** 1:1 (hits/s o hits/VI) y **re-test del CaC**; si sigue atascado, volver a
   la Parte B de `notes/2026-09-17-plan-revision-bloqueo-cac.md` con la cadencia ya correcta.
5. Si crashea con `Failed to find function at 0x...` (dirección **válida**): `python3
   tools/analysis/add_mid_entry.py 0xADDR` + `tools/recomp.py --config config/game_combined.toml
   --force` (el guardián `check_syms_overrides.py` aborta si se pierde un override; la herramienta
   rechaza delay slots y switches fusionados).

## Cómo leer los logs

- `hh_sched.log`: `queue`/`next`/`signal`/`park`/`wake`/`rntw`/`swap` de cada hilo. Un `park tid=N`
  sin `next/wake tid=N` posterior = hilo encolado que nunca corre.
- **Pacing** (foco actual): `hh_mq_all.log` (`HH_MQLOG_ALL=1`) = **todas** las colas con `t=`, `tid`,
  `mq`, `msg` y `valid`; `[GATE]` (`HH_VERBOSE=1`) y `[GATE2]` (`HH_GATELOG=1`) = cambios de
  `0x8005CD4C` y recv/send del gate RSP; `[SUBM]` (`HH_TBLTRACE=1`) = submits con contador antes/después.
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
