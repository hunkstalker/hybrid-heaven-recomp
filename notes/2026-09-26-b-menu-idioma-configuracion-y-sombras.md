# Menú: bug de `IDIOMA`, rename a `CONFIGURACIÓN` y análisis de sombras

> Sesión 2026-09-26 (b), rama `menu-nativo`. Cierra dos tareas del backlog del menú y deja
> analizado el pulido de sombras. Todo **validado en Windows** por el mantenedor.

## 1. Bug del submenú `IDIOMA` (Aplicado sin confirmar al reentrar)

**Síntoma**: entrar en `IDIOMA`, mover el cursor sobre un idioma **sin aplicarlo** y salir con **B** no
hacía nada (correcto); pero al **volver a entrar y salir** se aplicaba el idioma señalado, sin
confirmar con A.

**Causa**: en `feed_menu_navigation` (`src/hooks/sections.cpp`), al pulsar **A** sobre el submenú
`IDIOMA` (en `CONFIGURACIÓN`), `hh::menu::confirm()` **apila** la pantalla hija y devuelve `Accept`.
Después, el handler genérico evaluaba `hh::menu::current_screen()` —que ya era **Language**— y, con
`ev == Accept`, ejecutaba el bloque de IDIOMA: `hh::text_set_language(kLangCodes[s.cursor])`. Es
decir, **entrar en el submenú aplicaba el idioma del cursor**, no una confirmación interna.

**Fix**: capturar `screen_before` **antes** de procesar el botón y aplicar las acciones por `Accept`
(aplicar idioma y `SALIR`) **solo si la pantalla no cambió** (`same_screen`). Así el `Accept` que
entra en un submenú no ejecuta acciones de la pantalla hija.

## 2. `AJUSTES` → `CONFIGURACIÓN` (con traducciones)

- Raíz y entrada de submenú: `CONFIGURACIÓN`.
- Traducciones (`src/subsystems/menu.cpp`, `kMenuTr`):
  **ES** `CONFIGURACIÓN` · **EN** `SETTINGS` · **CA** `CONFIGURACIÓ` · **FR** `CONFIGURATION` ·
  **DE** `KONFIGURATION`.
- Comentarios de `include/hh/menu.h` y `src/hooks/sections.cpp` y `docs/menu.md` actualizados.
- **No** se toca `src/subsystems/text.cpp` (`SOUND`/`OPTION` → `AJUSTES`): es texto **nativo** (campos
  de ancho fijo del motor) y `CONFIGURACIÓN` (13 vs 7) podría desbordar; además el menú nativo va
  oculto.

## 3. Análisis de sombras (backlog)

Motivo: revisión visual del mantenedor. El motor dibuja el **texto** con sombra negra a **+1 px
derecha / +1 px abajo** (horneada en el atlas `font.cpp`: nivel 1 = tinta, nivel ≥2 = negro).

- **Flecha de cursor**: `append_native_cursor` (`src/hooks/menu_overlay.cpp`) la compone con
  **rectángulos sólidos** (`frame.panels`) de un color → **no tiene sombra**. Fix: dibujar antes una
  **copia negra desplazada (+1,+1)** y encima la flecha.
- **Tildes/marcas de acento**: `tools/text/menu_marks.py` genera las marcas con `crop_shift(ink)` →
  **solo tinta (nivel 1)**, sin sombra. Solo `¿ ¡` (ruta `AUTO` con `add_shadow_cell`) llevan nivel 2.
  Si el mantenedor dibujó sombra en la capa, `read_cell` la **aplana a tinta** (sale del color del
  texto, no negra) y/o la recorta la celda. Fix: generar sombra **+1,+1** también en las marcas de
  acento e **incluirla en el recorte**; comprobar que la celda (ancho `kMarkW=8`, alto 12, `pix[96]`)
  no la recorta. Regenerar `include/hh/menu_marks.h`.

Tareas anotadas en `TODO.md` §"Menú nativo — funcionales y pulido" (8 y 9).
