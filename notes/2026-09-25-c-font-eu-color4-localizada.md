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

## 5. Pendiente (paso 4, vía B)

1. **Identificar** cada slot acentuado (leer los 76 del preview y anotar el Unicode).
2. **Integrar**: el overlay usa `color0` 8×8; o se migra el atlas del overlay a `color4` 8×12
   (misma fuente que el juego in-game) o se transportan los bitmaps. Decidir y reescalar layout.
3. Quitar el plegado `to_ascii` y mapear UTF-8 → slot.
4. Validar con `HH_MENU_SCREEN=5` (IDIOMA) y navegando.

## 6. Nota de higiene

`notes/eu_manifest.yaml` tiene offsets **incorrectos** para los ficheros de fuente (al menos
107-111 equivalentes). Corregir o marcar; la herramienta no depende de él.
