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
      DIFICULTAD -> lista DEFINITIVO / DIFÍCIL / NORMAL (aplicada en verde, resto gris; A fija)
      IDIOMA -> lista ENGLISH/ESPAÑOL/CATALÀ/FRANÇAIS/DEUTSCH/NIHONGO (endónimos; activa en
            verde, resto gris; A fija). Cambia el idioma del MENÚ y del texto in-game; persiste.
      CÁMARA LIBRE   NO/SÍ         (selector; izq/der cambia; activo en verde, resto gris)
      APUNTADO LIBRE NO/SÍ         (selector; izq/der cambia)
MODO COMBATE -> (por definir; de momento sale DESHABILITADO, en gris)
AJUSTES ->
      GRÁFICOS ->
            RATIO        < AUTO / ORIGINAL / 4:3 / 16:9 / 16:10 / 21:9 >
            RESOLUCIÓN   < AUTO … >    (filtrada por RATIO; AUTO/ORIGINAL + las del ratio)
            P. COMPLETA  NO/SÍ         (pantalla completa)
            ANTIALIASING < x0 / x2 / x4 / x8 >
            VSYNC        NO/SÍ         (por defecto SÍ)
            LÍMITE DE FPS < NATIVO / 30 / 40 / 60 / 75 / 90 / 120 / 144 / 165 / 240 >
                          (NATIVO = refresco del monitor)
      SONIDO ->
            VOLUMEN      < 0% … 100% > (pasos de 10; 100% = sin atenuar)
            SALIDA       < MONO / ESTÉREO / AURICULARES > (AURICULARES = crossfeed)
            MENÚ SFX     NO/SÍ (activa/desactiva los sonidos del menú)
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
  defecto `RATIO=AUTO` y `RESOLUCIÓN=AUTO` (la nativa del SO → `[video] res = auto`). Aplican en vivo
  (`hh::video_set_aspect` / `video_set_resolution`) y persisten (`aspect`/`res`); al cambiar `RATIO`
  se re-aplica la `RESOLUCIÓN` resultante del filtro. `res` acepta `auto`/`original`/`2x`/`<n>`/`4k`/
  `8k`/`ANCHOxALTO`.
- **`ANTIALIASING`** (`x0/x2/x4/x8`): MSAA de RT64; por defecto `x8` (el de `[video].msaa`). Aplica en
  vivo (`hh::video_set_msaa` → `set_graphics_config` → `updateMultisampling`) y persiste (`msaa`).
  `res=ANCHOxALTO` usa como multiplicador el mayor de ancho/320 y alto/240, para que cada opción dé un
  paso de escala distinto (antes varias colapsaban al mismo → parecía que "no cambiaba").
- **Widescreen y ratios fijos**: el *snap* de overscan del port (`hh::snap_overscan`) se aplica a los
  aspectos **más anchos que 4:3** (`auto`/`expand` y `16:9`/`16:10`/`21:9`); sin él, `AspectRatio::
  Manual` escalaba el contenido 4:3 al target y salía una **caja pequeña centrada** (bug 2026-09-25).
  `original`/`4:3` dejan el 4:3 nativo (288x224).
- **Ventana `windowed`**: el tamaño inicial sale de la geometría recordada (`win_w/h/x/y`), si no de
  una `res` concreta `ANCHOxALTO`, y si no de la resolución nativa del monitor. Al cerrar se guarda el
  tamaño/posición actual (`hh::video_remember_window`). `P. COMPLETA` sigue siendo independiente.
- **`P. COMPLETA`** (pantalla completa, `NO/SÍ`): **por defecto `SÍ`** (la realidad del port es
  `wm = borderless`). `NO` = ventana (`wm = windowed`), `SÍ` = completa (`wm = borderless`). Al cambiar
  el valor se aplica en vivo (`hh::video_set_fullscreen` → `set_graphics_config`), como el atajo F3.
  El `.` también se dibuja (la fuente no lo tiene).
- **`VSYNC`** por defecto **SÍ** (`hh::video_set_vsync` → `swapChain->setVsyncEnabled`, aplicado en el
  hilo de render). **`LÍMITE DE FPS`** por defecto **`NATIVO`** = refresco del monitor (`RefreshRate::
  Display`); un número = tasa fija (`RefreshRate::Manual`, `hh::video_set_fps_limit`). Es el
  `refreshRate` de RT64: interpola hacia la tasa objetivo y la **recorta al refresco del monitor**
  (`swapChainRate`); con `viOriginalRate`=30 del juego, `30` = sin interpolación y `60` = interpolado.
  Lista: `NATIVO/30/40/60/75/90/120/144/165/240` (40 = Steam Deck; 75 = monitores antiguos). Los
  objetivos que **no** son múltiplos de 30 (40/75/144/165) pueden dar algo de *judder*.
  **Verificar VSYNC**: con `HH_FPS=1` la línea `[hh-fps]` incluye `vsync=<0|1>` (estado real del
  swapchain, `isVsyncEnabled`); al cambiarlo, el log muestra `[hh] vsync=... real=...`.
- **Persistencia**: las acciones de `RATIO` / `RESOLUCIÓN` / `P. COMPLETA` / `ANTIALIASING` / `VSYNC` /
  `LÍMITE DE FPS` / `MOSTRAR FPS` / `VENTANA DEBUG` persisten en `config.ini` `[video]` (`aspect`/
  `res`/`wm`/`msaa`/`vsync`/`fps`/`showfps`/`developer`) y el menú se inicializa con esos valores. El
  escritor compartido es
  `hh::config_ini_set` (`include/hh/config_ini.h`), que preserva el resto del fichero.
- **`MOSTRAR FPS`**: indicador de **solo números** en la **esquina superior izquierda REAL** de la
  ventana, dibujado por el overlay (`hh::overlay::set_fps_indicator`) como **capa independiente** del
  frame del menú → se ve también en gameplay. Se ancla al framebuffer del swapchain con su propia
  proyección en píxeles (no al área 4:3 centrada del juego). La tasa es la **real de presentación**
  (frames que llegan al swapchain, `hh::overlay::presented_frames`), no la de `update_screen` (tasa VI).
- **`DEBUG`** (submenú): **`VENTANA DEBUG`** (`NO/SÍ`) habilita el modo desarrollador de RT64
  (Inspector con **F1**), aplica en vivo (`hh::video_set_developer_mode`) y **persiste** (`developer`);
  **`MOSTRAR FPS`** (`NO/SÍ`), también persistente (`showfps`). Se sacó de `GRÁFICOS` para no alargarlo.
  **F1 en caliente**: en Windows RT64 instala su *hook* de teclado solo al arrancar (si el modo dev ya
  estaba activo); si se activa en caliente, el port detecta que RT64 no lo gestiona
  (`hh::rt64_handles_dev_keys`) y maneja F1 él mismo (`hh::toggle_inspector` →
  `processDeveloperShortcut(Inspector)`).
- **Listas** (IDIOMA, DIFICULTAD): la opción **aplicada** va en **verde** y el resto en **gris**
  (deshabilitado), como en el original; **A** la marca y **B** atrás. El cursor lo marca la flecha nativa.
- **`SONIDO`** (antes lista vanilla ESTÉREO/MONO): ahora `VOLUMEN` (0-100 % en pasos de 10; afecta a
  **todo**: juego, música y SFX) y `SALIDA` (`MONO` / `ESTÉREO` / `AURICULARES`). `MONO` hace downmix
  `(L+R)/2`; `AURICULARES` aplica **crossfeed** (un poco del canal opuesto filtrado en paso-bajo, para
  auriculares). Aplican en vivo en `hh::queue_samples` (`hh_apply_audio_processing`) y persisten en
  `[audio]`. El `%` no está en la fuente: se dibuja con rectángulos (como `:`/`.`). `MENÚ SFX` (`NO/SÍ`)
  silencia/activa los sonidos del menú (`hh::menu_sfx::play` respeta `[audio].menusfx`).
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

## Idiomas y acentos (2026-09-25)

- **Etiquetas localizadas**: las del modelo están en **español (canónico)** y se traducen al idioma
  activo con `hh::menu::localized()` (tabla `kMenuTr`, `src/subsystems/menu.cpp`), que el overlay usa
  al publicar el texto. Idiomas: **en/es/ca/fr/de**. La lista `IDIOMA` muestra **endónimos**
  (`ENGLISH · ESPAÑOL · CATALÀ · FRANÇAIS · DEUTSCH · NIHONGO`) iguales en todos los idiomas.
- **Acentos del menú = letra + marca**: el overlay pinta la **letra base** (color0 8×8, **sin
  deformar**) + una **marca** (agudo, grave, circunflejo, diéresis, virgulilla, cedilla, punto medio)
  dibujada por el propio overlay (`kMarkShapes` en `src/platform/overlay.cpp`) con la **forma que
  dibuja el mantenedor** (`tools/text/menu_marks.py`: plantilla editable → import →
  `include/hh/menu_marks.h`). Evita comprimir mayúsculas. `¿ ¡` se generan girando `? !`.
- **Texto in-game**: los acentos del texto in-game usan la fuente real **8×12 (`color4`)** compuesta
  (`tools/text/build_font.py` → `include/hh/game_font_color4.h`, ES/CA/FR/DE). **Pendiente cablearla**
  (hoy `src/hooks/text_glyphs.cpp` sirve un set 8×8 propio).
- **Idioma del sistema**: sin `[lang]` guardado, se usa el locale del SO (`GetUserDefaultLocaleName`
  en Windows; `LANG`/`LC_*` en Linux) **si es uno de `en/es/ca/fr/de/ja`**; si no, **inglés**.
  Prioridad: `HH_LANG` > `config.ini [lang]` > sistema > `en`.
- **Japonés**: pendiente. `color0` JP tiene **kana** (no kanji); de momento JA cae a inglés en las
  etiquetas del menú. El texto in-game sí soporta EUC-JP (kanji).

## Input — DECIDIDO: control total

El overlay moderno **desacopla** el menú inicial del juego: nuestro menú lee el input
(arriba/abajo/izq-der/A/B) y gestiona su **propia pila de pantallas**; el menú nativo se **oculta** y su
input se **neutraliza** (ver `architecture.md` §7). Los botones se leen con los lectores del propio
juego (`func_801C1340` direcciones / `func_801C1334` A/B/START), que el handler nativo ve a 0 mientras
manda el overlay (`feed_menu_navigation`).

## SFX

El SFX del menú se dispara desde los **eventos del modelo** (`Move`/`Accept`/`Back`), no por pulsación
de botón: en `feed_menu_navigation` se traduce `Event::Move/Accept/Back` a
`hh::menu_sfx::play(Move/Accept/Back)`. Al sonar por evento **no suena si la pulsación no hace nada**
(arriba en la 1.ª entrada, `B` en la raíz, opción gris, o izquierda/derecha donde no hay selector). El
antiguo **puente** (que deducía move/accept del cursor/transición nativos) está **retirado**: con el
input nativo muteado quedaba en silencio y nunca disparaba `back`. Solo suena con el overlay activo
(`HH_OVERLAY=0` deja el menú nativo, que trae su propio sonido).

## Assets de sonido

`assets/sounds/`: `.mp3` (origen) + `.wav` 48 kHz/S16. El build **solo copia los `.wav`** a `sounds/`
junto al `.exe`; **cambiar un `.mp3` NO regenera el `.wav`** → reconvertir con `ffmpeg`
(`-ar 48000 -ac 2 -sample_fmt s16`) y commitear el `.wav`. Nombres que carga `src/platform/menu_sfx.cpp`:
`menu-move.wav`, `menu-accept.wav`, `menu-back.wav`. `test_sounds/` = sonidos antiguos (backup).
**Personalización**: el usuario puede reemplazar los `.wav` de `sounds/` (mismos nombres, **48 kHz /
S16 / estéreo**); si el formato no encaja, se ignora y se avisa en `hh.log`. `MENÚ SFX = NO` los silencia.

## Estado de implementación

| paso | estado |
|---|---|
| 1. Modelo `hh::menu` (estado) | **HECHO** (`include/hh/menu.h` + `src/subsystems/menu.cpp`) |
| 2. Dibujo 1:1 (fuente + flecha nativa) | **HECHO** y **validado en Windows**. Listas con la aplicada en verde y el resto en gris; selectores (valores juntos o `< valor >` con flechas dibujadas); dígitos mapeados (2026-09-24) |
| 3. Ocultar el menú nativo | **HECHO** y **validado en Windows** (los 3 bugs del overlay). Ver `architecture.md` §7 |
| 4. Etiquetas propias + acentos + idiomas | **HECHO (2026-09-25)**: etiquetas localizadas (en/es/ca/fr/de) + acentos por **letra+marca** + `IDIOMA` funcional + **detección del idioma del sistema**. Falta **JA** (kana) y validar en Windows |
| 5. Navegación propia (A/B + selectores, control total) | **HECHO y validado headless** (2026-09-24). `feed_menu_navigation` cubre arriba/abajo/izq-der/A/B (sin X) y el input del handler nativo queda **muteado**. Pendiente validar en Windows |
| 6. Acciones (mapear cada entrada a la función del juego) | parcial: `DEBUG` engancha el modo desarrollador de RT64 (F1) y **`MOSTRAR FPS`** dibuja el indicador; **`RATIO` / `RESOLUCIÓN` / `P. COMPLETA` / `ANTIALIASING` / `VSYNC` / `LÍMITE DE FPS`** aplican en vivo y **persisten en `config.ini`** (`[video]`) con los valores iniciales leídos de la config (+ geometría de ventana). Falta `CÁMARA LIBRE`/`APUNTADO LIBRE`/`EMPEZAR PARTIDA`/`CONTINUAR` |
| 7. SFX desde eventos del modelo (retirar el puente) | **HECHO** (2026-09-25): `Move`/`Accept`/`Back` desde los eventos de `hh::menu`; puente retirado. Falta validar en Windows |
| 8. Validar en Windows | pendiente |

**Orden seguido:** 5 → 6 → 7 → 4 (hechos). **Pendiente: 8 (validar en Windows)**; y el **JA** del menú
(kana). Los submenús se pueden forzar con `HH_MENU_SCREEN=6` GRÁFICOS / `=5` IDIOMA.

La configuración de los selectores ya **persiste** (`config.ini`) y el idioma también (`[lang]`).
Pendiente funcional: `CÁMARA LIBRE`/`APUNTADO LIBRE` (requieren modificar el juego) y
`DIFICULTAD`/`EMPEZAR PARTIDA`/`CONTINUAR` (arrancar/retomar partida con la dificultad interna).
