# Sesión 2026-10-06 — motor de traducción del diálogo (A+ + color4) y arranque de contenido

> Resumen de la sesión. Normativa de la tarea: **`docs/traduccion.md`**; decisión: **ADR 0016**.
> Handoff: **`RETOMAR.md`**.

## Resultado

- **Motor de sustitución del diálogo HECHO y VALIDADO en Windows**:
  - Texto EUC-JP de ancho completo **inline en nodos**; sustitución en runtime (`src/subsystems/text.cpp`).
  - **A+ (reparto por mensaje)**: agrupa líneas hasta `fa/fe 00` y reescribe el tramo moviendo saltos
    de línea; **presupuesto = mensaje inglés**. Fallback ruta A por línea.
  - **Acentos**: inyección por estilo en `src/hooks/text_glyphs.cpp` — color0 (menú) **y color4**
    (diálogo, 8×12); fuente `include/hh/game_font_color4.h` (`build_font.py`). Sombras a **nivel 3**
    (negras) y `¿/¡` = `?/!` nativo rotado.
  - **Descartada la "ruta B"** (reubicar nodos + parchear tablas cross-módulo). Ver §"Substraído".
- **Referencia DE/FR** extraída de la EU: `work/dialogues/us_de_fr.tsv` (936 mensajes, ~97%).
- **Contenido inicial**: conversación de **Mr. Diaz** (módulo 12 = primer diálogo del juego) y
  **módulo 27** (escena del gargatuano) en **es + ca**.

## Decisiones

- **A+**, no reubicación de nodos (coste/fragilidad). ADR 0016.
- **Nombres propios = línea oficial**: la raza se queda **`Gargatuan`** (el alemán lo respetó; el
  francés lo "corrigió" a *Gargantuan* apartándose). **Ante dudas de traducción (nombres,
  neologismos, convenciones): PREGUNTAR al mantenedor.**
- **No** asumir índice de módulo = área/orden de juego: son **escenas**; el orden se confirma con el
  mantenedor.
- Estilo: **español de España**; catalán derivado del español.

## Substraído / corregido (para no repetir)

- `notes/2026-10-06-dialogos-guion-punteros-y-ruta-a.md`: los "punteros a texto" eran una
  **coincidencia** (con base equivocada); el texto va **inline en nodos**. Válido: gramática
  (`f3/f0` salto, `fa/fe` fin, `f8` espera, `fd` fin) y la ruta A.
- `notes/2026-10-06-dialogos-ruta-b-arena.md`: **descartada** (ruta B).
- `notes/2026-10-06-dialogos-estructura-nodos-y-a-plus.md`: estructura real + A+: **vigente**.
- `notes/2026-10-06-color4-acentos-dialogo.md`: color4 + sombras + `¿/¡`. **Vigente**.
- `notes/2026-10-06-dialogos-extraccion-euc.md`: extractor + cobertura. **Vigente**.

## Pendiente (ver `RETOMAR.md` y `docs/traduccion.md`)

- **Traducir TODO el diálogo a es/ca** (~936 mensajes / 2.509 líneas). Validar con
  `tools/text/check_dialogue_fit.py`.
- Extraer DE/FR por módulo ya está (referencia). JA pospuesto.
- **Aparte**: bug de los subtítulos de la intro al skipear.
