# Work order — Pacing/cadencia: cuadrar la lógica del port con el original

> Documento operativo **autocontenido** para retomar ESTA tarea en una sesión nueva.
> Continúa `notes/2026-09-17-plan-revision-bloqueo-cac.md` (Parte A) y
> `notes/2026-09-13-cadena-boot-y-progreso-fe00.md` §5.
> Estado al escribir: foco recién elegido, causa raíz sin confirmar. Última actualización: 2026-09-17.

## 0. TL;DR (30 segundos)

El port ejecuta la **lógica de juego** (`FUN_80001454` frame, `FUN_80005270` dispatcher) a
**~16–28/s**, mientras VI y audio van a **60/s**. El original (emulador) parece ir a **~32–70/s**
según qué se mida. Si el original va a 60 y el port a ~30, hay **media cadencia**: los state
machines por-frame/temporizador divergen y los scripts avanzan a distinto ritmo → hipótesis fuerte
(no probada) de por qué el módulo 23 **nunca llega al `case 2`** que arma el combate CaC.

Pista ya documentada: el **gate `[0x8005CD4C]`** (tareas RSP pendientes). Si `[0x8005CD4C] >= 2`,
`FUN_80001454` **se salta el dispatcher**. En el emulador oscila 0/1; en el port quedó descansando
en 1–2 (notas `2026-09-13-cadena-…` §5 y `2026-09-13-deadlock-sp-race.md`).

**Objetivo**: cadencia y **ratio eventos/VI** 1:1 con el original. Subir a 60 fps *más* que el
original **no** es el objetivo (física/animación atadas al frame; sería otro proyecto).

## 1. Objetivo y criterios de éxito

- **Objetivo**: que la lógica del port se ejecute al mismo ritmo (por VI) que el original.
- **Criterios medibles** (en la misma fase, boot→attract/gameplay):
  1. Hits/s de `FUN_80001454` y `FUN_80005270` del port ≈ emulador (**±10%**) **o**, si el emulador
     va sin throttling, **ratio hits/VI** igual.
  2. `[0x8005CD4C]` oscila como el emulador (0/1) y `FUN_80005270` se llama cada frame que toca.
  3. Ratio tareas/VI (audio, SP, gfx) igual al original.
  4. Re-test del repro de **CaC** con la cadencia corregida (puede cambiar el desenlace).
- **Bar acordado con el usuario**: primero **1:1 con el sistema original**; "más fps" solo después.

## 2. Mecanismo conocido del gate `[0x8005CD4C]`

Verificado por disasm en `notes/2026-09-13-workorder-gate-rsp.md` §2:

- `FUN_80001454` (`RecompiledFuncs/funcs_0.c:3119`), en `0x800017AC..0x80001854`:
  si `[0x8008D545]==0` **y** `[0x8005C4B0+0x89C] >= 2` → **epílogo** (no llama al dispatcher).
- **Incremento**: `FUN_80000ed0` (submit de task) si `[msg+8] & 0x40` → `[a0+0x89C]++` en
  `0x80000F54` (a0=`0x8005C4B0`) y `osSendMesg(0x8005C4F0, msg)`.
- **Decremento**: hilo **17** en `FUN_80000bf0`, al consumir un msg con `[msg+8]&0x40` →
  `[a0+0x89C]--` en `0x80000D7C`; después espera completions **SP** (evento 4, msg `0x29B`) y
  **DP** (evento 9, msg `0x29C`).
- Dispatcher `FUN_80005270` (`funcs_1.c:7031`) corre en el cuerpo principal + pump `FUN_8000433C`.

## 3. Evidencia medida (NO repetir salvo para confirmar)

### Port
- Linux `build_dbg`, 85 s, `HH_NOAUDIO=1`, `HH_TRACE="0x80001454:frame,0x80005270:disp"` (llvmpipe):
  `frame` **1787/80 s ≈ 22/s**, `disp` **1267/80 s ≈ 16/s**.
- `hh_state.log`: `VI=4809`, `vi_ticks=4793`, `audio=4770` a t=80 s → **60/s** los tres.
  `polls` variable (≈12–30/s según fase).
- Windows (usuario, `run_corrupt.bat`): `polls` ≈ **28/s**, `disp` ≈ **24/s**; VI/audio 60/s.
- **La task de audio NO es el cuello**: `hh_rsp.log` → `avg 0.4–1.5 ms, max 4 ms` (límite 16.7).
- `hh_audio.log`: 60 calls/s, ~43.2k frames/s, cola SDL crece ~100 frames/s (drift 0.2%),
  `reported=720` (cap de `support.cpp:374`).

### Emulador (r64dump)
- `FUN_80001454`: **2118/30 s = 70/s** (`work/debug/ratetest.log`) → **posible run sin throttling**:
  70/s sería su máximo, no la cadencia original.
- `FUN_80005270` + `FUN_80000ed0`: **3833/60 s** (nota `2026-09-13-audio-ai-…` §3). **Ambigüedad**:
  si la cifra es la **suma de ambos breakpoints**, son ~32/s cada uno, no 64.
- Otra nota (`2026-09-13-cadena-…` §2) da dispatcher **36/s** en el emulador → consistente con ~30-36.
- wplog: escribe `0x8005CD4C`: `wr=1 pc=0x80000F58`, `wr=0 pc=0x80000D80`.

> **Conclusión de la evidencia**: el "64/s" del plan es dudoso. **Fase 0 debe resolver si HH corre a
> 30 o 60 fps lógicos** antes de tocar nada. El port va a la mitad del original con cualquiera de
> las dos lecturas, pero el *target* cambia.

## 4. Fase 0 — Referencia del original (emulador, misma fase)

Objetivo: tasa/ratio de `FUN_80001454`, `FUN_80005270` y `FUN_80000ed0` **por separado**, junto al
contador VI del harness (`r64dump.cpp:58` `g_vi_count`; imprime `[dbg] vi_count=…` periódicamente).

```sh
HB_TRACE_EXEC=0x80001454,0x80005270,0x80000ed0 tools/analysis/emu_ref.sh work/debug/emu_rate2 60 60
# Luego: contar líneas por dirección y leer los [dbg] vi_count del stdout del harness.
```

- **Métrica robusta = hits/VI** (independiente del throttling y del coste de `HB_TRACE_EXEC`).
- Si el harness permite correr sin límite, comprobar también el VI/s real del emulador.
- Entregable: tabla "original = X frame/s, Y disp/s, Z VI/s → **hits/VI**".

## 5. Fase 1 — Localizar el limitador en el port

Instrumentación existente (reusar; no hace falta escribir casi nada):

| Qué | Knob / fichero | Dónde |
|---|---|---|
| Cambios de `cd4c` | `HH_VERBOSE=1` → `[GATE] vis=… cd4c=…` | `events.cpp:380` |
| Línea `[RND]` completa (3750/fe00/node/cd4c/**t17q/t16q**/mqr/mqs…) | `HH_VERBOSE=1` | `events.cpp:398` |
| Recv/send del gate | `HH_GATELOG=1` → `[GATE2] … fl8=… cnt=…` | `mesgqueue.cpp:250` |
| Submit con contador antes/después | `HH_TBLTRACE=1` → `[SUBM]` | `overlays.cpp:855` |
| Todas las colas (t, tid, mq, msg) | `HH_MQLOG_ALL=1` → `hh_mq_all.log` | `mesgqueue.cpp:86` |
| Park/wake del scheduler | siempre → `hh_sched.log` (16 MB) | `threads.cpp:18` |
| Frame/dispatcher | `HH_TRACE="0x80001454:frame,0x80005270:disp"` | `recomp.cpp` (`hh_trace_fn`) |
| Snapshot VI/polls/audio/pending | `HH_STATE_SECS=5` → `hh_state.log` | `main.cpp:310` |

Preguntas a responder:
1. ¿En qué **espera** se va el tiempo entre frames? (mq VI `0x8005C560`, gate `0x8005C4F0`,
   SP/DP, `osRecvMesg` bloqueante). Con `hh_mq_all.log` + `hh_sched.log` se ve t, tid y mq.
2. ¿Quién deja `cd4c` en 1–2? ¿tasks de **audio** (hilo 3) o de **gfx** (t17)? ¿El decremento del
   hilo 17 ocurre para todas?
3. ¿Cuántos **parks/wakes** hace el frame por iteración y cuánto cuesta cada uno (condvar + game lock)?
4. ¿El frame espera al **VI event** o va sobrado de tiempo?

Entregable: "el frame pierde **T ms/frame** esperando a **X**" + `cd4c` por frame + quién lo sube.

## 6. Fase 2 — Fixes candidatos (uno por pasada, medir con Fase 1)

1. **Gate `0x8005CD4C`** (pista documentada): que drene 0/1 como el original.
   - Revisar la completación de las tasks con flag `0x40` (¿audio incluido?) y el camino
     SP/DP dirigido (`pending_completions`, `mesgqueue.cpp`).
   - Recordar: `sp_complete` **sintético** para gfx en `submit_rsp_task` (`events.cpp:750`).
     ¿Falta el equivalente para audio, o sobra un decremento?
2. **Scheduler/handoff**: `threads.cpp` game lock (`:147-162`) + `wait_for_resumed` (`:280`),
   `scheduling.cpp` (`check_running_queue`, FIFO entre iguales). A/B quitando el lock (TODO #9).
3. **Handshake audio/SP**: completar la task inline (mismo patrón que gfx) y A/B de
   `HH_SP_SHARED`, `HH_AI_QUEUE_REPORT=full`, `HH_AI_SPEED`.

Regla: **una variable por pasada**; si un fix no mueve la métrica de Fase 1, revertir.

## 7. Fase 3 — Validación

1. Port == original (hits/s o hits/VI) en boot y en gameplay.
2. `[0x8005CD4C]` oscila 0/1 y `FUN_80005270` corre cada frame.
3. Re-correr bats de regresión de menús/guardado y el **repro de CaC** (con y sin objetos/daño).
4. Si el CaC sigue, volver a `2026-09-17-plan-revision-bloqueo-cac.md` Parte B con la cadencia ya
   correcta (el `case 2` de `M23_FUN_801c1dc0` es el siguiente hito).

## 8. Comandos base

```sh
# Port Linux (Xvfb :99 con GLX vivo)
cd port/HybridHeavenRecomp/build_dbg
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_NOAUDIO=1 HH_TRACE="0x80001454:frame,0x80005270:disp" timeout 85 "./Hybrid Heaven Recomp"
# Diagnóstico de pacing:
HH_VERBOSE=1 HH_GATELOG=1 HH_TBLTRACE=1 HH_MQLOG_ALL=1 HH_STATE_SECS=5 ... "./Hybrid Heaven Recomp"

# Port Windows (usuario): port/build_windows.local.bat  ->  port/run_corrupt.bat
#   logs junto al .exe: port/HybridHeavenRecomp/build_win/bin/Release/ (abiertos en "w")

# Emulador de referencia
HB_TRACE_EXEC=0x80001454,0x80005270 tools/analysis/emu_ref.sh work/debug/emu_rate2 60 60
python3 tools/analysis/parse_exec_trace.py work/debug/emu_rate2.log   # si aplica

# Recompilar (si se toca syms/tool): NUNCA editar RecompiledFuncs/ a mano
python3 tools/recomp.py --config config/game_combined.toml --build
```

## 9. Trampas y reglas

- `HB_TRACE_EXEC` **detiene** la emulación en cada hit: invalida el wall-clock; usar **hits/VI**.
- El emulador `r64dump` puede ir **sin throttling** → su fps es su máximo, no la cadencia original.
- RDRAM del harness `r64dump`: **LE nativo, sin `bswap32`** (lo viejo de `AGENTS.md` corrompe).
- Windows: los logs se abren en `"w"` (no mezclar pasadas); guardar copia en `logs_*/` por pasada.
- El runtime local vive en `port/HybridHeavenRecomp/lib/N64ModernRuntime` (repo anidado gitignored;
  `port/build_windows.local.bat` compila `lib/` tal cual).
- No tocar `RecompiledFuncs/` a mano; fixes a `config/*.syms.toml` o al runtime.
- No commitear sin pedirlo. No tocar ROMs, saves ni `work/*.so`.

## 10. Artefactos en disco

- Port: `port/HybridHeavenRecomp/build_dbg/{hh_trace,hh_state,hh_rsp,hh_audio}.log`,
  `work/debug/rateport.log`; evidencia Windows en `build_win/bin/Release/logs_*/`.
- Emulador: `work/debug/ratetest.log` (conteos 2118/2006), `work/debug/emu_rate2*` (nuevos).
- Instrumentación de pacing: `hh_mq_all.log`, `hh_sched.log`, `hh_gate*.log` (según knobs).

## 11. Referencias

- `notes/2026-09-17-plan-revision-bloqueo-cac.md` — plan general y Parte A (pacing).
- `notes/2026-09-13-cadena-boot-y-progreso-fe00.md` §5 — gate `0x8005CD4C`, port 9,5/s vs emu 36/s.
- `notes/2026-09-13-workorder-gate-rsp.md` — mecanismo del gate por disasm.
- `notes/2026-09-13-deadlock-sp-race.md` — fix SP y "cd4c oscila 1/2".
- `notes/2026-09-13-audio-ai-y-estructura-pre-transicion.md` §3 — tasas del emulador (3833/60 s).
- `docs/architecture.md` §5 — divergencias con upstream (lock single-CPU, scheduler).
- `TODO.md` → Backlog "Audio (FUTURO): desacoplar de los fps".
