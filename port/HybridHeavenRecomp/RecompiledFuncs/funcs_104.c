#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M12_FUN_802428c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802428C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802428C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802428C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802428CC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802428D0: jal         0x800058DC
    // 0x802428D4: addiu       $a1, $a1, 0x28E8
    ctx->r5 = ADD32(ctx->r5, 0X28E8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802428D4: addiu       $a1, $a1, 0x28E8
    ctx->r5 = ADD32(ctx->r5, 0X28E8);
    after_0:
    // 0x802428D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802428DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802428E0: jr          $ra
    // 0x802428E4: nop

    return;
    // 0x802428E4: nop

;}
RECOMP_FUNC void M12_FUN_802428e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802428E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802428EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802428F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x802428F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x802428F8: jal         0x80133A24
    // 0x802428FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x802428FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80242900: beq         $v0, $zero, L_80242918
    if (ctx->r2 == 0) {
        // 0x80242904: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80242918;
    }
    // 0x80242904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80242908: jal         0x80005700
    // 0x8024290C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x8024290C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80242910: b           L_8024294C
    // 0x80242914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8024294C;
    // 0x80242914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80242918:
    // 0x80242918: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8024291C: jal         0x80126CC0
    // 0x80242920: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_2;
    // 0x80242920: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    after_2:
    // 0x80242924: beq         $v0, $zero, L_80242948
    if (ctx->r2 == 0) {
        // 0x80242928: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80242948;
    }
    // 0x80242928: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8024292C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80242930: addiu       $t6, $t6, 0x2958
    ctx->r14 = ADD32(ctx->r14, 0X2958);
    // 0x80242934: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80242938: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    // 0x8024293C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80242940: jal         0x8013B570
    // 0x80242944: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_3;
    // 0x80242944: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
L_80242948:
    // 0x80242948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8024294C:
    // 0x8024294C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80242950: jr          $ra
    // 0x80242954: nop

    return;
    // 0x80242954: nop

;}
RECOMP_FUNC void M12_FUN_80242958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8024295C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242960: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80242964: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x80242968: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8024296C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80242970: sh          $t6, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r14;
    // 0x80242974: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80242978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8024297C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242980: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80242984: addiu       $a1, $a1, 0x29A8
    ctx->r5 = ADD32(ctx->r5, 0X29A8);
    // 0x80242988: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8024298C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80242990: jal         0x800058DC
    // 0x80242994: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80242994: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x80242998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8024299C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802429A0: jr          $ra
    // 0x802429A4: nop

    return;
    // 0x802429A4: nop

;}
RECOMP_FUNC void M12_FUN_802429a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802429A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802429AC: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x802429B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802429B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x802429B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802429BC: addiu       $t7, $t7, 0x5DD4
    ctx->r15 = ADD32(ctx->r15, 0X5DD4);
    // 0x802429C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x802429C4: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x802429C8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x802429CC: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x802429D0: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x802429D4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x802429D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x802429DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x802429E0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x802429E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x802429E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x802429EC: jal         0x8012CE9C
    // 0x802429F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x802429F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x802429F4: bne         $v0, $zero, L_80242A2C
    if (ctx->r2 != 0) {
        // 0x802429F8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80242A2C;
    }
    // 0x802429F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x802429FC: jal         0x80010550
    // 0x80242A00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80242A00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80242A04: jal         0x80133A24
    // 0x80242A08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_2;
    // 0x80242A08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_2:
    // 0x80242A0C: beq         $v0, $zero, L_80242A2C
    if (ctx->r2 == 0) {
        // 0x80242A10: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80242A2C;
    }
    // 0x80242A10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80242A14: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80242A18: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242A1C: addiu       $a1, $a1, 0x2A3C
    ctx->r5 = ADD32(ctx->r5, 0X2A3C);
    // 0x80242A20: sh          $t1, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r9;
    // 0x80242A24: jal         0x800058DC
    // 0x80242A28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80242A28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80242A2C:
    // 0x80242A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80242A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80242A34: jr          $ra
    // 0x80242A38: nop

    return;
    // 0x80242A38: nop

;}
RECOMP_FUNC void M12_FUN_80242a3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242A3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80242A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80242A44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80242A48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80242A4C: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80242A50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80242A54: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80242A58: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80242A5C: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80242A60: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80242A64: addiu       $t9, $t9, 0x5DE0
    ctx->r25 = ADD32(ctx->r25, 0X5DE0);
    // 0x80242A68: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x80242A6C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80242A70: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80242A74: nop

    // 0x80242A78: bc1fl       L_80242A94
    if (!c1cs) {
        // 0x80242A7C: lw          $t1, 0x0($t9)
        ctx->r9 = MEM_W(ctx->r25, 0X0);
            goto L_80242A94;
    }
    goto skip_0;
    // 0x80242A7C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    skip_0:
    // 0x80242A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80242A84: nop

    // 0x80242A88: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80242A8C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80242A90: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
L_80242A94:
    // 0x80242A94: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80242A98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242A9C: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x80242AA0: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80242AA4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80242AA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80242AAC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80242AB0: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80242AB4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80242AB8: jal         0x8012CE9C
    // 0x80242ABC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x80242ABC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x80242AC0: bne         $v0, $zero, L_80242AF0
    if (ctx->r2 != 0) {
        // 0x80242AC4: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80242AF0;
    }
    // 0x80242AC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242AC8: jal         0x80010550
    // 0x80242ACC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80242ACC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80242AD0: beq         $v0, $zero, L_80242AF0
    if (ctx->r2 == 0) {
        // 0x80242AD4: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80242AF0;
    }
    // 0x80242AD4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80242AD8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80242ADC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242AE0: addiu       $a1, $a1, 0x2B00
    ctx->r5 = ADD32(ctx->r5, 0X2B00);
    // 0x80242AE4: sh          $t3, 0x78($t4)
    MEM_H(0X78, ctx->r12) = ctx->r11;
    // 0x80242AE8: jal         0x800058DC
    // 0x80242AEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80242AEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80242AF0:
    // 0x80242AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80242AF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80242AF8: jr          $ra
    // 0x80242AFC: nop

    return;
    // 0x80242AFC: nop

;}
RECOMP_FUNC void M12_FUN_80242b00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80242B04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80242B08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80242B0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80242B10: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80242B14: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242B18: jal         0x80010550
    // 0x80242B1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x80242B1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80242B20: jal         0x80133A24
    // 0x80242B24: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_1;
    // 0x80242B24: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x80242B28: beq         $v0, $zero, L_80242B9C
    if (ctx->r2 == 0) {
        // 0x80242B2C: lui         $t7, 0x8024
        ctx->r15 = S32(0X8024 << 16);
            goto L_80242B9C;
    }
    // 0x80242B2C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80242B30: addiu       $t7, $t7, 0x5DEC
    ctx->r15 = ADD32(ctx->r15, 0X5DEC);
    // 0x80242B34: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80242B38: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80242B3C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242B40: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80242B44: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80242B48: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80242B4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80242B50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80242B54: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80242B58: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80242B5C: jal         0x8012CE9C
    // 0x80242B60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_2;
    // 0x80242B60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x80242B64: bnel        $v0, $zero, L_80242BA0
    if (ctx->r2 != 0) {
        // 0x80242B68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80242BA0;
    }
    goto skip_0;
    // 0x80242B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80242B6C: jal         0x80133A24
    // 0x80242B70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_3;
    // 0x80242B70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x80242B74: beq         $v0, $zero, L_80242B9C
    if (ctx->r2 == 0) {
        // 0x80242B78: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80242B9C;
    }
    // 0x80242B78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80242B7C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80242B80: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80242B84: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80242B88: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242B8C: sh          $t1, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r9;
    // 0x80242B90: sh          $t3, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r11;
    // 0x80242B94: jal         0x800058DC
    // 0x80242B98: addiu       $a1, $a1, 0x2BAC
    ctx->r5 = ADD32(ctx->r5, 0X2BAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80242B98: addiu       $a1, $a1, 0x2BAC
    ctx->r5 = ADD32(ctx->r5, 0X2BAC);
    after_4:
L_80242B9C:
    // 0x80242B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80242BA0:
    // 0x80242BA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80242BA4: jr          $ra
    // 0x80242BA8: nop

    return;
    // 0x80242BA8: nop

;}
RECOMP_FUNC void M12_FUN_80242bac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242BAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80242BB0: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80242BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80242BB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80242BBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80242BC0: addiu       $t7, $t7, 0x5DF8
    ctx->r15 = ADD32(ctx->r15, 0X5DF8);
    // 0x80242BC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80242BC8: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80242BCC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80242BD0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80242BD4: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80242BD8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80242BDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242BE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80242BE4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80242BE8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80242BEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80242BF0: jal         0x8012CE9C
    // 0x80242BF4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x80242BF4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80242BF8: bne         $v0, $zero, L_80242C48
    if (ctx->r2 != 0) {
        // 0x80242BFC: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80242C48;
    }
    // 0x80242BFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242C00: jal         0x80010550
    // 0x80242C04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80242C04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80242C08: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80242C0C: lh          $v1, 0x94($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X94);
    // 0x80242C10: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80242C14: bne         $v1, $zero, L_80242C48
    if (ctx->r3 != 0) {
        // 0x80242C18: sh          $t1, 0x94($a1)
        MEM_H(0X94, ctx->r5) = ctx->r9;
            goto L_80242C48;
    }
    // 0x80242C18: sh          $t1, 0x94($a1)
    MEM_H(0X94, ctx->r5) = ctx->r9;
    // 0x80242C1C: jal         0x80133980
    // 0x80242C20: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_2;
    // 0x80242C20: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x80242C24: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80242C28: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80242C2C: addiu       $a0, $zero, 0x338
    ctx->r4 = ADD32(0, 0X338);
    // 0x80242C30: jal         0x80020744
    // 0x80242C34: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80242C34: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    after_3:
    // 0x80242C38: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242C3C: addiu       $a1, $a1, 0x2C58
    ctx->r5 = ADD32(ctx->r5, 0X2C58);
    // 0x80242C40: jal         0x800058DC
    // 0x80242C44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80242C44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_80242C48:
    // 0x80242C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80242C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80242C50: jr          $ra
    // 0x80242C54: nop

    return;
    // 0x80242C54: nop

;}
RECOMP_FUNC void M12_FUN_80242c58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242C58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80242C5C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80242C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80242C64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80242C68: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80242C6C: addiu       $t7, $t7, 0x5E04
    ctx->r15 = ADD32(ctx->r15, 0X5E04);
    // 0x80242C70: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80242C74: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80242C78: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80242C7C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80242C80: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80242C84: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80242C88: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80242C8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80242C90: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80242C94: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80242C98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80242C9C: jal         0x8012CE9C
    // 0x80242CA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x80242CA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80242CA4: bne         $v0, $zero, L_80242CE0
    if (ctx->r2 != 0) {
        // 0x80242CA8: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80242CE0;
    }
    // 0x80242CA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80242CAC: jal         0x80010550
    // 0x80242CB0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80242CB0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80242CB4: beql        $v0, $zero, L_80242CE4
    if (ctx->r2 == 0) {
        // 0x80242CB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80242CE4;
    }
    goto skip_0;
    // 0x80242CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80242CBC: jal         0x801270C0
    // 0x80242CC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x801270C0)(rdram, ctx);
        goto after_2;
    // 0x80242CC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80242CC4: beq         $v0, $zero, L_80242CE0
    if (ctx->r2 == 0) {
        // 0x80242CC8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80242CE0;
    }
    // 0x80242CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80242CCC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80242CD0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80242CD4: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x80242CD8: jal         0x801268CC
    // 0x80242CDC: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    LOOKUP_FUNC(0x801268CC)(rdram, ctx);
        goto after_3;
    // 0x80242CDC: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    after_3:
L_80242CE0:
    // 0x80242CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80242CE4:
    // 0x80242CE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80242CE8: jr          $ra
    // 0x80242CEC: nop

    return;
    // 0x80242CEC: nop

;}
RECOMP_FUNC void M12_FUN_80242cf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242CF0: jr          $ra
    // 0x80242CF4: nop

    return;
    // 0x80242CF4: nop

;}
RECOMP_FUNC void M12_FUN_80242cf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242CF8: nop

    // 0x80242CFC: nop

;}
RECOMP_FUNC void M12_FUN_80242d00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242D08: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80242D0C: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    // 0x80242D10: jal         0x801293C8
    // 0x80242D14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801293C8)(rdram, ctx);
        goto after_0;
    // 0x80242D14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80242D18: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80242D1C: lw          $t6, -0x2A2C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A2C);
    // 0x80242D20: lw          $a0, 0x64($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X64);
    // 0x80242D24: beql        $a0, $zero, L_80242D44
    if (ctx->r4 == 0) {
        // 0x80242D28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80242D44;
    }
    goto skip_0;
    // 0x80242D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80242D2C: jal         0x80005700
    // 0x80242D30: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80242D30: nop

    after_1:
    // 0x80242D34: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80242D38: lw          $t7, -0x2A2C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A2C);
    // 0x80242D3C: sw          $zero, 0x64($t7)
    MEM_W(0X64, ctx->r15) = 0;
    // 0x80242D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80242D44:
    // 0x80242D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80242D48: jr          $ra
    // 0x80242D4C: nop

    return;
    // 0x80242D4C: nop

;}
RECOMP_FUNC void M12_FUN_80242d50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242D58: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80242D5C: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    // 0x80242D60: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80242D64: jal         0x80129554
    // 0x80242D68: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80129554)(rdram, ctx);
        goto after_0;
    // 0x80242D68: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x80242D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80242D74: jr          $ra
    // 0x80242D78: nop

    return;
    // 0x80242D78: nop

;}
RECOMP_FUNC void M12_FUN_80242d7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242D7C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80242D80: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80242D84: lw          $t6, 0xE0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE0);
    // 0x80242D88: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80242D8C: lwc1        $f4, -0x64D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X64D0);
    // 0x80242D90: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80242D94: lui         $at, 0xC3A4
    ctx->r1 = S32(0XC3A4 << 16);
    // 0x80242D98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80242D9C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80242DA0: lw          $t8, 0xE0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE0);
    // 0x80242DA4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80242DA8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x80242DAC: jr          $ra
    // 0x80242DB0: sh          $zero, 0xB9A($v0)
    MEM_H(0XB9A, ctx->r2) = 0;
    return;
    // 0x80242DB0: sh          $zero, 0xB9A($v0)
    MEM_H(0XB9A, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80242db4(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80242db4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242DB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80242DB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80242DBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80242DC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80242DC4: jal         0x80133A24
    // 0x80242DC8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80242DC8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80242DCC: beq         $v0, $zero, L_80242DE4
    if (ctx->r2 == 0) {
        // 0x80242DD0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80242DE4;
    }
    // 0x80242DD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80242DD4: jal         0x80005700
    // 0x80242DD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80242DD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80242DDC: b           L_80242E38
    // 0x80242DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80242E38;
    // 0x80242DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80242DE4:
    // 0x80242DE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80242DE8: jal         0x80126CC0
    // 0x80242DEC: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_2;
    // 0x80242DEC: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    after_2:
    // 0x80242DF0: beql        $v0, $zero, L_80242E38
    if (ctx->r2 == 0) {
        // 0x80242DF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80242E38;
    }
    goto skip_0;
    // 0x80242DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80242DF8: jal         0x80126968
    // 0x80242DFC: nop

    LOOKUP_FUNC(0x80126968)(rdram, ctx);
        goto after_3;
    // 0x80242DFC: nop

    after_3:
    // 0x80242E00: jal         0x80020718
    // 0x80242E04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_4;
    // 0x80242E04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x80242E08: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80242E0C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80242E10: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80242E14: addiu       $t8, $t8, 0x2E44
    ctx->r24 = ADD32(ctx->r24, 0X2E44);
    // 0x80242E18: sh          $t6, 0xA8($t7)
    MEM_H(0XA8, ctx->r15) = ctx->r14;
    // 0x80242E1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80242E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80242E24: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x80242E28: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80242E2C: jal         0x8013B570
    // 0x80242E30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_5;
    // 0x80242E30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_5:
    // 0x80242E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80242E38:
    // 0x80242E38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80242E3C: jr          $ra
    // 0x80242E40: nop

    return;
    // 0x80242E40: nop

;}
RECOMP_FUNC void M12_FUN_80242e44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242E48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80242E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242E50: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242E54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80242E58: jal         0x80203830
    // 0x80242E5C: addiu       $a1, $a1, 0x5E78
    ctx->r5 = ADD32(ctx->r5, 0X5E78);
    LOOKUP_FUNC(0x80203830)(rdram, ctx);
        goto after_0;
    // 0x80242E5C: addiu       $a1, $a1, 0x5E78
    ctx->r5 = ADD32(ctx->r5, 0X5E78);
    after_0:
    // 0x80242E60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80242E64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80242E68: jal         0x8020394C
    // 0x80242E6C: sw          $t6, -0x3388($at)
    MEM_W(-0X3388, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x8020394C)(rdram, ctx);
        goto after_1;
    // 0x80242E6C: sw          $t6, -0x3388($at)
    MEM_W(-0X3388, ctx->r1) = ctx->r14;
    after_1:
    // 0x80242E70: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80242E74: addiu       $a1, $a1, 0x2E90
    ctx->r5 = ADD32(ctx->r5, 0X2E90);
    // 0x80242E78: jal         0x800058DC
    // 0x80242E7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80242E7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80242E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80242E88: jr          $ra
    // 0x80242E8C: nop

    return;
    // 0x80242E8C: nop

;}
RECOMP_FUNC void M12_FUN_80242e90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242E98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80242E9C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80242EA0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80242EA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80242EA8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80242EAC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80242EB0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80242EB4: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80242EB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80242EBC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80242EC0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80242EC4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80242EC8: nop

    // 0x80242ECC: sw          $t9, 0x1058($v0)
    MEM_W(0X1058, ctx->r2) = ctx->r25;
    // 0x80242ED0: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80242ED4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80242ED8: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80242EDC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80242EE0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80242EE4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80242EE8: nop

    // 0x80242EEC: sw          $t3, 0x105C($v0)
    MEM_W(0X105C, ctx->r2) = ctx->r11;
    // 0x80242EF0: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x80242EF4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x80242EF8: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80242EFC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80242F00: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80242F04: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80242F08: nop

    // 0x80242F0C: sw          $t7, 0x1060($v0)
    MEM_W(0X1060, ctx->r2) = ctx->r15;
    // 0x80242F10: lhu         $v1, 0xA8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA8);
    // 0x80242F14: beq         $v1, $zero, L_80242F38
    if (ctx->r3 == 0) {
        // 0x80242F18: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80242F38;
    }
    // 0x80242F18: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80242F1C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80242F20: bne         $t9, $zero, L_80242F38
    if (ctx->r25 != 0) {
        // 0x80242F24: sh          $t8, 0xA8($a0)
        MEM_H(0XA8, ctx->r4) = ctx->r24;
            goto L_80242F38;
    }
    // 0x80242F24: sh          $t8, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r24;
    // 0x80242F28: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80242F2C: jal         0x800208C4
    // 0x80242F30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x80242F30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80242F34: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80242F38:
    // 0x80242F38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80242F3C: jal         0x802039B0
    // 0x80242F40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x802039B0)(rdram, ctx);
        goto after_1;
    // 0x80242F40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80242F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80242F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80242F4C: jr          $ra
    // 0x80242F50: nop

    return;
    // 0x80242F50: nop

;}
RECOMP_FUNC void M12_FUN_80242f54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242F54: nop

    // 0x80242F58: nop

    // 0x80242F5C: nop

;}
RECOMP_FUNC void M12_FUN_80242f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242F60: lhu         $t6, 0x6($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6);
    // 0x80242F64: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80242F68: jr          $ra
    // 0x80242F6C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    return;
    // 0x80242F6C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80242f70(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80242f70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242F70: lhu         $t6, 0x6($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6);
    // 0x80242F74: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80242F78: jr          $ra
    // 0x80242F7C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    return;
    // 0x80242F7C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_80242f80(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_80242f80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80242F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80242F88: lbu         $t6, 0x95($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X95);
    // 0x80242F8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80242F90: bne         $t6, $at, L_80242FA8
    if (ctx->r14 != ctx->r1) {
        // 0x80242F94: nop
    
            goto L_80242FA8;
    }
    // 0x80242F94: nop

    // 0x80242F98: jal         0x80242F70
    // 0x80242F9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80242F70)(rdram, ctx);
        goto after_0;
    // 0x80242F9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80242FA0: b           L_80242FB4
    // 0x80242FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80242FB4;
    // 0x80242FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80242FA8:
    // 0x80242FA8: jal         0x80242F60
    // 0x80242FAC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80242F60)(rdram, ctx);
        goto after_1;
    // 0x80242FAC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80242FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80242FB4:
    // 0x80242FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80242FB8: jr          $ra
    // 0x80242FBC: nop

    return;
    // 0x80242FBC: nop

;}
RECOMP_FUNC void M12_FUN_80242fc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242FC0: jr          $ra
    // 0x80242FC4: nop

    return;
    // 0x80242FC4: nop

;}
RECOMP_FUNC void M12_FUN_80242fc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242FC8: jr          $ra
    // 0x80242FCC: nop

    return;
    // 0x80242FCC: nop

;}
RECOMP_FUNC void M12_FUN_80242fd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80242FD0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80242FD4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x80242FD8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80242FDC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80242FE0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80242FE4: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80242FE8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80242FEC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80242FF0: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80242FF4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80242FF8: nop

    // 0x80242FFC: bc1fl       L_80243014
    if (!c1cs) {
        // 0x80243000: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80243014;
    }
    goto skip_0;
    // 0x80243000: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x80243004: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80243008: b           L_80243014
    // 0x8024300C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80243014;
    // 0x8024300C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80243010: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_80243014:
    // 0x80243014: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80243018: nop

    // 0x8024301C: bc1fl       L_80243068
    if (!c1cs) {
        // 0x80243020: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80243068;
    }
    goto skip_1;
    // 0x80243020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80243024: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80243028: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8024302C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80243030: nop

    // 0x80243034: bc1fl       L_8024304C
    if (!c1cs) {
        // 0x80243038: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8024304C;
    }
    goto skip_2;
    // 0x80243038: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x8024303C: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80243040: b           L_8024304C
    // 0x80243044: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8024304C;
    // 0x80243044: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80243048: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_8024304C:
    // 0x8024304C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80243050: nop

    // 0x80243054: bc1fl       L_80243068
    if (!c1cs) {
        // 0x80243058: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80243068;
    }
    goto skip_3;
    // 0x80243058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8024305C: jr          $ra
    // 0x80243060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80243060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80243064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80243068:
    // 0x80243068: jr          $ra
    // 0x8024306C: nop

    return;
    // 0x8024306C: nop

;}
RECOMP_FUNC void M12_FUN_80243070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80243074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80243078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8024307C: jal         0x8001F74C
    // 0x80243080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80243080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80243084: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80243088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8024308C: jal         0x80126CC0
    // 0x80243090: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_1;
    // 0x80243090: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    after_1:
    // 0x80243094: beq         $v0, $zero, L_802430FC
    if (ctx->r2 == 0) {
        // 0x80243098: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_802430FC;
    }
    // 0x80243098: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8024309C: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x802430A0: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x802430A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802430A8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x802430AC: addiu       $t6, $t6, 0x310C
    ctx->r14 = ADD32(ctx->r14, 0X310C);
    // 0x802430B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x802430B4: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x802430B8: beq         $v1, $zero, L_802430D0
    if (ctx->r3 == 0) {
        // 0x802430BC: addiu       $a3, $zero, 0x4
        ctx->r7 = ADD32(0, 0X4);
            goto L_802430D0;
    }
    // 0x802430BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x802430C0: beq         $v1, $at, L_802430E4
    if (ctx->r3 == ctx->r1) {
        // 0x802430C4: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_802430E4;
    }
    // 0x802430C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x802430C8: b           L_80243100
    // 0x802430CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80243100;
    // 0x802430CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802430D0:
    // 0x802430D0: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x802430D4: jal         0x8013B570
    // 0x802430D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_2;
    // 0x802430D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x802430DC: b           L_80243100
    // 0x802430E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80243100;
    // 0x802430E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802430E4:
    // 0x802430E4: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x802430E8: addiu       $t7, $t7, 0x388C
    ctx->r15 = ADD32(ctx->r15, 0X388C);
    // 0x802430EC: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x802430F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x802430F4: jal         0x8013B570
    // 0x802430F8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_3;
    // 0x802430F8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_3:
L_802430FC:
    // 0x802430FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80243100:
    // 0x80243100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80243104: jr          $ra
    // 0x80243108: nop

    return;
    // 0x80243108: nop

;}
RECOMP_FUNC void M12_FUN_8024310c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024310C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80243110: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80243114: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80243118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8024311C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80243120: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80243124: sh          $zero, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = 0;
    // 0x80243128: sb          $zero, 0x90($a0)
    MEM_B(0X90, ctx->r4) = 0;
    // 0x8024312C: sb          $zero, 0x95($a0)
    MEM_B(0X95, ctx->r4) = 0;
    // 0x80243130: sb          $zero, 0x96($a0)
    MEM_B(0X96, ctx->r4) = 0;
    // 0x80243134: sb          $t0, 0x97($a0)
    MEM_B(0X97, ctx->r4) = ctx->r8;
    // 0x80243138: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
    // 0x8024313C: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80243140: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x80243144: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80243148: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8024314C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80243150: addiu       $t9, $t9, 0x6C64
    ctx->r25 = ADD32(ctx->r25, 0X6C64);
    // 0x80243154: lui         $t3, 0x1F
    ctx->r11 = S32(0X1F << 16);
    // 0x80243158: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8024315C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80243160: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80243164: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80243168: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8024316C: nop

    // 0x80243170: sh          $t8, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r24;
    // 0x80243174: sh          $t0, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r8;
    // 0x80243178: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8024317C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80243180: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80243184: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80243188: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8024318C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80243190: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x80243194: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80243198: jal         0x8013A1B4
    // 0x8024319C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_0;
    // 0x8024319C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x802431A0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802431A4: addiu       $a1, $a1, 0x31C4
    ctx->r5 = ADD32(ctx->r5, 0X31C4);
    // 0x802431A8: jal         0x800058DC
    // 0x802431AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x802431AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802431B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x802431B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802431B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x802431BC: jr          $ra
    // 0x802431C0: nop

    return;
    // 0x802431C0: nop

;}
RECOMP_FUNC void M12_FUN_802431c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802431C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x802431C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x802431CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x802431D0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x802431D4: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x802431D8: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x802431DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802431E0: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x802431E4: lbu         $v1, 0x94($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X94);
    // 0x802431E8: addiu       $a3, $zero, 0x65E
    ctx->r7 = ADD32(0, 0X65E);
    // 0x802431EC: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x802431F0: mfhi        $t7
    ctx->r15 = hi;
    // 0x802431F4: bnel        $t7, $zero, L_80243234
    if (ctx->r15 != 0) {
        // 0x802431F8: lbu         $t0, 0x90($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X90);
            goto L_80243234;
    }
    goto skip_0;
    // 0x802431F8: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    skip_0:
    // 0x802431FC: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80243200: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80243204: lwc1        $f4, -0x64C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X64C0);
    // 0x80243208: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8024320C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80243210: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80243214: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80243218: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8024321C: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80243220: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80243224: jal         0x80127430
    // 0x80243228: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80127430)(rdram, ctx);
        goto after_0;
    // 0x80243228: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8024322C: lbu         $v1, 0x94($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X94);
    // 0x80243230: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
L_80243234:
    // 0x80243234: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80243238: sb          $t9, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r25;
    // 0x8024323C: beql        $t0, $zero, L_80243260
    if (ctx->r8 == 0) {
        // 0x80243240: lw          $t4, 0x24($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X24);
            goto L_80243260;
    }
    goto skip_1;
    // 0x80243240: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x80243244: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80243248: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x8024324C: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x80243250: addiu       $t3, $t2, 0x1000
    ctx->r11 = ADD32(ctx->r10, 0X1000);
    // 0x80243254: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x80243258: sb          $zero, 0x90($s0)
    MEM_B(0X90, ctx->r16) = 0;
    // 0x8024325C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
L_80243260:
    // 0x80243260: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80243264: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80243268: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8024326C: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80243270: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80243274: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80243278: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8024327C: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80243280: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80243284: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80243288: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8024328C: lwc1        $f16, 0xC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80243290: jal         0x80010550
    // 0x80243294: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80243294: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80243298: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8024329C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x802432A0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x802432A4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x802432A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x802432AC: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x802432B0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x802432B4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x802432B8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x802432BC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x802432C0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x802432C4: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x802432C8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x802432CC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x802432D0: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x802432D4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x802432D8: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x802432DC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x802432E0: jal         0x801475C8
    // 0x802432E4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801475C8)(rdram, ctx);
        goto after_2;
    // 0x802432E4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x802432E8: lh          $t6, 0xA0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA0);
    // 0x802432EC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x802432F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x802432F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x802432F8: sh          $t7, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r15;
    // 0x802432FC: lh          $t8, 0xA0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA0);
    // 0x80243300: bgezl       $t8, L_80243310
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80243304: lwc1        $f8, 0x34($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80243310;
    }
    goto skip_2;
    // 0x80243304: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80243308: sh          $zero, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = 0;
    // 0x8024330C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
L_80243310:
    // 0x80243310: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80243314: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80243318: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8024331C: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x80243320: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80243324: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80243328: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8024332C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80243330: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80243334: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80243338: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8024333C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80243340: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80243344: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80243348: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8024334C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80243350: jal         0x8010843C
    // 0x80243354: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_3;
    // 0x80243354: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80243358: beq         $v0, $zero, L_802433A0
    if (ctx->r2 == 0) {
        // 0x8024335C: nop
    
            goto L_802433A0;
    }
    // 0x8024335C: nop

    // 0x80243360: sb          $zero, 0x96($s0)
    MEM_B(0X96, ctx->r16) = 0;
    // 0x80243364: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80243368: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8024336C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243370: sh          $v1, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r3;
    // 0x80243374: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80243378: addiu       $a1, $a1, 0x342C
    ctx->r5 = ADD32(ctx->r5, 0X342C);
    // 0x8024337C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80243380: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x80243384: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80243388: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8024338C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80243390: jal         0x800058DC
    // 0x80243394: sh          $t4, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80243394: sh          $t4, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r12;
    after_4:
    // 0x80243398: b           L_8024341C
    // 0x8024339C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8024341C;
    // 0x8024339C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802433A0:
    // 0x802433A0: jal         0x80242FD0
    // 0x802433A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80242FD0)(rdram, ctx);
        goto after_5;
    // 0x802433A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x802433A8: beql        $v0, $zero, L_8024341C
    if (ctx->r2 == 0) {
        // 0x802433AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8024341C;
    }
    goto skip_3;
    // 0x802433AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x802433B0: lh          $t5, 0xA0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA0);
    // 0x802433B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802433B8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802433BC: bnel        $t5, $zero, L_8024341C
    if (ctx->r13 != 0) {
        // 0x802433C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8024341C;
    }
    goto skip_4;
    // 0x802433C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x802433C4: jal         0x80242F80
    // 0x802433C8: addiu       $a1, $a1, 0x6C7C
    ctx->r5 = ADD32(ctx->r5, 0X6C7C);
    LOOKUP_FUNC(0x80242F80)(rdram, ctx);
        goto after_6;
    // 0x802433C8: addiu       $a1, $a1, 0x6C7C
    ctx->r5 = ADD32(ctx->r5, 0X6C7C);
    after_6:
    // 0x802433CC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x802433D0: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x802433D4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x802433D8: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x802433DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x802433E0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x802433E4: jal         0x8012C6B4
    // 0x802433E8: sh          $t9, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x802433E8: sh          $t9, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r25;
    after_7:
    // 0x802433EC: addiu       $t0, $v0, 0x3C
    ctx->r8 = ADD32(ctx->r2, 0X3C);
    // 0x802433F0: sb          $t0, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r8;
    // 0x802433F4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x802433F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x802433FC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243400: sh          $v1, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r3;
    // 0x80243404: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80243408: addiu       $a1, $a1, 0x3578
    ctx->r5 = ADD32(ctx->r5, 0X3578);
    // 0x8024340C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80243410: jal         0x800058DC
    // 0x80243414: sb          $v1, 0x76($t2)
    MEM_B(0X76, ctx->r10) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x80243414: sb          $v1, 0x76($t2)
    MEM_B(0X76, ctx->r10) = ctx->r3;
    after_8:
    // 0x80243418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8024341C:
    // 0x8024341C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80243420: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80243424: jr          $ra
    // 0x80243428: nop

    return;
    // 0x80243428: nop

;}
RECOMP_FUNC void M12_FUN_8024342c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024342C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80243430: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80243434: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80243438: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8024343C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80243440: addiu       $t6, $t6, 0x6C70
    ctx->r14 = ADD32(ctx->r14, 0X6C70);
    // 0x80243444: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80243448: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8024344C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80243450: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80243454: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80243458: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8024345C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80243460: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80243464: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80243468: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8024346C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243470: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80243474: jal         0x8012CE9C
    // 0x80243478: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x80243478: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8024347C: bne         $v0, $zero, L_80243564
    if (ctx->r2 != 0) {
        // 0x80243480: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80243564;
    }
    // 0x80243480: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80243484: lh          $v1, 0x98($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X98);
    // 0x80243488: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8024348C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80243490: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80243494: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x80243498: lh          $t1, 0x9C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X9C);
    // 0x8024349C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802434A0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x802434A4: subu        $t2, $t1, $v1
    ctx->r10 = SUB32(ctx->r9, ctx->r3);
    // 0x802434A8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x802434AC: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x802434B0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x802434B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802434B8: div.s       $f2, $f8, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x802434BC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x802434C0: div.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x802434C4: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x802434C8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x802434CC: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x802434D0: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x802434D4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x802434D8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x802434DC: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x802434E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802434E4: jal         0x80010550
    // 0x802434E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x802434E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x802434EC: beq         $v0, $zero, L_80243564
    if (ctx->r2 == 0) {
        // 0x802434F0: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_80243564;
    }
    // 0x802434F0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x802434F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802434F8: sh          $v0, 0x78($t4)
    MEM_H(0X78, ctx->r12) = ctx->r2;
    // 0x802434FC: lbu         $t5, 0x95($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X95);
    // 0x80243500: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80243504: addiu       $a0, $a0, 0x6C64
    ctx->r4 = ADD32(ctx->r4, 0X6C64);
    // 0x80243508: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x8024350C: sb          $t6, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r14;
    // 0x80243510: sb          $v0, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r2;
    // 0x80243514: jal         0x80242F70
    // 0x80243518: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    LOOKUP_FUNC(0x80242F70)(rdram, ctx);
        goto after_2;
    // 0x80243518: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    after_2:
    // 0x8024351C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80243520: addiu       $t7, $t7, 0x6C64
    ctx->r15 = ADD32(ctx->r15, 0X6C64);
    // 0x80243524: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80243528: lui         $t0, 0x1F
    ctx->r8 = S32(0X1F << 16);
    // 0x8024352C: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x80243530: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80243534: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x80243538: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8024353C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243540: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80243544: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x80243548: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8024354C: jal         0x8013A1B4
    // 0x80243550: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_3;
    // 0x80243550: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x80243554: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243558: addiu       $a1, $a1, 0x31C4
    ctx->r5 = ADD32(ctx->r5, 0X31C4);
    // 0x8024355C: jal         0x800058DC
    // 0x80243560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80243560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80243564:
    // 0x80243564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80243568: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8024356C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80243570: jr          $ra
    // 0x80243574: nop

    return;
    // 0x80243574: nop

;}
RECOMP_FUNC void M12_FUN_80243578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243578: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8024357C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80243580: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80243584: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80243588: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8024358C: addiu       $t6, $t6, 0x6C7C
    ctx->r14 = ADD32(ctx->r14, 0X6C7C);
    // 0x80243590: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80243594: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80243598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8024359C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x802435A0: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x802435A4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x802435A8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x802435AC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x802435B0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x802435B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x802435B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x802435BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802435C0: jal         0x8012CE9C
    // 0x802435C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x802435C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x802435C8: bnel        $v0, $zero, L_80243678
    if (ctx->r2 != 0) {
        // 0x802435CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80243678;
    }
    goto skip_0;
    // 0x802435CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x802435D0: lhu         $t0, 0x70($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X70);
    // 0x802435D4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x802435D8: bnel        $t0, $at, L_802435EC
    if (ctx->r8 != ctx->r1) {
        // 0x802435DC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_802435EC;
    }
    goto skip_1;
    // 0x802435DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x802435E0: jal         0x80020744
    // 0x802435E4: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x802435E4: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    after_1:
    // 0x802435E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_802435EC:
    // 0x802435EC: jal         0x80010550
    // 0x802435F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x802435F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x802435F4: beql        $v0, $zero, L_80243678
    if (ctx->r2 == 0) {
        // 0x802435F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80243678;
    }
    goto skip_2;
    // 0x802435F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x802435FC: lbu         $t1, 0x92($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X92);
    // 0x80243600: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80243604: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80243608: beq         $t3, $zero, L_8024361C
    if (ctx->r11 == 0) {
        // 0x8024360C: sb          $t2, 0x92($s0)
        MEM_B(0X92, ctx->r16) = ctx->r10;
            goto L_8024361C;
    }
    // 0x8024360C: sb          $t2, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r10;
    // 0x80243610: jal         0x80242FD0
    // 0x80243614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80242FD0)(rdram, ctx);
        goto after_3;
    // 0x80243614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80243618: bne         $v0, $zero, L_80243674
    if (ctx->r2 != 0) {
        // 0x8024361C: lui         $a1, 0x8024
        ctx->r5 = S32(0X8024 << 16);
            goto L_80243674;
    }
L_8024361C:
    // 0x8024361C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243620: addiu       $a1, $a1, 0x6C88
    ctx->r5 = ADD32(ctx->r5, 0X6C88);
    // 0x80243624: jal         0x80242F80
    // 0x80243628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80242F80)(rdram, ctx);
        goto after_4;
    // 0x80243628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8024362C: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x80243630: addiu       $t4, $t4, 0x6C88
    ctx->r12 = ADD32(ctx->r12, 0X6C88);
    // 0x80243634: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80243638: lui         $t7, 0x1F
    ctx->r15 = S32(0X1F << 16);
    // 0x8024363C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80243640: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80243644: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x80243648: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8024364C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243650: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80243654: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x80243658: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8024365C: jal         0x8013A1B4
    // 0x80243660: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_5;
    // 0x80243660: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_5:
    // 0x80243664: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243668: addiu       $a1, $a1, 0x3688
    ctx->r5 = ADD32(ctx->r5, 0X3688);
    // 0x8024366C: jal         0x800058DC
    // 0x80243670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80243670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80243674:
    // 0x80243674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80243678:
    // 0x80243678: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8024367C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80243680: jr          $ra
    // 0x80243684: nop

    return;
    // 0x80243684: nop

;}
RECOMP_FUNC void M12_FUN_80243688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243688: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8024368C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80243690: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80243694: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80243698: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x8024369C: ldc1        $f0, -0x64B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X64B8);
    // 0x802436A0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x802436A4: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x802436A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x802436AC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x802436B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x802436B4: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x802436B8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x802436BC: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x802436C0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x802436C4: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x802436C8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x802436CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802436D0: sub.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d - ctx->f0.d;
    // 0x802436D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x802436D8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x802436DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x802436E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x802436E4: jal         0x80010550
    // 0x802436E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x802436E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x802436EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x802436F0: beq         $v0, $zero, L_8024372C
    if (ctx->r2 == 0) {
        // 0x802436F4: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8024372C;
    }
    // 0x802436F4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x802436F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x802436FC: sh          $t8, 0x78($a3)
    MEM_H(0X78, ctx->r7) = ctx->r24;
    // 0x80243700: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80243704: sh          $t9, 0xA0($a2)
    MEM_H(0XA0, ctx->r6) = ctx->r25;
    // 0x80243708: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8024370C: addiu       $a1, $a1, 0x6C64
    ctx->r5 = ADD32(ctx->r5, 0X6C64);
    // 0x80243710: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80243714: jal         0x80242F80
    // 0x80243718: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80242F80)(rdram, ctx);
        goto after_1;
    // 0x80243718: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8024371C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243720: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80243724: jal         0x800058DC
    // 0x80243728: addiu       $a1, $a1, 0x373C
    ctx->r5 = ADD32(ctx->r5, 0X373C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80243728: addiu       $a1, $a1, 0x373C
    ctx->r5 = ADD32(ctx->r5, 0X373C);
    after_2:
L_8024372C:
    // 0x8024372C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80243730: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80243734: jr          $ra
    // 0x80243738: nop

    return;
    // 0x80243738: nop

;}
RECOMP_FUNC void M12_FUN_8024373c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024373C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80243740: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80243744: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80243748: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8024374C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80243750: lh          $t7, 0x9C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X9C);
    // 0x80243754: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80243758: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8024375C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80243760: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80243764: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80243768: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8024376C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80243770: ldc1        $f4, -0x64B0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X64B0);
    // 0x80243774: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80243778: addiu       $t9, $t9, 0x6C64
    ctx->r25 = ADD32(ctx->r25, 0X6C64);
    // 0x8024377C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80243780: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80243784: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80243788: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8024378C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80243790: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80243794: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80243798: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8024379C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x802437A0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x802437A4: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x802437A8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x802437AC: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x802437B0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x802437B4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x802437B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x802437BC: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x802437C0: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x802437C4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x802437C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x802437CC: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x802437D0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x802437D4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x802437D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802437DC: jal         0x8012CE9C
    // 0x802437E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x802437E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x802437E4: bne         $v0, $zero, L_80243878
    if (ctx->r2 != 0) {
        // 0x802437E8: lwc1        $f0, 0x28($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80243878;
    }
    // 0x802437E8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x802437EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x802437F0: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x802437F4: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x802437F8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x802437FC: addiu       $t3, $t3, 0x6C64
    ctx->r11 = ADD32(ctx->r11, 0X6C64);
    // 0x80243800: bc1fl       L_80243814
    if (!c1cs) {
        // 0x80243804: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80243814;
    }
    goto skip_0;
    // 0x80243804: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80243808: b           L_80243814
    // 0x8024380C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80243814;
    // 0x8024380C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80243810: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80243814:
    // 0x80243814: ldc1        $f4, -0x64A8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X64A8);
    // 0x80243818: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8024381C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80243820: nop

    // 0x80243824: bc1tl       L_8024387C
    if (c1cs) {
        // 0x80243828: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8024387C;
    }
    goto skip_1;
    // 0x80243828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8024382C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80243830: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x80243834: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80243838: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8024383C: lw          $a2, 0x4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X4);
    // 0x80243840: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80243844: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243848: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8024384C: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    // 0x80243850: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80243854: jal         0x8013A1B4
    // 0x80243858: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_1;
    // 0x80243858: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8024385C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243860: jal         0x80010550
    // 0x80243864: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x80243864: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80243868: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8024386C: addiu       $a1, $a1, 0x31C4
    ctx->r5 = ADD32(ctx->r5, 0X31C4);
    // 0x80243870: jal         0x800058DC
    // 0x80243874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80243874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80243878:
    // 0x80243878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8024387C:
    // 0x8024387C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80243880: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80243884: jr          $ra
    // 0x80243888: nop

    return;
    // 0x80243888: nop

;}
RECOMP_FUNC void M12_FUN_8024388c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024388C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80243890: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80243894: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80243898: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8024389C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x802438A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802438A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802438A8: jal         0x8012636C
    // 0x802438AC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_0;
    // 0x802438AC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x802438B0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x802438B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x802438B8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x802438BC: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    // 0x802438C0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x802438C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x802438C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x802438CC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x802438D0: addiu       $t1, $t1, -0x23D4
    ctx->r9 = ADD32(ctx->r9, -0X23D4);
    // 0x802438D4: lui         $t4, 0xE0
    ctx->r12 = S32(0XE0 << 16);
    // 0x802438D8: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    // 0x802438DC: sb          $zero, 0x94($s0)
    MEM_B(0X94, ctx->r16) = 0;
    // 0x802438E0: sb          $zero, 0x91($s0)
    MEM_B(0X91, ctx->r16) = 0;
    // 0x802438E4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x802438E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x802438EC: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x802438F0: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x802438F4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x802438F8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x802438FC: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x80243900: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80243904: jal         0x8013A1B4
    // 0x80243908: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_1;
    // 0x80243908: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8024390C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243910: addiu       $a1, $a1, 0x3930
    ctx->r5 = ADD32(ctx->r5, 0X3930);
    // 0x80243914: jal         0x800058DC
    // 0x80243918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80243918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8024391C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80243920: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80243924: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80243928: jr          $ra
    // 0x8024392C: nop

    return;
    // 0x8024392C: nop

;}
RECOMP_FUNC void M12_FUN_80243930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243930: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80243934: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80243938: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8024393C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80243940: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80243944: addiu       $t6, $t6, 0x6C94
    ctx->r14 = ADD32(ctx->r14, 0X6C94);
    // 0x80243948: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8024394C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80243950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80243954: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80243958: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x8024395C: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80243960: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80243964: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80243968: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8024396C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80243970: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243974: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80243978: jal         0x8012CE9C
    // 0x8024397C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x8024397C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x80243980: bne         $v0, $zero, L_80243A5C
    if (ctx->r2 != 0) {
        // 0x80243984: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80243A5C;
    }
    // 0x80243984: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243988: jal         0x80010550
    // 0x8024398C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x8024398C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80243990: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80243994: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80243998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8024399C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x802439A0: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x802439A4: addiu       $a3, $zero, 0x65F
    ctx->r7 = ADD32(0, 0X65F);
    // 0x802439A8: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x802439AC: lbu         $v1, 0x94($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X94);
    // 0x802439B0: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x802439B4: mfhi        $t2
    ctx->r10 = hi;
    // 0x802439B8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x802439BC: bnel        $t2, $at, L_802439FC
    if (ctx->r10 != ctx->r1) {
        // 0x802439C0: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_802439FC;
    }
    goto skip_0;
    // 0x802439C0: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x802439C4: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x802439C8: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x802439CC: lwc1        $f6, -0x64A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X64A0);
    // 0x802439D0: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x802439D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802439D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x802439DC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x802439E0: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x802439E4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x802439E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x802439EC: jal         0x80127430
    // 0x802439F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80127430)(rdram, ctx);
        goto after_2;
    // 0x802439F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x802439F4: lbu         $v1, 0x94($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X94);
    // 0x802439F8: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
L_802439FC:
    // 0x802439FC: sb          $t4, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r12;
    // 0x80243A00: jal         0x80242FD0
    // 0x80243A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80242FD0)(rdram, ctx);
        goto after_3;
    // 0x80243A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80243A08: beql        $v0, $zero, L_80243A60
    if (ctx->r2 == 0) {
        // 0x80243A0C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80243A60;
    }
    goto skip_1;
    // 0x80243A0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80243A10: jal         0x8012C6B4
    // 0x80243A14: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80243A14: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_4:
    // 0x80243A18: bnel        $v0, $zero, L_80243A60
    if (ctx->r2 != 0) {
        // 0x80243A1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80243A60;
    }
    goto skip_2;
    // 0x80243A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80243A20: jal         0x8012C6B4
    // 0x80243A24: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80243A24: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_5:
    // 0x80243A28: addiu       $t5, $v0, 0x3C
    ctx->r13 = ADD32(ctx->r2, 0X3C);
    // 0x80243A2C: sb          $t5, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r13;
    // 0x80243A30: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80243A34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80243A38: lui         $at, 0x8025
    ctx->r1 = S32(0X8025 << 16);
    // 0x80243A3C: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    // 0x80243A40: lwc1        $f10, -0x649C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X649C);
    // 0x80243A44: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80243A48: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243A4C: addiu       $a1, $a1, 0x3A70
    ctx->r5 = ADD32(ctx->r5, 0X3A70);
    // 0x80243A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80243A54: jal         0x800058DC
    // 0x80243A58: swc1        $f10, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->f10.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80243A58: swc1        $f10, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->f10.u32l;
    after_6:
L_80243A5C:
    // 0x80243A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80243A60:
    // 0x80243A60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80243A64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80243A68: jr          $ra
    // 0x80243A6C: nop

    return;
    // 0x80243A6C: nop

;}
RECOMP_FUNC void M12_FUN_80243a70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243A70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80243A74: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80243A78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80243A7C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80243A80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80243A84: addiu       $t6, $t6, 0x6CA0
    ctx->r14 = ADD32(ctx->r14, 0X6CA0);
    // 0x80243A88: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80243A8C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80243A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80243A94: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80243A98: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80243A9C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80243AA0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80243AA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80243AA8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80243AAC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80243AB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243AB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80243AB8: jal         0x8012CE9C
    // 0x80243ABC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x80243ABC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x80243AC0: bne         $v0, $zero, L_80243B5C
    if (ctx->r2 != 0) {
        // 0x80243AC4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80243B5C;
    }
    // 0x80243AC4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80243AC8: jal         0x80010550
    // 0x80243ACC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80243ACC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80243AD0: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80243AD4: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80243AD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80243ADC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80243AE0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80243AE4: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x80243AE8: lhu         $t2, 0x70($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X70);
    // 0x80243AEC: bnel        $t2, $at, L_80243B28
    if (ctx->r10 != ctx->r1) {
        // 0x80243AF0: lbu         $v1, 0x92($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X92);
            goto L_80243B28;
    }
    goto skip_0;
    // 0x80243AF0: lbu         $v1, 0x92($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X92);
    skip_0:
    // 0x80243AF4: lbu         $t3, 0x91($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X91);
    // 0x80243AF8: bne         $t3, $zero, L_80243B10
    if (ctx->r11 != 0) {
        // 0x80243AFC: nop
    
            goto L_80243B10;
    }
    // 0x80243AFC: nop

    // 0x80243B00: jal         0x80020744
    // 0x80243B04: addiu       $a0, $zero, 0x322
    ctx->r4 = ADD32(0, 0X322);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80243B04: addiu       $a0, $zero, 0x322
    ctx->r4 = ADD32(0, 0X322);
    after_2:
    // 0x80243B08: b           L_80243B1C
    // 0x80243B0C: lbu         $t4, 0x91($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X91);
        goto L_80243B1C;
    // 0x80243B0C: lbu         $t4, 0x91($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X91);
L_80243B10:
    // 0x80243B10: jal         0x80020744
    // 0x80243B14: addiu       $a0, $zero, 0x323
    ctx->r4 = ADD32(0, 0X323);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80243B14: addiu       $a0, $zero, 0x323
    ctx->r4 = ADD32(0, 0X323);
    after_3:
    // 0x80243B18: lbu         $t4, 0x91($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X91);
L_80243B1C:
    // 0x80243B1C: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x80243B20: sb          $t5, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r13;
    // 0x80243B24: lbu         $v1, 0x92($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X92);
L_80243B28:
    // 0x80243B28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80243B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80243B30: blez        $v1, L_80243B44
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80243B34: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80243B44;
    }
    // 0x80243B34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80243B38: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80243B3C: sb          $t6, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r14;
    // 0x80243B40: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
L_80243B44:
    // 0x80243B44: bne         $v0, $zero, L_80243B5C
    if (ctx->r2 != 0) {
        // 0x80243B48: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80243B5C;
    }
    // 0x80243B48: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80243B4C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243B50: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    // 0x80243B54: jal         0x800058DC
    // 0x80243B58: addiu       $a1, $a1, 0x3930
    ctx->r5 = ADD32(ctx->r5, 0X3930);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80243B58: addiu       $a1, $a1, 0x3930
    ctx->r5 = ADD32(ctx->r5, 0X3930);
    after_4:
L_80243B5C:
    // 0x80243B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80243B60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80243B64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80243B68: jr          $ra
    // 0x80243B6C: nop

    return;
    // 0x80243B6C: nop

;}
RECOMP_FUNC void M12_FUN_80243b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243B70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80243B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80243B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80243B7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80243B80: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80243B84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80243B88: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x80243B8C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80243B90: beq         $v0, $zero, L_80243BB8
    if (ctx->r2 == 0) {
        // 0x80243B94: nop
    
            goto L_80243BB8;
    }
    // 0x80243B94: nop

    // 0x80243B98: jal         0x80133A24
    // 0x80243B9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80243B9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x80243BA0: beq         $v0, $zero, L_80243BB8
    if (ctx->r2 == 0) {
        // 0x80243BA4: nop
    
            goto L_80243BB8;
    }
    // 0x80243BA4: nop

    // 0x80243BA8: jal         0x80005700
    // 0x80243BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80243BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80243BB0: b           L_80243C5C
    // 0x80243BB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80243C5C;
    // 0x80243BB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80243BB8:
    // 0x80243BB8: jal         0x8001F74C
    // 0x80243BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_2;
    // 0x80243BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80243BC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80243BC4: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x80243BC8: jal         0x80126CC0
    // 0x80243BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_3;
    // 0x80243BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80243BD0: beql        $v0, $zero, L_80243C5C
    if (ctx->r2 == 0) {
        // 0x80243BD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80243C5C;
    }
    goto skip_0;
    // 0x80243BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80243BD8: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80243BDC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80243BE0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80243BE4: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x80243BE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80243BEC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80243BF0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80243BF4: addiu       $a1, $a1, 0x3C6C
    ctx->r5 = ADD32(ctx->r5, 0X3C6C);
    // 0x80243BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80243BFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80243C00: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80243C04: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80243C08: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80243C0C: swc1        $f16, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f16.u32l;
    // 0x80243C10: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80243C14: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80243C18: nop

    // 0x80243C1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80243C20: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80243C24: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80243C28: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80243C2C: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
    // 0x80243C30: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x80243C34: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x80243C38: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80243C3C: nop

    // 0x80243C40: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80243C44: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80243C48: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x80243C4C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80243C50: jal         0x800058DC
    // 0x80243C54: swc1        $f8, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80243C54: swc1        $f8, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80243C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80243C5C:
    // 0x80243C5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80243C60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80243C64: jr          $ra
    // 0x80243C68: nop

    return;
    // 0x80243C68: nop

;}
RECOMP_FUNC void M12_FUN_80243c6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80243C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80243C70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80243C74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80243C78: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80243C7C: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80243C80: addiu       $a3, $zero, 0x660
    ctx->r7 = ADD32(0, 0X660);
    // 0x80243C84: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80243C88: mfhi        $t6
    ctx->r14 = hi;
    // 0x80243C8C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80243C90: bnel        $t6, $zero, L_80243CCC
    if (ctx->r14 != 0) {
        // 0x80243C94: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_80243CCC;
    }
    goto skip_0;
    // 0x80243C94: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80243C98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80243C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80243CA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80243CA4: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    // 0x80243CA8: lwc1        $f14, 0x94($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80243CAC: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x80243CB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80243CB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80243CB8: jal         0x80127430
    // 0x80243CBC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80127430)(rdram, ctx);
        goto after_0;
    // 0x80243CBC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80243CC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80243CC4: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80243CC8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
L_80243CCC:
    // 0x80243CCC: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x80243CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80243CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80243CD8: jr          $ra
    // 0x80243CDC: nop

    return;
    // 0x80243CDC: nop

;}
RECOMP_FUNC void M12_FUN_80243ce0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80243CE0u);
    return;
}
RECOMP_FUNC void M12_FUN_802445e8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802445E8u);
    return;
}
RECOMP_FUNC void M12_FUN_80244964(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80244964u);
    return;
}
RECOMP_FUNC void M12_FUN_80244e40(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80244E40u);
    return;
}
RECOMP_FUNC void M12_FUN_8024518c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8024518C: sra         $v1, $t2, 24
    ctx->r3 = S32(SIGNED(ctx->r10) >> 24);
    // 0x80245190: nop

    // 0x80245194: scd         $zero, -0x400($zero)
    SD(0, -0X400, 0);
    // 0x80245198: nop

    // 0x8024519C: sb          $s4, -0x5C11($fp)
    MEM_B(-0X5C11, ctx->r30) = ctx->r20;
    // 0x802451A0: sb          $at, -0x5C10($t5)
    MEM_B(-0X5C10, ctx->r13) = ctx->r1;
    // 0x802451A4: sb          $s2, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r18;
    // 0x802451A8: sb          $s0, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r16;
    // 0x802451AC: sb          $s2, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r18;
    // 0x802451B0: sb          $at, -0x5C1A($t5)
    MEM_B(-0X5C1A, ctx->r13) = ctx->r1;
    // 0x802451B4: sb          $t7, -0x5C0E($ra)
    MEM_B(-0X5C0E, ctx->r31) = ctx->r15;
    // 0x802451B8: sb          $at, -0x5C13($t5)
    MEM_B(-0X5C13, ctx->r13) = ctx->r1;
    // 0x802451BC: sb          $t7, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r15;
    // 0x802451C0: sb          $s3, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r19;
    // 0x802451C4: sb          $a1, -0x5C0E($ra)
    MEM_B(-0X5C0E, ctx->r31) = ctx->r5;
    // 0x802451C8: sb          $s3, -0xD00($ra)
    MEM_B(-0XD00, ctx->r31) = ctx->r19;
    // 0x802451CC: sb          $v0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r2;
    // 0x802451D0: sb          $a2, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r6;
    // 0x802451D4: sb          $s2, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r18;
    // 0x802451D8: sb          $at, -0x5C13($t5)
    MEM_B(-0X5C13, ctx->r13) = ctx->r1;
    // 0x802451DC: sb          $a1, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r5;
    // 0x802451E0: sb          $s4, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r20;
    // 0x802451E4: sb          $t4, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r12;
    // 0x802451E8: sb          $at, -0x5C1C($ra)
    MEM_B(-0X5C1C, ctx->r31) = ctx->r1;
    // 0x802451EC: sb          $t2, -0x5C0B($ra)
    MEM_B(-0X5C0B, ctx->r31) = ctx->r10;
    // 0x802451F0: sb          $s3, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r19;
    // 0x802451F4: sb          $t5, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r13;
    // 0x802451F8: sb          $t6, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r14;
    // 0x802451FC: sb          $s3, -0xD00($ra)
    MEM_B(-0XD00, ctx->r31) = ctx->r19;
    // 0x80245200: sb          $a1, -0x5C0D($ra)
    MEM_B(-0X5C0D, ctx->r31) = ctx->r5;
    // 0x80245204: sb          $v1, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r3;
    // 0x80245208: sb          $s0, -0x5C17($ra)
    MEM_B(-0X5C17, ctx->r31) = ctx->r16;
    // 0x8024520C: sb          $t6, -0x5C19($ra)
    MEM_B(-0X5C19, ctx->r31) = ctx->r14;
    // 0x80245210: sb          $a0, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r4;
    // 0x80245214: sb          $at, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r1;
    // 0x80245218: sb          $a3, -0x5C0B($ra)
    MEM_B(-0X5C0B, ctx->r31) = ctx->r7;
    // 0x8024521C: sb          $t6, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r14;
    // 0x80245220: sb          $s4, -0x5C18($ra)
    MEM_B(-0X5C18, ctx->r31) = ctx->r20;
    // 0x80245224: sb          $at, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r1;
    // 0x80245228: sb          $at, -0x5C09($t5)
    MEM_B(-0X5C09, ctx->r13) = ctx->r1;
    // 0x8024522C: sb          $t7, -0x5C0B($ra)
    MEM_B(-0X5C0B, ctx->r31) = ctx->r15;
    // 0x80245230: sb          $t4, -0x5C1C($ra)
    MEM_B(-0X5C1C, ctx->r31) = ctx->r12;
    // 0x80245234: scd         $zero, -0x5C12($t8)
    SD(0, -0X5C12, ctx->r24);
    // 0x80245238: sb          $t7, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r15;
    // 0x8024523C: sb          $at, -0x5C1F($t5)
    MEM_B(-0X5C1F, ctx->r13) = ctx->r1;
    // 0x80245240: sb          $a2, -0x5C1A($ra)
    MEM_B(-0X5C1A, ctx->r31) = ctx->r6;
    // 0x80245244: sb          $a1, -0x5C1D($ra)
    MEM_B(-0X5C1D, ctx->r31) = ctx->r5;
    // 0x80245248: sb          $s4, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r20;
    // 0x8024524C: sb          $s4, -0x5C18($ra)
    MEM_B(-0X5C18, ctx->r31) = ctx->r20;
    // 0x80245250: sb          $a1, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r5;
    // 0x80245254: sb          $a3, -0x5C0E($ra)
    MEM_B(-0X5C0E, ctx->r31) = ctx->r7;
    // 0x80245258: sb          $at, -0x5C0A($ra)
    MEM_B(-0X5C0A, ctx->r31) = ctx->r1;
    // 0x8024525C: sb          $t1, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r9;
    // 0x80245260: sb          $t9, -0x600($ra)
    MEM_B(-0X600, ctx->r31) = ctx->r25;
    // 0x80245264: nop

    // 0x80245268: scd         $zero, -0x700($zero)
    SD(0, -0X700, 0);
    // 0x8024526C: nop

    // 0x80245270: sb          $s3, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r19;
    // 0x80245274: sb          $at, -0x5C1E($ra)
    MEM_B(-0X5C1E, ctx->r31) = ctx->r1;
    // 0x80245278: sb          $t1, -0x5C14($ra)
    MEM_B(-0X5C14, ctx->r31) = ctx->r9;
    // 0x8024527C: sb          $t1, -0x5C06($ra)
    MEM_B(-0X5C06, ctx->r31) = ctx->r9;
    // 0x80245280: sb          $t1, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r9;
    // 0x80245284: sb          $a3, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r7;
    // 0x80245288: sb          $s0, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r16;
    // 0x8024528C: sb          $s2, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r18;
    // 0x80245290: sb          $t1, -0x5C1D($ra)
    MEM_B(-0X5C1D, ctx->r31) = ctx->r9;
    // 0x80245294: sb          $t4, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r12;
    // 0x80245298: sb          $s3, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r19;
    // 0x8024529C: sb          $t1, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r9;
    // 0x802452A0: sb          $at, -0x5C0C($t5)
    MEM_B(-0X5C0C, ctx->r13) = ctx->r1;
    // 0x802452A4: sb          $t0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r8;
    // 0x802452A8: scd         $zero, -0x700($zero)
    SD(0, -0X700, 0);
    // 0x802452AC: nop

    // 0x802452B0: sb          $s5, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r21;
    // 0x802452B4: sb          $a0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r4;
    // 0x802452B8: sb          $s2, -0x5C19($ra)
    MEM_B(-0X5C19, ctx->r31) = ctx->r18;
    // 0x802452BC: sb          $s2, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r18;
    // 0x802452C0: sb          $s5, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r21;
    // 0x802452C4: sb          $a0, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r4;
    // 0x802452C8: sb          $s3, -0x5C18($ra)
    MEM_B(-0X5C18, ctx->r31) = ctx->r19;
    // 0x802452CC: sb          $a1, -0x5C14($ra)
    MEM_B(-0X5C14, ctx->r31) = ctx->r5;
    // 0x802452D0: sb          $s4, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r20;
    // 0x802452D4: sb          $s2, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r18;
    // 0x802452D8: sb          $s7, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r23;
    // 0x802452DC: sb          $s3, -0x600($ra)
    MEM_B(-0X600, ctx->r31) = ctx->r19;
    // 0x802452E0: nop

    // 0x802452E4: scd         $zero, -0x700($zero)
    SD(0, -0X700, 0);
    // 0x802452E8: nop

    // 0x802452EC: sb          $a0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r4;
    // 0x802452F0: sb          $s6, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r22;
    // 0x802452F4: sb          $t4, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r12;
    // 0x802452F8: sb          $s0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r16;
    // 0x802452FC: sb          $a0, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r4;
    // 0x80245300: sb          $at, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r1;
    // 0x80245304: sb          $a0, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r4;
    // 0x80245308: sb          $a0, -0x5C17($ra)
    MEM_B(-0X5C17, ctx->r31) = ctx->r4;
    // 0x8024530C: sb          $s3, -0x5C10($ra)
    MEM_B(-0X5C10, ctx->r31) = ctx->r19;
    // 0x80245310: sb          $t7, -0x5C0D($ra)
    MEM_B(-0X5C0D, ctx->r31) = ctx->r15;
    // 0x80245314: sb          $a1, -0x5C1C($ra)
    MEM_B(-0X5C1C, ctx->r31) = ctx->r5;
    // 0x80245318: scd         $zero, -0x700($zero)
    SD(0, -0X700, 0);
    // 0x8024531C: nop

    // 0x80245320: sb          $s4, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r20;
    // 0x80245324: sb          $at, -0x5C1E($t5)
    MEM_B(-0X5C1E, ctx->r13) = ctx->r1;
    // 0x80245328: sb          $s2, -0x5C17($ra)
    MEM_B(-0X5C17, ctx->r31) = ctx->r18;
    // 0x8024532C: sb          $t6, -0x5C19($ra)
    MEM_B(-0X5C19, ctx->r31) = ctx->r14;
    // 0x80245330: sb          $at, -0x5C0C($t5)
    MEM_B(-0X5C0C, ctx->r13) = ctx->r1;
    // 0x80245334: sb          $t0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r8;
    // 0x80245338: sb          $t5, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r13;
    // 0x8024533C: sb          $s5, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r21;
    // 0x80245340: sb          $a0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r4;
    // 0x80245344: sb          $s2, -0x700($ra)
    MEM_B(-0X700, ctx->r31) = ctx->r18;
    // 0x80245348: nop

    // 0x8024534C: sb          $v1, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r3;
    // 0x80245350: sb          $t6, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r14;
    // 0x80245354: sb          $s2, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r18;
    // 0x80245358: sb          $t4, -0x5E5B($ra)
    MEM_B(-0X5E5B, ctx->r31) = ctx->r12;
    // 0x8024535C: sb          $a1, -0x5E5B($t5)
    MEM_B(-0X5E5B, ctx->r13) = ctx->r5;
    // 0x80245360: scd         $zero, -0x600($zero)
    SD(0, -0X600, 0);
    // 0x80245364: nop

    // 0x80245368: scd         $zero, -0x800($zero)
    SD(0, -0X800, 0);
    // 0x8024536C: nop

    // 0x80245370: sb          $s5, -0x5C12($fp)
    MEM_B(-0X5C12, ctx->r30) = ctx->r21;
    // 0x80245374: sb          $a2, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r6;
    // 0x80245378: sb          $s2, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r18;
    // 0x8024537C: sb          $s5, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r21;
    // 0x80245380: sb          $at, -0x5C0C($ra)
    MEM_B(-0X5C0C, ctx->r31) = ctx->r1;
    // 0x80245384: sb          $a1, -0x5C14($ra)
    MEM_B(-0X5C14, ctx->r31) = ctx->r5;
    // 0x80245388: sb          $t9, -0x5E5C($ra)
    MEM_B(-0X5E5C, ctx->r31) = ctx->r25;
    // 0x8024538C: sb          $at, -0x5C0C($t5)
    MEM_B(-0X5C0C, ctx->r13) = ctx->r1;
    // 0x80245390: sb          $t0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r8;
    // 0x80245394: sb          $s2, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r18;
    // 0x80245398: sb          $at, -0x5C1F($t5)
    MEM_B(-0X5C1F, ctx->r13) = ctx->r1;
    // 0x8024539C: sb          $s2, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r18;
    // 0x802453A0: sb          $at, -0x5C12($t5)
    MEM_B(-0X5C12, ctx->r13) = ctx->r1;
    // 0x802453A4: sb          $t7, -0xD00($ra)
    MEM_B(-0XD00, ctx->r31) = ctx->r15;
    // 0x802453A8: sb          $s3, -0x5C0B($ra)
    MEM_B(-0X5C0B, ctx->r31) = ctx->r19;
    // 0x802453AC: sb          $v1, -0x5C18($ra)
    MEM_B(-0X5C18, ctx->r31) = ctx->r3;
    // 0x802453B0: sb          $at, -0x5C19($t5)
    MEM_B(-0X5C19, ctx->r13) = ctx->r1;
    // 0x802453B4: sb          $s5, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r21;
    // 0x802453B8: sb          $s3, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r19;
    // 0x802453BC: sb          $t1, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r9;
    // 0x802453C0: sb          $at, -0x5C0C($t5)
    MEM_B(-0X5C0C, ctx->r13) = ctx->r1;
    // 0x802453C4: sb          $t0, -0x5C17($ra)
    MEM_B(-0X5C17, ctx->r31) = ctx->r8;
    // 0x802453C8: sb          $s3, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r19;
    // 0x802453CC: sb          $v0, -0x5C14($ra)
    MEM_B(-0X5C14, ctx->r31) = ctx->r2;
    // 0x802453D0: sb          $t7, -0x5C1D($ra)
    MEM_B(-0X5C1D, ctx->r31) = ctx->r15;
    // 0x802453D4: sb          $t3, -0x5E5B($ra)
    MEM_B(-0X5E5B, ctx->r31) = ctx->r11;
    // 0x802453D8: sb          $a1, -0x5E5B($t5)
    MEM_B(-0X5E5B, ctx->r13) = ctx->r5;
    // 0x802453DC: scd         $zero, -0x600($zero)
    SD(0, -0X600, 0);
    // 0x802453E0: nop

    // 0x802453E4: scd         $zero, -0x5C3F($t8)
    SD(0, -0X5C3F, ctx->r24);
    // 0x802453E8: sb          $at, -0x5C1C($t5)
    MEM_B(-0X5C1C, ctx->r13) = ctx->r1;
    // 0x802453EC: sb          $a1, -0x5C1A($ra)
    MEM_B(-0X5C1A, ctx->r31) = ctx->r5;
    // 0x802453F0: sb          $s5, -0x5C0D($ra)
    MEM_B(-0X5C0D, ctx->r31) = ctx->r21;
    // 0x802453F4: sb          $a1, -0x5C0E($ra)
    MEM_B(-0X5C0E, ctx->r31) = ctx->r5;
    // 0x802453F8: sb          $at, -0x5C0C($t5)
    MEM_B(-0X5C0C, ctx->r13) = ctx->r1;
    // 0x802453FC: sb          $t7, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r15;
    // 0x80245400: sb          $a3, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r7;
    // 0x80245404: sb          $s4, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r20;
    // 0x80245408: sb          $s2, -0x5C17($ra)
    MEM_B(-0X5C17, ctx->r31) = ctx->r18;
    // 0x8024540C: sb          $a0, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r4;
    // 0x80245410: sb          $t7, -0x5C1A($ra)
    MEM_B(-0X5C1A, ctx->r31) = ctx->r15;
    // 0x80245414: sb          $at, -0x5C0C($t5)
    MEM_B(-0X5C0C, ctx->r13) = ctx->r1;
    // 0x80245418: sb          $t0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r8;
    // 0x8024541C: scd         $zero, -0x5C0D($t8)
    SD(0, -0X5C0D, ctx->r24);
    // 0x80245420: sb          $s5, -0x5C0E($ra)
    MEM_B(-0X5C0E, ctx->r31) = ctx->r21;
    // 0x80245424: sb          $s6, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r22;
    // 0x80245428: sb          $t1, -0x5C14($ra)
    MEM_B(-0X5C14, ctx->r31) = ctx->r9;
    // 0x8024542C: sb          $t4, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r12;
    // 0x80245430: sb          $t6, -0x5C1D($ra)
    MEM_B(-0X5C1D, ctx->r31) = ctx->r14;
    // 0x80245434: sb          $a1, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r5;
    // 0x80245438: sb          $a0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r4;
    // 0x8024543C: sb          $s6, -0x5C17($ra)
    MEM_B(-0X5C17, ctx->r31) = ctx->r22;
    // 0x80245440: sb          $v1, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r3;
    // 0x80245444: sb          $s3, -0x5E5F($ra)
    MEM_B(-0X5E5F, ctx->r31) = ctx->r19;
    // 0x80245448: sb          $t0, -0x5C1F($ra)
    MEM_B(-0X5C1F, ctx->r31) = ctx->r8;
    // 0x8024544C: sb          $s3, -0x700($ra)
    MEM_B(-0X700, ctx->r31) = ctx->r19;
    // 0x80245450: nop

    // 0x80245454: sb          $v0, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r2;
    // 0x80245458: sb          $a1, -0x5C12($ra)
    MEM_B(-0X5C12, ctx->r31) = ctx->r5;
    // 0x8024545C: sb          $at, -0x5C1A($t5)
    MEM_B(-0X5C1A, ctx->r13) = ctx->r1;
    // 0x80245460: sb          $t7, -0x5C0B($ra)
    MEM_B(-0X5C0B, ctx->r31) = ctx->r15;
    // 0x80245464: sb          $t6, -0x5C1C($ra)
    MEM_B(-0X5C1C, ctx->r31) = ctx->r14;
    // 0x80245468: sb          $at, -0x5C1F($t5)
    MEM_B(-0X5C1F, ctx->r13) = ctx->r1;
    // 0x8024546C: sb          $t6, -0x5C1C($ra)
    MEM_B(-0X5C1C, ctx->r31) = ctx->r14;
    // 0x80245470: sb          $at, -0x5C1C($t5)
    MEM_B(-0X5C1C, ctx->r13) = ctx->r1;
    // 0x80245474: sb          $t1, -0x5C0D($ra)
    MEM_B(-0X5C0D, ctx->r31) = ctx->r9;
    // 0x80245478: sb          $s0, -0x5C11($ra)
    MEM_B(-0X5C11, ctx->r31) = ctx->r16;
    // 0x8024547C: sb          $s3, -0x5C1B($ra)
    MEM_B(-0X5C1B, ctx->r31) = ctx->r19;
    // 0x80245480: sb          $a0, -0x5E5B($ra)
    MEM_B(-0X5E5B, ctx->r31) = ctx->r4;
    // 0x80245484: scd         $zero, -0x600($zero)
    SD(0, -0X600, 0);
    // 0x80245488: nop

    // 0x8024548C: scd         $zero, -0x300($zero)
    SD(0, -0X300, 0);
    // 0x80245490: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // 0x80245494: sra         $v1, $t2, 24
    ctx->r3 = S32(SIGNED(ctx->r10) >> 24);
    // 0x80245498: sra         $zero, $at, 24
    // write to $zero
    // 0x8024549C: nop

    // 0x802454A0: scd         $zero, -0x400($zero)
    SD(0, -0X400, 0);
    // 0x802454A4: nop

    // 0x802454A8: sb          $t5, -0x5E5B($fp)
    MEM_B(-0X5E5B, ctx->r30) = ctx->r13;
    // 0x802454AC: sb          $a1, -0x5E5B($t5)
    MEM_B(-0X5E5B, ctx->r13) = ctx->r5;
    // 0x802454B0: sb          $t5, -0x5C0E($fp)
    MEM_B(-0X5C0E, ctx->r30) = ctx->r13;
    // 0x802454B4: sb          $a1, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r5;
    // 0x802454B8: sb          $a0, -0x5C17($fp)
    MEM_B(-0X5C17, ctx->r30) = ctx->r4;
    // 0x802454BC: sb          $at, -0x5C06($ra)
    MEM_B(-0X5C06, ctx->r31) = ctx->r1;
    // 0x802454C0: sb          $t2, -0x5E57($t5)
    MEM_B(-0X5E57, ctx->r13) = ctx->r10;
    // 0x802454C4: scd         $zero, -0x600($zero)
    SD(0, -0X600, 0);
    // 0x802454C8: nop

    // 0x802454CC: scd         $zero, -0x300($zero)
    SD(0, -0X300, 0);
    // 0x802454D0: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M12_FUN_802454d4(rdram, ctx);
;}
RECOMP_FUNC void M12_FUN_802454d4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802454D4u);
    return;
}
RECOMP_FUNC void M55_FUN_803757e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803757E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803757E4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803757E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803757EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803757F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803757F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803757F8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x803757FC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80375800: sltiu       $at, $a2, 0x5
    ctx->r1 = ctx->r6 < 0X5 ? 1 : 0;
    // 0x80375804: andi        $s0, $a3, 0xFF
    ctx->r16 = ctx->r7 & 0XFF;
    // 0x80375808: beq         $at, $zero, L_80375888
    if (ctx->r1 == 0) {
        // 0x8037580C: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80375888;
    }
    // 0x8037580C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80375810: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80375814: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80375818: addu        $at, $at, $t7
    gpr jr_addend_80375820 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8037581C: lw          $t7, -0x6F14($at)
    ctx->r15 = ADD32(ctx->r1, -0X6F14);
    // 0x80375820: jr          $t7
    // 0x80375824: nop

    switch (jr_addend_80375820 >> 2) {
        case 0: goto L_80375888; break;
        case 1: goto L_80375828; break;
        case 2: goto L_80375850; break;
        case 3: goto L_8037583C; break;
        case 4: goto L_8037586C; break;
        default: switch_error(__func__, 0x80375820, 0x803890EC);
    }
    // 0x80375824: nop

L_80375828:
    // 0x80375828: andi        $s0, $s0, 0xF
    ctx->r16 = ctx->r16 & 0XF;
    // 0x8037582C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80375830: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80375834: b           L_803758A0
    // 0x80375838: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
        goto L_803758A0;
    // 0x80375838: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
L_8037583C:
    // 0x8037583C: andi        $s0, $s0, 0xF
    ctx->r16 = ctx->r16 & 0XF;
    // 0x80375840: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80375844: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80375848: b           L_803758A0
    // 0x8037584C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
        goto L_803758A0;
    // 0x8037584C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
L_80375850:
    // 0x80375850: andi        $s0, $s0, 0xF0
    ctx->r16 = ctx->r16 & 0XF0;
    // 0x80375854: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80375858: sra         $s0, $s0, 4
    ctx->r16 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8037585C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80375860: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80375864: b           L_803758A0
    // 0x80375868: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
        goto L_803758A0;
    // 0x80375868: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
L_8037586C:
    // 0x8037586C: andi        $s0, $s0, 0xF0
    ctx->r16 = ctx->r16 & 0XF0;
    // 0x80375870: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80375874: sra         $s0, $s0, 4
    ctx->r16 = S32(SIGNED(ctx->r16) >> 4);
    // 0x80375878: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037587C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80375880: b           L_803758A0
    // 0x80375884: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
        goto L_803758A0;
    // 0x80375884: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
L_80375888:
    // 0x80375888: andi        $s0, $s0, 0xF0
    ctx->r16 = ctx->r16 & 0XF0;
    // 0x8037588C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80375890: sra         $s0, $s0, 4
    ctx->r16 = S32(SIGNED(ctx->r16) >> 4);
    // 0x80375894: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80375898: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8037589C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
L_803758A0:
    // 0x803758A0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x803758A4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x803758A8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x803758AC: lhu         $v0, 0xE($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XE);
    // 0x803758B0: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x803758B4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x803758B8: beq         $v0, $at, L_803758EC
    if (ctx->r2 == ctx->r1) {
        // 0x803758BC: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_803758EC;
    }
    // 0x803758BC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x803758C0: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x803758C4: beq         $v0, $at, L_80375938
    if (ctx->r2 == ctx->r1) {
        // 0x803758C8: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80375938;
    }
    // 0x803758C8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x803758CC: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x803758D0: beq         $v0, $at, L_80375990
    if (ctx->r2 == ctx->r1) {
        // 0x803758D4: sll         $t3, $v1, 5
        ctx->r11 = S32(ctx->r3 << 5);
            goto L_80375990;
    }
    // 0x803758D4: sll         $t3, $v1, 5
    ctx->r11 = S32(ctx->r3 << 5);
    // 0x803758D8: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x803758DC: beql        $v0, $at, L_80375994
    if (ctx->r2 == ctx->r1) {
        // 0x803758E0: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_80375994;
    }
    goto skip_0;
    // 0x803758E0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    skip_0:
    // 0x803758E4: b           L_80375994
    // 0x803758E8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
        goto L_80375994;
    // 0x803758E8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
L_803758EC:
    // 0x803758EC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x803758F0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x803758F4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x803758F8: lw          $t3, -0x78D8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X78D8);
    // 0x803758FC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80375900: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80375904: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80375908: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8037590C: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x80375910: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80375914: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80375918: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8037591C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80375920: jal         0x8012CE9C
    // 0x80375924: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x80375924: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x80375928: beql        $v0, $zero, L_803759E4
    if (ctx->r2 == 0) {
        // 0x8037592C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_803759E4;
    }
    goto skip_1;
    // 0x8037592C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80375930: b           L_803759F0
    // 0x80375934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_803759F0;
    // 0x80375934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80375938:
    // 0x80375938: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8037593C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80375940: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80375944: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80375948: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037594C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80375950: lw          $t9, -0x7968($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7968);
    // 0x80375954: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80375958: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037595C: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80375960: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x80375964: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80375968: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037596C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80375970: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x80375974: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80375978: jal         0x8012CE9C
    // 0x8037597C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_1;
    // 0x8037597C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x80375980: beql        $v0, $zero, L_803759E4
    if (ctx->r2 == 0) {
        // 0x80375984: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_803759E4;
    }
    goto skip_2;
    // 0x80375984: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80375988: b           L_803759F0
    // 0x8037598C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_803759F0;
    // 0x8037598C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80375990:
    // 0x80375990: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
L_80375994:
    // 0x80375994: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80375998: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037599C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x803759A0: lw          $t6, -0x7A28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7A28);
    // 0x803759A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x803759A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x803759AC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x803759B0: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x803759B4: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x803759B8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x803759BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x803759C0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803759C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x803759C8: jal         0x8012CE9C
    // 0x803759CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_2;
    // 0x803759CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x803759D0: beql        $v0, $zero, L_803759E4
    if (ctx->r2 == 0) {
        // 0x803759D4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_803759E4;
    }
    goto skip_3;
    // 0x803759D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x803759D8: b           L_803759F0
    // 0x803759DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_803759F0;
    // 0x803759DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x803759E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_803759E4:
    // 0x803759E4: jal         0x80010550
    // 0x803759E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x803759E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x803759EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803759F0:
    // 0x803759F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803759F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803759F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x803759FC: jr          $ra
    // 0x80375A00: nop

    return;
    // 0x80375A00: nop

;}
RECOMP_FUNC void M55_FUN_80375a04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375A04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80375A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375A0C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80375A10: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80375A14: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80375A18: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80375A1C: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80375A20: lw          $t7, 0xE0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XE0);
    // 0x80375A24: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80375A28: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80375A2C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80375A30: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80375A34: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80375A38: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80375A3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80375A40: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80375A44: jal         0x8001EF38
    // 0x80375A48: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x80375A48: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80375A4C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80375A50: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80375A54: lw          $t9, 0xE0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XE0);
    // 0x80375A58: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80375A5C: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80375A60: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80375A64: lhu         $t3, 0xE($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XE);
    // 0x80375A68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80375A6C: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x80375A70: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80375A74: subu        $a3, $t1, $v0
    ctx->r7 = SUB32(ctx->r9, ctx->r2);
    // 0x80375A78: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80375A7C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80375A80: andi        $a3, $a3, 0x1FFF
    ctx->r7 = ctx->r7 & 0X1FFF;
    // 0x80375A84: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80375A88: bne         $t3, $at, L_80375AF0
    if (ctx->r11 != ctx->r1) {
        // 0x80375A8C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_80375AF0;
    }
    // 0x80375A8C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80375A90: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80375A94: jal         0x8012A630
    // 0x80375A98: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_1;
    // 0x80375A98: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_1:
    // 0x80375A9C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80375AA0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80375AA4: beq         $v0, $zero, L_80375B58
    if (ctx->r2 == 0) {
        // 0x80375AA8: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_80375B58;
    }
    // 0x80375AA8: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80375AAC: lbu         $t4, 0xEF4($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XEF4);
    // 0x80375AB0: slti        $at, $a3, 0x801
    ctx->r1 = SIGNED(ctx->r7) < 0X801 ? 1 : 0;
    // 0x80375AB4: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80375AB8: andi        $v1, $t5, 0xFF
    ctx->r3 = ctx->r13 & 0XFF;
    // 0x80375ABC: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x80375AC0: beq         $t6, $zero, L_80375B58
    if (ctx->r14 == 0) {
        // 0x80375AC4: sb          $t5, 0xEF4($a2)
        MEM_B(0XEF4, ctx->r6) = ctx->r13;
            goto L_80375B58;
    }
    // 0x80375AC4: sb          $t5, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r13;
    // 0x80375AC8: bne         $at, $zero, L_80375AE8
    if (ctx->r1 != 0) {
        // 0x80375ACC: andi        $t8, $v1, 0xFFFE
        ctx->r24 = ctx->r3 & 0XFFFE;
            goto L_80375AE8;
    }
    // 0x80375ACC: andi        $t8, $v1, 0xFFFE
    ctx->r24 = ctx->r3 & 0XFFFE;
    // 0x80375AD0: slti        $at, $a3, 0x1800
    ctx->r1 = SIGNED(ctx->r7) < 0X1800 ? 1 : 0;
    // 0x80375AD4: beq         $at, $zero, L_80375AE8
    if (ctx->r1 == 0) {
        // 0x80375AD8: andi        $t7, $v1, 0xFFFE
        ctx->r15 = ctx->r3 & 0XFFFE;
            goto L_80375AE8;
    }
    // 0x80375AD8: andi        $t7, $v1, 0xFFFE
    ctx->r15 = ctx->r3 & 0XFFFE;
    // 0x80375ADC: sb          $t7, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r15;
    // 0x80375AE0: b           L_80375B5C
    // 0x80375AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80375B5C;
    // 0x80375AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80375AE8:
    // 0x80375AE8: b           L_80375B58
    // 0x80375AEC: sb          $t8, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r24;
        goto L_80375B58;
    // 0x80375AEC: sb          $t8, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r24;
L_80375AF0:
    // 0x80375AF0: jal         0x8012A630
    // 0x80375AF4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_2;
    // 0x80375AF4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x80375AF8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80375AFC: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80375B00: beq         $v0, $zero, L_80375B4C
    if (ctx->r2 == 0) {
        // 0x80375B04: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_80375B4C;
    }
    // 0x80375B04: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80375B08: lbu         $t9, 0xEF4($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XEF4);
    // 0x80375B0C: slti        $at, $a3, 0x801
    ctx->r1 = SIGNED(ctx->r7) < 0X801 ? 1 : 0;
    // 0x80375B10: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80375B14: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x80375B18: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x80375B1C: beq         $t1, $zero, L_80375B58
    if (ctx->r9 == 0) {
        // 0x80375B20: sb          $t0, 0xEF4($a2)
        MEM_B(0XEF4, ctx->r6) = ctx->r8;
            goto L_80375B58;
    }
    // 0x80375B20: sb          $t0, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r8;
    // 0x80375B24: bne         $at, $zero, L_80375B44
    if (ctx->r1 != 0) {
        // 0x80375B28: andi        $t3, $v1, 0xFFFE
        ctx->r11 = ctx->r3 & 0XFFFE;
            goto L_80375B44;
    }
    // 0x80375B28: andi        $t3, $v1, 0xFFFE
    ctx->r11 = ctx->r3 & 0XFFFE;
    // 0x80375B2C: slti        $at, $a3, 0x1800
    ctx->r1 = SIGNED(ctx->r7) < 0X1800 ? 1 : 0;
    // 0x80375B30: beq         $at, $zero, L_80375B44
    if (ctx->r1 == 0) {
        // 0x80375B34: andi        $t2, $v1, 0xFFFE
        ctx->r10 = ctx->r3 & 0XFFFE;
            goto L_80375B44;
    }
    // 0x80375B34: andi        $t2, $v1, 0xFFFE
    ctx->r10 = ctx->r3 & 0XFFFE;
    // 0x80375B38: sb          $t2, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r10;
    // 0x80375B3C: b           L_80375B5C
    // 0x80375B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80375B5C;
    // 0x80375B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80375B44:
    // 0x80375B44: b           L_80375B58
    // 0x80375B48: sb          $t3, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r11;
        goto L_80375B58;
    // 0x80375B48: sb          $t3, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r11;
L_80375B4C:
    // 0x80375B4C: lbu         $t4, 0xEF4($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XEF4);
    // 0x80375B50: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80375B54: sb          $t5, 0xEF4($a2)
    MEM_B(0XEF4, ctx->r6) = ctx->r13;
L_80375B58:
    // 0x80375B58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80375B5C:
    // 0x80375B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80375B60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80375B64: jr          $ra
    // 0x80375B68: nop

    return;
    // 0x80375B68: nop

;}
RECOMP_FUNC void M55_FUN_80375b6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375B6C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80375B70: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x80375B74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80375B78: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80375B7C: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x80375B80: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80375B84: andi        $s4, $a1, 0xFF
    ctx->r20 = ctx->r5 & 0XFF;
    // 0x80375B88: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x80375B8C: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x80375B90: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x80375B94: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80375B98: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x80375B9C: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x80375BA0: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x80375BA4: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x80375BA8: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80375BAC: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80375BB0: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x80375BB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80375BB8: jal         0x8012C6B4
    // 0x80375BBC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80375BBC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x80375BC0: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x80375BC4: addiu       $s6, $s6, -0x4410
    ctx->r22 = ADD32(ctx->r22, -0X4410);
    // 0x80375BC8: lw          $t7, 0xE0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0XE0);
    // 0x80375BCC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80375BD0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80375BD4: lw          $a1, 0x2C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X2C);
    // 0x80375BD8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x80375BDC: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x80375BE0: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80375BE4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80375BE8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80375BEC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80375BF0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80375BF4: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80375BF8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80375BFC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80375C00: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80375C04: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80375C08: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80375C0C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80375C10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80375C14: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80375C18: jal         0x8002FC20
    // 0x80375C1C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x80375C1C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80375C20: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80375C24: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80375C28: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80375C2C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80375C30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80375C34: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80375C38: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80375C3C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80375C40: bc1f        L_80375C50
    if (!c1cs) {
        // 0x80375C44: nop
    
            goto L_80375C50;
    }
    // 0x80375C44: nop

    // 0x80375C48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80375C4C: nop

L_80375C50:
    // 0x80375C50: jal         0x8012C6B4
    // 0x80375C54: swc1        $f2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80375C54: swc1        $f2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80375C58: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80375C5C: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80375C60: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80375C64: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80375C68: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x80375C6C: lui         $s5, 0x8039
    ctx->r21 = S32(0X8039 << 16);
    // 0x80375C70: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x80375C74: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80375C78: addiu       $s5, $s5, -0x70A0
    ctx->r21 = ADD32(ctx->r21, -0X70A0);
    // 0x80375C7C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80375C80: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80375C84: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
L_80375C88:
    // 0x80375C88: beql        $s3, $zero, L_80375DC8
    if (ctx->r19 == 0) {
        // 0x80375C8C: lw          $t4, 0xE0($s6)
        ctx->r12 = MEM_W(ctx->r22, 0XE0);
            goto L_80375DC8;
    }
    goto skip_0;
    // 0x80375C8C: lw          $t4, 0xE0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0XE0);
    skip_0:
    // 0x80375C90: bnel        $s3, $s4, L_80375DC8
    if (ctx->r19 != ctx->r20) {
        // 0x80375C94: lw          $t4, 0xE0($s6)
        ctx->r12 = MEM_W(ctx->r22, 0XE0);
            goto L_80375DC8;
    }
    goto skip_1;
    // 0x80375C94: lw          $t4, 0xE0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0XE0);
    skip_1:
    // 0x80375C98: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80375C9C: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80375CA0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80375CA4: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80375CA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80375CAC: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80375CB0: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x80375CB4: lwc1        $f20, 0x4($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80375CB8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80375CBC: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x80375CC0: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x80375CC4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80375CC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80375CCC: lwc1        $f24, 0xC($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80375CD0: jal         0x8001EAD0
    // 0x80375CD4: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80375CD4: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
    after_3:
    // 0x80375CD8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80375CDC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80375CE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80375CE4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80375CE8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80375CEC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80375CF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80375CF4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80375CF8: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80375CFC: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80375D00: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x80375D04: add.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d + ctx->f18.d;
    // 0x80375D08: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
    // 0x80375D0C: cvt.s.d     $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f28.fl = CVT_S_D(ctx->f6.d);
    // 0x80375D10: swc1        $f26, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f26.u32l;
    // 0x80375D14: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80375D18: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80375D1C: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    // 0x80375D20: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x80375D24: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80375D28: jal         0x8001EB64
    // 0x80375D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x80375D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x80375D30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80375D34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80375D38: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80375D3C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80375D40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80375D44: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80375D48: cvt.d.s     $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f4.d = CVT_D_S(ctx->f24.fl);
    // 0x80375D4C: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80375D50: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80375D54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80375D58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80375D5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80375D60: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80375D64: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80375D68: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80375D6C: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80375D70: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80375D74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80375D78: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80375D7C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80375D80: addiu       $a1, $zero, 0x170
    ctx->r5 = ADD32(0, 0X170);
    // 0x80375D84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80375D88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80375D8C: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    // 0x80375D90: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80375D94: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x80375D98: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x80375D9C: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x80375DA0: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80375DA4: swc1        $f24, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f24.u32l;
    // 0x80375DA8: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80375DAC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80375DB0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80375DB4: jal         0x8011AAF4
    // 0x80375DB8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_5;
    // 0x80375DB8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80375DBC: b           L_80375E98
    // 0x80375DC0: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
        goto L_80375E98;
    // 0x80375DC0: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80375DC4: lw          $t4, 0xE0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0XE0);
L_80375DC8:
    // 0x80375DC8: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80375DCC: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80375DD0: lw          $a1, 0x2C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X2C);
    // 0x80375DD4: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x80375DD8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80375DDC: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80375DE0: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80375DE4: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80375DE8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80375DEC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80375DF0: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80375DF4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80375DF8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80375DFC: mul.d       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f30.d);
    // 0x80375E00: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80375E04: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80375E08: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80375E0C: mul.d       $f8, $f4, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f30.d);
    // 0x80375E10: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80375E14: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x80375E18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80375E1C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80375E20: nop

    // 0x80375E24: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80375E28: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80375E2C: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    // 0x80375E30: mul.d       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f30.d);
    // 0x80375E34: jal         0x8001EAD0
    // 0x80375E38: cvt.s.d     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f24.fl = CVT_S_D(ctx->f10.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x80375E38: cvt.s.d     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f24.fl = CVT_S_D(ctx->f10.d);
    after_6:
    // 0x80375E3C: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80375E40: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80375E44: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80375E48: jal         0x8012C6B4
    // 0x80375E4C: add.s       $f28, $f18, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f28.fl = ctx->f18.fl + ctx->f20.fl;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80375E4C: add.s       $f28, $f18, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f28.fl = ctx->f18.fl + ctx->f20.fl;
    after_7:
    // 0x80375E50: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80375E54: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80375E58: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80375E5C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80375E60: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80375E64: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80375E68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80375E6C: add.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80375E70: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80375E74: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x80375E78: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80375E7C: jal         0x8001EB64
    // 0x80375E80: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x80375E80: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80375E84: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80375E88: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80375E8C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80375E90: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x80375E94: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
L_80375E98:
    // 0x80375E98: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80375E9C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80375EA0: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80375EA4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80375EA8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80375EAC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80375EB0: jal         0x8010843C
    // 0x80375EB4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_9;
    // 0x80375EB4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80375EB8: bne         $v0, $zero, L_80375F3C
    if (ctx->r2 != 0) {
        // 0x80375EBC: addiu       $s1, $s1, 0x200
        ctx->r17 = ADD32(ctx->r17, 0X200);
            goto L_80375F3C;
    }
    // 0x80375EBC: addiu       $s1, $s1, 0x200
    ctx->r17 = ADD32(ctx->r17, 0X200);
    // 0x80375EC0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80375EC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80375EC8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80375ECC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80375ED0: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80375ED4: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80375ED8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80375EDC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80375EE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80375EE4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80375EE8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80375EEC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80375EF0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80375EF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80375EF8: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    // 0x80375EFC: addiu       $a1, $zero, 0x181
    ctx->r5 = ADD32(0, 0X181);
    // 0x80375F00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80375F04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80375F08: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x80375F0C: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x80375F10: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80375F14: swc1        $f24, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f24.u32l;
    // 0x80375F18: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80375F1C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80375F20: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80375F24: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80375F28: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80375F2C: jal         0x8011AAF4
    // 0x80375F30: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_10;
    // 0x80375F30: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80375F34: b           L_80375F58
    // 0x80375F38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80375F58;
    // 0x80375F38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80375F3C:
    // 0x80375F3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80375F40: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80375F44: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x80375F48: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80375F4C: bne         $at, $zero, L_80375C88
    if (ctx->r1 != 0) {
        // 0x80375F50: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_80375C88;
    }
    // 0x80375F50: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80375F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80375F58:
    // 0x80375F58: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x80375F5C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80375F60: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80375F64: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x80375F68: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x80375F6C: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x80375F70: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x80375F74: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80375F78: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80375F7C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x80375F80: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x80375F84: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x80375F88: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x80375F8C: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x80375F90: jr          $ra
    // 0x80375F94: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80375F94: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80375f98(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80375f98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375F98: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80375F9C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80375FA0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80375FA4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80375FA8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80375FAC: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x80375FB0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80375FB4: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80375FB8: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80375FBC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80375FC0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80375FC4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80375FC8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80375FCC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80375FD0: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80375FD4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80375FD8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80375FDC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80375FE0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80375FE4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80375FE8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80375FEC: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80375FF0: jal         0x8002FC20
    // 0x80375FF4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80375FF4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80375FF8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80375FFC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80376000: lw          $t0, 0xE0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE0);
    // 0x80376004: lw          $t9, 0xE8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8);
    // 0x80376008: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8037600C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80376010: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x80376014: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80376018: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8037601C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80376020: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80376024: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80376028: lwc1        $f14, 0x38($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8037602C: add.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d + ctx->f10.d;
    // 0x80376030: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80376034: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80376038: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8037603C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80376040: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80376044: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80376048: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037604C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80376050: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x80376054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80376058: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8037605C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80376060: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80376064: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80376068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037606C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80376070: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80376074: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80376078: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8037607C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80376080: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80376084: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80376088: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8037608C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80376090: addiu       $a0, $a0, -0x7020
    ctx->r4 = ADD32(ctx->r4, -0X7020);
    // 0x80376094: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80376098: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8037609C: addiu       $a1, $zero, 0x1A2
    ctx->r5 = ADD32(0, 0X1A2);
    // 0x803760A0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x803760A4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x803760A8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x803760AC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x803760B0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x803760B4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x803760B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x803760BC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x803760C0: jal         0x8011AAF4
    // 0x803760C4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x803760C4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x803760C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x803760CC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x803760D0: jr          $ra
    // 0x803760D4: nop

    return;
    // 0x803760D4: nop

;}
RECOMP_FUNC void M55_FUN_803760d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803760D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803760DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803760E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803760E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803760E8: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x803760EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803760F0: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x803760F4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x803760F8: beq         $v0, $zero, L_80376120
    if (ctx->r2 == 0) {
        // 0x803760FC: nop
    
            goto L_80376120;
    }
    // 0x803760FC: nop

    // 0x80376100: jal         0x80133A24
    // 0x80376104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80376104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x80376108: beq         $v0, $zero, L_80376120
    if (ctx->r2 == 0) {
        // 0x8037610C: nop
    
            goto L_80376120;
    }
    // 0x8037610C: nop

    // 0x80376110: jal         0x80005700
    // 0x80376114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80376114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80376118: b           L_80376150
    // 0x8037611C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80376150;
    // 0x8037611C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80376120:
    // 0x80376120: jal         0x8001F74C
    // 0x80376124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_2;
    // 0x80376124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80376128: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8037612C: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x80376130: jal         0x80126CC0
    // 0x80376134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_3;
    // 0x80376134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80376138: beq         $v0, $zero, L_8037614C
    if (ctx->r2 == 0) {
        // 0x8037613C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037614C;
    }
    // 0x8037613C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376140: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376144: jal         0x800058DC
    // 0x80376148: addiu       $a1, $a1, 0x6160
    ctx->r5 = ADD32(ctx->r5, 0X6160);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80376148: addiu       $a1, $a1, 0x6160
    ctx->r5 = ADD32(ctx->r5, 0X6160);
    after_4:
L_8037614C:
    // 0x8037614C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80376150:
    // 0x80376150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80376154: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376158: jr          $ra
    // 0x8037615C: nop

    return;
    // 0x8037615C: nop

;}
RECOMP_FUNC void M55_FUN_80376160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80376164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376168: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037616C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80376170: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80376174: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80376178: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8037617C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80376180: addiu       $t6, $t6, -0x1A50
    ctx->r14 = ADD32(ctx->r14, -0X1A50);
    // 0x80376184: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x80376188: beq         $v0, $zero, L_803761A8
    if (ctx->r2 == 0) {
        // 0x8037618C: addiu       $t7, $t7, -0x1944
        ctx->r15 = ADD32(ctx->r15, -0X1944);
            goto L_803761A8;
    }
    // 0x8037618C: addiu       $t7, $t7, -0x1944
    ctx->r15 = ADD32(ctx->r15, -0X1944);
    // 0x80376190: beq         $v0, $at, L_803761A8
    if (ctx->r2 == ctx->r1) {
        // 0x80376194: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_803761A8;
    }
    // 0x80376194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80376198: beq         $v0, $at, L_803761A8
    if (ctx->r2 == ctx->r1) {
        // 0x8037619C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_803761A8;
    }
    // 0x8037619C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x803761A0: bnel        $v0, $at, L_8037620C
    if (ctx->r2 != ctx->r1) {
        // 0x803761A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037620C;
    }
    goto skip_0;
    // 0x803761A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_803761A8:
    // 0x803761A8: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x803761AC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x803761B0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x803761B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803761B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x803761BC: srl         $t9, $t8, 24
    ctx->r25 = S32(U32(ctx->r24) >> 24);
    // 0x803761C0: bne         $t9, $at, L_803761F4
    if (ctx->r25 != ctx->r1) {
        // 0x803761C4: addiu       $a3, $zero, 0x4
        ctx->r7 = ADD32(0, 0X4);
            goto L_803761F4;
    }
    // 0x803761C4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x803761C8: lui         $t0, 0x8037
    ctx->r8 = S32(0X8037 << 16);
    // 0x803761CC: addiu       $t0, $t0, 0x6218
    ctx->r8 = ADD32(ctx->r8, 0X6218);
    // 0x803761D0: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x803761D4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x803761D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x803761DC: jal         0x8013B570
    // 0x803761E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x803761E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x803761E4: jal         0x80126968
    // 0x803761E8: nop

    LOOKUP_FUNC(0x80126968)(rdram, ctx);
        goto after_1;
    // 0x803761E8: nop

    after_1:
    // 0x803761EC: b           L_8037620C
    // 0x803761F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037620C;
    // 0x803761F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803761F4:
    // 0x803761F4: lui         $t1, 0x8037
    ctx->r9 = S32(0X8037 << 16);
    // 0x803761F8: addiu       $t1, $t1, 0x6218
    ctx->r9 = ADD32(ctx->r9, 0X6218);
    // 0x803761FC: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x80376200: jal         0x8013B570
    // 0x80376204: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_2;
    // 0x80376204: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_2:
    // 0x80376208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037620C:
    // 0x8037620C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376210: jr          $ra
    // 0x80376214: nop

    return;
    // 0x80376214: nop

;}
RECOMP_FUNC void M55_FUN_80376218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037621C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80376224: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80376228: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8037622C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80376230: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80376234: jal         0x80010550
    // 0x80376238: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x80376238: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8037623C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376240: jal         0x8012636C
    // 0x80376244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_1;
    // 0x80376244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80376248: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8037624C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80376250: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80376254: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    // 0x80376258: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x8037625C: ori         $t9, $t8, 0xC00
    ctx->r25 = ctx->r24 | 0XC00;
    // 0x80376260: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80376264: lw          $v0, 0x201C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X201C);
    // 0x80376268: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8037626C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80376270: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x80376274: jal         0x8000522C
    // 0x80376278: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_2;
    // 0x80376278: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    after_2:
    // 0x8037627C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80376280: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80376284: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376288: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x8037628C: addiu       $a1, $a1, 0x62E0
    ctx->r5 = ADD32(ctx->r5, 0X62E0);
    // 0x80376290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376294: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80376298: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x8037629C: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x803762A0: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x803762A4: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x803762A8: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    // 0x803762AC: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x803762B0: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x803762B4: swc1        $f8, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f8.u32l;
    // 0x803762B8: lw          $t5, 0x2C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2C);
    // 0x803762BC: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x803762C0: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x803762C4: jal         0x800058DC
    // 0x803762C8: sh          $t6, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x803762C8: sh          $t6, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r14;
    after_3:
    // 0x803762CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803762D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803762D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803762D8: jr          $ra
    // 0x803762DC: nop

    return;
    // 0x803762DC: nop

;}
RECOMP_FUNC void M55_FUN_803762e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803762E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803762E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803762E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803762EC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x803762F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803762F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x803762F8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x803762FC: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80376300(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80376300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376300: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x80376304: srl         $a3, $a3, 8
    ctx->r7 = S32(U32(ctx->r7) >> 8);
    // 0x80376308: jal         0x803757E0
    // 0x8037630C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_0;
    // 0x8037630C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80376310: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80376314: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80376318: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x8037631C: srl         $t9, $v1, 24
    ctx->r25 = S32(U32(ctx->r3) >> 24);
    // 0x80376320: beq         $t9, $at, L_80376438
    if (ctx->r25 == ctx->r1) {
        // 0x80376324: srl         $t0, $v1, 16
        ctx->r8 = S32(U32(ctx->r3) >> 16);
            goto L_80376438;
    }
    // 0x80376324: srl         $t0, $v1, 16
    ctx->r8 = S32(U32(ctx->r3) >> 16);
    // 0x80376328: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8037632C: beql        $t1, $zero, L_8037638C
    if (ctx->r9 == 0) {
        // 0x80376330: lw          $t6, 0x38($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X38);
            goto L_8037638C;
    }
    goto skip_0;
    // 0x80376330: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80376334: jal         0x801C3B3C
    // 0x80376338: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_1;
    // 0x80376338: nop

    after_1:
    // 0x8037633C: bnel        $v0, $zero, L_8037638C
    if (ctx->r2 != 0) {
        // 0x80376340: lw          $t6, 0x38($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X38);
            goto L_8037638C;
    }
    goto skip_1;
    // 0x80376340: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x80376344: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80376348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037634C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376350: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80376354: srl         $t4, $t3, 16
    ctx->r12 = S32(U32(ctx->r11) >> 16);
    // 0x80376358: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8037635C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80376360: bgez        $t5, L_80376374
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80376364: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80376374;
    }
    // 0x80376364: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80376368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037636C: nop

    // 0x80376370: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80376374:
    // 0x80376374: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80376378: jal         0x8012A630
    // 0x8037637C: nop

    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_2;
    // 0x8037637C: nop

    after_2:
    // 0x80376380: bne         $v0, $zero, L_803763AC
    if (ctx->r2 != 0) {
        // 0x80376384: nop
    
            goto L_803763AC;
    }
    // 0x80376384: nop

    // 0x80376388: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
L_8037638C:
    // 0x8037638C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80376390: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x80376394: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80376398: bnel        $t9, $zero, L_8037643C
    if (ctx->r25 != 0) {
        // 0x8037639C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037643C;
    }
    goto skip_2;
    // 0x8037639C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803763A0: jal         0x80375A04
    // 0x803763A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80375A04)(rdram, ctx);
        goto after_3;
    // 0x803763A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x803763A8: beq         $v0, $zero, L_80376438
    if (ctx->r2 == 0) {
        // 0x803763AC: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80376438;
    }
L_803763AC:
    // 0x803763AC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803763B0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803763B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x803763B8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x803763BC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x803763C0: sh          $a2, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r6;
    // 0x803763C4: sh          $t0, 0x190($v0)
    MEM_H(0X190, ctx->r2) = ctx->r8;
    // 0x803763C8: sh          $t1, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r9;
    // 0x803763CC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x803763D0: lw          $v1, 0xE0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE0);
    // 0x803763D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x803763D8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x803763DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x803763E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x803763E4: lwc1        $f8, 0x4($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X4);
    // 0x803763E8: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x803763EC: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803763F0: swc1        $f8, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->f8.u32l;
    // 0x803763F4: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x803763F8: addiu       $a1, $a1, 0x644C
    ctx->r5 = ADD32(ctx->r5, 0X644C);
    // 0x803763FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376400: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x80376404: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80376408: swc1        $f10, 0xF18($v0)
    MEM_W(0XF18, ctx->r2) = ctx->f10.u32l;
    // 0x8037640C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80376410: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80376414: swc1        $f16, 0x198($v0)
    MEM_W(0X198, ctx->r2) = ctx->f16.u32l;
    // 0x80376418: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8037641C: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80376420: sh          $t8, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r24;
    // 0x80376424: swc1        $f0, 0xF04($v0)
    MEM_W(0XF04, ctx->r2) = ctx->f0.u32l;
    // 0x80376428: swc1        $f0, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f0.u32l;
    // 0x8037642C: swc1        $f18, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->f18.u32l;
    // 0x80376430: jal         0x800058DC
    // 0x80376434: sh          $a2, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80376434: sh          $a2, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r6;
    after_4:
L_80376438:
    // 0x80376438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037643C:
    // 0x8037643C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80376440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80376444: jr          $ra
    // 0x80376448: nop

    return;
    // 0x80376448: nop

;}
