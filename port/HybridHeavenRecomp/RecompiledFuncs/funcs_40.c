#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M23_FUN_801caa2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAA2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CAA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CAA34: bne         $t6, $zero, L_801CAA58
    if (ctx->r14 != 0) {
        // 0x801CAA38: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801CAA58;
    }
    // 0x801CAA38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CAA3C: lbu         $t7, 0x17E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X17E);
    // 0x801CAA40: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801CAA44: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAA48: bnel        $t7, $at, L_801CAA5C
    if (ctx->r15 != ctx->r1) {
        // 0x801CAA4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CAA5C;
    }
    goto skip_0;
    // 0x801CAA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CAA50: jal         0x800058DC
    // 0x801CAA54: addiu       $a1, $a1, -0x5598
    ctx->r5 = ADD32(ctx->r5, -0X5598);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CAA54: addiu       $a1, $a1, -0x5598
    ctx->r5 = ADD32(ctx->r5, -0X5598);
    after_0:
L_801CAA58:
    // 0x801CAA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CAA5C:
    // 0x801CAA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CAA60: jr          $ra
    // 0x801CAA64: nop

    return;
    // 0x801CAA64: nop

;}
RECOMP_FUNC void M23_FUN_801caa68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAA68: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801CAA6C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801CAA70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CAA74: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801CAA78: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801CAA7C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CAA80: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801CAA84: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801CAA88: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801CAA8C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801CAA90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CAA94: addiu       $a3, $a3, -0x98C
    ctx->r7 = ADD32(ctx->r7, -0X98C);
    // 0x801CAA98: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CAA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CAAA0: jal         0x8001B204
    // 0x801CAAA4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801CAAA4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x801CAAA8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAAAC: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
    // 0x801CAAB0: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x801CAAB4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801CAAB8: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801CAABC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CAAC0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x801CAAC4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801CAAC8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801CAACC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CAAD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CAAD4: addiu       $a1, $a1, -0x97C
    ctx->r5 = ADD32(ctx->r5, -0X97C);
    // 0x801CAAD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CAADC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CAAE0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CAAE4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CAAE8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CAAEC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CAAF0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CAAF4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CAAF8: jal         0x8001A804
    // 0x801CAAFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x801CAAFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_1:
    // 0x801CAB00: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801CAB04: addiu       $t0, $t0, -0x21E
    ctx->r8 = ADD32(ctx->r8, -0X21E);
    // 0x801CAB08: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x801CAB0C: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x801CAB10: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801CAB14: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CAB18: addiu       $v1, $v1, -0x21C
    ctx->r3 = ADD32(ctx->r3, -0X21C);
    // 0x801CAB1C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x801CAB20: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801CAB24: negu        $t7, $a2
    ctx->r15 = SUB32(0, ctx->r6);
    // 0x801CAB28: mflo        $a3
    ctx->r7 = lo;
    // 0x801CAB2C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x801CAB30: bne         $a3, $a1, L_801CAC08
    if (ctx->r7 != ctx->r5) {
        // 0x801CAB34: nop
    
            goto L_801CAC08;
    }
    // 0x801CAB34: nop

    // 0x801CAB38: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x801CAB3C: addiu       $a3, $a3, -0x6D50
    ctx->r7 = ADD32(ctx->r7, -0X6D50);
    // 0x801CAB40: lhu         $a1, 0x1D0($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X1D0);
    // 0x801CAB44: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801CAB48: addiu       $s3, $s3, -0x220
    ctx->r19 = ADD32(ctx->r19, -0X220);
    // 0x801CAB4C: andi        $t4, $a1, 0x800
    ctx->r12 = ctx->r5 & 0X800;
    // 0x801CAB50: beq         $t4, $zero, L_801CAB90
    if (ctx->r12 == 0) {
        // 0x801CAB54: andi        $t8, $a1, 0x400
        ctx->r24 = ctx->r5 & 0X400;
            goto L_801CAB90;
    }
    // 0x801CAB54: andi        $t8, $a1, 0x400
    ctx->r24 = ctx->r5 & 0X400;
    // 0x801CAB58: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x801CAB5C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801CAB60: addiu       $a2, $a2, -0x21F
    ctx->r6 = ADD32(ctx->r6, -0X21F);
    // 0x801CAB64: blez        $v0, L_801CAB90
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801CAB68: nop
    
            goto L_801CAB90;
    }
    // 0x801CAB68: nop

    // 0x801CAB6C: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x801CAB70: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x801CAB74: sb          $t5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r13;
    // 0x801CAB78: blez        $v1, L_801CAB8C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801CAB7C: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_801CAB8C;
    }
    // 0x801CAB7C: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x801CAB80: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x801CAB84: b           L_801CAB90
    // 0x801CAB88: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
        goto L_801CAB90;
    // 0x801CAB88: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
L_801CAB8C:
    // 0x801CAB8C: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
L_801CAB90:
    // 0x801CAB90: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801CAB94: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801CAB98: addiu       $s3, $s3, -0x220
    ctx->r19 = ADD32(ctx->r19, -0X220);
    // 0x801CAB9C: beq         $t8, $zero, L_801CABE0
    if (ctx->r24 == 0) {
        // 0x801CABA0: addiu       $a2, $a2, -0x21F
        ctx->r6 = ADD32(ctx->r6, -0X21F);
            goto L_801CABE0;
    }
    // 0x801CABA0: addiu       $a2, $a2, -0x21F
    ctx->r6 = ADD32(ctx->r6, -0X21F);
    // 0x801CABA4: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x801CABA8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x801CABAC: beql        $at, $zero, L_801CABE4
    if (ctx->r1 == 0) {
        // 0x801CABB0: lhu         $t5, 0x1C8($a3)
        ctx->r13 = MEM_HU(ctx->r7, 0X1C8);
            goto L_801CABE4;
    }
    goto skip_0;
    // 0x801CABB0: lhu         $t5, 0x1C8($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X1C8);
    skip_0:
    // 0x801CABB4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x801CABB8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801CABBC: sb          $t9, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r25;
    // 0x801CABC0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x801CABC4: beq         $at, $zero, L_801CABD4
    if (ctx->r1 == 0) {
        // 0x801CABC8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_801CABD4;
    }
    // 0x801CABC8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x801CABCC: b           L_801CABE0
    // 0x801CABD0: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
        goto L_801CABE0;
    // 0x801CABD0: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
L_801CABD4:
    // 0x801CABD4: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x801CABD8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801CABDC: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
L_801CABE0:
    // 0x801CABE0: lhu         $t5, 0x1C8($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X1C8);
L_801CABE4:
    // 0x801CABE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CABE8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CABEC: andi        $t6, $t5, 0xB000
    ctx->r14 = ctx->r13 & 0XB000;
    // 0x801CABF0: beq         $t6, $zero, L_801CAC60
    if (ctx->r14 == 0) {
        // 0x801CABF4: nop
    
            goto L_801CAC60;
    }
    // 0x801CABF4: nop

    // 0x801CABF8: jal         0x800058DC
    // 0x801CABFC: addiu       $a1, $a1, -0x5310
    ctx->r5 = ADD32(ctx->r5, -0X5310);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CABFC: addiu       $a1, $a1, -0x5310
    ctx->r5 = ADD32(ctx->r5, -0X5310);
    after_2:
    // 0x801CAC00: b           L_801CACCC
    // 0x801CAC04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801CACCC;
    // 0x801CAC04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801CAC08:
    // 0x801CAC08: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CAC0C: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    // 0x801CAC10: mflo        $v0
    ctx->r2 = lo;
    // 0x801CAC14: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CAC18: beql        $at, $zero, L_801CAC40
    if (ctx->r1 == 0) {
        // 0x801CAC1C: slt         $at, $v0, $a1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_801CAC40;
    }
    goto skip_1;
    // 0x801CAC1C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    skip_1:
    // 0x801CAC20: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x801CAC24: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x801CAC28: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801CAC2C: beql        $at, $zero, L_801CAC40
    if (ctx->r1 == 0) {
        // 0x801CAC30: slt         $at, $v0, $a1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_801CAC40;
    }
    goto skip_2;
    // 0x801CAC30: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    skip_2:
    // 0x801CAC34: sh          $a3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r7;
    // 0x801CAC38: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x801CAC3C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
L_801CAC40:
    // 0x801CAC40: beq         $at, $zero, L_801CAC60
    if (ctx->r1 == 0) {
        // 0x801CAC44: addiu       $t9, $a1, -0x2
        ctx->r25 = ADD32(ctx->r5, -0X2);
            goto L_801CAC60;
    }
    // 0x801CAC44: addiu       $t9, $a1, -0x2
    ctx->r25 = ADD32(ctx->r5, -0X2);
    // 0x801CAC48: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x801CAC4C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x801CAC50: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CAC54: beq         $at, $zero, L_801CAC60
    if (ctx->r1 == 0) {
        // 0x801CAC58: nop
    
            goto L_801CAC60;
    }
    // 0x801CAC58: nop

    // 0x801CAC5C: sh          $a3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r7;
L_801CAC60:
    // 0x801CAC60: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801CAC64: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801CAC68: addiu       $s3, $s3, -0x220
    ctx->r19 = ADD32(ctx->r19, -0X220);
    // 0x801CAC6C: addiu       $s0, $s0, -0x1C24
    ctx->r16 = ADD32(ctx->r16, -0X1C24);
    // 0x801CAC70: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801CAC74: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
L_801CAC78:
    // 0x801CAC78: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x801CAC7C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAC80: lh          $a1, -0x21C($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X21C);
    // 0x801CAC84: bnel        $s1, $t3, L_801CACAC
    if (ctx->r17 != ctx->r11) {
        // 0x801CAC88: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_801CACAC;
    }
    goto skip_3;
    // 0x801CAC88: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x801CAC8C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CAC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CAC94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801CAC98: jalr        $t9
    // 0x801CAC9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x801CAC9C: nop

    after_3:
    // 0x801CACA0: b           L_801CACC0
    // 0x801CACA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_801CACC0;
    // 0x801CACA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801CACA8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_801CACAC:
    // 0x801CACAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CACB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801CACB4: jalr        $t9
    // 0x801CACB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x801CACB8: nop

    after_4:
    // 0x801CACBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801CACC0:
    // 0x801CACC0: bne         $s1, $s2, L_801CAC78
    if (ctx->r17 != ctx->r18) {
        // 0x801CACC4: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_801CAC78;
    }
    // 0x801CACC4: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x801CACC8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801CACCC:
    // 0x801CACCC: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801CACD0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801CACD4: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801CACD8: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801CACDC: jr          $ra
    // 0x801CACE0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801CACE0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cace4(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cace4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CACE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CACE8: jr          $ra
    // 0x801CACEC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CACEC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cacf0(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cacf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CACF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801CACF4: lbu         $v0, -0x220($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X220);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cacf8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cacf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CACF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CACFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CAD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CAD04: bne         $v0, $zero, L_801CAD18
    if (ctx->r2 != 0) {
        // 0x801CAD08: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801CAD18;
    }
    // 0x801CAD08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CAD0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CAD10: b           L_801CAD24
    // 0x801CAD14: sb          $zero, -0x40C3($at)
    MEM_B(-0X40C3, ctx->r1) = 0;
        goto L_801CAD24;
    // 0x801CAD14: sb          $zero, -0x40C3($at)
    MEM_B(-0X40C3, ctx->r1) = 0;
L_801CAD18:
    // 0x801CAD18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CAD1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CAD20: sb          $t6, -0x40C3($at)
    MEM_B(-0X40C3, ctx->r1) = ctx->r14;
L_801CAD24:
    // 0x801CAD24: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801CAD28: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801CAD2C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CAD30: addiu       $t8, $t8, -0x1C24
    ctx->r24 = ADD32(ctx->r24, -0X1C24);
    // 0x801CAD34: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801CAD38: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x801CAD3C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x801CAD40: jalr        $t9
    // 0x801CAD44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801CAD44: nop

    after_0:
    // 0x801CAD48: jal         0x800023A8
    // 0x801CAD4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_1;
    // 0x801CAD4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801CAD50: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAD54: addiu       $a1, $a1, -0x531C
    ctx->r5 = ADD32(ctx->r5, -0X531C);
    // 0x801CAD58: jal         0x800058DC
    // 0x801CAD5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CAD5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801CAD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CAD64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CAD68: jr          $ra
    // 0x801CAD6C: nop

    return;
    // 0x801CAD6C: nop

;}
RECOMP_FUNC void M23_FUN_801cad70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAD70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CAD74: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801CAD78: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801CAD7C: addiu       $t6, $t6, -0x210
    ctx->r14 = ADD32(ctx->r14, -0X210);
    // 0x801CAD80: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x801CAD84: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x801CAD88: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801CAD8C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x801CAD90: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801CAD94: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x801CAD98: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801CAD9C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801CADA0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801CADA4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801CADA8: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x801CADAC: lhu         $t0, -0x19FC($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X19FC);
    // 0x801CADB0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x801CADB4: addiu       $t1, $a1, 0x1
    ctx->r9 = ADD32(ctx->r5, 0X1);
    // 0x801CADB8: bne         $v0, $t0, L_801CADCC
    if (ctx->r2 != ctx->r8) {
        // 0x801CADBC: nop
    
            goto L_801CADCC;
    }
    // 0x801CADBC: nop

    // 0x801CADC0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x801CADC4: b           L_801CADDC
    // 0x801CADC8: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
        goto L_801CADDC;
    // 0x801CADC8: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
L_801CADCC:
    // 0x801CADCC: beql        $v0, $zero, L_801CADE0
    if (ctx->r2 == 0) {
        // 0x801CADD0: slti        $at, $a1, 0x5
        ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
            goto L_801CADE0;
    }
    goto skip_0;
    // 0x801CADD0: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    skip_0:
    // 0x801CADD4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x801CADD8: andi        $a1, $zero, 0xFF
    ctx->r5 = 0 & 0XFF;
L_801CADDC:
    // 0x801CADDC: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
L_801CADE0:
    // 0x801CADE0: bne         $at, $zero, L_801CADF8
    if (ctx->r1 != 0) {
            // 0x801CADE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x801CADF8)(rdram, ctx);
    return;
    }
    // 0x801CADE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CADE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CADEC: sb          $t2, -0x4319($at)
    MEM_B(-0X4319, ctx->r1) = ctx->r10;
    // 0x801CADF0: jr          $ra
    // 0x801CADF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CADF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cadf8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cadf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CADF8: jr          $ra
    // 0x801CADFC: nop

    return;
    // 0x801CADFC: nop

;}
RECOMP_FUNC void M23_FUN_801cae00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAE00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CAE04: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801CAE08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CAE0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CAE10: addiu       $v1, $v1, -0x210
    ctx->r3 = ADD32(ctx->r3, -0X210);
    // 0x801CAE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CAE18:
    // 0x801CAE18: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x801CAE1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CAE20: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CAE24: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801CAE28: bne         $at, $zero, L_801CAE18
    if (ctx->r1 != 0) {
        // 0x801CAE2C: sb          $zero, 0x0($t6)
        MEM_B(0X0, ctx->r14) = 0;
            goto L_801CAE18;
    }
    // 0x801CAE2C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x801CAE30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CAE34: sb          $zero, -0x4319($at)
    MEM_B(-0X4319, ctx->r1) = 0;
    // 0x801CAE38: jal         0x8013E620
    // 0x801CAE3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8013E620)(rdram, ctx);
        goto after_0;
    // 0x801CAE3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CAE40: beq         $v0, $zero, L_801CAED4
    if (ctx->r2 == 0) {
        // 0x801CAE44: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801CAED4;
    }
    // 0x801CAE44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CAE48: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x801CAE4C: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x801CAE50: beq         $t7, $zero, L_801CAE6C
    if (ctx->r15 == 0) {
        // 0x801CAE54: andi        $t9, $v1, 0x4
        ctx->r25 = ctx->r3 & 0X4;
            goto L_801CAE6C;
    }
    // 0x801CAE54: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x801CAE58: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAE5C: addiu       $a1, $a1, -0x20D
    ctx->r5 = ADD32(ctx->r5, -0X20D);
    // 0x801CAE60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CAE64: b           L_801CAE78
    // 0x801CAE68: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
        goto L_801CAE78;
    // 0x801CAE68: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
L_801CAE6C:
    // 0x801CAE6C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAE70: addiu       $a1, $a1, -0x20D
    ctx->r5 = ADD32(ctx->r5, -0X20D);
    // 0x801CAE74: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_801CAE78:
    // 0x801CAE78: beq         $t9, $zero, L_801CAE94
    if (ctx->r25 == 0) {
        // 0x801CAE7C: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801CAE94;
    }
    // 0x801CAE7C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801CAE80: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801CAE84: addiu       $v0, $v0, -0x20C
    ctx->r2 = ADD32(ctx->r2, -0X20C);
    // 0x801CAE88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CAE8C: b           L_801CAE9C
    // 0x801CAE90: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_801CAE9C;
    // 0x801CAE90: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_801CAE94:
    // 0x801CAE94: addiu       $v0, $v0, -0x20C
    ctx->r2 = ADD32(ctx->r2, -0X20C);
    // 0x801CAE98: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_801CAE9C:
    // 0x801CAE9C: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x801CAEA0: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x801CAEA4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAEA8: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x801CAEAC: beq         $t3, $zero, L_801CAEC4
    if (ctx->r11 == 0) {
        // 0x801CAEB0: nop
    
            goto L_801CAEC4;
    }
    // 0x801CAEB0: nop

    // 0x801CAEB4: jal         0x800058DC
    // 0x801CAEB8: addiu       $a1, $a1, -0x5114
    ctx->r5 = ADD32(ctx->r5, -0X5114);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CAEB8: addiu       $a1, $a1, -0x5114
    ctx->r5 = ADD32(ctx->r5, -0X5114);
    after_1:
    // 0x801CAEBC: b           L_801CAEE0
    // 0x801CAEC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CAEE0;
    // 0x801CAEC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CAEC4:
    // 0x801CAEC4: jal         0x80005700
    // 0x801CAEC8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801CAEC8: nop

    after_2:
    // 0x801CAECC: b           L_801CAEE0
    // 0x801CAED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CAEE0;
    // 0x801CAED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CAED4:
    // 0x801CAED4: jal         0x80005700
    // 0x801CAED8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801CAED8: nop

    after_3:
    // 0x801CAEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CAEE0:
    // 0x801CAEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CAEE4: jr          $ra
    // 0x801CAEE8: nop

    return;
    // 0x801CAEE8: nop

;}
RECOMP_FUNC void M23_FUN_801caeec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAEEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CAEF0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801CAEF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801CAEF8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801CAEFC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CAF00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801CAF04:
    // 0x801CAF04: jal         0x801CAD70
    // 0x801CAF08: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x801CAD70)(rdram, ctx);
        goto after_0;
    // 0x801CAF08: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x801CAF0C: beq         $v0, $zero, L_801CB014
    if (ctx->r2 == 0) {
        // 0x801CAF10: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801CB014;
    }
    // 0x801CAF10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CAF14: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801CAF18: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801CAF1C: lbu         $v1, 0xF7($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XF7);
    // 0x801CAF20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CAF24: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801CAF28: beq         $v1, $at, L_801CAF4C
    if (ctx->r3 == ctx->r1) {
        // 0x801CAF2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801CAF4C;
    }
    // 0x801CAF2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CAF30: beq         $v1, $at, L_801CAF7C
    if (ctx->r3 == ctx->r1) {
        // 0x801CAF34: lui         $t7, 0x801D
        ctx->r15 = S32(0X801D << 16);
            goto L_801CAF7C;
    }
    // 0x801CAF34: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CAF38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801CAF3C: beq         $v1, $at, L_801CAFAC
    if (ctx->r3 == ctx->r1) {
        // 0x801CAF40: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CAFAC;
    }
    // 0x801CAF40: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CAF44: b           L_801CAFDC
    // 0x801CAF48: nop

        goto L_801CAFDC;
    // 0x801CAF48: nop

L_801CAF4C:
    // 0x801CAF4C: lbu         $t6, -0x20D($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X20D);
    // 0x801CAF50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CAF54: beql        $t6, $zero, L_801CAF74
    if (ctx->r14 == 0) {
        // 0x801CAF58: sb          $zero, 0xF7($a0)
        MEM_B(0XF7, ctx->r4) = 0;
            goto L_801CAF74;
    }
    goto skip_0;
    // 0x801CAF58: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
    skip_0:
    // 0x801CAF5C: jal         0x80020718
    // 0x801CAF60: addiu       $a0, $zero, 0x506
    ctx->r4 = ADD32(0, 0X506);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x801CAF60: addiu       $a0, $zero, 0x506
    ctx->r4 = ADD32(0, 0X506);
    after_1:
    // 0x801CAF64: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801CAF68: b           L_801CAFDC
    // 0x801CAF6C: lbu         $v1, -0x4319($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4319);
        goto L_801CAFDC;
    // 0x801CAF6C: lbu         $v1, -0x4319($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4319);
    // 0x801CAF70: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
L_801CAF74:
    // 0x801CAF74: b           L_801CB024
    // 0x801CAF78: sb          $zero, -0x210($at)
    MEM_B(-0X210, ctx->r1) = 0;
        goto L_801CB024;
    // 0x801CAF78: sb          $zero, -0x210($at)
    MEM_B(-0X210, ctx->r1) = 0;
L_801CAF7C:
    // 0x801CAF7C: lbu         $t7, -0x20C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X20C);
    // 0x801CAF80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CAF84: beql        $t7, $zero, L_801CAFA4
    if (ctx->r15 == 0) {
        // 0x801CAF88: sb          $zero, 0xF7($a0)
        MEM_B(0XF7, ctx->r4) = 0;
            goto L_801CAFA4;
    }
    goto skip_1;
    // 0x801CAF88: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
    skip_1:
    // 0x801CAF8C: jal         0x80020718
    // 0x801CAF90: addiu       $a0, $zero, 0x509
    ctx->r4 = ADD32(0, 0X509);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801CAF90: addiu       $a0, $zero, 0x509
    ctx->r4 = ADD32(0, 0X509);
    after_2:
    // 0x801CAF94: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801CAF98: b           L_801CAFDC
    // 0x801CAF9C: lbu         $v1, -0x4319($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4319);
        goto L_801CAFDC;
    // 0x801CAF9C: lbu         $v1, -0x4319($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4319);
    // 0x801CAFA0: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
L_801CAFA4:
    // 0x801CAFA4: b           L_801CB024
    // 0x801CAFA8: sb          $zero, -0x20F($at)
    MEM_B(-0X20F, ctx->r1) = 0;
        goto L_801CB024;
    // 0x801CAFA8: sb          $zero, -0x20F($at)
    MEM_B(-0X20F, ctx->r1) = 0;
L_801CAFAC:
    // 0x801CAFAC: lbu         $t8, -0x20C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X20C);
    // 0x801CAFB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CAFB4: beql        $t8, $zero, L_801CAFD4
    if (ctx->r24 == 0) {
        // 0x801CAFB8: sb          $zero, 0xF7($a0)
        MEM_B(0XF7, ctx->r4) = 0;
            goto L_801CAFD4;
    }
    goto skip_2;
    // 0x801CAFB8: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
    skip_2:
    // 0x801CAFBC: jal         0x80020718
    // 0x801CAFC0: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_3;
    // 0x801CAFC0: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    after_3:
    // 0x801CAFC4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801CAFC8: b           L_801CAFDC
    // 0x801CAFCC: lbu         $v1, -0x4319($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4319);
        goto L_801CAFDC;
    // 0x801CAFCC: lbu         $v1, -0x4319($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4319);
    // 0x801CAFD0: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
L_801CAFD4:
    // 0x801CAFD4: b           L_801CB024
    // 0x801CAFD8: sb          $zero, -0x20E($at)
    MEM_B(-0X20E, ctx->r1) = 0;
        goto L_801CB024;
    // 0x801CAFD8: sb          $zero, -0x20E($at)
    MEM_B(-0X20E, ctx->r1) = 0;
L_801CAFDC:
    // 0x801CAFDC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CAFE0: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x801CAFE4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801CAFE8: addiu       $a3, $a3, -0x8DC
    ctx->r7 = ADD32(ctx->r7, -0X8DC);
    // 0x801CAFEC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801CAFF0: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x801CAFF4: addiu       $a2, $zero, 0x62
    ctx->r6 = ADD32(0, 0X62);
    // 0x801CAFF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801CAFFC: jal         0x8001B204
    // 0x801CB000: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801CB000: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_4:
    // 0x801CB004: jal         0x80005700
    // 0x801CB008: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x801CB008: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x801CB00C: b           L_801CB028
    // 0x801CB010: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801CB028;
    // 0x801CB010: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801CB014:
    // 0x801CB014: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CB018: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x801CB01C: bne         $at, $zero, L_801CAF04
    if (ctx->r1 != 0) {
        // 0x801CB020: nop
    
            goto L_801CAF04;
    }
    // 0x801CB020: nop

L_801CB024:
    // 0x801CB024: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801CB028:
    // 0x801CB028: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801CB02C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CB030: jr          $ra
    // 0x801CB034: nop

    return;
    // 0x801CB034: nop

;}
RECOMP_FUNC void M23_FUN_801cb038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB038: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801CB03C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801CB040: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801CB044: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801CB048: jal         0x80126930
    // 0x801CB04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80126930)(rdram, ctx);
        goto after_0;
    // 0x801CB04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801CB050: jal         0x80116E80
    // 0x801CB054: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x801CB054: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_1:
    // 0x801CB058: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB05C: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x801CB060: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x801CB064: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801CB068: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CB06C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CB070: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CB074: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801CB078: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CB07C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CB080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CB084: addiu       $a1, $a1, -0x8C8
    ctx->r5 = ADD32(ctx->r5, -0X8C8);
    // 0x801CB088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CB08C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CB090: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CB094: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB098: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB09C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB0A0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CB0A4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CB0A8: jal         0x8001A804
    // 0x801CB0AC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x801CB0AC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x801CB0B0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB0B4: addiu       $a1, $a1, -0x4F30
    ctx->r5 = ADD32(ctx->r5, -0X4F30);
    // 0x801CB0B8: jal         0x800058DC
    // 0x801CB0BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CB0BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x801CB0C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801CB0C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801CB0C8: jr          $ra
    // 0x801CB0CC: nop

    return;
    // 0x801CB0CC: nop

;}
RECOMP_FUNC void M23_FUN_801cb0d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB0D0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801CB0D4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801CB0D8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801CB0DC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801CB0E0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801CB0E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CB0E8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801CB0EC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801CB0F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CB0F4: addiu       $s2, $sp, 0x67
    ctx->r18 = ADD32(ctx->r29, 0X67);
    // 0x801CB0F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CB0FC:
    // 0x801CB0FC: sll         $a3, $v0, 5
    ctx->r7 = S32(ctx->r2 << 5);
    // 0x801CB100: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801CB104: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801CB108: addiu       $t6, $zero, 0x56
    ctx->r14 = ADD32(0, 0X56);
    // 0x801CB10C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x801CB110: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x801CB114: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x801CB118: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801CB11C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CB120: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CB124: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CB128: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801CB12C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB130: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CB134: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801CB138: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB13C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB140: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB144: jal         0x80146208
    // 0x801CB148: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x801CB148: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801CB14C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB150: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x801CB154: jal         0x80145348
    // 0x801CB158: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_1;
    // 0x801CB158: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_1:
    // 0x801CB15C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CB160: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CB164: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x801CB168: bne         $at, $zero, L_801CB0FC
    if (ctx->r1 != 0) {
        // 0x801CB16C: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_801CB0FC;
    }
    // 0x801CB16C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801CB170: sll         $a3, $v0, 5
    ctx->r7 = S32(ctx->r2 << 5);
    // 0x801CB174: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801CB178: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801CB17C: addiu       $t0, $zero, 0x56
    ctx->r8 = ADD32(0, 0X56);
    // 0x801CB180: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x801CB184: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801CB188: addiu       $t3, $zero, 0x228
    ctx->r11 = ADD32(0, 0X228);
    // 0x801CB18C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801CB190: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801CB194: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801CB198: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CB19C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801CB1A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB1A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CB1A8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801CB1AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB1B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB1B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB1B8: jal         0x80146208
    // 0x801CB1BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x801CB1BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x801CB1C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB1C4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x801CB1C8: jal         0x80145348
    // 0x801CB1CC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x801CB1CC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x801CB1D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CB1D4: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_801CB1D8:
    // 0x801CB1D8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x801CB1DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CB1E0: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x801CB1E4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801CB1E8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CB1EC: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x801CB1F0: bne         $at, $zero, L_801CB1D8
    if (ctx->r1 != 0) {
        // 0x801CB1F4: sh          $v0, 0x28($t6)
        MEM_H(0X28, ctx->r14) = ctx->r2;
            goto L_801CB1D8;
    }
    // 0x801CB1F4: sh          $v0, 0x28($t6)
    MEM_H(0X28, ctx->r14) = ctx->r2;
    // 0x801CB1F8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB1FC: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
    // 0x801CB200: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x801CB204: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801CB208: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CB20C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CB210: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801CB214: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CB218: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801CB21C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CB220: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CB224: addiu       $a1, $a1, -0x8A0
    ctx->r5 = ADD32(ctx->r5, -0X8A0);
    // 0x801CB228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CB22C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CB230: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CB234: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB238: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB23C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB240: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CB244: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CB248: jal         0x8001A804
    // 0x801CB24C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_4;
    // 0x801CB24C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_4:
    // 0x801CB250: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB254: addiu       $a1, $a1, -0x4D84
    ctx->r5 = ADD32(ctx->r5, -0X4D84);
    // 0x801CB258: jal         0x800058DC
    // 0x801CB25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801CB25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801CB260: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801CB264: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801CB268: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801CB26C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801CB270: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801CB274: jr          $ra
    // 0x801CB278: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801CB278: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cb27c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cb27c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB27C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CB280: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801CB284: lbu         $t6, 0x164($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X164);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cb288(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cb288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB288: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CB28C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801CB290: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801CB294: bne         $t6, $zero, L_801CB540
    if (ctx->r14 != 0) {
        // 0x801CB298: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_801CB540;
    }
    // 0x801CB298: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801CB29C: lbu         $t7, 0x17E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X17E);
    // 0x801CB2A0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801CB2A4: bnel        $t7, $at, L_801CB544
    if (ctx->r15 != ctx->r1) {
        // 0x801CB2A8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801CB544;
    }
    goto skip_0;
    // 0x801CB2A8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801CB2AC: jal         0x8013E620
    // 0x801CB2B0: nop

    LOOKUP_FUNC(0x8013E620)(rdram, ctx);
        goto after_0;
    // 0x801CB2B0: nop

    after_0:
    // 0x801CB2B4: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x801CB2B8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB2BC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CB2C0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x801CB2C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801CB2C8: addiu       $a3, $a3, -0x878
    ctx->r7 = ADD32(ctx->r7, -0X878);
    // 0x801CB2CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CB2D0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB2D4: jal         0x8001B204
    // 0x801CB2D8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801CB2D8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x801CB2DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB2E0: addiu       $t0, $zero, 0x130
    ctx->r8 = ADD32(0, 0X130);
    // 0x801CB2E4: addiu       $t1, $zero, 0xE0
    ctx->r9 = ADD32(0, 0XE0);
    // 0x801CB2E8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x801CB2EC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801CB2F0: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801CB2F4: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x801CB2F8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801CB2FC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801CB300: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801CB304: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CB308: addiu       $a1, $a1, -0x864
    ctx->r5 = ADD32(ctx->r5, -0X864);
    // 0x801CB30C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CB310: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CB314: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CB318: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB31C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB320: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB324: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CB328: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CB32C: jal         0x8001A804
    // 0x801CB330: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x801CB330: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x801CB334: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CB338: lbu         $v0, -0x43F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43F3);
    // 0x801CB33C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CB340: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB344: beq         $v0, $zero, L_801CB36C
    if (ctx->r2 == 0) {
        // 0x801CB348: addiu       $a2, $zero, 0x82
        ctx->r6 = ADD32(0, 0X82);
            goto L_801CB36C;
    }
    // 0x801CB348: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x801CB34C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CB350: beq         $v0, $at, L_801CB3A8
    if (ctx->r2 == ctx->r1) {
        // 0x801CB354: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_801CB3A8;
    }
    // 0x801CB354: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801CB358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CB35C: beq         $v0, $at, L_801CB480
    if (ctx->r2 == ctx->r1) {
        // 0x801CB360: lw          $t5, 0x4C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X4C);
            goto L_801CB480;
    }
    // 0x801CB360: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x801CB364: b           L_801CB530
    // 0x801CB368: nop

        goto L_801CB530;
    // 0x801CB368: nop

L_801CB36C:
    // 0x801CB36C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB370: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801CB374: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801CB378: jal         0x8001B204
    // 0x801CB37C: addiu       $a3, $a3, -0x83C
    ctx->r7 = ADD32(ctx->r7, -0X83C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801CB37C: addiu       $a3, $a3, -0x83C
    ctx->r7 = ADD32(ctx->r7, -0X83C);
    after_3:
    // 0x801CB380: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB384: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801CB388: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CB38C: addiu       $a3, $a3, -0x820
    ctx->r7 = ADD32(ctx->r7, -0X820);
    // 0x801CB390: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CB394: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB398: jal         0x8001B204
    // 0x801CB39C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801CB39C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_4:
    // 0x801CB3A0: b           L_801CB530
    // 0x801CB3A4: nop

        goto L_801CB530;
    // 0x801CB3A4: nop

L_801CB3A8:
    // 0x801CB3A8: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801CB3AC: beq         $t8, $zero, L_801CB43C
    if (ctx->r24 == 0) {
        // 0x801CB3B0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801CB43C;
    }
    // 0x801CB3B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CB3B4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB3B8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CB3BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801CB3C0: addiu       $a3, $a3, -0x808
    ctx->r7 = ADD32(ctx->r7, -0X808);
    // 0x801CB3C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CB3C8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB3CC: jal         0x8001B204
    // 0x801CB3D0: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801CB3D0: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_5:
    // 0x801CB3D4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB3D8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801CB3DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CB3E0: addiu       $a3, $a3, -0x7F0
    ctx->r7 = ADD32(ctx->r7, -0X7F0);
    // 0x801CB3E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CB3E8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB3EC: jal         0x8001B204
    // 0x801CB3F0: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801CB3F0: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    after_6:
    // 0x801CB3F4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB3F8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801CB3FC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801CB400: addiu       $a3, $a3, -0x7DC
    ctx->r7 = ADD32(ctx->r7, -0X7DC);
    // 0x801CB404: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801CB408: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB40C: jal         0x8001B204
    // 0x801CB410: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801CB410: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_7:
    // 0x801CB414: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB418: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801CB41C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CB420: addiu       $a3, $a3, -0x7C0
    ctx->r7 = ADD32(ctx->r7, -0X7C0);
    // 0x801CB424: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801CB428: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB42C: jal         0x8001B204
    // 0x801CB430: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801CB430: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    after_8:
    // 0x801CB434: b           L_801CB530
    // 0x801CB438: nop

        goto L_801CB530;
    // 0x801CB438: nop

L_801CB43C:
    // 0x801CB43C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB440: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801CB444: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801CB448: addiu       $a3, $a3, -0x7A4
    ctx->r7 = ADD32(ctx->r7, -0X7A4);
    // 0x801CB44C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB450: jal         0x8001B204
    // 0x801CB454: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801CB454: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    after_9:
    // 0x801CB458: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB45C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801CB460: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801CB464: addiu       $a3, $a3, -0x788
    ctx->r7 = ADD32(ctx->r7, -0X788);
    // 0x801CB468: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CB46C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB470: jal         0x8001B204
    // 0x801CB474: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801CB474: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_10:
    // 0x801CB478: b           L_801CB530
    // 0x801CB47C: nop

        goto L_801CB530;
    // 0x801CB47C: nop

L_801CB480:
    // 0x801CB480: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x801CB484: beq         $t6, $zero, L_801CB4F4
    if (ctx->r14 == 0) {
        // 0x801CB488: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801CB4F4;
    }
    // 0x801CB488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CB48C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB490: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801CB494: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CB498: addiu       $a3, $a3, -0x76C
    ctx->r7 = ADD32(ctx->r7, -0X76C);
    // 0x801CB49C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CB4A0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB4A4: jal         0x8001B204
    // 0x801CB4A8: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801CB4A8: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_11:
    // 0x801CB4AC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB4B0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801CB4B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801CB4B8: addiu       $a3, $a3, -0x74C
    ctx->r7 = ADD32(ctx->r7, -0X74C);
    // 0x801CB4BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CB4C0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB4C4: jal         0x8001B204
    // 0x801CB4C8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801CB4C8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_12:
    // 0x801CB4CC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB4D0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CB4D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801CB4D8: addiu       $a3, $a3, -0x730
    ctx->r7 = ADD32(ctx->r7, -0X730);
    // 0x801CB4DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801CB4E0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB4E4: jal         0x8001B204
    // 0x801CB4E8: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801CB4E8: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    after_13:
    // 0x801CB4EC: b           L_801CB530
    // 0x801CB4F0: nop

        goto L_801CB530;
    // 0x801CB4F0: nop

L_801CB4F4:
    // 0x801CB4F4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB4F8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801CB4FC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CB500: addiu       $a3, $a3, -0x70C
    ctx->r7 = ADD32(ctx->r7, -0X70C);
    // 0x801CB504: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB508: jal         0x8001B204
    // 0x801CB50C: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x801CB50C: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    after_14:
    // 0x801CB510: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB514: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801CB518: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801CB51C: addiu       $a3, $a3, -0x6F0
    ctx->r7 = ADD32(ctx->r7, -0X6F0);
    // 0x801CB520: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CB524: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CB528: jal         0x8001B204
    // 0x801CB52C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x801CB52C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_15:
L_801CB530:
    // 0x801CB530: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB534: addiu       $a1, $a1, -0x4AB0
    ctx->r5 = ADD32(ctx->r5, -0X4AB0);
    // 0x801CB538: jal         0x800058DC
    // 0x801CB53C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x801CB53C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_16:
L_801CB540:
    // 0x801CB540: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801CB544:
    // 0x801CB544: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801CB548: jr          $ra
    // 0x801CB54C: nop

    return;
    // 0x801CB54C: nop

;}
RECOMP_FUNC void M23_FUN_801cb550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB550: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801CB554: lhu         $t6, -0x6B88($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cb558(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cb558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB558: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CB55C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CB560: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x801CB564: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CB568: beq         $t7, $zero, L_801CB588
    if (ctx->r15 == 0) {
        // 0x801CB56C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801CB588;
    }
    // 0x801CB56C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CB570: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801CB574: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801CB578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801CB57C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801CB580: jal         0x8012FE50
    // 0x801CB584: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801CB584: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
L_801CB588:
    // 0x801CB588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CB58C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CB590: jr          $ra
    // 0x801CB594: nop

    return;
    // 0x801CB594: nop

;}
RECOMP_FUNC void M23_FUN_801cb598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB598: nop

    // 0x801CB59C: nop

;}
RECOMP_FUNC void M23_FUN_801cb5a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB5A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CB5A4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801CB5A8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801CB5AC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CB5B0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801CB5B4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801CB5B8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801CB5BC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801CB5C0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801CB5C4: jal         0x80126930
    // 0x801CB5C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80126930)(rdram, ctx);
        goto after_0;
    // 0x801CB5C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801CB5CC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801CB5D0: addiu       $a1, $a1, 0x4434
    ctx->r5 = ADD32(ctx->r5, 0X4434);
    // 0x801CB5D4: jal         0x80005670
    // 0x801CB5D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801CB5D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x801CB5DC: jal         0x80116E80
    // 0x801CB5E0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_2;
    // 0x801CB5E0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_2:
    // 0x801CB5E4: jal         0x80116E80
    // 0x801CB5E8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_3;
    // 0x801CB5E8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x801CB5EC: sb          $zero, 0x90($s3)
    MEM_B(0X90, ctx->r19) = 0;
    // 0x801CB5F0: sw          $zero, 0xAC($s3)
    MEM_W(0XAC, ctx->r19) = 0;
    // 0x801CB5F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CB5F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801CB5FC: addiu       $s2, $sp, 0x5F
    ctx->r18 = ADD32(ctx->r29, 0X5F);
L_801CB600:
    // 0x801CB600: sll         $a3, $s1, 5
    ctx->r7 = S32(ctx->r17 << 5);
    // 0x801CB604: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801CB608: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801CB60C: addiu       $t6, $zero, 0x56
    ctx->r14 = ADD32(0, 0X56);
    // 0x801CB610: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x801CB614: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x801CB618: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x801CB61C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801CB620: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CB624: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CB628: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CB62C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801CB630: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801CB634: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CB638: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801CB63C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB640: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB644: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB648: jal         0x80146208
    // 0x801CB64C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x801CB64C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    after_4:
    // 0x801CB650: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CB654: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CB658: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x801CB65C: bne         $at, $zero, L_801CB600
    if (ctx->r1 != 0) {
        // 0x801CB660: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_801CB600;
    }
    // 0x801CB660: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x801CB664: sll         $a3, $s1, 5
    ctx->r7 = S32(ctx->r17 << 5);
    // 0x801CB668: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801CB66C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801CB670: addiu       $t0, $zero, 0x56
    ctx->r8 = ADD32(0, 0X56);
    // 0x801CB674: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x801CB678: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801CB67C: addiu       $t3, $zero, 0x228
    ctx->r11 = ADD32(0, 0X228);
    // 0x801CB680: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801CB684: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801CB688: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801CB68C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CB690: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801CB694: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801CB698: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CB69C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801CB6A0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB6A4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CB6A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CB6AC: jal         0x80146208
    // 0x801CB6B0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x801CB6B0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    after_5:
    // 0x801CB6B4: jal         0x80006214
    // 0x801CB6B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x801CB6B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x801CB6BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CB6C0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801CB6C4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x801CB6C8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
L_801CB6CC:
    // 0x801CB6CC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x801CB6D0: addu        $v0, $s4, $t4
    ctx->r2 = ADD32(ctx->r20, ctx->r12);
    // 0x801CB6D4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801CB6D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CB6DC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CB6E0: sh          $a1, 0x28($t5)
    MEM_H(0X28, ctx->r13) = ctx->r5;
    // 0x801CB6E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801CB6E8: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x801CB6EC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB6F0: sb          $zero, 0xD($t7)
    MEM_B(0XD, ctx->r15) = 0;
    // 0x801CB6F4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801CB6F8: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x801CB6FC: lbu         $a0, 0xD($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD);
    // 0x801CB700: sb          $a0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r4;
    // 0x801CB704: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801CB708: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CB70C: sb          $a0, 0x9($t0)
    MEM_B(0X9, ctx->r8) = ctx->r4;
    // 0x801CB710: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801CB714: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB718: sb          $a0, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r4;
    // 0x801CB71C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801CB720: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB724: sb          $a2, 0xE($t4)
    MEM_B(0XE, ctx->r12) = ctx->r6;
    // 0x801CB728: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801CB72C: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x801CB730: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x801CB734: sb          $t6, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r14;
    // 0x801CB738: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801CB73C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CB740: sb          $a3, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r7;
    // 0x801CB744: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801CB748: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x801CB74C: lbu         $t0, 0xF($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XF);
    // 0x801CB750: bne         $at, $zero, L_801CB6CC
    if (ctx->r1 != 0) {
        // 0x801CB754: sb          $t0, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r8;
            goto L_801CB6CC;
    }
    // 0x801CB754: sb          $t0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r8;
    // 0x801CB758: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB75C: addiu       $a1, $a1, -0x4878
    ctx->r5 = ADD32(ctx->r5, -0X4878);
    // 0x801CB760: jal         0x800058DC
    // 0x801CB764: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801CB764: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x801CB768: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CB76C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801CB770: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801CB774: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801CB778: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801CB77C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801CB780: jr          $ra
    // 0x801CB784: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801CB784: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cb788(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cb788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB788: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801CB78C: lw          $t0, -0x2260($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2260);
    // 0x801CB790: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801CB794: ori         $at, $at, 0xA5E0
    ctx->r1 = ctx->r1 | 0XA5E0;
    // 0x801CB798: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cb79c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cb79c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB79C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801CB7A0: mflo        $v0
    ctx->r2 = lo;
    // 0x801CB7A4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801CB7A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801CB7AC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x801CB7B0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801CB7B4: blez        $t6, L_801CB7D4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801CB7B8: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_801CB7D4;
    }
    // 0x801CB7B8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801CB7BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801CB7C0: ori         $at, $at, 0xA5E0
    ctx->r1 = ctx->r1 | 0XA5E0;
    // 0x801CB7C4: multu       $v1, $at
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CB7C8: mflo        $t7
    ctx->r15 = lo;
    // 0x801CB7CC: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x801CB7D0: nop

L_801CB7D4:
    // 0x801CB7D4: addiu       $at, $zero, 0x708
    ctx->r1 = ADD32(0, 0X708);
    // 0x801CB7D8: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x801CB7DC: mflo        $v0
    ctx->r2 = lo;
    // 0x801CB7E0: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x801CB7E4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x801CB7E8: blez        $t8, L_801CB808
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801CB7EC: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_801CB808;
    }
    // 0x801CB7EC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x801CB7F0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801CB7F4: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x801CB7F8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x801CB7FC: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x801CB800: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801CB804: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
L_801CB808:
    // 0x801CB808: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x801CB80C: bne         $at, $zero, L_801CB818
    if (ctx->r1 != 0) {
        // 0x801CB810: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_801CB818;
    }
    // 0x801CB810: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801CB814: addiu       $t1, $zero, 0x63
    ctx->r9 = ADD32(0, 0X63);
L_801CB818:
    // 0x801CB818: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB81C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801CB820: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801CB824: addiu       $a3, $a3, -0x688
    ctx->r7 = ADD32(ctx->r7, -0X688);
    // 0x801CB828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CB82C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CB830: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x801CB834: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x801CB838: jal         0x8001B204
    // 0x801CB83C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801CB83C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_0:
    // 0x801CB840: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CB844: lbu         $v0, -0x43F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43F3);
    // 0x801CB848: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x801CB84C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801CB850: bne         $v0, $zero, L_801CB88C
    if (ctx->r2 != 0) {
        // 0x801CB854: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801CB88C;
    }
    // 0x801CB854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CB858: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB85C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801CB860: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801CB864: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801CB868: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801CB86C: addiu       $a3, $a3, -0x660
    ctx->r7 = ADD32(ctx->r7, -0X660);
    // 0x801CB870: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CB874: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801CB878: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801CB87C: jal         0x8001B204
    // 0x801CB880: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801CB880: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_1:
    // 0x801CB884: b           L_801CB8FC
    // 0x801CB888: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
        goto L_801CB8FC;
    // 0x801CB888: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
L_801CB88C:
    // 0x801CB88C: bne         $v0, $at, L_801CB8CC
    if (ctx->r2 != ctx->r1) {
        // 0x801CB890: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_801CB8CC;
    }
    // 0x801CB890: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801CB894: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB898: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801CB89C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801CB8A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CB8A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CB8A8: addiu       $a3, $a3, -0x644
    ctx->r7 = ADD32(ctx->r7, -0X644);
    // 0x801CB8AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801CB8B0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CB8B4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801CB8B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801CB8BC: jal         0x8001B204
    // 0x801CB8C0: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801CB8C0: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_2:
    // 0x801CB8C4: b           L_801CB8FC
    // 0x801CB8C8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
        goto L_801CB8FC;
    // 0x801CB8C8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
L_801CB8CC:
    // 0x801CB8CC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB8D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801CB8D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB8D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801CB8DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801CB8E0: addiu       $a3, $a3, -0x62C
    ctx->r7 = ADD32(ctx->r7, -0X62C);
    // 0x801CB8E4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CB8E8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801CB8EC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801CB8F0: jal         0x8001B204
    // 0x801CB8F4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801CB8F4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_3:
    // 0x801CB8F8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
L_801CB8FC:
    // 0x801CB8FC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801CB900: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x801CB904: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801CB908: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x801CB90C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x801CB910: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801CB914: mflo        $t9
    ctx->r25 = lo;
    // 0x801CB918: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x801CB91C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB920: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801CB924: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801CB928: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801CB92C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801CB930: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801CB934: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801CB938: addiu       $a3, $a3, -0x60C
    ctx->r7 = ADD32(ctx->r7, -0X60C);
    // 0x801CB93C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801CB940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CB944: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CB948: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    // 0x801CB94C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CB950: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801CB954: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801CB958: jal         0x8001B204
    // 0x801CB95C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801CB95C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_4:
    // 0x801CB960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801CB964: lbu         $t6, -0x2262($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2262);
    // 0x801CB968: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB96C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801CB970: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801CB974: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801CB978: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801CB97C: addiu       $a3, $a3, -0x5D8
    ctx->r7 = ADD32(ctx->r7, -0X5D8);
    // 0x801CB980: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CB984: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CB988: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x801CB98C: jal         0x8001B204
    // 0x801CB990: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801CB990: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_5:
    // 0x801CB994: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801CB998: lbu         $t7, -0x226D($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X226D);
    // 0x801CB99C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x801CB9A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801CB9A4: beq         $t7, $zero, L_801CBB38
    if (ctx->r15 == 0) {
        // 0x801CB9A8: addiu       $a1, $zero, 0x68
        ctx->r5 = ADD32(0, 0X68);
            goto L_801CBB38;
    }
    // 0x801CB9A8: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x801CB9AC: lbu         $v0, 0x90($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X90);
    // 0x801CB9B0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CB9B4: addiu       $a3, $a3, -0x5B4
    ctx->r7 = ADD32(ctx->r7, -0X5B4);
    // 0x801CB9B8: bne         $v0, $zero, L_801CB9C8
    if (ctx->r2 != 0) {
        // 0x801CB9BC: addiu       $a2, $zero, 0xC8
        ctx->r6 = ADD32(0, 0XC8);
            goto L_801CB9C8;
    }
    // 0x801CB9BC: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x801CB9C0: b           L_801CB9CC
    // 0x801CB9C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_801CB9CC;
    // 0x801CB9C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_801CB9C8:
    // 0x801CB9C8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_801CB9CC:
    // 0x801CB9CC: bne         $v0, $zero, L_801CB9DC
    if (ctx->r2 != 0) {
        // 0x801CB9D0: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_801CB9DC;
    }
    // 0x801CB9D0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801CB9D4: b           L_801CB9DC
    // 0x801CB9D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_801CB9DC;
    // 0x801CB9D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_801CB9DC:
    // 0x801CB9DC: bne         $v0, $zero, L_801CB9EC
    if (ctx->r2 != 0) {
        // 0x801CB9E0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801CB9EC;
    }
    // 0x801CB9E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CB9E4: b           L_801CB9EC
    // 0x801CB9E8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_801CB9EC;
    // 0x801CB9E8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_801CB9EC:
    // 0x801CB9EC: bne         $v0, $zero, L_801CB9FC
    if (ctx->r2 != 0) {
        // 0x801CB9F0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801CB9FC;
    }
    // 0x801CB9F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CB9F4: b           L_801CB9FC
    // 0x801CB9F8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_801CB9FC;
    // 0x801CB9F8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_801CB9FC:
    // 0x801CB9FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CBA00: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801CBA04: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801CBA08: jal         0x8001B204
    // 0x801CBA0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801CBA0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
    // 0x801CBA10: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CBA14: lhu         $v0, -0x4368($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4368);
    // 0x801CBA18: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x801CBA1C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x801CBA20: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x801CBA24: beq         $t9, $zero, L_801CBA34
    if (ctx->r25 == 0) {
        // 0x801CBA28: andi        $t4, $v0, 0x100
        ctx->r12 = ctx->r2 & 0X100;
            goto L_801CBA34;
    }
    // 0x801CBA28: andi        $t4, $v0, 0x100
    ctx->r12 = ctx->r2 & 0X100;
    // 0x801CBA2C: b           L_801CBA44
    // 0x801CBA30: sb          $zero, 0x90($t3)
    MEM_B(0X90, ctx->r11) = 0;
        goto L_801CBA44;
    // 0x801CBA30: sb          $zero, 0x90($t3)
    MEM_B(0X90, ctx->r11) = 0;
L_801CBA34:
    // 0x801CBA34: beq         $t4, $zero, L_801CBA44
    if (ctx->r12 == 0) {
        // 0x801CBA38: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_801CBA44;
    }
    // 0x801CBA38: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x801CBA3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CBA40: sb          $t5, 0x90($t6)
    MEM_B(0X90, ctx->r14) = ctx->r13;
L_801CBA44:
    // 0x801CBA44: lhu         $t7, -0x6B88($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6B88);
    // 0x801CBA48: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x801CBA4C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801CBA50: beql        $t8, $zero, L_801CBB7C
    if (ctx->r24 == 0) {
        // 0x801CBA54: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801CBB7C;
    }
    goto skip_0;
    // 0x801CBA54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801CBA58: lbu         $t3, 0x90($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X90);
    // 0x801CBA5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CBA60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CBA64: bne         $t3, $zero, L_801CBA84
    if (ctx->r11 != 0) {
        // 0x801CBA68: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801CBA84;
    }
    // 0x801CBA68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CBA6C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBA70: addiu       $a1, $a1, -0x4414
    ctx->r5 = ADD32(ctx->r5, -0X4414);
    // 0x801CBA74: jal         0x800058DC
    // 0x801CBA78: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801CBA78: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_7:
    // 0x801CBA7C: b           L_801CBB7C
    // 0x801CBA80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801CBB7C;
    // 0x801CBA80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801CBA84:
    // 0x801CBA84: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CBA88: jal         0x8001B204
    // 0x801CBA8C: addiu       $a3, $a3, -0x594
    ctx->r7 = ADD32(ctx->r7, -0X594);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801CBA8C: addiu       $a3, $a3, -0x594
    ctx->r7 = ADD32(ctx->r7, -0X594);
    after_8:
    // 0x801CBA90: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CBA94: addiu       $a3, $a3, -0x590
    ctx->r7 = ADD32(ctx->r7, -0X590);
    // 0x801CBA98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CBA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CBAA0: jal         0x8001B204
    // 0x801CBAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801CBAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x801CBAA8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CBAAC: addiu       $a3, $a3, -0x58C
    ctx->r7 = ADD32(ctx->r7, -0X58C);
    // 0x801CBAB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801CBAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CBAB8: jal         0x8001B204
    // 0x801CBABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801CBABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x801CBAC0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CBAC4: addiu       $a3, $a3, -0x588
    ctx->r7 = ADD32(ctx->r7, -0X588);
    // 0x801CBAC8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801CBACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CBAD0: jal         0x8001B204
    // 0x801CBAD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801CBAD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x801CBAD8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CBADC: addiu       $a3, $a3, -0x584
    ctx->r7 = ADD32(ctx->r7, -0X584);
    // 0x801CBAE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801CBAE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CBAE8: jal         0x8001B204
    // 0x801CBAEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801CBAEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x801CBAF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CBAF4: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_801CBAF8:
    // 0x801CBAF8: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x801CBAFC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x801CBB00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CBB04: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801CBB08: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CBB0C: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801CBB10: bne         $at, $zero, L_801CBAF8
    if (ctx->r1 != 0) {
        // 0x801CBB14: sb          $zero, 0x22($t6)
        MEM_B(0X22, ctx->r14) = 0;
            goto L_801CBAF8;
    }
    // 0x801CBB14: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x801CBB18: jal         0x8037D508
    // 0x801CBB1C: nop

    LOOKUP_FUNC(0x8037D508)(rdram, ctx);
        goto after_13;
    // 0x801CBB1C: nop

    after_13:
    // 0x801CBB20: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBB24: addiu       $a1, $a1, -0x4478
    ctx->r5 = ADD32(ctx->r5, -0X4478);
    // 0x801CBB28: jal         0x800058DC
    // 0x801CBB2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x801CBB2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_14:
    // 0x801CBB30: b           L_801CBB7C
    // 0x801CBB34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801CBB7C;
    // 0x801CBB34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801CBB38:
    // 0x801CBB38: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x801CBB3C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBB40: addiu       $a1, $a1, -0x4414
    ctx->r5 = ADD32(ctx->r5, -0X4414);
    // 0x801CBB44: lw          $v0, 0xAC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XAC);
    // 0x801CBB48: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x801CBB4C: slti        $v1, $v0, 0x12D
    ctx->r3 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x801CBB50: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801CBB54: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x801CBB58: bne         $v1, $zero, L_801CBB70
    if (ctx->r3 != 0) {
        // 0x801CBB5C: sw          $t8, 0xAC($t7)
        MEM_W(0XAC, ctx->r15) = ctx->r24;
            goto L_801CBB70;
    }
    // 0x801CBB5C: sw          $t8, 0xAC($t7)
    MEM_W(0XAC, ctx->r15) = ctx->r24;
    // 0x801CBB60: lhu         $t3, -0x6B88($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X6B88);
    // 0x801CBB64: andi        $t9, $t3, 0x4000
    ctx->r25 = ctx->r11 & 0X4000;
    // 0x801CBB68: beql        $t9, $zero, L_801CBB7C
    if (ctx->r25 == 0) {
        // 0x801CBB6C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801CBB7C;
    }
    goto skip_1;
    // 0x801CBB6C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
L_801CBB70:
    // 0x801CBB70: jal         0x800058DC
    // 0x801CBB74: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x801CBB74: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_15:
    // 0x801CBB78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801CBB7C:
    // 0x801CBB7C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801CBB80: jr          $ra
    // 0x801CBB84: nop

    return;
    // 0x801CBB84: nop

;}
RECOMP_FUNC void M23_FUN_801cbb88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBB88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CBB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBB90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CBB94: jal         0x8037D598
    // 0x801CBB98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8037D598)(rdram, ctx);
        goto after_0;
    // 0x801CBB98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CBB9C: beq         $v0, $zero, L_801CBBDC
    if (ctx->r2 == 0) {
        // 0x801CBBA0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_801CBBDC;
    }
    // 0x801CBBA0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBBA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CBBA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801CBBAC:
    // 0x801CBBAC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801CBBB0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801CBBB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CBBB8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CBBBC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CBBC0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801CBBC4: bne         $at, $zero, L_801CBBAC
    if (ctx->r1 != 0) {
        // 0x801CBBC8: sb          $v1, 0x22($t8)
        MEM_B(0X22, ctx->r24) = ctx->r3;
            goto L_801CBBAC;
    }
    // 0x801CBBC8: sb          $v1, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r3;
    // 0x801CBBCC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBBD0: addiu       $a1, $a1, -0x4878
    ctx->r5 = ADD32(ctx->r5, -0X4878);
    // 0x801CBBD4: jal         0x800058DC
    // 0x801CBBD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CBBD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_801CBBDC:
    // 0x801CBBDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CBBE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CBBE4: jr          $ra
    // 0x801CBBE8: nop

    return;
    // 0x801CBBE8: nop

;}
RECOMP_FUNC void M23_FUN_801cbbec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBBEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801CBBF0: lbu         $t6, -0x226D($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X226D);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cbbf4(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cbbf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBBF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CBBF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBBFC: beq         $t6, $zero, L_801CBC2C
    if (ctx->r14 == 0) {
        // 0x801CBC00: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801CBC2C;
    }
    // 0x801CBC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CBC04: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801CBC08: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    // 0x801CBC0C: jal         0x80005670
    // 0x801CBC10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801CBC10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CBC14: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBC18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CBC1C: jal         0x800058DC
    // 0x801CBC20: addiu       $a1, $a1, -0x43B8
    ctx->r5 = ADD32(ctx->r5, -0X43B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CBC20: addiu       $a1, $a1, -0x43B8
    ctx->r5 = ADD32(ctx->r5, -0X43B8);
    after_1:
    // 0x801CBC24: b           L_801CBC3C
    // 0x801CBC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CBC3C;
    // 0x801CBC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CBC2C:
    // 0x801CBC2C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBC30: jal         0x800058DC
    // 0x801CBC34: addiu       $a1, $a1, -0x42AC
    ctx->r5 = ADD32(ctx->r5, -0X42AC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CBC34: addiu       $a1, $a1, -0x42AC
    ctx->r5 = ADD32(ctx->r5, -0X42AC);
    after_2:
    // 0x801CBC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CBC3C:
    // 0x801CBC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CBC40: jr          $ra
    // 0x801CBC44: nop

    return;
    // 0x801CBC44: nop

;}
RECOMP_FUNC void M23_FUN_801cbc48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBC48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801CBC4C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801CBC50: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801CBC54: jal         0x80142570
    // 0x801CBC58: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x801CBC58: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CBC5C: jal         0x8013EA94
    // 0x801CBC60: nop

    LOOKUP_FUNC(0x8013EA94)(rdram, ctx);
        goto after_1;
    // 0x801CBC60: nop

    after_1:
    // 0x801CBC64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBC68: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x801CBC6C: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x801CBC70: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801CBC74: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801CBC78: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801CBC7C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CBC80: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801CBC84: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CBC88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CBC8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CBC90: addiu       $a1, $a1, -0x554
    ctx->r5 = ADD32(ctx->r5, -0X554);
    // 0x801CBC94: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801CBC98: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CBC9C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CBCA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CBCA4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CBCA8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CBCAC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CBCB0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CBCB4: jal         0x8001A804
    // 0x801CBCB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x801CBCB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x801CBCBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CBCC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CBCC4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBCC8: sb          $t1, -0x4410($at)
    MEM_B(-0X4410, ctx->r1) = ctx->r9;
    // 0x801CBCCC: addiu       $a1, $a1, -0x4318
    ctx->r5 = ADD32(ctx->r5, -0X4318);
    // 0x801CBCD0: jal         0x800058DC
    // 0x801CBCD4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CBCD4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x801CBCD8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801CBCDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801CBCE0: jr          $ra
    // 0x801CBCE4: nop

    return;
    // 0x801CBCE4: nop

;}
RECOMP_FUNC void M23_FUN_801cbce8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBCE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CBCEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CBCF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CBCF4: jal         0x8013EB2C
    // 0x801CBCF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013EB2C)(rdram, ctx);
        goto after_0;
    // 0x801CBCF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CBCFC: beq         $v0, $zero, L_801CBD44
    if (ctx->r2 == 0) {
        // 0x801CBD00: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_801CBD44;
    }
    // 0x801CBD00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBD04: jal         0x80142570
    // 0x801CBD08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x801CBD08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x801CBD0C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBD10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CBD14:
    // 0x801CBD14: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801CBD18: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801CBD1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CBD20: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CBD24: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CBD28: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801CBD2C: bne         $at, $zero, L_801CBD14
    if (ctx->r1 != 0) {
        // 0x801CBD30: sb          $zero, 0x22($t8)
        MEM_B(0X22, ctx->r24) = 0;
            goto L_801CBD14;
    }
    // 0x801CBD30: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x801CBD34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBD38: addiu       $a1, $a1, -0x42AC
    ctx->r5 = ADD32(ctx->r5, -0X42AC);
    // 0x801CBD3C: jal         0x800058DC
    // 0x801CBD40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CBD40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_801CBD44:
    // 0x801CBD44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CBD48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CBD4C: jr          $ra
    // 0x801CBD50: nop

    return;
    // 0x801CBD50: nop

;}
RECOMP_FUNC void M23_FUN_801cbd54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBD54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CBD58: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801CBD5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CBD60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CBD64: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CBD68: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x801CBD6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CBD70:
    // 0x801CBD70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801CBD74: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801CBD78: sltiu       $at, $v0, 0x28
    ctx->r1 = ctx->r2 < 0X28 ? 1 : 0;
    // 0x801CBD7C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x801CBD80: bne         $at, $zero, L_801CBD70
    if (ctx->r1 != 0) {
        // 0x801CBD84: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801CBD70;
    }
    // 0x801CBD84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CBD88: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x801CBD8C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801CBD90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801CBD94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801CBD98: jal         0x8012FE50
    // 0x801CBD9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801CBD9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x801CBDA0: jal         0x80005700
    // 0x801CBDA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801CBDA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801CBDA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBDAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CBDB0: jr          $ra
    // 0x801CBDB4: nop

    return;
    // 0x801CBDB4: nop

;}
RECOMP_FUNC void M23_FUN_801cbdb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBDB8: nop

    // 0x801CBDBC: nop

;}
RECOMP_FUNC void M23_FUN_801cbdc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBDC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CBDC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CBDC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CBDCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CBDD0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801CBDD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CBDD8: jal         0x80005E44
    // 0x801CBDDC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CBDDC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801CBDE0: jal         0x80006214
    // 0x801CBDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CBDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CBDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CBDEC: jal         0x8012636C
    // 0x801CBDF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x801CBDF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x801CBDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CBDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CBDFC: addiu       $a2, $zero, 0xE8
    ctx->r6 = ADD32(0, 0XE8);
    // 0x801CBE00: jal         0x8012C89C
    // 0x801CBE04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801CBE04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801CBE08: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801CBE0C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801CBE10: ori         $a1, $a1, 0xC00
    ctx->r5 = ctx->r5 | 0XC00;
    // 0x801CBE14: jal         0x800062F8
    // 0x801CBE18: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_4;
    // 0x801CBE18: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x801CBE1C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801CBE20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CBE24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801CBE28: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801CBE2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CBE30: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBE34: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CBE38: addiu       $a1, $a1, -0x4178
    ctx->r5 = ADD32(ctx->r5, -0X4178);
    // 0x801CBE3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CBE40: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x801CBE44: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801CBE48: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CBE4C: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    // 0x801CBE50: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801CBE54: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CBE58: swc1        $f0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f0.u32l;
    // 0x801CBE5C: sb          $zero, -0x1FD($at)
    MEM_B(-0X1FD, ctx->r1) = 0;
    // 0x801CBE60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CBE64: sh          $zero, -0x200($at)
    MEM_H(-0X200, ctx->r1) = 0;
    // 0x801CBE68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CBE6C: jal         0x800058DC
    // 0x801CBE70: sb          $zero, -0x1FE($at)
    MEM_B(-0X1FE, ctx->r1) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801CBE70: sb          $zero, -0x1FE($at)
    MEM_B(-0X1FE, ctx->r1) = 0;
    after_5:
    // 0x801CBE74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBE78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CBE7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CBE80: jr          $ra
    // 0x801CBE84: nop

    return;
    // 0x801CBE84: nop

;}
RECOMP_FUNC void M23_FUN_801cbe88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBE88: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801CBE8C: lhu         $t6, -0x6B88($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801cbe90(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801cbe90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBE90: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CBE94: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CBE98: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x801CBE9C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801CBEA0: beq         $t7, $zero, L_801CBFA0
    if (ctx->r15 == 0) {
        // 0x801CBEA4: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_801CBFA0;
    }
    // 0x801CBEA4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801CBEA8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801CBEAC: addiu       $v0, $v0, -0x1FE
    ctx->r2 = ADD32(ctx->r2, -0X1FE);
    // 0x801CBEB0: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x801CBEB4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CBEB8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801CBEBC: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x801CBEC0: beq         $at, $zero, L_801CBF94
    if (ctx->r1 == 0) {
        // 0x801CBEC4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801CBF94;
    }
    // 0x801CBEC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CBEC8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801CBECC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CBED0: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x801CBED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CBED8: lui         $at, 0x4457
    ctx->r1 = S32(0X4457 << 16);
    // 0x801CBEDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CBEE0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801CBEE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CBEE8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801CBEEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CBEF0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x801CBEF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CBEF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CBEFC: lwc1        $f18, -0x324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X324);
    // 0x801CBF00: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801CBF04: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801CBF08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CBF0C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801CBF10: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801CBF14: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801CBF18: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801CBF1C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801CBF20: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801CBF24: addiu       $a0, $a0, -0x4BC
    ctx->r4 = ADD32(ctx->r4, -0X4BC);
    // 0x801CBF28: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
    // 0x801CBF2C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801CBF30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CBF34: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801CBF38: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801CBF3C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801CBF40: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x801CBF44: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x801CBF48: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801CBF4C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801CBF50: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801CBF54: jal         0x8011AAF4
    // 0x801CBF58: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801CBF58: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801CBF5C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CBF60: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801CBF64: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801CBF68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CBF6C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801CBF70: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801CBF74: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801CBF78: addiu       $a3, $a3, -0x480
    ctx->r7 = ADD32(ctx->r7, -0X480);
    // 0x801CBF7C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801CBF80: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CBF84: jal         0x8001B204
    // 0x801CBF88: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801CBF88: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    after_1:
    // 0x801CBF8C: b           L_801CBFA0
    // 0x801CBF90: nop

        goto L_801CBFA0;
    // 0x801CBF90: nop

L_801CBF94:
    // 0x801CBF94: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x801CBF98: b           L_801CC284
    // 0x801CBF9C: sh          $t7, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r15;
        goto L_801CC284;
    // 0x801CBF9C: sh          $t7, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r15;
L_801CBFA0:
    // 0x801CBFA0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801CBFA4: addiu       $t0, $t0, -0x1FE
    ctx->r8 = ADD32(ctx->r8, -0X1FE);
    // 0x801CBFA8: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x801CBFAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801CBFB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CBFB4: bne         $a2, $a0, L_801CBFE8
    if (ctx->r6 != ctx->r4) {
        // 0x801CBFB8: lui         $a1, 0x801D
        ctx->r5 = S32(0X801D << 16);
            goto L_801CBFE8;
    }
    // 0x801CBFB8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBFBC: addiu       $a1, $a1, -0x200
    ctx->r5 = ADD32(ctx->r5, -0X200);
    // 0x801CBFC0: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x801CBFC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CBFC8: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x801CBFCC: slti        $v0, $v1, 0x97
    ctx->r2 = SIGNED(ctx->r3) < 0X97 ? 1 : 0;
    // 0x801CBFD0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801CBFD4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801CBFD8: beq         $v0, $zero, L_801CBFE8
    if (ctx->r2 == 0) {
        // 0x801CBFDC: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_801CBFE8;
    }
    // 0x801CBFDC: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x801CBFE0: b           L_801CC284
    // 0x801CBFE4: sh          $t9, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r25;
        goto L_801CC284;
    // 0x801CBFE4: sh          $t9, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r25;
L_801CBFE8:
    // 0x801CBFE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CBFEC: beq         $a0, $at, L_801CC01C
    if (ctx->r4 == ctx->r1) {
        // 0x801CBFF0: addiu       $a1, $zero, 0xDC
        ctx->r5 = ADD32(0, 0XDC);
            goto L_801CC01C;
    }
    // 0x801CBFF0: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x801CBFF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CBFF8: beq         $a0, $at, L_801CC0A8
    if (ctx->r4 == ctx->r1) {
        // 0x801CBFFC: addiu       $a1, $zero, 0xE2
        ctx->r5 = ADD32(0, 0XE2);
            goto L_801CC0A8;
    }
    // 0x801CBFFC: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x801CC000: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801CC004: beq         $a0, $at, L_801CC158
    if (ctx->r4 == ctx->r1) {
        // 0x801CC008: nop
    
            goto L_801CC158;
    }
    // 0x801CC008: nop

    // 0x801CC00C: beql        $a0, $a2, L_801CC1C0
    if (ctx->r4 == ctx->r6) {
        // 0x801CC010: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_801CC1C0;
    }
    goto skip_0;
    // 0x801CC010: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x801CC014: b           L_801CC288
    // 0x801CC018: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_801CC288;
    // 0x801CC018: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801CC01C:
    // 0x801CC01C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801CC020: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CC024: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801CC028: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CC02C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801CC030: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CC034: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x801CC038: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CC03C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x801CC040: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CC044: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801CC048: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CC04C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801CC050: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CC054: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801CC058: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801CC05C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801CC060: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801CC064: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801CC068: addiu       $a0, $a0, -0x42C
    ctx->r4 = ADD32(ctx->r4, -0X42C);
    // 0x801CC06C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801CC070: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CC074: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801CC078: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801CC07C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801CC080: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801CC084: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801CC088: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801CC08C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801CC090: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801CC094: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801CC098: jal         0x8011AAF4
    // 0x801CC09C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x801CC09C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801CC0A0: b           L_801CC288
    // 0x801CC0A4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_801CC288;
    // 0x801CC0A4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801CC0A8:
    // 0x801CC0A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801CC0AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CC0B0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801CC0B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CC0B8: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x801CC0BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CC0C0: lui         $at, 0x4457
    ctx->r1 = S32(0X4457 << 16);
    // 0x801CC0C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CC0C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CC0CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CC0D0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801CC0D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CC0D8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801CC0DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CC0E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC0E4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801CC0E8: lwc1        $f4, -0x320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X320);
    // 0x801CC0EC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801CC0F0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801CC0F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CC0F8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801CC0FC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801CC100: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801CC104: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CC108: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801CC10C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801CC110: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801CC114: addiu       $a0, $a0, -0x3F0
    ctx->r4 = ADD32(ctx->r4, -0X3F0);
    // 0x801CC118: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801CC11C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CC120: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801CC124: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801CC128: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801CC12C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801CC130: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801CC134: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801CC138: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801CC13C: jal         0x8011AAF4
    // 0x801CC140: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_3;
    // 0x801CC140: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801CC144: bne         $v0, $zero, L_801CC284
    if (ctx->r2 != 0) {
        // 0x801CC148: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_801CC284;
    }
    // 0x801CC148: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801CC14C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC150: b           L_801CC284
    // 0x801CC154: sb          $t7, -0x1FE($at)
    MEM_B(-0X1FE, ctx->r1) = ctx->r15;
        goto L_801CC284;
    // 0x801CC154: sb          $t7, -0x1FE($at)
    MEM_B(-0X1FE, ctx->r1) = ctx->r15;
L_801CC158:
    // 0x801CC158: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801CC15C: addiu       $a0, $a0, -0x1FD
    ctx->r4 = ADD32(ctx->r4, -0X1FD);
    // 0x801CC160: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x801CC164: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x801CC168: beq         $at, $zero, L_801CC180
    if (ctx->r1 == 0) {
        // 0x801CC16C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801CC180;
    }
    // 0x801CC16C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801CC170: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801CC174: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x801CC178: b           L_801CC188
    // 0x801CC17C: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
        goto L_801CC188;
    // 0x801CC17C: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
L_801CC180:
    // 0x801CC180: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CC184: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_801CC188:
    // 0x801CC188: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CC18C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801CC190: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801CC194: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801CC198: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801CC19C: addiu       $a3, $a3, -0x3B4
    ctx->r7 = ADD32(ctx->r7, -0X3B4);
    // 0x801CC1A0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801CC1A4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801CC1A8: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x801CC1AC: jal         0x8001B204
    // 0x801CC1B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801CC1B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x801CC1B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CC1B8: nop

    // 0x801CC1BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801CC1C0:
    // 0x801CC1C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CC1C4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801CC1C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CC1CC: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x801CC1D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CC1D4: lui         $at, 0x4457
    ctx->r1 = S32(0X4457 << 16);
    // 0x801CC1D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CC1DC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801CC1E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CC1E4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801CC1E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CC1EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC1F0: lwc1        $f6, -0x31C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X31C);
    // 0x801CC1F4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801CC1F8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801CC1FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CC200: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801CC204: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801CC208: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CC20C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801CC210: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801CC214: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801CC218: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801CC21C: addiu       $a0, $a0, -0x380
    ctx->r4 = ADD32(ctx->r4, -0X380);
    // 0x801CC220: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x801CC224: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801CC228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CC22C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801CC230: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801CC234: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801CC238: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801CC23C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801CC240: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801CC244: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801CC248: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801CC24C: jal         0x8011AAF4
    // 0x801CC250: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_5;
    // 0x801CC250: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x801CC254: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x801CC258: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801CC25C: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x801CC260: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x801CC264: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x801CC268: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
    // 0x801CC26C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x801CC270: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801CC274: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x801CC278: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x801CC27C: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x801CC280: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
L_801CC284:
    // 0x801CC284: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801CC288:
    // 0x801CC288: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801CC28C: jr          $ra
    // 0x801CC290: nop

    return;
    // 0x801CC290: nop

;}
RECOMP_FUNC void M23_FUN_801cc294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC294: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC298: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801CC29C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CC2A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC2A4: addiu       $t6, $t6, -0x3D34
    ctx->r14 = ADD32(ctx->r14, -0X3D34);
    // 0x801CC2A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CC2AC: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801CC2B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801CC2B4: jal         0x8013B570
    // 0x801CC2B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801CC2B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x801CC2BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CC2C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC2C4: jr          $ra
    // 0x801CC2C8: nop

    return;
    // 0x801CC2C8: nop

;}
RECOMP_FUNC void M23_FUN_801cc2cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC2CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC2D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC2D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC2D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC2DC: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC2E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CC2E4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC2E8: addiu       $t8, $t8, -0x1978
    ctx->r24 = ADD32(ctx->r24, -0X1978);
    // 0x801CC2EC: sh          $t7, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r15;
    // 0x801CC2F0: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC2F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC2F8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC2FC: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC300: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC304: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC308: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC30C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801CC310: jal         0x8013A28C
    // 0x801CC314: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_0;
    // 0x801CC314: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x801CC318: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC31C: jal         0x80010550
    // 0x801CC320: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801CC320: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x801CC324: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC328: addiu       $a1, $a1, -0x3CBC
    ctx->r5 = ADD32(ctx->r5, -0X3CBC);
    // 0x801CC32C: jal         0x800058DC
    // 0x801CC330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CC330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801CC334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC33C: jr          $ra
    // 0x801CC340: nop

    return;
    // 0x801CC340: nop

;}
RECOMP_FUNC void M23_FUN_801cc344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC34C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC350: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC354: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC358: jal         0x80010550
    // 0x801CC35C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC35C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x801CC360: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CC364: lbu         $t7, -0x1FE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1FE);
    // 0x801CC368: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x801CC36C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC370: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801CC374: bne         $at, $zero, L_801CC38C
    if (ctx->r1 != 0) {
        // 0x801CC378: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_801CC38C;
    }
    // 0x801CC378: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC37C: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801CC380: jal         0x800058DC
    // 0x801CC384: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC384: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x801CC388: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
L_801CC38C:
    // 0x801CC38C: beq         $v1, $zero, L_801CC3CC
    if (ctx->r3 == 0) {
        // 0x801CC390: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CC3CC;
    }
    // 0x801CC390: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC394: addiu       $t8, $t8, -0x1954
    ctx->r24 = ADD32(ctx->r24, -0X1954);
    // 0x801CC398: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC39C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC3A0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC3A4: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC3A8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC3AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC3B0: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC3B4: jal         0x8013A28C
    // 0x801CC3B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC3B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC3BC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC3C0: addiu       $a1, $a1, -0x3C24
    ctx->r5 = ADD32(ctx->r5, -0X3C24);
    // 0x801CC3C4: jal         0x800058DC
    // 0x801CC3C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC3C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_801CC3CC:
    // 0x801CC3CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC3D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC3D4: jr          $ra
    // 0x801CC3D8: nop

    return;
    // 0x801CC3D8: nop

;}
RECOMP_FUNC void M23_FUN_801cc3dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC3DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC3E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC3E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC3E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC3EC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC3F0: jal         0x80010550
    // 0x801CC3F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC3F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x801CC3F8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CC3FC: lbu         $t7, -0x1FE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1FE);
    // 0x801CC400: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x801CC404: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC408: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801CC40C: bne         $at, $zero, L_801CC424
    if (ctx->r1 != 0) {
        // 0x801CC410: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_801CC424;
    }
    // 0x801CC410: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC414: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801CC418: jal         0x800058DC
    // 0x801CC41C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC41C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x801CC420: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
L_801CC424:
    // 0x801CC424: beq         $v1, $zero, L_801CC474
    if (ctx->r3 == 0) {
        // 0x801CC428: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CC474;
    }
    // 0x801CC428: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC42C: addiu       $t8, $t8, -0x1948
    ctx->r24 = ADD32(ctx->r24, -0X1948);
    // 0x801CC430: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC434: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC438: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC43C: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC440: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC444: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC448: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC44C: jal         0x8013A28C
    // 0x801CC450: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC450: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC454: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801CC458: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CC45C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC460: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC464: addiu       $a1, $a1, -0x3B7C
    ctx->r5 = ADD32(ctx->r5, -0X3B7C);
    // 0x801CC468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC46C: jal         0x800058DC
    // 0x801CC470: swc1        $f4, -0x1FC($at)
    MEM_W(-0X1FC, ctx->r1) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC470: swc1        $f4, -0x1FC($at)
    MEM_W(-0X1FC, ctx->r1) = ctx->f4.u32l;
    after_3:
L_801CC474:
    // 0x801CC474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC47C: jr          $ra
    // 0x801CC480: nop

    return;
    // 0x801CC480: nop

;}
RECOMP_FUNC void M23_FUN_801cc484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC48C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CC490: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CC494: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC498: jal         0x80010550
    // 0x801CC49C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC49C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x801CC4A0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801CC4A4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801CC4A8: addiu       $v1, $v1, -0x1FC
    ctx->r3 = ADD32(ctx->r3, -0X1FC);
    // 0x801CC4AC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801CC4B0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801CC4B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC4B8: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801CC4BC: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801CC4C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC4C4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CC4C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801CC4CC: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x801CC4D0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801CC4D4: ldc1        $f18, -0x318($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X318);
    // 0x801CC4D8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801CC4DC: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x801CC4E0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801CC4E4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x801CC4E8: lbu         $t9, -0x1FE($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1FE);
    // 0x801CC4EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CC4F0: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x801CC4F4: bnel        $at, $zero, L_801CC510
    if (ctx->r1 != 0) {
        // 0x801CC4F8: lwc1        $f10, 0x0($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
            goto L_801CC510;
    }
    goto skip_0;
    // 0x801CC4F8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x801CC4FC: jal         0x800058DC
    // 0x801CC500: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC500: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    after_1:
    // 0x801CC504: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801CC508: addiu       $v1, $v1, -0x1FC
    ctx->r3 = ADD32(ctx->r3, -0X1FC);
    // 0x801CC50C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
L_801CC510:
    // 0x801CC510: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x801CC514: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801CC518: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801CC51C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801CC520: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x801CC524: addiu       $t0, $t0, -0x193C
    ctx->r8 = ADD32(ctx->r8, -0X193C);
    // 0x801CC528: bc1fl       L_801CC568
    if (!c1cs) {
        // 0x801CC52C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CC568;
    }
    goto skip_1;
    // 0x801CC52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801CC530: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801CC534: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801CC538: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x801CC53C: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x801CC540: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC544: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC548: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x801CC54C: jal         0x8013A28C
    // 0x801CC550: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC550: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC554: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC558: addiu       $a1, $a1, -0x3A8C
    ctx->r5 = ADD32(ctx->r5, -0X3A8C);
    // 0x801CC55C: jal         0x800058DC
    // 0x801CC560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801CC564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC568:
    // 0x801CC568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC56C: jr          $ra
    // 0x801CC570: nop

    return;
    // 0x801CC570: nop

;}
RECOMP_FUNC void M23_FUN_801cc574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC57C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC580: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC584: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC588: jal         0x80010550
    // 0x801CC58C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC58C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x801CC590: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CC594: lbu         $t7, -0x1FE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1FE);
    // 0x801CC598: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x801CC59C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC5A0: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801CC5A4: bne         $at, $zero, L_801CC5BC
    if (ctx->r1 != 0) {
        // 0x801CC5A8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_801CC5BC;
    }
    // 0x801CC5A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC5AC: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801CC5B0: jal         0x800058DC
    // 0x801CC5B4: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC5B4: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x801CC5B8: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
L_801CC5BC:
    // 0x801CC5BC: beq         $v1, $zero, L_801CC608
    if (ctx->r3 == 0) {
        // 0x801CC5C0: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CC608;
    }
    // 0x801CC5C0: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC5C4: addiu       $t8, $t8, -0x1930
    ctx->r24 = ADD32(ctx->r24, -0X1930);
    // 0x801CC5C8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC5CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC5D0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC5D4: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC5D8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC5DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC5E0: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC5E4: jal         0x8013A28C
    // 0x801CC5E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC5E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC5EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CC5F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC5F4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC5F8: sb          $t1, -0x1FE($at)
    MEM_B(-0X1FE, ctx->r1) = ctx->r9;
    // 0x801CC5FC: addiu       $a1, $a1, -0x39E8
    ctx->r5 = ADD32(ctx->r5, -0X39E8);
    // 0x801CC600: jal         0x800058DC
    // 0x801CC604: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC604: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_801CC608:
    // 0x801CC608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC60C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC610: jr          $ra
    // 0x801CC614: nop

    return;
    // 0x801CC614: nop

;}
RECOMP_FUNC void M23_FUN_801cc618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC61C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC620: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC624: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC628: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC62C: jal         0x80010550
    // 0x801CC630: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC630: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x801CC634: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CC638: lbu         $t7, -0x1FE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1FE);
    // 0x801CC63C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x801CC640: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC644: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801CC648: bne         $at, $zero, L_801CC660
    if (ctx->r1 != 0) {
        // 0x801CC64C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_801CC660;
    }
    // 0x801CC64C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC650: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801CC654: jal         0x800058DC
    // 0x801CC658: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC658: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x801CC65C: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
L_801CC660:
    // 0x801CC660: beq         $v1, $zero, L_801CC6A0
    if (ctx->r3 == 0) {
        // 0x801CC664: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CC6A0;
    }
    // 0x801CC664: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC668: addiu       $t8, $t8, -0x1924
    ctx->r24 = ADD32(ctx->r24, -0X1924);
    // 0x801CC66C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC670: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC674: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC678: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC67C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC680: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC684: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC688: jal         0x8013A28C
    // 0x801CC68C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC68C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC690: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC694: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x801CC698: jal         0x800058DC
    // 0x801CC69C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC69C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_801CC6A0:
    // 0x801CC6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC6A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC6A8: jr          $ra
    // 0x801CC6AC: nop

    return;
    // 0x801CC6AC: nop

;}
RECOMP_FUNC void M23_FUN_801cc6b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC6B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC6B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC6BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC6C0: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC6C4: jal         0x80010550
    // 0x801CC6C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC6C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x801CC6CC: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CC6D0: lbu         $t7, -0x1FE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1FE);
    // 0x801CC6D4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x801CC6D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC6DC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801CC6E0: bne         $at, $zero, L_801CC6F8
    if (ctx->r1 != 0) {
        // 0x801CC6E4: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_801CC6F8;
    }
    // 0x801CC6E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC6E8: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801CC6EC: jal         0x800058DC
    // 0x801CC6F0: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC6F0: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x801CC6F4: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
L_801CC6F8:
    // 0x801CC6F8: beq         $v1, $zero, L_801CC738
    if (ctx->r3 == 0) {
        // 0x801CC6FC: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CC738;
    }
    // 0x801CC6FC: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC700: addiu       $t8, $t8, -0x1918
    ctx->r24 = ADD32(ctx->r24, -0X1918);
    // 0x801CC704: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC708: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC70C: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC710: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC714: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC718: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC71C: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC720: jal         0x8013A28C
    // 0x801CC724: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC724: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC728: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC72C: addiu       $a1, $a1, -0x38B8
    ctx->r5 = ADD32(ctx->r5, -0X38B8);
    // 0x801CC730: jal         0x800058DC
    // 0x801CC734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CC734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_801CC738:
    // 0x801CC738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC73C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC740: jr          $ra
    // 0x801CC744: nop

    return;
    // 0x801CC744: nop

;}
RECOMP_FUNC void M23_FUN_801cc748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC750: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CC754: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CC758: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801CC75C: jal         0x80010550
    // 0x801CC760: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801CC760: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x801CC764: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CC768: lbu         $t7, -0x1FE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1FE);
    // 0x801CC76C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x801CC770: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CC774: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801CC778: bne         $at, $zero, L_801CC790
    if (ctx->r1 != 0) {
        // 0x801CC77C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_801CC790;
    }
    // 0x801CC77C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801CC780: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801CC784: jal         0x800058DC
    // 0x801CC788: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CC788: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x801CC78C: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
L_801CC790:
    // 0x801CC790: beq         $v1, $zero, L_801CC7CC
    if (ctx->r3 == 0) {
        // 0x801CC794: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801CC7CC;
    }
    // 0x801CC794: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801CC798: addiu       $t8, $t8, -0x196C
    ctx->r24 = ADD32(ctx->r24, -0X196C);
    // 0x801CC79C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801CC7A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CC7A4: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801CC7A8: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801CC7AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CC7B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC7B4: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801CC7B8: jal         0x8013A28C
    // 0x801CC7BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x801CC7BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801CC7C0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801CC7C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CC7C8: sb          $t1, -0x1FE($at)
    MEM_B(-0X1FE, ctx->r1) = ctx->r9;
L_801CC7CC:
    // 0x801CC7CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC7D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC7D4: jr          $ra
    // 0x801CC7D8: nop

    return;
    // 0x801CC7D8: nop

;}
RECOMP_FUNC void M23_FUN_801cc7dc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801CC7DCu);
    return;
}
RECOMP_FUNC void M54_FUN_803837e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803837E0: lui         $t6, 0x8038
    ctx->r14 = S32(0X8038 << 16);
    // 0x803837E4: lhu         $t6, 0x436A($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X436A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_803837e8(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_803837e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803837E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x803837EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x803837F0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x803837F4: beq         $t6, $zero, L_80383874
    if (ctx->r14 == 0) {
        // 0x803837F8: sw          $s0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r16;
            goto L_80383874;
    }
    // 0x803837F8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x803837FC: lui         $t7, 0x8038
    ctx->r15 = S32(0X8038 << 16);
    // 0x80383800: addiu       $s0, $t7, 0x4360
    ctx->r16 = ADD32(ctx->r15, 0X4360);
    // 0x80383804: lhu         $s1, 0xA($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0XA);
    // 0x80383808: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_8038380C:
    // 0x8038380C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80383810: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x80383814: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80383818: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8038381C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80383820: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80383824: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x80383828: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x8038382C: lhu         $t3, 0xE($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XE);
    // 0x80383830: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80383834: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80383838: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8038383C: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x80383840: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x80383844: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80383848: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8038384C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80383850: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80383854: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80383858: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8038385C: jal         0x8014B1A4
    // 0x80383860: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014B1A4)(rdram, ctx);
        goto after_0;
    // 0x80383860: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    after_0:
    // 0x80383864: lhu         $s1, 0x1A($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X1A);
    // 0x80383868: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8038386C: bnel        $s1, $zero, L_8038380C
    if (ctx->r17 != 0) {
        // 0x80383870: lh          $t0, 0x6($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X6);
            goto L_8038380C;
    }
    goto skip_0;
    // 0x80383870: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    skip_0:
L_80383874:
    // 0x80383874: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80383878: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8038387C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80383880: jr          $ra
    // 0x80383884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80383884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383888(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383888: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8038388C: lui         $t6, 0x8038
    ctx->r14 = S32(0X8038 << 16);
    // 0x80383890: lhu         $t6, 0x436A($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X436A);
    // 0x80383894: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80383898: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8038389C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x803838A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x803838A4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x803838A8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x803838AC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x803838B0: beq         $t6, $zero, L_80383974
    if (ctx->r14 == 0) {
        // 0x803838B4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80383974;
    }
    // 0x803838B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x803838B8: lui         $s0, 0x8038
    ctx->r16 = S32(0X8038 << 16);
    // 0x803838BC: addiu       $s0, $s0, 0x4360
    ctx->r16 = ADD32(ctx->r16, 0X4360);
    // 0x803838C0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x803838C4: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x803838C8: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
L_803838CC:
    // 0x803838CC: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x803838D0: mflo        $t7
    ctx->r15 = lo;
    // 0x803838D4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x803838D8: bne         $s3, $zero, L_803838E4
    if (ctx->r19 != 0) {
        // 0x803838DC: nop
    
            goto L_803838E4;
    }
    // 0x803838DC: nop

    // 0x803838E0: break       7
    do_break(2151168224);
L_803838E4:
    // 0x803838E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x803838E8: bne         $s3, $at, L_803838FC
    if (ctx->r19 != ctx->r1) {
        // 0x803838EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_803838FC;
    }
    // 0x803838EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803838F0: bne         $v0, $at, L_803838FC
    if (ctx->r2 != ctx->r1) {
        // 0x803838F4: nop
    
            goto L_803838FC;
    }
    // 0x803838F4: nop

    // 0x803838F8: break       6
    do_break(2151168248);
L_803838FC:
    // 0x803838FC: bnel        $s2, $t8, L_80383968
    if (ctx->r18 != ctx->r24) {
        // 0x80383900: lhu         $t7, 0x1A($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X1A);
            goto L_80383968;
    }
    goto skip_0;
    // 0x80383900: lhu         $t7, 0x1A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1A);
    skip_0:
    // 0x80383904: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x80383908: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8038390C: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    // 0x80383910: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80383914: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80383918: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8038391C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80383920: lhu         $t2, 0xA($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XA);
    // 0x80383924: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
    // 0x80383928: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x8038392C: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x80383930: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80383934: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80383938: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x8038393C: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x80383940: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80383944: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80383948: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8038394C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80383950: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80383954: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80383958: jal         0x8014B1A4
    // 0x8038395C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8014B1A4)(rdram, ctx);
        goto after_0;
    // 0x8038395C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80383960: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80383964: lhu         $t7, 0x1A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1A);
L_80383968:
    // 0x80383968: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8038396C: bnel        $t7, $zero, L_803838CC
    if (ctx->r15 != 0) {
        // 0x80383970: lhu         $v0, 0xE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XE);
            goto L_803838CC;
    }
    goto skip_1;
    // 0x80383970: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    skip_1:
L_80383974:
    // 0x80383974: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80383978: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8038397C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80383980: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80383984: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80383988: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8038398C: jr          $ra
    // 0x80383990: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80383990: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383994(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383994: nop

    // 0x80383998: nop

    // 0x8038399C: nop

;}
RECOMP_FUNC void M54_FUN_803839a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803839A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803839A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803839A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803839AC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x803839B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803839B4: jal         0x80005E44
    // 0x803839B8: addiu       $a1, $a1, -0x2354
    ctx->r5 = ADD32(ctx->r5, -0X2354);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803839B8: addiu       $a1, $a1, -0x2354
    ctx->r5 = ADD32(ctx->r5, -0X2354);
    after_0:
    // 0x803839BC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803839C0: addiu       $a1, $a1, 0x39DC
    ctx->r5 = ADD32(ctx->r5, 0X39DC);
    // 0x803839C4: jal         0x800058DC
    // 0x803839C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x803839C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x803839CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803839D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803839D4: jr          $ra
    // 0x803839D8: nop

    return;
    // 0x803839D8: nop

;}
RECOMP_FUNC void M54_FUN_803839dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803839DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803839E0: jr          $ra
    // 0x803839E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x803839E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_803839e8(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_803839e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803839E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803839EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803839F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803839F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x803839F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803839FC: jal         0x80005E44
    // 0x80383A00: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80383A00: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    after_0:
    // 0x80383A04: jal         0x80006214
    // 0x80383A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80383A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80383A0C: jal         0x8001F430
    // 0x80383A10: addiu       $a0, $zero, 0x178
    ctx->r4 = ADD32(0, 0X178);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_2;
    // 0x80383A10: addiu       $a0, $zero, 0x178
    ctx->r4 = ADD32(0, 0X178);
    after_2:
    // 0x80383A14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80383A18: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80383A1C: addiu       $v1, $v1, -0x223C
    ctx->r3 = ADD32(ctx->r3, -0X223C);
    // 0x80383A20: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80383A24: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80383A28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80383A2C: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x80383A30: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80383A34: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80383A38: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80383A3C: sw          $t7, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r15;
    // 0x80383A40: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80383A44: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80383A48: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80383A4C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80383A50: jal         0x80032890
    // 0x80383A54: sh          $t2, 0x28($t3)
    MEM_H(0X28, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x80032890)(rdram, ctx);
        goto after_3;
    // 0x80383A54: sh          $t2, 0x28($t3)
    MEM_H(0X28, ctx->r11) = ctx->r10;
    after_3:
    // 0x80383A58: jal         0x80020744
    // 0x80383A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x80383A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80383A60: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A64: sb          $zero, -0x2450($at)
    MEM_B(-0X2450, ctx->r1) = 0;
    // 0x80383A68: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A6C: sw          $zero, -0x244C($at)
    MEM_W(-0X244C, ctx->r1) = 0;
    // 0x80383A70: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A74: sw          $zero, -0x2448($at)
    MEM_W(-0X2448, ctx->r1) = 0;
    // 0x80383A78: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A7C: sb          $zero, -0x2440($at)
    MEM_B(-0X2440, ctx->r1) = 0;
    // 0x80383A80: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A84: sw          $zero, -0x243C($at)
    MEM_W(-0X243C, ctx->r1) = 0;
    // 0x80383A88: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A8C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80383A90: sw          $t4, -0x2438($at)
    MEM_W(-0X2438, ctx->r1) = ctx->r12;
    // 0x80383A94: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383A98: sw          $zero, -0x2434($at)
    MEM_W(-0X2434, ctx->r1) = 0;
    // 0x80383A9C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383AA0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383AA4: sb          $zero, -0x242C($at)
    MEM_B(-0X242C, ctx->r1) = 0;
    // 0x80383AA8: lw          $a1, -0x223C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X223C);
    // 0x80383AAC: jal         0x80383E54
    // 0x80383AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80383E54)(rdram, ctx);
        goto after_5;
    // 0x80383AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80383AB4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80383AB8: addiu       $a1, $a1, 0x3AD4
    ctx->r5 = ADD32(ctx->r5, 0X3AD4);
    // 0x80383ABC: jal         0x800058DC
    // 0x80383AC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80383AC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80383AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383ACC: jr          $ra
    // 0x80383AD0: nop

    return;
    // 0x80383AD0: nop

;}
RECOMP_FUNC void M54_FUN_80383ad4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383AD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80383ADC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383AE0: addiu       $a1, $a1, -0x2438
    ctx->r5 = ADD32(ctx->r5, -0X2438);
    // 0x80383AE4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80383AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80383AF0: bne         $v1, $zero, L_80383B04
    if (ctx->r3 != 0) {
        // 0x80383AF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80383B04;
    }
    // 0x80383AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80383AF8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80383AFC: b           L_80383B0C
    // 0x80383B00: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
        goto L_80383B0C;
    // 0x80383B00: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
L_80383B04:
    // 0x80383B04: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80383B08: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80383B0C:
    // 0x80383B0C: andi        $t7, $v0, 0x1000
    ctx->r15 = ctx->r2 & 0X1000;
    // 0x80383B10: beq         $t7, $zero, L_80383B74
    if (ctx->r15 == 0) {
        // 0x80383B14: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_80383B74;
    }
    // 0x80383B14: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383B18: addiu       $v0, $v0, -0x2448
    ctx->r2 = ADD32(ctx->r2, -0X2448);
    // 0x80383B1C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80383B20: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80383B24: addiu       $v1, $v1, -0x2434
    ctx->r3 = ADD32(ctx->r3, -0X2434);
    // 0x80383B28: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80383B2C: beq         $at, $zero, L_80383B44
    if (ctx->r1 == 0) {
        // 0x80383B30: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_80383B44;
    }
    // 0x80383B30: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80383B34: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80383B38: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80383B3C: b           L_80383B74
    // 0x80383B40: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_80383B74;
    // 0x80383B40: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80383B44:
    // 0x80383B44: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80383B48: addiu       $v1, $v1, -0x2434
    ctx->r3 = ADD32(ctx->r3, -0X2434);
    // 0x80383B4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80383B50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80383B54: bne         $v0, $at, L_80383B64
    if (ctx->r2 != ctx->r1) {
        // 0x80383B58: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_80383B64;
    }
    // 0x80383B58: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80383B5C: b           L_80383B74
    // 0x80383B60: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_80383B74;
    // 0x80383B60: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80383B64:
    // 0x80383B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80383B68: bne         $v0, $at, L_80383B74
    if (ctx->r2 != ctx->r1) {
        // 0x80383B6C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80383B74;
    }
    // 0x80383B6C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80383B70: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80383B74:
    // 0x80383B74: jal         0x80383BCC
    // 0x80383B78: nop

    LOOKUP_FUNC(0x80383BCC)(rdram, ctx);
        goto after_0;
    // 0x80383B78: nop

    after_0:
    // 0x80383B7C: jal         0x80383D08
    // 0x80383B80: nop

    LOOKUP_FUNC(0x80383D08)(rdram, ctx);
        goto after_1;
    // 0x80383B80: nop

    after_1:
    // 0x80383B84: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383B88: lw          $a1, -0x223C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X223C);
    // 0x80383B8C: jal         0x80383E54
    // 0x80383B90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80383E54)(rdram, ctx);
        goto after_2;
    // 0x80383B90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80383B94: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80383B98: lbu         $t3, -0x2450($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2450);
    // 0x80383B9C: beql        $t3, $zero, L_80383BC0
    if (ctx->r11 == 0) {
        // 0x80383BA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383BC0;
    }
    goto skip_0;
    // 0x80383BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383BA4: jal         0x80133AAC
    // 0x80383BA8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80133AAC)(rdram, ctx);
        goto after_3;
    // 0x80383BA8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80383BAC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80383BB0: addiu       $a1, $a1, 0x4E30
    ctx->r5 = ADD32(ctx->r5, 0X4E30);
    // 0x80383BB4: jal         0x800057DC
    // 0x80383BB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800057DC)(rdram, ctx);
        goto after_4;
    // 0x80383BB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80383BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383BC0:
    // 0x80383BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383BC4: jr          $ra
    // 0x80383BC8: nop

    return;
    // 0x80383BC8: nop

;}
RECOMP_FUNC void M54_FUN_80383bcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383BCC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80383BD0: addiu       $a0, $a0, -0x2448
    ctx->r4 = ADD32(ctx->r4, -0X2448);
    // 0x80383BD4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80383BD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383BDC: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383BE0: beq         $v1, $zero, L_80383C14
    if (ctx->r3 == 0) {
            // 0x80383BE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80383C14)(rdram, ctx);
    return;
    }
    // 0x80383BE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80383BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383BEC: beq         $v0, $a1, L_80383C58
    if (ctx->r2 == ctx->r5) {
            // 0x80383BF0: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    LOOKUP_FUNC(0x80383C58)(rdram, ctx);
    return;
    }
    // 0x80383BF0: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383BF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80383BF8: beq         $v0, $at, L_80383CA8
    if (ctx->r2 == ctx->r1) {
            // 0x80383BFC: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    LOOKUP_FUNC(0x80383CA8)(rdram, ctx);
    return;
    }
    // 0x80383BFC: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383C00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80383C04: beq         $v0, $at, L_80383CF8
    if (ctx->r2 == ctx->r1) {
            // 0x80383C08: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    LOOKUP_FUNC(0x80383CF8)(rdram, ctx);
    return;
    }
    // 0x80383C08: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383C0C: jr          $ra
    // 0x80383C10: sw          $zero, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = 0;
    return;
    // 0x80383C10: sw          $zero, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383c14(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383c14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383C14: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383C18: addiu       $a2, $a2, -0x2440
    ctx->r6 = ADD32(ctx->r6, -0X2440);
    // 0x80383C1C: sw          $a1, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = ctx->r5;
    // 0x80383C20: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80383C24: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383C28: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x80383C2C: addiu       $t7, $t6, 0xC
    ctx->r15 = ADD32(ctx->r14, 0XC);
    // 0x80383C30: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80383C34: slti        $at, $t8, 0xF1
    ctx->r1 = SIGNED(ctx->r24) < 0XF1 ? 1 : 0;
    // 0x80383C38: bne         $at, $zero, L_80383C50
    if (ctx->r1 != 0) {
        // 0x80383C3C: sb          $t7, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r15;
            goto L_80383C50;
    }
    // 0x80383C3C: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80383C40: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80383C44: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x80383C48: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80383C4C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_80383C50:
    // 0x80383C50: jr          $ra
    // 0x80383C54: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x80383C54: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383c58(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383c58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383C58: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383C5C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383C60: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x80383C64: sw          $a1, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = ctx->r5;
    // 0x80383C68: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80383C6C: addiu       $a2, $a2, -0x2440
    ctx->r6 = ADD32(ctx->r6, -0X2440);
    // 0x80383C70: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80383C74: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80383C78: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80383C7C: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x80383C80: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383C84: sw          $a1, -0x2428($at)
    MEM_W(-0X2428, ctx->r1) = ctx->r5;
    // 0x80383C88: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80383C8C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80383C90: slti        $at, $t4, 0xA9
    ctx->r1 = SIGNED(ctx->r12) < 0XA9 ? 1 : 0;
    // 0x80383C94: bne         $at, $zero, L_80383D00
    if (ctx->r1 != 0) {
            // 0x80383C98: nop

    LOOKUP_FUNC(0x80383D00)(rdram, ctx);
    return;
    }
    // 0x80383C98: nop

    // 0x80383C9C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80383CA0: jr          $ra
    // 0x80383CA4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x80383CA4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383ca8(rdram, ctx);
;}
