# Caja de subtítulos = caja del diálogo (mismo límite de ancho + misma transparencia)

> Sesión **2026-10-08**, directo en **`main`** (pulido de la intro antes de la traducción).
> Estado: **HECHO y validado en Windows** (mantenedor). Contexto: `notes/2026-10-06-subtitulos-intro.md`.

## 1. Petición (mantenedor)

Había **dos maneras de dibujar la caja** de subtítulos según la relación de aspecto (widescreen vs
4:3). Quiere dejar **una sola** (la de 4:3) y que su **límite de tamaño** sea el de la caja del
overlay de **diálogo**, con la **misma transparencia**.

## 2. Antes

- `subtitle_max_width()` (en `src/subsystems/subtitles.cpp`) troceaba según el aspecto:
  - **widescreen** (`auto`/`expand`): `visible_width() − 24` ≈ **403** unidades.
  - **4:3** (`original`/`4:3` manual): `320 − 40` = **280**.
  Así la caja podía estirarse muchísimo en 16:9.
- El panel de subtítulos usaba **alfa fijo 176** (`rgba(0,0,0,176)`), distinto del de la caja de
  diálogo (`HH_DLG_ALPHA`, defecto **95**).

## 3. Cambio

- **Un solo estilo de caja**: `subtitle_max_width()` devuelve siempre el **área interior de la caja
  de diálogo**, independiente del aspecto → el panel de subtítulos nunca supera el de diálogo.
- **Límite compartido**: nueva `hh::overlay::dialogue_text_width()` = `ancho_caja − 2·padding` =
  `264 − 8` = **256** unidades (sigue `HH_DLG_BOX`). La usan el troceo de subtítulos y el diálogo.
  Panel de subtítulos ≤ **264** (igual que la caja de diálogo, centrada en `x=28` como ella).
- **Misma transparencia**: helper `dialogue_panel_alpha()` (`HH_DLG_ALPHA`, defecto **95**), que ahora
  comparten el panel de diálogo y el de subtítulos (antes: diálogo 95, subtítulos 176).

Efecto colateral esperado: al ser la caja más estrecha, textos largos pueden partir en más
líneas/páginas (el paginado sigue limitado a 3 líneas por página).

## 4. Ficheros

- `src/subsystems/subtitles.cpp` (`subtitle_max_width()`).
- `src/platform/overlay.cpp` (`dialogue_panel_alpha()`, `dialogue_text_width()`, alfa del panel de
  subtítulos).
- `include/hh/overlay.h` (declaración de `dialogue_text_width()`; comentario de `set_subtitle`).

## 5. Validación (Windows, mantenedor)

- **Widescreen**: la caja de subtítulos ya **no se estira**; misma anchura que la caja del diálogo,
  centrada, con la **misma transparencia**. ✔
- **4:3**: la caja **no cambia** de tamaño respecto a widescreen. ✔
