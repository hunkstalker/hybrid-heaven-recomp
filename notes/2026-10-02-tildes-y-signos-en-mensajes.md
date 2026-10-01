# Acentos/`¿`/`¡` en los mensajes del overlay (cápsula DATA SAVE/LOAD) (2026-10-02)

> Sesión 2026-10-02. Rama **`menu-carga-guardado-partida`**. **HECHO y VALIDADO en Windows** (ver §5).
> Objetivo: que el texto de los mensajes del overlay (cápsula de guardado/carga) muestre los **acentos**
> (p. ej. la `í` de `aquí`) y el **`¿` de apertura**, sin romper los signos especiales ya existentes.

## 1. Síntoma (mantenedor)

En la cápsula de guardado, los mensajes del overlay salían sin los caracteres especiales:

- `¿Guardar la partida?` → salía `Guardar la partida?` (sin `¿`).
- `Guardando la partida actual aquí.` → salía `... aqu .` (sin la `í`).

Ambas cadenas SÍ están bien en `assets/lang/es.txt` (verificado en bytes: `\xc2\xbf` y `\xc3\xad`).

## 2. Contexto: DOS sistemas de fuentes/pintado

1. **Motor de texto nativo** (`func_8001D394`/`func_8001BFE4`, ver `src/hooks/text_glyphs.cpp`): los
   acentos del juego inyectado (texto del diálogo in-game) viven en `include/hh/accent_glyphs.h`
   (`hh::kAccentGlyphs`, valores de glifo 200+; se cocinan sobre el `color0` de 8x8). **Estos
   funcionan** (era lo que salía bien).
2. **Overlay del port** (menú + cápsula): dibuja con el **atlas** de `src/subsystems/font.cpp` /
   `src/platform/overlay.cpp`. La fuente `Face::Color4` (8x12, la del mensaje) es la que falla con
   acentos.

## 3. Causa raíz `[MEDIDO]`

La **ROM de color4 solo trae 88 glifos** (`kColor4Values=88`; bloque 2bpp de 44 bloques × 48 B =
2112 B, confirmado leyendo `baserom.us.z64` @ `0x6E4CD6`). **No hay** un "bloque CP437" en la ROM: los
acentos/`¿`/`¡` que se ven en el juego son los **generados** de `hh::kAccentGlyphs` (color0 8x8).

Primer intento (fallido, descartado): mapear `cp >= 0x80` a `value = 88 + (cp-0x80)` contiguo a la
banda color4 → leía fuera de la ROM y **rompía los glifos especiales** (el mantenedor vio
"CANCELAR"/mensajes con signos rotos).

Segundo intento (fallido): cocinar los acentos **dentro** de la banda color4 a partir de la celda 88
→ la banda de color4 en el atlas solo tiene **6 filas (96 celdas)**; las celdas 88..215 se salían de
la banda y **pisaban `color3`/kana**; `face_glyph_uv` devolvía UVs de otra franja → **no se veía nada**.

## 4. Solución (implementada, build Linux OK)

- **Franja propia de acentos** en el atlas (`font.cpp`): `kAccentTop = kColor4Top + kColor4Rows*H`,
  8 filas × 16 celdas (128 codepoints latin-1 `0x80..0xFF`), mismas dimensiones de celda (8x12).
  `kColor3Top` y `kFullHeight` se reubican en consecuencia (atlas 128→579 px, sin solapes).
- **FUENTE = la MISMA que el menú de guardado** (`[MEDIDO]` 2026-10-02, corrección del primer enfoque):
  el mensaje usa `color4` (8x12), así que los acentos NO pueden venir de `hh::kAccentGlyphs` (que son
  glifos **color0 8x8**, otra tipografía). Se usa **`hh::kGameGlyphs`** (`include/hh/game_font_color4.h`):
  glifos **reales de color4 EU** + **compuestos letra-base color4 + marca** (el truco pedido por el
  mantenedor: p. ej. `í` = `i` de color4 con la tilde encima y sin punto), generados por
  `tools/text/build_font.py --style color4`. Cubre todo es/ca/fr/de.
- `bake_atlas` **cocina `hh::kGameGlyphs`** (solo cp latin-1) en esa franja: bloque 8x12 2bpp (valor
  PAR → plano 0xCC, ver `pack_even`); la **sombra se pinta NEGRA** (el generador normaliza el nivel
  3→2, pero aqui NO debe salir gris: las letras color4 de la ROM usan sombra negra).
- `face_glyph_uv(Face::Color4, c)` con `c >= 0x80` → busca en la franja de acentos por codepoint.
- `overlay.cpp`: para `cp >= 0x80` en `Color4` se llama a `face_glyph_uv` (reusa el mismo camino de
  siempre); se **elimina** el hack del `?` girado 180° para el `¿` (ahora el `¿` es un glifo propio,
  con su sombra normal) y toda la lógica CP437.

## 5. Estado / validación

- **Build Linux**: OK. `docs_index.py --check` y `check_translations.py`: OK.
- **Validación Windows parcial (2026-10-02, mantenedor)**: `¿` **OK**, `ó` **OK**; fallaban (a) la
  sombra salía **gris** y (b) la **`í` rota** (parecia una `T` con tilde). Corregido:
  - **(a) sombra negra**: `font.cpp` pinta cualquier nivel `>=2` como negro (el generador normaliza a
    2; antes se mapeaba a gris 140).
  - **(b) `í` (`T` con tilde)**: causa raiz — `extract_mark` tomaba como tope la `bb[1]` de la **letra
    destino**; tras `strip_dot(base,4)` (que quita bien el punto de la `i`) valia 4 y capturaba la fila
    3 del glifo EU, que es la **barra superior del cuerpo** (`###`), no el acento. Arreglo: el acento
    son **siempre** las filas `0..2` del glifo EU (el cuerpo de las minusculas empieza en la fila 3;
    medido en `e/o/a/n/u`, y el tallo de la `i` en la 4), y `strip_dot` se **restaura**.
- **3ª iteracion (2026-10-02, mantenedor)**: `¿` **subido 2 filas** (el rotado del `?` caia en 2..11 y
  su sombra inferior se cortaba); la `í` queda con el **acento 2 px en diagonal** en el sitio del punto
  (se quita el punto, sin punto duplicado) y con **1 px de separación** entre acento y letra
  (`place_top(..., gap=1)` para `i`/`j`); la sombra se genera limpia (negro) con `auto_shadow`.
- **✅ VALIDADO en Windows (2026-10-02, mantenedor)**: "Ahora sí ha quedado bien" (tras la 4.ª iteración,
  1 px de separación en `í`). `¿`/`¡`, `ó`, `á`, `í/ì/î/ï`, sombras negras y signos especiales OK.
- **Ficheros**: `src/subsystems/font.cpp`, `src/platform/overlay.cpp`, `tools/text/build_font.py`,
  `include/hh/game_font_color4.h` (`work/fonts/coverage_color4.md` es regenerable).

## 6. Riesgos / notas

- El atlas crece 96 px en alto (580 → 676? no: `kFullHeight` de 483 a 579). Sin coste visible.
- Si algún acento no estuviera en `hh::kGameGlyphs`, no saldría (hoy cubre todo ES/CA/FR/DE: á é í ó ú
  ü ñ ç à è ê â ä ö ß y mayúsculas, más `¿ ¡ ·`).
- Los **kana** siguen su camino (`Color0`/`Color1`), intacto.

## 7. Cómo probar (Windows)

1. Recompilar el port (y copiar `assets/lang/` junto al exe).
2. En la cápsula: guardar (`¿Guardar la partida?` → `Guardando la partida actual aquí.` → `Yes/No`) y
   borrar (`Remove play data?`), en ES y CA.
3. Confirmar que no hay glifos rotos ni sombras "al revés".

## Referencias

- Formato de la fuente: `notes/2026-09-23-b-fuente-formato-y-gaiji.md`.
- Acentos del motor: `src/hooks/text_glyphs.cpp`, `include/hh/accent_glyphs.h`
  (`tools/text/gen_accent_glyphs.py`).
- Mensajes de la cápsula: `notes/2026-09-30-save-capsule-logica.md` §8ter.
- i18n (clave = inglés): `notes/2026-10-01-i18n-unificar-traducciones-plan.md`, ADR 0014.
