#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8014b3b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B3B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B3B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B3BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8014B3C0: jal         0x8014B7CC
    // 0x8014B3C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B3C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014B3C8: beq         $v0, $zero, L_8014B3DC
    if (ctx->r2 == 0) {
        // 0x8014B3CC: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_8014B3DC;
    }
    // 0x8014B3CC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8014B3D0: sb          $t6, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r14;
    // 0x8014B3D4: b           L_8014B3E0
    // 0x8014B3D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014B3E0;
    // 0x8014B3D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014B3DC:
    // 0x8014B3DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B3E0:
    // 0x8014B3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B3E8: jr          $ra
    // 0x8014B3EC: nop

    return;
    // 0x8014B3EC: nop

;}
RECOMP_FUNC void M7_FUN_8014b3f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B3F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B3F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B3F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B3FC: jal         0x8014B7CC
    // 0x8014B400: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B400: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014B404: beq         $v0, $zero, L_8014B414
    if (ctx->r2 == 0) {
        // 0x8014B408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014B414;
    }
    // 0x8014B408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B40C: b           L_8014B418
    // 0x8014B410: lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8);
        goto L_8014B418;
    // 0x8014B410: lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8);
L_8014B414:
    // 0x8014B414: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
L_8014B418:
    // 0x8014B418: jr          $ra
    // 0x8014B41C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014B41C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014b420(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014b420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B42C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8014B430: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014B434: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8014B438: jal         0x8014B7CC
    // 0x8014B43C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B43C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8014B440: beql        $v0, $zero, L_8014B490
    if (ctx->r2 == 0) {
        // 0x8014B444: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014B490;
    }
    goto skip_0;
    // 0x8014B444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014B448: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8014B44C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8014B450: beql        $t6, $zero, L_8014B490
    if (ctx->r14 == 0) {
        // 0x8014B454: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014B490;
    }
    goto skip_1;
    // 0x8014B454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014B458: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8014B45C: swc1        $f4, 0x90($t7)
    MEM_W(0X90, ctx->r15) = ctx->f4.u32l;
    // 0x8014B460: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8014B464: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8014B468: swc1        $f6, 0x94($t8)
    MEM_W(0X94, ctx->r24) = ctx->f6.u32l;
    // 0x8014B46C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8014B470: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8014B474: swc1        $f8, 0x98($t9)
    MEM_W(0X98, ctx->r25) = ctx->f8.u32l;
    // 0x8014B478: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8014B47C: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8014B480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014B484: b           L_8014B490
    // 0x8014B488: sh          $t0, 0x9C($t1)
    MEM_H(0X9C, ctx->r9) = ctx->r8;
        goto L_8014B490;
    // 0x8014B488: sh          $t0, 0x9C($t1)
    MEM_H(0X9C, ctx->r9) = ctx->r8;
    // 0x8014B48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B490:
    // 0x8014B490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B498: jr          $ra
    // 0x8014B49C: nop

    return;
    // 0x8014B49C: nop

;}
RECOMP_FUNC void M7_FUN_8014b4a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B4A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B4A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B4AC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8014B4B0: jal         0x8014B7CC
    // 0x8014B4B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B4B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014B4B8: beq         $v0, $zero, L_8014B504
    if (ctx->r2 == 0) {
        // 0x8014B4BC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8014B504;
    }
    // 0x8014B4BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014B4C0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8014B4C4: beql        $t6, $zero, L_8014B508
    if (ctx->r14 == 0) {
        // 0x8014B4C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014B508;
    }
    goto skip_0;
    // 0x8014B4C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014B4CC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8014B4D0: lwc1        $f4, 0x90($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X90);
    // 0x8014B4D4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8014B4D8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8014B4DC: lwc1        $f6, 0x94($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X94);
    // 0x8014B4E0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8014B4E4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8014B4E8: lwc1        $f8, 0x98($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X98);
    // 0x8014B4EC: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8014B4F0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8014B4F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014B4F8: lh          $t1, 0x9C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X9C);
    // 0x8014B4FC: b           L_8014B508
    // 0x8014B500: sh          $t1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r9;
        goto L_8014B508;
    // 0x8014B500: sh          $t1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r9;
L_8014B504:
    // 0x8014B504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B508:
    // 0x8014B508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B50C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B510: jr          $ra
    // 0x8014B514: nop

    return;
    // 0x8014B514: nop

;}
RECOMP_FUNC void M7_FUN_8014b518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B518: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014B51C: addiu       $v0, $v0, -0x12CE
    ctx->r2 = ADD32(ctx->r2, -0X12CE);
    // 0x8014B520: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8014B524: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014B528: addiu       $a1, $a1, -0x12D0
    ctx->r5 = ADD32(ctx->r5, -0X12D0);
    // 0x8014B52C: bne         $t6, $zero, L_8014B568
    if (ctx->r14 != 0) {
            // 0x8014B530: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    LOOKUP_FUNC(0x8014B568)(rdram, ctx);
    return;
    }
    // 0x8014B530: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8014B534: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8014B538: ori         $at, $zero, 0x80F7
    ctx->r1 = 0 | 0X80F7;
    // 0x8014B53C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014B540: bnel        $at, $zero, L_8014B55C
    if (ctx->r1 != 0) {
        // 0x8014B544: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_8014B55C;
    }
    goto skip_0;
    // 0x8014B544: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8014B548: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014B54C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8014B550: b           L_8014B568
    // 0x8014B554: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    LOOKUP_FUNC(0x8014B568)(rdram, ctx);
    return;
    // 0x8014B554: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8014B558: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_8014B55C:
    // 0x8014B55C: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8014B560: jr          $ra
    // 0x8014B564: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x8014B564: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014b568(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014b568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B568: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014B56C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8014B570: addiu       $a1, $a1, -0x12D0
    ctx->r5 = ADD32(ctx->r5, -0X12D0);
    // 0x8014B574: addiu       $a3, $a3, -0xE94
    ctx->r7 = ADD32(ctx->r7, -0XE94);
    // 0x8014B578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B57C: addiu       $t0, $t0, -0xE88
    ctx->r8 = ADD32(ctx->r8, -0XE88);
    // 0x8014B580: ori         $a2, $zero, 0x80F6
    ctx->r6 = 0 | 0X80F6;
L_8014B584:
    // 0x8014B584: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014B588: addiu       $a0, $a0, -0x10C8
    ctx->r4 = ADD32(ctx->r4, -0X10C8);
    // 0x8014B58C: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
L_8014B590:
    // 0x8014B590: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8014B594: beq         $t9, $zero, L_8014B5AC
    if (ctx->r25 == 0) {
        // 0x8014B598: nop
    
            goto L_8014B5AC;
    }
    // 0x8014B598: nop

    // 0x8014B59C: lhu         $t1, 0x0($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X0);
    // 0x8014B5A0: lhu         $t2, 0x2($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X2);
    // 0x8014B5A4: beql        $t1, $t2, L_8014B5D4
    if (ctx->r9 == ctx->r10) {
        // 0x8014B5A8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8014B5D4;
    }
    goto skip_0;
    // 0x8014B5A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_8014B5AC:
    // 0x8014B5AC: bnel        $a0, $a3, L_8014B5C8
    if (ctx->r4 != ctx->r7) {
        // 0x8014B5B0: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_8014B5C8;
    }
    goto skip_1;
    // 0x8014B5B0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    skip_1:
    // 0x8014B5B4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8014B5B8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x8014B5BC: jr          $ra
    // 0x8014B5C0: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    return;
    // 0x8014B5C0: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x8014B5C4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
L_8014B5C8:
    // 0x8014B5C8: bnel        $a0, $t0, L_8014B590
    if (ctx->r4 != ctx->r8) {
        // 0x8014B5CC: lbu         $t8, 0x0($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X0);
            goto L_8014B590;
    }
    goto skip_2;
    // 0x8014B5CC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    skip_2:
    // 0x8014B5D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8014B5D4:
    // 0x8014B5D4: bne         $v0, $a2, L_8014B584
    if (ctx->r2 != ctx->r6) {
        // 0x8014B5D8: nop
    
            goto L_8014B584;
    }
    // 0x8014B5D8: nop

    // 0x8014B5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B5E0: jr          $ra
    // 0x8014B5E4: nop

    return;
    // 0x8014B5E4: nop

;}
RECOMP_FUNC void M7_FUN_8014b5e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B5E8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014B5EC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014B5F0: addiu       $v0, $v0, -0x10C8
    ctx->r2 = ADD32(ctx->r2, -0X10C8);
    // 0x8014B5F4: addiu       $v1, $v1, -0x12C8
    ctx->r3 = ADD32(ctx->r3, -0X12C8);
    // 0x8014B5F8: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_8014B5FC:
    // 0x8014B5FC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8014B600: bnel        $t7, $zero, L_8014B614
    if (ctx->r15 != 0) {
        // 0x8014B604: lbu         $t8, 0x10($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X10);
            goto L_8014B614;
    }
    goto skip_0;
    // 0x8014B604: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    skip_0:
    // 0x8014B608: jr          $ra
    // 0x8014B60C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8014B60C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8014B610: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
L_8014B614:
    // 0x8014B614: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8014B618: bnel        $t9, $zero, L_8014B62C
    if (ctx->r25 != 0) {
        // 0x8014B61C: lbu         $t0, 0x20($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X20);
            goto L_8014B62C;
    }
    goto skip_1;
    // 0x8014B61C: lbu         $t0, 0x20($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X20);
    skip_1:
    // 0x8014B620: jr          $ra
    // 0x8014B624: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    return;
    // 0x8014B624: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8014B628: lbu         $t0, 0x20($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X20);
L_8014B62C:
    // 0x8014B62C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8014B630: bnel        $t1, $zero, L_8014B644
    if (ctx->r9 != 0) {
        // 0x8014B634: lbu         $t2, 0x30($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X30);
            goto L_8014B644;
    }
    goto skip_2;
    // 0x8014B634: lbu         $t2, 0x30($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X30);
    skip_2:
    // 0x8014B638: jr          $ra
    // 0x8014B63C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    return;
    // 0x8014B63C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8014B640: lbu         $t2, 0x30($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X30);
L_8014B644:
    // 0x8014B644: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014B648: bnel        $t3, $zero, L_8014B65C
    if (ctx->r11 != 0) {
        // 0x8014B64C: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_8014B65C;
    }
    goto skip_3;
    // 0x8014B64C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    skip_3:
    // 0x8014B650: jr          $ra
    // 0x8014B654: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    return;
    // 0x8014B654: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8014B658: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_8014B65C:
    // 0x8014B65C: bnel        $v1, $v0, L_8014B5FC
    if (ctx->r3 != ctx->r2) {
        // 0x8014B660: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_8014B5FC;
    }
    goto skip_4;
    // 0x8014B660: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_4:
    // 0x8014B664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B668: jr          $ra
    // 0x8014B66C: nop

    return;
    // 0x8014B66C: nop

;}
RECOMP_FUNC void M7_FUN_8014b670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B670: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014B674: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014B678: addiu       $v0, $v0, -0xE88
    ctx->r2 = ADD32(ctx->r2, -0XE88);
    // 0x8014B67C: addiu       $v1, $v1, -0x10C8
    ctx->r3 = ADD32(ctx->r3, -0X10C8);
    // 0x8014B680: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_8014B684:
    // 0x8014B684: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8014B688: bnel        $t7, $zero, L_8014B69C
    if (ctx->r15 != 0) {
        // 0x8014B68C: lbu         $t8, 0xC($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XC);
            goto L_8014B69C;
    }
    goto skip_0;
    // 0x8014B68C: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
    skip_0:
    // 0x8014B690: jr          $ra
    // 0x8014B694: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8014B694: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8014B698: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
L_8014B69C:
    // 0x8014B69C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8014B6A0: bnel        $t9, $zero, L_8014B6B4
    if (ctx->r25 != 0) {
        // 0x8014B6A4: lbu         $t0, 0x18($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X18);
            goto L_8014B6B4;
    }
    goto skip_1;
    // 0x8014B6A4: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
    skip_1:
    // 0x8014B6A8: jr          $ra
    // 0x8014B6AC: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    return;
    // 0x8014B6AC: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // 0x8014B6B0: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
L_8014B6B4:
    // 0x8014B6B4: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8014B6B8: bnel        $t1, $zero, L_8014B6CC
    if (ctx->r9 != 0) {
        // 0x8014B6BC: lbu         $t2, 0x24($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X24);
            goto L_8014B6CC;
    }
    goto skip_2;
    // 0x8014B6BC: lbu         $t2, 0x24($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X24);
    skip_2:
    // 0x8014B6C0: jr          $ra
    // 0x8014B6C4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    return;
    // 0x8014B6C4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8014B6C8: lbu         $t2, 0x24($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X24);
L_8014B6CC:
    // 0x8014B6CC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014B6D0: bnel        $t3, $zero, L_8014B6E4
    if (ctx->r11 != 0) {
        // 0x8014B6D4: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8014B6E4;
    }
    goto skip_3;
    // 0x8014B6D4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_3:
    // 0x8014B6D8: jr          $ra
    // 0x8014B6DC: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    return;
    // 0x8014B6DC: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    // 0x8014B6E0: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_8014B6E4:
    // 0x8014B6E4: bnel        $v1, $v0, L_8014B684
    if (ctx->r3 != ctx->r2) {
        // 0x8014B6E8: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_8014B684;
    }
    goto skip_4;
    // 0x8014B6E8: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_4:
    // 0x8014B6EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B6F0: jr          $ra
    // 0x8014B6F4: nop

    return;
    // 0x8014B6F4: nop

;}
RECOMP_FUNC void M7_FUN_8014b6f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B6F8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8014B6FC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8014B700: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014B704: beq         $at, $zero, L_8014B714
    if (ctx->r1 == 0) {
            // 0x8014B708: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8014B714)(rdram, ctx);
    return;
    }
    // 0x8014B708: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8014B70C: jr          $ra
    // 0x8014B710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8014B710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014b714(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014b714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B714: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014B718: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014B71C: addiu       $v1, $v1, -0x10C8
    ctx->r3 = ADD32(ctx->r3, -0X10C8);
    // 0x8014B720: addiu       $a0, $a0, -0x12C8
    ctx->r4 = ADD32(ctx->r4, -0X12C8);
    // 0x8014B724: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8014B728:
    // 0x8014B728: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8014B72C: beql        $t7, $zero, L_8014B74C
    if (ctx->r15 == 0) {
        // 0x8014B730: lbu         $t9, 0x10($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X10);
            goto L_8014B74C;
    }
    goto skip_0;
    // 0x8014B730: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    skip_0:
    // 0x8014B734: lhu         $t8, 0xA($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XA);
    // 0x8014B738: bnel        $v0, $t8, L_8014B74C
    if (ctx->r2 != ctx->r24) {
        // 0x8014B73C: lbu         $t9, 0x10($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X10);
            goto L_8014B74C;
    }
    goto skip_1;
    // 0x8014B73C: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    skip_1:
    // 0x8014B740: jr          $ra
    // 0x8014B744: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8014B744: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8014B748: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
L_8014B74C:
    // 0x8014B74C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8014B750: beql        $t0, $zero, L_8014B770
    if (ctx->r8 == 0) {
        // 0x8014B754: lbu         $t2, 0x20($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X20);
            goto L_8014B770;
    }
    goto skip_2;
    // 0x8014B754: lbu         $t2, 0x20($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X20);
    skip_2:
    // 0x8014B758: lhu         $t1, 0x1A($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X1A);
    // 0x8014B75C: bnel        $v0, $t1, L_8014B770
    if (ctx->r2 != ctx->r9) {
        // 0x8014B760: lbu         $t2, 0x20($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X20);
            goto L_8014B770;
    }
    goto skip_3;
    // 0x8014B760: lbu         $t2, 0x20($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X20);
    skip_3:
    // 0x8014B764: jr          $ra
    // 0x8014B768: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    return;
    // 0x8014B768: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8014B76C: lbu         $t2, 0x20($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X20);
L_8014B770:
    // 0x8014B770: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014B774: beql        $t3, $zero, L_8014B794
    if (ctx->r11 == 0) {
        // 0x8014B778: lbu         $t5, 0x30($a0)
        ctx->r13 = MEM_BU(ctx->r4, 0X30);
            goto L_8014B794;
    }
    goto skip_4;
    // 0x8014B778: lbu         $t5, 0x30($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X30);
    skip_4:
    // 0x8014B77C: lhu         $t4, 0x2A($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2A);
    // 0x8014B780: bnel        $v0, $t4, L_8014B794
    if (ctx->r2 != ctx->r12) {
        // 0x8014B784: lbu         $t5, 0x30($a0)
        ctx->r13 = MEM_BU(ctx->r4, 0X30);
            goto L_8014B794;
    }
    goto skip_5;
    // 0x8014B784: lbu         $t5, 0x30($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X30);
    skip_5:
    // 0x8014B788: jr          $ra
    // 0x8014B78C: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    return;
    // 0x8014B78C: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x8014B790: lbu         $t5, 0x30($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X30);
L_8014B794:
    // 0x8014B794: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8014B798: beql        $t6, $zero, L_8014B7B8
    if (ctx->r14 == 0) {
        // 0x8014B79C: addiu       $a0, $a0, 0x40
        ctx->r4 = ADD32(ctx->r4, 0X40);
            goto L_8014B7B8;
    }
    goto skip_6;
    // 0x8014B79C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    skip_6:
    // 0x8014B7A0: lhu         $t7, 0x3A($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X3A);
    // 0x8014B7A4: bnel        $v0, $t7, L_8014B7B8
    if (ctx->r2 != ctx->r15) {
        // 0x8014B7A8: addiu       $a0, $a0, 0x40
        ctx->r4 = ADD32(ctx->r4, 0X40);
            goto L_8014B7B8;
    }
    goto skip_7;
    // 0x8014B7A8: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    skip_7:
    // 0x8014B7AC: jr          $ra
    // 0x8014B7B0: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    return;
    // 0x8014B7B0: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x8014B7B4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
L_8014B7B8:
    // 0x8014B7B8: bnel        $a0, $v1, L_8014B728
    if (ctx->r4 != ctx->r3) {
        // 0x8014B7BC: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8014B728;
    }
    goto skip_8;
    // 0x8014B7BC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_8:
    // 0x8014B7C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B7C4: jr          $ra
    // 0x8014B7C8: nop

    return;
    // 0x8014B7C8: nop

;}
RECOMP_FUNC void M7_FUN_8014b7cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B7CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8014B7D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014B7D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014B7D8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8014B7DC: addiu       $v0, $v0, -0xE88
    ctx->r2 = ADD32(ctx->r2, -0XE88);
    // 0x8014B7E0: addiu       $v1, $v1, -0x10C8
    ctx->r3 = ADD32(ctx->r3, -0X10C8);
    // 0x8014B7E4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_8014B7E8:
    // 0x8014B7E8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8014B7EC: beql        $t7, $zero, L_8014B820
    if (ctx->r15 == 0) {
        // 0x8014B7F0: lbu         $t2, 0xC($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0XC);
            goto L_8014B820;
    }
    goto skip_0;
    // 0x8014B7F0: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    skip_0:
    // 0x8014B7F4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8014B7F8: lhu         $t9, 0xA8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA8);
    // 0x8014B7FC: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8014B800: bnel        $t0, $zero, L_8014B820
    if (ctx->r8 != 0) {
        // 0x8014B804: lbu         $t2, 0xC($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0XC);
            goto L_8014B820;
    }
    goto skip_1;
    // 0x8014B804: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    skip_1:
    // 0x8014B808: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    // 0x8014B80C: bnel        $a0, $t1, L_8014B820
    if (ctx->r4 != ctx->r9) {
        // 0x8014B810: lbu         $t2, 0xC($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0XC);
            goto L_8014B820;
    }
    goto skip_2;
    // 0x8014B810: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    skip_2:
    // 0x8014B814: jr          $ra
    // 0x8014B818: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8014B818: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8014B81C: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
L_8014B820:
    // 0x8014B820: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014B824: beql        $t3, $zero, L_8014B858
    if (ctx->r11 == 0) {
        // 0x8014B828: lbu         $t8, 0x18($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X18);
            goto L_8014B858;
    }
    goto skip_3;
    // 0x8014B828: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    skip_3:
    // 0x8014B82C: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x8014B830: lhu         $t5, 0xA8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XA8);
    // 0x8014B834: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8014B838: bnel        $t6, $zero, L_8014B858
    if (ctx->r14 != 0) {
        // 0x8014B83C: lbu         $t8, 0x18($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X18);
            goto L_8014B858;
    }
    goto skip_4;
    // 0x8014B83C: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    skip_4:
    // 0x8014B840: lhu         $t7, 0xE($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XE);
    // 0x8014B844: bnel        $a0, $t7, L_8014B858
    if (ctx->r4 != ctx->r15) {
        // 0x8014B848: lbu         $t8, 0x18($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X18);
            goto L_8014B858;
    }
    goto skip_5;
    // 0x8014B848: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    skip_5:
    // 0x8014B84C: jr          $ra
    // 0x8014B850: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    return;
    // 0x8014B850: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // 0x8014B854: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
L_8014B858:
    // 0x8014B858: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8014B85C: beql        $t9, $zero, L_8014B890
    if (ctx->r25 == 0) {
        // 0x8014B860: lbu         $t4, 0x24($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X24);
            goto L_8014B890;
    }
    goto skip_6;
    // 0x8014B860: lbu         $t4, 0x24($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X24);
    skip_6:
    // 0x8014B864: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x8014B868: lhu         $t1, 0xA8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XA8);
    // 0x8014B86C: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x8014B870: bnel        $t2, $zero, L_8014B890
    if (ctx->r10 != 0) {
        // 0x8014B874: lbu         $t4, 0x24($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X24);
            goto L_8014B890;
    }
    goto skip_7;
    // 0x8014B874: lbu         $t4, 0x24($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X24);
    skip_7:
    // 0x8014B878: lhu         $t3, 0x1A($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X1A);
    // 0x8014B87C: bnel        $a0, $t3, L_8014B890
    if (ctx->r4 != ctx->r11) {
        // 0x8014B880: lbu         $t4, 0x24($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X24);
            goto L_8014B890;
    }
    goto skip_8;
    // 0x8014B880: lbu         $t4, 0x24($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X24);
    skip_8:
    // 0x8014B884: jr          $ra
    // 0x8014B888: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    return;
    // 0x8014B888: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8014B88C: lbu         $t4, 0x24($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X24);
L_8014B890:
    // 0x8014B890: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8014B894: beql        $t5, $zero, L_8014B8C8
    if (ctx->r13 == 0) {
        // 0x8014B898: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8014B8C8;
    }
    goto skip_9;
    // 0x8014B898: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_9:
    // 0x8014B89C: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x8014B8A0: lhu         $t7, 0xA8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XA8);
    // 0x8014B8A4: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8014B8A8: bnel        $t8, $zero, L_8014B8C8
    if (ctx->r24 != 0) {
        // 0x8014B8AC: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8014B8C8;
    }
    goto skip_10;
    // 0x8014B8AC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_10:
    // 0x8014B8B0: lhu         $t9, 0x26($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X26);
    // 0x8014B8B4: bnel        $a0, $t9, L_8014B8C8
    if (ctx->r4 != ctx->r25) {
        // 0x8014B8B8: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8014B8C8;
    }
    goto skip_11;
    // 0x8014B8B8: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_11:
    // 0x8014B8BC: jr          $ra
    // 0x8014B8C0: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    return;
    // 0x8014B8C0: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    // 0x8014B8C4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_8014B8C8:
    // 0x8014B8C8: bnel        $v1, $v0, L_8014B7E8
    if (ctx->r3 != ctx->r2) {
        // 0x8014B8CC: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_8014B7E8;
    }
    goto skip_12;
    // 0x8014B8CC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_12:
    // 0x8014B8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B8D4: jr          $ra
    // 0x8014B8D8: nop

    return;
    // 0x8014B8D8: nop

;}
RECOMP_FUNC void M7_FUN_8014b8dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B8DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014B8E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014B8E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8014B8E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8014B8EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014B8F0: jal         0x8012FF58
    // 0x8014B8F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8012FF58)(rdram, ctx);
        goto after_0;
    // 0x8014B8F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8014B8F8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8014B8FC: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8014B900: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8014B904: addiu       $s3, $s3, -0xE88
    ctx->r19 = ADD32(ctx->r19, -0XE88);
    // 0x8014B908: addiu       $s0, $s0, -0x10C8
    ctx->r16 = ADD32(ctx->r16, -0X10C8);
    // 0x8014B90C: ori         $s2, $zero, 0x8000
    ctx->r18 = 0 | 0X8000;
    // 0x8014B910: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8014B914:
    // 0x8014B914: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8014B918: beql        $t7, $zero, L_8014B9D8
    if (ctx->r15 == 0) {
        // 0x8014B91C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8014B9D8;
    }
    goto skip_0;
    // 0x8014B91C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x8014B920: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x8014B924: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8014B928: bnel        $at, $zero, L_8014B9D8
    if (ctx->r1 != 0) {
        // 0x8014B92C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8014B9D8;
    }
    goto skip_1;
    // 0x8014B92C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x8014B930: jal         0x8014B6F8
    // 0x8014B934: nop

    LOOKUP_FUNC(0x8014B6F8)(rdram, ctx);
        goto after_1;
    // 0x8014B934: nop

    after_1:
    // 0x8014B938: beq         $v0, $zero, L_8014B944
    if (ctx->r2 == 0) {
        // 0x8014B93C: nop
    
            goto L_8014B944;
    }
    // 0x8014B93C: nop

    // 0x8014B940: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8014B944:
    // 0x8014B944: jal         0x8014B5E8
    // 0x8014B948: nop

    LOOKUP_FUNC(0x8014B5E8)(rdram, ctx);
        goto after_2;
    // 0x8014B948: nop

    after_2:
    // 0x8014B94C: beql        $v0, $zero, L_8014B9D8
    if (ctx->r2 == 0) {
        // 0x8014B950: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8014B9D8;
    }
    goto skip_2;
    // 0x8014B950: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x8014B954: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8014B958: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8014B95C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x8014B960: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8014B964: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8014B968: lwc1        $f4, 0x90($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X90);
    // 0x8014B96C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8014B970: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8014B974: nop

    // 0x8014B978: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x8014B97C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8014B980: lwc1        $f8, 0x94($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X94);
    // 0x8014B984: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8014B988: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8014B98C: nop

    // 0x8014B990: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8014B994: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8014B998: lwc1        $f16, 0x98($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X98);
    // 0x8014B99C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8014B9A0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8014B9A4: nop

    // 0x8014B9A8: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x8014B9AC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8014B9B0: lh          $t0, 0x9C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X9C);
    // 0x8014B9B4: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x8014B9B8: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x8014B9BC: sh          $s1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r17;
    // 0x8014B9C0: sh          $t1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r9;
    // 0x8014B9C4: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
    // 0x8014B9C8: sb          $t2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r10;
    // 0x8014B9CC: lbu         $t3, 0x9($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X9);
    // 0x8014B9D0: sb          $t3, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r11;
    // 0x8014B9D4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8014B9D8:
    // 0x8014B9D8: bnel        $s0, $s3, L_8014B914
    if (ctx->r16 != ctx->r19) {
        // 0x8014B9DC: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8014B914;
    }
    goto skip_3;
    // 0x8014B9DC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_3:
    // 0x8014B9E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014B9E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8014B9E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8014B9EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8014B9F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8014B9F4: jr          $ra
    // 0x8014B9F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8014B9F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014b9fc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014b9fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B9FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014BA00: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014BA04: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8014BA08: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8014BA0C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8014BA10: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8014BA14: jal         0x8012FF58
    // 0x8014BA18: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x8012FF58)(rdram, ctx);
        goto after_0;
    // 0x8014BA18: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // 0x8014BA1C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8014BA20: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8014BA24: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8014BA28: addiu       $s4, $s4, -0x10C8
    ctx->r20 = ADD32(ctx->r20, -0X10C8);
    // 0x8014BA2C: addiu       $s0, $s0, -0x12C8
    ctx->r16 = ADD32(ctx->r16, -0X12C8);
    // 0x8014BA30: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_8014BA34:
    // 0x8014BA34: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8014BA38: beql        $t6, $zero, L_8014BB28
    if (ctx->r14 == 0) {
        // 0x8014BA3C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8014BB28;
    }
    goto skip_0;
    // 0x8014BA3C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x8014BA40: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x8014BA44: bnel        $s3, $t7, L_8014BB28
    if (ctx->r19 != ctx->r15) {
        // 0x8014BA48: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8014BB28;
    }
    goto skip_1;
    // 0x8014BA48: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_1:
    // 0x8014BA4C: lhu         $t8, 0xA($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XA);
    // 0x8014BA50: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x8014BA54: andi        $t9, $s2, 0x2
    ctx->r25 = ctx->r18 & 0X2;
    // 0x8014BA58: beql        $t8, $zero, L_8014BB28
    if (ctx->r24 == 0) {
        // 0x8014BA5C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8014BB28;
    }
    goto skip_2;
    // 0x8014BA5C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_2:
    // 0x8014BA60: bne         $t9, $zero, L_8014BAB8
    if (ctx->r25 != 0) {
        // 0x8014BA64: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8014BAB8;
    }
    // 0x8014BA64: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8014BA68: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x8014BA6C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8014BA70: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x8014BA74: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8014BA78: lhu         $t3, 0xA($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA);
    // 0x8014BA7C: lbu         $t4, 0xC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XC);
    // 0x8014BA80: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014BA84: lbu         $t5, 0xD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XD);
    // 0x8014BA88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8014BA8C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8014BA90: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x8014BA94: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8014BA98: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8014BA9C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8014BAA0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8014BAA4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014BAA8: jal         0x8014ADB4
    // 0x8014BAAC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    LOOKUP_FUNC(0x8014ADB4)(rdram, ctx);
        goto after_1;
    // 0x8014BAAC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x8014BAB0: b           L_8014BB04
    // 0x8014BAB4: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
        goto L_8014BB04;
    // 0x8014BAB4: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
L_8014BAB8:
    // 0x8014BAB8: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x8014BABC: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8014BAC0: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8014BAC4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8014BAC8: lhu         $t9, 0xA($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA);
    // 0x8014BACC: lbu         $t0, 0xC($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XC);
    // 0x8014BAD0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014BAD4: lbu         $t1, 0xD($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XD);
    // 0x8014BAD8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8014BADC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8014BAE0: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x8014BAE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8014BAE8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8014BAEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8014BAF0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8014BAF4: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014BAF8: jal         0x8014AEF4
    // 0x8014BAFC: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    LOOKUP_FUNC(0x8014AEF4)(rdram, ctx);
        goto after_2;
    // 0x8014BAFC: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_2:
    // 0x8014BB00: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
L_8014BB04:
    // 0x8014BB04: beq         $v0, $zero, L_8014BB24
    if (ctx->r2 == 0) {
        // 0x8014BB08: sb          $s2, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r18;
            goto L_8014BB24;
    }
    // 0x8014BB08: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // 0x8014BB0C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8014BB10: jal         0x8014B2FC
    // 0x8014BB14: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    LOOKUP_FUNC(0x8014B2FC)(rdram, ctx);
        goto after_3;
    // 0x8014BB14: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_3:
    // 0x8014BB18: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8014BB1C: jal         0x8014B28C
    // 0x8014BB20: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    LOOKUP_FUNC(0x8014B28C)(rdram, ctx);
        goto after_4;
    // 0x8014BB20: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_4:
L_8014BB24:
    // 0x8014BB24: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8014BB28:
    // 0x8014BB28: bnel        $s0, $s4, L_8014BA34
    if (ctx->r16 != ctx->r20) {
        // 0x8014BB2C: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_8014BA34;
    }
    goto skip_3;
    // 0x8014BB2C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_3:
    // 0x8014BB30: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014BB34: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8014BB38: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8014BB3C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8014BB40: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8014BB44: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8014BB48: jr          $ra
    // 0x8014BB4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8014BB4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014bb50(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014bb50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BB50: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014BB54: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014BB58: addiu       $a1, $a1, -0xE88
    ctx->r5 = ADD32(ctx->r5, -0XE88);
    // 0x8014BB5C: addiu       $v1, $v1, -0x10C8
    ctx->r3 = ADD32(ctx->r3, -0X10C8);
    // 0x8014BB60: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    // 0x8014BB64: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_8014BB68:
    // 0x8014BB68: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8014BB6C: beql        $t7, $zero, L_8014BB90
    if (ctx->r15 == 0) {
        // 0x8014BB70: lbu         $t8, 0xC($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XC);
            goto L_8014BB90;
    }
    goto skip_0;
    // 0x8014BB70: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
    skip_0:
    // 0x8014BB74: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8014BB78: beq         $v0, $zero, L_8014BB8C
    if (ctx->r2 == 0) {
        // 0x8014BB7C: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8014BB8C;
    }
    // 0x8014BB7C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8014BB80: beql        $at, $zero, L_8014BB90
    if (ctx->r1 == 0) {
        // 0x8014BB84: lbu         $t8, 0xC($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XC);
            goto L_8014BB90;
    }
    goto skip_1;
    // 0x8014BB84: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
    skip_1:
    // 0x8014BB88: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8014BB8C:
    // 0x8014BB8C: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
L_8014BB90:
    // 0x8014BB90: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8014BB94: beql        $t9, $zero, L_8014BBB8
    if (ctx->r25 == 0) {
        // 0x8014BB98: lbu         $t0, 0x18($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X18);
            goto L_8014BBB8;
    }
    goto skip_2;
    // 0x8014BB98: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
    skip_2:
    // 0x8014BB9C: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x8014BBA0: beq         $v0, $zero, L_8014BBB4
    if (ctx->r2 == 0) {
        // 0x8014BBA4: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8014BBB4;
    }
    // 0x8014BBA4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8014BBA8: beql        $at, $zero, L_8014BBB8
    if (ctx->r1 == 0) {
        // 0x8014BBAC: lbu         $t0, 0x18($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X18);
            goto L_8014BBB8;
    }
    goto skip_3;
    // 0x8014BBAC: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
    skip_3:
    // 0x8014BBB0: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
L_8014BBB4:
    // 0x8014BBB4: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
L_8014BBB8:
    // 0x8014BBB8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8014BBBC: beql        $t1, $zero, L_8014BBE0
    if (ctx->r9 == 0) {
        // 0x8014BBC0: lbu         $t2, 0x24($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X24);
            goto L_8014BBE0;
    }
    goto skip_4;
    // 0x8014BBC0: lbu         $t2, 0x24($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X24);
    skip_4:
    // 0x8014BBC4: lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1A);
    // 0x8014BBC8: beq         $v0, $zero, L_8014BBDC
    if (ctx->r2 == 0) {
        // 0x8014BBCC: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8014BBDC;
    }
    // 0x8014BBCC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8014BBD0: beql        $at, $zero, L_8014BBE0
    if (ctx->r1 == 0) {
        // 0x8014BBD4: lbu         $t2, 0x24($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X24);
            goto L_8014BBE0;
    }
    goto skip_5;
    // 0x8014BBD4: lbu         $t2, 0x24($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X24);
    skip_5:
    // 0x8014BBD8: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
L_8014BBDC:
    // 0x8014BBDC: lbu         $t2, 0x24($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X24);
L_8014BBE0:
    // 0x8014BBE0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014BBE4: beql        $t3, $zero, L_8014BC08
    if (ctx->r11 == 0) {
        // 0x8014BBE8: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8014BC08;
    }
    goto skip_6;
    // 0x8014BBE8: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_6:
    // 0x8014BBEC: lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X26);
    // 0x8014BBF0: beq         $v0, $zero, L_8014BC04
    if (ctx->r2 == 0) {
        // 0x8014BBF4: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8014BC04;
    }
    // 0x8014BBF4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8014BBF8: beql        $at, $zero, L_8014BC08
    if (ctx->r1 == 0) {
        // 0x8014BBFC: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8014BC08;
    }
    goto skip_7;
    // 0x8014BBFC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_7:
    // 0x8014BC00: sb          $zero, 0x24($v1)
    MEM_B(0X24, ctx->r3) = 0;
L_8014BC04:
    // 0x8014BC04: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_8014BC08:
    // 0x8014BC08: bnel        $v1, $a1, L_8014BB68
    if (ctx->r3 != ctx->r5) {
        // 0x8014BC0C: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_8014BB68;
    }
    goto skip_8;
    // 0x8014BC0C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_8:
    // 0x8014BC10: jr          $ra
    // 0x8014BC14: nop

    return;
    // 0x8014BC14: nop

;}
RECOMP_FUNC void M7_FUN_8014bc18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BC18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014BC1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014BC20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8014BC24: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8014BC28: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8014BC2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014BC30: addiu       $s1, $s1, -0xE88
    ctx->r17 = ADD32(ctx->r17, -0XE88);
    // 0x8014BC34: addiu       $s0, $s0, -0x10C8
    ctx->r16 = ADD32(ctx->r16, -0X10C8);
    // 0x8014BC38: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_8014BC3C:
    // 0x8014BC3C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8014BC40: beq         $t6, $zero, L_8014BC58
    if (ctx->r14 == 0) {
        // 0x8014BC44: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_8014BC58;
    }
    // 0x8014BC44: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x8014BC48: beq         $t7, $zero, L_8014BC58
    if (ctx->r15 == 0) {
        // 0x8014BC4C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8014BC58;
    }
    // 0x8014BC4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014BC50: jal         0x8014B034
    // 0x8014BC54: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    LOOKUP_FUNC(0x8014B034)(rdram, ctx);
        goto after_0;
    // 0x8014BC54: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    after_0:
L_8014BC58:
    // 0x8014BC58: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8014BC5C: bnel        $s0, $s1, L_8014BC3C
    if (ctx->r16 != ctx->r17) {
        // 0x8014BC60: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_8014BC3C;
    }
    goto skip_0;
    // 0x8014BC60: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_0:
    // 0x8014BC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BC68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8014BC6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8014BC70: jr          $ra
    // 0x8014BC74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8014BC74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014bc78(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014bc78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BC78: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8014BC7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014BC80: lwc1        $f4, 0x26C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X26C);
    // 0x8014BC84: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8014BC88: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8014BC8C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8014BC90: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8014BC94: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8014BC98: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8014BC9C: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8014BCA0: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8014BCA4: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x8014BCA8: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8014BCAC: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x8014BCB0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8014BCB4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8014BCB8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8014BCBC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8014BCC0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8014BCC4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8014BCC8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8014BCCC: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x8014BCD0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8014BCD4: addiu       $s4, $s4, -0x10C8
    ctx->r20 = ADD32(ctx->r20, -0X10C8);
    // 0x8014BCD8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8014BCDC: lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X0);
L_8014BCE0:
    // 0x8014BCE0: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8014BCE4: beq         $t6, $zero, L_8014C014
    if (ctx->r14 == 0) {
        // 0x8014BCE8: nop
    
            goto L_8014C014;
    }
    // 0x8014BCE8: nop

    // 0x8014BCEC: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8014BCF0: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8014BCF4: beq         $v0, $zero, L_8014C014
    if (ctx->r2 == 0) {
        // 0x8014BCF8: nop
    
            goto L_8014C014;
    }
    // 0x8014BCF8: nop

    // 0x8014BCFC: bnel        $t7, $zero, L_8014BE94
    if (ctx->r15 != 0) {
        // 0x8014BD00: lbu         $v1, 0x9($s4)
        ctx->r3 = MEM_BU(ctx->r20, 0X9);
            goto L_8014BE94;
    }
    goto skip_0;
    // 0x8014BD00: lbu         $v1, 0x9($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X9);
    skip_0:
    // 0x8014BD04: lbu         $v1, 0x8($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X8);
    // 0x8014BD08: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8014BD0C: addiu       $t9, $t9, 0x1E40
    ctx->r25 = ADD32(ctx->r25, 0X1E40);
    // 0x8014BD10: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8014BD14: addu        $s3, $t8, $t9
    ctx->r19 = ADD32(ctx->r24, ctx->r25);
    // 0x8014BD18: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8014BD1C: lh          $s2, 0x9C($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X9C);
    // 0x8014BD20: beq         $a0, $zero, L_8014C014
    if (ctx->r4 == 0) {
        // 0x8014BD24: nop
    
            goto L_8014C014;
    }
    // 0x8014BD24: nop

    // 0x8014BD28: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8014BD2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8014BD30: c.eq.s      $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f30.fl == ctx->f6.fl;
    // 0x8014BD34: nop

    // 0x8014BD38: bc1t        L_8014C014
    if (c1cs) {
        // 0x8014BD3C: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_8014C014;
    }
    // 0x8014BD3C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
L_8014BD40:
    // 0x8014BD40: jal         0x8001EB64
    // 0x8014BD44: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8014BD44: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8014BD48: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014BD4C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014BD50: jal         0x8001EAD0
    // 0x8014BD54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8014BD54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8014BD58: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8014BD5C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014BD60: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014BD64: addu        $s0, $t0, $s1
    ctx->r16 = ADD32(ctx->r8, ctx->r17);
    // 0x8014BD68: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8014BD6C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8014BD70: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8014BD74: nop

    // 0x8014BD78: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8014BD7C: jal         0x8001EAD0
    // 0x8014BD80: sub.s       $f22, $f10, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8014BD80: sub.s       $f22, $f10, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f6.fl;
    after_2:
    // 0x8014BD84: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014BD88: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014BD8C: jal         0x8001EB64
    // 0x8014BD90: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8014BD90: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x8014BD94: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8014BD98: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8014BD9C: addu        $s0, $t1, $s1
    ctx->r16 = ADD32(ctx->r9, ctx->r17);
    // 0x8014BDA0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8014BDA4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8014BDA8: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8014BDAC: lwc1        $f8, 0x90($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X90);
    // 0x8014BDB0: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8014BDB4: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014BDB8: lwc1        $f4, 0x98($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8014BDBC: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8014BDC0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8014BDC4: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8014BDC8: sub.s       $f2, $f24, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x8014BDCC: lwc1        $f10, 0x94($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X94);
    // 0x8014BDD0: sub.s       $f14, $f26, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x8014BDD4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8014BDD8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8014BDDC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8014BDE0: sub.s       $f16, $f28, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x8014BDE4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014BDE8: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8014BDEC: jal         0x8002FC20
    // 0x8014BDF0: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x8014BDF0: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_4:
    // 0x8014BDF4: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8014BDF8: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8014BDFC: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x8014BE00: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8014BE04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014BE08: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8014BE0C: nop

    // 0x8014BE10: bc1fl       L_8014BE70
    if (!c1cs) {
        // 0x8014BE14: lwc1        $f4, 0x1C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_8014BE70;
    }
    goto skip_1;
    // 0x8014BE14: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x8014BE18: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8014BE1C: lwc1        $f4, 0x90($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X90);
    // 0x8014BE20: lwc1        $f6, 0x94($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X94);
    // 0x8014BE24: lwc1        $f8, 0x98($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8014BE28: sub.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8014BE2C: sub.s       $f14, $f28, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f6.fl;
    // 0x8014BE30: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8014BE34: sub.s       $f16, $f26, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x8014BE38: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8014BE3C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8014BE40: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8014BE44: jal         0x8002FC20
    // 0x8014BE48: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_5;
    // 0x8014BE48: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_5:
    // 0x8014BE4C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8014BE50: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8014BE54: nop

    // 0x8014BE58: bc1f        L_8014C014
    if (!c1cs) {
        // 0x8014BE5C: nop
    
            goto L_8014C014;
    }
    // 0x8014BE5C: nop

    // 0x8014BE60: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8014BE64: b           L_8014C014
    // 0x8014BE68: lhu         $s5, 0x2($s4)
    ctx->r21 = MEM_HU(ctx->r20, 0X2);
        goto L_8014C014;
    // 0x8014BE68: lhu         $s5, 0x2($s4)
    ctx->r21 = MEM_HU(ctx->r20, 0X2);
    // 0x8014BE6C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
L_8014BE70:
    // 0x8014BE70: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8014BE74: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8014BE78: c.eq.s      $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f30.fl == ctx->f4.fl;
    // 0x8014BE7C: nop

    // 0x8014BE80: bc1fl       L_8014BD40
    if (!c1cs) {
        // 0x8014BE84: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_8014BD40;
    }
    goto skip_2;
    // 0x8014BE84: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    skip_2:
    // 0x8014BE88: b           L_8014C014
    // 0x8014BE8C: nop

        goto L_8014C014;
    // 0x8014BE8C: nop

    // 0x8014BE90: lbu         $v1, 0x9($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X9);
L_8014BE94:
    // 0x8014BE94: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8014BE98: addiu       $t4, $t4, 0x1F94
    ctx->r12 = ADD32(ctx->r12, 0X1F94);
    // 0x8014BE9C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8014BEA0: addu        $s3, $t3, $t4
    ctx->r19 = ADD32(ctx->r11, ctx->r12);
    // 0x8014BEA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8014BEA8: lh          $s2, 0x9C($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X9C);
    // 0x8014BEAC: beq         $a0, $zero, L_8014C014
    if (ctx->r4 == 0) {
        // 0x8014BEB0: nop
    
            goto L_8014C014;
    }
    // 0x8014BEB0: nop

    // 0x8014BEB4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8014BEB8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8014BEBC: c.eq.s      $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f30.fl == ctx->f6.fl;
    // 0x8014BEC0: nop

    // 0x8014BEC4: bc1t        L_8014C014
    if (c1cs) {
        // 0x8014BEC8: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_8014C014;
    }
    // 0x8014BEC8: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
L_8014BECC:
    // 0x8014BECC: jal         0x8001EB64
    // 0x8014BED0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x8014BED0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_6:
    // 0x8014BED4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014BED8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014BEDC: jal         0x8001EAD0
    // 0x8014BEE0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x8014BEE0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_7:
    // 0x8014BEE4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8014BEE8: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014BEEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014BEF0: addu        $s0, $t5, $s1
    ctx->r16 = ADD32(ctx->r13, ctx->r17);
    // 0x8014BEF4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8014BEF8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8014BEFC: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8014BF00: nop

    // 0x8014BF04: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8014BF08: jal         0x8001EAD0
    // 0x8014BF0C: sub.s       $f22, $f10, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x8014BF0C: sub.s       $f22, $f10, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f6.fl;
    after_8:
    // 0x8014BF10: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014BF14: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014BF18: jal         0x8001EB64
    // 0x8014BF1C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x8014BF1C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x8014BF20: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8014BF24: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8014BF28: addu        $s0, $t6, $s1
    ctx->r16 = ADD32(ctx->r14, ctx->r17);
    // 0x8014BF2C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8014BF30: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8014BF34: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8014BF38: lwc1        $f8, 0x90($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X90);
    // 0x8014BF3C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8014BF40: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014BF44: lwc1        $f4, 0x98($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8014BF48: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8014BF4C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8014BF50: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8014BF54: sub.s       $f2, $f24, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x8014BF58: lwc1        $f10, 0x94($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X94);
    // 0x8014BF5C: sub.s       $f14, $f26, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x8014BF60: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8014BF64: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8014BF68: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8014BF6C: sub.s       $f16, $f28, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x8014BF70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014BF74: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8014BF78: jal         0x8002FC20
    // 0x8014BF7C: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_10;
    // 0x8014BF7C: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_10:
    // 0x8014BF80: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8014BF84: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8014BF88: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
    // 0x8014BF8C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8014BF90: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014BF94: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8014BF98: nop

    // 0x8014BF9C: bc1fl       L_8014BFFC
    if (!c1cs) {
        // 0x8014BFA0: lwc1        $f4, 0x1C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_8014BFFC;
    }
    goto skip_3;
    // 0x8014BFA0: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    skip_3:
    // 0x8014BFA4: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8014BFA8: lwc1        $f4, 0x90($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X90);
    // 0x8014BFAC: lwc1        $f6, 0x94($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X94);
    // 0x8014BFB0: lwc1        $f8, 0x98($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8014BFB4: sub.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8014BFB8: sub.s       $f14, $f28, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f6.fl;
    // 0x8014BFBC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8014BFC0: sub.s       $f16, $f26, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x8014BFC4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8014BFC8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8014BFCC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8014BFD0: jal         0x8002FC20
    // 0x8014BFD4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_11;
    // 0x8014BFD4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_11:
    // 0x8014BFD8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8014BFDC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8014BFE0: nop

    // 0x8014BFE4: bc1f        L_8014C014
    if (!c1cs) {
        // 0x8014BFE8: nop
    
            goto L_8014C014;
    }
    // 0x8014BFE8: nop

    // 0x8014BFEC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8014BFF0: b           L_8014C014
    // 0x8014BFF4: lhu         $s5, 0x2($s4)
    ctx->r21 = MEM_HU(ctx->r20, 0X2);
        goto L_8014C014;
    // 0x8014BFF4: lhu         $s5, 0x2($s4)
    ctx->r21 = MEM_HU(ctx->r20, 0X2);
    // 0x8014BFF8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
L_8014BFFC:
    // 0x8014BFFC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8014C000: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8014C004: c.eq.s      $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f30.fl == ctx->f4.fl;
    // 0x8014C008: nop

    // 0x8014C00C: bc1fl       L_8014BECC
    if (!c1cs) {
        // 0x8014C010: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_8014BECC;
    }
    goto skip_4;
    // 0x8014C010: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    skip_4:
L_8014C014:
    // 0x8014C014: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8014C018: addiu       $t8, $t8, -0xE88
    ctx->r24 = ADD32(ctx->r24, -0XE88);
    // 0x8014C01C: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x8014C020: bnel        $s4, $t8, L_8014BCE0
    if (ctx->r20 != ctx->r24) {
        // 0x8014C024: lbu         $v1, 0x0($s4)
        ctx->r3 = MEM_BU(ctx->r20, 0X0);
            goto L_8014BCE0;
    }
    goto skip_5;
    // 0x8014C024: lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X0);
    skip_5:
    // 0x8014C028: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8014C02C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x8014C030: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8014C034: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8014C038: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8014C03C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8014C040: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8014C044: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8014C048: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8014C04C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8014C050: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8014C054: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8014C058: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8014C05C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8014C060: jr          $ra
    // 0x8014C064: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8014C064: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c068(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C074: jal         0x8014B7CC
    // 0x8014C078: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C078: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C07C: beq         $v0, $zero, L_8014C09C
    if (ctx->r2 == 0) {
        // 0x8014C080: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C09C;
    }
    // 0x8014C080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C084: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C088: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8014C08C: beql        $t7, $zero, L_8014C0A0
    if (ctx->r15 == 0) {
        // 0x8014C090: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C0A0;
    }
    goto skip_0;
    // 0x8014C090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014C094: b           L_8014C0A0
    // 0x8014C098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014C0A0;
    // 0x8014C098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014C09C:
    // 0x8014C09C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014C0A0:
    // 0x8014C0A0: jr          $ra
    // 0x8014C0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014C0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c0a8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c0a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C0AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C0B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C0B4: jal         0x8014B7CC
    // 0x8014C0B8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C0B8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C0BC: beq         $v0, $zero, L_8014C0E4
    if (ctx->r2 == 0) {
        // 0x8014C0C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C0E4;
    }
    // 0x8014C0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C0C4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C0C8: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8014C0CC: beq         $t6, $zero, L_8014C0E4
    if (ctx->r14 == 0) {
        // 0x8014C0D0: andi        $t7, $v1, 0x4
        ctx->r15 = ctx->r3 & 0X4;
            goto L_8014C0E4;
    }
    // 0x8014C0D0: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x8014C0D4: beql        $t7, $zero, L_8014C0E8
    if (ctx->r15 == 0) {
        // 0x8014C0D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C0E8;
    }
    goto skip_0;
    // 0x8014C0D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014C0DC: b           L_8014C0E8
    // 0x8014C0E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014C0E8;
    // 0x8014C0E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014C0E4:
    // 0x8014C0E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014C0E8:
    // 0x8014C0E8: jr          $ra
    // 0x8014C0EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014C0EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c0f0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c0f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C0F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C0FC: jal         0x8014B7CC
    // 0x8014C100: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C100: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C104: beq         $v0, $zero, L_8014C12C
    if (ctx->r2 == 0) {
        // 0x8014C108: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C12C;
    }
    // 0x8014C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C10C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C110: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8014C114: beq         $t6, $zero, L_8014C12C
    if (ctx->r14 == 0) {
        // 0x8014C118: andi        $t7, $v1, 0x8
        ctx->r15 = ctx->r3 & 0X8;
            goto L_8014C12C;
    }
    // 0x8014C118: andi        $t7, $v1, 0x8
    ctx->r15 = ctx->r3 & 0X8;
    // 0x8014C11C: beql        $t7, $zero, L_8014C130
    if (ctx->r15 == 0) {
        // 0x8014C120: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C130;
    }
    goto skip_0;
    // 0x8014C120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014C124: b           L_8014C130
    // 0x8014C128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014C130;
    // 0x8014C128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014C12C:
    // 0x8014C12C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014C130:
    // 0x8014C130: jr          $ra
    // 0x8014C134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014C134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c138(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C13C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C144: jal         0x8014B7CC
    // 0x8014C148: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C148: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C14C: beql        $v0, $zero, L_8014C184
    if (ctx->r2 == 0) {
        // 0x8014C150: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C184;
    }
    goto skip_0;
    // 0x8014C150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014C154: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C158: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8014C15C: beql        $t7, $zero, L_8014C184
    if (ctx->r15 == 0) {
        // 0x8014C160: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C184;
    }
    goto skip_1;
    // 0x8014C160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014C164: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8014C168: beql        $t8, $zero, L_8014C184
    if (ctx->r24 == 0) {
        // 0x8014C16C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C184;
    }
    goto skip_2;
    // 0x8014C16C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8014C170: jal         0x801FF348
    // 0x8014C174: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    LOOKUP_FUNC(0x801FF348)(rdram, ctx);
        goto after_1;
    // 0x8014C174: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x8014C178: b           L_8014C188
    // 0x8014C17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014C188;
    // 0x8014C17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014C184:
    // 0x8014C184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014C188:
    // 0x8014C188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C18C: jr          $ra
    // 0x8014C190: nop

    return;
    // 0x8014C190: nop

;}
RECOMP_FUNC void M7_FUN_8014c194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C19C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C1A0: jal         0x8014B7CC
    // 0x8014C1A4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C1A4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C1A8: beql        $v0, $zero, L_8014C1E0
    if (ctx->r2 == 0) {
        // 0x8014C1AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C1E0;
    }
    goto skip_0;
    // 0x8014C1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014C1B0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C1B4: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8014C1B8: beql        $t7, $zero, L_8014C1E0
    if (ctx->r15 == 0) {
        // 0x8014C1BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C1E0;
    }
    goto skip_1;
    // 0x8014C1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014C1C0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8014C1C4: beql        $t8, $zero, L_8014C1E0
    if (ctx->r24 == 0) {
        // 0x8014C1C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014C1E0;
    }
    goto skip_2;
    // 0x8014C1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8014C1CC: jal         0x801FF3D0
    // 0x8014C1D0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    LOOKUP_FUNC(0x801FF3D0)(rdram, ctx);
        goto after_1;
    // 0x8014C1D0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x8014C1D4: b           L_8014C1E4
    // 0x8014C1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014C1E4;
    // 0x8014C1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C1DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014C1E0:
    // 0x8014C1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014C1E4:
    // 0x8014C1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C1E8: jr          $ra
    // 0x8014C1EC: nop

    return;
    // 0x8014C1EC: nop

;}
RECOMP_FUNC void M7_FUN_8014c1f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C1F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C1FC: jal         0x8014B7CC
    // 0x8014C200: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C200: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C204: beq         $v0, $zero, L_8014C230
    if (ctx->r2 == 0) {
        // 0x8014C208: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C230;
    }
    // 0x8014C208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C20C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C210: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8014C214: beql        $t7, $zero, L_8014C234
    if (ctx->r15 == 0) {
        // 0x8014C218: ori         $v0, $zero, 0xFF00
        ctx->r2 = 0 | 0XFF00;
            goto L_8014C234;
    }
    goto skip_0;
    // 0x8014C218: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
    skip_0:
    // 0x8014C21C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8014C220: beql        $t8, $zero, L_8014C234
    if (ctx->r24 == 0) {
        // 0x8014C224: ori         $v0, $zero, 0xFF00
        ctx->r2 = 0 | 0XFF00;
            goto L_8014C234;
    }
    goto skip_1;
    // 0x8014C224: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
    skip_1:
    // 0x8014C228: b           L_8014C234
    // 0x8014C22C: lbu         $v0, 0x9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X9);
        goto L_8014C234;
    // 0x8014C22C: lbu         $v0, 0x9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X9);
L_8014C230:
    // 0x8014C230: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
L_8014C234:
    // 0x8014C234: jr          $ra
    // 0x8014C238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014C238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c23c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c23c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C23C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C248: jal         0x8014B7CC
    // 0x8014C24C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014C24C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014C250: beql        $v0, $zero, L_8014C284
    if (ctx->r2 == 0) {
        // 0x8014C254: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C284;
    }
    goto skip_0;
    // 0x8014C254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014C258: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8014C25C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8014C260: beql        $t7, $zero, L_8014C284
    if (ctx->r15 == 0) {
        // 0x8014C264: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C284;
    }
    goto skip_1;
    // 0x8014C264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8014C268: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8014C26C: beql        $v1, $zero, L_8014C284
    if (ctx->r3 == 0) {
        // 0x8014C270: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C284;
    }
    goto skip_2;
    // 0x8014C270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8014C274: lhu         $t8, 0xA8($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XA8);
    // 0x8014C278: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8014C27C: sh          $t9, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r25;
    // 0x8014C280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014C284:
    // 0x8014C284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014C28C: jr          $ra
    // 0x8014C290: nop

    return;
    // 0x8014C290: nop

;}
RECOMP_FUNC void M7_FUN_8014c294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C294: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014C298: jr          $ra
    // 0x8014C29C: addiu       $v0, $v0, -0x12C8
    ctx->r2 = ADD32(ctx->r2, -0X12C8);
    return;
    // 0x8014C29C: addiu       $v0, $v0, -0x12C8
    ctx->r2 = ADD32(ctx->r2, -0X12C8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c2a0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c2a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C2A0: jr          $ra
    // 0x8014C2A4: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    return;
    // 0x8014C2A4: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c2a8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c2a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C2A8: nop

    // 0x8014C2AC: nop

;}
RECOMP_FUNC void M7_FUN_8014c2b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C2B0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8014C2B4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8014C2B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8014C2BC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8014C2C0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014C2C4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8014C2C8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8014C2CC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8014C2D0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8014C2D4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8014C2D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8014C2DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014C2E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8014C2E4: jal         0x80126CC0
    // 0x8014C2E8: addiu       $a1, $a1, -0x2DFC
    ctx->r5 = ADD32(ctx->r5, -0X2DFC);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x8014C2E8: addiu       $a1, $a1, -0x2DFC
    ctx->r5 = ADD32(ctx->r5, -0X2DFC);
    after_0:
    // 0x8014C2EC: beql        $v0, $zero, L_8014C6CC
    if (ctx->r2 == 0) {
        // 0x8014C2F0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8014C6CC;
    }
    goto skip_0;
    // 0x8014C2F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8014C2F4: jal         0x8001F7D4
    // 0x8014C2F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8001F7D4)(rdram, ctx);
        goto after_1;
    // 0x8014C2F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8014C2FC: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8014C300: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014C304: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014C308: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8014C30C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014C310: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x8014C314: sb          $t7, 0x90($s3)
    MEM_B(0X90, ctx->r19) = ctx->r15;
    // 0x8014C318: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8014C31C: srl         $t0, $t8, 16
    ctx->r8 = S32(U32(ctx->r24) >> 16);
    // 0x8014C320: sb          $t0, 0x91($s3)
    MEM_B(0X91, ctx->r19) = ctx->r8;
    // 0x8014C324: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x8014C328: srl         $t2, $t1, 24
    ctx->r10 = S32(U32(ctx->r9) >> 24);
    // 0x8014C32C: sb          $t2, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r10;
    // 0x8014C330: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8014C334: srl         $t5, $t3, 16
    ctx->r13 = S32(U32(ctx->r11) >> 16);
    // 0x8014C338: sb          $t5, 0xA5($s3)
    MEM_B(0XA5, ctx->r19) = ctx->r13;
    // 0x8014C33C: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8014C340: sh          $t7, 0x9E($s3)
    MEM_H(0X9E, ctx->r19) = ctx->r15;
    // 0x8014C344: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8014C348: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x8014C34C: sh          $t9, 0xA0($s3)
    MEM_H(0XA0, ctx->r19) = ctx->r25;
    // 0x8014C350: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    // 0x8014C354: sh          $t1, 0xA2($s3)
    MEM_H(0XA2, ctx->r19) = ctx->r9;
    // 0x8014C358: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8014C35C: sb          $zero, 0x9C($s3)
    MEM_B(0X9C, ctx->r19) = 0;
    // 0x8014C360: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8014C364: sb          $t3, 0xA6($s3)
    MEM_B(0XA6, ctx->r19) = ctx->r11;
L_8014C368:
    // 0x8014C368: lw          $t4, 0x3BC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X3BC);
    // 0x8014C36C: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8014C370: addiu       $s4, $s4, -0x4410
    ctx->r20 = ADD32(ctx->r20, -0X4410);
    // 0x8014C374: bne         $t4, $zero, L_8014C38C
    if (ctx->r12 != 0) {
        // 0x8014C378: addiu       $t5, $zero, 0x1E
        ctx->r13 = ADD32(0, 0X1E);
            goto L_8014C38C;
    }
    // 0x8014C378: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8014C37C: sw          $s3, 0x3BC($v1)
    MEM_W(0X3BC, ctx->r3) = ctx->r19;
    // 0x8014C380: sb          $v0, 0x9C($s3)
    MEM_B(0X9C, ctx->r19) = ctx->r2;
    // 0x8014C384: b           L_8014C3A0
    // 0x8014C388: sh          $t5, 0x3B8($s4)
    MEM_H(0X3B8, ctx->r20) = ctx->r13;
        goto L_8014C3A0;
    // 0x8014C388: sh          $t5, 0x3B8($s4)
    MEM_H(0X3B8, ctx->r20) = ctx->r13;
L_8014C38C:
    // 0x8014C38C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8014C390: bne         $v0, $a0, L_8014C368
    if (ctx->r2 != ctx->r4) {
        // 0x8014C394: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8014C368;
    }
    // 0x8014C394: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8014C398: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8014C39C: addiu       $s4, $s4, -0x4410
    ctx->r20 = ADD32(ctx->r20, -0X4410);
L_8014C3A0:
    // 0x8014C3A0: lbu         $t6, 0x90($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X90);
    // 0x8014C3A4: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x8014C3A8: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x8014C3AC: multu       $t6, $s7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014C3B0: addiu       $s6, $s6, 0x294C
    ctx->r22 = ADD32(ctx->r22, 0X294C);
    // 0x8014C3B4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8014C3B8: addiu       $t0, $t0, 0x4F40
    ctx->r8 = ADD32(ctx->r8, 0X4F40);
    // 0x8014C3BC: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8014C3C0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8014C3C4: ori         $t3, $t3, 0xC00
    ctx->r11 = ctx->r11 | 0XC00;
    // 0x8014C3C8: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8014C3CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8014C3D0: mflo        $t7
    ctx->r15 = lo;
    // 0x8014C3D4: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8014C3D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8014C3DC: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8014C3E0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8014C3E4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8014C3E8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8014C3EC: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x8014C3F0: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8014C3F4: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x8014C3F8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8014C3FC: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x8014C400: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8014C404: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x8014C408: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8014C40C: beq         $s5, $t5, L_8014C434
    if (ctx->r21 == ctx->r13) {
        // 0x8014C410: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_8014C434;
    }
    // 0x8014C410: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8014C414: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8014C418:
    // 0x8014C418: jal         0x80005E44
    // 0x8014C41C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x8014C41C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8014C420: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x8014C424: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8014C428: bnel        $s5, $t6, L_8014C418
    if (ctx->r21 != ctx->r14) {
        // 0x8014C42C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8014C418;
    }
    goto skip_1;
    // 0x8014C42C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
    // 0x8014C430: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8014C434:
    // 0x8014C434: jal         0x80006214
    // 0x8014C438: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x8014C438: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x8014C43C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8014C440: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8014C444: beq         $s5, $t8, L_8014C558
    if (ctx->r21 == ctx->r24) {
        // 0x8014C448: or          $s1, $t7, $zero
        ctx->r17 = ctx->r15 | 0;
            goto L_8014C558;
    }
    // 0x8014C448: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8014C44C: lw          $s0, 0x64($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X64);
L_8014C450:
    // 0x8014C450: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
    // 0x8014C454: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8014C458: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8014C45C: bnel        $t0, $zero, L_8014C470
    if (ctx->r8 != 0) {
        // 0x8014C460: lbu         $t1, 0x90($s3)
        ctx->r9 = MEM_BU(ctx->r19, 0X90);
            goto L_8014C470;
    }
    goto skip_2;
    // 0x8014C460: lbu         $t1, 0x90($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X90);
    skip_2:
    // 0x8014C464: jal         0x8012636C
    // 0x8014C468: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_4;
    // 0x8014C468: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x8014C46C: lbu         $t1, 0x90($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X90);
L_8014C470:
    // 0x8014C470: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8014C474: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014C478: mflo        $t2
    ctx->r10 = lo;
    // 0x8014C47C: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x8014C480: lhu         $v0, 0x4($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X4);
    // 0x8014C484: beql        $v0, $zero, L_8014C498
    if (ctx->r2 == 0) {
        // 0x8014C488: lw          $t5, 0x0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X0);
            goto L_8014C498;
    }
    goto skip_3;
    // 0x8014C488: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8014C48C: bnel        $v0, $at, L_8014C4B8
    if (ctx->r2 != ctx->r1) {
        // 0x8014C490: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_8014C4B8;
    }
    goto skip_4;
    // 0x8014C490: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x8014C494: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
L_8014C498:
    // 0x8014C498: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8014C49C: addiu       $t4, $t4, 0x26D8
    ctx->r12 = ADD32(ctx->r12, 0X26D8);
    // 0x8014C4A0: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    // 0x8014C4A4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8014C4A8: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x8014C4AC: b           L_8014C544
    // 0x8014C4B0: sw          $t4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r12;
        goto L_8014C544;
    // 0x8014C4B0: sw          $t4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r12;
    // 0x8014C4B4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_8014C4B8:
    // 0x8014C4B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8014C4BC: addiu       $t1, $t1, -0x50C8
    ctx->r9 = ADD32(ctx->r9, -0X50C8);
    // 0x8014C4C0: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8014C4C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8014C4C8: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8014C4CC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8014C4D0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8014C4D4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8014C4D8: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x8014C4DC: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x8014C4E0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8014C4E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8014C4E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8014C4EC: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x8014C4F0: sw          $t2, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r10;
    // 0x8014C4F4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8014C4F8: lbu         $t6, 0xF32($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XF32);
    // 0x8014C4FC: lw          $t8, 0x30($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X30);
    // 0x8014C500: sb          $t6, 0x4C($t8)
    MEM_B(0X4C, ctx->r24) = ctx->r14;
    // 0x8014C504: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8014C508: lbu         $t7, 0xF33($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0XF33);
    // 0x8014C50C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014C510: sb          $t7, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r15;
    // 0x8014C514: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8014C518: lbu         $t1, 0xF34($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0XF34);
    // 0x8014C51C: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8014C520: sb          $t1, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r9;
    // 0x8014C524: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8014C528: lbu         $t5, 0xF35($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0XF35);
    // 0x8014C52C: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8014C530: sb          $t5, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r13;
    // 0x8014C534: lhu         $a3, 0x2($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X2);
    // 0x8014C538: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    // 0x8014C53C: jal         0x8012C89C
    // 0x8014C540: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x8014C540: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    after_5:
L_8014C544:
    // 0x8014C544: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
    // 0x8014C548: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8014C54C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8014C550: bne         $s5, $t8, L_8014C450
    if (ctx->r21 != ctx->r24) {
        // 0x8014C554: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8014C450;
    }
    // 0x8014C554: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8014C558:
    // 0x8014C558: jal         0x8001F74C
    // 0x8014C55C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_6;
    // 0x8014C55C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8014C560: lw          $t9, 0x2C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X2C);
    // 0x8014C564: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8014C568: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014C56C: ori         $t7, $t9, 0x800
    ctx->r15 = ctx->r25 | 0X800;
    // 0x8014C570: sw          $t7, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r15;
    // 0x8014C574: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x8014C578: lbu         $t7, 0x91($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X91);
    // 0x8014C57C: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8014C580: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x8014C584: swc1        $f4, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->f4.u32l;
    // 0x8014C588: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x8014C58C: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8014C590: swc1        $f6, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f6.u32l;
    // 0x8014C594: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x8014C598: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8014C59C: swc1        $f8, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->f8.u32l;
    // 0x8014C5A0: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x8014C5A4: lh          $t4, 0x10($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X10);
    // 0x8014C5A8: sh          $t4, 0x84($s3)
    MEM_H(0X84, ctx->r19) = ctx->r12;
    // 0x8014C5AC: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x8014C5B0: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x8014C5B4: sh          $t6, 0x86($s3)
    MEM_H(0X86, ctx->r19) = ctx->r14;
    // 0x8014C5B8: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x8014C5BC: lh          $t9, 0x14($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X14);
    // 0x8014C5C0: sb          $zero, 0x93($s3)
    MEM_B(0X93, ctx->r19) = 0;
    // 0x8014C5C4: swc1        $f10, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->f10.u32l;
    // 0x8014C5C8: beq         $t0, $zero, L_8014C5F4
    if (ctx->r8 == 0) {
        // 0x8014C5CC: sh          $t9, 0x88($s3)
        MEM_H(0X88, ctx->r19) = ctx->r25;
            goto L_8014C5F4;
    }
    // 0x8014C5CC: sh          $t9, 0x88($s3)
    MEM_H(0X88, ctx->r19) = ctx->r25;
    // 0x8014C5D0: lbu         $t3, 0x90($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X90);
    // 0x8014C5D4: lhu         $a0, 0x36($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X36);
    // 0x8014C5D8: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014C5DC: mflo        $t1
    ctx->r9 = lo;
    // 0x8014C5E0: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x8014C5E4: jal         0x8012C97C
    // 0x8014C5E8: lhu         $a1, 0x10($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X10);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_7;
    // 0x8014C5E8: lhu         $a1, 0x10($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X10);
    after_7:
    // 0x8014C5EC: b           L_8014C614
    // 0x8014C5F0: sw          $v0, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->r2;
        goto L_8014C614;
    // 0x8014C5F0: sw          $v0, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->r2;
L_8014C5F4:
    // 0x8014C5F4: lbu         $t4, 0x90($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X90);
    // 0x8014C5F8: lhu         $a0, 0x36($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X36);
    // 0x8014C5FC: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014C600: mflo        $t5
    ctx->r13 = lo;
    // 0x8014C604: addu        $t6, $s6, $t5
    ctx->r14 = ADD32(ctx->r22, ctx->r13);
    // 0x8014C608: jal         0x8012C97C
    // 0x8014C60C: lhu         $a1, 0xE($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XE);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_8;
    // 0x8014C60C: lhu         $a1, 0xE($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XE);
    after_8:
    // 0x8014C610: sw          $v0, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->r2;
L_8014C614:
    // 0x8014C614: lbu         $t8, 0x3A6($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X3A6);
    // 0x8014C618: lbu         $t9, 0xA4($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0XA4);
    // 0x8014C61C: bnel        $t8, $t9, L_8014C65C
    if (ctx->r24 != ctx->r25) {
        // 0x8014C620: lbu         $t4, 0x91($s3)
        ctx->r12 = MEM_BU(ctx->r19, 0X91);
            goto L_8014C65C;
    }
    goto skip_5;
    // 0x8014C620: lbu         $t4, 0x91($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X91);
    skip_5:
    // 0x8014C624: lw          $t7, 0x38($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X38);
    // 0x8014C628: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014C62C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8014C630: lw          $t0, 0x10($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X10);
    // 0x8014C634: srl         $t3, $t0, 8
    ctx->r11 = S32(U32(ctx->r8) >> 8);
    // 0x8014C638: andi        $t1, $t3, 0xFF
    ctx->r9 = ctx->r11 & 0XFF;
    // 0x8014C63C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014C640: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8014C644: lw          $v0, 0x2694($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2694);
    // 0x8014C648: beql        $v0, $zero, L_8014C65C
    if (ctx->r2 == 0) {
        // 0x8014C64C: lbu         $t4, 0x91($s3)
        ctx->r12 = MEM_BU(ctx->r19, 0X91);
            goto L_8014C65C;
    }
    goto skip_6;
    // 0x8014C64C: lbu         $t4, 0x91($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X91);
    skip_6:
    // 0x8014C650: jalr        $v0
    // 0x8014C654: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x8014C654: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_9:
    // 0x8014C658: lbu         $t4, 0x91($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X91);
L_8014C65C:
    // 0x8014C65C: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x8014C660: beq         $t5, $zero, L_8014C6B8
    if (ctx->r13 == 0) {
        // 0x8014C664: nop
    
            goto L_8014C6B8;
    }
    // 0x8014C664: nop

    // 0x8014C668: lbu         $t6, 0x90($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X90);
    // 0x8014C66C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014C670: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8014C674: multu       $t6, $s7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014C678: mflo        $t8
    ctx->r24 = lo;
    // 0x8014C67C: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8014C680: lhu         $t7, 0x4($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X4);
    // 0x8014C684: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8014C688: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8014C68C: lw          $v0, 0x2268($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2268);
    // 0x8014C690: beq         $v0, $zero, L_8014C6A0
    if (ctx->r2 == 0) {
        // 0x8014C694: nop
    
            goto L_8014C6A0;
    }
    // 0x8014C694: nop

    // 0x8014C698: jalr        $v0
    // 0x8014C69C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x8014C69C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_10:
L_8014C6A0:
    // 0x8014C6A0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014C6A4: addiu       $a1, $a1, -0x2F90
    ctx->r5 = ADD32(ctx->r5, -0X2F90);
    // 0x8014C6A8: jal         0x800058DC
    // 0x8014C6AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x8014C6AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x8014C6B0: b           L_8014C6CC
    // 0x8014C6B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8014C6CC;
    // 0x8014C6B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8014C6B8:
    // 0x8014C6B8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014C6BC: addiu       $a1, $a1, -0x390C
    ctx->r5 = ADD32(ctx->r5, -0X390C);
    // 0x8014C6C0: jal         0x800058DC
    // 0x8014C6C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8014C6C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x8014C6C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8014C6CC:
    // 0x8014C6CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8014C6D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8014C6D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8014C6D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8014C6DC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8014C6E0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8014C6E4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8014C6E8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8014C6EC: jr          $ra
    // 0x8014C6F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8014C6F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014c6f4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014c6f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C6FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014C700: jal         0x801C3D90
    // 0x8014C704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3D90)(rdram, ctx);
        goto after_0;
    // 0x8014C704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014C708: beq         $v0, $zero, L_8014C71C
    if (ctx->r2 == 0) {
        // 0x8014C70C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8014C71C;
    }
    // 0x8014C70C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8014C710: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014C714: jal         0x800058DC
    // 0x8014C718: addiu       $a1, $a1, -0x38D4
    ctx->r5 = ADD32(ctx->r5, -0X38D4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8014C718: addiu       $a1, $a1, -0x38D4
    ctx->r5 = ADD32(ctx->r5, -0X38D4);
    after_1:
L_8014C71C:
    // 0x8014C71C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C724: jr          $ra
    // 0x8014C728: nop

    return;
    // 0x8014C728: nop

;}
RECOMP_FUNC void M7_FUN_8014c72c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C72C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8014C730: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8014C734: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8014C738: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8014C73C: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x8014C740: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8014C744: addiu       $t8, $t8, 0x294C
    ctx->r24 = ADD32(ctx->r24, 0X294C);
    // 0x8014C748: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014C74C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014C750: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014C754: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8014C758: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x8014C75C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014C760: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014C764: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014C768: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8014C76C: lw          $v0, 0x1FA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1FA0);
    // 0x8014C770: beql        $v0, $zero, L_8014C7A0
    if (ctx->r2 == 0) {
        // 0x8014C774: lw          $v0, 0x38($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X38);
            goto L_8014C7A0;
    }
    goto skip_0;
    // 0x8014C774: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x8014C778: jalr        $v0
    // 0x8014C77C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8014C77C: nop

    after_0:
    // 0x8014C780: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x8014C784: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8014C788: addiu       $t3, $t3, 0x294C
    ctx->r11 = ADD32(ctx->r11, 0X294C);
    // 0x8014C78C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014C790: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8014C794: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8014C798: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8014C79C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_8014C7A0:
    // 0x8014C7A0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014C7A4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014C7A8: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x8014C7AC: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x8014C7B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014C7B4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8014C7B8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8014C7BC: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x8014C7C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014C7C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014C7C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014C7CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014C7D0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014C7D4: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014C7D8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8014C7DC: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014C7E0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8014C7E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014C7E8: bgez        $t6, L_8014C7FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014C7EC: cvt.s.d     $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
            goto L_8014C7FC;
    }
    // 0x8014C7EC: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8014C7F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014C7F4: nop

    // 0x8014C7F8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8014C7FC:
    // 0x8014C7FC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8014C800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014C804: nop

    // 0x8014C808: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8014C80C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8014C810: jal         0x801C3D20
    // 0x8014C814: nop

    LOOKUP_FUNC(0x801C3D20)(rdram, ctx);
        goto after_1;
    // 0x8014C814: nop

    after_1:
    // 0x8014C818: beql        $v0, $zero, L_8014C8C4
    if (ctx->r2 == 0) {
        // 0x8014C81C: lw          $t3, 0x2C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X2C);
            goto L_8014C8C4;
    }
    goto skip_1;
    // 0x8014C81C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    skip_1:
    // 0x8014C820: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x8014C824: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014C828: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8014C82C: lh          $t0, 0x8($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X8);
    // 0x8014C830: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014C834: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8014C838: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8014C83C: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8014C840: lw          $t7, 0xE0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XE0);
    // 0x8014C844: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014C848: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8014C84C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8014C850: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014C854: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014C858: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014C85C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8014C860: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8014C864: div.d       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8014C868: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8014C86C: sub.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d - ctx->f4.d;
    // 0x8014C870: c.le.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d <= ctx->f0.d;
    // 0x8014C874: nop

    // 0x8014C878: bc1fl       L_8014C8C4
    if (!c1cs) {
        // 0x8014C87C: lw          $t3, 0x2C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X2C);
            goto L_8014C8C4;
    }
    goto skip_2;
    // 0x8014C87C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x8014C880: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014C884: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014C888: nop

    // 0x8014C88C: add.d       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f2.d + ctx->f8.d;
    // 0x8014C890: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x8014C894: nop

    // 0x8014C898: bc1fl       L_8014C8C4
    if (!c1cs) {
        // 0x8014C89C: lw          $t3, 0x2C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X2C);
            goto L_8014C8C4;
    }
    goto skip_3;
    // 0x8014C89C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    skip_3:
    // 0x8014C8A0: jal         0x80126944
    // 0x8014C8A4: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_2;
    // 0x8014C8A4: nop

    after_2:
    // 0x8014C8A8: bnel        $v0, $zero, L_8014C8C4
    if (ctx->r2 != 0) {
        // 0x8014C8AC: lw          $t3, 0x2C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X2C);
            goto L_8014C8C4;
    }
    goto skip_4;
    // 0x8014C8AC: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    skip_4:
    // 0x8014C8B0: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x8014C8B4: ori         $t2, $t1, 0x800
    ctx->r10 = ctx->r9 | 0X800;
    // 0x8014C8B8: b           L_8014C8D8
    // 0x8014C8BC: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
        goto L_8014C8D8;
    // 0x8014C8BC: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x8014C8C0: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
L_8014C8C4:
    // 0x8014C8C4: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8014C8C8: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8014C8CC: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8014C8D0: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8014C8D4: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
L_8014C8D8:
    // 0x8014C8D8: jal         0x8014F330
    // 0x8014C8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F330)(rdram, ctx);
        goto after_3;
    // 0x8014C8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8014C8E0: beql        $v0, $zero, L_8014CD90
    if (ctx->r2 == 0) {
        // 0x8014C8E4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8014CD90;
    }
    goto skip_5;
    // 0x8014C8E4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x8014C8E8: jal         0x80126944
    // 0x8014C8EC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_4;
    // 0x8014C8EC: nop

    after_4:
    // 0x8014C8F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014C8F4: beql        $v0, $at, L_8014CD90
    if (ctx->r2 == ctx->r1) {
        // 0x8014C8F8: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8014CD90;
    }
    goto skip_6;
    // 0x8014C8F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x8014C8FC: jal         0x801C3B88
    // 0x8014C900: nop

    LOOKUP_FUNC(0x801C3B88)(rdram, ctx);
        goto after_5;
    // 0x8014C900: nop

    after_5:
    // 0x8014C904: jal         0x801C3B7C
    // 0x8014C908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_6;
    // 0x8014C908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8014C90C: lbu         $t5, 0x91($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X91);
    // 0x8014C910: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x8014C914: beql        $t6, $zero, L_8014C930
    if (ctx->r14 == 0) {
        // 0x8014C918: lbu         $t7, 0x435($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X435);
            goto L_8014C930;
    }
    goto skip_7;
    // 0x8014C918: lbu         $t7, 0x435($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X435);
    skip_7:
    // 0x8014C91C: jal         0x801C3B70
    // 0x8014C920: nop

    LOOKUP_FUNC(0x801C3B70)(rdram, ctx);
        goto after_7;
    // 0x8014C920: nop

    after_7:
    // 0x8014C924: b           L_8014CD90
    // 0x8014C928: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8014CD90;
    // 0x8014C928: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8014C92C: lbu         $t7, 0x435($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X435);
L_8014C930:
    // 0x8014C930: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014C934: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014C938: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8014C93C: sb          $t8, 0x435($s1)
    MEM_B(0X435, ctx->r17) = ctx->r24;
    // 0x8014C940: lbu         $t9, 0x9C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9C);
    // 0x8014C944: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8014C948: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8014C94C: sh          $t9, 0x1B0($s1)
    MEM_H(0X1B0, ctx->r17) = ctx->r25;
    // 0x8014C950: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x8014C954: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
    // 0x8014C958: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8014C95C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8014C960: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8014C964: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8014C968: lhu         $v0, 0x2950($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2950);
    // 0x8014C96C: beq         $v0, $zero, L_8014C97C
    if (ctx->r2 == 0) {
        // 0x8014C970: nop
    
            goto L_8014C97C;
    }
    // 0x8014C970: nop

    // 0x8014C974: bne         $v0, $at, L_8014C984
    if (ctx->r2 != ctx->r1) {
        // 0x8014C978: nop
    
            goto L_8014C984;
    }
    // 0x8014C978: nop

L_8014C97C:
    // 0x8014C97C: b           L_8014CD54
    // 0x8014C980: sb          $t2, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r10;
        goto L_8014CD54;
    // 0x8014C980: sb          $t2, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r10;
L_8014C984:
    // 0x8014C984: jal         0x801C3B2C
    // 0x8014C988: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801C3B2C)(rdram, ctx);
        goto after_8;
    // 0x8014C988: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x8014C98C: jal         0x801C3B10
    // 0x8014C990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C3B10)(rdram, ctx);
        goto after_9;
    // 0x8014C990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8014C994: jal         0x801C3BC8
    // 0x8014C998: nop

    LOOKUP_FUNC(0x801C3BC8)(rdram, ctx);
        goto after_10;
    // 0x8014C998: nop

    after_10:
    // 0x8014C99C: jal         0x801C3B5C
    // 0x8014C9A0: nop

    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_11;
    // 0x8014C9A0: nop

    after_11:
    // 0x8014C9A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8014C9A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014C9AC: sb          $v0, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r2;
    // 0x8014C9B0: sb          $t3, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r11;
    // 0x8014C9B4: lw          $t5, 0xE8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XE8);
    // 0x8014C9B8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8014C9BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8014C9C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8014C9C4: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x8014C9C8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8014C9CC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8014C9D0: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8014C9D4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8014C9D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8014C9DC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8014C9E0: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8014C9E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014C9E8: addiu       $a0, $a0, 0x2C8
    ctx->r4 = ADD32(ctx->r4, 0X2C8);
    // 0x8014C9EC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8014C9F0: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8014C9F4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8014C9F8: addiu       $a1, $zero, 0x4EC
    ctx->r5 = ADD32(0, 0X4EC);
    // 0x8014C9FC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8014CA00: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8014CA04: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8014CA08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014CA0C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8014CA10: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8014CA14: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8014CA18: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8014CA1C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8014CA20: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8014CA24: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8014CA28: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8014CA2C: jal         0x8011AAF4
    // 0x8014CA30: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_12;
    // 0x8014CA30: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8014CA34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014CA38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014CA3C: sw          $v1, -0xE80($at)
    MEM_W(-0XE80, ctx->r1) = ctx->r3;
    // 0x8014CA40: lbu         $t8, 0x92($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X92);
    // 0x8014CA44: bnel        $v1, $t8, L_8014CA6C
    if (ctx->r3 != ctx->r24) {
        // 0x8014CA48: lw          $t6, 0x24($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X24);
            goto L_8014CA6C;
    }
    goto skip_8;
    // 0x8014CA48: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    skip_8:
    // 0x8014CA4C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014CA50: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014CA54: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x8014CA58: addiu       $t4, $t1, 0x1000
    ctx->r12 = ADD32(ctx->r9, 0X1000);
    // 0x8014CA5C: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8014CA60: b           L_8014CA78
    // 0x8014CA64: sh          $t5, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r13;
        goto L_8014CA78;
    // 0x8014CA64: sh          $t5, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r13;
    // 0x8014CA68: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
L_8014CA6C:
    // 0x8014CA6C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014CA70: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x8014CA74: sh          $t8, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r24;
L_8014CA78:
    // 0x8014CA78: jal         0x8001EAD0
    // 0x8014CA7C: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_13;
    // 0x8014CA7C: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    after_13:
    // 0x8014CA80: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x8014CA84: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8014CA88: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014CA8C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014CA90: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8014CA94: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8014CA98: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8014CA9C: lhu         $t1, 0x2958($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X2958);
    // 0x8014CAA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014CAA4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8014CAA8: bgez        $t1, L_8014CABC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8014CAAC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8014CABC;
    }
    // 0x8014CAAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014CAB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014CAB4: nop

    // 0x8014CAB8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8014CABC:
    // 0x8014CABC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014CAC0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8014CAC4: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8014CAC8: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x8014CACC: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x8014CAD0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014CAD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014CAD8: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8014CADC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014CAE0: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    // 0x8014CAE4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014CAE8: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8014CAEC: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8014CAF0: mul.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8014CAF4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8014CAF8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8014CAFC: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014CB00: jal         0x8001EB64
    // 0x8014CB04: swc1        $f8, 0x198($s1)
    MEM_W(0X198, ctx->r17) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_14;
    // 0x8014CB04: swc1        $f8, 0x198($s1)
    MEM_W(0X198, ctx->r17) = ctx->f8.u32l;
    after_14:
    // 0x8014CB08: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014CB0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8014CB10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014CB14: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8014CB18: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8014CB1C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8014CB20: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8014CB24: lhu         $t6, 0x2958($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2958);
    // 0x8014CB28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014CB2C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8014CB30: bgez        $t6, L_8014CB44
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014CB34: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014CB44;
    }
    // 0x8014CB34: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014CB38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014CB3C: nop

    // 0x8014CB40: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8014CB44:
    // 0x8014CB44: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014CB48: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014CB4C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8014CB50: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x8014CB54: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8014CB58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014CB5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014CB60: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8014CB64: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014CB68: lw          $t1, 0xE0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XE0);
    // 0x8014CB6C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014CB70: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x8014CB74: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8014CB78: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x8014CB7C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014CB80: lwc1        $f4, 0x198($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X198);
    // 0x8014CB84: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x8014CB88: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8014CB8C: swc1        $f16, 0x1A0($s1)
    MEM_W(0X1A0, ctx->r17) = ctx->f16.u32l;
    // 0x8014CB90: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014CB94: lwc1        $f8, 0x1A0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1A0);
    // 0x8014CB98: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014CB9C: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8014CBA0: swc1        $f10, 0x19C($s1)
    MEM_W(0X19C, ctx->r17) = ctx->f10.u32l;
    // 0x8014CBA4: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x8014CBA8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014CBAC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014CBB0: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8014CBB4: jal         0x8001EF38
    // 0x8014CBB8: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_15;
    // 0x8014CBB8: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_15:
    // 0x8014CBBC: lw          $t2, 0xE0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XE0);
    // 0x8014CBC0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8014CBC4: sh          $v0, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r2;
    // 0x8014CBC8: jal         0x8001EAD0
    // 0x8014CBCC: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_16;
    // 0x8014CBCC: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    after_16:
    // 0x8014CBD0: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014CBD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8014CBD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014CBDC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8014CBE0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8014CBE4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8014CBE8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8014CBEC: lhu         $t6, 0x2958($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2958);
    // 0x8014CBF0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014CBF4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8014CBF8: bgez        $t6, L_8014CC0C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014CBFC: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8014CC0C;
    }
    // 0x8014CBFC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014CC00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014CC04: nop

    // 0x8014CC08: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8014CC0C:
    // 0x8014CC0C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014CC10: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014CC14: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8014CC18: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8014CC1C: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8014CC20: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8014CC24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014CC28: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8014CC2C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014CC30: ldc1        $f10, 0x670($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X670);
    // 0x8014CC34: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8014CC38: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014CC3C: add.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d + ctx->f16.d;
    // 0x8014CC40: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8014CC44: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014CC48: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    // 0x8014CC4C: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x8014CC50: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014CC54: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8014CC58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014CC5C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8014CC60: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014CC64: div.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8014CC68: add.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d + ctx->f8.d;
    // 0x8014CC6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014CC70: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014CC74: lui         $at, 0x4031
    ctx->r1 = S32(0X4031 << 16);
    // 0x8014CC78: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8014CC7C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014CC80: swc1        $f4, 0x328($s1)
    MEM_W(0X328, ctx->r17) = ctx->f4.u32l;
    // 0x8014CC84: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x8014CC88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014CC8C: lh          $t0, 0x8($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X8);
    // 0x8014CC90: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8014CC94: nop

    // 0x8014CC98: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014CC9C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8014CCA0: div.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8014CCA4: add.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f16.d + ctx->f4.d;
    // 0x8014CCA8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8014CCAC: jal         0x8001EB64
    // 0x8014CCB0: swc1        $f18, 0x32C($s1)
    MEM_W(0X32C, ctx->r17) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_17;
    // 0x8014CCB0: swc1        $f18, 0x32C($s1)
    MEM_W(0X32C, ctx->r17) = ctx->f18.u32l;
    after_17:
    // 0x8014CCB4: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x8014CCB8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8014CCBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014CCC0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014CCC4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8014CCC8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8014CCCC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8014CCD0: lhu         $t3, 0x2958($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X2958);
    // 0x8014CCD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014CCD8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8014CCDC: bgez        $t3, L_8014CCF0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8014CCE0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014CCF0;
    }
    // 0x8014CCE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014CCE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014CCE8: nop

    // 0x8014CCEC: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8014CCF0:
    // 0x8014CCF0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014CCF4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8014CCF8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014CCFC: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8014CD00: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8014CD04: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014CD08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014CD0C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8014CD10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014CD14: ldc1        $f8, 0x678($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X678);
    // 0x8014CD18: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x8014CD1C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014CD20: add.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f18.d + ctx->f6.d;
    // 0x8014CD24: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8014CD28: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014CD2C: add.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f16.d + ctx->f8.d;
    // 0x8014CD30: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014CD34: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8014CD38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014CD3C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014CD40: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8014CD44: div.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x8014CD48: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x8014CD4C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8014CD50: swc1        $f16, 0x330($s1)
    MEM_W(0X330, ctx->r17) = ctx->f16.u32l;
L_8014CD54:
    // 0x8014CD54: lbu         $t6, 0x91($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X91);
    // 0x8014CD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CD5C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014CD60: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8014CD64: beq         $t7, $zero, L_8014CD84
    if (ctx->r15 == 0) {
        // 0x8014CD68: nop
    
            goto L_8014CD84;
    }
    // 0x8014CD68: nop

    // 0x8014CD6C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014CD70: addiu       $a1, $a1, 0x6EC
    ctx->r5 = ADD32(ctx->r5, 0X6EC);
    // 0x8014CD74: jal         0x800058DC
    // 0x8014CD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x8014CD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8014CD7C: b           L_8014CD90
    // 0x8014CD80: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8014CD90;
    // 0x8014CD80: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8014CD84:
    // 0x8014CD84: jal         0x800058DC
    // 0x8014CD88: addiu       $a1, $a1, -0x3260
    ctx->r5 = ADD32(ctx->r5, -0X3260);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_19;
    // 0x8014CD88: addiu       $a1, $a1, -0x3260
    ctx->r5 = ADD32(ctx->r5, -0X3260);
    after_19:
    // 0x8014CD8C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8014CD90:
    // 0x8014CD90: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8014CD94: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8014CD98: jr          $ra
    // 0x8014CD9C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8014CD9C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014cda0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014cda0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CDA0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014CDA4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014CDA8: lbu         $t6, 0x182($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X182);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014cdac(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014cdac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CDAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014CDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014CDB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014CDB8: bne         $t6, $zero, L_8014CE44
    if (ctx->r14 != 0) {
        // 0x8014CDBC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8014CE44;
    }
    // 0x8014CDBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014CDC0: lbu         $t7, 0x187($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X187);
    // 0x8014CDC4: bnel        $t7, $zero, L_8014CE48
    if (ctx->r15 != 0) {
        // 0x8014CDC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014CE48;
    }
    goto skip_0;
    // 0x8014CDC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014CDCC: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x8014CDD0: beql        $t8, $zero, L_8014CE04
    if (ctx->r24 == 0) {
        // 0x8014CDD4: lbu         $t2, 0x92($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X92);
            goto L_8014CE04;
    }
    goto skip_1;
    // 0x8014CDD4: lbu         $t2, 0x92($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X92);
    skip_1:
    // 0x8014CDD8: lbu         $t9, 0x92($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X92);
    // 0x8014CDDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014CDE0: bnel        $t9, $at, L_8014CDF8
    if (ctx->r25 != ctx->r1) {
        // 0x8014CDE4: lhu         $t1, 0xA2($a2)
        ctx->r9 = MEM_HU(ctx->r6, 0XA2);
            goto L_8014CDF8;
    }
    goto skip_2;
    // 0x8014CDE4: lhu         $t1, 0xA2($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XA2);
    skip_2:
    // 0x8014CDE8: lhu         $t0, 0xA0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XA0);
    // 0x8014CDEC: b           L_8014CE34
    // 0x8014CDF0: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
        goto L_8014CE34;
    // 0x8014CDF0: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
    // 0x8014CDF4: lhu         $t1, 0xA2($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XA2);
L_8014CDF8:
    // 0x8014CDF8: b           L_8014CE34
    // 0x8014CDFC: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
        goto L_8014CE34;
    // 0x8014CDFC: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x8014CE00: lbu         $t2, 0x92($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X92);
L_8014CE04:
    // 0x8014CE04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014CE08: bnel        $t2, $at, L_8014CE28
    if (ctx->r10 != ctx->r1) {
        // 0x8014CE0C: lhu         $a0, 0xA2($a2)
        ctx->r4 = MEM_HU(ctx->r6, 0XA2);
            goto L_8014CE28;
    }
    goto skip_3;
    // 0x8014CE0C: lhu         $a0, 0xA2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XA2);
    skip_3:
    // 0x8014CE10: lhu         $a0, 0xA0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XA0);
    // 0x8014CE14: jal         0x80126820
    // 0x8014CE18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80126820)(rdram, ctx);
        goto after_0;
    // 0x8014CE18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014CE1C: b           L_8014CE34
    // 0x8014CE20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_8014CE34;
    // 0x8014CE20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014CE24: lhu         $a0, 0xA2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XA2);
L_8014CE28:
    // 0x8014CE28: jal         0x80126820
    // 0x8014CE2C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80126820)(rdram, ctx);
        goto after_1;
    // 0x8014CE2C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014CE30: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8014CE34:
    // 0x8014CE34: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014CE38: addiu       $a1, $a1, -0x31AC
    ctx->r5 = ADD32(ctx->r5, -0X31AC);
    // 0x8014CE3C: jal         0x800058DC
    // 0x8014CE40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8014CE40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_8014CE44:
    // 0x8014CE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014CE48:
    // 0x8014CE48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014CE4C: jr          $ra
    // 0x8014CE50: nop

    return;
    // 0x8014CE50: nop

;}
RECOMP_FUNC void M7_FUN_8014ce54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CE54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014CE58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014CE5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014CE60: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8014CE64: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x8014CE68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8014CE6C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014CE70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014CE74: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014CE78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014CE7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8014CE80: lhu         $t8, 0x2950($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2950);
    // 0x8014CE84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014CE88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8014CE8C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8014CE90: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8014CE94: lw          $v0, 0x2104($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2104);
    // 0x8014CE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CE9C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8014CEA0: bne         $v0, $zero, L_8014CEB0
    if (ctx->r2 != 0) {
        // 0x8014CEA4: nop
    
            goto L_8014CEB0;
    }
    // 0x8014CEA4: nop

    // 0x8014CEA8: b           L_8014CEC4
    // 0x8014CEAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8014CEC4;
    // 0x8014CEAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8014CEB0:
    // 0x8014CEB0: jalr        $v0
    // 0x8014CEB4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8014CEB4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014CEB8: bne         $v0, $zero, L_8014CEC4
    if (ctx->r2 != 0) {
        // 0x8014CEBC: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8014CEC4;
    }
    // 0x8014CEBC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014CEC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8014CEC4:
    // 0x8014CEC4: beql        $v1, $zero, L_8014D060
    if (ctx->r3 == 0) {
        // 0x8014CEC8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8014D060;
    }
    goto skip_0;
    // 0x8014CEC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8014CECC: jal         0x80126950
    // 0x8014CED0: nop

    LOOKUP_FUNC(0x80126950)(rdram, ctx);
        goto after_1;
    // 0x8014CED0: nop

    after_1:
    // 0x8014CED4: bnel        $v0, $zero, L_8014D060
    if (ctx->r2 != 0) {
        // 0x8014CED8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8014D060;
    }
    goto skip_1;
    // 0x8014CED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8014CEDC: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x8014CEE0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8014CEE4: addiu       $t2, $t2, 0x294C
    ctx->r10 = ADD32(ctx->r10, 0X294C);
    // 0x8014CEE8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8014CEEC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8014CEF0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8014CEF4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8014CEF8: lhu         $v1, 0x12($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X12);
    // 0x8014CEFC: beql        $v1, $zero, L_8014CF90
    if (ctx->r3 == 0) {
        // 0x8014CF00: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8014CF90;
    }
    goto skip_2;
    // 0x8014CF00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x8014CF04: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8014CF08: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014CF0C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014CF10: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8014CF14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014CF18: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x8014CF1C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8014CF20: lh          $t4, 0x8($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X8);
    // 0x8014CF24: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8014CF28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014CF2C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8014CF30: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8014CF34: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014CF38: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014CF3C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014CF40: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014CF44: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8014CF48: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014CF4C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8014CF50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014CF54: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014CF58: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8014CF5C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8014CF60: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014CF64: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8014CF68: jal         0x801FC830
    // 0x8014CF6C: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_2;
    // 0x8014CF6C: nop

    after_2:
    // 0x8014CF70: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8014CF74: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8014CF78: addiu       $t8, $t8, 0x294C
    ctx->r24 = ADD32(ctx->r24, 0X294C);
    // 0x8014CF7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014CF80: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014CF84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014CF88: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8014CF8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8014CF90:
    // 0x8014CF90: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8014CF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CF98: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    // 0x8014CF9C: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x8014CFA0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014CFA4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8014CFA8: lw          $v1, 0x2268($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2268);
    // 0x8014CFAC: beql        $v1, $zero, L_8014CFC0
    if (ctx->r3 == 0) {
        // 0x8014CFB0: lbu         $t1, 0xA5($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0XA5);
            goto L_8014CFC0;
    }
    goto skip_3;
    // 0x8014CFB0: lbu         $t1, 0xA5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XA5);
    skip_3:
    // 0x8014CFB4: jalr        $v1
    // 0x8014CFB8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x8014CFB8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x8014CFBC: lbu         $t1, 0xA5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XA5);
L_8014CFC0:
    // 0x8014CFC0: beql        $t1, $zero, L_8014D044
    if (ctx->r9 == 0) {
        // 0x8014CFC4: lw          $t7, 0x74($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X74);
            goto L_8014D044;
    }
    goto skip_4;
    // 0x8014CFC4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    skip_4:
    // 0x8014CFC8: lhu         $t2, 0x9E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X9E);
    // 0x8014CFCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014CFD0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8014CFD4: sh          $t2, -0x440C($at)
    MEM_H(-0X440C, ctx->r1) = ctx->r10;
    // 0x8014CFD8: lbu         $v1, 0x91($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X91);
    // 0x8014CFDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8014CFE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014CFE4: andi        $t3, $v1, 0x4
    ctx->r11 = ctx->r3 & 0X4;
    // 0x8014CFE8: beq         $t3, $zero, L_8014CFF4
    if (ctx->r11 == 0) {
        // 0x8014CFEC: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_8014CFF4;
    }
    // 0x8014CFEC: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x8014CFF0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_8014CFF4:
    // 0x8014CFF4: beq         $t4, $zero, L_8014D014
    if (ctx->r12 == 0) {
        // 0x8014CFF8: nop
    
            goto L_8014D014;
    }
    // 0x8014CFF8: nop

    // 0x8014CFFC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8014D000: jal         0x80020718
    // 0x8014D004: sb          $a2, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_4;
    // 0x8014D004: sb          $a2, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r6;
    after_4:
    // 0x8014D008: lbu         $a2, 0x2A($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2A);
    // 0x8014D00C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8014D010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014D014:
    // 0x8014D014: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014D018: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x8014D01C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8014D020: jal         0x8012FE50
    // 0x8014D024: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_5;
    // 0x8014D024: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x8014D028: lbu         $t5, 0xA5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA5);
    // 0x8014D02C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014D030: sb          $t5, -0x406A($at)
    MEM_B(-0X406A, ctx->r1) = ctx->r13;
    // 0x8014D034: lbu         $t6, 0x92($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X92);
    // 0x8014D038: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014D03C: sb          $t6, -0x4069($at)
    MEM_B(-0X4069, ctx->r1) = ctx->r14;
    // 0x8014D040: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
L_8014D044:
    // 0x8014D044: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014D048: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8014D04C: addiu       $a1, $a1, -0x2F90
    ctx->r5 = ADD32(ctx->r5, -0X2F90);
    // 0x8014D050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014D054: jal         0x800058DC
    // 0x8014D058: sw          $t7, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8014D058: sw          $t7, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r15;
    after_6:
    // 0x8014D05C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8014D060:
    // 0x8014D060: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014D064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014D068: jr          $ra
    // 0x8014D06C: nop

    return;
    // 0x8014D06C: nop

;}
RECOMP_FUNC void M7_FUN_8014d070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014D07C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8014D080: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8014D084: lbu         $t5, 0x90($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X90);
    // 0x8014D088: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8014D08C: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x8014D090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014D094: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8014D098: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8014D09C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8014D0A0: swc1        $f4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f4.u32l;
    // 0x8014D0A4: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8014D0A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8014D0AC: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8014D0B0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8014D0B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014D0B8: swc1        $f6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f6.u32l;
    // 0x8014D0BC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x8014D0C0: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8014D0C4: swc1        $f8, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f8.u32l;
    // 0x8014D0C8: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x8014D0CC: lh          $t0, 0x10($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10);
    // 0x8014D0D0: sh          $t0, 0x84($a0)
    MEM_H(0X84, ctx->r4) = ctx->r8;
    // 0x8014D0D4: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x8014D0D8: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x8014D0DC: sh          $t2, 0x86($a0)
    MEM_H(0X86, ctx->r4) = ctx->r10;
    // 0x8014D0E0: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x8014D0E4: lh          $t4, 0x14($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X14);
    // 0x8014D0E8: sh          $t4, 0x88($a0)
    MEM_H(0X88, ctx->r4) = ctx->r12;
    // 0x8014D0EC: lhu         $t7, 0x2950($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2950);
    // 0x8014D0F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8014D0F4: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8014D0F8: lw          $v1, 0x23CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X23CC);
    // 0x8014D0FC: beql        $v1, $zero, L_8014D180
    if (ctx->r3 == 0) {
        // 0x8014D100: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D180;
    }
    goto skip_0;
    // 0x8014D100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8014D104: jalr        $v1
    // 0x8014D108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8014D108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8014D10C: bnel        $v0, $zero, L_8014D180
    if (ctx->r2 != 0) {
        // 0x8014D110: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D180;
    }
    goto skip_1;
    // 0x8014D110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8014D114: lw          $t9, 0x98($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X98);
    // 0x8014D118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8014D11C: jal         0x801C3B7C
    // 0x8014D120: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_1;
    // 0x8014D120: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    after_1:
    // 0x8014D124: jal         0x8014BC18
    // 0x8014D128: nop

    LOOKUP_FUNC(0x8014BC18)(rdram, ctx);
        goto after_2;
    // 0x8014D128: nop

    after_2:
    // 0x8014D12C: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D130: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8014D134: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014D138: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8014D13C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8014D140: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8014D144: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8014D148: lhu         $t2, 0x2950($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2950);
    // 0x8014D14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014D150: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8014D154: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8014D158: lw          $v0, 0x2530($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2530);
    // 0x8014D15C: beq         $v0, $zero, L_8014D16C
    if (ctx->r2 == 0) {
        // 0x8014D160: nop
    
            goto L_8014D16C;
    }
    // 0x8014D160: nop

    // 0x8014D164: jalr        $v0
    // 0x8014D168: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x8014D168: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
L_8014D16C:
    // 0x8014D16C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014D170: addiu       $a1, $a1, -0x2E70
    ctx->r5 = ADD32(ctx->r5, -0X2E70);
    // 0x8014D174: jal         0x800058DC
    // 0x8014D178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8014D178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8014D17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014D180:
    // 0x8014D180: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014D184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D188: jr          $ra
    // 0x8014D18C: nop

    return;
    // 0x8014D18C: nop

;}
RECOMP_FUNC void M7_FUN_8014d190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D198: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014D19C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x8014D1A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014D1A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014D1A8: bnel        $t6, $at, L_8014D1BC
    if (ctx->r14 != ctx->r1) {
        // 0x8014D1AC: lhu         $v0, 0xA2($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0XA2);
            goto L_8014D1BC;
    }
    goto skip_0;
    // 0x8014D1AC: lhu         $v0, 0xA2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XA2);
    skip_0:
    // 0x8014D1B0: b           L_8014D1BC
    // 0x8014D1B4: lhu         $v0, 0xA0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA0);
        goto L_8014D1BC;
    // 0x8014D1B4: lhu         $v0, 0xA0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA0);
    // 0x8014D1B8: lhu         $v0, 0xA2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XA2);
L_8014D1BC:
    // 0x8014D1BC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8014D1C0: jal         0x80126880
    // 0x8014D1C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80126880)(rdram, ctx);
        goto after_0;
    // 0x8014D1C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014D1C8: beq         $v0, $zero, L_8014D1F4
    if (ctx->r2 == 0) {
        // 0x8014D1CC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8014D1F4;
    }
    // 0x8014D1CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014D1D0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014D1D4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014D1D8: lbu         $t7, 0x435($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X435);
    // 0x8014D1DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014D1E0: addiu       $a1, $a1, -0x38D4
    ctx->r5 = ADD32(ctx->r5, -0X38D4);
    // 0x8014D1E4: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8014D1E8: sb          $t8, 0x435($v0)
    MEM_B(0X435, ctx->r2) = ctx->r24;
    // 0x8014D1EC: jal         0x800058DC
    // 0x8014D1F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8014D1F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_8014D1F4:
    // 0x8014D1F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D1F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D1FC: jr          $ra
    // 0x8014D200: nop

    return;
    // 0x8014D200: nop

;}
RECOMP_FUNC void M7_FUN_8014d204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D20C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014D210: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8014D214: lbu         $t8, 0x9C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9C);
    // 0x8014D218: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8014D21C: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8014D220: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8014D224: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014D228: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8014D22C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8014D230: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8014D234: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8014D238: sw          $zero, -0x4054($at)
    MEM_W(-0X4054, ctx->r1) = 0;
    // 0x8014D23C: jal         0x800058DC
    // 0x8014D240: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8014D240: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x8014D244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D24C: jr          $ra
    // 0x8014D250: nop

    return;
    // 0x8014D250: nop

;}
RECOMP_FUNC void M7_FUN_8014d254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D25C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014D260: lwc1        $f0, 0x94($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X94);
    // 0x8014D264: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014D268: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014D26C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8014D270: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8014D274: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8014D278: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8014D27C: nop

    // 0x8014D280: bne         $v0, $zero, L_8014D298
    if (ctx->r2 != 0) {
        // 0x8014D284: swc1        $f8, 0x94($a0)
        MEM_W(0X94, ctx->r4) = ctx->f8.u32l;
            goto L_8014D298;
    }
    // 0x8014D284: swc1        $f8, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f8.u32l;
    // 0x8014D288: jal         0x8014F400
    // 0x8014D28C: nop

    LOOKUP_FUNC(0x8014F400)(rdram, ctx);
        goto after_0;
    // 0x8014D28C: nop

    after_0:
    // 0x8014D290: b           L_8014D2C0
    // 0x8014D294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D2C0;
    // 0x8014D294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D298:
    // 0x8014D298: lw          $t7, -0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XE80);
    // 0x8014D29C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014D2A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014D2A4: bne         $t7, $zero, L_8014D2C0
    if (ctx->r15 != 0) {
        // 0x8014D2A8: nop
    
            goto L_8014D2C0;
    }
    // 0x8014D2A8: nop

    // 0x8014D2AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014D2B0: sb          $t8, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r24;
    // 0x8014D2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D2B8: b           L_8014D2C0
    // 0x8014D2BC: swc1        $f10, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
        goto L_8014D2C0;
    // 0x8014D2BC: swc1        $f10, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
L_8014D2C0:
    // 0x8014D2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D2C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D2C8: jr          $ra
    // 0x8014D2CC: nop

    return;
    // 0x8014D2CC: nop

;}
RECOMP_FUNC void M7_FUN_8014d2d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D2D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8014D2D4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8014D2D8: jr          $ra
    // 0x8014D2DC: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
    return;
    // 0x8014D2DC: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014d2e0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014d2e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D2E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D2E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D2E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014D2EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8014D2F0: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014D2F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014D2F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014D2FC: beq         $v0, $at, L_8014D31C
    if (ctx->r2 == ctx->r1) {
        // 0x8014D300: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014D31C;
    }
    // 0x8014D300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014D304: beq         $v0, $at, L_8014D454
    if (ctx->r2 == ctx->r1) {
        // 0x8014D308: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8014D454;
    }
    // 0x8014D308: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014D30C: beql        $v0, $at, L_8014D538
    if (ctx->r2 == ctx->r1) {
        // 0x8014D310: lw          $t3, 0x24($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X24);
            goto L_8014D538;
    }
    goto skip_0;
    // 0x8014D310: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x8014D314: b           L_8014D6A8
    // 0x8014D318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D6A8;
    // 0x8014D318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D31C:
    // 0x8014D31C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8014D320: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014D324: jal         0x8001EB64
    // 0x8014D328: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8014D328: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x8014D32C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D330: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8014D334: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014D338: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D33C: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x8014D340: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8014D344: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014D348: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8014D34C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014D350: mflo        $t0
    ctx->r8 = lo;
    // 0x8014D354: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8014D358: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8014D35C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014D360: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014D364: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8014D368: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x8014D36C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8014D370: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8014D374: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8014D378: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014D37C: jal         0x8001EAD0
    // 0x8014D380: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8014D380: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x8014D384: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D388: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8014D38C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014D390: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D394: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x8014D398: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x8014D39C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014D3A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014D3A4: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8014D3A8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014D3AC: mflo        $t6
    ctx->r14 = lo;
    // 0x8014D3B0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8014D3B4: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8014D3B8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014D3BC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014D3C0: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8014D3C4: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x8014D3C8: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8014D3CC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8014D3D0: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D3D4: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014D3D8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014D3DC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D3E0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8014D3E4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014D3E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8014D3EC: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x8014D3F0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014D3F4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D3F8: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8014D3FC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8014D400: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8014D404: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x8014D408: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8014D40C: bgez        $t0, L_8014D420
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8014D410: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8014D420;
    }
    // 0x8014D410: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014D414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014D418: nop

    // 0x8014D41C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8014D420:
    // 0x8014D420: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x8014D424: nop

    // 0x8014D428: bc1fl       L_8014D6A8
    if (!c1cs) {
        // 0x8014D42C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014D6A8;
    }
    goto skip_1;
    // 0x8014D42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014D430: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x8014D434: jal         0x8014F358
    // 0x8014D438: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_2;
    // 0x8014D438: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    after_2:
    // 0x8014D43C: beq         $v0, $zero, L_8014D6A4
    if (ctx->r2 == 0) {
        // 0x8014D440: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8014D6A4;
    }
    // 0x8014D440: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8014D444: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014D448: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x8014D44C: b           L_8014D6A4
    // 0x8014D450: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_8014D6A4;
    // 0x8014D450: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_8014D454:
    // 0x8014D454: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8014D458: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014D45C: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014D460: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014D464: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014D468: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x8014D46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D470: add.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8014D474: bc1f        L_8014D480
    if (!c1cs) {
        // 0x8014D478: nop
    
            goto L_8014D480;
    }
    // 0x8014D478: nop

    // 0x8014D47C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D480:
    // 0x8014D480: beq         $v0, $zero, L_8014D490
    if (ctx->r2 == 0) {
        // 0x8014D484: swc1        $f8, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
            goto L_8014D490;
    }
    // 0x8014D484: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x8014D488: jal         0x8014F940
    // 0x8014D48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_3;
    // 0x8014D48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8014D490:
    // 0x8014D490: jal         0x801C3044
    // 0x8014D494: nop

    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_4;
    // 0x8014D494: nop

    after_4:
    // 0x8014D498: bne         $v0, $zero, L_8014D6A4
    if (ctx->r2 != 0) {
        // 0x8014D49C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8014D6A4;
    }
    // 0x8014D49C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014D4A0: jal         0x801C2F0C
    // 0x8014D4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_5;
    // 0x8014D4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8014D4A8: lbu         $t2, 0x91($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X91);
    // 0x8014D4AC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8014D4B0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014D4B4: beql        $t3, $zero, L_8014D4D0
    if (ctx->r11 == 0) {
        // 0x8014D4B8: lw          $t5, 0x38($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X38);
            goto L_8014D4D0;
    }
    goto skip_2;
    // 0x8014D4B8: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x8014D4BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014D4C0: sb          $t4, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r12;
    // 0x8014D4C4: b           L_8014D6A4
    // 0x8014D4C8: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
        goto L_8014D6A4;
    // 0x8014D4C8: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x8014D4CC: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
L_8014D4D0:
    // 0x8014D4D0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014D4D4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014D4D8: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8014D4DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014D4E0: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8014D4E4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8014D4E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D4EC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014D4F0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014D4F4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014D4F8: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8014D4FC: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8014D500: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    // 0x8014D504: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x8014D508: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x8014D50C: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x8014D510: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014D514: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8014D518: nop

    // 0x8014D51C: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D520: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8014D524: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8014D528: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8014D52C: b           L_8014D6A8
    // 0x8014D530: swc1        $f16, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f16.u32l;
        goto L_8014D6A8;
    // 0x8014D530: swc1        $f16, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f16.u32l;
    // 0x8014D534: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
L_8014D538:
    // 0x8014D538: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014D53C: jal         0x8001EB64
    // 0x8014D540: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x8014D540: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_6:
    // 0x8014D544: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D548: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014D54C: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014D550: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014D554: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014D558: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014D55C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8014D560: lwc1        $f4, 0x2954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014D564: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014D568: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8014D56C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D570: mul.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8014D574: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014D578: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014D57C: sub.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d - ctx->f6.d;
    // 0x8014D580: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014D584: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8014D588: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8014D58C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014D590: jal         0x8001EAD0
    // 0x8014D594: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x8014D594: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_7:
    // 0x8014D598: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D59C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8014D5A0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014D5A4: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D5A8: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x8014D5AC: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8014D5B0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8014D5B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014D5B8: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x8014D5BC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014D5C0: mflo        $t2
    ctx->r10 = lo;
    // 0x8014D5C4: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8014D5C8: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8014D5CC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D5D0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014D5D4: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8014D5D8: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8014D5DC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8014D5E0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8014D5E4: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D5E8: lwc1        $f16, 0x94($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014D5EC: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D5F0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8014D5F4: mflo        $t5
    ctx->r13 = lo;
    // 0x8014D5F8: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x8014D5FC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014D600: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014D604: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8014D608: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x8014D60C: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8014D610: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x8014D614: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8014D618: bgez        $t6, L_8014D62C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014D61C: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8014D62C;
    }
    // 0x8014D61C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014D620: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014D624: nop

    // 0x8014D628: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8014D62C:
    // 0x8014D62C: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8014D630: nop

    // 0x8014D634: bc1fl       L_8014D6A8
    if (!c1cs) {
        // 0x8014D638: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014D6A8;
    }
    goto skip_3;
    // 0x8014D638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014D63C: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8014D640: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014D644: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014D648: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8014D64C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014D650: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014D654: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8014D658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D65C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014D660: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D664: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014D668: div.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8014D66C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8014D670: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x8014D674: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8014D678: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8014D67C: lh          $t2, 0xA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XA);
    // 0x8014D680: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014D684: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8014D688: nop

    // 0x8014D68C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014D690: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D694: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8014D698: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8014D69C: b           L_8014D6A8
    // 0x8014D6A0: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
        goto L_8014D6A8;
    // 0x8014D6A0: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
L_8014D6A4:
    // 0x8014D6A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D6A8:
    // 0x8014D6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D6AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014D6B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D6B4: jr          $ra
    // 0x8014D6B8: nop

    return;
    // 0x8014D6B8: nop

;}
RECOMP_FUNC void M7_FUN_8014d6bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D6C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014D6C8: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014D6CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014D6D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014D6D4: beq         $v0, $at, L_8014D6F4
    if (ctx->r2 == ctx->r1) {
        // 0x8014D6D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014D6F4;
    }
    // 0x8014D6D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014D6DC: beq         $v0, $at, L_8014D7C4
    if (ctx->r2 == ctx->r1) {
        // 0x8014D6E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8014D7C4;
    }
    // 0x8014D6E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014D6E4: beql        $v0, $at, L_8014D890
    if (ctx->r2 == ctx->r1) {
        // 0x8014D6E8: lbu         $t2, 0x90($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X90);
            goto L_8014D890;
    }
    goto skip_0;
    // 0x8014D6E8: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
    skip_0:
    // 0x8014D6EC: b           L_8014D968
    // 0x8014D6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D968;
    // 0x8014D6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D6F4:
    // 0x8014D6F4: lbu         $t7, 0x90($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X90);
    // 0x8014D6F8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8014D6FC: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x8014D700: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D704: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014D708: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8014D70C: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x8014D710: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014D714: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014D718: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D71C: mflo        $t8
    ctx->r24 = lo;
    // 0x8014D720: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8014D724: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8014D728: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014D72C: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8014D730: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8014D734: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8014D738: lbu         $t0, 0x90($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X90);
    // 0x8014D73C: lwc1        $f4, 0x94($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014D740: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014D744: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D748: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D74C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014D750: mflo        $t1
    ctx->r9 = lo;
    // 0x8014D754: addu        $v1, $a0, $t1
    ctx->r3 = ADD32(ctx->r4, ctx->r9);
    // 0x8014D758: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014D75C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014D760: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8014D764: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x8014D768: swc1        $f0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f0.u32l;
    // 0x8014D76C: lhu         $t2, 0x6($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X6);
    // 0x8014D770: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8014D774: bgez        $t2, L_8014D788
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014D778: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8014D788;
    }
    // 0x8014D778: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014D77C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014D780: nop

    // 0x8014D784: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8014D788:
    // 0x8014D788: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8014D78C: nop

    // 0x8014D790: bc1fl       L_8014D968
    if (!c1cs) {
        // 0x8014D794: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014D968;
    }
    goto skip_1;
    // 0x8014D794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014D798: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x8014D79C: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x8014D7A0: jal         0x8014F358
    // 0x8014D7A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_0;
    // 0x8014D7A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014D7A8: beq         $v0, $zero, L_8014D964
    if (ctx->r2 == 0) {
        // 0x8014D7AC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8014D964;
    }
    // 0x8014D7AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014D7B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014D7B4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8014D7B8: sb          $t3, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r11;
    // 0x8014D7BC: b           L_8014D964
    // 0x8014D7C0: swc1        $f8, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
        goto L_8014D964;
    // 0x8014D7C0: swc1        $f8, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
L_8014D7C4:
    // 0x8014D7C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8014D7C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014D7CC: lwc1        $f0, 0x94($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014D7D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014D7D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014D7D8: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x8014D7DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D7E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014D7E4: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8014D7E8: bc1f        L_8014D7F4
    if (!c1cs) {
        // 0x8014D7EC: nop
    
            goto L_8014D7F4;
    }
    // 0x8014D7EC: nop

    // 0x8014D7F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D7F4:
    // 0x8014D7F4: beq         $v0, $zero, L_8014D808
    if (ctx->r2 == 0) {
        // 0x8014D7F8: swc1        $f18, 0x94($a2)
        MEM_W(0X94, ctx->r6) = ctx->f18.u32l;
            goto L_8014D808;
    }
    // 0x8014D7F8: swc1        $f18, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f18.u32l;
    // 0x8014D7FC: jal         0x8014F940
    // 0x8014D800: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_1;
    // 0x8014D800: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014D804: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8014D808:
    // 0x8014D808: jal         0x801C3044
    // 0x8014D80C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_2;
    // 0x8014D80C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x8014D810: bne         $v0, $zero, L_8014D964
    if (ctx->r2 != 0) {
        // 0x8014D814: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8014D964;
    }
    // 0x8014D814: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014D818: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014D81C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014D820: jal         0x801C2F0C
    // 0x8014D824: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_3;
    // 0x8014D824: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x8014D828: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014D82C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8014D830: lbu         $t4, 0x91($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X91);
    // 0x8014D834: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8014D838: beql        $t5, $zero, L_8014D854
    if (ctx->r13 == 0) {
        // 0x8014D83C: lw          $t7, 0x38($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X38);
            goto L_8014D854;
    }
    goto skip_2;
    // 0x8014D83C: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    skip_2:
    // 0x8014D840: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014D844: sb          $t6, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r14;
    // 0x8014D848: b           L_8014D964
    // 0x8014D84C: swc1        $f6, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f6.u32l;
        goto L_8014D964;
    // 0x8014D84C: swc1        $f6, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f6.u32l;
    // 0x8014D850: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
L_8014D854:
    // 0x8014D854: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014D858: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8014D85C: lh          $t8, 0x8($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X8);
    // 0x8014D860: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014D864: lw          $t9, 0x24($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X24);
    // 0x8014D868: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8014D86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D870: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014D874: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D878: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014D87C: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8014D880: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014D884: b           L_8014D968
    // 0x8014D888: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
        goto L_8014D968;
    // 0x8014D888: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x8014D88C: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
L_8014D890:
    // 0x8014D890: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8014D894: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
    // 0x8014D898: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D89C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014D8A0: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8014D8A4: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x8014D8A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014D8AC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014D8B0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D8B4: mflo        $t3
    ctx->r11 = lo;
    // 0x8014D8B8: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8014D8BC: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014D8C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014D8C4: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x8014D8C8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014D8CC: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8014D8D0: lbu         $t5, 0x90($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X90);
    // 0x8014D8D4: lwc1        $f4, 0x94($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014D8D8: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D8DC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014D8E0: mflo        $t6
    ctx->r14 = lo;
    // 0x8014D8E4: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8014D8E8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014D8EC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8014D8F0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8014D8F4: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x8014D8F8: swc1        $f0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f0.u32l;
    // 0x8014D8FC: lhu         $t7, 0x6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X6);
    // 0x8014D900: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8014D904: bgez        $t7, L_8014D918
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8014D908: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014D918;
    }
    // 0x8014D908: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014D90C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014D910: nop

    // 0x8014D914: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8014D918:
    // 0x8014D918: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8014D91C: nop

    // 0x8014D920: bc1fl       L_8014D968
    if (!c1cs) {
        // 0x8014D924: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014D968;
    }
    goto skip_3;
    // 0x8014D924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014D928: lw          $t8, 0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X38);
    // 0x8014D92C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014D930: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014D934: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x8014D938: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014D93C: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
    // 0x8014D940: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8014D944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014D948: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014D94C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014D950: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014D954: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    // 0x8014D958: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8014D95C: b           L_8014D968
    // 0x8014D960: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
        goto L_8014D968;
    // 0x8014D960: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
L_8014D964:
    // 0x8014D964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D968:
    // 0x8014D968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D970: jr          $ra
    // 0x8014D974: nop

    return;
    // 0x8014D974: nop

;}
RECOMP_FUNC void M7_FUN_8014d978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D97C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D980: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014D984: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8014D988: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014D98C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014D990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014D994: beq         $v0, $at, L_8014D9B8
    if (ctx->r2 == ctx->r1) {
        // 0x8014D998: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8014D9B8;
    }
    // 0x8014D998: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8014D99C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014D9A0: beq         $v0, $at, L_8014DB94
    if (ctx->r2 == ctx->r1) {
        // 0x8014D9A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8014DB94;
    }
    // 0x8014D9A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014D9A8: beql        $v0, $at, L_8014DCD0
    if (ctx->r2 == ctx->r1) {
        // 0x8014D9AC: lw          $t0, 0x24($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X24);
            goto L_8014DCD0;
    }
    goto skip_0;
    // 0x8014D9AC: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x8014D9B0: b           L_8014DF40
    // 0x8014D9B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014DF40;
    // 0x8014D9B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D9B8:
    // 0x8014D9B8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8014D9BC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014D9C0: jal         0x8001EB64
    // 0x8014D9C4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8014D9C4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x8014D9C8: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x8014D9CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014D9D0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8014D9D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014D9D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8014D9DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8014D9E0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8014D9E4: lwc1        $f6, 0x2954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014D9E8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014D9EC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8014D9F0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014D9F4: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8014D9F8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014D9FC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DA00: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x8014DA04: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8014DA08: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8014DA0C: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x8014DA10: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014DA14: jal         0x8001EAD0
    // 0x8014DA18: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8014DA18: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_1:
    // 0x8014DA1C: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DA20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014DA24: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8014DA28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8014DA2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8014DA30: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8014DA34: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8014DA38: lwc1        $f16, 0x2954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014DA3C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DA40: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8014DA44: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DA48: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8014DA4C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014DA50: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014DA54: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x8014DA58: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DA5C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8014DA60: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8014DA64: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014DA68: jal         0x8001EB64
    // 0x8014DA6C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x8014DA6C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_2:
    // 0x8014DA70: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DA74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014DA78: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8014DA7C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014DA80: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8014DA84: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8014DA88: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8014DA8C: lwc1        $f6, 0x2954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014DA90: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DA94: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8014DA98: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014DA9C: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8014DAA0: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014DAA4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DAA8: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x8014DAAC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8014DAB0: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8014DAB4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x8014DAB8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014DABC: jal         0x8001EAD0
    // 0x8014DAC0: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x8014DAC0: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_3:
    // 0x8014DAC4: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DAC8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8014DACC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014DAD0: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014DAD4: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x8014DAD8: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8014DADC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DAE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014DAE4: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8014DAE8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014DAEC: mflo        $t5
    ctx->r13 = lo;
    // 0x8014DAF0: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8014DAF4: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8014DAF8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014DAFC: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DB00: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8014DB04: add.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d + ctx->f10.d;
    // 0x8014DB08: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DB0C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8014DB10: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DB14: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014DB18: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014DB1C: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014DB20: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DB24: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014DB28: mflo        $t8
    ctx->r24 = lo;
    // 0x8014DB2C: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8014DB30: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014DB34: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014DB38: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8014DB3C: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DB40: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8014DB44: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x8014DB48: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8014DB4C: bgez        $t9, L_8014DB60
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014DB50: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8014DB60;
    }
    // 0x8014DB50: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014DB54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014DB58: nop

    // 0x8014DB5C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8014DB60:
    // 0x8014DB60: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8014DB64: nop

    // 0x8014DB68: bc1fl       L_8014DF40
    if (!c1cs) {
        // 0x8014DB6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014DF40;
    }
    goto skip_1;
    // 0x8014DB6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014DB70: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x8014DB74: jal         0x8014F358
    // 0x8014DB78: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_4;
    // 0x8014DB78: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    after_4:
    // 0x8014DB7C: beq         $v0, $zero, L_8014DF3C
    if (ctx->r2 == 0) {
        // 0x8014DB80: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8014DF3C;
    }
    // 0x8014DB80: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8014DB84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014DB88: sb          $t0, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r8;
    // 0x8014DB8C: b           L_8014DF3C
    // 0x8014DB90: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_8014DF3C;
    // 0x8014DB90: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_8014DB94:
    // 0x8014DB94: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8014DB98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014DB9C: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014DBA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014DBA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014DBA8: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x8014DBAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014DBB0: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8014DBB4: bc1f        L_8014DBC0
    if (!c1cs) {
        // 0x8014DBB8: nop
    
            goto L_8014DBC0;
    }
    // 0x8014DBB8: nop

    // 0x8014DBBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014DBC0:
    // 0x8014DBC0: beq         $v0, $zero, L_8014DBD0
    if (ctx->r2 == 0) {
        // 0x8014DBC4: swc1        $f4, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
            goto L_8014DBD0;
    }
    // 0x8014DBC4: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x8014DBC8: jal         0x8014F940
    // 0x8014DBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_5;
    // 0x8014DBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8014DBD0:
    // 0x8014DBD0: jal         0x801C3044
    // 0x8014DBD4: nop

    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_6;
    // 0x8014DBD4: nop

    after_6:
    // 0x8014DBD8: bne         $v0, $zero, L_8014DF3C
    if (ctx->r2 != 0) {
        // 0x8014DBDC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8014DF3C;
    }
    // 0x8014DBDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014DBE0: jal         0x801C2F0C
    // 0x8014DBE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_7;
    // 0x8014DBE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8014DBE8: lbu         $t1, 0x91($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X91);
    // 0x8014DBEC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8014DBF0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8014DBF4: beql        $t2, $zero, L_8014DC10
    if (ctx->r10 == 0) {
        // 0x8014DBF8: lw          $t4, 0x38($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X38);
            goto L_8014DC10;
    }
    goto skip_2;
    // 0x8014DBF8: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x8014DBFC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014DC00: sb          $t3, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r11;
    // 0x8014DC04: b           L_8014DF3C
    // 0x8014DC08: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
        goto L_8014DF3C;
    // 0x8014DC08: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
    // 0x8014DC0C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
L_8014DC10:
    // 0x8014DC10: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014DC14: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014DC18: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x8014DC1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014DC20: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8014DC24: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8014DC28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014DC2C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014DC30: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014DC34: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014DC38: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8014DC3C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DC40: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8014DC44: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8014DC48: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8014DC4C: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x8014DC50: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014DC54: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8014DC58: nop

    // 0x8014DC5C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014DC60: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DC64: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8014DC68: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8014DC6C: swc1        $f16, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f16.u32l;
    // 0x8014DC70: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8014DC74: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x8014DC78: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x8014DC7C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014DC80: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8014DC84: nop

    // 0x8014DC88: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014DC8C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8014DC90: div.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014DC94: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8014DC98: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
    // 0x8014DC9C: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8014DCA0: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8014DCA4: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8014DCA8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014DCAC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8014DCB0: nop

    // 0x8014DCB4: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014DCB8: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8014DCBC: div.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8014DCC0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8014DCC4: b           L_8014DF40
    // 0x8014DCC8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
        goto L_8014DF40;
    // 0x8014DCC8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x8014DCCC: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
L_8014DCD0:
    // 0x8014DCD0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014DCD4: jal         0x8001EB64
    // 0x8014DCD8: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x8014DCD8: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_8:
    // 0x8014DCDC: lbu         $t3, 0x90($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DCE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014DCE4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8014DCE8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8014DCEC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8014DCF0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8014DCF4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8014DCF8: lwc1        $f16, 0x2954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014DCFC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DD00: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8014DD04: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DD08: mul.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8014DD0C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014DD10: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DD14: sub.d       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f6.d - ctx->f18.d;
    // 0x8014DD18: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DD1C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8014DD20: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014DD24: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014DD28: jal         0x8001EAD0
    // 0x8014DD2C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_9;
    // 0x8014DD2C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_9:
    // 0x8014DD30: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DD34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014DD38: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8014DD3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8014DD40: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8014DD44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8014DD48: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8014DD4C: lwc1        $f8, 0x2954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014DD50: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DD54: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8014DD58: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DD5C: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8014DD60: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014DD64: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DD68: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x8014DD6C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8014DD70: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8014DD74: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8014DD78: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014DD7C: jal         0x8001EB64
    // 0x8014DD80: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_10;
    // 0x8014DD80: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_10:
    // 0x8014DD84: lbu         $t3, 0x90($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DD88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014DD8C: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8014DD90: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8014DD94: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8014DD98: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8014DD9C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8014DDA0: lwc1        $f16, 0x2954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014DDA4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DDA8: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8014DDAC: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DDB0: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8014DDB4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014DDB8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DDBC: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x8014DDC0: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DDC4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8014DDC8: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014DDCC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014DDD0: jal         0x8001EAD0
    // 0x8014DDD4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x8014DDD4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_11:
    // 0x8014DDD8: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DDDC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8014DDE0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014DDE4: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014DDE8: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x8014DDEC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8014DDF0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014DDF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014DDF8: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8014DDFC: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014DE00: mflo        $t9
    ctx->r25 = lo;
    // 0x8014DE04: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8014DE08: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8014DE0C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DE10: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DE14: mul.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8014DE18: sub.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d - ctx->f18.d;
    // 0x8014DE1C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8014DE20: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8014DE24: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x8014DE28: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014DE2C: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014DE30: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8014DE34: mflo        $t2
    ctx->r10 = lo;
    // 0x8014DE38: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x8014DE3C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014DE40: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014DE44: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x8014DE48: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8014DE4C: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8014DE50: lhu         $t3, 0x6($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X6);
    // 0x8014DE54: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8014DE58: bgez        $t3, L_8014DE6C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8014DE5C: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8014DE6C;
    }
    // 0x8014DE5C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014DE60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014DE64: nop

    // 0x8014DE68: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8014DE6C:
    // 0x8014DE6C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8014DE70: nop

    // 0x8014DE74: bc1fl       L_8014DF40
    if (!c1cs) {
        // 0x8014DE78: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014DF40;
    }
    goto skip_3;
    // 0x8014DE78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014DE7C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8014DE80: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014DE84: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014DE88: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x8014DE8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014DE90: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8014DE94: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8014DE98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014DE9C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014DEA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014DEA4: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8014DEA8: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014DEAC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8014DEB0: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x8014DEB4: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8014DEB8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8014DEBC: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x8014DEC0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014DEC4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8014DEC8: nop

    // 0x8014DECC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014DED0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014DED4: div.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8014DED8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8014DEDC: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x8014DEE0: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8014DEE4: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x8014DEE8: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x8014DEEC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014DEF0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8014DEF4: nop

    // 0x8014DEF8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014DEFC: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8014DF00: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8014DF04: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8014DF08: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    // 0x8014DF0C: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8014DF10: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8014DF14: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8014DF18: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014DF1C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8014DF20: nop

    // 0x8014DF24: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014DF28: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014DF2C: div.d       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014DF30: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8014DF34: b           L_8014DF40
    // 0x8014DF38: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
        goto L_8014DF40;
    // 0x8014DF38: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
L_8014DF3C:
    // 0x8014DF3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014DF40:
    // 0x8014DF40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014DF44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8014DF48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8014DF4C: jr          $ra
    // 0x8014DF50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8014DF50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014df54(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014df54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DF54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014DF58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014DF5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014DF60: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014DF64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014DF68: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8014DF6C: beq         $v0, $at, L_8014DF90
    if (ctx->r2 == ctx->r1) {
        // 0x8014DF70: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8014DF90;
    }
    // 0x8014DF70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014DF74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014DF78: beq         $v0, $at, L_8014E0E0
    if (ctx->r2 == ctx->r1) {
        // 0x8014DF7C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8014E0E0;
    }
    // 0x8014DF7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014DF80: beql        $v0, $at, L_8014E204
    if (ctx->r2 == ctx->r1) {
        // 0x8014DF84: lbu         $t2, 0x90($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X90);
            goto L_8014E204;
    }
    goto skip_0;
    // 0x8014DF84: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
    skip_0:
    // 0x8014DF88: b           L_8014E3B4
    // 0x8014DF8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014E3B4;
    // 0x8014DF8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014DF90:
    // 0x8014DF90: lbu         $t7, 0x90($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X90);
    // 0x8014DF94: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8014DF98: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8014DF9C: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014DFA0: addiu       $a3, $a3, 0x294C
    ctx->r7 = ADD32(ctx->r7, 0X294C);
    // 0x8014DFA4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8014DFA8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8014DFAC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014DFB0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8014DFB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014DFB8: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8014DFBC: mflo        $t8
    ctx->r24 = lo;
    // 0x8014DFC0: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8014DFC4: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8014DFC8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014DFCC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014DFD0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8014DFD4: div.d       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x8014DFD8: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x8014DFDC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014DFE0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8014DFE4: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
    // 0x8014DFE8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8014DFEC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014DFF0: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014DFF4: lw          $a0, 0x30($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X30);
    // 0x8014DFF8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014DFFC: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8014E000: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E004: mflo        $t3
    ctx->r11 = lo;
    // 0x8014E008: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x8014E00C: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014E010: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E014: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8014E018: div.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f12.d);
    // 0x8014E01C: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x8014E020: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E024: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8014E028: lbu         $t6, 0x90($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X90);
    // 0x8014E02C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8014E030: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E034: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x8014E038: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8014E03C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E040: mflo        $t7
    ctx->r15 = lo;
    // 0x8014E044: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8014E048: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014E04C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E050: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8014E054: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E058: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8014E05C: lbu         $t9, 0x90($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X90);
    // 0x8014E060: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014E064: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E068: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E06C: mflo        $t1
    ctx->r9 = lo;
    // 0x8014E070: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x8014E074: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014E078: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014E07C: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x8014E080: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E084: swc1        $f2, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f2.u32l;
    // 0x8014E088: lhu         $t2, 0x6($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X6);
    // 0x8014E08C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8014E090: bgez        $t2, L_8014E0A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014E094: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8014E0A4;
    }
    // 0x8014E094: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014E098: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014E09C: nop

    // 0x8014E0A0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8014E0A4:
    // 0x8014E0A4: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8014E0A8: nop

    // 0x8014E0AC: bc1fl       L_8014E3B4
    if (!c1cs) {
        // 0x8014E0B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014E3B4;
    }
    goto skip_1;
    // 0x8014E0B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014E0B4: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x8014E0B8: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x8014E0BC: jal         0x8014F358
    // 0x8014E0C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_0;
    // 0x8014E0C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014E0C4: beq         $v0, $zero, L_8014E3B0
    if (ctx->r2 == 0) {
        // 0x8014E0C8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8014E3B0;
    }
    // 0x8014E0C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014E0CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014E0D0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8014E0D4: sb          $t3, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r11;
    // 0x8014E0D8: b           L_8014E3B0
    // 0x8014E0DC: swc1        $f6, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f6.u32l;
        goto L_8014E3B0;
    // 0x8014E0DC: swc1        $f6, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f6.u32l;
L_8014E0E0:
    // 0x8014E0E0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8014E0E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014E0E8: lwc1        $f0, 0x94($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014E0EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014E0F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014E0F4: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x8014E0F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014E0FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014E100: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8014E104: bc1f        L_8014E110
    if (!c1cs) {
        // 0x8014E108: nop
    
            goto L_8014E110;
    }
    // 0x8014E108: nop

    // 0x8014E10C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E110:
    // 0x8014E110: beq         $v0, $zero, L_8014E124
    if (ctx->r2 == 0) {
        // 0x8014E114: swc1        $f8, 0x94($a2)
        MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
            goto L_8014E124;
    }
    // 0x8014E114: swc1        $f8, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
    // 0x8014E118: jal         0x8014F940
    // 0x8014E11C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_1;
    // 0x8014E11C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014E120: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_8014E124:
    // 0x8014E124: jal         0x801C3044
    // 0x8014E128: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_2;
    // 0x8014E128: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8014E12C: bne         $v0, $zero, L_8014E3B0
    if (ctx->r2 != 0) {
        // 0x8014E130: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8014E3B0;
    }
    // 0x8014E130: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014E134: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014E138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014E13C: jal         0x801C2F0C
    // 0x8014E140: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_3;
    // 0x8014E140: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8014E144: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014E148: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8014E14C: lbu         $t4, 0x91($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X91);
    // 0x8014E150: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8014E154: beql        $t5, $zero, L_8014E170
    if (ctx->r13 == 0) {
        // 0x8014E158: lw          $t7, 0x38($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X38);
            goto L_8014E170;
    }
    goto skip_2;
    // 0x8014E158: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    skip_2:
    // 0x8014E15C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014E160: sb          $t6, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r14;
    // 0x8014E164: b           L_8014E3B0
    // 0x8014E168: swc1        $f16, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f16.u32l;
        goto L_8014E3B0;
    // 0x8014E168: swc1        $f16, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f16.u32l;
    // 0x8014E16C: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
L_8014E170:
    // 0x8014E170: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014E174: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014E178: lh          $t8, 0x8($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X8);
    // 0x8014E17C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014E180: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8014E184: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8014E188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014E18C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8014E190: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014E194: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E198: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8014E19C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E1A0: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x8014E1A4: lw          $t2, 0x38($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X38);
    // 0x8014E1A8: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8014E1AC: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x8014E1B0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014E1B4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8014E1B8: nop

    // 0x8014E1BC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014E1C0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E1C4: div.d       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8014E1C8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E1CC: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x8014E1D0: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    // 0x8014E1D4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8014E1D8: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8014E1DC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014E1E0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8014E1E4: nop

    // 0x8014E1E8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014E1EC: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8014E1F0: div.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8014E1F4: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8014E1F8: b           L_8014E3B4
    // 0x8014E1FC: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
        goto L_8014E3B4;
    // 0x8014E1FC: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x8014E200: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
L_8014E204:
    // 0x8014E204: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8014E208: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8014E20C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E210: addiu       $a3, $a3, 0x294C
    ctx->r7 = ADD32(ctx->r7, 0X294C);
    // 0x8014E214: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8014E218: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8014E21C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014E220: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8014E224: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014E228: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8014E22C: mflo        $t3
    ctx->r11 = lo;
    // 0x8014E230: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x8014E234: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014E238: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014E23C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8014E240: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014E244: div.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x8014E248: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x8014E24C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E250: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8014E254: lbu         $t6, 0x90($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X90);
    // 0x8014E258: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8014E25C: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E260: lw          $a0, 0x30($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X30);
    // 0x8014E264: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8014E268: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E26C: mflo        $t7
    ctx->r15 = lo;
    // 0x8014E270: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8014E274: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014E278: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8014E27C: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8014E280: div.d       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x8014E284: sub.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d - ctx->f18.d;
    // 0x8014E288: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E28C: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x8014E290: lbu         $t1, 0x90($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X90);
    // 0x8014E294: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8014E298: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E29C: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x8014E2A0: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8014E2A4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E2A8: mflo        $t2
    ctx->r10 = lo;
    // 0x8014E2AC: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x8014E2B0: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8014E2B4: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E2B8: sub.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d - ctx->f18.d;
    // 0x8014E2BC: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E2C0: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x8014E2C4: lbu         $t4, 0x90($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X90);
    // 0x8014E2C8: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014E2CC: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E2D0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E2D4: mflo        $t5
    ctx->r13 = lo;
    // 0x8014E2D8: addu        $v1, $a3, $t5
    ctx->r3 = ADD32(ctx->r7, ctx->r13);
    // 0x8014E2DC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014E2E0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E2E4: add.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d + ctx->f18.d;
    // 0x8014E2E8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E2EC: swc1        $f2, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f2.u32l;
    // 0x8014E2F0: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x8014E2F4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8014E2F8: bgez        $t6, L_8014E30C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014E2FC: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8014E30C;
    }
    // 0x8014E2FC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014E300: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014E304: nop

    // 0x8014E308: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_8014E30C:
    // 0x8014E30C: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8014E310: nop

    // 0x8014E314: bc1fl       L_8014E3B4
    if (!c1cs) {
        // 0x8014E318: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014E3B4;
    }
    goto skip_3;
    // 0x8014E318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014E31C: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x8014E320: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014E324: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014E328: lh          $t8, 0x8($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X8);
    // 0x8014E32C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014E330: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8014E334: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8014E338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014E33C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8014E340: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014E344: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E348: div.d       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014E34C: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8014E350: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x8014E354: lw          $t2, 0x38($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X38);
    // 0x8014E358: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8014E35C: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x8014E360: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014E364: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8014E368: nop

    // 0x8014E36C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014E370: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E374: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8014E378: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E37C: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x8014E380: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    // 0x8014E384: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8014E388: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8014E38C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014E390: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8014E394: nop

    // 0x8014E398: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014E39C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8014E3A0: div.d       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014E3A4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E3A8: b           L_8014E3B4
    // 0x8014E3AC: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
        goto L_8014E3B4;
    // 0x8014E3AC: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
L_8014E3B0:
    // 0x8014E3B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E3B4:
    // 0x8014E3B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014E3B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014E3BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014E3C0: jr          $ra
    // 0x8014E3C4: nop

    return;
    // 0x8014E3C4: nop

;}
RECOMP_FUNC void M7_FUN_8014e3c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E3C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014E3CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014E3D0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8014E3D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8014E3D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014E3DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8014E3E0: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014E3E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8014E3E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014E3EC: beq         $v0, $a2, L_8014E480
    if (ctx->r2 == ctx->r6) {
        // 0x8014E3F0: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8014E480;
    }
    // 0x8014E3F0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8014E3F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014E3F8: beq         $v0, $at, L_8014E798
    if (ctx->r2 == ctx->r1) {
        // 0x8014E3FC: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8014E798;
    }
    // 0x8014E3FC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014E400: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014E404: beq         $v0, $at, L_8014E804
    if (ctx->r2 == ctx->r1) {
        // 0x8014E408: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8014E804;
    }
    // 0x8014E408: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8014E40C: bne         $v0, $at, L_8014ECB0
    if (ctx->r2 != ctx->r1) {
        // 0x8014E410: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8014ECB0;
    }
    // 0x8014E410: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014E414: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014E418: lbu         $t6, 0x434($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X434);
    // 0x8014E41C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8014E420: bnel        $a2, $t6, L_8014ECB4
    if (ctx->r6 != ctx->r14) {
        // 0x8014E424: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014ECB4;
    }
    goto skip_0;
    // 0x8014E424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8014E428: sb          $t7, 0x434($v1)
    MEM_B(0X434, ctx->r3) = ctx->r15;
    // 0x8014E42C: lbu         $t0, 0x90($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X90);
    // 0x8014E430: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8014E434: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014E438: multu       $t0, $s3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E43C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8014E440: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8014E444: addiu       $s2, $s2, 0x294C
    ctx->r18 = ADD32(ctx->r18, 0X294C);
    // 0x8014E448: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014E44C: sb          $t8, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r24;
    // 0x8014E450: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
    // 0x8014E454: swc1        $f4, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f4.u32l;
    // 0x8014E458: sw          $t9, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->r25;
    // 0x8014E45C: mflo        $t1
    ctx->r9 = lo;
    // 0x8014E460: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x8014E464: lhu         $a0, 0x12($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X12);
    // 0x8014E468: beql        $a0, $zero, L_8014ECB4
    if (ctx->r4 == 0) {
        // 0x8014E46C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014ECB4;
    }
    goto skip_1;
    // 0x8014E46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014E470: jal         0x80020718
    // 0x8014E474: nop

    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x8014E474: nop

    after_0:
    // 0x8014E478: b           L_8014ECB4
    // 0x8014E47C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014ECB4;
    // 0x8014E47C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E480:
    // 0x8014E480: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8014E484: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014E488: jal         0x8001EB64
    // 0x8014E48C: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8014E48C: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_1:
    // 0x8014E490: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E494: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8014E498: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8014E49C: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E4A0: addiu       $s2, $s2, 0x294C
    ctx->r18 = ADD32(ctx->r18, 0X294C);
    // 0x8014E4A4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8014E4A8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E4AC: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8014E4B0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E4B4: mflo        $t7
    ctx->r15 = lo;
    // 0x8014E4B8: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8014E4BC: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014E4C0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E4C4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E4C8: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8014E4CC: add.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f4.d + ctx->f16.d;
    // 0x8014E4D0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8014E4D4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8014E4D8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014E4DC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014E4E0: jal         0x8001EAD0
    // 0x8014E4E4: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8014E4E4: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_2:
    // 0x8014E4E8: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E4EC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8014E4F0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E4F4: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E4F8: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8014E4FC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E500: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E504: mflo        $t3
    ctx->r11 = lo;
    // 0x8014E508: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8014E50C: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014E510: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E514: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8014E518: sub.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d - ctx->f16.d;
    // 0x8014E51C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E520: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8014E524: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014E528: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014E52C: jal         0x8001EB64
    // 0x8014E530: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8014E530: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_3:
    // 0x8014E534: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E538: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8014E53C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E540: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E544: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8014E548: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E54C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E550: mflo        $t9
    ctx->r25 = lo;
    // 0x8014E554: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8014E558: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8014E55C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E560: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8014E564: sub.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f10.d - ctx->f16.d;
    // 0x8014E568: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8014E56C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8014E570: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x8014E574: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014E578: jal         0x8001EAD0
    // 0x8014E57C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8014E57C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_4:
    // 0x8014E580: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E584: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8014E588: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E58C: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E590: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8014E594: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8014E598: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E59C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E5A0: mflo        $t5
    ctx->r13 = lo;
    // 0x8014E5A4: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x8014E5A8: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8014E5AC: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E5B0: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8014E5B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014E5B8: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x8014E5BC: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E5C0: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8014E5C4: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014E5C8: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8014E5CC: nop

    // 0x8014E5D0: bc1fl       L_8014E710
    if (!c1cs) {
        // 0x8014E5D4: lbu         $t1, 0x90($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X90);
            goto L_8014E710;
    }
    goto skip_2;
    // 0x8014E5D4: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    skip_2:
    // 0x8014E5D8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8014E5DC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014E5E0: jal         0x8001EB64
    // 0x8014E5E4: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8014E5E4: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_5:
    // 0x8014E5E8: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E5EC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8014E5F0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E5F4: multu       $t0, $s3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E5F8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x8014E5FC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E600: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E604: mflo        $t1
    ctx->r9 = lo;
    // 0x8014E608: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x8014E60C: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8014E610: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8014E614: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8014E618: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8014E61C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E620: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8014E624: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8014E628: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014E62C: jal         0x8001EAD0
    // 0x8014E630: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x8014E630: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_6:
    // 0x8014E634: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E638: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x8014E63C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E640: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E644: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8014E648: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E64C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014E650: mflo        $t7
    ctx->r15 = lo;
    // 0x8014E654: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8014E658: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014E65C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E660: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x8014E664: sub.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d - ctx->f18.d;
    // 0x8014E668: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8014E66C: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8014E670: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014E674: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014E678: jal         0x8001EB64
    // 0x8014E67C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x8014E67C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_7:
    // 0x8014E680: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E684: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x8014E688: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E68C: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E690: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8014E694: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E698: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E69C: mflo        $t3
    ctx->r11 = lo;
    // 0x8014E6A0: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8014E6A4: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014E6A8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014E6AC: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8014E6B0: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8014E6B4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8014E6B8: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8014E6BC: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014E6C0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014E6C4: jal         0x8001EAD0
    // 0x8014E6C8: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x8014E6C8: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_8:
    // 0x8014E6CC: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E6D0: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8014E6D4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E6D8: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E6DC: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8014E6E0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E6E4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014E6E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8014E6EC: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8014E6F0: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8014E6F4: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E6F8: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8014E6FC: add.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d + ctx->f18.d;
    // 0x8014E700: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8014E704: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8014E708: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014E70C: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
L_8014E710:
    // 0x8014E710: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x8014E714: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014E718: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E71C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8014E720: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8014E724: mflo        $t2
    ctx->r10 = lo;
    // 0x8014E728: addu        $v1, $s2, $t2
    ctx->r3 = ADD32(ctx->r18, ctx->r10);
    // 0x8014E72C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014E730: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014E734: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x8014E738: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E73C: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x8014E740: lhu         $t3, 0x6($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X6);
    // 0x8014E744: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014E748: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014E74C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8014E750: bgez        $t3, L_8014E764
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8014E754: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014E764;
    }
    // 0x8014E754: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014E758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014E75C: nop

    // 0x8014E760: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_8014E764:
    // 0x8014E764: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8014E768: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014E76C: nop

    // 0x8014E770: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8014E774: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8014E778: nop

    // 0x8014E77C: bc1fl       L_8014ECB4
    if (!c1cs) {
        // 0x8014E780: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014ECB4;
    }
    goto skip_3;
    // 0x8014E780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014E784: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014E788: sb          $t4, 0x434($v1)
    MEM_B(0X434, ctx->r3) = ctx->r12;
    // 0x8014E78C: sb          $t5, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r13;
    // 0x8014E790: b           L_8014ECB0
    // 0x8014E794: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
        goto L_8014ECB0;
    // 0x8014E794: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
L_8014E798:
    // 0x8014E798: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014E79C: lbu         $t6, 0x434($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X434);
    // 0x8014E7A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8014E7A4: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8014E7A8: bnel        $t6, $at, L_8014ECB4
    if (ctx->r14 != ctx->r1) {
        // 0x8014E7AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014ECB4;
    }
    goto skip_4;
    // 0x8014E7AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8014E7B0: sb          $t7, 0x434($v1)
    MEM_B(0X434, ctx->r3) = ctx->r15;
    // 0x8014E7B4: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E7B8: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8014E7BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014E7C0: multu       $t0, $s3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E7C4: lw          $t9, 0x98($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X98);
    // 0x8014E7C8: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8014E7CC: addiu       $s2, $s2, 0x294C
    ctx->r18 = ADD32(ctx->r18, 0X294C);
    // 0x8014E7D0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8014E7D4: sb          $t8, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r24;
    // 0x8014E7D8: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    // 0x8014E7DC: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x8014E7E0: mflo        $t1
    ctx->r9 = lo;
    // 0x8014E7E4: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x8014E7E8: lhu         $a0, 0x12($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X12);
    // 0x8014E7EC: beql        $a0, $zero, L_8014ECB4
    if (ctx->r4 == 0) {
        // 0x8014E7F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014ECB4;
    }
    goto skip_5;
    // 0x8014E7F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x8014E7F4: jal         0x80020718
    // 0x8014E7F8: nop

    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_9;
    // 0x8014E7F8: nop

    after_9:
    // 0x8014E7FC: b           L_8014ECB4
    // 0x8014E800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014ECB4;
    // 0x8014E800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E804:
    // 0x8014E804: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8014E808: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014E80C: jal         0x8001EB64
    // 0x8014E810: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_10;
    // 0x8014E810: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_10:
    // 0x8014E814: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E818: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8014E81C: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8014E820: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E824: addiu       $s2, $s2, 0x294C
    ctx->r18 = ADD32(ctx->r18, 0X294C);
    // 0x8014E828: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8014E82C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E830: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8014E834: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E838: mflo        $t7
    ctx->r15 = lo;
    // 0x8014E83C: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8014E840: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014E844: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E848: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E84C: mul.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8014E850: sub.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d - ctx->f10.d;
    // 0x8014E854: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8014E858: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8014E85C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014E860: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014E864: jal         0x8001EAD0
    // 0x8014E868: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x8014E868: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_11:
    // 0x8014E86C: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E870: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8014E874: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E878: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E87C: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8014E880: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E884: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E888: mflo        $t3
    ctx->r11 = lo;
    // 0x8014E88C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8014E890: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014E894: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E898: mul.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8014E89C: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x8014E8A0: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E8A4: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8014E8A8: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014E8AC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014E8B0: jal         0x8001EB64
    // 0x8014E8B4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_12;
    // 0x8014E8B4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_12:
    // 0x8014E8B8: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E8BC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8014E8C0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E8C4: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E8C8: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8014E8CC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E8D0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E8D4: mflo        $t9
    ctx->r25 = lo;
    // 0x8014E8D8: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8014E8DC: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8014E8E0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E8E4: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8014E8E8: add.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f16.d + ctx->f10.d;
    // 0x8014E8EC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8014E8F0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8014E8F4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x8014E8F8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014E8FC: jal         0x8001EAD0
    // 0x8014E900: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_13;
    // 0x8014E900: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_13:
    // 0x8014E904: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E908: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8014E90C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E910: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E914: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8014E918: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014E91C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E920: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8014E924: mflo        $t5
    ctx->r13 = lo;
    // 0x8014E928: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x8014E92C: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8014E930: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E934: mul.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8014E938: sub.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d - ctx->f10.d;
    // 0x8014E93C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E940: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8014E944: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E948: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014E94C: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E950: mflo        $t8
    ctx->r24 = lo;
    // 0x8014E954: addu        $v1, $s2, $t8
    ctx->r3 = ADD32(ctx->r18, ctx->r24);
    // 0x8014E958: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x8014E95C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8014E960: bgez        $t9, L_8014E974
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014E964: cvt.s.w     $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8014E974;
    }
    // 0x8014E964: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014E968: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014E96C: nop

    // 0x8014E970: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8014E974:
    // 0x8014E974: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8014E978: nop

    // 0x8014E97C: bc1fl       L_8014EAD0
    if (!c1cs) {
        // 0x8014E980: lwc1        $f18, 0x8($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
            goto L_8014EAD0;
    }
    goto skip_6;
    // 0x8014E980: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    skip_6:
    // 0x8014E984: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8014E988: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014E98C: jal         0x8001EB64
    // 0x8014E990: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_14;
    // 0x8014E990: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_14:
    // 0x8014E994: lbu         $t3, 0x90($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E998: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x8014E99C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E9A0: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E9A4: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8014E9A8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014E9AC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014E9B0: mflo        $t4
    ctx->r12 = lo;
    // 0x8014E9B4: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8014E9B8: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8014E9BC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E9C0: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8014E9C4: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x8014E9C8: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8014E9CC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8014E9D0: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8014E9D4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014E9D8: jal         0x8001EAD0
    // 0x8014E9DC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x8014E9DC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_15:
    // 0x8014E9E0: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x8014E9E4: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8014E9E8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014E9EC: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E9F0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8014E9F4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014E9F8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014E9FC: mflo        $t0
    ctx->r8 = lo;
    // 0x8014EA00: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8014EA04: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8014EA08: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014EA0C: mul.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8014EA10: add.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f10.d + ctx->f16.d;
    // 0x8014EA14: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8014EA18: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8014EA1C: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8014EA20: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014EA24: jal         0x8001EB64
    // 0x8014EA28: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_16;
    // 0x8014EA28: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_16:
    // 0x8014EA2C: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EA30: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x8014EA34: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014EA38: multu       $t5, $s3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014EA3C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8014EA40: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014EA44: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014EA48: mflo        $t6
    ctx->r14 = lo;
    // 0x8014EA4C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8014EA50: lwc1        $f18, 0x8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8014EA54: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EA58: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8014EA5C: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x8014EA60: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8014EA64: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8014EA68: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8014EA6C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014EA70: jal         0x8001EAD0
    // 0x8014EA74: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_17;
    // 0x8014EA74: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_17:
    // 0x8014EA78: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EA7C: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x8014EA80: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014EA84: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014EA88: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x8014EA8C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014EA90: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EA94: mflo        $t2
    ctx->r10 = lo;
    // 0x8014EA98: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x8014EA9C: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8014EAA0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014EAA4: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8014EAA8: sub.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d - ctx->f16.d;
    // 0x8014EAAC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8014EAB0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8014EAB4: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EAB8: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014EABC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8014EAC0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8014EAC4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8014EAC8: addu        $v1, $s2, $t5
    ctx->r3 = ADD32(ctx->r18, ctx->r13);
    // 0x8014EACC: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
L_8014EAD0:
    // 0x8014EAD0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8014EAD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014EAD8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EADC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8014EAE0: add.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d + ctx->f8.d;
    // 0x8014EAE4: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x8014EAE8: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x8014EAEC: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x8014EAF0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014EAF4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014EAF8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8014EAFC: bgez        $t6, L_8014EB10
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014EB00: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014EB10;
    }
    // 0x8014EB00: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014EB04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014EB08: nop

    // 0x8014EB0C: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8014EB10:
    // 0x8014EB10: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8014EB14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014EB18: nop

    // 0x8014EB1C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8014EB20: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8014EB24: nop

    // 0x8014EB28: bc1fl       L_8014ECB4
    if (!c1cs) {
        // 0x8014EB2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014ECB4;
    }
    goto skip_7;
    // 0x8014EB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_7:
    // 0x8014EB30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014EB34: sb          $zero, 0x434($v1)
    MEM_B(0X434, ctx->r3) = 0;
    // 0x8014EB38: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8014EB3C: sb          $t7, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r15;
    // 0x8014EB40: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    // 0x8014EB44: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x8014EB48: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014EB4C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014EB50: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8014EB54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014EB58: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8014EB5C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014EB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014EB64: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014EB68: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EB6C: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8014EB70: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014EB74: swc1        $f8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f8.u32l;
    // 0x8014EB78: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8014EB7C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8014EB80: lh          $t3, 0xA($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XA);
    // 0x8014EB84: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014EB88: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8014EB8C: nop

    // 0x8014EB90: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014EB94: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014EB98: div.d       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8014EB9C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8014EBA0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    // 0x8014EBA4: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8014EBA8: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8014EBAC: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8014EBB0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014EBB4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8014EBB8: nop

    // 0x8014EBBC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014EBC0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8014EBC4: div.d       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8014EBC8: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8014EBCC: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x8014EBD0: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x8014EBD4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8014EBD8: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x8014EBDC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014EBE0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8014EBE4: nop

    // 0x8014EBE8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014EBEC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8014EBF0: div.d       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8014EBF4: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8014EBF8: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
    // 0x8014EBFC: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8014EC00: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8014EC04: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x8014EC08: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014EC0C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8014EC10: nop

    // 0x8014EC14: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014EC18: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014EC1C: div.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014EC20: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8014EC24: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x8014EC28: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8014EC2C: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x8014EC30: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x8014EC34: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014EC38: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8014EC3C: nop

    // 0x8014EC40: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014EC44: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8014EC48: div.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014EC4C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8014EC50: swc1        $f16, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f16.u32l;
    // 0x8014EC54: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8014EC58: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x8014EC5C: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x8014EC60: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014EC64: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8014EC68: nop

    // 0x8014EC6C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014EC70: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EC74: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8014EC78: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8014EC7C: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    // 0x8014EC80: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8014EC84: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x8014EC88: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8014EC8C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014EC90: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8014EC94: nop

    // 0x8014EC98: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014EC9C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8014ECA0: div.d       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8014ECA4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8014ECA8: b           L_8014ECB4
    // 0x8014ECAC: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
        goto L_8014ECB4;
    // 0x8014ECAC: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
L_8014ECB0:
    // 0x8014ECB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014ECB4:
    // 0x8014ECB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014ECB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8014ECBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8014ECC0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8014ECC4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8014ECC8: jr          $ra
    // 0x8014ECCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8014ECCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014ecd0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014ecd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014ECD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014ECD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014ECD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014ECDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8014ECE0: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014ECE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014ECE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014ECEC: beq         $v0, $at, L_8014ED0C
    if (ctx->r2 == ctx->r1) {
        // 0x8014ECF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014ED0C;
    }
    // 0x8014ECF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014ECF4: beq         $v0, $at, L_8014EE44
    if (ctx->r2 == ctx->r1) {
        // 0x8014ECF8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8014EE44;
    }
    // 0x8014ECF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014ECFC: beql        $v0, $at, L_8014EEEC
    if (ctx->r2 == ctx->r1) {
        // 0x8014ED00: lw          $t3, 0x24($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X24);
            goto L_8014EEEC;
    }
    goto skip_0;
    // 0x8014ED00: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x8014ED04: b           L_8014F05C
    // 0x8014ED08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F05C;
    // 0x8014ED08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014ED0C:
    // 0x8014ED0C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8014ED10: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014ED14: jal         0x8001EB64
    // 0x8014ED18: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8014ED18: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x8014ED1C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x8014ED20: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8014ED24: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014ED28: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014ED2C: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x8014ED30: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8014ED34: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014ED38: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8014ED3C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014ED40: mflo        $t0
    ctx->r8 = lo;
    // 0x8014ED44: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8014ED48: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8014ED4C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014ED50: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014ED54: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8014ED58: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x8014ED5C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8014ED60: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8014ED64: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8014ED68: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014ED6C: jal         0x8001EAD0
    // 0x8014ED70: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8014ED70: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x8014ED74: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x8014ED78: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8014ED7C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014ED80: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014ED84: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x8014ED88: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x8014ED8C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8014ED90: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014ED94: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8014ED98: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014ED9C: mflo        $t6
    ctx->r14 = lo;
    // 0x8014EDA0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8014EDA4: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8014EDA8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8014EDAC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014EDB0: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8014EDB4: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x8014EDB8: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8014EDBC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8014EDC0: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EDC4: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014EDC8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014EDCC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014EDD0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EDD4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014EDD8: mflo        $t9
    ctx->r25 = lo;
    // 0x8014EDDC: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x8014EDE0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014EDE4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014EDE8: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8014EDEC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8014EDF0: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8014EDF4: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x8014EDF8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8014EDFC: bgez        $t0, L_8014EE10
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8014EE00: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8014EE10;
    }
    // 0x8014EE00: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014EE04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014EE08: nop

    // 0x8014EE0C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8014EE10:
    // 0x8014EE10: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x8014EE14: nop

    // 0x8014EE18: bc1fl       L_8014F05C
    if (!c1cs) {
        // 0x8014EE1C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014F05C;
    }
    goto skip_1;
    // 0x8014EE1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014EE20: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x8014EE24: jal         0x8014F358
    // 0x8014EE28: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_2;
    // 0x8014EE28: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    after_2:
    // 0x8014EE2C: beq         $v0, $zero, L_8014F058
    if (ctx->r2 == 0) {
        // 0x8014EE30: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8014F058;
    }
    // 0x8014EE30: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8014EE34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014EE38: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x8014EE3C: b           L_8014F058
    // 0x8014EE40: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_8014F058;
    // 0x8014EE40: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_8014EE44:
    // 0x8014EE44: jal         0x801C3044
    // 0x8014EE48: nop

    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_3;
    // 0x8014EE48: nop

    after_3:
    // 0x8014EE4C: bne         $v0, $zero, L_8014F058
    if (ctx->r2 != 0) {
        // 0x8014EE50: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8014F058;
    }
    // 0x8014EE50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014EE54: jal         0x801C2F0C
    // 0x8014EE58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_4;
    // 0x8014EE58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8014EE5C: lbu         $t2, 0x91($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X91);
    // 0x8014EE60: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8014EE64: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8014EE68: beql        $t3, $zero, L_8014EE84
    if (ctx->r11 == 0) {
        // 0x8014EE6C: lw          $t5, 0x38($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X38);
            goto L_8014EE84;
    }
    goto skip_2;
    // 0x8014EE6C: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x8014EE70: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014EE74: sb          $t4, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r12;
    // 0x8014EE78: b           L_8014F058
    // 0x8014EE7C: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
        goto L_8014F058;
    // 0x8014EE7C: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
    // 0x8014EE80: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
L_8014EE84:
    // 0x8014EE84: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014EE88: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014EE8C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8014EE90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014EE94: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8014EE98: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8014EE9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014EEA0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014EEA4: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014EEA8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014EEAC: div.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014EEB0: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014EEB4: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x8014EEB8: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x8014EEBC: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x8014EEC0: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x8014EEC4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014EEC8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8014EECC: nop

    // 0x8014EED0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014EED4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8014EED8: div.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014EEDC: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8014EEE0: b           L_8014F05C
    // 0x8014EEE4: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
        goto L_8014F05C;
    // 0x8014EEE4: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x8014EEE8: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
L_8014EEEC:
    // 0x8014EEEC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014EEF0: jal         0x8001EB64
    // 0x8014EEF4: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8014EEF4: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_5:
    // 0x8014EEF8: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EEFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014EF00: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8014EF04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014EF08: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014EF0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014EF10: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8014EF14: lwc1        $f10, 0x2954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x8014EF18: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014EF1C: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8014EF20: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014EF24: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8014EF28: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014EF2C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8014EF30: sub.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d - ctx->f8.d;
    // 0x8014EF34: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8014EF38: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8014EF3C: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8014EF40: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014EF44: jal         0x8001EAD0
    // 0x8014EF48: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x8014EF48: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_6:
    // 0x8014EF4C: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EF50: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8014EF54: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014EF58: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014EF5C: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x8014EF60: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8014EF64: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8014EF68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014EF6C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x8014EF70: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8014EF74: mflo        $t2
    ctx->r10 = lo;
    // 0x8014EF78: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8014EF7C: lwc1        $f4, 0x8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8014EF80: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8014EF84: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8014EF88: mul.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8014EF8C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8014EF90: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8014EF94: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8014EF98: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x8014EF9C: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8014EFA0: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014EFA4: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014EFA8: mflo        $t5
    ctx->r13 = lo;
    // 0x8014EFAC: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x8014EFB0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014EFB4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014EFB8: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8014EFBC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8014EFC0: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8014EFC4: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x8014EFC8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8014EFCC: bgez        $t6, L_8014EFE0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014EFD0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8014EFE0;
    }
    // 0x8014EFD0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014EFD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014EFD8: nop

    // 0x8014EFDC: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_8014EFE0:
    // 0x8014EFE0: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x8014EFE4: nop

    // 0x8014EFE8: bc1fl       L_8014F05C
    if (!c1cs) {
        // 0x8014EFEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014F05C;
    }
    goto skip_3;
    // 0x8014EFEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014EFF0: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8014EFF4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014EFF8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014EFFC: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8014F000: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014F004: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8014F008: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8014F00C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014F010: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014F014: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014F018: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014F01C: div.d       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8014F020: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8014F024: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8014F028: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8014F02C: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8014F030: lh          $t2, 0xA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XA);
    // 0x8014F034: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014F038: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8014F03C: nop

    // 0x8014F040: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014F044: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8014F048: div.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8014F04C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8014F050: b           L_8014F05C
    // 0x8014F054: swc1        $f16, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f16.u32l;
        goto L_8014F05C;
    // 0x8014F054: swc1        $f16, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f16.u32l;
L_8014F058:
    // 0x8014F058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014F05C:
    // 0x8014F05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014F064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014F068: jr          $ra
    // 0x8014F06C: nop

    return;
    // 0x8014F06C: nop

;}
RECOMP_FUNC void M7_FUN_8014f070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014F074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014F07C: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x8014F080: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014F084: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014F088: beq         $v0, $at, L_8014F0A8
    if (ctx->r2 == ctx->r1) {
        // 0x8014F08C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014F0A8;
    }
    // 0x8014F08C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014F090: beq         $v0, $at, L_8014F178
    if (ctx->r2 == ctx->r1) {
        // 0x8014F094: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8014F178;
    }
    // 0x8014F094: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014F098: beql        $v0, $at, L_8014F248
    if (ctx->r2 == ctx->r1) {
        // 0x8014F09C: lbu         $t2, 0x90($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X90);
            goto L_8014F248;
    }
    goto skip_0;
    // 0x8014F09C: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
    skip_0:
    // 0x8014F0A0: b           L_8014F320
    // 0x8014F0A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F320;
    // 0x8014F0A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014F0A8:
    // 0x8014F0A8: lbu         $t7, 0x90($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X90);
    // 0x8014F0AC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8014F0B0: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x8014F0B4: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F0B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014F0BC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8014F0C0: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x8014F0C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F0C8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014F0CC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8014F0D0: mflo        $t8
    ctx->r24 = lo;
    // 0x8014F0D4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8014F0D8: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8014F0DC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014F0E0: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8014F0E4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8014F0E8: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8014F0EC: lbu         $t0, 0x90($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X90);
    // 0x8014F0F0: lwc1        $f4, 0x94($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014F0F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014F0F8: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F0FC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014F100: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014F104: mflo        $t1
    ctx->r9 = lo;
    // 0x8014F108: addu        $v1, $a0, $t1
    ctx->r3 = ADD32(ctx->r4, ctx->r9);
    // 0x8014F10C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014F110: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014F114: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8014F118: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x8014F11C: swc1        $f0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f0.u32l;
    // 0x8014F120: lhu         $t2, 0x6($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X6);
    // 0x8014F124: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8014F128: bgez        $t2, L_8014F13C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014F12C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8014F13C;
    }
    // 0x8014F12C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014F130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014F134: nop

    // 0x8014F138: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8014F13C:
    // 0x8014F13C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8014F140: nop

    // 0x8014F144: bc1fl       L_8014F320
    if (!c1cs) {
        // 0x8014F148: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014F320;
    }
    goto skip_1;
    // 0x8014F148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014F14C: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x8014F150: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x8014F154: jal         0x8014F358
    // 0x8014F158: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_0;
    // 0x8014F158: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014F15C: beq         $v0, $zero, L_8014F31C
    if (ctx->r2 == 0) {
        // 0x8014F160: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8014F31C;
    }
    // 0x8014F160: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014F164: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014F168: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8014F16C: sb          $t3, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r11;
    // 0x8014F170: b           L_8014F31C
    // 0x8014F174: swc1        $f8, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
        goto L_8014F31C;
    // 0x8014F174: swc1        $f8, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
L_8014F178:
    // 0x8014F178: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8014F17C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014F180: lwc1        $f0, 0x94($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014F184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014F188: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014F18C: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x8014F190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014F194: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014F198: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8014F19C: bc1f        L_8014F1A8
    if (!c1cs) {
        // 0x8014F1A0: nop
    
            goto L_8014F1A8;
    }
    // 0x8014F1A0: nop

    // 0x8014F1A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014F1A8:
    // 0x8014F1A8: beq         $v0, $zero, L_8014F1BC
    if (ctx->r2 == 0) {
        // 0x8014F1AC: swc1        $f18, 0x94($a2)
        MEM_W(0X94, ctx->r6) = ctx->f18.u32l;
            goto L_8014F1BC;
    }
    // 0x8014F1AC: swc1        $f18, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f18.u32l;
    // 0x8014F1B0: jal         0x8014F940
    // 0x8014F1B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_1;
    // 0x8014F1B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014F1B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8014F1BC:
    // 0x8014F1BC: jal         0x801C3B5C
    // 0x8014F1C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_2;
    // 0x8014F1C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x8014F1C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8014F1C8: bne         $v0, $at, L_8014F31C
    if (ctx->r2 != ctx->r1) {
        // 0x8014F1CC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8014F31C;
    }
    // 0x8014F1CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014F1D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014F1D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014F1D8: jal         0x801C2F0C
    // 0x8014F1DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_3;
    // 0x8014F1DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x8014F1E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8014F1E4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8014F1E8: lbu         $t4, 0x91($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X91);
    // 0x8014F1EC: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8014F1F0: beql        $t5, $zero, L_8014F20C
    if (ctx->r13 == 0) {
        // 0x8014F1F4: lw          $t7, 0x38($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X38);
            goto L_8014F20C;
    }
    goto skip_2;
    // 0x8014F1F4: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    skip_2:
    // 0x8014F1F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014F1FC: sb          $t6, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r14;
    // 0x8014F200: b           L_8014F31C
    // 0x8014F204: swc1        $f6, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f6.u32l;
        goto L_8014F31C;
    // 0x8014F204: swc1        $f6, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f6.u32l;
    // 0x8014F208: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
L_8014F20C:
    // 0x8014F20C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014F210: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8014F214: lh          $t8, 0x8($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X8);
    // 0x8014F218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014F21C: lw          $t9, 0x24($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X24);
    // 0x8014F220: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8014F224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014F228: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014F22C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014F230: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014F234: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8014F238: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014F23C: b           L_8014F320
    // 0x8014F240: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
        goto L_8014F320;
    // 0x8014F240: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x8014F244: lbu         $t2, 0x90($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X90);
L_8014F248:
    // 0x8014F248: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8014F24C: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
    // 0x8014F250: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F254: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014F258: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8014F25C: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x8014F260: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F264: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014F268: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014F26C: mflo        $t3
    ctx->r11 = lo;
    // 0x8014F270: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8014F274: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8014F278: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8014F27C: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x8014F280: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014F284: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8014F288: lbu         $t5, 0x90($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X90);
    // 0x8014F28C: lwc1        $f4, 0x94($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X94);
    // 0x8014F290: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F294: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014F298: mflo        $t6
    ctx->r14 = lo;
    // 0x8014F29C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8014F2A0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8014F2A4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8014F2A8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8014F2AC: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x8014F2B0: swc1        $f0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f0.u32l;
    // 0x8014F2B4: lhu         $t7, 0x6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X6);
    // 0x8014F2B8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8014F2BC: bgez        $t7, L_8014F2D0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8014F2C0: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014F2D0;
    }
    // 0x8014F2C0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014F2C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014F2C8: nop

    // 0x8014F2CC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8014F2D0:
    // 0x8014F2D0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8014F2D4: nop

    // 0x8014F2D8: bc1fl       L_8014F320
    if (!c1cs) {
        // 0x8014F2DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014F320;
    }
    goto skip_3;
    // 0x8014F2DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8014F2E0: lw          $t8, 0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X38);
    // 0x8014F2E4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014F2E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014F2EC: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x8014F2F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014F2F4: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
    // 0x8014F2F8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8014F2FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014F300: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014F304: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014F308: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014F30C: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    // 0x8014F310: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8014F314: b           L_8014F320
    // 0x8014F318: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
        goto L_8014F320;
    // 0x8014F318: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
L_8014F31C:
    // 0x8014F31C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014F320:
    // 0x8014F320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014F328: jr          $ra
    // 0x8014F32C: nop

    return;
    // 0x8014F32C: nop

;}
RECOMP_FUNC void M7_FUN_8014f330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014F334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F338: jal         0x801C3B88
    // 0x8014F33C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C3B88)(rdram, ctx);
        goto after_0;
    // 0x8014F33C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014F340: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8014F344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014F34C: xor         $v0, $v0, $t6
    ctx->r2 = ctx->r2 ^ ctx->r14;
    // 0x8014F350: jr          $ra
    // 0x8014F354: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8014F354: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014f358(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014f358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F358: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014F35C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F360: lwc1        $f4, 0x680($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X680);
    // 0x8014F364: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014F368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014F36C: lui         $t7, 0x168
    ctx->r15 = S32(0X168 << 16);
    // 0x8014F370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F374: addiu       $t6, $zero, 0x1100
    ctx->r14 = ADD32(0, 0X1100);
    // 0x8014F378: ori         $t7, $t7, 0x3F
    ctx->r15 = ctx->r15 | 0X3F;
    // 0x8014F37C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8014F380: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8014F384: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8014F388: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x8014F38C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8014F390: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8014F394: sh          $t8, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r24;
    // 0x8014F398: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8014F39C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8014F3A0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8014F3A4: jal         0x801C2F0C
    // 0x8014F3A8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_0;
    // 0x8014F3A8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8014F3AC: beql        $v0, $zero, L_8014F3F0
    if (ctx->r2 == 0) {
        // 0x8014F3B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014F3F0;
    }
    goto skip_0;
    // 0x8014F3B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014F3B4: jal         0x801C3C3C
    // 0x8014F3B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3C3C)(rdram, ctx);
        goto after_1;
    // 0x8014F3B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8014F3BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014F3C0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x8014F3C4: lw          $v1, 0xDC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XDC);
    // 0x8014F3C8: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8014F3CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014F3D0: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x8014F3D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F3D8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8014F3DC: sw          $t0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r8;
    // 0x8014F3E0: lw          $t1, 0xDC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XDC);
    // 0x8014F3E4: b           L_8014F3F0
    // 0x8014F3E8: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
        goto L_8014F3F0;
    // 0x8014F3E8: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
    // 0x8014F3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014F3F0:
    // 0x8014F3F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F3F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014F3F8: jr          $ra
    // 0x8014F3FC: nop

    return;
    // 0x8014F3FC: nop

;}
RECOMP_FUNC void M7_FUN_8014f400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F400: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014F404: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8014F408: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8014F40C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8014F410: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8014F414: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8014F418: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8014F41C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x8014F420: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014F424: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014F428: bnel        $t6, $at, L_8014F570
    if (ctx->r14 != ctx->r1) {
        // 0x8014F42C: lw          $t3, 0x24($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X24);
            goto L_8014F570;
    }
    goto skip_0;
    // 0x8014F42C: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    skip_0:
    // 0x8014F430: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8014F434: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014F438: jal         0x8001EAD0
    // 0x8014F43C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8014F43C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_0:
    // 0x8014F440: lbu         $t9, 0x90($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F444: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8014F448: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8014F44C: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F450: addiu       $s2, $s2, 0x294C
    ctx->r18 = ADD32(ctx->r18, 0X294C);
    // 0x8014F454: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014F458: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8014F45C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8014F460: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8014F464: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8014F468: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F46C: mflo        $t0
    ctx->r8 = lo;
    // 0x8014F470: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8014F474: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8014F478: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8014F47C: bgez        $t2, L_8014F490
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014F480: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8014F490;
    }
    // 0x8014F480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014F484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014F488: nop

    // 0x8014F48C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8014F490:
    // 0x8014F490: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F494: ldc1        $f16, 0x688($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X688);
    // 0x8014F498: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8014F49C: lw          $t3, 0x38($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X38);
    // 0x8014F4A0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8014F4A4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8014F4A8: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x8014F4AC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014F4B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014F4B4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8014F4B8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014F4BC: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8014F4C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014F4C4: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8014F4C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8014F4CC: div.d       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x8014F4D0: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x8014F4D4: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8014F4D8: swc1        $f16, 0x334($s0)
    MEM_W(0X334, ctx->r16) = ctx->f16.u32l;
    // 0x8014F4DC: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x8014F4E0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014F4E4: jal         0x8001EB64
    // 0x8014F4E8: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8014F4E8: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_1:
    // 0x8014F4EC: lbu         $t7, 0x90($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F4F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F4F4: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F4F8: mflo        $t8
    ctx->r24 = lo;
    // 0x8014F4FC: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8014F500: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8014F504: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8014F508: bgez        $t0, L_8014F51C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8014F50C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8014F51C;
    }
    // 0x8014F50C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014F510: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014F514: nop

    // 0x8014F518: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8014F51C:
    // 0x8014F51C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F520: ldc1        $f6, 0x690($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X690);
    // 0x8014F524: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8014F528: lw          $t1, 0x38($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X38);
    // 0x8014F52C: mul.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x8014F530: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8014F534: lh          $t2, 0xA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XA);
    // 0x8014F538: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8014F53C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014F540: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8014F544: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8014F548: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x8014F54C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014F550: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8014F554: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8014F558: div.d       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x8014F55C: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x8014F560: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8014F564: b           L_8014F6A4
    // 0x8014F568: swc1        $f6, 0x33C($s0)
    MEM_W(0X33C, ctx->r16) = ctx->f6.u32l;
        goto L_8014F6A4;
    // 0x8014F568: swc1        $f6, 0x33C($s0)
    MEM_W(0X33C, ctx->r16) = ctx->f6.u32l;
    // 0x8014F56C: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
L_8014F570:
    // 0x8014F570: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014F574: jal         0x8001EAD0
    // 0x8014F578: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8014F578: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_2:
    // 0x8014F57C: lbu         $t5, 0x90($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F580: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8014F584: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8014F588: multu       $t5, $s3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F58C: addiu       $s2, $s2, 0x294C
    ctx->r18 = ADD32(ctx->r18, 0X294C);
    // 0x8014F590: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014F594: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8014F598: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8014F59C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8014F5A0: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8014F5A4: mflo        $t6
    ctx->r14 = lo;
    // 0x8014F5A8: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8014F5AC: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8014F5B0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8014F5B4: bgez        $t8, L_8014F5CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8014F5B8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8014F5CC;
    }
    // 0x8014F5B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014F5BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F5C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014F5C4: nop

    // 0x8014F5C8: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_8014F5CC:
    // 0x8014F5CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F5D0: ldc1        $f4, 0x698($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X698);
    // 0x8014F5D4: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8014F5D8: lw          $t9, 0x38($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X38);
    // 0x8014F5DC: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8014F5E0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8014F5E4: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x8014F5E8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8014F5EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014F5F0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8014F5F4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8014F5F8: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x8014F5FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014F600: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8014F604: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8014F608: div.d       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x8014F60C: add.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
    // 0x8014F610: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8014F614: swc1        $f4, 0x334($s0)
    MEM_W(0X334, ctx->r16) = ctx->f4.u32l;
    // 0x8014F618: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x8014F61C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014F620: jal         0x8001EB64
    // 0x8014F624: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8014F624: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_3:
    // 0x8014F628: lbu         $t3, 0x90($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F62C: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F630: mflo        $t4
    ctx->r12 = lo;
    // 0x8014F634: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8014F638: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x8014F63C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8014F640: bgez        $t6, L_8014F658
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014F644: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014F658;
    }
    // 0x8014F644: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014F648: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F64C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014F650: nop

    // 0x8014F654: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8014F658:
    // 0x8014F658: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F65C: ldc1        $f18, 0x6A0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X6A0);
    // 0x8014F660: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8014F664: lw          $t7, 0x38($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X38);
    // 0x8014F668: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8014F66C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8014F670: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8014F674: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014F678: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014F67C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8014F680: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8014F684: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8014F688: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014F68C: mul.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8014F690: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8014F694: div.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x8014F698: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8014F69C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8014F6A0: swc1        $f18, 0x33C($s0)
    MEM_W(0X33C, ctx->r16) = ctx->f18.u32l;
L_8014F6A4:
    // 0x8014F6A4: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x8014F6A8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8014F6AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014F6B0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014F6B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014F6B8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8014F6BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014F6C0: swc1        $f8, 0x338($s0)
    MEM_W(0X338, ctx->r16) = ctx->f8.u32l;
    // 0x8014F6C4: lbu         $t1, 0x92($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X92);
    // 0x8014F6C8: bnel        $t1, $at, L_8014F6F4
    if (ctx->r9 != ctx->r1) {
        // 0x8014F6CC: lw          $t4, 0x24($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X24);
            goto L_8014F6F4;
    }
    goto skip_1;
    // 0x8014F6CC: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    skip_1:
    // 0x8014F6D0: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x8014F6D4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014F6D8: lh          $v0, 0x12($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X12);
    // 0x8014F6DC: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x8014F6E0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8014F6E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8014F6E8: b           L_8014F6FC
    // 0x8014F6EC: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
        goto L_8014F6FC;
    // 0x8014F6EC: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8014F6F0: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
L_8014F6F4:
    // 0x8014F6F4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8014F6F8: lh          $v0, 0x12($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X12);
L_8014F6FC:
    // 0x8014F6FC: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8014F700: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014F704: jal         0x8001EAD0
    // 0x8014F708: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8014F708: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_4:
    // 0x8014F70C: lbu         $t6, 0x90($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F710: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014F714: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8014F718: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F71C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F720: mflo        $t7
    ctx->r15 = lo;
    // 0x8014F724: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8014F728: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x8014F72C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8014F730: bgez        $t9, L_8014F744
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014F734: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8014F744;
    }
    // 0x8014F734: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014F738: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014F73C: nop

    // 0x8014F740: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8014F744:
    // 0x8014F744: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014F748: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014F74C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8014F750: lw          $t0, 0x38($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X38);
    // 0x8014F754: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8014F758: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F75C: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x8014F760: ldc1        $f10, 0x6A8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X6A8);
    // 0x8014F764: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8014F768: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8014F76C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F770: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8014F774: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014F778: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8014F77C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014F780: div.d       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x8014F784: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x8014F788: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8014F78C: swc1        $f6, 0x340($s0)
    MEM_W(0X340, ctx->r16) = ctx->f6.u32l;
    // 0x8014F790: lbu         $t2, 0x90($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F794: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F798: mflo        $t3
    ctx->r11 = lo;
    // 0x8014F79C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8014F7A0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8014F7A4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8014F7A8: bgez        $t5, L_8014F7BC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8014F7AC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8014F7BC;
    }
    // 0x8014F7AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014F7B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014F7B4: nop

    // 0x8014F7B8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8014F7BC:
    // 0x8014F7BC: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x8014F7C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F7C4: ldc1        $f16, 0x6B0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X6B0);
    // 0x8014F7C8: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8014F7CC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8014F7D0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014F7D4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8014F7D8: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8014F7DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014F7E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014F7E4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014F7E8: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8014F7EC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8014F7F0: div.d       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x8014F7F4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8014F7F8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8014F7FC: jal         0x8001EB64
    // 0x8014F800: swc1        $f10, 0x344($s0)
    MEM_W(0X344, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8014F800: swc1        $f10, 0x344($s0)
    MEM_W(0X344, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x8014F804: lbu         $t8, 0x90($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X90);
    // 0x8014F808: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014F80C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014F810: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F814: mflo        $t9
    ctx->r25 = lo;
    // 0x8014F818: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8014F81C: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8014F820: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8014F824: bgez        $t1, L_8014F838
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8014F828: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8014F838;
    }
    // 0x8014F828: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014F82C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014F830: nop

    // 0x8014F834: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8014F838:
    // 0x8014F838: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014F83C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014F840: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8014F844: lw          $t2, 0x38($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X38);
    // 0x8014F848: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8014F84C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F850: lh          $t3, 0xA($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XA);
    // 0x8014F854: ldc1        $f18, 0x6B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X6B8);
    // 0x8014F858: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8014F85C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8014F860: lwc1        $f12, 0x340($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X340);
    // 0x8014F864: lwc1        $f14, 0x344($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X344);
    // 0x8014F868: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8014F86C: lw          $a3, 0x334($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X334);
    // 0x8014F870: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014F874: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8014F878: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8014F87C: lwc1        $f10, 0x338($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X338);
    // 0x8014F880: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x8014F884: lwc1        $f18, 0x33C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X33C);
    // 0x8014F888: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8014F88C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8014F890: add.d       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f6.d + ctx->f4.d;
    // 0x8014F894: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8014F898: swc1        $f8, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->f8.u32l;
    // 0x8014F89C: jal         0x8010843C
    // 0x8014F8A0: lw          $a2, 0x348($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X348);
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_6;
    // 0x8014F8A0: lw          $a2, 0x348($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X348);
    after_6:
    // 0x8014F8A4: beql        $v0, $zero, L_8014F8C8
    if (ctx->r2 == 0) {
        // 0x8014F8A8: lw          $v0, 0xE8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XE8);
            goto L_8014F8C8;
    }
    goto skip_2;
    // 0x8014F8A8: lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE8);
    skip_2:
    // 0x8014F8AC: lwc1        $f6, 0x380($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X380);
    // 0x8014F8B0: lwc1        $f4, 0x384($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X384);
    // 0x8014F8B4: lwc1        $f16, 0x388($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X388);
    // 0x8014F8B8: swc1        $f6, 0x334($s0)
    MEM_W(0X334, ctx->r16) = ctx->f6.u32l;
    // 0x8014F8BC: swc1        $f4, 0x338($s0)
    MEM_W(0X338, ctx->r16) = ctx->f4.u32l;
    // 0x8014F8C0: swc1        $f16, 0x33C($s0)
    MEM_W(0X33C, ctx->r16) = ctx->f16.u32l;
    // 0x8014F8C4: lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE8);
L_8014F8C8:
    // 0x8014F8C8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014F8CC: addiu       $a1, $a1, 0x26AC
    ctx->r5 = ADD32(ctx->r5, 0X26AC);
    // 0x8014F8D0: lw          $t4, 0x2C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F8D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014F8D8: lwc1        $f8, 0x30($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X30);
    // 0x8014F8DC: swc1        $f8, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->f8.u32l;
    // 0x8014F8E0: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F8E4: lwc1        $f10, 0x34($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X34);
    // 0x8014F8E8: swc1        $f10, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->f10.u32l;
    // 0x8014F8EC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F8F0: lwc1        $f18, 0x38($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X38);
    // 0x8014F8F4: swc1        $f18, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->f18.u32l;
    // 0x8014F8F8: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F8FC: lwc1        $f6, 0x3C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x8014F900: swc1        $f6, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->f6.u32l;
    // 0x8014F904: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F908: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8014F90C: swc1        $f4, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->f4.u32l;
    // 0x8014F910: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F914: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8014F918: jal         0x80005670
    // 0x8014F91C: swc1        $f16, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_7;
    // 0x8014F91C: swc1        $f16, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->f16.u32l;
    after_7:
    // 0x8014F920: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8014F924: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8014F928: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8014F92C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8014F930: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8014F934: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8014F938: jr          $ra
    // 0x8014F93C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8014F93C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014f940(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014f940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F940: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014F944: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014F948: lw          $v0, 0xE8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014f94c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014f94c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014F950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F954: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F958: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014F95C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8014F960: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x8014F964: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014F968: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8014F96C: swc1        $f4, 0x1E8($v1)
    MEM_W(0X1E8, ctx->r3) = ctx->f4.u32l;
    // 0x8014F970: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F974: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014F978: lwc1        $f6, 0x34($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X34);
    // 0x8014F97C: swc1        $f6, 0x1EC($v1)
    MEM_W(0X1EC, ctx->r3) = ctx->f6.u32l;
    // 0x8014F980: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F984: lwc1        $f8, 0x38($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8014F988: swc1        $f8, 0x1F0($v1)
    MEM_W(0X1F0, ctx->r3) = ctx->f8.u32l;
    // 0x8014F98C: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F990: lwc1        $f8, 0x328($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X328);
    // 0x8014F994: lwc1        $f10, 0x3C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x8014F998: swc1        $f10, 0x1F4($v1)
    MEM_W(0X1F4, ctx->r3) = ctx->f10.u32l;
    // 0x8014F99C: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F9A0: lwc1        $f10, 0x32C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X32C);
    // 0x8014F9A4: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8014F9A8: swc1        $f4, 0x1F8($v1)
    MEM_W(0X1F8, ctx->r3) = ctx->f4.u32l;
    // 0x8014F9AC: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x8014F9B0: lwc1        $f4, 0x330($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X330);
    // 0x8014F9B4: lwc1        $f6, 0x44($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X44);
    // 0x8014F9B8: swc1        $f8, 0x334($v1)
    MEM_W(0X334, ctx->r3) = ctx->f8.u32l;
    // 0x8014F9BC: swc1        $f10, 0x338($v1)
    MEM_W(0X338, ctx->r3) = ctx->f10.u32l;
    // 0x8014F9C0: swc1        $f6, 0x1FC($v1)
    MEM_W(0X1FC, ctx->r3) = ctx->f6.u32l;
    // 0x8014F9C4: lwc1        $f6, 0x198($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X198);
    // 0x8014F9C8: swc1        $f4, 0x33C($v1)
    MEM_W(0X33C, ctx->r3) = ctx->f4.u32l;
    // 0x8014F9CC: swc1        $f6, 0x340($v1)
    MEM_W(0X340, ctx->r3) = ctx->f6.u32l;
    // 0x8014F9D0: lw          $t2, 0x38($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X38);
    // 0x8014F9D4: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x8014F9D8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8014F9DC: nop

    // 0x8014F9E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014F9E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014F9E8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8014F9EC: div.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f12.d);
    // 0x8014F9F0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8014F9F4: lwc1        $f6, 0x1A0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1A0);
    // 0x8014F9F8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8014F9FC: swc1        $f6, 0x348($v1)
    MEM_W(0X348, ctx->r3) = ctx->f6.u32l;
    // 0x8014FA00: swc1        $f4, 0x344($v1)
    MEM_W(0X344, ctx->r3) = ctx->f4.u32l;
    // 0x8014FA04: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x8014FA08: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x8014FA0C: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x8014FA10: lwc1        $f8, 0x30($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8014FA14: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8014FA18: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8014FA1C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014FA20: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8014FA24: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x8014FA28: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8014FA2C: nop

    // 0x8014FA30: bc1fl       L_8014FA4C
    if (!c1cs) {
        // 0x8014FA34: sub.d       $f4, $f0, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f0.d - ctx->f2.d;
            goto L_8014FA4C;
    }
    goto skip_0;
    // 0x8014FA34: sub.d       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f0.d - ctx->f2.d;
    skip_0:
    // 0x8014FA38: sub.d       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f0.d - ctx->f2.d;
    // 0x8014FA3C: neg.d       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = -ctx->f8.d;
    // 0x8014FA40: b           L_8014FA50
    // 0x8014FA44: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
        goto L_8014FA50;
    // 0x8014FA44: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8014FA48: sub.d       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f0.d - ctx->f2.d;
L_8014FA4C:
    // 0x8014FA4C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_8014FA50:
    // 0x8014FA50: lh          $t5, 0x8($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X8);
    // 0x8014FA54: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8014FA58: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8014FA5C: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8014FA60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014FA64: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8014FA68: div.d       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = DIV_D(ctx->f4.d, ctx->f12.d);
    // 0x8014FA6C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8014FA70: nop

    // 0x8014FA74: bc1fl       L_8014FA90
    if (!c1cs) {
        // 0x8014FA78: sub.d       $f10, $f2, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f2.d - ctx->f0.d;
            goto L_8014FA90;
    }
    goto skip_1;
    // 0x8014FA78: sub.d       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f2.d - ctx->f0.d;
    skip_1:
    // 0x8014FA7C: sub.d       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f2.d - ctx->f0.d;
    // 0x8014FA80: neg.d       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = -ctx->f6.d;
    // 0x8014FA84: b           L_8014FA94
    // 0x8014FA88: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_8014FA94;
    // 0x8014FA88: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8014FA8C: sub.d       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f2.d - ctx->f0.d;
L_8014FA90:
    // 0x8014FA90: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
L_8014FA94:
    // 0x8014FA94: lh          $t6, 0xA($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XA);
    // 0x8014FA98: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8014FA9C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8014FAA0: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8014FAA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014FAA8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014FAAC: div.d       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x8014FAB0: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8014FAB4: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8014FAB8: nop

    // 0x8014FABC: bc1fl       L_8014FAD8
    if (!c1cs) {
        // 0x8014FAC0: sub.d       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f0.d - ctx->f2.d;
            goto L_8014FAD8;
    }
    goto skip_2;
    // 0x8014FAC0: sub.d       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f0.d - ctx->f2.d;
    skip_2:
    // 0x8014FAC4: sub.d       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f0.d - ctx->f2.d;
    // 0x8014FAC8: neg.d       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = -ctx->f4.d;
    // 0x8014FACC: b           L_8014FADC
    // 0x8014FAD0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
        goto L_8014FADC;
    // 0x8014FAD0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8014FAD4: sub.d       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f0.d - ctx->f2.d;
L_8014FAD8:
    // 0x8014FAD8: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_8014FADC:
    // 0x8014FADC: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8014FAE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014FAE4: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8014FAE8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8014FAEC: jal         0x8002FC20
    // 0x8014FAF0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8014FAF0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x8014FAF4: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x8014FAF8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8014FAFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014FB00: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8014FB04: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014FB08: div.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8014FB0C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014FB10: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014FB14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8014FB18: addiu       $a1, $a1, 0x26C0
    ctx->r5 = ADD32(ctx->r5, 0X26C0);
    // 0x8014FB1C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8014FB20: jal         0x80005670
    // 0x8014FB24: swc1        $f8, 0x200($v1)
    MEM_W(0X200, ctx->r3) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8014FB24: swc1        $f8, 0x200($v1)
    MEM_W(0X200, ctx->r3) = ctx->f8.u32l;
    after_1:
    // 0x8014FB28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FB2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014FB30: jr          $ra
    // 0x8014FB34: nop

    return;
    // 0x8014FB34: nop

;}
RECOMP_FUNC void M7_FUN_8014fb38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FB38: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8014FB3C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8014FB40: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8014FB44: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8014FB48: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8014FB4C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8014FB50: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x8014FB54: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8014FB58: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8014FB5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014FB60: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8014FB64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014FB68: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8014FB6C: lhu         $t8, 0x2950($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2950);
    // 0x8014FB70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014FB74: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8014FB78: bne         $t8, $zero, L_8014FB90
    if (ctx->r24 != 0) {
        // 0x8014FB7C: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_8014FB90;
    }
    // 0x8014FB7C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8014FB80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014FB84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8014FB88: b           L_8014FB9C
    // 0x8014FB8C: lbu         $v0, 0x3A7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3A7);
        goto L_8014FB9C;
    // 0x8014FB8C: lbu         $v0, 0x3A7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3A7);
L_8014FB90:
    // 0x8014FB90: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8014FB94: nop

    // 0x8014FB98: lbu         $v0, 0x3A7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3A7);
L_8014FB9C:
    // 0x8014FB9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014FBA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014FBA4: beq         $v1, $v0, L_8014FBB4
    if (ctx->r3 == ctx->r2) {
        // 0x8014FBA8: nop
    
            goto L_8014FBB4;
    }
    // 0x8014FBA8: nop

    // 0x8014FBAC: bnel        $v0, $at, L_8014FE80
    if (ctx->r2 != ctx->r1) {
        // 0x8014FBB0: lw          $t5, 0x24($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X24);
            goto L_8014FE80;
    }
    goto skip_0;
    // 0x8014FBB0: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    skip_0:
L_8014FBB4:
    // 0x8014FBB4: bnel        $v1, $v0, L_8014FBE4
    if (ctx->r3 != ctx->r2) {
        // 0x8014FBB8: lw          $t1, 0x24($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X24);
            goto L_8014FBE4;
    }
    goto skip_1;
    // 0x8014FBB8: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    skip_1:
    // 0x8014FBBC: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x8014FBC0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014FBC4: lh          $v0, 0x12($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X12);
    // 0x8014FBC8: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x8014FBCC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8014FBD0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8014FBD4: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8014FBD8: b           L_8014FBEC
    // 0x8014FBDC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_8014FBEC;
    // 0x8014FBDC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8014FBE0: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
L_8014FBE4:
    // 0x8014FBE4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014FBE8: lhu         $v0, 0x12($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X12);
L_8014FBEC:
    // 0x8014FBEC: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8014FBF0: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8014FBF4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014FBF8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014FBFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014FC00: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8014FC04: jal         0x8001EAD0
    // 0x8014FC08: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8014FC08: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8014FC0C: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8014FC10: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x8014FC14: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014FC18: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8014FC1C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8014FC20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014FC24: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8014FC28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014FC2C: jal         0x8001EB64
    // 0x8014FC30: swc1        $f8, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8014FC30: swc1        $f8, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8014FC34: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8014FC38: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x8014FC3C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8014FC40: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8014FC44: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014FC48: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014FC4C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014FC50: lwc1        $f16, 0xC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8014FC54: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8014FC58: swc1        $f18, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->f18.u32l;
    // 0x8014FC5C: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x8014FC60: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014FC64: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014FC68: sh          $t9, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r25;
    // 0x8014FC6C: jal         0x8001EAD0
    // 0x8014FC70: swc1        $f4, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8014FC70: swc1        $f4, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8014FC74: lbu         $t0, 0x90($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X90);
    // 0x8014FC78: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8014FC7C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014FC80: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8014FC84: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8014FC88: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8014FC8C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8014FC90: lhu         $t2, 0x2958($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2958);
    // 0x8014FC94: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8014FC98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8014FC9C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8014FCA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014FCA4: bgez        $t2, L_8014FCBC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014FCA8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8014FCBC;
    }
    // 0x8014FCA8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014FCAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014FCB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014FCB4: nop

    // 0x8014FCB8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8014FCBC:
    // 0x8014FCBC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014FCC0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8014FCC4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8014FCC8: lw          $t3, 0x38($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X38);
    // 0x8014FCCC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8014FCD0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8014FCD4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014FCD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014FCDC: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x8014FCE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FCE4: ldc1        $f8, 0x6C0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X6C0);
    // 0x8014FCE8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8014FCEC: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8014FCF0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8014FCF4: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8014FCF8: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8014FCFC: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8014FD00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8014FD04: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014FD08: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8014FD0C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8014FD10: div.d       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8014FD14: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x8014FD18: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8014FD1C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014FD20: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8014FD24: swc1        $f6, 0x328($s0)
    MEM_W(0X328, ctx->r16) = ctx->f6.u32l;
    // 0x8014FD28: lw          $t5, 0x38($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X38);
    // 0x8014FD2C: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x8014FD30: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8014FD34: nop

    // 0x8014FD38: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014FD3C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8014FD40: div.d       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x8014FD44: add.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d + ctx->f18.d;
    // 0x8014FD48: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8014FD4C: jal         0x8001EB64
    // 0x8014FD50: swc1        $f10, 0x32C($s0)
    MEM_W(0X32C, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8014FD50: swc1        $f10, 0x32C($s0)
    MEM_W(0X32C, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x8014FD54: lbu         $t7, 0x90($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X90);
    // 0x8014FD58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8014FD5C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8014FD60: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8014FD64: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8014FD68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8014FD6C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8014FD70: lhu         $t9, 0x2958($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X2958);
    // 0x8014FD74: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8014FD78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8014FD7C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8014FD80: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014FD84: bgez        $t9, L_8014FD9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014FD88: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8014FD9C;
    }
    // 0x8014FD88: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014FD8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014FD90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014FD94: nop

    // 0x8014FD98: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_8014FD9C:
    // 0x8014FD9C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014FDA0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8014FDA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014FDA8: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8014FDAC: lw          $t0, 0x38($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X38);
    // 0x8014FDB0: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8014FDB4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8014FDB8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8014FDBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014FDC0: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x8014FDC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FDC8: ldc1        $f4, 0x6C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X6C8);
    // 0x8014FDCC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8014FDD0: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8014FDD4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8014FDD8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8014FDDC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8014FDE0: add.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f16.d + ctx->f4.d;
    // 0x8014FDE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8014FDE8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8014FDEC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014FDF0: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8014FDF4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8014FDF8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8014FDFC: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8014FE00: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8014FE04: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8014FE08: lwc1        $f16, 0x328($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X328);
    // 0x8014FE0C: div.d       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x8014FE10: lwc1        $f4, 0x32C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X32C);
    // 0x8014FE14: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8014FE18: addiu       $a0, $a0, 0x4A0
    ctx->r4 = ADD32(ctx->r4, 0X4A0);
    // 0x8014FE1C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8014FE20: lwc1        $f4, 0x1A0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x8014FE24: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8014FE28: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8014FE2C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8014FE30: addiu       $a1, $zero, 0x85A
    ctx->r5 = ADD32(0, 0X85A);
    // 0x8014FE34: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8014FE38: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8014FE3C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8014FE40: add.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d + ctx->f18.d;
    // 0x8014FE44: lwc1        $f18, 0x198($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X198);
    // 0x8014FE48: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8014FE4C: lwc1        $f6, 0x19C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X19C);
    // 0x8014FE50: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8014FE54: swc1        $f8, 0x330($s0)
    MEM_W(0X330, ctx->r16) = ctx->f8.u32l;
    // 0x8014FE58: lwc1        $f10, 0x330($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X330);
    // 0x8014FE5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014FE60: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8014FE64: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8014FE68: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014FE6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014FE70: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8014FE74: jal         0x8011AAF4
    // 0x8014FE78: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_4;
    // 0x8014FE78: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8014FE7C: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
L_8014FE80:
    // 0x8014FE80: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8014FE84: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8014FE88: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014FE8C: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8014FE90: swc1        $f18, 0x3A8($s0)
    MEM_W(0X3A8, ctx->r16) = ctx->f18.u32l;
    // 0x8014FE94: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x8014FE98: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014FE9C: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8014FEA0: swc1        $f6, 0x3AC($s0)
    MEM_W(0X3AC, ctx->r16) = ctx->f6.u32l;
    // 0x8014FEA4: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x8014FEA8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8014FEAC: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8014FEB0: swc1        $f8, 0x3B0($s0)
    MEM_W(0X3B0, ctx->r16) = ctx->f8.u32l;
    // 0x8014FEB4: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x8014FEB8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8014FEBC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8014FEC0: lh          $t3, 0x12($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X12);
    // 0x8014FEC4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8014FEC8: nop

    // 0x8014FECC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014FED0: swc1        $f4, 0x3B4($s0)
    MEM_W(0X3B4, ctx->r16) = ctx->f4.u32l;
    // 0x8014FED4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8014FED8: jr          $ra
    // 0x8014FEDC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8014FEDC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014fee0(rdram, ctx);
;}
