# 2026-09-11 — 9d: `terminate called without an active exception` — RESUELTO

> Evidencia de sesión. No editar.

## Causa real (no era una carrera)
El abort **coincidía exactamente con el `timeout`/SIGTERM** (20 s → vis=1200, 35 s → 2100, 90 s → 5400;
es decir, siempre en el apagado). El juego **corre indefinidamente** hasta que se le manda SIGTERM.
La conclusión previa de "race" fue errónea (gdb también corría hasta *su* timeout).

Cadena (backtrace con stack intacto):
```
poll_input (src/game/input.cpp)  -> std::exit(EXIT_SUCCESS)   <- en SDL_QUIT
  -> __funcs_on_exit
     -> ~save_context (pi.cpp): std::thread::~thread(saving_thread)  [joinable]
        -> std::terminate  -> abort
```
Dos bugs de apagado:

1. **`hh::poll_input()`** (SDL_QUIT) llamaba **`std::exit(0)`** directamente → corrían los
   destructores estáticos → `~std::thread` sobre `save_context.saving_thread`, aún **joinable**
   (nunca se llamó a `join_saving_thread()`) → `std::terminate`.
2. **`main`** terminaba con `while (true) { SDL_Delay(100); }` (se creía que `recomp::start` no
   retorna). Al usar el cierre ordenado, `recomp::start` sí retorna y `main` colgaba.

## Fix
- `src/game/input.cpp`: en `SDL_QUIT` → **`ultramodern::quit()`** (activa el apagado limpio de
  `recomp::start`, que hace `join` de todos los hilos) en vez de `std::exit`.
- `src/main/main.cpp`: tras `recomp::start` → **`return 0`** (quitado el `while(true)`).

## Resultado
Salida **limpia**: `exit=0`, 0 `terminate`, con `timeout 25` y `timeout 45`.
(Añadido además un safeguard en `~UltraThreadContext()`: nunca destruir con `host_thread` joinable.)

## Notas de método
- Interposers LD_PRELOAD (`__cxa_throw`, `pthread_mutex_lock`, `std::terminate`, `~thread`) fueron
  **inconcluyentes**; el desenrollado del stack tras `terminate` da frames no fiables.
- Lo que resolvió el caso fue detectar la **correlación con el `timeout`** y reproducir el apagado
  de forma determinista, obteniendo el stack **intacto** en el `abort`.
