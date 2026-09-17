# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`.
> Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 4 líneas

- Se **juega** en Windows (menús → GAME START → escenas 3D y combate, mando Xbox, audio 43200 Hz,
  Controller Pak emulado). Fixes previos validados: **guardado en cápsula**, cuelgue por daño del
  robot, objeto del NPC y regresión de las escaleras (ver `TODO.md` → "Hecho" y `notes/`).
- **Sesión actual (2026-09-17) — PACING/CADENCIA: CERRADO (validado en Windows)**. Original = 30 fps
  lógicos (`notes/2026-09-17-fase0-*.md`); el limitador eran los logs de diagnóstico always-on
  (ahora opt-in con `HH_DIAG=1`). Windows (RTX 4080) con `port\run_pacing.bat`: **polls 27,1-28,4/s,
  audio 60,0/s, VI 60,0/s**; Linux: 28,9/s y 32,9 disp. Detalle:
  `notes/2026-09-17-fase2-*.md`, `logdiag-y-comparacion-linux-windows` y
  `validacion-windows-pacing-y-cac`.
- **BLOQUEANTE (CaC)**: freeze al entrar en combate (cadencia descartada como causa). Repro Linux con
  replay corto desde guardado (PFS carga, `mode=0004`, polls parados). **Diferencial port↔emulador con
  el MISMO input HECHO**. **Cadena de la divergencia RESUELTA hasta el mecanismo** (2026-09-17, ronda
  nueva): la ráfaga #22 son pasos de guion de la **línea temporal de escena del módulo 24** (driver
  `M24_FUN_801bfaa0`, periodos `g2=[0x801D8CE8]`); en el emulador `g2 0→1` en **VI 2187** (espera por
  tiempo `osGetTime-epoch`, 3/11/20 s) y de ahí sale la ráfaga; en el port el driver corre pero
  **`M24_FUN_801bffac` (avance de periodo) nunca se ejecuta** (esperas siempre 0) y en su lugar la vía
  alterna de cambio de escena (`M24_FUN_801bf508` → `M24_FUN_801c0254`) dispara en **VI≈799-840** y
  carga los módulos 8/9/10/12 sobre el módulo 24 → la ráfaga se pierde. **Rondas 2-3**: base de tiempo
  **refutada** (port `osGetTime` == tiempo VI) y **causa raíz encontrada**: el disparo es el bit
  `0x1000` de `[0x80089478]` = **START recién pulsado** (registro de flancos de input, `FUN_800021b4`).
  El emulador no lo pulsa durante la transición; el port sí porque **aplica el replay por frame**
  (samples 412-431 = START de menú con `vis` 1092-1135 caen en VI 766-803) y su relación frame↔VI
  (~1.86) difiere de la de la grabación (~2.65). **Reproducido y acotado (2026-09-17)**: con el
  replay de **BizHawk** (mantenedor jugó; `bizhawk_hh_tracker_v3.lua` + `bizhawk_to_replay.py`,
  `--vis-offset -100`; el reloj VI del emulador va ~100 VI por delante) el port **se cuelga igual**
  (`[BADMQ] mq=8005C084`, watchdog VI=32122, `work/debug/cac/bizhawk1/hh_hang_rdram_20526_0.bin`) y el
  emulador no. **Clave: la ráfaga #22 SÍ se ejecuta** (cargas #23-35 idénticas) → **la teoría del
  "burst saltado" queda refutada**; el primer desvío nuevo es la **carga #49 (~VI 20500)** (el port
  sigue con ráfaga de escena y el emulador recarga menú/módulo). **Siguiente**: rebuild para `[LD384]
  s=`, dumps finos 20400-20800 en ambos lados y comparar estado de la línea temporal/directorio.
  `HH_REPLAY_CLOCK` queda de fallback. **El test de juego del port nativo lo hace el usuario
  (mantenedor)**; dev solo hace pasadas headless. Detalle:
  **`notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`**.
  - Evidencia previa (veneno/llamante): `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md` (§1-10).
    Contexto: `notes/2026-09-17-cac-ownership-resuelto.md`. Replay Linux fiel;
    `run_corrupt.bat clean` para grabar estable. El freeze en Windows se graba/reproduce con
    `run_corrupt.bat` / `run_replay.bat`.
- **Runtime (fork) con cambios LOCALES sin push** (`e9a178f`, `efc5f17`, `0806e19`), por encima del
  pin publicado `feae2d5`. En Windows usar **`port\build_windows.local.bat`** (no `--force-libs`,
  que resetea `lib\` al pin y perdería las mitigaciones).

## TU TAREA AHORA (pasos exactos)

> **Nota operativa actual (CaC)**: **`notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`** (diferencial
> completo; §10 = primera divergencia de flujo). El plan antiguo
> `notes/2026-09-17-plan-revision-bloqueo-cac.md` está **superado** (su premisa "case 2 arma combate"
> quedó refutada; se conserva como historial).
> Pacing cerrado: `notes/2026-09-17-workorder-pacing-cadencia.md` y
> `notes/2026-09-17-validacion-windows-pacing-y-cac.md`.

> **Los logs de diagnóstico now requieren `HH_DIAG=1`** (default off). Para medir pacing, usar
> `port\run_pacing.bat` (Windows) o los defaults (Linux). No hace falta tmpfs desde el gating.

1. **[SIGUIENTE — CaC: primer desvío con la ráfaga hecha = carga #49 (~VI 20500)]**.
   El replay de BizHawk reproduce el freeze en el port CON la ráfaga #22 → refutada la teoría del
   burst saltado. El primer desvío de flujo es la **carga #49** (`~VI 20500`): el port sigue cargando
   recursos de escena (`00B7EF20@8025D168`, …) y el emulador recarga menú/módulo (`005F1190@801BF1A0`,
   …); 14 cargas después el port engancha la cadena del emulador (port #63 = emu #49).
   - **Pasos**: (a) rebuild (`make -C build_dbg`) para tener `[LD384] … s=<muestra>`; (b) dumps finos
     (20400/20500/20600/20800) en port (`HH_DUMP_VI`) y emulador (`HB_DUMP_VI`) con el mismo replay;
     (c) comparar línea temporal módulo 24 (`0x801D8CE8`, `0x801D8DA8`, `0x801D8D00`, `0x801D8CFC`),
     directorio `0x8008DFC8`, objeto de transición `0x801FDA70` y colas; (d) seguir el primer campo que
     diverja, aguas arriba.
   - Detalle: **`notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`** y
     **`notes/2026-09-17-cac-timeline-modulo24-periodo.md`** (§4b-5).
   - Instrumentación: `[DT]`, `[LST]`, `[TL]`, `[LD384] s=` en el runtime (fork local, commit
     `948279f`); `bizhawk_hh_tracker_v3.lua` + `bizhawk_to_replay.py` (main, commit `1491836`).
2. **[Pacing — CERRADO]** validación Windows hecha (27,1-28,4 polls/s, audio 60,0/s). Afinar a 30/s
   exactos es opcional y no bloqueante (knobs `HH_NO_MQYIELD`/`HH_MQYIELD` disponibles).
3. **[Verificado]** gating completo (`pi.cpp` incluido, tras el reinicio de Windows): por defecto
   solo `hh_state` + volcados; con `HH_DIAG=1` reaparecen todos.
4. **Knobs e instrumentación nuevos** (runtime local, sin commitear): `HH_DIAG=1`,
   `HH_NO_MQYIELD`, `HH_MQYIELD=wake|QUANTUM_MS`, `HH_YIELD_STRICT`, `hh_wait.log` (`HH_WAITLOG=1`),
   `[TRACE]` con `t=`/`tid=`, `[GATE]/[GATE2]/[SUBM]` con `t=`, sched con `ra=`.
   **No usar `HH_MQLOG_ALL` para pacing** (atasca aun filtrado).
5. **[Backlog documentado, posterior]** estabilidad de cadencia (28,4 vs 30) y hitches de puertas:
   plan de medición y fixes en `notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`
   (TODO → Backlog). No es la causa del CaC.
6. Si crashea con `Failed to find function at 0x...` (dirección **válida**): `python3
   tools/analysis/add_mid_entry.py 0xADDR` + `tools/recomp.py --config config/game_combined.toml
   --force` (el guardián `check_syms_overrides.py` aborta si se pierde un override; la herramienta
   rechaza delay slots y switches fusionados).

## Cómo leer los logs

- `hh_sched.log`: `queue`/`next`/`signal`/`park`/`wake`/`rntw`/`swap` de cada hilo. Un `park tid=N`
  sin `next/wake tid=N` posterior = hilo encolado que nunca corre.
- **Pacing** (cerrado; referencia): `hh_mq_all.log` (`HH_MQLOG_ALL=1`) = **todas** las colas con `t=`, `tid`,
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
- `hh_watch.log` (watchpoint, `run_watch.bat`; env `HH_WATCH_ADDR`/`HH_WATCH_SIZE`): accesos de código
  recompilado a un rango, con `val=`, `ra`, `a0..a3` y `ret=(exe+0x…)` (simbolizar con `addr2line -e
  "Hybrid Heaven Recomp"`). **Ojo**: no ve las escrituras directas del runtime (p. ej. `do_send`).
- `[LD384]` (`HH_TBLTRACE=1`): cada carga del loader `FUN_80003824` (`a0`=src ROM, `a1`=dst,
  `a2`=size, `a3`=fin) + `0x801CC8C4` post-carga. `[SETCB]`: cada llamada al setter `FUN_800058dc`
  (`obj`, `cb`). `[MODT]` (`HH_MODTRACE=[rom:]offset:label,…`): entrada a funciones por offset de
  módulo (base-aware; incluye `vi`, `mode`, `ra`). `[SUBM]`: submits del RSP.
- Emulador: `[MPIW] wr 0x… val=… pc=…` = watchpoint de escritura del core
  `work/libmupen64plus-wplog.so` (`HH_WPLO`/`HH_WPHI` **físicas**); `[dbg] stop pc=… vi_count=… a0=…`
  = breakpoint de ejecución de `HB_TRACE_EXEC=<csv de PCs>` en `r64dump`; `[HHR] idx=N/M` = progreso
  del replay del plugin `work/hhinput.so` (`HH_KEYS_REPLAY=<txt>`, mismo formato que el port).

## Entorno / git

- **Repo principal**: `git push origin main` es fast-forward (publica el fix del B y el mid-entry).
  No he hecho push.
- **Fork del runtime** (rama `hybrid-heaven`, con `main` = upstream): commits locales de esta sesión
  `e9a178f`, `efc5f17`, `0806e19` **sin push**. `port/runtime.lock` sigue en `feae2d5`.
  Flujo: editar `lib/N64ModernRuntime` → commit → push al fork → actualizar el SHA del lock.
  `N64Recomp` es submódulo (fork propio) del runtime.
- Bats: `build_windows.bat` (clona/actualiza por lock), **`build_windows.local.bat`** (compila `lib\`
  tal cual, sin git; no versionado), `run_windows.bat` (admite `noaudio`/`audlog`),
  **`run_pacing.bat`** (pacing: movidos a `logs_pacing_<fecha>\`; modos `trace` y `gate`),
  `run_mqlog.bat` (traza + s0fix) y `run_watch.bat` (watchpoint; ahora en `0x8024A9A8` tamaño `0x80`).
  Los tres últimos ponen `HH_DIAG=1` (los logs always-on son opt-in).
- Docs vivos: `AGENTS.md` (arranque) · `TODO.md` · `PROYECTO.md` · `notes/` (evidencia por ronda).
