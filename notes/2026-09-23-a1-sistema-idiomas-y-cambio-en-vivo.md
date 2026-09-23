# A1 — Sistema de idiomas + cambio en vivo (base del selector, ADR 0008)

> Sesión 2026-09-23. Primera parte de la vía **A** (UI/selector propio). Funcional; falta la parte
> visual (A2).

## Qué se ha implementado

- **Lista de idiomas "de serie"**: `en, es, ca, fr, de, ja` (`src/subsystems/text.cpp`). Además se
  detectan idiomas extra en `lang/*.txt` (junto al `.exe`) y en **mods** (`mods/*/lang/<code>.txt`).
- **Carga por idioma**: `lang/<code>.txt` (o `HH_LANG_FILE`); si falta, `es` usa la tabla embebida;
  cualquier otro sin tabla → se muestra el original (inglés). `en` = texto original.
- **Persistencia**: el idioma activo se guarda en `config.ini` `[lang] language = <code>` y se lee al
  arrancar (prioridad: `HH_LANG` > config > `en`).
- **Cambio en vivo**: `hh::text_set_language(code)` → recarga la tabla y llama a
  `hh_trans_reapply_language()` (`src/subsystems/trans_cache.cpp`), que **vuelve a escribir en RDRAM**
  los módulos ya cargados (bytes originales del cache/re-decodificados) con el idioma nuevo. Como se
  preservan longitudes, los punteros del juego siguen válidos → el menú se redibuja en el idioma nuevo
  **sin recargar**.
- **Atajo**: **F5** cicla idioma (`hh::text_cycle_language()`), `src/subsystems/input.cpp`.
- **Assets**: `assets/lang/{es,ca,fr,de,ja}.txt`; CMake los copia a `lang/` junto al ejecutable.

## API (`include/hh.h`)

```cpp
std::vector<std::string> hh::text_available_languages();
const std::string&       hh::text_current_language();
void                     hh::text_set_language(const std::string& code);
void                     hh::text_cycle_language();
extern "C" void          hh_trans_reapply_language(void);
```

## Validado (Linux headless)

`HH_LANG=es` → `[text] lang 'es': 22 entradas de .../lang/es.txt` + `68 cadenas traducidas` en el
módulo 23. Cambio en vivo con el diagnóstico `HH_LANG_CYCLE_AT=25`:

```
[text] HH_LANG_CYCLE_AT=25.0 -> cicla idioma
[text] lang 'ca': 0 entradas de .../lang/ca.txt
[text] idioma persistido en config.ini: ca
[text] idioma re-aplicado a 9 modulos cargados
[text] idioma activo: 'ca' (traduciendo=1)
```

→ selección + persistencia + re-aplicación a módulos cargados funcionan sin recargar el juego.
Pendiente validación visual en Windows (F5 y menú en español).

## Pendiente

- **A2 (visual)**: el selector gráfico. Opciones: overlay **ImGui** dentro de RT64 (requiere modificar
  el fork `lib/rt64` + pin) o ventana/overlay propio. Decidir en A2.
- `ca/fr/de/ja` están como **stubs** (comentarios): falta contenido y, para acentos, la fuente
  (ver `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`). `ja` necesita además tablas en **EUC-JP**.
- Al re-aplicar no se detectan módulos **liberados** por el juego; en un uso normal son módulos de
  texto residentes, pero conviene trackear `free` si se observan corrupciones.
