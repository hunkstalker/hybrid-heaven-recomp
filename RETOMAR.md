# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota de la sesión. **Detalle completo**: **empieza por
> `notes/2026-09-19-causa-raiz-cadencia-frames.md`** (causa raíz probable: cadencia de frames 1 vs 2
> VI/tick, y el camino de fix), y después
> `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` (verificación del harness),
> `notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md` (inventario completo),
> `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (§3/§5: `HH_VI_EVERY` y el fix de tick),
> `notes/2026-09-19-clasificacion-adelanto-fase-previa.md` y `notes/2026-09-19-bat-stall-check.md`.
> Última sesión: **2026-09-19 (noche-3)**. Sesión de reanudación; continuar en una nueva.

## Aviso importante (leer antes de nada)

La sesión anterior (`crisp-circuit`, #18) **se colgó en bucle** al final. Su tramo 17:03–18:00 no
quedó documentado y su último razonamiento es **contradictorio**. La verificación independiente
(`notes/2026-09-19-verificacion-cadencia-y-harness-replay.md`) confirma una cadena causal dentro
del port, pero **cuestiona la comparación port↔emu**: el emulador consume el replay ~2× más rápido
que el port, así que sus hitos (p. ej. #12 en `vi 1535`) **no son una referencia estable**.

## Estado en pocas líneas (síntesis corregida)

- **El CaC no entra**: el replay reproduce el freeze clásico (veneno) y, con `HH_NO_B280`, un
  **softlock**; en el CaC el port toma una rama que el emulador **nunca** toma.
- **Confirmado (verificado 2026-09-19 noche-3)**:
  - El port ejecuta el frame `FUN_80001454` a **~58/s · 1,03 VI/frame**; el emulador a **~30/s ·
    2,0 VI/frame**. El bucle `FUN_800011b0` espera en la cola **`0x8005C288`** y decide con
    `[0x80037748]`: `0` → `FUN_80001454` (frame); `!=0` → `FUN_80001BB0` (no-op).
  - El port **nunca** pone `[0x80037748]` a 1 (sin `[NOOP]`), así que hace frame cada VI.
  - El port consume el replay a la tasa de la grabación (**~0,5 muestras/VI**); el emulador
    **~1,8-2× más rápido** (~0,9-1,0/VI). Ambos harnesses son **poll-indexed**.
  - **Objeto de transición `0x801D0474`**: port `vi 218`; con **`HH_VI_EVERY=2` → `vi 328`**; emu
    `vi 347`. ⇒ La **cadencia de frames** explica el adelanto del front-end; `HH_VI_EVERY=2` lo
    corrige.
- **En cuestión (no fiable tal cual)**: el "port ~20 s (~1200 VI) adelantado" y el "emu no toma la
  rama M10/M12" se midieron con el harness del emulador, que consume el replay ~2× rápido y es muy
  inestable al padding: #12 pasa de `vi 1535` (original) a `vi 2959` (`cac_pad163`) a no llegar
  (`cac_dup` stride 2); y con input vis-fiel (1/VI) el emulador **ni llega a #12**. La divergencia
  real del front-end es la **cadencia de frames**, no un misterio de 20 s.
- **Cadena causal dentro del port (sí en pie)**: en el CaC el port llama al **instalador M10/M12 del
  disable** (`m188=0x8024C934`, callback `802425F4`) → freeze/softlock; enmascarar el START
  (`HH_MASK_START=400:700`) lo evita (`objCB=801CB71C`, `m188=0`). El cambio de escena prematuro
  (A) **causa** la rama del CaC (B).
- **Descartado como causa** (probado): reloj (`HH_DET_CLOCK`, `quant`, `quant+bias`), deslizamiento
  del limiter, fase del replay (`HH_REPLAY_PACE=vi`), cache de assets (`HH_TRANS_CACHE=0`), y los
  parches `HH_NO_DISABLE`/`HH_NO_B280` (solo mueven el síntoma).

## TU TAREA AHORA — PLAN ÚNICO (no proponer variantes hasta cerrarlo)

**Objetivo**: que el port deje de **adelantarse en el front-end** (el objeto de transición nace en
`vi 218` vs emu `347`) y que el CaC entre al combate por el mismo camino, sin freeze ni softlock.

**Causa raíz probable (verificada 2026-09-19 noche-3b, `notes/2026-09-19-causa-raiz-cadencia-frames.md`)**:
el port ejecuta el frame `FUN_80001454` a **1,03 VI/frame** y el emulador a **2,0**. El bucle
`FUN_800011b0` decide con `[0x80037748]`: el port **nunca lo pone a 1** (no toma la rama no-op), así
que hace frame cada VI. `HH_VI_EVERY=2` (entrega del evento VI cada 2 VI) **corrige la cadencia** y
mueve el objeto de `vi 218` a **`vi 328`** (≈ emu `347`). El "port ~20 s adelantado" era un artefacto
compuesto (el emulador consume el replay ~2× rápido y es inestable: #12 = `vi 1535` → `2959` → no llega).

**Pasos restantes:**
1. **Rama no-op: causa localizada** (nota §5/§6). El tipo está en `[0x8005C4B0]` y **siempre es 1**
   (nunca 3); lo publica el productor (`FUN_8001fba8`, tid 19) en la cola `0x8005C288`, que consume
   el bucle principal (`FUN_800011b0`, tid 5). La raíz está en la **entrega del evento VI**:
   `ultramodern/src/events.cpp:364-392` lo entrega **cada VI**; el original entrega 60 VI/s y el
   juego marca tick cada 2 VI.
2. **Fix correcto** (no `HH_VI_EVERY` global): auditar la ruta ROM `osCreateViManager`/`viMgrMain` →
   `retrace_count` y por qué en el port se satisface cada VI; tocar la entrega/contabilidad del
   retrace en `events.cpp` (`load_vi_regs`/`update_vi`) para que el juego marque **2 VI/tick** con
   fase estable (slips a 3 VI si el trabajo no cabe), como
   `notes/2026-09-17-replay-mode-vi-vis-negativo.md` §5.2.
3. **Reproducir el CaC con `HH_REPLAY_MODE=vi`** (no solo `poll`) para validar el replay sin depender
   de la elección poll/vis.
4. **Validar**: objeto `0x801D0474` en su `vi` (~347); loader #12 (`005FBEC6`) en su `vi`; `CHAIN` sin
   completar antes; CaC con `objCB=801CB71C`/`m188=0`; **entra al combate**; y sin softlock en vivo.

**Criterio de cierre**: sin `HH_NO_B280`/`HH_NO_DISABLE` y sin `HH_VI_EVERY`, el port entra al combate
por el **mismo camino** que el emulador.

**Advertencia de método**: el emulador **no** es una referencia válida con este replay (consumo
poll-indexed ~2× y sensibilidad extrema al padding). Para comparar, o harness vis-fiel real, o el
`state.log` original del mantenedor (nota 09-17), o el propio replay del port en modo `vi`.

## Datos de partida (fijos)

- **Replay completo** (inicio→CaC; válido para emu, sin save):
  `work/debug/replays/cac_full_20260918_210956.txt` (9815 muestras; copia de
  `port/.../logs_pacing_20260918_210956/cac_rec.txt`). **No re-grabar** salvo cambio del port.
- **Replays re-muestreados de la sesión anterior** (para diagnóstico del harness):
  `work/debug/replays/cac_dup_20260919.txt` (stride 2), `cac_pad163_20260919.txt` (1,63×) y
  `cac_vi1_20260919.txt` (1 muestra/VI, vis-fiel; el emulador se cuelga con él antes de #12).
- **Replay save→softlock** (solo port; NO válido para emu):
  `work/debug/replays/cac_save_nob280_20260919_112932.txt` (4457). Save del port (formato propio):
  `work/debug/replays/hh.us.bin.pak.bak`.
- **Evidencia clave** (todo en `work/debug/`):
  - `m24/tl_port.log` (M24: ADVANCE/EVQCHECK/P89478/CHAIN), `m24/pacevi_tl.log`, `m24/loader_clock.log`,
    `m24/loader_nocache.log`, `m24/epoch_port.log`, `m24/mask_start.log`, `m24/mask_full.log`.
  - `loader_port.log` (cargas con vi/s), `emu_epoch_run.log` (HB_TRACE_EXEC=0x801C0A30),
    `emu_gate_run.log` (HB_TRACE_EXEC=0x8021B240,0x80126A0C).
  - `m24/emu_ld_ref.log` (hitos emu), `m24/emu_dup*.log`, `m24/emu_pad163.log` (sensibilidad al padding).
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
  (`[STATE] trans/mq`, `HH_LDTRACE`, `HH_EPOCHTRACE`, `HH_FRAMERATE`) y `HH_STATE_SECS` bajo.

## Herramientas/hooks añadidos (opt-in; no afectan al juego normal)

- **Runtime** (`lib/N64ModernRuntime/librecomp/src/overlays.cpp`, **sin commitear**):
  - `HH_M7GATE` → traza puerta `M7_FUN_80126CC0` (filtra `a1==0x80127014`): `[M7GATE]`.
  - `HH_GATE_A` → traza puerta `M7_FUN_80126A0C` (disable): `[GATE_A]`.
  - `HH_EPOCHTRACE` → traza `M24_FUN_801c0a30` (epoch): `[EPOCH]`.
  - `HH_LDTRACE` (o `HH_TBLTRACE`) → loader `0x80003824` con `vi/gframe/s/ra`: `[LD384]`.
  - `HH_FRAMERATE` (nuevo, noche-3) → `[FRM]` (cadena de `FUN_80001454` + polls) y `[NOOP]`.
  - `HH_NO_B280` (workaround: ignora publicar `0x8021B280`; **no es fix**).
  - `HH_DET_CLOCK=quant` (+ `HH_DET_CLOCK_BIAS`) en `ultramodern/src/timer.cpp`.
- **Runtime** (`ultramodern/src/events.cpp:371`): `HH_VI_EVERY=N` (entrega el evento VI al guest cada
  N VI; `N=2` deja el frame a 2,0 VI/frame). **Ya en el fork.**
- **Port** (`src/main/main.cpp`): en `hh_state.log`, líneas `[STATE] trans` (42D0/7730/38/48/50/g2/cnt30/
  objCB/a8/q4F0/q268/m188/m181), `[STATE] mq` (colas) y **anillos por hilo**.
- **Port** (`src/game/input.cpp`): `HH_MASK_START=lo:hi` (enmascara el bit START 0x1000 en una ventana
  de VI; **diagnóstico, no fix**). `HH_REPLAY_MODE=poll` (1 muestra/poll) o `vi` (última con
  `vis<=VI`).
- **Bats**: `port/run_cac_tick2.bat` (**doble clic**, sin flags: lanza en vivo con `HH_VI_EVERY=2`
  para validar el tick a 2 VI), `port/run_stall_check.bat [det] [nob280]`,
  `port/run_stall_check_nob280.bat`, `port/run_cac_nob280.bat` (replay + `HH_NO_B280=1`),
  `port/run_cac_record_nob280.bat`, `port/stall_summary.ps1`.
- **Tool**: `tools/analysis/ring_syms.py` (simboliza anillos de `hh_hang.log`/`hh_slice.log`).

## Cómo reproducir las medidas clave (headless)

- Build: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run base: `cd port/HybridHeavenRecomp/build_dbg && DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 HH_NO_B280=1 HH_REPLAY=work/debug/replays/cac_full_20260918_210956.txt HH_REPLAY_MODE=poll ./"Hybrid Heaven Recomp"`
- Cadencia de frames/polls (noche-3): añadir `HH_FRAMERATE=1` (→ `[FRM]`).
- Epoch port: añadir `HH_EPOCHTRACE=1` (→ `[EPOCH]`).
- Loader: añadir `HH_LDTRACE=1` (→ `[LD384 ... vi=.. gframe=.. s=..]`).
- M24: `HH_TBLTRACE=1 HH_LSTTRACE=1` (→ `[TL] ADVANCE/EVQCHECK/P89478/CHAIN`).
- Emu epoch: `HH_KEYS_REPLAY=work/debug/replays/cac_full_20260918_210956.txt HB_TRACE_EXEC=0x801C0A30 tools/analysis/emu_ref.sh work/debug/emu_epoch 40 9999`
- Emu instalador/puerta: igual con `HB_TRACE_EXEC=0x8021B240,0x80126A0C` (el emu **no** ejecuta el instalador).

## Knobs del runtime (recordatorio)

`HH_REPLAY_MODE` (`poll`|`vi`), `HH_VI_EVERY`, `HH_FRAMERATE`, `HH_REPLAY_PACE` (no usar `vi`),
`HH_REPLAY_CLOCK`, `HH_DET_CLOCK`(+`_BIAS`, `quant`), `HH_MASK_START`, `HH_EPOCHTRACE`, `HH_LDTRACE`,
`HH_M7GATE`, `HH_GATE_A`, `HH_NO_B280`, `HH_NO_DISABLE`, `HH_B280TRACE`, `HH_WATCH_ADDR`/`HH_WATCH_VENOM`,
`HH_MQLOG_ALL`/`HH_MQLOG_MQ`, `HH_WAITLOG`/`HH_WAITLOG_MQ`, `HH_DUMP_VI`/`HH_DUMP_SAMPLE`, `HH_STATE_SECS`,
`HH_TRANS_CACHE`, `HH_TRANS_NATIVE`, `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.

## Estado de repos/branches (listo para push)

Estado verificado 2026-09-19 noche-3 (tras commitear la documentación de esta sesión):

- **Main repo** (`https://github.com/hunkstalker/hybrid-heaven-recomp.git`, `origin`, rama `main`):
  `origin/main` ya tiene `9163f11` y `e4fac49`. **Pendiente de push: 1 commit** (la documentación de
  esta sesión). Push: `cd /app/hybrid-heaven-recomp && git push origin main`.
- **N64Recomp fork** (`https://github.com/hunkstalker/N64Recomp.git`, remote `origin`, rama
  `hybrid-heaven`): commit `cab94d9` **ya pusheado** (`origin/hybrid-heaven == HEAD`). Sin cambios.
- **Runtime fork** (`https://github.com/hunkstalker/N64ModernRuntime.git`, remote **`fork`**, rama
  `hybrid-heaven`): commit `15f920d` **ya pusheado** (`fork/hybrid-heaven == HEAD`); commit-wise no
  falta push. **Solo queda un diff de instrumentación sin commitear** en
  `librecomp/src/overlays.cpp` (`HH_FRAMERATE`/`gframe`), **fuera del commit por decisión de esta
  sesión** (no había tarea validada). Decidir si se commitea más adelante:
  `cd port/HybridHeavenRecomp/lib/N64ModernRuntime && git push fork hybrid-heaven`.
- **`port/runtime.lock`**: `NMR_COMMIT` apunta a
  **`15f920d5e29ecb59d811988ea69e78ee09547d89`** (ya pusheado) y `N64RECOMP_COMMIT` a
  **`cab94d912ff858d6574974cead7dbbcca09e282f`** (ya pusheado). El pin es válido en un clone limpio.
- **Orden de push** (ver `AGENTS.md`): N64Recomp → N64ModernRuntime → main.
- En Windows, rutas: main `E:\dev\docker\hybrid-heaven-pc-port\hybrid-heaven-recomp`; fork
  `...\port\HybridHeavenRecomp\lib\N64ModernRuntime`. Alternativa sin push: `port\build_windows.local.bat`
  (compila el árbol local tal cual).

## Documentación de la sesión

- **`notes/2026-09-19-causa-raiz-cadencia-frames.md`** — **empezar aquí**: causa raíz probable
  (cadencia de frames 1 vs 2 VI/tick), el flag `0x80037748` que nunca cambia y el camino de fix.
- `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` — verificación independiente
  (cadencia, tasa de poll port↔emu, sensibilidad al padding, cadena causal).
- `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (§3/§5) — `HH_VI_EVERY=2` como candidato a fix y
  la cuantización de tick del original.
- `notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md` — inventario de lo probado y
  corrección de `[0x801BBD56]`.
- `notes/2026-09-19-bat-stall-check.md` — medida de stalls, M7/M12, driver M24, epoch y test A→B.
- `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` — cadena del veneno, gate, `HH_NO_DISABLE`.
- Contexto: `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` (§2b/§4/§6),
  `notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`,
  `notes/2026-09-17-cac-timeline-modulo24-periodo.md` (§3 epoch, §5 opciones de fix de fase).
- Índice: `python3 tools/analysis/docs_index.py` (`--check` valida).
