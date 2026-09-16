#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80141108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141108: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8014110C: lbu         $t8, -0x13FC($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X13FC);
    // 0x80141110: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80141114: lbu         $t6, -0x13FB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FB);
    // 0x80141118: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8014111C: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80141120: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141124(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80141128: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8014112C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80141130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141134: addiu       $t3, $t3, -0x1480
    ctx->r11 = ADD32(ctx->r11, -0X1480);
    // 0x80141138: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x8014113C: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x80141140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80141144: jal         0x801439C0
    // 0x80141148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801439C0)(rdram, ctx);
        goto after_0;
    // 0x80141148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8014114C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141154: jr          $ra
    // 0x80141158: nop

    return;
    // 0x80141158: nop

;}
RECOMP_FUNC void M7_FUN_8014115c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014115C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80141160: lbu         $v0, -0x13FE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X13FE);
    // 0x80141164: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80141168: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8014116C: bne         $v1, $v0, L_80141198
    if (ctx->r3 != ctx->r2) {
            // 0x80141170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80141198)(rdram, ctx);
    return;
    }
    // 0x80141170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80141174: lbu         $t6, -0x13FB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FB);
    // 0x80141178: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8014117C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80141180: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80141184: lbu         $t8, -0x147C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X147C);
    // 0x80141188: bne         $v1, $t8, L_80141198
    if (ctx->r3 != ctx->r24) {
            // 0x8014118C: nop

    LOOKUP_FUNC(0x80141198)(rdram, ctx);
    return;
    }
    // 0x8014118C: nop

    // 0x80141190: jr          $ra
    // 0x80141194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80141194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141198(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141198: bne         $v0, $at, L_801411C4
    if (ctx->r2 != ctx->r1) {
        // 0x8014119C: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_801411C4;
    }
    // 0x8014119C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801411A0: lbu         $t9, -0x13FB($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X13FB);
    // 0x801411A4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801411A8: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x801411AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801411B0: lbu         $t1, -0x1454($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1454);
    // 0x801411B4: bnel        $v1, $t1, L_801411C8
    if (ctx->r3 != ctx->r9) {
        // 0x801411B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801411C8;
    }
    goto skip_0;
    // 0x801411B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801411BC: jr          $ra
    // 0x801411C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801411C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801411C4:
    // 0x801411C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801411C8:
    // 0x801411C8: jr          $ra
    // 0x801411CC: nop

    return;
    // 0x801411CC: nop

;}
RECOMP_FUNC void M7_FUN_801411d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801411D0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801411D4: lbu         $a0, -0x13FE($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X13FE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801411d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801411d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801411D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801411DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801411E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801411E4: bne         $v1, $a0, L_8014121C
    if (ctx->r3 != ctx->r4) {
        // 0x801411E8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8014121C;
    }
    // 0x801411E8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801411EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801411F0: lbu         $a1, -0x13FB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FB);
    // 0x801411F4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801411F8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x801411FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80141200: lbu         $t7, -0x147C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X147C);
    // 0x80141204: bnel        $v1, $t7, L_80141220
    if (ctx->r3 != ctx->r15) {
        // 0x80141208: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80141220;
    }
    goto skip_0;
    // 0x80141208: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8014120C: jal         0x801415C4
    // 0x80141210: nop

    LOOKUP_FUNC(0x801415C4)(rdram, ctx);
        goto after_0;
    // 0x80141210: nop

    after_0:
    // 0x80141214: b           L_8014125C
    // 0x80141218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014125C;
    // 0x80141218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014121C:
    // 0x8014121C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80141220:
    // 0x80141220: bne         $v0, $at, L_80141254
    if (ctx->r2 != ctx->r1) {
        // 0x80141224: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80141254;
    }
    // 0x80141224: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80141228: lbu         $a1, -0x13FB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FB);
    // 0x8014122C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80141230: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80141234: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80141238: lbu         $t9, -0x1454($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1454);
    // 0x8014123C: bnel        $v1, $t9, L_80141258
    if (ctx->r3 != ctx->r25) {
        // 0x80141240: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80141258;
    }
    goto skip_1;
    // 0x80141240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80141244: jal         0x801415C4
    // 0x80141248: nop

    LOOKUP_FUNC(0x801415C4)(rdram, ctx);
        goto after_1;
    // 0x80141248: nop

    after_1:
    // 0x8014124C: b           L_8014125C
    // 0x80141250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014125C;
    // 0x80141250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141254:
    // 0x80141254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141258:
    // 0x80141258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014125C:
    // 0x8014125C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141260: jr          $ra
    // 0x80141264: nop

    return;
    // 0x80141264: nop

;}
RECOMP_FUNC void M7_FUN_80141268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141268: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8014126C: lbu         $t6, -0x13FE($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13FE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141270(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141274: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80141278: bne         $t6, $at, L_80141384
    if (ctx->r14 != ctx->r1) {
        // 0x8014127C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80141384;
    }
    // 0x8014127C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141280: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80141284: lbu         $a1, -0x13FB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FB);
    // 0x80141288: jal         0x80141628
    // 0x8014128C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80141628)(rdram, ctx);
        goto after_0;
    // 0x8014128C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80141290: bne         $v0, $zero, L_80141344
    if (ctx->r2 != 0) {
        // 0x80141294: sb          $v0, 0x1F($sp)
        MEM_B(0X1F, ctx->r29) = ctx->r2;
            goto L_80141344;
    }
    // 0x80141294: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x80141298: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8014129C: lbu         $t7, -0x13FB($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X13FB);
    // 0x801412A0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801412A4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801412A8: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x801412AC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801412B0: addiu       $t9, $t9, -0x1480
    ctx->r25 = ADD32(ctx->r25, -0X1480);
    // 0x801412B4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801412B8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x801412BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801412C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801412C4: sb          $t0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r8;
    // 0x801412C8: bne         $t2, $zero, L_80141304
    if (ctx->r10 != 0) {
        // 0x801412CC: sb          $t1, 0x5($v1)
        MEM_B(0X5, ctx->r3) = ctx->r9;
            goto L_80141304;
    }
    // 0x801412CC: sb          $t1, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r9;
    // 0x801412D0: jal         0x80108280
    // 0x801412D4: nop

    LOOKUP_FUNC(0x80108280)(rdram, ctx);
        goto after_1;
    // 0x801412D4: nop

    after_1:
    // 0x801412D8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801412DC: lbu         $t3, -0x13FB($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X13FB);
    // 0x801412E0: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801412E4: addiu       $t5, $t5, -0x1480
    ctx->r13 = ADD32(ctx->r13, -0X1480);
    // 0x801412E8: sra         $t6, $v0, 8
    ctx->r14 = S32(SIGNED(ctx->r2) >> 8);
    // 0x801412EC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801412F0: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x801412F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801412F8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801412FC: b           L_8014130C
    // 0x80141300: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
        goto L_8014130C;
    // 0x80141300: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
L_80141304:
    // 0x80141304: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80141308: sb          $t7, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r15;
L_8014130C:
    // 0x8014130C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80141310: lhu         $t8, -0x2378($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2378);
    // 0x80141314: lhu         $t9, 0xA($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XA);
    // 0x80141318: lhu         $t1, 0x8($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X8);
    // 0x8014131C: lbu         $t2, 0x1D($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1D);
    // 0x80141320: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80141324: addiu       $a1, $a1, -0x147C
    ctx->r5 = ADD32(ctx->r5, -0X147C);
    // 0x80141328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8014132C: sb          $t8, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r24;
    // 0x80141330: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x80141334: sb          $t1, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r9;
    // 0x80141338: jal         0x80141568
    // 0x8014133C: sb          $t2, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r10;
    LOOKUP_FUNC(0x80141568)(rdram, ctx);
        goto after_2;
    // 0x8014133C: sb          $t2, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r10;
    after_2:
    // 0x80141340: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
L_80141344:
    // 0x80141344: bne         $v0, $zero, L_80141384
    if (ctx->r2 != 0) {
        // 0x80141348: lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
            goto L_80141384;
    }
    // 0x80141348: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8014134C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80141350: lbu         $t5, -0x13FC($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X13FC);
    // 0x80141354: lbu         $t3, -0x13FB($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X13FB);
    // 0x80141358: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8014135C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80141360: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80141364: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80141368: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8014136C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80141370: addiu       $t0, $t0, -0x1480
    ctx->r8 = ADD32(ctx->r8, -0X1480);
    // 0x80141374: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80141378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8014137C: jal         0x8014307C
    // 0x80141380: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_3;
    // 0x80141380: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    after_3:
L_80141384:
    // 0x80141384: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80141388: lbu         $t1, -0x13FE($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X13FE);
    // 0x8014138C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80141390: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80141394: bne         $t1, $at, L_8014149C
    if (ctx->r9 != ctx->r1) {
        // 0x80141398: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_8014149C;
    }
    // 0x80141398: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014139C: jal         0x80141628
    // 0x801413A0: lbu         $a1, -0x13FB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FB);
    LOOKUP_FUNC(0x80141628)(rdram, ctx);
        goto after_4;
    // 0x801413A0: lbu         $a1, -0x13FB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13FB);
    after_4:
    // 0x801413A4: bne         $v0, $zero, L_8014145C
    if (ctx->r2 != 0) {
        // 0x801413A8: sb          $v0, 0x1F($sp)
        MEM_B(0X1F, ctx->r29) = ctx->r2;
            goto L_8014145C;
    }
    // 0x801413A8: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x801413AC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801413B0: lbu         $t2, -0x13FB($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X13FB);
    // 0x801413B4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801413B8: addiu       $t5, $t5, -0x1458
    ctx->r13 = ADD32(ctx->r13, -0X1458);
    // 0x801413BC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x801413C0: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x801413C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801413C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801413CC: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x801413D0: sb          $t4, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r12;
    // 0x801413D4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801413D8: lbu         $t7, -0x4410($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4410);
    // 0x801413DC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801413E0: bnel        $t7, $zero, L_80141418
    if (ctx->r15 != 0) {
        // 0x801413E4: sb          $t2, 0x6($v1)
        MEM_B(0X6, ctx->r3) = ctx->r10;
            goto L_80141418;
    }
    goto skip_0;
    // 0x801413E4: sb          $t2, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r10;
    skip_0:
    // 0x801413E8: jal         0x80108280
    // 0x801413EC: nop

    LOOKUP_FUNC(0x80108280)(rdram, ctx);
        goto after_5;
    // 0x801413EC: nop

    after_5:
    // 0x801413F0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801413F4: lbu         $t8, -0x13FB($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X13FB);
    // 0x801413F8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801413FC: addiu       $t0, $t0, -0x1458
    ctx->r8 = ADD32(ctx->r8, -0X1458);
    // 0x80141400: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80141404: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80141408: sra         $t1, $v0, 8
    ctx->r9 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8014140C: b           L_80141418
    // 0x80141410: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
        goto L_80141418;
    // 0x80141410: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    // 0x80141414: sb          $t2, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r10;
L_80141418:
    // 0x80141418: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8014141C: lhu         $t3, -0x2378($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2378);
    // 0x80141420: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80141424: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80141428: sb          $t3, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r11;
    // 0x8014142C: lhu         $t5, -0x4406($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X4406);
    // 0x80141430: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80141434: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80141438: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    // 0x8014143C: lhu         $t4, -0x4408($t6)
    ctx->r12 = MEM_HU(ctx->r14, -0X4408);
    // 0x80141440: addiu       $a1, $a1, -0x1454
    ctx->r5 = ADD32(ctx->r5, -0X1454);
    // 0x80141444: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80141448: sb          $t4, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r12;
    // 0x8014144C: lbu         $t7, -0x43F3($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X43F3);
    // 0x80141450: jal         0x80141568
    // 0x80141454: sb          $t7, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r15;
    LOOKUP_FUNC(0x80141568)(rdram, ctx);
        goto after_6;
    // 0x80141454: sb          $t7, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r15;
    after_6:
    // 0x80141458: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
L_8014145C:
    // 0x8014145C: bne         $v0, $zero, L_8014149C
    if (ctx->r2 != 0) {
        // 0x80141460: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8014149C;
    }
    // 0x80141460: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80141464: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80141468: lbu         $t0, -0x13FC($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X13FC);
    // 0x8014146C: lbu         $t8, -0x13FB($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X13FB);
    // 0x80141470: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80141474: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80141478: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8014147C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80141480: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80141484: addiu       $t5, $t3, 0x4
    ctx->r13 = ADD32(ctx->r11, 0X4);
    // 0x80141488: addiu       $t6, $t6, -0x1458
    ctx->r14 = ADD32(ctx->r14, -0X1458);
    // 0x8014148C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80141490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80141494: jal         0x8014307C
    // 0x80141498: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x8014307C)(rdram, ctx);
        goto after_7;
    // 0x80141498: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    after_7:
L_8014149C:
    // 0x8014149C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801414A0: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x801414A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801414A8: jr          $ra
    // 0x801414AC: nop

    return;
    // 0x801414AC: nop

;}
RECOMP_FUNC void M7_FUN_801414b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801414B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801414B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801414B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801414BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801414C0: beq         $a0, $at, L_801414DC
    if (ctx->r4 == ctx->r1) {
        // 0x801414C4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801414DC;
    }
    // 0x801414C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801414C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801414CC: beq         $a0, $at, L_801414EC
    if (ctx->r4 == ctx->r1) {
        // 0x801414D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801414EC;
    }
    // 0x801414D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801414D4: b           L_801414FC
    // 0x801414D8: nop

        goto L_801414FC;
    // 0x801414D8: nop

L_801414DC:
    // 0x801414DC: jal         0x80142240
    // 0x801414E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142240)(rdram, ctx);
        goto after_0;
    // 0x801414E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801414E4: b           L_80141500
    // 0x801414E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80141500;
    // 0x801414E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801414EC:
    // 0x801414EC: jal         0x80142240
    // 0x801414F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142240)(rdram, ctx);
        goto after_1;
    // 0x801414F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801414F4: b           L_80141500
    // 0x801414F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80141500;
    // 0x801414F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801414FC:
    // 0x801414FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141500:
    // 0x80141500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141504: jr          $ra
    // 0x80141508: nop

    return;
    // 0x80141508: nop

;}
RECOMP_FUNC void M7_FUN_8014150c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014150C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80141510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80141514: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80141518: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014151C: beq         $a0, $at, L_80141538
    if (ctx->r4 == ctx->r1) {
        // 0x80141520: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80141538;
    }
    // 0x80141520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80141528: beq         $a0, $at, L_80141548
    if (ctx->r4 == ctx->r1) {
        // 0x8014152C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80141548;
    }
    // 0x8014152C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141530: b           L_80141558
    // 0x80141534: nop

        goto L_80141558;
    // 0x80141534: nop

L_80141538:
    // 0x80141538: jal         0x801422E4
    // 0x8014153C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801422E4)(rdram, ctx);
        goto after_0;
    // 0x8014153C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80141540: b           L_8014155C
    // 0x80141544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014155C;
    // 0x80141544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141548:
    // 0x80141548: jal         0x801422E4
    // 0x8014154C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801422E4)(rdram, ctx);
        goto after_1;
    // 0x8014154C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80141550: b           L_8014155C
    // 0x80141554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014155C;
    // 0x80141554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141558:
    // 0x80141558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014155C:
    // 0x8014155C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141560: jr          $ra
    // 0x80141564: nop

    return;
    // 0x80141564: nop

;}
RECOMP_FUNC void M7_FUN_80141568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014156C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80141570: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80141574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80141578: beq         $a0, $at, L_80141594
    if (ctx->r4 == ctx->r1) {
        // 0x8014157C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80141594;
    }
    // 0x8014157C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141580: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80141584: beq         $a0, $at, L_801415A4
    if (ctx->r4 == ctx->r1) {
        // 0x80141588: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801415A4;
    }
    // 0x80141588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014158C: b           L_801415B4
    // 0x80141590: nop

        goto L_801415B4;
    // 0x80141590: nop

L_80141594:
    // 0x80141594: jal         0x80142350
    // 0x80141598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142350)(rdram, ctx);
        goto after_0;
    // 0x80141598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8014159C: b           L_801415B8
    // 0x801415A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801415B8;
    // 0x801415A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801415A4:
    // 0x801415A4: jal         0x80142350
    // 0x801415A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142350)(rdram, ctx);
        goto after_1;
    // 0x801415A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801415AC: b           L_801415B8
    // 0x801415B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801415B8;
    // 0x801415B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801415B4:
    // 0x801415B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801415B8:
    // 0x801415B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801415BC: jr          $ra
    // 0x801415C0: nop

    return;
    // 0x801415C0: nop

;}
RECOMP_FUNC void M7_FUN_801415c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801415C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801415C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801415CC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801415D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801415D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801415D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801415DC: beq         $a0, $at, L_801415F8
    if (ctx->r4 == ctx->r1) {
        // 0x801415E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801415F8;
    }
    // 0x801415E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801415E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801415E8: beq         $a0, $at, L_80141608
    if (ctx->r4 == ctx->r1) {
        // 0x801415EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80141608;
    }
    // 0x801415EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801415F0: b           L_80141618
    // 0x801415F4: nop

        goto L_80141618;
    // 0x801415F4: nop

L_801415F8:
    // 0x801415F8: jal         0x801423C8
    // 0x801415FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801423C8)(rdram, ctx);
        goto after_0;
    // 0x801415FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80141600: b           L_8014161C
    // 0x80141604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014161C;
    // 0x80141604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141608:
    // 0x80141608: jal         0x801423C8
    // 0x8014160C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801423C8)(rdram, ctx);
        goto after_1;
    // 0x8014160C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80141610: b           L_8014161C
    // 0x80141614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014161C;
    // 0x80141614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141618:
    // 0x80141618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014161C:
    // 0x8014161C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141620: jr          $ra
    // 0x80141624: nop

    return;
    // 0x80141624: nop

;}
RECOMP_FUNC void M7_FUN_80141628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014162C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80141630: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80141634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80141638: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014163C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80141640: beq         $a0, $at, L_8014165C
    if (ctx->r4 == ctx->r1) {
        // 0x80141644: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8014165C;
    }
    // 0x80141644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014164C: beq         $a0, $at, L_8014166C
    if (ctx->r4 == ctx->r1) {
        // 0x80141650: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014166C;
    }
    // 0x80141650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141654: b           L_8014167C
    // 0x80141658: nop

        goto L_8014167C;
    // 0x80141658: nop

L_8014165C:
    // 0x8014165C: jal         0x80142450
    // 0x80141660: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80142450)(rdram, ctx);
        goto after_0;
    // 0x80141660: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80141664: b           L_80141680
    // 0x80141668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80141680;
    // 0x80141668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014166C:
    // 0x8014166C: jal         0x80142450
    // 0x80141670: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80142450)(rdram, ctx);
        goto after_1;
    // 0x80141670: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80141674: b           L_80141680
    // 0x80141678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80141680;
    // 0x80141678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014167C:
    // 0x8014167C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141680:
    // 0x80141680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141684: jr          $ra
    // 0x80141688: nop

    return;
    // 0x80141688: nop

;}
RECOMP_FUNC void M7_FUN_8014168c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014168C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80141690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80141694: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80141698: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8014169C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801416A0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801416A4: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    // 0x801416A8: jal         0x8001F430
    // 0x801416AC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_0;
    // 0x801416AC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    after_0:
    // 0x801416B0: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x801416B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801416B8: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x801416BC: beq         $a0, $at, L_801416D8
    if (ctx->r4 == ctx->r1) {
        // 0x801416C0: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801416D8;
    }
    // 0x801416C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801416C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801416C8: beq         $a0, $at, L_80141734
    if (ctx->r4 == ctx->r1) {
        // 0x801416CC: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80141734;
    }
    // 0x801416CC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801416D0: b           L_80141788
    // 0x801416D4: nop

        goto L_80141788;
    // 0x801416D4: nop

L_801416D8:
    // 0x801416D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801416DC: addiu       $a1, $a1, -0x13F0
    ctx->r5 = ADD32(ctx->r5, -0X13F0);
    // 0x801416E0: jal         0x801422E4
    // 0x801416E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801422E4)(rdram, ctx);
        goto after_1;
    // 0x801416E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801416E8: bne         $v0, $zero, L_80141788
    if (ctx->r2 != 0) {
        // 0x801416EC: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80141788;
    }
    // 0x801416EC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801416F0: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x801416F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801416F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801416FC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80141700: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80141704: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x80141708: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8014170C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80141710: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x80141714: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x80141718: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8014171C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80141720: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x80141724: jal         0x800031EC
    // 0x80141728: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x800031EC)(rdram, ctx);
        goto after_2;
    // 0x80141728: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x8014172C: b           L_80141788
    // 0x80141730: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80141788;
    // 0x80141730: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80141734:
    // 0x80141734: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80141738: jal         0x801422E4
    // 0x8014173C: addiu       $a1, $a1, -0x13F0
    ctx->r5 = ADD32(ctx->r5, -0X13F0);
    LOOKUP_FUNC(0x801422E4)(rdram, ctx);
        goto after_3;
    // 0x8014173C: addiu       $a1, $a1, -0x13F0
    ctx->r5 = ADD32(ctx->r5, -0X13F0);
    after_3:
    // 0x80141740: bne         $v0, $zero, L_80141788
    if (ctx->r2 != 0) {
        // 0x80141744: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80141788;
    }
    // 0x80141744: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80141748: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x8014174C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80141750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80141754: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80141758: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8014175C: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x80141760: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80141764: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80141768: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x8014176C: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x80141770: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80141774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80141778: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x8014177C: jal         0x800031EC
    // 0x80141780: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x800031EC)(rdram, ctx);
        goto after_4;
    // 0x80141780: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80141784: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80141788:
    // 0x80141788: bne         $v1, $zero, L_80141914
    if (ctx->r3 != 0) {
        // 0x8014178C: lbu         $v0, 0x2F($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X2F);
            goto L_80141914;
    }
    // 0x8014178C: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x80141790: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80141794: beq         $v0, $at, L_801417B0
    if (ctx->r2 == ctx->r1) {
        // 0x80141798: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_801417B0;
    }
    // 0x80141798: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014179C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801417A0: beq         $v0, $at, L_80141864
    if (ctx->r2 == ctx->r1) {
        // 0x801417A4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80141864;
    }
    // 0x801417A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801417A8: b           L_80141918
    // 0x801417AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80141918;
    // 0x801417AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_801417B0:
    // 0x801417B0: addiu       $a1, $a1, -0x13D0
    ctx->r5 = ADD32(ctx->r5, -0X13D0);
    // 0x801417B4: jal         0x801422E4
    // 0x801417B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801422E4)(rdram, ctx);
        goto after_5;
    // 0x801417B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801417BC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801417C0: addiu       $a1, $a1, -0x13D0
    ctx->r5 = ADD32(ctx->r5, -0X13D0);
    // 0x801417C4: bne         $v0, $zero, L_80141818
    if (ctx->r2 != 0) {
        // 0x801417C8: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80141818;
    }
    // 0x801417C8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801417CC: lbu         $t1, 0x33($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X33);
    // 0x801417D0: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801417D4: addiu       $t3, $t3, -0x13F0
    ctx->r11 = ADD32(ctx->r11, -0X13F0);
    // 0x801417D8: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x801417DC: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x801417E0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801417E4: lwl         $t6, 0x0($t4)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r12, 0X0);
    // 0x801417E8: lwr         $t6, 0x3($t4)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r12, 0X3);
    // 0x801417EC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801417F0: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x801417F4: swl         $t6, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r14);
    // 0x801417F8: swr         $t6, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r14);
    // 0x801417FC: lwl         $t5, 0x4($t4)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r12, 0X4);
    // 0x80141800: lwr         $t5, 0x7($t4)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r12, 0X7);
    // 0x80141804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80141808: swl         $t5, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r13);
    // 0x8014180C: jal         0x80142350
    // 0x80141810: swr         $t5, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r13);
    LOOKUP_FUNC(0x80142350)(rdram, ctx);
        goto after_6;
    // 0x80141810: swr         $t5, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r13);
    after_6:
    // 0x80141814: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80141818:
    // 0x80141818: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8014181C: bne         $t7, $zero, L_80141914
    if (ctx->r15 != 0) {
        // 0x80141820: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80141914;
    }
    // 0x80141820: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80141824: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x80141828: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8014182C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80141830: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80141834: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80141838: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8014183C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80141840: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80141844: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x80141848: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x8014184C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80141850: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x80141854: jal         0x800032E0
    // 0x80141858: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x800032E0)(rdram, ctx);
        goto after_7;
    // 0x80141858: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_7:
    // 0x8014185C: b           L_80141914
    // 0x80141860: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80141914;
    // 0x80141860: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80141864:
    // 0x80141864: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80141868: jal         0x801422E4
    // 0x8014186C: addiu       $a1, $a1, -0x13D0
    ctx->r5 = ADD32(ctx->r5, -0X13D0);
    LOOKUP_FUNC(0x801422E4)(rdram, ctx);
        goto after_8;
    // 0x8014186C: addiu       $a1, $a1, -0x13D0
    ctx->r5 = ADD32(ctx->r5, -0X13D0);
    after_8:
    // 0x80141870: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80141874: addiu       $a1, $a1, -0x13D0
    ctx->r5 = ADD32(ctx->r5, -0X13D0);
    // 0x80141878: bne         $v0, $zero, L_801418CC
    if (ctx->r2 != 0) {
        // 0x8014187C: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_801418CC;
    }
    // 0x8014187C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80141880: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x80141884: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80141888: addiu       $t4, $t4, -0x13F0
    ctx->r12 = ADD32(ctx->r12, -0X13F0);
    // 0x8014188C: sll         $t0, $t3, 3
    ctx->r8 = S32(ctx->r11 << 3);
    // 0x80141890: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x80141894: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80141898: lwl         $t7, 0x0($t5)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r13, 0X0);
    // 0x8014189C: lwr         $t7, 0x3($t5)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r13, 0X3);
    // 0x801418A0: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x801418A4: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x801418A8: swl         $t7, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r15);
    // 0x801418AC: swr         $t7, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r15);
    // 0x801418B0: lwl         $t6, 0x4($t5)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r13, 0X4);
    // 0x801418B4: lwr         $t6, 0x7($t5)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r13, 0X7);
    // 0x801418B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801418BC: swl         $t6, 0x4($t2)
    do_swl(rdram, 0X4, ctx->r10, ctx->r14);
    // 0x801418C0: jal         0x80142350
    // 0x801418C4: swr         $t6, 0x7($t2)
    do_swr(rdram, 0X7, ctx->r10, ctx->r14);
    LOOKUP_FUNC(0x80142350)(rdram, ctx);
        goto after_9;
    // 0x801418C4: swr         $t6, 0x7($t2)
    do_swr(rdram, 0X7, ctx->r10, ctx->r14);
    after_9:
    // 0x801418C8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_801418CC:
    // 0x801418CC: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x801418D0: bne         $t8, $zero, L_80141914
    if (ctx->r24 != 0) {
        // 0x801418D4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80141914;
    }
    // 0x801418D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801418D8: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x801418DC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x801418E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801418E4: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801418E8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801418EC: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x801418F0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801418F4: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801418F8: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x801418FC: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x80141900: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80141904: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x80141908: jal         0x800032E0
    // 0x8014190C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x800032E0)(rdram, ctx);
        goto after_10;
    // 0x8014190C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_10:
    // 0x80141910: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80141914:
    // 0x80141914: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80141918:
    // 0x80141918: jal         0x8001F540
    // 0x8014191C: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_11;
    // 0x8014191C: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_11:
    // 0x80141920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80141924: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x80141928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014192C: jr          $ra
    // 0x80141930: nop

    return;
    // 0x80141930: nop

;}
RECOMP_FUNC void M7_FUN_80141934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141934: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80141938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014193C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80141940: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80141944: jal         0x8014150C
    // 0x80141948: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_0;
    // 0x80141948: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8014194C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80141950: bne         $v0, $at, L_80141968
    if (ctx->r2 != ctx->r1) {
        // 0x80141954: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80141968;
    }
    // 0x80141954: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80141958: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8014195C: jal         0x8014150C
    // 0x80141960: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x8014150C)(rdram, ctx);
        goto after_1;
    // 0x80141960: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80141964: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80141968:
    // 0x80141968: lbu         $t6, 0x34($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X34);
    // 0x8014196C: lbu         $t7, 0x1C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1C);
    // 0x80141970: lbu         $t9, 0x24($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X24);
    // 0x80141974: lbu         $t1, 0x2C($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2C);
    // 0x80141978: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8014197C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80141980: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80141984: bne         $t2, $zero, L_80141998
    if (ctx->r10 != 0) {
        // 0x80141988: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80141998;
    }
    // 0x80141988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014198C: bnel        $v0, $zero, L_8014199C
    if (ctx->r2 != 0) {
        // 0x80141990: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8014199C;
    }
    goto skip_0;
    // 0x80141990: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80141994: addiu       $v1, $zero, 0xFD
    ctx->r3 = ADD32(0, 0XFD);
L_80141998:
    // 0x80141998: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8014199C:
    // 0x8014199C: jr          $ra
    // 0x801419A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801419A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801419a4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801419a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801419A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801419A8: addiu       $t7, $t7, 0x1480
    ctx->r15 = ADD32(ctx->r15, 0X1480);
    // 0x801419AC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801419b0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801419b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801419B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801419B4: addiu       $t6, $sp, 0xC
    ctx->r14 = ADD32(ctx->r29, 0XC);
    // 0x801419B8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801419BC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801419C0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801419C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801419C8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801419CC: lbu         $t9, 0xC($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XC);
    // 0x801419D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x801419D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801419D8: sb          $t9, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r25;
L_801419DC:
    // 0x801419DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801419E0: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801419E4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x801419E8: bne         $at, $zero, L_801419DC
    if (ctx->r1 != 0) {
        // 0x801419EC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801419DC;
    }
    // 0x801419EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801419F0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x801419F4: addiu       $a1, $sp, 0xC
    ctx->r5 = ADD32(ctx->r29, 0XC);
    // 0x801419F8: addiu       $v0, $sp, 0x19
    ctx->r2 = ADD32(ctx->r29, 0X19);
L_801419FC:
    // 0x801419FC: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x80141A00: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80141A04: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80141A08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141A0C: bne         $at, $zero, L_801419FC
    if (ctx->r1 != 0) {
        // 0x80141A10: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_801419FC;
    }
    // 0x80141A10: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x80141A14: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x80141A18: lbu         $t1, 0x1($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1);
    // 0x80141A1C: lbu         $t2, 0x2($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2);
    // 0x80141A20: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
    // 0x80141A24: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80141A28: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80141A2C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80141A30: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80141A34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80141A38:
    // 0x80141A38: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80141A3C: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x80141A40: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x80141A44: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80141A48: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80141A4C: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x80141A50: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80141A54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80141A58: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80141A5C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80141A60: bne         $v0, $a0, L_80141A38
    if (ctx->r2 != ctx->r4) {
        // 0x80141A64: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80141A38;
    }
    // 0x80141A64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80141A68: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // 0x80141A6C: jr          $ra
    // 0x80141A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80141A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141a74(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141a74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141A78: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80141A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80141A80: addiu       $t7, $t7, 0x1490
    ctx->r15 = ADD32(ctx->r15, 0X1490);
    // 0x80141A84: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80141A88: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
    // 0x80141A8C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80141A90: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80141A94: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80141A98: addiu       $a3, $sp, 0x8
    ctx->r7 = ADD32(ctx->r29, 0X8);
    // 0x80141A9C: addiu       $v0, $sp, 0x15
    ctx->r2 = ADD32(ctx->r29, 0X15);
    // 0x80141AA0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80141AA4: lbu         $t9, 0xC($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XC);
    // 0x80141AA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80141AAC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80141AB0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80141AB4: sb          $t9, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r25;
L_80141AB8:
    // 0x80141AB8: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x80141ABC: lbu         $t1, 0x0($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X0);
    // 0x80141AC0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80141AC4: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80141AC8: beq         $t0, $t1, L_80141AD4
    if (ctx->r8 == ctx->r9) {
        // 0x80141ACC: nop
    
            goto L_80141AD4;
    }
    // 0x80141ACC: nop

    // 0x80141AD0: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_80141AD4:
    // 0x80141AD4: bne         $at, $zero, L_80141AB8
    if (ctx->r1 != 0) {
        // 0x80141AD8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80141AB8;
    }
    // 0x80141AD8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80141ADC: bne         $v1, $zero, L_80141BC4
    if (ctx->r3 != 0) {
        // 0x80141AE0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80141BC4;
    }
    // 0x80141AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141AE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80141AE8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80141AEC:
    // 0x80141AEC: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    // 0x80141AF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80141AF4: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80141AF8: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80141AFC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80141B00: bne         $at, $zero, L_80141AEC
    if (ctx->r1 != 0) {
        // 0x80141B04: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80141AEC;
    }
    // 0x80141B04: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80141B08: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x80141B0C: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x80141B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80141B14: beq         $t3, $t4, L_80141B20
    if (ctx->r11 == ctx->r12) {
        // 0x80141B18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80141B20;
    }
    // 0x80141B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141B1C: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_80141B20:
    // 0x80141B20: bne         $v1, $zero, L_80141BC4
    if (ctx->r3 != 0) {
        // 0x80141B24: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80141BC4;
    }
    // 0x80141B24: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80141B28: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80141B2C:
    // 0x80141B2C: lbu         $t5, 0x10($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X10);
    // 0x80141B30: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80141B34: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80141B38: sb          $t5, -0x10($a0)
    MEM_B(-0X10, ctx->r4) = ctx->r13;
    // 0x80141B3C: lbu         $t6, 0x11($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X11);
    // 0x80141B40: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80141B44: sb          $t6, -0xF($a0)
    MEM_B(-0XF, ctx->r4) = ctx->r14;
    // 0x80141B48: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
    // 0x80141B4C: sb          $t7, -0xE($a0)
    MEM_B(-0XE, ctx->r4) = ctx->r15;
    // 0x80141B50: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x80141B54: sb          $t8, -0xD($a0)
    MEM_B(-0XD, ctx->r4) = ctx->r24;
    // 0x80141B58: lbu         $t0, 0x4($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X4);
    // 0x80141B5C: lbu         $t9, 0x5($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X5);
    // 0x80141B60: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80141B64: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80141B68: sh          $t2, -0xC($a0)
    MEM_H(-0XC, ctx->r4) = ctx->r10;
    // 0x80141B6C: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x80141B70: sb          $t3, -0xA($a0)
    MEM_B(-0XA, ctx->r4) = ctx->r11;
    // 0x80141B74: lbu         $t4, 0x7($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X7);
    // 0x80141B78: sb          $t4, -0x9($a0)
    MEM_B(-0X9, ctx->r4) = ctx->r12;
    // 0x80141B7C: lbu         $t5, 0x8($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X8);
    // 0x80141B80: sb          $t5, -0x8($a0)
    MEM_B(-0X8, ctx->r4) = ctx->r13;
    // 0x80141B84: lbu         $t6, 0x9($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X9);
    // 0x80141B88: sb          $t6, -0x7($a0)
    MEM_B(-0X7, ctx->r4) = ctx->r14;
    // 0x80141B8C: lbu         $t7, 0xA($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XA);
    // 0x80141B90: sb          $t7, -0x6($a0)
    MEM_B(-0X6, ctx->r4) = ctx->r15;
    // 0x80141B94: lbu         $t8, 0xB($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XB);
    // 0x80141B98: sb          $t8, -0x5($a0)
    MEM_B(-0X5, ctx->r4) = ctx->r24;
    // 0x80141B9C: lbu         $t9, 0xC($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XC);
    // 0x80141BA0: lbu         $t0, 0xD($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XD);
    // 0x80141BA4: sll         $t1, $t9, 8
    ctx->r9 = S32(ctx->r25 << 8);
    // 0x80141BA8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80141BAC: sh          $t2, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r10;
    // 0x80141BB0: lbu         $t3, 0xE($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XE);
    // 0x80141BB4: sb          $t3, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r11;
    // 0x80141BB8: lbu         $t4, 0xF($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XF);
    // 0x80141BBC: bne         $v0, $a1, L_80141B2C
    if (ctx->r2 != ctx->r5) {
        // 0x80141BC0: sb          $t4, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r12;
            goto L_80141B2C;
    }
    // 0x80141BC0: sb          $t4, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r12;
L_80141BC4:
    // 0x80141BC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80141BC8: jr          $ra
    // 0x80141BCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80141BCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141bd0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141bd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141BD0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80141BD4: addiu       $t7, $t7, 0x14A0
    ctx->r15 = ADD32(ctx->r15, 0X14A0);
    // 0x80141BD8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141bdc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141bdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141BE0: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
    // 0x80141BE4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80141BE8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80141BEC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80141BF0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80141BF4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80141BF8: lbu         $t9, 0xC($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XC);
    // 0x80141BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141C00: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80141C04: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80141C08: sb          $t9, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r25;
L_80141C0C:
    // 0x80141C0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80141C10: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80141C14: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80141C18: bne         $at, $zero, L_80141C0C
    if (ctx->r1 != 0) {
        // 0x80141C1C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80141C0C;
    }
    // 0x80141C1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141C20: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80141C24: addiu       $a0, $sp, 0x8
    ctx->r4 = ADD32(ctx->r29, 0X8);
    // 0x80141C28: addiu       $v0, $sp, 0x15
    ctx->r2 = ADD32(ctx->r29, 0X15);
L_80141C2C:
    // 0x80141C2C: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x80141C30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80141C34: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80141C38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141C3C: bne         $at, $zero, L_80141C2C
    if (ctx->r1 != 0) {
        // 0x80141C40: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_80141C2C;
    }
    // 0x80141C40: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x80141C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141C48: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80141C4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80141C50:
    // 0x80141C50: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80141C54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80141C58: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80141C5C: sb          $t1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r9;
    // 0x80141C60: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
    // 0x80141C64: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80141C68: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80141C6C: sb          $t2, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r10;
    // 0x80141C70: lbu         $t3, -0x6($a0)
    ctx->r11 = MEM_BU(ctx->r4, -0X6);
    // 0x80141C74: sb          $t3, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r11;
    // 0x80141C78: lbu         $t4, -0x5($a0)
    ctx->r12 = MEM_BU(ctx->r4, -0X5);
    // 0x80141C7C: sb          $t4, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r12;
    // 0x80141C80: lhu         $t5, -0x4($a0)
    ctx->r13 = MEM_HU(ctx->r4, -0X4);
    // 0x80141C84: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80141C88: sb          $t6, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r14;
    // 0x80141C8C: lhu         $t8, -0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, -0X4);
    // 0x80141C90: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x80141C94: lbu         $t9, -0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X2);
    // 0x80141C98: sb          $t9, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r25;
    // 0x80141C9C: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x80141CA0: bne         $at, $zero, L_80141C50
    if (ctx->r1 != 0) {
        // 0x80141CA4: sb          $t0, 0xF($v1)
        MEM_B(0XF, ctx->r3) = ctx->r8;
            goto L_80141C50;
    }
    // 0x80141CA4: sb          $t0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r8;
    // 0x80141CA8: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80141CAC: lbu         $t1, 0x1($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X1);
    // 0x80141CB0: lbu         $t2, 0x2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2);
    // 0x80141CB4: addiu       $v1, $a1, 0x3
    ctx->r3 = ADD32(ctx->r5, 0X3);
    // 0x80141CB8: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80141CBC: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80141CC0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80141CC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80141CC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80141CCC:
    // 0x80141CCC: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80141CD0: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x80141CD4: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x80141CD8: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80141CDC: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80141CE0: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80141CE4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80141CE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80141CEC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80141CF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80141CF4: bne         $v0, $a1, L_80141CCC
    if (ctx->r2 != ctx->r5) {
        // 0x80141CF8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80141CCC;
    }
    // 0x80141CF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80141CFC: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80141D00: jr          $ra
    // 0x80141D04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80141D04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80141d08(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80141d08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141D08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80141D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141D10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80141D14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80141D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80141D1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80141D20:
    // 0x80141D20: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80141D24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141D28: slti        $at, $v1, 0xCFF
    ctx->r1 = SIGNED(ctx->r3) < 0XCFF ? 1 : 0;
    // 0x80141D2C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80141D30: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80141D34: bne         $at, $zero, L_80141D20
    if (ctx->r1 != 0) {
        // 0x80141D38: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80141D20;
    }
    // 0x80141D38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80141D3C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80141D40: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80141D44: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
    // 0x80141D48: beq         $t7, $t8, L_80141D58
    if (ctx->r15 == ctx->r24) {
        // 0x80141D4C: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80141D58;
    }
    // 0x80141D4C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80141D50: b           L_80141F14
    // 0x80141D54: sb          $t9, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r25;
        goto L_80141F14;
    // 0x80141D54: sb          $t9, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r25;
L_80141D58:
    // 0x80141D58: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x80141D5C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80141D60: jal         0x80144E68
    // 0x80141D64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80144E68)(rdram, ctx);
        goto after_0;
    // 0x80141D64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80141D68: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80141D6C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80141D70: addiu       $t0, $t0, -0x23E0
    ctx->r8 = ADD32(ctx->r8, -0X23E0);
    // 0x80141D74: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80141D78: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80141D7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80141D80: addiu       $a0, $a2, 0x300
    ctx->r4 = ADD32(ctx->r6, 0X300);
L_80141D84:
    // 0x80141D84: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80141D88: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80141D8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80141D90: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80141D94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141D98: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80141D9C: bne         $at, $zero, L_80141D84
    if (ctx->r1 != 0) {
        // 0x80141DA0: sb          $t1, 0x0($t3)
        MEM_B(0X0, ctx->r11) = ctx->r9;
            goto L_80141D84;
    }
    // 0x80141DA0: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x80141DA4: jal         0x8014B8DC
    // 0x80141DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8014B8DC)(rdram, ctx);
        goto after_1;
    // 0x80141DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80141DAC: jal         0x8014C294
    // 0x80141DB0: nop

    LOOKUP_FUNC(0x8014C294)(rdram, ctx);
        goto after_2;
    // 0x80141DB0: nop

    after_2:
    // 0x80141DB4: jal         0x8014C2A0
    // 0x80141DB8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8014C2A0)(rdram, ctx);
        goto after_3;
    // 0x80141DB8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80141DBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80141DC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80141DC4: blez        $v0, L_80141DEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80141DC8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80141DEC;
    }
    // 0x80141DC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80141DCC:
    // 0x80141DCC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80141DD0: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80141DD4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80141DD8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80141DDC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141DE0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80141DE4: bne         $at, $zero, L_80141DCC
    if (ctx->r1 != 0) {
        // 0x80141DE8: sb          $t4, 0x0($t6)
        MEM_B(0X0, ctx->r14) = ctx->r12;
            goto L_80141DCC;
    }
    // 0x80141DE8: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
L_80141DEC:
    // 0x80141DEC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80141DF0: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x80141DF4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80141DF8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80141DFC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80141E00: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80141E04: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x80141E08: lbu         $t1, 0x2($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2);
    // 0x80141E0C: lbu         $t2, 0x3($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X3);
    // 0x80141E10: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x80141E14: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x80141E18: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80141E1C: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x80141E20: lbu         $t6, -0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0X18);
    // 0x80141E24: lbu         $t4, -0x17($a0)
    ctx->r12 = MEM_BU(ctx->r4, -0X17);
    // 0x80141E28: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x80141E2C: addu        $t7, $t4, $t8
    ctx->r15 = ADD32(ctx->r12, ctx->r24);
    // 0x80141E30: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x80141E34: lbu         $t0, -0x16($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X16);
    // 0x80141E38: lbu         $t9, -0x15($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X15);
    // 0x80141E3C: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80141E40: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80141E44: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x80141E48: lbu         $t5, -0x14($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X14);
    // 0x80141E4C: lbu         $t3, -0x13($a0)
    ctx->r11 = MEM_BU(ctx->r4, -0X13);
    // 0x80141E50: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80141E54: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x80141E58: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x80141E5C: lbu         $t7, -0x12($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X12);
    // 0x80141E60: lbu         $t8, -0x11($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X11);
    // 0x80141E64: sll         $t0, $t7, 8
    ctx->r8 = S32(ctx->r15 << 8);
    // 0x80141E68: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80141E6C: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x80141E70: lbu         $t2, -0x10($a0)
    ctx->r10 = MEM_BU(ctx->r4, -0X10);
    // 0x80141E74: lbu         $t1, -0xF($a0)
    ctx->r9 = MEM_BU(ctx->r4, -0XF);
    // 0x80141E78: sll         $t5, $t2, 8
    ctx->r13 = S32(ctx->r10 << 8);
    // 0x80141E7C: addu        $t3, $t1, $t5
    ctx->r11 = ADD32(ctx->r9, ctx->r13);
    // 0x80141E80: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x80141E84: lbu         $t4, -0xE($a0)
    ctx->r12 = MEM_BU(ctx->r4, -0XE);
    // 0x80141E88: lbu         $t6, -0xD($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0XD);
    // 0x80141E8C: sll         $t7, $t4, 8
    ctx->r15 = S32(ctx->r12 << 8);
    // 0x80141E90: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80141E94: sb          $t8, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r24;
    // 0x80141E98: lbu         $t9, -0xC($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0XC);
    // 0x80141E9C: lbu         $t0, -0xB($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0XB);
    // 0x80141EA0: sll         $t2, $t9, 8
    ctx->r10 = S32(ctx->r25 << 8);
    // 0x80141EA4: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x80141EA8: sb          $t1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r9;
    // 0x80141EAC: lbu         $t3, -0xA($a0)
    ctx->r11 = MEM_BU(ctx->r4, -0XA);
    // 0x80141EB0: lbu         $t5, -0x9($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X9);
    // 0x80141EB4: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80141EB8: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80141EBC: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80141EC0: lbu         $t7, -0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X8);
    // 0x80141EC4: sb          $t7, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r15;
    // 0x80141EC8: lbu         $t8, -0x7($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X7);
    // 0x80141ECC: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
    // 0x80141ED0: lbu         $t9, -0x6($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X6);
    // 0x80141ED4: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
    // 0x80141ED8: sb          $t9, 0x39D($v0)
    MEM_B(0X39D, ctx->r2) = ctx->r25;
    // 0x80141EDC: lbu         $t2, -0x5($a0)
    ctx->r10 = MEM_BU(ctx->r4, -0X5);
    // 0x80141EE0: lbu         $t0, -0x4($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X4);
    // 0x80141EE4: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x80141EE8: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80141EEC: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x80141EF0: lbu         $t5, -0x3($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X3);
    // 0x80141EF4: sb          $t5, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r13;
    // 0x80141EF8: lbu         $t4, -0x2($a0)
    ctx->r12 = MEM_BU(ctx->r4, -0X2);
    // 0x80141EFC: sb          $t4, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r12;
    // 0x80141F00: lbu         $t6, -0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0X1);
    // 0x80141F04: sb          $t6, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r14;
    // 0x80141F08: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80141F0C: sh          $t8, 0x18C($v0)
    MEM_H(0X18C, ctx->r2) = ctx->r24;
    // 0x80141F10: sb          $t7, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r15;
L_80141F14:
    // 0x80141F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141F18: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x80141F1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80141F20: jr          $ra
    // 0x80141F24: nop

    return;
    // 0x80141F24: nop

;}
RECOMP_FUNC void M7_FUN_80141f28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141F28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80141F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141F30: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80141F34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80141F38: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80141F3C:
    // 0x80141F3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141F40: slti        $at, $v1, 0xD00
    ctx->r1 = SIGNED(ctx->r3) < 0XD00 ? 1 : 0;
    // 0x80141F44: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80141F48: bne         $at, $zero, L_80141F3C
    if (ctx->r1 != 0) {
        // 0x80141F4C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80141F3C;
    }
    // 0x80141F4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80141F50: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80141F54: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80141F58: jal         0x80144C40
    // 0x80141F5C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80144C40)(rdram, ctx);
        goto after_0;
    // 0x80141F5C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80141F60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80141F64: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80141F68: addiu       $t6, $t6, -0x23E0
    ctx->r14 = ADD32(ctx->r14, -0X23E0);
    // 0x80141F6C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80141F70: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80141F74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80141F78: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
L_80141F7C:
    // 0x80141F7C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80141F80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80141F84: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80141F88: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80141F8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141F90: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80141F94: bne         $at, $zero, L_80141F7C
    if (ctx->r1 != 0) {
        // 0x80141F98: sb          $t9, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r25;
            goto L_80141F7C;
    }
    // 0x80141F98: sb          $t9, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r25;
    // 0x80141F9C: jal         0x8014B8DC
    // 0x80141FA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8014B8DC)(rdram, ctx);
        goto after_1;
    // 0x80141FA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80141FA4: jal         0x8014C294
    // 0x80141FA8: nop

    LOOKUP_FUNC(0x8014C294)(rdram, ctx);
        goto after_2;
    // 0x80141FA8: nop

    after_2:
    // 0x80141FAC: jal         0x8014C2A0
    // 0x80141FB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8014C2A0)(rdram, ctx);
        goto after_3;
    // 0x80141FB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80141FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80141FB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80141FBC: blez        $v0, L_80141FE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80141FC0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80141FE4;
    }
    // 0x80141FC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80141FC4:
    // 0x80141FC4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80141FC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80141FCC: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80141FD0: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80141FD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80141FD8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80141FDC: bne         $at, $zero, L_80141FC4
    if (ctx->r1 != 0) {
        // 0x80141FE0: sb          $t2, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r10;
            goto L_80141FC4;
    }
    // 0x80141FE0: sb          $t2, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r10;
L_80141FE4:
    // 0x80141FE4: jal         0x80126968
    // 0x80141FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80126968)(rdram, ctx);
        goto after_4;
    // 0x80141FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x80141FEC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80141FF0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80141FF4: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    // 0x80141FF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80141FFC: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80142000: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80142004: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x80142008: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8014200C: sb          $t6, -0x1B($a0)
    MEM_B(-0X1B, ctx->r4) = ctx->r14;
    // 0x80142010: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    // 0x80142014: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80142018: sb          $t8, -0x1A($a0)
    MEM_B(-0X1A, ctx->r4) = ctx->r24;
    // 0x8014201C: lhu         $t0, 0x4($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4);
    // 0x80142020: sb          $t0, -0x19($a0)
    MEM_B(-0X19, ctx->r4) = ctx->r8;
    // 0x80142024: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
    // 0x80142028: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8014202C: sb          $t2, -0x18($a0)
    MEM_B(-0X18, ctx->r4) = ctx->r10;
    // 0x80142030: lhu         $t4, 0x6($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X6);
    // 0x80142034: sb          $t4, -0x17($a0)
    MEM_B(-0X17, ctx->r4) = ctx->r12;
    // 0x80142038: lhu         $t5, 0xE($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XE);
    // 0x8014203C: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80142040: sb          $t6, -0x16($a0)
    MEM_B(-0X16, ctx->r4) = ctx->r14;
    // 0x80142044: lhu         $t8, 0xE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XE);
    // 0x80142048: sb          $t8, -0x15($a0)
    MEM_B(-0X15, ctx->r4) = ctx->r24;
    // 0x8014204C: lhu         $t9, 0x10($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X10);
    // 0x80142050: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x80142054: sb          $t0, -0x14($a0)
    MEM_B(-0X14, ctx->r4) = ctx->r8;
    // 0x80142058: lhu         $t2, 0x10($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X10);
    // 0x8014205C: sb          $t2, -0x13($a0)
    MEM_B(-0X13, ctx->r4) = ctx->r10;
    // 0x80142060: lhu         $t3, 0x12($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X12);
    // 0x80142064: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80142068: sb          $t4, -0x12($a0)
    MEM_B(-0X12, ctx->r4) = ctx->r12;
    // 0x8014206C: lhu         $t6, 0x12($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X12);
    // 0x80142070: sb          $t6, -0x11($a0)
    MEM_B(-0X11, ctx->r4) = ctx->r14;
    // 0x80142074: lhu         $t7, 0x14($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X14);
    // 0x80142078: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8014207C: sb          $t8, -0x10($a0)
    MEM_B(-0X10, ctx->r4) = ctx->r24;
    // 0x80142080: lhu         $t0, 0x14($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X14);
    // 0x80142084: sb          $t0, -0xF($a0)
    MEM_B(-0XF, ctx->r4) = ctx->r8;
    // 0x80142088: lbu         $t1, 0x16($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X16);
    // 0x8014208C: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80142090: sb          $t2, -0xE($a0)
    MEM_B(-0XE, ctx->r4) = ctx->r10;
    // 0x80142094: lbu         $t4, 0x16($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X16);
    // 0x80142098: sb          $t4, -0xD($a0)
    MEM_B(-0XD, ctx->r4) = ctx->r12;
    // 0x8014209C: lb          $t5, 0x18($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X18);
    // 0x801420A0: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x801420A4: sb          $t6, -0xC($a0)
    MEM_B(-0XC, ctx->r4) = ctx->r14;
    // 0x801420A8: lb          $t8, 0x18($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X18);
    // 0x801420AC: sb          $t8, -0xB($a0)
    MEM_B(-0XB, ctx->r4) = ctx->r24;
    // 0x801420B0: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x801420B4: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x801420B8: sb          $t0, -0xA($a0)
    MEM_B(-0XA, ctx->r4) = ctx->r8;
    // 0x801420BC: lhu         $t2, 0x8($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X8);
    // 0x801420C0: sb          $t2, -0x9($a0)
    MEM_B(-0X9, ctx->r4) = ctx->r10;
    // 0x801420C4: lb          $t3, 0x19($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X19);
    // 0x801420C8: sb          $t3, -0x8($a0)
    MEM_B(-0X8, ctx->r4) = ctx->r11;
    // 0x801420CC: lbu         $t4, 0x17($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X17);
    // 0x801420D0: sb          $t4, -0x7($a0)
    MEM_B(-0X7, ctx->r4) = ctx->r12;
    // 0x801420D4: lbu         $t5, 0x39D($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X39D);
    // 0x801420D8: sb          $t5, -0x6($a0)
    MEM_B(-0X6, ctx->r4) = ctx->r13;
    // 0x801420DC: lhu         $t6, 0xA($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XA);
    // 0x801420E0: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x801420E4: sb          $t7, -0x5($a0)
    MEM_B(-0X5, ctx->r4) = ctx->r15;
    // 0x801420E8: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x801420EC: sb          $t9, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r25;
    // 0x801420F0: lbu         $t0, 0x1A($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1A);
    // 0x801420F4: sb          $t0, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r8;
    // 0x801420F8: lbu         $t1, 0x1B($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1B);
    // 0x801420FC: sb          $t1, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r9;
    // 0x80142100: lbu         $t2, 0x1C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1C);
    // 0x80142104: sb          $t2, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r10;
    // 0x80142108: lbu         $t3, 0x1D($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1D);
    // 0x8014210C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80142110: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80142114: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80142118: addiu       $a0, $zero, 0xCFF
    ctx->r4 = ADD32(0, 0XCFF);
    // 0x8014211C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80142120: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80142124: lbu         $t5, 0x2($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X2);
    // 0x80142128: addiu       $a1, $a2, 0x3
    ctx->r5 = ADD32(ctx->r6, 0X3);
    // 0x8014212C: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80142130: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80142134: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80142138:
    // 0x80142138: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8014213C: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80142140: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x80142144: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x80142148: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8014214C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80142150: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80142154: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80142158: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8014215C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80142160: bne         $v1, $a0, L_80142138
    if (ctx->r3 != ctx->r4) {
        // 0x80142164: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80142138;
    }
    // 0x80142164: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80142168: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8014216C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80142174: jr          $ra
    // 0x80142178: nop

    return;
    // 0x80142178: nop

;}
RECOMP_FUNC void M7_FUN_8014217c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014217C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80142180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142184: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80142188: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x8014218C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80142190: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x80142194: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80142198: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8014219C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x801421A0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801421A4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x801421A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801421AC: addiu       $v1, $a2, 0x3
    ctx->r3 = ADD32(ctx->r6, 0X3);
    // 0x801421B0: addiu       $a1, $zero, 0xCFF
    ctx->r5 = ADD32(0, 0XCFF);
L_801421B4:
    // 0x801421B4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x801421B8: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x801421BC: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
    // 0x801421C0: lbu         $t1, 0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3);
    // 0x801421C4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801421C8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x801421CC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x801421D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801421D4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801421D8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x801421DC: bne         $a0, $a1, L_801421B4
    if (ctx->r4 != ctx->r5) {
        // 0x801421E0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801421B4;
    }
    // 0x801421E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801421E4: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x801421E8: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x801421EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801421F0: beq         $t2, $t3, L_80142200
    if (ctx->r10 == ctx->r11) {
        // 0x801421F4: andi        $t4, $a3, 0x1
        ctx->r12 = ctx->r7 & 0X1;
            goto L_80142200;
    }
    // 0x801421F4: andi        $t4, $a3, 0x1
    ctx->r12 = ctx->r7 & 0X1;
    // 0x801421F8: b           L_8014222C
    // 0x801421FC: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
        goto L_8014222C;
    // 0x801421FC: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_80142200:
    // 0x80142200: beq         $t4, $zero, L_8014221C
    if (ctx->r12 == 0) {
        // 0x80142204: sw          $a2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r6;
            goto L_8014221C;
    }
    // 0x80142204: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80142208: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8014220C: jal         0x80145014
    // 0x80142210: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    LOOKUP_FUNC(0x80145014)(rdram, ctx);
        goto after_0;
    // 0x80142210: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    after_0:
    // 0x80142214: b           L_8014222C
    // 0x80142218: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
        goto L_8014222C;
    // 0x80142218: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
L_8014221C:
    // 0x8014221C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80142220: jal         0x80144E68
    // 0x80142224: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80144E68)(rdram, ctx);
        goto after_1;
    // 0x80142224: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    after_1:
    // 0x80142228: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
L_8014222C:
    // 0x8014222C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142230: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80142234: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80142238: jr          $ra
    // 0x8014223C: nop

    return;
    // 0x8014223C: nop

;}
RECOMP_FUNC void M7_FUN_80142240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142240: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80142244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142248: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014224C: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x80142250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80142254: jal         0x80002EF0
    // 0x80142258: addiu       $a2, $zero, 0x3500
    ctx->r6 = ADD32(0, 0X3500);
    LOOKUP_FUNC(0x80002EF0)(rdram, ctx);
        goto after_0;
    // 0x80142258: addiu       $a2, $zero, 0x3500
    ctx->r6 = ADD32(0, 0X3500);
    after_0:
    // 0x8014225C: beq         $v0, $zero, L_80142270
    if (ctx->r2 == 0) {
        // 0x80142260: sb          $v0, 0x2B($sp)
        MEM_B(0X2B, ctx->r29) = ctx->r2;
            goto L_80142270;
    }
    // 0x80142260: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x80142264: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80142268: bnel        $v0, $at, L_801422D4
    if (ctx->r2 != ctx->r1) {
        // 0x8014226C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801422D4;
    }
    goto skip_0;
    // 0x8014226C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80142270:
    // 0x80142270: jal         0x8001F430
    // 0x80142274: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_1;
    // 0x80142274: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_1:
    // 0x80142278: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8014227C: jal         0x801419A4
    // 0x80142280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x801419A4)(rdram, ctx);
        goto after_2;
    // 0x80142280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80142284: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80142288: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x8014228C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80142290: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142294: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80142298: jal         0x800032E0
    // 0x8014229C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x800032E0)(rdram, ctx);
        goto after_3;
    // 0x8014229C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x801422A0: beq         $v0, $zero, L_801422C8
    if (ctx->r2 == 0) {
        // 0x801422A4: sb          $v0, 0x2B($sp)
        MEM_B(0X2B, ctx->r29) = ctx->r2;
            goto L_801422C8;
    }
    // 0x801422A4: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x801422A8: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x801422AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801422B0: jal         0x80002DBC
    // 0x801422B4: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x80002DBC)(rdram, ctx);
        goto after_4;
    // 0x801422B4: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    after_4:
    // 0x801422B8: bne         $v0, $zero, L_801422C8
    if (ctx->r2 != 0) {
        // 0x801422BC: lbu         $a0, 0x33($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X33);
            goto L_801422C8;
    }
    // 0x801422BC: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x801422C0: jal         0x8000303C
    // 0x801422C4: lbu         $a1, 0x2A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x8000303C)(rdram, ctx);
        goto after_5;
    // 0x801422C4: lbu         $a1, 0x2A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2A);
    after_5:
L_801422C8:
    // 0x801422C8: jal         0x8001F540
    // 0x801422CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_6;
    // 0x801422CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x801422D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801422D4:
    // 0x801422D4: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x801422D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801422DC: jr          $ra
    // 0x801422E0: nop

    return;
    // 0x801422E0: nop

;}
RECOMP_FUNC void M7_FUN_801422e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801422E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801422E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801422EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801422F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801422F4: jal         0x8001F430
    // 0x801422F8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_0;
    // 0x801422F8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x801422FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80142300: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80142304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80142308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014230C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80142310: jal         0x800031EC
    // 0x80142314: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x800031EC)(rdram, ctx);
        goto after_1;
    // 0x80142314: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80142318: bne         $v0, $zero, L_80142330
    if (ctx->r2 != 0) {
        // 0x8014231C: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80142330;
    }
    // 0x8014231C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80142320: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80142324: jal         0x80141A74
    // 0x80142328: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80141A74)(rdram, ctx);
        goto after_2;
    // 0x80142328: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014232C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80142330:
    // 0x80142330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80142334: jal         0x8001F540
    // 0x80142338: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_3;
    // 0x80142338: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_3:
    // 0x8014233C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142340: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x80142344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142348: jr          $ra
    // 0x8014234C: nop

    return;
    // 0x8014234C: nop

;}
RECOMP_FUNC void M7_FUN_80142350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142358: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014235C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80142360: jal         0x80002BE0
    // 0x80142364: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80142364: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x80142368: bne         $v0, $zero, L_801423B4
    if (ctx->r2 != 0) {
        // 0x8014236C: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_801423B4;
    }
    // 0x8014236C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80142370: jal         0x8001F430
    // 0x80142374: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_1;
    // 0x80142374: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_1:
    // 0x80142378: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8014237C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80142380: jal         0x80141BD0
    // 0x80142384: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80141BD0)(rdram, ctx);
        goto after_2;
    // 0x80142384: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80142388: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8014238C: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80142390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80142394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142398: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8014239C: jal         0x800032E0
    // 0x801423A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x800032E0)(rdram, ctx);
        goto after_3;
    // 0x801423A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x801423A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801423A8: jal         0x8001F540
    // 0x801423AC: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_4;
    // 0x801423AC: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    after_4:
    // 0x801423B0: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
L_801423B4:
    // 0x801423B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801423B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801423BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801423C0: jr          $ra
    // 0x801423C4: nop

    return;
    // 0x801423C4: nop

;}
RECOMP_FUNC void M7_FUN_801423c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801423C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801423CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801423D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801423D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801423D8: jal         0x8001F430
    // 0x801423DC: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_0;
    // 0x801423DC: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    after_0:
    // 0x801423E0: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x801423E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801423E8: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x801423EC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801423F0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801423F4: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x801423F8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801423FC: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80142400: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x80142404: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x80142408: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8014240C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80142410: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x80142414: jal         0x800031EC
    // 0x80142418: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x800031EC)(rdram, ctx);
        goto after_1;
    // 0x80142418: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x8014241C: bne         $v0, $zero, L_80142430
    if (ctx->r2 != 0) {
        // 0x80142420: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80142430;
    }
    // 0x80142420: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80142424: jal         0x80141D08
    // 0x80142428: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80141D08)(rdram, ctx);
        goto after_2;
    // 0x80142428: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014242C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80142430:
    // 0x80142430: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80142434: jal         0x8001F540
    // 0x80142438: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_3;
    // 0x80142438: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_3:
    // 0x8014243C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142440: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x80142444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142448: jr          $ra
    // 0x8014244C: nop

    return;
    // 0x8014244C: nop

;}
RECOMP_FUNC void M7_FUN_80142450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142458: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014245C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80142460: jal         0x8001F430
    // 0x80142464: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_0;
    // 0x80142464: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    after_0:
    // 0x80142468: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8014246C: jal         0x80141F28
    // 0x80142470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80141F28)(rdram, ctx);
        goto after_1;
    // 0x80142470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80142474: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x80142478: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8014247C: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80142480: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80142484: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80142488: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8014248C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80142490: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80142494: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x80142498: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x8014249C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x801424A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801424A4: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x801424A8: jal         0x800032E0
    // 0x801424AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x800032E0)(rdram, ctx);
        goto after_2;
    // 0x801424AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x801424B0: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x801424B4: jal         0x8001F540
    // 0x801424B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_3;
    // 0x801424B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801424BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801424C0: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x801424C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801424C8: jr          $ra
    // 0x801424CC: nop

    return;
    // 0x801424CC: nop

;}
RECOMP_FUNC void M7_FUN_801424d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801424D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801424D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801424D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801424DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801424E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801424E4: jal         0x8001F430
    // 0x801424E8: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_0;
    // 0x801424E8: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    after_0:
    // 0x801424EC: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x801424F0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801424F4: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x801424F8: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801424FC: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80142500: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x80142504: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80142508: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8014250C: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x80142510: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x80142514: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80142518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014251C: addiu       $a3, $zero, 0xD00
    ctx->r7 = ADD32(0, 0XD00);
    // 0x80142520: jal         0x800031EC
    // 0x80142524: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x800031EC)(rdram, ctx);
        goto after_1;
    // 0x80142524: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80142528: bne         $v0, $zero, L_80142540
    if (ctx->r2 != 0) {
        // 0x8014252C: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80142540;
    }
    // 0x8014252C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80142530: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x80142534: jal         0x8014217C
    // 0x80142538: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8014217C)(rdram, ctx);
        goto after_2;
    // 0x80142538: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014253C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80142540:
    // 0x80142540: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80142544: jal         0x8001F540
    // 0x80142548: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_3;
    // 0x80142548: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_3:
    // 0x8014254C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142550: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x80142554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142558: jr          $ra
    // 0x8014255C: nop

    return;
    // 0x8014255C: nop

;}
RECOMP_FUNC void M7_FUN_80142560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142560: nop

    // 0x80142564: nop

    // 0x80142568: nop

    // 0x8014256C: nop

;}
RECOMP_FUNC void M7_FUN_80142570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142570: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80142574: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80142578: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8014257C: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80142580: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80142584: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80142588: addiu       $s1, $s1, -0xF10
    ctx->r17 = ADD32(ctx->r17, -0XF10);
    // 0x8014258C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80142590: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80142594:
    // 0x80142594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80142598: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014259C: jal         0x8001B204
    // 0x801425A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801425A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
    // 0x801425A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801425A8: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
    // 0x801425AC: bnel        $at, $zero, L_80142594
    if (ctx->r1 != 0) {
        // 0x801425B0: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80142594;
    }
    goto skip_0;
    // 0x801425B0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
    // 0x801425B4: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x801425B8: addiu       $s1, $s1, -0xF0C
    ctx->r17 = ADD32(ctx->r17, -0XF0C);
    // 0x801425BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801425C0: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x801425C4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_801425C8:
    // 0x801425C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801425CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801425D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801425D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801425D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801425DC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801425E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801425E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801425E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801425EC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801425F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801425F4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801425F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801425FC: jal         0x8001A804
    // 0x80142600: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x80142600: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_1:
    // 0x80142604: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80142608: bnel        $s0, $s2, L_801425C8
    if (ctx->r16 != ctx->r18) {
        // 0x8014260C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_801425C8;
    }
    goto skip_1;
    // 0x8014260C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_1:
    // 0x80142610: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142614: addiu       $a1, $a1, -0xEE4
    ctx->r5 = ADD32(ctx->r5, -0XEE4);
    // 0x80142618: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8014261C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142620: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80142624: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80142628: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8014262C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80142630: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80142634: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80142638: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8014263C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80142640: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80142644: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80142648: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8014264C: jal         0x8001A804
    // 0x80142650: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80142650: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_2:
    // 0x80142654: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142658: addiu       $a1, $a1, -0xEBC
    ctx->r5 = ADD32(ctx->r5, -0XEBC);
    // 0x8014265C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80142660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142664: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80142668: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014266C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80142670: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80142674: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80142678: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014267C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80142680: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80142684: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80142688: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8014268C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80142690: jal         0x8001A804
    // 0x80142694: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80142694: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_3:
    // 0x80142698: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8014269C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801426A0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801426A4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801426A8: jr          $ra
    // 0x801426AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801426AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801426b0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801426b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801426B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801426B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801426B8: jal         0x80142570
    // 0x801426BC: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x801426BC: nop

    after_0:
    // 0x801426C0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801426C4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x801426C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801426CC: addiu       $a3, $a3, -0xE94
    ctx->r7 = ADD32(ctx->r7, -0XE94);
    // 0x801426D0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801426D4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801426D8: jal         0x8001B204
    // 0x801426DC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801426DC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_1:
    // 0x801426E0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801426E4: addiu       $a3, $a3, -0xE7C
    ctx->r7 = ADD32(ctx->r7, -0XE7C);
    // 0x801426E8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801426EC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x801426F0: jal         0x8001B204
    // 0x801426F4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801426F4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x801426F8: addiu       $t7, $zero, 0x7A
    ctx->r15 = ADD32(0, 0X7A);
    // 0x801426FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80142700: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80142704: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142708: addiu       $t8, $zero, 0x5C
    ctx->r24 = ADD32(0, 0X5C);
    // 0x8014270C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80142710: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x80142714: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80142718: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8014271C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80142720: addiu       $t4, $zero, 0x90
    ctx->r12 = ADD32(0, 0X90);
    // 0x80142724: addiu       $t5, $zero, 0x90
    ctx->r13 = ADD32(0, 0X90);
    // 0x80142728: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x8014272C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80142730: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80142734: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80142738: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8014273C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80142740: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80142744: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80142748: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8014274C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80142750: addiu       $a1, $a1, -0xE6C
    ctx->r5 = ADD32(ctx->r5, -0XE6C);
    // 0x80142754: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80142758: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8014275C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80142760: jal         0x8001A804
    // 0x80142764: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80142764: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_3:
    // 0x80142768: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8014276C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80142770: jr          $ra
    // 0x80142774: nop

    return;
    // 0x80142774: nop

;}
RECOMP_FUNC void M7_FUN_80142778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142778: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014277C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80142780: jal         0x80142570
    // 0x80142784: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x80142784: nop

    after_0:
    // 0x80142788: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014278C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80142790: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80142794: addiu       $a3, $a3, -0xE44
    ctx->r7 = ADD32(ctx->r7, -0XE44);
    // 0x80142798: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8014279C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801427A0: jal         0x8001B204
    // 0x801427A4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801427A4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_1:
    // 0x801427A8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801427AC: addiu       $a3, $a3, -0xE2C
    ctx->r7 = ADD32(ctx->r7, -0XE2C);
    // 0x801427B0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801427B4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x801427B8: jal         0x8001B204
    // 0x801427BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801427BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x801427C0: addiu       $t7, $zero, 0x7A
    ctx->r15 = ADD32(0, 0X7A);
    // 0x801427C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801427C8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801427CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801427D0: addiu       $t8, $zero, 0x5C
    ctx->r24 = ADD32(0, 0X5C);
    // 0x801427D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801427D8: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x801427DC: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801427E0: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801427E4: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801427E8: addiu       $t4, $zero, 0x90
    ctx->r12 = ADD32(0, 0X90);
    // 0x801427EC: addiu       $t5, $zero, 0x90
    ctx->r13 = ADD32(0, 0X90);
    // 0x801427F0: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x801427F4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801427F8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801427FC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80142800: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80142804: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80142808: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8014280C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80142810: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80142814: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80142818: addiu       $a1, $a1, -0xE1C
    ctx->r5 = ADD32(ctx->r5, -0XE1C);
    // 0x8014281C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80142820: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80142824: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80142828: jal         0x8001A804
    // 0x8014282C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x8014282C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_3:
    // 0x80142830: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80142834: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80142838: jr          $ra
    // 0x8014283C: nop

    return;
    // 0x8014283C: nop

;}
RECOMP_FUNC void M7_FUN_80142840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142840: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80142844: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80142848: jal         0x80142570
    // 0x8014284C: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x8014284C: nop

    after_0:
    // 0x80142850: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80142854: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80142858: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014285C: addiu       $a3, $a3, -0xDF4
    ctx->r7 = ADD32(ctx->r7, -0XDF4);
    // 0x80142860: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80142864: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80142868: jal         0x8001B204
    // 0x8014286C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8014286C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_1:
    // 0x80142870: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80142874: addiu       $a3, $a3, -0xDD0
    ctx->r7 = ADD32(ctx->r7, -0XDD0);
    // 0x80142878: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8014287C: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80142880: jal         0x8001B204
    // 0x80142884: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x80142884: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x80142888: addiu       $t7, $zero, 0x7A
    ctx->r15 = ADD32(0, 0X7A);
    // 0x8014288C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80142890: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80142894: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142898: addiu       $t8, $zero, 0x5C
    ctx->r24 = ADD32(0, 0X5C);
    // 0x8014289C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801428A0: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x801428A4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801428A8: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801428AC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801428B0: addiu       $t4, $zero, 0x90
    ctx->r12 = ADD32(0, 0X90);
    // 0x801428B4: addiu       $t5, $zero, 0x90
    ctx->r13 = ADD32(0, 0X90);
    // 0x801428B8: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x801428BC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801428C0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801428C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801428C8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801428CC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801428D0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801428D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801428D8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801428DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801428E0: addiu       $a1, $a1, -0xDAC
    ctx->r5 = ADD32(ctx->r5, -0XDAC);
    // 0x801428E4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801428E8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801428EC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801428F0: jal         0x8001A804
    // 0x801428F4: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x801428F4: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_3:
    // 0x801428F8: addiu       $t8, $zero, 0x7A
    ctx->r24 = ADD32(0, 0X7A);
    // 0x801428FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80142900: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142904: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142908: addiu       $t9, $zero, 0x5C
    ctx->r25 = ADD32(0, 0X5C);
    // 0x8014290C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80142910: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80142914: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80142918: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8014291C: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80142920: addiu       $t5, $zero, 0x90
    ctx->r13 = ADD32(0, 0X90);
    // 0x80142924: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x80142928: addiu       $t7, $zero, 0x90
    ctx->r15 = ADD32(0, 0X90);
    // 0x8014292C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80142930: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80142934: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80142938: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8014293C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80142940: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80142944: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80142948: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8014294C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80142950: addiu       $a1, $a1, -0xD84
    ctx->r5 = ADD32(ctx->r5, -0XD84);
    // 0x80142954: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80142958: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8014295C: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x80142960: jal         0x8001A804
    // 0x80142964: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_4;
    // 0x80142964: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_4:
    // 0x80142968: addiu       $t9, $zero, 0x7A
    ctx->r25 = ADD32(0, 0X7A);
    // 0x8014296C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80142970: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x80142974: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142978: addiu       $t0, $zero, 0x35
    ctx->r8 = ADD32(0, 0X35);
    // 0x8014297C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80142980: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80142984: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80142988: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x8014298C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80142990: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x80142994: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x80142998: addiu       $t8, $zero, 0xC0
    ctx->r24 = ADD32(0, 0XC0);
    // 0x8014299C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x801429A0: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801429A4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801429A8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801429AC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801429B0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801429B4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801429B8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801429BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801429C0: addiu       $a1, $a1, -0xD5C
    ctx->r5 = ADD32(ctx->r5, -0XD5C);
    // 0x801429C4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801429C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801429CC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801429D0: jal         0x8001A804
    // 0x801429D4: addiu       $a3, $zero, 0xA6
    ctx->r7 = ADD32(0, 0XA6);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_5;
    // 0x801429D4: addiu       $a3, $zero, 0xA6
    ctx->r7 = ADD32(0, 0XA6);
    after_5:
    // 0x801429D8: addiu       $t0, $zero, 0x7A
    ctx->r8 = ADD32(0, 0X7A);
    // 0x801429DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801429E0: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
    // 0x801429E4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801429E8: addiu       $t1, $zero, 0x35
    ctx->r9 = ADD32(0, 0X35);
    // 0x801429EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801429F0: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801429F4: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x801429F8: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x801429FC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80142A00: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x80142A04: addiu       $t8, $zero, 0xC0
    ctx->r24 = ADD32(0, 0XC0);
    // 0x80142A08: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x80142A0C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80142A10: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80142A14: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80142A18: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80142A1C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80142A20: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80142A24: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80142A28: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80142A2C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80142A30: addiu       $a1, $a1, -0xD34
    ctx->r5 = ADD32(ctx->r5, -0XD34);
    // 0x80142A34: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80142A38: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80142A3C: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x80142A40: jal         0x8001A804
    // 0x80142A44: addiu       $a3, $zero, 0xA6
    ctx->r7 = ADD32(0, 0XA6);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_6;
    // 0x80142A44: addiu       $a3, $zero, 0xA6
    ctx->r7 = ADD32(0, 0XA6);
    after_6:
    // 0x80142A48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80142A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80142A50: jr          $ra
    // 0x80142A54: nop

    return;
    // 0x80142A54: nop

;}
RECOMP_FUNC void M7_FUN_80142a58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142A58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80142A5C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80142A60: jal         0x80142570
    // 0x80142A64: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x80142A64: nop

    after_0:
    // 0x80142A68: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80142A6C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80142A70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80142A74: addiu       $a3, $a3, -0xD0C
    ctx->r7 = ADD32(ctx->r7, -0XD0C);
    // 0x80142A78: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80142A7C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80142A80: jal         0x8001B204
    // 0x80142A84: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80142A84: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_1:
    // 0x80142A88: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80142A8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80142A90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80142A94: addiu       $a3, $a3, -0xCF4
    ctx->r7 = ADD32(ctx->r7, -0XCF4);
    // 0x80142A98: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80142A9C: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80142AA0: jal         0x8001B204
    // 0x80142AA4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x80142AA4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x80142AA8: addiu       $t8, $zero, 0x7A
    ctx->r24 = ADD32(0, 0X7A);
    // 0x80142AAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80142AB0: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142AB4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142AB8: addiu       $t9, $zero, 0x5C
    ctx->r25 = ADD32(0, 0X5C);
    // 0x80142ABC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80142AC0: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80142AC4: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80142AC8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80142ACC: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80142AD0: addiu       $t5, $zero, 0x90
    ctx->r13 = ADD32(0, 0X90);
    // 0x80142AD4: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x80142AD8: addiu       $t7, $zero, 0x90
    ctx->r15 = ADD32(0, 0X90);
    // 0x80142ADC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80142AE0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80142AE4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80142AE8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80142AEC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80142AF0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80142AF4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80142AF8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80142AFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80142B00: addiu       $a1, $a1, -0xCC4
    ctx->r5 = ADD32(ctx->r5, -0XCC4);
    // 0x80142B04: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80142B08: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80142B0C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80142B10: jal         0x8001A804
    // 0x80142B14: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80142B14: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_3:
    // 0x80142B18: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80142B1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80142B20: jr          $ra
    // 0x80142B24: nop

    return;
    // 0x80142B24: nop

;}
RECOMP_FUNC void M7_FUN_80142b28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142B28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80142B2C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80142B30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142B34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80142B38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80142B3C: addiu       $t6, $t6, 0x14B0
    ctx->r14 = ADD32(ctx->r14, 0X14B0);
    // 0x80142B40: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80142B44: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x80142B48: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80142B4C: bne         $v1, $zero, L_80142B9C
    if (ctx->r3 != 0) {
        // 0x80142B50: sw          $t8, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r24;
            goto L_80142B9C;
    }
    // 0x80142B50: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80142B54: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80142B58: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142B5C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80142B60: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80142B64: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80142B68: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80142B6C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80142B70: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80142B74: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80142B78: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80142B7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80142B80: addiu       $a1, $a1, -0xC9C
    ctx->r5 = ADD32(ctx->r5, -0XC9C);
    // 0x80142B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142B88: jal         0x8001A804
    // 0x80142B8C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80142B8C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
    // 0x80142B90: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80142B94: b           L_80142BE4
    // 0x80142B98: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_80142BE4;
    // 0x80142B98: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_80142B9C:
    // 0x80142B9C: lbu         $t4, 0x33($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X33);
    // 0x80142BA0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142BA4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80142BA8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80142BAC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80142BB0: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80142BB4: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80142BB8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142BBC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80142BC0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80142BC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80142BC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80142BCC: addiu       $a1, $a1, -0xC90
    ctx->r5 = ADD32(ctx->r5, -0XC90);
    // 0x80142BD0: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142BD4: jal         0x8001A804
    // 0x80142BD8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x80142BD8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_1:
    // 0x80142BDC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80142BE0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_80142BE4:
    // 0x80142BE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80142BE8: bne         $v1, $at, L_80142C1C
    if (ctx->r3 != ctx->r1) {
        // 0x80142BEC: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_80142C1C;
    }
    // 0x80142BEC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142BF0: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80142BF4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142BF8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80142BFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80142C00: addiu       $a1, $a1, -0xC84
    ctx->r5 = ADD32(ctx->r5, -0XC84);
    // 0x80142C04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80142C08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142C0C: jal         0x8001A804
    // 0x80142C10: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80142C10: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80142C14: b           L_80142C44
    // 0x80142C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80142C44;
    // 0x80142C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142C1C:
    // 0x80142C1C: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80142C20: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80142C24: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80142C28: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80142C2C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80142C30: addiu       $a1, $a1, -0xC78
    ctx->r5 = ADD32(ctx->r5, -0XC78);
    // 0x80142C34: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142C38: jal         0x8001A804
    // 0x80142C3C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80142C3C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x80142C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142C44:
    // 0x80142C44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80142C48: jr          $ra
    // 0x80142C4C: nop

    return;
    // 0x80142C4C: nop

;}
RECOMP_FUNC void M7_FUN_80142c50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142C50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80142C54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80142C58: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80142C5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80142C60: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80142C64: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80142C68: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80142C6C: beq         $v0, $zero, L_80142CA0
    if (ctx->r2 == 0) {
        // 0x80142C70: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80142CA0;
    }
    // 0x80142C70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80142C78: beq         $v0, $at, L_80142D44
    if (ctx->r2 == ctx->r1) {
        // 0x80142C7C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80142D44;
    }
    // 0x80142C7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80142C80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80142C84: beq         $v0, $at, L_80142DE4
    if (ctx->r2 == ctx->r1) {
        // 0x80142C88: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80142DE4;
    }
    // 0x80142C88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80142C8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80142C90: beq         $v0, $at, L_80142E84
    if (ctx->r2 == ctx->r1) {
        // 0x80142C94: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80142E84;
    }
    // 0x80142C94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80142C98: b           L_80142F20
    // 0x80142C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80142F20;
    // 0x80142C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142CA0:
    // 0x80142CA0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142CA4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80142CA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80142CAC: addiu       $a1, $a1, -0xC6C
    ctx->r5 = ADD32(ctx->r5, -0XC6C);
    // 0x80142CB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80142CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142CB8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80142CBC: jal         0x8001A804
    // 0x80142CC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80142CC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80142CC4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142CC8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142CCC: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80142CD0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80142CD4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80142CD8: addiu       $a1, $a1, -0xC60
    ctx->r5 = ADD32(ctx->r5, -0XC60);
    // 0x80142CDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80142CE0: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142CE4: jal         0x8001A804
    // 0x80142CE8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x80142CE8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_1:
    // 0x80142CEC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142CF0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80142CF4: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80142CF8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80142CFC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80142D00: addiu       $a1, $a1, -0xC54
    ctx->r5 = ADD32(ctx->r5, -0XC54);
    // 0x80142D04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80142D08: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142D0C: jal         0x8001A804
    // 0x80142D10: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80142D10: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_2:
    // 0x80142D14: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142D18: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80142D1C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80142D20: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80142D24: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80142D28: addiu       $a1, $a1, -0xC48
    ctx->r5 = ADD32(ctx->r5, -0XC48);
    // 0x80142D2C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80142D30: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142D34: jal         0x8001A804
    // 0x80142D38: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80142D38: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x80142D3C: b           L_80142F20
    // 0x80142D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80142F20;
    // 0x80142D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142D44:
    // 0x80142D44: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142D48: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80142D4C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80142D50: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80142D54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80142D58: addiu       $a1, $a1, -0xC3C
    ctx->r5 = ADD32(ctx->r5, -0XC3C);
    // 0x80142D5C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142D60: jal         0x8001A804
    // 0x80142D64: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_4;
    // 0x80142D64: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_4:
    // 0x80142D68: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142D6C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80142D70: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80142D74: addiu       $a1, $a1, -0xC30
    ctx->r5 = ADD32(ctx->r5, -0XC30);
    // 0x80142D78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80142D7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142D80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80142D84: jal         0x8001A804
    // 0x80142D88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_5;
    // 0x80142D88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80142D8C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142D90: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80142D94: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142D98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80142D9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80142DA0: addiu       $a1, $a1, -0xC24
    ctx->r5 = ADD32(ctx->r5, -0XC24);
    // 0x80142DA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80142DA8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142DAC: jal         0x8001A804
    // 0x80142DB0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_6;
    // 0x80142DB0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_6:
    // 0x80142DB4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142DB8: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80142DBC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80142DC0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80142DC4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80142DC8: addiu       $a1, $a1, -0xC18
    ctx->r5 = ADD32(ctx->r5, -0XC18);
    // 0x80142DCC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80142DD0: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142DD4: jal         0x8001A804
    // 0x80142DD8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_7;
    // 0x80142DD8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_7:
    // 0x80142DDC: b           L_80142F20
    // 0x80142DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80142F20;
    // 0x80142DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142DE4:
    // 0x80142DE4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142DE8: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80142DEC: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80142DF0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80142DF4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80142DF8: addiu       $a1, $a1, -0xC0C
    ctx->r5 = ADD32(ctx->r5, -0XC0C);
    // 0x80142DFC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142E00: jal         0x8001A804
    // 0x80142E04: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_8;
    // 0x80142E04: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_8:
    // 0x80142E08: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142E0C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80142E10: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80142E14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80142E18: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80142E1C: addiu       $a1, $a1, -0xC00
    ctx->r5 = ADD32(ctx->r5, -0XC00);
    // 0x80142E20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80142E24: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142E28: jal         0x8001A804
    // 0x80142E2C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_9;
    // 0x80142E2C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_9:
    // 0x80142E30: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142E34: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80142E38: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80142E3C: addiu       $a1, $a1, -0xBF4
    ctx->r5 = ADD32(ctx->r5, -0XBF4);
    // 0x80142E40: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80142E44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142E48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80142E4C: jal         0x8001A804
    // 0x80142E50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_10;
    // 0x80142E50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x80142E54: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142E58: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80142E5C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80142E60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80142E64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80142E68: addiu       $a1, $a1, -0xBE8
    ctx->r5 = ADD32(ctx->r5, -0XBE8);
    // 0x80142E6C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80142E70: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142E74: jal         0x8001A804
    // 0x80142E78: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_11;
    // 0x80142E78: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_11:
    // 0x80142E7C: b           L_80142F20
    // 0x80142E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80142F20;
    // 0x80142E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142E84:
    // 0x80142E84: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142E88: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142E8C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80142E90: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80142E94: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80142E98: addiu       $a1, $a1, -0xBDC
    ctx->r5 = ADD32(ctx->r5, -0XBDC);
    // 0x80142E9C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142EA0: jal         0x8001A804
    // 0x80142EA4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_12;
    // 0x80142EA4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_12:
    // 0x80142EA8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142EAC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80142EB0: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80142EB4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80142EB8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80142EBC: addiu       $a1, $a1, -0xBD0
    ctx->r5 = ADD32(ctx->r5, -0XBD0);
    // 0x80142EC0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80142EC4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142EC8: jal         0x8001A804
    // 0x80142ECC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_13;
    // 0x80142ECC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_13:
    // 0x80142ED0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142ED4: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80142ED8: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80142EDC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80142EE0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80142EE4: addiu       $a1, $a1, -0xBC4
    ctx->r5 = ADD32(ctx->r5, -0XBC4);
    // 0x80142EE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80142EEC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142EF0: jal         0x8001A804
    // 0x80142EF4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_14;
    // 0x80142EF4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_14:
    // 0x80142EF8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142EFC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80142F00: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80142F04: addiu       $a1, $a1, -0xBB8
    ctx->r5 = ADD32(ctx->r5, -0XBB8);
    // 0x80142F08: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80142F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80142F10: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80142F14: jal         0x8001A804
    // 0x80142F18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_15;
    // 0x80142F18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x80142F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142F20:
    // 0x80142F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80142F24: jr          $ra
    // 0x80142F28: nop

    return;
    // 0x80142F28: nop

;}
RECOMP_FUNC void M7_FUN_80142f2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142F2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142F30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80142F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142F38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80142F3C: addiu       $t6, $t6, 0x14B4
    ctx->r14 = ADD32(ctx->r14, 0X14B4);
    // 0x80142F40: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80142F44: addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
    // 0x80142F48: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142F4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80142F50: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x80142F54: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80142F58: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80142F5C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80142F60: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80142F64: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80142F68: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80142F6C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80142F70: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80142F74: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80142F78: addiu       $a1, $a1, -0xBAC
    ctx->r5 = ADD32(ctx->r5, -0XBAC);
    // 0x80142F7C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142F80: jal         0x8001A804
    // 0x80142F84: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80142F84: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_0:
    // 0x80142F88: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80142F8C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142F90: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80142F94: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80142F98: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80142F9C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80142FA0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80142FA4: addiu       $a1, $a1, -0xBA0
    ctx->r5 = ADD32(ctx->r5, -0XBA0);
    // 0x80142FA8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142FAC: jal         0x8001A804
    // 0x80142FB0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x80142FB0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_1:
    // 0x80142FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142FB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142FBC: jr          $ra
    // 0x80142FC0: nop

    return;
    // 0x80142FC0: nop

;}
RECOMP_FUNC void M7_FUN_80142fc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142FC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80142FC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142FCC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142FD0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80142FD4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80142FD8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80142FDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80142FE0: addiu       $a1, $a1, -0xB94
    ctx->r5 = ADD32(ctx->r5, -0XB94);
    // 0x80142FE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80142FE8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80142FEC: jal         0x8001A804
    // 0x80142FF0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80142FF0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_0:
    // 0x80142FF4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80142FF8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80142FFC: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80143000: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80143004: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80143008: addiu       $a1, $a1, -0xB88
    ctx->r5 = ADD32(ctx->r5, -0XB88);
    // 0x8014300C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80143010: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80143014: jal         0x8001A804
    // 0x80143018: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x80143018: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_1:
    // 0x8014301C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143020: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80143024: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80143028: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8014302C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80143030: addiu       $a1, $a1, -0xB7C
    ctx->r5 = ADD32(ctx->r5, -0XB7C);
    // 0x80143034: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80143038: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8014303C: jal         0x8001A804
    // 0x80143040: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80143040: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_2:
    // 0x80143044: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143048: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x8014304C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80143050: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80143054: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80143058: addiu       $a1, $a1, -0xB70
    ctx->r5 = ADD32(ctx->r5, -0XB70);
    // 0x8014305C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80143060: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80143064: jal         0x8001A804
    // 0x80143068: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80143068: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x8014306C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80143074: jr          $ra
    // 0x80143078: nop

    return;
    // 0x80143078: nop

;}
RECOMP_FUNC void M7_FUN_8014307c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014307C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80143080: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80143084: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80143088: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8014308C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80143090: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80143094: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80143098: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8014309C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x801430A0: addiu       $t7, $t7, 0x14B8
    ctx->r15 = ADD32(ctx->r15, 0X14B8);
    // 0x801430A4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801430A8: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x801430AC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801430B0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801430B4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801430B8: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x801430BC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801430C0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801430C4: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801430C8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801430CC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801430D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801430D4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801430D8: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x801430DC: addiu       $t2, $sp, 0x50
    ctx->r10 = ADD32(ctx->r29, 0X50);
    // 0x801430E0: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x801430E4: addiu       $s1, $s1, -0xB64
    ctx->r17 = ADD32(ctx->r17, -0XB64);
    // 0x801430E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801430EC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801430F0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801430F4: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
L_801430F8:
    // 0x801430F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801430FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143100: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    // 0x80143104: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143108: jal         0x8001B204
    // 0x8014310C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8014310C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
    // 0x80143110: lhu         $t4, 0x6($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X6);
    // 0x80143114: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143118: addiu       $a3, $a3, -0xB60
    ctx->r7 = ADD32(ctx->r7, -0XB60);
    // 0x8014311C: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x80143120: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80143124: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014312C: jal         0x8001B204
    // 0x80143130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80143130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80143134: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143138: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8014313C: bnel        $at, $zero, L_801430F8
    if (ctx->r1 != 0) {
        // 0x80143140: lhu         $t3, 0x6($s2)
        ctx->r11 = MEM_HU(ctx->r18, 0X6);
            goto L_801430F8;
    }
    goto skip_0;
    // 0x80143140: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
    skip_0:
    // 0x80143144: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x80143148: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014314C: addiu       $a1, $a1, -0xB5C
    ctx->r5 = ADD32(ctx->r5, -0XB5C);
    // 0x80143150: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143154: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014315C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143160: jal         0x8001A804
    // 0x80143164: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x80143164: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80143168: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x8014316C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143170: addiu       $a1, $a1, -0xB4C
    ctx->r5 = ADD32(ctx->r5, -0XB4C);
    // 0x80143174: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143178: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8014317C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143180: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143184: jal         0x8001A804
    // 0x80143188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x80143188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8014318C: lbu         $v0, 0x6F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X6F);
    // 0x80143190: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80143194: bne         $at, $zero, L_801431AC
    if (ctx->r1 != 0) {
        // 0x80143198: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_801431AC;
    }
    // 0x80143198: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x8014319C: beq         $v0, $at, L_801438C8
    if (ctx->r2 == ctx->r1) {
        // 0x801431A0: addiu       $a2, $zero, 0x6A
        ctx->r6 = ADD32(0, 0X6A);
            goto L_801438C8;
    }
    // 0x801431A0: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    // 0x801431A4: b           L_801439AC
    // 0x801431A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x801431A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801431AC:
    // 0x801431AC: sltiu       $at, $v0, 0x10
    ctx->r1 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x801431B0: beq         $at, $zero, L_801439A8
    if (ctx->r1 == 0) {
        // 0x801431B4: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_801439A8;
    }
    // 0x801431B4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x801431B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801431BC: addu        $at, $at, $t5
    gpr jr_addend_801431C4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801431C0: lw          $t5, -0x81C($at)
    ctx->r13 = ADD32(ctx->r1, -0X81C);
    // 0x801431C4: jr          $t5
    // 0x801431C8: nop

    switch (jr_addend_801431C4 >> 2) {
        case 0: goto L_801431CC; break;
        case 1: goto L_80143254; break;
        case 2: goto L_801439A8; break;
        case 3: goto L_80143340; break;
        case 4: goto L_80143518; break;
        case 5: goto L_80143518; break;
        case 6: goto L_801439A8; break;
        case 7: goto L_80143604; break;
        case 8: goto L_801439A8; break;
        case 9: goto L_801436F0; break;
        case 10: goto L_801439A8; break;
        case 11: goto L_801439A8; break;
        case 12: goto L_801439A8; break;
        case 13: goto L_801439A8; break;
        case 14: goto L_801437DC; break;
        case 15: goto L_8014342C; break;
        default: switch_error(__func__, 0x801431C4, 0x8018F7E4);
    }
    // 0x801431C8: nop

L_801431CC:
    // 0x801431CC: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x801431D0: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x801431D4: lh          $a1, 0x4($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X4);
    // 0x801431D8: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x801431DC: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x801431E0: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x801431E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801431E8: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x801431EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801431F0: lhu         $t8, 0x4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X4);
    // 0x801431F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801431F8: lbu         $t9, 0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X6);
    // 0x801431FC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80143200: lbu         $t0, 0x7($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7);
    // 0x80143204: jal         0x8014456C
    // 0x80143208: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_4;
    // 0x80143208: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_4:
    // 0x8014320C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80143210: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x80143214: lh          $a1, 0x4($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X4);
    // 0x80143218: lbu         $t2, 0xA($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XA);
    // 0x8014321C: lbu         $a3, 0x8($t1)
    ctx->r7 = MEM_BU(ctx->r9, 0X8);
    // 0x80143220: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    // 0x80143224: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80143228: lbu         $t3, 0xB($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0XB);
    // 0x8014322C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80143230: lhu         $t4, 0xC($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0XC);
    // 0x80143234: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80143238: lbu         $t5, 0xE($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XE);
    // 0x8014323C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80143240: lbu         $t6, 0xF($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XF);
    // 0x80143244: jal         0x8014456C
    // 0x80143248: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_5;
    // 0x80143248: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_5:
    // 0x8014324C: b           L_801439AC
    // 0x80143250: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x80143250: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80143254:
    // 0x80143254: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80143258: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x8014325C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143260: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80143264: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80143268: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8014326C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80143270: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80143274: addiu       $a3, $a3, -0xB3C
    ctx->r7 = ADD32(ctx->r7, -0XB3C);
    // 0x80143278: jal         0x8001B204
    // 0x8014327C: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x8014327C: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_6:
    // 0x80143280: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80143284: addiu       $s1, $s1, -0xB38
    ctx->r17 = ADD32(ctx->r17, -0XB38);
    // 0x80143288: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8014328C: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
L_80143290:
    // 0x80143290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143298: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x8014329C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801432A0: jal         0x8001B204
    // 0x801432A4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801432A4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x801432A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801432AC: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x801432B0: bnel        $at, $zero, L_80143290
    if (ctx->r1 != 0) {
        // 0x801432B4: lhu         $t8, 0x6($s2)
        ctx->r24 = MEM_HU(ctx->r18, 0X6);
            goto L_80143290;
    }
    goto skip_1;
    // 0x801432B4: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
    skip_1:
    // 0x801432B8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801432BC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x801432C0: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
L_801432C4:
    // 0x801432C4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801432C8: addiu       $a3, $a3, -0xB34
    ctx->r7 = ADD32(ctx->r7, -0XB34);
    // 0x801432CC: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x801432D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801432D4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801432D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801432DC: jal         0x8001B204
    // 0x801432E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801432E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x801432E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801432E8: bnel        $s0, $s1, L_801432C4
    if (ctx->r16 != ctx->r17) {
        // 0x801432EC: lhu         $t9, 0x6($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0X6);
            goto L_801432C4;
    }
    goto skip_2;
    // 0x801432EC: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
    skip_2:
    // 0x801432F0: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x801432F4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801432F8: addiu       $a1, $a1, -0xB30
    ctx->r5 = ADD32(ctx->r5, -0XB30);
    // 0x801432FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143300: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143304: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014330C: jal         0x8001A804
    // 0x80143310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_9;
    // 0x80143310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80143314: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x80143318: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014331C: addiu       $a1, $a1, -0xB20
    ctx->r5 = ADD32(ctx->r5, -0XB20);
    // 0x80143320: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143324: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143328: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014332C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143330: jal         0x8001A804
    // 0x80143334: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_10;
    // 0x80143334: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80143338: b           L_801439AC
    // 0x8014333C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x8014333C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80143340:
    // 0x80143340: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80143344: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x80143348: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014334C: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80143350: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80143354: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80143358: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8014335C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80143360: addiu       $a3, $a3, -0xB10
    ctx->r7 = ADD32(ctx->r7, -0XB10);
    // 0x80143364: jal         0x8001B204
    // 0x80143368: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x80143368: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_11:
    // 0x8014336C: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80143370: addiu       $s1, $s1, -0xB0C
    ctx->r17 = ADD32(ctx->r17, -0XB0C);
    // 0x80143374: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143378: lhu         $t2, 0x6($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X6);
L_8014337C:
    // 0x8014337C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143384: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    // 0x80143388: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014338C: jal         0x8001B204
    // 0x80143390: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x80143390: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x80143394: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143398: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8014339C: bnel        $at, $zero, L_8014337C
    if (ctx->r1 != 0) {
        // 0x801433A0: lhu         $t2, 0x6($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X6);
            goto L_8014337C;
    }
    goto skip_3;
    // 0x801433A0: lhu         $t2, 0x6($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X6);
    skip_3:
    // 0x801433A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801433A8: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x801433AC: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
L_801433B0:
    // 0x801433B0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801433B4: addiu       $a3, $a3, -0xB08
    ctx->r7 = ADD32(ctx->r7, -0XB08);
    // 0x801433B8: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    // 0x801433BC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801433C0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801433C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801433C8: jal         0x8001B204
    // 0x801433CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801433CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x801433D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801433D4: bnel        $s0, $s1, L_801433B0
    if (ctx->r16 != ctx->r17) {
        // 0x801433D8: lhu         $t3, 0x6($s2)
        ctx->r11 = MEM_HU(ctx->r18, 0X6);
            goto L_801433B0;
    }
    goto skip_4;
    // 0x801433D8: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
    skip_4:
    // 0x801433DC: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x801433E0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801433E4: addiu       $a1, $a1, -0xB04
    ctx->r5 = ADD32(ctx->r5, -0XB04);
    // 0x801433E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801433EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801433F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801433F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801433F8: jal         0x8001A804
    // 0x801433FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_14;
    // 0x801433FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80143400: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x80143404: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143408: addiu       $a1, $a1, -0xAF4
    ctx->r5 = ADD32(ctx->r5, -0XAF4);
    // 0x8014340C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143410: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143414: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014341C: jal         0x8001A804
    // 0x80143420: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_15;
    // 0x80143420: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80143424: b           L_801439AC
    // 0x80143428: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x80143428: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8014342C:
    // 0x8014342C: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80143430: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x80143434: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143438: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x8014343C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80143440: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80143444: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80143448: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8014344C: addiu       $a3, $a3, -0xAE4
    ctx->r7 = ADD32(ctx->r7, -0XAE4);
    // 0x80143450: jal         0x8001B204
    // 0x80143454: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_16;
    // 0x80143454: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_16:
    // 0x80143458: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8014345C: addiu       $s1, $s1, -0xAE0
    ctx->r17 = ADD32(ctx->r17, -0XAE0);
    // 0x80143460: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143464: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
L_80143468:
    // 0x80143468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014346C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143470: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    // 0x80143474: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143478: jal         0x8001B204
    // 0x8014347C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_17;
    // 0x8014347C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_17:
    // 0x80143480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143484: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80143488: bnel        $at, $zero, L_80143468
    if (ctx->r1 != 0) {
        // 0x8014348C: lhu         $t5, 0x6($s2)
        ctx->r13 = MEM_HU(ctx->r18, 0X6);
            goto L_80143468;
    }
    goto skip_5;
    // 0x8014348C: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
    skip_5:
    // 0x80143490: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143494: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80143498: lhu         $t1, 0x6($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X6);
L_8014349C:
    // 0x8014349C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801434A0: addiu       $a3, $a3, -0xADC
    ctx->r7 = ADD32(ctx->r7, -0XADC);
    // 0x801434A4: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    // 0x801434A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801434AC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801434B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801434B4: jal         0x8001B204
    // 0x801434B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_18;
    // 0x801434B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x801434BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801434C0: bnel        $s0, $s1, L_8014349C
    if (ctx->r16 != ctx->r17) {
        // 0x801434C4: lhu         $t1, 0x6($s2)
        ctx->r9 = MEM_HU(ctx->r18, 0X6);
            goto L_8014349C;
    }
    goto skip_6;
    // 0x801434C4: lhu         $t1, 0x6($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X6);
    skip_6:
    // 0x801434C8: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x801434CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801434D0: addiu       $a1, $a1, -0xAD8
    ctx->r5 = ADD32(ctx->r5, -0XAD8);
    // 0x801434D4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801434D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801434DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801434E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801434E4: jal         0x8001A804
    // 0x801434E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_19;
    // 0x801434E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
    // 0x801434EC: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x801434F0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801434F4: addiu       $a1, $a1, -0xAC8
    ctx->r5 = ADD32(ctx->r5, -0XAC8);
    // 0x801434F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801434FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143500: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143504: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143508: jal         0x8001A804
    // 0x8014350C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_20;
    // 0x8014350C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_20:
    // 0x80143510: b           L_801439AC
    // 0x80143514: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x80143514: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80143518:
    // 0x80143518: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x8014351C: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x80143520: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143524: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80143528: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8014352C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80143530: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143534: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80143538: addiu       $a3, $a3, -0xAB8
    ctx->r7 = ADD32(ctx->r7, -0XAB8);
    // 0x8014353C: jal         0x8001B204
    // 0x80143540: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_21;
    // 0x80143540: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_21:
    // 0x80143544: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80143548: addiu       $s1, $s1, -0xAB4
    ctx->r17 = ADD32(ctx->r17, -0XAB4);
    // 0x8014354C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143550: lhu         $t7, 0x6($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6);
L_80143554:
    // 0x80143554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143558: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014355C: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x80143560: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143564: jal         0x8001B204
    // 0x80143568: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_22;
    // 0x80143568: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x8014356C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143570: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80143574: bnel        $at, $zero, L_80143554
    if (ctx->r1 != 0) {
        // 0x80143578: lhu         $t7, 0x6($s2)
        ctx->r15 = MEM_HU(ctx->r18, 0X6);
            goto L_80143554;
    }
    goto skip_7;
    // 0x80143578: lhu         $t7, 0x6($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6);
    skip_7:
    // 0x8014357C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143580: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80143584: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
L_80143588:
    // 0x80143588: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014358C: addiu       $a3, $a3, -0xAB0
    ctx->r7 = ADD32(ctx->r7, -0XAB0);
    // 0x80143590: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x80143594: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80143598: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014359C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801435A0: jal         0x8001B204
    // 0x801435A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_23;
    // 0x801435A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x801435A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801435AC: bnel        $s0, $s1, L_80143588
    if (ctx->r16 != ctx->r17) {
        // 0x801435B0: lhu         $t8, 0x6($s2)
        ctx->r24 = MEM_HU(ctx->r18, 0X6);
            goto L_80143588;
    }
    goto skip_8;
    // 0x801435B0: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
    skip_8:
    // 0x801435B4: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x801435B8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801435BC: addiu       $a1, $a1, -0xAAC
    ctx->r5 = ADD32(ctx->r5, -0XAAC);
    // 0x801435C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801435C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801435C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801435CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801435D0: jal         0x8001A804
    // 0x801435D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_24;
    // 0x801435D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x801435D8: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x801435DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801435E0: addiu       $a1, $a1, -0xA9C
    ctx->r5 = ADD32(ctx->r5, -0XA9C);
    // 0x801435E4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801435E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801435EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801435F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801435F4: jal         0x8001A804
    // 0x801435F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_25;
    // 0x801435F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_25:
    // 0x801435FC: b           L_801439AC
    // 0x80143600: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x80143600: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80143604:
    // 0x80143604: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80143608: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x8014360C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143610: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80143614: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80143618: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8014361C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80143620: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80143624: addiu       $a3, $a3, -0xA8C
    ctx->r7 = ADD32(ctx->r7, -0XA8C);
    // 0x80143628: jal         0x8001B204
    // 0x8014362C: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_26;
    // 0x8014362C: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_26:
    // 0x80143630: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80143634: addiu       $s1, $s1, -0xA88
    ctx->r17 = ADD32(ctx->r17, -0XA88);
    // 0x80143638: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8014363C: lhu         $t0, 0x6($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X6);
L_80143640:
    // 0x80143640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143648: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    // 0x8014364C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143650: jal         0x8001B204
    // 0x80143654: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_27;
    // 0x80143654: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_27:
    // 0x80143658: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8014365C: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80143660: bnel        $at, $zero, L_80143640
    if (ctx->r1 != 0) {
        // 0x80143664: lhu         $t0, 0x6($s2)
        ctx->r8 = MEM_HU(ctx->r18, 0X6);
            goto L_80143640;
    }
    goto skip_9;
    // 0x80143664: lhu         $t0, 0x6($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X6);
    skip_9:
    // 0x80143668: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8014366C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80143670: lhu         $t2, 0x6($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X6);
L_80143674:
    // 0x80143674: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143678: addiu       $a3, $a3, -0xA84
    ctx->r7 = ADD32(ctx->r7, -0XA84);
    // 0x8014367C: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    // 0x80143680: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80143684: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014368C: jal         0x8001B204
    // 0x80143690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_28;
    // 0x80143690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x80143694: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143698: bnel        $s0, $s1, L_80143674
    if (ctx->r16 != ctx->r17) {
        // 0x8014369C: lhu         $t2, 0x6($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X6);
            goto L_80143674;
    }
    goto skip_10;
    // 0x8014369C: lhu         $t2, 0x6($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X6);
    skip_10:
    // 0x801436A0: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x801436A4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801436A8: addiu       $a1, $a1, -0xA80
    ctx->r5 = ADD32(ctx->r5, -0XA80);
    // 0x801436AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801436B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801436B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801436B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801436BC: jal         0x8001A804
    // 0x801436C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_29;
    // 0x801436C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_29:
    // 0x801436C4: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x801436C8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801436CC: addiu       $a1, $a1, -0xA70
    ctx->r5 = ADD32(ctx->r5, -0XA70);
    // 0x801436D0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801436D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801436D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801436DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801436E0: jal         0x8001A804
    // 0x801436E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_30;
    // 0x801436E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_30:
    // 0x801436E8: b           L_801439AC
    // 0x801436EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x801436EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801436F0:
    // 0x801436F0: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x801436F4: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x801436F8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801436FC: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80143700: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80143704: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80143708: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8014370C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80143710: addiu       $a3, $a3, -0xA60
    ctx->r7 = ADD32(ctx->r7, -0XA60);
    // 0x80143714: jal         0x8001B204
    // 0x80143718: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_31;
    // 0x80143718: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_31:
    // 0x8014371C: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80143720: addiu       $s1, $s1, -0xA5C
    ctx->r17 = ADD32(ctx->r17, -0XA5C);
    // 0x80143724: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143728: lhu         $t4, 0x6($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X6);
L_8014372C:
    // 0x8014372C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143734: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x80143738: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014373C: jal         0x8001B204
    // 0x80143740: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_32;
    // 0x80143740: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_32:
    // 0x80143744: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143748: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8014374C: bnel        $at, $zero, L_8014372C
    if (ctx->r1 != 0) {
        // 0x80143750: lhu         $t4, 0x6($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X6);
            goto L_8014372C;
    }
    goto skip_11;
    // 0x80143750: lhu         $t4, 0x6($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X6);
    skip_11:
    // 0x80143754: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143758: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8014375C: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
L_80143760:
    // 0x80143760: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143764: addiu       $a3, $a3, -0xA58
    ctx->r7 = ADD32(ctx->r7, -0XA58);
    // 0x80143768: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    // 0x8014376C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80143770: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143778: jal         0x8001B204
    // 0x8014377C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_33;
    // 0x8014377C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
    // 0x80143780: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143784: bnel        $s0, $s1, L_80143760
    if (ctx->r16 != ctx->r17) {
        // 0x80143788: lhu         $t5, 0x6($s2)
        ctx->r13 = MEM_HU(ctx->r18, 0X6);
            goto L_80143760;
    }
    goto skip_12;
    // 0x80143788: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
    skip_12:
    // 0x8014378C: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x80143790: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143794: addiu       $a1, $a1, -0xA54
    ctx->r5 = ADD32(ctx->r5, -0XA54);
    // 0x80143798: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8014379C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801437A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801437A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801437A8: jal         0x8001A804
    // 0x801437AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_34;
    // 0x801437AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x801437B0: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x801437B4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801437B8: addiu       $a1, $a1, -0xA44
    ctx->r5 = ADD32(ctx->r5, -0XA44);
    // 0x801437BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801437C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801437C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801437C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801437CC: jal         0x8001A804
    // 0x801437D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_35;
    // 0x801437D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_35:
    // 0x801437D4: b           L_801439AC
    // 0x801437D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x801437D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801437DC:
    // 0x801437DC: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x801437E0: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x801437E4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801437E8: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801437EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801437F0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801437F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801437F8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801437FC: addiu       $a3, $a3, -0xA34
    ctx->r7 = ADD32(ctx->r7, -0XA34);
    // 0x80143800: jal         0x8001B204
    // 0x80143804: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_36;
    // 0x80143804: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_36:
    // 0x80143808: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8014380C: addiu       $s1, $s1, -0xA30
    ctx->r17 = ADD32(ctx->r17, -0XA30);
    // 0x80143810: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143814: lhu         $t6, 0x6($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X6);
L_80143818:
    // 0x80143818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014381C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143820: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    // 0x80143824: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143828: jal         0x8001B204
    // 0x8014382C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_37;
    // 0x8014382C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_37:
    // 0x80143830: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143834: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80143838: bnel        $at, $zero, L_80143818
    if (ctx->r1 != 0) {
        // 0x8014383C: lhu         $t6, 0x6($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X6);
            goto L_80143818;
    }
    goto skip_13;
    // 0x8014383C: lhu         $t6, 0x6($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X6);
    skip_13:
    // 0x80143840: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80143844: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80143848: lhu         $t7, 0x6($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6);
L_8014384C:
    // 0x8014384C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143850: addiu       $a3, $a3, -0xA2C
    ctx->r7 = ADD32(ctx->r7, -0XA2C);
    // 0x80143854: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x80143858: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8014385C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143864: jal         0x8001B204
    // 0x80143868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_38;
    // 0x80143868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_38:
    // 0x8014386C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143870: bnel        $s0, $s1, L_8014384C
    if (ctx->r16 != ctx->r17) {
        // 0x80143874: lhu         $t7, 0x6($s2)
        ctx->r15 = MEM_HU(ctx->r18, 0X6);
            goto L_8014384C;
    }
    goto skip_14;
    // 0x80143874: lhu         $t7, 0x6($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6);
    skip_14:
    // 0x80143878: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x8014387C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143880: addiu       $a1, $a1, -0xA28
    ctx->r5 = ADD32(ctx->r5, -0XA28);
    // 0x80143884: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143888: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8014388C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143894: jal         0x8001A804
    // 0x80143898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_39;
    // 0x80143898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_39:
    // 0x8014389C: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x801438A0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801438A4: addiu       $a1, $a1, -0xA18
    ctx->r5 = ADD32(ctx->r5, -0XA18);
    // 0x801438A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801438AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801438B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801438B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801438B8: jal         0x8001A804
    // 0x801438BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_40;
    // 0x801438BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_40:
    // 0x801438C0: b           L_801439AC
    // 0x801438C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801439AC;
    // 0x801438C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801438C8:
    // 0x801438C8: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x801438CC: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x801438D0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801438D4: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801438D8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801438DC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801438E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801438E4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801438E8: jal         0x8001B204
    // 0x801438EC: addiu       $a3, $a3, -0xA08
    ctx->r7 = ADD32(ctx->r7, -0XA08);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_41;
    // 0x801438EC: addiu       $a3, $a3, -0xA08
    ctx->r7 = ADD32(ctx->r7, -0XA08);
    after_41:
    // 0x801438F0: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x801438F4: addiu       $s1, $s1, -0xA04
    ctx->r17 = ADD32(ctx->r17, -0XA04);
    // 0x801438F8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801438FC: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
L_80143900:
    // 0x80143900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80143904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80143908: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x8014390C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143910: jal         0x8001B204
    // 0x80143914: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_42;
    // 0x80143914: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_42:
    // 0x80143918: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8014391C: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80143920: bnel        $at, $zero, L_80143900
    if (ctx->r1 != 0) {
        // 0x80143924: lhu         $t9, 0x6($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0X6);
            goto L_80143900;
    }
    goto skip_15;
    // 0x80143924: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
    skip_15:
    // 0x80143928: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8014392C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80143930: lhu         $t0, 0x6($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X6);
L_80143934:
    // 0x80143934: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80143938: addiu       $a3, $a3, -0xA00
    ctx->r7 = ADD32(ctx->r7, -0XA00);
    // 0x8014393C: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    // 0x80143940: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80143944: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80143948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014394C: jal         0x8001B204
    // 0x80143950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_43;
    // 0x80143950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_43:
    // 0x80143954: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80143958: bnel        $s0, $s1, L_80143934
    if (ctx->r16 != ctx->r17) {
        // 0x8014395C: lhu         $t0, 0x6($s2)
        ctx->r8 = MEM_HU(ctx->r18, 0X6);
            goto L_80143934;
    }
    goto skip_16;
    // 0x8014395C: lhu         $t0, 0x6($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X6);
    skip_16:
    // 0x80143960: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x80143964: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80143968: addiu       $a1, $a1, -0x9FC
    ctx->r5 = ADD32(ctx->r5, -0X9FC);
    // 0x8014396C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143970: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143974: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014397C: jal         0x8001A804
    // 0x80143980: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_44;
    // 0x80143980: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_44:
    // 0x80143984: lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3);
    // 0x80143988: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014398C: addiu       $a1, $a1, -0x9EC
    ctx->r5 = ADD32(ctx->r5, -0X9EC);
    // 0x80143990: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143994: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80143998: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014399C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801439A0: jal         0x8001A804
    // 0x801439A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_45;
    // 0x801439A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_45:
L_801439A8:
    // 0x801439A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801439AC:
    // 0x801439AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801439B0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801439B4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801439B8: jr          $ra
    // 0x801439BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801439BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801439c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801439c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801439C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801439C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801439C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801439CC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801439D0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801439D4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801439D8: addiu       $t6, $t6, 0x14CC
    ctx->r14 = ADD32(ctx->r14, 0X14CC);
    // 0x801439DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801439E0: addiu       $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x801439E4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801439E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801439EC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801439F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801439F4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801439F8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801439FC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80143A00: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80143A04: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80143A08: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x80143A0C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80143A10: bne         $a1, $at, L_80143AB0
    if (ctx->r5 != ctx->r1) {
        // 0x80143A14: sw          $t8, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r24;
            goto L_80143AB0;
    }
    // 0x80143A14: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x80143A18: lbu         $t9, 0x53($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X53);
    // 0x80143A1C: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x80143A20: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x80143A24: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80143A28: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80143A2C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80143A30: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80143A34: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80143A38: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80143A3C: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80143A40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80143A44: lbu         $t3, 0x3($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X3);
    // 0x80143A48: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80143A4C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80143A50: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x80143A54: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80143A58: lbu         $t5, 0x6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6);
    // 0x80143A5C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80143A60: lbu         $t6, 0x7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7);
    // 0x80143A64: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80143A68: jal         0x8014456C
    // 0x80143A6C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_0;
    // 0x80143A6C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80143A70: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80143A74: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x80143A78: lbu         $a3, 0x8($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X8);
    // 0x80143A7C: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80143A80: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80143A84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80143A88: lbu         $t8, 0xB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XB);
    // 0x80143A8C: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    // 0x80143A90: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80143A94: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x80143A98: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80143A9C: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80143AA0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80143AA4: lbu         $t1, 0xF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF);
    // 0x80143AA8: jal         0x8014456C
    // 0x80143AAC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_1;
    // 0x80143AAC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_1:
L_80143AB0:
    // 0x80143AB0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80143AB4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80143AB8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80143ABC: jr          $ra
    // 0x80143AC0: nop

    return;
    // 0x80143AC0: nop

;}
RECOMP_FUNC void M7_FUN_80143ac4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143AC4: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80143ac8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80143ac8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143AC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143ACC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80143AD0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80143AD4: addiu       $v1, $v1, -0x13B0
    ctx->r3 = ADD32(ctx->r3, -0X13B0);
    // 0x80143AD8: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x80143ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80143AE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80143AE8: beq         $v0, $zero, L_80143B14
    if (ctx->r2 == 0) {
        // 0x80143AEC: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_80143B14;
    }
    // 0x80143AEC: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80143AF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80143AF4: beq         $v0, $at, L_80143B24
    if (ctx->r2 == ctx->r1) {
        // 0x80143AF8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80143B24;
    }
    // 0x80143AF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80143AFC: beq         $v0, $at, L_80143B34
    if (ctx->r2 == ctx->r1) {
        // 0x80143B00: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80143B34;
    }
    // 0x80143B00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80143B04: beq         $v0, $at, L_80143B44
    if (ctx->r2 == ctx->r1) {
        // 0x80143B08: nop
    
            goto L_80143B44;
    }
    // 0x80143B08: nop

    // 0x80143B0C: b           L_80143B50
    // 0x80143B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80143B50;
    // 0x80143B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143B14:
    // 0x80143B14: jal         0x80143C08
    // 0x80143B18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80143C08)(rdram, ctx);
        goto after_0;
    // 0x80143B18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80143B1C: b           L_80143B50
    // 0x80143B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80143B50;
    // 0x80143B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143B24:
    // 0x80143B24: jal         0x80143E38
    // 0x80143B28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80143E38)(rdram, ctx);
        goto after_1;
    // 0x80143B28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80143B2C: b           L_80143B50
    // 0x80143B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80143B50;
    // 0x80143B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143B34:
    // 0x80143B34: jal         0x8014405C
    // 0x80143B38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x8014405C)(rdram, ctx);
        goto after_2;
    // 0x80143B38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80143B3C: b           L_80143B50
    // 0x80143B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80143B50;
    // 0x80143B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143B44:
    // 0x80143B44: jal         0x8014428C
    // 0x80143B48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x8014428C)(rdram, ctx);
        goto after_3;
    // 0x80143B48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80143B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143B50:
    // 0x80143B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80143B54: jr          $ra
    // 0x80143B58: nop

    return;
    // 0x80143B58: nop

;}
RECOMP_FUNC void M7_FUN_80143b5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143B5C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80143B60: lbu         $v0, -0x13B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X13B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80143b64(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80143b64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143B64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143B6C: beq         $v0, $zero, L_80143B98
    if (ctx->r2 == 0) {
        // 0x80143B70: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80143B98;
    }
    // 0x80143B70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80143B74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80143B78: beq         $v0, $at, L_80143BB0
    if (ctx->r2 == ctx->r1) {
        // 0x80143B7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80143BB0;
    }
    // 0x80143B7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80143B80: beq         $v0, $at, L_80143BC8
    if (ctx->r2 == ctx->r1) {
        // 0x80143B84: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80143BC8;
    }
    // 0x80143B84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80143B88: beq         $v0, $at, L_80143BE0
    if (ctx->r2 == ctx->r1) {
        // 0x80143B8C: nop
    
            goto L_80143BE0;
    }
    // 0x80143B8C: nop

    // 0x80143B90: b           L_80143BF8
    // 0x80143B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80143BF8;
    // 0x80143B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143B98:
    // 0x80143B98: jal         0x80143D38
    // 0x80143B9C: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80143D38)(rdram, ctx);
        goto after_0;
    // 0x80143B9C: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_0:
    // 0x80143BA0: beq         $v0, $zero, L_80143BF4
    if (ctx->r2 == 0) {
        // 0x80143BA4: lbu         $v1, 0x1F($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X1F);
            goto L_80143BF4;
    }
    // 0x80143BA4: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x80143BA8: b           L_80143BF4
    // 0x80143BAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80143BF4;
    // 0x80143BAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80143BB0:
    // 0x80143BB0: jal         0x80143F5C
    // 0x80143BB4: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80143F5C)(rdram, ctx);
        goto after_1;
    // 0x80143BB4: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_1:
    // 0x80143BB8: beq         $v0, $zero, L_80143BF4
    if (ctx->r2 == 0) {
        // 0x80143BBC: lbu         $v1, 0x1F($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X1F);
            goto L_80143BF4;
    }
    // 0x80143BBC: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x80143BC0: b           L_80143BF4
    // 0x80143BC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80143BF4;
    // 0x80143BC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80143BC8:
    // 0x80143BC8: jal         0x8014418C
    // 0x80143BCC: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8014418C)(rdram, ctx);
        goto after_2;
    // 0x80143BCC: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_2:
    // 0x80143BD0: beq         $v0, $zero, L_80143BF4
    if (ctx->r2 == 0) {
        // 0x80143BD4: lbu         $v1, 0x1F($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X1F);
            goto L_80143BF4;
    }
    // 0x80143BD4: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x80143BD8: b           L_80143BF4
    // 0x80143BDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80143BF4;
    // 0x80143BDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80143BE0:
    // 0x80143BE0: jal         0x801443B0
    // 0x80143BE4: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801443B0)(rdram, ctx);
        goto after_3;
    // 0x80143BE4: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_3:
    // 0x80143BE8: beq         $v0, $zero, L_80143BF4
    if (ctx->r2 == 0) {
        // 0x80143BEC: lbu         $v1, 0x1F($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X1F);
            goto L_80143BF4;
    }
    // 0x80143BEC: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x80143BF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80143BF4:
    // 0x80143BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143BF8:
    // 0x80143BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80143BFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80143C00: jr          $ra
    // 0x80143C04: nop

    return;
    // 0x80143C04: nop

;}
RECOMP_FUNC void M7_FUN_80143c08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143C08: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80143C0C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80143C10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80143C14: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80143C18: addiu       $t7, $t7, 0x14E0
    ctx->r15 = ADD32(ctx->r15, 0X14E0);
    // 0x80143C1C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80143C20: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x80143C24: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80143C28: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80143C2C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80143C30: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80143C34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80143C38: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80143C3C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80143C40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80143C44: sh          $t0, -0x13AE($at)
    MEM_H(-0X13AE, ctx->r1) = ctx->r8;
    // 0x80143C48: lbu         $t1, -0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, -0XE);
    // 0x80143C4C: lbu         $a3, -0x10($s0)
    ctx->r7 = MEM_BU(ctx->r16, -0X10);
    // 0x80143C50: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80143C54: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80143C58: lbu         $t2, -0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, -0XD);
    // 0x80143C5C: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x80143C60: lh          $a1, 0x40($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X40);
    // 0x80143C64: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80143C68: lhu         $t3, -0xC($s0)
    ctx->r11 = MEM_HU(ctx->r16, -0XC);
    // 0x80143C6C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80143C70: lbu         $t4, -0xA($s0)
    ctx->r12 = MEM_BU(ctx->r16, -0XA);
    // 0x80143C74: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80143C78: lbu         $t5, -0x9($s0)
    ctx->r13 = MEM_BU(ctx->r16, -0X9);
    // 0x80143C7C: jal         0x8014456C
    // 0x80143C80: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_0;
    // 0x80143C80: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x80143C84: addiu       $v0, $s0, -0x10
    ctx->r2 = ADD32(ctx->r16, -0X10);
    // 0x80143C88: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x80143C8C: lbu         $a3, 0x8($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X8);
    // 0x80143C90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80143C94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143C98: lbu         $t7, 0xB($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB);
    // 0x80143C9C: lh          $a1, 0x44($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X44);
    // 0x80143CA0: lh          $a2, 0x46($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X46);
    // 0x80143CA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80143CA8: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x80143CAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80143CB0: lbu         $t9, 0xE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XE);
    // 0x80143CB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80143CB8: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
    // 0x80143CBC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80143CC0: jal         0x8014456C
    // 0x80143CC4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_1;
    // 0x80143CC4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80143CC8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80143CCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80143CD0: lh          $a1, 0x48($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X48);
    // 0x80143CD4: lbu         $t1, 0x12($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X12);
    // 0x80143CD8: lbu         $a3, 0x10($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X10);
    // 0x80143CDC: lh          $a2, 0x4A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4A);
    // 0x80143CE0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80143CE4: lbu         $t2, 0x13($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X13);
    // 0x80143CE8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80143CEC: lhu         $t3, 0x14($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X14);
    // 0x80143CF0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80143CF4: lbu         $t4, 0x16($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X16);
    // 0x80143CF8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80143CFC: lbu         $t5, 0x17($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17);
    // 0x80143D00: jal         0x8014456C
    // 0x80143D04: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_2;
    // 0x80143D04: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_2:
    // 0x80143D08: addiu       $t6, $zero, 0x9E
    ctx->r14 = ADD32(0, 0X9E);
    // 0x80143D0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143D10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80143D14: lh          $a1, 0x48($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X48);
    // 0x80143D18: lh          $a2, 0x4A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4A);
    // 0x80143D1C: jal         0x80144A4C
    // 0x80143D20: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_3;
    // 0x80143D20: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_3:
    // 0x80143D24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80143D28: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80143D2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80143D30: jr          $ra
    // 0x80143D34: nop

    return;
    // 0x80143D34: nop

;}
RECOMP_FUNC void M7_FUN_80143d38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143D38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80143D3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80143D40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80143D44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80143D48: addiu       $t7, $t7, 0x14EC
    ctx->r15 = ADD32(ctx->r15, 0X14EC);
    // 0x80143D4C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80143D50: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80143D54: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80143D58: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80143D5C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80143D60: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80143D64: addiu       $s0, $s0, -0x13AE
    ctx->r16 = ADD32(ctx->r16, -0X13AE);
    // 0x80143D68: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80143D6C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80143D70: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80143D74: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x80143D78: addiu       $t4, $zero, 0x9E
    ctx->r12 = ADD32(0, 0X9E);
    // 0x80143D7C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80143D80: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80143D84: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80143D88: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80143D8C: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    // 0x80143D90: subu        $a2, $t2, $t3
    ctx->r6 = SUB32(ctx->r10, ctx->r11);
    // 0x80143D94: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80143D98: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80143D9C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80143DA0: jal         0x80144A4C
    // 0x80143DA4: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_0;
    // 0x80143DA4: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_0:
    // 0x80143DA8: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80143DAC: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80143DB0: addiu       $t7, $zero, 0x9E
    ctx->r15 = ADD32(0, 0X9E);
    // 0x80143DB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80143DB8: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    // 0x80143DBC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80143DC0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80143DC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80143DC8: lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X30);
    // 0x80143DCC: jal         0x80144A4C
    // 0x80143DD0: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_1;
    // 0x80143DD0: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_1:
    // 0x80143DD4: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80143DD8: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80143DDC: addiu       $t0, $zero, 0x9E
    ctx->r8 = ADD32(0, 0X9E);
    // 0x80143DE0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80143DE4: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    // 0x80143DE8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80143DEC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80143DF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80143DF4: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x80143DF8: jal         0x80144A4C
    // 0x80143DFC: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_2;
    // 0x80143DFC: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_2:
    // 0x80143E00: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80143E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80143E08: slti        $at, $t1, 0x2E
    ctx->r1 = SIGNED(ctx->r9) < 0X2E ? 1 : 0;
    // 0x80143E0C: bne         $at, $zero, L_80143E24
    if (ctx->r1 != 0) {
        // 0x80143E10: nop
    
            goto L_80143E24;
    }
    // 0x80143E10: nop

    // 0x80143E14: jal         0x801444B0
    // 0x80143E18: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801444B0)(rdram, ctx);
        goto after_3;
    // 0x80143E18: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80143E1C: b           L_80143E24
    // 0x80143E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80143E24;
    // 0x80143E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80143E24:
    // 0x80143E24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80143E28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80143E2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80143E30: jr          $ra
    // 0x80143E34: nop

    return;
    // 0x80143E34: nop

;}
RECOMP_FUNC void M7_FUN_80143e38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143E38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80143E3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80143E40: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80143E44: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80143E48: addiu       $t7, $t7, 0x14F8
    ctx->r15 = ADD32(ctx->r15, 0X14F8);
    // 0x80143E4C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80143E50: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80143E54: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80143E58: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80143E5C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80143E60: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80143E64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80143E68: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80143E6C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80143E70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80143E74: sh          $t0, -0x13AE($at)
    MEM_H(-0X13AE, ctx->r1) = ctx->r8;
    // 0x80143E78: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x80143E7C: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x80143E80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80143E84: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80143E88: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x80143E8C: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x80143E90: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x80143E94: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80143E98: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    // 0x80143E9C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80143EA0: lbu         $t4, 0x6($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6);
    // 0x80143EA4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80143EA8: lbu         $t5, 0x7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7);
    // 0x80143EAC: jal         0x8014456C
    // 0x80143EB0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_0;
    // 0x80143EB0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x80143EB4: addiu       $t6, $zero, 0x9E
    ctx->r14 = ADD32(0, 0X9E);
    // 0x80143EB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143EBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80143EC0: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x80143EC4: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x80143EC8: jal         0x80144A4C
    // 0x80143ECC: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_1;
    // 0x80143ECC: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_1:
    // 0x80143ED0: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x80143ED4: lbu         $a3, 0x8($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X8);
    // 0x80143ED8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80143EDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80143EE0: lbu         $t8, 0xB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XB);
    // 0x80143EE4: lh          $a1, 0x3C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3C);
    // 0x80143EE8: lh          $a2, 0x3E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3E);
    // 0x80143EEC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80143EF0: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x80143EF4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80143EF8: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80143EFC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80143F00: lbu         $t1, 0xF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF);
    // 0x80143F04: jal         0x8014456C
    // 0x80143F08: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_2;
    // 0x80143F08: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_2:
    // 0x80143F0C: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x80143F10: lbu         $a3, 0x10($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X10);
    // 0x80143F14: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80143F18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80143F1C: lbu         $t3, 0x13($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X13);
    // 0x80143F20: lh          $a1, 0x40($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X40);
    // 0x80143F24: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x80143F28: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80143F2C: lhu         $t4, 0x14($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X14);
    // 0x80143F30: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80143F34: lbu         $t5, 0x16($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X16);
    // 0x80143F38: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80143F3C: lbu         $t6, 0x17($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17);
    // 0x80143F40: jal         0x8014456C
    // 0x80143F44: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_3;
    // 0x80143F44: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_3:
    // 0x80143F48: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80143F4C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80143F50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80143F54: jr          $ra
    // 0x80143F58: nop

    return;
    // 0x80143F58: nop

;}
RECOMP_FUNC void M7_FUN_80143f5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143F5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80143F60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80143F64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80143F68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80143F6C: addiu       $t7, $t7, 0x1504
    ctx->r15 = ADD32(ctx->r15, 0X1504);
    // 0x80143F70: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80143F74: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80143F78: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80143F7C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80143F80: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80143F84: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80143F88: addiu       $s0, $s0, -0x13AE
    ctx->r16 = ADD32(ctx->r16, -0X13AE);
    // 0x80143F8C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80143F90: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80143F94: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80143F98: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x80143F9C: addiu       $t4, $zero, 0x9E
    ctx->r12 = ADD32(0, 0X9E);
    // 0x80143FA0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80143FA4: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80143FA8: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80143FAC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80143FB0: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    // 0x80143FB4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x80143FB8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80143FBC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80143FC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80143FC4: jal         0x80144A4C
    // 0x80143FC8: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_0;
    // 0x80143FC8: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_0:
    // 0x80143FCC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80143FD0: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80143FD4: addiu       $t7, $zero, 0x9E
    ctx->r15 = ADD32(0, 0X9E);
    // 0x80143FD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80143FDC: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80143FE0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80143FE4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80143FE8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80143FEC: lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X30);
    // 0x80143FF0: jal         0x80144A4C
    // 0x80143FF4: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_1;
    // 0x80143FF4: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_1:
    // 0x80143FF8: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80143FFC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80144000: addiu       $t0, $zero, 0x9E
    ctx->r8 = ADD32(0, 0X9E);
    // 0x80144004: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80144008: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x8014400C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144010: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144014: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80144018: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x8014401C: jal         0x80144A4C
    // 0x80144020: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_2;
    // 0x80144020: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_2:
    // 0x80144024: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80144028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014402C: slti        $at, $t1, 0x2E
    ctx->r1 = SIGNED(ctx->r9) < 0X2E ? 1 : 0;
    // 0x80144030: bne         $at, $zero, L_80144048
    if (ctx->r1 != 0) {
        // 0x80144034: nop
    
            goto L_80144048;
    }
    // 0x80144034: nop

    // 0x80144038: jal         0x801444B0
    // 0x8014403C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801444B0)(rdram, ctx);
        goto after_3;
    // 0x8014403C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80144040: b           L_80144048
    // 0x80144044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80144048;
    // 0x80144044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80144048:
    // 0x80144048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014404C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80144050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80144054: jr          $ra
    // 0x80144058: nop

    return;
    // 0x80144058: nop

;}
RECOMP_FUNC void M7_FUN_8014405c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014405C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80144060: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80144064: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80144068: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8014406C: addiu       $t7, $t7, 0x1510
    ctx->r15 = ADD32(ctx->r15, 0X1510);
    // 0x80144070: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80144074: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x80144078: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8014407C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80144080: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80144084: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80144088: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014408C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80144090: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80144094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80144098: sh          $t0, -0x13AE($at)
    MEM_H(-0X13AE, ctx->r1) = ctx->r8;
    // 0x8014409C: lbu         $t1, -0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, -0XE);
    // 0x801440A0: lbu         $a3, -0x10($s0)
    ctx->r7 = MEM_BU(ctx->r16, -0X10);
    // 0x801440A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801440A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801440AC: lbu         $t2, -0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, -0XD);
    // 0x801440B0: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x801440B4: lh          $a1, 0x40($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X40);
    // 0x801440B8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801440BC: lhu         $t3, -0xC($s0)
    ctx->r11 = MEM_HU(ctx->r16, -0XC);
    // 0x801440C0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801440C4: lbu         $t4, -0xA($s0)
    ctx->r12 = MEM_BU(ctx->r16, -0XA);
    // 0x801440C8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801440CC: lbu         $t5, -0x9($s0)
    ctx->r13 = MEM_BU(ctx->r16, -0X9);
    // 0x801440D0: jal         0x8014456C
    // 0x801440D4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_0;
    // 0x801440D4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x801440D8: addiu       $v0, $s0, -0x10
    ctx->r2 = ADD32(ctx->r16, -0X10);
    // 0x801440DC: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x801440E0: lbu         $a3, 0x8($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X8);
    // 0x801440E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801440E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801440EC: lbu         $t7, 0xB($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB);
    // 0x801440F0: lh          $a1, 0x44($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X44);
    // 0x801440F4: lh          $a2, 0x46($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X46);
    // 0x801440F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801440FC: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x80144100: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80144104: lbu         $t9, 0xE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XE);
    // 0x80144108: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8014410C: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
    // 0x80144110: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80144114: jal         0x8014456C
    // 0x80144118: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_1;
    // 0x80144118: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x8014411C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80144120: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80144124: lh          $a1, 0x48($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X48);
    // 0x80144128: lbu         $t1, 0x12($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X12);
    // 0x8014412C: lbu         $a3, 0x10($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X10);
    // 0x80144130: lh          $a2, 0x4A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4A);
    // 0x80144134: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80144138: lbu         $t2, 0x13($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X13);
    // 0x8014413C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80144140: lhu         $t3, 0x14($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X14);
    // 0x80144144: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80144148: lbu         $t4, 0x16($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X16);
    // 0x8014414C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80144150: lbu         $t5, 0x17($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17);
    // 0x80144154: jal         0x8014456C
    // 0x80144158: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_2;
    // 0x80144158: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_2:
    // 0x8014415C: addiu       $t6, $zero, 0x9E
    ctx->r14 = ADD32(0, 0X9E);
    // 0x80144160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80144164: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80144168: lh          $a1, 0x48($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X48);
    // 0x8014416C: lh          $a2, 0x4A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4A);
    // 0x80144170: jal         0x80144A4C
    // 0x80144174: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_3;
    // 0x80144174: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_3:
    // 0x80144178: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8014417C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80144180: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80144184: jr          $ra
    // 0x80144188: nop

    return;
    // 0x80144188: nop

;}
