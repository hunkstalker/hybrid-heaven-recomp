# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-23.**
>
> **A2 Fase A: IMPLEMENTADA y VALIDADA en Windows** — overlay del menú inicial por **render hook de
> RT64** + plume, con el **atlas RGBA8 de la fuente del juego**. Alineación clavada sobre el texto del
> juego. **SFX de menú** (move/accept) mezclados sobre el audio del juego.
> Detalle técnico: **`notes/2026-09-23-a2-render-hook-y-atlas.md`**.

## ⚠️ Forma de trabajar (leer primero)

- **Recomendar, no ejecutar por iniciativa.** El mantenedor decide. Antes de implementar algo que no
  esté **explícitamente acordado**, preguntar. En esta sesión me adelanté varias veces (implementé el
  SFX cuando se quería diferir; añadí un "panel + cursor" que **nadie había pedido con esas
  características**) y generé varios commits para una misma tarea. **No repetir.**
- **Un tema = un commit.** No trocear una tarea en 3-4 commits.
- **El menú del overlay debe verse COMO EL NATIVO del juego.** Nada de elementos inventados. Si se
  habla de "panel" o "cursor", **confirmar qué significa exactamente** antes de dibujar nada.
- No hacer `squash`/reescrituras de historia salvo petición expresa.

## Qué hay hecho (A2 Fase A)

- **Render hook de RT64** (`RT64::SetRenderHooks(init, draw, deinit)`) + **plume**: se dibuja sobre el
  framebuffer del swapchain ya compuesto. **OJO**: `SetRenderHooks` va **antes** de `app->setup()`
  (el `init` se llama dentro de `setup`); en `src/platform/rt64_render_context.cpp`.
- **Shaders** `shaders/OverlayVS.hlsl` / `OverlayPS.hlsl` (compilados con DXC vía
  `build_vertex_shader`/`build_pixel_shader`; `CMakeLists.txt` re-declara `DXC*` y añade
  `${CMAKE_BINARY_DIR}`).
- **Atlas de la fuente del juego**: `hh::font::game` (`include/hh/font.h` + `src/subsystems/font.cpp`)
  decodifica la fuente **color0** (fichero Nisitenma 107, 8×8) a un atlas RGBA8 128×32 en host.
  `src/platform/overlay.cpp` lo sube como textura y dibuja paneles (textura 1×1 blanca) + texto.
- **Menú de título**: `hh_title_menu_hook` (override de `0x801C1DB8`, módulo 23) **delega en el
  original** y publica el frame del overlay leyendo el estado real (etiquetas + selección).
  `src/hooks/menu_overlay.cpp`.
- **SFX de menú** (`src/platform/menu_sfx.cpp`): WAV en `assets/sounds/` (solo los `.wav` se copian a
  `sounds/` en la release), mezclados sobre el stream de audio del juego.

### Formato de la fuente (clave)

**2bpp, DOS glifos empaquetados por bloque** (`bloque = valor>>1`, `paridad = valor&1`; PAR → bits 2-3
del nibble, IMPAR → bits 0-1). Dentro del glifo: **nivel 1 = tinta (texto)**, **nivel ≥2 = sombra**
(copia desplazada; el motor la pinta en negro). `font.cpp` (`bake_atlas`) es el decode correcto;
**NO** usar la vista 4bpp de `tools/text/font_dump.py` (es la unión de los dos glifos). Ver
`notes/2026-09-23-b-fuente-formato-y-gaiji.md`.

### Alineación (calibrada, no tocar sin motivo)

- **Proyección uniforme (píxel cuadrado, área 4:3 centrada)**: el texto 2D del juego **no** va estirado
  a 16:9, así que el overlay tampoco. Por eso los glifos van a **`scale = 1.0`** (tamaño nativo).
- Defaults en `src/hooks/menu_overlay.cpp`: `x = 112.0`, `y = 5.0`, `scale_x = scale_y = 1.0`.
- Ajustables en caliente con **Ctrl+flechas / Ctrl+RePág·AvPág / Ctrl+Inicio·Fin** (ver
  `src/subsystems/input.cpp`); escribe `[overlay] calib x=.. y=.. sx=.. sy=..` en `hh.log`.
  Entorno: `HH_OVERLAY_X/Y/SX/SY`. **F6** muestra/oculta el overlay.

## Menú (`hh_menu`) — INTENTADO Y REVERTIDO

Se empezó `hh_menu` (modelo de entradas/cursor + dibujo) en el commit `c2ce652`, **pero se revirtió**
porque añadía un **panel de fondo negro** y una **barra de cursor** que el mantenedor **no había
pedido** (el acuerdo es que el menú se vea **como el nativo**). El estado actual (`b95c6a4`) **no**
tiene `hh_menu`; el overlay dibuja solo las entradas, como se validó.

**Lección**: no inventar elementos visuales. Cuando se retome `hh_menu`, **definir con el mantenedor**
qué es "panel" y "cursor" (probablemente: el menú tal cual el nativo, con la flecha del juego).

## SIGUIENTE TAREA (sesión nueva)

1. **Retomar `hh_menu` CON el mantenedor**, confirmando antes el diseño visual (nativo). Objetivos:
   navegación/acciones propias, etiquetas propias (quitar el límite de 15 caracteres de los campos del
   juego) y **suprimir el texto nativo** (que ya no se dibuje debajo).
2. **Migrar el SFX** a los eventos del modelo (`hh_menu`), retirando el puente actual. Hoy el SFX solo
   suena en el **menú de título** (move/accept); **`back` no suena** en el título (es la raíz) y
   **tampoco en submenús** (se intentó engancharlos y se revirtió con `c2ce652`/`3aede33`).
   El mantenedor prefiere **integrar el audio en 1 solo commit** al migrar a `hh_menu`.
3. **Validar B (acentos) en Windows**: la inyección compila ("25 glifos inyectados") pero **no se ha
   visto en pantalla**.

## Método

- **Validación visual en Windows** (el headless Linux llega al menú de forma **intermitente sin
  input**). Captura headless: `Xvfb :99`, `DISPLAY=:99 SDL_VIDEODRIVER=x11
  VK_ICD_FILENAMES=…/lvp_icd.x86_64.json`, `DISPLAY=:99 import -window root out.png`.
- **Inspector de RT64**: `HH_DEVELOPER=1` + **F1**.
- Diagnósticos (a `hh.log`): `HH_MENU_TRACE=1`, `HH_FONT_TRACE=1`, `HH_ACCENTS=0`, `HH_LANG=es`,
  `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`. Atajos: F2 aspecto, F3 ventana, F4 MSAA, F5 idioma, F6 overlay.
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM de análisis: `/app/baserom.us.z64`
  (Windows: `build\windows\bin\Release\hh.us.z64`).

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git (estado al cerrar esta sesión)

- **`main` local** (SIN push): `HEAD = b95c6a4`. Commits de esta sesión (2.ª):
  - `5867de5 feat(a2): overlay del menu inicial por render hook de RT64 + fuente del juego`
  - `d6f4afb feat(a2): SFX del menu ...` · `de99550 fix(a2): ... func_801C1334` ·
    `b95c6a4 fix(a2): SFX del menu por cambio real (cursor/transicion)`
  - `c2ce652` (hh_menu) y `3aede33` (SFX submenús): **REVERTIDOS/eliminados** (no están en el árbol).
- **`origin/main` = `c977bd5` (v0.4.0)**. Locales sin push previos: `ac4a89f` (traducción/idiomas),
  el arreglo del pin de rt64, `22e3eed` (ratón).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70` (gitlink correcto). **`N64ModernRuntime` /
  `N64Recomp`**: en sync.
- Push normal pendiente de `main` (`git -C hybrid-heaven-recomp push origin main`; el repo principal
  requiere `--force-with-lease`, ver AGENTS.md §Push).
- Tags publicados: `v0.1.x`, `v0.2.0`, `v0.3.0`, **`v0.4.0`**. Próximo: `v0.4.1`.

## Contexto (notas)

`notes/2026-09-23-a2-render-hook-y-atlas.md` (**A2: render hook + atlas + SFX**, principal),
`notes/2026-09-23-a2-overlay-primer-paso.md` (intento GBI fallido + decisión de vía),
`notes/2026-09-23-b-fuente-formato-y-gaiji.md` (fuente/gaiji),
`-b-motor-texto-localizado.md`, `-b-fuente-localizacion.md`, `-texto-euc-jp-y-glifos-pal.md`,
`-a2-plan-menu-ajustes-idioma.md`, `-a1-sistema-idiomas-y-cambio-en-vivo.md`,
`-spike-traduccion-charset-y-sustitucion.md`, `-input-raton-y-panel-rt64.md`. Ver **`TODO.md`** §Ahora.
