# 2026-09-22 — FPS: contador mínimo (`HH_FPS`) y pista `PresentEarly`

> Evidencia de la sesión. Estado/tareas: `TODO.md`. Referencia MIT en `/tmp/opencode/ref-hh`
> (`danielgomesvieira2000/hybrid-heaven-recomp`).

## Contexto

El mantenedor probó la build de la **referencia**: se siente más suave desde la intro y su panel de
desarrollo (F1) marca **~120-144 fps**. En su README, el *high frame rate* figura como **meta
planificada** ("smooth motion up to your display's refresh rate, with the game's own timing"), pero
en la práctica ya presenta a esa tasa.

## Hallazgo: `PresentationMode::PresentEarly`

- La referencia pasa **`ultramodern::renderer::PresentationMode::PresentEarly`** a
  `create_render_context` (`ref-hh/src/frontend.cpp:170-180`; su `RT64Context::enable_instant_present`
  es un **no-op** comentado: "Not wired up yet").
- Su NMR es más nuevo y tiene el *plumbing* de `PresentationMode`; el nuestro
  (`lib/N64ModernRuntime/ultramodern`) solo declara el enum (`config.hpp:60`) y el método virtual
  `RendererContext::enable_instant_present()` (`renderer_context.hpp:85`), pero **nadie lo llama**.
- En **nuestro** port, `hh::RT64Context::enable_instant_present()`
  (`src/platform/rt64_render_context.cpp:329`) **sí** enciende RT64:
  `app->enhancementConfig.presentation.mode = Presentation::Mode::PresentEarly`. Está listo pero
  **sin invocar**.

**Implicación**: la suavidad de la referencia probablemente viene de *present early* (presentar cada
frame en cuanto se dibuja → RT64 interpola y presenta al refresco del monitor) más que de un cambio
en la lógica del juego (que sigue a 30 Hz). Habría que **llamar** `enable_instant_present()` y medir
FPS, latencia y efecto en audio/timing. Riesgo: el modelo de audio va atado al tick de 30 Hz.

## Contador mínimo implementado (opción B)

`HH_FPS=1` → en `hh::RT64Context::update_screen()` se registra en `hh.log`, **una vez por segundo**:

```
[hh-fps] 121.3 fps | 30 display lists en 1.00s
```

- *fps* = tasa real de **present** (llamadas a `update_screen`).
- *display lists* = listas enviadas en ese intervalo (tasa de dibujo del juego).
- Sin overlay ni `developerMode`; espejo del `HH_FRAME_STATS` de la referencia
  (`ref-hh/src/renderer.cpp:256-266`).

Código: `src/platform/rt64_render_context.cpp` (contador `g_hh_dl_count` en `send_dl` +
bloque de log en `update_screen`). Doc: `docs/BUILDING_windows.md` (envs).

## Cómo medir

```
set HH_FPS=1
hybrid-heaven-recomp\run_windows_release.bat
```
Mirar `build\windows\bin\Release\hh.log` (`[hh-fps] ...`). Comparar con `HH_NO_HUD_REWRITE`/aspectos
si hace falta. Para el experimento de `PresentEarly`: invocar `enable_instant_present()` (p. ej. tras
crear el contexto, gateado por env) y comparar fps/latencia.

## Pendiente

- Validar `HH_FPS` en Windows.
- Decidir si `PresentEarly` se activa por defecto (medir fps, latencia, audio/timing).
- (Opcional) overlay on-screen real → requeriría el Inspector/ImGui de RT64 (`developerMode`), hoy
  desactivado y con F1/F2/F3 en conflicto.
