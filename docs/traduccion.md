# Traducción del texto in-game (diálogos) — guía de la tarea

> **Documento vivo** para la tarea de localización del **diálogo del gameplay** (el que dibuja el
> propio juego). Complementa `documentation.md`, `architecture.md` y el ADR `0016`. Evidencia:
> `notes/2026-10-06-*`. Handoff: `../RETOMAR.md`.

## 1. Objetivo y alcance

- Localizar a **español (es)** y **catalán (ca)** el texto de los **diálogos del gameplay**
  (NPC/historia). **EN→ES** y **ES→CA**. **JA** pospuesto (requiere procesar la ROM JP).
- **DE/FR**: la ROM **EU** ya trae esas traducciones oficiales → se usan como **referencia**.
- **NO** es la intro (esa va por el overlay de subtítulos, `notes/2026-10-06-subtitulos-intro.md`).

## 2. Cómo funciona el motor (resumen)

- El diálogo va **inline en "nodos"** codificados en **EUC-JP de ancho completo** (inglés en `A3xx`),
  referenciados por tablas en otros módulos. **No** se mueve memoria (la ruta "reubicar nodos" se
  descartó: exigía parchear tablas cruzadas).
- `src/subsystems/text.cpp` decodifica cada **línea** EUC a la **clave inglesa**, la traduce y:
  - **A+ (reparto por mensaje)**: agrupa líneas hasta `fa 00`/`fe 00` y reescribe el tramo moviendo
    los saltos de línea. **Presupuesto = suma de caracteres del mensaje inglés.** Si no cabe, cae a
    **ruta A** por línea (y la línea que no cabe se deja en inglés).
- Acentos/tildes: inyección por color en `src/hooks/text_glyphs.cpp` (**color4**, 8×12, diálogo;
  menú sigue **color0**). La fuente sale de `include/hh/game_font_color4.h` (`tools/text/build_font.py`).
- Clave del `.txt` = **texto original inglés** (misma fuente que el menú; ADR `0014`).
- **Overlay propio del diálogo** (en `main`): capa propia que sustituye el
  dibujo del texto para **quitar el límite de longitud**. Lee **entradas de MENSAJE** del mismo
  fichero de idioma: **clave = mensaje inglés completo** (líneas unidas con espacio), **valor = la
  traducción con los saltos "baked"** en `\n`. Así dos mensajes que comparten una línea no chocan
  (el texto del guion se repite). Ver ADR `0017` y `notes/2026-10-07-experimento-overlay-dialogo.md` §9.

## 3. Herramientas

| Herramienta | Uso |
|---|---|
| `tools/text/extract_dialogues.py` | Extrae diálogos EUC: `--module N`/`--all`, `--tsv`, `--unique`; emparejado US↔EU con `--pair` (DE/FR). |
| `tools/text/build_dialogue_messages.py` | Añade a `assets/lang/<lang>.txt` las **entradas de MENSAJE** (clave = mensaje inglés completo; valor con saltos `\n`). Usa la versión larga `(tú)` si existe; si no, la traducción por-línea correcta. `--lang es\|ca [--dry-run --show N]`. |
| `tools/text/check_dialogue_fit.py` | **Valida** que cada mensaje traducido cabe en su presupuesto y da cobertura. `--lang es\|ca [--module N] [--verbose]`. |
| `tools/text/check_translations.py` | Valida las tablas de idioma (claves duplicadas, formato). |
| `tools/text/build_font.py` | Genera `include/hh/game_font_color4.h` (glifos acentuados color4). |

ROM de trabajo (generada, no versionada): `work/roms/us_retail.z64` (US) y `/app/roms/baserom.eu.z64`
(EU). Referencia DE/FR: `work/dialogues/us_de_fr.tsv` (generada con `--pair`).

## 4. Pipeline

1. Extraer los mensajes del módulo: lista de líneas inglesas (clave) — `extract_dialogues.py`.
2. Traducir **EN→ES** (español de España). Referencias: `work/dialogues/us_de_fr.tsv` y, para párrafos
   completos, el **guion inglés de GameFAQs** (*Hybrid Heaven - Game Script*, Pandora_aden).
3. Traducir **ES→CA** (catalán a partir del español).
4. Volcar las correcciones en `assets/lang/es.txt` y `assets/lang/ca.txt` (clave = línea inglesa; las
   que no cabían van como `(tú)` en `assets/dialogos.txt`).
5. Generar las **entradas de MENSAJE** (para el overlay): `python3 tools/text/build_dialogue_messages.py
   --lang es` (y `--lang ca`). Idempotente; no toca los menús.
6. Validar: `python3 tools/text/check_dialogue_fit.py --lang es`, `check_translations.py [--lang ca]` y
   `python3 tools/analysis/docs_index.py --check`.

## 5. Reglas de redacción (importantes)

- **Clave exacta**: la línea inglesa tal cual (¡incluye **espacios dobles** y puntuación!). Si la clave
  no coincide, no se sustituye.
- **Presupuesto**: el español **cabe o no** según la suma de caracteres del mensaje inglés. El español
  es ~15-25% más largo → hay que **abreviar/ser conciso**. Comprobar con `check_dialogue_fit.py`.
- **Ancho de caja**: ~**30-32 caracteres por línea**, ~4 líneas. Partir las líneas para que quepan.
- **Nombres propios / neologismos**: seguir la **línea oficial**. Ejemplo canónico: **`Gargatuan`** se
  queda **igual que en inglés** (el equipo oficial alemán lo respetó; el francés lo "corrigió" a
  *Gargantuan*, pero se apartó). **Ante cualquier duda de este tipo (nombres, términos inventados,
  convenciones, tuteo/usted, siglas): PREGUNTAR al mantenedor antes de decidir.**
- Acentos: escribir los caracteres reales (`á é í ó ú ñ ü ¿ ¡`); el motor los dibuja (color4).
- **No asumir** que el índice de módulo = área/orden del juego. Los módulos son **escenas**; si hace
  falta el orden, confirmarlo con el mantenedor.

## 6. Estado y cobertura

- Motor **hecho y validado en Windows** (A+ + color4).
- **Alcance solo-diálogo**: **27 escenas** = **872 mensajes / 2173 líneas únicas** (los 936/2509 totales
  incluyen UI/menú, fuera de alcance).
- **Hecho (2026-10-07)**: módulos **12, 13, 14, 16, 17** completos (es + ca). **Parcial**: 27 (46/109).
- **Cobertura**: **262/872 mensajes ≈ 30 %** · **668/2173 líneas únicas ≈ 30.7 %**. Medir con
  `check_dialogue_fit.py --lang es|ca` (`lineas_sin_traduccion`). Detalle:
  `../notes/2026-10-07-dialogos-traduccion-es-ca.md`.
- **Pendiente**: módulos 18, 19, 20, 21, 26, 28-33, 37, 38, 40, 42-45, 47, 48, 50, 52, 53 y terminar 27.

## 7. Validación

- Compila en Linux para errores (`cmake --build build/linux -j`).
- **Visual en Windows** (mantenedor): no se concluye solo desde headless. Reconstruir y llegar a la
  escena; comprobar tildes y que no haya inglés mezclado.
- **Overlay del diálogo — validado (2026-10-07)**: primer diálogo (módulo 12) correcto (texto completo,
  respuesta al input y cierre de la caja). Herramientas de depuración: `HH_DLG_DY=-64` +
  `HH_DLG_KEEP_ORIGINAL=1` (ver `notes/2026-10-07-experimento-overlay-dialogo.md` §9.7).
- **Espacios extremos — RESUELTO**: las claves con espacio inicial/final (p. ej. módulo 12
  `changers are top secret, `) se casan recortando extremos en `translate_euc()` y
  `check_dialogue_fit.py`; y `build_dialogue_messages.py` toma el valor correcto de la tabla por-línea
  (no del `dialogos.txt` mezclado). Pendiente el repaso visual del resto de módulos.
