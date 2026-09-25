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
- **Publicado**: push de `main` + release **v0.4.3** (2026-09-25) con las notas de
  `docs/releases/v0.4.3.md` ("Combat HUD: stamina depletion bar fix").

## Bug aplazado (interpolación de frames)

**Artefacto de interpolación (puerta + primer jefe del nivel 1) — APLAZADO.**
- **Síntoma**: con `Refresh Rate Mode = Display` (interpolación **ON**) cierta **puerta** parpadea
  entre visible/oculta, y el **primer jefe del nivel 1** muestra geometría incoherente. Con
  `Original` (interpolación **OFF**) **no** ocurre. `Presentation Mode = Present Early` no influye.
  **NO** ocurre en **BizHawk** ni **Simple64** → es del render (RT64/port).
- **Causa**: la **interpolación** de RT64 (`RefreshRate::Display`, v0.4.0): empareja draw calls entre
  frames e interpola sus matrices; con ciertos objetos salen frames intermedios incoherentes.
- **APLAZADO**: la solución de fondo es **desacoplar la lógica del juego del render** (lógica a 60 Hz)
  → épica aparte. Detalle: `notes/2026-09-22-fps-y-present-early.md` §Regresión conocida.

## Tareas siguientes (ver `TODO.md` §Ahora`)

- **EN CURSO (prioridad)**:
  **[issue #7](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/7) — minimapa desanclado
  al inicio del nivel 2-1**. La salud (POWER/STAMINA) **ya se arregló**; queda el **minimapa**.
  Misma familia de causa que el issue #3 (la **dirección RDRAM no es identidad**). Investigar con
  **F7** (captura pareada) + Inspector de RT64.
- **Menú multilingüe / `SALIR` / `IDIOMA`**: rama **`menu-nativo`** (ahead 25, sin push).
- **Widescreen**: falta la **barra HP** y elementos de la derecha (`right`/`stretch`) — re-derivar
  sus identidades con F7 (captura pareada).
- **APLAZADO**: artefacto de interpolación (puerta + jefe) — ver arriba.
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

- **`main`**: **pusheado** (fast-forward) con el cierre del issue #3 y **release v0.4.3 publicada**
  (2026-09-25). `docs/releases/v0.4.3.md` da el título al Release (`release.yml`).
- **`menu-nativo`**: work del menú (`SALIR`, `IDIOMA` en AJUSTES, fix reapply idioma), ahead 25.
- No commitear sin validación (regla `AGENTS.md`).
