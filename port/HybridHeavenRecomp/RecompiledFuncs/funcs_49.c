#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801cdb94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDB94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDB98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CDB9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CDBA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDBA4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CDBA8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDBAC: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    // 0x801CDBB0: jal         0x800058DC
    // 0x801CDBB4: addiu       $a1, $a1, -0x32A0
    ctx->r5 = ADD32(ctx->r5, -0X32A0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CDBB4: addiu       $a1, $a1, -0x32A0
    ctx->r5 = ADD32(ctx->r5, -0X32A0);
    after_0:
    // 0x801CDBB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDBBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDBC0: jr          $ra
    // 0x801CDBC4: nop

    return;
    // 0x801CDBC4: nop

;}
RECOMP_FUNC void M24_FUN_801cdbc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDBC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CDBCC: jr          $ra
    // 0x801CDBD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CDBD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdbd4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdbd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDBD4: sub.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x801CDBD8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CDBDC: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x801CDBE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801CDBE4: jr          $ra
    // 0x801CDBE8: add.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f12.fl;
    return;
    // 0x801CDBE8: add.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f12.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdbec(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdbec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDBEC: nop

;}
RECOMP_FUNC void M24_FUN_801cdbf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDBF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDBF4: sw          $zero, -0x5434($at)
    MEM_W(-0X5434, ctx->r1) = 0;
    // 0x801CDBF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDBFC: sw          $zero, -0x53B8($at)
    MEM_W(-0X53B8, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdc00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdc00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDC00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDC04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDC08: sw          $zero, -0x53B4($at)
    MEM_W(-0X53B4, ctx->r1) = 0;
    // 0x801CDC0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDC10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CDC14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDC18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CDC1C: sw          $zero, -0x5430($at)
    MEM_W(-0X5430, ctx->r1) = 0;
    // 0x801CDC20: jal         0x801BF6C4
    // 0x801CDC24: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_0;
    // 0x801CDC24: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x801CDC28: jal         0x801CDDF8
    // 0x801CDC2C: nop

    LOOKUP_FUNC(0x801CDDF8)(rdram, ctx);
        goto after_1;
    // 0x801CDC2C: nop

    after_1:
    // 0x801CDC30: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CDC34: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDC38: addiu       $v0, $v0, -0x5418
    ctx->r2 = ADD32(ctx->r2, -0X5418);
    // 0x801CDC3C: addiu       $t6, $t6, 0xD10
    ctx->r14 = ADD32(ctx->r14, 0XD10);
    // 0x801CDC40: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801CDC44: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CDC48: lui         $t0, 0xDF00
    ctx->r8 = S32(0XDF00 << 16);
    // 0x801CDC4C: addiu       $t7, $t7, 0xF10
    ctx->r15 = ADD32(ctx->r15, 0XF10);
    // 0x801CDC50: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x801CDC54: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801CDC58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801CDC5C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801CDC60: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801CDC64: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x801CDC68: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x801CDC6C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDC70: addiu       $a1, $a1, -0x2374
    ctx->r5 = ADD32(ctx->r5, -0X2374);
    // 0x801CDC74: jal         0x800058DC
    // 0x801CDC78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CDC78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801CDC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDC84: jr          $ra
    // 0x801CDC88: nop

    return;
    // 0x801CDC88: nop

;}
RECOMP_FUNC void M24_FUN_801cdc8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDC8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDC90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDC94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CDC98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDC9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CDCA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CDCA4: jal         0x801BF968
    // 0x801CDCA8: sw          $t6, -0x5434($at)
    MEM_W(-0X5434, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x801CDCA8: sw          $t6, -0x5434($at)
    MEM_W(-0X5434, ctx->r1) = ctx->r14;
    after_0:
    // 0x801CDCAC: beq         $v0, $zero, L_801CDCC0
    if (ctx->r2 == 0) {
        // 0x801CDCB0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801CDCC0;
    }
    // 0x801CDCB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CDCB4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDCB8: jal         0x800058DC
    // 0x801CDCBC: addiu       $a1, $a1, -0x2330
    ctx->r5 = ADD32(ctx->r5, -0X2330);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CDCBC: addiu       $a1, $a1, -0x2330
    ctx->r5 = ADD32(ctx->r5, -0X2330);
    after_1:
L_801CDCC0:
    // 0x801CDCC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDCC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDCC8: jr          $ra
    // 0x801CDCCC: nop

    return;
    // 0x801CDCCC: nop

;}
RECOMP_FUNC void M24_FUN_801cdcd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDCD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdcd4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdcd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDCD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDCD8: sw          $a0, -0x53B8($at)
    MEM_W(-0X53B8, ctx->r1) = ctx->r4;
    // 0x801CDCDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDCE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CDCE8: sw          $a1, -0x53B4($at)
    MEM_W(-0X53B4, ctx->r1) = ctx->r5;
    // 0x801CDCEC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CDCF0: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CDCF4: addiu       $a2, $a2, 0x1188
    ctx->r6 = ADD32(ctx->r6, 0X1188);
    // 0x801CDCF8: addiu       $a0, $a0, -0x5440
    ctx->r4 = ADD32(ctx->r4, -0X5440);
    // 0x801CDCFC: jal         0x801BF850
    // 0x801CDD00: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_0;
    // 0x801CDD00: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x801CDD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDD08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDD0C: jr          $ra
    // 0x801CDD10: nop

    return;
    // 0x801CDD10: nop

;}
RECOMP_FUNC void M24_FUN_801cdd14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDD14: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CDD18: jr          $ra
    // 0x801CDD1C: lw          $v0, -0x5434($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5434);
    return;
    // 0x801CDD1C: lw          $v0, -0x5434($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5434);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdd20(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdd20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDD20: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CDD24: addiu       $v1, $v1, -0x5430
    ctx->r3 = ADD32(ctx->r3, -0X5430);
    // 0x801CDD28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CDD2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801CDD30: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801CDD34: jr          $ra
    // 0x801CDD38: slti        $v0, $t7, 0xA
    ctx->r2 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    return;
    // 0x801CDD38: slti        $v0, $t7, 0xA
    ctx->r2 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdd3c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdd3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDD3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CDD40: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CDD44: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDD48: addiu       $v0, $v0, -0x5418
    ctx->r2 = ADD32(ctx->r2, -0X5418);
    // 0x801CDD4C: addiu       $t6, $t6, 0xD10
    ctx->r14 = ADD32(ctx->r14, 0XD10);
    // 0x801CDD50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CDD54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CDD58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CDD5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CDD60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801CDD64: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CDD68: lui         $a3, 0xDF00
    ctx->r7 = S32(0XDF00 << 16);
    // 0x801CDD6C: addiu       $t7, $t7, 0xF10
    ctx->r15 = ADD32(ctx->r15, 0XF10);
    // 0x801CDD70: sw          $a3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r7;
    // 0x801CDD74: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801CDD78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801CDD7C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801CDD80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801CDD84: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801CDD88: addiu       $s2, $s2, -0x5430
    ctx->r18 = ADD32(ctx->r18, -0X5430);
    // 0x801CDD8C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x801CDD90: sw          $a3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r7;
    // 0x801CDD94: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801CDD98: beq         $a2, $zero, L_801CDDD4
    if (ctx->r6 == 0) {
        // 0x801CDD9C: nop
    
            goto L_801CDDD4;
    }
    // 0x801CDD9C: nop

    // 0x801CDDA0: blez        $a2, L_801CDDD0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x801CDDA4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801CDDD0;
    }
    // 0x801CDDA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CDDA8: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CDDAC: addiu       $s1, $s1, 0x1110
    ctx->r17 = ADD32(ctx->r17, 0X1110);
L_801CDDB0:
    // 0x801CDDB0: jal         0x801C25B0
    // 0x801CDDB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C25B0)(rdram, ctx);
        goto after_0;
    // 0x801CDDB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x801CDDB8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x801CDDBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CDDC0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x801CDDC4: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801CDDC8: bne         $at, $zero, L_801CDDB0
    if (ctx->r1 != 0) {
        // 0x801CDDCC: nop
    
            goto L_801CDDB0;
    }
    // 0x801CDDCC: nop

L_801CDDD0:
    // 0x801CDDD0: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_801CDDD4:
    // 0x801CDDD4: jal         0x801CDDF8
    // 0x801CDDD8: nop

    LOOKUP_FUNC(0x801CDDF8)(rdram, ctx);
        goto after_1;
    // 0x801CDDD8: nop

    after_1:
    // 0x801CDDDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CDDE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CDDE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CDDE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CDDEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CDDF0: jr          $ra
    // 0x801CDDF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CDDF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cddf8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cddf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDDF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDDFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDE00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDE04: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CDE08: sw          $zero, -0x5430($at)
    MEM_W(-0X5430, ctx->r1) = 0;
    // 0x801CDE0C: addiu       $a1, $a1, 0x1110
    ctx->r5 = ADD32(ctx->r5, 0X1110);
    // 0x801CDE10: jal         0x801C26C4
    // 0x801CDE14: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x801C26C4)(rdram, ctx);
        goto after_0;
    // 0x801CDE14: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x801CDE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDE1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDE20: jr          $ra
    // 0x801CDE24: nop

    return;
    // 0x801CDE24: nop

;}
RECOMP_FUNC void M24_FUN_801cde28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CDE2C: jr          $ra
    // 0x801CDE30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CDE30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cde34(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cde34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDE38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CDE3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CDE40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDE44: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CDE48: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDE4C: lw          $a0, -0x53B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B8);
    // 0x801CDE50: jal         0x800058DC
    // 0x801CDE54: addiu       $a1, $a1, -0x2374
    ctx->r5 = ADD32(ctx->r5, -0X2374);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CDE54: addiu       $a1, $a1, -0x2374
    ctx->r5 = ADD32(ctx->r5, -0X2374);
    after_0:
    // 0x801CDE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CDE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDE60: jr          $ra
    // 0x801CDE64: nop

    return;
    // 0x801CDE64: nop

;}
RECOMP_FUNC void M24_FUN_801cde68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CDE6C: jr          $ra
    // 0x801CDE70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CDE70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cde74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cde74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE74: nop

    // 0x801CDE78: nop

    // 0x801CDE7C: nop

;}
RECOMP_FUNC void M24_FUN_801cde80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDE84: sw          $a0, -0x53B0($at)
    MEM_W(-0X53B0, ctx->r1) = ctx->r4;
    // 0x801CDE88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDE8C: sw          $zero, -0x5390($at)
    MEM_W(-0X5390, ctx->r1) = 0;
    // 0x801CDE90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cde94(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cde94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDE94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801CDE98: sw          $zero, -0x538C($at)
    MEM_W(-0X538C, ctx->r1) = 0;
    // 0x801CDE9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDEA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CDEA4: sw          $t6, -0x5388($at)
    MEM_W(-0X5388, ctx->r1) = ctx->r14;
    // 0x801CDEA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDEAC: sw          $zero, -0x5384($at)
    MEM_W(-0X5384, ctx->r1) = 0;
    // 0x801CDEB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDEB4: sw          $zero, -0x53A8($at)
    MEM_W(-0X53A8, ctx->r1) = 0;
    // 0x801CDEB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDEBC: sw          $zero, -0x537C($at)
    MEM_W(-0X537C, ctx->r1) = 0;
    // 0x801CDEC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801CDEC4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801CDEC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDECC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CDED0: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x801CDED4: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801CDED8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CDEDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CDEE0: sw          $zero, -0x5378($at)
    MEM_W(-0X5378, ctx->r1) = 0;
    // 0x801CDEE4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801CDEE8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801CDEEC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801CDEF0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CDEF4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CDEF8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801CDEFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801CDF00: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801CDF04: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CDF08: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801CDF0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CDF10: jal         0x801CC654
    // 0x801CDF14: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x801CC654)(rdram, ctx);
        goto after_0;
    // 0x801CDF14: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_0:
    // 0x801CDF18: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801CDF1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CDF20: addiu       $t2, $t2, -0x20B0
    ctx->r10 = ADD32(ctx->r10, -0X20B0);
    // 0x801CDF24: sw          $v0, -0x5374($at)
    MEM_W(-0X5374, ctx->r1) = ctx->r2;
    // 0x801CDF28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801CDF2C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CDF30: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x801CDF34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CDF38: jal         0x8013B570
    // 0x801CDF3C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_1;
    // 0x801CDF3C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801CDF40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801CDF44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801CDF48: jr          $ra
    // 0x801CDF4C: nop

    return;
    // 0x801CDF4C: nop

;}
RECOMP_FUNC void M24_FUN_801cdf50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CDF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CDF58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CDF5C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CDF60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CDF64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDF68: beq         $t6, $zero, L_801CDF94
    if (ctx->r14 == 0) {
        // 0x801CDF6C: nop
    
            goto L_801CDF94;
    }
    // 0x801CDF6C: nop

    // 0x801CDF70: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801CDF74: jal         0x8012D844
    // 0x801CDF78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801CDF78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CDF7C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDF80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CDF84: jal         0x800058DC
    // 0x801CDF88: addiu       $a1, $a1, -0x2054
    ctx->r5 = ADD32(ctx->r5, -0X2054);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CDF88: addiu       $a1, $a1, -0x2054
    ctx->r5 = ADD32(ctx->r5, -0X2054);
    after_1:
    // 0x801CDF8C: b           L_801CDFA0
    // 0x801CDF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CDFA0;
    // 0x801CDF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CDF94:
    // 0x801CDF94: jal         0x800058DC
    // 0x801CDF98: addiu       $a1, $a1, -0x20B0
    ctx->r5 = ADD32(ctx->r5, -0X20B0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CDF98: addiu       $a1, $a1, -0x20B0
    ctx->r5 = ADD32(ctx->r5, -0X20B0);
    after_2:
    // 0x801CDF9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CDFA0:
    // 0x801CDFA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CDFA4: jr          $ra
    // 0x801CDFA8: nop

    return;
    // 0x801CDFA8: nop

;}
RECOMP_FUNC void M24_FUN_801cdfac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDFAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CDFB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CDFB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801CDFB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CDFBC: jal         0x801CC540
    // 0x801CDFC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801CDFC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CDFC4: beq         $v0, $zero, L_801CDFE4
    if (ctx->r2 == 0) {
        // 0x801CDFC8: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801CDFE4;
    }
    // 0x801CDFC8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDFCC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CDFD0: addiu       $a1, $a1, -0x2054
    ctx->r5 = ADD32(ctx->r5, -0X2054);
    // 0x801CDFD4: jal         0x800058DC
    // 0x801CDFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CDFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CDFDC: b           L_801CE264
    // 0x801CDFE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801CE264;
    // 0x801CDFE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CDFE4:
    // 0x801CDFE4: lw          $t6, -0x5390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5390);
    // 0x801CDFE8: beq         $t6, $zero, L_801CE03C
    if (ctx->r14 == 0) {
        // 0x801CDFEC: nop
    
            goto L_801CE03C;
    }
    // 0x801CDFEC: nop

    // 0x801CDFF0: jal         0x80006214
    // 0x801CDFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801CDFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801CDFF8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CDFFC: lw          $t7, -0x5390($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5390);
    // 0x801CE000: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801CE004: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801CE008: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801CE00C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801CE010: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801CE014: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CE018: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CE01C: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801CE020: jal         0x8013A28C
    // 0x801CE024: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801CE024: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801CE028: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801CE02C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CE030: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE034: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801CE038: sw          $zero, -0x5390($at)
    MEM_W(-0X5390, ctx->r1) = 0;
L_801CE03C:
    // 0x801CE03C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE040: lw          $v0, -0x538C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X538C);
    // 0x801CE044: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE048: beq         $v0, $zero, L_801CE114
    if (ctx->r2 == 0) {
        // 0x801CE04C: nop
    
            goto L_801CE114;
    }
    // 0x801CE04C: nop

    // 0x801CE050: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801CE054: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801CE058: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CE05C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801CE060: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801CE064: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CE068: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CE06C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801CE070: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801CE074: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE078: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CE07C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CE080: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CE084: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CE088: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CE08C: nop

    // 0x801CE090: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CE094: beql        $t4, $zero, L_801CE0E4
    if (ctx->r12 == 0) {
        // 0x801CE098: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801CE0E4;
    }
    goto skip_0;
    // 0x801CE098: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801CE09C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CE0A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CE0A4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CE0A8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CE0AC: nop

    // 0x801CE0B0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CE0B4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CE0B8: nop

    // 0x801CE0BC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CE0C0: bne         $t4, $zero, L_801CE0D8
    if (ctx->r12 != 0) {
        // 0x801CE0C4: nop
    
            goto L_801CE0D8;
    }
    // 0x801CE0C4: nop

    // 0x801CE0C8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801CE0CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CE0D0: b           L_801CE0F0
    // 0x801CE0D4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801CE0F0;
    // 0x801CE0D4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801CE0D8:
    // 0x801CE0D8: b           L_801CE0F0
    // 0x801CE0DC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801CE0F0;
    // 0x801CE0DC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CE0E0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801CE0E4:
    // 0x801CE0E4: nop

    // 0x801CE0E8: bltz        $t4, L_801CE0D8
    if (SIGNED(ctx->r12) < 0) {
        // 0x801CE0EC: nop
    
            goto L_801CE0D8;
    }
    // 0x801CE0EC: nop

L_801CE0F0:
    // 0x801CE0F0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CE0F4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801CE0F8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801CE0FC: jal         0x80011140
    // 0x801CE100: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801CE100: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801CE104: beq         $v0, $zero, L_801CE1C0
    if (ctx->r2 == 0) {
        // 0x801CE108: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CE1C0;
    }
    // 0x801CE108: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE10C: b           L_801CE1C0
    // 0x801CE110: sw          $zero, -0x538C($at)
    MEM_W(-0X538C, ctx->r1) = 0;
        goto L_801CE1C0;
    // 0x801CE110: sw          $zero, -0x538C($at)
    MEM_W(-0X538C, ctx->r1) = 0;
L_801CE114:
    // 0x801CE114: jal         0x80010550
    // 0x801CE118: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801CE118: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801CE11C: beq         $v0, $zero, L_801CE134
    if (ctx->r2 == 0) {
        // 0x801CE120: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CE134;
    }
    // 0x801CE120: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE124: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CE128: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE12C: b           L_801CE138
    // 0x801CE130: sw          $t5, -0x5388($at)
    MEM_W(-0X5388, ctx->r1) = ctx->r13;
        goto L_801CE138;
    // 0x801CE130: sw          $t5, -0x5388($at)
    MEM_W(-0X5388, ctx->r1) = ctx->r13;
L_801CE134:
    // 0x801CE134: sw          $zero, -0x5388($at)
    MEM_W(-0X5388, ctx->r1) = 0;
L_801CE138:
    // 0x801CE138: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE13C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CE140: addiu       $t6, $t6, 0x11B0
    ctx->r14 = ADD32(ctx->r14, 0X11B0);
    // 0x801CE144: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801CE148: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801CE14C: addiu       $t2, $t2, -0x3FD8
    ctx->r10 = ADD32(ctx->r10, -0X3FD8);
    // 0x801CE150: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE154: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CE158: addiu       $t1, $t1, 0x11A0
    ctx->r9 = ADD32(ctx->r9, 0X11A0);
    // 0x801CE15C: lw          $t0, 0x5C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X5C);
    // 0x801CE160: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE164: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE168: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x801CE16C: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x801CE170: addiu       $a0, $a0, 0x11C0
    ctx->r4 = ADD32(ctx->r4, 0X11C0);
    // 0x801CE174: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x801CE178: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x801CE17C: lw          $t0, 0x64($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X64);
    // 0x801CE180: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x801CE184: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801CE188: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801CE18C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801CE190: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801CE194: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x801CE198: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x801CE19C: sw          $a1, -0x53AC($at)
    MEM_W(-0X53AC, ctx->r1) = ctx->r5;
    // 0x801CE1A0: jal         0x8013A334
    // 0x801CE1A4: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_6;
    // 0x801CE1A4: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    after_6:
    // 0x801CE1A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE1AC: addiu       $a0, $a0, 0x11D0
    ctx->r4 = ADD32(ctx->r4, 0X11D0);
    // 0x801CE1B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE1B4: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    // 0x801CE1B8: jal         0x8013A334
    // 0x801CE1BC: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_7;
    // 0x801CE1BC: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_7:
L_801CE1C0:
    // 0x801CE1C0: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801CE1C4: lw          $t5, -0x5384($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5384);
    // 0x801CE1C8: beq         $t5, $zero, L_801CE1D8
    if (ctx->r13 == 0) {
        // 0x801CE1CC: nop
    
            goto L_801CE1D8;
    }
    // 0x801CE1CC: nop

    // 0x801CE1D0: jal         0x801CE5A8
    // 0x801CE1D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CE5A8)(rdram, ctx);
        goto after_8;
    // 0x801CE1D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_801CE1D8:
    // 0x801CE1D8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CE1DC: lw          $t7, -0x53A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X53A8);
    // 0x801CE1E0: beq         $t7, $zero, L_801CE1F0
    if (ctx->r15 == 0) {
        // 0x801CE1E4: nop
    
            goto L_801CE1F0;
    }
    // 0x801CE1E4: nop

    // 0x801CE1E8: jal         0x801CE5D8
    // 0x801CE1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CE5D8)(rdram, ctx);
        goto after_9;
    // 0x801CE1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_801CE1F0:
    // 0x801CE1F0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CE1F4: lw          $t6, -0x5378($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5378);
    // 0x801CE1F8: beql        $t6, $zero, L_801CE264
    if (ctx->r14 == 0) {
        // 0x801CE1FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801CE264;
    }
    goto skip_1;
    // 0x801CE1FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801CE200: jal         0x80006214
    // 0x801CE204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x801CE204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801CE208: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801CE20C: addiu       $v1, $v1, 0x1CF0
    ctx->r3 = ADD32(ctx->r3, 0X1CF0);
    // 0x801CE210: lw          $t8, 0xD8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XD8);
    // 0x801CE214: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801CE218: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801CE21C: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x801CE220: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801CE224: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CE228: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CE22C: sw          $t0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r8;
    // 0x801CE230: lw          $t3, 0xD8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XD8);
    // 0x801CE234: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x801CE238: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801CE23C: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE240: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x801CE244: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x801CE248: lw          $t8, 0xD8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XD8);
    // 0x801CE24C: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x801CE250: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CE254: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801CE258: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x801CE25C: sh          $t1, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r9;
    // 0x801CE260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CE264:
    // 0x801CE264: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801CE268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CE26C: jr          $ra
    // 0x801CE270: nop

    return;
    // 0x801CE270: nop

;}
RECOMP_FUNC void M24_FUN_801ce274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE274: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE278: lw          $v0, -0x538C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X538C);
    // 0x801CE27C: jr          $ra
    // 0x801CE280: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801CE280: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce284(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE284: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CE288: lw          $t6, -0x538C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X538C);
    // 0x801CE28C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CE290: beq         $t6, $zero, L_801CE2A0
    if (ctx->r14 == 0) {
            // 0x801CE294: nop

    LOOKUP_FUNC(0x801CE2A0)(rdram, ctx);
    return;
    }
    // 0x801CE294: nop

    // 0x801CE298: jr          $ra
    // 0x801CE29C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CE29C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce2a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce2a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE2A0: lw          $t7, -0x5390($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5390);
    // 0x801CE2A4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE2A8: beq         $t7, $zero, L_801CE2B8
    if (ctx->r15 == 0) {
            // 0x801CE2AC: nop

    LOOKUP_FUNC(0x801CE2B8)(rdram, ctx);
    return;
    }
    // 0x801CE2AC: nop

    // 0x801CE2B0: jr          $ra
    // 0x801CE2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CE2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce2b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce2b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE2B8: lw          $v0, -0x5388($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5388);
    // 0x801CE2BC: jr          $ra
    // 0x801CE2C0: nop

    return;
    // 0x801CE2C0: nop

;}
RECOMP_FUNC void M24_FUN_801ce2c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE2C4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE2C8: jr          $ra
    // 0x801CE2CC: addiu       $v0, $v0, 0x11A0
    ctx->r2 = ADD32(ctx->r2, 0X11A0);
    return;
    // 0x801CE2CC: addiu       $v0, $v0, 0x11A0
    ctx->r2 = ADD32(ctx->r2, 0X11A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce2d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce2d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE2D0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CE2D4: addiu       $v1, $v1, 0x11B0
    ctx->r3 = ADD32(ctx->r3, 0X11B0);
    // 0x801CE2D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CE2DC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CE2E0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801CE2E4: beql        $a0, $t6, L_801CE2F8
    if (ctx->r4 == ctx->r14) {
        // 0x801CE2E8: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801CE2F8;
    }
    goto skip_0;
    // 0x801CE2E8: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801CE2EC: jr          $ra
    // 0x801CE2F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CE2F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CE2F4: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801CE2F8:
    // 0x801CE2F8: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801CE2FC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CE300: jr          $ra
    // 0x801CE304: nop

    return;
    // 0x801CE304: nop

;}
RECOMP_FUNC void M24_FUN_801ce308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE308: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CE30C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CE310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CE314: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801CE318: beq         $a0, $zero, L_801CE36C
    if (ctx->r4 == 0) {
        // 0x801CE31C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801CE36C;
    }
    // 0x801CE31C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801CE320: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE324: jal         0x80006214
    // 0x801CE328: lw          $a0, -0x53B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CE328: lw          $a0, -0x53B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B0);
    after_0:
    // 0x801CE32C: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801CE330: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801CE334: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE338: lw          $a0, -0x53B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B0);
    // 0x801CE33C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CE340: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801CE344: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801CE348: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801CE34C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CE350: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CE354: jal         0x801C3370
    // 0x801CE358: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801CE358: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_1:
    // 0x801CE35C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CE360: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE364: b           L_801CE374
    // 0x801CE368: sw          $t8, -0x5384($at)
    MEM_W(-0X5384, ctx->r1) = ctx->r24;
        goto L_801CE374;
    // 0x801CE368: sw          $t8, -0x5384($at)
    MEM_W(-0X5384, ctx->r1) = ctx->r24;
L_801CE36C:
    // 0x801CE36C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE370: sw          $zero, -0x5384($at)
    MEM_W(-0X5384, ctx->r1) = 0;
L_801CE374:
    // 0x801CE374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CE378: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CE37C: jr          $ra
    // 0x801CE380: nop

    return;
    // 0x801CE380: nop

;}
RECOMP_FUNC void M24_FUN_801ce384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE384: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE388: lw          $v0, -0x5384($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5384);
    // 0x801CE38C: jr          $ra
    // 0x801CE390: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801CE390: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce394(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE394: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE398: jr          $ra
    // 0x801CE39C: lw          $v0, -0x53B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53B0);
    return;
    // 0x801CE39C: lw          $v0, -0x53B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce3a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce3a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3A0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE3A4: jr          $ra
    // 0x801CE3A8: lw          $v0, -0x53AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53AC);
    return;
    // 0x801CE3A8: lw          $v0, -0x53AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce3ac(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce3ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3AC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE3B0: jr          $ra
    // 0x801CE3B4: addiu       $v0, $v0, 0x11C0
    ctx->r2 = ADD32(ctx->r2, 0X11C0);
    return;
    // 0x801CE3B4: addiu       $v0, $v0, 0x11C0
    ctx->r2 = ADD32(ctx->r2, 0X11C0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce3b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce3b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3B8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE3BC: jr          $ra
    // 0x801CE3C0: addiu       $v0, $v0, 0x11D0
    ctx->r2 = ADD32(ctx->r2, 0X11D0);
    return;
    // 0x801CE3C0: addiu       $v0, $v0, 0x11D0
    ctx->r2 = ADD32(ctx->r2, 0X11D0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce3c4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce3c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE3C8: jr          $ra
    // 0x801CE3CC: sw          $a0, -0x537C($at)
    MEM_W(-0X537C, ctx->r1) = ctx->r4;
    return;
    // 0x801CE3CC: sw          $a0, -0x537C($at)
    MEM_W(-0X537C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce3d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce3d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3D0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CE3D4: addiu       $v0, $v0, -0x53A8
    ctx->r2 = ADD32(ctx->r2, -0X53A8);
    // 0x801CE3D8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801CE3DC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CE3E0: lw          $t6, -0x537C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X537C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce3e4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce3e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE3EC: beql        $t6, $zero, L_801CE43C
    if (ctx->r14 == 0) {
        // 0x801CE3F0: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801CE43C;
    }
    goto skip_0;
    // 0x801CE3F0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801CE3F4: beq         $a0, $zero, L_801CE420
    if (ctx->r4 == 0) {
        // 0x801CE3F8: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_801CE420;
    }
    // 0x801CE3F8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801CE3FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE400: jal         0x801C0B2C
    // 0x801CE404: sw          $zero, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CE404: sw          $zero, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = 0;
    after_0:
    // 0x801CE408: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE40C: sw          $v0, 0x11E0($at)
    MEM_W(0X11E0, ctx->r1) = ctx->r2;
    // 0x801CE410: sw          $v1, 0x11E4($at)
    MEM_W(0X11E4, ctx->r1) = ctx->r3;
    // 0x801CE414: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE418: b           L_801CE478
    // 0x801CE41C: sw          $zero, 0x11E8($at)
    MEM_W(0X11E8, ctx->r1) = 0;
        goto L_801CE478;
    // 0x801CE41C: sw          $zero, 0x11E8($at)
    MEM_W(0X11E8, ctx->r1) = 0;
L_801CE420:
    // 0x801CE420: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE424: lw          $a0, -0x53B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B0);
    // 0x801CE428: jal         0x8012D844
    // 0x801CE42C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801CE42C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x801CE430: b           L_801CE47C
    // 0x801CE434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CE47C;
    // 0x801CE434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE438: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801CE43C:
    // 0x801CE43C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE440: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801CE444: beq         $t8, $zero, L_801CE470
    if (ctx->r24 == 0) {
        // 0x801CE448: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801CE470;
    }
    // 0x801CE448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CE44C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE450: jal         0x801C0B2C
    // 0x801CE454: sw          $zero, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801CE454: sw          $zero, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = 0;
    after_2:
    // 0x801CE458: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE45C: sw          $v0, 0x11E0($at)
    MEM_W(0X11E0, ctx->r1) = ctx->r2;
    // 0x801CE460: sw          $v1, 0x11E4($at)
    MEM_W(0X11E4, ctx->r1) = ctx->r3;
    // 0x801CE464: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE468: b           L_801CE478
    // 0x801CE46C: sw          $zero, 0x11E8($at)
    MEM_W(0X11E8, ctx->r1) = 0;
        goto L_801CE478;
    // 0x801CE46C: sw          $zero, 0x11E8($at)
    MEM_W(0X11E8, ctx->r1) = 0;
L_801CE470:
    // 0x801CE470: jal         0x8012D844
    // 0x801CE474: lw          $a0, -0x53B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B0);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801CE474: lw          $a0, -0x53B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53B0);
    after_3:
L_801CE478:
    // 0x801CE478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CE47C:
    // 0x801CE47C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CE480: jr          $ra
    // 0x801CE484: nop

    return;
    // 0x801CE484: nop

;}
RECOMP_FUNC void M24_FUN_801ce488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE488: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE48C: jr          $ra
    // 0x801CE490: sw          $a0, -0x5378($at)
    MEM_W(-0X5378, ctx->r1) = ctx->r4;
    return;
    // 0x801CE490: sw          $a0, -0x5378($at)
    MEM_W(-0X5378, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce494(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE494: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CE498: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CE49C: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CE4A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CE4A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CE4A8: addiu       $s1, $s1, -0x53B0
    ctx->r17 = ADD32(ctx->r17, -0X53B0);
    // 0x801CE4AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CE4B0: jal         0x80006214
    // 0x801CE4B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CE4B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x801CE4B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801CE4BC: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CE4C0: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801CE4C4: lw          $t0, 0x5C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X5C);
    // 0x801CE4C8: addiu       $ra, $ra, -0x6D40
    ctx->r31 = ADD32(ctx->r31, -0X6D40);
    // 0x801CE4CC: addiu       $s1, $s1, -0x6D98
    ctx->r17 = ADD32(ctx->r17, -0X6D98);
    // 0x801CE4D0: lhu         $v1, 0xC($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0XC);
    // 0x801CE4D4: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x801CE4D8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801CE4DC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x801CE4E0: bne         $at, $zero, L_801CE594
    if (ctx->r1 != 0) {
        // 0x801CE4E4: addiu       $a3, $v0, 0x4
        ctx->r7 = ADD32(ctx->r2, 0X4);
            goto L_801CE594;
    }
    // 0x801CE4E4: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x801CE4E8: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801CE4EC: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801CE4F0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x801CE4F4: addiu       $t2, $t2, -0x2578
    ctx->r10 = ADD32(ctx->r10, -0X2578);
    // 0x801CE4F8: addiu       $t3, $t3, -0x6E48
    ctx->r11 = ADD32(ctx->r11, -0X6E48);
    // 0x801CE4FC: addiu       $t5, $t5, -0x6EA0
    ctx->r13 = ADD32(ctx->r13, -0X6EA0);
    // 0x801CE500: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801CE504: addiu       $t1, $zero, 0x15
    ctx->r9 = ADD32(0, 0X15);
    // 0x801CE508: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
L_801CE50C:
    // 0x801CE50C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x801CE510: addu        $a1, $t2, $a0
    ctx->r5 = ADD32(ctx->r10, ctx->r4);
    // 0x801CE514: bgezl       $t7, L_801CE528
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CE518: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_801CE528;
    }
    goto skip_0;
    // 0x801CE518: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x801CE51C: b           L_801CE584
    // 0x801CE520: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
        goto L_801CE584;
    // 0x801CE520: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801CE524: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_801CE528:
    // 0x801CE528: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801CE52C: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x801CE530: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x801CE534: bne         $t1, $t6, L_801CE558
    if (ctx->r9 != ctx->r14) {
        // 0x801CE538: nop
    
            goto L_801CE558;
    }
    // 0x801CE538: nop

    // 0x801CE53C: beq         $s0, $zero, L_801CE550
    if (ctx->r16 == 0) {
        // 0x801CE540: or          $t8, $t5, $a2
        ctx->r24 = ctx->r13 | ctx->r6;
            goto L_801CE550;
    }
    // 0x801CE540: or          $t8, $t5, $a2
    ctx->r24 = ctx->r13 | ctx->r6;
    // 0x801CE544: or          $t7, $t3, $a2
    ctx->r15 = ctx->r11 | ctx->r6;
    // 0x801CE548: b           L_801CE570
    // 0x801CE54C: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
        goto L_801CE570;
    // 0x801CE54C: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
L_801CE550:
    // 0x801CE550: b           L_801CE570
    // 0x801CE554: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
        goto L_801CE570;
    // 0x801CE554: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
L_801CE558:
    // 0x801CE558: beq         $s0, $zero, L_801CE56C
    if (ctx->r16 == 0) {
        // 0x801CE55C: or          $t6, $s1, $a2
        ctx->r14 = ctx->r17 | ctx->r6;
            goto L_801CE56C;
    }
    // 0x801CE55C: or          $t6, $s1, $a2
    ctx->r14 = ctx->r17 | ctx->r6;
    // 0x801CE560: or          $t9, $ra, $a2
    ctx->r25 = ctx->r31 | ctx->r6;
    // 0x801CE564: b           L_801CE570
    // 0x801CE568: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_801CE570;
    // 0x801CE568: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_801CE56C:
    // 0x801CE56C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_801CE570:
    // 0x801CE570: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801CE574: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE578: sb          $t4, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r12;
    // 0x801CE57C: lhu         $v1, 0xC($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0XC);
    // 0x801CE580: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_801CE584:
    // 0x801CE584: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801CE588: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CE58C: bne         $at, $zero, L_801CE50C
    if (ctx->r1 != 0) {
        // 0x801CE590: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_801CE50C;
    }
    // 0x801CE590: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_801CE594:
    // 0x801CE594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE598: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CE59C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CE5A0: jr          $ra
    // 0x801CE5A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CE5A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce5a8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce5a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE5A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE5B0: jal         0x80006214
    // 0x801CE5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CE5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CE5B8: jal         0x801C354C
    // 0x801CE5BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801CE5BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801CE5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CE5C4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CE5C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE5CC: sw          $t6, -0x5384($at)
    MEM_W(-0X5384, ctx->r1) = ctx->r14;
    // 0x801CE5D0: jr          $ra
    // 0x801CE5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801CE5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce5d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce5d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE5D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CE5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE5E0: jal         0x801C0B2C
    // 0x801CE5E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CE5E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CE5E8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CE5EC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CE5F0: lw          $t7, 0x11E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11E4);
    // 0x801CE5F4: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // 0x801CE5F8: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801CE5FC: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801CE600: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801CE604: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801CE608: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CE60C: jal         0x80034C24
    // 0x801CE610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801CE610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801CE614: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE618: ldc1        $f4, -0x2BD0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2BD0);
    // 0x801CE61C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CE620: addiu       $t0, $t0, 0x11E8
    ctx->r8 = ADD32(ctx->r8, 0X11E8);
    // 0x801CE624: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801CE628: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801CE62C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801CE630: addiu       $t2, $t2, -0x5370
    ctx->r10 = ADD32(ctx->r10, -0X5370);
    // 0x801CE634: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x801CE638: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x801CE63C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801CE640: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801CE644: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CE648: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801CE64C: nop

    // 0x801CE650: bc1fl       L_801CE750
    if (!c1cs) {
        // 0x801CE654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CE750;
    }
    goto skip_0;
    // 0x801CE654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CE658: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x801CE65C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CE660: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801CE664: beq         $v1, $zero, L_801CE67C
    if (ctx->r3 == 0) {
        // 0x801CE668: nop
    
            goto L_801CE67C;
    }
    // 0x801CE668: nop

    // 0x801CE66C: beq         $v1, $at, L_801CE6C0
    if (ctx->r3 == ctx->r1) {
        // 0x801CE670: lui         $t4, 0x801E
        ctx->r12 = S32(0X801E << 16);
            goto L_801CE6C0;
    }
    // 0x801CE670: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801CE674: b           L_801CE704
    // 0x801CE678: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
        goto L_801CE704;
    // 0x801CE678: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
L_801CE67C:
    // 0x801CE67C: lw          $t3, -0x537C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X537C);
    // 0x801CE680: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801CE684: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CE688: beq         $t3, $zero, L_801CE6A4
    if (ctx->r11 == 0) {
        // 0x801CE68C: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_801CE6A4;
    }
    // 0x801CE68C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801CE690: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CE694: jal         0x8012D844
    // 0x801CE698: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801CE698: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x801CE69C: b           L_801CE6AC
    // 0x801CE6A0: nop

        goto L_801CE6AC;
    // 0x801CE6A0: nop

L_801CE6A4:
    // 0x801CE6A4: jal         0x8012D844
    // 0x801CE6A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801CE6A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_801CE6AC:
    // 0x801CE6AC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE6B0: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CE6B4: addiu       $t0, $t0, 0x11E8
    ctx->r8 = ADD32(ctx->r8, 0X11E8);
    // 0x801CE6B8: b           L_801CE700
    // 0x801CE6BC: lw          $a0, 0x11E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11E8);
        goto L_801CE700;
    // 0x801CE6BC: lw          $a0, 0x11E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11E8);
L_801CE6C0:
    // 0x801CE6C0: lw          $t4, -0x537C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X537C);
    // 0x801CE6C4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x801CE6C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CE6CC: beq         $t4, $zero, L_801CE6E8
    if (ctx->r12 == 0) {
        // 0x801CE6D0: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_801CE6E8;
    }
    // 0x801CE6D0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801CE6D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CE6D8: jal         0x8012D844
    // 0x801CE6DC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801CE6DC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_4:
    // 0x801CE6E0: b           L_801CE6F0
    // 0x801CE6E4: nop

        goto L_801CE6F0;
    // 0x801CE6E4: nop

L_801CE6E8:
    // 0x801CE6E8: jal         0x8012D844
    // 0x801CE6EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_5;
    // 0x801CE6EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
L_801CE6F0:
    // 0x801CE6F0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE6F4: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CE6F8: addiu       $t0, $t0, 0x11E8
    ctx->r8 = ADD32(ctx->r8, 0X11E8);
    // 0x801CE6FC: lw          $a0, 0x11E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11E8);
L_801CE700:
    // 0x801CE700: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
L_801CE704:
    // 0x801CE704: sltiu       $at, $t5, 0xF
    ctx->r1 = ctx->r13 < 0XF ? 1 : 0;
    // 0x801CE708: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x801CE70C: bne         $at, $zero, L_801CE738
    if (ctx->r1 != 0) {
        // 0x801CE710: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_801CE738;
    }
    // 0x801CE710: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x801CE714: jal         0x801C0B2C
    // 0x801CE718: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_6;
    // 0x801CE718: nop

    after_6:
    // 0x801CE71C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE720: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CE724: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CE728: addiu       $t0, $t0, 0x11E8
    ctx->r8 = ADD32(ctx->r8, 0X11E8);
    // 0x801CE72C: lw          $a0, 0x11E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11E8);
    // 0x801CE730: sw          $v0, 0x11E0($at)
    MEM_W(0X11E0, ctx->r1) = ctx->r2;
    // 0x801CE734: sw          $v1, 0x11E4($at)
    MEM_W(0X11E4, ctx->r1) = ctx->r3;
L_801CE738:
    // 0x801CE738: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801CE73C: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801CE740: mfhi        $t6
    ctx->r14 = hi;
    // 0x801CE744: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801CE748: nop

    // 0x801CE74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CE750:
    // 0x801CE750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CE754: jr          $ra
    // 0x801CE758: nop

    return;
    // 0x801CE758: nop

;}
RECOMP_FUNC void M24_FUN_801ce75c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE75C: nop

;}
RECOMP_FUNC void M24_FUN_801ce760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE760: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE764: sw          $a0, 0x11F0($at)
    MEM_W(0X11F0, ctx->r1) = ctx->r4;
    // 0x801CE768: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE76C: sw          $zero, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = 0;
    // 0x801CE770: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE774: sw          $zero, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = 0;
    // 0x801CE778: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE77C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CE780: sw          $t6, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r14;
    // 0x801CE784: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE788: sw          $zero, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ce78c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ce78c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE78C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CE790: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE794: sw          $zero, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = 0;
    // 0x801CE798: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CE79C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CE7A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CE7A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE7A8: addiu       $t7, $t7, -0x182C
    ctx->r15 = ADD32(ctx->r15, -0X182C);
    // 0x801CE7AC: sw          $zero, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = 0;
    // 0x801CE7B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CE7B4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801CE7B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CE7BC: jal         0x8013B570
    // 0x801CE7C0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801CE7C0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801CE7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CE7C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CE7CC: jr          $ra
    // 0x801CE7D0: nop

    return;
    // 0x801CE7D0: nop

;}
RECOMP_FUNC void M24_FUN_801ce7d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE7DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CE7E0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CE7E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CE7E8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CE7EC: beq         $t6, $zero, L_801CE818
    if (ctx->r14 == 0) {
        // 0x801CE7F0: nop
    
            goto L_801CE818;
    }
    // 0x801CE7F0: nop

    // 0x801CE7F4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801CE7F8: jal         0x8012D844
    // 0x801CE7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801CE7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CE800: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CE804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CE808: jal         0x800058DC
    // 0x801CE80C: addiu       $a1, $a1, -0x17D0
    ctx->r5 = ADD32(ctx->r5, -0X17D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CE80C: addiu       $a1, $a1, -0x17D0
    ctx->r5 = ADD32(ctx->r5, -0X17D0);
    after_1:
    // 0x801CE810: b           L_801CE824
    // 0x801CE814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CE824;
    // 0x801CE814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CE818:
    // 0x801CE818: jal         0x800058DC
    // 0x801CE81C: addiu       $a1, $a1, -0x182C
    ctx->r5 = ADD32(ctx->r5, -0X182C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CE81C: addiu       $a1, $a1, -0x182C
    ctx->r5 = ADD32(ctx->r5, -0X182C);
    after_2:
    // 0x801CE820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CE824:
    // 0x801CE824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CE828: jr          $ra
    // 0x801CE82C: nop

    return;
    // 0x801CE82C: nop

;}
RECOMP_FUNC void M24_FUN_801ce830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CE830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CE834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CE838: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CE83C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CE840: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801CE844: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CE848: beq         $t6, $zero, L_801CEA30
    if (ctx->r14 == 0) {
        // 0x801CE84C: nop
    
            goto L_801CEA30;
    }
    // 0x801CE84C: nop

    // 0x801CE850: lw          $t7, -0x52AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52AC);
    // 0x801CE854: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CE858: addiu       $a2, $a2, -0x52C0
    ctx->r6 = ADD32(ctx->r6, -0X52C0);
    // 0x801CE85C: beq         $t7, $zero, L_801CEA04
    if (ctx->r15 == 0) {
        // 0x801CE860: nop
    
            goto L_801CEA04;
    }
    // 0x801CE860: nop

    // 0x801CE864: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    // 0x801CE868: jal         0x80005FAC
    // 0x801CE86C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801CE86C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801CE870: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801CE874: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801CE878: lw          $t9, 0x11A0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X11A0);
    // 0x801CE87C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CE880: addiu       $v1, $v1, -0x52B0
    ctx->r3 = ADD32(ctx->r3, -0X52B0);
    // 0x801CE884: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801CE888: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801CE88C: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801CE890: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801CE894: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801CE898: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801CE89C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CE8A0: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801CE8A4: lw          $t4, 0x11A0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X11A0);
    // 0x801CE8A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CE8AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CE8B0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801CE8B4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE8B8: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801CE8BC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801CE8C0: addiu       $t4, $t4, -0x6018
    ctx->r12 = ADD32(ctx->r12, -0X6018);
    // 0x801CE8C4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801CE8C8: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801CE8CC: lw          $t9, 0x11A0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X11A0);
    // 0x801CE8D0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801CE8D4: lui         $t8, 0x4
    ctx->r24 = S32(0X4 << 16);
    // 0x801CE8D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CE8DC: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801CE8E0: ori         $t8, $t8, 0x300
    ctx->r24 = ctx->r24 | 0X300;
    // 0x801CE8E4: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801CE8E8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801CE8EC: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CE8F0: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801CE8F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CE8F8: addiu       $a2, $a2, -0x52A4
    ctx->r6 = ADD32(ctx->r6, -0X52A4);
    // 0x801CE8FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CE900: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE904: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CE908: sw          $t5, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r13;
    // 0x801CE90C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801CE910: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801CE914: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x801CE918: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801CE91C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CE920: sb          $zero, 0x48($t2)
    MEM_B(0X48, ctx->r10) = 0;
    // 0x801CE924: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801CE928: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801CE92C: sb          $a0, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r4;
    // 0x801CE930: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CE934: lw          $t5, 0x2C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE938: sb          $a0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r4;
    // 0x801CE93C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801CE940: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x801CE944: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801CE948: sb          $a0, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r4;
    // 0x801CE94C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801CE950: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801CE954: sb          $a0, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r4;
    // 0x801CE958: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801CE95C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801CE960: sb          $a0, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r4;
    // 0x801CE964: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801CE968: lw          $t7, 0x2C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X2C);
    // 0x801CE96C: sb          $a0, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r4;
    // 0x801CE970: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801CE974: lw          $t9, 0x2C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X2C);
    // 0x801CE978: sb          $a0, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r4;
    // 0x801CE97C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CE980: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x801CE984: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x801CE988: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801CE98C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801CE990: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801CE994: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801CE998: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801CE99C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801CE9A0: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x801CE9A4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9A8: lw          $t7, 0x2C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X2C);
    // 0x801CE9AC: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x801CE9B0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9B4: lw          $t9, 0x2C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X2C);
    // 0x801CE9B8: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801CE9BC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9C0: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801CE9C4: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801CE9C8: sh          $t6, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r14;
    // 0x801CE9CC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9D0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CE9D4: swc1        $f2, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f2.u32l;
    // 0x801CE9D8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9DC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801CE9E0: swc1        $f2, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f2.u32l;
    // 0x801CE9E4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9E8: lw          $t5, 0x2C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X2C);
    // 0x801CE9EC: swc1        $f2, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f2.u32l;
    // 0x801CE9F0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801CE9F4: lw          $t9, -0x52A8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X52A8);
    // 0x801CE9F8: sb          $t9, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r25;
    // 0x801CE9FC: b           L_801CEA18
    // 0x801CEA00: sw          $zero, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = 0;
        goto L_801CEA18;
    // 0x801CEA00: sw          $zero, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = 0;
L_801CEA04:
    // 0x801CEA04: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CEA08: addiu       $v1, $v1, -0x52B0
    ctx->r3 = ADD32(ctx->r3, -0X52B0);
    // 0x801CEA0C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801CEA10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEA14: sw          $zero, -0x52A8($at)
    MEM_W(-0X52A8, ctx->r1) = 0;
L_801CEA18:
    // 0x801CEA18: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEA1C: addiu       $a1, $a1, -0x15B0
    ctx->r5 = ADD32(ctx->r5, -0X15B0);
    // 0x801CEA20: jal         0x800058DC
    // 0x801CEA24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CEA24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801CEA28: b           L_801CEA44
    // 0x801CEA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CEA44;
    // 0x801CEA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CEA30:
    // 0x801CEA30: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEA34: addiu       $a1, $a1, -0x17D0
    ctx->r5 = ADD32(ctx->r5, -0X17D0);
    // 0x801CEA38: jal         0x800058DC
    // 0x801CEA3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CEA3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801CEA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CEA44:
    // 0x801CEA44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CEA48: jr          $ra
    // 0x801CEA4C: nop

    return;
    // 0x801CEA4C: nop

;}
RECOMP_FUNC void M24_FUN_801cea50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEA50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CEA54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CEA58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CEA5C: jal         0x801CC540
    // 0x801CEA60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801CEA60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CEA64: beq         $v0, $zero, L_801CEA84
    if (ctx->r2 == 0) {
        // 0x801CEA68: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801CEA84;
    }
    // 0x801CEA68: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CEA6C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CEA70: addiu       $a1, $a1, -0x15B0
    ctx->r5 = ADD32(ctx->r5, -0X15B0);
    // 0x801CEA74: jal         0x800058DC
    // 0x801CEA78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CEA78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801CEA7C: b           L_801CED50
    // 0x801CEA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801CED50;
    // 0x801CEA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CEA84:
    // 0x801CEA84: lw          $t6, -0x52D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X52D8);
    // 0x801CEA88: beq         $t6, $zero, L_801CEAE0
    if (ctx->r14 == 0) {
        // 0x801CEA8C: nop
    
            goto L_801CEAE0;
    }
    // 0x801CEA8C: nop

    // 0x801CEA90: jal         0x80006214
    // 0x801CEA94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801CEA94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801CEA98: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CEA9C: lw          $t7, -0x52D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52D8);
    // 0x801CEAA0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801CEAA4: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801CEAA8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801CEAAC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801CEAB0: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801CEAB4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CEAB8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CEABC: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801CEAC0: jal         0x8013A28C
    // 0x801CEAC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801CEAC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801CEAC8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801CEACC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CEAD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEAD4: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801CEAD8: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801CEADC: sw          $zero, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = 0;
L_801CEAE0:
    // 0x801CEAE0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CEAE4: lw          $v0, -0x52D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52D4);
    // 0x801CEAE8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801CEAEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CEAF0: beq         $v0, $zero, L_801CEBBC
    if (ctx->r2 == 0) {
        // 0x801CEAF4: nop
    
            goto L_801CEBBC;
    }
    // 0x801CEAF4: nop

    // 0x801CEAF8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801CEAFC: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801CEB00: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CEB04: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801CEB08: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801CEB0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CEB10: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CEB14: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801CEB18: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801CEB1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801CEB20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CEB24: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CEB28: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CEB2C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CEB30: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CEB34: nop

    // 0x801CEB38: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CEB3C: beql        $t4, $zero, L_801CEB8C
    if (ctx->r12 == 0) {
        // 0x801CEB40: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801CEB8C;
    }
    goto skip_0;
    // 0x801CEB40: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801CEB44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CEB48: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CEB4C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CEB50: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CEB54: nop

    // 0x801CEB58: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CEB5C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CEB60: nop

    // 0x801CEB64: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CEB68: bne         $t4, $zero, L_801CEB80
    if (ctx->r12 != 0) {
        // 0x801CEB6C: nop
    
            goto L_801CEB80;
    }
    // 0x801CEB6C: nop

    // 0x801CEB70: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801CEB74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CEB78: b           L_801CEB98
    // 0x801CEB7C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801CEB98;
    // 0x801CEB7C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801CEB80:
    // 0x801CEB80: b           L_801CEB98
    // 0x801CEB84: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801CEB98;
    // 0x801CEB84: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CEB88: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801CEB8C:
    // 0x801CEB8C: nop

    // 0x801CEB90: bltz        $t4, L_801CEB80
    if (SIGNED(ctx->r12) < 0) {
        // 0x801CEB94: nop
    
            goto L_801CEB80;
    }
    // 0x801CEB94: nop

L_801CEB98:
    // 0x801CEB98: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CEB9C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801CEBA0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801CEBA4: jal         0x80011140
    // 0x801CEBA8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801CEBA8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801CEBAC: beq         $v0, $zero, L_801CEC34
    if (ctx->r2 == 0) {
        // 0x801CEBB0: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CEC34;
    }
    // 0x801CEBB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEBB4: b           L_801CEC34
    // 0x801CEBB8: sw          $zero, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = 0;
        goto L_801CEC34;
    // 0x801CEBB8: sw          $zero, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = 0;
L_801CEBBC:
    // 0x801CEBBC: jal         0x80010550
    // 0x801CEBC0: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801CEBC0: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801CEBC4: beq         $v0, $zero, L_801CEBDC
    if (ctx->r2 == 0) {
        // 0x801CEBC8: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CEBDC;
    }
    // 0x801CEBC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEBCC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CEBD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEBD4: b           L_801CEBE0
    // 0x801CEBD8: sw          $t5, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r13;
        goto L_801CEBE0;
    // 0x801CEBD8: sw          $t5, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r13;
L_801CEBDC:
    // 0x801CEBDC: sw          $zero, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = 0;
L_801CEBE0:
    // 0x801CEBE0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801CEBE4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CEBE8: addiu       $t6, $t6, 0x1208
    ctx->r14 = ADD32(ctx->r14, 0X1208);
    // 0x801CEBEC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801CEBF0: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801CEBF4: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801CEBF8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CEBFC: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801CEC00: addiu       $t2, $t2, 0x11F8
    ctx->r10 = ADD32(ctx->r10, 0X11F8);
    // 0x801CEC04: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801CEC08: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801CEC0C: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801CEC10: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801CEC14: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801CEC18: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801CEC1C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801CEC20: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801CEC24: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801CEC28: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801CEC2C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801CEC30: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801CEC34:
    // 0x801CEC34: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CEC38: lw          $t7, -0x52F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52F0);
    // 0x801CEC3C: beq         $t7, $zero, L_801CEC4C
    if (ctx->r15 == 0) {
        // 0x801CEC40: nop
    
            goto L_801CEC4C;
    }
    // 0x801CEC40: nop

    // 0x801CEC44: jal         0x801CEF20
    // 0x801CEC48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801CEF20)(rdram, ctx);
        goto after_6;
    // 0x801CEC48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_801CEC4C:
    // 0x801CEC4C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CEC50: lw          $t8, -0x52C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X52C8);
    // 0x801CEC54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801CEC58: addiu       $v0, $v0, 0x1CF0
    ctx->r2 = ADD32(ctx->r2, 0X1CF0);
    // 0x801CEC5C: beq         $t8, $zero, L_801CECB0
    if (ctx->r24 == 0) {
        // 0x801CEC60: lui         $v1, 0x8009
        ctx->r3 = S32(0X8009 << 16);
            goto L_801CECB0;
    }
    // 0x801CEC60: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801CEC64: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x801CEC68: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x801CEC6C: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x801CEC70: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801CEC74: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CEC78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CEC7C: sw          $t0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r8;
    // 0x801CEC80: lw          $t3, 0xDC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XDC);
    // 0x801CEC84: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x801CEC88: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801CEC8C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CEC90: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x801CEC94: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x801CEC98: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x801CEC9C: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
    // 0x801CECA0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x801CECA4: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801CECA8: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x801CECAC: sh          $t1, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r9;
L_801CECB0:
    // 0x801CECB0: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801CECB4: lw          $t3, -0x52C4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X52C4);
    // 0x801CECB8: beq         $t3, $zero, L_801CECC8
    if (ctx->r11 == 0) {
        // 0x801CECBC: nop
    
            goto L_801CECC8;
    }
    // 0x801CECBC: nop

    // 0x801CECC0: jal         0x801CF080
    // 0x801CECC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801CF080)(rdram, ctx);
        goto after_7;
    // 0x801CECC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
L_801CECC8:
    // 0x801CECC8: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801CECCC: lw          $t4, -0x52AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X52AC);
    // 0x801CECD0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CECD4: addiu       $v0, $v0, -0x52B0
    ctx->r2 = ADD32(ctx->r2, -0X52B0);
    // 0x801CECD8: beq         $t4, $zero, L_801CED4C
    if (ctx->r12 == 0) {
        // 0x801CECDC: lui         $t7, 0x801E
        ctx->r15 = S32(0X801E << 16);
            goto L_801CED4C;
    }
    // 0x801CECDC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CECE0: lw          $t7, -0x52A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52A8);
    // 0x801CECE4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801CECE8: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CECEC: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CECF0: sb          $t7, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r15;
    // 0x801CECF4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801CECF8: lbu         $t8, -0x52A4($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X52A4);
    // 0x801CECFC: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CED00: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801CED04: sb          $t8, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r24;
    // 0x801CED08: lw          $t0, -0x52A0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X52A0);
    // 0x801CED0C: beql        $t0, $zero, L_801CED34
    if (ctx->r8 == 0) {
        // 0x801CED10: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801CED34;
    }
    goto skip_1;
    // 0x801CED10: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x801CED14: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801CED18: addiu       $t1, $t1, -0x5FD8
    ctx->r9 = ADD32(ctx->r9, -0X5FD8);
    // 0x801CED1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CED20: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801CED24: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x801CED28: b           L_801CED4C
    // 0x801CED2C: sw          $t2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r10;
        goto L_801CED4C;
    // 0x801CED2C: sw          $t2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r10;
    // 0x801CED30: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801CED34:
    // 0x801CED34: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CED38: addiu       $t7, $t7, -0x6018
    ctx->r15 = ADD32(ctx->r15, -0X6018);
    // 0x801CED3C: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x801CED40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CED44: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x801CED48: sw          $t5, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r13;
L_801CED4C:
    // 0x801CED4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CED50:
    // 0x801CED50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CED54: jr          $ra
    // 0x801CED58: nop

    return;
    // 0x801CED58: nop

;}
RECOMP_FUNC void M24_FUN_801ced5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CED5C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CED60: addiu       $v0, $v0, -0x52F0
    ctx->r2 = ADD32(ctx->r2, -0X52F0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ced64(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ced64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CED64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CED68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CED6C: beq         $a0, $zero, L_801CED98
    if (ctx->r4 == 0) {
        // 0x801CED70: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801CED98;
    }
    // 0x801CED70: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801CED74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CED78: jal         0x801C0B2C
    // 0x801CED7C: sw          $zero, -0x52D0($at)
    MEM_W(-0X52D0, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CED7C: sw          $zero, -0x52D0($at)
    MEM_W(-0X52D0, ctx->r1) = 0;
    after_0:
    // 0x801CED80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CED84: sw          $v0, 0x1218($at)
    MEM_W(0X1218, ctx->r1) = ctx->r2;
    // 0x801CED88: sw          $v1, 0x121C($at)
    MEM_W(0X121C, ctx->r1) = ctx->r3;
    // 0x801CED8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CED90: b           L_801CEDAC
    // 0x801CED94: sw          $zero, 0x1220($at)
    MEM_W(0X1220, ctx->r1) = 0;
        goto L_801CEDAC;
    // 0x801CED94: sw          $zero, 0x1220($at)
    MEM_W(0X1220, ctx->r1) = 0;
L_801CED98:
    // 0x801CED98: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CED9C: lw          $a0, 0x11F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11F0);
    // 0x801CEDA0: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801CEDA4: jal         0x8012D844
    // 0x801CEDA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801CEDA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801CEDAC:
    // 0x801CEDAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CEDB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CEDB4: jr          $ra
    // 0x801CEDB8: nop

    return;
    // 0x801CEDB8: nop

;}
RECOMP_FUNC void M24_FUN_801cedbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEDBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEDC0: jr          $ra
    // 0x801CEDC4: sw          $a0, -0x52AC($at)
    MEM_W(-0X52AC, ctx->r1) = ctx->r4;
    return;
    // 0x801CEDC4: sw          $a0, -0x52AC($at)
    MEM_W(-0X52AC, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cedc8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cedc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEDC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEDCC: jr          $ra
    // 0x801CEDD0: sw          $a0, -0x52A8($at)
    MEM_W(-0X52A8, ctx->r1) = ctx->r4;
    return;
    // 0x801CEDD0: sw          $a0, -0x52A8($at)
    MEM_W(-0X52A8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cedd4(rdram, ctx);
;}
