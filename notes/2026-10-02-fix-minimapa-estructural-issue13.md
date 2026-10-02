# 2026-10-02 — #13 minimapa: anclaje ESTRUCTURAL (hash fuera) — ARREGLADO y VALIDADO

> Fix definitivo del **issue #13** (HUD/minimapa desanclado al cambiar de Área). **Validado en Windows
> en todos los niveles** (2-1, 3-1, 4-1 y el resto de áreas probadas): el minimapa queda **dentro de su
> marco** en cualquier Área/capítulo. Decisión estructural: **ADR 0015**. Distinción **medido** /
> **inferido** explícita.

## Síntoma y causa

Al entrar en un **Área nueva** (reportado en 3-1; se preveían 4-1…) el **minimapa salía fuera de su
marco**; la salud/POWER/STAMINA iban bien. El `class_of` (`src/hooks/hud_rewrite.cpp`) anclaba el
minimapa (`kRight`) por **hash de contenido** de sus listas (`0xbbb8c0ba`/`0x1427da33`) tras el fix del
issue #7. El overlay del mapa **se recarga por escena/capítulo**, así que en un Área nueva el hash es
otro → `kAuto` → el contenido no recibía `viewport_align(RIGHT)` y se dibujaba fuera del panel.

Patrón recurrente #3/#7/#13: **anclar por detección/hash es frágil**.

## Medición (headless Linux, `HH_REPLAY` + F7/trazas)

Replay `work/debug/replays/hh_replay_map.txt`; trazas `HH_HUD_REWRITE_TRACE` + `HH_HUD_SITES_TRACE` +
`HH_HUD_DRAWS_TRACE`.

**Antes (v0.6.0, por hash):** `kRight` = 3 identidades: `dl:0x03000f10#1427da33`,
`dl:0x030002e0#bbb8c0ba` y el fill `fill:0x00000000@197,143,277,223`.

**Medido con contexto (scissor + viewport):**

| identidad | scissor (320x240) | viewport (w1) | clase antes |
|---|---|---|---|
| `dl:0x03000f10#1427da33` | `197,143..277,223` (panel) | `0x8025b628` | `kRight` (hash) |
| `dl:0x030002e0#bbb8c0ba` | `197,143..277,223` (panel) | `0x8025b628` | `kRight` (hash) |
| `dl:0x800433e0#4993da10` | `197,143..277,223` (panel) | `0x8025b628` | `kAuto` |
| `dl:0x8017b3e0#df0069a1` | `197,143..277,223` (panel) | `0x8025b628` | `kAuto` |
| `dl:0x80181860#e59a0172` (dial radar) | `0,0..320,240` (full) | `0x8025a658` | `kLeft` |
| `fill:0x00000000@197,143,277,223` | `0,0..320,240` (full) | `0x800433a0` | `kRight` (posicional) |

Hechos medidos:
- El **contenido** del minimapa se dibuja bajo un `G_SETSCISSOR` de **panel** (`197,143..277,223` =
  `0x31423C`/`0x45437C` en cuartos de px): **no cubre el ancho** del framebuffer y cae en la **mitad
  derecha**.
- Las **4** listas del grupo del mapa comparten **viewport** (`0x8025b628`), distinto del estándar del
  HUD izquierdo (`0x800433a0`) y del dial (`0x8025a658`).
- El scissor de panel está vigente **antes** de cada `G_DL`, así que se decide en el punto de
  clasificación del `dl`.

## Solución (criterio estructural)

Ver **ADR 0015**. En `src/hooks/hud_rewrite.cpp` (+ comentario en `include/hh/hudrewrite.h`):

- **Se eliminan** de `class_of` los 2 hashes `dl:` del mapa y el fill posicional.
- `right_panel_box(ulx,uly,lrx,lry)`: rectángulo **no** de ancho completo, dentro de pantalla,
  `ulx ≥ fb_width/2`, ≥ 8 px de lado. `right_panel_scissor()` = el scissor vigente cumple eso.
- Toda lista `dl` (call o branch) bajo panel derecho → `kRight`; el primer panel detectado fija el
  **panel canónico** del frame.
- El **fill negro** que coincide con el panel canónico → `kRight` (y si llega antes, lo establece).
- Traza nueva `[hh-panel]` (bajo `HH_HUD_REWRITE_TRACE`) con la caja del panel estructural.

No hay números mágicos del recurso: solo "no ancho completo" + "mitad derecha".

## Validación

**Headless (medido):**
- **Independencia del hash**: tras quitar la rama de hash, el minimapa **sigue** clasificándose `kRight`
  (5 identidades). Esto **reproduce la condición de 3-1** (hash desconocido) sin depender del recurso.
- **Sin over-match**: mapa `kLeft`=3 / `kRight`=5 (todas del grupo); título/menú: **0** paneles y **0**
  clases. Ninguna identidad izquierda pasó a derecha.
- Panel detectado `[hh-panel] panel derecho estructural @ 197,143..277,223`; fondo `[hh-bg] ... ->
  bg=198,144..276,222` (idéntico a antes).

**Windows (validado por el mantenedor, 2026-10-02):** el minimapa queda **dentro de su marco en todos
los niveles** probados (2-1, 3-1, 4-1 y resto), sin regresión en el HUD izquierdo ni en menús.

## Evidencia

- `build/linux/hh_hud.log` (regenerable con `HH_HUD_REWRITE_TRACE=1`) y `hh.log`
  (`[hh-panel]`, `[hh-bg]`, `[hh-draw]`).
- Decisión: `docs/adr/0015-anclaje-estructural-minimapa.md`.
- Antecedente: `notes/2026-09-26-fix-minimapa-contenido.md` (issue #7, hash) y
  `notes/2026-10-02-handoff-bugs-13-14-hud-y-veneno.md`.
