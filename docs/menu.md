# Menú inicial del port (`hh_menu`)

> Documento vivo. **Diseño acordado (2026-09-23)** e implementación del menú inicial propio del port.
> Decisión de base: **ADR 0008** (menú in-game de opciones PC). Técnica del overlay y de la fuente:
> `architecture.md` §7. Evidencia: `../notes/2026-09-23-a2-plan-menu-ajustes-idioma.md`,
> `../notes/2026-09-23-a2-render-hook-y-atlas.md`, `../notes/2026-09-24-a2-*.md`.

## Principios

1. **Imitar el diseño original 1:1** (posiciones, tipografía y **flecha nativa**), **incluyendo menús
   nuevos** (p. ej. `SONIDO` → `CONFIGURACIÓN`, y dentro `IDIOMA` + `SONIDO`). **Ni panel ni cursor
   inventados**: nada de elementos extra que no existan en el original. **Única excepción acordada:
   `SALIR`** en la raíz, debajo de `CONFIGURACIÓN` (decisión del mantenedor, 2026-09-25; ver §SALIR).
2. **Ocultar el menú nativo** por defecto (el port ya añade menús que no existían). Mecanismo:
   `architecture.md` §7 (supresión por tablas de etiquetas).
3. **Navegación**: arriba/abajo mueve el cursor (la **flecha nativa**); **A** marca/selecciona (entra
   en submenús y fija la opción de una lista); **B** atrás. En los **selectores laterales**,
   izquierda/derecha cambian el valor. **No hay "aplicar" con X**: los cambios son en vivo. Colores:
   las **etiquetas** del menú van en **blanco** (amarillo la del cursor); en las **opciones a
   configurar** (elementos de lista y valores de selector), la activa/aplicada en **verde** y el resto
   en **gris**; las entradas **deshabilitadas** (`enabled=false`) van en **gris** (etiqueta y valor) y el
   cursor no se posa en ellas. Hoy no hay ninguna deshabilitada, pero el mecanismo se conserva.
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
      (CÁMARA LIBRE / APUNTADO LIBRE: OCULTOS por ahora, 2026-09-27; ver §Experiencia moderna)
MODO COMBATE -> (recreado con nuestro menu; acciones nativas por cursor; ver §MODO COMBATE)
      MODO VS              (nativo: cursor 0)
      COMBATE DE CRIATURAS -> (nativo: cursor 1)
            5 COMBATES     (nativo: cursor 0)
            SUPERVIVENCIA  (nativo: cursor 1)
      EDITAR DATOS         (nativo: cursor 2)
      (sin SALIR: se sale con B, que dispara el EXIT nativo = cursor 3)
CONFIGURACIÓN ->
      IDIOMA -> lista ENGLISH/ESPAÑOL/CATALÀ/FRANÇAIS/DEUTSCH/NIHONGO (endónimos; activa en
            verde, resto gris; A fija). Cambia el idioma del MENÚ y del texto in-game; persiste.
      GRÁFICOS ->
            RATIO        < AUTO / ORIGINAL / 4:3 / 16:9 / 16:10 / 21:9 >
            RESOLUCIÓN   < AUTO … >    (filtrada por RATIO; AUTO/ORIGINAL + las del ratio)
            P. COMPLETA  NO/SÍ         (pantalla completa)
            ANTIALIASING < x2 >        (stepper; valores x0/x2/x4/x8)
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
EXTRAS ->                                  (desbloqueable con el código Konami / MANTENER EXTRAS; §EXTRAS)
      MODO HEAVEN        NO/SÍ             (modo global persistente: ATRIBUTOS/ESTADO 99 + 86 hab. +
                                            invulnerabilidad + items no consumibles + PODER/RESIS. ∞)
      MANTENER EXTRAS    NO/SÍ
      LOGOS ORIGINALES   NO/SÍ
      EDICIÓN DE PARTIDA -> …              (editor de saves; ver §EDICIÓN DE PARTIDA)
      VENTAJA            NO/SÍ             (ventaja de combate / back attack)
      PODER ∞            NO/SÍ             (el PODER de combate no se gasta)
      RESISTENCIA ∞      NO/SÍ             (la RESISTENCIA de combate no se gasta)
SALIR                                      (extra del port: cierra de forma ordenada; ver §SALIR)
```

- **`RESOLUCIÓN` sale de la raíz**: el menú raíz queda en **CONTINUAR / NUEVA PARTIDA / MODO COMBATE /
  CONFIGURACIÓN / SALIR** (el `RESOLUTION` nativo se mueve a **GRÁFICOS**; `SALIR` es el extra del port,
  ver §SALIR).
- **`RATIO` + `RESOLUCIÓN`**: `RATIO` (aspecto) filtra la lista de `RESOLUCIÓN` (las adecuadas a ese
  ratio); la fuente no tiene `:`, así que los ratios se rotulan `4:3`, `16:9`… con el `:` **dibujado
  con rectángulos** (como el chevron). Reglas: `RATIO=ORIGINAL → RESOLUCIÓN=ORIGINAL`,
  `RATIO=AUTO → RESOLUCIÓN=AUTO` y los **ratios concretos → la resolución mínima** de su lista. Por
  defecto `RATIO=AUTO` y `RESOLUCIÓN=AUTO` (la nativa del SO → `[video] res = auto`). Aplican en vivo
  (`hh::video_set_aspect` / `video_set_resolution`) y persisten (`aspect`/`res`); al cambiar `RATIO`
  se re-aplica la `RESOLUCIÓN` resultante del filtro. `res` acepta `auto`/`original`/`2x`/`<n>`/`4k`/
  `8k`/`ANCHOxALTO`.
- **`ANTIALIASING`** (`x0/x2/x4/x8`, MSAA de RT64; por defecto `x8` = `[video].msaa`): se muestra como
  **stepper** `< x2 >` (solo el activo, con chevrons) aunque sus 4 valores quepan enteros, gracias al
  flag `Entry::stepper` (ver §Selectores laterales). Aplica en vivo (`hh::video_set_msaa` →
  `set_graphics_config` → `updateMultisampling`) y persiste (`msaa`).
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
  cada lado de la barra); los **largos** (RESOLUCIÓN, LÍMITE DE FPS) y los marcados con
  **`Entry::stepper`** (ANTIALIASING) muestran solo el activo entre **flechas `<` `>` a 4 px**
  (`< x2 >`). La fuente del menú no tiene `<>/:.`, así que la barra, las
  flechas y los signos `:` `.` se dibujan con rectángulos (como la flecha nativa). Los **dígitos**
  (resoluciones, FPS) se mapean en el atlas (`hh::font::game::glyph_value`).
- **Experiencia moderna**: CÁMARA LIBRE y APUNTADO LIBRE (mejoras jugables fuera del original) vivían
  **dentro de NUEVA PARTIDA**, debajo de DIFICULTAD (antes eran un submenú `AJUSTES EXPERIENCIA
  MODERNA`, cuya etiqueta larga se solapaba con los valores). El usuario las configura **antes** de
  pulsar `EMPEZAR PARTIDA`.
  **OCULTAS (2026-09-27)**: requieren modificar el juego, así que por ahora **no se muestran** en el
  menú. Se reactivarán cuando el juego soporte cámara/apuntado libres (ver `TODO.md`). El mecanismo de
  entradas deshabilitadas (`enabled=false` + salto en `move_up`/`move_down`) se conserva por si se
  deshabilitan otras.
- **MODO COMBATE**: **habilitado (2026-09-27)** y **recreado con nuestro menú** (mismos rótulos que
  el original, traducidos a en/ca/fr/de): `MODO VS` / `COMBATE DE CRIATURAS` / `EDITAR DATOS`. **No
  hay entrada `SALIR`**: se sale con **B** (atrás), que dispara el `EXIT` nativo (cursor 3).
  Navegación propia y **despacho nativo cableado**: al confirmar una entrada, el overlay fija el
  **cursor de batalla** (`0x801CC8C8`, `0..3`) y reenvía **A** al submenú nativo (`func_801C4200`),
  igual que `sel`+A en la raíz. El overlay dibuja la subpantalla con sus rótulos traducidos
  (etiquetas/flecha nativas suprimidas).
- **`COMBATE DE CRIATURAS`** (pantalla interna): recreada con nuestro menú, con las dos opciones del
  original `5 COMBATES` (`5 MATCHES`) y `SUPERVIVENCIA` (`SURVIVAL`). Mismo patrón: hook de
  `func_801C44C4`, **cursor** `0x801CC8C8` (`0..1`) + A inyectada; **B vuelve a la raíz** (el original
  va directo al título, no al submenú de batalla).
- **Validado en Windows (2026-09-27)**: `MODO COMBATE` y `COMBATE DE CRIATURAS` (5 COMBATES /
  SUPERVIVENCIA) con su despacho nativo. **`MODO VS` no validado**: el port solo reporta el **puerto
  0** de mando, así que no se detecta un **2.º mando** (¿o 2.º Controller Pak?) — backlog `TODO.md`.
  `EDITAR DATOS` sigue siendo el flujo nativo (no tiene pantalla de opciones propia).
  Detalle: `../notes/2026-09-27-battle-mode-recon.md`.

### `EXTRAS`

- **Desbloqueo**: se entra si se tecleó el **código Konami** en el logo KONAMI o si `MANTENER EXTRAS`
  está en SÍ (`config.ini [extras].persist`). También se mantiene visible si algún toggle de EXTRAS
  está activo, para poder apagarlo.
- **`MANTENER EXTRAS`** (`NO/SÍ`, persiste `[extras].persist`) y **`LOGOS ORIGINALES`**
  (`NO/SÍ`, `[extras].original_logos`).
- **`MODO HEAVEN`** (`NO/SÍ`, `[extras].heaven`): **modo global persistente**, independiente de la
  partida. Al cargar/empezar partida aplica ATRIBUTOS/ESTADO 99 + 86 habilidades; en runtime,
  invulnerabilidad (combate y campo), items no consumibles y **PODER/RESISTENCIA ∞**. **No** incluye
  VENTAJA. Detalle técnico y direcciones: `../RETOMAR.md`.
- **`EDICIÓN DE PARTIDA`**: submenú del editor de saves (ver `../notes/` y `RETOMAR.md`).
- **`VENTAJA`** (`NO/SÍ`, `[extras].advantage`): ventaja de combate ("back attack"); fuerza
  `0x801BCC24 = 2` por frame. Independiente de HEAVEN.
- **`PODER ∞`** / **`RESISTENCIA ∞`** (`NO/SÍ`, `[extras].infinite_power` / `[extras].infinite_stamina`):
  mantienen el gauge de combate al máximo (no se gasta). El `∞` (U+221E) **no está en la fuente** y se
  dibuja vectorial (13×5, con sombra), como `:` `.` `%` `/`.
- **Idiomas**: todas las etiquetas traducidas a **en/es/ca/fr/de/ja**.

### `GUARDAR PARTIDA` (cápsula / `DATA SAVE`)

- **Menú propio** encima del `DATA SAVE` nativo (que queda oculto; F8 alterna su visibilidad). Flujo
  por fases (`hh::menu::SavePhase`):
  - `Ask` → `Save play data?` Yes/No (slots ocultos). **No** → `Exit without saving?` (sale o vuelve).
  - `Select` → mensaje con **bindings reales** (inglés, 3 líneas: `Select location in which to\nsave
    play data pressing A/J or X/H\nto remove.`) y la lista (`NEW GAME` + slots con datos).
  - `ConfirmHere` → `Saving current play data here.` Yes/No → guarda (`save_live`) → `Completed`.
  - `Completed` → `Save completed.` + flecha ↓; **A sale de la cápsula**.
  - **Borrado**: **X** (agacharse) sobre un slot con datos → `Remove play data?` Yes/No → Yes borra →
    `Remove completed.` + flecha ↓; **A vuelve a la lista** (no sale). `NEW GAME` no se puede borrar.
- **A** (aceptar) guarda; **X** (agacharse) borra. Los bindings se leen en vivo (remapeables). El
  guardado **serializa los globals vivos** (`func_80141F28`) y escribe el `.pak` con `hh::save`.
- Detalle técnico: `notes/2026-09-30-save-capsule-logica.md`.

### `SALIR`

- **Extra del port** (el original no lo tiene): la **única** entrada fuera del árbol nativo, acordada
  con el mantenedor (2026-09-25). Va la **última de la raíz**, debajo de `CONFIGURACIÓN`.
- **A** cierra el port de forma **ordenada**: `hh::request_quit()` recuerda la geometría de la ventana
  (`hh::video_remember_window`) y llama a `ultramodern::quit()` (salida limpia de `recomp::start`, con
  *join* de hilos; **no** `std::exit`, que dispararía `std::terminate`). Mismo camino que `SDL_QUIT`
  o `F11` en `src/subsystems/input.cpp`. El enganche está en `feed_menu_navigation`
  (`src/hooks/sections.cpp`): solo actúa con el **overlay controlando** el menú (`HH_OVERLAY=0` deja
  mandar al nativo).
- **Etiqueta localizada** (`EXIT` / `SORTIR` / `QUITTER` / `BEENDEN`; JA cae a inglés). El modelo está
  en `hh::menu` (`Action::Exit`); el dibujo es el genérico (una entrada más).

## Idiomas y acentos (2026-09-25)

> **Tipografías (fuentes `color0..5`, API `overlay::Text.face`, avances): `fonts.md`** — fuente de
> verdad. El menú usa `Color0`; el `DATA LOAD` propio usa `Color3` (título) y `Color4` (mensaje).

- **Etiquetas localizadas**: las del modelo están en **español (canónico)** y se traducen al idioma
  activo con `hh::menu::localized()` (tabla `kMenuTr`, `src/subsystems/menu.cpp`), que el overlay usa
  al publicar el texto. Idiomas: **en/es/ca/fr/de**. La lista `IDIOMA` muestra **endónimos**
  (`ENGLISH · ESPAÑOL · CATALÀ · FRANÇAIS · DEUTSCH · NIHONGO`) iguales en todos los idiomas.
- **Acentos del menú = letra + marca**: el overlay pinta la **letra base** (color0 8×8, **sin
  deformar**) + una **marca** (agudo, grave, circunflejo, diéresis, virgulilla, cedilla, punto medio)
  dibujada por el propio overlay (`kMarkShapes` en `src/platform/overlay.cpp`) con la **forma que
  dibuja el mantenedor** (`tools/text/menu_marks.py`: plantilla editable → import →
  `include/hh/menu_marks.h`). Evita comprimir mayúsculas. `¿ ¡` se generan girando `? !`. Las marcas
  van **detrás** de la letra (z-order, para que su sombra +1,+1 no la pise); **excepción: la cedilla**
  (`Ç`), que va **delante** (se dibuja después) por ir debajo de la letra (`mark_front = dy > 0`).
- **Texto in-game**: los acentos del texto in-game usan la fuente real **8×12 (`color4`)** compuesta
  (`tools/text/build_font.py` → `include/hh/game_font_color4.h`, ES/CA/FR/DE). **Pendiente cablearla**
  (hoy `src/hooks/text_glyphs.cpp` sirve un set 8×8 propio).
- **Idioma del sistema**: sin `[lang]` guardado, se usa el locale del SO (`GetUserDefaultLocaleName`
  en Windows; `LANG`/`LC_*` en Linux) **si es uno de `en/es/ca/fr/de/ja`**; si no, **inglés**.
  Prioridad: `HH_LANG` > `config.ini [lang]` > sistema > `en`.
- **Japonés (2026-09-27)**: el `color0` (idx107) del ROM JP es **byte-idéntico al US** (mismo
  fichero, otra dirección): la **kana** vive en los valores **64..255** y ya está en la ROM que carga
  el port
  (no hay que extraerla de `jp.z64`). Mapping kana→glifo desde las tablas EUC→slot del `.resident`
  del ELF (`tools/text/extract_jp_kana.py` → `include/hh/jp_kana.h`, 165 entradas). El atlas pasa a
  **128×128** (+ franja de marcas); el overlay resuelve los codepoints kana con `jp_kana_value`. La
  columna **JA** de `kMenuTr` va en **kana** (no hay kanji en `color0`) y `localized()` ya **no cae a
  inglés**; el endónimo de la lista `IDIOMA` es `ニホンゴ`. El texto in-game (EUC-JP con kanji) sigue
  por su propia vía (`assets/lang/ja.txt`, pendiente). Como `color0` **no trae sombra fiable** en los
  valores **>=64** (kana/símbolos), `hh::font::game::bake_atlas` la **descarta** y el overlay dibuja la
  sombra de la kana como **copia negra del glifo +1,+1** (puede salir de la celda de 8 px, sin
  recortes); el latino (0..63) no se toca (ya la trae).

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

`assets/sounds/`: `.mp3` (origen) + `.wav` 48 kHz/S16. El build **solo copia los `.wav`** a `assets/sounds/`
a `assets/sounds/` junto al `.exe`; **cambiar un `.mp3` NO regenera el `.wav`** → reconvertir con `ffmpeg`
(`-ar 48000 -ac 2 -sample_fmt s16`) y commitear el `.wav`. Nombres que carga `src/platform/menu_sfx.cpp`:
`menu-move.wav`, `menu-accept.wav`, `menu-back.wav`. `test_sounds/` = sonidos antiguos (backup).
**Personalización**: el usuario puede reemplazar los `.wav` de `assets/sounds/` (mismos nombres, **48 kHz /
S16 / estéreo**); si el formato no encaja, se ignora y se avisa en `hh.log`. `MENÚ SFX = NO` los silencia.

## Estado de implementación

| paso | estado |
|---|---|
| 1. Modelo `hh::menu` (estado) | **HECHO** (`include/hh/menu.h` + `src/subsystems/menu.cpp`) |
| 2. Dibujo 1:1 (fuente + flecha nativa) | **HECHO** y **validado en Windows**. Listas con la aplicada en verde y el resto en gris; selectores (valores juntos o `< valor >` con flechas dibujadas); dígitos mapeados (2026-09-24) |
| 3. Ocultar el menú nativo | **HECHO** y **validado en Windows** (los 3 bugs del overlay). Ver `architecture.md` §7 |
| 4. Etiquetas propias + acentos + idiomas | **HECHO (2026-09-25 / 2026-09-27) y validado en Windows (2026-09-27)**: etiquetas localizadas (en/es/ca/fr/de **/ja**) + acentos por **letra+marca** + `IDIOMA` funcional + **detección del idioma del sistema**. **JA en kana** (valores 64..255 de `color0`; `include/hh/jp_kana.h`) y atlas 128×140. Tildes a **+0.5 px**. Pendiente: verificar los textos JA contra la ROM japonesa |
| 5. Navegación propia (A/B + selectores, control total) | **HECHO (2026-09-24) y validado en Windows**. `feed_menu_navigation` cubre arriba/abajo/izq-der/A/B (sin X) y el input del handler nativo queda **muteado** |
| 6. Acciones (mapear cada entrada a la función del juego) | parcial: `DEBUG` engancha el modo desarrollador de RT64 (F1) y **`MOSTRAR FPS`** dibuja el indicador; **`RATIO` / `RESOLUCIÓN` / `P. COMPLETA` / `ANTIALIASING` / `VSYNC` / `LÍMITE DE FPS`** aplican en vivo y **persisten en `config.ini`** (`[video]`) con los valores iniciales leídos de la config (+ geometría de ventana). **`SALIR`** cierra el port de forma ordenada (extra del port). **`CONTINUAR`** retoma la partida y **`EMPEZAR PARTIDA`** arranca partida nueva (disparo nativo; ver §Acciones nativas), **`EMPEZAR PARTIDA` validado en Windows (2026-09-26)**. **`DIFICULTAD`** fija la dificultad de esa partida (global `0x801BBC0D`): implementada, pero su **efecto real** (daño enemigo) **queda por comprobar jugando**. **`MODO COMBATE`** habilitado con subpantallas propias (`MODO VS`/`COMBATE DE CRIATURAS`→`5 COMBATES`/`SUPERVIVENCIA`/`EDITAR DATOS`; se sale con B) y **despacho nativo** por cursor; **validado en Windows (2026-09-27)** salvo `MODO VS` (solo se reporta el puerto 0 de mando). `CÁMARA LIBRE`/`APUNTADO LIBRE` **ocultos** (2026-09-27) hasta que el juego los soporte |
| 7. SFX desde eventos del modelo (retirar el puente) | **HECHO (2026-09-25) y validado en Windows**: `Move`/`Accept`/`Back` desde los eventos de `hh::menu`; puente retirado |
| 8. Validar en Windows | **HECHO (2026-09-27)**: menú completo (navegación, idiomas/acentos, acciones, `CONTROLES`, `MODO COMBATE`, `EXTRAS`, JA) validado |

**Orden seguido:** 5 → 6 → 7 → 4 → 8 (todos hechos; **JA y validación en Windows, 2026-09-27**). Los
submenús se pueden forzar con `HH_MENU_SCREEN=6` GRÁFICOS / `=5` IDIOMA.

La configuración de los selectores ya **persiste** (`config.ini`) y el idioma también (`[lang]`).
`CÁMARA LIBRE`/`APUNTADO LIBRE` **ocultos** por ahora hasta que el juego los soporte (requieren
modificar el juego).

## Acciones nativas (arranque/retomada de partida)

El overlay es la UI, pero las **acciones que arrancan la partida** reutilizan el flujo del juego
(evitando reimplementarlo). En `feed_menu_navigation` (`src/hooks/sections.cpp`):

- **`CONTINUAR`** (raíz, hoja nativa): se fija `sel` (`0x801CC8C4`) a `1` (CONTINUE) y se inyecta
  **A** una vez (`g_inject_native_a`); el handler de la raíz corre su rama real
  (`func_801C3CDC`, carga la partida).
- **`EMPEZAR PARTIDA`** (hoja del submenú nativo `NUEVA PARTIDA`): se fija la **dificultad** en el
  byte global **`0x801BBC0D`** (`0=NORMAL`, `1=DIFÍCIL`, `2=DEFINITIVO`) y se dispara la rama
  **GAME START** del submenú (`func_801C3A40`, idx 0): `func_80005670(obj, 0x80044090)` crea el
  objeto de transición y `func_800058DC(obj, 0x801C3BA4)` fija el callback; la cadena nativa
  `func_801C3BA4 → func_801C3BD8 → func_801C3C14` crea la partida. **NO** se pasa por
  `func_801C3940`: solo resetea la dificultad y registra las etiquetas del submenú (que el overlay ya
  dibuja). El objeto del menú (`obj`) es el `a0` del handler (`ctx->r4`).
- **`DIFICULTAD`**: la lista del overlay (`DEFINITIVO/DIFÍCIL/NORMAL`) es orden inverso al nativo;
  la acción de `EMPEZAR PARTIDA` lee la opción marcada (`hh::menu::screen(ScreenId::Difficulty)`) y
  la escribe en `0x801BBC0D`.

**Validado en Windows (2026-09-26)**: `EMPEZAR PARTIDA` arranca la partida nueva. La **`DIFICULTAD`**
se escribe correctamente en `0x801BBC0D` (implementación confiada), pero su **efecto en el juego**
(daño de los enemigos) **queda por comprobar jugando** en una sesión posterior. Evidencia:
`notes/2026-09-26-g-empezar-partida-y-dificultad.md`.

Criterio de futuro: el overlay **reemplaza** los submenús nativos (SOUND/RESOLUTION/CONFIGURACIÓN),
así que las acciones nativas se disparan de forma **puntual y centralizada** desde la hoja del
overlay, no pilotando el submenú nativo. Si algún día se decide reutilizar un submenú nativo entero
(p. ej. `MODO COMBATE`), eso sería un diseño aparte con sus propios hooks.
