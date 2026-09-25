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

### Implementado: **high frame rate por defecto (desde v0.4.0)**

En `src/platform/rt64_render_context.cpp`:
- **`HH_REFRESH_RATE=original|display|manual:<hz>`** → fija `userConfig.refreshRate`. **Default
  `display`**: objetivo = refresco del monitor (RT64 interpola/presenta a esa tasa). `original` =
  ritmo del juego (30 Hz).
- **`HH_PRESENT_EARLY=0`** desactiva PresentEarly. **Default ON**: `RT64Context::enable_instant_present()`
  tras el setup (PresentEarly en RT64).

**Validado por el mantenedor (2026-09-23)**: RTSS marca **~109 fps** (supera el cap de 60);
F1/Inspector y el resto de atajos OK.

Las capturas de la referencia confirman: `Display Refresh Rate (OS): 120`, `Average Present (OS)`
≈ 9.3 ms (**107 FPS**), `Presentation: Present Early`, `Refresh Rate Mode: Display`. Y a la vez
`Update Screen (VI Changed)` y `Display List (API)` ≈ **28-29 FPS** = ritmo propio del juego.

## Matriz de validación (Windows)

| Caso | Envs | Esperado |
|---|---|---|
| Base | (ninguno) | present ≈ 30 fps (ritmo del juego) |
| Present early | `HH_PRESENT_EARLY=1` | misma tasa, menos latencia |
| Display rate | `HH_REFRESH_RATE=display` | present ≈ refresco del monitor (p. ej. 120), movimiento suave |
| Ambos | `HH_PRESENT_EARLY=1` + `HH_REFRESH_RATE=display` | como la referencia (~107-144 fps) |

Medir con `HH_FPS=1` (en `hh.log`) y comprobar que el **juego sigue a ~30 fps lógicos**. Vigilar
audio, timing y carga de CPU/GPU (no forzar si el equipo no llega).

## Pendiente

- `HH_FPS` validado; high frame rate validado y **activado por defecto** (v0.4.0).
- (Opcional) overlay on-screen propio sin dev-mode (hoy: `HH_DEVELOPER=1` + F1, o RTSS).
- (Futuro) mejorar la interpolación (hints IHLE) y desacoplar audio/pacing.

## Regresión conocida (2026-09-25): geometría que parpadea con interpolación

- **Síntoma**: una puerta concreta parpadea entre **visible/oculta**. **No** ocurre en **BizHawk** ni
  **Simple64** → es del render (RT64/port), no del juego.
- **Verificado por el mantenedor** (A/B en caliente con los toggles **F8** PresentEarly / **F9**
  interpolación):
  - `Refresh Rate Mode = Display` (interpolación **ON**) → **parpadea**.
  - `Refresh Rate Mode = Original` (interpolación **OFF**) → **no parpadea**.
  - `Presentation Mode = Present Early` en **ambos** casos → **no influye**.
  - Conclusión: el culpable es la **interpolación** (`RefreshRate::Display`), **no** el PresentEarly.
- **Causa**: RT64 empareja los *draw calls* entre el frame actual y el anterior (`GameFrame::match`)
  y **interpola** sus matrices hacia los frames intermedios. Si un objeto no empareja bien (o su
  visibilidad/transform salta entre frames), salen frames intermedios incoherentes → parpadeo.
- **Opciones de arreglo** (sin decidir): (a) default `original` (mitigación; pierde el high fps);
  (b) arreglo quirúrgico con *matrix groups* de RT64 (`gEXMatrixGroupNoInterpolate`) para los draws
  afectados; (c) largo plazo: **desbloquear los fps del juego** (lógica a 60 Hz), épica aparte.

Nota: la Captura de pantalla de referencia útil del bug: guardar frames con F7 (captura pareada)
mientras se alterna F9, para ver el frame interpolado.
