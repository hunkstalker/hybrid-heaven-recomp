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

## 7. Resolución (2026-09-21) — RESUELTO en Linux

**F0/F1 (reproducido y simbolizado, Linux)**: con `HH_AUTOQUIT=22` bajo Xvfb el cierre da `rc=139`
(SIGSEGV) y `hh_crash.log` con `[CRASH] modulo: ./Hybrid Heaven Recomp +0x12673DB`. `addr2line`
resuelve ese offset a **`func_80001454_2054`** (código recompilado del juego). Backtrace (gdb): el
hilo de **frame** del juego (`func_800011B0_1DB0 → hh_wrap_FUN_80001454 → func_80001454_2054`)
sigue ejecutando durante el apagado. La instrucción que falla es `movslq 0x37764(%rbp),%rax` con
**`rbp` = base de RDRAM** (`0x7de9b5800000`): lee la dirección de juego `0x80037764` **después** de
que `recomp::start` haga `munmap(rdram)` → SIGSEGV.

**Causa raíz**: al salir, el runtime libera RDRAM mientras un hilo de juego aún puede estar
ejecutando código recompilado (que accede a RDRAM). El hilo de frame no se detiene antes del `free`.

**F2 (fix)** — dos partes en el fork `N64ModernRuntime`:
1. `librecomp/src/recomp.cpp`: **no liberar RDRAM al salir** (se elimina el `munmap`/`VirtualFree`
   final). El SO recupera la memoria al terminar el proceso.
2. `ultramodern/src/threads.cpp`: al salir, **el planificador cooperativo deja de despachar hilos**
   (`run_next_thread`/`resume_thread` con `exited` no señalizan; `run_next_thread_and_wait` aparca sin
   tocar el registro-sombra). Sin esto, tras quitar el `munmap` el crash pasaba al **registro-sombra**
   (`hh_sh_find`, UAF de un hilo liberado por el cleaner) desde el mismo hilo de frame.

Commits del fork: `54b076c` (rdram) + `baf9e19` (scheduler); pin en `runtime.lock`.

**Bonus (regresión de la mudanza)**: `gen_runtime_func_table.py` leía el ELF en la ruta vieja
(`elf/hybrid-heaven.us.elf`), así que tras mover los intermedios a `build/recomp/` la tabla salía
**vacía** (0 registros) y MSVC fallaba con C2466. Arreglado (ruta nueva + placeholder MSVC-safe);
ahora registra las **47** funciones del runtime. `sections.cpp` ignora la entrada placeholder.

**F3 (gate)**: Linux `HH_AUTOQUIT` → **`rc=0`, sin `[SEGV]` ni `hh_crash.log`, 3/3 pasadas** (antes
`rc=139`). Pendiente validar el cierre en **Windows** (playtest del mantenedor) — no bloquea.


