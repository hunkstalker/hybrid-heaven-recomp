# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota de la sesión. **Detalle completo de esta sesión**:
> `notes/2026-09-19-bat-stall-check.md` (y `notes/2026-09-19-veneno-capturado-bug-signo-extension.md`).
> Última sesión: **2026-09-19**. Sesión cerrada; continuar en una nueva.

## Estado en pocas líneas (síntesis corregida)

- **El CaC no entra**: el replay reproduce el freeze clásico (veneno) y, con `HH_NO_B280`, un **softlock**;
  en el CaC el port toma una rama que el emulador **nunca** toma.
- **El input grabado es CORRECTO**: el replay aplica cada muestra en su `vis` (p. ej. el START de
  `vis 508-517` se aplica en `vi 511`). El problema **no** es tu grabación.
- **El port va ~20 s (≈1200 VI) por delante** en la fase pre-transición:
  - Inicio del timeline M24 (`M24_FUN_801c0a30`, fija la epoch): **port vi 421** vs **emu vi 1625**.
  - Carga #12 (`005FBEC6→801BF1A0`): **port vi 417** vs **emu vi 1535**.
- Por eso el START de menú cae **dentro de la transición** del port → cadena `CHK_012C` → **cambio de
  escena prematuro** (port vi ~549 vs emu ~3660) → en el CaC el port llama al **instalador M10/M12 del
  disable** (`m188=0x8024C934`, callback `802425F4`) → freeze/softlock.
- **Test de causalidad (decisivo)**: enmascarar el START en `vi 400-700` (`HH_MASK_START`) hace que el
  port llegue al CaC en **`objCB=801CB71C`, `m188=0`** (como el emulador), **sin rama del instalador ni
  crash**. ⇒ El **cambio de escena prematuro (A) causa la rama del CaC (B)**; comparten raíz = **fase/tiempo**.
- **El emulador NUNCA ejecuta el instalador `M10_FUN_8021b240`** (0 veces) con el mismo replay; la puerta
  `M7_FUN_80126A0C` sí corre 18 veces. ⇒ **No es un input de puerta**: es divergencia de **camino/estado
  (timing)** aguas arriba.
- **Descartado como causa** (probado): reloj (`HH_DET_CLOCK`, `quant`, `quant+bias`), deslizamiento del
  limiter (3 % de ticks de 3 VI; arreglarlo **no** quita el softlock), fase del replay
  (`HH_REPLAY_PACE=vi`), cache de assets (`HH_TRANS_CACHE=0`), y los parches `HH_NO_DISABLE`/`HH_NO_B280`
  (solo mueven el síntoma).

## TU TAREA AHORA — PLAN ÚNICO (no proponer variantes hasta cerrarlo)

**Objetivo**: que **el port no se adelante** en la fase pre-transición, para que la transición no sea
prematura y el CaC no tome la rama M10/M12 (**sin freeze ni softlock**).

**Pasos:**
1. **Localizar el primer punto** donde el port se adelanta en la fase **boot → inicio del timeline**
   (port `vi 0→421`; emu `vi 0→1625`). Trazar port↔emu las etapas (intro/logos, menús, cargas) **y el
   consumo muestra↔tick** del replay.
2. **Decidir la naturaleza** de ese primer salto:
   - Si es **cadencia del replay** (`GetKeys` original ~1,47/tick = 44,3/s frente a 30 ticks/s; port
     1/tick) → fix del **mapeo muestra↔tick**.
   - Si es **timing del motor** → **modelo determinista A2** (VI y `osGetTime` en lockstep), ya acotado
     a ese punto.
3. **Validar**:
   - Epoch M24 en `vi ~1625` y carga #12 en `vi ~1535` (como el emu); `CHAIN` sin completar antes de tiempo.
   - CaC con `objCB=801CB71C`/`m188=0` (sin rama M10/M12); **entra al combate**.
   - **En vivo** (save avanzado): comprobar si el fix también resuelve el softlock de esa ruta.
     **Pregunta abierta**: la ruta con save no incluye la fase temprana; su disparo puede ser el timing
     del CaC (misma familia de tiempo), a confirmar.

**Criterio de cierre**: sin `HH_NO_B280`/`HH_NO_DISABLE`, el port entra al combate por el **mismo camino**
que el emulador.

## Datos de partida (fijos)

- **Replay completo** (inicio→CaC; válido para emu, sin save):
  `work/debug/replays/cac_full_20260918_210956.txt` (9815 muestras; copia de
  `port/.../logs_pacing_20260918_210956/cac_rec.txt`). **No re-grabar** salvo cambio del port.
- **Replay save→softlock** (solo port; NO válido para emu):
  `work/debug/replays/cac_save_nob280_20260919_112932.txt` (4457). Save del port (formato propio):
  `work/debug/replays/hh.us.bin.pak.bak`.
- **Evidencia clave** (todo en `work/debug/`):
  - `m24/tl_port.log` (M24: ADVANCE/EVQCHECK/P89478/CHAIN), `m24/pacevi_tl.log`, `m24/loader_clock.log`,
    `m24/loader_nocache.log`, `m24/epoch_port.log`, `m24/mask_start.log`, `m24/mask_full.log`.
  - `loader_port.log` (cargas con vi/s), `emu_epoch_run.log` (HB_TRACE_EXEC=0x801C0A30),
    `emu_gate_run.log` (HB_TRACE_EXEC=0x8021B240,0x80126A0C).
  - `nob280/run3`/`run5`/`full_state/` (softlock: `objCB=80242E90`, `a8=0`), `nob280/m7gate/`.
  - `cac/diff_vi_20260918/` (dumps port+emu 20200-20900), `build_dbg/work/debug/port_vi*.bin`.

## Hechos clave del CaC/transición (no repetir)

- **Veneno**: `FUN_800058dc` escribe en `0x8024AB14`; cadena
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → M10_FUN_8022c7ac → M55_FUN_80379410 → FUN_800058dc`;
  instalador `M10_FUN_8021b240` (publica `0x8021B280`) **solo si** `M7_FUN_80126A0C(obj,0x39,1) != 0`.
  Emu: instalador **0 ejecuciones**; callback sano `801CB71C`.
- **M24**: driver `M24_FUN_801bfaa0`; avance de periodo `M24_FUN_801bffac` (**ADVANCE=0 en port**);
  waits `FUN_801C0B8C` (**EVQCHECK=0**); **epoch** = `M24_FUN_801c0a30` ← `M24_FUN_801C0C08`
  (`[0x801D8D80:84]`).
- **Cambio de escena**: cadena `M24_FUN_801bf398 → M24_FUN_801c0c68`(cnt≥60)` → M24_FUN_801c012c →
  M24_FUN_801c0190`, disparada por el flanco START (`[0x80089478] & 0x1000`).
- **Diferencial VI 20200-20900** (con dumps): port y emu **idénticos** (objeto CaC, callback
  `0x80135320`, M24, directorio) salvo colas `0x8005C4F0`/`0x8005C268` (port 0 vs emu `0x80049930`).
  `0x8005C268` = cola del helper de lectura ROM síncrona; `0x8005C4F0` = cola tid5/tid17.
- **Ojo con la instrumentación**: los dumps grandes (`HH_DUMP_VI`) y los logs por línea
  (`HH_MQLOG_ALL`/`HH_WAITLOG`) **enmascaran o frenan** la divergencia; usar trazas ligeras
  (`[STATE] trans/mq`, `HH_LDTRACE`, `HH_EPOCHTRACE`) y `HH_STATE_SECS` bajo.

## Herramientas/hooks añadidos esta sesión (opt-in; no afectan al juego normal)

- **Runtime** (`lib/N64ModernRuntime/librecomp/src/overlays.cpp`):
  - `HH_M7GATE` → traza puerta `M7_FUN_80126CC0` (filtra `a1==0x80127014`): `[M7GATE]`.
  - `HH_GATE_A` → traza puerta `M7_FUN_80126A0C` (disble): `[GATE_A]`.
  - `HH_EPOCHTRACE` → traza `M24_FUN_801c0a30` (epoch): `[EPOCH]`.
  - `HH_LDTRACE` (o `HH_TBLTRACE`) → loader `0x80003824` con `vi/s/ra`: `[LD384]`.
  - `HH_NO_B280` (workaround: ignora publicar `0x8021B280`; **no es fix**).
  - `HH_DET_CLOCK=quant` (+ `HH_DET_CLOCK_BIAS`) en `ultramodern/src/timer.cpp`.
- **Port** (`src/main/main.cpp`): en `hh_state.log`, líneas `[STATE] trans` (42D0/7730/38/48/50/g2/cnt30/
  objCB/a8/q4F0/q268/m188/m181), `[STATE] mq` (colas) y **anillos por hilo**.
- **Port** (`src/game/input.cpp`): `HH_MASK_START=lo:hi` (enmascara el bit START 0x1000 en una ventana de
  VI; **diagnóstico**, no fix).
- **Bats**: `port/run_stall_check.bat [det] [nob280]`, `port/run_stall_check_nob280.bat`,
  `port/run_cac_nob280.bat` (replay + `HH_NO_B280=1`), `port/run_cac_record_nob280.bat`,
  `port/stall_summary.ps1`.
- **Tool**: `tools/analysis/ring_syms.py` (simboliza anillos de `hh_hang.log`/`hh_slice.log`).

## Cómo reproducir las medidas clave (headless)

- Build: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run base: `cd port/HybridHeavenRecomp/build_dbg && DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 HH_NO_B280=1 HH_REPLAY=work/debug/replays/cac_full_20260918_210956.txt HH_REPLAY_MODE=poll ./"Hybrid Heaven Recomp"`
- Epoch port: añadir `HH_EPOCHTRACE=1` (→ `[EPOCH]`).
- Loader: añadir `HH_LDTRACE=1` (→ `[LD384 ... vi=.. s=..]`).
- M24: `HH_TBLTRACE=1 HH_LSTTRACE=1` (→ `[TL] ADVANCE/EVQCHECK/P89478/CHAIN`).
- Emu epoch: `HH_KEYS_REPLAY=work/debug/replays/cac_full_20260918_210956.txt HB_TRACE_EXEC=0x801C0A30 tools/analysis/emu_ref.sh work/debug/emu_epoch 40 9999`
- Emu instalador/puerta: igual con `HB_TRACE_EXEC=0x8021B240,0x80126A0C` (el emu **no** ejecuta el instalador).

## Knobs del runtime (recordatorio)

`HH_REPLAY_MODE` (`poll`), `HH_REPLAY_PACE` (no usar `vi`), `HH_REPLAY_CLOCK`, `HH_DET_CLOCK`(+`_BIAS`,
`quant`), `HH_MASK_START`, `HH_EPOCHTRACE`, `HH_LDTRACE`, `HH_M7GATE`, `HH_GATE_A`, `HH_NO_B280`,
`HH_NO_DISABLE`, `HH_B280TRACE`, `HH_WATCH_ADDR`/`HH_WATCH_VENOM`, `HH_MQLOG_ALL`/`HH_MQLOG_MQ`,
`HH_WAITLOG`/`HH_WAITLOG_MQ`, `HH_DUMP_VI`/`HH_DUMP_SAMPLE`, `HH_STATE_SECS`, `HH_TRANS_CACHE`,
`HH_TRANS_NATIVE`, `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.

## Estado de repos/branches (PENDIENTE DE PUSH)

Commits **hechos** esta sesión; **falta pushear** (no se ha hecho por indicación).

- **Main repo** (`https://github.com/hunkstalker/hybrid-heaven-recomp.git`, `origin`, rama `main`):
  commit **`9163f11`** `diag(cac): herramienta de stalls, instrumentacion de estado y reanalisis`.
  Push: `cd /app/hybrid-heaven-recomp && git push origin main`.
- **Runtime fork** (`https://github.com/hunkstalker/N64ModernRuntime.git`, remote **`fork`**, rama
  `hybrid-heaven`): commit **`15f920d`** `diag(cac): hooks de diagnostico M7/epoch/loader ...`.
  Push: `cd port/HybridHeavenRecomp/lib/N64ModernRuntime && git push fork hybrid-heaven`
  (si el remoto rechaza por historial reescrito: `git push fork hybrid-heaven --force-with-lease`).
- **`port/runtime.lock`**: `NMR_COMMIT` ya apunta a **`15f920d5e29ecb59d811988ea69e78ee09547d89`**
  (válido **tras** el push del fork). Incluido en el commit `9163f11`. El `N64RECOMP_COMMIT` no cambió;
  recordar que **ambos** forks deben estar pusheados para que el pin funcione en un clone limpio.
- En Windows, rutas: main `E:\dev\docker\hybrid-heaven-pc-port\hybrid-heaven-recomp`; fork
  `...\port\HybridHeavenRecomp\lib\N64ModernRuntime`. Alternativa sin push: `port\build_windows.local.bat`
  (compila el árbol local tal cual).

## Documentación de la sesión

- **`notes/2026-09-19-bat-stall-check.md`** — principal: medida de stalls, M7/M12, driver M24, epoch,
  **test de causalidad A→B** y síntesis. Empieza por aquí.
- `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` — cadena del veneno, gate, `HH_NO_DISABLE`.
- Contexto: `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` (§2b/§4/§6),
  `notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`,
  `notes/2026-09-17-cac-timeline-modulo24-periodo.md` (§3 epoch, §5 opciones de fix de fase).
- Índice: `python3 tools/analysis/docs_index.py` (`--check` valida).
