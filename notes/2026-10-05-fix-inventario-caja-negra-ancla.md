# 2026-10-05 — inventario: caja negra anclada a la derecha — ARREGLADO y VALIDADO

> Estado: **validado por el mantenedor en Windows (2026-10-05)**. Continúa el handoff
> `notes/2026-10-05-bug-inventario-recuerdo-negro-desplazado.md` (síntoma y evidencia; no lo repite).
> **MEDIDO** (nota #13, ADR 0015): el fondo del minimapa es `fill:0x00000000@197,143,277,223` (320x240).
> **INFERIDO**: la caja del inventario no coincide con esa caja (el fix funciona sin reclasificarla).

## Causa (localizada en código)

`src/hooks/hud_rewrite.cpp`, `case kFillRect`: si el fill es negro (`fill_colour == 0`), no hay panel
capturado y la caja pasa `right_panel_box()` (mitad derecha, no ancho completo, ≥8 px), se marcaba como
**fondo del mapa** (`kRight`), fijando `map_panel_w0/w1` con esa misma caja y reconstruyendo el rect con
origen derecho → la caja se **ancla a la derecha** y se mueve con el aspecto. Generalización introducida
por el fix del **#13** (`7068f5b`): antes el fondo se identificaba por su **caja** (`197,143,277,223`);
ahora "cualquier fill negro a la derecha" → la caja del inventario caía en el falso positivo (la caja
**no debía tocarse**).

## Fix (quirúrgico)

En `src/hooks/hud_rewrite.cpp`:

- Nuevo `Writer::is_map_bg_box(ulx,uly,lrx,lry)`: la **caja canónica** del fondo del minimapa
  (`197,143..277,223` en 320x240, tolerancia ±1 px por el redondeo de `to_320`).
- La rama que **establece** el panel con un fill negro pasa de `right_panel_box(...)` a
  `is_map_bg_box(f_ulx,f_uly,f_lrx,f_lry)`. La rama "coincide con el panel ya capturado" no cambia.
- Traza `[hh-mapbg] fill negro box=... sc=... have_panel=... canon=...` (dedup por caja, bajo
  `HH_HUD_TRACE=1`/F7): deja la identidad de cada caja negra con forma de panel.

Efecto: el fondo del mapa (caja canónica) sigue `kRight`; la caja del inventario queda `kAuto`
(**quieta**, junto a su panel). No se añade ancla nueva; no se toca el contenido del mapa ni las barras
del HUD de combate.

## Validación

- **Windows (mantenedor, 2026-10-05)**: la caja negra del inventario queda **junto a su panel** en los
  ratios probados (16:9 y 4:3); el **minimapa** sigue anclado; sin regresión visible en las barras del
  HUD de combate.
- **Compilación Linux** (`build/linux`, incremental): OK. Aviso MSVC corregido: el lambda no puede
  llamarse `near` (palabra clave legacy de MSVC) → `close_enough`.

## Evidencia

- Capturas: `work/gameplay screenshots/items/` (16:9 y 4:3).
- Traza: `build/windows/bin/Release/hh_hud.log` con `HH_HUD_TRACE=1` (líneas `[hh-mapbg]`).
- Antecedentes: `notes/2026-10-05-bug-inventario-recuerdo-negro-desplazado.md`,
  `notes/2026-10-02-fix-minimapa-estructural-issue13.md`, `docs/adr/0015-anclaje-estructural-minimapa.md`.

## Nota (por si reaparece)

Si el recuadro del inventario volviera a anclarse, comprobar si su `sc` pasa `right_panel_scissor` (la
captura del panel por scissor, `~hud_rewrite.cpp:615`, también habría que acotarla a la caja canónica).
