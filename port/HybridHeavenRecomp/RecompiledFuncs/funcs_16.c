#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_804c4650(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804C4650u);
    return;
}
RECOMP_FUNC void FUN_804c7044(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804C7044u);
    return;
}
RECOMP_FUNC void FUN_804e0fe0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804E0FE0u);
    return;
}
RECOMP_FUNC void FUN_804e1518(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804E1518u);
    return;
}
RECOMP_FUNC void M7_FUN_80107830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010783C: jal         0x800201D0
    // 0x80107840: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800201D0)(rdram, ctx);
        goto after_0;
    // 0x80107840: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80107844: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80107848: addiu       $a1, $a1, 0x7864
    ctx->r5 = ADD32(ctx->r5, 0X7864);
    // 0x8010784C: jal         0x800058DC
    // 0x80107850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80107850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80107854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010785C: jr          $ra
    // 0x80107860: nop

    return;
    // 0x80107860: nop

;}
RECOMP_FUNC void M7_FUN_80107864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010786C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80107870: jal         0x80016DF0
    // 0x80107874: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80016DF0)(rdram, ctx);
        goto after_0;
    // 0x80107874: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80107878: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8010787C: jal         0x80004310
    // 0x80107880: addiu       $a0, $a0, 0x2DE4
    ctx->r4 = ADD32(ctx->r4, 0X2DE4);
    LOOKUP_FUNC(0x80004310)(rdram, ctx);
        goto after_1;
    // 0x80107880: addiu       $a0, $a0, 0x2DE4
    ctx->r4 = ADD32(ctx->r4, 0X2DE4);
    after_1:
    // 0x80107884: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80107888: addiu       $a1, $a1, 0x78A4
    ctx->r5 = ADD32(ctx->r5, 0X78A4);
    // 0x8010788C: jal         0x800058DC
    // 0x80107890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80107890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80107894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010789C: jr          $ra
    // 0x801078A0: nop

    return;
    // 0x801078A0: nop

;}
RECOMP_FUNC void M7_FUN_801078a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801078A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801078A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801078AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801078B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801078B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801078B8: jal         0x800024D0
    // 0x801078BC: sb          $zero, -0x4A00($at)
    MEM_B(-0X4A00, ctx->r1) = 0;
    LOOKUP_FUNC(0x800024D0)(rdram, ctx);
        goto after_0;
    // 0x801078BC: sb          $zero, -0x4A00($at)
    MEM_B(-0X4A00, ctx->r1) = 0;
    after_0:
    // 0x801078C0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801078C4: addiu       $a1, $a1, 0x78E0
    ctx->r5 = ADD32(ctx->r5, 0X78E0);
    // 0x801078C8: jal         0x800058DC
    // 0x801078CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801078CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801078D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801078D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801078D8: jr          $ra
    // 0x801078DC: nop

    return;
    // 0x801078DC: nop

;}
RECOMP_FUNC void M7_FUN_801078e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801078E0: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801078E4: lhu         $t6, -0x6B8A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B8A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801078e8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801078e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801078E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801078EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801078F0: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x801078F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801078F8: beq         $t7, $zero, L_80107918
    if (ctx->r15 == 0) {
        // 0x801078FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80107918;
    }
    // 0x801078FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80107900: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80107904: addiu       $v1, $v1, -0x4A00
    ctx->r3 = ADD32(ctx->r3, -0X4A00);
    // 0x80107908: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8010790C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107910: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80107914: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_80107918:
    // 0x80107918: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8010791C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80107920: bne         $v0, $at, L_8010794C
    if (ctx->r2 != ctx->r1) {
        // 0x80107924: addiu       $v1, $v1, -0x4A00
        ctx->r3 = ADD32(ctx->r3, -0X4A00);
            goto L_8010794C;
    }
    // 0x80107924: addiu       $v1, $v1, -0x4A00
    ctx->r3 = ADD32(ctx->r3, -0X4A00);
    // 0x80107928: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x8010792C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80107930: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x80107934: bnel        $at, $zero, L_8010795C
    if (ctx->r1 != 0) {
        // 0x80107938: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010795C;
    }
    goto skip_0;
    // 0x80107938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010793C: jal         0x80005624
    // 0x80107940: addiu       $a0, $a0, 0x3504
    ctx->r4 = ADD32(ctx->r4, 0X3504);
    LOOKUP_FUNC(0x80005624)(rdram, ctx);
        goto after_0;
    // 0x80107940: addiu       $a0, $a0, 0x3504
    ctx->r4 = ADD32(ctx->r4, 0X3504);
    after_0:
    // 0x80107944: b           L_8010795C
    // 0x80107948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010795C;
    // 0x80107948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010794C:
    // 0x8010794C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80107950: jal         0x800058DC
    // 0x80107954: addiu       $a1, $a1, 0x7968
    ctx->r5 = ADD32(ctx->r5, 0X7968);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80107954: addiu       $a1, $a1, 0x7968
    ctx->r5 = ADD32(ctx->r5, 0X7968);
    after_1:
    // 0x80107958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010795C:
    // 0x8010795C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107960: jr          $ra
    // 0x80107964: nop

    return;
    // 0x80107964: nop

;}
RECOMP_FUNC void M7_FUN_80107968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010796C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80107970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107974: lui         $a0, 0x3000
    ctx->r4 = S32(0X3000 << 16);
    // 0x80107978: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010797C: jal         0x800058B8
    // 0x80107980: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    LOOKUP_FUNC(0x800058B8)(rdram, ctx);
        goto after_0;
    // 0x80107980: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    after_0:
    // 0x80107984: bne         $v0, $zero, L_80107998
    if (ctx->r2 != 0) {
        // 0x80107988: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80107998;
    }
    // 0x80107988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010798C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80107990: jal         0x800057DC
    // 0x80107994: addiu       $a1, $a1, 0x2FC0
    ctx->r5 = ADD32(ctx->r5, 0X2FC0);
    LOOKUP_FUNC(0x800057DC)(rdram, ctx);
        goto after_1;
    // 0x80107994: addiu       $a1, $a1, 0x2FC0
    ctx->r5 = ADD32(ctx->r5, 0X2FC0);
    after_1:
L_80107998:
    // 0x80107998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010799C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801079A0: jr          $ra
    // 0x801079A4: nop

    return;
    // 0x801079A4: nop

;}
RECOMP_FUNC void M7_FUN_801079a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801079A8: nop

    // 0x801079AC: nop

;}
RECOMP_FUNC void M7_FUN_801079b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801079B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801079B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801079B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801079BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801079C0: jal         0x80020744
    // 0x801079C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x801079C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801079C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801079CC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801079D0: addiu       $a0, $a0, -0xE60
    ctx->r4 = ADD32(ctx->r4, -0XE60);
    // 0x801079D4: addiu       $t6, $t6, -0x800
    ctx->r14 = ADD32(ctx->r14, -0X800);
    // 0x801079D8: jal         0x8001F204
    // 0x801079DC: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(0x8001F204)(rdram, ctx);
        goto after_1;
    // 0x801079DC: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    after_1:
    // 0x801079E0: jal         0x80016DF0
    // 0x801079E4: nop

    LOOKUP_FUNC(0x80016DF0)(rdram, ctx);
        goto after_2;
    // 0x801079E4: nop

    after_2:
    // 0x801079E8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801079EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801079F0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801079F4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801079F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801079FC: jal         0x80005444
    // 0x80107A00: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x80005444)(rdram, ctx);
        goto after_3;
    // 0x80107A00: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_3:
    // 0x80107A04: jal         0x80016E40
    // 0x80107A08: ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
    LOOKUP_FUNC(0x80016E40)(rdram, ctx);
        goto after_4;
    // 0x80107A08: ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
    after_4:
    // 0x80107A0C: jal         0x80004484
    // 0x80107A10: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    LOOKUP_FUNC(0x80004484)(rdram, ctx);
        goto after_5;
    // 0x80107A10: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_5:
    // 0x80107A14: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80107A18: jal         0x80005624
    // 0x80107A1C: addiu       $a0, $a0, -0x237C
    ctx->r4 = ADD32(ctx->r4, -0X237C);
    LOOKUP_FUNC(0x80005624)(rdram, ctx);
        goto after_6;
    // 0x80107A1C: addiu       $a0, $a0, -0x237C
    ctx->r4 = ADD32(ctx->r4, -0X237C);
    after_6:
    // 0x80107A20: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80107A24: jal         0x80005624
    // 0x80107A28: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    LOOKUP_FUNC(0x80005624)(rdram, ctx);
        goto after_7;
    // 0x80107A28: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    after_7:
    // 0x80107A2C: jal         0x80133AAC
    // 0x80107A30: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    LOOKUP_FUNC(0x80133AAC)(rdram, ctx);
        goto after_8;
    // 0x80107A30: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_8:
    // 0x80107A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107A3C: jr          $ra
    // 0x80107A40: nop

    return;
    // 0x80107A40: nop

;}
RECOMP_FUNC void M7_FUN_80107a44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107A44: nop

    // 0x80107A48: nop

    // 0x80107A4C: nop

;}
RECOMP_FUNC void M7_FUN_80107a50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107A50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80107A58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80107A5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80107A60: jal         0x80020744
    // 0x80107A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80107A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80107A68: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80107A6C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80107A70: addiu       $a0, $a0, -0xE60
    ctx->r4 = ADD32(ctx->r4, -0XE60);
    // 0x80107A74: addiu       $t6, $t6, -0x800
    ctx->r14 = ADD32(ctx->r14, -0X800);
    // 0x80107A78: jal         0x8001F204
    // 0x80107A7C: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(0x8001F204)(rdram, ctx);
        goto after_1;
    // 0x80107A7C: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    after_1:
    // 0x80107A80: jal         0x80016DF0
    // 0x80107A84: nop

    LOOKUP_FUNC(0x80016DF0)(rdram, ctx);
        goto after_2;
    // 0x80107A84: nop

    after_2:
    // 0x80107A88: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x80107A8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80107A90: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80107A94: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x80107A98: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80107A9C: jal         0x80005444
    // 0x80107AA0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x80005444)(rdram, ctx);
        goto after_3;
    // 0x80107AA0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_3:
    // 0x80107AA4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80107AA8: jal         0x80005624
    // 0x80107AAC: addiu       $a0, $a0, 0x3518
    ctx->r4 = ADD32(ctx->r4, 0X3518);
    LOOKUP_FUNC(0x80005624)(rdram, ctx);
        goto after_4;
    // 0x80107AAC: addiu       $a0, $a0, 0x3518
    ctx->r4 = ADD32(ctx->r4, 0X3518);
    after_4:
    // 0x80107AB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107AB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107AB8: jr          $ra
    // 0x80107ABC: nop

    return;
    // 0x80107ABC: nop

;}
RECOMP_FUNC void M7_FUN_80107ac0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107AC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80107AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107ACC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80107AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80107AD4: jal         0x80005670
    // 0x80107AD8: addiu       $a1, $a1, 0x4420
    ctx->r5 = ADD32(ctx->r5, 0X4420);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x80107AD8: addiu       $a1, $a1, 0x4420
    ctx->r5 = ADD32(ctx->r5, 0X4420);
    after_0:
    // 0x80107ADC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80107AE0: addiu       $a1, $a1, 0x4220
    ctx->r5 = ADD32(ctx->r5, 0X4220);
    // 0x80107AE4: jal         0x80005670
    // 0x80107AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x80107AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80107AEC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80107AF0: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    // 0x80107AF4: jal         0x80005670
    // 0x80107AF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x80107AF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80107AFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107B00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80107B04: sb          $v0, -0x453C($at)
    MEM_B(-0X453C, ctx->r1) = ctx->r2;
    // 0x80107B08: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80107B0C: sb          $v0, -0x453B($at)
    MEM_B(-0X453B, ctx->r1) = ctx->r2;
    // 0x80107B10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80107B14: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
    // 0x80107B18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80107B1C: sb          $zero, -0x4539($at)
    MEM_B(-0X4539, ctx->r1) = 0;
    // 0x80107B20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80107B24: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x80107B28: sb          $zero, -0x4538($at)
    MEM_B(-0X4538, ctx->r1) = 0;
    // 0x80107B2C: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x80107B30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80107B34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80107B38: jal         0x80002364
    // 0x80107B3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_3;
    // 0x80107B3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80107B40: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80107B44: addiu       $a1, $a1, 0x7B60
    ctx->r5 = ADD32(ctx->r5, 0X7B60);
    // 0x80107B48: jal         0x800058DC
    // 0x80107B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80107B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80107B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107B58: jr          $ra
    // 0x80107B5C: nop

    return;
    // 0x80107B5C: nop

;}
RECOMP_FUNC void M7_FUN_80107b60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107B60: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80107B64: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80107B68: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80107B6C: lhu         $t6, 0x1C8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1C8);
    // 0x80107B70: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80107B74: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80107B78: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x80107B7C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80107B80: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80107B84: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80107B88: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80107B8C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80107B90: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80107B94: beq         $t7, $zero, L_80107C40
    if (ctx->r15 == 0) {
        // 0x80107B98: sw          $a1, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r5;
            goto L_80107C40;
    }
    // 0x80107B98: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80107B9C: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80107BA0: addiu       $s3, $s3, -0x453B
    ctx->r19 = ADD32(ctx->r19, -0X453B);
    // 0x80107BA4: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x80107BA8: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80107BAC: addiu       $s1, $s1, -0x453C
    ctx->r17 = ADD32(ctx->r17, -0X453C);
    // 0x80107BB0: bnel        $t8, $zero, L_80107C44
    if (ctx->r24 != 0) {
        // 0x80107BB4: lhu         $v0, 0x1D0($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X1D0);
            goto L_80107C44;
    }
    goto skip_0;
    // 0x80107BB4: lhu         $v0, 0x1D0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1D0);
    skip_0:
    // 0x80107BB8: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80107BBC: bne         $t9, $zero, L_80107C40
    if (ctx->r25 != 0) {
        // 0x80107BC0: lui         $s2, 0x801C
        ctx->r18 = S32(0X801C << 16);
            goto L_80107C40;
    }
    // 0x80107BC0: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80107BC4: addiu       $s2, $s2, -0x4539
    ctx->r18 = ADD32(ctx->r18, -0X4539);
    // 0x80107BC8: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x80107BCC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80107BD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80107BD4: bne         $t0, $zero, L_80107C30
    if (ctx->r8 != 0) {
        // 0x80107BD8: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_80107C30;
    }
    // 0x80107BD8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80107BDC: addiu       $s0, $s0, -0x49F0
    ctx->r16 = ADD32(ctx->r16, -0X49F0);
    // 0x80107BE0: lbu         $t1, 0x200($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X200);
    // 0x80107BE4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80107BE8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80107BEC: bne         $t1, $zero, L_801081C0
    if (ctx->r9 != 0) {
        // 0x80107BF0: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_801081C0;
    }
    // 0x80107BF0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80107BF4: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x80107BF8: sb          $s0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r16;
    // 0x80107BFC: sh          $zero, 0x352($v0)
    MEM_H(0X352, ctx->r2) = 0;
    // 0x80107C00: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80107C04: lbu         $t2, -0x453A($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X453A);
    // 0x80107C08: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80107C0C: addiu       $a0, $a0, 0x3390
    ctx->r4 = ADD32(ctx->r4, 0X3390);
    // 0x80107C10: jal         0x80017990
    // 0x80107C14: sh          $t2, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r10;
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_0;
    // 0x80107C14: sh          $t2, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r10;
    after_0:
    // 0x80107C18: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80107C1C: addiu       $a1, $a1, -0x7E08
    ctx->r5 = ADD32(ctx->r5, -0X7E08);
    // 0x80107C20: jal         0x800058DC
    // 0x80107C24: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80107C24: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80107C28: b           L_801081C0
    // 0x80107C2C: nop

        goto L_801081C0;
    // 0x80107C2C: nop

L_80107C30:
    // 0x80107C30: jal         0x800058DC
    // 0x80107C34: addiu       $a1, $a1, -0x7DBC
    ctx->r5 = ADD32(ctx->r5, -0X7DBC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80107C34: addiu       $a1, $a1, -0x7DBC
    ctx->r5 = ADD32(ctx->r5, -0X7DBC);
    after_2:
    // 0x80107C38: b           L_801081C0
    // 0x80107C3C: nop

        goto L_801081C0;
    // 0x80107C3C: nop

L_80107C40:
    // 0x80107C40: lhu         $v0, 0x1D0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1D0);
L_80107C44:
    // 0x80107C44: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80107C48: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80107C4C: andi        $t3, $v0, 0x200
    ctx->r11 = ctx->r2 & 0X200;
    // 0x80107C50: addiu       $s3, $s3, -0x453B
    ctx->r19 = ADD32(ctx->r19, -0X453B);
    // 0x80107C54: beq         $t3, $zero, L_80107C80
    if (ctx->r11 == 0) {
        // 0x80107C58: addiu       $s1, $s1, -0x453C
        ctx->r17 = ADD32(ctx->r17, -0X453C);
            goto L_80107C80;
    }
    // 0x80107C58: addiu       $s1, $s1, -0x453C
    ctx->r17 = ADD32(ctx->r17, -0X453C);
    // 0x80107C5C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80107C60: addiu       $s2, $s2, -0x4539
    ctx->r18 = ADD32(ctx->r18, -0X4539);
    // 0x80107C64: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x80107C68: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80107C6C: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x80107C70: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80107C74: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    // 0x80107C78: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80107C7C: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_80107C80:
    // 0x80107C80: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80107C84: andi        $t8, $v0, 0x100
    ctx->r24 = ctx->r2 & 0X100;
    // 0x80107C88: addiu       $s2, $s2, -0x4539
    ctx->r18 = ADD32(ctx->r18, -0X4539);
    // 0x80107C8C: beq         $t8, $zero, L_80107CAC
    if (ctx->r24 == 0) {
        // 0x80107C90: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80107CAC;
    }
    // 0x80107C90: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80107C94: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80107C98: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x80107C9C: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x80107CA0: sb          $t1, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r9;
    // 0x80107CA4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80107CA8: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
L_80107CAC:
    // 0x80107CAC: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x80107CB0: beq         $t3, $zero, L_80107CD8
    if (ctx->r11 == 0) {
        // 0x80107CB4: andi        $t8, $v0, 0x400
        ctx->r24 = ctx->r2 & 0X400;
            goto L_80107CD8;
    }
    // 0x80107CB4: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x80107CB8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80107CBC: addiu       $v1, $v1, -0x453A
    ctx->r3 = ADD32(ctx->r3, -0X453A);
    // 0x80107CC0: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80107CC4: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x80107CC8: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80107CCC: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80107CD0: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80107CD4: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80107CD8:
    // 0x80107CD8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80107CDC: beq         $t8, $zero, L_80107CFC
    if (ctx->r24 == 0) {
        // 0x80107CE0: addiu       $v1, $v1, -0x453A
        ctx->r3 = ADD32(ctx->r3, -0X453A);
            goto L_80107CFC;
    }
    // 0x80107CE0: addiu       $v1, $v1, -0x453A
    ctx->r3 = ADD32(ctx->r3, -0X453A);
    // 0x80107CE4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80107CE8: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x80107CEC: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80107CF0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80107CF4: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80107CF8: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
L_80107CFC:
    // 0x80107CFC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80107D00: lbu         $t3, -0x4538($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X4538);
    // 0x80107D04: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x80107D08: bnel        $t4, $zero, L_80107D3C
    if (ctx->r12 != 0) {
        // 0x80107D0C: lbu         $t5, 0x0($s3)
        ctx->r13 = MEM_BU(ctx->r19, 0X0);
            goto L_80107D3C;
    }
    goto skip_1;
    // 0x80107D0C: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    skip_1:
    // 0x80107D10: jal         0x80002BE0
    // 0x80107D14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_3;
    // 0x80107D14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80107D18: beq         $v0, $zero, L_80107D38
    if (ctx->r2 == 0) {
        // 0x80107D1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80107D38;
    }
    // 0x80107D1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80107D20: bnel        $v0, $at, L_80107D34
    if (ctx->r2 != ctx->r1) {
        // 0x80107D24: sb          $s0, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r16;
            goto L_80107D34;
    }
    goto skip_2;
    // 0x80107D24: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    skip_2:
    // 0x80107D28: jal         0x80002BE0
    // 0x80107D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_4;
    // 0x80107D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80107D30: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
L_80107D34:
    // 0x80107D34: sb          $s0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r16;
L_80107D38:
    // 0x80107D38: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
L_80107D3C:
    // 0x80107D3C: beql        $t5, $zero, L_80107D78
    if (ctx->r13 == 0) {
        // 0x80107D40: lbu         $t6, 0x0($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X0);
            goto L_80107D78;
    }
    goto skip_3;
    // 0x80107D40: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    skip_3:
    // 0x80107D44: jal         0x80002BE0
    // 0x80107D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_5;
    // 0x80107D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80107D4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80107D50: bne         $v0, $at, L_80107D60
    if (ctx->r2 != ctx->r1) {
        // 0x80107D54: nop
    
            goto L_80107D60;
    }
    // 0x80107D54: nop

    // 0x80107D58: jal         0x80002BE0
    // 0x80107D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_6;
    // 0x80107D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
L_80107D60:
    // 0x80107D60: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80107D64: addiu       $a1, $s0, -0x49F0
    ctx->r5 = ADD32(ctx->r16, -0X49F0);
    // 0x80107D68: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x80107D6C: jal         0x800035C4
    // 0x80107D70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800035C4)(rdram, ctx);
        goto after_7;
    // 0x80107D70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80107D74: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
L_80107D78:
    // 0x80107D78: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80107D7C: addiu       $s0, $s0, -0x49F0
    ctx->r16 = ADD32(ctx->r16, -0X49F0);
    // 0x80107D80: beq         $t6, $zero, L_801081C0
    if (ctx->r14 == 0) {
        // 0x80107D84: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801081C0;
    }
    // 0x80107D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80107D88: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80107D8C: addiu       $t7, $zero, 0xF8
    ctx->r15 = ADD32(0, 0XF8);
    // 0x80107D90: addiu       $t8, $zero, 0xA6
    ctx->r24 = ADD32(0, 0XA6);
    // 0x80107D94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80107D98: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80107D9C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80107DA0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80107DA4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80107DA8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80107DAC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80107DB0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80107DB4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80107DB8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80107DBC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80107DC0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80107DC4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80107DC8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80107DCC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80107DD0: addiu       $a1, $a1, 0x5620
    ctx->r5 = ADD32(ctx->r5, 0X5620);
    // 0x80107DD4: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x80107DD8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80107DDC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80107DE0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80107DE4: jal         0x8001A804
    // 0x80107DE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_8;
    // 0x80107DE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_8:
    // 0x80107DEC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107DF0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80107DF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80107DF8: addiu       $a3, $a3, 0x5648
    ctx->r7 = ADD32(ctx->r7, 0X5648);
    // 0x80107DFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80107E00: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80107E04: jal         0x8001B204
    // 0x80107E08: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x80107E08: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_9:
    // 0x80107E0C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80107E10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80107E14: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80107E18: bne         $t6, $zero, L_80107E5C
    if (ctx->r14 != 0) {
        // 0x80107E1C: addiu       $a2, $zero, 0x23
        ctx->r6 = ADD32(0, 0X23);
            goto L_80107E5C;
    }
    // 0x80107E1C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80107E20: lbu         $t9, 0x201($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X201);
    // 0x80107E24: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107E28: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80107E2C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80107E30: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80107E34: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80107E38: addiu       $a3, $a3, 0x5674
    ctx->r7 = ADD32(ctx->r7, 0X5674);
    // 0x80107E3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80107E40: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80107E44: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80107E48: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80107E4C: jal         0x8001B204
    // 0x80107E50: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x80107E50: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_10:
    // 0x80107E54: b           L_80107E88
    // 0x80107E58: lbu         $t3, 0x200($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X200);
        goto L_80107E88;
    // 0x80107E58: lbu         $t3, 0x200($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X200);
L_80107E5C:
    // 0x80107E5C: lbu         $t2, 0x201($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X201);
    // 0x80107E60: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107E64: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80107E68: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80107E6C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80107E70: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80107E74: addiu       $a3, $a3, 0x56B8
    ctx->r7 = ADD32(ctx->r7, 0X56B8);
    // 0x80107E78: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80107E7C: jal         0x8001B204
    // 0x80107E80: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x80107E80: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_11:
    // 0x80107E84: lbu         $t3, 0x200($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X200);
L_80107E88:
    // 0x80107E88: sltiu       $at, $t3, 0x10
    ctx->r1 = ctx->r11 < 0X10 ? 1 : 0;
    // 0x80107E8C: beq         $at, $zero, L_801081C0
    if (ctx->r1 == 0) {
        // 0x80107E90: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_801081C0;
    }
    // 0x80107E90: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80107E94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80107E98: addu        $at, $at, $t3
    gpr jr_addend_80107EA0 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80107E9C: lw          $t3, 0x57FC($at)
    ctx->r11 = ADD32(ctx->r1, 0X57FC);
    // 0x80107EA0: jr          $t3
    // 0x80107EA4: nop

    switch (jr_addend_80107EA0 >> 2) {
        case 0: goto L_80107EA8; break;
        case 1: goto L_80107FB8; break;
        case 2: goto L_801081C0; break;
        case 3: goto L_80108018; break;
        case 4: goto L_80108150; break;
        case 5: goto L_80108150; break;
        case 6: goto L_801081C0; break;
        case 7: goto L_80108090; break;
        case 8: goto L_801081C0; break;
        case 9: goto L_801081C0; break;
        case 10: goto L_801081C0; break;
        case 11: goto L_801081C0; break;
        case 12: goto L_801081C0; break;
        case 13: goto L_801081C0; break;
        case 14: goto L_801081C0; break;
        case 15: goto L_801080F0; break;
        default: switch_error(__func__, 0x80107EA0, 0x801857FC);
    }
    // 0x80107EA4: nop

L_80107EA8:
    // 0x80107EA8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107EAC: addiu       $a3, $a3, 0x56FC
    ctx->r7 = ADD32(ctx->r7, 0X56FC);
    // 0x80107EB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80107EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80107EB8: jal         0x8001B204
    // 0x80107EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x80107EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80107EC0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80107EC4: addiu       $s4, $t4, -0x49F0
    ctx->r20 = ADD32(ctx->r12, -0X49F0);
    // 0x80107EC8: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80107ECC: addiu       $s3, $s3, -0x47EE
    ctx->r19 = ADD32(ctx->r19, -0X47EE);
    // 0x80107ED0: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80107ED4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80107ED8: addiu       $s2, $zero, 0x32
    ctx->r18 = ADD32(0, 0X32);
    // 0x80107EDC: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
L_80107EE0:
    // 0x80107EE0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80107EE4: lbu         $t7, -0x453A($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X453A);
    // 0x80107EE8: lbu         $t5, 0x412($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X412);
    // 0x80107EEC: lbu         $t6, 0x413($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X413);
    // 0x80107EF0: sb          $zero, 0x7A($sp)
    MEM_B(0X7A, ctx->r29) = 0;
    // 0x80107EF4: sb          $t5, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r13;
    // 0x80107EF8: bne         $s0, $t7, L_80107F4C
    if (ctx->r16 != ctx->r15) {
        // 0x80107EFC: sb          $t6, 0x79($sp)
        MEM_B(0X79, ctx->r29) = ctx->r14;
            goto L_80107F4C;
    }
    // 0x80107EFC: sb          $t6, 0x79($sp)
    MEM_B(0X79, ctx->r29) = ctx->r14;
    // 0x80107F00: lbu         $t9, 0x4A2($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X4A2);
    // 0x80107F04: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80107F08: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x80107F0C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107F10: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x80107F14: addiu       $t8, $sp, 0x78
    ctx->r24 = ADD32(ctx->r29, 0X78);
    // 0x80107F18: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80107F1C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80107F20: addiu       $a3, $a3, 0x5700
    ctx->r7 = ADD32(ctx->r7, 0X5700);
    // 0x80107F24: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80107F28: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80107F2C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80107F30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80107F34: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x80107F38: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x80107F3C: jal         0x8001B204
    // 0x80107F40: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x80107F40: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_13:
    // 0x80107F44: b           L_80107F98
    // 0x80107F48: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
        goto L_80107F98;
    // 0x80107F48: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
L_80107F4C:
    // 0x80107F4C: lbu         $t2, 0x4A2($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X4A2);
    // 0x80107F50: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80107F54: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x80107F58: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107F5C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80107F60: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x80107F64: addiu       $t1, $sp, 0x78
    ctx->r9 = ADD32(ctx->r29, 0X78);
    // 0x80107F68: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80107F6C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80107F70: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80107F74: addiu       $a3, $a3, 0x571C
    ctx->r7 = ADD32(ctx->r7, 0X571C);
    // 0x80107F78: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80107F7C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80107F80: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80107F84: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x80107F88: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x80107F8C: jal         0x8001B204
    // 0x80107F90: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x80107F90: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_14:
    // 0x80107F94: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
L_80107F98:
    // 0x80107F98: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80107F9C: addiu       $v1, $v1, 0x9
    ctx->r3 = ADD32(ctx->r3, 0X9);
    // 0x80107FA0: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x80107FA4: addiu       $s3, $s3, 0x21
    ctx->r19 = ADD32(ctx->r19, 0X21);
    // 0x80107FA8: bne         $s1, $s5, L_80107EE0
    if (ctx->r17 != ctx->r21) {
        // 0x80107FAC: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80107EE0;
    }
    // 0x80107FAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80107FB0: b           L_801081C0
    // 0x80107FB4: nop

        goto L_801081C0;
    // 0x80107FB4: nop

L_80107FB8:
    // 0x80107FB8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80107FBC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80107FC0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80107FC4: addiu       $a3, $a3, 0x5738
    ctx->r7 = ADD32(ctx->r7, 0X5738);
    // 0x80107FC8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80107FCC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80107FD0: jal         0x8001B204
    // 0x80107FD4: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x80107FD4: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_15:
    // 0x80107FD8: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80107FDC: addiu       $s1, $s1, 0x577C
    ctx->r17 = ADD32(ctx->r17, 0X577C);
    // 0x80107FE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80107FE4: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80107FE8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80107FEC:
    // 0x80107FEC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80107FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80107FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80107FF8: jal         0x8001B204
    // 0x80107FFC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_16;
    // 0x80107FFC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_16:
    // 0x80108000: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80108004: bnel        $s0, $s5, L_80107FEC
    if (ctx->r16 != ctx->r21) {
        // 0x80108008: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80107FEC;
    }
    goto skip_4;
    // 0x80108008: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_4:
    // 0x8010800C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108010: b           L_801081C0
    // 0x80108014: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
        goto L_801081C0;
    // 0x80108014: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
L_80108018:
    // 0x80108018: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8010801C: addiu       $a3, $a3, 0x5780
    ctx->r7 = ADD32(ctx->r7, 0X5780);
    // 0x80108020: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80108024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108028: jal         0x8001B204
    // 0x8010802C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_17;
    // 0x8010802C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80108030: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80108034: addiu       $s1, $s1, 0x5784
    ctx->r17 = ADD32(ctx->r17, 0X5784);
    // 0x80108038: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010803C: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80108040: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80108044:
    // 0x80108044: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80108048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010804C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80108050: jal         0x8001B204
    // 0x80108054: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_18;
    // 0x80108054: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_18:
    // 0x80108058: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010805C: bnel        $s0, $s5, L_80108044
    if (ctx->r16 != ctx->r21) {
        // 0x80108060: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80108044;
    }
    goto skip_5;
    // 0x80108060: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_5:
    // 0x80108064: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108068: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8010806C: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
    // 0x80108070: jal         0x80017990
    // 0x80108074: addiu       $a0, $a0, 0x3004
    ctx->r4 = ADD32(ctx->r4, 0X3004);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_19;
    // 0x80108074: addiu       $a0, $a0, 0x3004
    ctx->r4 = ADD32(ctx->r4, 0X3004);
    after_19:
    // 0x80108078: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010807C: addiu       $a1, $a1, -0x7E08
    ctx->r5 = ADD32(ctx->r5, -0X7E08);
    // 0x80108080: jal         0x800058DC
    // 0x80108084: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_20;
    // 0x80108084: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_20:
    // 0x80108088: b           L_801081C0
    // 0x8010808C: nop

        goto L_801081C0;
    // 0x8010808C: nop

L_80108090:
    // 0x80108090: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80108094: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80108098: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8010809C: addiu       $a3, $a3, 0x5788
    ctx->r7 = ADD32(ctx->r7, 0X5788);
    // 0x801080A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801080A4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801080A8: jal         0x8001B204
    // 0x801080AC: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_21;
    // 0x801080AC: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_21:
    // 0x801080B0: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x801080B4: addiu       $s1, $s1, 0x57BC
    ctx->r17 = ADD32(ctx->r17, 0X57BC);
    // 0x801080B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801080BC: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x801080C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_801080C4:
    // 0x801080C4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801080C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801080CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801080D0: jal         0x8001B204
    // 0x801080D4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_22;
    // 0x801080D4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x801080D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801080DC: bnel        $s0, $s5, L_801080C4
    if (ctx->r16 != ctx->r21) {
        // 0x801080E0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_801080C4;
    }
    goto skip_6;
    // 0x801080E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_6:
    // 0x801080E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801080E8: b           L_801081C0
    // 0x801080EC: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
        goto L_801081C0;
    // 0x801080EC: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
L_801080F0:
    // 0x801080F0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801080F4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801080F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801080FC: addiu       $a3, $a3, 0x57C0
    ctx->r7 = ADD32(ctx->r7, 0X57C0);
    // 0x80108100: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80108104: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80108108: jal         0x8001B204
    // 0x8010810C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_23;
    // 0x8010810C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_23:
    // 0x80108110: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80108114: addiu       $s1, $s1, 0x57F0
    ctx->r17 = ADD32(ctx->r17, 0X57F0);
    // 0x80108118: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010811C: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80108120: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80108124:
    // 0x80108124: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80108128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010812C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80108130: jal         0x8001B204
    // 0x80108134: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_24;
    // 0x80108134: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_24:
    // 0x80108138: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010813C: bnel        $s0, $s5, L_80108124
    if (ctx->r16 != ctx->r21) {
        // 0x80108140: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80108124;
    }
    goto skip_7;
    // 0x80108140: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_7:
    // 0x80108144: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108148: b           L_801081C0
    // 0x8010814C: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
        goto L_801081C0;
    // 0x8010814C: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
L_80108150:
    // 0x80108150: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80108154: addiu       $a3, $a3, 0x57F4
    ctx->r7 = ADD32(ctx->r7, 0X57F4);
    // 0x80108158: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8010815C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108160: jal         0x8001B204
    // 0x80108164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_25;
    // 0x80108164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80108168: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x8010816C: addiu       $s1, $s1, 0x57F8
    ctx->r17 = ADD32(ctx->r17, 0X57F8);
    // 0x80108170: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80108174: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80108178: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_8010817C:
    // 0x8010817C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80108180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80108188: jal         0x8001B204
    // 0x8010818C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_26;
    // 0x8010818C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_26:
    // 0x80108190: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80108194: bnel        $s0, $s5, L_8010817C
    if (ctx->r16 != ctx->r21) {
        // 0x80108198: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8010817C;
    }
    goto skip_8;
    // 0x80108198: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_8:
    // 0x8010819C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801081A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801081A4: sb          $zero, -0x453A($at)
    MEM_B(-0X453A, ctx->r1) = 0;
    // 0x801081A8: jal         0x80017990
    // 0x801081AC: addiu       $a0, $a0, 0x30D0
    ctx->r4 = ADD32(ctx->r4, 0X30D0);
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_27;
    // 0x801081AC: addiu       $a0, $a0, 0x30D0
    ctx->r4 = ADD32(ctx->r4, 0X30D0);
    after_27:
    // 0x801081B0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801081B4: addiu       $a1, $a1, -0x7E08
    ctx->r5 = ADD32(ctx->r5, -0X7E08);
    // 0x801081B8: jal         0x800058DC
    // 0x801081BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_28;
    // 0x801081BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_28:
L_801081C0:
    // 0x801081C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801081C4: addiu       $v0, $v0, -0x4538
    ctx->r2 = ADD32(ctx->r2, -0X4538);
    // 0x801081C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801081CC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801081D0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801081D4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801081D8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801081DC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801081E0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801081E4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801081E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801081EC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x801081F0: jr          $ra
    // 0x801081F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801081F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801081f8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801081f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801081F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801081FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80108204: jal         0x800178E8
    // 0x80108208: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80108208: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010820C: beq         $v0, $zero, L_80108234
    if (ctx->r2 == 0) {
        // 0x80108210: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80108234;
    }
    // 0x80108210: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108218: sb          $v0, -0x453C($at)
    MEM_B(-0X453C, ctx->r1) = ctx->r2;
    // 0x8010821C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108220: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80108224: sb          $v0, -0x453B($at)
    MEM_B(-0X453B, ctx->r1) = ctx->r2;
    // 0x80108228: addiu       $a1, $a1, 0x7B60
    ctx->r5 = ADD32(ctx->r5, 0X7B60);
    // 0x8010822C: jal         0x800058DC
    // 0x80108230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80108230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80108234:
    // 0x80108234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010823C: jr          $ra
    // 0x80108240: nop

    return;
    // 0x80108240: nop

;}
RECOMP_FUNC void M7_FUN_80108244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010824C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80108250: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80108254: jal         0x800023A8
    // 0x80108258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_0;
    // 0x80108258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8010825C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80108260: addiu       $a1, $a1, 0x2FC0
    ctx->r5 = ADD32(ctx->r5, 0X2FC0);
    // 0x80108264: jal         0x800057DC
    // 0x80108268: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800057DC)(rdram, ctx);
        goto after_1;
    // 0x80108268: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8010826C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108274: jr          $ra
    // 0x80108278: nop

    return;
    // 0x80108278: nop

;}
RECOMP_FUNC void M7_FUN_8010827c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010827C: nop

;}
RECOMP_FUNC void M7_FUN_80108280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108280: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80108284: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80108288: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8010828C: addiu       $s5, $s5, -0x4410
    ctx->r21 = ADD32(ctx->r21, -0X4410);
    // 0x80108290: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80108294: lw          $t6, 0x50($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X50);
    // 0x80108298: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8010829C: addiu       $s4, $s4, -0x4530
    ctx->r20 = ADD32(ctx->r20, -0X4530);
    // 0x801082A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801082A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801082A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801082AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801082B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801082B4: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x801082B8: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x801082BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801082C0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x801082C4: beq         $s0, $zero, L_80108394
    if (ctx->r16 == 0) {
        // 0x801082C8: addiu       $s3, $zero, 0xFD
        ctx->r19 = ADD32(0, 0XFD);
            goto L_80108394;
    }
    // 0x801082C8: addiu       $s3, $zero, 0xFD
    ctx->r19 = ADD32(0, 0XFD);
    // 0x801082CC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
L_801082D0:
    // 0x801082D0: beql        $t7, $zero, L_8010838C
    if (ctx->r15 == 0) {
        // 0x801082D4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8010838C;
    }
    goto skip_0;
    // 0x801082D4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x801082D8: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x801082DC: beql        $v1, $zero, L_8010838C
    if (ctx->r3 == 0) {
        // 0x801082E0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8010838C;
    }
    goto skip_1;
    // 0x801082E0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x801082E4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x801082E8: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x801082EC: beql        $t9, $zero, L_8010838C
    if (ctx->r25 == 0) {
        // 0x801082F0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8010838C;
    }
    goto skip_2;
    // 0x801082F0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x801082F4: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x801082F8: bnel        $s3, $t0, L_8010838C
    if (ctx->r19 != ctx->r8) {
        // 0x801082FC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8010838C;
    }
    goto skip_3;
    // 0x801082FC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80108300: jal         0x8012FF58
    // 0x80108304: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    LOOKUP_FUNC(0x8012FF58)(rdram, ctx);
        goto after_0;
    // 0x80108304: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    after_0:
    // 0x80108308: jal         0x8012FF58
    // 0x8010830C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8012FF58)(rdram, ctx);
        goto after_1;
    // 0x8010830C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x80108310: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x80108314: mfhi        $t1
    ctx->r9 = hi;
    // 0x80108318: lhu         $t4, 0x4($s5)
    ctx->r12 = MEM_HU(ctx->r21, 0X4);
    // 0x8010831C: bne         $s2, $zero, L_80108328
    if (ctx->r18 != 0) {
        // 0x80108320: nop
    
            goto L_80108328;
    }
    // 0x80108320: nop

    // 0x80108324: break       7
    do_break(2148565796);
L_80108328:
    // 0x80108328: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010832C: bne         $s2, $at, L_80108340
    if (ctx->r18 != ctx->r1) {
        // 0x80108330: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80108340;
    }
    // 0x80108330: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80108334: bne         $v0, $at, L_80108340
    if (ctx->r2 != ctx->r1) {
        // 0x80108338: nop
    
            goto L_80108340;
    }
    // 0x80108338: nop

    // 0x8010833C: break       6
    do_break(2148565820);
L_80108340:
    // 0x80108340: div         $zero, $s1, $s2
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r18)));
    // 0x80108344: bne         $s2, $zero, L_80108350
    if (ctx->r18 != 0) {
        // 0x80108348: nop
    
            goto L_80108350;
    }
    // 0x80108348: nop

    // 0x8010834C: break       7
    do_break(2148565836);
L_80108350:
    // 0x80108350: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80108354: bne         $s2, $at, L_80108368
    if (ctx->r18 != ctx->r1) {
        // 0x80108358: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80108368;
    }
    // 0x80108358: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010835C: bne         $s1, $at, L_80108368
    if (ctx->r17 != ctx->r1) {
        // 0x80108360: nop
    
            goto L_80108368;
    }
    // 0x80108360: nop

    // 0x80108364: break       6
    do_break(2148565860);
L_80108368:
    // 0x80108368: mflo        $t2
    ctx->r10 = lo;
    // 0x8010836C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80108370: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    // 0x80108374: addiu       $a0, $a0, 0x101
    ctx->r4 = ADD32(ctx->r4, 0X101);
    // 0x80108378: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x8010837C: bne         $at, $zero, L_80108388
    if (ctx->r1 != 0) {
        // 0x80108380: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80108388;
    }
    // 0x80108380: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80108384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80108388:
    // 0x80108388: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8010838C:
    // 0x8010838C: bnel        $s0, $zero, L_801082D0
    if (ctx->r16 != 0) {
        // 0x80108390: lw          $t7, 0x24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X24);
            goto L_801082D0;
    }
    goto skip_4;
    // 0x80108390: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    skip_4:
L_80108394:
    // 0x80108394: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80108398: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010839C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801083A0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801083A4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801083A8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801083AC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801083B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801083B4: jr          $ra
    // 0x801083B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x801083B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801083bc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801083bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801083BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801083C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801083C4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801083C8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801083CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801083D0: jal         0x80108280
    // 0x801083D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80108280)(rdram, ctx);
        goto after_0;
    // 0x801083D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801083D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801083DC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801083E0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801083E4: addiu       $t6, $t6, -0x799C
    ctx->r14 = ADD32(ctx->r14, -0X799C);
    // 0x801083E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801083EC: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x801083F0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801083F4: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801083F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801083FC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80108400: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80108404: jal         0x80108868
    // 0x80108408: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_1;
    // 0x80108408: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8010840C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80108410: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80108414: lw          $t8, -0x4084($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4084);
    // 0x80108418: lw          $t7, -0x4530($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4530);
    // 0x8010841C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80108420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108424: beql        $t7, $t8, L_80108434
    if (ctx->r15 == ctx->r24) {
        // 0x80108428: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80108434;
    }
    goto skip_0;
    // 0x80108428: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8010842C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80108430: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80108434:
    // 0x80108434: jr          $ra
    // 0x80108438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010843c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010843c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010843C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108440: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80108444: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80108448: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010844C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108450: addiu       $t6, $t6, -0x799C
    ctx->r14 = ADD32(ctx->r14, -0X799C);
    // 0x80108454: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108458: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010845C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80108460: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x80108464: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80108468: jal         0x80108868
    // 0x8010846C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_0;
    // 0x8010846C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80108470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108478: jr          $ra
    // 0x8010847C: nop

    return;
    // 0x8010847C: nop

;}
RECOMP_FUNC void M7_FUN_80108480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108484: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80108488: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010848C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80108490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108494: addiu       $t6, $t6, -0x7990
    ctx->r14 = ADD32(ctx->r14, -0X7990);
    // 0x80108498: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010849C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801084A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801084A4: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x801084A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801084AC: jal         0x80108868
    // 0x801084B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_0;
    // 0x801084B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801084B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801084B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801084BC: jr          $ra
    // 0x801084C0: nop

    return;
    // 0x801084C0: nop

;}
RECOMP_FUNC void M7_FUN_801084c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801084C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801084C8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801084CC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801084D0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801084D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801084D8: addiu       $t6, $t6, -0x793C
    ctx->r14 = ADD32(ctx->r14, -0X793C);
    // 0x801084DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801084E0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801084E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801084E8: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x801084EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801084F0: jal         0x80108868
    // 0x801084F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_0;
    // 0x801084F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801084F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801084FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108500: jr          $ra
    // 0x80108504: nop

    return;
    // 0x80108504: nop

;}
RECOMP_FUNC void M7_FUN_80108508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010850C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80108510: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80108514: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80108518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010851C: addiu       $t6, $t6, -0x78E8
    ctx->r14 = ADD32(ctx->r14, -0X78E8);
    // 0x80108520: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108524: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80108528: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8010852C: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x80108530: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80108534: jal         0x80108868
    // 0x80108538: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_0;
    // 0x80108538: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8010853C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108540: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108544: jr          $ra
    // 0x80108548: nop

    return;
    // 0x80108548: nop

;}
RECOMP_FUNC void M7_FUN_8010854c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010854C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108550: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80108554: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80108558: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010855C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108560: addiu       $t6, $t6, -0x7894
    ctx->r14 = ADD32(ctx->r14, -0X7894);
    // 0x80108564: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108568: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010856C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80108570: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x80108574: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80108578: jal         0x80108868
    // 0x8010857C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_0;
    // 0x8010857C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80108580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108588: jr          $ra
    // 0x8010858C: nop

    return;
    // 0x8010858C: nop

;}
RECOMP_FUNC void M7_FUN_80108590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108594: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80108598: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010859C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801085A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801085A4: addiu       $t6, $t6, -0x7840
    ctx->r14 = ADD32(ctx->r14, -0X7840);
    // 0x801085A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801085AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801085B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801085B4: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x801085B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801085BC: jal         0x80108868
    // 0x801085C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108868)(rdram, ctx);
        goto after_0;
    // 0x801085C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801085C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801085C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801085CC: jr          $ra
    // 0x801085D0: nop

    return;
    // 0x801085D0: nop

;}
RECOMP_FUNC void M7_FUN_801085d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801085D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801085D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801085DC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801085E0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801085E4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801085E8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801085EC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801085F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801085F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801085F8: addiu       $t6, $t6, -0x77EC
    ctx->r14 = ADD32(ctx->r14, -0X77EC);
    // 0x801085FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108600: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80108604: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80108608: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8010860C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80108610: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    // 0x80108614: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80108618: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8010861C: jal         0x8010A1AC
    // 0x80108620: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8010A1AC)(rdram, ctx);
        goto after_0;
    // 0x80108620: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80108624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80108628: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010862C: jr          $ra
    // 0x80108630: nop

    return;
    // 0x80108630: nop

;}
RECOMP_FUNC void M7_FUN_80108634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108638: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010863C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108640: addiu       $t6, $t6, -0x799C
    ctx->r14 = ADD32(ctx->r14, -0X799C);
    // 0x80108644: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108648: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010864C: jal         0x80109560
    // 0x80108650: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x80109560)(rdram, ctx);
        goto after_0;
    // 0x80108650: sw          $t6, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r14;
    after_0:
    // 0x80108654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010865C: jr          $ra
    // 0x80108660: nop

    return;
    // 0x80108660: nop

;}
RECOMP_FUNC void M7_FUN_80108664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108664: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80108668: jr          $ra
    // 0x8010866C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8010866C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80108670(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80108670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108670: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80108674: lbu         $t6, 0x3530($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3530);
    // 0x80108678: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8010867C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80108680: beq         $a2, $t6, L_801086B8
    if (ctx->r6 == ctx->r14) {
        // 0x80108684: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_801086B8;
    }
    // 0x80108684: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80108688: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8010868C: addiu       $v1, $t7, 0x3530
    ctx->r3 = ADD32(ctx->r15, 0X3530);
    // 0x80108690: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80108694: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
L_80108698:
    // 0x80108698: bnel        $v0, $a1, L_801086AC
    if (ctx->r2 != ctx->r5) {
        // 0x8010869C: lbu         $a1, 0x1($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X1);
            goto L_801086AC;
    }
    goto skip_0;
    // 0x8010869C: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x801086A0: jr          $ra
    // 0x801086A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801086A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801086A8: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
L_801086AC:
    // 0x801086AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801086B0: bne         $a2, $a1, L_80108698
    if (ctx->r6 != ctx->r5) {
        // 0x801086B4: nop
    
            goto L_80108698;
    }
    // 0x801086B4: nop

L_801086B8:
    // 0x801086B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801086BC: jr          $ra
    // 0x801086C0: nop

    return;
    // 0x801086C0: nop

;}
RECOMP_FUNC void M7_FUN_801086c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801086C4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801086C8: lbu         $t6, 0x3570($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3570);
    // 0x801086CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801086D0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801086D4: beq         $a2, $t6, L_8010870C
    if (ctx->r6 == ctx->r14) {
        // 0x801086D8: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_8010870C;
    }
    // 0x801086D8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801086DC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801086E0: addiu       $v1, $t7, 0x3570
    ctx->r3 = ADD32(ctx->r15, 0X3570);
    // 0x801086E4: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x801086E8: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
L_801086EC:
    // 0x801086EC: bnel        $v0, $a1, L_80108700
    if (ctx->r2 != ctx->r5) {
        // 0x801086F0: lbu         $a1, 0x1($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X1);
            goto L_80108700;
    }
    goto skip_0;
    // 0x801086F0: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x801086F4: jr          $ra
    // 0x801086F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801086F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801086FC: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
L_80108700:
    // 0x80108700: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80108704: bne         $a2, $a1, L_801086EC
    if (ctx->r6 != ctx->r5) {
        // 0x80108708: nop
    
            goto L_801086EC;
    }
    // 0x80108708: nop

L_8010870C:
    // 0x8010870C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108710: jr          $ra
    // 0x80108714: nop

    return;
    // 0x80108714: nop

;}
RECOMP_FUNC void M7_FUN_80108718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108718: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8010871C: lbu         $t6, 0x35B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X35B0);
    // 0x80108720: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80108724: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80108728: beq         $a2, $t6, L_80108760
    if (ctx->r6 == ctx->r14) {
        // 0x8010872C: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_80108760;
    }
    // 0x8010872C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80108730: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80108734: addiu       $v1, $t7, 0x35B0
    ctx->r3 = ADD32(ctx->r15, 0X35B0);
    // 0x80108738: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8010873C: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
L_80108740:
    // 0x80108740: bnel        $v0, $a1, L_80108754
    if (ctx->r2 != ctx->r5) {
        // 0x80108744: lbu         $a1, 0x1($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X1);
            goto L_80108754;
    }
    goto skip_0;
    // 0x80108744: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x80108748: jr          $ra
    // 0x8010874C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8010874C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80108750: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
L_80108754:
    // 0x80108754: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80108758: bne         $a2, $a1, L_80108740
    if (ctx->r6 != ctx->r5) {
        // 0x8010875C: nop
    
            goto L_80108740;
    }
    // 0x8010875C: nop

L_80108760:
    // 0x80108760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108764: jr          $ra
    // 0x80108768: nop

    return;
    // 0x80108768: nop

;}
RECOMP_FUNC void M7_FUN_8010876c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010876C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80108770: lbu         $t6, 0x35F0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X35F0);
    // 0x80108774: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80108778: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8010877C: beq         $a2, $t6, L_801087B4
    if (ctx->r6 == ctx->r14) {
        // 0x80108780: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_801087B4;
    }
    // 0x80108780: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80108784: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80108788: addiu       $v1, $t7, 0x35F0
    ctx->r3 = ADD32(ctx->r15, 0X35F0);
    // 0x8010878C: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80108790: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
L_80108794:
    // 0x80108794: bnel        $v0, $a1, L_801087A8
    if (ctx->r2 != ctx->r5) {
        // 0x80108798: lbu         $a1, 0x1($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X1);
            goto L_801087A8;
    }
    goto skip_0;
    // 0x80108798: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x8010879C: jr          $ra
    // 0x801087A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801087A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801087A4: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
L_801087A8:
    // 0x801087A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801087AC: bne         $a2, $a1, L_80108794
    if (ctx->r6 != ctx->r5) {
        // 0x801087B0: nop
    
            goto L_80108794;
    }
    // 0x801087B0: nop

L_801087B4:
    // 0x801087B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801087B8: jr          $ra
    // 0x801087BC: nop

    return;
    // 0x801087BC: nop

;}
RECOMP_FUNC void M7_FUN_801087c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801087C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801087C4: lbu         $t6, 0x3630($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3630);
    // 0x801087C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801087CC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801087D0: beq         $a2, $t6, L_80108808
    if (ctx->r6 == ctx->r14) {
        // 0x801087D4: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_80108808;
    }
    // 0x801087D4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801087D8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801087DC: addiu       $v1, $t7, 0x3630
    ctx->r3 = ADD32(ctx->r15, 0X3630);
    // 0x801087E0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x801087E4: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
L_801087E8:
    // 0x801087E8: bnel        $v0, $a1, L_801087FC
    if (ctx->r2 != ctx->r5) {
        // 0x801087EC: lbu         $a1, 0x1($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X1);
            goto L_801087FC;
    }
    goto skip_0;
    // 0x801087EC: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x801087F0: jr          $ra
    // 0x801087F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801087F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801087F8: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
L_801087FC:
    // 0x801087FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80108800: bne         $a2, $a1, L_801087E8
    if (ctx->r6 != ctx->r5) {
        // 0x80108804: nop
    
            goto L_801087E8;
    }
    // 0x80108804: nop

L_80108808:
    // 0x80108808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010880C: jr          $ra
    // 0x80108810: nop

    return;
    // 0x80108810: nop

;}
RECOMP_FUNC void M7_FUN_80108814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108814: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80108818: lbu         $t6, 0x3670($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3670);
    // 0x8010881C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80108820: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80108824: beq         $a2, $t6, L_8010885C
    if (ctx->r6 == ctx->r14) {
        // 0x80108828: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_8010885C;
    }
    // 0x80108828: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8010882C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80108830: addiu       $v1, $t7, 0x3670
    ctx->r3 = ADD32(ctx->r15, 0X3670);
    // 0x80108834: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80108838: andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
L_8010883C:
    // 0x8010883C: bnel        $v0, $a1, L_80108850
    if (ctx->r2 != ctx->r5) {
        // 0x80108840: lbu         $a1, 0x1($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X1);
            goto L_80108850;
    }
    goto skip_0;
    // 0x80108840: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x80108844: jr          $ra
    // 0x80108848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80108848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010884C: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
L_80108850:
    // 0x80108850: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80108854: bne         $a2, $a1, L_8010883C
    if (ctx->r6 != ctx->r5) {
        // 0x80108858: nop
    
            goto L_8010883C;
    }
    // 0x80108858: nop

L_8010885C:
    // 0x8010885C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108860: jr          $ra
    // 0x80108864: nop

    return;
    // 0x80108864: nop

;}
RECOMP_FUNC void M7_FUN_80108868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108868: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x8010886C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80108870: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x80108874: addiu       $s4, $s4, -0x4410
    ctx->r20 = ADD32(ctx->r20, -0X4410);
    // 0x80108878: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010887C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80108880: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80108884: lw          $t9, 0x50($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X50);
    // 0x80108888: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8010888C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80108890: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80108894: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80108898: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8010889C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801088A0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801088A4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801088A8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801088AC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x801088B0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x801088B4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801088B8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801088BC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801088C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801088C4: swc1        $f12, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f12.u32l;
    // 0x801088C8: swc1        $f14, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->f14.u32l;
    // 0x801088CC: sw          $a2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r6;
    // 0x801088D0: sw          $a3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r7;
    // 0x801088D4: sb          $zero, 0x35A($s4)
    MEM_B(0X35A, ctx->r20) = 0;
    // 0x801088D8: sb          $zero, 0x35B($s4)
    MEM_B(0X35B, ctx->r20) = 0;
    // 0x801088DC: sw          $zero, 0x38C($s4)
    MEM_W(0X38C, ctx->r20) = 0;
    // 0x801088E0: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x801088E4: swc1        $f0, 0x35C($s4)
    MEM_W(0X35C, ctx->r20) = ctx->f0.u32l;
    // 0x801088E8: swc1        $f0, 0x360($s4)
    MEM_W(0X360, ctx->r20) = ctx->f0.u32l;
    // 0x801088EC: swc1        $f0, 0x364($s4)
    MEM_W(0X364, ctx->r20) = ctx->f0.u32l;
    // 0x801088F0: swc1        $f0, 0x368($s4)
    MEM_W(0X368, ctx->r20) = ctx->f0.u32l;
    // 0x801088F4: swc1        $f0, 0x36C($s4)
    MEM_W(0X36C, ctx->r20) = ctx->f0.u32l;
    // 0x801088F8: swc1        $f0, 0x370($s4)
    MEM_W(0X370, ctx->r20) = ctx->f0.u32l;
    // 0x801088FC: swc1        $f0, 0x374($s4)
    MEM_W(0X374, ctx->r20) = ctx->f0.u32l;
    // 0x80108900: swc1        $f0, 0x378($s4)
    MEM_W(0X378, ctx->r20) = ctx->f0.u32l;
    // 0x80108904: swc1        $f0, 0x37C($s4)
    MEM_W(0X37C, ctx->r20) = ctx->f0.u32l;
    // 0x80108908: swc1        $f0, 0x380($s4)
    MEM_W(0X380, ctx->r20) = ctx->f0.u32l;
    // 0x8010890C: swc1        $f0, 0x384($s4)
    MEM_W(0X384, ctx->r20) = ctx->f0.u32l;
    // 0x80108910: swc1        $f0, 0x388($s4)
    MEM_W(0X388, ctx->r20) = ctx->f0.u32l;
    // 0x80108914: swc1        $f6, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f6.u32l;
    // 0x80108918: lw          $s5, 0x8($t9)
    ctx->r21 = MEM_W(ctx->r25, 0X8);
    // 0x8010891C: addiu       $s6, $sp, 0x144
    ctx->r22 = ADD32(ctx->r29, 0X144);
    // 0x80108920: addiu       $s7, $sp, 0x140
    ctx->r23 = ADD32(ctx->r29, 0X140);
    // 0x80108924: beql        $s5, $zero, L_80109080
    if (ctx->r21 == 0) {
        // 0x80108928: lw          $t6, 0x17C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X17C);
            goto L_80109080;
    }
    goto skip_0;
    // 0x80108928: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    skip_0:
    // 0x8010892C: addiu       $fp, $sp, 0x13C
    ctx->r30 = ADD32(ctx->r29, 0X13C);
    // 0x80108930: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
L_80108934:
    // 0x80108934: beql        $v1, $zero, L_80109074
    if (ctx->r3 == 0) {
        // 0x80108938: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109074;
    }
    goto skip_1;
    // 0x80108938: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x8010893C: lw          $a1, 0x74($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X74);
    // 0x80108940: beql        $a1, $zero, L_80109074
    if (ctx->r5 == 0) {
        // 0x80108944: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109074;
    }
    goto skip_2;
    // 0x80108944: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_2:
    // 0x80108948: lw          $t0, 0x2C($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X2C);
    // 0x8010894C: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x80108950: beql        $t1, $zero, L_80109074
    if (ctx->r9 == 0) {
        // 0x80108954: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109074;
    }
    goto skip_3;
    // 0x80108954: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_3:
    // 0x80108958: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8010895C: beql        $v0, $zero, L_80108990
    if (ctx->r2 == 0) {
        // 0x80108960: lw          $v0, 0x2C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X2C);
            goto L_80108990;
    }
    goto skip_4;
    // 0x80108960: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    skip_4:
    // 0x80108964: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80108968: swc1        $f10, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f10.u32l;
    // 0x8010896C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80108970: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80108974: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80108978: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
    // 0x8010897C: lh          $s1, 0x10($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X10);
    // 0x80108980: lh          $s2, 0x12($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X12);
    // 0x80108984: b           L_801089B4
    // 0x80108988: lh          $s3, 0x14($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X14);
        goto L_801089B4;
    // 0x80108988: lh          $s3, 0x14($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X14);
    // 0x8010898C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_80108990:
    // 0x80108990: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80108994: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
    // 0x80108998: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010899C: swc1        $f10, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f10.u32l;
    // 0x801089A0: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801089A4: swc1        $f8, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f8.u32l;
    // 0x801089A8: lh          $s1, 0x10($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X10);
    // 0x801089AC: lh          $s2, 0x12($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X12);
    // 0x801089B0: lh          $s3, 0x14($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X14);
L_801089B4:
    // 0x801089B4: bne         $s1, $zero, L_80108AF8
    if (ctx->r17 != 0) {
        // 0x801089B8: negu        $s0, $s1
        ctx->r16 = SUB32(0, ctx->r17);
            goto L_80108AF8;
    }
    // 0x801089B8: negu        $s0, $s1
    ctx->r16 = SUB32(0, ctx->r17);
    // 0x801089BC: bnel        $s2, $zero, L_80108AFC
    if (ctx->r18 != 0) {
        // 0x801089C0: sll         $s0, $s0, 16
        ctx->r16 = S32(ctx->r16 << 16);
            goto L_80108AFC;
    }
    goto skip_5;
    // 0x801089C0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    skip_5:
    // 0x801089C4: bnel        $s3, $zero, L_80108AFC
    if (ctx->r19 != 0) {
        // 0x801089C8: sll         $s0, $s0, 16
        ctx->r16 = S32(ctx->r16 << 16);
            goto L_80108AFC;
    }
    goto skip_6;
    // 0x801089C8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    skip_6:
    // 0x801089CC: lwc1        $f4, 0x180($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X180);
    // 0x801089D0: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x801089D4: lwc1        $f8, 0x184($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X184);
    // 0x801089D8: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x801089DC: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801089E0: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x801089E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801089E8: swc1        $f10, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f10.u32l;
    // 0x801089EC: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801089F0: lwc1        $f8, 0x188($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X188);
    // 0x801089F4: swc1        $f10, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f10.u32l;
    // 0x801089F8: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x801089FC: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80108A00: swc1        $f8, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f8.u32l;
    // 0x80108A04: lwc1        $f8, 0x18C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x80108A08: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80108A0C: lwc1        $f6, 0x190($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X190);
    // 0x80108A10: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
    // 0x80108A14: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80108A18: lwc1        $f6, 0x194($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X194);
    // 0x80108A1C: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80108A20: swc1        $f8, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f8.u32l;
    // 0x80108A24: jal         0x8010ACF8
    // 0x80108A28: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8010ACF8)(rdram, ctx);
        goto after_0;
    // 0x80108A28: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80108A2C: beq         $v0, $zero, L_80109070
    if (ctx->r2 == 0) {
        // 0x80108A30: lwc1        $f0, 0x164($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X164);
            goto L_80109070;
    }
    // 0x80108A30: lwc1        $f0, 0x164($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X164);
    // 0x80108A34: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80108A38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80108A3C: sw          $t2, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r10;
    // 0x80108A40: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80108A44: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80108A48: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80108A4C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80108A50: bc1f        L_80109070
    if (!c1cs) {
        // 0x80108A54: addiu       $a3, $sp, 0x138
        ctx->r7 = ADD32(ctx->r29, 0X138);
            goto L_80109070;
    }
    // 0x80108A54: addiu       $a3, $sp, 0x138
    ctx->r7 = ADD32(ctx->r29, 0X138);
    // 0x80108A58: jal         0x8010B634
    // 0x80108A5C: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8010B634)(rdram, ctx);
        goto after_1;
    // 0x80108A5C: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80108A60: lwc1        $f24, 0x140($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80108A64: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80108A68: lwc1        $f26, 0x13C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80108A6C: lwc1        $f28, 0x138($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80108A70: lwc1        $f30, 0x120($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80108A74: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80108A78: add.s       $f10, $f24, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x80108A7C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80108A80: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80108A84: add.s       $f6, $f28, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f28.fl + ctx->f30.fl;
    // 0x80108A88: swc1        $f10, 0x374($s4)
    MEM_W(0X374, ctx->r20) = ctx->f10.u32l;
    // 0x80108A8C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80108A90: add.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl + ctx->f4.fl;
    // 0x80108A94: swc1        $f6, 0x37C($s4)
    MEM_W(0X37C, ctx->r20) = ctx->f6.u32l;
    // 0x80108A98: addiu       $a3, $sp, 0x138
    ctx->r7 = ADD32(ctx->r29, 0X138);
    // 0x80108A9C: jal         0x8010B4D8
    // 0x80108AA0: swc1        $f8, 0x378($s4)
    MEM_W(0X378, ctx->r20) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8010B4D8)(rdram, ctx);
        goto after_2;
    // 0x80108AA0: swc1        $f8, 0x378($s4)
    MEM_W(0X378, ctx->r20) = ctx->f8.u32l;
    after_2:
    // 0x80108AA4: lwc1        $f24, 0x140($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80108AA8: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80108AAC: lwc1        $f26, 0x13C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80108AB0: lwc1        $f28, 0x138($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80108AB4: lwc1        $f8, 0x124($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80108AB8: add.s       $f4, $f24, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f10.fl;
    // 0x80108ABC: lwc1        $f18, 0x168($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X168);
    // 0x80108AC0: lwc1        $f20, 0x16C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x80108AC4: add.s       $f10, $f28, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f28.fl + ctx->f30.fl;
    // 0x80108AC8: lwc1        $f22, 0x170($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X170);
    // 0x80108ACC: lbu         $t3, 0x160($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X160);
    // 0x80108AD0: add.s       $f6, $f26, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f26.fl + ctx->f8.fl;
    // 0x80108AD4: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x80108AD8: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80108ADC: sw          $s5, 0x38C($s4)
    MEM_W(0X38C, ctx->r20) = ctx->r21;
    // 0x80108AE0: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80108AE4: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
    // 0x80108AE8: swc1        $f20, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f20.u32l;
    // 0x80108AEC: swc1        $f22, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f22.u32l;
    // 0x80108AF0: b           L_80109070
    // 0x80108AF4: sb          $t3, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r11;
        goto L_80109070;
    // 0x80108AF4: sb          $t3, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r11;
L_80108AF8:
    // 0x80108AF8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
L_80108AFC:
    // 0x80108AFC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80108B00: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80108B04: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x80108B08: jal         0x8001EAD0
    // 0x80108B0C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80108B0C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x80108B10: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80108B14: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x80108B18: jal         0x8001EB64
    // 0x80108B1C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x80108B1C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x80108B20: negu        $s0, $s2
    ctx->r16 = SUB32(0, ctx->r18);
    // 0x80108B24: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80108B28: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80108B2C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80108B30: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80108B34: jal         0x8001EAD0
    // 0x80108B38: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x80108B38: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x80108B3C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80108B40: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x80108B44: jal         0x8001EB64
    // 0x80108B48: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x80108B48: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_6:
    // 0x80108B4C: negu        $s0, $s3
    ctx->r16 = SUB32(0, ctx->r19);
    // 0x80108B50: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80108B54: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80108B58: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80108B5C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80108B60: jal         0x8001EAD0
    // 0x80108B64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x80108B64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x80108B68: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80108B6C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80108B70: jal         0x8001EB64
    // 0x80108B74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x80108B74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_8:
    // 0x80108B78: mul.s       $f24, $f0, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80108B7C: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80108B80: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80108B84: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80108B88: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80108B8C: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80108B90: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80108B94: mul.s       $f6, $f20, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80108B98: nop

    // 0x80108B9C: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80108BA0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80108BA4: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80108BA8: nop

    // 0x80108BAC: mul.s       $f10, $f2, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f30.fl);
    // 0x80108BB0: lwc1        $f2, 0x128($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80108BB4: swc1        $f12, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f12.u32l;
    // 0x80108BB8: mul.s       $f26, $f20, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80108BBC: swc1        $f12, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f12.u32l;
    // 0x80108BC0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80108BC4: sub.s       $f28, $f6, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80108BC8: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80108BCC: nop

    // 0x80108BD0: mul.s       $f10, $f26, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80108BD4: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80108BD8: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80108BDC: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    // 0x80108BE0: mul.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80108BE4: nop

    // 0x80108BE8: mul.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80108BEC: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80108BF0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80108BF4: swc1        $f12, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f12.u32l;
    // 0x80108BF8: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80108BFC: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80108C00: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80108C04: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x80108C08: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80108C0C: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x80108C10: swc1        $f6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f6.u32l;
    // 0x80108C14: mul.s       $f14, $f8, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80108C18: lwc1        $f20, 0x190($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X190);
    // 0x80108C1C: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80108C20: nop

    // 0x80108C24: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80108C28: sub.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80108C2C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80108C30: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x80108C34: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80108C38: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x80108C3C: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80108C40: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80108C44: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x80108C48: lwc1        $f6, 0x184($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X184);
    // 0x80108C4C: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80108C50: lwc1        $f10, 0x180($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80108C54: mul.s       $f4, $f24, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x80108C58: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80108C5C: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80108C60: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80108C64: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80108C68: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80108C6C: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80108C70: lwc1        $f10, 0x188($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X188);
    // 0x80108C74: mul.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80108C78: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108C7C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80108C80: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80108C84: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80108C88: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108C8C: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80108C90: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80108C94: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x80108C98: swc1        $f4, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f4.u32l;
    // 0x80108C9C: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80108CA0: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80108CA4: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80108CA8: lwc1        $f6, 0x188($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X188);
    // 0x80108CAC: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80108CB0: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108CB4: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80108CB8: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80108CBC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108CC0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80108CC4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80108CC8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80108CCC: swc1        $f10, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f10.u32l;
    // 0x80108CD0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80108CD4: nop

    // 0x80108CD8: mul.s       $f6, $f26, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f30.fl);
    // 0x80108CDC: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80108CE0: mul.s       $f12, $f22, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80108CE4: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80108CE8: lwc1        $f22, 0x18C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x80108CEC: mul.s       $f10, $f2, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x80108CF0: lwc1        $f2, 0x194($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X194);
    // 0x80108CF4: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80108CF8: sub.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80108CFC: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80108D00: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80108D04: sub.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80108D08: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80108D0C: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x80108D10: mul.s       $f10, $f28, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80108D14: nop

    // 0x80108D18: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80108D1C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80108D20: lwc1        $f10, 0x188($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X188);
    // 0x80108D24: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80108D28: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80108D2C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80108D30: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80108D34: mul.s       $f8, $f24, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x80108D38: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80108D3C: swc1        $f6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f6.u32l;
    // 0x80108D40: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80108D44: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80108D48: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80108D4C: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80108D50: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80108D54: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80108D58: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80108D5C: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80108D60: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x80108D64: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80108D68: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80108D6C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80108D70: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80108D74: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80108D78: mul.s       $f6, $f28, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x80108D7C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80108D80: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80108D84: swc1        $f8, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f8.u32l;
    // 0x80108D88: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80108D8C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80108D90: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80108D94: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80108D98: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80108D9C: jal         0x8010ACF8
    // 0x80108DA0: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8010ACF8)(rdram, ctx);
        goto after_9;
    // 0x80108DA0: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x80108DA4: beq         $v0, $zero, L_80109070
    if (ctx->r2 == 0) {
        // 0x80108DA8: lwc1        $f0, 0x164($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X164);
            goto L_80109070;
    }
    // 0x80108DA8: lwc1        $f0, 0x164($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X164);
    // 0x80108DAC: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80108DB0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80108DB4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80108DB8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80108DBC: sw          $t4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r12;
    // 0x80108DC0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80108DC4: bc1fl       L_80109074
    if (!c1cs) {
        // 0x80108DC8: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109074;
    }
    goto skip_7;
    // 0x80108DC8: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_7:
    // 0x80108DCC: jal         0x8001EAD0
    // 0x80108DD0: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_10;
    // 0x80108DD0: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80108DD4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80108DD8: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x80108DDC: jal         0x8001EB64
    // 0x80108DE0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_11;
    // 0x80108DE0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
    // 0x80108DE4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80108DE8: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80108DEC: jal         0x8001EAD0
    // 0x80108DF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x80108DF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_12:
    // 0x80108DF4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80108DF8: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x80108DFC: jal         0x8001EB64
    // 0x80108E00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x80108E00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_13:
    // 0x80108E04: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80108E08: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80108E0C: jal         0x8001EAD0
    // 0x80108E10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_14;
    // 0x80108E10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_14:
    // 0x80108E14: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80108E18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80108E1C: jal         0x8001EB64
    // 0x80108E20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_15;
    // 0x80108E20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_15:
    // 0x80108E24: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80108E28: lwc1        $f12, 0x110($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80108E2C: lwc1        $f14, 0x114($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80108E30: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    // 0x80108E34: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80108E38: mul.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80108E3C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80108E40: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x80108E44: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80108E48: addiu       $a3, $sp, 0x138
    ctx->r7 = ADD32(ctx->r29, 0X138);
    // 0x80108E4C: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80108E50: nop

    // 0x80108E54: mul.s       $f4, $f30, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80108E58: nop

    // 0x80108E5C: mul.s       $f18, $f30, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f30.fl, ctx->f12.fl);
    // 0x80108E60: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80108E64: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80108E68: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    // 0x80108E6C: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x80108E70: mul.s       $f10, $f14, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80108E74: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80108E78: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80108E7C: nop

    // 0x80108E80: mul.s       $f6, $f30, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f20.fl);
    // 0x80108E84: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x80108E88: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80108E8C: jal         0x8010B634
    // 0x80108E90: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010B634)(rdram, ctx);
        goto after_16;
    // 0x80108E90: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80108E94: lwc1        $f24, 0x140($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80108E98: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80108E9C: lwc1        $f26, 0x13C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80108EA0: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80108EA4: mul.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80108EA8: lwc1        $f28, 0x138($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80108EAC: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80108EB0: mul.s       $f10, $f6, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80108EB4: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80108EB8: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80108EBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108EC0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80108EC4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80108EC8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80108ECC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80108ED0: mul.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80108ED4: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80108ED8: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x80108EDC: mul.s       $f2, $f22, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80108EE0: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80108EE4: addiu       $a3, $sp, 0x138
    ctx->r7 = ADD32(ctx->r29, 0X138);
    // 0x80108EE8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80108EEC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80108EF0: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    // 0x80108EF4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80108EF8: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80108EFC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80108F00: swc1        $f4, 0x374($s4)
    MEM_W(0X374, ctx->r20) = ctx->f4.u32l;
    // 0x80108F04: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80108F08: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80108F0C: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80108F10: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80108F14: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x80108F18: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80108F1C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80108F20: mul.s       $f10, $f14, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x80108F24: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108F28: mul.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80108F2C: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80108F30: mul.s       $f12, $f22, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80108F34: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80108F38: mul.s       $f6, $f16, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80108F3C: swc1        $f0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f0.u32l;
    // 0x80108F40: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80108F44: swc1        $f10, -0x4098($at)
    MEM_W(-0X4098, ctx->r1) = ctx->f10.u32l;
    // 0x80108F48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80108F4C: mul.s       $f8, $f12, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x80108F50: swc1        $f12, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f12.u32l;
    // 0x80108F54: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80108F58: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80108F5C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80108F60: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80108F64: jal         0x8010B4D8
    // 0x80108F68: swc1        $f10, -0x4094($at)
    MEM_W(-0X4094, ctx->r1) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010B4D8)(rdram, ctx);
        goto after_17;
    // 0x80108F68: swc1        $f10, -0x4094($at)
    MEM_W(-0X4094, ctx->r1) = ctx->f10.u32l;
    after_17:
    // 0x80108F6C: lwc1        $f24, 0x140($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80108F70: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80108F74: lwc1        $f26, 0x13C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80108F78: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80108F7C: mul.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x80108F80: lwc1        $f28, 0x138($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80108F84: lwc1        $f2, 0xB4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80108F88: mul.s       $f10, $f4, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80108F8C: lwc1        $f30, 0xCC($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80108F90: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80108F94: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80108F98: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80108F9C: lwc1        $f12, 0xB8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80108FA0: lwc1        $f18, 0x168($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X168);
    // 0x80108FA4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80108FA8: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80108FAC: lwc1        $f20, 0x16C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x80108FB0: lwc1        $f22, 0x170($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X170);
    // 0x80108FB4: mul.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80108FB8: lbu         $t5, 0x160($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X160);
    // 0x80108FBC: sw          $s5, 0x38C($s4)
    MEM_W(0X38C, ctx->r20) = ctx->r21;
    // 0x80108FC0: sb          $t5, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r13;
    // 0x80108FC4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108FC8: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80108FCC: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80108FD0: mul.s       $f6, $f2, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80108FD4: nop

    // 0x80108FD8: mul.s       $f4, $f30, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x80108FDC: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x80108FE0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80108FE4: mul.s       $f6, $f14, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x80108FE8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80108FEC: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80108FF0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80108FF4: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80108FF8: nop

    // 0x80108FFC: mul.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80109000: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80109004: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109008: mul.s       $f4, $f12, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x8010900C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80109010: lwc1        $f6, 0x120($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80109014: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80109018: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8010901C: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80109020: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80109024: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80109028: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8010902C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109030: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80109034: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80109038: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8010903C: nop

    // 0x80109040: mul.s       $f8, $f30, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f20.fl);
    // 0x80109044: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x80109048: mul.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x8010904C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109050: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80109054: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109058: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010905C: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    // 0x80109060: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80109064: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80109068: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010906C: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
L_80109070:
    // 0x80109070: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
L_80109074:
    // 0x80109074: bnel        $s5, $zero, L_80108934
    if (ctx->r21 != 0) {
        // 0x80109078: lw          $v1, 0x24($s5)
        ctx->r3 = MEM_W(ctx->r21, 0X24);
            goto L_80108934;
    }
    goto skip_8;
    // 0x80109078: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
    skip_8:
    // 0x8010907C: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
L_80109080:
    // 0x80109080: addiu       $s6, $sp, 0x144
    ctx->r22 = ADD32(ctx->r29, 0X144);
    // 0x80109084: beql        $t6, $zero, L_80109518
    if (ctx->r14 == 0) {
        // 0x80109088: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80109518;
    }
    goto skip_9;
    // 0x80109088: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_9:
    // 0x8010908C: lw          $t7, 0x50($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X50);
    // 0x80109090: lw          $s5, 0x8($t7)
    ctx->r21 = MEM_W(ctx->r15, 0X8);
    // 0x80109094: beql        $s5, $zero, L_801094A4
    if (ctx->r21 == 0) {
        // 0x80109098: lwc1        $f4, 0x374($s4)
        ctx->f4.u32l = MEM_W(ctx->r20, 0X374);
            goto L_801094A4;
    }
    goto skip_10;
    // 0x80109098: lwc1        $f4, 0x374($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X374);
    skip_10:
    // 0x8010909C: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
L_801090A0:
    // 0x801090A0: beql        $v1, $zero, L_80109498
    if (ctx->r3 == 0) {
        // 0x801090A4: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109498;
    }
    goto skip_11;
    // 0x801090A4: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_11:
    // 0x801090A8: lw          $a1, 0x74($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X74);
    // 0x801090AC: beql        $a1, $zero, L_80109498
    if (ctx->r5 == 0) {
        // 0x801090B0: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109498;
    }
    goto skip_12;
    // 0x801090B0: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_12:
    // 0x801090B4: lw          $t8, 0x2C($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X2C);
    // 0x801090B8: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x801090BC: beql        $t9, $zero, L_80109498
    if (ctx->r25 == 0) {
        // 0x801090C0: lw          $s5, 0x0($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X0);
            goto L_80109498;
    }
    goto skip_13;
    // 0x801090C0: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
    skip_13:
    // 0x801090C4: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x801090C8: beql        $v0, $zero, L_801090FC
    if (ctx->r2 == 0) {
        // 0x801090CC: lw          $v0, 0x2C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X2C);
            goto L_801090FC;
    }
    goto skip_14;
    // 0x801090CC: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    skip_14:
    // 0x801090D0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801090D4: swc1        $f10, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f10.u32l;
    // 0x801090D8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801090DC: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x801090E0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801090E4: swc1        $f6, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f6.u32l;
    // 0x801090E8: lh          $s1, 0x10($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X10);
    // 0x801090EC: lh          $s2, 0x12($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X12);
    // 0x801090F0: b           L_80109120
    // 0x801090F4: lh          $s3, 0x14($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X14);
        goto L_80109120;
    // 0x801090F4: lh          $s3, 0x14($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X14);
    // 0x801090F8: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_801090FC:
    // 0x801090FC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80109100: swc1        $f8, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f8.u32l;
    // 0x80109104: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80109108: swc1        $f10, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f10.u32l;
    // 0x8010910C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80109110: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
    // 0x80109114: lh          $s1, 0x10($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X10);
    // 0x80109118: lh          $s2, 0x12($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X12);
    // 0x8010911C: lh          $s3, 0x14($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X14);
L_80109120:
    // 0x80109120: bne         $s1, $zero, L_80109194
    if (ctx->r17 != 0) {
        // 0x80109124: negu        $s0, $s1
        ctx->r16 = SUB32(0, ctx->r17);
            goto L_80109194;
    }
    // 0x80109124: negu        $s0, $s1
    ctx->r16 = SUB32(0, ctx->r17);
    // 0x80109128: bnel        $s2, $zero, L_80109198
    if (ctx->r18 != 0) {
        // 0x8010912C: sll         $s0, $s0, 16
        ctx->r16 = S32(ctx->r16 << 16);
            goto L_80109198;
    }
    goto skip_15;
    // 0x8010912C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    skip_15:
    // 0x80109130: bnel        $s3, $zero, L_80109198
    if (ctx->r19 != 0) {
        // 0x80109134: sll         $s0, $s0, 16
        ctx->r16 = S32(ctx->r16 << 16);
            goto L_80109198;
    }
    goto skip_16;
    // 0x80109134: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    skip_16:
    // 0x80109138: lwc1        $f6, 0x180($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X180);
    // 0x8010913C: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80109140: lwc1        $f4, 0x184($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X184);
    // 0x80109144: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x80109148: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010914C: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80109150: swc1        $f10, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f10.u32l;
    // 0x80109154: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80109158: lwc1        $f4, 0x188($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X188);
    // 0x8010915C: swc1        $f10, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f10.u32l;
    // 0x80109160: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80109164: sub.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80109168: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
    // 0x8010916C: lwc1        $f4, 0x374($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X374);
    // 0x80109170: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80109174: lwc1        $f8, 0x378($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X378);
    // 0x80109178: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
    // 0x8010917C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80109180: lwc1        $f8, 0x37C($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X37C);
    // 0x80109184: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80109188: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x8010918C: b           L_80109470
    // 0x80109190: swc1        $f6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f6.u32l;
        goto L_80109470;
    // 0x80109190: swc1        $f6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f6.u32l;
L_80109194:
    // 0x80109194: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
L_80109198:
    // 0x80109198: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010919C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801091A0: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x801091A4: jal         0x8001EAD0
    // 0x801091A8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_18;
    // 0x801091A8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_18:
    // 0x801091AC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801091B0: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x801091B4: jal         0x8001EB64
    // 0x801091B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_19;
    // 0x801091B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_19:
    // 0x801091BC: negu        $s0, $s2
    ctx->r16 = SUB32(0, ctx->r18);
    // 0x801091C0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801091C4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801091C8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801091CC: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x801091D0: jal         0x8001EAD0
    // 0x801091D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_20;
    // 0x801091D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_20:
    // 0x801091D8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801091DC: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x801091E0: jal         0x8001EB64
    // 0x801091E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_21;
    // 0x801091E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_21:
    // 0x801091E8: negu        $s0, $s3
    ctx->r16 = SUB32(0, ctx->r19);
    // 0x801091EC: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801091F0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801091F4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801091F8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801091FC: jal         0x8001EAD0
    // 0x80109200: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_22;
    // 0x80109200: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_22:
    // 0x80109204: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80109208: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010920C: jal         0x8001EB64
    // 0x80109210: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_23;
    // 0x80109210: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_23:
    // 0x80109214: mul.s       $f24, $f0, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80109218: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x8010921C: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80109220: mul.s       $f12, $f22, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80109224: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x80109228: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8010922C: mul.s       $f14, $f8, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80109230: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80109234: lwc1        $f22, 0x184($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X184);
    // 0x80109238: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010923C: swc1        $f24, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f24.u32l;
    // 0x80109240: swc1        $f12, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
    // 0x80109244: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80109248: swc1        $f14, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f14.u32l;
    // 0x8010924C: mul.s       $f10, $f20, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80109250: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x80109254: swc1        $f6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f6.u32l;
    // 0x80109258: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8010925C: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80109260: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109264: mul.s       $f26, $f20, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80109268: nop

    // 0x8010926C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80109270: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80109274: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x80109278: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x8010927C: mul.s       $f6, $f26, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f30.fl);
    // 0x80109280: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109284: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80109288: lwc1        $f20, 0x188($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X188);
    // 0x8010928C: mul.s       $f6, $f2, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f30.fl);
    // 0x80109290: lwc1        $f2, 0x128($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80109294: swc1        $f16, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f16.u32l;
    // 0x80109298: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8010929C: sub.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801092A0: mul.s       $f4, $f0, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x801092A4: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801092A8: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x801092AC: lwc1        $f0, 0x374($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X374);
    // 0x801092B0: mul.s       $f6, $f26, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x801092B4: lwc1        $f26, 0x180($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X180);
    // 0x801092B8: swc1        $f28, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f28.u32l;
    // 0x801092BC: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801092C0: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x801092C4: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x801092C8: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801092CC: swc1        $f18, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f18.u32l;
    // 0x801092D0: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801092D4: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x801092D8: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801092DC: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x801092E0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801092E4: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x801092E8: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801092EC: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801092F0: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x801092F4: mul.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801092F8: swc1        $f4, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f4.u32l;
    // 0x801092FC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80109300: mul.s       $f10, $f24, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x80109304: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80109308: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8010930C: mul.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x80109310: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109314: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80109318: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010931C: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80109320: lwc1        $f24, 0xDC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80109324: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80109328: lwc1        $f14, 0x37C($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X37C);
    // 0x8010932C: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80109330: sub.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f30.fl;
    // 0x80109334: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80109338: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8010933C: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80109340: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80109344: swc1        $f4, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f4.u32l;
    // 0x80109348: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8010934C: nop

    // 0x80109350: mul.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80109354: lwc1        $f18, 0xC8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80109358: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010935C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80109360: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x80109364: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80109368: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x8010936C: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109370: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80109374: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80109378: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010937C: swc1        $f4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f4.u32l;
    // 0x80109380: mul.s       $f4, $f28, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f26.fl);
    // 0x80109384: lwc1        $f26, 0x80($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80109388: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x8010938C: mul.s       $f6, $f16, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80109390: lwc1        $f22, 0xD8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80109394: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109398: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8010939C: lwc1        $f20, 0xD4($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x801093A0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801093A4: mul.s       $f6, $f2, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x801093A8: nop

    // 0x801093AC: mul.s       $f10, $f26, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x801093B0: lwc1        $f16, 0xC4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801093B4: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801093B8: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801093BC: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x801093C0: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801093C4: lwc1        $f12, 0x378($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X378);
    // 0x801093C8: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801093CC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801093D0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801093D4: mul.s       $f6, $f24, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x801093D8: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
    // 0x801093DC: mul.s       $f4, $f20, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x801093E0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801093E4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801093E8: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x801093EC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801093F0: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x801093F4: nop

    // 0x801093F8: mul.s       $f4, $f26, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x801093FC: sub.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80109400: sub.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x80109404: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80109408: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8010940C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80109410: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
    // 0x80109414: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80109418: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8010941C: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80109420: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80109424: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80109428: mul.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8010942C: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80109430: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80109434: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80109438: nop

    // 0x8010943C: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80109440: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x80109444: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80109448: mul.s       $f8, $f22, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010944C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109450: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80109454: nop

    // 0x80109458: mul.s       $f8, $f26, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x8010945C: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80109460: mul.s       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80109464: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80109468: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010946C: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
L_80109470:
    // 0x80109470: jal         0x8010ACF8
    // 0x80109474: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    LOOKUP_FUNC(0x8010ACF8)(rdram, ctx);
        goto after_24;
    // 0x80109474: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_24:
    // 0x80109478: beq         $v0, $zero, L_80109494
    if (ctx->r2 == 0) {
        // 0x8010947C: lwc1        $f8, 0xF8($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
            goto L_80109494;
    }
    // 0x8010947C: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80109480: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80109484: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80109488: swc1        $f8, 0x374($s4)
    MEM_W(0X374, ctx->r20) = ctx->f8.u32l;
    // 0x8010948C: swc1        $f6, 0x378($s4)
    MEM_W(0X378, ctx->r20) = ctx->f6.u32l;
    // 0x80109490: swc1        $f10, 0x37C($s4)
    MEM_W(0X37C, ctx->r20) = ctx->f10.u32l;
L_80109494:
    // 0x80109494: lw          $s5, 0x0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X0);
L_80109498:
    // 0x80109498: bnel        $s5, $zero, L_801090A0
    if (ctx->r21 != 0) {
        // 0x8010949C: lw          $v1, 0x24($s5)
        ctx->r3 = MEM_W(ctx->r21, 0X24);
            goto L_801090A0;
    }
    goto skip_17;
    // 0x8010949C: lw          $v1, 0x24($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X24);
    skip_17:
    // 0x801094A0: lwc1        $f4, 0x374($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X374);
L_801094A4:
    // 0x801094A4: lwc1        $f8, 0x18C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x801094A8: lwc1        $f10, 0x378($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X378);
    // 0x801094AC: lbu         $v0, 0xEF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XEF);
    // 0x801094B0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801094B4: lwc1        $f4, 0x190($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X190);
    // 0x801094B8: andi        $t0, $v0, 0x3F
    ctx->r8 = ctx->r2 & 0X3F;
    // 0x801094BC: sra         $t1, $v0, 6
    ctx->r9 = S32(SIGNED(ctx->r2) >> 6);
    // 0x801094C0: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801094C4: swc1        $f6, 0x368($s4)
    MEM_W(0X368, ctx->r20) = ctx->f6.u32l;
    // 0x801094C8: lwc1        $f6, 0x37C($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X37C);
    // 0x801094CC: lwc1        $f10, 0x194($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X194);
    // 0x801094D0: swc1        $f8, 0x36C($s4)
    MEM_W(0X36C, ctx->r20) = ctx->f8.u32l;
    // 0x801094D4: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x801094D8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801094DC: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x801094E0: swc1        $f8, 0x35C($s4)
    MEM_W(0X35C, ctx->r20) = ctx->f8.u32l;
    // 0x801094E4: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x801094E8: swc1        $f4, 0x370($s4)
    MEM_W(0X370, ctx->r20) = ctx->f4.u32l;
    // 0x801094EC: swc1        $f6, 0x360($s4)
    MEM_W(0X360, ctx->r20) = ctx->f6.u32l;
    // 0x801094F0: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x801094F4: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x801094F8: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x801094FC: sb          $t0, 0x35A($s4)
    MEM_B(0X35A, ctx->r20) = ctx->r8;
    // 0x80109500: sb          $t1, 0x35B($s4)
    MEM_B(0X35B, ctx->r20) = ctx->r9;
    // 0x80109504: swc1        $f10, 0x364($s4)
    MEM_W(0X364, ctx->r20) = ctx->f10.u32l;
    // 0x80109508: swc1        $f4, 0x380($s4)
    MEM_W(0X380, ctx->r20) = ctx->f4.u32l;
    // 0x8010950C: swc1        $f8, 0x384($s4)
    MEM_W(0X384, ctx->r20) = ctx->f8.u32l;
    // 0x80109510: swc1        $f6, 0x388($s4)
    MEM_W(0X388, ctx->r20) = ctx->f6.u32l;
    // 0x80109514: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80109518:
    // 0x80109518: lw          $v0, 0x17C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X17C);
    // 0x8010951C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80109520: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80109524: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80109528: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010952C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80109530: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80109534: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80109538: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8010953C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80109540: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80109544: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80109548: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8010954C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80109550: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80109554: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80109558: jr          $ra
    // 0x8010955C: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x8010955C: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80109560(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80109560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109560: addiu       $sp, $sp, -0x1D0
    ctx->r29 = ADD32(ctx->r29, -0X1D0);
    // 0x80109564: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80109568: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8010956C: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x80109570: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80109574: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80109578: lw          $t2, 0x50($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X50);
    // 0x8010957C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80109580: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80109584: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80109588: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8010958C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80109590: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80109594: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80109598: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8010959C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801095A0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x801095A4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x801095A8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801095AC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801095B0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801095B4: swc1        $f12, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->f12.u32l;
    // 0x801095B8: swc1        $f14, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f14.u32l;
    // 0x801095BC: sw          $a2, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r6;
    // 0x801095C0: sw          $zero, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = 0;
    // 0x801095C4: sb          $zero, 0x35A($s2)
    MEM_B(0X35A, ctx->r18) = 0;
    // 0x801095C8: sb          $zero, 0x35B($s2)
    MEM_B(0X35B, ctx->r18) = 0;
    // 0x801095CC: sw          $zero, 0x38C($s2)
    MEM_W(0X38C, ctx->r18) = 0;
    // 0x801095D0: swc1        $f20, 0x35C($s2)
    MEM_W(0X35C, ctx->r18) = ctx->f20.u32l;
    // 0x801095D4: swc1        $f20, 0x360($s2)
    MEM_W(0X360, ctx->r18) = ctx->f20.u32l;
    // 0x801095D8: swc1        $f20, 0x364($s2)
    MEM_W(0X364, ctx->r18) = ctx->f20.u32l;
    // 0x801095DC: swc1        $f20, 0x368($s2)
    MEM_W(0X368, ctx->r18) = ctx->f20.u32l;
    // 0x801095E0: swc1        $f20, 0x36C($s2)
    MEM_W(0X36C, ctx->r18) = ctx->f20.u32l;
    // 0x801095E4: swc1        $f20, 0x370($s2)
    MEM_W(0X370, ctx->r18) = ctx->f20.u32l;
    // 0x801095E8: swc1        $f20, 0x374($s2)
    MEM_W(0X374, ctx->r18) = ctx->f20.u32l;
    // 0x801095EC: swc1        $f20, 0x378($s2)
    MEM_W(0X378, ctx->r18) = ctx->f20.u32l;
    // 0x801095F0: swc1        $f20, 0x37C($s2)
    MEM_W(0X37C, ctx->r18) = ctx->f20.u32l;
    // 0x801095F4: swc1        $f20, 0x380($s2)
    MEM_W(0X380, ctx->r18) = ctx->f20.u32l;
    // 0x801095F8: swc1        $f20, 0x384($s2)
    MEM_W(0X384, ctx->r18) = ctx->f20.u32l;
    // 0x801095FC: swc1        $f20, 0x388($s2)
    MEM_W(0X388, ctx->r18) = ctx->f20.u32l;
    // 0x80109600: lw          $s1, 0x8($t2)
    ctx->r17 = MEM_W(ctx->r10, 0X8);
    // 0x80109604: addiu       $s7, $sp, 0x12C
    ctx->r23 = ADD32(ctx->r29, 0X12C);
    // 0x80109608: addiu       $fp, $sp, 0x128
    ctx->r30 = ADD32(ctx->r29, 0X128);
    // 0x8010960C: beq         $s1, $zero, L_8010A160
    if (ctx->r17 == 0) {
        // 0x80109610: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8010A160;
    }
    // 0x80109610: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80109614: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80109618: addiu       $s6, $sp, 0x194
    ctx->r22 = ADD32(ctx->r29, 0X194);
    // 0x8010961C: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
L_80109620:
    // 0x80109620: beql        $v1, $zero, L_8010A158
    if (ctx->r3 == 0) {
        // 0x80109624: lw          $s1, 0x0($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X0);
            goto L_8010A158;
    }
    goto skip_0;
    // 0x80109624: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80109628: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x8010962C: beql        $t3, $zero, L_8010A158
    if (ctx->r11 == 0) {
        // 0x80109630: lw          $s1, 0x0($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X0);
            goto L_8010A158;
    }
    goto skip_1;
    // 0x80109630: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80109634: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x80109638: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x8010963C: beql        $t5, $zero, L_8010A158
    if (ctx->r13 == 0) {
        // 0x80109640: lw          $s1, 0x0($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X0);
            goto L_8010A158;
    }
    goto skip_2;
    // 0x80109640: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80109644: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x80109648: beql        $v0, $zero, L_8010967C
    if (ctx->r2 == 0) {
        // 0x8010964C: lw          $v0, 0x2C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X2C);
            goto L_8010967C;
    }
    goto skip_3;
    // 0x8010964C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    skip_3:
    // 0x80109650: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80109654: swc1        $f8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f8.u32l;
    // 0x80109658: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010965C: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x80109660: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80109664: swc1        $f10, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f10.u32l;
    // 0x80109668: lh          $s3, 0x10($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X10);
    // 0x8010966C: lh          $s4, 0x12($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X12);
    // 0x80109670: b           L_801096A0
    // 0x80109674: lh          $s5, 0x14($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X14);
        goto L_801096A0;
    // 0x80109674: lh          $s5, 0x14($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X14);
    // 0x80109678: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_8010967C:
    // 0x8010967C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80109680: swc1        $f4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f4.u32l;
    // 0x80109684: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80109688: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x8010968C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80109690: swc1        $f6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f6.u32l;
    // 0x80109694: lh          $s3, 0x10($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X10);
    // 0x80109698: lh          $s4, 0x12($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X12);
    // 0x8010969C: lh          $s5, 0x14($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X14);
L_801096A0:
    // 0x801096A0: lwc1        $f14, 0x78($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X78);
    // 0x801096A4: lwc1        $f10, 0x1D0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x801096A8: lwc1        $f16, 0x7C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x801096AC: lwc1        $f4, 0x1D4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x801096B0: sub.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801096B4: lwc1        $f18, 0x80($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X80);
    // 0x801096B8: lwc1        $f8, 0x1D8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x801096BC: sub.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801096C0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x801096C4: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x801096C8: bc1tl       L_801096D8
    if (c1cs) {
        // 0x801096CC: c.lt.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
            goto L_801096D8;
    }
    goto skip_4;
    // 0x801096CC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    skip_4:
    // 0x801096D0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x801096D4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
L_801096D8:
    // 0x801096D8: nop

    // 0x801096DC: bc1tl       L_801096EC
    if (c1cs) {
        // 0x801096E0: c.lt.s      $f20, $f12
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
            goto L_801096EC;
    }
    goto skip_5;
    // 0x801096E0: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    skip_5:
    // 0x801096E4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x801096E8: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
L_801096EC:
    // 0x801096EC: nop

    // 0x801096F0: bc1tl       L_80109700
    if (c1cs) {
        // 0x801096F4: c.lt.s      $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
            goto L_80109700;
    }
    goto skip_6;
    // 0x801096F4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    skip_6:
    // 0x801096F8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801096FC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_80109700:
    // 0x80109700: nop

    // 0x80109704: bc1fl       L_8010A128
    if (!c1cs) {
        // 0x80109708: lwc1        $f6, 0x108($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
            goto L_8010A128;
    }
    goto skip_7;
    // 0x80109708: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    skip_7:
    // 0x8010970C: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x80109710: nop

    // 0x80109714: bc1fl       L_8010A128
    if (!c1cs) {
        // 0x80109718: lwc1        $f6, 0x108($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
            goto L_8010A128;
    }
    goto skip_8;
    // 0x80109718: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    skip_8:
    // 0x8010971C: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    // 0x80109720: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80109724: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80109728: bc1fl       L_8010A128
    if (!c1cs) {
        // 0x8010972C: lwc1        $f6, 0x108($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
            goto L_8010A128;
    }
    goto skip_9;
    // 0x8010972C: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    skip_9:
    // 0x80109730: sub.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80109734: lh          $v0, 0x84($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X84);
    // 0x80109738: lh          $t7, 0x86($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X86);
    // 0x8010973C: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80109740: lwc1        $f4, 0x100($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80109744: subu        $t6, $v0, $s3
    ctx->r14 = SUB32(ctx->r2, ctx->r19);
    // 0x80109748: subu        $t8, $t7, $s4
    ctx->r24 = SUB32(ctx->r15, ctx->r20);
    // 0x8010974C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80109750: lh          $t9, 0x88($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X88);
    // 0x80109754: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80109758: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8010975C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80109760: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x80109764: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80109768: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010976C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80109770: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80109774: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80109778: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010977C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80109780: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80109784: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80109788: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010978C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80109790: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x80109794: nop

    // 0x80109798: bc1tl       L_8010A128
    if (c1cs) {
        // 0x8010979C: lwc1        $f6, 0x108($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
            goto L_8010A128;
    }
    goto skip_10;
    // 0x8010979C: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    skip_10:
    // 0x801097A0: swc1        $f14, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f14.u32l;
    // 0x801097A4: swc1        $f16, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f16.u32l;
    // 0x801097A8: jal         0x8001EAD0
    // 0x801097AC: swc1        $f18, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801097AC: swc1        $f18, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801097B0: lh          $a0, 0x84($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X84);
    // 0x801097B4: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x801097B8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x801097BC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801097C0: jal         0x8001EB64
    // 0x801097C4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801097C4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801097C8: lh          $a0, 0x86($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X86);
    // 0x801097CC: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x801097D0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x801097D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801097D8: jal         0x8001EAD0
    // 0x801097DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801097DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x801097E0: lh          $a0, 0x86($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X86);
    // 0x801097E4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801097E8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x801097EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801097F0: jal         0x8001EB64
    // 0x801097F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801097F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x801097F8: lh          $a0, 0x88($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X88);
    // 0x801097FC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80109800: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80109804: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80109808: jal         0x8001EAD0
    // 0x8010980C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8010980C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x80109810: lh          $a0, 0x88($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X88);
    // 0x80109814: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80109818: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8010981C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80109820: jal         0x8001EB64
    // 0x80109824: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80109824: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x80109828: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8010982C: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x80109830: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80109834: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80109838: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010983C: mul.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80109840: nop

    // 0x80109844: mul.s       $f6, $f20, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80109848: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x8010984C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x80109850: mul.s       $f8, $f2, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80109854: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109858: mul.s       $f14, $f20, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010985C: nop

    // 0x80109860: mul.s       $f6, $f0, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80109864: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x80109868: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8010986C: mul.s       $f8, $f14, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x80109870: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80109874: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x80109878: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x8010987C: mul.s       $f8, $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80109880: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x80109884: mul.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x80109888: nop

    // 0x8010988C: mul.s       $f4, $f2, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x80109890: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x80109894: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80109898: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8010989C: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801098A0: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x801098A4: nop

    // 0x801098A8: mul.s       $f6, $f14, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x801098AC: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x801098B0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801098B4: lwc1        $f6, 0x1D0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x801098B8: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801098BC: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x801098C0: lwc1        $f6, 0x1D4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x801098C4: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x801098C8: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801098CC: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x801098D0: lwc1        $f6, 0x1D8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x801098D4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801098D8: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801098DC: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801098E0: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x801098E4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801098E8: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x801098EC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801098F0: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801098F4: swc1        $f6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f6.u32l;
    // 0x801098F8: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801098FC: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80109900: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80109904: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109908: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8010990C: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80109910: add.s       $f30, $f6, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109914: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80109918: nop

    // 0x8010991C: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80109920: nop

    // 0x80109924: mul.s       $f4, $f22, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x80109928: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010992C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80109930: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80109934: jal         0x8001EAD0
    // 0x80109938: swc1        $f8, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x80109938: swc1        $f8, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8010993C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80109940: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80109944: jal         0x8001EB64
    // 0x80109948: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x80109948: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x8010994C: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80109950: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80109954: jal         0x8001EAD0
    // 0x80109958: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x80109958: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_8:
    // 0x8010995C: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80109960: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80109964: jal         0x8001EB64
    // 0x80109968: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x80109968: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_9:
    // 0x8010996C: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80109970: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80109974: jal         0x8001EAD0
    // 0x80109978: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_10;
    // 0x80109978: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_10:
    // 0x8010997C: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80109980: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80109984: jal         0x8001EB64
    // 0x80109988: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_11;
    // 0x80109988: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
    // 0x8010998C: mul.s       $f2, $f26, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x80109990: lwc1        $f12, 0x138($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80109994: lwc1        $f10, 0x130($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X130);
    // 0x80109998: mul.s       $f14, $f28, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x8010999C: swc1        $f12, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f12.u32l;
    // 0x801099A0: negu        $s0, $s3
    ctx->r16 = SUB32(0, ctx->r19);
    // 0x801099A4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801099A8: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x801099AC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801099B0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801099B4: mul.s       $f8, $f28, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x801099B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801099BC: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801099C0: mul.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x801099C4: nop

    // 0x801099C8: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x801099CC: nop

    // 0x801099D0: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801099D4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801099D8: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x801099DC: nop

    // 0x801099E0: mul.s       $f4, $f26, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x801099E4: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801099E8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801099EC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801099F0: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x801099F4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801099F8: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x801099FC: nop

    // 0x80109A00: mul.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80109A04: swc1        $f4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f4.u32l;
    // 0x80109A08: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80109A0C: mul.s       $f8, $f4, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80109A10: nop

    // 0x80109A14: mul.s       $f6, $f22, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80109A18: nop

    // 0x80109A1C: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80109A20: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109A24: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80109A28: nop

    // 0x80109A2C: mul.s       $f8, $f26, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80109A30: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80109A34: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80109A38: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109A3C: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80109A40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109A44: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80109A48: neg.s       $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = -ctx->f24.fl;
    // 0x80109A4C: swc1        $f8, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f8.u32l;
    // 0x80109A50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80109A54: nop

    // 0x80109A58: mul.s       $f4, $f26, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x80109A5C: nop

    // 0x80109A60: mul.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80109A64: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80109A68: mul.s       $f8, $f28, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x80109A6C: nop

    // 0x80109A70: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80109A74: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80109A78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109A7C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80109A80: jal         0x8001EAD0
    // 0x80109A84: swc1        $f4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x80109A84: swc1        $f4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80109A88: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80109A8C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80109A90: jal         0x8001EB64
    // 0x80109A94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x80109A94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_13:
    // 0x80109A98: negu        $s0, $s4
    ctx->r16 = SUB32(0, ctx->r20);
    // 0x80109A9C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80109AA0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80109AA4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80109AA8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80109AAC: jal         0x8001EAD0
    // 0x80109AB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_14;
    // 0x80109AB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_14:
    // 0x80109AB4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80109AB8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80109ABC: jal         0x8001EB64
    // 0x80109AC0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_15;
    // 0x80109AC0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_15:
    // 0x80109AC4: negu        $s0, $s5
    ctx->r16 = SUB32(0, ctx->r21);
    // 0x80109AC8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80109ACC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80109AD0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80109AD4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80109AD8: jal         0x8001EAD0
    // 0x80109ADC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_16;
    // 0x80109ADC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_16:
    // 0x80109AE0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80109AE4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80109AE8: jal         0x8001EB64
    // 0x80109AEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_17;
    // 0x80109AEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_17:
    // 0x80109AF0: mul.s       $f12, $f0, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80109AF4: lw          $t1, 0x74($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X74);
    // 0x80109AF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80109AFC: mul.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80109B00: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x80109B04: mul.s       $f6, $f20, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80109B08: nop

    // 0x80109B0C: mul.s       $f8, $f2, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80109B10: nop

    // 0x80109B14: mul.s       $f14, $f20, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80109B18: nop

    // 0x80109B1C: mul.s       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80109B20: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109B24: mul.s       $f4, $f14, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x80109B28: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x80109B2C: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x80109B30: nop

    // 0x80109B34: mul.s       $f8, $f2, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x80109B38: sub.s       $f30, $f10, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80109B3C: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80109B40: swc1        $f30, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f30.u32l;
    // 0x80109B44: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80109B48: mul.s       $f6, $f14, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x80109B4C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80109B50: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x80109B54: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x80109B58: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80109B5C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109B60: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80109B64: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80109B68: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x80109B6C: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x80109B70: mul.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80109B74: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80109B78: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80109B7C: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x80109B80: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x80109B84: lwc1        $f8, 0x144($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X144);
    // 0x80109B88: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x80109B8C: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80109B90: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80109B94: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80109B98: mul.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80109B9C: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80109BA0: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80109BA4: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80109BA8: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80109BAC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80109BB0: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109BB4: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80109BB8: mul.s       $f10, $f24, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x80109BBC: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109BC0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80109BC4: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80109BC8: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80109BCC: sub.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80109BD0: sub.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80109BD4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109BD8: lwc1        $f8, 0x1D0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x80109BDC: swc1        $f4, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f4.u32l;
    // 0x80109BE0: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80109BE4: lwc1        $f8, 0x1D4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x80109BE8: mul.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80109BEC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109BF0: lwc1        $f8, 0x1D8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x80109BF4: mul.s       $f8, $f24, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80109BF8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109BFC: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80109C00: sub.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80109C04: sub.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80109C08: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109C0C: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x80109C10: swc1        $f4, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f4.u32l;
    // 0x80109C14: mul.s       $f0, $f8, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80109C18: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80109C1C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x80109C20: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80109C24: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80109C28: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80109C2C: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x80109C30: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80109C34: nop

    // 0x80109C38: mul.s       $f4, $f6, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x80109C3C: sub.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80109C40: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80109C44: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80109C48: lwc1        $f8, 0x1D0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x80109C4C: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80109C50: lwc1        $f8, 0x1D4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x80109C54: mul.s       $f8, $f30, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f8.fl);
    // 0x80109C58: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109C5C: lwc1        $f8, 0x1D8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x80109C60: mul.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80109C64: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109C68: mul.s       $f2, $f22, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x80109C6C: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80109C70: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80109C74: swc1        $f8, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f8.u32l;
    // 0x80109C78: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80109C7C: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x80109C80: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80109C84: nop

    // 0x80109C88: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80109C8C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80109C90: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80109C94: lwc1        $f4, 0x1D0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x80109C98: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80109C9C: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80109CA0: lwc1        $f10, 0x1D4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x80109CA4: mul.s       $f6, $f20, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80109CA8: lwc1        $f10, 0x1D8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x80109CAC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80109CB0: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80109CB4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109CB8: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80109CBC: lwc1        $f4, 0x138($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80109CC0: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x80109CC4: mul.s       $f24, $f0, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80109CC8: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80109CCC: swc1        $f4, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->f4.u32l;
    // 0x80109CD0: swc1        $f10, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f10.u32l;
    // 0x80109CD4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80109CD8: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80109CDC: mul.s       $f8, $f30, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f4.fl);
    // 0x80109CE0: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80109CE4: add.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x80109CE8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80109CEC: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80109CF0: swc1        $f10, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->f10.u32l;
    // 0x80109CF4: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80109CF8: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x80109CFC: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80109D00: nop

    // 0x80109D04: mul.s       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80109D08: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80109D0C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80109D10: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80109D14: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80109D18: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80109D1C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80109D20: lwc1        $f8, 0x124($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80109D24: swc1        $f6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f6.u32l;
    // 0x80109D28: swc1        $f4, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f4.u32l;
    // 0x80109D2C: swc1        $f10, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->f10.u32l;
    // 0x80109D30: jal         0x8010ACF8
    // 0x80109D34: swc1        $f8, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8010ACF8)(rdram, ctx);
        goto after_18;
    // 0x80109D34: swc1        $f8, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x80109D38: beq         $v0, $zero, L_8010A124
    if (ctx->r2 == 0) {
        // 0x80109D3C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8010A124;
    }
    // 0x80109D3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80109D40: lbu         $v0, 0x1B0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B0);
    // 0x80109D44: lwc1        $f10, 0x1C0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C0);
    // 0x80109D48: sw          $t2, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r10;
    // 0x80109D4C: andi        $t3, $v0, 0x3F
    ctx->r11 = ctx->r2 & 0X3F;
    // 0x80109D50: sra         $t4, $v0, 6
    ctx->r12 = S32(SIGNED(ctx->r2) >> 6);
    // 0x80109D54: sb          $t3, 0x35A($s2)
    MEM_B(0X35A, ctx->r18) = ctx->r11;
    // 0x80109D58: sb          $t4, 0x35B($s2)
    MEM_B(0X35B, ctx->r18) = ctx->r12;
    // 0x80109D5C: lwc1        $f22, 0x1B8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1B8);
    // 0x80109D60: lwc1        $f30, 0x1BC($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x80109D64: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80109D68: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80109D6C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80109D70: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    // 0x80109D74: jal         0x8010B634
    // 0x80109D78: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010B634)(rdram, ctx);
        goto after_19;
    // 0x80109D78: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x80109D7C: lwc1        $f2, 0x144($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X144);
    // 0x80109D80: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80109D84: lwc1        $f0, 0x140($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80109D88: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80109D8C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80109D90: lwc1        $f20, 0xA4($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80109D94: lwc1        $f26, 0x104($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80109D98: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80109D9C: lwc1        $f6, 0x138($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80109DA0: lw          $t5, 0x74($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X74);
    // 0x80109DA4: lwc1        $f14, 0xD4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80109DA8: swc1        $f6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f6.u32l;
    // 0x80109DAC: lwc1        $f12, 0xD0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80109DB0: addiu       $a0, $sp, 0x160
    ctx->r4 = ADD32(ctx->r29, 0X160);
    // 0x80109DB4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109DB8: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80109DBC: sw          $t5, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r13;
    // 0x80109DC0: mul.s       $f8, $f26, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x80109DC4: add.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x80109DC8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80109DCC: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80109DD0: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80109DD4: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80109DD8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109DDC: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80109DE0: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
    // 0x80109DE4: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80109DE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109DEC: mul.s       $f6, $f20, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80109DF0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80109DF4: mul.s       $f8, $f26, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f12.fl);
    // 0x80109DF8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80109DFC: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80109E00: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80109E04: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80109E08: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80109E0C: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80109E10: lwc1        $f8, 0x124($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80109E14: swc1        $f6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f6.u32l;
    // 0x80109E18: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x80109E1C: swc1        $f4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f4.u32l;
    // 0x80109E20: jal         0x8010ACF8
    // 0x80109E24: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8010ACF8)(rdram, ctx);
        goto after_20;
    // 0x80109E24: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x80109E28: beq         $v0, $zero, L_80109E64
    if (ctx->r2 == 0) {
        // 0x80109E2C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80109E64;
    }
    // 0x80109E2C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80109E30: lbu         $v0, 0x17C($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X17C);
    // 0x80109E34: lwc1        $f10, 0x18C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x80109E38: lwc1        $f22, 0x184($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X184);
    // 0x80109E3C: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x80109E40: sra         $t7, $v0, 6
    ctx->r15 = S32(SIGNED(ctx->r2) >> 6);
    // 0x80109E44: sb          $t6, 0x35A($s2)
    MEM_B(0X35A, ctx->r18) = ctx->r14;
    // 0x80109E48: sb          $t7, 0x35B($s2)
    MEM_B(0X35B, ctx->r18) = ctx->r15;
    // 0x80109E4C: lwc1        $f30, 0x188($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X188);
    // 0x80109E50: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80109E54: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80109E58: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    // 0x80109E5C: jal         0x8010B4D8
    // 0x80109E60: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010B4D8)(rdram, ctx);
        goto after_21;
    // 0x80109E60: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    after_21:
L_80109E64:
    // 0x80109E64: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80109E68: jal         0x8001EAD0
    // 0x80109E6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_22;
    // 0x80109E6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_22:
    // 0x80109E70: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80109E74: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80109E78: jal         0x8001EB64
    // 0x80109E7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_23;
    // 0x80109E7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_23:
    // 0x80109E80: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80109E84: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80109E88: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80109E8C: swc1        $f22, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f22.u32l;
    // 0x80109E90: jal         0x8001EAD0
    // 0x80109E94: swc1        $f30, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f30.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_24;
    // 0x80109E94: swc1        $f30, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f30.u32l;
    after_24:
    // 0x80109E98: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80109E9C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80109EA0: jal         0x8001EB64
    // 0x80109EA4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_25;
    // 0x80109EA4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_25:
    // 0x80109EA8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80109EAC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80109EB0: jal         0x8001EAD0
    // 0x80109EB4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_26;
    // 0x80109EB4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_26:
    // 0x80109EB8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80109EBC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80109EC0: jal         0x8001EB64
    // 0x80109EC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_27;
    // 0x80109EC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_27:
    // 0x80109EC8: mul.s       $f16, $f22, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80109ECC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80109ED0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80109ED4: mul.s       $f2, $f26, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x80109ED8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80109EDC: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80109EE0: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    // 0x80109EE4: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
    // 0x80109EE8: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80109EEC: nop

    // 0x80109EF0: mul.s       $f4, $f28, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x80109EF4: nop

    // 0x80109EF8: mul.s       $f14, $f28, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x80109EFC: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80109F00: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80109F04: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x80109F08: mul.s       $f10, $f26, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x80109F0C: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x80109F10: lwc1        $f18, 0x124($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80109F14: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80109F18: nop

    // 0x80109F1C: mul.s       $f4, $f28, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80109F20: add.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80109F24: mul.s       $f10, $f14, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80109F28: swc1        $f30, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f30.u32l;
    // 0x80109F2C: swc1        $f30, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f30.u32l;
    // 0x80109F30: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80109F34: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80109F38: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80109F3C: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x80109F40: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x80109F44: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80109F48: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80109F4C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80109F50: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80109F54: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80109F58: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80109F5C: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x80109F60: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80109F64: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x80109F68: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80109F6C: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80109F70: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109F74: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80109F78: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80109F7C: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109F80: lwc1        $f10, 0x108($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80109F84: mul.s       $f30, $f22, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f30.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80109F88: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109F8C: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80109F90: swc1        $f4, -0x409C($at)
    MEM_W(-0X409C, ctx->r1) = ctx->f4.u32l;
    // 0x80109F94: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80109F98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80109F9C: mul.s       $f10, $f30, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f8.fl);
    // 0x80109FA0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109FA4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80109FA8: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80109FAC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109FB0: mul.s       $f14, $f26, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x80109FB4: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80109FB8: mul.s       $f2, $f28, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x80109FBC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80109FC0: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80109FC4: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x80109FC8: swc1        $f10, -0x4098($at)
    MEM_W(-0X4098, ctx->r1) = ctx->f10.u32l;
    // 0x80109FCC: mul.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80109FD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80109FD4: swc1        $f2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f2.u32l;
    // 0x80109FD8: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80109FDC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109FE0: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80109FE4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80109FE8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80109FEC: lwc1        $f4, 0x1D0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x80109FF0: swc1        $f8, -0x4094($at)
    MEM_W(-0X4094, ctx->r1) = ctx->f8.u32l;
    // 0x80109FF4: lwc1        $f6, 0x374($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X374);
    // 0x80109FF8: lwc1        $f8, 0x378($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X378);
    // 0x80109FFC: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8010A000: lwc1        $f6, 0x1D4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x8010A004: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010A008: swc1        $f10, 0x368($s2)
    MEM_W(0X368, ctx->r18) = ctx->f10.u32l;
    // 0x8010A00C: lwc1        $f10, 0x37C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X37C);
    // 0x8010A010: lwc1        $f8, 0x1D8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x8010A014: swc1        $f4, 0x36C($s2)
    MEM_W(0X36C, ctx->r18) = ctx->f4.u32l;
    // 0x8010A018: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010A01C: jal         0x8010B4D8
    // 0x8010A020: swc1        $f6, 0x370($s2)
    MEM_W(0X370, ctx->r18) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010B4D8)(rdram, ctx);
        goto after_28;
    // 0x8010A020: swc1        $f6, 0x370($s2)
    MEM_W(0X370, ctx->r18) = ctx->f6.u32l;
    after_28:
    // 0x8010A024: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8010A028: lwc1        $f20, 0x12C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010A02C: lwc1        $f12, 0x128($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010A030: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010A034: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8010A038: lwc1        $f18, 0x124($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8010A03C: lwc1        $f24, 0xE0($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010A040: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8010A044: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010A048: lwc1        $f22, 0xD4($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8010A04C: lwc1        $f0, 0xA0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8010A050: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010A054: lwc1        $f2, 0xB8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8010A058: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010A05C: mul.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x8010A060: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010A064: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8010A068: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010A06C: mul.s       $f8, $f30, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f20.fl);
    // 0x8010A070: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8010A074: swc1        $f4, -0x4090($at)
    MEM_W(-0X4090, ctx->r1) = ctx->f4.u32l;
    // 0x8010A078: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8010A07C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010A080: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010A084: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8010A088: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A08C: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8010A090: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010A094: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010A098: lwc1        $f20, 0xF4($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8010A09C: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8010A0A0: swc1        $f8, -0x408C($at)
    MEM_W(-0X408C, ctx->r1) = ctx->f8.u32l;
    // 0x8010A0A4: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8010A0A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010A0AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010A0B0: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8010A0B4: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8010A0B8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010A0BC: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8010A0C0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A0C4: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8010A0C8: nop

    // 0x8010A0CC: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010A0D0: swc1        $f4, -0x4088($at)
    MEM_W(-0X4088, ctx->r1) = ctx->f4.u32l;
    // 0x8010A0D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010A0D8: mul.s       $f10, $f24, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f12.fl);
    // 0x8010A0DC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A0E0: mul.s       $f8, $f30, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f20.fl);
    // 0x8010A0E4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010A0E8: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8010A0EC: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8010A0F0: swc1        $f6, 0x35C($s2)
    MEM_W(0X35C, ctx->r18) = ctx->f6.u32l;
    // 0x8010A0F4: mul.s       $f4, $f22, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8010A0F8: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010A0FC: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010A100: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010A104: mul.s       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8010A108: swc1        $f8, -0x40B0($at)
    MEM_W(-0X40B0, ctx->r1) = ctx->f8.u32l;
    // 0x8010A10C: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8010A110: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010A114: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010A118: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010A11C: swc1        $f10, -0x40AC($at)
    MEM_W(-0X40AC, ctx->r1) = ctx->f10.u32l;
    // 0x8010A120: sw          $s1, 0x38C($s2)
    MEM_W(0X38C, ctx->r18) = ctx->r17;
L_8010A124:
    // 0x8010A124: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
L_8010A128:
    // 0x8010A128: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8010A12C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8010A130: swc1        $f6, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f6.u32l;
    // 0x8010A134: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8010A138: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8010A13C: swc1        $f4, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f4.u32l;
    // 0x8010A140: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8010A144: sh          $s3, 0x84($s1)
    MEM_H(0X84, ctx->r17) = ctx->r19;
    // 0x8010A148: sh          $s4, 0x86($s1)
    MEM_H(0X86, ctx->r17) = ctx->r20;
    // 0x8010A14C: sh          $s5, 0x88($s1)
    MEM_H(0X88, ctx->r17) = ctx->r21;
    // 0x8010A150: swc1        $f8, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f8.u32l;
    // 0x8010A154: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
L_8010A158:
    // 0x8010A158: bnel        $s1, $zero, L_80109620
    if (ctx->r17 != 0) {
        // 0x8010A15C: lw          $v1, 0x24($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X24);
            goto L_80109620;
    }
    goto skip_11;
    // 0x8010A15C: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    skip_11:
L_8010A160:
    // 0x8010A160: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8010A164: lw          $v0, 0x1CC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1CC);
    // 0x8010A168: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010A16C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010A170: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010A174: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010A178: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8010A17C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8010A180: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8010A184: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8010A188: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8010A18C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8010A190: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8010A194: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8010A198: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8010A19C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8010A1A0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8010A1A4: jr          $ra
    // 0x8010A1A8: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    return;
    // 0x8010A1A8: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010a1ac(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010a1ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A1AC: addiu       $sp, $sp, -0x188
    ctx->r29 = ADD32(ctx->r29, -0X188);
    // 0x8010A1B0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8010A1B4: lw          $t0, -0x43C0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X43C0);
    // 0x8010A1B8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8010A1BC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8010A1C0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8010A1C4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8010A1C8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8010A1CC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8010A1D0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8010A1D4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8010A1D8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8010A1DC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8010A1E0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8010A1E4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010A1E8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010A1EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010A1F0: sw          $a0, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r4;
    // 0x8010A1F4: sw          $a1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r5;
    // 0x8010A1F8: sw          $a2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r6;
    // 0x8010A1FC: sw          $a3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r7;
    // 0x8010A200: lw          $s3, 0x8($t0)
    ctx->r19 = MEM_W(ctx->r8, 0X8);
    // 0x8010A204: addiu       $s5, $sp, 0x14C
    ctx->r21 = ADD32(ctx->r29, 0X14C);
    // 0x8010A208: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8010A20C: beql        $s3, $zero, L_8010A660
    if (ctx->r19 == 0) {
        // 0x8010A210: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A660;
    }
    goto skip_0;
    // 0x8010A210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8010A214: lw          $v1, 0x24($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X24);
L_8010A218:
    // 0x8010A218: beql        $v1, $zero, L_8010A64C
    if (ctx->r3 == 0) {
        // 0x8010A21C: lw          $s3, 0x0($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X0);
            goto L_8010A64C;
    }
    goto skip_1;
    // 0x8010A21C: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x8010A220: lw          $a0, 0x74($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X74);
    // 0x8010A224: beql        $a0, $zero, L_8010A64C
    if (ctx->r4 == 0) {
        // 0x8010A228: lw          $s3, 0x0($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X0);
            goto L_8010A64C;
    }
    goto skip_2;
    // 0x8010A228: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x8010A22C: lw          $t1, 0x2C($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X2C);
    // 0x8010A230: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x8010A234: beql        $t2, $zero, L_8010A64C
    if (ctx->r10 == 0) {
        // 0x8010A238: lw          $s3, 0x0($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X0);
            goto L_8010A64C;
    }
    goto skip_3;
    // 0x8010A238: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x8010A23C: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8010A240: lbu         $s4, 0x18B($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0X18B);
    // 0x8010A244: beq         $v0, $zero, L_8010A274
    if (ctx->r2 == 0) {
        // 0x8010A248: andi        $s4, $s4, 0x11
        ctx->r20 = ctx->r20 & 0X11;
            goto L_8010A274;
    }
    // 0x8010A248: andi        $s4, $s4, 0x11
    ctx->r20 = ctx->r20 & 0X11;
    // 0x8010A24C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010A250: swc1        $f6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f6.u32l;
    // 0x8010A254: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010A258: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
    // 0x8010A25C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8010A260: swc1        $f10, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f10.u32l;
    // 0x8010A264: lh          $a1, 0x10($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X10);
    // 0x8010A268: lh          $s1, 0x12($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X12);
    // 0x8010A26C: b           L_8010A29C
    // 0x8010A270: lh          $s2, 0x14($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X14);
        goto L_8010A29C;
    // 0x8010A270: lh          $s2, 0x14($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X14);
L_8010A274:
    // 0x8010A274: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8010A278: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010A27C: swc1        $f8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f8.u32l;
    // 0x8010A280: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010A284: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x8010A288: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8010A28C: swc1        $f4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f4.u32l;
    // 0x8010A290: lh          $a1, 0x10($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X10);
    // 0x8010A294: lh          $s1, 0x12($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X12);
    // 0x8010A298: lh          $s2, 0x14($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X14);
L_8010A29C:
    // 0x8010A29C: bne         $a1, $zero, L_8010A308
    if (ctx->r5 != 0) {
        // 0x8010A2A0: sw          $a0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r4;
            goto L_8010A308;
    }
    // 0x8010A2A0: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
    // 0x8010A2A4: bnel        $s1, $zero, L_8010A30C
    if (ctx->r17 != 0) {
        // 0x8010A2A8: negu        $s0, $a1
        ctx->r16 = SUB32(0, ctx->r5);
            goto L_8010A30C;
    }
    goto skip_4;
    // 0x8010A2A8: negu        $s0, $a1
    ctx->r16 = SUB32(0, ctx->r5);
    skip_4:
    // 0x8010A2AC: bne         $s2, $zero, L_8010A308
    if (ctx->r18 != 0) {
        // 0x8010A2B0: lwc1        $f10, 0x18C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X18C);
            goto L_8010A308;
    }
    // 0x8010A2B0: lwc1        $f10, 0x18C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x8010A2B4: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8010A2B8: lwc1        $f4, 0x190($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X190);
    // 0x8010A2BC: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010A2C0: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8010A2C4: swc1        $f6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f6.u32l;
    // 0x8010A2C8: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010A2CC: lwc1        $f4, 0x194($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X194);
    // 0x8010A2D0: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x8010A2D4: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8010A2D8: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010A2DC: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x8010A2E0: lwc1        $f4, 0x198($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X198);
    // 0x8010A2E4: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8010A2E8: lwc1        $f8, 0x19C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x8010A2EC: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    // 0x8010A2F0: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8010A2F4: lwc1        $f8, 0x1A0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x8010A2F8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010A2FC: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8010A300: b           L_8010A5A8
    // 0x8010A304: swc1        $f10, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f10.u32l;
        goto L_8010A5A8;
    // 0x8010A304: swc1        $f10, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f10.u32l;
L_8010A308:
    // 0x8010A308: negu        $s0, $a1
    ctx->r16 = SUB32(0, ctx->r5);
L_8010A30C:
    // 0x8010A30C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8010A310: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010A314: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8010A318: jal         0x8001EAD0
    // 0x8010A31C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8010A31C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8010A320: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8010A324: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8010A328: jal         0x8001EB64
    // 0x8010A32C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8010A32C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8010A330: negu        $s0, $s1
    ctx->r16 = SUB32(0, ctx->r17);
    // 0x8010A334: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8010A338: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010A33C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8010A340: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8010A344: jal         0x8001EAD0
    // 0x8010A348: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8010A348: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x8010A34C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8010A350: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x8010A354: jal         0x8001EB64
    // 0x8010A358: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8010A358: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x8010A35C: negu        $s0, $s2
    ctx->r16 = SUB32(0, ctx->r18);
    // 0x8010A360: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8010A364: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010A368: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8010A36C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010A370: jal         0x8001EAD0
    // 0x8010A374: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8010A374: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x8010A378: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8010A37C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8010A380: jal         0x8001EB64
    // 0x8010A384: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8010A384: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x8010A388: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010A38C: nop

    // 0x8010A390: mul.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8010A394: nop

    // 0x8010A398: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x8010A39C: nop

    // 0x8010A3A0: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8010A3A4: nop

    // 0x8010A3A8: mul.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x8010A3AC: nop

    // 0x8010A3B0: mul.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8010A3B4: add.s       $f30, $f4, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010A3B8: mul.s       $f2, $f22, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x8010A3BC: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8010A3C0: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8010A3C4: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8010A3C8: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8010A3CC: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x8010A3D0: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x8010A3D4: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8010A3D8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8010A3DC: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8010A3E0: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x8010A3E4: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x8010A3E8: mul.s       $f18, $f6, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8010A3EC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x8010A3F0: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x8010A3F4: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8010A3F8: nop

    // 0x8010A3FC: mul.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8010A400: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010A404: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8010A408: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8010A40C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8010A410: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010A414: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8010A418: sub.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010A41C: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x8010A420: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x8010A424: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8010A428: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x8010A42C: lwc1        $f22, 0x19C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x8010A430: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8010A434: nop

    // 0x8010A438: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8010A43C: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8010A440: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010A444: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x8010A448: mul.s       $f8, $f4, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8010A44C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8010A450: lwc1        $f4, 0x190($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X190);
    // 0x8010A454: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010A458: lwc1        $f8, 0x18C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x8010A45C: mul.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010A460: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x8010A464: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x8010A468: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010A46C: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x8010A470: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010A474: lwc1        $f10, 0x194($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X194);
    // 0x8010A478: mul.s       $f8, $f28, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f10.fl);
    // 0x8010A47C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A480: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8010A484: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x8010A488: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A48C: swc1        $f6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f6.u32l;
    // 0x8010A490: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010A494: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8010A498: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8010A49C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8010A4A0: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8010A4A4: mul.s       $f6, $f30, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f8.fl);
    // 0x8010A4A8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010A4AC: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8010A4B0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8010A4B4: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010A4B8: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010A4BC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010A4C0: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x8010A4C4: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8010A4C8: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010A4CC: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x8010A4D0: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8010A4D4: lwc1        $f24, 0x198($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X198);
    // 0x8010A4D8: mul.s       $f8, $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8010A4DC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A4E0: mul.s       $f2, $f20, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010A4E4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010A4E8: lwc1        $f20, 0x1A0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x8010A4EC: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x8010A4F0: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010A4F4: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8010A4F8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010A4FC: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8010A500: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010A504: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010A508: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8010A50C: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010A510: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010A514: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8010A518: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8010A51C: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8010A520: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010A524: mul.s       $f6, $f14, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8010A528: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A52C: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8010A530: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A534: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010A538: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010A53C: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8010A540: nop

    // 0x8010A544: mul.s       $f6, $f16, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8010A548: swc1        $f8, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f8.u32l;
    // 0x8010A54C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010A550: mul.s       $f10, $f28, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8010A554: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010A558: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010A55C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A560: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8010A564: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8010A568: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8010A56C: mul.s       $f10, $f30, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f24.fl);
    // 0x8010A570: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010A574: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8010A578: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010A57C: mul.s       $f10, $f14, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8010A580: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010A584: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010A588: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8010A58C: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8010A590: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8010A594: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010A598: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010A59C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A5A0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010A5A4: swc1        $f6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f6.u32l;
L_8010A5A8:
    // 0x8010A5A8: lw          $t3, 0x74($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X74);
    // 0x8010A5AC: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8010A5B0: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010A5B4: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010A5B8: swc1        $f8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f8.u32l;
    // 0x8010A5BC: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x8010A5C0: lwc1        $f6, 0x150($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8010A5C4: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8010A5C8: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8010A5CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010A5D0: sw          $t3, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r11;
    // 0x8010A5D4: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x8010A5D8: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
    // 0x8010A5DC: swc1        $f8, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f8.u32l;
    // 0x8010A5E0: bne         $s4, $at, L_8010A600
    if (ctx->r20 != ctx->r1) {
        // 0x8010A5E4: swc1        $f10, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->f10.u32l;
            goto L_8010A600;
    }
    // 0x8010A5E4: swc1        $f10, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f10.u32l;
    // 0x8010A5E8: jal         0x8010AF98
    // 0x8010A5EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x8010AF98)(rdram, ctx);
        goto after_6;
    // 0x8010A5EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x8010A5F0: beql        $v0, $zero, L_8010A604
    if (ctx->r2 == 0) {
        // 0x8010A5F4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8010A604;
    }
    goto skip_5;
    // 0x8010A5F4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_5:
    // 0x8010A5F8: b           L_8010A660
    // 0x8010A5FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A660;
    // 0x8010A5FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010A600:
    // 0x8010A600: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_8010A604:
    // 0x8010A604: bnel        $s4, $at, L_8010A628
    if (ctx->r20 != ctx->r1) {
        // 0x8010A608: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8010A628;
    }
    goto skip_6;
    // 0x8010A608: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_6:
    // 0x8010A60C: jal         0x8010AF98
    // 0x8010A610: addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
    LOOKUP_FUNC(0x8010AF98)(rdram, ctx);
        goto after_7;
    // 0x8010A610: addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
    after_7:
    // 0x8010A614: beql        $v0, $zero, L_8010A628
    if (ctx->r2 == 0) {
        // 0x8010A618: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8010A628;
    }
    goto skip_7;
    // 0x8010A618: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_7:
    // 0x8010A61C: b           L_8010A660
    // 0x8010A620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A660;
    // 0x8010A620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010A624: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_8010A628:
    // 0x8010A628: bnel        $s4, $at, L_8010A64C
    if (ctx->r20 != ctx->r1) {
        // 0x8010A62C: lw          $s3, 0x0($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X0);
            goto L_8010A64C;
    }
    goto skip_8;
    // 0x8010A62C: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    skip_8:
    // 0x8010A630: jal         0x8010B238
    // 0x8010A634: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x8010B238)(rdram, ctx);
        goto after_8;
    // 0x8010A634: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x8010A638: beql        $v0, $zero, L_8010A64C
    if (ctx->r2 == 0) {
        // 0x8010A63C: lw          $s3, 0x0($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X0);
            goto L_8010A64C;
    }
    goto skip_9;
    // 0x8010A63C: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    skip_9:
    // 0x8010A640: b           L_8010A660
    // 0x8010A644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A660;
    // 0x8010A644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010A648: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
L_8010A64C:
    // 0x8010A64C: beql        $s3, $zero, L_8010A660
    if (ctx->r19 == 0) {
        // 0x8010A650: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A660;
    }
    goto skip_10;
    // 0x8010A650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
    // 0x8010A654: beql        $s6, $zero, L_8010A218
    if (ctx->r22 == 0) {
        // 0x8010A658: lw          $v1, 0x24($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X24);
            goto L_8010A218;
    }
    goto skip_11;
    // 0x8010A658: lw          $v1, 0x24($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X24);
    skip_11:
    // 0x8010A65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A660:
    // 0x8010A660: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8010A664: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010A668: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010A66C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010A670: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010A674: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8010A678: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8010A67C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8010A680: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8010A684: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8010A688: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8010A68C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8010A690: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8010A694: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8010A698: jr          $ra
    // 0x8010A69C: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
    return;
    // 0x8010A69C: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010a6a0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010a6a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A6A0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8010A6A4: sdc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X30, ctx->r29);
    // 0x8010A6A8: sdc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X28, ctx->r29);
    // 0x8010A6AC: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x8010A6B0: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x8010A6B4: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8010A6B8: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8010A6BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8010A6C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010A6C4: lwc1        $f28, 0x4($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010A6C8: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010A6CC: lwc1        $f30, 0x8($a0)
    ctx->f30.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8010A6D0: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8010A6D4: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8010A6D8: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8010A6DC: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x8010A6E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8010A6E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8010A6E8: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010A6EC: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x8010A6F0: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x8010A6F4: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010A6F8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010A6FC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8010A700: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8010A704: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010A708: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010A70C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8010A710: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010A714: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8010A718: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x8010A71C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8010A720: c.le.s      $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f16.fl <= ctx->f28.fl;
    // 0x8010A724: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010A728: sub.s       $f22, $f0, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x8010A72C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8010A730: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8010A734: sub.s       $f24, $f2, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x8010A738: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8010A73C: sub.s       $f26, $f12, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8010A740: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010A744: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8010A748: lh          $t0, 0x10($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X10);
    // 0x8010A74C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8010A750: nop

    // 0x8010A754: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010A758: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010A75C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8010A760: lh          $t1, 0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X12);
    // 0x8010A764: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8010A768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010A76C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8010A770: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8010A774: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8010A778: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010A77C: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8010A780: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x8010A784: bc1f        L_8010A7EC
    if (!c1cs) {
        // 0x8010A788: swc1        $f10, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
            goto L_8010A7EC;
    }
    // 0x8010A788: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8010A78C: c.le.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl <= ctx->f4.fl;
    // 0x8010A790: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010A794: bc1f        L_8010A7EC
    if (!c1cs) {
        // 0x8010A798: nop
    
            goto L_8010A7EC;
    }
    // 0x8010A798: nop

    // 0x8010A79C: c.le.s      $f6, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f6.fl <= ctx->f30.fl;
    // 0x8010A7A0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010A7A4: bc1f        L_8010A7EC
    if (!c1cs) {
        // 0x8010A7A8: nop
    
            goto L_8010A7EC;
    }
    // 0x8010A7A8: nop

    // 0x8010A7AC: c.le.s      $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f30.fl <= ctx->f8.fl;
    // 0x8010A7B0: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010A7B4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010A7B8: bc1f        L_8010A7EC
    if (!c1cs) {
        // 0x8010A7BC: nop
    
            goto L_8010A7EC;
    }
    // 0x8010A7BC: nop

    // 0x8010A7C0: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8010A7C4: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010A7C8: bc1f        L_8010A7EC
    if (!c1cs) {
        // 0x8010A7CC: nop
    
            goto L_8010A7EC;
    }
    // 0x8010A7CC: nop

    // 0x8010A7D0: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8010A7D4: nop

    // 0x8010A7D8: bc1f        L_8010A7EC
    if (!c1cs) {
        // 0x8010A7DC: nop
    
            goto L_8010A7EC;
    }
    // 0x8010A7DC: nop

    // 0x8010A7E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010A7E4: b           L_8010ACBC
    // 0x8010A7E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
        goto L_8010ACBC;
    // 0x8010A7E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
L_8010A7EC:
    // 0x8010A7EC: bne         $v0, $zero, L_8010A804
    if (ctx->r2 != 0) {
        // 0x8010A7F0: nop
    
            goto L_8010A804;
    }
    // 0x8010A7F0: nop

    // 0x8010A7F4: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010A7F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010A7FC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A800: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_8010A804:
    // 0x8010A804: bne         $v0, $v1, L_8010A814
    if (ctx->r2 != ctx->r3) {
        // 0x8010A808: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8010A814;
    }
    // 0x8010A808: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010A80C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A810: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
L_8010A814:
    // 0x8010A814: bne         $v0, $a0, L_8010A82C
    if (ctx->r2 != ctx->r4) {
        // 0x8010A818: nop
    
            goto L_8010A82C;
    }
    // 0x8010A818: nop

    // 0x8010A81C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010A820: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010A824: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A828: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_8010A82C:
    // 0x8010A82C: bne         $v0, $a1, L_8010A83C
    if (ctx->r2 != ctx->r5) {
        // 0x8010A830: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8010A83C;
    }
    // 0x8010A830: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010A834: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A838: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
L_8010A83C:
    // 0x8010A83C: mul.s       $f16, $f20, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8010A840: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010A844: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010A848: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8010A84C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8010A850: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8010A854: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A858: nop
    
            goto L_8010A974;
    }
    // 0x8010A858: nop

    // 0x8010A85C: div.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8010A860: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010A864: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010A868: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8010A86C: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8010A870: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8010A874: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8010A878: c.le.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl <= ctx->f0.fl;
    // 0x8010A87C: nop

    // 0x8010A880: bc1fl       L_8010A89C
    if (!c1cs) {
        // 0x8010A884: c.le.s      $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
            goto L_8010A89C;
    }
    goto skip_0;
    // 0x8010A884: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    skip_0:
    // 0x8010A888: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8010A88C: nop

    // 0x8010A890: bc1tl       L_8010A8BC
    if (c1cs) {
        // 0x8010A894: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8010A8BC;
    }
    goto skip_1;
    // 0x8010A894: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x8010A898: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
L_8010A89C:
    // 0x8010A89C: nop

    // 0x8010A8A0: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A8A4: nop
    
            goto L_8010A974;
    }
    // 0x8010A8A4: nop

    // 0x8010A8A8: c.le.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl <= ctx->f28.fl;
    // 0x8010A8AC: nop

    // 0x8010A8B0: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A8B4: nop
    
            goto L_8010A974;
    }
    // 0x8010A8B4: nop

    // 0x8010A8B8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_8010A8BC:
    // 0x8010A8BC: mul.s       $f0, $f24, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x8010A8C0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010A8C4: sub.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f30.fl;
    // 0x8010A8C8: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8010A8CC: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8010A8D0: nop

    // 0x8010A8D4: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A8D8: nop
    
            goto L_8010A974;
    }
    // 0x8010A8D8: nop

    // 0x8010A8DC: sub.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x8010A8E0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010A8E4: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010A8E8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010A8EC: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8010A8F0: nop

    // 0x8010A8F4: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A8F8: nop
    
            goto L_8010A974;
    }
    // 0x8010A8F8: nop

    // 0x8010A8FC: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010A900: mul.s       $f0, $f26, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x8010A904: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010A908: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010A90C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8010A910: nop

    // 0x8010A914: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A918: nop
    
            goto L_8010A974;
    }
    // 0x8010A918: nop

    // 0x8010A91C: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010A920: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010A924: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8010A928: nop

    // 0x8010A92C: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A930: nop
    
            goto L_8010A974;
    }
    // 0x8010A930: nop

    // 0x8010A934: div.s       $f0, $f14, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8010A938: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8010A93C: nop

    // 0x8010A940: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8010A944: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010A948: mul.s       $f6, $f26, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8010A94C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010A950: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010A954: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010A958: nop

    // 0x8010A95C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010A960: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8010A964: nop

    // 0x8010A968: bc1f        L_8010A974
    if (!c1cs) {
        // 0x8010A96C: nop
    
            goto L_8010A974;
    }
    // 0x8010A96C: nop

    // 0x8010A970: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
L_8010A974:
    // 0x8010A974: bne         $at, $zero, L_8010A7EC
    if (ctx->r1 != 0) {
        // 0x8010A978: nop
    
            goto L_8010A7EC;
    }
    // 0x8010A978: nop

    // 0x8010A97C: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x8010A980: lwc1        $f20, 0x74($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010A984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A988:
    // 0x8010A988: bne         $v0, $zero, L_8010A9A0
    if (ctx->r2 != 0) {
        // 0x8010A98C: nop
    
            goto L_8010A9A0;
    }
    // 0x8010A98C: nop

    // 0x8010A990: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010A994: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010A998: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A99C: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_8010A9A0:
    // 0x8010A9A0: bne         $v0, $v1, L_8010A9B0
    if (ctx->r2 != ctx->r3) {
        // 0x8010A9A4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8010A9B0;
    }
    // 0x8010A9A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010A9A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A9AC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
L_8010A9B0:
    // 0x8010A9B0: bne         $v0, $a0, L_8010A9C8
    if (ctx->r2 != ctx->r4) {
        // 0x8010A9B4: nop
    
            goto L_8010A9C8;
    }
    // 0x8010A9B4: nop

    // 0x8010A9B8: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010A9BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010A9C0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A9C4: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_8010A9C8:
    // 0x8010A9C8: bne         $v0, $a1, L_8010A9D8
    if (ctx->r2 != ctx->r5) {
        // 0x8010A9CC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8010A9D8;
    }
    // 0x8010A9CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010A9D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010A9D4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
L_8010A9D8:
    // 0x8010A9D8: mul.s       $f16, $f20, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010A9DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010A9E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010A9E4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8010A9E8: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8010A9EC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8010A9F0: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010A9F4: nop
    
            goto L_8010AB10;
    }
    // 0x8010A9F4: nop

    // 0x8010A9F8: div.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8010A9FC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010AA00: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010AA04: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x8010AA08: mul.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8010AA0C: sub.s       $f14, $f8, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8010AA10: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8010AA14: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    // 0x8010AA18: nop

    // 0x8010AA1C: bc1fl       L_8010AA38
    if (!c1cs) {
        // 0x8010AA20: c.le.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
            goto L_8010AA38;
    }
    goto skip_2;
    // 0x8010AA20: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    skip_2:
    // 0x8010AA24: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8010AA28: nop

    // 0x8010AA2C: bc1tl       L_8010AA58
    if (c1cs) {
        // 0x8010AA30: lwc1        $f10, 0x68($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
            goto L_8010AA58;
    }
    goto skip_3;
    // 0x8010AA30: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    skip_3:
    // 0x8010AA34: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
L_8010AA38:
    // 0x8010AA38: nop

    // 0x8010AA3C: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AA40: nop
    
            goto L_8010AB10;
    }
    // 0x8010AA40: nop

    // 0x8010AA44: c.le.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl <= ctx->f30.fl;
    // 0x8010AA48: nop

    // 0x8010AA4C: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AA50: nop
    
            goto L_8010AB10;
    }
    // 0x8010AA50: nop

    // 0x8010AA54: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
L_8010AA58:
    // 0x8010AA58: mul.s       $f0, $f22, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010AA5C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010AA60: sub.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f28.fl;
    // 0x8010AA64: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8010AA68: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8010AA6C: nop

    // 0x8010AA70: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AA74: nop
    
            goto L_8010AB10;
    }
    // 0x8010AA74: nop

    // 0x8010AA78: sub.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x8010AA7C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010AA80: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010AA84: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010AA88: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8010AA8C: nop

    // 0x8010AA90: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AA94: nop
    
            goto L_8010AB10;
    }
    // 0x8010AA94: nop

    // 0x8010AA98: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010AA9C: mul.s       $f0, $f26, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x8010AAA0: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010AAA4: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010AAA8: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8010AAAC: nop

    // 0x8010AAB0: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AAB4: nop
    
            goto L_8010AB10;
    }
    // 0x8010AAB4: nop

    // 0x8010AAB8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010AABC: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010AAC0: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8010AAC4: nop

    // 0x8010AAC8: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AACC: nop
    
            goto L_8010AB10;
    }
    // 0x8010AACC: nop

    // 0x8010AAD0: div.s       $f0, $f14, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8010AAD4: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8010AAD8: nop

    // 0x8010AADC: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8010AAE0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010AAE4: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8010AAE8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010AAEC: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010AAF0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010AAF4: nop

    // 0x8010AAF8: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010AAFC: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8010AB00: nop

    // 0x8010AB04: bc1f        L_8010AB10
    if (!c1cs) {
        // 0x8010AB08: nop
    
            goto L_8010AB10;
    }
    // 0x8010AB08: nop

    // 0x8010AB0C: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
L_8010AB10:
    // 0x8010AB10: bne         $at, $zero, L_8010A988
    if (ctx->r1 != 0) {
        // 0x8010AB14: nop
    
            goto L_8010A988;
    }
    // 0x8010AB14: nop

    // 0x8010AB18: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x8010AB1C: lwc1        $f20, 0x70($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010AB20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010AB24:
    // 0x8010AB24: bne         $v0, $zero, L_8010AB3C
    if (ctx->r2 != 0) {
        // 0x8010AB28: nop
    
            goto L_8010AB3C;
    }
    // 0x8010AB28: nop

    // 0x8010AB2C: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010AB30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010AB34: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010AB38: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_8010AB3C:
    // 0x8010AB3C: bne         $v0, $v1, L_8010AB4C
    if (ctx->r2 != ctx->r3) {
        // 0x8010AB40: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8010AB4C;
    }
    // 0x8010AB40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010AB44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010AB48: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
L_8010AB4C:
    // 0x8010AB4C: bne         $v0, $a0, L_8010AB64
    if (ctx->r2 != ctx->r4) {
        // 0x8010AB50: nop
    
            goto L_8010AB64;
    }
    // 0x8010AB50: nop

    // 0x8010AB54: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010AB58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010AB5C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010AB60: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_8010AB64:
    // 0x8010AB64: bne         $v0, $a1, L_8010AB74
    if (ctx->r2 != ctx->r5) {
        // 0x8010AB68: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8010AB74;
    }
    // 0x8010AB68: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010AB6C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010AB70: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
L_8010AB74:
    // 0x8010AB74: mul.s       $f16, $f20, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010AB78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010AB7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010AB80: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8010AB84: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8010AB88: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010AB8C: nop
    
            goto L_8010ACA8;
    }
    // 0x8010AB8C: nop

    // 0x8010AB90: div.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8010AB94: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010AB98: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010AB9C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010ABA0: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8010ABA4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8010ABA8: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8010ABAC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8010ABB0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8010ABB4: nop

    // 0x8010ABB8: bc1fl       L_8010ABD4
    if (!c1cs) {
        // 0x8010ABBC: c.le.s      $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
            goto L_8010ABD4;
    }
    goto skip_4;
    // 0x8010ABBC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    skip_4:
    // 0x8010ABC0: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8010ABC4: nop

    // 0x8010ABC8: bc1tl       L_8010ABF4
    if (c1cs) {
        // 0x8010ABCC: lwc1        $f6, 0x68($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
            goto L_8010ABF4;
    }
    goto skip_5;
    // 0x8010ABCC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    skip_5:
    // 0x8010ABD0: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
L_8010ABD4:
    // 0x8010ABD4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010ABD8: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010ABDC: nop
    
            goto L_8010ACA8;
    }
    // 0x8010ABDC: nop

    // 0x8010ABE0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8010ABE4: nop

    // 0x8010ABE8: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010ABEC: nop
    
            goto L_8010ACA8;
    }
    // 0x8010ABEC: nop

    // 0x8010ABF0: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
L_8010ABF4:
    // 0x8010ABF4: mul.s       $f0, $f22, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010ABF8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010ABFC: sub.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x8010AC00: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010AC04: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8010AC08: nop

    // 0x8010AC0C: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010AC10: nop
    
            goto L_8010ACA8;
    }
    // 0x8010AC10: nop

    // 0x8010AC14: sub.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x8010AC18: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010AC1C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8010AC20: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8010AC24: nop

    // 0x8010AC28: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010AC2C: nop
    
            goto L_8010ACA8;
    }
    // 0x8010AC2C: nop

    // 0x8010AC30: sub.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x8010AC34: mul.s       $f0, $f24, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x8010AC38: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010AC3C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010AC40: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8010AC44: nop

    // 0x8010AC48: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010AC4C: nop
    
            goto L_8010ACA8;
    }
    // 0x8010AC4C: nop

    // 0x8010AC50: sub.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x8010AC54: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8010AC58: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8010AC5C: nop

    // 0x8010AC60: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010AC64: nop
    
            goto L_8010ACA8;
    }
    // 0x8010AC64: nop

    // 0x8010AC68: div.s       $f0, $f14, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8010AC6C: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8010AC70: nop

    // 0x8010AC74: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8010AC78: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010AC7C: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8010AC80: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010AC84: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010AC88: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010AC8C: nop

    // 0x8010AC90: mul.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010AC94: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8010AC98: nop

    // 0x8010AC9C: bc1f        L_8010ACA8
    if (!c1cs) {
        // 0x8010ACA0: nop
    
            goto L_8010ACA8;
    }
    // 0x8010ACA0: nop

    // 0x8010ACA4: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
L_8010ACA8:
    // 0x8010ACA8: bne         $v0, $a2, L_8010AB24
    if (ctx->r2 != ctx->r6) {
        // 0x8010ACAC: nop
    
            goto L_8010AB24;
    }
    // 0x8010ACAC: nop

    // 0x8010ACB0: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x8010ACB4: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010ACB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
L_8010ACBC:
    // 0x8010ACBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010ACC0: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8010ACC4: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8010ACC8: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8010ACCC: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8010ACD0: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x8010ACD4: ldc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X28);
    // 0x8010ACD8: bc1f        L_8010ACEC
    if (!c1cs) {
        // 0x8010ACDC: ldc1        $f30, 0x30($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X30);
            goto L_8010ACEC;
    }
    // 0x8010ACDC: ldc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X30);
    // 0x8010ACE0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010ACE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8010ACE8: nop

L_8010ACEC:
    // 0x8010ACEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8010ACF0: jr          $ra
    // 0x8010ACF4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8010ACF4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010acf8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010acf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010ACF8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8010ACFC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8010AD00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010AD04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010AD08: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8010AD0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8010AD10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010AD14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010AD18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010AD1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010AD20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010AD24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010AD28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010AD2C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8010AD30: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x8010AD34: addiu       $a1, $zero, 0xFD
    ctx->r5 = ADD32(0, 0XFD);
    // 0x8010AD38: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8010AD3C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010AD40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8010AD44: bne         $a1, $v0, L_8010AD64
    if (ctx->r5 != ctx->r2) {
        // 0x8010AD48: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8010AD64;
    }
    // 0x8010AD48: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8010AD4C: addiu       $t6, $v1, 0x14
    ctx->r14 = ADD32(ctx->r3, 0X14);
L_8010AD50:
    // 0x8010AD50: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8010AD54: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x8010AD58: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8010AD5C: beql        $a1, $v0, L_8010AD50
    if (ctx->r5 == ctx->r2) {
        // 0x8010AD60: addiu       $t6, $v1, 0x14
        ctx->r14 = ADD32(ctx->r3, 0X14);
            goto L_8010AD50;
    }
    goto skip_0;
    // 0x8010AD60: addiu       $t6, $v1, 0x14
    ctx->r14 = ADD32(ctx->r3, 0X14);
    skip_0:
L_8010AD64:
    // 0x8010AD64: bne         $v0, $at, L_8010AF50
    if (ctx->r2 != ctx->r1) {
        // 0x8010AD68: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010AF50;
    }
    // 0x8010AD68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010AD6C: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8010AD70: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8010AD74: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8010AD78: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x8010AD7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010AD80: nop

    // 0x8010AD84: bc1fl       L_8010ADB4
    if (!c1cs) {
        // 0x8010AD88: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010ADB4;
    }
    goto skip_1;
    // 0x8010AD88: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_1:
    // 0x8010AD8C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010AD90: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010AD94: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8010AD98: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8010AD9C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8010ADA0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8010ADA4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8010ADA8: b           L_8010ADD0
    // 0x8010ADAC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8010ADD0;
    // 0x8010ADAC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010ADB0: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010ADB4:
    // 0x8010ADB4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010ADB8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8010ADBC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8010ADC0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8010ADC4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8010ADC8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8010ADCC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010ADD0:
    // 0x8010ADD0: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8010ADD4: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8010ADD8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010ADDC: nop

    // 0x8010ADE0: bc1fl       L_8010AE10
    if (!c1cs) {
        // 0x8010ADE4: trunc.w.s   $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010AE10;
    }
    goto skip_2;
    // 0x8010ADE4: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_2:
    // 0x8010ADE8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010ADEC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010ADF0: mfc1        $s5, $f18
    ctx->r21 = (int32_t)ctx->f18.u32l;
    // 0x8010ADF4: mfc1        $s6, $f4
    ctx->r22 = (int32_t)ctx->f4.u32l;
    // 0x8010ADF8: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8010ADFC: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8010AE00: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8010AE04: b           L_8010AE2C
    // 0x8010AE08: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
        goto L_8010AE2C;
    // 0x8010AE08: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8010AE0C: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010AE10:
    // 0x8010AE10: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010AE14: mfc1        $s5, $f6
    ctx->r21 = (int32_t)ctx->f6.u32l;
    // 0x8010AE18: mfc1        $s6, $f8
    ctx->r22 = (int32_t)ctx->f8.u32l;
    // 0x8010AE1C: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8010AE20: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8010AE24: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8010AE28: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
L_8010AE2C:
    // 0x8010AE2C: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8010AE30: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8010AE34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010AE38: nop

    // 0x8010AE3C: bc1fl       L_8010AE6C
    if (!c1cs) {
        // 0x8010AE40: trunc.w.s   $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010AE6C;
    }
    goto skip_3;
    // 0x8010AE40: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_3:
    // 0x8010AE44: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010AE48: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010AE4C: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x8010AE50: mfc1        $fp, $f16
    ctx->r30 = (int32_t)ctx->f16.u32l;
    // 0x8010AE54: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x8010AE58: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8010AE5C: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8010AE60: b           L_8010AE88
    // 0x8010AE64: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
        goto L_8010AE88;
    // 0x8010AE64: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8010AE68: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010AE6C:
    // 0x8010AE6C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010AE70: mfc1        $s7, $f18
    ctx->r23 = (int32_t)ctx->f18.u32l;
    // 0x8010AE74: mfc1        $fp, $f4
    ctx->r30 = (int32_t)ctx->f4.u32l;
    // 0x8010AE78: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x8010AE7C: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8010AE80: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8010AE84: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
L_8010AE88:
    // 0x8010AE88: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8010AE8C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x8010AE90: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x8010AE94: beql        $s3, $t9, L_8010AF68
    if (ctx->r19 == ctx->r25) {
        // 0x8010AE98: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8010AF68;
    }
    goto skip_4;
    // 0x8010AE98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x8010AE9C: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
L_8010AEA0:
    // 0x8010AEA0: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010AEA4: bnel        $at, $zero, L_8010AF3C
    if (ctx->r1 != 0) {
        // 0x8010AEA8: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010AF3C;
    }
    goto skip_5;
    // 0x8010AEA8: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_5:
    // 0x8010AEAC: lh          $t1, 0xE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE);
    // 0x8010AEB0: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8010AEB4: bnel        $at, $zero, L_8010AF3C
    if (ctx->r1 != 0) {
        // 0x8010AEB8: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010AF3C;
    }
    goto skip_6;
    // 0x8010AEB8: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_6:
    // 0x8010AEBC: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x8010AEC0: slt         $at, $s6, $t2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010AEC4: bnel        $at, $zero, L_8010AF3C
    if (ctx->r1 != 0) {
        // 0x8010AEC8: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010AF3C;
    }
    goto skip_7;
    // 0x8010AEC8: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_7:
    // 0x8010AECC: lh          $t3, 0x10($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X10);
    // 0x8010AED0: slt         $at, $t3, $s5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8010AED4: bnel        $at, $zero, L_8010AF3C
    if (ctx->r1 != 0) {
        // 0x8010AED8: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010AF3C;
    }
    goto skip_8;
    // 0x8010AED8: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_8:
    // 0x8010AEDC: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8010AEE0: slt         $at, $fp, $t4
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8010AEE4: bnel        $at, $zero, L_8010AF3C
    if (ctx->r1 != 0) {
        // 0x8010AEE8: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010AF3C;
    }
    goto skip_9;
    // 0x8010AEE8: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_9:
    // 0x8010AEEC: lh          $t5, 0x12($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X12);
    // 0x8010AEF0: slt         $at, $t5, $s7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8010AEF4: bnel        $at, $zero, L_8010AF3C
    if (ctx->r1 != 0) {
        // 0x8010AEF8: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010AF3C;
    }
    goto skip_10;
    // 0x8010AEF8: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_10:
    // 0x8010AEFC: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8010AF00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010AF04: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010AF08: mflo        $t7
    ctx->r15 = lo;
    // 0x8010AF0C: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8010AF10: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8010AF14: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8010AF18: sh          $a2, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r6;
    // 0x8010AF1C: jal         0x8010B73C
    // 0x8010AF20: sh          $a1, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8010B73C)(rdram, ctx);
        goto after_0;
    // 0x8010AF20: sh          $a1, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010AF24: lh          $a1, 0x4C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4C);
    // 0x8010AF28: lh          $a2, 0x46($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X46);
    // 0x8010AF2C: beq         $v0, $zero, L_8010AF38
    if (ctx->r2 == 0) {
        // 0x8010AF30: lw          $a3, 0x64($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X64);
            goto L_8010AF38;
    }
    // 0x8010AF30: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8010AF34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8010AF38:
    // 0x8010AF38: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
L_8010AF3C:
    // 0x8010AF3C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8010AF40: bnel        $s3, $t9, L_8010AEA0
    if (ctx->r19 != ctx->r25) {
        // 0x8010AF44: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_8010AEA0;
    }
    goto skip_11;
    // 0x8010AF44: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_11:
    // 0x8010AF48: b           L_8010AF68
    // 0x8010AF4C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8010AF68;
    // 0x8010AF4C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010AF50:
    // 0x8010AF50: jal         0x8010B73C
    // 0x8010AF54: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8010B73C)(rdram, ctx);
        goto after_1;
    // 0x8010AF54: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_1:
    // 0x8010AF58: beq         $v0, $zero, L_8010AF64
    if (ctx->r2 == 0) {
        // 0x8010AF5C: lw          $a3, 0x64($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X64);
            goto L_8010AF64;
    }
    // 0x8010AF5C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8010AF60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8010AF64:
    // 0x8010AF64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010AF68:
    // 0x8010AF68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010AF6C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AF70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010AF74: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010AF78: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010AF7C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8010AF80: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8010AF84: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8010AF88: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8010AF8C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8010AF90: jr          $ra
    // 0x8010AF94: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8010AF94: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010af98(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010af98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AF98: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8010AF9C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010AFA0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8010AFA4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8010AFA8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010AFAC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010AFB0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010AFB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010AFB8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010AFBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010AFC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010AFC4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8010AFC8: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x8010AFCC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010AFD0: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8010AFD4: addiu       $t6, $a3, 0x14
    ctx->r14 = ADD32(ctx->r7, 0X14);
    // 0x8010AFD8: bnel        $v0, $at, L_8010AFF0
    if (ctx->r2 != ctx->r1) {
        // 0x8010AFDC: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8010AFF0;
    }
    goto skip_0;
    // 0x8010AFDC: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    skip_0:
    // 0x8010AFE0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8010AFE4: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x8010AFE8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8010AFEC: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
L_8010AFF0:
    // 0x8010AFF0: bne         $v0, $at, L_8010B1EC
    if (ctx->r2 != ctx->r1) {
        // 0x8010AFF4: nop
    
            goto L_8010B1EC;
    }
    // 0x8010AFF4: nop

    // 0x8010AFF8: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8010AFFC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8010B000: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8010B004: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8010B008: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B00C: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x8010B010: bc1fl       L_8010B040
    if (!c1cs) {
        // 0x8010B014: trunc.w.s   $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010B040;
    }
    goto skip_1;
    // 0x8010B014: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_1:
    // 0x8010B018: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B01C: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010B020: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010B024: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010B028: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8010B02C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8010B030: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8010B034: b           L_8010B05C
    // 0x8010B038: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8010B05C;
    // 0x8010B038: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010B03C: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010B040:
    // 0x8010B040: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B044: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8010B048: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8010B04C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8010B050: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8010B054: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8010B058: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010B05C:
    // 0x8010B05C: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8010B060: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8010B064: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B068: nop

    // 0x8010B06C: bc1fl       L_8010B09C
    if (!c1cs) {
        // 0x8010B070: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010B09C;
    }
    goto skip_2;
    // 0x8010B070: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_2:
    // 0x8010B074: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B078: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010B07C: mfc1        $fp, $f16
    ctx->r30 = (int32_t)ctx->f16.u32l;
    // 0x8010B080: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8010B084: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8010B088: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8010B08C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8010B090: b           L_8010B0B8
    // 0x8010B094: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8010B0B8;
    // 0x8010B094: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010B098: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010B09C:
    // 0x8010B09C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B0A0: mfc1        $fp, $f4
    ctx->r30 = (int32_t)ctx->f4.u32l;
    // 0x8010B0A4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8010B0A8: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8010B0AC: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8010B0B0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8010B0B4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8010B0B8:
    // 0x8010B0B8: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8010B0BC: lwc1        $f2, 0x18($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8010B0C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B0C4: nop

    // 0x8010B0C8: bc1fl       L_8010B0F8
    if (!c1cs) {
        // 0x8010B0CC: trunc.w.s   $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010B0F8;
    }
    goto skip_3;
    // 0x8010B0CC: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_3:
    // 0x8010B0D0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B0D4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010B0D8: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8010B0DC: mfc1        $s6, $f10
    ctx->r22 = (int32_t)ctx->f10.u32l;
    // 0x8010B0E0: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8010B0E4: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8010B0E8: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8010B0EC: b           L_8010B114
    // 0x8010B0F0: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
        goto L_8010B114;
    // 0x8010B0F0: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8010B0F4: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010B0F8:
    // 0x8010B0F8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B0FC: mfc1        $s5, $f16
    ctx->r21 = (int32_t)ctx->f16.u32l;
    // 0x8010B100: mfc1        $s6, $f18
    ctx->r22 = (int32_t)ctx->f18.u32l;
    // 0x8010B104: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8010B108: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8010B10C: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8010B110: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
L_8010B114:
    // 0x8010B114: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8010B118: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8010B11C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8010B120: beql        $s7, $t9, L_8010B208
    if (ctx->r23 == ctx->r25) {
        // 0x8010B124: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B208;
    }
    goto skip_4;
    // 0x8010B124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8010B128: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
L_8010B12C:
    // 0x8010B12C: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010B130: bnel        $at, $zero, L_8010B1D4
    if (ctx->r1 != 0) {
        // 0x8010B134: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B1D4;
    }
    goto skip_5;
    // 0x8010B134: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_5:
    // 0x8010B138: lh          $t1, 0xE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE);
    // 0x8010B13C: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8010B140: bnel        $at, $zero, L_8010B1D4
    if (ctx->r1 != 0) {
        // 0x8010B144: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B1D4;
    }
    goto skip_6;
    // 0x8010B144: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_6:
    // 0x8010B148: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x8010B14C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010B150: bnel        $at, $zero, L_8010B1D4
    if (ctx->r1 != 0) {
        // 0x8010B154: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B1D4;
    }
    goto skip_7;
    // 0x8010B154: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_7:
    // 0x8010B158: lh          $t3, 0x10($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X10);
    // 0x8010B15C: slt         $at, $t3, $fp
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8010B160: bnel        $at, $zero, L_8010B1D4
    if (ctx->r1 != 0) {
        // 0x8010B164: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B1D4;
    }
    goto skip_8;
    // 0x8010B164: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_8:
    // 0x8010B168: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8010B16C: slt         $at, $s6, $t4
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8010B170: bnel        $at, $zero, L_8010B1D4
    if (ctx->r1 != 0) {
        // 0x8010B174: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B1D4;
    }
    goto skip_9;
    // 0x8010B174: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_9:
    // 0x8010B178: lh          $t5, 0x12($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X12);
    // 0x8010B17C: addu        $t6, $s1, $s2
    ctx->r14 = ADD32(ctx->r17, ctx->r18);
    // 0x8010B180: slt         $at, $t5, $s5
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8010B184: bnel        $at, $zero, L_8010B1D4
    if (ctx->r1 != 0) {
        // 0x8010B188: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B1D4;
    }
    goto skip_10;
    // 0x8010B188: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_10:
    // 0x8010B18C: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8010B190: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8010B194: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010B198: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010B19C: mflo        $t7
    ctx->r15 = lo;
    // 0x8010B1A0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8010B1A4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8010B1A8: sh          $a2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r6;
    // 0x8010B1AC: sh          $a1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r5;
    // 0x8010B1B0: jal         0x8010C21C
    // 0x8010B1B4: sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8010C21C)(rdram, ctx);
        goto after_0;
    // 0x8010B1B4: sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    after_0:
    // 0x8010B1B8: lh          $v1, 0x42($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X42);
    // 0x8010B1BC: lh          $a1, 0x4A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4A);
    // 0x8010B1C0: beq         $v0, $zero, L_8010B1D0
    if (ctx->r2 == 0) {
        // 0x8010B1C4: lh          $a2, 0x44($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X44);
            goto L_8010B1D0;
    }
    // 0x8010B1C4: lh          $a2, 0x44($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X44);
    // 0x8010B1C8: b           L_8010B208
    // 0x8010B1CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B208;
    // 0x8010B1CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010B1D0:
    // 0x8010B1D0: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
L_8010B1D4:
    // 0x8010B1D4: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8010B1D8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8010B1DC: bnel        $s7, $t9, L_8010B12C
    if (ctx->r23 != ctx->r25) {
        // 0x8010B1E0: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_8010B12C;
    }
    goto skip_11;
    // 0x8010B1E0: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_11:
    // 0x8010B1E4: b           L_8010B208
    // 0x8010B1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010B208;
    // 0x8010B1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B1EC:
    // 0x8010B1EC: jal         0x8010C21C
    // 0x8010B1F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8010C21C)(rdram, ctx);
        goto after_1;
    // 0x8010B1F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8010B1F4: beql        $v0, $zero, L_8010B208
    if (ctx->r2 == 0) {
        // 0x8010B1F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B208;
    }
    goto skip_12;
    // 0x8010B1F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_12:
    // 0x8010B1FC: b           L_8010B208
    // 0x8010B200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B208;
    // 0x8010B200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010B204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B208:
    // 0x8010B208: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010B20C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B210: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B214: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010B218: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010B21C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010B220: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8010B224: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8010B228: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8010B22C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8010B230: jr          $ra
    // 0x8010B234: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8010B234: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010b238(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010b238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B238: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8010B23C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010B240: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8010B244: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8010B248: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010B24C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010B250: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010B254: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010B258: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010B25C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010B260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B264: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8010B268: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x8010B26C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010B270: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8010B274: addiu       $t6, $a3, 0x14
    ctx->r14 = ADD32(ctx->r7, 0X14);
    // 0x8010B278: bnel        $v0, $at, L_8010B290
    if (ctx->r2 != ctx->r1) {
        // 0x8010B27C: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8010B290;
    }
    goto skip_0;
    // 0x8010B27C: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    skip_0:
    // 0x8010B280: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8010B284: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x8010B288: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8010B28C: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
L_8010B290:
    // 0x8010B290: bne         $v0, $at, L_8010B48C
    if (ctx->r2 != ctx->r1) {
        // 0x8010B294: nop
    
            goto L_8010B48C;
    }
    // 0x8010B294: nop

    // 0x8010B298: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8010B29C: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8010B2A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8010B2A4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8010B2A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B2AC: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x8010B2B0: bc1fl       L_8010B2E0
    if (!c1cs) {
        // 0x8010B2B4: trunc.w.s   $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010B2E0;
    }
    goto skip_1;
    // 0x8010B2B4: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_1:
    // 0x8010B2B8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B2BC: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010B2C0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010B2C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010B2C8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8010B2CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8010B2D0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8010B2D4: b           L_8010B2FC
    // 0x8010B2D8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8010B2FC;
    // 0x8010B2D8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010B2DC: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010B2E0:
    // 0x8010B2E0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B2E4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8010B2E8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8010B2EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8010B2F0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8010B2F4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8010B2F8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010B2FC:
    // 0x8010B2FC: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8010B300: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8010B304: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B308: nop

    // 0x8010B30C: bc1fl       L_8010B33C
    if (!c1cs) {
        // 0x8010B310: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010B33C;
    }
    goto skip_2;
    // 0x8010B310: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_2:
    // 0x8010B314: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B318: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010B31C: mfc1        $fp, $f16
    ctx->r30 = (int32_t)ctx->f16.u32l;
    // 0x8010B320: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8010B324: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8010B328: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8010B32C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8010B330: b           L_8010B358
    // 0x8010B334: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8010B358;
    // 0x8010B334: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010B338: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010B33C:
    // 0x8010B33C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B340: mfc1        $fp, $f4
    ctx->r30 = (int32_t)ctx->f4.u32l;
    // 0x8010B344: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8010B348: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8010B34C: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8010B350: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8010B354: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8010B358:
    // 0x8010B358: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8010B35C: lwc1        $f2, 0x18($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8010B360: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B364: nop

    // 0x8010B368: bc1fl       L_8010B398
    if (!c1cs) {
        // 0x8010B36C: trunc.w.s   $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8010B398;
    }
    goto skip_3;
    // 0x8010B36C: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_3:
    // 0x8010B370: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B374: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010B378: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8010B37C: mfc1        $s6, $f10
    ctx->r22 = (int32_t)ctx->f10.u32l;
    // 0x8010B380: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8010B384: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8010B388: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8010B38C: b           L_8010B3B4
    // 0x8010B390: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
        goto L_8010B3B4;
    // 0x8010B390: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8010B394: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
L_8010B398:
    // 0x8010B398: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010B39C: mfc1        $s5, $f16
    ctx->r21 = (int32_t)ctx->f16.u32l;
    // 0x8010B3A0: mfc1        $s6, $f18
    ctx->r22 = (int32_t)ctx->f18.u32l;
    // 0x8010B3A4: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8010B3A8: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8010B3AC: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8010B3B0: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
L_8010B3B4:
    // 0x8010B3B4: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8010B3B8: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8010B3BC: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8010B3C0: beql        $s7, $t9, L_8010B4A8
    if (ctx->r23 == ctx->r25) {
        // 0x8010B3C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B4A8;
    }
    goto skip_4;
    // 0x8010B3C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8010B3C8: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
L_8010B3CC:
    // 0x8010B3CC: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010B3D0: bnel        $at, $zero, L_8010B474
    if (ctx->r1 != 0) {
        // 0x8010B3D4: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B474;
    }
    goto skip_5;
    // 0x8010B3D4: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_5:
    // 0x8010B3D8: lh          $t1, 0xE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE);
    // 0x8010B3DC: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8010B3E0: bnel        $at, $zero, L_8010B474
    if (ctx->r1 != 0) {
        // 0x8010B3E4: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B474;
    }
    goto skip_6;
    // 0x8010B3E4: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_6:
    // 0x8010B3E8: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x8010B3EC: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010B3F0: bnel        $at, $zero, L_8010B474
    if (ctx->r1 != 0) {
        // 0x8010B3F4: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B474;
    }
    goto skip_7;
    // 0x8010B3F4: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_7:
    // 0x8010B3F8: lh          $t3, 0x10($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X10);
    // 0x8010B3FC: slt         $at, $t3, $fp
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8010B400: bnel        $at, $zero, L_8010B474
    if (ctx->r1 != 0) {
        // 0x8010B404: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B474;
    }
    goto skip_8;
    // 0x8010B404: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_8:
    // 0x8010B408: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8010B40C: slt         $at, $s6, $t4
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8010B410: bnel        $at, $zero, L_8010B474
    if (ctx->r1 != 0) {
        // 0x8010B414: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B474;
    }
    goto skip_9;
    // 0x8010B414: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_9:
    // 0x8010B418: lh          $t5, 0x12($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X12);
    // 0x8010B41C: addu        $t6, $s1, $s2
    ctx->r14 = ADD32(ctx->r17, ctx->r18);
    // 0x8010B420: slt         $at, $t5, $s5
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8010B424: bnel        $at, $zero, L_8010B474
    if (ctx->r1 != 0) {
        // 0x8010B428: lbu         $t9, 0x14($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X14);
            goto L_8010B474;
    }
    goto skip_10;
    // 0x8010B428: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
    skip_10:
    // 0x8010B42C: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8010B430: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8010B434: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010B438: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010B43C: mflo        $t7
    ctx->r15 = lo;
    // 0x8010B440: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8010B444: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8010B448: sh          $a2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r6;
    // 0x8010B44C: sh          $a1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r5;
    // 0x8010B450: jal         0x8010CC68
    // 0x8010B454: sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8010CC68)(rdram, ctx);
        goto after_0;
    // 0x8010B454: sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    after_0:
    // 0x8010B458: lh          $v1, 0x42($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X42);
    // 0x8010B45C: lh          $a1, 0x4A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4A);
    // 0x8010B460: beq         $v0, $zero, L_8010B470
    if (ctx->r2 == 0) {
        // 0x8010B464: lh          $a2, 0x44($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X44);
            goto L_8010B470;
    }
    // 0x8010B464: lh          $a2, 0x44($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X44);
    // 0x8010B468: b           L_8010B4A8
    // 0x8010B46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B4A8;
    // 0x8010B46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010B470:
    // 0x8010B470: lbu         $t9, 0x14($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X14);
L_8010B474:
    // 0x8010B474: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8010B478: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8010B47C: bnel        $s7, $t9, L_8010B3CC
    if (ctx->r23 != ctx->r25) {
        // 0x8010B480: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_8010B3CC;
    }
    goto skip_11;
    // 0x8010B480: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_11:
    // 0x8010B484: b           L_8010B4A8
    // 0x8010B488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010B4A8;
    // 0x8010B488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B48C:
    // 0x8010B48C: jal         0x8010CC68
    // 0x8010B490: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8010CC68)(rdram, ctx);
        goto after_1;
    // 0x8010B490: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8010B494: beql        $v0, $zero, L_8010B4A8
    if (ctx->r2 == 0) {
        // 0x8010B498: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B4A8;
    }
    goto skip_12;
    // 0x8010B498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_12:
    // 0x8010B49C: b           L_8010B4A8
    // 0x8010B4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B4A8;
    // 0x8010B4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010B4A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B4A8:
    // 0x8010B4A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010B4AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B4B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B4B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010B4B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010B4BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010B4C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8010B4C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8010B4C8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8010B4CC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8010B4D0: jr          $ra
    // 0x8010B4D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8010B4D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010b4d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010b4d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B4D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010B4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B4E0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8010B4E4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8010B4E8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8010B4EC: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010B4F0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010B4F4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8010B4F8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8010B4FC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010B500: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8010B504: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8010B508: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8010B50C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8010B510: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8010B514: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010B518: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8010B51C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8010B520: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8010B524: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8010B528: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8010B52C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010B530: jal         0x8002FC20
    // 0x8010B534: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8010B534: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8010B538: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8010B53C: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8010B540: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010B544: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8010B548: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8010B54C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8010B550: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8010B554: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8010B558: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010B55C: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8010B560: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010B564: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8010B568: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8010B56C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8010B570: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010B574: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010B578: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8010B57C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010B580: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8010B584: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8010B588: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010B58C: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010B590: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8010B594: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8010B598: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010B59C: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8010B5A0: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010B5A4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010B5A8: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8010B5AC: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010B5B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010B5B4: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8010B5B8: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010B5BC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8010B5C0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010B5C4: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8010B5C8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8010B5CC: div.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8010B5D0: add.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8010B5D4: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010B5D8: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x8010B5DC: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010B5E0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8010B5E4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8010B5E8: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8010B5EC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010B5F0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B5F4: div.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8010B5F8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8010B5FC: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x8010B600: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010B604: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8010B608: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8010B60C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010B610: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010B614: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010B618: div.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010B61C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010B620: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8010B624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B628: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010B62C: jr          $ra
    // 0x8010B630: nop

    return;
    // 0x8010B630: nop

;}
RECOMP_FUNC void M7_FUN_8010b634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010B638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B63C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8010B640: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010B644: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8010B648: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8010B64C: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8010B650: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8010B654: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8010B658: nop

    // 0x8010B65C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8010B660: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B664: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8010B668: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010B66C: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8010B670: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010B674: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010B678: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8010B67C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010B680: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8010B684: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010B688: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8010B68C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8010B690: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010B694: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010B698: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010B69C: div.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8010B6A0: jal         0x8002FC20
    // 0x8010B6A4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8010B6A4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8010B6A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010B6AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010B6B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8010B6B4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010B6B8: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010B6BC: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8010B6C0: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8010B6C4: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8010B6C8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8010B6CC: div.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010B6D0: div.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8010B6D4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8010B6D8: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010B6DC: div.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010B6E0: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8010B6E4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010B6E8: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8010B6EC: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8010B6F0: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8010B6F4: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8010B6F8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8010B6FC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8010B700: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010B704: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8010B708: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8010B70C: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8010B710: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8010B714: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8010B718: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010B71C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010B720: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010B724: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010B728: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8010B72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010B734: jr          $ra
    // 0x8010B738: nop

    return;
    // 0x8010B738: nop

;}
RECOMP_FUNC void M7_FUN_8010b73c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B73C: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x8010B740: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8010B744: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8010B748: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8010B74C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8010B750: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8010B754: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8010B758: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8010B75C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8010B760: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8010B764: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010B768: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010B76C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010B770: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010B774: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010B778: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010B77C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8010B780: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8010B784: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8010B788: bc1fl       L_8010B7A0
    if (!c1cs) {
        // 0x8010B78C: swc1        $f18, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
            goto L_8010B7A0;
    }
    goto skip_0;
    // 0x8010B78C: swc1        $f18, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
    skip_0:
    // 0x8010B790: swc1        $f16, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f16.u32l;
    // 0x8010B794: b           L_8010B7A4
    // 0x8010B798: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
        goto L_8010B7A4;
    // 0x8010B798: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x8010B79C: swc1        $f18, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
L_8010B7A0:
    // 0x8010B7A0: swc1        $f16, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f16.u32l;
L_8010B7A4:
    // 0x8010B7A4: lwc1        $f12, 0x8($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8010B7A8: lwc1        $f14, 0x14($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8010B7AC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8010B7B0: sub.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x8010B7B4: bc1fl       L_8010B7CC
    if (!c1cs) {
        // 0x8010B7B8: swc1        $f14, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->f14.u32l;
            goto L_8010B7CC;
    }
    goto skip_1;
    // 0x8010B7B8: swc1        $f14, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f14.u32l;
    skip_1:
    // 0x8010B7BC: swc1        $f12, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f12.u32l;
    // 0x8010B7C0: b           L_8010B7D0
    // 0x8010B7C4: swc1        $f14, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f14.u32l;
        goto L_8010B7D0;
    // 0x8010B7C4: swc1        $f14, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f14.u32l;
    // 0x8010B7C8: swc1        $f14, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f14.u32l;
L_8010B7CC:
    // 0x8010B7CC: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
L_8010B7D0:
    // 0x8010B7D0: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8010B7D4: lwc1        $f2, 0x18($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8010B7D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B7DC: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8010B7E0: bc1fl       L_8010B7F8
    if (!c1cs) {
        // 0x8010B7E4: swc1        $f2, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
            goto L_8010B7F8;
    }
    goto skip_2;
    // 0x8010B7E4: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    skip_2:
    // 0x8010B7E8: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x8010B7EC: b           L_8010B7FC
    // 0x8010B7F0: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
        goto L_8010B7FC;
    // 0x8010B7F0: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
    // 0x8010B7F4: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
L_8010B7F8:
    // 0x8010B7F8: swc1        $f0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f0.u32l;
L_8010B7FC:
    // 0x8010B7FC: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
    // 0x8010B800: swc1        $f4, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f4.u32l;
    // 0x8010B804: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x8010B808: swc1        $f8, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f8.u32l;
    // 0x8010B80C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x8010B810: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8010B814: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8010B818: beq         $t6, $at, L_8010C1E0
    if (ctx->r14 == ctx->r1) {
        // 0x8010B81C: addu        $a1, $s2, $s4
        ctx->r5 = ADD32(ctx->r18, ctx->r20);
            goto L_8010C1E0;
    }
    // 0x8010B81C: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
L_8010B820:
    // 0x8010B820: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
    // 0x8010B824: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8010B828: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8010B82C: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010B830: beql        $at, $zero, L_8010B884
    if (ctx->r1 == 0) {
        // 0x8010B834: lh          $a2, 0xC($a1)
        ctx->r6 = MEM_H(ctx->r5, 0XC);
            goto L_8010B884;
    }
    goto skip_3;
    // 0x8010B834: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    skip_3:
    // 0x8010B838: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    // 0x8010B83C: sll         $s0, $t4, 16
    ctx->r16 = S32(ctx->r12 << 16);
    // 0x8010B840: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010B844: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010B848: beq         $at, $zero, L_8010B878
    if (ctx->r1 == 0) {
        // 0x8010B84C: sll         $s1, $a2, 16
        ctx->r17 = S32(ctx->r6 << 16);
            goto L_8010B878;
    }
    // 0x8010B84C: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x8010B850: sll         $s1, $t1, 16
    ctx->r17 = S32(ctx->r9 << 16);
    // 0x8010B854: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010B858: beq         $at, $zero, L_8010B86C
    if (ctx->r1 == 0) {
        // 0x8010B85C: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_8010B86C;
    }
    // 0x8010B85C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010B860: sll         $s0, $t4, 16
    ctx->r16 = S32(ctx->r12 << 16);
    // 0x8010B864: b           L_8010B8C4
    // 0x8010B868: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010B8C4;
    // 0x8010B868: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010B86C:
    // 0x8010B86C: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x8010B870: b           L_8010B8C4
    // 0x8010B874: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010B8C4;
    // 0x8010B874: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010B878:
    // 0x8010B878: b           L_8010B8C4
    // 0x8010B87C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
        goto L_8010B8C4;
    // 0x8010B87C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010B880: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
L_8010B884:
    // 0x8010B884: sll         $s0, $t1, 16
    ctx->r16 = S32(ctx->r9 << 16);
    // 0x8010B888: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010B88C: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8010B890: beq         $at, $zero, L_8010B8C0
    if (ctx->r1 == 0) {
        // 0x8010B894: sll         $s1, $a2, 16
        ctx->r17 = S32(ctx->r6 << 16);
            goto L_8010B8C0;
    }
    // 0x8010B894: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x8010B898: sll         $s1, $t4, 16
    ctx->r17 = S32(ctx->r12 << 16);
    // 0x8010B89C: slt         $at, $t1, $a2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010B8A0: beq         $at, $zero, L_8010B8B4
    if (ctx->r1 == 0) {
        // 0x8010B8A4: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_8010B8B4;
    }
    // 0x8010B8A4: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010B8A8: sll         $s0, $t1, 16
    ctx->r16 = S32(ctx->r9 << 16);
    // 0x8010B8AC: b           L_8010B8C4
    // 0x8010B8B0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010B8C4;
    // 0x8010B8B0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010B8B4:
    // 0x8010B8B4: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x8010B8B8: b           L_8010B8C4
    // 0x8010B8BC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010B8C4;
    // 0x8010B8BC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010B8C0:
    // 0x8010B8C0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_8010B8C4:
    // 0x8010B8C4: lh          $t5, 0x2($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2);
    // 0x8010B8C8: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x8010B8CC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8010B8D0: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010B8D4: beq         $at, $zero, L_8010B924
    if (ctx->r1 == 0) {
        // 0x8010B8D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8010B924;
    }
    // 0x8010B8D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010B8DC: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010B8E0: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x8010B8E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010B8E8: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010B8EC: beq         $at, $zero, L_8010B91C
    if (ctx->r1 == 0) {
        // 0x8010B8F0: sll         $a2, $a3, 16
        ctx->r6 = S32(ctx->r7 << 16);
            goto L_8010B91C;
    }
    // 0x8010B8F0: sll         $a2, $a3, 16
    ctx->r6 = S32(ctx->r7 << 16);
    // 0x8010B8F4: sll         $a2, $t2, 16
    ctx->r6 = S32(ctx->r10 << 16);
    // 0x8010B8F8: slt         $at, $t5, $a3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010B8FC: beq         $at, $zero, L_8010B910
    if (ctx->r1 == 0) {
        // 0x8010B900: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8010B910;
    }
    // 0x8010B900: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010B904: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x8010B908: b           L_8010B968
    // 0x8010B90C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010B968;
    // 0x8010B90C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010B910:
    // 0x8010B910: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8010B914: b           L_8010B968
    // 0x8010B918: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010B968;
    // 0x8010B918: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010B91C:
    // 0x8010B91C: b           L_8010B968
    // 0x8010B920: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8010B968;
    // 0x8010B920: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010B924:
    // 0x8010B924: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010B928: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8010B92C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010B930: slt         $at, $a3, $t5
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8010B934: beq         $at, $zero, L_8010B964
    if (ctx->r1 == 0) {
        // 0x8010B938: sll         $a2, $a3, 16
        ctx->r6 = S32(ctx->r7 << 16);
            goto L_8010B964;
    }
    // 0x8010B938: sll         $a2, $a3, 16
    ctx->r6 = S32(ctx->r7 << 16);
    // 0x8010B93C: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x8010B940: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010B944: beq         $at, $zero, L_8010B958
    if (ctx->r1 == 0) {
        // 0x8010B948: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8010B958;
    }
    // 0x8010B948: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010B94C: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8010B950: b           L_8010B968
    // 0x8010B954: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010B968;
    // 0x8010B954: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010B958:
    // 0x8010B958: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8010B95C: b           L_8010B968
    // 0x8010B960: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010B968;
    // 0x8010B960: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010B964:
    // 0x8010B964: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010B968:
    // 0x8010B968: lh          $ra, 0x4($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X4);
    // 0x8010B96C: lh          $t3, 0xA($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XA);
    // 0x8010B970: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8010B974: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010B978: beql        $at, $zero, L_8010B9CC
    if (ctx->r1 == 0) {
        // 0x8010B97C: lh          $t0, 0x10($a1)
        ctx->r8 = MEM_H(ctx->r5, 0X10);
            goto L_8010B9CC;
    }
    goto skip_4;
    // 0x8010B97C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    skip_4:
    // 0x8010B980: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8010B984: sll         $v0, $ra, 16
    ctx->r2 = S32(ctx->r31 << 16);
    // 0x8010B988: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8010B98C: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010B990: beq         $at, $zero, L_8010B9C0
    if (ctx->r1 == 0) {
        // 0x8010B994: sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8 << 16);
            goto L_8010B9C0;
    }
    // 0x8010B994: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8010B998: sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11 << 16);
    // 0x8010B99C: slt         $at, $ra, $t0
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010B9A0: beq         $at, $zero, L_8010B9B4
    if (ctx->r1 == 0) {
        // 0x8010B9A4: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8010B9B4;
    }
    // 0x8010B9A4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010B9A8: sll         $v0, $ra, 16
    ctx->r2 = S32(ctx->r31 << 16);
    // 0x8010B9AC: b           L_8010BA0C
    // 0x8010B9B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010BA0C;
    // 0x8010B9B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010B9B4:
    // 0x8010B9B4: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8010B9B8: b           L_8010BA0C
    // 0x8010B9BC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010BA0C;
    // 0x8010B9BC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010B9C0:
    // 0x8010B9C0: b           L_8010BA0C
    // 0x8010B9C4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8010BA0C;
    // 0x8010B9C4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010B9C8: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
L_8010B9CC:
    // 0x8010B9CC: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x8010B9D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8010B9D4: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8010B9D8: beq         $at, $zero, L_8010BA08
    if (ctx->r1 == 0) {
        // 0x8010B9DC: sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8 << 16);
            goto L_8010BA08;
    }
    // 0x8010B9DC: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8010B9E0: sll         $v1, $ra, 16
    ctx->r3 = S32(ctx->r31 << 16);
    // 0x8010B9E4: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010B9E8: beq         $at, $zero, L_8010B9FC
    if (ctx->r1 == 0) {
        // 0x8010B9EC: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8010B9FC;
    }
    // 0x8010B9EC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010B9F0: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x8010B9F4: b           L_8010BA0C
    // 0x8010B9F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010BA0C;
    // 0x8010B9F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010B9FC:
    // 0x8010B9FC: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8010BA00: b           L_8010BA0C
    // 0x8010BA04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010BA0C;
    // 0x8010BA04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010BA08:
    // 0x8010BA08: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8010BA0C:
    // 0x8010BA0C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8010BA10: nop

    // 0x8010BA14: bc1tl       L_8010C1C8
    if (c1cs) {
        // 0x8010BA18: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_5;
    // 0x8010BA18: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_5:
    // 0x8010BA1C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x8010BA20: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8010BA24: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BA28: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8010BA2C: nop

    // 0x8010BA30: bc1tl       L_8010C1C8
    if (c1cs) {
        // 0x8010BA34: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_6;
    // 0x8010BA34: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_6:
    // 0x8010BA38: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x8010BA3C: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8010BA40: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BA44: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8010BA48: nop

    // 0x8010BA4C: bc1tl       L_8010C1C8
    if (c1cs) {
        // 0x8010BA50: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_7;
    // 0x8010BA50: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_7:
    // 0x8010BA54: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8010BA58: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8010BA5C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BA60: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8010BA64: nop

    // 0x8010BA68: bc1tl       L_8010C1C8
    if (c1cs) {
        // 0x8010BA6C: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_8;
    // 0x8010BA6C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_8:
    // 0x8010BA70: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8010BA74: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8010BA78: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BA7C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8010BA80: nop

    // 0x8010BA84: bc1tl       L_8010C1C8
    if (c1cs) {
        // 0x8010BA88: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_9;
    // 0x8010BA88: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_9:
    // 0x8010BA8C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8010BA90: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8010BA94: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8010BA98: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BA9C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8010BAA0: nop

    // 0x8010BAA4: bc1tl       L_8010C1C8
    if (c1cs) {
        // 0x8010BAA8: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_10;
    // 0x8010BAA8: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_10:
    // 0x8010BAAC: lw          $t9, -0x452C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X452C);
    // 0x8010BAB0: addu        $t7, $s2, $s4
    ctx->r15 = ADD32(ctx->r18, ctx->r20);
    // 0x8010BAB4: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8010BAB8: jalr        $t9
    // 0x8010BABC: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8010BABC: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010BAC0: beq         $v0, $zero, L_8010C1C4
    if (ctx->r2 == 0) {
        // 0x8010BAC4: lw          $a1, 0xEC($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XEC);
            goto L_8010C1C4;
    }
    // 0x8010BAC4: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8010BAC8: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x8010BACC: lh          $t5, 0x2($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2);
    // 0x8010BAD0: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8010BAD4: lh          $ra, 0x4($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X4);
    // 0x8010BAD8: subu        $s0, $t2, $t5
    ctx->r16 = SUB32(ctx->r10, ctx->r13);
    // 0x8010BADC: lh          $t3, 0xA($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XA);
    // 0x8010BAE0: subu        $v0, $t0, $ra
    ctx->r2 = SUB32(ctx->r8, ctx->r31);
    // 0x8010BAE4: multu       $s0, $v0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010BAE8: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010BAEC: subu        $s1, $t3, $ra
    ctx->r17 = SUB32(ctx->r11, ctx->r31);
    // 0x8010BAF0: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    // 0x8010BAF4: subu        $v1, $a3, $t5
    ctx->r3 = SUB32(ctx->r7, ctx->r13);
    // 0x8010BAF8: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x8010BAFC: lh          $t1, 0x6($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X6);
    // 0x8010BB00: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8010BB04: subu        $a0, $a2, $t4
    ctx->r4 = SUB32(ctx->r6, ctx->r12);
    // 0x8010BB08: subu        $s2, $t1, $t4
    ctx->r18 = SUB32(ctx->r9, ctx->r12);
    // 0x8010BB0C: mflo        $t8
    ctx->r24 = lo;
    // 0x8010BB10: nop

    // 0x8010BB14: nop

    // 0x8010BB18: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010BB1C: mflo        $t6
    ctx->r14 = lo;
    // 0x8010BB20: subu        $t7, $t8, $t6
    ctx->r15 = SUB32(ctx->r24, ctx->r14);
    // 0x8010BB24: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010BB28: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010BB2C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BB30: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010BB34: mflo        $t9
    ctx->r25 = lo;
    // 0x8010BB38: nop

    // 0x8010BB3C: nop

    // 0x8010BB40: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010BB44: mflo        $t8
    ctx->r24 = lo;
    // 0x8010BB48: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x8010BB4C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8010BB50: multu       $s2, $v1
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010BB54: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BB58: lwc1        $f6, 0x118($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8010BB5C: mflo        $t7
    ctx->r15 = lo;
    // 0x8010BB60: nop

    // 0x8010BB64: nop

    // 0x8010BB68: multu       $s0, $a0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010BB6C: mflo        $t9
    ctx->r25 = lo;
    // 0x8010BB70: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8010BB74: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8010BB78: nop

    // 0x8010BB7C: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BB80: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8010BB84: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010BB88: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8010BB8C: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010BB90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010BB94: add.s       $f26, $f6, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010BB98: c.lt.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl < ctx->f8.fl;
    // 0x8010BB9C: swc1        $f26, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f26.u32l;
    // 0x8010BBA0: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BBA4: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_11;
    // 0x8010BBA4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_11:
    // 0x8010BBA8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8010BBAC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8010BBB0: mtc1        $ra, $f6
    ctx->f6.u32l = ctx->r31;
    // 0x8010BBB4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BBB8: lwc1        $f22, 0x4($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8010BBBC: lwc1        $f24, 0x8($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8010BBC0: lwc1        $f28, 0xC($s3)
    ctx->f28.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8010BBC4: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x8010BBC8: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BBCC: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8010BBD0: swc1        $f12, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f12.u32l;
    // 0x8010BBD4: swc1        $f2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f2.u32l;
    // 0x8010BBD8: swc1        $f22, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f22.u32l;
    // 0x8010BBDC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BBE0: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010BBE4: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x8010BBE8: swc1        $f24, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f24.u32l;
    // 0x8010BBEC: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8010BBF0: swc1        $f28, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f28.u32l;
    // 0x8010BBF4: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8010BBF8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010BBFC: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8010BC00: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8010BC04: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x8010BC08: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010BC0C: mul.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8010BC10: nop

    // 0x8010BC14: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8010BC18: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8010BC1C: swc1        $f14, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f14.u32l;
    // 0x8010BC20: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010BC24: mul.s       $f6, $f12, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x8010BC28: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010BC2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010BC30: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8010BC34: mul.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8010BC38: swc1        $f10, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f10.u32l;
    // 0x8010BC3C: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x8010BC40: nop

    // 0x8010BC44: bc1f        L_8010BC60
    if (!c1cs) {
        // 0x8010BC48: nop
    
            goto L_8010BC60;
    }
    // 0x8010BC48: nop

    // 0x8010BC4C: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8010BC50: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x8010BC54: nop

    // 0x8010BC58: bc1tl       L_8010BC90
    if (c1cs) {
        // 0x8010BC5C: lwc1        $f0, 0x118($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X118);
            goto L_8010BC90;
    }
    goto skip_12;
    // 0x8010BC5C: lwc1        $f0, 0x118($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X118);
    skip_12:
L_8010BC60:
    // 0x8010BC60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010BC64: nop

    // 0x8010BC68: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x8010BC6C: nop

    // 0x8010BC70: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BC74: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_13;
    // 0x8010BC74: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_13:
    // 0x8010BC78: mul.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8010BC7C: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x8010BC80: nop

    // 0x8010BC84: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BC88: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_14;
    // 0x8010BC88: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_14:
    // 0x8010BC8C: lwc1        $f0, 0x118($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X118);
L_8010BC90:
    // 0x8010BC90: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8010BC94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010BC98: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010BC9C: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8010BCA0: nop

    // 0x8010BCA4: bc1fl       L_8010BCC4
    if (!c1cs) {
        // 0x8010BCA8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010BCC4;
    }
    goto skip_15;
    // 0x8010BCA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_15:
    // 0x8010BCAC: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8010BCB0: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8010BCB4: nop

    // 0x8010BCB8: bc1tl       L_8010BCF0
    if (c1cs) {
        // 0x8010BCBC: lwc1        $f8, 0x114($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
            goto L_8010BCF0;
    }
    goto skip_16;
    // 0x8010BCBC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    skip_16:
    // 0x8010BCC0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8010BCC4:
    // 0x8010BCC4: nop

    // 0x8010BCC8: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x8010BCCC: nop

    // 0x8010BCD0: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BCD4: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_17;
    // 0x8010BCD4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_17:
    // 0x8010BCD8: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8010BCDC: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8010BCE0: nop

    // 0x8010BCE4: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BCE8: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_18;
    // 0x8010BCE8: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_18:
    // 0x8010BCEC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
L_8010BCF0:
    // 0x8010BCF0: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8010BCF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010BCF8: mul.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8010BCFC: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8010BD00: nop

    // 0x8010BD04: bc1fl       L_8010BD24
    if (!c1cs) {
        // 0x8010BD08: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8010BD24;
    }
    goto skip_19;
    // 0x8010BD08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_19:
    // 0x8010BD0C: mul.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8010BD10: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x8010BD14: nop

    // 0x8010BD18: bc1tl       L_8010BD50
    if (c1cs) {
        // 0x8010BD1C: lwc1        $f18, 0x108($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
            goto L_8010BD50;
    }
    goto skip_20;
    // 0x8010BD1C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    skip_20:
    // 0x8010BD20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8010BD24:
    // 0x8010BD24: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8010BD28: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8010BD2C: nop

    // 0x8010BD30: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BD34: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_21;
    // 0x8010BD34: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_21:
    // 0x8010BD38: mul.s       $f8, $f10, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8010BD3C: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8010BD40: nop

    // 0x8010BD44: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BD48: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_22;
    // 0x8010BD48: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_22:
    // 0x8010BD4C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
L_8010BD50:
    // 0x8010BD50: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8010BD54: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010BD58: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8010BD5C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010BD60: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010BD64: add.s       $f28, $f20, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8010BD68: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8010BD6C: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8010BD70: add.s       $f30, $f12, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8010BD74: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8010BD78: nop

    // 0x8010BD7C: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BD80: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010BD84: add.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8010BD88: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8010BD8C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BD90: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    // 0x8010BD94: mul.s       $f10, $f22, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8010BD98: nop

    // 0x8010BD9C: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010BDA0: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010BDA4: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x8010BDA8: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010BDAC: cvt.s.w     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BDB0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010BDB4: nop

    // 0x8010BDB8: mul.s       $f4, $f24, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8010BDBC: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8010BDC0: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8010BDC4: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010BDC8: mul.s       $f4, $f22, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8010BDCC: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8010BDD0: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8010BDD4: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010BDD8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010BDDC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010BDE0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010BDE4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010BDE8: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8010BDEC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8010BDF0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BDF4: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010BDF8: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8010BDFC: swc1        $f12, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f12.u32l;
    // 0x8010BE00: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BE04: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8010BE08: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010BE0C: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    // 0x8010BE10: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BE14: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x8010BE18: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010BE1C: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010BE20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010BE24: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8010BE28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010BE2C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010BE30: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8010BE34: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8010BE38: nop

    // 0x8010BE3C: bc1f        L_8010BE78
    if (!c1cs) {
        // 0x8010BE40: nop
    
            goto L_8010BE78;
    }
    // 0x8010BE40: nop

    // 0x8010BE44: mul.s       $f10, $f14, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010BE48: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010BE4C: mul.s       $f8, $f16, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010BE50: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010BE54: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8010BE58: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010BE5C: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010BE60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010BE64: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010BE68: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8010BE6C: nop

    // 0x8010BE70: bc1tl       L_8010BEC4
    if (c1cs) {
        // 0x8010BE74: subu        $t6, $a3, $t2
        ctx->r14 = SUB32(ctx->r7, ctx->r10);
            goto L_8010BEC4;
    }
    goto skip_23;
    // 0x8010BE74: subu        $t6, $a3, $t2
    ctx->r14 = SUB32(ctx->r7, ctx->r10);
    skip_23:
L_8010BE78:
    // 0x8010BE78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010BE7C: nop

    // 0x8010BE80: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8010BE84: nop

    // 0x8010BE88: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BE8C: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_24;
    // 0x8010BE8C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_24:
    // 0x8010BE90: mul.s       $f4, $f14, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010BE94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010BE98: mul.s       $f10, $f16, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010BE9C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010BEA0: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010BEA4: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010BEA8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010BEAC: mul.s       $f8, $f20, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010BEB0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010BEB4: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8010BEB8: nop

    // 0x8010BEBC: bc1f        L_8010C1C4
    if (!c1cs) {
        // 0x8010BEC0: subu        $t6, $a3, $t2
        ctx->r14 = SUB32(ctx->r7, ctx->r10);
            goto L_8010C1C4;
    }
    // 0x8010BEC0: subu        $t6, $a3, $t2
    ctx->r14 = SUB32(ctx->r7, ctx->r10);
L_8010BEC4:
    // 0x8010BEC4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010BEC8: subu        $t7, $t0, $t3
    ctx->r15 = SUB32(ctx->r8, ctx->r11);
    // 0x8010BECC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010BED0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BED4: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8010BED8: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010BEDC: subu        $t9, $a2, $t1
    ctx->r25 = SUB32(ctx->r6, ctx->r9);
    // 0x8010BEE0: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BEE4: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010BEE8: nop

    // 0x8010BEEC: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8010BEF0: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010BEF4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8010BEF8: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010BEFC: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BF00: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8010BF04: nop

    // 0x8010BF08: mul.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010BF0C: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010BF10: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8010BF14: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8010BF18: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010BF1C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8010BF20: nop

    // 0x8010BF24: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BF28: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010BF2C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8010BF30: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BF34: mul.s       $f4, $f14, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8010BF38: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BF3C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8010BF40: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010BF44: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8010BF48: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010BF4C: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8010BF50: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010BF54: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8010BF58: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010BF5C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010BF60: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8010BF64: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010BF68: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010BF6C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010BF70: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8010BF74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010BF78: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010BF7C: add.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8010BF80: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8010BF84: nop

    // 0x8010BF88: bc1f        L_8010BFC4
    if (!c1cs) {
        // 0x8010BF8C: nop
    
            goto L_8010BFC4;
    }
    // 0x8010BF8C: nop

    // 0x8010BF90: mul.s       $f10, $f14, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010BF94: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010BF98: mul.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010BF9C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010BFA0: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8010BFA4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010BFA8: mul.s       $f8, $f20, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010BFAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010BFB0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010BFB4: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8010BFB8: nop

    // 0x8010BFBC: bc1tl       L_8010C010
    if (c1cs) {
        // 0x8010BFC0: subu        $t8, $t5, $a3
        ctx->r24 = SUB32(ctx->r13, ctx->r7);
            goto L_8010C010;
    }
    goto skip_25;
    // 0x8010BFC0: subu        $t8, $t5, $a3
    ctx->r24 = SUB32(ctx->r13, ctx->r7);
    skip_25:
L_8010BFC4:
    // 0x8010BFC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010BFC8: nop

    // 0x8010BFCC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8010BFD0: nop

    // 0x8010BFD4: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010BFD8: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_26;
    // 0x8010BFD8: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_26:
    // 0x8010BFDC: mul.s       $f6, $f14, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010BFE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010BFE4: mul.s       $f10, $f16, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010BFE8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010BFEC: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010BFF0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8010BFF4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010BFF8: mul.s       $f4, $f20, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010BFFC: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010C000: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8010C004: nop

    // 0x8010C008: bc1f        L_8010C1C4
    if (!c1cs) {
        // 0x8010C00C: subu        $t8, $t5, $a3
        ctx->r24 = SUB32(ctx->r13, ctx->r7);
            goto L_8010C1C4;
    }
    // 0x8010C00C: subu        $t8, $t5, $a3
    ctx->r24 = SUB32(ctx->r13, ctx->r7);
L_8010C010:
    // 0x8010C010: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010C014: subu        $t6, $ra, $t0
    ctx->r14 = SUB32(ctx->r31, ctx->r8);
    // 0x8010C018: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010C01C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C020: lwc1        $f8, 0x124($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8010C024: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010C028: subu        $t7, $t4, $a2
    ctx->r15 = SUB32(ctx->r12, ctx->r6);
    // 0x8010C02C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C030: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010C034: nop

    // 0x8010C038: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8010C03C: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8010C040: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010C044: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010C048: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C04C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010C050: nop

    // 0x8010C054: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010C058: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010C05C: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010C060: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010C064: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C068: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010C06C: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8010C070: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010C074: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010C078: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8010C07C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010C080: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010C084: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010C088: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8010C08C: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010C090: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010C094: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010C098: mul.s       $f10, $f22, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8010C09C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010C0A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010C0A4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010C0A8: add.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8010C0AC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8010C0B0: nop

    // 0x8010C0B4: bc1f        L_8010C0F0
    if (!c1cs) {
        // 0x8010C0B8: nop
    
            goto L_8010C0F0;
    }
    // 0x8010C0B8: nop

    // 0x8010C0BC: mul.s       $f10, $f14, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010C0C0: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010C0C4: mul.s       $f6, $f16, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010C0C8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010C0CC: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010C0D0: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010C0D4: mul.s       $f4, $f20, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010C0D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010C0DC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010C0E0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8010C0E4: nop

    // 0x8010C0E8: bc1tl       L_8010C140
    if (c1cs) {
        // 0x8010C0EC: lwc1        $f8, 0x10C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
            goto L_8010C140;
    }
    goto skip_27;
    // 0x8010C0EC: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    skip_27:
L_8010C0F0:
    // 0x8010C0F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010C0F4: nop

    // 0x8010C0F8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8010C0FC: nop

    // 0x8010C100: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010C104: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_28;
    // 0x8010C104: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_28:
    // 0x8010C108: mul.s       $f8, $f14, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010C10C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010C110: mul.s       $f10, $f16, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010C114: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010C118: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010C11C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8010C120: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010C124: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010C128: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010C12C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8010C130: nop

    // 0x8010C134: bc1fl       L_8010C1C8
    if (!c1cs) {
        // 0x8010C138: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010C1C8;
    }
    goto skip_29;
    // 0x8010C138: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_29:
    // 0x8010C13C: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
L_8010C140:
    // 0x8010C140: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8010C144: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8010C148: div.s       $f0, $f8, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8010C14C: lwc1        $f14, 0x114($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8010C150: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8010C154: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8010C158: nop

    // 0x8010C15C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8010C160: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010C164: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8010C168: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010C16C: lwc1        $f10, 0x20($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X20);
    // 0x8010C170: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010C174: nop

    // 0x8010C178: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010C17C: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8010C180: nop

    // 0x8010C184: bc1f        L_8010C1C4
    if (!c1cs) {
        // 0x8010C188: nop
    
            goto L_8010C1C4;
    }
    // 0x8010C188: nop

    // 0x8010C18C: sw          $t9, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r25;
    // 0x8010C190: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8010C194: swc1        $f12, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f12.u32l;
    // 0x8010C198: addu        $t6, $t8, $s4
    ctx->r14 = ADD32(ctx->r24, ctx->r20);
    // 0x8010C19C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8010C1A0: sb          $t7, 0x1C($s3)
    MEM_B(0X1C, ctx->r19) = ctx->r15;
    // 0x8010C1A4: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010C1A8: swc1        $f8, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f8.u32l;
    // 0x8010C1AC: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010C1B0: swc1        $f6, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f6.u32l;
    // 0x8010C1B4: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8010C1B8: swc1        $f4, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f4.u32l;
    // 0x8010C1BC: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8010C1C0: swc1        $f10, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->f10.u32l;
L_8010C1C4:
    // 0x8010C1C4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
L_8010C1C8:
    // 0x8010C1C8: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x8010C1CC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8010C1D0: addu        $t9, $s2, $s4
    ctx->r25 = ADD32(ctx->r18, ctx->r20);
    // 0x8010C1D4: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x8010C1D8: bnel        $t8, $at, L_8010B820
    if (ctx->r24 != ctx->r1) {
        // 0x8010C1DC: addu        $a1, $s2, $s4
        ctx->r5 = ADD32(ctx->r18, ctx->r20);
            goto L_8010B820;
    }
    goto skip_30;
    // 0x8010C1DC: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
    skip_30:
L_8010C1E0:
    // 0x8010C1E0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8010C1E4: lw          $v0, 0x130($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X130);
    // 0x8010C1E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010C1EC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010C1F0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010C1F4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010C1F8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8010C1FC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8010C200: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8010C204: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8010C208: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8010C20C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8010C210: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8010C214: jr          $ra
    // 0x8010C218: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x8010C218: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010c21c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010c21c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C21C: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x8010C220: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8010C224: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8010C228: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8010C22C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8010C230: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8010C234: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8010C238: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8010C23C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8010C240: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8010C244: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010C248: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010C24C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010C250: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010C254: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010C258: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8010C25C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8010C260: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8010C264: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8010C268: bc1fl       L_8010C280
    if (!c1cs) {
        // 0x8010C26C: swc1        $f18, 0xD4($sp)
        MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
            goto L_8010C280;
    }
    goto skip_0;
    // 0x8010C26C: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    skip_0:
    // 0x8010C270: swc1        $f16, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f16.u32l;
    // 0x8010C274: b           L_8010C284
    // 0x8010C278: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
        goto L_8010C284;
    // 0x8010C278: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x8010C27C: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
L_8010C280:
    // 0x8010C280: swc1        $f16, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f16.u32l;
L_8010C284:
    // 0x8010C284: lwc1        $f12, 0x8($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8010C288: lwc1        $f14, 0x14($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8010C28C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8010C290: sub.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x8010C294: bc1fl       L_8010C2AC
    if (!c1cs) {
        // 0x8010C298: swc1        $f14, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f14.u32l;
            goto L_8010C2AC;
    }
    goto skip_1;
    // 0x8010C298: swc1        $f14, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f14.u32l;
    skip_1:
    // 0x8010C29C: swc1        $f12, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f12.u32l;
    // 0x8010C2A0: b           L_8010C2B0
    // 0x8010C2A4: swc1        $f14, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f14.u32l;
        goto L_8010C2B0;
    // 0x8010C2A4: swc1        $f14, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f14.u32l;
    // 0x8010C2A8: swc1        $f14, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f14.u32l;
L_8010C2AC:
    // 0x8010C2AC: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
L_8010C2B0:
    // 0x8010C2B0: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8010C2B4: lwc1        $f2, 0x18($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X18);
    // 0x8010C2B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010C2BC: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8010C2C0: bc1fl       L_8010C2D8
    if (!c1cs) {
        // 0x8010C2C4: swc1        $f2, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->f2.u32l;
            goto L_8010C2D8;
    }
    goto skip_2;
    // 0x8010C2C4: swc1        $f2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f2.u32l;
    skip_2:
    // 0x8010C2C8: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x8010C2CC: b           L_8010C2DC
    // 0x8010C2D0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
        goto L_8010C2DC;
    // 0x8010C2D0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    // 0x8010C2D4: swc1        $f2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f2.u32l;
L_8010C2D8:
    // 0x8010C2D8: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
L_8010C2DC:
    // 0x8010C2DC: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
    // 0x8010C2E0: swc1        $f6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f6.u32l;
    // 0x8010C2E4: swc1        $f8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f8.u32l;
    // 0x8010C2E8: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    // 0x8010C2EC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8010C2F0: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8010C2F4: beq         $t6, $at, L_8010CC2C
    if (ctx->r14 == ctx->r1) {
        // 0x8010C2F8: addu        $a1, $s2, $s3
        ctx->r5 = ADD32(ctx->r18, ctx->r19);
            goto L_8010CC2C;
    }
    // 0x8010C2F8: addu        $a1, $s2, $s3
    ctx->r5 = ADD32(ctx->r18, ctx->r19);
L_8010C2FC:
    // 0x8010C2FC: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
    // 0x8010C300: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8010C304: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8010C308: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010C30C: beql        $at, $zero, L_8010C360
    if (ctx->r1 == 0) {
        // 0x8010C310: lh          $a2, 0xC($a1)
        ctx->r6 = MEM_H(ctx->r5, 0XC);
            goto L_8010C360;
    }
    goto skip_3;
    // 0x8010C310: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    skip_3:
    // 0x8010C314: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    // 0x8010C318: sll         $s0, $t4, 16
    ctx->r16 = S32(ctx->r12 << 16);
    // 0x8010C31C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010C320: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010C324: beq         $at, $zero, L_8010C354
    if (ctx->r1 == 0) {
        // 0x8010C328: sll         $s1, $a2, 16
        ctx->r17 = S32(ctx->r6 << 16);
            goto L_8010C354;
    }
    // 0x8010C328: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x8010C32C: sll         $s1, $t1, 16
    ctx->r17 = S32(ctx->r9 << 16);
    // 0x8010C330: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010C334: beq         $at, $zero, L_8010C348
    if (ctx->r1 == 0) {
        // 0x8010C338: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_8010C348;
    }
    // 0x8010C338: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010C33C: sll         $s0, $t4, 16
    ctx->r16 = S32(ctx->r12 << 16);
    // 0x8010C340: b           L_8010C3A0
    // 0x8010C344: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010C3A0;
    // 0x8010C344: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010C348:
    // 0x8010C348: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x8010C34C: b           L_8010C3A0
    // 0x8010C350: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010C3A0;
    // 0x8010C350: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010C354:
    // 0x8010C354: b           L_8010C3A0
    // 0x8010C358: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
        goto L_8010C3A0;
    // 0x8010C358: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010C35C: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
L_8010C360:
    // 0x8010C360: sll         $s0, $t1, 16
    ctx->r16 = S32(ctx->r9 << 16);
    // 0x8010C364: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8010C368: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8010C36C: beq         $at, $zero, L_8010C39C
    if (ctx->r1 == 0) {
        // 0x8010C370: sll         $s1, $a2, 16
        ctx->r17 = S32(ctx->r6 << 16);
            goto L_8010C39C;
    }
    // 0x8010C370: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x8010C374: sll         $s1, $t4, 16
    ctx->r17 = S32(ctx->r12 << 16);
    // 0x8010C378: slt         $at, $t1, $a2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010C37C: beq         $at, $zero, L_8010C390
    if (ctx->r1 == 0) {
        // 0x8010C380: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_8010C390;
    }
    // 0x8010C380: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010C384: sll         $s0, $t1, 16
    ctx->r16 = S32(ctx->r9 << 16);
    // 0x8010C388: b           L_8010C3A0
    // 0x8010C38C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010C3A0;
    // 0x8010C38C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010C390:
    // 0x8010C390: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x8010C394: b           L_8010C3A0
    // 0x8010C398: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
        goto L_8010C3A0;
    // 0x8010C398: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8010C39C:
    // 0x8010C39C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_8010C3A0:
    // 0x8010C3A0: lh          $t5, 0x2($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2);
    // 0x8010C3A4: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x8010C3A8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8010C3AC: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010C3B0: beq         $at, $zero, L_8010C400
    if (ctx->r1 == 0) {
        // 0x8010C3B4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8010C400;
    }
    // 0x8010C3B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C3B8: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010C3BC: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x8010C3C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010C3C4: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8010C3C8: beq         $at, $zero, L_8010C3F8
    if (ctx->r1 == 0) {
        // 0x8010C3CC: sll         $a2, $a3, 16
        ctx->r6 = S32(ctx->r7 << 16);
            goto L_8010C3F8;
    }
    // 0x8010C3CC: sll         $a2, $a3, 16
    ctx->r6 = S32(ctx->r7 << 16);
    // 0x8010C3D0: sll         $a2, $t2, 16
    ctx->r6 = S32(ctx->r10 << 16);
    // 0x8010C3D4: slt         $at, $t5, $a3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010C3D8: beq         $at, $zero, L_8010C3EC
    if (ctx->r1 == 0) {
        // 0x8010C3DC: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8010C3EC;
    }
    // 0x8010C3DC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010C3E0: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x8010C3E4: b           L_8010C444
    // 0x8010C3E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010C444;
    // 0x8010C3E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010C3EC:
    // 0x8010C3EC: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8010C3F0: b           L_8010C444
    // 0x8010C3F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010C444;
    // 0x8010C3F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010C3F8:
    // 0x8010C3F8: b           L_8010C444
    // 0x8010C3FC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8010C444;
    // 0x8010C3FC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010C400:
    // 0x8010C400: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010C404: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8010C408: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010C40C: slt         $at, $a3, $t5
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8010C410: beq         $at, $zero, L_8010C440
    if (ctx->r1 == 0) {
        // 0x8010C414: sll         $a2, $a3, 16
        ctx->r6 = S32(ctx->r7 << 16);
            goto L_8010C440;
    }
    // 0x8010C414: sll         $a2, $a3, 16
    ctx->r6 = S32(ctx->r7 << 16);
    // 0x8010C418: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x8010C41C: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010C420: beq         $at, $zero, L_8010C434
    if (ctx->r1 == 0) {
        // 0x8010C424: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8010C434;
    }
    // 0x8010C424: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010C428: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8010C42C: b           L_8010C444
    // 0x8010C430: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010C444;
    // 0x8010C430: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010C434:
    // 0x8010C434: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8010C438: b           L_8010C444
    // 0x8010C43C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010C444;
    // 0x8010C43C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010C440:
    // 0x8010C440: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010C444:
    // 0x8010C444: lh          $ra, 0x4($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X4);
    // 0x8010C448: lh          $t3, 0xA($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XA);
    // 0x8010C44C: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8010C450: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010C454: beql        $at, $zero, L_8010C4A8
    if (ctx->r1 == 0) {
        // 0x8010C458: lh          $t0, 0x10($a1)
        ctx->r8 = MEM_H(ctx->r5, 0X10);
            goto L_8010C4A8;
    }
    goto skip_4;
    // 0x8010C458: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    skip_4:
    // 0x8010C45C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8010C460: sll         $v0, $ra, 16
    ctx->r2 = S32(ctx->r31 << 16);
    // 0x8010C464: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8010C468: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010C46C: beq         $at, $zero, L_8010C49C
    if (ctx->r1 == 0) {
        // 0x8010C470: sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8 << 16);
            goto L_8010C49C;
    }
    // 0x8010C470: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8010C474: sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11 << 16);
    // 0x8010C478: slt         $at, $ra, $t0
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010C47C: beq         $at, $zero, L_8010C490
    if (ctx->r1 == 0) {
        // 0x8010C480: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8010C490;
    }
    // 0x8010C480: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010C484: sll         $v0, $ra, 16
    ctx->r2 = S32(ctx->r31 << 16);
    // 0x8010C488: b           L_8010C4E8
    // 0x8010C48C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010C4E8;
    // 0x8010C48C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010C490:
    // 0x8010C490: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8010C494: b           L_8010C4E8
    // 0x8010C498: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010C4E8;
    // 0x8010C498: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010C49C:
    // 0x8010C49C: b           L_8010C4E8
    // 0x8010C4A0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8010C4E8;
    // 0x8010C4A0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010C4A4: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
L_8010C4A8:
    // 0x8010C4A8: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x8010C4AC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8010C4B0: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8010C4B4: beq         $at, $zero, L_8010C4E4
    if (ctx->r1 == 0) {
        // 0x8010C4B8: sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8 << 16);
            goto L_8010C4E4;
    }
    // 0x8010C4B8: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8010C4BC: sll         $v1, $ra, 16
    ctx->r3 = S32(ctx->r31 << 16);
    // 0x8010C4C0: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010C4C4: beq         $at, $zero, L_8010C4D8
    if (ctx->r1 == 0) {
        // 0x8010C4C8: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8010C4D8;
    }
    // 0x8010C4C8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010C4CC: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x8010C4D0: b           L_8010C4E8
    // 0x8010C4D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010C4E8;
    // 0x8010C4D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010C4D8:
    // 0x8010C4D8: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8010C4DC: b           L_8010C4E8
    // 0x8010C4E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010C4E8;
    // 0x8010C4E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010C4E4:
    // 0x8010C4E4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8010C4E8:
    // 0x8010C4E8: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8010C4EC: nop

    // 0x8010C4F0: bc1tl       L_8010CC14
    if (c1cs) {
        // 0x8010C4F4: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_5;
    // 0x8010C4F4: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_5:
    // 0x8010C4F8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x8010C4FC: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8010C500: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010C504: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8010C508: nop

    // 0x8010C50C: bc1tl       L_8010CC14
    if (c1cs) {
        // 0x8010C510: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_6;
    // 0x8010C510: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_6:
    // 0x8010C514: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x8010C518: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8010C51C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010C520: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8010C524: nop

    // 0x8010C528: bc1tl       L_8010CC14
    if (c1cs) {
        // 0x8010C52C: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_7;
    // 0x8010C52C: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_7:
    // 0x8010C530: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8010C534: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8010C538: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C53C: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8010C540: nop

    // 0x8010C544: bc1tl       L_8010CC14
    if (c1cs) {
        // 0x8010C548: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_8;
    // 0x8010C548: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_8:
    // 0x8010C54C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8010C550: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8010C554: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C558: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8010C55C: nop

    // 0x8010C560: bc1tl       L_8010CC14
    if (c1cs) {
        // 0x8010C564: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_9;
    // 0x8010C564: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_9:
    // 0x8010C568: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8010C56C: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8010C570: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8010C574: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C578: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8010C57C: nop

    // 0x8010C580: bc1tl       L_8010CC14
    if (c1cs) {
        // 0x8010C584: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_10;
    // 0x8010C584: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_10:
    // 0x8010C588: lw          $t9, -0x452C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X452C);
    // 0x8010C58C: addu        $t7, $s2, $s3
    ctx->r15 = ADD32(ctx->r18, ctx->r19);
    // 0x8010C590: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8010C594: jalr        $t9
    // 0x8010C598: sw          $a1, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8010C598: sw          $a1, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010C59C: beq         $v0, $zero, L_8010CC10
    if (ctx->r2 == 0) {
        // 0x8010C5A0: lw          $a1, 0xF0($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XF0);
            goto L_8010CC10;
    }
    // 0x8010C5A0: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x8010C5A4: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x8010C5A8: lh          $t5, 0x2($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2);
    // 0x8010C5AC: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8010C5B0: lh          $ra, 0x4($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X4);
    // 0x8010C5B4: subu        $s0, $t2, $t5
    ctx->r16 = SUB32(ctx->r10, ctx->r13);
    // 0x8010C5B8: lh          $t3, 0xA($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XA);
    // 0x8010C5BC: subu        $v0, $t0, $ra
    ctx->r2 = SUB32(ctx->r8, ctx->r31);
    // 0x8010C5C0: multu       $s0, $v0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010C5C4: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010C5C8: subu        $s1, $t3, $ra
    ctx->r17 = SUB32(ctx->r11, ctx->r31);
    // 0x8010C5CC: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    // 0x8010C5D0: subu        $v1, $a3, $t5
    ctx->r3 = SUB32(ctx->r7, ctx->r13);
    // 0x8010C5D4: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x8010C5D8: lh          $t1, 0x6($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X6);
    // 0x8010C5DC: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8010C5E0: subu        $a0, $a2, $t4
    ctx->r4 = SUB32(ctx->r6, ctx->r12);
    // 0x8010C5E4: subu        $s2, $t1, $t4
    ctx->r18 = SUB32(ctx->r9, ctx->r12);
    // 0x8010C5E8: mflo        $t8
    ctx->r24 = lo;
    // 0x8010C5EC: nop

    // 0x8010C5F0: nop

    // 0x8010C5F4: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010C5F8: mflo        $t6
    ctx->r14 = lo;
    // 0x8010C5FC: subu        $t7, $t8, $t6
    ctx->r15 = SUB32(ctx->r24, ctx->r14);
    // 0x8010C600: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010C604: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010C608: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010C60C: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C610: swc1        $f0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f0.u32l;
    // 0x8010C614: mflo        $t9
    ctx->r25 = lo;
    // 0x8010C618: nop

    // 0x8010C61C: nop

    // 0x8010C620: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010C624: mflo        $t8
    ctx->r24 = lo;
    // 0x8010C628: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x8010C62C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8010C630: multu       $s2, $v1
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010C634: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C638: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8010C63C: swc1        $f2, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f2.u32l;
    // 0x8010C640: mflo        $t7
    ctx->r15 = lo;
    // 0x8010C644: nop

    // 0x8010C648: nop

    // 0x8010C64C: multu       $s0, $a0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010C650: mflo        $t9
    ctx->r25 = lo;
    // 0x8010C654: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8010C658: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8010C65C: nop

    // 0x8010C660: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C664: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8010C668: swc1        $f12, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f12.u32l;
    // 0x8010C66C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010C670: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8010C674: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010C678: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010C67C: add.s       $f26, $f6, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010C680: c.lt.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl < ctx->f8.fl;
    // 0x8010C684: swc1        $f26, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f26.u32l;
    // 0x8010C688: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C68C: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_11;
    // 0x8010C68C: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_11:
    // 0x8010C690: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8010C694: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8010C698: mtc1        $ra, $f6
    ctx->f6.u32l = ctx->r31;
    // 0x8010C69C: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C6A0: lwc1        $f20, 0x130($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X130);
    // 0x8010C6A4: lwc1        $f18, 0x12C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010C6A8: lwc1        $f16, 0x128($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010C6AC: lwc1        $f22, 0x4($s4)
    ctx->f22.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8010C6B0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010C6B4: lwc1        $f24, 0x8($s4)
    ctx->f24.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8010C6B8: lwc1        $f28, 0xC($s4)
    ctx->f28.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8010C6BC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8010C6C0: swc1        $f22, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f22.u32l;
    // 0x8010C6C4: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C6C8: mul.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x8010C6CC: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x8010C6D0: swc1        $f24, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f24.u32l;
    // 0x8010C6D4: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8010C6D8: swc1        $f28, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f28.u32l;
    // 0x8010C6DC: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x8010C6E0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010C6E4: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8010C6E8: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    // 0x8010C6EC: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x8010C6F0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010C6F4: mul.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8010C6F8: nop

    // 0x8010C6FC: mul.s       $f8, $f18, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8010C700: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8010C704: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010C708: mul.s       $f6, $f16, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x8010C70C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010C710: sub.s       $f30, $f8, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8010C714: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010C718: mul.s       $f18, $f4, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x8010C71C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8010C720: nop

    // 0x8010C724: bc1f        L_8010C740
    if (!c1cs) {
        // 0x8010C728: nop
    
            goto L_8010C740;
    }
    // 0x8010C728: nop

    // 0x8010C72C: mul.s       $f10, $f4, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8010C730: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x8010C734: nop

    // 0x8010C738: bc1tl       L_8010C768
    if (c1cs) {
        // 0x8010C73C: lwc1        $f0, 0x11C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X11C);
            goto L_8010C768;
    }
    goto skip_12;
    // 0x8010C73C: lwc1        $f0, 0x11C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X11C);
    skip_12:
L_8010C740:
    // 0x8010C740: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x8010C744: nop

    // 0x8010C748: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C74C: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_13;
    // 0x8010C74C: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_13:
    // 0x8010C750: mul.s       $f6, $f2, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8010C754: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x8010C758: nop

    // 0x8010C75C: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C760: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_14;
    // 0x8010C760: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_14:
    // 0x8010C764: lwc1        $f0, 0x11C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X11C);
L_8010C768:
    // 0x8010C768: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010C76C: mul.s       $f12, $f0, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8010C770: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8010C774: nop

    // 0x8010C778: bc1fl       L_8010C798
    if (!c1cs) {
        // 0x8010C77C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010C798;
    }
    goto skip_15;
    // 0x8010C77C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_15:
    // 0x8010C780: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8010C784: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8010C788: nop

    // 0x8010C78C: bc1tl       L_8010C7C4
    if (c1cs) {
        // 0x8010C790: lwc1        $f8, 0x118($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
            goto L_8010C7C4;
    }
    goto skip_16;
    // 0x8010C790: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    skip_16:
    // 0x8010C794: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8010C798:
    // 0x8010C798: nop

    // 0x8010C79C: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x8010C7A0: nop

    // 0x8010C7A4: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C7A8: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_17;
    // 0x8010C7A8: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_17:
    // 0x8010C7AC: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8010C7B0: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8010C7B4: nop

    // 0x8010C7B8: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C7BC: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_18;
    // 0x8010C7BC: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_18:
    // 0x8010C7C0: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
L_8010C7C4:
    // 0x8010C7C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010C7C8: mul.s       $f2, $f8, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8010C7CC: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8010C7D0: nop

    // 0x8010C7D4: bc1fl       L_8010C7F4
    if (!c1cs) {
        // 0x8010C7D8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8010C7F4;
    }
    goto skip_19;
    // 0x8010C7D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_19:
    // 0x8010C7DC: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8010C7E0: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x8010C7E4: nop

    // 0x8010C7E8: bc1tl       L_8010C820
    if (c1cs) {
        // 0x8010C7EC: lwc1        $f10, 0xB0($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_8010C820;
    }
    goto skip_20;
    // 0x8010C7EC: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    skip_20:
    // 0x8010C7F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8010C7F4:
    // 0x8010C7F4: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8010C7F8: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x8010C7FC: nop

    // 0x8010C800: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C804: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_21;
    // 0x8010C804: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_21:
    // 0x8010C808: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8010C80C: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8010C810: nop

    // 0x8010C814: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C818: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_22;
    // 0x8010C818: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_22:
    // 0x8010C81C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
L_8010C820:
    // 0x8010C820: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8010C824: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8010C828: lwc1        $f20, 0x128($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010C82C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8010C830: add.s       $f28, $f18, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8010C834: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8010C838: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8010C83C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010C840: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8010C844: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8010C848: add.s       $f30, $f12, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8010C84C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C850: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8010C854: mul.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8010C858: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x8010C85C: lwc1        $f10, 0x12C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010C860: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C864: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    // 0x8010C868: nop

    // 0x8010C86C: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C870: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010C874: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010C878: lwc1        $f8, 0x130($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X130);
    // 0x8010C87C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010C880: nop

    // 0x8010C884: mul.s       $f6, $f24, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8010C888: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010C88C: mul.s       $f4, $f24, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x8010C890: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010C894: mul.s       $f6, $f22, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8010C898: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010C89C: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8010C8A0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010C8A4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010C8A8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010C8AC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010C8B0: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8010C8B4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8010C8B8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8010C8BC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C8C0: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010C8C4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8010C8C8: swc1        $f12, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f12.u32l;
    // 0x8010C8CC: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C8D0: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8010C8D4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010C8D8: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    // 0x8010C8DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010C8E0: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8010C8E4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8010C8E8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010C8EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010C8F0: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8010C8F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010C8F8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010C8FC: add.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8010C900: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8010C904: nop

    // 0x8010C908: bc1f        L_8010C944
    if (!c1cs) {
        // 0x8010C90C: nop
    
            goto L_8010C944;
    }
    // 0x8010C90C: nop

    // 0x8010C910: mul.s       $f4, $f14, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010C914: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010C918: mul.s       $f10, $f16, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010C91C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010C920: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8010C924: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010C928: mul.s       $f8, $f20, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010C92C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010C930: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010C934: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8010C938: nop

    // 0x8010C93C: bc1tl       L_8010C990
    if (c1cs) {
        // 0x8010C940: subu        $t6, $a3, $t2
        ctx->r14 = SUB32(ctx->r7, ctx->r10);
            goto L_8010C990;
    }
    goto skip_23;
    // 0x8010C940: subu        $t6, $a3, $t2
    ctx->r14 = SUB32(ctx->r7, ctx->r10);
    skip_23:
L_8010C944:
    // 0x8010C944: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010C948: nop

    // 0x8010C94C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8010C950: nop

    // 0x8010C954: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010C958: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_24;
    // 0x8010C958: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_24:
    // 0x8010C95C: mul.s       $f6, $f14, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010C960: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010C964: mul.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010C968: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010C96C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010C970: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8010C974: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010C978: mul.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010C97C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010C980: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x8010C984: nop

    // 0x8010C988: bc1f        L_8010CC10
    if (!c1cs) {
        // 0x8010C98C: subu        $t6, $a3, $t2
        ctx->r14 = SUB32(ctx->r7, ctx->r10);
            goto L_8010CC10;
    }
    // 0x8010C98C: subu        $t6, $a3, $t2
    ctx->r14 = SUB32(ctx->r7, ctx->r10);
L_8010C990:
    // 0x8010C990: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8010C994: subu        $t7, $t0, $t3
    ctx->r15 = SUB32(ctx->r8, ctx->r11);
    // 0x8010C998: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010C99C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C9A0: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010C9A4: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010C9A8: subu        $t9, $a2, $t1
    ctx->r25 = SUB32(ctx->r6, ctx->r9);
    // 0x8010C9AC: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C9B0: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010C9B4: nop

    // 0x8010C9B8: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8010C9BC: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010C9C0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8010C9C4: lwc1        $f10, 0x130($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X130);
    // 0x8010C9C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C9CC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010C9D0: nop

    // 0x8010C9D4: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010C9D8: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8010C9DC: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010C9E0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8010C9E4: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010C9E8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8010C9EC: nop

    // 0x8010C9F0: cvt.s.w     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C9F4: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8010C9F8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8010C9FC: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010CA00: mul.s       $f6, $f14, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8010CA04: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CA08: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8010CA0C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010CA10: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010CA14: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010CA18: mul.s       $f10, $f22, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8010CA1C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010CA20: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8010CA24: add.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010CA28: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010CA2C: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010CA30: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010CA34: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010CA38: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010CA3C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010CA40: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010CA44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CA48: add.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8010CA4C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8010CA50: nop

    // 0x8010CA54: bc1f        L_8010CA90
    if (!c1cs) {
        // 0x8010CA58: nop
    
            goto L_8010CA90;
    }
    // 0x8010CA58: nop

    // 0x8010CA5C: mul.s       $f4, $f14, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010CA60: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010CA64: mul.s       $f6, $f16, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010CA68: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CA6C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010CA70: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010CA74: mul.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010CA78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010CA7C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010CA80: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x8010CA84: nop

    // 0x8010CA88: bc1tl       L_8010CADC
    if (c1cs) {
        // 0x8010CA8C: subu        $t8, $t5, $a3
        ctx->r24 = SUB32(ctx->r13, ctx->r7);
            goto L_8010CADC;
    }
    goto skip_25;
    // 0x8010CA8C: subu        $t8, $t5, $a3
    ctx->r24 = SUB32(ctx->r13, ctx->r7);
    skip_25:
L_8010CA90:
    // 0x8010CA90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010CA94: nop

    // 0x8010CA98: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8010CA9C: nop

    // 0x8010CAA0: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010CAA4: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_26;
    // 0x8010CAA4: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_26:
    // 0x8010CAA8: mul.s       $f8, $f14, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010CAAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010CAB0: mul.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010CAB4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010CAB8: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010CABC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8010CAC0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010CAC4: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010CAC8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010CACC: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8010CAD0: nop

    // 0x8010CAD4: bc1f        L_8010CC10
    if (!c1cs) {
        // 0x8010CAD8: subu        $t8, $t5, $a3
        ctx->r24 = SUB32(ctx->r13, ctx->r7);
            goto L_8010CC10;
    }
    // 0x8010CAD8: subu        $t8, $t5, $a3
    ctx->r24 = SUB32(ctx->r13, ctx->r7);
L_8010CADC:
    // 0x8010CADC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8010CAE0: subu        $t6, $ra, $t0
    ctx->r14 = SUB32(ctx->r31, ctx->r8);
    // 0x8010CAE4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8010CAE8: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010CAEC: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8010CAF0: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8010CAF4: subu        $t7, $t4, $a2
    ctx->r15 = SUB32(ctx->r12, ctx->r6);
    // 0x8010CAF8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010CAFC: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010CB00: nop

    // 0x8010CB04: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8010CB08: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010CB0C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010CB10: lwc1        $f6, 0x130($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X130);
    // 0x8010CB14: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CB18: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8010CB1C: nop

    // 0x8010CB20: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8010CB24: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010CB28: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010CB2C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8010CB30: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010CB34: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010CB38: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8010CB3C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8010CB40: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010CB44: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8010CB48: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010CB4C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8010CB50: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010CB54: mul.s       $f10, $f14, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8010CB58: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010CB5C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010CB60: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010CB64: mul.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8010CB68: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010CB6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010CB70: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010CB74: add.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8010CB78: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8010CB7C: nop

    // 0x8010CB80: bc1f        L_8010CBBC
    if (!c1cs) {
        // 0x8010CB84: nop
    
            goto L_8010CBBC;
    }
    // 0x8010CB84: nop

    // 0x8010CB88: mul.s       $f4, $f14, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010CB8C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010CB90: mul.s       $f8, $f16, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010CB94: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010CB98: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8010CB9C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010CBA0: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010CBA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010CBA8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010CBAC: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8010CBB0: nop

    // 0x8010CBB4: bc1t        L_8010CC08
    if (c1cs) {
        // 0x8010CBB8: nop
    
            goto L_8010CC08;
    }
    // 0x8010CBB8: nop

L_8010CBBC:
    // 0x8010CBBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010CBC0: nop

    // 0x8010CBC4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8010CBC8: nop

    // 0x8010CBCC: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010CBD0: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_27;
    // 0x8010CBD0: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_27:
    // 0x8010CBD4: mul.s       $f10, $f14, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x8010CBD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010CBDC: mul.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8010CBE0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010CBE4: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010CBE8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010CBEC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010CBF0: mul.s       $f8, $f20, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8010CBF4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010CBF8: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8010CBFC: nop

    // 0x8010CC00: bc1fl       L_8010CC14
    if (!c1cs) {
        // 0x8010CC04: lw          $s2, 0x0($s4)
        ctx->r18 = MEM_W(ctx->r20, 0X0);
            goto L_8010CC14;
    }
    goto skip_28;
    // 0x8010CC04: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    skip_28:
L_8010CC08:
    // 0x8010CC08: b           L_8010CC30
    // 0x8010CC0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010CC30;
    // 0x8010CC0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010CC10:
    // 0x8010CC10: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
L_8010CC14:
    // 0x8010CC14: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
    // 0x8010CC18: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8010CC1C: addu        $t9, $s2, $s3
    ctx->r25 = ADD32(ctx->r18, ctx->r19);
    // 0x8010CC20: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x8010CC24: bnel        $t8, $at, L_8010C2FC
    if (ctx->r24 != ctx->r1) {
        // 0x8010CC28: addu        $a1, $s2, $s3
        ctx->r5 = ADD32(ctx->r18, ctx->r19);
            goto L_8010C2FC;
    }
    goto skip_29;
    // 0x8010CC28: addu        $a1, $s2, $s3
    ctx->r5 = ADD32(ctx->r18, ctx->r19);
    skip_29:
L_8010CC2C:
    // 0x8010CC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CC30:
    // 0x8010CC30: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8010CC34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010CC38: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010CC3C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010CC40: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010CC44: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8010CC48: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8010CC4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8010CC50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8010CC54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8010CC58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8010CC5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8010CC60: jr          $ra
    // 0x8010CC64: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x8010CC64: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010cc68(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010cc68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CC68: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x8010CC6C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8010CC70: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8010CC74: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8010CC78: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8010CC7C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8010CC80: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8010CC84: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8010CC88: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8010CC8C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8010CC90: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010CC94: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010CC98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010CC9C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8010CCA0: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010CCA4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010CCA8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8010CCAC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010CCB0: nop

    // 0x8010CCB4: bc1fl       L_8010CCCC
    if (!c1cs) {
        // 0x8010CCB8: swc1        $f2, 0x10C($sp)
        MEM_W(0X10C, ctx->r29) = ctx->f2.u32l;
            goto L_8010CCCC;
    }
    goto skip_0;
    // 0x8010CCB8: swc1        $f2, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f2.u32l;
    skip_0:
    // 0x8010CCBC: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x8010CCC0: b           L_8010CCD0
    // 0x8010CCC4: swc1        $f2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f2.u32l;
        goto L_8010CCD0;
    // 0x8010CCC4: swc1        $f2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f2.u32l;
    // 0x8010CCC8: swc1        $f2, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f2.u32l;
L_8010CCCC:
    // 0x8010CCCC: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
L_8010CCD0:
    // 0x8010CCD0: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8010CCD4: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8010CCD8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010CCDC: nop

    // 0x8010CCE0: bc1fl       L_8010CCF8
    if (!c1cs) {
        // 0x8010CCE4: swc1        $f2, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->f2.u32l;
            goto L_8010CCF8;
    }
    goto skip_1;
    // 0x8010CCE4: swc1        $f2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f2.u32l;
    skip_1:
    // 0x8010CCE8: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x8010CCEC: b           L_8010CCFC
    // 0x8010CCF0: swc1        $f2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f2.u32l;
        goto L_8010CCFC;
    // 0x8010CCF0: swc1        $f2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f2.u32l;
    // 0x8010CCF4: swc1        $f2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f2.u32l;
L_8010CCF8:
    // 0x8010CCF8: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
L_8010CCFC:
    // 0x8010CCFC: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8010CD00: lwc1        $f2, 0x18($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8010CD04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010CD08: nop

    // 0x8010CD0C: bc1fl       L_8010CD24
    if (!c1cs) {
        // 0x8010CD10: swc1        $f2, 0x104($sp)
        MEM_W(0X104, ctx->r29) = ctx->f2.u32l;
            goto L_8010CD24;
    }
    goto skip_2;
    // 0x8010CD10: swc1        $f2, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f2.u32l;
    skip_2:
    // 0x8010CD14: swc1        $f0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f0.u32l;
    // 0x8010CD18: b           L_8010CD28
    // 0x8010CD1C: swc1        $f2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f2.u32l;
        goto L_8010CD28;
    // 0x8010CD1C: swc1        $f2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f2.u32l;
    // 0x8010CD20: swc1        $f2, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f2.u32l;
L_8010CD24:
    // 0x8010CD24: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
L_8010CD28:
    // 0x8010CD28: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x8010CD2C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8010CD30: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8010CD34: beq         $t9, $at, L_8010DCA8
    if (ctx->r25 == ctx->r1) {
        // 0x8010CD38: addu        $a1, $s2, $s4
        ctx->r5 = ADD32(ctx->r18, ctx->r20);
            goto L_8010DCA8;
    }
    // 0x8010CD38: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
L_8010CD3C:
    // 0x8010CD3C: lh          $t5, 0x8($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X8);
    // 0x8010CD40: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8010CD44: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8010CD48: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8010CD4C: beql        $at, $zero, L_8010CDA0
    if (ctx->r1 == 0) {
        // 0x8010CD50: lh          $a2, 0xC($a1)
        ctx->r6 = MEM_H(ctx->r5, 0XC);
            goto L_8010CDA0;
    }
    goto skip_3;
    // 0x8010CD50: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    skip_3:
    // 0x8010CD54: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    // 0x8010CD58: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8010CD5C: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8010CD60: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8010CD64: beq         $at, $zero, L_8010CD94
    if (ctx->r1 == 0) {
        // 0x8010CD68: sll         $s1, $a2, 16
        ctx->r17 = S32(ctx->r6 << 16);
            goto L_8010CD94;
    }
    // 0x8010CD68: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x8010CD6C: sll         $s1, $t5, 16
    ctx->r17 = S32(ctx->r13 << 16);
    // 0x8010CD70: slt         $at, $t1, $a2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010CD74: beq         $at, $zero, L_8010CD88
    if (ctx->r1 == 0) {
        // 0x8010CD78: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_8010CD88;
    }
    // 0x8010CD78: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010CD7C: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8010CD80: b           L_8010CDE0
    // 0x8010CD84: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
        goto L_8010CDE0;
    // 0x8010CD84: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
L_8010CD88:
    // 0x8010CD88: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8010CD8C: b           L_8010CDE0
    // 0x8010CD90: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
        goto L_8010CDE0;
    // 0x8010CD90: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
L_8010CD94:
    // 0x8010CD94: b           L_8010CDE0
    // 0x8010CD98: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
        goto L_8010CDE0;
    // 0x8010CD98: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010CD9C: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
L_8010CDA0:
    // 0x8010CDA0: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x8010CDA4: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8010CDA8: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010CDAC: beq         $at, $zero, L_8010CDDC
    if (ctx->r1 == 0) {
        // 0x8010CDB0: sll         $s1, $a2, 16
        ctx->r17 = S32(ctx->r6 << 16);
            goto L_8010CDDC;
    }
    // 0x8010CDB0: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x8010CDB4: sll         $s1, $t1, 16
    ctx->r17 = S32(ctx->r9 << 16);
    // 0x8010CDB8: slt         $at, $t5, $a2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010CDBC: beq         $at, $zero, L_8010CDD0
    if (ctx->r1 == 0) {
        // 0x8010CDC0: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_8010CDD0;
    }
    // 0x8010CDC0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8010CDC4: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x8010CDC8: b           L_8010CDE0
    // 0x8010CDCC: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
        goto L_8010CDE0;
    // 0x8010CDCC: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
L_8010CDD0:
    // 0x8010CDD0: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8010CDD4: b           L_8010CDE0
    // 0x8010CDD8: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
        goto L_8010CDE0;
    // 0x8010CDD8: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
L_8010CDDC:
    // 0x8010CDDC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_8010CDE0:
    // 0x8010CDE0: lh          $t3, 0x2($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2);
    // 0x8010CDE4: lh          $ra, 0x8($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X8);
    // 0x8010CDE8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8010CDEC: slt         $at, $t3, $ra
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8010CDF0: beq         $at, $zero, L_8010CE40
    if (ctx->r1 == 0) {
        // 0x8010CDF4: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8010CE40;
    }
    // 0x8010CDF4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010CDF8: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010CDFC: sll         $a0, $t3, 16
    ctx->r4 = S32(ctx->r11 << 16);
    // 0x8010CE00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010CE04: slt         $at, $a3, $ra
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8010CE08: beq         $at, $zero, L_8010CE38
    if (ctx->r1 == 0) {
        // 0x8010CE0C: sll         $a2, $a3, 16
        ctx->r6 = S32(ctx->r7 << 16);
            goto L_8010CE38;
    }
    // 0x8010CE0C: sll         $a2, $a3, 16
    ctx->r6 = S32(ctx->r7 << 16);
    // 0x8010CE10: sll         $a2, $ra, 16
    ctx->r6 = S32(ctx->r31 << 16);
    // 0x8010CE14: slt         $at, $t3, $a3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010CE18: beq         $at, $zero, L_8010CE2C
    if (ctx->r1 == 0) {
        // 0x8010CE1C: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8010CE2C;
    }
    // 0x8010CE1C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010CE20: sll         $a0, $t3, 16
    ctx->r4 = S32(ctx->r11 << 16);
    // 0x8010CE24: b           L_8010CE84
    // 0x8010CE28: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010CE84;
    // 0x8010CE28: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010CE2C:
    // 0x8010CE2C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8010CE30: b           L_8010CE84
    // 0x8010CE34: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010CE84;
    // 0x8010CE34: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010CE38:
    // 0x8010CE38: b           L_8010CE84
    // 0x8010CE3C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8010CE84;
    // 0x8010CE3C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010CE40:
    // 0x8010CE40: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010CE44: sll         $a0, $ra, 16
    ctx->r4 = S32(ctx->r31 << 16);
    // 0x8010CE48: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8010CE4C: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010CE50: beq         $at, $zero, L_8010CE80
    if (ctx->r1 == 0) {
        // 0x8010CE54: sll         $a2, $a3, 16
        ctx->r6 = S32(ctx->r7 << 16);
            goto L_8010CE80;
    }
    // 0x8010CE54: sll         $a2, $a3, 16
    ctx->r6 = S32(ctx->r7 << 16);
    // 0x8010CE58: sll         $a2, $t3, 16
    ctx->r6 = S32(ctx->r11 << 16);
    // 0x8010CE5C: slt         $at, $ra, $a3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010CE60: beq         $at, $zero, L_8010CE74
    if (ctx->r1 == 0) {
        // 0x8010CE64: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8010CE74;
    }
    // 0x8010CE64: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8010CE68: sll         $a0, $ra, 16
    ctx->r4 = S32(ctx->r31 << 16);
    // 0x8010CE6C: b           L_8010CE84
    // 0x8010CE70: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010CE84;
    // 0x8010CE70: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010CE74:
    // 0x8010CE74: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8010CE78: b           L_8010CE84
    // 0x8010CE7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8010CE84;
    // 0x8010CE7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8010CE80:
    // 0x8010CE80: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8010CE84:
    // 0x8010CE84: lh          $t4, 0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X4);
    // 0x8010CE88: lh          $s0, 0xA($a1)
    ctx->r16 = MEM_H(ctx->r5, 0XA);
    // 0x8010CE8C: lwc1        $f4, 0x100($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8010CE90: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8010CE94: beql        $at, $zero, L_8010CEE8
    if (ctx->r1 == 0) {
        // 0x8010CE98: lh          $t0, 0x10($a1)
        ctx->r8 = MEM_H(ctx->r5, 0X10);
            goto L_8010CEE8;
    }
    goto skip_4;
    // 0x8010CE98: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    skip_4:
    // 0x8010CE9C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8010CEA0: sll         $v0, $t4, 16
    ctx->r2 = S32(ctx->r12 << 16);
    // 0x8010CEA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8010CEA8: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8010CEAC: beq         $at, $zero, L_8010CEDC
    if (ctx->r1 == 0) {
        // 0x8010CEB0: sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8 << 16);
            goto L_8010CEDC;
    }
    // 0x8010CEB0: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8010CEB4: sll         $v1, $s0, 16
    ctx->r3 = S32(ctx->r16 << 16);
    // 0x8010CEB8: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010CEBC: beq         $at, $zero, L_8010CED0
    if (ctx->r1 == 0) {
        // 0x8010CEC0: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8010CED0;
    }
    // 0x8010CEC0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010CEC4: sll         $v0, $t4, 16
    ctx->r2 = S32(ctx->r12 << 16);
    // 0x8010CEC8: b           L_8010CF28
    // 0x8010CECC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010CF28;
    // 0x8010CECC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010CED0:
    // 0x8010CED0: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8010CED4: b           L_8010CF28
    // 0x8010CED8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010CF28;
    // 0x8010CED8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010CEDC:
    // 0x8010CEDC: b           L_8010CF28
    // 0x8010CEE0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8010CF28;
    // 0x8010CEE0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010CEE4: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
L_8010CEE8:
    // 0x8010CEE8: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8010CEEC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8010CEF0: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8010CEF4: beq         $at, $zero, L_8010CF24
    if (ctx->r1 == 0) {
        // 0x8010CEF8: sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8 << 16);
            goto L_8010CF24;
    }
    // 0x8010CEF8: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8010CEFC: sll         $v1, $t4, 16
    ctx->r3 = S32(ctx->r12 << 16);
    // 0x8010CF00: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010CF04: beq         $at, $zero, L_8010CF18
    if (ctx->r1 == 0) {
        // 0x8010CF08: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8010CF18;
    }
    // 0x8010CF08: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8010CF0C: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8010CF10: b           L_8010CF28
    // 0x8010CF14: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010CF28;
    // 0x8010CF14: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010CF18:
    // 0x8010CF18: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8010CF1C: b           L_8010CF28
    // 0x8010CF20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8010CF28;
    // 0x8010CF20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8010CF24:
    // 0x8010CF24: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8010CF28:
    // 0x8010CF28: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8010CF2C: nop

    // 0x8010CF30: bc1tl       L_8010DC90
    if (c1cs) {
        // 0x8010CF34: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_5;
    // 0x8010CF34: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_5:
    // 0x8010CF38: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8010CF3C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8010CF40: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010CF44: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8010CF48: nop

    // 0x8010CF4C: bc1tl       L_8010DC90
    if (c1cs) {
        // 0x8010CF50: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_6;
    // 0x8010CF50: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_6:
    // 0x8010CF54: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8010CF58: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8010CF5C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010CF60: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8010CF64: nop

    // 0x8010CF68: bc1tl       L_8010DC90
    if (c1cs) {
        // 0x8010CF6C: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_7;
    // 0x8010CF6C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_7:
    // 0x8010CF70: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8010CF74: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8010CF78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CF7C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8010CF80: nop

    // 0x8010CF84: bc1tl       L_8010DC90
    if (c1cs) {
        // 0x8010CF88: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_8;
    // 0x8010CF88: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_8:
    // 0x8010CF8C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8010CF90: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8010CF94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CF98: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8010CF9C: nop

    // 0x8010CFA0: bc1tl       L_8010DC90
    if (c1cs) {
        // 0x8010CFA4: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_9;
    // 0x8010CFA4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_9:
    // 0x8010CFA8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8010CFAC: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8010CFB0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8010CFB4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010CFB8: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8010CFBC: nop

    // 0x8010CFC0: bc1tl       L_8010DC90
    if (c1cs) {
        // 0x8010CFC4: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_10;
    // 0x8010CFC4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_10:
    // 0x8010CFC8: lw          $t9, -0x452C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X452C);
    // 0x8010CFCC: addu        $t8, $s2, $s4
    ctx->r24 = ADD32(ctx->r18, ctx->r20);
    // 0x8010CFD0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8010CFD4: jalr        $t9
    // 0x8010CFD8: sw          $a1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8010CFD8: sw          $a1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010CFDC: beq         $v0, $zero, L_8010DC8C
    if (ctx->r2 == 0) {
        // 0x8010CFE0: lw          $a1, 0x128($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X128);
            goto L_8010DC8C;
    }
    // 0x8010CFE0: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x8010CFE4: lh          $ra, 0x8($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X8);
    // 0x8010CFE8: lh          $t3, 0x2($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2);
    // 0x8010CFEC: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8010CFF0: lh          $t4, 0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X4);
    // 0x8010CFF4: subu        $t2, $ra, $t3
    ctx->r10 = SUB32(ctx->r31, ctx->r11);
    // 0x8010CFF8: lh          $s0, 0xA($a1)
    ctx->r16 = MEM_H(ctx->r5, 0XA);
    // 0x8010CFFC: subu        $v0, $t0, $t4
    ctx->r2 = SUB32(ctx->r8, ctx->r12);
    // 0x8010D000: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010D004: lh          $a3, 0xE($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XE);
    // 0x8010D008: subu        $s1, $s0, $t4
    ctx->r17 = SUB32(ctx->r16, ctx->r12);
    // 0x8010D00C: subu        $v1, $a3, $t3
    ctx->r3 = SUB32(ctx->r7, ctx->r11);
    // 0x8010D010: mflo        $t6
    ctx->r14 = lo;
    // 0x8010D014: nop

    // 0x8010D018: nop

    // 0x8010D01C: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010D020: mflo        $t7
    ctx->r15 = lo;
    // 0x8010D024: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8010D028: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010D02C: nop

    // 0x8010D030: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D034: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
    // 0x8010D038: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x8010D03C: lh          $a2, 0xC($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XC);
    // 0x8010D040: lh          $t5, 0x6($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X6);
    // 0x8010D044: subu        $a0, $a2, $t1
    ctx->r4 = SUB32(ctx->r6, ctx->r9);
    // 0x8010D048: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010D04C: subu        $s2, $t5, $t1
    ctx->r18 = SUB32(ctx->r13, ctx->r9);
    // 0x8010D050: mflo        $t9
    ctx->r25 = lo;
    // 0x8010D054: nop

    // 0x8010D058: nop

    // 0x8010D05C: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010D060: mflo        $t6
    ctx->r14 = lo;
    // 0x8010D064: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8010D068: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010D06C: multu       $s2, $v1
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010D070: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D074: swc1        $f10, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f10.u32l;
    // 0x8010D078: mflo        $t8
    ctx->r24 = lo;
    // 0x8010D07C: nop

    // 0x8010D080: nop

    // 0x8010D084: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010D088: mflo        $t9
    ctx->r25 = lo;
    // 0x8010D08C: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8010D090: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8010D094: nop

    // 0x8010D098: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D09C: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8010D0A0: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8010D0A4: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    // 0x8010D0A8: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8010D0AC: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8010D0B0: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x8010D0B4: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8010D0B8: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010D0BC: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8010D0C0: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8010D0C4: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x8010D0C8: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8010D0CC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8010D0D0: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
    // 0x8010D0D4: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010D0D8: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8010D0DC: lwc1        $f14, 0xC($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8010D0E0: lwc1        $f2, 0x18($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8010D0E4: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8010D0E8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010D0EC: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8010D0F0: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8010D0F4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010D0F8: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010D0FC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8010D100: swc1        $f14, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f14.u32l;
    // 0x8010D104: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8010D108: sub.s       $f26, $f2, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8010D10C: swc1        $f2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f2.u32l;
    // 0x8010D110: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D114: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010D118: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8010D11C: mul.s       $f6, $f10, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8010D120: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010D124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010D128: nop

    // 0x8010D12C: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x8010D130: swc1        $f24, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f24.u32l;
    // 0x8010D134: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D138: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_11;
    // 0x8010D138: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_11:
    // 0x8010D13C: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
    // 0x8010D140: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8010D144: mov.s       $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = ctx->f8.fl;
    // 0x8010D148: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8010D14C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D150: lwc1        $f30, 0x60($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010D154: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8010D158: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D15C: mul.s       $f6, $f30, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f16.fl);
    // 0x8010D160: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x8010D164: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x8010D168: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D16C: mul.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8010D170: swc1        $f14, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f14.u32l;
    // 0x8010D174: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8010D178: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010D17C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010D180: neg.s       $f6, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = -ctx->f30.fl;
    // 0x8010D184: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010D188: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8010D18C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8010D190: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8010D194: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x8010D198: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8010D19C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010D1A0: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8010D1A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D1A8: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8010D1AC: sub.s       $f28, $f6, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8010D1B0: mul.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8010D1B4: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8010D1B8: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x8010D1BC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010D1C0: bc1fl       L_8010D1E4
    if (!c1cs) {
        // 0x8010D1C4: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8010D1E4;
    }
    goto skip_12;
    // 0x8010D1C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_12:
    // 0x8010D1C8: mul.s       $f4, $f0, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8010D1CC: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010D1D0: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8010D1D4: nop

    // 0x8010D1D8: bc1t        L_8010D20C
    if (c1cs) {
        // 0x8010D1DC: nop
    
            goto L_8010D20C;
    }
    // 0x8010D1DC: nop

    // 0x8010D1E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8010D1E4:
    // 0x8010D1E4: nop

    // 0x8010D1E8: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8010D1EC: nop

    // 0x8010D1F0: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D1F4: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_13;
    // 0x8010D1F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_13:
    // 0x8010D1F8: mul.s       $f4, $f0, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8010D1FC: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8010D200: nop

    // 0x8010D204: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D208: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_14;
    // 0x8010D208: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_14:
L_8010D20C:
    // 0x8010D20C: mul.s       $f22, $f12, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x8010D210: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D214: nop

    // 0x8010D218: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x8010D21C: nop

    // 0x8010D220: bc1fl       L_8010D240
    if (!c1cs) {
        // 0x8010D224: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D240;
    }
    goto skip_15;
    // 0x8010D224: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_15:
    // 0x8010D228: mul.s       $f6, $f12, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8010D22C: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x8010D230: nop

    // 0x8010D234: bc1t        L_8010D268
    if (c1cs) {
        // 0x8010D238: nop
    
            goto L_8010D268;
    }
    // 0x8010D238: nop

    // 0x8010D23C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8010D240:
    // 0x8010D240: nop

    // 0x8010D244: c.le.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl <= ctx->f10.fl;
    // 0x8010D248: nop

    // 0x8010D24C: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D250: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_16;
    // 0x8010D250: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_16:
    // 0x8010D254: mul.s       $f4, $f12, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8010D258: c.le.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl <= ctx->f22.fl;
    // 0x8010D25C: nop

    // 0x8010D260: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D264: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_17;
    // 0x8010D264: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_17:
L_8010D268:
    // 0x8010D268: mul.s       $f20, $f26, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x8010D26C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D270: nop

    // 0x8010D274: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x8010D278: nop

    // 0x8010D27C: bc1fl       L_8010D29C
    if (!c1cs) {
        // 0x8010D280: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D29C;
    }
    goto skip_18;
    // 0x8010D280: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_18:
    // 0x8010D284: mul.s       $f6, $f26, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x8010D288: c.le.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl <= ctx->f6.fl;
    // 0x8010D28C: nop

    // 0x8010D290: bc1tl       L_8010D2C8
    if (c1cs) {
        // 0x8010D294: lwc1        $f14, 0x144($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X144);
            goto L_8010D2C8;
    }
    goto skip_19;
    // 0x8010D294: lwc1        $f14, 0x144($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X144);
    skip_19:
    // 0x8010D298: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8010D29C:
    // 0x8010D29C: nop

    // 0x8010D2A0: c.le.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl <= ctx->f10.fl;
    // 0x8010D2A4: nop

    // 0x8010D2A8: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D2AC: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_20;
    // 0x8010D2AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_20:
    // 0x8010D2B0: mul.s       $f4, $f26, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x8010D2B4: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x8010D2B8: nop

    // 0x8010D2BC: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D2C0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_21;
    // 0x8010D2C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_21:
    // 0x8010D2C4: lwc1        $f14, 0x144($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X144);
L_8010D2C8:
    // 0x8010D2C8: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8010D2CC: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010D2D0: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010D2D4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8010D2D8: add.s       $f26, $f8, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010D2DC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8010D2E0: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8010D2E4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8010D2E8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8010D2EC: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010D2F0: add.s       $f28, $f22, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x8010D2F4: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8010D2F8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D2FC: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010D300: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D304: add.s       $f30, $f20, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x8010D308: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010D30C: nop

    // 0x8010D310: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8010D314: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010D318: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x8010D31C: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010D320: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D324: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8010D328: nop

    // 0x8010D32C: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010D330: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010D334: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8010D338: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8010D33C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010D340: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010D344: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010D348: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8010D34C: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010D350: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8010D354: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D358: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010D35C: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8010D360: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8010D364: nop

    // 0x8010D368: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D36C: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010D370: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8010D374: swc1        $f22, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f22.u32l;
    // 0x8010D378: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D37C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D380: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8010D384: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010D388: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010D38C: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x8010D390: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010D394: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010D398: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010D39C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D3A0: mul.s       $f4, $f22, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010D3A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D3A8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D3AC: add.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8010D3B0: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x8010D3B4: nop

    // 0x8010D3B8: bc1f        L_8010D3F4
    if (!c1cs) {
        // 0x8010D3BC: nop
    
            goto L_8010D3F4;
    }
    // 0x8010D3BC: nop

    // 0x8010D3C0: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D3C4: nop

    // 0x8010D3C8: mul.s       $f10, $f18, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D3CC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D3D0: mul.s       $f8, $f14, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D3D4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D3D8: mul.s       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D3DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D3E0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D3E4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8010D3E8: nop

    // 0x8010D3EC: bc1t        L_8010D438
    if (c1cs) {
        // 0x8010D3F0: nop
    
            goto L_8010D438;
    }
    // 0x8010D3F0: nop

L_8010D3F4:
    // 0x8010D3F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010D3F8: nop

    // 0x8010D3FC: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8010D400: nop

    // 0x8010D404: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D408: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_22;
    // 0x8010D408: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_22:
    // 0x8010D40C: mul.s       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D410: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D414: mul.s       $f8, $f18, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D418: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D41C: mul.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D420: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010D424: mul.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D428: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010D42C: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x8010D430: nop

    // 0x8010D434: bc1f        L_8010D6BC
    if (!c1cs) {
        // 0x8010D438: subu        $t7, $a3, $ra
        ctx->r15 = SUB32(ctx->r7, ctx->r31);
            goto L_8010D6BC;
    }
L_8010D438:
    // 0x8010D438: subu        $t7, $a3, $ra
    ctx->r15 = SUB32(ctx->r7, ctx->r31);
    // 0x8010D43C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010D440: subu        $t8, $t0, $s0
    ctx->r24 = SUB32(ctx->r8, ctx->r16);
    // 0x8010D444: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8010D448: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D44C: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010D450: lwc1        $f8, 0x164($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010D454: subu        $t9, $a2, $t5
    ctx->r25 = SUB32(ctx->r6, ctx->r13);
    // 0x8010D458: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D45C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010D460: nop

    // 0x8010D464: mul.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8010D468: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8010D46C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010D470: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010D474: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D478: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010D47C: nop

    // 0x8010D480: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8010D484: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8010D488: mul.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010D48C: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8010D490: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010D494: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8010D498: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D49C: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8010D4A0: mtc1        $ra, $f10
    ctx->f10.u32l = ctx->r31;
    // 0x8010D4A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D4A8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D4AC: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8010D4B0: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8010D4B4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010D4B8: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x8010D4BC: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8010D4C0: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010D4C4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D4C8: mul.s       $f10, $f22, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010D4CC: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8010D4D0: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8010D4D4: add.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010D4D8: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8010D4DC: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010D4E0: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8010D4E4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010D4E8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010D4EC: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010D4F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D4F4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D4F8: add.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8010D4FC: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x8010D500: nop

    // 0x8010D504: bc1f        L_8010D540
    if (!c1cs) {
        // 0x8010D508: nop
    
            goto L_8010D540;
    }
    // 0x8010D508: nop

    // 0x8010D50C: mul.s       $f8, $f16, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D510: nop

    // 0x8010D514: mul.s       $f6, $f18, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D518: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D51C: mul.s       $f10, $f14, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D520: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D524: mul.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D528: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D52C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D530: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8010D534: nop

    // 0x8010D538: bc1t        L_8010D584
    if (c1cs) {
        // 0x8010D53C: nop
    
            goto L_8010D584;
    }
    // 0x8010D53C: nop

L_8010D540:
    // 0x8010D540: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D544: nop

    // 0x8010D548: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8010D54C: nop

    // 0x8010D550: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D554: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_23;
    // 0x8010D554: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_23:
    // 0x8010D558: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D55C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010D560: mul.s       $f10, $f18, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D564: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D568: mul.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D56C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010D570: mul.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D574: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010D578: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8010D57C: nop

    // 0x8010D580: bc1f        L_8010D6BC
    if (!c1cs) {
        // 0x8010D584: subu        $t6, $t3, $a3
        ctx->r14 = SUB32(ctx->r11, ctx->r7);
            goto L_8010D6BC;
    }
L_8010D584:
    // 0x8010D584: subu        $t6, $t3, $a3
    ctx->r14 = SUB32(ctx->r11, ctx->r7);
    // 0x8010D588: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8010D58C: subu        $t7, $t4, $t0
    ctx->r15 = SUB32(ctx->r12, ctx->r8);
    // 0x8010D590: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010D594: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D598: lwc1        $f6, 0x160($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010D59C: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010D5A0: subu        $t8, $t1, $a2
    ctx->r24 = SUB32(ctx->r9, ctx->r6);
    // 0x8010D5A4: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D5A8: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010D5AC: nop

    // 0x8010D5B0: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8010D5B4: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8010D5B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8010D5BC: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010D5C0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D5C4: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8010D5C8: nop

    // 0x8010D5CC: mul.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010D5D0: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010D5D4: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8010D5D8: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010D5DC: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010D5E0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010D5E4: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010D5E8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010D5EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010D5F0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010D5F4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D5F8: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8010D5FC: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8010D600: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8010D604: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010D608: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8010D60C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8010D610: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010D614: mul.s       $f8, $f22, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010D618: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D61C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D620: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D624: add.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8010D628: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x8010D62C: nop

    // 0x8010D630: bc1f        L_8010D66C
    if (!c1cs) {
        // 0x8010D634: nop
    
            goto L_8010D66C;
    }
    // 0x8010D634: nop

    // 0x8010D638: mul.s       $f8, $f16, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D63C: nop

    // 0x8010D640: mul.s       $f6, $f18, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D644: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D648: mul.s       $f10, $f14, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D64C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D650: mul.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D654: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D658: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D65C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8010D660: nop

    // 0x8010D664: bc1t        L_8010D6B4
    if (c1cs) {
        // 0x8010D668: nop
    
            goto L_8010D6B4;
    }
    // 0x8010D668: nop

L_8010D66C:
    // 0x8010D66C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D670: nop

    // 0x8010D674: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8010D678: nop

    // 0x8010D67C: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D680: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_24;
    // 0x8010D680: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_24:
    // 0x8010D684: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D688: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010D68C: mul.s       $f10, $f18, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D690: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010D694: mul.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D698: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8010D69C: mul.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D6A0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010D6A4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8010D6A8: nop

    // 0x8010D6AC: bc1fl       L_8010D6C0
    if (!c1cs) {
        // 0x8010D6B0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8010D6C0;
    }
    goto skip_25;
    // 0x8010D6B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_25:
L_8010D6B4:
    // 0x8010D6B4: b           L_8010DCAC
    // 0x8010D6B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010DCAC;
    // 0x8010D6B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010D6BC:
    // 0x8010D6BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8010D6C0:
    // 0x8010D6C0: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8010D6C4: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8010D6C8: c.lt.s      $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f10.fl < ctx->f24.fl;
    // 0x8010D6CC: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8010D6D0: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8010D6D4: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D6D8: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_26;
    // 0x8010D6D8: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_26:
    // 0x8010D6DC: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010D6E0: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8010D6E4: lwc1        $f18, 0x168($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010D6E8: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8010D6EC: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8010D6F0: lwc1        $f16, 0x164($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010D6F4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8010D6F8: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010D6FC: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8010D700: lwc1        $f14, 0x160($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010D704: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8010D708: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D70C: mul.s       $f6, $f14, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x8010D710: add.s       $f24, $f8, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D714: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8010D718: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8010D71C: cvt.s.w     $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    ctx->f30.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D720: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8010D724: swc1        $f24, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f24.u32l;
    // 0x8010D728: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D72C: swc1        $f30, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f30.u32l;
    // 0x8010D730: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D734: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8010D738: swc1        $f22, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f22.u32l;
    // 0x8010D73C: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8010D740: swc1        $f20, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f20.u32l;
    // 0x8010D744: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D748: mul.s       $f8, $f30, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f14.fl);
    // 0x8010D74C: add.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D750: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8010D754: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8010D758: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8010D75C: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8010D760: nop

    // 0x8010D764: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010D768: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010D76C: mul.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8010D770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010D774: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010D778: sub.s       $f28, $f6, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8010D77C: mul.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8010D780: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8010D784: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x8010D788: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010D78C: bc1f        L_8010D7AC
    if (!c1cs) {
        // 0x8010D790: nop
    
            goto L_8010D7AC;
    }
    // 0x8010D790: nop

    // 0x8010D794: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8010D798: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010D79C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x8010D7A0: nop

    // 0x8010D7A4: bc1t        L_8010D7D8
    if (c1cs) {
        // 0x8010D7A8: nop
    
            goto L_8010D7D8;
    }
    // 0x8010D7A8: nop

L_8010D7AC:
    // 0x8010D7AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010D7B0: nop

    // 0x8010D7B4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8010D7B8: nop

    // 0x8010D7BC: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D7C0: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_27;
    // 0x8010D7C0: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_27:
    // 0x8010D7C4: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8010D7C8: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8010D7CC: nop

    // 0x8010D7D0: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D7D4: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_28;
    // 0x8010D7D4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_28:
L_8010D7D8:
    // 0x8010D7D8: mul.s       $f22, $f12, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x8010D7DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D7E0: nop

    // 0x8010D7E4: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x8010D7E8: nop

    // 0x8010D7EC: bc1fl       L_8010D80C
    if (!c1cs) {
        // 0x8010D7F0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8010D80C;
    }
    goto skip_29;
    // 0x8010D7F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_29:
    // 0x8010D7F4: mul.s       $f6, $f12, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8010D7F8: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x8010D7FC: nop

    // 0x8010D800: bc1t        L_8010D834
    if (c1cs) {
        // 0x8010D804: nop
    
            goto L_8010D834;
    }
    // 0x8010D804: nop

    // 0x8010D808: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8010D80C:
    // 0x8010D80C: nop

    // 0x8010D810: c.le.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl <= ctx->f4.fl;
    // 0x8010D814: nop

    // 0x8010D818: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D81C: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_30;
    // 0x8010D81C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_30:
    // 0x8010D820: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8010D824: c.le.s      $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f10.fl <= ctx->f22.fl;
    // 0x8010D828: nop

    // 0x8010D82C: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D830: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_31;
    // 0x8010D830: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_31:
L_8010D834:
    // 0x8010D834: mul.s       $f20, $f26, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x8010D838: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010D83C: nop

    // 0x8010D840: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x8010D844: nop

    // 0x8010D848: bc1fl       L_8010D868
    if (!c1cs) {
        // 0x8010D84C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8010D868;
    }
    goto skip_32;
    // 0x8010D84C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_32:
    // 0x8010D850: mul.s       $f6, $f26, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x8010D854: c.le.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl <= ctx->f6.fl;
    // 0x8010D858: nop

    // 0x8010D85C: bc1tl       L_8010D894
    if (c1cs) {
        // 0x8010D860: lwc1        $f8, 0xE4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
            goto L_8010D894;
    }
    goto skip_33;
    // 0x8010D860: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    skip_33:
    // 0x8010D864: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8010D868:
    // 0x8010D868: nop

    // 0x8010D86C: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x8010D870: nop

    // 0x8010D874: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D878: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_34;
    // 0x8010D878: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_34:
    // 0x8010D87C: mul.s       $f10, $f26, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x8010D880: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x8010D884: nop

    // 0x8010D888: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D88C: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_35;
    // 0x8010D88C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_35:
    // 0x8010D890: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
L_8010D894:
    // 0x8010D894: lwc1        $f6, 0x144($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8010D898: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010D89C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8010D8A0: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8010D8A4: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010D8A8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8010D8AC: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8010D8B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010D8B4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8010D8B8: lwc1        $f6, 0x160($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010D8BC: add.s       $f28, $f22, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x8010D8C0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8010D8C4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D8C8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D8CC: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010D8D0: add.s       $f30, $f20, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8010D8D4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010D8D8: nop

    // 0x8010D8DC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8010D8E0: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010D8E4: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8010D8E8: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010D8EC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D8F0: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8010D8F4: nop

    // 0x8010D8F8: mul.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010D8FC: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010D900: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8010D904: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8010D908: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010D90C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D910: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x8010D914: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8010D918: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x8010D91C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8010D920: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D924: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8010D928: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D92C: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8010D930: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x8010D934: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8010D938: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8010D93C: nop

    // 0x8010D940: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010D944: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8010D948: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010D94C: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010D950: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010D954: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010D958: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010D95C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010D960: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8010D964: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010D968: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010D96C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010D970: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8010D974: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010D978: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010D97C: add.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8010D980: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x8010D984: nop

    // 0x8010D988: bc1f        L_8010D9C4
    if (!c1cs) {
        // 0x8010D98C: nop
    
            goto L_8010D9C4;
    }
    // 0x8010D98C: nop

    // 0x8010D990: mul.s       $f10, $f16, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D994: nop

    // 0x8010D998: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D99C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010D9A0: mul.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D9A4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D9A8: mul.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D9AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010D9B0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010D9B4: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x8010D9B8: nop

    // 0x8010D9BC: bc1t        L_8010DA08
    if (c1cs) {
        // 0x8010D9C0: nop
    
            goto L_8010DA08;
    }
    // 0x8010D9C0: nop

L_8010D9C4:
    // 0x8010D9C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010D9C8: nop

    // 0x8010D9CC: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8010D9D0: nop

    // 0x8010D9D4: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010D9D8: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_36;
    // 0x8010D9D8: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_36:
    // 0x8010D9DC: mul.s       $f8, $f16, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010D9E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010D9E4: mul.s       $f6, $f18, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010D9E8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010D9EC: mul.s       $f8, $f14, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010D9F0: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8010D9F4: mul.s       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010D9F8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010D9FC: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8010DA00: nop

    // 0x8010DA04: bc1f        L_8010DC8C
    if (!c1cs) {
        // 0x8010DA08: subu        $t9, $a3, $ra
        ctx->r25 = SUB32(ctx->r7, ctx->r31);
            goto L_8010DC8C;
    }
L_8010DA08:
    // 0x8010DA08: subu        $t9, $a3, $ra
    ctx->r25 = SUB32(ctx->r7, ctx->r31);
    // 0x8010DA0C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010DA10: subu        $t6, $t0, $s0
    ctx->r14 = SUB32(ctx->r8, ctx->r16);
    // 0x8010DA14: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8010DA18: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010DA1C: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010DA20: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010DA24: subu        $t7, $a2, $t5
    ctx->r15 = SUB32(ctx->r6, ctx->r13);
    // 0x8010DA28: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010DA2C: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010DA30: nop

    // 0x8010DA34: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8010DA38: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8010DA3C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010DA40: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010DA44: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010DA48: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010DA4C: nop

    // 0x8010DA50: mul.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8010DA54: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010DA58: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010DA5C: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8010DA60: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010DA64: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8010DA68: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010DA6C: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010DA70: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
    // 0x8010DA74: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010DA78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010DA7C: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x8010DA80: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8010DA84: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8010DA88: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8010DA8C: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8010DA90: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010DA94: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8010DA98: mul.s       $f4, $f22, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010DA9C: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8010DAA0: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8010DAA4: add.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8010DAA8: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8010DAAC: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010DAB0: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8010DAB4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010DAB8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010DABC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8010DAC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010DAC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DAC8: add.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8010DACC: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8010DAD0: nop

    // 0x8010DAD4: bc1f        L_8010DB10
    if (!c1cs) {
        // 0x8010DAD8: nop
    
            goto L_8010DB10;
    }
    // 0x8010DAD8: nop

    // 0x8010DADC: mul.s       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010DAE0: nop

    // 0x8010DAE4: mul.s       $f8, $f18, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010DAE8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DAEC: mul.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010DAF0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010DAF4: mul.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010DAF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010DAFC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DB00: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8010DB04: nop

    // 0x8010DB08: bc1t        L_8010DB54
    if (c1cs) {
        // 0x8010DB0C: nop
    
            goto L_8010DB54;
    }
    // 0x8010DB0C: nop

L_8010DB10:
    // 0x8010DB10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010DB14: nop

    // 0x8010DB18: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x8010DB1C: nop

    // 0x8010DB20: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010DB24: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_37;
    // 0x8010DB24: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_37:
    // 0x8010DB28: mul.s       $f10, $f16, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010DB2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010DB30: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010DB34: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010DB38: mul.s       $f10, $f14, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010DB3C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010DB40: mul.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010DB44: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010DB48: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8010DB4C: nop

    // 0x8010DB50: bc1f        L_8010DC8C
    if (!c1cs) {
        // 0x8010DB54: subu        $t8, $t3, $a3
        ctx->r24 = SUB32(ctx->r11, ctx->r7);
            goto L_8010DC8C;
    }
L_8010DB54:
    // 0x8010DB54: subu        $t8, $t3, $a3
    ctx->r24 = SUB32(ctx->r11, ctx->r7);
    // 0x8010DB58: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8010DB5C: subu        $t9, $t4, $t0
    ctx->r25 = SUB32(ctx->r12, ctx->r8);
    // 0x8010DB60: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010DB64: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010DB68: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8010DB6C: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8010DB70: subu        $t6, $t1, $a2
    ctx->r14 = SUB32(ctx->r9, ctx->r6);
    // 0x8010DB74: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010DB78: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010DB7C: nop

    // 0x8010DB80: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8010DB84: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8010DB88: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8010DB8C: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8010DB90: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010DB94: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8010DB98: nop

    // 0x8010DB9C: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010DBA0: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010DBA4: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8010DBA8: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010DBAC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010DBB0: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8010DBB4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8010DBB8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8010DBBC: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010DBC0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010DBC4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DBC8: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010DBCC: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8010DBD0: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8010DBD4: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010DBD8: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8010DBDC: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8010DBE0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8010DBE4: mul.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8010DBE8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010DBEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010DBF0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DBF4: add.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8010DBF8: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8010DBFC: nop

    // 0x8010DC00: bc1f        L_8010DC3C
    if (!c1cs) {
        // 0x8010DC04: nop
    
            goto L_8010DC3C;
    }
    // 0x8010DC04: nop

    // 0x8010DC08: mul.s       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010DC0C: nop

    // 0x8010DC10: mul.s       $f8, $f18, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010DC14: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DC18: mul.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010DC1C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010DC20: mul.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010DC24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010DC28: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010DC2C: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8010DC30: nop

    // 0x8010DC34: bc1t        L_8010DC84
    if (c1cs) {
        // 0x8010DC38: nop
    
            goto L_8010DC84;
    }
    // 0x8010DC38: nop

L_8010DC3C:
    // 0x8010DC3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010DC40: nop

    // 0x8010DC44: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x8010DC48: nop

    // 0x8010DC4C: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010DC50: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_38;
    // 0x8010DC50: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_38:
    // 0x8010DC54: mul.s       $f10, $f16, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8010DC58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010DC5C: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8010DC60: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8010DC64: mul.s       $f10, $f14, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8010DC68: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8010DC6C: mul.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8010DC70: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010DC74: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8010DC78: nop

    // 0x8010DC7C: bc1fl       L_8010DC90
    if (!c1cs) {
        // 0x8010DC80: lw          $s2, 0x0($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X0);
            goto L_8010DC90;
    }
    goto skip_39;
    // 0x8010DC80: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    skip_39:
L_8010DC84:
    // 0x8010DC84: b           L_8010DCAC
    // 0x8010DC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010DCAC;
    // 0x8010DC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010DC8C:
    // 0x8010DC8C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
L_8010DC90:
    // 0x8010DC90: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x8010DC94: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8010DC98: addu        $t7, $s2, $s4
    ctx->r15 = ADD32(ctx->r18, ctx->r20);
    // 0x8010DC9C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8010DCA0: bnel        $t8, $at, L_8010CD3C
    if (ctx->r24 != ctx->r1) {
        // 0x8010DCA4: addu        $a1, $s2, $s4
        ctx->r5 = ADD32(ctx->r18, ctx->r20);
            goto L_8010CD3C;
    }
    goto skip_40;
    // 0x8010DCA4: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
    skip_40:
L_8010DCA8:
    // 0x8010DCA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010DCAC:
    // 0x8010DCAC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8010DCB0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010DCB4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010DCB8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010DCBC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010DCC0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8010DCC4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8010DCC8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8010DCCC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8010DCD0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8010DCD4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8010DCD8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8010DCDC: jr          $ra
    // 0x8010DCE0: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    return;
    // 0x8010DCE0: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8010dce4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8010dce4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DCE4: nop

    // 0x8010DCE8: nop

    // 0x8010DCEC: nop

;}
RECOMP_FUNC void M7_FUN_8010dcf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DCF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010DCF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010DCF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010DCFC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8010DD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010DD04: jal         0x80005670
    // 0x8010DD08: addiu       $a1, $a1, 0x372C
    ctx->r5 = ADD32(ctx->r5, 0X372C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x8010DD08: addiu       $a1, $a1, 0x372C
    ctx->r5 = ADD32(ctx->r5, 0X372C);
    after_0:
    // 0x8010DD0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010DD10: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8010DD14: sw          $v0, -0x41C4($at)
    MEM_W(-0X41C4, ctx->r1) = ctx->r2;
    // 0x8010DD18: addiu       $a1, $a1, 0x3718
    ctx->r5 = ADD32(ctx->r5, 0X3718);
    // 0x8010DD1C: jal         0x80005670
    // 0x8010DD20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8010DD20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8010DD24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8010DD28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010DD2C: sw          $v0, -0x41C0($at)
    MEM_W(-0X41C0, ctx->r1) = ctx->r2;
    // 0x8010DD30: addiu       $a1, $a1, -0x22B4
    ctx->r5 = ADD32(ctx->r5, -0X22B4);
    // 0x8010DD34: jal         0x800058DC
    // 0x8010DD38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8010DD38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8010DD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010DD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010DD44: jr          $ra
    // 0x8010DD48: nop

    return;
    // 0x8010DD48: nop

;}
