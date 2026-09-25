# 0012 — Soporte multi-idioma y acentos (menú + in-game)

- **Estado:** Aceptado (2026-09-25).
- **Contexto:** sub-objetivo obligatorio: **traducir todo el texto** (ES/CA/FR/DE/JA). La ROM **US** no
  trae acentos en la fuente del **menú** (`color0`, 8×8, solo latino/símbolos); los glifos acentuados
  reales viven en **`color4`** (8×12, tipografía del texto **in-game**). El motor usa **EUC-JP** y tiene
  kanji en `color3`/`color1`. DE/FR están en la ROM **EU**; JA en la **JP**; ES/CA son propios.
- **Decisión:**
  1. **Menú:** los acentos se componen como **letra base (color0, sin deformar) + marca** superpuesta,
     dibujada por el mantenedor y procesada por `tools/text/menu_marks.py` (recorte de forma +
     colocación por tipo + centrado). **No** se usan los glifos `color4` (otra tipografía) ni se
     comprime la mayúscula. `¿ ¡` = `? !` girados.
  2. **Localización del menú:** etiquetas canónicas en español + tabla `kMenuTr` →
     `hh::menu::localized()` (idioma activo). La lista `IDIOMA` usa **endónimos**.
  3. **Selección de idioma:** `IDIOMA` funcional (`hh::text_set_language`), persiste en
     `config.ini [lang]`. Sin preferencia: **idioma del sistema** si es `en/es/ca/fr/de/ja`; si no,
     **inglés**. Prioridad `HH_LANG` > `[lang]` > sistema > `en`.
  4. **Texto in-game:** juego de acentos 8×12 generado desde la ROM (`tools/text/build_font.py` →
     `include/hh/game_font_color4.h`, ES/CA/FR/DE), embebido porque el runtime USA no los trae.
  5. **Japonés:** el motor ya soporta EUC-JP (kanji en in-game); el **menú JA (kana)** queda pendiente
     de embeber la kana del `color0` JP o pasar a TTF.
- **Consecuencias:**
  - El menú no deforma letras y mantiene el 1:1 con el original; las marcas son un asset editable.
  - El overlay gana un segundo atlas (marcas) y decodificación UTF-8 en el texto.
  - La fuente in-game es recompilable por script; su cableado en `text_glyphs.cpp` queda pendiente.
- **Alternativas descartadas:**
  - Usar glifos reales `color4` en el menú → tipografía distinta (detectado con el mantenedor).
  - Componer acentos 8×8 por letra → comprime/ distorsiona la mayúscula.
  - Extraer el endónimo JA `日本語` → kanji no está en `color0`.
- **Criterio de salida:** validar en Windows el menú localizado + acentos; y cerrar JA (kana) y el
  cableado del set in-game.
