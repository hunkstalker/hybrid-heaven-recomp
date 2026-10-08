# ADR 0017 — Overlay propio del diálogo y traducción por MENSAJE en un solo fichero por idioma

- **Estado**: aceptado (2026-10-07). **Supersede parcialmente** el ADR `0016` (su alternativa
  "Overlay propio del diálogo — descartado").
- **Contexto**:
  - El ADR `0016` acotó la traducción del diálogo al **presupuesto A+** (suma de caracteres del
    mensaje inglés) y descartó el overlay porque el juego dibuja el texto. Con ese límite, las
    correcciones del mantenedor que **no caben** quedaban recortadas ("aplicado").
  - La tabla por-línea (`es.txt`/`ca.txt`, clave = línea inglesa) **colisiona** cuando el guion
    **repite una línea** en mensajes distintos con distinta traducción: p. ej. `control system of
    this shelter,` en mod17 m28 y m29, o `Johnny Slater!`. El texto se repite de verdad (verificado
    en la ROM: dos offsets distintos; y conversaciones enteras reutilizadas mod29↔mod31).
  - El juego identifica el texto por su **posición** en el guion; la unidad con contexto cerrado es
    el **mensaje** (hasta `FA00/FE00`).
- **Decisión**:
  1. **Overlay propio del diálogo**: capa que sustituye el dibujo del texto del juego (y su caja),
     eliminando el límite de longitud. Reconstruye el mensaje desde `func_8001800C`, acumula por
     **página** (corte real = opcode `F800`), typewriter por VI, flecha y cierre 1:1 con el original.
  2. Traducción indexada por **MENSAJE**: clave = **mensaje inglés completo** (líneas unidas con
     espacio); valor = traducción con los **saltos "baked"** en `\n`. Todo en **un solo fichero por
     idioma** (`assets/lang/<code>.txt`), junto a las entradas de menú.
  3. Las entradas de mensaje se generan con `tools/text/build_dialogue_messages.py` desde
     `assets/dialogos.txt` (alineado 1:1 con los mensajes de la ROM) y la tabla por-línea: se usa la
     versión larga `(tú)` si existe; si no, la traducción **por-línea** correcta (nunca el valor
     mezclado EN/ES de `dialogos.txt`).
  4. **Se eliminan** `assets/lang/es.dlg.txt` y `ca.dlg.txt`: su papel lo cubren las entradas de
     mensaje del fichero único.
  5. Runtime: `text::dialogue_message_choice` + `find_message_value` (índice del fichero único). El
     motor A+ in-place se conserva como base/fallback y para los menús.
- **Consecuencias**:
  - Traducción **sin límite de longitud**; la estructura de líneas del original se conserva salvo
    cuando el texto no cabe (entonces se reparte, pudiendo crecer en líneas).
  - **Sin colisiones** por líneas repetidas (la clave es el mensaje); **una sola fuente** por idioma.
  - Se mantiene el comportamiento 1:1 en lo no traducido; menús intactos.
  - Depuración comparando con el original: `HH_DLG_DY=-64` + `HH_DLG_KEEP_ORIGINAL=1`.
- **Alternativas**:
  - **Clave por línea** (estado previo): colisiona con líneas repetidas. Descartada.
  - **Clave por posición/offset** (lo que hace el juego): única pero **frágil y opaca** (cambia si se
    mueve el guion o se reubican datos). Descartada.
  - **Dos ficheros** (`es.txt` por-línea + `es.dlg.txt` por-mensaje): rechazado por el mantenedor
    (una sola fuente por idioma).
- **Criterio de salida**: validación visual en Windows del **primer diálogo** (módulo 12) — texto
  completo, respuesta al input y cierre de la caja correctos (hecho, 2026-10-07); extender al resto
  del juego.
