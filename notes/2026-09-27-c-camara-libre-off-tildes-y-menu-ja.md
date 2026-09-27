# 2026-09-27 — CÁMARA/APUNTADO LIBRE off, tildes +0.5 px y MENÚ en japonés (kana)

> Sesión `menu-nativo`. Objetivo acordado: 13–15 de `TODO.md` (deshabilitar los selectores modernos,
> mover las marcas 1 px y traducir el menú al japonés). Commits `d27dc54`, `12961d4`, `0c5f50c`.
> **Validado en Windows (2026-09-27)**: los tres temas. El ajuste de las tildes se estrenó como
> `+1.0 px` (`12961d4`) y resultó **excesivo**: se dejó en **`+0.5 px`** (corrección final pendiente de
> commit al cerrar).

## 1. `CÁMARA LIBRE` / `APUNTADO LIBRE`: de deshabilitados a OCULTOS

- **Primero deshabilitados** (commit `d27dc54`): `make_selector` acepta `enabled` y los dos selectores
  de `NUEVA PARTIDA` se crearon con `enabled=false` (`src/subsystems/menu.cpp`). `move_up`/`move_down`
  saltan las entradas `!enabled` (helper `step_enabled`, guarda: si no hay ninguna habilitada devuelve
  `-1`). El overlay pinta en gris etiqueta, valor activo y chevrons cuando `!e.enabled`.
- **DECISIÓN FINAL (2026-09-27, último cambio antes de v0.5.0)**: el mantenedor prefiere que **no se
  vean**; se **retiran del árbol** (`build_tree`), así que `NUEVA PARTIDA` queda solo con
  `EMPEZAR PARTIDA` + `DIFICULTAD`. La maquinaria de deshabilitados se **conserva** (por si se
  deshabilita otra entrada), aunque hoy no haya ninguna.

## 2. Tildes/marcas a la derecha (commit `12961d4`, corregido a +0.5 px)

- En `src/platform/overlay.cpp` (dibujo de la marca) el `dx` centrado se desplaza a la derecha. Es
  **global** para todas las marcas; **no** se regenera `include/hh/menu_marks.h` (el ajuste va en el
  overlay, no en el asset).
- **Historia del valor**: se probó `+1.0f * t.scale_x` (`12961d4`) y en Windows se vio **demasiado a
  la derecha**; se dejó en **`+0.5f * t.scale_x`** (validado). El plan inicial decía "volver a la
  posición anterior" (0 px), pero la posición buena es el punto medio.
- **Aclaración** (por si se relee el hilo): el **centrado del submenú `EXTRAS`** (`x_shift` en
  `src/hooks/menu_overlay.cpp`) **no** afecta a la posición relativa de la marca: desplaza la columna
  de texto entera, y la marca va pegada a su letra. Solo el centrado + este offset mueven la marca
  dentro de la celda.

## 3. Menú en japonés (commit `0c5f50c`)

### Hallazgo que corrige el plan: la fuente JP es la del US

- `color0` (Nisitenma idx 107) del **ROM JP es byte-idéntico** al del US: en `jp.z64` está @`0x6EBA40`
  y en el US @`0x6E3CD6`; los **128/128 bloques de 32 B coinciden**. Por tanto **la kana ya está en la
  ROM que carga el port** (valores 64..255 del mismo fichero); no hubo que extraer nada del ROM JP.
- Es decir: el paso "localizar el color0 del JP" del plan queda **trivialmente resuelto** (mismo
  fichero). El ROM JP solo tiene otra **dirección** para el mismo asset.

### Mapping kana → valor de glifo (tablas del motor)

- El motor mapea EUC-JP → "slot" (= valor de glifo, porque `func_8001BFE4` carga
  `file_base + stride*(slot>>1)`) con `func_8001D394`, que despacha por fila JIS. Las tablas viven en
  `.resident` del ELF recompilado (`build/recomp/elf/hybrid-heaven.us.elf`, no versionado):
  - fila A1 (símbolos, p. ej. `ー`) @`0x80044648`, index por `bajo-0xA1`;
  - fila A3 (ASCII) @`0x800446AC`, index por `bajo-0xB0` (comprobado `'A'→37`);
  - fila A4 (hiragana) @`0x800446F8`, index por `bajo-0xA1`;
  - fila A5 (katakana) @`0x8004474C`, index por `bajo-0xA1`.
- Verificado por bitmap (decodificando color0): A4AF (`く`)→92 dibuja "く"; A4B7 (`し`)→96;
  A5AF (`ク`)→172; A5A2 (`ア`)→165; A1BC (`ー`)→246.
- `tools/text/extract_jp_kana.py` lee esas tablas del `.resident` (parsea ELF32/ELF64) y genera
  `include/hh/jp_kana.h` (165 entradas `{cp, valor, nota}`; incluye hiragana, katakana, ー y `、。`).

### Cableado en el overlay

- `font.cpp`: `kMaxValue` 64 → **256**; el atlas pasa de 128×32 a **128×128** (glifos 0..255) + la
  franja de marcas debajo (128×12) = **128×140**. `bake_atlas` ya recorría `kMaxValue`, así que no
  hubo más cambios. `jp_kana_value(cp, v)` busca en `kJpKana`.
- `overlay.cpp`: al dibujar, los codepoints `>= 0x80` se resuelven como kana (`jp_kana_value`) en vez
  de `glyph_value` (ASCII); misma celda 8×8, sin marca ni compensación de bearing.
- `menu.cpp`: `kMenuTr` añade la columna **`ja`** (kana, katakana en su mayoría) a todas las
  entradas/opciones y `localized()` deja de caer a inglés (`lang=5`). El endónimo JA de la lista
  `IDIOMA` pasa de `NIHONGO` (rōmaji) a **`ニホンゴ`**.
- Validación **offline** de la composición: recomponiendo los bitmaps de `コンティニュー`,
  `ニューゲーム`, `バトルモード`, `ゲームスタート`, `ハイ`, `イイエ`, `ニホンゴ` el texto se lee
  correctamente. Además, los 58 kana usados en `kMenuTr` están todos en `kJpKana`.

### Limitaciones / notas

- No hay **kanji** en `color0`: el menú JA va en kana (katakana/hiragana). El texto in-game
  (EUC-JP con kanji) sigue por su propia vía (`src/subsystems/text.cpp`, `assets/lang/ja.txt`).
- El offset del fichero de fuente sigue siendo **fijo** (`0x6E3CD6`, ROM US). Correr el port con el
  ROM JP ya daba la fuente mal antes de esta sesión; aquí no se ha cambiado (la kana del US basta).
  Queda como posible mejora futura detectar la región para el offset.

## 4. Validación en Windows (2026-09-27) y pendientes

- **Validado en Windows (2026-09-27)**: los tres temas — `CÁMARA/APUNTADO LIBRE` (primero deshabilitados;
  **decisión final: ocultos**); tildes ES/CA/FR a **+0.5 px**; y el menú en **japonés**
  (`IDIOMA → NIHONGO`).
- **Pendiente (tarea futura)**: el mantenedor **no lee japonés**; verificar los textos JA contra la
  **ROM japonesa** (rótulos originales) más adelante. Ver `TODO.md` (backlog).
- `docs/menu.md` / `TODO.md` / `RETOMAR.md` / `PROYECTO.md` actualizados.

## 5. Release

- Al fusionar `menu-nativo` con `main` (hoy **fast-forward**: `main` es ancestro), la release es
  **v0.5.0** (MINOR: features del menú inicial, idiomas, modos de juego y opciones PC). Título
  propuesto en `docs/releases/v0.5.0.md`.
