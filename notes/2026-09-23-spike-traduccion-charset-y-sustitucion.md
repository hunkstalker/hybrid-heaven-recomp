# Spike de traducción — charset USA resuelto y sustitución en runtime (módulo 23)

> Sesión 2026-09-23 (continuación del handoff `RETOMAR.md` §Tarea de ESTA sesión).
> Spike go/no-go para la base del selector de idioma (ADR 0008). Validado en **Linux headless**
> (compila y sustituye en memoria); **falta la validación visual en Windows**.

## 0. Resultado corto

- El **"encoding custom" USA no es tal**: el texto son **cadenas ASCII** terminadas en NUL,
  guardadas en **campos de ancho fijo rellenos con espacios (0x20)**. Los bytes raros que se veían
  en la ROM eran los **flujos comprimidos LZKN64** (copias literales y comandos), no códigos de
  texto. Los prefijos `%p`/`%m`/`%a`/`%f` sí son marcas de formato/estilo (printf-like).
- Módulo con el texto del **título/menú/opciones**: **Nisitenma idx 23** ("expansionram";
  ROM `0x5F1190`, base `0x801BF1A0`, descompresión 68432 B). Cargado por `trans` (2 veces, en
  `0x801BF1A0` y `0x801FA948`).
- **Sustitución en runtime implementada** interceptando el loader `trans` (ya cacheado):
  `hh_trans_load` traduce el buffer descomprimido **antes** de escribirlo a RDRAM. 68 cadenas
  traducidas en el módulo 23 (0 descartadas).
- **Registros de tamaño fijo con holgura**: las tablas son de **12/16 bytes** con relleno de NUL.
  Ej.: `EXIT` ocupa 4 B de texto en un registro de 12 (8 NUL de holgura); `" NEW GAME   "` 12 B en
  16. Es holgura **deliberada** (la versión PAL guardaba 3 idiomas) → se usa para traducciones algo
  más largas; el registro se reescribe con relleno de espacios + NUL. Knob de holgura máx.: 16 B.
- **Falta**: validación visual Windows y, para *cambio en vivo* de idioma, la rutina text-emit
  (el hook actual traduce al cargar el módulo, no por-frame).

## 1. Charset: derivación (paso 1 del plan)

Herramienta nueva `tools/text/extract_strings.py` (ROM → texto):

```sh
python3 tools/text/extract_strings.py --module 23      # descomprime y lista cadenas
python3 tools/text/extract_strings.py --off 0x5FB543   # localiza el módulo por offset
python3 tools/text/extract_strings.py --all --tsv work/text_strings.tsv
```

Hallazgo de formato (ejemplo, módulo 23 descomprimido):

```
00fa24  20 4e 45 57 20 47 41 4d 45 20 20 20 00   " NEW GAME   \0"
00fa34  20 43 4f 4e 54 49 4e 55 45 20 20 20 00   " CONTINUE   \0"
00fa44  20 42 41 54 54 4c 45 20 4d 4f 44 45 00   " BATTLE MODE\0"
00fa64  20 52 45 53 4f 4c 55 54 49 4f 4e 20 00   " RESOLUTION \0"
00fb80  20 47 41 4d 45 20 53 54 41 52 54 00      " GAME START\0"
```

Cada campo: relleno de espacios + NUL; a veces prefijo de formato (`%p`, `%m%p`, `@%m%p`, `%f`,
`%m%a`). Los nombres de fichero de origen (`/hdisk1/u/nu64/rz011_usa/main/game/source/*.c`) y
algunas cadenas en SJIS (debug japonés) siguen presentes en el binario, pero **el texto de la UI
USA es ASCII plano**.

**Registros de tamaño fijo**: los campos van en registros de **12 o 16 bytes** con NUL de relleno
(no cadenas empaquetadas). Ejemplos medidos:

```
NEW GAME    : 12 B texto + 4 NUL = registro 16
GAME START  : 11 B texto + 1 NUL = registro 12
EXIT        :  4 B texto + 8 NUL = registro 12
RESOLUTION  : 14 B texto + 2 NUL = registro 16
```

→ la holgura es **deliberada** (la versión PAL guardaba 3 idiomas). La sustitución la aprovecha
(hasta 16 B de relleno) y reescribe el registro con espacios + NUL, sin invadir el siguiente.

## 2. Sustitución en runtime (implementación)

- `src/subsystems/text.cpp` (nuevo): tabla EN→ES (embebida; `assets/lang/es.txt` como copia
  editable), escaneo por segmentos NUL, sustitución **preservando la longitud exacta** del campo
  (no altera el layout). Knobs: `HH_LANG=es`, `HH_LANG_FILE=<ruta>`, `HH_TEXT_TRACE=1`.
  Si existe `lang/es.txt` junto al `.exe`, gana sobre la tabla embebida.
- `src/subsystems/trans_cache.cpp`: `store_guest_translated()` (hit/nativo) y `translate_rdram()`
  (fallback del loader original). El **cache persistente queda en inglés** (se traduce la copia que
  va a RDRAM), así se puede cambiar la traducción sin regenerar `cache/trans.bin`.
- `CMakeLists.txt`: añade `src/subsystems/text.cpp`.

### Validación headless (Linux)

```sh
cmake --build build/linux -j
cd build/linux && DISPLAY=:99 SDL_VIDEODRIVER=x11 \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_LANG=es HH_TEXT_TRACE=1 timeout 40 "./Hybrid Heaven Recomp"
```

`hh.log`:

```
[text] idioma 'es' (tabla embebida, 22 entradas)
[text] 68 cadenas traducidas (bloque de 68432 bytes)
[trans] load src=005F1190 size=00AD36 dst=801BF1A0 kind=hit len=68432
```

### Validación pendiente (Windows)

Compilar y ejecutar con `HH_LANG=es`; en la pantalla de título y el menú de opciones deberían
verse `SELECCIONA`, `INICIAR`, `JUEGO NUEVO`, `CONTINUAR`, `MODO LUCHA`, `SONIDO`, `RESOLUCION`,
`DIFICULTAD`, `SALIR`.

## 3. Limitaciones y siguiente paso

- Solo se traduce lo que cabe en el **registro** original (texto + holgura de NUL, hasta 16 B). No
  hay glifos nuevos (acentos/`ñ`/`¿`/`¡`): la traducción actual es ASCII sin acentos.
- **Cambio en vivo** de idioma y traducción de diálogos dinámicos (con `%d`, etc.) requieren la
  **rutina text-emit** (paso 2 del plan). Con el hook de carga basta para el go/no-go visual.
- Ampliar cobertura: extraer todos los módulos (`extract_strings.py --all`) y crecer la tabla;
  valorar glifos nuevos en la fuente (paso 4 del plan).
