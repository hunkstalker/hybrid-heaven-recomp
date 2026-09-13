# ADR 0003 — Subsistema VI: libultra del ROM, runtime solo como hardware

- **Estado**: Aceptado (2026-09-13).
- **Fecha**: 2026-09-13
- **Contexto relacionado**: ADR 0002 (des-stubbing de init), `../../TODO.md` #14,
  `../../notes/2026-09-13-vi-context-y-sentinel.md`, `../architecture.md` (runtime).

## Contexto

El runtime reimplementa la familia VI (`osCreateViManager` como **no-op**, y
`osViSetMode`/`osViSetEvent`/`osViSwapBuffer`/… manteniendo un `ViState` interno en C++).
`__osViInit` y `__osViSwapContext` ya se generan del ROM (ADR 0002) pero **nadie los llama**:
`osCreateViManager` (que los invoca y arranca `viMgrMain`) está reimplementado.

Consecuencia observada: el `OSViContext` del juego (`0x8004AE70…`, punteros `__osViCurr/Next` en
`0x8004AED0/4`) queda **a cero**. El juego lo lee directamente (p. ej. `FUN_80035050` devuelve
`__osViCurr->framebuffer`) y su hilo de tareas RSP espera un cambio de framebuffer que nunca llega
⇒ el contador `0x8005CD4C` no drena ⇒ el gate de `FUN_80001454` deja de llamar a `FUN_80005270`
⇒ `fase=0`. En el emulador `__osViSwapContext` corre ~54 veces/s (una por retrace) desde
`viMgrMain` y mantiene ese estado. Es la misma clase de fallo que ADR 0002: el juego usa estado de
libultra que el runtime no mantiene.

## Decisión

**Ampliar ADR 0002 a todo el subsistema VI**: generar del ROM las funciones que el juego usa como
fuente de verdad y dejar en el runtime únicamente la emulación de hardware (temporización del
interrupt VI y exposición de registros).

Se quitan de `reimplemented_funcs`/`ignored_funcs` (`toolchain/src/N64Recomp/src/symbol_lists.cpp`):

- `osCreateViManager` (crea `viEventQueue`, registra eventos 7/3, llama `__osViInit`, arranca
  `viMgrMain`)
- `osViSetMode`, `osViSetEvent`, `osViSwapBuffer`, `osViBlack`, `osViSetSpecialFeatures`
- `osViGetCurrentFramebuffer`, `osViGetNextFramebuffer`

`viMgrMain` (`FUN_80034840`) y `__osViGetCurrentContext` (`FUN_800349D0`) ya se compilan del ROM
(los nombres de las listas no coinciden con los syms). El hilo VI del runtime sigue generando el
retrace y entregando el evento al mq registrado por `osSetEventMesg` (ahora el interno
`0x800CE920`); el ROM hace el swap y entrega el mensaje del juego (`0x29A` a `0x8005C560`).

El runtime deja de mantener su `ViState` para el juego: lee los **registros VI MMIO** que escribe
`__osViSwapContext` (`0x04400000+`) para alimentar `ViRegs` (screen update de RT64). `ViState`
queda solo para el modo *dummy* previo al arranque.

`osSetEventMesg` sigue reimplementado (es el punto de entrega del interrupt) y `osViSetXScale`/
`osViSetYScale` se mantienen en el runtime (no los llama el juego).

## Consecuencias

- **Positivas**: una sola fuente de verdad para VI (libultra del ROM); desaparece el no-op de
  `osCreateViManager` y la clase de bug “runtime no mantiene estado libultra”; sin direcciones
  específicas del juego en el runtime; `OSViContext`, `__osViCurr/Next` y los registros VI quedan
  como en el emulador.
- **Negativas/Riesgos**: el toolchain queda más parcheado (mismo riesgo operativo que ADR 0002);
  convivencia de dos consumidores del evento VI (t19 del juego y `viMgrMain`), igual que en el
  emulador; el screen update puede llevar un frame de retraso (se lee el registro tras el swap).
- **Operativa**: rebuild del tool con **`--target N64RecompCLI`**; después
  `python3 tools/recomp.py --config config/game_combined.toml --build`.

## Alternativas descartadas

- **B — mantener el `ViState` del runtime y duplicar el `OSViContext`** (o invocar
  `__osViSwapContext` desde los stubs): mantiene dos fuentes de verdad, obliga a hardcodear
  direcciones de HH y reaparece con el siguiente API interno (ya pasó con `osCreateMesgQueue`).
- **Dejar `osCreateViManager` no-op y solo inicializar el contexto a mano**: parche parcial;
  no mantiene el swap por retrace ni el conteo de retrace del juego.

## Criterio de salida

`OSViContext` no-cero y avanzando por retrace en el port; `FUN_80035050` devuelve framebuffers;
`[0x8005CD4C]` oscila 0/1; `FUN_80005270` se llama cada frame; `fase (u16 @0x80037750)` avanza; RT64
sigue presentando. Comparar contra `emu_ref.sh` los registros VI y el contexto.
