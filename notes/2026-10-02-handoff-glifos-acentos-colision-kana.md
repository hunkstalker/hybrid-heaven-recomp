# Handoff — artefactos gráficos en el diálogo del ordenador: los acentos pisan la KANA

> 2026-10-02. Bug reportado por el mantenedor: al inicio (justo tras el primer punto de guardado),
> el PJ manipula un ordenador y aparece una ventana de diálogo con **"caracteres alienígenas" con
> artefactos**. Surgió **después** de añadir los acentos/tildes al motor de texto (commit `ee34c7a`).
>
> **Causa raíz encontrada y confirmada por análisis estático (medido).** Solución robusta **pendiente**
> (esta nota es el handoff para una sesión nueva). No confundir con los fixes ya hechos (#13, #14,
> textos al guardar, número de Área).

## 1. Qué son los artefactos (no son imágenes)

No son tiras de imágenes: son **glifos de la fuente del juego mal sustituidos**. El motor pide un
glifo por **valor**; en la fuente **color0** (NIS idx 107, 8×8) los valores **74..248** corresponden a
**kana** (katakana/hiragana), y el port reutilizó un subrango de esos valores para **sus acentos**.
El hook devuelve el bitmap del acento donde tocaba kana → "alienígena".

## 2. Causa raíz (medido)

### 2.1 El hook de inyección de acentos es ciego al color y al código
`src/hooks/text_glyphs.cpp`:
- `hh_accent_d394` (`func_8001D394`): mapea **código EUC propio** (`0xB1A1..0xB1B9`) → **`value` propio**.
- `hh_accent_bfe4` (`func_8001BFE4`): **sustituye el bitmap si `ctx->r5` (value) coincide** con uno de
  los valores propios. **NO mira `ctx->r4` (color/estilo) ni el código EUC.**

→ Cualquier glifo nativo cuyo `value` caiga en el rango reservado se sustituye por un acento.

### 2.2 Los valores reservados colisionan con la kana de color0
`tools/text/gen_accent_glyphs.py` usa `OUR_VALUE_BASE = 200` y asigna pares `200,202,…,248` con el
comentario *"bloques libres (el motor no mapea más allá de ~75)"* — **esa suposición es falsa**.

`include/hh/jp_kana.h` (kana real de la MISMA fuente color0, extraída del mapeo EUC→slot del ELF)
usa valores **74..248 de forma contigua**. Colisiones exactas (value == value):

```
U+30A1 ァ=236 · U+30A5 ォ=238 · U+30A9 ゥ=240 · U+30AE ヶ=212 · U+30B2 ギ=214 · U+30B6 ザ=216
U+30BA ズ=218 · U+30BE ゼ=220 · U+30C2 ヂ=222 · U+30C7 ヂ=224 · U+30D0 バ=226 · U+30D4 ビ=232
U+30D6 ブ=228 · U+30DA ベ=234 · U+30DC ボ=230 · U+30E3 ャ=242 · U+30E4 ヤ=200 · U+30E7 ョ=244
U+30E8 ヨ=202 · U+30EA リ=204 · U+30EC レ=206 · U+30EF ワ=208 · U+30F3 ン=210 · U+30FC ー=246
```

Y **23 más por bloque par/impar** (el bitmap empaqueta DOS glifos por bloque: par usa plano `0xCC`,
impar `0x33`): p. ej. `U+30A3 ィ=237` comparte bloque `118` con el acento `236`.

### 2.3 El rango libre de color0 está agotado
`value` de color0 = 0..255. Ocupados por ASCII/puntuación (0..73), **kana (74..248)**. "Libres":
`249..255` (no fiables: pueden ser gaiji/símbolos) y `0..73` (ASCII). **No hay hueco limpio** donde
meter 25 acentos sin colisionar. → **La estrategia de inventar `value` es intrínsecamente frágil.**

## 3. Por qué importa para el futuro japonés

El port ya soporta kana (`include/hh/jp_kana.h`, `tools/text/extract_jp_kana.py`) y **la ROM JP
comparte color0 byte-idéntico con la US** (ver `notes/2026-09-27-c-*`). Cualquier solución que siga
inventando `value` volverá a pisar kana (y al añadir más idiomas, más). Hay que quitar los acentos del
espacio de `value` o separarlos por **color+origen**, no por `value`.

## 4. Dirección de solución (robusta, acordada con el mantenedor)

**Mecanismo de DONANTES ASCII** (Opción B de `notes/2026-09-23-b-fuente-formato-y-gaiji.md` §5):
- Elegir código(s) ASCII poco usados como **donantes**; en la **traducción** (`src/subsystems/text.cpp`)
  emitir la letra acentuada como **2 bytes EUC propios** (`B1Ax`, ya reservados) que el motor mapea al
  `value` de un **código donante** (no inventado).
- El override de `func_8001BFE4` sirve el bitmap acentuado **solo** cuando `value` == un donante
  **resuelto desde nuestro `func_8001D394`** (marca de origen por color+código), nunca por `value` a
  secas. Así la kana (que llega con `value` 74..248 **por su propio `d394`**) pasa intacta.
- Los bitmaps se **componen** desde la letra base del propio fichero + píxeles de marca (mismo estilo),
  como ya hace `gen_accent_glyphs.py` (reutilizable). Cubre ES/CA/FR/DE y **no depende de la PAL**.

Alternativa más barata (NO elegida, se documenta): marca de "último `code` propio visto" en `d394` y
usarla en `bfe4`; arregla el bug de hoy pero sigue inventando `value` y es frágil para JA.

## 5. Evidencia / instrumentación ya disponible

- **Traza de fuentes** `HH_FONT_TRACE=1` (`src/hooks/sections.cpp` `hh_font_trace_d394`/
  `hh_font_trace_bfe4`): loguea a `hh.log`:
  ```
  [font] d394 code=XXXX -> N (slot N>>1)
  [font] bfe4 color=C code=XXXX slot=N stride=S fileidx=F
  ```
  → fija **qué color/estilo** usa el diálogo del ordenador y los `value` reales. **Primer paso de la
  sesión nueva**: confirmar con esta traza que la ventana usa color0 y valores 200..248.
- **Dump de bloque de glifo**: `HH_FONT_DUMP_GLYPH=<color>` (+ `HH_FONT_DUMP_ONLY=<value>`) vuelca el
  bloque cargado en `0x801077E0` (ver `hh_font_trace_bfe4`).
- Tabla kana: `include/hh/jp_kana.h`; generador `tools/text/extract_jp_kana.py`.
- Acentos actuales: `include/hh/accent_glyphs.h` (color0 8×8), generador `tools/text/gen_accent_glyphs.py`.
- Acentos color4 (cápsula): `include/hh/game_font_color4.h`, `tools/text/build_font.py`; franja
  `kAccentTop` en `src/subsystems/font.cpp` (`bake_atlas`) — **ojo**: esa franja es del **atlas del
  overlay**, no del motor in-game; no colisiona con kana, pero el **mecanismo de `value` del motor
  in-game sí** (es el bug).

## 6. Plan de la sesión nueva (orden sugerido)

1. **Medir** con `HH_FONT_TRACE=1` en Windows: abrir la ventana del ordenador y recoger `[font]`
   (`color`, `code`, `slot`, `fileidx`). Confirmar color0 + `slot` 200..248. *(Si usa otro color,
   anotar el alcance.)*
2. **Implementar donantes ASCII**: elegir donantes libres reales por color; extender `gen_accent_glyphs.py`
   para emitir los bitmaps como **donantes**; reescribir `hh_accent_d394`/`hh_accent_bfe4` para
   sustituir **solo** si el `value` proviene de un código propio (marca por color); ajustar
   `src/subsystems/text.cpp` para emitir los 2 bytes EUC de cada acento.
3. **Regenerar** headers (`python3 tools/text/gen_accent_glyphs.py` y, si aplica, `build_font.py`) y
   compilar.
4. **Validar en Windows**: (a) la kana del diálogo vuelve a salir correcta; (b) los acentos siguen
   bien en cápsula/menú (ES/CA/FR/DE); (c) preparar el terreno para JA sin regresión.
5. **Documentar** y commitear (un tema = un commit). Si la decisión de "donantes" se consolida como
   política, valorar ADR (extiende el sistema de fuente/ADR 0012).

## 7. Referencias

- `notes/2026-09-23-b-fuente-formato-y-gaiji.md` (formato 2bpp, colores, **Opción B donantes** §5).
- `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`, `notes/2026-09-25-c-font-eu-color4-localizada.md`.
- `src/hooks/text_glyphs.cpp` (`hh_accent_d394`/`hh_accent_bfe4`), `include/hh/accent_glyphs.h`,
  `include/hh/jp_kana.h`, `tools/text/gen_accent_glyphs.py`.
- Commit que introdujo el problema: `ee34c7a` (*"acentos, ¿ y ¡ en los mensajes de la cápsula"*).
