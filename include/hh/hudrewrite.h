#pragma once

// Reescritor del HUD 2D para widescreen. Adaptado del port de referencia (MIT; ver CREDITS.md y
// licenses/hybrid-heaven-recomp-MIT.txt), `src/hudrewrite.cpp` (Phase 07).
//
// El juego dibuja el HUD bajo una proyeccion ortografica 320x240; RT64, en aspect=Expand, ensancha
// el 3D pero no re-ancla la 2D. `rewrite` copia la lista a un scratch de RDRAM e inserta GBI
// extendido alrededor de cada elemento clasificado (izquierda/derecha/stretch/spill).
//
// Devuelve la direccion KSEG0 de la copia, o 0 si no hay nada clasificado / la lista no cabe o no
// termina en G_ENDDL (en cuyo caso el frontend envia la lista original del juego).

#include <cstdint>

namespace hh::hudrewrite {

// Clases de un elemento, en el orden que usaria un panel. kSpill solo levanta el scissor 4:3.
enum Class : int { kAuto = 0, kLeft = 1, kRight = 2, kStretch = 3, kSpill = 4 };

// Clase de una identidad (tabla fija, re-derivada con HH_HUD_TRACE=1). kAuto si no esta.
//
// La direccion RDRAM no es identidad; se clasifica por HASH DE CONTENIDO. Cuando un hash se
// reutiliza (p. ej. la mascara `dfde6ac5` compone radial, minimapa y menus), se desambigua con
// criterios extra:
//   - `box`  extension en px 320x240 (ulx,uly,lrx,lry); -1 si no aplica (dl). El par del
//            radial/disco (`a3036828`/`dfde6ac5`) solo se ancla en 27,19,59,51.
//   - Posicion: la barra de COMBO son 4 `G_FILLRECT` en la fila y=28..30 (color rojo/azul por
//            prim; la traza lee fill_color=0). Se clasifica por fila, no por color.
//   - `env`  color de entorno RGBA (G_SETENVCOLOR) del draw (pista secundaria).
// Ver notes/2026-09-25-f-hud-combate-contenido.md.
int class_of(const char* identity, int ulx = -1, int uly = -1, int lrx = -1, int lry = -1,
             uint32_t env_colour = 0);

// Hay alguna identidad clasificada en la tabla fija.
bool any_classes();

// Recorte del mapa en px (por lado), ajustable en caliente (teclas +/- del teclado numerico).
int map_crop();
void map_crop_add(int delta);

uint32_t rewrite(uint8_t* rdram, uint32_t list_address);

}  // namespace hh::hudrewrite
