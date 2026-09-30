# DATA LOAD — recrear la maqueta 1:1 en el overlay

> Sesión 2026-09-30 (3.ª). Rama `menu-carga-guardado-partida`. Tarea de `RETOMAR.md`: "recrear la UI
> del `DATA LOAD` original **1:1** en nuestro overlay (`menu_overlay.cpp`, rama `is_load_game`)".
> Resultado: **maqueta (cajas, título, subtítulo `MEMORY SLOTS`, marco exterior y caja/mensaje),
> colores y sombras alineados al nativo** y **mensaje 1:1 glifo a glifo** (avance de color4 y sombra
> de glifos cableadas); validado headless contra la captura pareada del port. Queda fuera (documentado
> abajo) el **contenido/alineado de las filas**.

## 0. Resumen

Todo `[MEDIDO]` sobre la captura nativa renderizada por **nuestro port** (misma ventana RT64 que la
del overlay, sin depender del escalado del emulador):
`work/gameplay screenshots/menu-carga/LOAD DATA Continuar.png` (2559×1439, 16:9). La UI 2D nativa va
**centrada** en el espacio virtual 320×240, con `k = alto/240` (el mismo `k` que usa el overlay);
verificado porque `CONTROLLER PAK` cae en x≈38 (coincide con `a1=0x26` de `func_801426B0`).

Constantes nuevas (`src/hooks/menu_overlay.cpp`, rama `is_load_game`):

| Elemento | Valor (virtual 320×240) |
|---|---|
| Título `DATA LOAD` (color3 12×13) | centro x=160, top de celda y=**28** |
| Subtítulo `MEMORY SLOTS` (color0) | x=**38**, top de celda y=**53** |
| Caja de partida | x=**37**, w=**112**, h=**37**, paso entre cajas=**46** |
| Texto de fila (color0) | sangría celda (+**5** x, +**4** y), paso de línea=**12** |
| Caja de mensaje (color4) | x=**29**, y=**171**, w=**262**, h=**51**; texto (+5 x, +3 y) |

Se **elimina la flecha de cursor** de la caja seleccionada: el nativo marca la selección **solo con el
borde verde** (ni la captura del emulador ni la del port muestran flecha en el `DATA LOAD`).

## 1. Verificación pareada (headless)

Comando: `HH_MENU_SCREEN=19 HH_PRESS_SEQ="64:start,…"` sobre Xvfb + lavapipe; captura con `import`
(la misma receta de `docs/fonts.md`). Midiendo nuestro render con `px = vx·3 + 160`, `py = vy·3`
(1280×720, `k=3`) y el nativo con `px = vx·k + (W−320k)/2`, `py = vy·k`:

| Elemento | Nativo | Overlay | Δ |
|---|---|---|---|
| Caja seleccionada | x 37.0–148.9, y 71.0–107.9 | x 37.0–148.7, y 71.0–107.7 | <1 px |
| 2.ª caja (top) | 117 | 117 | 0 |
| Título (tinta) | x 107–211, y 29.0– | x 107–210.7, y 29.0– | <1 px |
| Subtítulo `MEMORY SLOTS` | x 39–148.9, y 53.0–59.9 | x 39–148.7, y 53.0–59.7 | <1 px |
| Líneas de fila (top) | 75.1 / 87.1 / 99.1 | 75 / 87 / 99 | <1 px |
| Caja de mensaje | x 29–290.9, y 171.5–222.6 | x 29–290.7, y 171–222 | <1 px |

## 2. Avance de color4 (mensaje) y subtítulo — HECHO

1. **Ajuste fino del mensaje (misma sesión, tras la revisión del mantenedor).** El mensaje salía con
   los **espacios más anchos** que el nativo. Causa: el overlay avanzaba 8 px fijos. Se ha **cableado
   el avance del motor** (`hh::font::game::face_glyph_advance`, usado en `src/platform/overlay.cpp`):
   para `Color4`, **espacio = 4 px** y `f i j l r t` = 6 px; el resto 8. Medido sobre la captura
   pareada: con espacio=4 el mensaje nuestro **calca** el nativo **glifo a glifo** (drift 0.0). El
   valor 4 (no 6) se **midió**: cada espacio del mensaje nativo ocupa 4 px (progresión del drift
   +2/espacio con el valor anterior). Ver `docs/fonts.md` §6 (actualizado).
2. **Punto final `.` del mensaje**: el overlay lo dibujaba a mano como un cuadro **2x2** centrado
   (parecía un `·` grueso); el nativo es un punto de **1x1 px en el baseline** (col. 2, fila 8 de la
   celda 8x12). Ajustado en `src/platform/overlay.cpp` (solo `Color4`; el de `Color0`/menú mantiene su
   2x2). Medido: nuestro punto queda a **Δ<0.3 px** del nativo.
3. **Subtítulo `CONTROLLER PAK` → `MEMORY SLOTS`** (decisión del mantenedor; en PC no hay Controller
   Pak). Nueva entrada `kMenuTr` `RANURAS DE MEMORIA/MEMORY SLOTS/RANURES DE MEMÒRIA/EMPLACEMENTS
   MÉMOIRE/SPEICHERPLÄTZE/メモリースロット` (`src/subsystems/menu.cpp`) y el overlay usa
   `localized("RANURAS DE MEMORIA")` en la **misma posición 1:1** (x=38, y=53).
4. **Colores `[MEDIDO]`** (capturas del emulador y del port): el borde del **mensaje NO es blanco
   puro** (~`170,166,165`), los bordes de **slot** sin seleccionar son gris medio (~`90`), el
   **seleccionado** es un verde saturado (`19,255,13`), y los rellenos son oscuros translúcidos. El
   overlay usaba blanco puro y un verde claro; ajustado con constantes locales en `menu_overlay.cpp`.
5. **Marco exterior que agrupa los slots** (faltaba): es un rect con borde gris y relleno oscuro. Su
   rect sale del **setup nativo `func_801426B0`**: `func_8001A804(a0=6, D_8018F194, px=32, py=66,
   sx=122, sy=92, …)` → x=32,y=66,w=122,h=92; **expandido 1 px por lado** para calcar la medida del
   emulador (insets de ~6 frente a las cajas): **x=31, y=65, w=124, h=94**. Se dibuja **debajo** de las
   cajas de slot (las cajas van por encima; por eso su texto se ve a color pleno).
6. **Slot vacío**: el nativo (US) muestra **`NO DATA` CENTRADO** (horizontal y vertical) en la caja y
   **en blanco**. `kMenuTr` `SIN DATOS/NO DATA/SENSE DADES/PAS DE DONNÉES/KEINE DATEN/データナシ` y el
   modelo usa `localized("SIN DATOS")` (`src/subsystems/menu.cpp`); el overlay lo dibuja centrado
   (`menu_overlay.cpp`, rama `!present`). Verificado: centro x=92.8 (caja 93), y=89.0 (caja 89.5).
7. **Sombra del glifo: nivel 2 = GRIS (no negro)** `[MEDIDO]`. El mantenedor notó que la `l` de
   `Select play data to be loaded.` no era fiel: nuestro glifo dibujaba en **negro** el pixel de
   nivel 2 (el gancho superior de la `l`), mientras el motor lo dibuja como **gris suave** (~`134`
   sobre fondo ~`60`; el nivel 3 sí es negro). Causa: `bake_face`/`bake_atlas` colapsaban el nivel
   `>=2` a negro. Fix: el atlas guarda **nivel 1→255, nivel 2→140, nivel 3→0** en R (el PS ya hace
   `lerp(negro, color, R/255)`), en `src/subsystems/font.cpp`. Aplica a `color0`, `color3` y `color4`.
   Verificado: el gancho de la `l` sale gris (nuestro 140 vs nativo 134) y el mensaje calca el nativo.

## 2bis. Pendiente (decisión del mantenedor)

- **Contenido/alineación de las filas**: el nativo (US) muestra `AREA/LEVEL/TIME` con el **valor
  alineado a la derecha** (columna ~x 119–150), mientras el overlay usa los rótulos `ÁREA/NIVEL/
  TIEMPO` con un solo espacio (valor pegado a la etiqueta). Es contenido/formato, no geometría:
  confirmar antes de cambiarlo (AGENTS: no inventar UI).

## 3. Cómo reproducir

```sh
cd build/linux
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_MENU_SCREEN=19 HH_PRESS_SEQ="64:start,65:-,67:start,68:-,70:a,71:-,73:a,74:-" \
  timeout 100 "./Hybrid Heaven Recomp"
# capturar tras el `[save-edit] .pak cargado` (≈t=65 s): import -window root cap.png
```

Medición de rectángulos de borde: umbral sobre `lum`/saturación y agrupación de filas/columnas
(ver historial de la sesión). El nativo se mide en `LOAD DATA Continuar.png`; el overlay, en la
captura RT64 1280×720.

Referencias: `docs/fonts.md`, `notes/2026-09-30-tipografias-data-load-hallazgos.md`,
`notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`.
