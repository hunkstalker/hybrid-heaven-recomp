# B / A2-camino1 — Motor de texto del juego localizado (rutina de dibujo)

> Sesión 2026-09-23. Camino elegido por el mantenedor: **reutilizar el motor de texto del juego**
> para el menú PC (estilo idéntico), estructurado para poder añadir una tipografía moderna después.
> Complementa `notes/2026-09-23-b-fuente-localizacion.md` y `notes/2026-09-23-a2-plan-menu-ajustes-idioma.md`.

## Arquitectura decidida (3 capas)

```
hh_menu  (lógica: entradas, cursor, acciones)          [nuestro]
   └─ hh_font (interfaz: draw_text(x,y,text,color))     [nuestro]
        ├─ backend_game   (motor de texto + fuente del juego)   <- hoy
        └─ backend_modern (fuente TTF/atlas HD)                 <- futuro
```

Separación de "origen del texto" (tabla de idiomas, ya hecha) y "motor de dibujo". Cambiar a fuente
moderna = otro backend, sin tocar menús ni traducciones.

## Sistema de texto del juego (mapa, flat / código plano 0x8001xxxx)

| dirección | rol |
|---|---|
| `0x8001B204` | **set/actualizar ENTRADA de menú**: usa una tabla de estilos en `0x8004xxxx` (0x4548/0x4608/0x4614…); llama a `0x8001BC04`. Es lo que el menú invoca por cada entrada. |
| `0x8001BC04` | **colocar TEXTO**: estado en struct `s0` y **color global `0x8009E48..0x8009E4F`** (RGBA). Llama a `0x8001BD20`, `0x8001D394`, `0x8001C0B0`. |
| `0x8001BD20` / `0x8001D394` / `0x8001C0B0` | subrutinas de `0x8001BC04` (layout/render de texto; pendiente detalle). |
| `0x8001F204` | parser de formato de string (`%p`, `%m`, `%a`…); llama a `0x8001F160` (memclear). |
| `0x8001F290` | allocator de heap (bloques), **no** dibujo. |

- La tabla de estilos (colores/posición por plantilla) está en `0x8004xxxx`.
- El color de texto activo vive en `0x8009E48..E4F`.

## Herramientas añadidas en el port

- `HH_MENUTRACE=1` (`src/hooks/dl_snap.cpp`, `hh::menu_trace`): vuelca a `hh_menudl.log` las display
  lists con texturas (`SetTImg`/`TexRect`) para cazar las primitivas de glifo. (En headless el menú
  de título no llega a dibujarse sin input; para verlo hay que interactuar en Windows.)

## Siguiente paso

1. Desensamblar `0x8001BC04` (+ `0x8001D394`/`0x8001C0B0`) para entender la firma de "colocar texto"
   y así poder invocarla desde un `backend_game` (posiblemente basta con `0x8001B204`/`0x8001BC04`).
2. Localizar la **textura de fuente** que usan (asset) para el `backend_game` y para B (acentos).
3. Montar `hh_font` con `backend_game` y el menú AJUSTES/IDIOMA encima (A2 camino 1).
