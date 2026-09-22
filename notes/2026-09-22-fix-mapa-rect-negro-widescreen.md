# 2026-09-22 — Fix mapa: rect negro vs contenido (widescreen fase 07b)

> Tarea cerrada y **validada en Windows** por el mantenedor (2026-09-22). Continúa
> `notes/2026-09-21-anclaje-hud-widescreen-radar.md` (anclaje del HUD/mapa).

## Síntoma

Bajo widescreen (`aspect=auto`/`expand`), el **contenido** del minimapa (verde + flecha) se salía
por la derecha del **rect negro** del panel (`197,143..277,223`). Tras el fix B, arriba/izquierda/
abajo ya cuadraban; el residuo era el **ancho del fill negro**.

## Causas y fixes (orden)

1. **Fix B** (sesión previa, commit `cc29772`): el scissor Ortopédico no recibía
   `horizontalMisalignment` → bordes de contenido y rect desfasados ~4 px. Aplicado en
   `lib/rt64/.../rt64_framebuffer_renderer.cpp`. Validado en 3 bordes.
2. **`kMapCropRight` revertido**: error de diagnóstico (el crop derecho ya recortaba bien).
3. **Fill reconstruido con scissor propio**: el `G_FILLRECT` se emite con
   `emit_fill_rect_ext(RIGHT, RIGHT, …)` y, justo antes, un `G_EX_SETSCISSOR_V1` con **las mismas
   coords** del fill (no a pantalla completa, no el del panel). Así RT64 ve `rect` “cubriendo” el
   scissor → `invRatioScale = 1` (sin estragar por aspecto) y el panel no recorta el borde derecho.
   Después se restaura el scissor del panel con `anchored_scissor`.
   - Intento fallido previo: scissor a pantalla completa para el fill → el fill no cubre el scissor
     → `invRatioScale = 1/aspect` → negro **más estrecho** (solo el trozo que faltaba).
4. **Ajuste del ancho** durante la depuración: se probó con una perilla `kMapBgExtendR` (alargaba
   solo `b_lrx` del fill) hasta cuadrarlo; también hubo perillas de fondo (`map_bg_crop`/`map_bg_shift`).
   El valor útil final resultó **0** (el ancho correcto ya lo da el panel + crop), así que **todas
   esas perillas se retiraron** en la limpieza (`cleanup(hud)`).

## Por qué el quad del fondo está prohibido

El contenido del mapa **no es 2D en píxeles**: son triángulos en espacio de mapa con modelview por
elemento. Un quad en píxeles cae fuera; en espacio de mapa **gira con el mapa** («línea negra que
gira»). El fondo es y será **rect**.

## Controles en caliente (conservados)

| Tecla | Efecto |
|---|---|
| `+`/`-` (num.) | `map_crop` — recorte del panel/scissor por lado |

## Validación

- Build Linux OK; rebuild Windows limpio + mapa con **B**.
- Con `map_crop = 1` (default) el negro queda **clavado** donde toca.
- Parches RT64 commiteados en el fork `lib/rt64` (`a8f0a70`); el parche 3 no hace falta.

## Ficheros

- `src/hooks/hud_rewrite.cpp` — fill con scissor propio + `anchored_scissor`
- `src/subsystems/input.cpp` — teclas `+`/`-` (`map_crop`)
- `include/hh/hudrewrite.h` — API `map_crop`
- `lib/rt64/src/render/rt64_framebuffer_renderer.cpp` — misalign Ortopédico + parches 2D
