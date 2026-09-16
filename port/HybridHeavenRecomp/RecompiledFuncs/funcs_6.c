#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80017990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017990: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80017994: addiu       $v0, $v0, -0x1188
    ctx->r2 = ADD32(ctx->r2, -0X1188);
    // 0x80017998: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001799C: bne         $t6, $zero, L_800179A8
    if (ctx->r14 != 0) {
        // 0x800179A0: nop
    
            goto L_800179A8;
    }
    // 0x800179A0: nop

    // 0x800179A4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_800179A8:
    // 0x800179A8: jr          $ra
    // 0x800179AC: nop

    return;
    // 0x800179AC: nop

;}
RECOMP_FUNC void FUN_800179b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800179B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800179B4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800179B8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800179BC: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800179C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800179C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800179C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800179CC: addiu       $s1, $s1, -0x3380
    ctx->r17 = ADD32(ctx->r17, -0X3380);
    // 0x800179D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800179D4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_800179D8:
    // 0x800179D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800179DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800179E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800179E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800179E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800179EC: jal         0x8001A804
    // 0x800179F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x800179F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x800179F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800179F8: slti        $at, $s0, 0x7
    ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x800179FC: bnel        $at, $zero, L_800179D8
    if (ctx->r1 != 0) {
        // 0x80017A00: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_800179D8;
    }
    goto skip_0;
    // 0x80017A00: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
    // 0x80017A04: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80017A08: addiu       $s1, $s1, -0x3370
    ctx->r17 = ADD32(ctx->r17, -0X3370);
    // 0x80017A0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017A10: addiu       $s2, $zero, 0x1C
    ctx->r18 = ADD32(0, 0X1C);
    // 0x80017A14: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80017A18:
    // 0x80017A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80017A20: jal         0x8001B204
    // 0x80017A24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80017A24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x80017A28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017A2C: bnel        $s0, $s2, L_80017A18
    if (ctx->r16 != ctx->r18) {
        // 0x80017A30: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80017A18;
    }
    goto skip_1;
    // 0x80017A30: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_1:
    // 0x80017A34: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80017A38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A3C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80017A40: sw          $t6, -0x1188($at)
    MEM_W(-0X1188, ctx->r1) = ctx->r14;
    // 0x80017A44: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A48: sw          $zero, -0x1184($at)
    MEM_W(-0X1184, ctx->r1) = 0;
    // 0x80017A4C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A50: sb          $zero, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = 0;
    // 0x80017A54: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A58: sb          $zero, -0x117F($at)
    MEM_B(-0X117F, ctx->r1) = 0;
    // 0x80017A5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A60: sb          $zero, -0x117E($at)
    MEM_B(-0X117E, ctx->r1) = 0;
    // 0x80017A64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A68: sb          $zero, -0x117D($at)
    MEM_B(-0X117D, ctx->r1) = 0;
    // 0x80017A6C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A70: sh          $zero, -0x1440($at)
    MEM_H(-0X1440, ctx->r1) = 0;
    // 0x80017A74: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A78: sh          $zero, -0x143E($at)
    MEM_H(-0X143E, ctx->r1) = 0;
    // 0x80017A7C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A80: sh          $zero, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = 0;
    // 0x80017A84: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A88: sh          $zero, -0x143A($at)
    MEM_H(-0X143A, ctx->r1) = 0;
    // 0x80017A8C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A90: sh          $zero, -0x1438($at)
    MEM_H(-0X1438, ctx->r1) = 0;
    // 0x80017A94: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017A98: sh          $zero, -0x1436($at)
    MEM_H(-0X1436, ctx->r1) = 0;
    // 0x80017A9C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AA0: sh          $zero, -0x1434($at)
    MEM_H(-0X1434, ctx->r1) = 0;
    // 0x80017AA4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AA8: sh          $zero, -0x1432($at)
    MEM_H(-0X1432, ctx->r1) = 0;
    // 0x80017AAC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AB0: sh          $zero, -0x1430($at)
    MEM_H(-0X1430, ctx->r1) = 0;
    // 0x80017AB4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AB8: sh          $zero, -0x142E($at)
    MEM_H(-0X142E, ctx->r1) = 0;
    // 0x80017ABC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AC0: sh          $t7, -0x142C($at)
    MEM_H(-0X142C, ctx->r1) = ctx->r15;
    // 0x80017AC4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AC8: addiu       $t8, $zero, 0xAB
    ctx->r24 = ADD32(0, 0XAB);
    // 0x80017ACC: sh          $t8, -0x142A($at)
    MEM_H(-0X142A, ctx->r1) = ctx->r24;
    // 0x80017AD0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AD4: addiu       $t9, $zero, 0x104
    ctx->r25 = ADD32(0, 0X104);
    // 0x80017AD8: sh          $t9, -0x1428($at)
    MEM_H(-0X1428, ctx->r1) = ctx->r25;
    // 0x80017ADC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AE0: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80017AE4: sh          $t0, -0x1426($at)
    MEM_H(-0X1426, ctx->r1) = ctx->r8;
    // 0x80017AE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80017AEC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AF0: sh          $v0, -0x1424($at)
    MEM_H(-0X1424, ctx->r1) = ctx->r2;
    // 0x80017AF4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017AF8: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80017AFC: sh          $t1, -0x1422($at)
    MEM_H(-0X1422, ctx->r1) = ctx->r9;
    // 0x80017B00: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B04: addiu       $t2, $zero, 0xAC
    ctx->r10 = ADD32(0, 0XAC);
    // 0x80017B08: sh          $t2, -0x1420($at)
    MEM_H(-0X1420, ctx->r1) = ctx->r10;
    // 0x80017B0C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B10: sh          $zero, -0x141E($at)
    MEM_H(-0X141E, ctx->r1) = 0;
    // 0x80017B14: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B18: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80017B1C: sh          $t3, -0x141C($at)
    MEM_H(-0X141C, ctx->r1) = ctx->r11;
    // 0x80017B20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B24: sh          $v0, -0x141A($at)
    MEM_H(-0X141A, ctx->r1) = ctx->r2;
    // 0x80017B28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B2C: sh          $zero, -0x1418($at)
    MEM_H(-0X1418, ctx->r1) = 0;
    // 0x80017B30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80017B38: sh          $t4, -0x1416($at)
    MEM_H(-0X1416, ctx->r1) = ctx->r12;
    // 0x80017B3C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B40: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
    // 0x80017B44: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B48: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80017B4C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80017B50: sh          $t5, -0x1412($at)
    MEM_H(-0X1412, ctx->r1) = ctx->r13;
    // 0x80017B54: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80017B58: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017B5C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80017B60: sh          $zero, -0x1410($at)
    MEM_H(-0X1410, ctx->r1) = 0;
    // 0x80017B64: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80017B68: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80017B6C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80017B70: sh          $zero, 0x34E($v1)
    MEM_H(0X34E, ctx->r3) = 0;
    // 0x80017B74: sh          $zero, 0x350($v1)
    MEM_H(0X350, ctx->r3) = 0;
    // 0x80017B78: jr          $ra
    // 0x80017B7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80017B7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80017b80(rdram, ctx);
;}
RECOMP_FUNC void FUN_80017b80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017B8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017B90: jal         0x800179B0
    // 0x80017B94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x80017B94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80017B98: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80017B9C: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x80017BA0: jal         0x800058DC
    // 0x80017BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80017BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80017BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017BB0: jr          $ra
    // 0x80017BB4: nop

    return;
    // 0x80017BB4: nop

;}
RECOMP_FUNC void FUN_80017bb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017BB8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80017BBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80017BC0: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80017BC4: addiu       $s3, $s3, -0x1188
    ctx->r19 = ADD32(ctx->r19, -0X1188);
    // 0x80017BC8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80017BCC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017BD0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80017BD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80017BD8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80017BDC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80017BE0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80017BE4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80017BE8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80017BEC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80017BF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017BF4: beq         $t6, $zero, L_80017FDC
    if (ctx->r14 == 0) {
        // 0x80017BF8: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_80017FDC;
    }
    // 0x80017BF8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80017BFC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80017C00: addiu       $v1, $v1, -0x1410
    ctx->r3 = ADD32(ctx->r3, -0X1410);
    // 0x80017C04: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80017C08: beq         $v0, $zero, L_80017C18
    if (ctx->r2 == 0) {
        // 0x80017C0C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80017C18;
    }
    // 0x80017C0C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80017C10: b           L_80017FDC
    // 0x80017C14: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
        goto L_80017FDC;
    // 0x80017C14: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_80017C18:
    // 0x80017C18: lui         $fp, 0x8002
    ctx->r30 = S32(0X8002 << 16);
    // 0x80017C1C: lui         $s7, 0x8002
    ctx->r23 = S32(0X8002 << 16);
    // 0x80017C20: lui         $s6, 0x8002
    ctx->r22 = S32(0X8002 << 16);
    // 0x80017C24: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80017C28: lui         $s4, 0x8002
    ctx->r20 = S32(0X8002 << 16);
    // 0x80017C2C: addiu       $s4, $s4, -0x6D0C
    ctx->r20 = ADD32(ctx->r20, -0X6D0C);
    // 0x80017C30: addiu       $s5, $s5, -0x117C
    ctx->r21 = ADD32(ctx->r21, -0X117C);
    // 0x80017C34: addiu       $s6, $s6, -0x6DD4
    ctx->r22 = ADD32(ctx->r22, -0X6DD4);
    // 0x80017C38: addiu       $s7, $s7, -0x61F4
    ctx->r23 = ADD32(ctx->r23, -0X61F4);
    // 0x80017C3C: addiu       $fp, $fp, -0x6768
    ctx->r30 = ADD32(ctx->r30, -0X6768);
    // 0x80017C40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017C44: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80017C48: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80017C4C:
    // 0x80017C4C: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x80017C50: addiu       $t8, $v0, 0x4
    ctx->r24 = ADD32(ctx->r2, 0X4);
    // 0x80017C54: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80017C58: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x80017C5C: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x80017C60: beq         $at, $zero, L_80017FA8
    if (ctx->r1 == 0) {
        // 0x80017C64: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80017FA8;
    }
    // 0x80017C64: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80017C68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017C6C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80017C70: addu        $at, $at, $t9
    gpr jr_addend_80017C78 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80017C74: lw          $t9, -0x32E8($at)
    ctx->r25 = ADD32(ctx->r1, -0X32E8);
    // 0x80017C78: jr          $t9
    // 0x80017C7C: nop

    switch (jr_addend_80017C78 >> 2) {
        case 0: goto L_80017C80; break;
        case 1: goto L_80017D9C; break;
        case 2: goto L_80017E20; break;
        case 3: goto L_80017E30; break;
        case 4: goto L_80017E40; break;
        case 5: goto L_80017E60; break;
        case 6: goto L_80017ED0; break;
        case 7: goto L_80017F48; break;
        case 8: goto L_80017F8C; break;
        default: switch_error(__func__, 0x80017C78, 0x8004CD18);
    }
    // 0x80017C7C: nop

L_80017C80:
    // 0x80017C80: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80017C84: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80017C88: beql        $t0, $zero, L_80017CB0
    if (ctx->r8 == 0) {
        // 0x80017C8C: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80017CB0;
    }
    goto skip_0;
    // 0x80017C8C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80017C90: lbu         $t1, -0x117F($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X117F);
    // 0x80017C94: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80017C98: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80017C9C: sb          $t1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r9;
    // 0x80017CA0: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x80017CA4: lh          $t3, -0x1168($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X1168);
    // 0x80017CA8: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80017CAC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80017CB0:
    // 0x80017CB0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80017CB4: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x80017CB8: jal         0x8001800C
    // 0x80017CBC: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    LOOKUP_FUNC(0x8001800C)(rdram, ctx);
        goto after_0;
    // 0x80017CBC: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    after_0:
    // 0x80017CC0: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80017CC4: beq         $at, $zero, L_80017D8C
    if (ctx->r1 == 0) {
        // 0x80017CC8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80017D8C;
    }
    // 0x80017CC8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80017CCC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80017CD0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80017CD4: addu        $at, $at, $t6
    gpr jr_addend_80017CDC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80017CD8: lw          $t6, -0x32C4($at)
    ctx->r14 = ADD32(ctx->r1, -0X32C4);
    // 0x80017CDC: jr          $t6
    // 0x80017CE0: nop

    switch (jr_addend_80017CDC >> 2) {
        case 0: goto L_80017D8C; break;
        case 1: goto L_80017CE4; break;
        case 2: goto L_80017D00; break;
        case 3: goto L_80017D1C; break;
        case 4: goto L_80017D34; break;
        case 5: goto L_80017D4C; break;
        case 6: goto L_80017D64; break;
        case 7: goto L_80017D7C; break;
        case 8: goto L_80017D8C; break;
        default: switch_error(__func__, 0x80017CDC, 0x8004CD3C);
    }
    // 0x80017CE0: nop

L_80017CE4:
    // 0x80017CE4: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80017CE8: addiu       $a1, $a1, -0x6BF0
    ctx->r5 = ADD32(ctx->r5, -0X6BF0);
    // 0x80017CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017CF0: jal         0x800058DC
    // 0x80017CF4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80017CF4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_1:
    // 0x80017CF8: b           L_80017D8C
    // 0x80017CFC: nop

        goto L_80017D8C;
    // 0x80017CFC: nop

L_80017D00:
    // 0x80017D00: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80017D04: addiu       $a1, $a1, -0x6BA0
    ctx->r5 = ADD32(ctx->r5, -0X6BA0);
    // 0x80017D08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017D0C: jal         0x800058DC
    // 0x80017D10: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80017D10: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_2:
    // 0x80017D14: b           L_80017D8C
    // 0x80017D18: nop

        goto L_80017D8C;
    // 0x80017D18: nop

L_80017D1C:
    // 0x80017D1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017D20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80017D24: jal         0x800058DC
    // 0x80017D28: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80017D28: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_3:
    // 0x80017D2C: b           L_80017D8C
    // 0x80017D30: nop

        goto L_80017D8C;
    // 0x80017D30: nop

L_80017D34:
    // 0x80017D34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017D38: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80017D3C: jal         0x800058DC
    // 0x80017D40: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80017D40: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_4:
    // 0x80017D44: b           L_80017D8C
    // 0x80017D48: nop

        goto L_80017D8C;
    // 0x80017D48: nop

L_80017D4C:
    // 0x80017D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017D50: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80017D54: jal         0x800058DC
    // 0x80017D58: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80017D58: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_5:
    // 0x80017D5C: b           L_80017D8C
    // 0x80017D60: nop

        goto L_80017D8C;
    // 0x80017D60: nop

L_80017D64:
    // 0x80017D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017D68: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80017D6C: jal         0x800058DC
    // 0x80017D70: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80017D70: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_6:
    // 0x80017D74: b           L_80017D8C
    // 0x80017D78: nop

        goto L_80017D8C;
    // 0x80017D78: nop

L_80017D7C:
    // 0x80017D7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017D80: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80017D84: jal         0x800058DC
    // 0x80017D88: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80017D88: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_7:
L_80017D8C:
    // 0x80017D8C: beql        $s2, $zero, L_80017CB0
    if (ctx->r18 == 0) {
        // 0x80017D90: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80017CB0;
    }
    goto skip_1;
    // 0x80017D90: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x80017D94: b           L_80017FD4
    // 0x80017D98: nop

        goto L_80017FD4;
    // 0x80017D98: nop

L_80017D9C:
    // 0x80017D9C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80017DA0: bnel        $t7, $zero, L_80017DBC
    if (ctx->r15 != 0) {
        // 0x80017DA4: lw          $t0, 0x0($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X0);
            goto L_80017DBC;
    }
    goto skip_2;
    // 0x80017DA4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x80017DA8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80017DAC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80017DB0: b           L_80017FD4
    // 0x80017DB4: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
        goto L_80017FD4;
    // 0x80017DB4: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80017DB8: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
L_80017DBC:
    // 0x80017DBC: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80017DC0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80017DC4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80017DC8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017DCC: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80017DD0: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80017DD4: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80017DD8: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80017DDC: lbu         $t5, -0x12D8($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X12D8);
    // 0x80017DE0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80017DE4: sb          $t6, -0x12D8($at)
    MEM_B(-0X12D8, ctx->r1) = ctx->r14;
    // 0x80017DE8: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80017DEC: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x80017DF0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80017DF4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x80017DF8: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80017DFC: addiu       $t0, $t9, 0xC
    ctx->r8 = ADD32(ctx->r25, 0XC);
    // 0x80017E00: sw          $t0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r8;
    // 0x80017E04: lbu         $t1, -0xB($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0XB);
    // 0x80017E08: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80017E0C: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
    // 0x80017E10: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80017E14: lbu         $t3, -0xB($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0XB);
    // 0x80017E18: b           L_80017FD4
    // 0x80017E1C: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
        goto L_80017FD4;
    // 0x80017E1C: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
L_80017E20:
    // 0x80017E20: jal         0x800183D0
    // 0x80017E24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800183D0)(rdram, ctx);
        goto after_8;
    // 0x80017E24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80017E28: b           L_80017FD4
    // 0x80017E2C: nop

        goto L_80017FD4;
    // 0x80017E2C: nop

L_80017E30:
    // 0x80017E30: jal         0x80018518
    // 0x80017E34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80018518)(rdram, ctx);
        goto after_9;
    // 0x80017E34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80017E38: b           L_80017FD4
    // 0x80017E3C: nop

        goto L_80017FD4;
    // 0x80017E3C: nop

L_80017E40:
    // 0x80017E40: jal         0x80018684
    // 0x80017E44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80018684)(rdram, ctx);
        goto after_10;
    // 0x80017E44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80017E48: beq         $v0, $zero, L_80017FD4
    if (ctx->r2 == 0) {
        // 0x80017E4C: nop
    
            goto L_80017FD4;
    }
    // 0x80017E4C: nop

    // 0x80017E50: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80017E54: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80017E58: b           L_80017FD4
    // 0x80017E5C: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
        goto L_80017FD4;
    // 0x80017E5C: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
L_80017E60:
    // 0x80017E60: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80017E64: addiu       $t6, $t6, -0x12D8
    ctx->r14 = ADD32(ctx->r14, -0X12D8);
    // 0x80017E68: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x80017E6C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80017E70: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80017E74: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80017E78: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80017E7C: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x80017E80: lhu         $t0, -0x143E($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X143E);
    // 0x80017E84: lhu         $t3, -0x140E($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X140E);
    // 0x80017E88: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80017E8C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80017E90: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80017E94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80017E98: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80017E9C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80017EA0: addiu       $t2, $t2, -0x13E8
    ctx->r10 = ADD32(ctx->r10, -0X13E8);
    // 0x80017EA4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80017EA8: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80017EAC: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80017EB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017EB4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80017EB8: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x80017EBC: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80017EC0: jal         0x80018C9C
    // 0x80017EC4: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    LOOKUP_FUNC(0x80018C9C)(rdram, ctx);
        goto after_11;
    // 0x80017EC4: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    after_11:
    // 0x80017EC8: b           L_80017FD4
    // 0x80017ECC: nop

        goto L_80017FD4;
    // 0x80017ECC: nop

L_80017ED0:
    // 0x80017ED0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80017ED4: addiu       $v1, $v1, -0x12D8
    ctx->r3 = ADD32(ctx->r3, -0X12D8);
    // 0x80017ED8: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80017EDC: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80017EE0: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80017EE4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80017EE8: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80017EEC: sb          $zero, -0xB($t7)
    MEM_B(-0XB, ctx->r15) = 0;
    // 0x80017EF0: lhu         $t8, -0x143E($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X143E);
    // 0x80017EF4: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80017EF8: lhu         $t1, -0x1422($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X1422);
    // 0x80017EFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80017F00: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80017F04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017F08: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80017F0C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80017F10: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80017F14: addiu       $t0, $t0, -0x13E8
    ctx->r8 = ADD32(ctx->r8, -0X13E8);
    // 0x80017F18: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80017F1C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80017F20: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80017F24: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80017F28: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80017F2C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80017F30: addiu       $a1, $a1, -0x5FE4
    ctx->r5 = ADD32(ctx->r5, -0X5FE4);
    // 0x80017F34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017F38: jal         0x800058DC
    // 0x80017F3C: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x80017F3C: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    after_12:
    // 0x80017F40: b           L_80017FD4
    // 0x80017F44: nop

        goto L_80017FD4;
    // 0x80017F44: nop

L_80017F48:
    // 0x80017F48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80017F4C: jal         0x800189BC
    // 0x80017F50: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800189BC)(rdram, ctx);
        goto after_13;
    // 0x80017F50: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_13:
    // 0x80017F54: bne         $v0, $zero, L_80017F68
    if (ctx->r2 != 0) {
        // 0x80017F58: nop
    
            goto L_80017F68;
    }
    // 0x80017F58: nop

    // 0x80017F5C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80017F60: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80017F64: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
L_80017F68:
    // 0x80017F68: jal         0x800189BC
    // 0x80017F6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800189BC)(rdram, ctx);
        goto after_14;
    // 0x80017F6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80017F70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017F74: bne         $v0, $at, L_80017FD4
    if (ctx->r2 != ctx->r1) {
        // 0x80017F78: nop
    
            goto L_80017FD4;
    }
    // 0x80017F78: nop

    // 0x80017F7C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80017F80: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x80017F84: b           L_80017FD4
    // 0x80017F88: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
        goto L_80017FD4;
    // 0x80017F88: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
L_80017F8C:
    // 0x80017F8C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80017F90: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017F94: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x80017F98: sw          $t7, -0x1184($at)
    MEM_W(-0X1184, ctx->r1) = ctx->r15;
    // 0x80017F9C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80017FA0: b           L_80017FD4
    // 0x80017FA4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
        goto L_80017FD4;
    // 0x80017FA4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
L_80017FA8:
    // 0x80017FA8: lw          $v0, -0x1184($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1184);
    // 0x80017FAC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017FB0: bnel        $v0, $zero, L_80017FD0
    if (ctx->r2 != 0) {
        // 0x80017FB4: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_80017FD0;
    }
    goto skip_3;
    // 0x80017FB4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    skip_3:
    // 0x80017FB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80017FBC: sh          $zero, -0x40C2($at)
    MEM_H(-0X40C2, ctx->r1) = 0;
    // 0x80017FC0: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x80017FC4: b           L_80017FD4
    // 0x80017FC8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80017FD4;
    // 0x80017FC8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80017FCC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_80017FD0:
    // 0x80017FD0: sw          $zero, -0x1184($at)
    MEM_W(-0X1184, ctx->r1) = 0;
L_80017FD4:
    // 0x80017FD4: beql        $s0, $zero, L_80017C4C
    if (ctx->r16 == 0) {
        // 0x80017FD8: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80017C4C;
    }
    goto skip_4;
    // 0x80017FD8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_4:
L_80017FDC:
    // 0x80017FDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80017FE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017FE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017FE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80017FEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80017FF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80017FF4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80017FF8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80017FFC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80018000: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80018004: jr          $ra
    // 0x80018008: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80018008: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001800c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001800c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001800C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80018010: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80018014: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80018018: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001801C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80018020: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80018024: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80018028: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001802C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80018030: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80018034: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80018038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001803C: addiu       $t7, $t7, 0x4184
    ctx->r15 = ADD32(ctx->r15, 0X4184);
    // 0x80018040: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80018044: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80018048: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8001804C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80018050: lbu         $t9, 0x4($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X4);
    // 0x80018054: addiu       $t1, $t1, 0x418C
    ctx->r9 = ADD32(ctx->r9, 0X418C);
    // 0x80018058: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x8001805C: sb          $t9, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r25;
    // 0x80018060: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80018064: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80018068: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8001806C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80018070: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x80018074: addiu       $t5, $t5, 0x4198
    ctx->r13 = ADD32(ctx->r13, 0X4198);
    // 0x80018078: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8001807C: sh          $t3, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r11;
    // 0x80018080: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80018084: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80018088: addiu       $t4, $sp, 0x5C
    ctx->r12 = ADD32(ctx->r29, 0X5C);
    // 0x8001808C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80018090: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80018094: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80018098: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8001809C: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x800180A0: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800180A4: addiu       $s6, $s6, -0x13E8
    ctx->r22 = ADD32(ctx->r22, -0X13E8);
    // 0x800180A8: addiu       $s5, $s5, -0x143E
    ctx->r21 = ADD32(ctx->r21, -0X143E);
    // 0x800180AC: addiu       $s3, $s3, -0x117F
    ctx->r19 = ADD32(ctx->r19, -0X117F);
    // 0x800180B0: addiu       $s2, $s2, -0x1164
    ctx->r18 = ADD32(ctx->r18, -0X1164);
    // 0x800180B4: addiu       $s1, $s1, -0x1166
    ctx->r17 = ADD32(ctx->r17, -0X1166);
    // 0x800180B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800180BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800180C0: addiu       $s7, $zero, 0x26
    ctx->r23 = ADD32(0, 0X26);
    // 0x800180C4: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800180C8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_800180CC:
    // 0x800180CC: bne         $s4, $zero, L_800180E0
    if (ctx->r20 != 0) {
        // 0x800180D0: ori         $at, $zero, 0xF901
        ctx->r1 = 0 | 0XF901;
            goto L_800180E0;
    }
    // 0x800180D0: ori         $at, $zero, 0xF901
    ctx->r1 = 0 | 0XF901;
    // 0x800180D4: srl         $a0, $fp, 16
    ctx->r4 = S32(U32(ctx->r30) >> 16);
    // 0x800180D8: b           L_800180E8
    // 0x800180DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
        goto L_800180E8;
    // 0x800180DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_800180E0:
    // 0x800180E0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800180E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_800180E8:
    // 0x800180E8: andi        $v0, $a0, 0xFF00
    ctx->r2 = ctx->r4 & 0XFF00;
    // 0x800180EC: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800180F0: bne         $at, $zero, L_80018134
    if (ctx->r1 != 0) {
        // 0x800180F4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80018134;
    }
    // 0x800180F4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800180F8: ori         $at, $zero, 0xFA00
    ctx->r1 = 0 | 0XFA00;
    // 0x800180FC: beq         $v0, $at, L_800182BC
    if (ctx->r2 == ctx->r1) {
        // 0x80018100: ori         $at, $zero, 0xFB00
        ctx->r1 = 0 | 0XFB00;
            goto L_800182BC;
    }
    // 0x80018100: ori         $at, $zero, 0xFB00
    ctx->r1 = 0 | 0XFB00;
    // 0x80018104: beq         $v0, $at, L_800182D0
    if (ctx->r2 == ctx->r1) {
        // 0x80018108: ori         $at, $zero, 0xFC00
        ctx->r1 = 0 | 0XFC00;
            goto L_800182D0;
    }
    // 0x80018108: ori         $at, $zero, 0xFC00
    ctx->r1 = 0 | 0XFC00;
    // 0x8001810C: beq         $v0, $at, L_800182E0
    if (ctx->r2 == ctx->r1) {
        // 0x80018110: ori         $at, $zero, 0xFD00
        ctx->r1 = 0 | 0XFD00;
            goto L_800182E0;
    }
    // 0x80018110: ori         $at, $zero, 0xFD00
    ctx->r1 = 0 | 0XFD00;
    // 0x80018114: beq         $v0, $at, L_80018358
    if (ctx->r2 == ctx->r1) {
        // 0x80018118: ori         $at, $zero, 0xFE00
        ctx->r1 = 0 | 0XFE00;
            goto L_80018358;
    }
    // 0x80018118: ori         $at, $zero, 0xFE00
    ctx->r1 = 0 | 0XFE00;
    // 0x8001811C: beq         $v0, $at, L_80018368
    if (ctx->r2 == ctx->r1) {
        // 0x80018120: ori         $at, $zero, 0xFF00
        ctx->r1 = 0 | 0XFF00;
            goto L_80018368;
    }
    // 0x80018120: ori         $at, $zero, 0xFF00
    ctx->r1 = 0 | 0XFF00;
    // 0x80018124: beq         $v0, $at, L_80018378
    if (ctx->r2 == ctx->r1) {
        // 0x80018128: nop
    
            goto L_80018378;
    }
    // 0x80018128: nop

    // 0x8001812C: b           L_80018380
    // 0x80018130: nop

        goto L_80018380;
    // 0x80018130: nop

L_80018134:
    // 0x80018134: ori         $at, $zero, 0xF000
    ctx->r1 = 0 | 0XF000;
    // 0x80018138: beq         $v0, $at, L_80018388
    if (ctx->r2 == ctx->r1) {
        // 0x8001813C: ori         $at, $zero, 0xF100
        ctx->r1 = 0 | 0XF100;
            goto L_80018388;
    }
    // 0x8001813C: ori         $at, $zero, 0xF100
    ctx->r1 = 0 | 0XF100;
    // 0x80018140: beq         $v0, $at, L_80018188
    if (ctx->r2 == ctx->r1) {
        // 0x80018144: andi        $t8, $v1, 0xF
        ctx->r24 = ctx->r3 & 0XF;
            goto L_80018188;
    }
    // 0x80018144: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x80018148: ori         $at, $zero, 0xF200
    ctx->r1 = 0 | 0XF200;
    // 0x8001814C: beq         $v0, $at, L_80018194
    if (ctx->r2 == ctx->r1) {
        // 0x80018150: andi        $t9, $v1, 0x1
        ctx->r25 = ctx->r3 & 0X1;
            goto L_80018194;
    }
    // 0x80018150: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x80018154: ori         $at, $zero, 0xF300
    ctx->r1 = 0 | 0XF300;
    // 0x80018158: beq         $v0, $at, L_800181B8
    if (ctx->r2 == ctx->r1) {
        // 0x8001815C: lui         $t1, 0x8009
        ctx->r9 = S32(0X8009 << 16);
            goto L_800181B8;
    }
    // 0x8001815C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80018160: ori         $at, $zero, 0xF400
    ctx->r1 = 0 | 0XF400;
    // 0x80018164: beq         $v0, $at, L_80018264
    if (ctx->r2 == ctx->r1) {
        // 0x80018168: andi        $t5, $v1, 0xF
        ctx->r13 = ctx->r3 & 0XF;
            goto L_80018264;
    }
    // 0x80018168: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001816C: ori         $at, $zero, 0xF800
    ctx->r1 = 0 | 0XF800;
    // 0x80018170: beq         $v0, $at, L_80018270
    if (ctx->r2 == ctx->r1) {
        // 0x80018174: ori         $at, $zero, 0xF900
        ctx->r1 = 0 | 0XF900;
            goto L_80018270;
    }
    // 0x80018174: ori         $at, $zero, 0xF900
    ctx->r1 = 0 | 0XF900;
    // 0x80018178: beql        $v0, $at, L_800182B0
    if (ctx->r2 == ctx->r1) {
        // 0x8001817C: sh          $zero, 0x0($s1)
        MEM_H(0X0, ctx->r17) = 0;
            goto L_800182B0;
    }
    goto skip_0;
    // 0x8001817C: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    skip_0:
    // 0x80018180: b           L_80018380
    // 0x80018184: nop

        goto L_80018380;
    // 0x80018184: nop

L_80018188:
    // 0x80018188: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001818C: b           L_80018388
    // 0x80018190: sb          $t8, -0x116C($at)
    MEM_B(-0X116C, ctx->r1) = ctx->r24;
        goto L_80018388;
    // 0x80018190: sb          $t8, -0x116C($at)
    MEM_B(-0X116C, ctx->r1) = ctx->r24;
L_80018194:
    // 0x80018194: beq         $t9, $zero, L_800181B0
    if (ctx->r25 == 0) {
        // 0x80018198: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_800181B0;
    }
    // 0x80018198: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001819C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800181A0: lhu         $t0, -0x1412($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X1412);
    // 0x800181A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800181A8: b           L_80018388
    // 0x800181AC: sb          $t0, -0x116B($at)
    MEM_B(-0X116B, ctx->r1) = ctx->r8;
        goto L_80018388;
    // 0x800181AC: sb          $t0, -0x116B($at)
    MEM_B(-0X116B, ctx->r1) = ctx->r8;
L_800181B0:
    // 0x800181B0: b           L_80018388
    // 0x800181B4: sb          $zero, -0x116B($at)
    MEM_B(-0X116B, ctx->r1) = 0;
        goto L_80018388;
    // 0x800181B4: sb          $zero, -0x116B($at)
    MEM_B(-0X116B, ctx->r1) = 0;
L_800181B8:
    // 0x800181B8: addiu       $t2, $sp, 0x5C
    ctx->r10 = ADD32(ctx->r29, 0X5C);
    // 0x800181BC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800181C0: lw          $t1, -0x1174($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1174);
    // 0x800181C4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800181C8: swl         $t4, 0x0($t1)
    do_swl(rdram, 0X0, ctx->r9, ctx->r12);
    // 0x800181CC: swr         $t4, 0x3($t1)
    do_swr(rdram, 0X3, ctx->r9, ctx->r12);
    // 0x800181D0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800181D4: swl         $t3, 0x4($t1)
    do_swl(rdram, 0X4, ctx->r9, ctx->r11);
    // 0x800181D8: swr         $t3, 0x7($t1)
    do_swr(rdram, 0X7, ctx->r9, ctx->r11);
    // 0x800181DC: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x800181E0: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    // 0x800181E4: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800181E8: multu       $v1, $s7
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800181EC: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x800181F0: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x800181F4: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x800181F8: mflo        $t5
    ctx->r13 = lo;
    // 0x800181FC: addu        $v0, $s6, $t5
    ctx->r2 = ADD32(ctx->r22, ctx->r13);
    // 0x80018200: lbu         $a2, 0x4($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X4);
    // 0x80018204: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80018208: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001820C: beql        $at, $zero, L_80018220
    if (ctx->r1 == 0) {
        // 0x80018210: sb          $a1, 0x0($s3)
        MEM_B(0X0, ctx->r19) = ctx->r5;
            goto L_80018220;
    }
    goto skip_1;
    // 0x80018210: sb          $a1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r5;
    skip_1:
    // 0x80018214: b           L_80018220
    // 0x80018218: sb          $t7, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r15;
        goto L_80018220;
    // 0x80018218: sb          $t7, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r15;
    // 0x8001821C: sb          $a1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r5;
L_80018220:
    // 0x80018220: lbu         $v1, 0xA($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA);
    // 0x80018224: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80018228: beq         $at, $zero, L_80018254
    if (ctx->r1 == 0) {
        // 0x8001822C: addiu       $t4, $v1, 0x1
        ctx->r12 = ADD32(ctx->r3, 0X1);
            goto L_80018254;
    }
    // 0x8001822C: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80018230: lhu         $t1, -0x141A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X141A);
    // 0x80018234: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80018238: lhu         $t9, -0x141E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X141E);
    // 0x8001823C: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80018240: lbu         $t2, 0x70($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X70);
    // 0x80018244: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80018248: sb          $t4, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r12;
    // 0x8001824C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80018250: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
L_80018254:
    // 0x80018254: jal         0x80018C9C
    // 0x80018258: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    LOOKUP_FUNC(0x80018C9C)(rdram, ctx);
        goto after_0;
    // 0x80018258: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    after_0:
    // 0x8001825C: b           L_8001838C
    // 0x80018260: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8001838C;
    // 0x80018260: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80018264:
    // 0x80018264: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018268: b           L_80018388
    // 0x8001826C: sb          $t5, -0x116A($at)
    MEM_B(-0X116A, ctx->r1) = ctx->r13;
        goto L_80018388;
    // 0x8001826C: sb          $t5, -0x116A($at)
    MEM_B(-0X116A, ctx->r1) = ctx->r13;
L_80018270:
    // 0x80018270: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80018274: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80018278: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x8001827C: multu       $v1, $s7
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018280: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80018284: sb          $t6, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r14;
    // 0x80018288: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8001828C: mflo        $t7
    ctx->r15 = lo;
    // 0x80018290: addu        $v0, $s6, $t7
    ctx->r2 = ADD32(ctx->r22, ctx->r15);
    // 0x80018294: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80018298: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8001829C: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x800182A0: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x800182A4: b           L_80018388
    // 0x800182A8: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
        goto L_80018388;
    // 0x800182A8: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x800182AC: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_800182B0:
    // 0x800182B0: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x800182B4: b           L_80018388
    // 0x800182B8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80018388;
    // 0x800182B8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_800182BC:
    // 0x800182BC: jal         0x80019038
    // 0x800182C0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80019038)(rdram, ctx);
        goto after_1;
    // 0x800182C0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    after_1:
    // 0x800182C4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x800182C8: b           L_80018388
    // 0x800182CC: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
        goto L_80018388;
    // 0x800182CC: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_800182D0:
    // 0x800182D0: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x800182D4: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x800182D8: b           L_80018388
    // 0x800182DC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80018388;
    // 0x800182DC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_800182E0:
    // 0x800182E0: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x800182E4: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800182E8: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x800182EC: multu       $v1, $s7
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800182F0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800182F4: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    // 0x800182F8: lhu         $t2, -0x142C($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X142C);
    // 0x800182FC: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80018300: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80018304: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80018308: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x8001830C: mflo        $t0
    ctx->r8 = lo;
    // 0x80018310: addu        $v0, $s6, $t0
    ctx->r2 = ADD32(ctx->r22, ctx->r8);
    // 0x80018314: sh          $t2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r10;
    // 0x80018318: lhu         $t3, -0x142A($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X142A);
    // 0x8001831C: sh          $t3, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r11;
    // 0x80018320: lhu         $t4, -0x1422($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X1422);
    // 0x80018324: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x80018328: lhu         $t5, -0x1420($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X1420);
    // 0x8001832C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80018330: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x80018334: lhu         $t6, -0x1424($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X1424);
    // 0x80018338: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8001833C: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x80018340: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80018344: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x80018348: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8001834C: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80018350: b           L_80018388
    // 0x80018354: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
        goto L_80018388;
    // 0x80018354: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
L_80018358:
    // 0x80018358: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x8001835C: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x80018360: b           L_80018388
    // 0x80018364: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_80018388;
    // 0x80018364: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_80018368:
    // 0x80018368: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x8001836C: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x80018370: b           L_80018388
    // 0x80018374: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80018388;
    // 0x80018374: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_80018378:
    // 0x80018378: b           L_80018388
    // 0x8001837C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_80018388;
    // 0x8001837C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_80018380:
    // 0x80018380: jal         0x80018E9C
    // 0x80018384: nop

    LOOKUP_FUNC(0x80018E9C)(rdram, ctx);
        goto after_2;
    // 0x80018384: nop

    after_2:
L_80018388:
    // 0x80018388: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8001838C:
    // 0x8001838C: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x80018390: beq         $at, $zero, L_800183A0
    if (ctx->r1 == 0) {
        // 0x80018394: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800183A0;
    }
    // 0x80018394: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80018398: beq         $s0, $zero, L_800180CC
    if (ctx->r16 == 0) {
        // 0x8001839C: nop
    
            goto L_800180CC;
    }
    // 0x8001839C: nop

L_800183A0:
    // 0x800183A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800183A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800183A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800183AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800183B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800183B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800183B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800183BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800183C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800183C4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800183C8: jr          $ra
    // 0x800183CC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800183CC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800183d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800183d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800183D0: srl         $t6, $a0, 16
    ctx->r14 = S32(U32(ctx->r4) >> 16);
    // 0x800183D4: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800183D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800183DC: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x800183E0: beq         $at, $zero, L_80018508
    if (ctx->r1 == 0) {
        // 0x800183E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80018508;
    }
    // 0x800183E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800183E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800183EC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800183F0: addu        $at, $at, $t7
    gpr jr_addend_800183F8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800183F4: lw          $t7, -0x32A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X32A0);
    // 0x800183F8: jr          $t7
    // 0x800183FC: nop

    switch (jr_addend_800183F8 >> 2) {
        case 0: goto L_80018400; break;
        case 1: goto L_80018418; break;
        case 2: goto L_80018430; break;
        case 3: goto L_80018444; break;
        case 4: goto L_80018464; break;
        case 5: goto L_8001848C; break;
        case 6: goto L_800184A0; break;
        case 7: goto L_800184B0; break;
        case 8: goto L_800184C0; break;
        case 9: goto L_800184D4; break;
        case 10: goto L_800184F4; break;
        default: switch_error(__func__, 0x800183F8, 0x8004CD60);
    }
    // 0x800183FC: nop

L_80018400:
    // 0x80018400: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018404: jal         0x80002BE0
    // 0x80018408: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80018408: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    after_0:
    // 0x8001840C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018410: b           L_80018508
    // 0x80018414: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
        goto L_80018508;
    // 0x80018414: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_80018418:
    // 0x80018418: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001841C: jal         0x80002D00
    // 0x80018420: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    LOOKUP_FUNC(0x80002D00)(rdram, ctx);
        goto after_1;
    // 0x80018420: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    after_1:
    // 0x80018424: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018428: b           L_80018508
    // 0x8001842C: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
        goto L_80018508;
    // 0x8001842C: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_80018430:
    // 0x80018430: jal         0x801414B0
    // 0x80018434: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801414B0)(rdram, ctx);
        goto after_2;
    // 0x80018434: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80018438: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001843C: b           L_80018508
    // 0x80018440: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
        goto L_80018508;
    // 0x80018440: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_80018444:
    // 0x80018444: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018448: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001844C: lbu         $a1, -0x1439($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1439);
    // 0x80018450: jal         0x8000303C
    // 0x80018454: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    LOOKUP_FUNC(0x8000303C)(rdram, ctx);
        goto after_3;
    // 0x80018454: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    after_3:
    // 0x80018458: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001845C: b           L_80018508
    // 0x80018460: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
        goto L_80018508;
    // 0x80018460: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_80018464:
    // 0x80018464: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018468: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    // 0x8001846C: jal         0x80003118
    // 0x80018470: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x80003118)(rdram, ctx);
        goto after_4;
    // 0x80018470: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_4:
    // 0x80018474: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018478: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8001847C: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
    // 0x80018480: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018484: b           L_80018508
    // 0x80018488: sh          $t8, -0x143A($at)
    MEM_H(-0X143A, ctx->r1) = ctx->r24;
        goto L_80018508;
    // 0x80018488: sh          $t8, -0x143A($at)
    MEM_H(-0X143A, ctx->r1) = ctx->r24;
L_8001848C:
    // 0x8001848C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018490: jal         0x80017820
    // 0x80018494: lhu         $a0, -0x143C($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X143C);
    LOOKUP_FUNC(0x80017820)(rdram, ctx);
        goto after_5;
    // 0x80018494: lhu         $a0, -0x143C($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X143C);
    after_5:
    // 0x80018498: b           L_8001850C
    // 0x8001849C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001850C;
    // 0x8001849C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800184A0:
    // 0x800184A0: jal         0x80141108
    // 0x800184A4: nop

    LOOKUP_FUNC(0x80141108)(rdram, ctx);
        goto after_6;
    // 0x800184A4: nop

    after_6:
    // 0x800184A8: b           L_8001850C
    // 0x800184AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001850C;
    // 0x800184AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800184B0:
    // 0x800184B0: jal         0x801414B0
    // 0x800184B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801414B0)(rdram, ctx);
        goto after_7;
    // 0x800184B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800184B8: b           L_8001850C
    // 0x800184BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001850C;
    // 0x800184BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800184C0:
    // 0x800184C0: jal         0x801414B0
    // 0x800184C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801414B0)(rdram, ctx);
        goto after_8;
    // 0x800184C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x800184C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800184CC: b           L_80018508
    // 0x800184D0: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
        goto L_80018508;
    // 0x800184D0: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_800184D4:
    // 0x800184D4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800184D8: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    // 0x800184DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800184E0: jal         0x80002DBC
    // 0x800184E4: addiu       $a2, $sp, 0x1F
    ctx->r6 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x80002DBC)(rdram, ctx);
        goto after_9;
    // 0x800184E4: addiu       $a2, $sp, 0x1F
    ctx->r6 = ADD32(ctx->r29, 0X1F);
    after_9:
    // 0x800184E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800184EC: b           L_80018508
    // 0x800184F0: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
        goto L_80018508;
    // 0x800184F0: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_800184F4:
    // 0x800184F4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800184F8: jal         0x80141934
    // 0x800184FC: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    LOOKUP_FUNC(0x80141934)(rdram, ctx);
        goto after_10;
    // 0x800184FC: lbu         $a0, -0x143B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143B);
    after_10:
    // 0x80018500: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018504: sh          $v0, -0x143C($at)
    MEM_H(-0X143C, ctx->r1) = ctx->r2;
L_80018508:
    // 0x80018508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001850C:
    // 0x8001850C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018510: jr          $ra
    // 0x80018514: nop

    return;
    // 0x80018514: nop

;}
RECOMP_FUNC void FUN_80018518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018518: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x8001851C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80018520: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80018524: beq         $at, $zero, L_8001867C
    if (ctx->r1 == 0) {
        // 0x80018528: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8001867C;
    }
    // 0x80018528: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001852C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80018530: addu        $at, $at, $t7
    gpr jr_addend_80018538 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80018534: lw          $t7, -0x3274($at)
    ctx->r15 = ADD32(ctx->r1, -0X3274);
    // 0x80018538: jr          $t7
    // 0x8001853C: nop

    switch (jr_addend_80018538 >> 2) {
        case 0: goto L_80018540; break;
        case 1: goto L_80018568; break;
        case 2: goto L_80018598; break;
        case 3: goto L_800185C8; break;
        case 4: goto L_80018600; break;
        case 5: goto L_80018640; break;
        default: switch_error(__func__, 0x80018538, 0x8004CD8C);
    }
    // 0x8001853C: nop

L_80018540:
    // 0x80018540: srl         $t9, $a0, 8
    ctx->r25 = S32(U32(ctx->r4) >> 8);
    // 0x80018544: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80018548: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x8001854C: addiu       $v1, $v1, 0x40A4
    ctx->r3 = ADD32(ctx->r3, 0X40A4);
    // 0x80018550: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80018554: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80018558: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001855C: srl         $t8, $a0, 16
    ctx->r24 = S32(U32(ctx->r4) >> 16);
    // 0x80018560: jr          $ra
    // 0x80018564: sh          $t8, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r24;
    return;
    // 0x80018564: sh          $t8, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r24;
L_80018568:
    // 0x80018568: srl         $t4, $a0, 8
    ctx->r12 = S32(U32(ctx->r4) >> 8);
    // 0x8001856C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80018570: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x80018574: addiu       $v1, $v1, 0x40A4
    ctx->r3 = ADD32(ctx->r3, 0X40A4);
    // 0x80018578: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001857C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80018580: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80018584: srl         $t1, $a0, 16
    ctx->r9 = S32(U32(ctx->r4) >> 16);
    // 0x80018588: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8001858C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80018590: jr          $ra
    // 0x80018594: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x80018594: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_80018598:
    // 0x80018598: srl         $t8, $a0, 8
    ctx->r24 = S32(U32(ctx->r4) >> 8);
    // 0x8001859C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800185A0: andi        $t3, $t8, 0x1F
    ctx->r11 = ctx->r24 & 0X1F;
    // 0x800185A4: addiu       $v1, $v1, 0x40A4
    ctx->r3 = ADD32(ctx->r3, 0X40A4);
    // 0x800185A8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800185AC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800185B0: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x800185B4: srl         $t0, $a0, 16
    ctx->r8 = S32(U32(ctx->r4) >> 16);
    // 0x800185B8: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800185BC: subu        $t9, $t6, $t0
    ctx->r25 = SUB32(ctx->r14, ctx->r8);
    // 0x800185C0: jr          $ra
    // 0x800185C4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    return;
    // 0x800185C4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_800185C8:
    // 0x800185C8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800185CC: srl         $t1, $a0, 16
    ctx->r9 = S32(U32(ctx->r4) >> 16);
    // 0x800185D0: addiu       $v1, $v1, 0x40A4
    ctx->r3 = ADD32(ctx->r3, 0X40A4);
    // 0x800185D4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800185D8: addu        $t8, $v1, $t2
    ctx->r24 = ADD32(ctx->r3, ctx->r10);
    // 0x800185DC: srl         $t5, $a0, 8
    ctx->r13 = S32(U32(ctx->r4) >> 8);
    // 0x800185E0: lw          $t3, 0x0($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X0);
    // 0x800185E4: andi        $t7, $t5, 0x1F
    ctx->r15 = ctx->r13 & 0X1F;
    // 0x800185E8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800185EC: addu        $t0, $v1, $t6
    ctx->r8 = ADD32(ctx->r3, ctx->r14);
    // 0x800185F0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800185F4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800185F8: jr          $ra
    // 0x800185FC: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    return;
    // 0x800185FC: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
L_80018600:
    // 0x80018600: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80018604: srl         $t1, $a0, 8
    ctx->r9 = S32(U32(ctx->r4) >> 8);
    // 0x80018608: addiu       $v1, $v1, 0x40A4
    ctx->r3 = ADD32(ctx->r3, 0X40A4);
    // 0x8001860C: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x80018610: srl         $t7, $a0, 16
    ctx->r15 = S32(U32(ctx->r4) >> 16);
    // 0x80018614: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80018618: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8001861C: addu        $t3, $v1, $t8
    ctx->r11 = ADD32(ctx->r3, ctx->r24);
    // 0x80018620: addu        $t0, $v1, $t6
    ctx->r8 = ADD32(ctx->r3, ctx->r14);
    // 0x80018624: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80018628: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8001862C: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80018630: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x80018634: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x80018638: jr          $ra
    // 0x8001863C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x8001863C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_80018640:
    // 0x80018640: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80018644: srl         $t2, $a0, 8
    ctx->r10 = S32(U32(ctx->r4) >> 8);
    // 0x80018648: addiu       $v1, $v1, 0x40A4
    ctx->r3 = ADD32(ctx->r3, 0X40A4);
    // 0x8001864C: andi        $t8, $t2, 0x1F
    ctx->r24 = ctx->r10 & 0X1F;
    // 0x80018650: srl         $t0, $a0, 16
    ctx->r8 = S32(U32(ctx->r4) >> 16);
    // 0x80018654: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80018658: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8001865C: addu        $t7, $v1, $t3
    ctx->r15 = ADD32(ctx->r3, ctx->r11);
    // 0x80018660: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80018664: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80018668: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001866C: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x80018670: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80018674: subu        $t2, $t6, $t1
    ctx->r10 = SUB32(ctx->r14, ctx->r9);
    // 0x80018678: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_8001867C:
    // 0x8001867C: jr          $ra
    // 0x80018680: nop

    return;
    // 0x80018680: nop

;}
RECOMP_FUNC void FUN_80018684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018684: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80018688: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8001868C: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x80018690: beq         $at, $zero, L_800189B4
    if (ctx->r1 == 0) {
        // 0x80018694: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800189B4;
    }
    // 0x80018694: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018698: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001869C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800186A0: addu        $at, $at, $t7
    gpr jr_addend_800186A8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800186A4: lw          $t7, -0x325C($at)
    ctx->r15 = ADD32(ctx->r1, -0X325C);
    // 0x800186A8: jr          $t7
    // 0x800186AC: nop

    switch (jr_addend_800186A8 >> 2) {
        case 0: goto L_800186B0; break;
        case 1: goto L_800186E8; break;
        case 2: goto L_80018720; break;
        case 3: goto L_8001875C; break;
        case 4: goto L_80018798; break;
        case 5: goto L_800187D4; break;
        case 6: goto L_80018810; break;
        case 7: goto L_80018854; break;
        case 8: goto L_80018898; break;
        case 9: goto L_800188E0; break;
        case 10: goto L_80018928; break;
        case 11: goto L_80018970; break;
        default: switch_error(__func__, 0x800186A8, 0x8004CDA4);
    }
    // 0x800186AC: nop

L_800186B0:
    // 0x800186B0: srl         $t0, $a0, 8
    ctx->r8 = S32(U32(ctx->r4) >> 8);
    // 0x800186B4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800186B8: andi        $t1, $t0, 0x1F
    ctx->r9 = ctx->r8 & 0X1F;
    // 0x800186BC: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x800186C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800186C4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800186C8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800186CC: srl         $t8, $a0, 16
    ctx->r24 = S32(U32(ctx->r4) >> 16);
    // 0x800186D0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800186D4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800186D8: bne         $t9, $t5, L_800189B4
    if (ctx->r25 != ctx->r13) {
        // 0x800186DC: nop
    
            goto L_800189B4;
    }
    // 0x800186DC: nop

    // 0x800186E0: jr          $ra
    // 0x800186E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800186E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800186E8:
    // 0x800186E8: srl         $t8, $a0, 8
    ctx->r24 = S32(U32(ctx->r4) >> 8);
    // 0x800186EC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800186F0: andi        $t0, $t8, 0x1F
    ctx->r8 = ctx->r24 & 0X1F;
    // 0x800186F4: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x800186F8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800186FC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80018700: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80018704: srl         $t6, $a0, 16
    ctx->r14 = S32(U32(ctx->r4) >> 16);
    // 0x80018708: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8001870C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80018710: beq         $t7, $t4, L_800189B4
    if (ctx->r15 == ctx->r12) {
        // 0x80018714: nop
    
            goto L_800189B4;
    }
    // 0x80018714: nop

    // 0x80018718: jr          $ra
    // 0x8001871C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001871C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018720:
    // 0x80018720: srl         $t6, $a0, 8
    ctx->r14 = S32(U32(ctx->r4) >> 8);
    // 0x80018724: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80018728: andi        $t8, $t6, 0x1F
    ctx->r24 = ctx->r14 & 0X1F;
    // 0x8001872C: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x80018730: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80018734: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80018738: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001873C: srl         $t9, $a0, 16
    ctx->r25 = S32(U32(ctx->r4) >> 16);
    // 0x80018740: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80018744: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80018748: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001874C: bne         $at, $zero, L_800189B4
    if (ctx->r1 != 0) {
        // 0x80018750: nop
    
            goto L_800189B4;
    }
    // 0x80018750: nop

    // 0x80018754: jr          $ra
    // 0x80018758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80018758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001875C:
    // 0x8001875C: srl         $t7, $a0, 8
    ctx->r15 = S32(U32(ctx->r4) >> 8);
    // 0x80018760: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80018764: andi        $t4, $t7, 0x1F
    ctx->r12 = ctx->r15 & 0X1F;
    // 0x80018768: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x8001876C: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80018770: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80018774: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80018778: srl         $t1, $a0, 16
    ctx->r9 = S32(U32(ctx->r4) >> 16);
    // 0x8001877C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80018780: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x80018784: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80018788: bne         $at, $zero, L_800189B4
    if (ctx->r1 != 0) {
        // 0x8001878C: nop
    
            goto L_800189B4;
    }
    // 0x8001878C: nop

    // 0x80018790: jr          $ra
    // 0x80018794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80018794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018798:
    // 0x80018798: srl         $t5, $a0, 8
    ctx->r13 = S32(U32(ctx->r4) >> 8);
    // 0x8001879C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800187A0: andi        $t3, $t5, 0x1F
    ctx->r11 = ctx->r13 & 0X1F;
    // 0x800187A4: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x800187A8: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800187AC: addu        $t4, $v0, $t7
    ctx->r12 = ADD32(ctx->r2, ctx->r15);
    // 0x800187B0: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800187B4: srl         $t8, $a0, 16
    ctx->r24 = S32(U32(ctx->r4) >> 16);
    // 0x800187B8: andi        $t1, $t8, 0xFFFF
    ctx->r9 = ctx->r24 & 0XFFFF;
    // 0x800187BC: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800187C0: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800187C4: beq         $at, $zero, L_800189B4
    if (ctx->r1 == 0) {
        // 0x800187C8: nop
    
            goto L_800189B4;
    }
    // 0x800187C8: nop

    // 0x800187CC: jr          $ra
    // 0x800187D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800187D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800187D4:
    // 0x800187D4: srl         $t5, $a0, 8
    ctx->r13 = S32(U32(ctx->r4) >> 8);
    // 0x800187D8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800187DC: andi        $t3, $t5, 0x1F
    ctx->r11 = ctx->r13 & 0X1F;
    // 0x800187E0: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x800187E4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800187E8: addu        $t4, $v0, $t7
    ctx->r12 = ADD32(ctx->r2, ctx->r15);
    // 0x800187EC: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800187F0: srl         $t0, $a0, 16
    ctx->r8 = S32(U32(ctx->r4) >> 16);
    // 0x800187F4: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x800187F8: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x800187FC: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80018800: beq         $at, $zero, L_800189B4
    if (ctx->r1 == 0) {
        // 0x80018804: nop
    
            goto L_800189B4;
    }
    // 0x80018804: nop

    // 0x80018808: jr          $ra
    // 0x8001880C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001880C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018810:
    // 0x80018810: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80018814: srl         $t6, $a0, 8
    ctx->r14 = S32(U32(ctx->r4) >> 8);
    // 0x80018818: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x8001881C: andi        $t1, $t6, 0x1F
    ctx->r9 = ctx->r14 & 0X1F;
    // 0x80018820: srl         $t4, $a0, 16
    ctx->r12 = S32(U32(ctx->r4) >> 16);
    // 0x80018824: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80018828: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8001882C: addu        $t5, $v0, $t0
    ctx->r13 = ADD32(ctx->r2, ctx->r8);
    // 0x80018830: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80018834: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80018838: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x8001883C: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x80018840: lhu         $t7, 0x0($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X0);
    // 0x80018844: bne         $t7, $t6, L_800189B4
    if (ctx->r15 != ctx->r14) {
        // 0x80018848: nop
    
            goto L_800189B4;
    }
    // 0x80018848: nop

    // 0x8001884C: jr          $ra
    // 0x80018850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80018850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018854:
    // 0x80018854: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80018858: srl         $t1, $a0, 8
    ctx->r9 = S32(U32(ctx->r4) >> 8);
    // 0x8001885C: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x80018860: andi        $t0, $t1, 0x1F
    ctx->r8 = ctx->r9 & 0X1F;
    // 0x80018864: srl         $t2, $a0, 16
    ctx->r10 = S32(U32(ctx->r4) >> 16);
    // 0x80018868: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8001886C: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80018870: addu        $t3, $v0, $t5
    ctx->r11 = ADD32(ctx->r2, ctx->r13);
    // 0x80018874: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x80018878: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001887C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80018880: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x80018884: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80018888: beq         $t9, $t1, L_800189B4
    if (ctx->r25 == ctx->r9) {
        // 0x8001888C: nop
    
            goto L_800189B4;
    }
    // 0x8001888C: nop

    // 0x80018890: jr          $ra
    // 0x80018894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80018894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018898:
    // 0x80018898: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001889C: srl         $t8, $a0, 8
    ctx->r24 = S32(U32(ctx->r4) >> 8);
    // 0x800188A0: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x800188A4: andi        $t7, $t8, 0x1F
    ctx->r15 = ctx->r24 & 0X1F;
    // 0x800188A8: srl         $t0, $a0, 16
    ctx->r8 = S32(U32(ctx->r4) >> 16);
    // 0x800188AC: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800188B0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800188B4: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800188B8: addu        $t3, $v0, $t5
    ctx->r11 = ADD32(ctx->r2, ctx->r13);
    // 0x800188BC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800188C0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800188C4: lhu         $t2, 0x0($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X0);
    // 0x800188C8: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x800188CC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800188D0: bne         $at, $zero, L_800189B4
    if (ctx->r1 != 0) {
        // 0x800188D4: nop
    
            goto L_800189B4;
    }
    // 0x800188D4: nop

    // 0x800188D8: jr          $ra
    // 0x800188DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800188DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800188E0:
    // 0x800188E0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800188E4: srl         $t5, $a0, 8
    ctx->r13 = S32(U32(ctx->r4) >> 8);
    // 0x800188E8: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x800188EC: andi        $t3, $t5, 0x1F
    ctx->r11 = ctx->r13 & 0X1F;
    // 0x800188F0: srl         $t9, $a0, 16
    ctx->r25 = S32(U32(ctx->r4) >> 16);
    // 0x800188F4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800188F8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800188FC: addu        $t8, $v0, $t4
    ctx->r24 = ADD32(ctx->r2, ctx->r12);
    // 0x80018900: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80018904: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x80018908: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8001890C: lhu         $t5, 0x0($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X0);
    // 0x80018910: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x80018914: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80018918: bne         $at, $zero, L_800189B4
    if (ctx->r1 != 0) {
        // 0x8001891C: nop
    
            goto L_800189B4;
    }
    // 0x8001891C: nop

    // 0x80018920: jr          $ra
    // 0x80018924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80018924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018928:
    // 0x80018928: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001892C: srl         $t3, $a0, 8
    ctx->r11 = S32(U32(ctx->r4) >> 8);
    // 0x80018930: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x80018934: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x80018938: srl         $t2, $a0, 16
    ctx->r10 = S32(U32(ctx->r4) >> 16);
    // 0x8001893C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80018940: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80018944: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x80018948: addu        $t6, $v0, $t0
    ctx->r14 = ADD32(ctx->r2, ctx->r8);
    // 0x8001894C: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80018950: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80018954: lhu         $t3, 0x0($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X0);
    // 0x80018958: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x8001895C: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80018960: beq         $at, $zero, L_800189B4
    if (ctx->r1 == 0) {
        // 0x80018964: nop
    
            goto L_800189B4;
    }
    // 0x80018964: nop

    // 0x80018968: jr          $ra
    // 0x8001896C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001896C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018970:
    // 0x80018970: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80018974: srl         $t0, $a0, 8
    ctx->r8 = S32(U32(ctx->r4) >> 8);
    // 0x80018978: addiu       $v0, $v0, 0x40A4
    ctx->r2 = ADD32(ctx->r2, 0X40A4);
    // 0x8001897C: andi        $t6, $t0, 0x1F
    ctx->r14 = ctx->r8 & 0X1F;
    // 0x80018980: srl         $t4, $a0, 16
    ctx->r12 = S32(U32(ctx->r4) >> 16);
    // 0x80018984: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80018988: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8001898C: addu        $t1, $v0, $t5
    ctx->r9 = ADD32(ctx->r2, ctx->r13);
    // 0x80018990: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x80018994: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80018998: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8001899C: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x800189A0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800189A4: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800189A8: beq         $at, $zero, L_800189B4
    if (ctx->r1 == 0) {
        // 0x800189AC: nop
    
            goto L_800189B4;
    }
    // 0x800189AC: nop

    // 0x800189B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800189B4:
    // 0x800189B4: jr          $ra
    // 0x800189B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800189B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800189bc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800189bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800189BC: srl         $v0, $a0, 8
    ctx->r2 = S32(U32(ctx->r4) >> 8);
    // 0x800189C0: jr          $ra
    // 0x800189C4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    return;
    // 0x800189C4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800189c8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800189c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800189C8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800189CC: addiu       $t1, $t1, -0x143E
    ctx->r9 = ADD32(ctx->r9, -0X143E);
    // 0x800189D0: lhu         $a0, 0x0($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X0);
    // 0x800189D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800189D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800189DC: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x800189E0: jal         0x8001B154
    // 0x800189E4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_0;
    // 0x800189E4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_0:
    // 0x800189E8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800189EC: addiu       $t1, $t1, -0x143E
    ctx->r9 = ADD32(ctx->r9, -0X143E);
    // 0x800189F0: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x800189F4: addiu       $t3, $zero, 0x26
    ctx->r11 = ADD32(0, 0X26);
    // 0x800189F8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800189FC: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018A00: addiu       $t2, $t2, -0x13E8
    ctx->r10 = ADD32(ctx->r10, -0X13E8);
    // 0x80018A04: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x80018A08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80018A0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80018A10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80018A14: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80018A18: mflo        $t7
    ctx->r15 = lo;
    // 0x80018A1C: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x80018A20: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x80018A24: blezl       $t9, L_80018AA4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80018A28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018AA4;
    }
    goto skip_0;
    // 0x80018A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80018A2C: lbu         $t4, 0x12($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X12);
L_80018A30:
    // 0x80018A30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80018A34: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80018A38: beq         $a1, $t4, L_80018A64
    if (ctx->r5 == ctx->r12) {
        // 0x80018A3C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80018A64;
    }
    // 0x80018A3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80018A40:
    // 0x80018A40: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80018A44: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80018A48: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x80018A4C: sb          $zero, 0x17($v0)
    MEM_B(0X17, ctx->r2) = 0;
    // 0x80018A50: sb          $a2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r6;
    // 0x80018A54: addu        $v0, $a0, $t5
    ctx->r2 = ADD32(ctx->r4, ctx->r13);
    // 0x80018A58: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x80018A5C: bnel        $a1, $t6, L_80018A40
    if (ctx->r5 != ctx->r14) {
        // 0x80018A60: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80018A40;
    }
    goto skip_1;
    // 0x80018A60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
L_80018A64:
    // 0x80018A64: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80018A68: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80018A6C: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x80018A70: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80018A74: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80018A78: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80018A7C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80018A80: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018A84: addiu       $a0, $a0, 0x11A
    ctx->r4 = ADD32(ctx->r4, 0X11A);
    // 0x80018A88: mflo        $t8
    ctx->r24 = lo;
    // 0x80018A8C: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80018A90: lbu         $t4, 0x4($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X4);
    // 0x80018A94: slt         $at, $a3, $t4
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80018A98: bnel        $at, $zero, L_80018A30
    if (ctx->r1 != 0) {
        // 0x80018A9C: lbu         $t4, 0x12($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X12);
            goto L_80018A30;
    }
    goto skip_2;
    // 0x80018A9C: lbu         $t4, 0x12($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X12);
    skip_2:
    // 0x80018AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018AA4:
    // 0x80018AA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80018AA8: sh          $zero, -0x40C0($at)
    MEM_H(-0X40C0, ctx->r1) = 0;
    // 0x80018AAC: jr          $ra
    // 0x80018AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80018AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80018ab4(rdram, ctx);
;}
RECOMP_FUNC void FUN_80018ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018AB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80018AB8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80018ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018AC0: addiu       $t6, $t6, 0x41A0
    ctx->r14 = ADD32(ctx->r14, 0X41A0);
    // 0x80018AC4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80018AC8: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x80018ACC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80018AD0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80018AD4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80018AD8: addiu       $t9, $t9, 0x41AC
    ctx->r25 = ADD32(ctx->r25, 0X41AC);
    // 0x80018ADC: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80018AE0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80018AE4: lhu         $t8, 0x8($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X8);
    // 0x80018AE8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80018AEC: addiu       $a2, $a2, -0x143E
    ctx->r6 = ADD32(ctx->r6, -0X143E);
    // 0x80018AF0: sh          $t8, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r24;
    // 0x80018AF4: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80018AF8: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x80018AFC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80018B00: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x80018B04: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80018B08: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80018B0C: jal         0x8001B154
    // 0x80018B10: sb          $zero, 0x37($sp)
    MEM_B(0X37, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_0;
    // 0x80018B10: sb          $zero, 0x37($sp)
    MEM_B(0X37, ctx->r29) = 0;
    after_0:
    // 0x80018B14: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80018B18: addiu       $a2, $a2, -0x143E
    ctx->r6 = ADD32(ctx->r6, -0X143E);
    // 0x80018B1C: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x80018B20: addiu       $t1, $zero, 0x26
    ctx->r9 = ADD32(0, 0X26);
    // 0x80018B24: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018B28: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018B2C: addiu       $a0, $a0, -0x13E8
    ctx->r4 = ADD32(ctx->r4, -0X13E8);
    // 0x80018B30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80018B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018B38: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x80018B3C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x80018B40: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80018B44: mflo        $t5
    ctx->r13 = lo;
    // 0x80018B48: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80018B4C: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80018B50: blezl       $t7, L_80018BCC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80018B54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018BCC;
    }
    goto skip_0;
    // 0x80018B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80018B58: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80018B5C:
    // 0x80018B5C: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80018B60: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80018B64: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80018B68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80018B6C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80018B70: swl         $t9, 0x12($v1)
    do_swl(rdram, 0X12, ctx->r3, ctx->r25);
    // 0x80018B74: swr         $t9, 0x15($v1)
    do_swr(rdram, 0X15, ctx->r3, ctx->r25);
    // 0x80018B78: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x80018B7C: addiu       $v1, $v1, 0x11A
    ctx->r3 = ADD32(ctx->r3, 0X11A);
    // 0x80018B80: swl         $t8, -0x104($v1)
    do_swl(rdram, -0X104, ctx->r3, ctx->r24);
    // 0x80018B84: swr         $t8, -0x101($v1)
    do_swr(rdram, -0X101, ctx->r3, ctx->r24);
    // 0x80018B88: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80018B8C: swl         $t3, -0x112($v1)
    do_swl(rdram, -0X112, ctx->r3, ctx->r11);
    // 0x80018B90: swr         $t3, -0x10F($v1)
    do_swr(rdram, -0X10F, ctx->r3, ctx->r11);
    // 0x80018B94: lw          $t2, 0x4($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X4);
    // 0x80018B98: swl         $t2, -0x10E($v1)
    do_swl(rdram, -0X10E, ctx->r3, ctx->r10);
    // 0x80018B9C: swr         $t2, -0x10B($v1)
    do_swr(rdram, -0X10B, ctx->r3, ctx->r10);
    // 0x80018BA0: lhu         $t3, 0x8($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X8);
    // 0x80018BA4: sh          $t3, -0x10A($v1)
    MEM_H(-0X10A, ctx->r3) = ctx->r11;
    // 0x80018BA8: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x80018BAC: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018BB0: mflo        $t5
    ctx->r13 = lo;
    // 0x80018BB4: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80018BB8: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80018BBC: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80018BC0: bnel        $at, $zero, L_80018B5C
    if (ctx->r1 != 0) {
        // 0x80018BC4: sb          $v0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r2;
            goto L_80018B5C;
    }
    goto skip_1;
    // 0x80018BC4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    skip_1:
    // 0x80018BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018BCC:
    // 0x80018BCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80018BD0: jr          $ra
    // 0x80018BD4: nop

    return;
    // 0x80018BD4: nop

;}
RECOMP_FUNC void FUN_80018bd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BD8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018BDC: lhu         $a0, -0x143E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X143E);
    // 0x80018BE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018BE8: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x80018BEC: jal         0x8001B154
    // 0x80018BF0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_0;
    // 0x80018BF0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_0:
    // 0x80018BF4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80018BF8: lhu         $t6, -0x143E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X143E);
    // 0x80018BFC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80018C00: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x80018C04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80018C08: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80018C0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018C10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018C14: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80018C18: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80018C1C: lbu         $t0, -0x13E4($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X13E4);
    // 0x80018C20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80018C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80018C28: blez        $t0, L_80018C90
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80018C2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018C90;
    }
    // 0x80018C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018C30: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80018C34:
    // 0x80018C34: lhu         $t8, 0x10($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X10);
    // 0x80018C38: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80018C3C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80018C40: beq         $t8, $zero, L_80018C4C
    if (ctx->r24 == 0) {
        // 0x80018C44: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80018C4C;
    }
    // 0x80018C44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80018C48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80018C4C:
    // 0x80018C4C: lbu         $t9, 0x12($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X12);
    // 0x80018C50: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80018C54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80018C58: beq         $a1, $t9, L_80018C88
    if (ctx->r5 == ctx->r25) {
        // 0x80018C5C: nop
    
            goto L_80018C88;
    }
    // 0x80018C5C: nop

    // 0x80018C60: lbu         $t1, 0x17($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X17);
L_80018C64:
    // 0x80018C64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80018C68: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80018C6C: beq         $t1, $zero, L_80018C78
    if (ctx->r9 == 0) {
        // 0x80018C70: sll         $t2, $v1, 3
        ctx->r10 = S32(ctx->r3 << 3);
            goto L_80018C78;
    }
    // 0x80018C70: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x80018C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80018C78:
    // 0x80018C78: addu        $v0, $a0, $t2
    ctx->r2 = ADD32(ctx->r4, ctx->r10);
    // 0x80018C7C: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x80018C80: bnel        $a1, $t3, L_80018C64
    if (ctx->r5 != ctx->r11) {
        // 0x80018C84: lbu         $t1, 0x17($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X17);
            goto L_80018C64;
    }
    goto skip_0;
    // 0x80018C84: lbu         $t1, 0x17($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X17);
    skip_0:
L_80018C88:
    // 0x80018C88: bne         $at, $zero, L_80018C34
    if (ctx->r1 != 0) {
        // 0x80018C8C: addiu       $a0, $a0, 0x11A
        ctx->r4 = ADD32(ctx->r4, 0X11A);
            goto L_80018C34;
    }
    // 0x80018C8C: addiu       $a0, $a0, 0x11A
    ctx->r4 = ADD32(ctx->r4, 0X11A);
L_80018C90:
    // 0x80018C90: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80018C94: jr          $ra
    // 0x80018C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80018C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80018c9c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80018c9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018CA0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80018CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018CA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80018CAC: addiu       $t7, $t7, 0x41B4
    ctx->r15 = ADD32(ctx->r15, 0X41B4);
    // 0x80018CB0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80018CB4: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80018CB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80018CBC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80018CC0: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x80018CC4: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80018CC8: addiu       $t5, $t5, 0x41C0
    ctx->r13 = ADD32(ctx->r13, 0X41C0);
    // 0x80018CCC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80018CD0: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x80018CD4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80018CD8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80018CDC: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80018CE0: addiu       $t4, $sp, 0x1C
    ctx->r12 = ADD32(ctx->r29, 0X1C);
    // 0x80018CE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80018CE8: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80018CEC: jal         0x8001B154
    // 0x80018CF0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_0;
    // 0x80018CF0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    after_0:
    // 0x80018CF4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80018CF8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80018CFC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80018D00: addiu       $a2, $a2, -0x1174
    ctx->r6 = ADD32(ctx->r6, -0X1174);
    // 0x80018D04: addiu       $a1, $a1, -0x1170
    ctx->r5 = ADD32(ctx->r5, -0X1170);
    // 0x80018D08: addiu       $v1, $v1, -0x1178
    ctx->r3 = ADD32(ctx->r3, -0X1178);
    // 0x80018D0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80018D10: addiu       $t9, $v0, 0x12
    ctx->r25 = ADD32(ctx->r2, 0X12);
    // 0x80018D14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80018D18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80018D1C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80018D20: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80018D24: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
    // 0x80018D28: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80018D2C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80018D30: addiu       $t1, $t1, -0x143E
    ctx->r9 = ADD32(ctx->r9, -0X143E);
    // 0x80018D34: sb          $a3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r7;
    // 0x80018D38: lhu         $t5, 0x0($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X0);
    // 0x80018D3C: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80018D40: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80018D44: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018D48: addiu       $t0, $t0, -0x13E8
    ctx->r8 = ADD32(ctx->r8, -0X13E8);
    // 0x80018D4C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80018D50: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018D54: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80018D58: addiu       $t3, $t3, -0x1418
    ctx->r11 = ADD32(ctx->r11, -0X1418);
    // 0x80018D5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80018D60: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80018D64: addiu       $v0, $v0, -0x1164
    ctx->r2 = ADD32(ctx->r2, -0X1164);
    // 0x80018D68: mflo        $t6
    ctx->r14 = lo;
    // 0x80018D6C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80018D70: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80018D74: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x80018D78: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x80018D7C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80018D80: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80018D84: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018D88: mflo        $t5
    ctx->r13 = lo;
    // 0x80018D8C: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x80018D90: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80018D94: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80018D98: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x80018D9C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80018DA0: lhu         $t9, -0x1166($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1166);
    // 0x80018DA4: sh          $t9, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r25;
    // 0x80018DA8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80018DAC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80018DB0: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80018DB4: swl         $t8, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r24);
    // 0x80018DB8: swr         $t8, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r24);
    // 0x80018DBC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80018DC0: swl         $t7, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r15);
    // 0x80018DC4: swr         $t7, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r15);
    // 0x80018DC8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80018DCC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80018DD0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80018DD4: swl         $t6, 0x0($t9)
    do_swl(rdram, 0X0, ctx->r25, ctx->r14);
    // 0x80018DD8: swr         $t6, 0x3($t9)
    do_swr(rdram, 0X3, ctx->r25, ctx->r14);
    // 0x80018DDC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80018DE0: swl         $t5, 0x4($t9)
    do_swl(rdram, 0X4, ctx->r25, ctx->r13);
    // 0x80018DE4: swr         $t5, 0x7($t9)
    do_swr(rdram, 0X7, ctx->r25, ctx->r13);
    // 0x80018DE8: lhu         $t6, 0x8($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X8);
    // 0x80018DEC: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x80018DF0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80018DF4: lhu         $t7, -0x141E($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X141E);
    // 0x80018DF8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80018DFC: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
    // 0x80018E00: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80018E04: lhu         $t9, -0x141C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X141C);
    // 0x80018E08: sh          $t9, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r25;
    // 0x80018E0C: sh          $zero, -0x1168($at)
    MEM_H(-0X1168, ctx->r1) = 0;
    // 0x80018E10: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018E14: sb          $zero, -0x116C($at)
    MEM_B(-0X116C, ctx->r1) = 0;
    // 0x80018E18: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018E1C: sb          $zero, -0x116B($at)
    MEM_B(-0X116B, ctx->r1) = 0;
    // 0x80018E20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80018E24: sb          $zero, -0x116A($at)
    MEM_B(-0X116A, ctx->r1) = 0;
    // 0x80018E28: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x80018E2C: beql        $t5, $zero, L_80018E90
    if (ctx->r13 == 0) {
        // 0x80018E30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018E90;
    }
    goto skip_0;
    // 0x80018E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80018E34: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80018E38: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80018E3C: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
    // 0x80018E40: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x80018E44: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80018E48: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80018E4C: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    // 0x80018E50: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x80018E54: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x80018E58: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x80018E5C: mflo        $t7
    ctx->r15 = lo;
    // 0x80018E60: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80018E64: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80018E68: bne         $t5, $zero, L_80018E74
    if (ctx->r13 != 0) {
        // 0x80018E6C: nop
    
            goto L_80018E74;
    }
    // 0x80018E6C: nop

    // 0x80018E70: break       7
    do_break(2147585648);
L_80018E74:
    // 0x80018E74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80018E78: bne         $t5, $at, L_80018E8C
    if (ctx->r13 != ctx->r1) {
        // 0x80018E7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80018E8C;
    }
    // 0x80018E7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80018E80: bne         $t6, $at, L_80018E8C
    if (ctx->r14 != ctx->r1) {
        // 0x80018E84: nop
    
            goto L_80018E8C;
    }
    // 0x80018E84: nop

    // 0x80018E88: break       6
    do_break(2147585672);
L_80018E8C:
    // 0x80018E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018E90:
    // 0x80018E90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80018E94: jr          $ra
    // 0x80018E98: nop

    return;
    // 0x80018E98: nop

;}
RECOMP_FUNC void FUN_80018e9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018EA0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80018EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018EAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80018EB0: addiu       $t7, $t7, 0x41C8
    ctx->r15 = ADD32(ctx->r15, 0X41C8);
    // 0x80018EB4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80018EB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80018EBC: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80018EC0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80018EC4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80018EC8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80018ECC: addiu       $s0, $s0, -0x1174
    ctx->r16 = ADD32(ctx->r16, -0X1174);
    // 0x80018ED0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80018ED4: lhu         $t0, -0x141A($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X141A);
    // 0x80018ED8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80018EDC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80018EE0: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x80018EE4: lhu         $a1, -0x1416($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X1416);
    // 0x80018EE8: jal         0x80019158
    // 0x80018EEC: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    LOOKUP_FUNC(0x80019158)(rdram, ctx);
        goto after_0;
    // 0x80018EEC: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    after_0:
    // 0x80018EF0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80018EF4: lbu         $t2, -0x116A($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X116A);
    // 0x80018EF8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80018EFC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80018F00: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80018F04: sb          $t3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r11;
    // 0x80018F08: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80018F0C: lbu         $t5, -0x116C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X116C);
    // 0x80018F10: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018F14: sb          $t5, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r13;
    // 0x80018F18: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x80018F1C: jal         0x8001BD20
    // 0x80018F20: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    LOOKUP_FUNC(0x8001BD20)(rdram, ctx);
        goto after_1;
    // 0x80018F20: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    after_1:
    // 0x80018F24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80018F28: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80018F2C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80018F30: sb          $v0, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r2;
    // 0x80018F34: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80018F38: lhu         $t8, -0x1416($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X1416);
    // 0x80018F3C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80018F40: sb          $t8, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r24;
    // 0x80018F44: lhu         $t0, -0x1418($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X1418);
    // 0x80018F48: beql        $t0, $zero, L_80018F60
    if (ctx->r8 == 0) {
        // 0x80018F4C: lw          $t3, 0x0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X0);
            goto L_80018F60;
    }
    goto skip_0;
    // 0x80018F4C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80018F50: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80018F54: b           L_80018F68
    // 0x80018F58: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
        goto L_80018F68;
    // 0x80018F58: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
    // 0x80018F5C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
L_80018F60:
    // 0x80018F60: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80018F64: sb          $t2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r10;
L_80018F68:
    // 0x80018F68: lbu         $t4, -0x116B($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X116B);
    // 0x80018F6C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80018F70: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018F74: sb          $t4, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r12;
    // 0x80018F78: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x80018F7C: jal         0x8001D394
    // 0x80018F80: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_2;
    // 0x80018F80: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    after_2:
    // 0x80018F84: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018F88: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80018F8C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80018F90: lbu         $a2, -0x1419($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1419);
    // 0x80018F94: lhu         $a1, -0x1168($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X1168);
    // 0x80018F98: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    // 0x80018F9C: jal         0x8001C0B0
    // 0x80018FA0: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_3;
    // 0x80018FA0: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_3:
    // 0x80018FA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80018FA8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80018FAC: addiu       $a1, $a1, -0x1168
    ctx->r5 = ADD32(ctx->r5, -0X1168);
    // 0x80018FB0: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80018FB4: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80018FB8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80018FBC: addiu       $v1, $v1, -0x1166
    ctx->r3 = ADD32(ctx->r3, -0X1166);
    // 0x80018FC0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80018FC4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80018FC8: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x80018FCC: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
    // 0x80018FD0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80018FD4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80018FD8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80018FDC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x80018FE0: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x80018FE4: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80018FE8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80018FEC: addiu       $a0, $a0, -0x1170
    ctx->r4 = ADD32(ctx->r4, -0X1170);
    // 0x80018FF0: swl         $t6, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r14);
    // 0x80018FF4: swr         $t6, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r14);
    // 0x80018FF8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80018FFC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80019000: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80019004: swl         $t5, 0x4($t2)
    do_swl(rdram, 0X4, ctx->r10, ctx->r13);
    // 0x80019008: swr         $t5, 0x7($t2)
    do_swr(rdram, 0X7, ctx->r10, ctx->r13);
    // 0x8001900C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80019010: lhu         $t7, -0x141E($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X141E);
    // 0x80019014: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
    // 0x80019018: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8001901C: lhu         $t9, -0x141C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X141C);
    // 0x80019020: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
    // 0x80019024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019028: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001902C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80019030: jr          $ra
    // 0x80019034: nop

    return;
    // 0x80019034: nop

;}
RECOMP_FUNC void FUN_80019038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019038: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001903C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80019040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80019044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80019048: addiu       $t7, $t7, 0x41D0
    ctx->r15 = ADD32(ctx->r15, 0X41D0);
    // 0x8001904C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80019050: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80019054: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80019058: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001905C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019060: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80019064: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80019068: addiu       $v0, $v0, -0x141A
    ctx->r2 = ADD32(ctx->r2, -0X141A);
    // 0x8001906C: addiu       $s0, $s0, -0x1174
    ctx->r16 = ADD32(ctx->r16, -0X1174);
    // 0x80019070: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80019074: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x80019078: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001907C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80019080: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x80019084: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80019088: lbu         $t2, -0x116A($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X116A);
    // 0x8001908C: ori         $a1, $zero, 0xA2A7
    ctx->r5 = 0 | 0XA2A7;
    // 0x80019090: sb          $t2, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r10;
    // 0x80019094: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80019098: lbu         $t4, -0x116C($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X116C);
    // 0x8001909C: sb          $t4, 0x3($t5)
    MEM_B(0X3, ctx->r13) = ctx->r12;
    // 0x800190A0: jal         0x8001BD20
    // 0x800190A4: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    LOOKUP_FUNC(0x8001BD20)(rdram, ctx);
        goto after_0;
    // 0x800190A4: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    after_0:
    // 0x800190A8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800190AC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800190B0: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800190B4: sb          $v0, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r2;
    // 0x800190B8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800190BC: lhu         $t7, -0x1416($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X1416);
    // 0x800190C0: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800190C4: sb          $t7, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r15;
    // 0x800190C8: lhu         $t9, -0x1418($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1418);
    // 0x800190CC: beql        $t9, $zero, L_800190E4
    if (ctx->r25 == 0) {
        // 0x800190D0: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_800190E4;
    }
    goto skip_0;
    // 0x800190D0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800190D4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800190D8: b           L_800190EC
    // 0x800190DC: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
        goto L_800190EC;
    // 0x800190DC: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x800190E0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_800190E4:
    // 0x800190E4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800190E8: sb          $t1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r9;
L_800190EC:
    // 0x800190EC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800190F0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800190F4: ori         $a1, $zero, 0xA2A7
    ctx->r5 = 0 | 0XA2A7;
    // 0x800190F8: sb          $t3, 0x7($t4)
    MEM_B(0X7, ctx->r12) = ctx->r11;
    // 0x800190FC: jal         0x8001D394
    // 0x80019100: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_1;
    // 0x80019100: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    after_1:
    // 0x80019104: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80019108: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001910C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80019110: lbu         $a2, -0x1419($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1419);
    // 0x80019114: lhu         $a1, -0x1168($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X1168);
    // 0x80019118: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    // 0x8001911C: jal         0x8001C0B0
    // 0x80019120: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_2;
    // 0x80019120: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80019124: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80019128: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001912C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80019130: swl         $t8, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r24);
    // 0x80019134: swr         $t8, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r24);
    // 0x80019138: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001913C: swl         $t7, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r15);
    // 0x80019140: swr         $t7, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r15);
    // 0x80019144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001914C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80019150: jr          $ra
    // 0x80019154: nop

    return;
    // 0x80019154: nop

;}
RECOMP_FUNC void FUN_80019158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019158: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001915C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80019160: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80019164: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80019168: addiu       $t6, $t6, 0x41D8
    ctx->r14 = ADD32(ctx->r14, 0X41D8);
    // 0x8001916C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80019170: addiu       $a2, $sp, 0x4
    ctx->r6 = ADD32(ctx->r29, 0X4);
    // 0x80019174: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80019178: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8001917C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80019180: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80019184: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80019188: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001918C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80019190: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019194: ori         $at, $zero, 0xA3E1
    ctx->r1 = 0 | 0XA3E1;
    // 0x80019198: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8001919C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800191A0: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x800191A4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x800191A8: sw          $t8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r24;
    // 0x800191AC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800191B0: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x800191B4: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800191B8: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800191BC: lhu         $t8, 0x1C($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X1C);
    // 0x800191C0: bne         $a1, $zero, L_800191D0
    if (ctx->r5 != 0) {
        // 0x800191C4: sh          $t8, 0x1C($a2)
        MEM_H(0X1C, ctx->r6) = ctx->r24;
            goto L_800191D0;
    }
    // 0x800191C4: sh          $t8, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r24;
    // 0x800191C8: b           L_800191D0
    // 0x800191CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800191D0;
    // 0x800191CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800191D0:
    // 0x800191D0: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800191D4: bne         $at, $zero, L_800191F8
    if (ctx->r1 != 0) {
        // 0x800191D8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800191F8;
    }
    // 0x800191D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800191DC: ori         $at, $zero, 0xA3FB
    ctx->r1 = 0 | 0XA3FB;
    // 0x800191E0: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800191E4: beq         $at, $zero, L_800191F8
    if (ctx->r1 == 0) {
        // 0x800191E8: addu        $t9, $a2, $v0
        ctx->r25 = ADD32(ctx->r6, ctx->r2);
            goto L_800191F8;
    }
    // 0x800191E8: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x800191EC: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x800191F0: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800191F4: lbu         $v1, 0x5C1F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5C1F);
L_800191F8:
    // 0x800191F8: ori         $at, $zero, 0xA3C1
    ctx->r1 = 0 | 0XA3C1;
    // 0x800191FC: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80019200: bne         $at, $zero, L_80019220
    if (ctx->r1 != 0) {
        // 0x80019204: ori         $at, $zero, 0xA3DB
        ctx->r1 = 0 | 0XA3DB;
            goto L_80019220;
    }
    // 0x80019204: ori         $at, $zero, 0xA3DB
    ctx->r1 = 0 | 0XA3DB;
    // 0x80019208: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001920C: beq         $at, $zero, L_80019220
    if (ctx->r1 == 0) {
        // 0x80019210: addu        $t0, $a2, $a0
        ctx->r8 = ADD32(ctx->r6, ctx->r4);
            goto L_80019220;
    }
    // 0x80019210: addu        $t0, $a2, $a0
    ctx->r8 = ADD32(ctx->r6, ctx->r4);
    // 0x80019214: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x80019218: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8001921C: lbu         $v1, 0x5C3F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5C3F);
L_80019220:
    // 0x80019220: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80019224: jr          $ra
    // 0x80019228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80019228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001922c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001922c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001922C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019230: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80019234: lhu         $t6, 0x1C8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1C8);
    // 0x80019238: lhu         $t7, 0x1E8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1E8);
    // 0x8001923C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019244: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019248: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8001924C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019250: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019254: jal         0x80018BD8
    // 0x80019258: sh          $t8, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r24;
    LOOKUP_FUNC(0x80018BD8)(rdram, ctx);
        goto after_0;
    // 0x80019258: sh          $t8, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r24;
    after_0:
    // 0x8001925C: bne         $v0, $zero, L_8001927C
    if (ctx->r2 != 0) {
        // 0x80019260: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8001927C;
    }
    // 0x80019260: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80019264: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80019268: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x8001926C: jal         0x800058DC
    // 0x80019270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80019270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80019274: b           L_800192E8
    // 0x80019278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800192E8;
    // 0x80019278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001927C:
    // 0x8001927C: lhu         $t9, -0x1440($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1440);
    // 0x80019280: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80019284: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80019288: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001928C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80019290: lw          $t1, 0x4124($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4124);
    // 0x80019294: lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4);
    // 0x80019298: andi        $t2, $v0, 0xF000
    ctx->r10 = ctx->r2 & 0XF000;
    // 0x8001929C: beq         $t2, $zero, L_800192E4
    if (ctx->r10 == 0) {
        // 0x800192A0: andi        $t3, $v0, 0xB000
        ctx->r11 = ctx->r2 & 0XB000;
            goto L_800192E4;
    }
    // 0x800192A0: andi        $t3, $v0, 0xB000
    ctx->r11 = ctx->r2 & 0XB000;
    // 0x800192A4: beq         $t3, $zero, L_800192B8
    if (ctx->r11 == 0) {
        // 0x800192A8: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800192B8;
    }
    // 0x800192A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800192AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800192B0: b           L_800192C0
    // 0x800192B4: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
        goto L_800192C0;
    // 0x800192B4: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
L_800192B8:
    // 0x800192B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800192BC: sh          $t4, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = ctx->r12;
L_800192C0:
    // 0x800192C0: lhu         $t5, -0x1434($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X1434);
    // 0x800192C4: bnel        $t5, $zero, L_800192E8
    if (ctx->r13 != 0) {
        // 0x800192C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800192E8;
    }
    goto skip_0;
    // 0x800192C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800192CC: jal         0x800189C8
    // 0x800192D0: nop

    LOOKUP_FUNC(0x800189C8)(rdram, ctx);
        goto after_2;
    // 0x800192D0: nop

    after_2:
    // 0x800192D4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x800192D8: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x800192DC: jal         0x800058DC
    // 0x800192E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x800192E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_800192E4:
    // 0x800192E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800192E8:
    // 0x800192E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800192EC: jr          $ra
    // 0x800192F0: nop

    return;
    // 0x800192F0: nop

;}
RECOMP_FUNC void FUN_800192f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800192F4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800192F8: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x800192FC: lhu         $t6, 0x1C8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1C8);
    // 0x80019300: lhu         $t7, 0x1E8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1E8);
    // 0x80019304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001930C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019310: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80019314: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001931C: jal         0x80018BD8
    // 0x80019320: sh          $t8, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r24;
    LOOKUP_FUNC(0x80018BD8)(rdram, ctx);
        goto after_0;
    // 0x80019320: sh          $t8, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r24;
    after_0:
    // 0x80019324: beq         $v0, $zero, L_80019340
    if (ctx->r2 == 0) {
        // 0x80019328: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_80019340;
    }
    // 0x80019328: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001932C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80019330: addiu       $v1, $v1, -0x117E
    ctx->r3 = ADD32(ctx->r3, -0X117E);
    // 0x80019334: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80019338: b           L_80019350
    // 0x8001933C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80019350;
    // 0x8001933C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80019340:
    // 0x80019340: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80019344: addiu       $v1, $v1, -0x117E
    ctx->r3 = ADD32(ctx->r3, -0X117E);
    // 0x80019348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001934C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80019350:
    // 0x80019350: lhu         $t9, -0x1440($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1440);
    // 0x80019354: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80019358: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001935C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80019360: lw          $t1, 0x4124($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4124);
    // 0x80019364: lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4);
    // 0x80019368: andi        $t2, $v0, 0xF000
    ctx->r10 = ctx->r2 & 0XF000;
    // 0x8001936C: beq         $t2, $zero, L_800193D0
    if (ctx->r10 == 0) {
        // 0x80019370: andi        $t3, $v0, 0xB000
        ctx->r11 = ctx->r2 & 0XB000;
            goto L_800193D0;
    }
    // 0x80019370: andi        $t3, $v0, 0xB000
    ctx->r11 = ctx->r2 & 0XB000;
    // 0x80019374: beq         $t3, $zero, L_80019388
    if (ctx->r11 == 0) {
        // 0x80019378: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80019388;
    }
    // 0x80019378: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001937C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019380: b           L_8001938C
    // 0x80019384: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
        goto L_8001938C;
    // 0x80019384: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
L_80019388:
    // 0x80019388: sh          $a2, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = ctx->r6;
L_8001938C:
    // 0x8001938C: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80019390: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80019394: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019398: bne         $t4, $zero, L_800193C0
    if (ctx->r12 != 0) {
        // 0x8001939C: addiu       $a1, $a1, -0x6C20
        ctx->r5 = ADD32(ctx->r5, -0X6C20);
            goto L_800193C0;
    }
    // 0x8001939C: addiu       $a1, $a1, -0x6C20
    ctx->r5 = ADD32(ctx->r5, -0X6C20);
    // 0x800193A0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800193A4: lhu         $t5, -0x1434($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X1434);
    // 0x800193A8: bnel        $t5, $zero, L_800193D4
    if (ctx->r13 != 0) {
        // 0x800193AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800193D4;
    }
    goto skip_0;
    // 0x800193AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800193B0: jal         0x800189C8
    // 0x800193B4: nop

    LOOKUP_FUNC(0x800189C8)(rdram, ctx);
        goto after_1;
    // 0x800193B4: nop

    after_1:
    // 0x800193B8: b           L_800193D4
    // 0x800193BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800193D4;
    // 0x800193BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800193C0:
    // 0x800193C0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800193C4: sb          $a2, -0x117D($at)
    MEM_B(-0X117D, ctx->r1) = ctx->r6;
    // 0x800193C8: jal         0x800058DC
    // 0x800193CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x800193CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_800193D0:
    // 0x800193D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800193D4:
    // 0x800193D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800193D8: jr          $ra
    // 0x800193DC: nop

    return;
    // 0x800193DC: nop

;}
RECOMP_FUNC void FUN_800193e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800193E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800193E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800193E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800193EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800193F0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x800193F4: sb          $zero, -0x117D($at)
    MEM_B(-0X117D, ctx->r1) = 0;
    // 0x800193F8: jal         0x800058DC
    // 0x800193FC: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x800193FC: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    after_0:
    // 0x80019400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019408: jr          $ra
    // 0x8001940C: nop

    return;
    // 0x8001940C: nop

;}
RECOMP_FUNC void FUN_80019410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001941C: jal         0x80018BD8
    // 0x80019420: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80018BD8)(rdram, ctx);
        goto after_0;
    // 0x80019420: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80019424: bnel        $v0, $zero, L_80019454
    if (ctx->r2 != 0) {
        // 0x80019428: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80019454;
    }
    goto skip_0;
    // 0x80019428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001942C: jal         0x80018AB4
    // 0x80019430: nop

    LOOKUP_FUNC(0x80018AB4)(rdram, ctx);
        goto after_1;
    // 0x80019430: nop

    after_1:
    // 0x80019434: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80019438: jal         0x80018C9C
    // 0x8001943C: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    LOOKUP_FUNC(0x80018C9C)(rdram, ctx);
        goto after_2;
    // 0x8001943C: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    after_2:
    // 0x80019440: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80019444: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x80019448: jal         0x800058DC
    // 0x8001944C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8001944C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80019450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019454:
    // 0x80019454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019458: jr          $ra
    // 0x8001945C: nop

    return;
    // 0x8001945C: nop

;}
RECOMP_FUNC void FUN_80019460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019460: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80019464: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80019468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001946C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80019470: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80019474: addiu       $t7, $t7, 0x41F8
    ctx->r15 = ADD32(ctx->r15, 0X41F8);
    // 0x80019478: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001947C: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x80019480: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80019484: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80019488: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x8001948C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80019490: addiu       $t4, $t4, 0x4204
    ctx->r12 = ADD32(ctx->r12, 0X4204);
    // 0x80019494: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80019498: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x8001949C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800194A0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800194A4: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x800194A8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800194AC: addiu       $t7, $t7, 0x420C
    ctx->r15 = ADD32(ctx->r15, 0X420C);
    // 0x800194B0: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800194B4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800194B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800194BC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800194C0: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x800194C4: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x800194C8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800194CC: lbu         $t9, 0x4($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X4);
    // 0x800194D0: lhu         $t3, 0x1C8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X1C8);
    // 0x800194D4: lhu         $t4, 0x1E8($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X1E8);
    // 0x800194D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800194DC: sb          $t9, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r25;
    // 0x800194E0: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800194E4: jal         0x80018BD8
    // 0x800194E8: sh          $t5, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x80018BD8)(rdram, ctx);
        goto after_0;
    // 0x800194E8: sh          $t5, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r13;
    after_0:
    // 0x800194EC: bne         $v0, $zero, L_800196F0
    if (ctx->r2 != 0) {
        // 0x800194F0: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_800196F0;
    }
    // 0x800194F0: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800194F4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800194F8: lhu         $a0, -0x143E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X143E);
    // 0x800194FC: sb          $zero, 0x47($sp)
    MEM_B(0X47, ctx->r29) = 0;
    // 0x80019500: jal         0x8001B154
    // 0x80019504: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_1;
    // 0x80019504: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_1:
    // 0x80019508: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8001950C: lhu         $a3, -0x143E($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X143E);
    // 0x80019510: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80019514: addiu       $t7, $t7, -0x13E8
    ctx->r15 = ADD32(ctx->r15, -0X13E8);
    // 0x80019518: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8001951C: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x80019520: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019524: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80019528: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001952C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80019530: lbu         $a2, 0x4($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X4);
    // 0x80019534: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    // 0x80019538: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x8001953C: blez        $a2, L_800195D4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80019540: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800195D4;
    }
    // 0x80019540: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80019544: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019548: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001954C: addiu       $t0, $t0, -0x141A
    ctx->r8 = ADD32(ctx->r8, -0X141A);
    // 0x80019550: addiu       $t1, $t1, -0x141E
    ctx->r9 = ADD32(ctx->r9, -0X141E);
    // 0x80019554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80019558:
    // 0x80019558: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x8001955C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80019560: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80019564: beql        $t8, $zero, L_800195C8
    if (ctx->r24 == 0) {
        // 0x80019568: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800195C8;
    }
    goto skip_0;
    // 0x80019568: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x8001956C: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80019570: lh          $t3, 0x2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2);
    // 0x80019574: bnel        $t9, $t3, L_800195C8
    if (ctx->r25 != ctx->r11) {
        // 0x80019578: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800195C8;
    }
    goto skip_1;
    // 0x80019578: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_1:
    // 0x8001957C: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    // 0x80019580: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x80019584: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80019588: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8001958C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80019590: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80019594: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80019598: addiu       $t3, $t3, -0x13E8
    ctx->r11 = ADD32(ctx->r11, -0X13E8);
    // 0x8001959C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800195A0: sb          $t8, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r24;
    // 0x800195A4: lhu         $a3, -0x143E($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X143E);
    // 0x800195A8: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800195AC: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x800195B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800195B4: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x800195B8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800195BC: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
    // 0x800195C0: lbu         $a2, 0x4($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X4);
    // 0x800195C4: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_800195C8:
    // 0x800195C8: bne         $at, $zero, L_80019558
    if (ctx->r1 != 0) {
        // 0x800195CC: addiu       $v1, $v1, 0x11A
        ctx->r3 = ADD32(ctx->r3, 0X11A);
            goto L_80019558;
    }
    // 0x800195CC: addiu       $v1, $v1, 0x11A
    ctx->r3 = ADD32(ctx->r3, 0X11A);
    // 0x800195D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800195D4:
    // 0x800195D4: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800195D8: jal         0x8001B154
    // 0x800195DC: sb          $a1, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_2;
    // 0x800195DC: sb          $a1, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r5;
    after_2:
    // 0x800195E0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800195E4: lhu         $t4, -0x143E($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X143E);
    // 0x800195E8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800195EC: addiu       $t6, $t6, -0x13E8
    ctx->r14 = ADD32(ctx->r14, -0X13E8);
    // 0x800195F0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800195F4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800195F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800195FC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80019600: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80019604: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80019608: lbu         $a2, 0x4($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X4);
    // 0x8001960C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80019610: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019614: addiu       $t1, $t1, -0x141E
    ctx->r9 = ADD32(ctx->r9, -0X141E);
    // 0x80019618: addiu       $t0, $t0, -0x141A
    ctx->r8 = ADD32(ctx->r8, -0X141A);
    // 0x8001961C: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    // 0x80019620: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x80019624: blez        $a2, L_800196B4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80019628: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800196B4;
    }
    // 0x80019628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001962C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80019630:
    // 0x80019630: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80019634: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80019638: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001963C: beql        $t7, $zero, L_800196AC
    if (ctx->r15 == 0) {
        // 0x80019640: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800196AC;
    }
    goto skip_2;
    // 0x80019640: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_2:
    // 0x80019644: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80019648: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x8001964C: beql        $v0, $t8, L_800196AC
    if (ctx->r2 == ctx->r24) {
        // 0x80019650: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800196AC;
    }
    goto skip_3;
    // 0x80019650: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_3:
    // 0x80019654: sb          $a3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r7;
    // 0x80019658: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x8001965C: lhu         $t5, 0x0($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X0);
    // 0x80019660: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80019664: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80019668: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001966C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80019670: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80019674: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x80019678: sb          $t6, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r14;
    // 0x8001967C: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80019680: lhu         $t9, -0x143E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X143E);
    // 0x80019684: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80019688: addiu       $t4, $t4, -0x13E8
    ctx->r12 = ADD32(ctx->r12, -0X13E8);
    // 0x8001968C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80019690: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x80019694: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80019698: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8001969C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800196A0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800196A4: lbu         $a2, 0x4($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X4);
    // 0x800196A8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_800196AC:
    // 0x800196AC: bne         $at, $zero, L_80019630
    if (ctx->r1 != 0) {
        // 0x800196B0: addiu       $v1, $v1, 0x11A
        ctx->r3 = ADD32(ctx->r3, 0X11A);
            goto L_80019630;
    }
    // 0x800196B0: addiu       $v1, $v1, 0x11A
    ctx->r3 = ADD32(ctx->r3, 0X11A);
L_800196B4:
    // 0x800196B4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800196B8: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x800196BC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800196C0: lw          $t5, -0x1174($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X1174);
    // 0x800196C4: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x800196C8: addiu       $a1, $a1, -0x68A8
    ctx->r5 = ADD32(ctx->r5, -0X68A8);
    // 0x800196CC: swl         $t8, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r24);
    // 0x800196D0: swr         $t8, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r24);
    // 0x800196D4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800196D8: swl         $t7, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r15);
    // 0x800196DC: swr         $t7, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r15);
    // 0x800196E0: jal         0x800058DC
    // 0x800196E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x800196E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x800196E8: b           L_8001974C
    // 0x800196EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001974C;
    // 0x800196EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800196F0:
    // 0x800196F0: lhu         $t9, -0x1440($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1440);
    // 0x800196F4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800196F8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800196FC: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80019700: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80019704: lw          $t4, 0x4124($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4124);
    // 0x80019708: lhu         $v0, 0x4($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X4);
    // 0x8001970C: andi        $t5, $v0, 0xF000
    ctx->r13 = ctx->r2 & 0XF000;
    // 0x80019710: beq         $t5, $zero, L_80019748
    if (ctx->r13 == 0) {
        // 0x80019714: andi        $t6, $v0, 0xB000
        ctx->r14 = ctx->r2 & 0XB000;
            goto L_80019748;
    }
    // 0x80019714: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x80019718: beq         $t6, $zero, L_8001972C
    if (ctx->r14 == 0) {
        // 0x8001971C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001972C;
    }
    // 0x8001971C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019720: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019724: b           L_80019734
    // 0x80019728: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
        goto L_80019734;
    // 0x80019728: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
L_8001972C:
    // 0x8001972C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019730: sh          $v0, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = ctx->r2;
L_80019734:
    // 0x80019734: lhu         $t7, -0x1434($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X1434);
    // 0x80019738: bnel        $t7, $zero, L_8001974C
    if (ctx->r15 != 0) {
        // 0x8001973C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001974C;
    }
    goto skip_4;
    // 0x8001973C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80019740: jal         0x800189C8
    // 0x80019744: nop

    LOOKUP_FUNC(0x800189C8)(rdram, ctx);
        goto after_4;
    // 0x80019744: nop

    after_4:
L_80019748:
    // 0x80019748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001974C:
    // 0x8001974C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80019750: jr          $ra
    // 0x80019754: nop

    return;
    // 0x80019754: nop

;}
RECOMP_FUNC void FUN_80019758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019758: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001975C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80019760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019764: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80019768: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8001976C: addiu       $t7, $t7, 0x4214
    ctx->r15 = ADD32(ctx->r15, 0X4214);
    // 0x80019770: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80019774: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x80019778: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001977C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80019780: lbu         $t9, 0x4($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X4);
    // 0x80019784: sb          $t9, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r25;
    // 0x80019788: lhu         $a0, -0x143E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X143E);
    // 0x8001978C: sb          $zero, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = 0;
    // 0x80019790: jal         0x8001B154
    // 0x80019794: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x8001B154)(rdram, ctx);
        goto after_0;
    // 0x80019794: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_0:
    // 0x80019798: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001979C: lhu         $t0, -0x143E($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X143E);
    // 0x800197A0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800197A4: addiu       $t2, $t2, -0x13E8
    ctx->r10 = ADD32(ctx->r10, -0X13E8);
    // 0x800197A8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800197AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800197B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800197B4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800197B8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800197BC: addu        $a3, $t1, $t2
    ctx->r7 = ADD32(ctx->r9, ctx->r10);
    // 0x800197C0: lbu         $a0, 0x4($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X4);
    // 0x800197C4: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    // 0x800197C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800197CC: blez        $a0, L_80019800
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800197D0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019800;
    }
    // 0x800197D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800197D4:
    // 0x800197D4: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x800197D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800197DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800197E0: beq         $t3, $zero, L_800197F8
    if (ctx->r11 == 0) {
        // 0x800197E4: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800197F8;
    }
    // 0x800197E4: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800197E8: lbu         $t4, 0xB($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XB);
    // 0x800197EC: beq         $t4, $zero, L_800197F8
    if (ctx->r12 == 0) {
        // 0x800197F0: nop
    
            goto L_800197F8;
    }
    // 0x800197F0: nop

    // 0x800197F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800197F8:
    // 0x800197F8: bne         $at, $zero, L_800197D4
    if (ctx->r1 != 0) {
        // 0x800197FC: addiu       $v1, $v1, 0x11A
        ctx->r3 = ADD32(ctx->r3, 0X11A);
            goto L_800197D4;
    }
    // 0x800197FC: addiu       $v1, $v1, 0x11A
    ctx->r3 = ADD32(ctx->r3, 0X11A);
L_80019800:
    // 0x80019800: bne         $a2, $zero, L_80019888
    if (ctx->r6 != 0) {
        // 0x80019804: lui         $a2, 0x8009
        ctx->r6 = S32(0X8009 << 16);
            goto L_80019888;
    }
    // 0x80019804: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80019808: addiu       $a2, $a2, -0x117F
    ctx->r6 = ADD32(ctx->r6, -0X117F);
    // 0x8001980C: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80019810: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80019814: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x80019818: subu        $t5, $v1, $v0
    ctx->r13 = SUB32(ctx->r3, ctx->r2);
    // 0x8001981C: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80019820: beq         $at, $zero, L_80019830
    if (ctx->r1 == 0) {
        // 0x80019824: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_80019830;
    }
    // 0x80019824: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80019828: b           L_80019834
    // 0x8001982C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
        goto L_80019834;
    // 0x8001982C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
L_80019830:
    // 0x80019830: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80019834:
    // 0x80019834: lbu         $v0, 0xA($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XA);
    // 0x80019838: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001983C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019840: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80019844: beq         $at, $zero, L_80019870
    if (ctx->r1 == 0) {
        // 0x80019848: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_80019870;
    }
    // 0x80019848: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8001984C: lhu         $t1, -0x141A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X141A);
    // 0x80019850: lh          $t7, 0x8($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X8);
    // 0x80019854: lhu         $t8, -0x141E($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X141E);
    // 0x80019858: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x8001985C: lbu         $t2, 0x34($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X34);
    // 0x80019860: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80019864: sb          $t4, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r12;
    // 0x80019868: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8001986C: sh          $t3, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r11;
L_80019870:
    // 0x80019870: jal         0x80018C9C
    // 0x80019874: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    LOOKUP_FUNC(0x80018C9C)(rdram, ctx);
        goto after_1;
    // 0x80019874: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    after_1:
    // 0x80019878: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8001987C: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x80019880: jal         0x800058DC
    // 0x80019884: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80019884: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
L_80019888:
    // 0x80019888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001988C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80019890: jr          $ra
    // 0x80019894: nop

    return;
    // 0x80019894: nop

;}
RECOMP_FUNC void FUN_80019898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019898: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001989C: addiu       $t0, $t0, -0x143E
    ctx->r8 = ADD32(ctx->r8, -0X143E);
    // 0x800198A0: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x800198A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800198A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800198AC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800198B0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800198B4: beq         $at, $zero, L_800198D0
    if (ctx->r1 == 0) {
        // 0x800198B8: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_800198D0;
    }
    // 0x800198B8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800198BC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800198C0: jal         0x80018C9C
    // 0x800198C4: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    LOOKUP_FUNC(0x80018C9C)(rdram, ctx);
        goto after_0;
    // 0x800198C4: lbu         $a0, -0x117F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X117F);
    after_0:
    // 0x800198C8: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800198CC: addiu       $t0, $t0, -0x143E
    ctx->r8 = ADD32(ctx->r8, -0X143E);
L_800198D0:
    // 0x800198D0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800198D4: lhu         $t7, -0x1430($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X1430);
    // 0x800198D8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x800198DC: beq         $at, $zero, L_80019AFC
    if (ctx->r1 == 0) {
        // 0x800198E0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80019AFC;
    }
    // 0x800198E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800198E4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800198E8: addu        $at, $at, $t7
    gpr jr_addend_800198F0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800198EC: lw          $t7, -0x322C($at)
    ctx->r15 = ADD32(ctx->r1, -0X322C);
    // 0x800198F0: jr          $t7
    // 0x800198F4: nop

    switch (jr_addend_800198F0 >> 2) {
        case 0: goto L_800198F8; break;
        case 1: goto L_80019940; break;
        case 2: goto L_80019984; break;
        case 3: goto L_800199D0; break;
        case 4: goto L_80019A20; break;
        case 5: goto L_80019A70; break;
        case 6: goto L_80019AB8; break;
        default: switch_error(__func__, 0x800198F0, 0x8004CDD4);
    }
    // 0x800198F4: nop

L_800198F8:
    // 0x800198F8: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x800198FC: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80019900: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019904: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019908: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x8001990C: addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // 0x80019910: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80019914: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80019918: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001991C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80019920: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
    // 0x80019924: sb          $zero, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = 0;
    // 0x80019928: mflo        $t9
    ctx->r25 = lo;
    // 0x8001992C: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x80019930: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x80019934: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
    // 0x80019938: b           L_80019B1C
    // 0x8001993C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019B1C;
    // 0x8001993C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019940:
    // 0x80019940: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x80019944: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80019948: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001994C: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019950: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x80019954: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80019958: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8001995C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80019960: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80019964: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
    // 0x80019968: sb          $zero, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = 0;
    // 0x8001996C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80019970: mflo        $t7
    ctx->r15 = lo;
    // 0x80019974: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x80019978: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x8001997C: b           L_80019B1C
    // 0x80019980: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
        goto L_80019B1C;
    // 0x80019980: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
L_80019984:
    // 0x80019984: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x80019988: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x8001998C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019990: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019994: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x80019998: addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // 0x8001999C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800199A0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800199A4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800199A8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x800199AC: sb          $t8, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = ctx->r24;
    // 0x800199B0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800199B4: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
    // 0x800199B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800199BC: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x800199C0: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x800199C4: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
    // 0x800199C8: b           L_80019B1C
    // 0x800199CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019B1C;
    // 0x800199CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800199D0:
    // 0x800199D0: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x800199D4: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x800199D8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800199DC: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800199E0: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x800199E4: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x800199E8: sb          $t7, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r15;
    // 0x800199EC: addiu       $t8, $zero, 0xC0
    ctx->r24 = ADD32(0, 0XC0);
    // 0x800199F0: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800199F4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800199F8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800199FC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80019A00: sb          $t8, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = ctx->r24;
    // 0x80019A04: mflo        $t6
    ctx->r14 = lo;
    // 0x80019A08: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x80019A0C: addiu       $ra, $zero, 0xC0
    ctx->r31 = ADD32(0, 0XC0);
    // 0x80019A10: sb          $t7, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r15;
    // 0x80019A14: sb          $t8, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r24;
    // 0x80019A18: b           L_80019B1C
    // 0x80019A1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019B1C;
    // 0x80019A1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019A20:
    // 0x80019A20: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80019A24: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80019A28: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019A2C: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019A30: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x80019A34: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x80019A38: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x80019A3C: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x80019A40: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80019A44: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80019A48: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x80019A4C: sb          $t6, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = ctx->r14;
    // 0x80019A50: sb          $t9, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r25;
    // 0x80019A54: mflo        $t8
    ctx->r24 = lo;
    // 0x80019A58: addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
    // 0x80019A5C: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x80019A60: addiu       $ra, $zero, 0xC0
    ctx->r31 = ADD32(0, 0XC0);
    // 0x80019A64: sb          $t9, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r25;
    // 0x80019A68: b           L_80019B1C
    // 0x80019A6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019B1C;
    // 0x80019A6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019A70:
    // 0x80019A70: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x80019A74: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80019A78: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019A7C: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019A80: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x80019A84: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x80019A88: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80019A8C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80019A90: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80019A94: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80019A98: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
    // 0x80019A9C: sb          $zero, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = 0;
    // 0x80019AA0: mflo        $t7
    ctx->r15 = lo;
    // 0x80019AA4: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x80019AA8: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x80019AAC: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
    // 0x80019AB0: b           L_80019B1C
    // 0x80019AB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019B1C;
    // 0x80019AB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019AB8:
    // 0x80019AB8: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x80019ABC: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80019AC0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019AC4: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019AC8: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x80019ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80019AD0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80019AD4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80019AD8: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80019ADC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80019AE0: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
    // 0x80019AE4: sb          $zero, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = 0;
    // 0x80019AE8: mflo        $t9
    ctx->r25 = lo;
    // 0x80019AEC: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x80019AF0: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x80019AF4: b           L_80019B1C
    // 0x80019AF8: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
        goto L_80019B1C;
    // 0x80019AF8: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
L_80019AFC:
    // 0x80019AFC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80019B00: addiu       $t1, $t1, -0x13E8
    ctx->r9 = ADD32(ctx->r9, -0X13E8);
    // 0x80019B04: lbu         $ra, 0x4C($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X4C);
    // 0x80019B08: lbu         $t5, 0x4D($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4D);
    // 0x80019B0C: lbu         $t4, 0x4E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4E);
    // 0x80019B10: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x80019B14: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80019B18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019B1C:
    // 0x80019B1C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019B20: lhu         $v0, -0x1432($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1432);
    // 0x80019B24: beq         $v0, $zero, L_80019B3C
    if (ctx->r2 == 0) {
        // 0x80019B28: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80019B3C;
    }
    // 0x80019B28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019B2C: beql        $v0, $at, L_80019B74
    if (ctx->r2 == ctx->r1) {
        // 0x80019B30: lhu         $t7, 0x0($t0)
        ctx->r15 = MEM_HU(ctx->r8, 0X0);
            goto L_80019B74;
    }
    goto skip_0;
    // 0x80019B30: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    skip_0:
    // 0x80019B34: b           L_80019B9C
    // 0x80019B38: nop

        goto L_80019B9C;
    // 0x80019B38: nop

L_80019B3C:
    // 0x80019B3C: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x80019B40: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80019B44: lhu         $t8, -0x1428($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X1428);
    // 0x80019B48: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019B4C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80019B50: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80019B54: mflo        $t7
    ctx->r15 = lo;
    // 0x80019B58: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x80019B5C: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x80019B60: lhu         $t9, -0x1426($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1426);
    // 0x80019B64: sh          $t6, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r14;
    // 0x80019B68: b           L_80019B9C
    // 0x80019B6C: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
        goto L_80019B9C;
    // 0x80019B6C: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x80019B70: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
L_80019B74:
    // 0x80019B74: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80019B78: lhu         $t9, -0x1428($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X1428);
    // 0x80019B7C: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019B80: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80019B84: mflo        $t8
    ctx->r24 = lo;
    // 0x80019B88: addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
    // 0x80019B8C: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x80019B90: lhu         $t6, -0x1426($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X1426);
    // 0x80019B94: sh          $v1, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r3;
    // 0x80019B98: sh          $t6, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r14;
L_80019B9C:
    // 0x80019B9C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019BA0: lhu         $v0, -0x142E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X142E);
    // 0x80019BA4: beq         $v0, $zero, L_80019BBC
    if (ctx->r2 == 0) {
        // 0x80019BA8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80019BBC;
    }
    // 0x80019BA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019BAC: beql        $v0, $at, L_80019C28
    if (ctx->r2 == ctx->r1) {
        // 0x80019BB0: lhu         $v1, 0x0($t0)
        ctx->r3 = MEM_HU(ctx->r8, 0X0);
            goto L_80019C28;
    }
    goto skip_1;
    // 0x80019BB0: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    skip_1:
    // 0x80019BB4: b           L_80019C94
    // 0x80019BB8: nop

        goto L_80019C94;
    // 0x80019BB8: nop

L_80019BBC:
    // 0x80019BBC: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x80019BC0: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019BC4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80019BC8: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019BCC: addiu       $a1, $a1, -0x336C
    ctx->r5 = ADD32(ctx->r5, -0X336C);
    // 0x80019BD0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80019BD4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80019BD8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80019BDC: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80019BE0: mflo        $t7
    ctx->r15 = lo;
    // 0x80019BE4: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x80019BE8: lhu         $t8, 0x12($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X12);
    // 0x80019BEC: lhu         $t9, 0x14($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X14);
    // 0x80019BF0: lhu         $t6, 0x16($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X16);
    // 0x80019BF4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80019BF8: lbu         $t8, 0x4A($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4A);
    // 0x80019BFC: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x80019C00: lh          $a2, 0xC($v0)
    ctx->r6 = MEM_H(ctx->r2, 0XC);
    // 0x80019C04: lh          $a3, 0xE($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XE);
    // 0x80019C08: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80019C0C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80019C10: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80019C14: jal         0x8001A804
    // 0x80019C18: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x80019C18: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_1:
    // 0x80019C1C: b           L_80019C94
    // 0x80019C20: nop

        goto L_80019C94;
    // 0x80019C20: nop

    // 0x80019C24: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
L_80019C28:
    // 0x80019C28: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019C2C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80019C30: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019C34: addiu       $a1, $a1, -0x3348
    ctx->r5 = ADD32(ctx->r5, -0X3348);
    // 0x80019C38: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80019C3C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80019C40: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80019C44: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80019C48: mflo        $t9
    ctx->r25 = lo;
    // 0x80019C4C: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x80019C50: lhu         $t6, 0x12($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X12);
    // 0x80019C54: lhu         $t7, 0x14($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X14);
    // 0x80019C58: lhu         $t8, 0x16($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X16);
    // 0x80019C5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80019C60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80019C64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80019C68: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x80019C6C: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x80019C70: lbu         $t6, 0x4A($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4A);
    // 0x80019C74: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80019C78: lh          $a2, 0xC($v0)
    ctx->r6 = MEM_H(ctx->r2, 0XC);
    // 0x80019C7C: lh          $a3, 0xE($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XE);
    // 0x80019C80: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80019C84: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80019C88: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80019C8C: jal         0x8001A804
    // 0x80019C90: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80019C90: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_2:
L_80019C94:
    // 0x80019C94: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80019C98: addiu       $a1, $a1, -0x634C
    ctx->r5 = ADD32(ctx->r5, -0X634C);
    // 0x80019C9C: jal         0x800058DC
    // 0x80019CA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80019CA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x80019CA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80019CA8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80019CAC: jr          $ra
    // 0x80019CB0: nop

    return;
    // 0x80019CB0: nop

;}
RECOMP_FUNC void FUN_80019cb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019CB4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019CB8: lhu         $v0, -0x142E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X142E);
    // 0x80019CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019CC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019CC8: beq         $v0, $zero, L_80019CE4
    if (ctx->r2 == 0) {
        // 0x80019CCC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80019CE4;
    }
    // 0x80019CCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019CD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019CD4: beq         $v0, $at, L_80019DF0
    if (ctx->r2 == ctx->r1) {
        // 0x80019CD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80019DF0;
    }
    // 0x80019CD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80019CDC: b           L_80019E00
    // 0x80019CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80019E00;
    // 0x80019CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019CE4:
    // 0x80019CE4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80019CE8: lhu         $t0, -0x143E($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X143E);
    // 0x80019CEC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80019CF0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80019CF4: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80019CF8: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80019CFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019D00: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x80019D04: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80019D08: addiu       $t7, $t7, -0x13E8
    ctx->r15 = ADD32(ctx->r15, -0X13E8);
    // 0x80019D0C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80019D10: lbu         $a2, 0x10($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X10);
    // 0x80019D14: lbu         $a3, 0x11($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X11);
    // 0x80019D18: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x80019D1C: sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6 << 4);
    // 0x80019D20: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x80019D24: sll         $a0, $a3, 4
    ctx->r4 = S32(ctx->r7 << 4);
    // 0x80019D28: mflo        $t9
    ctx->r25 = lo;
    // 0x80019D2C: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80019D30: bne         $a1, $zero, L_80019D3C
    if (ctx->r5 != 0) {
        // 0x80019D34: nop
    
            goto L_80019D3C;
    }
    // 0x80019D34: nop

    // 0x80019D38: break       7
    do_break(2147589432);
L_80019D3C:
    // 0x80019D3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80019D40: bne         $a1, $at, L_80019D54
    if (ctx->r5 != ctx->r1) {
        // 0x80019D44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80019D54;
    }
    // 0x80019D44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019D48: bne         $v1, $at, L_80019D54
    if (ctx->r3 != ctx->r1) {
        // 0x80019D4C: nop
    
            goto L_80019D54;
    }
    // 0x80019D4C: nop

    // 0x80019D50: break       6
    do_break(2147589456);
L_80019D54:
    // 0x80019D54: div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // 0x80019D58: sh          $t2, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r10;
    // 0x80019D5C: lh          $t3, 0x1E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1E);
    // 0x80019D60: bne         $a1, $zero, L_80019D6C
    if (ctx->r5 != 0) {
        // 0x80019D64: nop
    
            goto L_80019D6C;
    }
    // 0x80019D64: nop

    // 0x80019D68: break       7
    do_break(2147589480);
L_80019D6C:
    // 0x80019D6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80019D70: bne         $a1, $at, L_80019D84
    if (ctx->r5 != ctx->r1) {
        // 0x80019D74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80019D84;
    }
    // 0x80019D74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019D78: bne         $a0, $at, L_80019D84
    if (ctx->r4 != ctx->r1) {
        // 0x80019D7C: nop
    
            goto L_80019D84;
    }
    // 0x80019D7C: nop

    // 0x80019D80: break       6
    do_break(2147589504);
L_80019D84:
    // 0x80019D84: lh          $t1, 0x1C($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1C);
    // 0x80019D88: mflo        $t4
    ctx->r12 = lo;
    // 0x80019D8C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80019D90: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80019D94: beq         $at, $zero, L_80019DB4
    if (ctx->r1 == 0) {
        // 0x80019D98: sh          $t5, 0x1E($v0)
        MEM_H(0X1E, ctx->r2) = ctx->r13;
            goto L_80019DB4;
    }
    // 0x80019D98: sh          $t5, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r13;
    // 0x80019D9C: lh          $v1, 0x1E($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1E);
    // 0x80019DA0: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019DA4: addiu       $a1, $a1, -0x3318
    ctx->r5 = ADD32(ctx->r5, -0X3318);
    // 0x80019DA8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019DAC: bne         $at, $zero, L_80019DDC
    if (ctx->r1 != 0) {
        // 0x80019DB0: andi        $a0, $t0, 0xFF
        ctx->r4 = ctx->r8 & 0XFF;
            goto L_80019DDC;
    }
    // 0x80019DB0: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
L_80019DB4:
    // 0x80019DB4: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019DB8: addiu       $a1, $a1, -0x3320
    ctx->r5 = ADD32(ctx->r5, -0X3320);
    // 0x80019DBC: jal         0x8001A804
    // 0x80019DC0: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80019DC0: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    after_0:
    // 0x80019DC4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80019DC8: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x80019DCC: jal         0x800058DC
    // 0x80019DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80019DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80019DD4: b           L_80019E00
    // 0x80019DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80019E00;
    // 0x80019DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019DDC:
    // 0x80019DDC: sra         $a2, $t1, 4
    ctx->r6 = S32(SIGNED(ctx->r9) >> 4);
    // 0x80019DE0: jal         0x8001A804
    // 0x80019DE4: sra         $a3, $v1, 4
    ctx->r7 = S32(SIGNED(ctx->r3) >> 4);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80019DE4: sra         $a3, $v1, 4
    ctx->r7 = S32(SIGNED(ctx->r3) >> 4);
    after_2:
    // 0x80019DE8: b           L_80019E00
    // 0x80019DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80019E00;
    // 0x80019DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019DF0:
    // 0x80019DF0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80019DF4: jal         0x800058DC
    // 0x80019DF8: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80019DF8: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    after_3:
    // 0x80019DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019E00:
    // 0x80019E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019E04: jr          $ra
    // 0x80019E08: nop

    return;
    // 0x80019E08: nop

;}
RECOMP_FUNC void FUN_80019e0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E0C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80019E10: lhu         $t6, -0x143E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X143E);
    // 0x80019E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019E1C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80019E20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019E24: beq         $at, $zero, L_80019E5C
    if (ctx->r1 == 0) {
        // 0x80019E28: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80019E5C;
    }
    // 0x80019E28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019E2C: jal         0x80018BD8
    // 0x80019E30: nop

    LOOKUP_FUNC(0x80018BD8)(rdram, ctx);
        goto after_0;
    // 0x80019E30: nop

    after_0:
    // 0x80019E34: bnel        $v0, $zero, L_80019E70
    if (ctx->r2 != 0) {
        // 0x80019E38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80019E70;
    }
    goto skip_0;
    // 0x80019E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80019E3C: jal         0x80018AB4
    // 0x80019E40: nop

    LOOKUP_FUNC(0x80018AB4)(rdram, ctx);
        goto after_1;
    // 0x80019E40: nop

    after_1:
    // 0x80019E44: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80019E48: addiu       $a1, $a1, -0x6184
    ctx->r5 = ADD32(ctx->r5, -0X6184);
    // 0x80019E4C: jal         0x800058DC
    // 0x80019E50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80019E50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80019E54: b           L_80019E70
    // 0x80019E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80019E70;
    // 0x80019E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019E5C:
    // 0x80019E5C: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x80019E60: addiu       $a1, $a1, -0x6184
    ctx->r5 = ADD32(ctx->r5, -0X6184);
    // 0x80019E64: jal         0x800058DC
    // 0x80019E68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80019E68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80019E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019E70:
    // 0x80019E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019E74: jr          $ra
    // 0x80019E78: nop

    return;
    // 0x80019E78: nop

;}
RECOMP_FUNC void FUN_80019e7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E7C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019E80: lhu         $v0, -0x142E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X142E);
    // 0x80019E84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80019E8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80019E90: beq         $v0, $zero, L_80019EAC
    if (ctx->r2 == 0) {
        // 0x80019E94: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80019EAC;
    }
    // 0x80019E94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80019E98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019E9C: beq         $v0, $at, L_80019FD8
    if (ctx->r2 == ctx->r1) {
        // 0x80019EA0: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_80019FD8;
    }
    // 0x80019EA0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80019EA4: b           L_8001A010
    // 0x80019EA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001A010;
    // 0x80019EA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80019EAC:
    // 0x80019EAC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80019EB0: lhu         $v1, -0x143E($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X143E);
    // 0x80019EB4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80019EB8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80019EBC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80019EC0: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80019EC4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019EC8: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80019ECC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80019ED0: addiu       $t7, $t7, -0x13E8
    ctx->r15 = ADD32(ctx->r15, -0X13E8);
    // 0x80019ED4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80019ED8: lbu         $t9, 0x10($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10);
    // 0x80019EDC: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x80019EE0: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x80019EE4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x80019EE8: div         $zero, $t2, $a0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r4)));
    // 0x80019EEC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80019EF0: mflo        $t3
    ctx->r11 = lo;
    // 0x80019EF4: subu        $t4, $t8, $t3
    ctx->r12 = SUB32(ctx->r24, ctx->r11);
    // 0x80019EF8: bne         $a0, $zero, L_80019F04
    if (ctx->r4 != 0) {
        // 0x80019EFC: nop
    
            goto L_80019F04;
    }
    // 0x80019EFC: nop

    // 0x80019F00: break       7
    do_break(2147589888);
L_80019F04:
    // 0x80019F04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80019F08: bne         $a0, $at, L_80019F1C
    if (ctx->r4 != ctx->r1) {
        // 0x80019F0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80019F1C;
    }
    // 0x80019F0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019F10: bne         $t2, $at, L_80019F1C
    if (ctx->r10 != ctx->r1) {
        // 0x80019F14: nop
    
            goto L_80019F1C;
    }
    // 0x80019F14: nop

    // 0x80019F18: break       6
    do_break(2147589912);
L_80019F1C:
    // 0x80019F1C: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x80019F20: lh          $t5, 0x1E($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1E);
    // 0x80019F24: sh          $t4, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r12;
    // 0x80019F28: lh          $t0, 0x1C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X1C);
    // 0x80019F2C: mflo        $t9
    ctx->r25 = lo;
    // 0x80019F30: subu        $t2, $t5, $t9
    ctx->r10 = SUB32(ctx->r13, ctx->r25);
    // 0x80019F34: bne         $a0, $zero, L_80019F40
    if (ctx->r4 != 0) {
        // 0x80019F38: nop
    
            goto L_80019F40;
    }
    // 0x80019F38: nop

    // 0x80019F3C: break       7
    do_break(2147589948);
L_80019F40:
    // 0x80019F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80019F44: bne         $a0, $at, L_80019F58
    if (ctx->r4 != ctx->r1) {
        // 0x80019F48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80019F58;
    }
    // 0x80019F48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019F4C: bne         $t7, $at, L_80019F58
    if (ctx->r15 != ctx->r1) {
        // 0x80019F50: nop
    
            goto L_80019F58;
    }
    // 0x80019F50: nop

    // 0x80019F54: break       6
    do_break(2147589972);
L_80019F58:
    // 0x80019F58: sh          $t2, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r10;
    // 0x80019F5C: blez        $t0, L_80019F78
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80019F60: andi        $a0, $v1, 0xFF
        ctx->r4 = ctx->r3 & 0XFF;
            goto L_80019F78;
    }
    // 0x80019F60: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80019F64: lh          $t1, 0x1E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1E);
    // 0x80019F68: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019F6C: addiu       $a1, $a1, -0x3300
    ctx->r5 = ADD32(ctx->r5, -0X3300);
    // 0x80019F70: bgtz        $t1, L_80019FC4
    if (SIGNED(ctx->r9) > 0) {
        // 0x80019F74: sra         $a2, $t0, 4
        ctx->r6 = S32(SIGNED(ctx->r8) >> 4);
            goto L_80019FC4;
    }
    // 0x80019F74: sra         $a2, $t0, 4
    ctx->r6 = S32(SIGNED(ctx->r8) >> 4);
L_80019F78:
    // 0x80019F78: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019F7C: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x80019F80: sh          $zero, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = 0;
    // 0x80019F84: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x80019F88: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
    // 0x80019F8C: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x80019F90: addiu       $a1, $a1, -0x3310
    ctx->r5 = ADD32(ctx->r5, -0X3310);
    // 0x80019F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019F98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80019F9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019FA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80019FA4: jal         0x8001A804
    // 0x80019FA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80019FA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x80019FAC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80019FB0: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x80019FB4: jal         0x800058DC
    // 0x80019FB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80019FB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80019FBC: b           L_8001A010
    // 0x80019FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001A010;
    // 0x80019FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80019FC4:
    // 0x80019FC4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80019FC8: jal         0x8001A804
    // 0x80019FCC: sra         $a3, $t1, 4
    ctx->r7 = S32(SIGNED(ctx->r9) >> 4);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80019FCC: sra         $a3, $t1, 4
    ctx->r7 = S32(SIGNED(ctx->r9) >> 4);
    after_2:
    // 0x80019FD0: b           L_8001A010
    // 0x80019FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001A010;
    // 0x80019FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80019FD8:
    // 0x80019FD8: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80019FDC: addiu       $a1, $a1, -0x32F8
    ctx->r5 = ADD32(ctx->r5, -0X32F8);
    // 0x80019FE0: lbu         $a0, -0x143D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X143D);
    // 0x80019FE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019FE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80019FEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019FF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80019FF4: jal         0x8001A804
    // 0x80019FF8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80019FF8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
    // 0x80019FFC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8001A000: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x8001A004: jal         0x800058DC
    // 0x8001A008: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8001A008: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8001A00C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001A010:
    // 0x8001A010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001A014: jr          $ra
    // 0x8001A018: nop

    return;
    // 0x8001A018: nop

;}
RECOMP_FUNC void FUN_8001a01c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001A028: jal         0x80018BD8
    // 0x8001A02C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80018BD8)(rdram, ctx);
        goto after_0;
    // 0x8001A02C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001A030: bne         $v0, $zero, L_8001A094
    if (ctx->r2 != 0) {
        // 0x8001A034: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_8001A094;
    }
    // 0x8001A034: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A038: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001A03C: sb          $zero, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = 0;
    // 0x8001A040: lbu         $a0, -0x1419($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1419);
    // 0x8001A044: jal         0x8001D394
    // 0x8001A048: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_1;
    // 0x8001A048: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    after_1:
    // 0x8001A04C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001A050: lbu         $t6, -0x1180($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1180);
    // 0x8001A054: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001A058: addiu       $t8, $t8, -0x12D8
    ctx->r24 = ADD32(ctx->r24, -0X12D8);
    // 0x8001A05C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001A060: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001A064: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001A068: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001A06C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001A070: lbu         $a2, -0x1419($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1419);
    // 0x8001A074: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A078: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001A07C: jal         0x8001C0B0
    // 0x8001A080: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_2;
    // 0x8001A080: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x8001A084: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001A088: addiu       $a1, $a1, -0x5F5C
    ctx->r5 = ADD32(ctx->r5, -0X5F5C);
    // 0x8001A08C: jal         0x800058DC
    // 0x8001A090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8001A090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_8001A094:
    // 0x8001A094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A09C: jr          $ra
    // 0x8001A0A0: nop

    return;
    // 0x8001A0A0: nop

;}
RECOMP_FUNC void FUN_8001a0a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A0A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001A0A8: lbu         $v0, -0x1180($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1180);
    // 0x8001A0AC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8001A0B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001A0B4: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A0B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001A0BC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001A0C0: addiu       $a1, $a1, -0x6D50
    ctx->r5 = ADD32(ctx->r5, -0X6D50);
    // 0x8001A0C4: lhu         $t6, 0x1C8($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1C8);
    // 0x8001A0C8: lhu         $t7, 0x1E8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1E8);
    // 0x8001A0CC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001A0D0: addiu       $a2, $a2, -0x12D8
    ctx->r6 = ADD32(ctx->r6, -0X12D8);
    // 0x8001A0D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A0D8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8001A0DC: mflo        $t9
    ctx->r25 = lo;
    // 0x8001A0E0: sh          $t8, -0x1404($at)
    MEM_H(-0X1404, ctx->r1) = ctx->r24;
    // 0x8001A0E4: addu        $v1, $a2, $t9
    ctx->r3 = ADD32(ctx->r6, ctx->r25);
    // 0x8001A0E8: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x8001A0EC: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x8001A0F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A0F4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8001A0F8: multu       $t2, $a3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A0FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A100: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001A104: sb          $v0, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r2;
    // 0x8001A108: sb          $t1, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r9;
    // 0x8001A10C: sb          $t0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r8;
    // 0x8001A110: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A114: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001A118: mflo        $t3
    ctx->r11 = lo;
    // 0x8001A11C: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8001A120: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001A124: lbu         $t7, 0x2($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X2);
    // 0x8001A128: bne         $t5, $t7, L_8001A2A0
    if (ctx->r13 != ctx->r15) {
        // 0x8001A12C: nop
    
            goto L_8001A2A0;
    }
    // 0x8001A12C: nop

    // 0x8001A130: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001A134: lhu         $t8, -0x1440($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X1440);
    // 0x8001A138: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001A13C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001A140: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A144: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8001A148: lw          $v0, 0x4124($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4124);
    // 0x8001A14C: addiu       $s0, $s0, -0x141A
    ctx->r16 = ADD32(ctx->r16, -0X141A);
    // 0x8001A150: ori         $a1, $zero, 0xA1A1
    ctx->r5 = 0 | 0XA1A1;
    // 0x8001A154: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x8001A158: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
    // 0x8001A15C: beq         $t0, $zero, L_8001A200
    if (ctx->r8 == 0) {
        // 0x8001A160: nop
    
            goto L_8001A200;
    }
    // 0x8001A160: nop

    // 0x8001A164: jal         0x8001D394
    // 0x8001A168: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_0;
    // 0x8001A168: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    after_0:
    // 0x8001A16C: lbu         $t1, 0x2E($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2E);
    // 0x8001A170: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001A174: addiu       $t3, $t3, -0x12D8
    ctx->r11 = ADD32(ctx->r11, -0X12D8);
    // 0x8001A178: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A17C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8001A180: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001A184: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A188: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A18C: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001A190: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A194: jal         0x8001C0B0
    // 0x8001A198: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_1;
    // 0x8001A198: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x8001A19C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A1A0: jal         0x8001D394
    // 0x8001A1A4: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_2;
    // 0x8001A1A4: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    after_2:
    // 0x8001A1A8: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001A1AC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001A1B0: addiu       $t5, $t5, -0x12D8
    ctx->r13 = ADD32(ctx->r13, -0X12D8);
    // 0x8001A1B4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8001A1B8: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8001A1BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001A1C0: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x8001A1C4: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A1C8: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001A1CC: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A1D0: jal         0x8001C0B0
    // 0x8001A1D4: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_3;
    // 0x8001A1D4: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_3:
    // 0x8001A1D8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001A1DC: lhu         $t8, -0x1440($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X1440);
    // 0x8001A1E0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001A1E4: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001A1E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A1EC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8001A1F0: lw          $v0, 0x4124($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4124);
    // 0x8001A1F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A1F8: sb          $t7, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = ctx->r15;
    // 0x8001A1FC: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
L_8001A200:
    // 0x8001A200: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001A204: andi        $t0, $v1, 0x100
    ctx->r8 = ctx->r3 & 0X100;
    // 0x8001A208: beq         $t0, $zero, L_8001A408
    if (ctx->r8 == 0) {
        // 0x8001A20C: addiu       $s0, $s0, -0x141A
        ctx->r16 = ADD32(ctx->r16, -0X141A);
            goto L_8001A408;
    }
    // 0x8001A20C: addiu       $s0, $s0, -0x141A
    ctx->r16 = ADD32(ctx->r16, -0X141A);
    // 0x8001A210: lbu         $t1, 0x2E($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2E);
    // 0x8001A214: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001A218: addiu       $t3, $t3, -0x12D8
    ctx->r11 = ADD32(ctx->r11, -0X12D8);
    // 0x8001A21C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A220: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8001A224: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001A228: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A22C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001A230: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A234: jal         0x8001D394
    // 0x8001A238: ori         $a1, $zero, 0xA1A1
    ctx->r5 = 0 | 0XA1A1;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_4;
    // 0x8001A238: ori         $a1, $zero, 0xA1A1
    ctx->r5 = 0 | 0XA1A1;
    after_4:
    // 0x8001A23C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001A240: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A244: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x8001A248: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A24C: jal         0x8001C0B0
    // 0x8001A250: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_5;
    // 0x8001A250: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    after_5:
    // 0x8001A254: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A258: jal         0x8001D394
    // 0x8001A25C: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_6;
    // 0x8001A25C: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    after_6:
    // 0x8001A260: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001A264: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A268: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x8001A26C: lbu         $a0, 0x2($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X2);
    // 0x8001A270: jal         0x8001C0B0
    // 0x8001A274: lhu         $a1, 0x4($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X4);
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_7;
    // 0x8001A274: lhu         $a1, 0x4($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X4);
    after_7:
    // 0x8001A278: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001A27C: lhu         $t5, -0x1440($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X1440);
    // 0x8001A280: lbu         $t6, 0x2D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2D);
    // 0x8001A284: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001A288: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001A28C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8001A290: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A294: lw          $v0, 0x4124($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4124);
    // 0x8001A298: b           L_8001A408
    // 0x8001A29C: sb          $t6, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = ctx->r14;
        goto L_8001A408;
    // 0x8001A29C: sb          $t6, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = ctx->r14;
L_8001A2A0:
    // 0x8001A2A0: lhu         $t8, -0x1440($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X1440);
    // 0x8001A2A4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001A2A8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001A2AC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A2B0: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8001A2B4: lw          $v0, 0x4124($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4124);
    // 0x8001A2B8: addiu       $s0, $s0, -0x141A
    ctx->r16 = ADD32(ctx->r16, -0X141A);
    // 0x8001A2BC: ori         $a1, $zero, 0xA1A1
    ctx->r5 = 0 | 0XA1A1;
    // 0x8001A2C0: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x8001A2C4: andi        $t0, $v1, 0x800
    ctx->r8 = ctx->r3 & 0X800;
    // 0x8001A2C8: beq         $t0, $zero, L_8001A36C
    if (ctx->r8 == 0) {
        // 0x8001A2CC: nop
    
            goto L_8001A36C;
    }
    // 0x8001A2CC: nop

    // 0x8001A2D0: jal         0x8001D394
    // 0x8001A2D4: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_8;
    // 0x8001A2D4: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    after_8:
    // 0x8001A2D8: lbu         $t1, 0x2E($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2E);
    // 0x8001A2DC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001A2E0: addiu       $t3, $t3, -0x12D8
    ctx->r11 = ADD32(ctx->r11, -0X12D8);
    // 0x8001A2E4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A2E8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8001A2EC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001A2F0: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A2F4: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A2F8: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001A2FC: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A300: jal         0x8001C0B0
    // 0x8001A304: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_9;
    // 0x8001A304: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_9:
    // 0x8001A308: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A30C: jal         0x8001D394
    // 0x8001A310: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_10;
    // 0x8001A310: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    after_10:
    // 0x8001A314: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001A318: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001A31C: addiu       $t5, $t5, -0x12D8
    ctx->r13 = ADD32(ctx->r13, -0X12D8);
    // 0x8001A320: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8001A324: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8001A328: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001A32C: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x8001A330: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A334: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001A338: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A33C: jal         0x8001C0B0
    // 0x8001A340: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_11;
    // 0x8001A340: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_11:
    // 0x8001A344: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001A348: lhu         $t8, -0x1440($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X1440);
    // 0x8001A34C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001A350: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001A354: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A358: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8001A35C: lw          $v0, 0x4124($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4124);
    // 0x8001A360: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A364: sb          $t7, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = ctx->r15;
    // 0x8001A368: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
L_8001A36C:
    // 0x8001A36C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001A370: andi        $t0, $v1, 0x400
    ctx->r8 = ctx->r3 & 0X400;
    // 0x8001A374: beq         $t0, $zero, L_8001A408
    if (ctx->r8 == 0) {
        // 0x8001A378: addiu       $s0, $s0, -0x141A
        ctx->r16 = ADD32(ctx->r16, -0X141A);
            goto L_8001A408;
    }
    // 0x8001A378: addiu       $s0, $s0, -0x141A
    ctx->r16 = ADD32(ctx->r16, -0X141A);
    // 0x8001A37C: lbu         $t1, 0x2E($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2E);
    // 0x8001A380: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001A384: addiu       $t3, $t3, -0x12D8
    ctx->r11 = ADD32(ctx->r11, -0X12D8);
    // 0x8001A388: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A38C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8001A390: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001A394: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A398: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001A39C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A3A0: jal         0x8001D394
    // 0x8001A3A4: ori         $a1, $zero, 0xA1A1
    ctx->r5 = 0 | 0XA1A1;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_12;
    // 0x8001A3A4: ori         $a1, $zero, 0xA1A1
    ctx->r5 = 0 | 0XA1A1;
    after_12:
    // 0x8001A3A8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001A3AC: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A3B0: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x8001A3B4: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A3B8: jal         0x8001C0B0
    // 0x8001A3BC: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_13;
    // 0x8001A3BC: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    after_13:
    // 0x8001A3C0: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A3C4: jal         0x8001D394
    // 0x8001A3C8: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_14;
    // 0x8001A3C8: ori         $a1, $zero, 0xA1FC
    ctx->r5 = 0 | 0XA1FC;
    after_14:
    // 0x8001A3CC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001A3D0: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8001A3D4: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x8001A3D8: lbu         $a0, 0x2($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X2);
    // 0x8001A3DC: jal         0x8001C0B0
    // 0x8001A3E0: lhu         $a1, 0x4($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X4);
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_15;
    // 0x8001A3E0: lhu         $a1, 0x4($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X4);
    after_15:
    // 0x8001A3E4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001A3E8: lhu         $t5, -0x1440($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X1440);
    // 0x8001A3EC: lbu         $t6, 0x2D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2D);
    // 0x8001A3F0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001A3F4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001A3F8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8001A3FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A400: lw          $v0, 0x4124($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4124);
    // 0x8001A404: sb          $t6, -0x1180($at)
    MEM_B(-0X1180, ctx->r1) = ctx->r14;
L_8001A408:
    // 0x8001A408: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x8001A40C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001A410: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001A414: andi        $t8, $a0, 0xF000
    ctx->r24 = ctx->r4 & 0XF000;
    // 0x8001A418: beq         $t8, $zero, L_8001A470
    if (ctx->r24 == 0) {
        // 0x8001A41C: lui         $a1, 0x8001
        ctx->r5 = S32(0X8001 << 16);
            goto L_8001A470;
    }
    // 0x8001A41C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8001A420: lbu         $t9, -0x1180($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1180);
    // 0x8001A424: addiu       $t1, $t1, -0x12D8
    ctx->r9 = ADD32(ctx->r9, -0X12D8);
    // 0x8001A428: andi        $t2, $a0, 0xB000
    ctx->r10 = ctx->r4 & 0XB000;
    // 0x8001A42C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001A430: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8001A434: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001A438: beq         $t2, $zero, L_8001A44C
    if (ctx->r10 == 0) {
        // 0x8001A43C: addu        $v1, $t0, $t1
        ctx->r3 = ADD32(ctx->r8, ctx->r9);
            goto L_8001A44C;
    }
    // 0x8001A43C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8001A440: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A444: b           L_8001A458
    // 0x8001A448: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
        goto L_8001A458;
    // 0x8001A448: sh          $zero, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = 0;
L_8001A44C:
    // 0x8001A44C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001A450: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A454: sh          $t3, -0x1414($at)
    MEM_H(-0X1414, ctx->r1) = ctx->r11;
L_8001A458:
    // 0x8001A458: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x8001A45C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A460: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001A464: addiu       $a1, $a1, 0x7BB8
    ctx->r5 = ADD32(ctx->r5, 0X7BB8);
    // 0x8001A468: jal         0x800058DC
    // 0x8001A46C: sw          $t4, -0x1188($at)
    MEM_W(-0X1188, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x8001A46C: sw          $t4, -0x1188($at)
    MEM_W(-0X1188, ctx->r1) = ctx->r12;
    after_16:
L_8001A470:
    // 0x8001A470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A474: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A478: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001A47C: jr          $ra
    // 0x8001A480: nop

    return;
    // 0x8001A480: nop

    // 0x8001A484: nop

    // 0x8001A488: nop

    // 0x8001A48C: nop

;}
RECOMP_FUNC void FUN_8001a490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A490: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001A494: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001A498: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001A49C: addiu       $t7, $t7, 0x42E8
    ctx->r15 = ADD32(ctx->r15, 0X42E8);
    // 0x8001A4A0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001A4A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001A4A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001A4AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A4B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A4B4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8001A4B8: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x8001A4BC: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_8001A4C0:
    // 0x8001A4C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001A4C4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8001A4C8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001A4CC: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8001A4D0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8001A4D4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8001A4D8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8001A4DC: bne         $t7, $t0, L_8001A4C0
    if (ctx->r15 != ctx->r8) {
        // 0x8001A4E0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8001A4C0;
    }
    // 0x8001A4E0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8001A4E4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001A4E8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001A4EC: addiu       $s0, $s0, -0x1160
    ctx->r16 = ADD32(ctx->r16, -0X1160);
    // 0x8001A4F0: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x8001A4F4: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x8001A4F8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
L_8001A4FC:
    // 0x8001A4FC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8001A500: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8001A504: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8001A508: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x8001A50C: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x8001A510: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x8001A514: sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
    // 0x8001A518: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x8001A51C: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
    // 0x8001A520: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x8001A524: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x8001A528: sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    // 0x8001A52C: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x8001A530: sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // 0x8001A534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001A538: jal         0x80005E44
    // 0x8001A53C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8001A53C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8001A540: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001A544: bne         $s1, $s2, L_8001A4FC
    if (ctx->r17 != ctx->r18) {
        // 0x8001A548: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8001A4FC;
    }
    // 0x8001A548: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8001A54C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001A550: jal         0x80005E44
    // 0x8001A554: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x8001A554: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8001A558: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001A55C: addiu       $a1, $a1, -0x5A7C
    ctx->r5 = ADD32(ctx->r5, -0X5A7C);
    // 0x8001A560: jal         0x800058DC
    // 0x8001A564: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8001A564: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x8001A568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001A56C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A570: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A574: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A578: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001A57C: jr          $ra
    // 0x8001A580: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8001A580: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001a584(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001a584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A584: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001A588: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001A58C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001A590: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8001A594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001A59C: addiu       $v0, $v0, -0x1160
    ctx->r2 = ADD32(ctx->r2, -0X1160);
    // 0x8001A5A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A5A4: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8001A5A8: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // 0x8001A5AC: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
L_8001A5B0:
    // 0x8001A5B0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8001A5B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001A5B8: bnel        $a1, $t6, L_8001A6C8
    if (ctx->r5 != ctx->r14) {
        // 0x8001A5BC: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_8001A6C8;
    }
    goto skip_0;
    // 0x8001A5BC: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_0:
    // 0x8001A5C0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001A5C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001A5C8: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001A5CC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8001A5D0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x8001A5D4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001A5D8: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x8001A5DC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8001A5E0: sh          $t1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r9;
    // 0x8001A5E4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001A5E8: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x8001A5EC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8001A5F0: sb          $t4, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r12;
    // 0x8001A5F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001A5F8: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x8001A5FC: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x8001A600: sb          $t8, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r24;
    // 0x8001A604: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001A608: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x8001A60C: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x8001A610: sb          $t2, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r10;
    // 0x8001A614: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001A618: lbu         $t5, 0x9($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X9);
    // 0x8001A61C: lw          $t6, 0x2C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X2C);
    // 0x8001A620: sb          $t5, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r13;
    // 0x8001A624: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001A628: lbu         $t7, 0xA($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XA);
    // 0x8001A62C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8001A630: sb          $t7, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r15;
    // 0x8001A634: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001A638: lbu         $t1, 0xB($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XB);
    // 0x8001A63C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8001A640: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x8001A644: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001A648: lbu         $t4, 0xC($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XC);
    // 0x8001A64C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8001A650: sb          $t4, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r12;
    // 0x8001A654: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001A658: lbu         $t8, 0xD($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XD);
    // 0x8001A65C: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x8001A660: sb          $t8, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r24;
    // 0x8001A664: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001A668: lhu         $t2, 0xE($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XE);
    // 0x8001A66C: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x8001A670: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x8001A674: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001A678: lhu         $t5, 0x10($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X10);
    // 0x8001A67C: lw          $t6, 0x2C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X2C);
    // 0x8001A680: sh          $t5, 0xE($t6)
    MEM_H(0XE, ctx->r14) = ctx->r13;
    // 0x8001A684: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001A688: lhu         $t7, 0x12($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X12);
    // 0x8001A68C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8001A690: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    // 0x8001A694: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x8001A698: bnel        $a2, $t1, L_8001A6C8
    if (ctx->r6 != ctx->r9) {
        // 0x8001A69C: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_8001A6C8;
    }
    goto skip_1;
    // 0x8001A69C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_1:
    // 0x8001A6A0: lhu         $t2, 0xE($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XE);
    // 0x8001A6A4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001A6A8: subu        $t3, $a3, $t2
    ctx->r11 = SUB32(ctx->r7, ctx->r10);
    // 0x8001A6AC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8001A6B0: bgez        $t3, L_8001A6C0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8001A6B4: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8001A6C0;
    }
    // 0x8001A6B4: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8001A6B8: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8001A6BC: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8001A6C0:
    // 0x8001A6C0: sh          $t4, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r12;
    // 0x8001A6C4: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_8001A6C8:
    // 0x8001A6C8: bne         $a0, $t0, L_8001A5B0
    if (ctx->r4 != ctx->r8) {
        // 0x8001A6CC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001A5B0;
    }
    // 0x8001A6CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001A6D0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8001A6D4: lbu         $t8, -0x4072($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4072);
    // 0x8001A6D8: bne         $t8, $zero, L_8001A6F0
    if (ctx->r24 != 0) {
        // 0x8001A6DC: nop
    
            goto L_8001A6F0;
    }
    // 0x8001A6DC: nop

    // 0x8001A6E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001A6E4: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x8001A6E8: b           L_8001A7F4
    // 0x8001A6EC: sb          $zero, 0x7($t9)
    MEM_B(0X7, ctx->r25) = 0;
        goto L_8001A7F4;
    // 0x8001A6EC: sb          $zero, 0x7($t9)
    MEM_B(0X7, ctx->r25) = 0;
L_8001A6F0:
    // 0x8001A6F0: jal         0x801302CC
    // 0x8001A6F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_0;
    // 0x8001A6F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001A6F8: bne         $v0, $zero, L_8001A740
    if (ctx->r2 != 0) {
        // 0x8001A6FC: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8001A740;
    }
    // 0x8001A6FC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001A700: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001A704: addiu       $t1, $zero, 0xC5
    ctx->r9 = ADD32(0, 0XC5);
    // 0x8001A708: addiu       $t5, $zero, 0x8F
    ctx->r13 = ADD32(0, 0X8F);
    // 0x8001A70C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8001A710: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8001A714: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
    // 0x8001A718: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001A71C: lw          $t6, 0x2C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X2C);
    // 0x8001A720: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
    // 0x8001A724: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001A728: lw          $t7, 0x2C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X2C);
    // 0x8001A72C: sh          $v0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r2;
    // 0x8001A730: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8001A734: lw          $t2, 0x2C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X2C);
    // 0x8001A738: b           L_8001A77C
    // 0x8001A73C: sh          $v0, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r2;
        goto L_8001A77C;
    // 0x8001A73C: sh          $v0, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r2;
L_8001A740:
    // 0x8001A740: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8001A744: addiu       $t1, $zero, 0xF1
    ctx->r9 = ADD32(0, 0XF1);
    // 0x8001A748: addiu       $t5, $zero, 0x88
    ctx->r13 = ADD32(0, 0X88);
    // 0x8001A74C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8001A750: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8001A754: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x8001A758: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001A75C: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x8001A760: sh          $t5, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r13;
    // 0x8001A764: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001A768: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x8001A76C: sh          $v0, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r2;
    // 0x8001A770: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001A774: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8001A778: sh          $v0, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r2;
L_8001A77C:
    // 0x8001A77C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001A780: addiu       $t9, $zero, 0x60
    ctx->r25 = ADD32(0, 0X60);
    // 0x8001A784: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8001A788: lw          $t4, 0x2C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X2C);
    // 0x8001A78C: sb          $zero, 0x4($t4)
    MEM_B(0X4, ctx->r12) = 0;
    // 0x8001A790: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001A794: lw          $t5, 0x2C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X2C);
    // 0x8001A798: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x8001A79C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7A0: lw          $t7, 0x2C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X2C);
    // 0x8001A7A4: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x8001A7A8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7AC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8001A7B0: sb          $t9, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r25;
    // 0x8001A7B4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7B8: lw          $t4, 0x2C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X2C);
    // 0x8001A7BC: sb          $zero, 0x8($t4)
    MEM_B(0X8, ctx->r12) = 0;
    // 0x8001A7C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7C4: lw          $t5, 0x2C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X2C);
    // 0x8001A7C8: sb          $zero, 0x9($t5)
    MEM_B(0X9, ctx->r13) = 0;
    // 0x8001A7CC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7D0: lw          $t7, 0x2C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X2C);
    // 0x8001A7D4: sb          $zero, 0xA($t7)
    MEM_B(0XA, ctx->r15) = 0;
    // 0x8001A7D8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7DC: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    // 0x8001A7E0: sb          $zero, 0xB($t9)
    MEM_B(0XB, ctx->r25) = 0;
    // 0x8001A7E4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8001A7E8: lw          $t1, 0x2C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X2C);
    // 0x8001A7EC: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x8001A7F0: sb          $zero, -0x4072($at)
    MEM_B(-0X4072, ctx->r1) = 0;
L_8001A7F4:
    // 0x8001A7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A7F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001A7FC: jr          $ra
    // 0x8001A800: nop

    return;
    // 0x8001A800: nop

;}
RECOMP_FUNC void FUN_8001a804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A804: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A808: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001A80C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001A810: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001A814: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001A818: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001A81C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001A820: addiu       $t7, $t7, -0x1160
    ctx->r15 = ADD32(ctx->r15, -0X1160);
    // 0x8001A824: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001A828: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A82C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001A830: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8001A834: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8001A838: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8001A83C: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8001A840: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001A844: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A848: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001A84C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x8001A850: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x8001A854: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x8001A858: addiu       $s4, $zero, 0x61
    ctx->r20 = ADD32(0, 0X61);
    // 0x8001A85C: beq         $a2, $zero, L_8001AA34
    if (ctx->r6 == 0) {
        // 0x8001A860: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001AA34;
    }
    // 0x8001A860: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001A864: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A868: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8001A86C: addiu       $s3, $zero, 0x62
    ctx->r19 = ADD32(0, 0X62);
    // 0x8001A870: addiu       $s2, $zero, 0x67
    ctx->r18 = ADD32(0, 0X67);
    // 0x8001A874: addiu       $s1, $zero, 0x72
    ctx->r17 = ADD32(0, 0X72);
    // 0x8001A878: addiu       $s0, $zero, 0x77
    ctx->r16 = ADD32(0, 0X77);
    // 0x8001A87C: addiu       $t5, $zero, 0x66
    ctx->r13 = ADD32(0, 0X66);
    // 0x8001A880: addiu       $t4, $zero, 0x73
    ctx->r12 = ADD32(0, 0X73);
    // 0x8001A884: addiu       $t3, $zero, 0x79
    ctx->r11 = ADD32(0, 0X79);
    // 0x8001A888: addiu       $t2, $zero, -0x4
    ctx->r10 = ADD32(0, -0X4);
    // 0x8001A88C: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x8001A890: addiu       $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
L_8001A894:
    // 0x8001A894: beql        $a1, $a2, L_8001AA28
    if (ctx->r5 == ctx->r6) {
        // 0x8001A898: lbu         $a2, 0x1($a0)
        ctx->r6 = MEM_BU(ctx->r4, 0X1);
            goto L_8001AA28;
    }
    goto skip_0;
    // 0x8001A898: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
    skip_0:
    // 0x8001A89C: bne         $t0, $a2, L_8001A8E0
    if (ctx->r8 != ctx->r6) {
        // 0x8001A8A0: nop
    
            goto L_8001A8E0;
    }
    // 0x8001A8A0: nop

    // 0x8001A8A4: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
    // 0x8001A8A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A8AC: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001A8B0: bne         $t1, $a2, L_8001A8C8
    if (ctx->r9 != ctx->r6) {
        // 0x8001A8B4: nop
    
            goto L_8001A8C8;
    }
    // 0x8001A8B4: nop

    // 0x8001A8B8: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001A8BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A8C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A8C4: sh          $t6, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r14;
L_8001A8C8:
    // 0x8001A8C8: bne         $t3, $a2, L_8001A8E0
    if (ctx->r11 != ctx->r6) {
        // 0x8001A8CC: addiu       $t7, $v0, 0x3
        ctx->r15 = ADD32(ctx->r2, 0X3);
            goto L_8001A8E0;
    }
    // 0x8001A8CC: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x8001A8D0: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8001A8D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001A8D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A8DC: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
L_8001A8E0:
    // 0x8001A8E0: bne         $t4, $a2, L_8001A93C
    if (ctx->r12 != ctx->r6) {
        // 0x8001A8E4: nop
    
            goto L_8001A93C;
    }
    // 0x8001A8E4: nop

    // 0x8001A8E8: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
    // 0x8001A8EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A8F0: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001A8F4: bne         $t1, $a2, L_8001A90C
    if (ctx->r9 != ctx->r6) {
        // 0x8001A8F8: nop
    
            goto L_8001A90C;
    }
    // 0x8001A8F8: nop

    // 0x8001A8FC: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001A900: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A904: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A908: sh          $t6, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r14;
L_8001A90C:
    // 0x8001A90C: bne         $t3, $a2, L_8001A924
    if (ctx->r11 != ctx->r6) {
        // 0x8001A910: addiu       $t7, $v0, 0x3
        ctx->r15 = ADD32(ctx->r2, 0X3);
            goto L_8001A924;
    }
    // 0x8001A910: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x8001A914: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8001A918: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001A91C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A920: sh          $t8, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r24;
L_8001A924:
    // 0x8001A924: bne         $t5, $a2, L_8001A93C
    if (ctx->r13 != ctx->r6) {
        // 0x8001A928: addiu       $t9, $v0, 0x3
        ctx->r25 = ADD32(ctx->r2, 0X3);
            goto L_8001A93C;
    }
    // 0x8001A928: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001A92C: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001A930: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A934: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A938: sh          $t6, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r14;
L_8001A93C:
    // 0x8001A93C: bne         $s0, $a2, L_8001A9B0
    if (ctx->r16 != ctx->r6) {
        // 0x8001A940: nop
    
            goto L_8001A9B0;
    }
    // 0x8001A940: nop

    // 0x8001A944: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
    // 0x8001A948: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A94C: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x8001A950: bne         $s1, $a2, L_8001A968
    if (ctx->r17 != ctx->r6) {
        // 0x8001A954: nop
    
            goto L_8001A968;
    }
    // 0x8001A954: nop

    // 0x8001A958: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8001A95C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001A960: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A964: sb          $t8, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r24;
L_8001A968:
    // 0x8001A968: bne         $s2, $a2, L_8001A980
    if (ctx->r18 != ctx->r6) {
        // 0x8001A96C: addiu       $t9, $v0, 0x3
        ctx->r25 = ADD32(ctx->r2, 0X3);
            goto L_8001A980;
    }
    // 0x8001A96C: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001A970: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001A974: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A978: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A97C: sb          $t6, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r14;
L_8001A980:
    // 0x8001A980: bne         $s3, $a2, L_8001A998
    if (ctx->r19 != ctx->r6) {
        // 0x8001A984: addiu       $t7, $v0, 0x3
        ctx->r15 = ADD32(ctx->r2, 0X3);
            goto L_8001A998;
    }
    // 0x8001A984: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x8001A988: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8001A98C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001A990: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A994: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_8001A998:
    // 0x8001A998: bne         $s4, $a2, L_8001A9B0
    if (ctx->r20 != ctx->r6) {
        // 0x8001A99C: addiu       $t9, $v0, 0x3
        ctx->r25 = ADD32(ctx->r2, 0X3);
            goto L_8001A9B0;
    }
    // 0x8001A99C: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001A9A0: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001A9A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A9A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A9AC: sb          $t6, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r14;
L_8001A9B0:
    // 0x8001A9B0: bnel        $t5, $a2, L_8001AA28
    if (ctx->r13 != ctx->r6) {
        // 0x8001A9B4: lbu         $a2, 0x1($a0)
        ctx->r6 = MEM_BU(ctx->r4, 0X1);
            goto L_8001AA28;
    }
    goto skip_1;
    // 0x8001A9B4: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x8001A9B8: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
    // 0x8001A9BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A9C0: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x8001A9C4: bne         $s1, $a2, L_8001A9DC
    if (ctx->r17 != ctx->r6) {
        // 0x8001A9C8: nop
    
            goto L_8001A9DC;
    }
    // 0x8001A9C8: nop

    // 0x8001A9CC: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8001A9D0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001A9D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A9D8: sb          $t8, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r24;
L_8001A9DC:
    // 0x8001A9DC: bne         $s2, $a2, L_8001A9F4
    if (ctx->r18 != ctx->r6) {
        // 0x8001A9E0: addiu       $t9, $v0, 0x3
        ctx->r25 = ADD32(ctx->r2, 0X3);
            goto L_8001A9F4;
    }
    // 0x8001A9E0: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001A9E4: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001A9E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A9EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A9F0: sb          $t6, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r14;
L_8001A9F4:
    // 0x8001A9F4: bne         $s3, $a2, L_8001AA0C
    if (ctx->r19 != ctx->r6) {
        // 0x8001A9F8: addiu       $t7, $v0, 0x3
        ctx->r15 = ADD32(ctx->r2, 0X3);
            goto L_8001AA0C;
    }
    // 0x8001A9F8: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x8001A9FC: and         $v0, $t7, $t2
    ctx->r2 = ctx->r15 & ctx->r10;
    // 0x8001AA00: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001AA04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001AA08: sb          $t8, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r24;
L_8001AA0C:
    // 0x8001AA0C: bne         $s4, $a2, L_8001AA24
    if (ctx->r20 != ctx->r6) {
        // 0x8001AA10: addiu       $t9, $v0, 0x3
        ctx->r25 = ADD32(ctx->r2, 0X3);
            goto L_8001AA24;
    }
    // 0x8001AA10: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8001AA14: and         $v0, $t9, $t2
    ctx->r2 = ctx->r25 & ctx->r10;
    // 0x8001AA18: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001AA1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001AA20: sb          $t6, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r14;
L_8001AA24:
    // 0x8001AA24: lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X1);
L_8001AA28:
    // 0x8001AA28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001AA2C: bne         $a2, $zero, L_8001A894
    if (ctx->r6 != 0) {
        // 0x8001AA30: nop
    
            goto L_8001A894;
    }
    // 0x8001AA30: nop

L_8001AA34:
    // 0x8001AA34: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001AA38: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8001AA3C: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8001AA40: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x8001AA44: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x8001AA48: jr          $ra
    // 0x8001AA4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001AA4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001aa50(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001aa50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AA50: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001AA54: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001AA58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001AA5C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8001AA60: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8001AA64: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001AA68: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001AA6C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001AA70: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001AA74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001AA78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001AA7C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8001AA80: addiu       $t6, $t6, 0x44E0
    ctx->r14 = ADD32(ctx->r14, 0X44E0);
    // 0x8001AA84: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001AA88: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x8001AA8C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001AA90: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8001AA94: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001AA98: addiu       $t9, $t9, 0x44EC
    ctx->r25 = ADD32(ctx->r25, 0X44EC);
    // 0x8001AA9C: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x8001AAA0: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x8001AAA4: lhu         $t8, 0x8($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X8);
    // 0x8001AAA8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001AAAC: addiu       $t2, $t2, 0x44F4
    ctx->r10 = ADD32(ctx->r10, 0X44F4);
    // 0x8001AAB0: sh          $t8, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r24;
    // 0x8001AAB4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8001AAB8: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
    // 0x8001AABC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001AAC0: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x8001AAC4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001AAC8: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001AACC: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8001AAD0: sw          $t0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r8;
    // 0x8001AAD4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001AAD8: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8001AADC: addiu       $s3, $s3, -0x107E
    ctx->r19 = ADD32(ctx->r19, -0X107E);
    // 0x8001AAE0: sw          $t4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r12;
    // 0x8001AAE4: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8001AAE8: addiu       $s2, $s2, -0x1088
    ctx->r18 = ADD32(ctx->r18, -0X1088);
    // 0x8001AAEC: addiu       $s0, $s0, -0x1090
    ctx->r16 = ADD32(ctx->r16, -0X1090);
    // 0x8001AAF0: sw          $t3, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r11;
    // 0x8001AAF4: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8001AAF8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001AAFC: sw          $t4, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r12;
    // 0x8001AB00: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8001AB04: sw          $t3, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r11;
    // 0x8001AB08: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x8001AB0C: sw          $t4, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r12;
    // 0x8001AB10: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8001AB14: sw          $t3, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r11;
    // 0x8001AB18: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x8001AB1C: sw          $t4, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r12;
    // 0x8001AB20: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x8001AB24: sw          $t3, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r11;
L_8001AB28:
    // 0x8001AB28: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8001AB2C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8001AB30: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8001AB34: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8001AB38: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8001AB3C: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x8001AB40: swl         $t6, 0x0($s2)
    do_swl(rdram, 0X0, ctx->r18, ctx->r14);
    // 0x8001AB44: lw          $t5, 0x4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X4);
    // 0x8001AB48: swr         $t6, 0x3($s2)
    do_swr(rdram, 0X3, ctx->r18, ctx->r14);
    // 0x8001AB4C: lhu         $t6, 0x8($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X8);
    // 0x8001AB50: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8001AB54: lw          $t7, 0x4($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4);
    // 0x8001AB58: swl         $t5, 0x4($s2)
    do_swl(rdram, 0X4, ctx->r18, ctx->r13);
    // 0x8001AB5C: sra         $t9, $s1, 2
    ctx->r25 = S32(SIGNED(ctx->r17) >> 2);
    // 0x8001AB60: swr         $t5, 0x7($s2)
    do_swr(rdram, 0X7, ctx->r18, ctx->r13);
    // 0x8001AB64: sh          $t6, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r14;
    // 0x8001AB68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001AB6C: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x8001AB70: swl         $t8, 0x0($s3)
    do_swl(rdram, 0X0, ctx->r19, ctx->r24);
    // 0x8001AB74: swl         $t7, 0x4($s3)
    do_swl(rdram, 0X4, ctx->r19, ctx->r15);
    // 0x8001AB78: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8001AB7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8001AB80: swr         $t8, 0x3($s3)
    do_swr(rdram, 0X3, ctx->r19, ctx->r24);
    // 0x8001AB84: jal         0x80005E44
    // 0x8001AB88: swr         $t7, 0x7($s3)
    do_swr(rdram, 0X7, ctx->r19, ctx->r15);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8001AB88: swr         $t7, 0x7($s3)
    do_swr(rdram, 0X7, ctx->r19, ctx->r15);
    after_0:
    // 0x8001AB8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001AB90: slti        $at, $s1, 0x1C
    ctx->r1 = SIGNED(ctx->r17) < 0X1C ? 1 : 0;
    // 0x8001AB94: addiu       $s0, $s0, 0x11A
    ctx->r16 = ADD32(ctx->r16, 0X11A);
    // 0x8001AB98: addiu       $s2, $s2, 0x11A
    ctx->r18 = ADD32(ctx->r18, 0X11A);
    // 0x8001AB9C: bne         $at, $zero, L_8001AB28
    if (ctx->r1 != 0) {
        // 0x8001ABA0: addiu       $s3, $s3, 0x11A
        ctx->r19 = ADD32(ctx->r19, 0X11A);
            goto L_8001AB28;
    }
    // 0x8001ABA0: addiu       $s3, $s3, 0x11A
    ctx->r19 = ADD32(ctx->r19, 0X11A);
    // 0x8001ABA4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001ABA8: addiu       $a1, $a1, 0x444C
    ctx->r5 = ADD32(ctx->r5, 0X444C);
    // 0x8001ABAC: jal         0x80005E44
    // 0x8001ABB0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x8001ABB0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x8001ABB4: jal         0x80006214
    // 0x8001ABB8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x8001ABB8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x8001ABBC: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001ABC0: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8001ABC4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8001ABC8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ABCC: addiu       $a0, $a0, 0x51C0
    ctx->r4 = ADD32(ctx->r4, 0X51C0);
    // 0x8001ABD0: addiu       $a1, $a1, -0x4C40
    ctx->r5 = ADD32(ctx->r5, -0X4C40);
    // 0x8001ABD4: addiu       $s3, $s3, -0x107E
    ctx->r19 = ADD32(ctx->r19, -0X107E);
    // 0x8001ABD8: addiu       $s2, $s2, -0x1088
    ctx->r18 = ADD32(ctx->r18, -0X1088);
    // 0x8001ABDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001ABE0: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x8001ABE4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
L_8001ABE8:
    // 0x8001ABE8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001ABEC: sra         $v0, $s1, 1
    ctx->r2 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8001ABF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001ABF4: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    // 0x8001ABF8: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x8001ABFC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8001AC00: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x8001AC04: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC08: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8001AC0C: andi        $t5, $s1, 0x1
    ctx->r13 = ctx->r17 & 0X1;
    // 0x8001AC10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001AC14: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x8001AC18: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC1C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8001AC20: sb          $zero, 0x4($t8)
    MEM_B(0X4, ctx->r24) = 0;
    // 0x8001AC24: lw          $t9, -0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC28: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8001AC2C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8001AC30: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8001AC34: sll         $t8, $t8, 8
    ctx->r24 = S32(ctx->r24 << 8);
    // 0x8001AC38: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8001AC3C: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x8001AC40: lw          $t1, -0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC44: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8001AC48: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x8001AC4C: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC50: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8001AC54: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8001AC58: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8001AC5C: sll         $t2, $t2, 9
    ctx->r10 = S32(ctx->r10 << 9);
    // 0x8001AC60: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8001AC64: sb          $zero, 0xA($t4)
    MEM_B(0XA, ctx->r12) = 0;
    // 0x8001AC68: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC6C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8001AC70: sb          $t5, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r13;
    // 0x8001AC74: lw          $t0, -0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC78: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8001AC7C: sw          $t9, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r25;
    // 0x8001AC80: lw          $t4, -0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC84: lw          $t6, 0x2C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X2C);
    // 0x8001AC88: sw          $t3, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r11;
    // 0x8001AC8C: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC90: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x8001AC94: sw          $s2, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r18;
    // 0x8001AC98: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x8001AC9C: addiu       $s2, $s2, 0x11A
    ctx->r18 = ADD32(ctx->r18, 0X11A);
    // 0x8001ACA0: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x8001ACA4: sw          $s3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r19;
    // 0x8001ACA8: bne         $s1, $a2, L_8001ABE8
    if (ctx->r17 != ctx->r6) {
        // 0x8001ACAC: addiu       $s3, $s3, 0x11A
        ctx->r19 = ADD32(ctx->r19, 0X11A);
            goto L_8001ABE8;
    }
    // 0x8001ACAC: addiu       $s3, $s3, 0x11A
    ctx->r19 = ADD32(ctx->r19, 0X11A);
    // 0x8001ACB0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001ACB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001ACB8: sb          $t9, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r25;
    // 0x8001ACBC: jal         0x80001060
    // 0x8001ACC0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_3;
    // 0x8001ACC0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x8001ACC4: beq         $v0, $zero, L_8001AD10
    if (ctx->r2 == 0) {
        // 0x8001ACC8: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_8001AD10;
    }
    // 0x8001ACC8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8001ACCC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001ACD0: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8001ACD4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8001ACD8: lw          $t3, 0x2C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X2C);
    // 0x8001ACDC: addiu       $t8, $zero, 0x260
    ctx->r24 = ADD32(0, 0X260);
    // 0x8001ACE0: addiu       $t1, $zero, 0x1D0
    ctx->r9 = ADD32(0, 0X1D0);
    // 0x8001ACE4: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x8001ACE8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001ACEC: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x8001ACF0: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x8001ACF4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8001ACF8: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x8001ACFC: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x8001AD00: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001AD04: lw          $t2, 0x2C($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X2C);
    // 0x8001AD08: b           L_8001AD50
    // 0x8001AD0C: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
        goto L_8001AD50;
    // 0x8001AD0C: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
L_8001AD10:
    // 0x8001AD10: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001AD14: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8001AD18: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8001AD1C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8001AD20: addiu       $t9, $zero, 0x130
    ctx->r25 = ADD32(0, 0X130);
    // 0x8001AD24: addiu       $t2, $zero, 0xE8
    ctx->r10 = ADD32(0, 0XE8);
    // 0x8001AD28: sh          $t3, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r11;
    // 0x8001AD2C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8001AD30: lw          $t8, 0x2C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X2C);
    // 0x8001AD34: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
    // 0x8001AD38: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001AD3C: lw          $t1, 0x2C($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X2C);
    // 0x8001AD40: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
    // 0x8001AD44: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001AD48: lw          $t3, 0x2C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X2C);
    // 0x8001AD4C: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
L_8001AD50:
    // 0x8001AD50: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001AD54: addiu       $v0, $v0, 0x77C0
    ctx->r2 = ADD32(ctx->r2, 0X77C0);
    // 0x8001AD58: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8001AD5C: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8001AD60: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8001AD64: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8001AD68: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8001AD6C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8001AD70: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8001AD74: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8001AD78: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001AD7C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001AD80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AD84: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8001AD88: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x8001AD8C: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8001AD90: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8001AD94: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8001AD98: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x8001AD9C: addiu       $a1, $a1, -0x4F50
    ctx->r5 = ADD32(ctx->r5, -0X4F50);
    // 0x8001ADA0: jal         0x800058DC
    // 0x8001ADA4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8001ADA4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_4:
    // 0x8001ADA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001ADAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001ADB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001ADB4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ADB8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001ADBC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001ADC0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001ADC4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8001ADC8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8001ADCC: jr          $ra
    // 0x8001ADD0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001ADD0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001add4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001add4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ADD4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001ADD8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001ADDC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001ADE0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8001ADE4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8001ADE8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001ADEC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001ADF0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001ADF4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001ADF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001ADFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001AE00: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8001AE04: addiu       $t6, $t6, 0x4514
    ctx->r14 = ADD32(ctx->r14, 0X4514);
    // 0x8001AE08: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001AE0C: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x8001AE10: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001AE14: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8001AE18: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001AE1C: addiu       $t9, $t9, 0x4520
    ctx->r25 = ADD32(ctx->r25, 0X4520);
    // 0x8001AE20: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x8001AE24: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x8001AE28: lhu         $t8, 0x8($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X8);
    // 0x8001AE2C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001AE30: addiu       $t2, $t2, 0x4528
    ctx->r10 = ADD32(ctx->r10, 0X4528);
    // 0x8001AE34: sh          $t8, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r24;
    // 0x8001AE38: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8001AE3C: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
    // 0x8001AE40: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8001AE44: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x8001AE48: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001AE4C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001AE50: sw          $t0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r8;
    // 0x8001AE54: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001AE58: sw          $t4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r12;
    // 0x8001AE5C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8001AE60: sw          $t3, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r11;
    // 0x8001AE64: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8001AE68: sw          $t4, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r12;
    // 0x8001AE6C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8001AE70: sw          $t3, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r11;
    // 0x8001AE74: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x8001AE78: sw          $t4, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r12;
    // 0x8001AE7C: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8001AE80: sw          $t3, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r11;
    // 0x8001AE84: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x8001AE88: sw          $t4, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r12;
    // 0x8001AE8C: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x8001AE90: jal         0x80116E80
    // 0x8001AE94: sw          $t3, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r11;
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x8001AE94: sw          $t3, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r11;
    after_0:
    // 0x8001AE98: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001AE9C: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001AEA0: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8001AEA4: addiu       $s3, $s3, -0x107E
    ctx->r19 = ADD32(ctx->r19, -0X107E);
    // 0x8001AEA8: addiu       $s2, $s2, -0x1088
    ctx->r18 = ADD32(ctx->r18, -0X1088);
    // 0x8001AEAC: addiu       $s0, $s0, -0x1090
    ctx->r16 = ADD32(ctx->r16, -0X1090);
    // 0x8001AEB0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001AEB4:
    // 0x8001AEB4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8001AEB8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8001AEBC: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8001AEC0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8001AEC4: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8001AEC8: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x8001AECC: swl         $t6, 0x0($s2)
    do_swl(rdram, 0X0, ctx->r18, ctx->r14);
    // 0x8001AED0: lw          $t5, 0x4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X4);
    // 0x8001AED4: swr         $t6, 0x3($s2)
    do_swr(rdram, 0X3, ctx->r18, ctx->r14);
    // 0x8001AED8: lhu         $t6, 0x8($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X8);
    // 0x8001AEDC: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8001AEE0: lw          $t7, 0x4($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4);
    // 0x8001AEE4: swl         $t5, 0x4($s2)
    do_swl(rdram, 0X4, ctx->r18, ctx->r13);
    // 0x8001AEE8: sra         $t9, $s1, 2
    ctx->r25 = S32(SIGNED(ctx->r17) >> 2);
    // 0x8001AEEC: swr         $t5, 0x7($s2)
    do_swr(rdram, 0X7, ctx->r18, ctx->r13);
    // 0x8001AEF0: sh          $t6, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r14;
    // 0x8001AEF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001AEF8: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x8001AEFC: swl         $t8, 0x0($s3)
    do_swl(rdram, 0X0, ctx->r19, ctx->r24);
    // 0x8001AF00: swl         $t7, 0x4($s3)
    do_swl(rdram, 0X4, ctx->r19, ctx->r15);
    // 0x8001AF04: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8001AF08: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8001AF0C: swr         $t8, 0x3($s3)
    do_swr(rdram, 0X3, ctx->r19, ctx->r24);
    // 0x8001AF10: jal         0x80005E44
    // 0x8001AF14: swr         $t7, 0x7($s3)
    do_swr(rdram, 0X7, ctx->r19, ctx->r15);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x8001AF14: swr         $t7, 0x7($s3)
    do_swr(rdram, 0X7, ctx->r19, ctx->r15);
    after_1:
    // 0x8001AF18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001AF1C: slti        $at, $s1, 0x1C
    ctx->r1 = SIGNED(ctx->r17) < 0X1C ? 1 : 0;
    // 0x8001AF20: addiu       $s0, $s0, 0x11A
    ctx->r16 = ADD32(ctx->r16, 0X11A);
    // 0x8001AF24: addiu       $s2, $s2, 0x11A
    ctx->r18 = ADD32(ctx->r18, 0X11A);
    // 0x8001AF28: bne         $at, $zero, L_8001AEB4
    if (ctx->r1 != 0) {
        // 0x8001AF2C: addiu       $s3, $s3, 0x11A
        ctx->r19 = ADD32(ctx->r19, 0X11A);
            goto L_8001AEB4;
    }
    // 0x8001AF2C: addiu       $s3, $s3, 0x11A
    ctx->r19 = ADD32(ctx->r19, 0X11A);
    // 0x8001AF30: jal         0x80006214
    // 0x8001AF34: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x8001AF34: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x8001AF38: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001AF3C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8001AF40: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8001AF44: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001AF48: addiu       $a0, $a0, 0x51C0
    ctx->r4 = ADD32(ctx->r4, 0X51C0);
    // 0x8001AF4C: addiu       $a1, $a1, -0x4C40
    ctx->r5 = ADD32(ctx->r5, -0X4C40);
    // 0x8001AF50: addiu       $s3, $s3, -0x107E
    ctx->r19 = ADD32(ctx->r19, -0X107E);
    // 0x8001AF54: addiu       $s2, $s2, -0x1088
    ctx->r18 = ADD32(ctx->r18, -0X1088);
    // 0x8001AF58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001AF5C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x8001AF60: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
L_8001AF64:
    // 0x8001AF64: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8001AF68: sra         $v1, $s1, 1
    ctx->r3 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8001AF6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001AF70: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    // 0x8001AF74: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8001AF78: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8001AF7C: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x8001AF80: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8001AF84: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8001AF88: andi        $t5, $s1, 0x1
    ctx->r13 = ctx->r17 & 0X1;
    // 0x8001AF8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001AF90: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x8001AF94: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8001AF98: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8001AF9C: sb          $zero, 0x4($t8)
    MEM_B(0X4, ctx->r24) = 0;
    // 0x8001AFA0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x8001AFA4: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8001AFA8: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8001AFAC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8001AFB0: sll         $t8, $t8, 8
    ctx->r24 = S32(ctx->r24 << 8);
    // 0x8001AFB4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8001AFB8: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x8001AFBC: lw          $t1, -0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X4);
    // 0x8001AFC0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8001AFC4: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x8001AFC8: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8001AFCC: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x8001AFD0: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8001AFD4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8001AFD8: sll         $t2, $t2, 9
    ctx->r10 = S32(ctx->r10 << 9);
    // 0x8001AFDC: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8001AFE0: sb          $zero, 0xA($t4)
    MEM_B(0XA, ctx->r12) = 0;
    // 0x8001AFE4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x8001AFE8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8001AFEC: sb          $t5, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r13;
    // 0x8001AFF0: lw          $t0, -0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X4);
    // 0x8001AFF4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8001AFF8: sw          $t9, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r25;
    // 0x8001AFFC: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x8001B000: lw          $t6, 0x2C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X2C);
    // 0x8001B004: sw          $t3, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r11;
    // 0x8001B008: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8001B00C: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x8001B010: sw          $s2, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r18;
    // 0x8001B014: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x8001B018: addiu       $s2, $s2, 0x11A
    ctx->r18 = ADD32(ctx->r18, 0X11A);
    // 0x8001B01C: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x8001B020: sw          $s3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r19;
    // 0x8001B024: bne         $s1, $a2, L_8001AF64
    if (ctx->r17 != ctx->r6) {
        // 0x8001B028: addiu       $s3, $s3, 0x11A
        ctx->r19 = ADD32(ctx->r19, 0X11A);
            goto L_8001AF64;
    }
    // 0x8001B028: addiu       $s3, $s3, 0x11A
    ctx->r19 = ADD32(ctx->r19, 0X11A);
    // 0x8001B02C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001B030: addiu       $v0, $v0, 0x77C0
    ctx->r2 = ADD32(ctx->r2, 0X77C0);
    // 0x8001B034: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8001B038: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8001B03C: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8001B040: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8001B044: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8001B048: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8001B04C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8001B050: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8001B054: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001B058: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8001B05C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8001B060: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8001B064: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x8001B068: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x8001B06C: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x8001B070: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x8001B074: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x8001B078: addiu       $a1, $a1, -0x4F50
    ctx->r5 = ADD32(ctx->r5, -0X4F50);
    // 0x8001B07C: jal         0x800058DC
    // 0x8001B080: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8001B080: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x8001B084: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001B088: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001B08C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001B090: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B094: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001B098: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001B09C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001B0A0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B0A4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8001B0A8: jr          $ra
    // 0x8001B0AC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001B0AC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001b0b0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001b0b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B0B0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001B0B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001B0B8: addiu       $v1, $v1, -0x1090
    ctx->r3 = ADD32(ctx->r3, -0X1090);
    // 0x8001B0BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B0C0: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x8001B0C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8001B0C8:
    // 0x8001B0C8: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001B0CC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8001B0D0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x8001B0D4: bnel        $a2, $t6, L_8001B144
    if (ctx->r6 != ctx->r14) {
        // 0x8001B0D8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001B144;
    }
    goto skip_0;
    // 0x8001B0D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8001B0DC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8001B0E0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8001B0E4: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x8001B0E8: sb          $t8, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r24;
    // 0x8001B0EC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8001B0F0: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x8001B0F4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8001B0F8: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x8001B0FC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8001B100: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x8001B104: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8001B108: sh          $t3, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r11;
    // 0x8001B10C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8001B110: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8001B114: sb          $zero, 0x4($t7)
    MEM_B(0X4, ctx->r15) = 0;
    // 0x8001B118: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001B11C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8001B120: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x8001B124: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8001B128: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
    // 0x8001B12C: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x8001B130: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x8001B134: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8001B138: lw          $t3, 0x2C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X2C);
    // 0x8001B13C: sb          $zero, 0xA($t3)
    MEM_B(0XA, ctx->r11) = 0;
    // 0x8001B140: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001B144:
    // 0x8001B144: bne         $v0, $a3, L_8001B0C8
    if (ctx->r2 != ctx->r7) {
        // 0x8001B148: addiu       $v1, $v1, 0x11A
        ctx->r3 = ADD32(ctx->r3, 0X11A);
            goto L_8001B0C8;
    }
    // 0x8001B148: addiu       $v1, $v1, 0x11A
    ctx->r3 = ADD32(ctx->r3, 0X11A);
    // 0x8001B14C: jr          $ra
    // 0x8001B150: nop

    return;
    // 0x8001B150: nop

;}
RECOMP_FUNC void FUN_8001b154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B154: slti        $at, $a0, 0x1C
    ctx->r1 = SIGNED(ctx->r4) < 0X1C ? 1 : 0;
    // 0x8001B158: beq         $at, $zero, L_8001B18C
    if (ctx->r1 == 0) {
        // 0x8001B15C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001B18C;
    }
    // 0x8001B15C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B160: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8001B164: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001B168: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B16C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001B170: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B174: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001B178: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001B17C: addiu       $t7, $t7, -0x1090
    ctx->r15 = ADD32(ctx->r15, -0X1090);
    // 0x8001B180: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B184: jr          $ra
    // 0x8001B188: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x8001B188: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8001B18C:
    // 0x8001B18C: jr          $ra
    // 0x8001B190: nop

    return;
    // 0x8001B190: nop

;}
RECOMP_FUNC void FUN_8001b194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B194: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001B198: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001B19C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8001B1A0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001B1A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B1A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001B1AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B1B0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001B1B4: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001B1B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001B1BC: addiu       $t7, $t7, -0x1090
    ctx->r15 = ADD32(ctx->r15, -0X1090);
    // 0x8001B1C0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B1C4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001B1C8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001B1CC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001B1D0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001B1D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001B1D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001B1DC: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x8001B1E0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001B1E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001B1E8: sb          $a3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r7;
    // 0x8001B1EC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8001B1F0: beq         $a1, $at, L_8001B1FC
    if (ctx->r5 == ctx->r1) {
        // 0x8001B1F4: sb          $v1, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r3;
            goto L_8001B1FC;
    }
    // 0x8001B1F4: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8001B1F8: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
L_8001B1FC:
    // 0x8001B1FC: jr          $ra
    // 0x8001B200: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    return;
    // 0x8001B200: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001b204(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001b204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B204: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x8001B208: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001B20C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001B210: addiu       $t7, $t7, 0x4548
    ctx->r15 = ADD32(ctx->r15, 0X4548);
    // 0x8001B214: andi        $s7, $a0, 0xFF
    ctx->r23 = ctx->r4 & 0XFF;
    // 0x8001B218: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001B21C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001B220: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001B224: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001B228: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001B22C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001B230: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001B234: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001B238: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B23C: sw          $a0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r4;
    // 0x8001B240: sw          $a1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r5;
    // 0x8001B244: sw          $a2, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r6;
    // 0x8001B248: sw          $a3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r7;
    // 0x8001B24C: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
    // 0x8001B250: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x8001B254: addiu       $t1, $t7, 0xC0
    ctx->r9 = ADD32(ctx->r15, 0XC0);
    // 0x8001B258: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
L_8001B25C:
    // 0x8001B25C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001B260: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8001B264: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001B268: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8001B26C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8001B270: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8001B274: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8001B278: bne         $t7, $t1, L_8001B25C
    if (ctx->r15 != ctx->r9) {
        // 0x8001B27C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8001B25C;
    }
    // 0x8001B27C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8001B280: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001B284: addiu       $t2, $t2, 0x4608
    ctx->r10 = ADD32(ctx->r10, 0X4608);
    // 0x8001B288: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001B28C: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8001B290: addiu       $t5, $t5, 0x4614
    ctx->r13 = ADD32(ctx->r13, 0X4614);
    // 0x8001B294: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8001B298: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8001B29C: slti        $at, $s7, 0x1C
    ctx->r1 = SIGNED(ctx->r23) < 0X1C ? 1 : 0;
    // 0x8001B2A0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001B2A4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8001B2A8: lhu         $t4, 0x8($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X8);
    // 0x8001B2AC: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8001B2B0: addiu       $fp, $fp, 0xE4D
    ctx->r30 = ADD32(ctx->r30, 0XE4D);
    // 0x8001B2B4: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
    // 0x8001B2B8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001B2BC: addiu       $a1, $a1, 0xE4C
    ctx->r5 = ADD32(ctx->r5, 0XE4C);
    // 0x8001B2C0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001B2C4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001B2C8: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8001B2CC: addiu       $t8, $sp, 0x168
    ctx->r24 = ADD32(ctx->r29, 0X168);
    // 0x8001B2D0: bne         $at, $zero, L_8001B2E0
    if (ctx->r1 != 0) {
        // 0x8001B2D4: sw          $t1, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r9;
            goto L_8001B2E0;
    }
    // 0x8001B2D4: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x8001B2D8: b           L_8001BBD4
    // 0x8001B2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BBD4;
    // 0x8001B2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B2E0:
    // 0x8001B2E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B2E4: sb          $zero, 0xE48($at)
    MEM_B(0XE48, ctx->r1) = 0;
    // 0x8001B2E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B2EC: sb          $zero, 0xE49($at)
    MEM_B(0XE49, ctx->r1) = 0;
    // 0x8001B2F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B2F4: sb          $t6, 0xE4A($at)
    MEM_B(0XE4A, ctx->r1) = ctx->r14;
    // 0x8001B2F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B2FC: sb          $zero, 0xE4B($at)
    MEM_B(0XE4B, ctx->r1) = 0;
    // 0x8001B300: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8001B304: sb          $zero, 0x0($fp)
    MEM_B(0X0, ctx->r30) = 0;
    // 0x8001B308: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B30C: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8001B310: sb          $zero, 0xE4E($at)
    MEM_B(0XE4E, ctx->r1) = 0;
    // 0x8001B314: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B318: sb          $zero, 0xE4F($at)
    MEM_B(0XE4F, ctx->r1) = 0;
    // 0x8001B31C: sh          $zero, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = 0;
    // 0x8001B320: sb          $zero, 0x129($sp)
    MEM_B(0X129, ctx->r29) = 0;
    // 0x8001B324: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x8001B328: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8001B32C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001B330: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001B334: bne         $a0, $zero, L_8001B3B4
    if (ctx->r4 != 0) {
        // 0x8001B338: sll         $t2, $s7, 3
        ctx->r10 = S32(ctx->r23 << 3);
            goto L_8001B3B4;
    }
    // 0x8001B338: sll         $t2, $s7, 3
    ctx->r10 = S32(ctx->r23 << 3);
    // 0x8001B33C: addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // 0x8001B340: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001B344: subu        $t2, $t2, $s7
    ctx->r10 = SUB32(ctx->r10, ctx->r23);
    // 0x8001B348: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001B34C: addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // 0x8001B350: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001B354: addiu       $t3, $t3, -0x1090
    ctx->r11 = ADD32(ctx->r11, -0X1090);
    // 0x8001B358: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001B35C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8001B360: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001B364: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8001B368: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8001B36C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8001B370: swl         $t5, 0x8($v0)
    do_swl(rdram, 0X8, ctx->r2, ctx->r13);
    // 0x8001B374: swr         $t5, 0xB($v0)
    do_swr(rdram, 0XB, ctx->r2, ctx->r13);
    // 0x8001B378: lhu         $t5, 0x8($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X8);
    // 0x8001B37C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001B380: swl         $t4, 0xC($v0)
    do_swl(rdram, 0XC, ctx->r2, ctx->r12);
    // 0x8001B384: swl         $t7, 0x12($v0)
    do_swl(rdram, 0X12, ctx->r2, ctx->r15);
    // 0x8001B388: swl         $t1, 0x16($v0)
    do_swl(rdram, 0X16, ctx->r2, ctx->r9);
    // 0x8001B38C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8001B390: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8001B394: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8001B398: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8001B39C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8001B3A0: swr         $t4, 0xF($v0)
    do_swr(rdram, 0XF, ctx->r2, ctx->r12);
    // 0x8001B3A4: swr         $t7, 0x15($v0)
    do_swr(rdram, 0X15, ctx->r2, ctx->r15);
    // 0x8001B3A8: swr         $t1, 0x19($v0)
    do_swr(rdram, 0X19, ctx->r2, ctx->r9);
    // 0x8001B3AC: b           L_8001BBD0
    // 0x8001B3B0: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
        goto L_8001BBD0;
    // 0x8001B3B0: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
L_8001B3B4:
    // 0x8001B3B4: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8001B3B8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001B3BC: beq         $v1, $zero, L_8001BAF0
    if (ctx->r3 == 0) {
        // 0x8001B3C0: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001BAF0;
    }
    // 0x8001B3C0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001B3C4: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
L_8001B3C8:
    // 0x8001B3C8: beq         $v1, $at, L_8001B484
    if (ctx->r3 == ctx->r1) {
        // 0x8001B3CC: lw          $t3, 0x164($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X164);
            goto L_8001B484;
    }
    // 0x8001B3CC: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x8001B3D0: sll         $t6, $s7, 3
    ctx->r14 = S32(ctx->r23 << 3);
    // 0x8001B3D4: addu        $t6, $t6, $s7
    ctx->r14 = ADD32(ctx->r14, ctx->r23);
    // 0x8001B3D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B3DC: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8001B3E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B3E4: addu        $t6, $t6, $s7
    ctx->r14 = ADD32(ctx->r14, ctx->r23);
    // 0x8001B3E8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B3EC: sll         $t8, $s4, 3
    ctx->r24 = S32(ctx->r20 << 3);
    // 0x8001B3F0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001B3F4: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001B3F8: addiu       $t3, $t3, -0x1090
    ctx->r11 = ADD32(ctx->r11, -0X1090);
    // 0x8001B3FC: addiu       $t2, $t9, 0x12
    ctx->r10 = ADD32(ctx->r25, 0X12);
    // 0x8001B400: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8001B404: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x8001B408: bne         $at, $zero, L_8001B428
    if (ctx->r1 != 0) {
        // 0x8001B40C: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B428;
    }
    // 0x8001B40C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001B410: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8001B414: beq         $at, $zero, L_8001B428
    if (ctx->r1 == 0) {
        // 0x8001B418: sll         $t4, $v1, 1
        ctx->r12 = S32(ctx->r3 << 1);
            goto L_8001B428;
    }
    // 0x8001B418: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8001B41C: addu        $a3, $sp, $t4
    ctx->r7 = ADD32(ctx->r29, ctx->r12);
    // 0x8001B420: b           L_8001B444
    // 0x8001B424: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
        goto L_8001B444;
    // 0x8001B424: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
L_8001B428:
    // 0x8001B428: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x8001B42C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B430: sll         $t6, $v1, 8
    ctx->r14 = S32(ctx->r3 << 8);
    // 0x8001B434: addu        $t1, $t5, $s5
    ctx->r9 = ADD32(ctx->r13, ctx->r21);
    // 0x8001B438: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8001B43C: addu        $a3, $t7, $t6
    ctx->r7 = ADD32(ctx->r15, ctx->r14);
    // 0x8001B440: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
L_8001B444:
    // 0x8001B444: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001B448: andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // 0x8001B44C: jal         0x8001BC04
    // 0x8001B450: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001BC04)(rdram, ctx);
        goto after_0;
    // 0x8001B450: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x8001B454: beq         $v0, $zero, L_8001B468
    if (ctx->r2 == 0) {
        // 0x8001B458: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8001B468;
    }
    // 0x8001B458: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001B45C: lbu         $t8, 0x0($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X0);
    // 0x8001B460: addu        $s6, $s6, $t8
    ctx->r22 = ADD32(ctx->r22, ctx->r24);
    // 0x8001B464: andi        $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 & 0XFFFF;
L_8001B468:
    // 0x8001B468: lbu         $t9, 0xE4C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0XE4C);
    // 0x8001B46C: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8001B470: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001B474: addu        $s3, $s2, $t9
    ctx->r19 = ADD32(ctx->r18, ctx->r25);
    // 0x8001B478: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8001B47C: b           L_8001BAD4
    // 0x8001B480: addu        $a0, $t2, $s5
    ctx->r4 = ADD32(ctx->r10, ctx->r21);
        goto L_8001BAD4;
    // 0x8001B480: addu        $a0, $t2, $s5
    ctx->r4 = ADD32(ctx->r10, ctx->r21);
L_8001B484:
    // 0x8001B484: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B488: addu        $t4, $t3, $s5
    ctx->r12 = ADD32(ctx->r11, ctx->r21);
    // 0x8001B48C: lbu         $v1, 0x0($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0X0);
    // 0x8001B490: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x8001B494: sb          $zero, 0x133($sp)
    MEM_B(0X133, ctx->r29) = 0;
    // 0x8001B498: bne         $v1, $at, L_8001B590
    if (ctx->r3 != ctx->r1) {
        // 0x8001B49C: lw          $a0, 0x124($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X124);
            goto L_8001B590;
    }
    // 0x8001B49C: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8001B4A0: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8001B4A4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B4A8: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x8001B4AC: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8001B4B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001B4B4: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B4B8: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B4BC: sw          $a0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r4;
    // 0x8001B4C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B4C4: beql        $v1, $zero, L_8001B590
    if (ctx->r3 == 0) {
        // 0x8001B4C8: addiu       $v1, $zero, 0x73
        ctx->r3 = ADD32(0, 0X73);
            goto L_8001B590;
    }
    goto skip_0;
    // 0x8001B4C8: addiu       $v1, $zero, 0x73
    ctx->r3 = ADD32(0, 0X73);
    skip_0:
    // 0x8001B4CC: beq         $at, $zero, L_8001B58C
    if (ctx->r1 == 0) {
        // 0x8001B4D0: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B58C;
    }
    // 0x8001B4D0: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001B4D4: sll         $t5, $s7, 3
    ctx->r13 = S32(ctx->r23 << 3);
    // 0x8001B4D8: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x8001B4DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8001B4E0: subu        $t5, $t5, $s7
    ctx->r13 = SUB32(ctx->r13, ctx->r23);
    // 0x8001B4E4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8001B4E8: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x8001B4EC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8001B4F0: sll         $t1, $s4, 3
    ctx->r9 = S32(ctx->r20 << 3);
    // 0x8001B4F4: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x8001B4F8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001B4FC: addiu       $t8, $t8, -0x1090
    ctx->r24 = ADD32(ctx->r24, -0X1090);
    // 0x8001B500: addiu       $t6, $t7, 0x12
    ctx->r14 = ADD32(ctx->r15, 0X12);
    // 0x8001B504: addu        $s1, $t6, $t8
    ctx->r17 = ADD32(ctx->r14, ctx->r24);
L_8001B508:
    // 0x8001B508: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8001B50C: bne         $at, $zero, L_8001B52C
    if (ctx->r1 != 0) {
        // 0x8001B510: andi        $a0, $s7, 0xFF
        ctx->r4 = ctx->r23 & 0XFF;
            goto L_8001B52C;
    }
    // 0x8001B510: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001B514: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8001B518: beq         $at, $zero, L_8001B52C
    if (ctx->r1 == 0) {
        // 0x8001B51C: sll         $t9, $v1, 1
        ctx->r25 = S32(ctx->r3 << 1);
            goto L_8001B52C;
    }
    // 0x8001B51C: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8001B520: addu        $a3, $sp, $t9
    ctx->r7 = ADD32(ctx->r29, ctx->r25);
    // 0x8001B524: b           L_8001B540
    // 0x8001B528: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
        goto L_8001B540;
    // 0x8001B528: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
L_8001B52C:
    // 0x8001B52C: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B530: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x8001B534: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B538: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x8001B53C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
L_8001B540:
    // 0x8001B540: andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // 0x8001B544: jal         0x8001BC04
    // 0x8001B548: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001BC04)(rdram, ctx);
        goto after_1;
    // 0x8001B548: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8001B54C: beq         $v0, $zero, L_8001B560
    if (ctx->r2 == 0) {
        // 0x8001B550: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_8001B560;
    }
    // 0x8001B550: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001B554: lbu         $t4, 0x0($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X0);
    // 0x8001B558: addu        $s6, $s6, $t4
    ctx->r22 = ADD32(ctx->r22, ctx->r12);
    // 0x8001B55C: andi        $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 & 0XFFFF;
L_8001B560:
    // 0x8001B560: lbu         $t5, 0xE4C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XE4C);
    // 0x8001B564: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B568: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B56C: addu        $s3, $s2, $t5
    ctx->r19 = ADD32(ctx->r18, ctx->r13);
    // 0x8001B570: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8001B574: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001B578: beq         $v1, $zero, L_8001B58C
    if (ctx->r3 == 0) {
        // 0x8001B57C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8001B58C;
    }
    // 0x8001B57C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8001B580: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B584: bne         $at, $zero, L_8001B508
    if (ctx->r1 != 0) {
        // 0x8001B588: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B508;
    }
    // 0x8001B588: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8001B58C:
    // 0x8001B58C: addiu       $v1, $zero, 0x73
    ctx->r3 = ADD32(0, 0X73);
L_8001B590:
    // 0x8001B590: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8001B594: bne         $v1, $at, L_8001B648
    if (ctx->r3 != ctx->r1) {
        // 0x8001B598: addiu       $s0, $sp, 0x134
        ctx->r16 = ADD32(ctx->r29, 0X134);
            goto L_8001B648;
    }
    // 0x8001B598: addiu       $s0, $sp, 0x134
    ctx->r16 = ADD32(ctx->r29, 0X134);
    // 0x8001B59C: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8001B5A0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B5A4: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8001B5A8: addu        $a0, $t1, $s5
    ctx->r4 = ADD32(ctx->r9, ctx->r21);
    // 0x8001B5AC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B5B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B5B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B5B8: bne         $v1, $at, L_8001B5C4
    if (ctx->r3 != ctx->r1) {
        // 0x8001B5BC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8001B5C4;
    }
    // 0x8001B5BC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B5C0: sb          $t7, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r15;
L_8001B5C4:
    // 0x8001B5C4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8001B5C8: bne         $v1, $at, L_8001B5D4
    if (ctx->r3 != ctx->r1) {
        // 0x8001B5CC: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8001B5D4;
    }
    // 0x8001B5CC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001B5D0: sb          $t6, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r14;
L_8001B5D4:
    // 0x8001B5D4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8001B5D8: bne         $v1, $at, L_8001B5E4
    if (ctx->r3 != ctx->r1) {
        // 0x8001B5DC: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_8001B5E4;
    }
    // 0x8001B5DC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8001B5E0: sb          $t8, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r24;
L_8001B5E4:
    // 0x8001B5E4: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8001B5E8: bne         $v1, $at, L_8001B5F4
    if (ctx->r3 != ctx->r1) {
        // 0x8001B5EC: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8001B5F4;
    }
    // 0x8001B5EC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8001B5F0: sb          $t9, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r25;
L_8001B5F4:
    // 0x8001B5F4: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x8001B5F8: bne         $v1, $at, L_8001B604
    if (ctx->r3 != ctx->r1) {
        // 0x8001B5FC: addiu       $t2, $zero, 0x5
        ctx->r10 = ADD32(0, 0X5);
            goto L_8001B604;
    }
    // 0x8001B5FC: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8001B600: sb          $t2, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r10;
L_8001B604:
    // 0x8001B604: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x8001B608: bne         $v1, $at, L_8001B614
    if (ctx->r3 != ctx->r1) {
        // 0x8001B60C: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_8001B614;
    }
    // 0x8001B60C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8001B610: sb          $t3, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r11;
L_8001B614:
    // 0x8001B614: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x8001B618: bne         $v1, $at, L_8001B624
    if (ctx->r3 != ctx->r1) {
        // 0x8001B61C: addiu       $t4, $zero, 0x7
        ctx->r12 = ADD32(0, 0X7);
            goto L_8001B624;
    }
    // 0x8001B61C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8001B620: sb          $t4, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r12;
L_8001B624:
    // 0x8001B624: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001B628: bne         $v1, $at, L_8001B634
    if (ctx->r3 != ctx->r1) {
        // 0x8001B62C: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_8001B634;
    }
    // 0x8001B62C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8001B630: sb          $t5, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r13;
L_8001B634:
    // 0x8001B634: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8001B638: bne         $v1, $at, L_8001B644
    if (ctx->r3 != ctx->r1) {
        // 0x8001B63C: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_8001B644;
    }
    // 0x8001B63C: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8001B640: sb          $t1, 0x133($sp)
    MEM_B(0X133, ctx->r29) = ctx->r9;
L_8001B644:
    // 0x8001B644: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
L_8001B648:
    // 0x8001B648: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8001B64C: bne         $v1, $at, L_8001B754
    if (ctx->r3 != ctx->r1) {
        // 0x8001B650: lw          $v0, 0x124($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X124);
            goto L_8001B754;
    }
    // 0x8001B650: lw          $v0, 0x124($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X124);
    // 0x8001B654: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001B658: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B65C: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8001B660: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B664: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x8001B668: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x8001B66C: lbu         $a1, 0x133($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X133);
    // 0x8001B670: jal         0x8001DBC8
    // 0x8001B674: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    LOOKUP_FUNC(0x8001DBC8)(rdram, ctx);
        goto after_2;
    // 0x8001B674: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    after_2:
    // 0x8001B678: lbu         $v1, 0x134($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X134);
    // 0x8001B67C: addiu       $s0, $sp, 0x135
    ctx->r16 = ADD32(ctx->r29, 0X135);
    // 0x8001B680: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B684: beql        $v1, $zero, L_8001B754
    if (ctx->r3 == 0) {
        // 0x8001B688: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_8001B754;
    }
    goto skip_1;
    // 0x8001B688: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    skip_1:
    // 0x8001B68C: beq         $at, $zero, L_8001B750
    if (ctx->r1 == 0) {
        // 0x8001B690: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B750;
    }
    // 0x8001B690: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001B694: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x8001B698: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x8001B69C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B6A0: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x8001B6A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B6A8: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x8001B6AC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8001B6B0: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
    // 0x8001B6B4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8001B6B8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001B6BC: addiu       $t2, $t2, -0x1090
    ctx->r10 = ADD32(ctx->r10, -0X1090);
    // 0x8001B6C0: addiu       $t9, $t8, 0x12
    ctx->r25 = ADD32(ctx->r24, 0X12);
    // 0x8001B6C4: addu        $s1, $t9, $t2
    ctx->r17 = ADD32(ctx->r25, ctx->r10);
L_8001B6C8:
    // 0x8001B6C8: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8001B6CC: bne         $at, $zero, L_8001B6EC
    if (ctx->r1 != 0) {
        // 0x8001B6D0: andi        $a0, $s7, 0xFF
        ctx->r4 = ctx->r23 & 0XFF;
            goto L_8001B6EC;
    }
    // 0x8001B6D0: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001B6D4: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8001B6D8: beq         $at, $zero, L_8001B6EC
    if (ctx->r1 == 0) {
        // 0x8001B6DC: sll         $t3, $v1, 1
        ctx->r11 = S32(ctx->r3 << 1);
            goto L_8001B6EC;
    }
    // 0x8001B6DC: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8001B6E0: addu        $a3, $sp, $t3
    ctx->r7 = ADD32(ctx->r29, ctx->r11);
    // 0x8001B6E4: b           L_8001B704
    // 0x8001B6E8: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
        goto L_8001B704;
    // 0x8001B6E8: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
L_8001B6EC:
    // 0x8001B6EC: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B6F0: sll         $t5, $v1, 8
    ctx->r13 = S32(ctx->r3 << 8);
    // 0x8001B6F4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B6F8: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x8001B6FC: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8001B700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001B704:
    // 0x8001B704: andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // 0x8001B708: jal         0x8001BC04
    // 0x8001B70C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001BC04)(rdram, ctx);
        goto after_3;
    // 0x8001B70C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x8001B710: beq         $v0, $zero, L_8001B724
    if (ctx->r2 == 0) {
        // 0x8001B714: lui         $t7, 0x8009
        ctx->r15 = S32(0X8009 << 16);
            goto L_8001B724;
    }
    // 0x8001B714: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001B718: lbu         $t1, 0x0($fp)
    ctx->r9 = MEM_BU(ctx->r30, 0X0);
    // 0x8001B71C: addu        $s6, $s6, $t1
    ctx->r22 = ADD32(ctx->r22, ctx->r9);
    // 0x8001B720: andi        $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 & 0XFFFF;
L_8001B724:
    // 0x8001B724: lbu         $t7, 0xE4C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0XE4C);
    // 0x8001B728: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B72C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B730: addu        $s3, $s2, $t7
    ctx->r19 = ADD32(ctx->r18, ctx->r15);
    // 0x8001B734: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8001B738: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001B73C: beq         $v1, $zero, L_8001B750
    if (ctx->r3 == 0) {
        // 0x8001B740: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8001B750;
    }
    // 0x8001B740: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8001B744: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B748: bne         $at, $zero, L_8001B6C8
    if (ctx->r1 != 0) {
        // 0x8001B74C: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B6C8;
    }
    // 0x8001B74C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8001B750:
    // 0x8001B750: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
L_8001B754:
    // 0x8001B754: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8001B758: bne         $v1, $at, L_8001B860
    if (ctx->r3 != ctx->r1) {
        // 0x8001B75C: lw          $v0, 0x124($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X124);
            goto L_8001B860;
    }
    // 0x8001B75C: lw          $v0, 0x124($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X124);
    // 0x8001B760: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001B764: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B768: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8001B76C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B770: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x8001B774: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x8001B778: lbu         $a1, 0x133($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X133);
    // 0x8001B77C: jal         0x8001D69C
    // 0x8001B780: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001D69C)(rdram, ctx);
        goto after_4;
    // 0x8001B780: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8001B784: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B788: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B78C: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B790: beql        $v1, $zero, L_8001B860
    if (ctx->r3 == 0) {
        // 0x8001B794: addiu       $v1, $zero, 0x64
        ctx->r3 = ADD32(0, 0X64);
            goto L_8001B860;
    }
    goto skip_2;
    // 0x8001B794: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    skip_2:
    // 0x8001B798: beq         $at, $zero, L_8001B85C
    if (ctx->r1 == 0) {
        // 0x8001B79C: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B85C;
    }
    // 0x8001B79C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001B7A0: sll         $t6, $s7, 3
    ctx->r14 = S32(ctx->r23 << 3);
    // 0x8001B7A4: addu        $t6, $t6, $s7
    ctx->r14 = ADD32(ctx->r14, ctx->r23);
    // 0x8001B7A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B7AC: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8001B7B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001B7B4: addu        $t6, $t6, $s7
    ctx->r14 = ADD32(ctx->r14, ctx->r23);
    // 0x8001B7B8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B7BC: sll         $t8, $s4, 3
    ctx->r24 = S32(ctx->r20 << 3);
    // 0x8001B7C0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001B7C4: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001B7C8: addiu       $t3, $t3, -0x1090
    ctx->r11 = ADD32(ctx->r11, -0X1090);
    // 0x8001B7CC: addiu       $t2, $t9, 0x12
    ctx->r10 = ADD32(ctx->r25, 0X12);
    // 0x8001B7D0: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
L_8001B7D4:
    // 0x8001B7D4: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8001B7D8: bne         $at, $zero, L_8001B7F8
    if (ctx->r1 != 0) {
        // 0x8001B7DC: andi        $a0, $s7, 0xFF
        ctx->r4 = ctx->r23 & 0XFF;
            goto L_8001B7F8;
    }
    // 0x8001B7DC: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001B7E0: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8001B7E4: beq         $at, $zero, L_8001B7F8
    if (ctx->r1 == 0) {
        // 0x8001B7E8: sll         $t4, $v1, 1
        ctx->r12 = S32(ctx->r3 << 1);
            goto L_8001B7F8;
    }
    // 0x8001B7E8: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8001B7EC: addu        $a3, $sp, $t4
    ctx->r7 = ADD32(ctx->r29, ctx->r12);
    // 0x8001B7F0: b           L_8001B810
    // 0x8001B7F4: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
        goto L_8001B810;
    // 0x8001B7F4: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
L_8001B7F8:
    // 0x8001B7F8: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B7FC: sll         $t1, $v1, 8
    ctx->r9 = S32(ctx->r3 << 8);
    // 0x8001B800: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B804: addu        $a3, $t5, $t1
    ctx->r7 = ADD32(ctx->r13, ctx->r9);
    // 0x8001B808: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8001B80C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001B810:
    // 0x8001B810: andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // 0x8001B814: jal         0x8001BC04
    // 0x8001B818: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001BC04)(rdram, ctx);
        goto after_5;
    // 0x8001B818: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_5:
    // 0x8001B81C: beq         $v0, $zero, L_8001B830
    if (ctx->r2 == 0) {
        // 0x8001B820: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_8001B830;
    }
    // 0x8001B820: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001B824: lbu         $t7, 0x0($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X0);
    // 0x8001B828: addu        $s6, $s6, $t7
    ctx->r22 = ADD32(ctx->r22, ctx->r15);
    // 0x8001B82C: andi        $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 & 0XFFFF;
L_8001B830:
    // 0x8001B830: lbu         $t6, 0xE4C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XE4C);
    // 0x8001B834: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B838: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B83C: addu        $s3, $s2, $t6
    ctx->r19 = ADD32(ctx->r18, ctx->r14);
    // 0x8001B840: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8001B844: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001B848: beq         $v1, $zero, L_8001B85C
    if (ctx->r3 == 0) {
        // 0x8001B84C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8001B85C;
    }
    // 0x8001B84C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8001B850: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B854: bne         $at, $zero, L_8001B7D4
    if (ctx->r1 != 0) {
        // 0x8001B858: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B7D4;
    }
    // 0x8001B858: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8001B85C:
    // 0x8001B85C: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
L_8001B860:
    // 0x8001B860: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x8001B864: bne         $v1, $at, L_8001B978
    if (ctx->r3 != ctx->r1) {
        // 0x8001B868: lw          $v0, 0x124($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X124);
            goto L_8001B978;
    }
    // 0x8001B868: lw          $v0, 0x124($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X124);
    // 0x8001B86C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001B870: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B874: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8001B878: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B87C: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x8001B880: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x8001B884: lbu         $a1, 0x133($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X133);
    // 0x8001B888: jal         0x8001D69C
    // 0x8001B88C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001D69C)(rdram, ctx);
        goto after_6;
    // 0x8001B88C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x8001B890: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B898: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B89C: beql        $v1, $zero, L_8001B978
    if (ctx->r3 == 0) {
        // 0x8001B8A0: addiu       $v1, $zero, 0x64
        ctx->r3 = ADD32(0, 0X64);
            goto L_8001B978;
    }
    goto skip_3;
    // 0x8001B8A0: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    skip_3:
    // 0x8001B8A4: beq         $at, $zero, L_8001B974
    if (ctx->r1 == 0) {
        // 0x8001B8A8: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B974;
    }
    // 0x8001B8A8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001B8AC: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8001B8B0: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x8001B8B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001B8B8: subu        $t8, $t8, $s7
    ctx->r24 = SUB32(ctx->r24, ctx->r23);
    // 0x8001B8BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001B8C0: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x8001B8C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001B8C8: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8001B8CC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B8D0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8001B8D4: addiu       $t4, $t4, -0x1090
    ctx->r12 = ADD32(ctx->r12, -0X1090);
    // 0x8001B8D8: addiu       $t3, $t2, 0x12
    ctx->r11 = ADD32(ctx->r10, 0X12);
    // 0x8001B8DC: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
L_8001B8E0:
    // 0x8001B8E0: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8001B8E4: bne         $at, $zero, L_8001B904
    if (ctx->r1 != 0) {
        // 0x8001B8E8: andi        $a0, $s7, 0xFF
        ctx->r4 = ctx->r23 & 0XFF;
            goto L_8001B904;
    }
    // 0x8001B8E8: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001B8EC: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8001B8F0: beq         $at, $zero, L_8001B904
    if (ctx->r1 == 0) {
        // 0x8001B8F4: sll         $t5, $v1, 1
        ctx->r13 = S32(ctx->r3 << 1);
            goto L_8001B904;
    }
    // 0x8001B8F4: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x8001B8F8: addu        $a3, $sp, $t5
    ctx->r7 = ADD32(ctx->r29, ctx->r13);
    // 0x8001B8FC: b           L_8001B91C
    // 0x8001B900: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
        goto L_8001B91C;
    // 0x8001B900: lhu         $a3, 0x24($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X24);
L_8001B904:
    // 0x8001B904: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B908: sll         $t7, $v1, 8
    ctx->r15 = S32(ctx->r3 << 8);
    // 0x8001B90C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001B910: addu        $a3, $t1, $t7
    ctx->r7 = ADD32(ctx->r9, ctx->r15);
    // 0x8001B914: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8001B918: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001B91C:
    // 0x8001B91C: ori         $at, $zero, 0xA1A1
    ctx->r1 = 0 | 0XA1A1;
    // 0x8001B920: bne         $a3, $at, L_8001B92C
    if (ctx->r7 != ctx->r1) {
        // 0x8001B924: andi        $a1, $s3, 0xFFFF
        ctx->r5 = ctx->r19 & 0XFFFF;
            goto L_8001B92C;
    }
    // 0x8001B924: andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // 0x8001B928: ori         $a3, $zero, 0xA3B0
    ctx->r7 = 0 | 0XA3B0;
L_8001B92C:
    // 0x8001B92C: jal         0x8001BC04
    // 0x8001B930: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001BC04)(rdram, ctx);
        goto after_7;
    // 0x8001B930: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_7:
    // 0x8001B934: beq         $v0, $zero, L_8001B948
    if (ctx->r2 == 0) {
        // 0x8001B938: lui         $t8, 0x8009
        ctx->r24 = S32(0X8009 << 16);
            goto L_8001B948;
    }
    // 0x8001B938: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001B93C: lbu         $t6, 0x0($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X0);
    // 0x8001B940: addu        $s6, $s6, $t6
    ctx->r22 = ADD32(ctx->r22, ctx->r14);
    // 0x8001B944: andi        $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 & 0XFFFF;
L_8001B948:
    // 0x8001B948: lbu         $t8, 0xE4C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0XE4C);
    // 0x8001B94C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B950: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B954: addu        $s3, $s2, $t8
    ctx->r19 = ADD32(ctx->r18, ctx->r24);
    // 0x8001B958: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8001B95C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001B960: beq         $v1, $zero, L_8001B974
    if (ctx->r3 == 0) {
        // 0x8001B964: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8001B974;
    }
    // 0x8001B964: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8001B968: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001B96C: bne         $at, $zero, L_8001B8E0
    if (ctx->r1 != 0) {
        // 0x8001B970: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001B8E0;
    }
    // 0x8001B970: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8001B974:
    // 0x8001B974: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
L_8001B978:
    // 0x8001B978: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8001B97C: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x8001B980: bne         $v1, $at, L_8001B9AC
    if (ctx->r3 != ctx->r1) {
        // 0x8001B984: addu        $a0, $t9, $s5
        ctx->r4 = ADD32(ctx->r25, ctx->r21);
            goto L_8001B9AC;
    }
    // 0x8001B984: addu        $a0, $t9, $s5
    ctx->r4 = ADD32(ctx->r25, ctx->r21);
    // 0x8001B988: lw          $v0, 0x124($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X124);
    // 0x8001B98C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B990: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8001B994: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8001B998: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8001B99C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B9A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B9A4: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x8001B9A8: sb          $t2, 0xE48($at)
    MEM_B(0XE48, ctx->r1) = ctx->r10;
L_8001B9AC:
    // 0x8001B9AC: addiu       $at, $zero, 0x70
    ctx->r1 = ADD32(0, 0X70);
    // 0x8001B9B0: bne         $v1, $at, L_8001B9D8
    if (ctx->r3 != ctx->r1) {
        // 0x8001B9B4: lw          $t3, 0x124($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X124);
            goto L_8001B9D8;
    }
    // 0x8001B9B4: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x8001B9B8: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x8001B9BC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B9C0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8001B9C4: addiu       $t1, $t5, 0x4
    ctx->r9 = ADD32(ctx->r13, 0X4);
    // 0x8001B9C8: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x8001B9CC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001B9D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B9D4: sb          $t7, 0xE4B($at)
    MEM_B(0XE4B, ctx->r1) = ctx->r15;
L_8001B9D8:
    // 0x8001B9D8: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x8001B9DC: bne         $v1, $at, L_8001BA00
    if (ctx->r3 != ctx->r1) {
        // 0x8001B9E0: lw          $t6, 0x124($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X124);
            goto L_8001BA00;
    }
    // 0x8001B9E0: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x8001B9E4: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x8001B9E8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001B9EC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8001B9F0: addiu       $t2, $t9, 0x4
    ctx->r10 = ADD32(ctx->r25, 0X4);
    // 0x8001B9F4: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x8001B9F8: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8001B9FC: sb          $t3, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r11;
L_8001BA00:
    // 0x8001BA00: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8001BA04: bne         $v1, $at, L_8001BA2C
    if (ctx->r3 != ctx->r1) {
        // 0x8001BA08: lw          $t4, 0x124($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X124);
            goto L_8001BA2C;
    }
    // 0x8001BA08: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x8001BA0C: addiu       $t1, $t4, 0x3
    ctx->r9 = ADD32(ctx->r12, 0X3);
    // 0x8001BA10: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001BA14: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8001BA18: addiu       $t7, $t5, 0x4
    ctx->r15 = ADD32(ctx->r13, 0X4);
    // 0x8001BA1C: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x8001BA20: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001BA24: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001BA28: sb          $t6, 0xE4E($at)
    MEM_B(0XE4E, ctx->r1) = ctx->r14;
L_8001BA2C:
    // 0x8001BA2C: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8001BA30: bne         $v1, $at, L_8001BA54
    if (ctx->r3 != ctx->r1) {
        // 0x8001BA34: lw          $t8, 0x124($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X124);
            goto L_8001BA54;
    }
    // 0x8001BA34: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8001BA38: addiu       $t2, $t8, 0x3
    ctx->r10 = ADD32(ctx->r24, 0X3);
    // 0x8001BA3C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001BA40: and         $t9, $t2, $at
    ctx->r25 = ctx->r10 & ctx->r1;
    // 0x8001BA44: addiu       $t3, $t9, 0x4
    ctx->r11 = ADD32(ctx->r25, 0X4);
    // 0x8001BA48: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x8001BA4C: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8001BA50: sh          $t4, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r12;
L_8001BA54:
    // 0x8001BA54: addiu       $at, $zero, 0x61
    ctx->r1 = ADD32(0, 0X61);
    // 0x8001BA58: bne         $v1, $at, L_8001BA80
    if (ctx->r3 != ctx->r1) {
        // 0x8001BA5C: lw          $t1, 0x124($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X124);
            goto L_8001BA80;
    }
    // 0x8001BA5C: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x8001BA60: addiu       $t7, $t1, 0x3
    ctx->r15 = ADD32(ctx->r9, 0X3);
    // 0x8001BA64: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001BA68: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x8001BA6C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8001BA70: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x8001BA74: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001BA78: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001BA7C: sb          $t8, 0xE4A($at)
    MEM_B(0XE4A, ctx->r1) = ctx->r24;
L_8001BA80:
    // 0x8001BA80: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8001BA84: bne         $v1, $at, L_8001BAAC
    if (ctx->r3 != ctx->r1) {
        // 0x8001BA88: lw          $t2, 0x124($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X124);
            goto L_8001BAAC;
    }
    // 0x8001BA88: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x8001BA8C: addiu       $t3, $t2, 0x3
    ctx->r11 = ADD32(ctx->r10, 0X3);
    // 0x8001BA90: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001BA94: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x8001BA98: addiu       $t4, $t9, 0x4
    ctx->r12 = ADD32(ctx->r25, 0X4);
    // 0x8001BA9C: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x8001BAA0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8001BAA4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001BAA8: sb          $t1, 0xE4F($at)
    MEM_B(0XE4F, ctx->r1) = ctx->r9;
L_8001BAAC:
    // 0x8001BAAC: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x8001BAB0: bne         $v1, $at, L_8001BAD4
    if (ctx->r3 != ctx->r1) {
        // 0x8001BAB4: lw          $t7, 0x124($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X124);
            goto L_8001BAD4;
    }
    // 0x8001BAB4: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x8001BAB8: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x8001BABC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001BAC0: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x8001BAC4: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x8001BAC8: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x8001BACC: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8001BAD0: sb          $t2, 0x129($sp)
    MEM_B(0X129, ctx->r29) = ctx->r10;
L_8001BAD4:
    // 0x8001BAD4: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x8001BAD8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001BADC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001BAE0: beq         $v1, $zero, L_8001BAF0
    if (ctx->r3 == 0) {
        // 0x8001BAE4: slti        $at, $s3, 0x101
        ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
            goto L_8001BAF0;
    }
    // 0x8001BAE4: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001BAE8: bnel        $at, $zero, L_8001B3C8
    if (ctx->r1 != 0) {
        // 0x8001BAEC: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_8001B3C8;
    }
    goto skip_4;
    // 0x8001BAEC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    skip_4:
L_8001BAF0:
    // 0x8001BAF0: sll         $t3, $s7, 3
    ctx->r11 = S32(ctx->r23 << 3);
    // 0x8001BAF4: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x8001BAF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001BAFC: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8001BB00: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001BB04: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x8001BB08: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8001BB0C: lh          $t9, 0x15E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X15E);
    // 0x8001BB10: addiu       $t4, $t4, -0x1090
    ctx->r12 = ADD32(ctx->r12, -0X1090);
    // 0x8001BB14: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8001BB18: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8001BB1C: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8001BB20: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x8001BB24: lh          $t1, 0x162($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X162);
    // 0x8001BB28: lhu         $t7, 0x12A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X12A);
    // 0x8001BB2C: lbu         $t6, 0x129($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X129);
    // 0x8001BB30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001BB34: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001BB38: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x8001BB3C: addiu       $a1, $a1, 0xE4C
    ctx->r5 = ADD32(ctx->r5, 0XE4C);
    // 0x8001BB40: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8001BB44: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8001BB48: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8001BB4C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8001BB50: bne         $v1, $at, L_8001BB94
    if (ctx->r3 != ctx->r1) {
        // 0x8001BB54: sb          $t6, 0x8($v0)
        MEM_B(0X8, ctx->r2) = ctx->r14;
            goto L_8001BB94;
    }
    // 0x8001BB54: sb          $t6, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r14;
    // 0x8001BB58: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001BB5C: bne         $at, $zero, L_8001BB74
    if (ctx->r1 != 0) {
        // 0x8001BB60: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001BB74;
    }
    // 0x8001BB60: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001BB64: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BB68: subu        $s3, $s2, $t8
    ctx->r19 = SUB32(ctx->r18, ctx->r24);
    // 0x8001BB6C: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8001BB70: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8001BB74:
    // 0x8001BB74: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x8001BB78: subu        $t2, $t5, $s2
    ctx->r10 = SUB32(ctx->r13, ctx->r18);
    // 0x8001BB7C: bgez        $t2, L_8001BB8C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001BB80: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8001BB8C;
    }
    // 0x8001BB80: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8001BB84: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8001BB88: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8001BB8C:
    // 0x8001BB8C: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x8001BB90: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
L_8001BB94:
    // 0x8001BB94: slti        $at, $v1, 0x349
    ctx->r1 = SIGNED(ctx->r3) < 0X349 ? 1 : 0;
    // 0x8001BB98: bne         $at, $zero, L_8001BBD0
    if (ctx->r1 != 0) {
        // 0x8001BB9C: slti        $at, $s3, 0x101
        ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
            goto L_8001BBD0;
    }
    // 0x8001BB9C: slti        $at, $s3, 0x101
    ctx->r1 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // 0x8001BBA0: bne         $at, $zero, L_8001BBB4
    if (ctx->r1 != 0) {
        // 0x8001BBA4: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_8001BBB4;
    }
    // 0x8001BBA4: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001BBA8: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BBAC: subu        $s3, $s3, $t4
    ctx->r19 = SUB32(ctx->r19, ctx->r12);
    // 0x8001BBB0: andi        $s2, $s3, 0xFFFF
    ctx->r18 = ctx->r19 & 0XFFFF;
L_8001BBB4:
    // 0x8001BBB4: bgez        $s2, L_8001BBC4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8001BBB8: sra         $t9, $s2, 1
        ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
            goto L_8001BBC4;
    }
    // 0x8001BBB8: sra         $t9, $s2, 1
    ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8001BBBC: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x8001BBC0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8001BBC4:
    // 0x8001BBC4: subu        $t1, $v1, $t9
    ctx->r9 = SUB32(ctx->r3, ctx->r25);
    // 0x8001BBC8: addiu       $t7, $t1, -0x3E8
    ctx->r15 = ADD32(ctx->r9, -0X3E8);
    // 0x8001BBCC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
L_8001BBD0:
    // 0x8001BBD0: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_8001BBD4:
    // 0x8001BBD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001BBD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001BBDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BBE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001BBE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001BBE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001BBEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BBF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001BBF4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001BBF8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001BBFC: jr          $ra
    // 0x8001BC00: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x8001BC00: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001bc04(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001bc04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BC08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001BC0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BC10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BC14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001BC18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001BC1C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001BC20: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8001BC24: lbu         $a0, 0xE48($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XE48);
    // 0x8001BC28: jal         0x8001BD20
    // 0x8001BC2C: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001BD20)(rdram, ctx);
        goto after_0;
    // 0x8001BC2C: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    after_0:
    // 0x8001BC30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001BC34: sb          $v0, 0xE4C($at)
    MEM_B(0XE4C, ctx->r1) = ctx->r2;
    // 0x8001BC38: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x8001BC3C: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8001BC40: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001BC44: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8001BC48: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BC4C: slti        $at, $t8, 0x101
    ctx->r1 = SIGNED(ctx->r24) < 0X101 ? 1 : 0;
    // 0x8001BC50: beq         $at, $zero, L_8001BCEC
    if (ctx->r1 == 0) {
        // 0x8001BC54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001BCEC;
    }
    // 0x8001BC54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BC58: lbu         $a0, 0xE48($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XE48);
    // 0x8001BC5C: jal         0x8001D394
    // 0x8001BC60: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001D394)(rdram, ctx);
        goto after_1;
    // 0x8001BC60: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    after_1:
    // 0x8001BC64: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001BC68: lbu         $a2, 0xE48($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XE48);
    // 0x8001BC6C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8001BC70: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    // 0x8001BC74: jal         0x8001C0B0
    // 0x8001BC78: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8001C0B0)(rdram, ctx);
        goto after_2;
    // 0x8001BC78: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x8001BC7C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001BC80: lbu         $t9, 0xE48($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0XE48);
    // 0x8001BC84: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001BC88: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001BC8C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8001BC90: lbu         $t0, 0xE49($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0XE49);
    // 0x8001BC94: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001BC98: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001BC9C: sb          $t0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r8;
    // 0x8001BCA0: lbu         $t1, 0xE4A($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XE4A);
    // 0x8001BCA4: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8001BCA8: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001BCAC: sb          $t1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r9;
    // 0x8001BCB0: lbu         $t2, 0xE4B($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XE4B);
    // 0x8001BCB4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001BCB8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8001BCBC: sb          $t2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r10;
    // 0x8001BCC0: lbu         $t3, 0xE4C($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0XE4C);
    // 0x8001BCC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BCC8: sb          $t3, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r11;
    // 0x8001BCCC: lbu         $t4, 0xE4D($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0XE4D);
    // 0x8001BCD0: sb          $t4, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r12;
    // 0x8001BCD4: lbu         $t5, 0xE4E($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XE4E);
    // 0x8001BCD8: sb          $t5, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r13;
    // 0x8001BCDC: lbu         $t6, 0xE4F($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XE4F);
    // 0x8001BCE0: sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // 0x8001BCE4: b           L_8001BD0C
    // 0x8001BCE8: sb          $t6, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r14;
        goto L_8001BD0C;
    // 0x8001BCE8: sb          $t6, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r14;
L_8001BCEC:
    // 0x8001BCEC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8001BCF0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8001BCF4: sb          $v1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r3;
    // 0x8001BCF8: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8001BCFC: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x8001BD00: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8001BD04: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x8001BD08: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
L_8001BD0C:
    // 0x8001BD0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BD10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001BD14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001BD18: jr          $ra
    // 0x8001BD1C: nop

    return;
    // 0x8001BD1C: nop

;}
RECOMP_FUNC void FUN_8001bd20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BD24: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001BD28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001BD2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001BD30: addiu       $t6, $t6, 0x461C
    ctx->r14 = ADD32(ctx->r14, 0X461C);
    // 0x8001BD34: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001BD38: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x8001BD3C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001BD40: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001BD44: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x8001BD48: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8001BD4C: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x8001BD50: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
    // 0x8001BD54: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001BD58: bne         $a2, $v0, L_8001BE78
    if (ctx->r6 != ctx->r2) {
        // 0x8001BD5C: lbu         $v1, 0x0($t9)
        ctx->r3 = MEM_BU(ctx->r25, 0X0);
            goto L_8001BE78;
    }
    // 0x8001BD5C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x8001BD60: ori         $at, $zero, 0xA3C9
    ctx->r1 = 0 | 0XA3C9;
    // 0x8001BD64: bne         $a1, $at, L_8001BD74
    if (ctx->r5 != ctx->r1) {
        // 0x8001BD68: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001BD74;
    }
    // 0x8001BD68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001BD6C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BD70: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BD74:
    // 0x8001BD74: ori         $at, $zero, 0xA3E9
    ctx->r1 = 0 | 0XA3E9;
    // 0x8001BD78: bnel        $a0, $at, L_8001BD8C
    if (ctx->r4 != ctx->r1) {
        // 0x8001BD7C: ori         $at, $zero, 0xA3EA
        ctx->r1 = 0 | 0XA3EA;
            goto L_8001BD8C;
    }
    goto skip_0;
    // 0x8001BD7C: ori         $at, $zero, 0xA3EA
    ctx->r1 = 0 | 0XA3EA;
    skip_0:
    // 0x8001BD80: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BD84: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BD88: ori         $at, $zero, 0xA3EA
    ctx->r1 = 0 | 0XA3EA;
L_8001BD8C:
    // 0x8001BD8C: bnel        $a0, $at, L_8001BDA0
    if (ctx->r4 != ctx->r1) {
        // 0x8001BD90: ori         $at, $zero, 0xA3EC
        ctx->r1 = 0 | 0XA3EC;
            goto L_8001BDA0;
    }
    goto skip_1;
    // 0x8001BD90: ori         $at, $zero, 0xA3EC
    ctx->r1 = 0 | 0XA3EC;
    skip_1:
    // 0x8001BD94: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BD98: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BD9C: ori         $at, $zero, 0xA3EC
    ctx->r1 = 0 | 0XA3EC;
L_8001BDA0:
    // 0x8001BDA0: bnel        $a0, $at, L_8001BDB4
    if (ctx->r4 != ctx->r1) {
        // 0x8001BDA4: ori         $at, $zero, 0xA3B1
        ctx->r1 = 0 | 0XA3B1;
            goto L_8001BDB4;
    }
    goto skip_2;
    // 0x8001BDA4: ori         $at, $zero, 0xA3B1
    ctx->r1 = 0 | 0XA3B1;
    skip_2:
    // 0x8001BDA8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BDAC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BDB0: ori         $at, $zero, 0xA3B1
    ctx->r1 = 0 | 0XA3B1;
L_8001BDB4:
    // 0x8001BDB4: bnel        $a0, $at, L_8001BDC8
    if (ctx->r4 != ctx->r1) {
        // 0x8001BDB8: ori         $at, $zero, 0xA1A4
        ctx->r1 = 0 | 0XA1A4;
            goto L_8001BDC8;
    }
    goto skip_3;
    // 0x8001BDB8: ori         $at, $zero, 0xA1A4
    ctx->r1 = 0 | 0XA1A4;
    skip_3:
    // 0x8001BDBC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BDC0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BDC4: ori         $at, $zero, 0xA1A4
    ctx->r1 = 0 | 0XA1A4;
L_8001BDC8:
    // 0x8001BDC8: bnel        $a0, $at, L_8001BDDC
    if (ctx->r4 != ctx->r1) {
        // 0x8001BDCC: ori         $at, $zero, 0xA1A5
        ctx->r1 = 0 | 0XA1A5;
            goto L_8001BDDC;
    }
    goto skip_4;
    // 0x8001BDCC: ori         $at, $zero, 0xA1A5
    ctx->r1 = 0 | 0XA1A5;
    skip_4:
    // 0x8001BDD0: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BDD4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BDD8: ori         $at, $zero, 0xA1A5
    ctx->r1 = 0 | 0XA1A5;
L_8001BDDC:
    // 0x8001BDDC: bnel        $a0, $at, L_8001BDF0
    if (ctx->r4 != ctx->r1) {
        // 0x8001BDE0: ori         $at, $zero, 0xA1A8
        ctx->r1 = 0 | 0XA1A8;
            goto L_8001BDF0;
    }
    goto skip_5;
    // 0x8001BDE0: ori         $at, $zero, 0xA1A8
    ctx->r1 = 0 | 0XA1A8;
    skip_5:
    // 0x8001BDE4: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BDE8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BDEC: ori         $at, $zero, 0xA1A8
    ctx->r1 = 0 | 0XA1A8;
L_8001BDF0:
    // 0x8001BDF0: bnel        $a0, $at, L_8001BE04
    if (ctx->r4 != ctx->r1) {
        // 0x8001BDF4: ori         $at, $zero, 0xA1A7
        ctx->r1 = 0 | 0XA1A7;
            goto L_8001BE04;
    }
    goto skip_6;
    // 0x8001BDF4: ori         $at, $zero, 0xA1A7
    ctx->r1 = 0 | 0XA1A7;
    skip_6:
    // 0x8001BDF8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BDFC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BE00: ori         $at, $zero, 0xA1A7
    ctx->r1 = 0 | 0XA1A7;
L_8001BE04:
    // 0x8001BE04: bnel        $a0, $at, L_8001BE18
    if (ctx->r4 != ctx->r1) {
        // 0x8001BE08: ori         $at, $zero, 0xA1AD
        ctx->r1 = 0 | 0XA1AD;
            goto L_8001BE18;
    }
    goto skip_7;
    // 0x8001BE08: ori         $at, $zero, 0xA1AD
    ctx->r1 = 0 | 0XA1AD;
    skip_7:
    // 0x8001BE0C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BE10: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BE14: ori         $at, $zero, 0xA1AD
    ctx->r1 = 0 | 0XA1AD;
L_8001BE18:
    // 0x8001BE18: bnel        $a0, $at, L_8001BE2C
    if (ctx->r4 != ctx->r1) {
        // 0x8001BE1C: ori         $at, $zero, 0xA1AB
        ctx->r1 = 0 | 0XA1AB;
            goto L_8001BE2C;
    }
    goto skip_8;
    // 0x8001BE1C: ori         $at, $zero, 0xA1AB
    ctx->r1 = 0 | 0XA1AB;
    skip_8:
    // 0x8001BE20: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BE24: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BE28: ori         $at, $zero, 0xA1AB
    ctx->r1 = 0 | 0XA1AB;
L_8001BE2C:
    // 0x8001BE2C: bnel        $a0, $at, L_8001BE40
    if (ctx->r4 != ctx->r1) {
        // 0x8001BE30: ori         $at, $zero, 0xA1AA
        ctx->r1 = 0 | 0XA1AA;
            goto L_8001BE40;
    }
    goto skip_9;
    // 0x8001BE30: ori         $at, $zero, 0xA1AA
    ctx->r1 = 0 | 0XA1AA;
    skip_9:
    // 0x8001BE34: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BE38: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BE3C: ori         $at, $zero, 0xA1AA
    ctx->r1 = 0 | 0XA1AA;
L_8001BE40:
    // 0x8001BE40: bnel        $a0, $at, L_8001BE54
    if (ctx->r4 != ctx->r1) {
        // 0x8001BE44: ori         $at, $zero, 0xA1CA
        ctx->r1 = 0 | 0XA1CA;
            goto L_8001BE54;
    }
    goto skip_10;
    // 0x8001BE44: ori         $at, $zero, 0xA1CA
    ctx->r1 = 0 | 0XA1CA;
    skip_10:
    // 0x8001BE48: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BE4C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BE50: ori         $at, $zero, 0xA1CA
    ctx->r1 = 0 | 0XA1CA;
L_8001BE54:
    // 0x8001BE54: bnel        $a0, $at, L_8001BE68
    if (ctx->r4 != ctx->r1) {
        // 0x8001BE58: ori         $at, $zero, 0xA1CB
        ctx->r1 = 0 | 0XA1CB;
            goto L_8001BE68;
    }
    goto skip_11;
    // 0x8001BE58: ori         $at, $zero, 0xA1CB
    ctx->r1 = 0 | 0XA1CB;
    skip_11:
    // 0x8001BE5C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BE60: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BE64: ori         $at, $zero, 0xA1CB
    ctx->r1 = 0 | 0XA1CB;
L_8001BE68:
    // 0x8001BE68: bnel        $a0, $at, L_8001BE7C
    if (ctx->r4 != ctx->r1) {
        // 0x8001BE6C: addiu       $a3, $zero, 0x4
        ctx->r7 = ADD32(0, 0X4);
            goto L_8001BE7C;
    }
    goto skip_12;
    // 0x8001BE6C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    skip_12:
    // 0x8001BE70: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BE74: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BE78:
    // 0x8001BE78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_8001BE7C:
    // 0x8001BE7C: bne         $a3, $v0, L_8001BF74
    if (ctx->r7 != ctx->r2) {
        // 0x8001BE80: ori         $at, $zero, 0xA1AE
        ctx->r1 = 0 | 0XA1AE;
            goto L_8001BF74;
    }
    // 0x8001BE80: ori         $at, $zero, 0xA1AE
    ctx->r1 = 0 | 0XA1AE;
    // 0x8001BE84: slt         $at, $a1, $at
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001BE88: bne         $at, $zero, L_8001BEBC
    if (ctx->r1 != 0) {
        // 0x8001BE8C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001BEBC;
    }
    // 0x8001BE8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001BE90: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001BE94: ori         $at, $at, 0x5C1A
    ctx->r1 = ctx->r1 | 0X5C1A;
    // 0x8001BE98: addu        $t0, $a0, $at
    ctx->r8 = ADD32(ctx->r4, ctx->r1);
    // 0x8001BE9C: sltiu       $at, $t0, 0xF
    ctx->r1 = ctx->r8 < 0XF ? 1 : 0;
    // 0x8001BEA0: beq         $at, $zero, L_8001BF74
    if (ctx->r1 == 0) {
        // 0x8001BEA4: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8001BF74;
    }
    // 0x8001BEA4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001BEA8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001BEAC: addu        $at, $at, $t0
    gpr jr_addend_8001BEB4 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8001BEB0: lw          $t0, -0x3210($at)
    ctx->r8 = ADD32(ctx->r1, -0X3210);
    // 0x8001BEB4: jr          $t0
    // 0x8001BEB8: nop

    switch (jr_addend_8001BEB4 >> 2) {
        case 0: goto L_8001BF00; break;
        case 1: goto L_8001BF74; break;
        case 2: goto L_8001BF74; break;
        case 3: goto L_8001BEF4; break;
        case 4: goto L_8001BF0C; break;
        case 5: goto L_8001BF74; break;
        case 6: goto L_8001BF18; break;
        case 7: goto L_8001BF74; break;
        case 8: goto L_8001BF74; break;
        case 9: goto L_8001BF74; break;
        case 10: goto L_8001BF74; break;
        case 11: goto L_8001BF74; break;
        case 12: goto L_8001BF24; break;
        case 13: goto L_8001BF74; break;
        case 14: goto L_8001BF30; break;
        default: switch_error(__func__, 0x8001BEB4, 0x8004CDF0);
    }
    // 0x8001BEB8: nop

L_8001BEBC:
    // 0x8001BEBC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001BEC0: ori         $at, $at, 0x5E5F
    ctx->r1 = ctx->r1 | 0X5E5F;
    // 0x8001BEC4: addu        $t1, $a0, $at
    ctx->r9 = ADD32(ctx->r4, ctx->r1);
    // 0x8001BEC8: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x8001BECC: beq         $at, $zero, L_8001BF74
    if (ctx->r1 == 0) {
        // 0x8001BED0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8001BF74;
    }
    // 0x8001BED0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001BED4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001BED8: addu        $at, $at, $t1
    gpr jr_addend_8001BEE0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8001BEDC: lw          $t1, -0x31D4($at)
    ctx->r9 = ADD32(ctx->r1, -0X31D4);
    // 0x8001BEE0: jr          $t1
    // 0x8001BEE4: nop

    switch (jr_addend_8001BEE0 >> 2) {
        case 0: goto L_8001BEE8; break;
        case 1: goto L_8001BF74; break;
        case 2: goto L_8001BF74; break;
        case 3: goto L_8001BF3C; break;
        case 4: goto L_8001BF48; break;
        case 5: goto L_8001BF74; break;
        case 6: goto L_8001BF6C; break;
        case 7: goto L_8001BF60; break;
        case 8: goto L_8001BF74; break;
        case 9: goto L_8001BF74; break;
        case 10: goto L_8001BF74; break;
        case 11: goto L_8001BF74; break;
        case 12: goto L_8001BF54; break;
        default: switch_error(__func__, 0x8001BEE0, 0x8004CE2C);
    }
    // 0x8001BEE4: nop

L_8001BEE8:
    // 0x8001BEE8: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BEEC: b           L_8001BF74
    // 0x8001BEF0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BEF0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BEF4:
    // 0x8001BEF4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BEF8: b           L_8001BF74
    // 0x8001BEFC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BEFC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF00:
    // 0x8001BF00: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF04: b           L_8001BF74
    // 0x8001BF08: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF08: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF0C:
    // 0x8001BF0C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF10: b           L_8001BF74
    // 0x8001BF14: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF14: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF18:
    // 0x8001BF18: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF1C: b           L_8001BF74
    // 0x8001BF20: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF20: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF24:
    // 0x8001BF24: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF28: b           L_8001BF74
    // 0x8001BF2C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF2C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF30:
    // 0x8001BF30: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF34: b           L_8001BF74
    // 0x8001BF38: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF38: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF3C:
    // 0x8001BF3C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF40: b           L_8001BF74
    // 0x8001BF44: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF44: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF48:
    // 0x8001BF48: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BF4C: b           L_8001BF74
    // 0x8001BF50: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF50: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF54:
    // 0x8001BF54: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BF58: b           L_8001BF74
    // 0x8001BF5C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF5C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF60:
    // 0x8001BF60: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF64: b           L_8001BF74
    // 0x8001BF68: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_8001BF74;
    // 0x8001BF68: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF6C:
    // 0x8001BF6C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8001BF70: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF74:
    // 0x8001BF74: bne         $v0, $zero, L_8001BF90
    if (ctx->r2 != 0) {
        // 0x8001BF78: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001BF90;
    }
    // 0x8001BF78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BF7C: ori         $a0, $zero, 0xA1B8
    ctx->r4 = 0 | 0XA1B8;
    // 0x8001BF80: bne         $a0, $a1, L_8001BF90
    if (ctx->r4 != ctx->r5) {
        // 0x8001BF84: nop
    
            goto L_8001BF90;
    }
    // 0x8001BF84: nop

    // 0x8001BF88: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BF8C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BF90:
    // 0x8001BF90: bne         $v0, $at, L_8001BFA8
    if (ctx->r2 != ctx->r1) {
        // 0x8001BF94: ori         $a0, $zero, 0xA1B8
        ctx->r4 = 0 | 0XA1B8;
            goto L_8001BFA8;
    }
    // 0x8001BF94: ori         $a0, $zero, 0xA1B8
    ctx->r4 = 0 | 0XA1B8;
    // 0x8001BF98: bne         $a0, $a1, L_8001BFA8
    if (ctx->r4 != ctx->r5) {
        // 0x8001BF9C: nop
    
            goto L_8001BFA8;
    }
    // 0x8001BF9C: nop

    // 0x8001BFA0: addiu       $v1, $v1, -0x6
    ctx->r3 = ADD32(ctx->r3, -0X6);
    // 0x8001BFA4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BFA8:
    // 0x8001BFA8: bne         $a2, $v0, L_8001BFC0
    if (ctx->r6 != ctx->r2) {
        // 0x8001BFAC: nop
    
            goto L_8001BFC0;
    }
    // 0x8001BFAC: nop

    // 0x8001BFB0: bne         $a0, $a1, L_8001BFC0
    if (ctx->r4 != ctx->r5) {
        // 0x8001BFB4: nop
    
            goto L_8001BFC0;
    }
    // 0x8001BFB4: nop

    // 0x8001BFB8: addiu       $v1, $v1, -0x6
    ctx->r3 = ADD32(ctx->r3, -0X6);
    // 0x8001BFBC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8001BFC0:
    // 0x8001BFC0: bnel        $a3, $v0, L_8001BFDC
    if (ctx->r7 != ctx->r2) {
        // 0x8001BFC4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001BFDC;
    }
    goto skip_13;
    // 0x8001BFC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_13:
    // 0x8001BFC8: bnel        $a0, $a1, L_8001BFDC
    if (ctx->r4 != ctx->r5) {
        // 0x8001BFCC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001BFDC;
    }
    goto skip_14;
    // 0x8001BFCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_14:
    // 0x8001BFD0: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001BFD4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8001BFD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001BFDC:
    // 0x8001BFDC: jr          $ra
    // 0x8001BFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001BFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001bfe4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001bfe4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BFE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001BFE8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001BFEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BFF0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001BFF4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8001BFF8: addiu       $t7, $t7, 0x4624
    ctx->r15 = ADD32(ctx->r15, 0X4624);
    // 0x8001BFFC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001C000: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8001C004: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8001C008: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8001C00C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001C010: addiu       $t0, $t0, 0x462C
    ctx->r8 = ADD32(ctx->r8, 0X462C);
    // 0x8001C014: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x8001C018: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
    // 0x8001C01C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8001C020: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001C024: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C028: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8001C02C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8001C030: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8001C034: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8001C038: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8001C03C: lbu         $t4, 0x3B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3B);
    // 0x8001C040: sb          $t3, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = ctx->r11;
    // 0x8001C044: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8001C048: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8001C04C: jal         0x8000511C
    // 0x8001C050: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    LOOKUP_FUNC(0x8000511C)(rdram, ctx);
        goto after_0;
    // 0x8001C050: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    after_0:
    // 0x8001C054: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x8001C058: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x8001C05C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8001C060: addu        $a2, $sp, $t7
    ctx->r6 = ADD32(ctx->r29, ctx->r15);
    // 0x8001C064: lbu         $a2, 0x2C($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X2C);
    // 0x8001C068: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8001C06C: addiu       $a1, $a1, 0x77E0
    ctx->r5 = ADD32(ctx->r5, 0X77E0);
    // 0x8001C070: multu       $a2, $t9
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C074: mflo        $t0
    ctx->r8 = lo;
    // 0x8001C078: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x8001C07C: jal         0x80001FE8
    // 0x8001C080: nop

    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_1;
    // 0x8001C080: nop

    after_1:
    // 0x8001C084: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8001C088: beq         $v1, $zero, L_8001C09C
    if (ctx->r3 == 0) {
        // 0x8001C08C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_8001C09C;
    }
    // 0x8001C08C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8001C090:
    // 0x8001C090: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001C094: bne         $v0, $zero, L_8001C090
    if (ctx->r2 != 0) {
        // 0x8001C098: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001C090;
    }
    // 0x8001C098: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001C09C:
    // 0x8001C09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C0A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C0A4: sb          $zero, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = 0;
    // 0x8001C0A8: jr          $ra
    // 0x8001C0AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001C0AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c0b0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c0b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C0B0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001C0B4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001C0B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C0BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C0C0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001C0C4: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8001C0C8: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8001C0CC: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x8001C0D0: addiu       $t7, $t7, 0x4638
    ctx->r15 = ADD32(ctx->r15, 0X4638);
    // 0x8001C0D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001C0D8: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x8001C0DC: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x8001C0E0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8001C0E4: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001C0E8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001C0EC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8001C0F0: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
    // 0x8001C0F4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C0F8: addiu       $t6, $t6, 0x4640
    ctx->r14 = ADD32(ctx->r14, 0X4640);
    // 0x8001C0FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C100: addu        $t9, $v0, $a2
    ctx->r25 = ADD32(ctx->r2, ctx->r6);
    // 0x8001C104: addiu       $t7, $t7, 0x77C0
    ctx->r15 = ADD32(ctx->r15, 0X77C0);
    // 0x8001C108: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001C10C: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x8001C110: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x8001C114: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x8001C118: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8001C11C: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x8001C120: sh          $a3, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r7;
    // 0x8001C124: sb          $a2, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r6;
    // 0x8001C128: addu        $ra, $t6, $t7
    ctx->r31 = ADD32(ctx->r14, ctx->r15);
    // 0x8001C12C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001C130: jal         0x8001BFE4
    // 0x8001C134: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8001BFE4)(rdram, ctx);
        goto after_0;
    // 0x8001C134: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x8001C138: lbu         $a2, 0x83($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X83);
    // 0x8001C13C: lbu         $t5, 0x7B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X7B);
    // 0x8001C140: lhu         $a3, 0x86($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X86);
    // 0x8001C144: addu        $v0, $sp, $a2
    ctx->r2 = ADD32(ctx->r29, ctx->r6);
    // 0x8001C148: andi        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 & 0X1;
    // 0x8001C14C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8001C150: lbu         $v0, 0x64($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X64);
    // 0x8001C154: bne         $t8, $zero, L_8001C3E0
    if (ctx->r24 != 0) {
        // 0x8001C158: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001C3E0;
    }
    // 0x8001C158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C15C: andi        $t9, $a3, 0x1
    ctx->r25 = ctx->r7 & 0X1;
    // 0x8001C160: bne         $t9, $zero, L_8001C29C
    if (ctx->r25 != 0) {
        // 0x8001C164: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8001C29C;
    }
    // 0x8001C164: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001C168: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001C16C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C170: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
L_8001C174:
    // 0x8001C174: blez        $t1, L_8001C288
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C178: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001C288;
    }
    // 0x8001C178: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C17C: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8001C180: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001C184: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001C188: sll         $t8, $t8, 8
    ctx->r24 = S32(ctx->r24 << 8);
    // 0x8001C18C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8001C190: bgez        $s0, L_8001C1A0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001C194: sra         $t6, $s0, 1
        ctx->r14 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8001C1A0;
    }
    // 0x8001C194: sra         $t6, $s0, 1
    ctx->r14 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001C198: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8001C19C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8001C1A0:
    // 0x8001C1A0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001C1A4: addiu       $t7, $t7, 0x51C0
    ctx->r15 = ADD32(ctx->r15, 0X51C0);
    // 0x8001C1A8: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x8001C1AC: addu        $a3, $t9, $t7
    ctx->r7 = ADD32(ctx->r25, ctx->r15);
    // 0x8001C1B0: sll         $t2, $t3, 7
    ctx->r10 = S32(ctx->r11 << 7);
    // 0x8001C1B4: beq         $v0, $zero, L_8001C1FC
    if (ctx->r2 == 0) {
        // 0x8001C1B8: addu        $v1, $ra, $a1
        ctx->r3 = ADD32(ctx->r31, ctx->r5);
            goto L_8001C1FC;
    }
    // 0x8001C1B8: addu        $v1, $ra, $a1
    ctx->r3 = ADD32(ctx->r31, ctx->r5);
    // 0x8001C1BC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001C1C0: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C1C4:
    // 0x8001C1C4: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C1C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C1CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C1D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001C1D4: andi        $t9, $t6, 0x33
    ctx->r25 = ctx->r14 & 0X33;
    // 0x8001C1D8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001C1DC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C1E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C1E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C1E8: andi        $t6, $t7, 0xCC
    ctx->r14 = ctx->r15 & 0XCC;
    // 0x8001C1EC: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C1F0: bne         $t0, $a2, L_8001C1C4
    if (ctx->r8 != ctx->r6) {
        // 0x8001C1F4: sb          $t8, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r24;
            goto L_8001C1C4;
    }
    // 0x8001C1F4: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8001C1F8: beq         $a2, $t1, L_8001C288
    if (ctx->r6 == ctx->r9) {
        // 0x8001C1FC: addu        $a0, $t2, $a2
        ctx->r4 = ADD32(ctx->r10, ctx->r6);
            goto L_8001C288;
    }
L_8001C1FC:
    // 0x8001C1FC: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C200:
    // 0x8001C200: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C204: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C208: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001C20C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001C210: andi        $t6, $t7, 0x33
    ctx->r14 = ctx->r15 & 0X33;
    // 0x8001C214: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001C218: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C21C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001C220: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C224: andi        $t7, $t8, 0xCC
    ctx->r15 = ctx->r24 & 0XCC;
    // 0x8001C228: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8001C22C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8001C230: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001C234: andi        $t7, $t8, 0x33
    ctx->r15 = ctx->r24 & 0X33;
    // 0x8001C238: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8001C23C: lbu         $t9, -0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X3);
    // 0x8001C240: andi        $t8, $t9, 0xCC
    ctx->r24 = ctx->r25 & 0XCC;
    // 0x8001C244: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8001C248: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8001C24C: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x8001C250: andi        $t8, $t9, 0x33
    ctx->r24 = ctx->r25 & 0X33;
    // 0x8001C254: sb          $t8, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r24;
    // 0x8001C258: lbu         $t6, -0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X2);
    // 0x8001C25C: andi        $t9, $t6, 0xCC
    ctx->r25 = ctx->r14 & 0XCC;
    // 0x8001C260: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x8001C264: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8001C268: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x8001C26C: andi        $t9, $t6, 0x33
    ctx->r25 = ctx->r14 & 0X33;
    // 0x8001C270: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
    // 0x8001C274: lbu         $t7, -0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X1);
    // 0x8001C278: andi        $t6, $t7, 0xCC
    ctx->r14 = ctx->r15 & 0XCC;
    // 0x8001C27C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C280: bne         $a2, $t1, L_8001C200
    if (ctx->r6 != ctx->r9) {
        // 0x8001C284: sb          $t8, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r24;
            goto L_8001C200;
    }
    // 0x8001C284: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_8001C288:
    // 0x8001C288: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001C28C: bne         $t3, $t4, L_8001C174
    if (ctx->r11 != ctx->r12) {
        // 0x8001C290: nop
    
            goto L_8001C174;
    }
    // 0x8001C290: nop

    // 0x8001C294: b           L_8001C660
    // 0x8001C298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001C660;
    // 0x8001C298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001C29C:
    // 0x8001C29C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C2A0: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
L_8001C2A4:
    // 0x8001C2A4: blez        $t1, L_8001C3CC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C2A8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001C3CC;
    }
    // 0x8001C2A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C2AC: sra         $t9, $t5, 1
    ctx->r25 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8001C2B0: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8001C2B4: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8001C2B8: sll         $t6, $t6, 8
    ctx->r14 = S32(ctx->r14 << 8);
    // 0x8001C2BC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8001C2C0: bgez        $s0, L_8001C2D0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001C2C4: sra         $t7, $s0, 1
        ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8001C2D0;
    }
    // 0x8001C2C4: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001C2C8: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8001C2CC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8001C2D0:
    // 0x8001C2D0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8001C2D4: addiu       $t9, $t9, 0x51C0
    ctx->r25 = ADD32(ctx->r25, 0X51C0);
    // 0x8001C2D8: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x8001C2DC: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C2E0: sll         $t2, $t3, 7
    ctx->r10 = S32(ctx->r11 << 7);
    // 0x8001C2E4: beq         $v0, $zero, L_8001C330
    if (ctx->r2 == 0) {
        // 0x8001C2E8: addu        $v1, $ra, $a1
        ctx->r3 = ADD32(ctx->r31, ctx->r5);
            goto L_8001C330;
    }
    // 0x8001C2E8: addu        $v1, $ra, $a1
    ctx->r3 = ADD32(ctx->r31, ctx->r5);
    // 0x8001C2EC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001C2F0: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C2F4:
    // 0x8001C2F4: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C2F8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C2FC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C300: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001C304: andi        $t8, $t7, 0x33
    ctx->r24 = ctx->r15 & 0X33;
    // 0x8001C308: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8001C30C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C310: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C314: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C318: andi        $t7, $t9, 0x33
    ctx->r15 = ctx->r25 & 0X33;
    // 0x8001C31C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001C320: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8001C324: bne         $t0, $a2, L_8001C2F4
    if (ctx->r8 != ctx->r6) {
        // 0x8001C328: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_8001C2F4;
    }
    // 0x8001C328: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001C32C: beq         $a2, $t1, L_8001C3CC
    if (ctx->r6 == ctx->r9) {
        // 0x8001C330: addu        $a0, $t2, $a2
        ctx->r4 = ADD32(ctx->r10, ctx->r6);
            goto L_8001C3CC;
    }
L_8001C330:
    // 0x8001C330: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C334:
    // 0x8001C334: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C338: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C33C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001C340: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001C344: andi        $t6, $t7, 0x33
    ctx->r14 = ctx->r15 & 0X33;
    // 0x8001C348: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001C34C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C350: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001C354: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C358: andi        $t7, $t9, 0x33
    ctx->r15 = ctx->r25 & 0X33;
    // 0x8001C35C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001C360: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8001C364: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001C368: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001C36C: andi        $t8, $t7, 0x33
    ctx->r24 = ctx->r15 & 0X33;
    // 0x8001C370: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8001C374: lbu         $t9, -0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X3);
    // 0x8001C378: andi        $t7, $t9, 0x33
    ctx->r15 = ctx->r25 & 0X33;
    // 0x8001C37C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001C380: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8001C384: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8001C388: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8001C38C: andi        $t6, $t7, 0x33
    ctx->r14 = ctx->r15 & 0X33;
    // 0x8001C390: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x8001C394: lbu         $t9, -0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X2);
    // 0x8001C398: andi        $t7, $t9, 0x33
    ctx->r15 = ctx->r25 & 0X33;
    // 0x8001C39C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001C3A0: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8001C3A4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001C3A8: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x8001C3AC: andi        $t8, $t7, 0x33
    ctx->r24 = ctx->r15 & 0X33;
    // 0x8001C3B0: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    // 0x8001C3B4: lbu         $t9, -0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X1);
    // 0x8001C3B8: andi        $t7, $t9, 0x33
    ctx->r15 = ctx->r25 & 0X33;
    // 0x8001C3BC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001C3C0: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8001C3C4: bne         $a2, $t1, L_8001C334
    if (ctx->r6 != ctx->r9) {
        // 0x8001C3C8: sb          $t9, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r25;
            goto L_8001C334;
    }
    // 0x8001C3C8: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
L_8001C3CC:
    // 0x8001C3CC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001C3D0: bne         $t3, $t4, L_8001C2A4
    if (ctx->r11 != ctx->r12) {
        // 0x8001C3D4: nop
    
            goto L_8001C2A4;
    }
    // 0x8001C3D4: nop

    // 0x8001C3D8: b           L_8001C660
    // 0x8001C3DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001C660;
    // 0x8001C3DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001C3E0:
    // 0x8001C3E0: andi        $t7, $a3, 0x1
    ctx->r15 = ctx->r7 & 0X1;
    // 0x8001C3E4: bne         $t7, $zero, L_8001C534
    if (ctx->r15 != 0) {
        // 0x8001C3E8: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8001C534;
    }
    // 0x8001C3E8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001C3EC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001C3F0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C3F4: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
L_8001C3F8:
    // 0x8001C3F8: blez        $t1, L_8001C520
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C3FC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001C520;
    }
    // 0x8001C3FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C400: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8001C404: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8001C408: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8001C40C: sll         $t9, $t9, 8
    ctx->r25 = S32(ctx->r25 << 8);
    // 0x8001C410: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8001C414: bgez        $s0, L_8001C424
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001C418: sra         $t8, $s0, 1
        ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8001C424;
    }
    // 0x8001C418: sra         $t8, $s0, 1
    ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001C41C: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8001C420: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8001C424:
    // 0x8001C424: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C428: addiu       $t6, $t6, 0x51C0
    ctx->r14 = ADD32(ctx->r14, 0X51C0);
    // 0x8001C42C: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x8001C430: addu        $a3, $t7, $t6
    ctx->r7 = ADD32(ctx->r15, ctx->r14);
    // 0x8001C434: sll         $t2, $t3, 7
    ctx->r10 = S32(ctx->r11 << 7);
    // 0x8001C438: beq         $v0, $zero, L_8001C484
    if (ctx->r2 == 0) {
        // 0x8001C43C: addu        $v1, $ra, $a1
        ctx->r3 = ADD32(ctx->r31, ctx->r5);
            goto L_8001C484;
    }
    // 0x8001C43C: addu        $v1, $ra, $a1
    ctx->r3 = ADD32(ctx->r31, ctx->r5);
    // 0x8001C440: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001C444: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C448:
    // 0x8001C448: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C44C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C450: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C454: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001C458: andi        $t7, $t8, 0xCC
    ctx->r15 = ctx->r24 & 0XCC;
    // 0x8001C45C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8001C460: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C464: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C468: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C46C: andi        $t8, $t6, 0xCC
    ctx->r24 = ctx->r14 & 0XCC;
    // 0x8001C470: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8001C474: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001C478: bne         $t0, $a2, L_8001C448
    if (ctx->r8 != ctx->r6) {
        // 0x8001C47C: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_8001C448;
    }
    // 0x8001C47C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001C480: beq         $a2, $t1, L_8001C520
    if (ctx->r6 == ctx->r9) {
        // 0x8001C484: addu        $a0, $t2, $a2
        ctx->r4 = ADD32(ctx->r10, ctx->r6);
            goto L_8001C520;
    }
L_8001C484:
    // 0x8001C484: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C488:
    // 0x8001C488: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C48C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C490: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001C494: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001C498: andi        $t9, $t8, 0xCC
    ctx->r25 = ctx->r24 & 0XCC;
    // 0x8001C49C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001C4A0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C4A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001C4A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C4AC: andi        $t8, $t6, 0xCC
    ctx->r24 = ctx->r14 & 0XCC;
    // 0x8001C4B0: sra         $t7, $t8, 2
    ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8001C4B4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8001C4B8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8001C4BC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001C4C0: andi        $t7, $t8, 0xCC
    ctx->r15 = ctx->r24 & 0XCC;
    // 0x8001C4C4: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8001C4C8: lbu         $t6, -0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X3);
    // 0x8001C4CC: andi        $t8, $t6, 0xCC
    ctx->r24 = ctx->r14 & 0XCC;
    // 0x8001C4D0: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8001C4D4: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x8001C4D8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001C4DC: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x8001C4E0: andi        $t9, $t8, 0xCC
    ctx->r25 = ctx->r24 & 0XCC;
    // 0x8001C4E4: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x8001C4E8: lbu         $t6, -0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X2);
    // 0x8001C4EC: andi        $t8, $t6, 0xCC
    ctx->r24 = ctx->r14 & 0XCC;
    // 0x8001C4F0: sra         $t7, $t8, 2
    ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8001C4F4: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x8001C4F8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8001C4FC: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x8001C500: andi        $t7, $t8, 0xCC
    ctx->r15 = ctx->r24 & 0XCC;
    // 0x8001C504: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    // 0x8001C508: lbu         $t6, -0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X1);
    // 0x8001C50C: andi        $t8, $t6, 0xCC
    ctx->r24 = ctx->r14 & 0XCC;
    // 0x8001C510: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8001C514: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001C518: bne         $a2, $t1, L_8001C488
    if (ctx->r6 != ctx->r9) {
        // 0x8001C51C: sb          $t6, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r14;
            goto L_8001C488;
    }
    // 0x8001C51C: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
L_8001C520:
    // 0x8001C520: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001C524: bne         $t3, $t4, L_8001C3F8
    if (ctx->r11 != ctx->r12) {
        // 0x8001C528: nop
    
            goto L_8001C3F8;
    }
    // 0x8001C528: nop

    // 0x8001C52C: b           L_8001C660
    // 0x8001C530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001C660;
    // 0x8001C530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001C534:
    // 0x8001C534: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C538: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
L_8001C53C:
    // 0x8001C53C: blez        $t1, L_8001C650
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C540: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001C650;
    }
    // 0x8001C540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C544: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8001C548: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8001C54C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8001C550: sll         $t9, $t9, 8
    ctx->r25 = S32(ctx->r25 << 8);
    // 0x8001C554: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8001C558: bgez        $s0, L_8001C568
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001C55C: sra         $t8, $s0, 1
        ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8001C568;
    }
    // 0x8001C55C: sra         $t8, $s0, 1
    ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001C560: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8001C564: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8001C568:
    // 0x8001C568: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C56C: addiu       $t7, $t7, 0x51C0
    ctx->r15 = ADD32(ctx->r15, 0X51C0);
    // 0x8001C570: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x8001C574: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8001C578: sll         $t2, $t3, 7
    ctx->r10 = S32(ctx->r11 << 7);
    // 0x8001C57C: beq         $v0, $zero, L_8001C5C4
    if (ctx->r2 == 0) {
        // 0x8001C580: addu        $v1, $ra, $a1
        ctx->r3 = ADD32(ctx->r31, ctx->r5);
            goto L_8001C5C4;
    }
    // 0x8001C580: addu        $v1, $ra, $a1
    ctx->r3 = ADD32(ctx->r31, ctx->r5);
    // 0x8001C584: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001C588: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C58C:
    // 0x8001C58C: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C590: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C594: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C598: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001C59C: andi        $t6, $t8, 0xCC
    ctx->r14 = ctx->r24 & 0XCC;
    // 0x8001C5A0: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001C5A4: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C5A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C5AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C5B0: andi        $t8, $t7, 0x33
    ctx->r24 = ctx->r15 & 0X33;
    // 0x8001C5B4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001C5B8: bne         $t0, $a2, L_8001C58C
    if (ctx->r8 != ctx->r6) {
        // 0x8001C5BC: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_8001C58C;
    }
    // 0x8001C5BC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001C5C0: beq         $a2, $t1, L_8001C650
    if (ctx->r6 == ctx->r9) {
        // 0x8001C5C4: addu        $a0, $t2, $a2
        ctx->r4 = ADD32(ctx->r10, ctx->r6);
            goto L_8001C650;
    }
L_8001C5C4:
    // 0x8001C5C4: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
L_8001C5C8:
    // 0x8001C5C8: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8001C5CC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001C5D0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001C5D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001C5D8: andi        $t8, $t7, 0xCC
    ctx->r24 = ctx->r15 & 0XCC;
    // 0x8001C5DC: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8001C5E0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001C5E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001C5E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C5EC: andi        $t7, $t9, 0x33
    ctx->r15 = ctx->r25 & 0X33;
    // 0x8001C5F0: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8001C5F4: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8001C5F8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001C5FC: andi        $t7, $t9, 0xCC
    ctx->r15 = ctx->r25 & 0XCC;
    // 0x8001C600: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8001C604: lbu         $t6, -0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X3);
    // 0x8001C608: andi        $t9, $t6, 0x33
    ctx->r25 = ctx->r14 & 0X33;
    // 0x8001C60C: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x8001C610: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8001C614: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8001C618: andi        $t9, $t6, 0xCC
    ctx->r25 = ctx->r14 & 0XCC;
    // 0x8001C61C: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x8001C620: lbu         $t8, -0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X2);
    // 0x8001C624: andi        $t6, $t8, 0x33
    ctx->r14 = ctx->r24 & 0X33;
    // 0x8001C628: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x8001C62C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8001C630: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x8001C634: andi        $t6, $t8, 0xCC
    ctx->r14 = ctx->r24 & 0XCC;
    // 0x8001C638: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x8001C63C: lbu         $t7, -0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X1);
    // 0x8001C640: andi        $t8, $t7, 0x33
    ctx->r24 = ctx->r15 & 0X33;
    // 0x8001C644: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001C648: bne         $a2, $t1, L_8001C5C8
    if (ctx->r6 != ctx->r9) {
        // 0x8001C64C: sb          $t9, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r25;
            goto L_8001C5C8;
    }
    // 0x8001C64C: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
L_8001C650:
    // 0x8001C650: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001C654: bne         $t3, $t4, L_8001C53C
    if (ctx->r11 != ctx->r12) {
        // 0x8001C658: nop
    
            goto L_8001C53C;
    }
    // 0x8001C658: nop

    // 0x8001C65C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001C660:
    // 0x8001C660: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C664: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001C668: jr          $ra
    // 0x8001C66C: nop

    return;
    // 0x8001C66C: nop

;}
RECOMP_FUNC void FUN_8001c670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C670: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001C674: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C678: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001C67C: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x8001C680: addiu       $t6, $t6, 0x4648
    ctx->r14 = ADD32(ctx->r14, 0X4648);
    // 0x8001C684: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C688: addiu       $t0, $t6, 0x54
    ctx->r8 = ADD32(ctx->r14, 0X54);
    // 0x8001C68C: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8001C690:
    // 0x8001C690: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C694: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001C698: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8001C69C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8001C6A0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8001C6A4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8001C6A8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8001C6AC: bne         $t6, $t0, L_8001C690
    if (ctx->r14 != ctx->r8) {
        // 0x8001C6B0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8001C690;
    }
    // 0x8001C6B0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8001C6B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C6B8: slti        $at, $a0, 0x5C
    ctx->r1 = SIGNED(ctx->r4) < 0X5C ? 1 : 0;
    // 0x8001C6BC: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C6C0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001C6C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001C6C8: beq         $at, $zero, L_8001C6D8
    if (ctx->r1 == 0) {
        // 0x8001C6CC: sw          $t7, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r15;
            goto L_8001C6D8;
    }
    // 0x8001C6CC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8001C6D0: b           L_8001C6DC
    // 0x8001C6D4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
        goto L_8001C6DC;
    // 0x8001C6D4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
L_8001C6D8:
    // 0x8001C6D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001C6DC:
    // 0x8001C6DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001C6E0: jr          $ra
    // 0x8001C6E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8001C6E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c6e8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c6e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C6E8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001C6EC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C6F0: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001C6F4: addiu       $t6, $t6, 0x46A4
    ctx->r14 = ADD32(ctx->r14, 0X46A4);
    // 0x8001C6F8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C6FC: addiu       $v0, $sp, 0x4
    ctx->r2 = ADD32(ctx->r29, 0X4);
    // 0x8001C700: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C704: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001C708: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001C70C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001C710: beq         $at, $zero, L_8001C724
    if (ctx->r1 == 0) {
        // 0x8001C714: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_8001C724;
    }
    // 0x8001C714: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001C718: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C71C: b           L_8001C728
    // 0x8001C720: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
        goto L_8001C728;
    // 0x8001C720: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
L_8001C724:
    // 0x8001C724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001C728:
    // 0x8001C728: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001C72C: jr          $ra
    // 0x8001C730: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001C730: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c734(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C734: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001C738: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C73C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8001C740: addiu       $v0, $sp, 0x4
    ctx->r2 = ADD32(ctx->r29, 0X4);
    // 0x8001C744: addiu       $t6, $t6, 0x46AC
    ctx->r14 = ADD32(ctx->r14, 0X46AC);
    // 0x8001C748: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C74C: addiu       $t0, $t6, 0x48
    ctx->r8 = ADD32(ctx->r14, 0X48);
    // 0x8001C750: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8001C754:
    // 0x8001C754: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C758: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001C75C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8001C760: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8001C764: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8001C768: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8001C76C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8001C770: bne         $t6, $t0, L_8001C754
    if (ctx->r14 != ctx->r8) {
        // 0x8001C774: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8001C754;
    }
    // 0x8001C774: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8001C778: lwr         $t8, 0x2($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X2);
    // 0x8001C77C: slti        $at, $a0, 0x4B
    ctx->r1 = SIGNED(ctx->r4) < 0X4B ? 1 : 0;
    // 0x8001C780: beq         $at, $zero, L_8001C794
    if (ctx->r1 == 0) {
        // 0x8001C784: swr         $t8, 0x2($t9)
        do_swr(rdram, 0X2, ctx->r25, ctx->r24);
            goto L_8001C794;
    }
    // 0x8001C784: swr         $t8, 0x2($t9)
    do_swr(rdram, 0X2, ctx->r25, ctx->r24);
    // 0x8001C788: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C78C: b           L_8001C798
    // 0x8001C790: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
        goto L_8001C798;
    // 0x8001C790: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
L_8001C794:
    // 0x8001C794: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001C798:
    // 0x8001C798: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001C79C: jr          $ra
    // 0x8001C7A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8001C7A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c7a4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c7a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C7A4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001C7A8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C7AC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001C7B0: addiu       $v0, $sp, 0x4
    ctx->r2 = ADD32(ctx->r29, 0X4);
    // 0x8001C7B4: addiu       $t6, $t6, 0x46F8
    ctx->r14 = ADD32(ctx->r14, 0X46F8);
    // 0x8001C7B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C7BC: addiu       $t0, $t6, 0x48
    ctx->r8 = ADD32(ctx->r14, 0X48);
    // 0x8001C7C0: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8001C7C4:
    // 0x8001C7C4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C7C8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001C7CC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8001C7D0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8001C7D4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8001C7D8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8001C7DC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8001C7E0: bne         $t6, $t0, L_8001C7C4
    if (ctx->r14 != ctx->r8) {
        // 0x8001C7E4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8001C7C4;
    }
    // 0x8001C7E4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8001C7E8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C7EC: slti        $at, $a0, 0x53
    ctx->r1 = SIGNED(ctx->r4) < 0X53 ? 1 : 0;
    // 0x8001C7F0: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C7F4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001C7F8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001C7FC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8001C800: lwr         $t8, 0xA($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XA);
    // 0x8001C804: beq         $at, $zero, L_8001C814
    if (ctx->r1 == 0) {
        // 0x8001C808: swr         $t8, 0xA($t9)
        do_swr(rdram, 0XA, ctx->r25, ctx->r24);
            goto L_8001C814;
    }
    // 0x8001C808: swr         $t8, 0xA($t9)
    do_swr(rdram, 0XA, ctx->r25, ctx->r24);
    // 0x8001C80C: b           L_8001C818
    // 0x8001C810: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
        goto L_8001C818;
    // 0x8001C810: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
L_8001C814:
    // 0x8001C814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001C818:
    // 0x8001C818: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001C81C: jr          $ra
    // 0x8001C820: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001C820: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c824(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C824: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001C828: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C82C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001C830: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x8001C834: addiu       $t6, $t6, 0x474C
    ctx->r14 = ADD32(ctx->r14, 0X474C);
    // 0x8001C838: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C83C: addiu       $t0, $t6, 0x54
    ctx->r8 = ADD32(ctx->r14, 0X54);
    // 0x8001C840: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8001C844:
    // 0x8001C844: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001C848: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001C84C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8001C850: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8001C854: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8001C858: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8001C85C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8001C860: bne         $t6, $t0, L_8001C844
    if (ctx->r14 != ctx->r8) {
        // 0x8001C864: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8001C844;
    }
    // 0x8001C864: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8001C868: slti        $at, $a0, 0x54
    ctx->r1 = SIGNED(ctx->r4) < 0X54 ? 1 : 0;
    // 0x8001C86C: beq         $at, $zero, L_8001C87C
    if (ctx->r1 == 0) {
        // 0x8001C870: addu        $t1, $v0, $a0
        ctx->r9 = ADD32(ctx->r2, ctx->r4);
            goto L_8001C87C;
    }
    // 0x8001C870: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C874: b           L_8001C880
    // 0x8001C878: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
        goto L_8001C880;
    // 0x8001C878: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
L_8001C87C:
    // 0x8001C87C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001C880:
    // 0x8001C880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001C884: jr          $ra
    // 0x8001C888: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001C888: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c88c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c88c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C88C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001C890: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001C894: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8001C898: sra         $a1, $a0, 8
    ctx->r5 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8001C89C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C8A0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001C8A4: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8001C8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C8AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C8B0: bne         $a1, $at, L_8001C8D0
    if (ctx->r5 != ctx->r1) {
        // 0x8001C8B4: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8001C8D0;
    }
    // 0x8001C8B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001C8B8: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001C8BC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C8C0: jal         0x8001C670
    // 0x8001C8C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001C670)(rdram, ctx);
        goto after_0;
    // 0x8001C8C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001C8C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001C8CC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C8D0:
    // 0x8001C8D0: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x8001C8D4: bne         $a1, $at, L_8001C8F4
    if (ctx->r5 != ctx->r1) {
        // 0x8001C8D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001C8F4;
    }
    // 0x8001C8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C8DC: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001C8E0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C8E4: jal         0x8001C6E8
    // 0x8001C8E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001C6E8)(rdram, ctx);
        goto after_1;
    // 0x8001C8E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001C8EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001C8F0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C8F4:
    // 0x8001C8F4: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x8001C8F8: bne         $a1, $at, L_8001C918
    if (ctx->r5 != ctx->r1) {
        // 0x8001C8FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001C918;
    }
    // 0x8001C8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C900: addiu       $a0, $a0, -0xB0
    ctx->r4 = ADD32(ctx->r4, -0XB0);
    // 0x8001C904: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C908: jal         0x8001C734
    // 0x8001C90C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001C734)(rdram, ctx);
        goto after_2;
    // 0x8001C90C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8001C910: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001C914: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C918:
    // 0x8001C918: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x8001C91C: bne         $a1, $at, L_8001C93C
    if (ctx->r5 != ctx->r1) {
        // 0x8001C920: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001C93C;
    }
    // 0x8001C920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C924: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001C928: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C92C: jal         0x8001C7A4
    // 0x8001C930: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001C7A4)(rdram, ctx);
        goto after_3;
    // 0x8001C930: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x8001C934: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001C938: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C93C:
    // 0x8001C93C: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x8001C940: bne         $a1, $at, L_8001C958
    if (ctx->r5 != ctx->r1) {
        // 0x8001C944: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001C958;
    }
    // 0x8001C944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C948: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001C94C: jal         0x8001C824
    // 0x8001C950: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x8001C824)(rdram, ctx);
        goto after_4;
    // 0x8001C950: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_4:
    // 0x8001C954: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C958:
    // 0x8001C958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C95C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001C964: jr          $ra
    // 0x8001C968: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C968: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001c96c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001c96c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C96C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001C970: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001C974: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8001C978: sra         $a2, $a0, 8
    ctx->r6 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8001C97C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001C980: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8001C984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C988: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C98C: bne         $a2, $at, L_8001C9B4
    if (ctx->r6 != ctx->r1) {
        // 0x8001C990: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8001C9B4;
    }
    // 0x8001C990: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001C994: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001C998: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C99C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8001C9A0: jal         0x8001C670
    // 0x8001C9A4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C670)(rdram, ctx);
        goto after_0;
    // 0x8001C9A4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001C9A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001C9AC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C9B0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C9B4:
    // 0x8001C9B4: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x8001C9B8: bne         $a2, $at, L_8001C9E0
    if (ctx->r6 != ctx->r1) {
        // 0x8001C9BC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001C9E0;
    }
    // 0x8001C9BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001C9C0: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001C9C4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C9C8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8001C9CC: jal         0x8001C6E8
    // 0x8001C9D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C6E8)(rdram, ctx);
        goto after_1;
    // 0x8001C9D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8001C9D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001C9D8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C9DC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001C9E0:
    // 0x8001C9E0: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x8001C9E4: bne         $a2, $at, L_8001CA0C
    if (ctx->r6 != ctx->r1) {
        // 0x8001C9E8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001CA0C;
    }
    // 0x8001C9E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001C9EC: addiu       $a0, $a0, -0xB0
    ctx->r4 = ADD32(ctx->r4, -0XB0);
    // 0x8001C9F0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001C9F4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8001C9F8: jal         0x8001C734
    // 0x8001C9FC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C734)(rdram, ctx);
        goto after_2;
    // 0x8001C9FC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8001CA00: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001CA04: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CA08: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001CA0C:
    // 0x8001CA0C: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x8001CA10: bne         $a2, $at, L_8001CA38
    if (ctx->r6 != ctx->r1) {
        // 0x8001CA14: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001CA38;
    }
    // 0x8001CA14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001CA18: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001CA1C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001CA20: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8001CA24: jal         0x8001C7A4
    // 0x8001CA28: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C7A4)(rdram, ctx);
        goto after_3;
    // 0x8001CA28: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_3:
    // 0x8001CA2C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001CA30: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CA34: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001CA38:
    // 0x8001CA38: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x8001CA3C: bne         $a2, $at, L_8001CA64
    if (ctx->r6 != ctx->r1) {
        // 0x8001CA40: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001CA64;
    }
    // 0x8001CA40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001CA44: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001CA48: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001CA4C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8001CA50: jal         0x8001C824
    // 0x8001CA54: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C824)(rdram, ctx);
        goto after_4;
    // 0x8001CA54: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_4:
    // 0x8001CA58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001CA5C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CA60: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8001CA64:
    // 0x8001CA64: slti        $at, $a2, 0xB0
    ctx->r1 = SIGNED(ctx->r6) < 0XB0 ? 1 : 0;
    // 0x8001CA68: bne         $at, $zero, L_8001CE90
    if (ctx->r1 != 0) {
        // 0x8001CA6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001CE90;
    }
    // 0x8001CA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CA70: ori         $at, $zero, 0xBCF3
    ctx->r1 = 0 | 0XBCF3;
    // 0x8001CA74: bnel        $a1, $at, L_8001CA84
    if (ctx->r5 != ctx->r1) {
        // 0x8001CA78: ori         $at, $zero, 0xC5EA
        ctx->r1 = 0 | 0XC5EA;
            goto L_8001CA84;
    }
    goto skip_0;
    // 0x8001CA78: ori         $at, $zero, 0xC5EA
    ctx->r1 = 0 | 0XC5EA;
    skip_0:
    // 0x8001CA7C: addiu       $v1, $zero, 0xFD
    ctx->r3 = ADD32(0, 0XFD);
    // 0x8001CA80: ori         $at, $zero, 0xC5EA
    ctx->r1 = 0 | 0XC5EA;
L_8001CA84:
    // 0x8001CA84: bnel        $a1, $at, L_8001CA94
    if (ctx->r5 != ctx->r1) {
        // 0x8001CA88: ori         $at, $zero, 0xB0EC
        ctx->r1 = 0 | 0XB0EC;
            goto L_8001CA94;
    }
    goto skip_1;
    // 0x8001CA88: ori         $at, $zero, 0xB0EC
    ctx->r1 = 0 | 0XB0EC;
    skip_1:
    // 0x8001CA8C: addiu       $v1, $zero, 0xFE
    ctx->r3 = ADD32(0, 0XFE);
    // 0x8001CA90: ori         $at, $zero, 0xB0EC
    ctx->r1 = 0 | 0XB0EC;
L_8001CA94:
    // 0x8001CA94: bnel        $a1, $at, L_8001CAA4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CA98: ori         $at, $zero, 0xCBDC
        ctx->r1 = 0 | 0XCBDC;
            goto L_8001CAA4;
    }
    goto skip_2;
    // 0x8001CA98: ori         $at, $zero, 0xCBDC
    ctx->r1 = 0 | 0XCBDC;
    skip_2:
    // 0x8001CA9C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8001CAA0: ori         $at, $zero, 0xCBDC
    ctx->r1 = 0 | 0XCBDC;
L_8001CAA4:
    // 0x8001CAA4: bnel        $a1, $at, L_8001CAB4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CAA8: ori         $at, $zero, 0xC7D8
        ctx->r1 = 0 | 0XC7D8;
            goto L_8001CAB4;
    }
    goto skip_3;
    // 0x8001CAA8: ori         $at, $zero, 0xC7D8
    ctx->r1 = 0 | 0XC7D8;
    skip_3:
    // 0x8001CAAC: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x8001CAB0: ori         $at, $zero, 0xC7D8
    ctx->r1 = 0 | 0XC7D8;
L_8001CAB4:
    // 0x8001CAB4: bnel        $a1, $at, L_8001CAC4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CAB8: ori         $at, $zero, 0xC9E9
        ctx->r1 = 0 | 0XC9E9;
            goto L_8001CAC4;
    }
    goto skip_4;
    // 0x8001CAB8: ori         $at, $zero, 0xC9E9
    ctx->r1 = 0 | 0XC9E9;
    skip_4:
    // 0x8001CABC: addiu       $v1, $zero, 0x101
    ctx->r3 = ADD32(0, 0X101);
    // 0x8001CAC0: ori         $at, $zero, 0xC9E9
    ctx->r1 = 0 | 0XC9E9;
L_8001CAC4:
    // 0x8001CAC4: bnel        $a1, $at, L_8001CAD4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CAC8: ori         $at, $zero, 0xC8BF
        ctx->r1 = 0 | 0XC8BF;
            goto L_8001CAD4;
    }
    goto skip_5;
    // 0x8001CAC8: ori         $at, $zero, 0xC8BF
    ctx->r1 = 0 | 0XC8BF;
    skip_5:
    // 0x8001CACC: addiu       $v1, $zero, 0x102
    ctx->r3 = ADD32(0, 0X102);
    // 0x8001CAD0: ori         $at, $zero, 0xC8BF
    ctx->r1 = 0 | 0XC8BF;
L_8001CAD4:
    // 0x8001CAD4: bnel        $a1, $at, L_8001CAE4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CAD8: ori         $at, $zero, 0xBFC8
        ctx->r1 = 0 | 0XBFC8;
            goto L_8001CAE4;
    }
    goto skip_6;
    // 0x8001CAD8: ori         $at, $zero, 0xBFC8
    ctx->r1 = 0 | 0XBFC8;
    skip_6:
    // 0x8001CADC: addiu       $v1, $zero, 0x103
    ctx->r3 = ADD32(0, 0X103);
    // 0x8001CAE0: ori         $at, $zero, 0xBFC8
    ctx->r1 = 0 | 0XBFC8;
L_8001CAE4:
    // 0x8001CAE4: bnel        $a1, $at, L_8001CAF4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CAE8: ori         $at, $zero, 0xB5D5
        ctx->r1 = 0 | 0XB5D5;
            goto L_8001CAF4;
    }
    goto skip_7;
    // 0x8001CAE8: ori         $at, $zero, 0xB5D5
    ctx->r1 = 0 | 0XB5D5;
    skip_7:
    // 0x8001CAEC: addiu       $v1, $zero, 0x104
    ctx->r3 = ADD32(0, 0X104);
    // 0x8001CAF0: ori         $at, $zero, 0xB5D5
    ctx->r1 = 0 | 0XB5D5;
L_8001CAF4:
    // 0x8001CAF4: bnel        $a1, $at, L_8001CB04
    if (ctx->r5 != ctx->r1) {
        // 0x8001CAF8: ori         $at, $zero, 0xB8AA
        ctx->r1 = 0 | 0XB8AA;
            goto L_8001CB04;
    }
    goto skip_8;
    // 0x8001CAF8: ori         $at, $zero, 0xB8AA
    ctx->r1 = 0 | 0XB8AA;
    skip_8:
    // 0x8001CAFC: addiu       $v1, $zero, 0x105
    ctx->r3 = ADD32(0, 0X105);
    // 0x8001CB00: ori         $at, $zero, 0xB8AA
    ctx->r1 = 0 | 0XB8AA;
L_8001CB04:
    // 0x8001CB04: bnel        $a1, $at, L_8001CB14
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB08: ori         $at, $zero, 0xBAD5
        ctx->r1 = 0 | 0XBAD5;
            goto L_8001CB14;
    }
    goto skip_9;
    // 0x8001CB08: ori         $at, $zero, 0xBAD5
    ctx->r1 = 0 | 0XBAD5;
    skip_9:
    // 0x8001CB0C: addiu       $v1, $zero, 0x106
    ctx->r3 = ADD32(0, 0X106);
    // 0x8001CB10: ori         $at, $zero, 0xBAD5
    ctx->r1 = 0 | 0XBAD5;
L_8001CB14:
    // 0x8001CB14: bnel        $a1, $at, L_8001CB24
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB18: ori         $at, $zero, 0xB9FC
        ctx->r1 = 0 | 0XB9FC;
            goto L_8001CB24;
    }
    goto skip_10;
    // 0x8001CB18: ori         $at, $zero, 0xB9FC
    ctx->r1 = 0 | 0XB9FC;
    skip_10:
    // 0x8001CB1C: addiu       $v1, $zero, 0x107
    ctx->r3 = ADD32(0, 0X107);
    // 0x8001CB20: ori         $at, $zero, 0xB9FC
    ctx->r1 = 0 | 0XB9FC;
L_8001CB24:
    // 0x8001CB24: bnel        $a1, $at, L_8001CB34
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB28: ori         $at, $zero, 0xBFE2
        ctx->r1 = 0 | 0XBFE2;
            goto L_8001CB34;
    }
    goto skip_11;
    // 0x8001CB28: ori         $at, $zero, 0xBFE2
    ctx->r1 = 0 | 0XBFE2;
    skip_11:
    // 0x8001CB2C: addiu       $v1, $zero, 0x108
    ctx->r3 = ADD32(0, 0X108);
    // 0x8001CB30: ori         $at, $zero, 0xBFE2
    ctx->r1 = 0 | 0XBFE2;
L_8001CB34:
    // 0x8001CB34: bnel        $a1, $at, L_8001CB44
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB38: ori         $at, $zero, 0xC4BE
        ctx->r1 = 0 | 0XC4BE;
            goto L_8001CB44;
    }
    goto skip_12;
    // 0x8001CB38: ori         $at, $zero, 0xC4BE
    ctx->r1 = 0 | 0XC4BE;
    skip_12:
    // 0x8001CB3C: addiu       $v1, $zero, 0x109
    ctx->r3 = ADD32(0, 0X109);
    // 0x8001CB40: ori         $at, $zero, 0xC4BE
    ctx->r1 = 0 | 0XC4BE;
L_8001CB44:
    // 0x8001CB44: bnel        $a1, $at, L_8001CB54
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB48: ori         $at, $zero, 0xC4B7
        ctx->r1 = 0 | 0XC4B7;
            goto L_8001CB54;
    }
    goto skip_13;
    // 0x8001CB48: ori         $at, $zero, 0xC4B7
    ctx->r1 = 0 | 0XC4B7;
    skip_13:
    // 0x8001CB4C: addiu       $v1, $zero, 0x10A
    ctx->r3 = ADD32(0, 0X10A);
    // 0x8001CB50: ori         $at, $zero, 0xC4B7
    ctx->r1 = 0 | 0XC4B7;
L_8001CB54:
    // 0x8001CB54: bnel        $a1, $at, L_8001CB64
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB58: ori         $at, $zero, 0xC9A8
        ctx->r1 = 0 | 0XC9A8;
            goto L_8001CB64;
    }
    goto skip_14;
    // 0x8001CB58: ori         $at, $zero, 0xC9A8
    ctx->r1 = 0 | 0XC9A8;
    skip_14:
    // 0x8001CB5C: addiu       $v1, $zero, 0x10B
    ctx->r3 = ADD32(0, 0X10B);
    // 0x8001CB60: ori         $at, $zero, 0xC9A8
    ctx->r1 = 0 | 0XC9A8;
L_8001CB64:
    // 0x8001CB64: bnel        $a1, $at, L_8001CB74
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB68: ori         $at, $zero, 0xC0B5
        ctx->r1 = 0 | 0XC0B5;
            goto L_8001CB74;
    }
    goto skip_15;
    // 0x8001CB68: ori         $at, $zero, 0xC0B5
    ctx->r1 = 0 | 0XC0B5;
    skip_15:
    // 0x8001CB6C: addiu       $v1, $zero, 0x10C
    ctx->r3 = ADD32(0, 0X10C);
    // 0x8001CB70: ori         $at, $zero, 0xC0B5
    ctx->r1 = 0 | 0XC0B5;
L_8001CB74:
    // 0x8001CB74: bnel        $a1, $at, L_8001CB84
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB78: ori         $at, $zero, 0xCCCC
        ctx->r1 = 0 | 0XCCCC;
            goto L_8001CB84;
    }
    goto skip_16;
    // 0x8001CB78: ori         $at, $zero, 0xCCCC
    ctx->r1 = 0 | 0XCCCC;
    skip_16:
    // 0x8001CB7C: addiu       $v1, $zero, 0x10D
    ctx->r3 = ADD32(0, 0X10D);
    // 0x8001CB80: ori         $at, $zero, 0xCCCC
    ctx->r1 = 0 | 0XCCCC;
L_8001CB84:
    // 0x8001CB84: bnel        $a1, $at, L_8001CB94
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB88: ori         $at, $zero, 0xB8C7
        ctx->r1 = 0 | 0XB8C7;
            goto L_8001CB94;
    }
    goto skip_17;
    // 0x8001CB88: ori         $at, $zero, 0xB8C7
    ctx->r1 = 0 | 0XB8C7;
    skip_17:
    // 0x8001CB8C: addiu       $v1, $zero, 0x10E
    ctx->r3 = ADD32(0, 0X10E);
    // 0x8001CB90: ori         $at, $zero, 0xB8C7
    ctx->r1 = 0 | 0XB8C7;
L_8001CB94:
    // 0x8001CB94: bnel        $a1, $at, L_8001CBA4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB98: ori         $at, $zero, 0xBDBD
        ctx->r1 = 0 | 0XBDBD;
            goto L_8001CBA4;
    }
    goto skip_18;
    // 0x8001CB98: ori         $at, $zero, 0xBDBD
    ctx->r1 = 0 | 0XBDBD;
    skip_18:
    // 0x8001CB9C: addiu       $v1, $zero, 0x10F
    ctx->r3 = ADD32(0, 0X10F);
    // 0x8001CBA0: ori         $at, $zero, 0xBDBD
    ctx->r1 = 0 | 0XBDBD;
L_8001CBA4:
    // 0x8001CBA4: bnel        $a1, $at, L_8001CBB4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CBA8: ori         $at, $zero, 0xBBFA
        ctx->r1 = 0 | 0XBBFA;
            goto L_8001CBB4;
    }
    goto skip_19;
    // 0x8001CBA8: ori         $at, $zero, 0xBBFA
    ctx->r1 = 0 | 0XBBFA;
    skip_19:
    // 0x8001CBAC: addiu       $v1, $zero, 0x110
    ctx->r3 = ADD32(0, 0X110);
    // 0x8001CBB0: ori         $at, $zero, 0xBBFA
    ctx->r1 = 0 | 0XBBFA;
L_8001CBB4:
    // 0x8001CBB4: bnel        $a1, $at, L_8001CBC4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CBB8: ori         $at, $zero, 0xCFC6
        ctx->r1 = 0 | 0XCFC6;
            goto L_8001CBC4;
    }
    goto skip_20;
    // 0x8001CBB8: ori         $at, $zero, 0xCFC6
    ctx->r1 = 0 | 0XCFC6;
    skip_20:
    // 0x8001CBBC: addiu       $v1, $zero, 0x111
    ctx->r3 = ADD32(0, 0X111);
    // 0x8001CBC0: ori         $at, $zero, 0xCFC6
    ctx->r1 = 0 | 0XCFC6;
L_8001CBC4:
    // 0x8001CBC4: bnel        $a1, $at, L_8001CBD4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CBC8: ori         $at, $zero, 0xBDB3
        ctx->r1 = 0 | 0XBDB3;
            goto L_8001CBD4;
    }
    goto skip_21;
    // 0x8001CBC8: ori         $at, $zero, 0xBDB3
    ctx->r1 = 0 | 0XBDB3;
    skip_21:
    // 0x8001CBCC: addiu       $v1, $zero, 0x112
    ctx->r3 = ADD32(0, 0X112);
    // 0x8001CBD0: ori         $at, $zero, 0xBDB3
    ctx->r1 = 0 | 0XBDB3;
L_8001CBD4:
    // 0x8001CBD4: bnel        $a1, $at, L_8001CBE4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CBD8: ori         $at, $zero, 0xCDE1
        ctx->r1 = 0 | 0XCDE1;
            goto L_8001CBE4;
    }
    goto skip_22;
    // 0x8001CBD8: ori         $at, $zero, 0xCDE1
    ctx->r1 = 0 | 0XCDE1;
    skip_22:
    // 0x8001CBDC: addiu       $v1, $zero, 0x113
    ctx->r3 = ADD32(0, 0X113);
    // 0x8001CBE0: ori         $at, $zero, 0xCDE1
    ctx->r1 = 0 | 0XCDE1;
L_8001CBE4:
    // 0x8001CBE4: bnel        $a1, $at, L_8001CBF4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CBE8: ori         $at, $zero, 0xBCE8
        ctx->r1 = 0 | 0XBCE8;
            goto L_8001CBF4;
    }
    goto skip_23;
    // 0x8001CBE8: ori         $at, $zero, 0xBCE8
    ctx->r1 = 0 | 0XBCE8;
    skip_23:
    // 0x8001CBEC: addiu       $v1, $zero, 0x114
    ctx->r3 = ADD32(0, 0X114);
    // 0x8001CBF0: ori         $at, $zero, 0xBCE8
    ctx->r1 = 0 | 0XBCE8;
L_8001CBF4:
    // 0x8001CBF4: bnel        $a1, $at, L_8001CC04
    if (ctx->r5 != ctx->r1) {
        // 0x8001CBF8: ori         $at, $zero, 0xC0DA
        ctx->r1 = 0 | 0XC0DA;
            goto L_8001CC04;
    }
    goto skip_24;
    // 0x8001CBF8: ori         $at, $zero, 0xC0DA
    ctx->r1 = 0 | 0XC0DA;
    skip_24:
    // 0x8001CBFC: addiu       $v1, $zero, 0x115
    ctx->r3 = ADD32(0, 0X115);
    // 0x8001CC00: ori         $at, $zero, 0xC0DA
    ctx->r1 = 0 | 0XC0DA;
L_8001CC04:
    // 0x8001CC04: bnel        $a1, $at, L_8001CC14
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC08: ori         $at, $zero, 0xCAD6
        ctx->r1 = 0 | 0XCAD6;
            goto L_8001CC14;
    }
    goto skip_25;
    // 0x8001CC08: ori         $at, $zero, 0xCAD6
    ctx->r1 = 0 | 0XCAD6;
    skip_25:
    // 0x8001CC0C: addiu       $v1, $zero, 0x116
    ctx->r3 = ADD32(0, 0X116);
    // 0x8001CC10: ori         $at, $zero, 0xCAD6
    ctx->r1 = 0 | 0XCAD6;
L_8001CC14:
    // 0x8001CC14: bnel        $a1, $at, L_8001CC24
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC18: ori         $at, $zero, 0xC3E6
        ctx->r1 = 0 | 0XC3E6;
            goto L_8001CC24;
    }
    goto skip_26;
    // 0x8001CC18: ori         $at, $zero, 0xC3E6
    ctx->r1 = 0 | 0XC3E6;
    skip_26:
    // 0x8001CC1C: addiu       $v1, $zero, 0x117
    ctx->r3 = ADD32(0, 0X117);
    // 0x8001CC20: ori         $at, $zero, 0xC3E6
    ctx->r1 = 0 | 0XC3E6;
L_8001CC24:
    // 0x8001CC24: bnel        $a1, $at, L_8001CC34
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC28: ori         $at, $zero, 0xB2BC
        ctx->r1 = 0 | 0XB2BC;
            goto L_8001CC34;
    }
    goto skip_27;
    // 0x8001CC28: ori         $at, $zero, 0xB2BC
    ctx->r1 = 0 | 0XB2BC;
    skip_27:
    // 0x8001CC2C: addiu       $v1, $zero, 0x118
    ctx->r3 = ADD32(0, 0X118);
    // 0x8001CC30: ori         $at, $zero, 0xB2BC
    ctx->r1 = 0 | 0XB2BC;
L_8001CC34:
    // 0x8001CC34: bnel        $a1, $at, L_8001CC44
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC38: ori         $at, $zero, 0xC3CA
        ctx->r1 = 0 | 0XC3CA;
            goto L_8001CC44;
    }
    goto skip_28;
    // 0x8001CC38: ori         $at, $zero, 0xC3CA
    ctx->r1 = 0 | 0XC3CA;
    skip_28:
    // 0x8001CC3C: addiu       $v1, $zero, 0x119
    ctx->r3 = ADD32(0, 0X119);
    // 0x8001CC40: ori         $at, $zero, 0xC3CA
    ctx->r1 = 0 | 0XC3CA;
L_8001CC44:
    // 0x8001CC44: bnel        $a1, $at, L_8001CC54
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC48: ori         $at, $zero, 0xBAB8
        ctx->r1 = 0 | 0XBAB8;
            goto L_8001CC54;
    }
    goto skip_29;
    // 0x8001CC48: ori         $at, $zero, 0xBAB8
    ctx->r1 = 0 | 0XBAB8;
    skip_29:
    // 0x8001CC4C: addiu       $v1, $zero, 0x11A
    ctx->r3 = ADD32(0, 0X11A);
    // 0x8001CC50: ori         $at, $zero, 0xBAB8
    ctx->r1 = 0 | 0XBAB8;
L_8001CC54:
    // 0x8001CC54: bnel        $a1, $at, L_8001CC64
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC58: ori         $at, $zero, 0xB1A6
        ctx->r1 = 0 | 0XB1A6;
            goto L_8001CC64;
    }
    goto skip_30;
    // 0x8001CC58: ori         $at, $zero, 0xB1A6
    ctx->r1 = 0 | 0XB1A6;
    skip_30:
    // 0x8001CC5C: addiu       $v1, $zero, 0x11B
    ctx->r3 = ADD32(0, 0X11B);
    // 0x8001CC60: ori         $at, $zero, 0xB1A6
    ctx->r1 = 0 | 0XB1A6;
L_8001CC64:
    // 0x8001CC64: bnel        $a1, $at, L_8001CC74
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC68: ori         $at, $zero, 0xB2A3
        ctx->r1 = 0 | 0XB2A3;
            goto L_8001CC74;
    }
    goto skip_31;
    // 0x8001CC68: ori         $at, $zero, 0xB2A3
    ctx->r1 = 0 | 0XB2A3;
    skip_31:
    // 0x8001CC6C: addiu       $v1, $zero, 0x11C
    ctx->r3 = ADD32(0, 0X11C);
    // 0x8001CC70: ori         $at, $zero, 0xB2A3
    ctx->r1 = 0 | 0XB2A3;
L_8001CC74:
    // 0x8001CC74: bnel        $a1, $at, L_8001CC84
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC78: ori         $at, $zero, 0xCEA2
        ctx->r1 = 0 | 0XCEA2;
            goto L_8001CC84;
    }
    goto skip_32;
    // 0x8001CC78: ori         $at, $zero, 0xCEA2
    ctx->r1 = 0 | 0XCEA2;
    skip_32:
    // 0x8001CC7C: addiu       $v1, $zero, 0x11D
    ctx->r3 = ADD32(0, 0X11D);
    // 0x8001CC80: ori         $at, $zero, 0xCEA2
    ctx->r1 = 0 | 0XCEA2;
L_8001CC84:
    // 0x8001CC84: bnel        $a1, $at, L_8001CC94
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC88: ori         $at, $zero, 0xCFD3
        ctx->r1 = 0 | 0XCFD3;
            goto L_8001CC94;
    }
    goto skip_33;
    // 0x8001CC88: ori         $at, $zero, 0xCFD3
    ctx->r1 = 0 | 0XCFD3;
    skip_33:
    // 0x8001CC8C: addiu       $v1, $zero, 0x11E
    ctx->r3 = ADD32(0, 0X11E);
    // 0x8001CC90: ori         $at, $zero, 0xCFD3
    ctx->r1 = 0 | 0XCFD3;
L_8001CC94:
    // 0x8001CC94: bnel        $a1, $at, L_8001CCA4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CC98: ori         $at, $zero, 0xCDEE
        ctx->r1 = 0 | 0XCDEE;
            goto L_8001CCA4;
    }
    goto skip_34;
    // 0x8001CC98: ori         $at, $zero, 0xCDEE
    ctx->r1 = 0 | 0XCDEE;
    skip_34:
    // 0x8001CC9C: addiu       $v1, $zero, 0x11F
    ctx->r3 = ADD32(0, 0X11F);
    // 0x8001CCA0: ori         $at, $zero, 0xCDEE
    ctx->r1 = 0 | 0XCDEE;
L_8001CCA4:
    // 0x8001CCA4: bnel        $a1, $at, L_8001CCB4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CCA8: ori         $at, $zero, 0xBEE5
        ctx->r1 = 0 | 0XBEE5;
            goto L_8001CCB4;
    }
    goto skip_35;
    // 0x8001CCA8: ori         $at, $zero, 0xBEE5
    ctx->r1 = 0 | 0XBEE5;
    skip_35:
    // 0x8001CCAC: addiu       $v1, $zero, 0x120
    ctx->r3 = ADD32(0, 0X120);
    // 0x8001CCB0: ori         $at, $zero, 0xBEE5
    ctx->r1 = 0 | 0XBEE5;
L_8001CCB4:
    // 0x8001CCB4: bnel        $a1, $at, L_8001CCC4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CCB8: ori         $at, $zero, 0xBCC2
        ctx->r1 = 0 | 0XBCC2;
            goto L_8001CCC4;
    }
    goto skip_36;
    // 0x8001CCB8: ori         $at, $zero, 0xBCC2
    ctx->r1 = 0 | 0XBCC2;
    skip_36:
    // 0x8001CCBC: addiu       $v1, $zero, 0x121
    ctx->r3 = ADD32(0, 0X121);
    // 0x8001CCC0: ori         $at, $zero, 0xBCC2
    ctx->r1 = 0 | 0XBCC2;
L_8001CCC4:
    // 0x8001CCC4: bnel        $a1, $at, L_8001CCD4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CCC8: ori         $at, $zero, 0xB3E4
        ctx->r1 = 0 | 0XB3E4;
            goto L_8001CCD4;
    }
    goto skip_37;
    // 0x8001CCC8: ori         $at, $zero, 0xB3E4
    ctx->r1 = 0 | 0XB3E4;
    skip_37:
    // 0x8001CCCC: addiu       $v1, $zero, 0x122
    ctx->r3 = ADD32(0, 0X122);
    // 0x8001CCD0: ori         $at, $zero, 0xB3E4
    ctx->r1 = 0 | 0XB3E4;
L_8001CCD4:
    // 0x8001CCD4: bnel        $a1, $at, L_8001CCE4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CCD8: ori         $at, $zero, 0xC1C8
        ctx->r1 = 0 | 0XC1C8;
            goto L_8001CCE4;
    }
    goto skip_38;
    // 0x8001CCD8: ori         $at, $zero, 0xC1C8
    ctx->r1 = 0 | 0XC1C8;
    skip_38:
    // 0x8001CCDC: addiu       $v1, $zero, 0x123
    ctx->r3 = ADD32(0, 0X123);
    // 0x8001CCE0: ori         $at, $zero, 0xC1C8
    ctx->r1 = 0 | 0XC1C8;
L_8001CCE4:
    // 0x8001CCE4: bnel        $a1, $at, L_8001CCF4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CCE8: ori         $at, $zero, 0xB4AC
        ctx->r1 = 0 | 0XB4AC;
            goto L_8001CCF4;
    }
    goto skip_39;
    // 0x8001CCE8: ori         $at, $zero, 0xB4AC
    ctx->r1 = 0 | 0XB4AC;
    skip_39:
    // 0x8001CCEC: addiu       $v1, $zero, 0x124
    ctx->r3 = ADD32(0, 0X124);
    // 0x8001CCF0: ori         $at, $zero, 0xB4AC
    ctx->r1 = 0 | 0XB4AC;
L_8001CCF4:
    // 0x8001CCF4: bnel        $a1, $at, L_8001CD04
    if (ctx->r5 != ctx->r1) {
        // 0x8001CCF8: ori         $at, $zero, 0xC0DE
        ctx->r1 = 0 | 0XC0DE;
            goto L_8001CD04;
    }
    goto skip_40;
    // 0x8001CCF8: ori         $at, $zero, 0xC0DE
    ctx->r1 = 0 | 0XC0DE;
    skip_40:
    // 0x8001CCFC: addiu       $v1, $zero, 0x125
    ctx->r3 = ADD32(0, 0X125);
    // 0x8001CD00: ori         $at, $zero, 0xC0DE
    ctx->r1 = 0 | 0XC0DE;
L_8001CD04:
    // 0x8001CD04: bnel        $a1, $at, L_8001CD14
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD08: ori         $at, $zero, 0xB8E5
        ctx->r1 = 0 | 0XB8E5;
            goto L_8001CD14;
    }
    goto skip_41;
    // 0x8001CD08: ori         $at, $zero, 0xB8E5
    ctx->r1 = 0 | 0XB8E5;
    skip_41:
    // 0x8001CD0C: addiu       $v1, $zero, 0x126
    ctx->r3 = ADD32(0, 0X126);
    // 0x8001CD10: ori         $at, $zero, 0xB8E5
    ctx->r1 = 0 | 0XB8E5;
L_8001CD14:
    // 0x8001CD14: bnel        $a1, $at, L_8001CD24
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD18: ori         $at, $zero, 0xB2F3
        ctx->r1 = 0 | 0XB2F3;
            goto L_8001CD24;
    }
    goto skip_42;
    // 0x8001CD18: ori         $at, $zero, 0xB2F3
    ctx->r1 = 0 | 0XB2F3;
    skip_42:
    // 0x8001CD1C: addiu       $v1, $zero, 0x127
    ctx->r3 = ADD32(0, 0X127);
    // 0x8001CD20: ori         $at, $zero, 0xB2F3
    ctx->r1 = 0 | 0XB2F3;
L_8001CD24:
    // 0x8001CD24: bnel        $a1, $at, L_8001CD34
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD28: ori         $at, $zero, 0xCAA7
        ctx->r1 = 0 | 0XCAA7;
            goto L_8001CD34;
    }
    goto skip_43;
    // 0x8001CD28: ori         $at, $zero, 0xCAA7
    ctx->r1 = 0 | 0XCAA7;
    skip_43:
    // 0x8001CD2C: addiu       $v1, $zero, 0x128
    ctx->r3 = ADD32(0, 0X128);
    // 0x8001CD30: ori         $at, $zero, 0xCAA7
    ctx->r1 = 0 | 0XCAA7;
L_8001CD34:
    // 0x8001CD34: bnel        $a1, $at, L_8001CD44
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD38: ori         $at, $zero, 0xC7BE
        ctx->r1 = 0 | 0XC7BE;
            goto L_8001CD44;
    }
    goto skip_44;
    // 0x8001CD38: ori         $at, $zero, 0xC7BE
    ctx->r1 = 0 | 0XC7BE;
    skip_44:
    // 0x8001CD3C: addiu       $v1, $zero, 0x129
    ctx->r3 = ADD32(0, 0X129);
    // 0x8001CD40: ori         $at, $zero, 0xC7BE
    ctx->r1 = 0 | 0XC7BE;
L_8001CD44:
    // 0x8001CD44: bnel        $a1, $at, L_8001CD54
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD48: ori         $at, $zero, 0xC5B7
        ctx->r1 = 0 | 0XC5B7;
            goto L_8001CD54;
    }
    goto skip_45;
    // 0x8001CD48: ori         $at, $zero, 0xC5B7
    ctx->r1 = 0 | 0XC5B7;
    skip_45:
    // 0x8001CD4C: addiu       $v1, $zero, 0x12A
    ctx->r3 = ADD32(0, 0X12A);
    // 0x8001CD50: ori         $at, $zero, 0xC5B7
    ctx->r1 = 0 | 0XC5B7;
L_8001CD54:
    // 0x8001CD54: bnel        $a1, $at, L_8001CD64
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD58: ori         $at, $zero, 0xC5DD
        ctx->r1 = 0 | 0XC5DD;
            goto L_8001CD64;
    }
    goto skip_46;
    // 0x8001CD58: ori         $at, $zero, 0xC5DD
    ctx->r1 = 0 | 0XC5DD;
    skip_46:
    // 0x8001CD5C: addiu       $v1, $zero, 0x12B
    ctx->r3 = ADD32(0, 0X12B);
    // 0x8001CD60: ori         $at, $zero, 0xC5DD
    ctx->r1 = 0 | 0XC5DD;
L_8001CD64:
    // 0x8001CD64: bnel        $a1, $at, L_8001CD74
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD68: ori         $at, $zero, 0xC2AD
        ctx->r1 = 0 | 0XC2AD;
            goto L_8001CD74;
    }
    goto skip_47;
    // 0x8001CD68: ori         $at, $zero, 0xC2AD
    ctx->r1 = 0 | 0XC2AD;
    skip_47:
    // 0x8001CD6C: addiu       $v1, $zero, 0x12C
    ctx->r3 = ADD32(0, 0X12C);
    // 0x8001CD70: ori         $at, $zero, 0xC2AD
    ctx->r1 = 0 | 0XC2AD;
L_8001CD74:
    // 0x8001CD74: bnel        $a1, $at, L_8001CD84
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD78: ori         $at, $zero, 0xE7A7
        ctx->r1 = 0 | 0XE7A7;
            goto L_8001CD84;
    }
    goto skip_48;
    // 0x8001CD78: ori         $at, $zero, 0xE7A7
    ctx->r1 = 0 | 0XE7A7;
    skip_48:
    // 0x8001CD7C: addiu       $v1, $zero, 0x12D
    ctx->r3 = ADD32(0, 0X12D);
    // 0x8001CD80: ori         $at, $zero, 0xE7A7
    ctx->r1 = 0 | 0XE7A7;
L_8001CD84:
    // 0x8001CD84: bnel        $a1, $at, L_8001CD94
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD88: ori         $at, $zero, 0xCAA2
        ctx->r1 = 0 | 0XCAA2;
            goto L_8001CD94;
    }
    goto skip_49;
    // 0x8001CD88: ori         $at, $zero, 0xCAA2
    ctx->r1 = 0 | 0XCAA2;
    skip_49:
    // 0x8001CD8C: addiu       $v1, $zero, 0x12E
    ctx->r3 = ADD32(0, 0X12E);
    // 0x8001CD90: ori         $at, $zero, 0xCAA2
    ctx->r1 = 0 | 0XCAA2;
L_8001CD94:
    // 0x8001CD94: bnel        $a1, $at, L_8001CDA4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CD98: ori         $at, $zero, 0xB6DA
        ctx->r1 = 0 | 0XB6DA;
            goto L_8001CDA4;
    }
    goto skip_50;
    // 0x8001CD98: ori         $at, $zero, 0xB6DA
    ctx->r1 = 0 | 0XB6DA;
    skip_50:
    // 0x8001CD9C: addiu       $v1, $zero, 0x12F
    ctx->r3 = ADD32(0, 0X12F);
    // 0x8001CDA0: ori         $at, $zero, 0xB6DA
    ctx->r1 = 0 | 0XB6DA;
L_8001CDA4:
    // 0x8001CDA4: bnel        $a1, $at, L_8001CDB4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CDA8: ori         $at, $zero, 0xBEAE
        ctx->r1 = 0 | 0XBEAE;
            goto L_8001CDB4;
    }
    goto skip_51;
    // 0x8001CDA8: ori         $at, $zero, 0xBEAE
    ctx->r1 = 0 | 0XBEAE;
    skip_51:
    // 0x8001CDAC: addiu       $v1, $zero, 0x130
    ctx->r3 = ADD32(0, 0X130);
    // 0x8001CDB0: ori         $at, $zero, 0xBEAE
    ctx->r1 = 0 | 0XBEAE;
L_8001CDB4:
    // 0x8001CDB4: bnel        $a1, $at, L_8001CDC4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CDB8: ori         $at, $zero, 0xC2E7
        ctx->r1 = 0 | 0XC2E7;
            goto L_8001CDC4;
    }
    goto skip_52;
    // 0x8001CDB8: ori         $at, $zero, 0xC2E7
    ctx->r1 = 0 | 0XC2E7;
    skip_52:
    // 0x8001CDBC: addiu       $v1, $zero, 0x131
    ctx->r3 = ADD32(0, 0X131);
    // 0x8001CDC0: ori         $at, $zero, 0xC2E7
    ctx->r1 = 0 | 0XC2E7;
L_8001CDC4:
    // 0x8001CDC4: bnel        $a1, $at, L_8001CDD4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CDC8: ori         $at, $zero, 0xC9FC
        ctx->r1 = 0 | 0XC9FC;
            goto L_8001CDD4;
    }
    goto skip_53;
    // 0x8001CDC8: ori         $at, $zero, 0xC9FC
    ctx->r1 = 0 | 0XC9FC;
    skip_53:
    // 0x8001CDCC: addiu       $v1, $zero, 0x132
    ctx->r3 = ADD32(0, 0X132);
    // 0x8001CDD0: ori         $at, $zero, 0xC9FC
    ctx->r1 = 0 | 0XC9FC;
L_8001CDD4:
    // 0x8001CDD4: bnel        $a1, $at, L_8001CDE4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CDD8: ori         $at, $zero, 0xB4F0
        ctx->r1 = 0 | 0XB4F0;
            goto L_8001CDE4;
    }
    goto skip_54;
    // 0x8001CDD8: ori         $at, $zero, 0xB4F0
    ctx->r1 = 0 | 0XB4F0;
    skip_54:
    // 0x8001CDDC: addiu       $v1, $zero, 0x133
    ctx->r3 = ADD32(0, 0X133);
    // 0x8001CDE0: ori         $at, $zero, 0xB4F0
    ctx->r1 = 0 | 0XB4F0;
L_8001CDE4:
    // 0x8001CDE4: bnel        $a1, $at, L_8001CDF4
    if (ctx->r5 != ctx->r1) {
        // 0x8001CDE8: ori         $at, $zero, 0xC1C3
        ctx->r1 = 0 | 0XC1C3;
            goto L_8001CDF4;
    }
    goto skip_55;
    // 0x8001CDE8: ori         $at, $zero, 0xC1C3
    ctx->r1 = 0 | 0XC1C3;
    skip_55:
    // 0x8001CDEC: addiu       $v1, $zero, 0x134
    ctx->r3 = ADD32(0, 0X134);
    // 0x8001CDF0: ori         $at, $zero, 0xC1C3
    ctx->r1 = 0 | 0XC1C3;
L_8001CDF4:
    // 0x8001CDF4: bnel        $a1, $at, L_8001CE04
    if (ctx->r5 != ctx->r1) {
        // 0x8001CDF8: ori         $at, $zero, 0xB9B6
        ctx->r1 = 0 | 0XB9B6;
            goto L_8001CE04;
    }
    goto skip_56;
    // 0x8001CDF8: ori         $at, $zero, 0xB9B6
    ctx->r1 = 0 | 0XB9B6;
    skip_56:
    // 0x8001CDFC: addiu       $v1, $zero, 0x135
    ctx->r3 = ADD32(0, 0X135);
    // 0x8001CE00: ori         $at, $zero, 0xB9B6
    ctx->r1 = 0 | 0XB9B6;
L_8001CE04:
    // 0x8001CE04: bnel        $a1, $at, L_8001CE14
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE08: ori         $at, $zero, 0xB7E2
        ctx->r1 = 0 | 0XB7E2;
            goto L_8001CE14;
    }
    goto skip_57;
    // 0x8001CE08: ori         $at, $zero, 0xB7E2
    ctx->r1 = 0 | 0XB7E2;
    skip_57:
    // 0x8001CE0C: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
    // 0x8001CE10: ori         $at, $zero, 0xB7E2
    ctx->r1 = 0 | 0XB7E2;
L_8001CE14:
    // 0x8001CE14: bnel        $a1, $at, L_8001CE24
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE18: ori         $at, $zero, 0xCECF
        ctx->r1 = 0 | 0XCECF;
            goto L_8001CE24;
    }
    goto skip_58;
    // 0x8001CE18: ori         $at, $zero, 0xCECF
    ctx->r1 = 0 | 0XCECF;
    skip_58:
    // 0x8001CE1C: addiu       $v1, $zero, 0x137
    ctx->r3 = ADD32(0, 0X137);
    // 0x8001CE20: ori         $at, $zero, 0xCECF
    ctx->r1 = 0 | 0XCECF;
L_8001CE24:
    // 0x8001CE24: bnel        $a1, $at, L_8001CE34
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE28: ori         $at, $zero, 0xCBC9
        ctx->r1 = 0 | 0XCBC9;
            goto L_8001CE34;
    }
    goto skip_59;
    // 0x8001CE28: ori         $at, $zero, 0xCBC9
    ctx->r1 = 0 | 0XCBC9;
    skip_59:
    // 0x8001CE2C: addiu       $v1, $zero, 0x138
    ctx->r3 = ADD32(0, 0X138);
    // 0x8001CE30: ori         $at, $zero, 0xCBC9
    ctx->r1 = 0 | 0XCBC9;
L_8001CE34:
    // 0x8001CE34: bnel        $a1, $at, L_8001CE44
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE38: ori         $at, $zero, 0xB8E6
        ctx->r1 = 0 | 0XB8E6;
            goto L_8001CE44;
    }
    goto skip_60;
    // 0x8001CE38: ori         $at, $zero, 0xB8E6
    ctx->r1 = 0 | 0XB8E6;
    skip_60:
    // 0x8001CE3C: addiu       $v1, $zero, 0x139
    ctx->r3 = ADD32(0, 0X139);
    // 0x8001CE40: ori         $at, $zero, 0xB8E6
    ctx->r1 = 0 | 0XB8E6;
L_8001CE44:
    // 0x8001CE44: bnel        $a1, $at, L_8001CE54
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE48: ori         $at, $zero, 0xC1C7
        ctx->r1 = 0 | 0XC1C7;
            goto L_8001CE54;
    }
    goto skip_61;
    // 0x8001CE48: ori         $at, $zero, 0xC1C7
    ctx->r1 = 0 | 0XC1C7;
    skip_61:
    // 0x8001CE4C: addiu       $v1, $zero, 0x13A
    ctx->r3 = ADD32(0, 0X13A);
    // 0x8001CE50: ori         $at, $zero, 0xC1C7
    ctx->r1 = 0 | 0XC1C7;
L_8001CE54:
    // 0x8001CE54: bnel        $a1, $at, L_8001CE64
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE58: ori         $at, $zero, 0xC1E1
        ctx->r1 = 0 | 0XC1E1;
            goto L_8001CE64;
    }
    goto skip_62;
    // 0x8001CE58: ori         $at, $zero, 0xC1E1
    ctx->r1 = 0 | 0XC1E1;
    skip_62:
    // 0x8001CE5C: addiu       $v1, $zero, 0x13B
    ctx->r3 = ADD32(0, 0X13B);
    // 0x8001CE60: ori         $at, $zero, 0xC1E1
    ctx->r1 = 0 | 0XC1E1;
L_8001CE64:
    // 0x8001CE64: bnel        $a1, $at, L_8001CE74
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE68: ori         $at, $zero, 0xC1B0
        ctx->r1 = 0 | 0XC1B0;
            goto L_8001CE74;
    }
    goto skip_63;
    // 0x8001CE68: ori         $at, $zero, 0xC1B0
    ctx->r1 = 0 | 0XC1B0;
    skip_63:
    // 0x8001CE6C: addiu       $v1, $zero, 0x13C
    ctx->r3 = ADD32(0, 0X13C);
    // 0x8001CE70: ori         $at, $zero, 0xC1B0
    ctx->r1 = 0 | 0XC1B0;
L_8001CE74:
    // 0x8001CE74: bnel        $a1, $at, L_8001CE84
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE78: ori         $at, $zero, 0xB5D3
        ctx->r1 = 0 | 0XB5D3;
            goto L_8001CE84;
    }
    goto skip_64;
    // 0x8001CE78: ori         $at, $zero, 0xB5D3
    ctx->r1 = 0 | 0XB5D3;
    skip_64:
    // 0x8001CE7C: addiu       $v1, $zero, 0x13D
    ctx->r3 = ADD32(0, 0X13D);
    // 0x8001CE80: ori         $at, $zero, 0xB5D3
    ctx->r1 = 0 | 0XB5D3;
L_8001CE84:
    // 0x8001CE84: bnel        $a1, $at, L_8001CE94
    if (ctx->r5 != ctx->r1) {
        // 0x8001CE88: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001CE94;
    }
    goto skip_65;
    // 0x8001CE88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_65:
    // 0x8001CE8C: addiu       $v1, $zero, 0x13E
    ctx->r3 = ADD32(0, 0X13E);
L_8001CE90:
    // 0x8001CE90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001CE94:
    // 0x8001CE94: jr          $ra
    // 0x8001CE98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001CE98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001ce9c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001ce9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001CEA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001CEA4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8001CEA8: sra         $a2, $a0, 8
    ctx->r6 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8001CEAC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001CEB0: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8001CEB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CEB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001CEBC: bne         $a2, $at, L_8001CEE4
    if (ctx->r6 != ctx->r1) {
        // 0x8001CEC0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8001CEE4;
    }
    // 0x8001CEC0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001CEC4: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001CEC8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001CECC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001CED0: jal         0x8001C670
    // 0x8001CED4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C670)(rdram, ctx);
        goto after_0;
    // 0x8001CED4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001CED8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001CEDC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CEE0: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
L_8001CEE4:
    // 0x8001CEE4: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x8001CEE8: bne         $a2, $at, L_8001CF10
    if (ctx->r6 != ctx->r1) {
        // 0x8001CEEC: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8001CF10;
    }
    // 0x8001CEEC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001CEF0: addiu       $a0, $a0, -0xA1
    ctx->r4 = ADD32(ctx->r4, -0XA1);
    // 0x8001CEF4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001CEF8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001CEFC: jal         0x8001C6E8
    // 0x8001CF00: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001C6E8)(rdram, ctx);
        goto after_1;
    // 0x8001CF00: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8001CF04: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001CF08: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CF0C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
L_8001CF10:
    // 0x8001CF10: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x8001CF14: bne         $a2, $at, L_8001CF2C
    if (ctx->r6 != ctx->r1) {
        // 0x8001CF18: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8001CF2C;
    }
    // 0x8001CF18: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001CF1C: addiu       $a0, $a0, -0xB0
    ctx->r4 = ADD32(ctx->r4, -0XB0);
    // 0x8001CF20: jal         0x8001C734
    // 0x8001CF24: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x8001C734)(rdram, ctx);
        goto after_2;
    // 0x8001CF24: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_2:
    // 0x8001CF28: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
L_8001CF2C:
    // 0x8001CF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001CF34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8001CF38: jr          $ra
    // 0x8001CF3C: nop

    return;
    // 0x8001CF3C: nop

;}
RECOMP_FUNC void FUN_8001cf40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF40: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001CF44: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001CF48: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001CF4C: addiu       $t6, $t6, 0x47A0
    ctx->r14 = ADD32(ctx->r14, 0X47A0);
    // 0x8001CF50: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001CF54: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x8001CF58: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001CF5C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001CF60: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001CF64: addiu       $t9, $t9, 0x47B0
    ctx->r25 = ADD32(ctx->r25, 0X47B0);
    // 0x8001CF68: addiu       $t2, $sp, 0x3C
    ctx->r10 = ADD32(ctx->r29, 0X3C);
    // 0x8001CF6C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001CF70: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8001CF74: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001CF78: andi        $t1, $a0, 0xFF
    ctx->r9 = ctx->r4 & 0XFF;
    // 0x8001CF7C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8001CF80: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001CF84: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8001CF88: addiu       $t8, $t8, 0x47D0
    ctx->r24 = ADD32(ctx->r24, 0X47D0);
    // 0x8001CF8C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8001CF90: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8001CF94: sra         $t0, $a0, 8
    ctx->r8 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8001CF98: addiu       $t1, $t1, -0xA0
    ctx->r9 = ADD32(ctx->r9, -0XA0);
    // 0x8001CF9C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001CFA0: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8001CFA4: addiu       $t0, $t0, -0xA0
    ctx->r8 = ADD32(ctx->r8, -0XA0);
    // 0x8001CFA8: andi        $a3, $t1, 0xFF
    ctx->r7 = ctx->r9 & 0XFF;
    // 0x8001CFAC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8001CFB0: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x8001CFB4: andi        $t4, $a3, 0xF
    ctx->r12 = ctx->r7 & 0XF;
    // 0x8001CFB8: sra         $t5, $a3, 4
    ctx->r13 = S32(SIGNED(ctx->r7) >> 4);
    // 0x8001CFBC: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x8001CFC0: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x8001CFC4: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    // 0x8001CFC8: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x8001CFCC: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
    // 0x8001CFD0: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x8001CFD4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001CFD8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8001CFDC: sw          $t7, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r15;
    // 0x8001CFE0: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x8001CFE4: sw          $t6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r14;
    // 0x8001CFE8: lw          $t7, 0x18($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X18);
    // 0x8001CFEC: sw          $t7, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r15;
    // 0x8001CFF0: lw          $t6, 0x1C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X1C);
    // 0x8001CFF4: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x8001CFF8: slti        $at, $t7, 0x30
    ctx->r1 = SIGNED(ctx->r15) < 0X30 ? 1 : 0;
    // 0x8001CFFC: sw          $t6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r14;
    // 0x8001D000: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8001D004: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8001D008: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8001D00C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8001D010: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8001D014: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x8001D018: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x8001D01C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8001D020: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x8001D024: lw          $t6, 0x10($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X10);
    // 0x8001D028: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x8001D02C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8001D030: sw          $t9, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r25;
    // 0x8001D034: lw          $t6, 0x18($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X18);
    // 0x8001D038: sw          $t6, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r14;
    // 0x8001D03C: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x8001D040: bne         $at, $zero, L_8001D04C
    if (ctx->r1 != 0) {
        // 0x8001D044: sw          $t9, 0x1C($a1)
        MEM_W(0X1C, ctx->r5) = ctx->r25;
            goto L_8001D04C;
    }
    // 0x8001D044: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
    // 0x8001D048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001D04C:
    // 0x8001D04C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8001D050: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8001D054: lw          $a0, 0x4360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4360);
    // 0x8001D058: addu        $t9, $t2, $t4
    ctx->r25 = ADD32(ctx->r10, ctx->r12);
    // 0x8001D05C: bne         $a0, $zero, L_8001D06C
    if (ctx->r4 != 0) {
        // 0x8001D060: addu        $t8, $a0, $t7
        ctx->r24 = ADD32(ctx->r4, ctx->r15);
            goto L_8001D06C;
    }
    // 0x8001D060: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8001D064: b           L_8001D2D4
    // 0x8001D068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8001D2D4;
    // 0x8001D068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001D06C:
    // 0x8001D06C: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x8001D070: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8001D074: lhu         $a2, 0x0($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X0);
    // 0x8001D078: and         $t7, $t6, $t9
    ctx->r15 = ctx->r14 & ctx->r25;
    // 0x8001D07C: bne         $t7, $zero, L_8001D08C
    if (ctx->r15 != 0) {
        // 0x8001D080: nop
    
            goto L_8001D08C;
    }
    // 0x8001D080: nop

    // 0x8001D084: b           L_8001D2D4
    // 0x8001D088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8001D2D4;
    // 0x8001D088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001D08C:
    // 0x8001D08C: blez        $t5, L_8001D268
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001D090: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8001D268;
    }
    // 0x8001D090: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001D094: andi        $t1, $t5, 0x3
    ctx->r9 = ctx->r13 & 0X3;
    // 0x8001D098: beq         $t1, $zero, L_8001D10C
    if (ctx->r9 == 0) {
        // 0x8001D09C: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8001D10C;
    }
    // 0x8001D09C: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8001D0A0: sll         $t8, $zero, 1
    ctx->r24 = S32(0 << 1);
    // 0x8001D0A4: addu        $t2, $a0, $t8
    ctx->r10 = ADD32(ctx->r4, ctx->r24);
L_8001D0A8:
    // 0x8001D0A8: lhu         $t1, 0x2($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X2);
    // 0x8001D0AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001D0B0: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8001D0B4: andi        $t6, $t1, 0xF
    ctx->r14 = ctx->r9 & 0XF;
    // 0x8001D0B8: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D0BC: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D0C0: sra         $t8, $t1, 4
    ctx->r24 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8001D0C4: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8001D0C8: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D0CC: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D0D0: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D0D4: sra         $t8, $t1, 8
    ctx->r24 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001D0D8: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8001D0DC: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D0E0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D0E4: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D0E8: sra         $t8, $t1, 12
    ctx->r24 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8001D0EC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8001D0F0: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D0F4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D0F8: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D0FC: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D100: bne         $a3, $t0, L_8001D0A8
    if (ctx->r7 != ctx->r8) {
        // 0x8001D104: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_8001D0A8;
    }
    // 0x8001D104: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8001D108: beq         $t0, $t5, L_8001D268
    if (ctx->r8 == ctx->r13) {
        // 0x8001D10C: sll         $t8, $t0, 1
        ctx->r24 = S32(ctx->r8 << 1);
            goto L_8001D268;
    }
L_8001D10C:
    // 0x8001D10C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8001D110: addu        $t2, $a0, $t8
    ctx->r10 = ADD32(ctx->r4, ctx->r24);
    // 0x8001D114: sra         $a3, $v1, 4
    ctx->r7 = S32(SIGNED(ctx->r3) >> 4);
L_8001D118:
    // 0x8001D118: lhu         $t1, 0x2($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X2);
    // 0x8001D11C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001D120: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x8001D124: andi        $t6, $t1, 0xF
    ctx->r14 = ctx->r9 & 0XF;
    // 0x8001D128: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D12C: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D130: sra         $t8, $t1, 4
    ctx->r24 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8001D134: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8001D138: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D13C: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D140: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D144: sra         $t8, $t1, 8
    ctx->r24 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001D148: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8001D14C: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D150: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D154: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D158: sra         $t8, $t1, 12
    ctx->r24 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8001D15C: lhu         $t1, -0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, -0X4);
    // 0x8001D160: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8001D164: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x8001D168: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D16C: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8001D170: andi        $t8, $t1, 0xF
    ctx->r24 = ctx->r9 & 0XF;
    // 0x8001D174: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8001D178: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8001D17C: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D180: sra         $t7, $t1, 4
    ctx->r15 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8001D184: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001D188: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8001D18C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D190: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8001D194: sra         $t7, $t1, 8
    ctx->r15 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001D198: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001D19C: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8001D1A0: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D1A4: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8001D1A8: sra         $t7, $t1, 12
    ctx->r15 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8001D1AC: lhu         $t1, -0x2($t2)
    ctx->r9 = MEM_HU(ctx->r10, -0X2);
    // 0x8001D1B0: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001D1B4: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8001D1B8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D1BC: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8001D1C0: andi        $t7, $t1, 0xF
    ctx->r15 = ctx->r9 & 0XF;
    // 0x8001D1C4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D1C8: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D1CC: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D1D0: sra         $t9, $t1, 4
    ctx->r25 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8001D1D4: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x8001D1D8: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D1DC: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D1E0: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D1E4: sra         $t9, $t1, 8
    ctx->r25 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001D1E8: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x8001D1EC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D1F0: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D1F4: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D1F8: sra         $t9, $t1, 12
    ctx->r25 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8001D1FC: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x8001D200: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x8001D204: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D208: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D20C: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D210: andi        $t9, $t1, 0xF
    ctx->r25 = ctx->r9 & 0XF;
    // 0x8001D214: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x8001D218: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8001D21C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D220: sra         $t6, $t1, 4
    ctx->r14 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8001D224: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x8001D228: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x8001D22C: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8001D230: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8001D234: sra         $t6, $t1, 8
    ctx->r14 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001D238: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x8001D23C: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x8001D240: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8001D244: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8001D248: sra         $t6, $t1, 12
    ctx->r14 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8001D24C: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x8001D250: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x8001D254: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8001D258: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8001D25C: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8001D260: bne         $t0, $a3, L_8001D118
    if (ctx->r8 != ctx->r7) {
        // 0x8001D264: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_8001D118;
    }
    // 0x8001D264: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_8001D268:
    // 0x8001D268: addu        $t6, $a1, $t4
    ctx->r14 = ADD32(ctx->r5, ctx->r12);
    // 0x8001D26C: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x8001D270: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x8001D274: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8001D278: lhu         $t6, 0x2($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X2);
    // 0x8001D27C: and         $t1, $t9, $t6
    ctx->r9 = ctx->r25 & ctx->r14;
    // 0x8001D280: andi        $t7, $t1, 0xF
    ctx->r15 = ctx->r9 & 0XF;
    // 0x8001D284: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D288: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D28C: sra         $t6, $t1, 4
    ctx->r14 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8001D290: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8001D294: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D298: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D29C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D2A0: sra         $t6, $t1, 8
    ctx->r14 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001D2A4: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8001D2A8: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D2AC: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D2B0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D2B4: sra         $t6, $t1, 12
    ctx->r14 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8001D2B8: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8001D2BC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D2C0: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D2C4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D2C8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8001D2CC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001D2D0: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_8001D2D4:
    // 0x8001D2D4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001D2D8: jr          $ra
    // 0x8001D2DC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8001D2DC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001d2e0(rdram, ctx);
;}
