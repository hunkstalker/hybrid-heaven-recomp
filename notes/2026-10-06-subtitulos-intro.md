# Subtítulos de la intro/prólogo — motor, datos, i18n y ancla

> Sesión 2026-10-06, rama **`subtitulos-intro`**. Objetivo: subtitular la **cinemática de prólogo**
> (tras `NUEVA PARTIDA` → `EMPEZAR PARTIDA`) en **en/es/ca/fr/de**, con el **estilo del diálogo
> in-game**. Estado: motor + datos + ancla **HECHOS y validados headless**; **pendiente validar en
> Windows**. Sigue el plan acordado (capas de overlay + i18n). Referencia de guion:
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
- `---` fuerza un corte exacto.

## 5. i18n

- 5 idiomas: **en/es/ca/fr/de** (`assets/lang/subtitles_<code>.txt`, plano y editable, con `# EN:` de
  contexto). Fallback a inglés si falta una clave. `check_translations: OK`.
- Idioma activo = el del juego/menú (`hh::text_current_language()`).

## 6. Ficheros tocados

- **Código**: `include/hh/subtitles.h`, `src/subsystems/subtitles.cpp`, `include/hh/overlay.h`,
  `src/platform/overlay.cpp`, `src/hooks/sections.cpp` (armado + `notify_scene`/`tick`),
  `src/subsystems/trans_cache.cpp` (`notify_load`), `src/subsystems/input.cpp` (`hh_input_buttons_now`,
  para el skip sin consumir flancos del menú), `src/platform/support.cpp` (`HH_AUDIODUMP_MB`),
  `CMakeLists.txt` (fuente + copia de `assets/subtitles` + copia de assets **siempre**).
- **Datos**: `assets/subtitles/intro_prologue.timing.txt`,
  `assets/lang/subtitles_{en,es,ca,fr,de}.txt`.
- **Herramientas**: `tools/text/build_subtitles.py`, `tools/text/preview_subtitles.py`.
- **Referencia**: `notes/reference/Hybrid-Heaven-Intro-Dialogues.txt`.

## 7. Validación (headless)

- Ancla a **+12.15 s** de EMPEZAR PARTIDA; `linea 0` a `t=11 s` tras el ancla (adelanto de 1 s pedido
  por el mantenedor) ≈ mismo instante absoluto que con el ancla anterior.
- Render con **color4** + panel centrado; **tildes** (es), apóstrofo y `…` correctos; skip con A.
- **Pendiente Windows** (el mantenedor): líneas fijas, balanceo, skip, cortes `---`, ancla nueva.

## 8. Pendiente

- **4:3** (pillarbox): posición/tamaño de subtítulos y líneas fijas.
- **Toggle por menú** (hoy `HH_SUBTITLES`, por defecto activado).
- **fr `œ/Œ/Ÿ`** (>U+00FF): cocer y consultar por codepoint en el overlay.
- Revisión de traducciones **es/ca** (mantenedor).
- Validación en **Windows**.

## 9. Referencias

- `docs/fonts.md` (tipografías), `docs/menu.md` (patrón overlay + control de UI nativa).
- `notes/2026-09-30-tipografias-data-load-hallazgos.md` (color4 = texto in-game).
