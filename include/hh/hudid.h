#pragma once

// Identidades de los elementos 2D del HUD. Adaptado del port de referencia (MIT; ver CREDITS.md y
// licenses/hybrid-heaven-recomp-MIT.txt), `include/hh/hudid.h` (Phase 07, widescreen).
//
// Una direccion sola NO identifica un elemento (docs/findings/phase-07.md de la referencia): el
// segmento 3 se remapea por escena, los overlays comparten direccion de carga, el heap reutiliza
// la misma direccion de textura para imagenes distintas y un color nombra todos los rects de ese
// color. Por eso cada identidad lleva lo que realmente se dibuja:
//
//   tex:<addr imagen>#<hash de sus primeros 64 bytes>
//   dl:<addr lista>#<hash de sus primeros 16 comandos>
//   fill:<color>@<ulx>,<uly>,<lrx>,<lry>   (pixeles 320x240)
//
// Los fills a pantalla completa son *clears*: no tienen identidad.

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>

namespace hh::hudid {

inline uint32_t read_word(const uint8_t* rdram, uint32_t phys) {
    uint32_t v;
    std::memcpy(&v, rdram + (phys & 0x7FFFFC), sizeof v);
    return v;
}

inline uint32_t fnv(uint32_t h, uint32_t word) {
    for (int i = 0; i < 4; ++i) {
        h ^= (word >> (8 * i)) & 0xFF;
        h *= 16777619u;
    }
    return h;
}

inline std::string texture(const uint8_t* rdram, uint32_t address, uint32_t phys) {
    uint32_t h = 2166136261u;
    for (uint32_t i = 0; i < 16; ++i) h = fnv(h, read_word(rdram, phys + 4 * i));
    char buf[40];
    std::snprintf(buf, sizeof buf, "tex:0x%08x#%08x", address, h);
    return buf;
}

inline std::string list(const uint8_t* rdram, uint32_t address, uint32_t phys) {
    uint32_t h = 2166136261u;
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t w0 = read_word(rdram, phys + 8 * i);
        h = fnv(fnv(h, w0), read_word(rdram, phys + 8 * i + 4));
        if ((w0 >> 24) == 0xDF) break;   // G_ENDDL
    }
    char buf[40];
    std::snprintf(buf, sizeof buf, "dl:0x%08x#%08x", address, h);
    return buf;
}

// Coordenadas en pixeles 320x240. Vacio para un clear a pantalla completa.
inline std::string fill(uint32_t colour, int ulx, int uly, int lrx, int lry) {
    if (ulx <= 0 && uly <= 0 && lrx >= 319 && lry >= 239) return std::string();
    char buf[48];
    std::snprintf(buf, sizeof buf, "fill:0x%08x@%d,%d,%d,%d", colour, ulx, uly, lrx, lry);
    return buf;
}

}  // namespace hh::hudid
