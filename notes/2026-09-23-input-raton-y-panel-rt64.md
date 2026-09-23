# Input: desactivar ratón→botones mientras el Inspector de RT64 está abierto

> Sesión 2026-09-23. Fix de usabilidad: al abrir el panel de desarrollador de RT64
> (`HH_DEVELOPER=1` + **F1**) y hacer clic para desplegar sus menús, el clic se colaba al juego
> porque `read_input_button()` mapea el botón izquierdo del ratón a **A** (y el derecho a **B**).

## Causa

`src/subsystems/input.cpp` (`read_input_button`) lee `SDL_GetMouseState` y añade `A_BUTTON`/
`B_BUTTON`. Es una lectura de estado (polling), así que aunque RT64 capture el evento SDL para su
Inspector (`Inspector::handleSdlEvent` → `WantCaptureMouse`), el botón físico sigue "pulsado" y se
mete en el juego.

## Fix

Se publica desde el hilo de render si el Inspector está abierto y el input lo consulta:

- `include/hh.h`: `bool hh::dev_panel_open();`.
- `src/platform/rt64_render_context.cpp`: `std::atomic<bool> g_dev_panel_open`; en `update_screen()`
  se actualiza leyendo `app->presentQueue->inspector != nullptr` bajo `presentQueue->inspectorMutex`
  (RT64 ya protege así la creación/destrucción del Inspector con F1). Cambia con log una vez por
  transición.
- `src/subsystems/input.cpp`: el mapeo ratón→A/B solo se aplica si `!hh::dev_panel_open()`.

Alcance: **solo mientras el panel está abierto**; el teclado y el mando no se tocan (y en el futuro
control teclado+ratón el clic izquierdo sigue disponible con el panel cerrado). El criterio es el
objeto `Inspector` (F1 lo crea/destruye); su ventana "Game editor" no tiene botón de cierre propio,
así que objeto presente = panel visible.

## Verificación

- Compila en Linux; smoke con `HH_DEVELOPER=1` (416 display lists, sin SEGV): el camino de
  `update_screen` (lock + lectura) no rompe nada y no cambia el flag si no se pulsa F1.
- **Pendiente de validar en Windows** (visual): abrir el panel (F1), hacer clic en sus menús → el
  juego no debe recibir A; cerrar (F1) → el clic vuelve a mapear a A. En `hh.log` aparece
  `panel de desarrollo ABIERTO/cerrado; input de raton desactivado/activo`.

Archivos tocados: `include/hh.h`, `src/platform/rt64_render_context.cpp`,
`src/subsystems/input.cpp`.
