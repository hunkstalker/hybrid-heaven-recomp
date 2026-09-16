#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_801fa6fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA6FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801FA700: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801FA704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FA708: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FA70C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FA710: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x801FA714: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FA718: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FA71C: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x801FA720: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801FA724: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801FA728: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FA72C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FA730: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801FA734: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FA738: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801FA73C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801FA740: sw          $a0, 0x70B0($at)
    MEM_W(0X70B0, ctx->r1) = ctx->r4;
    // 0x801FA744: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801FA748: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA74C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801FA750: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x801FA754: jal         0x80126CC0
    // 0x801FA758: addiu       $a1, $a1, -0x5790
    ctx->r5 = ADD32(ctx->r5, -0X5790);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x801FA758: addiu       $a1, $a1, -0x5790
    ctx->r5 = ADD32(ctx->r5, -0X5790);
    after_0:
    // 0x801FA75C: beql        $v0, $zero, L_801FA854
    if (ctx->r2 == 0) {
        // 0x801FA760: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FA854;
    }
    goto skip_0;
    // 0x801FA760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801FA764: jal         0x8001F74C
    // 0x801FA768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_1;
    // 0x801FA768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801FA76C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x801FA770: ori         $t1, $t1, 0xC00
    ctx->r9 = ctx->r9 | 0XC00;
    // 0x801FA774: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801FA778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA77C: jal         0x80005E44
    // 0x801FA780: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801FA780: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801FA784: jal         0x80006214
    // 0x801FA788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801FA788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801FA78C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA790: jal         0x8012636C
    // 0x801FA794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_4;
    // 0x801FA794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x801FA798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA79C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FA7A0: jal         0x8012C784
    // 0x801FA7A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_5;
    // 0x801FA7A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801FA7A8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801FA7AC: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    // 0x801FA7B0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FA7B4: sw          $t2, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r10;
    // 0x801FA7B8: jal         0x8000C3B0
    // 0x801FA7BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_6;
    // 0x801FA7BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x801FA7C0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801FA7C4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FA7C8: lwc1        $f0, -0x71F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71F8);
    // 0x801FA7CC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801FA7D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801FA7D4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801FA7D8: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x801FA7DC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FA7E0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA7E4: addiu       $a1, $a1, -0x579C
    ctx->r5 = ADD32(ctx->r5, -0X579C);
    // 0x801FA7E8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FA7EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA7F0: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x801FA7F4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801FA7F8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FA7FC: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    // 0x801FA800: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FA804: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801FA808: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x801FA80C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801FA810: lbu         $t2, 0xF32($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF32);
    // 0x801FA814: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FA818: sb          $t2, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r10;
    // 0x801FA81C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FA820: lbu         $t6, 0xF33($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF33);
    // 0x801FA824: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FA828: sb          $t6, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r14;
    // 0x801FA82C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801FA830: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x801FA834: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FA838: sb          $t9, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r25;
    // 0x801FA83C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801FA840: lbu         $t3, 0xF35($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF35);
    // 0x801FA844: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x801FA848: jal         0x800058DC
    // 0x801FA84C: sb          $t3, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801FA84C: sb          $t3, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r11;
    after_7:
    // 0x801FA850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FA854:
    // 0x801FA854: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FA858: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FA85C: jr          $ra
    // 0x801FA860: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801FA860: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa864(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA864: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA868: jr          $ra
    // 0x801FA86C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801FA86C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa870(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA874: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA87C: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FA880: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FA884: sw          $zero, 0x70B0($at)
    MEM_W(0X70B0, ctx->r1) = 0;
    // 0x801FA888: jal         0x800058DC
    // 0x801FA88C: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FA88C: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x801FA890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA898: jr          $ra
    // 0x801FA89C: nop

    return;
    // 0x801FA89C: nop

;}
RECOMP_FUNC void M9_FUN_801fa8a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA8A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801FA8A4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801FA8A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FA8AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801FA8B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801FA8B4: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x801FA8B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FA8BC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FA8C0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x801FA8C4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801FA8C8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801FA8CC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FA8D0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FA8D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801FA8D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801FA8DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FA8E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801FA8E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801FA8E8: lhu         $a2, 0x72($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X72);
    // 0x801FA8EC: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x801FA8F0: jal         0x80126B14
    // 0x801FA8F4: addiu       $a3, $zero, 0x227
    ctx->r7 = ADD32(0, 0X227);
    LOOKUP_FUNC(0x80126B14)(rdram, ctx);
        goto after_0;
    // 0x801FA8F4: addiu       $a3, $zero, 0x227
    ctx->r7 = ADD32(0, 0X227);
    after_0:
    // 0x801FA8F8: beql        $v0, $zero, L_801FAA94
    if (ctx->r2 == 0) {
        // 0x801FA8FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801FAA94;
    }
    goto skip_0;
    // 0x801FA8FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801FA900: jal         0x8001F74C
    // 0x801FA904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_1;
    // 0x801FA904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801FA908: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x801FA90C: ori         $t0, $t0, 0x600
    ctx->r8 = ctx->r8 | 0X600;
    // 0x801FA910: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801FA914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA918: jal         0x80005E44
    // 0x801FA91C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801FA91C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801FA920: jal         0x80006214
    // 0x801FA924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801FA924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801FA928: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA92C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FA930: addiu       $a2, $zero, 0x227
    ctx->r6 = ADD32(0, 0X227);
    // 0x801FA934: jal         0x8012C89C
    // 0x801FA938: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801FA938: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x801FA93C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x801FA940: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801FA944: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801FA948: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801FA94C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FA950: addiu       $a1, $zero, 0x227
    ctx->r5 = ADD32(0, 0X227);
    // 0x801FA954: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FA958: jal         0x8012D8C8
    // 0x801FA95C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_5;
    // 0x801FA95C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x801FA960: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801FA964: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FA968: lwc1        $f0, -0x71F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71F4);
    // 0x801FA96C: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801FA970: lui         $t5, 0x8021
    ctx->r13 = S32(0X8021 << 16);
    // 0x801FA974: addiu       $t5, $t5, 0x6F30
    ctx->r13 = ADD32(ctx->r13, 0X6F30);
    // 0x801FA978: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x801FA97C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FA980: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FA984: ori         $t4, $t3, 0x300
    ctx->r12 = ctx->r11 | 0X300;
    // 0x801FA988: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x801FA98C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FA990: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x801FA994: addiu       $v1, $v1, 0x70B0
    ctx->r3 = ADD32(ctx->r3, 0X70B0);
    // 0x801FA998: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FA99C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801FA9A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801FA9A4: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x801FA9A8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801FA9AC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801FA9B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801FA9B4: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801FA9B8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801FA9BC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FA9C0: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x801FA9C4: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801FA9C8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801FA9CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801FA9D0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801FA9D4: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801FA9D8: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801FA9DC: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801FA9E0: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801FA9E4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801FA9E8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801FA9EC: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801FA9F0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801FA9F4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FA9F8: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801FA9FC: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801FAA00: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA04: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FAA08: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FAA0C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA10: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801FAA14: swc1        $f10, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f10.u32l;
    // 0x801FAA18: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA1C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801FAA20: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x801FAA24: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA28: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FAA2C: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x801FAA30: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801FAA34: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA38: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801FAA3C: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801FAA40: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FAA44: lh          $t5, 0x12($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X12);
    // 0x801FAA48: sh          $t5, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r13;
    // 0x801FAA4C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA50: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801FAA54: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x801FAA58: jal         0x80145310
    // 0x801FAA5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_6;
    // 0x801FAA5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x801FAA60: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FAA64: addiu       $t0, $zero, 0x96
    ctx->r8 = ADD32(0, 0X96);
    // 0x801FAA68: addiu       $t3, $zero, -0x800
    ctx->r11 = ADD32(0, -0X800);
    // 0x801FAA6C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FAA70: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    // 0x801FAA74: sb          $t0, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r8;
    // 0x801FAA78: jal         0x80145390
    // 0x801FAA7C: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    LOOKUP_FUNC(0x80145390)(rdram, ctx);
        goto after_7;
    // 0x801FAA7C: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    after_7:
    // 0x801FAA80: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FAA84: addiu       $a1, $a1, -0x555C
    ctx->r5 = ADD32(ctx->r5, -0X555C);
    // 0x801FAA88: jal         0x800058DC
    // 0x801FAA8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801FAA8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x801FAA90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801FAA94:
    // 0x801FAA94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801FAA98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801FAA9C: jr          $ra
    // 0x801FAAA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801FAAA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801faaa4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801faaa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAAA4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FAAA8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801FAAAC: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x801FAAB0: jr          $ra
    // 0x801FAAB4: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    return;
    // 0x801FAAB4: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801faab8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801faab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAAB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801FAABC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801FAAC0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801FAAC4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801FAAC8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801FAACC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801FAAD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FAAD4: sb          $t6, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r14;
    // 0x801FAAD8: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801FAADC: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801FAAE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FAAE4: slti        $v1, $v0, 0x10
    ctx->r3 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x801FAAE8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x801FAAEC: beq         $v1, $zero, L_801FAB1C
    if (ctx->r3 == 0) {
        // 0x801FAAF0: sh          $t8, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r24;
            goto L_801FAB1C;
    }
    // 0x801FAAF0: sh          $t8, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r24;
    // 0x801FAAF4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801FAAF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801FAAFC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801FAB00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x801FAB04: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x801FAB08: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801FAB0C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801FAB10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801FAB14: jal         0x801453CC
    // 0x801FAB18: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x801FAB18: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
L_801FAB1C:
    // 0x801FAB1C: jal         0x8001EAD0
    // 0x801FAB20: lh          $a0, 0x92($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X92);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801FAB20: lh          $a0, 0x92($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X92);
    after_1:
    // 0x801FAB24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801FAB28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FAB2C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FAB30: ldc1        $f10, -0x71F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X71F0);
    // 0x801FAB34: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801FAB38: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x801FAB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FAB40: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FAB44: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801FAB48: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801FAB4C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801FAB50: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FAB54: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801FAB58: swc1        $f18, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f18.u32l;
    // 0x801FAB5C: lh          $t6, 0x92($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X92);
    // 0x801FAB60: addiu       $t7, $t6, 0x100
    ctx->r15 = ADD32(ctx->r14, 0X100);
    // 0x801FAB64: sh          $t7, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r15;
    // 0x801FAB68: lh          $t8, 0x92($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X92);
    // 0x801FAB6C: slti        $at, $t8, 0x1001
    ctx->r1 = SIGNED(ctx->r24) < 0X1001 ? 1 : 0;
    // 0x801FAB70: bnel        $at, $zero, L_801FAB84
    if (ctx->r1 != 0) {
        // 0x801FAB74: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801FAB84;
    }
    goto skip_0;
    // 0x801FAB74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801FAB78: jal         0x800058DC
    // 0x801FAB7C: addiu       $a1, $a1, -0x546C
    ctx->r5 = ADD32(ctx->r5, -0X546C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FAB7C: addiu       $a1, $a1, -0x546C
    ctx->r5 = ADD32(ctx->r5, -0X546C);
    after_2:
    // 0x801FAB80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801FAB84:
    // 0x801FAB84: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801FAB88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801FAB8C: jr          $ra
    // 0x801FAB90: nop

    return;
    // 0x801FAB90: nop

;}
RECOMP_FUNC void M9_FUN_801fab94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAB94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FAB98: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801FAB9C: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x801FABA0: lbu         $v0, 0x4B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4B);
    // 0x801FABA4: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x801FABA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FABAC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FABB0: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x801FABB4: beq         $at, $zero, L_801FABC0
    if (ctx->r1 == 0) {
        // 0x801FABB8: nop
    
            goto L_801FABC0;
    }
    // 0x801FABB8: nop

    // 0x801FABBC: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_801FABC0:
    // 0x801FABC0: jr          $ra
    // 0x801FABC4: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    return;
    // 0x801FABC4: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fabc8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fabc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FABC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FABCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FABD0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801FABD4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FABD8: ldc1        $f6, -0x71E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X71E8);
    // 0x801FABDC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801FABE0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FABE4: ldc1        $f16, -0x71E0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X71E0);
    // 0x801FABE8: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801FABEC: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FABF0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801FABF4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801FABF8: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x801FABFC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801FAC00: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x801FAC04: nop

    // 0x801FAC08: bc1fl       L_801FAC2C
    if (!c1cs) {
        // 0x801FAC0C: swc1        $f0, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
            goto L_801FAC2C;
    }
    goto skip_0;
    // 0x801FAC0C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x801FAC10: jal         0x80005700
    // 0x801FAC14: sw          $zero, 0x70B8($at)
    MEM_W(0X70B8, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801FAC14: sw          $zero, 0x70B8($at)
    MEM_W(0X70B8, ctx->r1) = 0;
    after_0:
    // 0x801FAC18: jal         0x801FA624
    // 0x801FAC1C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x801FA624)(rdram, ctx);
        goto after_1;
    // 0x801FAC1C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_1:
    // 0x801FAC20: b           L_801FAC30
    // 0x801FAC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FAC30;
    // 0x801FAC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FAC28: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
L_801FAC2C:
    // 0x801FAC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FAC30:
    // 0x801FAC30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FAC34: jr          $ra
    // 0x801FAC38: nop

    return;
    // 0x801FAC38: nop

;}
RECOMP_FUNC void M9_FUN_801fac3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAC3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801FAC40: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801FAC44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FAC48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FAC4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FAC50: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x801FAC54: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FAC58: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FAC5C: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x801FAC60: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801FAC64: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801FAC68: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FAC6C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FAC70: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801FAC74: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801FAC78: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FAC7C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801FAC80: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801FAC84: lhu         $a2, 0x72($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X72);
    // 0x801FAC88: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x801FAC8C: jal         0x80126B14
    // 0x801FAC90: addiu       $a3, $zero, 0x227
    ctx->r7 = ADD32(0, 0X227);
    LOOKUP_FUNC(0x80126B14)(rdram, ctx);
        goto after_0;
    // 0x801FAC90: addiu       $a3, $zero, 0x227
    ctx->r7 = ADD32(0, 0X227);
    after_0:
    // 0x801FAC94: beql        $v0, $zero, L_801FADEC
    if (ctx->r2 == 0) {
        // 0x801FAC98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FADEC;
    }
    goto skip_0;
    // 0x801FAC98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801FAC9C: jal         0x8001F74C
    // 0x801FACA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_1;
    // 0x801FACA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801FACA4: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x801FACA8: ori         $t0, $t0, 0x2FF
    ctx->r8 = ctx->r8 | 0X2FF;
    // 0x801FACAC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801FACB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FACB4: jal         0x80005E44
    // 0x801FACB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801FACB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x801FACBC: jal         0x80006214
    // 0x801FACC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801FACC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801FACC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FACC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FACCC: addiu       $a2, $zero, 0x227
    ctx->r6 = ADD32(0, 0X227);
    // 0x801FACD0: jal         0x8012C89C
    // 0x801FACD4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801FACD4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x801FACD8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FACDC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FACE0: lwc1        $f0, -0x71D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71D8);
    // 0x801FACE4: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801FACE8: lui         $t4, 0x8021
    ctx->r12 = S32(0X8021 << 16);
    // 0x801FACEC: addiu       $t4, $t4, 0x6F98
    ctx->r12 = ADD32(ctx->r12, 0X6F98);
    // 0x801FACF0: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801FACF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FACF8: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FACFC: ori         $t3, $t2, 0x300
    ctx->r11 = ctx->r10 | 0X300;
    // 0x801FAD00: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801FAD04: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD08: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801FAD0C: addiu       $v1, $v1, 0x70B0
    ctx->r3 = ADD32(ctx->r3, 0X70B0);
    // 0x801FAD10: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FAD14: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FAD18: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FAD1C: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x801FAD20: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801FAD24: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD28: addiu       $a1, $a1, -0x5204
    ctx->r5 = ADD32(ctx->r5, -0X5204);
    // 0x801FAD2C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801FAD30: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FAD34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FAD38: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FAD3C: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x801FAD40: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801FAD44: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801FAD48: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD4C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801FAD50: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801FAD54: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801FAD58: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801FAD5C: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x801FAD60: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801FAD64: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD68: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801FAD6C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FAD70: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FAD74: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x801FAD78: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801FAD7C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD80: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FAD84: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x801FAD88: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD8C: lwc1        $f10, -0x71D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71D4);
    // 0x801FAD90: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801FAD94: swc1        $f10, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f10.u32l;
    // 0x801FAD98: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FAD9C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FADA0: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x801FADA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801FADA8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FADAC: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x801FADB0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801FADB4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801FADB8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801FADBC: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801FADC0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801FADC4: lh          $t4, 0x12($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X12);
    // 0x801FADC8: sh          $t4, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r12;
    // 0x801FADCC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FADD0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FADD4: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x801FADD8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801FADDC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FADE0: jal         0x800058DC
    // 0x801FADE4: sb          $zero, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801FADE4: sb          $zero, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = 0;
    after_5:
    // 0x801FADE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FADEC:
    // 0x801FADEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FADF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FADF4: jr          $ra
    // 0x801FADF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801FADF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fadfc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fadfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FADFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FAE00: jr          $ra
    // 0x801FAE04: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    return;
    // 0x801FAE04: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fae08(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fae08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAE08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FAE0C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801FAE10: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FAE14: ldc1        $f8, -0x71D0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X71D0);
    // 0x801FAE18: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801FAE1C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801FAE20: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801FAE24: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801FAE28: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801FAE2C: jr          $ra
    // 0x801FAE30: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x801FAE30: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fae34(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fae34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAE34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FAE38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FAE3C: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FAE40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FAE44: jal         0x80005700
    // 0x801FAE48: sw          $zero, 0x70BC($at)
    MEM_W(0X70BC, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801FAE48: sw          $zero, 0x70BC($at)
    MEM_W(0X70BC, ctx->r1) = 0;
    after_0:
    // 0x801FAE4C: jal         0x801FA624
    // 0x801FAE50: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x801FA624)(rdram, ctx);
        goto after_1;
    // 0x801FAE50: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_1:
    // 0x801FAE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FAE58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FAE5C: jr          $ra
    // 0x801FAE60: nop

    return;
    // 0x801FAE60: nop

;}
RECOMP_FUNC void M9_FUN_801fae64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAE64: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801FAE68: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801FAE6C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801FAE70: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x801FAE74: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x801FAE78: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801FAE7C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801FAE80: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801FAE84: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801FAE88: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801FAE8C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801FAE90: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801FAE94: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801FAE98: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801FAE9C: addiu       $t7, $t7, 0x70C4
    ctx->r15 = ADD32(ctx->r15, 0X70C4);
    // 0x801FAEA0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FAEA4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FAEA8: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x801FAEAC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801FAEB0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801FAEB4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FAEB8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FAEBC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x801FAEC0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801FAEC4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801FAEC8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801FAECC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801FAED0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801FAED4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801FAED8: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x801FAEDC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x801FAEE0: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x801FAEE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FAEE8: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x801FAEEC: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x801FAEF0: lhu         $a2, 0x72($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X72);
    // 0x801FAEF4: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x801FAEF8: jal         0x80126B14
    // 0x801FAEFC: addiu       $a3, $zero, 0x225
    ctx->r7 = ADD32(0, 0X225);
    LOOKUP_FUNC(0x80126B14)(rdram, ctx);
        goto after_0;
    // 0x801FAEFC: addiu       $a3, $zero, 0x225
    ctx->r7 = ADD32(0, 0X225);
    after_0:
    // 0x801FAF00: beql        $v0, $zero, L_801FB0CC
    if (ctx->r2 == 0) {
        // 0x801FAF04: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801FB0CC;
    }
    goto skip_0;
    // 0x801FAF04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801FAF08: jal         0x8001F74C
    // 0x801FAF0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_1;
    // 0x801FAF0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x801FAF10: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FAF14: sw          $s4, 0x70C0($at)
    MEM_W(0X70C0, ctx->r1) = ctx->r20;
    // 0x801FAF18: lui         $s7, 0x8021
    ctx->r23 = S32(0X8021 << 16);
    // 0x801FAF1C: addiu       $s7, $s7, 0x6F30
    ctx->r23 = ADD32(ctx->r23, 0X6F30);
    // 0x801FAF20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FAF24: or          $s7, $s7, $at
    ctx->r23 = ctx->r23 | ctx->r1;
    // 0x801FAF28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801FAF2C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801FAF30: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FAF34: lui         $s5, 0x8016
    ctx->r21 = S32(0X8016 << 16);
    // 0x801FAF38: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801FAF3C: addiu       $s3, $s3, -0x4410
    ctx->r19 = ADD32(ctx->r19, -0X4410);
    // 0x801FAF40: addiu       $s5, $s5, 0x4F40
    ctx->r21 = ADD32(ctx->r21, 0X4F40);
    // 0x801FAF44: ldc1        $f20, -0x71C8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X71C8);
    // 0x801FAF48: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801FAF4C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801FAF50: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_801FAF54:
    // 0x801FAF54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801FAF58: jal         0x80005E44
    // 0x801FAF5C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801FAF5C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x801FAF60: jal         0x80006214
    // 0x801FAF64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801FAF64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x801FAF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801FAF6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801FAF70: addiu       $a2, $zero, 0x225
    ctx->r6 = ADD32(0, 0X225);
    // 0x801FAF74: jal         0x8012C89C
    // 0x801FAF78: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801FAF78: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801FAF7C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x801FAF80: addu        $s0, $fp, $t0
    ctx->r16 = ADD32(ctx->r30, ctx->r8);
    // 0x801FAF84: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FAF88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FAF8C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x801FAF90: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801FAF94: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801FAF98: ori         $t3, $t2, 0x300
    ctx->r11 = ctx->r10 | 0X300;
    // 0x801FAF9C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801FAFA0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801FAFA4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FAFA8: sw          $s7, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r23;
    // 0x801FAFAC: jal         0x80145310
    // 0x801FAFB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_5;
    // 0x801FAFB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x801FAFB4: lw          $t6, 0xEC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XEC);
    // 0x801FAFB8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801FAFBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801FAFC0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801FAFC4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FAFC8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801FAFCC: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801FAFD0: bne         $s6, $s2, L_801FAFE0
    if (ctx->r22 != ctx->r18) {
        // 0x801FAFD4: swc1        $f4, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
            goto L_801FAFE0;
    }
    // 0x801FAFD4: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801FAFD8: b           L_801FAFE0
    // 0x801FAFDC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_801FAFE0;
    // 0x801FAFDC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_801FAFE0:
    // 0x801FAFE0: lw          $t1, 0xEC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XEC);
    // 0x801FAFE4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x801FAFE8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801FAFEC: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801FAFF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FAFF4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FAFF8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801FAFFC: addiu       $t2, $sp, 0x6C
    ctx->r10 = ADD32(ctx->r29, 0X6C);
    // 0x801FB000: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    // 0x801FB004: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801FB008: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x801FB00C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801FB010: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801FB014: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801FB018: addiu       $a1, $zero, 0x225
    ctx->r5 = ADD32(0, 0X225);
    // 0x801FB01C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FB020: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x801FB024: lw          $t6, 0xEC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XEC);
    // 0x801FB028: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801FB02C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801FB030: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FB034: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801FB038: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801FB03C: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801FB040: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
    // 0x801FB044: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801FB048: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801FB04C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801FB050: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FB054: mul.d       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x801FB058: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801FB05C: swc1        $f10, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f10.u32l;
    // 0x801FB060: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801FB064: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801FB068: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801FB06C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801FB070: mul.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x801FB074: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801FB078: swc1        $f8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f8.u32l;
    // 0x801FB07C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801FB080: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FB084: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801FB088: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FB08C: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x801FB090: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801FB094: swc1        $f18, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f18.u32l;
    // 0x801FB098: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801FB09C: jal         0x8012D8C8
    // 0x801FB0A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_6;
    // 0x801FB0A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_6:
    // 0x801FB0A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801FB0A8: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801FB0AC: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x801FB0B0: bne         $at, $zero, L_801FAF54
    if (ctx->r1 != 0) {
        // 0x801FB0B4: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_801FAF54;
    }
    // 0x801FB0B4: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x801FB0B8: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FB0BC: addiu       $a1, $a1, -0x4F00
    ctx->r5 = ADD32(ctx->r5, -0X4F00);
    // 0x801FB0C0: jal         0x800058DC
    // 0x801FB0C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801FB0C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x801FB0C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801FB0CC:
    // 0x801FB0CC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801FB0D0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801FB0D4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801FB0D8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801FB0DC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801FB0E0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801FB0E4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801FB0E8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x801FB0EC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x801FB0F0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x801FB0F4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x801FB0F8: jr          $ra
    // 0x801FB0FC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801FB0FC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fb100(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fb100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FB104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FB108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FB10C: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x801FB110: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801FB114: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x801FB118: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x801FB11C: bne         $t9, $zero, L_801FB12C
    if (ctx->r25 != 0) {
        // 0x801FB120: sh          $t8, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r24;
            goto L_801FB12C;
    }
    // 0x801FB120: sh          $t8, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r24;
    // 0x801FB124: jal         0x80005670
    // 0x801FB128: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801FB128: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    after_0:
L_801FB12C:
    // 0x801FB12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FB130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FB134: jr          $ra
    // 0x801FB138: nop

    return;
    // 0x801FB138: nop

;}
RECOMP_FUNC void M9_FUN_801fb13c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB13C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FB140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FB144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FB148: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FB14C: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x801FB150: jal         0x801FA248
    // 0x801FB154: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801FA248)(rdram, ctx);
        goto after_0;
    // 0x801FB154: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x801FB158: bnel        $v0, $zero, L_801FB17C
    if (ctx->r2 != 0) {
        // 0x801FB15C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FB17C;
    }
    goto skip_0;
    // 0x801FB15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FB160: jal         0x80005700
    // 0x801FB164: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FB164: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801FB168: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FB16C: sw          $zero, 0x70C0($at)
    MEM_W(0X70C0, ctx->r1) = 0;
    // 0x801FB170: jal         0x801FA624
    // 0x801FB174: addiu       $a0, $zero, 0x12A
    ctx->r4 = ADD32(0, 0X12A);
    LOOKUP_FUNC(0x801FA624)(rdram, ctx);
        goto after_2;
    // 0x801FB174: addiu       $a0, $zero, 0x12A
    ctx->r4 = ADD32(0, 0X12A);
    after_2:
    // 0x801FB178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FB17C:
    // 0x801FB17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FB180: jr          $ra
    // 0x801FB184: nop

    return;
    // 0x801FB184: nop

;}
RECOMP_FUNC void M9_FUN_801fb188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FB18C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FB190: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FB194: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FB198: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801FB19C: jal         0x8001F74C
    // 0x801FB1A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x801FB1A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x801FB1A4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FB1A8: lw          $t6, -0x4324($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4324);
    // 0x801FB1AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB1B0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FB1B4: beq         $t6, $zero, L_801FB2D0
    if (ctx->r14 == 0) {
        // 0x801FB1B8: nop
    
            goto L_801FB2D0;
    }
    // 0x801FB1B8: nop

    // 0x801FB1BC: jal         0x80005E44
    // 0x801FB1C0: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801FB1C0: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_1:
    // 0x801FB1C4: jal         0x80006214
    // 0x801FB1C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801FB1C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801FB1CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB1D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FB1D4: addiu       $a2, $zero, 0x225
    ctx->r6 = ADD32(0, 0X225);
    // 0x801FB1D8: jal         0x8012C89C
    // 0x801FB1DC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801FB1DC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x801FB1E0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FB1E4: lui         $t0, 0x8021
    ctx->r8 = S32(0X8021 << 16);
    // 0x801FB1E8: addiu       $t0, $t0, 0x6F30
    ctx->r8 = ADD32(ctx->r8, 0X6F30);
    // 0x801FB1EC: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801FB1F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FB1F4: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801FB1F8: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801FB1FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FB200: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x801FB204: ori         $t9, $t8, 0x300
    ctx->r25 = ctx->r24 | 0X300;
    // 0x801FB208: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801FB20C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801FB210: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801FB214: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
    // 0x801FB218: jal         0x80145310
    // 0x801FB21C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_4;
    // 0x801FB21C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x801FB220: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FB224: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FB228: lw          $t4, 0xEC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XEC);
    // 0x801FB22C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FB230: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FB234: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801FB238: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FB23C: lwc1        $f0, -0x71C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71C0);
    // 0x801FB240: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801FB244: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FB248: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801FB24C: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801FB250: lw          $t9, 0xEC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XEC);
    // 0x801FB254: ldc1        $f10, -0x71B8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X71B8);
    // 0x801FB258: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801FB25C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801FB260: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801FB264: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801FB268: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801FB26C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801FB270: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801FB274: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801FB278: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
    // 0x801FB27C: lw          $t4, 0xEC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XEC);
    // 0x801FB280: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801FB284: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801FB288: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FB28C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801FB290: addiu       $t5, $zero, -0x800
    ctx->r13 = ADD32(0, -0X800);
    // 0x801FB294: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x801FB298: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x801FB29C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801FB2A0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FB2A4: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x801FB2A8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801FB2AC: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801FB2B0: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x801FB2B4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801FB2B8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FB2BC: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x801FB2C0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801FB2C4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FB2C8: b           L_801FB2D8
    // 0x801FB2CC: sh          $t5, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r13;
        goto L_801FB2D8;
    // 0x801FB2CC: sh          $t5, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r13;
L_801FB2D0:
    // 0x801FB2D0: jal         0x80005700
    // 0x801FB2D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x801FB2D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
L_801FB2D8:
    // 0x801FB2D8: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FB2DC: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x801FB2E0: jal         0x800058DC
    // 0x801FB2E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801FB2E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x801FB2E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FB2EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FB2F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FB2F4: jr          $ra
    // 0x801FB2F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FB2F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fb2fc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fb2fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FB300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FB304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FB308: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801FB30C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FB310: ldc1        $f0, -0x71B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X71B0);
    // 0x801FB314: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801FB318: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801FB31C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801FB320: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x801FB324: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801FB328: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x801FB32C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801FB330: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801FB334: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801FB338: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801FB33C: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x801FB340: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801FB344: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x801FB348: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x801FB34C: jal         0x801FA248
    // 0x801FB350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801FA248)(rdram, ctx);
        goto after_0;
    // 0x801FB350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x801FB354: bnel        $v0, $zero, L_801FB368
    if (ctx->r2 != 0) {
        // 0x801FB358: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FB368;
    }
    goto skip_0;
    // 0x801FB358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FB35C: jal         0x80005700
    // 0x801FB360: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FB360: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801FB364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FB368:
    // 0x801FB368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FB36C: jr          $ra
    // 0x801FB370: nop

    return;
    // 0x801FB370: nop

;}
RECOMP_FUNC void M9_FUN_801fb374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB374: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801FB378: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801FB37C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801FB380: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801FB384: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FB388: addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // 0x801FB38C: jal         0x80126A0C
    // 0x801FB390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x801FB390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801FB394: beql        $v0, $zero, L_801FB478
    if (ctx->r2 == 0) {
        // 0x801FB398: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801FB478;
    }
    goto skip_0;
    // 0x801FB398: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801FB39C: jal         0x80116E80
    // 0x801FB3A0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x801FB3A0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_1:
    // 0x801FB3A4: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x801FB3A8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801FB3AC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801FB3B0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FB3B4: addiu       $t0, $zero, 0x20D
    ctx->r8 = ADD32(0, 0X20D);
    // 0x801FB3B8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801FB3BC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801FB3C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801FB3C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FB3C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FB3CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FB3D0: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x801FB3D4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB3D8: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x801FB3DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB3E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801FB3E4: jal         0x80146208
    // 0x801FB3E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x801FB3E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_2:
    // 0x801FB3EC: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x801FB3F0: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801FB3F4: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x801FB3F8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801FB3FC: addiu       $t5, $zero, 0x20D
    ctx->r13 = ADD32(0, 0X20D);
    // 0x801FB400: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801FB404: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801FB408: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801FB40C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801FB410: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801FB414: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801FB418: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801FB41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FB420: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x801FB424: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB428: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x801FB42C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB430: jal         0x80146208
    // 0x801FB434: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x801FB434: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x801FB438: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801FB43C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FB440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FB444: jal         0x80145310
    // 0x801FB448: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_4;
    // 0x801FB448: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x801FB44C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x801FB450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FB454: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FB458: jal         0x80145310
    // 0x801FB45C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_5;
    // 0x801FB45C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_5:
    // 0x801FB460: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FB464: sb          $zero, 0x90($s0)
    MEM_B(0X90, ctx->r16) = 0;
    // 0x801FB468: addiu       $a1, $a1, -0x4B78
    ctx->r5 = ADD32(ctx->r5, -0X4B78);
    // 0x801FB46C: jal         0x800058DC
    // 0x801FB470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801FB470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801FB474: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801FB478:
    // 0x801FB478: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801FB47C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801FB480: jr          $ra
    // 0x801FB484: nop

    return;
    // 0x801FB484: nop

;}
RECOMP_FUNC void M9_FUN_801fb488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FB48C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FB490: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FB494: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801FB498: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801FB49C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801FB4A0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801FB4A4: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x801FB4A8: beq         $v0, $at, L_801FB4C4
    if (ctx->r2 == ctx->r1) {
        // 0x801FB4AC: sb          $t7, 0x90($a0)
        MEM_B(0X90, ctx->r4) = ctx->r15;
            goto L_801FB4C4;
    }
    // 0x801FB4AC: sb          $t7, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r15;
    // 0x801FB4B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801FB4B4: beq         $v0, $at, L_801FB4FC
    if (ctx->r2 == ctx->r1) {
        // 0x801FB4B8: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_801FB4FC;
    }
    // 0x801FB4B8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801FB4BC: b           L_801FB530
    // 0x801FB4C0: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
        goto L_801FB530;
    // 0x801FB4C0: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
L_801FB4C4:
    // 0x801FB4C4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801FB4C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FB4CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FB4D0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x801FB4D4: jal         0x80145310
    // 0x801FB4D8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x801FB4D8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801FB4DC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801FB4E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FB4E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FB4E8: jal         0x80145310
    // 0x801FB4EC: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x801FB4EC: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_1:
    // 0x801FB4F0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801FB4F4: b           L_801FB52C
    // 0x801FB4F8: lbu         $v0, 0x90($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X90);
        goto L_801FB52C;
    // 0x801FB4F8: lbu         $v0, 0x90($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X90);
L_801FB4FC:
    // 0x801FB4FC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801FB500: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801FB504: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801FB508: jal         0x80145310
    // 0x801FB50C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x801FB50C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x801FB510: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x801FB514: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801FB518: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801FB51C: jal         0x80145310
    // 0x801FB520: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_3;
    // 0x801FB520: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_3:
    // 0x801FB524: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801FB528: lbu         $v0, 0x90($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X90);
L_801FB52C:
    // 0x801FB52C: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
L_801FB530:
    // 0x801FB530: bne         $at, $zero, L_801FB544
    if (ctx->r1 != 0) {
        // 0x801FB534: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801FB544;
    }
    // 0x801FB534: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801FB538: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FB53C: jal         0x800058DC
    // 0x801FB540: addiu       $a1, $a1, -0x4AAC
    ctx->r5 = ADD32(ctx->r5, -0X4AAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801FB540: addiu       $a1, $a1, -0x4AAC
    ctx->r5 = ADD32(ctx->r5, -0X4AAC);
    after_4:
L_801FB544:
    // 0x801FB544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FB548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FB54C: jr          $ra
    // 0x801FB550: nop

    return;
    // 0x801FB550: nop

;}
RECOMP_FUNC void M9_FUN_801fb554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FB558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FB55C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FB560: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x801FB564: jal         0x801FA29C
    // 0x801FB568: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801FA29C)(rdram, ctx);
        goto after_0;
    // 0x801FB568: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801FB56C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801FB570: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FB574: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801FB578: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801FB57C: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x801FB580: addiu       $t9, $t8, 0xF
    ctx->r25 = ADD32(ctx->r24, 0XF);
    // 0x801FB584: sb          $t9, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r25;
    // 0x801FB588: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x801FB58C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801FB590: lbu         $t1, 0xA($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XA);
    // 0x801FB594: sb          $t1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r9;
    // 0x801FB598: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x801FB59C: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x801FB5A0: lbu         $t3, 0xA($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XA);
    // 0x801FB5A4: addiu       $t4, $t3, 0xF
    ctx->r12 = ADD32(ctx->r11, 0XF);
    // 0x801FB5A8: sb          $t4, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r12;
    // 0x801FB5AC: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x801FB5B0: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x801FB5B4: lbu         $t6, 0xA($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XA);
    // 0x801FB5B8: sb          $t6, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r14;
    // 0x801FB5BC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801FB5C0: lbu         $t8, 0x22($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X22);
    // 0x801FB5C4: bnel        $t8, $zero, L_801FB5E4
    if (ctx->r24 != 0) {
        // 0x801FB5C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FB5E4;
    }
    goto skip_0;
    // 0x801FB5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FB5CC: sw          $zero, 0x70B4($at)
    MEM_W(0X70B4, ctx->r1) = 0;
    // 0x801FB5D0: jal         0x80005700
    // 0x801FB5D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FB5D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801FB5D8: jal         0x801FA624
    // 0x801FB5DC: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    LOOKUP_FUNC(0x801FA624)(rdram, ctx);
        goto after_2;
    // 0x801FB5DC: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    after_2:
    // 0x801FB5E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FB5E4:
    // 0x801FB5E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FB5E8: jr          $ra
    // 0x801FB5EC: nop

    return;
    // 0x801FB5EC: nop

;}
RECOMP_FUNC void M9_FUN_801fb5f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB5F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801FB5F4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801FB5F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801FB5FC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801FB600: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801FB604: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801FB608: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801FB60C: addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // 0x801FB610: jal         0x80126A0C
    // 0x801FB614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x801FB614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801FB618: beql        $v0, $zero, L_801FB8FC
    if (ctx->r2 == 0) {
        // 0x801FB61C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801FB8FC;
    }
    goto skip_0;
    // 0x801FB61C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801FB620: jal         0x80116E80
    // 0x801FB624: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x801FB624: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_1:
    // 0x801FB628: lbu         $v1, 0xAF($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XAF);
    // 0x801FB62C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FB630: addiu       $s0, $sp, 0x4F
    ctx->r16 = ADD32(ctx->r29, 0X4F);
    // 0x801FB634: beq         $v1, $at, L_801FB650
    if (ctx->r3 == ctx->r1) {
        // 0x801FB638: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801FB650;
    }
    // 0x801FB638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB63C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801FB640: beq         $v1, $at, L_801FB784
    if (ctx->r3 == ctx->r1) {
        // 0x801FB644: addiu       $s0, $sp, 0x4F
        ctx->r16 = ADD32(ctx->r29, 0X4F);
            goto L_801FB784;
    }
    // 0x801FB644: addiu       $s0, $sp, 0x4F
    ctx->r16 = ADD32(ctx->r29, 0X4F);
    // 0x801FB648: b           L_801FB8B8
    // 0x801FB64C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_801FB8B8;
    // 0x801FB64C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801FB650:
    // 0x801FB650: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x801FB654: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801FB658: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801FB65C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FB660: addiu       $t0, $zero, 0x20D
    ctx->r8 = ADD32(0, 0X20D);
    // 0x801FB664: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801FB668: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801FB66C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801FB670: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801FB674: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801FB678: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FB67C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FB680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB684: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB688: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x801FB68C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB690: jal         0x80146208
    // 0x801FB694: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x801FB694: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x801FB698: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x801FB69C: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801FB6A0: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801FB6A4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801FB6A8: addiu       $t6, $zero, 0x20D
    ctx->r14 = ADD32(0, 0X20D);
    // 0x801FB6AC: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x801FB6B0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801FB6B4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801FB6B8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801FB6BC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801FB6C0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801FB6C4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801FB6C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB6CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB6D0: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB6D4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x801FB6D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB6DC: jal         0x80146208
    // 0x801FB6E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x801FB6E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x801FB6E4: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x801FB6E8: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x801FB6EC: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x801FB6F0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FB6F4: addiu       $t2, $zero, 0x20D
    ctx->r10 = ADD32(0, 0X20D);
    // 0x801FB6F8: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x801FB6FC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801FB700: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801FB704: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801FB708: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801FB70C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801FB710: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FB714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB71C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB720: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x801FB724: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB728: jal         0x80146208
    // 0x801FB72C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x801FB72C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x801FB730: addiu       $t4, $zero, 0x96
    ctx->r12 = ADD32(0, 0X96);
    // 0x801FB734: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x801FB738: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x801FB73C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FB740: addiu       $t8, $zero, 0x20D
    ctx->r24 = ADD32(0, 0X20D);
    // 0x801FB744: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x801FB748: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801FB74C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801FB750: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801FB754: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801FB758: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801FB75C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801FB760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB764: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB768: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB76C: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    // 0x801FB770: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB774: jal         0x80146208
    // 0x801FB778: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x801FB778: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x801FB77C: b           L_801FB8B8
    // 0x801FB780: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_801FB8B8;
    // 0x801FB780: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801FB784:
    // 0x801FB784: addiu       $t0, $zero, 0x96
    ctx->r8 = ADD32(0, 0X96);
    // 0x801FB788: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801FB78C: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x801FB790: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FB794: addiu       $t4, $zero, 0x20D
    ctx->r12 = ADD32(0, 0X20D);
    // 0x801FB798: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801FB79C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801FB7A0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801FB7A4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801FB7A8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801FB7AC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801FB7B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801FB7B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB7B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB7BC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB7C0: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x801FB7C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB7C8: jal         0x80146208
    // 0x801FB7CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x801FB7CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // 0x801FB7D0: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x801FB7D4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801FB7D8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801FB7DC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FB7E0: addiu       $t0, $zero, 0x20D
    ctx->r8 = ADD32(0, 0X20D);
    // 0x801FB7E4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801FB7E8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801FB7EC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801FB7F0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801FB7F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801FB7F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FB7FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FB800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB804: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB808: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB80C: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    // 0x801FB810: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB814: jal         0x80146208
    // 0x801FB818: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_7;
    // 0x801FB818: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_7:
    // 0x801FB81C: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x801FB820: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801FB824: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801FB828: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801FB82C: addiu       $t6, $zero, 0x20D
    ctx->r14 = ADD32(0, 0X20D);
    // 0x801FB830: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801FB834: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801FB838: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801FB83C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801FB840: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801FB844: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801FB848: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801FB84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB850: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB854: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB858: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // 0x801FB85C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB860: jal         0x80146208
    // 0x801FB864: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x801FB864: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_8:
    // 0x801FB868: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x801FB86C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801FB870: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x801FB874: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FB878: addiu       $t2, $zero, 0x20D
    ctx->r10 = ADD32(0, 0X20D);
    // 0x801FB87C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801FB880: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801FB884: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801FB888: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801FB88C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801FB890: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801FB894: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FB898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FB89C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801FB8A0: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801FB8A4: addiu       $a3, $zero, 0xFC
    ctx->r7 = ADD32(0, 0XFC);
    // 0x801FB8A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FB8AC: jal         0x80146208
    // 0x801FB8B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_9;
    // 0x801FB8B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_9:
    // 0x801FB8B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801FB8B8:
    // 0x801FB8B8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
L_801FB8BC:
    // 0x801FB8BC: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x801FB8C0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x801FB8C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FB8C8: jal         0x80145310
    // 0x801FB8CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_10;
    // 0x801FB8CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x801FB8D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FB8D4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FB8D8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801FB8DC: bnel        $at, $zero, L_801FB8BC
    if (ctx->r1 != 0) {
        // 0x801FB8E0: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_801FB8BC;
    }
    goto skip_1;
    // 0x801FB8E0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    skip_1:
    // 0x801FB8E4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FB8E8: sb          $zero, 0x90($s1)
    MEM_B(0X90, ctx->r17) = 0;
    // 0x801FB8EC: addiu       $a1, $a1, -0x46F0
    ctx->r5 = ADD32(ctx->r5, -0X46F0);
    // 0x801FB8F0: jal         0x800058DC
    // 0x801FB8F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801FB8F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x801FB8F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801FB8FC:
    // 0x801FB8FC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801FB900: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801FB904: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801FB908: jr          $ra
    // 0x801FB90C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801FB90C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fb910(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fb910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FB910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FB914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FB918: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801FB91C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801FB920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FB924: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801FB928: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801FB92C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FB930: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801FB934: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x801FB938: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801FB93C: beq         $v0, $at, L_801FB958
    if (ctx->r2 == ctx->r1) {
        // 0x801FB940: sb          $t7, 0x90($a0)
        MEM_B(0X90, ctx->r4) = ctx->r15;
            goto L_801FB958;
    }
    // 0x801FB940: sb          $t7, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r15;
    // 0x801FB944: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801FB948: beql        $v0, $at, L_801FB994
    if (ctx->r2 == ctx->r1) {
        // 0x801FB94C: lbu         $t0, 0xAF($s2)
        ctx->r8 = MEM_BU(ctx->r18, 0XAF);
            goto L_801FB994;
    }
    goto skip_0;
    // 0x801FB94C: lbu         $t0, 0xAF($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XAF);
    skip_0:
    // 0x801FB950: b           L_801FBA10
    // 0x801FB954: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
        goto L_801FBA10;
    // 0x801FB954: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
L_801FB958:
    // 0x801FB958: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801FB95C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
L_801FB960:
    // 0x801FB960: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x801FB964: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x801FB968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FB96C: jal         0x80145310
    // 0x801FB970: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x801FB970: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x801FB974: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FB978: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FB97C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801FB980: bnel        $at, $zero, L_801FB960
    if (ctx->r1 != 0) {
        // 0x801FB984: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_801FB960;
    }
    goto skip_1;
    // 0x801FB984: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    skip_1:
    // 0x801FB988: b           L_801FBA0C
    // 0x801FB98C: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
        goto L_801FBA0C;
    // 0x801FB98C: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
    // 0x801FB990: lbu         $t0, 0xAF($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XAF);
L_801FB994:
    // 0x801FB994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FB998: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801FB99C: bne         $t0, $at, L_801FB9DC
    if (ctx->r8 != ctx->r1) {
        // 0x801FB9A0: nop
    
            goto L_801FB9DC;
    }
    // 0x801FB9A0: nop

    // 0x801FB9A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801FB9A8: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
L_801FB9AC:
    // 0x801FB9AC: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x801FB9B0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x801FB9B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801FB9B8: jal         0x80145310
    // 0x801FB9BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x801FB9BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x801FB9C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FB9C4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FB9C8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801FB9CC: bnel        $at, $zero, L_801FB9AC
    if (ctx->r1 != 0) {
        // 0x801FB9D0: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_801FB9AC;
    }
    goto skip_2;
    // 0x801FB9D0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    skip_2:
    // 0x801FB9D4: b           L_801FBA0C
    // 0x801FB9D8: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
        goto L_801FBA0C;
    // 0x801FB9D8: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
L_801FB9DC:
    // 0x801FB9DC: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
L_801FB9E0:
    // 0x801FB9E0: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x801FB9E4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801FB9E8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x801FB9EC: jal         0x80145310
    // 0x801FB9F0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x801FB9F0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    after_2:
    // 0x801FB9F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FB9F8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FB9FC: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801FBA00: bnel        $at, $zero, L_801FB9E0
    if (ctx->r1 != 0) {
        // 0x801FBA04: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_801FB9E0;
    }
    goto skip_3;
    // 0x801FBA04: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    skip_3:
    // 0x801FBA08: lbu         $v0, 0x90($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X90);
L_801FBA0C:
    // 0x801FBA0C: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
L_801FBA10:
    // 0x801FBA10: bne         $at, $zero, L_801FBA24
    if (ctx->r1 != 0) {
        // 0x801FBA14: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801FBA24;
    }
    // 0x801FBA14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801FBA18: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FBA1C: jal         0x800058DC
    // 0x801FBA20: addiu       $a1, $a1, -0x45C4
    ctx->r5 = ADD32(ctx->r5, -0X45C4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801FBA20: addiu       $a1, $a1, -0x45C4
    ctx->r5 = ADD32(ctx->r5, -0X45C4);
    after_3:
L_801FBA24:
    // 0x801FBA24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FBA28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FBA2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801FBA30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801FBA34: jr          $ra
    // 0x801FBA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801FBA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fba3c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fba3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBA3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FBA40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FBA44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801FBA48: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x801FBA4C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801FBA50: jal         0x801FA29C
    // 0x801FBA54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801FA29C)(rdram, ctx);
        goto after_0;
    // 0x801FBA54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801FBA58: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801FBA5C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801FBA60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801FBA64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FBA68: lbu         $t6, 0xAF($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XAF);
L_801FBA6C:
    // 0x801FBA6C: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x801FBA70: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801FBA74: bne         $a2, $t6, L_801FBAA8
    if (ctx->r6 != ctx->r14) {
        // 0x801FBA78: addu        $v1, $a1, $t3
        ctx->r3 = ADD32(ctx->r5, ctx->r11);
            goto L_801FBAA8;
    }
    // 0x801FBA78: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x801FBA7C: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x801FBA80: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801FBA84: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801FBA88: lbu         $t9, 0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XA);
    // 0x801FBA8C: addiu       $t0, $t9, 0xF
    ctx->r8 = ADD32(ctx->r25, 0XF);
    // 0x801FBA90: sb          $t0, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r8;
    // 0x801FBA94: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801FBA98: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801FBA9C: lbu         $t2, 0xA($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XA);
    // 0x801FBAA0: b           L_801FBACC
    // 0x801FBAA4: sb          $t2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r10;
        goto L_801FBACC;
    // 0x801FBAA4: sb          $t2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r10;
L_801FBAA8:
    // 0x801FBAA8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801FBAAC: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801FBAB0: lbu         $t5, 0xA($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XA);
    // 0x801FBAB4: addiu       $t6, $t5, 0xF
    ctx->r14 = ADD32(ctx->r13, 0XF);
    // 0x801FBAB8: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // 0x801FBABC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801FBAC0: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801FBAC4: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x801FBAC8: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
L_801FBACC:
    // 0x801FBACC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801FBAD0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801FBAD4: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x801FBAD8: bnel        $at, $zero, L_801FBA6C
    if (ctx->r1 != 0) {
        // 0x801FBADC: lbu         $t6, 0xAF($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0XAF);
            goto L_801FBA6C;
    }
    goto skip_0;
    // 0x801FBADC: lbu         $t6, 0xAF($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XAF);
    skip_0:
    // 0x801FBAE0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801FBAE4: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FBAE8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801FBAEC: lbu         $t0, 0x22($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X22);
    // 0x801FBAF0: bnel        $t0, $zero, L_801FBB0C
    if (ctx->r8 != 0) {
        // 0x801FBAF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FBB0C;
    }
    goto skip_1;
    // 0x801FBAF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801FBAF8: jal         0x80005700
    // 0x801FBAFC: sw          $zero, 0x70B4($at)
    MEM_W(0X70B4, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FBAFC: sw          $zero, 0x70B4($at)
    MEM_W(0X70B4, ctx->r1) = 0;
    after_1:
    // 0x801FBB00: jal         0x801FA624
    // 0x801FBB04: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    LOOKUP_FUNC(0x801FA624)(rdram, ctx);
        goto after_2;
    // 0x801FBB04: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    after_2:
    // 0x801FBB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FBB0C:
    // 0x801FBB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FBB10: jr          $ra
    // 0x801FBB14: nop

    return;
    // 0x801FBB14: nop

;}
RECOMP_FUNC void M9_FUN_801fbb18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBB18: nop

    // 0x801FBB1C: nop

;}
RECOMP_FUNC void M9_FUN_801fbb20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBB20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801FBB24: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FBB28: jr          $ra
    // 0x801FBB2C: sb          $t6, -0x4F1C($at)
    MEM_B(-0X4F1C, ctx->r1) = ctx->r14;
    return;
    // 0x801FBB2C: sb          $t6, -0x4F1C($at)
    MEM_B(-0X4F1C, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fbb30(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fbb30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBB30: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FBB34: jr          $ra
    // 0x801FBB38: sb          $zero, -0x4F1C($at)
    MEM_B(-0X4F1C, ctx->r1) = 0;
    return;
    // 0x801FBB38: sb          $zero, -0x4F1C($at)
    MEM_B(-0X4F1C, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fbb3c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fbb3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBB3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FBB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FBB44: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x801FBB48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801FBB4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FBB50: jal         0x80147598
    // 0x801FBB54: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_0;
    // 0x801FBB54: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    after_0:
    // 0x801FBB58: beq         $v0, $zero, L_801FBB70
    if (ctx->r2 == 0) {
        // 0x801FBB5C: nop
    
            goto L_801FBB70;
    }
    // 0x801FBB5C: nop

    // 0x801FBB60: jal         0x80005700
    // 0x801FBB64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FBB64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801FBB68: b           L_801FBC1C
    // 0x801FBB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FBC1C;
    // 0x801FBB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FBB70:
    // 0x801FBB70: jal         0x801FBB20
    // 0x801FBB74: nop

    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_2;
    // 0x801FBB74: nop

    after_2:
    // 0x801FBB78: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801FBB7C: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FBB80: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // 0x801FBB84: sw          $zero, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = 0;
    // 0x801FBB88: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x801FBB8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801FBB90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FBB94: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801FBB98: bgez        $t7, L_801FBBAC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801FBB9C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801FBBAC;
    }
    // 0x801FBB9C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801FBBA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801FBBA4: nop

    // 0x801FBBA8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_801FBBAC:
    // 0x801FBBAC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FBBB0: swc1        $f0, -0x4F20($at)
    MEM_W(-0X4F20, ctx->r1) = ctx->f0.u32l;
    // 0x801FBBB4: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x801FBBB8: beq         $v0, $zero, L_801FBC00
    if (ctx->r2 == 0) {
        // 0x801FBBBC: nop
    
            goto L_801FBC00;
    }
    // 0x801FBBBC: nop

    // 0x801FBBC0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801FBBC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801FBBC8: bgez        $v0, L_801FBBDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801FBBCC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801FBBDC;
    }
    // 0x801FBBCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FBBD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801FBBD4: nop

    // 0x801FBBD8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_801FBBDC:
    // 0x801FBBDC: div.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801FBBE0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x801FBBE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FBBE8: nop

    // 0x801FBBEC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801FBBF0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801FBBF4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x801FBBF8: nop

    // 0x801FBBFC: sh          $t9, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r25;
L_801FBC00:
    // 0x801FBC00: jal         0x80146CD4
    // 0x801FBC04: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x80146CD4)(rdram, ctx);
        goto after_3;
    // 0x801FBC04: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_3:
    // 0x801FBC08: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FBC0C: addiu       $a1, $a1, -0x43D8
    ctx->r5 = ADD32(ctx->r5, -0X43D8);
    // 0x801FBC10: jal         0x800058DC
    // 0x801FBC14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801FBC14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x801FBC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FBC1C:
    // 0x801FBC1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FBC20: jr          $ra
    // 0x801FBC24: nop

    return;
    // 0x801FBC24: nop

;}
RECOMP_FUNC void M9_FUN_801fbc28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBC28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801FBC2C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801FBC30: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801FBC34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801FBC38: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801FBC3C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801FBC40: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801FBC44: sb          $zero, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = 0;
    // 0x801FBC48: jal         0x80116E80
    // 0x801FBC4C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x801FBC4C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x801FBC50: jal         0x80116E80
    // 0x801FBC54: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x801FBC54: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_1:
    // 0x801FBC58: jal         0x80116E80
    // 0x801FBC5C: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_2;
    // 0x801FBC5C: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_2:
    // 0x801FBC60: jal         0x80116E80
    // 0x801FBC64: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_3;
    // 0x801FBC64: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_3:
    // 0x801FBC68: lbu         $t6, 0x4E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4E);
    // 0x801FBC6C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801FBC70: addiu       $s1, $s1, -0x1398
    ctx->r17 = ADD32(ctx->r17, -0X1398);
    // 0x801FBC74: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x801FBC78: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801FBC7C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x801FBC80: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801FBC84: addiu       $t1, $zero, 0x209
    ctx->r9 = ADD32(0, 0X209);
    // 0x801FBC88: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801FBC8C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801FBC90: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FBC94: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801FBC98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FBC9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801FBCA0: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x801FBCA4: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x801FBCA8: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    // 0x801FBCAC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FBCB0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801FBCB4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801FBCB8: jal         0x80146208
    // 0x801FBCBC: sb          $t6, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x801FBCBC: sb          $t6, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r14;
    after_4:
    // 0x801FBCC0: lbu         $t3, 0xA($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XA);
    // 0x801FBCC4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x801FBCC8: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x801FBCCC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801FBCD0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x801FBCD4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801FBCD8: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x801FBCDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FBCE0: sh          $t2, 0x28($t6)
    MEM_H(0X28, ctx->r14) = ctx->r10;
    // 0x801FBCE4: lbu         $t7, 0xA($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XA);
    // 0x801FBCE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801FBCEC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801FBCF0: jal         0x801451C0
    // 0x801FBCF4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_5;
    // 0x801FBCF4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_5:
    // 0x801FBCF8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801FBCFC: lbu         $t0, 0x4E($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4E);
    // 0x801FBD00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FBD04: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x801FBD08: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801FBD0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801FBD10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FBD14: addiu       $a2, $sp, 0x4E
    ctx->r6 = ADD32(ctx->r29, 0X4E);
    // 0x801FBD18: lui         $a3, 0x4228
    ctx->r7 = S32(0X4228 << 16);
    // 0x801FBD1C: sb          $t0, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r8;
    // 0x801FBD20: jal         0x80146894
    // 0x801FBD24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80146894)(rdram, ctx);
        goto after_6;
    // 0x801FBD24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x801FBD28: lbu         $t3, 0x4E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4E);
    // 0x801FBD2C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801FBD30: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    // 0x801FBD34: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x801FBD38: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x801FBD3C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FBD40: addiu       $t7, $zero, 0x209
    ctx->r15 = ADD32(0, 0X209);
    // 0x801FBD44: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801FBD48: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FBD4C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801FBD50: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801FBD54: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801FBD58: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801FBD5C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801FBD60: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801FBD64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801FBD68: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x801FBD6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801FBD70: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    // 0x801FBD74: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FBD78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801FBD7C: jal         0x80146208
    // 0x801FBD80: sb          $t3, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r11;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_7;
    // 0x801FBD80: sb          $t3, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r11;
    after_7:
    // 0x801FBD84: lbu         $t1, 0xC($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC);
    // 0x801FBD88: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x801FBD8C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801FBD90: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x801FBD94: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801FBD98: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801FBD9C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FBDA0: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x801FBDA4: beq         $s0, $zero, L_801FBDCC
    if (ctx->r16 == 0) {
        // 0x801FBDA8: sh          $t9, 0x28($t5)
        MEM_H(0X28, ctx->r13) = ctx->r25;
            goto L_801FBDCC;
    }
    // 0x801FBDA8: sh          $t9, 0x28($t5)
    MEM_H(0X28, ctx->r13) = ctx->r25;
    // 0x801FBDAC: jal         0x80005700
    // 0x801FBDB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_8;
    // 0x801FBDB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x801FBDB4: jal         0x801170DC
    // 0x801FBDB8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_9;
    // 0x801FBDB8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_9:
    // 0x801FBDBC: jal         0x801170DC
    // 0x801FBDC0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_10;
    // 0x801FBDC0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_10:
    // 0x801FBDC4: b           L_801FBDE0
    // 0x801FBDC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_801FBDE0;
    // 0x801FBDC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801FBDCC:
    // 0x801FBDCC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FBDD0: addiu       $a1, $a1, -0x420C
    ctx->r5 = ADD32(ctx->r5, -0X420C);
    // 0x801FBDD4: jal         0x800058DC
    // 0x801FBDD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801FBDD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x801FBDDC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801FBDE0:
    // 0x801FBDE0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801FBDE4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801FBDE8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801FBDEC: jr          $ra
    // 0x801FBDF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801FBDF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fbdf4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fbdf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBDF4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FBDF8: lbu         $t6, -0x138D($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X138D);
    // 0x801FBDFC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801FBE00: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fbe04(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fbe04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBE04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FBE08: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x801FBE0C: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x801FBE10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FBE14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FBE18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801FBE1C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801FBE20: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801FBE24: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801FBE28: beq         $at, $zero, L_801FBE34
    if (ctx->r1 == 0) {
        // 0x801FBE2C: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_801FBE34;
    }
    // 0x801FBE2C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801FBE30: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_801FBE34:
    // 0x801FBE34: jal         0x80126944
    // 0x801FBE38: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801FBE38: nop

    after_0:
    // 0x801FBE3C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801FBE40: bne         $v0, $zero, L_801FBFB0
    if (ctx->r2 != 0) {
        // 0x801FBE44: addiu       $v1, $v1, -0x23C0
        ctx->r3 = ADD32(ctx->r3, -0X23C0);
            goto L_801FBFB0;
    }
    // 0x801FBE44: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // 0x801FBE48: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x801FBE4C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801FBE50: addiu       $a0, $a0, -0x4F20
    ctx->r4 = ADD32(ctx->r4, -0X4F20);
    // 0x801FBE54: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801FBE58: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801FBE5C: bgez        $v0, L_801FBE74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801FBE60: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801FBE74;
    }
    // 0x801FBE60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801FBE64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801FBE68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FBE6C: nop

    // 0x801FBE70: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801FBE74:
    // 0x801FBE74: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x801FBE78: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801FBE7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801FBE80: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x801FBE84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801FBE88: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801FBE8C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801FBE90: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FBE94: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FBE98: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x801FBE9C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x801FBEA0: bgez        $t1, L_801FBEB4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801FBEA4: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_801FBEB4;
    }
    // 0x801FBEA4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801FBEA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FBEAC: nop

    // 0x801FBEB0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801FBEB4:
    // 0x801FBEB4: div.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801FBEB8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x801FBEBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801FBEC0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801FBEC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801FBEC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801FBECC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801FBED0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801FBED4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801FBED8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801FBEDC: add.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f10.d + ctx->f6.d;
    // 0x801FBEE0: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801FBEE4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801FBEE8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801FBEEC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801FBEF0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801FBEF4: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x801FBEF8: sh          $t3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r11;
    // 0x801FBEFC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801FBF00: nop

    // 0x801FBF04: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801FBF08: beql        $t5, $zero, L_801FBF58
    if (ctx->r13 == 0) {
        // 0x801FBF0C: mfc1        $t5, $f18
        ctx->r13 = (int32_t)ctx->f18.u32l;
            goto L_801FBF58;
    }
    goto skip_0;
    // 0x801FBF0C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801FBF10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801FBF14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801FBF18: sub.s       $f18, $f2, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x801FBF1C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801FBF20: nop

    // 0x801FBF24: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801FBF28: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801FBF2C: nop

    // 0x801FBF30: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801FBF34: bne         $t5, $zero, L_801FBF4C
    if (ctx->r13 != 0) {
        // 0x801FBF38: nop
    
            goto L_801FBF4C;
    }
    // 0x801FBF38: nop

    // 0x801FBF3C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x801FBF40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801FBF44: b           L_801FBF64
    // 0x801FBF48: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801FBF64;
    // 0x801FBF48: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801FBF4C:
    // 0x801FBF4C: b           L_801FBF64
    // 0x801FBF50: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801FBF64;
    // 0x801FBF50: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801FBF54: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
L_801FBF58:
    // 0x801FBF58: nop

    // 0x801FBF5C: bltz        $t5, L_801FBF4C
    if (SIGNED(ctx->r13) < 0) {
        // 0x801FBF60: nop
    
            goto L_801FBF4C;
    }
    // 0x801FBF60: nop

L_801FBF64:
    // 0x801FBF64: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801FBF68: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x801FBF6C: beql        $t6, $v0, L_801FC054
    if (ctx->r14 == ctx->r2) {
        // 0x801FBF70: lh          $a0, 0x1A($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X1A);
            goto L_801FC054;
    }
    goto skip_1;
    // 0x801FBF70: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    skip_1:
    // 0x801FBF74: lw          $v1, 0x70F4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X70F4);
    // 0x801FBF78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801FBF7C: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801FBF80: bne         $v1, $zero, L_801FBFA0
    if (ctx->r3 != 0) {
        // 0x801FBF84: nop
    
            goto L_801FBFA0;
    }
    // 0x801FBF84: nop

    // 0x801FBF88: jal         0x80005670
    // 0x801FBF8C: addiu       $a1, $a1, 0x710C
    ctx->r5 = ADD32(ctx->r5, 0X710C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801FBF8C: addiu       $a1, $a1, 0x710C
    ctx->r5 = ADD32(ctx->r5, 0X710C);
    after_1:
    // 0x801FBF90: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FBF94: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x801FBF98: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FBF9C: lw          $v1, 0x70F4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X70F4);
L_801FBFA0:
    // 0x801FBFA0: beq         $v1, $zero, L_801FC050
    if (ctx->r3 == 0) {
        // 0x801FBFA4: addiu       $t7, $zero, 0x32
        ctx->r15 = ADD32(0, 0X32);
            goto L_801FC050;
    }
    // 0x801FBFA4: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x801FBFA8: b           L_801FC050
    // 0x801FBFAC: sb          $t7, 0x90($v1)
    MEM_B(0X90, ctx->r3) = ctx->r15;
        goto L_801FC050;
    // 0x801FBFAC: sb          $t7, 0x90($v1)
    MEM_B(0X90, ctx->r3) = ctx->r15;
L_801FBFB0:
    // 0x801FBFB0: jal         0x80126944
    // 0x801FBFB4: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_2;
    // 0x801FBFB4: nop

    after_2:
    // 0x801FBFB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FBFBC: bne         $v0, $at, L_801FC050
    if (ctx->r2 != ctx->r1) {
        // 0x801FBFC0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801FC050;
    }
    // 0x801FBFC0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FBFC4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FBFC8: lbu         $t8, 0x1031($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1031);
    // 0x801FBFCC: blezl       $t8, L_801FC0D0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801FBFD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FC0D0;
    }
    goto skip_2;
    // 0x801FBFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801FBFD4: lh          $t9, 0x44E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X44E);
    // 0x801FBFD8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801FBFDC: addiu       $a0, $a0, -0x4F20
    ctx->r4 = ADD32(ctx->r4, -0X4F20);
    // 0x801FBFE0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801FBFE4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801FBFE8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801FBFEC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801FBFF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801FBFF4: lh          $t0, 0x44C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X44C);
    // 0x801FBFF8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x801FBFFC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801FC000: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801FC004: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801FC008: div.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x801FC00C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801FC010: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801FC014: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801FC018: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801FC01C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x801FC020: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801FC024: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801FC028: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801FC02C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801FC030: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x801FC034: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801FC038: trunc.w.d   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801FC03C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801FC040: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801FC044: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x801FC048: sh          $t4, 0x492($v0)
    MEM_H(0X492, ctx->r2) = ctx->r12;
    // 0x801FC04C: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
L_801FC050:
    // 0x801FC050: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
L_801FC054:
    // 0x801FC054: jal         0x80146CD4
    // 0x801FC058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80146CD4)(rdram, ctx);
        goto after_3;
    // 0x801FC058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x801FC05C: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x801FC060: jal         0x80146BE0
    // 0x801FC064: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80146BE0)(rdram, ctx);
        goto after_4;
    // 0x801FC064: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x801FC068: jal         0x80236BA4
    // 0x801FC06C: nop

    LOOKUP_FUNC(0x80236BA4)(rdram, ctx);
        goto after_5;
    // 0x801FC06C: nop

    after_5:
    // 0x801FC070: beq         $v0, $zero, L_801FC088
    if (ctx->r2 == 0) {
        // 0x801FC074: lui         $t5, 0x8022
        ctx->r13 = S32(0X8022 << 16);
            goto L_801FC088;
    }
    // 0x801FC074: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x801FC078: lbu         $t5, -0x4F1C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4F1C);
    // 0x801FC07C: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801FC080: bne         $t5, $zero, L_801FC0A4
    if (ctx->r13 != 0) {
        // 0x801FC084: nop
    
            goto L_801FC0A4;
    }
    // 0x801FC084: nop

L_801FC088:
    // 0x801FC088: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801FC08C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FC090: jal         0x80147148
    // 0x801FC094: lw          $a0, 0x24($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X24);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_6;
    // 0x801FC094: lw          $a0, 0x24($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X24);
    after_6:
    // 0x801FC098: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FC09C: b           L_801FC0CC
    // 0x801FC0A0: sb          $zero, 0x70F0($at)
    MEM_B(0X70F0, ctx->r1) = 0;
        goto L_801FC0CC;
    // 0x801FC0A0: sb          $zero, 0x70F0($at)
    MEM_B(0X70F0, ctx->r1) = 0;
L_801FC0A4:
    // 0x801FC0A4: lbu         $t7, 0x70F0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X70F0);
    // 0x801FC0A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x801FC0AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FC0B0: bnel        $t7, $zero, L_801FC0D0
    if (ctx->r15 != 0) {
        // 0x801FC0B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FC0D0;
    }
    goto skip_3;
    // 0x801FC0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801FC0B8: jal         0x80147148
    // 0x801FC0BC: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_7;
    // 0x801FC0BC: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    after_7:
    // 0x801FC0C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801FC0C4: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FC0C8: sb          $t9, 0x70F0($at)
    MEM_B(0X70F0, ctx->r1) = ctx->r25;
L_801FC0CC:
    // 0x801FC0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FC0D0:
    // 0x801FC0D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FC0D4: jr          $ra
    // 0x801FC0D8: nop

    return;
    // 0x801FC0D8: nop

;}
RECOMP_FUNC void M9_FUN_801fc0dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC0DC: jr          $ra
    // 0x801FC0E0: nop

    return;
    // 0x801FC0E0: nop

;}
RECOMP_FUNC void M9_FUN_801fc0e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC0E4: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x801FC0E8: lbu         $t6, -0x4F1C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4F1C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc0ec(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc0ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC0EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FC0F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FC0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC0F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FC0FC: bne         $t6, $at, L_801FC10C
    if (ctx->r14 != ctx->r1) {
        // 0x801FC100: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_801FC10C;
    }
    // 0x801FC100: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801FC104: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801FC108: sb          $t7, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r15;
L_801FC10C:
    // 0x801FC10C: lbu         $t8, 0x91($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X91);
    // 0x801FC110: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801FC114: addiu       $a1, $zero, 0x10E
    ctx->r5 = ADD32(0, 0X10E);
    // 0x801FC118: beq         $t8, $zero, L_801FC150
    if (ctx->r24 == 0) {
        // 0x801FC11C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801FC150;
    }
    // 0x801FC11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FC120: jal         0x80126A0C
    // 0x801FC124: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x801FC124: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801FC128: beq         $v0, $zero, L_801FC150
    if (ctx->r2 == 0) {
        // 0x801FC12C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_801FC150;
    }
    // 0x801FC12C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801FC130: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    // 0x801FC134: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801FC138: jal         0x80147148
    // 0x801FC13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_1;
    // 0x801FC13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801FC140: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FC144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801FC148: jal         0x800058DC
    // 0x801FC14C: addiu       $a1, $a1, -0x420C
    ctx->r5 = ADD32(ctx->r5, -0X420C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FC14C: addiu       $a1, $a1, -0x420C
    ctx->r5 = ADD32(ctx->r5, -0X420C);
    after_2:
L_801FC150:
    // 0x801FC150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FC154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FC158: jr          $ra
    // 0x801FC15C: nop

    return;
    // 0x801FC15C: nop

;}
RECOMP_FUNC void M9_FUN_801fc160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC160: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801FC164: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801FC168: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801FC16C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801FC170: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x801FC174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FC178: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801FC17C: bne         $v1, $zero, L_801FC210
    if (ctx->r3 != 0) {
        // 0x801FC180: addiu       $a3, $zero, 0x55
        ctx->r7 = ADD32(0, 0X55);
            goto L_801FC210;
    }
    // 0x801FC180: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
    // 0x801FC184: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x801FC188: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FC18C: jal         0x801465A0
    // 0x801FC190: lhu         $a2, -0x23BE($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X23BE);
    LOOKUP_FUNC(0x801465A0)(rdram, ctx);
        goto after_0;
    // 0x801FC190: lhu         $a2, -0x23BE($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X23BE);
    after_0:
    // 0x801FC194: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x801FC198: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801FC19C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801FC1A0: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x801FC1A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FC1A8: addiu       $t2, $zero, 0x209
    ctx->r10 = ADD32(0, 0X209);
    // 0x801FC1AC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801FC1B0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801FC1B4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801FC1B8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801FC1BC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801FC1C0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FC1C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801FC1C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FC1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FC1D0: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x801FC1D4: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x801FC1D8: addiu       $a3, $zero, 0x5E
    ctx->r7 = ADD32(0, 0X5E);
    // 0x801FC1DC: jal         0x80146208
    // 0x801FC1E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x801FC1E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x801FC1E4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801FC1E8: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x801FC1EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801FC1F0: lhu         $a2, -0x23C0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X23C0);
    // 0x801FC1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FC1F8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x801FC1FC: jal         0x801465A0
    // 0x801FC200: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    LOOKUP_FUNC(0x801465A0)(rdram, ctx);
        goto after_2;
    // 0x801FC200: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    after_2:
    // 0x801FC204: jal         0x80006214
    // 0x801FC208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801FC208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801FC20C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
L_801FC210:
    // 0x801FC210: beq         $v1, $zero, L_801FC22C
    if (ctx->r3 == 0) {
        // 0x801FC214: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801FC22C;
    }
    // 0x801FC214: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801FC218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801FC21C: sb          $a3, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r7;
L_801FC220:
    // 0x801FC220: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801FC224: bnel        $v0, $zero, L_801FC220
    if (ctx->r2 != 0) {
        // 0x801FC228: sb          $a3, 0x22($v0)
        MEM_B(0X22, ctx->r2) = ctx->r7;
            goto L_801FC220;
    }
    goto skip_0;
    // 0x801FC228: sb          $a3, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r7;
    skip_0:
L_801FC22C:
    // 0x801FC22C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FC230: lwc1        $f4, -0x4F20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4F20);
    // 0x801FC234: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801FC238: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801FC23C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801FC240: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801FC244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FC248: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801FC24C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801FC250: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801FC254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FC258: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801FC25C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801FC260: nop

    // 0x801FC264: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x801FC268: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801FC26C: nop

    // 0x801FC270: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801FC274: beql        $a2, $zero, L_801FC2C8
    if (ctx->r6 == 0) {
        // 0x801FC278: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801FC2C8;
    }
    goto skip_1;
    // 0x801FC278: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801FC27C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801FC280: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801FC284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FC288: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x801FC28C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801FC290: nop

    // 0x801FC294: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x801FC298: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801FC29C: nop

    // 0x801FC2A0: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801FC2A4: bne         $a2, $zero, L_801FC2BC
    if (ctx->r6 != 0) {
        // 0x801FC2A8: nop
    
            goto L_801FC2BC;
    }
    // 0x801FC2A8: nop

    // 0x801FC2AC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801FC2B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801FC2B4: b           L_801FC2D4
    // 0x801FC2B8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801FC2D4;
    // 0x801FC2B8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801FC2BC:
    // 0x801FC2BC: b           L_801FC2D4
    // 0x801FC2C0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801FC2D4;
    // 0x801FC2C0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801FC2C4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801FC2C8:
    // 0x801FC2C8: nop

    // 0x801FC2CC: bltz        $a2, L_801FC2BC
    if (SIGNED(ctx->r6) < 0) {
        // 0x801FC2D0: nop
    
            goto L_801FC2BC;
    }
    // 0x801FC2D0: nop

L_801FC2D4:
    // 0x801FC2D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801FC2D8: jal         0x8014677C
    // 0x801FC2DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    LOOKUP_FUNC(0x8014677C)(rdram, ctx);
        goto after_4;
    // 0x801FC2DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_4:
    // 0x801FC2E0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801FC2E4: lhu         $a2, -0x23C0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X23C0);
    // 0x801FC2E8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801FC2EC: jal         0x8014677C
    // 0x801FC2F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8014677C)(rdram, ctx);
        goto after_5;
    // 0x801FC2F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x801FC2F4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FC2F8: lwc1        $f18, -0x4F20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4F20);
    // 0x801FC2FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801FC300: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801FC304: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801FC308: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801FC30C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801FC310: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801FC314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801FC318: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801FC31C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801FC320: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801FC324: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801FC328: nop

    // 0x801FC32C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x801FC330: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801FC334: nop

    // 0x801FC338: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801FC33C: beql        $t7, $zero, L_801FC390
    if (ctx->r15 == 0) {
        // 0x801FC340: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_801FC390;
    }
    goto skip_2;
    // 0x801FC340: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x801FC344: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801FC348: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801FC34C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801FC350: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x801FC354: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801FC358: nop

    // 0x801FC35C: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x801FC360: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801FC364: nop

    // 0x801FC368: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801FC36C: bne         $t7, $zero, L_801FC384
    if (ctx->r15 != 0) {
        // 0x801FC370: nop
    
            goto L_801FC384;
    }
    // 0x801FC370: nop

    // 0x801FC374: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x801FC378: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801FC37C: b           L_801FC39C
    // 0x801FC380: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801FC39C;
    // 0x801FC380: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801FC384:
    // 0x801FC384: b           L_801FC39C
    // 0x801FC388: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801FC39C;
    // 0x801FC388: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801FC38C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_801FC390:
    // 0x801FC390: nop

    // 0x801FC394: bltz        $t7, L_801FC384
    if (SIGNED(ctx->r15) < 0) {
        // 0x801FC398: nop
    
            goto L_801FC384;
    }
    // 0x801FC398: nop

L_801FC39C:
    // 0x801FC39C: lhu         $t9, -0x23BE($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X23BE);
    // 0x801FC3A0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801FC3A4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801FC3A8: bnel        $t8, $t9, L_801FC3C0
    if (ctx->r24 != ctx->r25) {
        // 0x801FC3AC: lbu         $v0, 0x90($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X90);
            goto L_801FC3C0;
    }
    goto skip_3;
    // 0x801FC3AC: lbu         $v0, 0x90($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X90);
    skip_3:
    // 0x801FC3B0: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x801FC3B4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801FC3B8: sb          $t1, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r9;
    // 0x801FC3BC: lbu         $v0, 0x90($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X90);
L_801FC3C0:
    // 0x801FC3C0: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x801FC3C4: bnel        $at, $zero, L_801FC3FC
    if (ctx->r1 != 0) {
        // 0x801FC3C8: slti        $at, $v0, 0xF
        ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
            goto L_801FC3FC;
    }
    goto skip_4;
    // 0x801FC3C8: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    skip_4:
    // 0x801FC3CC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x801FC3D0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801FC3D4: beql        $v0, $zero, L_801FC444
    if (ctx->r2 == 0) {
        // 0x801FC3D8: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_801FC444;
    }
    goto skip_5;
    // 0x801FC3D8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x801FC3DC: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
L_801FC3E0:
    // 0x801FC3E0: sb          $v1, 0xB($t2)
    MEM_B(0XB, ctx->r10) = ctx->r3;
    // 0x801FC3E4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801FC3E8: bnel        $v0, $zero, L_801FC3E0
    if (ctx->r2 != 0) {
        // 0x801FC3EC: lw          $t2, 0x30($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X30);
            goto L_801FC3E0;
    }
    goto skip_6;
    // 0x801FC3EC: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    skip_6:
    // 0x801FC3F0: b           L_801FC444
    // 0x801FC3F4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
        goto L_801FC444;
    // 0x801FC3F4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x801FC3F8: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
L_801FC3FC:
    // 0x801FC3FC: beql        $at, $zero, L_801FC444
    if (ctx->r1 == 0) {
        // 0x801FC400: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_801FC444;
    }
    goto skip_7;
    // 0x801FC400: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x801FC404: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x801FC408: beql        $v0, $zero, L_801FC444
    if (ctx->r2 == 0) {
        // 0x801FC40C: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_801FC444;
    }
    goto skip_8;
    // 0x801FC40C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_8:
    // 0x801FC410: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
L_801FC414:
    // 0x801FC414: lbu         $v1, 0xB($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XB);
    // 0x801FC418: addiu       $v1, $v1, -0x14
    ctx->r3 = ADD32(ctx->r3, -0X14);
    // 0x801FC41C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FC420: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FC424: bgezl       $v1, L_801FC434
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801FC428: sb          $v1, 0xB($a0)
        MEM_B(0XB, ctx->r4) = ctx->r3;
            goto L_801FC434;
    }
    goto skip_9;
    // 0x801FC428: sb          $v1, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r3;
    skip_9:
    // 0x801FC42C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801FC430: sb          $v1, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r3;
L_801FC434:
    // 0x801FC434: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801FC438: bnel        $v0, $zero, L_801FC414
    if (ctx->r2 != 0) {
        // 0x801FC43C: lw          $a0, 0x30($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X30);
            goto L_801FC414;
    }
    goto skip_10;
    // 0x801FC43C: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    skip_10:
    // 0x801FC440: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
L_801FC444:
    // 0x801FC444: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FC448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FC44C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801FC450: sb          $a3, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r7;
    // 0x801FC454: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801FC458: bnel        $t5, $zero, L_801FC46C
    if (ctx->r13 != 0) {
        // 0x801FC45C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801FC46C;
    }
    goto skip_11;
    // 0x801FC45C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_11:
    // 0x801FC460: jal         0x80005700
    // 0x801FC464: sw          $zero, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_6;
    // 0x801FC464: sw          $zero, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = 0;
    after_6:
    // 0x801FC468: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801FC46C:
    // 0x801FC46C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801FC470: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801FC474: jr          $ra
    // 0x801FC478: nop

    return;
    // 0x801FC478: nop

;}
RECOMP_FUNC void M9_FUN_801fc47c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC47C: jr          $ra
    // 0x801FC480: nop

    return;
    // 0x801FC480: nop

;}
RECOMP_FUNC void M9_FUN_801fc484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC484: nop

    // 0x801FC488: nop

    // 0x801FC48C: nop

;}
RECOMP_FUNC void M9_FUN_801fc490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FC494: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FC498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC49C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801FC4A0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FC4A4: sh          $zero, -0x41F4($at)
    MEM_H(-0X41F4, ctx->r1) = 0;
    // 0x801FC4A8: jal         0x800058DC
    // 0x801FC4AC: addiu       $a1, $a1, -0x3B40
    ctx->r5 = ADD32(ctx->r5, -0X3B40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FC4AC: addiu       $a1, $a1, -0x3B40
    ctx->r5 = ADD32(ctx->r5, -0X3B40);
    after_0:
    // 0x801FC4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FC4B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FC4B8: jr          $ra
    // 0x801FC4BC: nop

    return;
    // 0x801FC4BC: nop

;}
RECOMP_FUNC void M9_FUN_801fc4c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC4C0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FC4C4: lhu         $t6, -0x41F4($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X41F4);
    // 0x801FC4C8: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc4cc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc4cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC4CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FC4D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FC4D4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801FC4D8: lw          $v0, 0x7120($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7120);
    // 0x801FC4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC4E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FC4E4: beql        $v0, $zero, L_801FC4F8
    if (ctx->r2 == 0) {
        // 0x801FC4E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FC4F8;
    }
    goto skip_0;
    // 0x801FC4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FC4EC: jalr        $v0
    // 0x801FC4F0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801FC4F0: nop

    after_0:
    // 0x801FC4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FC4F8:
    // 0x801FC4F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FC4FC: jr          $ra
    // 0x801FC500: nop

    return;
    // 0x801FC500: nop

;}
RECOMP_FUNC void M9_FUN_801fc504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC504: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FC508: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FC50C: lh          $t6, 0x226($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X226);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc510(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FC514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC518: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801FC51C: sh          $t7, 0x226($v0)
    MEM_H(0X226, ctx->r2) = ctx->r15;
    // 0x801FC520: lh          $t8, 0x226($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X226);
    // 0x801FC524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FC528: bnel        $t8, $zero, L_801FC54C
    if (ctx->r24 != 0) {
        // 0x801FC52C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FC54C;
    }
    goto skip_0;
    // 0x801FC52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FC530: jal         0x80020718
    // 0x801FC534: lhu         $a0, 0x228($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X228);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801FC534: lhu         $a0, 0x228($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X228);
    after_0:
    // 0x801FC538: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FC53C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FC540: sh          $zero, 0x224($v0)
    MEM_H(0X224, ctx->r2) = 0;
    // 0x801FC544: sh          $zero, 0x21C($v0)
    MEM_H(0X21C, ctx->r2) = 0;
    // 0x801FC548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FC54C:
    // 0x801FC54C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FC550: jr          $ra
    // 0x801FC554: nop

    return;
    // 0x801FC554: nop

;}
RECOMP_FUNC void M9_FUN_801fc558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC558: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FC55C: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc560(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC560: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801FC564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC568: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801FC56C: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801FC570: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FC574: lwc1        $f6, -0x70A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X70A4);
    // 0x801FC578: lui         $at, 0xC3A4
    ctx->r1 = S32(0XC3A4 << 16);
    // 0x801FC57C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FC580: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FC584: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FC588: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801FC58C: jal         0x8001EF38
    // 0x801FC590: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801FC590: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x801FC594: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801FC598: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x801FC59C: addiu       $t9, $v0, 0x270
    ctx->r25 = ADD32(ctx->r2, 0X270);
    // 0x801FC5A0: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801FC5A4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801FC5A8: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801FC5AC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FC5B0: lwc1        $f16, -0x70A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X70A0);
    // 0x801FC5B4: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FC5B8: lui         $at, 0xC3A4
    ctx->r1 = S32(0XC3A4 << 16);
    // 0x801FC5BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FC5C0: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801FC5C4: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FC5C8: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801FC5CC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801FC5D0: nop

    // 0x801FC5D4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801FC5D8: jal         0x8002FC20
    // 0x801FC5DC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801FC5DC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x801FC5E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801FC5E4: jal         0x8001EAD0
    // 0x801FC5E8: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801FC5E8: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    after_2:
    // 0x801FC5EC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801FC5F0: lui         $at, 0x4386
    ctx->r1 = S32(0X4386 << 16);
    // 0x801FC5F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FC5F8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801FC5FC: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x801FC600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FC604: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    // 0x801FC608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FC60C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801FC610: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801FC614: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801FC618: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801FC61C: nop

    // 0x801FC620: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FC624: jal         0x8002096C
    // 0x801FC628: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8002096C)(rdram, ctx);
        goto after_3;
    // 0x801FC628: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_3:
    // 0x801FC62C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801FC630: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801FC634: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801FC638: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801FC63C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FC640: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801FC644: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FC648: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801FC64C: jal         0x8001EF38
    // 0x801FC650: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x801FC650: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    after_4:
    // 0x801FC654: addiu       $a0, $v0, 0x270
    ctx->r4 = ADD32(ctx->r2, 0X270);
    // 0x801FC658: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FC65C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FC660: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801FC664: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FC668: jal         0x8001EB64
    // 0x801FC66C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x801FC66C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x801FC670: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x801FC674: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FC678: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    // 0x801FC67C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801FC680: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801FC684: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801FC688: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801FC68C: nop

    // 0x801FC690: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FC694: jal         0x8002096C
    // 0x801FC698: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8002096C)(rdram, ctx);
        goto after_6;
    // 0x801FC698: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_6:
    // 0x801FC69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FC6A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801FC6A4: jr          $ra
    // 0x801FC6A8: nop

    return;
    // 0x801FC6A8: nop

;}
RECOMP_FUNC void M9_FUN_801fc6ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC6AC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FC6B0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FC6B4: lh          $t6, 0x226($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X226);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc6b8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc6b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC6B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FC6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC6C0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801FC6C4: sh          $t7, 0x226($v0)
    MEM_H(0X226, ctx->r2) = ctx->r15;
    // 0x801FC6C8: lh          $t8, 0x226($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X226);
    // 0x801FC6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FC6D0: bnel        $t8, $zero, L_801FC6F4
    if (ctx->r24 != 0) {
        // 0x801FC6D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FC6F4;
    }
    goto skip_0;
    // 0x801FC6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FC6D8: jal         0x800208C4
    // 0x801FC6DC: lhu         $a0, 0x228($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X228);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801FC6DC: lhu         $a0, 0x228($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X228);
    after_0:
    // 0x801FC6E0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FC6E4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FC6E8: sh          $zero, 0x224($v0)
    MEM_H(0X224, ctx->r2) = 0;
    // 0x801FC6EC: sh          $zero, 0x21C($v0)
    MEM_H(0X21C, ctx->r2) = 0;
    // 0x801FC6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FC6F4:
    // 0x801FC6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FC6F8: jr          $ra
    // 0x801FC6FC: nop

    return;
    // 0x801FC6FC: nop

;}
RECOMP_FUNC void M9_FUN_801fc700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC700: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FC704: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FC708: sh          $zero, 0x21C($v0)
    MEM_H(0X21C, ctx->r2) = 0;
    // 0x801FC70C: sw          $zero, 0x220($v0)
    MEM_W(0X220, ctx->r2) = 0;
    // 0x801FC710: sh          $zero, 0x224($v0)
    MEM_H(0X224, ctx->r2) = 0;
    // 0x801FC714: sh          $zero, 0x226($v0)
    MEM_H(0X226, ctx->r2) = 0;
    // 0x801FC718: jr          $ra
    // 0x801FC71C: sh          $zero, 0x228($v0)
    MEM_H(0X228, ctx->r2) = 0;
    return;
    // 0x801FC71C: sh          $zero, 0x228($v0)
    MEM_H(0X228, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc720(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FC724: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FC728: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801FC72C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FC730: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x801FC734: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801FC738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FC73C: bne         $at, $zero, L_801FC74C
    if (ctx->r1 != 0) {
        // 0x801FC740: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_801FC74C;
    }
    // 0x801FC740: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x801FC744: b           L_801FC814
    // 0x801FC748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801FC814;
    // 0x801FC748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FC74C:
    // 0x801FC74C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801FC750: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801FC754: sh          $a0, 0x228($v1)
    MEM_H(0X228, ctx->r3) = ctx->r4;
    // 0x801FC758: sh          $a1, 0x21C($v1)
    MEM_H(0X21C, ctx->r3) = ctx->r5;
    // 0x801FC75C: sw          $a2, 0x220($v1)
    MEM_W(0X220, ctx->r3) = ctx->r6;
    // 0x801FC760: sh          $zero, 0x224($v1)
    MEM_H(0X224, ctx->r3) = 0;
    // 0x801FC764: bne         $v0, $zero, L_801FC77C
    if (ctx->r2 != 0) {
        // 0x801FC768: sh          $zero, 0x226($v1)
        MEM_H(0X226, ctx->r3) = 0;
            goto L_801FC77C;
    }
    // 0x801FC768: sh          $zero, 0x226($v1)
    MEM_H(0X226, ctx->r3) = 0;
    // 0x801FC76C: sh          $zero, 0x228($v1)
    MEM_H(0X228, ctx->r3) = 0;
    // 0x801FC770: sh          $zero, 0x21C($v1)
    MEM_H(0X21C, ctx->r3) = 0;
    // 0x801FC774: b           L_801FC814
    // 0x801FC778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FC814;
    // 0x801FC778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FC77C:
    // 0x801FC77C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FC780: bnel        $v0, $at, L_801FC7A8
    if (ctx->r2 != ctx->r1) {
        // 0x801FC784: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801FC7A8;
    }
    goto skip_0;
    // 0x801FC784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
    // 0x801FC788: jal         0x80020718
    // 0x801FC78C: lhu         $a0, 0x228($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X228);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801FC78C: lhu         $a0, 0x228($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X228);
    after_0:
    // 0x801FC790: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801FC794: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801FC798: sh          $zero, 0x21C($v1)
    MEM_H(0X21C, ctx->r3) = 0;
    // 0x801FC79C: b           L_801FC814
    // 0x801FC7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FC814;
    // 0x801FC7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801FC7A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_801FC7A8:
    // 0x801FC7A8: bnel        $v0, $at, L_801FC7D0
    if (ctx->r2 != ctx->r1) {
        // 0x801FC7AC: lhu         $v0, 0x21C($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X21C);
            goto L_801FC7D0;
    }
    goto skip_1;
    // 0x801FC7AC: lhu         $v0, 0x21C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X21C);
    skip_1:
    // 0x801FC7B0: jal         0x800208C4
    // 0x801FC7B4: lhu         $a0, 0x228($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X228);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801FC7B4: lhu         $a0, 0x228($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X228);
    after_1:
    // 0x801FC7B8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801FC7BC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801FC7C0: sh          $zero, 0x21C($v1)
    MEM_H(0X21C, ctx->r3) = 0;
    // 0x801FC7C4: b           L_801FC814
    // 0x801FC7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FC814;
    // 0x801FC7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801FC7CC: lhu         $v0, 0x21C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X21C);
L_801FC7D0:
    // 0x801FC7D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801FC7D4: beq         $v0, $at, L_801FC7F4
    if (ctx->r2 == ctx->r1) {
        // 0x801FC7D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801FC7F4;
    }
    // 0x801FC7D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801FC7DC: beq         $v0, $at, L_801FC7FC
    if (ctx->r2 == ctx->r1) {
        // 0x801FC7E0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801FC7FC;
    }
    // 0x801FC7E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801FC7E4: beql        $v0, $at, L_801FC810
    if (ctx->r2 == ctx->r1) {
        // 0x801FC7E8: sh          $a2, 0x226($v1)
        MEM_H(0X226, ctx->r3) = ctx->r6;
            goto L_801FC810;
    }
    goto skip_2;
    // 0x801FC7E8: sh          $a2, 0x226($v1)
    MEM_H(0X226, ctx->r3) = ctx->r6;
    skip_2:
    // 0x801FC7EC: b           L_801FC814
    // 0x801FC7F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FC814;
    // 0x801FC7F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FC7F4:
    // 0x801FC7F4: b           L_801FC810
    // 0x801FC7F8: sh          $a2, 0x226($v1)
    MEM_H(0X226, ctx->r3) = ctx->r6;
        goto L_801FC810;
    // 0x801FC7F8: sh          $a2, 0x226($v1)
    MEM_H(0X226, ctx->r3) = ctx->r6;
L_801FC7FC:
    // 0x801FC7FC: jal         0x80020718
    // 0x801FC800: lhu         $a0, 0x228($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X228);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801FC800: lhu         $a0, 0x228($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X228);
    after_2:
    // 0x801FC804: b           L_801FC814
    // 0x801FC808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FC814;
    // 0x801FC808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801FC80C: sh          $a2, 0x226($v1)
    MEM_H(0X226, ctx->r3) = ctx->r6;
L_801FC810:
    // 0x801FC810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FC814:
    // 0x801FC814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FC818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FC81C: jr          $ra
    // 0x801FC820: nop

    return;
    // 0x801FC820: nop

;}
RECOMP_FUNC void M9_FUN_801fc824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC824: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FC828: jr          $ra
    // 0x801FC82C: lhu         $v0, -0x41F4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X41F4);
    return;
    // 0x801FC82C: lhu         $v0, -0x41F4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X41F4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fc830(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fc830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC830: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801FC834: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FC838: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801FC83C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FC840: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801FC844: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x801FC848: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x801FC84C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801FC850: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801FC854: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x801FC858: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801FC85C: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FC860: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801FC864: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FC868: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801FC86C: jal         0x8001EF38
    // 0x801FC870: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801FC870: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x801FC874: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801FC878: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801FC87C: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x801FC880: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801FC884: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801FC888: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801FC88C: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FC890: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FC894: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801FC898: jal         0x8001EF38
    // 0x801FC89C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801FC89C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x801FC8A0: lh          $t8, 0x28($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X28);
    // 0x801FC8A4: subu        $a0, $t8, $v0
    ctx->r4 = SUB32(ctx->r24, ctx->r2);
    // 0x801FC8A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FC8AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FC8B0: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801FC8B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FC8B8: jal         0x8001EAD0
    // 0x801FC8BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801FC8BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x801FC8C0: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x801FC8C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FC8C8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x801FC8CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801FC8D0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801FC8D4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801FC8D8: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801FC8DC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801FC8E0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801FC8E4: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801FC8E8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x801FC8EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801FC8F0: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801FC8F4: lw          $a3, 0x30($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X30);
    // 0x801FC8F8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801FC8FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801FC900: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FC904: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801FC908: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801FC90C: jal         0x8012FFDC
    // 0x801FC910: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8012FFDC)(rdram, ctx);
        goto after_3;
    // 0x801FC910: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_3:
    // 0x801FC914: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801FC918: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801FC91C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801FC920: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x801FC924: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x801FC928: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801FC92C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x801FC930: bc1fl       L_801FC94C
    if (!c1cs) {
        // 0x801FC934: c.lt.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
            goto L_801FC94C;
    }
    goto skip_0;
    // 0x801FC934: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    skip_0:
    // 0x801FC938: jal         0x800207D0
    // 0x801FC93C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_4;
    // 0x801FC93C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801FC940: b           L_801FC9B0
    // 0x801FC944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801FC9B0;
    // 0x801FC944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FC948: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
L_801FC94C:
    // 0x801FC94C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801FC950: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FC954: bc1f        L_801FC960
    if (!c1cs) {
        // 0x801FC958: nop
    
            goto L_801FC960;
    }
    // 0x801FC958: nop

    // 0x801FC95C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_801FC960:
    // 0x801FC960: ldc1        $f10, -0x7098($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X7098);
    // 0x801FC964: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x801FC968: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801FC96C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801FC970: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x801FC974: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x801FC978: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801FC97C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801FC980: nop

    // 0x801FC984: blezl       $t2, L_801FC9B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x801FC988: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801FC9B0;
    }
    goto skip_1;
    // 0x801FC988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801FC98C: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x801FC990: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x801FC994: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x801FC998: sub.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x801FC99C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801FC9A0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801FC9A4: jal         0x800207D0
    // 0x801FC9A8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_5;
    // 0x801FC9A8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_5:
    // 0x801FC9AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801FC9B0:
    // 0x801FC9B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801FC9B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801FC9B8: jr          $ra
    // 0x801FC9BC: nop

    return;
    // 0x801FC9BC: nop

;}
RECOMP_FUNC void M9_FUN_801fc9c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FC9C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FC9C4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FC9C8: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801FC9CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FC9D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801FC9D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801FC9D8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801FC9DC: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801FC9E0: lw          $a3, 0x30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X30);
    // 0x801FC9E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801FC9E8: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801FC9EC: jal         0x8012FFDC
    // 0x801FC9F0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012FFDC)(rdram, ctx);
        goto after_0;
    // 0x801FC9F0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801FC9F4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801FC9F8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FC9FC: ldc1        $f8, -0x7090($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X7090);
    // 0x801FCA00: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801FCA04: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801FCA08: div.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x801FCA0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FCA10: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    // 0x801FCA14: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801FCA18: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801FCA1C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801FCA20: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801FCA24: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x801FCA28: nop

    // 0x801FCA2C: blezl       $v0, L_801FCA40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801FCA30: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FCA40;
    }
    goto skip_0;
    // 0x801FCA30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801FCA34: jal         0x800207A0
    // 0x801FCA38: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x800207A0)(rdram, ctx);
        goto after_1;
    // 0x801FCA38: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_1:
    // 0x801FCA3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FCA40:
    // 0x801FCA40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FCA44: jr          $ra
    // 0x801FCA48: nop

    return;
    // 0x801FCA48: nop

;}
