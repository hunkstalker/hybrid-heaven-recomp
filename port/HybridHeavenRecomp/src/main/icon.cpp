#ifdef _WIN32
#define SDL_MAIN_HANDLED
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include <cstdint>
#include <cstring>
#include <vector>

#include "hh.h"

#include "../../assets/icon_bmp.inc"

static uint32_t read_le32(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint16_t read_le16(const uint8_t* p) {
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

void hh::set_window_icon(SDL_Window* window) {
    const uint8_t* d = kHybridHeavenIconBmp;
    if (kHybridHeavenIconBmpSize < 54 || d[0] != 'B' || d[1] != 'M') {
        return;
    }

    uint32_t data_offset = read_le32(d + 10);
    uint32_t dib_size = read_le32(d + 14);
    if (dib_size < 40 || data_offset >= kHybridHeavenIconBmpSize) {
        return;
    }

    int32_t width = (int32_t)read_le32(d + 18);
    int32_t raw_height = (int32_t)read_le32(d + 22);
    uint16_t bit_count = read_le16(d + 28);
    uint32_t compression = read_le32(d + 30);

    if (width <= 0 || raw_height == 0 || bit_count != 32 || compression != 0) {
        return;
    }

    int32_t height = raw_height < 0 ? -raw_height : raw_height;
    int32_t stride = width * 4;
    if (data_offset + (uint64_t)stride * height > kHybridHeavenIconBmpSize) {
        return;
    }

    static std::vector<uint8_t> flipped;
    flipped.resize((size_t)stride * height);

    for (int32_t y = 0; y < height; y++) {
        int32_t src_row = raw_height > 0 ? (height - 1 - y) : y;
        std::memcpy(&flipped[(size_t)y * stride], d + data_offset + (size_t)src_row * stride, (size_t)stride);
    }

    static SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
        flipped.data(), (int)width, (int)height, 32, stride, SDL_PIXELFORMAT_BGRA32
    );

    if (surface != nullptr) {
        SDL_SetWindowIcon(window, surface);
    }
}