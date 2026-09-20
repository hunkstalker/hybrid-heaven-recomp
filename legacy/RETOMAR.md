# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota de la sesión.
> **Detalle completo**: **empieza por `notes/2026-09-20-nodo-8005bf14-origen-y-captura.md`** (cierra
> “quién pisa” y corrige el mecanismo de `FUN_80000934`), después
> `notes/2026-09-19-causa-raiz-cadencia-frames.md` (hasta §16), y luego
> `notes/2026-09-19-bat-stall-check.md`, `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` y
> `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`.
> Última sesión: **2026-09-20 (noche-5)**. Continuar en una sesión nueva.

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
5. **2026-09-20 (noche-3/4)**: descartado el front-end/cadencia como causa. **La causa inmediata
   parecía corrupción de memoria**: el CaC corrompe la **lista de suscriptores del event-dispatch** →
   mensajes a colas basura (`[BADMQ]`) → deadlock.
6. **2026-09-20 (noche-5, esta tanda)**: **cerrado “quién pisa”**. El nodo `0x8005BF14` es un
   **local de pila** (`sp+0x34`) de `FUN_800011b0` (bucle principal, hilo 5), empujado una vez. **No**
   lo corrompe una escritura ajena: lo **pisa la cadena del disable**, que se **reinvoca en bucle
   sobre el mismo objeto escalando la pila ~0x58 por iteración** (los 12 venenos del log son el
   **tope del instrumento**, `vn>=12`, no el número real). El marco que pisa coincide con
   `FUN_800011b0` (`sp=0x8005BEE0` ⇒ `node=sp+0x34`). Corrección de doc: `FUN_80000934` **no**
   asigna el nodo (`FUN_800267F0` es un setter de máscara de interrupción, no un allocator). El nodo
   es **colateral** ⇒ la causa raíz es la **reinvocación de la cadena del disable**.

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
| `HH_NO_DISABLE` (ignora el centinela `0xFFFF84CD`) | ❌ **en vivo sigue el cuelgue** (no evita la cadena que pisa la pila) | `2026-09-19-veneno…` §6; noche-5 |
| Puerta `M7_FUN_80126A0C(obj,0x39,1)` | ✔ se llama 16 veces; #13 → `ret=1` con `42D0=0x2B88` | `causa-raiz…` §9 |
| Evento temporizado `0x39` (target `0x3000`) | ✔ el scheduler `FUN_80004bb0` lo despacha (emu no) | `causa-raiz…` §12 |
| Cadena `b1A8→b200→b240→b280` | ✔ confirmada en vivo (objeto `0x8024D690`/`0x8024C7CC`) | `causa-raiz…` §11 |

### 3e. Corrupción de memoria / nodo de suscriptores
| Prueba | Resultado | Fuente |
|---|---|---|
| `[BADMQ]` (osSendMesg a cola corrupta) | ✔ aparece **sin veneno** (headless) y con `HH_NO_DISABLE` | `causa-raiz…` §13 |
| Punteros de cola corruptos | ✔ son **floats de física** (`3F3851EC`, `40500000`…) | `causa-raiz…` §14 |
| Event-dispatch `FUN_80000A0C` (broadcast a suscriptores `{next,mq}` en `[obj+0x888]`) | ✔ identificado | `causa-raiz…` §15 |
| Nodo corrupto | ✔ **`0x8005BF14`** (→ cola `0x8005C288`) se pisa; la lista salta a nodos basura | `causa-raiz…` §16 |
| Todos los `[PUSH]` observados | ✔ `q` válido ⇒ el nodo se corrompe **después** de insertarse | `causa-raiz…` §16 |
| Watchpoint **por acceso** `HH_WATCH_ADDR=0x8005BF14` | ❌ **SEGV** (nodo en pila) | noche-4 |
| **Origen del nodo** (estático) | ✔ `0x8005BF14 = sp+0x34` de `FUN_800011b0` (hilo 5), push único; `FUN_80000934(obj,node,mq)` recibe el nodo del llamante (`FUN_800267F0` = setter de máscara, **no** allocator) | noche-5, `nodo-8005bf14…` §1-2 |
| `[NODEWATCH]` (mini-canary por VI de nodos persistentes) | ✔ captura el pisado con **ventana de llamadas de todos los hilos**; evita el SEGV | noche-5, `nodo-8005bf14…` §5 |
| `[BCORRUPT]` (walk acotado + detector de ciclo/q-no-cola) | ✔ reporta el primer nodo roto; el walk sin cota se colgaba con ciclos | noche-5 |
| **`HH_DRWATCH` de Windows** (watchpoint de HW sobre el nodo) | ❌ solo captó **arranque** (`rip=exe+0x828234`, valores sin inicializar); no fiable para el CaC | noche-5, `nodo-8005bf14…` §8 |
| **Autor del pisado** (`run_node_drwatch.bat`) | ✔ **hilo 5, marcos de la cadena del disable**; `[NODEWATCH]` lo sitúa (vi 18231-18281 según run) | noche-5, `nodo-8005bf14…` §8 |
| Los 12 venenos: `sp` escala **+0x58** | ✔ `8005BDD8 … 8005C1A0`; **todos del mismo objeto**; el “12” es **tope de log** (`vn>=12`) | noche-5 |
| `ring2-last512` en el veneno | ✔ el driver (`FUN_80006214`/`FUN_8001f718`/`M7_FUN_8012c9c0…`) se ejecuta a `sp` constante y la cadena se reinvoca a `sp+0x58` por iteración | noche-5 |
| Cronología causal (Windows) | ✔ `[CHAIN]` vi 7895-7924 → `[SCHED] a0=0x39` vi 7924 → corrupción vi 7929 | noche-5 |
| Pila final: `ra` de hilo 5 = `8005C3A2` (dirección de pila) | ✔ **smash de pila**, no escritura suelta | noche-5 |

---

## 4. ESTADO ACTUAL (dónde está el problema)

- **RESUELTO (noche-5, validado Windows)**: la **fuga de pila** que corrompía el nodo `0x8005BF14` (y
  con ella el `[BADMQ]` y el deadlock de colas). Mecanismo: en el CaC la cadena del disable tiene
  **mid-entries** (`M55_FUN_80379410/424/444/464`, sin prólogo) **y** el dispatcher `FUN_80005270`
  que devuelven `sp +0x58`; el `sp` del hilo 5 trepaba `~0x58/frame` y pisaba el marco de
  `FUN_800011b0` (nodo de suscriptores). **Fix `HH_M55SPFIX=1`** (restaurar `sp` en esos wrappers).
  Evidencia: nodo intacto (lista `80095FF8 → 8005BF14` sana en el dump), sin `[BCORRUPT]`, y **el
  juego llega al CaC con el HUD de combate apareciendo**.
- **NUEVO BLOQUEO**: el port **sigue instalando el veneno** (cadena del disable) y ahora hace un
  **livelock** de tid 5 en código M10/M12 del CaC (`M10_FUN_80228298`, `ra=000000FE`,
  `queue=00000000`, `ctx_sp=8005BE18` sano) justo con el HUD apareciendo. No es corrupción de pila.
- **Instrumentación activa** (`HH_CHAINTRACE=1`): `[CHAIN]`, `[SCHED]`/`[DISP]`, `[BCAST]`/`[PUSH]`/
  `[POP]`, `[NODEWATCH]`/`[BCORRUPT]`, `[B280CALL]`, `[SPCHK]`, `[M55SPFIX]`/`[DISP-SPFIX]`, `[DISP]`,
  `[S0FIX]`.

---

## 5. SIGUIENTE PASO (para la próxima sesión)

**CAUSA RAÍZ REAL (noche-5, tarde)**: la extracción inicial de módulos era **incompleta** —
`tools/setup_module.py` extraía solo **11 de las 625** entradas de la tabla Nisitenma y **faltaba el
índice 56 = FICHERO 57 (combate)** (`rom=0x69E416`, base `0x80358820`), que el juego carga con un
**segundo loader streamed `FUN_80004838`** (no por `file_load`). Sin el 57, `0x80379410` resolvía a
`M55_FUN_80379410` (**mid-función del fichero 56/exploración**, sin prólogo) → fuga de pila (+0x58) →
nodo/deadlock. `HH_M55SPFIX` era un **parche de síntoma**.

**Aplicado**: módulo 56 extraído + recompilado (`M56_FUN_80379410` correcto), wrapper de `0x80004838`
que lo registra al cargar, `recomp_syscall_handler` stub. Ver
`notes/2026-09-20-nodo-8005bf14-origen-y-captura.md` §12.

**Pendiente**:
1. **Validar en Windows con `port/run_fix57.bat`** (SIN `HH_M55SPFIX`): debe verse `[STREAM] id=57`,
   el nodo no corromperse y el combate avanzar. Si es así, la fuga está resuelta de raíz.
2. **Re-evaluar TODOS los workarounds** ahora: `HH_M55SPFIX`, `HH_NO_B280`, `HH_NO_DISABLE`,
   `HH_VI_EVERY` — buena parte pueden sobrar (el usuario lo apuntó).
3. **Arreglar el pipeline**: `setup_module.py` aborta en un `[ERROR] ramas cruzadas` de module55 (usar
   `--force` en la validación) para que la regeneración incluya el 56 automáticamente.
4. **Filtrar los datos-como-código** de module56 (`0x80386E80..0x8038xxxx`: `syscall`/`mthi`/`break`)
   para no generar funciones basura (`recomp_syscall_handler`).
5. Revisar si faltan **más** módulos de código (la tabla tiene 625 entradas; el port declaraba ~91
   ficheros de código).

**Descartado (no repetir)**: `HH_DRWATCH` (solo arranque), watchpoint por acceso, cadencia/front-end,
fallthroughs de la cadena M7/M10.

**Criterio de cierre**: sin parches (`HH_NO_*`), el port **entra al combate** por el mismo camino que
el emulador.

---

## 6. HERRAMIENTAS / HOOKS (opt-in; no afectan al juego normal)

- **Runtime NMR `librecomp/src/overlays.cpp`** (instrumentación, **sin commitear**):
  `HH_M7GATE`, `HH_GATE_A` (puerta `0x39`), `HH_EPOCHTRACE`, `HH_LDTRACE`/`HH_TBLTRACE`, `HH_FRAMERATE`
  (`[FRM]`/`[NOOP]`), `HH_B280TRACE`, `HH_NO_B280`, `HH_NO_DISABLE`, `HH_CHAINTRACE` (`[CHAIN]`,
  `[SCHED]`, `[DISP]`, `[BCAST]`, `[PUSH]`, `[POP]`, `[NODEWATCH]`, `[BCORRUPT]`, **`[B280CALL]`**),
  watchpoint `HH_WATCH_ADDR`/`HH_WATCH_SIZE`/
  `HH_WATCH_VENOM`. `hh_venom.log` vuelca `stack-RA` + `callring` + **`ring2-last512`** (historial
  largo por hilo, `target sp`; `hh_ring2` se activa con `HH_CHAINTRACE` o `HH_WATCH_ADDR`).
  **`hh_b280call.log`** (`[B280CALL]`): profundidad (`depth`) + contador por objeto (`objcount`) de
  `M10_FUN_8021b280` — mide la reinvocación (tope de veneno subido a 64).
  **`hh_spchk.log`** (`[SPCHK]`): **fuga de pila** — wrappers de las funciones del driver/cadena
  (`FUN_80006214`/`FUN_8001f718`/`M7_FUN_801277b0`/`M7_FUN_8012c9c0…`/`M55_FUN_80379410`/
  `M10_FUN_8022c7a4…`) que loguean `entry/exit/delta` de `sp`; localiza quién retorna con `sp` de más.
  **`HH_M55SPFIX=1`** (`[M55SPFIX]`/`[DISP-SPFIX]` → `hh_m55spfix.log`; `[DISP]` → `hh_disp.log`):
  **fix de la fuga de pila** — restaura `sp` en el cluster M55 (`M55_FUN_80379410/424/444/464`, no el
  epílogo `8037948C`) y en el dispatcher `FUN_80005270`. Ver §5.
- **Runtime NMR `librecomp/src/recomp.cpp`**: `hh_nodewatch_*` (mini-canary del nodo), `hh_ring2_*`,
  `HH_CANARY` (canary por VI), **`HH_DRWATCH`** (watchpoint de hardware Windows; guarda `hh_drwatch.log`
  + `hh_drwatch_rdram.bin`).
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
- `port/run_node_drwatch.bat` — en vivo con **watchpoint de HARDWARE** (`HH_DRWATCH` sobre
  `0x8005BF14/18` y `0x80095FF8/C`) + `HH_CHAINTRACE=1` + **`HH_M55SPFIX=1`** (fix de la fuga de pila):
  recoge `hh_nodewatch.log`, `hh_spchk.log`, `hh_m55spfix.log`, `hh_disp.log`, `hh_venom.log`… en
  `logs_nodewatch_<fecha>\`. **Nota**: `HH_DRWATCH` solo pilló el arranque; lo útil es `[NODEWATCH]`+
  `[SPCHK]`+`[M55SPFIX]`. Válido cargando partida justo antes del CaC.
- `port/run_stackfix_nob280.bat` — como el anterior pero con **`HH_NO_B280=1`** (ignora el veneno):
  diagnostica si el **livelock restante** es consecuencia del disable. Logs en
  `logs_stackfix_nob280_<fecha>\`.
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
- **Event-dispatch**: `FUN_80000934(obj, node, mq)` empuja nodo `{next,mq}` — el **nodo lo aporta el
  llamante** (`a1`, típicamente su pila); `FUN_800267F0` es un **setter de máscara de interrupción**
  (`cop0 Status`/`0xA430000C`), **no un allocator**. `FUN_80000A0C(obj,msg)` hace broadcast; nodo en
  `[obj+0x888]`. (Corrige la nota `causa-raiz…` §15.)
- **Nodo `0x8005BF14`**: `sp+0x34` de `FUN_800011b0` (bucle principal, hilo 5; push único, `q=0x8005C288`).
  Lo pisa la **cadena del disable** al reinvocarse en bucle (sp +0x58/iteración), no una escritura ajena.
- **Cadena del disable reinvocada**: los venenos del log son del **mismo objeto** y su `sp` escala
  0x58; el tope `vn>=12` de `hh_dump_venom` **trunca** el log (no son 12 iteraciones reales). El driver
  es `FUN_80006214`/`FUN_8001f718` + `M7_FUN_801277b0`/`M7_FUN_8012c9c0…`; esperar 20-30 s para el
  `ra=8005C3A2` (smash de pila) si aplica.
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

- **`notes/2026-09-20-nodo-8005bf14-origen-y-captura.md`** — **empezar aquí** (mecanismo real de
  `FUN_80000934`, origen del nodo en `FUN_800011b0`, forma del pisado, instrumentación `NODEWATCH`/
  `BCORRUPT`, captura Windows §8, corrección del tope `vn>=12`).
- **`notes/2026-09-19-causa-raiz-cadencia-frames.md`** — §0-§16: cadencia, harness, scheduler, evento
  `0x39`, cadena del disable, corrupción de la lista de suscriptores y nodo corrupto.
- `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` — verificación del harness port↔emu.
- `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` — veneno, gate, `HH_NO_DISABLE`, reloj.
- `notes/2026-09-19-bat-stall-check.md` — stalls, M7/M12, driver M24, test A→B.
- `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` — diferencial VI, cadena del disable.
- `notes/2026-09-17-replay-mode-vi-vis-negativo.md` — replay/pacing/AI FIFO/`HH_VI_EVERY`.
- `notes/2026-09-17-cac-timeline-modulo24-periodo.md`, `notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`,
  `notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md`, `notes/2026-09-19-clasificacion-adelanto-fase-previa.md`.
- Índice: `python3 tools/analysis/docs_index.py` (`--check` valida).
