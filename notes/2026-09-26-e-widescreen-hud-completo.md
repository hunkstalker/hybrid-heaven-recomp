# Widescreen/HUD: cierre (no existe "barra HP")

> Sesión 2026-09-26 (e), rama `menu-nativo` (aplica a `main`). **Corrección de documentación**: se
> cerraba como pendiente una "barra HP" que **no existe**. El anclaje del HUD está **completo y
> validado en Windows**.

## Aclaración

En el HUD de combate **no hay barra de HP**. La salud se muestra con el **dial radial**
(arriba-izquierda) y el **numérico** `HP n / n`; ninguno es una "barra" aparte. La idea de una
"barra HP" venía de una suposición de una sesión anterior (p. ej. el listado
`Barras POWER/STAMINA/HP y elementos de la derecha`), nunca fue un elemento real.

## Estado: HUD/widescreen COMPLETO (validado en Windows)

- **Izquierda**: radar + HUD de combate — POWER/STAMINA, disco radial, barra de combo, stamina
  gastada. **Derecha**: minimapa (contenido + fondo negro a todo el ancho).
- **Persiste** entre combates y niveles (issue #3: clasificación por **hash de contenido** / posición,
  no por dirección RDRAM; issue #7: minimapa por hash de contenido).
- **Cuadros de diálogo**: salen **centrados** con su propio anclaje → **no requieren cambios**.
- Reescritor: `src/hooks/hud_rewrite.cpp` (`HH_NO_HUD_REWRITE=1`, `HH_FULL_FRAME=0`, `HH_HUD_TRACE=1`).

## Docs corregidos

- `TODO.md`: item de widescreen consolidado como **`[x]` COMPLETO**; eliminada la "barra HP" y
  aclarado que la salud es dial + numérico.
- `RETOMAR.md`: bloque de widescreen marcado **CERRADO**.
- `docs/BUILDING_windows.md` §Widescreen: POWER/STAMINA **ancladas** (antes decía que quedaban en 4:3);
  aclarado que **no hay barra HP** y que los diálogos van centrados.

Notas históricas (`notes/2026-09-21-…-radar.md`, `notes/2026-09-22-…-fase07b.md`, commit `8d7ff23`)
conservan la mención antigua; **esta nota la supersede**.