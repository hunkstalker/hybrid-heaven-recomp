# RETOMAR — handoff (2026-10-06)

> **Última sesión**: **subtítulos de la intro/prólogo** — **HECHOS y validados** (headless + Windows) y
> rama `subtitulos-intro` **MERGEADA a `main`**. Detalle: `notes/2026-10-06-subtitulos-intro.md`
> (resumen en `docs/TAREAS-HECHAS.md`). Reglas: `AGENTS.md`, `docs/documentation.md`.
>
> **TAREA SIGUIENTE**: **Traducción — JUEGO/GAMEPLAY (texto in-game)** (`TODO.md` "Ahora" #1).

## TAREA SIGUIENTE — Traducción del texto in-game (gameplay)

**Objetivo**: localizar las **cadenas del juego** (diálogos de gameplay; y cuando toque, intro/final) en
**en/es/ca/fr/de** (JA pospuesto, ver abajo). El texto in-game lo dibuja **el propio juego** (no el
overlay): se **sustituye en runtime** al cargar los módulos por el motor `trans`
(`src/subsystems/trans_cache.cpp` + `src/subsystems/text.cpp`).

**Hecho (2026-09-23)**:
- Charset USA derivado (ASCII en campos de ancho fijo + NUL; el "encoding custom" era LZKN64).
- **Sustitución en runtime** (`src/subsystems/text.cpp`; `HH_LANG=es`); extractor
  `tools/text/extract_strings.py`.
- **Sistema A1**: lista `en/es/ca/fr/de/ja` + mods, **cambio en vivo** (F5) con re-aplicación a módulos
  cargados y persistencia `[lang]`.
- i18n del port **unificado** en `assets/lang/*.txt` (ADR `0014`); idioma de menú e in-game comparten
  `hh::text_current_language()`.

**Pendiente (checklist)**:
1. **Longitud variable**: la sustitución no debe romper los campos de **ancho fijo** (ES/DE suelen ser
   más largos que EN). Definir política (truncar / expandir / rellenar) y probarla.
2. **Validar A1 en Windows** (build del mantenedor): cambio de idioma en vivo (F5) + persistencia.
3. **Cablear la fuente in-game 8×12 `color4`** en `src/hooks/text_glyphs.cpp` (hoy sirve un set 8×8
   propio). Usar `tools/text/build_font.py` → `include/hh/game_font_color4.h` (ES/CA/FR/DE). Es la MISMA
   tipografía que los subtítulos, que ya tiene **banda de extras >U+00FF** (`face_glyph_cp_uv`, p. ej.
   `œ/Œ/Ÿ`). `HH_ACCENTS=0` desactiva la inyección (para comparar).
4. **Extraer DE/FR** de la ROM **EU** emparejando por **módulo** → `assets/lang/*.txt` (la **PAL FR/DE
   es la referencia**). El **JA** (ROM JP) va con la tarea pospuesta.
5. **Redactar ES/CA** (revisión del mantenedor).
6. **Medir cobertura** (nº de strings/zonas) y decidir el formato de datos.

**Código a tocar**: `src/subsystems/text.cpp` (sustitución), `src/hooks/text_glyphs.cpp` (fuente
`color4`), `tools/text/extract_strings.py`, `tools/text/build_font.py`, `assets/lang/*.txt`.

**Referencias**: `PROYECTO.md §4`; notas `notes/2026-09-23-spike-traduccion-charset-y-sustitucion.md`,
`notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`,
`notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`, `notes/2026-09-23-b-fuente-formato-y-gaiji.md`,
`notes/2026-09-25-e-fix-reapply-idioma.md`, `notes/2026-09-05_asset-map.md`.

**Instrumentación (traducción)**:
- `HH_LANG=<code>` activa un idioma; **F5** lo cambia en vivo; `HH_LANG_CYCLE_AT=<s>` lo cicla a los
  `<s>` s.
- `HH_LANG_FILE=<ruta>` usa un `assets/lang/<code>.txt` **alternativo** (probar traducciones sin tocar
  los assets del repo).
- `HH_ACCENTS=0` desactiva la inyección de glifos acentuados `color4` (comparar con/sin).

## Diferidos de la familia subtítulos (intro cerrada)

- **FINAL**: reutiliza la misma arquitectura; referencia preparada en
  `notes/reference/Hybrid-Heaven-Ending-Dialogues .txt` (sin trackear). **Diferido** hasta que el
  mantenedor pueda llegar/validar el final del juego.
- **fr/de** de los subtítulos de la intro: **sin revisar** (el mantenedor no domina esos idiomas).
- **JA (juego + intro + final) — POSPUESTO**: requiere procesar la ROM japonesa. El **menú de título JA**
  ya está traducido (kana) pero **deshabilitado**.

## Run (mantenedor)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Pitfalls (NO repetir)

- **No** concluir sync/visual solo desde headless; validar en Windows (el mantenedor).
- El texto in-game lo dibuja **el juego** (loader `trans`), no el overlay: no confundir con los
  subtítulos (capa propia `hh::overlay::set_subtitle`).
- **No** editar el C generado (se regenera; ADR `0009`); no tocar ROMs/forks/push sin pedir.
- Un tema = un commit.
