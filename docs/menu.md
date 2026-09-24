# Menú inicial del port (`hh_menu`)

> Documento vivo. **Diseño acordado (2026-09-23)** e implementación del menú inicial propio del port.
> Decisión de base: **ADR 0008** (menú in-game de opciones PC). Técnica del overlay y de la fuente:
> `architecture.md` §7. Evidencia: `../notes/2026-09-23-a2-plan-menu-ajustes-idioma.md`,
> `../notes/2026-09-23-a2-render-hook-y-atlas.md`, `../notes/2026-09-24-a2-*.md`.

## Principios

1. **Imitar el diseño original 1:1** (posiciones, tipografía y **flecha nativa**), **incluyendo menús
   nuevos** (p. ej. `SONIDO` → `AJUSTES`, y dentro `IDIOMA` + `SONIDO`). **Ni panel ni cursor
   inventados**: nada de elementos extra que no existan en el original.
2. **Ocultar el menú nativo** por defecto (el port ya añade menús que no existían). Mecanismo:
   `architecture.md` §7 (supresión por tablas de etiquetas).
3. **Navegación**: arriba/abajo mueve el cursor (la **flecha nativa**); **A** marca/selecciona (entra
   en submenús y fija la opción de una lista); **B** atrás. En los **selectores laterales**,
   izquierda/derecha cambian el valor. **No hay "aplicar" con X**: los cambios son en vivo. Colores:
   las **etiquetas** del menú van en **blanco** (amarillo la del cursor); en las **opciones a
   configurar** (elementos de lista y valores de selector), la activa/aplicada en **verde** y el resto
   en **gris**; las entradas **deshabilitadas** (p. ej. `MODO COMBATE`, por definir) van en **gris**.
4. **Control TOTAL del menú** (no reutilizar el del juego): el overlay moderno **desacopla** el menú
   inicial del juego para tener todo el control (ver §Input).
5. **Sin entradas `ACEPTAR`**: el patrón **A/B** (punto 3) es común a **todas** las pantallas de
   selección. La **guía de botones** (sprites A/B abajo) **se implementa más adelante**.

## Árbol de menús

Orden de arriba a abajo; `->` = con A se entra a esa pantalla. En todas rige **A/B** (A marca/entra,
B atrás):

```
CONTINUAR                                  (arriba del todo: retomar partida directo)
NUEVA PARTIDA ->
      EMPEZAR PARTIDA              (inicia el juego con la config elegida)
      DIFICULTAD -> lista SUPREMO / DIFÍCIL / NORMAL (aplicada en verde, resto gris; A fija)
      CÁMARA LIBRE   NO/SÍ         (selector; izq/der cambia; activo en verde, resto gris)
      APUNTADO LIBRE NO/SÍ         (selector; izq/der cambia)
MODO COMBATE -> (por definir; de momento sale DESHABILITADO, en gris)
AJUSTES ->
      IDIOMA -> lista INGLÉS (arriba) … JAPONÉS (abajo); activa en verde, resto gris
            (los rótulos cambian según el idioma elegido; por defecto, el del sistema)
      GRÁFICOS ->
            RATIO        < AUTO / ORIGINAL / 4:3 / 16:9 / 16:10 / 21:9 >
            RESOLUCIÓN   < AUTO … >    (filtrada por RATIO; AUTO/ORIGINAL + las del ratio)
            P. COMPLETA  NO/SÍ         (pantalla completa)
            ANTIALIASING < x0 / x2 / x4 / x8 >
            VSYNC        NO/SÍ         (por defecto SÍ)
            LÍMITE DE FPS < NATIVO / 30 / 60 / 120 / 144 / 160 >  (NATIVO = refresco del monitor)
      SONIDO -> lista ESTÉREO / MONO (activo en verde, resto gris)
      DEBUG ->
            VENTANA DEBUG  NO/SÍ    (habilita el Inspector de RT64 con F1)
            MOSTRAR FPS    NO/SÍ
```

- **`RESOLUCIÓN` sale de la raíz**: el menú raíz queda en **CONTINUAR / NUEVA PARTIDA / MODO COMBATE /
  AJUSTES** (el `RESOLUTION` nativo se mueve a **GRÁFICOS**).
- **`RATIO` + `RESOLUCIÓN`**: `RATIO` (aspecto) filtra la lista de `RESOLUCIÓN` (las adecuadas a ese
  ratio); la fuente no tiene `:`, así que los ratios se rotulan `4:3`, `16:9`… con el `:` **dibujado
  con rectángulos** (como el chevron). Reglas: `RATIO=ORIGINAL → RESOLUCIÓN=ORIGINAL`,
  `RATIO=AUTO → RESOLUCIÓN=AUTO` y los **ratios concretos → la resolución mínima** de su lista. Por
  defecto `RATIO=AUTO` y `RESOLUCIÓN=AUTO` (la nativa del SO → `[video] res = auto`).
- **`P. COMPLETA`** (pantalla completa, `NO/SÍ`): **por defecto `SÍ`** (la realidad del port es
  `wm = borderless`). `NO` = ventana (`wm = windowed`), `SÍ` = completa (`wm = borderless`). Al cambiar
  el valor se aplica en vivo (`hh::video_set_fullscreen` → `set_graphics_config`), como el atajo F3.
  El `.` también se dibuja (la fuente no lo tiene).
- **`VSYNC`** por defecto **SÍ** (`hh::video_set_vsync` → `swapChain->setVsyncEnabled`, aplicado en el
  hilo de render). **`LÍMITE DE FPS`** por defecto **`NATIVO`** = refresco del monitor (`RefreshRate::
  Display`); un número = tasa fija (`RefreshRate::Manual`, `hh::video_set_fps_limit`). Es el
  `refreshRate` de RT64: interpola hacia la tasa objetivo y la **recorta al refresco del monitor**
  (`swapChainRate`); con `viOriginalRate`=30 del juego, `30` = sin interpolación y `60` = interpolado.
- **Persistencia**: las acciones de `P. COMPLETA` / `VSYNC` / `LÍMITE DE FPS` / `MOSTRAR FPS`
  persisten en `config.ini` `[video]` (`wm` / `vsync` / `fps` / `showfps`) y el menú se inicializa con
  esos valores. El escritor compartido es `hh::config_ini_set` (`include/hh/config_ini.h`), que
  preserva el resto del fichero.
- **`MOSTRAR FPS`**: indicador de **solo números** en la **esquina superior izquierda REAL** de la
  ventana, dibujado por el overlay (`hh::overlay::set_fps_indicator`) como **capa independiente** del
  frame del menú → se ve también en gameplay. Se ancla al framebuffer del swapchain con su propia
  proyección en píxeles (no al área 4:3 centrada del juego). La tasa es la **real de presentación**
  (frames que llegan al swapchain, `hh::overlay::presented_frames`), no la de `update_screen` (tasa VI).
- **`DEBUG`** (submenú): **`VENTANA DEBUG`** (`NO/SÍ`) habilita el modo desarrollador de RT64
  (Inspector con **F1**); **`MOSTRAR FPS`** (`NO/SÍ`). Se sacó de `GRÁFICOS` para no alargarlo.
- **Listas** (IDIOMA, DIFICULTAD, SONIDO): la opción **aplicada** va en **verde** y el resto en **gris**
  (deshabilitado), como en el original; **A** la marca y **B** atrás. El cursor lo marca la flecha nativa.
- **Selectores laterales** (CÁMARA LIBRE, APUNTADO LIBRE, RATIO, RESOLUCIÓN, P. COMPLETA, ANTIALIASING,
  VSYNC, LÍMITE DE FPS, VENTANA DEBUG, MOSTRAR FPS): **el activo en verde** y el resto en gris;
  izquierda/derecha cambian el valor. Todos los **valores empiezan en la misma columna** (los chevrons
  quedan fuera de esa alineación). Los de **pocos valores** se ven juntos (`NO / SÍ`, con **2 px** a
  cada lado de la barra); los **largos** (RESOLUCIÓN, LÍMITE DE FPS) muestran solo el activo entre
  **flechas `<` `>` a 4 px** (`< 800x600 >`). La fuente del menú no tiene `<>/:.`, así que la barra, las
  flechas y los signos `:` `.` se dibujan con rectángulos (como la flecha nativa). Los **dígitos**
  (resoluciones, FPS) se mapean en el atlas (`hh::font::game::glyph_value`).
- **Experiencia moderna**: CÁMARA LIBRE y APUNTADO LIBRE (mejoras jugables fuera del original) viven
  **dentro de NUEVA PARTIDA**, debajo de DIFICULTAD (antes eran un submenú `AJUSTES EXPERIENCIA
  MODERNA`, cuya etiqueta larga se solapaba con los valores). El usuario las configura **antes** de
  pulsar `EMPEZAR PARTIDA`.
- **MODO COMBATE**: por definir; de momento aparece **deshabilitado en gris**.

## Input — DECIDIDO: control total

El overlay moderno **desacopla** el menú inicial del juego: nuestro menú lee el input
(arriba/abajo/izq-der/A/B) y gestiona su **propia pila de pantallas**; el menú nativo se **oculta** y su
input se **neutraliza** (ver `architecture.md` §7). Los botones se leen con los lectores del propio
juego (`func_801C1340` direcciones / `func_801C1334` A/B/START), que el handler nativo ve a 0 mientras
manda el overlay (`feed_menu_navigation`).

## SFX

El SFX del menú se dispara desde los **eventos del modelo** (`move`/`accept`/`back`), no por pulsación
de botón. Hoy hay un **puente** que suena solo en el menú de título (move/accept, por cambio real de
cursor/transición); al completar la navegación propia se retira el puente y `back` sonará donde toque
(la raíz no tiene atrás). Un solo commit.

## Assets de sonido

`assets/sounds/`: `.mp3` (origen) + `.wav` 48 kHz/S16. El build **solo copia los `.wav`** a `sounds/`
junto al `.exe`; **cambiar un `.mp3` NO regenera el `.wav`** → reconvertir con `ffmpeg`
(`-ar 48000 -ac 2 -sample_fmt s16`) y commitear el `.wav`. Nombres que carga `src/platform/menu_sfx.cpp`:
`menu-move.wav`, `menu-accept.wav`, `menu-back.wav`. `test_sounds/` = sonidos antiguos (backup).

## Estado de implementación

| paso | estado |
|---|---|
| 1. Modelo `hh::menu` (estado) | **HECHO** (`include/hh/menu.h` + `src/subsystems/menu.cpp`) |
| 2. Dibujo 1:1 (fuente + flecha nativa) | **HECHO** y **validado en Windows**. Listas con la aplicada en verde y el resto en gris; selectores (valores juntos o `< valor >` con flechas dibujadas); dígitos mapeados (2026-09-24). Falta: acentos reales |
| 3. Ocultar el menú nativo | **HECHO** y **validado en Windows** (los 3 bugs del overlay). Ver `architecture.md` §7 |
| 4. Etiquetas propias + acentos del overlay | pendiente. **Se hace DESPUÉS de completar el menú** (si no, no hay pantalla con tildes que validar) |
| 5. Navegación propia (A/B + selectores, control total) | **HECHO y validado headless** (2026-09-24). `feed_menu_navigation` cubre arriba/abajo/izq-der/A/B (sin X) y el input del handler nativo queda **muteado**. Pendiente validar en Windows |
| 6. Acciones (mapear cada entrada a la función del juego) | parcial: `DEBUG` engancha el modo desarrollador de RT64 (F1) y **`MOSTRAR FPS`** dibuja el indicador; **`P. COMPLETA` / `VSYNC` / `LÍMITE DE FPS`** aplican en vivo y **persisten en `config.ini`** (`[video]`) con los valores iniciales leídos de la config. Falta el resto (pantalla a pantalla) |
| 7. SFX desde eventos del modelo (retirar el puente) | pendiente |
| 8. Validar en Windows | pendiente |

**Orden acordado (2026-09-24):** completar el menú **antes** de los acentos → **5 → 6 → 7 → 4 → 8**.
Así, al integrar los acentos los submenús ya son navegables y se pueden validar (o forzarlos con
`HH_MENU_SCREEN=6` GRÁFICOS / `=5` IDIOMA).

Alcance de la tanda actual: **solo el árbol de menús** (estructura, navegación y dibujo). **NO**
persistir la configuración todavía (los selectores cambian en memoria; el guardado en `config.ini`
queda para después).
