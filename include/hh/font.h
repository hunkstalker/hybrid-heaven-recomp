#pragma once

// hh_font — backend "fuente del juego" (A2).
//
// Decodifica la fuente del juego (color0, fichero Nisitenma 107, 8x8, 2bpp) desde la ROM a un
// **atlas RGBA8 en memoria host**, listo para subirse como textura en el render hook de RT64
// (plume). NO emite GBI: el dibujo lo hace el render hook (ver RETOMAR.md, A2 Fase A).
//
// Formato de la fuente (ver notes/2026-09-23-b-fuente-formato-y-gaiji.md): cada bloque de `stride`
// bytes contiene DOS glifos empaquetados: valor PAR -> bits 2-3 de cada nibble (0xCC); valor IMPAR
// -> bits 0-1 (0x33); `block = valor>>1`.
//
// El atlas es de 128x32 px (16 glifos por fila, valores 0..63). Cada pixel RGBA8:
//   R = 255 tinta (nivel>=2, texto) / 0 sombra (nivel 1, desplazada en diagonal)
//   A = cobertura (0/255)
// El PS pinta el color del vertice en la tinta y negro en la sombra (como el motor).

#include <cstdint>

namespace hh::font {
namespace game {

// Lee la fuente color0 de la ROM (get_rom_path()) y construye el atlas RGBA8. Idempotente.
// false si no encuentra/lee la ROM (no aborta). No necesita RDRAM.
bool init();

bool ready();

// Atlas RGBA8: `atlas_width()*atlas_height()*4` bytes. Valido si ready().
const uint8_t* atlas_rgba8();
unsigned atlas_width();    // 128
unsigned atlas_height();   // 32
unsigned char_width();     // 8
unsigned char_height();    // 8

// Valor de glifo del motor para un caracter ASCII (0 = vacio). false si no hay glifo.
bool glyph_value(unsigned char c, unsigned& value);
// Posicion (px) del glifo en el atlas. false si no hay glifo.
bool glyph_uv(unsigned char c, unsigned& x, unsigned& y);

}  // namespace game
}  // namespace hh::font
