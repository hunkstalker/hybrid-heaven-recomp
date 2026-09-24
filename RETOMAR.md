# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-24.**
>
> **A2 Fase A: IMPLEMENTADA y VALIDADA en Windows** — overlay del menú inicial por **render hook de
> RT64** + plume, con el **atlas RGBA8 de la fuente del juego**. Alineación clavada sobre el texto del
> juego. **SFX de menú** (move/accept) mezclados sobre el audio del juego.
> Detalle técnico: **`notes/2026-09-23-a2-render-hook-y-atlas.md`**.
>
> **Sesión 2026-09-24 (inicio de `hh_menu`):** modelo `hh_menu` (árbol + cursor), dibujo 1:1 con la
> fuente del juego y la **flecha nativa**, terreno de navegación con **nuestro** cursor, y **F6
> alterna el menú nativo** (oculto por defecto). **TODO ESTÁ SIN COMMITEAR** (working tree).
>
> ✅ **PROBLEMA RESUELTO (2026-09-24, sesión de continuación): el menú NATIVO del juego ya no se ve
> al entrar al título.** Causa raíz: el juego tiene **DOS tablas de etiquetas idénticas** para el menú
> y el filtro solo cubría una. Ver **§PROBLEMA (resuelto)** justo abajo. **Validado en headless Linux
> con captura**; pendiente la validación visual del mantenedor en Windows.

## ⚠️ Forma de trabajar (leer primero)

- **Recomendar, no ejecutar por iniciativa.** El mantenedor decide. Antes de implementar algo que no
  esté **explícitamente acordado**, preguntar. En esta sesión me adelanté varias veces (implementé el
  SFX cuando se quería diferir; añadí un "panel + cursor" que **nadie había pedido con esas
  características**) y generé varios commits para una misma tarea. **No repetir.**
- **Un tema = un commit.** No trocear una tarea en 3-4 commits.
- **El menú del overlay debe verse COMO EL NATIVO del juego.** Nada de elementos inventados. Si se
  habla de "panel" o "cursor", **confirmar qué significa exactamente** antes de dibujar nada.
- **Rigor al informar (fallo de la sesión 2026-09-24):** distinguir SIEMPRE **"medido"** de
  **"inferido"**, y no afirmar el estado de ejecución sin evidencia. En esta sesión se dijo
  alternativamente "se compone una vez" y "se carga dos veces" mezclando cosas distintas (componer
  texto ≠ cargar el módulo), y se afirmó un timing (~1 s) que **nunca se midió**. **No repetir.**
- No hacer `squash`/reescrituras de historia salvo petición expresa.

## ✅ PROBLEMA RESUELTO (2026-09-24): ocultar el menú NATIVO

**Síntoma original (reportado en Windows):** al entrar al menú de título, el **menú nativo del juego
se veía ~1 s**; F6 lo alternaba pero la primera pulsación no hacía nada (ya visible) y la segunda lo
ocultaba.

**Causa raíz (MEDIDA en headless):** el juego tiene **DOS tablas de etiquetas IDÉNTICAS** para el
menú de título, una por ruta de entrada, y el filtro solo cubría la primera:
- **set A** `0x801CEBB4`: la usa el update **`func_801C18FC`** (al pulsar START).
- **set B** `0x801CEC6C`: la usa **`func_801C1C44`** (segunda entrada / desde el propio título).
Ambas con `idx0` = flecha (gaiji `A1FC`), `idx1..5` = entradas de 16 B, `idx6` = variante
`%p RESOLUTION`; **byte-idénticas** entre sí. El handler **`func_801C1DB8`** re-registra la flecha
`0x801CECFC` cada frame.

En la ruta que reportó el mantenedor se compone el **set B**; como `filter_native_text` solo miraba
`[0x801CEBB4, 0x801CEC14)`, el texto del set B **no se filtraba** y quedaba visible. F6 lo ocultaba
porque fuerza la recomposición del **set A** (con blancos) sobre los mismos slots `0..5`.

**Arreglo (1 commit, `src/hooks/menu_overlay.cpp`):** cubrir **ambos** sets (`7*16` B cada uno:
`idx0..6`) y la flecha en `suppress_native` y `filter_native_text`.

**Evidencia (headless Linux, Xvfb + lavapipe; replay que entra al menú):**
- Antes: `[native] filter first text=801CECFC` (la flecha; el set B nunca se filtraba).
- Después: `[native] filter first text=801CEC6C` (set B) + captura `menu_native_off.png` con **solo
  el overlay del port** (CONTINUAR / NUEVA PARTIDA / MODO COMBATE / AJUSTES) y **sin** el 5.º renglón
  nativo ni duplicados. **Pendiente validar en Windows.**

**Histórico de intentos (se conserva):** (1) blanking de la tabla → no ocultaba (el texto ya
compuesto no se relee de la tabla); (2) forzar el re-registro de `func_801C18FC` → sí pero con
ventana de ~1 s (durante el fade-in el handler no corre); (3) override de `0x8001B204`
(`hh_entry_register_hook` → `filter_native_text`) + `suppress_native` (backup/restore) → base del
arreglo actual; le faltaba el set B.

**Nota:** el headless **sí** llega al menú con un replay adecuado (pulsos de START desde ~t=60 s;
el fichero de la sesión anterior pulsaba demasiado pronto y no llegaba). Ver §Método.

## 🐞 Bugs del overlay (2026-09-24) — RESUELTOS (headless; falta validar en Windows)

1. **"MODO COMBATE" 1 px a la izquierda** → **no era posición**: es el *bearing* del glifo 'M'
   (columna 0; el resto en la 1). Se compensa el primer glifo a la columna 1. Nota
   `notes/2026-09-24-a2-overlay-alineacion-y-cierre.md`.
2. **Al volver atrás de una opción reaparecía el menú NATIVO** → había un **tercer set** de
   etiquetas (`0x801CF110`, `func_801C56B8`, el "atrás" de todos los submenús) que el filtro no
   cubría. Anotado en `notes/2026-09-24-a2-ocultar-menu-nativo-dos-tablas.md`.
3. **El overlay tardaba ~1 s en desaparecer** → el umbral de `tick()` era 30 ticks (~1 s a 30 Hz);
   ahora es **por tiempo** (150 ms). Nota de alineación (misma que el bug 1).

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
- **Menú de título (reescrito en la sesión 2026-09-24)**: `hh_title_menu_hook` (override de
  `0x801C1DB8`) sigue delegando en el original, pero el overlay ya **no** lee el estado nativo:
  publica el frame desde el **modelo `hh::menu`** (`include/hh/menu.h` + `src/subsystems/menu.cpp`) —
  entradas, cursor, **flecha nativa** (6×5) en posiciones nativas, listas en verde. `DEBUG`:
  `HH_MENU_SCREEN=<id>` dibuja una pantalla concreta. `feed_menu_navigation` mueve **nuestro** cursor
  con los botones del juego (A/B/X aún van al handler nativo → paso 6). El menú nativo se intenta
  ocultar (**ver §PROBLEMA ABIERTO**). `src/hooks/menu_overlay.cpp`.
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
- Posiciones nativas en `include/hh/menu.h` (`Layout`: `x = 112.0`, `y0 = 0x76`, `dy = 10`);
  `menu_overlay.cpp` suma +5 px de métrica de fuente. La calibración de `menu_overlay.cpp` es un
  **delta** sobre esa posición nativa (por defecto 0).
- Ajustables en caliente con **Ctrl+flechas / Ctrl+RePág·AvPág / Ctrl+Inicio·Fin** (ver
  `src/subsystems/input.cpp`); escribe `[overlay] calib dx=.. dy=.. sx=.. sy=..` en `hh.log`.
  Entorno: `HH_OVERLAY_X/Y/SX/SY` (delta), `HH_OVERLAY=0` desactiva el overlay del port.
  **F6** muestra/oculta el **menú NATIVO del juego** (oculto por defecto), no el overlay del port.

## Menú (`hh_menu`) — diseño ACORDADO (2026-09-23)

> Se intentó antes (`c2ce652`) y **se revirtió**: añadí un **panel de fondo** y una **barra de cursor**
> que **nadie pidió**. Regla: **imitar el original 1:1, sin elementos extra**.

**Principios (confirmados por el mantenedor):**
1. **Imitar el diseño original 1:1** (posiciones, tipografía y **flecha nativa**), **incluyendo menús
   nuevos** (p. ej. `SONIDO` → `AJUSTES`, y dentro `IDIOMA` + `SONIDO`). **Ni panel ni cursor
   inventados**.
2. **Ocultar el menú nativo** (por defecto). El port ya añade menús que no existían; no tiene sentido
   seguir viendo el original debajo.
3. **Navegación**: arriba/abajo mueve el cursor (la **flecha nativa**); **A** marca/selecciona la
   opción resaltada, **X** aplica (guarda y vuelve atrás), **B** atrás (descarta). En los
   **selectores laterales**, izquierda/derecha cambian el valor (`< 30 >`, con **flechas amarillas** a
   los lados). La **selección resaltada se pinta en verde**.
4. **Control TOTAL del menú** (no reutilizar el del juego): el overlay moderno **desacopla** el menú
   inicial del juego para tener todo el control. Ver §Input.
5. **Sin entradas `ACEPTAR`**: el patrón **A/X/B** (punto 3) es común a **todas** las pantallas de
   selección. La **guía de botones** (sprites X/A/B abajo: `X`=Aplicar, `A`=Seleccionar, `B`=Atrás,
   como la que el juego ya muestra en la pausa) **se implementa más adelante**.

**Árbol de menús** (orden de arriba a abajo; `->` = con A se entra a esa pantalla). En todas las
pantallas rige el patrón **A/X/B** (A marca, X aplica y vuelve, B atrás):

```
CONTINUAR                                  (arriba del todo: retomar partida directo)
NUEVA PARTIDA ->
      AJUSTES EXPERIENCIA MODERNA -> (selectores laterales; A marca, X aplica y vuelve, B atrás)
            CÁMARA LIBRE   < SÍ / NO >      (propuesta; por decidir)
            APUNTADO LIBRE < SÍ / NO >      (propuesta; por decidir)
      EMPEZAR PARTIDA              (inicia el juego con la config elegida)
      DIFICULTAD -> lista SUPREMO / DIFÍCIL / NORMAL (selección en verde; A/X/B)
MODO COMBATE -> (por definir; de momento sale DESHABILITADO, en gris)
AJUSTES ->
      IDIOMA -> lista INGLÉS (arriba) … JAPONÉS (abajo)
            (los rótulos cambian según el idioma elegido; por defecto, el del sistema)
      GRÁFICOS ->
            RESOLUCIÓN -> lista de TODAS las resoluciones (puede ser larga); A/X/B
            ANTIALIASING (x0 / x2 / x4 / x8; desactivar las que RT64 inhabilite por resolución)
            VSYNC        (SÍ / NO)
            LÍMITE DE FPS < 0 / 30 / 60 / 120 / 144 / 160 … >  (selector lateral)
            MOSTRAR FPS  (SÍ / NO)
      SONIDO -> lista ESTÉREO / MONO (selección en verde)
```

- **`RESOLUCIÓN` sale de la raíz**: el menú raíz queda en **CONTINUAR / NUEVA PARTIDA / MODO COMBATE /
  AJUSTES** (el `RESOLUTION` nativo se mueve a **GRÁFICOS**).
- **Listas** (IDIOMA, DIFICULTAD, SONIDO, RESOLUCIÓN): como en el vanilla, la opción activa se
  **resalta en verde**; **A** la marca, **X** aplica y vuelve, **B** atrás.
- **Selectores laterales** (CÁMARA LIBRE, APUNTADO LIBRE, LÍMITE DE FPS): `< valor >` con flechas
  amarillas; izquierda/derecha cambian el valor. El de **LÍMITE DE FPS** aún no tiene lista cerrada
  (se irá probando el diseño).
- **AJUSTES EXPERIENCIA MODERNA**: pensado para futuras mejoras jugables que se salen del original.
  Por ahora las entradas **CÁMARA LIBRE** y **APUNTADO LIBRE** son **propuestas por decidir**. El
  usuario las configura **antes** de empezar; luego pulsa `EMPEZAR PARTIDA` en la pantalla de NUEVA
  PARTIDA y el flujo del juego continúa normal.
- **MODO COMBATE**: por definir; de momento aparece **deshabilitado en gris**.
- **Guía de botones**: se implementa **más adelante**.

## SIGUIENTE TAREA (sesión nueva): implementar `hh_menu` según el diseño de arriba

> **NO inventar nada visual.** El diseño de arriba está **acordado** (2026-09-23); solo quedan
> abiertos **MODO COMBATE** (deshabilitado en gris) y las entradas de **AJUSTES EXPERIENCIA MODERNA**.
> Si algo no está en el árbol/diseño, **preguntar**. **1 tema = 1 commit.**
>
> **Alcance de esta tanda**: solo el **árbol de menús** (estructura, navegación y dibujo). **NO**
> persistir la configuración todavía: los selectores cambian en memoria; el guardado en `config.ini`
> queda para después.

Pasos sugeridos (acordar con el mantenedor antes de cada uno):
1. **Modelo `hh_menu`** (solo estado) — **HECHO** (2026-09-24): `include/hh/menu.h` +
   `src/subsystems/menu.cpp` (árbol, cursor, navegación, `Event` para el SFX, `describe_*`,
   `debug_show`). Sin dibujo.
2. **Dibujo 1:1 con el original** — **HECHO** (sin validar en Windows): `menu_overlay.cpp` dibuja el
   modelo con la fuente y posiciones nativas + **flecha nativa** (triángulo 6x5 extraído del original);
   sin paneles de fondo. Pendiente: acentos reales (hoy se pliegan a ASCII) y valores de los selectores.
3. **Ocultar el menú nativo** — ✅ **RESUELTO** (headless; pendiente validar en Windows). Ver
   §PROBLEMA (resuelto). Arreglo: cubrir las **dos** tablas de etiquetas (`0x801CEBB4` y
   `0x801CEC6C`) en `suppress_native`/`filter_native_text` (`src/hooks/menu_overlay.cpp`). **F6**
   alterna el nativo (override de `func_801C18FC` + forzar el contador `0x3C` a 0 para re-registrar al
   vuelo).
4. **Etiquetas propias**: tabla del port (quita el límite de 15 caracteres de los campos del juego),
   integrada con el sistema de idiomas (A1/B).
5. **Navegación propia**: leer el input y mover el cursor; confirmar/atrás. **Terreno HECHO**:
   `feed_menu_navigation` lee los botones del juego (`func_801C1340`/`func_801C1334`) y mueve **nuestro**
   cursor (arriba/abajo). Pendiente: neutralizar el input del handler nativo y añadir A/B/X + selectores
   (control total). Fuente de input: los botones del juego (ver §Input).
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
- **El headless SÍ llega al menú** con un replay que **no toque nada hasta ~t=60 s** y luego pulse
  START (`0x1000`) cada ~2 s (los pulsos tempranos desvían a otra ruta). Formato `<t> <vis> <btns>
  <x> <y>`; `HH_REPLAY=… HH_REPLAY_PACE=1`. Con eso se midió la causa raíz (dos tablas de etiquetas).
  (El `hh_replay_title_hold.txt` de la sesión anterior pulsaba demasiado pronto y no llegaba.)
- **Inspector de RT64**: `HH_DEVELOPER=1` + **F1**.
- Diagnósticos (a `hh.log`): `HH_MENU_TRACE=1`, `HH_FONT_TRACE=1`, `HH_ACCENTS=0`, `HH_LANG=es`,
  `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`, `HH_MENU_SCREEN`. Atajos: F2 aspecto, F3 ventana, F4 MSAA,
  F5 idioma, **F6 menú nativo** (oculto por defecto).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM de análisis: `/app/baserom.us.z64`
  (Windows: `build\windows\bin\Release\hh.us.z64`).

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git (estado al cerrar esta sesión)

- **`main` local** (SIN push): `HEAD = 2181fab` (2026-09-24). El trabajo de `hh_menu` (modelo +
  dibujo 1:1 + navegación + **menú nativo oculto**, fix de las **dos tablas**) va en **un solo commit**
  `2181fab`; el árbol queda limpio. Sesiones previas: `8265b9d`, `5867de5` (overlay A2), `d6f4afb`
  · `de99550` · `b95c6a4` (SFX). `c2ce652` (hh_menu) y `3aede33` (SFX submenús):
  **REVERTIDOS/eliminados** (no están en el árbol).
- `work/debug/hh_replay_title_hold.txt` (replay auxiliar, **gitignored**). El replay que **sí** llega
  al menú en headless es temporal (pulsos de START desde ~t=60 s); no está versionado.
- **Pendiente inmediato**: **validar en Windows** el commit `2181fab` (menú nativo oculto por defecto
  + F6). Si sale bien, push normal de `main`.
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
