# D — Menú multilingüe, acentos por marcas e idiomas (EN/ES/CA/FR/DE)

> Sesión 2026-09-25 (4.ª del día). Cierra la **tarea de menú + traducción** iniciada en las notas
> A2. Continúa `notes/2026-09-25-c-font-eu-color4-localizada.md` (que corregimos aquí).

## 1. Corrección de formato de la fuente "idioma" (color4)

La nota C afirmaba 8×8/32 B (`stride=32`) y que la EU estaba reordenada. **Es incorrecto**:
- El fichero "idioma" (Nisitenma **idx108**) es **8×12**: 2 glifos por bloque, **48 B** US / **56 B** EU
  (8 B extra por bloque). US = 88 valores; EU = **130**. `bloque = v>>1`, paridad `v&1`.
- La base coincide con US en casi todo: `v1..v10`="0".."9", `v11..v36`="a".."z", `v37..v62`="A".."Z".
  Los acentos reales EU están en valores ~87..128 (Ü Ä Ö À Ç É Ê …).
- Con 32 B la extracción salía **troceada** (de ahí el "reordenado"): herramienta **corregida**,
  `tools/text/extract_eu_font.py` (stride 56, 8×12, 130 valores).
- La traza `[font] bfe4 color=0 ... stride=32 fileidx=108` **no era color4**: `fileidx=108` es el índice
  **1-based** del motor → `file_table[107]` = Nisitenma **107** = **color0 8×8**. Y `stride=32` es el de
  color0. → **El menú usa color0** (por eso el overlay 8×8 casa 1:1). `stride=32` lo confirma.

## 2. Idiomas en las ROMs

- **EU** (`work/roms/eu_dec.z64`): edición **En/Fr/De**. Texto localizado DE @`0x8BE290`, FR @`0x8BF250`
  (EUC-JP con gaiji de 2 bytes). **No hay ES/CA/IT/NL** (0 coincidencias).
- **JP** (`work/roms/jp.z64`, de `Hybrid Heaven (Japan).zip`): z64, `HYBRID HEAVEN JP`, Nisitenma
  @`0x3A4E8`, 624 módulos. **Texto de juego en japonés** (p. ej. módulo 56 @`0x6C0F06`
  `…Ａボタンをおすと攻撃選択画面になり…`). Fuente `color3` = **50 544 B** (kanji).
- Conclusión de fuentes: **DE/FR de la EU**, **JA de la JP**, **ES/CA propios**.

## 3. Acentos del MENÚ — decisión: letra + marca

Los acentos reales están en **color4 8×12** (tipografía in-game), **no** en el color0 del menú; y
mezclarlos quedaría mal. Decisión del mantenedor: **no comprimir las mayúsculas**; se dibuja la
**letra base color0 tal cual** + una **marca** encima/debajo.

- El mantenedor dibuja las marcas sobre una plantilla (`tools/text/menu_marks.py --template`), cada
  celda con letra de referencia (A/N/C); luego exporta **solo la capa de marcas**.
- `--from-layer` recorta la **forma** (import con umbral para no engordar trazos), fija la posición
  vertical y la centra, y emite `include/hh/menu_marks.h` (sprites + tabla `codepoint → letra+marca`).
- El overlay (`src/platform/overlay.cpp`, `src/subsystems/font.cpp`) hornea las marcas en el atlas
  (128×44) y pinta letra + marca en UTF-8. `¿ ¡` = `? !` girados.
- Ficheros editables: `work/fonts/menu_marks_{base,layer}.png` + `menu_marks_legend.md`.

## 4. Localización del menú + idioma del sistema

- Etiquetas del modelo en **español canónico** → `hh::menu::localized()` (tabla `kMenuTr`,
  `src/subsystems/menu.cpp`): **en/ca/fr/de** (JA → inglés de momento).
- **`IDIOMA` movido debajo de `DIFICULTAD`** (en `NUEVA PARTIDA`) y **funcional**: A aplica
  `hh::text_set_language(code)` (texto in-game + menú) y **persiste** en `config.ini [lang]`. La lista
  muestra **endónimos** (`ENGLISH · ESPAÑOL · CATALÀ · FRANÇAIS · DEUTSCH · NIHONGO`).
- Correcciones del mantenedor: ca `NOVA PARTIDA`, `MODE COMBAT`, `APUNTAT LLIURE`, `DEBUG`/`RATIO`
  iguales en todos, `P. COMPLETA`; dificultad **`ULTIMATE`/`DEFINITIVO`/`DEFINITIU`**.
- **Idioma del sistema** (`src/subsystems/text.cpp`): sin `[lang]`, usa el locale del SO
  (`GetUserDefaultLocaleName` / `LANG`·`LC_*`) si es `en/es/ca/fr/de/ja`; si no, **inglés**.
  Prioridad: `HH_LANG` > `[lang]` > sistema > `en`. Probado: `fr_FR→fr`, `ca_ES→ca`, `de_AT→de`,
  `ja_JP→ja`, `es_MX→es`, `pt_BR→en`, `en_GB→en`.

## 5. Fuente in-game (ES/CA/FR/DE) — preparada, sin cablear

`tools/text/build_font.py` compone el juego de acentos 8×12 (base US + marcas reales EU) para
**ES/CA/FR/DE** y emite `include/hh/game_font_color4.h` (y una variante 8×8 `game_font_color0.h`).
**Pendiente**: cablearlo en `src/hooks/text_glyphs.cpp` (hoy sirve un set 8×8 propio `accent_glyphs.h`).

## 6. Japonés en el menú

`color0` JP **sí tiene kana** (hiragana + katakana + `ー ・ 、。`), **no kanji**. Para menú JA habría que
embeber la kana del color0 JP en el overlay (o ir a TTF). De momento JA cae a inglés en las etiquetas.

## 7. Herramientas nuevas / tocadas

- `tools/text/extract_eu_font.py` — **corregido** (8×12, stride 56).
- `tools/text/build_font.py` — **nuevo**: fuente in-game ES/CA/FR/DE (8×12 `color4` + 8×8 `color0`),
  hojas editables + import + informe de cobertura.
- `tools/text/menu_marks.py` — **nuevo**: plantilla/import de marcas del menú (letra+marca).
- `tools/text/README_font_sheet.md` — formato de las hojas y flujo en Affinity.

## 8. Cómo probar

```sh
python3 tools/text/menu_marks.py --template work/fonts/menu_marks_base.png \
    work/fonts/menu_marks_layer.png
# dibujar en Affinity y exportar la capa de marcas
python3 tools/text/menu_marks.py --from-layer work/fonts/menu_marks_layer.png \
    --out include/hh/menu_marks.h
cmake --build build/linux --parallel $(nproc)
```

Previews: `work/fonts/preview_menu_ingame.png`, `preview_lang_{en,es,ca,fr,de}.png`,
`preview_cadenas.png`. Compila y arranca headless (atlas 128×44). **Falta validar en Windows.**
