# Issue #3 — HUD de combate: anclaje por identidad de contenido (RESUELTO)

> **Sesiones 2026-09-25.** Cerrado y **validado en Windows** en las 3 partes. Aquí queda el cómo,
> la herramienta usada (captura pareada F10) y los errores a no repetir.

## Resumen de los arreglos (issue #3)

Todos en `src/hooks/hud_rewrite.cpp` (`class_of`) salvo lo indicado. Regla transversal: **la
dirección RDRAM no es identidad**; se clasifica por lo que se dibuja (hash de contenido, caja,
posición) — nunca por color.

1. **POWER/STAMINA** (ya en `d820d8e`, validado): hash de **contenido** de la textura (primeros
   64 B) en vez de `tex:<direccion>#<hash>`, porque el módulo de combate (file 57) se carga en
   memoria dinámica y cambia de dirección cada encuentro.
2. **Disco plateado del radial** (validado): el par `a3036828` (aro/fondo) + `dfde6ac5` (capa azul)
   se ancla por **hash + caja exacta `27,19,59,51`** (32×32). El hash `dfde6ac5` es una máscara
   compartida (~200 usos: minimapa, menús) → la **caja** lo desambigua. `box` también cubre el
   anclaje de la capa `dfde6ac5` del propio radial.
3. **Barra de combo** (validado): son **4 `G_FILLRECT`** en la fila `y=28..30` (x 64..182). Se
   anclan por **posición** (`kLeft`). El color NO sirve (rojo→azul→parpadeo) y la traza lee
   `fill_color=0` porque **RT64 pinta el relleno con el PRIM color**.
4. **Herramienta F10 — captura pareada** (nueva): ver más abajo.

(Detalle de cada uno y de los intentos descartados, en el resto de la nota.)

## Qué es `d820d8e` (SÍ commiteado, SÍ validado)

`fix(hud): anclar el HUD de combate por contenido, no por direccion (issue #3)` — cambia
`class_of` (`src/hooks/hud_rewrite.cpp`) + `hudid.h` (`texture_hash`/`parse_hash`). Las texturas
POWER/STAMINA se clasifican por **hash de contenido** (primeros 64 B) en vez de por
`tex:<dirección>#<hash>`.

- **Validado por el mantenedor**: el 1er y 2º combate se arreglaron (POWER/STAMINA) y siguen
  funcionando. El mecanismo es correcto: la **dirección RDRAM no es identidad**; el hash sí.

## Piezas añadidas (commiteadas con el cierre)

- **`class_of(identity, box, env_colour)`** (`hud_rewrite.cpp` + `hudrewrite.h`): acepta caja
  (ulx,uly,lrx,lry en 320x240) y color de entorno para desambiguar hashes compartidos.
- **Disco del radial** (`a3036828` + `dfde6ac5`): **hash + caja exacta `27,19,59,51`**. Validado.
- **Traza `rect_begin`**: volcado del scissor vigente por rect clasificado.
- **F10**: captura pareada (traza + imagen), ver §Captura pareada.
- **Intento de combo por `dfde6ac5` 32×32**: **descartado y retirado** (falso positivo: no era la
  barra de combo; con `dfde6ac5` compartido habría over-match). La solución real es el fill por
  posición (§RESUELTO).

## La barra de combo (planteamiento original del problema)

**Síntoma**: los segmentos de la barra de combo (la que se «gasta» al ejecutar combos) están
desplazados a la derecha y hay que llevarlos a la izquierda, igual que POWER/STAMINA.
**Resuelto**: son 4 `G_FILLRECT` en `y=28..30` (ver §RESUELTO).

**Lo que se sabe con datos (no adivinar):**

- La barra de combo tiene **estados según los segmentos gastados**: **rojo → azul oscuro** y, al
  cambiar, un **parpadeo multicolor** en la transición. El color **parece no ser fiable** (además
  de que el modelo de esta sesión no lo reconoce bien: confundió verde con rojo varias veces).
  **No usar el color como criterio.**
- **Tampoco el hash solo**: `dfde6ac5` (máscara reutilizada) sale en ~100 sitios
  (radial, minimapa, menús, barras).
- En una run con el combo visible (16:52), los únicos `dfde6ac5` **32x32** que no eran el radial
  eran `133,114,165,146` y `156,114,188,146` (2 segmentos), y salían **`cls=0`** (no anclados).
  Por eso se probó el criterio «`dfde6ac5` 32x32 y no radial» → **pendiente de validar**.
- Todos los `rect_begin` de esa run tenían scissor **full-frame `0,0..320,240`** → `widen_scissor`
  no hace nada; el anclaje lo produce `SetRectAlign(LEFT)` (el mismo camino que el disco, que sí
  funciona).

**Hipótesis abiertas (sin confirmar):**

1. El combo son esos `dfde6ac5` 32x32 → el criterio actual debería bastar. No validado.
2. Puede haber **más segmentos** de otros tamaños/posiciones que el criterio 32x32 no coge.
3. El mantenedor describe los segmentos como **barras finas y largas** (≈5:1 ancho/alto); si la
   textura es 32x32 y el juego la estira, el rect del draw no sería 32x32. **Confirmar midiendo
   el rect real** (no la textura) con la traza.

## Errores de esta sesión (para no repetir)

- **El color no es fiable** para este modelo: confundió **verde** (PUNCH/KICK/COMBO son tiras
  verdes) con rojo repetidamente. Además la propia barra de combo cambia de estado
  (rojo → azul → parpadeo). **No basar la clasificación en el color.**
- Se dio por bueno `c5a3d327` como «combo»: era un falso positivo (no movía nada).
- Se tomaron coordenadas de capturas a 2560 como si fueran 320x240 sin corregir escala/offset
  (área 4:3: escala 6, offset x=320). Medir SIEMPRE con el análisis de píxeles del PNG, no a ojo.

## Protocolo recomendado para la sesión nueva

1. **No fiarse del color.** Usar solo: hash de contenido + caja + (si hace falta) color como
   pista secundaria, nunca como criterio único.
2. Medir el **rect real del draw** (no la textura) con la traza F10 → `hh_hud.log`
   (`tex rect ... box ulx,uly,lrx,lry`).
3. Localizar la barra de combo en una captura con el combo visible analizando **píxeles** (PNG),
   corrigiendo escala (6) y offset (x=320) del área 4:3.
4. Cruzar caja real ↔ hash y clasificar por **hash + caja**. Validar en Windows.
5. Cuidado con over-match: `dfde6ac5` es máscara compartida; clasificar solo con la caja exacta.

## Ficheros tocados (working tree, sin commitear)

`include/hh.h`, `include/hh/hudrewrite.h`, `src/hooks/dl_snap.cpp`, `src/hooks/hud_rewrite.cpp`,
`src/subsystems/input.cpp`. Build Linux OK; tests deterministas de `class_of` en verde.

## Sesión 2026-09-25 (2.ª) — reintentos fallidos y captura pareada

**Dos intentos de clasificar el combo que NO valieron** (revertidos; ver working tree sin committear):
- **Banda vertical `dfde6ac5` y∈[100,160]** → movió el **menú de acciones** (PUNCH/KICK/COMBO), que
  usa la misma máscara y **no** es la barra de combo. El usuario lo confirmó en captura.
- **`f619e975`** (9 tramos) → era una **fuente/atlas compartido**: movió el **menú principal**.
- Conclusión: ni `dfde6ac5` en esa banda ni `f619e975` son la barra de combo; **no identificada aún**.

**Herramienta nueva: captura PAREADA con F10** (para atar `box` del trace a píxeles, de una vez).
Cada **F10** abre una captura nueva y guarda, en el mismo instante:
1. `hh_cap_<n>.log` — traza de identidades 2D de **un frame** (walker `dl_snap` + reescritor
   `hud_rewrite`), con `box` y `prim`/`env`. Los `seen` de dedup se vacían por **época** de captura
   (`hud_capture_epoch`), así cada captura es completa.
2. `hh_cap_<n>.bmp` — imagen de la ventana (Windows: `PrintWindow`/`BitBlt`; ver
   `src/platform/rt64_render_context.cpp`).
Otro **F10** mientras la anterior sigue abierta la cancela. `HH_HUD_TRACE=1` /
`HH_HUD_REWRITE_TRACE=1` siguen volcando a `hh_hud.log` (traza continua).

**Próximo paso**: capturar la barra de combo **en rojo**, **en azul** y **parpadeando** (3×F10),
analizar el `.bmp` (píxeles) y cruzar con el `.log` del mismo índice. Los elementos vetados
(menú principal/fuente, menú de acciones) sirven de descarte.

## RESUELTO (2026-09-25, 3.ª) — la barra de combo son 4 `G_FILLRECT` en `y=28..30`

Con las **3 capturas pareadas** (`build/windows/bin/Release/hh_cap_1..3.{log,bmp}`) y el **Inspector
de RT64** (`HH_DEVELOPER=1`, capturas en `work/gameplay screenshots/HUD desfasado/Dev Panel/`):

- La barra de combo son **4 `G_FILLRECT`**: `@64,28,92,30`, `@94,28,122,30`, `@124,28,152,30`,
  `@154,28,182,30` (4 segmentos con huecos de 2 px). En las 3 capturas son **idénticos** salvo el
  color.
- **Color plano** cambia: rojo `(255,0,0)` → azul `(0,0,128)` → parpadeo `(210,136,214)`.
- **La traza miente con el color**: la identidad sale `fill:0x00000000@...` (fill_color=0) en las 3,
  porque **RT64 pinta el relleno con el PRIM color**, no con el fill color. El Inspector lo confirma:
  draw bajo el cursor = **`Rect 64,28,92,30`**, 2 triángulos, **PrimColor rojo**.
- En la traza salían **`class 0`** (sin anclar). El relleno de POWER (`@64,24,183,27`) sí casaba con el
  prefijo `fill:0x00000000@64,24,` y se anclaba; la fila de combo (`y=28..30`) no.

**Fix** (`src/hooks/hud_rewrite.cpp`, `class_of`): clasificar los fills de la fila de combo por
**posición** (`uly>=28 && uly<=30 && lry 30..32` → `kLeft`), sin usar color. Mismo camino que el
relleno POWER/STAMINA (SetRectAlign LEFT). **Pendiente validar en Windows** (1.º/2.º combate + que no
se muevan menú principal ni menú de acciones).
