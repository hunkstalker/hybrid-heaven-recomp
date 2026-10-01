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
// El atlas es de 128x(h+12) px (16 glifos por fila, valores 0..255): 128x128 para los glifos
// (0..63 latino, 64..255 simbolos/kana/kanji) + una franja de marcas del menu debajo. Cada pixel
// RGBA8:
//   R = 255 tinta (nivel 1, glifo) / 0 sombra (nivel >=2, desplazada en diagonal)
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
unsigned atlas_height();   // 128 (glifos) + franja de marcas (140 con el set actual)
unsigned char_width();     // 8
unsigned char_height();    // 8

// Tipografia (fichero de fuente Nisitenma) del motor. El DATA LOAD usa las TRES:
//   Color0 (8x8, idx 107) = menu/overlay y filas del DATA LOAD ("AREA/LEVEL/TIME", "CONTROLLER PAK").
//   Color4 (8x12, idx 108) = texto in-game y mensaje "Select play data to be loaded.".
//   Color3 (12x13, idx 106) = titulo grande ("DATA LOAD"). ASCII mayusculas: valor = 0x76 + (c-'A').
//   Color1 (10x10, idx 109) = kana "grande" (titulo JA); mismo mapeo ASCII/kana que color0.
enum class Face { Color0, Color4, Color3, Color1 };

// Tamaño de celda del glifo (px) de cada tipografia.
unsigned face_cell_w(Face f);   // 8, 8, 12
unsigned face_cell_h(Face f);   // 8, 12, 13

// Avance (px) que el motor da al glifo `c` de la tipografia `f`. Base = ancho de celda; color4 tiene
// correcciones por caracter (`func_8001BD20`): **espacio = 4** y `f i j l r t` = 6. Ver docs/fonts.md §6.
unsigned face_glyph_advance(Face f, unsigned char c);

// UV del glifo de `c` en la tipografia `f` (ASCII). false si no hay glifo.
bool face_glyph_uv(Face f, unsigned char c, unsigned& x, unsigned& y);

// UV del glifo por su VALOR de motor en la tipografia `f` (Color1/Color0; kana incluida). false si no.
bool face_value_uv(Face f, unsigned value, unsigned& x, unsigned& y);

// Valor de glifo del motor para un caracter ASCII (0 = vacio). false si no hay glifo.
bool glyph_value(unsigned char c, unsigned& value);
// Posicion (px) del glifo en el atlas. false si no hay glifo.
bool glyph_uv(unsigned char c, unsigned& x, unsigned& y);
// Columna de la primera tinta del glifo dentro de su celda (0..7), o -1 si no hay glifo/esta vacio.
// La fuente del juego NO es uniforme: M/O/V/W/X/Z empiezan en la columna 0 y el resto (salvo I, en
// la 2) en la 1. El motor dibuja cada glifo en su celda sin compensar, asi que una linea que empiece
// por 'M' sale 1 px a la izquierda del resto. Ver notes/2026-09-24-a2-*.md.
int glyph_left_bearing(unsigned char c);

// --- Marcas del MENU (overlay) -------------------------------------------------------------------
// El menu lo dibuja el overlay: para una letra acentuada se pinta la letra base TAL CUAL (color0)
// + una MARCA centrada encima (ver tools/text/menu_marks.py). Asi no se deforman las mayusculas.
//
// Busca `cp` (codepoint Unicode) en la tabla de acentuados/simbolos del menu. Si esta: `value` =
// valor de la letra base (0 = sin letra, simbolo suelto) y `mark` = indice de marca. false si no.
bool menu_char(unsigned cp, unsigned& value, int& mark);

// UV de un glifo por su VALOR (0..255). false si esta fuera.
bool value_uv(unsigned value, unsigned& x, unsigned& y);

// Valor de glifo del motor para un CODEPOINT kana (hiragana/katakana y 'ー'), segun la tabla
// generada en include/hh/jp_kana.h. false si el codepoint no es kana de la fuente (p. ej. kanji).
bool jp_kana_value(unsigned cp, unsigned& value);

// Marca horneada en el atlas: UV, tamaño y `dy` = offset vertical en px de glifo relativo al TOPE
// de la letra (negativo = por encima). false si el indice no es valido.
bool mark_info(int mark, unsigned& x, unsigned& y, unsigned& w, unsigned& h, int& dy);

}  // namespace game
}  // namespace hh::font
