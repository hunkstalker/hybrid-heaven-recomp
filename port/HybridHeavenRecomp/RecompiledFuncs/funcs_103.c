#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M12_FUN_802409ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802409AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802409B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802409B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802409B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x802409BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x802409C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802409C4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802409C8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802409CC: addiu       $a1, $a1, 0x5D7C
    ctx->r5 = ADD32(ctx->r5, 0X5D7C);
    // 0x802409D0: jal         0x80005670
    // 0x802409D4: lw          $a0, -0x43CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43CC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x802409D4: lw          $a0, -0x43CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43CC);
    after_0:
    // 0x802409D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802409DC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802409E0: addiu       $a1, $a1, 0x5D68
    ctx->r5 = ADD32(ctx->r5, 0X5D68);
    // 0x802409E4: jal         0x80005670
    // 0x802409E8: lw          $a0, -0x43CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43CC);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x802409E8: lw          $a0, -0x43CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43CC);
    after_1:
    // 0x802409EC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802409F0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802409F4: addiu       $a1, $a1, 0x5DA4
    ctx->r5 = ADD32(ctx->r5, 0X5DA4);
    // 0x802409F8: jal         0x80005670
    // 0x802409FC: lw          $a0, -0x43C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43C0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x802409FC: lw          $a0, -0x43C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43C0);
    after_2:
    // 0x80240A00: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80240A04: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80240A08: jal         0x80005F6C
    // 0x80240A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_3;
    // 0x80240A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80240A10: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80240A14: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80240A18: jal         0x80005F6C
    // 0x80240A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_4;
    // 0x80240A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80240A20: jal         0x80006214
    // 0x80240A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x80240A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80240A28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80240A2C: jal         0x8012636C
    // 0x80240A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_6;
    // 0x80240A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80240A34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80240A38: jal         0x8012636C
    // 0x80240A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_7;
    // 0x80240A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80240A40: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80240A44: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80240A48: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x80240A4C: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80240A50: addiu       $t9, $t9, -0x4808
    ctx->r25 = ADD32(ctx->r25, -0X4808);
    // 0x80240A54: or          $t2, $t9, $t0
    ctx->r10 = ctx->r25 | ctx->r8;
    // 0x80240A58: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80240A5C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80240A60: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80240A64: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x80240A68: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x80240A6C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80240A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80240A74: lui         $at, 0xC25C
    ctx->r1 = S32(0XC25C << 16);
    // 0x80240A78: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80240A7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80240A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80240A84: sw          $t2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r10;
    // 0x80240A88: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80240A8C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80240A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80240A94: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80240A98: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80240A9C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80240AA0: sb          $zero, 0x48($t6)
    MEM_B(0X48, ctx->r14) = 0;
    // 0x80240AA4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80240AA8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80240AAC: sb          $t1, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r9;
    // 0x80240AB0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80240AB4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80240AB8: ori         $t8, $t8, 0x600
    ctx->r24 = ctx->r24 | 0X600;
    // 0x80240ABC: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80240AC0: sb          $zero, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = 0;
    // 0x80240AC4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80240AC8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80240ACC: sb          $t2, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r10;
    // 0x80240AD0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80240AD4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80240AD8: addiu       $t5, $t5, -0x4C78
    ctx->r13 = ADD32(ctx->r13, -0X4C78);
    // 0x80240ADC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80240AE0: or          $t6, $t5, $t0
    ctx->r14 = ctx->r13 | ctx->r8;
    // 0x80240AE4: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x80240AE8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80240AEC: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
    // 0x80240AF0: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80240AF4: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x80240AF8: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    // 0x80240AFC: ori         $t2, $t4, 0x100
    ctx->r10 = ctx->r12 | 0X100;
    // 0x80240B00: sw          $t2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r10;
    // 0x80240B04: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80240B08: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80240B0C: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x80240B10: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80240B14: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80240B18: sb          $zero, 0x48($t3)
    MEM_B(0X48, ctx->r11) = 0;
    // 0x80240B1C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80240B20: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x80240B24: sb          $t1, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r9;
    // 0x80240B28: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80240B2C: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80240B30: sb          $zero, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = 0;
    // 0x80240B34: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80240B38: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x80240B3C: jal         0x8012C89C
    // 0x80240B40: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_8;
    // 0x80240B40: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    after_8:
    // 0x80240B44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80240B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80240B4C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80240B50: jal         0x8012C89C
    // 0x80240B54: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_9;
    // 0x80240B54: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80240B58: jal         0x80133980
    // 0x80240B5C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_10;
    // 0x80240B5C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_10:
    // 0x80240B60: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240B64: addiu       $a1, $a1, 0xB84
    ctx->r5 = ADD32(ctx->r5, 0XB84);
    // 0x80240B68: jal         0x800058DC
    // 0x80240B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80240B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80240B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80240B74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80240B78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80240B7C: jr          $ra
    // 0x80240B80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80240B80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80240b84(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80240b84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80240B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80240B8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80240B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80240B94: jal         0x8012A564
    // 0x80240B98: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    LOOKUP_FUNC(0x8012A564)(rdram, ctx);
        goto after_0;
    // 0x80240B98: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_0:
    // 0x80240B9C: beql        $v0, $zero, L_80240BDC
    if (ctx->r2 == 0) {
        // 0x80240BA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80240BDC;
    }
    goto skip_0;
    // 0x80240BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80240BA4: jal         0x801FBB30
    // 0x80240BA8: nop

    LOOKUP_FUNC(0x801FBB30)(rdram, ctx);
        goto after_1;
    // 0x80240BA8: nop

    after_1:
    // 0x80240BAC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80240BB0: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x80240BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80240BB8: jal         0x801268F4
    // 0x80240BBC: sh          $t6, 0x90($t7)
    MEM_H(0X90, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x801268F4)(rdram, ctx);
        goto after_2;
    // 0x80240BBC: sh          $t6, 0x90($t7)
    MEM_H(0X90, ctx->r15) = ctx->r14;
    after_2:
    // 0x80240BC0: jal         0x801339D0
    // 0x80240BC4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801339D0)(rdram, ctx);
        goto after_3;
    // 0x80240BC4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80240BC8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240BCC: addiu       $a1, $a1, 0xBE8
    ctx->r5 = ADD32(ctx->r5, 0XBE8);
    // 0x80240BD0: jal         0x800058DC
    // 0x80240BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80240BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80240BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80240BDC:
    // 0x80240BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80240BE0: jr          $ra
    // 0x80240BE4: nop

    return;
    // 0x80240BE4: nop

;}
RECOMP_FUNC void M12_FUN_80240be8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240BE8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80240BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80240bf0(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80240bf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240BF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80240BF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80240BF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80240BFC: lui         $at, 0x4427
    ctx->r1 = S32(0X4427 << 16);
    // 0x80240C00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80240C04: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x80240C08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80240C0C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80240C10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80240C14: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80240C18: lwc1        $f16, -0x6570($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6570);
    // 0x80240C1C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80240C20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80240C24: lui         $at, 0x4379
    ctx->r1 = S32(0X4379 << 16);
    // 0x80240C28: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80240C2C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80240C30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80240C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80240C38: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80240C3C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80240C40: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80240C44: lui         $a0, 0x8025
    ctx->r4 = S32(0X8025 << 16);
    // 0x80240C48: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80240C4C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80240C50: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80240C54: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80240C58: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80240C5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80240C60: addiu       $a0, $a0, -0x6718
    ctx->r4 = ADD32(ctx->r4, -0X6718);
    // 0x80240C64: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80240C68: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80240C6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80240C70: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80240C74: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80240C78: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80240C7C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80240C80: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80240C84: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80240C88: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80240C8C: jal         0x8011AAF4
    // 0x80240C90: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x80240C90: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80240C94: bnel        $v0, $zero, L_80240CF4
    if (ctx->r2 != 0) {
        // 0x80240C98: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80240CF4;
    }
    goto skip_0;
    // 0x80240C98: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80240C9C: jal         0x80020744
    // 0x80240CA0: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80240CA0: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    after_1:
    // 0x80240CA4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80240CA8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80240CAC: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x80240CB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80240CB4: lui         $t1, 0x348
    ctx->r9 = S32(0X348 << 16);
    // 0x80240CB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80240CBC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80240CC0: ori         $t1, $t1, 0x17
    ctx->r9 = ctx->r9 | 0X17;
    // 0x80240CC4: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x80240CC8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240CCC: sh          $t9, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r25;
    // 0x80240CD0: sh          $t0, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r8;
    // 0x80240CD4: sw          $t1, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r9;
    // 0x80240CD8: sh          $zero, 0xF0C($v0)
    MEM_H(0XF0C, ctx->r2) = 0;
    // 0x80240CDC: sh          $t2, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r10;
    // 0x80240CE0: addiu       $a1, $a1, 0xD00
    ctx->r5 = ADD32(ctx->r5, 0XD00);
    // 0x80240CE4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80240CE8: jal         0x800058DC
    // 0x80240CEC: swc1        $f8, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80240CEC: swc1        $f8, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f8.u32l;
    after_2:
    // 0x80240CF0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80240CF4:
    // 0x80240CF4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80240CF8: jr          $ra
    // 0x80240CFC: nop

    return;
    // 0x80240CFC: nop

;}
RECOMP_FUNC void M12_FUN_80240d00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80240D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80240D08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80240D0C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80240D10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80240D14: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80240D18: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80240D1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80240D20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80240D24: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80240D28: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80240D2C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80240D30: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80240D34: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80240D38: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
    // 0x80240D3C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80240D40: bne         $v1, $zero, L_80240D84
    if (ctx->r3 != 0) {
        // 0x80240D44: sh          $t8, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r24;
            goto L_80240D84;
    }
    // 0x80240D44: sh          $t8, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r24;
    // 0x80240D48: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x80240D4C: jal         0x80020744
    // 0x80240D50: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80240D50: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80240D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80240D58: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80240D5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80240D60: sh          $t9, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r25;
    // 0x80240D64: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80240D68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80240D6C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240D70: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80240D74: addiu       $a1, $a1, 0xD94
    ctx->r5 = ADD32(ctx->r5, 0XD94);
    // 0x80240D78: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80240D7C: jal         0x800058DC
    // 0x80240D80: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80240D80: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    after_1:
L_80240D84:
    // 0x80240D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80240D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80240D8C: jr          $ra
    // 0x80240D90: nop

    return;
    // 0x80240D90: nop

;}
RECOMP_FUNC void M12_FUN_80240d94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80240D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80240D9C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80240DA0: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80240DA4: ldc1        $f8, -0x6568($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6568);
    // 0x80240DA8: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80240DAC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240DB0: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80240DB4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80240DB8: addiu       $a1, $a1, 0xDF4
    ctx->r5 = ADD32(ctx->r5, 0XDF4);
    // 0x80240DBC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80240DC0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80240DC4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80240DC8: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80240DCC: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
    // 0x80240DD0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80240DD4: bne         $v1, $zero, L_80240DE4
    if (ctx->r3 != 0) {
        // 0x80240DD8: sh          $t7, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r15;
            goto L_80240DE4;
    }
    // 0x80240DD8: sh          $t7, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r15;
    // 0x80240DDC: jal         0x800058DC
    // 0x80240DE0: sh          $t8, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80240DE0: sh          $t8, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r24;
    after_0:
L_80240DE4:
    // 0x80240DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80240DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80240DEC: jr          $ra
    // 0x80240DF0: nop

    return;
    // 0x80240DF0: nop

;}
RECOMP_FUNC void M12_FUN_80240df4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80240DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80240DFC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80240E00: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80240E04: ldc1        $f8, -0x6560($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6560);
    // 0x80240E08: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80240E0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80240E10: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80240E14: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80240E18: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80240E1C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80240E20: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80240E24: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
    // 0x80240E28: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80240E2C: bne         $v1, $zero, L_80240E6C
    if (ctx->r3 != 0) {
        // 0x80240E30: sh          $t7, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r15;
            goto L_80240E6C;
    }
    // 0x80240E30: sh          $t7, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r15;
    // 0x80240E34: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80240E38: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80240E3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80240E40: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80240E44: addiu       $t0, $zero, 0x46
    ctx->r8 = ADD32(0, 0X46);
    // 0x80240E48: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x80240E4C: sh          $t0, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r8;
    // 0x80240E50: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80240E54: jal         0x80020744
    // 0x80240E58: addiu       $a0, $zero, 0x6B2
    ctx->r4 = ADD32(0, 0X6B2);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80240E58: addiu       $a0, $zero, 0x6B2
    ctx->r4 = ADD32(0, 0X6B2);
    after_0:
    // 0x80240E5C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80240E64: jal         0x800058DC
    // 0x80240E68: addiu       $a1, $a1, 0xE7C
    ctx->r5 = ADD32(ctx->r5, 0XE7C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80240E68: addiu       $a1, $a1, 0xE7C
    ctx->r5 = ADD32(ctx->r5, 0XE7C);
    after_1:
L_80240E6C:
    // 0x80240E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80240E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80240E74: jr          $ra
    // 0x80240E78: nop

    return;
    // 0x80240E78: nop

;}
RECOMP_FUNC void M12_FUN_80240e7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80240E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80240E84: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80240E88: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80240E8C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80240E90: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80240E94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80240E98: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80240E9C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80240EA0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80240EA4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80240EA8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80240EAC: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80240EB0: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
    // 0x80240EB4: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80240EB8: bne         $v1, $zero, L_80240EF0
    if (ctx->r3 != 0) {
        // 0x80240EBC: sh          $t7, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r15;
            goto L_80240EF0;
    }
    // 0x80240EBC: sh          $t7, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r15;
    // 0x80240EC0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80240EC4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80240EC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80240ECC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80240ED0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80240ED4: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x80240ED8: jal         0x80133980
    // 0x80240EDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x80240EDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80240EE0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240EE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80240EE8: jal         0x800058DC
    // 0x80240EEC: addiu       $a1, $a1, 0xF00
    ctx->r5 = ADD32(ctx->r5, 0XF00);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80240EEC: addiu       $a1, $a1, 0xF00
    ctx->r5 = ADD32(ctx->r5, 0XF00);
    after_1:
L_80240EF0:
    // 0x80240EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80240EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80240EF8: jr          $ra
    // 0x80240EFC: nop

    return;
    // 0x80240EFC: nop

;}
RECOMP_FUNC void M12_FUN_80240f00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240F00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80240F04: jr          $ra
    // 0x80240F08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80240F08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80240f0c(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80240f0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240F0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80240F10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80240F14: sb          $t6, -0x428A($at)
    MEM_B(-0X428A, ctx->r1) = ctx->r14;
    // 0x80240F18: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80240F1C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80240F20: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80240F24: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80240F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80240F2C: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x80240F30: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80240F34: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80240F38: addiu       $t0, $t0, 0xF4C
    ctx->r8 = ADD32(ctx->r8, 0XF4C);
    // 0x80240F3C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x80240F40: sw          $t0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r8;
    // 0x80240F44: jr          $ra
    // 0x80240F48: swc1        $f4, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80240F48: swc1        $f4, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80240f4c(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80240f4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80240F50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80240F54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80240F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80240F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80240F60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80240F64: sb          $t6, -0x428A($at)
    MEM_B(-0X428A, ctx->r1) = ctx->r14;
    // 0x80240F68: lwc1        $f0, 0x90($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80240F6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80240F70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80240F74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80240F78: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80240F7C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80240F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80240F84: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80240F88: bc1t        L_80240F94
    if (c1cs) {
        // 0x80240F8C: nop
    
            goto L_80240F94;
    }
    // 0x80240F8C: nop

    // 0x80240F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80240F94:
    // 0x80240F94: bne         $v0, $zero, L_80240FD8
    if (ctx->r2 != 0) {
        // 0x80240F98: swc1        $f8, 0x90($a1)
        MEM_W(0X90, ctx->r5) = ctx->f8.u32l;
            goto L_80240FD8;
    }
    // 0x80240F98: swc1        $f8, 0x90($a1)
    MEM_W(0X90, ctx->r5) = ctx->f8.u32l;
    // 0x80240F9C: lhu         $t7, 0x36($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X36);
    // 0x80240FA0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80240FA4: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80240FA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80240FAC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80240FB0: lw          $t9, 0x1CEC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1CEC);
    // 0x80240FB4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80240FB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80240FBC: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x80240FC0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80240FC4: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80240FC8: jal         0x80126E88
    // 0x80240FCC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x80240FCC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80240FD0: jal         0x80005700
    // 0x80240FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80240FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80240FD8:
    // 0x80240FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80240FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80240FE0: jr          $ra
    // 0x80240FE4: nop

    return;
    // 0x80240FE4: nop

;}
RECOMP_FUNC void M12_FUN_80240fe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80240FE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80240FEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80240FF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80240FF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80240FF8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80240FFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80241000: jal         0x80005F6C
    // 0x80241004: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x80241004: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80241008: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8024100C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80241010: jal         0x80005F6C
    // 0x80241014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_1;
    // 0x80241014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80241018: jal         0x80006214
    // 0x8024101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x8024101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80241020: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241024: lwc1        $f4, -0x6558($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6558);
    // 0x80241028: lui         $a2, 0x4429
    ctx->r6 = S32(0X4429 << 16);
    // 0x8024102C: ori         $a2, $a2, 0x1333
    ctx->r6 = ctx->r6 | 0X1333;
    // 0x80241030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80241034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80241038: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8024103C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80241040: jal         0x801264D4
    // 0x80241044: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801264D4)(rdram, ctx);
        goto after_3;
    // 0x80241044: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80241048: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x8024104C: lwc1        $f6, -0x6554($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6554);
    // 0x80241050: lui         $a2, 0x4429
    ctx->r6 = S32(0X4429 << 16);
    // 0x80241054: ori         $a2, $a2, 0x1333
    ctx->r6 = ctx->r6 | 0X1333;
    // 0x80241058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8024105C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80241060: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80241064: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80241068: jal         0x801264D4
    // 0x8024106C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801264D4)(rdram, ctx);
        goto after_4;
    // 0x8024106C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80241070: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80241074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80241078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8024107C: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80241080: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x80241084: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80241088: jal         0x8012C89C
    // 0x8024108C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x8024108C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80241090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80241094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80241098: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8024109C: jal         0x8012C89C
    // 0x802410A0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x802410A0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_6:
    // 0x802410A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x802410A8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x802410AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x802410B0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x802410B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x802410B8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802410BC: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802410C0: addiu       $a1, $a1, 0x10F4
    ctx->r5 = ADD32(ctx->r5, 0X10F4);
    // 0x802410C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802410C8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802410CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x802410D0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x802410D4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x802410D8: jal         0x800058DC
    // 0x802410DC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x802410DC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_7:
    // 0x802410E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x802410E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802410E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x802410EC: jr          $ra
    // 0x802410F0: nop

    return;
    // 0x802410F0: nop

;}
RECOMP_FUNC void M12_FUN_802410f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802410F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802410F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802410FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80241100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80241104: jal         0x80133A24
    // 0x80241108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80241108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8024110C: beq         $v0, $zero, L_80241198
    if (ctx->r2 == 0) {
        // 0x80241110: addiu       $t6, $zero, 0xF
        ctx->r14 = ADD32(0, 0XF);
            goto L_80241198;
    }
    // 0x80241110: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80241114: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80241118: addiu       $a0, $zero, 0x1C3
    ctx->r4 = ADD32(0, 0X1C3);
    // 0x8024111C: jal         0x80020744
    // 0x80241120: sh          $t6, 0x90($t7)
    MEM_H(0X90, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80241120: sh          $t6, 0x90($t7)
    MEM_H(0X90, ctx->r15) = ctx->r14;
    after_1:
    // 0x80241124: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80241128: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8024112C: lw          $v1, 0xE0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE0);
    // 0x80241130: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80241134: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80241138: sh          $t8, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r24;
    // 0x8024113C: sh          $t9, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r25;
    // 0x80241140: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x80241144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80241148: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8024114C: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80241150: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241154: addiu       $t2, $zero, 0x1100
    ctx->r10 = ADD32(0, 0X1100);
    // 0x80241158: swc1        $f4, 0x198($v0)
    MEM_W(0X198, ctx->r2) = ctx->f4.u32l;
    // 0x8024115C: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x80241160: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241164: addiu       $a1, $a1, 0x11A8
    ctx->r5 = ADD32(ctx->r5, 0X11A8);
    // 0x80241168: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8024116C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241170: swc1        $f6, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->f6.u32l;
    // 0x80241174: lwc1        $f8, -0x6550($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6550);
    // 0x80241178: lui         $at, 0x43A6
    ctx->r1 = S32(0X43A6 << 16);
    // 0x8024117C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80241180: sh          $t2, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r10;
    // 0x80241184: swc1        $f0, 0xF04($v0)
    MEM_W(0XF04, ctx->r2) = ctx->f0.u32l;
    // 0x80241188: swc1        $f0, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f0.u32l;
    // 0x8024118C: swc1        $f8, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->f8.u32l;
    // 0x80241190: jal         0x800058DC
    // 0x80241194: swc1        $f10, 0xF18($v0)
    MEM_W(0XF18, ctx->r2) = ctx->f10.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80241194: swc1        $f10, 0xF18($v0)
    MEM_W(0XF18, ctx->r2) = ctx->f10.u32l;
    after_2:
L_80241198:
    // 0x80241198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8024119C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802411A0: jr          $ra
    // 0x802411A4: nop

    return;
    // 0x802411A4: nop

;}
RECOMP_FUNC void M12_FUN_802411a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802411A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802411AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802411B0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x802411B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802411B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802411BC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x802411C0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802411C4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x802411C8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802411CC: addiu       $a1, $a1, 0x1200
    ctx->r5 = ADD32(ctx->r5, 0X1200);
    // 0x802411D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x802411D4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x802411D8: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
    // 0x802411DC: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x802411E0: bne         $v1, $zero, L_802411F0
    if (ctx->r3 != 0) {
        // 0x802411E4: sh          $t7, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r15;
            goto L_802411F0;
    }
    // 0x802411E4: sh          $t7, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r15;
    // 0x802411E8: jal         0x800058DC
    // 0x802411EC: sh          $t8, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802411EC: sh          $t8, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r24;
    after_0:
L_802411F0:
    // 0x802411F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802411F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802411F8: jr          $ra
    // 0x802411FC: nop

    return;
    // 0x802411FC: nop

;}
RECOMP_FUNC void M12_FUN_80241200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241208: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8024120C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80241210: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80241214: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x80241218: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x8024121C: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x80241220: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
    // 0x80241224: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80241228: bne         $v1, $zero, L_80241254
    if (ctx->r3 != 0) {
        // 0x8024122C: sh          $t9, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r25;
            goto L_80241254;
    }
    // 0x8024122C: sh          $t9, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r25;
    // 0x80241230: addiu       $a0, $zero, 0x1C5
    ctx->r4 = ADD32(0, 0X1C5);
    // 0x80241234: jal         0x80020744
    // 0x80241238: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80241238: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8024123C: jal         0x80133980
    // 0x80241240: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_1;
    // 0x80241240: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80241244: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8024124C: jal         0x800058DC
    // 0x80241250: addiu       $a1, $a1, 0x1264
    ctx->r5 = ADD32(ctx->r5, 0X1264);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80241250: addiu       $a1, $a1, 0x1264
    ctx->r5 = ADD32(ctx->r5, 0X1264);
    after_2:
L_80241254:
    // 0x80241254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8024125C: jr          $ra
    // 0x80241260: nop

    return;
    // 0x80241260: nop

;}
RECOMP_FUNC void M12_FUN_80241264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8024126C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80241270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80241274: jal         0x80133A24
    // 0x80241278: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80241278: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8024127C: beq         $v0, $zero, L_80241298
    if (ctx->r2 == 0) {
        // 0x80241280: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80241298;
    }
    // 0x80241280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241284: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80241288: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8024128C: sh          $t6, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r14;
    // 0x80241290: jal         0x800058DC
    // 0x80241294: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, 0X12A8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80241294: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, 0X12A8);
    after_1:
L_80241298:
    // 0x80241298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8024129C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802412A0: jr          $ra
    // 0x802412A4: nop

    return;
    // 0x802412A4: nop

;}
RECOMP_FUNC void M12_FUN_802412a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802412A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802412AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802412B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802412B4: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x802412B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x802412BC: addiu       $t7, $zero, 0x3F
    ctx->r15 = ADD32(0, 0X3F);
    // 0x802412C0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x802412C4: bne         $v0, $zero, L_802412EC
    if (ctx->r2 != 0) {
        // 0x802412C8: sh          $t6, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r14;
            goto L_802412EC;
    }
    // 0x802412C8: sh          $t6, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r14;
    // 0x802412CC: sh          $t7, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r15;
    // 0x802412D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x802412D4: jal         0x80020744
    // 0x802412D8: addiu       $a0, $zero, 0x1C4
    ctx->r4 = ADD32(0, 0X1C4);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x802412D8: addiu       $a0, $zero, 0x1C4
    ctx->r4 = ADD32(0, 0X1C4);
    after_0:
    // 0x802412DC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802412E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x802412E4: jal         0x800058DC
    // 0x802412E8: addiu       $a1, $a1, 0x12FC
    ctx->r5 = ADD32(ctx->r5, 0X12FC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x802412E8: addiu       $a1, $a1, 0x12FC
    ctx->r5 = ADD32(ctx->r5, 0X12FC);
    after_1:
L_802412EC:
    // 0x802412EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802412F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802412F4: jr          $ra
    // 0x802412F8: nop

    return;
    // 0x802412F8: nop

;}
RECOMP_FUNC void M12_FUN_802412fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802412FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80241300: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80241304(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80241304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241304: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80241308: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8024130C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80241310: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80241314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241318: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x8024131C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80241320: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80241324: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80241328: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x8024132C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80241330: lui         $at, 0x437D
    ctx->r1 = S32(0X437D << 16);
    // 0x80241334: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80241338: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8024133C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80241340: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80241344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241348: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8024134C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80241350: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80241354: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80241358: lui         $a0, 0x8025
    ctx->r4 = S32(0X8025 << 16);
    // 0x8024135C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80241360: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80241364: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80241368: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8024136C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80241370: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80241374: addiu       $a0, $a0, -0x66A8
    ctx->r4 = ADD32(ctx->r4, -0X66A8);
    // 0x80241378: addiu       $a1, $zero, 0x182
    ctx->r5 = ADD32(0, 0X182);
    // 0x8024137C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80241380: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80241384: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80241388: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8024138C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80241390: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80241394: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80241398: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8024139C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x802413A0: jal         0x8011AAF4
    // 0x802413A4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x802413A4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x802413A8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x802413AC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x802413B0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x802413B4: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x802413B8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x802413BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x802413C0: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x802413C4: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x802413C8: addiu       $t1, $t0, -0x40
    ctx->r9 = ADD32(ctx->r8, -0X40);
    // 0x802413CC: sh          $t1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r9;
    // 0x802413D0: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x802413D4: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x802413D8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x802413DC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x802413E0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x802413E4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x802413E8: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x802413EC: lh          $a0, 0x90($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X90);
    // 0x802413F0: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x802413F4: bne         $a0, $zero, L_80241418
    if (ctx->r4 != 0) {
        // 0x802413F8: sh          $t3, 0x90($a2)
        MEM_H(0X90, ctx->r6) = ctx->r11;
            goto L_80241418;
    }
    // 0x802413F8: sh          $t3, 0x90($a2)
    MEM_H(0X90, ctx->r6) = ctx->r11;
    // 0x802413FC: addiu       $a0, $zero, 0x1C6
    ctx->r4 = ADD32(0, 0X1C6);
    // 0x80241400: jal         0x80020744
    // 0x80241404: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80241404: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x80241408: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8024140C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80241410: jal         0x800058DC
    // 0x80241414: addiu       $a1, $a1, 0x1428
    ctx->r5 = ADD32(ctx->r5, 0X1428);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80241414: addiu       $a1, $a1, 0x1428
    ctx->r5 = ADD32(ctx->r5, 0X1428);
    after_2:
L_80241418:
    // 0x80241418: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8024141C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80241420: jr          $ra
    // 0x80241424: nop

    return;
    // 0x80241424: nop

;}
RECOMP_FUNC void M12_FUN_80241428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8024142C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80241430(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80241430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241430: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80241434: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80241438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8024143C: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80241440: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241444: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80241448: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8024144C: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80241450: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80241454: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80241458: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8024145C: lui         $at, 0x437D
    ctx->r1 = S32(0X437D << 16);
    // 0x80241460: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80241464: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80241468: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8024146C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80241470: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241474: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80241478: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8024147C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80241480: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80241484: lui         $a0, 0x8025
    ctx->r4 = S32(0X8025 << 16);
    // 0x80241488: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8024148C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80241490: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80241494: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80241498: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8024149C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x802414A0: addiu       $a0, $a0, -0x666C
    ctx->r4 = ADD32(ctx->r4, -0X666C);
    // 0x802414A4: addiu       $a1, $zero, 0x18E
    ctx->r5 = ADD32(0, 0X18E);
    // 0x802414A8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x802414AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802414B0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x802414B4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x802414B8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x802414BC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x802414C0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x802414C4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x802414C8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x802414CC: jal         0x8011AAF4
    // 0x802414D0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x802414D0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x802414D4: bne         $v0, $zero, L_802414E8
    if (ctx->r2 != 0) {
        // 0x802414D8: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_802414E8;
    }
    // 0x802414D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x802414DC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802414E0: jal         0x800058DC
    // 0x802414E4: addiu       $a1, $a1, 0x14F8
    ctx->r5 = ADD32(ctx->r5, 0X14F8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x802414E4: addiu       $a1, $a1, 0x14F8
    ctx->r5 = ADD32(ctx->r5, 0X14F8);
    after_1:
L_802414E8:
    // 0x802414E8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x802414EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x802414F0: jr          $ra
    // 0x802414F4: nop

    return;
    // 0x802414F4: nop

;}
RECOMP_FUNC void M12_FUN_802414f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802414F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x802414FC: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241500: lwc1        $f4, -0x654C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X654C);
    // 0x80241504: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x80241508: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8024150C: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x80241510: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80241514: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241518: lwc1        $f10, -0x6548($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6548);
    // 0x8024151C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80241520: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80241524: lui         $at, 0x439F
    ctx->r1 = S32(0X439F << 16);
    // 0x80241528: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8024152C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80241530: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80241534: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80241538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8024153C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80241540: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80241544: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80241548: lui         $a0, 0x8025
    ctx->r4 = S32(0X8025 << 16);
    // 0x8024154C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80241550: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80241554: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80241558: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8024155C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80241560: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80241564: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    // 0x80241568: addiu       $a1, $zero, 0x198
    ctx->r5 = ADD32(0, 0X198);
    // 0x8024156C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80241570: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80241574: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80241578: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8024157C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80241580: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80241584: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80241588: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8024158C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80241590: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80241594: jal         0x8011AAF4
    // 0x80241598: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x80241598: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8024159C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x802415A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x802415A4: sh          $t9, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r25;
    // 0x802415A8: jal         0x80133980
    // 0x802415AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_1;
    // 0x802415AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x802415B0: jal         0x801FBB20
    // 0x802415B4: nop

    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_2;
    // 0x802415B4: nop

    after_2:
    // 0x802415B8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802415BC: addiu       $a1, $a1, 0x15D8
    ctx->r5 = ADD32(ctx->r5, 0X15D8);
    // 0x802415C0: jal         0x800058DC
    // 0x802415C4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x802415C4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x802415C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x802415CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x802415D0: jr          $ra
    // 0x802415D4: nop

    return;
    // 0x802415D4: nop

;}
RECOMP_FUNC void M12_FUN_802415d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802415D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802415DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802415E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x802415E4: jal         0x80150584
    // 0x802415E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x802415E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x802415EC: beql        $v0, $zero, L_80241600
    if (ctx->r2 == 0) {
        // 0x802415F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80241600;
    }
    goto skip_0;
    // 0x802415F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x802415F4: jal         0x80005700
    // 0x802415F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x802415F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x802415FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80241600:
    // 0x80241600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241604: jr          $ra
    // 0x80241608: nop

    return;
    // 0x80241608: nop

;}
RECOMP_FUNC void M12_FUN_8024160c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024160C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80241610: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80241614: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80241618: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8024161C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80241620: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80241624: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80241628: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8024162C: jal         0x80005F6C
    // 0x80241630: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x80241630: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80241634: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80241638: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x8024163C: jal         0x80005F6C
    // 0x80241640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_1;
    // 0x80241640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80241644: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80241648: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x8024164C: jal         0x80005F6C
    // 0x80241650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_2;
    // 0x80241650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80241654: jal         0x80006214
    // 0x80241658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80241658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8024165C: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241660: lwc1        $f20, -0x6544($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6544);
    // 0x80241664: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241668: lwc1        $f4, -0x6540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6540);
    // 0x8024166C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80241670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80241674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80241678: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8024167C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80241680: jal         0x801264D4
    // 0x80241684: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801264D4)(rdram, ctx);
        goto after_4;
    // 0x80241684: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80241688: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x8024168C: lwc1        $f6, -0x653C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X653C);
    // 0x80241690: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80241694: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80241698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8024169C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x802416A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x802416A4: jal         0x801264D4
    // 0x802416A8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801264D4)(rdram, ctx);
        goto after_5;
    // 0x802416A8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x802416AC: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x802416B0: lwc1        $f8, -0x6538($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6538);
    // 0x802416B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x802416B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802416BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x802416C0: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x802416C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x802416C8: jal         0x801264D4
    // 0x802416CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801264D4)(rdram, ctx);
        goto after_6;
    // 0x802416CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x802416D0: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    // 0x802416D4: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x802416D8: lwc1        $f0, -0x6534($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6534);
    // 0x802416DC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x802416E0: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
    // 0x802416E4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802416E8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x802416EC: ori         $a0, $a0, 0x600
    ctx->r4 = ctx->r4 | 0X600;
    // 0x802416F0: sw          $a0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r4;
    // 0x802416F4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x802416F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x802416FC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80241700: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80241704: addiu       $t2, $t2, -0x4860
    ctx->r10 = ADD32(ctx->r10, -0X4860);
    // 0x80241708: or          $t3, $t2, $a1
    ctx->r11 = ctx->r10 | ctx->r5;
    // 0x8024170C: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x80241710: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80241714: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80241718: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x8024171C: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x80241720: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80241724: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80241728: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x8024172C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80241730: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80241734: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x80241738: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    // 0x8024173C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80241740: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80241744: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80241748: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8024174C: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241750: sb          $zero, 0x48($t7)
    MEM_B(0X48, ctx->r15) = 0;
    // 0x80241754: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80241758: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8024175C: sb          $a2, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r6;
    // 0x80241760: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80241764: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80241768: sb          $zero, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = 0;
    // 0x8024176C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80241770: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80241774: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x80241778: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8024177C: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80241780: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x80241784: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80241788: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8024178C: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x80241790: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80241794: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80241798: swc1        $f20, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f20.u32l;
    // 0x8024179C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802417A0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802417A4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x802417A8: addiu       $t0, $t0, -0x4760
    ctx->r8 = ADD32(ctx->r8, -0X4760);
    // 0x802417AC: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x802417B0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802417B4: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x802417B8: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x802417BC: swc1        $f12, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f12.u32l;
    // 0x802417C0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x802417C4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x802417C8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x802417CC: sh          $a3, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r7;
    // 0x802417D0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x802417D4: sw          $a0, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r4;
    // 0x802417D8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x802417DC: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x802417E0: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x802417E4: ori         $t9, $t8, 0x4100
    ctx->r25 = ctx->r24 | 0X4100;
    // 0x802417E8: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x802417EC: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x802417F0: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x802417F4: sw          $t1, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r9;
    // 0x802417F8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x802417FC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80241800: sb          $t3, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r11;
    // 0x80241804: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80241808: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8024180C: sb          $zero, 0x48($t8)
    MEM_B(0X48, ctx->r24) = 0;
    // 0x80241810: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80241814: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80241818: sb          $a2, 0x49($t0)
    MEM_B(0X49, ctx->r8) = ctx->r6;
    // 0x8024181C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80241820: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80241824: sb          $zero, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = 0;
    // 0x80241828: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8024182C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80241830: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80241834: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80241838: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x8024183C: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80241840: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80241844: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80241848: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x8024184C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80241850: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80241854: swc1        $f20, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f20.u32l;
    // 0x80241858: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8024185C: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80241860: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80241864: addiu       $t2, $t2, -0x47B0
    ctx->r10 = ADD32(ctx->r10, -0X47B0);
    // 0x80241868: swc1        $f2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f2.u32l;
    // 0x8024186C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80241870: or          $t1, $t2, $a1
    ctx->r9 = ctx->r10 | ctx->r5;
    // 0x80241874: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x80241878: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8024187C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80241880: swc1        $f12, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f12.u32l;
    // 0x80241884: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80241888: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x8024188C: sh          $a3, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r7;
    // 0x80241890: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80241894: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80241898: sw          $a0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r4;
    // 0x8024189C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x802418A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802418A4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x802418A8: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x802418AC: ori         $t0, $t9, 0x100
    ctx->r8 = ctx->r25 | 0X100;
    // 0x802418B0: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x802418B4: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x802418B8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802418BC: sw          $t1, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r9;
    // 0x802418C0: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x802418C4: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x802418C8: sb          $zero, 0x48($t6)
    MEM_B(0X48, ctx->r14) = 0;
    // 0x802418CC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x802418D0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802418D4: sb          $a2, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r6;
    // 0x802418D8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x802418DC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x802418E0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802418E4: sb          $zero, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = 0;
    // 0x802418E8: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x802418EC: lw          $t1, 0x30($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X30);
    // 0x802418F0: sb          $t2, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r10;
    // 0x802418F4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x802418F8: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x802418FC: swc1        $f20, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f20.u32l;
    // 0x80241900: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80241904: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80241908: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x8024190C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80241910: lwc1        $f16, -0x6530($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6530);
    // 0x80241914: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80241918: jal         0x8012C89C
    // 0x8024191C: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x8024191C: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
    after_7:
    // 0x80241920: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241924: addiu       $a1, $a1, 0x1948
    ctx->r5 = ADD32(ctx->r5, 0X1948);
    // 0x80241928: jal         0x800058DC
    // 0x8024192C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8024192C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80241930: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80241934: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80241938: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8024193C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80241940: jr          $ra
    // 0x80241944: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80241944: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80241948(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80241948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8024194C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241950: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80241954: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80241958: jal         0x80133A24
    // 0x8024195C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x8024195C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80241960: beq         $v0, $zero, L_80241974
    if (ctx->r2 == 0) {
        // 0x80241964: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80241974;
    }
    // 0x80241964: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241968: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8024196C: jal         0x800058DC
    // 0x80241970: addiu       $a1, $a1, 0x1984
    ctx->r5 = ADD32(ctx->r5, 0X1984);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80241970: addiu       $a1, $a1, 0x1984
    ctx->r5 = ADD32(ctx->r5, 0X1984);
    after_1:
L_80241974:
    // 0x80241974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8024197C: jr          $ra
    // 0x80241980: nop

    return;
    // 0x80241980: nop

;}
RECOMP_FUNC void M12_FUN_80241984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241988: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8024198C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241990: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80241994: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241998: sh          $t6, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r14;
    // 0x8024199C: jal         0x800058DC
    // 0x802419A0: addiu       $a1, $a1, 0x19B4
    ctx->r5 = ADD32(ctx->r5, 0X19B4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802419A0: addiu       $a1, $a1, 0x19B4
    ctx->r5 = ADD32(ctx->r5, 0X19B4);
    after_0:
    // 0x802419A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802419A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802419AC: jr          $ra
    // 0x802419B0: nop

    return;
    // 0x802419B0: nop

;}
RECOMP_FUNC void M12_FUN_802419b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802419B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802419B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802419BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802419C0: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x802419C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x802419C8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x802419CC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x802419D0: bne         $v0, $zero, L_80241A20
    if (ctx->r2 != 0) {
        // 0x802419D4: sh          $t6, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r14;
            goto L_80241A20;
    }
    // 0x802419D4: sh          $t6, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r14;
    // 0x802419D8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802419DC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x802419E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x802419E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x802419E8: lui         $t9, 0x348
    ctx->r25 = S32(0X348 << 16);
    // 0x802419EC: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x802419F0: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x802419F4: sh          $t7, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r15;
    // 0x802419F8: sh          $t8, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r24;
    // 0x802419FC: sw          $t9, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r25;
    // 0x80241A00: sh          $zero, 0xF0C($v0)
    MEM_H(0XF0C, ctx->r2) = 0;
    // 0x80241A04: sh          $t0, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r8;
    // 0x80241A08: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80241A0C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241A10: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    // 0x80241A14: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x80241A18: jal         0x800058DC
    // 0x80241A1C: addiu       $a1, $a1, 0x1AF0
    ctx->r5 = ADD32(ctx->r5, 0X1AF0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80241A1C: addiu       $a1, $a1, 0x1AF0
    ctx->r5 = ADD32(ctx->r5, 0X1AF0);
    after_0:
L_80241A20:
    // 0x80241A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241A28: jr          $ra
    // 0x80241A2C: nop

    return;
    // 0x80241A2C: nop

;}
RECOMP_FUNC void M12_FUN_80241a30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241A30: jr          $ra
    // 0x80241A34: nop

    return;
    // 0x80241A34: nop

;}
RECOMP_FUNC void M12_FUN_80241a38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241A38: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80241A3C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80241A40: lw          $t6, 0xE0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80241a44(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80241a44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80241A50: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80241A54: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241A58: lwc1        $f4, -0x652C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X652C);
    // 0x80241A5C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80241A60: lui         $at, 0x43A6
    ctx->r1 = S32(0X43A6 << 16);
    // 0x80241A64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80241A68: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80241A6C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80241A70: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80241A74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80241A78: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80241A7C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80241A80: lui         $t9, 0x348
    ctx->r25 = S32(0X348 << 16);
    // 0x80241A84: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241A88: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80241A8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80241A90: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80241A94: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80241A98: ori         $t9, $t9, 0x17
    ctx->r25 = ctx->r25 | 0X17;
    // 0x80241A9C: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x80241AA0: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80241AA4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80241AA8: addiu       $a1, $a1, 0x1AF0
    ctx->r5 = ADD32(ctx->r5, 0X1AF0);
    // 0x80241AAC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80241AB0: nop

    // 0x80241AB4: bc1tl       L_80241AE4
    if (c1cs) {
        // 0x80241AB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80241AE4;
    }
    goto skip_0;
    // 0x80241AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80241ABC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80241AC0: sh          $t7, 0x194($v1)
    MEM_H(0X194, ctx->r3) = ctx->r15;
    // 0x80241AC4: sh          $t8, 0x192($v1)
    MEM_H(0X192, ctx->r3) = ctx->r24;
    // 0x80241AC8: sw          $t9, 0xF10($v1)
    MEM_W(0XF10, ctx->r3) = ctx->r25;
    // 0x80241ACC: sh          $zero, 0xF0C($v1)
    MEM_H(0XF0C, ctx->r3) = 0;
    // 0x80241AD0: sh          $t0, 0xF00($v1)
    MEM_H(0XF00, ctx->r3) = ctx->r8;
    // 0x80241AD4: swc1        $f8, 0xF08($v1)
    MEM_W(0XF08, ctx->r3) = ctx->f8.u32l;
    // 0x80241AD8: jal         0x800058DC
    // 0x80241ADC: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80241ADC: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    after_0:
    // 0x80241AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80241AE4:
    // 0x80241AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241AE8: jr          $ra
    // 0x80241AEC: nop

    return;
    // 0x80241AEC: nop

;}
RECOMP_FUNC void M12_FUN_80241af0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241AF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80241AFC: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x80241B00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80241B04: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80241B08: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80241B0C: bne         $v0, $zero, L_80241B78
    if (ctx->r2 != 0) {
        // 0x80241B10: sh          $t6, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r14;
            goto L_80241B78;
    }
    // 0x80241B10: sh          $t6, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r14;
    // 0x80241B14: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80241B18: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80241B1C: sh          $t7, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r15;
    // 0x80241B20: sh          $t8, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r24;
    // 0x80241B24: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241B28: lwc1        $f4, -0x6528($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6528);
    // 0x80241B2C: lui         $at, 0x43A6
    ctx->r1 = S32(0X43A6 << 16);
    // 0x80241B30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241B34: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241B38: swc1        $f4, 0x198($v0)
    MEM_W(0X198, ctx->r2) = ctx->f4.u32l;
    // 0x80241B3C: swc1        $f6, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->f6.u32l;
    // 0x80241B40: lwc1        $f8, -0x6524($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6524);
    // 0x80241B44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80241B48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80241B4C: lui         $t9, 0x168
    ctx->r25 = S32(0X168 << 16);
    // 0x80241B50: ori         $t9, $t9, 0x3E
    ctx->r25 = ctx->r25 | 0X3E;
    // 0x80241B54: addiu       $t0, $zero, 0x1100
    ctx->r8 = ADD32(0, 0X1100);
    // 0x80241B58: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241B5C: sw          $t9, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r25;
    // 0x80241B60: sh          $zero, 0xF0C($v0)
    MEM_H(0XF0C, ctx->r2) = 0;
    // 0x80241B64: sh          $t0, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r8;
    // 0x80241B68: addiu       $a1, $a1, 0x1B88
    ctx->r5 = ADD32(ctx->r5, 0X1B88);
    // 0x80241B6C: swc1        $f8, 0xF04($v0)
    MEM_W(0XF04, ctx->r2) = ctx->f8.u32l;
    // 0x80241B70: jal         0x800058DC
    // 0x80241B74: swc1        $f10, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f10.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80241B74: swc1        $f10, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f10.u32l;
    after_0:
L_80241B78:
    // 0x80241B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241B80: jr          $ra
    // 0x80241B84: nop

    return;
    // 0x80241B84: nop

;}
RECOMP_FUNC void M12_FUN_80241b88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241B88: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80241B8C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80241B90: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x80241B94: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80241B98: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80241B9C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80241BA0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80241BA4: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241BA8: lwc1        $f4, -0x6520($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6520);
    // 0x80241BAC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80241BB0: lui         $at, 0x43A6
    ctx->r1 = S32(0X43A6 << 16);
    // 0x80241BB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80241BB8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80241BBC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80241BC0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80241BC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80241BC8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80241BCC: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80241BD0: lui         $a0, 0x8025
    ctx->r4 = S32(0X8025 << 16);
    // 0x80241BD4: addiu       $a0, $a0, -0x65AC
    ctx->r4 = ADD32(ctx->r4, -0X65AC);
    // 0x80241BD8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80241BDC: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241BE0: addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    // 0x80241BE4: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80241BE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80241BEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80241BF0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80241BF4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80241BF8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80241BFC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80241C00: nop

    // 0x80241C04: bc1tl       L_80241CBC
    if (c1cs) {
        // 0x80241C08: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80241CBC;
    }
    goto skip_0;
    // 0x80241C08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80241C0C: lwc1        $f8, -0x651C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X651C);
    // 0x80241C10: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80241C14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80241C18: lui         $at, 0x4393
    ctx->r1 = S32(0X4393 << 16);
    // 0x80241C1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80241C20: lui         $at, 0x4428
    ctx->r1 = S32(0X4428 << 16);
    // 0x80241C24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80241C28: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80241C2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80241C30: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241C34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80241C38: lwc1        $f6, -0x6518($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6518);
    // 0x80241C3C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80241C40: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80241C44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80241C48: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80241C4C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80241C50: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80241C54: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80241C58: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80241C5C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80241C60: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80241C64: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80241C68: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80241C6C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80241C70: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80241C74: jal         0x8011AAF4
    // 0x80241C78: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x80241C78: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80241C7C: bne         $v0, $zero, L_80241CB8
    if (ctx->r2 != 0) {
        // 0x80241C80: lw          $t1, 0x50($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X50);
            goto L_80241CB8;
    }
    // 0x80241C80: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80241C84: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x80241C88: sh          $t0, 0x94($t1)
    MEM_H(0X94, ctx->r9) = ctx->r8;
    // 0x80241C8C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80241C90: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x80241C94: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    // 0x80241C98: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80241C9C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80241CA0: jal         0x80020744
    // 0x80241CA4: sh          $t2, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r10;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80241CA4: sh          $t2, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r10;
    after_1:
    // 0x80241CA8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241CAC: addiu       $a1, $a1, 0x1CC8
    ctx->r5 = ADD32(ctx->r5, 0X1CC8);
    // 0x80241CB0: jal         0x800058DC
    // 0x80241CB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80241CB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
L_80241CB8:
    // 0x80241CB8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80241CBC:
    // 0x80241CBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80241CC0: jr          $ra
    // 0x80241CC4: nop

    return;
    // 0x80241CC4: nop

;}
RECOMP_FUNC void M12_FUN_80241cc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241CD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80241CD4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80241CD8: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241CDC: ldc1        $f8, -0x6510($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6510);
    // 0x80241CE0: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80241CE4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80241CE8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80241CEC: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80241CF0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80241CF4: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80241CF8: lh          $v1, 0x94($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X94);
    // 0x80241CFC: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80241D00: bne         $v1, $zero, L_80241D6C
    if (ctx->r3 != 0) {
        // 0x80241D04: sh          $t8, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r24;
            goto L_80241D6C;
    }
    // 0x80241D04: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    // 0x80241D08: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80241D0C: lui         $at, 0x43AB
    ctx->r1 = S32(0X43AB << 16);
    // 0x80241D10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80241D14: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80241D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80241D1C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80241D20: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80241D24: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80241D28: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80241D2C: jal         0x8012C89C
    // 0x80241D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80241D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80241D34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80241D3C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80241D40: jal         0x8012C89C
    // 0x80241D44: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_1;
    // 0x80241D44: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x80241D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241D4C: addiu       $t2, $zero, 0x3F
    ctx->r10 = ADD32(0, 0X3F);
    // 0x80241D50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80241D54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80241D58: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241D5C: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    // 0x80241D60: sh          $t3, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r11;
    // 0x80241D64: jal         0x800058DC
    // 0x80241D68: addiu       $a1, $a1, 0x1D7C
    ctx->r5 = ADD32(ctx->r5, 0X1D7C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80241D68: addiu       $a1, $a1, 0x1D7C
    ctx->r5 = ADD32(ctx->r5, 0X1D7C);
    after_2:
L_80241D6C:
    // 0x80241D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241D74: jr          $ra
    // 0x80241D78: nop

    return;
    // 0x80241D78: nop

;}
RECOMP_FUNC void M12_FUN_80241d7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241D84: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80241D88: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80241D8C: ldc1        $f8, -0x6508($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6508);
    // 0x80241D90: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80241D94: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80241D98: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80241D9C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80241DA0: swc1        $f16, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f16.u32l;
    // 0x80241DA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80241DA8: lwc1        $f0, 0x90($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80241DAC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80241DB0: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x80241DB4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80241DB8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80241DBC: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80241DC0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80241DC4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80241DC8: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x80241DCC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80241DD0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80241DD4: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x80241DD8: addiu       $t5, $t4, 0xFE
    ctx->r13 = ADD32(ctx->r12, 0XFE);
    // 0x80241DDC: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x80241DE0: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80241DE4: lwc1        $f0, 0x90($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80241DE8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80241DEC: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x80241DF0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80241DF4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80241DF8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80241DFC: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80241E00: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80241E04: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80241E08: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x80241E0C: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x80241E10: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x80241E14: lh          $t4, 0x12($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X12);
    // 0x80241E18: addiu       $t5, $t4, 0xFE
    ctx->r13 = ADD32(ctx->r12, 0XFE);
    // 0x80241E1C: sh          $t5, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r13;
    // 0x80241E20: lh          $a3, 0x94($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X94);
    // 0x80241E24: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x80241E28: bne         $a3, $zero, L_80241E54
    if (ctx->r7 != 0) {
        // 0x80241E2C: sh          $t6, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r14;
            goto L_80241E54;
    }
    // 0x80241E2C: sh          $t6, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r14;
    // 0x80241E30: sh          $t7, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r15;
    // 0x80241E34: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80241E38: addiu       $a0, $a0, 0x56C0
    ctx->r4 = ADD32(ctx->r4, 0X56C0);
    // 0x80241E3C: jal         0x800179B0
    // 0x80241E40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x80241E40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80241E44: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241E48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241E4C: jal         0x800058DC
    // 0x80241E50: addiu       $a1, $a1, 0x1E64
    ctx->r5 = ADD32(ctx->r5, 0X1E64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80241E50: addiu       $a1, $a1, 0x1E64
    ctx->r5 = ADD32(ctx->r5, 0X1E64);
    after_1:
L_80241E54:
    // 0x80241E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241E5C: jr          $ra
    // 0x80241E60: nop

    return;
    // 0x80241E60: nop

;}
RECOMP_FUNC void M12_FUN_80241e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241E6C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80241E70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241E74: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80241E78: lui         $t4, 0x2A8
    ctx->r12 = S32(0X2A8 << 16);
    // 0x80241E7C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80241E80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80241E84: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80241E88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80241E8C: ori         $t4, $t4, 0x3
    ctx->r12 = ctx->r12 | 0X3;
    // 0x80241E90: swc1        $f8, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f8.u32l;
    // 0x80241E94: lwc1        $f10, 0x98($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80241E98: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80241E9C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241EA0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80241EA4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80241EA8: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x80241EAC: addiu       $a1, $a1, 0x1F18
    ctx->r5 = ADD32(ctx->r5, 0X1F18);
    // 0x80241EB0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80241EB4: nop

    // 0x80241EB8: bgez        $t7, L_80241ECC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80241EBC: andi        $t8, $t7, 0x1F
        ctx->r24 = ctx->r15 & 0X1F;
            goto L_80241ECC;
    }
    // 0x80241EBC: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x80241EC0: beq         $t8, $zero, L_80241ECC
    if (ctx->r24 == 0) {
        // 0x80241EC4: nop
    
            goto L_80241ECC;
    }
    // 0x80241EC4: nop

    // 0x80241EC8: addiu       $t8, $t8, -0x20
    ctx->r24 = ADD32(ctx->r24, -0X20);
L_80241ECC:
    // 0x80241ECC: sb          $t8, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r24;
    // 0x80241ED0: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x80241ED4: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80241ED8: bne         $v0, $zero, L_80241F08
    if (ctx->r2 != 0) {
        // 0x80241EDC: sh          $t1, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r9;
            goto L_80241F08;
    }
    // 0x80241EDC: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x80241EE0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80241EE4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80241EE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80241EEC: sh          $t2, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r10;
    // 0x80241EF0: sh          $t3, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r11;
    // 0x80241EF4: sw          $t4, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r12;
    // 0x80241EF8: sh          $zero, 0xF0C($v0)
    MEM_H(0XF0C, ctx->r2) = 0;
    // 0x80241EFC: sh          $t5, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r13;
    // 0x80241F00: jal         0x800058DC
    // 0x80241F04: swc1        $f18, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f18.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80241F04: swc1        $f18, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f18.u32l;
    after_0:
L_80241F08:
    // 0x80241F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241F10: jr          $ra
    // 0x80241F14: nop

    return;
    // 0x80241F14: nop

;}
RECOMP_FUNC void M12_FUN_80241f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241F20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80241F24: jal         0x800178E8
    // 0x80241F28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80241F28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80241F2C: beq         $v0, $zero, L_80241F78
    if (ctx->r2 == 0) {
        // 0x80241F30: lui         $a0, 0x8024
        ctx->r4 = S32(0X8024 << 16);
            goto L_80241F78;
    }
    // 0x80241F30: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80241F34: jal         0x80017990
    // 0x80241F38: addiu       $a0, $a0, 0x577C
    ctx->r4 = ADD32(ctx->r4, 0X577C);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_1;
    // 0x80241F38: addiu       $a0, $a0, 0x577C
    ctx->r4 = ADD32(ctx->r4, 0X577C);
    after_1:
    // 0x80241F3C: jal         0x80020744
    // 0x80241F40: addiu       $a0, $zero, 0x3DF
    ctx->r4 = ADD32(0, 0X3DF);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80241F40: addiu       $a0, $zero, 0x3DF
    ctx->r4 = ADD32(0, 0X3DF);
    after_2:
    // 0x80241F44: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80241F48: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80241F4C: lui         $t7, 0x2A8
    ctx->r15 = S32(0X2A8 << 16);
    // 0x80241F50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80241F54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80241F58: ori         $t7, $t7, 0x4
    ctx->r15 = ctx->r15 | 0X4;
    // 0x80241F5C: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x80241F60: sw          $t7, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r15;
    // 0x80241F64: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80241F68: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241F6C: addiu       $a1, $a1, 0x1F88
    ctx->r5 = ADD32(ctx->r5, 0X1F88);
    // 0x80241F70: jal         0x800058DC
    // 0x80241F74: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80241F74: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    after_3:
L_80241F78:
    // 0x80241F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241F80: jr          $ra
    // 0x80241F84: nop

    return;
    // 0x80241F84: nop

;}
RECOMP_FUNC void M12_FUN_80241f88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241F90: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80241F94: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80241F98: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80241F9C: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x80241FA0: addiu       $t8, $t7, 0x7F
    ctx->r24 = ADD32(ctx->r15, 0X7F);
    // 0x80241FA4: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x80241FA8: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80241FAC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80241FB0: addiu       $a1, $a1, 0x1FEC
    ctx->r5 = ADD32(ctx->r5, 0X1FEC);
    // 0x80241FB4: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80241FB8: lh          $t0, 0x12($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X12);
    // 0x80241FBC: addiu       $t1, $t0, 0x7F
    ctx->r9 = ADD32(ctx->r8, 0X7F);
    // 0x80241FC0: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x80241FC4: lh          $a2, 0x94($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X94);
    // 0x80241FC8: addiu       $t2, $a2, -0x1
    ctx->r10 = ADD32(ctx->r6, -0X1);
    // 0x80241FCC: bne         $a2, $zero, L_80241FDC
    if (ctx->r6 != 0) {
        // 0x80241FD0: sh          $t2, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r10;
            goto L_80241FDC;
    }
    // 0x80241FD0: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    // 0x80241FD4: jal         0x800058DC
    // 0x80241FD8: sh          $t3, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80241FD8: sh          $t3, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r11;
    after_0:
L_80241FDC:
    // 0x80241FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80241FE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80241FE4: jr          $ra
    // 0x80241FE8: nop

    return;
    // 0x80241FE8: nop

;}
RECOMP_FUNC void M12_FUN_80241fec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80241FEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80241FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80241FF4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80241FF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80241FFC: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80242000: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80242004: swc1        $f8, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f8.u32l;
    // 0x80242008: lwc1        $f10, 0x98($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8024200C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80242010: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242014: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80242018: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8024201C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80242020: nop

    // 0x80242024: bgez        $t7, L_80242038
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80242028: andi        $t8, $t7, 0x1F
        ctx->r24 = ctx->r15 & 0X1F;
            goto L_80242038;
    }
    // 0x80242028: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x8024202C: beq         $t8, $zero, L_80242038
    if (ctx->r24 == 0) {
        // 0x80242030: nop
    
            goto L_80242038;
    }
    // 0x80242030: nop

    // 0x80242034: addiu       $t8, $t8, -0x20
    ctx->r24 = ADD32(ctx->r24, -0X20);
L_80242038:
    // 0x80242038: sb          $t8, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r24;
    // 0x8024203C: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x80242040: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80242044: bne         $v0, $zero, L_80242054
    if (ctx->r2 != 0) {
        // 0x80242048: sh          $t1, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r9;
            goto L_80242054;
    }
    // 0x80242048: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x8024204C: jal         0x800058DC
    // 0x80242050: addiu       $a1, $a1, 0x2064
    ctx->r5 = ADD32(ctx->r5, 0X2064);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80242050: addiu       $a1, $a1, 0x2064
    ctx->r5 = ADD32(ctx->r5, 0X2064);
    after_0:
L_80242054:
    // 0x80242054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8024205C: jr          $ra
    // 0x80242060: nop

    return;
    // 0x80242060: nop

;}
RECOMP_FUNC void M12_FUN_80242064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8024206C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80242070: jal         0x800178E8
    // 0x80242074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80242074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80242078: beq         $v0, $zero, L_802420B4
    if (ctx->r2 == 0) {
        // 0x8024207C: lui         $a0, 0x8024
        ctx->r4 = S32(0X8024 << 16);
            goto L_802420B4;
    }
    // 0x8024207C: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80242080: jal         0x80017990
    // 0x80242084: addiu       $a0, $a0, 0x58E0
    ctx->r4 = ADD32(ctx->r4, 0X58E0);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_1;
    // 0x80242084: addiu       $a0, $a0, 0x58E0
    ctx->r4 = ADD32(ctx->r4, 0X58E0);
    after_1:
    // 0x80242088: jal         0x80020744
    // 0x8024208C: addiu       $a0, $zero, 0x3DF
    ctx->r4 = ADD32(0, 0X3DF);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x8024208C: addiu       $a0, $zero, 0x3DF
    ctx->r4 = ADD32(0, 0X3DF);
    after_2:
    // 0x80242090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80242094: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80242098: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8024209C: sh          $t6, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r14;
    // 0x802420A0: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x802420A4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802420A8: addiu       $a1, $a1, 0x20C4
    ctx->r5 = ADD32(ctx->r5, 0X20C4);
    // 0x802420AC: jal         0x800058DC
    // 0x802420B0: sh          $t7, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x802420B0: sh          $t7, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r15;
    after_3:
L_802420B4:
    // 0x802420B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802420B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802420BC: jr          $ra
    // 0x802420C0: nop

    return;
    // 0x802420C0: nop

;}
RECOMP_FUNC void M12_FUN_802420c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802420C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802420C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802420CC: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x802420D0: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x802420D4: lbu         $t7, 0x48($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X48);
    // 0x802420D8: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x802420DC: sb          $t8, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r24;
    // 0x802420E0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x802420E4: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x802420E8: lh          $t0, 0x10($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X10);
    // 0x802420EC: addiu       $t1, $t0, 0x7F
    ctx->r9 = ADD32(ctx->r8, 0X7F);
    // 0x802420F0: sh          $t1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r9;
    // 0x802420F4: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x802420F8: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x802420FC: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80242100: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x80242104: addiu       $t4, $t3, 0x7F
    ctx->r12 = ADD32(ctx->r11, 0X7F);
    // 0x80242108: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x8024210C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80242110: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x80242114: lh          $t6, 0x12($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X12);
    // 0x80242118: addiu       $t7, $t6, 0x7F
    ctx->r15 = ADD32(ctx->r14, 0X7F);
    // 0x8024211C: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
    // 0x80242120: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80242124: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242128: addiu       $a1, $a1, 0x2164
    ctx->r5 = ADD32(ctx->r5, 0X2164);
    // 0x8024212C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80242130: lh          $t9, 0x12($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X12);
    // 0x80242134: addiu       $t0, $t9, 0x7F
    ctx->r8 = ADD32(ctx->r25, 0X7F);
    // 0x80242138: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x8024213C: lh          $a2, 0x94($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X94);
    // 0x80242140: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x80242144: bne         $a2, $zero, L_80242154
    if (ctx->r6 != 0) {
        // 0x80242148: sh          $t1, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r9;
            goto L_80242154;
    }
    // 0x80242148: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x8024214C: jal         0x800058DC
    // 0x80242150: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80242150: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    after_0:
L_80242154:
    // 0x80242154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8024215C: jr          $ra
    // 0x80242160: nop

    return;
    // 0x80242160: nop

;}
RECOMP_FUNC void M12_FUN_80242164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8024216C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80242170: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80242174: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80242178: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8024217C: swc1        $f8, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f8.u32l;
    // 0x80242180: lwc1        $f10, 0x98($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80242184: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80242188: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8024218C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80242190: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80242194: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80242198: nop

    // 0x8024219C: bgez        $t7, L_802421B0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x802421A0: andi        $t8, $t7, 0x1F
        ctx->r24 = ctx->r15 & 0X1F;
            goto L_802421B0;
    }
    // 0x802421A0: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x802421A4: beq         $t8, $zero, L_802421B0
    if (ctx->r24 == 0) {
        // 0x802421A8: nop
    
            goto L_802421B0;
    }
    // 0x802421A8: nop

    // 0x802421AC: addiu       $t8, $t8, -0x20
    ctx->r24 = ADD32(ctx->r24, -0X20);
L_802421B0:
    // 0x802421B0: sb          $t8, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r24;
    // 0x802421B4: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x802421B8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x802421BC: bne         $v0, $zero, L_802421CC
    if (ctx->r2 != 0) {
        // 0x802421C0: sh          $t1, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r9;
            goto L_802421CC;
    }
    // 0x802421C0: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x802421C4: jal         0x800058DC
    // 0x802421C8: addiu       $a1, $a1, 0x21DC
    ctx->r5 = ADD32(ctx->r5, 0X21DC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802421C8: addiu       $a1, $a1, 0x21DC
    ctx->r5 = ADD32(ctx->r5, 0X21DC);
    after_0:
L_802421CC:
    // 0x802421CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802421D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802421D4: jr          $ra
    // 0x802421D8: nop

    return;
    // 0x802421D8: nop

;}
RECOMP_FUNC void M12_FUN_802421dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802421DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802421E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802421E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x802421E8: jal         0x800178E8
    // 0x802421EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x802421EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x802421F0: beq         $v0, $zero, L_8024223C
    if (ctx->r2 == 0) {
        // 0x802421F4: lui         $a0, 0x8024
        ctx->r4 = S32(0X8024 << 16);
            goto L_8024223C;
    }
    // 0x802421F4: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x802421F8: jal         0x80017990
    // 0x802421FC: addiu       $a0, $a0, 0x5AD0
    ctx->r4 = ADD32(ctx->r4, 0X5AD0);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_1;
    // 0x802421FC: addiu       $a0, $a0, 0x5AD0
    ctx->r4 = ADD32(ctx->r4, 0X5AD0);
    after_1:
    // 0x80242200: jal         0x80020744
    // 0x80242204: addiu       $a0, $zero, 0x3DF
    ctx->r4 = ADD32(0, 0X3DF);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80242204: addiu       $a0, $zero, 0x3DF
    ctx->r4 = ADD32(0, 0X3DF);
    after_2:
    // 0x80242208: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8024220C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80242210: lui         $t7, 0x2A8
    ctx->r15 = S32(0X2A8 << 16);
    // 0x80242214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80242218: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8024221C: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80242220: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x80242224: sw          $t7, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r15;
    // 0x80242228: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8024222C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242230: addiu       $a1, $a1, 0x224C
    ctx->r5 = ADD32(ctx->r5, 0X224C);
    // 0x80242234: jal         0x800058DC
    // 0x80242238: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80242238: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    after_3:
L_8024223C:
    // 0x8024223C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80242244: jr          $ra
    // 0x80242248: nop

    return;
    // 0x80242248: nop

;}
RECOMP_FUNC void M12_FUN_8024224c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024224C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242254: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80242258: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8024225C: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x80242260: addiu       $t8, $t7, -0xE
    ctx->r24 = ADD32(ctx->r15, -0XE);
    // 0x80242264: sb          $t8, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r24;
    // 0x80242268: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8024226C: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80242270: lh          $t0, 0x10($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X10);
    // 0x80242274: addiu       $t1, $t0, 0x1FF
    ctx->r9 = ADD32(ctx->r8, 0X1FF);
    // 0x80242278: sh          $t1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r9;
    // 0x8024227C: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80242280: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80242284: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80242288: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x8024228C: addiu       $t4, $t3, 0x1FF
    ctx->r12 = ADD32(ctx->r11, 0X1FF);
    // 0x80242290: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x80242294: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80242298: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x8024229C: lh          $t6, 0x12($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X12);
    // 0x802422A0: addiu       $t7, $t6, 0x1FF
    ctx->r15 = ADD32(ctx->r14, 0X1FF);
    // 0x802422A4: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
    // 0x802422A8: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x802422AC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802422B0: addiu       $a1, $a1, 0x22EC
    ctx->r5 = ADD32(ctx->r5, 0X22EC);
    // 0x802422B4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x802422B8: lh          $t9, 0x12($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X12);
    // 0x802422BC: addiu       $t0, $t9, 0x1FF
    ctx->r8 = ADD32(ctx->r25, 0X1FF);
    // 0x802422C0: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x802422C4: lh          $a2, 0x94($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X94);
    // 0x802422C8: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x802422CC: bne         $a2, $zero, L_802422DC
    if (ctx->r6 != 0) {
        // 0x802422D0: sh          $t1, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r9;
            goto L_802422DC;
    }
    // 0x802422D0: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x802422D4: jal         0x800058DC
    // 0x802422D8: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802422D8: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    after_0:
L_802422DC:
    // 0x802422DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802422E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802422E4: jr          $ra
    // 0x802422E8: nop

    return;
    // 0x802422E8: nop

;}
RECOMP_FUNC void M12_FUN_802422ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802422EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802422F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802422F4: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x802422F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802422FC: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80242300: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80242304: swc1        $f8, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f8.u32l;
    // 0x80242308: lwc1        $f10, 0x98($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8024230C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80242310: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242314: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80242318: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8024231C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80242320: nop

    // 0x80242324: bgez        $t7, L_80242338
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80242328: andi        $t8, $t7, 0x1F
        ctx->r24 = ctx->r15 & 0X1F;
            goto L_80242338;
    }
    // 0x80242328: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x8024232C: beq         $t8, $zero, L_80242338
    if (ctx->r24 == 0) {
        // 0x80242330: nop
    
            goto L_80242338;
    }
    // 0x80242330: nop

    // 0x80242334: addiu       $t8, $t8, -0x20
    ctx->r24 = ADD32(ctx->r24, -0X20);
L_80242338:
    // 0x80242338: sb          $t8, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r24;
    // 0x8024233C: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x80242340: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80242344: bne         $v0, $zero, L_80242354
    if (ctx->r2 != 0) {
        // 0x80242348: sh          $t1, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r9;
            goto L_80242354;
    }
    // 0x80242348: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x8024234C: jal         0x800058DC
    // 0x80242350: addiu       $a1, $a1, 0x2364
    ctx->r5 = ADD32(ctx->r5, 0X2364);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80242350: addiu       $a1, $a1, 0x2364
    ctx->r5 = ADD32(ctx->r5, 0X2364);
    after_0:
L_80242354:
    // 0x80242354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8024235C: jr          $ra
    // 0x80242360: nop

    return;
    // 0x80242360: nop

;}
RECOMP_FUNC void M12_FUN_80242364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8024236C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80242370: jal         0x800178E8
    // 0x80242374: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80242374: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80242378: beq         $v0, $zero, L_802423B0
    if (ctx->r2 == 0) {
        // 0x8024237C: lui         $t6, 0x2A8
        ctx->r14 = S32(0X2A8 << 16);
            goto L_802423B0;
    }
    // 0x8024237C: lui         $t6, 0x2A8
    ctx->r14 = S32(0X2A8 << 16);
    // 0x80242380: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80242384: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80242388: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8024238C: sw          $t6, -0x3500($at)
    MEM_W(-0X3500, ctx->r1) = ctx->r14;
    // 0x80242390: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x80242394: addiu       $a0, $zero, 0x1BE
    ctx->r4 = ADD32(0, 0X1BE);
    // 0x80242398: jal         0x80020744
    // 0x8024239C: sh          $t7, 0x94($t8)
    MEM_H(0X94, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x8024239C: sh          $t7, 0x94($t8)
    MEM_H(0X94, ctx->r24) = ctx->r15;
    after_1:
    // 0x802423A0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802423A4: addiu       $a1, $a1, 0x23C0
    ctx->r5 = ADD32(ctx->r5, 0X23C0);
    // 0x802423A8: jal         0x800058DC
    // 0x802423AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x802423AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_802423B0:
    // 0x802423B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802423B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802423B8: jr          $ra
    // 0x802423BC: nop

    return;
    // 0x802423BC: nop

;}
RECOMP_FUNC void M12_FUN_802423c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802423C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802423C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802423C8: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x802423CC: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x802423D0: ldc1        $f8, -0x6500($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6500);
    // 0x802423D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x802423D8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x802423DC: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x802423E0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x802423E4: swc1        $f16, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f16.u32l;
    // 0x802423E8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x802423EC: lwc1        $f0, 0x90($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X90);
    // 0x802423F0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802423F4: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x802423F8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x802423FC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80242400: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80242404: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80242408: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8024240C: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x80242410: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80242414: lwc1        $f0, 0x90($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80242418: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8024241C: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x80242420: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x80242424: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80242428: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x8024242C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80242430: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80242434: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x80242438: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8024243C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80242440: lh          $t9, 0x10($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X10);
    // 0x80242444: addiu       $t0, $t9, 0x280
    ctx->r8 = ADD32(ctx->r25, 0X280);
    // 0x80242448: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8024244C: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80242450: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80242454: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x80242458: lh          $t2, 0x10($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X10);
    // 0x8024245C: addiu       $t3, $t2, 0x280
    ctx->r11 = ADD32(ctx->r10, 0X280);
    // 0x80242460: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x80242464: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80242468: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8024246C: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    // 0x80242470: addiu       $t6, $t5, 0x280
    ctx->r14 = ADD32(ctx->r13, 0X280);
    // 0x80242474: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x80242478: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8024247C: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x80242480: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x80242484: addiu       $t9, $t8, 0x280
    ctx->r25 = ADD32(ctx->r24, 0X280);
    // 0x80242488: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
    // 0x8024248C: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x80242490: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80242494: bne         $v0, $zero, L_802424C8
    if (ctx->r2 != 0) {
        // 0x80242498: sh          $t0, 0x94($a0)
        MEM_H(0X94, ctx->r4) = ctx->r8;
            goto L_802424C8;
    }
    // 0x80242498: sh          $t0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r8;
    // 0x8024249C: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    // 0x802424A0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x802424A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x802424A8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802424AC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802424B0: addiu       $a1, $a1, 0x24D8
    ctx->r5 = ADD32(ctx->r5, 0X24D8);
    // 0x802424B4: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x802424B8: lw          $t4, 0x4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4);
    // 0x802424BC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802424C0: jal         0x800058DC
    // 0x802424C4: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802424C4: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    after_0:
L_802424C8:
    // 0x802424C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802424CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802424D0: jr          $ra
    // 0x802424D4: nop

    return;
    // 0x802424D4: nop

;}
RECOMP_FUNC void M12_FUN_802424d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802424D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802424DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802424E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x802424E4: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x802424E8: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x802424EC: ldc1        $f8, -0x64F8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X64F8);
    // 0x802424F0: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x802424F4: lui         $t1, 0x168
    ctx->r9 = S32(0X168 << 16);
    // 0x802424F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x802424FC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80242500: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80242504: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80242508: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8024250C: ori         $t1, $t1, 0x3E
    ctx->r9 = ctx->r9 | 0X3E;
    // 0x80242510: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80242514: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x80242518: addiu       $t3, $zero, 0x1102
    ctx->r11 = ADD32(0, 0X1102);
    // 0x8024251C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80242520: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80242524: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80242528: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8024252C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80242530: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80242534: lh          $v1, 0x94($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X94);
    // 0x80242538: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8024253C: bne         $v1, $zero, L_802425E4
    if (ctx->r3 != 0) {
        // 0x80242540: sh          $t8, 0x94($t7)
        MEM_H(0X94, ctx->r15) = ctx->r24;
            goto L_802425E4;
    }
    // 0x80242540: sh          $t8, 0x94($t7)
    MEM_H(0X94, ctx->r15) = ctx->r24;
    // 0x80242544: sh          $t9, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r25;
    // 0x80242548: sh          $t0, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r8;
    // 0x8024254C: lwc1        $f18, -0x64F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X64F0);
    // 0x80242550: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x80242554: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80242558: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x8024255C: swc1        $f18, 0x198($v0)
    MEM_W(0X198, ctx->r2) = ctx->f18.u32l;
    // 0x80242560: swc1        $f4, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->f4.u32l;
    // 0x80242564: lwc1        $f6, -0x64EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X64EC);
    // 0x80242568: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x8024256C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80242570: swc1        $f6, 0xF04($v0)
    MEM_W(0XF04, ctx->r2) = ctx->f6.u32l;
    // 0x80242574: lwc1        $f8, -0x64E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64E8);
    // 0x80242578: sw          $t1, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r9;
    // 0x8024257C: sh          $t2, 0xF0C($v0)
    MEM_H(0XF0C, ctx->r2) = ctx->r10;
    // 0x80242580: sh          $t3, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r11;
    // 0x80242584: jal         0x80133980
    // 0x80242588: swc1        $f8, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x80242588: swc1        $f8, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x8024258C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80242590: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80242594: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80242598: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x8024259C: addiu       $a0, $zero, 0x1C7
    ctx->r4 = ADD32(0, 0X1C7);
    // 0x802425A0: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x802425A4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x802425A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x802425AC: jal         0x80020744
    // 0x802425B0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x802425B0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    after_1:
    // 0x802425B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x802425B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x802425BC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802425C0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x802425C4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x802425C8: addiu       $a1, $a1, 0x25F4
    ctx->r5 = ADD32(ctx->r5, 0X25F4);
    // 0x802425CC: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    // 0x802425D0: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x802425D4: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x802425D8: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x802425DC: jal         0x800058DC
    // 0x802425E0: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x802425E0: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    after_2:
L_802425E4:
    // 0x802425E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802425E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802425EC: jr          $ra
    // 0x802425F0: nop

    return;
    // 0x802425F0: nop

;}
RECOMP_FUNC void M12_FUN_802425f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802425F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802425F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802425FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80242600: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80242604: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80242608: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x8024260C: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80242610: ldc1        $f8, -0x64E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X64E0);
    // 0x80242614: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80242618: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8024261C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80242620: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80242624: swc1        $f16, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f16.u32l;
    // 0x80242628: jal         0x8001518C
    // 0x8024262C: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_0;
    // 0x8024262C: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    after_0:
    // 0x80242630: jal         0x80029280
    // 0x80242634: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_1;
    // 0x80242634: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80242638: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8024263C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80242640: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80242644: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x80242648: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8024264C: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80242650: sb          $t8, 0xF28($s0)
    MEM_B(0XF28, ctx->r16) = ctx->r24;
    // 0x80242654: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80242658: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8024265C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80242660: nop

    // 0x80242664: sb          $t7, 0xF26($s0)
    MEM_B(0XF26, ctx->r16) = ctx->r15;
    // 0x80242668: jal         0x8001518C
    // 0x8024266C: lwc1        $f12, 0x90($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X90);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_2;
    // 0x8024266C: lwc1        $f12, 0x90($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X90);
    after_2:
    // 0x80242670: jal         0x80032720
    // 0x80242674: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_3;
    // 0x80242674: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80242678: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8024267C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80242680: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80242684: sb          $t1, 0xF32($s0)
    MEM_B(0XF32, ctx->r16) = ctx->r9;
    // 0x80242688: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8024268C: sb          $zero, 0xF33($s0)
    MEM_B(0XF33, ctx->r16) = 0;
    // 0x80242690: sb          $zero, 0xF34($s0)
    MEM_B(0XF34, ctx->r16) = 0;
    // 0x80242694: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80242698: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8024269C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x802426A0: nop

    // 0x802426A4: sb          $t0, 0xF27($s0)
    MEM_B(0XF27, ctx->r16) = ctx->r8;
    // 0x802426A8: jal         0x8001518C
    // 0x802426AC: lwc1        $f12, 0x90($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X90);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_4;
    // 0x802426AC: lwc1        $f12, 0x90($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X90);
    after_4:
    // 0x802426B0: jal         0x80029280
    // 0x802426B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_5;
    // 0x802426B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x802426B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x802426BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x802426C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x802426C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x802426C8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x802426CC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x802426D0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x802426D4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x802426D8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x802426DC: nop

    // 0x802426E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x802426E4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x802426E8: nop

    // 0x802426EC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x802426F0: beql        $t3, $zero, L_80242740
    if (ctx->r11 == 0) {
        // 0x802426F4: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_80242740;
    }
    goto skip_0;
    // 0x802426F4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x802426F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802426FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80242700: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80242704: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80242708: nop

    // 0x8024270C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80242710: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80242714: nop

    // 0x80242718: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8024271C: bne         $t3, $zero, L_80242734
    if (ctx->r11 != 0) {
        // 0x80242720: nop
    
            goto L_80242734;
    }
    // 0x80242720: nop

    // 0x80242724: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80242728: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8024272C: b           L_8024274C
    // 0x80242730: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8024274C;
    // 0x80242730: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80242734:
    // 0x80242734: b           L_8024274C
    // 0x80242738: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8024274C;
    // 0x80242738: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8024273C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_80242740:
    // 0x80242740: nop

    // 0x80242744: bltz        $t3, L_80242734
    if (SIGNED(ctx->r11) < 0) {
        // 0x80242748: nop
    
            goto L_80242734;
    }
    // 0x80242748: nop

L_8024274C:
    // 0x8024274C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80242750: addiu       $t5, $t3, 0x96
    ctx->r13 = ADD32(ctx->r11, 0X96);
    // 0x80242754: sb          $t5, 0xF20($s0)
    MEM_B(0XF20, ctx->r16) = ctx->r13;
    // 0x80242758: sb          $v0, 0xF21($s0)
    MEM_B(0XF21, ctx->r16) = ctx->r2;
    // 0x8024275C: sb          $v0, 0xF22($s0)
    MEM_B(0XF22, ctx->r16) = ctx->r2;
    // 0x80242760: sb          $t6, 0xF23($s0)
    MEM_B(0XF23, ctx->r16) = ctx->r14;
    // 0x80242764: sb          $zero, 0xF24($s0)
    MEM_B(0XF24, ctx->r16) = 0;
    // 0x80242768: sb          $zero, 0xF25($s0)
    MEM_B(0XF25, ctx->r16) = 0;
    // 0x8024276C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80242770: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80242774: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80242778: jr          $ra
    // 0x8024277C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8024277C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80242780(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80242780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80242784: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80242788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8024278C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80242790: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80242794: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80242798: jal         0x80005F6C
    // 0x8024279C: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x8024279C: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    after_0:
    // 0x802427A0: jal         0x80006214
    // 0x802427A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802427A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802427A8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x802427AC: lw          $v1, 0x1EEC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1EEC);
    // 0x802427B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x802427B4: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x802427B8: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x802427BC: jal         0x8000522C
    // 0x802427C0: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_2;
    // 0x802427C0: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    after_2:
    // 0x802427C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x802427C8: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x802427CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802427D0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x802427D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x802427D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x802427DC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x802427E0: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x802427E4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802427E8: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x802427EC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x802427F0: addiu       $a1, $a1, 0x2840
    ctx->r5 = ADD32(ctx->r5, 0X2840);
    // 0x802427F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802427F8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x802427FC: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x80242800: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80242804: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80242808: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x8024280C: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80242810: sh          $zero, 0x86($s0)
    MEM_H(0X86, ctx->r16) = 0;
    // 0x80242814: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80242818: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
    // 0x8024281C: swc1        $f2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f2.u32l;
    // 0x80242820: swc1        $f2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f2.u32l;
    // 0x80242824: jal         0x800058DC
    // 0x80242828: swc1        $f2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f2.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80242828: swc1        $f2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f2.u32l;
    after_3:
    // 0x8024282C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80242830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80242834: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80242838: jr          $ra
    // 0x8024283C: nop

    return;
    // 0x8024283C: nop

;}
RECOMP_FUNC void M12_FUN_80242840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80242848: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8024284C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80242854: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80242858: jal         0x80133A24
    // 0x8024285C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x8024285C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80242860: beq         $v0, $zero, L_80242874
    if (ctx->r2 == 0) {
        // 0x80242864: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80242874;
    }
    // 0x80242864: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80242868: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x8024286C: b           L_80242878
    // 0x80242870: sw          $t6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r14;
        goto L_80242878;
    // 0x80242870: sw          $t6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r14;
L_80242874:
    // 0x80242874: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
L_80242878:
    // 0x80242878: lh          $v0, 0x90($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X90);
    // 0x8024287C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80242880: bne         $v0, $zero, L_802428AC
    if (ctx->r2 != 0) {
        // 0x80242884: sh          $t7, 0x90($a1)
        MEM_H(0X90, ctx->r5) = ctx->r15;
            goto L_802428AC;
    }
    // 0x80242884: sh          $t7, 0x90($a1)
    MEM_H(0X90, ctx->r5) = ctx->r15;
    // 0x80242888: lh          $t8, 0x90($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X90);
    // 0x8024288C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80242890: sh          $t9, 0x90($a1)
    MEM_H(0X90, ctx->r5) = ctx->r25;
    // 0x80242894: jal         0x80150584
    // 0x80242898: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_1;
    // 0x80242898: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8024289C: beq         $v0, $zero, L_802428AC
    if (ctx->r2 == 0) {
        // 0x802428A0: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_802428AC;
    }
    // 0x802428A0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x802428A4: jal         0x80005700
    // 0x802428A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x802428A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_802428AC:
    // 0x802428AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802428B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802428B4: jr          $ra
    // 0x802428B8: nop

    return;
    // 0x802428B8: nop

;}
