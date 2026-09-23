# A2 — overlay por render hook de RT64: infra + atlas (Fase A)

> Sesión 2026-09-23 (2.ª del día). Implementa la vía decidida en
> `notes/2026-09-23-a2-overlay-primer-paso.md` (render hook de RT64 + plume) y cierra el "spike" del
> hook. Estado: **infra validada en headless**; alineación fina y supresión del texto del juego,
> pendientes de validar en Windows.

## 1. Hallazgo que corrige el handoff

El handoff decía registrar `RT64::SetRenderHooks(...)` **tras** `app->setup()`. Es **incorrecto**: el
hook `init` se invoca **DENTRO** de `Application::setup()` (`lib/rt64/src/hle/rt64_application.cpp:307`).
Hay que registrarlo **antes** de `setup()` (Goemon lo hace al inicio del constructor,
`goemon-sourcecode/src/main/rt64_render_context.cpp:207`). En el port: primera línea de
`hh::RT64Context::RT64Context` (`src/platform/rt64_render_context.cpp`).

## 2. Implementado

- **Shaders** `shaders/OverlayVS.hlsl` / `OverlayPS.hlsl` (estilo Goemon, MIT): VS con push constant
  `float4` (xy escala clip/unidad, zw offset) y PS que muestrea el atlas (sampler `s1/space0`, textura
  `t2/space1`) × color de vértice. Compilados a SPIRV (y DXIL/MSL según plataforma) con las funciones
  `build_vertex_shader`/`build_pixel_shader` de RT64; el `CMakeLists.txt` raíz re-declara las variables
  `DXC*` (no visibles desde el scope padre) y añade `${CMAKE_BINARY_DIR}` a los include dirs (los
  `.spirv.h`/`.dxil.h` se generan en `${CMAKE_BINARY_DIR}/shaders`).
- **Módulo render hook** `src/platform/overlay.cpp` + `include/hh/overlay.h`:
  - `init(rhi, device)`: shaders, sampler nearest, layout (set 0 = sampler inmutable + CB dummy por el
    workaround D3D12 de Goemon; set 1 = textura), pipeline (alpha blend, `B8G8R8A8_UNORM`), buffers
    dinámicos de vértices/índices (UPLOAD), textura 1×1 blanca para paneles, y **atlas de la fuente del
    juego** (`hh::font::game`) subido como textura RGBA8 por una cola de copia (fila alineada a 256 B).
  - `draw(list, swapchain_fb)`: lee el `Frame` publicado (mutex), construye TODA la geometría en un
    único buffer y dibuja por rangos de índices (paneles con la textura blanca, texto con el atlas).
  - `deinit()`: libera todos los recursos (imprescindible: `app->end()` llama al deinit antes de
    destruir el device).
  - **Trampa resuelta**: subir dos veces el mismo buffer antes de que se ejecute la command list hacía
    que ambos draws leyeran el último dato (el panel "dibujaba" texto). Solución: una sola subida y
    `drawIndexedInstanced` con `startIndex`.
- **`hh_menu` (título)**: `src/hooks/menu_overlay.cpp` + `src/hooks/sections.cpp`.
  - `hh_title_menu_hook` sustituye `0x801C1DB8` (handler del menú de título, módulo 23) y **delega en
    el original** (el menú del juego sigue funcionando y **su texto queda visible**, por decisión del
    mantenedor, para poder alinear el overlay encima).
  - Tras el original, lee el estado REAL y publica el frame: etiquetas en
    `base(0x801BF1A0) + 0xFA14 + 16*idx` (idx 1..5) y selección en `0x801CC8C4`. Verificado en
    headless: `' NEW GAME   '`, `' CONTINUE   '`, `' BATTLE MODE'`, `' SOUND      '`,
    `' RESOLUTION '`.
  - Re-registro del override tras cada carga de módulo (`register_title_menu_hook` en
    `announce_load`): el loader reescribe `func_map` y borraría el override.
  - `tick()` (hilo de render) oculta el frame si el menú deja de publicarlo.
- **Toggle F6** (`src/subsystems/input.cpp`): muestra/oculta el overlay (para comparar con el texto del
  juego). Offset de alineación: `HH_OVERLAY_X` / `HH_OVERLAY_Y` (unidades virtuales 320×240).
- Diagnósticos: `HH_OVERLAY=0` desactiva el overlay; `HH_MENU_TRACE=1` loguea etiquetas y `sel`.

## 3. Validación (headless Linux, Xvfb + lavapipe)

- **Spike del hook**: un quad verde se presenta **encima** del frame del juego (intro KONAMI), no en un
  framebuffer interno → confirma registro/init/draw/deinit, viewport/scissor, proyección y present
  sobre el swapchain compuesto.
- **Atlas/texto**: panel + texto con la fuente del juego legible sobre la intro (captura con un frame
  de prueba; ya retirado).
- **Hook del título**: `[menu] a0=... sel=0` + etiquetas leídas correctamente (arriba).
- **No validado**: el overlay **sobre el menú de título** (el headless alcanza el menú de forma
  intermitente y con timing variable; la ventana se desplaza entre ejecuciones). Validar en Windows.

## 4. Siguiente

1. **Validar en Windows**: `HH_MENU_TRACE=1`, entrar al menú inicial; ajustar `HH_OVERLAY_X/Y` hasta
   que los textos del overlay coincidan con los del juego; comprobar F6.
2. **Suprimir el texto del juego** una vez alineado (override del constructor `func_801C18FC` con
   etiquetas vacías, o supresión selectiva del draw de texto).
3. **`hh_menu`**: cursor/navegación/acciones propias; después `backend_modern` (TTF) o migrar a
   recompui/RmlUi (Fase B).

> **Nota (gap conocido)**: `hh_pc_menu_register()` (submenús AJUSTES/IDIOMA de la sesión anterior)
> sigue **desactivado** (decisión de la 1.ª sesión: sustituirlo por el overlay). Hasta que `hh_menu`
> implemente esas entradas, AJUSTES abre el submenú de SONIDO original y el selector IDIOMA in-game
> no está disponible (sí el cambio de idioma en vivo con **F5**).

## 5. Herramientas de la sesión

- `work/debug/hh_replay_title.txt` (gitignored): replay sintético que pulsa START cada 3 s desde t=35 s;
  sirve para acercarse al menú de título en headless (`HH_REPLAY=<ruta> HH_REPLAY_PACE=1`). El formato
  de 5 campos (`t vis botones x y`) es obligatorio: con 4 campos el parser confunde `vis` con botones y
  la máscara sale siempre 0.

## 6. Validación en Windows (2026-09-23) y alineación
El mantenedor validó en Windows (2560×1440, aspecto expand). Resultado: **funciona** — el overlay
dibuja las etiquetas con la fuente del juego y **la entrada seleccionada se resalta al mover el cursor
del juego** (enlace con el menú real confirmado). Sale **duplicado** (texto del juego + nuestro
overlay), que es lo esperado hasta suprimir el del juego.

Medición del desfase (imagen 2560×1440; virtual 320×240 → escala 8×6; mismo tamaño de glifo en ambos):

| | nuestro (amarillo) | juego | desfase |
|---|---|---|---|
| línea 1, x | 80 | 1046 | +966 px = **+120.75 virtual** |
| línea 1, y (top) | 714 | 738 | +24 px = **+4 virtual** |

Defaults actualizados en `src/hooks/menu_overlay.cpp` (`g_offset_x = 120.75`, `g_offset_y = 4.0`).
Ajuste fino sin recompilar: `HH_OVERLAY_X` / `HH_OVERLAY_Y`.

**Ojo con el aspecto**: el offset asume que el juego llena el ancho (aspecto expand/16:9). Con
aspecto `original` (4:3) el juego va pillarboxeado y el overlay se estira a todo el ancho → no
coincidirían. Pendiente de manejar si se quiere soportar 4:3.

### 6b. "Texto duplicado" = sombra del glifo 2bpp (corregido)

Síntoma: el texto del overlay se veía **doblado** (el usuario lo confirmó con F6: al ocultar el
overlay desaparecían el texto y su "duplicado", así que era 100% nuestro).

Diagnóstico (capturas `203525` overlay ON / `203528` F6 OFF):
- Con F6 OFF solo queda el menú del juego (un bloque): el juego dibuja su menú una vez.
- **Correlación de nuestro bloque con nuestro render esperado: residuo = 0** → no hay doble `draw`.
- Decodificando los niveles del glifo 2bpp (p. ej. `'E'` valor 41): **nivel 1 = glifo principal**
  (forma limpia), **nivel ≥2 = sombra** (copia desplazada abajo-derecha). El motor los pinta en dos
  colores; nosotros pintábamos todo con el color de texto → se veía como copia sólida.

Corrección:
- `src/subsystems/font.cpp` (`bake_atlas`): `R = (lvl == 1) ? 255 : 0`, `A = (lvl != 0) ? 255 : 0`.
- `shaders/OverlayPS.hlsl`: `col = lerp(negro, iColor.rgb, t.r)` → nivel 1 = color de texto, sombra =
  negro. (Los paneles usan la textura 1x1 blanca, R=255, así que salen con el color de vértice.)

### 6c. Tamaño del texto y proyección uniforme

Medido a 2560 de ancho: el menú del juego avanza **~46 px/glifo** con glifo de **~42 px** de alto
(cuadrado, 4:3). El texto 2D del juego **no lo toca el widescreen** (validado quitándolo: el ancho no
cambia). El deformado era **nuestro overlay**: mapeábamos el espacio virtual 4:3 (320×240) al ancho
16:9 → escala X=8, Y=6, así que a escala 1.0 el glifo salía 64×48 (estirado).

Solución (limpia, sin trucos): **proyección uniforme (píxel cuadrado)** en `src/platform/overlay.cpp`
(`draw_hook`): `k = alto/240` px por unidad virtual, centrado horizontalmente
(`offset_x = -(320·k)/width`). Así el área 4:3 queda centrada como el 2D del juego y los glifos se
dibujan a **tamaño nativo con `scale = 1.0`** (8 px → 48 px, igual que el juego). No hace falta el
`0.75` anterior.

**Calibración en vivo** (con el overlay visible, F6): `Ctrl+←/→` mueve X, `Ctrl+↑/↓` mueve Y,
`Ctrl+RePág/AvPág` escala Y, `Ctrl+Inicio/Fin` escala X; cada cambio se escribe en `hh.log`
(`[overlay] calib x=.. y=.. sx=.. sy=..`). Ver `src/subsystems/input.cpp` y
`hh::menu_overlay::adjust`.

**Valores actuales**: `x=112.0`, `y=5.0`, `scale_x=1.0`, `scale_y=1.0` (defaults en
`src/hooks/menu_overlay.cpp`); la alineación queda clavada sobre el texto del juego (captura
`2026-09-23 212404.png` con el sistema anterior, equivalente). Ajustables con `HH_OVERLAY_X/Y/SX/SY`.

Nota: el decode 2bpp de `font.cpp` es **correcto** (verificado contra la tabla real del motor en
`0x800446AC`: `'A'→37` bloque 18 paridad 1; `'B'→38` y `'C'→39` comparten el bloque 19). El contacto
4bpp de `font_dump.py` era una vista alternativa (unión de los dos glifos empaquetados).

## 7. Efectos de sonido del menú (SFX)

El juego no tiene SFX de UI decentes; se añadieron propios (`assets/sounds/*.wav`, aportados por el
mantenedor). Implementación en `src/platform/menu_sfx.cpp`:

- **Un solo dispositivo**: se **mezclan sobre el stream de audio del juego** (`hh::menu_sfx::mix`
  llamado desde `hh::queue_samples`), no con un segundo dispositivo SDL (fallaba en algunos drivers:
  "Audio device already open"). Resample a la tasa real del dispositivo (`hh::audio_output_rate()`).
- **Assets**: los `.mp3` de origen se convirtieron a **WAV 48 kHz/S16/estéreo** (ffmpeg) para no
  añadir decodificador de mp3. En la release se copian **solo los `.wav`** a `sounds/` junto al
  ejecutable (`CMakeLists.txt`); los `.mp3` quedan como fuente en `assets/sounds/`.
- **Disparo por CAMBIO REAL, no por pulsación** (un botón puede no hacer nada: arriba en la primera
  entrada, A sobre una opción deshabilitada, B sin "atrás"). En `hh_title_menu_hook`:
  - **move**: cambia la selección (`0x801CC8C4`).
  - **accept/back**: se ha producido una **transición de pantalla** (`func_800058DC`, contada por
    `hh_goto_hook`, registrado siempre) y se clasifica por el botón (A/START → accept, B → back).
  - Botones: hay **dos** funciones — `func_801C1340` (0x80089E80, direcciones) y `func_801C1334`
    (0x80089E78, A/START); se combinan. Traza `HH_MENU_TRACE=1`.
  - `back` no sonará en el menú de título (es la raíz: B no provoca transición); sí en submenús. El
    control fino se mudará a `hh_menu` (nuestro menú) cuando exista.
