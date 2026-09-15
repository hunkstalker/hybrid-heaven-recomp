# 2026-09-15 — Cuelgue del NPC (6ª ronda): desbordamiento de pila + sombra host del scheduler

> Nota de sesión. Cierra la cadena de diagnósticos del día (M9 → requeue PI → scheduler FIFO →
> struct de hilo → mid-entry `0x80380010` → **stack overflow**). Precedentes en `notes/`.

## 1. Evidencia (watchpoint + ring de llamadas)

- `hh_watch.log` (watch sobre `0x80059D80`, el struct del hilo 5): los accesos son **escrituras de
  pila** del propio hilo (`sw a0, 0(sp)` con `sp=0x80059DA0`), y todo el bloque profundo ocurre en
  ~0,55 s durante la secuencia del objeto.
- Presupuesto de pila del hilo 5: tope `0x8005BF20`, struct en `0x80059D80` → ~0x2170 bytes útiles.
  La pila baja a `0x80059C60`-`0x80059D28` → **pisa su propio struct**.
- `hh_ring.log` (ring de las últimas 96 llamadas con `sp`): la cadena activa en el fondo solo suma
  ~0x860 bytes (9 frames), pero el `sp` está ~0x2000 por debajo del tope → hay frames "ocultos"
  (llamadas en cola con marcos que no vuelven) que consumen pila. En el emulador de referencia el
  struct del hilo 5 está en la *misma* dirección (no es un error de dirección).

## 2. Fix aplicado: sombra host de los campos de scheduling

En vez de seguir cazando el frame oculto (barrido estático de las 34022 tail-calls y análisis de
balance de `sp`: todos los desbalances son pares prologue/epilogue de mid-entries legítimos), se
blinda el scheduler:

- `ultramodern/src/threads.cpp`: registro host `OSThread* → HhThreadShadow {next, priority, queue,
  state, id, sp}` con accesores `hh_sh_*` (declarados en `ultra64.h`).
- `threadqueue.cpp`, `scheduling.cpp`, `mesgqueue.cpp`, `threads.cpp`: **todos** los usos de
  `next/priority/queue/state/id/sp` del `OSThread` pasan por la sombra. Las cabezas de lista
  (`blocked_on_recv`, `running_queue`) siguen en memoria guest; los enlaces se leen/escriben en la
  sombra.
- `osCreateThread` inicializa la sombra (y mantiene las escrituras guest por compatibilidad).
- `thread_queue_remove` reescrito correctamente (upstream solo miraba la cabeza).

Con esto, aunque la pila desborde sobre el struct (o el juego lo reutilice, caso ya visto), el
scheduler no se corrompe: el hilo sigue siendo elegible y la partida no se cuelga. La pila puede
bajar ~0x2100 byte más (hasta el struct del hilo 1, también en sombra) antes de acercarse a BSS.

Smoke Linux (`build_dbg`, Xvfb, 40 s): arranca, menús y scheduling normales, sin errores.

## 3. Pendiente

1. Recompilar en Windows y repetir la entrega del objeto. Objetivo: que la secuencia avance (el
   desbordamiento ya no debe romper el scheduler).
2. Si algo más falla: `hh_state.log` (¿`polls` suben?), `hh_crash.log` (backtrace host) y la consola.
3. Limpieza: cuando esté validado, decidir si se quedan la sombra, `requeue_pi`, `[MQDROP]` y las
   trazas (`hh_sched.log`, `hh_mq.log`, `hh_watch`/`hh_ring` solo con env).
