# Menú: sombras (flecha y marcas) y nombres de las capas de marcas (Set A)

> Sesión 2026-09-26 (c), rama `menu-nativo`. Implementa las tareas 8 y 9 del backlog del menú
> (analizadas en `notes/2026-09-26-b-menu-idioma-configuracion-y-sombras.md` §3) y ordena los
> ficheros de marcas. **Validado en Windows** por el mantenedor (flecha, sombra de marcas y z-order).

## 1. Sombra de la flecha de cursor

`append_native_cursor` (`src/hooks/menu_overlay.cpp`) dibujaba la flecha con **rectángulos sólidos**
(`frame.panels`) de un color, sin la sombra +1,+1 que lleva el texto. Ahora se pintan **primero** los
mismos rectángulos desplazados **+1 px derecha / +1 abajo** con el nuevo color `kShadow`
(`rgba(0,0,0,255)`) y **encima** la flecha.

## 2. Sombra de las marcas (tildes y `· Æ Œ`)

- `tools/text/menu_marks.py` (`from_layer`) generaba las marcas **solo con tinta (nivel 1)**; solo las
  `¿ ¡` de la ruta `AUTO` llevaban sombra. Ahora **todas** pasan por `add_shadow_cell` (**nivel 2**,
  copia +1,+1).
- Los símbolos sueltos `Æ`/`Œ` (7 px de ancho) tocaban el borde derecho de la celda: se desplazan
  **1 px a la izquierda** antes de la sombra (`shift_left`/`touches_right`), para que quepa; el
  overlay re-centra la marca, así que la forma no se descoloca. `·` no lo necesita.
- `include/hh/menu_marks.h` **regenerado desde `assets/fonts/menu_marks_ed.png`**. Verificado que la
  **tinta del mantenedor coincide** marca a marca con el header anterior, que `kMenuChars` es
  idéntico y que todo cabe en la celda (máx. 8×9; `kMarkW=8`, alto 12, `pix[96]`).

## 3. Z-order: las marcas van DEBAJO de la letra

Con la sombra, el primer intento (marca dibujada **después** de la letra en `src/platform/overlay.cpp`)
hacía que la copia +1,+1 pisara la fila superior de la letra y la estropeaba. Ahora, para un carácter
acentuado se emite **primero la marca y después la letra base**: la letra queda por encima y su tinta
manda donde solapan; la sombra de la marca solo se ve en el fondo.

## 4. Nombres de las capas de marcas (Set A)

Se aclaran los roles y se evita que el comando destructivo (`--template`, que escribe la capa **en
blanco**) apunte nunca al diseño:

| Fichero | Rol |
|---|---|
| `assets/fonts/menu_marks_base.png` | plantilla (letras de referencia) |
| `assets/fonts/menu_marks_ed.png` | **diseño del mantenedor (fuente de verdad)**; `--from-layer` lee de aquí |
| `assets/fonts/menu_marks_blank.png` | lienzo en blanco que produce `--template` (antes `menu_marks_layer.png`, vacío y confuso) |
| `assets/fonts/menu_marks_legend.md` | leyenda (texto corregido) |

Referencias alineadas en `tools/text/README_font_sheet.md`, docstring de `tools/text/menu_marks.py` y
la leyenda que genera `write_legend`. Regenerar el header:
`python3 tools/text/menu_marks.py --from-layer assets/fonts/menu_marks_ed.png --out include/hh/menu_marks.h`.

## 5. Ficheros tocados

`src/hooks/menu_overlay.cpp` · `src/platform/overlay.cpp` · `tools/text/menu_marks.py` ·
`include/hh/menu_marks.h` · `tools/text/README_font_sheet.md` · `assets/fonts/menu_marks_*` ·
`TODO.md` · `RETOMAR.md`.