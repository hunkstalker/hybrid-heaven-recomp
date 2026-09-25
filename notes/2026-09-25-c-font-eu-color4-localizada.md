# C — Fuente EU (`color4`) localizada y decodificada: gaiji acentuados reales

> Sesión 2026-09-25. Desbloquea el paso 4 (acentos) del menú A2 y la vía B (glifos **reales**, no
> inventados). Continúa `notes/2026-09-23-b-fuente-formato-y-gaiji.md`.

## 1. Problema

La nota B decía que el fichero `color4` EU estaba en el `original_offset` del manifiesto EU
(`notes/eu_manifest.yaml`, índice 117 → `0x70E4AA`, 3648 B). Al decodificarlo con el esquema
correcto (2bpp, 2 glifos/bloque, paridad) **salía ruido**. Comprobado: esos bytes son **código
MIPS**, no bitmaps. **Los offsets de los ficheros de fuente del manifiesto EU están desfasados.**

## 2. Localización real (MEDIDA)

Los ficheros de fuente EU se localizan por **vecindad en el residente, junto al `color0`**, que es
**byte-idéntico al US** (confirmado): el `color0` US (idx107, 4096 B) aparece tal cual en
`eu_dec.z64` @ **`0x8C2290`**. A partir de ahí:

| estilo | offset EU | tamaño | ¿== US? |
|---|---|---|---|
| color0 | `0x8C2290` | 4096 | sí (idx107) |
| **color4** | **`0x8C3290`** | **3648** | **no** (US idx108 = 2112 B) |
| color1 | `0x8C40D0` | 8000 | sí (idx109) |
| color2 | `0x8C6010` | 2592 | sí (idx110) |
| color5 | `0x8C6A30` | 1104 | sí (idx111) |
| color3 | `0x8C0240` | 8272 | sí (idx106) |

El `color4` EU (`0x8C3290`, 48 B/bloque, 8×12) **decodifica limpio** con el esquema 2bpp/paridad:
`valor 1` = "1", etc. **76 glifos** (US 44).

## 2b. CORRECCIÓN — el estilo del menú es `fileidx=108` y `stride=32` (MEDIDO con el dump)

El dump runtime (`HH_FONT_DUMP_GLYPH=0` en el port US) muestra que al componer texto el motor llama
`func_8001BFE4` con **`stride=32` y `fileidx=108`** (`[font] bfe4 color=0 code=... stride=32
fileidx=108`). Es decir:
- El estilo que usa el **menú/UI** no es "color0 idx107 con stride 32" sino **el fichero 108 con
  stride 32** (8×8, 32 B/glifo). La suposición previa de "color4 = 48 B, 8×12" era **incorrecta**.
- El fichero 108 US (2112 B) tiene por tanto **66 glifos** de 32 B (no 44); el EU (3648 B) tendría
  **114**. El mapeo `EUC→valor` (`B0xx→0x56…`) es **compartido** por color0/color4 (`func_8001C88C`
  y `func_8001D2E0` usan las mismas subrutinas `C670/C6E8/C734/...`).

**Pendiente de fijar con evidencia**: el layout exacto del fichero EU (¿8×8/32 B fila a fila? ¿orden
de bloques?) y la correspondencia `B0xx → glifo`. La deducción offline no basta y hay que hacerlo con
el **oráculo del emulador** corriendo la ROM EU (volcar RDRAM tras cargar un gaiji) — ver
`docs/workflows.md` §6.

## 2c. Intento previo (descartado): shift de 2 filas

Se probó asumir 48 B/12 filas con "sangrado" de 2 filas (shift 16 px); **no es el caso**: con el dato
real (`stride=32`, `fileidx=108`) esa hipótesis queda descartada. `EU_SHIFT_PX` debe ser **0**.

## 3. Mapeo EUC → slot (MEDIDO)

Tabla de gaiji EU en `eu_dec.z64` @ **`0x1EA30`**, entradas de 8 B:
`34 01 <EUC_BE> <props> <...> <slot_hi> <slot_lo>`. Para `props=0x24`, el slot es el byte 7:
`B0A1→0x56`, `B0A2→0x57`, … **secuencial** (`B0CA→0x7F`), más `A1FC→0x56`, `A2A7→0x61`.
Son 41 códigos `B0xx` en esa tabla (resto son kanji JIS fila 16 que la PAL reasigna).

El estilo `color4` EU contiene, por slot: dígitos (0-9), mayúsculas (10-…), latín extra
(`Ä` @44-49) y los **acentos** en los slots altos (`à è é ü ã ñ ß`…). Identificación de cada
acento: pendiente de fijar leyendo el texto DE/FR de la PAL (la nota B dio `B0B2=ä, B0B3=â,
B0B4=à, B0B7=ê, B0B8=è, B0B9=é, B0BA=ü, B0BF=ö, B0C1=ç, B0CA=ß`) **verificada contra el bitmap**.

## 4. Herramienta

`tools/text/extract_eu_font.py`:
- Localiza `color4` EU por vecindad del `color0` US (robusto; no usa el manifiesto EU).
- Extrae los 76 glifos y emite `--preview` (`work/fonts/eu_gaiji.png`) + header C (`--out`).
- Lee el mapeo `B0xx→slot` de la tabla EU.

## 4b. Captura con BizHawk (2026-09-25) — buffer del menú EU localizado

Con `tools/analysis/bizhawk_eu_glyph_capture.lua` (v2, por botón) el mantenedor volcó RDRAM de la ROM
EU (17 snapshots, `work/eu_glyphs/`). El dominio de N64 en BizHawk es **"System Bus"**. Hallazgos:

- Los volcanes contienen **141 bloques de 32 B de la fuente EU** (confirma que el motor usa esa
  fuente). Pero el motor **no copia el bloque tal cual**: lo **compone** (despaqueta/reempaqueta), así
  que la coincidencia exacta no localiza el buffer.
- **Buffer de glifos del menú EU ≈ `0x80109B60`** (zona que cambia al cambiar el texto del menú; en el
  frame francés aparecen glifos que no están en el inglés). Se leen letras sueltas 8×8.
- La `func_8001D394` EU está en `0x8001ECFC` (prólogo `27bdffd8`); el despacho por color comparte
  subrutinas con US (`C670/C6E8/C734/...`).

Herramienta: `tools/analysis/eu_glyphs_find.py --buf 0x80109B60 --render` (PNG del buffer).

**Pendiente**: fijar el **layout exacto del buffer** (tamaño de tile/orden) y el `valor→glifo` real
para identificar cada acento; luego decidir vía (migrar overlay a la fuente de menú EU, o componer).

## 4c. Fuente EU EXTRAÍDA Y LEGIBLE (2026-09-25) — formato confirmado

**El fichero de fuente "idioma" EU está @ `0x8C3298`** (localizado por el primer bloque del fichero
US `idx108`). Formato **idéntico al US**:
- 32 B por **par** de valores (`bloque = v>>1`), paridad `v&1` elige el plano.
- 8×8 2bpp, 2 px/byte (nibble). **US = 66 valores** (2112 B); **EU = 114 valores** (3648 B).
- Verificado: `v1`="1", `v2`="2"; los valores altos son los acentos.
- **El fichero EU NO es US+extra: está reordenado por completo** (solo 1 bloque coincide). El orden
  de valores difiere, así que el `valor→Unicode` hay que **identificarlo leyendo** la hoja.

Herramienta: `tools/text/extract_eu_font.py --sheet work/fonts/eu_all.png` (hoja etiquetada por valor).

Lectura preliminar (valores altos, acentos): `56=Ü`, `64=Ï`, `65=Ä`, `74=Ö`, `85=À`, `86=Ç`,
`89=É`, `93=Ê`, `96=Î`, `98=Ì`, `103=Ù`, `104/105=É`, `106=ö`, `107=ü`, `108=ß`, `112/113`… (revisar).

## 5. Pendiente (paso 4, vía B)

1. **Identificar** cada slot acentuado (leer los 41 gaiji del preview `work/fonts/eu_gaiji.png` /
   `/tmp` sheet y anotar el Unicode). Confirmados por texto DE/FR: `B0B2=ä, B0B3=â, B0B4=à,
   B0B7=ê, B0B8=è, B0B9=é, B0BA=ü, B0BF=ö, B0C1=ç, B0CA=ß`. El resto de `B0xx` mezcla símbolos
   (¡ ? ’ “ ” …) y más acentos (`ï î ì Ä Ö Ü ù`), pendientes de confirmar slot por slot.
2. **Integrar**: el overlay usa `color0` 8×8; o se migra el atlas del overlay a `color4` 8×12
   (misma fuente que el juego in-game) o se transportan los bitmaps. Decidir y reescalar layout.
3. Quitar el plegado `to_ascii` y mapear UTF-8 → slot.
4. Validar con `HH_MENU_SCREEN=5` (IDIOMA) y navegando.

## 5b. Catalán / francés — glifos que podrían faltar

- **Francés**: la PAL **no** incluye `Ò`/`ò` grave (solo `à è`), ni `œ`. Si los necesitamos, la vía
  acordada es **derivar** (`Ó` girada 180°, o composición base+marca) y añadir el slot.
- **Catalán**: necesita `à è é í ï ò ó ú ü ç` + `·` (punt volat) y `l·l`. La PAL cubre casi todo
  salvo quizá `í`/`ó`/`ú` con acento agudo en ciertas posiciones y `ï`/`ò`; revisar contra los 41
  gaiji. El `·` no está en la fuente y habría que dibujarlo (como `:`/`.`/`%`).
- Verificar cada caso contra el preview antes de decidir "derivar".

## 6. Nota de higiene

`notes/eu_manifest.yaml` tiene offsets **incorrectos** para los ficheros de fuente (al menos
107-111 equivalentes). Corregir o marcar; la herramienta no depende de él.
