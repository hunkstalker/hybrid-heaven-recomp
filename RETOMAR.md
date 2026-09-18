# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`. Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 4 líneas

- **El port corre y se juega en Windows** (menús → gameplay → CaC, mando Xbox, audio 43200 Hz).
- **Cadencia**: el live limpio va a **30 ticks/s** (`d2=29 d3=1`, ~5% de ticks a 3 VI) → la
  cadencia live es prácticamente la del original; el 27/s medido antes era artefacto de los logs
  pesados de `HH_DIAG`.
- **Replay (diagnóstico)**: la semántica correcta es **`HH_REPLAY_MODE=vi`** (input en función del
  contador VI; se auto-corrige). `run_cac_replay.bat` ya lo usa. Con `mode=poll` cualquier slip
  acumulaba y la ruta se perdía (no determinista entre pasadas).
- **Siguiente bloque de trabajo (aprobado)**: "una N64 que nunca se queda ahogada" — eliminar los
  tirones *del port* (no los hitches auténticos). **Fase B (cache de assets + loader nativo) v1 hecha**
  (`cache/trans.bin` + decoder LZKN64 nativo; cargas 0,2-15 ms). **Causa raíz de los tirones restantes
  localizada**: `get_function()` hacía 4-5 `getenv()` por cada llamada recompilada (millones en el
  decodificador `0x80015A64`/`0x80016xxx`) -> **fix: cachear los flags**; pendiente medir en Windows.
  El CaC/veneno queda en espera.

## TU TAREA AHORA (pasos exactos)

1. **[MANTENEDOR — validación Windows del fix de `get_function`]** Recompilar
   (`port\build_windows.local.bat`) y `port\run_cac_profile.bat` jugando **1-2 min incluyendo la 1ª
   puerta** y cerrar.
   - Objetivo: los stalls de 1-4 s (`hh_slow.log`, picos con `guest_busy≈dt`) deben **desaparecer o
     reducirse mucho**, y la cadencia en gameplay debería acercarse a `d3=1`. Ese overhead afectaba a
     *todo* el código guest, así que puede notarse también en el "régimen 2" (escenas cargadas).
   - Se siguen generando `hh_slice.log` (funciones guest durante un stall) y `hh.log` (líneas
     `[trans] load`) por si hay que afinar más. El `0xC0000005` al cerrar es el **teardown** conocido.
2. **[DEV — Fase B, v1 hecha]** Cache `cache/trans.bin` + decoder LZKN64 nativo
   (`src/game/trans_cache.cpp` + wrapper en `overlays.cpp`; knobs `HH_TRANS_*`). Validado headless
   (nativo==original==`lzkn64.py`) y con `tools/analysis/validate_trans_cache.py`. Detalle:
   `notes/2026-09-18-faseb-cache-trans-implementado.md`. Pendiente: extractor offline opcional.
3. **[DEV — audio] Sincronizar la tasa** para eliminar los descartes del watermark (feedback del
   error de cola SDL en `osAiGetLength`); opcional, mejora el petardeo residual.
4. **[FASE C — decidido, con spike previo] MENÚ IN-GAME de opciones PC** (ADR 0008): reutilizar el
   menú del **Expansion Pak** (`expansionram`; 3 resoluciones Low/High Normal/High Letterbox en el
   original) para opciones PC. **Módulo ya localizado**: manifest **idx 23** (`notes/us_manifest.yaml`),
   ROM **`0x5F1190`** (44.342 B comp → 68.432 B), cargado en **`0x801BF1A0`** — es el módulo que el
   port YA traza y analizó en el CaC (funciones `0x801BF***`/`0x801C0***`, p. ej. `M24_FUN_801bfaa0`
   driver, `M24_FUN_801bffac` avance, `M24_FUN_801bf850` intérprete). **Antes de comprometerla:
   spike go/no-go** (nota `2026-09-18` §6):
   1) localizar el `expansionram` y leer su menú; 2) probar reemplazo del handler de una función de
   MÓDULO end-to-end (no-op con log); 3) pintar un rótulo propio con las fuentes del juego;
   4) aplicar+persistir un valor de `GraphicsConfig` en caliente. Si 1-4 salen -> Fase C normal
   (handler -> `GraphicsConfig`+RT64 + rótulos); si no, adaptar (p. ej. overlay propio). Se descarta
   el launcher del ecosistema.
   > **Calibración**: la viabilidad está evaluada sobre los *mecanismos* (reimplementadas/hooks/
   > patches/config) que este repo ya usa, NO sobre el código del menú (no leído aún). El spike es
   > para confirmarlo.
5. **[OPCIONAL] Warm-up de RT64**: el primer display list del boot tarda ~843 ms (creación de
   pipelines). Ideas: precarga asíncrona, cache de pipelines, o aceptar el hitch de arranque.

## Comandos útiles

- Build Linux debug: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run headless: `DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 ./port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"`
- Replay de una grabación (headless): `HH_REPLAY=<cac_rec.txt> HH_REPLAY_MODE=vi`
- Emulador de referencia: `tools/analysis/emu_ref.sh <prefix> <secs> [dumps]` (usa `work/r64dump`).
- Lanzadores Windows: `run_pacing.bat`, `run_cac_profile.bat`, `run_cac_replay.bat`,
  `run_cac_replay_noaudio.bat`, `run_cac_record.bat`, `run_cac_tick2.bat`.
- LZKN64: `python3 tools/analysis/test_lzkn64.py` (espera la ROM en `rom/baserom.us.z64`; usar
  `work/roms/us_retail.z64` o copiarla).

## Knobs nuevos del runtime (fork local, sin push)

`HH_AI_FIFO` (0 = AI antiguo; por defecto fiel), `HH_AI_MAX_MS` (watermark de la cola SDL),
`HH_TIMESCALE`, `HH_VI_EVERY`, `HH_REPLAY_PACE` (vacío; `vi`/`1`), `HH_REPLAY_MODE` (`vi`),
`HH_DUMP_CNT30`, `HH_DUMP_SAMPLE`, `HH_M24LOG`, `HH_SP_SHARED`, `HH_S0FIX`, `HH_DIAG` (logs
opt-in). **Fase B**: `HH_TRANS_CACHE` (def 1), `HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY`,
`HH_TRANS_DUMP`. Instrumentación siempre activa: `hh_tick.log`, `hh_slow.log`, `hh_state.log`,
`hh_audio.log`.

## Estado de repos/branches

- Main repo: sesión larga; commits previos sin push (`232f833`, `1491836`, `ff7e2cc`, `ef233e1`…).
  Esta sesión NO ha commiteado (pedir antes de commitear).
- Runtime fork (`port/HybridHeavenRecomp/lib/N64ModernRuntime`): cambios **locales** (AI FIFO,
  audio pipeline, ROM read, timeBeginPeriod, watchdog RAM, instrumentación) por encima de
  `948279f`; Windows compila con `port\build_windows.local.bat` (árbol local).

## Documentación de esta sesión

- **`notes/2026-09-18-suavizado-fase1-y-cache-loader.md`** (resumen del día + plan).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B v1: cache + loader nativo; firma
  del loader, validación, knobs).
- Detalle extendido (misma sesión): `notes/2026-09-17-replay-mode-vi-vis-negativo.md` §5b-5i.
- CaC/veneno (histórico relevante): `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`.
