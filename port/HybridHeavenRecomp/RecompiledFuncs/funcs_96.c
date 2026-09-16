#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_80225540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80225544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80225548: jal         0x80225450
    // 0x8022554C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80225450)(rdram, ctx);
        goto after_0;
    // 0x8022554C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80225550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80225554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80225558: jr          $ra
    // 0x8022555C: nop

    return;
    // 0x8022555C: nop

;}
RECOMP_FUNC void M10_FUN_80225560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225560: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80225564: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80225568: slti        $at, $a1, 0x26
    ctx->r1 = SIGNED(ctx->r5) < 0X26 ? 1 : 0;
    // 0x8022556C: bne         $at, $zero, L_80225578
    if (ctx->r1 != 0) {
        // 0x80225570: lw          $v1, 0x5C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X5C);
            goto L_80225578;
    }
    // 0x80225570: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x80225574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80225578:
    // 0x80225578: lbu         $t6, 0x75($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X75);
    // 0x8022557C: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80225580: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80225584: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80225588: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8022558C: lw          $t8, -0x3730($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3730);
    // 0x80225590: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80225594: jr          $ra
    // 0x80225598: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    return;
    // 0x80225598: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022559c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022559c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022559C: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x802255A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x802255A4: addiu       $a2, $a2, -0x3730
    ctx->r6 = ADD32(ctx->r6, -0X3730);
    // 0x802255A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802255AC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_802255B0:
    // 0x802255B0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x802255B4: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x802255B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x802255BC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
L_802255C0:
    // 0x802255C0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x802255C4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x802255C8: bnel        $a1, $t0, L_802255DC
    if (ctx->r5 != ctx->r8) {
        // 0x802255CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_802255DC;
    }
    goto skip_0;
    // 0x802255CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x802255D0: jr          $ra
    // 0x802255D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x802255D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x802255D8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_802255DC:
    // 0x802255DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x802255E0: slti        $at, $a0, 0x26
    ctx->r1 = SIGNED(ctx->r4) < 0X26 ? 1 : 0;
    // 0x802255E4: bnel        $at, $zero, L_802255C0
    if (ctx->r1 != 0) {
        // 0x802255E8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_802255C0;
    }
    goto skip_1;
    // 0x802255E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    skip_1:
    // 0x802255EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x802255F0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x802255F4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x802255F8: bnel        $at, $zero, L_802255B0
    if (ctx->r1 != 0) {
        // 0x802255FC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_802255B0;
    }
    goto skip_2;
    // 0x802255FC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_2:
    // 0x80225600: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80225604: jr          $ra
    // 0x80225608: nop

    return;
    // 0x80225608: nop

;}
RECOMP_FUNC void M10_FUN_8022560c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022560C: lbu         $t6, 0x75($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X75);
    // 0x80225610: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80225614: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80225618: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8022561C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80225620: lw          $v0, -0x3730($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3730);
    // 0x80225624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80225628: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_8022562C:
    // 0x8022562C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80225630: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80225634: bnel        $v1, $t0, L_80225648
    if (ctx->r3 != ctx->r8) {
        // 0x80225638: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80225648;
    }
    goto skip_0;
    // 0x80225638: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x8022563C: jr          $ra
    // 0x80225640: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80225640: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80225644: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80225648:
    // 0x80225648: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8022564C: slti        $at, $a1, 0x26
    ctx->r1 = SIGNED(ctx->r5) < 0X26 ? 1 : 0;
    // 0x80225650: bnel        $at, $zero, L_8022562C
    if (ctx->r1 != 0) {
        // 0x80225654: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_8022562C;
    }
    goto skip_1;
    // 0x80225654: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_1:
    // 0x80225658: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8022565C: jr          $ra
    // 0x80225660: nop

    return;
    // 0x80225660: nop

;}
RECOMP_FUNC void M10_FUN_80225664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225664: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80225668: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022566c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022566c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022566C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80225670: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80225674: bne         $a1, $t6, L_80225688
    if (ctx->r5 != ctx->r14) {
        // 0x80225678: addiu       $t1, $sp, 0x0
        ctx->r9 = ADD32(ctx->r29, 0X0);
            goto L_80225688;
    }
    // 0x80225678: addiu       $t1, $sp, 0x0
    ctx->r9 = ADD32(ctx->r29, 0X0);
    // 0x8022567C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80225680: b           L_8022568C
    // 0x80225684: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_8022568C;
    // 0x80225684: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80225688:
    // 0x80225688: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_8022568C:
    // 0x8022568C: sw          $a2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r6;
    // 0x80225690: sh          $zero, 0x4($sp)
    MEM_H(0X4, ctx->r29) = 0;
    // 0x80225694: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80225698: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x8022569C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802256A0: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x802256A4: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x802256A8: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x802256AC: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x802256B0: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x802256B4: bnel        $t9, $at, L_802256C4
    if (ctx->r25 != ctx->r1) {
        // 0x802256B8: lw          $t3, 0x0($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X0);
            goto L_802256C4;
    }
    goto skip_0;
    // 0x802256B8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    skip_0:
    // 0x802256BC: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x802256C0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_802256C4:
    // 0x802256C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x802256C8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x802256CC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x802256D0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x802256D4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x802256D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x802256DC: jr          $ra
    // 0x802256E0: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    return;
    // 0x802256E0: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802256e4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802256e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802256E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802256E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x802256EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802256F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802256F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x802256F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x802256FC: jal         0x80225560
    // 0x80225700: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x80225560)(rdram, ctx);
        goto after_0;
    // 0x80225700: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x80225704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80225708: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8022570C: jal         0x80225664
    // 0x80225710: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80225664)(rdram, ctx);
        goto after_1;
    // 0x80225710: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80225714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80225718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8022571C: jr          $ra
    // 0x80225720: nop

    return;
    // 0x80225720: nop

;}
RECOMP_FUNC void M10_FUN_80225724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225724: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80225728: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8022572C: lwc1        $f0, 0x35C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X35C);
    // 0x80225730: lwc1        $f2, 0x364($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X364);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80225734(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80225734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80225738: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8022573C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80225740: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80225744: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80225748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8022574C: jal         0x8002FC20
    // 0x80225750: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80225750: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80225754: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80225758: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8022575C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80225760: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80225764: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x80225768: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8022576C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80225770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80225774: bc1f        L_80225788
    if (!c1cs) {
        // 0x80225778: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_80225788;
    }
    // 0x80225778: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8022577C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80225780: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80225784: nop

L_80225788:
    // 0x80225788: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8022578C: lwc1        $f18, 0x364($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X364);
    // 0x80225790: lwc1        $f0, 0x35C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X35C);
    // 0x80225794: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80225798: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8022579C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x802257A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x802257A4: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x802257A8: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x802257AC: nop

    // 0x802257B0: bc1fl       L_802257C4
    if (!c1cs) {
        // 0x802257B4: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_802257C4;
    }
    goto skip_0;
    // 0x802257B4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_0:
    // 0x802257B8: b           L_802257C4
    // 0x802257BC: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_802257C4;
    // 0x802257BC: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x802257C0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_802257C4:
    // 0x802257C4: div.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x802257C8: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x802257CC: div.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x802257D0: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x802257D4: lwc1        $f6, 0x364($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X364);
    // 0x802257D8: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x802257DC: div.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x802257E0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x802257E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802257E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802257EC: jr          $ra
    // 0x802257F0: nop

    return;
    // 0x802257F0: nop

;}
RECOMP_FUNC void M10_FUN_802257f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802257F4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x802257F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x802257FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80225800: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80225804: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80225808: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8022580C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80225810: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80225814: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80225818: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8022581C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80225820: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80225824: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80225828: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8022582C: jal         0x8001EAD0
    // 0x80225830: lh          $a0, 0x12($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80225830: lh          $a0, 0x12($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X12);
    after_0:
    // 0x80225834: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80225838: jal         0x8001EB64
    // 0x8022583C: lh          $a0, 0x12($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8022583C: lh          $a0, 0x12($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X12);
    after_1:
    // 0x80225840: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x80225844: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80225848: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8022584C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80225850: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80225854: lh          $t7, 0x5A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5A);
    // 0x80225858: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8022585C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80225860: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80225864: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x80225868: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8022586C: add.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80225870: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80225874: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80225878: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8022587C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80225880: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80225884: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80225888: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8022588C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80225890: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80225894: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80225898: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8022589C: jal         0x80108480
    // 0x802258A0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80108480)(rdram, ctx);
        goto after_2;
    // 0x802258A0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x802258A4: beq         $v0, $zero, L_80225918
    if (ctx->r2 == 0) {
        // 0x802258A8: lh          $t8, 0x56($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X56);
            goto L_80225918;
    }
    // 0x802258A8: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x802258AC: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x802258B0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x802258B4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x802258B8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x802258BC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x802258C0: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x802258C4: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x802258C8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x802258CC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x802258D0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802258D4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x802258D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x802258DC: nop

    // 0x802258E0: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x802258E4: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x802258E8: jal         0x80225724
    // 0x802258EC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80225724)(rdram, ctx);
        goto after_3;
    // 0x802258EC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x802258F0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x802258F4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x802258F8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x802258FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225900: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80225904: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80225908: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8022590C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80225910: b           L_8022591C
    // 0x80225914: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8022591C;
    // 0x80225914: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_80225918:
    // 0x80225918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022591C:
    // 0x8022591C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80225920: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80225924: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80225928: jr          $ra
    // 0x8022592C: nop

    return;
    // 0x8022592C: nop

;}
RECOMP_FUNC void M10_FUN_80225930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225930: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80225934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80225938: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8022593C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80225940: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80225944: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80225948: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8022594C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80225950: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80225954: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80225958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8022595C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80225960: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80225964: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80225968: jal         0x8001EAD0
    // 0x8022596C: lh          $a0, 0x12($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8022596C: lh          $a0, 0x12($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X12);
    after_0:
    // 0x80225970: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80225974: jal         0x8001EB64
    // 0x80225978: lh          $a0, 0x12($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80225978: lh          $a0, 0x12($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X12);
    after_1:
    // 0x8022597C: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x80225980: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80225984: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80225988: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8022598C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80225990: lh          $t7, 0x5A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5A);
    // 0x80225994: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80225998: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8022599C: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x802259A0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x802259A4: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x802259A8: add.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x802259AC: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x802259B0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x802259B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x802259B8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802259BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x802259C0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x802259C4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x802259C8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x802259CC: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x802259D0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x802259D4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x802259D8: jal         0x80108480
    // 0x802259DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108480)(rdram, ctx);
        goto after_2;
    // 0x802259DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x802259E0: beq         $v0, $zero, L_80225A50
    if (ctx->r2 == 0) {
        // 0x802259E4: lh          $t8, 0x56($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X56);
            goto L_80225A50;
    }
    // 0x802259E4: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x802259E8: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x802259EC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x802259F0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x802259F4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x802259F8: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x802259FC: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80225A00: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80225A04: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80225A08: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80225A0C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80225A10: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80225A14: nop

    // 0x80225A18: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80225A1C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80225A20: jal         0x80225724
    // 0x80225A24: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80225724)(rdram, ctx);
        goto after_3;
    // 0x80225A24: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80225A28: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80225A2C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80225A30: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80225A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225A38: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80225A3C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80225A40: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80225A44: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80225A48: b           L_80225A54
    // 0x80225A4C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_80225A54;
    // 0x80225A4C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_80225A50:
    // 0x80225A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80225A54:
    // 0x80225A54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80225A58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80225A5C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80225A60: jr          $ra
    // 0x80225A64: nop

    return;
    // 0x80225A64: nop

;}
RECOMP_FUNC void M10_FUN_80225a68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225A68: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80225A6C: lbu         $t6, 0x74($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X74);
    // 0x80225A70: bnel        $t6, $zero, L_80225A84
    if (ctx->r14 != 0) {
        // 0x80225A74: lwc1        $f0, 0x68($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X68);
            goto L_80225A84;
    }
    goto skip_0;
    // 0x80225A74: lwc1        $f0, 0x68($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X68);
    skip_0:
    // 0x80225A78: jr          $ra
    // 0x80225A7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80225A7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80225A80: lwc1        $f0, 0x68($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X68);
L_80225A84:
    // 0x80225A84: lwc1        $f2, 0x6C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80225A88: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80225A8C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80225A90: nop

    // 0x80225A94: bc1f        L_80225B4C
    if (!c1cs) {
            // 0x80225A98: nop

    LOOKUP_FUNC(0x80225B4C)(rdram, ctx);
    return;
    }
    // 0x80225A98: nop

    // 0x80225A9C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80225AA0: ldc1        $f6, -0x1020($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1020);
    // 0x80225AA4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80225AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225AAC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80225AB0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80225AB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80225AB8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225ABC: nop

    // 0x80225AC0: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80225AC4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225AC8: nop

    // 0x80225ACC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225AD0: beql        $v0, $zero, L_80225B34
    if (ctx->r2 == 0) {
        // 0x80225AD4: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_80225B34;
    }
    goto skip_1;
    // 0x80225AD4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80225AD8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80225ADC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80225AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225AE4: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x80225AE8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225AEC: nop

    // 0x80225AF0: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x80225AF4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225AF8: nop

    // 0x80225AFC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225B00: bnel        $v0, $zero, L_80225B24
    if (ctx->r2 != 0) {
        // 0x80225B04: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80225B24;
    }
    goto skip_2;
    // 0x80225B04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x80225B08: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80225B0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80225B10: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80225B14: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80225B18: jr          $ra
    // 0x80225B1C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x80225B1C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80225B20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80225B24:
    // 0x80225B24: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80225B28: jr          $ra
    // 0x80225B2C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x80225B2C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80225B30: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_80225B34:
    // 0x80225B34: nop

    // 0x80225B38: bltzl       $v0, L_80225B24
    if (SIGNED(ctx->r2) < 0) {
        // 0x80225B3C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80225B24;
    }
    goto skip_3;
    // 0x80225B3C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_3:
    // 0x80225B40: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80225B44: jr          $ra
    // 0x80225B48: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x80225B48: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80225b4c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80225b4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225B4C: ldc1        $f18, -0x1018($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X1018);
    // 0x80225B50: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80225B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225B58: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80225B5C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80225B60: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80225B64: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225B68: nop

    // 0x80225B6C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80225B70: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225B74: nop

    // 0x80225B78: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225B7C: beql        $v0, $zero, L_80225BD0
    if (ctx->r2 == 0) {
        // 0x80225B80: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80225BD0;
    }
    goto skip_0;
    // 0x80225B80: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80225B84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80225B88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80225B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225B90: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80225B94: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225B98: nop

    // 0x80225B9C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x80225BA0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225BA4: nop

    // 0x80225BA8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225BAC: bne         $v0, $zero, L_80225BC4
    if (ctx->r2 != 0) {
        // 0x80225BB0: nop
    
            goto L_80225BC4;
    }
    // 0x80225BB0: nop

    // 0x80225BB4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80225BB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80225BBC: b           L_80225BDC
    // 0x80225BC0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80225BDC;
    // 0x80225BC0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80225BC4:
    // 0x80225BC4: b           L_80225BDC
    // 0x80225BC8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80225BDC;
    // 0x80225BC8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80225BCC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80225BD0:
    // 0x80225BD0: nop

    // 0x80225BD4: bltz        $v0, L_80225BC4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80225BD8: nop
    
            goto L_80225BC4;
    }
    // 0x80225BD8: nop

L_80225BDC:
    // 0x80225BDC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80225BE0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80225BE4: nop

    // 0x80225BE8: jr          $ra
    // 0x80225BEC: nop

    return;
    // 0x80225BEC: nop

;}
RECOMP_FUNC void M10_FUN_80225bf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225BF0: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x80225BF4: lbu         $t6, 0x74($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X74);
    // 0x80225BF8: bnel        $t6, $zero, L_80225C0C
    if (ctx->r14 != 0) {
        // 0x80225BFC: lwc1        $f4, 0x68($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
            goto L_80225C0C;
    }
    goto skip_0;
    // 0x80225BFC: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    skip_0:
    // 0x80225C00: jr          $ra
    // 0x80225C04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80225C04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80225C08: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
L_80225C0C:
    // 0x80225C0C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80225C10: ldc1        $f8, -0x1010($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1010);
    // 0x80225C14: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80225C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225C1C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80225C20: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80225C24: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80225C28: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225C2C: nop

    // 0x80225C30: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x80225C34: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225C38: nop

    // 0x80225C3C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225C40: beql        $v0, $zero, L_80225C94
    if (ctx->r2 == 0) {
        // 0x80225C44: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_80225C94;
    }
    goto skip_1;
    // 0x80225C44: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80225C48: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80225C4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80225C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225C54: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x80225C58: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225C5C: nop

    // 0x80225C60: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80225C64: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225C68: nop

    // 0x80225C6C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225C70: bne         $v0, $zero, L_80225C88
    if (ctx->r2 != 0) {
        // 0x80225C74: nop
    
            goto L_80225C88;
    }
    // 0x80225C74: nop

    // 0x80225C78: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80225C7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80225C80: b           L_80225CA0
    // 0x80225C84: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80225CA0;
    // 0x80225C84: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80225C88:
    // 0x80225C88: b           L_80225CA0
    // 0x80225C8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80225CA0;
    // 0x80225C8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80225C90: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_80225C94:
    // 0x80225C94: nop

    // 0x80225C98: bltz        $v0, L_80225C88
    if (SIGNED(ctx->r2) < 0) {
        // 0x80225C9C: nop
    
            goto L_80225C88;
    }
    // 0x80225C9C: nop

L_80225CA0:
    // 0x80225CA0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80225CA4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80225CA8: nop

    // 0x80225CAC: jr          $ra
    // 0x80225CB0: nop

    return;
    // 0x80225CB0: nop

;}
RECOMP_FUNC void M10_FUN_80225cb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225CB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80225CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80225CBC: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80225CC0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80225CC4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80225CC8: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80225CCC: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80225CD0: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80225CD4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80225CD8: nop

    // 0x80225CDC: bc1f        L_80225D94
    if (!c1cs) {
        // 0x80225CE0: nop
    
            goto L_80225D94;
    }
    // 0x80225CE0: nop

    // 0x80225CE4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80225CE8: ldc1        $f8, -0x1008($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1008);
    // 0x80225CEC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80225CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80225CF4: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80225CF8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80225CFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80225D00: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80225D04: nop

    // 0x80225D08: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x80225D0C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80225D10: nop

    // 0x80225D14: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80225D18: beql        $a1, $zero, L_80225D7C
    if (ctx->r5 == 0) {
        // 0x80225D1C: mfc1        $a1, $f16
        ctx->r5 = (int32_t)ctx->f16.u32l;
            goto L_80225D7C;
    }
    goto skip_0;
    // 0x80225D1C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80225D20: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80225D24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80225D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80225D2C: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x80225D30: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80225D34: nop

    // 0x80225D38: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80225D3C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80225D40: nop

    // 0x80225D44: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80225D48: bnel        $a1, $zero, L_80225D6C
    if (ctx->r5 != 0) {
        // 0x80225D4C: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_80225D6C;
    }
    goto skip_1;
    // 0x80225D4C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    skip_1:
    // 0x80225D50: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80225D54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80225D58: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80225D5C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x80225D60: b           L_80225E30
    // 0x80225D64: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
        goto L_80225E30;
    // 0x80225D64: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80225D68: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80225D6C:
    // 0x80225D6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80225D70: b           L_80225E30
    // 0x80225D74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
        goto L_80225E30;
    // 0x80225D74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80225D78: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
L_80225D7C:
    // 0x80225D7C: nop

    // 0x80225D80: bltzl       $a1, L_80225D6C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80225D84: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_80225D6C;
    }
    goto skip_2;
    // 0x80225D84: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    skip_2:
    // 0x80225D88: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80225D8C: b           L_80225E30
    // 0x80225D90: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
        goto L_80225E30;
    // 0x80225D90: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_80225D94:
    // 0x80225D94: ldc1        $f4, -0x1000($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1000);
    // 0x80225D98: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80225D9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80225DA0: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80225DA4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80225DA8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80225DAC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80225DB0: nop

    // 0x80225DB4: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x80225DB8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80225DBC: nop

    // 0x80225DC0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80225DC4: beql        $a1, $zero, L_80225E18
    if (ctx->r5 == 0) {
        // 0x80225DC8: mfc1        $a1, $f8
        ctx->r5 = (int32_t)ctx->f8.u32l;
            goto L_80225E18;
    }
    goto skip_3;
    // 0x80225DC8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x80225DCC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80225DD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80225DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80225DD8: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x80225DDC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80225DE0: nop

    // 0x80225DE4: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x80225DE8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80225DEC: nop

    // 0x80225DF0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80225DF4: bne         $a1, $zero, L_80225E0C
    if (ctx->r5 != 0) {
        // 0x80225DF8: nop
    
            goto L_80225E0C;
    }
    // 0x80225DF8: nop

    // 0x80225DFC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80225E00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80225E04: b           L_80225E24
    // 0x80225E08: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80225E24;
    // 0x80225E08: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80225E0C:
    // 0x80225E0C: b           L_80225E24
    // 0x80225E10: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80225E24;
    // 0x80225E10: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80225E14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
L_80225E18:
    // 0x80225E18: nop

    // 0x80225E1C: bltz        $a1, L_80225E0C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80225E20: nop
    
            goto L_80225E0C;
    }
    // 0x80225E20: nop

L_80225E24:
    // 0x80225E24: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80225E28: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80225E2C: nop

L_80225E30:
    // 0x80225E30: sb          $a1, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r5;
    // 0x80225E34: jal         0x80225A68
    // 0x80225E38: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x80225A68)(rdram, ctx);
        goto after_0;
    // 0x80225E38: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80225E3C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80225E40: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80225E44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80225E48: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80225E4C: lbu         $a1, 0x1E($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1E);
    // 0x80225E50: c.le.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d <= ctx->f10.d;
    // 0x80225E54: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80225E58: subu        $t8, $a1, $v1
    ctx->r24 = SUB32(ctx->r5, ctx->r3);
    // 0x80225E5C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80225E60: bc1f        L_80225E74
    if (!c1cs) {
        // 0x80225E64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80225E74;
    }
    // 0x80225E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80225E68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80225E6C: b           L_80225EA0
    // 0x80225E70: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
        goto L_80225EA0;
    // 0x80225E70: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
L_80225E74:
    // 0x80225E74: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80225E78: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80225E7C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80225E80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80225E84: c.le.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d <= ctx->f0.d;
    // 0x80225E88: nop

    // 0x80225E8C: bc1fl       L_80225EA0
    if (!c1cs) {
        // 0x80225E90: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80225EA0;
    }
    goto skip_4;
    // 0x80225E90: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    skip_4:
    // 0x80225E94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80225E98: nop

    // 0x80225E9C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
L_80225EA0:
    // 0x80225EA0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80225EA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80225EA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80225EAC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80225EB0: bgezl       $v1, L_80225EC8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80225EB4: add.s       $f18, $f6, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
            goto L_80225EC8;
    }
    goto skip_5;
    // 0x80225EB4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    skip_5:
    // 0x80225EB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80225EBC: nop

    // 0x80225EC0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80225EC4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
L_80225EC8:
    // 0x80225EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225ECC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80225ED0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80225ED4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225ED8: nop

    // 0x80225EDC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80225EE0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225EE4: nop

    // 0x80225EE8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225EEC: beql        $v0, $zero, L_80225F3C
    if (ctx->r2 == 0) {
        // 0x80225EF0: mfc1        $v0, $f4
        ctx->r2 = (int32_t)ctx->f4.u32l;
            goto L_80225F3C;
    }
    goto skip_6;
    // 0x80225EF0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x80225EF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80225EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225EFC: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80225F00: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80225F04: nop

    // 0x80225F08: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80225F0C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80225F10: nop

    // 0x80225F14: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80225F18: bne         $v0, $zero, L_80225F30
    if (ctx->r2 != 0) {
        // 0x80225F1C: nop
    
            goto L_80225F30;
    }
    // 0x80225F1C: nop

    // 0x80225F20: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80225F24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80225F28: b           L_80225F48
    // 0x80225F2C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80225F48;
    // 0x80225F2C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80225F30:
    // 0x80225F30: b           L_80225F48
    // 0x80225F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80225F48;
    // 0x80225F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80225F38: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
L_80225F3C:
    // 0x80225F3C: nop

    // 0x80225F40: bltz        $v0, L_80225F30
    if (SIGNED(ctx->r2) < 0) {
        // 0x80225F44: nop
    
            goto L_80225F30;
    }
    // 0x80225F44: nop

L_80225F48:
    // 0x80225F48: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80225F4C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80225F50: jr          $ra
    // 0x80225F54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80225F54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80225f58(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80225f58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225F58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80225F5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80225F60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80225F64: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80225F68: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80225F6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80225F70: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80225F74: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80225F78: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80225F7C: lbu         $t8, 0x4E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4E);
    // 0x80225F80: jal         0x80225CB4
    // 0x80225F84: sb          $t8, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80225CB4)(rdram, ctx);
        goto after_0;
    // 0x80225F84: sb          $t8, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r24;
    after_0:
    // 0x80225F88: sb          $v0, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r2;
    // 0x80225F8C: jal         0x80225BF0
    // 0x80225F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80225BF0)(rdram, ctx);
        goto after_1;
    // 0x80225F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80225F94: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x80225F98: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
    // 0x80225F9C: lbu         $a2, 0x4E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4E);
    // 0x80225FA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80225FA4: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80225FA8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80225FAC: jal         0x80225930
    // 0x80225FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80225930)(rdram, ctx);
        goto after_2;
    // 0x80225FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80225FB4: beq         $v0, $zero, L_80225FC4
    if (ctx->r2 == 0) {
        // 0x80225FB8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80225FC4;
    }
    // 0x80225FB8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80225FBC: b           L_80225FFC
    // 0x80225FC0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80225FFC;
    // 0x80225FC0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80225FC4:
    // 0x80225FC4: lbu         $a2, 0x4E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4E);
    // 0x80225FC8: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x80225FCC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80225FD0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80225FD4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80225FD8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80225FDC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80225FE0: jal         0x80225930
    // 0x80225FE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80225930)(rdram, ctx);
        goto after_3;
    // 0x80225FE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80225FE8: beql        $v0, $zero, L_80225FFC
    if (ctx->r2 == 0) {
        // 0x80225FEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80225FFC;
    }
    goto skip_0;
    // 0x80225FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80225FF0: b           L_80225FFC
    // 0x80225FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80225FFC;
    // 0x80225FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80225FFC:
    // 0x80225FFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80226000: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80226004: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80226008: jr          $ra
    // 0x8022600C: nop

    return;
    // 0x8022600C: nop

;}
RECOMP_FUNC void M10_FUN_80226010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226010: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80226014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80226018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8022601C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80226020: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80226024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80226028: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8022602C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80226030: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80226034: lbu         $t8, 0x4C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4C);
    // 0x80226038: jal         0x80225CB4
    // 0x8022603C: sb          $t8, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80225CB4)(rdram, ctx);
        goto after_0;
    // 0x8022603C: sb          $t8, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r24;
    after_0:
    // 0x80226040: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x80226044: jal         0x80225BF0
    // 0x80226048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80225BF0)(rdram, ctx);
        goto after_1;
    // 0x80226048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8022604C: sb          $v0, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r2;
    // 0x80226050: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
    // 0x80226054: lbu         $a2, 0x4C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4C);
    // 0x80226058: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8022605C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80226060: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80226064: jal         0x802257F4
    // 0x80226068: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x802257F4)(rdram, ctx);
        goto after_2;
    // 0x80226068: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x8022606C: beq         $v0, $zero, L_8022607C
    if (ctx->r2 == 0) {
        // 0x80226070: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8022607C;
    }
    // 0x80226070: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80226074: b           L_802260B4
    // 0x80226078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_802260B4;
    // 0x80226078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8022607C:
    // 0x8022607C: lbu         $a2, 0x4C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4C);
    // 0x80226080: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x80226084: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80226088: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x8022608C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80226090: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80226094: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80226098: jal         0x802257F4
    // 0x8022609C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x802257F4)(rdram, ctx);
        goto after_3;
    // 0x8022609C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x802260A0: beql        $v0, $zero, L_802260B4
    if (ctx->r2 == 0) {
        // 0x802260A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_802260B4;
    }
    goto skip_0;
    // 0x802260A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x802260A8: b           L_802260B4
    // 0x802260AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_802260B4;
    // 0x802260AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x802260B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802260B4:
    // 0x802260B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802260B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x802260BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x802260C0: jr          $ra
    // 0x802260C4: nop

    return;
    // 0x802260C4: nop

;}
RECOMP_FUNC void M10_FUN_802260c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802260C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x802260CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802260D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802260D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802260D8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x802260DC: lbu         $v0, 0x4C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4C);
    // 0x802260E0: lbu         $a3, 0x4E($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X4E);
    // 0x802260E4: lw          $s1, 0x2C($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X2C);
    // 0x802260E8: sb          $v0, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = ctx->r2;
    // 0x802260EC: sb          $a3, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r7;
    // 0x802260F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802260F4: lbu         $a2, 0x4C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4C);
    // 0x802260F8: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x802260FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80226100: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80226104: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80226108: sb          $a3, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r7;
    // 0x8022610C: jal         0x802257F4
    // 0x80226110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x802257F4)(rdram, ctx);
        goto after_0;
    // 0x80226110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80226114: beq         $v0, $zero, L_80226124
    if (ctx->r2 == 0) {
        // 0x80226118: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80226124;
    }
    // 0x80226118: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8022611C: b           L_802261B8
    // 0x80226120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_802261B8;
    // 0x80226120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80226124:
    // 0x80226124: lbu         $a2, 0x4C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4C);
    // 0x80226128: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x8022612C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80226130: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80226134: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80226138: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022613C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80226140: jal         0x802257F4
    // 0x80226144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x802257F4)(rdram, ctx);
        goto after_1;
    // 0x80226144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80226148: beq         $v0, $zero, L_80226158
    if (ctx->r2 == 0) {
        // 0x8022614C: lbu         $v1, 0x2A($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X2A);
            goto L_80226158;
    }
    // 0x8022614C: lbu         $v1, 0x2A($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2A);
    // 0x80226150: b           L_802261B8
    // 0x80226154: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_802261B8;
    // 0x80226154: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80226158:
    // 0x80226158: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x8022615C: lbu         $a2, 0x4E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4E);
    // 0x80226160: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80226164: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80226168: jal         0x80225930
    // 0x8022616C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80225930)(rdram, ctx);
        goto after_2;
    // 0x8022616C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80226170: beq         $v0, $zero, L_80226180
    if (ctx->r2 == 0) {
        // 0x80226174: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80226180;
    }
    // 0x80226174: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80226178: b           L_802261B8
    // 0x8022617C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_802261B8;
    // 0x8022617C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80226180:
    // 0x80226180: lbu         $a2, 0x4E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4E);
    // 0x80226184: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x80226188: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8022618C: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80226190: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80226194: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80226198: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8022619C: jal         0x80225930
    // 0x802261A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80225930)(rdram, ctx);
        goto after_3;
    // 0x802261A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x802261A4: beql        $v0, $zero, L_802261B8
    if (ctx->r2 == 0) {
        // 0x802261A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_802261B8;
    }
    goto skip_0;
    // 0x802261A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x802261AC: b           L_802261B8
    // 0x802261B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_802261B8;
    // 0x802261B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x802261B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802261B8:
    // 0x802261B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802261BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802261C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802261C4: jr          $ra
    // 0x802261C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x802261C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802261cc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802261cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802261CC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x802261D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x802261D4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x802261D8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x802261DC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x802261E0: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x802261E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802261E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x802261EC: jal         0x80126944
    // 0x802261F0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x802261F0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_0:
    // 0x802261F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802261F8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x802261FC: beq         $v0, $at, L_8022620C
    if (ctx->r2 == ctx->r1) {
        // 0x80226200: lw          $t0, 0x54($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X54);
            goto L_8022620C;
    }
    // 0x80226200: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80226204: b           L_802264BC
    // 0x80226208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802264BC;
    // 0x80226208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8022620C:
    // 0x8022620C: bnel        $v1, $zero, L_80226220
    if (ctx->r3 != 0) {
        // 0x80226210: lbu         $t6, 0x63($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X63);
            goto L_80226220;
    }
    goto skip_0;
    // 0x80226210: lbu         $t6, 0x63($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X63);
    skip_0:
    // 0x80226214: b           L_802264BC
    // 0x80226218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802264BC;
    // 0x80226218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8022621C: lbu         $t6, 0x63($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X63);
L_80226220:
    // 0x80226220: bnel        $t6, $zero, L_80226234
    if (ctx->r14 != 0) {
        // 0x80226224: lw          $t7, 0x24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X24);
            goto L_80226234;
    }
    goto skip_1;
    // 0x80226224: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x80226228: b           L_802264BC
    // 0x8022622C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802264BC;
    // 0x8022622C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80226230: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
L_80226234:
    // 0x80226234: bnel        $t7, $zero, L_80226248
    if (ctx->r15 != 0) {
        // 0x80226238: lw          $t8, 0x0($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X0);
            goto L_80226248;
    }
    goto skip_2;
    // 0x80226238: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x8022623C: b           L_802264BC
    // 0x80226240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802264BC;
    // 0x80226240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80226244: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
L_80226248:
    // 0x80226248: bnel        $t8, $zero, L_8022625C
    if (ctx->r24 != 0) {
        // 0x8022624C: lhu         $t9, 0xC($v1)
        ctx->r25 = MEM_HU(ctx->r3, 0XC);
            goto L_8022625C;
    }
    goto skip_3;
    // 0x8022624C: lhu         $t9, 0xC($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XC);
    skip_3:
    // 0x80226250: b           L_802264BC
    // 0x80226254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802264BC;
    // 0x80226254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80226258: lhu         $t9, 0xC($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XC);
L_8022625C:
    // 0x8022625C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80226260: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80226264: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x80226268: bnel        $t3, $zero, L_8022627C
    if (ctx->r11 != 0) {
        // 0x8022626C: lw          $t5, 0xB0($v1)
        ctx->r13 = MEM_W(ctx->r3, 0XB0);
            goto L_8022627C;
    }
    goto skip_4;
    // 0x8022626C: lw          $t5, 0xB0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XB0);
    skip_4:
    // 0x80226270: b           L_802264BC
    // 0x80226274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802264BC;
    // 0x80226274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80226278: lw          $t5, 0xB0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XB0);
L_8022627C:
    // 0x8022627C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80226280: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80226284: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x80226288: lw          $a3, 0xB4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XB4);
    // 0x8022628C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80226290: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80226294: lw          $t5, 0xB8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XB8);
    // 0x80226298: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8022629C: lw          $t7, 0xBC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XBC);
    // 0x802262A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x802262A4: lw          $t6, 0xC0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC0);
    // 0x802262A8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x802262AC: lw          $t7, 0xC4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC4);
    // 0x802262B0: jal         0x80223B2C
    // 0x802262B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80223B2C)(rdram, ctx);
        goto after_1;
    // 0x802262B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x802262B8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x802262BC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802262C0: ldc1        $f8, -0xFF8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0XFF8);
    // 0x802262C4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x802262C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x802262CC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x802262D0: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x802262D4: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x802262D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x802262DC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x802262E0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x802262E4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x802262E8: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x802262EC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802262F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x802262F4: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x802262F8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x802262FC: nop

    // 0x80226300: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80226304: beq         $t1, $zero, L_80226354
    if (ctx->r9 == 0) {
        // 0x80226308: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_80226354;
    }
    // 0x80226308: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8022630C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80226310: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80226314: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80226318: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x8022631C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80226320: nop

    // 0x80226324: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80226328: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8022632C: nop

    // 0x80226330: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80226334: bne         $t1, $zero, L_8022634C
    if (ctx->r9 != 0) {
        // 0x80226338: nop
    
            goto L_8022634C;
    }
    // 0x80226338: nop

    // 0x8022633C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80226340: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80226344: b           L_80226364
    // 0x80226348: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80226364;
    // 0x80226348: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8022634C:
    // 0x8022634C: b           L_80226364
    // 0x80226350: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80226364;
    // 0x80226350: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80226354:
    // 0x80226354: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80226358: nop

    // 0x8022635C: bltz        $t1, L_8022634C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80226360: nop
    
            goto L_8022634C;
    }
    // 0x80226360: nop

L_80226364:
    // 0x80226364: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80226368: sb          $t1, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r9;
    // 0x8022636C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80226370: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80226374: jal         0x802257F4
    // 0x80226378: andi        $a2, $t1, 0xFF
    ctx->r6 = ctx->r9 & 0XFF;
    LOOKUP_FUNC(0x802257F4)(rdram, ctx);
        goto after_2;
    // 0x80226378: andi        $a2, $t1, 0xFF
    ctx->r6 = ctx->r9 & 0XFF;
    after_2:
    // 0x8022637C: beq         $v0, $zero, L_80226388
    if (ctx->r2 == 0) {
        // 0x80226380: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80226388;
    }
    // 0x80226380: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80226384: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80226388:
    // 0x80226388: lbu         $a2, 0x4C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4C);
    // 0x8022638C: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x80226390: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80226394: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80226398: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022639C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802263A0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802263A4: jal         0x802257F4
    // 0x802263A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x802257F4)(rdram, ctx);
        goto after_3;
    // 0x802263A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x802263AC: beq         $v0, $zero, L_802263BC
    if (ctx->r2 == 0) {
        // 0x802263B0: lwc1        $f18, 0x44($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
            goto L_802263BC;
    }
    // 0x802263B0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x802263B4: ori         $s1, $s1, 0x1
    ctx->r17 = ctx->r17 | 0X1;
    // 0x802263B8: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
L_802263BC:
    // 0x802263BC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802263C0: ldc1        $f6, -0xFF0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0XFF0);
    // 0x802263C4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802263C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x802263CC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x802263D0: lbu         $v0, 0x4E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4E);
    // 0x802263D4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x802263D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x802263DC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x802263E0: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x802263E4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802263E8: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x802263EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x802263F0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x802263F4: nop

    // 0x802263F8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x802263FC: beql        $t3, $zero, L_80226450
    if (ctx->r11 == 0) {
        // 0x80226400: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_80226450;
    }
    goto skip_5;
    // 0x80226400: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_5:
    // 0x80226404: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80226408: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8022640C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80226410: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x80226414: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80226418: nop

    // 0x8022641C: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x80226420: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80226424: nop

    // 0x80226428: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8022642C: bne         $t3, $zero, L_80226444
    if (ctx->r11 != 0) {
        // 0x80226430: nop
    
            goto L_80226444;
    }
    // 0x80226430: nop

    // 0x80226434: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80226438: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022643C: b           L_8022645C
    // 0x80226440: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8022645C;
    // 0x80226440: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80226444:
    // 0x80226444: b           L_8022645C
    // 0x80226448: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8022645C;
    // 0x80226448: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8022644C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_80226450:
    // 0x80226450: nop

    // 0x80226454: bltz        $t3, L_80226444
    if (SIGNED(ctx->r11) < 0) {
        // 0x80226458: nop
    
            goto L_80226444;
    }
    // 0x80226458: nop

L_8022645C:
    // 0x8022645C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80226460: sb          $t3, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r11;
    // 0x80226464: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80226468: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8022646C: jal         0x80225930
    // 0x80226470: andi        $a2, $t3, 0xFF
    ctx->r6 = ctx->r11 & 0XFF;
    LOOKUP_FUNC(0x80225930)(rdram, ctx);
        goto after_4;
    // 0x80226470: andi        $a2, $t3, 0xFF
    ctx->r6 = ctx->r11 & 0XFF;
    after_4:
    // 0x80226474: beq         $v0, $zero, L_80226484
    if (ctx->r2 == 0) {
        // 0x80226478: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80226484;
    }
    // 0x80226478: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8022647C: ori         $s1, $s1, 0x8
    ctx->r17 = ctx->r17 | 0X8;
    // 0x80226480: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
L_80226484:
    // 0x80226484: lbu         $a2, 0x4E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4E);
    // 0x80226488: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x8022648C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80226490: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80226494: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80226498: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022649C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802264A0: jal         0x80225930
    // 0x802264A4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80225930)(rdram, ctx);
        goto after_5;
    // 0x802264A4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x802264A8: beql        $v0, $zero, L_802264BC
    if (ctx->r2 == 0) {
        // 0x802264AC: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_802264BC;
    }
    goto skip_6;
    // 0x802264AC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_6:
    // 0x802264B0: ori         $s1, $s1, 0x4
    ctx->r17 = ctx->r17 | 0X4;
    // 0x802264B4: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x802264B8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_802264BC:
    // 0x802264BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x802264C0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x802264C4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x802264C8: jr          $ra
    // 0x802264CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x802264CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802264d0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802264d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802264D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802264D4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x802264D8: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802264dc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802264dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802264DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x802264E0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x802264E4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x802264E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802264EC: beq         $a0, $v0, L_802264FC
    if (ctx->r4 == ctx->r2) {
        // 0x802264F0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_802264FC;
    }
    // 0x802264F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x802264F4: b           L_80226500
    // 0x802264F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80226500;
    // 0x802264F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_802264FC:
    // 0x802264FC: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_80226500:
    // 0x80226500: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80226504: addiu       $t7, $t7, -0x36F4
    ctx->r15 = ADD32(ctx->r15, -0X36F4);
    // 0x80226508: lhu         $v1, 0x36($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X36);
    // 0x8022650C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80226510: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80226514: lhu         $t0, 0x36($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X36);
    // 0x80226518: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x8022651C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80226520: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80226524: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80226528: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x8022652C: sw          $t8, 0x4($t6)
        MEM_W(0X4, ctx->r14) = ctx->r24;
            goto L_80226578;
    }
    // 0x8022652C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80226530: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80226534: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226538: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_80226578;
    }
    // 0x80226538: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8022653C: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226540: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80226578;
    }
    // 0x80226540: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80226544: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226548: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80226578;
    }
    // 0x80226548: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8022654C: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226550: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80226578;
    }
    // 0x80226550: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80226554: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226558: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80226578;
    }
    // 0x80226558: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8022655C: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226560: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_80226578;
    }
    // 0x80226560: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80226564: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226568: addiu       $at, $zero, 0x58
        ctx->r1 = ADD32(0, 0X58);
            goto L_80226578;
    }
    // 0x80226568: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8022656C: beq         $v1, $at, L_80226578
    if (ctx->r3 == ctx->r1) {
        // 0x80226570: addiu       $at, $zero, 0x59
        ctx->r1 = ADD32(0, 0X59);
            goto L_80226578;
    }
    // 0x80226570: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80226574: bne         $v1, $at, L_802265BC
    if (ctx->r3 != ctx->r1) {
        // 0x80226578: addiu       $at, $zero, 0x281
        ctx->r1 = ADD32(0, 0X281);
            goto L_802265BC;
    }
L_80226578:
    // 0x80226578: addiu       $at, $zero, 0x281
    ctx->r1 = ADD32(0, 0X281);
    // 0x8022657C: bne         $a1, $at, L_802265BC
    if (ctx->r5 != ctx->r1) {
        // 0x80226580: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_802265BC;
    }
    // 0x80226580: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80226584: addiu       $a1, $sp, 0x27
    ctx->r5 = ADD32(ctx->r29, 0X27);
    // 0x80226588: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    // 0x8022658C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80226590: jal         0x801DFCAC
    // 0x80226594: sh          $t0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801DFCAC)(rdram, ctx);
        goto after_0;
    // 0x80226594: sh          $t0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x80226598: lbu         $t1, 0x26($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X26);
    // 0x8022659C: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x802265A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x802265A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x802265A8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x802265AC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x802265B0: addu        $a1, $sp, $t5
    ctx->r5 = ADD32(ctx->r29, ctx->r13);
    // 0x802265B4: lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X30);
    // 0x802265B8: lhu         $a1, 0x28($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X28);
L_802265BC:
    // 0x802265BC: addiu       $v1, $zero, 0xF6
    ctx->r3 = ADD32(0, 0XF6);
    // 0x802265C0: beq         $v1, $v0, L_802265D4
    if (ctx->r3 == ctx->r2) {
        // 0x802265C4: addiu       $a0, $zero, 0xF4
        ctx->r4 = ADD32(0, 0XF4);
            goto L_802265D4;
    }
    // 0x802265C4: addiu       $a0, $zero, 0xF4
    ctx->r4 = ADD32(0, 0XF4);
    // 0x802265C8: beq         $a0, $v0, L_802265D4
    if (ctx->r4 == ctx->r2) {
        // 0x802265CC: addiu       $a2, $zero, 0xF5
        ctx->r6 = ADD32(0, 0XF5);
            goto L_802265D4;
    }
    // 0x802265CC: addiu       $a2, $zero, 0xF5
    ctx->r6 = ADD32(0, 0XF5);
    // 0x802265D0: bne         $a2, $v0, L_80226638
    if (ctx->r6 != ctx->r2) {
        // 0x802265D4: slti        $at, $a1, 0x282
        ctx->r1 = SIGNED(ctx->r5) < 0X282 ? 1 : 0;
            goto L_80226638;
    }
L_802265D4:
    // 0x802265D4: slti        $at, $a1, 0x282
    ctx->r1 = SIGNED(ctx->r5) < 0X282 ? 1 : 0;
    // 0x802265D8: bne         $at, $zero, L_80226604
    if (ctx->r1 != 0) {
        // 0x802265DC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80226604;
    }
    // 0x802265DC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x802265E0: addiu       $t6, $v0, -0x3B3
    ctx->r14 = ADD32(ctx->r2, -0X3B3);
    // 0x802265E4: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x802265E8: beq         $at, $zero, L_802266B4
    if (ctx->r1 == 0) {
        // 0x802265EC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_802266B4;
    }
    // 0x802265EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x802265F0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802265F4: addu        $at, $at, $t6
    gpr jr_addend_802265FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x802265F8: lw          $t6, -0xFE8($at)
    ctx->r14 = ADD32(ctx->r1, -0XFE8);
    // 0x802265FC: jr          $t6
    // 0x80226600: nop

    switch (jr_addend_802265FC >> 2) {
        case 0: goto L_80226620; break;
        case 1: goto L_80226620; break;
        case 2: goto L_80226620; break;
        case 3: goto L_80226620; break;
        case 4: goto L_80226620; break;
        case 5: goto L_80226620; break;
        case 6: goto L_80226620; break;
        case 7: goto L_80226620; break;
        case 8: goto L_802266B4; break;
        case 9: goto L_802266B4; break;
        case 10: goto L_80226628; break;
        default: switch_error(__func__, 0x802265FC, 0x8023F018);
    }
    // 0x80226600: nop

L_80226604:
    // 0x80226604: addiu       $at, $zero, 0x27B
    ctx->r1 = ADD32(0, 0X27B);
    // 0x80226608: beq         $v0, $at, L_80226630
    if (ctx->r2 == ctx->r1) {
        // 0x8022660C: addiu       $at, $zero, 0x281
        ctx->r1 = ADD32(0, 0X281);
            goto L_80226630;
    }
    // 0x8022660C: addiu       $at, $zero, 0x281
    ctx->r1 = ADD32(0, 0X281);
    // 0x80226610: bne         $v0, $at, L_802266B4
    if (ctx->r2 != ctx->r1) {
        // 0x80226614: nop
    
            goto L_802266B4;
    }
    // 0x80226614: nop

    // 0x80226618: jal         0x80020718
    // 0x8022661C: addiu       $a0, $zero, 0x22D
    ctx->r4 = ADD32(0, 0X22D);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x8022661C: addiu       $a0, $zero, 0x22D
    ctx->r4 = ADD32(0, 0X22D);
    after_1:
L_80226620:
    // 0x80226620: b           L_802266B4
    // 0x80226624: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
        goto L_802266B4;
    // 0x80226624: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
L_80226628:
    // 0x80226628: b           L_802266B4
    // 0x8022662C: addiu       $a1, $zero, 0x230
    ctx->r5 = ADD32(0, 0X230);
        goto L_802266B4;
    // 0x8022662C: addiu       $a1, $zero, 0x230
    ctx->r5 = ADD32(0, 0X230);
L_80226630:
    // 0x80226630: b           L_802266B4
    // 0x80226634: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
        goto L_802266B4;
    // 0x80226634: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
L_80226638:
    // 0x80226638: beq         $v1, $t0, L_80226650
    if (ctx->r3 == ctx->r8) {
        // 0x8022663C: slti        $at, $a1, 0x27C
        ctx->r1 = SIGNED(ctx->r5) < 0X27C ? 1 : 0;
            goto L_80226650;
    }
    // 0x8022663C: slti        $at, $a1, 0x27C
    ctx->r1 = SIGNED(ctx->r5) < 0X27C ? 1 : 0;
    // 0x80226640: beq         $a0, $t0, L_80226650
    if (ctx->r4 == ctx->r8) {
        // 0x80226644: nop
    
            goto L_80226650;
    }
    // 0x80226644: nop

    // 0x80226648: bne         $a2, $t0, L_802266B4
    if (ctx->r6 != ctx->r8) {
        // 0x8022664C: nop
    
            goto L_802266B4;
    }
    // 0x8022664C: nop

L_80226650:
    // 0x80226650: bne         $at, $zero, L_8022667C
    if (ctx->r1 != 0) {
        // 0x80226654: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8022667C;
    }
    // 0x80226654: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80226658: addiu       $t7, $v0, -0x3B3
    ctx->r15 = ADD32(ctx->r2, -0X3B3);
    // 0x8022665C: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80226660: beq         $at, $zero, L_802266B4
    if (ctx->r1 == 0) {
        // 0x80226664: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_802266B4;
    }
    // 0x80226664: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80226668: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022666C: addu        $at, $at, $t7
    gpr jr_addend_80226674 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80226670: lw          $t7, -0xFBC($at)
    ctx->r15 = ADD32(ctx->r1, -0XFBC);
    // 0x80226674: jr          $t7
    // 0x80226678: nop

    switch (jr_addend_80226674 >> 2) {
        case 0: goto L_80226688; break;
        case 1: goto L_80226690; break;
        case 2: goto L_80226698; break;
        case 3: goto L_802266B4; break;
        case 4: goto L_80226688; break;
        case 5: goto L_80226690; break;
        case 6: goto L_80226698; break;
        case 7: goto L_802266B4; break;
        case 8: goto L_802266A0; break;
        case 9: goto L_802266A8; break;
        case 10: goto L_802266B0; break;
        default: switch_error(__func__, 0x80226674, 0x8023F044);
    }
    // 0x80226678: nop

L_8022667C:
    // 0x8022667C: addiu       $at, $zero, 0x27B
    ctx->r1 = ADD32(0, 0X27B);
    // 0x80226680: bne         $v0, $at, L_802266B4
    if (ctx->r2 != ctx->r1) {
        // 0x80226684: nop
    
            goto L_802266B4;
    }
    // 0x80226684: nop

L_80226688:
    // 0x80226688: b           L_802266B4
    // 0x8022668C: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
        goto L_802266B4;
    // 0x8022668C: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
L_80226690:
    // 0x80226690: b           L_802266B4
    // 0x80226694: addiu       $a1, $zero, 0x22C
    ctx->r5 = ADD32(0, 0X22C);
        goto L_802266B4;
    // 0x80226694: addiu       $a1, $zero, 0x22C
    ctx->r5 = ADD32(0, 0X22C);
L_80226698:
    // 0x80226698: b           L_802266B4
    // 0x8022669C: addiu       $a1, $zero, 0x22D
    ctx->r5 = ADD32(0, 0X22D);
        goto L_802266B4;
    // 0x8022669C: addiu       $a1, $zero, 0x22D
    ctx->r5 = ADD32(0, 0X22D);
L_802266A0:
    // 0x802266A0: b           L_802266B4
    // 0x802266A4: addiu       $a1, $zero, 0x22A
    ctx->r5 = ADD32(0, 0X22A);
        goto L_802266B4;
    // 0x802266A4: addiu       $a1, $zero, 0x22A
    ctx->r5 = ADD32(0, 0X22A);
L_802266A8:
    // 0x802266A8: b           L_802266B4
    // 0x802266AC: addiu       $a1, $zero, 0x22F
    ctx->r5 = ADD32(0, 0X22F);
        goto L_802266B4;
    // 0x802266AC: addiu       $a1, $zero, 0x22F
    ctx->r5 = ADD32(0, 0X22F);
L_802266B0:
    // 0x802266B0: addiu       $a1, $zero, 0x230
    ctx->r5 = ADD32(0, 0X230);
L_802266B4:
    // 0x802266B4: jal         0x80020718
    // 0x802266B8: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x802266B8: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_2:
    // 0x802266BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802266C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x802266C4: jr          $ra
    // 0x802266C8: nop

    return;
    // 0x802266C8: nop

;}
RECOMP_FUNC void M10_FUN_802266cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802266CC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802266D0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x802266D4: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802266d8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802266d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802266D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802266DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802266E0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x802266E4: beq         $a0, $v0, L_802266F4
    if (ctx->r4 == ctx->r2) {
        // 0x802266E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_802266F4;
    }
    // 0x802266E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802266EC: b           L_802266F8
    // 0x802266F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_802266F8;
    // 0x802266F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_802266F4:
    // 0x802266F4: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_802266F8:
    // 0x802266F8: jal         0x802264D0
    // 0x802266FC: nop

    LOOKUP_FUNC(0x802264D0)(rdram, ctx);
        goto after_0;
    // 0x802266FC: nop

    after_0:
    // 0x80226700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80226704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80226708: jr          $ra
    // 0x8022670C: nop

    return;
    // 0x8022670C: nop

;}
RECOMP_FUNC void M10_FUN_80226710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226710: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80226714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80226718: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8022671C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80226720: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80226724: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80226728: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x8022672C: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80226730: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80226734: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80226738: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8022673C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80226740: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80226744: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80226748: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8022674C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80226750: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x80226754: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x80226758: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8022675C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80226760: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x80226764: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x80226768: jal         0x801DC9C4
    // 0x8022676C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_0;
    // 0x8022676C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80226770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80226774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80226778: jr          $ra
    // 0x8022677C: nop

    return;
    // 0x8022677C: nop

;}
RECOMP_FUNC void M10_FUN_80226780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226780: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80226784: lhu         $t6, -0x43E4($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X43E4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80226788(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80226788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022678C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80226790: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80226794: beq         $t6, $at, L_802267D8
    if (ctx->r14 == ctx->r1) {
        // 0x80226798: lw          $v0, 0x5C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X5C);
            goto L_802267D8;
    }
    // 0x80226798: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8022679C: lbu         $t7, 0x74($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X74);
    // 0x802267A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802267A4: bnel        $t7, $at, L_802267DC
    if (ctx->r15 != ctx->r1) {
        // 0x802267A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802267DC;
    }
    goto skip_0;
    // 0x802267A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x802267AC: lhu         $t8, 0x36($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X36);
    // 0x802267B0: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x802267B4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802267B8: bne         $t8, $at, L_802267D8
    if (ctx->r24 != ctx->r1) {
        // 0x802267BC: addiu       $a1, $a1, -0x3708
        ctx->r5 = ADD32(ctx->r5, -0X3708);
            goto L_802267D8;
    }
    // 0x802267BC: addiu       $a1, $a1, -0x3708
    ctx->r5 = ADD32(ctx->r5, -0X3708);
    // 0x802267C0: jal         0x80005670
    // 0x802267C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x802267C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x802267C8: beq         $v0, $zero, L_802267D8
    if (ctx->r2 == 0) {
        // 0x802267CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_802267D8;
    }
    // 0x802267CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x802267D0: sh          $zero, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = 0;
    // 0x802267D4: sw          $a0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r4;
L_802267D8:
    // 0x802267D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802267DC:
    // 0x802267DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802267E0: jr          $ra
    // 0x802267E4: nop

    return;
    // 0x802267E4: nop

;}
RECOMP_FUNC void M10_FUN_802267e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802267E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802267EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802267F0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x802267F4: lbu         $a1, -0x33DF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X33DF);
    // 0x802267F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802267FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80226800: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80226804: bne         $at, $zero, L_80226818
    if (ctx->r1 != 0) {
        // 0x80226808: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_80226818;
    }
    // 0x80226808: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022680C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80226810: bne         $a1, $at, L_80226864
    if (ctx->r5 != ctx->r1) {
        // 0x80226814: nop
    
            goto L_80226864;
    }
    // 0x80226814: nop

L_80226818:
    // 0x80226818: lh          $t6, -0x3C26($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X3C26);
    // 0x8022681C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80226820: blez        $t6, L_80226864
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80226824: nop
    
            goto L_80226864;
    }
    // 0x80226824: nop

    // 0x80226828: lw          $t7, -0x3BF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3BF8);
    // 0x8022682C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80226830: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80226834: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80226838: bne         $t9, $zero, L_80226864
    if (ctx->r25 != 0) {
        // 0x8022683C: nop
    
            goto L_80226864;
    }
    // 0x8022683C: nop

    // 0x80226840: lh          $t0, -0x3FC2($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X3FC2);
    // 0x80226844: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80226848: blez        $t0, L_80226864
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8022684C: nop
    
            goto L_80226864;
    }
    // 0x8022684C: nop

    // 0x80226850: lw          $t1, -0x3F94($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3F94);
    // 0x80226854: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80226858: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x8022685C: beql        $t3, $zero, L_80226888
    if (ctx->r11 == 0) {
        // 0x80226860: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80226888;
    }
    goto skip_0;
    // 0x80226860: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_0:
L_80226864:
    // 0x80226864: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80226868: addiu       $a1, $a1, 0x693C
    ctx->r5 = ADD32(ctx->r5, 0X693C);
    // 0x8022686C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80226870: jal         0x800058DC
    // 0x80226874: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80226874: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80226878: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8022687C: lbu         $a1, -0x33DF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X33DF);
    // 0x80226880: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80226884: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_80226888:
    // 0x80226888: bne         $a1, $at, L_802268D4
    if (ctx->r5 != ctx->r1) {
        // 0x8022688C: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_802268D4;
    }
    // 0x8022688C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80226890: lbu         $v1, -0x3CEB($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X3CEB);
    // 0x80226894: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80226898: beq         $v1, $at, L_802268D4
    if (ctx->r3 == ctx->r1) {
        // 0x8022689C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_802268D4;
    }
    // 0x8022689C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x802268A0: beq         $v1, $at, L_802268D4
    if (ctx->r3 == ctx->r1) {
        // 0x802268A4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_802268D4;
    }
    // 0x802268A4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x802268A8: beq         $v1, $at, L_802268D4
    if (ctx->r3 == ctx->r1) {
        // 0x802268AC: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_802268D4;
    }
    // 0x802268AC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x802268B0: beq         $v1, $at, L_802268D4
    if (ctx->r3 == ctx->r1) {
        // 0x802268B4: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_802268D4;
    }
    // 0x802268B4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x802268B8: beq         $v1, $at, L_802268D4
    if (ctx->r3 == ctx->r1) {
        // 0x802268BC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_802268D4;
    }
    // 0x802268BC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x802268C0: beql        $v1, $at, L_802268D8
    if (ctx->r3 == ctx->r1) {
        // 0x802268C4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_802268D8;
    }
    goto skip_1;
    // 0x802268C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
    // 0x802268C8: sh          $zero, 0x6C($a3)
    MEM_H(0X6C, ctx->r7) = 0;
    // 0x802268CC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x802268D0: lbu         $a1, -0x33DF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X33DF);
L_802268D4:
    // 0x802268D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_802268D8:
    // 0x802268D8: bne         $a1, $at, L_8022692C
    if (ctx->r5 != ctx->r1) {
        // 0x802268DC: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_8022692C;
    }
    // 0x802268DC: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x802268E0: lw          $t4, -0x3BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3BF8);
    // 0x802268E4: addiu       $v0, $a3, 0x6C
    ctx->r2 = ADD32(ctx->r7, 0X6C);
    // 0x802268E8: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x802268EC: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x802268F0: bnel        $t6, $zero, L_80226930
    if (ctx->r14 != 0) {
        // 0x802268F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80226930;
    }
    goto skip_2;
    // 0x802268F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x802268F8: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x802268FC: addiu       $a1, $zero, 0x507
    ctx->r5 = ADD32(0, 0X507);
    // 0x80226900: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80226904: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80226908: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8022690C: slti        $at, $t9, 0x12D
    ctx->r1 = SIGNED(ctx->r25) < 0X12D ? 1 : 0;
    // 0x80226910: bne         $at, $zero, L_8022692C
    if (ctx->r1 != 0) {
        // 0x80226914: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_8022692C;
    }
    // 0x80226914: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80226918: lw          $a0, 0xC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC);
    // 0x8022691C: jal         0x80226710
    // 0x80226920: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80226710)(rdram, ctx);
        goto after_1;
    // 0x80226920: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80226924: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80226928: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_8022692C:
    // 0x8022692C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80226930:
    // 0x80226930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80226934: jr          $ra
    // 0x80226938: nop

    return;
    // 0x80226938: nop

;}
RECOMP_FUNC void M10_FUN_8022693c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022693C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80226940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80226944: jal         0x80005700
    // 0x80226948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80226948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8022694C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80226950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80226954: jr          $ra
    // 0x80226958: nop

    return;
    // 0x80226958: nop

;}
RECOMP_FUNC void M10_FUN_8022695c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022695C: jr          $ra
    // 0x80226960: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80226960: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80226964(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80226964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226964: jr          $ra
    // 0x80226968: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80226968: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022696c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022696c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022696C: jr          $ra
    // 0x80226970: nop

    return;
    // 0x80226970: nop

;}
RECOMP_FUNC void M10_FUN_80226974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226974: nop

    // 0x80226978: nop

    // 0x8022697C: nop

;}
RECOMP_FUNC void M10_FUN_80226980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226980: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80226984: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80226988: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8022698C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80226990: lbu         $t6, 0x7DC($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7DC);
    // 0x80226994: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80226998: beq         $t6, $zero, L_802269A8
    if (ctx->r14 == 0) {
            // 0x8022699C: nop

    LOOKUP_FUNC(0x802269A8)(rdram, ctx);
    return;
    }
    // 0x8022699C: nop

    // 0x802269A0: jr          $ra
    // 0x802269A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x802269A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802269a8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802269a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802269A8: jr          $ra
    // 0x802269AC: nop

    return;
    // 0x802269AC: nop

;}
RECOMP_FUNC void M10_FUN_802269b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802269B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802269B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x802269B8: jr          $ra
    // 0x802269BC: sb          $a0, -0x36E0($at)
    MEM_B(-0X36E0, ctx->r1) = ctx->r4;
    return;
    // 0x802269BC: sb          $a0, -0x36E0($at)
    MEM_B(-0X36E0, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802269c0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802269c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802269C0: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x802269C4: jr          $ra
    // 0x802269C8: lbu         $v0, -0x36E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X36E0);
    return;
    // 0x802269C8: lbu         $v0, -0x36E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X36E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802269cc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802269cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802269CC: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x802269D0: jr          $ra
    // 0x802269D4: lbu         $v0, 0x7DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7DA);
    return;
    // 0x802269D4: lbu         $v0, 0x7DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7DA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802269d8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802269d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802269D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802269DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802269E0: jal         0x80126944
    // 0x802269E4: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x802269E4: nop

    after_0:
    // 0x802269E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802269EC: bne         $v0, $at, L_802269FC
    if (ctx->r2 != ctx->r1) {
        // 0x802269F0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_802269FC;
    }
    // 0x802269F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x802269F4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802269F8: sb          $zero, 0x7DA($at)
    MEM_B(0X7DA, ctx->r1) = 0;
L_802269FC:
    // 0x802269FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80226A00: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x80226A04: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80226A08: beq         $v0, $at, L_80226A14
    if (ctx->r2 == ctx->r1) {
        // 0x80226A0C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80226A14;
    }
    // 0x80226A0C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80226A10: bne         $v0, $at, L_80226A1C
    if (ctx->r2 != ctx->r1) {
        // 0x80226A14: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_80226A1C;
    }
L_80226A14:
    // 0x80226A14: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80226A18: sb          $t6, 0x7DA($at)
    MEM_B(0X7DA, ctx->r1) = ctx->r14;
L_80226A1C:
    // 0x80226A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80226A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80226A24: jr          $ra
    // 0x80226A28: nop

    return;
    // 0x80226A28: nop

;}
RECOMP_FUNC void M10_FUN_80226a2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226A2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80226A30: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80226A34: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80226A38: addiu       $s1, $s1, -0x1398
    ctx->r17 = ADD32(ctx->r17, -0X1398);
    // 0x80226A3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80226A40: lbu         $s0, 0x1E($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X1E);
    // 0x80226A44: lbu         $t6, 0x1F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1F);
    // 0x80226A48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80226A4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80226A50: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80226A54: beq         $at, $zero, L_80226A8C
    if (ctx->r1 == 0) {
        // 0x80226A58: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80226A8C;
    }
    // 0x80226A58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80226A5C:
    // 0x80226A5C: jal         0x802269CC
    // 0x80226A60: nop

    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_0;
    // 0x80226A60: nop

    after_0:
    // 0x80226A64: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80226A68: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80226A6C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80226A70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80226A74: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80226A78: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
    // 0x80226A7C: lbu         $t0, 0x1F($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1F);
    // 0x80226A80: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80226A84: bne         $at, $zero, L_80226A5C
    if (ctx->r1 != 0) {
        // 0x80226A88: nop
    
            goto L_80226A5C;
    }
    // 0x80226A88: nop

L_80226A8C:
    // 0x80226A8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80226A90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80226A94: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80226A98: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80226A9C: jr          $ra
    // 0x80226AA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80226AA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80226aa4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80226aa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80226AA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80226AA8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80226AAC: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x80226AB0: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x80226AB4: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80226AB8: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80226ABC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80226AC0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80226AC4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80226AC8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80226ACC: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80226AD0: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x80226AD4: addiu       $s7, $s7, -0x1398
    ctx->r23 = ADD32(ctx->r23, -0X1398);
    // 0x80226AD8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80226ADC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80226AE0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80226AE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80226AE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80226AEC: sb          $t6, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r14;
L_80226AF0:
    // 0x80226AF0: jal         0x80006214
    // 0x80226AF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x80226AF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x80226AF8: jal         0x80147598
    // 0x80226AFC: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_1;
    // 0x80226AFC: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    after_1:
    // 0x80226B00: beq         $v0, $zero, L_80226B6C
    if (ctx->r2 == 0) {
        // 0x80226B04: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80226B6C;
    }
    // 0x80226B04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226B08: sll         $a3, $s0, 6
    ctx->r7 = S32(ctx->r16 << 6);
    // 0x80226B0C: addiu       $a3, $a3, 0x144
    ctx->r7 = ADD32(ctx->r7, 0X144);
    // 0x80226B10: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80226B14: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x80226B18: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80226B1C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80226B20: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80226B24: addiu       $t1, $zero, 0x20C
    ctx->r9 = ADD32(0, 0X20C);
    // 0x80226B28: addiu       $t2, $s0, 0x2
    ctx->r10 = ADD32(ctx->r16, 0X2);
    // 0x80226B2C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80226B30: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80226B34: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80226B38: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80226B3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80226B40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80226B44: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80226B48: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226B4C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226B50: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80226B54: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226B58: jal         0x80146208
    // 0x80226B5C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x80226B5C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x80226B60: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226B64: b           L_80226BC4
    // 0x80226B68: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
        goto L_80226BC4;
    // 0x80226B68: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
L_80226B6C:
    // 0x80226B6C: sll         $a3, $s0, 6
    ctx->r7 = S32(ctx->r16 << 6);
    // 0x80226B70: addiu       $a3, $a3, 0x144
    ctx->r7 = ADD32(ctx->r7, 0X144);
    // 0x80226B74: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80226B78: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x80226B7C: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80226B80: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80226B84: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80226B88: addiu       $t7, $zero, 0x20A
    ctx->r15 = ADD32(0, 0X20A);
    // 0x80226B8C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80226B90: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80226B94: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80226B98: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80226B9C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80226BA0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80226BA4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226BA8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80226BAC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226BB0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80226BB4: jal         0x80146208
    // 0x80226BB8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x80226BB8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    after_3:
    // 0x80226BBC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226BC0: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
L_80226BC4:
    // 0x80226BC4: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80226BC8: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x80226BCC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80226BD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80226BD4: jal         0x80145310
    // 0x80226BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_4;
    // 0x80226BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80226BDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80226BE0: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80226BE4: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80226BE8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80226BEC: bne         $at, $zero, L_80226AF0
    if (ctx->r1 != 0) {
        // 0x80226BF0: nop
    
            goto L_80226AF0;
    }
    // 0x80226BF0: nop

    // 0x80226BF4: lbu         $t0, 0x0($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X0);
    // 0x80226BF8: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80226BFC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80226C00: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80226C04: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80226C08: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80226C0C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80226C10: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80226C14: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80226C18: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80226C1C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80226C20: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80226C24: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226C28: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226C2C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226C30: addiu       $a2, $zero, 0x16C
    ctx->r6 = ADD32(0, 0X16C);
    // 0x80226C34: addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    // 0x80226C38: jal         0x80146178
    // 0x80226C3C: sb          $t0, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r8;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_5;
    // 0x80226C3C: sb          $t0, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r8;
    after_5:
    // 0x80226C40: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80226C44: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226C48: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x80226C4C: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80226C50: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80226C54: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80226C58: addiu       $t1, $zero, 0x209
    ctx->r9 = ADD32(0, 0X209);
    // 0x80226C5C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80226C60: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226C64: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80226C68: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80226C6C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80226C70: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80226C74: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80226C78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80226C7C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80226C80: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226C84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226C88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226C8C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80226C90: addiu       $a3, $zero, 0x16C
    ctx->r7 = ADD32(0, 0X16C);
    // 0x80226C94: jal         0x80146208
    // 0x80226C98: sb          $t6, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x80226C98: sb          $t6, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r14;
    after_6:
    // 0x80226C9C: lbu         $t3, 0x4($s7)
    ctx->r11 = MEM_BU(ctx->r23, 0X4);
    // 0x80226CA0: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226CA4: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226CA8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80226CAC: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80226CB0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80226CB4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80226CB8: jal         0x80145310
    // 0x80226CBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_7;
    // 0x80226CBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x80226CC0: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80226CC4: addiu       $t7, $zero, 0x77
    ctx->r15 = ADD32(0, 0X77);
    // 0x80226CC8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80226CCC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80226CD0: addiu       $t0, $zero, 0xFA
    ctx->r8 = ADD32(0, 0XFA);
    // 0x80226CD4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80226CD8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80226CDC: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80226CE0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80226CE4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80226CE8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80226CEC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80226CF0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80226CF4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80226CF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80226CFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226D00: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226D04: addiu       $a2, $zero, 0x16C
    ctx->r6 = ADD32(0, 0X16C);
    // 0x80226D08: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80226D0C: jal         0x80146178
    // 0x80226D10: sb          $t6, 0x1($s7)
    MEM_B(0X1, ctx->r23) = ctx->r14;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_8;
    // 0x80226D10: sb          $t6, 0x1($s7)
    MEM_B(0X1, ctx->r23) = ctx->r14;
    after_8:
    // 0x80226D14: lbu         $t4, 0x0($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X0);
    // 0x80226D18: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226D1C: addiu       $t5, $zero, 0x77
    ctx->r13 = ADD32(0, 0X77);
    // 0x80226D20: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80226D24: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80226D28: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80226D2C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80226D30: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80226D34: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226D38: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80226D3C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80226D40: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80226D44: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80226D48: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80226D4C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80226D50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80226D54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226D58: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226D5C: addiu       $a2, $zero, 0x16C
    ctx->r6 = ADD32(0, 0X16C);
    // 0x80226D60: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80226D64: jal         0x80146178
    // 0x80226D68: sb          $t4, 0x2($s7)
    MEM_B(0X2, ctx->r23) = ctx->r12;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_9;
    // 0x80226D68: sb          $t4, 0x2($s7)
    MEM_B(0X2, ctx->r23) = ctx->r12;
    after_9:
    // 0x80226D6C: lbu         $t1, 0x0($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X0);
    // 0x80226D70: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226D74: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226D78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80226D7C: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x80226D80: sb          $t1, 0x1C($s7)
    MEM_B(0X1C, ctx->r23) = ctx->r9;
L_80226D84:
    // 0x80226D84: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80226D88: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80226D8C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80226D90: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80226D94: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80226D98: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80226D9C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80226DA0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80226DA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80226DA8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226DAC: mflo        $a2
    ctx->r6 = lo;
    // 0x80226DB0: addiu       $a2, $a2, 0x16C
    ctx->r6 = ADD32(ctx->r6, 0X16C);
    // 0x80226DB4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80226DB8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80226DBC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226DC0: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80226DC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80226DC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226DCC: jal         0x80146178
    // 0x80226DD0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_10;
    // 0x80226DD0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_10:
    // 0x80226DD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80226DD8: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80226DDC: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80226DE0: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80226DE4: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226DE8: bne         $at, $zero, L_80226D84
    if (ctx->r1 != 0) {
        // 0x80226DEC: andi        $s2, $s2, 0xFF
        ctx->r18 = ctx->r18 & 0XFF;
            goto L_80226D84;
    }
    // 0x80226DEC: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226DF0: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80226DF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80226DF8: sb          $t6, 0x1A($s7)
    MEM_B(0X1A, ctx->r23) = ctx->r14;
L_80226DFC:
    // 0x80226DFC: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80226E00: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x80226E04: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80226E08: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80226E0C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80226E10: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80226E14: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80226E18: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80226E1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80226E20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226E24: mflo        $a2
    ctx->r6 = lo;
    // 0x80226E28: addiu       $a2, $a2, 0x16C
    ctx->r6 = ADD32(ctx->r6, 0X16C);
    // 0x80226E2C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80226E30: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80226E34: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226E38: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80226E3C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80226E40: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80226E44: jal         0x80146178
    // 0x80226E48: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_11;
    // 0x80226E48: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_11:
    // 0x80226E4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80226E50: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80226E54: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80226E58: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80226E5C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226E60: bne         $at, $zero, L_80226DFC
    if (ctx->r1 != 0) {
        // 0x80226E64: andi        $s2, $s2, 0xFF
        ctx->r18 = ctx->r18 & 0XFF;
            goto L_80226DFC;
    }
    // 0x80226E64: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226E68: jal         0x80147598
    // 0x80226E6C: nop

    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_12;
    // 0x80226E6C: nop

    after_12:
    // 0x80226E70: bne         $v0, $zero, L_80226EDC
    if (ctx->r2 != 0) {
        // 0x80226E74: nop
    
            goto L_80226EDC;
    }
    // 0x80226E74: nop

    // 0x80226E78: lbu         $t1, 0x0($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X0);
    // 0x80226E7C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80226E80: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x80226E84: addiu       $t2, $zero, 0x2D
    ctx->r10 = ADD32(0, 0X2D);
    // 0x80226E88: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80226E8C: lhu         $a2, 0x44E($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X44E);
    // 0x80226E90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226E94: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80226E98: addiu       $a3, $zero, 0x193
    ctx->r7 = ADD32(0, 0X193);
    // 0x80226E9C: jal         0x801465A0
    // 0x80226EA0: sb          $t1, 0x6($s7)
    MEM_B(0X6, ctx->r23) = ctx->r9;
    LOOKUP_FUNC(0x801465A0)(rdram, ctx);
        goto after_13;
    // 0x80226EA0: sb          $t1, 0x6($s7)
    MEM_B(0X6, ctx->r23) = ctx->r9;
    after_13:
    // 0x80226EA4: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x80226EA8: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x80226EAC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226EB0: addiu       $t5, $t3, 0x4
    ctx->r13 = ADD32(ctx->r11, 0X4);
    // 0x80226EB4: sb          $t5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r13;
    // 0x80226EB8: sb          $t5, 0x7($s7)
    MEM_B(0X7, ctx->r23) = ctx->r13;
    // 0x80226EBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80226EC0: lhu         $a2, 0x44C($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X44C);
    // 0x80226EC4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80226EC8: jal         0x801465A0
    // 0x80226ECC: addiu       $a3, $zero, 0x1BB
    ctx->r7 = ADD32(0, 0X1BB);
    LOOKUP_FUNC(0x801465A0)(rdram, ctx);
        goto after_14;
    // 0x80226ECC: addiu       $a3, $zero, 0x1BB
    ctx->r7 = ADD32(0, 0X1BB);
    after_14:
    // 0x80226ED0: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    // 0x80226ED4: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80226ED8: sb          $t8, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r24;
L_80226EDC:
    // 0x80226EDC: jal         0x80147598
    // 0x80226EE0: nop

    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_15;
    // 0x80226EE0: nop

    after_15:
    // 0x80226EE4: beql        $v0, $zero, L_80227008
    if (ctx->r2 == 0) {
        // 0x80226EE8: lbu         $t7, 0x0($s3)
        ctx->r15 = MEM_BU(ctx->r19, 0X0);
            goto L_80227008;
    }
    goto skip_0;
    // 0x80226EE8: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    skip_0:
    // 0x80226EEC: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80226EF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226EF4: jal         0x80006214
    // 0x80226EF8: sb          $t9, 0xA($s7)
    MEM_B(0XA, ctx->r23) = ctx->r25;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_16;
    // 0x80226EF8: sb          $t9, 0xA($s7)
    MEM_B(0XA, ctx->r23) = ctx->r25;
    after_16:
    // 0x80226EFC: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x80226F00: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80226F04: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80226F08: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80226F0C: addiu       $t4, $zero, 0x209
    ctx->r12 = ADD32(0, 0X209);
    // 0x80226F10: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80226F14: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80226F18: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80226F1C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80226F20: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80226F24: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80226F28: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226F2C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226F30: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80226F34: addiu       $a3, $zero, 0x147
    ctx->r7 = ADD32(0, 0X147);
    // 0x80226F38: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226F3C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80226F40: jal         0x80146208
    // 0x80226F44: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_17;
    // 0x80226F44: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_17:
    // 0x80226F48: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80226F4C: addu        $v1, $s6, $t5
    ctx->r3 = ADD32(ctx->r22, ctx->r13);
    // 0x80226F50: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80226F54: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x80226F58: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226F5C: sh          $t6, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r14;
    // 0x80226F60: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226F64: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80226F68: jal         0x801451C0
    // 0x80226F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_18;
    // 0x80226F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80226F70: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80226F74: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x80226F78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80226F7C: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80226F80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80226F84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80226F8C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80226F90: lui         $a3, 0x43AB
    ctx->r7 = S32(0X43AB << 16);
    // 0x80226F94: sb          $t8, 0xB($s7)
    MEM_B(0XB, ctx->r23) = ctx->r24;
    // 0x80226F98: jal         0x80146894
    // 0x80226F9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80146894)(rdram, ctx);
        goto after_19;
    // 0x80226F9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x80226FA0: lbu         $t0, 0x0($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X0);
    // 0x80226FA4: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80226FA8: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x80226FAC: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80226FB0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80226FB4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80226FB8: addiu       $t5, $zero, 0x209
    ctx->r13 = ADD32(0, 0X209);
    // 0x80226FBC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80226FC0: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80226FC4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80226FC8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80226FCC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80226FD0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80226FD4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80226FD8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80226FDC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80226FE0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80226FE4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80226FE8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80226FEC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80226FF0: addiu       $a3, $zero, 0x147
    ctx->r7 = ADD32(0, 0X147);
    // 0x80226FF4: jal         0x80146208
    // 0x80226FF8: sb          $t0, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r8;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_20;
    // 0x80226FF8: sb          $t0, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r8;
    after_20:
    // 0x80226FFC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227000: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80227004: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
L_80227008:
    // 0x80227008: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8022700C: sb          $t7, 0x1E($s7)
    MEM_B(0X1E, ctx->r23) = ctx->r15;
    // 0x80227010: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x80227014: sb          $t8, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r24;
L_80227018:
    // 0x80227018: jal         0x80006214
    // 0x8022701C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_21;
    // 0x8022701C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_21:
    // 0x80227020: sll         $a3, $s0, 6
    ctx->r7 = S32(ctx->r16 << 6);
    // 0x80227024: addiu       $a3, $a3, -0xC4
    ctx->r7 = ADD32(ctx->r7, -0XC4);
    // 0x80227028: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8022702C: addiu       $t9, $zero, 0xB9
    ctx->r25 = ADD32(0, 0XB9);
    // 0x80227030: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x80227034: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80227038: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8022703C: addiu       $t3, $zero, 0x20C
    ctx->r11 = ADD32(0, 0X20C);
    // 0x80227040: addiu       $t4, $s0, 0x5
    ctx->r12 = ADD32(ctx->r16, 0X5);
    // 0x80227044: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80227048: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8022704C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80227050: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80227054: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80227058: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8022705C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80227060: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80227064: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80227068: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8022706C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80227070: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80227074: jal         0x80146208
    // 0x80227078: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_22;
    // 0x80227078: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_22:
    // 0x8022707C: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80227080: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227084: addu        $t6, $s6, $t5
    ctx->r14 = ADD32(ctx->r22, ctx->r13);
    // 0x80227088: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8022708C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80227090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80227094: jal         0x80145310
    // 0x80227098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_23;
    // 0x80227098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x8022709C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x802270A0: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802270A4: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x802270A8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x802270AC: bne         $at, $zero, L_80227018
    if (ctx->r1 != 0) {
        // 0x802270B0: nop
    
            goto L_80227018;
    }
    // 0x802270B0: nop

    // 0x802270B4: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    // 0x802270B8: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x802270BC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x802270C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x802270C4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x802270C8: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x802270CC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x802270D0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x802270D4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x802270D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x802270DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x802270E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x802270E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x802270E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802270EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x802270F0: addiu       $a2, $zero, -0x7C
    ctx->r6 = ADD32(0, -0X7C);
    // 0x802270F4: addiu       $a3, $zero, 0xCA
    ctx->r7 = ADD32(0, 0XCA);
    // 0x802270F8: jal         0x80146178
    // 0x802270FC: sb          $t7, 0x12($s7)
    MEM_B(0X12, ctx->r23) = ctx->r15;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_24;
    // 0x802270FC: sb          $t7, 0x12($s7)
    MEM_B(0X12, ctx->r23) = ctx->r15;
    after_24:
    // 0x80227100: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x80227104: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227108: addiu       $t4, $zero, 0xCA
    ctx->r12 = ADD32(0, 0XCA);
    // 0x8022710C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80227110: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80227114: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80227118: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8022711C: addiu       $t9, $zero, 0x209
    ctx->r25 = ADD32(0, 0X209);
    // 0x80227120: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80227124: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80227128: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8022712C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80227130: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80227134: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80227138: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8022713C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80227140: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80227144: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80227148: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8022714C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80227150: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x80227154: addiu       $a3, $zero, -0x7C
    ctx->r7 = ADD32(0, -0X7C);
    // 0x80227158: jal         0x80146208
    // 0x8022715C: sb          $t3, 0x11($s7)
    MEM_B(0X11, ctx->r23) = ctx->r11;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_25;
    // 0x8022715C: sb          $t3, 0x11($s7)
    MEM_B(0X11, ctx->r23) = ctx->r11;
    after_25:
    // 0x80227160: lbu         $t1, 0x11($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X11);
    // 0x80227164: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227168: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8022716C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80227170: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80227174: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80227178: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8022717C: jal         0x80145310
    // 0x80227180: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_26;
    // 0x80227180: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_26:
    // 0x80227184: lbu         $t4, 0x0($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X0);
    // 0x80227188: addiu       $t5, $zero, 0x77
    ctx->r13 = ADD32(0, 0X77);
    // 0x8022718C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80227190: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80227194: addiu       $t8, $zero, 0xFA
    ctx->r24 = ADD32(0, 0XFA);
    // 0x80227198: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8022719C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x802271A0: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x802271A4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x802271A8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x802271AC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x802271B0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x802271B4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x802271B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x802271BC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x802271C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802271C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x802271C8: addiu       $a2, $zero, -0xA3
    ctx->r6 = ADD32(0, -0XA3);
    // 0x802271CC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x802271D0: jal         0x80146178
    // 0x802271D4: sb          $t4, 0xE($s7)
    MEM_B(0XE, ctx->r23) = ctx->r12;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_27;
    // 0x802271D4: sb          $t4, 0xE($s7)
    MEM_B(0XE, ctx->r23) = ctx->r12;
    after_27:
    // 0x802271D8: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
    // 0x802271DC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x802271E0: addiu       $t3, $zero, 0x77
    ctx->r11 = ADD32(0, 0X77);
    // 0x802271E4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x802271E8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x802271EC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x802271F0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x802271F4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x802271F8: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x802271FC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80227200: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80227204: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80227208: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8022720C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80227210: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80227214: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80227218: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8022721C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80227220: addiu       $a2, $zero, -0xA3
    ctx->r6 = ADD32(0, -0XA3);
    // 0x80227224: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x80227228: jal         0x80146178
    // 0x8022722C: sb          $t2, 0xF($s7)
    MEM_B(0XF, ctx->r23) = ctx->r10;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_28;
    // 0x8022722C: sb          $t2, 0xF($s7)
    MEM_B(0XF, ctx->r23) = ctx->r10;
    after_28:
    // 0x80227230: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80227234: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227238: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8022723C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80227240: addiu       $s1, $zero, -0x48
    ctx->r17 = ADD32(0, -0X48);
    // 0x80227244: sb          $t9, 0x1D($s7)
    MEM_B(0X1D, ctx->r23) = ctx->r25;
L_80227248:
    // 0x80227248: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8022724C: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80227250: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80227254: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80227258: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8022725C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80227260: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80227264: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80227268: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8022726C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80227270: mflo        $t0
    ctx->r8 = lo;
    // 0x80227274: subu        $a2, $s1, $t0
    ctx->r6 = SUB32(ctx->r17, ctx->r8);
    // 0x80227278: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022727C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80227280: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80227284: addiu       $a3, $zero, 0xD6
    ctx->r7 = ADD32(0, 0XD6);
    // 0x80227288: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8022728C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80227290: jal         0x80146178
    // 0x80227294: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_29;
    // 0x80227294: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_29:
    // 0x80227298: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8022729C: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802272A0: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x802272A4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x802272A8: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x802272AC: bne         $at, $zero, L_80227248
    if (ctx->r1 != 0) {
        // 0x802272B0: andi        $s2, $s2, 0xFF
        ctx->r18 = ctx->r18 & 0XFF;
            goto L_80227248;
    }
    // 0x802272B0: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x802272B4: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x802272B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x802272BC: sb          $t5, 0x1B($s7)
    MEM_B(0X1B, ctx->r23) = ctx->r13;
L_802272C0:
    // 0x802272C0: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802272C4: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x802272C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x802272CC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x802272D0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x802272D4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x802272D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x802272DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x802272E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x802272E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802272E8: mflo        $t6
    ctx->r14 = lo;
    // 0x802272EC: subu        $a2, $s1, $t6
    ctx->r6 = SUB32(ctx->r17, ctx->r14);
    // 0x802272F0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802272F4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802272F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x802272FC: addiu       $a3, $zero, 0xD6
    ctx->r7 = ADD32(0, 0XD6);
    // 0x80227300: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80227304: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80227308: jal         0x80146178
    // 0x8022730C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_30;
    // 0x8022730C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_30:
    // 0x80227310: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80227314: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80227318: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8022731C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80227320: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227324: bne         $at, $zero, L_802272C0
    if (ctx->r1 != 0) {
        // 0x80227328: andi        $s2, $s2, 0xFF
        ctx->r18 = ctx->r18 & 0XFF;
            goto L_802272C0;
    }
    // 0x80227328: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8022732C: lbu         $t1, 0x0($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X0);
    // 0x80227330: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80227334: jal         0x80006214
    // 0x80227338: sb          $t1, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r9;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_31;
    // 0x80227338: sb          $t1, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r9;
    after_31:
    // 0x8022733C: addiu       $t2, $zero, 0xBB
    ctx->r10 = ADD32(0, 0XBB);
    // 0x80227340: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80227344: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80227348: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8022734C: addiu       $t6, $zero, 0x209
    ctx->r14 = ADD32(0, 0X209);
    // 0x80227350: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80227354: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80227358: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8022735C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80227360: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80227364: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80227368: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8022736C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80227370: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80227374: addiu       $a3, $zero, -0x27
    ctx->r7 = ADD32(0, -0X27);
    // 0x80227378: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8022737C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80227380: jal         0x80146208
    // 0x80227384: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_32;
    // 0x80227384: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_32:
    // 0x80227388: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8022738C: addu        $v1, $s6, $t7
    ctx->r3 = ADD32(ctx->r22, ctx->r15);
    // 0x80227390: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80227394: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x80227398: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8022739C: sh          $t8, 0x28($t9)
    MEM_H(0X28, ctx->r25) = ctx->r24;
    // 0x802273A0: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x802273A4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x802273A8: jal         0x801451C0
    // 0x802273AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_33;
    // 0x802273AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x802273B0: lbu         $t0, 0x0($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X0);
    // 0x802273B4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802273B8: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x802273BC: sb          $t0, 0x18($s7)
    MEM_B(0X18, ctx->r23) = ctx->r8;
    // 0x802273C0: lwc1        $f6, -0xF70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF70);
    // 0x802273C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x802273C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802273CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802273D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x802273D4: lui         $a3, 0xC1C4
    ctx->r7 = S32(0XC1C4 << 16);
    // 0x802273D8: jal         0x80146894
    // 0x802273DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80146894)(rdram, ctx);
        goto after_34;
    // 0x802273DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_34:
    // 0x802273E0: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
    // 0x802273E4: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x802273E8: addiu       $t3, $zero, 0xBB
    ctx->r11 = ADD32(0, 0XBB);
    // 0x802273EC: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x802273F0: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x802273F4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x802273F8: addiu       $t7, $zero, 0x209
    ctx->r15 = ADD32(0, 0X209);
    // 0x802273FC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80227400: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80227404: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80227408: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8022740C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80227410: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80227414: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80227418: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8022741C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80227420: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80227424: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80227428: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8022742C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80227430: addiu       $a3, $zero, -0x27
    ctx->r7 = ADD32(0, -0X27);
    // 0x80227434: jal         0x80146208
    // 0x80227438: sb          $t2, 0x19($s7)
    MEM_B(0X19, ctx->r23) = ctx->r10;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_35;
    // 0x80227438: sb          $t2, 0x19($s7)
    MEM_B(0X19, ctx->r23) = ctx->r10;
    after_35:
    // 0x8022743C: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80227440: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80227444: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80227448: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8022744C: jal         0x80006214
    // 0x80227450: sb          $t9, 0x1F($s7)
    MEM_B(0X1F, ctx->r23) = ctx->r25;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_36;
    // 0x80227450: sb          $t9, 0x1F($s7)
    MEM_B(0X1F, ctx->r23) = ctx->r25;
    after_36:
    // 0x80227454: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80227458: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8022745C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80227460: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80227464: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80227468: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8022746C: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80227470: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80227474: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x80227478: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8022747C: jr          $ra
    // 0x80227480: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80227480: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80227484(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80227484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80227484: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80227488: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8022748C: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x80227490: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80227494: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80227498: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8022749C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x802274A0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802274A4: lh          $v0, 0xA($a1)
    ctx->r2 = MEM_H(ctx->r5, 0XA);
    // 0x802274A8: bne         $t6, $zero, L_802274C8
    if (ctx->r14 != 0) {
        // 0x802274AC: lh          $v1, 0x4A($a1)
        ctx->r3 = MEM_H(ctx->r5, 0X4A);
            goto L_802274C8;
    }
    // 0x802274AC: lh          $v1, 0x4A($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4A);
    // 0x802274B0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802274B4: addiu       $a0, $a0, -0x1398
    ctx->r4 = ADD32(ctx->r4, -0X1398);
    // 0x802274B8: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
    // 0x802274BC: lbu         $t0, 0x4($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4);
    // 0x802274C0: b           L_802274DC
    // 0x802274C4: sb          $t7, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r15;
        goto L_802274DC;
    // 0x802274C4: sb          $t7, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r15;
L_802274C8:
    // 0x802274C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802274CC: addiu       $a0, $a0, -0x1398
    ctx->r4 = ADD32(ctx->r4, -0X1398);
    // 0x802274D0: lbu         $t8, 0x12($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X12);
    // 0x802274D4: lbu         $t0, 0x11($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X11);
    // 0x802274D8: sb          $t8, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r24;
L_802274DC:
    // 0x802274DC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x802274E0: beq         $at, $zero, L_802274F8
    if (ctx->r1 == 0) {
        // 0x802274E4: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_802274F8;
    }
    // 0x802274E4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x802274E8: lh          $t9, 0x42($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X42);
    // 0x802274EC: blez        $t9, L_802274F8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x802274F0: nop
    
            goto L_802274F8;
    }
    // 0x802274F0: nop

    // 0x802274F4: sh          $v0, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r2;
L_802274F8:
    // 0x802274F8: lbu         $t1, -0x33DF($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X33DF);
    // 0x802274FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80227500: beq         $t1, $at, L_80227554
    if (ctx->r9 == ctx->r1) {
        // 0x80227504: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80227554;
    }
    // 0x80227504: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80227508: beq         $at, $zero, L_80227554
    if (ctx->r1 == 0) {
        // 0x8022750C: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80227554;
    }
    // 0x8022750C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80227510: lb          $a2, 0x5B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X5B);
    // 0x80227514: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80227518: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x8022751C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80227520: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x80227524: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80227528: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8022752C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80227530: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80227534: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80227538: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8022753C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80227540: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80227544: jal         0x801453CC
    // 0x80227548: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x80227548: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_0:
    // 0x8022754C: b           L_802275D0
    // 0x80227550: lb          $t5, 0x5B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5B);
        goto L_802275D0;
    // 0x80227550: lb          $t5, 0x5B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5B);
L_80227554:
    // 0x80227554: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80227558: beq         $at, $zero, L_80227584
    if (ctx->r1 == 0) {
        // 0x8022755C: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80227584;
    }
    // 0x8022755C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80227560: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80227564: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80227568: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8022756C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80227570: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80227574: jal         0x80145310
    // 0x80227578: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x80227578: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x8022757C: b           L_802275D0
    // 0x80227580: lb          $t5, 0x5B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5B);
        goto L_802275D0;
    // 0x80227580: lb          $t5, 0x5B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5B);
L_80227584:
    // 0x80227584: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80227588: addu        $s0, $t9, $t1
    ctx->r16 = ADD32(ctx->r25, ctx->r9);
    // 0x8022758C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80227590: jal         0x801451C0
    // 0x80227594: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_2;
    // 0x80227594: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80227598: lb          $a2, 0x5B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X5B);
    // 0x8022759C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x802275A0: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x802275A4: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x802275A8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x802275AC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x802275B0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x802275B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x802275B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x802275BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x802275C0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x802275C4: jal         0x801453CC
    // 0x802275C8: addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_3;
    // 0x802275C8: addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    after_3:
    // 0x802275CC: lb          $t5, 0x5B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5B);
L_802275D0:
    // 0x802275D0: lbu         $t7, 0x4E($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4E);
    // 0x802275D4: bne         $t5, $zero, L_80227608
    if (ctx->r13 != 0) {
        // 0x802275D8: nop
    
            goto L_80227608;
    }
    // 0x802275D8: nop

    // 0x802275DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x802275E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x802275E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x802275E8: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x802275EC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x802275F0: sb          $t9, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r25;
    // 0x802275F4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x802275F8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x802275FC: lbu         $t3, 0x22($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X22);
    // 0x80227600: b           L_80227630
    // 0x80227604: sb          $t3, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r11;
        goto L_80227630;
    // 0x80227604: sb          $t3, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r11;
L_80227608:
    // 0x80227608: jal         0x802269CC
    // 0x8022760C: nop

    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_4;
    // 0x8022760C: nop

    after_4:
    // 0x80227610: lbu         $t7, 0x4E($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4E);
    // 0x80227614: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80227618: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8022761C: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80227620: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80227624: sb          $v0, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r2;
    // 0x80227628: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8022762C: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
L_80227630:
    // 0x80227630: lh          $t1, 0xA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XA);
    // 0x80227634: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x80227638: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8022763C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80227640: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80227644: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80227648: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8022764C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80227650: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80227654: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80227658: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8022765C: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80227660: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80227664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80227668: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8022766C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80227670: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80227674: nop

    // 0x80227678: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8022767C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80227680: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80227684: addiu       $t3, $a2, 0x40
    ctx->r11 = ADD32(ctx->r6, 0X40);
    // 0x80227688: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8022768C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80227690: swc1        $f16, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f16.u32l;
    // 0x80227694: lh          $t6, 0x8($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X8);
    // 0x80227698: lh          $t5, 0x4A($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4A);
    // 0x8022769C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x802276A0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x802276A4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x802276A8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802276AC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802276B0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802276B4: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x802276B8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x802276BC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x802276C0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x802276C4: nop

    // 0x802276C8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802276CC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802276D0: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x802276D4: sh          $t9, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r25;
    // 0x802276D8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x802276DC: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x802276E0: sh          $t3, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r11;
    // 0x802276E4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x802276E8: sh          $a2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r6;
    // 0x802276EC: jal         0x801451C0
    // 0x802276F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_5;
    // 0x802276F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_5:
    // 0x802276F4: lb          $t5, 0x5B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5B);
    // 0x802276F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802276FC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80227700: bne         $t5, $at, L_8022773C
    if (ctx->r13 != ctx->r1) {
        // 0x80227704: lh          $a2, 0x4C($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X4C);
            goto L_8022773C;
    }
    // 0x80227704: lh          $a2, 0x4C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4C);
    // 0x80227708: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8022770C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80227710: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x80227714: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x80227718: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8022771C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80227720: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80227724: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80227728: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8022772C: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80227730: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80227734: subu        $t6, $t7, $t5
    ctx->r14 = SUB32(ctx->r15, ctx->r13);
    // 0x80227738: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8022773C:
    // 0x8022773C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80227740: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80227744: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80227748: jr          $ra
    // 0x8022774C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8022774C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80227750(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80227750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80227750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80227754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80227758: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x8022775C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80227760: jal         0x8012C6B4
    // 0x80227764: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80227764: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80227768: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8022776C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80227770: jal         0x8012C6B4
    // 0x80227774: sb          $v0, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80227774: sb          $v0, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r2;
    after_1:
    // 0x80227778: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8022777C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80227780: jal         0x8012C6B4
    // 0x80227784: sb          $v0, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80227784: sb          $v0, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r2;
    after_2:
    // 0x80227788: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8022778C: sb          $v0, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r2;
    // 0x80227790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80227794: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80227798: jr          $ra
    // 0x8022779C: nop

    return;
    // 0x8022779C: nop

;}
RECOMP_FUNC void M10_FUN_802277a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802277A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x802277A4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802277A8: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x802277AC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x802277B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x802277B4: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x802277B8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x802277BC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x802277C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x802277C4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x802277C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x802277CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x802277D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x802277D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x802277D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x802277DC: bne         $a2, $t7, L_8022780C
    if (ctx->r6 != ctx->r15) {
        // 0x802277E0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8022780C;
    }
    // 0x802277E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802277E4: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x802277E8: addiu       $t8, $a0, 0x98
    ctx->r24 = ADD32(ctx->r4, 0X98);
    // 0x802277EC: addiu       $t9, $a0, 0x9A
    ctx->r25 = ADD32(ctx->r4, 0X9A);
    // 0x802277F0: addiu       $t0, $a0, 0x94
    ctx->r8 = ADD32(ctx->r4, 0X94);
    // 0x802277F4: lbu         $s7, -0x137E($s7)
    ctx->r23 = MEM_BU(ctx->r23, -0X137E);
    // 0x802277F8: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x802277FC: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x80227800: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80227804: b           L_80227830
    // 0x80227808: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
        goto L_80227830;
    // 0x80227808: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8022780C:
    // 0x8022780C: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x80227810: addiu       $t1, $a0, 0x99
    ctx->r9 = ADD32(ctx->r4, 0X99);
    // 0x80227814: addiu       $t2, $a0, 0x9B
    ctx->r10 = ADD32(ctx->r4, 0X9B);
    // 0x80227818: addiu       $t3, $a0, 0x96
    ctx->r11 = ADD32(ctx->r4, 0X96);
    // 0x8022781C: lbu         $s7, -0x137D($s7)
    ctx->r23 = MEM_BU(ctx->r23, -0X137D);
    // 0x80227820: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80227824: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80227828: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8022782C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80227830:
    // 0x80227830: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x80227834: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x80227838: addiu       $t5, $t5, 0x7D0
    ctx->r13 = ADD32(ctx->r13, 0X7D0);
    // 0x8022783C: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80227840: addu        $s4, $t4, $t5
    ctx->r20 = ADD32(ctx->r12, ctx->r13);
    // 0x80227844: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80227848: addiu       $s6, $zero, 0x64
    ctx->r22 = ADD32(0, 0X64);
    // 0x8022784C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80227850:
    // 0x80227850: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80227854: lh          $t6, 0x4C($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X4C);
    // 0x80227858: addu        $s1, $s4, $s0
    ctx->r17 = ADD32(ctx->r20, ctx->r16);
    // 0x8022785C: addu        $t0, $s4, $s0
    ctx->r8 = ADD32(ctx->r20, ctx->r16);
    // 0x80227860: mflo        $t7
    ctx->r15 = lo;
    // 0x80227864: addiu       $t8, $t7, 0x64
    ctx->r24 = ADD32(ctx->r15, 0X64);
    // 0x80227868: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8022786C: bnel        $at, $zero, L_802278D0
    if (ctx->r1 != 0) {
        // 0x80227870: sb          $zero, 0x0($t0)
        MEM_B(0X0, ctx->r8) = 0;
            goto L_802278D0;
    }
    goto skip_0;
    // 0x80227870: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    skip_0:
    // 0x80227874: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80227878: bnel        $t9, $zero, L_802278D4
    if (ctx->r25 != 0) {
        // 0x8022787C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_802278D4;
    }
    goto skip_1;
    // 0x8022787C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80227880: bne         $s5, $zero, L_80227898
    if (ctx->r21 != 0) {
        // 0x80227884: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_80227898;
    }
    // 0x80227884: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80227888: jal         0x80020744
    // 0x8022788C: addiu       $a0, $zero, 0x3BE
    ctx->r4 = ADD32(0, 0X3BE);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x8022788C: addiu       $a0, $zero, 0x3BE
    ctx->r4 = ADD32(0, 0X3BE);
    after_0:
    // 0x80227890: b           L_802278C4
    // 0x80227894: nop

        goto L_802278C4;
    // 0x80227894: nop

L_80227898:
    // 0x80227898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022789C: bne         $v0, $at, L_802278C4
    if (ctx->r2 != ctx->r1) {
        // 0x802278A0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_802278C4;
    }
    // 0x802278A0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802278A4: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x802278A8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x802278AC: beq         $v0, $at, L_802278BC
    if (ctx->r2 == ctx->r1) {
        // 0x802278B0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_802278BC;
    }
    // 0x802278B0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x802278B4: bne         $v0, $at, L_802278C4
    if (ctx->r2 != ctx->r1) {
        // 0x802278B8: nop
    
            goto L_802278C4;
    }
    // 0x802278B8: nop

L_802278BC:
    // 0x802278BC: jal         0x80020744
    // 0x802278C0: addiu       $a0, $zero, 0x3BE
    ctx->r4 = ADD32(0, 0X3BE);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x802278C0: addiu       $a0, $zero, 0x3BE
    ctx->r4 = ADD32(0, 0X3BE);
    after_1:
L_802278C4:
    // 0x802278C4: b           L_802278D0
    // 0x802278C8: sb          $s2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r18;
        goto L_802278D0;
    // 0x802278C8: sb          $s2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r18;
    // 0x802278CC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_802278D0:
    // 0x802278D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_802278D4:
    // 0x802278D4: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802278D8: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x802278DC: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x802278E0: bne         $at, $zero, L_80227850
    if (ctx->r1 != 0) {
        // 0x802278E4: nop
    
            goto L_80227850;
    }
    // 0x802278E4: nop

    // 0x802278E8: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x802278EC: addiu       $t2, $t2, 0x7C8
    ctx->r10 = ADD32(ctx->r10, 0X7C8);
    // 0x802278F0: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x802278F4: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
    // 0x802278F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_802278FC:
    // 0x802278FC: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80227900: lh          $t3, 0x4C($s3)
    ctx->r11 = MEM_H(ctx->r19, 0X4C);
    // 0x80227904: sll         $t0, $s7, 2
    ctx->r8 = S32(ctx->r23 << 2);
    // 0x80227908: addu        $t1, $fp, $t0
    ctx->r9 = ADD32(ctx->r30, ctx->r8);
    // 0x8022790C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80227910: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
    // 0x80227914: addu        $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x80227918: mflo        $t4
    ctx->r12 = lo;
    // 0x8022791C: addiu       $t5, $t4, 0x64
    ctx->r13 = ADD32(ctx->r12, 0X64);
    // 0x80227920: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80227924: beq         $at, $zero, L_802279A8
    if (ctx->r1 == 0) {
        // 0x80227928: addu        $t4, $t1, $t2
        ctx->r12 = ADD32(ctx->r9, ctx->r10);
            goto L_802279A8;
    }
    // 0x80227928: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8022792C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80227930: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80227934: sll         $t2, $s7, 2
    ctx->r10 = S32(ctx->r23 << 2);
    // 0x80227938: bnel        $t7, $zero, L_80227958
    if (ctx->r15 != 0) {
        // 0x8022793C: sb          $s2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r18;
            goto L_80227958;
    }
    goto skip_2;
    // 0x8022793C: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
    skip_2:
    // 0x80227940: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
    // 0x80227944: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80227948: sb          $s2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r18;
    // 0x8022794C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80227950: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
    // 0x80227954: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_80227958:
    // 0x80227958: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
    // 0x8022795C: lh          $t0, 0x4C($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X4C);
    // 0x80227960: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80227964: beql        $at, $zero, L_802279B8
    if (ctx->r1 == 0) {
        // 0x80227968: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_802279B8;
    }
    goto skip_3;
    // 0x80227968: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x8022796C: bne         $s5, $zero, L_80227988
    if (ctx->r21 != 0) {
        // 0x80227970: addu        $v1, $fp, $t2
        ctx->r3 = ADD32(ctx->r30, ctx->r10);
            goto L_80227988;
    }
    // 0x80227970: addu        $v1, $fp, $t2
    ctx->r3 = ADD32(ctx->r30, ctx->r10);
    // 0x80227974: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80227978: addu        $t3, $v1, $t4
    ctx->r11 = ADD32(ctx->r3, ctx->r12);
    // 0x8022797C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80227980: b           L_802279B4
    // 0x80227984: sb          $s2, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r18;
        goto L_802279B4;
    // 0x80227984: sb          $s2, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r18;
L_80227988:
    // 0x80227988: jal         0x802269CC
    // 0x8022798C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_2;
    // 0x8022798C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_2:
    // 0x80227990: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80227994: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80227998: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x8022799C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x802279A0: b           L_802279B4
    // 0x802279A4: sb          $v0, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r2;
        goto L_802279B4;
    // 0x802279A4: sb          $v0, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r2;
L_802279A8:
    // 0x802279A8: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x802279AC: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x802279B0: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
L_802279B4:
    // 0x802279B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_802279B8:
    // 0x802279B8: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802279BC: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x802279C0: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x802279C4: bne         $at, $zero, L_802278FC
    if (ctx->r1 != 0) {
        // 0x802279C8: nop
    
            goto L_802278FC;
    }
    // 0x802279C8: nop

    // 0x802279CC: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x802279D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802279D4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x802279D8: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x802279DC: bnel        $t7, $at, L_80227A54
    if (ctx->r15 != ctx->r1) {
        // 0x802279E0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80227A54;
    }
    goto skip_4;
    // 0x802279E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x802279E4: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x802279E8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x802279EC: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x802279F0: beql        $at, $zero, L_80227A20
    if (ctx->r1 == 0) {
        // 0x802279F4: slti        $at, $v0, 0x28
        ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
            goto L_80227A20;
    }
    goto skip_5;
    // 0x802279F4: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    skip_5:
    // 0x802279F8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x802279FC: sll         $t2, $s7, 2
    ctx->r10 = S32(ctx->r23 << 2);
    // 0x80227A00: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80227A04: addu        $t1, $fp, $t0
    ctx->r9 = ADD32(ctx->r30, ctx->r8);
    // 0x80227A08: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80227A0C: jal         0x80227750
    // 0x80227A10: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    LOOKUP_FUNC(0x80227750)(rdram, ctx);
        goto after_3;
    // 0x80227A10: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_3:
    // 0x80227A14: b           L_80227A54
    // 0x80227A18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80227A54;
    // 0x80227A18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80227A1C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
L_80227A20:
    // 0x80227A20: bne         $at, $zero, L_80227A50
    if (ctx->r1 != 0) {
        // 0x80227A24: lw          $t3, 0x50($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X50);
            goto L_80227A50;
    }
    // 0x80227A24: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80227A28: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x80227A2C: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80227A30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80227A34: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80227A38: addu        $t6, $fp, $t7
    ctx->r14 = ADD32(ctx->r30, ctx->r15);
    // 0x80227A3C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80227A40: jal         0x801451C0
    // 0x80227A44: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_4;
    // 0x80227A44: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x80227A48: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80227A4C: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_80227A50:
    // 0x80227A50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80227A54:
    // 0x80227A54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80227A58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80227A5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80227A60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80227A64: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80227A68: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80227A6C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80227A70: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80227A74: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80227A78: jr          $ra
    // 0x80227A7C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80227A7C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80227a80(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80227a80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80227A80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80227A84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80227A88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80227A8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80227A90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80227A94: lh          $t0, 0x4C($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4C);
    // 0x80227A98: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x80227A9C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80227AA0: lw          $t2, 0x30($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X30);
    // 0x80227AA4: bne         $t0, $zero, L_80227AB8
    if (ctx->r8 != 0) {
        // 0x80227AA8: or          $t7, $a0, $zero
        ctx->r15 = ctx->r4 | 0;
            goto L_80227AB8;
    }
    // 0x80227AA8: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80227AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80227AB0: b           L_80227AF4
    // 0x80227AB4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
        goto L_80227AF4;
    // 0x80227AB4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_80227AB8:
    // 0x80227AB8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80227ABC: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x80227AC0: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x80227AC4: mflo        $a0
    ctx->r4 = lo;
    // 0x80227AC8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80227ACC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80227AD0: bne         $a2, $zero, L_80227ADC
    if (ctx->r6 != 0) {
        // 0x80227AD4: nop
    
            goto L_80227ADC;
    }
    // 0x80227AD4: nop

    // 0x80227AD8: break       7
    do_break(2149743320);
L_80227ADC:
    // 0x80227ADC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80227AE0: bne         $a2, $at, L_80227AF4
    if (ctx->r6 != ctx->r1) {
        // 0x80227AE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80227AF4;
    }
    // 0x80227AE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80227AE8: bne         $t8, $at, L_80227AF4
    if (ctx->r24 != ctx->r1) {
        // 0x80227AEC: nop
    
            goto L_80227AF4;
    }
    // 0x80227AEC: nop

    // 0x80227AF0: break       6
    do_break(2149743344);
L_80227AF4:
    // 0x80227AF4: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80227AF8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80227AFC: lh          $t3, 0x6($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X6);
    // 0x80227B00: mflo        $v0
    ctx->r2 = lo;
    // 0x80227B04: subu        $v1, $t3, $v0
    ctx->r3 = SUB32(ctx->r11, ctx->r2);
    // 0x80227B08: subu        $a1, $t0, $v0
    ctx->r5 = SUB32(ctx->r8, ctx->r2);
    // 0x80227B0C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80227B10: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80227B14: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80227B18: bgez        $v1, L_80227B24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80227B1C: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80227B24;
    }
    // 0x80227B1C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80227B20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80227B24:
    // 0x80227B24: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80227B28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80227B2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80227B30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80227B34: lui         $at, 0x42EE
    ctx->r1 = S32(0X42EE << 16);
    // 0x80227B38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80227B3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80227B40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80227B44: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80227B48: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80227B4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80227B50: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80227B54: nop

    // 0x80227B58: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80227B5C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80227B60: nop

    // 0x80227B64: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80227B68: beql        $t5, $zero, L_80227BB8
    if (ctx->r13 == 0) {
        // 0x80227B6C: mfc1        $t5, $f16
        ctx->r13 = (int32_t)ctx->f16.u32l;
            goto L_80227BB8;
    }
    goto skip_0;
    // 0x80227B6C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80227B70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80227B74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80227B78: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80227B7C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80227B80: nop

    // 0x80227B84: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80227B88: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80227B8C: nop

    // 0x80227B90: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80227B94: bne         $t5, $zero, L_80227BAC
    if (ctx->r13 != 0) {
        // 0x80227B98: nop
    
            goto L_80227BAC;
    }
    // 0x80227B98: nop

    // 0x80227B9C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80227BA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80227BA4: b           L_80227BC4
    // 0x80227BA8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80227BC4;
    // 0x80227BA8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80227BAC:
    // 0x80227BAC: b           L_80227BC4
    // 0x80227BB0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80227BC4;
    // 0x80227BB0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80227BB4: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
L_80227BB8:
    // 0x80227BB8: nop

    // 0x80227BBC: bltz        $t5, L_80227BAC
    if (SIGNED(ctx->r13) < 0) {
        // 0x80227BC0: nop
    
            goto L_80227BAC;
    }
    // 0x80227BC0: nop

L_80227BC4:
    // 0x80227BC4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80227BC8: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80227BCC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80227BD0: sh          $t5, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r13;
    // 0x80227BD4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80227BD8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80227BDC: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80227BE0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80227BE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80227BE8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80227BEC: nop

    // 0x80227BF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80227BF4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80227BF8: nop

    // 0x80227BFC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80227C00: beql        $t7, $zero, L_80227C50
    if (ctx->r15 == 0) {
        // 0x80227C04: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_80227C50;
    }
    goto skip_1;
    // 0x80227C04: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80227C08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80227C0C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80227C10: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80227C14: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80227C18: nop

    // 0x80227C1C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80227C20: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80227C24: nop

    // 0x80227C28: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80227C2C: bne         $t7, $zero, L_80227C44
    if (ctx->r15 != 0) {
        // 0x80227C30: nop
    
            goto L_80227C44;
    }
    // 0x80227C30: nop

    // 0x80227C34: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80227C38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80227C3C: b           L_80227C5C
    // 0x80227C40: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80227C5C;
    // 0x80227C40: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80227C44:
    // 0x80227C44: b           L_80227C5C
    // 0x80227C48: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80227C5C;
    // 0x80227C48: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80227C4C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_80227C50:
    // 0x80227C50: nop

    // 0x80227C54: bltz        $t7, L_80227C44
    if (SIGNED(ctx->r15) < 0) {
        // 0x80227C58: nop
    
            goto L_80227C44;
    }
    // 0x80227C58: nop

L_80227C5C:
    // 0x80227C5C: sh          $t7, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r15;
    // 0x80227C60: lh          $t9, 0x4($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X4);
    // 0x80227C64: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x80227C68: lh          $t4, 0x4($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X4);
    // 0x80227C6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80227C70: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x80227C74: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x80227C78: lh          $t5, 0x4($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X4);
    // 0x80227C7C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80227C80: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x80227C84: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80227C88: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80227C8C: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x80227C90: beq         $at, $zero, L_80227CE0
    if (ctx->r1 == 0) {
        // 0x80227C94: nop
    
            goto L_80227CE0;
    }
    // 0x80227C94: nop

    // 0x80227C98: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80227C9C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80227CA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80227CA4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80227CA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80227CAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80227CB0: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80227CB4: nop

    // 0x80227CB8: bc1f        L_80227CE0
    if (!c1cs) {
        // 0x80227CBC: nop
    
            goto L_80227CE0;
    }
    // 0x80227CBC: nop

    // 0x80227CC0: jal         0x801451C0
    // 0x80227CC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80227CC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80227CC8: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x80227CCC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80227CD0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80227CD4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80227CD8: b           L_80227D34
    // 0x80227CDC: sb          $t9, 0x7DC($at)
    MEM_B(0X7DC, ctx->r1) = ctx->r25;
        goto L_80227D34;
    // 0x80227CDC: sb          $t9, 0x7DC($at)
    MEM_B(0X7DC, ctx->r1) = ctx->r25;
L_80227CE0:
    // 0x80227CE0: bne         $v1, $a2, L_80227D1C
    if (ctx->r3 != ctx->r6) {
        // 0x80227CE4: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80227D1C;
    }
    // 0x80227CE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80227CE8: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x80227CEC: addiu       $t5, $zero, 0x22
    ctx->r13 = ADD32(0, 0X22);
    // 0x80227CF0: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80227CF4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80227CF8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80227CFC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80227D00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80227D04: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80227D08: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x80227D0C: jal         0x801453CC
    // 0x80227D10: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_1;
    // 0x80227D10: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    after_1:
    // 0x80227D14: b           L_80227D38
    // 0x80227D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80227D38;
    // 0x80227D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80227D1C:
    // 0x80227D1C: jal         0x801451C0
    // 0x80227D20: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_2;
    // 0x80227D20: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_2:
    // 0x80227D24: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x80227D28: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80227D2C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80227D30: sb          $zero, 0x7DC($at)
    MEM_B(0X7DC, ctx->r1) = 0;
L_80227D34:
    // 0x80227D34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80227D38:
    // 0x80227D38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80227D3C: jr          $ra
    // 0x80227D40: nop

    return;
    // 0x80227D40: nop

;}
RECOMP_FUNC void M10_FUN_80227d44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80227D44: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80227d48(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80227d48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80227D48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80227D4C: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x80227D50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80227D54: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x80227D58: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80227D5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80227D60: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80227D64: bne         $a2, $t7, L_80227DC8
    if (ctx->r6 != ctx->r15) {
        // 0x80227D68: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80227DC8;
    }
    // 0x80227D68: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80227D6C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80227D70: addiu       $t0, $t0, -0x1398
    ctx->r8 = ADD32(ctx->r8, -0X1398);
    // 0x80227D74: lbu         $t8, 0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1);
    // 0x80227D78: lbu         $t3, 0x2($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X2);
    // 0x80227D7C: lbu         $t7, 0xB($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XB);
    // 0x80227D80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80227D84: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x80227D88: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80227D8C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80227D90: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80227D94: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80227D98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80227D9C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80227DA0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80227DA4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80227DA8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80227DAC: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80227DB0: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80227DB4: sh          $t2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r10;
    // 0x80227DB8: sh          $t3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r11;
    // 0x80227DBC: sb          $zero, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = 0;
    // 0x80227DC0: b           L_80227E24
    // 0x80227DC4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
        goto L_80227E24;
    // 0x80227DC4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80227DC8:
    // 0x80227DC8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80227DCC: addiu       $t4, $t4, -0x1398
    ctx->r12 = ADD32(ctx->r12, -0X1398);
    // 0x80227DD0: lbu         $t5, 0xE($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XE);
    // 0x80227DD4: lbu         $t8, 0xF($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0XF);
    // 0x80227DD8: lbu         $t2, 0x18($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X18);
    // 0x80227DDC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80227DE0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80227DE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80227DE8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80227DEC: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80227DF0: addu        $t1, $a3, $t9
    ctx->r9 = ADD32(ctx->r7, ctx->r25);
    // 0x80227DF4: addu        $t5, $a3, $t3
    ctx->r13 = ADD32(ctx->r7, ctx->r11);
    // 0x80227DF8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80227DFC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80227E00: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x80227E04: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80227E08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80227E0C: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x80227E10: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    // 0x80227E14: sb          $t9, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r25;
    // 0x80227E18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80227E1C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80227E20: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80227E24:
    // 0x80227E24: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80227E28: lh          $t2, 0x40($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X40);
    // 0x80227E2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80227E30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80227E34: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80227E38: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x80227E3C: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80227E40: bgezl       $v0, L_80227E54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80227E44: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_80227E54;
    }
    goto skip_0;
    // 0x80227E44: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x80227E48: b           L_80227E64
    // 0x80227E4C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
        goto L_80227E64;
    // 0x80227E4C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80227E50: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_80227E54:
    // 0x80227E54: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80227E58: beql        $at, $zero, L_80227E68
    if (ctx->r1 == 0) {
        // 0x80227E5C: sh          $zero, 0x40($s0)
        MEM_H(0X40, ctx->r16) = 0;
            goto L_80227E68;
    }
    goto skip_1;
    // 0x80227E5C: sh          $zero, 0x40($s0)
    MEM_H(0X40, ctx->r16) = 0;
    skip_1:
    // 0x80227E60: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
L_80227E64:
    // 0x80227E64: sh          $zero, 0x40($s0)
    MEM_H(0X40, ctx->r16) = 0;
L_80227E68:
    // 0x80227E68: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80227E6C: jal         0x80227484
    // 0x80227E70: lb          $a2, 0x2D($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X2D);
    LOOKUP_FUNC(0x80227484)(rdram, ctx);
        goto after_0;
    // 0x80227E70: lb          $a2, 0x2D($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X2D);
    after_0:
    // 0x80227E74: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x80227E78: lh          $t6, 0x42($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X42);
    // 0x80227E7C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80227E80: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80227E84: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80227E88: sh          $t7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r15;
    // 0x80227E8C: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x80227E90: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80227E94: bgezl       $v0, L_80227EA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80227E98: lh          $v1, 0x8($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X8);
            goto L_80227EA8;
    }
    goto skip_2;
    // 0x80227E98: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x80227E9C: b           L_80227EB8
    // 0x80227EA0: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
        goto L_80227EB8;
    // 0x80227EA0: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80227EA4: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
L_80227EA8:
    // 0x80227EA8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80227EAC: beql        $at, $zero, L_80227EBC
    if (ctx->r1 == 0) {
        // 0x80227EB0: lh          $t8, 0x6($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X6);
            goto L_80227EBC;
    }
    goto skip_3;
    // 0x80227EB0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    skip_3:
    // 0x80227EB4: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
L_80227EB8:
    // 0x80227EB8: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
L_80227EBC:
    // 0x80227EBC: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x80227EC0: sh          $zero, 0x42($s0)
    MEM_H(0X42, ctx->r16) = 0;
    // 0x80227EC4: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x80227EC8: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x80227ECC: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80227ED0: bgezl       $v0, L_80227EE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80227ED4: lh          $v1, 0x4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X4);
            goto L_80227EE8;
    }
    goto skip_4;
    // 0x80227ED4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    skip_4:
    // 0x80227ED8: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80227EDC: b           L_80227EFC
    // 0x80227EE0: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
        goto L_80227EFC;
    // 0x80227EE0: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80227EE4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
L_80227EE8:
    // 0x80227EE8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80227EEC: beql        $at, $zero, L_80227F00
    if (ctx->r1 == 0) {
        // 0x80227EF0: lh          $v1, 0x4C($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X4C);
            goto L_80227F00;
    }
    goto skip_5;
    // 0x80227EF0: lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4C);
    skip_5:
    // 0x80227EF4: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x80227EF8: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
L_80227EFC:
    // 0x80227EFC: lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4C);
L_80227F00:
    // 0x80227F00: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    // 0x80227F04: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80227F08: beq         $at, $zero, L_80227F18
    if (ctx->r1 == 0) {
        // 0x80227F0C: addiu       $t1, $v1, -0x4
        ctx->r9 = ADD32(ctx->r3, -0X4);
            goto L_80227F18;
    }
    // 0x80227F0C: addiu       $t1, $v1, -0x4
    ctx->r9 = ADD32(ctx->r3, -0X4);
    // 0x80227F10: b           L_80227F1C
    // 0x80227F14: sh          $t1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r9;
        goto L_80227F1C;
    // 0x80227F14: sh          $t1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r9;
L_80227F18:
    // 0x80227F18: sh          $v0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r2;
L_80227F1C:
    // 0x80227F1C: lbu         $t2, -0x33DF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X33DF);
    // 0x80227F20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80227F24: bnel        $t2, $at, L_80227FB4
    if (ctx->r10 != ctx->r1) {
        // 0x80227F28: lh          $t5, 0x4($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X4);
            goto L_80227FB4;
    }
    goto skip_6;
    // 0x80227F28: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    skip_6:
    // 0x80227F2C: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x80227F30: lh          $t3, 0x4A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4A);
    // 0x80227F34: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80227F38: beql        $at, $zero, L_80227F54
    if (ctx->r1 == 0) {
        // 0x80227F3C: lhu         $t7, 0x60($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X60);
            goto L_80227F54;
    }
    goto skip_7;
    // 0x80227F3C: lhu         $t7, 0x60($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X60);
    skip_7:
    // 0x80227F40: lhu         $t5, 0x60($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X60);
    // 0x80227F44: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80227F48: b           L_80227F5C
    // 0x80227F4C: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
        goto L_80227F5C;
    // 0x80227F4C: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
    // 0x80227F50: lhu         $t7, 0x60($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X60);
L_80227F54:
    // 0x80227F54: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80227F58: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
L_80227F5C:
    // 0x80227F5C: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    // 0x80227F60: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x80227F64: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80227F68: beql        $at, $zero, L_80227F7C
    if (ctx->r1 == 0) {
        // 0x80227F6C: lh          $v0, 0x6($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X6);
            goto L_80227F7C;
    }
    goto skip_8;
    // 0x80227F6C: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    skip_8:
    // 0x80227F70: sh          $v1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r3;
    // 0x80227F74: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
    // 0x80227F78: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
L_80227F7C:
    // 0x80227F7C: lh          $t4, 0x4C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4C);
    // 0x80227F80: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80227F84: bnel        $at, $zero, L_80227FB4
    if (ctx->r1 != 0) {
        // 0x80227F88: lh          $t5, 0x4($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X4);
            goto L_80227FB4;
    }
    goto skip_9;
    // 0x80227F88: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    skip_9:
    // 0x80227F8C: lhu         $t1, 0x5E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X5E);
    // 0x80227F90: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // 0x80227F94: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80227F98: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80227F9C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x80227FA0: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80227FA4: beql        $at, $zero, L_80227FB4
    if (ctx->r1 == 0) {
        // 0x80227FA8: lh          $t5, 0x4($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X4);
            goto L_80227FB4;
    }
    goto skip_10;
    // 0x80227FA8: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    skip_10:
    // 0x80227FAC: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x80227FB0: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
L_80227FB4:
    // 0x80227FB4: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x80227FB8: lb          $t1, 0x2D($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X2D);
    // 0x80227FBC: bne         $t5, $t6, L_80228008
    if (ctx->r13 != ctx->r14) {
        // 0x80227FC0: nop
    
            goto L_80228008;
    }
    // 0x80227FC0: nop

    // 0x80227FC4: lw          $t8, 0x30($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X30);
    // 0x80227FC8: addiu       $t7, $zero, 0x77
    ctx->r15 = ADD32(0, 0X77);
    // 0x80227FCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80227FD0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x80227FD4: lb          $t9, 0x2D($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X2D);
    // 0x80227FD8: bnel        $t9, $zero, L_80227FEC
    if (ctx->r25 != 0) {
        // 0x80227FDC: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80227FEC;
    }
    goto skip_11;
    // 0x80227FDC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    skip_11:
    // 0x80227FE0: b           L_80228000
    // 0x80227FE4: sb          $t4, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r12;
        goto L_80228000;
    // 0x80227FE4: sb          $t4, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r12;
    // 0x80227FE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
L_80227FEC:
    // 0x80227FEC: jal         0x802269CC
    // 0x80227FF0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_1;
    // 0x80227FF0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_1:
    // 0x80227FF4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80227FF8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80227FFC: sb          $v0, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r2;
L_80228000:
    // 0x80228000: b           L_80228038
    // 0x80228004: sb          $zero, 0x22($a2)
    MEM_B(0X22, ctx->r6) = 0;
        goto L_80228038;
    // 0x80228004: sb          $zero, 0x22($a2)
    MEM_B(0X22, ctx->r6) = 0;
L_80228008:
    // 0x80228008: bne         $t1, $zero, L_8022801C
    if (ctx->r9 != 0) {
        // 0x8022800C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8022801C;
    }
    // 0x8022800C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80228010: sb          $t3, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r11;
    // 0x80228014: b           L_80228038
    // 0x80228018: sb          $t3, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r11;
        goto L_80228038;
    // 0x80228018: sb          $t3, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r11;
L_8022801C:
    // 0x8022801C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80228020: jal         0x802269CC
    // 0x80228024: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x802269CC)(rdram, ctx);
        goto after_2;
    // 0x80228024: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_2:
    // 0x80228028: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8022802C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80228030: sb          $v0, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r2;
    // 0x80228034: sb          $v0, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r2;
L_80228038:
    // 0x80228038: lbu         $a3, 0x2D($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2D);
    // 0x8022803C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228040: jal         0x80227A80
    // 0x80228044: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80227A80)(rdram, ctx);
        goto after_3;
    // 0x80228044: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80228048: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8022804C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80228050: jal         0x802277A0
    // 0x80228054: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x802277A0)(rdram, ctx);
        goto after_4;
    // 0x80228054: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80228058: jal         0x80147598
    // 0x8022805C: nop

    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_5;
    // 0x8022805C: nop

    after_5:
    // 0x80228060: beq         $v0, $zero, L_802280B8
    if (ctx->r2 == 0) {
        // 0x80228064: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802280B8;
    }
    // 0x80228064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228068: jal         0x80146A9C
    // 0x8022806C: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    LOOKUP_FUNC(0x80146A9C)(rdram, ctx);
        goto after_6;
    // 0x8022806C: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    after_6:
    // 0x80228070: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80228074: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80228078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022807C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80228080: lb          $a1, 0x2D($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X2D);
    // 0x80228084: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80228088: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8022808C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80228090: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80228094: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80228098: nop

    // 0x8022809C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802280A0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802280A4: jal         0x80146CD4
    // 0x802280A8: sh          $a0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80146CD4)(rdram, ctx);
        goto after_7;
    // 0x802280A8: sh          $a0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r4;
    after_7:
    // 0x802280AC: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
    // 0x802280B0: jal         0x80146BE0
    // 0x802280B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80146BE0)(rdram, ctx);
        goto after_8;
    // 0x802280B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_8:
L_802280B8:
    // 0x802280B8: lb          $t7, 0x2D($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X2D);
    // 0x802280BC: bnel        $t7, $zero, L_8022810C
    if (ctx->r15 != 0) {
        // 0x802280C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8022810C;
    }
    goto skip_12;
    // 0x802280C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x802280C4: jal         0x80147598
    // 0x802280C8: nop

    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_9;
    // 0x802280C8: nop

    after_9:
    // 0x802280CC: bne         $v0, $zero, L_80228108
    if (ctx->r2 != 0) {
        // 0x802280D0: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80228108;
    }
    // 0x802280D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x802280D4: lhu         $t8, 0x30($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X30);
    // 0x802280D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x802280DC: lhu         $a2, 0x46($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X46);
    // 0x802280E0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x802280E4: jal         0x8014677C
    // 0x802280E8: lbu         $a1, -0x1398($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1398);
    LOOKUP_FUNC(0x8014677C)(rdram, ctx);
        goto after_10;
    // 0x802280E8: lbu         $a1, -0x1398($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1398);
    after_10:
    // 0x802280EC: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x802280F0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x802280F4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x802280F8: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x802280FC: lbu         $a1, -0x1398($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1398);
    // 0x80228100: jal         0x8014677C
    // 0x80228104: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8014677C)(rdram, ctx);
        goto after_11;
    // 0x80228104: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    after_11:
L_80228108:
    // 0x80228108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8022810C:
    // 0x8022810C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80228110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80228114: jr          $ra
    // 0x80228118: nop

    return;
    // 0x80228118: nop

;}
RECOMP_FUNC void M10_FUN_8022811c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022811C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80228120: addiu       $v1, $v1, -0x1398
    ctx->r3 = ADD32(ctx->r3, -0X1398);
    // 0x80228124: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x80228128: lbu         $t0, 0xF($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022812c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022812c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022812C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80228130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80228134: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80228138: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8022813C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80228140: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80228144: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80228148: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8022814C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80228150: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80228154: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80228158: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8022815C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80228160: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
    // 0x80228164: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80228168: jal         0x80227D44
    // 0x8022816C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80227D44)(rdram, ctx);
        goto after_0;
    // 0x8022816C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_0:
    // 0x80228170: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80228174: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80228178: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
    // 0x8022817C: jal         0x80227D44
    // 0x80228180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80227D44)(rdram, ctx);
        goto after_1;
    // 0x80228180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80228184: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80228188: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8022818C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80228190: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80228194: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80228198: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8022819C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x802281A0: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x802281A4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x802281A8: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x802281AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802281B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802281B4: jr          $ra
    // 0x802281B8: nop

    return;
    // 0x802281B8: nop

;}
RECOMP_FUNC void M10_FUN_802281bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802281BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802281C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x802281C4: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x802281C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x802281CC: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x802281D0: addiu       $s2, $s2, -0x1398
    ctx->r18 = ADD32(ctx->r18, -0X1398);
    // 0x802281D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x802281D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802281DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802281E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802281E4: lbu         $a1, 0x5($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X5);
    // 0x802281E8: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    // 0x802281EC: jal         0x801470E8
    // 0x802281F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_0;
    // 0x802281F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x802281F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802281F8: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    // 0x802281FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80228200: jal         0x801470E8
    // 0x80228204: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_1;
    // 0x80228204: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_1:
    // 0x80228208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022820C: lbu         $a1, 0x1A($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1A);
    // 0x80228210: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80228214: jal         0x801470E8
    // 0x80228218: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_2;
    // 0x80228218: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_2:
    // 0x8022821C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228220: lbu         $a1, 0x1C($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1C);
    // 0x80228224: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80228228: jal         0x801470E8
    // 0x8022822C: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_3;
    // 0x8022822C: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_3:
    // 0x80228230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228234: lbu         $a1, 0x12($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X12);
    // 0x80228238: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8022823C: jal         0x801470E8
    // 0x80228240: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_4;
    // 0x80228240: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_4:
    // 0x80228244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228248: lbu         $a1, 0xE($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XE);
    // 0x8022824C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80228250: jal         0x801470E8
    // 0x80228254: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_5;
    // 0x80228254: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_5:
    // 0x80228258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022825C: lbu         $a1, 0x1B($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1B);
    // 0x80228260: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80228264: jal         0x801470E8
    // 0x80228268: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_6;
    // 0x80228268: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_6:
    // 0x8022826C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80228270: lbu         $a1, 0x1D($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1D);
    // 0x80228274: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80228278: jal         0x801470E8
    // 0x8022827C: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_7;
    // 0x8022827C: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_7:
    // 0x80228280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80228284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80228288: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8022828C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80228290: jr          $ra
    // 0x80228294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80228294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80228298(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80228298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80228298: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022829C: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x802282A0: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x802282A4: bne         $a0, $t7, L_802282B4
    if (ctx->r4 != ctx->r15) {
        // 0x802282A8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_802282B4;
    }
    // 0x802282A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x802282AC: b           L_802282B8
    // 0x802282B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802282B8;
    // 0x802282B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802282B4:
    // 0x802282B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802282B8:
    // 0x802282B8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x802282BC: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x802282C0: addiu       $t9, $t9, 0x7C8
    ctx->r25 = ADD32(ctx->r25, 0X7C8);
    // 0x802282C4: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x802282C8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x802282CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802282D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_802282D4:
    // 0x802282D4: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802282D8: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x802282DC: addu        $t3, $a2, $v1
    ctx->r11 = ADD32(ctx->r6, ctx->r3);
    // 0x802282E0: addu        $t4, $a2, $v1
    ctx->r12 = ADD32(ctx->r6, ctx->r3);
    // 0x802282E4: mflo        $t1
    ctx->r9 = lo;
    // 0x802282E8: addiu       $t2, $t1, 0x64
    ctx->r10 = ADD32(ctx->r9, 0X64);
    // 0x802282EC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x802282F0: beql        $at, $zero, L_80228304
    if (ctx->r1 == 0) {
        // 0x802282F4: sb          $zero, 0x0($t4)
        MEM_B(0X0, ctx->r12) = 0;
            goto L_80228304;
    }
    goto skip_0;
    // 0x802282F4: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    skip_0:
    // 0x802282F8: b           L_80228304
    // 0x802282FC: sb          $a3, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r7;
        goto L_80228304;
    // 0x802282FC: sb          $a3, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r7;
    // 0x80228300: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
L_80228304:
    // 0x80228304: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80228308: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8022830C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80228310: bne         $at, $zero, L_802282D4
    if (ctx->r1 != 0) {
        // 0x80228314: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_802282D4;
    }
    // 0x80228314: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80228318: jr          $ra
    // 0x8022831C: nop

    return;
    // 0x8022831C: nop

;}
