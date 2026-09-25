# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-25.**
> **Rama de trabajo: `main`.** **Issue #3 (HUD de combate en widescreen) CERRADO y validado.**

## Estado

- **Issue #3 CERRADO (v0.4.3)** — el HUD de combate se ancla entero en widescreen también del 2.º
  combate en adelante:
  - **POWER/STAMINA**: hash de contenido (`d820d8e`).
  - **Disco plateado del radial**: hash + caja exacta `27,19,59,51` (32×32).
  - **Barra de combo**: 4 `G_FILLRECT` en la fila `y=28..30`, por **posición**.
  - **Stamina gastada** (v0.4.3): `G_FILLRECT` en `y=34..38`, por **posición**.
  - Detalle, herramienta y errores a no repetir: `notes/2026-09-25-f-hud-combate-contenido.md`.
- Herramienta nueva: **F7 = captura pareada** (traza de un frame → `hh_cap_<n>.log` **+ imagen** de
  la ventana → `hh_cap_<n>.bmp`, mismo instante). Toggles de diagnóstico **F8/F9/F10**. Ver §Método HUD.
- **Pendiente de publicar**: push de `main` (forks primero) y tag **v0.4.3** (ver §Git).

## Bugs abiertos (2026-09-25)

**1. Barra de STAMINA gastada descolocada — RESUELTO (v0.4.3, validado en Windows).**
- Era un **`G_FILLRECT`** en la fila de stamina `y=34..38` (Inspector: `Rect 64,34,92,38`, `Call #3`)
  que `class_of` no clasificaba → quedaba en 4:3 → a la derecha. **Fix**: generalizar el anclaje de
  los rellenos del HUD de combate por **posición** (`uly 24..38`, `lrx<=190`). Ver la nota.

**2. Puerta que parpadea (PAUSADO; CAUSA VERIFICADA 2026-09-25).**
- **Síntoma**: una puerta concreta parpadea entre visible/oculta. **NO** ocurre en **BizHawk** ni
  **Simple64** → es del render (RT64/port), no del juego.
- **CAUSA VERIFICADA por el mantenedor** (A/B en caliente con los toggles F8/F9):
  - `Refresh Rate Mode = Display` (interpolación **ON**) → **parpadea**.
  - `Refresh Rate Mode = Original` (interpolación **OFF**) → **no parpadea**.
  - `Presentation Mode = Present Early` en **ambos** casos → **no influye**.
  - Culpable: la **interpolación** (`RefreshRate::Display`), no el PresentEarly.
- **Detalle**: ver `notes/2026-09-22-fps-y-present-early.md` §Regresión conocida.
- **Opciones de arreglo** (sin decidir): (a) default `original` (mitigación, pierde high fps);
  (b) arreglo quirúrgico con *matrix groups* de RT64 (`gEXMatrixGroupNoInterpolate`) para los draws
  afectados; (c) largo plazo: **desbloquear los fps del juego** (lógica a 60 Hz), épica aparte.

## Tareas siguientes (ver `TODO.md` §Ahora`)

- **PAUSADO (prioridad)**: bug de la **puerta** (bug 2) — probar el A/B **F8/F9/F10** en la puerta
  y ver si **F9** (interpolación) lo arregla.
- **Menú multilingüe / `SALIR` / `IDIOMA`**: rama **`menu-nativo`** (ahead 25, sin push).
- **Widescreen**: falta la **barra HP** y elementos de la derecha (`right`/`stretch`) — re-derivar
  sus identidades con F7 (captura pareada).
- Resto del backlog de `TODO.md`.

## Método HUD

- **Lista de validación**: solo Windows (build release GUI). Linux headless solo compila.
- Trazas a fichero junto al exe: `HH_HUD_TRACE=1`, `HH_HUD_REWRITE_TRACE=1`, `HH_HUD_SCISSOR_TRACE=1`,
  `HH_FULL_FRAME=0` (off), `HH_NO_HUD_REWRITE=1` (off), `HH_MAP_CROP=<px>`.
- **Atajos de diagnostico** (A/B en caliente):
  - **F7 = captura pareada**: traza de identidades 2D de UN frame → `hh_cap_<n>.log` **+ imagen** de
    la ventana → `hh_cap_<n>.bmp`, en el mismo instante. Otro F7 la cancela. `HH_HUD_TRACE=1` sigue
    volcando traza continua a `hh_hud.log`.
  - **F8 = PresentEarly** ON/OFF (RT64: PresentEarly ↔ SkipBuffering).
  - **F9 = interpolación** ON/OFF (RT64: `RefreshRate` Display ↔ Original; ver bug de la puerta).
  - **F10 = reescritor HUD** ON/OFF (`HH_NO_HUD_REWRITE`).
- **Regla**: la **dirección RDRAM no es identidad**; usar **hash de contenido** (+ caja/posición
  cuando el hash se reutiliza). **No fiarse del color**: la barra de combo pasa rojo→azul y parpadea,
  y RT64 pinta el relleno con el **PRIM color** (la traza lee `fill_color=0`).
- El **Inspector de RT64** (`HH_DEVELOPER=1`, F1) fue clave: muestra el `Rect` y el `PrimColor` del
  draw bajo el cursor.

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
```
(La build **no siempre** refresca el `.exe`: comprobar su fecha; si no cambia, borrar
`build\windows` y recompilar desde cero. Verificado que sale `=== LISTO ===` pero a veces no
actualiza el ejecutable.)

## Git

- **`main`**: commits del cierre del issue #3 + v0.4.3, **sin pushear**. Publicar: forks primero
  (N64Recomp, N64ModernRuntime), luego `main` (es fast-forward, no hace falta `--force`) y tag
  **v0.4.3** (ver `AGENTS.md` §Push).
- **`menu-nativo`**: work del menú (`SALIR`, `IDIOMA` en AJUSTES, fix reapply idioma), ahead 25.
- No commitear sin validación (regla `AGENTS.md`).
