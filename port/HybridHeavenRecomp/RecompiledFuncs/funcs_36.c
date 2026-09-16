#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80153008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153008: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8015300C: addiu       $a0, $a0, 0x3AD0
    ctx->r4 = ADD32(ctx->r4, 0X3AD0);
    // 0x80153010: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80153014: lhu         $v0, -0x2272($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2272);
    // 0x80153018: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8015301C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80153020: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80153024: beql        $v0, $t6, L_8015305C
    if (ctx->r2 == ctx->r14) {
        // 0x80153028: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_8015305C;
    }
    goto skip_0;
    // 0x80153028: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    skip_0:
    // 0x8015302C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80153030:
    // 0x80153030: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80153034: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80153038: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x8015303C: mflo        $t7
    ctx->r15 = lo;
    // 0x80153040: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80153044: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80153048: beql        $v0, $t9, L_8015305C
    if (ctx->r2 == ctx->r25) {
        // 0x8015304C: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_8015305C;
    }
    goto skip_1;
    // 0x8015304C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    skip_1:
    // 0x80153050: bnel        $at, $zero, L_80153030
    if (ctx->r1 != 0) {
        // 0x80153054: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80153030;
    }
    goto skip_2;
    // 0x80153054: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80153058: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8015305C:
    // 0x8015305C: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80153060: mflo        $t0
    ctx->r8 = lo;
    // 0x80153064: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80153068: jr          $ra
    // 0x8015306C: lhu         $v0, 0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X8);
    return;
    // 0x8015306C: lhu         $v0, 0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80153070(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80153070(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80153070u);
    return;
}
RECOMP_FUNC void M23_FUN_801bf1a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF1A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF1A8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801BF1AC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF1B0: addiu       $a1, $a1, -0xE24
    ctx->r5 = ADD32(ctx->r5, -0XE24);
    // 0x801BF1B4: jal         0x800058DC
    // 0x801BF1B8: lw          $a0, -0x30C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X30C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801BF1B8: lw          $a0, -0x30C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X30C);
    after_0:
    // 0x801BF1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF1C4: jr          $ra
    // 0x801BF1C8: nop

    return;
    // 0x801BF1C8: nop

;}
RECOMP_FUNC void M23_FUN_801bf1cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801BF1D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801BF1D4: jr          $ra
    // 0x801BF1D8: sw          $a0, -0x30C($at)
    MEM_W(-0X30C, ctx->r1) = ctx->r4;
    return;
    // 0x801BF1D8: sw          $a0, -0x30C($at)
    MEM_W(-0X30C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801bf1dc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801bf1dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF1E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF1E8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801BF1EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF1F0: jal         0x80005670
    // 0x801BF1F4: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801BF1F4: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    after_0:
    // 0x801BF1F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801BF1FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801BF200: addiu       $v0, $v0, -0x310
    ctx->r2 = ADD32(ctx->r2, -0X310);
    // 0x801BF204: addiu       $t7, $t6, 0x90
    ctx->r15 = ADD32(ctx->r14, 0X90);
    // 0x801BF208: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801BF20C: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801BF210: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x801BF214: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x801BF218: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801BF21C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801BF220: jal         0x80002364
    // 0x801BF224: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x801BF224: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801BF228: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF22C: addiu       $a1, $a1, -0xDB8
    ctx->r5 = ADD32(ctx->r5, -0XDB8);
    // 0x801BF230: jal         0x800058DC
    // 0x801BF234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801BF234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801BF238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF23C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF240: jr          $ra
    // 0x801BF244: nop

    return;
    // 0x801BF244: nop

;}
RECOMP_FUNC void M23_FUN_801bf248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF24C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF254: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF258: jal         0x800058DC
    // 0x801BF25C: addiu       $a1, $a1, -0xD78
    ctx->r5 = ADD32(ctx->r5, -0XD78);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801BF25C: addiu       $a1, $a1, -0xD78
    ctx->r5 = ADD32(ctx->r5, -0XD78);
    after_0:
    // 0x801BF260: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801BF264: lw          $v0, -0x310($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X310);
    // 0x801BF268: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x801BF26C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801BF270: jal         0x80152238
    // 0x801BF274: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    LOOKUP_FUNC(0x80152238)(rdram, ctx);
        goto after_1;
    // 0x801BF274: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    after_1:
    // 0x801BF278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF27C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF280: jr          $ra
    // 0x801BF284: nop

    return;
    // 0x801BF284: nop

;}
RECOMP_FUNC void M23_FUN_801bf288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF294: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF298: jal         0x801170DC
    // 0x801BF29C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_0;
    // 0x801BF29C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x801BF2A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801BF2A4: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x801BF2A8: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x801BF2AC: sh          $zero, 0x94($v0)
    MEM_H(0X94, ctx->r2) = 0;
    // 0x801BF2B0: sh          $zero, 0x96($v0)
    MEM_H(0X96, ctx->r2) = 0;
    // 0x801BF2B4: jal         0x801C12B0
    // 0x801BF2B8: sh          $zero, 0x98($v0)
    MEM_H(0X98, ctx->r2) = 0;
    LOOKUP_FUNC(0x801C12B0)(rdram, ctx);
        goto after_1;
    // 0x801BF2B8: sh          $zero, 0x98($v0)
    MEM_H(0X98, ctx->r2) = 0;
    after_1:
    // 0x801BF2BC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF2C0: addiu       $a1, $a1, -0xD24
    ctx->r5 = ADD32(ctx->r5, -0XD24);
    // 0x801BF2C4: jal         0x800058DC
    // 0x801BF2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801BF2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801BF2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF2D4: jr          $ra
    // 0x801BF2D8: nop

    return;
    // 0x801BF2D8: nop

;}
RECOMP_FUNC void M23_FUN_801bf2dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF2DC: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801BF2E0: lbu         $t8, -0x2A52($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2A52);
    // 0x801BF2E4: addiu       $t7, $a0, 0x90
    ctx->r15 = ADD32(ctx->r4, 0X90);
    // 0x801BF2E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801bf2ec(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801bf2ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF2EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801BF2F0: sw          $t7, -0x310($at)
    MEM_W(-0X310, ctx->r1) = ctx->r15;
    // 0x801BF2F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801BF2F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BF2FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801BF300: bne         $t8, $at, L_801BF440
    if (ctx->r24 != ctx->r1) {
        // 0x801BF304: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801BF440;
    }
    // 0x801BF304: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801BF308: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF30C: addiu       $a3, $a3, -0x1900
    ctx->r7 = ADD32(ctx->r7, -0X1900);
    // 0x801BF310: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801BF314: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x801BF318: jal         0x8001B204
    // 0x801BF31C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801BF31C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x801BF320: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF324: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801BF328: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801BF32C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801BF330: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801BF334: addiu       $a3, $a3, -0x18F4
    ctx->r7 = ADD32(ctx->r7, -0X18F4);
    // 0x801BF338: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801BF33C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF340: jal         0x8001B204
    // 0x801BF344: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801BF344: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_1:
    // 0x801BF348: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF34C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801BF350: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801BF354: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801BF358: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801BF35C: addiu       $a3, $a3, -0x18D8
    ctx->r7 = ADD32(ctx->r7, -0X18D8);
    // 0x801BF360: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801BF364: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF368: jal         0x8001B204
    // 0x801BF36C: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801BF36C: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    after_2:
    // 0x801BF370: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF374: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801BF378: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801BF37C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801BF380: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BF384: addiu       $a3, $a3, -0x18BC
    ctx->r7 = ADD32(ctx->r7, -0X18BC);
    // 0x801BF388: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801BF38C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF390: jal         0x8001B204
    // 0x801BF394: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801BF394: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_3:
    // 0x801BF398: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF39C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801BF3A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801BF3A4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801BF3A8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801BF3AC: addiu       $a3, $a3, -0x18A0
    ctx->r7 = ADD32(ctx->r7, -0X18A0);
    // 0x801BF3B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801BF3B4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF3B8: jal         0x8001B204
    // 0x801BF3BC: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801BF3BC: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    after_4:
    // 0x801BF3C0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF3C4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801BF3C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801BF3CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801BF3D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801BF3D4: addiu       $a3, $a3, -0x1884
    ctx->r7 = ADD32(ctx->r7, -0X1884);
    // 0x801BF3D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801BF3DC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF3E0: jal         0x8001B204
    // 0x801BF3E4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801BF3E4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_5:
    // 0x801BF3E8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF3EC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801BF3F0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801BF3F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801BF3F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801BF3FC: addiu       $a3, $a3, -0x1868
    ctx->r7 = ADD32(ctx->r7, -0X1868);
    // 0x801BF400: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801BF404: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF408: jal         0x8001B204
    // 0x801BF40C: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801BF40C: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    after_6:
    // 0x801BF410: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF414: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801BF418: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801BF41C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801BF420: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801BF424: addiu       $a3, $a3, -0x184C
    ctx->r7 = ADD32(ctx->r7, -0X184C);
    // 0x801BF428: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x801BF42C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801BF430: jal         0x8001B204
    // 0x801BF434: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801BF434: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    after_7:
    // 0x801BF438: b           L_801BF5E0
    // 0x801BF43C: nop

        goto L_801BF5E0;
    // 0x801BF43C: nop

L_801BF440:
    // 0x801BF440: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF444: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801BF448: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BF44C: addiu       $a3, $a3, -0x182C
    ctx->r7 = ADD32(ctx->r7, -0X182C);
    // 0x801BF450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801BF454: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801BF458: jal         0x8001B204
    // 0x801BF45C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801BF45C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_8:
    // 0x801BF460: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF464: addiu       $a3, $a3, -0x181C
    ctx->r7 = ADD32(ctx->r7, -0X181C);
    // 0x801BF468: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801BF46C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF470: jal         0x8001B204
    // 0x801BF474: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801BF474: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    after_9:
    // 0x801BF478: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF47C: addiu       $a3, $a3, -0x180C
    ctx->r7 = ADD32(ctx->r7, -0X180C);
    // 0x801BF480: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801BF484: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF488: jal         0x8001B204
    // 0x801BF48C: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801BF48C: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    after_10:
    // 0x801BF490: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF494: addiu       $a3, $a3, -0x1800
    ctx->r7 = ADD32(ctx->r7, -0X1800);
    // 0x801BF498: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801BF49C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF4A0: jal         0x8001B204
    // 0x801BF4A4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801BF4A4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_11:
    // 0x801BF4A8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF4AC: addiu       $a3, $a3, -0x17F4
    ctx->r7 = ADD32(ctx->r7, -0X17F4);
    // 0x801BF4B0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801BF4B4: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF4B8: jal         0x8001B204
    // 0x801BF4BC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801BF4BC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_12:
    // 0x801BF4C0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF4C4: addiu       $a3, $a3, -0x17E8
    ctx->r7 = ADD32(ctx->r7, -0X17E8);
    // 0x801BF4C8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801BF4CC: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF4D0: jal         0x8001B204
    // 0x801BF4D4: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801BF4D4: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    after_13:
    // 0x801BF4D8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF4DC: addiu       $a3, $a3, -0x17DC
    ctx->r7 = ADD32(ctx->r7, -0X17DC);
    // 0x801BF4E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801BF4E4: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF4E8: jal         0x8001B204
    // 0x801BF4EC: addiu       $a2, $zero, 0x5E
    ctx->r6 = ADD32(0, 0X5E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x801BF4EC: addiu       $a2, $zero, 0x5E
    ctx->r6 = ADD32(0, 0X5E);
    after_14:
    // 0x801BF4F0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF4F4: addiu       $a3, $a3, -0x17D0
    ctx->r7 = ADD32(ctx->r7, -0X17D0);
    // 0x801BF4F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801BF4FC: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF500: jal         0x8001B204
    // 0x801BF504: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x801BF504: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    after_15:
    // 0x801BF508: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF50C: addiu       $a3, $a3, -0x17C4
    ctx->r7 = ADD32(ctx->r7, -0X17C4);
    // 0x801BF510: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x801BF514: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF518: jal         0x8001B204
    // 0x801BF51C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_16;
    // 0x801BF51C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_16:
    // 0x801BF520: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF524: addiu       $a3, $a3, -0x17B8
    ctx->r7 = ADD32(ctx->r7, -0X17B8);
    // 0x801BF528: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801BF52C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF530: jal         0x8001B204
    // 0x801BF534: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_17;
    // 0x801BF534: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    after_17:
    // 0x801BF538: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF53C: addiu       $a3, $a3, -0x17AC
    ctx->r7 = ADD32(ctx->r7, -0X17AC);
    // 0x801BF540: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801BF544: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF548: jal         0x8001B204
    // 0x801BF54C: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_18;
    // 0x801BF54C: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    after_18:
    // 0x801BF550: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF554: addiu       $a3, $a3, -0x17A0
    ctx->r7 = ADD32(ctx->r7, -0X17A0);
    // 0x801BF558: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801BF55C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF560: jal         0x8001B204
    // 0x801BF564: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_19;
    // 0x801BF564: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    after_19:
    // 0x801BF568: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF56C: addiu       $a3, $a3, -0x1794
    ctx->r7 = ADD32(ctx->r7, -0X1794);
    // 0x801BF570: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x801BF574: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF578: jal         0x8001B204
    // 0x801BF57C: addiu       $a2, $zero, 0x8E
    ctx->r6 = ADD32(0, 0X8E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_20;
    // 0x801BF57C: addiu       $a2, $zero, 0x8E
    ctx->r6 = ADD32(0, 0X8E);
    after_20:
    // 0x801BF580: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF584: addiu       $a3, $a3, -0x1788
    ctx->r7 = ADD32(ctx->r7, -0X1788);
    // 0x801BF588: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x801BF58C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF590: jal         0x8001B204
    // 0x801BF594: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_21;
    // 0x801BF594: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_21:
    // 0x801BF598: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF59C: addiu       $a3, $a3, -0x177C
    ctx->r7 = ADD32(ctx->r7, -0X177C);
    // 0x801BF5A0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801BF5A4: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF5A8: jal         0x8001B204
    // 0x801BF5AC: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_22;
    // 0x801BF5AC: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    after_22:
    // 0x801BF5B0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF5B4: addiu       $a3, $a3, -0x1770
    ctx->r7 = ADD32(ctx->r7, -0X1770);
    // 0x801BF5B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801BF5BC: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF5C0: jal         0x8001B204
    // 0x801BF5C4: addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_23;
    // 0x801BF5C4: addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    after_23:
    // 0x801BF5C8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF5CC: addiu       $a3, $a3, -0x1764
    ctx->r7 = ADD32(ctx->r7, -0X1764);
    // 0x801BF5D0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x801BF5D4: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801BF5D8: jal         0x8001B204
    // 0x801BF5DC: addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_24;
    // 0x801BF5DC: addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    after_24:
L_801BF5E0:
    // 0x801BF5E0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801BF5E4: lw          $t4, -0x310($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X310);
    // 0x801BF5E8: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801BF5EC: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801BF5F0: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x801BF5F4: lw          $t5, -0x310($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X310);
    // 0x801BF5F8: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x801BF5FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801BF600: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801BF604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BF608: jal         0x80002364
    // 0x801BF60C: sh          $zero, 0x2($t5)
    MEM_H(0X2, ctx->r13) = 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_25;
    // 0x801BF60C: sh          $zero, 0x2($t5)
    MEM_H(0X2, ctx->r13) = 0;
    after_25:
    // 0x801BF610: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF614: addiu       $a1, $a1, -0x9D0
    ctx->r5 = ADD32(ctx->r5, -0X9D0);
    // 0x801BF618: jal         0x800058DC
    // 0x801BF61C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_26;
    // 0x801BF61C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_26:
    // 0x801BF620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801BF624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801BF628: jr          $ra
    // 0x801BF62C: nop

    return;
    // 0x801BF62C: nop

;}
RECOMP_FUNC void M23_FUN_801bf630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF630: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF634: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF638: lhu         $v0, 0x1C8($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X1C8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801bf63c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801bf63c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF63C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801BF640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BF644: andi        $t6, $v0, 0x808
    ctx->r14 = ctx->r2 & 0X808;
    // 0x801BF648: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801BF64C: bne         $t6, $zero, L_801BF664
    if (ctx->r14 != 0) {
        // 0x801BF650: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801BF664;
    }
    // 0x801BF650: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801BF654: lhu         $t7, 0x1D0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X1D0);
    // 0x801BF658: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x801BF65C: beq         $t8, $zero, L_801BF6D0
    if (ctx->r24 == 0) {
        // 0x801BF660: nop
    
            goto L_801BF6D0;
    }
    // 0x801BF660: nop

L_801BF664:
    // 0x801BF664: lbu         $t9, 0x42FE($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X42FE);
    // 0x801BF668: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF66C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801BF670: bne         $t2, $t9, L_801BF6A4
    if (ctx->r10 != ctx->r25) {
        // 0x801BF674: addiu       $t0, $t0, -0x310
        ctx->r8 = ADD32(ctx->r8, -0X310);
            goto L_801BF6A4;
    }
    // 0x801BF674: addiu       $t0, $t0, -0x310
    ctx->r8 = ADD32(ctx->r8, -0X310);
    // 0x801BF678: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801BF67C: addiu       $t0, $t0, -0x310
    ctx->r8 = ADD32(ctx->r8, -0X310);
    // 0x801BF680: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x801BF684: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801BF688: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x801BF68C: bne         $v0, $zero, L_801BF69C
    if (ctx->r2 != 0) {
        // 0x801BF690: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_801BF69C;
    }
    // 0x801BF690: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801BF694: b           L_801BF6C4
    // 0x801BF698: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
        goto L_801BF6C4;
    // 0x801BF698: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
L_801BF69C:
    // 0x801BF69C: b           L_801BF6C4
    // 0x801BF6A0: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
        goto L_801BF6C4;
    // 0x801BF6A0: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_801BF6A4:
    // 0x801BF6A4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x801BF6A8: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x801BF6AC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x801BF6B0: bne         $v0, $zero, L_801BF6C0
    if (ctx->r2 != 0) {
        // 0x801BF6B4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801BF6C0;
    }
    // 0x801BF6B4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801BF6B8: b           L_801BF6C4
    // 0x801BF6BC: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
        goto L_801BF6C4;
    // 0x801BF6BC: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
L_801BF6C0:
    // 0x801BF6C0: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
L_801BF6C4:
    // 0x801BF6C4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801BF6C8: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x801BF6CC: lhu         $v0, 0x1C8($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X1C8);
L_801BF6D0:
    // 0x801BF6D0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801BF6D4: andi        $t8, $v0, 0x404
    ctx->r24 = ctx->r2 & 0X404;
    // 0x801BF6D8: addiu       $t0, $t0, -0x310
    ctx->r8 = ADD32(ctx->r8, -0X310);
    // 0x801BF6DC: bne         $t8, $zero, L_801BF6F4
    if (ctx->r24 != 0) {
        // 0x801BF6E0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801BF6F4;
    }
    // 0x801BF6E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF6E4: lhu         $t9, 0x1D0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X1D0);
    // 0x801BF6E8: andi        $t3, $t9, 0x400
    ctx->r11 = ctx->r25 & 0X400;
    // 0x801BF6EC: beql        $t3, $zero, L_801BF750
    if (ctx->r11 == 0) {
        // 0x801BF6F0: lbu         $a1, 0x42FE($t1)
        ctx->r5 = MEM_BU(ctx->r9, 0X42FE);
            goto L_801BF750;
    }
    goto skip_0;
    // 0x801BF6F0: lbu         $a1, 0x42FE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X42FE);
    skip_0:
L_801BF6F4:
    // 0x801BF6F4: lbu         $t4, 0x42FE($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X42FE);
    // 0x801BF6F8: bnel        $t2, $t4, L_801BF728
    if (ctx->r10 != ctx->r12) {
        // 0x801BF6FC: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_801BF728;
    }
    goto skip_1;
    // 0x801BF6FC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x801BF700: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x801BF704: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801BF708: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x801BF70C: bne         $v0, $at, L_801BF71C
    if (ctx->r2 != ctx->r1) {
        // 0x801BF710: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_801BF71C;
    }
    // 0x801BF710: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801BF714: b           L_801BF744
    // 0x801BF718: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
        goto L_801BF744;
    // 0x801BF718: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
L_801BF71C:
    // 0x801BF71C: b           L_801BF744
    // 0x801BF720: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
        goto L_801BF744;
    // 0x801BF720: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x801BF724: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_801BF728:
    // 0x801BF728: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801BF72C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x801BF730: bne         $v0, $at, L_801BF740
    if (ctx->r2 != ctx->r1) {
        // 0x801BF734: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_801BF740;
    }
    // 0x801BF734: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801BF738: b           L_801BF744
    // 0x801BF73C: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
        goto L_801BF744;
    // 0x801BF73C: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
L_801BF740:
    // 0x801BF740: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
L_801BF744:
    // 0x801BF744: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801BF748: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x801BF74C: lbu         $a1, 0x42FE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X42FE);
L_801BF750:
    // 0x801BF750: bnel        $t2, $a1, L_801BF7BC
    if (ctx->r10 != ctx->r5) {
        // 0x801BF754: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_801BF7BC;
    }
    goto skip_2;
    // 0x801BF754: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x801BF758: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801BF75C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF760: addiu       $a3, $a3, -0x1758
    ctx->r7 = ADD32(ctx->r7, -0X1758);
    // 0x801BF764: lhu         $a2, 0x2($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X2);
    // 0x801BF768: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801BF76C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF770: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801BF774: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801BF778: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x801BF77C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801BF780: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    // 0x801BF784: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801BF788: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801BF78C: jal         0x8001B204
    // 0x801BF790: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801BF790: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_0:
    // 0x801BF794: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF798: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF79C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF7A0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF7A4: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF7A8: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF7AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF7B0: b           L_801BFC9C
    // 0x801BF7B4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF7B4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x801BF7B8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_801BF7BC:
    // 0x801BF7BC: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x801BF7C0: sltiu       $at, $a0, 0x10
    ctx->r1 = ctx->r4 < 0X10 ? 1 : 0;
    // 0x801BF7C4: beq         $at, $zero, L_801BFC9C
    if (ctx->r1 == 0) {
        // 0x801BF7C8: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_801BFC9C;
    }
    // 0x801BF7C8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x801BF7CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801BF7D0: addu        $at, $at, $t9
    gpr jr_addend_801BF7D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801BF7D4: lw          $t9, -0x1618($at)
    ctx->r25 = ADD32(ctx->r1, -0X1618);
    // 0x801BF7D8: jr          $t9
    // 0x801BF7DC: nop

    switch (jr_addend_801BF7D8 >> 2) {
        case 0: goto L_801BF7E0; break;
        case 1: goto L_801BF82C; break;
        case 2: goto L_801BF878; break;
        case 3: goto L_801BF8C4; break;
        case 4: goto L_801BF910; break;
        case 5: goto L_801BF95C; break;
        case 6: goto L_801BF9A8; break;
        case 7: goto L_801BF9F4; break;
        case 8: goto L_801BFA40; break;
        case 9: goto L_801BFA8C; break;
        case 10: goto L_801BFAD8; break;
        case 11: goto L_801BFB24; break;
        case 12: goto L_801BFB70; break;
        case 13: goto L_801BFBBC; break;
        case 14: goto L_801BFC08; break;
        case 15: goto L_801BFC54; break;
        default: switch_error(__func__, 0x801BF7D8, 0x801CE9E8);
    }
    // 0x801BF7DC: nop

L_801BF7E0:
    // 0x801BF7E0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF7E4: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801BF7E8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801BF7EC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801BF7F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BF7F4: addiu       $a3, $a3, -0x1750
    ctx->r7 = ADD32(ctx->r7, -0X1750);
    // 0x801BF7F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF7FC: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF800: jal         0x8001B204
    // 0x801BF804: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801BF804: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    after_1:
    // 0x801BF808: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF80C: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF810: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF814: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF818: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF81C: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF820: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF824: b           L_801BFC9C
    // 0x801BF828: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF828: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF82C:
    // 0x801BF82C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF830: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801BF834: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801BF838: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801BF83C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801BF840: addiu       $a3, $a3, -0x1748
    ctx->r7 = ADD32(ctx->r7, -0X1748);
    // 0x801BF844: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF848: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF84C: jal         0x8001B204
    // 0x801BF850: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801BF850: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    after_2:
    // 0x801BF854: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF858: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF85C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF860: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF864: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF868: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF86C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF870: b           L_801BFC9C
    // 0x801BF874: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF874: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF878:
    // 0x801BF878: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF87C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801BF880: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801BF884: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801BF888: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801BF88C: addiu       $a3, $a3, -0x1740
    ctx->r7 = ADD32(ctx->r7, -0X1740);
    // 0x801BF890: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF894: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF898: jal         0x8001B204
    // 0x801BF89C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801BF89C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_3:
    // 0x801BF8A0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF8A4: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF8A8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF8AC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF8B0: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF8B4: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF8B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF8BC: b           L_801BFC9C
    // 0x801BF8C0: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF8C0: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF8C4:
    // 0x801BF8C4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF8C8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x801BF8CC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801BF8D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801BF8D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801BF8D8: addiu       $a3, $a3, -0x1738
    ctx->r7 = ADD32(ctx->r7, -0X1738);
    // 0x801BF8DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF8E0: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF8E4: jal         0x8001B204
    // 0x801BF8E8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801BF8E8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_4:
    // 0x801BF8EC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF8F0: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF8F4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF8F8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF8FC: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF900: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF904: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF908: b           L_801BFC9C
    // 0x801BF90C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF90C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF910:
    // 0x801BF910: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF914: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801BF918: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801BF91C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801BF920: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801BF924: addiu       $a3, $a3, -0x1730
    ctx->r7 = ADD32(ctx->r7, -0X1730);
    // 0x801BF928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF92C: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF930: jal         0x8001B204
    // 0x801BF934: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801BF934: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    after_5:
    // 0x801BF938: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF93C: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF940: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF944: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF948: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF94C: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF950: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF954: b           L_801BFC9C
    // 0x801BF958: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF958: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF95C:
    // 0x801BF95C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF960: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801BF964: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801BF968: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801BF96C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BF970: addiu       $a3, $a3, -0x1728
    ctx->r7 = ADD32(ctx->r7, -0X1728);
    // 0x801BF974: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF978: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF97C: jal         0x8001B204
    // 0x801BF980: addiu       $a2, $zero, 0x5E
    ctx->r6 = ADD32(0, 0X5E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801BF980: addiu       $a2, $zero, 0x5E
    ctx->r6 = ADD32(0, 0X5E);
    after_6:
    // 0x801BF984: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF988: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF98C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF990: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF994: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF998: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF99C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF9A0: b           L_801BFC9C
    // 0x801BF9A4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF9A4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF9A8:
    // 0x801BF9A8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF9AC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801BF9B0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801BF9B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801BF9B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801BF9BC: addiu       $a3, $a3, -0x1720
    ctx->r7 = ADD32(ctx->r7, -0X1720);
    // 0x801BF9C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BF9C4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BF9C8: jal         0x8001B204
    // 0x801BF9CC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801BF9CC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    after_7:
    // 0x801BF9D0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BF9D4: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BF9D8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BF9DC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BF9E0: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BF9E4: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BF9E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF9EC: b           L_801BFC9C
    // 0x801BF9F0: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BF9F0: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BF9F4:
    // 0x801BF9F4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BF9F8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801BF9FC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801BFA00: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801BFA04: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BFA08: addiu       $a3, $a3, -0x1718
    ctx->r7 = ADD32(ctx->r7, -0X1718);
    // 0x801BFA0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFA10: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFA14: jal         0x8001B204
    // 0x801BFA18: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801BFA18: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_8:
    // 0x801BFA1C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFA20: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFA24: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFA28: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFA2C: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFA30: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFA34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFA38: b           L_801BFC9C
    // 0x801BFA3C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFA3C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFA40:
    // 0x801BFA40: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFA44: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801BFA48: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801BFA4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801BFA50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801BFA54: addiu       $a3, $a3, -0x1710
    ctx->r7 = ADD32(ctx->r7, -0X1710);
    // 0x801BFA58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFA5C: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFA60: jal         0x8001B204
    // 0x801BFA64: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801BFA64: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    after_9:
    // 0x801BFA68: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFA6C: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFA70: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFA74: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFA78: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFA7C: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFA80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFA84: b           L_801BFC9C
    // 0x801BFA88: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFA88: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFA8C:
    // 0x801BFA8C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFA90: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801BFA94: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801BFA98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801BFA9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801BFAA0: addiu       $a3, $a3, -0x1708
    ctx->r7 = ADD32(ctx->r7, -0X1708);
    // 0x801BFAA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFAA8: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFAAC: jal         0x8001B204
    // 0x801BFAB0: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801BFAB0: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    after_10:
    // 0x801BFAB4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFAB8: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFABC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFAC0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFAC4: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFAC8: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFACC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFAD0: b           L_801BFC9C
    // 0x801BFAD4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFAD4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFAD8:
    // 0x801BFAD8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFADC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x801BFAE0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801BFAE4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801BFAE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801BFAEC: addiu       $a3, $a3, -0x1700
    ctx->r7 = ADD32(ctx->r7, -0X1700);
    // 0x801BFAF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFAF4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFAF8: jal         0x8001B204
    // 0x801BFAFC: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801BFAFC: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    after_11:
    // 0x801BFB00: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFB04: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFB08: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFB0C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFB10: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFB14: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFB18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFB1C: b           L_801BFC9C
    // 0x801BFB20: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFB20: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFB24:
    // 0x801BFB24: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFB28: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801BFB2C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801BFB30: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801BFB34: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801BFB38: addiu       $a3, $a3, -0x16F8
    ctx->r7 = ADD32(ctx->r7, -0X16F8);
    // 0x801BFB3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFB40: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFB44: jal         0x8001B204
    // 0x801BFB48: addiu       $a2, $zero, 0x8E
    ctx->r6 = ADD32(0, 0X8E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801BFB48: addiu       $a2, $zero, 0x8E
    ctx->r6 = ADD32(0, 0X8E);
    after_12:
    // 0x801BFB4C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFB50: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFB54: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFB58: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFB5C: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFB60: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFB64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFB68: b           L_801BFC9C
    // 0x801BFB6C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFB6C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFB70:
    // 0x801BFB70: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFB74: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801BFB78: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801BFB7C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801BFB80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BFB84: addiu       $a3, $a3, -0x16F0
    ctx->r7 = ADD32(ctx->r7, -0X16F0);
    // 0x801BFB88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFB8C: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFB90: jal         0x8001B204
    // 0x801BFB94: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801BFB94: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_13:
    // 0x801BFB98: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFB9C: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFBA0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFBA4: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFBA8: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFBAC: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFBB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFBB4: b           L_801BFC9C
    // 0x801BFBB8: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFBB8: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFBBC:
    // 0x801BFBBC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFBC0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801BFBC4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801BFBC8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801BFBCC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801BFBD0: addiu       $a3, $a3, -0x16E8
    ctx->r7 = ADD32(ctx->r7, -0X16E8);
    // 0x801BFBD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFBD8: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFBDC: jal         0x8001B204
    // 0x801BFBE0: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x801BFBE0: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    after_14:
    // 0x801BFBE4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFBE8: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFBEC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFBF0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFBF4: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFBF8: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFBFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFC00: b           L_801BFC9C
    // 0x801BFC04: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFC04: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFC08:
    // 0x801BFC08: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFC0C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801BFC10: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801BFC14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801BFC18: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BFC1C: addiu       $a3, $a3, -0x16E0
    ctx->r7 = ADD32(ctx->r7, -0X16E0);
    // 0x801BFC20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFC24: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFC28: jal         0x8001B204
    // 0x801BFC2C: addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x801BFC2C: addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    after_15:
    // 0x801BFC30: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFC34: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFC38: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFC3C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFC40: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFC44: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFC48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFC4C: b           L_801BFC9C
    // 0x801BFC50: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFC9C;
    // 0x801BFC50: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFC54:
    // 0x801BFC54: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801BFC58: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801BFC5C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801BFC60: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801BFC64: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801BFC68: addiu       $a3, $a3, -0x16D8
    ctx->r7 = ADD32(ctx->r7, -0X16D8);
    // 0x801BFC6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BFC70: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x801BFC74: jal         0x8001B204
    // 0x801BFC78: addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_16;
    // 0x801BFC78: addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    after_16:
    // 0x801BFC7C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFC80: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFC84: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFC88: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801BFC8C: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x801BFC90: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFC94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFC98: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFC9C:
    // 0x801BFC9C: lhu         $t7, 0x1C8($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X1C8);
    // 0x801BFCA0: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x801BFCA4: beq         $t8, $zero, L_801BFE0C
    if (ctx->r24 == 0) {
        // 0x801BFCA8: nop
    
            goto L_801BFE0C;
    }
    // 0x801BFCA8: nop

    // 0x801BFCAC: bne         $t2, $a1, L_801BFD48
    if (ctx->r10 != ctx->r5) {
        // 0x801BFCB0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_801BFD48;
    }
    // 0x801BFCB0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801BFCB4: beql        $a0, $at, L_801BFD18
    if (ctx->r4 == ctx->r1) {
        // 0x801BFCB8: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801BFD18;
    }
    goto skip_3;
    // 0x801BFCB8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    skip_3:
    // 0x801BFCBC: bne         $a0, $zero, L_801BFCF0
    if (ctx->r4 != 0) {
        // 0x801BFCC0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801BFCF0;
    }
    // 0x801BFCC0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801BFCC4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801BFCC8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801BFCCC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801BFCD0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801BFCD4: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x801BFCD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801BFCDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BFCE0: jal         0x8012FE50
    // 0x801BFCE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_17;
    // 0x801BFCE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x801BFCE8: b           L_801BFD2C
    // 0x801BFCEC: nop

        goto L_801BFD2C;
    // 0x801BFCEC: nop

L_801BFCF0:
    // 0x801BFCF0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801BFCF4: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x801BFCF8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801BFCFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BFD00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BFD04: jal         0x8012FE50
    // 0x801BFD08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_18;
    // 0x801BFD08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x801BFD0C: b           L_801BFD2C
    // 0x801BFD10: nop

        goto L_801BFD2C;
    // 0x801BFD10: nop

    // 0x801BFD14: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
L_801BFD18:
    // 0x801BFD18: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x801BFD1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BFD20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BFD24: jal         0x8012FE50
    // 0x801BFD28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_19;
    // 0x801BFD28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_19:
L_801BFD2C:
    // 0x801BFD2C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFD30: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFD34: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFD38: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFD3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFD40: b           L_801BFE0C
    // 0x801BFD44: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFE0C;
    // 0x801BFD44: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFD48:
    // 0x801BFD48: bne         $a0, $zero, L_801BFD8C
    if (ctx->r4 != 0) {
        // 0x801BFD4C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801BFD8C;
    }
    // 0x801BFD4C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801BFD50: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801BFD54: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801BFD58: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BFD5C: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x801BFD60: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801BFD64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BFD68: jal         0x8012FE50
    // 0x801BFD6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_20;
    // 0x801BFD6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_20:
    // 0x801BFD70: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFD74: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFD78: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFD7C: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFD80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFD84: b           L_801BFE0C
    // 0x801BFD88: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFE0C;
    // 0x801BFD88: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFD8C:
    // 0x801BFD8C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801BFD90: beql        $a0, $at, L_801BFDE0
    if (ctx->r4 == ctx->r1) {
        // 0x801BFD94: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801BFDE0;
    }
    goto skip_4;
    // 0x801BFD94: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    skip_4:
    // 0x801BFD98: jal         0x80152230
    // 0x801BFD9C: nop

    LOOKUP_FUNC(0x80152230)(rdram, ctx);
        goto after_21;
    // 0x801BFD9C: nop

    after_21:
    // 0x801BFDA0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801BFDA4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801BFDA8: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x801BFDAC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801BFDB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BFDB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BFDB8: jal         0x8012FE50
    // 0x801BFDBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_22;
    // 0x801BFDBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x801BFDC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFDC4: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFDC8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFDCC: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFDD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFDD4: b           L_801BFE0C
    // 0x801BFDD8: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
        goto L_801BFE0C;
    // 0x801BFDD8: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x801BFDDC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
L_801BFDE0:
    // 0x801BFDE0: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x801BFDE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BFDE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BFDEC: jal         0x8012FE50
    // 0x801BFDF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_23;
    // 0x801BFDF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x801BFDF4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801BFDF8: lw          $v1, -0x310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X310);
    // 0x801BFDFC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801BFE00: lbu         $a1, -0x2A52($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2A52);
    // 0x801BFE04: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BFE08: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_801BFE0C:
    // 0x801BFE0C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801BFE10: bne         $t2, $a1, L_801BFE88
    if (ctx->r10 != ctx->r5) {
        // 0x801BFE14: addiu       $v0, $v0, -0x4410
        ctx->r2 = ADD32(ctx->r2, -0X4410);
            goto L_801BFE88;
    }
    // 0x801BFE14: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801BFE18: sltiu       $at, $a0, 0x7
    ctx->r1 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x801BFE1C: beq         $at, $zero, L_801BFFA0
    if (ctx->r1 == 0) {
        // 0x801BFE20: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_801BFFA0;
    }
    // 0x801BFE20: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x801BFE24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801BFE28: addu        $at, $at, $t4
    gpr jr_addend_801BFE30 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801BFE2C: lw          $t4, -0x15D8($at)
    ctx->r12 = ADD32(ctx->r1, -0X15D8);
    // 0x801BFE30: jr          $t4
    // 0x801BFE34: nop

    switch (jr_addend_801BFE30 >> 2) {
        case 0: goto L_801BFE38; break;
        case 1: goto L_801BFE40; break;
        case 2: goto L_801BFE4C; break;
        case 3: goto L_801BFE58; break;
        case 4: goto L_801BFE64; break;
        case 5: goto L_801BFE70; break;
        case 6: goto L_801BFE7C; break;
        default: switch_error(__func__, 0x801BFE30, 0x801CEA28);
    }
    // 0x801BFE34: nop

L_801BFE38:
    // 0x801BFE38: b           L_801BFFA0
    // 0x801BFE3C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFE3C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_801BFE40:
    // 0x801BFE40: addiu       $t5, $zero, 0x104
    ctx->r13 = ADD32(0, 0X104);
    // 0x801BFE44: b           L_801BFFA0
    // 0x801BFE48: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
        goto L_801BFFA0;
    // 0x801BFE48: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
L_801BFE4C:
    // 0x801BFE4C: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x801BFE50: b           L_801BFFA0
    // 0x801BFE54: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
        goto L_801BFFA0;
    // 0x801BFE54: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
L_801BFE58:
    // 0x801BFE58: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
    // 0x801BFE5C: b           L_801BFFA0
    // 0x801BFE60: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
        goto L_801BFFA0;
    // 0x801BFE60: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
L_801BFE64:
    // 0x801BFE64: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x801BFE68: b           L_801BFFA0
    // 0x801BFE6C: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
        goto L_801BFFA0;
    // 0x801BFE6C: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
L_801BFE70:
    // 0x801BFE70: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x801BFE74: b           L_801BFFA0
    // 0x801BFE78: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
        goto L_801BFFA0;
    // 0x801BFE78: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
L_801BFE7C:
    // 0x801BFE7C: addiu       $t3, $zero, 0xC2
    ctx->r11 = ADD32(0, 0XC2);
    // 0x801BFE80: b           L_801BFFA0
    // 0x801BFE84: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
        goto L_801BFFA0;
    // 0x801BFE84: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
L_801BFE88:
    // 0x801BFE88: sltiu       $at, $a0, 0x10
    ctx->r1 = ctx->r4 < 0X10 ? 1 : 0;
    // 0x801BFE8C: beq         $at, $zero, L_801BFFA0
    if (ctx->r1 == 0) {
        // 0x801BFE90: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_801BFFA0;
    }
    // 0x801BFE90: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x801BFE94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801BFE98: addu        $at, $at, $t4
    gpr jr_addend_801BFEA0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801BFE9C: lw          $t4, -0x15BC($at)
    ctx->r12 = ADD32(ctx->r1, -0X15BC);
    // 0x801BFEA0: jr          $t4
    // 0x801BFEA4: nop

    switch (jr_addend_801BFEA0 >> 2) {
        case 0: goto L_801BFEA8; break;
        case 1: goto L_801BFEB8; break;
        case 2: goto L_801BFEC4; break;
        case 3: goto L_801BFED4; break;
        case 4: goto L_801BFEE4; break;
        case 5: goto L_801BFEF4; break;
        case 6: goto L_801BFF04; break;
        case 7: goto L_801BFF14; break;
        case 8: goto L_801BFF24; break;
        case 9: goto L_801BFF34; break;
        case 10: goto L_801BFF44; break;
        case 11: goto L_801BFF54; break;
        case 12: goto L_801BFF64; break;
        case 13: goto L_801BFF74; break;
        case 14: goto L_801BFF84; break;
        case 15: goto L_801BFF94; break;
        default: switch_error(__func__, 0x801BFEA0, 0x801CEA44);
    }
    // 0x801BFEA4: nop

L_801BFEA8:
    // 0x801BFEA8: addiu       $t5, $zero, 0x104
    ctx->r13 = ADD32(0, 0X104);
    // 0x801BFEAC: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x801BFEB0: b           L_801BFFA0
    // 0x801BFEB4: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFEB4: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFEB8:
    // 0x801BFEB8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801BFEBC: b           L_801BFFA0
    // 0x801BFEC0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFEC0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFEC4:
    // 0x801BFEC4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801BFEC8: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x801BFECC: b           L_801BFFA0
    // 0x801BFED0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFED0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFED4:
    // 0x801BFED4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801BFED8: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x801BFEDC: b           L_801BFFA0
    // 0x801BFEE0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFEE0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFEE4:
    // 0x801BFEE4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801BFEE8: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x801BFEEC: b           L_801BFFA0
    // 0x801BFEF0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFEF0: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFEF4:
    // 0x801BFEF4: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801BFEF8: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x801BFEFC: b           L_801BFFA0
    // 0x801BFF00: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF00: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF04:
    // 0x801BFF04: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x801BFF08: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x801BFF0C: b           L_801BFFA0
    // 0x801BFF10: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF10: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF14:
    // 0x801BFF14: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x801BFF18: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    // 0x801BFF1C: b           L_801BFFA0
    // 0x801BFF20: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF20: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF24:
    // 0x801BFF24: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x801BFF28: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x801BFF2C: b           L_801BFFA0
    // 0x801BFF30: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF30: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF34:
    // 0x801BFF34: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x801BFF38: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x801BFF3C: b           L_801BFFA0
    // 0x801BFF40: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF40: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF44:
    // 0x801BFF44: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x801BFF48: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x801BFF4C: b           L_801BFFA0
    // 0x801BFF50: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF50: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF54:
    // 0x801BFF54: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x801BFF58: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x801BFF5C: b           L_801BFFA0
    // 0x801BFF60: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF60: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF64:
    // 0x801BFF64: addiu       $t9, $zero, 0x8C
    ctx->r25 = ADD32(0, 0X8C);
    // 0x801BFF68: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x801BFF6C: b           L_801BFFA0
    // 0x801BFF70: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF70: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF74:
    // 0x801BFF74: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x801BFF78: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x801BFF7C: b           L_801BFFA0
    // 0x801BFF80: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF80: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF84:
    // 0x801BFF84: addiu       $t4, $zero, 0x9A
    ctx->r12 = ADD32(0, 0X9A);
    // 0x801BFF88: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    // 0x801BFF8C: b           L_801BFFA0
    // 0x801BFF90: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
        goto L_801BFFA0;
    // 0x801BFF90: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFF94:
    // 0x801BFF94: addiu       $t5, $zero, 0xBE
    ctx->r13 = ADD32(0, 0XBE);
    // 0x801BFF98: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x801BFF9C: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
L_801BFFA0:
    // 0x801BFFA0: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x801BFFA4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801BFFA8: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x801BFFAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801BFFB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801BFFB4: jr          $ra
    // 0x801BFFB8: nop

    return;
    // 0x801BFFB8: nop

;}
RECOMP_FUNC void M23_FUN_801bffbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFFBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801BFFC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801BFFC4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801BFFC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BFFCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801BFFD0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801BFFD4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801BFFD8: jal         0x80005E44
    // 0x801BFFDC: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801BFFDC: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    after_0:
    // 0x801BFFE0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x801BFFE4: addiu       $a2, $a2, 0x4F30
    ctx->r6 = ADD32(ctx->r6, 0X4F30);
    // 0x801BFFE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801BFFEC: jal         0x80005FAC
    // 0x801BFFF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_1;
    // 0x801BFFF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x801BFFF4: jal         0x80006214
    // 0x801BFFF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801BFFF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801BFFFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C0000: jal         0x8012636C
    // 0x801C0004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_3;
    // 0x801C0004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x801C0008: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C000C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C0010: lwc1        $f0, -0x157C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X157C);
    // 0x801C0014: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C0020: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x801C0024: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C0028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C002C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C0030: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x801C0034: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C0038: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C003C: jal         0x8012C784
    // 0x801C0040: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_4;
    // 0x801C0040: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    after_4:
    // 0x801C0044: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x801C0048: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C004C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801C0050: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C0058: lui         $at, 0xC208
    ctx->r1 = S32(0XC208 << 16);
    // 0x801C005C: swc1        $f2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f2.u32l;
    // 0x801C0060: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x801C0064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C0068: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x801C006C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C0070: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x801C0074: addiu       $t4, $t4, -0x4AA8
    ctx->r12 = ADD32(ctx->r12, -0X4AA8);
    // 0x801C0078: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x801C007C: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x801C0080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C0084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C0088: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C008C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C0090: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x801C0094: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x801C0098: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C009C: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
    // 0x801C00A0: addiu       $t0, $t9, 0x155
    ctx->r8 = ADD32(ctx->r25, 0X155);
    // 0x801C00A4: sh          $t0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r8;
    // 0x801C00A8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C00AC: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801C00B0: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801C00B4: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x801C00B8: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801C00BC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C00C0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801C00C4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C00C8: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x801C00CC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C00D0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C00D4: sb          $zero, 0x48($t8)
    MEM_B(0X48, ctx->r24) = 0;
    // 0x801C00D8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C00DC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C00E0: sb          $a3, 0x49($t0)
    MEM_B(0X49, ctx->r8) = ctx->r7;
    // 0x801C00E4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C00E8: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C00EC: sb          $a3, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r7;
    // 0x801C00F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C00F4: lw          $t4, 0x2C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X2C);
    // 0x801C00F8: jal         0x8012C784
    // 0x801C00FC: sb          $t3, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r11;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_5;
    // 0x801C00FC: sb          $t3, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r11;
    after_5:
    // 0x801C0100: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801C0104: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C0108: lwc1        $f0, -0x1578($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1578);
    // 0x801C010C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0110: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x801C0114: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x801C0118: sh          $t6, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r14;
    // 0x801C011C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x801C0120: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C0124: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C0128: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C012C: addiu       $a1, $a1, 0x1AC
    ctx->r5 = ADD32(ctx->r5, 0X1AC);
    // 0x801C0130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C0134: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x801C0138: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x801C013C: lw          $t5, 0x2C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0140: swc1        $f2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f2.u32l;
    // 0x801C0144: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x801C0148: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C014C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801C0150: addiu       $t3, $t3, -0x5168
    ctx->r11 = ADD32(ctx->r11, -0X5168);
    // 0x801C0154: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x801C0158: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801C015C: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0160: swc1        $f2, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f2.u32l;
    // 0x801C0164: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801C0168: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801C016C: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x801C0170: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x801C0174: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801C0178: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x801C017C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x801C0180: lw          $t5, 0x2C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0184: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x801C0188: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C018C: lw          $t7, 0x2C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X2C);
    // 0x801C0190: jal         0x800058DC
    // 0x801C0194: sw          $t3, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C0194: sw          $t3, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r11;
    after_6:
    // 0x801C0198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C019C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C01A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C01A4: jr          $ra
    // 0x801C01A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C01A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c01ac(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c01ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C01AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C01B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C01B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C01B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C01BC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C01C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C01C4: ldc1        $f8, -0x1570($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1570);
    // 0x801C01C8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C01CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C01D0: ldc1        $f16, -0x1568($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1568);
    // 0x801C01D4: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x801C01D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C01DC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801C01E0: nop

    // 0x801C01E4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801C01E8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C01EC: nop

    // 0x801C01F0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801C01F4: jal         0x8001518C
    // 0x801C01F8: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_0;
    // 0x801C01F8: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x801C01FC: jal         0x80029280
    // 0x801C0200: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_1;
    // 0x801C0200: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x801C0204: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801C0208: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C020C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801C0210: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C0214: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801C0218: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C021C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C0220: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801C0224: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C0228: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C022C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C0230: nop

    // 0x801C0234: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C0238: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C023C: nop

    // 0x801C0240: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C0244: beql        $t0, $zero, L_801C0294
    if (ctx->r8 == 0) {
        // 0x801C0248: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_801C0294;
    }
    goto skip_0;
    // 0x801C0248: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801C024C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C0250: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C0254: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C0258: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C025C: nop

    // 0x801C0260: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C0264: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C0268: nop

    // 0x801C026C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C0270: bne         $t0, $zero, L_801C0288
    if (ctx->r8 != 0) {
        // 0x801C0274: nop
    
            goto L_801C0288;
    }
    // 0x801C0274: nop

    // 0x801C0278: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x801C027C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C0280: b           L_801C02A0
    // 0x801C0284: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801C02A0;
    // 0x801C0284: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801C0288:
    // 0x801C0288: b           L_801C02A0
    // 0x801C028C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801C02A0;
    // 0x801C028C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C0290: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_801C0294:
    // 0x801C0294: nop

    // 0x801C0298: bltz        $t0, L_801C0288
    if (SIGNED(ctx->r8) < 0) {
        // 0x801C029C: nop
    
            goto L_801C0288;
    }
    // 0x801C029C: nop

L_801C02A0:
    // 0x801C02A0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801C02A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C02A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C02AC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C02B0: sb          $t0, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = ctx->r8;
    // 0x801C02B4: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801C02B8: ldc1        $f6, -0x1560($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1560);
    // 0x801C02BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C02C0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C02C4: ldc1        $f10, -0x1558($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1558);
    // 0x801C02C8: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    // 0x801C02CC: lh          $t6, 0x10($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X10);
    // 0x801C02D0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C02D4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801C02D8: nop

    // 0x801C02DC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801C02E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C02E4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C02E8: nop

    // 0x801C02EC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C02F0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801C02F4: jal         0x8001518C
    // 0x801C02F8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_2;
    // 0x801C02F8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_2:
    // 0x801C02FC: jal         0x80029280
    // 0x801C0300: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_3;
    // 0x801C0300: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x801C0304: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801C0308: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C030C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801C0310: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C0314: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801C0318: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C031C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C0320: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801C0324: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C0328: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C032C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C0330: nop

    // 0x801C0334: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C0338: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C033C: nop

    // 0x801C0340: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C0344: beql        $t8, $zero, L_801C0394
    if (ctx->r24 == 0) {
        // 0x801C0348: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_801C0394;
    }
    goto skip_1;
    // 0x801C0348: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x801C034C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C0350: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C0354: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801C0358: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C035C: nop

    // 0x801C0360: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C0364: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C0368: nop

    // 0x801C036C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C0370: bne         $t8, $zero, L_801C0388
    if (ctx->r24 != 0) {
        // 0x801C0374: nop
    
            goto L_801C0388;
    }
    // 0x801C0374: nop

    // 0x801C0378: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x801C037C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C0380: b           L_801C03A0
    // 0x801C0384: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801C03A0;
    // 0x801C0384: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801C0388:
    // 0x801C0388: b           L_801C03A0
    // 0x801C038C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801C03A0;
    // 0x801C038C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C0390: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_801C0394:
    // 0x801C0394: nop

    // 0x801C0398: bltz        $t8, L_801C0388
    if (SIGNED(ctx->r24) < 0) {
        // 0x801C039C: nop
    
            goto L_801C0388;
    }
    // 0x801C039C: nop

L_801C03A0:
    // 0x801C03A0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C03A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C03A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C03AC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C03B0: sb          $t8, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r24;
    // 0x801C03B4: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801C03B8: ldc1        $f8, -0x1550($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1550);
    // 0x801C03BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C03C0: lw          $t3, 0x2C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X2C);
    // 0x801C03C4: ldc1        $f16, -0x1548($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1548);
    // 0x801C03C8: lui         $at, 0x406E
    ctx->r1 = S32(0X406E << 16);
    // 0x801C03CC: lh          $t4, 0x14($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X14);
    // 0x801C03D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C03D4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801C03D8: nop

    // 0x801C03DC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801C03E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C03E4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C03E8: nop

    // 0x801C03EC: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801C03F0: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801C03F4: jal         0x8001518C
    // 0x801C03F8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_4;
    // 0x801C03F8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_4:
    // 0x801C03FC: jal         0x80029280
    // 0x801C0400: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_5;
    // 0x801C0400: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x801C0404: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801C0408: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C040C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801C0410: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C0414: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801C0418: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C041C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C0420: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801C0424: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801C0428: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C042C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C0430: nop

    // 0x801C0434: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C0438: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C043C: nop

    // 0x801C0440: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C0444: beql        $t6, $zero, L_801C0494
    if (ctx->r14 == 0) {
        // 0x801C0448: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_801C0494;
    }
    goto skip_2;
    // 0x801C0448: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x801C044C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C0450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C0454: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C0458: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C045C: nop

    // 0x801C0460: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C0464: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C0468: nop

    // 0x801C046C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C0470: bne         $t6, $zero, L_801C0488
    if (ctx->r14 != 0) {
        // 0x801C0474: nop
    
            goto L_801C0488;
    }
    // 0x801C0474: nop

    // 0x801C0478: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801C047C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C0480: b           L_801C04A0
    // 0x801C0484: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C04A0;
    // 0x801C0484: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C0488:
    // 0x801C0488: b           L_801C04A0
    // 0x801C048C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C04A0;
    // 0x801C048C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C0490: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_801C0494:
    // 0x801C0494: nop

    // 0x801C0498: bltz        $t6, L_801C0488
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C049C: nop
    
            goto L_801C0488;
    }
    // 0x801C049C: nop

L_801C04A0:
    // 0x801C04A0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C04A4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C04A8: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801C04AC: sb          $t6, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r14;
    // 0x801C04B0: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801C04B4: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801C04B8: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x801C04BC: addiu       $t0, $t2, 0x2
    ctx->r8 = ADD32(ctx->r10, 0X2);
    // 0x801C04C0: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x801C04C4: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801C04C8: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C04CC: lh          $t4, 0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X10);
    // 0x801C04D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801C04D4: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
    // 0x801C04D8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801C04DC: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C04E0: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x801C04E4: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x801C04E8: sh          $t6, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r14;
    // 0x801C04EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C04F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C04F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C04F8: jr          $ra
    // 0x801C04FC: nop

    return;
    // 0x801C04FC: nop

;}
RECOMP_FUNC void M23_FUN_801c0500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C0504: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C0508: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C050C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C0510: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C0514: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801C0518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C051C: jal         0x80005E44
    // 0x801C0520: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C0520: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    after_0:
    // 0x801C0524: jal         0x80006214
    // 0x801C0528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C0528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0530: jal         0x8012636C
    // 0x801C0534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x801C0534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x801C0538: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C053C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C0540: lwc1        $f0, -0x1540($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1540);
    // 0x801C0544: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C054C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C0550: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x801C0554: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C0558: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801C055C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C0560: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x801C0564: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801C0568: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C056C: jal         0x8012C784
    // 0x801C0570: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_3;
    // 0x801C0570: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    after_3:
    // 0x801C0574: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C0578: addiu       $a1, $a1, 0x608
    ctx->r5 = ADD32(ctx->r5, 0X608);
    // 0x801C057C: jal         0x800058DC
    // 0x801C0580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C0580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801C0584: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801C0588: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C058C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801C0590: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0594: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C0598: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x801C059C: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801C05A0: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801C05A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C05A8: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x801C05AC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C05B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x801C05B4: addiu       $t4, $t4, -0x4600
    ctx->r12 = ADD32(ctx->r12, -0X4600);
    // 0x801C05B8: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801C05BC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801C05C0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C05C4: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801C05C8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801C05CC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C05D0: sh          $t8, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r24;
    // 0x801C05D4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C05D8: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801C05DC: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801C05E0: ori         $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 | 0X4000;
    // 0x801C05E4: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801C05E8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C05EC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C05F0: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x801C05F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C05F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C05FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C0600: jr          $ra
    // 0x801C0604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C0604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c0608(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c0608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C060C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C0614: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C0618: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C061C: addiu       $a3, $a3, -0x16D0
    ctx->r7 = ADD32(ctx->r7, -0X16D0);
    // 0x801C0620: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801C0624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C0628: jal         0x8001B204
    // 0x801C062C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C062C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_0:
    // 0x801C0630: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x801C0634: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C0638: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C063C: lwc1        $f4, 0x90($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X90);
    // 0x801C0640: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C0644: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0648: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C064C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801C0650: swc1        $f16, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f16.u32l;
    // 0x801C0654: lwc1        $f18, 0x90($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X90);
    // 0x801C0658: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C065C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C0660: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C0664: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801C0668: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C066C: bgez        $t7, L_801C0680
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C0670: andi        $t8, $t7, 0x7F
        ctx->r24 = ctx->r15 & 0X7F;
            goto L_801C0680;
    }
    // 0x801C0670: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x801C0674: beq         $t8, $zero, L_801C0680
    if (ctx->r24 == 0) {
        // 0x801C0678: nop
    
            goto L_801C0680;
    }
    // 0x801C0678: nop

    // 0x801C067C: addiu       $t8, $t8, -0x80
    ctx->r24 = ADD32(ctx->r24, -0X80);
L_801C0680:
    // 0x801C0680: sb          $t8, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r24;
    // 0x801C0684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C068C: jr          $ra
    // 0x801C0690: nop

    return;
    // 0x801C0690: nop

;}
RECOMP_FUNC void M23_FUN_801c0694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C0698: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801C069C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C06A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C06A4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801C06A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C06AC: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    // 0x801C06B0: jal         0x80005E44
    // 0x801C06B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C06B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x801C06B8: jal         0x80006214
    // 0x801C06BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C06BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C06C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C06C4: jal         0x8012636C
    // 0x801C06C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x801C06C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x801C06CC: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x801C06D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801C06D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C06D8: lwc1        $f0, -0x153C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X153C);
    // 0x801C06DC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x801C06E0: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x801C06E4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801C06E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C06EC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C06F0: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x801C06F4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801C06F8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C06FC: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x801C0700: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801C0704: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0708: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x801C070C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801C0710: lw          $v0, 0x10($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X10);
    // 0x801C0714: beql        $v0, $zero, L_801C073C
    if (ctx->r2 == 0) {
        // 0x801C0718: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_801C073C;
    }
    goto skip_0;
    // 0x801C0718: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x801C071C: beq         $v0, $at, L_801C07C4
    if (ctx->r2 == ctx->r1) {
        // 0x801C0720: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C07C4;
    }
    // 0x801C0720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0724: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C0728: beql        $v0, $at, L_801C0820
    if (ctx->r2 == ctx->r1) {
        // 0x801C072C: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_801C0820;
    }
    goto skip_1;
    // 0x801C072C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x801C0730: b           L_801C08C4
    // 0x801C0734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C08C4;
    // 0x801C0734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0738: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_801C073C:
    // 0x801C073C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801C0740: addiu       $t5, $t5, -0x4E08
    ctx->r13 = ADD32(ctx->r13, -0X4E08);
    // 0x801C0744: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0748: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C074C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x801C0750: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x801C0754: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x801C0758: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C075C: addiu       $a1, $a1, 0x8D4
    ctx->r5 = ADD32(ctx->r5, 0X8D4);
    // 0x801C0760: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801C0764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0768: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x801C076C: ori         $t1, $t0, 0x5000
    ctx->r9 = ctx->r8 | 0X5000;
    // 0x801C0770: jal         0x800058DC
    // 0x801C0774: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C0774: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    after_3:
    // 0x801C0778: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801C077C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0780: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801C0784: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0788: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C078C: lui         $at, 0xC214
    ctx->r1 = S32(0XC214 << 16);
    // 0x801C0790: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801C0794: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801C0798: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C079C: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x801C07A0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C07A4: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801C07A8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801C07AC: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801C07B0: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801C07B4: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801C07B8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C07BC: b           L_801C08C0
    // 0x801C07C0: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
        goto L_801C08C0;
    // 0x801C07C0: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
L_801C07C4:
    // 0x801C07C4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C07C8: jal         0x800058DC
    // 0x801C07CC: addiu       $a1, $a1, 0xA88
    ctx->r5 = ADD32(ctx->r5, 0XA88);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C07CC: addiu       $a1, $a1, 0xA88
    ctx->r5 = ADD32(ctx->r5, 0XA88);
    after_4:
    // 0x801C07D0: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801C07D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C07D8: lui         $at, 0xC150
    ctx->r1 = S32(0XC150 << 16);
    // 0x801C07DC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C07E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C07E4: lui         $at, 0xC214
    ctx->r1 = S32(0XC214 << 16);
    // 0x801C07E8: swc1        $f10, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f10.u32l;
    // 0x801C07EC: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801C07F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C07F4: addiu       $t6, $zero, -0x800
    ctx->r14 = ADD32(0, -0X800);
    // 0x801C07F8: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C07FC: swc1        $f16, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f16.u32l;
    // 0x801C0800: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801C0804: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801C0808: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    // 0x801C080C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801C0810: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801C0814: b           L_801C08C0
    // 0x801C0818: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
        goto L_801C08C0;
    // 0x801C0818: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x801C081C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
L_801C0820:
    // 0x801C0820: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C0824: lwc1        $f0, -0x1538($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1538);
    // 0x801C0828: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C082C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801C0830: addiu       $t7, $t7, -0x4F58
    ctx->r15 = ADD32(ctx->r15, -0X4F58);
    // 0x801C0834: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x801C0838: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801C083C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C0840: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x801C0844: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0848: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C084C: addiu       $a1, $a1, 0xB24
    ctx->r5 = ADD32(ctx->r5, 0XB24);
    // 0x801C0850: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x801C0854: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x801C0858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C085C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C0860: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x801C0864: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801C0868: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x801C086C: jal         0x800058DC
    // 0x801C0870: sw          $t9, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C0870: sw          $t9, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r25;
    after_5:
    // 0x801C0874: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801C0878: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C087C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C0880: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C0884: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x801C0888: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C088C: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801C0890: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801C0894: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x801C0898: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C089C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C08A0: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x801C08A4: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801C08A8: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801C08AC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C08B0: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x801C08B4: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801C08B8: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801C08BC: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
L_801C08C0:
    // 0x801C08C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C08C4:
    // 0x801C08C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C08C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C08CC: jr          $ra
    // 0x801C08D0: nop

    return;
    // 0x801C08D0: nop

;}
RECOMP_FUNC void M23_FUN_801c08d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C08D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C08D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C08DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C08E0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C08E4: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C08E8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C08EC: lh          $v1, 0x12($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X12);
    // 0x801C08F0: andi        $t7, $v1, 0x1FFF
    ctx->r15 = ctx->r3 & 0X1FFF;
    // 0x801C08F4: beq         $t7, $at, L_801C0900
    if (ctx->r15 == ctx->r1) {
        // 0x801C08F8: addiu       $t8, $v1, 0x10
        ctx->r24 = ADD32(ctx->r3, 0X10);
            goto L_801C0900;
    }
    // 0x801C08F8: addiu       $t8, $v1, 0x10
    ctx->r24 = ADD32(ctx->r3, 0X10);
    // 0x801C08FC: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_801C0900:
    // 0x801C0900: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C0904: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801C0908: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C090C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801C0910: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801C0914: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0918: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C091C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x801C0920: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0924: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C0928: bgez        $t0, L_801C093C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C092C: andi        $t1, $t0, 0x7F
        ctx->r9 = ctx->r8 & 0X7F;
            goto L_801C093C;
    }
    // 0x801C092C: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x801C0930: beq         $t1, $zero, L_801C093C
    if (ctx->r9 == 0) {
        // 0x801C0934: nop
    
            goto L_801C093C;
    }
    // 0x801C0934: nop

    // 0x801C0938: addiu       $t1, $t1, -0x80
    ctx->r9 = ADD32(ctx->r9, -0X80);
L_801C093C:
    // 0x801C093C: sb          $t1, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r9;
    // 0x801C0940: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x801C0944: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801C0948: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x801C094C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801C0950: lui         $a3, 0xC1A0
    ctx->r7 = S32(0XC1A0 << 16);
    // 0x801C0954: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0958: sb          $zero, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = 0;
    // 0x801C095C: lwc1        $f8, 0x90($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C0960: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801C0964: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801C0968: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801C096C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801C0970: lw          $t1, 0x2C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0974: bgez        $t9, L_801C0988
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C0978: andi        $t0, $t9, 0x7F
        ctx->r8 = ctx->r25 & 0X7F;
            goto L_801C0988;
    }
    // 0x801C0978: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x801C097C: beq         $t0, $zero, L_801C0988
    if (ctx->r8 == 0) {
        // 0x801C0980: nop
    
            goto L_801C0988;
    }
    // 0x801C0980: nop

    // 0x801C0984: addiu       $t0, $t0, -0x80
    ctx->r8 = ADD32(ctx->r8, -0X80);
L_801C0988:
    // 0x801C0988: sb          $t0, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r8;
    // 0x801C098C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801C0990: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801C0994: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C0998: sb          $zero, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = 0;
    // 0x801C099C: lwc1        $f16, 0x90($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C09A0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801C09A4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801C09A8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C09AC: swc1        $f8, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f8.u32l;
    // 0x801C09B0: lwc1        $f10, -0x1534($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1534);
    // 0x801C09B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C09B8: jal         0x8012AAE8
    // 0x801C09BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012AAE8)(rdram, ctx);
        goto after_0;
    // 0x801C09BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801C09C0: bne         $v0, $zero, L_801C09D4
    if (ctx->r2 != 0) {
        // 0x801C09C4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C09D4;
    }
    // 0x801C09C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C09C8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C09CC: jal         0x800058DC
    // 0x801C09D0: addiu       $a1, $a1, 0x9E4
    ctx->r5 = ADD32(ctx->r5, 0X9E4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C09D0: addiu       $a1, $a1, 0x9E4
    ctx->r5 = ADD32(ctx->r5, 0X9E4);
    after_1:
L_801C09D4:
    // 0x801C09D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C09D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C09DC: jr          $ra
    // 0x801C09E0: nop

    return;
    // 0x801C09E0: nop

;}
RECOMP_FUNC void M23_FUN_801c09e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C09E4: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C09E8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C09EC: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C09F0: lh          $v1, 0x12($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X12);
    // 0x801C09F4: andi        $t7, $v1, 0x1FFF
    ctx->r15 = ctx->r3 & 0X1FFF;
    // 0x801C09F8: beq         $t7, $at, L_801C0A04
    if (ctx->r15 == ctx->r1) {
        // 0x801C09FC: addiu       $t8, $v1, 0x10
        ctx->r24 = ADD32(ctx->r3, 0X10);
            goto L_801C0A04;
    }
    // 0x801C09FC: addiu       $t8, $v1, 0x10
    ctx->r24 = ADD32(ctx->r3, 0X10);
    // 0x801C0A00: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_801C0A04:
    // 0x801C0A04: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C0A08: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801C0A0C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C0A10: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801C0A14: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0A18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0A1C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C0A20: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x801C0A24: nop

    // 0x801C0A28: bgez        $t0, L_801C0A3C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C0A2C: andi        $t1, $t0, 0x7F
        ctx->r9 = ctx->r8 & 0X7F;
            goto L_801C0A3C;
    }
    // 0x801C0A2C: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x801C0A30: beq         $t1, $zero, L_801C0A3C
    if (ctx->r9 == 0) {
        // 0x801C0A34: nop
    
            goto L_801C0A3C;
    }
    // 0x801C0A34: nop

    // 0x801C0A38: addiu       $t1, $t1, -0x80
    ctx->r9 = ADD32(ctx->r9, -0X80);
L_801C0A3C:
    // 0x801C0A3C: sb          $t1, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r9;
    // 0x801C0A40: lwc1        $f8, 0x90($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C0A44: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C0A48: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801C0A4C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0A50: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801C0A54: nop

    // 0x801C0A58: bgez        $t5, L_801C0A6C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C0A5C: andi        $t6, $t5, 0x7F
        ctx->r14 = ctx->r13 & 0X7F;
            goto L_801C0A6C;
    }
    // 0x801C0A5C: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x801C0A60: beq         $t6, $zero, L_801C0A6C
    if (ctx->r14 == 0) {
        // 0x801C0A64: nop
    
            goto L_801C0A6C;
    }
    // 0x801C0A64: nop

    // 0x801C0A68: addiu       $t6, $t6, -0x80
    ctx->r14 = ADD32(ctx->r14, -0X80);
L_801C0A6C:
    // 0x801C0A6C: sb          $t6, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r14;
    // 0x801C0A70: lwc1        $f16, 0x90($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C0A74: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801C0A78: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801C0A7C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0A80: jr          $ra
    // 0x801C0A84: swc1        $f8, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x801C0A84: swc1        $f8, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f8.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c0a88(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c0a88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C0A8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C0A90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C0A94: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C0A98: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C0A9C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801C0AA0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0AA4: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    // 0x801C0AA8: lui         $a3, 0xC1A0
    ctx->r7 = S32(0XC1A0 << 16);
    // 0x801C0AAC: lh          $v1, 0x12($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X12);
    // 0x801C0AB0: andi        $t7, $v1, 0x1FFF
    ctx->r15 = ctx->r3 & 0X1FFF;
    // 0x801C0AB4: beq         $t7, $at, L_801C0AC0
    if (ctx->r15 == ctx->r1) {
        // 0x801C0AB8: addiu       $t8, $v1, -0x10
        ctx->r24 = ADD32(ctx->r3, -0X10);
            goto L_801C0AC0;
    }
    // 0x801C0AB8: addiu       $t8, $v1, -0x10
    ctx->r24 = ADD32(ctx->r3, -0X10);
    // 0x801C0ABC: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_801C0AC0:
    // 0x801C0AC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C0AC4: lwc1        $f4, -0x1530($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1530);
    // 0x801C0AC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C0ACC: jal         0x8012AAE8
    // 0x801C0AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012AAE8)(rdram, ctx);
        goto after_0;
    // 0x801C0AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801C0AD4: bne         $v0, $zero, L_801C0AE8
    if (ctx->r2 != 0) {
        // 0x801C0AD8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C0AE8;
    }
    // 0x801C0AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C0ADC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C0AE0: jal         0x800058DC
    // 0x801C0AE4: addiu       $a1, $a1, 0xAF8
    ctx->r5 = ADD32(ctx->r5, 0XAF8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C0AE4: addiu       $a1, $a1, 0xAF8
    ctx->r5 = ADD32(ctx->r5, 0XAF8);
    after_1:
L_801C0AE8:
    // 0x801C0AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0AEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C0AF0: jr          $ra
    // 0x801C0AF4: nop

    return;
    // 0x801C0AF4: nop

;}
RECOMP_FUNC void M23_FUN_801c0af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0AF8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C0AFC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C0B00: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C0B04: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0B08: lh          $v1, 0x12($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X12);
    // 0x801C0B0C: andi        $t7, $v1, 0x1FFF
    ctx->r15 = ctx->r3 & 0X1FFF;
    // 0x801C0B10: beq         $t7, $at, L_801C0B1C
    if (ctx->r15 == ctx->r1) {
        // 0x801C0B14: addiu       $t8, $v1, -0x10
        ctx->r24 = ADD32(ctx->r3, -0X10);
            goto L_801C0B1C;
    }
    // 0x801C0B14: addiu       $t8, $v1, -0x10
    ctx->r24 = ADD32(ctx->r3, -0X10);
    // 0x801C0B18: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_801C0B1C:
    // 0x801C0B1C: jr          $ra
    // 0x801C0B20: nop

    return;
    // 0x801C0B20: nop

;}
RECOMP_FUNC void M23_FUN_801c0b24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0B24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C0B28: jr          $ra
    // 0x801C0B2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C0B2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c0b30(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c0b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0B30: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801C0B34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C0B38: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C0B3C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801C0B40: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C0B44: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C0B48: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801C0B4C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801C0B50: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801C0B54: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801C0B58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C0B5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C0B60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C0B64: jal         0x80116E80
    // 0x801C0B68: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x801C0B68: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x801C0B6C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801C0B70: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x801C0B74: jal         0x80005E44
    // 0x801C0B78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801C0B78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x801C0B7C: beql        $v0, $zero, L_801C0F38
    if (ctx->r2 == 0) {
        // 0x801C0B80: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
        LOOKUP_FUNC(0x801C0F38)(rdram, ctx);
        return;
    }
    goto skip_0;
    // 0x801C0B80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801C0B84: jal         0x80006214
    // 0x801C0B88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801C0B88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x801C0B8C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C0B90: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801C0B94: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x801C0B98: jal         0x8001F430
    // 0x801C0B9C: sh          $t6, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_3;
    // 0x801C0B9C: sh          $t6, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r14;
    after_3:
    // 0x801C0BA0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C0BA4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x801C0BA8: ori         $t4, $t4, 0x600
    ctx->r12 = ctx->r12 | 0X600;
    // 0x801C0BAC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C0BB0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C0BB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801C0BB8: sw          $v0, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r2;
    // 0x801C0BBC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C0BC0: addiu       $a1, $a1, 0xF64
    ctx->r5 = ADD32(ctx->r5, 0XF64);
    // 0x801C0BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C0BC8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C0BCC: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x801C0BD0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C0BD4: jal         0x800058DC
    // 0x801C0BD8: sw          $t4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C0BD8: sw          $t4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r12;
    after_4:
    // 0x801C0BDC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0BE0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0BE4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x801C0BE8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801C0BEC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C0BF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C0BF4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0BF8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x801C0BFC: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x801C0C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0C04: lui         $s1, 0xE300
    ctx->r17 = S32(0XE300 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c0c08(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c0c08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0C08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C0C0C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C0C10: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0C14: ori         $s1, $s1, 0xC00
    ctx->r17 = ctx->r17 | 0XC00;
    // 0x801C0C18: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x801C0C1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C0C20: lui         $t9, 0xD9F1
    ctx->r25 = S32(0XD9F1 << 16);
    // 0x801C0C24: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x801C0C28: sw          $s1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r17;
    // 0x801C0C2C: ori         $t9, $t9, 0xFBFF
    ctx->r25 = ctx->r25 | 0XFBFF;
    // 0x801C0C30: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801C0C34: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801C0C38: jal         0x80001060
    // 0x801C0C3C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x801C0C3C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x801C0C40: beq         $v0, $zero, L_801C0C68
    if (ctx->r2 == 0) {
        // 0x801C0C44: lui         $t6, 0xE200
        ctx->r14 = S32(0XE200 << 16);
            goto L_801C0C68;
    }
    // 0x801C0C44: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801C0C48: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0C4C: lui         $t3, 0x9F
    ctx->r11 = S32(0X9F << 16);
    // 0x801C0C50: ori         $t3, $t3, 0xC77C
    ctx->r11 = ctx->r11 | 0XC77C;
    // 0x801C0C54: lui         $t2, 0xED00
    ctx->r10 = S32(0XED00 << 16);
    // 0x801C0C58: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801C0C5C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801C0C60: b           L_801C0C84
    // 0x801C0C64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_801C0C84;
    // 0x801C0C64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_801C0C68:
    // 0x801C0C68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0C6C: lui         $t5, 0x4F
    ctx->r13 = S32(0X4F << 16);
    // 0x801C0C70: ori         $t5, $t5, 0xC3BC
    ctx->r13 = ctx->r13 | 0XC3BC;
    // 0x801C0C74: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x801C0C78: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801C0C7C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801C0C80: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_801C0C84:
    // 0x801C0C84: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0C88: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0C8C: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x801C0C90: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x801C0C94: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x801C0C98: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801C0C9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C0CA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801C0CA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0CA8: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x801C0CAC: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x801C0CB0: ori         $t9, $t9, 0xF67B
    ctx->r25 = ctx->r25 | 0XF67B;
    // 0x801C0CB4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x801C0CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0CBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C0CC0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C0CC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0CC8: lui         $t2, 0xD700
    ctx->r10 = S32(0XD700 << 16);
    // 0x801C0CCC: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x801C0CD0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801C0CD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C0CD8: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x801C0CDC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801C0CE0: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x801C0CE4: ori         $t4, $t4, 0xF00
    ctx->r12 = ctx->r12 | 0XF00;
    // 0x801C0CE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0CEC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x801C0CF0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801C0CF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801C0CF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0CFC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x801C0D00: ori         $t5, $t5, 0x1E01
    ctx->r13 = ctx->r13 | 0X1E01;
    // 0x801C0D04: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0D08: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801C0D0C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801C0D10: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0D14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C0D18: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x801C0D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0D20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C0D24: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801C0D28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0D2C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x801C0D30: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x801C0D34: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x801C0D38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C0D3C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x801C0D40: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801C0D44: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x801C0D48: ori         $t2, $t2, 0x1001
    ctx->r10 = ctx->r10 | 0X1001;
    // 0x801C0D4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0D50: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x801C0D54: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801C0D58: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x801C0D5C: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
    // 0x801C0D60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801C0D64: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C0D68: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0D6C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x801C0D70: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801C0D74: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x801C0D78: lui         $fp, 0xF510
    ctx->r30 = S32(0XF510 << 16);
    // 0x801C0D7C: lui         $s7, 0xFD10
    ctx->r23 = S32(0XFD10 << 16);
L_801C0D80:
    // 0x801C0D80: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801C0D84: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x801C0D88: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x801C0D8C: sll         $s5, $a3, 2
    ctx->r21 = S32(ctx->r7 << 2);
    // 0x801C0D90: andi        $s5, $s5, 0xFFF
    ctx->r21 = ctx->r21 & 0XFFF;
    // 0x801C0D94: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801C0D98: sll         $s6, $a2, 2
    ctx->r22 = S32(ctx->r6 << 2);
    // 0x801C0D9C: andi        $s6, $s6, 0xFFF
    ctx->r22 = ctx->r22 & 0XFFF;
    // 0x801C0DA0: addiu       $t3, $t3, -0x37A8
    ctx->r11 = ADD32(ctx->r11, -0X37A8);
    // 0x801C0DA4: sll         $s5, $s5, 12
    ctx->r21 = S32(ctx->r21 << 12);
    // 0x801C0DA8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x801C0DAC: or          $s5, $s5, $at
    ctx->r21 = ctx->r21 | ctx->r1;
    // 0x801C0DB0: sll         $s6, $s6, 12
    ctx->r22 = S32(ctx->r22 << 12);
    // 0x801C0DB4: addiu       $s3, $zero, 0x58
    ctx->r19 = ADD32(0, 0X58);
    // 0x801C0DB8: addiu       $s1, $zero, 0x38
    ctx->r17 = ADD32(0, 0X38);
    // 0x801C0DBC: addu        $s2, $v1, $t3
    ctx->r18 = ADD32(ctx->r3, ctx->r11);
L_801C0DC0:
    // 0x801C0DC0: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x801C0DC4: sw          $s7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r23;
    // 0x801C0DC8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x801C0DCC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0DD0: jal         0x8000522C
    // 0x801C0DD4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_1;
    // 0x801C0DD4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
    // 0x801C0DD8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801C0DDC: lui         $t4, 0x709
    ctx->r12 = S32(0X709 << 16);
    // 0x801C0DE0: ori         $t4, $t4, 0xC260
    ctx->r12 = ctx->r12 | 0XC260;
    // 0x801C0DE4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0DE8: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x801C0DEC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801C0DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0DF4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0DF8: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801C0DFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C0E00: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x801C0E04: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801C0E08: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x801C0E0C: lui         $t7, 0x77F
    ctx->r15 = S32(0X77F << 16);
    // 0x801C0E10: ori         $t7, $t7, 0xF080
    ctx->r15 = ctx->r15 | 0XF080;
    // 0x801C0E14: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0E18: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x801C0E1C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x801C0E20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801C0E24: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x801C0E28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0E2C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801C0E30: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C0E34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801C0E38: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0E3C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801C0E40: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x801C0E44: lui         $t2, 0x9
    ctx->r10 = S32(0X9 << 16);
    // 0x801C0E48: ori         $t2, $t2, 0xC260
    ctx->r10 = ctx->r10 | 0XC260;
    // 0x801C0E4C: ori         $t9, $t9, 0x2000
    ctx->r25 = ctx->r25 | 0X2000;
    // 0x801C0E50: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0E54: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x801C0E58: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x801C0E5C: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x801C0E60: ori         $t4, $t4, 0xC07C
    ctx->r12 = ctx->r12 | 0XC07C;
    // 0x801C0E64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0E68: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x801C0E6C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801C0E70: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801C0E74: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801C0E78: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x801C0E7C: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x801C0E80: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x801C0E84: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801C0E88: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C0E90: or          $t2, $s6, $t9
    ctx->r10 = ctx->r22 | ctx->r25;
    // 0x801C0E94: or          $t7, $s5, $t6
    ctx->r15 = ctx->r21 | ctx->r14;
    // 0x801C0E98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C0E9C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801C0EA0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0EA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C0EA8: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x801C0EAC: lui         $t3, 0xE100
    ctx->r11 = S32(0XE100 << 16);
    // 0x801C0EB0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x801C0EB4: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x801C0EB8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x801C0EBC: ori         $t5, $t5, 0x400
    ctx->r13 = ctx->r13 | 0X400;
    // 0x801C0EC0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x801C0EC4: lui         $t4, 0xF100
    ctx->r12 = S32(0XF100 << 16);
    // 0x801C0EC8: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x801C0ECC: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x801C0ED0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x801C0ED4: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x801C0ED8: bne         $s1, $at, L_801C0DC0
    if (ctx->r17 != ctx->r1) {
        // 0x801C0EDC: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_801C0DC0;
    }
    // 0x801C0EDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0EE0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x801C0EE4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x801C0EE8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x801C0EEC: addiu       $at, $zero, 0x180
    ctx->r1 = ADD32(0, 0X180);
    // 0x801C0EF0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x801C0EF4: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x801C0EF8: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x801C0EFC: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801C0F00: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x801C0F04: bne         $t3, $at, L_801C0D80
    if (ctx->r11 != ctx->r1) {
        // 0x801C0F08: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_801C0D80;
    }
    // 0x801C0F08: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x801C0F0C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C0F10: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x801C0F14: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x801C0F18: lui         $t4, 0xD700
    ctx->r12 = S32(0XD700 << 16);
    // 0x801C0F1C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801C0F20: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801C0F24: lui         $t6, 0xDF00
    ctx->r14 = S32(0XDF00 << 16);
    // 0x801C0F28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801C0F2C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801C0F30: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801C0F34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801C0F38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C0F3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0F40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C0F44: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C0F48: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C0F4C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801C0F50: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801C0F54: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801C0F58: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801C0F5C: jr          $ra
    // 0x801C0F60: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x801C0F60: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c0f64(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c0f64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0F64: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C0F68: jr          $ra
    // 0x801C0F6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C0F6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c0f70(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c0f70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0F74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C0F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0F7C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C0F80: jal         0x800058DC
    // 0x801C0F84: addiu       $a1, $a1, 0xF98
    ctx->r5 = ADD32(ctx->r5, 0XF98);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C0F84: addiu       $a1, $a1, 0xF98
    ctx->r5 = ADD32(ctx->r5, 0XF98);
    after_0:
    // 0x801C0F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C0F90: jr          $ra
    // 0x801C0F94: nop

    return;
    // 0x801C0F94: nop

;}
RECOMP_FUNC void M23_FUN_801c0f98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0F9C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801C0FA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C0FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0FA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C0FAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C0FB0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C0FB4: swc1        $f4, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f4.u32l;
    // 0x801C0FB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C0FBC: addiu       $a3, $a3, -0x1688
    ctx->r7 = ADD32(ctx->r7, -0X1688);
    // 0x801C0FC0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C0FC4: jal         0x8001B204
    // 0x801C0FC8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C0FC8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x801C0FCC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C0FD0: addiu       $a3, $a3, -0x166C
    ctx->r7 = ADD32(ctx->r7, -0X166C);
    // 0x801C0FD4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C0FD8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C0FDC: jal         0x8001B204
    // 0x801C0FE0: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C0FE0: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    after_1:
    // 0x801C0FE4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C0FE8: addiu       $a3, $a3, -0x1650
    ctx->r7 = ADD32(ctx->r7, -0X1650);
    // 0x801C0FEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C0FF0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C0FF4: jal         0x8001B204
    // 0x801C0FF8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C0FF8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_2:
    // 0x801C0FFC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1000: addiu       $a3, $a3, -0x1634
    ctx->r7 = ADD32(ctx->r7, -0X1634);
    // 0x801C1004: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C1008: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C100C: jal         0x8001B204
    // 0x801C1010: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C1010: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_3:
    // 0x801C1014: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1018: addiu       $a1, $a1, 0x1034
    ctx->r5 = ADD32(ctx->r5, 0X1034);
    // 0x801C101C: jal         0x800058DC
    // 0x801C1020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C1020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801C1024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C102C: jr          $ra
    // 0x801C1030: nop

    return;
    // 0x801C1030: nop

;}
RECOMP_FUNC void M23_FUN_801c1034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1034: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C1038: jr          $ra
    // 0x801C103C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C103C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1040(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1040: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C1044: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801C1048: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
    // 0x801C104C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801C1050: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C1054: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801C1058: blez        $a3, L_801C1080
    if (SIGNED(ctx->r7) <= 0) {
        // 0x801C105C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801C1080;
    }
    // 0x801C105C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C1060: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_801C1064:
    // 0x801C1064: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x801C1068: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801C106C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801C1070: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801C1074: sb          $a0, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r4;
    // 0x801C1078: bne         $at, $zero, L_801C1064
    if (ctx->r1 != 0) {
        // 0x801C107C: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_801C1064;
    }
    // 0x801C107C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_801C1080:
    // 0x801C1080: jr          $ra
    // 0x801C1084: nop

    return;
    // 0x801C1084: nop

;}
RECOMP_FUNC void M23_FUN_801c1088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1088: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C108C: lw          $a2, 0x30($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X30);
    // 0x801C1090: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801C1094: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801C1098: lbu         $v1, 0xB($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XB);
    // 0x801C109C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C10A0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x801C10A4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801C10A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801C10AC: bgez        $v1, L_801C10BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801C10B0: slti        $at, $v1, 0x100
        ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_801C10BC;
    }
    // 0x801C10B0: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x801C10B4: b           L_801C10D0
    // 0x801C10B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_801C10D0;
    // 0x801C10B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801C10BC:
    // 0x801C10BC: bne         $at, $zero, L_801C10D0
    if (ctx->r1 != 0) {
        // 0x801C10C0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C10D0;
    }
    // 0x801C10C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C10C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C10C8: b           L_801C10D0
    // 0x801C10CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801C10D0;
    // 0x801C10CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801C10D0:
    // 0x801C10D0: sb          $v1, 0xB($a2)
    MEM_B(0XB, ctx->r6) = ctx->r3;
    // 0x801C10D4: jr          $ra
    // 0x801C10D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x801C10D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c10dc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c10dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C10DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C10E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801C10E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801C10E8: andi        $s2, $a1, 0xFF
    ctx->r18 = ctx->r5 & 0XFF;
    // 0x801C10EC: sll         $s3, $a2, 24
    ctx->r19 = S32(ctx->r6 << 24);
    // 0x801C10F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C10F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C10F8: sra         $s3, $s3, 24
    ctx->r19 = S32(SIGNED(ctx->r19) >> 24);
    // 0x801C10FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C1100: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C1104: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801C1108: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C110C: blez        $s2, L_801C1140
    if (SIGNED(ctx->r18) <= 0) {
        // 0x801C1110: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801C1140;
    }
    // 0x801C1110: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C1114:
    // 0x801C1114: sll         $a1, $s3, 24
    ctx->r5 = S32(ctx->r19 << 24);
    // 0x801C1118: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801C111C: jal         0x801C1088
    // 0x801C1120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C1088)(rdram, ctx);
        goto after_0;
    // 0x801C1120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801C1124: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C1128: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C112C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x801C1130: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801C1134: bne         $at, $zero, L_801C1114
    if (ctx->r1 != 0) {
        // 0x801C1138: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_801C1114;
    }
    // 0x801C1138: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C113C: sb          $v1, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r3;
L_801C1140:
    // 0x801C1140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C1144: lbu         $v0, 0x2E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2E);
    // 0x801C1148: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C114C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C1150: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1154: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801C1158: jr          $ra
    // 0x801C115C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C115C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1160(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1160: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C1164: addiu       $v0, $v0, -0x3758
    ctx->r2 = ADD32(ctx->r2, -0X3758);
    // 0x801C1168: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c116c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c116c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C116C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1174: beq         $t6, $zero, L_801C11AC
    if (ctx->r14 == 0) {
        // 0x801C1178: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C11AC;
    }
    // 0x801C1178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C117C: jal         0x80145390
    // 0x801C1180: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    LOOKUP_FUNC(0x80145390)(rdram, ctx);
        goto after_0;
    // 0x801C1180: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    after_0:
    // 0x801C1184: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C1188: addiu       $v0, $v0, -0x3758
    ctx->r2 = ADD32(ctx->r2, -0X3758);
    // 0x801C118C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C1190: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1194: addiu       $a1, $a1, 0x258C
    ctx->r5 = ADD32(ctx->r5, 0X258C);
    // 0x801C1198: sh          $zero, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = 0;
    // 0x801C119C: jal         0x800058DC
    // 0x801C11A0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C11A0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x801C11A4: b           L_801C11AC
    // 0x801C11A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C11AC;
    // 0x801C11A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C11AC:
    // 0x801C11AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C11B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C11B4: jr          $ra
    // 0x801C11B8: nop

    return;
    // 0x801C11B8: nop

;}
RECOMP_FUNC void M23_FUN_801c11bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C11BC: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C11C0: addiu       $t0, $t0, -0x375C
    ctx->r8 = ADD32(ctx->r8, -0X375C);
    // 0x801C11C4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c11c8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c11c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C11C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C11CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C11D0: bne         $t6, $zero, L_801C1248
    if (ctx->r14 != 0) {
        // 0x801C11D4: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_801C1248;
    }
    // 0x801C11D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C11D8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C11DC: addiu       $t7, $t7, -0x3630
    ctx->r15 = ADD32(ctx->r15, -0X3630);
    // 0x801C11E0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C11E4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801C11E8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801C11EC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801C11F0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801C11F4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C11F8: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801C11FC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801C1200: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C1204: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C1208: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x801C120C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801C1210: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801C1214: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C1218: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801C121C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801C1220: jal         0x8012C4D0
    // 0x801C1224: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801C1224: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C1228: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C122C: addiu       $t0, $t0, -0x375C
    ctx->r8 = ADD32(ctx->r8, -0X375C);
    // 0x801C1230: beq         $v0, $zero, L_801C1248
    if (ctx->r2 == 0) {
        // 0x801C1234: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_801C1248;
    }
    // 0x801C1234: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x801C1238: lb          $t2, 0x2B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X2B);
    // 0x801C123C: sb          $t2, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r10;
    // 0x801C1240: b           L_801C124C
    // 0x801C1244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C124C;
    // 0x801C1244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C1248:
    // 0x801C1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C124C:
    // 0x801C124C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C1250: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C1254: jr          $ra
    // 0x801C1258: nop

    return;
    // 0x801C1258: nop

;}
RECOMP_FUNC void M23_FUN_801c125c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C125C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C1260: addiu       $v1, $v1, -0x375C
    ctx->r3 = ADD32(ctx->r3, -0X375C);
    // 0x801C1264: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1268(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C126C: sll         $a2, $a0, 24
    ctx->r6 = S32(ctx->r4 << 24);
    // 0x801C1270: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801C1274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1278: beq         $v0, $zero, L_801C129C
    if (ctx->r2 == 0) {
        // 0x801C127C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801C129C;
    }
    // 0x801C127C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C1280: sb          $a2, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r6;
    // 0x801C1284: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1288: addiu       $a1, $a1, 0x3410
    ctx->r5 = ADD32(ctx->r5, 0X3410);
    // 0x801C128C: jal         0x800058DC
    // 0x801C1290: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1290: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_0:
    // 0x801C1294: b           L_801C12A0
    // 0x801C1298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C12A0;
    // 0x801C1298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C129C:
    // 0x801C129C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C12A0:
    // 0x801C12A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C12A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C12A8: jr          $ra
    // 0x801C12AC: nop

    return;
    // 0x801C12AC: nop

;}
RECOMP_FUNC void M23_FUN_801c12b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C12B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C12B4: lw          $a0, -0x3760($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3760);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c12b8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c12b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C12B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C12BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C12C0: beq         $a0, $zero, L_801C12F8
    if (ctx->r4 == 0) {
        // 0x801C12C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C12F8;
    }
    // 0x801C12C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C12C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C12CC: lw          $a1, -0x375C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X375C);
    // 0x801C12D0: beq         $a1, $zero, L_801C12E8
    if (ctx->r5 == 0) {
        // 0x801C12D4: nop
    
            goto L_801C12E8;
    }
    // 0x801C12D4: nop

    // 0x801C12D8: jal         0x80005700
    // 0x801C12DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C12DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801C12E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C12E4: lw          $a0, -0x3760($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3760);
L_801C12E8:
    // 0x801C12E8: jal         0x80005700
    // 0x801C12EC: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C12EC: nop

    after_1:
    // 0x801C12F0: b           L_801C12F8
    // 0x801C12F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C12F8;
    // 0x801C12F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C12F8:
    // 0x801C12F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C12FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1300: jr          $ra
    // 0x801C1304: nop

    return;
    // 0x801C1304: nop

;}
RECOMP_FUNC void M23_FUN_801c1308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1308: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C130C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C1310: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C1314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C1318: sb          $zero, 0x17($v0)
    MEM_B(0X17, ctx->r2) = 0;
    // 0x801C131C: sb          $v1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r3;
    // 0x801C1320: sb          $zero, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = 0;
    // 0x801C1324: sb          $v1, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r3;
    // 0x801C1328: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x801C132C: jr          $ra
    // 0x801C1330: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    return;
    // 0x801C1330: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1334(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1334: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801C1338: jr          $ra
    // 0x801C133C: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    return;
    // 0x801C133C: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1340(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1340: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801C1344: jr          $ra
    // 0x801C1348: lhu         $v0, -0x6B80($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B80);
    return;
    // 0x801C1348: lhu         $v0, -0x6B80($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c134c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c134c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C134C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801C1350: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801C1354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C1358: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C135C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801C1360: jal         0x8001EAD0
    // 0x801C1364: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801C1364: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    after_0:
    // 0x801C1368: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    // 0x801C136C: jal         0x8001EB64
    // 0x801C1370: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801C1370: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801C1374: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801C1378: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C137C: sw          $s0, -0x3760($at)
    MEM_W(-0X3760, ctx->r1) = ctx->r16;
    // 0x801C1380: div.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x801C1384: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801C1388: jal         0x801C11BC
    // 0x801C138C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C11BC)(rdram, ctx);
        goto after_2;
    // 0x801C138C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801C1390: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C1394: lbu         $t6, -0x3734($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3734);
    // 0x801C1398: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C139C: bnel        $t6, $at, L_801C14F8
    if (ctx->r14 != ctx->r1) {
        // 0x801C13A0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C14F8;
    }
    goto skip_0;
    // 0x801C13A0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801C13A4: jal         0x80116E80
    // 0x801C13A8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_3;
    // 0x801C13A8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x801C13AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C13B0: addiu       $a1, $a1, -0x3644
    ctx->r5 = ADD32(ctx->r5, -0X3644);
    // 0x801C13B4: jal         0x80005670
    // 0x801C13B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x801C13B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801C13BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C13C0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C13C4: sw          $v0, -0x3758($at)
    MEM_W(-0X3758, ctx->r1) = ctx->r2;
    // 0x801C13C8: addiu       $a1, $a1, -0x361C
    ctx->r5 = ADD32(ctx->r5, -0X361C);
    // 0x801C13CC: jal         0x80005670
    // 0x801C13D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x801C13D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801C13D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C13D8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C13DC: sw          $v0, -0x3754($at)
    MEM_W(-0X3754, ctx->r1) = ctx->r2;
    // 0x801C13E0: addiu       $a1, $a1, -0x35F4
    ctx->r5 = ADD32(ctx->r5, -0X35F4);
    // 0x801C13E4: jal         0x80005670
    // 0x801C13E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x801C13E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801C13EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C13F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801C13F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C13F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C13FC: sw          $v0, -0x3750($at)
    MEM_W(-0X3750, ctx->r1) = ctx->r2;
    // 0x801C1400: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801C1404: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801C1408: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801C140C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C1410: bc1f        L_801C1420
    if (!c1cs) {
        // 0x801C1414: lui         $a0, 0x801D
        ctx->r4 = S32(0X801D << 16);
            goto L_801C1420;
    }
    // 0x801C1414: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1418: b           L_801C1424
    // 0x801C141C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_801C1424;
    // 0x801C141C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_801C1420:
    // 0x801C1420: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_801C1424:
    // 0x801C1424: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801C1428: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C142C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C1430: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801C1434: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C1438: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C143C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C1440: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C1444: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801C1448: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801C144C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801C1450: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C1454: addiu       $a0, $a0, -0x1520
    ctx->r4 = ADD32(ctx->r4, -0X1520);
    // 0x801C1458: addiu       $a1, $zero, 0x205
    ctx->r5 = ADD32(0, 0X205);
    // 0x801C145C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801C1460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801C1464: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C1468: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C146C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C1470: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801C1474: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C1478: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C147C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801C1480: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801C1484: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801C1488: jal         0x8011AAF4
    // 0x801C148C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_7;
    // 0x801C148C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x801C1490: jal         0x801C125C
    // 0x801C1494: addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    LOOKUP_FUNC(0x801C125C)(rdram, ctx);
        goto after_8;
    // 0x801C1494: addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    after_8:
    // 0x801C1498: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C149C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C14A0: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x801C14A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C14A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C14AC: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801C14B0: sb          $zero, 0x17($v1)
    MEM_B(0X17, ctx->r3) = 0;
    // 0x801C14B4: sb          $t0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r8;
    // 0x801C14B8: sb          $t0, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r8;
    // 0x801C14BC: sb          $zero, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = 0;
    // 0x801C14C0: sb          $t1, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r9;
    // 0x801C14C4: sb          $t1, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r9;
    // 0x801C14C8: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x801C14CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801C14D0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801C14D4: jal         0x80002364
    // 0x801C14D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_9;
    // 0x801C14D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x801C14DC: jal         0x800208C4
    // 0x801C14E0: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_10;
    // 0x801C14E0: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    after_10:
    // 0x801C14E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C14E8: addiu       $a1, $a1, 0x1508
    ctx->r5 = ADD32(ctx->r5, 0X1508);
    // 0x801C14EC: jal         0x800058DC
    // 0x801C14F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801C14F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801C14F4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C14F8:
    // 0x801C14F8: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801C14FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801C1500: jr          $ra
    // 0x801C1504: nop

    return;
    // 0x801C1504: nop

;}
RECOMP_FUNC void M23_FUN_801c1508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1508: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801C150C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C1510: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801C1514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C1518: jal         0x801C1334
    // 0x801C151C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_0;
    // 0x801C151C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C1520: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x801C1524: beq         $t6, $zero, L_801C1538
    if (ctx->r14 == 0) {
        // 0x801C1528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C1538;
    }
    // 0x801C1528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C152C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1530: jal         0x800058DC
    // 0x801C1534: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1534: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    after_1:
L_801C1538:
    // 0x801C1538: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801C153C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C1540: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801C1544: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x801C1548: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C154C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C1550: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C1554: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801C1558: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C155C: lwc1        $f10, -0xDA0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XDA0);
    // 0x801C1560: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C1564: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C1568: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C156C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801C1570: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C1574: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C1578: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C157C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801C1580: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C1584: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C1588: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C158C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C1590: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C1594: addiu       $a0, $a0, -0x14E8
    ctx->r4 = ADD32(ctx->r4, -0X14E8);
    // 0x801C1598: addiu       $a1, $zero, 0x219
    ctx->r5 = ADD32(0, 0X219);
    // 0x801C159C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801C15A0: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C15A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801C15A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C15AC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801C15B0: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C15B4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801C15B8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801C15BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801C15C0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801C15C4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801C15C8: jal         0x8011AAF4
    // 0x801C15CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x801C15CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801C15D0: lhu         $t1, 0x3C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X3C);
    // 0x801C15D4: addiu       $at, $zero, 0x1C2
    ctx->r1 = ADD32(0, 0X1C2);
    // 0x801C15D8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801C15DC: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x801C15E0: bne         $t3, $at, L_801C15F0
    if (ctx->r11 != ctx->r1) {
        // 0x801C15E4: sh          $t2, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r10;
            goto L_801C15F0;
    }
    // 0x801C15E4: sh          $t2, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r10;
    // 0x801C15E8: jal         0x801C11BC
    // 0x801C15EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801C11BC)(rdram, ctx);
        goto after_3;
    // 0x801C15EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
L_801C15F0:
    // 0x801C15F0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C15F4: lbu         $t4, -0x3734($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X3734);
    // 0x801C15F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C15FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C1600: bne         $t4, $at, L_801C1610
    if (ctx->r12 != ctx->r1) {
        // 0x801C1604: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_801C1610;
    }
    // 0x801C1604: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1608: jal         0x800058DC
    // 0x801C160C: addiu       $a1, $a1, 0x1624
    ctx->r5 = ADD32(ctx->r5, 0X1624);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C160C: addiu       $a1, $a1, 0x1624
    ctx->r5 = ADD32(ctx->r5, 0X1624);
    after_4:
L_801C1610:
    // 0x801C1610: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C1614: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801C1618: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801C161C: jr          $ra
    // 0x801C1620: nop

    return;
    // 0x801C1620: nop

;}
RECOMP_FUNC void M23_FUN_801c1624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1624: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801C1628: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C162C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801C1630: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C1634: jal         0x801C1334
    // 0x801C1638: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_0;
    // 0x801C1638: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C163C: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x801C1640: beq         $t6, $zero, L_801C1654
    if (ctx->r14 == 0) {
        // 0x801C1644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C1654;
    }
    // 0x801C1644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C1648: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C164C: jal         0x800058DC
    // 0x801C1650: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1650: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    after_1:
L_801C1654:
    // 0x801C1654: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1658: jal         0x80005700
    // 0x801C165C: lw          $a0, -0x3754($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3754);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801C165C: lw          $a0, -0x3754($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3754);
    after_2:
    // 0x801C1660: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1664: jal         0x80005700
    // 0x801C1668: lw          $a0, -0x3750($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3750);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C1668: lw          $a0, -0x3750($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3750);
    after_3:
    // 0x801C166C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801C1670: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C1674: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1678: sw          $zero, -0x3754($at)
    MEM_W(-0X3754, ctx->r1) = 0;
    // 0x801C167C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1680: sw          $zero, -0x3750($at)
    MEM_W(-0X3750, ctx->r1) = 0;
    // 0x801C1684: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801C1688: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C168C: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x801C1690: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C1694: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C1698: lui         $at, 0x422A
    ctx->r1 = S32(0X422A << 16);
    // 0x801C169C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C16A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C16A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C16A8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C16AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C16B0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C16B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C16B8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801C16BC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801C16C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C16C4: addiu       $a0, $a0, -0x14B0
    ctx->r4 = ADD32(ctx->r4, -0X14B0);
    // 0x801C16C8: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
    // 0x801C16CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801C16D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C16D4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C16D8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C16DC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801C16E0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801C16E4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801C16E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C16EC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801C16F0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801C16F4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801C16F8: jal         0x8011AAF4
    // 0x801C16FC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_4;
    // 0x801C16FC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801C1700: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C1704: addiu       $a1, $a1, -0x3608
    ctx->r5 = ADD32(ctx->r5, -0X3608);
    // 0x801C1708: jal         0x80005670
    // 0x801C170C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x801C170C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801C1710: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1714: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C1718: sw          $v0, -0x374C($at)
    MEM_W(-0X374C, ctx->r1) = ctx->r2;
    // 0x801C171C: addiu       $a1, $a1, -0x35E0
    ctx->r5 = ADD32(ctx->r5, -0X35E0);
    // 0x801C1720: jal         0x80005670
    // 0x801C1724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x801C1724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801C1728: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C172C: sw          $v0, -0x3748($at)
    MEM_W(-0X3748, ctx->r1) = ctx->r2;
    // 0x801C1730: jal         0x801C125C
    // 0x801C1734: addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    LOOKUP_FUNC(0x801C125C)(rdram, ctx);
        goto after_7;
    // 0x801C1734: addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    after_7:
    // 0x801C1738: jal         0x801C1160
    // 0x801C173C: nop

    LOOKUP_FUNC(0x801C1160)(rdram, ctx);
        goto after_8;
    // 0x801C173C: nop

    after_8:
    // 0x801C1740: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1744: addiu       $a1, $a1, 0x1764
    ctx->r5 = ADD32(ctx->r5, 0X1764);
    // 0x801C1748: jal         0x800058DC
    // 0x801C174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801C174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801C1750: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C1754: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801C1758: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801C175C: jr          $ra
    // 0x801C1760: nop

    return;
    // 0x801C1760: nop

;}
RECOMP_FUNC void M23_FUN_801c1764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C176C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C1770: jal         0x801C1334
    // 0x801C1774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_0;
    // 0x801C1774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C1778: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x801C177C: beq         $t6, $zero, L_801C1790
    if (ctx->r14 == 0) {
        // 0x801C1780: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C1790;
    }
    // 0x801C1780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C1784: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1788: jal         0x800058DC
    // 0x801C178C: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C178C: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    after_1:
L_801C1790:
    // 0x801C1790: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C1794: lbu         $t7, -0x3734($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3734);
    // 0x801C1798: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x801C179C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801C17A0: bne         $t7, $zero, L_801C17B8
    if (ctx->r15 != 0) {
        // 0x801C17A4: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_801C17B8;
    }
    // 0x801C17A4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C17A8: sh          $t8, 0x3C($t9)
    MEM_H(0X3C, ctx->r25) = ctx->r24;
    // 0x801C17AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C17B0: jal         0x800058DC
    // 0x801C17B4: addiu       $a1, $a1, 0x17C8
    ctx->r5 = ADD32(ctx->r5, 0X17C8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C17B4: addiu       $a1, $a1, 0x17C8
    ctx->r5 = ADD32(ctx->r5, 0X17C8);
    after_2:
L_801C17B8:
    // 0x801C17B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C17BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C17C0: jr          $ra
    // 0x801C17C4: nop

    return;
    // 0x801C17C4: nop

;}
RECOMP_FUNC void M23_FUN_801c17c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C17C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C17CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C17D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C17D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C17D8: jal         0x801C1334
    // 0x801C17DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_0;
    // 0x801C17DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C17E0: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x801C17E4: beq         $t6, $zero, L_801C17F8
    if (ctx->r14 == 0) {
        // 0x801C17E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C17F8;
    }
    // 0x801C17E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C17EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C17F0: jal         0x800058DC
    // 0x801C17F4: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C17F4: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    after_1:
L_801C17F8:
    // 0x801C17F8: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801C17FC: addiu       $t8, $zero, 0x384
    ctx->r24 = ADD32(0, 0X384);
    // 0x801C1800: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C1804: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801C1808: bne         $v0, $zero, L_801C1838
    if (ctx->r2 != 0) {
        // 0x801C180C: sh          $t7, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r15;
            goto L_801C1838;
    }
    // 0x801C180C: sh          $t7, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r15;
    // 0x801C1810: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1814: sh          $t8, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r24;
    // 0x801C1818: addiu       $a3, $a3, -0x1478
    ctx->r7 = ADD32(ctx->r7, -0X1478);
    // 0x801C181C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1820: jal         0x8001B204
    // 0x801C1824: addiu       $a2, $zero, 0xA2
    ctx->r6 = ADD32(0, 0XA2);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C1824: addiu       $a2, $zero, 0xA2
    ctx->r6 = ADD32(0, 0XA2);
    after_2:
    // 0x801C1828: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C182C: addiu       $a1, $a1, 0x184C
    ctx->r5 = ADD32(ctx->r5, 0X184C);
    // 0x801C1830: jal         0x800058DC
    // 0x801C1834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C1834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_801C1838:
    // 0x801C1838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C183C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C1840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1844: jr          $ra
    // 0x801C1848: nop

    return;
    // 0x801C1848: nop

;}
RECOMP_FUNC void M23_FUN_801c184c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C184C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C1850: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C1854: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C1858: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C185C: jal         0x801C1334
    // 0x801C1860: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_0;
    // 0x801C1860: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C1864: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x801C1868: beq         $t6, $zero, L_801C18B8
    if (ctx->r14 == 0) {
        // 0x801C186C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C18B8;
    }
    // 0x801C186C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C1870: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1874: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801C1878: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C187C: addiu       $a3, $a3, -0x1464
    ctx->r7 = ADD32(ctx->r7, -0X1464);
    // 0x801C1880: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1884: jal         0x8001B204
    // 0x801C1888: addiu       $a2, $zero, 0xA2
    ctx->r6 = ADD32(0, 0XA2);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C1888: addiu       $a2, $zero, 0xA2
    ctx->r6 = ADD32(0, 0XA2);
    after_1:
    // 0x801C188C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1890: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1894: addiu       $a1, $a1, 0x27DC
    ctx->r5 = ADD32(ctx->r5, 0X27DC);
    // 0x801C1898: jal         0x800058DC
    // 0x801C189C: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C189C: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    after_2:
    // 0x801C18A0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C18A4: addiu       $a1, $a1, 0x18FC
    ctx->r5 = ADD32(ctx->r5, 0X18FC);
    // 0x801C18A8: jal         0x800058DC
    // 0x801C18AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C18AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801C18B0: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801C18B4: sh          $t8, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r24;
L_801C18B8:
    // 0x801C18B8: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801C18BC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801C18C0: bne         $v0, $zero, L_801C18E8
    if (ctx->r2 != 0) {
        // 0x801C18C4: sh          $t9, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r25;
            goto L_801C18E8;
    }
    // 0x801C18C4: sh          $t9, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r25;
    // 0x801C18C8: jal         0x80020718
    // 0x801C18CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_4;
    // 0x801C18CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x801C18D0: jal         0x801C5A00
    // 0x801C18D4: nop

    LOOKUP_FUNC(0x801C5A00)(rdram, ctx);
        goto after_5;
    // 0x801C18D4: nop

    after_5:
    // 0x801C18D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C18DC: addiu       $a1, $a1, 0x2050
    ctx->r5 = ADD32(ctx->r5, 0X2050);
    // 0x801C18E0: jal         0x800058DC
    // 0x801C18E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C18E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801C18E8:
    // 0x801C18E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C18EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C18F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C18F4: jr          $ra
    // 0x801C18F8: nop

    return;
    // 0x801C18F8: nop

;}
RECOMP_FUNC void M23_FUN_801c18fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C18FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C1900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C1904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C1908: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C190C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C1910: addiu       $t8, $zero, 0x384
    ctx->r24 = ADD32(0, 0X384);
    // 0x801C1914: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1918: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801C191C: bne         $v0, $zero, L_801C1A20
    if (ctx->r2 != 0) {
        // 0x801C1920: sh          $t7, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r15;
            goto L_801C1A20;
    }
    // 0x801C1920: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801C1924: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x801C1928: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C192C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1930: sh          $t8, 0x3C($t9)
    MEM_H(0X3C, ctx->r25) = ctx->r24;
    // 0x801C1934: lbu         $a2, -0x373C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X373C);
    // 0x801C1938: addiu       $a3, $a3, -0x144C
    ctx->r7 = ADD32(ctx->r7, -0X144C);
    // 0x801C193C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C1940: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C1944: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C1948: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C194C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C1950: addiu       $a2, $a2, 0x76
    ctx->r6 = ADD32(ctx->r6, 0X76);
    // 0x801C1954: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C1958: jal         0x8001B204
    // 0x801C195C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C195C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_0:
    // 0x801C1960: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1964: addiu       $a3, $a3, -0x143C
    ctx->r7 = ADD32(ctx->r7, -0X143C);
    // 0x801C1968: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C196C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1970: jal         0x8001B204
    // 0x801C1974: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C1974: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    after_1:
    // 0x801C1978: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C197C: addiu       $a3, $a3, -0x142C
    ctx->r7 = ADD32(ctx->r7, -0X142C);
    // 0x801C1980: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C1984: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1988: jal         0x8001B204
    // 0x801C198C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C198C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x801C1990: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1994: addiu       $a3, $a3, -0x141C
    ctx->r7 = ADD32(ctx->r7, -0X141C);
    // 0x801C1998: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C199C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C19A0: jal         0x8001B204
    // 0x801C19A4: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C19A4: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_3:
    // 0x801C19A8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C19AC: addiu       $a3, $a3, -0x140C
    ctx->r7 = ADD32(ctx->r7, -0X140C);
    // 0x801C19B0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C19B4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C19B8: jal         0x8001B204
    // 0x801C19BC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C19BC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_4:
    // 0x801C19C0: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x801C19C4: lhu         $t0, 0x7754($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X7754);
    // 0x801C19C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C19CC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C19D0: bne         $t0, $at, L_801C19F8
    if (ctx->r8 != ctx->r1) {
        // 0x801C19D4: addiu       $a1, $zero, 0x7D0
        ctx->r5 = ADD32(0, 0X7D0);
            goto L_801C19F8;
    }
    // 0x801C19D4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C19D8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C19DC: addiu       $a3, $a3, -0x13FC
    ctx->r7 = ADD32(ctx->r7, -0X13FC);
    // 0x801C19E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C19E4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C19E8: jal         0x8001B204
    // 0x801C19EC: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C19EC: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_5:
    // 0x801C19F0: b           L_801C1A10
    // 0x801C19F4: nop

        goto L_801C1A10;
    // 0x801C19F4: nop

L_801C19F8:
    // 0x801C19F8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C19FC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801C1A00: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C1A04: addiu       $a3, $a3, -0x13EC
    ctx->r7 = ADD32(ctx->r7, -0X13EC);
    // 0x801C1A08: jal         0x8001B204
    // 0x801C1A0C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C1A0C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_6:
L_801C1A10:
    // 0x801C1A10: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1A14: addiu       $a1, $a1, 0x1DB8
    ctx->r5 = ADD32(ctx->r5, 0X1DB8);
    // 0x801C1A18: jal         0x800058DC
    // 0x801C1A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C1A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
L_801C1A20:
    // 0x801C1A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1A28: jr          $ra
    // 0x801C1A2C: nop

    return;
    // 0x801C1A2C: nop

;}
RECOMP_FUNC void M23_FUN_801c1a30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1A30: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C1A34: addiu       $v1, $v1, -0x375C
    ctx->r3 = ADD32(ctx->r3, -0X375C);
    // 0x801C1A38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1a3c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1a3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1A44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C1A48: bne         $v0, $zero, L_801C1A60
    if (ctx->r2 != 0) {
        // 0x801C1A4C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C1A60;
    }
    // 0x801C1A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1A50: jal         0x801C11BC
    // 0x801C1A54: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801C11BC)(rdram, ctx);
        goto after_0;
    // 0x801C1A54: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_0:
    // 0x801C1A58: b           L_801C1A78
    // 0x801C1A5C: nop

        goto L_801C1A78;
    // 0x801C1A5C: nop

L_801C1A60:
    // 0x801C1A60: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x801C1A64: sb          $t6, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r14;
    // 0x801C1A68: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1A6C: addiu       $a1, $a1, 0x33C8
    ctx->r5 = ADD32(ctx->r5, 0X33C8);
    // 0x801C1A70: jal         0x800058DC
    // 0x801C1A74: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1A74: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_1:
L_801C1A78:
    // 0x801C1A78: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1A7C: addiu       $a1, $a1, 0x1A98
    ctx->r5 = ADD32(ctx->r5, 0X1A98);
    // 0x801C1A80: jal         0x800058DC
    // 0x801C1A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C1A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801C1A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1A90: jr          $ra
    // 0x801C1A94: nop

    return;
    // 0x801C1A94: nop

;}
