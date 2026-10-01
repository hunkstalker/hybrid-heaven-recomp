#pragma once

// hh::ttf — rasterizador de la fuente Work Sans embebida (SIL OFL-1.1; ver assets/fonts/OFL.txt).
//
// El .ttf va INCRUSTADO en el ejecutable (bytes generados por CMake; ver CMakeLists.txt). Al arrancar
// se carga con stb_truetype y se hornea un atlas RGBA8 con la cobertura del glifo en R (mismo contrato
// que el atlas del juego: el pixel shader del overlay usa R como tinta). Sirve para el titulo del
// Area traducido (el juego no tiene glifos para otros idiomas).
//
// No distribuye el .ttf suelto; el overlay lo usa desde memoria.

#include <cstdint>

namespace hh::ttf {

// Construye el atlas (idempotente). Devuelve false si no hay fuente embebida o falla stb.
bool ready();

// Atlas RGBA8 host: cobertura en R (255 = tinta). Valido si ready().
const uint8_t* atlas_rgba8();
unsigned atlas_width();
unsigned atlas_height();

// Metricas (en px del tamano de rasterizado). `ascent` por encima de la linea base (positivo).
float ascent();
float descent();
float line_height();

// Glifo de `cp` (codepoint Unicode): posicion en el atlas, tamano y offsets respecto a la linea base
// (xoff a la izquierda, yoff hacia arriba) y avance. false si no hay glifo.
struct Glyph {
    int x = 0, y = 0, w = 0, h = 0;   // rect en el atlas
    float xoff = 0.0f, yoff = 0.0f;   // offsets desde el origen (linea base) del glifo
    float advance = 0.0f;
    bool ok = false;
};
Glyph glyph(unsigned cp);

// Ancho en px (rasterizado) de la cadena UTF-8 `s`.
float text_width(const char* s);

}  // namespace hh::ttf
