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
3. **Navegación**: arriba/abajo mueve el cursor (la **flecha nativa**); **A** marca/selecciona la
   opción resaltada, **X** aplica (guarda y vuelve atrás), **B** atrás (descarta). En los
   **selectores laterales**, izquierda/derecha cambian el valor (`< 30 >`, con **flechas amarillas** a
   los lados). La **selección resaltada se pinta en verde**.
4. **Control TOTAL del menú** (no reutilizar el del juego): el overlay moderno **desacopla** el menú
   inicial del juego para tener todo el control (ver §Input).
5. **Sin entradas `ACEPTAR`**: el patrón **A/X/B** (punto 3) es común a **todas** las pantallas de
   selección. La **guía de botones** (sprites X/A/B abajo: `X`=Aplicar, `A`=Seleccionar, `B`=Atrás,
   como la que el juego ya muestra en la pausa) **se implementa más adelante**.

## Árbol de menús

Orden de arriba a abajo; `->` = con A se entra a esa pantalla. En todas rige **A/X/B** (A marca, X
aplica y vuelve, B atrás):

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
  amarillas; izquierda/derecha cambian el valor. El de **LÍMITE DE FPS** aún no tiene lista cerrada.
- **AJUSTES EXPERIENCIA MODERNA**: para mejoras jugables que se salen del original. Por ahora
  **CÁMARA LIBRE** y **APUNTADO LIBRE** son propuestas por decidir. El usuario las configura **antes**
  de empezar; luego pulsa `EMPEZAR PARTIDA` y el flujo del juego continúa normal.
- **MODO COMBATE**: por definir; de momento aparece **deshabilitado en gris**.

## Input — DECIDIDO: control total

El overlay moderno **desacopla** el menú inicial del juego: nuestro menú lee el input
(arriba/abajo/izq-der/A/B/X) y gestiona su **propia pila de pantallas**; el menú nativo se **oculta**
(no se deja correr su handler o se neutraliza su dibujo). Como es control total, lo natural es **no
depender del handler del juego**; la fuente concreta de botones (los del juego `func_801C1340`
direcciones / `func_801C1334` A/START, o el input propio `hh::get_input`) se decide en implementación.

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
| 2. Dibujo 1:1 (fuente + flecha nativa) | **HECHO** (headless; falta validar en Windows). Falta: acentos reales, valores de selectores |
| 3. Ocultar el menú nativo | **HECHO** (headless; falta Windows). Ver `architecture.md` §7 |
| 4. Etiquetas propias (tabla del port, integrada con idiomas A1/B) | pendiente |
| 5. Navegación propia (A/B/X + selectores, control total) | terreno hecho: `feed_menu_navigation` (arriba/abajo). Falta neutralizar el input nativo y A/B/X |
| 6. Acciones (mapear cada entrada a la función del juego) | pendiente (pantalla a pantalla) |
| 7. SFX desde eventos del modelo (retirar el puente) | pendiente |
| 8. Validar en Windows | pendiente |

Alcance de la tanda actual: **solo el árbol de menús** (estructura, navegación y dibujo). **NO**
persistir la configuración todavía (los selectores cambian en memoria; el guardado en `config.ini`
queda para después).
