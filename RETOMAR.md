# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota más reciente en `notes/`. Actualizar o borrar al cambiar la tarea.
> Última sesión: **2026-09-18**.

## Estado en 5 líneas

- **El port corre y se juega en Windows** (menús → gameplay → CaC, mando Xbox, audio 43200 Hz), a
  **30 ticks/s** estables (rendimiento resuelto: fix de `get_function` + Fase B de assets).
- **HITO de la última ronda**: el **replay reproduce el CaC de forma fiable** en el port (Windows
  VI≈20710 y Linux VI≈20949) usando **`HH_REPLAY_MODE=poll`**; y el **emulador pasa el CaC con el mismo
  input** (objeto sano). Por primera vez tenemos los dos lados con **input idéntico**.
- **Diferencial por VI hecho (20200–20900)**: port y emu **idénticos** en el estado del CaC (cuando el
  port no congela). Primera divergencia = **timing** del loader (carga #12: port vis 413 vs emu vi 1535),
  no la secuencia (verificada 1:1 con argumentos: 43/43 cargas idénticas).
- **VENENO CAPTURADO EN VIVO** (watchpoint en `0x8024AB14`): `FUN_800058dc` escribe `0xFFFF84CD` con
  `a0=0x8024AAF8` (llamante con `a2=0x801BC23A`/`a3=0x801BBBF0`); `M7_FUN_8012e774` lo consume. Cadena
  del setter **confirmada con evidencia directa**.
- **CONTRALADO EMULADOR (decisivo)**: mismo replay, el emu ejecuta `FUN_800058dc` **1426 veces sin el
  veneno** y **0 veces** `M10_FUN_8022c7ac`/`M55_FUN_80379410`. La forma correcta es **NO ejecutar el
  disable**: el callback sano del objeto es `801CB71C`.
- **Síntoma del bug**: el objeto `0x8024A990` acaba con callback `+0x1C=0xFFFF84CD` y colas `[BADMQ]`;
  `tid5` parado en `osRecvMesg` de `0x8005C288`. En el emulador ese objeto sigue vivo (`801CB71C`).
- **Lección de replay**: con el port ya a 30 ticks/s, `mode=vi` **sesga** el input (síntoma: "el PJ se
  va ligeramente a un lado"); **`mode=poll` es el correcto**. `HH_REPLAY_PACE` vacío.
- **Documentación consolidada**: `docs/README.md` es la visión/roadmap; Plan Maestro archivado; TODO y
  PROYECTO cortos. Visión a largo plazo: cobertura nativa progresiva.

## TU TAREA AHORA (pasos exactos)

**Objetivo: saber por qué el port llega a `M10_FUN_8022c7ac`** (que dispara el disable) y el emulador
**nunca**. El veneno y el contralado del emulador ya están capturados (ver §2d/§2e de la nota del
diferencial). La ruta correcta es **no ejecutar** `M10_FUN_8022c7ac`/`M55_FUN_80379410`.

### Datos de partida (fijos)

- Replay: `port/HybridHeavenRecomp/build_win/bin/Release/logs_pacing_20260918_210956/cac_rec.txt`
  (9815 muestras). **No re-grabar** salvo que se cambie algo del port.
- **Captura del veneno (headless)**: `build_dbg/hh_watch.log` (con `HH_WATCH_ADDR=0x8024AB14`),
  `hh_hang_rdram_50826_*.bin`. El watchpoint **mueve el freeze** (VI≈20170 vs 20949 sin él): es una
  carrera sensible al timing; el trace (`HH_TRACE`) a veces lo evita.
- **Contralado emulador**: `HB_TRACE_EXEC=0x800058DC` → 1426 llamadas, 0 con veneno; `HB_TRACE_EXEC=`
  `0x8022C7AC,0x80379410` → 0 ejecuciones. Volcados: `work/debug/cac/emu_trace_*`.
- Dumps del diferencial (paridad): `work/debug/cac/diff_vi_20260918/`.
- **Bug corregido**: `hh_ring2_n`/`hh_ring_n` desbordaban `int` a ~50 s (43 M llamadas/s) → SEGV en
  `hh_ring2_record`. Ya son `uint64_t` (runtime NMR, commit pendiente de push).

### 1. Localizar quién invoca `M10_FUN_8022c7ac`

- Es **callback por puntero** (no aparece ningún `LOOKUP_FUNC(0x8022C7AC)` en el C recompilado). Buscar
  la tabla/estructura que lo contiene: su VRAM es `0x8022C7AC` (módulo 10, base real `0x8021B150`).
- En el port, con el watch de `0x8024AB14` activo (que sí congela), capturar el **primer** instante en
  que se entra a `M10_FUN_8022c7ac` (trace `HH_TRACE=0x8022c7ac:M10`) y ver la pila/estado previo.
- Comparar con el emulador: **no lo ejecuta**; ¿qué condición lo evita? (el gate `0x8017DD92` vale 0 en
  ambos; debe ser otra cosa aguas arriba — estado de la state machine M12 / directorio de escena).

### 2. Atacar el desfase de timing del loader #12

La **secuencia** coincide 1:1; el **timing** no: la carga #12 (`005FBEC6→801BF1A0`) ocurre en el port a
**vis 413** y en el emu a **vi 1535** (~18 s de espera de escena que el port no consume). Es el
candidato nº1 a explicar por qué el port ejecuta un camino que el emu no.

### 3. Investigar `0x8005C4F0`/`0x8005C268`

En el port (sin freeze) están a **cero**; en el emu valen `80049930`. Watchpoint para ver quién las
escribe (o debería) y si su valor nulo explica la espera de #2.

> **Informe del diferencial: `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`.**

### (Contexto) Reproducir el freeze

- In-vivo (Windows, mantenedor): `run_cac_replay.bat` (poll) con `HH_WATCH_ADDR=0x8024AB14`
  `HH_MQLOG_ALL=1`. Es donde el freeze es ~100 %.
- Headless: `HH_REPLAY_MODE=poll` **sin** `HH_DUMP_VI`/`HH_M24LOG` (la instrumentación perturba el
  freeze); el watchpoint `0x8024AB14` sí lo capturó (aunque lo mueve de VI).
> Hito previo: `notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`.

## Contexto del CaC (lo ya sabido; no repetir)

- Reproducido en Linux con replay; **no es rendimiento**.
- La **ráfaga #22** del módulo 24 **sí** se ejecuta (teoría "burst saltado" refutada).
- Cadena del setter del veneno (documentada):
  `M10_FUN_8021b280 → M10_FUN_8022c7ac (gate 0x8017DD92) → M55_FUN_80379410 → FUN_800058dc(a1=0xFFFF84CD)`.
- Plan B alternativo: instrumentar el vivo (`HH_WATCH_ADDR=0x8024A9AC` + `HH_MQLOG_ALL`).
- Histórico: `notes/2026-09-17-cac-ownership-resuelto.md`, `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`, `notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`.

## Otras tareas vivas (TODO.md "Ahora")

- **Audio**: sincronizar la tasa (feedback del error de cola SDL en `osAiGetLength`).
- **Menú in-game (ADR 0008)**: spike go/no-go antes de comprometerlo.
- **Definir ADR 0009** (visión de cobertura nativa/clean-room) cuando se adopte.
- **Teardown SEGV** al cerrar en Windows; **mando** (botón de menú CaC → X, bloqueado por el CaC).

## Comandos útiles

- Build Linux debug: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run headless: `DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 ./port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"`
- Replay headless (el bueno): `HH_REPLAY=<cac_rec.txt> HH_REPLAY_MODE=poll` (añadir `HH_DUMP_VI=...`,
  `HH_M24LOG=1` según necesidad).
- Emulador: `tools/analysis/emu_ref.sh <prefix> <secs> [dumps]` (usa `work/r64dump`, `work/roms/us_retail.z64`).
- Lanzadores Windows: `run_cac_record.bat`, `run_cac_replay.bat` (**ya usa `poll`**), `run_cac_tick2.bat`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `INDEX.md`; `--check` valida).

## Knobs del runtime

`HH_AI_FIFO` (def fiel), `HH_AI_MAX_MS`, `HH_TIMESCALE`, `HH_VI_EVERY`, **`HH_REPLAY_MODE` (`poll`)**,
`HH_REPLAY_PACE` (vacío; **no** usar `vi`: tirones), `HH_REPLAY_CLOCK` (reloj determinista por VI),
`HH_DUMP_VI`, `HH_DUMP_SAMPLE`, `HH_M24LOG`, `HH_S0FIX`, `HH_DIAG`, `HH_WATCH_ADDR`/`HH_MQLOG_ALL`.
**Fase B**: `HH_TRANS_CACHE` (def 1), `HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.

## Estado de repos/branches

- **Main repo**: `main` = `origin/main` (todo pusheado; último: `2c52b42`). Historial reescrito
  (limpieza de la mención a ROMs). `backup-orig` conserva el historial anterior (borrar con
  `git branch -D backup-orig` cuando se quiera).
- **Runtime fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime`, repo aparte): `hybrid-heaven` =
  `fork/hybrid-heaven` (`a3a434f`, reloj de replay determinista). `port/runtime.lock` = `a3a434f`.
- Windows compila con `port\build_windows.local.bat` (árbol local, no versionado).

## Documentación de esta sesión

- **`notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`** (informe del diferencial; paridad + timing loader).
- **`notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`** (HITO: replay fiel + emulador).
- **`notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`** (ronda previa: reloj determinista, test).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B + fix de `get_function`).
- **`docs/README.md`** (visión/roadmap) · `notes/archive/2026-09-18-plan-maestro-legacy.md`.
