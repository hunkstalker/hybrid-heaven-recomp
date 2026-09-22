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
set HH_REFRESH_RATE=display
set HH_PRESENT_EARLY=1
hybrid-heaven-recomp\run_windows_release.bat
```
Mirar `build\windows\bin\Release\hh.log` (`[hh-fps] ...`). A/B con `HH_REFRESH_RATE=original`
(comportamiento previo) y sin `HH_PRESENT_EARLY`.

### Experimento implementado (env-gated, default OFF)

En `src/platform/rt64_render_context.cpp`:
- **`HH_REFRESH_RATE=original|display|manual:<hz>`** → fija `userConfig.refreshRate`. `Display`
  pone el objetivo al refresco del monitor (RT64 interpola/presenta a esa tasa); `Original` = ritmo
  del juego (30 Hz).
- **`HH_PRESENT_EARLY=1`** → llama a `RT64Context::enable_instant_present()` tras el setup
  (PresentEarly en RT64). La referencia tiene `Present Early` + `Refresh Rate Mode: Display`
  (capturas del mantenedor).

Las capturas de la referencia confirman: `Display Refresh Rate (OS): 120`, `Average Present (OS)`
≈ 9.3 ms (**107 FPS**), `Presentation: Present Early`, `Refresh Rate Mode: Display`. Y a la vez
`Update Screen (VI Changed)` y `Display List (API)` ≈ **28-29 FPS** = ritmo propio del juego.

## Pendiente

- Validar `HH_FPS` en Windows.
- Validar el experimento (`HH_REFRESH_RATE=display` + `HH_PRESENT_EARLY=1`): fps, latencia, audio y
  timing. Si va bien, **activar por defecto** (sería cambio visible → *bump* de versión).
- (Opcional) overlay on-screen real → requeriría el Inspector/ImGui de RT64 (`developerMode`), hoy
  desactivado y con F1/F2/F3 en conflicto.
