# BUG abierto — inventario: recuadro negro detrás de la info de items, desplazado en widescreen (2026-10-05)

> Estado: **abierto**. Reportado por el mantenedor (2026-10-05). Ámbito: port, **anclaje 2D del HUD**
> (`src/hooks/hud_rewrite.cpp`). Clasificación: **regresión de widescreen** (elemento mal clasificado).
> Evidencia: `work/gameplay screenshots/items/` (3 capturas en distintos ratios).
> **PALABRAS CLAVE:** `inventario`, `recuadro negro`, `caja negra`, `fill negro`, `panel de items`,
> `hud_rewrite`, `right_panel_box`, `right_panel_scissor`, `minimapa`, `anclaje`, `widescreen`,
> `desplazado a la derecha`, `ratios`.

## 1. Síntoma (mantenedor)

En el **inventario**, la **caja negra** que va **detrás de la info del item** (nombre, `x N`, `USABLE`)
aparece **anclada a la derecha** y se **mueve con el ratio/aspecto**, en vez de quedarse junto a su
panel. **Es un problema de ancla** (no de tamaño): el elemento **no debía tocarse** pero
**seguramente se ancló por accidente** al anclar el HUD/mapa.

### Evidencia (`work/gameplay screenshots/items/`)

| Captura | Ratio | Qué se ve |
|---|---|---|
| `...2026-10-02 233019.png` | **16:9** | caja negra pegada al borde **derecho**, muy lejos del inventario |
| `...2026-10-05 022054.png` | 4:3 | caja negra a la derecha; el panel del inventario se desplaza |
| `...2026-10-05 022102.png` | 4:3 | igual; la posición de la caja cambia con el encuadre |

La caja debe quedar **junto a su panel** en todos los ratios; hoy **sigue al borde**, no al panel.

## 2. Hipótesis (por qué) — INFERIDO

`hud_rewrite.cpp` ancla elementos 2D por **clase** (`kLeft`/`kRight`/`kAuto`). El **minimapa NO** se
identifica por hash: se ancla **estructuralmente** por su "panel" (un rectángulo negro a la derecha
que no cubre el ancho) con:
- `right_panel_box()` (`src/hooks/hud_rewrite.cpp:161`): mitad derecha, no full-width, dentro de
  pantalla, ≥8 px.
- `right_panel_scissor()` (`:171`): **cualquier** elemento dibujado bajo un scissor con esa forma.
- fills (`case kFillRect`, `:660`): `if (cls == kAuto && fill_colour == 0)` + `right_panel_box` → `kRight`.
- además, elementos `kAuto` bajo scissor de panel pasan a `kRight` (`:527`, `:544`).

**Sospecha**: la caja negra del inventario **casa con `right_panel_box`** (mitad derecha, no
full-width, ≥8 px) → se clasifica como `kRight` → se **ancla a la derecha**. Falso positivo de la
heurística del minimapa (ya reescrita para #7/#13).

## 3. ⚠️ CUIDADO al iterar (lección del mantenedor)

**No repetir el error**: al tocar el anclaje para arreglar esta caja, **se puede estar moviendo OTRO
objeto no visible**. Por tanto:
- Tras **cada** iteración/prueba, si **no** se ven resultados en la caja, **parar y revisar** qué
  otros elementos cambiaron de clase/posición antes de seguir tocando (comparar `HH_HUD_TRACE=1`
  antes/después: qué `fill`/`tex/dl` cambian de `cls`).
- El fix debe ser **quirúrgico**: acotar la heurística del panel **sin** reclasificar el inventario ni
  otros elementos; validar que **minimapa** y **barras del HUD de combate** siguen igual.
- Preferir un criterio **discriminante** (caja/aspecto/posición concretos del minimapa) a relajar
  `right_panel_box`/`right_panel_scissor` en general.

## 4. Pistas para localizarlo

- **Traza 2D del port**: `HH_HUD_TRACE=1` → líneas `[hh-hud]` con `fill:...`/`tex:...`/`dl:...`, su
  `box` y la **clase** calculada; mirar en el **inventario** la identidad del fill negro y su `box`.
- **Inspector RT64** (**F1**, `HH_DEVELOPER=1`): localizar el draw exacto (`Rect`) de la caja negra y
  su scissor.
- Código: `src/hooks/hud_rewrite.cpp` — `class_of()` (`:847`), `right_panel_box`/`right_panel_scissor`
  (`:161`/`:171`), `case kFillRect` (`:660`), y los `if (cls == kAuto && right_panel_scissor())`.

## 5. Direcciones de fix (a decidir con datos)

- **Acotar la heurística del panel**: exigir rasgos del minimapa (aspecto/caja/posición concretos, o
  no solapar el área de la info de items), sin romper el anclaje real del mapa.
- **Exclusión** posicional/por escena de la caja del inventario (dejarla en `kAuto`).
- Asegurar que **no** basta con `right_panel_scissor` para clasificar **cualquier** elemento como `kRight`.

## 6. Validación

- **Windows**: en el **inventario**, la caja negra queda **junto a su panel** en **todos los ratios**
  (16:9 y 4:3); el **minimapa** sigue **anclado** donde toca; sin regresión en las barras del HUD de
  combate (`kLeft` por fila); **ningún otro** elemento cambia de sitio (comparar capturas + `HH_HUD_TRACE`).
- `HH_HUD_TRACE=1` para confirmar que ese `fill` deja de clasificarse como `kRight` y que los demás
  conservan su clase.
