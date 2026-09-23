# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-23.**
>
> **A2 (overlay) — Fase A IMPLEMENTADA y VALIDADA en Windows** (render hook RT64 + plume, shaders,
> atlas RGBA8 de la fuente del juego, hook del menú de título; reacciona al cursor del juego).
> Offset por defecto ya ajustado. Ver `notes/2026-09-23-a2-render-hook-y-atlas.md` y §SIGUIENTE TAREA.

## A2 — CAMBIO DE VÍA (2026-09-23): overlay por RENDER HOOK de RT64 (no por GBI)

**Decisión de esta sesión**: el overlay de A2 se dibuja con el **render hook de RT64**
(`RT64::SetRenderHooks(init, draw, deinit)`, `lib/rt64/src/rhi/rt64_render_hooks.h`), que entrega el
**command list de plume** y el **framebuffer del swapchain** al final del frame. Es la vía que usan
**Goemon** (RmlUi + plume) y **recompui** (RecompFrontend, oficial). `recompui = render hook + RmlUi
encima`; el render hook es la base de ambas.

- **Por qué NO por GBI**: se intentó primero inyectando GBI (`G_EX_TEXRECT_V1`) en la display list del
  juego (patrón `hud_rewrite`). El overlay **se ejecuta y genera draw calls correctos**, e incluso
  **se ve al arrancar** (KONAMI logo), pero **desaparece** el resto del tiempo: RT64 **no presenta**
  el framebuffer del juego tal cual, lo **compone** (VI renderer) sobre el swapchain. Los draws GBI
  caían en un framebuffer de juego (`0x3B5000`/`0x3DA800`/`0x38F800`) y no en el presentado. El texto
  del menú del juego, de hecho, vive en **`0x600000`** (confirmado con el Inspector). **Ese intento se
  ha RETIRADO del árbol** (ver §Fallos para no repetirlos).
- **Ámbito A2**: **solo el menú inicial** (NUEVA PARTIDA/CONTINUAR/MODO LUCHA/AJUSTES/RESOLUCION). El
  **menú de pausa NO**.
- **Fuente**: se usa la **fuente original del juego** como atlas (estilo clavado); la arquitectura
  debe permitir **cambiar a una TTF moderna** en el futuro, **seleccionable desde el propio menú**.
  `hh_font` con backend intercambiable (`backend_game` hoy / `backend_modern` futuro).
- **B (fuente/acentos) NO es trabajo perdido**: dio el **formato y los bitmaps** de la fuente del
  juego, que alimentan el atlas del overlay (ahora hay que exportarla a **RGBA8** para la textura).

**Arquitectura objetivo**: `hh_menu` (entradas/cursor/acciones) → `hh_font`
(`draw_text(x,y,text,color)`) → backend de atlas; y el dibujo por **render hook + plume** encima del
frame del juego.

### A2 tiene DOS fases: A (base) y B (mejora)

- **Fase A (base, a hacer YA)**: render hook de RT64 + **plume** propio. Dibujamos nosotros los quads
  (texto del atlas del juego, panel, cursor). Control total, sin dependencias nuevas. Cubre el A2
  "imitando al juego" con la fuente original.
- **Fase B (mejora, DESPUÉS de A)**: **`recompui` (RecompFrontend) sobre RmlUi**, la API **oficial**
  de UI de N64Recomp. Da UI tipo HTML/CSS, **layout**, **TTF**, componentes (listas, sliders…), y es
  lo que usan **Goemon** y **Zelda64Recomp**. **Reutiliza el MISMO render hook**: RmlUi no dibuja por
  GBI, dibuja construyendo command lists de plume que se presentan en el hook. Es decir,
  `Fase B = Fase A + RmlUi encima`. Por eso A no es un atajo desechable: es el cimiento de B.
  - **Qué hace falta para B**: traer `N64Recomp/RecompFrontend` (`recompui`) + **RmlUi**; implementar
    la `RmlRenderInterface` (referencia: `/app/goemon-sourcecode/src/ui/ui_renderer.cpp`, clase
    `RmlRenderInterface_RT64_impl`, MIT); shaders `InterfaceVS/PS.hlsl`; cablear estado/eventos/input
    de RmlUi; y cargar el documento (menú) en `hh_menu`.
  - **Cuándo**: solo si el mantenedor quiere la UI moderna completa. Para el A2 mínimo (menú estilo
    juego con la fuente del juego) basta la Fase A.

> OJO con la ambigüedad: en este proyecto **"B" también es la tarea de fuente/acentos** (sección
> §B más abajo). Aquí "Fase B de A2" = la mejora a recompui/RmlUi; son cosas distintas.

### Terminología clave (LEER)

1. **Motor de TEXTO del juego**: la rutina que dibuja caracteres. Se ha **descodificado** (formato de
   fuente, mapeo). Del overlay se reutiliza **su fuente** (como atlas), no su código.
2. **Menú del JUEGO**: las pantallas nativas. **NO se reutiliza ni parchea** (los *overrides* de menú
   quedan **DESACTIVADOS** en `sections.cpp`). El menú lo construye el port.

Frase-resumen: **"reutilizar la fuente del juego, NO el menú del juego"**.

## Fallos del intento GBI (para no repetirlos) y REGLA

Documentado en **`notes/2026-09-23-a2-overlay-primer-paso.md`**. Resumen:

- `G_TEXRECT`/`G_EX_TEXRECT_V1` usan **cuartos de píxel** (10.2 fijo), no píxeles (nos salía a 1/4).
- El **cycle type del othermode va en la palabra H** (bits 20-21), no en L (el `G_FILLRECT` no era
  `G_CYC_FILL`).
- **No usar `0x400000..0x7A0000` para scratch**: son framebuffers del juego (el menú vive en
  `0x600000`). El scratch del HUD va en `0x7A0000/0x7C8000`.
- La UI GBI acaba en un framebuffer de juego, no en el swapchain presentado → **invisible**.

**REGLA (mantenedor, 2026-09-23)**: **no dejar restos de código de pruebas** en el árbol. Los
diagnósticos se hacen con variables de entorno y **se retiran al cerrar la tarea**; nada de código
muerto ni experimentos abandonados. Validar **visualmente en Windows** y con el **Inspector de RT64**
(`HH_DEVELOPER=1` + F1).

## SIGUIENTE TAREA (sesión nueva): alinear/validar el overlay A2 en Windows

> **Estado 2026-09-23 (2.ª sesión): Fase A IMPLEMENTADA; VALIDADA en Windows.** Render hook + plume,
> shaders, atlas RGBA8 de la fuente del juego y hook del menú de título (`0x801C1DB8`) funcionando.
> El overlay reacciona al cursor del juego (resalta la entrada seleccionada). Offset por defecto
> ajustado a lo medido (`+120.75`, `+4` virtual). **"Duplicado" del texto = sombra del glifo 2bpp
> (corregido: nivel 1 = texto, nivel ≥2 = sombra negra).** Escala X/Y tunable (`HH_OVERLAY_SX/SY`).
> Detalle completo: **`notes/2026-09-23-a2-render-hook-y-atlas.md`**.

1. **Pulir alineación** (si hace falta): `HH_OVERLAY_X` / `HH_OVERLAY_Y` (unidades virtuales 320×240).
   **F6** muestra/oculta el overlay. Sale **duplicado** (juego + overlay): es lo esperado hasta el paso 2.
2. **Suprimir el texto del juego** una vez alineado: override del constructor `func_801C18FC`
   registrando etiquetas vacías, o supresión selectiva del draw de texto.
3. **`hh_menu`**: cursor/navegación/acciones propias; después `backend_modern` (TTF) o migrar a
   recompui/RmlUi (Fase B).

### Lo ya hecho (referencia de ficheros)

- `shaders/OverlayVS.hlsl`, `shaders/OverlayPS.hlsl`; `CMakeLists.txt` (DXC + `${CMAKE_BINARY_DIR}`).
- `include/hh/overlay.h`, `src/platform/overlay.cpp` (render hook, atlas, paneles/texto, `publish`).
- `src/hooks/menu_overlay.cpp` (lee etiquetas/selección, publica; F6 en `input.cpp`).
- `src/hooks/sections.cpp`: `hh_title_menu_hook` + re-registro tras cada carga de módulo.
- `src/platform/menu_sfx.cpp`: SFX de menú (move/accept/back) mezclados sobre el audio del juego;
  WAV en `assets/sounds/` (solo los `.wav` van a `sounds/` en la release). Disparo por flancos de
  botón en `hh_title_menu_hook`.
- **OJO**: `SetRenderHooks` va **antes** de `app->setup()` (no después; el handoff anterior lo decía
  mal — el `init` se llama dentro de `setup`).

## B — fuente del juego: descodificada (cerrado)

Detalle completo en **`notes/2026-09-23-b-fuente-formato-y-gaiji.md`**.

- **No es una textura**: son **6 ficheros de bitmap por glifo** (Nisitenma US `106-111` / EU
  `115-120`), uno por color/estilo. `func_8001BFE4` carga el bloque de `stride` bytes en el buffer de
  trabajo `0x801077E0`; `func_8001C0B0` lo compone en la textura `0x800F51C0`.
- **Formato**: **2bpp**, `W×H`; cada bloque contiene **DOS glifos empaquetados**:
  **valor PAR → bits 2-3** de cada nibble (0xCC); **valor IMPAR → bits 0-1** (0x33). `slot = valor>>1`.
- Tamaños: color0 8×8 (stride 32, fichero 107), color1 10×10 (50), color2 10×12 (60), color3 12×13
  (78), color4 8×12 (48), color5 12×13 (78). `tblA` en `0x80044624`; `tblB` (fichero por color) en
  `0x8004462C`. **El menú inicial usa color0 → fichero 107 (8×8)**.
- **Mapeo ASCII→EUC** en `0x80044548` (96 entradas de 2 B: `'0'→A3B0`, `'A'→A3C1`, `'a'→A3E1`…).
  `func_8001D394(color, código)->valor`; `func_8001BD20` = ancho.
- PAL vs US: **5 de 6 ficheros byte-idénticos**; la PAL solo añade 32 glifos acentuados al color4.

### Herramientas y código de B (añadidos esta sesión)

- `tools/text/font_dump.py` — extrae las 6 fuentes y escribe hojas de contacto PNG (`work/fonts/`).
- `tools/text/gen_accent_glyphs.py` — compone glifos acentuados (letra base + acento, 2bpp 8×8) y
  emite `include/hh/accent_glyphs.h` (25 glifos: á é í ó ú ü ñ ç à è ê â ä ö ß Á É Í Ó Ú Ü Ñ Ç ¿ ¡).
  Previsualización: `python3 tools/text/gen_accent_glyphs.py --preview <png>`.
- `HH_FONT_TRACE=1` (`src/hooks/sections.cpp`): loguea `[font] d394 color=.. code=.. -> valor` y
  `[font] bfe4 color=.. code=.. slot=.. stride=.. fileidx=..` → fija mapping y estilo/pantalla.
- `src/hooks/text_glyphs.cpp`: **inyección** (override de `func_8001D394`/`func_8001BFE4`) de los
  glifos acentuados; activa por defecto (`HH_ACCENTS=0` la desactiva). `src/subsystems/text.cpp`
  convierte **UTF-8 → códigos EUC propios** (2 B) al traducir.
- `assets/lang/es.txt` / tabla embebida: `RESOLUTION=RESOLUCIÓN` (prueba de acento), `SOUND=AJUSTES`.

**Pendiente de validar**: la inyección compila y registra ("25 glifos inyectados"), pero **no se ha
visto en pantalla** (headless llega al menú de forma intermitente sin input). Validar en Windows o
con captura headless fiable.

## Método

- **Validación visual en Windows**; el headless Linux llega al menú de forma **intermitente sin
  input**. Captura headless: `Xvfb :99`, `DISPLAY=:99 SDL_VIDEODRIVER=x11
  VK_ICD_FILENAMES=…/lvp_icd.x86_64.json`, y `DISPLAY=:99 import -window root out.png`.
- **Inspector de RT64** para draw calls/framebuffers: `HH_DEVELOPER=1` + **F1**.
- Diagnósticos: `HH_LANG=es`, `HH_FONT_TRACE=1`, `HH_ACCENTS=0`, `HH_MENU_TRACE=1`, `HH_MENUTRACE=1`,
  `HH_DUMP_RDRAM_AT=<seg>`, `HH_TEXT_TRACE=1`. Trazas a `hh.log`.
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso explícito. ROM por defecto para análisis:
  `/app/baserom.us.z64` (contenedor) — en Windows, `build\windows\bin\Release\hh.us.z64`.

## Estado (ya cerrado)

- **Input de ratón vs panel de RT64 (2026-09-23, VALIDADO en Windows)**: con el Inspector abierto
  (`HH_DEVELOPER=1`+F1) el clic se colaba al juego (L→A). `hh::dev_panel_open()` (publicado en
  `update_screen`) desactiva el mapeo ratón→A/B **solo mientras el panel está abierto**. Commit
  `22e3eed`; nota `notes/2026-09-23-input-raton-y-panel-rt64.md`.
- **High frame rate por defecto (v0.4.0)**: `PresentEarly` + `Refresh Rate = Display` (~109 fps;
  lógica a 30 Hz). Revertir: `HH_REFRESH_RATE=original` / `HH_PRESENT_EARLY=0`.
- **Atajos**: **F2** aspecto, **F3** ventana, **F4** MSAA; **F1** = Inspector (con `HH_DEVELOPER=1`).
  Diagnóstico: `HH_FPS=1`, `HH_GRAPHICS_API`.
- **Traducción A1** operativa (`text.cpp`): lista `en/es/ca/fr/de/ja` + mods, cambio en vivo (F5),
  persistencia `config.ini [lang]`.

## Pendiente inmediato (mantenedor)

- **`v0.4.0` publicado** (tag en `origin`, commit `c977bd5`); gitlink de `lib/rt64` → fork `a8f0a70`.
  **No borrar/re-tag.**
- **Defecto conocido de v0.4.0** (corregido en `main`): su `build_windows.bat` clonaba de upstream si
  no se inicializaban submódulos. Publicar **`v0.4.1`** cuando toque.
- Push normal pendiente de `main` (incluye el arreglo del script y el fix del ratón):
  ```powershell
  git -C hybrid-heaven-recomp push origin main
  ```
  (el repo principal requiere `--force-with-lease`; ver AGENTS.md §Push.)

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git (estado de ESTA sesión)

- **Commit de la 1.ª sesión**: `22e3eed fix(input): no mapear raton a botones con el Inspector de RT64
  abierto` (validado en Windows).
- **2.ª sesión (2026-09-23), SIN COMMITEAR — A2 Fase A**:
  - Nuevos: `shaders/OverlayVS.hlsl`, `shaders/OverlayPS.hlsl`, `include/hh/overlay.h`,
    `src/platform/overlay.cpp`, `src/hooks/menu_overlay.cpp`,
    `notes/2026-09-23-a2-render-hook-y-atlas.md`.
  - Modificados: `CMakeLists.txt` (shaders + overlay.cpp + `${CMAKE_BINARY_DIR}`),
    `src/platform/rt64_render_context.cpp` (registro del hook + `tick`), `src/hooks/sections.cpp`
    (hook `0x801C1DB8` + re-registro), `src/subsystems/input.cpp` (F6), `include/hh.h`.
  - **Validado headless**; **pendiente validar/alinear en Windows** (ver SIGUIENTE TAREA).
- **A2 por GBI: RETIRADO del árbol** (1.ª sesión): hallazgos en
  `notes/2026-09-23-a2-overlay-primer-paso.md`.
- **A2 Fase A — base (1.ª sesión)**: `include/hh/font.h` + `src/subsystems/font.cpp` (decoder
  ROM→RGBA8, sin GBI). Ahora consumido por `overlay.cpp`.
- **Sin commitear (tarea B)**: `CMakeLists.txt` (`src/hooks/text_glyphs.cpp`), `assets/lang/es.txt`,
  `src/hooks/sections.cpp`, `src/subsystems/text.cpp`; nuevos `include/hh/accent_glyphs.h`,
  `src/hooks/text_glyphs.cpp`, `tools/text/font_dump.py`, `tools/text/gen_accent_glyphs.py`,
  `notes/2026-09-23-b-fuente-formato-y-gaiji.md`. **Pendiente validar B en Windows.**
- **Docs vivas sin commitear**: `RETOMAR.md`, `TODO.md`, `PROYECTO.md`, `docs/INDEX.md`.
- **`main`**: `origin/main` = `c977bd5` (v0.4.0). Locales sin push: `ac4a89f` (traducción/idiomas),
  el arreglo del pin de rt64 y `22e3eed` (ratón).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70` (gitlink correcto; árbol limpio).
- **`N64ModernRuntime` / `N64Recomp`**: en sync.
- Tags publicados: `v0.1.x`, `v0.2.0`, `v0.3.0`, **`v0.4.0`**. Próximo: `v0.4.1`.

## Contexto

`notes/2026-09-23-a2-render-hook-y-atlas.md` (**A2 Fase A implementada: render hook + atlas**),
`notes/2026-09-23-a2-overlay-primer-paso.md` (A2: intento GBI fallido + decisión de vía),
`notes/2026-09-23-b-fuente-formato-y-gaiji.md` (fuente/gaiji, **principal**),
`-b-motor-texto-localizado.md`, `-b-fuente-localizacion.md`, `-texto-euc-jp-y-glifos-pal.md`,
`-a2-plan-menu-ajustes-idioma.md`, `-a1-sistema-idiomas-y-cambio-en-vivo.md`,
`-spike-traduccion-charset-y-sustitucion.md`, `-input-raton-y-panel-rt64.md`. Ver **`TODO.md`** §Ahora.
