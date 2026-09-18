# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota más reciente en `notes/`. Actualizar o borrar al cambiar la tarea.
> Última sesión: **2026-09-18**.

## Estado en 5 líneas

- **El port corre y se juega en Windows** (menús → gameplay → CaC, mando Xbox, audio 43200 Hz). Cadencia
  **30 ticks/s** estables, sin stalls.
- **Rendimiento resuelto**: `get_function` hacía 4-5 `getenv()` por llamada recompilada (millones/tick);
  cachear los flags eliminó los stalls de 1-4 s. Fase B (cache de assets + loader LZKN64 nativo) hecha.
- **Bloqueante actual: entrar en combate CaC** → el juego cuelga (objeto `0x8024A990` con callback
  `+0x1C=0xFFFF84CD`, colas `[BADMQ]`, `tid5` parado en `osRecvMesg` de `0x8005C288`).
- **El replay NO reproduce el freeze** (ni Windows ni headless). Se descartaron `HH_VI_EVERY=2` (no lo
  arregla en vivo) y `HH_REPLAY_PACE=vi` (tirones). Se hizo **determinista el reloj de replay** (por VI)
  pero el freeze sigue sin reproducirse → parece **sensible al timing/jitter del entorno**.
- **Documentación consolidada**: `docs/README.md` es ahora la **visión/roadmap**; el Plan Maestro viejo
  quedó archivado; `TODO`/`PROYECTO` recortados. Visión a largo plazo: cobertura nativa progresiva.

## TU TAREA AHORA (pasos exactos)

**Objetivo: conseguir un replay que reproduzca el CaC** (para poder diagnosticarlo). El mantenedor cree
que es posible **jugando limpio, esquivando enemigos** (la divergencia no es RNG de IA, es timing).

1. **[MANTENEDOR] Grabar una partida nueva y limpia** con el build actual:
   ```
   port\build_windows.local.bat     REM el .exe debe incluir el fix de get_function y el reloj determinista
   port\run_cac_record.bat          REM graba el input en logs_pacing_<fecha>\cac_rec.txt
   ```
   Jugar hasta el CaC **esquivando enemigos**; cerrar la ventana al llegar/al colgarse.
   - Nota: hubo un intento (`logs_pacing_20260918_210956`) que quedó **vacío** (no se volcó `cac_rec.txt`);
     repetir asegurándose de que la carpeta de logs acaba con `cac_rec.txt`.
2. **[DEV/ambos] Reproducir la grabación** y comparar con la original:
   ```
   port\run_cac_replay.bat          REM HH_REPLAY_MODE=vi (auto-corrige slips)
   ```
   - **Éxito** = el replay llega al CaC y se cuelga en el mismo punto/firma que la grabación.
   - Si **diverge** (2ª puerta / contra una pared): pasar al **Plan B**.
3. **[DEV] Plan B — atacar el cuelgue en el vivo** (en paralelo o si el replay no reproduce):
   - Instrumentar el vivo para cazar quién escribe `FFFF84CD`:
     `HH_WATCH_ADDR=0x8024A9AC` (+`HH_MQLOG_ALL`, y el watchpoint de escritura) en una pasada de juego.
   - Cadena del setter ya documentada en `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`:
     `M10_FUN_8021b280 → M10_FUN_8022c7ac (gate 0x8017DD92) → M55_FUN_80379410 → FUN_800058dc(a1=0xFFFF84CD)`.

> **Detalle completo de la ronda**: `notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md` (incluye el
> fix del reloj, el test de determinismo y la evidencia).

## Contexto del CaC (lo ya sabido; no repetir)

- Reproducido en Linux con replay (PFS carga; `mode=0004`; objeto envenenado). **No es rendimiento.**
- El cuelgue es **intermitente** en headless (1 de 3) y ~100% en vivo → carrera sensible al timing.
- La **ráfaga #22** del módulo 24 **sí** se ejecuta; la teoría "burst saltado" quedó refutada.
- Primera divergencia de flujo port↔emulador (con replay BizHawk): **carga #49 (~VI 20500)**.
- Dumps del cuelgue real: `logs_pacing_20260918_155825/hh_hang_rdram_*`.
- Histórico: `notes/2026-09-17-cac-ownership-resuelto.md`, `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`, `notes/2026-09-17-replay-mode-vi-vis-negativo.md`.

## Otras tareas vivas (TODO.md "Ahora")

- **Audio**: sincronizar la tasa (feedback del error de cola SDL en `osAiGetLength`).
- **Menú in-game (ADR 0008)**: spike go/no-go antes de comprometerlo (nota 09-18 §6).
- **Definir ADR 0009** (visión de cobertura nativa/clean-room) cuando se adopte.
- **Teardown SEGV** al cerrar en Windows; **mando** (botón de menú CaC → X, **bloqueado por el CaC**).

## Comandos útiles

- Build Linux debug: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run headless: `DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 ./port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"`
- Replay headless: `HH_REPLAY=<cac_rec.txt> HH_REPLAY_MODE=vi HH_REPLAY_CLOCK=1` (reloj determinista por VI)
- Dumps: `HH_DUMP_SAMPLE=<n>` (muestra de replay), `HH_DUMP_VI=<vis,..>` (VI), `HH_M24LOG=1` (timeline M24)
- Lanzadores Windows: `run_cac_record.bat`, `run_cac_replay.bat`, `run_cac_tick2.bat`, `run_cac_profile.bat`.
- Emulador de referencia: `tools/analysis/emu_ref.sh <prefix> <secs> [dumps]` (lento en este contenedor).
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## Knobs del runtime

`HH_AI_FIFO` (def fiel), `HH_AI_MAX_MS`, `HH_TIMESCALE`, `HH_VI_EVERY`, `HH_REPLAY_MODE` (`vi`),
`HH_REPLAY_PACE` (vacío; **no** usar `vi`: tirones), `HH_REPLAY_CLOCK` (reloj de replay; ahora
determinista por VI), `HH_S0FIX`, `HH_DIAG` (logs opt-in), `HH_WATCH_ADDR`/`HH_MQLOG_ALL` (watchpoints).
**Fase B**: `HH_TRANS_CACHE` (def 1), `HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.

## Estado de repos/branches (todo pusheado y en sync)

- **Main repo**: `main` = `origin/main` (`2c52b42`). Historial reescrito (limpieza de la mención a ROMs).
  `backup-orig` conserva el historial anterior (borrar con `git branch -D backup-orig` cuando se quiera).
- **Runtime fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime`, repo aparte): `hybrid-heaven` =
  `fork/hybrid-heaven` (`a3a434f`). `port/runtime.lock` apunta a `a3a434f`.
- Windows compila con `port\build_windows.local.bat` (árbol local, no versionado).

## Documentación de esta sesión

- **`docs/README.md`** (visión/roadmap) · `notes/archive/2026-09-18-plan-maestro-legacy.md` (congelado).
- **`notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`** (ronda CaC/replay; reloj determinista).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B + fix de `get_function`).
- **`notes/2026-09-18-suavizado-fase1-y-cache-loader.md`** (resumen del día + plan).
