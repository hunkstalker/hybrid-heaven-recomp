# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota de la sesión.
> **Detalle completo**: **empieza por `notes/2026-09-19-causa-raiz-cadencia-frames.md`** (recoge toda
> la investigación del CaC hasta §16, incluida la corrupción de la lista de suscriptores), y después
> `notes/2026-09-19-bat-stall-check.md`, `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` y
> `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`.
> Última sesión: **2026-09-20 (noche-4)**. Continuar en una sesión nueva.

---

## 0. EL PROBLEMA (qué buscamos)

**El port no entra en el combate CaC (cuerpo a cuerpo): se queda congelado (freeze) o softlock.** Es el
bloqueante principal del proyecto. El emulador (referencia real) **sí** pasa el CaC con el mismo input.
Objetivo: que el port entre al combate por el mismo camino, **sin freeze ni softlock**, sin parches
(`HH_NO_*`).

---

## 1. EVIDENCIA Y REPRODUCCIÓN

- **Replay completo** (inicio→CaC; grabado por el mantenedor, válido para emu):
  `work/debug/replays/cac_full_20260918_210956.txt` (9815 muestras). **No re-grabar** salvo cambio del port.
- **Replay save→softlock** (solo port): `work/debug/replays/cac_save_nob280_20260919_112932.txt` (4457);
  save del port: `work/debug/replays/hh.us.bin.pak.bak`.
- **Replays re-muestreados** (diagnóstico del harness): `cac_dup_20260919.txt` (stride 2),
  `cac_pad163_20260919.txt` (1,63×), `cac_vi1_20260919.txt` (1 muestra/VI).
- **Run headless base**:
  `cd port/HybridHeavenRecomp/build_dbg && DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 HH_NO_B280=1 HH_REPLAY=work/debug/replays/cac_full_20260918_210956.txt HH_REPLAY_MODE=poll ./"Hybrid Heaven Recomp"`
- **Emulador**: `tools/analysis/emu_ref.sh <prefix> <secs> 9999` con `HH_KEYS_REPLAY=<replay> HB_TRACE_EXEC=<addrs>`.
- **Windows (mantenedor)**: `port\build_windows.local.bat` para compilar; bats de doble clic (ver §7).

---

## 2. EVOLUCIÓN CRONOLÓGICA (cómo se ha llegado hasta aquí)

1. **2026-09-14/16**: primer choque — el port entra al frame del CaC, aparece el centinela
   `0xFFFF84CD`/`0x8021D8D0` (notas `2026-09-16-crash-combate-*`, `-guardado-capsula-pak-y-crash-cac-*`).
   Se añadieron fallthroughs y fixes de módulos (M9/M55) que resolvieron otros cuelgues (NPC, cinemáticas).
2. **2026-09-17**: la línea temporal del módulo 24 (periodo `g2`) debía pedir la ráfaga #22; el port hacía
   un **cambio de escena temprano** (`VI≈840`). Se creyó causa raíz "el replay aplica el input en la fase
   equivocada (START durante la transición)". Nota `2026-09-17-cac-timeline-modulo24-periodo.md` (§4/§4b).
   También: **AI FIFO no fiel** y pacing (`2026-09-17-replay-mode-vi-vis-negativo.md` §5b-§5h); el
   **freeze es intermitente** en headless (~1 de 2-3) y ~100 % en Windows.
3. **2026-09-18**: hito — `HH_REPLAY_MODE=poll` reproduce el CaC en port (Win+Linux) y el emulador lo pasa
   con el mismo input (`2026-09-18-hito-*`). Diferencial por VI en 20200-20900: **paridad** salvo colas
   `0x8005C4F0`/`0x8005C268` (`2026-09-18-diferencial-*`). El veneno = rama M10/M12; el emulador **nunca**
   ejecuta el instalador.
4. **2026-09-19**: se pensó que el port iba "~20 s adelantado" en la fase pre-transición, y luego que el
   adelanto nacía en el **front-end** (objeto `0x801D0474`). Verificado: el port ejecuta el frame
   `FUN_80001454` a **1,03 VI/frame** con `HH_VI_EVERY=2` a 2,0 (objeto `vi 218 → 328`, emu `347`).
   **Pero `HH_VI_EVERY=2` NO arregla el freeze en vivo** (`VI=20829`).
5. **2026-09-20 (esta tanda)**: descartado el front-end/cadencia como causa. **La causa inmediata es
   corrupción de memoria**: el CaC corrompe la **lista de suscriptores del event-dispatch** → mensajes a
   colas basura (`[BADMQ]`) → deadlock. El **disable es un síntoma**, no el bloqueo (hay softlock sin
   veneno y con `HH_NO_DISABLE`).

---

## 3. INVENTARIO EXHAUSTIVO DE COMPROBACIONES (NO REPETIR)

> Estado: ❌ descartado / ✔ confirmado / ⚠ aparcado. Fuente entre paréntesis.

### 3a. Reloj / tiempo / cadencia
| Prueba | Resultado | Fuente |
|---|---|---|
| `osGetTime` a tasa correcta | ✔ correcta (== reloj pared == VI) | `2026-09-17-cac-timeline…` §4 |
| `HH_DET_CLOCK` (`1`,`quant`,`quant+bias`,`HH_VI_CLOCK`) | ❌ no quita la carrera; `VT_CLOCK` da ~20 fps | `2026-09-19-veneno…` §5/§8 |
| Deslizamiento del limiter (3 % ticks de 3 VI) | ❌ no es la causa | `2026-09-19-bat-stall-check` §6b |
| `HH_VI_EVERY=2` (tick a 2 VI) | ❌ **no arregla el freeze en vivo** (VI 20829) | esta sesión; `run_cac_tick2.bat` |
| Cadencia de frames del port (1,03 vs 2,0 VI/frame) | ✔ real, pero **ortogonal al freeze** | `2026-09-19-causa-raiz…` §1-§7 |
| `HH_REPLAY_PACE=vi`/`wall`, `HH_REPLAY_CLOCK`, `mode=vi` | ❌ negativos o inestables | `2026-09-17-replay-mode-vi-vis-negativo` |
| Stalls frame↔VI (`guest_busy`~34 ms vs 33,3) | ⚠ reales pero no bloqueante actual | `2026-09-19-bat-stall-check`, `-veneno…` §8 |

### 3b. Input / replay
| Prueba | Resultado | Fuente |
|---|---|---|
| Mapeo muestra↔frame port↔emu | ❌ idéntico (descarta cadencia del replay) | `2026-09-19-clasificacion…` §1 |
| Cadencia del callback de espera `M7_FUN_80124C54` | ❌ idéntica (30/s) | ídem §2 |
| Replay input cero (`cac_zero`) | ✔ la fase temprana es input-dependiente | `2026-09-19-inventario…` §3a |
| `HH_MASK_START=400:700` | ✔ evita la rama del CaC (test causal A→B) | `2026-09-19-bat-stall-check` |
| Emulador con el replay (poll, stride 2, pad163, vi1) | ⚠ **no es referencia válida** (consume ~2× y es inestable) | `2026-09-19-verificacion…`, `causa-raiz…` §2 |
| Replay en vivo en Windows: pacing por `sleep_for` | ❌ work-bound, pierde 30/s | `2026-09-17-replay…` §5e/§5f |
| Replay con `poll` en Windows: deriva de input (ticks de 3 VI) | ⚠ por eso el replay no reproduce bien en vivo | `2026-09-17-replay…` §5f, §8b |

### 3c. Transición / front-end / M24
| Prueba | Resultado | Fuente |
|---|---|---|
| Byte `[0x801BBD56]` como causa | ❌ **síntoma**, no causa | `2026-09-19-inventario…` §2 |
| Objeto de transición `0x801D0474` (13 callbacks) | ✔ mismo orden; solo cambia el dwell | `2026-09-19-inventario…` §2 |
| M24 driver/ADVANCE/EVQCHECK/epoch | ⚠ ADVANCE=0/EVQCHECK=0 en port (síntomas) | `2026-09-17-cac-timeline…` §3 |
| Cache de assets (`HH_TRANS_CACHE=0`/`NATIVE=0`) | ❌ no es la causa | `loader_nocache.log` |
| Fallthroughs en la cadena M7/M10/M55 | ❌ **bien encadenados** (verificado en el árbol) | esta sesión, `causa-raiz…` §9 |
| Funciones de M10 stubbeadas/ausentes (14) | ❌ **no se llaman** en ninguna corrida | esta sesión, `causa-raiz…` §14 |

### 3d. Veneno / disable / mysql del CaC
| Prueba | Resultado | Fuente |
|---|---|---|
| Rama M10/M12 = freeze (veneno) | ✔ confirmada (cadena M55→`FUN_800058dc`) | `2026-09-19-veneno…` §2/§4 |
| Emulador ejecuta el instalador `M10_FUN_8021b240` | ✔ **0 veces** (nunca) | `2026-09-19-bat-stall-check` |
| `HH_NO_B280` (ignora publicar `0x8021B280`) | ❌ workaround, cambia freeze→softlock; **no es fix** | `2026-09-19-bat-stall-check` |
| `HH_NO_DISABLE` (ignora el centinela) | ❌ **en vivo sigue el cuelgue**; el disable es síntoma | `2026-09-19-veneno…` §6; esta sesión |
| Puerta `M7_FUN_80126A0C(obj,0x39,1)` | ✔ se llama 16 veces; #13 → `ret=1` con `42D0=0x2B88` | `causa-raiz…` §9 |
| Evento temporizado `0x39` (target `0x3000`) | ✔ el scheduler `FUN_80004bb0` lo despacha (emu no) | `causa-raiz…` §12 |
| Cadena `b1A8→b200→b240→b280` | ✔ confirmada en vivo (objeto `0x8024D690`/`0x8024C7CC`) | `causa-raiz…` §11 |

### 3e. Corrupción de memoria (CAUSA INMEDIATA ACTUAL)
| Prueba | Resultado | Fuente |
|---|---|---|
| `[BADMQ]` (osSendMesg a cola corrupta) | ✔ aparece **sin veneno** (headless) y con `HH_NO_DISABLE` | `causa-raiz…` §13 |
| Punteros de cola corruptos | ✔ son **floats de física** (`3F3851EC`, `40500000`…) | `causa-raiz…` §14 |
| Event-dispatch `FUN_80000A0C` (broadcast a suscriptores `{next,mq}` en `[obj+0x888]`) | ✔ identificado | `causa-raiz…` §15 |
| Nodo corrupto | ✔ **`0x8005BF14`** (→ cola `0x8005C288`) se pisa: `q→80063DF0`, `next→8008DA88`; la lista salta a nodos basura `0x8025xxxx` | `causa-raiz…` §16 |
| Todos los `[PUSH]` observados | ✔ `q` válido ⇒ el nodo se corrompe **después** de insertarse | `causa-raiz…` §16 |
| Watchpoint sobre el nodo `0x8005BF14` | ❌ **SEGV** (nodo en pila del hilo) | esta sesión |

---

## 4. ESTADO ACTUAL (dónde está el problema)

- **Causa inmediata**: en el CaC se corrompe la **lista de suscriptores del event-dispatch** del motor
  (`[obj+0x888]`, `obj=0x8005C4B0`). El juego hace **broadcast** del mensaje del frame (`0x8005C4B0`) a
  cada `mq` de la lista (`FUN_80000A0C`). El **nodo `0x8005BF14`** (que apuntaba a la cola del bucle
  principal `0x8005C288`) se pisa, y la lista pasa a nodos basura (`0x8005BF14`→`8008DA88`→`0x8025xxxx`).
  El port manda `osSendMesg` a esos punteros inválidos, los **descarta** (`[BADMQ]`, mitigación en
  `mesgqueue.cpp do_send`) → el suscriptor real no recibe el evento → hilos bloqueados en `osRecvMesg`
  → **deadlock**.
- **El disable/veneno es un síntoma**, no el bloqueo (hay softlock sin veneno y con `HH_NO_DISABLE`).
- **Instrumentación activa** (`HH_CHAINTRACE=1`): `[CHAIN]` (cadena del disable), `[SCHED]`/`[DISP]`
  (scheduler `FUN_80004bb0`/`FUN_80004d20`), `[BCAST]`/`[PUSH]`/`[POP]` (event-dispatch).

---

## 5. SIGUIENTE PASO (para la próxima sesión)

**Cazar quién pisa el nodo `0x8005BF14`** (el watchpoint directo da SEGV por estar en pila). Vías:
1. **Volcar `next`/`q` de cada nodo recién insertado** en `[PUSH]` y, en el `[BCAST]`, detectar el
   primer nodo cuyo `q`/`next` no sea válido → localizar cuándo y desde qué tid.
2. **Inspeccionar los nodos basura `0x8025xxxx`** en `hh_hang_rdram_*.bin` (patrón físico: ¿son campos de
   un objeto M10 mal dimensionado?).
3. **Revisar el módulo M10** (el del CaC): data-as-code / símbolos con fronteras mal acotadas
   (`config/*.syms.toml`, `0xADDR:0xSIZE`, `docs/adr/0002*`). El TODO ya lista "Data-as-code (189
   sospechosas)".
4. Comparar con el emulador (que **no** se cuelga) — con la cautela de §3b (el emulador con este replay
   no es fiel).
5. **Validar en Windows en vivo** (allí el freeze es ~100 %; headless es intermitente).

**Criterio de cierre**: sin `HH_NO_B280`/`HH_NO_DISABLE` (ni `HH_VI_EVERY`), el port **entra al combate**
por el mismo camino que el emulador.

---

## 6. HERRAMIENTAS / HOOKS (opt-in; no afectan al juego normal)

- **Runtime NMR `librecomp/src/overlays.cpp`** (instrumentación, **sin commitear**):
  `HH_M7GATE`, `HH_GATE_A` (puerta `0x39`), `HH_EPOCHTRACE`, `HH_LDTRACE`/`HH_TBLTRACE`, `HH_FRAMERATE`
  (`[FRM]`/`[NOOP]`), `HH_B280TRACE`, `HH_NO_B280`, `HH_NO_DISABLE`, `HH_CHAINTRACE` (`[CHAIN]`,
  `[SCHED]`, `[DISP]`, `[BCAST]`, `[PUSH]`, `[POP]`), watchpoint `HH_WATCH_ADDR`/`HH_WATCH_SIZE`/
  `HH_WATCH_VENOM`.
- **Runtime NMR `ultramodern/src/`**: `HH_VI_EVERY=N` (`events.cpp`; **ya en el fork**); `HH_DET_CLOCK`
  (+`_BIAS`,`quant`) (`timer.cpp`); `[BADMQ]` en `mesgqueue.cpp` (valida colas).
- **Port** (`src/main/main.cpp`): `hh_state.log` con `[STATE] trans` (42D0/7730/38/48/50/g2/cnt30/objCB/
  a8/q4F0/q268/m188/m181) y `[STATE] mq`; anillos por hilo; watchdog (`HH_HANG_SECS`, `HH_HANG_FORCE`,
  `HH_STATE_SECS`), `HH_S0FIX`, `[FLAG]`.
- **Port** (`src/game/input.cpp`): `HH_MASK_START=lo:hi` (diagnóstico); `HH_REPLAY_MODE=poll|vi`.
- **Tool**: `tools/analysis/ring_syms.py` (simboliza `hh_hang.log`/`hh_slice.log`).

## 7. BATS (Windows, doble clic salvo indicación)

- `port/run_cac_tick2.bat` — en vivo con `HH_VI_EVERY=2` (ya probado: **no arregla**).
- `port/run_chain_live.bat` — en vivo con `HH_CHAINTRACE=1` (+ `HH_GATE_A`, `HH_B280TRACE`): recoge
  `hh_chain.log`, `hh_sched.log`, `hh_scheddisp.log`, `hh_hang.log`… en `logs_chain_<fecha>\`.
- `port/run_nodisable_live.bat` — en vivo con `HH_NO_DISABLE=1` (ya probado: **no arregla**; no recoge logs).
- `port/run_cac_nob280.bat [cac_rec.txt]` — replay + `HH_NO_B280=1`.
- `port/run_stall_check.bat [det] [nob280]`, `port/run_stall_check_nob280.bat`, `port/stall_summary.ps1`.

## 8. CÓMO REPRODUCIR MEDIDAS CLAVE (headless)

- Build: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Emu epoch: `HH_KEYS_REPLAY=<replay> HB_TRACE_EXEC=0x801C0A30 tools/analysis/emu_ref.sh work/debug/emu_epoch 40 9999`
- Emu instalador/puerta: igual con `HB_TRACE_EXEC=0x8021B240,0x80126A0C` (el emu **no** ejecuta el instalador).
- M24: `HH_TBLTRACE=1 HH_LSTTRACE=1` → `[TL] ADVANCE/EVQCHECK/P89478/CHAIN`.
- Emu gate: `HB_TRACE_EXEC=0x80126A0C` (la puerta; en `emu_gate_run.log` solo con `a1=0x113`/`0x74`).

## 9. HECHOS CLAVE (no repetir)

- **Veneno**: `FUN_800058dc` (setter, `sw a1,0x1C(a0)`) escribe el callback; cadena
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → … → M55_FUN_80379410 → FUN_800058dc`; instalador
  `M10_FUN_8021b240` **solo si** `M7_FUN_80126A0C(obj,0x39,1) != 0`. Emu: instalador **0 ejecuciones**.
  Publicación (`hh_b280set.log`): `callring … 80004BB0 801257DC 80125774 800058DC`.
- **M24**: driver `M24_FUN_801bfaa0`; avance `M24_FUN_801bffac`; waits `FUN_801C0B8C`; epoch
  `M24_FUN_801c0a30` ← `M24_FUN_801C0C08` (`[0x801D8D80:84]`).
- **Cola `0x8005C288`** = cola del bucle principal; el tipo del mensaje está en `[0x8005C4B0]` (siempre
  `1`, nunca `3`). El frame (`FUN_80001454`) se ejecuta cada VI en el port (60/s) vs cada 2 en el emu.
- **Event-dispatch**: `FUN_80000934(obj,mq)` empuja nodo `{next,mq}`; `FUN_80000A0C(obj,msg)` hace
  broadcast; nodo en `[obj+0x888]`.
- **Ojo con la instrumentación**: los dumps grandes (`HH_DUMP_VI`) y logs por línea
  (`HH_MQLOG_ALL`/`HH_WAITLOG`) **enmascaran/frenan** la divergencia; usar trazas ligeras y
  `HH_STATE_SECS` bajo. Las líneas de distintos hilos pueden aparecer **desordenadas** en un log.
- **Nota del mantenedor (a verificar)**: el audio petardea sobre todo en el menú/intro; gameplay casi fino.

## 10. ESTADO DE REPOS

- **Main repo** (`origin` → `hunkstalker/hybrid-heaven-recomp`, rama `main`): esta sesión commitea la
  documentación y la instrumentación (ver el commit). Push: `cd /app/hybrid-heaven-recomp && git push origin main`.
- **N64Recomp fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime/N64Recomp`, `origin`, rama
  `hybrid-heaven`): `cab94d9` ya pusheado.
- **Runtime fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime`, remote **`fork`**, rama
  `hybrid-heaven`): había `15f920d` pusheado; esta sesión añade **instrumentación nueva en
  `librecomp/src/overlays.cpp`** (y `recomp.cpp`/`mesgqueue.cpp`). Decidir commit/push:
  `git push fork hybrid-heaven`.
- **`port/runtime.lock`**: `NMR_COMMIT`/`N64RECOMP_COMMIT` (pin). Orden de push (AGENTS): N64Recomp →
  N64ModernRuntime → main.
- En Windows: main `E:\dev\docker\hybrid-heaven-pc-port\hybrid-heaven-recomp` (mismo árbol montado);
  recompilar con `port\build_windows.local.bat`.

## 11. DOCUMENTACIÓN DE LA SESIÓN

- **`notes/2026-09-19-causa-raiz-cadencia-frames.md`** — **empezar aquí** (§0-§16: cadencia, harness,
  scheduler, evento `0x39`, cadena del disable, corrupción de la lista de suscriptores y nodo corrupto).
- `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` — verificación del harness port↔emu.
- `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` — veneno, gate, `HH_NO_DISABLE`, reloj.
- `notes/2026-09-19-bat-stall-check.md` — stalls, M7/M12, driver M24, test A→B.
- `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` — diferencial VI, cadena del disable.
- `notes/2026-09-17-replay-mode-vi-vis-negativo.md` — replay/pacing/AI FIFO/`HH_VI_EVERY`.
- `notes/2026-09-17-cac-timeline-modulo24-periodo.md`, `notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`,
  `notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md`, `notes/2026-09-19-clasificacion-adelanto-fase-previa.md`.
- Índice: `python3 tools/analysis/docs_index.py` (`--check` valida).
