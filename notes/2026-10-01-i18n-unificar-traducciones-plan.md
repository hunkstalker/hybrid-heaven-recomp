# i18n — unificar todas las traducciones en `assets/lang/*.txt` (plan, Opción A)

> Sesión 2026-10-01 (4.ª de la jornada). Rama **`menu-carga-guardado-partida`**. Handoff de la tarea de
> `RETOMAR.md` (TAREA ACTUAL) y `TODO.md`. Es un **plan** (todavía sin implementar). Continúa el trabajo
> del título del Área (`notes/2026-10-01-titulo-area-*.md`, commit `874b9f6`).

## 0. Objetivo

Hoy la traducción está **repartida en dos mecanismos con claves distintas**. Unificar para que **todas
las traducciones vivan en un solo sitio** (ficheros por idioma) y el código solo referencie **claves**.
Beneficio extra: un jugador puede corregir una traducción editando el `.txt` (sin recompilar).

## 1. Estado actual `[MEDIDO]`

| Texto | Dónde | Clave |
|---|---|---|
| UI del port (pantallas, entradas, opciones, mensajes) | `kMenuTr` en `src/subsystems/menu.cpp` (~170 entradas, 6 columnas es/en/ca/fr/de/ja) | **español** |
| Nombres de Área | `kAreaNames` en `src/hooks/menu_overlay.cpp` (9 × 5 idiomas) | índice + columnas |
| Endónimos del selector IDIOMA | `kEndonyms` en `menu.cpp` | español |
| Texto **nativo de la ROM** | `assets/lang/<code>.txt` (+ `kEsDefaults` embebidos) | **inglés** |

- La sustitución del texto nativo la hace `hh_text_translate_guest` → `translate_segment` (match exacto
  del *core*: recorta el prefijo de formato `%m`/`%p`/`@` y los espacios finales). Flag `^` al inicio del
  valor = cadena **centrada** por el motor.
- `hh::menu::localized(label)` traduce la UI **en código** (tabla `kMenuTr`, clave = español).
- Redundancia: `es` está **dos veces** (defaults embebidos `kEsDefaults` + `assets/lang/es.txt`); el
  fichero gana si existe (`add_key` ignora duplicados).
- Los `lang/*.txt` actuales son un "spike": **`es` ~30** entradas y `ca/de/fr/ja` **vacías**.

## 2. Diseño propuesto (Opción A)

- **Clave única = texto original en inglés** (es la que ya usan los `lang/*.txt` y la que necesita la
  sustitución nativa).
- **Formato** (sin cambios): `assets/lang/<code>.txt`, `CLAVE=VALOR`, `^` = centrado. `en` = identidad
  (no necesita fichero: `translate()` devuelve la clave).
- **API nueva** `hh::text::translate(const std::string& key) -> std::string` (UTF-8): búsqueda **exacta**
  en la tabla activa; devuelve la clave si no hay entrada o si el idioma es `en`.
- `hh::menu::localized(key)` pasa a llamar a `translate(key)`.
- La **sustitución nativa** queda intacta (misma tabla, `core_of` + `translate_segment`).
- **`kEndonyms`** se quedan en código (se muestran en su propio idioma; no son traducciones).
- Se **eliminan** `kMenuTr` y las columnas de idioma de `kAreaNames`; el código guarda solo las claves
  (p. ej. `kAreaKey[9] = { "bioweapon storage facility", "Dr.Bross lab", ... }`).

## 3. Pasos de implementación

1. `hh::text::translate()` en `src/subsystems/text.cpp` + declaración en `include/hh.h` (junto a las
   funciones `text_*`).
2. **Migración asistida** con un script (`tools/text/`): generar `assets/lang/{es,ca,fr,de,ja}.txt` desde
   `kMenuTr` + `kAreaNames`, fusionando lo ya existente en `assets/lang/es.txt` (texto nativo). Evita
   transcripción manual y garantiza consistencia.
3. Convertir las **claves de la UI a inglés** (entradas y opciones del menú en `menu.cpp` + mensajes de
   `menu_overlay.cpp`) y cambiar `localized()` → `translate()`.
4. `area_title_name(area)` → `translate(kAreaKey[area-1])`.
5. Borrar `kMenuTr` y las columnas de idioma de `kAreaNames` (y `kEsDefaults`).
6. **Guard anti-recaída**: script de comprobación (clave usada en código ⇒ existe en `assets/lang/`),
   enganchado a la doc/CI como `docs_index --check`. Falla si falta una entrada.
7. Docs: `docs/architecture.md` §7, `docs/menu.md`, `docs/documentation.md`; regenerar `docs/INDEX.md`.

> Orden pensado para que el estado intermedio **compile y funcione** en cada paso (primero la API y las
> tablas; luego se cambian las claves; por último se borran las tablas de código).

## 4. Decisiones ROBUSTAS / mantenibles `[DECIDIDO]`

Criterio: que **no podamos volver a tener "traducción repartida"** ni una regresión silenciosa.

- **Una sola fuente = los ficheros** (`assets/lang/<code>.txt`). Se **elimina** `kMenuTr` y, con él, la
  tabla de UI en código. **`kEsDefaults` fuera**: `assets/lang/es.txt` es la fuente (nada de datos
  embebidos que puedan divergir). La única lista que se queda en código es `kEndonyms` (no son
  traducciones: son nombres de idioma mostrados en su propia lengua, invariantes por idioma).
- **Una sola convención de clave = inglés** (la que exige la sustitución nativa). Así UI y texto nativo
  comparten **una** tabla y **un** espacio de claves; no hay "dos mecanismos".
- **Un solo punto de traducción**: `hh::text::translate(key)`; `menu::localized` **delega**; la
  sustitución nativa reutiliza la misma tabla. El código solo pasa **claves**.
- **Anti-cola de regresiones (guard)**: un **check** (script en `tools/` + `docs_index --check`-style) que
  escanea el código en busca de literales traducibles (`localized("…")`, etiquetas/opciones del menú) y
  **falla si alguna clave no existe** en la tabla base; así no se cuela una traducción sin entrada ni se
  vuelve a "mitad en código, mitad en fichero". Añadirlo al cierre de la tarea.
- **Migración sin errores**: volcado **automático** de `kMenuTr`+`kAreaNames` a los `lang/*.txt` (script
  de un solo uso); se revisa el diff y luego se borran las tablas. Nada de transcripción a mano.
- **Edición del jugador**: directa sobre `assets/lang/<code>.txt`. El *override* por mods
  (`mods/<mod>/lang/<code>.txt`) se **difiere**; para que sea robusto cuando toque, la precedencia ya es
  un **único punto** documentado (`lang_dirs()`), y se cambiará ahí si se decide.
- **`en` = identidad** (sin `en.txt`): `translate()` devuelve la clave. Cero mantenimiento.

## 5. Riesgos / casos límite

- **Colisiones de clave**: una misma cadena inglesa con distinto sentido (p. ej. `SOUND` de menú vs
  in-game) → usar clave cualificada si molesta.
- Formato `.txt`: la clave no puede contener `=`; se recortan espacios extremos y se preservan internos;
  las etiquetas multi-línea de la UI (`\t`/`\n`) se construyen en código → cada componente con su clave.
- **Glifos**: acentos (marcas), kana `ja` (`color0`) e `∞`/flechas vectoriales ya soportados;
  `translate()` devuelve UTF-8 y el overlay ya lo pinta.
- **Longitud**: la sustitución nativa respeta el registro de ancho fijo (si no cabe, se omite; traza
  `HH_TEXT_TRACE`).
- **Reload en vivo** del idioma (F5 / `config.ini [lang]`) ya existe.

## 6. Validación

- Build Linux; ciclo de idioma (F5) y comprobar menús/opciones/mensajes/nombres de Área.
- Confirmar que la **sustitución in-game** sigue funcionando (mismas entradas, ahora también las de UI).
- Editar un valor en `assets/lang/es.txt` y verlo sin recompilar.
- `en` = claves; `ja` = kana; sin regresiones en el layout.

## 7. Referencias

- `src/subsystems/text.cpp` (`load_file`, `core_of`, `translate_segment`, `hh_text_translate_guest`).
- `src/subsystems/menu.cpp` (`kMenuTr`, `kEndonyms`, `localized`); `include/hh/menu.h`.
- `src/hooks/menu_overlay.cpp` (`kAreaNames`, `area_title_name`); `include/hh.h` (API `text_*`).
- `docs/menu.md` (§Idiomas), `docs/architecture.md` §7.

## 8. ESTADO: HECHO Y VALIDADO EN WINDOWS (2026-10-01)

Hechos los pasos del §3 (build Linux OK; árbol sin commitear):

1. **API**: `hh::text::translate(key)` en `src/subsystems/text.cpp` + declaración en `include/hh.h`.
   Búsqueda exacta; devuelve la clave si no hay entrada o el idioma es `en`. `localized` **delega**.
2. **Migración**: `tools/text/migrate_menu_tr.py` (un solo uso) volcó `kMenuTr` + `kAreaNames` +
   nativo existente a `assets/lang/{es,ca,fr,de,ja}.txt` (clave = inglés). Colisiones `SAVE`/`BODY`
   resueltas (fila cuya versión se usa); colisiones UI↔nativo resueltas a favor de la UI.
   Ficheros: `es`=120, `ca/fr/de`=112, `ja`=103.
3. **Claves de UI a inglés** en `menu.cpp` y `menu_overlay.cpp` (títulos `DATA LOAD`/`DATA SAVE`);
   `kPartLabels` a inglés; mensajes multi-línea con clave inglesa.
4. **Áreas**: `kAreaKey[9]` (nombres en inglés) + `area_title_name` → `translate`.
5. **`kMenuTr` borrado**; `kAreaNames` borrado.
6. **`kEsDefaults` retirado**; `es.txt` es la única fuente. Añadido `unescape` (`\n`/`\t`/`\\`) en el
   loader (las claves/valores multi-línea de la UI no pueden llevar saltos reales).
7. **Extras de robustez**: la sustitución nativa **omite** traducciones con glifos no representables
   (`utf8_to_game` devuelve fallo; p. ej. kana `ja`) en vez de escribir `????`. Guard
   `tools/text/check_translations.py` (enganchado a `docs_index.py --check`). Docs: `architecture.md`
   §7, `menu.md` §Idiomas, ADR 0014 (sustituye el punto 2 del ADR 0012).

**Validación Linux `[MEDIDO]`**: las 6 lenguas cargan N entradas correctas; `translate()` probado con
sondeo temporal en `es/ca/fr/de/ja` (incluida la clave multi-línea con `%s` y nombres de Área; `ja`
sin Área devuelve la clave). Build Linux limpio.

**Validación Windows `[MEDIDO]` (mantenedor, 2026-10-01)**: compilado y revisado; todo correcto
(build limpio + F5 por idiomas). Commit: bloque i18n en un solo commit.

**Riesgos observados** (sin incidencia en la validación): (a) la tabla nativa incorpora las claves
cortas de la UI (`SAVE`, `HEAD`, `MENU`…), que pueden sustituir texto in-game por coincidencia exacta
de core (acotado por el límite de longitud del registro); (b) glifos/acentos por fuente en cada
pantalla; (c) las filas del DATA LOAD usan `\t` pero se construyen en código (no son claves).
