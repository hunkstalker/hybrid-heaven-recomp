#include <stdint.h>

#define KSEG1_OFFSET 0x20000000

#define SP_BASE  0x04000000
#define DPC_BASE 0x04100000
#define VI_BASE  0x04400000
#define AI_BASE  0x04500000
#define PI_BASE  0x04600000
#define RI_BASE  0x04700000
#define SI_BASE  0x04800000

#define MMIO(base, reg) (uint32_t*)(rdram + KSEG1_OFFSET + (base) + (reg))

void init_mmio(uint8_t *rdram) {
    // SP status: halted
    *MMIO(SP_BASE, 0x10) = 0x00000001;
    // VI: all zero (video off)
    *MMIO(VI_BASE, 0x00) = 0x00000000; // VI_STATUS/VI_CTRL
    *MMIO(VI_BASE, 0x04) = 0x00000000; // VI_ORIGIN
    *MMIO(VI_BASE, 0x08) = 0x00000000; // VI_WIDTH
    *MMIO(VI_BASE, 0x10) = 0x00000000; // VI_V_CURRENT
    *MMIO(VI_BASE, 0x18) = 0x00000000; // VI_V_VIDEO (VI_V_SCALE)
    // AI: all zero
    *MMIO(AI_BASE, 0x00) = 0x00000000;
    *MMIO(AI_BASE, 0x04) = 0x00000000;
    // PI status: DMA not busy (game polls (status & 3) and spins while busy)
    *MMIO(PI_BASE, 0x10) = 0x00000000;
    // RI select: standard config
    *MMIO(RI_BASE, 0x00) = 0x00000014;
    // SI status: DMA not busy (game polls (status & 3) and spins while busy)
    *MMIO(SI_BASE, 0x18) = 0x00000000;
}
