#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M99_FUN_8038cfcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CFCC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CFD0: sw          $zero, -0x2434($at)
    MEM_W(-0X2434, ctx->r1) = 0;
    // 0x8038CFD4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CFD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038CFDC: sw          $t6, -0x2438($at)
    MEM_W(-0X2438, ctx->r1) = ctx->r14;
    // 0x8038CFE0: jr          $ra
    // 0x8038CFE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8038CFE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cfe8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cfe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CFE8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038CFEC: addiu       $a0, $a0, -0x2434
    ctx->r4 = ADD32(ctx->r4, -0X2434);
    // 0x8038CFF0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CFF4: lw          $t6, -0x2430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2430);
    // 0x8038CFF8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8038CFFC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8038D000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038D004: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8038D008: beq         $at, $zero, L_8038D018
    if (ctx->r1 == 0) {
        // 0x8038D00C: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8038D018;
    }
    // 0x8038D00C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8038D010: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D014: sw          $t7, -0x2438($at)
    MEM_W(-0X2438, ctx->r1) = ctx->r15;
L_8038D018:
    // 0x8038D018: jr          $ra
    // 0x8038D01C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    return;
    // 0x8038D01C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d020(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D028: jal         0x8038CD6C
    // 0x8038D02C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x8038CD6C)(rdram, ctx);
        goto after_0;
    // 0x8038D02C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8038D030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8038D03C: jr          $ra
    // 0x8038D040: nop

    return;
    // 0x8038D040: nop

;}
RECOMP_FUNC void M99_FUN_8038d044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D044: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8038D048: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D04C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038D050: sw          $t6, -0x241C($at)
    MEM_W(-0X241C, ctx->r1) = ctx->r14;
    // 0x8038D054: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8038D058: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D05C: addiu       $v0, $v0, -0x242C
    ctx->r2 = ADD32(ctx->r2, -0X242C);
    // 0x8038D060: sw          $t7, -0x2418($at)
    MEM_W(-0X2418, ctx->r1) = ctx->r15;
    // 0x8038D064: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038D068: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8038D06C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8038D070: addiu       $t8, $t8, -0x2F24
    ctx->r24 = ADD32(ctx->r24, -0X2F24);
    // 0x8038D074: addiu       $t9, $t9, -0x2EF4
    ctx->r25 = ADD32(ctx->r25, -0X2EF4);
    // 0x8038D078: addiu       $t0, $t0, -0x2E8C
    ctx->r8 = ADD32(ctx->r8, -0X2E8C);
    // 0x8038D07C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8038D080: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8038D084: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x8038D088: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D08C: sw          $zero, -0x2420($at)
    MEM_W(-0X2420, ctx->r1) = 0;
    // 0x8038D090: lui         $t1, 0x2
    ctx->r9 = S32(0X2 << 16);
    // 0x8038D094: ori         $t1, $t1, 0x2355
    ctx->r9 = ctx->r9 | 0X2355;
    // 0x8038D098: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D09C: jr          $ra
    // 0x8038D0A0: sw          $t1, -0x2414($at)
    MEM_W(-0X2414, ctx->r1) = ctx->r9;
    return;
    // 0x8038D0A0: sw          $t1, -0x2414($at)
    MEM_W(-0X2414, ctx->r1) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d0a4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d0a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D0A4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038D0A8: lw          $t6, -0x2420($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2420);
    // 0x8038D0AC: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d0b0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d0b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D0B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D0B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8038D0B8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8038D0BC: lw          $t9, -0x242C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X242C);
    // 0x8038D0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D0C4: jalr        $t9
    // 0x8038D0C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8038D0C8: nop

    after_0:
    // 0x8038D0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D0D4: jr          $ra
    // 0x8038D0D8: nop

    return;
    // 0x8038D0D8: nop

;}
RECOMP_FUNC void M99_FUN_8038d0dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D0DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D0E4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038D0E8: jal         0x8038CD6C
    // 0x8038D0EC: lw          $a0, -0x241C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X241C);
    LOOKUP_FUNC(0x8038CD6C)(rdram, ctx);
        goto after_0;
    // 0x8038D0EC: lw          $a0, -0x241C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X241C);
    after_0:
    // 0x8038D0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D0F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038D0F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D0FC: sw          $t6, -0x2420($at)
    MEM_W(-0X2420, ctx->r1) = ctx->r14;
    // 0x8038D100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D104: jr          $ra
    // 0x8038D108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8038D108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d10c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d10c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D10C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D114: jal         0x8001791C
    // 0x8038D118: nop

    LOOKUP_FUNC(0x8001791C)(rdram, ctx);
        goto after_0;
    // 0x8038D118: nop

    after_0:
    // 0x8038D11C: beq         $v0, $zero, L_8038D160
    if (ctx->r2 == 0) {
        // 0x8038D120: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_8038D160;
    }
    // 0x8038D120: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038D124: addiu       $v0, $v0, -0x241C
    ctx->r2 = ADD32(ctx->r2, -0X241C);
    // 0x8038D128: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8038D12C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038D130: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8038D134: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8038D138: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8038D13C: lw          $t8, -0x2418($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2418);
    // 0x8038D140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038D144: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8038D148: beq         $at, $zero, L_8038D158
    if (ctx->r1 == 0) {
        // 0x8038D14C: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038D158;
    }
    // 0x8038D14C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D150: b           L_8038D164
    // 0x8038D154: sw          $t0, -0x2420($at)
    MEM_W(-0X2420, ctx->r1) = ctx->r8;
        goto L_8038D164;
    // 0x8038D154: sw          $t0, -0x2420($at)
    MEM_W(-0X2420, ctx->r1) = ctx->r8;
L_8038D158:
    // 0x8038D158: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D15C: sw          $zero, -0x2420($at)
    MEM_W(-0X2420, ctx->r1) = 0;
L_8038D160:
    // 0x8038D160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038D164:
    // 0x8038D164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D16C: jr          $ra
    // 0x8038D170: nop

    return;
    // 0x8038D170: nop

;}
RECOMP_FUNC void M99_FUN_8038d174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D17C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D180: sw          $zero, -0x2414($at)
    MEM_W(-0X2414, ctx->r1) = 0;
    // 0x8038D184: jal         0x8038CD6C
    // 0x8038D188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x8038CD6C)(rdram, ctx);
        goto after_0;
    // 0x8038D188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8038D18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8038D198: jr          $ra
    // 0x8038D19C: nop

    return;
    // 0x8038D19C: nop

;}
RECOMP_FUNC void M99_FUN_8038d1a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D1A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8038D1A8: jr          $ra
    // 0x8038D1AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038D1AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d1b0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d1b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1B0: jr          $ra
    // 0x8038D1B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038D1B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d1b8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d1b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D1BC: jr          $ra
    // 0x8038D1C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038D1C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d1c4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d1c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D1C8: jr          $ra
    // 0x8038D1CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038D1CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d1d0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d1d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D1D4: jr          $ra
    // 0x8038D1D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038D1D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d1dc(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d1dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1DC: nop

;}
RECOMP_FUNC void M99_FUN_8038d1e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D1E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D1EC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038D1F0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038D1F4: sw          $zero, -0x1EB0($at)
    MEM_W(-0X1EB0, ctx->r1) = 0;
    // 0x8038D1F8: lw          $a1, -0x2400($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2400);
    // 0x8038D1FC: jal         0x8038D7D4
    // 0x8038D200: lw          $a0, -0x2404($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2404);
    LOOKUP_FUNC(0x8038D7D4)(rdram, ctx);
        goto after_0;
    // 0x8038D200: lw          $a0, -0x2404($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2404);
    after_0:
    // 0x8038D204: jal         0x801BF6C4
    // 0x8038D208: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_1;
    // 0x8038D208: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8038D20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D210: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038D214: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D218: sw          $t6, -0x1EB0($at)
    MEM_W(-0X1EB0, ctx->r1) = ctx->r14;
    // 0x8038D21C: jr          $ra
    // 0x8038D220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038D220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d224(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D22C: jal         0x801BF968
    // 0x8038D230: nop

    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x8038D230: nop

    after_0:
    // 0x8038D234: beq         $v0, $zero, L_8038D268
    if (ctx->r2 == 0) {
        // 0x8038D238: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038D268;
    }
    // 0x8038D238: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D23C: sw          $zero, -0x2404($at)
    MEM_W(-0X2404, ctx->r1) = 0;
    // 0x8038D240: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D244: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038D248: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038D24C: sw          $zero, -0x2400($at)
    MEM_W(-0X2400, ctx->r1) = 0;
    // 0x8038D250: addiu       $a2, $a2, -0x1E70
    ctx->r6 = ADD32(ctx->r6, -0X1E70);
    // 0x8038D254: addiu       $a0, $a0, -0x2410
    ctx->r4 = ADD32(ctx->r4, -0X2410);
    // 0x8038D258: jal         0x801BF850
    // 0x8038D25C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_1;
    // 0x8038D25C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8038D260: jal         0x8038D7E4
    // 0x8038D264: nop

    LOOKUP_FUNC(0x8038D7E4)(rdram, ctx);
        goto after_2;
    // 0x8038D264: nop

    after_2:
L_8038D268:
    // 0x8038D268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D26C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D270: jr          $ra
    // 0x8038D274: nop

    return;
    // 0x8038D274: nop

;}
RECOMP_FUNC void M99_FUN_8038d278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D278: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038D27C: jr          $ra
    // 0x8038D280: lw          $v0, -0x1EB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1EB0);
    return;
    // 0x8038D280: lw          $v0, -0x1EB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1EB0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d284(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D284: jr          $ra
    // 0x8038D288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038D288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d28c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d28c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D28C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038D298: jal         0x80020718
    // 0x8038D29C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x8038D29C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8038D2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D2A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D2A8: jr          $ra
    // 0x8038D2AC: nop

    return;
    // 0x8038D2AC: nop

;}
RECOMP_FUNC void M99_FUN_8038d2b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D2B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D2B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038D2BC: jal         0x80020BF8
    // 0x8038D2C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80020BF8)(rdram, ctx);
        goto after_0;
    // 0x8038D2C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8038D2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D2C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038D2CC: jr          $ra
    // 0x8038D2D0: nop

    return;
    // 0x8038D2D0: nop

;}
RECOMP_FUNC void M99_FUN_8038d2d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D2D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038D2E0: jal         0x80020DAC
    // 0x8038D2E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_0;
    // 0x8038D2E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8038D2E8: beq         $v0, $zero, L_8038D2F8
    if (ctx->r2 == 0) {
        // 0x8038D2EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8038D2F8;
    }
    // 0x8038D2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D2F0: b           L_8038D2FC
    // 0x8038D2F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8038D2FC;
    // 0x8038D2F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8038D2F8:
    // 0x8038D2F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8038D2FC:
    // 0x8038D2FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8038D300: jr          $ra
    // 0x8038D304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038D304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d308(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038D30C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038D314: jal         0x80020D3C
    // 0x8038D318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80020D3C)(rdram, ctx);
        goto after_0;
    // 0x8038D318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8038D31C: beq         $v0, $zero, L_8038D32C
    if (ctx->r2 == 0) {
        // 0x8038D320: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8038D32C;
    }
    // 0x8038D320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D324: b           L_8038D330
    // 0x8038D328: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8038D330;
    // 0x8038D328: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8038D32C:
    // 0x8038D32C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8038D330:
    // 0x8038D330: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8038D334: jr          $ra
    // 0x8038D338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038D338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d33c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d33c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D33C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8038D340: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8038D344: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8038D348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038D34C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8038D350: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8038D354: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8038D358: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8038D35C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8038D360: bc1f        L_8038D36C
    if (!c1cs) {
        // 0x8038D364: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_8038D36C;
    }
    // 0x8038D364: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8038D368: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_8038D36C:
    // 0x8038D36C: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8038D370: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8038D374: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8038D378: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8038D37C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8038D380: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8038D384: lwc1        $f16, 0x34($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8038D388: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8038D38C: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8038D390: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8038D394: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8038D398: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8038D39C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8038D3A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8038D3A4: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8038D3A8: jal         0x8002FC20
    // 0x8038D3AC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8038D3AC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x8038D3B0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8038D3B4: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8038D3B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8038D3BC: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8038D3C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8038D3C4: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8038D3C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8038D3CC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8038D3D0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8038D3D4: nop

    // 0x8038D3D8: bc1fl       L_8038D3EC
    if (!c1cs) {
        // 0x8038D3DC: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8038D3EC;
    }
    goto skip_0;
    // 0x8038D3DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x8038D3E0: b           L_8038D4A8
    // 0x8038D3E4: sb          $t7, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r15;
        goto L_8038D4A8;
    // 0x8038D3E4: sb          $t7, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r15;
    // 0x8038D3E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8038D3EC:
    // 0x8038D3EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D3F0: lwc1        $f6, -0x22B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X22B4);
    // 0x8038D3F4: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x8038D3F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8038D3FC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8038D400: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8038D404: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8038D408: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8038D40C: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8038D410: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8038D414: nop

    // 0x8038D418: bc1fl       L_8038D428
    if (!c1cs) {
        // 0x8038D41C: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_8038D428;
    }
    goto skip_1;
    // 0x8038D41C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_1:
    // 0x8038D420: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8038D424: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8038D428:
    // 0x8038D428: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8038D42C: nop

    // 0x8038D430: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8038D434: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8038D438: nop

    // 0x8038D43C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8038D440: beql        $t9, $zero, L_8038D490
    if (ctx->r25 == 0) {
        // 0x8038D444: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_8038D490;
    }
    goto skip_2;
    // 0x8038D444: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x8038D448: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8038D44C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8038D450: sub.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8038D454: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8038D458: nop

    // 0x8038D45C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8038D460: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8038D464: nop

    // 0x8038D468: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8038D46C: bne         $t9, $zero, L_8038D484
    if (ctx->r25 != 0) {
        // 0x8038D470: nop
    
            goto L_8038D484;
    }
    // 0x8038D470: nop

    // 0x8038D474: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8038D478: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8038D47C: b           L_8038D49C
    // 0x8038D480: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8038D49C;
    // 0x8038D480: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8038D484:
    // 0x8038D484: b           L_8038D49C
    // 0x8038D488: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8038D49C;
    // 0x8038D488: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8038D48C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_8038D490:
    // 0x8038D490: nop

    // 0x8038D494: bltz        $t9, L_8038D484
    if (SIGNED(ctx->r25) < 0) {
        // 0x8038D498: nop
    
            goto L_8038D484;
    }
    // 0x8038D498: nop

L_8038D49C:
    // 0x8038D49C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8038D4A0: sb          $t9, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r25;
    // 0x8038D4A4: nop

L_8038D4A8:
    // 0x8038D4A8: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x8038D4AC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8038D4B0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8038D4B4: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x8038D4B8: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8038D4BC: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8038D4C0: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8038D4C4: jal         0x8001EF38
    // 0x8038D4C8: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8038D4C8: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    after_1:
    // 0x8038D4CC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8038D4D0: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x8038D4D4: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8038D4D8: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x8038D4DC: lwc1        $f18, 0x44($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8038D4E0: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8038D4E4: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8038D4E8: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8038D4EC: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8038D4F0: jal         0x8001EF38
    // 0x8038D4F4: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8038D4F4: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_2:
    // 0x8038D4F8: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x8038D4FC: subu        $v1, $t2, $v0
    ctx->r3 = SUB32(ctx->r10, ctx->r2);
    // 0x8038D500: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8038D504: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8038D508: andi        $t3, $v1, 0x1000
    ctx->r11 = ctx->r3 & 0X1000;
    // 0x8038D50C: beq         $t3, $zero, L_8038D520
    if (ctx->r11 == 0) {
        // 0x8038D510: andi        $a1, $v1, 0x1FFF
        ctx->r5 = ctx->r3 & 0X1FFF;
            goto L_8038D520;
    }
    // 0x8038D510: andi        $a1, $v1, 0x1FFF
    ctx->r5 = ctx->r3 & 0X1FFF;
    // 0x8038D514: andi        $a1, $v1, 0x1FFF
    ctx->r5 = ctx->r3 & 0X1FFF;
    // 0x8038D518: b           L_8038D520
    // 0x8038D51C: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
        goto L_8038D520;
    // 0x8038D51C: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
L_8038D520:
    // 0x8038D520: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8038D524: jal         0x8001EAD0
    // 0x8038D528: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x8038D528: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x8038D52C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D530: ldc1        $f16, -0x22B0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X22B0);
    // 0x8038D534: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8038D538: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x8038D53C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8038D540: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8038D544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8038D548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8038D54C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8038D550: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x8038D554: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x8038D558: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8038D55C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8038D560: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x8038D564: nop

    // 0x8038D568: cvt.w.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_D(ctx->f8.d);
    // 0x8038D56C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x8038D570: nop

    // 0x8038D574: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8038D578: beql        $a1, $zero, L_8038D5CC
    if (ctx->r5 == 0) {
        // 0x8038D57C: mfc1        $a1, $f6
        ctx->r5 = (int32_t)ctx->f6.u32l;
            goto L_8038D5CC;
    }
    goto skip_3;
    // 0x8038D57C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8038D580: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8038D584: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8038D588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8038D58C: sub.d       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f8.d - ctx->f6.d;
    // 0x8038D590: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x8038D594: nop

    // 0x8038D598: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8038D59C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x8038D5A0: nop

    // 0x8038D5A4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8038D5A8: bne         $a1, $zero, L_8038D5C0
    if (ctx->r5 != 0) {
        // 0x8038D5AC: nop
    
            goto L_8038D5C0;
    }
    // 0x8038D5AC: nop

    // 0x8038D5B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8038D5B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8038D5B8: b           L_8038D5D8
    // 0x8038D5BC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8038D5D8;
    // 0x8038D5BC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_8038D5C0:
    // 0x8038D5C0: b           L_8038D5D8
    // 0x8038D5C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8038D5D8;
    // 0x8038D5C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8038D5C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
L_8038D5CC:
    // 0x8038D5CC: nop

    // 0x8038D5D0: bltz        $a1, L_8038D5C0
    if (SIGNED(ctx->r5) < 0) {
        // 0x8038D5D4: nop
    
            goto L_8038D5C0;
    }
    // 0x8038D5D4: nop

L_8038D5D8:
    // 0x8038D5D8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8038D5DC: jal         0x800207D0
    // 0x8038D5E0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_4;
    // 0x8038D5E0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_4:
    // 0x8038D5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038D5E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8038D5EC: jr          $ra
    // 0x8038D5F0: nop

    return;
    // 0x8038D5F0: nop

;}
RECOMP_FUNC void M99_FUN_8038d5f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D5F4: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038D5F8: addiu       $v0, $v0, -0x1EA8
    ctx->r2 = ADD32(ctx->r2, -0X1EA8);
    // 0x8038D5FC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8038D600: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8038D604: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8038D608: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8038D60C: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8038D610: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8038D614: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8038D618: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8038D61C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8038D620: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8038D624: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8038D628: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8038D62C: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x8038D630: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8038D634: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8038D638: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8038D63C: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8038D640: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8038D644: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8038D648: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x8038D64C: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8038D650: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x8038D654: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x8038D658: jr          $ra
    // 0x8038D65C: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    return;
    // 0x8038D65C: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d660(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D660: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038D664: addiu       $v1, $v1, -0x1EA8
    ctx->r3 = ADD32(ctx->r3, -0X1EA8);
    // 0x8038D668: lw          $a1, 0x18($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18);
    // 0x8038D66C: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d670(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D670: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8038D674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038D678: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x8038D67C: bnel        $at, $zero, L_8038D7C4
    if (ctx->r1 != 0) {
        // 0x8038D680: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8038D7C4;
    }
    goto skip_0;
    // 0x8038D680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8038D684: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8038D688: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x8038D68C: bgez        $a0, L_8038D6A4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8038D690: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8038D6A4;
    }
    // 0x8038D690: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8038D694: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8038D698: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8038D69C: nop

    // 0x8038D6A0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8038D6A4:
    // 0x8038D6A4: bgez        $a1, L_8038D6BC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8038D6A8: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8038D6BC;
    }
    // 0x8038D6A8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8038D6AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8038D6B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8038D6B4: nop

    // 0x8038D6B8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8038D6BC:
    // 0x8038D6BC: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8038D6C0: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8038D6C4: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8038D6C8: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8038D6CC: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8038D6D0: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8038D6D4: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8038D6D8: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8038D6DC: sub.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8038D6E0: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8038D6E4: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x8038D6E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D6EC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8038D6F0: nop

    // 0x8038D6F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8038D6F8: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x8038D6FC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8038D700: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8038D704: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8038D708: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8038D70C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8038D710: bne         $t6, $v0, L_8038D754
    if (ctx->r14 != ctx->r2) {
        // 0x8038D714: add.s       $f16, $f10, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
            goto L_8038D754;
    }
    // 0x8038D714: add.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8038D718: lwc1        $f18, -0x22A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X22A8);
    // 0x8038D71C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8038D720: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8038D724: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8038D728: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x8038D72C: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x8038D730: lhu         $a3, 0x1E($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X1E);
    // 0x8038D734: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8038D738: jal         0x8038D33C
    // 0x8038D73C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8038D33C)(rdram, ctx);
        goto after_0;
    // 0x8038D73C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8038D740: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038D744: addiu       $v1, $v1, -0x1EA8
    ctx->r3 = ADD32(ctx->r3, -0X1EA8);
    // 0x8038D748: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x8038D74C: b           L_8038D798
    // 0x8038D750: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
        goto L_8038D798;
    // 0x8038D750: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
L_8038D754:
    // 0x8038D754: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x8038D758: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8038D75C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8038D760: bne         $t7, $v0, L_8038D798
    if (ctx->r15 != ctx->r2) {
        // 0x8038D764: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038D798;
    }
    // 0x8038D764: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038D768: lwc1        $f10, -0x22A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X22A4);
    // 0x8038D76C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8038D770: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8038D774: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8038D778: lhu         $a3, 0x1E($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X1E);
    // 0x8038D77C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8038D780: jal         0x8038D33C
    // 0x8038D784: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8038D33C)(rdram, ctx);
        goto after_1;
    // 0x8038D784: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8038D788: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038D78C: addiu       $v1, $v1, -0x1EA8
    ctx->r3 = ADD32(ctx->r3, -0X1EA8);
    // 0x8038D790: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x8038D794: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
L_8038D798:
    // 0x8038D798: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x8038D79C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8038D7A0: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    // 0x8038D7A4: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x8038D7A8: beq         $at, $zero, L_8038D7B4
    if (ctx->r1 == 0) {
        // 0x8038D7AC: addiu       $t1, $a0, 0x1
        ctx->r9 = ADD32(ctx->r4, 0X1);
            goto L_8038D7B4;
    }
    // 0x8038D7AC: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x8038D7B0: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
L_8038D7B4:
    // 0x8038D7B4: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
    // 0x8038D7B8: b           L_8038D7C4
    // 0x8038D7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8038D7C4;
    // 0x8038D7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038D7C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8038D7C4:
    // 0x8038D7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8038D7C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8038D7CC: jr          $ra
    // 0x8038D7D0: nop

    return;
    // 0x8038D7D0: nop

;}
RECOMP_FUNC void M99_FUN_8038d7d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D7D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D7D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8038D7DC: jr          $ra
    // 0x8038D7E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038D7E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d7e4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d7e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D7E4: jr          $ra
    // 0x8038D7E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038D7E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d7ec(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d7ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D7EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D7F0: jr          $ra
    // 0x8038D7F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038D7F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d7f8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d7f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D7F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D7FC: jr          $ra
    // 0x8038D800: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038D800: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d804(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038D804: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038D808: jr          $ra
    // 0x8038D80C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038D80C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038d810(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038d810(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8038D810u);
    return;
}
RECOMP_FUNC void M99_FUN_8038d8f4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8038D8F4u);
    return;
}
RECOMP_FUNC void M99_FUN_8038d964(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8038D964u);
    return;
}
RECOMP_FUNC void M99_FUN_8038d9f4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8038D9F4u);
    return;
}
RECOMP_FUNC void M99_FUN_8038da94(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8038DA94u);
    return;
}
RECOMP_FUNC void M8_FUN_801bf1a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF1A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BF1A8: jr          $ra
    // 0x801BF1AC: sb          $a0, 0x4010($at)
    MEM_B(0X4010, ctx->r1) = ctx->r4;
    return;
    // 0x801BF1AC: sb          $a0, 0x4010($at)
    MEM_B(0X4010, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801bf1b0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801bf1b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BF1B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BF1B8: jr          $ra
    // 0x801BF1BC: sb          $a0, -0x386D($at)
    MEM_B(-0X386D, ctx->r1) = ctx->r4;
    return;
    // 0x801BF1BC: sb          $a0, -0x386D($at)
    MEM_B(-0X386D, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801bf1c0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801bf1c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1C0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x801BF1C4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801BF1C8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801BF1CC: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801BF1D0: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
    // 0x801BF1D4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801BF1D8: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x801BF1DC: beq         $v0, $zero, L_801C195C
    if (ctx->r2 == 0) {
        // 0x801BF1E0: sw          $a1, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r5;
            goto L_801C195C;
    }
    // 0x801BF1E0: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x801BF1E4: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801BF1E8: beql        $t6, $zero, L_801C1960
    if (ctx->r14 == 0) {
        // 0x801BF1EC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_0;
    // 0x801BF1EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801BF1F0: lbu         $t7, 0xF5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XF5);
    // 0x801BF1F4: beql        $t7, $zero, L_801C1960
    if (ctx->r15 == 0) {
        // 0x801BF1F8: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_1;
    // 0x801BF1F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x801BF1FC: jal         0x8011B260
    // 0x801BF200: nop

    LOOKUP_FUNC(0x8011B260)(rdram, ctx);
        goto after_0;
    // 0x801BF200: nop

    after_0:
    // 0x801BF204: beql        $v0, $zero, L_801BF218
    if (ctx->r2 == 0) {
        // 0x801BF208: lbu         $t8, 0xBA2($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0XBA2);
            goto L_801BF218;
    }
    goto skip_2;
    // 0x801BF208: lbu         $t8, 0xBA2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XBA2);
    skip_2:
    // 0x801BF20C: jal         0x801BF1A0
    // 0x801BF210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_1;
    // 0x801BF210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801BF214: lbu         $t8, 0xBA2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XBA2);
L_801BF218:
    // 0x801BF218: beq         $t8, $zero, L_801BF228
    if (ctx->r24 == 0) {
        // 0x801BF21C: nop
    
            goto L_801BF228;
    }
    // 0x801BF21C: nop

    // 0x801BF220: jal         0x801BF1A0
    // 0x801BF224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_2;
    // 0x801BF224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_801BF228:
    // 0x801BF228: jal         0x80126944
    // 0x801BF22C: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_3;
    // 0x801BF22C: nop

    after_3:
    // 0x801BF230: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801BF234: bne         $v0, $v1, L_801BF248
    if (ctx->r2 != ctx->r3) {
        // 0x801BF238: nop
    
            goto L_801BF248;
    }
    // 0x801BF238: nop

    // 0x801BF23C: jal         0x801BF1A0
    // 0x801BF240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_4;
    // 0x801BF240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801BF244: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801BF248:
    // 0x801BF248: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801BF24C: lbu         $t9, 0x4010($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4010);
    // 0x801BF250: sltiu       $at, $t9, 0x10
    ctx->r1 = ctx->r25 < 0X10 ? 1 : 0;
    // 0x801BF254: beq         $at, $zero, L_801C195C
    if (ctx->r1 == 0) {
        // 0x801BF258: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801C195C;
    }
    // 0x801BF258: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801BF25C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF260: addu        $at, $at, $t9
    gpr jr_addend_801BF268 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801BF264: lw          $t9, 0x256C($at)
    ctx->r25 = ADD32(ctx->r1, 0X256C);
    // 0x801BF268: jr          $t9
    // 0x801BF26C: nop

    switch (jr_addend_801BF268 >> 2) {
        case 0: goto L_801C195C; break;
        case 1: goto L_801BF270; break;
        case 2: goto L_801BF344; break;
        case 3: goto L_801BF5FC; break;
        case 4: goto L_801BF908; break;
        case 5: goto L_801BFB3C; break;
        case 6: goto L_801BFCAC; break;
        case 7: goto L_801C03A0; break;
        case 8: goto L_801C0660; break;
        case 9: goto L_801C0764; break;
        case 10: goto L_801C0C00; break;
        case 11: goto L_801C0F08; break;
        case 12: goto L_801C1058; break;
        case 13: goto L_801C12D8; break;
        case 14: goto L_801C1540; break;
        case 15: goto L_801C1654; break;
        default: switch_error(__func__, 0x801BF268, 0x801E256C);
    }
    // 0x801BF26C: nop

L_801BF270:
    // 0x801BF270: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x801BF274: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BF278: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BF27C: lw          $t0, 0x2C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X2C);
    // 0x801BF280: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801BF284: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BF288: lwc1        $f14, 0x30($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801BF28C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BF290: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801BF294: swc1        $f14, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f14.u32l;
    // 0x801BF298: lwc1        $f14, 0x34($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801BF29C: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801BF2A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BF2A4: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x801BF2A8: lwc1        $f14, 0x38($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801BF2AC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BF2B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801BF2B4: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    // 0x801BF2B8: lwc1        $f14, 0x3C($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801BF2BC: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801BF2C0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801BF2C4: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    // 0x801BF2C8: lwc1        $f14, 0x40($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801BF2CC: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801BF2D0: addiu       $a0, $a0, 0x2170
    ctx->r4 = ADD32(ctx->r4, 0X2170);
    // 0x801BF2D4: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x801BF2D8: lwc1        $f14, 0x44($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801BF2DC: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801BF2E0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801BF2E4: swc1        $f14, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f14.u32l;
    // 0x801BF2E8: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801BF2EC: addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    // 0x801BF2F0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801BF2F4: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801BF2F8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801BF2FC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801BF300: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801BF304: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801BF308: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801BF30C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801BF310: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801BF314: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x801BF318: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x801BF31C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801BF320: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x801BF324: jal         0x8011AAF4
    // 0x801BF328: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_5;
    // 0x801BF328: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    after_5:
    // 0x801BF32C: bnel        $v0, $zero, L_801C1960
    if (ctx->r2 != 0) {
        // 0x801BF330: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_3;
    // 0x801BF330: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x801BF334: jal         0x801BF1A0
    // 0x801BF338: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_6;
    // 0x801BF338: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801BF33C: b           L_801C1960
    // 0x801BF340: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BF340: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BF344:
    // 0x801BF344: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x801BF348: lbu         $v0, -0x5038($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5038);
    // 0x801BF34C: beql        $v0, $zero, L_801BF37C
    if (ctx->r2 == 0) {
        // 0x801BF350: lw          $t6, 0xE8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XE8);
            goto L_801BF37C;
    }
    goto skip_4;
    // 0x801BF350: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    skip_4:
    // 0x801BF354: beq         $v0, $v1, L_801BF394
    if (ctx->r2 == ctx->r3) {
        // 0x801BF358: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801BF394;
    }
    // 0x801BF358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801BF35C: beq         $v0, $at, L_801BF3D8
    if (ctx->r2 == ctx->r1) {
        // 0x801BF360: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801BF3D8;
    }
    // 0x801BF360: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801BF364: beq         $v0, $at, L_801BF378
    if (ctx->r2 == ctx->r1) {
        // 0x801BF368: lui         $t5, 0x801C
        ctx->r13 = S32(0X801C << 16);
            goto L_801BF378;
    }
    // 0x801BF368: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801BF36C: lw          $t5, -0x4328($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4328);
    // 0x801BF370: b           L_801BF548
    // 0x801BF374: lw          $t0, 0x2C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X2C);
        goto L_801BF548;
    // 0x801BF374: lw          $t0, 0x2C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X2C);
L_801BF378:
    // 0x801BF378: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
L_801BF37C:
    // 0x801BF37C: lw          $t0, 0x2C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X2C);
    // 0x801BF380: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801BF384: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801BF388: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801BF38C: b           L_801BF548
    // 0x801BF390: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
        goto L_801BF548;
    // 0x801BF390: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
L_801BF394:
    // 0x801BF394: lw          $t7, 0xE8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE8);
    // 0x801BF398: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF39C: ldc1        $f8, 0x25B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X25B0);
    // 0x801BF3A0: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x801BF3A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF3A8: lwc1        $f4, 0x34($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801BF3AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF3B0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801BF3B4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801BF3B8: ldc1        $f10, 0x25B8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X25B8);
    // 0x801BF3BC: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x801BF3C0: lwc1        $f6, 0x40($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801BF3C4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801BF3C8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801BF3CC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF3D0: b           L_801BF548
    // 0x801BF3D4: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
        goto L_801BF548;
    // 0x801BF3D4: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
L_801BF3D8:
    // 0x801BF3D8: lw          $t8, 0xE8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE8);
    // 0x801BF3DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF3E0: ldc1        $f4, 0x25C0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X25C0);
    // 0x801BF3E4: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801BF3E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF3EC: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF3F0: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801BF3F4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF3F8: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x801BF3FC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801BF400: ldc1        $f6, 0x25C8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X25C8);
    // 0x801BF404: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801BF408: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801BF40C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF410: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x801BF414: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF418: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x801BF41C: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801BF420: jal         0x8001EAD0
    // 0x801BF424: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x801BF424: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_7:
    // 0x801BF428: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF42C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801BF430: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801BF434: jal         0x8001EB64
    // 0x801BF438: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x801BF438: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_8:
    // 0x801BF43C: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF440: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801BF444: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801BF448: jal         0x8001EAD0
    // 0x801BF44C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_9;
    // 0x801BF44C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_9:
    // 0x801BF450: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF454: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801BF458: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801BF45C: jal         0x8001EB64
    // 0x801BF460: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_10;
    // 0x801BF460: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_10:
    // 0x801BF464: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF468: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801BF46C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BF470: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801BF474: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF478: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF47C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BF480: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801BF484: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BF488: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF48C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801BF490: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF494: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF498: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801BF49C: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x801BF4A0: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801BF4A4: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801BF4A8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801BF4AC: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BF4B0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x801BF4B4: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF4B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BF4BC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BF4C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF4C4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801BF4C8: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801BF4CC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801BF4D0: sub.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d - ctx->f6.d;
    // 0x801BF4D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF4D8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF4DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF4E0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF4E4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BF4E8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801BF4EC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801BF4F0: sub.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d - ctx->f10.d;
    // 0x801BF4F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF4F8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF4FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF500: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801BF504: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801BF508: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x801BF50C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801BF510: jal         0x801C5A1C
    // 0x801BF514: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_11;
    // 0x801BF514: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x801BF518: beq         $v0, $zero, L_801BF540
    if (ctx->r2 == 0) {
        // 0x801BF51C: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_801BF540;
    }
    // 0x801BF51C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801BF520: lwc1        $f10, 0x384($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801BF524: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801BF528: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801BF52C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801BF530: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF534: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x801BF538: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF53C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
L_801BF540:
    // 0x801BF540: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x801BF544: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
L_801BF548:
    // 0x801BF548: lwc1        $f4, 0x30($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801BF54C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BF550: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801BF554: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801BF558: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801BF55C: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801BF560: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801BF564: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801BF568: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801BF56C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BF570: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BF574: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x801BF578: lwc1        $f10, 0x44($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801BF57C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801BF580: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801BF584: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x801BF588: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801BF58C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801BF590: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801BF594: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801BF598: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BF59C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF5A0: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801BF5A4: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801BF5A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801BF5AC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801BF5B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801BF5B4: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801BF5B8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801BF5BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801BF5C0: addiu       $a0, $a0, 0x21B4
    ctx->r4 = ADD32(ctx->r4, 0X21B4);
    // 0x801BF5C4: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // 0x801BF5C8: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801BF5CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BF5D0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801BF5D4: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801BF5D8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801BF5DC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801BF5E0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801BF5E4: jal         0x8011AAF4
    // 0x801BF5E8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_12;
    // 0x801BF5E8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x801BF5EC: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801BF5F0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_5;
    // 0x801BF5F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x801BF5F4: b           L_801C1960
    // 0x801BF5F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BF5F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BF5FC:
    // 0x801BF5FC: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF600: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801BF604: jal         0x8001EAD0
    // 0x801BF608: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_13;
    // 0x801BF608: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_13:
    // 0x801BF60C: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF610: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801BF614: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801BF618: jal         0x8001EB64
    // 0x801BF61C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_14;
    // 0x801BF61C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_14:
    // 0x801BF620: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF624: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801BF628: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801BF62C: jal         0x8001EAD0
    // 0x801BF630: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x801BF630: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_15:
    // 0x801BF634: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF638: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801BF63C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801BF640: jal         0x8001EB64
    // 0x801BF644: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_16;
    // 0x801BF644: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_16:
    // 0x801BF648: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF64C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801BF650: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BF654: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801BF658: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF65C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF660: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BF664: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801BF668: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF66C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801BF670: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BF674: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF678: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF67C: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF680: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801BF684: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x801BF688: add.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d + ctx->f10.d;
    // 0x801BF68C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801BF690: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BF694: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF698: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BF69C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BF6A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF6A4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801BF6A8: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801BF6AC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801BF6B0: sub.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d - ctx->f6.d;
    // 0x801BF6B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF6B8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF6BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF6C0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF6C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BF6C8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801BF6CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF6D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF6D4: sub.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d - ctx->f10.d;
    // 0x801BF6D8: sub.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d - ctx->f8.d;
    // 0x801BF6DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF6E0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF6E4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF6E8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801BF6EC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801BF6F0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801BF6F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801BF6F8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801BF6FC: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x801BF700: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF704: jal         0x801C5A1C
    // 0x801BF708: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_17;
    // 0x801BF708: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x801BF70C: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x801BF710: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x801BF714: beql        $t5, $zero, L_801BF73C
    if (ctx->r13 == 0) {
        // 0x801BF718: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801BF73C;
    }
    goto skip_6;
    // 0x801BF718: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_6:
    // 0x801BF71C: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF720: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801BF724: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801BF728: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    // 0x801BF72C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BF730: b           L_801BF750
    // 0x801BF734: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_801BF750;
    // 0x801BF734: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801BF738: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
L_801BF73C:
    // 0x801BF73C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801BF740: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801BF744: addiu       $a0, $a0, -0x300
    ctx->r4 = ADD32(ctx->r4, -0X300);
    // 0x801BF748: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BF74C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801BF750:
    // 0x801BF750: jal         0x8001EAD0
    // 0x801BF754: sh          $a0, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_18;
    // 0x801BF754: sh          $a0, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r4;
    after_18:
    // 0x801BF758: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x801BF75C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801BF760: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801BF764: lw          $t0, 0x2C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X2C);
    // 0x801BF768: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BF76C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BF770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BF774: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF778: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801BF77C: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801BF780: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801BF784: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801BF788: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF78C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801BF790: lwc1        $f8, 0x4($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X4);
    // 0x801BF794: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801BF798: lh          $a0, 0xBE($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XBE);
    // 0x801BF79C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF7A0: sub.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d - ctx->f6.d;
    // 0x801BF7A4: sub.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f4.d - ctx->f2.d;
    // 0x801BF7A8: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801BF7AC: add.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f10.d + ctx->f2.d;
    // 0x801BF7B0: lwc1        $f10, 0x384($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801BF7B4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801BF7B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BF7BC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF7C0: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801BF7C4: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801BF7C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BF7CC: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF7D0: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x801BF7D4: sub.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d - ctx->f12.d;
    // 0x801BF7D8: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801BF7DC: add.d       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f12.d + ctx->f6.d;
    // 0x801BF7E0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF7E4: jal         0x8001EB64
    // 0x801BF7E8: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_19;
    // 0x801BF7E8: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x801BF7EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BF7F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801BF7F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801BF7F8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801BF7FC: lw          $t5, 0xE8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE8);
    // 0x801BF800: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BF804: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BF808: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF80C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BF810: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801BF814: lw          $t0, 0x2C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X2C);
    // 0x801BF818: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801BF81C: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801BF820: lwc1        $f10, 0x38($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801BF824: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801BF828: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BF82C: cvt.d.s     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f12.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF830: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x801BF834: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x801BF838: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BF83C: sub.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d - ctx->f8.d;
    // 0x801BF840: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BF844: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801BF848: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801BF84C: sub.d       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f6.d - ctx->f12.d;
    // 0x801BF850: addiu       $a0, $a0, 0x21F8
    ctx->r4 = ADD32(ctx->r4, 0X21F8);
    // 0x801BF854: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x801BF858: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801BF85C: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801BF860: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BF864: add.d       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f10.d + ctx->f12.d;
    // 0x801BF868: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF86C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801BF870: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF874: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801BF878: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BF87C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x801BF880: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801BF884: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BF888: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801BF88C: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF890: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF894: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801BF89C: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x801BF8A0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801BF8A4: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x801BF8A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BF8AC: sub.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f8.d - ctx->f2.d;
    // 0x801BF8B0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801BF8B4: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801BF8B8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801BF8BC: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801BF8C0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801BF8C4: add.d       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f2.d + ctx->f10.d;
    // 0x801BF8C8: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801BF8CC: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF8D0: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BF8D4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801BF8D8: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801BF8DC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801BF8E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF8E4: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x801BF8E8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801BF8EC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801BF8F0: jal         0x8011AAF4
    // 0x801BF8F4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_20;
    // 0x801BF8F4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x801BF8F8: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801BF8FC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_7;
    // 0x801BF8FC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x801BF900: b           L_801C1960
    // 0x801BF904: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BF904: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BF908:
    // 0x801BF908: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF90C: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801BF910: jal         0x8001EAD0
    // 0x801BF914: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_21;
    // 0x801BF914: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_21:
    // 0x801BF918: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF91C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801BF920: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801BF924: jal         0x8001EB64
    // 0x801BF928: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_22;
    // 0x801BF928: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_22:
    // 0x801BF92C: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF930: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801BF934: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801BF938: jal         0x8001EAD0
    // 0x801BF93C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_23;
    // 0x801BF93C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_23:
    // 0x801BF940: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF944: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801BF948: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801BF94C: jal         0x8001EB64
    // 0x801BF950: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_24;
    // 0x801BF950: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_24:
    // 0x801BF954: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801BF958: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801BF95C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BF960: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801BF964: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801BF968: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801BF96C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BF970: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF974: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF978: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801BF97C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BF980: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801BF984: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801BF988: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF98C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801BF990: sub.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d - ctx->f10.d;
    // 0x801BF994: add.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d + ctx->f6.d;
    // 0x801BF998: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801BF99C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BF9A0: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x801BF9A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BF9A8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BF9AC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801BF9B0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801BF9B4: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801BF9B8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801BF9BC: sub.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d - ctx->f4.d;
    // 0x801BF9C0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801BF9C4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801BF9C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF9CC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF9D0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801BF9D4: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801BF9D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF9DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF9E0: sub.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d - ctx->f6.d;
    // 0x801BF9E4: sub.d       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f2.d - ctx->f8.d;
    // 0x801BF9E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BF9EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BF9F0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801BF9F4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801BF9F8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801BF9FC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFA00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801BFA04: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801BFA08: sub.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d - ctx->f6.d;
    // 0x801BFA0C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801BFA10: jal         0x801C5A1C
    // 0x801BFA14: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_25;
    // 0x801BFA14: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x801BFA18: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x801BFA1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BFA20: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801BFA24: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801BFA28: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801BFA2C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801BFA30: lwc1        $f6, 0x384($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801BFA34: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801BFA38: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801BFA3C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BFA40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BFA44: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801BFA48: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801BFA4C: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801BFA50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801BFA54: lwc1        $f16, 0x30($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801BFA58: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFA5C: sub.d       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f8.d - ctx->f12.d;
    // 0x801BFA60: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x801BFA64: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFA68: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801BFA6C: mul.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801BFA70: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801BFA74: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801BFA78: addiu       $a0, $a0, 0x223C
    ctx->r4 = ADD32(ctx->r4, 0X223C);
    // 0x801BFA7C: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x801BFA80: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801BFA84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BFA88: add.d       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f12.d + ctx->f10.d;
    // 0x801BFA8C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801BFA90: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BFA94: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801BFA98: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801BFA9C: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801BFAA0: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801BFAA4: lwc1        $f10, 0x3C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801BFAA8: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x801BFAAC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801BFAB0: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801BFAB4: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801BFAB8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801BFABC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BFAC0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801BFAC4: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801BFAC8: sub.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d - ctx->f2.d;
    // 0x801BFACC: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801BFAD0: lwc1        $f10, 0x44($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801BFAD4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801BFAD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFADC: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x801BFAE0: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801BFAE4: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801BFAE8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801BFAEC: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x801BFAF0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801BFAF4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BFAF8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801BFAFC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801BFB00: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801BFB04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BFB08: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801BFB0C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801BFB10: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801BFB14: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801BFB18: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801BFB1C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801BFB20: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801BFB24: jal         0x8011AAF4
    // 0x801BFB28: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_26;
    // 0x801BFB28: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_26:
    // 0x801BFB2C: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801BFB30: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_8;
    // 0x801BFB30: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_8:
    // 0x801BFB34: b           L_801C1960
    // 0x801BFB38: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BFB38: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BFB3C:
    // 0x801BFB3C: lhu         $t6, 0xEF0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801BFB40: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x801BFB44: beq         $t7, $zero, L_801BFC9C
    if (ctx->r15 == 0) {
        // 0x801BFB48: nop
    
            goto L_801BFC9C;
    }
    // 0x801BFB48: nop

    // 0x801BFB4C: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFB50: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801BFB54: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801BFB58: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801BFB5C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFB60: jal         0x8001EAD0
    // 0x801BFB64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_27;
    // 0x801BFB64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_27:
    // 0x801BFB68: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFB6C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFB70: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFB74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFB78: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFB7C: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801BFB80: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801BFB84: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801BFB88: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFB8C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801BFB90: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x801BFB94: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801BFB98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFB9C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFBA0: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801BFBA4: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFBA8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801BFBAC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801BFBB0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801BFBB4: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801BFBB8: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801BFBBC: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801BFBC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFBC4: jal         0x8001EB64
    // 0x801BFBC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_28;
    // 0x801BFBC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_28:
    // 0x801BFBCC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BFBD0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801BFBD4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFBD8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFBDC: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFBE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFBE4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFBE8: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801BFBEC: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801BFBF0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801BFBF4: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BFBF8: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFBFC: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFC00: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801BFC04: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFC08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801BFC0C: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x801BFC10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFC14: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BFC18: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801BFC1C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801BFC20: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801BFC24: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801BFC28: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x801BFC2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFC30: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BFC34: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801BFC38: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801BFC3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801BFC40: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801BFC44: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801BFC48: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801BFC4C: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801BFC50: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801BFC54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BFC58: addiu       $a0, $a0, 0x2280
    ctx->r4 = ADD32(ctx->r4, 0X2280);
    // 0x801BFC5C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801BFC60: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801BFC64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BFC68: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801BFC6C: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801BFC70: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801BFC74: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801BFC78: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801BFC7C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801BFC80: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801BFC84: jal         0x8011AAF4
    // 0x801BFC88: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_29;
    // 0x801BFC88: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_29:
    // 0x801BFC8C: jal         0x801BF1A0
    // 0x801BFC90: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_30;
    // 0x801BFC90: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_30:
    // 0x801BFC94: b           L_801C1960
    // 0x801BFC98: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BFC98: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BFC9C:
    // 0x801BFC9C: jal         0x801BF1A0
    // 0x801BFCA0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_31;
    // 0x801BFCA0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_31:
    // 0x801BFCA4: b           L_801C1960
    // 0x801BFCA8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BFCA8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BFCAC:
    // 0x801BFCAC: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x801BFCB0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801BFCB4: beq         $v0, $at, L_801BFCD8
    if (ctx->r2 == ctx->r1) {
        // 0x801BFCB8: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_801BFCD8;
    }
    // 0x801BFCB8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801BFCBC: beq         $v0, $at, L_801BFCD8
    if (ctx->r2 == ctx->r1) {
        // 0x801BFCC0: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_801BFCD8;
    }
    // 0x801BFCC0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801BFCC4: beq         $v0, $at, L_801BFCD8
    if (ctx->r2 == ctx->r1) {
        // 0x801BFCC8: nop
    
            goto L_801BFCD8;
    }
    // 0x801BFCC8: nop

    // 0x801BFCCC: lbu         $t6, 0xBA2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XBA2);
    // 0x801BFCD0: beql        $t6, $zero, L_801BFCEC
    if (ctx->r14 == 0) {
        // 0x801BFCD4: lhu         $t7, 0xEF0($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0XEF0);
            goto L_801BFCEC;
    }
    goto skip_9;
    // 0x801BFCD4: lhu         $t7, 0xEF0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XEF0);
    skip_9:
L_801BFCD8:
    // 0x801BFCD8: jal         0x801BF1A0
    // 0x801BFCDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_32;
    // 0x801BFCDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x801BFCE0: b           L_801C1960
    // 0x801BFCE4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801BFCE4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801BFCE8: lhu         $t7, 0xEF0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XEF0);
L_801BFCEC:
    // 0x801BFCEC: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x801BFCF0: beql        $t8, $zero, L_801C0378
    if (ctx->r24 == 0) {
        // 0x801BFCF4: lbu         $t3, 0xBA3($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0XBA3);
            goto L_801C0378;
    }
    goto skip_10;
    // 0x801BFCF4: lbu         $t3, 0xBA3($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XBA3);
    skip_10:
    // 0x801BFCF8: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFCFC: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801BFD00: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801BFD04: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801BFD08: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFD0C: jal         0x8001EAD0
    // 0x801BFD10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_33;
    // 0x801BFD10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_33:
    // 0x801BFD14: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFD18: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BFD1C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFD20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BFD24: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFD28: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801BFD2C: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801BFD30: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801BFD34: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFD38: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801BFD3C: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801BFD40: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801BFD44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BFD48: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BFD4C: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x801BFD50: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFD54: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801BFD58: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801BFD5C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801BFD60: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801BFD64: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801BFD68: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801BFD6C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFD70: jal         0x8001EB64
    // 0x801BFD74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_34;
    // 0x801BFD74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_34:
    // 0x801BFD78: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFD7C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801BFD80: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFD84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801BFD88: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFD8C: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801BFD90: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801BFD94: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801BFD98: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BFD9C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFDA0: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFDA4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801BFDA8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801BFDAC: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x801BFDB0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801BFDB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFDB8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BFDBC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801BFDC0: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x801BFDC4: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BFDC8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801BFDCC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801BFDD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801BFDD4: jal         0x801084C4
    // 0x801BFDD8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_35;
    // 0x801BFDD8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    after_35:
    // 0x801BFDDC: beql        $v0, $zero, L_801C0190
    if (ctx->r2 == 0) {
        // 0x801BFDE0: lw          $t3, 0xE0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XE0);
            goto L_801C0190;
    }
    goto skip_11;
    // 0x801BFDE0: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    skip_11:
    // 0x801BFDE4: lbu         $t4, 0x35A($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X35A);
    // 0x801BFDE8: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801BFDEC: beql        $t4, $at, L_801C0190
    if (ctx->r12 == ctx->r1) {
        // 0x801BFDF0: lw          $t3, 0xE0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XE0);
            goto L_801C0190;
    }
    goto skip_12;
    // 0x801BFDF0: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    skip_12:
    // 0x801BFDF4: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFDF8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801BFDFC: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x801BFE00: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x801BFE04: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFE08: jal         0x8001EAD0
    // 0x801BFE0C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_36;
    // 0x801BFE0C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_36:
    // 0x801BFE10: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFE14: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BFE18: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFE1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFE20: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFE24: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801BFE28: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801BFE2C: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801BFE30: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFE34: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801BFE38: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801BFE3C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801BFE40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFE44: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BFE48: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801BFE4C: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFE50: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801BFE54: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x801BFE58: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801BFE5C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x801BFE60: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801BFE64: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x801BFE68: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFE6C: jal         0x8001EB64
    // 0x801BFE70: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_37;
    // 0x801BFE70: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_37:
    // 0x801BFE74: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFE78: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801BFE7C: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFE80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801BFE84: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFE88: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801BFE8C: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801BFE90: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801BFE94: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BFE98: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFE9C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFEA0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x801BFEA4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801BFEA8: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x801BFEAC: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x801BFEB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFEB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFEB8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801BFEBC: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801BFEC0: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BFEC4: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x801BFEC8: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x801BFECC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801BFED0: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x801BFED4: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x801BFED8: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801BFEDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801BFEE0: jal         0x801084C4
    // 0x801BFEE4: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_38;
    // 0x801BFEE4: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    after_38:
    // 0x801BFEE8: beql        $v0, $zero, L_801C02E4
    if (ctx->r2 == 0) {
        // 0x801BFEEC: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C02E4;
    }
    goto skip_13;
    // 0x801BFEEC: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    skip_13:
    // 0x801BFEF0: lbu         $t9, 0x35A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X35A);
    // 0x801BFEF4: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801BFEF8: beql        $t9, $at, L_801C02E4
    if (ctx->r25 == ctx->r1) {
        // 0x801BFEFC: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C02E4;
    }
    goto skip_14;
    // 0x801BFEFC: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    skip_14:
    // 0x801BFF00: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFF04: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801BFF08: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801BFF0C: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x801BFF10: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFF14: jal         0x8001EAD0
    // 0x801BFF18: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_39;
    // 0x801BFF18: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_39:
    // 0x801BFF1C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFF20: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFF24: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFF28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFF2C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFF30: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801BFF34: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801BFF38: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801BFF3C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFF40: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801BFF44: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801BFF48: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801BFF4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFF50: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFF54: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801BFF58: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFF5C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801BFF60: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x801BFF64: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801BFF68: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x801BFF6C: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801BFF70: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x801BFF74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801BFF78: jal         0x8001EB64
    // 0x801BFF7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_40;
    // 0x801BFF7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_40:
    // 0x801BFF80: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801BFF84: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801BFF88: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801BFF8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801BFF90: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801BFF94: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801BFF98: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801BFF9C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801BFFA0: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801BFFA4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801BFFA8: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801BFFAC: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801BFFB0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801BFFB4: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x801BFFB8: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801BFFBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801BFFC0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801BFFC4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801BFFC8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x801BFFCC: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801BFFD0: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x801BFFD4: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801BFFD8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801BFFDC: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x801BFFE0: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x801BFFE4: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801BFFE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801BFFEC: jal         0x801084C4
    // 0x801BFFF0: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_41;
    // 0x801BFFF0: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    after_41:
    // 0x801BFFF4: beql        $v0, $zero, L_801C02E4
    if (ctx->r2 == 0) {
        // 0x801BFFF8: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C02E4;
    }
    goto skip_15;
    // 0x801BFFF8: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    skip_15:
    // 0x801BFFFC: lbu         $t5, 0x35A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C0000: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C0004: beql        $t5, $at, L_801C02E4
    if (ctx->r13 == ctx->r1) {
        // 0x801C0008: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C02E4;
    }
    goto skip_16;
    // 0x801C0008: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    skip_16:
    // 0x801C000C: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0010: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0014: jal         0x8001EAD0
    // 0x801C0018: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_42;
    // 0x801C0018: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_42:
    // 0x801C001C: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0020: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0024: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0028: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C002C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801C0030: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C0034: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0038: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C003C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C0040: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C0044: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C0048: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C004C: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0050: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0054: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0058: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801C005C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0060: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x801C0064: sub.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f4.d - ctx->f2.d;
    // 0x801C0068: mul.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801C006C: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x801C0070: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C0074: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C0078: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801C007C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0080: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C0084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0088: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C008C: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0090: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801C0094: sub.d       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f8.d - ctx->f12.d;
    // 0x801C0098: mul.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C009C: add.d       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f12.d + ctx->f10.d;
    // 0x801C00A0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801C00A4: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801C00A8: jal         0x8001EB64
    // 0x801C00AC: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_43;
    // 0x801C00AC: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    after_43:
    // 0x801C00B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C00B4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C00B8: lw          $t2, 0xE8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE8);
    // 0x801C00BC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801C00C0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C00C4: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801C00C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C00CC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C00D0: lw          $t0, 0x2C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X2C);
    // 0x801C00D4: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801C00D8: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801C00DC: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801C00E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C00E4: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C00E8: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x801C00EC: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801C00F0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801C00F4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801C00F8: sub.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d - ctx->f12.d;
    // 0x801C00FC: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0100: add.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d + ctx->f12.d;
    // 0x801C0104: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0108: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x801C010C: lwc1        $f14, 0x3C($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C0110: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0114: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x801C0118: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x801C011C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0120: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C0124: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C0128: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C012C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C0130: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x801C0134: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0138: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C013C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C0140: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0144: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0148: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801C014C: sub.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d - ctx->f2.d;
    // 0x801C0150: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C0154: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801C0158: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C015C: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x801C0160: lwc1        $f6, 0x44($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801C0164: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x801C0168: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801C016C: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x801C0170: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0174: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0178: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C017C: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x801C0180: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C0184: b           L_801C02E0
    // 0x801C0188: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
        goto L_801C02E0;
    // 0x801C0188: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x801C018C: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
L_801C0190:
    // 0x801C0190: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0194: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x801C0198: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801C019C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C01A0: jal         0x8001EAD0
    // 0x801C01A4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_44;
    // 0x801C01A4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_44:
    // 0x801C01A8: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x801C01AC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C01B0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C01B4: lw          $t0, 0x2C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X2C);
    // 0x801C01B8: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801C01BC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C01C0: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801C01C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C01C8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C01CC: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C01D0: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x801C01D4: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x801C01D8: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801C01DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C01E0: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C01E4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801C01E8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C01EC: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x801C01F0: sub.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f4.d - ctx->f2.d;
    // 0x801C01F4: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C01F8: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x801C01FC: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0200: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C0204: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801C0208: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C020C: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C0210: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0214: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0218: cvt.d.s     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f12.d = CVT_D_S(ctx->f10.fl);
    // 0x801C021C: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x801C0220: sub.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d - ctx->f12.d;
    // 0x801C0224: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C0228: add.d       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f12.d + ctx->f8.d;
    // 0x801C022C: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C0230: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x801C0234: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C0238: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801C023C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0240: jal         0x8001EB64
    // 0x801C0244: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_45;
    // 0x801C0244: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_45:
    // 0x801C0248: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C024C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0250: lw          $t8, 0xE8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0254: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801C0258: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C025C: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0260: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0264: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C0268: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801C026C: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x801C0270: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0274: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801C0278: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C027C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C0280: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0284: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801C0288: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801C028C: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801C0290: sub.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d - ctx->f12.d;
    // 0x801C0294: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0298: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C029C: add.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d + ctx->f12.d;
    // 0x801C02A0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C02A4: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x801C02A8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C02AC: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x801C02B0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C02B4: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C02B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C02BC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C02C0: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801C02C4: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x801C02C8: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x801C02CC: sub.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f10.d - ctx->f2.d;
    // 0x801C02D0: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C02D4: add.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f2.d + ctx->f8.d;
    // 0x801C02D8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C02DC: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
L_801C02E0:
    // 0x801C02E0: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
L_801C02E4:
    // 0x801C02E4: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C02E8: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C02EC: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C02F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C02F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801C02F8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C02FC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801C0300: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801C0304: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801C0308: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801C030C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C0310: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0314: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C0318: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C031C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0320: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C0324: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C0328: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801C032C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801C0330: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801C0334: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C0338: addiu       $a0, $a0, 0x22C4
    ctx->r4 = ADD32(ctx->r4, 0X22C4);
    // 0x801C033C: addiu       $a1, $zero, 0x135
    ctx->r5 = ADD32(0, 0X135);
    // 0x801C0340: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C0344: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C0348: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C034C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C0350: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801C0354: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801C0358: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801C035C: jal         0x8011AAF4
    // 0x801C0360: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_46;
    // 0x801C0360: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_46:
    // 0x801C0364: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801C0368: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_17;
    // 0x801C0368: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_17:
    // 0x801C036C: b           L_801C1960
    // 0x801C0370: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C0370: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C0374: lbu         $t3, 0xBA3($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XBA3);
L_801C0378:
    // 0x801C0378: beq         $t3, $zero, L_801C0390
    if (ctx->r11 == 0) {
        // 0x801C037C: nop
    
            goto L_801C0390;
    }
    // 0x801C037C: nop

    // 0x801C0380: jal         0x801BF1A0
    // 0x801C0384: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_47;
    // 0x801C0384: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_47:
    // 0x801C0388: b           L_801C1960
    // 0x801C038C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C038C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0390:
    // 0x801C0390: jal         0x801BF1A0
    // 0x801C0394: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_48;
    // 0x801C0394: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_48:
    // 0x801C0398: b           L_801C1960
    // 0x801C039C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C039C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C03A0:
    // 0x801C03A0: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801C03A4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C03A8: jal         0x8001EAD0
    // 0x801C03AC: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_49;
    // 0x801C03AC: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_49:
    // 0x801C03B0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C03B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C03B8: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C03BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C03C0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C03C4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C03C8: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C03CC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801C03D0: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C03D4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C03D8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C03DC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C03E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C03E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C03E8: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x801C03EC: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C03F0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C03F4: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C03F8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C03FC: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x801C0400: jal         0x8001EB64
    // 0x801C0404: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_50;
    // 0x801C0404: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    after_50:
    // 0x801C0408: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C040C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C0410: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0414: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C0418: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C041C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0420: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C0424: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801C0428: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C042C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0430: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x801C0434: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801C0438: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x801C043C: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0440: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C0444: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C0448: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C044C: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x801C0450: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0454: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801C0458: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x801C045C: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801C0460: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C0464: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C0468: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x801C046C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C0470: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801C0474: jal         0x801084C4
    // 0x801C0478: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_51;
    // 0x801C0478: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    after_51:
    // 0x801C047C: beql        $v0, $zero, L_801C05D0
    if (ctx->r2 == 0) {
        // 0x801C0480: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C05D0;
    }
    goto skip_18;
    // 0x801C0480: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    skip_18:
    // 0x801C0484: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0488: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C048C: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C0490: addiu       $a0, $a0, 0x600
    ctx->r4 = ADD32(ctx->r4, 0X600);
    // 0x801C0494: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0498: jal         0x8001EAD0
    // 0x801C049C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_52;
    // 0x801C049C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_52:
    // 0x801C04A0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C04A4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C04A8: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801C04AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C04B0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C04B4: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801C04B8: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801C04BC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C04C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C04C4: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801C04C8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801C04CC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801C04D0: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C04D4: addiu       $a0, $a0, 0x600
    ctx->r4 = ADD32(ctx->r4, 0X600);
    // 0x801C04D8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C04DC: jal         0x8001EB64
    // 0x801C04E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_53;
    // 0x801C04E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_53:
    // 0x801C04E4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C04E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C04EC: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C04F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C04F4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C04F8: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801C04FC: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801C0500: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C0504: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C0508: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C050C: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0510: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801C0514: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801C0518: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x801C051C: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x801C0520: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801C0524: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0528: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C052C: jal         0x801084C4
    // 0x801C0530: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_54;
    // 0x801C0530: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    after_54:
    // 0x801C0534: beql        $v0, $zero, L_801C05D0
    if (ctx->r2 == 0) {
        // 0x801C0538: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C05D0;
    }
    goto skip_19;
    // 0x801C0538: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    skip_19:
    // 0x801C053C: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0540: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0544: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x801C0548: addiu       $a0, $a0, -0x600
    ctx->r4 = ADD32(ctx->r4, -0X600);
    // 0x801C054C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0550: jal         0x8001EAD0
    // 0x801C0554: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_55;
    // 0x801C0554: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_55:
    // 0x801C0558: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C055C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C0560: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0564: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C0568: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C056C: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x801C0570: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801C0574: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0578: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C057C: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x801C0580: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0584: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x801C0588: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C058C: addiu       $a0, $a0, -0x600
    ctx->r4 = ADD32(ctx->r4, -0X600);
    // 0x801C0590: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0594: jal         0x8001EB64
    // 0x801C0598: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_56;
    // 0x801C0598: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_56:
    // 0x801C059C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C05A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C05A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C05A8: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C05AC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C05B0: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C05B4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C05B8: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801C05BC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C05C0: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801C05C4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C05C8: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x801C05CC: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
L_801C05D0:
    // 0x801C05D0: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C05D4: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C05D8: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C05DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C05E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801C05E4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C05E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801C05EC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801C05F0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801C05F4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801C05F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C05FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0600: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C0604: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C0608: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C060C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C0610: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C0614: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C0618: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801C061C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801C0620: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C0624: addiu       $a0, $a0, 0x2308
    ctx->r4 = ADD32(ctx->r4, 0X2308);
    // 0x801C0628: addiu       $a1, $zero, 0x14E
    ctx->r5 = ADD32(0, 0X14E);
    // 0x801C062C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C0630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C0634: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C0638: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C063C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801C0640: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801C0644: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801C0648: jal         0x8011AAF4
    // 0x801C064C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_57;
    // 0x801C064C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_57:
    // 0x801C0650: jal         0x801BF1A0
    // 0x801C0654: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_58;
    // 0x801C0654: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_58:
    // 0x801C0658: b           L_801C1960
    // 0x801C065C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C065C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0660:
    // 0x801C0660: lw          $t2, 0xE8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0664: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0668: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C066C: lw          $t0, 0x2C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0670: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801C0674: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0678: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C067C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0680: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801C0684: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801C0688: lwc1        $f6, 0x34($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C068C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C0690: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0694: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x801C0698: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801C069C: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C06A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C06A4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C06A8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801C06AC: lwc1        $f0, 0x38($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801C06B0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C06B4: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C06B8: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801C06BC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C06C0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C06C4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C06C8: sub.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f4.d - ctx->f2.d;
    // 0x801C06CC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C06D0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C06D4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C06D8: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C06DC: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C06E0: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x801C06E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C06E8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801C06EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C06F0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801C06F4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801C06F8: add.d       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f2.d + ctx->f8.d;
    // 0x801C06FC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C0700: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C0704: addiu       $a0, $a0, 0x234C
    ctx->r4 = ADD32(ctx->r4, 0X234C);
    // 0x801C0708: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x801C070C: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C0710: addiu       $a1, $zero, 0x15D
    ctx->r5 = ADD32(0, 0X15D);
    // 0x801C0714: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C0718: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x801C071C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C0720: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C0724: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C0728: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801C072C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801C0730: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801C0734: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801C0738: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801C073C: jal         0x8011AAF4
    // 0x801C0740: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_59;
    // 0x801C0740: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_59:
    // 0x801C0744: lhu         $t7, 0xEF0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C0748: andi        $t8, $t7, 0x880
    ctx->r24 = ctx->r15 & 0X880;
    // 0x801C074C: beql        $t8, $zero, L_801C1960
    if (ctx->r24 == 0) {
        // 0x801C0750: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_20;
    // 0x801C0750: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_20:
    // 0x801C0754: jal         0x801BF1A0
    // 0x801C0758: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_60;
    // 0x801C0758: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_60:
    // 0x801C075C: b           L_801C1960
    // 0x801C0760: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C0760: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0764:
    // 0x801C0764: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0768: lbu         $v0, 0x4011($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4011);
    // 0x801C076C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C0770: bne         $v1, $v0, L_801C0788
    if (ctx->r3 != ctx->r2) {
        // 0x801C0774: nop
    
            goto L_801C0788;
    }
    // 0x801C0774: nop

    // 0x801C0778: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801C077C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C0780: b           L_801C07A8
    // 0x801C0784: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
        goto L_801C07A8;
    // 0x801C0784: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
L_801C0788:
    // 0x801C0788: bne         $v0, $at, L_801C079C
    if (ctx->r2 != ctx->r1) {
        // 0x801C078C: lui         $at, 0xC080
        ctx->r1 = S32(0XC080 << 16);
            goto L_801C079C;
    }
    // 0x801C078C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x801C0790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C0794: b           L_801C07A8
    // 0x801C0798: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
        goto L_801C07A8;
    // 0x801C0798: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
L_801C079C:
    // 0x801C079C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C07A0: nop

    // 0x801C07A4: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
L_801C07A8:
    // 0x801C07A8: lhu         $t9, 0xEF0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C07AC: andi        $t1, $t9, 0x4
    ctx->r9 = ctx->r25 & 0X4;
    // 0x801C07B0: beq         $t1, $zero, L_801C0BF0
    if (ctx->r9 == 0) {
        // 0x801C07B4: nop
    
            goto L_801C0BF0;
    }
    // 0x801C07B4: nop

    // 0x801C07B8: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C07BC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C07C0: jal         0x8001EAD0
    // 0x801C07C4: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_61;
    // 0x801C07C4: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_61:
    // 0x801C07C8: lw          $t5, 0xE8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE8);
    // 0x801C07CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C07D0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C07D4: lw          $t0, 0x2C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X2C);
    // 0x801C07D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C07DC: ldc1        $f6, 0x25D0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X25D0);
    // 0x801C07E0: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801C07E4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C07E8: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C07EC: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801C07F0: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801C07F4: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801C07F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C07FC: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0800: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801C0804: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C0808: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x801C080C: sub.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d - ctx->f2.d;
    // 0x801C0810: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C0814: add.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f8.d + ctx->f2.d;
    // 0x801C0818: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C081C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C0820: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x801C0824: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0828: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C082C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C0830: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0834: cvt.d.s     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f12.d = CVT_D_S(ctx->f10.fl);
    // 0x801C0838: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x801C083C: sub.d       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f10.d - ctx->f12.d;
    // 0x801C0840: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801C0844: add.d       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f12.d + ctx->f4.d;
    // 0x801C0848: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C084C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x801C0850: jal         0x8001EB64
    // 0x801C0854: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_62;
    // 0x801C0854: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    after_62:
    // 0x801C0858: lw          $t7, 0xE8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE8);
    // 0x801C085C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0860: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0864: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C0868: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C086C: ldc1        $f6, 0x25D8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X25D8);
    // 0x801C0870: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0874: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C0878: lwc1        $f8, 0x38($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X38);
    // 0x801C087C: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C0880: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0884: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0888: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C088C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C0890: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0894: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x801C0898: sub.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d - ctx->f12.d;
    // 0x801C089C: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801C08A0: add.d       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f4.d + ctx->f12.d;
    // 0x801C08A4: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801C08A8: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801C08AC: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C08B0: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C08B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C08B8: jal         0x8001EAD0
    // 0x801C08BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_63;
    // 0x801C08BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_63:
    // 0x801C08C0: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x801C08C4: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801C08C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C08CC: lw          $t0, 0x2C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X2C);
    // 0x801C08D0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801C08D4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C08D8: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C08DC: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C08E0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C08E4: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801C08E8: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801C08EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C08F0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C08F4: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801C08F8: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C08FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0900: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0904: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C0908: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C090C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C0910: sub.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d - ctx->f12.d;
    // 0x801C0914: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C0918: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x801C091C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0920: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C0924: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x801C0928: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C092C: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C0930: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C0934: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0938: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801C093C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C0940: sub.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f10.d - ctx->f2.d;
    // 0x801C0944: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0948: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801C094C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0950: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x801C0954: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C0958: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C095C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0960: jal         0x8001EB64
    // 0x801C0964: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_64;
    // 0x801C0964: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_64:
    // 0x801C0968: lw          $t3, 0xE8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE8);
    // 0x801C096C: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801C0970: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0974: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0978: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801C097C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0980: lwc1        $f4, 0x44($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X44);
    // 0x801C0984: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C0988: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C098C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0990: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0994: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0998: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C099C: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801C09A0: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801C09A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C09A8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C09AC: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C09B0: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x801C09B4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801C09B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801C09BC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C09C0: sub.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f10.d - ctx->f2.d;
    // 0x801C09C4: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C09C8: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x801C09CC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C09D0: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x801C09D4: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C09D8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801C09DC: jal         0x801084C4
    // 0x801C09E0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_65;
    // 0x801C09E0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_65:
    // 0x801C09E4: beql        $v0, $zero, L_801C0A00
    if (ctx->r2 == 0) {
        // 0x801C09E8: lwc1        $f4, 0xAC($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
            goto L_801C0A00;
    }
    goto skip_21;
    // 0x801C09E8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    skip_21:
    // 0x801C09EC: lwc1        $f6, 0x380($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C09F0: lwc1        $f8, 0x388($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C09F4: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x801C09F8: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x801C09FC: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
L_801C0A00:
    // 0x801C0A00: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C0A04: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C0A08: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C0A0C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x801C0A10: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x801C0A14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C0A18: jal         0x801084C4
    // 0x801C0A1C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_66;
    // 0x801C0A1C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_66:
    // 0x801C0A20: beql        $v0, $zero, L_801C0B60
    if (ctx->r2 == 0) {
        // 0x801C0A24: lwc1        $f4, 0xB0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C0B60;
    }
    goto skip_22;
    // 0x801C0A24: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    skip_22:
    // 0x801C0A28: lbu         $t5, 0x35A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C0A2C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C0A30: beql        $t5, $at, L_801C0B60
    if (ctx->r13 == ctx->r1) {
        // 0x801C0A34: lwc1        $f4, 0xB0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801C0B60;
    }
    goto skip_23;
    // 0x801C0A34: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    skip_23:
    // 0x801C0A38: lwc1        $f6, 0x380($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C0A3C: lwc1        $f8, 0x384($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C0A40: lwc1        $f4, 0x388($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C0A44: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0A48: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x801C0A4C: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801C0A50: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x801C0A54: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0A58: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801C0A5C: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C0A60: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0A64: jal         0x8001EAD0
    // 0x801C0A68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_67;
    // 0x801C0A68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_67:
    // 0x801C0A6C: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801C0A70: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0A74: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0A78: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801C0A7C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C0A80: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C0A84: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0A88: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0A8C: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C0A90: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0A94: cvt.d.s     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f14.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0A98: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C0A9C: add.d       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = ctx->f14.d + ctx->f14.d;
    // 0x801C0AA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0AA4: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C0AA8: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0AAC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801C0AB0: sub.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d - ctx->f12.d;
    // 0x801C0AB4: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C0AB8: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x801C0ABC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0AC0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C0AC4: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x801C0AC8: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0ACC: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C0AD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C0AD4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0AD8: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801C0ADC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C0AE0: sub.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f10.d - ctx->f2.d;
    // 0x801C0AE4: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0AE8: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801C0AEC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0AF0: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x801C0AF4: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C0AF8: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C0AFC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0B00: jal         0x8001EB64
    // 0x801C0B04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_68;
    // 0x801C0B04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_68:
    // 0x801C0B08: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801C0B0C: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0B10: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0B14: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801C0B18: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0B1C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C0B20: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0B24: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x801C0B28: lwc1        $f8, 0x44($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X44);
    // 0x801C0B2C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0B30: cvt.d.s     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f14.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0B34: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0B38: add.d       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f14.d + ctx->f14.d;
    // 0x801C0B3C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0B40: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0B44: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801C0B48: sub.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f8.d - ctx->f2.d;
    // 0x801C0B4C: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0B50: add.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f10.d + ctx->f2.d;
    // 0x801C0B54: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0B58: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x801C0B5C: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
L_801C0B60:
    // 0x801C0B60: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C0B64: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C0B68: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C0B6C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C0B70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801C0B74: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C0B78: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801C0B7C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801C0B80: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801C0B84: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801C0B88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C0B8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C0B90: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C0B94: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C0B98: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0B9C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C0BA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C0BA4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C0BA8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801C0BAC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801C0BB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C0BB4: addiu       $a0, $a0, 0x2390
    ctx->r4 = ADD32(ctx->r4, 0X2390);
    // 0x801C0BB8: addiu       $a1, $zero, 0x17D
    ctx->r5 = ADD32(0, 0X17D);
    // 0x801C0BBC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C0BC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C0BC4: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C0BC8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C0BCC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801C0BD0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801C0BD4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x801C0BD8: jal         0x8011AAF4
    // 0x801C0BDC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_69;
    // 0x801C0BDC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_69:
    // 0x801C0BE0: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801C0BE4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_24;
    // 0x801C0BE4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_24:
    // 0x801C0BE8: b           L_801C1960
    // 0x801C0BEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C0BEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0BF0:
    // 0x801C0BF0: jal         0x801BF1A0
    // 0x801C0BF4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_70;
    // 0x801C0BF4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_70:
    // 0x801C0BF8: b           L_801C1960
    // 0x801C0BFC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C0BFC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0C00:
    // 0x801C0C00: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0C04: lbu         $v0, 0x4011($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4011);
    // 0x801C0C08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C0C0C: bne         $v1, $v0, L_801C0C24
    if (ctx->r3 != ctx->r2) {
        // 0x801C0C10: nop
    
            goto L_801C0C24;
    }
    // 0x801C0C10: nop

    // 0x801C0C14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C0C18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C0C1C: b           L_801C0C44
    // 0x801C0C20: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
        goto L_801C0C44;
    // 0x801C0C20: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
L_801C0C24:
    // 0x801C0C24: bne         $v0, $at, L_801C0C38
    if (ctx->r2 != ctx->r1) {
        // 0x801C0C28: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_801C0C38;
    }
    // 0x801C0C28: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x801C0C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C0C30: b           L_801C0C44
    // 0x801C0C34: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
        goto L_801C0C44;
    // 0x801C0C34: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
L_801C0C38:
    // 0x801C0C38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C0C3C: nop

    // 0x801C0C40: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
L_801C0C44:
    // 0x801C0C44: lhu         $t8, 0xEF0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C0C48: andi        $t9, $t8, 0x204
    ctx->r25 = ctx->r24 & 0X204;
    // 0x801C0C4C: beq         $t9, $zero, L_801C0EF8
    if (ctx->r25 == 0) {
        // 0x801C0C50: nop
    
            goto L_801C0EF8;
    }
    // 0x801C0C50: nop

    // 0x801C0C54: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0C58: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C0C5C: jal         0x8001EAD0
    // 0x801C0C60: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_71;
    // 0x801C0C60: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_71:
    // 0x801C0C64: lw          $t4, 0xE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0C68: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0C6C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0C70: lw          $t0, 0x2C($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X2C);
    // 0x801C0C74: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801C0C78: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C0C7C: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0C80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C0C84: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C0C88: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C0C8C: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801C0C90: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0C94: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0C98: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0C9C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0CA0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801C0CA4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0CA8: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x801C0CAC: sub.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f10.d - ctx->f2.d;
    // 0x801C0CB0: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801C0CB4: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x801C0CB8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C0CBC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C0CC0: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x801C0CC4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0CC8: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C0CCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C0CD0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0CD4: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0CD8: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x801C0CDC: sub.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d - ctx->f12.d;
    // 0x801C0CE0: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0CE4: add.d       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f12.d + ctx->f6.d;
    // 0x801C0CE8: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801C0CEC: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801C0CF0: jal         0x8001EB64
    // 0x801C0CF4: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_72;
    // 0x801C0CF4: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    after_72:
    // 0x801C0CF8: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0CFC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0D00: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0D04: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C0D08: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801C0D0C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C0D10: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0D14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C0D18: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C0D1C: lwc1        $f4, 0x38($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X38);
    // 0x801C0D20: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801C0D24: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x801C0D28: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0D2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0D30: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C0D34: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0D38: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801C0D3C: sub.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d - ctx->f12.d;
    // 0x801C0D40: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0D44: add.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d + ctx->f12.d;
    // 0x801C0D48: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0D4C: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x801C0D50: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C0D54: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C0D58: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0D5C: jal         0x8001EAD0
    // 0x801C0D60: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_73;
    // 0x801C0D60: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_73:
    // 0x801C0D64: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0D68: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801C0D6C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0D70: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C0D74: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801C0D78: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0D7C: lwc1        $f4, 0x3C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C0D80: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C0D84: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C0D88: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0D8C: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0D90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0D94: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0D98: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C0D9C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801C0DA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0DA4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0DA8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801C0DAC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0DB0: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801C0DB4: sub.d       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f4.d - ctx->f12.d;
    // 0x801C0DB8: mul.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801C0DBC: add.d       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f6.d + ctx->f12.d;
    // 0x801C0DC0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C0DC4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C0DC8: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x801C0DCC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0DD0: lwc1        $f8, 0x40($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C0DD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0DD8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0DDC: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0DE0: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801C0DE4: sub.d       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f8.d - ctx->f2.d;
    // 0x801C0DE8: mul.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C0DEC: add.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d + ctx->f10.d;
    // 0x801C0DF0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801C0DF4: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x801C0DF8: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C0DFC: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C0E00: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C0E04: jal         0x8001EB64
    // 0x801C0E08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_74;
    // 0x801C0E08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_74:
    // 0x801C0E0C: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0E10: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801C0E14: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C0E18: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C0E1C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801C0E20: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801C0E24: lwc1        $f6, 0x44($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X44);
    // 0x801C0E28: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0E2C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0E30: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C0E34: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0E38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C0E3C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C0E40: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0E44: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0E48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0E4C: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801C0E50: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C0E54: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C0E58: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0E5C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x801C0E60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C0E64: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C0E68: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0E6C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C0E70: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x801C0E74: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801C0E78: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801C0E7C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C0E80: sub.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f6.d - ctx->f2.d;
    // 0x801C0E84: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C0E88: addiu       $a0, $a0, 0x23D4
    ctx->r4 = ADD32(ctx->r4, 0X23D4);
    // 0x801C0E8C: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x801C0E90: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0E94: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C0E98: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801C0E9C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C0EA0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801C0EA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C0EA8: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C0EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C0EB0: add.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f10.d + ctx->f2.d;
    // 0x801C0EB4: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C0EB8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C0EBC: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C0EC0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0EC4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801C0EC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C0ECC: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C0ED0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801C0ED4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801C0ED8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801C0EDC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801C0EE0: jal         0x8011AAF4
    // 0x801C0EE4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_75;
    // 0x801C0EE4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_75:
    // 0x801C0EE8: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801C0EEC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_25;
    // 0x801C0EEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_25:
    // 0x801C0EF0: b           L_801C1960
    // 0x801C0EF4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C0EF4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0EF8:
    // 0x801C0EF8: jal         0x801BF1A0
    // 0x801C0EFC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_76;
    // 0x801C0EFC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_76:
    // 0x801C0F00: b           L_801C1960
    // 0x801C0F04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C0F04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C0F08:
    // 0x801C0F08: lhu         $t8, 0xEF0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C0F0C: andi        $t9, $t8, 0x204
    ctx->r25 = ctx->r24 & 0X204;
    // 0x801C0F10: beq         $t9, $zero, L_801C1048
    if (ctx->r25 == 0) {
        // 0x801C0F14: nop
    
            goto L_801C1048;
    }
    // 0x801C0F14: nop

    // 0x801C0F18: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x801C0F1C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C0F20: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C0F24: lw          $t0, 0x2C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X2C);
    // 0x801C0F28: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C0F2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C0F30: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C0F34: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801C0F38: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0F3C: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801C0F40: lwc1        $f6, 0x34($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C0F44: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C0F48: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C0F4C: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x801C0F50: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801C0F54: lwc1        $f14, 0x3C($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C0F58: lwc1        $f12, 0x38($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801C0F5C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C0F60: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x801C0F64: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C0F68: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801C0F6C: addiu       $a0, $a0, 0x2418
    ctx->r4 = ADD32(ctx->r4, 0X2418);
    // 0x801C0F70: addiu       $a1, $zero, 0x1A0
    ctx->r5 = ADD32(0, 0X1A0);
    // 0x801C0F74: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C0F78: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0F7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C0F80: mul.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801C0F84: lwc1        $f6, 0x40($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C0F88: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801C0F8C: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x801C0F90: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C0F94: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0F98: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C0F9C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C0FA0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0FA4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C0FA8: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x801C0FAC: sub.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f6.d - ctx->f2.d;
    // 0x801C0FB0: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C0FB4: add.d       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f2.d + ctx->f10.d;
    // 0x801C0FB8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801C0FBC: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    // 0x801C0FC0: lwc1        $f0, 0x44($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801C0FC4: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C0FC8: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801C0FCC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C0FD0: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x801C0FD4: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801C0FD8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801C0FDC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801C0FE0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C0FE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C0FE8: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C0FEC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801C0FF0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801C0FF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C0FF8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C0FFC: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C1000: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801C1004: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C1008: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801C100C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C1010: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C1014: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801C1018: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801C101C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C1020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C1024: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x801C1028: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801C102C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801C1030: jal         0x8011AAF4
    // 0x801C1034: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_77;
    // 0x801C1034: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_77:
    // 0x801C1038: beql        $v0, $zero, L_801C1960
    if (ctx->r2 == 0) {
        // 0x801C103C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_26;
    // 0x801C103C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_26:
    // 0x801C1040: b           L_801C1960
    // 0x801C1044: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C1044: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C1048:
    // 0x801C1048: jal         0x801BF1A0
    // 0x801C104C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_78;
    // 0x801C104C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_78:
    // 0x801C1050: b           L_801C1960
    // 0x801C1054: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C1054: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C1058:
    // 0x801C1058: lhu         $t6, 0xEF0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C105C: andi        $t7, $t6, 0xA00
    ctx->r15 = ctx->r14 & 0XA00;
    // 0x801C1060: beql        $t7, $zero, L_801C1074
    if (ctx->r15 == 0) {
        // 0x801C1064: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801C1074;
    }
    goto skip_27;
    // 0x801C1064: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_27:
    // 0x801C1068: jal         0x801BF1A0
    // 0x801C106C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_79;
    // 0x801C106C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_79:
    // 0x801C1070: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
L_801C1074:
    // 0x801C1074: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C1078: jal         0x8001EAD0
    // 0x801C107C: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_80;
    // 0x801C107C: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_80:
    // 0x801C1080: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801C1084: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801C1088: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C108C: jal         0x8001EB64
    // 0x801C1090: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_81;
    // 0x801C1090: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_81:
    // 0x801C1094: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C1098: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C109C: ldc1        $f18, 0x25E0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X25E0);
    // 0x801C10A0: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801C10A4: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C10A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C10AC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C10B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C10B4: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C10B8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801C10BC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801C10C0: add.d       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f2.d + ctx->f4.d;
    // 0x801C10C4: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801C10C8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C10CC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C10D0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801C10D4: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x801C10D8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801C10DC: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x801C10E0: sub.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d - ctx->f8.d;
    // 0x801C10E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C10E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C10EC: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801C10F0: add.d       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f2.d + ctx->f10.d;
    // 0x801C10F4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801C10F8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C10FC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801C1100: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C1104: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801C1108: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801C110C: sub.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d - ctx->f8.d;
    // 0x801C1110: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C1114: jal         0x801084C4
    // 0x801C1118: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_82;
    // 0x801C1118: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_82:
    // 0x801C111C: beql        $v0, $zero, L_801C117C
    if (ctx->r2 == 0) {
        // 0x801C1120: lw          $t5, 0xE0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0XE0);
            goto L_801C117C;
    }
    goto skip_28;
    // 0x801C1120: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    skip_28:
    // 0x801C1124: lwc1        $f4, 0x380($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C1128: lwc1        $f8, 0x384($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C112C: lwc1        $f6, 0x388($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C1130: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801C1134: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801C1138: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801C113C: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801C1140: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801C1144: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C1148: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C114C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C1150: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C1154: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x801C1158: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C115C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C1160: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x801C1164: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C1168: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x801C116C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C1170: b           L_801C1234
    // 0x801C1174: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
        goto L_801C1234;
    // 0x801C1174: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x801C1178: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
L_801C117C:
    // 0x801C117C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C1180: jal         0x8001EAD0
    // 0x801C1184: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_83;
    // 0x801C1184: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_83:
    // 0x801C1188: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C118C: ldc1        $f10, 0x25E8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X25E8);
    // 0x801C1190: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C1194: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C1198: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801C119C: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801C11A0: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C11A4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C11A8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C11AC: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x801C11B0: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801C11B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C11B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C11BC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801C11C0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C11C4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C11C8: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x801C11CC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801C11D0: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x801C11D4: jal         0x8001EB64
    // 0x801C11D8: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_84;
    // 0x801C11D8: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    after_84:
    // 0x801C11DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C11E0: ldc1        $f10, 0x25F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X25F0);
    // 0x801C11E4: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C11E8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C11EC: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C11F0: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801C11F4: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C11F8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C11FC: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801C1200: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x801C1204: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C1208: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C120C: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x801C1210: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C1214: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C1218: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x801C121C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C1220: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x801C1224: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C1228: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x801C122C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C1230: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
L_801C1234:
    // 0x801C1234: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C1238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C123C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C1240: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1244: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801C1248: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801C124C: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C1250: lwc1        $f4, 0x25F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25F8);
    // 0x801C1254: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C1258: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C125C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C1260: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801C1264: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801C1268: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801C126C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801C1270: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C1274: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C1278: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C127C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C1280: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C1284: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801C1288: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C128C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801C1290: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801C1294: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801C1298: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C129C: addiu       $a0, $a0, 0x245C
    ctx->r4 = ADD32(ctx->r4, 0X245C);
    // 0x801C12A0: addiu       $a1, $zero, 0x1BB
    ctx->r5 = ADD32(0, 0X1BB);
    // 0x801C12A4: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C12A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C12AC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801C12B0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801C12B4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801C12B8: jal         0x8011AAF4
    // 0x801C12BC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_85;
    // 0x801C12BC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_85:
    // 0x801C12C0: bnel        $v0, $zero, L_801C1960
    if (ctx->r2 != 0) {
        // 0x801C12C4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_29;
    // 0x801C12C4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_29:
    // 0x801C12C8: jal         0x801BF1A0
    // 0x801C12CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_86;
    // 0x801C12CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_86:
    // 0x801C12D0: b           L_801C1960
    // 0x801C12D4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C12D4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C12D8:
    // 0x801C12D8: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C12DC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C12E0: jal         0x8001EAD0
    // 0x801C12E4: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_87;
    // 0x801C12E4: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_87:
    // 0x801C12E8: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801C12EC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801C12F0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C12F4: jal         0x8001EB64
    // 0x801C12F8: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_88;
    // 0x801C12F8: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_88:
    // 0x801C12FC: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C1300: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1304: ldc1        $f18, 0x2600($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X2600);
    // 0x801C1308: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C130C: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C1310: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C1314: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C1318: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C131C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C1320: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801C1324: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801C1328: add.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f2.d + ctx->f8.d;
    // 0x801C132C: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801C1330: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C1334: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C1338: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x801C133C: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801C1340: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801C1344: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x801C1348: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x801C134C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C1350: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C1354: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C1358: add.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d + ctx->f10.d;
    // 0x801C135C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801C1360: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C1364: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C1368: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C136C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801C1370: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801C1374: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x801C1378: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C137C: jal         0x801084C4
    // 0x801C1380: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_89;
    // 0x801C1380: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_89:
    // 0x801C1384: beql        $v0, $zero, L_801C13E4
    if (ctx->r2 == 0) {
        // 0x801C1388: lw          $t9, 0xE0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XE0);
            goto L_801C13E4;
    }
    goto skip_30;
    // 0x801C1388: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    skip_30:
    // 0x801C138C: lwc1        $f8, 0x380($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C1390: lwc1        $f4, 0x384($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C1394: lwc1        $f6, 0x388($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C1398: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C139C: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801C13A0: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x801C13A4: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801C13A8: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C13AC: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C13B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C13B4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C13B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C13BC: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x801C13C0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C13C4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C13C8: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x801C13CC: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801C13D0: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x801C13D4: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C13D8: b           L_801C149C
    // 0x801C13DC: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
        goto L_801C149C;
    // 0x801C13DC: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x801C13E0: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
L_801C13E4:
    // 0x801C13E4: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801C13E8: jal         0x8001EAD0
    // 0x801C13EC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_90;
    // 0x801C13EC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_90:
    // 0x801C13F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C13F4: ldc1        $f10, 0x2608($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X2608);
    // 0x801C13F8: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C13FC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C1400: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801C1404: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801C1408: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801C140C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C1410: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C1414: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801C1418: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801C141C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C1420: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C1424: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801C1428: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C142C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C1430: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801C1434: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801C1438: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x801C143C: jal         0x8001EB64
    // 0x801C1440: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_91;
    // 0x801C1440: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    after_91:
    // 0x801C1444: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1448: ldc1        $f10, 0x2610($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X2610);
    // 0x801C144C: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C1450: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C1454: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801C1458: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C145C: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801C1460: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C1464: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801C1468: sub.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d - ctx->f4.d;
    // 0x801C146C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C1470: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C1474: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x801C1478: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C147C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C1480: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x801C1484: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C1488: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x801C148C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C1490: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x801C1494: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801C1498: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
L_801C149C:
    // 0x801C149C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C14A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C14A4: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C14A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C14AC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801C14B0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801C14B4: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C14B8: lwc1        $f8, 0x2618($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2618);
    // 0x801C14BC: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C14C0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C14C4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C14C8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801C14CC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x801C14D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801C14D4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801C14D8: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C14DC: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C14E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C14E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C14E8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C14EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C14F0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C14F4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C14F8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801C14FC: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801C1500: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C1504: addiu       $a0, $a0, 0x24A0
    ctx->r4 = ADD32(ctx->r4, 0X24A0);
    // 0x801C1508: addiu       $a1, $zero, 0x1D3
    ctx->r5 = ADD32(0, 0X1D3);
    // 0x801C150C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C1510: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801C1514: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801C1518: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801C151C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801C1520: jal         0x8011AAF4
    // 0x801C1524: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_92;
    // 0x801C1524: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_92:
    // 0x801C1528: bnel        $v0, $zero, L_801C1960
    if (ctx->r2 != 0) {
        // 0x801C152C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_31;
    // 0x801C152C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_31:
    // 0x801C1530: jal         0x801BF1A0
    // 0x801C1534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_93;
    // 0x801C1534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_93:
    // 0x801C1538: b           L_801C1960
    // 0x801C153C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C153C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C1540:
    // 0x801C1540: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1544: sb          $zero, 0x4013($at)
    MEM_B(0X4013, ctx->r1) = 0;
    // 0x801C1548: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C154C: sh          $zero, 0x4014($at)
    MEM_H(0X4014, ctx->r1) = 0;
    // 0x801C1550: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1554: sb          $zero, 0x4012($at)
    MEM_B(0X4012, ctx->r1) = 0;
    // 0x801C1558: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C155C: lwc1        $f4, 0x974($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X974);
    // 0x801C1560: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C1564: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C1568: addiu       $v0, $t7, 0x974
    ctx->r2 = ADD32(ctx->r15, 0X974);
    // 0x801C156C: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x801C1570: nop

    // 0x801C1574: bc1t        L_801C1644
    if (c1cs) {
        // 0x801C1578: nop
    
            goto L_801C1644;
    }
    // 0x801C1578: nop

    // 0x801C157C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C1580: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
L_801C1584:
    // 0x801C1584: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C1588: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C158C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C1590: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C1594: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C1598: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C159C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C15A0: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801C15A4: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801C15A8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C15AC: nop

    // 0x801C15B0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C15B4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801C15B8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C15BC: jal         0x8002FC20
    // 0x801C15C0: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_94;
    // 0x801C15C0: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_94:
    // 0x801C15C4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801C15C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C15CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C15D0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C15D4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C15D8: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x801C15DC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C15E0: bc1f        L_801C1604
    if (!c1cs) {
        // 0x801C15E4: nop
    
            goto L_801C1604;
    }
    // 0x801C15E4: nop

    // 0x801C15E8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C15EC: lbu         $at, 0x4012($v1)
    ctx->r1 = MEM_BU(ctx->r3, 0X4012);
    // 0x801C15F0: sll         $v1, $at, 2
    ctx->r3 = S32(ctx->r1 << 2);
    // 0x801C15F4: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x801C15F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C15FC: b           L_801C1644
    // 0x801C1600: sb          $v1, 0x4012($at)
    MEM_B(0X4012, ctx->r1) = ctx->r3;
        goto L_801C1644;
    // 0x801C1600: sb          $v1, 0x4012($at)
    MEM_B(0X4012, ctx->r1) = ctx->r3;
L_801C1604:
    // 0x801C1604: lbu         $v1, 0x4012($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4012);
    // 0x801C1608: addiu       $t1, $t1, 0x974
    ctx->r9 = ADD32(ctx->r9, 0X974);
    // 0x801C160C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C1610: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801C1614: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801C1618: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801C161C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801C1620: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801C1624: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x801C1628: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C162C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1630: sb          $v1, 0x4012($at)
    MEM_B(0X4012, ctx->r1) = ctx->r3;
    // 0x801C1634: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x801C1638: nop

    // 0x801C163C: bc1fl       L_801C1584
    if (!c1cs) {
        // 0x801C1640: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801C1584;
    }
    goto skip_32;
    // 0x801C1640: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_32:
L_801C1644:
    // 0x801C1644: jal         0x801BF1A0
    // 0x801C1648: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_95;
    // 0x801C1648: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_95:
    // 0x801C164C: b           L_801C1960
    // 0x801C1650: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801C1960;
    // 0x801C1650: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C1654:
    // 0x801C1654: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1658: lbu         $v1, 0x4012($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4012);
    // 0x801C165C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C1660: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C1664: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x801C1668: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801C166C: lhu         $t0, 0x9B0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X9B0);
    // 0x801C1670: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x801C1674: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C1678: beq         $t0, $zero, L_801C18BC
    if (ctx->r8 == 0) {
        // 0x801C167C: subu        $t3, $t3, $v1
        ctx->r11 = SUB32(ctx->r11, ctx->r3);
            goto L_801C18BC;
    }
    // 0x801C167C: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x801C1680: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C1684: addiu       $t4, $t4, 0x9E0
    ctx->r12 = ADD32(ctx->r12, 0X9E0);
    // 0x801C1688: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801C168C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x801C1690: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C1694: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C1698: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C169C: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801C16A0: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x801C16A4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C16A8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801C16AC: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801C16B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C16B4: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x801C16B8: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x801C16BC: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x801C16C0: bne         $t0, $at, L_801C17F8
    if (ctx->r8 != ctx->r1) {
        // 0x801C16C4: swc1        $f10, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
            goto L_801C17F8;
    }
    // 0x801C16C4: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x801C16C8: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C16CC: lbu         $t5, 0x4013($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4013);
    // 0x801C16D0: bne         $t5, $zero, L_801C1810
    if (ctx->r13 != 0) {
        // 0x801C16D4: nop
    
            goto L_801C1810;
    }
    // 0x801C16D4: nop

    // 0x801C16D8: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x801C16DC: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C16E0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C16E4: lw          $t0, 0x2C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X2C);
    // 0x801C16E8: lwc1        $f6, 0x30($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C16EC: lwc1        $f4, 0x34($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C16F0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C16F4: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C16F8: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801C16FC: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801C1700: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C1704: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C1708: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C170C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801C1710: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C1714: jal         0x8002FC20
    // 0x801C1718: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_96;
    // 0x801C1718: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_96:
    // 0x801C171C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1720: lbu         $v1, 0x4012($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4012);
    // 0x801C1724: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C1728: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C172C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801C1730: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C1734: lhu         $t8, 0x9B2($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X9B2);
    // 0x801C1738: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801C173C: bgez        $t8, L_801C1750
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C1740: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C1750;
    }
    // 0x801C1740: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C1744: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C1748: nop

    // 0x801C174C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_801C1750:
    // 0x801C1750: div.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801C1754: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1758: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C175C: swc1        $f8, 0x4018($at)
    MEM_W(0X4018, ctx->r1) = ctx->f8.u32l;
    // 0x801C1760: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x801C1764: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C1768: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C176C: lwc1        $f4, 0x3C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C1770: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C1774: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C1778: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C177C: lwc1        $f4, 0x44($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801C1780: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801C1784: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C1788: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C178C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C1790: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801C1794: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801C1798: jal         0x8002FC20
    // 0x801C179C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_97;
    // 0x801C179C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_97:
    // 0x801C17A0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C17A4: lbu         $v1, 0x4012($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4012);
    // 0x801C17A8: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801C17AC: addiu       $t2, $t2, 0x9B0
    ctx->r10 = ADD32(ctx->r10, 0X9B0);
    // 0x801C17B0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x801C17B4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x801C17B8: lhu         $t3, 0x2($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2);
    // 0x801C17BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C17C0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801C17C4: bgez        $t3, L_801C17D8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801C17C8: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C17D8;
    }
    // 0x801C17C8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C17CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C17D0: nop

    // 0x801C17D4: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_801C17D8:
    // 0x801C17D8: div.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801C17DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C17E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C17E4: swc1        $f6, 0x401C($at)
    MEM_W(0X401C, ctx->r1) = ctx->f6.u32l;
    // 0x801C17E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C17EC: sb          $t4, 0x4013($at)
    MEM_B(0X4013, ctx->r1) = ctx->r12;
    // 0x801C17F0: b           L_801C1810
    // 0x801C17F4: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
        goto L_801C1810;
    // 0x801C17F4: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
L_801C17F8:
    // 0x801C17F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C17FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C1800: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1804: swc1        $f0, 0x401C($at)
    MEM_W(0X401C, ctx->r1) = ctx->f0.u32l;
    // 0x801C1808: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C180C: swc1        $f0, 0x4018($at)
    MEM_W(0X4018, ctx->r1) = ctx->f0.u32l;
L_801C1810:
    // 0x801C1810: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1814: lwc1        $f10, 0x4018($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4018);
    // 0x801C1818: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801C181C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1820: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801C1824: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801C1828: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801C182C: lwc1        $f10, 0x401C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X401C);
    // 0x801C1830: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801C1834: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C1838: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C183C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801C1840: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801C1844: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801C1848: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801C184C: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801C1850: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801C1854: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C1858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C185C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C1860: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C1864: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C1868: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801C186C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801C1870: addiu       $a0, $a0, 0x24E4
    ctx->r4 = ADD32(ctx->r4, 0X24E4);
    // 0x801C1874: addiu       $a1, $zero, 0x1FD
    ctx->r5 = ADD32(0, 0X1FD);
    // 0x801C1878: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C187C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C1880: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C1884: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801C1888: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801C188C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x801C1890: jal         0x8011AAF4
    // 0x801C1894: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_98;
    // 0x801C1894: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_98:
    // 0x801C1898: bne         $v0, $zero, L_801C195C
    if (ctx->r2 != 0) {
        // 0x801C189C: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801C195C;
    }
    // 0x801C189C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C18A0: lbu         $v1, 0x4012($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4012);
    // 0x801C18A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C18A8: sb          $zero, 0x4013($at)
    MEM_B(0X4013, ctx->r1) = 0;
    // 0x801C18AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C18B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801C18B4: b           L_801C195C
    // 0x801C18B8: sb          $v1, 0x4012($at)
    MEM_B(0X4012, ctx->r1) = ctx->r3;
        goto L_801C195C;
    // 0x801C18B8: sb          $v1, 0x4012($at)
    MEM_B(0X4012, ctx->r1) = ctx->r3;
L_801C18BC:
    // 0x801C18BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C18C0: lw          $t8, 0xE8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE8);
    // 0x801C18C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C18C8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801C18CC: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801C18D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801C18D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C18D8: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x801C18DC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C18E0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C18E4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801C18E8: lwc1        $f6, 0x34($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X34);
    // 0x801C18EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C18F0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C18F4: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801C18F8: addiu       $a0, $a0, 0x2528
    ctx->r4 = ADD32(ctx->r4, 0X2528);
    // 0x801C18FC: addiu       $a1, $zero, 0x204
    ctx->r5 = ADD32(0, 0X204);
    // 0x801C1900: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801C1904: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801C1908: lwc1        $f8, 0x38($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801C190C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801C1910: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801C1914: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801C1918: lwc1        $f6, 0x3C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801C191C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C1920: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801C1924: lwc1        $f10, 0x40($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801C1928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C192C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801C1930: lwc1        $f4, 0x44($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801C1934: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801C1938: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801C193C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801C1940: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801C1944: jal         0x8011AAF4
    // 0x801C1948: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_99;
    // 0x801C1948: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_99:
    // 0x801C194C: bnel        $v0, $zero, L_801C1960
    if (ctx->r2 != 0) {
        // 0x801C1950: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801C1960;
    }
    goto skip_33;
    // 0x801C1950: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_33:
    // 0x801C1954: jal         0x801BF1A0
    // 0x801C1958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_100;
    // 0x801C1958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_100:
L_801C195C:
    // 0x801C195C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801C1960:
    // 0x801C1960: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801C1964: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x801C1968: jr          $ra
    // 0x801C196C: nop

    return;
    // 0x801C196C: nop

;}
RECOMP_FUNC void M8_FUN_801c1970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1970: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C1974: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C1978: lhu         $t6, 0x18E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c197c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c197c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C197C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1980: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C1984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1988: bne         $t6, $at, L_801C1A14
    if (ctx->r14 != ctx->r1) {
        // 0x801C198C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C1A14;
    }
    // 0x801C198C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1990: lhu         $t7, 0xEF0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XEF0);
    // 0x801C1994: lhu         $t9, 0x190($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X190);
    // 0x801C1998: andi        $t8, $t7, 0xEFFF
    ctx->r24 = ctx->r15 & 0XEFFF;
    // 0x801C199C: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x801C19A0: beq         $at, $zero, L_801C1A24
    if (ctx->r1 == 0) {
        // 0x801C19A4: sh          $t8, 0xEF0($v0)
        MEM_H(0XEF0, ctx->r2) = ctx->r24;
            goto L_801C1A24;
    }
    // 0x801C19A4: sh          $t8, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r24;
    // 0x801C19A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801C19AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C19B0: addu        $at, $at, $t9
    gpr jr_addend_801C19B8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801C19B4: lw          $t9, 0x26D8($at)
    ctx->r25 = ADD32(ctx->r1, 0X26D8);
    // 0x801C19B8: jr          $t9
    // 0x801C19BC: nop

    switch (jr_addend_801C19B8 >> 2) {
        case 0: goto L_801C19C0; break;
        case 1: goto L_801C19D4; break;
        case 2: goto L_801C19E8; break;
        case 3: goto L_801C1A00; break;
        case 4: goto L_801C19D4; break;
        case 5: goto L_801C19C0; break;
        case 6: goto L_801C19D4; break;
        default: switch_error(__func__, 0x801C19B8, 0x801E26D8);
    }
    // 0x801C19BC: nop

L_801C19C0:
    // 0x801C19C0: lui         $a1, 0x8025
    ctx->r5 = S32(0X8025 << 16);
    // 0x801C19C4: jal         0x800058DC
    // 0x801C19C8: addiu       $a1, $a1, -0x7718
    ctx->r5 = ADD32(ctx->r5, -0X7718);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C19C8: addiu       $a1, $a1, -0x7718
    ctx->r5 = ADD32(ctx->r5, -0X7718);
    after_0:
    // 0x801C19CC: b           L_801C1A28
    // 0x801C19D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1A28;
    // 0x801C19D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C19D4:
    // 0x801C19D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C19D8: jal         0x800058DC
    // 0x801C19DC: addiu       $a1, $a1, 0x1A34
    ctx->r5 = ADD32(ctx->r5, 0X1A34);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C19DC: addiu       $a1, $a1, 0x1A34
    ctx->r5 = ADD32(ctx->r5, 0X1A34);
    after_1:
    // 0x801C19E0: b           L_801C1A28
    // 0x801C19E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1A28;
    // 0x801C19E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C19E8:
    // 0x801C19E8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C19EC: sb          $zero, 0x230($v0)
    MEM_B(0X230, ctx->r2) = 0;
    // 0x801C19F0: jal         0x800058DC
    // 0x801C19F4: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C19F4: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, 0X2580);
    after_2:
    // 0x801C19F8: b           L_801C1A28
    // 0x801C19FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1A28;
    // 0x801C19FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1A00:
    // 0x801C1A00: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1A04: jal         0x800058DC
    // 0x801C1A08: addiu       $a1, $a1, 0x3070
    ctx->r5 = ADD32(ctx->r5, 0X3070);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C1A08: addiu       $a1, $a1, 0x3070
    ctx->r5 = ADD32(ctx->r5, 0X3070);
    after_3:
    // 0x801C1A0C: b           L_801C1A28
    // 0x801C1A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1A28;
    // 0x801C1A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1A14:
    // 0x801C1A14: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1A18: sh          $zero, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = 0;
    // 0x801C1A1C: jal         0x800058DC
    // 0x801C1A20: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C1A20: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    after_4:
L_801C1A24:
    // 0x801C1A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1A28:
    // 0x801C1A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1A2C: jr          $ra
    // 0x801C1A30: nop

    return;
    // 0x801C1A30: nop

;}
RECOMP_FUNC void M8_FUN_801c1a34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1A3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1A40: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801C1A44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C1A48: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801C1A4C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x801C1A50: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C1A54: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801C1A58: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x801C1A5C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C1A60: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x801C1A64: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x801C1A68: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x801C1A6C: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x801C1A70: lhu         $t1, 0x192($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X192);
    // 0x801C1A74: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801C1A78: sh          $zero, 0x194($v0)
    MEM_H(0X194, ctx->r2) = 0;
    // 0x801C1A7C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801C1A80: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x801C1A84: beq         $at, $zero, L_801C1B28
    if (ctx->r1 == 0) {
        // 0x801C1A88: sh          $t0, 0x196($v0)
        MEM_H(0X196, ctx->r2) = ctx->r8;
            goto L_801C1B28;
    }
    // 0x801C1A88: sh          $t0, 0x196($v0)
    MEM_H(0X196, ctx->r2) = ctx->r8;
    // 0x801C1A8C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801C1A90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1A94: addu        $at, $at, $t2
    gpr jr_addend_801C1A9C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801C1A98: lw          $t2, 0x26F4($at)
    ctx->r10 = ADD32(ctx->r1, 0X26F4);
    // 0x801C1A9C: jr          $t2
    // 0x801C1AA0: nop

    switch (jr_addend_801C1A9C >> 2) {
        case 0: goto L_801C1AA4; break;
        case 1: goto L_801C1AB8; break;
        case 2: goto L_801C1ACC; break;
        case 3: goto L_801C1AE0; break;
        case 4: goto L_801C1AF4; break;
        case 5: goto L_801C1B08; break;
        case 6: goto L_801C1B1C; break;
        default: switch_error(__func__, 0x801C1A9C, 0x801E26F4);
    }
    // 0x801C1AA0: nop

L_801C1AA4:
    // 0x801C1AA4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1AA8: jal         0x800058DC
    // 0x801C1AAC: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1AAC: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, 0X1B38);
    after_0:
    // 0x801C1AB0: b           L_801C1B2C
    // 0x801C1AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1B2C;
    // 0x801C1AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1AB8:
    // 0x801C1AB8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1ABC: jal         0x800058DC
    // 0x801C1AC0: addiu       $a1, $a1, 0x2110
    ctx->r5 = ADD32(ctx->r5, 0X2110);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1AC0: addiu       $a1, $a1, 0x2110
    ctx->r5 = ADD32(ctx->r5, 0X2110);
    after_1:
    // 0x801C1AC4: b           L_801C1B2C
    // 0x801C1AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1B2C;
    // 0x801C1AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1ACC:
    // 0x801C1ACC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1AD0: jal         0x800058DC
    // 0x801C1AD4: addiu       $a1, $a1, 0x1EE0
    ctx->r5 = ADD32(ctx->r5, 0X1EE0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C1AD4: addiu       $a1, $a1, 0x1EE0
    ctx->r5 = ADD32(ctx->r5, 0X1EE0);
    after_2:
    // 0x801C1AD8: b           L_801C1B2C
    // 0x801C1ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1B2C;
    // 0x801C1ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1AE0:
    // 0x801C1AE0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1AE4: jal         0x800058DC
    // 0x801C1AE8: addiu       $a1, $a1, 0x2030
    ctx->r5 = ADD32(ctx->r5, 0X2030);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C1AE8: addiu       $a1, $a1, 0x2030
    ctx->r5 = ADD32(ctx->r5, 0X2030);
    after_3:
    // 0x801C1AEC: b           L_801C1B2C
    // 0x801C1AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1B2C;
    // 0x801C1AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1AF4:
    // 0x801C1AF4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1AF8: jal         0x800058DC
    // 0x801C1AFC: addiu       $a1, $a1, 0x22A0
    ctx->r5 = ADD32(ctx->r5, 0X22A0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C1AFC: addiu       $a1, $a1, 0x22A0
    ctx->r5 = ADD32(ctx->r5, 0X22A0);
    after_4:
    // 0x801C1B00: b           L_801C1B2C
    // 0x801C1B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1B2C;
    // 0x801C1B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1B08:
    // 0x801C1B08: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1B0C: jal         0x800058DC
    // 0x801C1B10: addiu       $a1, $a1, 0x2494
    ctx->r5 = ADD32(ctx->r5, 0X2494);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C1B10: addiu       $a1, $a1, 0x2494
    ctx->r5 = ADD32(ctx->r5, 0X2494);
    after_5:
    // 0x801C1B14: b           L_801C1B2C
    // 0x801C1B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1B2C;
    // 0x801C1B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1B1C:
    // 0x801C1B1C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1B20: jal         0x800058DC
    // 0x801C1B24: addiu       $a1, $a1, 0x1D90
    ctx->r5 = ADD32(ctx->r5, 0X1D90);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C1B24: addiu       $a1, $a1, 0x1D90
    ctx->r5 = ADD32(ctx->r5, 0X1D90);
    after_6:
L_801C1B28:
    // 0x801C1B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1B2C:
    // 0x801C1B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1B30: jr          $ra
    // 0x801C1B34: nop

    return;
    // 0x801C1B34: nop

;}
RECOMP_FUNC void M8_FUN_801c1b38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1B38: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C1B3C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C1B40: lhu         $t6, 0x192($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X192);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c1b44(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c1b44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1B4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1B50: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801C1B54: bne         $t6, $at, L_801C1B70
    if (ctx->r14 != ctx->r1) {
        // 0x801C1B58: lw          $v0, 0x5C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X5C);
            goto L_801C1B70;
    }
    // 0x801C1B58: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801C1B5C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1B60: jal         0x800058DC
    // 0x801C1B64: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1B64: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    after_0:
    // 0x801C1B68: b           L_801C1C10
    // 0x801C1B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C1C10;
    // 0x801C1B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1B70:
    // 0x801C1B70: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x801C1B74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C1B78: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801C1B7C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x801C1B80: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x801C1B84: ori         $t0, $t8, 0x20
    ctx->r8 = ctx->r24 | 0X20;
    // 0x801C1B88: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x801C1B8C: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x801C1B90: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x801C1B94: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x801C1B98: lhu         $t1, 0x190($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X190);
    // 0x801C1B9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801C1BA0: addiu       $t4, $zero, 0x1100
    ctx->r12 = ADD32(0, 0X1100);
    // 0x801C1BA4: bne         $t1, $at, L_801C1BD0
    if (ctx->r9 != ctx->r1) {
        // 0x801C1BA8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_801C1BD0;
    }
    // 0x801C1BA8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C1BAC: lui         $t2, 0x168
    ctx->r10 = S32(0X168 << 16);
    // 0x801C1BB0: ori         $t2, $t2, 0x42
    ctx->r10 = ctx->r10 | 0X42;
    // 0x801C1BB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1BB8: sw          $t2, 0xB00($at)
    MEM_W(0XB00, ctx->r1) = ctx->r10;
    // 0x801C1BBC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801C1BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C1BC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1BC8: b           L_801C1BF0
    // 0x801C1BCC: swc1        $f4, 0xB08($at)
    MEM_W(0XB08, ctx->r1) = ctx->f4.u32l;
        goto L_801C1BF0;
    // 0x801C1BCC: swc1        $f4, 0xB08($at)
    MEM_W(0XB08, ctx->r1) = ctx->f4.u32l;
L_801C1BD0:
    // 0x801C1BD0: lui         $t3, 0x168
    ctx->r11 = S32(0X168 << 16);
    // 0x801C1BD4: ori         $t3, $t3, 0x41
    ctx->r11 = ctx->r11 | 0X41;
    // 0x801C1BD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1BDC: sw          $t3, 0xB00($at)
    MEM_W(0XB00, ctx->r1) = ctx->r11;
    // 0x801C1BE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C1BE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C1BE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1BEC: swc1        $f6, 0xB08($at)
    MEM_W(0XB08, ctx->r1) = ctx->f6.u32l;
L_801C1BF0:
    // 0x801C1BF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1BF4: sh          $zero, 0xB04($at)
    MEM_H(0XB04, ctx->r1) = 0;
    // 0x801C1BF8: sh          $t4, 0xB06($at)
    MEM_H(0XB06, ctx->r1) = ctx->r12;
    // 0x801C1BFC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1C00: sh          $t5, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r13;
    // 0x801C1C04: jal         0x800058DC
    // 0x801C1C08: addiu       $a1, $a1, 0x1C1C
    ctx->r5 = ADD32(ctx->r5, 0X1C1C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1C08: addiu       $a1, $a1, 0x1C1C
    ctx->r5 = ADD32(ctx->r5, 0X1C1C);
    after_1:
    // 0x801C1C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1C10:
    // 0x801C1C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1C14: jr          $ra
    // 0x801C1C18: nop

    return;
    // 0x801C1C18: nop

;}
RECOMP_FUNC void M8_FUN_801c1c1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C1C20: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C1C24: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C1C28: lhu         $t8, 0x190($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X190);
    // 0x801C1C2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C1C30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C1C34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C1C38: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x801C1C3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801C1C40: bne         $t8, $at, L_801C1C90
    if (ctx->r24 != ctx->r1) {
        // 0x801C1C44: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_801C1C90;
    }
    // 0x801C1C44: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801C1C48: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C1C4C: addiu       $t9, $t9, 0xB00
    ctx->r25 = ADD32(ctx->r25, 0XB00);
    // 0x801C1C50: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C1C54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801C1C58: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x801C1C5C: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x801C1C60: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x801C1C64: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C1C68: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x801C1C6C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C1C70: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801C1C74: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801C1C78: jal         0x8012CE9C
    // 0x801C1C7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801C1C7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x801C1C80: beql        $v0, $zero, L_801C1CD4
    if (ctx->r2 == 0) {
        // 0x801C1C84: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_801C1CD4;
    }
    goto skip_0;
    // 0x801C1C84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801C1C88: b           L_801C1D84
    // 0x801C1C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C1D84;
    // 0x801C1C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C1C90:
    // 0x801C1C90: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C1C94: addiu       $t3, $t3, 0xB00
    ctx->r11 = ADD32(ctx->r11, 0XB00);
    // 0x801C1C98: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801C1C9C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801C1CA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801C1CA4: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x801C1CA8: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x801C1CAC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C1CB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801C1CB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C1CB8: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801C1CBC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801C1CC0: jal         0x8012CE9C
    // 0x801C1CC4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_1;
    // 0x801C1CC4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x801C1CC8: bnel        $v0, $zero, L_801C1D84
    if (ctx->r2 != 0) {
        // 0x801C1CCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C1D84;
    }
    goto skip_1;
    // 0x801C1CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801C1CD0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_801C1CD4:
    // 0x801C1CD4: jal         0x80010550
    // 0x801C1CD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801C1CD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801C1CDC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C1CE0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C1CE4: lhu         $a0, 0x194($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X194);
    // 0x801C1CE8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C1CEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C1CF0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801C1CF4: bne         $a0, $at, L_801C1D14
    if (ctx->r4 != ctx->r1) {
        // 0x801C1CF8: sh          $t8, 0x196($v1)
        MEM_H(0X196, ctx->r3) = ctx->r24;
            goto L_801C1D14;
    }
    // 0x801C1CF8: sh          $t8, 0x196($v1)
    MEM_H(0X196, ctx->r3) = ctx->r24;
    // 0x801C1CFC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1D00: addiu       $a1, $a1, 0x1A34
    ctx->r5 = ADD32(ctx->r5, 0X1A34);
    // 0x801C1D04: jal         0x800058DC
    // 0x801C1D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C1D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x801C1D0C: b           L_801C1D84
    // 0x801C1D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C1D84;
    // 0x801C1D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C1D14:
    // 0x801C1D14: lhu         $t7, 0x192($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X192);
    // 0x801C1D18: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801C1D1C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1D20: bne         $t7, $at, L_801C1D38
    if (ctx->r15 != ctx->r1) {
        // 0x801C1D24: addiu       $a1, $a1, 0x5010
        ctx->r5 = ADD32(ctx->r5, 0X5010);
            goto L_801C1D38;
    }
    // 0x801C1D24: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C1D28: jal         0x800058DC
    // 0x801C1D2C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C1D2C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x801C1D30: b           L_801C1D84
    // 0x801C1D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C1D84;
    // 0x801C1D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C1D38:
    // 0x801C1D38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C1D3C: bne         $a0, $at, L_801C1D80
    if (ctx->r4 != ctx->r1) {
        // 0x801C1D40: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_801C1D80;
    }
    // 0x801C1D40: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801C1D44: lhu         $t0, 0xEF0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C1D48: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C1D4C: sh          $t9, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r25;
    // 0x801C1D50: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x801C1D54: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C1D58: sh          $t1, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r9;
    // 0x801C1D5C: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x801C1D60: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1D64: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C1D68: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x801C1D6C: sw          $t3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r11;
    // 0x801C1D70: lw          $t4, 0xEFC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C1D74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801C1D78: jal         0x800058DC
    // 0x801C1D7C: sw          $t4, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C1D7C: sw          $t4, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r12;
    after_5:
L_801C1D80:
    // 0x801C1D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C1D84:
    // 0x801C1D84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C1D88: jr          $ra
    // 0x801C1D8C: nop

    return;
    // 0x801C1D8C: nop

;}
RECOMP_FUNC void M8_FUN_801c1d90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1D98: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801C1D9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C1DA0: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x801C1DA4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x801C1DA8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801C1DAC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C1DB0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1DB4: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801C1DB8: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x801C1DBC: addiu       $v0, $v0, 0xB00
    ctx->r2 = ADD32(ctx->r2, 0XB00);
    // 0x801C1DC0: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x801C1DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C1DC8: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x801C1DCC: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x801C1DD0: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x801C1DD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C1DD8: lui         $t0, 0x168
    ctx->r8 = S32(0X168 << 16);
    // 0x801C1DDC: ori         $t0, $t0, 0x41
    ctx->r8 = ctx->r8 | 0X41;
    // 0x801C1DE0: addiu       $t1, $zero, 0x1100
    ctx->r9 = ADD32(0, 0X1100);
    // 0x801C1DE4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801C1DE8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801C1DEC: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x801C1DF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C1DF4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C1DF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801C1DFC: sh          $t2, 0x78($a1)
    MEM_H(0X78, ctx->r5) = ctx->r10;
    // 0x801C1E00: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801C1E04: jal         0x80010550
    // 0x801C1E08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801C1E08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x801C1E0C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C1E14: jal         0x800058DC
    // 0x801C1E18: addiu       $a1, $a1, 0x1E2C
    ctx->r5 = ADD32(ctx->r5, 0X1E2C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1E18: addiu       $a1, $a1, 0x1E2C
    ctx->r5 = ADD32(ctx->r5, 0X1E2C);
    after_1:
    // 0x801C1E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1E24: jr          $ra
    // 0x801C1E28: nop

    return;
    // 0x801C1E28: nop

;}
RECOMP_FUNC void M8_FUN_801c1e2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1E34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C1E38: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801C1E3C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801C1E40: jal         0x80010550
    // 0x801C1E44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801C1E44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x801C1E48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C1E4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C1E50: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1E54: sh          $t7, -0x427A($at)
    MEM_H(-0X427A, ctx->r1) = ctx->r15;
    // 0x801C1E58: addiu       $a1, $a1, 0x1E74
    ctx->r5 = ADD32(ctx->r5, 0X1E74);
    // 0x801C1E5C: jal         0x800058DC
    // 0x801C1E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C1E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C1E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1E6C: jr          $ra
    // 0x801C1E70: nop

    return;
    // 0x801C1E70: nop

;}
RECOMP_FUNC void M8_FUN_801c1e74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E74: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C1E78: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C1E7C: lhu         $t6, 0x194($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X194);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c1e80(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c1e80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C1E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1E8C: bne         $t6, $at, L_801C1ED0
    if (ctx->r14 != ctx->r1) {
        // 0x801C1E90: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C1ED0;
    }
    // 0x801C1E90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1E94: lhu         $t8, 0xEF0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C1E98: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x801C1E9C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801C1EA0: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801C1EA4: sh          $t7, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r15;
    // 0x801C1EA8: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x801C1EAC: sh          $t9, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r25;
    // 0x801C1EB0: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801C1EB4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1EB8: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801C1EBC: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x801C1EC0: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    // 0x801C1EC4: lw          $t2, 0xEFC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C1EC8: jal         0x800058DC
    // 0x801C1ECC: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1ECC: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    after_0:
L_801C1ED0:
    // 0x801C1ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1ED8: jr          $ra
    // 0x801C1EDC: nop

    return;
    // 0x801C1EDC: nop

;}
