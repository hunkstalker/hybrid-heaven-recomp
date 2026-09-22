# 2026-09-22 — Anclaje del HUD/mapa a los bordes (widescreen, fase 07b)

> Nota de **tarea** (fase 07b). Contexto previo del radar:
> `notes/2026-09-21-anclaje-hud-widescreen-radar.md`. Fix del rect negro del mapa:
> `notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`.

## Qué es la fase 07b

Con widescreen (`aspect=auto`/`expand`), el 3D llena la ventana pero el HUD/mapa 2D se dibuja bajo
proyección 320x240 y queda en la zona 4:3 sin anclar. **Fase 07b** = anclar cada elemento al borde
que le corresponde (izquierda / derecha / stretch) reescribiendo las display lists.

## Implementación

- **`src/hooks/hud_rewrite.cpp`**: copia cada DL a un scratch de RDRAM e inserta GBI extendido de
  RT64 alrededor de cada elemento clasificado (`left`/`right`/`stretch`/`spill`).
- Identidades con hash (`include/hh/hudid.h`); tabla fija en `class_of()`.
- Enganche en `send_dl` (`src/platform/rt64_render_context.cpp`).
- **Off**: `HH_FULL_FRAME=0` (widescreen snap), `HH_NO_HUD_REWRITE=1` (anclaje).
- Traza: `HH_HUD_TRACE=1` / `HH_HUD_DRAWS_TRACE=1` / `HH_HUD_SCISSOR_TRACE=1` → `hh.log`.

## Estado (2026-09-22)

| Elemento | Estado |
|---|---|
| Radar (`left`) | ✅ anclado (09-21, Linux + Windows) |
| HUD combate POWER/STAMINA (`left`) | ✅ anclado |
| **Mapa contenido** (`right` + scissor panel) | ✅ anclado y recortado |
| **Mapa fondo negro** (`right` + fill) | ✅ **validado 2026-09-22** (ver nota de fix) |
| Barras HP y demás `right`/`stretch` | ⬜ re-derivar identidades con `HH_HUD_TRACE=1` en combate/diálogos |

## Gotchas

- El fondo del mapa se dibuja **después** del contenido; su viewport vigente es el del último
  elemento (por eso el fill reemite coords del panel canónico, no el DL tal cual).
- Scissor del panel (`map_panel_w0/w1`): se fija una vez por frame del primer `right` cuyo scissor
  NO cubra todo el ancho; se reutiliza para fondo y contenido.
- Origen RIGHT en RT64: en `lrx`, **más positivo = más a la derecha**.
- El quad del fondo está **prohibido** (ver nota de fix / RETOMAR §2).
