# Subtítulos de la intro/prólogo — motor, datos, i18n, ancla, 4:3 y paginado

> Sesión 2026-10-06, rama **`subtitulos-intro`**. Objetivo: subtitular la **cinemática de prólogo**
> (tras `NUEVA PARTIDA` → `EMPEZAR PARTIDA`) en **en/es/ca/fr/de**, con el **estilo del diálogo
> in-game**. Estado: motor + datos + ancla + **4:3 + re-troceo (F2) + huérfanas + toggle de menú + extras
> `œ/Œ/Ÿ` HECHOS y validados (headless y Windows, 2026-10-06)**; **rama `subtitulos-intro` MERGEADA a
> `main`**. Sigue el plan acordado (capas de overlay + i18n). Referencia de guion:
> `notes/reference/Hybrid-Heaven-Intro-Dialogues.txt`.

## 1. Motor de subtítulos (overlay)

- **Capa propia** en el overlay, independiente del frame del menú (como `set_screen_image`/FPS):
  `hh::overlay::set_subtitle(bool visible, const std::vector<std::string>& lines)`.
  - `src/platform/overlay.cpp`: dibuja un **panel negro semitransparente** + texto con **`Face::Color4`**
    (la tipografía del **diálogo de gameplay**, confirmada por el mantenedor) centrado abajo.
  - Se factorizó `append_face_text` (la rama `face != Color0`) para reutilizarla en menú y subtítulos.
  - **Centrado**: en la mitad del área virtual 320 (**160**), no en `visible_width/2` (eso solo
    coincidía en 4:3 y desplazaba el panel a la derecha en 16:9).
  - **Early-return**: el `draw_hook` debía consultar la capa de subtítulos (durante la intro no hay
    frame de menú ni imagen → si no, no se dibujaba nada).
- **Subsystem** `src/subsystems/subtitles.cpp` + `include/hh/subtitles.h`:
  - Carga `assets/subtitles/<name>.timing.txt` (tiempos) + `assets/lang/subtitles_<code>.txt` (textos
    por idioma, con fallback a inglés).
  - Reloj por **`hh_get_vi_count()`** (~60 Hz), no wall-clock.
  - `begin(name)` (arma) → `notify_scene(0x104)` / `notify_load()` (hook por-frame + loader `trans`) →
    `tick()` (por frame, hilo del juego) publica la línea activa.
- **Fuente**: `Face::Color4` (8×12). **Apóstrofo** compuesto con la **coma subida** (la color4 no lo
  trae); `…`→`...`, comillas curvas → rectas (normalización en el cargador).
- **Extras > U+00FF** (`œ/Œ/Ÿ` FR, `ł/Ł/ś/Ś` PL): ya generados en `hh::kGameGlyphs`; no caben en la
  franja Latin‑1 (direccionada por `cp-0x80`), así que se cuecen en una **banda aparte al FINAL** del
  atlas (`kExtraTop`, 32 celdas reservadas) y se sirven por **codepoint** (`face_glyph_cp_uv`). **No
  desplazan** ninguna banda existente (color0/marcas/color4/accentos/color3/kana intactas).
- **Toggle en el menú** GRÁFICOS → `SUBTÍTULOS INTRO` (**NO/SÍ**, defecto **SÍ**): `hh::video_set_subtitles()`
  persiste en `config.ini [video].subtitles` (como el resto de opciones de GRÁFICOS) y aplica en caliente
  vía `hh::subtitles::set_enabled()`. El selector canónico es `NO`/`YES` (se muestra **NO/SÍ** por
  `assets/lang`). `HH_SUBTITLES` (env) tiene **prioridad** sobre la config (testing).
- **Ancho de troceo por aspecto** (`subtitle_max_width()`): en `auto`/`expand` (widescreen) se mantiene
  **exactamente** `visible_width() - 24` (sin cambios); en `original` (4:3 nativo) y `4:3` manual se
  trocea al área del **juego** (320), con margen **40** (`max_w = 280`, pedido por el mantenedor: la
  caja no debe tocar los bordes, hace falta «aire»); en ratios manuales, `240 × ratio - 24`. El panel
  del overlay ya estaba centrado en el área virtual 320 (evidencia 4:3/F2 en §7).

## 2. Ancla robusta (independiente de la carga entre PCs)

- La escena del prólogo es **0x104 (260)**; el índice de escena (`0x801BBBF4`) se activa ~**0.13 s**
  tras `EMPEZAR PARTIDA` (**antes** de cargar los módulos).
- El **contenido** (y la **campanada**) llega a ~**+12 s**, tras una **2ª oleada de cargas** de módulos.
- **Ancla = fin de la 2ª oleada de cargas**: primera carga tras un hueco >2 s entre oleadas + ~0.25 s
  sin cargas. Medido: **+12.15 s** (consistente en 2 corridas: 12150/12166 ms).
- **Descartado**: (a) onset de audio — la campanada es **parte de la BGM**, y el RMS depende del
  **volumen**/driver/música (frágil); (b) disparador de SE — no existe uno propio para la campanada.
- **Tiempos rebasados** a relativo-al-inicio-de-cinemática (restado el lead-in). Ajuste global en
  caliente: **`HH_SUB_OFFSET_MS`** (positivo = los subtítulos salen **antes**).

## 3. Formato de datos (referencia editable → datos del port)

- **Referencia** (editable a mano): `notes/reference/Hybrid-Heaven-Intro-Dialogues.txt`:
  ```
  [N][IN mm:ss] [OUT mm:ss]
  texto del bloque (varias líneas se unen; línea en blanco = párrafo)
  ```
  - `IN` = aparición; `OUT` = **margen de salida** (tiempo máximo visible; puede ser posterior al fin
    del audio, para dar margen a leer).
  - `[N]` (opcional, **prefijo**): línea fija **1 = arriba, 2 = abajo**. Sin `[N]` → paginado normal.
  - `---` (línea sola): **corte de página manual**.
- **Conversor** `tools/text/build_subtitles.py <referencia>` genera:
  - `assets/subtitles/<name>.timing.txt` → `id in_ms out_ms line` (única fuente de tiempos).
  - `assets/lang/subtitles_<code>.txt` → `<name>.<id>=texto` por idioma; **preserva traducciones** y
    añade `# EN:` (contexto). El **inglés** se genera; es/ca/fr/de se traducen a mano (aquí).
- **Preview** `tools/text/preview_subtitles.py` (páginas balanceadas, sin arrancar el juego).

## 4. Líneas fijas y paginado

- Con `[N]`: la frase se coloca en su línea; varias frases en la **misma** línea que se solapan en el
  tiempo se **secuencian** dentro de la ventana común (fracción del tiempo).
- Sin `[N]`: paginado automático **balanceado por ANCHO** (programación dinámica) en páginas de ≤3
  líneas → evita la página "huérfana" (p. ej. `3/3/1` → `3/2/2/3`).
- **Control de huérfanas de frase** (a nivel de **página**, en todos los aspectos): la DP penaliza
  cerrar una página en una línea que termina con el **arranque de una frase** (fin de frase `.`/`!`/`?`
  + 1-2 palabras, p. ej. `...same day. In`). Así el arranque no queda solo en la página anterior. Los
  `...` (pausa) y las abreviaturas (`Mr.`, `Dr.`, …) **no** cuentan como fin de frase. No cambia los
  saltos de línea normales, solo el reparto de líneas por página.
- `---` fuerza un corte exacto.

## 5. i18n

- 5 idiomas: **en/es/ca/fr/de** (`assets/lang/subtitles_<code>.txt`, plano y editable, con `# EN:` de
  contexto). Fallback a inglés si falta una clave. `check_translations: OK`. Revisión **es/ca validada**
  por el mantenedor (2026-10-06).
- Idioma activo = el del juego/menú (`hh::text_current_language()`).

## 6. Ficheros tocados

- **Código**: `include/hh/subtitles.h`, `src/subsystems/subtitles.cpp`, `include/hh/overlay.h`,
  `src/platform/overlay.cpp`, `src/hooks/sections.cpp` (armado + `notify_scene`/`tick`),
  `src/subsystems/trans_cache.cpp` (`notify_load`), `src/subsystems/input.cpp` (`hh_input_buttons_now`,
  para el skip sin consumir flancos del menú), `src/platform/support.cpp` (`HH_AUDIODUMP_MB`),
  `CMakeLists.txt` (fuente + copia de `assets/subtitles` + copia de assets **siempre**).
- **Fuente/atlas (extras >U+00FF)**: `src/subsystems/font.cpp` (banda `kExtraTop` + `face_glyph_cp_uv`),
  `include/hh/font.h` (declaración), `src/platform/overlay.cpp` (lookup en `append_face_text`); datos ya
  presentes en `include/hh/game_font_color4.h` (`tools/text/build_font.py`).
- **Datos**: `assets/subtitles/intro_prologue.timing.txt`,
  `assets/lang/subtitles_{en,es,ca,fr,de}.txt`.
- **Herramientas**: `tools/text/build_subtitles.py`, `tools/text/preview_subtitles.py`.
- **Referencia**: `notes/reference/Hybrid-Heaven-Intro-Dialogues.txt`.

## 7. Validación (headless)

- Ancla a **+12.15 s** de EMPEZAR PARTIDA; `linea 0` a `t=11 s` tras el ancla (adelanto de 1 s pedido
  por el mantenedor) ≈ mismo instante absoluto que con el ancla anterior.
- Render con **color4** + panel centrado; **tildes** (es), apóstrofo y `…` correctos; skip con A.
- **4:3 (captura pareada, `import -window root`, 1920×1080, Xvfb :110)**:
  - `[video] aspect = auto` → `max_w = 402.7` (= `visible_width()-24`); el troceo renderizado es
    **idéntico** al de antes del cambio (misma página de 2 líneas).
  - `[video] aspect = original` → `max_w = 280.0` (margen 40). El panel mide `max_w + 8` (padding) de
    tope, así que el ancho máximo real de la caja baja de ~294 (con 288) a ~286 (−1 glifo): deja «aire»
    respecto al borde del área 4:3 (320). Si el límite vuelve a quedarse pegado al borde, bajar otro
    glifo (p. ej. margen 48 → `max_w=272`).
  - **Toggle en caliente (F2)**: estando en `original` con una página publicada, se inyecta una tecla
    F2 real (XTest) → `aspect=expand`; el log muestra `ancho max_w=402.7 (...) -> re-troceo` y re-publica
    la página re-troceada (`pag x/5`) en el mismo frame. Corrección #2 validada headless.
- **Huérfanas de frase (headless, `auto`)**: el bloque 1 no cambia (2 líneas, captura idéntica); el de
  Holly (`id 2`) pasa de reparto `[2,3,2]` con 2 páginas que acababan en `...OK? Well,` / `...Eve? I`
  a `[1,3,3]` con 0 (página 1 de 1 línea limpia `...you're out again`, capturada). En 4:3 el reparto no
  cambia (el caso de `id 2` allí es estructuralmente inevitable).
- **Toggle (config + menú, validado)**: `[video] subtitles = no` → `[subs] init (activados=0)` y **sin
  panel** (captura en el 1er bloque); `= si` (defecto) los muestra. En el menú, GRÁFICOS muestra la fila
  `SUBTÍTULOS INTRO  NO/SÍ` (defecto SÍ, capturada); al pulsar IZQ → `[VIDEO] SUBTÍTULOS INTRO -> no` y
  `config.ini` pasa a `subtitles = no` (persistencia + cambio visual a `NO` en verde). **Validado
  headless y en Windows** (mantenedor, 2026-10-06).
- **Extras `œ/Œ/Ÿ` (headless)**: texto de prueba `cœur Œdipe aiguë Ÿ œuf` renderizado con color4
  (captura ampliada): los 3 glifos salen (no huecos); datos verificados en ASCII desde `kGameGlyphs`.
  Atlas pasa de `128×567` a `128×591` (+2 filas de la banda de extras). **Validación visual diferida**:
  se verá cuando alguna traducción use `œ/Œ/Ÿ` (hoy ninguna lo hace); la banda está pensada como
  preparación para los diálogos del gameplay.
- **Validado en Windows** (mantenedor, 2026-10-06): líneas fijas, balanceo, skip, cortes `---`, ancla,
  **4:3, F2 y huérfanas** (sync visual) `OK`.

## 8. Pendiente (diferidos)

- **FINAL**: reutilizará la misma arquitectura (referencia preparada, sin trackear). **Diferido**: el
  mantenedor no puede validarlo sin llegar al final del juego.
- **Diálogos del gameplay**: trabajo mayor futuro; ahí se validará visualmente `œ/Œ/Ÿ`.
- **fr/de**: sin revisar (el mantenedor no domina esos idiomas).

## 9. Referencias

- `docs/fonts.md` (tipografías), `docs/menu.md` (patrón overlay + control de UI nativa).
- `notes/2026-09-30-tipografias-data-load-hallazgos.md` (color4 = texto in-game).
