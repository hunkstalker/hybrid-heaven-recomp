# Tipografías del juego — extracción y uso en los menús

> **Documento vivo.** Fuente de verdad de las **tipografías** (`color0..5`): dónde están en la ROM, cómo
> se decodifican, la API del port para usarlas en la UI propia (`hh::overlay`) y el mapeo medido del
> `DATA LOAD`. Evidencia: `../notes/2026-09-23-b-fuente-formato-y-gaiji.md`,
> `../notes/2026-09-30-tipografias-data-load-hallazgos.md`. Modelo técnico: `architecture.md` §7.

## 1. Qué fuentes hay

El motor **no usa una textura de fuente**: carga el bitmap de cada glifo desde **6 ficheros** de la
tabla Nisitenma (uno por "color"/estilo). Todas las del US están **descomprimidas** en la ROM:

| `Face` | estilo | idx Nisitenma US | offset ROM US | celda | stride | uso típico |
|---|---|---|---|---|---|---|
| `Color0` | color0 | 107 | `0x6E3CD6` | 8×8 | 32 | menú/overlay; filas del DATA LOAD (`AREA/LEVEL/TIME`, `CONTROLLER PAK`) |
| — | color1 | 109 | `0x6E5516` | 10×10 | 50 | (no usado por la UI propia) |
| — | color2 | 110 | `0x6E7456` | 10×12 | 60 | (no usado) |
| `Color3` | color3 | 106 | `0x6E1C86` | 12×13 | 78 | **título grande** (`DATA LOAD`) |
| `Color4` | color4 | 108 | `0x6E4CD6` | 8×12 | 48 | **texto in-game** y mensaje (`Select play data…`) |
| — | color5 | 111 | `0x6E7E76` | 12×13 | 78 | (no usado) |

Los offsets/sizes salen del manifiesto (`notes/us_manifest.yaml`). **EU** usa otros índices Nisitenma
(ver `tools/text/font_dump.py`) y solo difiere en `color4` (acentos); ver §7.

## 2. Formato del glifo (regla dura)

`2bpp`, **dos glifos empaquetados por bloque** de `stride` bytes: `bloque = valor>>1`, `paridad =
valor&1`; el glifo PAR usa los bits 2-3 de cada nibble (`0xCC`), el IMPAR los bits 0-1 (`0x33`).
**Niveles dentro del glifo** `[MEDIDO]` (2026-09-30): **1 = tinta** (color pleno del texto), **2 =
gris** (sombra SUAVE del motor, ~`140/255`), **3 = negro** (sombra). El atlas guarda el nivel como
**luminancia en R** y `shaders/OverlayPS.hlsl` hace `lerp(negro, color del texto, R/255)`; por eso el
nivel 2 es un gris (no negro). Un ejemplo claro es la `l` de `color4`: su gancho superior es un único
pixel de nivel 2 (gris), no un punto negro. Decode: `src/subsystems/font.cpp`
(`bake_face`/`bake_atlas`). **No** usar la vista 4bpp de `tools/text/font_dump.py` (es la unión de los
dos glifos empaquetados).

## 3. Cómo elige la fuente el motor `[MEDIDO]`

- **Compositor** `func_8001B204(a0, a1, a2, a3)`: `a0` = **contexto/slot de salida** (0..0x1B, indexa
  `D_8008EF70 + a0*282`), `a1`/`a2` = **X/Y** (`a1=0x7D0` = sentinel "centrar"), `a3` = texto.
  `a0` **no** es la fuente (la premisa antigua era errónea).
- **La fuente se elige con el código `%m <n>` DENTRO de la cadena** (n=0..5) → `D_80090E48 = n`. Sin
  `%m`, el color arranca en 0 (color0). Otras marcas `%x %d %s …`; ver `notes/2026-09-23-b-...`.
- `func_8001D394(color, code)` mapea el código EUC → **valor de glifo**; `func_8001BFE4(color, valor)`
  carga el bloque (`bloque = valor>>1`) y `func_8001BD20(color, code)` da el **avance** (§6).
- Tablas del motor (residente): `tblB 0x8004462C` fileidx `{107,109,110,106,108,111}`;
  `tblA 0x80044624` stride `{32,50,60,78,48,78}`; anchos `0x8004461C {8,10,10,12,8,12}`.

### 3.1 Mapeo ASCII → valor de glifo por fuente

| Face | regla (ASCII) |
|---|---|
| `Color0` | `glyph_value`: espacio=0; `0-9`→1..10; `a-z`→11..36; `A-Z`→37..62 |
| `Color4` | **igual que color0** para ASCII (`glyph_value`) |
| `Color3` | **solo mayúsculas**: `'A'..'Z'` → `0x76 + (c-'A')` (espacio=0). Medido con `D=0x79,A=0x76,T=0x89,L=0x81,O=0x84` |

(`Color1/2/5` usan ordenaciones distintas, no cubiertas por la API; ver `func_8001D394`.)

## 4. API del port (usar en los menús)

Declarada en `include/hh/font.h` y cableada en `src/subsystems/font.cpp` + `src/platform/overlay.cpp`:

```cpp
enum class hh::font::game::Face { Color0, Color4, Color3 };
unsigned hh::font::game::face_cell_w(Face);   // 8, 8, 12
unsigned hh::font::game::face_cell_h(Face);   // 8, 12, 13
bool     hh::font::game::face_glyph_uv(Face, unsigned char c, unsigned& x, unsigned& y);
```

Para dibujar texto con una fuente concreta, basta rellenar `hh::overlay::Text.face` (por defecto
`Color0`). Ejemplo (el título del `LoadGame`):

```cpp
frame.texts.push_back({ x, y, scale_x, scale_y, hh::overlay::rgba(255,255,255,255),
                        "DATA LOAD", hh::font::game::Face::Color3 });
```

- El **atlas** es **uno** y se sube como textura en `overlay.cpp`: **128×227** =
  `color0` letras `128×128` + marcas `128×12` + `color4` `128×48` (16×4 celdas 8×12) + `color3`
  `128×39` (10×3 celdas 12×13). Se construye desde la ROM en `font::game::init()`.
- La rama `face != Color0` del bucle de texto dibuja **simple** (solo ASCII, sin marcas ni kana). La
  rama `Color0` mantiene **marcas de acento + kana + `glyph_left_bearing`** (no tocar).
- Las **marcas de acento** y la **kana** solo existen para `Color0` (fuente 8×8); ver §7.

## 5. Mapeo medido del `DATA LOAD` (2026-09-30) `[MEDIDO]`

| Texto | Face | evidencia |
|---|---|---|
| Título `DATA LOAD` | **Color3** | cadena `%m`+`DATA LOAD` con vararg 3; `bfe4 color=3 stride=78 fileidx=107` |
| Mensaje `Select play data to be loaded.` | **Color4** | `bfe4 color=4 stride=48 fileidx=109` |
| `CONTROLLER PAK` + filas `AREA/LEVEL/TIME` + valores | **Color0** | sin `%m` → color0; `bfe4 color=0 stride=32 fileidx=108` |

Cómo reproducirlo (headless Linux; `HH_NATIVE=1` evita el "blankeado" del overlay y deja ver el color
real del título):

```sh
cd build/linux
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_NATIVE=1 HH_FONT_TRACE=1 HH_FONT_DUMP_GLYPH=3 HH_MENU_TRACE=1 \
  HH_PRESS_SEQ="64:start,65:-,67:start,68:-,70:a,71:-,73:a,74:-" HH_AUTOQUIT=95 \
  timeout 130 "./Hybrid Heaven Recomp"
# -> hh.log: [font] d394/bfe4 color=… code=… stride=… fileidx=… ; [fontdump] volcado hex de glifos
```

Atajos útiles: `HH_MENU_SCREEN=19` fuerza la pantalla `LoadGame`; `HH_FONT_DUMP_GLYPH=<color>`
+`HH_FONT_DUMP_ONLY=<valor>` vuelca bloques concretos; captura con `DISPLAY=:99 import -window root`.

## 6. Avances (clave para el 1:1)

El motor **no** avanza un ancho fijo: `func_8001BD20(color, char)` devuelve el ancho con correcciones:

| Face | base | correcciones (código EUC) |
|---|---|---|
| `Color4` | 8 | **espacio = 4**; `f i j l r t` (EUC `A3E6/A3E9/A3EA/A3EC/A3F2/A3F4`) = 6 |
| `Color0` | 8 | (casos propios en `func_8001BD20`; el menú ya está validado) |
| `Color3` | 12 | sin correcciones |

**Estado:** **cableado** `hh::font::game::face_glyph_advance(Face, char)` (2026-09-30) y usado en
`src/platform/overlay.cpp` (pasada de puntuación y rama `face != Color0`). El avance del espacio de
`Color4` se **midió en la captura pareada** (el mensaje nativo calca con espacio=4; `func_8001BD20` da
`-2` sobre base 8, pero la medida del motor real es 4). El título `Color3` (12) y las filas `Color0` (8)
no cambian. Evidencia y medidas: `../notes/2026-09-30-data-load-maqueta-1a1.md`.

## 7. Acentos, kana y añadir una fuente

- **Acentos (ES/CA/FR/DE)**: solo el menú/`Color0` los compone a mano (letra base + marca) porque la
  ROM US no trae acentos en `color0`; ver `tools/text/menu_marks.py` e `include/hh/menu_marks.h`. La
  fuente **in-game** con acentos es **color4 EU**: `tools/text/build_font.py --style color4` →
  `include/hh/game_font_color4.h` (pendiente cablear en el texto in-game, no en este atlas).
- **Kana (JA)**: vive en los valores ≥64 de `color0`; mapeo en `include/hh/jp_kana.h`
  (`jp_kana_value`). Solo la rama `Color0` la resuelve.
- **Añadir una fuente nueva a la UI propia**: (1) entrada en `Face`; (2) offset/size/celda/stride en
  `font.cpp`; (3) ampliar `kFullHeight` y hornear con `bake_face(...)`; (4) UVs en `face_glyph_uv` y
  tamaño en `face_cell_w/h`; (5) usarla con `Text.face`. Documentar aquí el mapeo y el avance.

## 8. Referencias

- Formato/ficheros/PAL: `../notes/2026-09-23-b-fuente-formato-y-gaiji.md`.
- Motor de texto/EUC: `../notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`,
  `../notes/2026-09-23-a2-render-hook-y-atlas.md`.
- Mapeo del DATA LOAD (esta tanda): `../notes/2026-09-30-tipografias-data-load-hallazgos.md`.
- Herramientas: `tools/text/build_font.py`, `tools/text/font_dump.py`, `tools/text/menu_marks.py`,
  `tools/text/extract_jp_kana.py`.
