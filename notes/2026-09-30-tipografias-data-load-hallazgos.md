# TIPOGRAFÍAS del DATA LOAD — hallazgos `[MEDIDO]` (2026-09-30)

> Evidencia para `notes/2026-09-29-tipografias-data-load-tarea.md` (tarea) y el menú propio de carga
> (rama `menu-carga-guardado-partida`). **Corrige** la premisa de la tarea. Todo `[MEDIDO]` salvo lo
> marcado `[INFERIDO]`. No se ha tocado código del port en esta sesión (solo análisis + traza).

## 0. Resumen (la incógnita de la tarea, RESUELTA)

La tarea suponía que `func_8001B204(a0,…)` elegía el estilo/fuente por `a0` y que `DATA LOAD` y el
mensaje compartían `a0=7`. **Falso.** Medido en runtime y desensamblado:

| Texto del DATA LOAD | fuente | fichero Nisitenma (US) | tamaño | justificación |
|---|---|---|---|---|
| Título `DATA LOAD` | **color3** | idx **106** (`ROM 0x6E1C86`) | **12×13**, stride **78** | `%m 3` en la cadena |
| Mensaje `Select play data to be loaded.` | **color4** | idx **108** (`ROM 0x6E4CD6`) | **8×12**, stride **48** | `%m`→color 4; ya extraída (`game_font_color4.h`) |
| `CONTROLLER PAK` + cabeceras/filas de slot (`AREA`/`LEVEL`/`TIME` + valores) | **color0** | idx **107** (`ROM 0x6E3CD6`) | **8×8**, stride **32** | sin `%m` → color 0; es el atlas actual del overlay |

`color3` es la "3ª tipografía" que faltaba (no `color4`, que es la del texto in-game/mensaje). Los
altos medidos (11 / 9.3 / 7 ud) encajan: color3 ~13, color4 ~12, color0 ~8 (celda nativa).

## 1. `func_8001B204`: qué es cada argumento `[MEDIDO]`

- `a0` = **contexto/slot de salida** (0..0x1B). NO es la fuente: indexa `D_8008EF70 + a0*282`
  (stride real `0x11A = 282`, no `0x38` como decía la tarea) y ahí van los glifos ya compuestos.
- `a1`/`a2` = **posición X / Y**. `a1 = 0x7D0` es un **sentinel "centrar horizontalmente"** (se
  escribe `(0x140 - ancho)/2`); `a2` = Y.
- `a3` = puntero al texto (ASCII→EUC con la tabla `0x80044548`; control `0x25 xx`).
- **La fuente se elige con el código de control `%m <n>` DENTRO de la cadena** (n = 0..5): el parser
  lo guarda en `D_80090E48`, y `func_8001BC04`/`func_8001BFE4` lo usan como **color de estilo**
  (ancho de glifo vía `0x8004461C`, fichero vía `tblB 0x8004462C`, stride vía `tblA 0x80044624`).
  Al empezar cada llamada, `D_80090E48 = 0` (por eso un texto sin `%m` sale en color0).

Cadena del título (`D_8018F16C`, file_008): `25 6D` (`%m`) + `A3C4 A3C1 A3D4 A3C1 A1A1 A3CC A3CF A3C1 A3D4 A3C1`
= `%m` + `DATA LOAD`; el vararg (5º argumento en `%sp+0x10`) es **3** → color3.

## 2. Traza de runtime `[MEDIDO]` (headless Linux)

Build actual en `build/linux` (con el enganche de Fase 3 y `HH_NATIVE`). Comando:

```sh
cd build/linux
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_NATIVE=1 HH_FONT_TRACE=1 HH_FONT_DUMP_GLYPH=3 HH_MENU_TRACE=1 \
  HH_PRESS_SEQ="64:start,65:-,67:start,68:-,70:a,71:-,73:a,74:-" HH_AUTOQUIT=95 \
  timeout 130 "./Hybrid Heaven Recomp"
```

`HH_NATIVE=1` deja el texto nativo VISIBLE (sin el "blankeado" del overlay) → es la única forma de
ver el color real del título. Llegada al DATA LOAD: `[menu] goto pantalla=801C3CDC` (handler
CONTINUE) → `801C3D50` (setup) → `801426B0` (setup LOAD) y `8013E850` (update).

Secuencia `[font] bfe4` tras `CONTINUE` (color, `code`=valor de glifo del motor, stride, fileidx):

```
color=3 code=0079 slot=60 stride=78 fileidx=107   # 'D'  (121)
color=3 code=0076 slot=59 stride=78 fileidx=107   # 'A'  (118)
color=3 code=0089 slot=68 stride=78 fileidx=107   # 'T'  (137)
color=3 code=0000 slot=0  stride=78 fileidx=107   # ' '
color=3 code=0081 slot=64 stride=78 fileidx=107   # 'L'  (129)
color=3 code=0084 slot=66 stride=78 fileidx=107   # 'O'  (132)
color=4 … stride=48 fileidx=109 …                 # mensaje "Select play data to be loaded."
color=0 … stride=32 fileidx=108 …                 # CONTROLLER PAK + filas/cabeceras (dígitos)
```

`fileidx` es el valor crudo de `tblB` (`0x8004462C[color]`); el fichero real Nisitenma es
`fileidx-1`: color0→107, color3→106, color4→108.

Correspondencia de `code` a letra para el título (color3, `%m 3`): `'A'=0x76`, `'B'=0x77`, … (lineal,
`valor = 0x76 + (c - 'A')`); los 5 glifos con tinta medidos cuadran con la regla y con la captura.

## 3. Bloques del título (color3) `[MEDIDO]` (`HH_FONT_DUMP_GLYPH=3`)

`block = valor>>1`, `paridad = valor&1`, 2bpp, stride 78, 12×13. Bloques volcados en `[fontdump]`
(guardados en `build/linux/hh.log` de la corrida; no versionado). Ejemplos crudos (primeros 78 B):

```
D (121, slot 60): 00 00 00 00 00 00 01 11 55 50 00 00 00 17 3F F5 00 00 00 53 C0 00 50 … 
A (118, slot 59): 00 00 00 00 00 00 01 11 15 10 00 00 00 13 37 F1 00 00 00 13 40 40 10 … 
T (137, slot 68): 00 00 00 00 00 00 01 11 55 51 51 00 01 37 3D F7 7D 30 00 70 C1 30 4C … 
L (129, slot 64): 00 00 00 00 00 00 05 55 00 04 44 00 00 5F F0 00 4C C0 00 5F 00 04 0C … 
O (132, slot 66): 00 00 00 00 00 00 01 11 55 50 00 00 00 17 3F F5 00 00 00 53 C0 00 50 … 
```

(El trazado de `DATA LOAD` con esta fuente reproduce las **serifas** del 'D'/'T'/'A' de la captura
`work/gameplay screenshots/CONTINUAR/Captura de pantalla 2026-09-26 033740.png`.)

## 4. Lo que NO cambia (ya confirmado)

- `color0` (8×8) = atlas actual del overlay (`hh::font::game`); cabeceras y `CONTROLLER PAK` ya salen
  bien con él. Sin cambios.
- `color4` (8×12) = `include/hh/game_font_color4.h` (ya extraída, `tools/text/build_font.py`); falta
  usarla en el overlay para el mensaje.
- **Escala**: es 1.0 en el espacio virtual 320×240; la "altura" sale del tamaño de celda nativo de
  cada fuente (no hay que reescalar, solo usar la fuente/celda correcta por texto).

## 5. Cableado del overlay (HECHO, 2026-09-30)

Se ha cableado la UI propia (`LoadGame`) para dibujar cada texto con su fuente nativa:

- `include/hh/font.h` + `src/subsystems/font.cpp`: nueva `enum class Face { Color0, Color4, Color3 }`,
  `face_cell_w/h()` y `face_glyph_uv()`; el atlas pasa a **128×214** con dos franjas nuevas:
  **color4** (8×12, ASCII 0..63) y **color3** (12×13, espacio + `A`–`Z`, mapeo `0x76+idx`), leídas de
  la ROM como ya se hacía con color0.
- `include/hh/overlay.h` + `src/platform/overlay.cpp`: `overlay::Text` tiene `face`; el bucle de texto
  usa la celda/UV de la fuente elegida (color3/color4 por una vía simple sin marcas ni kana).
- `src/hooks/menu_overlay.cpp` (`LoadGame`): título `DATA LOAD` → **Color3**; mensaje `Select play data
  to be loaded.` → **Color4**; filas/`CONTROLLER PAK` → **Color0** (sin cambios).

**Validado headless (Linux)** con captura: título en la serif 12×13 y mensaje en la 8×12, ambos
coincidiendo con la captura nativa `work/gameplay screenshots/CONTINUAR/`. Comando de la captura
forzando la pantalla: `HH_MENU_SCREEN=19 HH_PRESS_SEQ="50:start,51:-,53:start,54:-"` + `import`.

> **Doc operativo:** `../docs/fonts.md` (fuente de verdad de las tipografías: API, atlas, mapeos,
> avances y cómo medir). Esta nota es la evidencia fechada.

## 6. Pendiente (siguiente paso)

1. **Validar 1:1 en Windows** (F7 pareado) contra la captura nativa: además de las fuentes, quedan
   detalles de MAQUETA (cajas/posiciones, `CONTROLLER PAK`, rótulos `AREA/LEVEL/TIME` vs los
   localizados `ÁREA/NIVEL/TIEMPO`), que son del afinado 1:1, no de las tipografías.
2. (Opcional) si se quiere `DATA SAVE`, la fuente ya sirve: `'S','V','E'` → `0x76+18/21/4`.
