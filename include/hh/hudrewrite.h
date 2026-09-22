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
int class_of(const char* identity);

// Hay alguna identidad clasificada en la tabla fija.
bool any_classes();

// Recorte del mapa en px (por lado), ajustable en caliente (teclas +/- del teclado numerico).
int map_crop();
void map_crop_add(int delta);

uint32_t rewrite(uint8_t* rdram, uint32_t list_address);

}  // namespace hh::hudrewrite
