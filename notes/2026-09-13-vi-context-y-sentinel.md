# 2026-09-13 — Sentinel de colas libultra + contexto VI del juego

> Evidencia (continúa `2026-09-13-directorio-nisitenma-y-gate-rsp.md` y su work order).
> Tarea: localizar quién escribe `0x8005C4F0+0/+4` y `0x80049930/40` y decidir el fix.

## 1. Escritores (trazas)

- Emulador (`HH_WPLOG` en `0x5C4E8..0x5C510`, `work/debug/emu_wmq.log`):
  - `0x8005C4F0 = 0x80049930` en **pc 0x80030624**: `FUN_80030610` = **`osCreateMesgQueue` del ROM**
    (desensamblado: `mtqueue=fullqueue=&__osThreadTail`, `validCount=0`, `first=0`, `msgCount`, `msg`).
    `0x80049930` es `&__osThreadTail`; `0x80049940 = __osRunningThread` (n64sym).
  - Después el ROM usa listas con centinela: `__osEnqueueThread` (pc 0x8002780C) y
    `__osDispatchThread` (pc 0x80027824) alternan `mtqueue = 0x8005C9D8 (hilo 17)` / `0x80049930`.
- Port (gdb watch en `0x8005C4F0`/`0x80049940`, `work/debug/port_wmq2.log`):
  - `mq+0 = 0x80049930` escrito por **`FUN_80030610`** (el mismo `osCreateMesgQueue` del ROM, que en el
    port se recompila y ejecuta).
  - `mq+0 = 0x8005C9D8` escrito por `ultramodern::thread_queue_insert` (do_recv, hilo 17).
  - `schedule_running_thread(t_=0x80049930)` desde `do_recv`/`do_send` ⇒ el runtime **programa el
    centinela como si fuera un hilo**: su `state` cae en `0x80049940` (`__osRunningThread`) y el
    `next` del centinela se auto-referencia. Corrupción de hilos/colas confirmada.

## 2. Causa raíz #1 (RESUELTA): semántica NULL vs centinela

El ROM inicializa `mtqueue/fullqueue` con `&__osThreadTail`, pero el runtime
(`ultramodern/src/mesgqueue.cpp`, `do_send`/`do_recv`) asume listas NULL-terminated
(`blocked_on_recv`/`blocked_on_send`). Al primer send/recv saca el centinela de la lista y llama a
`schedule_running_thread(0x80049930)`.

**Fix aplicado** (syms, sin tocar runtime): renombrar `FUN_80030610` → **`osCreateMesgQueue`** en
`config/us_ghidra.syms.toml` y `config/us_combined.syms.toml` (vram 0x80030610, size 0x30). El
nombre ya está en `reimplemented_funcs` (toolchain) y `osCreateMesgQueue_recomp` existe en
`ultra_translation.cpp`, así que las llamadas pasan a la versión del runtime (NULL-terminated, igual
que el resto de la API). No hay punteros a 0x80030610 en la ROM (verificado), así que el rename es
seguro. Pipeline: `python3 tools/recomp.py --config config/game_combined.toml --build`.

**Verificado tras el fix** (`port_vi600.bin`): `mq+0=mq+4=0`, `__osRunningThread=0x80091BF0` (puntero
válido, sin clobber), sin ciclos. El contador pasa de «siempre 2» a oscilar 0↔2 en las ventanas de
carga, pero sigue **descansando en 2**.

## 3. Causa raíz #2 (ABIERTA): el contexto VI del juego nunca se mantiene

Sondeos con `[RND]`/`[GATE]`/`[GATE2]` (instrumentación opt-in local, ver §5):
- `0x8005CD4C` (contador): `0→1→2→1→0→1→2` entre VIS 13 y 85, y **constante 2 desde VIS 85**
  (`work/debug/port_gate.log`). `FUN_80005270` sólo se llama 6 veces (emulador: ~544/15 s).
- `[GATE2]` (recv/send de las colas clave): t17 recibe 3A8/400/458, decrementa 3 veces, recibe el 4.º
  (3A8) y **no vuelve a recibir ni decrementar** (`work/debug/port_gate2.log`).
- `[PUSH]/[POP]/[BCAST]` con tid: t17 (nodo de pila `0x80053BB0`) y t16 (`0x80055BB0`) hacen
  push→broadcast(t19)→pop **≈1 vez por VI** sin avanzar (`work/debug/port_tid.log`).
- `FUN_80035050` (que devuelve `[[0x8004AED0]+4]`, el framebuffer del **OSViContext del juego**)
  devuelve **0x00000000 siempre** en el port (`work/debug/port_fb.log`); en el emulador devuelve
  `0x8038F800` (`0x8004AE70` = `00190001 8038F800 80049990 00013006 8005C560 0000029A…`).
- Trazas de ejecución: en el port `__osViInit`=0 llamadas, `__osViSwapContext`=0,
  `osViSwapBuffer`=2; en el emulador `__osViInit`=1, `__osViSwapContext`=541, `osViSwapBuffer`=427
  (≈54/s, una por retrace) desde `FUN_80034840` (hilo del VI manager del ROM).
  `osCreateViManager` (0x800346C0) está en `reimplemented_funcs` ⇒ el hilo del ROM nunca se crea y
  `__osViInit`/`__osViSwapContext` (des-stubbeados en ADR 0002) **no llegan a ejecutarse**.

**Deadlock funcional**: t17 espera a que cambie el framebuffer (`FUN_80035050`/`osViGetCurrentFramebuffer`
≠ `[msg+0xC]`) para completar la task; el framebuffer sólo cambia si el juego hace swap/retrace
(que depende de que avance el boot); el boot no avanza porque el gate `[0x8005CD4C]>=2` corta el
dispatcher `FUN_80005270`. En el emulador el retrace del VI manager avanza el contexto cada frame y
rompe el ciclo.

## 4. Siguiente paso (propuesto)

Mantener el **OSViContext del juego** y su swap por retrace, sin duplicar eventos VI. Opciones:
- **A (fiel)**: sacar `osCreateViManager` de `reimplemented_funcs` (toolchain, estilo ADR 0002) y
  dejar que el hilo del ROM (`FUN_80034840`) llame a `__osViInit`/`__osViSwapContext`; auditar la
  convivencia con el hilo VI del runtime (¿ambos consumen `0x8005C560`? t19 también espera ahí).
- **B (quirúrgico)**: que las versiones runtime de `osViSetMode`/`osViSetEvent`/`osViSwapBuffer`
  mantengan también el `OSViContext` (`0x8004AE70…`), p. ej. invocando el `__osViSwapContext`
  recompilado (`0x80032360`) tras cada retrace (el runtime tendría que llamar vía `get_function`).
Validación: `[0x8005CD4C]` oscila 0/1, `FUN_80005270` por frame, `fase (u16 @0x80037750)==1`.

## 5. Instrumentación local (runtime gitignored, opt-in)

- `events.cpp` `[RND]` ampliado: `cd4c`, `t17q/t17n`, `t16q`, `mqr/mqs/mqv`, `req` (+0x888), `q158r/v`,
  `t19q`; `[GATE]` log de cada cambio de `0x8005CD4C` con VIS (requiere `HH_VERBOSE=1`).
- `mesgqueue.cpp` `[GATE2]`: recv/send de `0x8005C4F0`/`0x8005C528` con `[msg+8]` y contador
  (`HH_GATELOG=1`).
- `overlays.cpp` wrappers `HH_TBLTRACE=1`: `[SUBM]` (FUN_80000ed0), `[PUSH]/[POP]/[BCAST]`
  (FUN_80000934/984/80000a0c) con tid, y `[FB]` (FUN_80035050).
- gdb: `work/debug/gdb_wmq2.gdb` (watchpoints con backtrace).

Artefactos: `work/debug/{port_gate,port_gate2,port_tid,port_fb,port_wmq2,emu_wmq,emu_vi}.log`.
