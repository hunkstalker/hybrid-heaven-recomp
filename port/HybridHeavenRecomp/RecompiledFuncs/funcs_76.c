#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801c1ee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1EE4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C1EE8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C1EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1EF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1EF4: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C1EF8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1EFC: addiu       $v0, $v0, 0xB00
    ctx->r2 = ADD32(ctx->r2, 0XB00);
    // 0x801C1F00: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C1F04: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C1F08: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C1F0C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C1F10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C1F14: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1F18: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C1F1C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C1F20: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C1F24: addiu       $a1, $a1, 0x1F40
    ctx->r5 = ADD32(ctx->r5, 0X1F40);
    // 0x801C1F28: jal         0x800058DC
    // 0x801C1F2C: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1F2C: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C1F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1F38: jr          $ra
    // 0x801C1F3C: nop

    return;
    // 0x801C1F3C: nop

;}
RECOMP_FUNC void M8_FUN_801c1f40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1F40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C1F44: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C1F48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C1F4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C1F50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C1F54: addiu       $t7, $t7, 0xB00
    ctx->r15 = ADD32(ctx->r15, 0XB00);
    // 0x801C1F58: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C1F5C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C1F60: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C1F64: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C1F68: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C1F6C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C1F70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C1F74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C1F78: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C1F7C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C1F80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C1F84: jal         0x8012CE9C
    // 0x801C1F88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C1F88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C1F8C: bne         $v0, $zero, L_801C2020
    if (ctx->r2 != 0) {
        // 0x801C1F90: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801C2020;
    }
    // 0x801C1F90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C1F94: jal         0x80010550
    // 0x801C1F98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C1F98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801C1F9C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C1FA0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C1FA4: lhu         $a0, 0x194($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X194);
    // 0x801C1FA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C1FAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C1FB0: bne         $a0, $at, L_801C1FD4
    if (ctx->r4 != ctx->r1) {
        // 0x801C1FB4: sh          $t1, 0x196($v1)
        MEM_H(0X196, ctx->r3) = ctx->r9;
            goto L_801C1FD4;
    }
    // 0x801C1FB4: sh          $t1, 0x196($v1)
    MEM_H(0X196, ctx->r3) = ctx->r9;
    // 0x801C1FB8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1FBC: addiu       $a1, $a1, 0x1A34
    ctx->r5 = ADD32(ctx->r5, 0X1A34);
    // 0x801C1FC0: jal         0x800058DC
    // 0x801C1FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C1FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801C1FC8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C1FCC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C1FD0: lhu         $a0, 0x194($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X194);
L_801C1FD4:
    // 0x801C1FD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C1FD8: bne         $a0, $at, L_801C2020
    if (ctx->r4 != ctx->r1) {
        // 0x801C1FDC: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_801C2020;
    }
    // 0x801C1FDC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801C1FE0: lhu         $t3, 0xEF0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C1FE4: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C1FE8: sh          $t2, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r10;
    // 0x801C1FEC: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x801C1FF0: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C1FF4: sh          $t4, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r12;
    // 0x801C1FF8: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x801C1FFC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2000: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C2004: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x801C2008: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x801C200C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801C2010: lw          $t7, 0xEFC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C2014: sw          $t7, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->r15;
    // 0x801C2018: jal         0x800058DC
    // 0x801C201C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C201C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_801C2020:
    // 0x801C2020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C2028: jr          $ra
    // 0x801C202C: nop

    return;
    // 0x801C202C: nop

;}
RECOMP_FUNC void M8_FUN_801c2030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2034: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C2038: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C203C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2040: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2044: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2048: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C204C: addiu       $v0, $v0, 0xB00
    ctx->r2 = ADD32(ctx->r2, 0XB00);
    // 0x801C2050: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C2054: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C2058: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C205C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C2060: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C2064: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2068: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C206C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C2070: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C2074: addiu       $a1, $a1, 0x2090
    ctx->r5 = ADD32(ctx->r5, 0X2090);
    // 0x801C2078: jal         0x800058DC
    // 0x801C207C: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C207C: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C2080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2088: jr          $ra
    // 0x801C208C: nop

    return;
    // 0x801C208C: nop

;}
RECOMP_FUNC void M8_FUN_801c2090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C2094: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C209C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C20A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C20A4: addiu       $t7, $t7, 0xB00
    ctx->r15 = ADD32(ctx->r15, 0XB00);
    // 0x801C20A8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C20AC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C20B0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C20B4: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C20B8: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C20BC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C20C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C20C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C20C8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C20CC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C20D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C20D4: jal         0x8012CE9C
    // 0x801C20D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C20D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C20DC: bne         $v0, $zero, L_801C2100
    if (ctx->r2 != 0) {
        // 0x801C20E0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801C2100;
    }
    // 0x801C20E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C20E4: jal         0x80010550
    // 0x801C20E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C20E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801C20EC: beq         $v0, $zero, L_801C2100
    if (ctx->r2 == 0) {
        // 0x801C20F0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_801C2100;
    }
    // 0x801C20F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C20F4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C20F8: jal         0x800058DC
    // 0x801C20FC: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C20FC: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    after_2:
L_801C2100:
    // 0x801C2100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2104: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C2108: jr          $ra
    // 0x801C210C: nop

    return;
    // 0x801C210C: nop

;}
RECOMP_FUNC void M8_FUN_801c2110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2114: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C2118: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C211C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2120: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2124: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2128: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C212C: addiu       $v0, $v0, 0xB00
    ctx->r2 = ADD32(ctx->r2, 0XB00);
    // 0x801C2130: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C2134: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C2138: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C213C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C2140: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C2144: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2148: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C214C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C2150: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C2154: addiu       $a1, $a1, 0x2170
    ctx->r5 = ADD32(ctx->r5, 0X2170);
    // 0x801C2158: jal         0x800058DC
    // 0x801C215C: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C215C: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C2160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2168: jr          $ra
    // 0x801C216C: nop

    return;
    // 0x801C216C: nop

;}
RECOMP_FUNC void M8_FUN_801c2170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C2174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C2178: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C217C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C2180: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C2184: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2188: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C218C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C2190: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C2194: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801C2198: lhu         $t9, 0xF0C($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XF0C);
    // 0x801C219C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C21A0: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C21A4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x801C21A8: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x801C21AC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801C21B0: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x801C21B4: lw          $a2, 0x1A0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1A0);
    // 0x801C21B8: jal         0x8012A7F4
    // 0x801C21BC: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_0;
    // 0x801C21BC: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    after_0:
    // 0x801C21C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C21C4: jal         0x8012AEE0
    // 0x801C21C8: lw          $a1, 0xF04($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF04);
    LOOKUP_FUNC(0x8012AEE0)(rdram, ctx);
        goto after_1;
    // 0x801C21C8: lw          $a1, 0xF04($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF04);
    after_1:
    // 0x801C21CC: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x801C21D0: lhu         $t3, 0xF0C($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XF0C);
    // 0x801C21D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C21D8: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801C21DC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801C21E0: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x801C21E4: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x801C21E8: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
    // 0x801C21EC: lw          $a2, 0x1A0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1A0);
    // 0x801C21F0: jal         0x8012AE54
    // 0x801C21F4: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_2;
    // 0x801C21F4: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    after_2:
    // 0x801C21F8: bne         $v0, $zero, L_801C2214
    if (ctx->r2 != 0) {
        // 0x801C21FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C2214;
    }
    // 0x801C21FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2200: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2204: jal         0x800058DC
    // 0x801C2208: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C2208: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    after_3:
    // 0x801C220C: b           L_801C2290
    // 0x801C2210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2290;
    // 0x801C2210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2214:
    // 0x801C2214: lhu         $t5, 0x194($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X194);
    // 0x801C2218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C221C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C2220: bne         $t5, $at, L_801C224C
    if (ctx->r13 != ctx->r1) {
        // 0x801C2224: addiu       $t8, $t8, 0xB00
        ctx->r24 = ADD32(ctx->r24, 0XB00);
            goto L_801C224C;
    }
    // 0x801C2224: addiu       $t8, $t8, 0xB00
    ctx->r24 = ADD32(ctx->r24, 0XB00);
    // 0x801C2228: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801C222C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C2230: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2234: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    // 0x801C2238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C223C: jal         0x800058DC
    // 0x801C2240: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2240: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    after_4:
    // 0x801C2244: b           L_801C2290
    // 0x801C2248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2290;
    // 0x801C2248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C224C:
    // 0x801C224C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801C2250: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x801C2254: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C2258: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801C225C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801C2260: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2264: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2268: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C226C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801C2270: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801C2274: jal         0x8012CE9C
    // 0x801C2278: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_5;
    // 0x801C2278: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_5:
    // 0x801C227C: bne         $v0, $zero, L_801C228C
    if (ctx->r2 != 0) {
        // 0x801C2280: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_801C228C;
    }
    // 0x801C2280: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C2284: jal         0x80010550
    // 0x801C2288: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x801C2288: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
L_801C228C:
    // 0x801C228C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2290:
    // 0x801C2290: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2294: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C2298: jr          $ra
    // 0x801C229C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C229C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c22a0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c22a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C22A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C22A4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C22A8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C22AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C22B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C22B4: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C22B8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C22BC: addiu       $v0, $v0, 0xB00
    ctx->r2 = ADD32(ctx->r2, 0XB00);
    // 0x801C22C0: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C22C4: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C22C8: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C22CC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C22D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C22D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C22D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C22DC: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C22E0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C22E4: addiu       $a1, $a1, 0x2300
    ctx->r5 = ADD32(ctx->r5, 0X2300);
    // 0x801C22E8: jal         0x800058DC
    // 0x801C22EC: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C22EC: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C22F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C22F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C22F8: jr          $ra
    // 0x801C22FC: nop

    return;
    // 0x801C22FC: nop

;}
RECOMP_FUNC void M8_FUN_801c2300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C2304: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C2308: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C230C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C2310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C2314: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C2318: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C231C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2320: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C2324: lhu         $t8, 0xF0C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XF0C);
    // 0x801C2328: lw          $s1, 0x5C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X5C);
    // 0x801C232C: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x801C2330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C2334: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x801C2338: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C233C: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x801C2340: lw          $a2, 0x1A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1A0);
    // 0x801C2344: jal         0x8012A7F4
    // 0x801C2348: lw          $a1, 0x198($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X198);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_0;
    // 0x801C2348: lw          $a1, 0x198($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X198);
    after_0:
    // 0x801C234C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2350: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2354: lw          $a1, 0xF04($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XF04);
    // 0x801C2358: jal         0x8012AEE0
    // 0x801C235C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012AEE0)(rdram, ctx);
        goto after_1;
    // 0x801C235C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C2360: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801C2364: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2368: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C236C: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801C2370: lhu         $t2, 0xF0C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XF0C);
    // 0x801C2374: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C2378: lh          $t1, 0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X12);
    // 0x801C237C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801C2380: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x801C2384: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x801C2388: lhu         $a0, 0x194($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X194);
    // 0x801C238C: bnel        $a0, $at, L_801C23DC
    if (ctx->r4 != ctx->r1) {
        // 0x801C2390: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C23DC;
    }
    goto skip_0;
    // 0x801C2390: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x801C2394: lhu         $t5, 0xEF0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C2398: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C239C: sh          $t4, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r12;
    // 0x801C23A0: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x801C23A4: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C23A8: sh          $t6, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r14;
    // 0x801C23AC: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x801C23B0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C23B4: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C23B8: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x801C23BC: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x801C23C0: lw          $t9, 0xEFC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C23C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C23C8: jal         0x800058DC
    // 0x801C23CC: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C23CC: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    after_2:
    // 0x801C23D0: b           L_801C2484
    // 0x801C23D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2484;
    // 0x801C23D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C23D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801C23DC:
    // 0x801C23DC: bne         $a0, $at, L_801C2404
    if (ctx->r4 != ctx->r1) {
        // 0x801C23E0: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_801C2404;
    }
    // 0x801C23E0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801C23E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C23E8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C23EC: sh          $t0, 0x78($s1)
    MEM_H(0X78, ctx->r17) = ctx->r8;
    // 0x801C23F0: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    // 0x801C23F4: jal         0x800058DC
    // 0x801C23F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C23F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801C23FC: b           L_801C2484
    // 0x801C2400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2484;
    // 0x801C2400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2404:
    // 0x801C2404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C2408: lw          $a1, 0x198($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X198);
    // 0x801C240C: jal         0x8012AE54
    // 0x801C2410: lw          $a2, 0x1A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1A0);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_4;
    // 0x801C2410: lw          $a2, 0x1A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1A0);
    after_4:
    // 0x801C2414: bne         $v0, $zero, L_801C243C
    if (ctx->r2 != 0) {
        // 0x801C2418: lui         $t2, 0x801E
        ctx->r10 = S32(0X801E << 16);
            goto L_801C243C;
    }
    // 0x801C2418: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801C241C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C2420: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2424: sh          $t1, 0x78($s1)
    MEM_H(0X78, ctx->r17) = ctx->r9;
    // 0x801C2428: addiu       $a1, $a1, 0x2494
    ctx->r5 = ADD32(ctx->r5, 0X2494);
    // 0x801C242C: jal         0x800058DC
    // 0x801C2430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C2430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801C2434: b           L_801C2484
    // 0x801C2438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2484;
    // 0x801C2438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C243C:
    // 0x801C243C: addiu       $t2, $t2, 0xB00
    ctx->r10 = ADD32(ctx->r10, 0XB00);
    // 0x801C2440: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801C2444: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801C2448: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C244C: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x801C2450: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x801C2454: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2458: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C245C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C2460: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801C2464: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801C2468: jal         0x8012CE9C
    // 0x801C246C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_6;
    // 0x801C246C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x801C2470: bne         $v0, $zero, L_801C2480
    if (ctx->r2 != 0) {
        // 0x801C2474: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_801C2480;
    }
    // 0x801C2474: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2478: jal         0x80010550
    // 0x801C247C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_7;
    // 0x801C247C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
L_801C2480:
    // 0x801C2480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2484:
    // 0x801C2484: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2488: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C248C: jr          $ra
    // 0x801C2490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C2490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c2494(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c2494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2494: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C2498: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C249C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C24A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C24A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C24A8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C24AC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801C24B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C24B4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C24B8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x801C24BC: sw          $t7, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r15;
    // 0x801C24C0: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x801C24C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C24C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C24CC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C24D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C24D4: lw          $a3, 0x1A0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1A0);
    // 0x801C24D8: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x801C24DC: lw          $a1, 0x198($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X198);
    // 0x801C24E0: jal         0x8012AAE8
    // 0x801C24E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012AAE8)(rdram, ctx);
        goto after_0;
    // 0x801C24E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801C24E8: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x801C24EC: addiu       $t0, $t0, -0x7B00
    ctx->r8 = ADD32(ctx->r8, -0X7B00);
    // 0x801C24F0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C24F4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801C24F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C24FC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801C2500: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801C2504: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2508: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801C250C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C2510: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C2514: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C2518: jal         0x8012CE9C
    // 0x801C251C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_1;
    // 0x801C251C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x801C2520: bne         $v0, $zero, L_801C2568
    if (ctx->r2 != 0) {
        // 0x801C2524: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_801C2568;
    }
    // 0x801C2524: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C2528: jal         0x80010550
    // 0x801C252C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801C252C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801C2530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C2534: lw          $a1, 0xF14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XF14);
    // 0x801C2538: lw          $a2, 0xF18($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XF18);
    // 0x801C253C: jal         0x8012A7F4
    // 0x801C2540: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_3;
    // 0x801C2540: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_3:
    // 0x801C2544: bne         $v0, $zero, L_801C2568
    if (ctx->r2 != 0) {
        // 0x801C2548: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_801C2568;
    }
    // 0x801C2548: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x801C254C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C2550: sh          $v0, 0x78($t4)
    MEM_H(0X78, ctx->r12) = ctx->r2;
    // 0x801C2554: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2558: sh          $v0, 0x196($s1)
    MEM_H(0X196, ctx->r17) = ctx->r2;
    // 0x801C255C: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    // 0x801C2560: jal         0x800058DC
    // 0x801C2564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801C2568:
    // 0x801C2568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C256C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2570: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C2574: jr          $ra
    // 0x801C2578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C2578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c257c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c257c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C257C: nop

;}
RECOMP_FUNC void M8_FUN_801c2580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C2584: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C2588: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C258C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C2590: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2594: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C2598: jal         0x801C3BBC
    // 0x801C259C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801C3BBC)(rdram, ctx);
        goto after_0;
    // 0x801C259C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801C25A0: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x801C25A4: beq         $at, $zero, L_801C27EC
    if (ctx->r1 == 0) {
        // 0x801C25A8: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_801C27EC;
    }
    // 0x801C25A8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x801C25AC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801C25B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C25B4: addu        $at, $at, $t6
    gpr jr_addend_801C25BC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801C25B8: lw          $t6, 0x292C($at)
    ctx->r14 = ADD32(ctx->r1, 0X292C);
    // 0x801C25BC: jr          $t6
    // 0x801C25C0: nop

    switch (jr_addend_801C25BC >> 2) {
        case 0: goto L_801C280C; break;
        case 1: goto L_801C25C4; break;
        case 2: goto L_801C261C; break;
        case 3: goto L_801C2674; break;
        case 4: goto L_801C26BC; break;
        case 5: goto L_801C274C; break;
        case 6: goto L_801C2794; break;
        default: switch_error(__func__, 0x801C25BC, 0x801E292C);
    }
    // 0x801C25C0: nop

L_801C25C4:
    // 0x801C25C4: jal         0x801C3B10
    // 0x801C25C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B10)(rdram, ctx);
        goto after_1;
    // 0x801C25C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801C25CC: jal         0x801C3BAC
    // 0x801C25D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_2;
    // 0x801C25D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C25D4: jal         0x801C3B2C
    // 0x801C25D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B2C)(rdram, ctx);
        goto after_3;
    // 0x801C25D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801C25DC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C25E0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C25E4: lwc1        $f4, 0x1E0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1E0);
    // 0x801C25E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C25EC: jal         0x801C3BF0
    // 0x801C25F0: swc1        $f4, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C3BF0)(rdram, ctx);
        goto after_4;
    // 0x801C25F0: swc1        $f4, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x801C25F4: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x801C25F8: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x801C25FC: jal         0x801C3B5C
    // 0x801C2600: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_5;
    // 0x801C2600: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    after_5:
    // 0x801C2604: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2608: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C260C: jal         0x800058DC
    // 0x801C2610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C2610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801C2614: b           L_801C2810
    // 0x801C2618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2810;
    // 0x801C2618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C261C:
    // 0x801C261C: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x801C2620: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x801C2624: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C2628: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x801C262C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C2630: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x801C2634: lw          $t1, 0x1C8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C8);
    // 0x801C2638: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C263C: sh          $zero, 0xB14($at)
    MEM_H(0XB14, ctx->r1) = 0;
    // 0x801C2640: sw          $t1, 0xB10($at)
    MEM_W(0XB10, ctx->r1) = ctx->r9;
    // 0x801C2644: lhu         $t2, 0x1C4($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X1C4);
    // 0x801C2648: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C264C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2650: sh          $t2, 0xB16($at)
    MEM_H(0XB16, ctx->r1) = ctx->r10;
    // 0x801C2654: lwc1        $f6, 0x1CC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x801C2658: addiu       $a1, $a1, 0x2820
    ctx->r5 = ADD32(ctx->r5, 0X2820);
    // 0x801C265C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C2660: swc1        $f6, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f6.u32l;
    // 0x801C2664: jal         0x800058DC
    // 0x801C2668: sh          $t3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C2668: sh          $t3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r11;
    after_7:
    // 0x801C266C: b           L_801C2810
    // 0x801C2670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2810;
    // 0x801C2670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2674:
    // 0x801C2674: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C2678: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C267C: lw          $t4, 0x1BC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1BC);
    // 0x801C2680: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2684: sh          $zero, 0xB14($at)
    MEM_H(0XB14, ctx->r1) = 0;
    // 0x801C2688: sw          $t4, 0xB10($at)
    MEM_W(0XB10, ctx->r1) = ctx->r12;
    // 0x801C268C: lhu         $t5, 0x1B8($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X1B8);
    // 0x801C2690: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C2694: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2698: sh          $t5, 0xB16($at)
    MEM_H(0XB16, ctx->r1) = ctx->r13;
    // 0x801C269C: lwc1        $f8, 0x1C0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x801C26A0: addiu       $a1, $a1, 0x29BC
    ctx->r5 = ADD32(ctx->r5, 0X29BC);
    // 0x801C26A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C26A8: swc1        $f8, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f8.u32l;
    // 0x801C26AC: jal         0x800058DC
    // 0x801C26B0: sh          $t6, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C26B0: sh          $t6, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r14;
    after_8:
    // 0x801C26B4: b           L_801C2810
    // 0x801C26B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2810;
    // 0x801C26B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C26BC:
    // 0x801C26BC: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x801C26C0: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x801C26C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C26C8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x801C26CC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C26D0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x801C26D4: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x801C26D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C26DC: sh          $zero, 0xB14($at)
    MEM_H(0XB14, ctx->r1) = 0;
    // 0x801C26E0: sw          $t9, 0xB10($at)
    MEM_W(0XB10, ctx->r1) = ctx->r25;
    // 0x801C26E4: lhu         $t0, 0x1B8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1B8);
    // 0x801C26E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C26EC: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801C26F0: sh          $t0, 0xB16($at)
    MEM_H(0XB16, ctx->r1) = ctx->r8;
    // 0x801C26F4: lwc1        $f10, 0x1C0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x801C26F8: addiu       $t2, $t2, 0xB10
    ctx->r10 = ADD32(ctx->r10, 0XB10);
    // 0x801C26FC: lui         $t5, 0xFF
    ctx->r13 = S32(0XFF << 16);
    // 0x801C2700: swc1        $f10, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f10.u32l;
    // 0x801C2704: sh          $t1, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r9;
    // 0x801C2708: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801C270C: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x801C2710: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C2714: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801C2718: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x801C271C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C2720: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C2724: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x801C2728: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C272C: jal         0x8013A1B4
    // 0x801C2730: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_9;
    // 0x801C2730: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_9:
    // 0x801C2734: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2738: addiu       $a1, $a1, 0x2A74
    ctx->r5 = ADD32(ctx->r5, 0X2A74);
    // 0x801C273C: jal         0x800058DC
    // 0x801C2740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801C2740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801C2744: b           L_801C2810
    // 0x801C2748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2810;
    // 0x801C2748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C274C:
    // 0x801C274C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C2750: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C2754: lw          $t6, 0x1BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1BC);
    // 0x801C2758: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C275C: sh          $zero, 0xB14($at)
    MEM_H(0XB14, ctx->r1) = 0;
    // 0x801C2760: sw          $t6, 0xB10($at)
    MEM_W(0XB10, ctx->r1) = ctx->r14;
    // 0x801C2764: lhu         $t7, 0x1B8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B8);
    // 0x801C2768: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C276C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2770: sh          $t7, 0xB16($at)
    MEM_H(0XB16, ctx->r1) = ctx->r15;
    // 0x801C2774: lwc1        $f16, 0x1C0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x801C2778: addiu       $a1, $a1, 0x2B00
    ctx->r5 = ADD32(ctx->r5, 0X2B00);
    // 0x801C277C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C2780: swc1        $f16, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f16.u32l;
    // 0x801C2784: jal         0x800058DC
    // 0x801C2788: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801C2788: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_11:
    // 0x801C278C: b           L_801C2810
    // 0x801C2790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2810;
    // 0x801C2790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2794:
    // 0x801C2794: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x801C2798: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x801C279C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C27A0: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x801C27A4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C27A8: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x801C27AC: lw          $t1, 0x1C8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C8);
    // 0x801C27B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C27B4: sh          $zero, 0xB14($at)
    MEM_H(0XB14, ctx->r1) = 0;
    // 0x801C27B8: sw          $t1, 0xB10($at)
    MEM_W(0XB10, ctx->r1) = ctx->r9;
    // 0x801C27BC: lhu         $t2, 0x1C4($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X1C4);
    // 0x801C27C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C27C4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C27C8: sh          $t2, 0xB16($at)
    MEM_H(0XB16, ctx->r1) = ctx->r10;
    // 0x801C27CC: lwc1        $f18, 0x1CC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x801C27D0: addiu       $a1, $a1, 0x2C80
    ctx->r5 = ADD32(ctx->r5, 0X2C80);
    // 0x801C27D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C27D8: swc1        $f18, 0xB18($at)
    MEM_W(0XB18, ctx->r1) = ctx->f18.u32l;
    // 0x801C27DC: jal         0x800058DC
    // 0x801C27E0: sh          $t3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x801C27E0: sh          $t3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r11;
    after_12:
    // 0x801C27E4: b           L_801C2810
    // 0x801C27E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2810;
    // 0x801C27E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C27EC:
    // 0x801C27EC: jal         0x801C3B10
    // 0x801C27F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B10)(rdram, ctx);
        goto after_13;
    // 0x801C27F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x801C27F4: jal         0x801C3BAC
    // 0x801C27F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_14;
    // 0x801C27F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x801C27FC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2800: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C2804: jal         0x800058DC
    // 0x801C2808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x801C2808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_801C280C:
    // 0x801C280C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2810:
    // 0x801C2810: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C2814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C2818: jr          $ra
    // 0x801C281C: nop

    return;
    // 0x801C281C: nop

;}
RECOMP_FUNC void M8_FUN_801c2820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2820: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C2824: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C2828: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C282C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C2830: lhu         $v0, 0x1B4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B4);
    // 0x801C2834: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C2838: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C283C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801C2840: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2844: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x801C2848: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C284C: beq         $t7, $zero, L_801C2870
    if (ctx->r15 == 0) {
        // 0x801C2850: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_801C2870;
    }
    // 0x801C2850: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801C2854: andi        $t8, $v0, 0xFFFE
    ctx->r24 = ctx->r2 & 0XFFFE;
    // 0x801C2858: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C285C: sh          $t8, 0x1B4($s0)
    MEM_H(0X1B4, ctx->r16) = ctx->r24;
    // 0x801C2860: jal         0x800058DC
    // 0x801C2864: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2864: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C2868: b           L_801C29AC
    // 0x801C286C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C29AC;
    // 0x801C286C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2870:
    // 0x801C2870: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801C2874: lhu         $t1, 0x1D0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X1D0);
    // 0x801C2878: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C287C: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801C2880: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x801C2884: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x801C2888: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801C288C: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x801C2890: lw          $a2, 0x1BC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1BC);
    // 0x801C2894: jal         0x8012A7F4
    // 0x801C2898: lw          $a1, 0x1B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1B8);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_1;
    // 0x801C2898: lw          $a1, 0x1B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1B8);
    after_1:
    // 0x801C289C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C28A0: jal         0x8012AEE0
    // 0x801C28A4: lw          $a1, 0x1C0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C0);
    LOOKUP_FUNC(0x8012AEE0)(rdram, ctx);
        goto after_2;
    // 0x801C28A4: lw          $a1, 0x1C0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C0);
    after_2:
    // 0x801C28A8: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x801C28AC: lhu         $t5, 0x1D0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X1D0);
    // 0x801C28B0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C28B4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C28B8: addiu       $t7, $t7, 0xB10
    ctx->r15 = ADD32(ctx->r15, 0XB10);
    // 0x801C28BC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C28C0: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x801C28C4: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x801C28C8: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x801C28CC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C28D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801C28D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x801C28D8: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C28DC: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C28E0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C28E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C28E8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C28EC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C28F0: jal         0x8012CE9C
    // 0x801C28F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_3;
    // 0x801C28F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x801C28F8: bne         $v0, $zero, L_801C29A8
    if (ctx->r2 != 0) {
        // 0x801C28FC: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_801C29A8;
    }
    // 0x801C28FC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x801C2900: jal         0x80010550
    // 0x801C2904: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_4;
    // 0x801C2904: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x801C2908: lhu         $v1, 0x1D2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1D2);
    // 0x801C290C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801C2910: beq         $v1, $zero, L_801C2954
    if (ctx->r3 == 0) {
        // 0x801C2914: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_801C2954;
    }
    // 0x801C2914: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x801C2918: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801C291C: bne         $t2, $zero, L_801C2954
    if (ctx->r10 != 0) {
        // 0x801C2920: sh          $t1, 0x1D2($s0)
        MEM_H(0X1D2, ctx->r16) = ctx->r9;
            goto L_801C2954;
    }
    // 0x801C2920: sh          $t1, 0x1D2($s0)
    MEM_H(0X1D2, ctx->r16) = ctx->r9;
    // 0x801C2924: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C2928: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801C292C: jal         0x801C3C3C
    // 0x801C2930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3C3C)(rdram, ctx);
        goto after_5;
    // 0x801C2930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801C2934: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x801C2938: lwc1        $f4, 0x1B8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1B8);
    // 0x801C293C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C2940: swc1        $f4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f4.u32l;
    // 0x801C2944: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x801C2948: lwc1        $f6, 0x1BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1BC);
    // 0x801C294C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C2950: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
L_801C2954:
    // 0x801C2954: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2958: lw          $a1, 0x1B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1B8);
    // 0x801C295C: lw          $a2, 0x1BC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1BC);
    // 0x801C2960: jal         0x8012AE54
    // 0x801C2964: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_6;
    // 0x801C2964: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_6:
    // 0x801C2968: beq         $v0, $zero, L_801C2978
    if (ctx->r2 == 0) {
        // 0x801C296C: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_801C2978;
    }
    // 0x801C296C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2970: beql        $t8, $zero, L_801C29AC
    if (ctx->r24 == 0) {
        // 0x801C2974: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801C29AC;
    }
    goto skip_0;
    // 0x801C2974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_801C2978:
    // 0x801C2978: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C297C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C2980: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x801C2984: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x801C2988: jal         0x801C3BAC
    // 0x801C298C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_7;
    // 0x801C298C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    after_7:
    // 0x801C2990: jal         0x801C3B48
    // 0x801C2994: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_8;
    // 0x801C2994: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_8:
    // 0x801C2998: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C299C: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    // 0x801C29A0: jal         0x800058DC
    // 0x801C29A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801C29A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
L_801C29A8:
    // 0x801C29A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C29AC:
    // 0x801C29AC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C29B0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C29B4: jr          $ra
    // 0x801C29B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C29B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c29bc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c29bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C29BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C29C0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C29C4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C29C8: lhu         $v0, 0x1B4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B4);
    // 0x801C29CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C29D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C29D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C29D8: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x801C29DC: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x801C29E0: beq         $t8, $zero, L_801C2A04
    if (ctx->r24 == 0) {
        // 0x801C29E4: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_801C2A04;
    }
    // 0x801C29E4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801C29E8: andi        $t9, $v0, 0xFFFE
    ctx->r25 = ctx->r2 & 0XFFFE;
    // 0x801C29EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C29F0: sh          $t9, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r25;
    // 0x801C29F4: jal         0x800058DC
    // 0x801C29F8: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C29F8: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C29FC: b           L_801C2A68
    // 0x801C2A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C2A68;
    // 0x801C2A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2A04:
    // 0x801C2A04: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C2A08: addiu       $t0, $t0, 0xB10
    ctx->r8 = ADD32(ctx->r8, 0XB10);
    // 0x801C2A0C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C2A10: lhu         $t3, 0x1C4($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X1C4);
    // 0x801C2A14: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2A18: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801C2A1C: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801C2A20: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2A24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C2A28: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C2A2C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C2A30: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C2A34: jal         0x80011140
    // 0x801C2A38: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x801C2A38: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x801C2A3C: beql        $v0, $zero, L_801C2A68
    if (ctx->r2 == 0) {
        // 0x801C2A40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C2A68;
    }
    goto skip_0;
    // 0x801C2A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801C2A44: jal         0x801C3BAC
    // 0x801C2A48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_2;
    // 0x801C2A48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C2A4C: jal         0x801C3B48
    // 0x801C2A50: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_3;
    // 0x801C2A50: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x801C2A54: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2A58: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    // 0x801C2A5C: jal         0x800058DC
    // 0x801C2A60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2A60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x801C2A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2A68:
    // 0x801C2A68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C2A6C: jr          $ra
    // 0x801C2A70: nop

    return;
    // 0x801C2A70: nop

;}
RECOMP_FUNC void M8_FUN_801c2a74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2A74: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2A78: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2A7C: lhu         $v0, 0x1B4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c2a80(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c2a80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2A88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2A8C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x801C2A90: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801C2A94: beq         $t6, $zero, L_801C2AB8
    if (ctx->r14 == 0) {
        // 0x801C2A98: lw          $a2, 0x5C($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X5C);
            goto L_801C2AB8;
    }
    // 0x801C2A98: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2A9C: andi        $t7, $v0, 0xFFFE
    ctx->r15 = ctx->r2 & 0XFFFE;
    // 0x801C2AA0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2AA4: sh          $t7, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r15;
    // 0x801C2AA8: jal         0x800058DC
    // 0x801C2AAC: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2AAC: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C2AB0: b           L_801C2AF4
    // 0x801C2AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C2AF4;
    // 0x801C2AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2AB8:
    // 0x801C2AB8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2ABC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801C2AC0: jal         0x80010550
    // 0x801C2AC4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C2AC4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x801C2AC8: beql        $v0, $zero, L_801C2AF4
    if (ctx->r2 == 0) {
        // 0x801C2ACC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C2AF4;
    }
    goto skip_0;
    // 0x801C2ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C2AD0: jal         0x801C3BAC
    // 0x801C2AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_2;
    // 0x801C2AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C2AD8: jal         0x801C3B48
    // 0x801C2ADC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_3;
    // 0x801C2ADC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x801C2AE0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2AE4: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    // 0x801C2AE8: jal         0x800058DC
    // 0x801C2AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801C2AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2AF4:
    // 0x801C2AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2AF8: jr          $ra
    // 0x801C2AFC: nop

    return;
    // 0x801C2AFC: nop

;}
RECOMP_FUNC void M8_FUN_801c2b00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C2B04: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2B08: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2B0C: lhu         $v0, 0x1B4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B4);
    // 0x801C2B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C2B14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C2B18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C2B1C: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2B20: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x801C2B24: beq         $t8, $zero, L_801C2B48
    if (ctx->r24 == 0) {
        // 0x801C2B28: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_801C2B48;
    }
    // 0x801C2B28: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801C2B2C: andi        $t9, $v0, 0xFFFE
    ctx->r25 = ctx->r2 & 0XFFFE;
    // 0x801C2B30: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2B34: sh          $t9, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r25;
    // 0x801C2B38: jal         0x800058DC
    // 0x801C2B3C: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2B3C: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C2B40: b           L_801C2BD0
    // 0x801C2B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C2BD0;
    // 0x801C2B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2B48:
    // 0x801C2B48: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C2B4C: addiu       $t0, $t0, 0xB10
    ctx->r8 = ADD32(ctx->r8, 0XB10);
    // 0x801C2B50: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C2B54: lhu         $t3, 0x1C4($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X1C4);
    // 0x801C2B58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2B5C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801C2B60: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801C2B64: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2B68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C2B6C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C2B70: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C2B74: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C2B78: jal         0x80011140
    // 0x801C2B7C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x801C2B7C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x801C2B80: beq         $v0, $zero, L_801C2BCC
    if (ctx->r2 == 0) {
        // 0x801C2B84: lui         $t4, 0x801E
        ctx->r12 = S32(0X801E << 16);
            goto L_801C2BCC;
    }
    // 0x801C2B84: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C2B88: addiu       $t4, $t4, 0xB10
    ctx->r12 = ADD32(ctx->r12, 0XB10);
    // 0x801C2B8C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801C2B90: lui         $t7, 0xFF
    ctx->r15 = S32(0XFF << 16);
    // 0x801C2B94: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x801C2B98: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x801C2B9C: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x801C2BA0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C2BA4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2BA8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C2BAC: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x801C2BB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C2BB4: jal         0x8013A1B4
    // 0x801C2BB8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_2;
    // 0x801C2BB8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801C2BBC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2BC0: addiu       $a1, $a1, 0x2BDC
    ctx->r5 = ADD32(ctx->r5, 0X2BDC);
    // 0x801C2BC4: jal         0x800058DC
    // 0x801C2BC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C2BC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_801C2BCC:
    // 0x801C2BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2BD0:
    // 0x801C2BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C2BD4: jr          $ra
    // 0x801C2BD8: nop

    return;
    // 0x801C2BD8: nop

;}
RECOMP_FUNC void M8_FUN_801c2bdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2BDC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2BE0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2BE4: lhu         $v0, 0x1B4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c2be8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c2be8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2BE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C2BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2BF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C2BF4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x801C2BF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801C2BFC: beq         $t6, $zero, L_801C2C20
    if (ctx->r14 == 0) {
        // 0x801C2C00: lw          $a2, 0x5C($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X5C);
            goto L_801C2C20;
    }
    // 0x801C2C00: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2C04: andi        $t7, $v0, 0xFFFE
    ctx->r15 = ctx->r2 & 0XFFFE;
    // 0x801C2C08: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2C0C: sh          $t7, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r15;
    // 0x801C2C10: jal         0x800058DC
    // 0x801C2C14: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2C14: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C2C18: b           L_801C2C74
    // 0x801C2C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C2C74;
    // 0x801C2C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2C20:
    // 0x801C2C20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801C2C24: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801C2C28: jal         0x80010550
    // 0x801C2C2C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C2C2C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x801C2C30: beql        $v0, $zero, L_801C2C74
    if (ctx->r2 == 0) {
        // 0x801C2C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C2C74;
    }
    goto skip_0;
    // 0x801C2C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C2C38: jal         0x801C3BAC
    // 0x801C2C3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_2;
    // 0x801C2C3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C2C40: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2C44: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    // 0x801C2C48: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x801C2C4C: jal         0x800058DC
    // 0x801C2C50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C2C50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801C2C54: jal         0x801C3BAC
    // 0x801C2C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_4;
    // 0x801C2C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801C2C5C: jal         0x801C3B48
    // 0x801C2C60: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_5;
    // 0x801C2C60: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x801C2C64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C2C68: jal         0x800058DC
    // 0x801C2C6C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C2C6C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x801C2C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2C74:
    // 0x801C2C74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C2C78: jr          $ra
    // 0x801C2C7C: nop

    return;
    // 0x801C2C7C: nop

;}
RECOMP_FUNC void M8_FUN_801c2c80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2C80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C2C84: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C2C88: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C2C8C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C2C90: lhu         $v0, 0x1B4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B4);
    // 0x801C2C94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C2C98: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C2C9C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801C2CA0: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2CA4: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x801C2CA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C2CAC: beq         $t7, $zero, L_801C2CD0
    if (ctx->r15 == 0) {
        // 0x801C2CB0: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_801C2CD0;
    }
    // 0x801C2CB0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801C2CB4: andi        $t8, $v0, 0xFFFE
    ctx->r24 = ctx->r2 & 0XFFFE;
    // 0x801C2CB8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2CBC: sh          $t8, 0x1B4($s0)
    MEM_H(0X1B4, ctx->r16) = ctx->r24;
    // 0x801C2CC0: jal         0x800058DC
    // 0x801C2CC4: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2CC4: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C2CC8: b           L_801C2E10
    // 0x801C2CCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C2E10;
    // 0x801C2CCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2CD0:
    // 0x801C2CD0: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801C2CD4: lhu         $t1, 0x1D0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X1D0);
    // 0x801C2CD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2CDC: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801C2CE0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x801C2CE4: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x801C2CE8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801C2CEC: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x801C2CF0: lw          $a2, 0x1BC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1BC);
    // 0x801C2CF4: jal         0x8012A7F4
    // 0x801C2CF8: lw          $a1, 0x1B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1B8);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_1;
    // 0x801C2CF8: lw          $a1, 0x1B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1B8);
    after_1:
    // 0x801C2CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2D00: jal         0x8012AEE0
    // 0x801C2D04: lw          $a1, 0x1C0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C0);
    LOOKUP_FUNC(0x8012AEE0)(rdram, ctx);
        goto after_2;
    // 0x801C2D04: lw          $a1, 0x1C0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C0);
    after_2:
    // 0x801C2D08: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x801C2D0C: lhu         $t5, 0x1D0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X1D0);
    // 0x801C2D10: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2D14: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C2D18: addiu       $t7, $t7, 0xB10
    ctx->r15 = ADD32(ctx->r15, 0XB10);
    // 0x801C2D1C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C2D20: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x801C2D24: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x801C2D28: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x801C2D2C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C2D30: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801C2D34: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x801C2D38: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C2D3C: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C2D40: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2D44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C2D48: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C2D4C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C2D50: jal         0x8012CE9C
    // 0x801C2D54: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_3;
    // 0x801C2D54: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x801C2D58: bne         $v0, $zero, L_801C2E0C
    if (ctx->r2 != 0) {
        // 0x801C2D5C: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_801C2E0C;
    }
    // 0x801C2D5C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x801C2D60: jal         0x80010550
    // 0x801C2D64: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_4;
    // 0x801C2D64: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x801C2D68: lhu         $v1, 0x1D2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1D2);
    // 0x801C2D6C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801C2D70: beq         $v1, $zero, L_801C2DB4
    if (ctx->r3 == 0) {
        // 0x801C2D74: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_801C2DB4;
    }
    // 0x801C2D74: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x801C2D78: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801C2D7C: bne         $t2, $zero, L_801C2DB4
    if (ctx->r10 != 0) {
        // 0x801C2D80: sh          $t1, 0x1D2($s0)
        MEM_H(0X1D2, ctx->r16) = ctx->r9;
            goto L_801C2DB4;
    }
    // 0x801C2D80: sh          $t1, 0x1D2($s0)
    MEM_H(0X1D2, ctx->r16) = ctx->r9;
    // 0x801C2D84: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C2D88: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801C2D8C: jal         0x801C3C3C
    // 0x801C2D90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3C3C)(rdram, ctx);
        goto after_5;
    // 0x801C2D90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801C2D94: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x801C2D98: lwc1        $f4, 0x1B8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1B8);
    // 0x801C2D9C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C2DA0: swc1        $f4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f4.u32l;
    // 0x801C2DA4: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x801C2DA8: lwc1        $f6, 0x1BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1BC);
    // 0x801C2DAC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C2DB0: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
L_801C2DB4:
    // 0x801C2DB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2DB8: lw          $a1, 0x1B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1B8);
    // 0x801C2DBC: lw          $a2, 0x1BC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1BC);
    // 0x801C2DC0: jal         0x8012AE54
    // 0x801C2DC4: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_6;
    // 0x801C2DC4: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_6:
    // 0x801C2DC8: beq         $v0, $zero, L_801C2DD8
    if (ctx->r2 == 0) {
        // 0x801C2DCC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_801C2DD8;
    }
    // 0x801C2DCC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2DD0: beql        $t8, $zero, L_801C2E10
    if (ctx->r24 == 0) {
        // 0x801C2DD4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801C2E10;
    }
    goto skip_0;
    // 0x801C2DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_801C2DD8:
    // 0x801C2DD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C2DDC: lui         $t9, 0x168
    ctx->r25 = S32(0X168 << 16);
    // 0x801C2DE0: ori         $t9, $t9, 0x41
    ctx->r25 = ctx->r25 | 0X41;
    // 0x801C2DE4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2DE8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2DEC: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x801C2DF0: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x801C2DF4: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x801C2DF8: sw          $t9, 0xB10($at)
    MEM_W(0XB10, ctx->r1) = ctx->r25;
    // 0x801C2DFC: sh          $zero, 0xB16($at)
    MEM_H(0XB16, ctx->r1) = 0;
    // 0x801C2E00: addiu       $a1, $a1, 0x2E20
    ctx->r5 = ADD32(ctx->r5, 0X2E20);
    // 0x801C2E04: jal         0x800058DC
    // 0x801C2E08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C2E08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_801C2E0C:
    // 0x801C2E0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C2E10:
    // 0x801C2E10: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2E14: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C2E18: jr          $ra
    // 0x801C2E1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C2E1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c2e20(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c2e20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2E20: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2E24: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c2e28(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c2e28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2E28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C2E2C: lhu         $v0, 0x1B4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B4);
    // 0x801C2E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C2E34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C2E38: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C2E3C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x801C2E40: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801C2E44: beq         $t7, $zero, L_801C2E68
    if (ctx->r15 == 0) {
        // 0x801C2E48: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_801C2E68;
    }
    // 0x801C2E48: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801C2E4C: andi        $t8, $v0, 0xFFFE
    ctx->r24 = ctx->r2 & 0XFFFE;
    // 0x801C2E50: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2E54: sh          $t8, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r24;
    // 0x801C2E58: jal         0x800058DC
    // 0x801C2E5C: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2E5C: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_0:
    // 0x801C2E60: b           L_801C2F00
    // 0x801C2E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C2F00;
    // 0x801C2E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2E68:
    // 0x801C2E68: lw          $t9, 0xE0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE0);
    // 0x801C2E6C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801C2E70: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801C2E74: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C2E78: lh          $a1, 0x1D4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X1D4);
    // 0x801C2E7C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    // 0x801C2E80: jal         0x801FD284
    // 0x801C2E84: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801FD284)(rdram, ctx);
        goto after_1;
    // 0x801C2E84: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x801C2E88: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2E8C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2E90: lw          $t1, 0xE0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE0);
    // 0x801C2E94: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C2E98: addiu       $t3, $t3, 0xB10
    ctx->r11 = ADD32(ctx->r11, 0XB10);
    // 0x801C2E9C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C2EA0: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x801C2EA4: sh          $v0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r2;
    // 0x801C2EA8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801C2EAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C2EB0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2EB4: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x801C2EB8: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x801C2EBC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C2EC0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C2EC4: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801C2EC8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801C2ECC: jal         0x80011140
    // 0x801C2ED0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x801C2ED0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x801C2ED4: beql        $v0, $zero, L_801C2F00
    if (ctx->r2 == 0) {
        // 0x801C2ED8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C2F00;
    }
    goto skip_0;
    // 0x801C2ED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801C2EDC: jal         0x801C3BAC
    // 0x801C2EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_3;
    // 0x801C2EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801C2EE4: jal         0x801C3B48
    // 0x801C2EE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_4;
    // 0x801C2EE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x801C2EEC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2EF0: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    // 0x801C2EF4: jal         0x800058DC
    // 0x801C2EF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C2EF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801C2EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2F00:
    // 0x801C2F00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C2F04: jr          $ra
    // 0x801C2F08: nop

    return;
    // 0x801C2F08: nop

;}
RECOMP_FUNC void M8_FUN_801c2f0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2F14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C2F18: jal         0x801C3B20
    // 0x801C2F1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B20)(rdram, ctx);
        goto after_0;
    // 0x801C2F1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C2F20: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801C2F24: bnel        $at, $zero, L_801C2FE8
    if (ctx->r1 != 0) {
        // 0x801C2F28: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C2FE8;
    }
    goto skip_0;
    // 0x801C2F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C2F2C: jal         0x801C3B3C
    // 0x801C2F30: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_1;
    // 0x801C2F30: nop

    after_1:
    // 0x801C2F34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C2F38: bne         $v0, $at, L_801C2FE4
    if (ctx->r2 != ctx->r1) {
        // 0x801C2F3C: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801C2FE4;
    }
    // 0x801C2F3C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2F40: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2F44: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2F48: beq         $v0, $zero, L_801C2F98
    if (ctx->r2 == 0) {
        // 0x801C2F4C: nop
    
            goto L_801C2F98;
    }
    // 0x801C2F4C: nop

    // 0x801C2F50: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C2F54: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C2F58: addiu       $t6, $t6, -0x4258
    ctx->r14 = ADD32(ctx->r14, -0X4258);
    // 0x801C2F5C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x801C2F60: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x801C2F64: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x801C2F68: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x801C2F6C: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x801C2F70: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x801C2F74: sw          $t7, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r15;
    // 0x801C2F78: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x801C2F7C: sw          $t8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r24;
    // 0x801C2F80: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x801C2F84: sw          $t7, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r15;
    // 0x801C2F88: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x801C2F8C: sw          $t8, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r24;
    // 0x801C2F90: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x801C2F94: sw          $t7, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r15;
L_801C2F98:
    // 0x801C2F98: jal         0x801C3BBC
    // 0x801C2F9C: sh          $zero, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = 0;
    LOOKUP_FUNC(0x801C3BBC)(rdram, ctx);
        goto after_2;
    // 0x801C2F9C: sh          $zero, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = 0;
    after_2:
    // 0x801C2FA0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C2FA4: beq         $v0, $zero, L_801C2FB8
    if (ctx->r2 == 0) {
        // 0x801C2FA8: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_801C2FB8;
    }
    // 0x801C2FA8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C2FAC: lhu         $t9, 0x1B4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1B4);
    // 0x801C2FB0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801C2FB4: sh          $t0, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r8;
L_801C2FB8:
    // 0x801C2FB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2FBC: lwc1        $f4, 0xB18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB18);
    // 0x801C2FC0: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x801C2FC4: jal         0x801C3BAC
    // 0x801C2FC8: swc1        $f4, 0x1E0($v1)
    MEM_W(0X1E0, ctx->r3) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C3BAC)(rdram, ctx);
        goto after_3;
    // 0x801C2FC8: swc1        $f4, 0x1E0($v1)
    MEM_W(0X1E0, ctx->r3) = ctx->f4.u32l;
    after_3:
    // 0x801C2FCC: jal         0x801C3B5C
    // 0x801C2FD0: nop

    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_4;
    // 0x801C2FD0: nop

    after_4:
    // 0x801C2FD4: jal         0x801C3BBC
    // 0x801C2FD8: nop

    LOOKUP_FUNC(0x801C3BBC)(rdram, ctx);
        goto after_5;
    // 0x801C2FD8: nop

    after_5:
    // 0x801C2FDC: b           L_801C2FE8
    // 0x801C2FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C2FE8;
    // 0x801C2FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C2FE4:
    // 0x801C2FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C2FE8:
    // 0x801C2FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2FF0: jr          $ra
    // 0x801C2FF4: nop

    return;
    // 0x801C2FF4: nop

;}
RECOMP_FUNC void M8_FUN_801c2ff8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3000: jal         0x801C3B20
    // 0x801C3004: nop

    LOOKUP_FUNC(0x801C3B20)(rdram, ctx);
        goto after_0;
    // 0x801C3004: nop

    after_0:
    // 0x801C3008: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801C300C: bnel        $at, $zero, L_801C3034
    if (ctx->r1 != 0) {
        // 0x801C3010: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C3034;
    }
    goto skip_0;
    // 0x801C3010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C3014: jal         0x801C3B3C
    // 0x801C3018: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_1;
    // 0x801C3018: nop

    after_1:
    // 0x801C301C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3020: bnel        $v0, $at, L_801C3034
    if (ctx->r2 != ctx->r1) {
        // 0x801C3024: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C3034;
    }
    goto skip_1;
    // 0x801C3024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801C3028: b           L_801C3034
    // 0x801C302C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C3034;
    // 0x801C302C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C3030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C3034:
    // 0x801C3034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C303C: jr          $ra
    // 0x801C3040: nop

    return;
    // 0x801C3040: nop

;}
RECOMP_FUNC void M8_FUN_801c3044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C304C: jal         0x801C3BBC
    // 0x801C3050: nop

    LOOKUP_FUNC(0x801C3BBC)(rdram, ctx);
        goto after_0;
    // 0x801C3050: nop

    after_0:
    // 0x801C3054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C305C: jr          $ra
    // 0x801C3060: nop

    return;
    // 0x801C3060: nop

;}
RECOMP_FUNC void M8_FUN_801c3064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3064: nop

    // 0x801C3068: nop

    // 0x801C306C: nop

;}
RECOMP_FUNC void M8_FUN_801c3070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C307C: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801C3080: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C3084: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801C3088: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x801C308C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3090: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801C3094: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x801C3098: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C309C: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x801C30A0: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x801C30A4: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x801C30A8: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x801C30AC: lhu         $t1, 0x1D8($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X1D8);
    // 0x801C30B0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801C30B4: sh          $zero, 0x1DA($v0)
    MEM_H(0X1DA, ctx->r2) = 0;
    // 0x801C30B8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801C30BC: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x801C30C0: beq         $at, $zero, L_801C3164
    if (ctx->r1 == 0) {
        // 0x801C30C4: sh          $t0, 0x1DC($v0)
        MEM_H(0X1DC, ctx->r2) = ctx->r8;
            goto L_801C3164;
    }
    // 0x801C30C4: sh          $t0, 0x1DC($v0)
    MEM_H(0X1DC, ctx->r2) = ctx->r8;
    // 0x801C30C8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801C30CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C30D0: addu        $at, $at, $t2
    gpr jr_addend_801C30D8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801C30D4: lw          $t2, 0x29AC($at)
    ctx->r10 = ADD32(ctx->r1, 0X29AC);
    // 0x801C30D8: jr          $t2
    // 0x801C30DC: nop

    switch (jr_addend_801C30D8 >> 2) {
        case 0: goto L_801C30E0; break;
        case 1: goto L_801C30F4; break;
        case 2: goto L_801C3108; break;
        case 3: goto L_801C311C; break;
        case 4: goto L_801C3130; break;
        case 5: goto L_801C3144; break;
        case 6: goto L_801C3158; break;
        default: switch_error(__func__, 0x801C30D8, 0x801E29AC);
    }
    // 0x801C30DC: nop

L_801C30E0:
    // 0x801C30E0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C30E4: jal         0x800058DC
    // 0x801C30E8: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C30E8: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    after_0:
    // 0x801C30EC: b           L_801C3168
    // 0x801C30F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3168;
    // 0x801C30F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C30F4:
    // 0x801C30F4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C30F8: jal         0x800058DC
    // 0x801C30FC: addiu       $a1, $a1, 0x3698
    ctx->r5 = ADD32(ctx->r5, 0X3698);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C30FC: addiu       $a1, $a1, 0x3698
    ctx->r5 = ADD32(ctx->r5, 0X3698);
    after_1:
    // 0x801C3100: b           L_801C3168
    // 0x801C3104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3168;
    // 0x801C3104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3108:
    // 0x801C3108: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C310C: jal         0x800058DC
    // 0x801C3110: addiu       $a1, $a1, 0x3468
    ctx->r5 = ADD32(ctx->r5, 0X3468);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C3110: addiu       $a1, $a1, 0x3468
    ctx->r5 = ADD32(ctx->r5, 0X3468);
    after_2:
    // 0x801C3114: b           L_801C3168
    // 0x801C3118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3168;
    // 0x801C3118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C311C:
    // 0x801C311C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3120: jal         0x800058DC
    // 0x801C3124: addiu       $a1, $a1, 0x35B8
    ctx->r5 = ADD32(ctx->r5, 0X35B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C3124: addiu       $a1, $a1, 0x35B8
    ctx->r5 = ADD32(ctx->r5, 0X35B8);
    after_3:
    // 0x801C3128: b           L_801C3168
    // 0x801C312C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3168;
    // 0x801C312C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3130:
    // 0x801C3130: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3134: jal         0x800058DC
    // 0x801C3138: addiu       $a1, $a1, 0x3828
    ctx->r5 = ADD32(ctx->r5, 0X3828);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C3138: addiu       $a1, $a1, 0x3828
    ctx->r5 = ADD32(ctx->r5, 0X3828);
    after_4:
    // 0x801C313C: b           L_801C3168
    // 0x801C3140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3168;
    // 0x801C3140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3144:
    // 0x801C3144: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3148: jal         0x800058DC
    // 0x801C314C: addiu       $a1, $a1, 0x3A1C
    ctx->r5 = ADD32(ctx->r5, 0X3A1C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C314C: addiu       $a1, $a1, 0x3A1C
    ctx->r5 = ADD32(ctx->r5, 0X3A1C);
    after_5:
    // 0x801C3150: b           L_801C3168
    // 0x801C3154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3168;
    // 0x801C3154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3158:
    // 0x801C3158: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C315C: jal         0x800058DC
    // 0x801C3160: addiu       $a1, $a1, 0x32EC
    ctx->r5 = ADD32(ctx->r5, 0X32EC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C3160: addiu       $a1, $a1, 0x32EC
    ctx->r5 = ADD32(ctx->r5, 0X32EC);
    after_6:
L_801C3164:
    // 0x801C3164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3168:
    // 0x801C3168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C316C: jr          $ra
    // 0x801C3170: nop

    return;
    // 0x801C3170: nop

;}
RECOMP_FUNC void M8_FUN_801c3174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C317C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C3180: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801C3184: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C3188: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801C318C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x801C3190: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3194: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C3198: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801C319C: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x801C31A0: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, 0XB20);
    // 0x801C31A4: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x801C31A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C31AC: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x801C31B0: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x801C31B4: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x801C31B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C31BC: lui         $t0, 0x168
    ctx->r8 = S32(0X168 << 16);
    // 0x801C31C0: ori         $t0, $t0, 0x41
    ctx->r8 = ctx->r8 | 0X41;
    // 0x801C31C4: addiu       $t1, $zero, 0x1100
    ctx->r9 = ADD32(0, 0X1100);
    // 0x801C31C8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801C31CC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C31D0: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x801C31D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C31D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C31DC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C31E0: addiu       $a1, $a1, 0x31FC
    ctx->r5 = ADD32(ctx->r5, 0X31FC);
    // 0x801C31E4: jal         0x800058DC
    // 0x801C31E8: sh          $t2, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C31E8: sh          $t2, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r10;
    after_0:
    // 0x801C31EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C31F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C31F4: jr          $ra
    // 0x801C31F8: nop

    return;
    // 0x801C31F8: nop

;}
RECOMP_FUNC void M8_FUN_801c31fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C31FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C3200: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C3204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C3208: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C320C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C3210: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, 0XB20);
    // 0x801C3214: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C3218: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C321C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C3220: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C3224: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C3228: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C322C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3230: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C3234: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C3238: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C323C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C3240: jal         0x8012CE9C
    // 0x801C3244: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C3244: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C3248: bne         $v0, $zero, L_801C32DC
    if (ctx->r2 != 0) {
        // 0x801C324C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801C32DC;
    }
    // 0x801C324C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C3250: jal         0x80010550
    // 0x801C3254: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C3254: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801C3258: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C325C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C3260: lhu         $a0, 0x1DA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1DA);
    // 0x801C3264: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C3268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C326C: bne         $a0, $at, L_801C3290
    if (ctx->r4 != ctx->r1) {
        // 0x801C3270: sh          $t1, 0x1DC($v1)
        MEM_H(0X1DC, ctx->r3) = ctx->r9;
            goto L_801C3290;
    }
    // 0x801C3270: sh          $t1, 0x1DC($v1)
    MEM_H(0X1DC, ctx->r3) = ctx->r9;
    // 0x801C3274: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3278: addiu       $a1, $a1, 0x3070
    ctx->r5 = ADD32(ctx->r5, 0X3070);
    // 0x801C327C: jal         0x800058DC
    // 0x801C3280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C3280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801C3284: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3288: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C328C: lhu         $a0, 0x1DA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1DA);
L_801C3290:
    // 0x801C3290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3294: bne         $a0, $at, L_801C32DC
    if (ctx->r4 != ctx->r1) {
        // 0x801C3298: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_801C32DC;
    }
    // 0x801C3298: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801C329C: lhu         $t3, 0xEF0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C32A0: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C32A4: sh          $t2, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r10;
    // 0x801C32A8: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x801C32AC: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C32B0: sh          $t4, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r12;
    // 0x801C32B4: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x801C32B8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C32BC: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C32C0: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x801C32C4: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x801C32C8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801C32CC: lw          $t7, 0xEFC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C32D0: sw          $t7, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->r15;
    // 0x801C32D4: jal         0x800058DC
    // 0x801C32D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C32D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_801C32DC:
    // 0x801C32DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C32E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C32E4: jr          $ra
    // 0x801C32E8: nop

    return;
    // 0x801C32E8: nop

;}
RECOMP_FUNC void M8_FUN_801c32ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C32EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C32F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C32F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C32F8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801C32FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C3300: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801C3304: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x801C3308: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C330C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C3310: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801C3314: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x801C3318: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, 0XB20);
    // 0x801C331C: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x801C3320: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C3324: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x801C3328: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x801C332C: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x801C3330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C3334: lui         $t0, 0x168
    ctx->r8 = S32(0X168 << 16);
    // 0x801C3338: ori         $t0, $t0, 0x41
    ctx->r8 = ctx->r8 | 0X41;
    // 0x801C333C: addiu       $t1, $zero, 0x1100
    ctx->r9 = ADD32(0, 0X1100);
    // 0x801C3340: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801C3344: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C3348: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x801C334C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C3350: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3354: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C3358: addiu       $a1, $a1, 0x3374
    ctx->r5 = ADD32(ctx->r5, 0X3374);
    // 0x801C335C: jal         0x800058DC
    // 0x801C3360: sh          $t2, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C3360: sh          $t2, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r10;
    after_0:
    // 0x801C3364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C336C: jr          $ra
    // 0x801C3370: nop

    return;
    // 0x801C3370: nop

;}
RECOMP_FUNC void M8_FUN_801c3374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3374: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C3378: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C337C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C3380: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C3384: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C3388: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, 0XB20);
    // 0x801C338C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C3390: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3394: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C3398: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C339C: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C33A0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C33A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C33A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C33AC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C33B0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C33B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C33B8: jal         0x8012CE9C
    // 0x801C33BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C33BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C33C0: bne         $v0, $zero, L_801C33EC
    if (ctx->r2 != 0) {
        // 0x801C33C4: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801C33EC;
    }
    // 0x801C33C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C33C8: jal         0x80010550
    // 0x801C33CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C33CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801C33D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C33D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C33D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C33DC: sh          $t1, -0x4234($at)
    MEM_H(-0X4234, ctx->r1) = ctx->r9;
    // 0x801C33E0: addiu       $a1, $a1, 0x33FC
    ctx->r5 = ADD32(ctx->r5, 0X33FC);
    // 0x801C33E4: jal         0x800058DC
    // 0x801C33E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C33E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_801C33EC:
    // 0x801C33EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C33F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C33F4: jr          $ra
    // 0x801C33F8: nop

    return;
    // 0x801C33F8: nop

;}
RECOMP_FUNC void M8_FUN_801c33fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C33FC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3400: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C3404: lhu         $t6, 0x1DA($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1DA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3408(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C340C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3414: bne         $t6, $at, L_801C3458
    if (ctx->r14 != ctx->r1) {
        // 0x801C3418: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C3458;
    }
    // 0x801C3418: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C341C: lhu         $t8, 0xEF0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C3420: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C3424: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801C3428: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801C342C: sh          $t7, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r15;
    // 0x801C3430: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C3434: sh          $t9, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r25;
    // 0x801C3438: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801C343C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C3440: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C3444: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x801C3448: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    // 0x801C344C: lw          $t2, 0xEFC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C3450: jal         0x800058DC
    // 0x801C3454: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C3454: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    after_0:
L_801C3458:
    // 0x801C3458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C345C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3460: jr          $ra
    // 0x801C3464: nop

    return;
    // 0x801C3464: nop

;}
RECOMP_FUNC void M8_FUN_801c3468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C346C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C3470: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C3474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3478: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C347C: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3480: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C3484: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, 0XB20);
    // 0x801C3488: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C348C: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C3490: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C3494: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C3498: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C349C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C34A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C34A4: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C34A8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C34AC: addiu       $a1, $a1, 0x34C8
    ctx->r5 = ADD32(ctx->r5, 0X34C8);
    // 0x801C34B0: jal         0x800058DC
    // 0x801C34B4: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C34B4: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C34B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C34BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C34C0: jr          $ra
    // 0x801C34C4: nop

    return;
    // 0x801C34C4: nop

;}
RECOMP_FUNC void M8_FUN_801c34c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C34C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C34CC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C34D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C34D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C34D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C34DC: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, 0XB20);
    // 0x801C34E0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C34E4: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C34E8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C34EC: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C34F0: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C34F4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C34F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C34FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C3500: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C3504: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C3508: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C350C: jal         0x8012CE9C
    // 0x801C3510: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C3510: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C3514: bne         $v0, $zero, L_801C35A8
    if (ctx->r2 != 0) {
        // 0x801C3518: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801C35A8;
    }
    // 0x801C3518: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C351C: jal         0x80010550
    // 0x801C3520: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C3520: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801C3524: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3528: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C352C: lhu         $a0, 0x1DA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1DA);
    // 0x801C3530: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C3534: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C3538: bne         $a0, $at, L_801C355C
    if (ctx->r4 != ctx->r1) {
        // 0x801C353C: sh          $t1, 0x1DC($v1)
        MEM_H(0X1DC, ctx->r3) = ctx->r9;
            goto L_801C355C;
    }
    // 0x801C353C: sh          $t1, 0x1DC($v1)
    MEM_H(0X1DC, ctx->r3) = ctx->r9;
    // 0x801C3540: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3544: addiu       $a1, $a1, 0x3070
    ctx->r5 = ADD32(ctx->r5, 0X3070);
    // 0x801C3548: jal         0x800058DC
    // 0x801C354C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C354C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801C3550: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3554: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C3558: lhu         $a0, 0x1DA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1DA);
L_801C355C:
    // 0x801C355C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3560: bne         $a0, $at, L_801C35A8
    if (ctx->r4 != ctx->r1) {
        // 0x801C3564: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_801C35A8;
    }
    // 0x801C3564: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801C3568: lhu         $t3, 0xEF0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C356C: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C3570: sh          $t2, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r10;
    // 0x801C3574: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x801C3578: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C357C: sh          $t4, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r12;
    // 0x801C3580: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x801C3584: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C3588: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C358C: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x801C3590: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x801C3594: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801C3598: lw          $t7, 0xEFC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C359C: sw          $t7, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->r15;
    // 0x801C35A0: jal         0x800058DC
    // 0x801C35A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C35A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_801C35A8:
    // 0x801C35A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C35AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C35B0: jr          $ra
    // 0x801C35B4: nop

    return;
    // 0x801C35B4: nop

;}
RECOMP_FUNC void M8_FUN_801c35b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C35B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C35BC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C35C0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C35C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C35C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C35CC: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C35D0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C35D4: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, 0XB20);
    // 0x801C35D8: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C35DC: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C35E0: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C35E4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C35E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C35EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C35F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C35F4: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C35F8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C35FC: addiu       $a1, $a1, 0x3618
    ctx->r5 = ADD32(ctx->r5, 0X3618);
    // 0x801C3600: jal         0x800058DC
    // 0x801C3604: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C3604: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C3608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C360C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3610: jr          $ra
    // 0x801C3614: nop

    return;
    // 0x801C3614: nop

;}
RECOMP_FUNC void M8_FUN_801c3618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C361C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C3620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C3624: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C3628: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C362C: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, 0XB20);
    // 0x801C3630: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C3634: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3638: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801C363C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801C3640: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801C3644: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C3648: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C364C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C3650: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C3654: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C3658: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C365C: jal         0x8012CE9C
    // 0x801C3660: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C3660: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C3664: bne         $v0, $zero, L_801C3688
    if (ctx->r2 != 0) {
        // 0x801C3668: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801C3688;
    }
    // 0x801C3668: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C366C: jal         0x80010550
    // 0x801C3670: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801C3670: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801C3674: beq         $v0, $zero, L_801C3688
    if (ctx->r2 == 0) {
        // 0x801C3678: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_801C3688;
    }
    // 0x801C3678: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C367C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3680: jal         0x800058DC
    // 0x801C3684: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C3684: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    after_2:
L_801C3688:
    // 0x801C3688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C368C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C3690: jr          $ra
    // 0x801C3694: nop

    return;
    // 0x801C3694: nop

;}
RECOMP_FUNC void M8_FUN_801c3698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C369C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C36A0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C36A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C36A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C36AC: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C36B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C36B4: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, 0XB20);
    // 0x801C36B8: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C36BC: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C36C0: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C36C4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C36C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C36CC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C36D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C36D4: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C36D8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C36DC: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x801C36E0: jal         0x800058DC
    // 0x801C36E4: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C36E4: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C36E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C36EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C36F0: jr          $ra
    // 0x801C36F4: nop

    return;
    // 0x801C36F4: nop

;}
RECOMP_FUNC void M8_FUN_801c36f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C36F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C36FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C3700: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C3704: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C3708: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C370C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3710: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C3714: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C3718: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C371C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801C3720: lhu         $t9, 0xF0C($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XF0C);
    // 0x801C3724: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C3728: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C372C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x801C3730: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x801C3734: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801C3738: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x801C373C: lw          $a2, 0x1A0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1A0);
    // 0x801C3740: jal         0x8012A7F4
    // 0x801C3744: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_0;
    // 0x801C3744: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    after_0:
    // 0x801C3748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C374C: jal         0x8012AEE0
    // 0x801C3750: lw          $a1, 0xF04($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF04);
    LOOKUP_FUNC(0x8012AEE0)(rdram, ctx);
        goto after_1;
    // 0x801C3750: lw          $a1, 0xF04($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF04);
    after_1:
    // 0x801C3754: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x801C3758: lhu         $t3, 0xF0C($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XF0C);
    // 0x801C375C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C3760: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801C3764: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801C3768: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x801C376C: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x801C3770: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
    // 0x801C3774: lw          $a2, 0x1A0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1A0);
    // 0x801C3778: jal         0x8012AE54
    // 0x801C377C: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_2;
    // 0x801C377C: lw          $a1, 0x198($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X198);
    after_2:
    // 0x801C3780: bne         $v0, $zero, L_801C379C
    if (ctx->r2 != 0) {
        // 0x801C3784: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C379C;
    }
    // 0x801C3784: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C3788: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C378C: jal         0x800058DC
    // 0x801C3790: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C3790: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    after_3:
    // 0x801C3794: b           L_801C3818
    // 0x801C3798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C3818;
    // 0x801C3798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C379C:
    // 0x801C379C: lhu         $t5, 0x1DA($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X1DA);
    // 0x801C37A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C37A4: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C37A8: bne         $t5, $at, L_801C37D4
    if (ctx->r13 != ctx->r1) {
        // 0x801C37AC: addiu       $t8, $t8, 0xB20
        ctx->r24 = ADD32(ctx->r24, 0XB20);
            goto L_801C37D4;
    }
    // 0x801C37AC: addiu       $t8, $t8, 0xB20
    ctx->r24 = ADD32(ctx->r24, 0XB20);
    // 0x801C37B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801C37B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C37B8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C37BC: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    // 0x801C37C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C37C4: jal         0x800058DC
    // 0x801C37C8: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C37C8: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    after_4:
    // 0x801C37CC: b           L_801C3818
    // 0x801C37D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C3818;
    // 0x801C37D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C37D4:
    // 0x801C37D4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801C37D8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x801C37DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C37E0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801C37E4: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801C37E8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C37EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801C37F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C37F4: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801C37F8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801C37FC: jal         0x8012CE9C
    // 0x801C3800: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_5;
    // 0x801C3800: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_5:
    // 0x801C3804: bne         $v0, $zero, L_801C3814
    if (ctx->r2 != 0) {
        // 0x801C3808: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_801C3814;
    }
    // 0x801C3808: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C380C: jal         0x80010550
    // 0x801C3810: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x801C3810: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
L_801C3814:
    // 0x801C3814: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C3818:
    // 0x801C3818: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C381C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C3820: jr          $ra
    // 0x801C3824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C3824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3828(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C382C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C3830: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C3834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3838: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C383C: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3840: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C3844: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, 0XB20);
    // 0x801C3848: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x801C384C: lhu         $t7, 0xF00($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XF00);
    // 0x801C3850: lwc1        $f4, 0xF08($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF08);
    // 0x801C3854: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C3858: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C385C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3860: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C3864: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x801C3868: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C386C: addiu       $a1, $a1, 0x3888
    ctx->r5 = ADD32(ctx->r5, 0X3888);
    // 0x801C3870: jal         0x800058DC
    // 0x801C3874: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C3874: sh          $t8, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r24;
    after_0:
    // 0x801C3878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C387C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3880: jr          $ra
    // 0x801C3884: nop

    return;
    // 0x801C3884: nop

;}
RECOMP_FUNC void M8_FUN_801c3888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3888: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C388C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C3890: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C3894: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C3898: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C389C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C38A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C38A4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C38A8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C38AC: lhu         $t8, 0xF0C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XF0C);
    // 0x801C38B0: lw          $s1, 0x5C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X5C);
    // 0x801C38B4: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x801C38B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C38BC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x801C38C0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C38C4: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x801C38C8: lw          $a2, 0x1A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1A0);
    // 0x801C38CC: jal         0x8012A7F4
    // 0x801C38D0: lw          $a1, 0x198($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X198);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_0;
    // 0x801C38D0: lw          $a1, 0x198($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X198);
    after_0:
    // 0x801C38D4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C38D8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C38DC: lw          $a1, 0xF04($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XF04);
    // 0x801C38E0: jal         0x8012AEE0
    // 0x801C38E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012AEE0)(rdram, ctx);
        goto after_1;
    // 0x801C38E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C38E8: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801C38EC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C38F0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C38F4: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801C38F8: lhu         $t2, 0xF0C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XF0C);
    // 0x801C38FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3900: lh          $t1, 0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X12);
    // 0x801C3904: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801C3908: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x801C390C: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x801C3910: lhu         $a0, 0x1DA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1DA);
    // 0x801C3914: bnel        $a0, $at, L_801C3964
    if (ctx->r4 != ctx->r1) {
        // 0x801C3918: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C3964;
    }
    goto skip_0;
    // 0x801C3918: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x801C391C: lhu         $t5, 0xEF0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C3920: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C3924: sh          $t4, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r12;
    // 0x801C3928: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x801C392C: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C3930: sh          $t6, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r14;
    // 0x801C3934: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x801C3938: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C393C: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C3940: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x801C3944: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x801C3948: lw          $t9, 0xEFC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C394C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3950: jal         0x800058DC
    // 0x801C3954: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C3954: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    after_2:
    // 0x801C3958: b           L_801C3A0C
    // 0x801C395C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C3A0C;
    // 0x801C395C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C3960: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801C3964:
    // 0x801C3964: bne         $a0, $at, L_801C398C
    if (ctx->r4 != ctx->r1) {
        // 0x801C3968: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_801C398C;
    }
    // 0x801C3968: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801C396C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C3970: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3974: sh          $t0, 0x78($s1)
    MEM_H(0X78, ctx->r17) = ctx->r8;
    // 0x801C3978: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    // 0x801C397C: jal         0x800058DC
    // 0x801C3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801C3984: b           L_801C3A0C
    // 0x801C3988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C3A0C;
    // 0x801C3988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C398C:
    // 0x801C398C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3990: lw          $a1, 0x198($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X198);
    // 0x801C3994: jal         0x8012AE54
    // 0x801C3998: lw          $a2, 0x1A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1A0);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_4;
    // 0x801C3998: lw          $a2, 0x1A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1A0);
    after_4:
    // 0x801C399C: bne         $v0, $zero, L_801C39C4
    if (ctx->r2 != 0) {
        // 0x801C39A0: lui         $t2, 0x801E
        ctx->r10 = S32(0X801E << 16);
            goto L_801C39C4;
    }
    // 0x801C39A0: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801C39A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C39A8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C39AC: sh          $t1, 0x78($s1)
    MEM_H(0X78, ctx->r17) = ctx->r9;
    // 0x801C39B0: addiu       $a1, $a1, 0x3A1C
    ctx->r5 = ADD32(ctx->r5, 0X3A1C);
    // 0x801C39B4: jal         0x800058DC
    // 0x801C39B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C39B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801C39BC: b           L_801C3A0C
    // 0x801C39C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C3A0C;
    // 0x801C39C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C39C4:
    // 0x801C39C4: addiu       $t2, $t2, 0xB20
    ctx->r10 = ADD32(ctx->r10, 0XB20);
    // 0x801C39C8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801C39CC: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801C39D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C39D4: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x801C39D8: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x801C39DC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C39E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C39E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C39E8: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801C39EC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801C39F0: jal         0x8012CE9C
    // 0x801C39F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_6;
    // 0x801C39F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x801C39F8: bne         $v0, $zero, L_801C3A08
    if (ctx->r2 != 0) {
        // 0x801C39FC: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_801C3A08;
    }
    // 0x801C39FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3A00: jal         0x80010550
    // 0x801C3A04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_7;
    // 0x801C3A04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
L_801C3A08:
    // 0x801C3A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C3A0C:
    // 0x801C3A0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C3A10: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C3A14: jr          $ra
    // 0x801C3A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C3A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3a1c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3a1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3A1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C3A20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C3A24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C3A28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C3A2C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3A30: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3A34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C3A38: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C3A3C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C3A40: sw          $t7, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r15;
    // 0x801C3A44: lw          $t8, 0xE0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE0);
    // 0x801C3A48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C3A4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C3A50: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C3A54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C3A58: lw          $a3, 0x1A0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1A0);
    // 0x801C3A5C: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x801C3A60: lw          $a1, 0x198($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X198);
    // 0x801C3A64: jal         0x8012AAE8
    // 0x801C3A68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012AAE8)(rdram, ctx);
        goto after_0;
    // 0x801C3A68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801C3A6C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x801C3A70: addiu       $t0, $t0, -0x7B00
    ctx->r8 = ADD32(ctx->r8, -0X7B00);
    // 0x801C3A74: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C3A78: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801C3A7C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C3A80: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801C3A84: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801C3A88: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C3A8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3A90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C3A94: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C3A98: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C3A9C: jal         0x8012CE9C
    // 0x801C3AA0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_1;
    // 0x801C3AA0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x801C3AA4: bne         $v0, $zero, L_801C3AF0
    if (ctx->r2 != 0) {
        // 0x801C3AA8: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_801C3AF0;
    }
    // 0x801C3AA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801C3AAC: jal         0x80010550
    // 0x801C3AB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801C3AB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801C3AB4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3AB8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C3ABC: lw          $a1, 0xF14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XF14);
    // 0x801C3AC0: lw          $a2, 0xF18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XF18);
    // 0x801C3AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3AC8: jal         0x8012A7F4
    // 0x801C3ACC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_3;
    // 0x801C3ACC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_3:
    // 0x801C3AD0: bne         $v0, $zero, L_801C3AF0
    if (ctx->r2 != 0) {
        // 0x801C3AD4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_801C3AF0;
    }
    // 0x801C3AD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3AD8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3ADC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3AE0: addiu       $a1, $a1, 0x3174
    ctx->r5 = ADD32(ctx->r5, 0X3174);
    // 0x801C3AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3AE8: jal         0x800058DC
    // 0x801C3AEC: sh          $t4, 0x78($t5)
    MEM_H(0X78, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C3AEC: sh          $t4, 0x78($t5)
    MEM_H(0X78, ctx->r13) = ctx->r12;
    after_4:
L_801C3AF0:
    // 0x801C3AF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C3AF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C3AF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C3AFC: jr          $ra
    // 0x801C3B00: nop

    return;
    // 0x801C3B00: nop

;}
RECOMP_FUNC void M8_FUN_801c3b04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B04: nop

    // 0x801C3B08: nop

    // 0x801C3B0C: nop

;}
RECOMP_FUNC void M8_FUN_801c3b10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3B14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3B18: jr          $ra
    // 0x801C3B1C: sh          $a0, -0x4282($at)
    MEM_H(-0X4282, ctx->r1) = ctx->r4;
    return;
    // 0x801C3B1C: sh          $a0, -0x4282($at)
    MEM_H(-0X4282, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b20(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B20: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3B24: jr          $ra
    // 0x801C3B28: lhu         $v0, -0x4282($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4282);
    return;
    // 0x801C3B28: lhu         $v0, -0x4282($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4282);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b2c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3B30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3B34: jr          $ra
    // 0x801C3B38: sh          $a0, -0x4280($at)
    MEM_H(-0X4280, ctx->r1) = ctx->r4;
    return;
    // 0x801C3B38: sh          $a0, -0x4280($at)
    MEM_H(-0X4280, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b3c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B3C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3B40: jr          $ra
    // 0x801C3B44: lhu         $v0, -0x4280($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4280);
    return;
    // 0x801C3B44: lhu         $v0, -0x4280($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4280);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b48(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3B4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3B50: sh          $a0, -0x426C($at)
    MEM_H(-0X426C, ctx->r1) = ctx->r4;
    // 0x801C3B54: jr          $ra
    // 0x801C3B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C3B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b5c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B5C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801C3B60: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801C3B64: lhu         $v0, 0x1A4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A4);
    // 0x801C3B68: jr          $ra
    // 0x801C3B6C: sh          $zero, 0x1A4($a0)
    MEM_H(0X1A4, ctx->r4) = 0;
    return;
    // 0x801C3B6C: sh          $zero, 0x1A4($a0)
    MEM_H(0X1A4, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b70(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3B74: jr          $ra
    // 0x801C3B78: sh          $zero, -0x426C($at)
    MEM_H(-0X426C, ctx->r1) = 0;
    return;
    // 0x801C3B78: sh          $zero, -0x426C($at)
    MEM_H(-0X426C, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b7c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B7C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3B80: jr          $ra
    // 0x801C3B84: sw          $a0, -0x4268($at)
    MEM_W(-0X4268, ctx->r1) = ctx->r4;
    return;
    // 0x801C3B84: sw          $a0, -0x4268($at)
    MEM_W(-0X4268, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b88(rdram, ctx);
;}
