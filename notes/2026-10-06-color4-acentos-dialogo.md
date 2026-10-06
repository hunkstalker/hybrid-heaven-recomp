# Glifos acentuados en color4 (diálogos): inyección por estilo

> Sesión 2026-10-06. Cierra el pendiente #3 de `RETOMAR.md`: la inyección de acentos solo servía
> `color0` (8×8, menús); ahora sirve también **`color4` (8×12)**, que es el estilo del **diálogo**.

## 1. Cambios

- `src/subsystems/text.cpp` (`utf8_to_euc`): el mapeo `codepoint -> código EUC` del texto de diálogo
  usa ahora `include/hh/game_font_color4.h` (`kGameGlyphs`, color4) en vez de `accent_glyphs.h`.
  El menú ASCII sigue con `accent_glyphs.h` (color0).
- `src/hooks/text_glyphs.cpp`: la inyección elige el set por el **stride del color** (tabla `tblA`
  en `0x80044624`):
  - `stride 32` → color0 (`kAccentGlyphs`, block 32).
  - `stride 48` → color4 (`kGameGlyphs`, block 48).
  Se mantiene el patrón de **donante ASCII (`@`) + marca de origen**; solo cambia el bloque servido
  y el tamaño de escritura en el scratch (`0x801077E0`).
- `assets/lang/es.txt`: el mensaje de prueba incluye ya acentos (`Sr.Díaz`, `código`, `¿Algún
  problema?`, `por ahí`) para validar `í/é/á/¿`.

## 2. Validación

- Compila (`cmake --build build/linux -j`).
- Simulación offline: los códigos emitidos para `í/á/¿` son `B1xx` del set color4 y el reparto por
  mensaje sigue cabiendo.
- **Pendiente**: validación **visual en Windows** (que `í/é/á/¿` se dibujen con el mismo estilo que
  el diálogo). Comparar con `HH_ACCENTS=0`.

## 3. Si falla visualmente

- Confirmar con `HH_FONT_TRACE=1` que el diálogo pasa por `color4` (stride 48); si usara otro color,
  añadir ese stride.
- Si el `value` del donante `@` en color4 fuera 0 (no se llamaría a `bfe4`), cambiar el donante.

## 4. Corrección: sombras grises (2026-10-06)

En la primera validación los acentos salían con **sombra gris** en vez de negra. Causa: `font.cpp`
confirma que en el motor **nivel 2 = gris suave** y **nivel 3 = negro**; `build_font.py` generaba la
sombra con `auto_shadow` en nivel 2 y ademas **normalizaba 3→2** (las nativas usan 3). El overlay no
se veía afectado porque `bake_game_glyph` hornea cualquier nivel ≥2 como negro; el **motor del juego**
sí distingue.

Fix: `auto_shadow` pone **nivel 3** y se elimina la normalización 3→2; regenerado
`include/hh/game_font_color4.h` (mismos `cp/code/value`; 61 bloques con la sombra a 3).

## 5. Corrección: `¿`/`¡` no casaban con la tipografía (2026-10-06)

`build_font` generaba `¿/¡` con `ink()` (solo nivel 1) + `auto_shadow`, es decir **planos**, mientras
el `?`/`!` nativo del motor lleva **bisel** (niveles 2/3 en el borde). Al faltarles el bisel no casaban.

Fix: `¿/¡` se generan rotando el glifo **nativo completo** (`rotate180(font_fc.glyph(75/74))` +
`shift_up(2)`), sin `ink()` ni `auto_shadow`; así conservan el mismo trazo/bisel que el `?`/`!`. En el
set color4 solo hay un `?` (v75) y un `!` (v74); no hay variantes más finas.
