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
- **Síntoma del bug**: el objeto `0x8024A990` acaba con callback `+0x1C=0xFFFF84CD` y colas `[BADMQ]`;
  `tid5` parado en `osRecvMesg` de `0x8005C288`. En el emulador ese objeto sigue vivo (`801CB71C`).
- **Lección de replay**: con el port ya a 30 ticks/s, `mode=vi` **sesga** el input (síntoma: "el PJ se
  va ligeramente a un lado"); **`mode=poll` es el correcto**. `HH_REPLAY_PACE` vacío.
- **Documentación consolidada**: `docs/README.md` es la visión/roadmap; Plan Maestro archivado; TODO y
  PROYECTO cortos. Visión a largo plazo: cobertura nativa progresiva.

## TU TAREA AHORA (pasos exactos)

**Objetivo: diferencial port↔emulador en el MISMO VI, alrededor del envenenamiento**, con el mismo
`cac_rec.txt` de la última grabación. La grabación y el build ya son fieles, así que no hace falta
grabar de nuevo.

### Datos de partida (fijos)

- Replay: `port/HybridHeavenRecomp/build_win/bin/Release/logs_pacing_20260918_210956/cac_rec.txt`
  (9815 muestras). **No re-grabar** salvo que se cambie algo del port.
- Envenenamiento en el port: **~VI 20.7k (Win) / 20.9k (Linux)**. Dumps del cuelgue ya guardados.
- Emulador: pasa el CaC; volcado final en `work/debug/cac/emu_nodump`.

### 1. Port (Linux headless) con dumps en VI coordinados

Desde `port/HybridHeavenRecomp/build_dbg` (ver "Comandos"):
```
HH_REPLAY=<...>/cac_rec.txt HH_REPLAY_MODE=poll HH_DUMP_VI=20200,20500,20700,20900 HH_M24LOG=1
```
Genera `build_dbg/work/debug/port_vi<VI>.bin`. (El freeze es ~VI 20.9k; los dumps caen antes.)

### 2. Emulador con dumps en los MISMOS VI

```
tools/analysis/emu_ref.sh work/debug/cac/emu_diff 340
```
y, para dumps por VI, usar `HH_REPLAY_VI=20200,20500,20700,20900` (y/o `HH_REPLAY_VI_OFF`) en `r64dump`.
Genera `work/debug/cac/emu_diff.vi<VI>.bin`. **Ejecutar port y emulador de uno en uno** (evitar
contención de CPU: es lo que hacía parecer lento al emulador).

### 3. Comparar y seguir aguas arriba

Comparar en cada VI: `0x8024A990`, `0x8024AAF8`, `0x8024AB14` (callback), directorio `0x8008DFC0/DFC4`,
M24 (`0x801D8CE8`/`DA8`), colas. La primera diferencia marca dónde seguir (dumps en el VI previo).
**Recordatorio**: el volcado del port del cuelgue es 15 s posterior → comparar en VI iguales, no el dump
del hang. Ayuda: `tools/analysis/diff_rdram.py <port> <emu> [base size]`.

> Detalle completo del hito: `notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`.

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

- **`notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`** (HITO: replay fiel + emulador).
- **`notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`** (ronda previa: reloj determinista, test).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B + fix de `get_function`).
- **`docs/README.md`** (visión/roadmap) · `notes/archive/2026-09-18-plan-maestro-legacy.md`.
