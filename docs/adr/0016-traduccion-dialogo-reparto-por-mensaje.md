# ADR 0016 — Traducción del diálogo in-game: reparto por mensaje (A+) y fuente color4

- **Estado**: aceptado (2026-10-06).
- **Contexto**: el texto de los diálogos lo dibuja el **propio juego** (no el overlay), codificado en
  **EUC-JP de ancho completo** e **inline en "nodos"** referenciados por tablas en otros módulos. La
  longitud del texto choca con los tramos fijos y el motor ASCII existente lo ignoraba. Los acentos
  requieren inyectar glifos en el estilo del diálogo (**color4**, 8×12).
- **Decisión**:
  1. **Sustituir en runtime** en `src/subsystems/text.cpp` al cargar el módulo (loader `trans`), sin
     mover datos.
  2. **A+ (reparto por mensaje)**: agrupar líneas hasta el fin de mensaje (`fa 00`/`fe 00`) y
     reescribir el tramo **recolocando los saltos de línea**; **presupuesto = suma de caracteres del
     mensaje inglés**. Si no cabe, **ruta A** por línea.
  3. **Acentos**: inyección de glifos por color (`text_glyphs.cpp`): color0 (menú) y **color4**
     (diálogo), con donante ASCII + marca de origen; fuente `include/hh/game_font_color4.h`.
  4. **Nombres propios**: seguir la **línea oficial** (p. ej. `Gargatuan` se mantiene; el alemán lo
     respetó). Ante dudas, **preguntar al mantenedor**.
- **Consecuencias**:
  - La traducción queda **acotada al presupuesto del mensaje inglés** → redacción **concisa** (no hay
    longitud libre real).
  - El **menú** (color0 / ASCII) y los **subtítulos de la intro** (overlay) quedan intactos.
  - El cambio de idioma en vivo (F5) sigue funcionando (re-aplicación).
- **Alternativas**:
  - **Ruta B — reubicar nodos + parchear tablas/enlaces** (cross-módulo): **descartada** por coste y
    fragilidad.
  - **Overlay propio** para el diálogo: descartado (el juego dibuja el texto; habría que ocultarlo).
- **Criterio de salida**: cobertura es/ca de los diálogos y **validación visual en Windows** del
  mantenedor (tildes correctas, sin inglés mezclado).
