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

## Menú (`hh_menu`) — diseño ACORDADO (2026-09-23)

> Se intentó antes (`c2ce652`) y **se revirtió**: añadí un **panel de fondo** y una **barra de cursor**
> que **nadie pidió**. Regla: **imitar el original 1:1, sin elementos extra**.

**Principios (confirmados por el mantenedor):**
1. **Imitar el diseño original 1:1** (posiciones, tipografía y **flecha nativa**), **incluyendo menús
   nuevos** (p. ej. `SONIDO` → `AJUSTES`, y dentro `IDIOMA` + `SONIDO`). **Ni panel ni cursor
   inventados**.
2. **Ocultar el menú nativo** (por defecto). El port ya añade menús que no existían; no tiene sentido
   seguir viendo el original debajo.
3. **Navegación**: arriba/abajo mueve la selección; **A** entra/confirma; **B** vuelve atrás. En los
   **selectores**, izquierda/derecha cambian el valor (`< 30 >`, con **flechas amarillas** a los lados).
4. **Control TOTAL del menú** (no reutilizar el del juego): el overlay moderno **desacopla** el menú
   inicial del juego para tener todo el control. Ver §Input.
5. **Guía de botones** (propuesta, a confirmar): en vez de entradas `ACEPTAR`, mostrar abajo
   **sprites de los botones X/A/B** con su función (`X`=Aplicar, `A`=Seleccionar, `B`=Atrás). Casa con
   la guía que el juego ya muestra en la pausa. Aplica sobre todo al selector de resolución (listas
   largas, donde un `ACEPTAR` al final quedaría lejísimos).

**Árbol de menús** (orden de arriba a abajo; `->` = con A se entra a esa pantalla; `A / B / C` = las
entradas de esa pantalla):

```
CONTINUAR                                  (arriba del todo: retomar partida directo)
NUEVA PARTIDA ->
      AJUSTES EXPERIENCIA MODERNA -> (selectores + ACEPTAR; al aceptar vuelve atrás guardando)
      EMPEZAR PARTIDA              (inicia el juego con la config elegida)
      DIFICULTAD -> SUPREMO / DIFÍCIL / NORMAL / ACEPTAR (vuelve atrás guardando)
MODO COMBATE -> (por definir)
AJUSTES ->
      IDIOMA ->
            INGLÉS / ESPAÑOL / CATALÁN / FRANCÉS / ALEMÁN / JAPONÉS
            (los rótulos cambian según el idioma elegido; por defecto, el del sistema)
      GRÁFICOS ->
            RESOLUCIÓN -> lista de TODAS las resoluciones (puede ser larga);
                          A marca la resaltada, X la aplica, B atrás (guía de botones abajo, sin ACEPTAR)
            ANTIALIASING (x0 / x2 / x4 / x8; desactivar las que RT64 inhabilite por resolución)
            VSYNC        (SÍ / NO)
            LÍMITE DE FPS (0 / 30 / 60 / 120 / 144 / 160 …?)
            MOSTRAR FPS  (SÍ / NO)
      SONIDO ->
            ESTÉREO / MONO
```

- **AJUSTES EXPERIENCIA MODERNA**: pensado para futuras mejoras jugables que se salen del original
  (p. ej. cámara libre, apuntado libre). El usuario las configura **antes** de empezar; luego pulsa
  `EMPEZAR PARTIDA` en la pantalla de NUEVA PARTIDA y el flujo del juego continúa normal.
- **MODO COMBATE**: por definir.

## SIGUIENTE TAREA (sesión nueva): implementar `hh_menu` según el diseño de arriba

> **NO inventar nada visual.** Si algo no está en el árbol/diseño, **preguntar**. Confirmar el diseño
> de cada pantalla antes de dibujarla. **1 tema = 1 commit.**

Pasos sugeridos (acordar con el mantenedor antes de cada uno):
1. **Modelo `hh_menu`** (solo estado): entradas `{label, enabled, acción}`, cursor, navegación
   (arriba/abajo/izq-der/confirmar/atrás) y layout. Sin dibujo aún.
2. **Dibujo 1:1 con el original**: entradas con la fuente del juego en las posiciones nativas;
   **flecha nativa** como cursor. **Sin panel ni rectángulos.**
3. **Ocultar el menú nativo**: override del constructor `func_801C18FC` con etiquetas vacías (o
   supresión selectiva del draw de texto), para que el juego no dibuje su menú.
4. **Etiquetas propias**: tabla del port (quita el límite de 15 caracteres de los campos del juego),
   integrada con el sistema de idiomas (A1/B).
5. **Navegación propia**: leer el input y mover el cursor; confirmar/atrás. (Pendiente de decidir de
   dónde se lee: ver §Input abajo.)
6. **Acciones**: mapear cada entrada a la función del juego (nueva partida, continuar, modo combate,
   ajustes, resolución…). Ir pantalla a pantalla.
7. **SFX** desde los eventos del modelo (move/accept/back), retirando el puente actual. **1 commit.**
8. **Validar en Windows.**

### Input — DECIDIDO: control total

El mantenedor quiere **control total**: el overlay moderno **desacopla** el menú inicial del juego.
Nuestro menú lee el input (arriba/abajo/izq-der/A/B/X) y gestiona su **propia pila de pantallas**; el
menú nativo se **oculta** (no se deja correr su handler, o se neutraliza su dibujo).

Fuente concreta de los botones (a decidir en implementación): leer los botones del juego
(`func_801C1340` direcciones, `func_801C1334` A/START) o el input propio del port (`hh::get_input`).
Como es control total, lo natural es **no depender del handler del juego**.

### Estado del SFX (puente)

Hoy el SFX suena **solo en el menú de título** (move/accept), por cambio real (cursor/transición). En
el título **`back` no aplica** (raíz) y los submenús **no están enganchados**. Al implementar `hh_menu`
se disparará desde **sus eventos** (y ahí `back` sonará donde toque), en **un solo commit**.

### Assets de sonido

`assets/sounds/`: `.mp3` (origen) + `.wav` 48 kHz/S16. El build **solo copia los `.wav`** a `sounds/`
junto al `.exe`; **cambiar un `.mp3` NO regenera el `.wav`** → hay que reconvertir con `ffmpeg`
(`-ar 48000 -ac 2 -sample_fmt s16`) y commitear el `.wav`. Nombres cargados por `menu_sfx.cpp`:
`menu-move.wav`, `menu-accept.wav`, `menu-back.wav`. `test_sounds/` = sonidos antiguos (backup).
*(Si se quiere, se puede añadir un paso de build que convierta mp3→wav, pero requiere ffmpeg.)*

### Pendiente adicional

- **Validar B (acentos) en Windows**: la inyección compila ("25 glifos inyectados") pero **no se ha
  visto en pantalla**. Afecta a los rótulos de idioma (ESPAÑOL, CATALÁN, FRANÇAIS…).

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
