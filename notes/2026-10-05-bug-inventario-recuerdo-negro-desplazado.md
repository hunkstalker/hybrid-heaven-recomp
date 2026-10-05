# BUG abierto — inventario: recuadro negro detrás de la info de items, desplazado en widescreen (2026-10-05)

> Estado: **abierto**. Reportado por el mantenedor (2026-10-05). Ámbito: port, **anclaje 2D del HUD**
> (`src/hooks/hud_rewrite.cpp`). Clasificación: **regresión de widescreen** (elemento mal clasificado).
> **PALABRAS CLAVE:** `inventario`, `recuadro negro`, `fill negro`, `hud_rewrite`, `right_panel_box`,
> `right_panel_scissor`, `minimapa`, `anclaje`, `widescreen`, `desplazado a la derecha`.

## 1. Síntoma (mantenedor)

En el **inventario** hay un **recuadro negro** detrás de la **información de los items** que aparece
**movido a la derecha** en widescreen, en vez de quedarse en su sitio. **No está documentado**;
se sospecha que lo movió sin querer el **anclaje del HUD/mapa**.

## 2. Hipótesis (por qué)

`hud_rewrite.cpp` ancla elementos 2D por **clase** (`kLeft`/`kRight`/`kAuto`). El **minimapa NO** se
identifica por hash: se ancla **estructuralmente** por su "panel" (un rectángulo negro a la derecha
que no cubre el ancho) con:
- `right_panel_box()` (`src/hooks/hud_rewrite.cpp:161`): mitad derecha, no full-width, dentro de
  pantalla, ≥8 px.
- `right_panel_scissor()` (`:171`): **cualquier** elemento dibujado bajo un scissor con esa forma.
- fills (`case kFillRect`, `:660`): `if (cls == kAuto && fill_colour == 0)` + `right_panel_box` → `kRight`.
- además, elementos `kAuto` bajo scissor de panel pasan a `kRight` (`:527`, `:544`).

**Sospecha**: el recuadro negro del inventario (mitad derecha, no full-width, ≥8 px) **casa con
`right_panel_box`** → se clasifica como `kRight` → se **ancla a la derecha** → se desplaza. Es un
**falso positivo** de la heurística del minimapa (que ya se reescribió para issues #7/#13).

## 3. Pistas para localizarlo

- **Traza 2D del port**: `HH_HUD_TRACE=1` → líneas `[hh-hud]` con `fill:...`/`tex:...`/`dl:...` y la
  clase calculada; mirar en el **inventario** la identidad del fill negro y su `box`.
- **Inspector RT64** (**F1**, `HH_DEVELOPER=1`): localizar el draw exacto (`Rect`) del recuadro negro
  y su scissor.
- Código: `src/hooks/hud_rewrite.cpp` — `class_of()` (`:847`), `right_panel_box`/`right_panel_scissor`
  (`:161`/`:171`), `case kFillRect` (`:660`), y los `if (cls == kAuto && right_panel_scissor())`.

## 4. Direcciones de fix (a decidir con datos)

- **Acotar la heurística del panel**: exigir rasgos del minimapa (p. ej. aspecto/caja concreta o no
  solapar el área de la info de items), sin romper el anclaje real del mapa.
- **Exclusión** por escena/posición del recuadro del inventario (p. ej. dejar ese `fill` en `kAuto`).
- Asegurar que **no** basta con `right_panel_scissor` para clasificar cualquier elemento como `kRight`.

## 5. Validación

- **Windows (widescreen)**: en el **inventario**, el recuadro negro queda **en su sitio** (no a la
  derecha); el **minimapa** sigue **anclado** donde toca; sin regresión en las barras del HUD de
  combate (`kLeft` por fila).
- `HH_HUD_TRACE=1` para confirmar que ese `fill` deja de clasificarse como `kRight`.
