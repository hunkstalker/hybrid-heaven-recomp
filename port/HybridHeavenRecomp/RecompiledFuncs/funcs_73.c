#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M99_FUN_8038b87c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B87C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038b880(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038b880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B884: sw          $a0, -0x27B0($at)
    MEM_W(-0X27B0, ctx->r1) = ctx->r4;
    // 0x8038B888: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B88C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B890: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038B894: sw          $a1, -0x27AC($at)
    MEM_W(-0X27AC, ctx->r1) = ctx->r5;
    // 0x8038B898: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038B89C: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038B8A0: addiu       $a2, $a2, -0x2280
    ctx->r6 = ADD32(ctx->r6, -0X2280);
    // 0x8038B8A4: addiu       $a0, $a0, -0x27F0
    ctx->r4 = ADD32(ctx->r4, -0X27F0);
    // 0x8038B8A8: jal         0x801BF850
    // 0x8038B8AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_0;
    // 0x8038B8AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8038B8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B8B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B8B8: jr          $ra
    // 0x8038B8BC: nop

    return;
    // 0x8038B8BC: nop

;}
RECOMP_FUNC void M99_FUN_8038b8c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B8C0: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038B8C4: jr          $ra
    // 0x8038B8C8: lw          $v0, -0x22A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X22A0);
    return;
    // 0x8038B8C8: lw          $v0, -0x22A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X22A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038b8cc(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038b8cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B8D4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038B8D8: jal         0x801C250C
    // 0x8038B8DC: addiu       $a0, $a0, -0x2298
    ctx->r4 = ADD32(ctx->r4, -0X2298);
    LOOKUP_FUNC(0x801C250C)(rdram, ctx);
        goto after_0;
    // 0x8038B8DC: addiu       $a0, $a0, -0x2298
    ctx->r4 = ADD32(ctx->r4, -0X2298);
    after_0:
    // 0x8038B8E0: jal         0x8038B8FC
    // 0x8038B8E4: nop

    LOOKUP_FUNC(0x8038B8FC)(rdram, ctx);
        goto after_1;
    // 0x8038B8E4: nop

    after_1:
    // 0x8038B8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B8EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8038B8F4: jr          $ra
    // 0x8038B8F8: nop

    return;
    // 0x8038B8F8: nop

;}
RECOMP_FUNC void M99_FUN_8038b8fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B8FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B904: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038B908: addiu       $a1, $a1, -0x2298
    ctx->r5 = ADD32(ctx->r5, -0X2298);
    // 0x8038B90C: jal         0x801C2608
    // 0x8038B910: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C2608)(rdram, ctx);
        goto after_0;
    // 0x8038B910: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8038B914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B91C: jr          $ra
    // 0x8038B920: nop

    return;
    // 0x8038B920: nop

;}
RECOMP_FUNC void M99_FUN_8038b924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B924: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038B928: jr          $ra
    // 0x8038B92C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038B92C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038b930(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038b930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038B938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038B93C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B940: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038B944: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038B948: lw          $a0, -0x27B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27B0);
    // 0x8038B94C: jal         0x800058DC
    // 0x8038B950: addiu       $a1, $a1, -0x47C8
    ctx->r5 = ADD32(ctx->r5, -0X47C8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8038B950: addiu       $a1, $a1, -0x47C8
    ctx->r5 = ADD32(ctx->r5, -0X47C8);
    after_0:
    // 0x8038B954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B95C: jr          $ra
    // 0x8038B960: nop

    return;
    // 0x8038B960: nop

;}
RECOMP_FUNC void M99_FUN_8038b964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B964: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038B968: jr          $ra
    // 0x8038B96C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038B96C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038b970(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038b970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B970: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B974: sw          $zero, -0x2794($at)
    MEM_W(-0X2794, ctx->r1) = 0;
    // 0x8038B978: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B97C: sw          $zero, -0x2734($at)
    MEM_W(-0X2734, ctx->r1) = 0;
    // 0x8038B980: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038b984(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038b984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B988: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038B98C: sw          $zero, -0x2730($at)
    MEM_W(-0X2730, ctx->r1) = 0;
    // 0x8038B990: addiu       $v0, $v0, -0x278C
    ctx->r2 = ADD32(ctx->r2, -0X278C);
    // 0x8038B994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038B99C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8038B9A0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B9A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038B9A8: sw          $zero, -0x2790($at)
    MEM_W(-0X2790, ctx->r1) = 0;
    // 0x8038B9AC: jal         0x801BF6C4
    // 0x8038B9B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_0;
    // 0x8038B9B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8038B9B4: jal         0x8038BB6C
    // 0x8038B9B8: nop

    LOOKUP_FUNC(0x8038BB6C)(rdram, ctx);
        goto after_1;
    // 0x8038B9B8: nop

    after_1:
    // 0x8038B9BC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038B9C0: addiu       $a1, $a1, -0x4624
    ctx->r5 = ADD32(ctx->r5, -0X4624);
    // 0x8038B9C4: jal         0x800058DC
    // 0x8038B9C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8038B9C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8038B9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B9D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B9D4: jr          $ra
    // 0x8038B9D8: nop

    return;
    // 0x8038B9D8: nop

;}
RECOMP_FUNC void M99_FUN_8038b9dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B9DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B9E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038B9E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038B9F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038B9F4: jal         0x801BF968
    // 0x8038B9F8: sw          $t6, -0x2794($at)
    MEM_W(-0X2794, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x8038B9F8: sw          $t6, -0x2794($at)
    MEM_W(-0X2794, ctx->r1) = ctx->r14;
    after_0:
    // 0x8038B9FC: beq         $v0, $zero, L_8038BA10
    if (ctx->r2 == 0) {
        // 0x8038BA00: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8038BA10;
    }
    // 0x8038BA00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8038BA04: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038BA08: jal         0x800058DC
    // 0x8038BA0C: addiu       $a1, $a1, -0x45E0
    ctx->r5 = ADD32(ctx->r5, -0X45E0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8038BA0C: addiu       $a1, $a1, -0x45E0
    ctx->r5 = ADD32(ctx->r5, -0X45E0);
    after_1:
L_8038BA10:
    // 0x8038BA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BA14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038BA18: jr          $ra
    // 0x8038BA1C: nop

    return;
    // 0x8038BA1C: nop

;}
RECOMP_FUNC void M99_FUN_8038ba20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BA20: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ba24(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ba24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BA24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BA28: sw          $a0, -0x2734($at)
    MEM_W(-0X2734, ctx->r1) = ctx->r4;
    // 0x8038BA2C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BA34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038BA38: sw          $a1, -0x2730($at)
    MEM_W(-0X2730, ctx->r1) = ctx->r5;
    // 0x8038BA3C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038BA40: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038BA44: addiu       $a2, $a2, -0x1FA0
    ctx->r6 = ADD32(ctx->r6, -0X1FA0);
    // 0x8038BA48: addiu       $a0, $a0, -0x27A0
    ctx->r4 = ADD32(ctx->r4, -0X27A0);
    // 0x8038BA4C: jal         0x801BF850
    // 0x8038BA50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_0;
    // 0x8038BA50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8038BA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BA58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038BA5C: jr          $ra
    // 0x8038BA60: nop

    return;
    // 0x8038BA60: nop

;}
RECOMP_FUNC void M99_FUN_8038ba64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BA64: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038BA68: jr          $ra
    // 0x8038BA6C: lw          $v0, -0x2794($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2794);
    return;
    // 0x8038BA6C: lw          $v0, -0x2794($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2794);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ba70(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ba70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BA70: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038BA74: addiu       $v1, $v1, -0x2790
    ctx->r3 = ADD32(ctx->r3, -0X2790);
    // 0x8038BA78: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8038BA7C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8038BA80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8038BA84: jr          $ra
    // 0x8038BA88: slti        $v0, $t7, 0x14
    ctx->r2 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    return;
    // 0x8038BA88: slti        $v0, $t7, 0x14
    ctx->r2 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ba8c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ba8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BA8C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038BA90: addiu       $v1, $v1, -0x278C
    ctx->r3 = ADD32(ctx->r3, -0X278C);
    // 0x8038BA94: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8038BA98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8038BA9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8038BAA0: jr          $ra
    // 0x8038BAA4: slti        $v0, $t7, 0x14
    ctx->r2 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    return;
    // 0x8038BAA4: slti        $v0, $t7, 0x14
    ctx->r2 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038baa8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038baa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BAA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8038BAAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8038BAB0: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x8038BAB4: addiu       $s2, $s2, -0x2790
    ctx->r18 = ADD32(ctx->r18, -0X2790);
    // 0x8038BAB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8038BABC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038BAC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8038BAC4: beq         $v0, $zero, L_8038BB00
    if (ctx->r2 == 0) {
        // 0x8038BAC8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8038BB00;
    }
    // 0x8038BAC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8038BACC: blez        $v0, L_8038BAFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8038BAD0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8038BAFC;
    }
    // 0x8038BAD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8038BAD4: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8038BAD8: addiu       $s1, $s1, -0x2270
    ctx->r17 = ADD32(ctx->r17, -0X2270);
L_8038BADC:
    // 0x8038BADC: jal         0x801C250C
    // 0x8038BAE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C250C)(rdram, ctx);
        goto after_0;
    // 0x8038BAE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8038BAE4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8038BAE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8038BAEC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8038BAF0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8038BAF4: bne         $at, $zero, L_8038BADC
    if (ctx->r1 != 0) {
        // 0x8038BAF8: nop
    
            goto L_8038BADC;
    }
    // 0x8038BAF8: nop

L_8038BAFC:
    // 0x8038BAFC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_8038BB00:
    // 0x8038BB00: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x8038BB04: addiu       $s2, $s2, -0x278C
    ctx->r18 = ADD32(ctx->r18, -0X278C);
    // 0x8038BB08: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8038BB0C: beq         $v0, $zero, L_8038BB48
    if (ctx->r2 == 0) {
        // 0x8038BB10: nop
    
            goto L_8038BB48;
    }
    // 0x8038BB10: nop

    // 0x8038BB14: blez        $v0, L_8038BB44
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8038BB18: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8038BB44;
    }
    // 0x8038BB18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8038BB1C: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8038BB20: addiu       $s1, $s1, -0x2090
    ctx->r17 = ADD32(ctx->r17, -0X2090);
L_8038BB24:
    // 0x8038BB24: jal         0x801C25B0
    // 0x8038BB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C25B0)(rdram, ctx);
        goto after_1;
    // 0x8038BB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8038BB2C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8038BB30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8038BB34: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8038BB38: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8038BB3C: bne         $at, $zero, L_8038BB24
    if (ctx->r1 != 0) {
        // 0x8038BB40: nop
    
            goto L_8038BB24;
    }
    // 0x8038BB40: nop

L_8038BB44:
    // 0x8038BB44: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_8038BB48:
    // 0x8038BB48: jal         0x8038BB6C
    // 0x8038BB4C: nop

    LOOKUP_FUNC(0x8038BB6C)(rdram, ctx);
        goto after_2;
    // 0x8038BB4C: nop

    after_2:
    // 0x8038BB50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038BB54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8038BB58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8038BB5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8038BB60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8038BB64: jr          $ra
    // 0x8038BB68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038BB68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bb6c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bb6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BB6C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bb70(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bb70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BB70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BB74: sw          $zero, -0x2790($at)
    MEM_W(-0X2790, ctx->r1) = 0;
    // 0x8038BB78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BB7C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BB80: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038BB84: sw          $zero, -0x278C($at)
    MEM_W(-0X278C, ctx->r1) = 0;
    // 0x8038BB88: addiu       $a1, $a1, -0x2270
    ctx->r5 = ADD32(ctx->r5, -0X2270);
    // 0x8038BB8C: jal         0x801C2608
    // 0x8038BB90: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801C2608)(rdram, ctx);
        goto after_0;
    // 0x8038BB90: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8038BB94: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038BB98: addiu       $a1, $a1, -0x2090
    ctx->r5 = ADD32(ctx->r5, -0X2090);
    // 0x8038BB9C: jal         0x801C26C4
    // 0x8038BBA0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801C26C4)(rdram, ctx);
        goto after_1;
    // 0x8038BBA0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8038BBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BBA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038BBAC: jr          $ra
    // 0x8038BBB0: nop

    return;
    // 0x8038BBB0: nop

;}
RECOMP_FUNC void M99_FUN_8038bbb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BBB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038BBB8: jr          $ra
    // 0x8038BBBC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038BBBC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bbc0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bbc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BBC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038BBC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038BBCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BBD0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038BBD4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038BBD8: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x8038BBDC: jal         0x800058DC
    // 0x8038BBE0: addiu       $a1, $a1, -0x4624
    ctx->r5 = ADD32(ctx->r5, -0X4624);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8038BBE0: addiu       $a1, $a1, -0x4624
    ctx->r5 = ADD32(ctx->r5, -0X4624);
    after_0:
    // 0x8038BBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BBE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038BBEC: jr          $ra
    // 0x8038BBF0: nop

    return;
    // 0x8038BBF0: nop

;}
RECOMP_FUNC void M99_FUN_8038bbf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BBF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038BBF8: jr          $ra
    // 0x8038BBFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038BBFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bc00(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bc00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BC00: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BC04: sw          $zero, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = 0;
    // 0x8038BC08: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bc0c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bc0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BC0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BC10: sw          $zero, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = 0;
    // 0x8038BC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BC18: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BC1C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038BC20: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038BC24: sw          $zero, -0x24B4($at)
    MEM_W(-0X24B4, ctx->r1) = 0;
    // 0x8038BC28: lw          $a1, -0x24AC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X24AC);
    // 0x8038BC2C: jal         0x8038C548
    // 0x8038BC30: lw          $a0, -0x24B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X24B0);
    LOOKUP_FUNC(0x8038C548)(rdram, ctx);
        goto after_0;
    // 0x8038BC30: lw          $a0, -0x24B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X24B0);
    after_0:
    // 0x8038BC34: jal         0x801BF6C4
    // 0x8038BC38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_1;
    // 0x8038BC38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8038BC3C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BC40: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038BC44: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038BC48: sw          $zero, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = 0;
    // 0x8038BC4C: addiu       $v1, $v1, -0x1F10
    ctx->r3 = ADD32(ctx->r3, -0X1F10);
    // 0x8038BC50: addiu       $v0, $v0, -0x1F90
    ctx->r2 = ADD32(ctx->r2, -0X1F90);
L_8038BC54:
    // 0x8038BC54: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8038BC58: sw          $zero, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = 0;
    // 0x8038BC5C: sw          $zero, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = 0;
    // 0x8038BC60: sw          $zero, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = 0;
    // 0x8038BC64: sw          $zero, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = 0;
    // 0x8038BC68: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x8038BC6C: sw          $zero, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = 0;
    // 0x8038BC70: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x8038BC74: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x8038BC78: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8038BC7C: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8038BC80: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x8038BC84: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8038BC88: sw          $zero, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = 0;
    // 0x8038BC8C: sw          $zero, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = 0;
    // 0x8038BC90: sw          $zero, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = 0;
    // 0x8038BC94: bne         $v0, $v1, L_8038BC54
    if (ctx->r2 != ctx->r3) {
        // 0x8038BC98: sw          $zero, -0x34($v0)
        MEM_W(-0X34, ctx->r2) = 0;
            goto L_8038BC54;
    }
    // 0x8038BC98: sw          $zero, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = 0;
    // 0x8038BC9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8038BCA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8038BCA4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8038BCA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8038BCAC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8038BCB0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038BCB4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BCB8: swc1        $f4, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f4.u32l;
    // 0x8038BCBC: swc1        $f6, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f6.u32l;
    // 0x8038BCC0: jal         0x8038BE98
    // 0x8038BCC4: lwc1        $f12, -0x2310($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2310);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_2;
    // 0x8038BCC4: lwc1        $f12, -0x2310($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2310);
    after_2:
    // 0x8038BCC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BCCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038BCD0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BCD4: sw          $t6, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r14;
    // 0x8038BCD8: jr          $ra
    // 0x8038BCDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038BCDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bce0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bce0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BCE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BCE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BCE8: jal         0x801BF968
    // 0x8038BCEC: nop

    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x8038BCEC: nop

    after_0:
    // 0x8038BCF0: beq         $v0, $zero, L_8038BD2C
    if (ctx->r2 == 0) {
        // 0x8038BCF4: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038BD2C;
    }
    // 0x8038BCF4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BCF8: sw          $zero, -0x24B0($at)
    MEM_W(-0X24B0, ctx->r1) = 0;
    // 0x8038BCFC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BD00: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038BD04: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038BD08: sw          $zero, -0x24AC($at)
    MEM_W(-0X24AC, ctx->r1) = 0;
    // 0x8038BD0C: addiu       $a2, $a2, -0x1F10
    ctx->r6 = ADD32(ctx->r6, -0X1F10);
    // 0x8038BD10: addiu       $a0, $a0, -0x2720
    ctx->r4 = ADD32(ctx->r4, -0X2720);
    // 0x8038BD14: jal         0x801BF850
    // 0x8038BD18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_1;
    // 0x8038BD18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8038BD1C: jal         0x8038C600
    // 0x8038BD20: nop

    LOOKUP_FUNC(0x8038C600)(rdram, ctx);
        goto after_2;
    // 0x8038BD20: nop

    after_2:
    // 0x8038BD24: jal         0x8038C5D4
    // 0x8038BD28: nop

    LOOKUP_FUNC(0x8038C5D4)(rdram, ctx);
        goto after_3;
    // 0x8038BD28: nop

    after_3:
L_8038BD2C:
    // 0x8038BD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038BD34: jr          $ra
    // 0x8038BD38: nop

    return;
    // 0x8038BD38: nop

;}
RECOMP_FUNC void M99_FUN_8038bd3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BD3C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038BD40: jr          $ra
    // 0x8038BD44: lw          $v0, -0x2714($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2714);
    return;
    // 0x8038BD44: lw          $v0, -0x2714($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2714);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bd48(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bd48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BD48: jr          $ra
    // 0x8038BD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038BD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bd50(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bd50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BD50: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8038BD54: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038BD58: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BD5C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8038BD60: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BD64: swc1        $f12, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f12.u32l;
    // 0x8038BD68: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BD6C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8038BD70: swc1        $f14, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f14.u32l;
    // 0x8038BD74: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BD78: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8038BD7C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8038BD80: jr          $ra
    // 0x8038BD84: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
    return;
    // 0x8038BD84: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bd88(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bd88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BD88: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8038BD8C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038BD90: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BD94: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8038BD98: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BD9C: swc1        $f12, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f12.u32l;
    // 0x8038BDA0: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BDA4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8038BDA8: swc1        $f14, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f14.u32l;
    // 0x8038BDAC: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BDB0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8038BDB4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8038BDB8: jr          $ra
    // 0x8038BDBC: swc1        $f4, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f4.u32l;
    return;
    // 0x8038BDBC: swc1        $f4, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bdc0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bdc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BDC0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8038BDC4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8038BDC8: lw          $t6, 0xE8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE8);
    // 0x8038BDCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8038BDD0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BDD4: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8038BDD8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8038BDDC: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x8038BDE0: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x8038BDE4: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8038BDE8: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8038BDEC: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8038BDF0: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
    // 0x8038BDF4: lw          $t8, 0xE8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE8);
    // 0x8038BDF8: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8038BDFC: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8038BE00: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8038BE04: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8038BE08: jr          $ra
    // 0x8038BE0C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8038BE0C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038be10(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038be10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BE10: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8038BE14: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8038BE18: lw          $t6, 0xE8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE8);
    // 0x8038BE1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8038BE20: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BE24: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8038BE28: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8038BE2C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x8038BE30: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x8038BE34: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8038BE38: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8038BE3C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8038BE40: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
    // 0x8038BE44: lw          $t8, 0xE8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE8);
    // 0x8038BE48: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8038BE4C: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8038BE50: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8038BE54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8038BE58: jr          $ra
    // 0x8038BE5C: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8038BE5C: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038be60(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038be60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BE60: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8038BE64: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038BE68: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BE6C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8038BE70: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BE74: swc1        $f12, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f12.u32l;
    // 0x8038BE78: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BE7C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8038BE80: swc1        $f14, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f14.u32l;
    // 0x8038BE84: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BE88: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8038BE8C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8038BE90: jr          $ra
    // 0x8038BE94: swc1        $f4, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f4.u32l;
    return;
    // 0x8038BE94: swc1        $f4, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038be98(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038be98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BE98: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8038BE9C: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8038BEA0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BEA4: jr          $ra
    // 0x8038BEA8: swc1        $f12, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f12.u32l;
    return;
    // 0x8038BEA8: swc1        $f12, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f12.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038beac(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038beac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BEAC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8038BEB0: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8038BEB4: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x8038BEB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8038BEBC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BEC0: jr          $ra
    // 0x8038BEC4: swc1        $f4, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f4.u32l;
    return;
    // 0x8038BEC4: swc1        $f4, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bec8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bec8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BEC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8038BECC: jr          $ra
    // 0x8038BED0: swc1        $f12, -0x4174($at)
    MEM_W(-0X4174, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8038BED0: swc1        $f12, -0x4174($at)
    MEM_W(-0X4174, ctx->r1) = ctx->f12.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038bed4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038bed4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BEDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038BEE0: jal         0x801C0D04
    // 0x8038BEE4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x8038BEE4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x8038BEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038BEEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038BEF0: jr          $ra
    // 0x8038BEF4: nop

    return;
    // 0x8038BEF4: nop

;}
RECOMP_FUNC void M99_FUN_8038bef8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038BEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038BEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038BF00: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8038BF04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8038BF08: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8038BF0C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8038BF10: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8038BF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038BF18: jal         0x801C0DE4
    // 0x8038BF1C: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x8038BF1C: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x8038BF20: beq         $v0, $zero, L_8038BF3C
    if (ctx->r2 == 0) {
        // 0x8038BF24: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038BF3C;
    }
    // 0x8038BF24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038BF28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038BF2C: jal         0x801C0EB0
    // 0x8038BF30: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x8038BF30: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_1:
    // 0x8038BF34: b           L_8038C058
    // 0x8038BF38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8038C058;
    // 0x8038BF38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8038BF3C:
    // 0x8038BF3C: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    // 0x8038BF40: jal         0x801C0DE4
    // 0x8038BF44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_2;
    // 0x8038BF44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8038BF48: beq         $v0, $zero, L_8038C054
    if (ctx->r2 == 0) {
        // 0x8038BF4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C054;
    }
    // 0x8038BF4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038BF50: jal         0x801C0F18
    // 0x8038BF54: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_3;
    // 0x8038BF54: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_3:
    // 0x8038BF58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8038BF5C: jal         0x80034C24
    // 0x8038BF60: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_4;
    // 0x8038BF60: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x8038BF64: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038BF68: ldc1        $f4, -0x2308($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2308);
    // 0x8038BF6C: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8038BF70: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8038BF74: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x8038BF78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8038BF7C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038BF80: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BF84: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8038BF88: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8038BF8C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038BF90: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8038BF94: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8038BF98: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x8038BF9C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8038BFA0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8038BFA4: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8038BFA8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8038BFAC: div.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8038BFB0: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8038BFB4: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038BFB8: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8038BFBC: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x8038BFC0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8038BFC4: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BFC8: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8038BFCC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8038BFD0: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038BFD4: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8038BFD8: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
    // 0x8038BFDC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8038BFE0: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x8038BFE4: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8038BFE8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8038BFEC: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038BFF0: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8038BFF4: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
    // 0x8038BFF8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8038BFFC: lw          $t2, 0xE8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C000: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8038C004: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8038C008: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C00C: add.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x8038C010: swc1        $f4, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f4.u32l;
    // 0x8038C014: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8038C018: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8038C01C: lw          $t4, 0xE8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C020: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8038C024: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8038C028: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8038C02C: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C030: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8038C034: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x8038C038: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8038C03C: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C040: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8038C044: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038C048: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C04C: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8038C050: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_8038C054:
    // 0x8038C054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038C058:
    // 0x8038C058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C05C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C060: jr          $ra
    // 0x8038C064: nop

    return;
    // 0x8038C064: nop

;}
RECOMP_FUNC void M99_FUN_8038c068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C074: jal         0x801C0D04
    // 0x8038C078: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x8038C078: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    after_0:
    // 0x8038C07C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C084: jr          $ra
    // 0x8038C088: nop

    return;
    // 0x8038C088: nop

;}
RECOMP_FUNC void M99_FUN_8038c08c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C08C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C094: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8038C098: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8038C09C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8038C0A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8038C0A4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8038C0A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C0AC: jal         0x801C0DE4
    // 0x8038C0B0: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x8038C0B0: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    after_0:
    // 0x8038C0B4: beq         $v0, $zero, L_8038C0D0
    if (ctx->r2 == 0) {
        // 0x8038C0B8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C0D0;
    }
    // 0x8038C0B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C0BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C0C0: jal         0x801C0EB0
    // 0x8038C0C4: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x8038C0C4: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    after_1:
    // 0x8038C0C8: b           L_8038C148
    // 0x8038C0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8038C148;
    // 0x8038C0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8038C0D0:
    // 0x8038C0D0: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    // 0x8038C0D4: jal         0x801C0DE4
    // 0x8038C0D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_2;
    // 0x8038C0D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8038C0DC: beq         $v0, $zero, L_8038C144
    if (ctx->r2 == 0) {
        // 0x8038C0E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C144;
    }
    // 0x8038C0E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C0E4: jal         0x801C0F18
    // 0x8038C0E8: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_3;
    // 0x8038C0E8: addiu       $a1, $zero, 0x2328
    ctx->r5 = ADD32(0, 0X2328);
    after_3:
    // 0x8038C0EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8038C0F0: jal         0x80034C24
    // 0x8038C0F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_4;
    // 0x8038C0F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x8038C0F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C0FC: ldc1        $f4, -0x2300($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2300);
    // 0x8038C100: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8038C104: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8038C108: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x8038C10C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8038C110: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8038C114: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8038C118: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8038C11C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038C120: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x8038C124: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8038C128: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8038C12C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8038C130: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8038C134: sub.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8038C138: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8038C13C: add.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8038C140: swc1        $f18, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f18.u32l;
L_8038C144:
    // 0x8038C144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038C148:
    // 0x8038C148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C14C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C150: jr          $ra
    // 0x8038C154: nop

    return;
    // 0x8038C154: nop

;}
RECOMP_FUNC void M99_FUN_8038c158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C15C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C164: jal         0x801C0D04
    // 0x8038C168: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x8038C168: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x8038C16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C174: jr          $ra
    // 0x8038C178: nop

    return;
    // 0x8038C178: nop

;}
RECOMP_FUNC void M99_FUN_8038c17c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C17C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C184: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8038C188: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8038C18C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8038C190: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8038C194: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8038C198: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C19C: jal         0x801C0DE4
    // 0x8038C1A0: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x8038C1A0: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x8038C1A4: beq         $v0, $zero, L_8038C1C0
    if (ctx->r2 == 0) {
        // 0x8038C1A8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C1C0;
    }
    // 0x8038C1A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C1AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C1B0: jal         0x801C0EB0
    // 0x8038C1B4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x8038C1B4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_1:
    // 0x8038C1B8: b           L_8038C2FC
    // 0x8038C1BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8038C2FC;
    // 0x8038C1BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8038C1C0:
    // 0x8038C1C0: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    // 0x8038C1C4: jal         0x801C0DE4
    // 0x8038C1C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_2;
    // 0x8038C1C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8038C1CC: beq         $v0, $zero, L_8038C2F8
    if (ctx->r2 == 0) {
        // 0x8038C1D0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C2F8;
    }
    // 0x8038C1D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C1D4: jal         0x801C0F18
    // 0x8038C1D8: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_3;
    // 0x8038C1D8: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_3:
    // 0x8038C1DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8038C1E0: jal         0x80034C24
    // 0x8038C1E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_4;
    // 0x8038C1E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x8038C1E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C1EC: ldc1        $f4, -0x22F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X22F8);
    // 0x8038C1F0: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8038C1F4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8038C1F8: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x8038C1FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8038C200: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038C204: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C208: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8038C20C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8038C210: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038C214: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8038C218: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8038C21C: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x8038C220: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8038C224: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8038C228: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8038C22C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8038C230: div.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8038C234: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8038C238: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C23C: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8038C240: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x8038C244: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8038C248: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C24C: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8038C250: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8038C254: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C258: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8038C25C: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
    // 0x8038C260: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8038C264: lw          $t0, 0xE8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C268: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8038C26C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8038C270: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C274: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8038C278: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
    // 0x8038C27C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8038C280: lw          $t2, 0xE8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C284: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8038C288: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8038C28C: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C290: add.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x8038C294: swc1        $f4, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f4.u32l;
    // 0x8038C298: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8038C29C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8038C2A0: lw          $t4, 0xE8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C2A4: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8038C2A8: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8038C2AC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8038C2B0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8038C2B4: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C2B8: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8038C2BC: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x8038C2C0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8038C2C4: lw          $t6, 0xE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C2C8: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8038C2CC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8038C2D0: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C2D4: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8038C2D8: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x8038C2DC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8038C2E0: lw          $t8, 0xE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE8);
    // 0x8038C2E4: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8038C2E8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8038C2EC: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C2F0: add.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x8038C2F4: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
L_8038C2F8:
    // 0x8038C2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038C2FC:
    // 0x8038C2FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C304: jr          $ra
    // 0x8038C308: nop

    return;
    // 0x8038C308: nop

;}
RECOMP_FUNC void M99_FUN_8038c30c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C30C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C318: jal         0x801C1000
    // 0x8038C31C: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    LOOKUP_FUNC(0x801C1000)(rdram, ctx);
        goto after_0;
    // 0x8038C31C: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    after_0:
    // 0x8038C320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C328: jr          $ra
    // 0x8038C32C: nop

    return;
    // 0x8038C32C: nop

;}
RECOMP_FUNC void M99_FUN_8038c330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038C33C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038C340: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8038C344: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8038C348: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8038C34C: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    // 0x8038C350: jal         0x801C1088
    // 0x8038C354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C1088)(rdram, ctx);
        goto after_0;
    // 0x8038C354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8038C358: beq         $v0, $zero, L_8038C49C
    if (ctx->r2 == 0) {
        // 0x8038C35C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C49C;
    }
    // 0x8038C35C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C360: jal         0x801C1134
    // 0x8038C364: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    LOOKUP_FUNC(0x801C1134)(rdram, ctx);
        goto after_1;
    // 0x8038C364: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    after_1:
    // 0x8038C368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8038C36C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8038C370: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8038C374: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x8038C378: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8038C37C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8038C380: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8038C384: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8038C388: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8038C38C: bgez        $t6, L_8038C3A4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8038C390: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8038C3A4;
    }
    // 0x8038C390: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8038C394: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8038C398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8038C39C: nop

    // 0x8038C3A0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8038C3A4:
    // 0x8038C3A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8038C3A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8038C3AC: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8038C3B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8038C3B4: bgez        $t8, L_8038C3C8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8038C3B8: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8038C3C8;
    }
    // 0x8038C3B8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8038C3BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8038C3C0: nop

    // 0x8038C3C4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8038C3C8:
    // 0x8038C3C8: div.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8038C3CC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8038C3D0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8038C3D4: lw          $t9, 0xE8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C3D8: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8038C3DC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8038C3E0: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8038C3E4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8038C3E8: swc1        $f10, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f10.u32l;
    // 0x8038C3EC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8038C3F0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8038C3F4: lw          $t1, 0xE8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C3F8: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8038C3FC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8038C400: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8038C404: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8038C408: swc1        $f6, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f6.u32l;
    // 0x8038C40C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8038C410: lw          $t3, 0xE8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C414: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8038C418: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8038C41C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8038C420: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8038C424: swc1        $f6, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f6.u32l;
    // 0x8038C428: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8038C42C: lw          $t5, 0xE8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C430: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8038C434: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8038C438: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8038C43C: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8038C440: swc1        $f6, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f6.u32l;
    // 0x8038C444: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8038C448: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C44C: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8038C450: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8038C454: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8038C458: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8038C45C: swc1        $f6, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f6.u32l;
    // 0x8038C460: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8038C464: lw          $t9, 0xE8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C468: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8038C46C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8038C470: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8038C474: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8038C478: swc1        $f6, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f6.u32l;
    // 0x8038C47C: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8038C480: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8038C484: lw          $t1, 0xE8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE8);
    // 0x8038C488: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8038C48C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8038C490: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8038C494: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8038C498: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
L_8038C49C:
    // 0x8038C49C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C4A0: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    // 0x8038C4A4: jal         0x801C1088
    // 0x8038C4A8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801C1088)(rdram, ctx);
        goto after_2;
    // 0x8038C4A8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8038C4AC: beq         $v0, $zero, L_8038C4C4
    if (ctx->r2 == 0) {
        // 0x8038C4B0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8038C4C4;
    }
    // 0x8038C4B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8038C4B4: jal         0x801C10D8
    // 0x8038C4B8: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    LOOKUP_FUNC(0x801C10D8)(rdram, ctx);
        goto after_3;
    // 0x8038C4B8: addiu       $a1, $zero, 0x20FC
    ctx->r5 = ADD32(0, 0X20FC);
    after_3:
    // 0x8038C4BC: b           L_8038C4C8
    // 0x8038C4C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8038C4C8;
    // 0x8038C4C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8038C4C4:
    // 0x8038C4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038C4C8:
    // 0x8038C4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C4CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C4D0: jr          $ra
    // 0x8038C4D4: nop

    return;
    // 0x8038C4D4: nop

;}
RECOMP_FUNC void M99_FUN_8038c4d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C4D8: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038C4DC: addiu       $a2, $a2, -0x2710
    ctx->r6 = ADD32(ctx->r6, -0X2710);
    // 0x8038C4E0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8038C4E4: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8038C4E8: addiu       $t3, $t3, -0x1F90
    ctx->r11 = ADD32(ctx->r11, -0X1F90);
    // 0x8038C4EC: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8038C4F0: beq         $at, $zero, L_8038C530
    if (ctx->r1 == 0) {
        // 0x8038C4F4: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_8038C530;
    }
    // 0x8038C4F4: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x8038C4F8: beq         $v0, $zero, L_8038C520
    if (ctx->r2 == 0) {
        // 0x8038C4FC: sll         $t2, $t0, 4
        ctx->r10 = S32(ctx->r8 << 4);
            goto L_8038C520;
    }
    // 0x8038C4FC: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x8038C500: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038C504: addiu       $t7, $t7, -0x1F90
    ctx->r15 = ADD32(ctx->r15, -0X1F90);
    // 0x8038C508: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8038C50C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8038C510: lw          $t8, -0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X10);
    // 0x8038C514: lw          $t9, -0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XC);
    // 0x8038C518: sw          $t8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r24;
    // 0x8038C51C: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
L_8038C520:
    // 0x8038C520: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8038C524: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8038C528: sw          $a0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r4;
    // 0x8038C52C: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
L_8038C530:
    // 0x8038C530: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C534: jr          $ra
    // 0x8038C538: sw          $a1, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = ctx->r5;
    return;
    // 0x8038C538: sw          $a1, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c53c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c53c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C53C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C540: jr          $ra
    // 0x8038C544: sw          $a0, -0x24B4($at)
    MEM_W(-0X24B4, ctx->r1) = ctx->r4;
    return;
    // 0x8038C544: sw          $a0, -0x24B4($at)
    MEM_W(-0X24B4, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c548(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C548: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8038C54C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8038C550: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8038C554: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8038C558: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8038C55C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8038C560: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8038C564: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8038C568: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8038C56C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038C570: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038C574: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8038C578: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8038C57C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8038C580: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8038C584: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8038C588: addiu       $a0, $a0, -0x2348
    ctx->r4 = ADD32(ctx->r4, -0X2348);
    // 0x8038C58C: addiu       $a1, $zero, 0x16E
    ctx->r5 = ADD32(0, 0X16E);
    // 0x8038C590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8038C594: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8038C598: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8038C59C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8038C5A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8038C5A4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8038C5A8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8038C5AC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8038C5B0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8038C5B4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8038C5B8: jal         0x8011AAF4
    // 0x8038C5BC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x8038C5BC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8038C5C0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8038C5C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8038C5C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8038C5CC: jr          $ra
    // 0x8038C5D0: nop

    return;
    // 0x8038C5D0: nop

;}
RECOMP_FUNC void M99_FUN_8038c5d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C5D4: jr          $ra
    // 0x8038C5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038C5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c5dc(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c5dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C5DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038C5E0: jr          $ra
    // 0x8038C5E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038C5E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c5e8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c5e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C5E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038C5EC: jr          $ra
    // 0x8038C5F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038C5F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c5f4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c5f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C5F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038C5F8: jr          $ra
    // 0x8038C5FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038C5FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c600(rdram, ctx);
;}
