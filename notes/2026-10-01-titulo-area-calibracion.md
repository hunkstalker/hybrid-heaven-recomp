# TÍTULO DEL ÁREA — calibración del texto (1:1 con el original)

> Sesión 2026-10-01 (3.ª de la jornada). Rama **`menu-carga-guardado-partida`**. Continúa
> `notes/2026-10-01-titulo-area-carga.md` (función hecha y verificada headless). Tarea de `RETOMAR.md`
> (TAREA ACTUAL) y `TODO.md`. Todo `[MEDIDO]`.

## 0. Objetivo

Fijar el **tamaño/estirado/tracking/posición** del nombre del Área (Work Sans, overlay propio) para que
mida 1:1 con el gráfico nativo. El `AREA N` (fuente del juego) NO se toca.

## 1. Medición del original `[MEDIDO]`

Se ancla la escala en el **`AREA N`**, que el port ya pinta idéntico (44,0 v de ancho con la fuente del
juego a escala 1) y que no forma parte de la tarea:

- `work/area_titles_montage.png` (montaje nativo): `AREA 1` = 132 px → **k = 3,0** px/v.
- Nombre del Área 1 en el montaje = 600 px × 42 px → **200,0 v × 14,0 v** (aspecto **14,29**).
- Contraste con `work/gameplay screenshots/titulo area/ingles emulador.png` (2557×1346, con
  pillarbox): nombre 1125 px × 79 px, `AREA` 248 px × 40 px; con k = 40/7,13 ≈ 5,608 → **200,6 v × 14,1 v**
  (aspecto 14,24). Coincide.

Centro vertical del nombre ≈ **107,0 v** (0,4458 del alto del original); el `AREA` queda en 92,5 v.

## 2. Work Sans `[MEDIDO]` (stb_truetype, mismo raster que el runtime)

Con la fuente cargada (**SemiBold**) y `kPixelHeight=22`:

- `text_width("bioweapon storage facility")` = 245,36 px; tinta = **245,12 px × 19 px** a escala 1
  (aspecto **12,78**).
- El original es **más ancho** (14,29), así que a igual ALTO (14,1 v) Work Sans daría ~182 v de ancho.

### 2bis. Peso: **SemiBold (600)** `[MEDIDO]`

El original (nativo, pixel-art ampliado) es más grueso que **Medium**. Medido en el mismo bbox y
alto (42 px; medianas de trazo vertical / cobertura):

| Fuente | trazo (mediana) | cobertura | aspecto natural |
|---|---|---|---|
| Original nativo | **6 px** | 0,230 | 14,24 |
| Work Sans Regular (400) | 4 px | 0,18 | — |
| Work Sans Medium (500) | 5 px | 0,23 | 12,78 |
| **Work Sans SemiBold (600)** | **7 px** | 0,29 | 13,4 |
| Work Sans Bold (700) | 8 px | 0,32 | — |

El original cae entre Medium y SemiBold; visualmente (`work/area_title_weight_mock.png`, original /
Medium / SemiBold apilados) **SemiBold** es el que reproduce el "peso" del original. Se añade
`assets/fonts/WorkSans-SemiBold.ttf` (aportado por el mantenedor, OFL) y se prefiere en el runtime
(`ttf.cpp`) por **carga de fichero** junto al exe (`fonts/WorkSans-SemiBold.ttf`); de momento **NO**
se incrusta (el embebido sigue siendo Regular y se ajustará a SemiBold al cerrar release).

### 2ter. Métrica (espacios): `word_space` `[MEDIDO]`

Con la caja ya cuadrada, la superposición con el original (`work/area_title_overlay_rgb.png`) reveló que
Work Sans **no comparte la métrica** del gráfico nativo:

| | espacio entre palabras | ancho por palabra |
|---|---|---|
| Original | **9,9 v** | — |
| Work Sans SemiBold | **6,2 / 5,7 v** | ~4 % más ancha (palabra 1 y 3) |

Es decir: letras ~4 % más anchas y **espacios ~40 % más estrechos**. Con solo `scale`/`tracking` no se
pueden cuadrar las tres cosas (alto, ancho total y espacios). Con el **ancho total FIXO** en 200,6 v y hueco entre palabras ≈ 9,9 v, las letras del original
**se tocan** (tracking negativo). Eso obliga a que el glifo sea **más grande** (SCALE 0,80): a ese
tamaño los anchos por palabra cuadran (Work Sans "bioweapon" 79,5 v vs 77,4 v; "storage" 55,4 vs 55,2).
El mantenedor pide además **estirado vertical**, así que `STRETCH` > 1 (alto de glifo = 19·scale·stretch).

```
scale   = 0,80   (ancho; a este tamaño las letras se tocan con tracking negativo)
stretch = 1,10   (ESTIRADO de alto; alto del glifo = 19·0,80·1,10 = 16,7 v)
tracking= -0,27  (NEGATIVO → las letras se tocan, como el original)
word_space = 5,67 (extra tras cada espacio → espacio ≈ 9,9 v como el original)
y       = 111,0  (centro = y − 4,5·(scale·stretch) = 107,0 v)
```

Solape de tinta con el original: IoU 0,507 con el ajuste previo (0,80/–0,27 da letras que se tocan,
como el original). Evidencia: `work/area_title_metric_mock.png` y **`work/area_title_variants.png`**
(original + variantes de `STRETCH`: 1,0 / 1,15 / 1,3 a igual ancho) para elegir cuánto estirar.

## 3. Defaults fijados `[MEDIDO del código]`

En `src/hooks/menu_overlay.cpp` → `publish_area_title`:

| Knob | Antes | **Ahora** |
|---|---|---|
| `HH_TITLE_SCALE` | 0,66 | **0,80** |
| `HH_TITLE_STRETCH` | 1,22 | **1,10** |
| `HH_TITLE_TRACK` | 0,00 | **-0,27** (negativo: se tocan) |
| `HH_TITLE_WORDSPACE` | — (nuevo) | **5,67** |
| `HH_TITLE_Y` | 111 | **111,0** |
| `HH_TITLE_NUM_Y` | 89 | 89 (NO tocar) |

Verificación visual: `work/area_title_match_mock.png` (medida), `work/area_title_weight_mock.png`
(peso), `work/area_title_metric_mock.png` (métrica/espacios) y `work/area_title_variants.png`
(estirado vertical). Build Linux OK.

**Nota**: `HH_TITLE_SCALE=1` (lo que probó el mantenedor en
`work/gameplay screenshots/titulo area/Captura de pantalla 2026-10-01 131341.png`) rinde **~241 v** de
ancho (**~20 % más ancho** que el original) y ~18 v de alto; no cuadra 1:1. Si prefiere ese tamaño,
basta con `HH_TITLE_SCALE=1` por entorno (los knobs se mantienen).

## 3bis. Salto de línea automático según aspecto `[MEDIDO/IMPLEMENTADO]`

En **4:3** el ancho visible es 320 v y **4 nombres** lo superan (Área 7 es 337,7 · Área 5 de 328,6 ·
Área 9 de 322,3 · Área 7 ca 322,0); en 16:9 caben todos (~427 v). Por eso, `publish_area_title` ahora
**parte el nombre por palabras** cuando no cabe en el **ancho visible real** y **centra cada línea**:

- El draw hook calcula el ancho visible (`240 · ancho/alto` del framebuffer) y lo publica con
  `overlay::set_visible_width()`; el juego lo lee con `overlay::visible_width()`.
- Si el nombre cabe → 1 línea (idéntico a antes; en 16:9 no cambia nada).
- Si no cabe → N líneas por palabras (greedy) + **reequilibrio** (evita una última línea de una sola
  palabra). Bloque centrado en el centro del nombre (≈107 v); si la 1.ª línea chocara con el `AREA N`
  (celda hasta y≈97 v) se baja el bloque lo justo.
- Reparto resultante en 4:3 (verificado con stb): A7 es → "instalación de almacenamiento de" /
  "clones 2"; A7 ca → "instal·lació d'emmagatzematge de" / "clons 2"; A5 de / A9 de →
  "Unterirdischer Schutzraum," / "unterste|oberste Ebene".

Ficheros: `include/hh/overlay.h`, `src/platform/overlay.cpp` (`visible_width`), `src/hooks/menu_overlay.cpp`.

## 4. Pendiente

- [ ] **Validar en Windows** (mantenedor): 1:1 de tamaño/posición, fade/tiempos y sin parpadeo;
      `en/es/ca/fr/de` y `ja`.

## 5. Referencias

- `notes/2026-10-01-titulo-area-carga.md` (función e idiomas).
- `src/hooks/menu_overlay.cpp` (`publish_area_title`), `src/subsystems/ttf.cpp` (`text_width`),
  `src/platform/overlay.cpp` (`TtfText`: `word_space`), `include/hh/overlay.h`.
- `work/area_titles_montage.png`, `work/area_title_match_mock.png`, `work/area_title_weight_mock.png`,
  `work/area_title_metric_mock.png`.
