# 0015 — Anclaje estructural del minimapa (panel por scissor/fondo, no por hash de contenido)

- **Estado:** Aceptado (2026-10-02). Implementado y **validado en Windows en todos los niveles** (2-1,
  3-1, 4-1 y resto): arregla definitivamente el issue #13. Rama `main` (v0.6.0).
- **Contexto:**
  - El HUD 2D se reescribe para widescreen en `src/hooks/hud_rewrite.cpp`: copia la display list a un
    scratch e inserta GBI extendido de RT64 alrededor de cada elemento clasificado (`kLeft`/`kRight`…).
  - La clasificación de cada elemento (`class_of`) venía siendo **por detección**: hash de contenido de
    la textura o de los primeros 16 comandos de una lista (`dl:<addr>#<hash>`), extensión en px, fila o
    color. Esto ha fallado de forma **recurrente** (#3 HUD de combate, #7 minimapa en 2-1, #13 minimapa
    en 3-1): la **dirección RDRAM y el recurso del overlay cambian por escena/capítulo**.
  - El issue #7 se "arregló" emparejando el **hash de contenido** del minimapa
    (`0xbbb8c0ba`/`0x1427da33`). El issue #13 demuestra que **no cubre todas las áreas**: en 3-1 el
    overlay del mapa es otro recurso → otro hash → `kAuto` → el contenido no recibe
    `viewport_align(RIGHT)` y sale **fuera del panel**.
  - **Medido** (F7 + `HH_HUD_REWRITE_TRACE`/`HH_HUD_SITES_TRACE`/`HH_HUD_DRAWS_TRACE`, replay de mapa): el contenido del minimapa
    se dibuja bajo un **`G_SETSCISSOR` de panel** (`197,143..277,223`, en cuartos de px
    `0x31423C/0x45437C`, o sea **no cubre el ancho del framebuffer** y cae en la **mitad derecha**) y
    comparte **viewport** (`dc080008/8025b628`). El fondo negro es un `G_FILLRECT` bajo scissor a
    pantalla completa, con el **mismo rectángulo** que el panel. El dial del radar (`kLeft`) va bajo
    scissor a pantalla completa.
- **Decisión:**
  1. **El minimapa deja de clasificarse por hash/identidad exacta.** `class_of` ya no contiene
     `dl:0x030002e0#bbb8c0ba`, `dl:0x03000f10#1427da33` ni `fill:0x00000000@197,143,277,223`.
  2. **Criterio estructural:** es contenido del minimapa **toda lista `dl` (call o branch) dibujada
     mientras está vigente un scissor de panel en la mitad derecha** (`right_panel_scissor()`:
     no ancho completo, dentro de pantalla, `ulx ≥ fb_width/2`, tamaño ≥ 8 px). El **primer** panel
     así detectado fija el **panel canónico** del frame.
  3. El **fondo negro** se reconoce estructuralmente: un `G_FILLRECT` negro cuyo rect **coincide con
     el panel canónico** (o que, viniendo antes, es él mismo un panel derecho) recibe `kRight` y se
     reconstruye anclado al panel.
  4. `right_panel_box`/`right_panel_scissor` son las funciones únicas del criterio (no hay números
     mágicos fuera de "mitad derecha" y "no ancho completo").
- **Consecuencias:**
  - El anclaje del minimapa es **independiente del área/capítulo** (no depende del hash ni de la
    dirección del overlay). Elimina la clase de fallo #7/#13 en su raíz.
  - Se clasifican además **2 listas más** del mismo grupo (mismo viewport, p. ej.
    `dl:0x800433e0#4993da10`, `dl:0x8017b3e0#df0069a1`) que antes quedaban `kAuto`; pasan a anclarse
    junto con el mapa.
  - Riesgo de **over-match** si alguna otra pantalla dibuja una lista bajo un panel derecho. Medido en
    los replays disponibles (mapa): **no** aparece ningún panel derecho ajeno; el replay de título/menú
    **no** detecta panel. Confirmado **sin over-match en Windows en todos los niveles** probados.
  - El resto del HUD (izquierda: radial, POWER/STAMINA, combo) **no cambia**: el arreglo se limita al
    criterio de `kRight` del minimapa.
- **Alternativas descartadas:**
  - **Otro par de hashes** para 3-1: mismo problema estructural, volvería a romperse en la siguiente
    área (#3/#7/#13 son el mismo patrón).
  - **Clasificar el mapa por viewport** (el contenido comparte `0x8025b628`): el viewport es una
    dirección de módulo relocalizable → no es identidad estable; el scissor/panel sí es geometría.
  - **Clasificar por color** (fondo negro): ambiguo (letterbox, fundidos, otros clears).
  - **Carril/callback del HUD** (propuesto como pista): la vía del callback nativo es más profunda;
    el panel por scissor ya agrupa todo el grupo del mapa sin tocar el juego.
- **Criterio de salida (CUMPLIDO):** el minimapa queda **dentro de su panel** en **todos los niveles**
  en **Windows**, sin cambios en el HUD izquierdo ni en menús. Evidencia:
  `notes/2026-10-02-fix-minimapa-estructural-issue13.md`.

> Nota: no sustituye a ADR 0007/0009; es una decisión local del reescritor de HUD. Si en el futuro se
> generaliza el anclaje estructural a *todo* el HUD (dejar de usar hashes también en combate), se
> supersede con un ADR nuevo.
