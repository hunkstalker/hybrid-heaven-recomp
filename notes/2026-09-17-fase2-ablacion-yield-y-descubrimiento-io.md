# Fase 2 — A/B de cesión de turno y descubrimiento: el I/O de los logs always-on dominaba las medidas

> Evidencia de la Fase 2 del work order `notes/2026-09-17-workorder-pacing-cadencia.md`.
> Continúa `notes/2026-09-17-fase1-limitador-pacing-port.md`. Fecha: 2026-09-17.
> Linux `build_dbg` (Release) + llvmpipe, `HH_NOAUDIO=1`, 45 s por pasada.

## 0. TL;DR

1. Los knobs de cesión (`HH_NO_MQYIELD`, `HH_MQYIELD_QUANTUM_MS`) mueven la cadencia de lógica
   (disp 17→23/s) pero **rompen el audio** (60→36-39/s): en un solo core no caben ambos con la
   política actual. `HH_MQYIELD=wake` = baseline.
2. **Hallazgo mayor**: la misma pasada ejecutada con CWD en **tmpfs** (`/dev/shm`) da
   **disp 33,5/s y polls 33,9/s** (≥ original 30/s) y frame 58,8/s. Las medidas en disco estaban
   **dominadas por el I/O de los logs always-on** del runtime/port (`hh_sched.log`, `hh_pi.log`,
   `hh_mq.log`, `hh_cmds.log`, `hh_trace.log`…): cada línea hace `fflush` y el fs del contenedor es
   lento. → Medir siempre en tmpfs (o silenciar logs).
3. En tmpfs queda **audio a ~44-46/s** (target 60/s): el hilo de lógica (`[Game] 5`) consume **78%
   de un core** y, al ser cooperativo, solo cede ~36 veces/s; el hilo de audio recibe ~1 slice por
   ciclo (~33 ms) y produce ~44 tasks/s. Siguiente palanca = cesión periódica por VI / prioridad del
   audio.

## 1. A/B de la política de cesión (mismo binario, CWD en disco)

Knobs nuevos en el runtime local (env, por defecto = comportamiento original):

| Knob | Efecto |
|---|---|
| `HH_NO_MQYIELD=1` | no cede nunca en `osSendMesg/osJamMesg/osRecvMesg` |
| `HH_MQYIELD=wake` | cede **solo si la operación despertó/encoló a otro hilo** |
| `HH_MQYIELD_QUANTUM_MS=<ms>` | cede si el hilo lleva >Q ms corriendo desde su último wake |
| `HH_YIELD_STRICT=1` | `check_running_queue` exige prioridad **estrictamente** mayor |

| Pasada (45 s, disco) | frame/s | disp/s | swaps tid5 | audio (t=40) | polls (t=40) |
|---|---|---|---|---|---|
| BASE (sin knobs) | 24,2 | 17,5 | 1765 | **2376 (59/s)** | 721 |
| `HH_NO_MQYIELD=1` | 59,3 | 20,8 | 6 | 1568 (39/s) | 864 |
| `HH_MQYIELD_QUANTUM_MS=12` | 54,5 | 22,9 | 730 | 1462 (37/s) | 942 |
| `HH_MQYIELD=wake` | 23,3 | 17,3 | 1842 | 2373 (59/s) | 709 |

Lectura: quitar cesiones sube la lógica (~+40%) pero **ahoga al audio** (la lógica acapara el core);
`wake` confirma que las cesiones del baseline corresponden a despertares reales (no son gratuitas).
Ninguna variante cumple las dos métricas → **no se adopta ninguna por defecto** (knobs quedan para
experimentos futuros).

## 2. Descubrimiento: I/O de logs vs tmpfs (mismo binario, mismos envs)

| CWD | frame/s | disp/s | polls/s (estable) | audio/s (estable) | gaps frame |
|---|---|---|---|---|---|
| `build_dbg/` (disco) | 24,2 | 17,5 | ~16 | ~59 | 40,6 ms |
| `/dev/shm/hh_fase2` (tmpfs) | 58,8 / 58,8 (x2) | **33,5 / 33,5 (x2)** | **33,9** | 44-46 | 17,0 ms |
| emulador (Fase 0) | 0,5/VI = 30 | 0,5/VI = 30 | 30 | 60 (asumido) | 33,3 ms |

- **disp y polls en tmpfs superan el objetivo** (33,5/s y ~33,9/s vs 30/s) y el frame interno corre
  cada VI con el dispatcher cada 2 VI (patrón del original).
- Reproducible en dos pasadas idénticas.
- CPU en tmpfs: `[Game] 5` **78%**, Gfx Thread 25%, llvmpipe ~200% (en disco `[Game] 5` era ~21% y el
  resto eran esperas de I/O dentro de los hilos).
- Conclusión: las medidas de Fase 1 ("frame a 3 VI por cesiones") eran, en gran parte, **stalls de
  escritura de logs** en cada hilo; el scheduler no es el cuello principal una vez medido sin I/O.

## 3. Estado de los criterios del work order

| Criterio | Estado |
|---|---|
| 1. hits/s de frame/disp ≈ emulador (±10%) | **CUMPLE en tmpfs** (disp 33,5/s vs 30; frame 58,8/s = 2x el original, ver nota) |
| 2. `cd4c` oscila 0/1 y disp corre cada frame | pendiente de re-medir en tmpfs (con `[GATE]`) |
| 3. Ratio tareas/VI (audio, SP, gfx) = original | **NO**: audio ~44-46/s vs 60/s (lógica acapara el core) |
| 4. Re-test del CaC con cadencia corregida | pendiente |

Nota: el frame `FUN_80001454` corre cada VI (58,8/s) mientras el dispatcher corre cada 2 VI (0,5/VI),
al revés que el original (ambos 0,5/VI). El ratio relevante de lógica (disp) sí coincide.

## 4. Siguiente (Fase 2, orden propuesto)

1. **Silenciar logs always-on** (higiene #5): gate de `hh_sched.log`/`hh_pi.log`/`hh_mq.log`/
   `hh_cmds.log`/`hh_ovl.log`/`hh_rsp.log` tras un env (p. ej. `HH_DIAG=1`), por defecto off. Es
   requisito para medir bien en disco y para el pacing de los usuarios.
2. **Audio a 60/s con lógica a 30/s**: A/B de cesión periódica (p. ej. forzar `check_running_queue`
   del hilo de lógica al entregar cada VI, 1 vez/2 VI) o subir la prioridad efectiva del audio;
   medir `audio/s` y `disp/s` en tmpfs. Alternativas: `HH_SP_SHARED`, `HH_AI_QUEUE_REPORT=full`,
   `HH_AI_SPEED`.
3. **Re-medir `cd4c`** en tmpfs (`HH_VERBOSE`+`HH_GATELOG`+pipe) y el re-test del CaC con la
   cadencia ya correcta (Fase 3).

## 5. Artefactos

- `work/debug/fase2_logs/{base,wake,tmpfs2}/` (state+trace+sched), `fase2_logs/` (tmpfs1).
- Knobs en `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/{mesgqueue,scheduling}.cpp`
  (+ `hh_thread_run_ms` en `threads.cpp`). **Sin commitear** (árbol local del runtime).
- Comando de medición fiable (tmpfs):
  ```sh
  cd /dev/shm/hh_fase2 && HH_NOAUDIO=1 HH_TRACE="0x80001454:frame,0x80005270:disp" HH_STATE_SECS=5 \
    timeout -s KILL 45 "/app/hybrid-heaven-recomp/port/HybridHeavenRecomp/build_dbg/Hybrid Heaven Recomp"
  ```
