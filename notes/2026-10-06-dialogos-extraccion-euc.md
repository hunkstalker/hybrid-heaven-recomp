# Diálogos in-game: son EUC-JP de ancho completo (no ASCII) — extractor y cobertura

> Sesión 2026-10-06 (continuación de la tarea de traducción, `TODO.md` "Ahora" #1 y `RETOMAR.md`
> §"TAREA SIGUIENTE"). Objetivo de esta sesión: **herramienta de extracción de diálogos** (paso 1
> acordado con el mantenedor). Alcance del mantenedor: **solo diálogos del gameplay**; menús/ayuda/
> sistema quedan fuera.

## 0. Resultado corto

- El spike de 2026-09-23 acertó para **menús/ayuda/sistema** (ASCII plano, campos fijos) pero **no**
  para los **diálogos**: estos usan el **mismo motor EUC-JP** del original japonés, con el inglés
  guardado como **ASCII de ancho completo** (`A3xx`) y los acentos PAL como **gaiji** (`B0xx`).
- Por eso el motor actual (`src/subsystems/text.cpp`, `tools/text/extract_strings.py`) **no ve ningún
  diálogo**: solo acepta bytes `0x20–0x7E`.
- Nueva herramienta **`tools/text/extract_dialogues.py`** (decodifica EUC, agrupa mensajes, exporta
  TSV/únicas, emparejado US↔EU best-effort). Inventario USA: **2.509 líneas, 2.260 únicas, 936
  mensajes** (80 módulos; ~30 concentran el diálogo). Salidas en `work/dialogues/` (gitignored).

## 1. Evidencia: dos codificaciones

- **ASCII plano** (ya cubierto): `módulo 23` (título/menú/créditos/final), `módulo 56` (ayuda/combate,
  `You are poisoned.`…), etiquetas de zona/sistema.
- **EUC-JP ancho completo** (diálogos): p. ej. `módulo 27` US, prólogo in-game:
  `Latin1: a3 c9 a1 ad a3 ed ...` → `euc_jp` → `Ｉ´ｍ　ｇｌａｄ...` = "I'm glad I made it in time".
- Confirmación JP: `módulo 27` JP tiene el mismo diálogo en kanji EUC-JP (motor de mensajes = EUC).
- Confirmación EU: `módulo 26` EU trae EN+DE+FR (p. ej. `Welcome to the birth area,` /
  `Willkommen im Geburtsbereich,` / `Bienvenue dans la zone de naissance,`); los acentos FR/DE son
  gaiji `B0xx` que EUC-JP decodifica como kanji y la fuente PAL remapea (`d[ü]mmlich`, bytes
  `a3 e4 b0 ba ...`).

## 2. Gramática del script de diálogo (medida en `módulo 27` US)

- Una **línea** = tira maximal de pares EUC que decodifica a texto latino (ancho completo + gaiji +
  puntuación `A1xx`).
- Tras la línea va un **opcode de 2 bytes**: `f3 00`/`f0 00` = salto de línea; `fa 00`/`fe 00` = fin.
- Un **mensaje** = 1..N líneas; se cierra cuando **entre el final de una línea y el principio de la
  siguiente** aparece un `fa 00`/`fe 00`. (El parser por "terminador de la propia línea" falla por
  secuencias `f0 00 fa 00`; el criterio del hueco es el robusto.)
- Ejemplo (`módulo 27`):
  ```
  ...time            f3 00            (salto)
  ...to meet you．   fa 00            (fin mensaje 1)
  00 00 00 00 00 f0 00 f8 00 00 00 00 00
  You must be ...    f3 00
  confused ...       f3 00
  right now...       f0 00 fa 00      (fin mensaje 2)
  ```

## 3. Herramienta `tools/text/extract_dialogues.py`

- Autodetecta la tabla Nisitenma (`Nisitenma-Ichigo`) → vale US/EU/JP.
- Decodifica pares EUC: `A3xx`→ASCII, `A1xx`→puntuación/espacio, `B0xx`→gaiji latino (mapa
  **provisional**, ver §4). Los pares que no son texto latino se descartan (rechaza el ruido binario).
- Agrupa en mensajes (§2) y exporta:
  - `--tsv <f>`: `module\toffset\tmessage\tline` (offset relativo al módulo descomprimido).
  - `--unique <f>`: lista de líneas únicas (order de trabajo de traducción).
  - `--pair` con `--rom-us`/`--rom-eu`: emparejado EN/DE/FR (best-effort, ver §4).
- Uso:
  ```sh
  python3 tools/text/extract_dialogues.py --rom work/roms/us_retail.z64 --module 27
  python3 tools/text/extract_dialogues.py --rom work/roms/us_retail.z64 --all --tsv work/dialogues/us.tsv --unique work/dialogues/us_unique.txt
  python3 tools/text/extract_dialogues.py --rom-us .../us.z64 --rom-eu .../eu.z64 --pair --tsv work/dialogues/us_eu_pair.tsv
  ```

## 4. Emparejado DE/FR (referencia) — limitaciones conocidas

- El **orden de las 3 variantes en la EU varía por bloque/módulo** (en `módulo 26` va EN,DE,FR; en
  `módulo 12` no están contiguas). El emparejado por "EN seguido de DE y FR" falla; se usa ventana +
  detección de idioma por stopwords, pero es **best-effort** (115 pares coherentes de ~2.260 líneas).
- El **mapa gaiji** (`B0xx`→letra) es **parcial**; se ha verificado `B0BA=ü` en texto real y se toma
  el resto de `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`. No cubre `ñ`/`¿`/`¡` (la PAL no tiene
  español). Para es/ca se usarán nuestros códigos `B1xx` + glifos `color4`.
- Conclusión: DE/FR sirve como **referencia aproximada**; no es un requisito de salida.

## 5. Inventario (USA, `--all`)

`# módulos=625 mensajes=936 líneas=2509 únicas=2260` (80 módulos con algún texto; los reales de
diálogo son ~30). Top: `27` (310), `20` (256), `14` (213), `17` (148), `29` (145), `18` (136),
`21` (135), `26` (128), `12` (123), `31` (96), `45` (84), `32` (82), `7` (47, sistema), `43`, `53`,
`13`, `44`, `48`, `16`, `42`, `28`, `33`, `52`, `23`, `38`, `56`, `50`, `19`, `40`, `55`…

Nota de ruido: quedan restos (etiquetas de menú/gráficos como `SLAVE`/`NO DATA`, `1P 2P`) y líneas
con espacios iniciales; filtrar por módulo/limpiar en el paso de traducción.

## 6. Siguiente paso (no hecho aquí)

- Motor de sustitución **EUC** en `src/subsystems/text.cpp` (decodificar línea EUC → clave; encode de
  vuelta a ancho completo + gaiji `B1xx`). **Política de longitud**: de entrada conservar el nº de
  caracteres EUC del mensaje (permitir re-paginar líneas dentro del mensaje); crecer solo con holgura.
- **Fuente `color4`** (`src/hooks/text_glyphs.cpp` + `include/hh/game_font_color4.h`) para acentos.
- Redactar es/ca sobre `us_unique.txt`.
- **Validación visual en Windows** (mantenedor): no se concluye desde headless.
