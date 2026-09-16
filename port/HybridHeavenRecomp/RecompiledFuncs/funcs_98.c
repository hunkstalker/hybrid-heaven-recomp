#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_8022b8c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022B8C4: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B8C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8022B8CC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8022B8D0: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
    // 0x8022B8D4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8022B8D8: bne         $v0, $zero, L_8022B8EC
    if (ctx->r2 != 0) {
        // 0x8022B8DC: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_8022B8EC;
    }
    // 0x8022B8DC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8022B8E0: sb          $t7, 0x2DF($a0)
    MEM_B(0X2DF, ctx->r4) = ctx->r15;
    // 0x8022B8E4: b           L_8022B9FC
    // 0x8022B8E8: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
        goto L_8022B9FC;
    // 0x8022B8E8: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
L_8022B8EC:
    // 0x8022B8EC: beq         $t9, $zero, L_8022B908
    if (ctx->r25 == 0) {
        // 0x8022B8F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8022B908;
    }
    // 0x8022B8F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8022B8F4: lbu         $t0, 0x2F0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B8F8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8022B8FC: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
    // 0x8022B900: lw          $t2, 0x2D4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B904: lbu         $v1, 0xC($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0XC);
L_8022B908:
    // 0x8022B908: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x8022B90C: beql        $t3, $zero, L_8022B92C
    if (ctx->r11 == 0) {
        // 0x8022B910: andi        $v0, $v1, 0xC
        ctx->r2 = ctx->r3 & 0XC;
            goto L_8022B92C;
    }
    goto skip_0;
    // 0x8022B910: andi        $v0, $v1, 0xC
    ctx->r2 = ctx->r3 & 0XC;
    skip_0:
    // 0x8022B914: lbu         $t4, 0x2F0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B918: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8022B91C: sb          $t5, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r13;
    // 0x8022B920: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B924: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
    // 0x8022B928: andi        $v0, $v1, 0xC
    ctx->r2 = ctx->r3 & 0XC;
L_8022B92C:
    // 0x8022B92C: bne         $v0, $at, L_8022B94C
    if (ctx->r2 != ctx->r1) {
        // 0x8022B930: nop
    
            goto L_8022B94C;
    }
    // 0x8022B930: nop

    // 0x8022B934: lbu         $t7, 0x2F0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B938: ori         $t8, $t7, 0xC
    ctx->r24 = ctx->r15 | 0XC;
    // 0x8022B93C: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
    // 0x8022B940: lw          $t9, 0x2D4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B944: b           L_8022B99C
    // 0x8022B948: lbu         $v1, 0xC($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0XC);
        goto L_8022B99C;
    // 0x8022B948: lbu         $v1, 0xC($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0XC);
L_8022B94C:
    // 0x8022B94C: beql        $v0, $zero, L_8022B9A0
    if (ctx->r2 == 0) {
        // 0x8022B950: andi        $v0, $v1, 0x30
        ctx->r2 = ctx->r3 & 0X30;
            goto L_8022B9A0;
    }
    goto skip_1;
    // 0x8022B950: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
    skip_1:
    // 0x8022B954: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x8022B958: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022B95C: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x8022B960: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x8022B964: bnel        $t2, $at, L_8022B98C
    if (ctx->r10 != ctx->r1) {
        // 0x8022B968: lbu         $t7, 0x2F0($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
            goto L_8022B98C;
    }
    goto skip_2;
    // 0x8022B968: lbu         $t7, 0x2F0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
    skip_2:
    // 0x8022B96C: lbu         $t3, 0x2F0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B970: xori        $t4, $v0, 0xC
    ctx->r12 = ctx->r2 ^ 0XC;
    // 0x8022B974: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8022B978: sb          $t5, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r13;
    // 0x8022B97C: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B980: b           L_8022B99C
    // 0x8022B984: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
        goto L_8022B99C;
    // 0x8022B984: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
    // 0x8022B988: lbu         $t7, 0x2F0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2F0);
L_8022B98C:
    // 0x8022B98C: or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // 0x8022B990: sb          $t8, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r24;
    // 0x8022B994: lw          $t9, 0x2D4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022B998: lbu         $v1, 0xC($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0XC);
L_8022B99C:
    // 0x8022B99C: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
L_8022B9A0:
    // 0x8022B9A0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8022B9A4: bne         $v0, $at, L_8022B9BC
    if (ctx->r2 != ctx->r1) {
        // 0x8022B9A8: nop
    
            goto L_8022B9BC;
    }
    // 0x8022B9A8: nop

    // 0x8022B9AC: lbu         $t0, 0x2F0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B9B0: ori         $t1, $t0, 0x30
    ctx->r9 = ctx->r8 | 0X30;
    // 0x8022B9B4: b           L_8022B9FC
    // 0x8022B9B8: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
        goto L_8022B9FC;
    // 0x8022B9B8: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
L_8022B9BC:
    // 0x8022B9BC: beql        $v0, $zero, L_8022BA00
    if (ctx->r2 == 0) {
        // 0x8022B9C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BA00;
    }
    goto skip_3;
    // 0x8022B9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8022B9C4: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x8022B9C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022B9CC: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x8022B9D0: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x8022B9D4: bnel        $t4, $at, L_8022B9F4
    if (ctx->r12 != ctx->r1) {
        // 0x8022B9D8: lbu         $t8, 0x2F0($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
            goto L_8022B9F4;
    }
    goto skip_4;
    // 0x8022B9D8: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
    skip_4:
    // 0x8022B9DC: lbu         $t5, 0x2F0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022B9E0: xori        $t6, $v0, 0x30
    ctx->r14 = ctx->r2 ^ 0X30;
    // 0x8022B9E4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8022B9E8: b           L_8022B9FC
    // 0x8022B9EC: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
        goto L_8022B9FC;
    // 0x8022B9EC: sb          $t7, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r15;
    // 0x8022B9F0: lbu         $t8, 0x2F0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2F0);
L_8022B9F4:
    // 0x8022B9F4: or          $t9, $t8, $v0
    ctx->r25 = ctx->r24 | ctx->r2;
    // 0x8022B9F8: sb          $t9, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r25;
L_8022B9FC:
    // 0x8022B9FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022BA00:
    // 0x8022BA00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8022BA04:
    // 0x8022BA04: lbu         $t0, 0x2F0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2F0);
    // 0x8022BA08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022BA0C: sllv        $t2, $t1, $v1
    ctx->r10 = S32(ctx->r9 << (ctx->r3 & 31));
    // 0x8022BA10: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x8022BA14: beq         $t3, $zero, L_8022BA28
    if (ctx->r11 == 0) {
        // 0x8022BA18: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8022BA28;
    }
    // 0x8022BA18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8022BA1C: lbu         $t4, 0x2DF($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2DF);
    // 0x8022BA20: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8022BA24: sb          $t5, 0x2DF($a0)
    MEM_B(0X2DF, ctx->r4) = ctx->r13;
L_8022BA28:
    // 0x8022BA28: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8022BA2C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022BA30: bne         $at, $zero, L_8022BA04
    if (ctx->r1 != 0) {
        // 0x8022BA34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8022BA04;
    }
    // 0x8022BA34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8022BA38: lbu         $t6, 0x2DF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2DF);
    // 0x8022BA3C: jr          $ra
    // 0x8022BA40: sb          $t6, 0x2DF($a1)
    MEM_B(0X2DF, ctx->r5) = ctx->r14;
    return;
    // 0x8022BA40: sb          $t6, 0x2DF($a1)
    MEM_B(0X2DF, ctx->r5) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022ba44(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022ba44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BA44: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022BA48: lbu         $v0, -0x33E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022ba4c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022ba4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BA4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8022BA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022BA54: bne         $v0, $zero, L_8022BA68
    if (ctx->r2 != 0) {
        // 0x8022BA58: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8022BA68;
    }
    // 0x8022BA58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8022BA5C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8022BA60: b           L_8022BA70
    // 0x8022BA64: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_8022BA70;
    // 0x8022BA64: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_8022BA68:
    // 0x8022BA68: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8022BA6C: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_8022BA70:
    // 0x8022BA70: bne         $v0, $zero, L_8022BA84
    if (ctx->r2 != 0) {
        // 0x8022BA74: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_8022BA84;
    }
    // 0x8022BA74: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022BA78: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022BA7C: b           L_8022BA88
    // 0x8022BA80: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
        goto L_8022BA88;
    // 0x8022BA80: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_8022BA84:
    // 0x8022BA84: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8022BA88:
    // 0x8022BA88: lbu         $v0, 0x2D8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D8);
    // 0x8022BA8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022BA90: beq         $v0, $at, L_8022BAB8
    if (ctx->r2 == ctx->r1) {
        // 0x8022BA94: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8022BAB8;
    }
    // 0x8022BA94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8022BA98: beq         $v0, $at, L_8022BAB8
    if (ctx->r2 == ctx->r1) {
        // 0x8022BA9C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8022BAB8;
    }
    // 0x8022BA9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022BAA0: beq         $v0, $at, L_8022BAB8
    if (ctx->r2 == ctx->r1) {
        // 0x8022BAA4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8022BAB8;
    }
    // 0x8022BAA4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8022BAA8: beq         $v0, $at, L_8022BAB8
    if (ctx->r2 == ctx->r1) {
        // 0x8022BAAC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8022BAB8;
    }
    // 0x8022BAAC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8022BAB0: bnel        $v0, $at, L_8022BB18
    if (ctx->r2 != ctx->r1) {
        // 0x8022BAB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BB18;
    }
    goto skip_0;
    // 0x8022BAB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8022BAB8:
    // 0x8022BAB8: lbu         $t6, 0x2FA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2FA);
    // 0x8022BABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022BAC0: bnel        $t6, $at, L_8022BB18
    if (ctx->r14 != ctx->r1) {
        // 0x8022BAC4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BB18;
    }
    goto skip_1;
    // 0x8022BAC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8022BAC8: sb          $zero, 0x2FA($a1)
    MEM_B(0X2FA, ctx->r5) = 0;
    // 0x8022BACC: sb          $zero, 0x2DF($a0)
    MEM_B(0X2DF, ctx->r4) = 0;
    // 0x8022BAD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8022BAD4: jal         0x8022B8C4
    // 0x8022BAD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8022B8C4)(rdram, ctx);
        goto after_0;
    // 0x8022BAD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8022BADC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8022BAE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8022BAE4: lbu         $t7, 0x2DA($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2DA);
    // 0x8022BAE8: beql        $t7, $zero, L_8022BB18
    if (ctx->r15 == 0) {
        // 0x8022BAEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BB18;
    }
    goto skip_2;
    // 0x8022BAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8022BAF0: lw          $t8, 0x30($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X30);
    // 0x8022BAF4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8022BAF8: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x8022BAFC: bnel        $t0, $zero, L_8022BB18
    if (ctx->r8 != 0) {
        // 0x8022BB00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BB18;
    }
    goto skip_3;
    // 0x8022BB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8022BB04: jal         0x80232E94
    // 0x8022BB08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80232E94)(rdram, ctx);
        goto after_1;
    // 0x8022BB08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8022BB0C: b           L_8022BB18
    // 0x8022BB10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022BB18;
    // 0x8022BB10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022BB18:
    // 0x8022BB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022BB1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8022BB20: jr          $ra
    // 0x8022BB24: nop

    return;
    // 0x8022BB24: nop

;}
RECOMP_FUNC void M10_FUN_8022bb28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BB28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022BB2C: lbu         $v1, -0x33E0($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022bb30(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022bb30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BB30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022BB34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022BB38: bne         $v1, $zero, L_8022BB4C
    if (ctx->r3 != 0) {
        // 0x8022BB3C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8022BB4C;
    }
    // 0x8022BB3C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022BB40: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022BB44: b           L_8022BB50
    // 0x8022BB48: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_8022BB50;
    // 0x8022BB48: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8022BB4C:
    // 0x8022BB4C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_8022BB50:
    // 0x8022BB50: lbu         $v1, 0x2D8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2D8);
    // 0x8022BB54: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8022BB58: beq         $v1, $at, L_8022BB68
    if (ctx->r3 == ctx->r1) {
        // 0x8022BB5C: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8022BB68;
    }
    // 0x8022BB5C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8022BB60: bnel        $v1, $at, L_8022BBA0
    if (ctx->r3 != ctx->r1) {
        // 0x8022BB64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BBA0;
    }
    goto skip_0;
    // 0x8022BB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8022BB68:
    // 0x8022BB68: lbu         $t6, 0x2FA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2FA);
    // 0x8022BB6C: beql        $t6, $zero, L_8022BBA0
    if (ctx->r14 == 0) {
        // 0x8022BB70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BBA0;
    }
    goto skip_1;
    // 0x8022BB70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8022BB74: lbu         $t7, 0x2DA($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2DA);
    // 0x8022BB78: sb          $zero, 0x2FA($v0)
    MEM_B(0X2FA, ctx->r2) = 0;
    // 0x8022BB7C: beq         $t7, $zero, L_8022BB94
    if (ctx->r15 == 0) {
        // 0x8022BB80: nop
    
            goto L_8022BB94;
    }
    // 0x8022BB80: nop

    // 0x8022BB84: lbu         $t8, 0x304($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X304);
    // 0x8022BB88: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022BB8C: jal         0x80232E94
    // 0x8022BB90: sb          $t9, 0x304($v0)
    MEM_B(0X304, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80232E94)(rdram, ctx);
        goto after_0;
    // 0x8022BB90: sb          $t9, 0x304($v0)
    MEM_B(0X304, ctx->r2) = ctx->r25;
    after_0:
L_8022BB94:
    // 0x8022BB94: b           L_8022BBA0
    // 0x8022BB98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022BBA0;
    // 0x8022BB98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022BB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022BBA0:
    // 0x8022BBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022BBA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022BBA8: jr          $ra
    // 0x8022BBAC: nop

    return;
    // 0x8022BBAC: nop

;}
RECOMP_FUNC void M10_FUN_8022bbb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BBB0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022BBB4: lbu         $t6, -0x33E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022bbb8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022bbb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BBB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8022BBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022BBC0: bne         $t6, $zero, L_8022BBD4
    if (ctx->r14 != 0) {
        // 0x8022BBC4: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8022BBD4;
    }
    // 0x8022BBC4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022BBC8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022BBCC: b           L_8022BBD8
    // 0x8022BBD0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
        goto L_8022BBD8;
    // 0x8022BBD0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8022BBD4:
    // 0x8022BBD4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8022BBD8:
    // 0x8022BBD8: lbu         $t7, 0x2FA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2FA);
    // 0x8022BBDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022BBE0: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x8022BBE4: bne         $t7, $at, L_8022BD18
    if (ctx->r15 != ctx->r1) {
        // 0x8022BBE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8022BD18;
    }
    // 0x8022BBE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022BBEC: lhu         $t8, 0x9A($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X9A);
    // 0x8022BBF0: sb          $zero, 0x2FA($v1)
    MEM_B(0X2FA, ctx->r3) = 0;
    // 0x8022BBF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022BBF8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8022BBFC: addiu       $a1, $a1, 0x76F0
    ctx->r5 = ADD32(ctx->r5, 0X76F0);
    // 0x8022BC00: bgez        $t8, L_8022BC14
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8022BC04: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022BC14;
    }
    // 0x8022BC04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022BC08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022BC0C: nop

    // 0x8022BC10: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8022BC14:
    // 0x8022BC14: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8022BC18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022BC1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8022BC20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8022BC24: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8022BC28: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022BC2C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022BC30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022BC34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8022BC38: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022BC3C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8022BC40: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8022BC44: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8022BC48: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022BC4C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8022BC50: nop

    // 0x8022BC54: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022BC58: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8022BC5C: nop

    // 0x8022BC60: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8022BC64: beql        $a2, $zero, L_8022BCB8
    if (ctx->r6 == 0) {
        // 0x8022BC68: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_8022BCB8;
    }
    goto skip_0;
    // 0x8022BC68: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8022BC6C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022BC70: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022BC74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8022BC78: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x8022BC7C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8022BC80: nop

    // 0x8022BC84: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022BC88: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8022BC8C: nop

    // 0x8022BC90: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8022BC94: bne         $a2, $zero, L_8022BCAC
    if (ctx->r6 != 0) {
        // 0x8022BC98: nop
    
            goto L_8022BCAC;
    }
    // 0x8022BC98: nop

    // 0x8022BC9C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8022BCA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022BCA4: b           L_8022BCC4
    // 0x8022BCA8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_8022BCC4;
    // 0x8022BCA8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_8022BCAC:
    // 0x8022BCAC: b           L_8022BCC4
    // 0x8022BCB0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_8022BCC4;
    // 0x8022BCB0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8022BCB4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_8022BCB8:
    // 0x8022BCB8: nop

    // 0x8022BCBC: bltz        $a2, L_8022BCAC
    if (SIGNED(ctx->r6) < 0) {
        // 0x8022BCC0: nop
    
            goto L_8022BCAC;
    }
    // 0x8022BCC0: nop

L_8022BCC4:
    // 0x8022BCC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022BCC8: sh          $a2, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r6;
    // 0x8022BCCC: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x8022BCD0: jal         0x80005670
    // 0x8022BCD4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x8022BCD4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8022BCD8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8022BCDC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8022BCE0: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    // 0x8022BCE4: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x8022BCE8: addiu       $t1, $t0, 0x44C
    ctx->r9 = ADD32(ctx->r8, 0X44C);
    // 0x8022BCEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8022BCF0: bne         $v1, $t1, L_8022BD00
    if (ctx->r3 != ctx->r9) {
        // 0x8022BCF4: sh          $a2, 0x94($v0)
        MEM_H(0X94, ctx->r2) = ctx->r6;
            goto L_8022BD00;
    }
    // 0x8022BCF4: sh          $a2, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r6;
    // 0x8022BCF8: b           L_8022BD08
    // 0x8022BCFC: sb          $zero, 0x96($v0)
    MEM_B(0X96, ctx->r2) = 0;
        goto L_8022BD08;
    // 0x8022BCFC: sb          $zero, 0x96($v0)
    MEM_B(0X96, ctx->r2) = 0;
L_8022BD00:
    // 0x8022BD00: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022BD04: sb          $t2, 0x96($v0)
    MEM_B(0X96, ctx->r2) = ctx->r10;
L_8022BD08:
    // 0x8022BD08: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8022BD0C: sb          $t3, 0x97($a0)
    MEM_B(0X97, ctx->r4) = ctx->r11;
    // 0x8022BD10: b           L_8022BD18
    // 0x8022BD14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022BD18;
    // 0x8022BD14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8022BD18:
    // 0x8022BD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022BD1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8022BD20: jr          $ra
    // 0x8022BD24: nop

    return;
    // 0x8022BD24: nop

;}
RECOMP_FUNC void M10_FUN_8022bd28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BD28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022BD2C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8022BD30: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    // 0x8022BD34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022BD38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022BD3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022BD40: beq         $v0, $at, L_8022BD84
    if (ctx->r2 == ctx->r1) {
        // 0x8022BD44: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8022BD84;
    }
    // 0x8022BD44: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8022BD48: beq         $v0, $at, L_8022BD84
    if (ctx->r2 == ctx->r1) {
        // 0x8022BD4C: addiu       $t6, $v1, 0x7E8
        ctx->r14 = ADD32(ctx->r3, 0X7E8);
            goto L_8022BD84;
    }
    // 0x8022BD4C: addiu       $t6, $v1, 0x7E8
    ctx->r14 = ADD32(ctx->r3, 0X7E8);
    // 0x8022BD50: bnel        $a0, $t6, L_8022BD88
    if (ctx->r4 != ctx->r14) {
        // 0x8022BD54: lbu         $v0, 0xA6($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0XA6);
            goto L_8022BD88;
    }
    goto skip_0;
    // 0x8022BD54: lbu         $v0, 0xA6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA6);
    skip_0:
    // 0x8022BD58: lbu         $v0, 0x1D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1D);
    // 0x8022BD5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022BD60: bne         $v0, $at, L_8022BD70
    if (ctx->r2 != ctx->r1) {
        // 0x8022BD64: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_8022BD70;
    }
    // 0x8022BD64: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BD68: b           L_8022BD84
    // 0x8022BD6C: lwc1        $f0, -0x6C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C4);
        goto L_8022BD84;
    // 0x8022BD6C: lwc1        $f0, -0x6C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C4);
L_8022BD70:
    // 0x8022BD70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022BD74: bne         $v0, $at, L_8022BD84
    if (ctx->r2 != ctx->r1) {
        // 0x8022BD78: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8022BD84;
    }
    // 0x8022BD78: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8022BD7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022BD80: nop

L_8022BD84:
    // 0x8022BD84: lbu         $v0, 0xA6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA6);
L_8022BD88:
    // 0x8022BD88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022BD8C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BD90: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8022BD94: beq         $t7, $zero, L_8022BDAC
    if (ctx->r15 == 0) {
        // 0x8022BD98: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_8022BDAC;
    }
    // 0x8022BD98: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8022BD9C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8022BDA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022BDA4: b           L_8022BDBC
    // 0x8022BDA8: ldc1        $f2, -0x6C0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6C0);
        goto L_8022BDBC;
    // 0x8022BDA8: ldc1        $f2, -0x6C0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6C0);
L_8022BDAC:
    // 0x8022BDAC: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8022BDB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022BDB4: nop

    // 0x8022BDB8: mov.d       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.d = ctx->f16.d;
L_8022BDBC:
    // 0x8022BDBC: beq         $t8, $zero, L_8022BDCC
    if (ctx->r24 == 0) {
        // 0x8022BDC0: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_8022BDCC;
    }
    // 0x8022BDC0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BDC4: b           L_8022BDD0
    // 0x8022BDC8: ldc1        $f12, -0x6B8($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X6B8);
        goto L_8022BDD0;
    // 0x8022BDC8: ldc1        $f12, -0x6B8($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X6B8);
L_8022BDCC:
    // 0x8022BDCC: mov.d       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.d = ctx->f16.d;
L_8022BDD0:
    // 0x8022BDD0: lhu         $t9, 0x9E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X9E);
    // 0x8022BDD4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BDD8: beql        $t9, $zero, L_8022BDEC
    if (ctx->r25 == 0) {
        // 0x8022BDDC: mov.d       $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.d = ctx->f16.d;
            goto L_8022BDEC;
    }
    goto skip_1;
    // 0x8022BDDC: mov.d       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.d = ctx->f16.d;
    skip_1:
    // 0x8022BDE0: b           L_8022BDEC
    // 0x8022BDE4: ldc1        $f14, -0x6B0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X6B0);
        goto L_8022BDEC;
    // 0x8022BDE4: ldc1        $f14, -0x6B0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X6B0);
    // 0x8022BDE8: mov.d       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.d = ctx->f16.d;
L_8022BDEC:
    // 0x8022BDEC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8022BDF0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022BDF4: lhu         $t0, 0x58($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X58);
    // 0x8022BDF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022BDFC: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x8022BE00: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8022BE04: sub.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d - ctx->f2.d;
    // 0x8022BE08: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022BE0C: bgez        $t0, L_8022BE20
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8022BE10: sub.d       $f10, $f8, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d - ctx->f14.d;
            goto L_8022BE20;
    }
    // 0x8022BE10: sub.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d - ctx->f14.d;
    // 0x8022BE14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022BE18: nop

    // 0x8022BE1C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8022BE20:
    // 0x8022BE20: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8022BE24: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022BE28: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022BE2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022BE30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022BE34: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022BE38: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8022BE3C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8022BE40: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x8022BE44: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8022BE48: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022BE4C: nop

    // 0x8022BE50: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022BE54: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022BE58: nop

    // 0x8022BE5C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022BE60: beql        $t2, $zero, L_8022BEB4
    if (ctx->r10 == 0) {
        // 0x8022BE64: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_8022BEB4;
    }
    goto skip_2;
    // 0x8022BE64: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x8022BE68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022BE6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022BE70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022BE74: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x8022BE78: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022BE7C: nop

    // 0x8022BE80: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022BE84: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022BE88: nop

    // 0x8022BE8C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022BE90: bne         $t2, $zero, L_8022BEA8
    if (ctx->r10 != 0) {
        // 0x8022BE94: nop
    
            goto L_8022BEA8;
    }
    // 0x8022BE94: nop

    // 0x8022BE98: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8022BE9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022BEA0: b           L_8022BEC0
    // 0x8022BEA4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8022BEC0;
    // 0x8022BEA4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8022BEA8:
    // 0x8022BEA8: b           L_8022BEC0
    // 0x8022BEAC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8022BEC0;
    // 0x8022BEAC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8022BEB0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_8022BEB4:
    // 0x8022BEB4: nop

    // 0x8022BEB8: bltz        $t2, L_8022BEA8
    if (SIGNED(ctx->r10) < 0) {
        // 0x8022BEBC: nop
    
            goto L_8022BEA8;
    }
    // 0x8022BEBC: nop

L_8022BEC0:
    // 0x8022BEC0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8022BEC4: jr          $ra
    // 0x8022BEC8: sh          $t2, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r10;
    return;
    // 0x8022BEC8: sh          $t2, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r10;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022becc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022becc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022BECC: lbu         $v0, 0xA6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA6);
    // 0x8022BED0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022BED4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BED8: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x8022BEDC: beq         $t6, $zero, L_8022BEF4
    if (ctx->r14 == 0) {
        // 0x8022BEE0: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_8022BEF4;
    }
    // 0x8022BEE0: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8022BEE4: mtc1        $zero, $f15
    ctx->f_odd[(15 - 1) * 2] = 0;
    // 0x8022BEE8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8022BEEC: b           L_8022BF04
    // 0x8022BEF0: ldc1        $f0, -0x6A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6A8);
        goto L_8022BF04;
    // 0x8022BEF0: ldc1        $f0, -0x6A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6A8);
L_8022BEF4:
    // 0x8022BEF4: mtc1        $zero, $f15
    ctx->f_odd[(15 - 1) * 2] = 0;
    // 0x8022BEF8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8022BEFC: nop

    // 0x8022BF00: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
L_8022BF04:
    // 0x8022BF04: beq         $t7, $zero, L_8022BF14
    if (ctx->r15 == 0) {
        // 0x8022BF08: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_8022BF14;
    }
    // 0x8022BF08: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BF0C: b           L_8022BF18
    // 0x8022BF10: ldc1        $f2, -0x6A0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6A0);
        goto L_8022BF18;
    // 0x8022BF10: ldc1        $f2, -0x6A0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6A0);
L_8022BF14:
    // 0x8022BF14: mov.d       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.d = ctx->f14.d;
L_8022BF18:
    // 0x8022BF18: lhu         $t8, 0x9E($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X9E);
    // 0x8022BF1C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022BF20: beql        $t8, $zero, L_8022BF34
    if (ctx->r24 == 0) {
        // 0x8022BF24: mov.d       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.d = ctx->f14.d;
            goto L_8022BF34;
    }
    goto skip_0;
    // 0x8022BF24: mov.d       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.d = ctx->f14.d;
    skip_0:
    // 0x8022BF28: b           L_8022BF34
    // 0x8022BF2C: ldc1        $f12, -0x698($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X698);
        goto L_8022BF34;
    // 0x8022BF2C: ldc1        $f12, -0x698($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X698);
    // 0x8022BF30: mov.d       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.d = ctx->f14.d;
L_8022BF34:
    // 0x8022BF34: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8022BF38: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022BF3C: lhu         $t9, 0x5A($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X5A);
    // 0x8022BF40: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022BF44: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8022BF48: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8022BF4C: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x8022BF50: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8022BF54: bgez        $t9, L_8022BF68
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8022BF58: sub.d       $f10, $f8, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d - ctx->f12.d;
            goto L_8022BF68;
    }
    // 0x8022BF58: sub.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d - ctx->f12.d;
    // 0x8022BF5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022BF60: nop

    // 0x8022BF64: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8022BF68:
    // 0x8022BF68: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8022BF6C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022BF70: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x8022BF74: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022BF78: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022BF7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022BF80: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022BF84: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x8022BF88: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8022BF8C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8022BF90: nop

    // 0x8022BF94: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022BF98: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8022BF9C: nop

    // 0x8022BFA0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8022BFA4: beql        $t1, $zero, L_8022BFF8
    if (ctx->r9 == 0) {
        // 0x8022BFA8: mfc1        $t1, $f18
        ctx->r9 = (int32_t)ctx->f18.u32l;
            goto L_8022BFF8;
    }
    goto skip_1;
    // 0x8022BFA8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x8022BFAC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022BFB0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022BFB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022BFB8: sub.d       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f4.d - ctx->f18.d;
    // 0x8022BFBC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8022BFC0: nop

    // 0x8022BFC4: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022BFC8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8022BFCC: nop

    // 0x8022BFD0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8022BFD4: bne         $t1, $zero, L_8022BFEC
    if (ctx->r9 != 0) {
        // 0x8022BFD8: nop
    
            goto L_8022BFEC;
    }
    // 0x8022BFD8: nop

    // 0x8022BFDC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8022BFE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022BFE4: b           L_8022C004
    // 0x8022BFE8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8022C004;
    // 0x8022BFE8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8022BFEC:
    // 0x8022BFEC: b           L_8022C004
    // 0x8022BFF0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8022C004;
    // 0x8022BFF0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8022BFF4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
L_8022BFF8:
    // 0x8022BFF8: nop

    // 0x8022BFFC: bltz        $t1, L_8022BFEC
    if (SIGNED(ctx->r9) < 0) {
        // 0x8022C000: nop
    
            goto L_8022BFEC;
    }
    // 0x8022C000: nop

L_8022C004:
    // 0x8022C004: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8022C008: jr          $ra
    // 0x8022C00C: sh          $t1, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r9;
    return;
    // 0x8022C00C: sh          $t1, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022c010(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022c010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C010: lbu         $v0, 0xA6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA6);
    // 0x8022C014: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022C018: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022C01C: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x8022C020: beq         $t6, $zero, L_8022C03C
    if (ctx->r14 == 0) {
        // 0x8022C024: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_8022C03C;
    }
    // 0x8022C024: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x8022C028: ldc1        $f14, -0x690($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X690);
    // 0x8022C02C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8022C030: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022C034: b           L_8022C050
    // 0x8022C038: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
        goto L_8022C050;
    // 0x8022C038: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
L_8022C03C:
    // 0x8022C03C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8022C040: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022C044: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022C048: ldc1        $f14, -0x688($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X688);
    // 0x8022C04C: mov.d       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = ctx->f16.d;
L_8022C050:
    // 0x8022C050: beq         $t7, $zero, L_8022C060
    if (ctx->r15 == 0) {
        // 0x8022C054: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_8022C060;
    }
    // 0x8022C054: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8022C058: b           L_8022C064
    // 0x8022C05C: mov.d       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.d = ctx->f14.d;
        goto L_8022C064;
    // 0x8022C05C: mov.d       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.d = ctx->f14.d;
L_8022C060:
    // 0x8022C060: mov.d       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.d = ctx->f16.d;
L_8022C064:
    // 0x8022C064: lhu         $t8, 0xA0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XA0);
    // 0x8022C068: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022C06C: blez        $t8, L_8022C07C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8022C070: sub.d       $f6, $f4, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d - ctx->f2.d;
            goto L_8022C07C;
    }
    // 0x8022C070: sub.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d - ctx->f2.d;
    // 0x8022C074: b           L_8022C080
    // 0x8022C078: mov.d       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.d = ctx->f14.d;
        goto L_8022C080;
    // 0x8022C078: mov.d       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.d = ctx->f14.d;
L_8022C07C:
    // 0x8022C07C: mov.d       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.d = ctx->f16.d;
L_8022C080:
    // 0x8022C080: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x8022C084: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8022C088: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x8022C08C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8022C090: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8022C094: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8022C098: jr          $ra
    // 0x8022C09C: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8022C09C: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022c0a0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022c0a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C0A0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022C0A4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8022C0A8: lbu         $v0, 0x1030($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1030);
    // 0x8022C0AC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022C0B0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
    // 0x8022C0B4: bne         $v0, $zero, L_8022C0C8
    if (ctx->r2 != 0) {
        // 0x8022C0B8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8022C0C8;
    }
    // 0x8022C0B8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8022C0BC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022C0C0: b           L_8022C0C8
    // 0x8022C0C4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8022C0C8;
    // 0x8022C0C4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8022C0C8:
    // 0x8022C0C8: lbu         $v0, 0x2D8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D8);
    // 0x8022C0CC: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x8022C0D0: beql        $a3, $v0, L_8022C1A0
    if (ctx->r7 == ctx->r2) {
        // 0x8022C0D4: lh          $t2, 0x6($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X6);
            goto L_8022C1A0;
    }
    goto skip_0;
    // 0x8022C0D4: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x8022C0D8: beq         $v0, $at, L_8022C19C
    if (ctx->r2 == ctx->r1) {
        // 0x8022C0DC: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_8022C19C;
    }
    // 0x8022C0DC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8022C0E0: beq         $t0, $v0, L_8022C19C
    if (ctx->r8 == ctx->r2) {
        // 0x8022C0E4: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8022C19C;
    }
    // 0x8022C0E4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8022C0E8: beq         $t1, $v0, L_8022C104
    if (ctx->r9 == ctx->r2) {
        // 0x8022C0EC: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_8022C104;
    }
    // 0x8022C0EC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8022C0F0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8022C0F4: bne         $at, $zero, L_8022C114
    if (ctx->r1 != 0) {
        // 0x8022C0F8: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_8022C114;
    }
    // 0x8022C0F8: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8022C0FC: beql        $at, $zero, L_8022C118
    if (ctx->r1 == 0) {
        // 0x8022C100: lh          $a1, 0x6($v1)
        ctx->r5 = MEM_H(ctx->r3, 0X6);
            goto L_8022C118;
    }
    goto skip_1;
    // 0x8022C100: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
    skip_1:
L_8022C104:
    // 0x8022C104: lbu         $t6, 0x2DA($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2DA);
    // 0x8022C108: bnel        $t6, $zero, L_8022C118
    if (ctx->r14 != 0) {
        // 0x8022C10C: lh          $a1, 0x6($v1)
        ctx->r5 = MEM_H(ctx->r3, 0X6);
            goto L_8022C118;
    }
    goto skip_2;
    // 0x8022C10C: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
    skip_2:
    // 0x8022C110: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
L_8022C114:
    // 0x8022C114: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
L_8022C118:
    // 0x8022C118: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x8022C11C: addiu       $t8, $a2, 0x44C
    ctx->r24 = ADD32(ctx->r6, 0X44C);
    // 0x8022C120: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022C124: sh          $a1, 0x300($v1)
    MEM_H(0X300, ctx->r3) = ctx->r5;
    // 0x8022C128: bne         $at, $zero, L_8022C138
    if (ctx->r1 != 0) {
        // 0x8022C12C: sh          $t7, 0x302($v1)
        MEM_H(0X302, ctx->r3) = ctx->r15;
            goto L_8022C138;
    }
    // 0x8022C12C: sh          $t7, 0x302($v1)
    MEM_H(0X302, ctx->r3) = ctx->r15;
    // 0x8022C130: b           L_8022C13C
    // 0x8022C134: sh          $a0, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r4;
        goto L_8022C13C;
    // 0x8022C134: sh          $a0, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r4;
L_8022C138:
    // 0x8022C138: sh          $a1, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r5;
L_8022C13C:
    // 0x8022C13C: lbu         $v0, 0x2D8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D8);
    // 0x8022C140: beq         $t1, $v0, L_8022C158
    if (ctx->r9 == ctx->r2) {
        // 0x8022C144: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_8022C158;
    }
    // 0x8022C144: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8022C148: bne         $at, $zero, L_8022C1AC
    if (ctx->r1 != 0) {
        // 0x8022C14C: slti        $at, $v0, 0x9
        ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
            goto L_8022C1AC;
    }
    // 0x8022C14C: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8022C150: beq         $at, $zero, L_8022C1AC
    if (ctx->r1 == 0) {
        // 0x8022C154: nop
    
            goto L_8022C1AC;
    }
    // 0x8022C154: nop

L_8022C158:
    // 0x8022C158: beql        $v1, $t8, L_8022C178
    if (ctx->r3 == ctx->r24) {
        // 0x8022C15C: lw          $t9, 0x2D4($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X2D4);
            goto L_8022C178;
    }
    goto skip_3;
    // 0x8022C15C: lw          $t9, 0x2D4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2D4);
    skip_3:
    // 0x8022C160: lhu         $v0, 0x2C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2C);
    // 0x8022C164: beql        $t0, $v0, L_8022C178
    if (ctx->r8 == ctx->r2) {
        // 0x8022C168: lw          $t9, 0x2D4($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X2D4);
            goto L_8022C178;
    }
    goto skip_4;
    // 0x8022C168: lw          $t9, 0x2D4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2D4);
    skip_4:
    // 0x8022C16C: bne         $a3, $v0, L_8022C1AC
    if (ctx->r7 != ctx->r2) {
        // 0x8022C170: nop
    
            goto L_8022C1AC;
    }
    // 0x8022C170: nop

    // 0x8022C174: lw          $t9, 0x2D4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2D4);
L_8022C178:
    // 0x8022C178: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
    // 0x8022C17C: lbu         $a0, 0x6($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X6);
    // 0x8022C180: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022C184: bne         $at, $zero, L_8022C194
    if (ctx->r1 != 0) {
        // 0x8022C188: nop
    
            goto L_8022C194;
    }
    // 0x8022C188: nop

    // 0x8022C18C: jr          $ra
    // 0x8022C190: sh          $a0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r4;
    return;
    // 0x8022C190: sh          $a0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r4;
L_8022C194:
    // 0x8022C194: jr          $ra
    // 0x8022C198: sh          $v0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r2;
    return;
    // 0x8022C198: sh          $v0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r2;
L_8022C19C:
    // 0x8022C19C: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
L_8022C1A0:
    // 0x8022C1A0: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8022C1A4: sh          $t3, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r11;
    // 0x8022C1A8: sh          $t2, 0x300($v1)
    MEM_H(0X300, ctx->r3) = ctx->r10;
L_8022C1AC:
    // 0x8022C1AC: jr          $ra
    // 0x8022C1B0: nop

    return;
    // 0x8022C1B0: nop

;}
RECOMP_FUNC void M10_FUN_8022c1b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C1B4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022C1B8: lbu         $v0, -0x33E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022c1bc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022c1bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C1BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8022C1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022C1C4: bne         $v0, $zero, L_8022C1D8
    if (ctx->r2 != 0) {
        // 0x8022C1C8: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8022C1D8;
    }
    // 0x8022C1C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8022C1CC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022C1D0: b           L_8022C1E0
    // 0x8022C1D4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8022C1E0;
    // 0x8022C1D4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8022C1D8:
    // 0x8022C1D8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022C1DC: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8022C1E0:
    // 0x8022C1E0: bne         $v0, $zero, L_8022C1F4
    if (ctx->r2 != 0) {
        // 0x8022C1E4: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_8022C1F4;
    }
    // 0x8022C1E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022C1E8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022C1EC: b           L_8022C1F8
    // 0x8022C1F0: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
        goto L_8022C1F8;
    // 0x8022C1F0: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_8022C1F4:
    // 0x8022C1F4: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8022C1F8:
    // 0x8022C1F8: lbu         $t6, 0x2D8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2D8);
    // 0x8022C1FC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8022C200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022C204: bne         $t6, $at, L_8022C304
    if (ctx->r14 != ctx->r1) {
        // 0x8022C208: nop
    
            goto L_8022C304;
    }
    // 0x8022C208: nop

    // 0x8022C20C: lbu         $t7, 0x2DA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2DA);
    // 0x8022C210: beq         $t7, $zero, L_8022C304
    if (ctx->r15 == 0) {
        // 0x8022C214: nop
    
            goto L_8022C304;
    }
    // 0x8022C214: nop

    // 0x8022C218: lbu         $t8, 0x2FA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2FA);
    // 0x8022C21C: beq         $t8, $zero, L_8022C304
    if (ctx->r24 == 0) {
        // 0x8022C220: nop
    
            goto L_8022C304;
    }
    // 0x8022C220: nop

    // 0x8022C224: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x8022C228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022C22C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8022C230: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x8022C234: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x8022C238: bnel        $t1, $at, L_8022C278
    if (ctx->r9 != ctx->r1) {
        // 0x8022C23C: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_8022C278;
    }
    goto skip_0;
    // 0x8022C23C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
    // 0x8022C240: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8022C244: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8022C248: jal         0x80376300
    // 0x8022C24C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80376300)(rdram, ctx);
        goto after_0;
    // 0x8022C24C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8022C250: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8022C254: beq         $v0, $zero, L_8022C268
    if (ctx->r2 == 0) {
        // 0x8022C258: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8022C268;
    }
    // 0x8022C258: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8022C25C: addiu       $t2, $zero, 0x51
    ctx->r10 = ADD32(0, 0X51);
    // 0x8022C260: b           L_8022C2A0
    // 0x8022C264: sb          $t2, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r10;
        goto L_8022C2A0;
    // 0x8022C264: sb          $t2, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r10;
L_8022C268:
    // 0x8022C268: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x8022C26C: b           L_8022C2A0
    // 0x8022C270: sb          $t3, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r11;
        goto L_8022C2A0;
    // 0x8022C270: sb          $t3, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r11;
    // 0x8022C274: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_8022C278:
    // 0x8022C278: jal         0x80376300
    // 0x8022C27C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80376300)(rdram, ctx);
        goto after_1;
    // 0x8022C27C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8022C280: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8022C284: beq         $v0, $zero, L_8022C298
    if (ctx->r2 == 0) {
        // 0x8022C288: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8022C298;
    }
    // 0x8022C288: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8022C28C: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8022C290: b           L_8022C2A0
    // 0x8022C294: sb          $t4, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r12;
        goto L_8022C2A0;
    // 0x8022C294: sb          $t4, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r12;
L_8022C298:
    // 0x8022C298: addiu       $t5, $zero, 0x51
    ctx->r13 = ADD32(0, 0X51);
    // 0x8022C29C: sb          $t5, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r13;
L_8022C2A0:
    // 0x8022C2A0: lbu         $t6, 0x2D9($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2D9);
    // 0x8022C2A4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8022C2A8: addiu       $t8, $t8, 0x42A0
    ctx->r24 = ADD32(ctx->r24, 0X42A0);
    // 0x8022C2AC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8022C2B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8022C2B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8022C2B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8022C2BC: sw          $t9, 0x2D4($v1)
    MEM_W(0X2D4, ctx->r3) = ctx->r25;
    // 0x8022C2C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8022C2C4: jal         0x8022C0A0
    // 0x8022C2C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8022C0A0)(rdram, ctx);
        goto after_2;
    // 0x8022C2C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8022C2CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8022C2D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8022C2D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022C2D8: lw          $t0, 0x2D4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2D4);
    // 0x8022C2DC: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x8022C2E0: sb          $t1, 0x2F0($a1)
    MEM_B(0X2F0, ctx->r5) = ctx->r9;
    // 0x8022C2E4: sb          $t3, 0x2DF($v1)
    MEM_B(0X2DF, ctx->r3) = ctx->r11;
    // 0x8022C2E8: sb          $t3, 0x2DF($a1)
    MEM_B(0X2DF, ctx->r5) = ctx->r11;
    // 0x8022C2EC: sb          $zero, 0x2DA($v1)
    MEM_B(0X2DA, ctx->r3) = 0;
    // 0x8022C2F0: sb          $zero, 0x2FA($a1)
    MEM_B(0X2FA, ctx->r5) = 0;
    // 0x8022C2F4: jal         0x80232E94
    // 0x8022C2F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80232E94)(rdram, ctx);
        goto after_3;
    // 0x8022C2F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8022C2FC: b           L_8022C304
    // 0x8022C300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022C304;
    // 0x8022C300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8022C304:
    // 0x8022C304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022C308: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8022C30C: jr          $ra
    // 0x8022C310: nop

    return;
    // 0x8022C310: nop

;}
RECOMP_FUNC void M10_FUN_8022c314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C314: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022C318: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8022C31C: addiu       $v0, $a0, -0x44C
    ctx->r2 = ADD32(ctx->r4, -0X44C);
    // 0x8022C320: bne         $v0, $a1, L_8022C334
    if (ctx->r2 != ctx->r5) {
        // 0x8022C324: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8022C334;
    }
    // 0x8022C324: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022C328: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022C32C: b           L_8022C338
    // 0x8022C330: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
        goto L_8022C338;
    // 0x8022C330: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8022C334:
    // 0x8022C334: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8022C338:
    // 0x8022C338: bne         $v0, $a1, L_8022C348
    if (ctx->r2 != ctx->r5) {
        // 0x8022C33C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8022C348;
    }
    // 0x8022C33C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022C340: b           L_8022C34C
    // 0x8022C344: lw          $v0, 0x444($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X444);
        goto L_8022C34C;
    // 0x8022C344: lw          $v0, 0x444($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X444);
L_8022C348:
    // 0x8022C348: lw          $v0, 0x448($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X448);
L_8022C34C:
    // 0x8022C34C: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x8022C350: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x8022C354: lhu         $t7, 0x94($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X94);
    // 0x8022C358: lhu         $t9, 0x90($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X90);
    // 0x8022C35C: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x8022C360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8022C364: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x8022C368: xor         $t4, $a1, $t3
    ctx->r12 = ctx->r5 ^ ctx->r11;
    // 0x8022C36C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8022C370: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8022C374: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8022C378: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8022C37C: beql        $t5, $zero, L_8022C390
    if (ctx->r13 == 0) {
        // 0x8022C380: lhu         $t6, 0x8A($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X8A);
            goto L_8022C390;
    }
    goto skip_0;
    // 0x8022C380: lhu         $t6, 0x8A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8A);
    skip_0:
    // 0x8022C384: b           L_8022C3D8
    // 0x8022C388: lh          $v1, 0x8C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8C);
        goto L_8022C3D8;
    // 0x8022C388: lh          $v1, 0x8C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8C);
    // 0x8022C38C: lhu         $t6, 0x8A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8A);
L_8022C390:
    // 0x8022C390: lhu         $t7, 0x92($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X92);
    // 0x8022C394: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
    // 0x8022C398: lhu         $t9, 0x94($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X94);
    // 0x8022C39C: lhu         $t2, 0x90($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X90);
    // 0x8022C3A0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8022C3A4: sll         $t4, $t0, 9
    ctx->r12 = S32(ctx->r8 << 9);
    // 0x8022C3A8: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x8022C3AC: xor         $t6, $a1, $t5
    ctx->r14 = ctx->r5 ^ ctx->r13;
    // 0x8022C3B0: subu        $t1, $t8, $t9
    ctx->r9 = SUB32(ctx->r24, ctx->r25);
    // 0x8022C3B4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8022C3B8: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8022C3BC: beql        $t3, $t6, L_8022C3D0
    if (ctx->r11 == ctx->r14) {
        // 0x8022C3C0: lhu         $a1, 0x8A($v1)
        ctx->r5 = MEM_HU(ctx->r3, 0X8A);
            goto L_8022C3D0;
    }
    goto skip_1;
    // 0x8022C3C0: lhu         $a1, 0x8A($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X8A);
    skip_1:
    // 0x8022C3C4: b           L_8022C3D0
    // 0x8022C3C8: lhu         $a1, 0x8C($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X8C);
        goto L_8022C3D0;
    // 0x8022C3C8: lhu         $a1, 0x8C($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X8C);
    // 0x8022C3CC: lhu         $a1, 0x8A($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X8A);
L_8022C3D0:
    // 0x8022C3D0: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8022C3D4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8022C3D8:
    // 0x8022C3D8: blezl       $v1, L_8022C408
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8022C3DC: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8022C408;
    }
    goto skip_2;
    // 0x8022C3DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x8022C3E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022C3E4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8022C3E8: mflo        $t8
    ctx->r24 = lo;
    // 0x8022C3EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022C3F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8022C3F4: nop

    // 0x8022C3F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022C3FC: b           L_8022C410
    // 0x8022C400: swc1        $f6, 0x308($a0)
    MEM_W(0X308, ctx->r4) = ctx->f6.u32l;
        goto L_8022C410;
    // 0x8022C400: swc1        $f6, 0x308($a0)
    MEM_W(0X308, ctx->r4) = ctx->f6.u32l;
    // 0x8022C404: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8022C408:
    // 0x8022C408: nop

    // 0x8022C40C: swc1        $f8, 0x308($a0)
    MEM_W(0X308, ctx->r4) = ctx->f8.u32l;
L_8022C410:
    // 0x8022C410: lbu         $t1, 0x75($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X75);
    // 0x8022C414: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022C418: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022C41C: bnel        $t1, $at, L_8022C444
    if (ctx->r9 != ctx->r1) {
        // 0x8022C420: lwc1        $f10, 0x308($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X308);
            goto L_8022C444;
    }
    goto skip_3;
    // 0x8022C420: lwc1        $f10, 0x308($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X308);
    skip_3:
    // 0x8022C424: lwc1        $f10, 0x308($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X308);
    // 0x8022C428: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022C42C: ldc1        $f18, -0x680($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X680);
    // 0x8022C430: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8022C434: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8022C438: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8022C43C: swc1        $f6, 0x308($a0)
    MEM_W(0X308, ctx->r4) = ctx->f6.u32l;
    // 0x8022C440: lwc1        $f10, 0x308($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X308);
L_8022C444:
    // 0x8022C444: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8022C448: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022C44C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8022C450: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8022C454: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8022C458: nop

    // 0x8022C45C: bc1f        L_8022C470
    if (!c1cs) {
        // 0x8022C460: nop
    
            goto L_8022C470;
    }
    // 0x8022C460: nop

    // 0x8022C464: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8022C468: nop

    // 0x8022C46C: swc1        $f18, 0x308($a0)
    MEM_W(0X308, ctx->r4) = ctx->f18.u32l;
L_8022C470:
    // 0x8022C470: jr          $ra
    // 0x8022C474: nop

    return;
    // 0x8022C474: nop

;}
RECOMP_FUNC void M10_FUN_8022c478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C478: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022C47C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8022C480: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8022C484: addiu       $v0, $a0, -0x44C
    ctx->r2 = ADD32(ctx->r4, -0X44C);
    // 0x8022C488: sb          $zero, 0x38B($a0)
    MEM_B(0X38B, ctx->r4) = 0;
    // 0x8022C48C: sb          $zero, 0x388($a0)
    MEM_B(0X388, ctx->r4) = 0;
    // 0x8022C490: sb          $zero, 0x385($a0)
    MEM_B(0X385, ctx->r4) = 0;
    // 0x8022C494: addiu       $t1, $t1, 0x3CE0
    ctx->r9 = ADD32(ctx->r9, 0X3CE0);
    // 0x8022C498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8022C49C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
L_8022C4A0:
    // 0x8022C4A0: bne         $v0, $a3, L_8022C4D4
    if (ctx->r2 != ctx->r7) {
        // 0x8022C4A4: slti        $at, $a1, 0xE
        ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
            goto L_8022C4D4;
    }
    // 0x8022C4A4: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x8022C4A8: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C4AC: mflo        $v1
    ctx->r3 = lo;
    // 0x8022C4B0: addu        $t6, $t1, $v1
    ctx->r14 = ADD32(ctx->r9, ctx->r3);
    // 0x8022C4B4: lwl         $t8, 0x0($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X0);
    // 0x8022C4B8: lwr         $t8, 0x3($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X3);
    // 0x8022C4BC: addu        $a2, $a0, $v1
    ctx->r6 = ADD32(ctx->r4, ctx->r3);
    // 0x8022C4C0: swl         $t8, 0xA8($a2)
    do_swl(rdram, 0XA8, ctx->r6, ctx->r24);
    // 0x8022C4C4: swr         $t8, 0xAB($a2)
    do_swr(rdram, 0XAB, ctx->r6, ctx->r24);
    // 0x8022C4C8: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x8022C4CC: b           L_8022C4FC
    // 0x8022C4D0: sh          $t8, 0xAC($a2)
    MEM_H(0XAC, ctx->r6) = ctx->r24;
        goto L_8022C4FC;
    // 0x8022C4D0: sh          $t8, 0xAC($a2)
    MEM_H(0XAC, ctx->r6) = ctx->r24;
L_8022C4D4:
    // 0x8022C4D4: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C4D8: mflo        $v1
    ctx->r3 = lo;
    // 0x8022C4DC: addu        $t9, $t1, $v1
    ctx->r25 = ADD32(ctx->r9, ctx->r3);
    // 0x8022C4E0: lwl         $t3, 0x204($t9)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r25, 0X204);
    // 0x8022C4E4: lwr         $t3, 0x207($t9)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r25, 0X207);
    // 0x8022C4E8: addu        $a2, $a0, $v1
    ctx->r6 = ADD32(ctx->r4, ctx->r3);
    // 0x8022C4EC: swl         $t3, 0xA8($a2)
    do_swl(rdram, 0XA8, ctx->r6, ctx->r11);
    // 0x8022C4F0: swr         $t3, 0xAB($a2)
    do_swr(rdram, 0XAB, ctx->r6, ctx->r11);
    // 0x8022C4F4: lhu         $t3, 0x208($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X208);
    // 0x8022C4F8: sh          $t3, 0xAC($a2)
    MEM_H(0XAC, ctx->r6) = ctx->r11;
L_8022C4FC:
    // 0x8022C4FC: lbu         $t4, 0xA8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XA8);
    // 0x8022C500: sb          $zero, 0xAC($a2)
    MEM_B(0XAC, ctx->r6) = 0;
    // 0x8022C504: beql        $t4, $zero, L_8022C594
    if (ctx->r12 == 0) {
        // 0x8022C508: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8022C594;
    }
    goto skip_0;
    // 0x8022C508: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x8022C50C: beq         $at, $zero, L_8022C524
    if (ctx->r1 == 0) {
        // 0x8022C510: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8022C524;
    }
    // 0x8022C510: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8022C514: lbu         $t5, 0x385($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X385);
    // 0x8022C518: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8022C51C: b           L_8022C590
    // 0x8022C520: sb          $t6, 0x385($a0)
    MEM_B(0X385, ctx->r4) = ctx->r14;
        goto L_8022C590;
    // 0x8022C520: sb          $t6, 0x385($a0)
    MEM_B(0X385, ctx->r4) = ctx->r14;
L_8022C524:
    // 0x8022C524: slti        $at, $v1, 0x22
    ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
    // 0x8022C528: beql        $at, $zero, L_8022C544
    if (ctx->r1 == 0) {
        // 0x8022C52C: slti        $at, $v1, 0x39
        ctx->r1 = SIGNED(ctx->r3) < 0X39 ? 1 : 0;
            goto L_8022C544;
    }
    goto skip_1;
    // 0x8022C52C: slti        $at, $v1, 0x39
    ctx->r1 = SIGNED(ctx->r3) < 0X39 ? 1 : 0;
    skip_1:
    // 0x8022C530: lbu         $t7, 0x388($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X388);
    // 0x8022C534: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8022C538: b           L_8022C590
    // 0x8022C53C: sb          $t8, 0x388($a0)
    MEM_B(0X388, ctx->r4) = ctx->r24;
        goto L_8022C590;
    // 0x8022C53C: sb          $t8, 0x388($a0)
    MEM_B(0X388, ctx->r4) = ctx->r24;
    // 0x8022C540: slti        $at, $v1, 0x39
    ctx->r1 = SIGNED(ctx->r3) < 0X39 ? 1 : 0;
L_8022C544:
    // 0x8022C544: beql        $at, $zero, L_8022C560
    if (ctx->r1 == 0) {
        // 0x8022C548: slti        $at, $v1, 0x3E
        ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
            goto L_8022C560;
    }
    goto skip_2;
    // 0x8022C548: slti        $at, $v1, 0x3E
    ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
    skip_2:
    // 0x8022C54C: lbu         $t9, 0x38B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X38B);
    // 0x8022C550: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8022C554: b           L_8022C590
    // 0x8022C558: sb          $t2, 0x38B($a0)
    MEM_B(0X38B, ctx->r4) = ctx->r10;
        goto L_8022C590;
    // 0x8022C558: sb          $t2, 0x38B($a0)
    MEM_B(0X38B, ctx->r4) = ctx->r10;
    // 0x8022C55C: slti        $at, $v1, 0x3E
    ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
L_8022C560:
    // 0x8022C560: beql        $at, $zero, L_8022C57C
    if (ctx->r1 == 0) {
        // 0x8022C564: slti        $at, $v1, 0x4E
        ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
            goto L_8022C57C;
    }
    goto skip_3;
    // 0x8022C564: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
    skip_3:
    // 0x8022C568: lbu         $t3, 0x38E($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X38E);
    // 0x8022C56C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8022C570: b           L_8022C590
    // 0x8022C574: sb          $t4, 0x38E($a0)
    MEM_B(0X38E, ctx->r4) = ctx->r12;
        goto L_8022C590;
    // 0x8022C574: sb          $t4, 0x38E($a0)
    MEM_B(0X38E, ctx->r4) = ctx->r12;
    // 0x8022C578: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
L_8022C57C:
    // 0x8022C57C: beql        $at, $zero, L_8022C594
    if (ctx->r1 == 0) {
        // 0x8022C580: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8022C594;
    }
    goto skip_4;
    // 0x8022C580: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
    // 0x8022C584: lbu         $t5, 0x38F($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X38F);
    // 0x8022C588: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8022C58C: sb          $t6, 0x38F($a0)
    MEM_B(0X38F, ctx->r4) = ctx->r14;
L_8022C590:
    // 0x8022C590: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8022C594:
    // 0x8022C594: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8022C598: slti        $at, $a1, 0x56
    ctx->r1 = SIGNED(ctx->r5) < 0X56 ? 1 : 0;
    // 0x8022C59C: bne         $at, $zero, L_8022C4A0
    if (ctx->r1 != 0) {
        // 0x8022C5A0: nop
    
            goto L_8022C4A0;
    }
    // 0x8022C5A0: nop

    // 0x8022C5A4: jr          $ra
    // 0x8022C5A8: nop

    return;
    // 0x8022C5A8: nop

;}
RECOMP_FUNC void M10_FUN_8022c5ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C5AC: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8022C5B0: addiu       $t6, $t6, -0x1D00
    ctx->r14 = ADD32(ctx->r14, -0X1D00);
    // 0x8022C5B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022c5b8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022c5b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C5B8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8022C5BC: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x8022C5C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8022C5C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8022C5C8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8022C5CC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8022C5D0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8022C5D4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8022C5D8: lh          $t9, 0x2C4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2C4);
    // 0x8022C5DC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8022C5E0: lh          $t2, 0x2C6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2C6);
    // 0x8022C5E4: lh          $t5, 0x2C8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2C8);
    // 0x8022C5E8: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C5EC: lh          $t8, 0x2CA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2CA);
    // 0x8022C5F0: mflo        $t0
    ctx->r8 = lo;
    // 0x8022C5F4: nop

    // 0x8022C5F8: nop

    // 0x8022C5FC: div         $zero, $t0, $a1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r5)));
    // 0x8022C600: mflo        $t1
    ctx->r9 = lo;
    // 0x8022C604: sh          $t1, 0x2B8($a0)
    MEM_H(0X2B8, ctx->r4) = ctx->r9;
    // 0x8022C608: bne         $a1, $zero, L_8022C614
    if (ctx->r5 != 0) {
        // 0x8022C60C: nop
    
            goto L_8022C614;
    }
    // 0x8022C60C: nop

    // 0x8022C610: break       7
    do_break(2149762576);
L_8022C614:
    // 0x8022C614: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022C618: bne         $a1, $at, L_8022C62C
    if (ctx->r5 != ctx->r1) {
        // 0x8022C61C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022C62C;
    }
    // 0x8022C61C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022C620: bne         $t0, $at, L_8022C62C
    if (ctx->r8 != ctx->r1) {
        // 0x8022C624: nop
    
            goto L_8022C62C;
    }
    // 0x8022C624: nop

    // 0x8022C628: break       6
    do_break(2149762600);
L_8022C62C:
    // 0x8022C62C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C630: lh          $t1, 0x2CC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2CC);
    // 0x8022C634: mflo        $t3
    ctx->r11 = lo;
    // 0x8022C638: nop

    // 0x8022C63C: nop

    // 0x8022C640: div         $zero, $t3, $a1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r5)));
    // 0x8022C644: mflo        $t4
    ctx->r12 = lo;
    // 0x8022C648: sh          $t4, 0x2BA($a0)
    MEM_H(0X2BA, ctx->r4) = ctx->r12;
    // 0x8022C64C: bne         $a1, $zero, L_8022C658
    if (ctx->r5 != 0) {
        // 0x8022C650: nop
    
            goto L_8022C658;
    }
    // 0x8022C650: nop

    // 0x8022C654: break       7
    do_break(2149762644);
L_8022C658:
    // 0x8022C658: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022C65C: bne         $a1, $at, L_8022C670
    if (ctx->r5 != ctx->r1) {
        // 0x8022C660: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022C670;
    }
    // 0x8022C660: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022C664: bne         $t3, $at, L_8022C670
    if (ctx->r11 != ctx->r1) {
        // 0x8022C668: nop
    
            goto L_8022C670;
    }
    // 0x8022C668: nop

    // 0x8022C66C: break       6
    do_break(2149762668);
L_8022C670:
    // 0x8022C670: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C674: lh          $t4, 0x2CE($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2CE);
    // 0x8022C678: mflo        $t6
    ctx->r14 = lo;
    // 0x8022C67C: nop

    // 0x8022C680: nop

    // 0x8022C684: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x8022C688: mflo        $t7
    ctx->r15 = lo;
    // 0x8022C68C: sh          $t7, 0x2BC($a0)
    MEM_H(0X2BC, ctx->r4) = ctx->r15;
    // 0x8022C690: bne         $a1, $zero, L_8022C69C
    if (ctx->r5 != 0) {
        // 0x8022C694: nop
    
            goto L_8022C69C;
    }
    // 0x8022C694: nop

    // 0x8022C698: break       7
    do_break(2149762712);
L_8022C69C:
    // 0x8022C69C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022C6A0: bne         $a1, $at, L_8022C6B4
    if (ctx->r5 != ctx->r1) {
        // 0x8022C6A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022C6B4;
    }
    // 0x8022C6A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022C6A8: bne         $t6, $at, L_8022C6B4
    if (ctx->r14 != ctx->r1) {
        // 0x8022C6AC: nop
    
            goto L_8022C6B4;
    }
    // 0x8022C6AC: nop

    // 0x8022C6B0: break       6
    do_break(2149762736);
L_8022C6B4:
    // 0x8022C6B4: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C6B8: mflo        $t9
    ctx->r25 = lo;
    // 0x8022C6BC: nop

    // 0x8022C6C0: nop

    // 0x8022C6C4: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x8022C6C8: mflo        $t0
    ctx->r8 = lo;
    // 0x8022C6CC: sh          $t0, 0x2BE($a0)
    MEM_H(0X2BE, ctx->r4) = ctx->r8;
    // 0x8022C6D0: bne         $a1, $zero, L_8022C6DC
    if (ctx->r5 != 0) {
        // 0x8022C6D4: nop
    
            goto L_8022C6DC;
    }
    // 0x8022C6D4: nop

    // 0x8022C6D8: break       7
    do_break(2149762776);
L_8022C6DC:
    // 0x8022C6DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022C6E0: bne         $a1, $at, L_8022C6F4
    if (ctx->r5 != ctx->r1) {
        // 0x8022C6E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022C6F4;
    }
    // 0x8022C6E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022C6E8: bne         $t9, $at, L_8022C6F4
    if (ctx->r25 != ctx->r1) {
        // 0x8022C6EC: nop
    
            goto L_8022C6F4;
    }
    // 0x8022C6EC: nop

    // 0x8022C6F0: break       6
    do_break(2149762800);
L_8022C6F4:
    // 0x8022C6F4: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C6F8: mflo        $t2
    ctx->r10 = lo;
    // 0x8022C6FC: nop

    // 0x8022C700: nop

    // 0x8022C704: div         $zero, $t2, $a1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r5)));
    // 0x8022C708: mflo        $t3
    ctx->r11 = lo;
    // 0x8022C70C: sh          $t3, 0x2C0($a0)
    MEM_H(0X2C0, ctx->r4) = ctx->r11;
    // 0x8022C710: bne         $a1, $zero, L_8022C71C
    if (ctx->r5 != 0) {
        // 0x8022C714: nop
    
            goto L_8022C71C;
    }
    // 0x8022C714: nop

    // 0x8022C718: break       7
    do_break(2149762840);
L_8022C71C:
    // 0x8022C71C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022C720: bne         $a1, $at, L_8022C734
    if (ctx->r5 != ctx->r1) {
        // 0x8022C724: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022C734;
    }
    // 0x8022C724: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022C728: bne         $t2, $at, L_8022C734
    if (ctx->r10 != ctx->r1) {
        // 0x8022C72C: nop
    
            goto L_8022C734;
    }
    // 0x8022C72C: nop

    // 0x8022C730: break       6
    do_break(2149762864);
L_8022C734:
    // 0x8022C734: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022C738: mflo        $t5
    ctx->r13 = lo;
    // 0x8022C73C: nop

    // 0x8022C740: nop

    // 0x8022C744: div         $zero, $t5, $a1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r5)));
    // 0x8022C748: mflo        $t6
    ctx->r14 = lo;
    // 0x8022C74C: sh          $t6, 0x2C2($a0)
    MEM_H(0X2C2, ctx->r4) = ctx->r14;
    // 0x8022C750: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8022C754: bne         $a1, $zero, L_8022C760
    if (ctx->r5 != 0) {
        // 0x8022C758: nop
    
            goto L_8022C760;
    }
    // 0x8022C758: nop

    // 0x8022C75C: break       7
    do_break(2149762908);
L_8022C760:
    // 0x8022C760: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022C764: bne         $a1, $at, L_8022C778
    if (ctx->r5 != ctx->r1) {
        // 0x8022C768: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022C778;
    }
    // 0x8022C768: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022C76C: bne         $t5, $at, L_8022C778
    if (ctx->r13 != ctx->r1) {
        // 0x8022C770: nop
    
            goto L_8022C778;
    }
    // 0x8022C770: nop

    // 0x8022C774: break       6
    do_break(2149762932);
L_8022C778:
    // 0x8022C778: swl         $t8, 0x2AC($a0)
    do_swl(rdram, 0X2AC, ctx->r4, ctx->r24);
    // 0x8022C77C: swr         $t8, 0x2AF($a0)
    do_swr(rdram, 0X2AF, ctx->r4, ctx->r24);
    // 0x8022C780: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8022C784: swl         $t7, 0x2B0($a0)
    do_swl(rdram, 0X2B0, ctx->r4, ctx->r15);
    // 0x8022C788: swr         $t7, 0x2B3($a0)
    do_swr(rdram, 0X2B3, ctx->r4, ctx->r15);
    // 0x8022C78C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8022C790: sb          $zero, 0x2D0($a0)
    MEM_B(0X2D0, ctx->r4) = 0;
    // 0x8022C794: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8022C798: swl         $t8, 0x2B4($a0)
    do_swl(rdram, 0X2B4, ctx->r4, ctx->r24);
    // 0x8022C79C: jr          $ra
    // 0x8022C7A0: swr         $t8, 0x2B7($a0)
    do_swr(rdram, 0X2B7, ctx->r4, ctx->r24);
    return;
    // 0x8022C7A0: swr         $t8, 0x2B7($a0)
    do_swr(rdram, 0X2B7, ctx->r4, ctx->r24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022c7a4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022c7a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C7A4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022C7A8: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022c7ac(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022c7ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022C7AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8022C7B0: addiu       $a1, $a0, -0x44C
    ctx->r5 = ADD32(ctx->r4, -0X44C);
    // 0x8022C7B4: bne         $a1, $a2, L_8022C7C8
    if (ctx->r5 != ctx->r6) {
        // 0x8022C7B8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8022C7C8;
    }
    // 0x8022C7B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022C7BC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8022C7C0: b           L_8022C7D0
    // 0x8022C7C4: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
        goto L_8022C7D0;
    // 0x8022C7C4: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
L_8022C7C8:
    // 0x8022C7C8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8022C7CC: addiu       $v1, $v1, -0x2322
    ctx->r3 = ADD32(ctx->r3, -0X2322);
L_8022C7D0:
    // 0x8022C7D0: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8022C7D4: addiu       $t7, $t7, -0x1CF4
    ctx->r15 = ADD32(ctx->r15, -0X1CF4);
    // 0x8022C7D8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8022C7DC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8022C7E0: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8022C7E4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8022C7E8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8022C7EC: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x8022C7F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022C7F4: andi        $t1, $zero, 0xFFFF
    ctx->r9 = 0 & 0XFFFF;
    // 0x8022C7F8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x8022C7FC: lhu         $v0, 0x2C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2C);
    // 0x8022C800: beq         $v0, $at, L_8022C810
    if (ctx->r2 == ctx->r1) {
        // 0x8022C804: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8022C810;
    }
    // 0x8022C804: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8022C808: bnel        $v0, $at, L_8022C824
    if (ctx->r2 != ctx->r1) {
        // 0x8022C80C: lh          $v0, 0x2($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X2);
            goto L_8022C824;
    }
    goto skip_0;
    // 0x8022C80C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    skip_0:
L_8022C810:
    // 0x8022C810: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8022C814: sh          $v0, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r2;
    // 0x8022C818: b           L_8022C82C
    // 0x8022C81C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
        goto L_8022C82C;
    // 0x8022C81C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8022C820: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
L_8022C824:
    // 0x8022C824: sh          $v0, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r2;
    // 0x8022C828: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8022C82C:
    // 0x8022C82C: sh          $zero, 0x300($a0)
    MEM_H(0X300, ctx->r4) = 0;
    // 0x8022C830: sh          $t1, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r9;
    // 0x8022C834: lhu         $t2, 0xE($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XE);
    // 0x8022C838: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x8022C83C: lh          $t4, 0x4C($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4C);
    // 0x8022C840: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8022C844: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8022C848: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8022C84C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8022C850: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8022C854: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
    // 0x8022C858: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8022C85C: sh          $t4, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r12;
    // 0x8022C860: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x8022C864: sh          $zero, 0x302($a0)
    MEM_H(0X302, ctx->r4) = 0;
    // 0x8022C868: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8022C86C: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // 0x8022C870: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // 0x8022C874: lh          $v0, 0x302($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X302);
    // 0x8022C878: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022C87C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022C880: sh          $v0, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r2;
    // 0x8022C884: sh          $v0, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r2;
    // 0x8022C888: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
    // 0x8022C88C: sh          $v0, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r2;
    // 0x8022C890: sh          $v0, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r2;
    // 0x8022C894: lhu         $v0, 0x42($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X42);
    // 0x8022C898: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x8022C89C: sh          $v0, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r2;
    // 0x8022C8A0: lhu         $v0, 0x46($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X46);
    // 0x8022C8A4: sh          $v0, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r2;
    // 0x8022C8A8: sh          $v0, 0x54($a0)
    MEM_H(0X54, ctx->r4) = ctx->r2;
    // 0x8022C8AC: lhu         $t5, 0x44($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X44);
    // 0x8022C8B0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8022C8B4: sh          $t5, 0x52($a0)
    MEM_H(0X52, ctx->r4) = ctx->r13;
    // 0x8022C8B8: lhu         $t6, 0x48($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X48);
    // 0x8022C8BC: sh          $zero, 0x5E($a0)
    MEM_H(0X5E, ctx->r4) = 0;
    // 0x8022C8C0: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    // 0x8022C8C4: sh          $v0, 0x62($a0)
    MEM_H(0X62, ctx->r4) = ctx->r2;
    // 0x8022C8C8: sh          $v0, 0x64($a0)
    MEM_H(0X64, ctx->r4) = ctx->r2;
    // 0x8022C8CC: sh          $zero, 0x66($a0)
    MEM_H(0X66, ctx->r4) = 0;
    // 0x8022C8D0: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    // 0x8022C8D4: sh          $zero, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = 0;
    // 0x8022C8D8: sh          $zero, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = 0;
    // 0x8022C8DC: sb          $t8, 0x384($a0)
    MEM_B(0X384, ctx->r4) = ctx->r24;
    // 0x8022C8E0: sb          $t6, 0x2D1($a0)
    MEM_B(0X2D1, ctx->r4) = ctx->r14;
    // 0x8022C8E4: lwl         $t0, 0x10($v1)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r3, 0X10);
    // 0x8022C8E8: lwr         $t0, 0x13($v1)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r3, 0X13);
    // 0x8022C8EC: swl         $t0, 0x82($a0)
    do_swl(rdram, 0X82, ctx->r4, ctx->r8);
    // 0x8022C8F0: swr         $t0, 0x85($a0)
    do_swr(rdram, 0X85, ctx->r4, ctx->r8);
    // 0x8022C8F4: lwl         $t9, 0x14($v1)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r3, 0X14);
    // 0x8022C8F8: lwr         $t9, 0x17($v1)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r3, 0X17);
    // 0x8022C8FC: swl         $t9, 0x86($a0)
    do_swl(rdram, 0X86, ctx->r4, ctx->r25);
    // 0x8022C900: swr         $t9, 0x89($a0)
    do_swr(rdram, 0X89, ctx->r4, ctx->r25);
    // 0x8022C904: lwl         $t0, 0x18($v1)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r3, 0X18);
    // 0x8022C908: lwr         $t0, 0x1B($v1)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r3, 0X1B);
    // 0x8022C90C: swl         $t0, 0x8A($a0)
    do_swl(rdram, 0X8A, ctx->r4, ctx->r8);
    // 0x8022C910: swr         $t0, 0x8D($a0)
    do_swr(rdram, 0X8D, ctx->r4, ctx->r8);
    // 0x8022C914: lwl         $t2, 0x1C($v1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r3, 0X1C);
    // 0x8022C918: lwr         $t2, 0x1F($v1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r3, 0X1F);
    // 0x8022C91C: swl         $t2, 0x8E($a0)
    do_swl(rdram, 0X8E, ctx->r4, ctx->r10);
    // 0x8022C920: swr         $t2, 0x91($a0)
    do_swr(rdram, 0X91, ctx->r4, ctx->r10);
    // 0x8022C924: lwl         $t1, 0x20($v1)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r3, 0X20);
    // 0x8022C928: lwr         $t1, 0x23($v1)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r3, 0X23);
    // 0x8022C92C: swl         $t1, 0x92($a0)
    do_swl(rdram, 0X92, ctx->r4, ctx->r9);
    // 0x8022C930: swr         $t1, 0x95($a0)
    do_swr(rdram, 0X95, ctx->r4, ctx->r9);
    // 0x8022C934: lwl         $t2, 0x24($v1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r3, 0X24);
    // 0x8022C938: lwr         $t2, 0x27($v1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r3, 0X27);
    // 0x8022C93C: swl         $t2, 0x96($a0)
    do_swl(rdram, 0X96, ctx->r4, ctx->r10);
    // 0x8022C940: swr         $t2, 0x99($a0)
    do_swr(rdram, 0X99, ctx->r4, ctx->r10);
    // 0x8022C944: lwl         $t4, 0x28($v1)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r3, 0X28);
    // 0x8022C948: lwr         $t4, 0x2B($v1)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r3, 0X2B);
    // 0x8022C94C: swl         $t4, 0x6A($a0)
    do_swl(rdram, 0X6A, ctx->r4, ctx->r12);
    // 0x8022C950: swr         $t4, 0x6D($a0)
    do_swr(rdram, 0X6D, ctx->r4, ctx->r12);
    // 0x8022C954: lwl         $t3, 0x2C($v1)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r3, 0X2C);
    // 0x8022C958: lwr         $t3, 0x2F($v1)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r3, 0X2F);
    // 0x8022C95C: swl         $t3, 0x6E($a0)
    do_swl(rdram, 0X6E, ctx->r4, ctx->r11);
    // 0x8022C960: swr         $t3, 0x71($a0)
    do_swr(rdram, 0X71, ctx->r4, ctx->r11);
    // 0x8022C964: lwl         $t4, 0x30($v1)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r3, 0X30);
    // 0x8022C968: lwr         $t4, 0x33($v1)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r3, 0X33);
    // 0x8022C96C: swl         $t4, 0x72($a0)
    do_swl(rdram, 0X72, ctx->r4, ctx->r12);
    // 0x8022C970: swr         $t4, 0x75($a0)
    do_swr(rdram, 0X75, ctx->r4, ctx->r12);
    // 0x8022C974: lwl         $t6, 0x34($v1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r3, 0X34);
    // 0x8022C978: lwr         $t6, 0x37($v1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r3, 0X37);
    // 0x8022C97C: swl         $t6, 0x76($a0)
    do_swl(rdram, 0X76, ctx->r4, ctx->r14);
    // 0x8022C980: swr         $t6, 0x79($a0)
    do_swr(rdram, 0X79, ctx->r4, ctx->r14);
    // 0x8022C984: lwl         $t5, 0x38($v1)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r3, 0X38);
    // 0x8022C988: lwr         $t5, 0x3B($v1)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r3, 0X3B);
    // 0x8022C98C: swl         $t5, 0x7A($a0)
    do_swl(rdram, 0X7A, ctx->r4, ctx->r13);
    // 0x8022C990: swr         $t5, 0x7D($a0)
    do_swr(rdram, 0X7D, ctx->r4, ctx->r13);
    // 0x8022C994: lwl         $t6, 0x3C($v1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r3, 0X3C);
    // 0x8022C998: lwr         $t6, 0x3F($v1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r3, 0X3F);
    // 0x8022C99C: sb          $zero, 0x2F8($a0)
    MEM_B(0X2F8, ctx->r4) = 0;
    // 0x8022C9A0: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8022C9A4: swl         $t6, 0x7E($a0)
    do_swl(rdram, 0X7E, ctx->r4, ctx->r14);
    // 0x8022C9A8: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8022C9AC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8022C9B0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8022C9B4: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x8022C9B8: swr         $t6, 0x81($a0)
    do_swr(rdram, 0X81, ctx->r4, ctx->r14);
    // 0x8022C9BC: lbu         $t7, 0x8C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8C);
    // 0x8022C9C0: sb          $zero, 0x2FB($a0)
    MEM_B(0X2FB, ctx->r4) = 0;
    // 0x8022C9C4: sb          $zero, 0x2FC($a0)
    MEM_B(0X2FC, ctx->r4) = 0;
    // 0x8022C9C8: sb          $zero, 0x2FD($a0)
    MEM_B(0X2FD, ctx->r4) = 0;
    // 0x8022C9CC: sb          $zero, 0x2FE($a0)
    MEM_B(0X2FE, ctx->r4) = 0;
    // 0x8022C9D0: sb          $zero, 0x2FF($a0)
    MEM_B(0X2FF, ctx->r4) = 0;
    // 0x8022C9D4: sb          $zero, 0xA6($a0)
    MEM_B(0XA6, ctx->r4) = 0;
    // 0x8022C9D8: sb          $zero, 0x385($a0)
    MEM_B(0X385, ctx->r4) = 0;
    // 0x8022C9DC: sb          $zero, 0x388($a0)
    MEM_B(0X388, ctx->r4) = 0;
    // 0x8022C9E0: sb          $zero, 0x38B($a0)
    MEM_B(0X38B, ctx->r4) = 0;
    // 0x8022C9E4: sb          $zero, 0x386($a0)
    MEM_B(0X386, ctx->r4) = 0;
    // 0x8022C9E8: sb          $zero, 0x389($a0)
    MEM_B(0X389, ctx->r4) = 0;
    // 0x8022C9EC: sb          $zero, 0x38C($a0)
    MEM_B(0X38C, ctx->r4) = 0;
    // 0x8022C9F0: sb          $zero, 0x387($a0)
    MEM_B(0X387, ctx->r4) = 0;
    // 0x8022C9F4: sb          $zero, 0x38A($a0)
    MEM_B(0X38A, ctx->r4) = 0;
    // 0x8022C9F8: sb          $zero, 0x38D($a0)
    MEM_B(0X38D, ctx->r4) = 0;
    // 0x8022C9FC: sb          $t7, 0x2F9($a0)
    MEM_B(0X2F9, ctx->r4) = ctx->r15;
    // 0x8022CA00: lwl         $t9, 0x56($v1)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r3, 0X56);
    // 0x8022CA04: lwr         $t9, 0x59($v1)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r3, 0X59);
    // 0x8022CA08: swl         $t9, 0x2C4($a0)
    do_swl(rdram, 0X2C4, ctx->r4, ctx->r25);
    // 0x8022CA0C: swr         $t9, 0x2C7($a0)
    do_swr(rdram, 0X2C7, ctx->r4, ctx->r25);
    // 0x8022CA10: lwl         $t8, 0x5A($v1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r3, 0X5A);
    // 0x8022CA14: lwr         $t8, 0x5D($v1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r3, 0X5D);
    // 0x8022CA18: swl         $t8, 0x2C8($a0)
    do_swl(rdram, 0X2C8, ctx->r4, ctx->r24);
    // 0x8022CA1C: swr         $t8, 0x2CB($a0)
    do_swr(rdram, 0X2CB, ctx->r4, ctx->r24);
    // 0x8022CA20: lwl         $t9, 0x5E($v1)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r3, 0X5E);
    // 0x8022CA24: lwr         $t9, 0x61($v1)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r3, 0X61);
    // 0x8022CA28: swl         $t9, 0x2CC($a0)
    do_swl(rdram, 0X2CC, ctx->r4, ctx->r25);
    // 0x8022CA2C: swr         $t9, 0x2CF($a0)
    do_swr(rdram, 0X2CF, ctx->r4, ctx->r25);
    // 0x8022CA30: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8022CA34: jal         0x8022C5AC
    // 0x8022CA38: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8022C5AC)(rdram, ctx);
        goto after_0;
    // 0x8022CA38: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x8022CA3C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8022CA40: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8022CA44: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x8022CA48: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    // 0x8022CA4C: sh          $t1, 0x310($a0)
    MEM_H(0X310, ctx->r4) = ctx->r9;
    // 0x8022CA50: sb          $zero, 0x30C($a0)
    MEM_B(0X30C, ctx->r4) = 0;
    // 0x8022CA54: sh          $zero, 0x30E($a0)
    MEM_H(0X30E, ctx->r4) = 0;
    // 0x8022CA58: sh          $t0, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r8;
    // 0x8022CA5C: lbu         $t2, 0x62($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X62);
    // 0x8022CA60: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8022CA64: sb          $t2, 0xA2($a0)
    MEM_B(0XA2, ctx->r4) = ctx->r10;
    // 0x8022CA68: lbu         $t3, 0x63($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X63);
    // 0x8022CA6C: sb          $t3, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r11;
    // 0x8022CA70: lbu         $t4, 0x64($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X64);
    // 0x8022CA74: sb          $t4, 0xA4($a0)
    MEM_B(0XA4, ctx->r4) = ctx->r12;
    // 0x8022CA78: lbu         $t5, 0x65($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X65);
    // 0x8022CA7C: sb          $t6, 0x399($a0)
    MEM_B(0X399, ctx->r4) = ctx->r14;
    // 0x8022CA80: jal         0x8022C314
    // 0x8022CA84: sb          $t5, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r13;
    LOOKUP_FUNC(0x8022C314)(rdram, ctx);
        goto after_1;
    // 0x8022CA84: sb          $t5, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r13;
    after_1:
    // 0x8022CA88: jal         0x8022C478
    // 0x8022CA8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8022C478)(rdram, ctx);
        goto after_2;
    // 0x8022CA8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8022CA90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8022CA94: lbu         $t7, -0x226E($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X226E);
    // 0x8022CA98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8022CA9C: bnel        $t7, $zero, L_8022CAB0
    if (ctx->r15 != 0) {
        // 0x8022CAA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022CAB0;
    }
    goto skip_1;
    // 0x8022CAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8022CAA4: jal         0x80379410
    // 0x8022CAA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80379410)(rdram, ctx);
        goto after_3;
    // 0x8022CAA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8022CAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022CAB0:
    // 0x8022CAB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8022CAB4: jr          $ra
    // 0x8022CAB8: nop

    return;
    // 0x8022CAB8: nop

;}
RECOMP_FUNC void M10_FUN_8022cabc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022CABC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8022CAC0: addiu       $t7, $t7, -0x3FC4
    ctx->r15 = ADD32(ctx->r15, -0X3FC4);
    // 0x8022CAC4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022CAC8: addiu       $t6, $t6, -0x3C28
    ctx->r14 = ADD32(ctx->r14, -0X3C28);
    // 0x8022CACC: addiu       $t0, $t7, 0x39C
    ctx->r8 = ADD32(ctx->r15, 0X39C);
L_8022CAD0:
    // 0x8022CAD0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8022CAD4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8022CAD8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8022CADC: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8022CAE0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8022CAE4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8022CAE8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8022CAEC: bne         $t7, $t0, L_8022CAD0
    if (ctx->r15 != ctx->r8) {
        // 0x8022CAF0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8022CAD0;
    }
    // 0x8022CAF0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8022CAF4: jr          $ra
    // 0x8022CAF8: nop

    return;
    // 0x8022CAF8: nop

;}
RECOMP_FUNC void M10_FUN_8022cafc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022CAFC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8022CB00: addiu       $t2, $t2, -0x4410
    ctx->r10 = ADD32(ctx->r10, -0X4410);
    // 0x8022CB04: lw          $t6, 0xDC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022cb08(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022cb08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022CB08: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8022CB0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022CB10: bne         $a0, $t6, L_8022CB24
    if (ctx->r4 != ctx->r14) {
        // 0x8022CB14: addiu       $t7, $t2, 0x44C
        ctx->r15 = ADD32(ctx->r10, 0X44C);
            goto L_8022CB24;
    }
    // 0x8022CB14: addiu       $t7, $t2, 0x44C
    ctx->r15 = ADD32(ctx->r10, 0X44C);
    // 0x8022CB18: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022CB1C: b           L_8022CB2C
    // 0x8022CB20: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
        goto L_8022CB2C;
    // 0x8022CB20: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_8022CB24:
    // 0x8022CB24: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022CB28: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_8022CB2C:
    // 0x8022CB2C: bne         $a3, $t7, L_8022CB40
    if (ctx->r7 != ctx->r15) {
        // 0x8022CB30: lui         $t8, 0x8024
        ctx->r24 = S32(0X8024 << 16);
            goto L_8022CB40;
    }
    // 0x8022CB30: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x8022CB34: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8022CB38: b           L_8022CB48
    // 0x8022CB3C: addiu       $t5, $t5, -0x3C28
    ctx->r13 = ADD32(ctx->r13, -0X3C28);
        goto L_8022CB48;
    // 0x8022CB3C: addiu       $t5, $t5, -0x3C28
    ctx->r13 = ADD32(ctx->r13, -0X3C28);
L_8022CB40:
    // 0x8022CB40: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8022CB44: addiu       $t5, $t5, -0x3FC4
    ctx->r13 = ADD32(ctx->r13, -0X3FC4);
L_8022CB48:
    // 0x8022CB48: addiu       $t8, $t8, -0x1CEC
    ctx->r24 = ADD32(ctx->r24, -0X1CEC);
    // 0x8022CB4C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8022CB50: addiu       $ra, $sp, 0x4C
    ctx->r31 = ADD32(ctx->r29, 0X4C);
    // 0x8022CB54: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8022CB58: sw          $t6, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r14;
    // 0x8022CB5C: lhu         $t6, 0x4($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X4);
    // 0x8022CB60: addiu       $v0, $v0, -0x36C0
    ctx->r2 = ADD32(ctx->r2, -0X36C0);
    // 0x8022CB64: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8022CB68: sh          $t6, 0x4($ra)
    MEM_H(0X4, ctx->r31) = ctx->r14;
    // 0x8022CB6C: sw          $v0, 0x334($a3)
    MEM_W(0X334, ctx->r7) = ctx->r2;
    // 0x8022CB70: lhu         $t8, 0x36($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X36);
    // 0x8022CB74: lhu         $t7, 0x4E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4E);
    // 0x8022CB78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022CB7C: addiu       $t3, $t3, -0x23C0
    ctx->r11 = ADD32(ctx->r11, -0X23C0);
    // 0x8022CB80: beq         $t7, $t8, L_8022CBBC
    if (ctx->r15 == ctx->r24) {
        // 0x8022CB84: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8022CBBC;
    }
    // 0x8022CB84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022CB88: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8022CB8C: addiu       $t9, $t1, 0xA0
    ctx->r25 = ADD32(ctx->r9, 0XA0);
L_8022CB90:
    // 0x8022CB90: sw          $t9, 0x334($a3)
    MEM_W(0X334, ctx->r7) = ctx->r25;
    // 0x8022CB94: lhu         $t7, 0x36($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X36);
    // 0x8022CB98: lhu         $t6, 0x4E($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X4E);
    // 0x8022CB9C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8022CBA0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022CBA4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022CBA8: beq         $t6, $t7, L_8022CBBC
    if (ctx->r14 == ctx->r15) {
        // 0x8022CBAC: or          $t1, $t9, $zero
        ctx->r9 = ctx->r25 | 0;
            goto L_8022CBBC;
    }
    // 0x8022CBAC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8022CBB0: slti        $at, $a2, 0x29
    ctx->r1 = SIGNED(ctx->r6) < 0X29 ? 1 : 0;
    // 0x8022CBB4: bnel        $at, $zero, L_8022CB90
    if (ctx->r1 != 0) {
        // 0x8022CBB8: addiu       $t9, $t1, 0xA0
        ctx->r25 = ADD32(ctx->r9, 0XA0);
            goto L_8022CB90;
    }
    goto skip_0;
    // 0x8022CBB8: addiu       $t9, $t1, 0xA0
    ctx->r25 = ADD32(ctx->r9, 0XA0);
    skip_0:
L_8022CBBC:
    // 0x8022CBBC: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
    // 0x8022CBC0: sb          $a2, 0x395($a3)
    MEM_B(0X395, ctx->r7) = ctx->r6;
    // 0x8022CBC4: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x8022CBC8: lh          $t9, 0x1E($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X1E);
    // 0x8022CBCC: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8022CBD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022CBD4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022CBD8: mflo        $t6
    ctx->r14 = lo;
    // 0x8022CBDC: nop

    // 0x8022CBE0: nop

    // 0x8022CBE4: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x8022CBE8: mflo        $t7
    ctx->r15 = lo;
    // 0x8022CBEC: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8022CBF0: bne         $t0, $zero, L_8022CBFC
    if (ctx->r8 != 0) {
        // 0x8022CBF4: nop
    
            goto L_8022CBFC;
    }
    // 0x8022CBF4: nop

    // 0x8022CBF8: break       7
    do_break(2149764088);
L_8022CBFC:
    // 0x8022CBFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022CC00: bne         $t0, $at, L_8022CC14
    if (ctx->r8 != ctx->r1) {
        // 0x8022CC04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022CC14;
    }
    // 0x8022CC04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022CC08: bne         $t6, $at, L_8022CC14
    if (ctx->r14 != ctx->r1) {
        // 0x8022CC0C: nop
    
            goto L_8022CC14;
    }
    // 0x8022CC0C: nop

    // 0x8022CC10: break       6
    do_break(2149764112);
L_8022CC14:
    // 0x8022CC14: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x8022CC18: lhu         $v0, 0x1C($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X1C);
    // 0x8022CC1C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8022CC20: beql        $at, $zero, L_8022CC34
    if (ctx->r1 == 0) {
        // 0x8022CC24: sh          $v1, 0x46($a3)
        MEM_H(0X46, ctx->r7) = ctx->r3;
            goto L_8022CC34;
    }
    goto skip_1;
    // 0x8022CC24: sh          $v1, 0x46($a3)
    MEM_H(0X46, ctx->r7) = ctx->r3;
    skip_1:
    // 0x8022CC28: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8022CC2C: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x8022CC30: sh          $v1, 0x46($a3)
    MEM_H(0X46, ctx->r7) = ctx->r3;
L_8022CC34:
    // 0x8022CC34: sh          $v1, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r3;
    // 0x8022CC38: lh          $t9, 0x22($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X22);
    // 0x8022CC3C: lhu         $t8, 0x8($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X8);
    // 0x8022CC40: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8022CC44: sh          $t6, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r14;
    // 0x8022CC48: lh          $a0, 0x8($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X8);
    // 0x8022CC4C: lhu         $a1, 0x20($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X20);
    // 0x8022CC50: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022CC54: beql        $at, $zero, L_8022CC68
    if (ctx->r1 == 0) {
        // 0x8022CC58: sh          $a0, 0xA($a3)
        MEM_H(0XA, ctx->r7) = ctx->r4;
            goto L_8022CC68;
    }
    goto skip_2;
    // 0x8022CC58: sh          $a0, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r4;
    skip_2:
    // 0x8022CC5C: sh          $a1, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r5;
    // 0x8022CC60: lh          $a0, 0x8($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X8);
    // 0x8022CC64: sh          $a0, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r4;
L_8022CC68:
    // 0x8022CC68: lb          $t8, 0x25($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X25);
    // 0x8022CC6C: lhu         $t7, 0xE($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0XE);
    // 0x8022CC70: addiu       $a1, $t1, 0x2D
    ctx->r5 = ADD32(ctx->r9, 0X2D);
    // 0x8022CC74: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8022CC78: sh          $t9, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r25;
    // 0x8022CC7C: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
    // 0x8022CC80: lbu         $v0, 0x24($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X24);
    // 0x8022CC84: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8022CC88: beq         $at, $zero, L_8022CC98
    if (ctx->r1 == 0) {
        // 0x8022CC8C: nop
    
            goto L_8022CC98;
    }
    // 0x8022CC8C: nop

    // 0x8022CC90: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8022CC94: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
L_8022CC98:
    // 0x8022CC98: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022CC9C: mflo        $t6
    ctx->r14 = lo;
    // 0x8022CCA0: sh          $t6, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r14;
    // 0x8022CCA4: lbu         $t8, 0xE($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XE);
    // 0x8022CCA8: lhu         $t7, 0x42($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X42);
    // 0x8022CCAC: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022CCB0: mflo        $t9
    ctx->r25 = lo;
    // 0x8022CCB4: nop

    // 0x8022CCB8: nop

    // 0x8022CCBC: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x8022CCC0: mflo        $v0
    ctx->r2 = lo;
    // 0x8022CCC4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8022CCC8: bne         $t0, $zero, L_8022CCD4
    if (ctx->r8 != 0) {
        // 0x8022CCCC: nop
    
            goto L_8022CCD4;
    }
    // 0x8022CCCC: nop

    // 0x8022CCD0: break       7
    do_break(2149764304);
L_8022CCD4:
    // 0x8022CCD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022CCD8: bne         $t0, $at, L_8022CCEC
    if (ctx->r8 != ctx->r1) {
        // 0x8022CCDC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022CCEC;
    }
    // 0x8022CCDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022CCE0: bne         $t9, $at, L_8022CCEC
    if (ctx->r25 != ctx->r1) {
        // 0x8022CCE4: nop
    
            goto L_8022CCEC;
    }
    // 0x8022CCE4: nop

    // 0x8022CCE8: break       6
    do_break(2149764328);
L_8022CCEC:
    // 0x8022CCEC: sh          $v0, 0x58($a3)
    MEM_H(0X58, ctx->r7) = ctx->r2;
    // 0x8022CCF0: sh          $v0, 0x4E($a3)
    MEM_H(0X4E, ctx->r7) = ctx->r2;
    // 0x8022CCF4: lhu         $a0, 0xC($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XC);
    // 0x8022CCF8: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x8022CCFC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8022CD00: beql        $at, $zero, L_8022CD14
    if (ctx->r1 == 0) {
        // 0x8022CD04: lhu         $t7, 0x40($t3)
        ctx->r15 = MEM_HU(ctx->r11, 0X40);
            goto L_8022CD14;
    }
    goto skip_3;
    // 0x8022CD04: lhu         $t7, 0x40($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X40);
    skip_3:
    // 0x8022CD08: sh          $a0, 0x58($a3)
    MEM_H(0X58, ctx->r7) = ctx->r4;
    // 0x8022CD0C: sh          $a0, 0x4E($a3)
    MEM_H(0X4E, ctx->r7) = ctx->r4;
    // 0x8022CD10: lhu         $t7, 0x40($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X40);
L_8022CD14:
    // 0x8022CD14: lbu         $t8, 0x12($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X12);
    // 0x8022CD18: lbu         $v0, 0x1D($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X1D);
    // 0x8022CD1C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022CD20: mflo        $t9
    ctx->r25 = lo;
    // 0x8022CD24: nop

    // 0x8022CD28: nop

    // 0x8022CD2C: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x8022CD30: mflo        $v0
    ctx->r2 = lo;
    // 0x8022CD34: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8022CD38: bne         $t0, $zero, L_8022CD44
    if (ctx->r8 != 0) {
        // 0x8022CD3C: nop
    
            goto L_8022CD44;
    }
    // 0x8022CD3C: nop

    // 0x8022CD40: break       7
    do_break(2149764416);
L_8022CD44:
    // 0x8022CD44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022CD48: bne         $t0, $at, L_8022CD5C
    if (ctx->r8 != ctx->r1) {
        // 0x8022CD4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022CD5C;
    }
    // 0x8022CD4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022CD50: bne         $t9, $at, L_8022CD5C
    if (ctx->r25 != ctx->r1) {
        // 0x8022CD54: nop
    
            goto L_8022CD5C;
    }
    // 0x8022CD54: nop

    // 0x8022CD58: break       6
    do_break(2149764440);
L_8022CD5C:
    // 0x8022CD5C: sh          $v0, 0x5A($a3)
    MEM_H(0X5A, ctx->r7) = ctx->r2;
    // 0x8022CD60: sh          $v0, 0x50($a3)
    MEM_H(0X50, ctx->r7) = ctx->r2;
    // 0x8022CD64: lhu         $v1, 0x10($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X10);
    // 0x8022CD68: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x8022CD6C: addiu       $t0, $t1, 0x27
    ctx->r8 = ADD32(ctx->r9, 0X27);
    // 0x8022CD70: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8022CD74: beql        $at, $zero, L_8022CD88
    if (ctx->r1 == 0) {
        // 0x8022CD78: lhu         $t7, 0x46($t3)
        ctx->r15 = MEM_HU(ctx->r11, 0X46);
            goto L_8022CD88;
    }
    goto skip_4;
    // 0x8022CD78: lhu         $t7, 0x46($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X46);
    skip_4:
    // 0x8022CD7C: sh          $v1, 0x5A($a3)
    MEM_H(0X5A, ctx->r7) = ctx->r3;
    // 0x8022CD80: sh          $v1, 0x50($a3)
    MEM_H(0X50, ctx->r7) = ctx->r3;
    // 0x8022CD84: lhu         $t7, 0x46($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X46);
L_8022CD88:
    // 0x8022CD88: lh          $t8, 0x16($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X16);
    // 0x8022CD8C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8022CD90: sh          $v0, 0x5C($a3)
    MEM_H(0X5C, ctx->r7) = ctx->r2;
    // 0x8022CD94: sh          $v0, 0x54($a3)
    MEM_H(0X54, ctx->r7) = ctx->r2;
    // 0x8022CD98: lhu         $v1, 0x14($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X14);
    // 0x8022CD9C: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8022CDA0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8022CDA4: beql        $at, $zero, L_8022CDB8
    if (ctx->r1 == 0) {
        // 0x8022CDA8: lhu         $t6, 0x44($t3)
        ctx->r14 = MEM_HU(ctx->r11, 0X44);
            goto L_8022CDB8;
    }
    goto skip_5;
    // 0x8022CDA8: lhu         $t6, 0x44($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X44);
    skip_5:
    // 0x8022CDAC: sh          $v1, 0x5C($a3)
    MEM_H(0X5C, ctx->r7) = ctx->r3;
    // 0x8022CDB0: sh          $v1, 0x54($a3)
    MEM_H(0X54, ctx->r7) = ctx->r3;
    // 0x8022CDB4: lhu         $t6, 0x44($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X44);
L_8022CDB8:
    // 0x8022CDB8: lh          $t7, 0x1A($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X1A);
    // 0x8022CDBC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8022CDC0: sh          $t8, 0x52($a3)
    MEM_H(0X52, ctx->r7) = ctx->r24;
    // 0x8022CDC4: lhu         $v0, 0x18($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X18);
    // 0x8022CDC8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8022CDCC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8022CDD0: beql        $at, $zero, L_8022CDE0
    if (ctx->r1 == 0) {
        // 0x8022CDD4: lhu         $t6, 0x26($t3)
        ctx->r14 = MEM_HU(ctx->r11, 0X26);
            goto L_8022CDE0;
    }
    goto skip_6;
    // 0x8022CDD4: lhu         $t6, 0x26($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X26);
    skip_6:
    // 0x8022CDD8: sh          $v0, 0x52($a3)
    MEM_H(0X52, ctx->r7) = ctx->r2;
    // 0x8022CDDC: lhu         $t6, 0x26($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X26);
L_8022CDE0:
    // 0x8022CDE0: lhu         $t7, 0x1E($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X1E);
    // 0x8022CDE4: lhu         $t9, 0x20($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X20);
    // 0x8022CDE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022CDEC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8022CDF0: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x8022CDF4: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8022CDF8: lhu         $t9, 0x24($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X24);
    // 0x8022CDFC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8022CE00: addiu       $v1, $a3, 0x82
    ctx->r3 = ADD32(ctx->r7, 0X82);
    // 0x8022CE04: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8022CE08: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8022CE0C: mflo        $t2
    ctx->r10 = lo;
    // 0x8022CE10: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x8022CE14: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
L_8022CE18:
    // 0x8022CE18: bnel        $a2, $zero, L_8022CE38
    if (ctx->r6 != 0) {
        // 0x8022CE1C: lb          $t9, 0x0($a1)
        ctx->r25 = MEM_B(ctx->r5, 0X0);
            goto L_8022CE38;
    }
    goto skip_7;
    // 0x8022CE1C: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    skip_7:
    // 0x8022CE20: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8022CE24: lhu         $t7, 0x1C($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X1C);
    // 0x8022CE28: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8022CE2C: b           L_8022CE40
    // 0x8022CE30: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_8022CE40;
    // 0x8022CE30: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8022CE34: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
L_8022CE38:
    // 0x8022CE38: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8022CE3C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_8022CE40:
    // 0x8022CE40: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8022CE44: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8022CE48: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8022CE4C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022CE50: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022CE54: beq         $at, $zero, L_8022CE64
    if (ctx->r1 == 0) {
        // 0x8022CE58: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8022CE64;
    }
    // 0x8022CE58: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022CE5C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8022CE60: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_8022CE64:
    // 0x8022CE64: bgtz        $a0, L_8022CE70
    if (SIGNED(ctx->r4) > 0) {
        // 0x8022CE68: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8022CE70;
    }
    // 0x8022CE68: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8022CE6C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8022CE70:
    // 0x8022CE70: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8022CE74: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8022CE78: bne         $at, $zero, L_8022CE18
    if (ctx->r1 != 0) {
        // 0x8022CE7C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8022CE18;
    }
    // 0x8022CE7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8022CE80: lhu         $t7, 0x1A($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X1A);
    // 0x8022CE84: lhu         $t8, 0x12($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X12);
    // 0x8022CE88: lhu         $t6, 0x14($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X14);
    // 0x8022CE8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022CE90: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8022CE94: lhu         $t8, 0x16($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X16);
    // 0x8022CE98: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8022CE9C: lhu         $t6, 0x18($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X18);
    // 0x8022CEA0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8022CEA4: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
    // 0x8022CEA8: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8022CEAC: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8022CEB0: mflo        $t2
    ctx->r10 = lo;
    // 0x8022CEB4: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x8022CEB8: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8022CEBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022CEC0: addiu       $v1, $a3, 0x8E
    ctx->r3 = ADD32(ctx->r7, 0X8E);
    // 0x8022CEC4: addiu       $t0, $t1, 0x33
    ctx->r8 = ADD32(ctx->r9, 0X33);
    // 0x8022CEC8: addiu       $a1, $t1, 0x39
    ctx->r5 = ADD32(ctx->r9, 0X39);
L_8022CECC:
    // 0x8022CECC: bnel        $a2, $zero, L_8022CEEC
    if (ctx->r6 != 0) {
        // 0x8022CED0: lb          $t6, 0x0($a1)
        ctx->r14 = MEM_B(ctx->r5, 0X0);
            goto L_8022CEEC;
    }
    goto skip_8;
    // 0x8022CED0: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    skip_8:
    // 0x8022CED4: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8022CED8: lhu         $t8, 0x10($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X10);
    // 0x8022CEDC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8022CEE0: b           L_8022CEF4
    // 0x8022CEE4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
        goto L_8022CEF4;
    // 0x8022CEE4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8022CEE8: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
L_8022CEEC:
    // 0x8022CEEC: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8022CEF0: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_8022CEF4:
    // 0x8022CEF4: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8022CEF8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8022CEFC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8022CF00: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022CF04: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022CF08: beq         $at, $zero, L_8022CF18
    if (ctx->r1 == 0) {
        // 0x8022CF0C: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8022CF18;
    }
    // 0x8022CF0C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022CF10: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8022CF14: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_8022CF18:
    // 0x8022CF18: bgtz        $a0, L_8022CF24
    if (SIGNED(ctx->r4) > 0) {
        // 0x8022CF1C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8022CF24;
    }
    // 0x8022CF1C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8022CF20: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8022CF24:
    // 0x8022CF24: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8022CF28: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8022CF2C: bne         $at, $zero, L_8022CECC
    if (ctx->r1 != 0) {
        // 0x8022CF30: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8022CECC;
    }
    // 0x8022CF30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8022CF34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8022CF38: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8022CF3C: jal         0x80378F64
    // 0x8022CF40: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80378F64)(rdram, ctx);
        goto after_0;
    // 0x8022CF40: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    after_0:
    // 0x8022CF44: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8022CF48: lw          $t8, 0x334($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X334);
    // 0x8022CF4C: lwl         $t6, 0x40($t8)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r24, 0X40);
    // 0x8022CF50: lwr         $t6, 0x43($t8)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r24, 0X43);
    // 0x8022CF54: swl         $t6, 0x2C4($a0)
    do_swl(rdram, 0X2C4, ctx->r4, ctx->r14);
    // 0x8022CF58: swr         $t6, 0x2C7($a0)
    do_swr(rdram, 0X2C7, ctx->r4, ctx->r14);
    // 0x8022CF5C: lwl         $t9, 0x44($t8)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r24, 0X44);
    // 0x8022CF60: lwr         $t9, 0x47($t8)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r24, 0X47);
    // 0x8022CF64: swl         $t9, 0x2C8($a0)
    do_swl(rdram, 0X2C8, ctx->r4, ctx->r25);
    // 0x8022CF68: swr         $t9, 0x2CB($a0)
    do_swr(rdram, 0X2CB, ctx->r4, ctx->r25);
    // 0x8022CF6C: lwl         $t6, 0x48($t8)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r24, 0X48);
    // 0x8022CF70: lwr         $t6, 0x4B($t8)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r24, 0X4B);
    // 0x8022CF74: swl         $t6, 0x2CC($a0)
    do_swl(rdram, 0X2CC, ctx->r4, ctx->r14);
    // 0x8022CF78: jal         0x8022C5AC
    // 0x8022CF7C: swr         $t6, 0x2CF($a0)
    do_swr(rdram, 0X2CF, ctx->r4, ctx->r14);
    LOOKUP_FUNC(0x8022C5AC)(rdram, ctx);
        goto after_1;
    // 0x8022CF7C: swr         $t6, 0x2CF($a0)
    do_swr(rdram, 0X2CF, ctx->r4, ctx->r14);
    after_1:
    // 0x8022CF80: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8022CF84: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8022CF88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022CF8C: lw          $t7, 0x334($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X334);
    // 0x8022CF90: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8022CF94: addiu       $ra, $sp, 0x4C
    ctx->r31 = ADD32(ctx->r29, 0X4C);
    // 0x8022CF98: lhu         $v0, 0x4E($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4E);
    // 0x8022CF9C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x8022CFA0: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x8022CFA4: bne         $v0, $at, L_8022CFD4
    if (ctx->r2 != ctx->r1) {
        // 0x8022CFA8: addiu       $t2, $zero, 0x4E
        ctx->r10 = ADD32(0, 0X4E);
            goto L_8022CFD4;
    }
    // 0x8022CFA8: addiu       $t2, $zero, 0x4E
    ctx->r10 = ADD32(0, 0X4E);
    // 0x8022CFAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022CFB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022CFB4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022CFB8: swc1        $f0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f0.u32l;
    // 0x8022CFBC: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x8022CFC0: lwc1        $f4, -0x678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X678);
    // 0x8022CFC4: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x8022CFC8: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x8022CFCC: b           L_8022D2D8
    // 0x8022CFD0: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
        goto L_8022D2D8;
    // 0x8022CFD0: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
L_8022CFD4:
    // 0x8022CFD4: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x8022CFD8: bne         $v0, $at, L_8022D00C
    if (ctx->r2 != ctx->r1) {
        // 0x8022CFDC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8022D00C;
    }
    // 0x8022CFDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022CFE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022CFE4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022CFE8: lwc1        $f12, -0x674($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X674);
    // 0x8022CFEC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022CFF0: swc1        $f12, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f12.u32l;
    // 0x8022CFF4: swc1        $f12, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f12.u32l;
    // 0x8022CFF8: lwc1        $f6, -0x670($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X670);
    // 0x8022CFFC: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x8022D000: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x8022D004: b           L_8022D2D8
    // 0x8022D008: swc1        $f6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f6.u32l;
        goto L_8022D2D8;
    // 0x8022D008: swc1        $f6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f6.u32l;
L_8022D00C:
    // 0x8022D00C: lhu         $t8, 0x54($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X54);
    // 0x8022D010: lhu         $t9, 0x54($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X54);
    // 0x8022D014: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    // 0x8022D018: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022D01C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022D020: slti        $at, $a2, -0x64
    ctx->r1 = SIGNED(ctx->r6) < -0X64 ? 1 : 0;
    // 0x8022D024: beq         $at, $zero, L_8022D050
    if (ctx->r1 == 0) {
        // 0x8022D028: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8022D050;
    }
    // 0x8022D028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D02C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D030: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D034: lwc1        $f8, -0x66C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X66C);
    // 0x8022D038: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8022D03C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022D040: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
    // 0x8022D044: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x8022D048: b           L_8022D218
    // 0x8022D04C: swc1        $f10, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f10.u32l;
        goto L_8022D218;
    // 0x8022D04C: swc1        $f10, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f10.u32l;
L_8022D050:
    // 0x8022D050: slti        $at, $a2, -0x3C
    ctx->r1 = SIGNED(ctx->r6) < -0X3C ? 1 : 0;
    // 0x8022D054: beq         $at, $zero, L_8022D0B0
    if (ctx->r1 == 0) {
        // 0x8022D058: addiu       $t6, $a2, 0x3C
        ctx->r14 = ADD32(ctx->r6, 0X3C);
            goto L_8022D0B0;
    }
    // 0x8022D058: addiu       $t6, $a2, 0x3C
    ctx->r14 = ADD32(ctx->r6, 0X3C);
    // 0x8022D05C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8022D060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D068: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8022D06C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D070: ldc1        $f4, -0x668($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X668);
    // 0x8022D074: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8022D078: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022D07C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8022D080: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022D084: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D088: ldc1        $f16, -0x660($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X660);
    // 0x8022D08C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D090: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
    // 0x8022D094: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8022D098: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x8022D09C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8022D0A0: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
    // 0x8022D0A4: lwc1        $f6, -0x658($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X658);
    // 0x8022D0A8: b           L_8022D218
    // 0x8022D0AC: swc1        $f6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f6.u32l;
        goto L_8022D218;
    // 0x8022D0AC: swc1        $f6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f6.u32l;
L_8022D0B0:
    // 0x8022D0B0: bgez        $a2, L_8022D110
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022D0B4: nop
    
            goto L_8022D110;
    }
    // 0x8022D0B4: nop

    // 0x8022D0B8: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x8022D0BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D0C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D0C4: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x8022D0C8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D0CC: ldc1        $f10, -0x650($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X650);
    // 0x8022D0D0: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x8022D0D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022D0D8: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x8022D0DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022D0E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8022D0E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022D0E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022D0EC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D0F0: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
    // 0x8022D0F4: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8022D0F8: sub.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d - ctx->f6.d;
    // 0x8022D0FC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8022D100: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x8022D104: lwc1        $f18, -0x648($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X648);
    // 0x8022D108: b           L_8022D218
    // 0x8022D10C: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
        goto L_8022D218;
    // 0x8022D10C: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
L_8022D110:
    // 0x8022D110: bne         $a2, $zero, L_8022D134
    if (ctx->r6 != 0) {
        // 0x8022D114: slti        $at, $a2, 0x3C
        ctx->r1 = SIGNED(ctx->r6) < 0X3C ? 1 : 0;
            goto L_8022D134;
    }
    // 0x8022D114: slti        $at, $a2, 0x3C
    ctx->r1 = SIGNED(ctx->r6) < 0X3C ? 1 : 0;
    // 0x8022D118: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D11C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D120: nop

    // 0x8022D124: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x8022D128: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
    // 0x8022D12C: b           L_8022D218
    // 0x8022D130: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
        goto L_8022D218;
    // 0x8022D130: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
L_8022D134:
    // 0x8022D134: beql        $at, $zero, L_8022D194
    if (ctx->r1 == 0) {
        // 0x8022D138: slti        $at, $a2, 0x64
        ctx->r1 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
            goto L_8022D194;
    }
    goto skip_9;
    // 0x8022D138: slti        $at, $a2, 0x64
    ctx->r1 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
    skip_9:
    // 0x8022D13C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8022D140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D144: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D148: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022D14C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D150: ldc1        $f6, -0x640($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X640);
    // 0x8022D154: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x8022D158: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022D15C: mul.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8022D160: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022D164: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D168: ldc1        $f4, -0x638($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X638);
    // 0x8022D16C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D170: div.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x8022D174: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8022D178: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8022D17C: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
    // 0x8022D180: lwc1        $f16, -0x630($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X630);
    // 0x8022D184: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x8022D188: b           L_8022D218
    // 0x8022D18C: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
        goto L_8022D218;
    // 0x8022D18C: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
    // 0x8022D190: slti        $at, $a2, 0x64
    ctx->r1 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
L_8022D194:
    // 0x8022D194: beq         $at, $zero, L_8022D1F4
    if (ctx->r1 == 0) {
        // 0x8022D198: addiu       $t7, $zero, 0x64
        ctx->r15 = ADD32(0, 0X64);
            goto L_8022D1F4;
    }
    // 0x8022D198: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8022D19C: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x8022D1A0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8022D1A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D1A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D1AC: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8022D1B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D1B4: ldc1        $f4, -0x628($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X628);
    // 0x8022D1B8: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8022D1BC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022D1C0: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8022D1C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022D1C8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D1CC: ldc1        $f10, -0x620($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X620);
    // 0x8022D1D0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D1D4: div.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x8022D1D8: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x8022D1DC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8022D1E0: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
    // 0x8022D1E4: lwc1        $f8, -0x618($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X618);
    // 0x8022D1E8: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    // 0x8022D1EC: b           L_8022D218
    // 0x8022D1F0: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
        goto L_8022D218;
    // 0x8022D1F0: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
L_8022D1F4:
    // 0x8022D1F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022D1F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022D1FC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D200: lwc1        $f6, -0x614($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X614);
    // 0x8022D204: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8022D208: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8022D20C: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
    // 0x8022D210: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x8022D214: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
L_8022D218:
    // 0x8022D218: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8022D21C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022D220: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022D224: swc1        $f2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
    // 0x8022D228: swc1        $f2, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f2.u32l;
    // 0x8022D22C: swc1        $f2, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f2.u32l;
    // 0x8022D230: lbu         $v0, -0x43F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43F3);
    // 0x8022D234: bne         $v0, $at, L_8022D284
    if (ctx->r2 != ctx->r1) {
        // 0x8022D238: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_8022D284;
    }
    // 0x8022D238: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D23C: ldc1        $f18, -0x610($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X610);
    // 0x8022D240: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8022D244: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D248: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8022D24C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8022D250: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x8022D254: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8022D258: ldc1        $f16, -0x608($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X608);
    // 0x8022D25C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D260: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8022D264: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8022D268: nop

    // 0x8022D26C: bc1fl       L_8022D2D8
    if (!c1cs) {
        // 0x8022D270: swc1        $f2, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
            goto L_8022D2D8;
    }
    goto skip_10;
    // 0x8022D270: swc1        $f2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
    skip_10:
    // 0x8022D274: lwc1        $f12, -0x600($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X600);
    // 0x8022D278: swc1        $f12, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f12.u32l;
    // 0x8022D27C: b           L_8022D2D4
    // 0x8022D280: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
        goto L_8022D2D4;
    // 0x8022D280: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
L_8022D284:
    // 0x8022D284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022D288: bne         $v0, $at, L_8022D2D4
    if (ctx->r2 != ctx->r1) {
        // 0x8022D28C: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_8022D2D4;
    }
    // 0x8022D28C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D290: ldc1        $f18, -0x5F8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X5F8);
    // 0x8022D294: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8022D298: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D29C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8022D2A0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8022D2A4: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x8022D2A8: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8022D2AC: ldc1        $f16, -0x5F0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X5F0);
    // 0x8022D2B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D2B4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8022D2B8: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8022D2BC: nop

    // 0x8022D2C0: bc1fl       L_8022D2D8
    if (!c1cs) {
        // 0x8022D2C4: swc1        $f2, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
            goto L_8022D2D8;
    }
    goto skip_11;
    // 0x8022D2C4: swc1        $f2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
    skip_11:
    // 0x8022D2C8: lwc1        $f12, -0x5E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5E8);
    // 0x8022D2CC: swc1        $f12, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f12.u32l;
    // 0x8022D2D0: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
L_8022D2D4:
    // 0x8022D2D4: swc1        $f2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
L_8022D2D8:
    // 0x8022D2D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8022D2DC:
    // 0x8022D2DC: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022D2E0: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x8022D2E4: slti        $at, $a2, 0x22
    ctx->r1 = SIGNED(ctx->r6) < 0X22 ? 1 : 0;
    // 0x8022D2E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8022D2EC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022D2F0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022D2F4: mflo        $t9
    ctx->r25 = lo;
    // 0x8022D2F8: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x8022D2FC: swl         $t7, 0xA8($v0)
    do_swl(rdram, 0XA8, ctx->r2, ctx->r15);
    // 0x8022D300: swr         $t7, 0xAB($v0)
    do_swr(rdram, 0XAB, ctx->r2, ctx->r15);
    // 0x8022D304: lhu         $t7, 0x4($ra)
    ctx->r15 = MEM_HU(ctx->r31, 0X4);
    // 0x8022D308: beq         $at, $zero, L_8022D31C
    if (ctx->r1 == 0) {
        // 0x8022D30C: sh          $t7, 0xAC($v0)
        MEM_H(0XAC, ctx->r2) = ctx->r15;
            goto L_8022D31C;
    }
    // 0x8022D30C: sh          $t7, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r15;
    // 0x8022D310: lw          $t8, 0x334($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X334);
    // 0x8022D314: lbu         $t9, 0x26($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X26);
    // 0x8022D318: sh          $t9, 0xAA($v0)
    MEM_H(0XAA, ctx->r2) = ctx->r25;
L_8022D31C:
    // 0x8022D31C: slti        $at, $a2, 0x56
    ctx->r1 = SIGNED(ctx->r6) < 0X56 ? 1 : 0;
    // 0x8022D320: bne         $at, $zero, L_8022D2DC
    if (ctx->r1 != 0) {
        // 0x8022D324: nop
    
            goto L_8022D2DC;
    }
    // 0x8022D324: nop

    // 0x8022D328: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
    // 0x8022D32C: sb          $zero, 0x38F($a3)
    MEM_B(0X38F, ctx->r7) = 0;
    // 0x8022D330: sb          $zero, 0x38E($a3)
    MEM_B(0X38E, ctx->r7) = 0;
    // 0x8022D334: addiu       $a0, $t1, 0x66
    ctx->r4 = ADD32(ctx->r9, 0X66);
    // 0x8022D338: addiu       $a1, $t1, 0x83
    ctx->r5 = ADD32(ctx->r9, 0X83);
    // 0x8022D33C: sb          $zero, 0x38D($a3)
    MEM_B(0X38D, ctx->r7) = 0;
    // 0x8022D340: sb          $zero, 0x38A($a3)
    MEM_B(0X38A, ctx->r7) = 0;
    // 0x8022D344: sb          $zero, 0x387($a3)
    MEM_B(0X387, ctx->r7) = 0;
    // 0x8022D348: sb          $zero, 0x38C($a3)
    MEM_B(0X38C, ctx->r7) = 0;
    // 0x8022D34C: sb          $zero, 0x389($a3)
    MEM_B(0X389, ctx->r7) = 0;
    // 0x8022D350: sb          $zero, 0x386($a3)
    MEM_B(0X386, ctx->r7) = 0;
    // 0x8022D354: sb          $zero, 0x38B($a3)
    MEM_B(0X38B, ctx->r7) = 0;
    // 0x8022D358: sb          $zero, 0x388($a3)
    MEM_B(0X388, ctx->r7) = 0;
    // 0x8022D35C: sb          $zero, 0x385($a3)
    MEM_B(0X385, ctx->r7) = 0;
    // 0x8022D360: addiu       $t1, $zero, 0x57
    ctx->r9 = ADD32(0, 0X57);
    // 0x8022D364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022D368: addiu       $ra, $zero, 0xC8
    ctx->r31 = ADD32(0, 0XC8);
    // 0x8022D36C: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x8022D370: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
L_8022D374:
    // 0x8022D374: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8022D378: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    // 0x8022D37C: beq         $t1, $v1, L_8022D57C
    if (ctx->r9 == ctx->r3) {
        // 0x8022D380: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8022D57C;
    }
    // 0x8022D380: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8022D384: beq         $at, $zero, L_8022D390
    if (ctx->r1 == 0) {
        // 0x8022D388: slti        $at, $v0, 0x25
        ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
            goto L_8022D390;
    }
    // 0x8022D388: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
    // 0x8022D38C: beq         $at, $zero, L_8022D3E4
    if (ctx->r1 == 0) {
        // 0x8022D390: slti        $at, $a2, 0x11
        ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
            goto L_8022D3E4;
    }
L_8022D390:
    // 0x8022D390: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    // 0x8022D394: bne         $at, $zero, L_8022D3B0
    if (ctx->r1 != 0) {
        // 0x8022D398: slti        $at, $a2, 0x17
        ctx->r1 = SIGNED(ctx->r6) < 0X17 ? 1 : 0;
            goto L_8022D3B0;
    }
    // 0x8022D398: slti        $at, $a2, 0x17
    ctx->r1 = SIGNED(ctx->r6) < 0X17 ? 1 : 0;
    // 0x8022D39C: beq         $at, $zero, L_8022D3B0
    if (ctx->r1 == 0) {
        // 0x8022D3A0: slti        $at, $v0, 0x4E
        ctx->r1 = SIGNED(ctx->r2) < 0X4E ? 1 : 0;
            goto L_8022D3B0;
    }
    // 0x8022D3A0: slti        $at, $v0, 0x4E
    ctx->r1 = SIGNED(ctx->r2) < 0X4E ? 1 : 0;
    // 0x8022D3A4: bnel        $at, $zero, L_8022D3B4
    if (ctx->r1 != 0) {
        // 0x8022D3A8: slti        $at, $a2, 0x19
        ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
            goto L_8022D3B4;
    }
    goto skip_12;
    // 0x8022D3A8: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
    skip_12:
    // 0x8022D3AC: bne         $t2, $v0, L_8022D3E4
    if (ctx->r10 != ctx->r2) {
        // 0x8022D3B0: slti        $at, $a2, 0x19
        ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
            goto L_8022D3E4;
    }
L_8022D3B0:
    // 0x8022D3B0: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
L_8022D3B4:
    // 0x8022D3B4: bne         $at, $zero, L_8022D3C4
    if (ctx->r1 != 0) {
        // 0x8022D3B8: slti        $at, $v0, 0x3E
        ctx->r1 = SIGNED(ctx->r2) < 0X3E ? 1 : 0;
            goto L_8022D3C4;
    }
    // 0x8022D3B8: slti        $at, $v0, 0x3E
    ctx->r1 = SIGNED(ctx->r2) < 0X3E ? 1 : 0;
    // 0x8022D3BC: bnel        $at, $zero, L_8022D3E8
    if (ctx->r1 != 0) {
        // 0x8022D3C0: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_8022D3E8;
    }
    goto skip_13;
    // 0x8022D3C0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_13:
L_8022D3C4:
    // 0x8022D3C4: beq         $a2, $t3, L_8022D3D4
    if (ctx->r6 == ctx->r11) {
        // 0x8022D3C8: slti        $at, $v0, 0x4E
        ctx->r1 = SIGNED(ctx->r2) < 0X4E ? 1 : 0;
            goto L_8022D3D4;
    }
    // 0x8022D3C8: slti        $at, $v0, 0x4E
    ctx->r1 = SIGNED(ctx->r2) < 0X4E ? 1 : 0;
    // 0x8022D3CC: bnel        $a2, $t5, L_8022D40C
    if (ctx->r6 != ctx->r13) {
        // 0x8022D3D0: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_8022D40C;
    }
    goto skip_14;
    // 0x8022D3D0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_14:
L_8022D3D4:
    // 0x8022D3D4: bne         $at, $zero, L_8022D3E4
    if (ctx->r1 != 0) {
        // 0x8022D3D8: slti        $at, $v0, 0x3E
        ctx->r1 = SIGNED(ctx->r2) < 0X3E ? 1 : 0;
            goto L_8022D3E4;
    }
    // 0x8022D3D8: slti        $at, $v0, 0x3E
    ctx->r1 = SIGNED(ctx->r2) < 0X3E ? 1 : 0;
    // 0x8022D3DC: bnel        $at, $zero, L_8022D40C
    if (ctx->r1 != 0) {
        // 0x8022D3E0: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_8022D40C;
    }
    goto skip_15;
    // 0x8022D3E0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_15:
L_8022D3E4:
    // 0x8022D3E4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
L_8022D3E8:
    // 0x8022D3E8: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8022D3EC: beql        $at, $zero, L_8022D40C
    if (ctx->r1 == 0) {
        // 0x8022D3F0: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_8022D40C;
    }
    goto skip_16;
    // 0x8022D3F0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_16:
    // 0x8022D3F4: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022D3F8: mflo        $t6
    ctx->r14 = lo;
    // 0x8022D3FC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8022D400: b           L_8022D57C
    // 0x8022D404: sh          $v0, 0xAA($t7)
    MEM_H(0XAA, ctx->r15) = ctx->r2;
        goto L_8022D57C;
    // 0x8022D404: sh          $v0, 0xAA($t7)
    MEM_H(0XAA, ctx->r15) = ctx->r2;
    // 0x8022D408: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
L_8022D40C:
    // 0x8022D40C: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8022D410: beq         $at, $zero, L_8022D568
    if (ctx->r1 == 0) {
        // 0x8022D414: slti        $at, $a2, 0x3
        ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
            goto L_8022D568;
    }
    // 0x8022D414: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8022D418: beql        $at, $zero, L_8022D434
    if (ctx->r1 == 0) {
        // 0x8022D41C: slti        $at, $a2, 0x6
        ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
            goto L_8022D434;
    }
    goto skip_17;
    // 0x8022D41C: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    skip_17:
    // 0x8022D420: lbu         $t8, 0x385($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X385);
    // 0x8022D424: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022D428: b           L_8022D538
    // 0x8022D42C: sb          $t9, 0x385($a3)
    MEM_B(0X385, ctx->r7) = ctx->r25;
        goto L_8022D538;
    // 0x8022D42C: sb          $t9, 0x385($a3)
    MEM_B(0X385, ctx->r7) = ctx->r25;
    // 0x8022D430: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
L_8022D434:
    // 0x8022D434: beql        $at, $zero, L_8022D450
    if (ctx->r1 == 0) {
        // 0x8022D438: slti        $at, $a2, 0x7
        ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
            goto L_8022D450;
    }
    goto skip_18;
    // 0x8022D438: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    skip_18:
    // 0x8022D43C: lbu         $t6, 0x386($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X386);
    // 0x8022D440: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8022D444: b           L_8022D538
    // 0x8022D448: sb          $t7, 0x386($a3)
    MEM_B(0X386, ctx->r7) = ctx->r15;
        goto L_8022D538;
    // 0x8022D448: sb          $t7, 0x386($a3)
    MEM_B(0X386, ctx->r7) = ctx->r15;
    // 0x8022D44C: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
L_8022D450:
    // 0x8022D450: beql        $at, $zero, L_8022D46C
    if (ctx->r1 == 0) {
        // 0x8022D454: slti        $at, $a2, 0xC
        ctx->r1 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
            goto L_8022D46C;
    }
    goto skip_19;
    // 0x8022D454: slti        $at, $a2, 0xC
    ctx->r1 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
    skip_19:
    // 0x8022D458: lbu         $t8, 0x387($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X387);
    // 0x8022D45C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022D460: b           L_8022D538
    // 0x8022D464: sb          $t9, 0x387($a3)
    MEM_B(0X387, ctx->r7) = ctx->r25;
        goto L_8022D538;
    // 0x8022D464: sb          $t9, 0x387($a3)
    MEM_B(0X387, ctx->r7) = ctx->r25;
    // 0x8022D468: slti        $at, $a2, 0xC
    ctx->r1 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
L_8022D46C:
    // 0x8022D46C: beql        $at, $zero, L_8022D488
    if (ctx->r1 == 0) {
        // 0x8022D470: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8022D488;
    }
    goto skip_20;
    // 0x8022D470: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_20:
    // 0x8022D474: lbu         $t6, 0x388($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X388);
    // 0x8022D478: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8022D47C: b           L_8022D538
    // 0x8022D480: sb          $t7, 0x388($a3)
    MEM_B(0X388, ctx->r7) = ctx->r15;
        goto L_8022D538;
    // 0x8022D480: sb          $t7, 0x388($a3)
    MEM_B(0X388, ctx->r7) = ctx->r15;
    // 0x8022D484: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8022D488:
    // 0x8022D488: beql        $at, $zero, L_8022D4A4
    if (ctx->r1 == 0) {
        // 0x8022D48C: slti        $at, $a2, 0x11
        ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
            goto L_8022D4A4;
    }
    goto skip_21;
    // 0x8022D48C: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    skip_21:
    // 0x8022D490: lbu         $t8, 0x389($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X389);
    // 0x8022D494: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022D498: b           L_8022D538
    // 0x8022D49C: sb          $t9, 0x389($a3)
    MEM_B(0X389, ctx->r7) = ctx->r25;
        goto L_8022D538;
    // 0x8022D49C: sb          $t9, 0x389($a3)
    MEM_B(0X389, ctx->r7) = ctx->r25;
    // 0x8022D4A0: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
L_8022D4A4:
    // 0x8022D4A4: beql        $at, $zero, L_8022D4C0
    if (ctx->r1 == 0) {
        // 0x8022D4A8: slti        $at, $a2, 0x14
        ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
            goto L_8022D4C0;
    }
    goto skip_22;
    // 0x8022D4A8: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    skip_22:
    // 0x8022D4AC: lbu         $t6, 0x38A($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X38A);
    // 0x8022D4B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8022D4B4: b           L_8022D538
    // 0x8022D4B8: sb          $t7, 0x38A($a3)
    MEM_B(0X38A, ctx->r7) = ctx->r15;
        goto L_8022D538;
    // 0x8022D4B8: sb          $t7, 0x38A($a3)
    MEM_B(0X38A, ctx->r7) = ctx->r15;
    // 0x8022D4BC: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
L_8022D4C0:
    // 0x8022D4C0: beql        $at, $zero, L_8022D4DC
    if (ctx->r1 == 0) {
        // 0x8022D4C4: slti        $at, $a2, 0x16
        ctx->r1 = SIGNED(ctx->r6) < 0X16 ? 1 : 0;
            goto L_8022D4DC;
    }
    goto skip_23;
    // 0x8022D4C4: slti        $at, $a2, 0x16
    ctx->r1 = SIGNED(ctx->r6) < 0X16 ? 1 : 0;
    skip_23:
    // 0x8022D4C8: lbu         $t8, 0x38B($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X38B);
    // 0x8022D4CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022D4D0: b           L_8022D538
    // 0x8022D4D4: sb          $t9, 0x38B($a3)
    MEM_B(0X38B, ctx->r7) = ctx->r25;
        goto L_8022D538;
    // 0x8022D4D4: sb          $t9, 0x38B($a3)
    MEM_B(0X38B, ctx->r7) = ctx->r25;
    // 0x8022D4D8: slti        $at, $a2, 0x16
    ctx->r1 = SIGNED(ctx->r6) < 0X16 ? 1 : 0;
L_8022D4DC:
    // 0x8022D4DC: beql        $at, $zero, L_8022D4F8
    if (ctx->r1 == 0) {
        // 0x8022D4E0: slti        $at, $a2, 0x17
        ctx->r1 = SIGNED(ctx->r6) < 0X17 ? 1 : 0;
            goto L_8022D4F8;
    }
    goto skip_24;
    // 0x8022D4E0: slti        $at, $a2, 0x17
    ctx->r1 = SIGNED(ctx->r6) < 0X17 ? 1 : 0;
    skip_24:
    // 0x8022D4E4: lbu         $t6, 0x38C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X38C);
    // 0x8022D4E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8022D4EC: b           L_8022D538
    // 0x8022D4F0: sb          $t7, 0x38C($a3)
    MEM_B(0X38C, ctx->r7) = ctx->r15;
        goto L_8022D538;
    // 0x8022D4F0: sb          $t7, 0x38C($a3)
    MEM_B(0X38C, ctx->r7) = ctx->r15;
    // 0x8022D4F4: slti        $at, $a2, 0x17
    ctx->r1 = SIGNED(ctx->r6) < 0X17 ? 1 : 0;
L_8022D4F8:
    // 0x8022D4F8: beql        $at, $zero, L_8022D514
    if (ctx->r1 == 0) {
        // 0x8022D4FC: slti        $at, $a2, 0x19
        ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
            goto L_8022D514;
    }
    goto skip_25;
    // 0x8022D4FC: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
    skip_25:
    // 0x8022D500: lbu         $t8, 0x38D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X38D);
    // 0x8022D504: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022D508: b           L_8022D538
    // 0x8022D50C: sb          $t9, 0x38D($a3)
    MEM_B(0X38D, ctx->r7) = ctx->r25;
        goto L_8022D538;
    // 0x8022D50C: sb          $t9, 0x38D($a3)
    MEM_B(0X38D, ctx->r7) = ctx->r25;
    // 0x8022D510: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
L_8022D514:
    // 0x8022D514: beql        $at, $zero, L_8022D530
    if (ctx->r1 == 0) {
        // 0x8022D518: lbu         $t8, 0x38F($a3)
        ctx->r24 = MEM_BU(ctx->r7, 0X38F);
            goto L_8022D530;
    }
    goto skip_26;
    // 0x8022D518: lbu         $t8, 0x38F($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X38F);
    skip_26:
    // 0x8022D51C: lbu         $t6, 0x38E($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X38E);
    // 0x8022D520: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8022D524: b           L_8022D538
    // 0x8022D528: sb          $t7, 0x38E($a3)
    MEM_B(0X38E, ctx->r7) = ctx->r15;
        goto L_8022D538;
    // 0x8022D528: sb          $t7, 0x38E($a3)
    MEM_B(0X38E, ctx->r7) = ctx->r15;
    // 0x8022D52C: lbu         $t8, 0x38F($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X38F);
L_8022D530:
    // 0x8022D530: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8022D534: sb          $t9, 0x38F($a3)
    MEM_B(0X38F, ctx->r7) = ctx->r25;
L_8022D538:
    // 0x8022D538: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8022D53C: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022D540: mflo        $t7
    ctx->r15 = lo;
    // 0x8022D544: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8022D548: sb          $t4, 0xA8($t8)
    MEM_B(0XA8, ctx->r24) = ctx->r12;
    // 0x8022D54C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8022D550: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8022D554: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022D558: mflo        $t7
    ctx->r15 = lo;
    // 0x8022D55C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8022D560: b           L_8022D57C
    // 0x8022D564: sh          $t9, 0xAA($t8)
    MEM_H(0XAA, ctx->r24) = ctx->r25;
        goto L_8022D57C;
    // 0x8022D564: sh          $t9, 0xAA($t8)
    MEM_H(0XAA, ctx->r24) = ctx->r25;
L_8022D568:
    // 0x8022D568: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022D56C: subu        $t6, $ra, $v0
    ctx->r14 = SUB32(ctx->r31, ctx->r2);
    // 0x8022D570: mflo        $t7
    ctx->r15 = lo;
    // 0x8022D574: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x8022D578: sh          $t6, 0xAA($t9)
    MEM_H(0XAA, ctx->r25) = ctx->r14;
L_8022D57C:
    // 0x8022D57C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8022D580: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022D584: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022D588: slti        $at, $a2, 0x1D
    ctx->r1 = SIGNED(ctx->r6) < 0X1D ? 1 : 0;
    // 0x8022D58C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8022D590: bne         $at, $zero, L_8022D374
    if (ctx->r1 != 0) {
        // 0x8022D594: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8022D374;
    }
    // 0x8022D594: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8022D598: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
    // 0x8022D59C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022D5A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022D5A4: lb          $t8, 0x50($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X50);
    // 0x8022D5A8: sh          $t8, 0x62($a3)
    MEM_H(0X62, ctx->r7) = ctx->r24;
    // 0x8022D5AC: lb          $t7, 0x51($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X51);
    // 0x8022D5B0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8022D5B4: sh          $t7, 0x64($a3)
    MEM_H(0X64, ctx->r7) = ctx->r15;
    // 0x8022D5B8: lbu         $v0, -0x43F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43F3);
    // 0x8022D5BC: bnel        $v0, $at, L_8022D740
    if (ctx->r2 != ctx->r1) {
        // 0x8022D5C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8022D740;
    }
    goto skip_27;
    // 0x8022D5C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_27:
    // 0x8022D5C4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8022D5C8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022D5CC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8022D5D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8022D5D4: bgez        $t6, L_8022D5F0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8022D5D8: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_8022D5F0;
    }
    // 0x8022D5D8: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8022D5DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022D5E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022D5E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022D5E8: nop

    // 0x8022D5EC: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_8022D5F0:
    // 0x8022D5F0: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8022D5F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022D5F8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022D5FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022D600: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022D604: nop

    // 0x8022D608: cvt.w.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022D60C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022D610: nop

    // 0x8022D614: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022D618: beql        $t8, $zero, L_8022D66C
    if (ctx->r24 == 0) {
        // 0x8022D61C: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_8022D66C;
    }
    goto skip_28;
    // 0x8022D61C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_28:
    // 0x8022D620: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022D624: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022D628: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022D62C: sub.d       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f8.d - ctx->f6.d;
    // 0x8022D630: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022D634: nop

    // 0x8022D638: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8022D63C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022D640: nop

    // 0x8022D644: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022D648: bne         $t8, $zero, L_8022D660
    if (ctx->r24 != 0) {
        // 0x8022D64C: nop
    
            goto L_8022D660;
    }
    // 0x8022D64C: nop

    // 0x8022D650: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8022D654: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022D658: b           L_8022D678
    // 0x8022D65C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8022D678;
    // 0x8022D65C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8022D660:
    // 0x8022D660: b           L_8022D678
    // 0x8022D664: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8022D678;
    // 0x8022D664: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8022D668: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_8022D66C:
    // 0x8022D66C: nop

    // 0x8022D670: bltz        $t8, L_8022D660
    if (SIGNED(ctx->r24) < 0) {
        // 0x8022D674: nop
    
            goto L_8022D660;
    }
    // 0x8022D674: nop

L_8022D678:
    // 0x8022D678: lhu         $t7, 0x64($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X64);
    // 0x8022D67C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022D680: sh          $t8, 0x62($a3)
    MEM_H(0X62, ctx->r7) = ctx->r24;
    // 0x8022D684: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8022D688: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022D68C: bgez        $t7, L_8022D6A4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8022D690: cvt.d.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.d = CVT_D_W(ctx->f16.u32l);
            goto L_8022D6A4;
    }
    // 0x8022D690: cvt.d.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.d = CVT_D_W(ctx->f16.u32l);
    // 0x8022D694: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022D698: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022D69C: nop

    // 0x8022D6A0: add.d       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f10.d + ctx->f4.d;
L_8022D6A4:
    // 0x8022D6A4: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8022D6A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8022D6AC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022D6B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022D6B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022D6B8: nop

    // 0x8022D6BC: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022D6C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022D6C4: nop

    // 0x8022D6C8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8022D6CC: beql        $t9, $zero, L_8022D720
    if (ctx->r25 == 0) {
        // 0x8022D6D0: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_8022D720;
    }
    goto skip_29;
    // 0x8022D6D0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_29:
    // 0x8022D6D4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022D6D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022D6DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8022D6E0: sub.d       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f18.d - ctx->f8.d;
    // 0x8022D6E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022D6E8: nop

    // 0x8022D6EC: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022D6F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022D6F4: nop

    // 0x8022D6F8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8022D6FC: bne         $t9, $zero, L_8022D714
    if (ctx->r25 != 0) {
        // 0x8022D700: nop
    
            goto L_8022D714;
    }
    // 0x8022D700: nop

    // 0x8022D704: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8022D708: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022D70C: b           L_8022D72C
    // 0x8022D710: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8022D72C;
    // 0x8022D710: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8022D714:
    // 0x8022D714: b           L_8022D72C
    // 0x8022D718: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8022D72C;
    // 0x8022D718: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8022D71C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_8022D720:
    // 0x8022D720: nop

    // 0x8022D724: bltz        $t9, L_8022D714
    if (SIGNED(ctx->r25) < 0) {
        // 0x8022D728: nop
    
            goto L_8022D714;
    }
    // 0x8022D728: nop

L_8022D72C:
    // 0x8022D72C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022D730: sh          $t9, 0x64($a3)
    MEM_H(0X64, ctx->r7) = ctx->r25;
    // 0x8022D734: b           L_8022D8B4
    // 0x8022D738: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
        goto L_8022D8B4;
    // 0x8022D738: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
    // 0x8022D73C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8022D740:
    // 0x8022D740: bnel        $v0, $at, L_8022D8B8
    if (ctx->r2 != ctx->r1) {
        // 0x8022D744: lh          $t6, 0x8($a3)
        ctx->r14 = MEM_H(ctx->r7, 0X8);
            goto L_8022D8B8;
    }
    goto skip_30;
    // 0x8022D744: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    skip_30:
    // 0x8022D748: lhu         $t8, 0x62($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X62);
    // 0x8022D74C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022D750: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8022D754: bgez        $t8, L_8022D76C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8022D758: cvt.d.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.d = CVT_D_W(ctx->f6.u32l);
            goto L_8022D76C;
    }
    // 0x8022D758: cvt.d.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022D75C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022D760: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022D764: nop

    // 0x8022D768: add.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = ctx->f0.d + ctx->f16.d;
L_8022D76C:
    // 0x8022D76C: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8022D770: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022D774: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022D778: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8022D77C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022D780: nop

    // 0x8022D784: cvt.w.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022D788: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022D78C: nop

    // 0x8022D790: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022D794: beql        $t6, $zero, L_8022D7E8
    if (ctx->r14 == 0) {
        // 0x8022D798: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_8022D7E8;
    }
    goto skip_31;
    // 0x8022D798: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_31:
    // 0x8022D79C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022D7A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022D7A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022D7A8: sub.d       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f4.d - ctx->f10.d;
    // 0x8022D7AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022D7B0: nop

    // 0x8022D7B4: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022D7B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022D7BC: nop

    // 0x8022D7C0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022D7C4: bne         $t6, $zero, L_8022D7DC
    if (ctx->r14 != 0) {
        // 0x8022D7C8: nop
    
            goto L_8022D7DC;
    }
    // 0x8022D7C8: nop

    // 0x8022D7CC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8022D7D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022D7D4: b           L_8022D7F4
    // 0x8022D7D8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8022D7F4;
    // 0x8022D7D8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8022D7DC:
    // 0x8022D7DC: b           L_8022D7F4
    // 0x8022D7E0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8022D7F4;
    // 0x8022D7E0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8022D7E4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_8022D7E8:
    // 0x8022D7E8: nop

    // 0x8022D7EC: bltz        $t6, L_8022D7DC
    if (SIGNED(ctx->r14) < 0) {
        // 0x8022D7F0: nop
    
            goto L_8022D7DC;
    }
    // 0x8022D7F0: nop

L_8022D7F4:
    // 0x8022D7F4: lhu         $t9, 0x64($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X64);
    // 0x8022D7F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8022D7FC: sh          $t6, 0x62($a3)
    MEM_H(0X62, ctx->r7) = ctx->r14;
    // 0x8022D800: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8022D804: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022D808: bgez        $t9, L_8022D820
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8022D80C: cvt.d.w     $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.d = CVT_D_W(ctx->f18.u32l);
            goto L_8022D820;
    }
    // 0x8022D80C: cvt.d.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.d = CVT_D_W(ctx->f18.u32l);
    // 0x8022D810: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022D814: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022D818: nop

    // 0x8022D81C: add.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d + ctx->f8.d;
L_8022D820:
    // 0x8022D820: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x8022D824: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8022D828: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022D82C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022D830: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8022D834: nop

    // 0x8022D838: cvt.w.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_D(ctx->f6.d);
    // 0x8022D83C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8022D840: nop

    // 0x8022D844: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8022D848: beql        $t7, $zero, L_8022D89C
    if (ctx->r15 == 0) {
        // 0x8022D84C: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_8022D89C;
    }
    goto skip_32;
    // 0x8022D84C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_32:
    // 0x8022D850: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022D854: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022D858: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8022D85C: sub.d       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f6.d - ctx->f16.d;
    // 0x8022D860: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8022D864: nop

    // 0x8022D868: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022D86C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8022D870: nop

    // 0x8022D874: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8022D878: bne         $t7, $zero, L_8022D890
    if (ctx->r15 != 0) {
        // 0x8022D87C: nop
    
            goto L_8022D890;
    }
    // 0x8022D87C: nop

    // 0x8022D880: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8022D884: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022D888: b           L_8022D8A8
    // 0x8022D88C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8022D8A8;
    // 0x8022D88C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8022D890:
    // 0x8022D890: b           L_8022D8A8
    // 0x8022D894: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8022D8A8;
    // 0x8022D894: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8022D898: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_8022D89C:
    // 0x8022D89C: nop

    // 0x8022D8A0: bltz        $t7, L_8022D890
    if (SIGNED(ctx->r15) < 0) {
        // 0x8022D8A4: nop
    
            goto L_8022D890;
    }
    // 0x8022D8A4: nop

L_8022D8A8:
    // 0x8022D8A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022D8AC: sh          $t7, 0x64($a3)
    MEM_H(0X64, ctx->r7) = ctx->r15;
    // 0x8022D8B0: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
L_8022D8B4:
    // 0x8022D8B4: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
L_8022D8B8:
    // 0x8022D8B8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D8BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8022D8C0: sh          $t6, 0x4A($a3)
    MEM_H(0X4A, ctx->r7) = ctx->r14;
    // 0x8022D8C4: lh          $t9, 0x52($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X52);
    // 0x8022D8C8: ldc1        $f18, -0x5E0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X5E0);
    // 0x8022D8CC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8022D8D0: nop

    // 0x8022D8D4: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022D8D8: div.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8022D8DC: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x8022D8E0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8022D8E4: nop

    // 0x8022D8E8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8022D8EC: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8022D8F0: bgez        $t9, L_8022D900
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8022D8F4: sra         $t8, $t9, 1
        ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8022D900;
    }
    // 0x8022D8F4: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8022D8F8: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8022D8FC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8022D900:
    // 0x8022D900: sh          $t8, 0x310($a3)
    MEM_H(0X310, ctx->r7) = ctx->r24;
    // 0x8022D904: lbu         $t7, 0x54($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X54);
    // 0x8022D908: sb          $t7, 0x332($a3)
    MEM_B(0X332, ctx->r7) = ctx->r15;
    // 0x8022D90C: jal         0x8022C314
    // 0x8022D910: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8022C314)(rdram, ctx);
        goto after_2;
    // 0x8022D910: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8022D914: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8022D918: lw          $t1, 0x334($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X334);
    // 0x8022D91C: lbu         $t6, 0x55($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X55);
    // 0x8022D920: sb          $t6, 0x384($a3)
    MEM_B(0X384, ctx->r7) = ctx->r14;
    // 0x8022D924: lbu         $t9, 0x57($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X57);
    // 0x8022D928: sb          $t9, 0xA2($a3)
    MEM_B(0XA2, ctx->r7) = ctx->r25;
    // 0x8022D92C: lbu         $t8, 0x58($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X58);
    // 0x8022D930: sb          $t8, 0xA3($a3)
    MEM_B(0XA3, ctx->r7) = ctx->r24;
    // 0x8022D934: lbu         $t7, 0x59($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X59);
    // 0x8022D938: sb          $t7, 0xA4($a3)
    MEM_B(0XA4, ctx->r7) = ctx->r15;
    // 0x8022D93C: lbu         $t6, 0x5A($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X5A);
    // 0x8022D940: sb          $t6, 0xA5($a3)
    MEM_B(0XA5, ctx->r7) = ctx->r14;
    // 0x8022D944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022D948: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8022D94C: jr          $ra
    // 0x8022D950: nop

    return;
    // 0x8022D950: nop

;}
RECOMP_FUNC void M10_FUN_8022d954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022D954: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022D958: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022d95c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022d95c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022D95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022D960: addiu       $t6, $v0, 0x44C
    ctx->r14 = ADD32(ctx->r2, 0X44C);
    // 0x8022D964: bne         $a0, $t6, L_8022D9A4
    if (ctx->r4 != ctx->r14) {
        // 0x8022D968: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8022D9A4;
    }
    // 0x8022D968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022D96C: lhu         $a0, 0x30($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X30);
    // 0x8022D970: sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4 << 7);
    // 0x8022D974: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022D978: jal         0x8001EAD0
    // 0x8022D97C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8022D97C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8022D980: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D984: lwc1        $f4, -0x5D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5D8);
    // 0x8022D988: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8022D98C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8022D990: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8022D994: nop

    // 0x8022D998: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8022D99C: b           L_8022D9DC
    // 0x8022D9A0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8022D9DC;
    // 0x8022D9A0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8022D9A4:
    // 0x8022D9A4: lhu         $a0, 0x30($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X30);
    // 0x8022D9A8: sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4 << 7);
    // 0x8022D9AC: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8022D9B0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022D9B4: jal         0x8001EAD0
    // 0x8022D9B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8022D9B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8022D9BC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022D9C0: lwc1        $f10, -0x5D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5D4);
    // 0x8022D9C4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8022D9C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8022D9CC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8022D9D0: nop

    // 0x8022D9D4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8022D9D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8022D9DC:
    // 0x8022D9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022D9E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022D9E4: jr          $ra
    // 0x8022D9E8: nop

    return;
    // 0x8022D9E8: nop

;}
RECOMP_FUNC void M10_FUN_8022d9ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022D9EC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022D9F0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022d9f4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022d9f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022D9F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022D9F8: addiu       $t6, $v0, 0x44C
    ctx->r14 = ADD32(ctx->r2, 0X44C);
    // 0x8022D9FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022DA00: bne         $a0, $t6, L_8022DA34
    if (ctx->r4 != ctx->r14) {
        // 0x8022DA04: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8022DA34;
    }
    // 0x8022DA04: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8022DA08: lh          $a0, 0x30($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X30);
    // 0x8022DA0C: jal         0x8001EAD0
    // 0x8022DA10: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8022DA10: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8022DA14: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022DA18: lwc1        $f4, -0x5D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5D0);
    // 0x8022DA1C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8022DA20: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8022DA24: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8022DA28: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8022DA2C: b           L_8022DA6C
    // 0x8022DA30: sb          $t8, 0x2D($a1)
    MEM_B(0X2D, ctx->r5) = ctx->r24;
        goto L_8022DA6C;
    // 0x8022DA30: sb          $t8, 0x2D($a1)
    MEM_B(0X2D, ctx->r5) = ctx->r24;
L_8022DA34:
    // 0x8022DA34: lhu         $a0, 0x30($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X30);
    // 0x8022DA38: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8022DA3C: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8022DA40: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022DA44: jal         0x8001EAD0
    // 0x8022DA48: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8022DA48: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8022DA4C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022DA50: lwc1        $f10, -0x5CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5CC);
    // 0x8022DA54: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8022DA58: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8022DA5C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8022DA60: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8022DA64: nop

    // 0x8022DA68: sb          $t0, 0x2D($a1)
    MEM_B(0X2D, ctx->r5) = ctx->r8;
L_8022DA6C:
    // 0x8022DA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022DA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022DA74: jr          $ra
    // 0x8022DA78: nop

    return;
    // 0x8022DA78: nop

;}
RECOMP_FUNC void M10_FUN_8022da7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022DA7C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8022DA80: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022DA84: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8022DA88: lw          $v1, 0xDC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XDC);
    // 0x8022DA8C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8022DA90: bne         $a0, $v1, L_8022DAA0
    if (ctx->r4 != ctx->r3) {
        // 0x8022DA94: lh          $v0, 0x12($t7)
        ctx->r2 = MEM_H(ctx->r15, 0X12);
            goto L_8022DAA0;
    }
    // 0x8022DA94: lh          $v0, 0x12($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X12);
    // 0x8022DA98: b           L_8022DAA4
    // 0x8022DA9C: lh          $a1, 0x75C($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X75C);
        goto L_8022DAA4;
    // 0x8022DA9C: lh          $a1, 0x75C($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X75C);
L_8022DAA0:
    // 0x8022DAA0: lh          $a1, 0xAF8($a2)
    ctx->r5 = MEM_H(ctx->r6, 0XAF8);
L_8022DAA4:
    // 0x8022DAA4: bnel        $a0, $v1, L_8022DAB8
    if (ctx->r4 != ctx->r3) {
        // 0x8022DAA8: lh          $v1, 0xB98($a2)
        ctx->r3 = MEM_H(ctx->r6, 0XB98);
            goto L_8022DAB8;
    }
    goto skip_0;
    // 0x8022DAA8: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
    skip_0:
    // 0x8022DAAC: b           L_8022DAC4
    // 0x8022DAB0: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
        goto L_8022DAC4;
    // 0x8022DAB0: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
    // 0x8022DAB4: lh          $v1, 0xB98($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XB98);
L_8022DAB8:
    // 0x8022DAB8: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x8022DABC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8022DAC0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8022DAC4:
    // 0x8022DAC4: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // 0x8022DAC8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8022DACC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022DAD0: andi        $a2, $a0, 0x1000
    ctx->r6 = ctx->r4 & 0X1000;
    // 0x8022DAD4: beq         $a2, $zero, L_8022DAE8
    if (ctx->r6 == 0) {
        // 0x8022DAD8: andi        $v1, $a0, 0x1FFF
        ctx->r3 = ctx->r4 & 0X1FFF;
            goto L_8022DAE8;
    }
    // 0x8022DAD8: andi        $v1, $a0, 0x1FFF
    ctx->r3 = ctx->r4 & 0X1FFF;
    // 0x8022DADC: andi        $v1, $a0, 0x1FFF
    ctx->r3 = ctx->r4 & 0X1FFF;
    // 0x8022DAE0: b           L_8022DAEC
    // 0x8022DAE4: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
        goto L_8022DAEC;
    // 0x8022DAE4: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
L_8022DAE8:
    // 0x8022DAE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8022DAEC:
    // 0x8022DAEC: bgez        $v0, L_8022DB10
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022DAF0: nop
    
            goto L_8022DB10;
    }
    // 0x8022DAF0: nop

    // 0x8022DAF4: beq         $a2, $zero, L_8022DB08
    if (ctx->r6 == 0) {
        // 0x8022DAF8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8022DB08;
    }
    // 0x8022DAF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8022DAFC: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
    // 0x8022DB00: b           L_8022DB24
    // 0x8022DB04: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8022DB24;
    // 0x8022DB04: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8022DB08:
    // 0x8022DB08: b           L_8022DB24
    // 0x8022DB0C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8022DB24;
    // 0x8022DB0C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8022DB10:
    // 0x8022DB10: beq         $a2, $zero, L_8022DB20
    if (ctx->r6 == 0) {
        // 0x8022DB14: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8022DB20;
    }
    // 0x8022DB14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8022DB18: b           L_8022DB20
    // 0x8022DB1C: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
        goto L_8022DB20;
    // 0x8022DB1C: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
L_8022DB20:
    // 0x8022DB20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8022DB24:
    // 0x8022DB24: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8022DB28: beq         $at, $zero, L_8022DB38
    if (ctx->r1 == 0) {
            // 0x8022DB2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x8022DB38)(rdram, ctx);
    return;
    }
    // 0x8022DB2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022DB30: jr          $ra
    // 0x8022DB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8022DB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022db38(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022db38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022DB38: jr          $ra
    // 0x8022DB3C: nop

    return;
    // 0x8022DB3C: nop

;}
RECOMP_FUNC void M10_FUN_8022db40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022DB40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8022DB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022DB48: lw          $t0, 0x2D4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2D4);
    // 0x8022DB4C: lhu         $t1, 0x82($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X82);
    // 0x8022DB50: lhu         $v0, 0x84($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X84);
    // 0x8022DB54: lbu         $t6, 0x9($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X9);
    // 0x8022DB58: lhu         $v1, 0x86($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X86);
    // 0x8022DB5C: lhu         $a3, 0x88($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X88);
    // 0x8022DB60: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8022DB64: lhu         $a1, 0x8A($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X8A);
    // 0x8022DB68: beq         $at, $zero, L_8022EB40
    if (ctx->r1 == 0) {
        // 0x8022DB6C: lhu         $a2, 0x8C($a0)
        ctx->r6 = MEM_HU(ctx->r4, 0X8C);
            goto L_8022EB40;
    }
    // 0x8022DB6C: lhu         $a2, 0x8C($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X8C);
    // 0x8022DB70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8022DB74: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022DB78: addu        $at, $at, $t6
    gpr jr_addend_8022DB80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8022DB7C: lw          $t6, -0x5C8($at)
    ctx->r14 = ADD32(ctx->r1, -0X5C8);
    // 0x8022DB80: jr          $t6
    // 0x8022DB84: nop

    switch (jr_addend_8022DB80 >> 2) {
        case 0: goto L_8022DB88; break;
        case 1: goto L_8022DDD8; break;
        case 2: goto L_8022E028; break;
        case 3: goto L_8022E150; break;
        case 4: goto L_8022E278; break;
        case 5: goto L_8022E36C; break;
        case 6: goto L_8022E48C; break;
        case 7: goto L_8022E5E8; break;
        case 8: goto L_8022E768; break;
        case 9: goto L_8022E890; break;
        case 10: goto L_8022E9A4; break;
        case 11: goto L_8022EB2C; break;
        default: switch_error(__func__, 0x8022DB80, 0x8023FA38);
    }
    // 0x8022DB84: nop

L_8022DB88:
    // 0x8022DB88: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8022DB8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022DB90: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8022DB94: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8022DB98: bnel        $t9, $at, L_8022DCC0
    if (ctx->r25 != ctx->r1) {
        // 0x8022DB9C: mtc1        $v1, $f10
        ctx->f10.u32l = ctx->r3;
            goto L_8022DCC0;
    }
    goto skip_0;
    // 0x8022DB9C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    skip_0:
    // 0x8022DBA0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8022DBA4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022DBA8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022DBAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022DBB0: bgez        $v1, L_8022DBC8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022DBB4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022DBC8;
    }
    // 0x8022DBB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022DBB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DBBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022DBC0: nop

    // 0x8022DBC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8022DBC8:
    // 0x8022DBC8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022DBCC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022DBD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022DBD4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8022DBD8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8022DBDC: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8022DBE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DBE4: bgez        $a1, L_8022DBF8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022DBE8: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022DBF8;
    }
    // 0x8022DBE8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022DBEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022DBF0: nop

    // 0x8022DBF4: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8022DBF8:
    // 0x8022DBF8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8022DBFC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8022DC00: mul.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8022DC04: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022DC08: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022DC0C: bgez        $v0, L_8022DC24
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022DC10: add.d       $f4, $f18, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
            goto L_8022DC24;
    }
    // 0x8022DC10: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x8022DC14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022DC18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022DC1C: nop

    // 0x8022DC20: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_8022DC24:
    // 0x8022DC24: add.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d + ctx->f8.d;
    // 0x8022DC28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022DC2C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022DC30: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x8022DC34: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022DC38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022DC3C: nop

    // 0x8022DC40: cvt.w.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022DC44: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022DC48: nop

    // 0x8022DC4C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8022DC50: beql        $t3, $zero, L_8022DCA4
    if (ctx->r11 == 0) {
        // 0x8022DC54: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_8022DCA4;
    }
    goto skip_1;
    // 0x8022DC54: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x8022DC58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022DC5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022DC60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022DC64: sub.d       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f16.d - ctx->f6.d;
    // 0x8022DC68: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022DC6C: nop

    // 0x8022DC70: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8022DC74: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022DC78: nop

    // 0x8022DC7C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8022DC80: bne         $t3, $zero, L_8022DC98
    if (ctx->r11 != 0) {
        // 0x8022DC84: nop
    
            goto L_8022DC98;
    }
    // 0x8022DC84: nop

    // 0x8022DC88: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8022DC8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022DC90: b           L_8022DCB0
    // 0x8022DC94: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8022DCB0;
    // 0x8022DC94: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8022DC98:
    // 0x8022DC98: b           L_8022DCB0
    // 0x8022DC9C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8022DCB0;
    // 0x8022DC9C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8022DCA0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_8022DCA4:
    // 0x8022DCA4: nop

    // 0x8022DCA8: bltz        $t3, L_8022DC98
    if (SIGNED(ctx->r11) < 0) {
        // 0x8022DCAC: nop
    
            goto L_8022DC98;
    }
    // 0x8022DCAC: nop

L_8022DCB0:
    // 0x8022DCB0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022DCB4: b           L_8022EB50
    // 0x8022DCB8: sh          $t3, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r11;
        goto L_8022EB50;
    // 0x8022DCB8: sh          $t3, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r11;
    // 0x8022DCBC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
L_8022DCC0:
    // 0x8022DCC0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022DCC4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022DCC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022DCCC: bgez        $v1, L_8022DCE4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022DCD0: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8022DCE4;
    }
    // 0x8022DCD0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022DCD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DCD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022DCDC: nop

    // 0x8022DCE0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8022DCE4:
    // 0x8022DCE4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022DCE8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022DCEC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022DCF0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8022DCF4: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8022DCF8: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8022DCFC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DD00: bgez        $a2, L_8022DD14
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022DD04: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8022DD14;
    }
    // 0x8022DD04: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022DD08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022DD0C: nop

    // 0x8022DD10: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_8022DD14:
    // 0x8022DD14: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8022DD18: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8022DD1C: mul.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8022DD20: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022DD24: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022DD28: bgez        $v0, L_8022DD40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022DD2C: add.d       $f10, $f6, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f6.d + ctx->f16.d;
            goto L_8022DD40;
    }
    // 0x8022DD2C: add.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f6.d + ctx->f16.d;
    // 0x8022DD30: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022DD34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022DD38: nop

    // 0x8022DD3C: add.d       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f8.d + ctx->f18.d;
L_8022DD40:
    // 0x8022DD40: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x8022DD44: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8022DD48: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022DD4C: add.d       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f6.d + ctx->f2.d;
    // 0x8022DD50: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022DD54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8022DD58: nop

    // 0x8022DD5C: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022DD60: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8022DD64: nop

    // 0x8022DD68: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8022DD6C: beql        $t5, $zero, L_8022DDC0
    if (ctx->r13 == 0) {
        // 0x8022DD70: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_8022DDC0;
    }
    goto skip_2;
    // 0x8022DD70: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x8022DD74: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022DD78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022DD7C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8022DD80: sub.d       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f16.d - ctx->f4.d;
    // 0x8022DD84: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8022DD88: nop

    // 0x8022DD8C: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022DD90: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8022DD94: nop

    // 0x8022DD98: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8022DD9C: bne         $t5, $zero, L_8022DDB4
    if (ctx->r13 != 0) {
        // 0x8022DDA0: nop
    
            goto L_8022DDB4;
    }
    // 0x8022DDA0: nop

    // 0x8022DDA4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8022DDA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022DDAC: b           L_8022DDCC
    // 0x8022DDB0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8022DDCC;
    // 0x8022DDB0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8022DDB4:
    // 0x8022DDB4: b           L_8022DDCC
    // 0x8022DDB8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8022DDCC;
    // 0x8022DDB8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8022DDBC: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_8022DDC0:
    // 0x8022DDC0: nop

    // 0x8022DDC4: bltz        $t5, L_8022DDB4
    if (SIGNED(ctx->r13) < 0) {
        // 0x8022DDC8: nop
    
            goto L_8022DDB4;
    }
    // 0x8022DDC8: nop

L_8022DDCC:
    // 0x8022DDCC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022DDD0: b           L_8022EB50
    // 0x8022DDD4: sh          $t5, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r13;
        goto L_8022EB50;
    // 0x8022DDD4: sh          $t5, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r13;
L_8022DDD8:
    // 0x8022DDD8: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x8022DDDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022DDE0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8022DDE4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8022DDE8: bnel        $t8, $at, L_8022DF10
    if (ctx->r24 != ctx->r1) {
        // 0x8022DDEC: mtc1        $a3, $f6
        ctx->f6.u32l = ctx->r7;
            goto L_8022DF10;
    }
    goto skip_3;
    // 0x8022DDEC: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    skip_3:
    // 0x8022DDF0: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x8022DDF4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022DDF8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022DDFC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022DE00: bgez        $a3, L_8022DE18
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022DE04: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8022DE18;
    }
    // 0x8022DE04: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022DE08: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DE0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022DE10: nop

    // 0x8022DE14: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8022DE18:
    // 0x8022DE18: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022DE1C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022DE20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022DE24: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8022DE28: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x8022DE2C: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8022DE30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DE34: bgez        $a1, L_8022DE48
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022DE38: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8022DE48;
    }
    // 0x8022DE38: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022DE3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022DE40: nop

    // 0x8022DE44: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8022DE48:
    // 0x8022DE48: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8022DE4C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8022DE50: mul.d       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8022DE54: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022DE58: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x8022DE5C: bgez        $v0, L_8022DE74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022DE60: add.d       $f18, $f4, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
            goto L_8022DE74;
    }
    // 0x8022DE60: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x8022DE64: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022DE68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022DE6C: nop

    // 0x8022DE70: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_8022DE74:
    // 0x8022DE74: add.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f18.d + ctx->f8.d;
    // 0x8022DE78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022DE7C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022DE80: add.d       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f4.d + ctx->f2.d;
    // 0x8022DE84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022DE88: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022DE8C: nop

    // 0x8022DE90: cvt.w.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022DE94: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022DE98: nop

    // 0x8022DE9C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022DEA0: beql        $t2, $zero, L_8022DEF4
    if (ctx->r10 == 0) {
        // 0x8022DEA4: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_8022DEF4;
    }
    goto skip_4;
    // 0x8022DEA4: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x8022DEA8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022DEAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022DEB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022DEB4: sub.d       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f16.d - ctx->f10.d;
    // 0x8022DEB8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022DEBC: nop

    // 0x8022DEC0: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022DEC4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022DEC8: nop

    // 0x8022DECC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022DED0: bne         $t2, $zero, L_8022DEE8
    if (ctx->r10 != 0) {
        // 0x8022DED4: nop
    
            goto L_8022DEE8;
    }
    // 0x8022DED4: nop

    // 0x8022DED8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8022DEDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022DEE0: b           L_8022DF00
    // 0x8022DEE4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8022DF00;
    // 0x8022DEE4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8022DEE8:
    // 0x8022DEE8: b           L_8022DF00
    // 0x8022DEEC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8022DF00;
    // 0x8022DEEC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8022DEF0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_8022DEF4:
    // 0x8022DEF4: nop

    // 0x8022DEF8: bltz        $t2, L_8022DEE8
    if (SIGNED(ctx->r10) < 0) {
        // 0x8022DEFC: nop
    
            goto L_8022DEE8;
    }
    // 0x8022DEFC: nop

L_8022DF00:
    // 0x8022DF00: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022DF04: b           L_8022EB50
    // 0x8022DF08: sh          $t2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r10;
        goto L_8022EB50;
    // 0x8022DF08: sh          $t2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r10;
    // 0x8022DF0C: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
L_8022DF10:
    // 0x8022DF10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022DF14: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022DF18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022DF1C: bgez        $a3, L_8022DF34
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022DF20: cvt.s.w     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8022DF34;
    }
    // 0x8022DF20: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8022DF24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DF28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022DF2C: nop

    // 0x8022DF30: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_8022DF34:
    // 0x8022DF34: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022DF38: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022DF3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022DF40: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8022DF44: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8022DF48: mul.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8022DF4C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022DF50: bgez        $a2, L_8022DF64
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022DF54: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8022DF64;
    }
    // 0x8022DF54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8022DF58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8022DF5C: nop

    // 0x8022DF60: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8022DF64:
    // 0x8022DF64: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8022DF68: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8022DF6C: mul.d       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x8022DF70: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022DF74: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x8022DF78: bgez        $v0, L_8022DF90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022DF7C: add.d       $f6, $f10, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f10.d + ctx->f16.d;
            goto L_8022DF90;
    }
    // 0x8022DF7C: add.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f10.d + ctx->f16.d;
    // 0x8022DF80: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022DF84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022DF88: nop

    // 0x8022DF8C: add.d       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f8.d + ctx->f4.d;
L_8022DF90:
    // 0x8022DF90: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8022DF94: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022DF98: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022DF9C: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x8022DFA0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022DFA4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022DFA8: nop

    // 0x8022DFAC: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022DFB0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022DFB4: nop

    // 0x8022DFB8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8022DFBC: beql        $t4, $zero, L_8022E010
    if (ctx->r12 == 0) {
        // 0x8022DFC0: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_8022E010;
    }
    goto skip_5;
    // 0x8022DFC0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x8022DFC4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022DFC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022DFCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022DFD0: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x8022DFD4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022DFD8: nop

    // 0x8022DFDC: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022DFE0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022DFE4: nop

    // 0x8022DFE8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8022DFEC: bne         $t4, $zero, L_8022E004
    if (ctx->r12 != 0) {
        // 0x8022DFF0: nop
    
            goto L_8022E004;
    }
    // 0x8022DFF0: nop

    // 0x8022DFF4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8022DFF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022DFFC: b           L_8022E01C
    // 0x8022E000: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8022E01C;
    // 0x8022E000: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8022E004:
    // 0x8022E004: b           L_8022E01C
    // 0x8022E008: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8022E01C;
    // 0x8022E008: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8022E00C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_8022E010:
    // 0x8022E010: nop

    // 0x8022E014: bltz        $t4, L_8022E004
    if (SIGNED(ctx->r12) < 0) {
        // 0x8022E018: nop
    
            goto L_8022E004;
    }
    // 0x8022E018: nop

L_8022E01C:
    // 0x8022E01C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022E020: b           L_8022EB50
    // 0x8022E024: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
        goto L_8022EB50;
    // 0x8022E024: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
L_8022E028:
    // 0x8022E028: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8022E02C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022E030: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8022E034: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E038: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E03C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E040: bgez        $a1, L_8022E058
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022E044: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022E058;
    }
    // 0x8022E044: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022E048: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E04C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022E050: nop

    // 0x8022E054: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8022E058:
    // 0x8022E058: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022E05C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022E060: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022E064: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8022E068: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8022E06C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8022E070: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E074: bgez        $a2, L_8022E088
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022E078: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022E088;
    }
    // 0x8022E078: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022E07C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022E080: nop

    // 0x8022E084: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8022E088:
    // 0x8022E088: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8022E08C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8022E090: mul.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8022E094: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E098: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8022E09C: bgez        $v0, L_8022E0B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E0A0: add.d       $f4, $f18, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
            goto L_8022E0B0;
    }
    // 0x8022E0A0: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x8022E0A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022E0A8: nop

    // 0x8022E0AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8022E0B0:
    // 0x8022E0B0: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8022E0B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022E0B8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E0BC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8022E0C0: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x8022E0C4: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8022E0C8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8022E0CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022E0D0: nop

    // 0x8022E0D4: cvt.w.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022E0D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022E0DC: nop

    // 0x8022E0E0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022E0E4: beql        $t6, $zero, L_8022E138
    if (ctx->r14 == 0) {
        // 0x8022E0E8: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_8022E138;
    }
    goto skip_6;
    // 0x8022E0E8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x8022E0EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E0F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E0F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022E0F8: sub.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d - ctx->f8.d;
    // 0x8022E0FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022E100: nop

    // 0x8022E104: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022E108: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022E10C: nop

    // 0x8022E110: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022E114: bne         $t6, $zero, L_8022E12C
    if (ctx->r14 != 0) {
        // 0x8022E118: nop
    
            goto L_8022E12C;
    }
    // 0x8022E118: nop

    // 0x8022E11C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8022E120: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E124: b           L_8022E144
    // 0x8022E128: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8022E144;
    // 0x8022E128: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8022E12C:
    // 0x8022E12C: b           L_8022E144
    // 0x8022E130: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8022E144;
    // 0x8022E130: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8022E134: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_8022E138:
    // 0x8022E138: nop

    // 0x8022E13C: bltz        $t6, L_8022E12C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8022E140: nop
    
            goto L_8022E12C;
    }
    // 0x8022E140: nop

L_8022E144:
    // 0x8022E144: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8022E148: b           L_8022EB50
    // 0x8022E14C: sh          $t6, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r14;
        goto L_8022EB50;
    // 0x8022E14C: sh          $t6, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r14;
L_8022E150:
    // 0x8022E150: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8022E154: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022E158: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x8022E15C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E160: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E164: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E168: bgez        $a2, L_8022E180
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022E16C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8022E180;
    }
    // 0x8022E16C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022E170: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E174: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8022E178: nop

    // 0x8022E17C: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_8022E180:
    // 0x8022E180: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022E184: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022E188: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022E18C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8022E190: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x8022E194: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8022E198: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E19C: bgez        $a1, L_8022E1B0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022E1A0: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8022E1B0;
    }
    // 0x8022E1A0: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022E1A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022E1A8: nop

    // 0x8022E1AC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8022E1B0:
    // 0x8022E1B0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8022E1B4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8022E1B8: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8022E1BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E1C0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022E1C4: bgez        $v0, L_8022E1D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E1C8: add.d       $f18, $f10, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
            goto L_8022E1D8;
    }
    // 0x8022E1C8: add.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
    // 0x8022E1CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022E1D0: nop

    // 0x8022E1D4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_8022E1D8:
    // 0x8022E1D8: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8022E1DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022E1E0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E1E4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8022E1E8: add.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f18.d + ctx->f8.d;
    // 0x8022E1EC: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8022E1F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8022E1F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022E1F8: nop

    // 0x8022E1FC: cvt.w.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_D(ctx->f6.d);
    // 0x8022E200: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022E204: nop

    // 0x8022E208: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022E20C: beql        $t8, $zero, L_8022E260
    if (ctx->r24 == 0) {
        // 0x8022E210: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_8022E260;
    }
    goto skip_7;
    // 0x8022E210: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_7:
    // 0x8022E214: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022E218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022E21C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022E220: sub.d       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f6.d - ctx->f16.d;
    // 0x8022E224: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022E228: nop

    // 0x8022E22C: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022E230: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022E234: nop

    // 0x8022E238: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022E23C: bne         $t8, $zero, L_8022E254
    if (ctx->r24 != 0) {
        // 0x8022E240: nop
    
            goto L_8022E254;
    }
    // 0x8022E240: nop

    // 0x8022E244: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8022E248: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E24C: b           L_8022E26C
    // 0x8022E250: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8022E26C;
    // 0x8022E250: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8022E254:
    // 0x8022E254: b           L_8022E26C
    // 0x8022E258: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8022E26C;
    // 0x8022E258: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8022E25C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_8022E260:
    // 0x8022E260: nop

    // 0x8022E264: bltz        $t8, L_8022E254
    if (SIGNED(ctx->r24) < 0) {
        // 0x8022E268: nop
    
            goto L_8022E254;
    }
    // 0x8022E268: nop

L_8022E26C:
    // 0x8022E26C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8022E270: b           L_8022EB50
    // 0x8022E274: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
        goto L_8022EB50;
    // 0x8022E274: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
L_8022E278:
    // 0x8022E278: addu        $t9, $v1, $a3
    ctx->r25 = ADD32(ctx->r3, ctx->r7);
    // 0x8022E27C: addu        $t2, $a1, $a2
    ctx->r10 = ADD32(ctx->r5, ctx->r6);
    // 0x8022E280: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8022E284: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8022E288: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8022E28C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022E290: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8022E294: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E298: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E29C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E2A0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022E2A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E2A8: div.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8022E2AC: div.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8022E2B0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8022E2B4: nop

    // 0x8022E2B8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022E2BC: bgez        $v0, L_8022E2D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E2C0: add.s       $f10, $f8, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_8022E2D0;
    }
    // 0x8022E2C0: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8022E2C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022E2C8: nop

    // 0x8022E2CC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8022E2D0:
    // 0x8022E2D0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8022E2D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022E2D8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E2DC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8022E2E0: add.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f16.d + ctx->f2.d;
    // 0x8022E2E4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022E2E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022E2EC: nop

    // 0x8022E2F0: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022E2F4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022E2F8: nop

    // 0x8022E2FC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8022E300: beql        $t4, $zero, L_8022E354
    if (ctx->r12 == 0) {
        // 0x8022E304: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_8022E354;
    }
    goto skip_8;
    // 0x8022E304: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_8:
    // 0x8022E308: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022E30C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022E310: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022E314: sub.d       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f18.d - ctx->f6.d;
    // 0x8022E318: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022E31C: nop

    // 0x8022E320: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8022E324: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022E328: nop

    // 0x8022E32C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8022E330: bne         $t4, $zero, L_8022E348
    if (ctx->r12 != 0) {
        // 0x8022E334: nop
    
            goto L_8022E348;
    }
    // 0x8022E334: nop

    // 0x8022E338: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8022E33C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E340: b           L_8022E360
    // 0x8022E344: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8022E360;
    // 0x8022E344: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8022E348:
    // 0x8022E348: b           L_8022E360
    // 0x8022E34C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8022E360;
    // 0x8022E34C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8022E350: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_8022E354:
    // 0x8022E354: nop

    // 0x8022E358: bltz        $t4, L_8022E348
    if (SIGNED(ctx->r12) < 0) {
        // 0x8022E35C: nop
    
            goto L_8022E348;
    }
    // 0x8022E35C: nop

L_8022E360:
    // 0x8022E360: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022E364: b           L_8022EB50
    // 0x8022E368: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
        goto L_8022EB50;
    // 0x8022E368: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
L_8022E36C:
    // 0x8022E36C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E370: ldc1        $f0, -0x598($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X598);
    // 0x8022E374: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8022E378: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E37C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E380: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E384: bgez        $v1, L_8022E3A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022E388: cvt.d.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
            goto L_8022E3A0;
    }
    // 0x8022E388: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8022E38C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E390: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E398: nop

    // 0x8022E39C: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_8022E3A0:
    // 0x8022E3A0: mul.d       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8022E3A4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8022E3A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E3AC: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022E3B0: bgez        $a3, L_8022E3C8
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022E3B4: cvt.s.d     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
            goto L_8022E3C8;
    }
    // 0x8022E3B4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8022E3B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E3BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E3C0: nop

    // 0x8022E3C4: add.d       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f10.d + ctx->f8.d;
L_8022E3C8:
    // 0x8022E3C8: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8022E3CC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8022E3D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E3D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8022E3D8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8022E3DC: bgez        $v0, L_8022E3F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E3E0: add.s       $f6, $f18, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_8022E3F0;
    }
    // 0x8022E3E0: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8022E3E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022E3E8: nop

    // 0x8022E3EC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8022E3F0:
    // 0x8022E3F0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8022E3F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022E3F8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E3FC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8022E400: add.d       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f16.d + ctx->f2.d;
    // 0x8022E404: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8022E408: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022E40C: nop

    // 0x8022E410: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022E414: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022E418: nop

    // 0x8022E41C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022E420: beql        $t6, $zero, L_8022E474
    if (ctx->r14 == 0) {
        // 0x8022E424: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_8022E474;
    }
    goto skip_9;
    // 0x8022E424: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_9:
    // 0x8022E428: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022E42C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022E430: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022E434: sub.d       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f8.d - ctx->f4.d;
    // 0x8022E438: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022E43C: nop

    // 0x8022E440: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022E444: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022E448: nop

    // 0x8022E44C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022E450: bne         $t6, $zero, L_8022E468
    if (ctx->r14 != 0) {
        // 0x8022E454: nop
    
            goto L_8022E468;
    }
    // 0x8022E454: nop

    // 0x8022E458: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8022E45C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E460: b           L_8022E480
    // 0x8022E464: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8022E480;
    // 0x8022E464: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8022E468:
    // 0x8022E468: b           L_8022E480
    // 0x8022E46C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8022E480;
    // 0x8022E46C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8022E470: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_8022E474:
    // 0x8022E474: nop

    // 0x8022E478: bltz        $t6, L_8022E468
    if (SIGNED(ctx->r14) < 0) {
        // 0x8022E47C: nop
    
            goto L_8022E468;
    }
    // 0x8022E47C: nop

L_8022E480:
    // 0x8022E480: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8022E484: b           L_8022EB50
    // 0x8022E488: sh          $t6, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r14;
        goto L_8022EB50;
    // 0x8022E488: sh          $t6, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r14;
L_8022E48C:
    // 0x8022E48C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E490: ldc1        $f0, -0x590($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X590);
    // 0x8022E494: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E498: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E49C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8022E4A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E4A4: bgez        $v1, L_8022E4B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022E4A8: sra         $t7, $v1, 1
        ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8022E4B4;
    }
    // 0x8022E4A8: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8022E4AC: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x8022E4B0: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8022E4B4:
    // 0x8022E4B4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8022E4B8: nop

    // 0x8022E4BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8022E4C0: bgez        $a3, L_8022E4D0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022E4C4: sra         $t8, $a3, 1
        ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
            goto L_8022E4D0;
    }
    // 0x8022E4C4: sra         $t8, $a3, 1
    ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8022E4C8: addiu       $at, $a3, 0x1
    ctx->r1 = ADD32(ctx->r7, 0X1);
    // 0x8022E4CC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8022E4D0:
    // 0x8022E4D0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8022E4D4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022E4D8: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022E4DC: bgez        $a1, L_8022E4F8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022E4E0: add.s       $f8, $f10, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
            goto L_8022E4F8;
    }
    // 0x8022E4E0: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8022E4E4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E4E8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022E4EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022E4F0: nop

    // 0x8022E4F4: add.d       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f6.d + ctx->f18.d;
L_8022E4F8:
    // 0x8022E4F8: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8022E4FC: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x8022E500: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E504: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x8022E508: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8022E50C: bgez        $a2, L_8022E524
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022E510: add.s       $f4, $f8, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_8022E524;
    }
    // 0x8022E510: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8022E514: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022E518: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022E51C: nop

    // 0x8022E520: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
L_8022E524:
    // 0x8022E524: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8022E528: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8022E52C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E530: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022E534: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8022E538: bgez        $v0, L_8022E54C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E53C: add.s       $f18, $f4, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
            goto L_8022E54C;
    }
    // 0x8022E53C: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8022E540: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022E544: nop

    // 0x8022E548: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8022E54C:
    // 0x8022E54C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8022E550: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022E554: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E558: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8022E55C: add.d       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f16.d + ctx->f2.d;
    // 0x8022E560: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022E564: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022E568: nop

    // 0x8022E56C: cvt.w.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022E570: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022E574: nop

    // 0x8022E578: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022E57C: beql        $t2, $zero, L_8022E5D0
    if (ctx->r10 == 0) {
        // 0x8022E580: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_8022E5D0;
    }
    goto skip_10;
    // 0x8022E580: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_10:
    // 0x8022E584: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E588: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E58C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022E590: sub.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d - ctx->f8.d;
    // 0x8022E594: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022E598: nop

    // 0x8022E59C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022E5A0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022E5A4: nop

    // 0x8022E5A8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022E5AC: bne         $t2, $zero, L_8022E5C4
    if (ctx->r10 != 0) {
        // 0x8022E5B0: nop
    
            goto L_8022E5C4;
    }
    // 0x8022E5B0: nop

    // 0x8022E5B4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8022E5B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E5BC: b           L_8022E5DC
    // 0x8022E5C0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8022E5DC;
    // 0x8022E5C0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8022E5C4:
    // 0x8022E5C4: b           L_8022E5DC
    // 0x8022E5C8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8022E5DC;
    // 0x8022E5C8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8022E5CC: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_8022E5D0:
    // 0x8022E5D0: nop

    // 0x8022E5D4: bltz        $t2, L_8022E5C4
    if (SIGNED(ctx->r10) < 0) {
        // 0x8022E5D8: nop
    
            goto L_8022E5C4;
    }
    // 0x8022E5D8: nop

L_8022E5DC:
    // 0x8022E5DC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022E5E0: b           L_8022EB50
    // 0x8022E5E4: sh          $t2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r10;
        goto L_8022EB50;
    // 0x8022E5E4: sh          $t2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r10;
L_8022E5E8:
    // 0x8022E5E8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E5EC: ldc1        $f0, -0x588($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X588);
    // 0x8022E5F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E5F4: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x8022E5F8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E5FC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E600: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E604: ldc1        $f12, -0x580($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X580);
    // 0x8022E608: bgez        $v1, L_8022E624
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022E60C: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_8022E624;
    }
    // 0x8022E60C: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x8022E610: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E614: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022E618: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022E61C: nop

    // 0x8022E620: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
L_8022E624:
    // 0x8022E624: mul.d       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8022E628: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8022E62C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E630: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x8022E634: bgez        $a3, L_8022E64C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022E638: cvt.s.d     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
            goto L_8022E64C;
    }
    // 0x8022E638: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8022E63C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022E640: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022E644: nop

    // 0x8022E648: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_8022E64C:
    // 0x8022E64C: mul.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8022E650: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8022E654: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E658: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022E65C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8022E660: bgez        $a1, L_8022E678
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022E664: add.s       $f8, $f10, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
            goto L_8022E678;
    }
    // 0x8022E664: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8022E668: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022E66C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022E670: nop

    // 0x8022E674: add.d       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f18.d + ctx->f6.d;
L_8022E678:
    // 0x8022E678: mul.d       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f12.d);
    // 0x8022E67C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8022E680: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E684: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022E688: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8022E68C: bgez        $a2, L_8022E6A4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022E690: add.s       $f4, $f8, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_8022E6A4;
    }
    // 0x8022E690: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8022E694: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022E698: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022E69C: nop

    // 0x8022E6A0: add.d       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f18.d + ctx->f10.d;
L_8022E6A4:
    // 0x8022E6A4: mul.d       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f12.d);
    // 0x8022E6A8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8022E6AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E6B0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022E6B4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8022E6B8: bgez        $v0, L_8022E6CC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E6BC: add.s       $f6, $f4, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
            goto L_8022E6CC;
    }
    // 0x8022E6BC: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8022E6C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022E6C4: nop

    // 0x8022E6C8: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_8022E6CC:
    // 0x8022E6CC: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8022E6D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022E6D4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E6D8: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8022E6DC: add.d       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f16.d + ctx->f2.d;
    // 0x8022E6E0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022E6E4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022E6E8: nop

    // 0x8022E6EC: cvt.w.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022E6F0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022E6F4: nop

    // 0x8022E6F8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8022E6FC: beql        $t4, $zero, L_8022E750
    if (ctx->r12 == 0) {
        // 0x8022E700: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_8022E750;
    }
    goto skip_11;
    // 0x8022E700: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_11:
    // 0x8022E704: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E708: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E70C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022E710: sub.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d - ctx->f8.d;
    // 0x8022E714: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022E718: nop

    // 0x8022E71C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022E720: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022E724: nop

    // 0x8022E728: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8022E72C: bne         $t4, $zero, L_8022E744
    if (ctx->r12 != 0) {
        // 0x8022E730: nop
    
            goto L_8022E744;
    }
    // 0x8022E730: nop

    // 0x8022E734: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8022E738: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E73C: b           L_8022E75C
    // 0x8022E740: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8022E75C;
    // 0x8022E740: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8022E744:
    // 0x8022E744: b           L_8022E75C
    // 0x8022E748: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8022E75C;
    // 0x8022E748: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8022E74C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_8022E750:
    // 0x8022E750: nop

    // 0x8022E754: bltz        $t4, L_8022E744
    if (SIGNED(ctx->r12) < 0) {
        // 0x8022E758: nop
    
            goto L_8022E744;
    }
    // 0x8022E758: nop

L_8022E75C:
    // 0x8022E75C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022E760: b           L_8022EB50
    // 0x8022E764: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
        goto L_8022EB50;
    // 0x8022E764: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
L_8022E768:
    // 0x8022E768: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E76C: ldc1        $f0, -0x578($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X578);
    // 0x8022E770: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8022E774: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E778: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E77C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E780: bgez        $v1, L_8022E79C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022E784: cvt.d.w     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
            goto L_8022E79C;
    }
    // 0x8022E784: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022E788: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E78C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022E790: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022E794: nop

    // 0x8022E798: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_8022E79C:
    // 0x8022E79C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E7A0: ldc1        $f16, -0x570($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X570);
    // 0x8022E7A4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8022E7A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E7AC: mul.d       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8022E7B0: cvt.d.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022E7B4: bgez        $a3, L_8022E7CC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022E7B8: cvt.s.d     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
            goto L_8022E7CC;
    }
    // 0x8022E7B8: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8022E7BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022E7C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022E7C4: nop

    // 0x8022E7C8: add.d       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f4.d + ctx->f18.d;
L_8022E7CC:
    // 0x8022E7CC: mul.d       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8022E7D0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8022E7D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E7D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022E7DC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8022E7E0: bgez        $v0, L_8022E7F4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E7E4: add.s       $f6, $f8, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_8022E7F4;
    }
    // 0x8022E7E4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8022E7E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8022E7EC: nop

    // 0x8022E7F0: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_8022E7F4:
    // 0x8022E7F4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8022E7F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022E7FC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022E800: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8022E804: add.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f10.d + ctx->f2.d;
    // 0x8022E808: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8022E80C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022E810: nop

    // 0x8022E814: cvt.w.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022E818: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022E81C: nop

    // 0x8022E820: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022E824: beql        $t6, $zero, L_8022E878
    if (ctx->r14 == 0) {
        // 0x8022E828: mfc1        $t6, $f16
        ctx->r14 = (int32_t)ctx->f16.u32l;
            goto L_8022E878;
    }
    goto skip_12;
    // 0x8022E828: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    skip_12:
    // 0x8022E82C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022E830: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022E834: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022E838: sub.d       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f18.d - ctx->f16.d;
    // 0x8022E83C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8022E840: nop

    // 0x8022E844: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022E848: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8022E84C: nop

    // 0x8022E850: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8022E854: bne         $t6, $zero, L_8022E86C
    if (ctx->r14 != 0) {
        // 0x8022E858: nop
    
            goto L_8022E86C;
    }
    // 0x8022E858: nop

    // 0x8022E85C: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8022E860: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E864: b           L_8022E884
    // 0x8022E868: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8022E884;
    // 0x8022E868: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8022E86C:
    // 0x8022E86C: b           L_8022E884
    // 0x8022E870: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8022E884;
    // 0x8022E870: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8022E874: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
L_8022E878:
    // 0x8022E878: nop

    // 0x8022E87C: bltz        $t6, L_8022E86C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8022E880: nop
    
            goto L_8022E86C;
    }
    // 0x8022E880: nop

L_8022E884:
    // 0x8022E884: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8022E888: b           L_8022EB50
    // 0x8022E88C: sh          $t6, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r14;
        goto L_8022EB50;
    // 0x8022E88C: sh          $t6, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r14;
L_8022E890:
    // 0x8022E890: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8022E894: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E898: ldc1        $f0, -0x568($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X568);
    // 0x8022E89C: bgez        $a1, L_8022E8B8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022E8A0: cvt.d.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
            goto L_8022E8B8;
    }
    // 0x8022E8A0: cvt.d.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022E8A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E8A8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E8AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E8B0: nop

    // 0x8022E8B4: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_8022E8B8:
    // 0x8022E8B8: mul.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8022E8BC: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x8022E8C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E8C4: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x8022E8C8: bgez        $a2, L_8022E8E0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022E8CC: cvt.s.d     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
            goto L_8022E8E0;
    }
    // 0x8022E8CC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8022E8D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022E8D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022E8D8: nop

    // 0x8022E8DC: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_8022E8E0:
    // 0x8022E8E0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8022E8E4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8022E8E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022E8EC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8022E8F0: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8022E8F4: bgez        $v0, L_8022E908
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022E8F8: add.s       $f16, $f18, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
            goto L_8022E908;
    }
    // 0x8022E8F8: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8022E8FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022E900: nop

    // 0x8022E904: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8022E908:
    // 0x8022E908: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8022E90C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022E910: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8022E914: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8022E918: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022E91C: nop

    // 0x8022E920: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8022E924: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022E928: nop

    // 0x8022E92C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022E930: beql        $t8, $zero, L_8022E980
    if (ctx->r24 == 0) {
        // 0x8022E934: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_8022E980;
    }
    goto skip_13;
    // 0x8022E934: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_13:
    // 0x8022E938: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022E93C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022E940: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8022E944: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022E948: nop

    // 0x8022E94C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8022E950: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022E954: nop

    // 0x8022E958: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022E95C: bne         $t8, $zero, L_8022E974
    if (ctx->r24 != 0) {
        // 0x8022E960: nop
    
            goto L_8022E974;
    }
    // 0x8022E960: nop

    // 0x8022E964: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8022E968: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022E96C: b           L_8022E98C
    // 0x8022E970: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8022E98C;
    // 0x8022E970: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8022E974:
    // 0x8022E974: b           L_8022E98C
    // 0x8022E978: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8022E98C;
    // 0x8022E978: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8022E97C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_8022E980:
    // 0x8022E980: nop

    // 0x8022E984: bltz        $t8, L_8022E974
    if (SIGNED(ctx->r24) < 0) {
        // 0x8022E988: nop
    
            goto L_8022E974;
    }
    // 0x8022E988: nop

L_8022E98C:
    // 0x8022E98C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E990: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8022E994: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E998: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E99C: b           L_8022EB50
    // 0x8022E9A0: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
        goto L_8022EB50;
    // 0x8022E9A0: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
L_8022E9A4:
    // 0x8022E9A4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E9A8: ldc1        $f0, -0x560($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X560);
    // 0x8022E9AC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022E9B0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8022E9B4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022E9B8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E9BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022E9C0: ldc1        $f12, -0x558($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X558);
    // 0x8022E9C4: bgez        $v1, L_8022E9E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022E9C8: cvt.d.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
            goto L_8022E9E0;
    }
    // 0x8022E9C8: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x8022E9CC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E9D0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022E9D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022E9D8: nop

    // 0x8022E9DC: add.d       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f4.d + ctx->f16.d;
L_8022E9E0:
    // 0x8022E9E0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022E9E4: ldc1        $f6, -0x550($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X550);
    // 0x8022E9E8: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8022E9EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022E9F0: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8022E9F4: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x8022E9F8: bgez        $a3, L_8022EA10
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022E9FC: cvt.s.d     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
            goto L_8022EA10;
    }
    // 0x8022E9FC: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8022EA00: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022EA04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022EA08: nop

    // 0x8022EA0C: add.d       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f16.d + ctx->f4.d;
L_8022EA10:
    // 0x8022EA10: mul.d       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x8022EA14: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8022EA18: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022EA1C: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022EA20: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8022EA24: bgez        $a1, L_8022EA3C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022EA28: add.s       $f8, $f10, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
            goto L_8022EA3C;
    }
    // 0x8022EA28: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8022EA2C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8022EA30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8022EA34: nop

    // 0x8022EA38: add.d       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f16.d + ctx->f6.d;
L_8022EA3C:
    // 0x8022EA3C: mul.d       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8022EA40: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8022EA44: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022EA48: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022EA4C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8022EA50: bgez        $a2, L_8022EA68
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022EA54: add.s       $f4, $f8, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
            goto L_8022EA68;
    }
    // 0x8022EA54: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8022EA58: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022EA5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022EA60: nop

    // 0x8022EA64: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_8022EA68:
    // 0x8022EA68: mul.d       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8022EA6C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8022EA70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022EA74: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022EA78: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8022EA7C: bgez        $v0, L_8022EA90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022EA80: add.s       $f6, $f4, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
            goto L_8022EA90;
    }
    // 0x8022EA80: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8022EA84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022EA88: nop

    // 0x8022EA8C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8022EA90:
    // 0x8022EA90: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8022EA94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022EA98: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022EA9C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8022EAA0: add.d       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f18.d + ctx->f2.d;
    // 0x8022EAA4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8022EAA8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022EAAC: nop

    // 0x8022EAB0: cvt.w.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_D(ctx->f10.d);
    // 0x8022EAB4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022EAB8: nop

    // 0x8022EABC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022EAC0: beql        $t2, $zero, L_8022EB14
    if (ctx->r10 == 0) {
        // 0x8022EAC4: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_8022EB14;
    }
    goto skip_14;
    // 0x8022EAC4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_14:
    // 0x8022EAC8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022EACC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022EAD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8022EAD4: sub.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d - ctx->f8.d;
    // 0x8022EAD8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022EADC: nop

    // 0x8022EAE0: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022EAE4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022EAE8: nop

    // 0x8022EAEC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8022EAF0: bne         $t2, $zero, L_8022EB08
    if (ctx->r10 != 0) {
        // 0x8022EAF4: nop
    
            goto L_8022EB08;
    }
    // 0x8022EAF4: nop

    // 0x8022EAF8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8022EAFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022EB00: b           L_8022EB20
    // 0x8022EB04: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8022EB20;
    // 0x8022EB04: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8022EB08:
    // 0x8022EB08: b           L_8022EB20
    // 0x8022EB0C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8022EB20;
    // 0x8022EB0C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8022EB10: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_8022EB14:
    // 0x8022EB14: nop

    // 0x8022EB18: bltz        $t2, L_8022EB08
    if (SIGNED(ctx->r10) < 0) {
        // 0x8022EB1C: nop
    
            goto L_8022EB08;
    }
    // 0x8022EB1C: nop

L_8022EB20:
    // 0x8022EB20: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8022EB24: b           L_8022EB50
    // 0x8022EB28: sh          $t2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r10;
        goto L_8022EB50;
    // 0x8022EB28: sh          $t2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r10;
L_8022EB2C:
    // 0x8022EB2C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022EB30: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022EB34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022EB38: b           L_8022EB50
    // 0x8022EB3C: sh          $t1, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r9;
        goto L_8022EB50;
    // 0x8022EB3C: sh          $t1, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r9;
L_8022EB40:
    // 0x8022EB40: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022EB44: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022EB48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022EB4C: sh          $v1, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r3;
L_8022EB50:
    // 0x8022EB50: lhu         $t3, 0x9A($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X9A);
    // 0x8022EB54: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022EB58: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8022EB5C: bgez        $t3, L_8022EB74
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8022EB60: cvt.d.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
            goto L_8022EB74;
    }
    // 0x8022EB60: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x8022EB64: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022EB68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022EB6C: nop

    // 0x8022EB70: add.d       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f16.d + ctx->f4.d;
L_8022EB74:
    // 0x8022EB74: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022EB78: ldc1        $f18, -0x548($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X548);
    // 0x8022EB7C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022EB80: ldc1        $f4, -0x540($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X540);
    // 0x8022EB84: mul.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8022EB88: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8022EB8C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8022EB90: add.d       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f6.d + ctx->f4.d;
    // 0x8022EB94: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8022EB98: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8022EB9C: lbu         $t4, 0xA($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XA);
    // 0x8022EBA0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8022EBA4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8022EBA8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8022EBAC: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8022EBB0: lh          $v0, 0xAA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XAA);
    // 0x8022EBB4: bgez        $v0, L_8022EBC4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022EBB8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8022EBC4;
    }
    // 0x8022EBB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8022EBBC: b           L_8022EBC4
    // 0x8022EBC0: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
        goto L_8022EBC4;
    // 0x8022EBC0: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_8022EBC4:
    // 0x8022EBC4: lbu         $t7, 0xE($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XE);
    // 0x8022EBC8: subu        $v1, $a1, $t7
    ctx->r3 = SUB32(ctx->r5, ctx->r15);
    // 0x8022EBCC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8022EBD0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8022EBD4: bgezl       $v1, L_8022EBE4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8022EBD8: lbu         $t8, 0x11($t0)
        ctx->r24 = MEM_BU(ctx->r8, 0X11);
            goto L_8022EBE4;
    }
    goto skip_15;
    // 0x8022EBD8: lbu         $t8, 0x11($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X11);
    skip_15:
    // 0x8022EBDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8022EBE0: lbu         $t8, 0x11($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X11);
L_8022EBE4:
    // 0x8022EBE4: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8022EBE8: beq         $at, $zero, L_8022ED7C
    if (ctx->r1 == 0) {
        // 0x8022EBEC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8022ED7C;
    }
    // 0x8022EBEC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8022EBF0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022EBF4: addu        $at, $at, $t8
    gpr jr_addend_8022EBFC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8022EBF8: lw          $t8, -0x538($at)
    ctx->r24 = ADD32(ctx->r1, -0X538);
    // 0x8022EBFC: jr          $t8
    // 0x8022EC00: nop

    switch (jr_addend_8022EBFC >> 2) {
        case 0: goto L_8022EC04; break;
        case 1: goto L_8022EC1C; break;
        case 2: goto L_8022EC94; break;
        case 3: goto L_8022ECCC; break;
        case 4: goto L_8022ED44; break;
        default: switch_error(__func__, 0x8022EBFC, 0x8023FAC8);
    }
    // 0x8022EC00: nop

L_8022EC04:
    // 0x8022EC04: lbu         $t9, 0xD($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XD);
    // 0x8022EC08: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022EC0C: mflo        $a1
    ctx->r5 = lo;
    // 0x8022EC10: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022EC14: b           L_8022ED80
    // 0x8022EC18: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_8022ED80;
    // 0x8022EC18: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8022EC1C:
    // 0x8022EC1C: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x8022EC20: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8022EC24: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8022EC28: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8022EC2C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8022EC30: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8022EC34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8022EC38: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8022EC3C: jal         0x8002FC20
    // 0x8022EC40: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8022EC40: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_0:
    // 0x8022EC44: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8022EC48: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022EC4C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022EC50: lbu         $t3, 0xD($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XD);
    // 0x8022EC54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022EC58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022EC5C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8022EC60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8022EC64: bgez        $t3, L_8022EC78
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8022EC68: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8022EC78;
    }
    // 0x8022EC68: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8022EC6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8022EC70: nop

    // 0x8022EC74: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8022EC78:
    // 0x8022EC78: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8022EC7C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8022EC80: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8022EC84: nop

    // 0x8022EC88: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022EC8C: b           L_8022ED80
    // 0x8022EC90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_8022ED80;
    // 0x8022EC90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8022EC94:
    // 0x8022EC94: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022EC98: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8022EC9C: mflo        $v0
    ctx->r2 = lo;
    // 0x8022ECA0: lbu         $t5, 0xD($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XD);
    // 0x8022ECA4: nop

    // 0x8022ECA8: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022ECAC: mflo        $t6
    ctx->r14 = lo;
    // 0x8022ECB0: nop

    // 0x8022ECB4: nop

    // 0x8022ECB8: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022ECBC: mflo        $a1
    ctx->r5 = lo;
    // 0x8022ECC0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022ECC4: b           L_8022ED80
    // 0x8022ECC8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_8022ED80;
    // 0x8022ECC8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8022ECCC:
    // 0x8022ECCC: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8022ECD0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8022ECD4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8022ECD8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8022ECDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8022ECE0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8022ECE4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8022ECE8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8022ECEC: jal         0x8002FC20
    // 0x8022ECF0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8022ECF0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_1:
    // 0x8022ECF4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8022ECF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022ECFC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8022ED00: lbu         $t8, 0xD($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XD);
    // 0x8022ED04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8022ED08: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022ED0C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8022ED10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8022ED14: bgez        $t8, L_8022ED28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8022ED18: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8022ED28;
    }
    // 0x8022ED18: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8022ED1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022ED20: nop

    // 0x8022ED24: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8022ED28:
    // 0x8022ED28: mul.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8022ED2C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8022ED30: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8022ED34: nop

    // 0x8022ED38: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022ED3C: b           L_8022ED80
    // 0x8022ED40: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_8022ED80;
    // 0x8022ED40: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8022ED44:
    // 0x8022ED44: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8022ED48: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8022ED4C: mflo        $v0
    ctx->r2 = lo;
    // 0x8022ED50: lbu         $t2, 0xD($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XD);
    // 0x8022ED54: nop

    // 0x8022ED58: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022ED5C: mflo        $t3
    ctx->r11 = lo;
    // 0x8022ED60: nop

    // 0x8022ED64: nop

    // 0x8022ED68: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022ED6C: mflo        $a1
    ctx->r5 = lo;
    // 0x8022ED70: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022ED74: b           L_8022ED80
    // 0x8022ED78: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_8022ED80;
    // 0x8022ED78: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8022ED7C:
    // 0x8022ED7C: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
L_8022ED80:
    // 0x8022ED80: bgez        $a1, L_8022ED8C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8022ED84: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_8022ED8C;
    }
    // 0x8022ED84: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8022ED88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8022ED8C:
    // 0x8022ED8C: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x8022ED90: lhu         $t4, 0x4E($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X4E);
    // 0x8022ED94: mflo        $a1
    ctx->r5 = lo;
    // 0x8022ED98: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022ED9C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8022EDA0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8022EDA4: bgez        $t4, L_8022EDBC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8022EDA8: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8022EDBC;
    }
    // 0x8022EDA8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8022EDAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022EDB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022EDB4: nop

    // 0x8022EDB8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8022EDBC:
    // 0x8022EDBC: lbu         $t5, 0x7($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X7);
    // 0x8022EDC0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8022EDC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022EDC8: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x8022EDCC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8022EDD0: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8022EDD4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022EDD8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8022EDDC: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8022EDE0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8022EDE4: add.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f8.d + ctx->f2.d;
    // 0x8022EDE8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8022EDEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022EDF0: nop

    // 0x8022EDF4: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022EDF8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022EDFC: nop

    // 0x8022EE00: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022EE04: beql        $t8, $zero, L_8022EE58
    if (ctx->r24 == 0) {
        // 0x8022EE08: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_8022EE58;
    }
    goto skip_16;
    // 0x8022EE08: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_16:
    // 0x8022EE0C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022EE10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022EE14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8022EE18: sub.d       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f4.d - ctx->f18.d;
    // 0x8022EE1C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8022EE20: nop

    // 0x8022EE24: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022EE28: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8022EE2C: nop

    // 0x8022EE30: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8022EE34: bne         $t8, $zero, L_8022EE4C
    if (ctx->r24 != 0) {
        // 0x8022EE38: nop
    
            goto L_8022EE4C;
    }
    // 0x8022EE38: nop

    // 0x8022EE3C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8022EE40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022EE44: b           L_8022EE64
    // 0x8022EE48: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8022EE64;
    // 0x8022EE48: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8022EE4C:
    // 0x8022EE4C: b           L_8022EE64
    // 0x8022EE50: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8022EE64;
    // 0x8022EE50: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8022EE54: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_8022EE58:
    // 0x8022EE58: nop

    // 0x8022EE5C: bltz        $t8, L_8022EE4C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8022EE60: nop
    
            goto L_8022EE4C;
    }
    // 0x8022EE60: nop

L_8022EE64:
    // 0x8022EE64: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
    // 0x8022EE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022EE6C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8022EE70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8022EE74: jr          $ra
    // 0x8022EE78: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    return;
    // 0x8022EE78: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022ee7c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022ee7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022EE7C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022EE80: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x8022EE84: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8022EE88: bne         $a1, $t7, L_8022EE9C
    if (ctx->r5 != ctx->r15) {
        // 0x8022EE8C: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8022EE9C;
    }
    // 0x8022EE8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8022EE90: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022EE94: b           L_8022EEA4
    // 0x8022EE98: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
        goto L_8022EEA4;
    // 0x8022EE98: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_8022EE9C:
    // 0x8022EE9C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022EEA0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8022EEA4:
    // 0x8022EEA4: lw          $v1, 0x2D4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2D4);
    // 0x8022EEA8: lbu         $a0, 0x8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X8);
    // 0x8022EEAC: beq         $a0, $zero, L_8022F0D8
    if (ctx->r4 == 0) {
        // 0x8022EEB0: nop
    
            goto L_8022F0D8;
    }
    // 0x8022EEB0: nop

    // 0x8022EEB4: lbu         $t8, 0xA($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XA);
    // 0x8022EEB8: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x8022EEBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8022EEC0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8022EEC4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8022EEC8: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8022EECC: lh          $a3, 0xAA($t0)
    ctx->r7 = MEM_H(ctx->r8, 0XAA);
    // 0x8022EED0: bgez        $a3, L_8022EEE0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022EED4: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8022EEE0;
    }
    // 0x8022EED4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8022EED8: b           L_8022EEE0
    // 0x8022EEDC: negu        $v1, $a3
    ctx->r3 = SUB32(0, ctx->r7);
        goto L_8022EEE0;
    // 0x8022EEDC: negu        $v1, $a3
    ctx->r3 = SUB32(0, ctx->r7);
L_8022EEE0:
    // 0x8022EEE0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8022EEE4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8022EEE8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022EEEC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022EEF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022EEF4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8022EEF8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022EEFC: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8022EF00: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8022EF04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022EF08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022EF0C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022EF10: bgez        $a2, L_8022EF28
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022EF14: add.d       $f18, $f10, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
            goto L_8022EF28;
    }
    // 0x8022EF14: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8022EF18: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022EF1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022EF20: nop

    // 0x8022EF24: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_8022EF28:
    // 0x8022EF28: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8022EF2C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022EF30: ldc1        $f16, -0x520($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X520);
    // 0x8022EF34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8022EF38: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022EF3C: div.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8022EF40: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8022EF44: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8022EF48: nop

    // 0x8022EF4C: cvt.w.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022EF50: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8022EF54: nop

    // 0x8022EF58: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8022EF5C: beql        $a2, $zero, L_8022EFB0
    if (ctx->r6 == 0) {
        // 0x8022EF60: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_8022EFB0;
    }
    goto skip_0;
    // 0x8022EF60: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8022EF64: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8022EF68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022EF6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8022EF70: sub.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d - ctx->f8.d;
    // 0x8022EF74: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8022EF78: nop

    // 0x8022EF7C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x8022EF80: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8022EF84: nop

    // 0x8022EF88: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8022EF8C: bne         $a2, $zero, L_8022EFA4
    if (ctx->r6 != 0) {
        // 0x8022EF90: nop
    
            goto L_8022EFA4;
    }
    // 0x8022EF90: nop

    // 0x8022EF94: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8022EF98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022EF9C: b           L_8022EFBC
    // 0x8022EFA0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_8022EFBC;
    // 0x8022EFA0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_8022EFA4:
    // 0x8022EFA4: b           L_8022EFBC
    // 0x8022EFA8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_8022EFBC;
    // 0x8022EFA8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8022EFAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_8022EFB0:
    // 0x8022EFB0: nop

    // 0x8022EFB4: bltz        $a2, L_8022EFA4
    if (SIGNED(ctx->r6) < 0) {
        // 0x8022EFB8: nop
    
            goto L_8022EFA4;
    }
    // 0x8022EFB8: nop

L_8022EFBC:
    // 0x8022EFBC: lbu         $t2, 0x2DB($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2DB);
    // 0x8022EFC0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8022EFC4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8022EFC8: beql        $t2, $zero, L_8022F08C
    if (ctx->r10 == 0) {
        // 0x8022EFCC: lhu         $v1, 0x300($a1)
        ctx->r3 = MEM_HU(ctx->r5, 0X300);
            goto L_8022F08C;
    }
    goto skip_1;
    // 0x8022EFCC: lhu         $v1, 0x300($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X300);
    skip_1:
    // 0x8022EFD0: bgez        $a2, L_8022EFE0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8022EFD4: sra         $t3, $a2, 1
        ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
            goto L_8022EFE0;
    }
    // 0x8022EFD4: sra         $t3, $a2, 1
    ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8022EFD8: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8022EFDC: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8022EFE0:
    // 0x8022EFE0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8022EFE4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022EFE8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8022EFEC: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x8022EFF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022EFF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8022EFF8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022EFFC: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8022F000: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8022F004: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8022F008: nop

    // 0x8022F00C: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x8022F010: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8022F014: nop

    // 0x8022F018: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8022F01C: beql        $a2, $zero, L_8022F070
    if (ctx->r6 == 0) {
        // 0x8022F020: mfc1        $a2, $f4
        ctx->r6 = (int32_t)ctx->f4.u32l;
            goto L_8022F070;
    }
    goto skip_2;
    // 0x8022F020: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x8022F024: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022F028: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022F02C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8022F030: sub.d       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f16.d - ctx->f4.d;
    // 0x8022F034: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8022F038: nop

    // 0x8022F03C: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022F040: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8022F044: nop

    // 0x8022F048: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8022F04C: bne         $a2, $zero, L_8022F064
    if (ctx->r6 != 0) {
        // 0x8022F050: nop
    
            goto L_8022F064;
    }
    // 0x8022F050: nop

    // 0x8022F054: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8022F058: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022F05C: b           L_8022F07C
    // 0x8022F060: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_8022F07C;
    // 0x8022F060: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_8022F064:
    // 0x8022F064: b           L_8022F07C
    // 0x8022F068: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_8022F07C;
    // 0x8022F068: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8022F06C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
L_8022F070:
    // 0x8022F070: nop

    // 0x8022F074: bltz        $a2, L_8022F064
    if (SIGNED(ctx->r6) < 0) {
        // 0x8022F078: nop
    
            goto L_8022F064;
    }
    // 0x8022F078: nop

L_8022F07C:
    // 0x8022F07C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8022F080: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8022F084: nop

    // 0x8022F088: lhu         $v1, 0x300($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X300);
L_8022F08C:
    // 0x8022F08C: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x8022F090: beql        $at, $zero, L_8022F0C0
    if (ctx->r1 == 0) {
        // 0x8022F094: lh          $a0, 0xA($v0)
        ctx->r4 = MEM_H(ctx->r2, 0XA);
            goto L_8022F0C0;
    }
    goto skip_3;
    // 0x8022F094: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    skip_3:
    // 0x8022F098: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022F09C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8022F0A0: mflo        $a2
    ctx->r6 = lo;
    // 0x8022F0A4: nop

    // 0x8022F0A8: nop

    // 0x8022F0AC: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x8022F0B0: mflo        $a2
    ctx->r6 = lo;
    // 0x8022F0B4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8022F0B8: nop

    // 0x8022F0BC: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
L_8022F0C0:
    // 0x8022F0C0: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8022F0C4: beql        $at, $zero, L_8022F0D8
    if (ctx->r1 == 0) {
        // 0x8022F0C8: sh          $a0, 0x42($v0)
        MEM_H(0X42, ctx->r2) = ctx->r4;
            goto L_8022F0D8;
    }
    goto skip_4;
    // 0x8022F0C8: sh          $a0, 0x42($v0)
    MEM_H(0X42, ctx->r2) = ctx->r4;
    skip_4:
    // 0x8022F0CC: jr          $ra
    // 0x8022F0D0: sh          $a2, 0x42($v0)
    MEM_H(0X42, ctx->r2) = ctx->r6;
    return;
    // 0x8022F0D0: sh          $a2, 0x42($v0)
    MEM_H(0X42, ctx->r2) = ctx->r6;
    // 0x8022F0D4: sh          $a0, 0x42($v0)
    MEM_H(0X42, ctx->r2) = ctx->r4;
L_8022F0D8:
    // 0x8022F0D8: jr          $ra
    // 0x8022F0DC: nop

    return;
    // 0x8022F0DC: nop

;}
RECOMP_FUNC void M10_FUN_8022f0e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F0E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8022F0E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022F0E8: addiu       $a1, $a0, 0x8E
    ctx->r5 = ADD32(ctx->r4, 0X8E);
    // 0x8022F0EC: lbu         $a2, 0x2F0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X2F0);
    // 0x8022F0F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8022F0F4:
    // 0x8022F0F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8022F0F8: sllv        $t7, $t6, $a3
    ctx->r15 = S32(ctx->r14 << (ctx->r7 & 31));
    // 0x8022F0FC: and         $t8, $a2, $t7
    ctx->r24 = ctx->r6 & ctx->r15;
    // 0x8022F100: beq         $t8, $zero, L_8022F118
    if (ctx->r24 == 0) {
        // 0x8022F104: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8022F118;
    }
    // 0x8022F104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8022F108: lhu         $t9, 0x0($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X0);
    // 0x8022F10C: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x8022F110: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8022F114: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8022F118:
    // 0x8022F118: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8022F11C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022F120: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8022F124: bne         $at, $zero, L_8022F0F4
    if (ctx->r1 != 0) {
        // 0x8022F128: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8022F0F4;
    }
    // 0x8022F128: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8022F12C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8022F130: lbu         $t0, 0x2DF($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X2DF);
    // 0x8022F134: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022F138: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8022F13C: ldc1        $f8, -0x518($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X518);
    // 0x8022F140: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8022F144: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8022F148: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8022F14C: bgez        $t0, L_8022F164
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8022F150: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_8022F164;
    }
    // 0x8022F150: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8022F154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8022F158: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022F15C: nop

    // 0x8022F160: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_8022F164:
    // 0x8022F164: div.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8022F168: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022F16C: ldc1        $f8, -0x510($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X510);
    // 0x8022F170: lhu         $t1, 0x50($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X50);
    // 0x8022F174: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022F178: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8022F17C: nop

    // 0x8022F180: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022F184: add.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d + ctx->f8.d;
    // 0x8022F188: bgez        $t1, L_8022F19C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8022F18C: cvt.s.d     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
            goto L_8022F19C;
    }
    // 0x8022F18C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x8022F190: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8022F194: nop

    // 0x8022F198: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8022F19C:
    // 0x8022F19C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8022F1A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8022F1A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022F1A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022F1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022F1B0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022F1B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8022F1B8: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x8022F1BC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8022F1C0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022F1C4: nop

    // 0x8022F1C8: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x8022F1CC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022F1D0: nop

    // 0x8022F1D4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8022F1D8: beql        $t3, $zero, L_8022F22C
    if (ctx->r11 == 0) {
        // 0x8022F1DC: mfc1        $t3, $f18
        ctx->r11 = (int32_t)ctx->f18.u32l;
            goto L_8022F22C;
    }
    goto skip_0;
    // 0x8022F1DC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x8022F1E0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8022F1E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8022F1E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022F1EC: sub.d       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f4.d - ctx->f18.d;
    // 0x8022F1F0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022F1F4: nop

    // 0x8022F1F8: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8022F1FC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022F200: nop

    // 0x8022F204: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8022F208: bne         $t3, $zero, L_8022F220
    if (ctx->r11 != 0) {
        // 0x8022F20C: nop
    
            goto L_8022F220;
    }
    // 0x8022F20C: nop

    // 0x8022F210: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8022F214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022F218: b           L_8022F238
    // 0x8022F21C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8022F238;
    // 0x8022F21C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8022F220:
    // 0x8022F220: b           L_8022F238
    // 0x8022F224: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8022F238;
    // 0x8022F224: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8022F228: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
L_8022F22C:
    // 0x8022F22C: nop

    // 0x8022F230: bltz        $t3, L_8022F220
    if (SIGNED(ctx->r11) < 0) {
        // 0x8022F234: nop
    
            goto L_8022F220;
    }
    // 0x8022F234: nop

L_8022F238:
    // 0x8022F238: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8022F23C: sh          $t3, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r11;
    // 0x8022F240: jr          $ra
    // 0x8022F244: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    return;
    // 0x8022F244: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022f248(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022f248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F248: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8022F24C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8022F250: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8022F254: addiu       $t7, $t7, -0x1CE4
    ctx->r15 = ADD32(ctx->r15, -0X1CE4);
    // 0x8022F258: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8022F25C: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8022F260: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8022F264: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8022F268: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8022F26C: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x8022F270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022F274: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
    // 0x8022F278: lbu         $t1, 0x2F0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2F0);
    // 0x8022F27C: addiu       $v1, $a0, 0x8E
    ctx->r3 = ADD32(ctx->r4, 0X8E);
    // 0x8022F280: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8022F284: beq         $t1, $zero, L_8022F41C
    if (ctx->r9 == 0) {
        // 0x8022F288: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8022F41C;
    }
    // 0x8022F288: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8022F28C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8022F290: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8022F294: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8022F298: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8022F29C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8022F2A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022F2A4: addiu       $t0, $sp, 0x14
    ctx->r8 = ADD32(ctx->r29, 0X14);
L_8022F2A8:
    // 0x8022F2A8: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8022F2AC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8022F2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8022F2B4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8022F2B8: addu        $a1, $t0, $t2
    ctx->r5 = ADD32(ctx->r8, ctx->r10);
    // 0x8022F2BC: bgez        $t3, L_8022F2D4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8022F2C0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022F2D4;
    }
    // 0x8022F2C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022F2C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022F2C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8022F2CC: nop

    // 0x8022F2D0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8022F2D4:
    // 0x8022F2D4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8022F2D8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8022F2DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8022F2E0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022F2E4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8022F2E8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8022F2EC: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8022F2F0: nop

    // 0x8022F2F4: bc1fl       L_8022F304
    if (!c1cs) {
        // 0x8022F2F8: lbu         $t4, 0x2F0($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X2F0);
            goto L_8022F304;
    }
    goto skip_0;
    // 0x8022F2F8: lbu         $t4, 0x2F0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2F0);
    skip_0:
    // 0x8022F2FC: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8022F300: lbu         $t4, 0x2F0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2F0);
L_8022F304:
    // 0x8022F304: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8022F308: sllv        $t6, $t5, $a2
    ctx->r14 = S32(ctx->r13 << (ctx->r6 & 31));
    // 0x8022F30C: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x8022F310: beq         $t7, $zero, L_8022F330
    if (ctx->r15 == 0) {
        // 0x8022F314: nop
    
            goto L_8022F330;
    }
    // 0x8022F314: nop

    // 0x8022F318: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8022F31C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8022F320: nop

    // 0x8022F324: bc1f        L_8022F330
    if (!c1cs) {
        // 0x8022F328: nop
    
            goto L_8022F330;
    }
    // 0x8022F328: nop

    // 0x8022F32C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8022F330:
    // 0x8022F330: bne         $at, $zero, L_8022F2A8
    if (ctx->r1 != 0) {
        // 0x8022F334: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8022F2A8;
    }
    // 0x8022F334: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8022F338: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8022F33C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8022F340:
    // 0x8022F340: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x8022F344: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8022F348: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8022F34C: sllv        $t2, $t1, $v1
    ctx->r10 = S32(ctx->r9 << (ctx->r3 & 31));
    // 0x8022F350: div.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8022F354: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8022F358: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8022F35C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8022F360: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8022F364: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8022F368: lbu         $t9, 0x2F0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2F0);
    // 0x8022F36C: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x8022F370: beq         $t3, $zero, L_8022F380
    if (ctx->r11 == 0) {
        // 0x8022F374: nop
    
            goto L_8022F380;
    }
    // 0x8022F374: nop

    // 0x8022F378: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8022F37C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_8022F380:
    // 0x8022F380: bnel        $at, $zero, L_8022F340
    if (ctx->r1 != 0) {
        // 0x8022F384: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8022F340;
    }
    goto skip_1;
    // 0x8022F384: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    skip_1:
    // 0x8022F388: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x8022F38C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8022F390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022F394: addiu       $a1, $a0, 0x2B8
    ctx->r5 = ADD32(ctx->r4, 0X2B8);
    // 0x8022F398: bc1f        L_8022F3A4
    if (!c1cs) {
        // 0x8022F39C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8022F3A4;
    }
    // 0x8022F39C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022F3A0: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_8022F3A4:
    // 0x8022F3A4: bgez        $a3, L_8022F3BC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022F3A8: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8022F3BC;
    }
    // 0x8022F3A8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022F3AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8022F3B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022F3B4: nop

    // 0x8022F3B8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8022F3BC:
    // 0x8022F3BC: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
L_8022F3C0:
    // 0x8022F3C0: lbu         $t5, 0x2F0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X2F0);
    // 0x8022F3C4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022F3C8: sllv        $t6, $t4, $a2
    ctx->r14 = S32(ctx->r12 << (ctx->r6 & 31));
    // 0x8022F3CC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8022F3D0: beq         $t7, $zero, L_8022F404
    if (ctx->r15 == 0) {
        // 0x8022F3D4: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8022F404;
    }
    // 0x8022F3D4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8022F3D8: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8022F3DC: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8022F3E0: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x8022F3E4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8022F3E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8022F3EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8022F3F0: nop

    // 0x8022F3F4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8022F3F8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8022F3FC: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x8022F400: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
L_8022F404:
    // 0x8022F404: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8022F408: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8022F40C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022F410: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8022F414: bne         $at, $zero, L_8022F3C0
    if (ctx->r1 != 0) {
        // 0x8022F418: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8022F3C0;
    }
    // 0x8022F418: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8022F41C:
    // 0x8022F41C: jr          $ra
    // 0x8022F420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8022F420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022f424(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022f424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F424: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022F428: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8022F42C: lbu         $v0, 0x1030($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1030);
    // 0x8022F430: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8022F434: addiu       $v1, $v1, -0x234A
    ctx->r3 = ADD32(ctx->r3, -0X234A);
    // 0x8022F438: bne         $v0, $zero, L_8022F44C
    if (ctx->r2 != 0) {
        // 0x8022F43C: nop
    
            goto L_8022F44C;
    }
    // 0x8022F43C: nop

    // 0x8022F440: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8022F444: b           L_8022F44C
    // 0x8022F448: addiu       $v1, $v1, -0x2358
    ctx->r3 = ADD32(ctx->r3, -0X2358);
        goto L_8022F44C;
    // 0x8022F448: addiu       $v1, $v1, -0x2358
    ctx->r3 = ADD32(ctx->r3, -0X2358);
L_8022F44C:
    // 0x8022F44C: bnel        $v0, $zero, L_8022F464
    if (ctx->r2 != 0) {
        // 0x8022F450: lbu         $a0, 0x73C($a2)
        ctx->r4 = MEM_BU(ctx->r6, 0X73C);
            goto L_8022F464;
    }
    goto skip_0;
    // 0x8022F450: lbu         $a0, 0x73C($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X73C);
    skip_0:
    // 0x8022F454: lw          $t6, 0x720($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X720);
    // 0x8022F458: b           L_8022F464
    // 0x8022F45C: lbu         $a0, 0xB($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XB);
        goto L_8022F464;
    // 0x8022F45C: lbu         $a0, 0xB($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XB);
    // 0x8022F460: lbu         $a0, 0x73C($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X73C);
L_8022F464:
    // 0x8022F464: lhu         $a1, 0x2C($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2C);
    // 0x8022F468: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022F46C: beq         $a1, $at, L_8022F550
    if (ctx->r5 == ctx->r1) {
        // 0x8022F470: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8022F550;
    }
    // 0x8022F470: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8022F474: beq         $a1, $at, L_8022F550
    if (ctx->r5 == ctx->r1) {
        // 0x8022F478: nop
    
            goto L_8022F550;
    }
    // 0x8022F478: nop

    // 0x8022F47C: bne         $v0, $zero, L_8022F4D4
    if (ctx->r2 != 0) {
        // 0x8022F480: nop
    
            goto L_8022F4D4;
    }
    // 0x8022F480: nop

    // 0x8022F484: lbu         $a1, 0x725($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X725);
    // 0x8022F488: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8022F48C: beq         $a1, $at, L_8022F4B4
    if (ctx->r5 == ctx->r1) {
        // 0x8022F490: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_8022F4B4;
    }
    // 0x8022F490: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x8022F494: beq         $a1, $at, L_8022F4B4
    if (ctx->r5 == ctx->r1) {
        // 0x8022F498: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_8022F4B4;
    }
    // 0x8022F498: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8022F49C: beq         $a1, $at, L_8022F4B4
    if (ctx->r5 == ctx->r1) {
        // 0x8022F4A0: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_8022F4B4;
    }
    // 0x8022F4A0: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x8022F4A4: beq         $a1, $at, L_8022F4B4
    if (ctx->r5 == ctx->r1) {
        // 0x8022F4A8: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_8022F4B4;
    }
    // 0x8022F4A8: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8022F4AC: bne         $a1, $at, L_8022F4D4
    if (ctx->r5 != ctx->r1) {
        // 0x8022F4B0: nop
    
            goto L_8022F4D4;
    }
    // 0x8022F4B0: nop

L_8022F4B4:
    // 0x8022F4B4: lw          $t7, 0x47C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X47C);
    // 0x8022F4B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022F4BC: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8022F4C0: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8022F4C4: bne         $t9, $at, L_8022F4D4
    if (ctx->r25 != ctx->r1) {
        // 0x8022F4C8: nop
    
            goto L_8022F4D4;
    }
    // 0x8022F4C8: nop

    // 0x8022F4CC: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8022F4D0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_8022F4D4:
    // 0x8022F4D4: bne         $v0, $zero, L_8022F50C
    if (ctx->r2 != 0) {
        // 0x8022F4D8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8022F50C;
    }
    // 0x8022F4D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8022F4DC: lbu         $t0, 0x725($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X725);
    // 0x8022F4E0: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x8022F4E4: bnel        $t0, $at, L_8022F510
    if (ctx->r8 != ctx->r1) {
        // 0x8022F4E8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8022F510;
    }
    goto skip_1;
    // 0x8022F4E8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_1:
    // 0x8022F4EC: lw          $t1, 0x47C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X47C);
    // 0x8022F4F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022F4F4: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x8022F4F8: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x8022F4FC: bnel        $t3, $at, L_8022F510
    if (ctx->r11 != ctx->r1) {
        // 0x8022F500: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8022F510;
    }
    goto skip_2;
    // 0x8022F500: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_2:
    // 0x8022F504: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8022F508: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_8022F50C:
    // 0x8022F50C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8022F510:
    // 0x8022F510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8022F514:
    // 0x8022F514: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022F518: sllv        $t5, $t4, $a2
    ctx->r13 = S32(ctx->r12 << (ctx->r6 & 31));
    // 0x8022F51C: and         $t6, $v0, $t5
    ctx->r14 = ctx->r2 & ctx->r13;
    // 0x8022F520: beq         $t6, $zero, L_8022F53C
    if (ctx->r14 == 0) {
        // 0x8022F524: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8022F53C;
    }
    // 0x8022F524: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8022F528: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8022F52C: slti        $at, $a0, 0x270F
    ctx->r1 = SIGNED(ctx->r4) < 0X270F ? 1 : 0;
    // 0x8022F530: beq         $at, $zero, L_8022F53C
    if (ctx->r1 == 0) {
        // 0x8022F534: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_8022F53C;
    }
    // 0x8022F534: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8022F538: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_8022F53C:
    // 0x8022F53C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8022F540: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8022F544: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8022F548: bne         $at, $zero, L_8022F514
    if (ctx->r1 != 0) {
        // 0x8022F54C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8022F514;
    }
    // 0x8022F54C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8022F550:
    // 0x8022F550: jr          $ra
    // 0x8022F554: nop

    return;
    // 0x8022F554: nop

;}
RECOMP_FUNC void M10_FUN_8022f558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F558: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022F55C: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x8022F560: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8022F564: bne         $a0, $t7, L_8022F578
    if (ctx->r4 != ctx->r15) {
        // 0x8022F568: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8022F578;
    }
    // 0x8022F568: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022F56C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022F570: b           L_8022F57C
    // 0x8022F574: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
        goto L_8022F57C;
    // 0x8022F574: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_8022F578:
    // 0x8022F578: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8022F57C:
    // 0x8022F57C: lbu         $v1, 0x2D8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2D8);
    // 0x8022F580: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8022F584: bne         $at, $zero, L_8022F590
    if (ctx->r1 != 0) {
        // 0x8022F588: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8022F590;
    }
    // 0x8022F588: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8022F58C: bne         $at, $zero, L_8022F5AC
    if (ctx->r1 != 0) {
        // 0x8022F590: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8022F5AC;
    }
L_8022F590:
    // 0x8022F590: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8022F594: beq         $v1, $at, L_8022F5AC
    if (ctx->r3 == ctx->r1) {
        // 0x8022F598: nop
    
            goto L_8022F5AC;
    }
    // 0x8022F598: nop

    // 0x8022F59C: lbu         $t8, 0x2DB($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2DB);
    // 0x8022F5A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022F5A4: beq         $t8, $zero, L_8022F5B4
    if (ctx->r24 == 0) {
            // 0x8022F5A8: nop

    LOOKUP_FUNC(0x8022F5B4)(rdram, ctx);
    return;
    }
    // 0x8022F5A8: nop

L_8022F5AC:
    // 0x8022F5AC: jr          $ra
    // 0x8022F5B0: sh          $zero, 0x312($a0)
    MEM_H(0X312, ctx->r4) = 0;
    return;
    // 0x8022F5B0: sh          $zero, 0x312($a0)
    MEM_H(0X312, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022f5b4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022f5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F5B4: beql        $v1, $at, L_8022F5DC
    if (ctx->r3 == ctx->r1) {
        // 0x8022F5B8: lh          $v0, 0x8($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X8);
            goto L_8022F5DC;
    }
    goto skip_0;
    // 0x8022F5B8: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
    skip_0:
    // 0x8022F5BC: lbu         $v0, 0x2F8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2F8);
    // 0x8022F5C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022F5C4: beql        $v0, $at, L_8022F5DC
    if (ctx->r2 == ctx->r1) {
        // 0x8022F5C8: lh          $v0, 0x8($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X8);
            goto L_8022F5DC;
    }
    goto skip_1;
    // 0x8022F5C8: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
    skip_1:
    // 0x8022F5CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8022F5D0: bne         $v0, $at, L_8022F628
    if (ctx->r2 != ctx->r1) {
        // 0x8022F5D4: nop
    
            goto L_8022F628;
    }
    // 0x8022F5D4: nop

    // 0x8022F5D8: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
L_8022F5DC:
    // 0x8022F5DC: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x8022F5E0: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8022F5E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8022F5E8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8022F5EC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8022F5F0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8022F5F4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8022F5F8: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x8022F5FC: mflo        $t2
    ctx->r10 = lo;
    // 0x8022F600: sh          $t2, 0x312($a0)
    MEM_H(0X312, ctx->r4) = ctx->r10;
    // 0x8022F604: bne         $v0, $zero, L_8022F610
    if (ctx->r2 != 0) {
        // 0x8022F608: nop
    
            goto L_8022F610;
    }
    // 0x8022F608: nop

    // 0x8022F60C: break       7
    do_break(2149774860);
L_8022F610:
    // 0x8022F610: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022F614: bne         $v0, $at, L_8022F628
    if (ctx->r2 != ctx->r1) {
        // 0x8022F618: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022F628;
    }
    // 0x8022F618: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022F61C: bne         $t1, $at, L_8022F628
    if (ctx->r9 != ctx->r1) {
        // 0x8022F620: nop
    
            goto L_8022F628;
    }
    // 0x8022F620: nop

    // 0x8022F624: break       6
    do_break(2149774884);
L_8022F628:
    // 0x8022F628: jr          $ra
    // 0x8022F62C: nop

    return;
    // 0x8022F62C: nop

;}
RECOMP_FUNC void M10_FUN_8022f630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F630: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8022F634: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8022F638: bne         $a1, $zero, L_8022F65C
    if (ctx->r5 != 0) {
            // 0x8022F63C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    LOOKUP_FUNC(0x8022F65C)(rdram, ctx);
    return;
    }
    // 0x8022F63C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8022F640: lh          $v0, 0x2C4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C4);
    // 0x8022F644: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x8022F648: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8022F64C: subu        $v0, $v0, $at
    ctx->r2 = SUB32(ctx->r2, ctx->r1);
    // 0x8022F650: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8022F654: jr          $ra
    // 0x8022F658: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x8022F658: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022f65c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022f65c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F65C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8022F660: lh          $v0, 0x2C4($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2C4);
    // 0x8022F664: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x8022F668: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8022F66C: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x8022F670: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8022F674: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8022F678: jr          $ra
    // 0x8022F67C: nop

    return;
    // 0x8022F67C: nop

;}
RECOMP_FUNC void M10_FUN_8022f680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8022F684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8022F688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8022F68C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8022F690: lh          $t6, 0x2B8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2B8);
    // 0x8022F694: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8022F698: bgezl       $t6, L_8022F6D0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8022F69C: lh          $t1, 0x2BA($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X2BA);
            goto L_8022F6D0;
    }
    goto skip_0;
    // 0x8022F69C: lh          $t1, 0x2BA($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2BA);
    skip_0:
    // 0x8022F6A0: lh          $t7, 0x2AC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2AC);
    // 0x8022F6A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8022F6A8: bnel        $t7, $zero, L_8022F6D0
    if (ctx->r15 != 0) {
        // 0x8022F6AC: lh          $t1, 0x2BA($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X2BA);
            goto L_8022F6D0;
    }
    goto skip_1;
    // 0x8022F6AC: lh          $t1, 0x2BA($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2BA);
    skip_1:
    // 0x8022F6B0: jal         0x8022F630
    // 0x8022F6B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8022F630)(rdram, ctx);
        goto after_0;
    // 0x8022F6B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8022F6B8: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x8022F6BC: sh          $v0, 0x2AC($s0)
    MEM_H(0X2AC, ctx->r16) = ctx->r2;
    // 0x8022F6C0: andi        $t9, $t8, 0xFFE1
    ctx->r25 = ctx->r24 & 0XFFE1;
    // 0x8022F6C4: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x8022F6C8: sb          $t0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r8;
    // 0x8022F6CC: lh          $t1, 0x2BA($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2BA);
L_8022F6D0:
    // 0x8022F6D0: bgezl       $t1, L_8022F6F8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8022F6D4: lh          $t3, 0x2BC($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X2BC);
            goto L_8022F6F8;
    }
    goto skip_2;
    // 0x8022F6D4: lh          $t3, 0x2BC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2BC);
    skip_2:
    // 0x8022F6D8: lh          $t2, 0x2AE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2AE);
    // 0x8022F6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022F6E0: bnel        $t2, $zero, L_8022F6F8
    if (ctx->r10 != 0) {
        // 0x8022F6E4: lh          $t3, 0x2BC($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X2BC);
            goto L_8022F6F8;
    }
    goto skip_3;
    // 0x8022F6E4: lh          $t3, 0x2BC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2BC);
    skip_3:
    // 0x8022F6E8: jal         0x8022F630
    // 0x8022F6EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8022F630)(rdram, ctx);
        goto after_1;
    // 0x8022F6EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8022F6F0: sh          $v0, 0x2AE($s0)
    MEM_H(0X2AE, ctx->r16) = ctx->r2;
    // 0x8022F6F4: lh          $t3, 0x2BC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2BC);
L_8022F6F8:
    // 0x8022F6F8: bgezl       $t3, L_8022F758
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8022F6FC: lh          $t5, 0x2BE($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2BE);
            goto L_8022F758;
    }
    goto skip_4;
    // 0x8022F6FC: lh          $t5, 0x2BE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2BE);
    skip_4:
    // 0x8022F700: lh          $t4, 0x2B0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2B0);
    // 0x8022F704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022F708: bnel        $t4, $zero, L_8022F758
    if (ctx->r12 != 0) {
        // 0x8022F70C: lh          $t5, 0x2BE($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2BE);
            goto L_8022F758;
    }
    goto skip_5;
    // 0x8022F70C: lh          $t5, 0x2BE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2BE);
    skip_5:
    // 0x8022F710: jal         0x8022F630
    // 0x8022F714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8022F630)(rdram, ctx);
        goto after_2;
    // 0x8022F714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8022F718: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022F71C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8022F720: sh          $v0, 0x2B0($s0)
    MEM_H(0X2B0, ctx->r16) = ctx->r2;
    // 0x8022F724: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8022F728: nop

    // 0x8022F72C: bc1fl       L_8022F758
    if (!c1cs) {
        // 0x8022F730: lh          $t5, 0x2BE($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2BE);
            goto L_8022F758;
    }
    goto skip_6;
    // 0x8022F730: lh          $t5, 0x2BE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2BE);
    skip_6:
    // 0x8022F734: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8022F738: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022F73C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8022F740: ldc1        $f10, -0x508($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X508);
    // 0x8022F744: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8022F748: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8022F74C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8022F750: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8022F754: lh          $t5, 0x2BE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2BE);
L_8022F758:
    // 0x8022F758: bgezl       $t5, L_8022F7B8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8022F75C: lh          $t7, 0x2C0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2C0);
            goto L_8022F7B8;
    }
    goto skip_7;
    // 0x8022F75C: lh          $t7, 0x2C0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2C0);
    skip_7:
    // 0x8022F760: lh          $t6, 0x2B2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2B2);
    // 0x8022F764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022F768: bnel        $t6, $zero, L_8022F7B8
    if (ctx->r14 != 0) {
        // 0x8022F76C: lh          $t7, 0x2C0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2C0);
            goto L_8022F7B8;
    }
    goto skip_8;
    // 0x8022F76C: lh          $t7, 0x2C0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2C0);
    skip_8:
    // 0x8022F770: jal         0x8022F630
    // 0x8022F774: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8022F630)(rdram, ctx);
        goto after_3;
    // 0x8022F774: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8022F778: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022F77C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8022F780: sh          $v0, 0x2B2($s0)
    MEM_H(0X2B2, ctx->r16) = ctx->r2;
    // 0x8022F784: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8022F788: nop

    // 0x8022F78C: bc1fl       L_8022F7B8
    if (!c1cs) {
        // 0x8022F790: lh          $t7, 0x2C0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2C0);
            goto L_8022F7B8;
    }
    goto skip_9;
    // 0x8022F790: lh          $t7, 0x2C0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2C0);
    skip_9:
    // 0x8022F794: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8022F798: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022F79C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8022F7A0: ldc1        $f10, -0x500($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X500);
    // 0x8022F7A4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8022F7A8: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8022F7AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8022F7B0: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8022F7B4: lh          $t7, 0x2C0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2C0);
L_8022F7B8:
    // 0x8022F7B8: bgezl       $t7, L_8022F7FC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8022F7BC: lh          $t1, 0x2C2($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X2C2);
            goto L_8022F7FC;
    }
    goto skip_10;
    // 0x8022F7BC: lh          $t1, 0x2C2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2C2);
    skip_10:
    // 0x8022F7C0: lh          $t8, 0x2B4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2B4);
    // 0x8022F7C4: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8022F7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022F7CC: bne         $t8, $zero, L_8022F7F8
    if (ctx->r24 != 0) {
        // 0x8022F7D0: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8022F7F8;
    }
    // 0x8022F7D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8022F7D4: jal         0x8022F630
    // 0x8022F7D8: sh          $t9, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x8022F630)(rdram, ctx);
        goto after_4;
    // 0x8022F7D8: sh          $t9, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r25;
    after_4:
    // 0x8022F7DC: sh          $v0, 0x2B4($s0)
    MEM_H(0X2B4, ctx->r16) = ctx->r2;
    // 0x8022F7E0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022F7E4: addiu       $a1, $a1, -0x6924
    ctx->r5 = ADD32(ctx->r5, -0X6924);
    // 0x8022F7E8: jal         0x80005670
    // 0x8022F7EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x8022F7EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8022F7F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8022F7F4: sb          $t0, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r8;
L_8022F7F8:
    // 0x8022F7F8: lh          $t1, 0x2C2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2C2);
L_8022F7FC:
    // 0x8022F7FC: bgezl       $t1, L_8022F840
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8022F800: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8022F840;
    }
    goto skip_11;
    // 0x8022F800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x8022F804: lh          $t2, 0x2B6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2B6);
    // 0x8022F808: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8022F80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022F810: bne         $t2, $zero, L_8022F83C
    if (ctx->r10 != 0) {
        // 0x8022F814: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8022F83C;
    }
    // 0x8022F814: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8022F818: jal         0x8022F630
    // 0x8022F81C: sh          $t3, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x8022F630)(rdram, ctx);
        goto after_6;
    // 0x8022F81C: sh          $t3, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r11;
    after_6:
    // 0x8022F820: sh          $v0, 0x2B6($s0)
    MEM_H(0X2B6, ctx->r16) = ctx->r2;
    // 0x8022F824: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8022F828: addiu       $a1, $a1, -0x6924
    ctx->r5 = ADD32(ctx->r5, -0X6924);
    // 0x8022F82C: jal         0x80005670
    // 0x8022F830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_7;
    // 0x8022F830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8022F834: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8022F838: sb          $t4, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r12;
L_8022F83C:
    // 0x8022F83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8022F840:
    // 0x8022F840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8022F844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8022F848: jr          $ra
    // 0x8022F84C: nop

    return;
    // 0x8022F84C: nop

;}
RECOMP_FUNC void M10_FUN_8022f850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F850: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8022F854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022F858: addiu       $v1, $a0, 0x2AC
    ctx->r3 = ADD32(ctx->r4, 0X2AC);
    // 0x8022F85C: addiu       $a1, $a0, 0x2C4
    ctx->r5 = ADD32(ctx->r4, 0X2C4);
    // 0x8022F860: addiu       $a2, $a0, 0x2B8
    ctx->r6 = ADD32(ctx->r4, 0X2B8);
    // 0x8022F864: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
L_8022F868:
    // 0x8022F868: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8022F86C: blez        $a3, L_8022F978
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8022F870: addiu       $t6, $a3, -0x1
        ctx->r14 = ADD32(ctx->r7, -0X1);
            goto L_8022F978;
    }
    // 0x8022F870: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x8022F874: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8022F878: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x8022F87C: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x8022F880: bnel        $t7, $zero, L_8022F97C
    if (ctx->r15 != 0) {
        // 0x8022F884: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8022F97C;
    }
    goto skip_0;
    // 0x8022F884: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8022F888: beq         $at, $zero, L_8022F910
    if (ctx->r1 == 0) {
        // 0x8022F88C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8022F910;
    }
    // 0x8022F88C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8022F890: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022F894: addu        $at, $at, $t8
    gpr jr_addend_8022F89C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8022F898: lw          $t8, -0x4F8($at)
    ctx->r24 = ADD32(ctx->r1, -0X4F8);
    // 0x8022F89C: jr          $t8
    // 0x8022F8A0: nop

    switch (jr_addend_8022F89C >> 2) {
        case 0: goto L_8022F8A4; break;
        case 1: goto L_8022F910; break;
        case 2: goto L_8022F8B4; break;
        case 3: goto L_8022F8D0; break;
        case 4: goto L_8022F8EC; break;
        case 5: goto L_8022F900; break;
        default: switch_error(__func__, 0x8022F89C, 0x8023FB08);
    }
    // 0x8022F8A0: nop

L_8022F8A4:
    // 0x8022F8A4: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8022F8A8: andi        $t1, $t9, 0xFFE1
    ctx->r9 = ctx->r25 & 0XFFE1;
    // 0x8022F8AC: b           L_8022F910
    // 0x8022F8B0: sb          $t1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r9;
        goto L_8022F910;
    // 0x8022F8B0: sb          $t1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r9;
L_8022F8B4:
    // 0x8022F8B4: lh          $t2, 0x2B2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2B2);
    // 0x8022F8B8: bnel        $t2, $zero, L_8022F914
    if (ctx->r10 != 0) {
        // 0x8022F8BC: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8022F914;
    }
    goto skip_1;
    // 0x8022F8BC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    skip_1:
    // 0x8022F8C0: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8022F8C4: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8022F8C8: b           L_8022F910
    // 0x8022F8CC: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
        goto L_8022F910;
    // 0x8022F8CC: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
L_8022F8D0:
    // 0x8022F8D0: lh          $t3, 0x2B0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2B0);
    // 0x8022F8D4: bnel        $t3, $zero, L_8022F914
    if (ctx->r11 != 0) {
        // 0x8022F8D8: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8022F914;
    }
    goto skip_2;
    // 0x8022F8D8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    skip_2:
    // 0x8022F8DC: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8022F8E0: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8022F8E4: b           L_8022F910
    // 0x8022F8E8: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
        goto L_8022F910;
    // 0x8022F8E8: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
L_8022F8EC:
    // 0x8022F8EC: lh          $t4, 0x2B6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2B6);
    // 0x8022F8F0: bnel        $t4, $zero, L_8022F914
    if (ctx->r12 != 0) {
        // 0x8022F8F4: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8022F914;
    }
    goto skip_3;
    // 0x8022F8F4: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    skip_3:
    // 0x8022F8F8: b           L_8022F910
    // 0x8022F8FC: sh          $zero, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = 0;
        goto L_8022F910;
    // 0x8022F8FC: sh          $zero, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = 0;
L_8022F900:
    // 0x8022F900: lh          $t5, 0x2B4($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2B4);
    // 0x8022F904: bnel        $t5, $zero, L_8022F914
    if (ctx->r13 != 0) {
        // 0x8022F908: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8022F914;
    }
    goto skip_4;
    // 0x8022F908: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    skip_4:
    // 0x8022F90C: sh          $zero, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = 0;
L_8022F910:
    // 0x8022F910: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
L_8022F914:
    // 0x8022F914: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8022F918: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8022F91C: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x8022F920: slti        $at, $a3, 0x65
    ctx->r1 = SIGNED(ctx->r7) < 0X65 ? 1 : 0;
    // 0x8022F924: bnel        $at, $zero, L_8022F938
    if (ctx->r1 != 0) {
        // 0x8022F928: lh          $t8, 0x0($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X0);
            goto L_8022F938;
    }
    goto skip_5;
    // 0x8022F928: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    skip_5:
    // 0x8022F92C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8022F930: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x8022F934: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
L_8022F938:
    // 0x8022F938: multu       $a3, $t8
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022F93C: mflo        $t9
    ctx->r25 = lo;
    // 0x8022F940: nop

    // 0x8022F944: nop

    // 0x8022F948: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x8022F94C: mflo        $t1
    ctx->r9 = lo;
    // 0x8022F950: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x8022F954: bne         $t0, $zero, L_8022F960
    if (ctx->r8 != 0) {
        // 0x8022F958: nop
    
            goto L_8022F960;
    }
    // 0x8022F958: nop

    // 0x8022F95C: break       7
    do_break(2149775708);
L_8022F960:
    // 0x8022F960: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022F964: bne         $t0, $at, L_8022F978
    if (ctx->r8 != ctx->r1) {
        // 0x8022F968: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022F978;
    }
    // 0x8022F968: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022F96C: bne         $t9, $at, L_8022F978
    if (ctx->r25 != ctx->r1) {
        // 0x8022F970: nop
    
            goto L_8022F978;
    }
    // 0x8022F970: nop

    // 0x8022F974: break       6
    do_break(2149775732);
L_8022F978:
    // 0x8022F978: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8022F97C:
    // 0x8022F97C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8022F980: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8022F984: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8022F988: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8022F98C: bne         $at, $zero, L_8022F868
    if (ctx->r1 != 0) {
        // 0x8022F990: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8022F868;
    }
    // 0x8022F990: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8022F994: jr          $ra
    // 0x8022F998: nop

    return;
    // 0x8022F998: nop

;}
RECOMP_FUNC void M10_FUN_8022f99c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022F99C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022F9A0: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8022F9A4: addiu       $v0, $a0, -0x44C
    ctx->r2 = ADD32(ctx->r4, -0X44C);
    // 0x8022F9A8: bne         $v0, $a3, L_8022F9BC
    if (ctx->r2 != ctx->r7) {
        // 0x8022F9AC: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8022F9BC;
    }
    // 0x8022F9AC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022F9B0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022F9B4: b           L_8022F9C0
    // 0x8022F9B8: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
        goto L_8022F9C0;
    // 0x8022F9B8: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8022F9BC:
    // 0x8022F9BC: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8022F9C0:
    // 0x8022F9C0: bne         $v0, $a3, L_8022F9D0
    if (ctx->r2 != ctx->r7) {
        // 0x8022F9C4: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8022F9D0;
    }
    // 0x8022F9C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8022F9C8: b           L_8022F9D4
    // 0x8022F9CC: lw          $v0, 0xDC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XDC);
        goto L_8022F9D4;
    // 0x8022F9CC: lw          $v0, 0xDC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XDC);
L_8022F9D0:
    // 0x8022F9D0: lw          $v0, 0xEC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XEC);
L_8022F9D4:
    // 0x8022F9D4: lbu         $t6, 0xA6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XA6);
    // 0x8022F9D8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8022F9DC: beql        $t7, $zero, L_8022F9F0
    if (ctx->r15 == 0) {
        // 0x8022F9E0: lw          $a1, 0x38($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X38);
            goto L_8022F9F0;
    }
    goto skip_0;
    // 0x8022F9E0: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
    skip_0:
    // 0x8022F9E4: b           L_8022FB04
    // 0x8022F9E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022FB04;
    // 0x8022F9E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022F9EC: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
L_8022F9F0:
    // 0x8022F9F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8022F9F4: sll         $a2, $a1, 1
    ctx->r6 = S32(ctx->r5 << 1);
    // 0x8022F9F8: srl         $a2, $a2, 30
    ctx->r6 = S32(U32(ctx->r6) >> 30);
    // 0x8022F9FC: beql        $t0, $a2, L_8022FA30
    if (ctx->r8 == ctx->r6) {
        // 0x8022FA00: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8022FA30;
    }
    goto skip_1;
    // 0x8022FA00: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    skip_1:
    // 0x8022FA04: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8022FA08: beql        $t1, $a2, L_8022FA30
    if (ctx->r9 == ctx->r6) {
        // 0x8022FA0C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8022FA30;
    }
    goto skip_2;
    // 0x8022FA0C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    skip_2:
    // 0x8022FA10: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    // 0x8022FA14: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8022FA18: srl         $a2, $a2, 30
    ctx->r6 = S32(U32(ctx->r6) >> 30);
    // 0x8022FA1C: beql        $t0, $a2, L_8022FA30
    if (ctx->r8 == ctx->r6) {
        // 0x8022FA20: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8022FA30;
    }
    goto skip_3;
    // 0x8022FA20: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    skip_3:
    // 0x8022FA24: bne         $t1, $a2, L_8022FA38
    if (ctx->r9 != ctx->r6) {
        // 0x8022FA28: srl         $t8, $a1, 31
        ctx->r24 = S32(U32(ctx->r5) >> 31);
            goto L_8022FA38;
    }
    // 0x8022FA28: srl         $t8, $a1, 31
    ctx->r24 = S32(U32(ctx->r5) >> 31);
    // 0x8022FA2C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8022FA30:
    // 0x8022FA30: b           L_8022FB04
    // 0x8022FA34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_8022FB04;
    // 0x8022FA34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_8022FA38:
    // 0x8022FA38: beq         $t8, $zero, L_8022FA48
    if (ctx->r24 == 0) {
        // 0x8022FA3C: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8022FA48;
    }
    // 0x8022FA3C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8022FA40: b           L_8022FB04
    // 0x8022FA44: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
        goto L_8022FB04;
    // 0x8022FA44: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8022FA48:
    // 0x8022FA48: lh          $t9, 0x2BA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2BA);
    // 0x8022FA4C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8022FA50: bgezl       $t9, L_8022FA64
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8022FA54: lhu         $t2, 0x32($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X32);
            goto L_8022FA64;
    }
    goto skip_4;
    // 0x8022FA54: lhu         $t2, 0x32($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X32);
    skip_4:
    // 0x8022FA58: b           L_8022FB04
    // 0x8022FA5C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_8022FB04;
    // 0x8022FA5C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8022FA60: lhu         $t2, 0x32($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X32);
L_8022FA64:
    // 0x8022FA64: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8022FA68: srl         $t3, $t2, 13
    ctx->r11 = S32(U32(ctx->r10) >> 13);
    // 0x8022FA6C: bnel        $t3, $at, L_8022FB00
    if (ctx->r11 != ctx->r1) {
        // 0x8022FA70: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8022FB00;
    }
    goto skip_5;
    // 0x8022FA70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    skip_5:
    // 0x8022FA74: lhu         $v1, 0x36($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X36);
    // 0x8022FA78: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x8022FA7C: beql        $v1, $at, L_8022FA94
    if (ctx->r3 == ctx->r1) {
        // 0x8022FA80: lhu         $t4, 0x2C($a3)
        ctx->r12 = MEM_HU(ctx->r7, 0X2C);
            goto L_8022FA94;
    }
    goto skip_6;
    // 0x8022FA80: lhu         $t4, 0x2C($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X2C);
    skip_6:
    // 0x8022FA84: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x8022FA88: bnel        $v1, $at, L_8022FAA4
    if (ctx->r3 != ctx->r1) {
        // 0x8022FA8C: lbu         $v1, 0x2C($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X2C);
            goto L_8022FAA4;
    }
    goto skip_7;
    // 0x8022FA8C: lbu         $v1, 0x2C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2C);
    skip_7:
    // 0x8022FA90: lhu         $t4, 0x2C($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X2C);
L_8022FA94:
    // 0x8022FA94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8022FA98: bnel        $a1, $t4, L_8022FB00
    if (ctx->r5 != ctx->r12) {
        // 0x8022FA9C: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8022FB00;
    }
    goto skip_8;
    // 0x8022FA9C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    skip_8:
    // 0x8022FAA0: lbu         $v1, 0x2C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2C);
L_8022FAA4:
    // 0x8022FAA4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8022FAA8: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8022FAAC: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x8022FAB0: mfhi        $v0
    ctx->r2 = hi;
    // 0x8022FAB4: xori        $v0, $v0, 0x9
    ctx->r2 = ctx->r2 ^ 0X9;
    // 0x8022FAB8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8022FABC: bne         $a1, $zero, L_8022FAC8
    if (ctx->r5 != 0) {
        // 0x8022FAC0: nop
    
            goto L_8022FAC8;
    }
    // 0x8022FAC0: nop

    // 0x8022FAC4: break       7
    do_break(2149776068);
L_8022FAC8:
    // 0x8022FAC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FACC: bne         $a1, $at, L_8022FAE0
    if (ctx->r5 != ctx->r1) {
        // 0x8022FAD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FAE0;
    }
    // 0x8022FAD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FAD4: bne         $v1, $at, L_8022FAE0
    if (ctx->r3 != ctx->r1) {
        // 0x8022FAD8: nop
    
            goto L_8022FAE0;
    }
    // 0x8022FAD8: nop

    // 0x8022FADC: break       6
    do_break(2149776092);
L_8022FAE0:
    // 0x8022FAE0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8022FAE4: beq         $v0, $zero, L_8022FAF4
    if (ctx->r2 == 0) {
        // 0x8022FAE8: sb          $t5, 0x2C($a0)
        MEM_B(0X2C, ctx->r4) = ctx->r13;
            goto L_8022FAF4;
    }
    // 0x8022FAE8: sb          $t5, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r13;
    // 0x8022FAEC: jr          $ra
    // 0x8022FAF0: sh          $t6, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r14;
    return;
    // 0x8022FAF0: sh          $t6, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r14;
L_8022FAF4:
    // 0x8022FAF4: jr          $ra
    // 0x8022FAF8: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    return;
    // 0x8022FAF8: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    // 0x8022FAFC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_8022FB00:
    // 0x8022FB00: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8022FB04:
    // 0x8022FB04: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x8022FB08: lh          $t8, 0x4A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4A);
    // 0x8022FB0C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8022FB10: bnel        $at, $zero, L_8022FB28
    if (ctx->r1 != 0) {
        // 0x8022FB14: lhu         $t9, 0x9E($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X9E);
            goto L_8022FB28;
    }
    goto skip_9;
    // 0x8022FB14: lhu         $t9, 0x9E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X9E);
    skip_9:
    // 0x8022FB18: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    // 0x8022FB1C: jr          $ra
    // 0x8022FB20: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    return;
    // 0x8022FB20: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    // 0x8022FB24: lhu         $t9, 0x9E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X9E);
L_8022FB28:
    // 0x8022FB28: beql        $t9, $zero, L_8022FB40
    if (ctx->r25 == 0) {
        // 0x8022FB2C: lhu         $t2, 0x30($a3)
        ctx->r10 = MEM_HU(ctx->r7, 0X30);
            goto L_8022FB40;
    }
    goto skip_10;
    // 0x8022FB2C: lhu         $t2, 0x30($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X30);
    skip_10:
    // 0x8022FB30: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    // 0x8022FB34: jr          $ra
    // 0x8022FB38: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    return;
    // 0x8022FB38: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    // 0x8022FB3C: lhu         $t2, 0x30($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X30);
L_8022FB40:
    // 0x8022FB40: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x8022FB44: mfhi        $t3
    ctx->r11 = hi;
    // 0x8022FB48: bne         $v0, $zero, L_8022FB54
    if (ctx->r2 != 0) {
        // 0x8022FB4C: nop
    
            goto L_8022FB54;
    }
    // 0x8022FB4C: nop

    // 0x8022FB50: break       7
    do_break(2149776208);
L_8022FB54:
    // 0x8022FB54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FB58: bne         $v0, $at, L_8022FB6C
    if (ctx->r2 != ctx->r1) {
        // 0x8022FB5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FB6C;
    }
    // 0x8022FB5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FB60: bne         $t2, $at, L_8022FB6C
    if (ctx->r10 != ctx->r1) {
        // 0x8022FB64: nop
    
            goto L_8022FB6C;
    }
    // 0x8022FB64: nop

    // 0x8022FB68: break       6
    do_break(2149776232);
L_8022FB6C:
    // 0x8022FB6C: bnel        $t3, $zero, L_8022FC30
    if (ctx->r11 != 0) {
        // 0x8022FB70: sh          $zero, 0x60($a0)
        MEM_H(0X60, ctx->r4) = 0;
            goto L_8022FC30;
    }
    goto skip_11;
    // 0x8022FB70: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    skip_11:
    // 0x8022FB74: lhu         $v1, 0x64($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X64);
    // 0x8022FB78: lhu         $t4, 0x68($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X68);
    // 0x8022FB7C: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x8022FB80: mfhi        $t5
    ctx->r13 = hi;
    // 0x8022FB84: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8022FB88: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8022FB8C: mflo        $t7
    ctx->r15 = lo;
    // 0x8022FB90: sh          $t6, 0x68($a0)
    MEM_H(0X68, ctx->r4) = ctx->r14;
    // 0x8022FB94: bne         $a1, $zero, L_8022FBA0
    if (ctx->r5 != 0) {
        // 0x8022FB98: nop
    
            goto L_8022FBA0;
    }
    // 0x8022FB98: nop

    // 0x8022FB9C: break       7
    do_break(2149776284);
L_8022FBA0:
    // 0x8022FBA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FBA4: bne         $a1, $at, L_8022FBB8
    if (ctx->r5 != ctx->r1) {
        // 0x8022FBA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FBB8;
    }
    // 0x8022FBA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FBAC: bne         $v1, $at, L_8022FBB8
    if (ctx->r3 != ctx->r1) {
        // 0x8022FBB0: nop
    
            goto L_8022FBB8;
    }
    // 0x8022FBB0: nop

    // 0x8022FBB4: break       6
    do_break(2149776308);
L_8022FBB8:
    // 0x8022FBB8: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x8022FBBC: bne         $a1, $zero, L_8022FBC8
    if (ctx->r5 != 0) {
        // 0x8022FBC0: nop
    
            goto L_8022FBC8;
    }
    // 0x8022FBC0: nop

    // 0x8022FBC4: break       7
    do_break(2149776324);
L_8022FBC8:
    // 0x8022FBC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FBCC: bne         $a1, $at, L_8022FBE0
    if (ctx->r5 != ctx->r1) {
        // 0x8022FBD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FBE0;
    }
    // 0x8022FBD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FBD4: bne         $v0, $at, L_8022FBE0
    if (ctx->r2 != ctx->r1) {
        // 0x8022FBD8: nop
    
            goto L_8022FBE0;
    }
    // 0x8022FBD8: nop

    // 0x8022FBDC: break       6
    do_break(2149776348);
L_8022FBE0:
    // 0x8022FBE0: mflo        $t8
    ctx->r24 = lo;
    // 0x8022FBE4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8022FBE8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8022FBEC: bne         $at, $zero, L_8022FC30
    if (ctx->r1 != 0) {
        // 0x8022FBF0: sh          $t9, 0x60($a0)
        MEM_H(0X60, ctx->r4) = ctx->r25;
            goto L_8022FC30;
    }
    // 0x8022FBF0: sh          $t9, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r25;
    // 0x8022FBF4: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x8022FBF8: mfhi        $t2
    ctx->r10 = hi;
    // 0x8022FBFC: sh          $t2, 0x68($a0)
    MEM_H(0X68, ctx->r4) = ctx->r10;
    // 0x8022FC00: bne         $a1, $zero, L_8022FC0C
    if (ctx->r5 != 0) {
        // 0x8022FC04: nop
    
            goto L_8022FC0C;
    }
    // 0x8022FC04: nop

    // 0x8022FC08: break       7
    do_break(2149776392);
L_8022FC0C:
    // 0x8022FC0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FC10: bne         $a1, $at, L_8022FC24
    if (ctx->r5 != ctx->r1) {
        // 0x8022FC14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FC24;
    }
    // 0x8022FC14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FC18: bne         $v0, $at, L_8022FC24
    if (ctx->r2 != ctx->r1) {
        // 0x8022FC1C: nop
    
            goto L_8022FC24;
    }
    // 0x8022FC1C: nop

    // 0x8022FC20: break       6
    do_break(2149776416);
L_8022FC24:
    // 0x8022FC24: jr          $ra
    // 0x8022FC28: nop

    return;
    // 0x8022FC28: nop

    // 0x8022FC2C: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
L_8022FC30:
    // 0x8022FC30: jr          $ra
    // 0x8022FC34: nop

    return;
    // 0x8022FC34: nop

;}
RECOMP_FUNC void M10_FUN_8022fc38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022FC38: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022FC3C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022fc40(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022fc40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022FC40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8022FC44: addiu       $v0, $a0, -0x44C
    ctx->r2 = ADD32(ctx->r4, -0X44C);
    // 0x8022FC48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022FC4C: bne         $v0, $a2, L_8022FC60
    if (ctx->r2 != ctx->r6) {
        // 0x8022FC50: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8022FC60;
    }
    // 0x8022FC50: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8022FC54: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022FC58: b           L_8022FC68
    // 0x8022FC5C: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
        goto L_8022FC68;
    // 0x8022FC5C: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_8022FC60:
    // 0x8022FC60: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8022FC64: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_8022FC68:
    // 0x8022FC68: bnel        $v0, $a2, L_8022FC84
    if (ctx->r2 != ctx->r6) {
        // 0x8022FC6C: lw          $t8, 0xEC($a2)
        ctx->r24 = MEM_W(ctx->r6, 0XEC);
            goto L_8022FC84;
    }
    goto skip_0;
    // 0x8022FC6C: lw          $t8, 0xEC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XEC);
    skip_0:
    // 0x8022FC70: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // 0x8022FC74: lw          $t7, 0x5C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X5C);
    // 0x8022FC78: b           L_8022FC8C
    // 0x8022FC7C: lw          $a0, 0x1C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1C);
        goto L_8022FC8C;
    // 0x8022FC7C: lw          $a0, 0x1C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1C);
    // 0x8022FC80: lw          $t8, 0xEC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XEC);
L_8022FC84:
    // 0x8022FC84: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8022FC88: lw          $a0, 0x1C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1C);
L_8022FC8C:
    // 0x8022FC8C: bnel        $v0, $a2, L_8022FCA0
    if (ctx->r2 != ctx->r6) {
        // 0x8022FC90: lw          $t2, 0x448($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X448);
            goto L_8022FCA0;
    }
    goto skip_1;
    // 0x8022FC90: lw          $t2, 0x448($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X448);
    skip_1:
    // 0x8022FC94: b           L_8022FCA0
    // 0x8022FC98: lw          $t2, 0x444($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X444);
        goto L_8022FCA0;
    // 0x8022FC98: lw          $t2, 0x444($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X444);
    // 0x8022FC9C: lw          $t2, 0x448($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X448);
L_8022FCA0:
    // 0x8022FCA0: bnel        $v0, $a2, L_8022FCB4
    if (ctx->r2 != ctx->r6) {
        // 0x8022FCA4: lw          $t0, 0xEC($a2)
        ctx->r8 = MEM_W(ctx->r6, 0XEC);
            goto L_8022FCB4;
    }
    goto skip_2;
    // 0x8022FCA4: lw          $t0, 0xEC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XEC);
    skip_2:
    // 0x8022FCA8: b           L_8022FCB4
    // 0x8022FCAC: lw          $t0, 0xDC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XDC);
        goto L_8022FCB4;
    // 0x8022FCAC: lw          $t0, 0xDC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XDC);
    // 0x8022FCB0: lw          $t0, 0xEC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XEC);
L_8022FCB4:
    // 0x8022FCB4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8022FCB8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8022FCBC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8022FCC0: jal         0x8022559C
    // 0x8022FCC4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8022559C)(rdram, ctx);
        goto after_0;
    // 0x8022FCC4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_0:
    // 0x8022FCC8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8022FCCC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022FCD0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8022FCD4: lbu         $t4, 0xA6($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XA6);
    // 0x8022FCD8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8022FCDC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8022FCE0: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x8022FCE4: beq         $t5, $zero, L_8022FCF8
    if (ctx->r13 == 0) {
        // 0x8022FCE8: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_8022FCF8;
    }
    // 0x8022FCE8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8022FCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022FCF0: b           L_8022FDF0
    // 0x8022FCF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8022FDF0;
    // 0x8022FCF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8022FCF8:
    // 0x8022FCF8: lw          $t6, 0x30($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X30);
    // 0x8022FCFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022FD00: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8022FD04: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8022FD08: beql        $t8, $zero, L_8022FD1C
    if (ctx->r24 == 0) {
        // 0x8022FD0C: lw          $v1, 0x38($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X38);
            goto L_8022FD1C;
    }
    goto skip_3;
    // 0x8022FD0C: lw          $v1, 0x38($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X38);
    skip_3:
    // 0x8022FD10: b           L_8022FDF0
    // 0x8022FD14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022FDF0;
    // 0x8022FD14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8022FD18: lw          $v1, 0x38($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X38);
L_8022FD1C:
    // 0x8022FD1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8022FD20: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8022FD24: srl         $a0, $a0, 30
    ctx->r4 = S32(U32(ctx->r4) >> 30);
    // 0x8022FD28: beq         $t3, $a0, L_8022FD54
    if (ctx->r11 == ctx->r4) {
        // 0x8022FD2C: nop
    
            goto L_8022FD54;
    }
    // 0x8022FD2C: nop

    // 0x8022FD30: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8022FD34: beq         $t1, $a0, L_8022FD54
    if (ctx->r9 == ctx->r4) {
        // 0x8022FD38: nop
    
            goto L_8022FD54;
    }
    // 0x8022FD38: nop

    // 0x8022FD3C: lw          $t9, 0x38($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X38);
    // 0x8022FD40: srl         $t6, $v1, 31
    ctx->r14 = S32(U32(ctx->r3) >> 31);
    // 0x8022FD44: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x8022FD48: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x8022FD4C: bne         $t1, $t5, L_8022FD5C
    if (ctx->r9 != ctx->r13) {
        // 0x8022FD50: nop
    
            goto L_8022FD5C;
    }
    // 0x8022FD50: nop

L_8022FD54:
    // 0x8022FD54: b           L_8022FDF0
    // 0x8022FD58: ori         $v0, $zero, 0xFFFD
    ctx->r2 = 0 | 0XFFFD;
        goto L_8022FDF0;
    // 0x8022FD58: ori         $v0, $zero, 0xFFFD
    ctx->r2 = 0 | 0XFFFD;
L_8022FD5C:
    // 0x8022FD5C: beql        $t6, $zero, L_8022FD70
    if (ctx->r14 == 0) {
        // 0x8022FD60: lhu         $t7, 0x32($a1)
        ctx->r15 = MEM_HU(ctx->r5, 0X32);
            goto L_8022FD70;
    }
    goto skip_4;
    // 0x8022FD60: lhu         $t7, 0x32($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X32);
    skip_4:
    // 0x8022FD64: b           L_8022FDF0
    // 0x8022FD68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8022FDF0;
    // 0x8022FD68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8022FD6C: lhu         $t7, 0x32($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X32);
L_8022FD70:
    // 0x8022FD70: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8022FD74: srl         $t8, $t7, 13
    ctx->r24 = S32(U32(ctx->r15) >> 13);
    // 0x8022FD78: beq         $t8, $at, L_8022FD9C
    if (ctx->r24 == ctx->r1) {
        // 0x8022FD7C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8022FD9C;
    }
    // 0x8022FD7C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8022FD80: beq         $v0, $at, L_8022FD9C
    if (ctx->r2 == ctx->r1) {
        // 0x8022FD84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8022FD9C;
    }
    // 0x8022FD84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8022FD88: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8022FD8C: beq         $v0, $at, L_8022FD9C
    if (ctx->r2 == ctx->r1) {
        // 0x8022FD90: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_8022FD9C;
    }
    // 0x8022FD90: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8022FD94: bnel        $v0, $at, L_8022FDF0
    if (ctx->r2 != ctx->r1) {
        // 0x8022FD98: andi        $v0, $t3, 0xFFFF
        ctx->r2 = ctx->r11 & 0XFFFF;
            goto L_8022FDF0;
    }
    goto skip_5;
    // 0x8022FD98: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    skip_5:
L_8022FD9C:
    // 0x8022FD9C: lhu         $v0, 0x36($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X36);
    // 0x8022FDA0: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x8022FDA4: beq         $v0, $at, L_8022FDD4
    if (ctx->r2 == ctx->r1) {
        // 0x8022FDA8: addiu       $at, $zero, 0xF6
        ctx->r1 = ADD32(0, 0XF6);
            goto L_8022FDD4;
    }
    // 0x8022FDA8: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x8022FDAC: beq         $v0, $at, L_8022FDD4
    if (ctx->r2 == ctx->r1) {
        // 0x8022FDB0: addiu       $at, $zero, 0x56
        ctx->r1 = ADD32(0, 0X56);
            goto L_8022FDD4;
    }
    // 0x8022FDB0: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x8022FDB4: beq         $v0, $at, L_8022FDD4
    if (ctx->r2 == ctx->r1) {
        // 0x8022FDB8: addiu       $at, $zero, 0x147
        ctx->r1 = ADD32(0, 0X147);
            goto L_8022FDD4;
    }
    // 0x8022FDB8: addiu       $at, $zero, 0x147
    ctx->r1 = ADD32(0, 0X147);
    // 0x8022FDBC: beq         $v0, $at, L_8022FDD4
    if (ctx->r2 == ctx->r1) {
        // 0x8022FDC0: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_8022FDD4;
    }
    // 0x8022FDC0: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8022FDC4: beq         $v0, $at, L_8022FDD4
    if (ctx->r2 == ctx->r1) {
        // 0x8022FDC8: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_8022FDD4;
    }
    // 0x8022FDC8: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x8022FDCC: bne         $v0, $at, L_8022FDE4
    if (ctx->r2 != ctx->r1) {
        // 0x8022FDD0: nop
    
            goto L_8022FDE4;
    }
    // 0x8022FDD0: nop

L_8022FDD4:
    // 0x8022FDD4: lhu         $t9, 0x2C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2C);
    // 0x8022FDD8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022FDDC: bnel        $t9, $at, L_8022FDF0
    if (ctx->r25 != ctx->r1) {
        // 0x8022FDE0: andi        $v0, $t3, 0xFFFF
        ctx->r2 = ctx->r11 & 0XFFFF;
            goto L_8022FDF0;
    }
    goto skip_6;
    // 0x8022FDE0: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    skip_6:
L_8022FDE4:
    // 0x8022FDE4: b           L_8022FDF0
    // 0x8022FDE8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_8022FDF0;
    // 0x8022FDE8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8022FDEC: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
L_8022FDF0:
    // 0x8022FDF0: lh          $t4, 0xA($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XA);
    // 0x8022FDF4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8022FDF8: slti        $at, $t4, 0x14
    ctx->r1 = SIGNED(ctx->r12) < 0X14 ? 1 : 0;
    // 0x8022FDFC: beql        $at, $zero, L_8022FE10
    if (ctx->r1 == 0) {
        // 0x8022FE00: lh          $t6, 0x6($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X6);
            goto L_8022FE10;
    }
    goto skip_7;
    // 0x8022FE00: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    skip_7:
    // 0x8022FE04: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8022FE08: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8022FE0C: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
L_8022FE10:
    // 0x8022FE10: lhu         $t8, 0x30($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X30);
    // 0x8022FE14: lhu         $t5, 0x62($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X62);
    // 0x8022FE18: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x8022FE1C: mflo        $t7
    ctx->r15 = lo;
    // 0x8022FE20: subu        $v1, $t5, $t7
    ctx->r3 = SUB32(ctx->r13, ctx->r15);
    // 0x8022FE24: bne         $a0, $zero, L_8022FE30
    if (ctx->r4 != 0) {
        // 0x8022FE28: nop
    
            goto L_8022FE30;
    }
    // 0x8022FE28: nop

    // 0x8022FE2C: break       7
    do_break(2149776940);
L_8022FE30:
    // 0x8022FE30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FE34: bne         $a0, $at, L_8022FE48
    if (ctx->r4 != ctx->r1) {
        // 0x8022FE38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FE48;
    }
    // 0x8022FE38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FE3C: bne         $t6, $at, L_8022FE48
    if (ctx->r14 != ctx->r1) {
        // 0x8022FE40: nop
    
            goto L_8022FE48;
    }
    // 0x8022FE40: nop

    // 0x8022FE44: break       6
    do_break(2149776964);
L_8022FE48:
    // 0x8022FE48: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x8022FE4C: mfhi        $t9
    ctx->r25 = hi;
    // 0x8022FE50: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8022FE54: bne         $v0, $zero, L_8022FE60
    if (ctx->r2 != 0) {
        // 0x8022FE58: nop
    
            goto L_8022FE60;
    }
    // 0x8022FE58: nop

    // 0x8022FE5C: break       7
    do_break(2149776988);
L_8022FE60:
    // 0x8022FE60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FE64: bne         $v0, $at, L_8022FE78
    if (ctx->r2 != ctx->r1) {
        // 0x8022FE68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FE78;
    }
    // 0x8022FE68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FE6C: bne         $t8, $at, L_8022FE78
    if (ctx->r24 != ctx->r1) {
        // 0x8022FE70: nop
    
            goto L_8022FE78;
    }
    // 0x8022FE70: nop

    // 0x8022FE74: break       6
    do_break(2149777012);
L_8022FE78:
    // 0x8022FE78: bnel        $t9, $zero, L_8022FEBC
    if (ctx->r25 != 0) {
        // 0x8022FE7C: sh          $zero, 0x5E($a1)
        MEM_H(0X5E, ctx->r5) = 0;
            goto L_8022FEBC;
    }
    goto skip_8;
    // 0x8022FE7C: sh          $zero, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = 0;
    skip_8:
    // 0x8022FE80: lhu         $t4, 0x66($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X66);
    // 0x8022FE84: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x8022FE88: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8022FE8C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8022FE90: bne         $at, $zero, L_8022FEB0
    if (ctx->r1 != 0) {
        // 0x8022FE94: sh          $t6, 0x66($a1)
        MEM_H(0X66, ctx->r5) = ctx->r14;
            goto L_8022FEB0;
    }
    // 0x8022FE94: sh          $t6, 0x66($a1)
    MEM_H(0X66, ctx->r5) = ctx->r14;
    // 0x8022FE98: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022FE9C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8022FEA0: mfhi        $t5
    ctx->r13 = hi;
    // 0x8022FEA4: sh          $t3, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = ctx->r11;
    // 0x8022FEA8: b           L_8022FEBC
    // 0x8022FEAC: sh          $t5, 0x66($a1)
    MEM_H(0X66, ctx->r5) = ctx->r13;
        goto L_8022FEBC;
    // 0x8022FEAC: sh          $t5, 0x66($a1)
    MEM_H(0X66, ctx->r5) = ctx->r13;
L_8022FEB0:
    // 0x8022FEB0: b           L_8022FEBC
    // 0x8022FEB4: sh          $zero, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = 0;
        goto L_8022FEBC;
    // 0x8022FEB4: sh          $zero, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = 0;
    // 0x8022FEB8: sh          $zero, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = 0;
L_8022FEBC:
    // 0x8022FEBC: lbu         $v1, 0x398($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X398);
    // 0x8022FEC0: beql        $v1, $zero, L_8022FF18
    if (ctx->r3 == 0) {
        // 0x8022FEC4: lh          $v0, 0x6($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X6);
            goto L_8022FF18;
    }
    goto skip_9;
    // 0x8022FEC4: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    skip_9:
    // 0x8022FEC8: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x8022FECC: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x8022FED0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8022FED4: beql        $at, $zero, L_8022FF18
    if (ctx->r1 == 0) {
        // 0x8022FED8: lh          $v0, 0x6($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X6);
            goto L_8022FF18;
    }
    goto skip_10;
    // 0x8022FED8: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    skip_10:
    // 0x8022FEDC: lbu         $t9, 0x74($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X74);
    // 0x8022FEE0: bnel        $t9, $zero, L_8022FF18
    if (ctx->r25 != 0) {
        // 0x8022FEE4: lh          $v0, 0x6($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X6);
            goto L_8022FF18;
    }
    goto skip_11;
    // 0x8022FEE4: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    skip_11:
    // 0x8022FEE8: lhu         $t4, 0x2C($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2C);
    // 0x8022FEEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022FEF0: beql        $t4, $at, L_8022FF18
    if (ctx->r12 == ctx->r1) {
        // 0x8022FEF4: lh          $v0, 0x6($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X6);
            goto L_8022FF18;
    }
    goto skip_12;
    // 0x8022FEF4: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    skip_12:
    // 0x8022FEF8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8022FEFC: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x8022FF00: sb          $t6, 0x398($a1)
    MEM_B(0X398, ctx->r5) = ctx->r14;
    // 0x8022FF04: bne         $t5, $zero, L_8022FFC4
    if (ctx->r13 != 0) {
        // 0x8022FF08: sh          $zero, 0x5E($a1)
        MEM_H(0X5E, ctx->r5) = 0;
            goto L_8022FFC4;
    }
    // 0x8022FF08: sh          $zero, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = 0;
    // 0x8022FF0C: b           L_8022FFC4
    // 0x8022FF10: sh          $t3, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = ctx->r11;
        goto L_8022FFC4;
    // 0x8022FF10: sh          $t3, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = ctx->r11;
    // 0x8022FF14: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
L_8022FF18:
    // 0x8022FF18: beql        $v0, $zero, L_8022FFC8
    if (ctx->r2 == 0) {
        // 0x8022FF1C: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_13;
    // 0x8022FF1C: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_13:
    // 0x8022FF20: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x8022FF24: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8022FF28: beql        $at, $zero, L_8022FFC8
    if (ctx->r1 == 0) {
        // 0x8022FF2C: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_14;
    // 0x8022FF2C: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_14:
    // 0x8022FF30: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x8022FF34: mfhi        $t8
    ctx->r24 = hi;
    // 0x8022FF38: bne         $a0, $zero, L_8022FF44
    if (ctx->r4 != 0) {
        // 0x8022FF3C: nop
    
            goto L_8022FF44;
    }
    // 0x8022FF3C: nop

    // 0x8022FF40: break       7
    do_break(2149777216);
L_8022FF44:
    // 0x8022FF44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8022FF48: bne         $a0, $at, L_8022FF5C
    if (ctx->r4 != ctx->r1) {
        // 0x8022FF4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8022FF5C;
    }
    // 0x8022FF4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022FF50: bne         $v0, $at, L_8022FF5C
    if (ctx->r2 != ctx->r1) {
        // 0x8022FF54: nop
    
            goto L_8022FF5C;
    }
    // 0x8022FF54: nop

    // 0x8022FF58: break       6
    do_break(2149777240);
L_8022FF5C:
    // 0x8022FF5C: bnel        $t8, $zero, L_8022FFC8
    if (ctx->r24 != 0) {
        // 0x8022FF60: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_15;
    // 0x8022FF60: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_15:
    // 0x8022FF64: lbu         $t9, 0x74($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X74);
    // 0x8022FF68: bnel        $t9, $zero, L_8022FFC8
    if (ctx->r25 != 0) {
        // 0x8022FF6C: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_16;
    // 0x8022FF6C: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_16:
    // 0x8022FF70: bnel        $v1, $zero, L_8022FFC8
    if (ctx->r3 != 0) {
        // 0x8022FF74: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_17;
    // 0x8022FF74: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_17:
    // 0x8022FF78: lhu         $t4, 0x2C($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2C);
    // 0x8022FF7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022FF80: beql        $t4, $at, L_8022FFC8
    if (ctx->r12 == ctx->r1) {
        // 0x8022FF84: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_18;
    // 0x8022FF84: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_18:
    // 0x8022FF88: lbu         $v0, 0x75($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X75);
    // 0x8022FF8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022FF90: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8022FF94: bne         $v0, $at, L_8022FFA4
    if (ctx->r2 != ctx->r1) {
        // 0x8022FF98: addiu       $t5, $zero, 0xF
        ctx->r13 = ADD32(0, 0XF);
            goto L_8022FFA4;
    }
    // 0x8022FF98: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8022FF9C: sb          $t6, 0x398($a1)
    MEM_B(0X398, ctx->r5) = ctx->r14;
    // 0x8022FFA0: lbu         $v0, 0x75($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X75);
L_8022FFA4:
    // 0x8022FFA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022FFA8: bne         $v0, $at, L_8022FFB8
    if (ctx->r2 != ctx->r1) {
        // 0x8022FFAC: addiu       $t7, $zero, 0x8
        ctx->r15 = ADD32(0, 0X8);
            goto L_8022FFB8;
    }
    // 0x8022FFAC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8022FFB0: sb          $t5, 0x398($a1)
    MEM_B(0X398, ctx->r5) = ctx->r13;
    // 0x8022FFB4: lbu         $v0, 0x75($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X75);
L_8022FFB8:
    // 0x8022FFB8: bnel        $v0, $zero, L_8022FFC8
    if (ctx->r2 != 0) {
        // 0x8022FFBC: lh          $t8, 0x4($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X4);
            goto L_8022FFC8;
    }
    goto skip_19;
    // 0x8022FFBC: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    skip_19:
    // 0x8022FFC0: sb          $t7, 0x398($a1)
    MEM_B(0X398, ctx->r5) = ctx->r15;
L_8022FFC4:
    // 0x8022FFC4: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
L_8022FFC8:
    // 0x8022FFC8: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x8022FFCC: bnel        $t8, $t9, L_8022FFF0
    if (ctx->r24 != ctx->r25) {
        // 0x8022FFD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8022FFF0;
    }
    goto skip_20;
    // 0x8022FFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_20:
    // 0x8022FFD4: lhu         $v0, 0x30E($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X30E);
    // 0x8022FFD8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8022FFDC: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8022FFE0: beq         $at, $zero, L_8022FFEC
    if (ctx->r1 == 0) {
        // 0x8022FFE4: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8022FFEC;
    }
    // 0x8022FFE4: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8022FFE8: sh          $t4, 0x30E($a1)
    MEM_H(0X30E, ctx->r5) = ctx->r12;
L_8022FFEC:
    // 0x8022FFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022FFF0:
    // 0x8022FFF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8022FFF4: jr          $ra
    // 0x8022FFF8: nop

    return;
    // 0x8022FFF8: nop

;}
RECOMP_FUNC void M10_FUN_8022fffc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022FFFC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80230000: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80230004(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80230004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80230008: addiu       $t6, $a1, 0x44C
    ctx->r14 = ADD32(ctx->r5, 0X44C);
    // 0x8023000C: bne         $a0, $t6, L_80230020
    if (ctx->r4 != ctx->r14) {
        // 0x80230010: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80230020;
    }
    // 0x80230010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80230014: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80230018: b           L_80230028
    // 0x8023001C: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
        goto L_80230028;
    // 0x8023001C: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80230020:
    // 0x80230020: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80230024: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80230028:
    // 0x80230028: lhu         $v0, 0x9E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X9E);
    // 0x8023002C: beql        $v0, $zero, L_802300E4
    if (ctx->r2 == 0) {
        // 0x80230030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802300E4;
    }
    goto skip_0;
    // 0x80230030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80230034: lhu         $t7, 0x30($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X30);
    // 0x80230038: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8023003C: beql        $t8, $zero, L_802300E4
    if (ctx->r24 == 0) {
        // 0x80230040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802300E4;
    }
    goto skip_1;
    // 0x80230040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80230044: lhu         $t9, 0x30($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X30);
    // 0x80230048: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x8023004C: bnel        $t0, $zero, L_802300E4
    if (ctx->r8 != 0) {
        // 0x80230050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802300E4;
    }
    goto skip_2;
    // 0x80230050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80230054: lhu         $t1, 0x30($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X30);
    // 0x80230058: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8023005C: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80230060: bnel        $t2, $zero, L_802300E4
    if (ctx->r10 != 0) {
        // 0x80230064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802300E4;
    }
    goto skip_3;
    // 0x80230064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80230068: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x8023006C: bne         $v1, $zero, L_80230078
    if (ctx->r3 != 0) {
        // 0x80230070: nop
    
            goto L_80230078;
    }
    // 0x80230070: nop

    // 0x80230074: break       7
    do_break(2149777524);
L_80230078:
    // 0x80230078: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8023007C: bne         $v1, $at, L_80230090
    if (ctx->r3 != ctx->r1) {
        // 0x80230080: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80230090;
    }
    // 0x80230080: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80230084: bne         $v0, $at, L_80230090
    if (ctx->r2 != ctx->r1) {
        // 0x80230088: nop
    
            goto L_80230090;
    }
    // 0x80230088: nop

    // 0x8023008C: break       6
    do_break(2149777548);
L_80230090:
    // 0x80230090: mfhi        $t3
    ctx->r11 = hi;
    // 0x80230094: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80230098: bnel        $t3, $zero, L_802300CC
    if (ctx->r11 != 0) {
        // 0x8023009C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_802300CC;
    }
    goto skip_4;
    // 0x8023009C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_4:
    // 0x802300A0: lbu         $t4, 0xA4($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XA4);
    // 0x802300A4: lhu         $v0, 0x9E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X9E);
    // 0x802300A8: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802300AC: mflo        $t5
    ctx->r13 = lo;
    // 0x802300B0: nop

    // 0x802300B4: nop

    // 0x802300B8: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x802300BC: mflo        $t6
    ctx->r14 = lo;
    // 0x802300C0: sh          $t6, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r14;
    // 0x802300C4: nop

    // 0x802300C8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_802300CC:
    // 0x802300CC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x802300D0: bne         $t8, $zero, L_802300E0
    if (ctx->r24 != 0) {
        // 0x802300D4: sh          $t7, 0x9E($a0)
        MEM_H(0X9E, ctx->r4) = ctx->r15;
            goto L_802300E0;
    }
    // 0x802300D4: sh          $t7, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r15;
    // 0x802300D8: jal         0x803796E4
    // 0x802300DC: nop

    LOOKUP_FUNC(0x803796E4)(rdram, ctx);
        goto after_0;
    // 0x802300DC: nop

    after_0:
L_802300E0:
    // 0x802300E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802300E4:
    // 0x802300E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802300E8: jr          $ra
    // 0x802300EC: nop

    return;
    // 0x802300EC: nop

;}
RECOMP_FUNC void M10_FUN_802300f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802300F0: lbu         $v0, 0x396($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X396);
    // 0x802300F4: beq         $v0, $zero, L_80230114
    if (ctx->r2 == 0) {
        // 0x802300F8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80230114;
    }
    // 0x802300F8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x802300FC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80230100: bne         $t7, $zero, L_80230114
    if (ctx->r15 != 0) {
        // 0x80230104: sb          $t6, 0x396($a0)
        MEM_B(0X396, ctx->r4) = ctx->r14;
            goto L_80230114;
    }
    // 0x80230104: sb          $t6, 0x396($a0)
    MEM_B(0X396, ctx->r4) = ctx->r14;
    // 0x80230108: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8023010C: andi        $t9, $t8, 0xFFE1
    ctx->r25 = ctx->r24 & 0XFFE1;
    // 0x80230110: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
L_80230114:
    // 0x80230114: jr          $ra
    // 0x80230118: nop

    return;
    // 0x80230118: nop

;}
RECOMP_FUNC void M10_FUN_8023011c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023011C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80230120: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x80230124: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80230128: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8023012C: bne         $a1, $t7, L_80230140
    if (ctx->r5 != ctx->r15) {
        // 0x80230130: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80230140;
    }
    // 0x80230130: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80230134: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80230138: b           L_80230148
    // 0x8023013C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
        goto L_80230148;
    // 0x8023013C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80230140:
    // 0x80230140: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80230144: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80230148:
    // 0x80230148: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x8023014C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80230150: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80230154: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x80230158: bgtzl       $t9, L_80230174
    if (SIGNED(ctx->r25) > 0) {
        // 0x8023015C: lwc1        $f6, 0x2F4($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X2F4);
            goto L_80230174;
    }
    goto skip_0;
    // 0x8023015C: lwc1        $f6, 0x2F4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2F4);
    skip_0:
    // 0x80230160: lbu         $t0, 0x30($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X30);
    // 0x80230164: andi        $t1, $t0, 0xFF9F
    ctx->r9 = ctx->r8 & 0XFF9F;
    // 0x80230168: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x8023016C: sb          $t2, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r10;
    // 0x80230170: lwc1        $f6, 0x2F4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2F4);
L_80230174:
    // 0x80230174: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80230178: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8023017C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80230180: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x80230184: nop

    // 0x80230188: bc1fl       L_802301FC
    if (!c1cs) {
        // 0x8023018C: lh          $v0, 0x0($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X0);
            goto L_802301FC;
    }
    goto skip_1;
    // 0x8023018C: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    skip_1:
    // 0x80230190: lhu         $t3, 0x300($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X300);
    // 0x80230194: slti        $at, $t3, 0x64
    ctx->r1 = SIGNED(ctx->r11) < 0X64 ? 1 : 0;
    // 0x80230198: bnel        $at, $zero, L_802301FC
    if (ctx->r1 != 0) {
        // 0x8023019C: lh          $v0, 0x0($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X0);
            goto L_802301FC;
    }
    goto skip_2;
    // 0x8023019C: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    skip_2:
    // 0x802301A0: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x802301A4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802301A8: ldc1        $f18, -0x4E0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X4E0);
    // 0x802301AC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x802301B0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x802301B4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x802301B8: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x802301BC: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x802301C0: bgezl       $a0, L_802301E0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x802301C4: c.lt.d      $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
            goto L_802301E0;
    }
    goto skip_3;
    // 0x802301C4: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    skip_3:
    // 0x802301C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x802301CC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x802301D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x802301D4: nop

    // 0x802301D8: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
    // 0x802301DC: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
L_802301E0:
    // 0x802301E0: nop

    // 0x802301E4: bc1fl       L_802301FC
    if (!c1cs) {
        // 0x802301E8: lh          $v0, 0x0($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X0);
            goto L_802301FC;
    }
    goto skip_4;
    // 0x802301E8: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    skip_4:
    // 0x802301EC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x802301F0: jr          $ra
    // 0x802301F4: sb          $t5, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r13;
    return;
    // 0x802301F4: sb          $t5, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r13;
    // 0x802301F8: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
L_802301FC:
    // 0x802301FC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80230200: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80230204: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80230208: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x8023020C: bne         $a0, $zero, L_80230218
    if (ctx->r4 != 0) {
        // 0x80230210: nop
    
            goto L_80230218;
    }
    // 0x80230210: nop

    // 0x80230214: break       7
    do_break(2149777940);
L_80230218:
    // 0x80230218: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8023021C: bne         $a0, $at, L_80230230
    if (ctx->r4 != ctx->r1) {
        // 0x80230220: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80230230;
    }
    // 0x80230220: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80230224: bne         $t6, $at, L_80230230
    if (ctx->r14 != ctx->r1) {
        // 0x80230228: nop
    
            goto L_80230230;
    }
    // 0x80230228: nop

    // 0x8023022C: break       6
    do_break(2149777964);
L_80230230:
    // 0x80230230: mflo        $t7
    ctx->r15 = lo;
    // 0x80230234: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80230238: beq         $at, $zero, L_8023024C
    if (ctx->r1 == 0) {
            // 0x8023023C: nop

    LOOKUP_FUNC(0x8023024C)(rdram, ctx);
    return;
    }
    // 0x8023023C: nop

    // 0x80230240: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80230244: jr          $ra
    // 0x80230248: sb          $t8, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r24;
    return;
    // 0x80230248: sb          $t8, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023024c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023024c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023024C: bgez        $v0, L_8023025C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80230250: sra         $t9, $v0, 2
        ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
            goto L_8023025C;
    }
    // 0x80230250: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80230254: addiu       $at, $v0, 0x3
    ctx->r1 = ADD32(ctx->r2, 0X3);
    // 0x80230258: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_8023025C:
    // 0x8023025C: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80230260: beq         $at, $zero, L_80230274
    if (ctx->r1 == 0) {
            // 0x80230264: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    LOOKUP_FUNC(0x80230274)(rdram, ctx);
    return;
    }
    // 0x80230264: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80230268: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8023026C: jr          $ra
    // 0x80230270: sb          $t0, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r8;
    return;
    // 0x80230270: sb          $t0, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80230274(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80230274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230274: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80230278: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8023027C: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80230280: div         $zero, $t1, $a0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r4)));
    // 0x80230284: bne         $a0, $zero, L_80230290
    if (ctx->r4 != 0) {
        // 0x80230288: nop
    
            goto L_80230290;
    }
    // 0x80230288: nop

    // 0x8023028C: break       7
    do_break(2149778060);
L_80230290:
    // 0x80230290: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80230294: bne         $a0, $at, L_802302A8
    if (ctx->r4 != ctx->r1) {
        // 0x80230298: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_802302A8;
    }
    // 0x80230298: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8023029C: bne         $t1, $at, L_802302A8
    if (ctx->r9 != ctx->r1) {
        // 0x802302A0: nop
    
            goto L_802302A8;
    }
    // 0x802302A0: nop

    // 0x802302A4: break       6
    do_break(2149778084);
L_802302A8:
    // 0x802302A8: mflo        $t2
    ctx->r10 = lo;
    // 0x802302AC: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x802302B0: beq         $at, $zero, L_802302C4
    if (ctx->r1 == 0) {
            // 0x802302B4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x802302C4)(rdram, ctx);
    return;
    }
    // 0x802302B4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x802302B8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x802302BC: jr          $ra
    // 0x802302C0: sb          $t3, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r11;
    return;
    // 0x802302C0: sb          $t3, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r11;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802302c4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802302c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802302C4: sb          $t4, 0x2F8($a1)
    MEM_B(0X2F8, ctx->r5) = ctx->r12;
    // 0x802302C8: jr          $ra
    // 0x802302CC: nop

    return;
    // 0x802302CC: nop

;}
RECOMP_FUNC void M10_FUN_802302d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802302D0: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x802302D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x802302D8: addiu       $t7, $t7, 0x42A0
    ctx->r15 = ADD32(ctx->r15, 0X42A0);
    // 0x802302DC: bne         $t6, $zero, L_802302E8
    if (ctx->r14 != 0) {
        // 0x802302E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_802302E8;
    }
    // 0x802302E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802302E4: sw          $t7, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r15;
L_802302E8:
    // 0x802302E8: lw          $t8, 0x2D4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2D4);
    // 0x802302EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x802302F0: addiu       $t9, $t9, 0x42A0
    ctx->r25 = ADD32(ctx->r25, 0X42A0);
    // 0x802302F4: bnel        $t8, $zero, L_80230304
    if (ctx->r24 != 0) {
        // 0x802302F8: sb          $v0, 0x2DA($a1)
        MEM_B(0X2DA, ctx->r5) = ctx->r2;
            goto L_80230304;
    }
    goto skip_0;
    // 0x802302F8: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
    skip_0:
    // 0x802302FC: sw          $t9, 0x2D4($a1)
    MEM_W(0X2D4, ctx->r5) = ctx->r25;
    // 0x80230300: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
L_80230304:
    // 0x80230304: sb          $v0, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = ctx->r2;
    // 0x80230308: lw          $t0, 0x2D4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2D4);
    // 0x8023030C: lbu         $t1, 0x1A($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1A);
    // 0x80230310: jr          $ra
    // 0x80230314: sb          $t1, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r9;
    return;
    // 0x80230314: sb          $t1, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80230318(rdram, ctx);
;}
