# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado), `docs/README.md` (visión) y la nota más reciente en `notes/`. Actualizar o borrar este
> archivo cuando cambie la tarea.

## Estado en 4 líneas

- **El port corre y se juega en Windows** (menús → gameplay → CaC, mando Xbox, audio 43200 Hz).
- **Cadencia**: **30 ticks/s** estables (`d2=29-30`), sin stalls. Causa raíz de los tirones resuelta:
  `get_function` hacía 4-5 `getenv()` por llamada recompilada; se cachean los flags. **Fase B** (cache
  de assets + loader LZKN64 nativo) hecha y validada. La caché experimental de `get_function` resultó
  **neutra** y se revirtió.
- **Replay (diagnóstico)**: semántica correcta = **`HH_REPLAY_MODE=vi`**; `run_cac_replay.bat` ya lo usa.
- **Documentación consolidada**: `docs/README.md` ahora es la **visión/roadmap**; el Plan Maestro viejo
  quedó archivado; `TODO`/`PROYECTO` recortados. El CaC/veneno sigue **en espera**.

## TU TAREA AHORA (pasos exactos)

1. **[DEV — audio] Sincronizar la tasa** para eliminar los descartes del watermark (feedback del error
   de cola SDL en `osAiGetLength`); mejora el petardeo residual. Ver nota 09-18 §2.
2. **[DEV — menú in-game (ADR 0008)] Spike go/no-go** antes de comprometerlo: reemplazar el handler de
   una función de módulo end-to-end, pintar un rótulo con las fuentes del juego y aplicar/persistir un
   valor de `GraphicsConfig` en caliente. Detalle: nota `2026-09-18-suavizado-...` §6.
3. **[VISIÓN] Definir ADR 0009** (estrategia de cobertura nativa / clean-room) **cuando se adopte** la
   visión de `docs/README.md`; incluye el manifiesto de reimplementadas + métrica de cobertura.
4. **[MANTENEDOR] Teardown SEGV** al cerrar en Windows y **botón de menú de combate → X**.
5. **[OPCIONAL] Warm-up de RT64**: el primer display list del boot tarda ~843 ms (pipelines).

> **CaC/veneno (en espera)**: bloqueante de lógica/estado (objeto `0x8024A990`, `[BADMQ]`), NO de
> rendimiento. Próximo paso: primera divergencia de flujo port↔emulador. Ver `TODO.md` (Backlog) y
> `notes/2026-09-17-cac-*.md`.

## Comandos útiles

- Build Linux debug: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run headless: `DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 ./port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"`
- Replay de una grabación (headless): `HH_REPLAY=<cac_rec.txt> HH_REPLAY_MODE=vi`
- Emulador de referencia: `tools/analysis/emu_ref.sh <prefix> <secs> [dumps]` (usa `work/r64dump`).
- Lanzadores Windows: `run_pacing.bat`, `run_cac_profile.bat`, `run_cac_replay.bat`,
  `run_cac_replay_noaudio.bat`, `run_cac_record.bat`, `run_cac_tick2.bat`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## Knobs del runtime

`HH_AI_FIFO` (0 = AI antiguo; por defecto fiel), `HH_AI_MAX_MS` (watermark de la cola SDL),
`HH_TIMESCALE`, `HH_VI_EVERY`, `HH_REPLAY_PACE` (vacío; `vi`/`1`), `HH_REPLAY_MODE` (`vi`),
`HH_DUMP_CNT30`, `HH_DUMP_SAMPLE`, `HH_M24LOG`, `HH_SP_SHARED`, `HH_S0FIX`, `HH_DIAG` (logs opt-in).
**Fase B**: `HH_TRANS_CACHE` (def 1), `HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.
Instrumentación siempre activa: `hh_tick.log`, `hh_slow.log`, `hh_state.log`, `hh_audio.log`.

## Estado de repos/branches

- **Main repo**: `main` = `origin/main`, con el historial reescrito (limpieza de la mención a ROMs) y
  pusheado. `backup-orig` conserva el historial anterior (borrar tras confirmar).
- **Runtime fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime`, repo aparte): `hybrid-heaven` =
  `fork/hybrid-heaven` (`3b231b3`), pusheado. Windows compila con `port\build_windows.local.bat`.

## Documentación de esta sesión

- **`docs/README.md`** (visión/roadmap) · `notes/archive/2026-09-18-plan-maestro-legacy.md` (Plan
  Maestro histórico congelado).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B + fix de `get_function`).
- **`notes/2026-09-18-suavizado-fase1-y-cache-loader.md`** (resumen del día + plan).
- CaC/veneno: `notes/2026-09-17-cac-ownership-resuelto.md`,
  `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`.
