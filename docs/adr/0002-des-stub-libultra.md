# ADR 0002 — Generar funciones de init de libultra del ROM (des-stubbing)

- **Estado**: Aceptado (2026-09-13).
- **Fecha**: 2026-09-13
- **Contexto relacionado**: `../../notes/2026-09-13-segundo-gate-libultra.md`,
  `../../TODO.md` #13, `../architecture.md` (runtime).

## Contexto

El runtime de N64ModernRuntime **reemplaza por implementaciones C++** (stubs o reimplementaciones)
una lista de funciones de libultra (`N64Recomp::reimplemented_funcs` en
`toolchain/src/N64Recomp/src/symbol_lists.cpp`). Para muchas de ellas el stub es un **no-op**
(p. ej. `osInitialize`) o una versión simplificada que **no escribe las estructuras internas del
juego** (p. ej. `osCreatePiManager` vacío).

Caso observado: el boot del port ejecutaba `osInitialize` y saltaba **toda** la cadena de
inicialización de libultra (`__osGetSR`, `__osSpRawReadIo/WriteIo`, `__osGetCause`,
`__osTimerServicesInit`…). Consecuencia: el juego quedaba en `fase=0` (el loader no iteraba todos
los módulos y el juego no llegaba a construir display lists). En el emulador esas funciones se
ejecutan y escriben estado que el juego **lee directamente**.

## Decisión

**Des-bloquear (generar la versión del ROM) las funciones de init/estado de libultra que el juego
usa como fuente de verdad**, quitándolas de la lista de reimplementadas y recompilándolas:

- `osInitialize`, `__osInitialize_common`
- `osCreatePiManager` (+ split de mid-entry `__osDevMgrMain` en los syms)
- `__osViInit`, `__osViSwapContext`
- `__osGetSR/__osSetSR/__osGetCause/__osSetCause`
- `__osSpRawReadIo/__osSpRawWriteIo`

Se **mantienen** reimplementadas las funciones que el runtime necesita controlar (hilos, colas,
timers, audio, PI DMA, `osGetMemSize` con el fix de 4 MB). Cuando una función del ROM escribe estado
que el runtime también necesita, se replica en el runtime (p. ej. `osSetEventMesg` ahora escribe
`__osEventStateTab` en `0x800CD5F0`).

El stub C++ de `osInitialize` del runtime se renombró a `osInitialize_stub` para evitar el conflicto
de firma con la versión generada.

## Consecuencias

- **Positivas**: el boot del port coincide con el emulador; los estados PI/VI/timers del juego se
  inicializan; menos divergencias de RDRAM (10.659 → 3.854 palabras fuera de módulos/framebuffer);
  la tabla de recursos deja de ser racy.
- **Negativas/Riesgos**: el toolchain queda parcheado (hay que recordar reaplicar el parche si se
  actualiza N64Recomp); algunas funciones del ROM dependen de hardware que el runtime abstrae (se
  limitan a escrituras de registros/estructuras, verificado que no rompen).
- **Operativa**: el ejecutable del tool se llama `N64Recomp` (OUTPUT_NAME de `N64RecompCLI`);
  reconstruir con **`--target N64RecompCLI`**, no `--target N64Recomp` (no relinkea).
  Tras tocar la lista: rebuild del tool → `python3 tools/recomp.py --config config/game_combined.toml --build`.

## Alternativas descartadas

- **Implementar el estado a mano en cada stub** (p. ej. escribir `0x8004AB10…` en C++): frágil,
  duplica la lógica del ROM y hay que descubrir cada escritura por separado (fue el camino previo;
  se agotó).
- **Ignorar el problema** (el juego “no usa” esas estructuras): refutado; el juego las lee.
- **JIT/interpretación dinámica**: descartado (contra el modelo del port, ADR 0001).

## Criterio de salida

La lista de funciones des-bloqueadas queda estable cuando el arranque del port coincide con la
referencia (`emu_ref.sh`) **función a función** en la fase de init. Revisar si en el futuro el
runtime necesita interceptar alguna de ellas (p. ej. por threading): en ese caso, reimplementar
**y replicar** la escritura de estado, no volver al no-op.
