# 2026-09-15 — Cuelgue del NPC (2ª ronda): completaciones PI perdidas en la cola del loader

> Nota de sesión. **Estado: hipótesis con alta evidencia y fix candidato aplicado (sin validar en
> Windows).** Contexto del fix anterior: `notes/2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md`.

## 1. Qué cambió respecto a la ronda anterior

- `fa02e24` (`M9_FUN_802169ac` acotado) **sí está en el exe**: `hh_stub.log` **no se creó** (ningún
  `do_break` ejecutado) y las 8011 lecturas PI del loader salen `region=rom`.
- El cuelgue **persiste pero con sintaxis distinta**: el watchdog de input **sí dispara**
  (`polls parados 15.0s / audio parado 0.0s`), o sea el hilo de juego se aparca mientras el audio y
  el VI siguen.
- Pista del usuario: el objeto del NPC rota pero **no** anima la escala; el atasco coincide con la
  escena del objeto.

## 2. Evidencia de la corrida instrumentada (14:1x)

Ficheros nuevos junto al exe: `hh_state.log` (snapshots cada 5 s), `hh_ovl.log`, `hh_stub.log`
(no creado), `hh_pi.log` con `t=` y tope 32 MB, `hh_hang.log` + `hh_hang_rdram_20068_0.bin`.

- `hh_state.log`: `polls` deja de subir entre t=110 (3151) y t=115 (3158); a partir de ahí
  constante. `audio` y `vi_ticks` siguen subiendo 60/s. El hilo de juego está aparcado, no hay
  busy-loop.
- `hh_hang.log`: `ctxN` (registros congelados) con `r4=8005C268 r5=0 r6=1` = llamada
  `osRecvMesg(mq=0x8005C268, NULL, block=1)`.
- La cola `0x8005C268` está **vacía** (`validCount=0`) y su `blocked_on_recv` = 0 en el volcado.
- El `OSIoMesg` de esa ruta vive en `0x8005CD80` (constante del wrapper `FUN_80001F30`):
  `retQueue=0x8005C268`, `dramAddr=0x800631B0`, `devAddr=0x008DE22E`, `size=0x30`.
  - Ojo: `0x008DE22E` **es una dirección ROM válida** (< 16 MB); la ronda anterior la llamó
    "basura" por error. La última lectura a esa cola (`t=109.821`, `dev=108DE22E`) **completó**.
- `hh_ovl.log`: a t≈76 se cargan los módulos de la escena (7/54/23/24/25/99/8/9/10/12/55); el
  atasco llega ~35 s después, al empezar la secuencia del objeto.
- No hay ninguna línea `region=DESCONOCIDA` ni `[MQDROP]` (el `[MQDROP]` se añadió después).

## 3. Mecanismo (hipótesis principal)

`FUN_80001F30` es un helper síncrono de lectura ROM: escribe el mb estático de `0x8005CD80`,
llama `osEPiStartDma` y hace `osRecvMesg(0x8005C268, …, block=1)`. La cola tiene
**`msgCount=1`** y es compartida por todos los llamadores del helper.

Las completaciones de PI se entregan vía `enqueue_external_message_src(..., Pi)`, que usa
`requeue_enabled[Pi]`. Ese bit quedaba a **false** (nadie llamaba a `set_message_queue_control`
con otro valor; el default del struct es `requeue_pi = false`). En `dequeue_external_messages`,
si `do_send` falla (cola llena) y `requeue_if_blocked=false`, **el mensaje se descarta**.

Con dos hilos usando el helper a la vez (los dos "sabores" de `dram`/`dev` que se intercalan en
`hh_pi.log` lo sugieren):
1. A y B lanzan sus DMA; hay 2 completaciones pendientes.
2. Un `osRecvMesg` de B drena las 2: la 1ª entra en la cola (msgCount=1), la 2ª se descarta.
3. B consume la 1ª; A se queda bloqueado para siempre esperando una completación que ya no existe.

Es compatible con todo lo observado: cola vacía, hilo en `osRecvMesg`, audio/VI vivos, y ausencia
de nuevos `[PI]` (A no vuelve a pedir DMA).

## 4. Fix aplicado (a validar en Windows)

- `port/HybridHeavenRecomp/src/main/main.cpp`: `configuration.message_queue_control.requeue_pi =
  true;`. Con eso la completación no se pierde: queda pendiente y se reintenta en el siguiente
  `dequeue_external_messages` (lo llama el bucle de `do_recv` del hilo bloqueado). Es el mismo
  comportamiento que ya tenían por defecto Timer/SP/SI/DP.
- No cambia la identidad de los mensajes (son `0`): el wrapper solo necesita que el **número** de
  completaciones cuadre con los `start`.

## 5. Instrumentación añadida (para confirmar/descartar)

- `[MQDROP]` por stderr cuando un mensaje externo se descarta por cola llena (100 avisos).
- `hh_pi.log` ahora incluye `tid=` (id del hilo de juego) → si en la próxima corrida hay dos
  `tid` distintos usando `mq=8005C268`, la concurrencia queda confirmada.
- `hh_state.log`/`hh_stub.log`/`hh_ovl.log` siguen activos.

## 6. Pendiente

1. Recompilar en Windows y repetir la entrega del objeto.
2. Si se arregla: seguir con el TODO (botón X de combate, SEGV de cierre, guardado).
3. Si persiste: mirar en `hh_pi.log` los `tid` de `mq=8005C268` y si hay `[MQDROP]`; valorar
   entrega dirigida (como SP/DP) para PI.
