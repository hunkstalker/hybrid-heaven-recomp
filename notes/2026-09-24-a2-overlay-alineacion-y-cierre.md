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

## Bug 3 — el overlay tardaba ~1 s en desaparecer al salir del menú

`hh::menu_overlay::tick()` (hilo de render) ocultaba el overlay tras **30 llamadas** sin
publicaciones. Pero `tick()` corre en cada `ScreenUpdateAction`, a una tasa que no controlamos
(~30 Hz o más): 30 ticks ≈ **1 s** de retardo (el comentario decía "~0.3 s", incorrecto).

**Arreglo:** umbral **por tiempo**, no por ticks: si pasan `HH_MENU_STALE_MS` (def. **150 ms**) sin
publicaciones, se publica un `Frame{}` vacío (una sola vez). Independiente de la tasa de `tick`.
`src/hooks/menu_overlay.cpp` (`tick`).

**Validado** (headless): al entrar en un submenú, `[overlay] ocultar: 150 ms sin publicar` justo
después de fijarse el handler del submenú (antes ~1 s).

## Pendiente

- Validar los tres bugs en Windows (build release).
