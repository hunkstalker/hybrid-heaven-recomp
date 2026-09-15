# 2026-09-15 — Cuelgue del NPC (3ª ronda): inanición del scheduler (LIFO entre igual prioridad)

> Nota de sesión. **Estado: causa raíz identificada con traza directa; fix aplicado (FIFO entre
> iguales), pendiente de validar en Windows.** Precedentes:
> `notes/2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md`,
> `notes/2026-09-15-cuelgue-npc-completaciones-pi-perdidas.md`.

## 1. Traza que lo demuestra (`hh_sched.log`, corrida 14:53)

El hilo **5** (el loader: lee ROM por la cola `0x8005C268` con `FUN_80001F30`) es el que se queda
aparcado y con él se congela la imagen; el audio sigue (hilo 3 y el ciclo de tareas 16/17/18/19).

Secuencia final del hilo 5 (formato `[SCH] t= … evento tid=N`):

```
t=53.203  next tid=5            ← lo eligen
t=53.203  wake tid=5
t=53.206  queue tid=18
t=53.206  swap from=5 to=18     ← cede a uno de mayor prioridad (normal)
t=53.207  next tid=5            ← lo vuelven a elegir
t=53.207  wake tid=5
t=53.207  swap from=5 to=1      ← cede a OTRO hilo de la MISMA prioridad (0)
t=53.207  signal tid=1
t=53.207  park tid=5            ← última vez que se ejecuta en toda la sesión
```

Después de `park tid=5` no hay ningún `next tid=5` ni `wake tid=5` (16 s hasta el watchdog), mientras
el ciclo periódico de audio/VI sigue encolando hilos de prioridad 12-150. El volcado RDRAM del
`hh_hang` confirma el estado: el hilo 5 tiene `queue=0xFFFFFFFF` (sentinela de `running_queue`), o
sea **encolado pero nunca elegido**.

## 2. Causa raíz

`thread_queue_insert` (upstream, sin cambios hasta hoy) ordena por prioridad descendente con:

```cpp
while (*cur && TO_PTR(OSThread, *cur)->priority > toadd->priority) { … }
```

Con `>` estricto, un hilo nuevo **se inserta delante** de los ya encolados de **igual** prioridad
(LIFO). El ciclo del juego tiene dos hilos a prioridad 0: el 5 (loader) y el 1 (gestor de
eventos/VI). Cuando el 5 cede al 1 (`check_running_queue`, cabeza con `priority >= self`), el 5 se
encola; pero cada vez que el 1 vuelve a ceder/bloquear, se re-encola **delante** del 5. Resultado:
el 5 nunca llega a la cabeza y se queda sin CPU para siempre. En hardware/libultra las prioridades
iguales son **round-robin (FIFO)**, así que el 5 y el 1 deberían turnarse.

Esto explica todo lo observado: la completación PI del loader **sí** llegaba (hilo 5 en
`running_queue`), el audio seguía (otros hilos corren), y la imagen se congelaba (el hilo 5 no
vuelve a producir frames). Los fixes anteriores (M9, `requeue_pi`) eran correctos pero no eran la
causa de este cuelgue.

## 3. Fix aplicado (a validar)

- `ultramodern/src/threadqueue.cpp`: nuevo parámetro `fifo_equals` en `thread_queue_insert`. Con
  `fifo_equals=true` los empates de prioridad se insertan al final (FIFO / round-robin); sin el flag
  se conserva el `>` original de upstream (LIFO entre iguales).
- `ultramodern/src/scheduling.cpp`: `swap_to_thread` (el camino de **ceder el CPU**) inserta con
  `fifo_equals=true`. Así el hilo que cede no se queda detrás de sus iguales para siempre.
- **Intento previo y por qué se descartó**: poner FIFO *global* (afectaba también a las listas
  `blocked_on_recv` de SP/DP/AI) hizo que el port **crasheara al arrancar** en
  `RT64::RSP::drawIndexedTri+0x29A` (`SEGV` en `addr=0x4`, VI=77). El orden de despertar de los
  hilos de tareas cambiaba el reparto de completaciones SP/DP (ruta con historial de races en este
  port). El cambio quirúrgico solo toca el yield.
- `hh_schedlog`: los `fprintf` no llevaban `\n` y `hh_sched.log` salía en una sola línea; corregido.

Nota: `requeue_pi=true` (ronda anterior) se mantiene: es correcto para lecturas síncronas aunque no
fuera la causa de este cuelgue. `[MQDROP]` y `hh_mq.log` siguen activos por si reaparece algo de la
ruta de mensajes.

## 4. Pendiente

1. Recompilar en Windows y repetir la entrega del objeto del NPC.
2. Si funciona: cerrar el objetivo y seguir con el TODO (botón X de combate, SEGV de cierre,
   guardado). Se puede retirar la instrumentación ruidosa (`hh_sched.log`, `hh_mq.log`) o dejarla
   tras un env.
3. Si no funciona: revisar el nuevo `hh_sched.log` (¿se elige `tid=5` tras `park`?) y el resto de
   logs.
