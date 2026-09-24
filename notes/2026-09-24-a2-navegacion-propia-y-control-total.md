# A2 — Paso 5: navegación propia y control total del menú de título

> Sesión 2026-09-24 (continuación). Implementa el **paso 5** del orden acordado en `RETOMAR.md`:
> navegación propia completa (A/B/X + selectores) y **neutralización del input del handler nativo**.
> Diseño: `docs/menu.md`. Técnica del overlay: `docs/architecture.md` §7.

## Qué se hizo

1. **`feed_menu_navigation`** (`src/hooks/sections.cpp`) pasa de solo arriba/abajo a cubrir todo:
   - `0x800`/`0x400` → `move_up`/`move_down` (cursor).
   - `0x200`/`0x100` → `move_left`/`move_right` (valor del selector lateral).
   - `0x8000` (A) → `confirm()`; `0x2000` (X físico = Z del N64) → `apply()`; `0x4000` (B) → `back()`.
   - Traza gateada por `HH_MENU_TRACE=1`: `[menu-nav] btn=… ev=… depth=…` + `describe_current()`.

2. **Control total — input nativo muteado**: se registran overrides de los dos lectores de botones
   del handler nativo (`add_loaded_function`), re-registrados en `register_title_menu_hook()`:
   - `0x801C1340` → `hh_native_dir_input`
   - `0x801C1334` → `hh_native_ab_input`
   Con la bandera `g_mute_native_input` activa devuelven `0`; si no, delegan en el original. El handler
   nativo se sigue ejecutando (mantiene el estado del juego) pero no mueve su cursor ni cambia de
   pantalla. `feed_menu_navigation` llama a los símbolos originales (no a los wrappers), así que lee el
   input real.

3. **Temporizador de inactividad**: el handler nativo decrementa `obj+0x3C` y, al llegar a 0, abandona
   el menú (`goto 0x801C2050`, medido). Con el input muteado nunca se reinicia → la pantalla se cerraba
   sola a los ~8-30 s. Se reescribe a `0x384` (el valor que usa el propio handler) tras cada llamada,
   solo mientras el overlay manda.

4. **`hh::overlay::enabled()`** (`include/hh/overlay.h`, `src/platform/overlay.cpp`): expone el flag
   `HH_OVERLAY`. Con el overlay desactivado **no** se mutea, para no bloquear el menú nativo
   (diagnóstico).

## Cómo se validó (headless, Linux)

Replay poll (`HH_REPLAY_PACE=1`) que espera al título, abre el menú con START y navega. `HH_MENU_TRACE=1`
deja en `hh.log`:

```
[menu-nav] btn=0x0400 ev=1 depth=1   # DOWN  (raíz)
[menu-nav] btn=0x8000 ev=2 depth=2   # A     -> AJUSTES
[menu-nav] btn=0x8000 ev=2 depth=3   # A     -> IDIOMA
[menu-nav] btn=0x0400 ev=1 depth=3   # DOWN  cursor 0->1
[menu-nav] btn=0x4000 ev=3 depth=2   # B     -> AJUSTES
[menu-nav] btn=0x4000 ev=3 depth=1   # B     -> raíz
```

Y con selectores/X:

```
screen=2 kind=Menu cursor=0 applies=1
> CÁMARA LIBRE < NO >
  APUNTADO LIBRE < NO >
[menu-nav] btn=0x0100 ev=1 depth=3    # RIGHT -> < SÍ >
[menu-nav] btn=0x2000 ev=4 depth=2    # X (Applied) -> vuelve a NUEVA PARTIDA
```

Comprobaciones: **0** gotos a `0x801C2050` (el menú ya no se cierra solo), una sola apertura del menú y
una sola ocultada del overlay (al salir). El auto-repeat al mantener una dirección (~10 Hz) es el del
propio motor de input del juego (el handler corre ~30 Hz y el botón se pulsa 1 de cada 3 frames);
nuestra navegación hereda ese ritmo, como el menú nativo.

## Pendiente

- **Validar en Windows** (build release): navegar raíz → submenús, A/B/X, selectores, y confirmar que
  el menú nativo no responde y no se cierra solo.
- **Paso 6**: acciones (mapear cada entrada a la función del juego). Hasta entonces las entradas que no
  son submenú (`CONTINUAR`, `EMPEZAR PARTIDA`, `MODO COMBATE`) no ejecutan nada: el modelo solo cambia
  de pantalla.
- **Paso 7**: SFX desde los eventos del modelo (retirar el puente actual). Con el input muteado, el
  puente basado en el cursor nativo queda en silencio; el paso 7 lo sustituye.

## Archivos

`src/hooks/sections.cpp`, `src/platform/overlay.cpp`, `include/hh/overlay.h`, `docs/menu.md`,
`docs/architecture.md` §7, `RETOMAR.md`, `TODO.md`. Sin commitear (regla: commitear tarea validada;
falta Windows).
