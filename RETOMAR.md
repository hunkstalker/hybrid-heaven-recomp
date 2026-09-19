# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota más reciente en `notes/`. Actualizar o borrar al cambiar la tarea.
> Última sesión: **2026-09-19** (tarde).

## Estado en 6 líneas

- **El port corre y se juega en Windows** (menús → gameplay → CaC, mando Xbox, audio 43200 Hz), a
  **30 ticks/s** estables (rendimiento resuelto: fix de `get_function` + Fase B de assets).
- **El replay reproduce el CaC de forma fiable** con **`HH_REPLAY_MODE=poll`** (Windows VI≈20710,
  Linux VI≈20949); el **emulador pasa el CaC con el mismo input** (objeto sano). Tenemos los dos lados
  con input idéntico.
- **Diferencial por VI (20200–20900)**: port y emu **idénticos** en el estado del CaC (cuando el port no
  congela). Única divergencia reproducible = **timing** del loader (carga #12: port vis 413 vs emu vi
  1535), no la secuencia (verificada 1:1: 43/43 cargas).
- **Veneno capturado en vivo (wrapper, `hh_venom.log`)**: `FUN_800058dc` escribe `0xFFFF84CD` en
  `0x8024AB14` (callback del objeto `0x8024AAF8`); `M7_FUN_8012e774` lo consume. **Cadena confirmada
  por el callring**:
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → M10_FUN_8022c5ac → M10_FUN_8022c314 → M10_FUN_8022c478 →
  M55_FUN_80379410 → FUN_800058dc`.
- **CONTRALADO EMULADOR (decisivo)**: con el mismo replay, el emu ejecuta `FUN_800058dc` **1426 veces
  sin el veneno** y **0 veces** `M10_FUN_8021b280`/`M55_FUN_80379410`. La forma correcta es **NO
  ejecutar el disable**; el callback sano del objeto es `801CB71C`. `M10_FUN_8021b280` se invoca como
  **callback por puntero** (12 resoluciones, `ra=0`).
- **Dos hipótesis de fix DESCARTADAS** (probadas): (a) reloj determinista `HH_DET_CLOCK` → 30 fps pero
  la ruta vuelve con stalls; (b) desactivar el disable `HH_NO_DISABLE=1` → en vivo **sigue colgando**.
  ⇒ El trigger son los **stalls/alineación frame↔VI** (en vivo: ticks de 3 VI, `guest_busy` ~34 ms).
- **Lección de replay**: con el port ya a 30 ticks/s, `mode=vi` **sesga** el input; `mode=poll` es el
  correcto. **PERO ojo**: en Windows en vivo el replay con `poll` **aún deriva** por los ticks de 3 VI
  (`hh_slow.log`); no es fiel al gameplay original hasta que se arreglen los stalls.

## TU TAREA AHORA (pasos exactos)

**Objetivo: hacer que el CaC entre.** Están identificados la **cadena**, el **instalador** y la **puerta**
del disable, y se han descartado dos hipótesis de fix (reloj determinista y desactivar el disable). **La
tarea es alinear frame↔VI** (los stalls del hilo de juego). Detalle:
`notes/2026-09-19-veneno-capturado-bug-signo-extension.md`.

### 0. Ya hecho (no repetir)

- **`hh_venom.log` capturado** (bug de signo-extensión corregido). Cadena confirmada:
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → M10_FUN_8022c5ac → M10_FUN_8022c314 → M10_FUN_8022c478 →
  M55_FUN_80379410 → FUN_800058dc`.
- **Instalador**: `M10_FUN_8021b240` publica `0x8021B280` en el slot `0x8024C950` del objeto
  `0x8024C934` vía `FUN_800058dc`, **solo si `M7_FUN_80126A0C(obj,0x39,1) != 0`**.
- **Puerta**: `M7_FUN_80126A0C`→`M7_FUN_80126A18` devuelve 1 si `[0x8008D580] < 0x3001` y
  `FUN_801267B8(lhu[sp+0x1E]) == 1` y `[0x801BBD71]==0`.
- **Reloj `HH_DET_CLOCK`** (implementado): `osGetTime = total_vis*781250 + sub-VI`; **da 30 fps**, pero
  **no** elimina la carrera (con watchpoint vuelve a aparecer 3/4). El trigger son los **stalls**.
- **Workaround `HH_NO_DISABLE=1` PROBADO EN VIVO (Windows): NO funciona.** Sigue el cuelgue antes del
  CaC. ⇒ El disable **no** es el único bloqueo: hay algo más aguas arriba. **Hipótesis fuerte**: el
  envenenamiento es un *síntoma* de que el frame del port va desalineado respecto al VI durante toda la
  transición; desactivarlo no arregla la transición.
- **Evidencia Windows (clave)**: en vivo hay desde el principio ticks de **3 VI** con `guest_busy`
  34–35 ms (`hh_slow.log`, presupuesto 2 VI = 33.3 ms), y el replay con `poll` **desvía el input**
  (no es fiel al gameplay original). El emulador no lo sufre: su frame va en lockstep con el VI.

### 1. Alinear frame↔VI (PRIORIDAD ÚNICA)

El limiter apunta a ~33.3 ms pero cierra a ~34 ms; según la fase respecto a la rejilla VI, el frame
abarca 2 o 3 VI. Objetivo: que **cada frame de juego abarque exactamente 1 tick / 2 VI** (como el
emulador), pase lo que pase con los stalls. Opciones a evaluar:
- Hacer que el limiter **reanude el frame sobre la rejilla VI** (no sobre el reloj continuo).
- **Desacoplar/eliminar los stalls** del hilo de juego (`send_dl` ~3 ms + `guest_busy` ~34 ms; RT64,
  WASAPI, I/O de logs).
- Ver §1 del handoff 2026-09-18 (`frame limiter 0x80001A88`, rutinas `__ll_*`
  `0x80026E58/0x80026F58/0x80034C24/0x80034AB8`).

**Banco de pruebas**: el freeze es intermitente headless (~1/3) pero ~100 % en **Windows en vivo**.
Validar en vivo (mantenedor) y afinar headless.

### 2. Diferencial de la puerta en el MISMO VI

Con `HH_B280TRACE=1` el trazado vuelca `0x188`/`0x181`/timer `0x42D0`/`0x42FF`/mode `0x8017DD92`.
Compararlas port↔emu en el mismo VI localiza la **primera divergencia exacta** (si la hay antes de la
transición). Candidato: la **espera de escena** (loader #12).

### 3. Investigar `0x8005C4F0`/`0x8005C268`

En el port (sin freeze) están a **cero**; en el emu valen `80049930` (§2b de la nota del diferencial).

> **Informe del diferencial: `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`.**

## Datos de partida (fijos)

- Replay: `port/HybridHeavenRecomp/build_win/bin/Release/logs_pacing_20260918_210956/cac_rec.txt`
  (9815 muestras). **No re-grabar** salvo que se cambie algo del port.
- Captura del veneno (wrapper): **`work/debug/cac/venom_20260919/hh_venom.log`** (+ `hh_owner.log`,
  `hh_b280_get.log`, `hh_b280set.log`).
  Watchpoint previo: `build_win/.../logs_*/hh_watch.log` (`HH_WATCH_ADDR=0x8024A9AC`/`0x8024AB14`).
- Instalador del disable: slot `0x8024C950` (obj `0x8024C934`) ← `M10_FUN_8021b240` ← `M7_FUN_80126A0C`.
- Contralado emulador: `work/debug/cac/emu_trace_*` (setter 1426/0 veneno; `M10_FUN_8021b280` 0).
- Dumps del diferencial (paridad): `work/debug/cac/diff_vi_20260918/`.
- **Prueba Windows del workaround (19-09)**: `build_win/.../logs_nodisable_20260919_081332/`
  (`hh_slow.log` con ticks de 3 VI; `guest_busy` 34–35 ms). Lanzadores:
  `port/run_cac_nodisable.bat` (replay) y `port/run_nodisable_live.bat` (en vivo, sin replay).
- **Bug corregido**: `hh_ring2_n`/`hh_ring_n` desbordaban `int` a ~50 s (43 M llamadas/s) → SEGV en
  `hh_ring2_record`. Ya son `uint64_t` (runtime NMR).
- **Bug corregido (19-09)**: comparación del veneno con signo-extensión; `HH_RETURN_ADDR()` en vez de
  `__builtin_return_address` (portabilidad MSVC). Ver nota 2026-09-19.

## Contexto del CaC (lo ya sabido; no repetir)

- Reproducido en Linux con replay; **no es rendimiento**.
- La **ráfaga #22** del módulo 24 **sí** se ejecuta (teoría "burst saltado" refutada).
- La llamada a `M10_FUN_8022C7A4` en `0x8021B69C` está condicionada por `lhu [objeto+0x2C]` ∈ {0xA,0xB}
  (pero ese campo vale 0 en los dumps → el discriminante es otro).
- Otro port independiente (`danielgomesvieira2000/hybrid-heaven-recomp`) va **más atrás** (no llegó al
  CaC) pero su doc confirma `0x801CC8C4` = "level/battle select" y da el lead del frame limiter.
- Histórico: `notes/2026-09-17-cac-ownership-resuelto.md`, `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`, `notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`.

## Otras tareas vivas (TODO.md "Ahora")

- **Audio**: sincronizar la tasa (feedback del error de cola SDL en `osAiGetLength`).
- **Menú in-game (ADR 0008)**: spike go/no-go antes de comprometerlo.
- **Definir ADR 0009** (visión de cobertura nativa/clean-room) cuando se adopte.
- **Teardown SEGV** al cerrar en Windows; **mando** (botón de menú CaC → X, bloqueado por el CaC).

## PENDIENTE (empezar la próxima sesión por aquí)

- [ ] **`.bat` de arranque para la vía de los stalls**: un lanzador Windows (p. ej.
  `port/run_stall_check.bat`, siguiendo el estilo de `run_nodisable_live.bat`) que arranque el port en
  vivo y **recoja/rotule** `hh_slow.log`, `hh_slice.log`, `hh_tick.log` y `hh_state.log`, y muestree
  `guest_busy` / `dvi` por tick, para que el mantenedor solo tenga que lanzarlo y devolver los logs.
  Objetivo: medir por qué el hilo de juego hace ticks de 3 VI (`guest_busy` ~34 ms) y atacar la
  alineación frame↔VI. Ver §1 de "TU TAREA AHORA" y `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` §6b.

## Comandos útiles

- Build Linux debug: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run headless: `DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 ./port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"`
- Replay headless (el bueno): `HH_REPLAY=<cac_rec.txt> HH_REPLAY_MODE=poll` (añadir `HH_DUMP_VI=...`,
  `HH_M24LOG=1` solo si no perturban el objetivo). El veneno es intermitente (~1/3): reintentar.
- Emulador: `tools/analysis/emu_ref.sh <prefix> <secs> [dumps]` (usa `work/r64dump`, `work/roms/us_retail.z64`).
- Windows: `port\build_windows.local.bat` (build), `run_cac_replay.bat` (replay),
  `run_cac_nodisable.bat` (replay + workaround), `run_nodisable_live.bat` (en vivo + workaround),
  `run_cac_record.bat`, `run_cac_tick2.bat`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `INDEX.md`; `--check` valida).

## Knobs del runtime

`HH_AI_FIFO` (def fiel), `HH_AI_MAX_MS`, `HH_TIMESCALE`, `HH_VI_EVERY`, **`HH_REPLAY_MODE` (`poll`)**,
`HH_REPLAY_PACE` (vacío; **no** usar `vi`: tirones), `HH_REPLAY_CLOCK` (reloj de replay por VI),
**`HH_DET_CLOCK`** (reloj de juego determinista sub-VI; da 30 fps pero no arregla los stalls),
`HH_DUMP_VI`, `HH_DUMP_SAMPLE`, `HH_M24LOG`, `HH_S0FIX`, `HH_DIAG`, `HH_WATCH_ADDR`/`HH_WATCH_VENOM`/
`HH_MQLOG_ALL`, **`HH_NO_DISABLE`** (workaround: probado, no basta), **`HH_B280TRACE`** (traza del
instalador del disable + variables de puerta), **`HH_CLOCKDIAG`**. **Fase B**: `HH_TRANS_CACHE` (def 1),
`HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.

## Estado de repos/branches

- **Main repo**: `main` = `origin/main` (`17f4406`, todo pusheado). Historial reescrito (limpieza de la
  mención a ROMs). `backup-orig` conserva el historial anterior (borrar con `git branch -D backup-orig`).
- **Runtime fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime`, repo aparte): `hybrid-heaven` en
  `5c27d30` (ya pusheado) **con 3 ficheros modificados sin commitear**:
  - `librecomp/src/overlays.cpp` (fix del veneno: cast a `uint32_t` + `hh_dump_venom` + wrapper de
    `FUN_800058f4`; trazas `HH_B280TRACE`; workaround `HH_NO_DISABLE`; diag `HH_CLOCKDIAG`;
    `HH_RETURN_ADDR`).
  - `ultramodern/src/timer.cpp` + `ultramodern/src/events.cpp` (reloj determinista `HH_DET_CLOCK` +
    `hh_get_vi_wall_us`; da 30 fps pero **no** arregla la carrera).
  `recomp.cpp` (volcado de pila del watchpoint) ya está en `5c27d30`. `port/runtime.lock` apunta al
  pin publicado. **Los 3 ficheros NO están pusheados**: para Windows hay que copiarlos al árbol local
  (o commitear/pushear y sincronizar).
- Windows compila con `port\build_windows.local.bat` (árbol local, no versionado).
- **Nuevo en el repo**: `port/run_cac_nodisable.bat`, `port/run_nodisable_live.bat` (sin commitear).

## Documentación de esta sesión

- **`notes/2026-09-19-veneno-capturado-bug-signo-extension.md`** (esta ronda: fix del wrapper,
  `hh_venom.log`, cadena confirmada, llamante por puntero).
- **`notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`** (informe del diferencial + §6: cadena
  del disable, comparación con el otro port, instrumentación nueva).
- **`notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`** (HITO: replay fiel + emulador).
- **`notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`** (reloj determinista, test de determinismo).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B + fix de `get_function`).
- **`docs/README.md`** (visión/roadmap) · `notes/archive/2026-09-18-plan-maestro-legacy.md`.
