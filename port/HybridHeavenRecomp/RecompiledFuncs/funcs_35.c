#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80151700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151708: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8015170C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80151710: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80151714: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151718: jal         0x801517CC
    // 0x8015171C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x8015171C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80151720: beq         $v0, $zero, L_8015177C
    if (ctx->r2 == 0) {
        // 0x80151724: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8015177C;
    }
    // 0x80151724: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151728: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8015172C: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80151730: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x80151734: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80151738: beql        $at, $zero, L_80151780
    if (ctx->r1 == 0) {
        // 0x8015173C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80151780;
    }
    goto skip_0;
    // 0x8015173C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80151740: jal         0x80006214
    // 0x80151744: nop

    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80151744: nop

    after_1:
    // 0x80151748: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x8015174C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80151750: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80151754: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80151758: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8015175C: lw          $t3, -0x2578($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2578);
    // 0x80151760: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80151764: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80151768: sw          $t0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r8;
    // 0x8015176C: jal         0x80006214
    // 0x80151770: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80151770: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    after_2:
    // 0x80151774: b           L_80151780
    // 0x80151778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80151780;
    // 0x80151778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015177C:
    // 0x8015177C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151780:
    // 0x80151780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151788: jr          $ra
    // 0x8015178C: nop

    return;
    // 0x8015178C: nop

;}
RECOMP_FUNC void M7_FUN_80151790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151798: jal         0x801517CC
    // 0x8015179C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x8015179C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801517A0: beq         $v0, $zero, L_801517BC
    if (ctx->r2 == 0) {
        // 0x801517A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801517BC;
    }
    // 0x801517A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801517A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801517AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801517B0: lbu         $t7, 0x91($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X91);
    // 0x801517B4: beq         $t7, $zero, L_801517C4
    if (ctx->r15 == 0) {
        // 0x801517B8: nop
    
            goto L_801517C4;
    }
    // 0x801517B8: nop

L_801517BC:
    // 0x801517BC: b           L_801517C4
    // 0x801517C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801517C4;
    // 0x801517C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801517C4:
    // 0x801517C4: jr          $ra
    // 0x801517C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801517C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801517cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801517cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801517CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801517D0: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x801517D4: beq         $v0, $zero, L_801517FC
    if (ctx->r2 == 0) {
        // 0x801517D8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801517FC;
    }
    // 0x801517D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801517DC: jal         0x8001F7B0
    // 0x801517E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F7B0)(rdram, ctx);
        goto after_0;
    // 0x801517E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801517E4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x801517E8: beq         $v0, $zero, L_801517FC
    if (ctx->r2 == 0) {
        // 0x801517EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801517FC;
    }
    // 0x801517EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801517F0: lbu         $v0, 0x90($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X90);
    // 0x801517F4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x801517F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_801517FC:
    // 0x801517FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151804: jr          $ra
    // 0x80151808: nop

    return;
    // 0x80151808: nop

;}
RECOMP_FUNC void M7_FUN_8015180c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015180C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151814: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80151818: jal         0x8001F7B0
    // 0x8015181C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F7B0)(rdram, ctx);
        goto after_0;
    // 0x8015181C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151820: beq         $v0, $zero, L_80151854
    if (ctx->r2 == 0) {
        // 0x80151824: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80151854;
    }
    // 0x80151824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80151828: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8015182C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80151830: addiu       $t0, $t0, 0x6EAC
    ctx->r8 = ADD32(ctx->r8, 0X6EAC);
    // 0x80151834: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x80151838: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8015183C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80151840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151844: lhu         $t9, 0x72($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X72);
    // 0x80151848: sw          $t0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r8;
    // 0x8015184C: b           L_80151858
    // 0x80151850: sh          $t9, 0x72($a0)
    MEM_H(0X72, ctx->r4) = ctx->r25;
        goto L_80151858;
    // 0x80151850: sh          $t9, 0x72($a0)
    MEM_H(0X72, ctx->r4) = ctx->r25;
L_80151854:
    // 0x80151854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151858:
    // 0x80151858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015185C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151860: jr          $ra
    // 0x80151864: nop

    return;
    // 0x80151864: nop

;}
RECOMP_FUNC void M7_FUN_80151868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151868: nop

    // 0x8015186C: nop

;}
RECOMP_FUNC void M7_FUN_80151870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80151878: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8015187C: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80151880: beq         $at, $zero, L_801518C0
    if (ctx->r1 == 0) {
        // 0x80151884: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801518C0;
    }
    // 0x80151884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151888: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8015188C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151890: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80151894: sh          $zero, -0xE70($at)
    MEM_H(-0XE70, ctx->r1) = 0;
    // 0x80151898: jal         0x80002A94
    // 0x8015189C: sb          $a0, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80002A94)(rdram, ctx);
        goto after_0;
    // 0x8015189C: sb          $a0, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r4;
    after_0:
    // 0x801518A0: bne         $v0, $zero, L_801518C0
    if (ctx->r2 != 0) {
        // 0x801518A4: lbu         $a0, 0x1B($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X1B);
            goto L_801518C0;
    }
    // 0x801518A4: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x801518A8: jal         0x80002BAC
    // 0x801518AC: nop

    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_1;
    // 0x801518AC: nop

    after_1:
    // 0x801518B0: bnel        $v0, $zero, L_801518C4
    if (ctx->r2 != 0) {
        // 0x801518B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801518C4;
    }
    goto skip_0;
    // 0x801518B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801518B8: b           L_801518C4
    // 0x801518BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801518C4;
    // 0x801518BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801518C0:
    // 0x801518C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801518C4:
    // 0x801518C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801518C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801518CC: jr          $ra
    // 0x801518D0: nop

    return;
    // 0x801518D0: nop

;}
RECOMP_FUNC void M7_FUN_801518d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801518D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801518D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801518DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801518E0: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x801518E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801518E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801518EC: jal         0x80151BC4
    // 0x801518F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_0;
    // 0x801518F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x801518F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801518F8: bnel        $v0, $at, L_8015190C
    if (ctx->r2 != ctx->r1) {
        // 0x801518FC: slti        $at, $s0, 0x2
        ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_8015190C;
    }
    goto skip_0;
    // 0x801518FC: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    skip_0:
    // 0x80151900: b           L_8015197C
    // 0x80151904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8015197C;
    // 0x80151904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80151908: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
L_8015190C:
    // 0x8015190C: beq         $at, $zero, L_80151978
    if (ctx->r1 == 0) {
        // 0x80151910: lhu         $t6, 0x2A($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0X2A);
            goto L_80151978;
    }
    // 0x80151910: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x80151914: bne         $t6, $zero, L_80151940
    if (ctx->r14 != 0) {
        // 0x80151918: nop
    
            goto L_80151940;
    }
    // 0x80151918: nop

    // 0x8015191C: jal         0x80002BAC
    // 0x80151920: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_1;
    // 0x80151920: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x80151924: bne         $v0, $zero, L_80151978
    if (ctx->r2 != 0) {
        // 0x80151928: sll         $t7, $s0, 1
        ctx->r15 = S32(ctx->r16 << 1);
            goto L_80151978;
    }
    // 0x80151928: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x8015192C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151930: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80151934: sh          $zero, -0xE70($at)
    MEM_H(-0XE70, ctx->r1) = 0;
    // 0x80151938: b           L_8015197C
    // 0x8015193C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015197C;
    // 0x8015193C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151940:
    // 0x80151940: jal         0x80002B44
    // 0x80151944: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002B44)(rdram, ctx);
        goto after_2;
    // 0x80151944: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x80151948: bne         $v0, $zero, L_80151978
    if (ctx->r2 != 0) {
        // 0x8015194C: lhu         $t8, 0x2A($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X2A);
            goto L_80151978;
    }
    // 0x8015194C: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x80151950: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80151954: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151958: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8015195C: sh          $t8, -0xE70($at)
    MEM_H(-0XE70, ctx->r1) = ctx->r24;
    // 0x80151960: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80151964: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151968: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8015196C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151970: b           L_8015197C
    // 0x80151974: sb          $t0, -0xE6C($at)
    MEM_B(-0XE6C, ctx->r1) = ctx->r8;
        goto L_8015197C;
    // 0x80151974: sb          $t0, -0xE6C($at)
    MEM_B(-0XE6C, ctx->r1) = ctx->r8;
L_80151978:
    // 0x80151978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015197C:
    // 0x8015197C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151980: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80151984: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151988: jr          $ra
    // 0x8015198C: nop

    return;
    // 0x8015198C: nop

;}
RECOMP_FUNC void M7_FUN_80151990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151990: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151994: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151998: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8015199C: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x801519A0: beq         $at, $zero, L_80151A74
    if (ctx->r1 == 0) {
        // 0x801519A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80151A74;
    }
    // 0x801519A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801519A8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801519AC: addiu       $t7, $t7, -0xE70
    ctx->r15 = ADD32(ctx->r15, -0XE70);
    // 0x801519B0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x801519B4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801519B8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x801519BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801519C0: beq         $v0, $zero, L_80151A6C
    if (ctx->r2 == 0) {
        // 0x801519C4: nop
    
            goto L_80151A6C;
    }
    // 0x801519C4: nop

    // 0x801519C8: bne         $v0, $at, L_801519F4
    if (ctx->r2 != ctx->r1) {
        // 0x801519CC: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_801519F4;
    }
    // 0x801519CC: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801519D0: jal         0x80002BAC
    // 0x801519D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_0;
    // 0x801519D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801519D8: bne         $v0, $zero, L_801519EC
    if (ctx->r2 != 0) {
        // 0x801519DC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_801519EC;
    }
    // 0x801519DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801519E0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x801519E4: b           L_80151A78
    // 0x801519E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80151A78;
    // 0x801519E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801519EC:
    // 0x801519EC: b           L_80151A78
    // 0x801519F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80151A78;
    // 0x801519F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801519F4:
    // 0x801519F4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x801519F8: lbu         $t8, -0xE6C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0XE6C);
    // 0x801519FC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80151A00: addiu       $t1, $v0, -0x2
    ctx->r9 = ADD32(ctx->r2, -0X2);
    // 0x80151A04: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80151A08: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80151A0C: lhu         $t0, 0x3334($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X3334);
    // 0x80151A10: bgez        $t1, L_80151A24
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80151A14: andi        $t2, $t1, 0xF
        ctx->r10 = ctx->r9 & 0XF;
            goto L_80151A24;
    }
    // 0x80151A14: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80151A18: beq         $t2, $zero, L_80151A24
    if (ctx->r10 == 0) {
        // 0x80151A1C: nop
    
            goto L_80151A24;
    }
    // 0x80151A1C: nop

    // 0x80151A20: addiu       $t2, $t2, -0x10
    ctx->r10 = ADD32(ctx->r10, -0X10);
L_80151A24:
    // 0x80151A24: srav        $t3, $t0, $t2
    ctx->r11 = S32(SIGNED(ctx->r8) >> (ctx->r10 & 31));
    // 0x80151A28: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80151A2C: beq         $t4, $zero, L_80151A44
    if (ctx->r12 == 0) {
        // 0x80151A30: nop
    
            goto L_80151A44;
    }
    // 0x80151A30: nop

    // 0x80151A34: jal         0x80002B44
    // 0x80151A38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80002B44)(rdram, ctx);
        goto after_1;
    // 0x80151A38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80151A3C: b           L_80151A50
    // 0x80151A40: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80151A50;
    // 0x80151A40: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80151A44:
    // 0x80151A44: jal         0x80002BAC
    // 0x80151A48: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_2;
    // 0x80151A48: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80151A4C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80151A50:
    // 0x80151A50: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80151A54: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80151A58: bne         $at, $zero, L_80151A64
    if (ctx->r1 != 0) {
        // 0x80151A5C: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80151A64;
    }
    // 0x80151A5C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80151A60: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
L_80151A64:
    // 0x80151A64: b           L_80151A78
    // 0x80151A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80151A78;
    // 0x80151A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151A6C:
    // 0x80151A6C: b           L_80151A78
    // 0x80151A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80151A78;
    // 0x80151A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151A74:
    // 0x80151A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151A78:
    // 0x80151A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151A80: jr          $ra
    // 0x80151A84: nop

    return;
    // 0x80151A84: nop

;}
RECOMP_FUNC void M7_FUN_80151a88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151A8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80151A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151A94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151A98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80151A9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80151AA0:
    // 0x80151AA0: jal         0x80151870
    // 0x80151AA4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80151870)(rdram, ctx);
        goto after_0;
    // 0x80151AA4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x80151AA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80151AAC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80151AB0: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80151AB4: bne         $at, $zero, L_80151AA0
    if (ctx->r1 != 0) {
        // 0x80151AB8: nop
    
            goto L_80151AA0;
    }
    // 0x80151AB8: nop

    // 0x80151ABC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151AC0: addiu       $a1, $a1, 0x1AE0
    ctx->r5 = ADD32(ctx->r5, 0X1AE0);
    // 0x80151AC4: jal         0x800058DC
    // 0x80151AC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80151AC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151AD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80151AD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151AD8: jr          $ra
    // 0x80151ADC: nop

    return;
    // 0x80151ADC: nop

;}
RECOMP_FUNC void M7_FUN_80151ae0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151AE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151AE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80151AE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151AEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151AF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80151AF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80151AF8:
    // 0x80151AF8: jal         0x80151990
    // 0x80151AFC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80151990)(rdram, ctx);
        goto after_0;
    // 0x80151AFC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x80151B00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80151B04: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80151B08: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80151B0C: bne         $at, $zero, L_80151AF8
    if (ctx->r1 != 0) {
        // 0x80151B10: nop
    
            goto L_80151AF8;
    }
    // 0x80151B10: nop

    // 0x80151B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151B18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80151B1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151B20: jr          $ra
    // 0x80151B24: nop

    return;
    // 0x80151B24: nop

;}
RECOMP_FUNC void M7_FUN_80151b28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151B28: nop

    // 0x80151B2C: nop

;}
RECOMP_FUNC void M7_FUN_80151b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151B38: jal         0x80151B98
    // 0x80151B3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80151B98)(rdram, ctx);
        goto after_0;
    // 0x80151B3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80151B40: jal         0x80151BD0
    // 0x80151B44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80151BD0)(rdram, ctx);
        goto after_1;
    // 0x80151B44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80151B48: jal         0x80151C08
    // 0x80151B4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80151C08)(rdram, ctx);
        goto after_2;
    // 0x80151B4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80151B50: jal         0x80151C40
    // 0x80151B54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80151C40)(rdram, ctx);
        goto after_3;
    // 0x80151B54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80151B58: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80151B5C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80151B60: lhu         $v1, 0x17A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X17A);
    // 0x80151B64: beq         $v1, $zero, L_80151B74
    if (ctx->r3 == 0) {
        // 0x80151B68: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80151B74;
    }
    // 0x80151B68: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80151B6C: sb          $t6, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r14;
    // 0x80151B70: sh          $zero, 0x17A($v0)
    MEM_H(0X17A, ctx->r2) = 0;
L_80151B74:
    // 0x80151B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151B78: sh          $zero, 0x16E($v0)
    MEM_H(0X16E, ctx->r2) = 0;
    // 0x80151B7C: sw          $zero, 0x170($v0)
    MEM_W(0X170, ctx->r2) = 0;
    // 0x80151B80: sw          $zero, 0x174($v0)
    MEM_W(0X174, ctx->r2) = 0;
    // 0x80151B84: jr          $ra
    // 0x80151B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80151B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151b8c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151b8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151B8C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80151B90: jr          $ra
    // 0x80151B94: lbu         $v0, -0x42A6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A6);
    return;
    // 0x80151B94: lbu         $v0, -0x42A6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151b98(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151b98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151B98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80151B9C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80151BA0: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80151BA4: beq         $at, $zero, L_80151BBC
    if (ctx->r1 == 0) {
            // 0x80151BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x80151BBC)(rdram, ctx);
    return;
    }
    // 0x80151BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80151BAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151BB0: sb          $a0, -0x42A6($at)
    MEM_B(-0X42A6, ctx->r1) = ctx->r4;
    // 0x80151BB4: jr          $ra
    // 0x80151BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80151BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151bbc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151bbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151BBC: jr          $ra
    // 0x80151BC0: nop

    return;
    // 0x80151BC0: nop

;}
RECOMP_FUNC void M7_FUN_80151bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151BC4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80151BC8: jr          $ra
    // 0x80151BCC: lbu         $v0, -0x42A5($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A5);
    return;
    // 0x80151BCC: lbu         $v0, -0x42A5($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151bd0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151bd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151BD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80151BD4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80151BD8: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80151BDC: beq         $at, $zero, L_80151BF4
    if (ctx->r1 == 0) {
            // 0x80151BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x80151BF4)(rdram, ctx);
    return;
    }
    // 0x80151BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80151BE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151BE8: sb          $a0, -0x42A5($at)
    MEM_B(-0X42A5, ctx->r1) = ctx->r4;
    // 0x80151BEC: jr          $ra
    // 0x80151BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80151BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151bf4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151bf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151BF4: jr          $ra
    // 0x80151BF8: nop

    return;
    // 0x80151BF8: nop

;}
RECOMP_FUNC void M7_FUN_80151bfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151BFC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80151C00: jr          $ra
    // 0x80151C04: lbu         $v0, -0x42A4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A4);
    return;
    // 0x80151C04: lbu         $v0, -0x42A4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151c08(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151c08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80151C0C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80151C10: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80151C14: beq         $at, $zero, L_80151C2C
    if (ctx->r1 == 0) {
            // 0x80151C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x80151C2C)(rdram, ctx);
    return;
    }
    // 0x80151C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80151C1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151C20: sb          $a0, -0x42A4($at)
    MEM_B(-0X42A4, ctx->r1) = ctx->r4;
    // 0x80151C24: jr          $ra
    // 0x80151C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80151C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151c2c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151c2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C2C: jr          $ra
    // 0x80151C30: nop

    return;
    // 0x80151C30: nop

;}
RECOMP_FUNC void M7_FUN_80151c34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C34: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80151C38: jr          $ra
    // 0x80151C3C: lbu         $v0, -0x42A3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A3);
    return;
    // 0x80151C3C: lbu         $v0, -0x42A3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X42A3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151c40(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151c40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80151C44: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80151C48: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80151C4C: beq         $at, $zero, L_80151C64
    if (ctx->r1 == 0) {
            // 0x80151C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x80151C64)(rdram, ctx);
    return;
    }
    // 0x80151C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80151C54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151C58: sb          $a0, -0x42A3($at)
    MEM_B(-0X42A3, ctx->r1) = ctx->r4;
    // 0x80151C5C: jr          $ra
    // 0x80151C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80151C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151c64(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151c64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C64: jr          $ra
    // 0x80151C68: nop

    return;
    // 0x80151C68: nop

;}
RECOMP_FUNC void M7_FUN_80151c6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151C70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151C74: jal         0x80151B8C
    // 0x80151C78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80151B8C)(rdram, ctx);
        goto after_0;
    // 0x80151C78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80151C7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80151C80: beq         $a0, $v0, L_80151C9C
    if (ctx->r4 == ctx->r2) {
        // 0x80151C84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80151C9C;
    }
    // 0x80151C84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80151C88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80151C8C: beq         $v0, $at, L_80151C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80151C90: nop
    
            goto L_80151C9C;
    }
    // 0x80151C90: nop

    // 0x80151C94: b           L_80151D6C
    // 0x80151C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80151D6C;
    // 0x80151C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151C9C:
    // 0x80151C9C: beq         $v1, $a0, L_80151D04
    if (ctx->r3 == ctx->r4) {
        // 0x80151CA0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80151D04;
    }
    // 0x80151CA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80151CA4: bne         $v1, $at, L_80151D60
    if (ctx->r3 != ctx->r1) {
        // 0x80151CA8: nop
    
            goto L_80151D60;
    }
    // 0x80151CA8: nop

    // 0x80151CAC: jal         0x80151C34
    // 0x80151CB0: nop

    LOOKUP_FUNC(0x80151C34)(rdram, ctx);
        goto after_1;
    // 0x80151CB0: nop

    after_1:
    // 0x80151CB4: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80151CB8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80151CBC: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x80151CC0: lhu         $s0, 0x3378($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X3378);
    // 0x80151CC4: jal         0x80125808
    // 0x80151CC8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_2;
    // 0x80151CC8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x80151CCC: jal         0x80017064
    // 0x80151CD0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_3;
    // 0x80151CD0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_3:
    // 0x80151CD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80151CD8: bne         $v0, $at, L_80151CE8
    if (ctx->r2 != ctx->r1) {
        // 0x80151CDC: nop
    
            goto L_80151CE8;
    }
    // 0x80151CDC: nop

    // 0x80151CE0: b           L_80151D6C
    // 0x80151CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80151D6C;
    // 0x80151CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151CE8:
    // 0x80151CE8: jal         0x80005204
    // 0x80151CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_4;
    // 0x80151CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80151CF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80151CF4: addu        $t7, $v0, $at
    ctx->r15 = ADD32(ctx->r2, ctx->r1);
    // 0x80151CF8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80151CFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151D00: sw          $t8, -0x429C($at)
    MEM_W(-0X429C, ctx->r1) = ctx->r24;
L_80151D04:
    // 0x80151D04: jal         0x80151C34
    // 0x80151D08: nop

    LOOKUP_FUNC(0x80151C34)(rdram, ctx);
        goto after_5;
    // 0x80151D08: nop

    after_5:
    // 0x80151D0C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80151D10: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80151D14: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80151D18: lhu         $s0, 0x3370($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X3370);
    // 0x80151D1C: jal         0x80125808
    // 0x80151D20: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_6;
    // 0x80151D20: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_6:
    // 0x80151D24: jal         0x80017064
    // 0x80151D28: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_7;
    // 0x80151D28: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_7:
    // 0x80151D2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80151D30: bne         $v0, $at, L_80151D40
    if (ctx->r2 != ctx->r1) {
        // 0x80151D34: nop
    
            goto L_80151D40;
    }
    // 0x80151D34: nop

    // 0x80151D38: b           L_80151D6C
    // 0x80151D3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80151D6C;
    // 0x80151D3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151D40:
    // 0x80151D40: jal         0x80005204
    // 0x80151D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_8;
    // 0x80151D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80151D48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80151D4C: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x80151D50: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80151D54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80151D58: b           L_80151D68
    // 0x80151D5C: sw          $t1, -0x42A0($at)
    MEM_W(-0X42A0, ctx->r1) = ctx->r9;
        goto L_80151D68;
    // 0x80151D5C: sw          $t1, -0x42A0($at)
    MEM_W(-0X42A0, ctx->r1) = ctx->r9;
L_80151D60:
    // 0x80151D60: b           L_80151D6C
    // 0x80151D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80151D6C;
    // 0x80151D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151D68:
    // 0x80151D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151D6C:
    // 0x80151D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151D70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80151D74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151D78: jr          $ra
    // 0x80151D7C: nop

    return;
    // 0x80151D7C: nop

;}
RECOMP_FUNC void M7_FUN_80151d80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151D80: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80151D84: lw          $t6, -0x42A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X42A0);
    // 0x80151D88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80151D8C: bne         $t6, $zero, L_80151D9C
    if (ctx->r14 != 0) {
            // 0x80151D90: nop

    LOOKUP_FUNC(0x80151D9C)(rdram, ctx);
    return;
    }
    // 0x80151D90: nop

    // 0x80151D94: jr          $ra
    // 0x80151D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80151D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151d9c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151d9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151D9C: jr          $ra
    // 0x80151DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80151DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151da4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80151da4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151DA4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80151DA8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80151DAC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80151DB0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80151DB4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80151DB8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80151DBC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80151DC0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80151DC4: addiu       $t7, $t7, -0x6B8C
    ctx->r15 = ADD32(ctx->r15, -0X6B8C);
    // 0x80151DC8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80151DCC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80151DD0: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80151DD4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80151DD8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80151DDC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80151DE0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80151DE4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80151DE8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80151DEC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80151DF0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80151DF4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80151DF8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x80151DFC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80151E00: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80151E04: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80151E08: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80151E0C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80151E10: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80151E14: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80151E18: lw          $t0, 0x170($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X170);
    // 0x80151E1C: addiu       $s0, $s0, -0x6D50
    ctx->r16 = ADD32(ctx->r16, -0X6D50);
    // 0x80151E20: beql        $t0, $zero, L_80152164
    if (ctx->r8 == 0) {
        // 0x80151E24: addiu       $t7, $sp, 0x58
        ctx->r15 = ADD32(ctx->r29, 0X58);
            goto L_80152164;
    }
    goto skip_0;
    // 0x80151E24: addiu       $t7, $sp, 0x58
    ctx->r15 = ADD32(ctx->r29, 0X58);
    skip_0:
    // 0x80151E28: lhu         $t1, 0xA8($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XA8);
    // 0x80151E2C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80151E30: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80151E34: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80151E38: mfhi        $t2
    ctx->r10 = hi;
    // 0x80151E3C: slti        $at, $t2, 0x12
    ctx->r1 = SIGNED(ctx->r10) < 0X12 ? 1 : 0;
    // 0x80151E40: beq         $at, $zero, L_80151E94
    if (ctx->r1 == 0) {
        // 0x80151E44: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80151E94;
    }
    // 0x80151E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80151E48: lhu         $t3, 0x2C($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X2C);
    // 0x80151E4C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80151E50: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80151E54: beq         $s2, $t3, L_80151E7C
    if (ctx->r18 == ctx->r11) {
        // 0x80151E58: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_80151E7C;
    }
    // 0x80151E58: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80151E5C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80151E60: addiu       $a3, $a3, 0x9F0
    ctx->r7 = ADD32(ctx->r7, 0X9F0);
    // 0x80151E64: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80151E68: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    // 0x80151E6C: jal         0x8001B204
    // 0x80151E70: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80151E70: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    after_0:
    // 0x80151E74: b           L_80151EA8
    // 0x80151E78: nop

        goto L_80151EA8;
    // 0x80151E78: nop

L_80151E7C:
    // 0x80151E7C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80151E80: addiu       $a3, $a3, 0x9FC
    ctx->r7 = ADD32(ctx->r7, 0X9FC);
    // 0x80151E84: jal         0x8001B204
    // 0x80151E88: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80151E88: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    after_1:
    // 0x80151E8C: b           L_80151EA8
    // 0x80151E90: nop

        goto L_80151EA8;
    // 0x80151E90: nop

L_80151E94:
    // 0x80151E94: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80151E98: addiu       $a3, $a3, 0xA08
    ctx->r7 = ADD32(ctx->r7, 0XA08);
    // 0x80151E9C: jal         0x8001B204
    // 0x80151EA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x80151EA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80151EA4: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
L_80151EA8:
    // 0x80151EA8: jal         0x80130078
    // 0x80151EAC: nop

    LOOKUP_FUNC(0x80130078)(rdram, ctx);
        goto after_3;
    // 0x80151EAC: nop

    after_3:
    // 0x80151EB0: bnel        $v0, $zero, L_80151EF4
    if (ctx->r2 != 0) {
        // 0x80151EB4: lui         $at, 0x4044
        ctx->r1 = S32(0X4044 << 16);
            goto L_80151EF4;
    }
    goto skip_1;
    // 0x80151EB4: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    skip_1:
    // 0x80151EB8: lhu         $t4, 0x1C8($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X1C8);
    // 0x80151EBC: addiu       $t6, $zero, 0x73
    ctx->r14 = ADD32(0, 0X73);
    // 0x80151EC0: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    // 0x80151EC4: andi        $t5, $t4, 0xF000
    ctx->r13 = ctx->r12 & 0XF000;
    // 0x80151EC8: beq         $t5, $zero, L_80151EF0
    if (ctx->r13 == 0) {
        // 0x80151ECC: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80151EF0;
    }
    // 0x80151ECC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80151ED0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80151ED4: sh          $t6, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r14;
    // 0x80151ED8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80151EE0: jal         0x8012FE50
    // 0x80151EE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_4;
    // 0x80151EE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80151EE8: jal         0x80020718
    // 0x80151EEC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x80151EEC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
L_80151EF0:
    // 0x80151EF0: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
L_80151EF4:
    // 0x80151EF4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80151EF8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80151EFC: lw          $a0, 0x170($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X170);
L_80151F00:
    // 0x80151F00: lhu         $v1, 0x16E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X16E);
    // 0x80151F04: addiu       $at, $zero, 0xC00
    ctx->r1 = ADD32(0, 0XC00);
    // 0x80151F08: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80151F0C: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80151F10: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80151F14: addu        $s0, $t8, $a0
    ctx->r16 = ADD32(ctx->r24, ctx->r4);
    // 0x80151F18: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80151F1C: bnel        $v0, $at, L_80152140
    if (ctx->r2 != ctx->r1) {
        // 0x80151F20: sh          $v0, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r2;
            goto L_80152140;
    }
    goto skip_2;
    // 0x80151F20: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    skip_2:
    // 0x80151F24: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80151F28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80151F2C: beq         $v0, $zero, L_80151F4C
    if (ctx->r2 == 0) {
        // 0x80151F30: nop
    
            goto L_80151F4C;
    }
    // 0x80151F30: nop

    // 0x80151F34: beq         $v0, $at, L_80151F74
    if (ctx->r2 == ctx->r1) {
        // 0x80151F38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80151F74;
    }
    // 0x80151F38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80151F3C: beql        $v0, $at, L_80151FC8
    if (ctx->r2 == ctx->r1) {
        // 0x80151F40: lhu         $v0, 0x2C($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X2C);
            goto L_80151FC8;
    }
    goto skip_3;
    // 0x80151F40: lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2C);
    skip_3:
    // 0x80151F44: b           L_80152134
    // 0x80151F48: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
        goto L_80152134;
    // 0x80151F48: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
L_80151F4C:
    // 0x80151F4C: jal         0x80133830
    // 0x80151F50: nop

    LOOKUP_FUNC(0x80133830)(rdram, ctx);
        goto after_6;
    // 0x80151F50: nop

    after_6:
    // 0x80151F54: jal         0x80133950
    // 0x80151F58: nop

    LOOKUP_FUNC(0x80133950)(rdram, ctx);
        goto after_7;
    // 0x80151F58: nop

    after_7:
    // 0x80151F5C: jal         0x80133A70
    // 0x80151F60: nop

    LOOKUP_FUNC(0x80133A70)(rdram, ctx);
        goto after_8;
    // 0x80151F60: nop

    after_8:
    // 0x80151F64: sh          $zero, 0x16E($s1)
    MEM_H(0X16E, ctx->r17) = 0;
    // 0x80151F68: lw          $a0, 0x170($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X170);
    // 0x80151F6C: b           L_80152130
    // 0x80151F70: andi        $v1, $zero, 0xFFFF
    ctx->r3 = 0 & 0XFFFF;
        goto L_80152130;
    // 0x80151F70: andi        $v1, $zero, 0xFFFF
    ctx->r3 = 0 & 0XFFFF;
L_80151F74:
    // 0x80151F74: jal         0x80133830
    // 0x80151F78: nop

    LOOKUP_FUNC(0x80133830)(rdram, ctx);
        goto after_9;
    // 0x80151F78: nop

    after_9:
    // 0x80151F7C: jal         0x80133950
    // 0x80151F80: nop

    LOOKUP_FUNC(0x80133950)(rdram, ctx);
        goto after_10;
    // 0x80151F80: nop

    after_10:
    // 0x80151F84: jal         0x80133A70
    // 0x80151F88: nop

    LOOKUP_FUNC(0x80133A70)(rdram, ctx);
        goto after_11;
    // 0x80151F88: nop

    after_11:
    // 0x80151F8C: addiu       $t9, $zero, 0x73
    ctx->r25 = ADD32(0, 0X73);
    // 0x80151F90: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80151F94: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x80151F98: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80151F9C: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x80151FA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80151FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80151FA8: jal         0x8012FE50
    // 0x80151FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_12;
    // 0x80151FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80151FB0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80151FB4: sh          $t1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r9;
    // 0x80151FB8: lw          $a0, 0x170($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X170);
    // 0x80151FBC: b           L_80152130
    // 0x80151FC0: lhu         $v1, 0x16E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X16E);
        goto L_80152130;
    // 0x80151FC0: lhu         $v1, 0x16E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X16E);
    // 0x80151FC4: lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2C);
L_80151FC8:
    // 0x80151FC8: beq         $s2, $v0, L_801520E0
    if (ctx->r18 == ctx->r2) {
        // 0x80151FCC: nop
    
            goto L_801520E0;
    }
    // 0x80151FCC: nop

    // 0x80151FD0: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x80151FD4: lw          $t3, 0xE0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XE0);
    // 0x80151FD8: addiu       $a0, $sp, 0x4E
    ctx->r4 = ADD32(ctx->r29, 0X4E);
    // 0x80151FDC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80151FE0: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80151FE4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80151FE8: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80151FEC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80151FF0: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
    // 0x80151FF4: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x80151FF8: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x80151FFC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80152000: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80152004: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80152008: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x8015200C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80152010: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x80152014: lw          $t2, 0xE0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XE0);
    // 0x80152018: lbu         $t9, 0x5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X5);
    // 0x8015201C: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x80152020: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80152024: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80152028: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8015202C: jal         0x8011A0F0
    // 0x80152030: sh          $t1, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r9;
    LOOKUP_FUNC(0x8011A0F0)(rdram, ctx);
        goto after_13;
    // 0x80152030: sh          $t1, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r9;
    after_13:
    // 0x80152034: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x80152038: lw          $t5, 0xE8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XE8);
    // 0x8015203C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80152040: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80152044: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80152048: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x8015204C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80152050: swc1        $f18, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f18.u32l;
    // 0x80152054: lh          $t7, 0xE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE);
    // 0x80152058: lw          $t9, 0xE8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XE8);
    // 0x8015205C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80152060: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x80152064: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80152068: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x8015206C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80152070: swc1        $f10, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f10.u32l;
    // 0x80152074: lbu         $t2, 0xB($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XB);
    // 0x80152078: lbu         $t0, 0xA($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA);
    // 0x8015207C: lw          $t6, 0xE8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE8);
    // 0x80152080: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x80152084: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80152088: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8015208C: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80152090: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80152094: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80152098: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8015209C: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x801520A0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801520A4: swc1        $f6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f6.u32l;
    // 0x801520A8: lbu         $t8, 0x11($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X11);
    // 0x801520AC: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x801520B0: lw          $t4, 0xE8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XE8);
    // 0x801520B4: sll         $t2, $t8, 8
    ctx->r10 = S32(ctx->r24 << 8);
    // 0x801520B8: addu        $t0, $t9, $t2
    ctx->r8 = ADD32(ctx->r25, ctx->r10);
    // 0x801520BC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x801520C0: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801520C4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x801520C8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801520CC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801520D0: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x801520D4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801520D8: swc1        $f18, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f18.u32l;
    // 0x801520DC: lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2C);
L_801520E0:
    // 0x801520E0: beq         $s2, $v0, L_8015211C
    if (ctx->r18 == ctx->r2) {
        // 0x801520E4: addiu       $a0, $sp, 0x52
        ctx->r4 = ADD32(ctx->r29, 0X52);
            goto L_8015211C;
    }
    // 0x801520E4: addiu       $a0, $sp, 0x52
    ctx->r4 = ADD32(ctx->r29, 0X52);
    // 0x801520E8: jal         0x80119F9C
    // 0x801520EC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_14;
    // 0x801520EC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_14:
    // 0x801520F0: lw          $t6, 0xE8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE8);
    // 0x801520F4: lh          $a0, 0x52($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X52);
    // 0x801520F8: lh          $a1, 0x50($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X50);
    // 0x801520FC: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80152100: lh          $a2, 0x4E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4E);
    // 0x80152104: addiu       $t7, $v0, 0x4C
    ctx->r15 = ADD32(ctx->r2, 0X4C);
    // 0x80152108: addiu       $t8, $v0, 0x50
    ctx->r24 = ADD32(ctx->r2, 0X50);
    // 0x8015210C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80152110: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80152114: jal         0x8011A148
    // 0x80152118: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_15;
    // 0x80152118: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    after_15:
L_8015211C:
    // 0x8015211C: lhu         $t9, 0x16E($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X16E);
    // 0x80152120: lw          $a0, 0x170($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X170);
    // 0x80152124: addiu       $t2, $t9, 0x2
    ctx->r10 = ADD32(ctx->r25, 0X2);
    // 0x80152128: sh          $t2, 0x16E($s1)
    MEM_H(0X16E, ctx->r17) = ctx->r10;
    // 0x8015212C: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
L_80152130:
    // 0x80152130: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
L_80152134:
    // 0x80152134: b           L_80151F00
    // 0x80152138: sh          $t0, 0x16E($s1)
    MEM_H(0X16E, ctx->r17) = ctx->r8;
        goto L_80151F00;
    // 0x80152138: sh          $t0, 0x16E($s1)
    MEM_H(0X16E, ctx->r17) = ctx->r8;
    // 0x8015213C: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
L_80152140:
    // 0x80152140: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x80152144: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80152148: sh          $t1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r9;
    // 0x8015214C: lb          $t3, 0x4($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X4);
    // 0x80152150: sh          $t3, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r11;
    // 0x80152154: lb          $t4, 0x5($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X5);
    // 0x80152158: sh          $t5, 0x16E($s1)
    MEM_H(0X16E, ctx->r17) = ctx->r13;
    // 0x8015215C: sh          $t4, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r12;
    // 0x80152160: addiu       $t7, $sp, 0x58
    ctx->r15 = ADD32(ctx->r29, 0X58);
L_80152164:
    // 0x80152164: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80152168: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8015216C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80152170: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80152174: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80152178: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8015217C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80152180: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80152184: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80152188: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8015218C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80152190: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80152194: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80152198: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8015219C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x801521A0: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x801521A4: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x801521A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801521AC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801521B0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801521B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801521B8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801521BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x801521C0: jr          $ra
    // 0x801521C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801521C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801521c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801521c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801521C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801521CC: lhu         $v1, -0x42A2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X42A2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801521d0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801521d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801521D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801521D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801521D8: bnel        $v1, $zero, L_801521F4
    if (ctx->r3 != 0) {
        // 0x801521DC: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_801521F4;
    }
    goto skip_0;
    // 0x801521DC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_0:
    // 0x801521E0: jal         0x80151C34
    // 0x801521E4: nop

    LOOKUP_FUNC(0x80151C34)(rdram, ctx);
        goto after_0;
    // 0x801521E4: nop

    after_0:
    // 0x801521E8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801521EC: lhu         $v1, -0x42A2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X42A2);
    // 0x801521F0: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_801521F4:
    // 0x801521F4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x801521F8: mfhi        $t6
    ctx->r14 = hi;
    // 0x801521FC: bne         $t6, $zero, L_8015220C
    if (ctx->r14 != 0) {
        // 0x80152200: nop
    
            goto L_8015220C;
    }
    // 0x80152200: nop

    // 0x80152204: jal         0x80150584
    // 0x80152208: nop

    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_1;
    // 0x80152208: nop

    after_1:
L_8015220C:
    // 0x8015220C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80152210: lhu         $t7, -0x42A2($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X42A2);
    // 0x80152214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152218: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8015221C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80152220: sh          $t8, -0x42A2($at)
    MEM_H(-0X42A2, ctx->r1) = ctx->r24;
    // 0x80152224: jr          $ra
    // 0x80152228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80152228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8015222c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8015222c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015222C: nop

    // 0x80152230: jr          $ra
    // 0x80152234: nop

    return;
    // 0x80152234: nop

;}
RECOMP_FUNC void M7_FUN_80152238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152238: jr          $ra
    // 0x8015223C: nop

    return;
    // 0x8015223C: nop

;}
RECOMP_FUNC void M7_FUN_80152240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152240: addiu       $sp, $sp, -0x390
    ctx->r29 = ADD32(ctx->r29, -0X390);
    // 0x80152244: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80152248: addiu       $t1, $sp, 0x2F0
    ctx->r9 = ADD32(ctx->r29, 0X2F0);
    // 0x8015224C: addiu       $t6, $t6, 0x34F8
    ctx->r14 = ADD32(ctx->r14, 0X34F8);
    // 0x80152250: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x80152254: addiu       $a0, $sp, 0x2D8
    ctx->r4 = ADD32(ctx->r29, 0X2D8);
    // 0x80152258: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x8015225C: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x80152260: addiu       $a3, $sp, 0xA4
    ctx->r7 = ADD32(ctx->r29, 0XA4);
    // 0x80152264: addiu       $t5, $t6, 0x9C
    ctx->r13 = ADD32(ctx->r14, 0X9C);
    // 0x80152268: or          $t9, $t1, $zero
    ctx->r25 = ctx->r9 | 0;
L_8015226C:
    // 0x8015226C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80152270: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80152274: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80152278: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8015227C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80152280: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80152284: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80152288: bne         $t6, $t5, L_8015226C
    if (ctx->r14 != ctx->r13) {
        // 0x8015228C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8015226C;
    }
    // 0x8015228C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80152290: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80152294: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80152298: addiu       $t5, $t5, 0x3598
    ctx->r13 = ADD32(ctx->r13, 0X3598);
    // 0x8015229C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x801522A0: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x801522A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801522A8: addiu       $t7, $t7, 0x35B0
    ctx->r15 = ADD32(ctx->r15, 0X35B0);
    // 0x801522AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801522B0: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801522B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801522B8: addiu       $t3, $t3, -0x1FFC
    ctx->r11 = ADD32(ctx->r11, -0X1FFC);
    // 0x801522BC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x801522C0: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x801522C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801522C8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801522CC: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x801522D0: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801522D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801522D8: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x801522DC: lw          $t9, 0x10($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X10);
    // 0x801522E0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x801522E4: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x801522E8: lbu         $t9, 0x14($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X14);
    // 0x801522EC: sb          $t9, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r25;
    // 0x801522F0: addiu       $t9, $t7, 0x204
    ctx->r25 = ADD32(ctx->r15, 0X204);
L_801522F4:
    // 0x801522F4: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x801522F8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801522FC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80152300: sw          $t5, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r13;
    // 0x80152304: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80152308: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8015230C: lw          $t5, -0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, -0X4);
    // 0x80152310: bne         $t7, $t9, L_801522F4
    if (ctx->r15 != ctx->r25) {
        // 0x80152314: sw          $t5, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r13;
            goto L_801522F4;
    }
    // 0x80152314: sw          $t5, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r13;
    // 0x80152318: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8015231C: addiu       $t9, $t9, 0x37B4
    ctx->r25 = ADD32(ctx->r25, 0X37B4);
    // 0x80152320: addiu       $t5, $t9, 0x24
    ctx->r13 = ADD32(ctx->r25, 0X24);
    // 0x80152324: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
L_80152328:
    // 0x80152328: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8015232C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80152330: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80152334: sw          $t6, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r14;
    // 0x80152338: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x8015233C: sw          $t7, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r15;
    // 0x80152340: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80152344: bne         $t9, $t5, L_80152328
    if (ctx->r25 != ctx->r13) {
        // 0x80152348: sw          $t6, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r14;
            goto L_80152328;
    }
    // 0x80152348: sw          $t6, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r14;
    // 0x8015234C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80152350: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80152354: addiu       $t5, $t5, 0x37DC
    ctx->r13 = ADD32(ctx->r13, 0X37DC);
    // 0x80152358: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8015235C: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80152360: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
    // 0x80152364: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80152368: lhu         $t8, 0x4($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X4);
    // 0x8015236C: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x80152370: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
    // 0x80152374: addiu       $t8, $t1, 0x9C
    ctx->r24 = ADD32(ctx->r9, 0X9C);
L_80152378:
    // 0x80152378: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8015237C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80152380: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80152384: sw          $t6, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r14;
    // 0x80152388: lw          $t7, -0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, -0X8);
    // 0x8015238C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80152390: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x80152394: bne         $t5, $t8, L_80152378
    if (ctx->r13 != ctx->r24) {
        // 0x80152398: sw          $t6, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r14;
            goto L_80152378;
    }
    // 0x80152398: sw          $t6, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r14;
    // 0x8015239C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801523A0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801523A4: addiu       $t8, $t8, -0x2322
    ctx->r24 = ADD32(ctx->r24, -0X2322);
    // 0x801523A8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x801523AC: addiu       $t6, $v1, 0x9C
    ctx->r14 = ADD32(ctx->r3, 0X9C);
    // 0x801523B0: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
L_801523B4:
    // 0x801523B4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801523B8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801523BC: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x801523C0: swl         $t9, -0xC($t8)
    do_swl(rdram, -0XC, ctx->r24, ctx->r25);
    // 0x801523C4: swr         $t9, -0x9($t8)
    do_swr(rdram, -0X9, ctx->r24, ctx->r25);
    // 0x801523C8: lw          $t5, -0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, -0X8);
    // 0x801523CC: swl         $t5, -0x8($t8)
    do_swl(rdram, -0X8, ctx->r24, ctx->r13);
    // 0x801523D0: swr         $t5, -0x5($t8)
    do_swr(rdram, -0X5, ctx->r24, ctx->r13);
    // 0x801523D4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801523D8: swl         $t9, -0x4($t8)
    do_swl(rdram, -0X4, ctx->r24, ctx->r25);
    // 0x801523DC: bne         $t7, $t6, L_801523B4
    if (ctx->r15 != ctx->r14) {
        // 0x801523E0: swr         $t9, -0x1($t8)
        do_swr(rdram, -0X1, ctx->r24, ctx->r25);
            goto L_801523B4;
    }
    // 0x801523E0: swr         $t9, -0x1($t8)
    do_swr(rdram, -0X1, ctx->r24, ctx->r25);
    // 0x801523E4: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x801523E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801523EC: addiu       $t6, $t6, -0x23C0
    ctx->r14 = ADD32(ctx->r14, -0X23C0);
    // 0x801523F0: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x801523F4: addiu       $t9, $v1, 0x9C
    ctx->r25 = ADD32(ctx->r3, 0X9C);
    // 0x801523F8: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
L_801523FC:
    // 0x801523FC: lwl         $t8, 0x0($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0X0);
    // 0x80152400: lwr         $t8, 0x3($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0X3);
    // 0x80152404: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80152408: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8015240C: swl         $t8, -0xC($t6)
    do_swl(rdram, -0XC, ctx->r14, ctx->r24);
    // 0x80152410: swr         $t8, -0x9($t6)
    do_swr(rdram, -0X9, ctx->r14, ctx->r24);
    // 0x80152414: lwl         $t7, -0x8($t5)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r13, -0X8);
    // 0x80152418: lwr         $t7, -0x5($t5)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r13, -0X5);
    // 0x8015241C: swl         $t7, -0x8($t6)
    do_swl(rdram, -0X8, ctx->r14, ctx->r15);
    // 0x80152420: swr         $t7, -0x5($t6)
    do_swr(rdram, -0X5, ctx->r14, ctx->r15);
    // 0x80152424: lwl         $t8, -0x4($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, -0X4);
    // 0x80152428: lwr         $t8, -0x1($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, -0X1);
    // 0x8015242C: swl         $t8, -0x4($t6)
    do_swl(rdram, -0X4, ctx->r14, ctx->r24);
    // 0x80152430: bne         $t5, $t9, L_801523FC
    if (ctx->r13 != ctx->r25) {
        // 0x80152434: swr         $t8, -0x1($t6)
        do_swr(rdram, -0X1, ctx->r14, ctx->r24);
            goto L_801523FC;
    }
    // 0x80152434: swr         $t8, -0x1($t6)
    do_swr(rdram, -0X1, ctx->r14, ctx->r24);
    // 0x80152438: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8015243C: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80152440: addiu       $t1, $zero, 0x27
    ctx->r9 = ADD32(0, 0X27);
    // 0x80152444: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
L_80152448:
    // 0x80152448: beq         $t1, $t0, L_80152458
    if (ctx->r9 == ctx->r8) {
        // 0x8015244C: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_80152458;
    }
    // 0x8015244C: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80152450: bne         $t2, $t0, L_80152464
    if (ctx->r10 != ctx->r8) {
        // 0x80152454: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_80152464;
    }
    // 0x80152454: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_80152458:
    // 0x80152458: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x8015245C: b           L_8015246C
    // 0x80152460: sb          $t4, 0x4($t5)
    MEM_B(0X4, ctx->r13) = ctx->r12;
        goto L_8015246C;
    // 0x80152460: sb          $t4, 0x4($t5)
    MEM_B(0X4, ctx->r13) = ctx->r12;
L_80152464:
    // 0x80152464: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80152468: sb          $zero, 0x4($t7)
    MEM_B(0X4, ctx->r15) = 0;
L_8015246C:
    // 0x8015246C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80152470: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80152474: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x80152478: bne         $at, $zero, L_80152448
    if (ctx->r1 != 0) {
        // 0x8015247C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80152448;
    }
    // 0x8015247C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80152480: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80152484: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80152488: addiu       $t2, $t2, -0x20D4
    ctx->r10 = ADD32(ctx->r10, -0X20D4);
    // 0x8015248C: addiu       $t3, $t3, -0x20EC
    ctx->r11 = ADD32(ctx->r11, -0X20EC);
    // 0x80152490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80152494: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_80152498:
    // 0x80152498: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8015249C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801524A0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801524A4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801524A8: mflo        $t0
    ctx->r8 = lo;
    // 0x801524AC: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x801524B0: lwl         $t5, 0x0($t8)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r24, 0X0);
    // 0x801524B4: lwr         $t5, 0x3($t8)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r24, 0X3);
    // 0x801524B8: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x801524BC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801524C0: lbu         $t5, 0x4($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X4);
    // 0x801524C4: sb          $t5, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r13;
    // 0x801524C8: lbu         $t9, 0x5($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5);
    // 0x801524CC: sb          $t9, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r25;
    // 0x801524D0: lbu         $t5, 0x6($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X6);
    // 0x801524D4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801524D8: addu        $t9, $t3, $t0
    ctx->r25 = ADD32(ctx->r11, ctx->r8);
    // 0x801524DC: sb          $t5, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r13;
    // 0x801524E0: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x801524E4: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    // 0x801524E8: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x801524EC: sb          $t8, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r24;
    // 0x801524F0: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x801524F4: sb          $t7, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r15;
    // 0x801524F8: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x801524FC: sb          $t8, 0x6($t6)
    MEM_B(0X6, ctx->r14) = ctx->r24;
    // 0x80152500: lwl         $t6, 0x0($v1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r3, 0X0);
    // 0x80152504: lwr         $t6, 0x3($v1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r3, 0X3);
    // 0x80152508: swl         $t6, 0x0($t9)
    do_swl(rdram, 0X0, ctx->r25, ctx->r14);
    // 0x8015250C: swr         $t6, 0x3($t9)
    do_swr(rdram, 0X3, ctx->r25, ctx->r14);
    // 0x80152510: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80152514: sb          $t6, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r14;
    // 0x80152518: lbu         $t5, 0x5($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X5);
    // 0x8015251C: sb          $t5, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r13;
    // 0x80152520: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x80152524: bne         $at, $zero, L_80152498
    if (ctx->r1 != 0) {
        // 0x80152528: sb          $t6, 0x6($t9)
        MEM_B(0X6, ctx->r25) = ctx->r14;
            goto L_80152498;
    }
    // 0x80152528: sb          $t6, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r14;
    // 0x8015252C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80152530: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80152534: addiu       $t2, $t2, 0x3CE0
    ctx->r10 = ADD32(ctx->r10, 0X3CE0);
    // 0x80152538: addiu       $t3, $t3, 0x40E8
    ctx->r11 = ADD32(ctx->r11, 0X40E8);
    // 0x8015253C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80152540: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
L_80152544:
    // 0x80152544: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80152548: mflo        $a0
    ctx->r4 = lo;
    // 0x8015254C: addu        $t7, $a1, $a0
    ctx->r15 = ADD32(ctx->r5, ctx->r4);
    // 0x80152550: lwl         $t9, 0x0($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X0);
    // 0x80152554: lwr         $t9, 0x3($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X3);
    // 0x80152558: addu        $t0, $t2, $a0
    ctx->r8 = ADD32(ctx->r10, ctx->r4);
    // 0x8015255C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80152560: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x80152564: lwl         $t8, 0x0($v1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r3, 0X0);
    // 0x80152568: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8015256C: lwr         $t8, 0x3($v1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r3, 0X3);
    // 0x80152570: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
    // 0x80152574: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80152578: swl         $t6, 0x204($t0)
    do_swl(rdram, 0X204, ctx->r8, ctx->r14);
    // 0x8015257C: swl         $t8, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r24);
    // 0x80152580: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80152584: swr         $t6, 0x207($t0)
    do_swr(rdram, 0X207, ctx->r8, ctx->r14);
    // 0x80152588: swr         $t8, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r24);
    // 0x8015258C: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
    // 0x80152590: lhu         $t6, 0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X4);
    // 0x80152594: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80152598: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    // 0x8015259C: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x801525A0: sh          $t8, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r24;
    // 0x801525A4: bne         $at, $zero, L_80152544
    if (ctx->r1 != 0) {
        // 0x801525A8: sh          $t6, 0x208($t0)
        MEM_H(0X208, ctx->r8) = ctx->r14;
            goto L_80152544;
    }
    // 0x801525A8: sh          $t6, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r14;
    // 0x801525AC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801525B0: addiu       $t5, $t5, -0x2284
    ctx->r13 = ADD32(ctx->r13, -0X2284);
    // 0x801525B4: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x801525B8: addiu       $t9, $a2, 0x24
    ctx->r25 = ADD32(ctx->r6, 0X24);
L_801525BC:
    // 0x801525BC: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x801525C0: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x801525C4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x801525C8: sw          $t7, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r15;
    // 0x801525CC: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x801525D0: sw          $t6, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r14;
    // 0x801525D4: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x801525D8: bne         $t8, $t9, L_801525BC
    if (ctx->r24 != ctx->r25) {
        // 0x801525DC: sw          $t7, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r15;
            goto L_801525BC;
    }
    // 0x801525DC: sw          $t7, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r15;
    // 0x801525E0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x801525E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801525E8: addiu       $t9, $t9, -0x225C
    ctx->r25 = ADD32(ctx->r25, -0X225C);
    // 0x801525EC: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x801525F0: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801525F4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x801525F8: lhu         $t5, 0x4($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X4);
    // 0x801525FC: addiu       $sp, $sp, 0x390
    ctx->r29 = ADD32(ctx->r29, 0X390);
    // 0x80152600: jr          $ra
    // 0x80152604: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    return;
    // 0x80152604: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152608(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152608: addiu       $sp, $sp, -0x2F0
    ctx->r29 = ADD32(ctx->r29, -0X2F0);
    // 0x8015260C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80152610: addiu       $a0, $sp, 0x250
    ctx->r4 = ADD32(ctx->r29, 0X250);
    // 0x80152614: addiu       $t6, $t6, 0x37E4
    ctx->r14 = ADD32(ctx->r14, 0X37E4);
    // 0x80152618: addiu       $a1, $sp, 0x238
    ctx->r5 = ADD32(ctx->r29, 0X238);
    // 0x8015261C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80152620: addiu       $a3, $sp, 0xC
    ctx->r7 = ADD32(ctx->r29, 0XC);
    // 0x80152624: addiu       $t1, $t6, 0x9C
    ctx->r9 = ADD32(ctx->r14, 0X9C);
    // 0x80152628: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8015262C:
    // 0x8015262C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80152630: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80152634: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80152638: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8015263C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80152640: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80152644: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80152648: bne         $t6, $t1, L_8015262C
    if (ctx->r14 != ctx->r9) {
        // 0x8015264C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8015262C;
    }
    // 0x8015264C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80152650: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80152654: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80152658: addiu       $t2, $t2, 0x3884
    ctx->r10 = ADD32(ctx->r10, 0X3884);
    // 0x8015265C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80152660: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80152664: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80152668: addiu       $t5, $t5, 0x389C
    ctx->r13 = ADD32(ctx->r13, 0X389C);
    // 0x8015266C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80152670: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80152674: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80152678: addiu       $t7, $t5, 0x204
    ctx->r15 = ADD32(ctx->r13, 0X204);
    // 0x8015267C: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80152680: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80152684: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x80152688: addiu       $t8, $t8, 0x3AA0
    ctx->r24 = ADD32(ctx->r24, 0X3AA0);
    // 0x8015268C: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x80152690: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80152694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80152698: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8015269C: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
    // 0x801526A0: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x801526A4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x801526A8: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
    // 0x801526AC: lbu         $t4, 0x14($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X14);
    // 0x801526B0: sb          $t4, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r12;
L_801526B4:
    // 0x801526B4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801526B8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x801526BC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801526C0: sw          $t6, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r14;
    // 0x801526C4: lw          $t1, -0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, -0X8);
    // 0x801526C8: sw          $t1, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r9;
    // 0x801526CC: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x801526D0: bne         $t5, $t7, L_801526B4
    if (ctx->r13 != ctx->r15) {
        // 0x801526D4: sw          $t6, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r14;
            goto L_801526B4;
    }
    // 0x801526D4: sw          $t6, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r14;
    // 0x801526D8: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x801526DC: addiu       $t7, $t8, 0x24
    ctx->r15 = ADD32(ctx->r24, 0X24);
L_801526E0:
    // 0x801526E0: lw          $t3, 0x0($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X0);
    // 0x801526E4: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x801526E8: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x801526EC: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x801526F0: lw          $t2, -0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, -0X8);
    // 0x801526F4: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x801526F8: lw          $t3, -0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, -0X4);
    // 0x801526FC: bne         $t8, $t7, L_801526E0
    if (ctx->r24 != ctx->r15) {
        // 0x80152700: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_801526E0;
    }
    // 0x80152700: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x80152704: lw          $t3, 0x0($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X0);
    // 0x80152708: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8015270C: addiu       $t5, $t5, -0x23C0
    ctx->r13 = ADD32(ctx->r13, -0X23C0);
    // 0x80152710: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80152714: addiu       $t7, $a0, 0x9C
    ctx->r15 = ADD32(ctx->r4, 0X9C);
    // 0x80152718: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8015271C:
    // 0x8015271C: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x80152720: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80152724: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80152728: swl         $t1, -0xC($t5)
    do_swl(rdram, -0XC, ctx->r13, ctx->r9);
    // 0x8015272C: swr         $t1, -0x9($t5)
    do_swr(rdram, -0X9, ctx->r13, ctx->r9);
    // 0x80152730: lw          $t9, -0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X8);
    // 0x80152734: swl         $t9, -0x8($t5)
    do_swl(rdram, -0X8, ctx->r13, ctx->r25);
    // 0x80152738: swr         $t9, -0x5($t5)
    do_swr(rdram, -0X5, ctx->r13, ctx->r25);
    // 0x8015273C: lw          $t1, -0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, -0X4);
    // 0x80152740: swl         $t1, -0x4($t5)
    do_swl(rdram, -0X4, ctx->r13, ctx->r9);
    // 0x80152744: bne         $t6, $t7, L_8015271C
    if (ctx->r14 != ctx->r15) {
        // 0x80152748: swr         $t1, -0x1($t5)
        do_swr(rdram, -0X1, ctx->r13, ctx->r9);
            goto L_8015271C;
    }
    // 0x80152748: swr         $t1, -0x1($t5)
    do_swr(rdram, -0X1, ctx->r13, ctx->r9);
    // 0x8015274C: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x80152750: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80152754: addiu       $a0, $a0, -0x1FFC
    ctx->r4 = ADD32(ctx->r4, -0X1FFC);
    // 0x80152758: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
L_8015275C:
    // 0x8015275C: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x80152760: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80152764: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80152768: bgez        $v1, L_8015277C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8015276C: andi        $t8, $v1, 0x3
        ctx->r24 = ctx->r3 & 0X3;
            goto L_8015277C;
    }
    // 0x8015276C: andi        $t8, $v1, 0x3
    ctx->r24 = ctx->r3 & 0X3;
    // 0x80152770: beq         $t8, $zero, L_8015277C
    if (ctx->r24 == 0) {
        // 0x80152774: nop
    
            goto L_8015277C;
    }
    // 0x80152774: nop

    // 0x80152778: addiu       $t8, $t8, -0x4
    ctx->r24 = ADD32(ctx->r24, -0X4);
L_8015277C:
    // 0x8015277C: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
    // 0x80152780: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80152784: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80152788: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8015278C: bne         $at, $zero, L_8015275C
    if (ctx->r1 != 0) {
        // 0x80152790: sb          $t4, 0x4($t3)
        MEM_B(0X4, ctx->r11) = ctx->r12;
            goto L_8015275C;
    }
    // 0x80152790: sb          $t4, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r12;
    // 0x80152794: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80152798: addiu       $a0, $a0, -0x20EC
    ctx->r4 = ADD32(ctx->r4, -0X20EC);
    // 0x8015279C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801527A0:
    // 0x801527A0: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801527A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801527A8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801527AC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801527B0: mflo        $v1
    ctx->r3 = lo;
    // 0x801527B4: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x801527B8: lwl         $t9, 0x0($t6)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r14, 0X0);
    // 0x801527BC: lwr         $t9, 0x3($t6)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r14, 0X3);
    // 0x801527C0: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x801527C4: swl         $t9, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r25);
    // 0x801527C8: swr         $t9, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r25);
    // 0x801527CC: lbu         $t9, 0x4($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X4);
    // 0x801527D0: sb          $t9, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r25;
    // 0x801527D4: lbu         $t5, 0x5($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X5);
    // 0x801527D8: sb          $t5, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r13;
    // 0x801527DC: lbu         $t9, 0x6($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X6);
    // 0x801527E0: bne         $at, $zero, L_801527A0
    if (ctx->r1 != 0) {
        // 0x801527E4: sb          $t9, 0x6($t7)
        MEM_B(0X6, ctx->r15) = ctx->r25;
            goto L_801527A0;
    }
    // 0x801527E4: sb          $t9, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r25;
    // 0x801527E8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801527EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801527F0: addiu       $a0, $a0, 0x3CE0
    ctx->r4 = ADD32(ctx->r4, 0X3CE0);
    // 0x801527F4: addiu       $t0, $t0, 0x40E8
    ctx->r8 = ADD32(ctx->r8, 0X40E8);
    // 0x801527F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801527FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80152800:
    // 0x80152800: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80152804: addu        $t3, $t0, $v0
    ctx->r11 = ADD32(ctx->r8, ctx->r2);
    // 0x80152808: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8015280C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80152810: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    // 0x80152814: mflo        $v1
    ctx->r3 = lo;
    // 0x80152818: addu        $t8, $a2, $v1
    ctx->r24 = ADD32(ctx->r6, ctx->r3);
    // 0x8015281C: lwl         $t4, 0x0($t8)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r24, 0X0);
    // 0x80152820: lwr         $t4, 0x3($t8)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r24, 0X3);
    // 0x80152824: addu        $t1, $a0, $v1
    ctx->r9 = ADD32(ctx->r4, ctx->r3);
    // 0x80152828: swl         $t4, 0x0($t1)
    do_swl(rdram, 0X0, ctx->r9, ctx->r12);
    // 0x8015282C: swr         $t4, 0x3($t1)
    do_swr(rdram, 0X3, ctx->r9, ctx->r12);
    // 0x80152830: lhu         $t4, 0x4($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X4);
    // 0x80152834: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
    // 0x80152838: bne         $at, $zero, L_80152800
    if (ctx->r1 != 0) {
        // 0x8015283C: sb          $zero, 0x0($t3)
        MEM_B(0X0, ctx->r11) = 0;
            goto L_80152800;
    }
    // 0x8015283C: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x80152840: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80152844: addiu       $t7, $t7, -0x2284
    ctx->r15 = ADD32(ctx->r15, -0X2284);
    // 0x80152848: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x8015284C: addiu       $t1, $a3, 0x24
    ctx->r9 = ADD32(ctx->r7, 0X24);
L_80152850:
    // 0x80152850: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80152854: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80152858: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8015285C: sw          $t5, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r13;
    // 0x80152860: lw          $t6, -0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X8);
    // 0x80152864: sw          $t6, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r14;
    // 0x80152868: lw          $t5, -0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, -0X4);
    // 0x8015286C: bne         $t9, $t1, L_80152850
    if (ctx->r25 != ctx->r9) {
        // 0x80152870: sw          $t5, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r13;
            goto L_80152850;
    }
    // 0x80152870: sw          $t5, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r13;
    // 0x80152874: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80152878: addiu       $sp, $sp, 0x2F0
    ctx->r29 = ADD32(ctx->r29, 0X2F0);
    // 0x8015287C: jr          $ra
    // 0x80152880: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    return;
    // 0x80152880: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152884(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152884: nop

    // 0x80152888: nop

    // 0x8015288C: nop

;}
RECOMP_FUNC void M7_FUN_80152890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152890: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152894: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152898: bne         $a0, $zero, L_801528AC
    if (ctx->r4 != 0) {
        // 0x8015289C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801528AC;
    }
    // 0x8015289C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801528A0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801528A4: b           L_801528B4
    // 0x801528A8: addiu       $v0, $v0, -0x2282
    ctx->r2 = ADD32(ctx->r2, -0X2282);
        goto L_801528B4;
    // 0x801528A8: addiu       $v0, $v0, -0x2282
    ctx->r2 = ADD32(ctx->r2, -0X2282);
L_801528AC:
    // 0x801528AC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801528B0: addiu       $v0, $v0, -0x227C
    ctx->r2 = ADD32(ctx->r2, -0X227C);
L_801528B4:
    // 0x801528B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801528B8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x801528BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801528C0: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x801528C4: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x801528C8: lbu         $t2, 0x3($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X3);
    // 0x801528CC: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
L_801528D0:
    // 0x801528D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801528D4: sllv        $a3, $t6, $a2
    ctx->r7 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x801528D8: and         $t7, $a1, $a3
    ctx->r15 = ctx->r5 & ctx->r7;
    // 0x801528DC: beq         $t7, $zero, L_801528EC
    if (ctx->r15 == 0) {
        // 0x801528E0: and         $t8, $t0, $a3
        ctx->r24 = ctx->r8 & ctx->r7;
            goto L_801528EC;
    }
    // 0x801528E0: and         $t8, $t0, $a3
    ctx->r24 = ctx->r8 & ctx->r7;
    // 0x801528E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801528E8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_801528EC:
    // 0x801528EC: beq         $t8, $zero, L_801528FC
    if (ctx->r24 == 0) {
        // 0x801528F0: and         $t9, $t1, $a3
        ctx->r25 = ctx->r9 & ctx->r7;
            goto L_801528FC;
    }
    // 0x801528F0: and         $t9, $t1, $a3
    ctx->r25 = ctx->r9 & ctx->r7;
    // 0x801528F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801528F8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_801528FC:
    // 0x801528FC: beq         $t9, $zero, L_8015290C
    if (ctx->r25 == 0) {
        // 0x80152900: and         $t4, $t2, $a3
        ctx->r12 = ctx->r10 & ctx->r7;
            goto L_8015290C;
    }
    // 0x80152900: and         $t4, $t2, $a3
    ctx->r12 = ctx->r10 & ctx->r7;
    // 0x80152904: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152908: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8015290C:
    // 0x8015290C: beq         $t4, $zero, L_8015291C
    if (ctx->r12 == 0) {
        // 0x80152910: and         $t5, $t3, $a3
        ctx->r13 = ctx->r11 & ctx->r7;
            goto L_8015291C;
    }
    // 0x80152910: and         $t5, $t3, $a3
    ctx->r13 = ctx->r11 & ctx->r7;
    // 0x80152914: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152918: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8015291C:
    // 0x8015291C: beq         $t5, $zero, L_8015292C
    if (ctx->r13 == 0) {
        // 0x80152920: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8015292C;
    }
    // 0x80152920: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80152924: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152928: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8015292C:
    // 0x8015292C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152930: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x80152934: bne         $at, $zero, L_801528D0
    if (ctx->r1 != 0) {
        // 0x80152938: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801528D0;
    }
    // 0x80152938: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8015293C: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x80152940: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80152944: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80152948: beq         $t6, $zero, L_80152958
    if (ctx->r14 == 0) {
        // 0x8015294C: andi        $t7, $a0, 0x2
        ctx->r15 = ctx->r4 & 0X2;
            goto L_80152958;
    }
    // 0x8015294C: andi        $t7, $a0, 0x2
    ctx->r15 = ctx->r4 & 0X2;
    // 0x80152950: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152954: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152958:
    // 0x80152958: beql        $t7, $zero, L_80152978
    if (ctx->r15 == 0) {
        // 0x8015295C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80152978;
    }
    goto skip_0;
    // 0x8015295C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_0:
    // 0x80152960: lbu         $t8, -0x226E($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X226E);
    // 0x80152964: bnel        $t8, $zero, L_80152978
    if (ctx->r24 != 0) {
        // 0x80152968: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80152978;
    }
    goto skip_1;
    // 0x80152968: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_1:
    // 0x8015296C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152970: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80152974: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80152978:
    // 0x80152978: jr          $ra
    // 0x8015297C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8015297C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152980(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80152984: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80152988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015298C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80152990: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80152994: bne         $a2, $zero, L_801529A8
    if (ctx->r6 != 0) {
        // 0x80152998: andi        $a3, $a1, 0xFF
        ctx->r7 = ctx->r5 & 0XFF;
            goto L_801529A8;
    }
    // 0x80152998: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x8015299C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801529A0: b           L_801529B0
    // 0x801529A4: addiu       $a0, $a0, -0x2282
    ctx->r4 = ADD32(ctx->r4, -0X2282);
        goto L_801529B0;
    // 0x801529A4: addiu       $a0, $a0, -0x2282
    ctx->r4 = ADD32(ctx->r4, -0X2282);
L_801529A8:
    // 0x801529A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801529AC: addiu       $a0, $a0, -0x227C
    ctx->r4 = ADD32(ctx->r4, -0X227C);
L_801529B0:
    // 0x801529B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801529B4: bne         $a2, $zero, L_801529F0
    if (ctx->r6 != 0) {
        // 0x801529B8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801529F0;
    }
    // 0x801529B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801529BC: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801529C0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x801529C4: sb          $zero, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = 0;
    // 0x801529C8: sb          $a2, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r6;
    // 0x801529CC: jal         0x80140274
    // 0x801529D0: sb          $a3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80140274)(rdram, ctx);
        goto after_0;
    // 0x801529D0: sb          $a3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r7;
    after_0:
    // 0x801529D4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801529D8: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x801529DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801529E0: lbu         $a1, 0x1E($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1E);
    // 0x801529E4: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x801529E8: bne         $at, $zero, L_80152A24
    if (ctx->r1 != 0) {
        // 0x801529EC: lbu         $a3, 0x2F($sp)
        ctx->r7 = MEM_BU(ctx->r29, 0X2F);
            goto L_80152A24;
    }
    // 0x801529EC: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
L_801529F0:
    // 0x801529F0: beq         $a2, $zero, L_80152A48
    if (ctx->r6 == 0) {
        // 0x801529F4: nop
    
            goto L_80152A48;
    }
    // 0x801529F4: nop

    // 0x801529F8: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    // 0x801529FC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80152A00: sb          $a1, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r5;
    // 0x80152A04: jal         0x801402AC
    // 0x80152A08: sb          $a3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801402AC)(rdram, ctx);
        goto after_1;
    // 0x80152A08: sb          $a3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r7;
    after_1:
    // 0x80152A0C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80152A10: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x80152A14: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80152A18: lbu         $a1, 0x1E($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1E);
    // 0x80152A1C: beq         $at, $zero, L_80152A48
    if (ctx->r1 == 0) {
        // 0x80152A20: lbu         $a3, 0x2F($sp)
        ctx->r7 = MEM_BU(ctx->r29, 0X2F);
            goto L_80152A48;
    }
    // 0x80152A20: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
L_80152A24:
    // 0x80152A24: bne         $a3, $zero, L_80152A34
    if (ctx->r7 != 0) {
        // 0x80152A28: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80152A34;
    }
    // 0x80152A28: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80152A2C: b           L_80152BB8
    // 0x80152A30: addiu       $v0, $zero, 0x11C
    ctx->r2 = ADD32(0, 0X11C);
        goto L_80152BB8;
    // 0x80152A30: addiu       $v0, $zero, 0x11C
    ctx->r2 = ADD32(0, 0X11C);
L_80152A34:
    // 0x80152A34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80152A38: bnel        $a2, $at, L_80152A70
    if (ctx->r6 != ctx->r1) {
        // 0x80152A3C: addiu       $a3, $a2, -0x2
        ctx->r7 = ADD32(ctx->r6, -0X2);
            goto L_80152A70;
    }
    goto skip_0;
    // 0x80152A3C: addiu       $a3, $a2, -0x2
    ctx->r7 = ADD32(ctx->r6, -0X2);
    skip_0:
    // 0x80152A40: b           L_80152BB8
    // 0x80152A44: addiu       $v0, $zero, 0x11B
    ctx->r2 = ADD32(0, 0X11B);
        goto L_80152BB8;
    // 0x80152A44: addiu       $v0, $zero, 0x11B
    ctx->r2 = ADD32(0, 0X11B);
L_80152A48:
    // 0x80152A48: bne         $a3, $zero, L_80152A58
    if (ctx->r7 != 0) {
        // 0x80152A4C: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80152A58;
    }
    // 0x80152A4C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80152A50: b           L_80152BB8
    // 0x80152A54: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
        goto L_80152BB8;
    // 0x80152A54: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
L_80152A58:
    // 0x80152A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80152A5C: bnel        $a2, $at, L_80152A70
    if (ctx->r6 != ctx->r1) {
        // 0x80152A60: addiu       $a3, $a2, -0x2
        ctx->r7 = ADD32(ctx->r6, -0X2);
            goto L_80152A70;
    }
    goto skip_1;
    // 0x80152A60: addiu       $a3, $a2, -0x2
    ctx->r7 = ADD32(ctx->r6, -0X2);
    skip_1:
    // 0x80152A64: b           L_80152BB8
    // 0x80152A68: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
        goto L_80152BB8;
    // 0x80152A68: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
    // 0x80152A6C: addiu       $a3, $a2, -0x2
    ctx->r7 = ADD32(ctx->r6, -0X2);
L_80152A70:
    // 0x80152A70: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    // 0x80152A74: bltz        $a2, L_80152B98
    if (SIGNED(ctx->r6) < 0) {
        // 0x80152A78: slti        $at, $a1, 0x8
        ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
            goto L_80152B98;
    }
L_80152A78:
    // 0x80152A78: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80152A7C: beq         $at, $zero, L_80152AA8
    if (ctx->r1 == 0) {
        // 0x80152A80: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80152AA8;
    }
    // 0x80152A80: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80152A84: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80152A88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80152A8C: sllv        $t8, $t7, $v0
    ctx->r24 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80152A90: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80152A94: beql        $t9, $zero, L_80152B8C
    if (ctx->r25 == 0) {
        // 0x80152A98: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80152B8C;
    }
    goto skip_2;
    // 0x80152A98: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_2:
    // 0x80152A9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152AA0: b           L_80152B88
    // 0x80152AA4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80152B88;
    // 0x80152AA4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152AA8:
    // 0x80152AA8: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80152AAC: beq         $at, $zero, L_80152AD8
    if (ctx->r1 == 0) {
        // 0x80152AB0: addiu       $t1, $v0, 0x18
        ctx->r9 = ADD32(ctx->r2, 0X18);
            goto L_80152AD8;
    }
    // 0x80152AB0: addiu       $t1, $v0, 0x18
    ctx->r9 = ADD32(ctx->r2, 0X18);
    // 0x80152AB4: lbu         $t0, 0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1);
    // 0x80152AB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80152ABC: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80152AC0: and         $t4, $t0, $t3
    ctx->r12 = ctx->r8 & ctx->r11;
    // 0x80152AC4: beql        $t4, $zero, L_80152B8C
    if (ctx->r12 == 0) {
        // 0x80152AC8: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80152B8C;
    }
    goto skip_3;
    // 0x80152AC8: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_3:
    // 0x80152ACC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152AD0: b           L_80152B88
    // 0x80152AD4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80152B88;
    // 0x80152AD4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152AD8:
    // 0x80152AD8: slti        $at, $v0, 0x18
    ctx->r1 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x80152ADC: beq         $at, $zero, L_80152B08
    if (ctx->r1 == 0) {
        // 0x80152AE0: addiu       $t7, $v0, 0x10
        ctx->r15 = ADD32(ctx->r2, 0X10);
            goto L_80152B08;
    }
    // 0x80152AE0: addiu       $t7, $v0, 0x10
    ctx->r15 = ADD32(ctx->r2, 0X10);
    // 0x80152AE4: lbu         $t5, 0x2($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X2);
    // 0x80152AE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80152AEC: sllv        $t8, $t6, $t7
    ctx->r24 = S32(ctx->r14 << (ctx->r15 & 31));
    // 0x80152AF0: and         $t9, $t5, $t8
    ctx->r25 = ctx->r13 & ctx->r24;
    // 0x80152AF4: beql        $t9, $zero, L_80152B8C
    if (ctx->r25 == 0) {
        // 0x80152AF8: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80152B8C;
    }
    goto skip_4;
    // 0x80152AF8: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_4:
    // 0x80152AFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152B00: b           L_80152B88
    // 0x80152B04: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80152B88;
    // 0x80152B04: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152B08:
    // 0x80152B08: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80152B0C: beq         $at, $zero, L_80152B38
    if (ctx->r1 == 0) {
        // 0x80152B10: addiu       $t1, $v0, 0x8
        ctx->r9 = ADD32(ctx->r2, 0X8);
            goto L_80152B38;
    }
    // 0x80152B10: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80152B14: lbu         $t2, 0x3($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X3);
    // 0x80152B18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80152B1C: sllv        $t3, $t0, $t1
    ctx->r11 = S32(ctx->r8 << (ctx->r9 & 31));
    // 0x80152B20: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80152B24: beql        $t4, $zero, L_80152B8C
    if (ctx->r12 == 0) {
        // 0x80152B28: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80152B8C;
    }
    goto skip_5;
    // 0x80152B28: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_5:
    // 0x80152B2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152B30: b           L_80152B88
    // 0x80152B34: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80152B88;
    // 0x80152B34: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152B38:
    // 0x80152B38: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80152B3C: beq         $at, $zero, L_80152B68
    if (ctx->r1 == 0) {
        // 0x80152B40: addiu       $t0, $v0, 0x18
        ctx->r8 = ADD32(ctx->r2, 0X18);
            goto L_80152B68;
    }
    // 0x80152B40: addiu       $t0, $v0, 0x18
    ctx->r8 = ADD32(ctx->r2, 0X18);
    // 0x80152B44: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x80152B48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80152B4C: sllv        $t5, $t7, $v0
    ctx->r13 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80152B50: and         $t8, $t6, $t5
    ctx->r24 = ctx->r14 & ctx->r13;
    // 0x80152B54: beql        $t8, $zero, L_80152B8C
    if (ctx->r24 == 0) {
        // 0x80152B58: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80152B8C;
    }
    goto skip_6;
    // 0x80152B58: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_6:
    // 0x80152B5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152B60: b           L_80152B88
    // 0x80152B64: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_80152B88;
    // 0x80152B64: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152B68:
    // 0x80152B68: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
    // 0x80152B6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80152B70: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80152B74: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x80152B78: beql        $t3, $zero, L_80152B8C
    if (ctx->r11 == 0) {
        // 0x80152B7C: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80152B8C;
    }
    goto skip_7;
    // 0x80152B7C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_7:
    // 0x80152B80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80152B84: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80152B88:
    // 0x80152B88: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
L_80152B8C:
    // 0x80152B8C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80152B90: beq         $at, $zero, L_80152A78
    if (ctx->r1 == 0) {
        // 0x80152B94: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80152A78;
    }
    // 0x80152B94: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_80152B98:
    // 0x80152B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80152B9C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80152BA0: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80152BA4: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80152BA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80152BAC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152BB0: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80152BB4: lhu         $v0, 0x3AD0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3AD0);
L_80152BB8:
    // 0x80152BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80152BC0: jr          $ra
    // 0x80152BC4: nop

    return;
    // 0x80152BC4: nop

;}
RECOMP_FUNC void M7_FUN_80152bc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152BC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152BCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80152BD0: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80152BD4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152BD8: bne         $a0, $zero, L_80152BEC
    if (ctx->r4 != 0) {
        // 0x80152BDC: sra         $a1, $a1, 24
        ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
            goto L_80152BEC;
    }
    // 0x80152BDC: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80152BE0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152BE4: b           L_80152BF4
    // 0x80152BE8: addiu       $v0, $v0, -0x2276
    ctx->r2 = ADD32(ctx->r2, -0X2276);
        goto L_80152BF4;
    // 0x80152BE8: addiu       $v0, $v0, -0x2276
    ctx->r2 = ADD32(ctx->r2, -0X2276);
L_80152BEC:
    // 0x80152BEC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152BF0: addiu       $v0, $v0, -0x2275
    ctx->r2 = ADD32(ctx->r2, -0X2275);
L_80152BF4:
    // 0x80152BF4: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80152BF8: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80152BFC: jr          $ra
    // 0x80152C00: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x80152C00: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152c04(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152c04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152C04: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80152C08: addiu       $a1, $a1, 0x3AD0
    ctx->r5 = ADD32(ctx->r5, 0X3AD0);
    // 0x80152C0C: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x80152C10: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80152C14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152C18: beq         $v0, $t6, L_80152C50
    if (ctx->r2 == ctx->r14) {
        // 0x80152C1C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80152C50;
    }
    // 0x80152C1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80152C20: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80152C24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80152C28:
    // 0x80152C28: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80152C2C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80152C30: slti        $at, $v1, 0x2C
    ctx->r1 = SIGNED(ctx->r3) < 0X2C ? 1 : 0;
    // 0x80152C34: mflo        $t7
    ctx->r15 = lo;
    // 0x80152C38: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80152C3C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80152C40: beql        $v0, $t9, L_80152C54
    if (ctx->r2 == ctx->r25) {
        // 0x80152C44: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80152C54;
    }
    goto skip_0;
    // 0x80152C44: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    skip_0:
    // 0x80152C48: bnel        $at, $zero, L_80152C28
    if (ctx->r1 != 0) {
        // 0x80152C4C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80152C28;
    }
    goto skip_1;
    // 0x80152C4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
L_80152C50:
    // 0x80152C50: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80152C54:
    // 0x80152C54: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80152C58: mflo        $t0
    ctx->r8 = lo;
    // 0x80152C5C: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80152C60: jr          $ra
    // 0x80152C64: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    return;
    // 0x80152C64: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152c68(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152c68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152C68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152C6C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152C70: bne         $a0, $zero, L_80152C84
    if (ctx->r4 != 0) {
            // 0x80152C74: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    LOOKUP_FUNC(0x80152C84)(rdram, ctx);
    return;
    }
    // 0x80152C74: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152C78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152C7C: jr          $ra
    // 0x80152C80: lbu         $v0, -0x2377($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2377);
    return;
    // 0x80152C80: lbu         $v0, -0x2377($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2377);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152c84(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152c84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152C84: lbu         $v0, -0x22D9($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X22D9);
    // 0x80152C88: jr          $ra
    // 0x80152C8C: nop

    return;
    // 0x80152C8C: nop

;}
RECOMP_FUNC void M7_FUN_80152c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152C90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152C94: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152C98: bne         $a0, $zero, L_80152CAC
    if (ctx->r4 != 0) {
        // 0x80152C9C: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_80152CAC;
    }
    // 0x80152C9C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80152CA0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80152CA4: b           L_80152CB0
    // 0x80152CA8: lbu         $v1, -0x2284($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2284);
        goto L_80152CB0;
    // 0x80152CA8: lbu         $v1, -0x2284($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2284);
L_80152CAC:
    // 0x80152CAC: lbu         $v1, -0x2283($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2283);
L_80152CB0:
    // 0x80152CB0: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x80152CB4: bne         $at, $zero, L_80152CC0
    if (ctx->r1 != 0) {
        // 0x80152CB8: nop
    
            goto L_80152CC0;
    }
    // 0x80152CB8: nop

    // 0x80152CBC: addiu       $v1, $zero, 0x63
    ctx->r3 = ADD32(0, 0X63);
L_80152CC0:
    // 0x80152CC0: jr          $ra
    // 0x80152CC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80152CC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152cc8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152cc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152CC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152CCC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152CD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80152CD4: bne         $a0, $zero, L_80152CE8
    if (ctx->r4 != 0) {
        // 0x80152CD8: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80152CE8;
    }
    // 0x80152CD8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80152CDC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152CE0: b           L_80152CF0
    // 0x80152CE4: addiu       $v0, $v0, -0x2274
    ctx->r2 = ADD32(ctx->r2, -0X2274);
        goto L_80152CF0;
    // 0x80152CE4: addiu       $v0, $v0, -0x2274
    ctx->r2 = ADD32(ctx->r2, -0X2274);
L_80152CE8:
    // 0x80152CE8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80152CEC: addiu       $v0, $v0, -0x2272
    ctx->r2 = ADD32(ctx->r2, -0X2272);
L_80152CF0:
    // 0x80152CF0: jr          $ra
    // 0x80152CF4: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    return;
    // 0x80152CF4: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152cf8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152cf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152CF8: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80152CFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80152D00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152D04: jr          $ra
    // 0x80152D08: sb          $t6, -0x226E($at)
    MEM_B(-0X226E, ctx->r1) = ctx->r14;
    return;
    // 0x80152D08: sb          $t6, -0x226E($at)
    MEM_B(-0X226E, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152d0c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152d0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152D0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152D10: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80152D14: beq         $a0, $zero, L_80152D2C
    if (ctx->r4 == 0) {
            // 0x80152D18: addiu       $t7, $zero, 0x11C
    ctx->r15 = ADD32(0, 0X11C);
    LOOKUP_FUNC(0x80152D2C)(rdram, ctx);
    return;
    }
    // 0x80152D18: addiu       $t7, $zero, 0x11C
    ctx->r15 = ADD32(0, 0X11C);
    // 0x80152D1C: addiu       $t6, $zero, 0x29
    ctx->r14 = ADD32(0, 0X29);
    // 0x80152D20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80152D24: jr          $ra
    // 0x80152D28: sh          $t6, -0x2274($at)
    MEM_H(-0X2274, ctx->r1) = ctx->r14;
    return;
    // 0x80152D28: sh          $t6, -0x2274($at)
    MEM_H(-0X2274, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152d2c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152d2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152D2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80152D30: sh          $t7, -0x2274($at)
    MEM_H(-0X2274, ctx->r1) = ctx->r15;
    // 0x80152D34: jr          $ra
    // 0x80152D38: nop

    return;
    // 0x80152D38: nop

;}
RECOMP_FUNC void M7_FUN_80152d3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152D3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80152D40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80152D44: jr          $ra
    // 0x80152D48: sb          $a0, -0x226D($at)
    MEM_B(-0X226D, ctx->r1) = ctx->r4;
    return;
    // 0x80152D48: sb          $a0, -0x226D($at)
    MEM_B(-0X226D, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152d4c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152d4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152D4C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80152D50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80152D54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80152D58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80152D5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80152D60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80152D64: jal         0x80152890
    // 0x80152D68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80152890)(rdram, ctx);
        goto after_0;
    // 0x80152D68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80152D6C: addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // 0x80152D70: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x80152D74: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80152D78: beq         $at, $zero, L_80152DB4
    if (ctx->r1 == 0) {
        // 0x80152D7C: andi        $a0, $v1, 0xFF
        ctx->r4 = ctx->r3 & 0XFF;
            goto L_80152DB4;
    }
    // 0x80152D7C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80152D80: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80152D84: addiu       $s0, $s0, -0x2284
    ctx->r16 = ADD32(ctx->r16, -0X2284);
    // 0x80152D88: addiu       $t7, $zero, 0x51
    ctx->r15 = ADD32(0, 0X51);
    // 0x80152D8C: addiu       $t8, $zero, 0x52
    ctx->r24 = ADD32(0, 0X52);
    // 0x80152D90: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80152D94: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
    // 0x80152D98: addiu       $t1, $zero, 0xF9
    ctx->r9 = ADD32(0, 0XF9);
    // 0x80152D9C: sh          $t9, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r25;
    // 0x80152DA0: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x80152DA4: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
    // 0x80152DA8: sh          $t1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r9;
    // 0x80152DAC: b           L_80152F64
    // 0x80152DB0: sh          $t0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r8;
        goto L_80152F64;
    // 0x80152DB0: sh          $t0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r8;
L_80152DB4:
    // 0x80152DB4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80152DB8: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
L_80152DBC:
    // 0x80152DBC: addu        $s0, $s2, $t2
    ctx->r16 = ADD32(ctx->r18, ctx->r10);
    // 0x80152DC0: jal         0x8012C6B4
    // 0x80152DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80152DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80152DC8: addiu       $t3, $v0, 0x2
    ctx->r11 = ADD32(ctx->r2, 0X2);
    // 0x80152DCC: bne         $s2, $zero, L_80152DE4
    if (ctx->r18 != 0) {
        // 0x80152DD0: sb          $t3, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r11;
            goto L_80152DE4;
    }
    // 0x80152DD0: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x80152DD4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152DD8: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152DDC: b           L_80152EB8
    // 0x80152DE0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
        goto L_80152EB8;
    // 0x80152DE0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
L_80152DE4:
    // 0x80152DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80152DE8: bne         $s2, $at, L_80152E10
    if (ctx->r18 != ctx->r1) {
        // 0x80152DEC: or          $a3, $s2, $zero
        ctx->r7 = ctx->r18 | 0;
            goto L_80152E10;
    }
    // 0x80152DEC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80152DF0: lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X41);
    // 0x80152DF4: lbu         $a0, 0x40($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X40);
    // 0x80152DF8: beql        $v1, $a0, L_80152E14
    if (ctx->r3 == ctx->r4) {
        // 0x80152DFC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80152E14;
    }
    goto skip_0;
    // 0x80152DFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80152E00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152E04: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152E08: b           L_80152EB8
    // 0x80152E0C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
        goto L_80152EB8;
    // 0x80152E0C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
L_80152E10:
    // 0x80152E10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80152E14:
    // 0x80152E14: lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X41);
    // 0x80152E18: bne         $a3, $at, L_80152E44
    if (ctx->r7 != ctx->r1) {
        // 0x80152E1C: lbu         $a0, 0x40($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X40);
            goto L_80152E44;
    }
    // 0x80152E1C: lbu         $a0, 0x40($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X40);
    // 0x80152E20: lbu         $a1, 0x42($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X42);
    // 0x80152E24: beql        $a1, $v1, L_80152E48
    if (ctx->r5 == ctx->r3) {
        // 0x80152E28: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80152E48;
    }
    goto skip_1;
    // 0x80152E28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x80152E2C: beql        $a1, $a0, L_80152E48
    if (ctx->r5 == ctx->r4) {
        // 0x80152E30: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80152E48;
    }
    goto skip_2;
    // 0x80152E30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x80152E34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152E38: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152E3C: b           L_80152EB8
    // 0x80152E40: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
        goto L_80152EB8;
    // 0x80152E40: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
L_80152E44:
    // 0x80152E44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80152E48:
    // 0x80152E48: bne         $a3, $at, L_80152E7C
    if (ctx->r7 != ctx->r1) {
        // 0x80152E4C: lbu         $a1, 0x42($sp)
        ctx->r5 = MEM_BU(ctx->r29, 0X42);
            goto L_80152E7C;
    }
    // 0x80152E4C: lbu         $a1, 0x42($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X42);
    // 0x80152E50: lbu         $v0, 0x43($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X43);
    // 0x80152E54: beql        $v0, $a1, L_80152E80
    if (ctx->r2 == ctx->r5) {
        // 0x80152E58: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80152E80;
    }
    goto skip_3;
    // 0x80152E58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_3:
    // 0x80152E5C: beql        $v0, $v1, L_80152E80
    if (ctx->r2 == ctx->r3) {
        // 0x80152E60: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80152E80;
    }
    goto skip_4;
    // 0x80152E60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_4:
    // 0x80152E64: beql        $v0, $a0, L_80152E80
    if (ctx->r2 == ctx->r4) {
        // 0x80152E68: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80152E80;
    }
    goto skip_5;
    // 0x80152E68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_5:
    // 0x80152E6C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152E70: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152E74: b           L_80152EB8
    // 0x80152E78: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
        goto L_80152EB8;
    // 0x80152E78: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
L_80152E7C:
    // 0x80152E7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80152E80:
    // 0x80152E80: bne         $a3, $at, L_80152EB8
    if (ctx->r7 != ctx->r1) {
        // 0x80152E84: lbu         $v0, 0x44($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X44);
            goto L_80152EB8;
    }
    // 0x80152E84: lbu         $v0, 0x44($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X44);
    // 0x80152E88: lbu         $t4, 0x43($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X43);
    // 0x80152E8C: beql        $v0, $t4, L_80152EBC
    if (ctx->r2 == ctx->r12) {
        // 0x80152E90: slti        $at, $a3, 0x5
        ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
            goto L_80152EBC;
    }
    goto skip_6;
    // 0x80152E90: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    skip_6:
    // 0x80152E94: beql        $v0, $a1, L_80152EBC
    if (ctx->r2 == ctx->r5) {
        // 0x80152E98: slti        $at, $a3, 0x5
        ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
            goto L_80152EBC;
    }
    goto skip_7;
    // 0x80152E98: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    skip_7:
    // 0x80152E9C: beql        $v0, $v1, L_80152EBC
    if (ctx->r2 == ctx->r3) {
        // 0x80152EA0: slti        $at, $a3, 0x5
        ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
            goto L_80152EBC;
    }
    goto skip_8;
    // 0x80152EA0: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    skip_8:
    // 0x80152EA4: beql        $v0, $a0, L_80152EBC
    if (ctx->r2 == ctx->r4) {
        // 0x80152EA8: slti        $at, $a3, 0x5
        ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
            goto L_80152EBC;
    }
    goto skip_9;
    // 0x80152EA8: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    skip_9:
    // 0x80152EAC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152EB0: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152EB4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
L_80152EB8:
    // 0x80152EB8: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
L_80152EBC:
    // 0x80152EBC: bnel        $at, $zero, L_80152DBC
    if (ctx->r1 != 0) {
        // 0x80152EC0: addiu       $t2, $sp, 0x40
        ctx->r10 = ADD32(ctx->r29, 0X40);
            goto L_80152DBC;
    }
    goto skip_10;
    // 0x80152EC0: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    skip_10:
    // 0x80152EC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80152EC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80152ECC: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
L_80152ED0:
    // 0x80152ED0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80152ED4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80152ED8:
    // 0x80152ED8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80152EDC: beq         $at, $zero, L_80152F04
    if (ctx->r1 == 0) {
        // 0x80152EE0: addu        $a0, $s1, $v0
        ctx->r4 = ADD32(ctx->r17, ctx->r2);
            goto L_80152F04;
    }
    // 0x80152EE0: addu        $a0, $s1, $v0
    ctx->r4 = ADD32(ctx->r17, ctx->r2);
    // 0x80152EE4: addu        $s0, $s1, $s2
    ctx->r16 = ADD32(ctx->r17, ctx->r18);
    // 0x80152EE8: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x80152EEC: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x80152EF0: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80152EF4: beql        $at, $zero, L_80152F08
    if (ctx->r1 == 0) {
        // 0x80152EF8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80152F08;
    }
    goto skip_11;
    // 0x80152EF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_11:
    // 0x80152EFC: sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // 0x80152F00: sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
L_80152F04:
    // 0x80152F04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80152F08:
    // 0x80152F08: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80152F0C: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80152F10: bne         $at, $zero, L_80152ED8
    if (ctx->r1 != 0) {
        // 0x80152F14: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80152ED8;
    }
    // 0x80152F14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80152F18: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152F1C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152F20: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80152F24: bne         $at, $zero, L_80152ED0
    if (ctx->r1 != 0) {
        // 0x80152F28: or          $a3, $s2, $zero
        ctx->r7 = ctx->r18 | 0;
            goto L_80152ED0;
    }
    // 0x80152F28: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80152F2C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80152F30: addiu       $s0, $s0, -0x2284
    ctx->r16 = ADD32(ctx->r16, -0X2284);
    // 0x80152F34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80152F38:
    // 0x80152F38: addu        $t5, $s1, $s2
    ctx->r13 = ADD32(ctx->r17, ctx->r18);
    // 0x80152F3C: lbu         $a1, 0x0($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X0);
    // 0x80152F40: jal         0x80152980
    // 0x80152F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80152980)(rdram, ctx);
        goto after_2;
    // 0x80152F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80152F48: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x80152F4C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80152F50: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80152F54: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80152F58: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80152F5C: bne         $at, $zero, L_80152F38
    if (ctx->r1 != 0) {
        // 0x80152F60: sh          $v0, 0x18($t7)
        MEM_H(0X18, ctx->r15) = ctx->r2;
            goto L_80152F38;
    }
    // 0x80152F60: sh          $v0, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r2;
L_80152F64:
    // 0x80152F64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80152F68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80152F6C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80152F70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80152F74: jr          $ra
    // 0x80152F78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80152F78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152f7c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152f7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152F7C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80152F80: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80152F84: lbu         $t6, 0x16($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80152f88(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80152f88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152F8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80152F90: bne         $t6, $at, L_80152FE4
    if (ctx->r14 != ctx->r1) {
        // 0x80152F94: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80152FE4;
    }
    // 0x80152F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152F98: jal         0x80152890
    // 0x80152F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80152890)(rdram, ctx);
        goto after_0;
    // 0x80152F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80152FA0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80152FA4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80152FA8: beq         $at, $zero, L_80152FC0
    if (ctx->r1 == 0) {
        // 0x80152FAC: addiu       $v1, $v1, -0x2284
        ctx->r3 = ADD32(ctx->r3, -0X2284);
            goto L_80152FC0;
    }
    // 0x80152FAC: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80152FB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80152FB4: lhu         $t7, 0x3AD0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X3AD0);
    // 0x80152FB8: b           L_80152FF8
    // 0x80152FBC: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
        goto L_80152FF8;
    // 0x80152FBC: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
L_80152FC0:
    // 0x80152FC0: lbu         $a1, 0x22($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X22);
    // 0x80152FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80152FC8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80152FCC: jal         0x80152980
    // 0x80152FD0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80152980)(rdram, ctx);
        goto after_1;
    // 0x80152FD0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x80152FD4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80152FD8: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80152FDC: b           L_80152FF8
    // 0x80152FE0: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
        goto L_80152FF8;
    // 0x80152FE0: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
L_80152FE4:
    // 0x80152FE4: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    // 0x80152FE8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80152FEC: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80152FF0: lhu         $t1, 0x18($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X18);
    // 0x80152FF4: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
L_80152FF8:
    // 0x80152FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153000: jr          $ra
    // 0x80153004: nop

    return;
    // 0x80153004: nop

;}
