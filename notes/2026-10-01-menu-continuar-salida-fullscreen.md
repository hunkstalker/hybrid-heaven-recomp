# Menú/vídeo: CONTINUAR sin partidas, SALIDA stepper y pantalla completa ↔ ventana (2026-10-01)

> Sesión 2026-10-01 (5.ª). Rama **`menu-carga-guardado-partida`**. Tres tareas pequeñas pedidas por el
> mantenedor, más una pasada de tildes en comentarios. **Validadas en Windows por el mantenedor** (salvo
> donde se indica `[INFERIDO]`). `[MEDIDO]` = comprobado por logs/build.

## 1. `CONTINUAR` gris y no seleccionable si no hay partidas

**Motivo**: sin ninguna partida guardada, entrar en CONTINUAR lleva a un DATA LOAD vacío (sin sentido).

**Implementación** (`src/subsystems/menu.cpp`):
- `any_game_save()`: `true` si el `.pak` tiene alguna PARTIDA del jugador (`slot_present` en los slots
  `0..game_slot_count()-1` = 0..44). Las **plantillas** (45..73) NO cuentan. No fuerza `load()`: si el
  `.pak` no está cargado (lo carga `rebuild_load_game` al construir el árbol), no hay partidas.
- `build_tree`: `make_item("CONTINUE", Action::Continue, any_game_save())`.
- `refresh_continue_entry()`: re-evalúa la entrada en cada `ensure()` (el `.pak` cambia al guardar/borrar)
  y, si el cursor quedó sobre una entrada deshabilitada, lo mueve a la primera habilitada (la raíz
  siempre tiene NUEVA PARTIDA / SALIR). También lo llama `refresh_load_game()` tras guardar/borrar.
- El overlay ya pinta en gris las entradas `enabled=false`; `move_up/down` las salta (`step_enabled`) y
  `confirm()` no las activa.

**Validación Windows (mantenedor)**: con 0 partidas, CONTINUAR sale gris y el cursor no se posa; al
guardar la primera se habilita.

## 2. `SONIDO → SALIDA` como stepper `< ESTÉREO >`

**Motivo**: era un selector normal que mostraba las 3 opciones (MONO / ESTÉREO / AURICULARES); se quiere
solo la activa, con `< >` (izq → MONO, der → AURICULARES).

**Implementación**:
- `src/subsystems/menu.cpp`: `make_selector_with_action("OUTPUT", {…}, Action::OutputSelect,
  output_default(), /*stepper=*/true)`.
- `src/hooks/menu_overlay.cpp` (bug de centrado, también afectaba a ANTIALIASING): el cálculo de ancho de
  `custom_layout` sumaba TODAS las opciones aunque el selector fuera `stepper`, reservando un ancho que no
  se dibuja y descentrando el menú. Ahora usa `!e.stepper` como el draw.

**Validación Windows (mantenedor)**: SALIDA sale `< ESTÉREO >` y SONIDO queda bien centrado.

## 3. Arranque y paso pantalla completa ↔ ventana (`P. COMPLETA` / F3)

### Investigación `[MEDIDO]`
- La cadena de aplicación es correcta: `video_set_fullscreen` → `set_graphics_config` →
  `RT64Context::update_config` → `app->setFullScreen`. En Linux headless se verificó el ciclo completo
  (flag SDL de fullscreen cambia y `wm` persiste).
- **Por qué "no funcionaba"**: RT64 guarda el rect de la ventana ANTES de entrar a pantalla completa
  (`ApplicationWindow::lastWindowRect`) y lo **restaura** al volver a `windowed`. Como el port arrancaba
  `borderless` a **tamaño de escritorio**, al volver a ventana restauraba una ventana del tamaño de la
  pantalla (parecía que el toggle no hacía nada).
- **Intentos descartados**: (a) redimensionar la ventana con `SDL_SetWindowSize` tras el toggle →
  RT64 se quedaba con el swapchain viejo (render en una esquina, sin borde); (b) crear la ventana
  `borderless` **oculta** a tamaño de ventana y mostrarla al estar RT64 listo → seguía viéndose la
  transición (RT64 la hace visible durante su `setFullScreen`) y **perdía el foco** (SDLK2 no enfoca).

### Solución (port, sin tocar el fork)
`src/platform/support.cpp` (`create_window`):
- `borderless`: se crea **visible ya a tamaño de pantalla** → sin transición y con foco (SDL da foco al
  crear). RT64 solo confirma el estado.
- `windowed`: tamaño por defecto **1280×720 centrada** (o geometría recordada, o `res` concreta), vía
  `hh::video_default_window_size()`.

`src/platform/rt64_render_context.cpp` (`hh::create_render_context`, solo `_WIN32`), justo tras crear el
contexto RT64 (miembros públicos de RT64):
- `g_app->appWindow->lastWindowRect` = rect de ventana deseado y centrado (con `AdjustWindowRectEx`) →
  al volver a ventana RT64 restaura **ese** tamaño, no el de pantalla.
- `g_app->appWindow->fullScreen = (wm != "windowed")` → **sincroniza** el estado de RT64 con la config;
  sin esto el primer toggle quedaba en un no-op (RT64 creía estar en ventana aunque la ventana fuera
  borderless a pantalla completa) y había que hacer un ciclo SÍ→NO para que "enganchara".

**Validación Windows (mantenedor)**: `P. COMPLETA = NO` da una ventana 1280×720 con marco; volver a SÍ
va a pantalla completa; arranque directo a pantalla completa sin transición ni clic para el foco.

> Nota: el arreglo del rect es **Windows-only** (los `#ifdef _WIN32` de RT64). En Linux/Deck,
> `setFullScreen` usa SDL y todavía puede restaurar el tamaño previo (tamaño de pantalla) al volver a
> ventana; pendiente si se quiere 1:1.

## 4. Pasada de tildes (chore)

Corregido `tamano`/`Tamano`/`tamanio` → `tamaño`/`Tamaño` en comentarios/cadenas de `src/`, `include/`
y `tools/` (17 ficheros). Sin cambios funcionales.

## Ficheros tocados
- `src/subsystems/menu.cpp` (CONTINUAR + SALIDA), `src/hooks/menu_overlay.cpp` (centrado stepper).
- `src/platform/support.cpp`, `src/platform/rt64_render_context.cpp`, `include/hh.h` (vídeo/windowed).
- Pasada de tildes: `include/hh{,.h}/…`, `src/hooks/hud_rewrite.cpp`, `src/subsystems/{font,input,save_edit,text,trans_cache,ttf}.cpp`,
  `src/platform/overlay.cpp`, `tools/…`.
- Docs: `docs/menu.md`, `docs/BUILDING_windows.md`, `TODO.md`, `RETOMAR.md`, `PROYECTO.md`.
