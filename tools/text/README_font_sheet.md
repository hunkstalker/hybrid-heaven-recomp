# Hojas de fuente editables (ES/CA/FR/DE)

Genera y reimporta el set de glifos acentuados de la fuente **real** del juego.
Herramienta: `tools/text/build_font.py`.

## Medidas exactas (formato del motor)

- **Glifo 8 px ancho × 12 px alto** (estilo `color4`, texto in‑game).
  - Menú/overlay: **8×8** (estilo `color0`).
- **2 bpp**: niveles `0` fondo, `1` tinta, `2/3` sombra (copia desplazada abajo‑derecha).
- Empaquetado: **2 glifos por bloque**; el valor **par** usa los bits 2‑3 de cada nibble,
  el **impar** los bits 0‑1. `bloque = valor>>1`.
  - `color4`: bloque **48 B** · `color0`: bloque **32 B**.
- Orden base: `0`=espacio, `1‑10`=`0`‑`9`, `11‑36`=`a`‑`z`, `37‑62`=`A`‑`Z`.

## Ficheros

| fichero | qué es |
|---|---|
| `work/fonts/edit_color4.png` | **editable** (8×12, escala ×8) — tinta negra, sombra roja, fondo blanco |
| `work/fonts/edit_color0.png` | **editable** (8×8, escala ×8) — para el menú |
| `work/fonts/ref_color4.png` / `ref_color0.png` | referencia ampliada (aspecto final) |
| `work/fonts/coverage_color4.md` | qué glifo es real / compuesto |
| `include/hh/game_font_color4.h` / `game_font_color0.h` | bloques empaquetados + `codepoint -> valor` |

## Editar en Affinity

- Abre `edit_color4.png` (o `edit_color0.png`).
- Cada **píxel de la fuente = un bloque de 8×8 px** de la imagen (escala ×8).
- Pinta **negro** (`#000000`) = tinta; **rojo** (`#DC2828`) = sombra; **blanco** = nada.
- Usa **borde duro** (sin antialias) y activa la **rejilla de 8 px** para alinear.
- No toques la banda de etiquetas de arriba de cada celda.
- Puedes rehacer a mano cualquier glifo; la sombra también (o se autogenera si falta).

## Reimportar

```bash
python3 tools/text/build_font.py --style color4 \
    --from-sheet work/fonts/edit_color4.png \
    --out include/hh/game_font_color4.h
```

La ida y vuelta es exacta (export → import) si no cambias los píxeles.

## Regenerar todo

```bash
python3 tools/text/build_font.py --style color4 \
    --sheet work/fonts/edit_color4.png --ref work/fonts/ref_color4.png \
    --out include/hh/game_font_color4.h --report work/fonts/coverage_color4.md
python3 tools/text/build_font.py --style color0 \
    --sheet work/fonts/edit_color0.png --ref work/fonts/ref_color0.png \
    --out include/hh/game_font_color0.h --report work/fonts/coverage_color0.md
```

## Origen de cada glifo

- **real**: glifo acentuado de la ROM EU (`color4`, 0x8C3298). Confirmado por los anclajes
  DE/FR (`ä=104, â=105, à=106, ê=109, è=110, é=111, ü=112, ö=117, ç=119, ß=128`).
- **comp**: compuesto desde la letra base (ROM US) + la marca de acento extraída de un
  glifo real. Revisar en la hoja; los agudos/graves de **mayúscula** son provisionales.

## Marcas del MENÚ (superponer, sin deformar la letra)

El menú lo dibuja el overlay: para una letra acentuada se pinta la **letra base tal cual**
(`color0`, 8×8) + una **marca centrada encima**. Así las mayúsculas NO se comprimen.

Herramienta: `tools/text/menu_marks.py`.

```bash
# 1) plantilla: base (letras de referencia) + LIENZO en blanco para dibujar
python3 tools/text/menu_marks.py --template \
    assets/fonts/menu_marks_base.png work/fonts/menu_marks_blank.png
# 2) en Affinity dibuja las tildes sobre el lienzo y exporta SOLO esa capa como el DISEÑO
#    (fuente de verdad): assets/fonts/menu_marks_ed.png
python3 tools/text/menu_marks.py --from-layer assets/fonts/menu_marks_ed.png \
    --out include/hh/menu_marks.h
```

- Una celda por símbolo (6 tildes con letra de referencia A/N/C + `· Æ Œ`), celda **8×12**:
  filas 0‑1 tilde · 2‑9 letra · 10‑11 cedilla. Escala ×12.
- `¿ ¡` se generan solos girando `? !` de la fuente del menú (`color0`: `!`=v74, `?`=v75).
- `menu_marks.h` contiene: `kMenuMarks[]` (sprites recortados con `dx,dy`) y
  `kMenuChars[]` (`codepoint -> letra base + índice de marca`).
- El overlay centra la marca sobre la tinta de cada letra y la pinta a `t.y + dy`.
- **Fuente versionada**: el dibujo del mantenedor está en `assets/fonts/menu_marks_ed.png` (la
  plantilla/guía en `assets/fonts/menu_marks_*.png`, la leyenda en `..._legend.md`). El lienzo
  `menu_marks_blank.png` es **scratch** de `--template` (no es fuente de verdad; no regenerar desde
  él). Regenerar el header:
  `python3 tools/text/menu_marks.py --from-layer assets/fonts/menu_marks_ed.png --out include/hh/menu_marks.h`.

## Pendiente (integración)

- Cablear `game_font_color4.h` en la inyección del motor (`src/hooks/text_glyphs.cpp`,
  hoy sirve bitmaps 8×8 de `color0`) y `game_font_color0.h` en el atlas del overlay
  (`src/subsystems/font.cpp`).
- Menú (overlay): usa `color0` 8×8; sus tildes salen de `game_font_color0.h`.
