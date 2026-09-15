# 2026-09-15 — Cuelgue del NPC (4ª ronda): struct del hilo reutilizado → crash al aparcar

> Nota de sesión. Tras el fix FIFO-al-ceder (ronda 3) el cuelgue desaparece, pero aparece un **SEGV**
> al recibir el objeto. Esta nota documenta la causa y el blindaje aplicado. Precedente inmediato:
> `notes/2026-09-15-cuelgue-npc-scheduler-fifo.md`.

## 1. Síntoma y volcado

- Release: `SEGV` en `Hybrid Heaven Recomp.exe +0x939366` = `moodycamel::LightweightSemaphore::wait+0x6`,
  fault `0xFFFFFFFFFFFFFFFF`, `rcx` basura (`0x4010C48041CA0010`), con contexto guest del hilo
  loader (`r4=8005C268` = cola `osRecvMesg`). Reproducible dos veces (VI=2497 y VI=2897).
- `hh_crash_rdram_27528_0.bin`: el struct del hilo 5 en `0x80059D80` está **pisado por floats del
  objeto** desde +0x1C:
  ```
  +0x00: 00000000 00000000 FFFFFFFF 00000000   (next/pri/queue/pad intactos; id=5 en +0x14)
  +0x1C: 41DA3080 41CA0000 412E4700 41740000   (antes: context high/low, sp)
  +0x2C: C1218E80 C157BFF0 ...
  ```
  El `context` de host (antes `0x015C11C7C920`) quedó como dos floats (`0x4010C48041CA0000`), que es
  exactamente el `r14`/`rcx` del crash.

## 2. Mecanismo

Al aparcar, el runtime leía el contexto propio del struct **guest**:

```cpp
UltraThreadContext* cur_context = TO_PTR(OSThread, thread_self)->context;  // threads.cpp
wait_for_resumed(cur_context);   // → cur_context->running.wait()
```

Si el juego destruye el hilo y reutiliza su struct (los floats del objeto), esa lectura devuelve
basura y el `wait()` revienta sobre un semáforo inválido. La ronda 3 hizo que el hilo 5 volviera a
correr, así que llegó a este punto (antes se quedaba inanido y se veía como cuelgue).

## 3. Blindaje aplicado (a validar)

Primer intento (insuficiente): `thread_local self_context` + leer el struct solo como fallback. El
siguiente crash lo dejó claro: el backtrace host señaló

```
run_next_thread+0x6D → run_next_thread_and_wait+0x109 → do_recv+0x2EC → osRecvMesg+0x97 →
osRecvMesg_recomp+0x8F → FUN_8001fba8 (guest) → run_thread_function → _thread_func
```

es decir, **otro** hilo sacaba de la cola de listos al hilo pisado y ejecutaba
`to_run->context->running.signal()` sobre el puntero basura (`rbx=0x4002E00041CA0000`). El campo
`context` guest no sirve para *señalizar a otros hilos*.

Fix definitivo — registro host:
- `threads.cpp`: `std::unordered_map<uintptr_t, UltraThreadContext*> hh_ctx_map` (clave = `OSThread*`
  host) con `hh_ctx_register/get/unregister`. Es la **fuente de verdad** del contexto de cada hilo.
- `osCreateThread` registra antes de lanzar el host thread; `CleanupGuard` desregistra al terminar;
  `osDestroyThread` desregistra + señaliza; `resume_thread`/`run_next_thread` señalizan usando el
  mapa (nunca el campo guest); `wait_for_resumed` compara contra el mapa para autodestruirse si el
  hilo fue destruido/reemplazado.
- Se mantiene `self_context` (thread_local) para el contexto propio al aparcar.
- Trazas de ciclo de vida en `hh_sched.log`: `create`/`start`/`stop`/`destroy`/`self-destroy`.
- `src/main/main.cpp` (handler Windows): **host backtrace** (`CaptureStackBackTrace`) en
  `hh_crash.log`/consola, mapeable con el `.map`.

Smoke Linux (`build_dbg`, Xvfb, 40 s): arranca y corre sin crashes; los 9 hilos se crean como siempre
y el scheduler sigue estable.

## 4. Pendiente

1. Recompilar y repetir la entrega del objeto. Mirar en `hh_sched.log` si aparece `destroy tid=5`
   (confirma que el juego destruye el hilo) y si el juego sigue tras la secuencia.
2. Si vuelve a crashear: `hh_crash.log` ya trae el backtrace host → mapear con
   `build_win/HybridHeavenRecomp-Release.map` (o build Debug para asserts/valores).
3. Si el hilo murió y el juego se queda a medias: revisar por qué el juego lo destruye antes de que
   termine su trabajo (posible desajuste de sincronización heredado).
