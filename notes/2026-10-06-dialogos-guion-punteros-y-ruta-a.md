# Diálogos: gramática del guion, punteros de entrada y ruta A (sustitución EUC in-place)

> Sesión 2026-10-06 (continúa `notes/2026-10-06-dialogos-extraccion-euc.md`). Implementación de la
> **ruta A** acordada con el mantenedor: sustituir las líneas de diálogo **en el sitio**, conservando
> la longitud, para validar el canal de punta a punta (motor EUC + fuente) con el **primer diálogo**.
> Alcance: **solo diálogos del gameplay**.

## 1. Gramática del guion (medida en `módulo 12`, conversación 1)

```
[texto] f3 00                                      ← salto de línea (no espera)
[texto] f3 00
[texto] fa 00 00 00 00 00 f0 00 f8 00 00 00 00 00  ← fin de mensaje + f8 00 = esperar botón
...
[texto] f0 00 fa 00 ... f0 00 fd 00 ff ff ff ff     ← fin de conversación (fd 00)
```

- `f3 00` = salto de línea. `fa 00` = fin del texto del mensaje.
- `f8 00` = **esperar pulsación** (una vez por mensaje); `fd 00` = fin de conversación.
- Opcodes/campos intercalados (`f0 00`, `fc 00`, `00 0a 1e 03`, `00 00 00 00`): se **conservan**.
- (Inferido del patrón de bytes; no leído aún del intérprete. Sin saltos internos en el bloque 1.)

## 2. Punteros de entrada (clave para la ruta B / longitud libre)

- El guion del primer diálogo está en `módulo 12` @`0x340C`.
- Base de módulo inferida `B=0x80240C28`; en el fichero `0x033F8` hay un **puntero**
  `0x80244034 = B + 0x340C`. En total **~16 punteros** a bloques de guion en el módulo (conversaciones).
- Al ser bloques **lineales con puntero de entrada**, la ruta B (reconstruir con longitud libre y
  repuntar) es viable; requiere una **arena en RAM** propia + parchear el/los punteros.

## 3. Ruta A implementada (`src/subsystems/text.cpp`)

- Nuevo camino **EUC** dentro de `hh_text_translate_guest` (además del ASCII de menús):
  - `euc_decode`: pares EUC → clave inglesa (`A3xx`→ASCII, `A1xx`→puntuación JIS, resto → no texto).
  - `utf8_to_euc`: traducción UTF-8 → EUC (`A3xx` alfanumérico, `A1xx` puntuación, acentos `B1xx`).
  - `translate_euc`: sustituye tiras EUC que casen con una clave **conservando el nº de caracteres**
    (rellena con `A1A1` si es más corta). Si no cabe o no es representable, deja el original.
  - `State::index` (`unordered_map clave→Key`) para búsqueda O(1).
- Tabla ASCII→EUC deducida de la ROM (puntuación): `' '`→`A1A1`, `'.'`→`A1A5`, `','`→`A1A4`,
  `'?'`→`A1A9`, `'!'`→`A1AA`, `"'"`→`A1AD`, etc.; alfanuméricos → `A3xx`.
- **Contenido de prueba** (accent-free, provisional) en `assets/lang/es.txt`: las 16 líneas de la
  conversación inicial (Mr.Diaz, `módulo 12`).

## 4. Validación

- **Lógica**: espejo Python del algoritmo sobre `módulo 12` → 16/16 líneas sustituidas, longitudes
  preservadas.
- **Compilación**: `cmake --build build/linux -j` → OK.
- **Visual**: pendiente de que el mantenedor lo valide en Windows (no se concluye desde headless).
  Prueba: `HH_LANG=es` (o F5/menú) y llegar al primer diálogo; debe verse en español (sin acentos).

## 5. Pendiente inmediato

- **color4**: servir glifos acentuados en el estilo del diálogo (`src/hooks/text_glyphs.cpp` +
  `include/hh/game_font_color4.h`) → necesario para tildes/`ñ`/`¿`/`¡`.
- **Ruta B** (longitud libre): arena RAM + repuntado de los punteros de guion.
- Redactar es/ca de verdad (revisión del mantenedor).
