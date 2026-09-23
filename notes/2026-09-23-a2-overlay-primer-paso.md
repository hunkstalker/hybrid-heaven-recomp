# A2 — Overlay propio: intento por GBI (fallido) y cambio de vía al render hook

> Sesión 2026-09-23. Primer paso de A2 (overlay moderno imitando al juego). Se intentó dibujar el
> overlay **inyectando GBI en la display list del juego** (patrón `hud_rewrite`). El overlay
> **funciona al arrancar** pero **no llega al frame presentado** el resto del tiempo. Se documenta
> aquí el intento, los fallos encontrados y el **cambio de vía** decidido.

## 1. Qué se intentó (y se ha retirado del árbol)

Se implementó `hh_font` (atlas de la fuente del juego + `draw_text` con `G_EX_TEXRECT_V1`) y
`hh_overlay` (inyección del rótulo en la copia del HUD), enganchado en `send_dl`. Se ha **revertido**
para no dejar código muerto; queda documentado aquí y en `RETOMAR.md`.

## 2. Fallos reales encontrados por el camino (útiles para el futuro)

- **Coordenadas de `G_TEXRECT`/`G_EX_TEXRECT_V1` en CUARTOS de píxel** (10.2 fijo), como el comando
  nativo. Pasábamos píxeles → todo salía a **1/4** (`92,20` → `23,5`). Lo confirmó el Inspector de
  RT64 (`Rect: 368 80 400 112 (92.00 20.00 100.00 28.00)`).
- **Cycle type del othermode va en la palabra H** (bits 20-21), no en L. `G_RDPSETOTHERMODE` con
  `high=0` y el cycle en `low` no ponía `G_CYC_FILL` (el fill salía `cycle=0`).
- **Colisión de memoria**: agrandar el scratch del HUD a `0x600000` chocaba con un **framebuffer del
  juego** (el menú vive en `0x600000`). El juego usa framebuffers en `0x400000..0x7A0000`; el scratch
  debe quedarse en `0x7A0000/0x7C8000`.
- El texto del menú del juego se dibuja en el framebuffer **`0x600000`**; nuestro overlay GBI acababa
  en `0x3B5000`/`0x3DA800`/`0x38F800` (buffers de render). **Distinto buffer → no se ve.**
- La copia del HUD no desbordaba (máx. ~16-22 KB) y la DL del menú es plana (1 `ENDDL`), así que el
  overlay sí se inyectaba al final; el problema no era ese.

## 3. Causa raíz y decisión

RT64 **no presenta directamente** el framebuffer del juego: lo **compone** (VI renderer) sobre el
**swapchain**. Los draws GBI inyectados quedan en un framebuffer de juego y no en el swapchain
presentado. Aunque rect/combine/textura/framebuffer eran correctos (lo confirma el Inspector), el
resultado no llega a pantalla.

La vía **correcta y documentada** en N64Recomp es dibujar la UI en el **render hook de RT64**
(`RT64::SetRenderHooks(init, draw, deinit)`, `lib/rt64/src/rhi/rt64_render_hooks.h`), que entrega el
**command list de plume** y el **framebuffer del swapchain** al final del frame. Es lo que usan
**Goemon** (RmlUi + plume) y **recompui** (RecompFrontend, RmlUi oficial). `recompui = render hook +
RmlUi encima`; el render hook es la base de ambos.

**Decisión**: A2 se implementa sobre el **render hook + plume** (opción A), y si se quiere UI moderna
completa (TTF, layout) se añade **RmlUi/recompui** encima (opción B) reutilizando el mismo hook.

## 4. Regla de trabajo (recordatorio)

- **No dejar restos de código de pruebas** en el árbol: los diagnósticos se hacen con variables de
  entorno y **se retiran al cerrar la tarea**. Nada de código muerto ni experimentos abandonados.
- Validar **visualmente en Windows** (headless Linux no reproduce el arranque de forma fiable) y usar
  el **Inspector de RT64** (`HH_DEVELOPER=1` + F1) para draw calls/framebuffers.

## 5. Siguiente paso (sesión nueva): A2 en DOS fases

**Fase A (base, ahora)** — render hook de RT64 + plume propio:

1. Shaders `OverlayVS/PS.hlsl` + compilación con `build_vertex_shader`/`build_pixel_shader` de RT64
   (DXC de `lib/rt64/src/contrib/dxc`), como hace Goemon (`shaders/InterfaceVS|PS.hlsl`). Requiere
   re-declarar `DXC*_OPTS` en nuestro `CMakeLists.txt` (no son visibles desde el scope padre) y
   añadir `${CMAKE_BINARY_DIR}` a los includes (los `.spirv.h`/`.dxil.h` se generan ahí).
2. Módulo de render hook: `init` (pipeline plume, sampler, descriptor set, textura del atlas) y
   `draw` (quad texturizado por glifo, viewport/scissor del swapchain, push constant con la
   proyección ortográfica 320×240→clip). Registrar con `RT64::SetRenderHooks(...)` tras
   `app->setup()`.
3. Atlas de la fuente del juego en **RGBA8**: **HECHO** el decoder (`hh::font::game`,
   `include/hh/font.h` + `src/subsystems/font.cpp`, sin GBI): `init()` lee la ROM (color0, fichero
   107) y construye un atlas RGBA8 128×32; `atlas_rgba8()`/`glyph_uv()`. Fase A solo sube el atlas
   como textura de plume.
4. Validar el rótulo; luego `hh_menu` (entradas/cursor/acciones).

**Fase B (mejora, después de A)** — `recompui` (RecompFrontend) sobre **RmlUi**: UI tipo HTML/CSS,
layout, TTF, componentes. Reutiliza el MISMO render hook (RmlUi dibuja con plume). Referencia:
`/app/goemon-sourcecode/src/ui/ui_renderer.cpp` (clase `RmlRenderInterface_RT64_impl`, MIT). Detalle
en `RETOMAR.md` §"A2 tiene DOS fases".

Referencia mínima del pipeline plume: `lib/rt64/src/contrib/plume/examples/triangle/main.cpp`.
