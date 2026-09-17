# Fase 1 — Limitador del pacing en el port: cesiones del scheduler en cada osSendMesg/osRecvMesg

> Evidencia de la Fase 1 del work order `notes/2026-09-17-workorder-pacing-cadencia.md`.
> Continúa `notes/2026-09-17-fase0-referencia-cadencia-emulador.md` (original = 30 fps lógicos,
> 0.5 hits/VI). Fecha: 2026-09-17. Mediciones en Linux `build_dbg` + llvmpipe, `HH_NOAUDIO=1`.

## 0. TL;DR

El hilo de lógica (guest **tid 5**, pri 10) trabaja ~13 ms/frame, pero **cada `osSendMesg`/`osRecvMesg`
suyo acaba en `check_running_queue` y le cede el turno a hilos de mayor prioridad** (tid 0 VI, pri
254; tid 17 gate, pri 100). Cada cesión tarda **~19 ms** de media en devolverle el CPU; con ~1,7
cesiones por frame, el frame pasa de **33 ms (2 VI, original)** a **~46-50 ms (3 VI)**. La lógica
cabe de sobra en 2 VI: el problema es el **round-robin cooperativo**, no el coste guest ni el render.

## 1. Cuantificación (pasada de 45 s, `HH_TRACE` + `HH_WAITLOG` + `HH_STATE_SECS=5`)

| Métrica | Valor |
|---|---|
| Frame `FUN_80001454` / dispatcher `FUN_80005270` | ~18 / ~14 por s (target 30/30 = 0.5/VI) |
| Gap entre frames | media **43,6 ms**, mediana 46 ms (≈3 VI); original = 33,3 ms exactos |
| tid 5 corriendo | 1834 slices, **10,3 s / 42 s (24,6%)**, media 5,6 ms, mediana **2 ms** |
| tid 5 cesiones (`swap from=5`) | **1809 (43/s)**: 934 → tid 17, 871 → tid 0 |
| Coste de una cesión (swap→wake) | media **19,4 ms**, mediana 15 ms; a tid 0: 25,7 ms; a tid 17: 13,6 ms |
| Cesiones entre frames consecutivos | media 1,7, mediana 2 |
| tid 5 bloqueos en colas (`recv-block`) | **0** en toda la pasada |
| VI | tid 19 consume `0x8005C560` a 60/s (espera media 15,9-18,7 ms = 1 VI) |
| CPU host | [Game] 5 ≈ 21%; Gfx ≈ 14%; llvmpipe ≈ 70% de un core |

**Aritmética del frame**: ~13,6 ms de trabajo guest (10,3 s / ~756 frames) + 1,7 cesiones × 19,4 ms
≈ **46,6 ms** ≈ gap observado. El trabajo guest cabe en 33 ms; sobran ~33 ms de espera por cesiones.

## 2. Mecanismo (por qué cede)

- `osSendMesg`/`osJamMesg`/`osRecvMesg` terminan con `ultramodern::check_running_queue()`
  (`mesgqueue.cpp:592/614/632`). Esa función hace `swap_to_thread` a cualquier hilo **encolado con
  prioridad >= la actual** (`scheduling.cpp:29`).
- tid 5 es el hilo de menor prioridad útil (pri 10; audio pri 12; tid 16/17/18/19 = 110-130; tid 0 =
  254). Sus sends (~48/s: 932 a `0x800CE920`, 591 a `0x8005CE20`, 590 submits a `0x8005C4F0`, 289 al
  loader) **siempre encuentran a tid 0/tid 17 encolados** porque en el port los eventos externos y
  las completaciones dirigidas llegan de forma asíncrona (no sincronizados con el yield del hilo
  principal como en hardware). Por eso el yield no es un no-op: cuesta un round-trip completo.
- En el original (BizHawk/mupen) los hilos de mayor prioridad están bloqueados en eventos de
  hardware en el momento del yield; el frame cae exactamente cada 2 VI (medido en Fase 0).

## 3. Gate `[0x8005CD4C]` (segunda pregunta del work order)

- Residencia medida (run con `[GATE]` timestamps): **0: 26,9% · 1: 49,4% · 2: 23,7%** del tiempo
  (original: oscila 0/1). El dispatcher se salta exactamente cuando `cd4c >= 2`: la fracción de
  frames sin dispatcher ((1700-1250)/1700 ≈ 24%) coincide con el 23,7%.
- Cadena de un submit: tid 5 (`FUN_80000ed0`, flag `0x40`, 1:1 con el dispatcher) → cola
  `0x8005C4F0` → tid 17 (gate) → `0x8005C528` → tid 16. La completación tarda **~60-83 ms de media**
  (p90 ~146 ms) en volver a tid 16, más que el intervalo entre submits (~61-68 ms) → siempre hay
  1-2 tasks en vuelo (`cd4c` 1-2). No se ven completaciones perdidas: `send`/`recv` cuadran 1:1.
- Conclusión: `cd4c` elevado es **consecuencia** del mismo atasco de scheduler (la completación pasa
  por 2 hilos de mayor prioridad que preemptan a tid 5), no de un task sin completar.

## 4. Descartado con medición

- **Render/llvmpipe**: `HH_RES=original` solo mejora ~7% (frame 20,7/s vs 19,3/s; submit ~61 ms vs
  68 ms). La latencia de completación (60-165 ms) no es rasterización.
- **Audio**: tasks 60/s, 0,4 ms de media (`hh_rsp.log`), sin esperas asociadas.
- **Coste guest**: tid 5 corre ~13,6 ms/frame de trabajo real; cabe en el presupuesto de 2 VI.
- **Espera de VI**: el frame no está enganchado a VI; los gaps son irregulares (0-9 VI). Los
  mensajes VI (msg `0x29A`) los consume tid 19 a 60/s clavados.

## 5. Instrumentación nueva (runtime local, **sin commitear**)

En `port/HybridHeavenRecomp/lib/N64ModernRuntime` (arbol local con cambios previos de sesión):

- `hh_time_now()` (reloj monotono compartido, recomp.cpp) + `hh_guest_ra()`.
- `[TRACE]` con `t=` y `tid=`; `[GATE]`, `[GATE2]`, `[SUBM]` con `t=`.
- `hh_sched.log`: `park`/`rntw`/`swap` con `ra=` guest.
- **`HH_WAITLOG=1`** → `hh_wait.log`: envios/bloqueos/desbloqueos con `t`, `tid`, `mq`, `dt`
  (`HH_WAITLOG_MQ=hex,...` filtra colas; `all` = todas). Bajo volumen, no altera el pacing.
- `HH_MQLOG_ALL`: ahora en buffer (flush cada 1024 líneas) y con filtro `HH_MQLOG_MQ`;
  `HH_MQLOG_FLUSH=1` restaura el flush por línea. **Aviso**: aun filtrado, MQLOG_ALL puede atascar el
  juego (livelock sensible al timing; `pending_ext` crece). Usar `HH_WAITLOG` para pacing.

## 6. Candidatos de Fase 2 (orden sugerido, uno por pasada)

1. **`check_running_queue` en ops de cola** (causa raíz medida): A/B quitándolo de
   `osSendMesg/osJamMesg/osRecvMesg`, o hacer que solo ceda ante prioridad **estrictamente mayor**, o
   que no ceda si el hilo encolado lleva <1 tick. Métrica: gap de frame (objetivo 33 ms) y `polls`.
2. **Prioridad del pump/VI (tid 0, pri 254)**: revisar si debe reencolarse a 60/s o solo cuando hay
   trabajo real; cada cesión a tid 0 cuesta 25,7 ms de mediana.
3. **Gate/`cd4c`**: si tras (1) sigue habiendo 24% de dispatcher saltado, revisar la cadena
   tid 17/tid 16 (completación DP) y el `sp_complete` sintético.
4. **Audio/SP** (`HH_SP_SHARED`, `HH_AI_QUEUE_REPORT=full`, `HH_AI_SPEED`): sin evidencia de ser el
   cuello en Linux; probar después de (1) y solo si la métrica no se mueve.

## 7. Artefactos

- `port/HybridHeavenRecomp/build_dbg/`: `hh_trace.log` (con `t=`/`tid=`), `hh_wait.log`,
  `hh_sched.log` (con `ra=`), `hh_state.log`; `work/debug/fase1_ts.log` (GATE/GATE2/SUBM con `t`),
  `work/debug/fase1_filtered.log`, `work/debug/fase1_light_stdout.log`.
- Comando base Fase 1:
  ```sh
  HH_NOAUDIO=1 HH_TRACE="0x80001454:frame,0x80005270:disp" HH_STATE_SECS=5 HH_WAITLOG=1 \
    timeout -s KILL 45 "./Hybrid Heaven Recomp"
  ```

## 8. Hallazgo colateral

- El juego puede **colgarse/crashear de forma determinista ~VI 5100 (~85 s)** en attract; con
  instrumentación pesada el punto se adelanta (p.ej. `polls` congelado en 428). Consistente con el
  bloqueante CaC de corrupción de estado. No es pacing, pero conviene re-test tras Fase 2.

## 9. Siguiente

Fase 2, candidato (1): A/B de `check_running_queue` en las ops de cola (una variable por pasada,
medir gap de frame + `polls` + `[GATE] cd4c`; revertir si no mueve).
