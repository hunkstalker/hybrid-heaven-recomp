# 0014 — Fuente única de traducciones (`assets/lang/*.txt`, clave = inglés)

- **Estado:** Aceptado (2026-10-01). Sustituye el punto 2 de la decisión del ADR 0012.
- **Contexto:** la traducción vivía en **dos mecanismos con claves distintas**: la UI del port en
  código (`kMenuTr` en `src/subsystems/menu.cpp`, nombres de Área en `kAreaNames`, clave = **español**)
  y el texto **nativo de la ROM** en `assets/lang/<code>.txt` (clave = **inglés**). Además `es` estaba
  duplicado (tabla embebida `kEsDefaults` + fichero). Corregir una traducción de UI exigía recompilar.
- **Decisión:**
  1. **Una sola fuente = los ficheros** `assets/lang/<code>.txt`; se eliminan `kMenuTr` y `kEsDefaults`.
  2. **Una sola convención de clave = texto original en inglés** (la que exige la sustitución nativa).
     `en` = identidad (sin `en.txt`).
  3. **Un solo punto de traducción**: `hh::text::translate(key)` (búsqueda exacta; devuelve la clave si
     no hay entrada o el idioma es `en`). `hh::menu::localized` **delega** en él; la sustitución nativa
     (`hh_text_translate_guest`/`translate_segment`) usa la **misma** tabla.
  4. **Formato** sin cambios de layout (`CLAVE=VALOR`, `^` = centrado) + escapes `\n`/`\t` para las
     claves/valores multi-línea de la UI. La sustitución nativa **omite** las traducciones con glifos
     no representables en la fuente del juego (p. ej. kana) en vez de escribir `????`.
  5. **`kEndonyms`** (selector IDIOMA) se quedan en código: no son traducciones (se muestran en su
     propia lengua, invariantes por idioma).
  6. El *override* por mods (`mods/<mod>/lang/<code>.txt`) queda **aplazado**; la precedencia ya es un
     único punto (`lang_dirs()`).
  7. **Guard anti-recaída**: `tools/text/check_translations.py` falla si reaparece una tabla en código
     o si una clave usada en código no existe en la tabla base; enganchado a `docs_index.py --check`.
- **Consecuencias:**
  - Un jugador corrige una traducción editando `assets/lang/<code>.txt` **sin recompilar**.
  - UI y texto nativo comparten espacio de claves: una misma cadena inglesa con distinto sentido debe
    resolverse con una única traducción (colisiones resueltas en la migración: `SAVE`, `BODY`).
  - Migración automática de un solo uso: `tools/text/migrate_menu_tr.py`.
- **Alternativas descartadas:** mantener `kMenuTr` (dos fuentes); clave = español (no sirve para la
  sustitución nativa); datos embebidos como respaldo (`kEsDefaults` diverge del fichero).
- **Criterio de salida:** build + ciclo de idioma (F5) en Windows; sustitución in-game intacta; editar
  un valor y verlo; `ja` en kana.
