# A2 — Bugs del overlay: alineación de "MODO COMBATE" y cierre al salir del menú

> Sesión 2026-09-24 (continuación). Arregla los bugs 1 y 3 reportados por el mantenedor. El bug 2
> (menú nativo al volver atrás) está en `notes/2026-09-24-a2-ocultar-menu-nativo-dos-tablas.md`.

## Bug 1 — "MODO COMBATE" 1 px a la izquierda

**No era un desplazamiento de posición**: el `pen_x` de todas las líneas es el mismo (`layout.x` +
un espacio inicial). Es el **bearing izquierdo del glifo**. La fuente del juego (color0, 8×8) no es
uniforme: la tinta de `M O V W X Z` empieza en la **columna 0**, la de `I` en la 2 y la del resto en
la 1. El motor dibuja cada glifo en su celda **sin compensar**, así que una línea que empiece por
`M` sale 1 px a la izquierda del resto.

**Medición** (captura 1280×960, `k = 4 px/unidad`; primer glifo en la celda de x=480):

| línea | letra (bearing) | tinta x (px) |
|---|---|---|
| nativo ` CONTINUE` | C (1) | 484 |
| nativo ` BATTLE MODE` | B (1) | 484 |
| nativo ` SOUND` | S (1) | 484 |
| nativo `…MODE` (media palabra) | M (0) | 704 = borde de celda |
| nuestro ` NUEVA PARTIDA` | N (1) | 484 |
| nuestro ` MODO COMBATE` (antes) | M (0) | **480** |
| nuestro ` AJUSTES` | A (1) | 484 |

El menú **nativo** solo usa inicios de columna 1 (N/C/B/S/R), por eso se ve uniforme; la traducción
introdujo "MODO COMBATE" (M, columna 0) y rompió esa uniformidad. El `M` nativo de "MODE" también
empieza en la columna 0 (confirmado en la captura del nativo), o sea que el motor haría lo mismo.

**Arreglo (cosmético, para igualar el look uniforme del menú nativo):** compensar el **primer**
glifo de cada línea a la columna de referencia 1:
- `hh::font::game::glyph_left_bearing(c)` (`include/hh/font.h` + `src/subsystems/font.cpp`): columna
  de la primera tinta (R≠0) del glifo en su celda, o -1.
- `src/hooks/menu_overlay.cpp` (`title_update`): `x_text += 1 - bearing` del primer carácter no
  espacio. Se desplaza la línea entera (no el glifo suelto, que dejaría un hueco interno).
- La flecha nativa se queda en `x+1` (posición nativa); solo se mueve el texto.

**Validado** (headless): `MODO COMBATE` pasa de 480 a 484 px, alineado con las demás líneas
(captura `ours_root.png`). Es un desvío deliberado del render exacto del glifo para que el menú se
vea como el nativo (uniforme); si se prefiere fidelidad estricta al bearing, se revierte.

## Bug 3 — el overlay tardaba en desaparecer al salir del menú

**Dos causas en cadena** (la primera no bastaba, validado en Windows el 2026-09-24):

1. `hh::menu_overlay::tick()` (hilo de render) ocultaba tras 30 llamadas sin publicaciones; a la
   tasa real de `ScreenUpdateAction` (no fija, ~30–110 Hz) eso daba hasta **~1 s**. Primer arreglo:
   umbral **por tiempo** (`HH_MENU_STALE_MS`, def. 150 ms) en vez de por ticks.
2. Pero `hh_title_menu_hook` llama a `title_update` **después** del handler original. Al seleccionar
   una opción, el handler llama a `func_800058DC` (cambio de pantalla) **y a continuación**
   re-publicábamos el frame de la raíz en ese mismo frame; el ocultado real dependía luego de
   `tick()` (hilo de render), que puede tardar. → el overlay seguía viéndose durante la transición.

**Arreglo** (`src/hooks/sections.cpp` + `src/hooks/menu_overlay.cpp`):
- **`hh_goto_hook`** (envuelve `func_800058DC`, hilo del juego) llama a
  **`hh::menu_overlay::hide_now()`** → publica un `Frame{}` vacío en el acto. Instantáneo,
  independiente de `tick`.
- `hh_title_menu_hook` **no** llama a `title_update` si la pantalla cambió ese frame
  (`goto_after != goto_before`), para no re-publicar la raíz tras el cambio.
- Se mantiene el umbral por tiempo de `tick` como red de seguridad.

Si la nueva pantalla sigue siendo la raíz, el handler vuelve a publicar en el frame siguiente y el
overlay reaparece (no parpadea al entrar).

**Estado**: pendiente de validar en Windows (los bugs 1 y 2 ya validados 2026-09-24: MODO COMBATE
alineado y el nativo ya no aparece al volver atrás).

## Pendiente

- Validar este bug 3 en Windows (build release).
