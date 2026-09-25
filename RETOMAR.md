# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-25.**
> **Rama de trabajo: `main`.** **Issue #3 (HUD de combate en widescreen) CERRADO y validado.**

## Estado

- **Issue #3 CERRADO (v0.4.2)** — el HUD de combate se ancla entero en widescreen también del 2.º
  combate en adelante:
  - **POWER/STAMINA**: hash de contenido (`d820d8e`).
  - **Disco plateado del radial**: hash + caja exacta `27,19,59,51` (32×32).
  - **Barra de combo**: 4 `G_FILLRECT` en la fila `y=28..30`, clasificados por **posición**.
  - Detalle, herramienta y errores a no repetir: `notes/2026-09-25-f-hud-combate-contenido.md`.
- Herramienta nueva: **F10 = captura pareada** (traza de un frame → `hh_cap_<n>.log` **+ imagen** de
  la ventana → `hh_cap_<n>.bmp`, mismo instante). Ver §Método HUD.
- **Pendiente de publicar**: push de `main` (forks primero) y tag **v0.4.2** (ver §Git).

## Tareas siguientes (ver `TODO.md` §Ahora)

- **Menú multilingüe / `SALIR` / `IDIOMA`**: rama **`menu-nativo`** (ahead 25, sin push). Retomar con
  `git switch menu-nativo` y validar en Windows.
- **Widescreen**: falta la **barra HP** y elementos de la derecha (`right`/`stretch`) — re-derivar
  sus identidades con F10 en las escenas donde aparecen.
- Resto del backlog de `TODO.md` (menú in-game de opciones PC, textos/traducción, etc.).

## Método HUD

- **Lista de validación**: solo Windows (build release GUI). Linux headless solo compila.
- Trazas a fichero junto al exe: `HH_HUD_TRACE=1`, `HH_HUD_REWRITE_TRACE=1`, `HH_HUD_SCISSOR_TRACE=1`,
  `HH_FULL_FRAME=0` (off), `HH_NO_HUD_REWRITE=1` (off), `HH_MAP_CROP=<px>`.
- **F10 = captura pareada**: traza de identidades 2D de UN frame → `hh_cap_<n>.log` **+ imagen** de la
  ventana → `hh_cap_<n>.bmp`, en el mismo instante. Otro F10 la cancela. Es la forma de atar un `box`
  del trace a lo que se ve. `HH_HUD_TRACE=1` sigue volcando traza continua a `hh_hud.log`.
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

- **`main`**: commits del cierre del issue #3 + v0.4.2, **sin pushear**. Publicar: forks primero
  (N64Recomp, N64ModernRuntime), luego `main` con `--force-with-lease` y tag **v0.4.2**
  (ver `AGENTS.md` §Push).
- **`menu-nativo`**: work del menú (`SALIR`, `IDIOMA` en AJUSTES, fix reapply idioma), ahead 25.
- No commitear sin validación (regla `AGENTS.md`).
