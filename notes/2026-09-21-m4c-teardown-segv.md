# 2026-09-21 — M4c: SEGV en el teardown (al cerrar)

> Nota de plan. Es el **último defecto conocido** del hito ya validado (vía ELF/splat, entrada al CaC
> OK). **No bloquea jugar**; el juego solo revienta al **cerrar**. Registrado para no perderlo tras
> cerrar la reorganización (M5). Ver `../TODO.md` y `../RETOMAR.md`.

## 1. Síntoma

- Al **cerrar** el port (cerrar la ventana / `ultramodern::quit()`), **SEGV** en el apagado.
- En Windows: `Hybrid Heaven Recomp.exe +0x12A602` (nota `2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md:65`).
- El `hh_crash.log` de las pasadas de replay es este mismo SEGV de cierre, no un crash de juego
  (`2026-09-17-replay-mode-vi-vis-negativo.md:183`).

## 2. Evidencia y estado

- **Hilos en código de módulo al apagar**: `2026-09-14-geometria-pixeles.md:24-26,34` (SEGV "en hilos
  que siguen ejecutando código de módulo con el estado de cierre", p.ej. `M25_FUN_801e2d94`).
- **Carrera de teardown**: `2026-09-13-workorder-evento-modulo-0x7D.md:64-66` ("sospecha de carrera de
  *teardown*, no del camino de juego").
- `docs/architecture.md` §5: "robustez de cierre (SEGV al teardown en código de módulo)".

## 3. Secuencia de apagado (a vigilar)

1. SDL_QUIT / `HH_AUTOQUIT` → `ultramodern::quit()` (`src/subsystems/input.cpp:451-468`).
2. Sale el bucle `while (!exited)` de `recomp::start` (`lib/N64ModernRuntime/librecomp/src/recomp.cpp:2006`).
3. `graphics_shutdown_ready.signal()` (recomp.cpp:2013) → el hilo de eventos hace
   `renderer_context->shutdown()` (RT64 `app->end()`) (`ultramodern/src/events.cpp:797-799`).
4. `game_thread.join()` + `join_event_threads()` + `join_thread_cleaner_thread()` + `join_saving_thread()`
   (recomp.cpp:2015-2018).
5. `VirtualFree(rdram)` (recomp.cpp:2024).

Hipótesis: (a) hilos de juego aún ejecutando **código recompilado de módulo** durante 3-5 (acceso a
`rdram`/estado ya en teardown); (b) **orden de deinit** RT64/runtime; (c) el handler de Windows
devuelve `EXCEPTION_EXECUTE_HANDLER` (`src/platform/main.cpp:696`), relacionado en el TODO con el orden
de deinit.

## 4. Instrumentación disponible

- **`HH_AUTOQUIT=<s>`** (`src/subsystems/input.cpp:451`): dispara `quit()` sin interacción → reproduce
  el teardown headless (Linux/Xvfb).
- **`hh_crash.log`**: incluye `[CRASH] host backtrace (exe+0x...)` (`main.cpp:685-690`) → el
  `+0x12A602` es un frame de esa pila.
- **`.map`**: `CMakeLists.txt:11-12` emite `/MAP:...HybridHeavenRecomp-<config>.map` (MSVC) → resuelve
  `exe+0xNNNN` a función.

## 5. Plan (fases con gate)

- **F0 — Reproducir en Linux**: `HH_AUTOQUIT` + Xvfb → confirmar SEGV de cierre y sacar **backtrace con
  gdb** + `hh_crash.log`.
- **F1 — Mapear**: resolver `0x12A602` en el `.map` del build Windows que crasheó y comparar con el
  frame simbólico de Linux; identificar el dueño (port / runtime / RT64 / llamada a módulo en teardown).
- **F2 — Arreglar** según categoría: orden de deinit (parar/sincronizar hilos antes de `shutdown()` y
  de liberar `rdram`), o el join de hilos que siguen en código recompilado, o el handler.
- **F3 — Gate**: cierre limpio (ventana y `HH_AUTOQUIT`) **sin SEGV** en Linux y Windows, sin regresión
  de arranque/título.

## 6. Dependencias

- Para F1 se necesita el `.map` del build Windows **o** la reproducción del cierre con su
  `hh_crash.log`. Sin eso, F0 (Linux) da el mismo frame de forma simbólica.
