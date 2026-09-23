# B — Formato de la fuente del juego, ficheros y gaiji PAL (hallazgos)

> Sesión 2026-09-23. Continúa `notes/2026-09-23-b-fuente-localizacion.md` y
> `-b-motor-texto-localizado.md`. **Localizada y descodificada la fuente**: no es una
> textura única sino **6 ficheros de bitmap por glifo**, uno por "color"/estilo. Herramienta
> nueva: `tools/text/font_dump.py` (hojas de contacto PNG en `work/fonts/`).

## 1. Dónde está la fuente

No hay una "textura de fuente" con UVs. El motor **carga cada glifo** desde ficheros de
la tabla Nisitenma, sin comprimir, y lo compone en RDRAM:

- `func_8001B204` (set entrada de menú) → estilos/tablas en `0x80044548`, `0x80044608`,
  `0x80044614`; fija color global `0x8009E48..E4F`; llama a `0x8001BC04`.
- `0x8001BC04` (colocar texto): `a0`=estilo/color, `a1`=¿?, `a2`=struct destino, `a3`=código de
  carácter; llama `0x8001BD20`, `0x8001D394`, `0x8001C0B0`.
- `0x8001BD20` → **ancho del glifo** (tabla `0x8004461C`).
- `0x8001D394` → **código EUC → índice de glifo** (dispatch por color; subrutinas
  `C88C/C96C/CE9C/D2E0/CF40`; casos especiales: `A2A7→0x55`, `A1FC→0x56`, y en PAL `B0A1..B0CA→0x57..`).
- **`0x8001BFE4`** → **carga el bitmap del glifo**: `dst = 0x801077E0` (US);
  `src = file_base(style) + stride*(glyph>>1)`, copia `stride` bytes. El fichero lo da
  `func_8000511C(idx) = file_table[idx-1] & 0x7FFFFFFF`.
- `0x8001C0B0` → compone el glifo en la "textura" de trabajo `0x800F51C0` (máscaras 0x33/0xCC).

Tablas `tblB` (`0x8004462C`) = índice de fichero por color (color0..5):
`0x6C 0x6E 0x6F 0x6B 0x6D 0x70` → ficheros Nisitenma **107,109,110,106,108,111**.
`tblA` (`0x80044624`) = bytes por glifo por color: `32,50,60,78,48,78`.
Anchos (`0x8004461C`): `8,10,10,12,8,12`.

**Conversión ASCII→EUC** (clave): el parser de texto (`0x8001B204`) lee el texto de la UI en ASCII
y, para bytes `0x20..0x7F`, los convierte a códigos EUC de 2 bytes con la **tabla `0x80044548`**
(96 entradas de 2 B): `'0'→A3B0`, `'A'→A3C1`, `'a'→A3E1`, `' '→A1A1`… Los bytes `>= 0x80` ya se
tratan como EUC de 2 bytes. `func_8001D394` mapea ese código a un valor que `0x8001BFE4` convierte en
slot. Tablas de mapeo (`C670`/`C6E8`/`C734`/`C7A4`/`C824`) en `0x80044648`/`A4`/`AC`/`F8`/`74C`.

## 2. Ficheros de fuente en la ROM (sin comprimir)

| estilo | US idx | size | EU idx | size | dim (px), bytes/bloque | bloques |
|---|---|---|---|---|---|---|
| color0 | 107 | 4096 | 116 | 4096 | 8×8, 32 B | 128 |
| color1 | 109 | 8000 | 118 | 8000 | 10×10, 50 B | 160 |
| color2 | 110 | 2592 | 119 | 2592 | ~10×12, 60 B | ~43 |
| color3 | 106 | 8272 | 115 | 8272 | 12×13, 78 B | 106 |
| **color4** | **108** | **2112** | **117** | **3648** | **8×12, 48 B** | **44 → 76** |
| color5 | 111 | 1104 | 120 | 1104 | ~12×13, 78 B | ~14 |

**Formato del glifo (corregido)**: **2 bits por píxel** (4 niveles), fila a fila, MSB-first, y
**cada bloque de `tblA` bytes contiene DOS glifos empaquetados**: el valor PAR usa los bits 2-3 de
cada nibble (máscara `0xCC`) y el IMPAR los bits 0-1 (`0x33`); `bloque = valor >> 1`,
`paridad = valor & 1`. Dentro de un glifo: **nivel 1 = glifo principal**, **nivel ≥2 = sombra**
(copia desplazada abajo-derecha que el motor pinta en negro; ver
`notes/2026-09-23-a2-render-hook-y-atlas.md` §6b). Confirmado contra la tabla real del motor en
`0x800446AC`: `'A'→37` (bloque 18 paridad 1), `'B'→38` y `'C'→39` comparten el bloque 19. El decode
correcto está en `src/subsystems/font.cpp` (`bake_atlas`).

> **OJO con `font_dump.py`**: sus hojas de contacto leen los ficheros como **4bpp (un glifo por
> bloque)**, que **NO es el formato real**: esa vista es la **unión de los dos glifos empaquetados**
> (de ahí que los patrones parezcan "limpios" aunque no correspondan a un glifo del motor). Sirve
> como inventario visual, no como referencia de formato. Los ficheros color1/color3 contienen
> **kana/kanji** (fuente japonesa, presente también en USA).

## 3. Hallazgo clave US↔EU

**Cinco de los seis ficheros son byte-idénticos** US↔EU. **Solo difiere el estilo `color4`**:

- US `idx108` = 2112 B = **44 glifos**.
- EU `idx117` = 3648 B = **76 glifos** (+1536 B = **32 glifos nuevos**).

Es decir: **la PAL añadió los glifos acentuados al estilo 4**, y **solo a ese**. La fuente se
reordenó (no es US+append; el primer byte ya difiere), pero el conjunto nuevo está en los slots
altos (`44..75`). El código PAL (`ROM 0x1EA30`) mapea los códigos EUC `B0A1..B0CA` (+`A1FC`,`A2A7`)
a índices `0x56..0x80`; el US (`ROM 0x1E0D8`) solo tiene los casos `D1DB/D9C7/E6AB/E0FA`.

Identificación (por contexto del texto DE/FR de la PAL, `notes/...texto-euc-jp-y-glifos-pal.md`):
`B0B2=ä`, `B0B3=â`, `B0B4=à`, `B0B7=ê`, `B0B8=è`, `B0B9=é`, `B0BA=ü`, `B0BF=ö`, `B0C1=ç`,
`B0CA=ß`, `A1AD='`. **No hay texto español en la PAL** (edición En/Fr/De), así que **ñ/¿/¡ (y
probablemente á/í/ó/ú) no están confirmados**; hay que verificarlo visualmente (hojas en
`work/fonts/font_eu_color4_idx117.png`, rejilla de 11 glifos por fila → `slot = fila*11+col`).

Alineando US↔EU (DP sobre los bitmaps), los glifos nuevos aparecen **en grupos justo después de
su letra base** (p. ej. tras la base hay 3-6 variantes). Es un patrón de "vocal + acentos", no un
bloque apéndice: respalda que el juego generó un charset latino con acentos insertado por letra.

## 4. Implicación para el plan B

Transplantar la fuente PAL tal cual obliga a: (a) sustituir el fichero `color4` y (b) portar/parchear
las funciones de mapeo `0x8001D394`/color (código residente, ADR 0002). Y **no garantiza** los
caracteres específicos del español.

**Vía recomendada (más robusta y de estilo idéntico):** conservar el motor de texto del juego y
**inyectar glifos propios** en runtime:

1. `font_dump.py` permite extraer los bitmaps base (letras sin acento) en el formato exacto.
2. Autorar los glifos que falten (á é í ó ú ñ ü ç à è ¿ ¡ …) como bitmaps 8×12 4bpp = 48 B,
   reutilizando la letra base + píxeles de acento → estilo idéntico.
3. En runtime: **override de `func_8001BFE4`** (o volcar dentro del buffer cargado
   `0x801077E0`/fichero) para servir esos bitmaps, y extender el mapeo `0x8001D394` (override)
   para rutear 2 bytes EUC reservados (p. ej. `B1A1..`) a los slots nuevos.
4. En `src/subsystems/text.cpp` (traducción) emitir esos 2 bytes EUC para las letras acentuadas.

Esto cubre ES/CA/FR/DE al 100 % y no depende de los gaiji de la PAL. Alternativa mínima: usar
**solo** los gaiji que la PAL sí tiene (ä â à ê è é ü ö ç ß) para FR/DE y dejar ES/CA en ASCII
hasta autorar los que falten.

## 5. Decisión y diseño de implementación (B, ES/CA/FR/DE)

Vía elegida por el mantenedor: **inyección de glifos propios** (cubre los 6 idiomas, estilo idéntico,
sin depender de la PAL). Diseño:

1. **Autorar** los glifos que falten (á é í ó ú ñ ü ç à è ê â è…, ¿ ¡) en el formato del motor.
   Lo más fiable es **componer** desde la letra base del propio fichero + píxeles de acento (mismo
   estilo). El set de glifos por idioma se puede generar en build-time (`tools/text/`) a un header C.
2. **Inyectar en runtime** sin tocar el C generado (patrón ADR 0002 / `add_loaded_function`):
   - *Opción A (código propio 2 bytes)*: emitir el char acentuado como 2 bytes EUC en
     `src/subsystems/text.cpp`; override de `func_8001D394` (mapea nuestro código a un slot libre) +
     `func_8001BFE4` (sirve nuestro bitmap). Requiere gestionar longitudes de registro (2 B vs 1 B).
   - *Opción B (donante ASCII, recomendada)*: elegir ASCII poco usados (`~ @ # $ ^ _ [ ] { }`) como
     **donantes**; sustituir en la traducción la letra acentuada por el donante (1 B → longitudes
     intactas); override de `func_8001BFE4` que, si `a1` es el código resuelto de un donante, escribe
     nuestro bitmap (derivado de la letra base en ese mismo tamaño). El código del donante se obtiene
     llamando a `func_8001D394` original con su código EUC (`0x80044548` es la tabla ASCII→EUC).
3. Elegir la **fuente/estilo** objetivo (ver §6): p. ej. forzar el mismo estilo que use el menú.

### §6. Instrumentación añadida (esta sesión)

Override gateado por **`HH_FONT_TRACE=1`** (`src/hooks/sections.cpp`): `hh_font_trace_d394` y
`hh_font_trace_bfe4` delegan en el original y anotan a `hh.log` (una vez por par único):

```
[font] d394 code=XXXX -> N (slot N>>1)           # tabla EUC -> slot, real
[font] bfe4 color=C code=XXXX slot=N stride=S fileidx=F
```

Esto resuelve empíricamente, en Windows (headless no dibuja texto sin input): (a) la tabla
código→slot, (b) **qué color/estilo** usa cada pantalla y (c) el `fileidx`/`stride` (fuente). Nota:
la fórmula del código→offset es `offset = tblA[color]*(code>>1)`, con `tblA` (`0x80044624`) =
`32,50,60,78,48,78`; hay que verificar el `>>1` con la traza.

## 7. Pendiente / siguiente paso

- En **Windows**: `HH_FONT_TRACE=1` + `HH_LANG=es`, recorrer título/menú/ajustes y recoger `[font]` de
  `hh.log` → fija el mapping real y el estilo del menú.
- Con eso, generar los bitmaps acentuados (composición base+acento) e implementar la Opción B.
- Confirmar visualmente el set PAL (`work/fonts/font_eu_color4_idx117.png`) por si sirviera de atajo
  para FR/DE (regen de `á/í/ó/ú/ñ` igualmente propio).
