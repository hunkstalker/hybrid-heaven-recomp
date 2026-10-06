# RETOMAR — handoff (2026-10-06)

> Rama **`subtitulos-intro`** **MERGEADA a `main`** (2026-10-06). Tarea de la sesión: **subtítulos de la
> intro/prólogo** — **HECHA y validada (headless + Windows)**. Detalle: **`notes/2026-10-06-subtitulos-intro.md`**
> (resumen en `docs/TAREAS-HECHAS.md`). Reglas: `AGENTS.md`, `docs/documentation.md`.
> **Siguiente**: lo que marque `TODO.md` "Ahora" (p. ej. **v0.7.3 push/tag**, **verificación byte-match**,
> épica **FPS/transiciones**).

## Estado (2026-10-06)

- **Motor**: capa de subtítulos en el overlay (`hh::overlay::set_subtitle`; `Face::Color4` = tipografía
  del diálogo in-game) + subsystem `hh::subtitles` (timing + textos por idioma, reloj por **VI**,
  **líneas fijas** `[N]`, paginado **balanceado por ancho**, cortes `---`, **skip** con A).
- **Ancla robusta**: al **fin de la 2ª oleada de cargas** de la escena 0x104 (coincide con la
  campanada; +12.15 s desde `EMPEZAR PARTIDA`). Independiente de la carga entre PCs y del audio.
- **Datos**: referencia editable `notes/reference/Hybrid-Heaven-Intro-Dialogues.txt` (formato
  `[N][IN] [OUT]` + texto) → `tools/text/build_subtitles.py` → `assets/subtitles/*.timing.txt` +
  `assets/lang/subtitles_<code>.txt` (en/es/ca/fr/de). Preview: `tools/text/preview_subtitles.py`.
- **4:3 HECHO y validado (headless + Windows)**: `subtitle_max_width()` en
  `src/subsystems/subtitles.cpp` trocea por el área del **juego**: `original`/`4:3` manual → 320 con
  margen **40** (`max_w=280`; la caja no toca el borde, deja «aire»); manuales → `240×ratio-24`;
  **`auto`/`expand` SIN CAMBIOS** (`visible_width()-24`). El re-troceo/re-publicado se fuerza al
  cambiar `max_w` (F2).
- **Huérfanas de frase (paginado)**: la página no cierra con `fin de frase + 1-2 palabras` (`. . .` de
  pausa y abreviaturas no cuentan); aplica en **widescreen y 4:3**. **Commiteado** (`2795669`).
- **Toggle en el menú**: GRÁFICOS → `SUBTÍTULOS INTRO` (NO/SÍ, defecto **SÍ**); persiste en
  `config.ini [video].subtitles` y aplica en caliente. `HH_SUBTITLES` (env) tiene prioridad. **Validado
  headless y en Windows** (mantenedor, 2026-10-06). Commit `ed49215`.
- **Extras > U+00FF (`œ/Œ/Ÿ` FR, `ł/Ł/ś/Ś` PL)**: horneados en una **banda aparte al final** del atlas
  (`font.cpp`, `kExtraTop`; 32 celdas reservadas) y servidos por codepoint (`face_glyph_cp_uv`); el
  overlay los consulta para `cp > 0xFF`. **Sin desplazar ninguna banda existente**. **Validado headless**
  (texto `cœur Œdipe aiguë Ÿ œuf` renderizado). **Validación visual diferida**: se verá cuando se
  traduzcan diálogos (gameplay/intro) que usen `œ/Œ/Ÿ` (hoy ninguna traducción los usa). Commit `8edcd8d`.

## TAREA SIGUIENTE

La subtitulación de la **intro** está **cerrada** (rama mergeada). **Diferidos** de la misma familia:

- **FINAL**: reutiliza la arquitectura; referencia preparada en `notes/reference/Hybrid-Heaven-Ending-Dialogues .txt`
  (sin trackear). **Diferido** hasta que el mantenedor pueda llegar/validar el final del juego.
- **Diálogos del gameplay**: trabajo mayor futuro (donde se validará visualmente `œ/Œ/Ÿ`).
- **fr/de** de los subtítulos: **sin revisar** (el mantenedor no domina esos idiomas).

Siguiente foco: `TODO.md` "Ahora" (**v0.7.3 push/tag**, verificación byte-match, épica FPS/transiciones).

## Instrumentación

- `HH_SUBTITLES=0` desactiva; `HH_SUB_TRACE=1` traza líneas/páginas/ancla; **`HH_SUB_OFFSET_MS=<ms>`**
  (positivo = subtítulos **antes**).
- `HH_AUDIODUMP=<f>` (+ `HH_AUDIODUMP_MB=<n>`) vuelca PCM; `HH_AUDIOLOG=1` log de buffers.
- `HH_MENU_TRACE=1` (EMPEZAR PARTIDA, `goto pantalla`), `HH_SCENE_TRACE=1`, `HH_SAVE_TIME_TRACE=1`.

## Run (mantenedor)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Pitfalls (NO repetir)

- **No** concluir sync/visual solo desde headless; validar en Windows.
- La campanada es **BGM** (no hay disparador de SE); **no** usar onset de audio como ancla (depende de
  volumen/driver/música).
- Los tiempos del `.txt` son **relativos al inicio de la cinemática** (no a `EMPEZAR PARTIDA`).
- Un tema = un commit; no editar el C generado; no tocar ROMs/forks/push sin pedir.
