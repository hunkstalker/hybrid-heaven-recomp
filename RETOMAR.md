# RETOMAR — fondo negro del mapa alineado con el contenido (widescreen, fase 07b)

> Handoff para **sesión nueva**. **Última sesión: 2026-09-22 (tarde).** Tarea: que el **fondo negro del
> mapa** (el `G_FILLRECT` del juego) cuadre con el **contenido** (mapa verde + flecha roja) bajo
> widescreen. El contenido se ancla y se recorta bien; el fondo (rect) quedaba desplazado respecto a él
> (~1 px en bordes, ~2 px en esquinas).
>
> **ESTADO**: el **fondo vuelve a ser rect** (se **abandonó** la vía del quad; ver §2). Los **parches de
> RT64 están APLICADOS** en `lib/rt64` (modificación local, ver §5) y **completados los bugs del quad**
> (por si se retoma). **Falta el ajuste fino de ancho/posición del fondo**, que se hace EN CALIENTE en
> Windows (ver §6) y luego se fija en el código. La tarea sigue **abierta**.

> **MÉTODO (lección de esta sesión)**: el mapa **solo se dibuja en Windows**. **NO** intentar
> reproducirlo en Linux headless: el port no llega a la escena del mapa con los replays actuales (se
> queda en la pantalla de carga). Cada minuto intentándolo ha sido un desperdicio. El dato debe salir
> de una **sesión del mantenedor en Windows**. No recompilar solo para `HH_HUD_DRAWS_TRACE` en consola:
> la build **Release es GUI** y no imprime; las trazas ahora van a **`hh.log`** (junto al exe) — ver §6.

> **Lee primero**: este fichero; `notes/2026-09-21-anclaje-hud-widescreen-radar.md` (contexto previo);
> `docs/BUILDING_windows.md` §“[video]”; `TODO.md`.

---

## 0. QUÉ ESTÁ HECHO Y QUÉ FALTA

### Hecho y validado en Windows (sesiones previas)
- **Radar** (`left`) y **HUD de combate POWER/STAMINA** (`left`): anclados, no se tocan.
- **Mapa**: el **contenido** (mapa verde + flecha roja) se ancla a la derecha y se recorta con el
  **scissor del panel** (`197,143..277,223`), recortado `kMapCrop` px por lado. Funciona.
- **Recorte en caliente**: `+`/`-` (numérico o `=`/`-`) ajustan `kMapCrop`. Traza: `[hh] recorte del
  mapa = N px`. Se conserva.
- **F11** cierra la aplicación.

### Hecho esta sesión (2026-09-22 tarde)
- **Bugs reales del quad, encontrados y corregidos** (en `src/hooks/hud_rewrite.cpp`):
  - **Opcode del triángulo**: estaba `G_TRI1 = 0xBF` (eso es **F3D**); el juego es **F3DEX2**
    (`docs/architecture.md`: «microcode F3DEX2 fifo 2.06»), donde `F3DEX2_G_TRI1 = 0x05`
    (`lib/rt64/src/gbi/rt64_gbi_f3dex2.h:43`). Con `0xBF`, RT64 **descarta el opcode en silencio**
    (`rt64_interpreter.cpp`: `if (func == nullptr) RT64_LOG_PRINTF("unknown opCode")`). **Era la razón
    principal de que el quad nunca se viera.**
  - **Tercer índice** del `G_TRI1`: iba en `<<25` (bit 26 = ya está en el opcode) en vez de `<<1`
    (campo real `p0(1,7)` que lee `tri1()`). Dejaba un triángulo degenerado.
  - **`extendRDRAM`**: la dirección de vértices `0x80000000|phys` exige emitir
    `gEXSetRDRAMExtended(1)` antes del `G_VTX` y `(0)` después (`RSP::maskPhysicalAddress` solo limpia
    el bit si `extended.extendRDRAM`, que **no** es el estado por defecto). Sin esto → `phys=0` (basura).
  - **Ciclo RDP**: el fill viene en `G_CYC_FILL`; un triángulo bajo FILL lo desvía RT64 a `FillRect`
    (clear, usa `callDesc.rect` vacío). Se fuerza `G_CYC_1CYCLE` alrededor del quad y se restaura.
  - **Culling**: con `G_CULL_*` activo RT64 descarta caras frontales; se apaga y se restaura.
  - Verificado con instrumentación temporal de RT64 (revertida): vértices cargados OK, draw procesado.

### Pendiente (esta tarea)
- **Ajustar ancho y posición del fondo negro** para que cuadre con el mapa verde. Se hace **en
  caliente** (§6) y luego se fija el valor en el código.
- **Descartada** la vía del quad (fondo como `G_TRI1`): ver §2 («por qué»). El fondo es **rect**.

---

## 1. CÓMO FUNCIONA (reescritor)

`src/hooks/hud_rewrite.cpp` recorre cada lista enviada, la copia a un scratch de RDRAM
(`0x7A0000`/`0x7C8000`, alternos) e envuelve cada elemento 2D **clasificado** con GBI extendido de
RT64. Identidades con hash (`include/hh/hudid.h`). Tabla fija en `class_of()`. Enganche en `send_dl`
(`src/platform/rt64_render_context.cpp`).

- **Panel único del mapa**: se fija **una vez** por frame del primer elemento `right` cuyo scissor NO
  cubra todo el ancho (el del contenido), y se reutiliza para todo lo `right`. Estados en `panel_done`
  (0 = sin fijar, 1 = por scissor, 2 = por rect/fill como fallback).
- `anchored_scissor(kRight, map_panel_w0, map_panel_w1, crop)` emite el scissor recortado del panel.
- **Fondo del mapa** (`case kFillRect`, `cls == kRight`): se emite **tal cual** el `G_FILLRECT` del
  juego, con `rect_begin/rect_end` que aplican `gEXSetRectAlign(G_EX_ORIGIN_NONE, G_EX_ORIGIN_RIGHT,
  leftOffset=0, topOffset=0, rightOffset=bg_shift, bottomOffset=-bg_crop)` (ver §6).
- El **panel canónico** (`map_panel_w0/w1`) se captura del scissor del contenido y se usa para recortar
  tanto el fondo como el contenido (mismo `anchored_scissor`).

**Gotchas**:
- El dial del radar va por **`G_DL` branch**; F3DEX2 `G_MOVEWORD` idx 6 con índice en bits 16-23; los
  fills a pantalla completa son *clears* (sin identidad); `gEXEnable` al inicio de cada lista.
- El fondo se dibuja **después** del contenido y su viewport vigente es otro (el del último elemento).

---

## 2. DIAGNÓSTICO (por qué rect y contenido se desfasan) y POR QUÉ SE DESCARTA EL QUAD

RT64 trata el mismo scissor por **dos caminos**:
- **Rects** (fill/texrect) → `convertFixedRect` (`coord - (coord % resScale)`, truncado) y, si "cubre
  el ancho del scissor", `invRatioScale=1` y `horizontalMisalignment=0`.
- **Triángulos 2D** (`Projection::Type::Orthographic`, el contenido del mapa) → `convertViewportRect`
  (`coord - fmod(...)`) y **sí** recibe `horizontalMisalignment`.
- Archivo: `lib/rt64/src/render/rt64_framebuffer_renderer.cpp` (~1547 rects, ~1627-1680 triángulos).

### Por qué se descartó pintar el fondo como quad (¡IMPORTANTE para no repetirlo!)
**El contenido del mapa NO es 2D en píxeles**: son **triángulos en espacio de mapa** (coords del orden
de `-1030..1027` en x, `-713..800` en y, z variable) transformados por un **modelview × proyección por
elemento** (el mvp cambia entre `G_VTX` consecutivos; lo verificamos con instrumentación de RT64). El
rect del juego, en cambio, es un `G_FILLRECT` **en píxeles de pantalla** que ignora matrices. Por eso:
- Un quad en **píxeles del panel** con la modelview vigente cae **fuera** de pantalla (posScreen ≈
  `(24..84, -71..1)`).
- Un quad en **espacio de mapa** hereda la matriz del **último** elemento del mapa y **gira con el
  mapa** (el mantenedor lo observó en Windows: «una línea negra que gira»). **Ese es el fallo**: metido
  en el mismo grupo/transformación que los quads del mapa, gira igual.
- **Conclusión**: el fondo NO puede compartir la transformación del contenido (no es única). La vía
  correcta es **rect + parches de RT64**.

El mantenedor lo explicó claro: lo verde son **figuras geométricas que representan el mapa**
(habitaciones) y la **flecha roja** la posición del jugador; es el mapa del juego, no un plano 2D.

---

## 3. PARCHES RT64 (APLICADOS en `lib/rt64`)

Los tres scripts están en `tools/`; **los dos primeros están aplicados** (modificación local del
submódulo, sin commit; ver §5). Son idempotentes y reversibles (`--check` / `--revert`):

1. **`tools/patch_rt64_misalignment.py`** — RT64 **issue #82**: `correctMisalignment` redondeaba
   siempre hacia abajo; con `G_EX_ORIGIN_RIGHT` debe redondear hacia arriba (afecta a
   `convertFixedRect` y `convertViewportRect`). **APLICADO.**
2. **`tools/patch_rt64_2d_misalignment.py`** — los triángulos ortográficos 2D **no** recibían
   `horizontalMisalignment` (solo los rects). El parche se lo aplica. **APLICADO.**
3. **`tools/patch_rt64_scissor_quant.py`** — cuantiza el scissor de triángulos (`fmod`) igual que el de
   rects (truncado). **NO aplicado**; probar **solo si tras 1+2 sigue habiendo desfase**.

Estado de parches: `python3 tools/patch_rt64_misalignment.py --check` y
`python3 tools/patch_rt64_2d_misalignment.py --check` → «aplicado».

---

## 4. ESTADO DEL CÓDIGO DEL QUAD (conservado por si se retoma)

El código del quad **se eliminó** de `hud_rewrite.cpp` en la limpieza final (estaba inactivo y hacía
ruido). Si se retoma, los hallazgos están en §0 y §2; el punto delicado es la **transformación por
elemento** del contenido (§2), no los bugs (ya resueltos y documentados arriba).

---

## 5. GIT / SUBMÓDULO RT64

- `lib/rt64` tiene **solo** `src/render/rt64_framebuffer_renderer.cpp` modificado (parches 1+2). No
  está commiteado. `git -C lib/rt64 diff` lo muestra.
- El build de Windows usa `lib/rt64` local (`SKIP_LIBS=1`), así que **los parches entran sin commit**.
- Al cerrar la tarea: commitear los parches en el fork de RT64 (o dejar documentado el procedimiento)
  según la política de commits. Alternativa oficial: proponer el fix upstream (issue #82).

---

## 6. AJUSTE DEL FONDO EN CALIENTE (lo que toca AHORA)

El fondo ya es rect y la build está lista. **El mantenedor ajusta en Windows en vivo** hasta que el
negro cuadre con el verde, y luego se fija el valor en el código.

Controles (sin recompilar):
- **`[` / `]`** → recorte del fondo por lado (`HH_MAP_BG_CROP`, reduce ancho/alto).
- **`;` / `'`** → desplazamiento horizontal (`HH_MAP_BG_SHIFT`, `+` = derecha).
- `+`/`-` → recorte del panel/scissor (`HH_MAP_CROP`), como antes.

Trazas (van a **`hh.log`** junto al exe, ya no a stderr — la Release es GUI):
- `[hh-bg] fill=A,B..C,D panel=… crop=… bg_crop=… bg_shift=…` (una vez): el rect del juego, el panel
  canónico y los ajustes actuales.
- `[hh-draw] …` (identidad, viewport, scissor), `[hh-scissor] …` (scissors únicos), `[hh-map] …`.
  Se activan con `HH_HUD_DRAWS_TRACE=1` / `HH_HUD_SCISSOR_TRACE=1` (a `hh.log`).

**Dato que necesito del mantenedor**: el `hh.log` tras abrir el mapa con **B**, o directamente el valor
de `[`/`]`/`;`/`'` que dejó el negro cuadrado. Con eso se fija el valor por defecto y se cierra.

---

## 7. CÓMO COMPILAR / EJECUTAR EN WINDOWS

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```
- **Gotcha MSBuild**: si un cambio no se ve, borrar `build\windows` (§ arriba) — `RETOMAR` clásico.
- No hace falta `regenerate.py` (el C recompilado no cambia).
- `hh.log` queda junto al exe:
  `hybrid-heaven-recomp\build\windows\bin\Release\hh.log`.
- Abrir el mapa con **B** (en gameplay/exploración).

---

## 8. FICHEROS

- **Nuevos**: `include/hh/hudid.h`, `include/hh/hudrewrite.h`, `src/hooks/hud_rewrite.cpp`,
  `tools/patch_rt64_misalignment.py`, `tools/patch_rt64_2d_misalignment.py`,
  `tools/patch_rt64_scissor_quant.py`, `record_input.bat`, `tests/replays/*`.
- **Modificados**: `src/hooks/dl_snap.cpp` (`hud_trace`, ahora a `hh.log`),
  `src/platform/rt64_render_context.cpp` (`send_dl`), `src/subsystems/input.cpp` (`+`/`-`,
  **`[`/`]`/`;`/`'`**, F11), `include/hh.h`, `CMakeLists.txt`, `docs/BUILDING_windows.md`, `TODO.md`,
  `.gitignore`, `RETOMAR.md`. `lib/rt64/src/render/rt64_framebuffer_renderer.cpp` (parches 1+2).

## 9. ENVS / INTERRUPTORES

- `HH_FULL_FRAME=0` — desactiva el widescreen (snap). Default ON.
- `HH_NO_HUD_REWRITE=1` — desactiva el anclaje del HUD (A/B). Útil para comparar.
- `HH_MAP_CROP=<px>` — recorte del panel/scissor (o `+`/`-`). Default `kMapCrop` (1).
- `HH_MAP_BG_CROP=<px>` — recorte del fondo negro (o `[`/`]`). Default 0.
- `HH_MAP_BG_SHIFT=<px>` — desplazamiento horizontal del fondo (o `;`/`'`). Default 0.
- `HH_HUD_DRAWS_TRACE=1` / `HH_HUD_SCISSOR_TRACE=1` / `HH_HUD_REWRITE_TRACE=1` — trazas (a `hh.log`).
- `config.ini [video] aspect` — `auto`/`expand` (widescreen), `original` (4:3).

## 10. PRIMEROS PASOS (sesión nueva)

1. **Compilar en Windows limpio** (§7) y abrir el mapa con **B** → leer `hh.log` (`[hh-bg]`).
2. Cuadrar el negro con **`[` `]` `;` `'`** y pasar el valor que encaje.
3. Fijar el valor por defecto en `hud_rewrite.cpp` (constantes del fondo), recompilar y validar.
4. Si tras 1+2 sigue desfasado, aplicar `tools/patch_rt64_scissor_quant.py` (parche 3) y reevaluar.
5. Cierre: actualizar `TODO.md`/`PROYECTO.md`, nota fechada en `notes/`, y commitear.
