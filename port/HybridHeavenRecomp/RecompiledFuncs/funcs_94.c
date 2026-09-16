#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_8021dea8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021DEA8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021DEAC: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8021DEB0: lw          $v0, 0xDC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021deb4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021deb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021DEB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021DEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021DEBC: beql        $a0, $v0, L_8021DED0
    if (ctx->r4 == ctx->r2) {
        // 0x8021DEC0: lw          $v1, 0xEC($a1)
        ctx->r3 = MEM_W(ctx->r5, 0XEC);
            goto L_8021DED0;
    }
    goto skip_0;
    // 0x8021DEC0: lw          $v1, 0xEC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XEC);
    skip_0:
    // 0x8021DEC4: b           L_8021DED0
    // 0x8021DEC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8021DED0;
    // 0x8021DEC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021DECC: lw          $v1, 0xEC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XEC);
L_8021DED0:
    // 0x8021DED0: lw          $a0, 0x5C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X5C);
    // 0x8021DED4: jal         0x8022560C
    // 0x8021DED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_0;
    // 0x8021DED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8021DEDC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021DEE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021DEE4: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8021DEE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8021DEEC: bne         $v0, $at, L_8021DF00
    if (ctx->r2 != ctx->r1) {
        // 0x8021DEF0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021DF00;
    }
    // 0x8021DEF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021DEF4: lhu         $t6, 0xE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XE);
    // 0x8021DEF8: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x8021DEFC: bne         $t6, $at, L_8021DF64
    if (ctx->r14 != ctx->r1) {
        // 0x8021DF00: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8021DF64;
    }
L_8021DF00:
    // 0x8021DF00: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8021DF04: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF08: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8021DF64;
    }
    // 0x8021DF08: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8021DF0C: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF10: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8021DF64;
    }
    // 0x8021DF10: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8021DF14: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF18: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8021DF64;
    }
    // 0x8021DF18: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8021DF1C: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF20: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8021DF64;
    }
    // 0x8021DF20: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8021DF24: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF28: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8021DF64;
    }
    // 0x8021DF28: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8021DF2C: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF30: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_8021DF64;
    }
    // 0x8021DF30: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8021DF34: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF38: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_8021DF64;
    }
    // 0x8021DF38: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8021DF3C: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF40: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_8021DF64;
    }
    // 0x8021DF40: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8021DF44: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF48: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_8021DF64;
    }
    // 0x8021DF48: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8021DF4C: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF50: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8021DF64;
    }
    // 0x8021DF50: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8021DF54: beq         $v1, $at, L_8021DF64
    if (ctx->r3 == ctx->r1) {
        // 0x8021DF58: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_8021DF64;
    }
    // 0x8021DF58: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8021DF5C: bnel        $v1, $at, L_8021DF98
    if (ctx->r3 != ctx->r1) {
        // 0x8021DF60: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021DF98;
    }
    goto skip_1;
    // 0x8021DF60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_8021DF64:
    // 0x8021DF64: lhu         $t7, 0x20($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X20);
    // 0x8021DF68: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8021DF6C: bne         $at, $zero, L_8021DF94
    if (ctx->r1 != 0) {
        // 0x8021DF70: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8021DF94;
    }
    // 0x8021DF70: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8021DF74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8021DF78: lwc1        $f4, 0xB90($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XB90);
    // 0x8021DF7C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8021DF80: nop

    // 0x8021DF84: bc1fl       L_8021DF98
    if (!c1cs) {
        // 0x8021DF88: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8021DF98;
    }
    goto skip_2;
    // 0x8021DF88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8021DF8C: b           L_8021DF98
    // 0x8021DF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8021DF98;
    // 0x8021DF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8021DF94:
    // 0x8021DF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8021DF98:
    // 0x8021DF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021DF9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021DFA0: jr          $ra
    // 0x8021DFA4: nop

    return;
    // 0x8021DFA4: nop

;}
RECOMP_FUNC void M10_FUN_8021dfa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021DFA8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8021DFAC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021DFB0: lw          $v0, -0x4334($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4334);
    // 0x8021DFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021DFB8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8021DFBC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8021DFC0: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x8021DFC4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8021DFC8: bne         $a0, $v0, L_8021DFDC
    if (ctx->r4 != ctx->r2) {
        // 0x8021DFCC: sw          $t7, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r15;
            goto L_8021DFDC;
    }
    // 0x8021DFCC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8021DFD0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021DFD4: b           L_8021DFE4
    // 0x8021DFD8: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8021DFE4;
    // 0x8021DFD8: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8021DFDC:
    // 0x8021DFDC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021DFE0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8021DFE4:
    // 0x8021DFE4: beq         $t8, $v0, L_8021DFF8
    if (ctx->r24 == ctx->r2) {
        // 0x8021DFE8: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_8021DFF8;
    }
    // 0x8021DFE8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8021DFEC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021DFF0: b           L_8021E000
    // 0x8021DFF4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_8021E000;
    // 0x8021DFF4: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_8021DFF8:
    // 0x8021DFF8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8021DFFC: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_8021E000:
    // 0x8021E000: lw          $t0, 0x68($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X68);
    // 0x8021E004: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x8021E008: lbu         $t1, 0x32($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X32);
    // 0x8021E00C: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x8021E010: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8021E014: andi        $t2, $t1, 0xFF1F
    ctx->r10 = ctx->r9 & 0XFF1F;
    // 0x8021E018: sb          $t2, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r10;
    // 0x8021E01C: lbu         $t3, -0x33DF($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X33DF);
    // 0x8021E020: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021E024: bnel        $t3, $at, L_8021E408
    if (ctx->r11 != ctx->r1) {
        // 0x8021E028: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021E408;
    }
    goto skip_0;
    // 0x8021E028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021E02C: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8021E030: srl         $t4, $v0, 31
    ctx->r12 = S32(U32(ctx->r2) >> 31);
    // 0x8021E034: bnel        $t4, $zero, L_8021E408
    if (ctx->r12 != 0) {
        // 0x8021E038: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021E408;
    }
    goto skip_1;
    // 0x8021E038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8021E03C: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x8021E040: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8021E044: srl         $t6, $t7, 30
    ctx->r14 = S32(U32(ctx->r15) >> 30);
    // 0x8021E048: blez        $t5, L_8021E058
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8021E04C: lw          $a1, 0x4C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X4C);
            goto L_8021E058;
    }
    // 0x8021E04C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8021E050: beql        $t6, $zero, L_8021E06C
    if (ctx->r14 == 0) {
        // 0x8021E054: lhu         $t8, 0x30($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X30);
            goto L_8021E06C;
    }
    goto skip_2;
    // 0x8021E054: lhu         $t8, 0x30($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X30);
    skip_2:
L_8021E058:
    // 0x8021E058: jal         0x802233B0
    // 0x8021E05C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x802233B0)(rdram, ctx);
        goto after_0;
    // 0x8021E05C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8021E060: b           L_8021E408
    // 0x8021E064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021E408;
    // 0x8021E064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E068: lhu         $t8, 0x30($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X30);
L_8021E06C:
    // 0x8021E06C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021E070: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x8021E074: bnel        $t9, $at, L_8021E090
    if (ctx->r25 != ctx->r1) {
        // 0x8021E078: lhu         $t1, 0x4($t0)
        ctx->r9 = MEM_HU(ctx->r8, 0X4);
            goto L_8021E090;
    }
    goto skip_3;
    // 0x8021E078: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    skip_3:
    // 0x8021E07C: jal         0x8022397C
    // 0x8021E080: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8022397C)(rdram, ctx);
        goto after_1;
    // 0x8021E080: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x8021E084: b           L_8021E408
    // 0x8021E088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021E408;
    // 0x8021E088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E08C: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
L_8021E090:
    // 0x8021E090: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8021E094: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8021E098: beql        $t2, $zero, L_8021E0E0
    if (ctx->r10 == 0) {
        // 0x8021E09C: lw          $v0, 0x1C($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X1C);
            goto L_8021E0E0;
    }
    goto skip_4;
    // 0x8021E09C: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
    skip_4:
    // 0x8021E0A0: lbu         $t3, 0x30($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X30);
    // 0x8021E0A4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8021E0A8: bnel        $t4, $zero, L_8021E0E0
    if (ctx->r12 != 0) {
        // 0x8021E0AC: lw          $v0, 0x1C($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X1C);
            goto L_8021E0E0;
    }
    goto skip_5;
    // 0x8021E0AC: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
    skip_5:
    // 0x8021E0B0: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x8021E0B4: slti        $at, $t5, 0x1F
    ctx->r1 = SIGNED(ctx->r13) < 0X1F ? 1 : 0;
    // 0x8021E0B8: bnel        $at, $zero, L_8021E0E0
    if (ctx->r1 != 0) {
        // 0x8021E0BC: lw          $v0, 0x1C($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X1C);
            goto L_8021E0E0;
    }
    goto skip_6;
    // 0x8021E0BC: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
    skip_6:
    // 0x8021E0C0: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8021E0C4: beql        $t7, $zero, L_8021E0E0
    if (ctx->r15 == 0) {
        // 0x8021E0C8: lw          $v0, 0x1C($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X1C);
            goto L_8021E0E0;
    }
    goto skip_7;
    // 0x8021E0C8: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
    skip_7:
    // 0x8021E0CC: jal         0x802237EC
    // 0x8021E0D0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x802237EC)(rdram, ctx);
        goto after_2;
    // 0x8021E0D0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8021E0D4: b           L_8021E408
    // 0x8021E0D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021E408;
    // 0x8021E0D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E0DC: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
L_8021E0E0:
    // 0x8021E0E0: lui         $at, 0x348
    ctx->r1 = S32(0X348 << 16);
    // 0x8021E0E4: ori         $at, $at, 0x10
    ctx->r1 = ctx->r1 | 0X10;
    // 0x8021E0E8: bnel        $v0, $at, L_8021E164
    if (ctx->r2 != ctx->r1) {
        // 0x8021E0EC: lui         $at, 0x410
        ctx->r1 = S32(0X410 << 16);
            goto L_8021E164;
    }
    goto skip_8;
    // 0x8021E0EC: lui         $at, 0x410
    ctx->r1 = S32(0X410 << 16);
    skip_8:
    // 0x8021E0F0: lwc1        $f6, 0x24($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X24);
    // 0x8021E0F4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8021E0F8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8021E0FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8021E100: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8021E104: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8021E108: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x8021E10C: nop

    // 0x8021E110: bc1tl       L_8021E164
    if (c1cs) {
        // 0x8021E114: lui         $at, 0x410
        ctx->r1 = S32(0X410 << 16);
            goto L_8021E164;
    }
    goto skip_9;
    // 0x8021E114: lui         $at, 0x410
    ctx->r1 = S32(0X410 << 16);
    skip_9:
    // 0x8021E118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8021E11C: nop

    // 0x8021E120: swc1        $f10, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f10.u32l;
    // 0x8021E124: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8021E128: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021E12C: lw          $t1, 0x1C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X1C);
    // 0x8021E130: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8021E134: lw          $a2, 0x20($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X20);
    // 0x8021E138: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021E13C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021E140: lw          $a3, 0x24($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X24);
    // 0x8021E144: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021E148: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8021E14C: jal         0x8013A28C
    // 0x8021E150: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x8021E150: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x8021E154: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8021E158: b           L_8021E1DC
    // 0x8021E15C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
        goto L_8021E1DC;
    // 0x8021E15C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021E160: lui         $at, 0x410
    ctx->r1 = S32(0X410 << 16);
L_8021E164:
    // 0x8021E164: ori         $at, $at, 0x2B
    ctx->r1 = ctx->r1 | 0X2B;
    // 0x8021E168: bne         $v0, $at, L_8021E1DC
    if (ctx->r2 != ctx->r1) {
        // 0x8021E16C: lw          $t2, 0x44($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X44);
            goto L_8021E1DC;
    }
    // 0x8021E16C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8021E170: lwc1        $f18, 0x24($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X24);
    // 0x8021E174: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8021E178: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8021E17C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8021E180: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8021E184: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8021E188: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x8021E18C: nop

    // 0x8021E190: bc1tl       L_8021E1E0
    if (c1cs) {
        // 0x8021E194: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8021E1E0;
    }
    goto skip_10;
    // 0x8021E194: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    skip_10:
    // 0x8021E198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8021E19C: nop

    // 0x8021E1A0: swc1        $f4, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f4.u32l;
    // 0x8021E1A4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8021E1A8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021E1AC: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x8021E1B0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8021E1B4: lw          $a2, 0x20($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X20);
    // 0x8021E1B8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021E1BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021E1C0: lw          $a3, 0x24($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X24);
    // 0x8021E1C4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021E1C8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8021E1CC: jal         0x8013A28C
    // 0x8021E1D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_4;
    // 0x8021E1D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_4:
    // 0x8021E1D4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8021E1D8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021E1DC:
    // 0x8021E1DC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_8021E1E0:
    // 0x8021E1E0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8021E1E4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8021E1E8: jal         0x80010550
    // 0x8021E1EC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x8021E1EC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_5:
    // 0x8021E1F0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021E1F4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8021E1F8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8021E1FC: lh          $t7, 0x6($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X6);
    // 0x8021E200: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8021E204: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021E208: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x8021E20C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8021E210: nop

    // 0x8021E214: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8021E218: div.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8021E21C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8021E220: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8021E224: lh          $t8, 0x8($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X8);
    // 0x8021E228: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8021E22C: nop

    // 0x8021E230: cvt.d.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
    // 0x8021E234: div.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8021E238: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8021E23C: jal         0x802242D0
    // 0x8021E240: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x802242D0)(rdram, ctx);
        goto after_6;
    // 0x8021E240: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8021E244: bne         $v0, $zero, L_8021E260
    if (ctx->r2 != 0) {
        // 0x8021E248: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_8021E260;
    }
    // 0x8021E248: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8021E24C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021E250: jal         0x8021DEA8
    // 0x8021E254: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8021DEA8)(rdram, ctx);
        goto after_7;
    // 0x8021E254: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_7:
    // 0x8021E258: beq         $v0, $zero, L_8021E350
    if (ctx->r2 == 0) {
        // 0x8021E25C: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_8021E350;
    }
    // 0x8021E25C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_8021E260:
    // 0x8021E260: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021E264: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8021E268: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x8021E26C: lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X36);
    // 0x8021E270: addiu       $t1, $t1, -0x3D70
    ctx->r9 = ADD32(ctx->r9, -0X3D70);
    // 0x8021E274: beq         $v0, $at, L_8021E29C
    if (ctx->r2 == ctx->r1) {
        // 0x8021E278: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_8021E29C;
    }
    // 0x8021E278: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8021E27C: beq         $v0, $at, L_8021E29C
    if (ctx->r2 == ctx->r1) {
        // 0x8021E280: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_8021E29C;
    }
    // 0x8021E280: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8021E284: beq         $v0, $at, L_8021E29C
    if (ctx->r2 == ctx->r1) {
        // 0x8021E288: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_8021E29C;
    }
    // 0x8021E288: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x8021E28C: beq         $v0, $at, L_8021E29C
    if (ctx->r2 == ctx->r1) {
        // 0x8021E290: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_8021E29C;
    }
    // 0x8021E290: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x8021E294: bne         $v0, $at, L_8021E320
    if (ctx->r2 != ctx->r1) {
        // 0x8021E298: lw          $a1, 0x4C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X4C);
            goto L_8021E320;
    }
    // 0x8021E298: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
L_8021E29C:
    // 0x8021E29C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8021E2A0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8021E2A4: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x8021E2A8: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8021E2AC: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8021E2B0: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x8021E2B4: jal         0x801DFE00
    // 0x8021E2B8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801DFE00)(rdram, ctx);
        goto after_8;
    // 0x8021E2B8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_8:
    // 0x8021E2BC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8021E2C0: beq         $v0, $zero, L_8021E2D0
    if (ctx->r2 == 0) {
        // 0x8021E2C4: lbu         $a3, 0x1F($sp)
        ctx->r7 = MEM_BU(ctx->r29, 0X1F);
            goto L_8021E2D0;
    }
    // 0x8021E2C4: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x8021E2C8: b           L_8021E2D4
    // 0x8021E2CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8021E2D4;
    // 0x8021E2CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8021E2D0:
    // 0x8021E2D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8021E2D4:
    // 0x8021E2D4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8021E2D8: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x8021E2DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021E2E0: lhu         $v0, 0x36($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X36);
    // 0x8021E2E4: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x8021E2E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8021E2EC: beq         $v0, $at, L_8021E2FC
    if (ctx->r2 == ctx->r1) {
        // 0x8021E2F0: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_8021E2FC;
    }
    // 0x8021E2F0: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x8021E2F4: bnel        $v0, $at, L_8021E304
    if (ctx->r2 != ctx->r1) {
        // 0x8021E2F8: sll         $t5, $a3, 2
        ctx->r13 = S32(ctx->r7 << 2);
            goto L_8021E304;
    }
    goto skip_11;
    // 0x8021E2F8: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    skip_11:
L_8021E2FC:
    // 0x8021E2FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8021E300: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
L_8021E304:
    // 0x8021E304: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8021E308: addu        $a1, $sp, $t6
    ctx->r5 = ADD32(ctx->r29, ctx->r14);
    // 0x8021E30C: lhu         $a1, 0x20($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20);
    // 0x8021E310: jal         0x80226710
    // 0x8021E314: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80226710)(rdram, ctx);
        goto after_9;
    // 0x8021E314: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_9:
    // 0x8021E318: b           L_8021E330
    // 0x8021E31C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
        goto L_8021E330;
    // 0x8021E31C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_8021E320:
    // 0x8021E320: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021E324: jal         0x8013B808
    // 0x8021E328: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8013B808)(rdram, ctx);
        goto after_10;
    // 0x8021E328: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_10:
    // 0x8021E32C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_8021E330:
    // 0x8021E330: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021E334: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8021E338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8021E33C: jal         0x80371930
    // 0x8021E340: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80371930)(rdram, ctx);
        goto after_11;
    // 0x8021E340: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_11:
    // 0x8021E344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8021E348: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8021E34C: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
L_8021E350:
    // 0x8021E350: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x8021E354: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021E358: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x8021E35C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8021E360: srl         $t1, $t9, 28
    ctx->r9 = S32(U32(ctx->r25) >> 28);
    // 0x8021E364: beq         $t1, $at, L_8021E3B4
    if (ctx->r9 == ctx->r1) {
        // 0x8021E368: lw          $t2, 0x48($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X48);
            goto L_8021E3B4;
    }
    // 0x8021E368: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8021E36C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8021E370: lw          $t3, -0x4334($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4334);
    // 0x8021E374: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8021E378: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8021E37C: bnel        $t2, $t3, L_8021E3B8
    if (ctx->r10 != ctx->r11) {
        // 0x8021E380: lh          $t4, 0x312($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X312);
            goto L_8021E3B8;
    }
    goto skip_12;
    // 0x8021E380: lh          $t4, 0x312($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X312);
    skip_12:
    // 0x8021E384: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8021E388: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8021E38C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8021E390: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8021E394: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8021E398: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8021E39C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8021E3A0: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8021E3A4: nop

    // 0x8021E3A8: bc1fl       L_8021E3B8
    if (!c1cs) {
        // 0x8021E3AC: lh          $t4, 0x312($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X312);
            goto L_8021E3B8;
    }
    goto skip_13;
    // 0x8021E3AC: lh          $t4, 0x312($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X312);
    skip_13:
    // 0x8021E3B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8021E3B4:
    // 0x8021E3B4: lh          $t4, 0x312($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X312);
L_8021E3B8:
    // 0x8021E3B8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021E3BC: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    // 0x8021E3C0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8021E3C4: sh          $t5, 0x312($v1)
    MEM_H(0X312, ctx->r3) = ctx->r13;
    // 0x8021E3C8: lh          $t7, 0x312($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X312);
    // 0x8021E3CC: bgtz        $t7, L_8021E3D8
    if (SIGNED(ctx->r15) > 0) {
        // 0x8021E3D0: nop
    
            goto L_8021E3D8;
    }
    // 0x8021E3D0: nop

    // 0x8021E3D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8021E3D8:
    // 0x8021E3D8: beql        $v0, $zero, L_8021E408
    if (ctx->r2 == 0) {
        // 0x8021E3DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021E408;
    }
    goto skip_14;
    // 0x8021E3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_14:
    // 0x8021E3E0: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x8021E3E4: lbu         $t9, 0x33($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X33);
    // 0x8021E3E8: sh          $zero, 0x312($v1)
    MEM_H(0X312, ctx->r3) = 0;
    // 0x8021E3EC: andi        $t8, $t6, 0xFFE1
    ctx->r24 = ctx->r14 & 0XFFE1;
    // 0x8021E3F0: andi        $t1, $t9, 0xFF7F
    ctx->r9 = ctx->r25 & 0XFF7F;
    // 0x8021E3F4: sb          $t8, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r24;
    // 0x8021E3F8: sb          $t1, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r9;
    // 0x8021E3FC: jal         0x800058DC
    // 0x8021E400: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8021E400: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_12:
    // 0x8021E404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021E408:
    // 0x8021E408: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8021E40C: jr          $ra
    // 0x8021E410: nop

    return;
    // 0x8021E410: nop

;}
RECOMP_FUNC void M10_FUN_8021e414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021E414: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8021E418: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8021E41C: lw          $t7, -0x4334($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4334);
    // 0x8021E420: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8021E424: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8021E428: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8021E42C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8021E430: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021E434: bne         $a0, $t7, L_8021E448
    if (ctx->r4 != ctx->r15) {
        // 0x8021E438: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_8021E448;
    }
    // 0x8021E438: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8021E43C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021E440: b           L_8021E450
    // 0x8021E444: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8021E450;
    // 0x8021E444: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8021E448:
    // 0x8021E448: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021E44C: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8021E450:
    // 0x8021E450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021E454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8021E458: jal         0x80224AC4
    // 0x8021E45C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80224AC4)(rdram, ctx);
        goto after_0;
    // 0x8021E45C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x8021E460: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8021E464: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8021E468: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8021E46C: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x8021E470: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8021E474: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8021E478: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x8021E47C: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x8021E480: bne         $t0, $zero, L_8021E4A8
    if (ctx->r8 != 0) {
        // 0x8021E484: nop
    
            goto L_8021E4A8;
    }
    // 0x8021E484: nop

    // 0x8021E488: lbu         $t1, 0x2F9($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2F9);
    // 0x8021E48C: lbu         $t6, 0x31($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X31);
    // 0x8021E490: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8021E494: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8021E498: andi        $t5, $t4, 0x60
    ctx->r13 = ctx->r12 & 0X60;
    // 0x8021E49C: andi        $t7, $t6, 0xFF9F
    ctx->r15 = ctx->r14 & 0XFF9F;
    // 0x8021E4A0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8021E4A4: sb          $t8, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r24;
L_8021E4A8:
    // 0x8021E4A8: jal         0x802256E4
    // 0x8021E4AC: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x8021E4AC: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    after_1:
    // 0x8021E4B0: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x8021E4B4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8021E4B8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8021E4BC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8021E4C0: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8021E4C4: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x8021E4C8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8021E4CC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8021E4D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8021E4D4: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8021E4D8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8021E4DC: jal         0x80011140
    // 0x8021E4E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x8021E4E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_2:
    // 0x8021E4E4: beq         $v0, $zero, L_8021E518
    if (ctx->r2 == 0) {
        // 0x8021E4E8: lhu         $t3, 0x36($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X36);
            goto L_8021E518;
    }
    // 0x8021E4E8: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    // 0x8021E4EC: bne         $t3, $zero, L_8021E50C
    if (ctx->r11 != 0) {
        // 0x8021E4F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8021E50C;
    }
    // 0x8021E4F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021E4F4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021E4F8: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    // 0x8021E4FC: jal         0x800058DC
    // 0x8021E500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021E500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8021E504: b           L_8021E51C
    // 0x8021E508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8021E51C;
    // 0x8021E508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8021E50C:
    // 0x8021E50C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021E510: jal         0x800058DC
    // 0x8021E514: addiu       $a1, $a1, -0x1AD4
    ctx->r5 = ADD32(ctx->r5, -0X1AD4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8021E514: addiu       $a1, $a1, -0x1AD4
    ctx->r5 = ADD32(ctx->r5, -0X1AD4);
    after_4:
L_8021E518:
    // 0x8021E518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8021E51C:
    // 0x8021E51C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8021E520: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8021E524: jr          $ra
    // 0x8021E528: nop

    return;
    // 0x8021E528: nop

;}
RECOMP_FUNC void M10_FUN_8021e52c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021E52C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8021E530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021E534: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8021E538: jal         0x80224F5C
    // 0x8021E53C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80224F5C)(rdram, ctx);
        goto after_0;
    // 0x8021E53C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8021E540: bne         $v0, $zero, L_8021E58C
    if (ctx->r2 != 0) {
        // 0x8021E544: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_8021E58C;
    }
    // 0x8021E544: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8021E548: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8021E54C: jal         0x802256E4
    // 0x8021E550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x8021E550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8021E554: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x8021E558: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8021E55C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8021E560: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8021E564: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8021E568: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021E56C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021E570: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8021E574: jal         0x8013A28C
    // 0x8021E578: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x8021E578: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x8021E57C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021E580: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    // 0x8021E584: jal         0x800058DC
    // 0x8021E588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021E588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_8021E58C:
    // 0x8021E58C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E590: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8021E594: jr          $ra
    // 0x8021E598: nop

    return;
    // 0x8021E598: nop

;}
RECOMP_FUNC void M10_FUN_8021e59c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021E59C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8021E5A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021E5A4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8021E5A8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8021E5AC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8021E5B0: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x8021E5B4: lw          $v0, 0xDC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XDC);
    // 0x8021E5B8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8021E5BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8021E5C0: bne         $a0, $v0, L_8021E5D4
    if (ctx->r4 != ctx->r2) {
        // 0x8021E5C4: lw          $t0, 0x68($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X68);
            goto L_8021E5D4;
    }
    // 0x8021E5C4: lw          $t0, 0x68($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X68);
    // 0x8021E5C8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021E5CC: b           L_8021E5DC
    // 0x8021E5D0: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_8021E5DC;
    // 0x8021E5D0: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_8021E5D4:
    // 0x8021E5D4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021E5D8: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_8021E5DC:
    // 0x8021E5DC: bne         $a3, $v0, L_8021E5F0
    if (ctx->r7 != ctx->r2) {
        // 0x8021E5E0: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_8021E5F0;
    }
    // 0x8021E5E0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021E5E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8021E5E8: b           L_8021E5F4
    // 0x8021E5EC: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
        goto L_8021E5F4;
    // 0x8021E5EC: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_8021E5F0:
    // 0x8021E5F0: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_8021E5F4:
    // 0x8021E5F4: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x8021E5F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021E5FC: blez        $t7, L_8021E618
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8021E600: nop
    
            goto L_8021E618;
    }
    // 0x8021E600: nop

    // 0x8021E604: lw          $v1, 0x30($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X30);
    // 0x8021E608: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8021E60C: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8021E610: beql        $t9, $zero, L_8021E62C
    if (ctx->r25 == 0) {
        // 0x8021E614: lbu         $v0, 0x1031($t1)
        ctx->r2 = MEM_BU(ctx->r9, 0X1031);
            goto L_8021E62C;
    }
    goto skip_0;
    // 0x8021E614: lbu         $v0, 0x1031($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1031);
    skip_0:
L_8021E618:
    // 0x8021E618: jal         0x802233B0
    // 0x8021E61C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x802233B0)(rdram, ctx);
        goto after_0;
    // 0x8021E61C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_0:
    // 0x8021E620: b           L_8021EB7C
    // 0x8021E624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021E624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E628: lbu         $v0, 0x1031($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1031);
L_8021E62C:
    // 0x8021E62C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8021E630: bne         $at, $zero, L_8021E650
    if (ctx->r1 != 0) {
        // 0x8021E634: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8021E650;
    }
    // 0x8021E634: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8021E638: beq         $v0, $at, L_8021E650
    if (ctx->r2 == ctx->r1) {
        // 0x8021E63C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8021E650;
    }
    // 0x8021E63C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021E640: jal         0x8022310C
    // 0x8021E644: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8022310C)(rdram, ctx);
        goto after_1;
    // 0x8021E644: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x8021E648: b           L_8021EB7C
    // 0x8021E64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021E64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021E650:
    // 0x8021E650: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021E654: bne         $v0, $at, L_8021EB78
    if (ctx->r2 != ctx->r1) {
        // 0x8021E658: srl         $t2, $v1, 31
        ctx->r10 = S32(U32(ctx->r3) >> 31);
            goto L_8021EB78;
    }
    // 0x8021E658: srl         $t2, $v1, 31
    ctx->r10 = S32(U32(ctx->r3) >> 31);
    // 0x8021E65C: bnel        $t2, $zero, L_8021EB7C
    if (ctx->r10 != 0) {
        // 0x8021E660: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021EB7C;
    }
    goto skip_1;
    // 0x8021E660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8021E664: lh          $t3, 0x6($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X6);
    // 0x8021E668: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8021E66C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8021E670: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8021E674: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8021E678: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8021E67C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021E680: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8021E684: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8021E688: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8021E68C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8021E690: lh          $t5, 0x8($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X8);
    // 0x8021E694: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021E698: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8021E69C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8021E6A0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8021E6A4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8021E6A8: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8021E6AC: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8021E6B0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8021E6B4: jal         0x8022518C
    // 0x8021E6B8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8022518C)(rdram, ctx);
        goto after_2;
    // 0x8021E6B8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8021E6BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8021E6C0: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8021E6C4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8021E6C8: lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XE);
    // 0x8021E6CC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8021E6D0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8021E6D4: bne         $v0, $at, L_8021E70C
    if (ctx->r2 != ctx->r1) {
        // 0x8021E6D8: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8021E70C;
    }
    // 0x8021E6D8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021E6DC: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
    // 0x8021E6E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8021E6E4: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8021E6E8: beql        $t7, $zero, L_8021E6FC
    if (ctx->r15 == 0) {
        // 0x8021E6EC: lbu         $t9, 0x33($a2)
        ctx->r25 = MEM_BU(ctx->r6, 0X33);
            goto L_8021E6FC;
    }
    goto skip_2;
    // 0x8021E6EC: lbu         $t9, 0x33($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X33);
    skip_2:
    // 0x8021E6F0: b           L_8021E760
    // 0x8021E6F4: sb          $t8, 0x390($a2)
    MEM_B(0X390, ctx->r6) = ctx->r24;
        goto L_8021E760;
    // 0x8021E6F4: sb          $t8, 0x390($a2)
    MEM_B(0X390, ctx->r6) = ctx->r24;
    // 0x8021E6F8: lbu         $t9, 0x33($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X33);
L_8021E6FC:
    // 0x8021E6FC: sb          $zero, 0x390($a2)
    MEM_B(0X390, ctx->r6) = 0;
    // 0x8021E700: andi        $t2, $t9, 0xFFE7
    ctx->r10 = ctx->r25 & 0XFFE7;
    // 0x8021E704: b           L_8021E760
    // 0x8021E708: sb          $t2, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r10;
        goto L_8021E760;
    // 0x8021E708: sb          $t2, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r10;
L_8021E70C:
    // 0x8021E70C: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x8021E710: bnel        $v0, $at, L_8021E764
    if (ctx->r2 != ctx->r1) {
        // 0x8021E714: lhu         $t2, 0x4($t0)
        ctx->r10 = MEM_HU(ctx->r8, 0X4);
            goto L_8021E764;
    }
    goto skip_3;
    // 0x8021E714: lhu         $t2, 0x4($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X4);
    skip_3:
    // 0x8021E718: lhu         $t3, 0x2($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X2);
    // 0x8021E71C: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8021E720: beql        $t4, $zero, L_8021E744
    if (ctx->r12 == 0) {
        // 0x8021E724: lbu         $t7, 0x390($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X390);
            goto L_8021E744;
    }
    goto skip_4;
    // 0x8021E724: lbu         $t7, 0x390($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X390);
    skip_4:
    // 0x8021E728: lbu         $t5, 0x390($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X390);
    // 0x8021E72C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8021E730: bnel        $t5, $zero, L_8021E764
    if (ctx->r13 != 0) {
        // 0x8021E734: lhu         $t2, 0x4($t0)
        ctx->r10 = MEM_HU(ctx->r8, 0X4);
            goto L_8021E764;
    }
    goto skip_5;
    // 0x8021E734: lhu         $t2, 0x4($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X4);
    skip_5:
    // 0x8021E738: b           L_8021E760
    // 0x8021E73C: sb          $t6, 0x390($a2)
    MEM_B(0X390, ctx->r6) = ctx->r14;
        goto L_8021E760;
    // 0x8021E73C: sb          $t6, 0x390($a2)
    MEM_B(0X390, ctx->r6) = ctx->r14;
    // 0x8021E740: lbu         $t7, 0x390($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X390);
L_8021E744:
    // 0x8021E744: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021E748: bnel        $t7, $at, L_8021E764
    if (ctx->r15 != ctx->r1) {
        // 0x8021E74C: lhu         $t2, 0x4($t0)
        ctx->r10 = MEM_HU(ctx->r8, 0X4);
            goto L_8021E764;
    }
    goto skip_6;
    // 0x8021E74C: lhu         $t2, 0x4($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X4);
    skip_6:
    // 0x8021E750: lbu         $t8, 0x33($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X33);
    // 0x8021E754: sb          $zero, 0x390($a2)
    MEM_B(0X390, ctx->r6) = 0;
    // 0x8021E758: andi        $t9, $t8, 0xFFE7
    ctx->r25 = ctx->r24 & 0XFFE7;
    // 0x8021E75C: sb          $t9, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r25;
L_8021E760:
    // 0x8021E760: lhu         $t2, 0x4($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X4);
L_8021E764:
    // 0x8021E764: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8021E768: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8021E76C: beql        $t3, $zero, L_8021E860
    if (ctx->r11 == 0) {
        // 0x8021E770: sw          $a1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r5;
            goto L_8021E860;
    }
    goto skip_7;
    // 0x8021E770: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    skip_7:
    // 0x8021E774: lhu         $t4, -0x43E4($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X43E4);
    // 0x8021E778: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8021E77C: bnel        $t4, $at, L_8021E860
    if (ctx->r12 != ctx->r1) {
        // 0x8021E780: sw          $a1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r5;
            goto L_8021E860;
    }
    goto skip_8;
    // 0x8021E780: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    skip_8:
    // 0x8021E784: lhu         $v0, 0x36($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X36);
    // 0x8021E788: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x8021E78C: beq         $v0, $at, L_8021E7A4
    if (ctx->r2 == ctx->r1) {
        // 0x8021E790: addiu       $at, $zero, 0xF9
        ctx->r1 = ADD32(0, 0XF9);
            goto L_8021E7A4;
    }
    // 0x8021E790: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x8021E794: beq         $v0, $at, L_8021E7A4
    if (ctx->r2 == ctx->r1) {
        // 0x8021E798: addiu       $at, $zero, 0xFC
        ctx->r1 = ADD32(0, 0XFC);
            goto L_8021E7A4;
    }
    // 0x8021E798: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x8021E79C: bnel        $v0, $at, L_8021E7EC
    if (ctx->r2 != ctx->r1) {
        // 0x8021E7A0: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_8021E7EC;
    }
    goto skip_9;
    // 0x8021E7A0: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    skip_9:
L_8021E7A4:
    // 0x8021E7A4: lh          $t5, 0x6($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X6);
    // 0x8021E7A8: slti        $at, $t5, 0x46
    ctx->r1 = SIGNED(ctx->r13) < 0X46 ? 1 : 0;
    // 0x8021E7AC: bnel        $at, $zero, L_8021E7EC
    if (ctx->r1 != 0) {
        // 0x8021E7B0: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_8021E7EC;
    }
    goto skip_10;
    // 0x8021E7B0: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    skip_10:
    // 0x8021E7B4: lh          $t6, 0xA($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XA);
    // 0x8021E7B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8021E7BC: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x8021E7C0: bnel        $at, $zero, L_8021E7EC
    if (ctx->r1 != 0) {
        // 0x8021E7C4: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_8021E7EC;
    }
    goto skip_11;
    // 0x8021E7C4: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    skip_11:
    // 0x8021E7C8: lh          $t8, 0x44($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X44);
    // 0x8021E7CC: lh          $t2, 0x42($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X42);
    // 0x8021E7D0: sb          $t7, 0x390($a2)
    MEM_B(0X390, ctx->r6) = ctx->r15;
    // 0x8021E7D4: addiu       $t9, $t8, 0x46
    ctx->r25 = ADD32(ctx->r24, 0X46);
    // 0x8021E7D8: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x8021E7DC: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    // 0x8021E7E0: b           L_8021E85C
    // 0x8021E7E4: sh          $t3, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r11;
        goto L_8021E85C;
    // 0x8021E7E4: sh          $t3, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r11;
    // 0x8021E7E8: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
L_8021E7EC:
    // 0x8021E7EC: beq         $v0, $at, L_8021E7FC
    if (ctx->r2 == ctx->r1) {
        // 0x8021E7F0: addiu       $at, $zero, 0xF1
        ctx->r1 = ADD32(0, 0XF1);
            goto L_8021E7FC;
    }
    // 0x8021E7F0: addiu       $at, $zero, 0xF1
    ctx->r1 = ADD32(0, 0XF1);
    // 0x8021E7F4: bnel        $v0, $at, L_8021E860
    if (ctx->r2 != ctx->r1) {
        // 0x8021E7F8: sw          $a1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r5;
            goto L_8021E860;
    }
    goto skip_12;
    // 0x8021E7F8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    skip_12:
L_8021E7FC:
    // 0x8021E7FC: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
    // 0x8021E800: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021E804: beql        $v0, $zero, L_8021E818
    if (ctx->r2 == 0) {
        // 0x8021E808: lh          $t4, 0x6($a2)
        ctx->r12 = MEM_H(ctx->r6, 0X6);
            goto L_8021E818;
    }
    goto skip_13;
    // 0x8021E808: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    skip_13:
    // 0x8021E80C: bne         $v0, $at, L_8021E858
    if (ctx->r2 != ctx->r1) {
        // 0x8021E810: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8021E858;
    }
    // 0x8021E810: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8021E814: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
L_8021E818:
    // 0x8021E818: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x8021E81C: bnel        $at, $zero, L_8021E860
    if (ctx->r1 != 0) {
        // 0x8021E820: sw          $a1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r5;
            goto L_8021E860;
    }
    goto skip_14;
    // 0x8021E820: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    skip_14:
    // 0x8021E824: lh          $t5, 0xA($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XA);
    // 0x8021E828: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8021E82C: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x8021E830: bnel        $at, $zero, L_8021E860
    if (ctx->r1 != 0) {
        // 0x8021E834: sw          $a1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r5;
            goto L_8021E860;
    }
    goto skip_15;
    // 0x8021E834: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    skip_15:
    // 0x8021E838: sb          $t6, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r14;
    // 0x8021E83C: lh          $t7, 0x44($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X44);
    // 0x8021E840: lh          $t9, 0x42($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X42);
    // 0x8021E844: addiu       $t8, $t7, 0x64
    ctx->r24 = ADD32(ctx->r15, 0X64);
    // 0x8021E848: addiu       $t2, $t9, 0x64
    ctx->r10 = ADD32(ctx->r25, 0X64);
    // 0x8021E84C: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x8021E850: b           L_8021E85C
    // 0x8021E854: sh          $t2, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r10;
        goto L_8021E85C;
    // 0x8021E854: sh          $t2, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r10;
L_8021E858:
    // 0x8021E858: sb          $t3, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r11;
L_8021E85C:
    // 0x8021E85C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
L_8021E860:
    // 0x8021E860: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8021E864: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8021E868: jal         0x8022560C
    // 0x8021E86C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_3;
    // 0x8021E86C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x8021E870: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8021E874: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021E878: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8021E87C: lhu         $t4, 0x30($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X30);
    // 0x8021E880: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8021E884: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021E888: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x8021E88C: bnel        $t5, $at, L_8021E8A8
    if (ctx->r13 != ctx->r1) {
        // 0x8021E890: lbu         $t6, 0x33($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X33);
            goto L_8021E8A8;
    }
    goto skip_16;
    // 0x8021E890: lbu         $t6, 0x33($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X33);
    skip_16:
    // 0x8021E894: jal         0x8022397C
    // 0x8021E898: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8022397C)(rdram, ctx);
        goto after_4;
    // 0x8021E898: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x8021E89C: b           L_8021EB7C
    // 0x8021E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E8A4: lbu         $t6, 0x33($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X33);
L_8021E8A8:
    // 0x8021E8A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021E8AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021E8B0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8021E8B4: bnel        $t7, $at, L_8021E8D8
    if (ctx->r15 != ctx->r1) {
        // 0x8021E8B8: lhu         $a0, 0x4($t0)
        ctx->r4 = MEM_HU(ctx->r8, 0X4);
            goto L_8021E8D8;
    }
    goto skip_17;
    // 0x8021E8B8: lhu         $a0, 0x4($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4);
    skip_17:
    // 0x8021E8BC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021E8C0: sb          $zero, 0x328($a2)
    MEM_B(0X328, ctx->r6) = 0;
    // 0x8021E8C4: jal         0x800058DC
    // 0x8021E8C8: addiu       $a1, $a1, -0x2058
    ctx->r5 = ADD32(ctx->r5, -0X2058);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8021E8C8: addiu       $a1, $a1, -0x2058
    ctx->r5 = ADD32(ctx->r5, -0X2058);
    after_5:
    // 0x8021E8CC: b           L_8021EB7C
    // 0x8021E8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021E8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021E8D4: lhu         $a0, 0x4($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4);
L_8021E8D8:
    // 0x8021E8D8: andi        $t8, $a0, 0x8000
    ctx->r24 = ctx->r4 & 0X8000;
    // 0x8021E8DC: beq         $t8, $zero, L_8021E950
    if (ctx->r24 == 0) {
        // 0x8021E8E0: andi        $t5, $a0, 0x10
        ctx->r13 = ctx->r4 & 0X10;
            goto L_8021E950;
    }
    // 0x8021E8E0: andi        $t5, $a0, 0x10
    ctx->r13 = ctx->r4 & 0X10;
    // 0x8021E8E4: lbu         $t9, 0x30($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X30);
    // 0x8021E8E8: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x8021E8EC: bne         $t2, $zero, L_8021E950
    if (ctx->r10 != 0) {
        // 0x8021E8F0: nop
    
            goto L_8021E950;
    }
    // 0x8021E8F0: nop

    // 0x8021E8F4: lh          $t3, 0x6($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X6);
    // 0x8021E8F8: slti        $at, $t3, 0x1F
    ctx->r1 = SIGNED(ctx->r11) < 0X1F ? 1 : 0;
    // 0x8021E8FC: bne         $at, $zero, L_8021E950
    if (ctx->r1 != 0) {
        // 0x8021E900: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8021E950;
    }
    // 0x8021E900: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8021E904: beq         $v0, $at, L_8021E950
    if (ctx->r2 == ctx->r1) {
        // 0x8021E908: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8021E950;
    }
    // 0x8021E908: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021E90C: beq         $v0, $at, L_8021E950
    if (ctx->r2 == ctx->r1) {
        // 0x8021E910: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8021E950;
    }
    // 0x8021E910: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021E914: beq         $v0, $at, L_8021E950
    if (ctx->r2 == ctx->r1) {
        // 0x8021E918: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8021E950;
    }
    // 0x8021E918: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8021E91C: beq         $v0, $at, L_8021E950
    if (ctx->r2 == ctx->r1) {
        // 0x8021E920: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8021E950;
    }
    // 0x8021E920: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8021E924: beq         $v0, $at, L_8021E950
    if (ctx->r2 == ctx->r1) {
        // 0x8021E928: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8021E950;
    }
    // 0x8021E928: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8021E92C: beq         $v0, $at, L_8021E950
    if (ctx->r2 == ctx->r1) {
        // 0x8021E930: nop
    
            goto L_8021E950;
    }
    // 0x8021E930: nop

    // 0x8021E934: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8021E938: beq         $t4, $zero, L_8021E950
    if (ctx->r12 == 0) {
        // 0x8021E93C: nop
    
            goto L_8021E950;
    }
    // 0x8021E93C: nop

    // 0x8021E940: jal         0x802237EC
    // 0x8021E944: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x802237EC)(rdram, ctx);
        goto after_6;
    // 0x8021E944: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x8021E948: b           L_8021EB7C
    // 0x8021E94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021E94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021E950:
    // 0x8021E950: beql        $t5, $zero, L_8021EA6C
    if (ctx->r13 == 0) {
        // 0x8021E954: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_8021EA6C;
    }
    goto skip_18;
    // 0x8021E954: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_18:
    // 0x8021E958: lbu         $t6, 0x30($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X30);
    // 0x8021E95C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021E960: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8021E964: bnel        $t7, $zero, L_8021EA6C
    if (ctx->r15 != 0) {
        // 0x8021E968: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_8021EA6C;
    }
    goto skip_19;
    // 0x8021E968: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_19:
    // 0x8021E96C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8021E970: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8021E974: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8021E978: jal         0x802242D0
    // 0x8021E97C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802242D0)(rdram, ctx);
        goto after_7;
    // 0x8021E97C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_7:
    // 0x8021E980: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8021E984: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8021E988: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8021E98C: beq         $v0, $zero, L_8021EA68
    if (ctx->r2 == 0) {
        // 0x8021E990: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8021EA68;
    }
    // 0x8021E990: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021E994: sb          $zero, 0x328($a2)
    MEM_B(0X328, ctx->r6) = 0;
    // 0x8021E998: lw          $t8, 0x30($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X30);
    // 0x8021E99C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8021E9A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021E9A4: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x8021E9A8: srl         $t2, $t9, 30
    ctx->r10 = S32(U32(ctx->r25) >> 30);
    // 0x8021E9AC: beq         $t2, $zero, L_8021EA58
    if (ctx->r10 == 0) {
        // 0x8021E9B0: nop
    
            goto L_8021EA58;
    }
    // 0x8021E9B0: nop

    // 0x8021E9B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8021E9B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8021E9BC: lwc1        $f10, -0x3880($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3880);
    // 0x8021E9C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8021E9C4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8021E9C8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8021E9CC: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x8021E9D0: nop

    // 0x8021E9D4: bc1fl       L_8021EA6C
    if (!c1cs) {
        // 0x8021E9D8: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_8021EA6C;
    }
    goto skip_20;
    // 0x8021E9D8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_20:
    // 0x8021E9DC: lbu         $v0, 0x74($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X74);
    // 0x8021E9E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021E9E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8021E9E8: beq         $v0, $at, L_8021E9FC
    if (ctx->r2 == ctx->r1) {
        // 0x8021E9EC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_8021E9FC;
    }
    // 0x8021E9EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8021E9F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021E9F4: bne         $v0, $at, L_8021EA2C
    if (ctx->r2 != ctx->r1) {
        // 0x8021E9F8: nop
    
            goto L_8021EA2C;
    }
    // 0x8021E9F8: nop

L_8021E9FC:
    // 0x8021E9FC: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    // 0x8021EA00: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8021EA04: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8021EA08: jal         0x8012C6B4
    // 0x8021EA0C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x8021EA0C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_8:
    // 0x8021EA10: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8021EA14: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x8021EA18: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8021EA1C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8021EA20: bne         $at, $zero, L_8021EA2C
    if (ctx->r1 != 0) {
        // 0x8021EA24: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8021EA2C;
    }
    // 0x8021EA24: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021EA28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8021EA2C:
    // 0x8021EA2C: beq         $v1, $zero, L_8021EA68
    if (ctx->r3 == 0) {
        // 0x8021EA30: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8021EA68;
    }
    // 0x8021EA30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021EA34: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8021EA38: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8021EA3C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8021EA40: jal         0x8036DD08
    // 0x8021EA44: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8036DD08)(rdram, ctx);
        goto after_9;
    // 0x8021EA44: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_9:
    // 0x8021EA48: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8021EA4C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8021EA50: b           L_8021EA68
    // 0x8021EA54: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
        goto L_8021EA68;
    // 0x8021EA54: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021EA58:
    // 0x8021EA58: jal         0x8035C98C
    // 0x8021EA5C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8035C98C)(rdram, ctx);
        goto after_10;
    // 0x8021EA5C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_10:
    // 0x8021EA60: b           L_8021EB7C
    // 0x8021EA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021EA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021EA68:
    // 0x8021EA68: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
L_8021EA6C:
    // 0x8021EA6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8021EA70: lbu         $v0, 0x74($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X74);
    // 0x8021EA74: beq         $v0, $at, L_8021EA84
    if (ctx->r2 == ctx->r1) {
        // 0x8021EA78: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8021EA84;
    }
    // 0x8021EA78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021EA7C: bnel        $v0, $at, L_8021EAC8
    if (ctx->r2 != ctx->r1) {
        // 0x8021EA80: lbu         $v0, 0x390($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X390);
            goto L_8021EAC8;
    }
    goto skip_21;
    // 0x8021EA80: lbu         $v0, 0x390($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X390);
    skip_21:
L_8021EA84:
    // 0x8021EA84: lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X2);
    // 0x8021EA88: andi        $t5, $v0, 0x20
    ctx->r13 = ctx->r2 & 0X20;
    // 0x8021EA8C: beq         $t5, $zero, L_8021EAC4
    if (ctx->r13 == 0) {
        // 0x8021EA90: andi        $t6, $v0, 0xF
        ctx->r14 = ctx->r2 & 0XF;
            goto L_8021EAC4;
    }
    // 0x8021EA90: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x8021EA94: beql        $t6, $zero, L_8021EAC8
    if (ctx->r14 == 0) {
        // 0x8021EA98: lbu         $v0, 0x390($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X390);
            goto L_8021EAC8;
    }
    goto skip_22;
    // 0x8021EA98: lbu         $v0, 0x390($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X390);
    skip_22:
    // 0x8021EA9C: lw          $t7, 0x30($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X30);
    // 0x8021EAA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021EAA4: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8021EAA8: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8021EAAC: beql        $t9, $zero, L_8021EAC8
    if (ctx->r25 == 0) {
        // 0x8021EAB0: lbu         $v0, 0x390($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X390);
            goto L_8021EAC8;
    }
    goto skip_23;
    // 0x8021EAB0: lbu         $v0, 0x390($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X390);
    skip_23:
    // 0x8021EAB4: jal         0x80362EC8
    // 0x8021EAB8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x80362EC8)(rdram, ctx);
        goto after_11;
    // 0x8021EAB8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_11:
    // 0x8021EABC: b           L_8021EB7C
    // 0x8021EAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021EAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021EAC4:
    // 0x8021EAC4: lbu         $v0, 0x390($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X390);
L_8021EAC8:
    // 0x8021EAC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021EACC: beql        $v0, $zero, L_8021EAEC
    if (ctx->r2 == 0) {
        // 0x8021EAD0: lbu         $t2, 0x328($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X328);
            goto L_8021EAEC;
    }
    goto skip_24;
    // 0x8021EAD0: lbu         $t2, 0x328($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X328);
    skip_24:
    // 0x8021EAD4: sb          $zero, 0x328($a2)
    MEM_B(0X328, ctx->r6) = 0;
    // 0x8021EAD8: jal         0x8036E960
    // 0x8021EADC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8036E960)(rdram, ctx);
        goto after_12;
    // 0x8021EADC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x8021EAE0: b           L_8021EB7C
    // 0x8021EAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021EAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021EAE8: lbu         $t2, 0x328($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X328);
L_8021EAEC:
    // 0x8021EAEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021EAF0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021EAF4: bnel        $t2, $at, L_8021EB10
    if (ctx->r10 != ctx->r1) {
        // 0x8021EAF8: lhu         $t3, 0x2($t0)
        ctx->r11 = MEM_HU(ctx->r8, 0X2);
            goto L_8021EB10;
    }
    goto skip_25;
    // 0x8021EAF8: lhu         $t3, 0x2($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X2);
    skip_25:
    // 0x8021EAFC: jal         0x8021F7AC
    // 0x8021EB00: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8021F7AC)(rdram, ctx);
        goto after_13;
    // 0x8021EB00: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_13:
    // 0x8021EB04: b           L_8021EB7C
    // 0x8021EB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021EB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021EB0C: lhu         $t3, 0x2($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X2);
L_8021EB10:
    // 0x8021EB10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021EB14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021EB18: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8021EB1C: beq         $t4, $zero, L_8021EB70
    if (ctx->r12 == 0) {
        // 0x8021EB20: nop
    
            goto L_8021EB70;
    }
    // 0x8021EB20: nop

    // 0x8021EB24: beq         $v0, $at, L_8021EB5C
    if (ctx->r2 == ctx->r1) {
        // 0x8021EB28: lwc1        $f0, 0x2C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8021EB5C;
    }
    // 0x8021EB28: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8021EB2C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8021EB30: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8021EB34: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8021EB38: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8021EB3C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8021EB40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8021EB44: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8021EB48: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8021EB4C: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8021EB50: nop

    // 0x8021EB54: bc1f        L_8021EB70
    if (!c1cs) {
        // 0x8021EB58: nop
    
            goto L_8021EB70;
    }
    // 0x8021EB58: nop

L_8021EB5C:
    // 0x8021EB5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8021EB60: jal         0x8021FE14
    // 0x8021EB64: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8021FE14)(rdram, ctx);
        goto after_14;
    // 0x8021EB64: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_14:
    // 0x8021EB68: b           L_8021EB7C
    // 0x8021EB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021EB7C;
    // 0x8021EB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021EB70:
    // 0x8021EB70: jal         0x8021EB88
    // 0x8021EB74: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8021EB88)(rdram, ctx);
        goto after_15;
    // 0x8021EB74: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_15:
L_8021EB78:
    // 0x8021EB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021EB7C:
    // 0x8021EB7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8021EB80: jr          $ra
    // 0x8021EB84: nop

    return;
    // 0x8021EB84: nop

;}
RECOMP_FUNC void M10_FUN_8021eb88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021EB88: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021EB8C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021eb90(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021eb90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021EB90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8021EB94: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x8021EB98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021EB9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021EBA0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8021EBA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021EBA8: bne         $a0, $t6, L_8021EBC0
    if (ctx->r4 != ctx->r14) {
        // 0x8021EBAC: lw          $v0, 0x68($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X68);
            goto L_8021EBC0;
    }
    // 0x8021EBAC: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x8021EBB0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8021EBB4: addiu       $t7, $t7, -0x3FC4
    ctx->r15 = ADD32(ctx->r15, -0X3FC4);
    // 0x8021EBB8: b           L_8021EBCC
    // 0x8021EBBC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_8021EBCC;
    // 0x8021EBBC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8021EBC0:
    // 0x8021EBC0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8021EBC4: addiu       $t8, $t8, -0x3C28
    ctx->r24 = ADD32(ctx->r24, -0X3C28);
    // 0x8021EBC8: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_8021EBCC:
    // 0x8021EBCC: lh          $t9, 0x232($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X232);
    // 0x8021EBD0: addiu       $t0, $zero, 0x2800
    ctx->r8 = ADD32(0, 0X2800);
    // 0x8021EBD4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8021EBD8: subu        $t3, $t0, $t9
    ctx->r11 = SUB32(ctx->r8, ctx->r25);
    // 0x8021EBDC: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8021EBE0: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    // 0x8021EBE4: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x8021EBE8: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x8021EBEC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8021EBF0: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8021EBF4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8021EBF8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8021EBFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8021EC00: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8021EC04: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8021EC08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8021EC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021EC10: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8021EC14: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8021EC18: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8021EC1C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8021EC20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8021EC24: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8021EC28: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8021EC2C: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x8021EC30: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8021EC34: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8021EC38: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8021EC3C: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8021EC40: nop

    // 0x8021EC44: bc1f        L_8021ECA4
    if (!c1cs) {
        // 0x8021EC48: nop
    
            goto L_8021ECA4;
    }
    // 0x8021EC48: nop

    // 0x8021EC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021EC50: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8021EC54: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8021EC58: jal         0x802237B0
    // 0x8021EC5C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x8021EC5C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8021EC60: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8021EC64: jal         0x8001EF38
    // 0x8021EC68: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8021EC68: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8021EC6C: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8021EC70: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8021EC74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021EC78: addu        $a2, $v0, $t8
    ctx->r6 = ADD32(ctx->r2, ctx->r24);
    // 0x8021EC7C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8021EC80: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8021EC84: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8021EC88: jal         0x8021F184
    // 0x8021EC8C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8021F184)(rdram, ctx);
        goto after_2;
    // 0x8021EC8C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x8021EC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021EC94: jal         0x80224AC4
    // 0x8021EC98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80224AC4)(rdram, ctx);
        goto after_3;
    // 0x8021EC98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8021EC9C: b           L_8021ECBC
    // 0x8021ECA0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
        goto L_8021ECBC;
    // 0x8021ECA0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021ECA4:
    // 0x8021ECA4: jal         0x802237B0
    // 0x8021ECA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_4;
    // 0x8021ECA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8021ECAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021ECB0: jal         0x8021ECD4
    // 0x8021ECB4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8021ECD4)(rdram, ctx);
        goto after_5;
    // 0x8021ECB4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x8021ECB8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021ECBC:
    // 0x8021ECBC: sb          $zero, 0x392($t0)
    MEM_B(0X392, ctx->r8) = 0;
    // 0x8021ECC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021ECC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021ECC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8021ECCC: jr          $ra
    // 0x8021ECD0: nop

    return;
    // 0x8021ECD0: nop

;}
RECOMP_FUNC void M10_FUN_8021ecd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021ECD4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8021ECD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021ECDC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8021ECE0: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8021ECE4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8021ECE8: lw          $t8, -0x4334($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4334);
    // 0x8021ECEC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8021ECF0: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x8021ECF4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8021ECF8: bne         $a0, $t8, L_8021ED0C
    if (ctx->r4 != ctx->r24) {
        // 0x8021ECFC: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_8021ED0C;
    }
    // 0x8021ECFC: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8021ED00: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021ED04: b           L_8021ED14
    // 0x8021ED08: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
        goto L_8021ED14;
    // 0x8021ED08: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
L_8021ED0C:
    // 0x8021ED0C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021ED10: addiu       $t0, $t0, -0x3C28
    ctx->r8 = ADD32(ctx->r8, -0X3C28);
L_8021ED14:
    // 0x8021ED14: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x8021ED18: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8021ED1C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8021ED20: sll         $t1, $t9, 9
    ctx->r9 = S32(ctx->r25 << 9);
    // 0x8021ED24: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x8021ED28: bne         $t2, $zero, L_8021ED50
    if (ctx->r10 != 0) {
        // 0x8021ED2C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8021ED50;
    }
    // 0x8021ED2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8021ED30: lbu         $t3, 0x2F9($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X2F9);
    // 0x8021ED34: lbu         $t8, 0x31($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X31);
    // 0x8021ED38: addiu       $t5, $t3, 0x2
    ctx->r13 = ADD32(ctx->r11, 0X2);
    // 0x8021ED3C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8021ED40: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x8021ED44: andi        $t9, $t8, 0xFF9F
    ctx->r25 = ctx->r24 & 0XFF9F;
    // 0x8021ED48: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8021ED4C: sb          $t1, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r9;
L_8021ED50:
    // 0x8021ED50: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x8021ED54: jal         0x802256E4
    // 0x8021ED58: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_0;
    // 0x8021ED58: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x8021ED5C: lhu         $t2, 0x32($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X32);
    // 0x8021ED60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8021ED64: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x8021ED68: jal         0x8022560C
    // 0x8021ED6C: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_1;
    // 0x8021ED6C: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
    after_1:
    // 0x8021ED70: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8021ED74: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021ED78: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x8021ED7C: bne         $at, $zero, L_8021ED98
    if (ctx->r1 != 0) {
        // 0x8021ED80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021ED98;
    }
    // 0x8021ED80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021ED84: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8021ED88: beql        $v0, $at, L_8021F144
    if (ctx->r2 == ctx->r1) {
        // 0x8021ED8C: addiu       $t7, $sp, 0x2C
        ctx->r15 = ADD32(ctx->r29, 0X2C);
            goto L_8021F144;
    }
    goto skip_0;
    // 0x8021ED8C: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    skip_0:
    // 0x8021ED90: b           L_8021F144
    // 0x8021ED94: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
        goto L_8021F144;
    // 0x8021ED94: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
L_8021ED98:
    // 0x8021ED98: sltiu       $at, $v1, 0x1D
    ctx->r1 = ctx->r3 < 0X1D ? 1 : 0;
    // 0x8021ED9C: beq         $at, $zero, L_8021F140
    if (ctx->r1 == 0) {
        // 0x8021EDA0: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_8021F140;
    }
    // 0x8021EDA0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8021EDA4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8021EDA8: addu        $at, $at, $t4
    gpr jr_addend_8021EDB0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8021EDAC: lw          $t4, -0x15E0($at)
    ctx->r12 = ADD32(ctx->r1, -0X15E0);
    // 0x8021EDB0: jr          $t4
    // 0x8021EDB4: nop

    switch (jr_addend_8021EDB0 >> 2) {
        case 0: goto L_8021F078; break;
        case 1: goto L_8021F140; break;
        case 2: goto L_8021EFD8; break;
        case 3: goto L_8021EFD8; break;
        case 4: goto L_8021EDD0; break;
        case 5: goto L_8021EDD0; break;
        case 6: goto L_8021EDD0; break;
        case 7: goto L_8021EDB8; break;
        case 8: goto L_8021EDB8; break;
        case 9: goto L_8021EDB8; break;
        case 10: goto L_8021F140; break;
        case 11: goto L_8021F140; break;
        case 12: goto L_8021F140; break;
        case 13: goto L_8021EDD0; break;
        case 14: goto L_8021EDD0; break;
        case 15: goto L_8021EDD0; break;
        case 16: goto L_8021EDD0; break;
        case 17: goto L_8021EDD0; break;
        case 18: goto L_8021EDD0; break;
        case 19: goto L_8021EDD0; break;
        case 20: goto L_8021EDD0; break;
        case 21: goto L_8021EDD0; break;
        case 22: goto L_8021EDD0; break;
        case 23: goto L_8021EDD0; break;
        case 24: goto L_8021EDD0; break;
        case 25: goto L_8021EDD0; break;
        case 26: goto L_8021EDD0; break;
        case 27: goto L_8021EDD0; break;
        case 28: goto L_8021EDD0; break;
        default: switch_error(__func__, 0x8021EDB0, 0x8023EA20);
    }
    // 0x8021EDB4: nop

L_8021EDB8:
    // 0x8021EDB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8021EDBC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021EDC0: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021EDC4: jal         0x800112B0
    // 0x8021EDC8: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x800112B0)(rdram, ctx);
        goto after_2;
    // 0x8021EDC8: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_2:
    // 0x8021EDCC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021EDD0:
    // 0x8021EDD0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021EDD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8021EDD8: jal         0x802237B0
    // 0x8021EDDC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_3;
    // 0x8021EDDC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x8021EDE0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021EDE4: jal         0x80010550
    // 0x8021EDE8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_4;
    // 0x8021EDE8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x8021EDEC: beq         $v0, $zero, L_8021F174
    if (ctx->r2 == 0) {
        // 0x8021EDF0: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8021F174;
    }
    // 0x8021EDF0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021EDF4: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x8021EDF8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8021EDFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8021EE00: bne         $v0, $at, L_8021EE54
    if (ctx->r2 != ctx->r1) {
        // 0x8021EE04: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_8021EE54;
    }
    // 0x8021EE04: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8021EE08: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x8021EE0C: lbu         $t2, 0x31($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X31);
    // 0x8021EE10: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x8021EE14: sll         $t6, $t5, 9
    ctx->r14 = S32(ctx->r13 << 9);
    // 0x8021EE18: srl         $t8, $t6, 30
    ctx->r24 = S32(U32(ctx->r14) >> 30);
    // 0x8021EE1C: xori        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 ^ 0X1;
    // 0x8021EE20: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x8021EE24: andi        $t1, $t9, 0x60
    ctx->r9 = ctx->r25 & 0X60;
    // 0x8021EE28: andi        $t3, $t2, 0xFF9F
    ctx->r11 = ctx->r10 & 0XFF9F;
    // 0x8021EE2C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8021EE30: sb          $t4, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r12;
    // 0x8021EE34: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021EE38: sh          $a3, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r7;
    // 0x8021EE3C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8021EE40: jal         0x802256E4
    // 0x8021EE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_5;
    // 0x8021EE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8021EE48: lh          $a3, 0x28($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X28);
    // 0x8021EE4C: b           L_8021EF2C
    // 0x8021EE50: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
        goto L_8021EF2C;
    // 0x8021EE50: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021EE54:
    // 0x8021EE54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021EE58: bnel        $v0, $at, L_8021EE8C
    if (ctx->r2 != ctx->r1) {
        // 0x8021EE5C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8021EE8C;
    }
    goto skip_1;
    // 0x8021EE5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
    // 0x8021EE60: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x8021EE64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021EE68: sll         $t6, $t5, 9
    ctx->r14 = S32(ctx->r13 << 9);
    // 0x8021EE6C: srl         $t8, $t6, 30
    ctx->r24 = S32(U32(ctx->r14) >> 30);
    // 0x8021EE70: bne         $t8, $at, L_8021EE80
    if (ctx->r24 != ctx->r1) {
        // 0x8021EE74: nop
    
            goto L_8021EE80;
    }
    // 0x8021EE74: nop

    // 0x8021EE78: b           L_8021EF2C
    // 0x8021EE7C: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
        goto L_8021EF2C;
    // 0x8021EE7C: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
L_8021EE80:
    // 0x8021EE80: b           L_8021EF2C
    // 0x8021EE84: addiu       $a3, $zero, 0x1800
    ctx->r7 = ADD32(0, 0X1800);
        goto L_8021EF2C;
    // 0x8021EE84: addiu       $a3, $zero, 0x1800
    ctx->r7 = ADD32(0, 0X1800);
    // 0x8021EE88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8021EE8C:
    // 0x8021EE8C: bnel        $v0, $at, L_8021EEC0
    if (ctx->r2 != ctx->r1) {
        // 0x8021EE90: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8021EEC0;
    }
    goto skip_2;
    // 0x8021EE90: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_2:
    // 0x8021EE94: lw          $t7, 0x30($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X30);
    // 0x8021EE98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021EE9C: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8021EEA0: srl         $t2, $t9, 30
    ctx->r10 = S32(U32(ctx->r25) >> 30);
    // 0x8021EEA4: bne         $t2, $at, L_8021EEB4
    if (ctx->r10 != ctx->r1) {
        // 0x8021EEA8: nop
    
            goto L_8021EEB4;
    }
    // 0x8021EEA8: nop

    // 0x8021EEAC: b           L_8021EF2C
    // 0x8021EEB0: addiu       $a3, $zero, 0x1800
    ctx->r7 = ADD32(0, 0X1800);
        goto L_8021EF2C;
    // 0x8021EEB0: addiu       $a3, $zero, 0x1800
    ctx->r7 = ADD32(0, 0X1800);
L_8021EEB4:
    // 0x8021EEB4: b           L_8021EF2C
    // 0x8021EEB8: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
        goto L_8021EF2C;
    // 0x8021EEB8: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    // 0x8021EEBC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_8021EEC0:
    // 0x8021EEC0: beq         $v0, $at, L_8021EEDC
    if (ctx->r2 == ctx->r1) {
        // 0x8021EEC4: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8021EEDC;
    }
    // 0x8021EEC4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8021EEC8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8021EECC: beq         $v0, $at, L_8021EEDC
    if (ctx->r2 == ctx->r1) {
        // 0x8021EED0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8021EEDC;
    }
    // 0x8021EED0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8021EED4: bnel        $v0, $at, L_8021EF30
    if (ctx->r2 != ctx->r1) {
        // 0x8021EED8: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_8021EF30;
    }
    goto skip_3;
    // 0x8021EED8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    skip_3:
L_8021EEDC:
    // 0x8021EEDC: lhu         $t3, 0x22($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X22);
    // 0x8021EEE0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8021EEE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8021EEE8: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8021EEEC: beql        $t4, $zero, L_8021EF08
    if (ctx->r12 == 0) {
        // 0x8021EEF0: lbu         $t7, 0x31($t0)
        ctx->r15 = MEM_BU(ctx->r8, 0X31);
            goto L_8021EF08;
    }
    goto skip_4;
    // 0x8021EEF0: lbu         $t7, 0x31($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X31);
    skip_4:
    // 0x8021EEF4: lbu         $t6, 0x31($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X31);
    // 0x8021EEF8: ori         $t8, $t6, 0x60
    ctx->r24 = ctx->r14 | 0X60;
    // 0x8021EEFC: b           L_8021EF14
    // 0x8021EF00: sb          $t8, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r24;
        goto L_8021EF14;
    // 0x8021EF00: sb          $t8, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r24;
    // 0x8021EF04: lbu         $t7, 0x31($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X31);
L_8021EF08:
    // 0x8021EF08: andi        $t9, $t7, 0xFF9F
    ctx->r25 = ctx->r15 & 0XFF9F;
    // 0x8021EF0C: ori         $t2, $t9, 0x40
    ctx->r10 = ctx->r25 | 0X40;
    // 0x8021EF10: sb          $t2, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r10;
L_8021EF14:
    // 0x8021EF14: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8021EF18: sh          $a3, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r7;
    // 0x8021EF1C: jal         0x802256E4
    // 0x8021EF20: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_6;
    // 0x8021EF20: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_6:
    // 0x8021EF24: lh          $a3, 0x28($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X28);
    // 0x8021EF28: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8021EF2C:
    // 0x8021EF2C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_8021EF30:
    // 0x8021EF30: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8021EF34: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8021EF38: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8021EF3C: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x8021EF40: lh          $t3, 0x12($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X12);
    // 0x8021EF44: addu        $t4, $t3, $a3
    ctx->r12 = ADD32(ctx->r11, ctx->r7);
    // 0x8021EF48: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
    // 0x8021EF4C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8021EF50: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x8021EF54: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x8021EF58: andi        $t8, $t6, 0x1FFF
    ctx->r24 = ctx->r14 & 0X1FFF;
    // 0x8021EF5C: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x8021EF60: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021EF64: jal         0x80224E00
    // 0x8021EF68: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80224E00)(rdram, ctx);
        goto after_7;
    // 0x8021EF68: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x8021EF6C: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x8021EF70: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8021EF74: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021EF78: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8021EF7C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x8021EF80: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021EF84: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021EF88: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x8021EF8C: jal         0x8013A28C
    // 0x8021EF90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_8;
    // 0x8021EF90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_8:
    // 0x8021EF94: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021EF98: jal         0x80010550
    // 0x8021EF9C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_9;
    // 0x8021EF9C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_9:
    // 0x8021EFA0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021EFA4: lbu         $t1, 0x32($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X32);
    // 0x8021EFA8: andi        $t3, $t1, 0xFF1F
    ctx->r11 = ctx->r9 & 0XFF1F;
    // 0x8021EFAC: sb          $t3, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r11;
    // 0x8021EFB0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8021EFB4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021EFB8: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x8021EFBC: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x8021EFC0: beql        $t6, $zero, L_8021F178
    if (ctx->r14 == 0) {
        // 0x8021EFC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021F178;
    }
    goto skip_5;
    // 0x8021EFC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8021EFC8: jal         0x8021FB0C
    // 0x8021EFCC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x8021FB0C)(rdram, ctx);
        goto after_10;
    // 0x8021EFCC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x8021EFD0: b           L_8021F178
    // 0x8021EFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F178;
    // 0x8021EFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021EFD8:
    // 0x8021EFD8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021EFDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8021EFE0: jal         0x80224AC4
    // 0x8021EFE4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80224AC4)(rdram, ctx);
        goto after_11;
    // 0x8021EFE4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_11:
    // 0x8021EFE8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021EFEC: jal         0x802237B0
    // 0x8021EFF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_12;
    // 0x8021EFF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8021EFF4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021EFF8: jal         0x80010550
    // 0x8021EFFC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_13;
    // 0x8021EFFC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_13:
    // 0x8021F000: beq         $v0, $zero, L_8021F050
    if (ctx->r2 == 0) {
        // 0x8021F004: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8021F050;
    }
    // 0x8021F004: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021F008: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8021F00C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8021F010: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F014: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8021F018: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x8021F01C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021F020: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021F024: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x8021F028: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8021F02C: jal         0x8013A28C
    // 0x8021F030: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_14;
    // 0x8021F030: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_14:
    // 0x8021F034: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F038: jal         0x80010550
    // 0x8021F03C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_15;
    // 0x8021F03C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x8021F040: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021F044: lbu         $t2, 0x32($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X32);
    // 0x8021F048: andi        $t1, $t2, 0xFF1F
    ctx->r9 = ctx->r10 & 0XFF1F;
    // 0x8021F04C: sb          $t1, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r9;
L_8021F050:
    // 0x8021F050: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8021F054: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021F058: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x8021F05C: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x8021F060: beql        $t5, $zero, L_8021F178
    if (ctx->r13 == 0) {
        // 0x8021F064: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021F178;
    }
    goto skip_6;
    // 0x8021F064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8021F068: jal         0x8021FB0C
    // 0x8021F06C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x8021FB0C)(rdram, ctx);
        goto after_16;
    // 0x8021F06C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_16:
    // 0x8021F070: b           L_8021F178
    // 0x8021F074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F178;
    // 0x8021F074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F078:
    // 0x8021F078: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021F07C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8021F080: jal         0x802237B0
    // 0x8021F084: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_17;
    // 0x8021F084: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_17:
    // 0x8021F088: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F08C: jal         0x80010550
    // 0x8021F090: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_18;
    // 0x8021F090: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_18:
    // 0x8021F094: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8021F098: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F09C: jal         0x800111E0
    // 0x8021F0A0: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x800111E0)(rdram, ctx);
        goto after_19;
    // 0x8021F0A0: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_19:
    // 0x8021F0A4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8021F0A8: lbu         $t6, 0x32($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X32);
    // 0x8021F0AC: andi        $t8, $t6, 0xFF1F
    ctx->r24 = ctx->r14 & 0XFF1F;
    // 0x8021F0B0: sb          $t8, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r24;
    // 0x8021F0B4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8021F0B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021F0BC: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8021F0C0: andi        $t2, $t9, 0x4000
    ctx->r10 = ctx->r25 & 0X4000;
    // 0x8021F0C4: beq         $t2, $zero, L_8021F0DC
    if (ctx->r10 == 0) {
        // 0x8021F0C8: nop
    
            goto L_8021F0DC;
    }
    // 0x8021F0C8: nop

    // 0x8021F0CC: jal         0x8021FB0C
    // 0x8021F0D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x8021FB0C)(rdram, ctx);
        goto after_20;
    // 0x8021F0D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_20:
    // 0x8021F0D4: b           L_8021F178
    // 0x8021F0D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F178;
    // 0x8021F0D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F0DC:
    // 0x8021F0DC: jal         0x80224B64
    // 0x8021F0E0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80224B64)(rdram, ctx);
        goto after_21;
    // 0x8021F0E0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_21:
    // 0x8021F0E4: beq         $v0, $zero, L_8021F100
    if (ctx->r2 == 0) {
        // 0x8021F0E8: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_8021F100;
    }
    // 0x8021F0E8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8021F0EC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8021F0F0: jal         0x80224BEC
    // 0x8021F0F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x80224BEC)(rdram, ctx);
        goto after_22;
    // 0x8021F0F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_22:
    // 0x8021F0F8: b           L_8021F178
    // 0x8021F0FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F178;
    // 0x8021F0FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F100:
    // 0x8021F100: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8021F104: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x8021F108: addiu       $t5, $sp, 0x2C
    ctx->r13 = ADD32(ctx->r29, 0X2C);
    // 0x8021F10C: beql        $t1, $t4, L_8021F178
    if (ctx->r9 == ctx->r12) {
        // 0x8021F110: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021F178;
    }
    goto skip_7;
    // 0x8021F110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8021F114: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8021F118: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F11C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8021F120: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x8021F124: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021F128: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021F12C: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x8021F130: jal         0x8013A28C
    // 0x8021F134: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_23;
    // 0x8021F134: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_23:
    // 0x8021F138: b           L_8021F178
    // 0x8021F13C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F178;
    // 0x8021F13C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F140:
    // 0x8021F140: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
L_8021F144:
    // 0x8021F144: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8021F148: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8021F14C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F150: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8021F154: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x8021F158: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8021F15C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8021F160: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8021F164: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x8021F168: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8021F16C: jal         0x80011140
    // 0x8021F170: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_24;
    // 0x8021F170: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_24:
L_8021F174:
    // 0x8021F174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F178:
    // 0x8021F178: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8021F17C: jr          $ra
    // 0x8021F180: nop

    return;
    // 0x8021F180: nop

;}
RECOMP_FUNC void M10_FUN_8021f184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021F184: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8021F188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021F18C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8021F190: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8021F194: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8021F198: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8021F19C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8021F1A0: lw          $t8, -0x4334($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4334);
    // 0x8021F1A4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8021F1A8: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x8021F1AC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8021F1B0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8021F1B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8021F1B8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8021F1BC: bne         $a0, $t8, L_8021F1D0
    if (ctx->r4 != ctx->r24) {
        // 0x8021F1C0: sw          $t7, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r15;
            goto L_8021F1D0;
    }
    // 0x8021F1C0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x8021F1C4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021F1C8: b           L_8021F1D8
    // 0x8021F1CC: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
        goto L_8021F1D8;
    // 0x8021F1CC: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
L_8021F1D0:
    // 0x8021F1D0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021F1D4: addiu       $t0, $t0, -0x3C28
    ctx->r8 = ADD32(ctx->r8, -0X3C28);
L_8021F1D8:
    // 0x8021F1D8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8021F1DC: lw          $t4, 0x30($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X30);
    // 0x8021F1E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8021F1E4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8021F1E8: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x8021F1EC: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x8021F1F0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8021F1F4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8021F1F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8021F1FC: lh          $v0, 0x12($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X12);
    // 0x8021F200: subu        $v1, $a2, $v0
    ctx->r3 = SUB32(ctx->r6, ctx->r2);
    // 0x8021F204: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8021F208: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8021F20C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8021F210: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8021F214: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // 0x8021F218: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8021F21C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8021F220: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8021F224: bgez        $v1, L_8021F230
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8021F228: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_8021F230;
    }
    // 0x8021F228: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x8021F22C: addiu       $at, $v1, 0x3FF
    ctx->r1 = ADD32(ctx->r3, 0X3FF);
L_8021F230:
    // 0x8021F230: sra         $v1, $at, 10
    ctx->r3 = S32(SIGNED(ctx->r1) >> 10);
    // 0x8021F234: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021F238: bne         $t6, $at, L_8021F260
    if (ctx->r14 != ctx->r1) {
        // 0x8021F23C: andi        $t1, $v1, 0xFF
        ctx->r9 = ctx->r3 & 0XFF;
            goto L_8021F260;
    }
    // 0x8021F23C: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8021F240: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8021F244: subu        $t1, $t8, $t7
    ctx->r9 = SUB32(ctx->r24, ctx->r15);
    // 0x8021F248: bgez        $t1, L_8021F25C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8021F24C: andi        $t1, $t1, 0x7
        ctx->r9 = ctx->r9 & 0X7;
            goto L_8021F25C;
    }
    // 0x8021F24C: andi        $t1, $t1, 0x7
    ctx->r9 = ctx->r9 & 0X7;
    // 0x8021F250: beq         $t1, $zero, L_8021F25C
    if (ctx->r9 == 0) {
        // 0x8021F254: nop
    
            goto L_8021F25C;
    }
    // 0x8021F254: nop

    // 0x8021F258: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
L_8021F25C:
    // 0x8021F25C: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
L_8021F260:
    // 0x8021F260: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8021F264: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8021F268: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8021F26C: c.le.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d <= ctx->f0.d;
    // 0x8021F270: nop

    // 0x8021F274: bc1fl       L_8021F288
    if (!c1cs) {
        // 0x8021F278: sw          $a3, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r7;
            goto L_8021F288;
    }
    goto skip_0;
    // 0x8021F278: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    skip_0:
    // 0x8021F27C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8021F280: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x8021F284: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
L_8021F288:
    // 0x8021F288: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8021F28C: sb          $t1, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r9;
    // 0x8021F290: jal         0x8022560C
    // 0x8021F294: sdc1        $f0, 0x28($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X28, ctx->r29);
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_0;
    // 0x8021F294: sdc1        $f0, 0x28($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X28, ctx->r29);
    after_0:
    // 0x8021F298: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8021F29C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F2A0: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x8021F2A4: sb          $v0, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = ctx->r2;
    // 0x8021F2A8: bne         $at, $zero, L_8021F2C4
    if (ctx->r1 != 0) {
        // 0x8021F2AC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021F2C4;
    }
    // 0x8021F2AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021F2B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8021F2B4: beql        $v0, $at, L_8021F710
    if (ctx->r2 == ctx->r1) {
        // 0x8021F2B8: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8021F710;
    }
    goto skip_1;
    // 0x8021F2B8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    skip_1:
    // 0x8021F2BC: b           L_8021F710
    // 0x8021F2C0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
        goto L_8021F710;
    // 0x8021F2C0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_8021F2C4:
    // 0x8021F2C4: sltiu       $at, $v1, 0x1D
    ctx->r1 = ctx->r3 < 0X1D ? 1 : 0;
    // 0x8021F2C8: beq         $at, $zero, L_8021F70C
    if (ctx->r1 == 0) {
        // 0x8021F2CC: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8021F70C;
    }
    // 0x8021F2CC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8021F2D0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8021F2D4: addu        $at, $at, $t9
    gpr jr_addend_8021F2DC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8021F2D8: lw          $t9, -0x156C($at)
    ctx->r25 = ADD32(ctx->r1, -0X156C);
    // 0x8021F2DC: jr          $t9
    // 0x8021F2E0: nop

    switch (jr_addend_8021F2DC >> 2) {
        case 0: goto L_8021F61C; break;
        case 1: goto L_8021F70C; break;
        case 2: goto L_8021F5FC; break;
        case 3: goto L_8021F5FC; break;
        case 4: goto L_8021F304; break;
        case 5: goto L_8021F304; break;
        case 6: goto L_8021F304; break;
        case 7: goto L_8021F2E4; break;
        case 8: goto L_8021F2E4; break;
        case 9: goto L_8021F2E4; break;
        case 10: goto L_8021F70C; break;
        case 11: goto L_8021F70C; break;
        case 12: goto L_8021F70C; break;
        case 13: goto L_8021F304; break;
        case 14: goto L_8021F304; break;
        case 15: goto L_8021F304; break;
        case 16: goto L_8021F304; break;
        case 17: goto L_8021F304; break;
        case 18: goto L_8021F304; break;
        case 19: goto L_8021F304; break;
        case 20: goto L_8021F304; break;
        case 21: goto L_8021F304; break;
        case 22: goto L_8021F304; break;
        case 23: goto L_8021F304; break;
        case 24: goto L_8021F304; break;
        case 25: goto L_8021F304; break;
        case 26: goto L_8021F304; break;
        case 27: goto L_8021F304; break;
        case 28: goto L_8021F304; break;
        default: switch_error(__func__, 0x8021F2DC, 0x8023EA94);
    }
    // 0x8021F2E0: nop

L_8021F2E4:
    // 0x8021F2E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8021F2E8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F2EC: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8021F2F0: sb          $t1, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r9;
    // 0x8021F2F4: jal         0x800112B0
    // 0x8021F2F8: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x800112B0)(rdram, ctx);
        goto after_1;
    // 0x8021F2F8: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_1:
    // 0x8021F2FC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F300: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
L_8021F304:
    // 0x8021F304: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8021F308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8021F30C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8021F310: jal         0x802237B0
    // 0x8021F314: sb          $t1, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_2;
    // 0x8021F314: sb          $t1, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r9;
    after_2:
    // 0x8021F318: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F31C: jal         0x80010550
    // 0x8021F320: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x8021F320: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x8021F324: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F328: beq         $v0, $zero, L_8021F570
    if (ctx->r2 == 0) {
        // 0x8021F32C: lbu         $t1, 0x4B($sp)
        ctx->r9 = MEM_BU(ctx->r29, 0X4B);
            goto L_8021F570;
    }
    // 0x8021F32C: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x8021F330: lbu         $v1, 0x4A($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4A);
    // 0x8021F334: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8021F338: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8021F33C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8021F340: bne         $v1, $at, L_8021F378
    if (ctx->r3 != ctx->r1) {
        // 0x8021F344: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_8021F378;
    }
    // 0x8021F344: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x8021F348: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x8021F34C: lbu         $t7, 0x31($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X31);
    // 0x8021F350: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8021F354: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x8021F358: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x8021F35C: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x8021F360: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8021F364: andi        $t8, $t6, 0x60
    ctx->r24 = ctx->r14 & 0X60;
    // 0x8021F368: andi        $t9, $t7, 0xFF9F
    ctx->r25 = ctx->r15 & 0XFF9F;
    // 0x8021F36C: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x8021F370: b           L_8021F42C
    // 0x8021F374: sb          $t2, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r10;
        goto L_8021F42C;
    // 0x8021F374: sb          $t2, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r10;
L_8021F378:
    // 0x8021F378: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021F37C: bnel        $v1, $at, L_8021F3B0
    if (ctx->r3 != ctx->r1) {
        // 0x8021F380: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8021F3B0;
    }
    goto skip_2;
    // 0x8021F380: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_2:
    // 0x8021F384: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x8021F388: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021F38C: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x8021F390: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x8021F394: bne         $t5, $at, L_8021F3A4
    if (ctx->r13 != ctx->r1) {
        // 0x8021F398: nop
    
            goto L_8021F3A4;
    }
    // 0x8021F398: nop

    // 0x8021F39C: b           L_8021F42C
    // 0x8021F3A0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
        goto L_8021F42C;
    // 0x8021F3A0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
L_8021F3A4:
    // 0x8021F3A4: b           L_8021F42C
    // 0x8021F3A8: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
        goto L_8021F42C;
    // 0x8021F3A8: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
    // 0x8021F3AC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8021F3B0:
    // 0x8021F3B0: bnel        $v1, $at, L_8021F3E4
    if (ctx->r3 != ctx->r1) {
        // 0x8021F3B4: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8021F3E4;
    }
    goto skip_3;
    // 0x8021F3B4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_3:
    // 0x8021F3B8: lw          $t6, 0x30($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X30);
    // 0x8021F3BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021F3C0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8021F3C4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8021F3C8: bne         $t8, $at, L_8021F3D8
    if (ctx->r24 != ctx->r1) {
        // 0x8021F3CC: nop
    
            goto L_8021F3D8;
    }
    // 0x8021F3CC: nop

    // 0x8021F3D0: b           L_8021F42C
    // 0x8021F3D4: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
        goto L_8021F42C;
    // 0x8021F3D4: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
L_8021F3D8:
    // 0x8021F3D8: b           L_8021F42C
    // 0x8021F3DC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
        goto L_8021F42C;
    // 0x8021F3DC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8021F3E0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_8021F3E4:
    // 0x8021F3E4: beq         $v1, $at, L_8021F3FC
    if (ctx->r3 == ctx->r1) {
        // 0x8021F3E8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8021F3FC;
    }
    // 0x8021F3E8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8021F3EC: beq         $v1, $at, L_8021F3FC
    if (ctx->r3 == ctx->r1) {
        // 0x8021F3F0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8021F3FC;
    }
    // 0x8021F3F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8021F3F4: bnel        $v1, $at, L_8021F430
    if (ctx->r3 != ctx->r1) {
        // 0x8021F3F8: lw          $v1, 0x64($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X64);
            goto L_8021F430;
    }
    goto skip_4;
    // 0x8021F3F8: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    skip_4:
L_8021F3FC:
    // 0x8021F3FC: lhu         $t9, 0x6($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X6);
    // 0x8021F400: andi        $t2, $t9, 0x10
    ctx->r10 = ctx->r25 & 0X10;
    // 0x8021F404: beql        $t2, $zero, L_8021F420
    if (ctx->r10 == 0) {
        // 0x8021F408: lbu         $t6, 0x31($t0)
        ctx->r14 = MEM_BU(ctx->r8, 0X31);
            goto L_8021F420;
    }
    goto skip_5;
    // 0x8021F408: lbu         $t6, 0x31($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X31);
    skip_5:
    // 0x8021F40C: lbu         $t4, 0x31($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X31);
    // 0x8021F410: ori         $t5, $t4, 0x60
    ctx->r13 = ctx->r12 | 0X60;
    // 0x8021F414: b           L_8021F42C
    // 0x8021F418: sb          $t5, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r13;
        goto L_8021F42C;
    // 0x8021F418: sb          $t5, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r13;
    // 0x8021F41C: lbu         $t6, 0x31($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X31);
L_8021F420:
    // 0x8021F420: andi        $t7, $t6, 0xFF9F
    ctx->r15 = ctx->r14 & 0XFF9F;
    // 0x8021F424: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8021F428: sb          $t8, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r24;
L_8021F42C:
    // 0x8021F42C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_8021F430:
    // 0x8021F430: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8021F434: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8021F438: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x8021F43C: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x8021F440: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x8021F444: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8021F448: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8021F44C: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    // 0x8021F450: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x8021F454: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x8021F458: sb          $t1, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r9;
    // 0x8021F45C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8021F460: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8021F464: jal         0x80224E00
    // 0x8021F468: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x80224E00)(rdram, ctx);
        goto after_4;
    // 0x8021F468: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x8021F46C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F470: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x8021F474: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8021F478: lw          $t7, 0x30($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X30);
    // 0x8021F47C: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8021F480: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8021F484: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8021F488: bnel        $t9, $zero, L_8021F4B4
    if (ctx->r25 != 0) {
        // 0x8021F48C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8021F4B4;
    }
    goto skip_6;
    // 0x8021F48C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_6:
    // 0x8021F490: lbu         $t2, 0x2F9($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X2F9);
    // 0x8021F494: lbu         $t7, 0x31($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X31);
    // 0x8021F498: addiu       $t4, $t2, 0x2
    ctx->r12 = ADD32(ctx->r10, 0X2);
    // 0x8021F49C: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8021F4A0: andi        $t6, $t5, 0x60
    ctx->r14 = ctx->r13 & 0X60;
    // 0x8021F4A4: andi        $t8, $t7, 0xFF9F
    ctx->r24 = ctx->r15 & 0XFF9F;
    // 0x8021F4A8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8021F4AC: sb          $t9, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r25;
    // 0x8021F4B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8021F4B4:
    // 0x8021F4B4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8021F4B8: lbu         $a2, -0x3D80($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X3D80);
    // 0x8021F4BC: jal         0x802256E4
    // 0x8021F4C0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_5;
    // 0x8021F4C0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    after_5:
    // 0x8021F4C4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8021F4C8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F4CC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8021F4D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8021F4D4: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x8021F4D8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021F4DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021F4E0: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x8021F4E4: jal         0x8013A28C
    // 0x8021F4E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_6;
    // 0x8021F4E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_6:
    // 0x8021F4EC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F4F0: jal         0x80010550
    // 0x8021F4F4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_7;
    // 0x8021F4F4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_7:
    // 0x8021F4F8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8021F4FC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F500: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8021F504: lhu         $t7, 0x4($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X4);
    // 0x8021F508: ldc1        $f6, 0x28($sp)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r29, 0X28);
    // 0x8021F50C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8021F510: andi        $t6, $t7, 0x4000
    ctx->r14 = ctx->r15 & 0X4000;
    // 0x8021F514: beql        $t6, $zero, L_8021F530
    if (ctx->r14 == 0) {
        // 0x8021F518: mtc1        $at, $f9
        ctx->f_odd[(9 - 1) * 2] = ctx->r1;
            goto L_8021F530;
    }
    goto skip_7;
    // 0x8021F518: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    skip_7:
    // 0x8021F51C: jal         0x8021FB0C
    // 0x8021F520: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x8021FB0C)(rdram, ctx);
        goto after_8;
    // 0x8021F520: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_8:
    // 0x8021F524: b           L_8021F7A0
    // 0x8021F528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F7A0;
    // 0x8021F528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021F52C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
L_8021F530:
    // 0x8021F530: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8021F534: nop

    // 0x8021F538: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8021F53C: nop

    // 0x8021F540: bc1fl       L_8021F560
    if (!c1cs) {
        // 0x8021F544: lbu         $t3, 0x32($t0)
        ctx->r11 = MEM_BU(ctx->r8, 0X32);
            goto L_8021F560;
    }
    goto skip_8;
    // 0x8021F544: lbu         $t3, 0x32($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X32);
    skip_8:
    // 0x8021F548: lbu         $t8, 0x32($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X32);
    // 0x8021F54C: andi        $t9, $t8, 0xFF1F
    ctx->r25 = ctx->r24 & 0XFF1F;
    // 0x8021F550: ori         $t2, $t9, 0x20
    ctx->r10 = ctx->r25 | 0X20;
    // 0x8021F554: b           L_8021F79C
    // 0x8021F558: sb          $t2, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r10;
        goto L_8021F79C;
    // 0x8021F558: sb          $t2, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r10;
    // 0x8021F55C: lbu         $t3, 0x32($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X32);
L_8021F560:
    // 0x8021F560: andi        $t4, $t3, 0xFF1F
    ctx->r12 = ctx->r11 & 0XFF1F;
    // 0x8021F564: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x8021F568: b           L_8021F79C
    // 0x8021F56C: sb          $t5, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r13;
        goto L_8021F79C;
    // 0x8021F56C: sb          $t5, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r13;
L_8021F570:
    // 0x8021F570: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8021F574: lbu         $v1, 0x4A($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4A);
    // 0x8021F578: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8021F57C: lhu         $t6, 0x4($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X4);
    // 0x8021F580: andi        $t8, $t6, 0x4000
    ctx->r24 = ctx->r14 & 0X4000;
    // 0x8021F584: beql        $t8, $zero, L_8021F7A0
    if (ctx->r24 == 0) {
        // 0x8021F588: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021F7A0;
    }
    goto skip_9;
    // 0x8021F588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8021F58C: beq         $v1, $at, L_8021F59C
    if (ctx->r3 == ctx->r1) {
        // 0x8021F590: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8021F59C;
    }
    // 0x8021F590: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8021F594: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8021F598: bne         $v1, $at, L_8021F5B4
    if (ctx->r3 != ctx->r1) {
        // 0x8021F59C: andi        $v0, $v0, 0x7
        ctx->r2 = ctx->r2 & 0X7;
            goto L_8021F5B4;
    }
L_8021F59C:
    // 0x8021F59C: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8021F5A0: beq         $v0, $zero, L_8021F5E8
    if (ctx->r2 == 0) {
        // 0x8021F5A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8021F5E8;
    }
    // 0x8021F5A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8021F5A8: beq         $v0, $at, L_8021F5E8
    if (ctx->r2 == ctx->r1) {
        // 0x8021F5AC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8021F5E8;
    }
    // 0x8021F5AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8021F5B0: beq         $v0, $at, L_8021F5E8
    if (ctx->r2 == ctx->r1) {
        // 0x8021F5B4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8021F5E8;
    }
L_8021F5B4:
    // 0x8021F5B4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8021F5B8: beq         $v1, $at, L_8021F5C8
    if (ctx->r3 == ctx->r1) {
        // 0x8021F5BC: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8021F5C8;
    }
    // 0x8021F5BC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8021F5C0: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8021F5C4: bne         $v1, $at, L_8021F79C
    if (ctx->r3 != ctx->r1) {
        // 0x8021F5C8: andi        $v0, $v0, 0x7
        ctx->r2 = ctx->r2 & 0X7;
            goto L_8021F79C;
    }
L_8021F5C8:
    // 0x8021F5C8: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8021F5CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021F5D0: beq         $v0, $at, L_8021F5E8
    if (ctx->r2 == ctx->r1) {
        // 0x8021F5D4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8021F5E8;
    }
    // 0x8021F5D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021F5D8: beq         $v0, $at, L_8021F5E8
    if (ctx->r2 == ctx->r1) {
        // 0x8021F5DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8021F5E8;
    }
    // 0x8021F5DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021F5E0: bnel        $v0, $at, L_8021F7A0
    if (ctx->r2 != ctx->r1) {
        // 0x8021F5E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021F7A0;
    }
    goto skip_10;
    // 0x8021F5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
L_8021F5E8:
    // 0x8021F5E8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8021F5EC: jal         0x8021FB0C
    // 0x8021F5F0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x8021FB0C)(rdram, ctx);
        goto after_9;
    // 0x8021F5F0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_9:
    // 0x8021F5F4: b           L_8021F7A0
    // 0x8021F5F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F7A0;
    // 0x8021F5F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F5FC:
    // 0x8021F5FC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8021F600: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F604: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8021F608: sb          $t1, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r9;
    // 0x8021F60C: jal         0x80011258
    // 0x8021F610: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x80011258)(rdram, ctx);
        goto after_10;
    // 0x8021F610: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_10:
    // 0x8021F614: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F618: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
L_8021F61C:
    // 0x8021F61C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8021F620: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8021F624: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8021F628: lhu         $t2, 0x4($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X4);
    // 0x8021F62C: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8021F630: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x8021F634: beql        $t3, $zero, L_8021F650
    if (ctx->r11 == 0) {
        // 0x8021F638: lw          $t4, 0x30($t0)
        ctx->r12 = MEM_W(ctx->r8, 0X30);
            goto L_8021F650;
    }
    goto skip_11;
    // 0x8021F638: lw          $t4, 0x30($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X30);
    skip_11:
    // 0x8021F63C: jal         0x8021FB0C
    // 0x8021F640: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x8021FB0C)(rdram, ctx);
        goto after_11;
    // 0x8021F640: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_11:
    // 0x8021F644: b           L_8021F7A0
    // 0x8021F648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021F7A0;
    // 0x8021F648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021F64C: lw          $t4, 0x30($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X30);
L_8021F650:
    // 0x8021F650: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8021F654: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x8021F658: srl         $t7, $t5, 30
    ctx->r15 = S32(U32(ctx->r13) >> 30);
    // 0x8021F65C: bne         $t7, $zero, L_8021F684
    if (ctx->r15 != 0) {
        // 0x8021F660: addiu       $a0, $a0, 0x1C
        ctx->r4 = ADD32(ctx->r4, 0X1C);
            goto L_8021F684;
    }
    // 0x8021F660: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8021F664: lbu         $t6, 0x2F9($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X2F9);
    // 0x8021F668: lbu         $t4, 0x31($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X31);
    // 0x8021F66C: addiu       $t9, $t6, 0x2
    ctx->r25 = ADD32(ctx->r14, 0X2);
    // 0x8021F670: sll         $t2, $t9, 5
    ctx->r10 = S32(ctx->r25 << 5);
    // 0x8021F674: andi        $t3, $t2, 0x60
    ctx->r11 = ctx->r10 & 0X60;
    // 0x8021F678: andi        $t5, $t4, 0xFF9F
    ctx->r13 = ctx->r12 & 0XFF9F;
    // 0x8021F67C: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x8021F680: sb          $t7, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r15;
L_8021F684:
    // 0x8021F684: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8021F688: lbu         $a2, -0x3D80($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X3D80);
    // 0x8021F68C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8021F690: jal         0x802256E4
    // 0x8021F694: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_12;
    // 0x8021F694: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    after_12:
    // 0x8021F698: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8021F69C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F6A0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8021F6A4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8021F6A8: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8021F6AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021F6B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021F6B4: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8021F6B8: jal         0x8013A28C
    // 0x8021F6BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_13;
    // 0x8021F6BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_13:
    // 0x8021F6C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8021F6C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8021F6C8: ldc1        $f10, 0x28($sp)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r29, 0X28);
    // 0x8021F6CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8021F6D0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F6D4: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8021F6D8: nop

    // 0x8021F6DC: bc1fl       L_8021F6FC
    if (!c1cs) {
        // 0x8021F6E0: lbu         $t5, 0x32($t0)
        ctx->r13 = MEM_BU(ctx->r8, 0X32);
            goto L_8021F6FC;
    }
    goto skip_12;
    // 0x8021F6E0: lbu         $t5, 0x32($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X32);
    skip_12:
    // 0x8021F6E4: lbu         $t2, 0x32($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X32);
    // 0x8021F6E8: andi        $t4, $t2, 0xFF1F
    ctx->r12 = ctx->r10 & 0XFF1F;
    // 0x8021F6EC: ori         $t3, $t4, 0x20
    ctx->r11 = ctx->r12 | 0X20;
    // 0x8021F6F0: b           L_8021F79C
    // 0x8021F6F4: sb          $t3, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r11;
        goto L_8021F79C;
    // 0x8021F6F4: sb          $t3, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r11;
    // 0x8021F6F8: lbu         $t5, 0x32($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X32);
L_8021F6FC:
    // 0x8021F6FC: andi        $t7, $t5, 0xFF1F
    ctx->r15 = ctx->r13 & 0XFF1F;
    // 0x8021F700: ori         $t6, $t7, 0x40
    ctx->r14 = ctx->r15 | 0X40;
    // 0x8021F704: b           L_8021F79C
    // 0x8021F708: sb          $t6, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r14;
        goto L_8021F79C;
    // 0x8021F708: sb          $t6, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r14;
L_8021F70C:
    // 0x8021F70C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_8021F710:
    // 0x8021F710: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8021F714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8021F718: jal         0x802256E4
    // 0x8021F71C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_14;
    // 0x8021F71C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    after_14:
    // 0x8021F720: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x8021F724: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8021F728: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8021F72C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021F730: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8021F734: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8021F738: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8021F73C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8021F740: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8021F744: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x8021F748: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8021F74C: jal         0x80011140
    // 0x8021F750: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_15;
    // 0x8021F750: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_15:
    // 0x8021F754: beq         $v0, $zero, L_8021F79C
    if (ctx->r2 == 0) {
        // 0x8021F758: lw          $t0, 0x50($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X50);
            goto L_8021F79C;
    }
    // 0x8021F758: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021F75C: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x8021F760: sll         $t5, $t3, 9
    ctx->r13 = S32(ctx->r11 << 9);
    // 0x8021F764: srl         $t7, $t5, 30
    ctx->r15 = S32(U32(ctx->r13) >> 30);
    // 0x8021F768: bnel        $t7, $zero, L_8021F794
    if (ctx->r15 != 0) {
        // 0x8021F76C: lbu         $t6, 0x32($t0)
        ctx->r14 = MEM_BU(ctx->r8, 0X32);
            goto L_8021F794;
    }
    goto skip_13;
    // 0x8021F76C: lbu         $t6, 0x32($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X32);
    skip_13:
    // 0x8021F770: lbu         $t6, 0x2F9($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X2F9);
    // 0x8021F774: lbu         $t3, 0x31($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X31);
    // 0x8021F778: addiu       $t9, $t6, 0x2
    ctx->r25 = ADD32(ctx->r14, 0X2);
    // 0x8021F77C: sll         $t2, $t9, 5
    ctx->r10 = S32(ctx->r25 << 5);
    // 0x8021F780: andi        $t4, $t2, 0x60
    ctx->r12 = ctx->r10 & 0X60;
    // 0x8021F784: andi        $t5, $t3, 0xFF9F
    ctx->r13 = ctx->r11 & 0XFF9F;
    // 0x8021F788: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x8021F78C: sb          $t7, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r15;
    // 0x8021F790: lbu         $t6, 0x32($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X32);
L_8021F794:
    // 0x8021F794: andi        $t8, $t6, 0xFF1F
    ctx->r24 = ctx->r14 & 0XFF1F;
    // 0x8021F798: sb          $t8, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r24;
L_8021F79C:
    // 0x8021F79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021F7A0:
    // 0x8021F7A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8021F7A4: jr          $ra
    // 0x8021F7A8: nop

    return;
    // 0x8021F7A8: nop

;}
RECOMP_FUNC void M10_FUN_8021f7ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021F7AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8021F7B0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021F7B4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021F7B8: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // 0x8021F7BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8021F7C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8021F7C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8021F7C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021F7CC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8021F7D0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8021F7D4: bne         $a0, $t6, L_8021F7E8
    if (ctx->r4 != ctx->r14) {
        // 0x8021F7D8: lw          $t0, 0x5C($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X5C);
            goto L_8021F7E8;
    }
    // 0x8021F7D8: lw          $t0, 0x5C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X5C);
    // 0x8021F7DC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8021F7E0: b           L_8021F7F0
    // 0x8021F7E4: addiu       $s1, $s1, -0x3FC4
    ctx->r17 = ADD32(ctx->r17, -0X3FC4);
        goto L_8021F7F0;
    // 0x8021F7E4: addiu       $s1, $s1, -0x3FC4
    ctx->r17 = ADD32(ctx->r17, -0X3FC4);
L_8021F7E8:
    // 0x8021F7E8: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8021F7EC: addiu       $s1, $s1, -0x3C28
    ctx->r17 = ADD32(ctx->r17, -0X3C28);
L_8021F7F0:
    // 0x8021F7F0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F7F4: lh          $t7, 0x232($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X232);
    // 0x8021F7F8: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x8021F7FC: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8021F800: addiu       $t4, $t4, -0x3D68
    ctx->r12 = ADD32(ctx->r12, -0X3D68);
    // 0x8021F804: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8021F808: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8021F80C: addiu       $t8, $zero, 0x2800
    ctx->r24 = ADD32(0, 0X2800);
    // 0x8021F810: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x8021F814: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x8021F818: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8021F81C: lh          $v1, 0x12($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X12);
    // 0x8021F820: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8021F824: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8021F828: lh          $t8, 0x32A($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X32A);
    // 0x8021F82C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8021F830: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8021F834: lhu         $t7, 0x36($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X36);
    // 0x8021F838: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8021F83C: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    // 0x8021F840: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8021F844: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8021F848: bne         $t7, $at, L_8021F8C0
    if (ctx->r15 != ctx->r1) {
        // 0x8021F84C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_8021F8C0;
    }
    // 0x8021F84C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8021F850: addiu       $s0, $t0, 0x1C
    ctx->r16 = ADD32(ctx->r8, 0X1C);
    // 0x8021F854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021F858: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8021F85C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8021F860: sh          $v1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r3;
    // 0x8021F864: jal         0x802256E4
    // 0x8021F868: sh          $a3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_0;
    // 0x8021F868: sh          $a3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8021F86C: lh          $v1, 0x36($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X36);
    // 0x8021F870: lh          $a3, 0x38($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X38);
    // 0x8021F874: subu        $t3, $a3, $v1
    ctx->r11 = SUB32(ctx->r7, ctx->r3);
    // 0x8021F878: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x8021F87C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8021F880: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8021F884: addiu       $t8, $t6, 0x800
    ctx->r24 = ADD32(ctx->r14, 0X800);
    // 0x8021F888: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8021F88C: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8021F890: andi        $t2, $t9, 0x1FFF
    ctx->r10 = ctx->r25 & 0X1FFF;
    // 0x8021F894: bgez        $t2, L_8021F8A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8021F898: sra         $t3, $t2, 12
        ctx->r11 = S32(SIGNED(ctx->r10) >> 12);
            goto L_8021F8A4;
    }
    // 0x8021F898: sra         $t3, $t2, 12
    ctx->r11 = S32(SIGNED(ctx->r10) >> 12);
    // 0x8021F89C: addiu       $at, $t2, 0xFFF
    ctx->r1 = ADD32(ctx->r10, 0XFFF);
    // 0x8021F8A0: sra         $t3, $at, 12
    ctx->r11 = S32(SIGNED(ctx->r1) >> 12);
L_8021F8A4:
    // 0x8021F8A4: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8021F8A8: beql        $t4, $zero, L_8021F94C
    if (ctx->r12 == 0) {
        // 0x8021F8AC: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8021F94C;
    }
    goto skip_0;
    // 0x8021F8AC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8021F8B0: lhu         $t5, 0x6($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6);
    // 0x8021F8B4: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8021F8B8: b           L_8021F948
    // 0x8021F8BC: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
        goto L_8021F948;
    // 0x8021F8BC: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
L_8021F8C0:
    // 0x8021F8C0: subu        $a0, $a3, $v1
    ctx->r4 = SUB32(ctx->r7, ctx->r3);
    // 0x8021F8C4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8021F8C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8021F8CC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8021F8D0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8021F8D4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x8021F8D8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8021F8DC: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
    // 0x8021F8E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8021F8E4: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8021F8E8: bgez        $a0, L_8021F8F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8021F8EC: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_8021F8F4;
    }
    // 0x8021F8EC: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8021F8F0: addiu       $at, $a0, 0x7FF
    ctx->r1 = ADD32(ctx->r4, 0X7FF);
L_8021F8F4:
    // 0x8021F8F4: sra         $a0, $at, 11
    ctx->r4 = S32(SIGNED(ctx->r1) >> 11);
    // 0x8021F8F8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8021F8FC: srl         $t9, $t7, 30
    ctx->r25 = S32(U32(ctx->r15) >> 30);
    // 0x8021F900: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8021F904: bne         $t9, $at, L_8021F930
    if (ctx->r25 != ctx->r1) {
        // 0x8021F908: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8021F930;
    }
    // 0x8021F908: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8021F90C: andi        $t2, $a0, 0xFF
    ctx->r10 = ctx->r4 & 0XFF;
    // 0x8021F910: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8021F914: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x8021F918: bgez        $v0, L_8021F92C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8021F91C: andi        $v0, $v0, 0x3
        ctx->r2 = ctx->r2 & 0X3;
            goto L_8021F92C;
    }
    // 0x8021F91C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8021F920: beq         $v0, $zero, L_8021F92C
    if (ctx->r2 == 0) {
        // 0x8021F924: nop
    
            goto L_8021F92C;
    }
    // 0x8021F924: nop

    // 0x8021F928: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_8021F92C:
    // 0x8021F92C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8021F930:
    // 0x8021F930: addiu       $s0, $t0, 0x1C
    ctx->r16 = ADD32(ctx->r8, 0X1C);
    // 0x8021F934: addu        $t4, $t1, $v0
    ctx->r12 = ADD32(ctx->r9, ctx->r2);
    // 0x8021F938: lbu         $a2, 0x0($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X0);
    // 0x8021F93C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021F940: jal         0x802256E4
    // 0x8021F944: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x8021F944: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_8021F948:
    // 0x8021F948: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8021F94C:
    // 0x8021F94C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8021F950: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8021F954: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8021F958: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021F95C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021F960: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8021F964: jal         0x8013A28C
    // 0x8021F968: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x8021F968: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x8021F96C: lbu         $t8, 0x32($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X32);
    // 0x8021F970: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8021F974: sb          $t3, 0x328($s1)
    MEM_B(0X328, ctx->r17) = ctx->r11;
    // 0x8021F978: andi        $t7, $t8, 0xFF1F
    ctx->r15 = ctx->r24 & 0XFF1F;
    // 0x8021F97C: ori         $t9, $t7, 0x60
    ctx->r25 = ctx->r15 | 0X60;
    // 0x8021F980: sb          $t9, 0x32($s1)
    MEM_B(0X32, ctx->r17) = ctx->r25;
    // 0x8021F984: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8021F988: jal         0x802237B0
    // 0x8021F98C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_3;
    // 0x8021F98C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8021F990: lh          $t2, 0x44($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X44);
    // 0x8021F994: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021F998: addiu       $a1, $a1, -0x638
    ctx->r5 = ADD32(ctx->r5, -0X638);
    // 0x8021F99C: addiu       $t4, $t2, 0xA
    ctx->r12 = ADD32(ctx->r10, 0XA);
    // 0x8021F9A0: sh          $t4, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r12;
    // 0x8021F9A4: jal         0x800058DC
    // 0x8021F9A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8021F9A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8021F9AC: sb          $zero, 0x392($s1)
    MEM_B(0X392, ctx->r17) = 0;
    // 0x8021F9B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8021F9B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8021F9B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8021F9BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021F9C0: jr          $ra
    // 0x8021F9C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8021F9C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021f9c8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021f9c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021F9C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8021F9CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021F9D0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021F9D4: lw          $t7, 0xDC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XDC);
    // 0x8021F9D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021F9DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8021F9E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8021F9E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8021F9E8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8021F9EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8021F9F0: bne         $a0, $t7, L_8021FA04
    if (ctx->r4 != ctx->r15) {
        // 0x8021F9F4: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_8021FA04;
    }
    // 0x8021F9F4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8021F9F8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021F9FC: b           L_8021FA0C
    // 0x8021FA00: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
        goto L_8021FA0C;
    // 0x8021FA00: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
L_8021FA04:
    // 0x8021FA04: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8021FA08: addiu       $s0, $s0, -0x3C28
    ctx->r16 = ADD32(ctx->r16, -0X3C28);
L_8021FA0C:
    // 0x8021FA0C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8021FA10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8021FA14: blez        $t8, L_8021FA30
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8021FA18: nop
    
            goto L_8021FA30;
    }
    // 0x8021FA18: nop

    // 0x8021FA1C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8021FA20: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8021FA24: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x8021FA28: beql        $t1, $zero, L_8021FA44
    if (ctx->r9 == 0) {
        // 0x8021FA2C: lbu         $t2, 0x1031($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X1031);
            goto L_8021FA44;
    }
    goto skip_0;
    // 0x8021FA2C: lbu         $t2, 0x1031($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1031);
    skip_0:
L_8021FA30:
    // 0x8021FA30: jal         0x802233B0
    // 0x8021FA34: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x802233B0)(rdram, ctx);
        goto after_0;
    // 0x8021FA34: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x8021FA38: b           L_8021FAFC
    // 0x8021FA3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021FAFC;
    // 0x8021FA3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8021FA40: lbu         $t2, 0x1031($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1031);
L_8021FA44:
    // 0x8021FA44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021FA48: bnel        $t2, $at, L_8021FAFC
    if (ctx->r10 != ctx->r1) {
        // 0x8021FA4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8021FAFC;
    }
    goto skip_1;
    // 0x8021FA4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8021FA50: lhu         $t3, 0x30($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X30);
    // 0x8021FA54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021FA58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8021FA5C: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8021FA60: bne         $t4, $at, L_8021FA78
    if (ctx->r12 != ctx->r1) {
        // 0x8021FA64: nop
    
            goto L_8021FA78;
    }
    // 0x8021FA64: nop

    // 0x8021FA68: jal         0x8022397C
    // 0x8021FA6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8022397C)(rdram, ctx);
        goto after_1;
    // 0x8021FA6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8021FA70: b           L_8021FAFC
    // 0x8021FA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021FAFC;
    // 0x8021FA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021FA78:
    // 0x8021FA78: jal         0x802237B0
    // 0x8021FA7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_2;
    // 0x8021FA7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8021FA80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8021FA84: jal         0x80010550
    // 0x8021FA88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x8021FA88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8021FA8C: beql        $v0, $zero, L_8021FAF8
    if (ctx->r2 == 0) {
        // 0x8021FA90: sb          $zero, 0x392($s0)
        MEM_B(0X392, ctx->r16) = 0;
            goto L_8021FAF8;
    }
    goto skip_2;
    // 0x8021FA90: sb          $zero, 0x392($s0)
    MEM_B(0X392, ctx->r16) = 0;
    skip_2:
    // 0x8021FA94: lbu         $t5, 0x32($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X32);
    // 0x8021FA98: sb          $zero, 0x328($s0)
    MEM_B(0X328, ctx->r16) = 0;
    // 0x8021FA9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8021FAA0: andi        $t6, $t5, 0xFF1F
    ctx->r14 = ctx->r13 & 0XFF1F;
    // 0x8021FAA4: sb          $t6, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r14;
    // 0x8021FAA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8021FAAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8021FAB0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8021FAB4: jal         0x802256E4
    // 0x8021FAB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_4;
    // 0x8021FAB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_4:
    // 0x8021FABC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8021FAC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8021FAC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8021FAC8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8021FACC: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x8021FAD0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021FAD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021FAD8: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x8021FADC: jal         0x8013A28C
    // 0x8021FAE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_5;
    // 0x8021FAE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_5:
    // 0x8021FAE4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021FAE8: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    // 0x8021FAEC: jal         0x800058DC
    // 0x8021FAF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8021FAF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8021FAF4: sb          $zero, 0x392($s0)
    MEM_B(0X392, ctx->r16) = 0;
L_8021FAF8:
    // 0x8021FAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021FAFC:
    // 0x8021FAFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8021FB00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8021FB04: jr          $ra
    // 0x8021FB08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8021FB08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021fb0c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021fb0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FB0C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021FB10: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8021FB14: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021fb18(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021fb18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FB18: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8021FB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021FB20: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8021FB24: bne         $a0, $t6, L_8021FB38
    if (ctx->r4 != ctx->r14) {
        // 0x8021FB28: lw          $v0, 0x68($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X68);
            goto L_8021FB38;
    }
    // 0x8021FB28: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x8021FB2C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021FB30: b           L_8021FB40
    // 0x8021FB34: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
        goto L_8021FB40;
    // 0x8021FB34: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
L_8021FB38:
    // 0x8021FB38: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021FB3C: addiu       $t0, $t0, -0x3C28
    ctx->r8 = ADD32(ctx->r8, -0X3C28);
L_8021FB40:
    // 0x8021FB40: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8021FB44: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x8021FB48: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8021FB4C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8021FB50: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8021FB54: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8021FB58: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8021FB5C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8021FB60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8021FB64: lh          $t1, 0x232($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X232);
    // 0x8021FB68: addiu       $t2, $zero, 0x2800
    ctx->r10 = ADD32(0, 0X2800);
    // 0x8021FB6C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8021FB70: subu        $t5, $t2, $t1
    ctx->r13 = SUB32(ctx->r10, ctx->r9);
    // 0x8021FB74: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x8021FB78: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x8021FB7C: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8021FB80: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8021FB84: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8021FB88: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8021FB8C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8021FB90: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x8021FB94: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x8021FB98: jal         0x8001EF38
    // 0x8021FB9C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8021FB9C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8021FBA0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8021FBA4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8021FBA8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8021FBAC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8021FBB0: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8021FBB4: lh          $t2, 0x46($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X46);
    // 0x8021FBB8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8021FBBC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8021FBC0: addu        $t4, $v0, $t2
    ctx->r12 = ADD32(ctx->r2, ctx->r10);
    // 0x8021FBC4: lh          $v1, 0x12($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X12);
    // 0x8021FBC8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021FBCC: subu        $a0, $t4, $v1
    ctx->r4 = SUB32(ctx->r12, ctx->r3);
    // 0x8021FBD0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8021FBD4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8021FBD8: andi        $a1, $a0, 0x1000
    ctx->r5 = ctx->r4 & 0X1000;
    // 0x8021FBDC: beq         $a1, $zero, L_8021FBF0
    if (ctx->r5 == 0) {
        // 0x8021FBE0: add.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_8021FBF0;
    }
    // 0x8021FBE0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8021FBE4: andi        $v0, $a0, 0x1FFF
    ctx->r2 = ctx->r4 & 0X1FFF;
    // 0x8021FBE8: b           L_8021FBF8
    // 0x8021FBEC: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_8021FBF8;
    // 0x8021FBEC: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_8021FBF0:
    // 0x8021FBF0: andi        $v0, $a0, 0x1FFF
    ctx->r2 = ctx->r4 & 0X1FFF;
    // 0x8021FBF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8021FBF8:
    // 0x8021FBF8: bgez        $v1, L_8021FC2C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8021FBFC: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_8021FC2C;
    }
    // 0x8021FBFC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8021FC00: beq         $a1, $zero, L_8021FC1C
    if (ctx->r5 == 0) {
        // 0x8021FC04: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021FC1C;
    }
    // 0x8021FC04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021FC08: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
    // 0x8021FC0C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8021FC10: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8021FC14: b           L_8021FC44
    // 0x8021FC18: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8021FC44;
    // 0x8021FC18: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8021FC1C:
    // 0x8021FC1C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8021FC20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8021FC24: b           L_8021FC44
    // 0x8021FC28: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8021FC44;
    // 0x8021FC28: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8021FC2C:
    // 0x8021FC2C: beq         $a1, $zero, L_8021FC3C
    if (ctx->r5 == 0) {
        // 0x8021FC30: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8021FC3C;
    }
    // 0x8021FC30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8021FC34: b           L_8021FC3C
    // 0x8021FC38: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_8021FC3C;
    // 0x8021FC38: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_8021FC3C:
    // 0x8021FC3C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8021FC40: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8021FC44:
    // 0x8021FC44: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8021FC48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8021FC4C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8021FC50: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x8021FC54: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8021FC58: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8021FC5C: bc1fl       L_8021FC94
    if (!c1cs) {
        // 0x8021FC60: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8021FC94;
    }
    goto skip_0;
    // 0x8021FC60: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_0:
    // 0x8021FC64: beql        $at, $zero, L_8021FC7C
    if (ctx->r1 == 0) {
        // 0x8021FC68: slti        $at, $v0, 0xC01
        ctx->r1 = SIGNED(ctx->r2) < 0XC01 ? 1 : 0;
            goto L_8021FC7C;
    }
    goto skip_1;
    // 0x8021FC68: slti        $at, $v0, 0xC01
    ctx->r1 = SIGNED(ctx->r2) < 0XC01 ? 1 : 0;
    skip_1:
    // 0x8021FC6C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8021FC70: b           L_8021FC88
    // 0x8021FC74: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
        goto L_8021FC88;
    // 0x8021FC74: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // 0x8021FC78: slti        $at, $v0, 0xC01
    ctx->r1 = SIGNED(ctx->r2) < 0XC01 ? 1 : 0;
L_8021FC7C:
    // 0x8021FC7C: bne         $at, $zero, L_8021FC88
    if (ctx->r1 != 0) {
        // 0x8021FC80: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_8021FC88;
    }
    // 0x8021FC80: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8021FC84: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
L_8021FC88:
    // 0x8021FC88: b           L_8021FC94
    // 0x8021FC8C: lhu         $v0, 0x3E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3E);
        goto L_8021FC94;
    // 0x8021FC8C: lhu         $v0, 0x3E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3E);
    // 0x8021FC90: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8021FC94:
    // 0x8021FC94: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8021FC98: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8021FC9C: jal         0x802256E4
    // 0x8021FCA0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x8021FCA0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    after_1:
    // 0x8021FCA4: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x8021FCA8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8021FCAC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8021FCB0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8021FCB4: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x8021FCB8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8021FCBC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8021FCC0: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x8021FCC4: jal         0x8013A28C
    // 0x8021FCC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x8021FCC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x8021FCCC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8021FCD0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021FCD4: addiu       $a1, $a1, -0x300
    ctx->r5 = ADD32(ctx->r5, -0X300);
    // 0x8021FCD8: lbu         $t8, 0x32($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X32);
    // 0x8021FCDC: andi        $t9, $t8, 0xFF1F
    ctx->r25 = ctx->r24 & 0XFF1F;
    // 0x8021FCE0: ori         $t2, $t9, 0x20
    ctx->r10 = ctx->r25 | 0X20;
    // 0x8021FCE4: sb          $t2, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r10;
    // 0x8021FCE8: jal         0x800058DC
    // 0x8021FCEC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021FCEC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x8021FCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021FCF4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8021FCF8: jr          $ra
    // 0x8021FCFC: nop

    return;
    // 0x8021FCFC: nop

;}
RECOMP_FUNC void M10_FUN_8021fd00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FD00: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8021FD04: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8021FD08: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021fd0c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021fd0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FD0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8021FD10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8021FD14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8021FD18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8021FD1C: bne         $a0, $t6, L_8021FD30
    if (ctx->r4 != ctx->r14) {
        // 0x8021FD20: lw          $a3, 0x5C($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X5C);
            goto L_8021FD30;
    }
    // 0x8021FD20: lw          $a3, 0x5C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X5C);
    // 0x8021FD24: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021FD28: b           L_8021FD38
    // 0x8021FD2C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8021FD38;
    // 0x8021FD2C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8021FD30:
    // 0x8021FD30: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021FD34: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8021FD38:
    // 0x8021FD38: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x8021FD3C: lbu         $t7, 0x1031($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1031);
    // 0x8021FD40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021FD44: bnel        $t7, $at, L_8021FE08
    if (ctx->r15 != ctx->r1) {
        // 0x8021FD48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8021FE08;
    }
    goto skip_0;
    // 0x8021FD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8021FD4C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x8021FD50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8021FD54: blez        $t8, L_8021FD70
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8021FD58: nop
    
            goto L_8021FD70;
    }
    // 0x8021FD58: nop

    // 0x8021FD5C: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x8021FD60: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8021FD64: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x8021FD68: beql        $t1, $zero, L_8021FD84
    if (ctx->r9 == 0) {
        // 0x8021FD6C: lhu         $t2, 0x30($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X30);
            goto L_8021FD84;
    }
    goto skip_1;
    // 0x8021FD6C: lhu         $t2, 0x30($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X30);
    skip_1:
L_8021FD70:
    // 0x8021FD70: jal         0x802233B0
    // 0x8021FD74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x802233B0)(rdram, ctx);
        goto after_0;
    // 0x8021FD74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8021FD78: b           L_8021FE08
    // 0x8021FD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021FE08;
    // 0x8021FD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8021FD80: lhu         $t2, 0x30($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X30);
L_8021FD84:
    // 0x8021FD84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8021FD88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8021FD8C: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8021FD90: bne         $t3, $at, L_8021FDA8
    if (ctx->r11 != ctx->r1) {
        // 0x8021FD94: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_8021FDA8;
    }
    // 0x8021FD94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8021FD98: jal         0x8022397C
    // 0x8021FD9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x8022397C)(rdram, ctx);
        goto after_1;
    // 0x8021FD9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8021FDA0: b           L_8021FE08
    // 0x8021FDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8021FE08;
    // 0x8021FDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021FDA8:
    // 0x8021FDA8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8021FDAC: jal         0x80010550
    // 0x8021FDB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x8021FDB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8021FDB4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8021FDB8: beq         $v0, $zero, L_8021FE04
    if (ctx->r2 == 0) {
        // 0x8021FDBC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8021FE04;
    }
    // 0x8021FDBC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8021FDC0: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x8021FDC4: lbu         $t0, 0x31($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X31);
    // 0x8021FDC8: lbu         $t3, 0x32($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X32);
    // 0x8021FDCC: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x8021FDD0: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x8021FDD4: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8021FDD8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8021FDDC: andi        $t9, $t8, 0x60
    ctx->r25 = ctx->r24 & 0X60;
    // 0x8021FDE0: andi        $t1, $t0, 0xFF9F
    ctx->r9 = ctx->r8 & 0XFF9F;
    // 0x8021FDE4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8021FDE8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021FDEC: andi        $t4, $t3, 0xFF1F
    ctx->r12 = ctx->r11 & 0XFF1F;
    // 0x8021FDF0: sb          $t2, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r10;
    // 0x8021FDF4: sb          $t4, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r12;
    // 0x8021FDF8: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    // 0x8021FDFC: jal         0x800058DC
    // 0x8021FE00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8021FE00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_8021FE04:
    // 0x8021FE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8021FE08:
    // 0x8021FE08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8021FE0C: jr          $ra
    // 0x8021FE10: nop

    return;
    // 0x8021FE10: nop

;}
RECOMP_FUNC void M10_FUN_8021fe14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FE14: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8021FE18: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x8021FE1C: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8021fe20(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8021fe20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FE20: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8021FE24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8021FE28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8021FE2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021FE30: bne         $a0, $t6, L_8021FE44
    if (ctx->r4 != ctx->r14) {
        // 0x8021FE34: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_8021FE44;
    }
    // 0x8021FE34: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8021FE38: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021FE3C: b           L_8021FE4C
    // 0x8021FE40: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8021FE4C;
    // 0x8021FE40: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8021FE44:
    // 0x8021FE44: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8021FE48: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8021FE4C:
    // 0x8021FE4C: lh          $t7, 0x232($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X232);
    // 0x8021FE50: addiu       $t8, $zero, 0x2800
    ctx->r24 = ADD32(0, 0X2800);
    // 0x8021FE54: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8021FE58: subu        $t1, $t8, $t7
    ctx->r9 = SUB32(ctx->r24, ctx->r15);
    // 0x8021FE5C: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x8021FE60: sh          $t2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r10;
    // 0x8021FE64: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x8021FE68: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8021FE6C: lh          $t5, 0x8($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X8);
    // 0x8021FE70: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8021FE74: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8021FE78: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8021FE7C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8021FE80: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8021FE84: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8021FE88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8021FE8C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8021FE90: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8021FE94: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8021FE98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8021FE9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021FEA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8021FEA4: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8021FEA8: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8021FEAC: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8021FEB0: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8021FEB4: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x8021FEB8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8021FEBC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8021FEC0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8021FEC4: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8021FEC8: nop

    // 0x8021FECC: bc1f        L_8021FF18
    if (!c1cs) {
        // 0x8021FED0: nop
    
            goto L_8021FF18;
    }
    // 0x8021FED0: nop

    // 0x8021FED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021FED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8021FEDC: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x8021FEE0: jal         0x802237B0
    // 0x8021FEE4: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x8021FEE4: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8021FEE8: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8021FEEC: jal         0x8001EF38
    // 0x8021FEF0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8021FEF0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8021FEF4: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x8021FEF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021FEFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8021FF00: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x8021FF04: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8021FF08: jal         0x8022038C
    // 0x8021FF0C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8022038C)(rdram, ctx);
        goto after_2;
    // 0x8021FF0C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_2:
    // 0x8021FF10: b           L_8021FF68
    // 0x8021FF14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021FF68;
    // 0x8021FF14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021FF18:
    // 0x8021FF18: jal         0x802237B0
    // 0x8021FF1C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_3;
    // 0x8021FF1C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x8021FF20: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8021FF24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8021FF28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8021FF2C: lbu         $t8, 0x390($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X390);
    // 0x8021FF30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8021FF34: bne         $t8, $at, L_8021FF4C
    if (ctx->r24 != ctx->r1) {
        // 0x8021FF38: nop
    
            goto L_8021FF4C;
    }
    // 0x8021FF38: nop

    // 0x8021FF3C: jal         0x8021FF78
    // 0x8021FF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8021FF78)(rdram, ctx);
        goto after_4;
    // 0x8021FF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8021FF44: b           L_8021FF68
    // 0x8021FF48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8021FF68;
    // 0x8021FF48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021FF4C:
    // 0x8021FF4C: jal         0x8021ECD4
    // 0x8021FF50: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x8021ECD4)(rdram, ctx);
        goto after_5;
    // 0x8021FF50: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x8021FF54: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8021FF58: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    // 0x8021FF5C: jal         0x800058DC
    // 0x8021FF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8021FF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8021FF64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021FF68:
    // 0x8021FF68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8021FF6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8021FF70: jr          $ra
    // 0x8021FF74: nop

    return;
    // 0x8021FF74: nop

;}
RECOMP_FUNC void M10_FUN_8021ff78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8021FF78: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8021FF7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8021FF80: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8021FF84: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8021FF88: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8021FF8C: lw          $t9, -0x4334($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4334);
    // 0x8021FF90: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8021FF94: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8021FF98: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021FF9C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8021FFA0: bne         $a0, $t9, L_8021FFB4
    if (ctx->r4 != ctx->r25) {
        // 0x8021FFA4: lw          $v0, 0x5C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X5C);
            goto L_8021FFB4;
    }
    // 0x8021FFA4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8021FFA8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8021FFAC: b           L_8021FFB8
    // 0x8021FFB0: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
        goto L_8021FFB8;
    // 0x8021FFB0: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
L_8021FFB4:
    // 0x8021FFB4: addiu       $t0, $t0, -0x3C28
    ctx->r8 = ADD32(ctx->r8, -0X3C28);
L_8021FFB8:
    // 0x8021FFB8: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x8021FFBC: lui         $a2, 0x191
    ctx->r6 = S32(0X191 << 16);
    // 0x8021FFC0: ori         $a2, $a2, 0xAA
    ctx->r6 = ctx->r6 | 0XAA;
    // 0x8021FFC4: bne         $a2, $t1, L_8021FFFC
    if (ctx->r6 != ctx->r9) {
        // 0x8021FFC8: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_8021FFFC;
    }
    // 0x8021FFC8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8021FFCC: lbu         $t2, 0x32($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X32);
    // 0x8021FFD0: addiu       $a1, $v0, 0x22
    ctx->r5 = ADD32(ctx->r2, 0X22);
    // 0x8021FFD4: andi        $t3, $t2, 0xFF1F
    ctx->r11 = ctx->r10 & 0XFF1F;
    // 0x8021FFD8: sb          $t3, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r11;
    // 0x8021FFDC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8021FFE0: jal         0x800111E0
    // 0x8021FFE4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x800111E0)(rdram, ctx);
        goto after_0;
    // 0x8021FFE4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_0:
    // 0x8021FFE8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8021FFEC: jal         0x80010550
    // 0x8021FFF0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x8021FFF0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8021FFF4: b           L_80220380
    // 0x8021FFF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80220380;
    // 0x8021FFF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8021FFFC:
    // 0x8021FFFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80220000: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80220004: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    // 0x80220008: jal         0x80225664
    // 0x8022000C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80225664)(rdram, ctx);
        goto after_2;
    // 0x8022000C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_2:
    // 0x80220010: lhu         $t4, 0x4A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4A);
    // 0x80220014: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80220018: ori         $t5, $t4, 0x100
    ctx->r13 = ctx->r12 | 0X100;
    // 0x8022001C: jal         0x8022560C
    // 0x80220020: sh          $t5, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_3;
    // 0x80220020: sh          $t5, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r13;
    after_3:
    // 0x80220024: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x80220028: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8022002C: sb          $v0, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r2;
    // 0x80220030: bne         $at, $zero, L_8022004C
    if (ctx->r1 != 0) {
        // 0x80220034: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8022004C;
    }
    // 0x80220034: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80220038: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8022003C: beql        $v0, $at, L_8022034C
    if (ctx->r2 == ctx->r1) {
        // 0x80220040: addiu       $t8, $sp, 0x44
        ctx->r24 = ADD32(ctx->r29, 0X44);
            goto L_8022034C;
    }
    goto skip_0;
    // 0x80220040: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    skip_0:
    // 0x80220044: b           L_8022034C
    // 0x80220048: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
        goto L_8022034C;
    // 0x80220048: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
L_8022004C:
    // 0x8022004C: sltiu       $at, $v1, 0x1D
    ctx->r1 = ctx->r3 < 0X1D ? 1 : 0;
    // 0x80220050: beq         $at, $zero, L_80220348
    if (ctx->r1 == 0) {
        // 0x80220054: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80220348;
    }
    // 0x80220054: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80220058: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022005C: addu        $at, $at, $t6
    gpr jr_addend_80220064 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80220060: lw          $t6, -0x14F8($at)
    ctx->r14 = ADD32(ctx->r1, -0X14F8);
    // 0x80220064: jr          $t6
    // 0x80220068: nop

    switch (jr_addend_80220064 >> 2) {
        case 0: goto L_80220348; break;
        case 1: goto L_802201A8; break;
        case 2: goto L_80220348; break;
        case 3: goto L_80220348; break;
        case 4: goto L_80220204; break;
        case 5: goto L_80220204; break;
        case 6: goto L_80220204; break;
        case 7: goto L_8022006C; break;
        case 8: goto L_8022006C; break;
        case 9: goto L_8022006C; break;
        case 10: goto L_80220348; break;
        case 11: goto L_80220348; break;
        case 12: goto L_80220348; break;
        case 13: goto L_80220348; break;
        case 14: goto L_80220348; break;
        case 15: goto L_80220348; break;
        case 16: goto L_80220348; break;
        case 17: goto L_80220348; break;
        case 18: goto L_80220348; break;
        case 19: goto L_80220348; break;
        case 20: goto L_80220348; break;
        case 21: goto L_80220348; break;
        case 22: goto L_80220348; break;
        case 23: goto L_80220348; break;
        case 24: goto L_80220348; break;
        case 25: goto L_80220348; break;
        case 26: goto L_80220348; break;
        case 27: goto L_80220348; break;
        case 28: goto L_80220348; break;
        default: switch_error(__func__, 0x80220064, 0x8023EB08);
    }
    // 0x80220068: nop

L_8022006C:
    // 0x8022006C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80220070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80220074: jal         0x802237B0
    // 0x80220078: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_4;
    // 0x80220078: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_4:
    // 0x8022007C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80220080: lbu         $t7, 0x31($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X31);
    // 0x80220084: andi        $t8, $t7, 0xFF9F
    ctx->r24 = ctx->r15 & 0XFF9F;
    // 0x80220088: sb          $t8, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r24;
    // 0x8022008C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80220090: jal         0x80010550
    // 0x80220094: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x80220094: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x80220098: beql        $v0, $zero, L_80220380
    if (ctx->r2 == 0) {
        // 0x8022009C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80220380;
    }
    goto skip_1;
    // 0x8022009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x802200A0: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x802200A4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x802200A8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x802200AC: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    // 0x802200B0: jal         0x80011328
    // 0x802200B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80011328)(rdram, ctx);
        goto after_6;
    // 0x802200B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x802200B8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x802200BC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x802200C0: jal         0x802256E4
    // 0x802200C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_7;
    // 0x802200C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x802200C8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x802200CC: lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X41);
    // 0x802200D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x802200D4: lhu         $t1, 0x6($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X6);
    // 0x802200D8: bne         $v1, $at, L_802200FC
    if (ctx->r3 != ctx->r1) {
        // 0x802200DC: sh          $t1, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r9;
            goto L_802200FC;
    }
    // 0x802200DC: sh          $t1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r9;
    // 0x802200E0: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x802200E4: beq         $t2, $zero, L_802200F4
    if (ctx->r10 == 0) {
        // 0x802200E8: nop
    
            goto L_802200F4;
    }
    // 0x802200E8: nop

    // 0x802200EC: b           L_8022012C
    // 0x802200F0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
        goto L_8022012C;
    // 0x802200F0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
L_802200F4:
    // 0x802200F4: b           L_8022012C
    // 0x802200F8: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
        goto L_8022012C;
    // 0x802200F8: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
L_802200FC:
    // 0x802200FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80220100: bne         $v1, $at, L_8022012C
    if (ctx->r3 != ctx->r1) {
        // 0x80220104: addiu       $a1, $zero, 0x1000
        ctx->r5 = ADD32(0, 0X1000);
            goto L_8022012C;
    }
    // 0x80220104: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80220108: lhu         $v0, 0x4A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X4A);
    // 0x8022010C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80220110: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x80220114: beq         $t3, $zero, L_80220124
    if (ctx->r11 == 0) {
        // 0x80220118: xori        $t4, $v0, 0x10
        ctx->r12 = ctx->r2 ^ 0X10;
            goto L_80220124;
    }
    // 0x80220118: xori        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 ^ 0X10;
    // 0x8022011C: b           L_80220124
    // 0x80220120: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
        goto L_80220124;
    // 0x80220120: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
L_80220124:
    // 0x80220124: b           L_8022012C
    // 0x80220128: sh          $t4, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r12;
        goto L_8022012C;
    // 0x80220128: sh          $t4, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r12;
L_8022012C:
    // 0x8022012C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80220130: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    // 0x80220134: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x80220138: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x8022013C: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x80220140: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x80220144: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x80220148: jal         0x80224E00
    // 0x8022014C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x80224E00)(rdram, ctx);
        goto after_8;
    // 0x8022014C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_8:
    // 0x80220150: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x80220154: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80220158: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8022015C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80220160: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80220164: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80220168: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8022016C: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80220170: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80220174: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220178: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8022017C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80220180: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80220184: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80220188: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8022018C: jal         0x8013A28C
    // 0x80220190: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_9;
    // 0x80220190: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_9:
    // 0x80220194: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220198: jal         0x80010550
    // 0x8022019C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_10;
    // 0x8022019C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x802201A0: b           L_80220380
    // 0x802201A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80220380;
    // 0x802201A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802201A8:
    // 0x802201A8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x802201AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802201B0: jal         0x802237B0
    // 0x802201B4: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_11;
    // 0x802201B4: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_11:
    // 0x802201B8: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x802201BC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x802201C0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x802201C4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x802201C8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x802201CC: lw          $a3, 0x4($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X4);
    // 0x802201D0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x802201D4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x802201D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x802201DC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x802201E0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x802201E4: jal         0x80011140
    // 0x802201E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_12;
    // 0x802201E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_12:
    // 0x802201EC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x802201F0: lbu         $t9, 0x32($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X32);
    // 0x802201F4: andi        $t1, $t9, 0xFF1F
    ctx->r9 = ctx->r25 & 0XFF1F;
    // 0x802201F8: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x802201FC: b           L_8022037C
    // 0x80220200: sb          $t2, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r10;
        goto L_8022037C;
    // 0x80220200: sb          $t2, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r10;
L_80220204:
    // 0x80220204: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80220208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8022020C: jal         0x802237B0
    // 0x80220210: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_13;
    // 0x80220210: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_13:
    // 0x80220214: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220218: jal         0x80010550
    // 0x8022021C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_14;
    // 0x8022021C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_14:
    // 0x80220220: beq         $v0, $zero, L_8022037C
    if (ctx->r2 == 0) {
        // 0x80220224: lw          $t0, 0x54($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X54);
            goto L_8022037C;
    }
    // 0x80220224: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80220228: lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X41);
    // 0x8022022C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80220230: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80220234: bnel        $v1, $at, L_80220270
    if (ctx->r3 != ctx->r1) {
        // 0x80220238: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80220270;
    }
    goto skip_2;
    // 0x80220238: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_2:
    // 0x8022023C: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x80220240: lbu         $t9, 0x31($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X31);
    // 0x80220244: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x80220248: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x8022024C: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x80220250: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x80220254: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80220258: andi        $t8, $t7, 0x60
    ctx->r24 = ctx->r15 & 0X60;
    // 0x8022025C: andi        $t1, $t9, 0xFF9F
    ctx->r9 = ctx->r25 & 0XFF9F;
    // 0x80220260: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80220264: b           L_802202D0
    // 0x80220268: sb          $t2, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r10;
        goto L_802202D0;
    // 0x80220268: sb          $t2, 0x31($t0)
    MEM_B(0X31, ctx->r8) = ctx->r10;
    // 0x8022026C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80220270:
    // 0x80220270: bnel        $v1, $at, L_802202A4
    if (ctx->r3 != ctx->r1) {
        // 0x80220274: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_802202A4;
    }
    goto skip_3;
    // 0x80220274: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_3:
    // 0x80220278: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x8022027C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80220280: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80220284: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x80220288: bne         $t5, $at, L_80220298
    if (ctx->r13 != ctx->r1) {
        // 0x8022028C: nop
    
            goto L_80220298;
    }
    // 0x8022028C: nop

    // 0x80220290: b           L_802202D0
    // 0x80220294: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
        goto L_802202D0;
    // 0x80220294: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
L_80220298:
    // 0x80220298: b           L_802202D0
    // 0x8022029C: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
        goto L_802202D0;
    // 0x8022029C: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
    // 0x802202A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_802202A4:
    // 0x802202A4: bnel        $v1, $at, L_802202D4
    if (ctx->r3 != ctx->r1) {
        // 0x802202A8: lw          $v1, 0x64($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X64);
            goto L_802202D4;
    }
    goto skip_4;
    // 0x802202A8: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    skip_4:
    // 0x802202AC: lw          $t6, 0x30($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X30);
    // 0x802202B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802202B4: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
    // 0x802202B8: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x802202BC: srl         $t9, $t7, 30
    ctx->r25 = S32(U32(ctx->r15) >> 30);
    // 0x802202C0: beq         $t9, $at, L_802202D0
    if (ctx->r25 == ctx->r1) {
        // 0x802202C4: nop
    
            goto L_802202D0;
    }
    // 0x802202C4: nop

    // 0x802202C8: b           L_802202D0
    // 0x802202CC: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
        goto L_802202D0;
    // 0x802202CC: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
L_802202D0:
    // 0x802202D0: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_802202D4:
    // 0x802202D4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x802202D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802202DC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x802202E0: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x802202E4: lh          $t1, 0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X12);
    // 0x802202E8: addu        $t2, $t1, $a3
    ctx->r10 = ADD32(ctx->r9, ctx->r7);
    // 0x802202EC: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x802202F0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x802202F4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x802202F8: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x802202FC: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x80220300: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x80220304: jal         0x802256E4
    // 0x80220308: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_15;
    // 0x80220308: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_15:
    // 0x8022030C: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80220310: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80220314: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220318: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8022031C: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x80220320: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80220324: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80220328: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8022032C: jal         0x8013A28C
    // 0x80220330: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_16;
    // 0x80220330: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_16:
    // 0x80220334: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220338: jal         0x80010550
    // 0x8022033C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_17;
    // 0x8022033C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_17:
    // 0x80220340: b           L_80220380
    // 0x80220344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80220380;
    // 0x80220344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80220348:
    // 0x80220348: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
L_8022034C:
    // 0x8022034C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80220350: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80220354: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220358: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8022035C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80220360: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80220364: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80220368: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8022036C: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x80220370: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80220374: jal         0x80011140
    // 0x80220378: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_18;
    // 0x80220378: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_18:
L_8022037C:
    // 0x8022037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80220380:
    // 0x80220380: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80220384: jr          $ra
    // 0x80220388: nop

    return;
    // 0x80220388: nop

;}
RECOMP_FUNC void M10_FUN_8022038c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022038C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80220390: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80220394: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80220398: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8022039C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x802203A0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x802203A4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802203A8: lw          $t0, -0x4334($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4334);
    // 0x802203AC: lw          $t9, 0x5C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X5C);
    // 0x802203B0: lw          $a3, 0x2C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X2C);
    // 0x802203B4: bne         $a0, $t0, L_802203CC
    if (ctx->r4 != ctx->r8) {
        // 0x802203B8: sw          $t9, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r25;
            goto L_802203CC;
    }
    // 0x802203B8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x802203BC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x802203C0: addiu       $t1, $t1, -0x3FC4
    ctx->r9 = ADD32(ctx->r9, -0X3FC4);
    // 0x802203C4: b           L_802203D8
    // 0x802203C8: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
        goto L_802203D8;
    // 0x802203C8: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
L_802203CC:
    // 0x802203CC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x802203D0: addiu       $t2, $t2, -0x3C28
    ctx->r10 = ADD32(ctx->r10, -0X3C28);
    // 0x802203D4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
L_802203D8:
    // 0x802203D8: lh          $t3, 0x12($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X12);
    // 0x802203DC: lh          $t4, 0x6A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6A);
    // 0x802203E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x802203E4: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x802203E8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802203EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802203F0: andi        $t5, $v0, 0x1000
    ctx->r13 = ctx->r2 & 0X1000;
    // 0x802203F4: beq         $t5, $zero, L_80220410
    if (ctx->r13 == 0) {
        // 0x802203F8: andi        $a2, $v0, 0x1FFF
        ctx->r6 = ctx->r2 & 0X1FFF;
            goto L_80220410;
    }
    // 0x802203F8: andi        $a2, $v0, 0x1FFF
    ctx->r6 = ctx->r2 & 0X1FFF;
    // 0x802203FC: andi        $a2, $v0, 0x1FFF
    ctx->r6 = ctx->r2 & 0X1FFF;
    // 0x80220400: addiu       $a2, $a2, -0x2000
    ctx->r6 = ADD32(ctx->r6, -0X2000);
    // 0x80220404: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80220408: b           L_80220418
    // 0x8022040C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_80220418;
    // 0x8022040C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_80220410:
    // 0x80220410: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80220414: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_80220418:
    // 0x80220418: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x8022041C: jal         0x8022560C
    // 0x80220420: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_0;
    // 0x80220420: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80220424: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x80220428: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x8022042C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80220430: sb          $v0, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r2;
    // 0x80220434: bne         $at, $zero, L_80220450
    if (ctx->r1 != 0) {
        // 0x80220438: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80220450;
    }
    // 0x80220438: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8022043C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80220440: beql        $v0, $at, L_8022079C
    if (ctx->r2 == ctx->r1) {
        // 0x80220444: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_8022079C;
    }
    goto skip_0;
    // 0x80220444: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80220448: b           L_8022079C
    // 0x8022044C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_8022079C;
    // 0x8022044C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80220450:
    // 0x80220450: sltiu       $at, $v1, 0x1D
    ctx->r1 = ctx->r3 < 0X1D ? 1 : 0;
    // 0x80220454: beq         $at, $zero, L_80220798
    if (ctx->r1 == 0) {
        // 0x80220458: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80220798;
    }
    // 0x80220458: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8022045C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80220460: addu        $at, $at, $t6
    gpr jr_addend_80220468 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80220464: lw          $t6, -0x1484($at)
    ctx->r14 = ADD32(ctx->r1, -0X1484);
    // 0x80220468: jr          $t6
    // 0x8022046C: nop

    switch (jr_addend_80220468 >> 2) {
        case 0: goto L_80220798; break;
        case 1: goto L_802205C4; break;
        case 2: goto L_80220798; break;
        case 3: goto L_80220798; break;
        case 4: goto L_8022065C; break;
        case 5: goto L_8022065C; break;
        case 6: goto L_8022065C; break;
        case 7: goto L_80220470; break;
        case 8: goto L_80220470; break;
        case 9: goto L_80220470; break;
        case 10: goto L_80220798; break;
        case 11: goto L_80220798; break;
        case 12: goto L_80220798; break;
        case 13: goto L_80220798; break;
        case 14: goto L_80220798; break;
        case 15: goto L_80220798; break;
        case 16: goto L_80220798; break;
        case 17: goto L_80220798; break;
        case 18: goto L_80220798; break;
        case 19: goto L_80220798; break;
        case 20: goto L_80220798; break;
        case 21: goto L_80220798; break;
        case 22: goto L_80220798; break;
        case 23: goto L_80220798; break;
        case 24: goto L_80220798; break;
        case 25: goto L_80220798; break;
        case 26: goto L_80220798; break;
        case 27: goto L_80220798; break;
        case 28: goto L_80220798; break;
        default: switch_error(__func__, 0x80220468, 0x8023EB7C);
    }
    // 0x8022046C: nop

L_80220470:
    // 0x80220470: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80220474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80220478: jal         0x802237B0
    // 0x8022047C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_1;
    // 0x8022047C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80220480: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80220484: lbu         $t7, 0x31($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X31);
    // 0x80220488: andi        $t9, $t7, 0xFF9F
    ctx->r25 = ctx->r15 & 0XFF9F;
    // 0x8022048C: sb          $t9, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r25;
    // 0x80220490: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80220494: jal         0x80010550
    // 0x80220498: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x80220498: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_2:
    // 0x8022049C: beq         $v0, $zero, L_802208A0
    if (ctx->r2 == 0) {
        // 0x802204A0: lw          $a3, 0x5C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X5C);
            goto L_802208A0;
    }
    // 0x802204A0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x802204A4: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x802204A8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x802204AC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x802204B0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x802204B4: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    // 0x802204B8: jal         0x80011328
    // 0x802204BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80011328)(rdram, ctx);
        goto after_3;
    // 0x802204BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x802204C0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x802204C4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x802204C8: jal         0x802256E4
    // 0x802204CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_4;
    // 0x802204CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x802204D0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x802204D4: lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X41);
    // 0x802204D8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x802204DC: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x802204E0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x802204E4: bne         $v1, $at, L_80220508
    if (ctx->r3 != ctx->r1) {
        // 0x802204E8: sh          $t0, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r8;
            goto L_80220508;
    }
    // 0x802204E8: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    // 0x802204EC: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x802204F0: beq         $t1, $zero, L_80220500
    if (ctx->r9 == 0) {
        // 0x802204F4: nop
    
            goto L_80220500;
    }
    // 0x802204F4: nop

    // 0x802204F8: b           L_80220538
    // 0x802204FC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
        goto L_80220538;
    // 0x802204FC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
L_80220500:
    // 0x80220500: b           L_80220538
    // 0x80220504: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
        goto L_80220538;
    // 0x80220504: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
L_80220508:
    // 0x80220508: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8022050C: bne         $v1, $at, L_80220538
    if (ctx->r3 != ctx->r1) {
        // 0x80220510: addiu       $a1, $zero, 0x1000
        ctx->r5 = ADD32(0, 0X1000);
            goto L_80220538;
    }
    // 0x80220510: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80220514: lhu         $v0, 0x4A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X4A);
    // 0x80220518: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8022051C: andi        $t2, $v0, 0x10
    ctx->r10 = ctx->r2 & 0X10;
    // 0x80220520: beq         $t2, $zero, L_80220530
    if (ctx->r10 == 0) {
        // 0x80220524: xori        $t3, $v0, 0x10
        ctx->r11 = ctx->r2 ^ 0X10;
            goto L_80220530;
    }
    // 0x80220524: xori        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 ^ 0X10;
    // 0x80220528: b           L_80220530
    // 0x8022052C: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
        goto L_80220530;
    // 0x8022052C: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
L_80220530:
    // 0x80220530: b           L_80220538
    // 0x80220534: sh          $t3, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r11;
        goto L_80220538;
    // 0x80220534: sh          $t3, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r11;
L_80220538:
    // 0x80220538: lh          $t4, 0x12($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X12);
    // 0x8022053C: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x80220540: sh          $t5, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r13;
    // 0x80220544: lh          $t6, 0x12($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X12);
    // 0x80220548: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x8022054C: sh          $t7, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r15;
    // 0x80220550: jal         0x80224E00
    // 0x80220554: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x80224E00)(rdram, ctx);
        goto after_5;
    // 0x80220554: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_5:
    // 0x80220558: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x8022055C: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x80220560: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80220564: addiu       $t2, $sp, 0x44
    ctx->r10 = ADD32(ctx->r29, 0X44);
    // 0x80220568: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8022056C: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80220570: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80220574: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x80220578: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x8022057C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80220580: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220584: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80220588: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x8022058C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80220590: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80220594: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x80220598: jal         0x8013A28C
    // 0x8022059C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_6;
    // 0x8022059C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_6:
    // 0x802205A0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x802205A4: jal         0x80010550
    // 0x802205A8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_7;
    // 0x802205A8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_7:
    // 0x802205AC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x802205B0: lbu         $t5, 0x32($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X32);
    // 0x802205B4: andi        $t6, $t5, 0xFF1F
    ctx->r14 = ctx->r13 & 0XFF1F;
    // 0x802205B8: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x802205BC: b           L_802208A0
    // 0x802205C0: sb          $t7, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r15;
        goto L_802208A0;
    // 0x802205C0: sb          $t7, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r15;
L_802205C4:
    // 0x802205C4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x802205C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802205CC: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x802205D0: jal         0x802237B0
    // 0x802205D4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_8;
    // 0x802205D4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_8:
    // 0x802205D8: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x802205DC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x802205E0: slti        $at, $a2, -0x100
    ctx->r1 = SIGNED(ctx->r6) < -0X100 ? 1 : 0;
    // 0x802205E4: beql        $at, $zero, L_80220604
    if (ctx->r1 == 0) {
        // 0x802205E8: slti        $at, $a2, 0x101
        ctx->r1 = SIGNED(ctx->r6) < 0X101 ? 1 : 0;
            goto L_80220604;
    }
    goto skip_1;
    // 0x802205E8: slti        $at, $a2, 0x101
    ctx->r1 = SIGNED(ctx->r6) < 0X101 ? 1 : 0;
    skip_1:
    // 0x802205EC: lh          $t9, 0x12($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X12);
    // 0x802205F0: addiu       $t1, $t9, 0x100
    ctx->r9 = ADD32(ctx->r25, 0X100);
    // 0x802205F4: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x802205F8: b           L_80220628
    // 0x802205FC: sh          $t2, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r10;
        goto L_80220628;
    // 0x802205FC: sh          $t2, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r10;
    // 0x80220600: slti        $at, $a2, 0x101
    ctx->r1 = SIGNED(ctx->r6) < 0X101 ? 1 : 0;
L_80220604:
    // 0x80220604: bne         $at, $zero, L_80220620
    if (ctx->r1 != 0) {
        // 0x80220608: lh          $t9, 0x6A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X6A);
            goto L_80220620;
    }
    // 0x80220608: lh          $t9, 0x6A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6A);
    // 0x8022060C: lh          $t3, 0x12($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X12);
    // 0x80220610: addiu       $t6, $t3, -0x100
    ctx->r14 = ADD32(ctx->r11, -0X100);
    // 0x80220614: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x80220618: b           L_80220628
    // 0x8022061C: sh          $t7, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r15;
        goto L_80220628;
    // 0x8022061C: sh          $t7, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r15;
L_80220620:
    // 0x80220620: andi        $t8, $t9, 0x1FFF
    ctx->r24 = ctx->r25 & 0X1FFF;
    // 0x80220624: sh          $t8, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r24;
L_80220628:
    // 0x80220628: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8022062C: jal         0x80010550
    // 0x80220630: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_9;
    // 0x80220630: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x80220634: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80220638: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8022063C: jal         0x800111E0
    // 0x80220640: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x800111E0)(rdram, ctx);
        goto after_10;
    // 0x80220640: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_10:
    // 0x80220644: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80220648: lbu         $t1, 0x32($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X32);
    // 0x8022064C: andi        $t2, $t1, 0xFF1F
    ctx->r10 = ctx->r9 & 0XFF1F;
    // 0x80220650: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x80220654: b           L_802208A0
    // 0x80220658: sb          $t3, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r11;
        goto L_802208A0;
    // 0x80220658: sb          $t3, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r11;
L_8022065C:
    // 0x8022065C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80220660: jal         0x802237B0
    // 0x80220664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_11;
    // 0x80220664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80220668: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8022066C: jal         0x80010550
    // 0x80220670: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_12;
    // 0x80220670: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_12:
    // 0x80220674: beq         $v0, $zero, L_802208A0
    if (ctx->r2 == 0) {
        // 0x80220678: lbu         $v1, 0x41($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X41);
            goto L_802208A0;
    }
    // 0x80220678: lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X41);
    // 0x8022067C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80220680: bne         $v1, $at, L_802206BC
    if (ctx->r3 != ctx->r1) {
        // 0x80220684: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_802206BC;
    }
    // 0x80220684: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80220688: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8022068C: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x80220690: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80220694: lbu         $t1, 0x31($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X31);
    // 0x80220698: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x8022069C: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x802206A0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x802206A4: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x802206A8: andi        $t8, $t9, 0x60
    ctx->r24 = ctx->r25 & 0X60;
    // 0x802206AC: andi        $t2, $t1, 0xFF9F
    ctx->r10 = ctx->r9 & 0XFF9F;
    // 0x802206B0: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x802206B4: b           L_80220720
    // 0x802206B8: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
        goto L_80220720;
    // 0x802206B8: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
L_802206BC:
    // 0x802206BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x802206C0: bne         $v1, $at, L_802206F0
    if (ctx->r3 != ctx->r1) {
        // 0x802206C4: lw          $t0, 0x54($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X54);
            goto L_802206F0;
    }
    // 0x802206C4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x802206C8: lw          $t4, 0x30($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X30);
    // 0x802206CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802206D0: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x802206D4: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x802206D8: bne         $t6, $at, L_802206E8
    if (ctx->r14 != ctx->r1) {
        // 0x802206DC: nop
    
            goto L_802206E8;
    }
    // 0x802206DC: nop

    // 0x802206E0: b           L_80220720
    // 0x802206E4: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
        goto L_80220720;
    // 0x802206E4: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
L_802206E8:
    // 0x802206E8: b           L_80220720
    // 0x802206EC: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
        goto L_80220720;
    // 0x802206EC: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
L_802206F0:
    // 0x802206F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x802206F4: bne         $v1, $at, L_80220720
    if (ctx->r3 != ctx->r1) {
        // 0x802206F8: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_80220720;
    }
    // 0x802206F8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x802206FC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80220700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80220704: addiu       $a3, $zero, -0x800
    ctx->r7 = ADD32(0, -0X800);
    // 0x80220708: sll         $t1, $t9, 9
    ctx->r9 = S32(ctx->r25 << 9);
    // 0x8022070C: srl         $t8, $t1, 30
    ctx->r24 = S32(U32(ctx->r9) >> 30);
    // 0x80220710: beq         $t8, $at, L_80220720
    if (ctx->r24 == ctx->r1) {
        // 0x80220714: nop
    
            goto L_80220720;
    }
    // 0x80220714: nop

    // 0x80220718: b           L_80220720
    // 0x8022071C: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
        goto L_80220720;
    // 0x8022071C: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
L_80220720:
    // 0x80220720: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80220724: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80220728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8022072C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80220730: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x80220734: lh          $t3, 0x12($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X12);
    // 0x80220738: addu        $t0, $t3, $a3
    ctx->r8 = ADD32(ctx->r11, ctx->r7);
    // 0x8022073C: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x80220740: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80220744: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x80220748: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    // 0x8022074C: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x80220750: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x80220754: jal         0x802256E4
    // 0x80220758: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_13;
    // 0x80220758: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_13:
    // 0x8022075C: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x80220760: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x80220764: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220768: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8022076C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x80220770: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80220774: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80220778: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x8022077C: jal         0x8013A28C
    // 0x80220780: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_14;
    // 0x80220780: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_14:
    // 0x80220784: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80220788: jal         0x80010550
    // 0x8022078C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_15;
    // 0x8022078C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_15:
    // 0x80220790: b           L_802208A4
    // 0x80220794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_802208A4;
    // 0x80220794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80220798:
    // 0x80220798: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8022079C:
    // 0x8022079C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802207A0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x802207A4: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x802207A8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x802207AC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x802207B0: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x802207B4: srl         $t0, $t3, 30
    ctx->r8 = S32(U32(ctx->r11) >> 30);
    // 0x802207B8: bnel        $t0, $at, L_802207D0
    if (ctx->r8 != ctx->r1) {
        // 0x802207BC: lw          $t5, 0x1C($t4)
        ctx->r13 = MEM_W(ctx->r12, 0X1C);
            goto L_802207D0;
    }
    goto skip_2;
    // 0x802207BC: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    skip_2:
    // 0x802207C0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x802207C4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802207C8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802207CC: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
L_802207D0:
    // 0x802207D0: lui         $at, 0x191
    ctx->r1 = S32(0X191 << 16);
    // 0x802207D4: ori         $at, $at, 0xAA
    ctx->r1 = ctx->r1 | 0XAA;
    // 0x802207D8: bnel        $t5, $at, L_802207F4
    if (ctx->r13 != ctx->r1) {
        // 0x802207DC: slti        $at, $a2, -0xC00
        ctx->r1 = SIGNED(ctx->r6) < -0XC00 ? 1 : 0;
            goto L_802207F4;
    }
    goto skip_3;
    // 0x802207DC: slti        $at, $a2, -0xC00
    ctx->r1 = SIGNED(ctx->r6) < -0XC00 ? 1 : 0;
    skip_3:
    // 0x802207E0: jal         0x802256E4
    // 0x802207E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_16;
    // 0x802207E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x802207E8: b           L_80220870
    // 0x802207EC: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
        goto L_80220870;
    // 0x802207EC: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x802207F0: slti        $at, $a2, -0xC00
    ctx->r1 = SIGNED(ctx->r6) < -0XC00 ? 1 : 0;
L_802207F4:
    // 0x802207F4: bne         $at, $zero, L_80220808
    if (ctx->r1 != 0) {
        // 0x802207F8: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80220808;
    }
    // 0x802207F8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x802207FC: slti        $at, $a2, 0xC01
    ctx->r1 = SIGNED(ctx->r6) < 0XC01 ? 1 : 0;
    // 0x80220800: bnel        $at, $zero, L_80220820
    if (ctx->r1 != 0) {
        // 0x80220804: slti        $at, $a2, -0x400
        ctx->r1 = SIGNED(ctx->r6) < -0X400 ? 1 : 0;
            goto L_80220820;
    }
    goto skip_4;
    // 0x80220804: slti        $at, $a2, -0x400
    ctx->r1 = SIGNED(ctx->r6) < -0X400 ? 1 : 0;
    skip_4:
L_80220808:
    // 0x80220808: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8022080C: jal         0x802256E4
    // 0x80220810: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_17;
    // 0x80220810: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_17:
    // 0x80220814: b           L_80220870
    // 0x80220818: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
        goto L_80220870;
    // 0x80220818: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x8022081C: slti        $at, $a2, -0x400
    ctx->r1 = SIGNED(ctx->r6) < -0X400 ? 1 : 0;
L_80220820:
    // 0x80220820: beq         $at, $zero, L_8022083C
    if (ctx->r1 == 0) {
        // 0x80220824: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_8022083C;
    }
    // 0x80220824: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80220828: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8022082C: jal         0x802256E4
    // 0x80220830: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_18;
    // 0x80220830: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_18:
    // 0x80220834: b           L_80220870
    // 0x80220838: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
        goto L_80220870;
    // 0x80220838: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
L_8022083C:
    // 0x8022083C: slti        $at, $a2, 0x401
    ctx->r1 = SIGNED(ctx->r6) < 0X401 ? 1 : 0;
    // 0x80220840: bne         $at, $zero, L_80220860
    if (ctx->r1 != 0) {
        // 0x80220844: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80220860;
    }
    // 0x80220844: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80220848: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8022084C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80220850: jal         0x802256E4
    // 0x80220854: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_19;
    // 0x80220854: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_19:
    // 0x80220858: b           L_80220870
    // 0x8022085C: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
        goto L_80220870;
    // 0x8022085C: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
L_80220860:
    // 0x80220860: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80220864: jal         0x802256E4
    // 0x80220868: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_20;
    // 0x80220868: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x8022086C: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
L_80220870:
    // 0x80220870: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80220874: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80220878: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8022087C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80220880: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80220884: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80220888: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8022088C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80220890: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80220894: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80220898: jal         0x80011140
    // 0x8022089C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_21;
    // 0x8022089C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_21:
L_802208A0:
    // 0x802208A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802208A4:
    // 0x802208A4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x802208A8: jr          $ra
    // 0x802208AC: nop

    return;
    // 0x802208AC: nop

;}
RECOMP_FUNC void M10_FUN_802208b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802208B0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802208B4: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x802208B8: lw          $v0, 0xDC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802208bc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802208bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802208BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x802208C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802208C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x802208C8: bne         $a0, $v0, L_802208DC
    if (ctx->r4 != ctx->r2) {
        // 0x802208CC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_802208DC;
    }
    // 0x802208CC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x802208D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802208D4: b           L_802208E4
    // 0x802208D8: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_802208E4;
    // 0x802208D8: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_802208DC:
    // 0x802208DC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802208E0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_802208E4:
    // 0x802208E4: beq         $a2, $v0, L_802208F8
    if (ctx->r6 == ctx->r2) {
        // 0x802208E8: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_802208F8;
    }
    // 0x802208E8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x802208EC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x802208F0: b           L_802208FC
    // 0x802208F4: addiu       $t1, $t1, -0x3FC4
    ctx->r9 = ADD32(ctx->r9, -0X3FC4);
        goto L_802208FC;
    // 0x802208F4: addiu       $t1, $t1, -0x3FC4
    ctx->r9 = ADD32(ctx->r9, -0X3FC4);
L_802208F8:
    // 0x802208F8: addiu       $t1, $t1, -0x3C28
    ctx->r9 = ADD32(ctx->r9, -0X3C28);
L_802208FC:
    // 0x802208FC: lbu         $v0, 0x1031($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X1031);
    // 0x80220900: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80220904: lw          $t2, 0x5C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X5C);
    // 0x80220908: beq         $v0, $at, L_80220F50
    if (ctx->r2 == ctx->r1) {
        // 0x8022090C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80220F50;
    }
    // 0x8022090C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80220910: bne         $v0, $at, L_80220958
    if (ctx->r2 != ctx->r1) {
        // 0x80220914: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80220958;
    }
    // 0x80220914: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220918: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    // 0x8022091C: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
    // 0x80220920: lw          $a1, 0x324($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X324);
    // 0x80220924: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
    // 0x80220928: lbu         $t5, 0x31($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X31);
    // 0x8022092C: lbu         $t7, 0x30($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X30);
    // 0x80220930: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
    // 0x80220934: andi        $t9, $t5, 0xFFF8
    ctx->r25 = ctx->r13 & 0XFFF8;
    // 0x80220938: sb          $t9, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r25;
    // 0x8022093C: andi        $t5, $t9, 0x7F
    ctx->r13 = ctx->r25 & 0X7F;
    // 0x80220940: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80220944: sb          $t8, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r24;
    // 0x80220948: jal         0x800058DC
    // 0x8022094C: sb          $t5, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8022094C: sb          $t5, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r13;
    after_0:
    // 0x80220950: b           L_80220F54
    // 0x80220954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220958:
    // 0x80220958: lhu         $t6, 0x30($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X30);
    // 0x8022095C: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80220960: bnel        $t7, $zero, L_80220F54
    if (ctx->r15 != 0) {
        // 0x80220964: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80220F54;
    }
    goto skip_0;
    // 0x80220964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80220968: lbu         $t8, 0x30($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X30);
    // 0x8022096C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80220970: beql        $t9, $zero, L_80220F54
    if (ctx->r25 == 0) {
        // 0x80220974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80220F54;
    }
    goto skip_1;
    // 0x80220974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80220978: lbu         $t5, 0x32($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X32);
    // 0x8022097C: lbu         $t7, 0x2DE($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2DE);
    // 0x80220980: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
    // 0x80220984: andi        $t6, $t5, 0xFFFC
    ctx->r14 = ctx->r13 & 0XFFFC;
    // 0x80220988: sb          $zero, 0x394($v1)
    MEM_B(0X394, ctx->r3) = 0;
    // 0x8022098C: sb          $zero, 0x2F1($v1)
    MEM_B(0X2F1, ctx->r3) = 0;
    // 0x80220990: sb          $zero, 0x2FA($v1)
    MEM_B(0X2FA, ctx->r3) = 0;
    // 0x80220994: sb          $zero, 0x2F8($v1)
    MEM_B(0X2F8, ctx->r3) = 0;
    // 0x80220998: beq         $t7, $zero, L_802209EC
    if (ctx->r15 == 0) {
        // 0x8022099C: sb          $t6, 0x32($v1)
        MEM_B(0X32, ctx->r3) = ctx->r14;
            goto L_802209EC;
    }
    // 0x8022099C: sb          $t6, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r14;
    // 0x802209A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802209A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x802209A8: sb          $zero, 0x2DE($v1)
    MEM_B(0X2DE, ctx->r3) = 0;
    // 0x802209AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x802209B0: swc1        $f4, 0x2EC($v1)
    MEM_W(0X2EC, ctx->r3) = ctx->f4.u32l;
    // 0x802209B4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x802209B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x802209BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x802209C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x802209C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x802209C8: jal         0x803602D4
    // 0x802209CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x803602D4)(rdram, ctx);
        goto after_1;
    // 0x802209CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x802209D0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802209D4: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x802209D8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x802209DC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x802209E0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x802209E4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x802209E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_802209EC:
    // 0x802209EC: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x802209F0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x802209F4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x802209F8: srl         $t5, $t9, 28
    ctx->r13 = S32(U32(ctx->r25) >> 28);
    // 0x802209FC: bnel        $t3, $t5, L_80220A18
    if (ctx->r11 != ctx->r13) {
        // 0x80220A00: lbu         $v0, 0x33($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X33);
            goto L_80220A18;
    }
    goto skip_2;
    // 0x80220A00: lbu         $v0, 0x33($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X33);
    skip_2:
    // 0x80220A04: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x80220A08: sh          $zero, 0x312($v1)
    MEM_H(0X312, ctx->r3) = 0;
    // 0x80220A0C: andi        $t7, $t6, 0xFFE1
    ctx->r15 = ctx->r14 & 0XFFE1;
    // 0x80220A10: sb          $t7, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r15;
    // 0x80220A14: lbu         $v0, 0x33($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X33);
L_80220A18:
    // 0x80220A18: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80220A1C: srl         $t8, $v0, 7
    ctx->r24 = S32(U32(ctx->r2) >> 7);
    // 0x80220A20: bne         $t4, $t8, L_80220A30
    if (ctx->r12 != ctx->r24) {
        // 0x80220A24: andi        $t9, $v0, 0xFF7F
        ctx->r25 = ctx->r2 & 0XFF7F;
            goto L_80220A30;
    }
    // 0x80220A24: andi        $t9, $v0, 0xFF7F
    ctx->r25 = ctx->r2 & 0XFF7F;
    // 0x80220A28: sb          $t9, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r25;
    // 0x80220A2C: sh          $zero, 0x312($v1)
    MEM_H(0X312, ctx->r3) = 0;
L_80220A30:
    // 0x80220A30: lhu         $t5, 0x2C($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X2C);
    // 0x80220A34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80220A38: bnel        $t5, $at, L_80220C84
    if (ctx->r13 != ctx->r1) {
        // 0x80220A3C: lhu         $v0, 0xE($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0XE);
            goto L_80220C84;
    }
    goto skip_3;
    // 0x80220A3C: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    skip_3:
    // 0x80220A40: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x80220A44: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x80220A48: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80220A4C: beql        $t7, $zero, L_80220C84
    if (ctx->r15 == 0) {
        // 0x80220A50: lhu         $v0, 0xE($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0XE);
            goto L_80220C84;
    }
    goto skip_4;
    // 0x80220A50: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    skip_4:
    // 0x80220A54: lbu         $a0, 0x2D8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80220A58: bnel        $a0, $zero, L_80220B20
    if (ctx->r4 != 0) {
        // 0x80220A5C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80220B20;
    }
    goto skip_5;
    // 0x80220A5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x80220A60: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x80220A64: slti        $at, $t8, 0x96
    ctx->r1 = SIGNED(ctx->r24) < 0X96 ? 1 : 0;
    // 0x80220A68: bnel        $at, $zero, L_80220B20
    if (ctx->r1 != 0) {
        // 0x80220A6C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80220B20;
    }
    goto skip_6;
    // 0x80220A6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
    // 0x80220A70: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80220A74: slti        $at, $t9, 0x1E
    ctx->r1 = SIGNED(ctx->r25) < 0X1E ? 1 : 0;
    // 0x80220A78: bnel        $at, $zero, L_80220B20
    if (ctx->r1 != 0) {
        // 0x80220A7C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80220B20;
    }
    goto skip_7;
    // 0x80220A7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_7:
    // 0x80220A80: lhu         $v0, 0x36($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X36);
    // 0x80220A84: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80220A88: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x80220A8C: beq         $a1, $v0, L_80220AB4
    if (ctx->r5 == ctx->r2) {
        // 0x80220A90: addiu       $t5, $zero, 0x13
        ctx->r13 = ADD32(0, 0X13);
            goto L_80220AB4;
    }
    // 0x80220A90: addiu       $t5, $zero, 0x13
    ctx->r13 = ADD32(0, 0X13);
    // 0x80220A94: beq         $v0, $at, L_80220AB4
    if (ctx->r2 == ctx->r1) {
        // 0x80220A98: addiu       $at, $zero, 0x146
        ctx->r1 = ADD32(0, 0X146);
            goto L_80220AB4;
    }
    // 0x80220A98: addiu       $at, $zero, 0x146
    ctx->r1 = ADD32(0, 0X146);
    // 0x80220A9C: beq         $v0, $at, L_80220AB4
    if (ctx->r2 == ctx->r1) {
        // 0x80220AA0: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80220AB4;
    }
    // 0x80220AA0: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80220AA4: beq         $v0, $at, L_80220AB4
    if (ctx->r2 == ctx->r1) {
        // 0x80220AA8: addiu       $at, $zero, 0xFB
        ctx->r1 = ADD32(0, 0XFB);
            goto L_80220AB4;
    }
    // 0x80220AA8: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x80220AAC: bnel        $v0, $at, L_80220B20
    if (ctx->r2 != ctx->r1) {
        // 0x80220AB0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80220B20;
    }
    goto skip_8;
    // 0x80220AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_8:
L_80220AB4:
    // 0x80220AB4: lh          $t6, 0x44($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X44);
    // 0x80220AB8: lh          $t8, 0x42($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X42);
    // 0x80220ABC: sb          $t5, 0x2D8($v1)
    MEM_B(0X2D8, ctx->r3) = ctx->r13;
    // 0x80220AC0: addiu       $t7, $t6, 0x96
    ctx->r15 = ADD32(ctx->r14, 0X96);
    // 0x80220AC4: addiu       $t9, $t8, 0x1E
    ctx->r25 = ADD32(ctx->r24, 0X1E);
    // 0x80220AC8: sh          $t7, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r15;
    // 0x80220ACC: sh          $t9, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r25;
    // 0x80220AD0: lhu         $v0, 0x36($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X36);
    // 0x80220AD4: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x80220AD8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80220ADC: beq         $v0, $at, L_80220AEC
    if (ctx->r2 == ctx->r1) {
        // 0x80220AE0: addiu       $at, $zero, 0x146
        ctx->r1 = ADD32(0, 0X146);
            goto L_80220AEC;
    }
    // 0x80220AE0: addiu       $at, $zero, 0x146
    ctx->r1 = ADD32(0, 0X146);
    // 0x80220AE4: bnel        $v0, $at, L_80220AF8
    if (ctx->r2 != ctx->r1) {
        // 0x80220AE8: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80220AF8;
    }
    goto skip_9;
    // 0x80220AE8: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    skip_9:
L_80220AEC:
    // 0x80220AEC: b           L_80220C80
    // 0x80220AF0: sb          $t5, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r13;
        goto L_80220C80;
    // 0x80220AF0: sb          $t5, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r13;
    // 0x80220AF4: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
L_80220AF8:
    // 0x80220AF8: beq         $v0, $at, L_80220B0C
    if (ctx->r2 == ctx->r1) {
        // 0x80220AFC: addiu       $t6, $zero, 0x6
        ctx->r14 = ADD32(0, 0X6);
            goto L_80220B0C;
    }
    // 0x80220AFC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80220B00: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x80220B04: bne         $v0, $at, L_80220B14
    if (ctx->r2 != ctx->r1) {
        // 0x80220B08: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_80220B14;
    }
    // 0x80220B08: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
L_80220B0C:
    // 0x80220B0C: b           L_80220C80
    // 0x80220B10: sb          $t6, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r14;
        goto L_80220C80;
    // 0x80220B10: sb          $t6, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r14;
L_80220B14:
    // 0x80220B14: b           L_80220C80
    // 0x80220B18: sb          $t7, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r15;
        goto L_80220C80;
    // 0x80220B18: sb          $t7, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r15;
    // 0x80220B1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80220B20:
    // 0x80220B20: bne         $a0, $at, L_80220C80
    if (ctx->r4 != ctx->r1) {
        // 0x80220B24: addiu       $a1, $zero, 0xFA
        ctx->r5 = ADD32(0, 0XFA);
            goto L_80220C80;
    }
    // 0x80220B24: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80220B28: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x80220B2C: slti        $at, $t8, 0xC8
    ctx->r1 = SIGNED(ctx->r24) < 0XC8 ? 1 : 0;
    // 0x80220B30: bnel        $at, $zero, L_80220C84
    if (ctx->r1 != 0) {
        // 0x80220B34: lhu         $v0, 0xE($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0XE);
            goto L_80220C84;
    }
    goto skip_10;
    // 0x80220B34: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    skip_10:
    // 0x80220B38: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80220B3C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80220B40: bnel        $at, $zero, L_80220C84
    if (ctx->r1 != 0) {
        // 0x80220B44: lhu         $v0, 0xE($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0XE);
            goto L_80220C84;
    }
    goto skip_11;
    // 0x80220B44: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    skip_11:
    // 0x80220B48: lhu         $v0, 0x36($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X36);
    // 0x80220B4C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x80220B50: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80220B54: beq         $a0, $v0, L_80220B9C
    if (ctx->r4 == ctx->r2) {
        // 0x80220B58: addiu       $t5, $zero, 0x13
        ctx->r13 = ADD32(0, 0X13);
            goto L_80220B9C;
    }
    // 0x80220B58: addiu       $t5, $zero, 0x13
    ctx->r13 = ADD32(0, 0X13);
    // 0x80220B5C: beq         $v0, $at, L_80220B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80220B60: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_80220B9C;
    }
    // 0x80220B60: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80220B64: beq         $v0, $at, L_80220B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80220B68: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_80220B9C;
    }
    // 0x80220B68: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x80220B6C: beql        $v0, $at, L_80220BA0
    if (ctx->r2 == ctx->r1) {
        // 0x80220B70: lh          $t6, 0x44($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X44);
            goto L_80220BA0;
    }
    goto skip_12;
    // 0x80220B70: lh          $t6, 0x44($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X44);
    skip_12:
    // 0x80220B74: beq         $a1, $v0, L_80220B9C
    if (ctx->r5 == ctx->r2) {
        // 0x80220B78: addiu       $at, $zero, 0xFC
        ctx->r1 = ADD32(0, 0XFC);
            goto L_80220B9C;
    }
    // 0x80220B78: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80220B7C: beq         $v0, $at, L_80220B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80220B80: addiu       $at, $zero, 0x147
        ctx->r1 = ADD32(0, 0X147);
            goto L_80220B9C;
    }
    // 0x80220B80: addiu       $at, $zero, 0x147
    ctx->r1 = ADD32(0, 0X147);
    // 0x80220B84: beq         $v0, $at, L_80220B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80220B88: addiu       $at, $zero, 0x148
        ctx->r1 = ADD32(0, 0X148);
            goto L_80220B9C;
    }
    // 0x80220B88: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x80220B8C: beq         $v0, $at, L_80220B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80220B90: addiu       $at, $zero, 0x11E
        ctx->r1 = ADD32(0, 0X11E);
            goto L_80220B9C;
    }
    // 0x80220B90: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    // 0x80220B94: bnel        $v0, $at, L_80220C84
    if (ctx->r2 != ctx->r1) {
        // 0x80220B98: lhu         $v0, 0xE($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0XE);
            goto L_80220C84;
    }
    goto skip_13;
    // 0x80220B98: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    skip_13:
L_80220B9C:
    // 0x80220B9C: lh          $t6, 0x44($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X44);
L_80220BA0:
    // 0x80220BA0: lh          $t8, 0x42($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X42);
    // 0x80220BA4: sb          $t5, 0x2D8($v1)
    MEM_B(0X2D8, ctx->r3) = ctx->r13;
    // 0x80220BA8: addiu       $t7, $t6, 0xC8
    ctx->r15 = ADD32(ctx->r14, 0XC8);
    // 0x80220BAC: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80220BB0: sh          $t7, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r15;
    // 0x80220BB4: sh          $t9, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r25;
    // 0x80220BB8: lhu         $v0, 0x36($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X36);
    // 0x80220BBC: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80220BC0: beq         $v0, $at, L_80220BD8
    if (ctx->r2 == ctx->r1) {
        // 0x80220BC4: addiu       $at, $zero, 0xFC
        ctx->r1 = ADD32(0, 0XFC);
            goto L_80220BD8;
    }
    // 0x80220BC4: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80220BC8: beq         $v0, $at, L_80220BD8
    if (ctx->r2 == ctx->r1) {
        // 0x80220BCC: addiu       $at, $zero, 0x147
        ctx->r1 = ADD32(0, 0X147);
            goto L_80220BD8;
    }
    // 0x80220BCC: addiu       $at, $zero, 0x147
    ctx->r1 = ADD32(0, 0X147);
    // 0x80220BD0: bne         $v0, $at, L_80220BE0
    if (ctx->r2 != ctx->r1) {
        // 0x80220BD4: nop
    
            goto L_80220BE0;
    }
    // 0x80220BD4: nop

L_80220BD8:
    // 0x80220BD8: b           L_80220C80
    // 0x80220BDC: sb          $t3, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r11;
        goto L_80220C80;
    // 0x80220BDC: sb          $t3, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r11;
L_80220BE0:
    // 0x80220BE0: beq         $a1, $v0, L_80220BF0
    if (ctx->r5 == ctx->r2) {
        // 0x80220BE4: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_80220BF0;
    }
    // 0x80220BE4: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x80220BE8: bne         $v0, $at, L_80220BF8
    if (ctx->r2 != ctx->r1) {
        // 0x80220BEC: nop
    
            goto L_80220BF8;
    }
    // 0x80220BEC: nop

L_80220BF0:
    // 0x80220BF0: b           L_80220C80
    // 0x80220BF4: sb          $zero, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = 0;
        goto L_80220C80;
    // 0x80220BF4: sb          $zero, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = 0;
L_80220BF8:
    // 0x80220BF8: bne         $a0, $v0, L_80220C0C
    if (ctx->r4 != ctx->r2) {
        // 0x80220BFC: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_80220C0C;
    }
    // 0x80220BFC: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80220C00: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80220C04: b           L_80220C80
    // 0x80220C08: sb          $t5, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r13;
        goto L_80220C80;
    // 0x80220C08: sb          $t5, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r13;
L_80220C0C:
    // 0x80220C0C: bnel        $v0, $at, L_80220C20
    if (ctx->r2 != ctx->r1) {
        // 0x80220C10: addiu       $at, $zero, 0x11E
        ctx->r1 = ADD32(0, 0X11E);
            goto L_80220C20;
    }
    goto skip_14;
    // 0x80220C10: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    skip_14:
    // 0x80220C14: b           L_80220C80
    // 0x80220C18: sb          $t4, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r12;
        goto L_80220C80;
    // 0x80220C18: sb          $t4, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r12;
    // 0x80220C1C: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
L_80220C20:
    // 0x80220C20: bnel        $v0, $at, L_80220C5C
    if (ctx->r2 != ctx->r1) {
        // 0x80220C24: lbu         $t8, 0x2D9($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X2D9);
            goto L_80220C5C;
    }
    goto skip_15;
    // 0x80220C24: lbu         $t8, 0x2D9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2D9);
    skip_15:
    // 0x80220C28: lbu         $v0, 0x2D9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D9);
    // 0x80220C2C: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80220C30: bnel        $at, $zero, L_80220C5C
    if (ctx->r1 != 0) {
        // 0x80220C34: lbu         $t8, 0x2D9($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X2D9);
            goto L_80220C5C;
    }
    goto skip_16;
    // 0x80220C34: lbu         $t8, 0x2D9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2D9);
    skip_16:
    // 0x80220C38: bgez        $v0, L_80220C4C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80220C3C: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80220C4C;
    }
    // 0x80220C3C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80220C40: beq         $t6, $zero, L_80220C4C
    if (ctx->r14 == 0) {
        // 0x80220C44: nop
    
            goto L_80220C4C;
    }
    // 0x80220C44: nop

    // 0x80220C48: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_80220C4C:
    // 0x80220C4C: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x80220C50: b           L_80220C80
    // 0x80220C54: sb          $t7, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r15;
        goto L_80220C80;
    // 0x80220C54: sb          $t7, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r15;
    // 0x80220C58: lbu         $t8, 0x2D9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2D9);
L_80220C5C:
    // 0x80220C5C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80220C60: addiu       $t9, $t8, -0xE
    ctx->r25 = ADD32(ctx->r24, -0XE);
    // 0x80220C64: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80220C68: mfhi        $t5
    ctx->r13 = hi;
    // 0x80220C6C: bgez        $t5, L_80220C7C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80220C70: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80220C7C;
    }
    // 0x80220C70: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80220C74: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80220C78: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80220C7C:
    // 0x80220C7C: sb          $t6, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r14;
L_80220C80:
    // 0x80220C80: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
L_80220C84:
    // 0x80220C84: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x80220C88: bnel        $v0, $at, L_80220CF4
    if (ctx->r2 != ctx->r1) {
        // 0x80220C8C: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_80220CF4;
    }
    goto skip_17;
    // 0x80220C8C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    skip_17:
    // 0x80220C90: lbu         $t7, 0x390($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X390);
    // 0x80220C94: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80220C98: bnel        $t7, $at, L_80220CF4
    if (ctx->r15 != ctx->r1) {
        // 0x80220C9C: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_80220CF4;
    }
    goto skip_18;
    // 0x80220C9C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    skip_18:
    // 0x80220CA0: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80220CA4: sll         $t9, $t8, 27
    ctx->r25 = S32(ctx->r24 << 27);
    // 0x80220CA8: srl         $t5, $t9, 30
    ctx->r13 = S32(U32(ctx->r25) >> 30);
    // 0x80220CAC: beql        $t5, $zero, L_80220CF4
    if (ctx->r13 == 0) {
        // 0x80220CB0: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_80220CF4;
    }
    goto skip_19;
    // 0x80220CB0: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    skip_19:
    // 0x80220CB4: lbu         $a0, 0x2D8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80220CB8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80220CBC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80220CC0: beql        $a1, $a0, L_80220CDC
    if (ctx->r5 == ctx->r4) {
        // 0x80220CC4: lbu         $t6, 0x33($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X33);
            goto L_80220CDC;
    }
    goto skip_20;
    // 0x80220CC4: lbu         $t6, 0x33($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X33);
    skip_20:
    // 0x80220CC8: beq         $a0, $at, L_80220CD8
    if (ctx->r4 == ctx->r1) {
        // 0x80220CCC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80220CD8;
    }
    // 0x80220CCC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80220CD0: bnel        $a0, $at, L_80220CF4
    if (ctx->r4 != ctx->r1) {
        // 0x80220CD4: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_80220CF4;
    }
    goto skip_21;
    // 0x80220CD4: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    skip_21:
L_80220CD8:
    // 0x80220CD8: lbu         $t6, 0x33($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X33);
L_80220CDC:
    // 0x80220CDC: lbu         $a0, 0x2D8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80220CE0: andi        $t7, $t6, 0xFFE7
    ctx->r15 = ctx->r14 & 0XFFE7;
    // 0x80220CE4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80220CE8: b           L_80220D18
    // 0x80220CEC: sb          $t8, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r24;
        goto L_80220D18;
    // 0x80220CEC: sb          $t8, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r24;
    // 0x80220CF0: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
L_80220CF4:
    // 0x80220CF4: bne         $v0, $at, L_80220D04
    if (ctx->r2 != ctx->r1) {
        // 0x80220CF8: addiu       $a1, $zero, 0x13
        ctx->r5 = ADD32(0, 0X13);
            goto L_80220D04;
    }
    // 0x80220CF8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80220CFC: b           L_80220D18
    // 0x80220D00: lbu         $a0, 0x2D8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2D8);
        goto L_80220D18;
    // 0x80220D00: lbu         $a0, 0x2D8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2D8);
L_80220D04:
    // 0x80220D04: lbu         $t9, 0x33($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X33);
    // 0x80220D08: sb          $zero, 0x390($v1)
    MEM_B(0X390, ctx->r3) = 0;
    // 0x80220D0C: lbu         $a0, 0x2D8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80220D10: andi        $t5, $t9, 0xFFE7
    ctx->r13 = ctx->r25 & 0XFFE7;
    // 0x80220D14: sb          $t5, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r13;
L_80220D18:
    // 0x80220D18: sltiu       $at, $a0, 0x15
    ctx->r1 = ctx->r4 < 0X15 ? 1 : 0;
    // 0x80220D1C: beq         $at, $zero, L_80220EF4
    if (ctx->r1 == 0) {
        // 0x80220D20: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80220EF4;
    }
    // 0x80220D20: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80220D24: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80220D28: addu        $at, $at, $t6
    gpr jr_addend_80220D30 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80220D2C: lw          $t6, -0x1410($at)
    ctx->r14 = ADD32(ctx->r1, -0X1410);
    // 0x80220D30: jr          $t6
    // 0x80220D34: nop

    switch (jr_addend_80220D30 >> 2) {
        case 0: goto L_80220D38; break;
        case 1: goto L_80220D38; break;
        case 2: goto L_80220D60; break;
        case 3: goto L_80220D38; break;
        case 4: goto L_80220DB4; break;
        case 5: goto L_80220DB4; break;
        case 6: goto L_80220DB4; break;
        case 7: goto L_80220DB4; break;
        case 8: goto L_80220D4C; break;
        case 9: goto L_80220D38; break;
        case 10: goto L_80220D38; break;
        case 11: goto L_80220EDC; break;
        case 12: goto L_80220EB0; break;
        case 13: goto L_80220E60; break;
        case 14: goto L_80220DC8; break;
        case 15: goto L_80220E08; break;
        case 16: goto L_80220EF4; break;
        case 17: goto L_80220E60; break;
        case 18: goto L_80220EF4; break;
        case 19: goto L_80220E9C; break;
        case 20: goto L_80220EF4; break;
        default: switch_error(__func__, 0x80220D30, 0x8023EBF0);
    }
    // 0x80220D34: nop

L_80220D38:
    // 0x80220D38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220D3C: jal         0x80360818
    // 0x80220D40: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80360818)(rdram, ctx);
        goto after_2;
    // 0x80220D40: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80220D44: b           L_80220F54
    // 0x80220D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220D4C:
    // 0x80220D4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220D50: jal         0x8036C110
    // 0x80220D54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8036C110)(rdram, ctx);
        goto after_3;
    // 0x80220D54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x80220D58: b           L_80220F54
    // 0x80220D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220D60:
    // 0x80220D60: lw          $t7, 0x38($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X38);
    // 0x80220D64: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80220D68: beql        $t8, $zero, L_80220D98
    if (ctx->r24 == 0) {
        // 0x80220D6C: lbu         $t7, 0x30($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X30);
            goto L_80220D98;
    }
    goto skip_22;
    // 0x80220D6C: lbu         $t7, 0x30($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X30);
    skip_22:
    // 0x80220D70: lw          $t9, 0x38($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X38);
    // 0x80220D74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220D78: srl         $t5, $t9, 31
    ctx->r13 = S32(U32(ctx->r25) >> 31);
    // 0x80220D7C: beql        $t5, $zero, L_80220D98
    if (ctx->r13 == 0) {
        // 0x80220D80: lbu         $t7, 0x30($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X30);
            goto L_80220D98;
    }
    goto skip_23;
    // 0x80220D80: lbu         $t7, 0x30($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X30);
    skip_23:
    // 0x80220D84: jal         0x80367914
    // 0x80220D88: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80367914)(rdram, ctx);
        goto after_4;
    // 0x80220D88: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_4:
    // 0x80220D8C: b           L_80220F54
    // 0x80220D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80220D94: lbu         $t7, 0x30($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X30);
L_80220D98:
    // 0x80220D98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220D9C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80220DA0: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80220DA4: jal         0x8035C98C
    // 0x80220DA8: sb          $t8, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x8035C98C)(rdram, ctx);
        goto after_5;
    // 0x80220DA8: sb          $t8, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r24;
    after_5:
    // 0x80220DAC: b           L_80220F54
    // 0x80220DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220DB4:
    // 0x80220DB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220DB8: jal         0x80369994
    // 0x80220DBC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80369994)(rdram, ctx);
        goto after_6;
    // 0x80220DBC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x80220DC0: b           L_80220F54
    // 0x80220DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220DC8:
    // 0x80220DC8: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x80220DCC: sll         $t5, $t9, 11
    ctx->r13 = S32(ctx->r25 << 11);
    // 0x80220DD0: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80220DD4: beql        $t6, $zero, L_80220E0C
    if (ctx->r14 == 0) {
        // 0x80220DD8: lw          $t7, 0x30($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X30);
            goto L_80220E0C;
    }
    goto skip_24;
    // 0x80220DD8: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    skip_24:
    // 0x80220DDC: lbu         $v0, 0x2D8($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2D8);
    // 0x80220DE0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80220DE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220DE8: beq         $v0, $at, L_80220DF8
    if (ctx->r2 == ctx->r1) {
        // 0x80220DEC: nop
    
            goto L_80220DF8;
    }
    // 0x80220DEC: nop

    // 0x80220DF0: bnel        $a1, $v0, L_80220E0C
    if (ctx->r5 != ctx->r2) {
        // 0x80220DF4: lw          $t7, 0x30($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X30);
            goto L_80220E0C;
    }
    goto skip_25;
    // 0x80220DF4: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    skip_25:
L_80220DF8:
    // 0x80220DF8: jal         0x8036D938
    // 0x80220DFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8036D938)(rdram, ctx);
        goto after_7;
    // 0x80220DFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x80220E00: b           L_80220F54
    // 0x80220E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220E08:
    // 0x80220E08: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
L_80220E0C:
    // 0x80220E0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220E10: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x80220E14: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80220E18: beql        $t9, $zero, L_80220E64
    if (ctx->r25 == 0) {
        // 0x80220E1C: addiu       $a1, $t2, 0x22
        ctx->r5 = ADD32(ctx->r10, 0X22);
            goto L_80220E64;
    }
    goto skip_26;
    // 0x80220E1C: addiu       $a1, $t2, 0x22
    ctx->r5 = ADD32(ctx->r10, 0X22);
    skip_26:
    // 0x80220E20: lbu         $v0, 0x2D8($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2D8);
    // 0x80220E24: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80220E28: beql        $v0, $at, L_80220E3C
    if (ctx->r2 == ctx->r1) {
        // 0x80220E2C: lbu         $t5, 0x30($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X30);
            goto L_80220E3C;
    }
    goto skip_27;
    // 0x80220E2C: lbu         $t5, 0x30($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X30);
    skip_27:
    // 0x80220E30: bne         $a1, $v0, L_80220E50
    if (ctx->r5 != ctx->r2) {
        // 0x80220E34: nop
    
            goto L_80220E50;
    }
    // 0x80220E34: nop

    // 0x80220E38: lbu         $t5, 0x30($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X30);
L_80220E3C:
    // 0x80220E3C: sb          $zero, 0x2DB($v1)
    MEM_B(0X2DB, ctx->r3) = 0;
    // 0x80220E40: andi        $t7, $t5, 0xFFFE
    ctx->r15 = ctx->r13 & 0XFFFE;
    // 0x80220E44: sb          $t7, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r15;
    // 0x80220E48: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80220E4C: sb          $t8, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r24;
L_80220E50:
    // 0x80220E50: jal         0x80365FE0
    // 0x80220E54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80365FE0)(rdram, ctx);
        goto after_8;
    // 0x80220E54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x80220E58: b           L_80220F54
    // 0x80220E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220E60:
    // 0x80220E60: addiu       $a1, $t2, 0x22
    ctx->r5 = ADD32(ctx->r10, 0X22);
L_80220E64:
    // 0x80220E64: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80220E68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80220E6C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80220E70: jal         0x80011258
    // 0x80220E74: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011258)(rdram, ctx);
        goto after_9;
    // 0x80220E74: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_9:
    // 0x80220E78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80220E7C: jal         0x800113D0
    // 0x80220E80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_10;
    // 0x80220E80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80220E84: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80220E88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80220E8C: jal         0x800058DC
    // 0x80220E90: addiu       $a1, $a1, 0x1070
    ctx->r5 = ADD32(ctx->r5, 0X1070);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80220E90: addiu       $a1, $a1, 0x1070
    ctx->r5 = ADD32(ctx->r5, 0X1070);
    after_11:
    // 0x80220E94: b           L_80220F54
    // 0x80220E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220E9C:
    // 0x80220E9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220EA0: jal         0x8036F9B0
    // 0x80220EA4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8036F9B0)(rdram, ctx);
        goto after_12;
    // 0x80220EA4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_12:
    // 0x80220EA8: b           L_80220F54
    // 0x80220EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220EB0:
    // 0x80220EB0: lbu         $v0, 0x2D9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D9);
    // 0x80220EB4: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80220EB8: bne         $at, $zero, L_80220EDC
    if (ctx->r1 != 0) {
        // 0x80220EBC: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_80220EDC;
    }
    // 0x80220EBC: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80220EC0: beq         $at, $zero, L_80220EDC
    if (ctx->r1 == 0) {
        // 0x80220EC4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80220EDC;
    }
    // 0x80220EC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220EC8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80220ECC: jal         0x800058DC
    // 0x80220ED0: addiu       $a1, $a1, 0x1040
    ctx->r5 = ADD32(ctx->r5, 0X1040);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x80220ED0: addiu       $a1, $a1, 0x1040
    ctx->r5 = ADD32(ctx->r5, 0X1040);
    after_13:
    // 0x80220ED4: b           L_80220F54
    // 0x80220ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220EDC:
    // 0x80220EDC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80220EE0: addiu       $a1, $a1, 0xF60
    ctx->r5 = ADD32(ctx->r5, 0XF60);
    // 0x80220EE4: jal         0x800058DC
    // 0x80220EE8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x80220EE8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_14:
    // 0x80220EEC: b           L_80220F54
    // 0x80220EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220EF4:
    // 0x80220EF4: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x80220EF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80220EFC: addiu       $a1, $t2, 0x22
    ctx->r5 = ADD32(ctx->r10, 0X22);
    // 0x80220F00: sll         $t5, $t9, 11
    ctx->r13 = S32(ctx->r25 << 11);
    // 0x80220F04: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80220F08: beql        $t6, $zero, L_80220F28
    if (ctx->r14 == 0) {
        // 0x80220F0C: sw          $a1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r5;
            goto L_80220F28;
    }
    goto skip_28;
    // 0x80220F0C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    skip_28:
    // 0x80220F10: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80220F14: jal         0x80365FE0
    // 0x80220F18: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80365FE0)(rdram, ctx);
        goto after_15;
    // 0x80220F18: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_15:
    // 0x80220F1C: b           L_80220F54
    // 0x80220F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80220F54;
    // 0x80220F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80220F24: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
L_80220F28:
    // 0x80220F28: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80220F2C: jal         0x80011258
    // 0x80220F30: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011258)(rdram, ctx);
        goto after_16;
    // 0x80220F30: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_16:
    // 0x80220F34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80220F38: jal         0x800113D0
    // 0x80220F3C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_17;
    // 0x80220F3C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_17:
    // 0x80220F40: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80220F44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80220F48: jal         0x800058DC
    // 0x80220F4C: addiu       $a1, $a1, 0x1070
    ctx->r5 = ADD32(ctx->r5, 0X1070);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x80220F4C: addiu       $a1, $a1, 0x1070
    ctx->r5 = ADD32(ctx->r5, 0X1070);
    after_18:
L_80220F50:
    // 0x80220F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220F54:
    // 0x80220F54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80220F58: jr          $ra
    // 0x80220F5C: nop

    return;
    // 0x80220F5C: nop

;}
RECOMP_FUNC void M10_FUN_80220f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80220F60: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80220F64: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80220F68: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80220f6c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80220f6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80220F6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80220F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80220F74: beql        $a0, $v0, L_80220F88
    if (ctx->r4 == ctx->r2) {
        // 0x80220F78: lw          $a2, 0xEC($v1)
        ctx->r6 = MEM_W(ctx->r3, 0XEC);
            goto L_80220F88;
    }
    goto skip_0;
    // 0x80220F78: lw          $a2, 0xEC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XEC);
    skip_0:
    // 0x80220F7C: b           L_80220F88
    // 0x80220F80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80220F88;
    // 0x80220F80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80220F84: lw          $a2, 0xEC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XEC);
L_80220F88:
    // 0x80220F88: lbu         $t6, 0x1031($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1031);
    // 0x80220F8C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80220F90: beql        $t6, $at, L_80220FB4
    if (ctx->r14 == ctx->r1) {
        // 0x80220F94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80220FB4;
    }
    goto skip_1;
    // 0x80220F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80220F98: jal         0x80359560
    // 0x80220F9C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80359560)(rdram, ctx);
        goto after_0;
    // 0x80220F9C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80220FA0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80220FA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80220FA8: jal         0x800058DC
    // 0x80220FAC: addiu       $a1, $a1, 0xFC0
    ctx->r5 = ADD32(ctx->r5, 0XFC0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80220FAC: addiu       $a1, $a1, 0xFC0
    ctx->r5 = ADD32(ctx->r5, 0XFC0);
    after_1:
    // 0x80220FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80220FB4:
    // 0x80220FB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80220FB8: jr          $ra
    // 0x80220FBC: nop

    return;
    // 0x80220FBC: nop

;}
RECOMP_FUNC void M10_FUN_80220fc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80220FC0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80220FC4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80220FC8: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80220fcc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80220fcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80220FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80220FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80220FD4: bne         $a0, $v0, L_80220FE8
    if (ctx->r4 != ctx->r2) {
        // 0x80220FD8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80220FE8;
    }
    // 0x80220FD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80220FDC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80220FE0: b           L_80220FF0
    // 0x80220FE4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80220FF0;
    // 0x80220FE4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80220FE8:
    // 0x80220FE8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80220FEC: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80220FF0:
    // 0x80220FF0: lbu         $t6, 0x1031($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1031);
    // 0x80220FF4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80220FF8: beql        $t6, $at, L_80221034
    if (ctx->r14 == ctx->r1) {
        // 0x80220FFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80221034;
    }
    goto skip_0;
    // 0x80220FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80221000: lbu         $t7, 0x1035($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1035);
    // 0x80221004: bnel        $t7, $zero, L_80221034
    if (ctx->r15 != 0) {
        // 0x80221008: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80221034;
    }
    goto skip_1;
    // 0x80221008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8022100C: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80221010: lw          $t1, 0x3C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X3C);
    // 0x80221014: lw          $a1, 0x324($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X324);
    // 0x80221018: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x8022101C: lbu         $t2, 0x31($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X31);
    // 0x80221020: sw          $t1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r9;
    // 0x80221024: andi        $t3, $t2, 0xFFF8
    ctx->r11 = ctx->r10 & 0XFFF8;
    // 0x80221028: jal         0x800058DC
    // 0x8022102C: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8022102C: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
    after_0:
    // 0x80221030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221034:
    // 0x80221034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80221038: jr          $ra
    // 0x8022103C: nop

    return;
    // 0x8022103C: nop

;}
RECOMP_FUNC void M10_FUN_80221040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221040: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80221044: lbu         $t6, -0x33DF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80221048(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80221048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8022104C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80221050: beq         $t6, $at, L_80221060
    if (ctx->r14 == ctx->r1) {
        // 0x80221054: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80221060;
    }
    // 0x80221054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80221058: jal         0x8035C048
    // 0x8022105C: nop

    LOOKUP_FUNC(0x8035C048)(rdram, ctx);
        goto after_0;
    // 0x8022105C: nop

    after_0:
L_80221060:
    // 0x80221060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80221064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80221068: jr          $ra
    // 0x8022106C: nop

    return;
    // 0x8022106C: nop

;}
RECOMP_FUNC void M10_FUN_80221070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221070: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221074: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80221078: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022107c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022107c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022107C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80221080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80221084: bne         $a0, $t6, L_80221098
    if (ctx->r4 != ctx->r14) {
        // 0x80221088: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80221098;
    }
    // 0x80221088: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8022108C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80221090: b           L_802210A0
    // 0x80221094: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_802210A0;
    // 0x80221094: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_80221098:
    // 0x80221098: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022109C: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_802210A0:
    // 0x802210A0: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x802210A4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x802210A8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x802210AC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x802210B0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x802210B4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x802210B8: sb          $zero, 0x392($a2)
    MEM_B(0X392, ctx->r6) = 0;
    // 0x802210BC: lbu         $t0, 0x1031($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1031);
    // 0x802210C0: beql        $t0, $at, L_80221714
    if (ctx->r8 == ctx->r1) {
        // 0x802210C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80221714;
    }
    goto skip_0;
    // 0x802210C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x802210C8: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x802210CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802210D0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802210D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x802210D8: srl         $v0, $v0, 28
    ctx->r2 = S32(U32(ctx->r2) >> 28);
    // 0x802210DC: beq         $v0, $at, L_802210F4
    if (ctx->r2 == ctx->r1) {
        // 0x802210E0: nop
    
            goto L_802210F4;
    }
    // 0x802210E0: nop

    // 0x802210E4: lbu         $t1, 0x2D8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X2D8);
    // 0x802210E8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x802210EC: bnel        $t1, $at, L_80221108
    if (ctx->r9 != ctx->r1) {
        // 0x802210F0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80221108;
    }
    goto skip_1;
    // 0x802210F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_1:
L_802210F4:
    // 0x802210F4: jal         0x800058DC
    // 0x802210F8: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802210F8: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    after_0:
    // 0x802210FC: b           L_80221714
    // 0x80221100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80221714;
    // 0x80221100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80221104: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80221108:
    // 0x80221108: bne         $v0, $at, L_8022118C
    if (ctx->r2 != ctx->r1) {
        // 0x8022110C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8022118C;
    }
    // 0x8022110C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80221110: lbu         $t2, 0x30($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X30);
    // 0x80221114: lbu         $t6, 0x31($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X31);
    // 0x80221118: lbu         $t8, 0x38($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X38);
    // 0x8022111C: andi        $t4, $t2, 0xFF7F
    ctx->r12 = ctx->r10 & 0XFF7F;
    // 0x80221120: sb          $t4, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r12;
    // 0x80221124: andi        $t5, $t4, 0xFE
    ctx->r13 = ctx->r12 & 0XFE;
    // 0x80221128: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8022112C: sb          $t5, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r13;
    // 0x80221130: sb          $t7, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r15;
    // 0x80221134: lw          $t4, 0x30($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X30);
    // 0x80221138: andi        $t0, $t8, 0xFF7F
    ctx->r8 = ctx->r24 & 0XFF7F;
    // 0x8022113C: andi        $t2, $t0, 0xEF
    ctx->r10 = ctx->r8 & 0XEF;
    // 0x80221140: sb          $t0, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r8;
    // 0x80221144: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x80221148: sb          $t2, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r10;
    // 0x8022114C: andi        $t3, $t2, 0x9F
    ctx->r11 = ctx->r10 & 0X9F;
    // 0x80221150: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80221154: sb          $t3, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r11;
    // 0x80221158: sb          $zero, 0x2F1($a2)
    MEM_B(0X2F1, ctx->r6) = 0;
    // 0x8022115C: sb          $zero, 0x391($a2)
    MEM_B(0X391, ctx->r6) = 0;
    // 0x80221160: beq         $t6, $zero, L_8022117C
    if (ctx->r14 == 0) {
        // 0x80221164: sb          $zero, 0x393($a2)
        MEM_B(0X393, ctx->r6) = 0;
            goto L_8022117C;
    }
    // 0x80221164: sb          $zero, 0x393($a2)
    MEM_B(0X393, ctx->r6) = 0;
    // 0x80221168: lui         $a1, 0x8036
    ctx->r5 = S32(0X8036 << 16);
    // 0x8022116C: jal         0x800058DC
    // 0x80221170: addiu       $a1, $a1, 0x6278
    ctx->r5 = ADD32(ctx->r5, 0X6278);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80221170: addiu       $a1, $a1, 0x6278
    ctx->r5 = ADD32(ctx->r5, 0X6278);
    after_1:
    // 0x80221174: b           L_80221714
    // 0x80221178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80221714;
    // 0x80221178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022117C:
    // 0x8022117C: jal         0x80366B30
    // 0x80221180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80366B30)(rdram, ctx);
        goto after_2;
    // 0x80221180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80221184: b           L_80221714
    // 0x80221188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80221714;
    // 0x80221188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8022118C:
    // 0x8022118C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80221190: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80221194: jal         0x802237B0
    // 0x80221198: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_3;
    // 0x80221198: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_3:
    // 0x8022119C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x802211A0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802211A4: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    // 0x802211A8: jal         0x80011258
    // 0x802211AC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80011258)(rdram, ctx);
        goto after_4;
    // 0x802211AC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_4:
    // 0x802211B0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802211B4: jal         0x800113D0
    // 0x802211B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_5;
    // 0x802211B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x802211BC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x802211C0: lw          $t7, 0x30($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X30);
    // 0x802211C4: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x802211C8: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x802211CC: bnel        $t9, $zero, L_802211F8
    if (ctx->r25 != 0) {
        // 0x802211D0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_802211F8;
    }
    goto skip_2;
    // 0x802211D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x802211D4: lbu         $t0, 0x2F9($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X2F9);
    // 0x802211D8: lbu         $t5, 0x31($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X31);
    // 0x802211DC: addiu       $t2, $t0, 0x2
    ctx->r10 = ADD32(ctx->r8, 0X2);
    // 0x802211E0: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x802211E4: andi        $t4, $t3, 0x60
    ctx->r12 = ctx->r11 & 0X60;
    // 0x802211E8: andi        $t6, $t5, 0xFF9F
    ctx->r14 = ctx->r13 & 0XFF9F;
    // 0x802211EC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x802211F0: sb          $t7, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r15;
    // 0x802211F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_802211F8:
    // 0x802211F8: jal         0x8022560C
    // 0x802211FC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_6;
    // 0x802211FC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_6:
    // 0x80221200: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80221204: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // 0x80221208: bne         $v0, $zero, L_80221228
    if (ctx->r2 != 0) {
        // 0x8022120C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80221228;
    }
    // 0x8022120C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80221210: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221214: addiu       $a1, $a1, 0x1720
    ctx->r5 = ADD32(ctx->r5, 0X1720);
    // 0x80221218: jal         0x800058DC
    // 0x8022121C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x8022121C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80221220: b           L_80221714
    // 0x80221224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80221714;
    // 0x80221224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221228:
    // 0x80221228: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022122C: bnel        $v1, $at, L_802212FC
    if (ctx->r3 != ctx->r1) {
        // 0x80221230: lbu         $a3, 0x37($sp)
        ctx->r7 = MEM_BU(ctx->r29, 0X37);
            goto L_802212FC;
    }
    goto skip_3;
    // 0x80221230: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    skip_3:
    // 0x80221234: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80221238: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8022123C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80221240: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80221244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221248: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8022124C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80221250: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80221254: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80221258: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8022125C: nop

    // 0x80221260: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80221264: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80221268: nop

    // 0x8022126C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80221270: beql        $a0, $zero, L_802212C0
    if (ctx->r4 == 0) {
        // 0x80221274: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_802212C0;
    }
    goto skip_4;
    // 0x80221274: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x80221278: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022127C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221280: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80221284: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80221288: nop

    // 0x8022128C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80221290: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80221294: nop

    // 0x80221298: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8022129C: bne         $a0, $zero, L_802212B4
    if (ctx->r4 != 0) {
        // 0x802212A0: nop
    
            goto L_802212B4;
    }
    // 0x802212A0: nop

    // 0x802212A4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x802212A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802212AC: b           L_802212CC
    // 0x802212B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_802212CC;
    // 0x802212B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_802212B4:
    // 0x802212B4: b           L_802212CC
    // 0x802212B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_802212CC;
    // 0x802212B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x802212BC: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_802212C0:
    // 0x802212C0: nop

    // 0x802212C4: bltz        $a0, L_802212B4
    if (SIGNED(ctx->r4) < 0) {
        // 0x802212C8: nop
    
            goto L_802212B4;
    }
    // 0x802212C8: nop

L_802212CC:
    // 0x802212CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x802212D0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x802212D4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x802212D8: jal         0x80011590
    // 0x802212DC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_8;
    // 0x802212DC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_8:
    // 0x802212E0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x802212E4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x802212E8: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x802212EC: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x802212F0: beql        $at, $zero, L_802214A4
    if (ctx->r1 == 0) {
        // 0x802212F4: lhu         $t5, 0x6($v1)
        ctx->r13 = MEM_HU(ctx->r3, 0X6);
            goto L_802214A4;
    }
    goto skip_5;
    // 0x802212F4: lhu         $t5, 0x6($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X6);
    skip_5:
    // 0x802212F8: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
L_802212FC:
    // 0x802212FC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80221300: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80221304: bne         $a3, $at, L_802213CC
    if (ctx->r7 != ctx->r1) {
        // 0x80221308: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_802213CC;
    }
    // 0x80221308: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8022130C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80221310: lwc1        $f16, 0x24($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80221314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221318: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8022131C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80221320: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80221324: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80221328: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8022132C: nop

    // 0x80221330: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80221334: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80221338: nop

    // 0x8022133C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80221340: beql        $a0, $zero, L_80221390
    if (ctx->r4 == 0) {
        // 0x80221344: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_80221390;
    }
    goto skip_6;
    // 0x80221344: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x80221348: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8022134C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221350: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80221354: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80221358: nop

    // 0x8022135C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80221360: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80221364: nop

    // 0x80221368: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8022136C: bne         $a0, $zero, L_80221384
    if (ctx->r4 != 0) {
        // 0x80221370: nop
    
            goto L_80221384;
    }
    // 0x80221370: nop

    // 0x80221374: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80221378: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022137C: b           L_8022139C
    // 0x80221380: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8022139C;
    // 0x80221380: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80221384:
    // 0x80221384: b           L_8022139C
    // 0x80221388: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8022139C;
    // 0x80221388: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8022138C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_80221390:
    // 0x80221390: nop

    // 0x80221394: bltz        $a0, L_80221384
    if (SIGNED(ctx->r4) < 0) {
        // 0x80221398: nop
    
            goto L_80221384;
    }
    // 0x80221398: nop

L_8022139C:
    // 0x8022139C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x802213A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x802213A4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x802213A8: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x802213AC: jal         0x80011590
    // 0x802213B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_9;
    // 0x802213B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_9:
    // 0x802213B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x802213B8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x802213BC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x802213C0: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x802213C4: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x802213C8: beq         $at, $zero, L_802214A0
    if (ctx->r1 == 0) {
        // 0x802213CC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_802214A0;
    }
L_802213CC:
    // 0x802213CC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x802213D0: bne         $a3, $at, L_802214D4
    if (ctx->r7 != ctx->r1) {
        // 0x802213D4: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_802214D4;
    }
    // 0x802213D4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x802213D8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x802213DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802213E0: lwc1        $f8, 0x24($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X24);
    // 0x802213E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x802213E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x802213EC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x802213F0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x802213F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x802213F8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x802213FC: nop

    // 0x80221400: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80221404: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80221408: nop

    // 0x8022140C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80221410: beql        $a0, $zero, L_80221460
    if (ctx->r4 == 0) {
        // 0x80221414: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80221460;
    }
    goto skip_7;
    // 0x80221414: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_7:
    // 0x80221418: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8022141C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221420: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80221424: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80221428: nop

    // 0x8022142C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80221430: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80221434: nop

    // 0x80221438: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8022143C: bne         $a0, $zero, L_80221454
    if (ctx->r4 != 0) {
        // 0x80221440: nop
    
            goto L_80221454;
    }
    // 0x80221440: nop

    // 0x80221444: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80221448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022144C: b           L_8022146C
    // 0x80221450: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8022146C;
    // 0x80221450: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80221454:
    // 0x80221454: b           L_8022146C
    // 0x80221458: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8022146C;
    // 0x80221458: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8022145C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80221460:
    // 0x80221460: nop

    // 0x80221464: bltz        $a0, L_80221454
    if (SIGNED(ctx->r4) < 0) {
        // 0x80221468: nop
    
            goto L_80221454;
    }
    // 0x80221468: nop

L_8022146C:
    // 0x8022146C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80221470: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80221474: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80221478: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8022147C: jal         0x80011590
    // 0x80221480: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_10;
    // 0x80221480: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_10:
    // 0x80221484: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80221488: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8022148C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80221490: lhu         $t3, 0x4($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X4);
    // 0x80221494: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80221498: bnel        $at, $zero, L_802214D8
    if (ctx->r1 != 0) {
        // 0x8022149C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_802214D8;
    }
    goto skip_8;
    // 0x8022149C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_8:
L_802214A0:
    // 0x802214A0: lhu         $t5, 0x6($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X6);
L_802214A4:
    // 0x802214A4: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x802214A8: andi        $t4, $t5, 0x10
    ctx->r12 = ctx->r13 & 0X10;
    // 0x802214AC: beql        $t4, $zero, L_802214CC
    if (ctx->r12 == 0) {
        // 0x802214B0: lbu         $t0, 0x31($a2)
        ctx->r8 = MEM_BU(ctx->r6, 0X31);
            goto L_802214CC;
    }
    goto skip_9;
    // 0x802214B0: lbu         $t0, 0x31($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X31);
    skip_9:
    // 0x802214B4: lbu         $t6, 0x31($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X31);
    // 0x802214B8: andi        $t7, $t6, 0xFF9F
    ctx->r15 = ctx->r14 & 0XFF9F;
    // 0x802214BC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x802214C0: b           L_802214D4
    // 0x802214C4: sb          $t8, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r24;
        goto L_802214D4;
    // 0x802214C4: sb          $t8, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r24;
    // 0x802214C8: lbu         $t0, 0x31($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X31);
L_802214CC:
    // 0x802214CC: ori         $t1, $t0, 0x60
    ctx->r9 = ctx->r8 | 0X60;
    // 0x802214D0: sb          $t1, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r9;
L_802214D4:
    // 0x802214D4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_802214D8:
    // 0x802214D8: beq         $a3, $at, L_802214F4
    if (ctx->r7 == ctx->r1) {
        // 0x802214DC: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_802214F4;
    }
    // 0x802214DC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802214E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x802214E4: beq         $a3, $at, L_802214F4
    if (ctx->r7 == ctx->r1) {
        // 0x802214E8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_802214F4;
    }
    // 0x802214E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x802214EC: bnel        $a3, $at, L_80221510
    if (ctx->r7 != ctx->r1) {
        // 0x802214F0: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_80221510;
    }
    goto skip_10;
    // 0x802214F0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    skip_10:
L_802214F4:
    // 0x802214F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x802214F8: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x802214FC: jal         0x800112B0
    // 0x80221500: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800112B0)(rdram, ctx);
        goto after_11;
    // 0x80221500: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_11:
    // 0x80221504: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80221508: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8022150C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80221510:
    // 0x80221510: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80221514: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80221518: jal         0x80010550
    // 0x8022151C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_12;
    // 0x8022151C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80221520: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80221524: beq         $v0, $zero, L_80221710
    if (ctx->r2 == 0) {
        // 0x80221528: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80221710;
    }
    // 0x80221528: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8022152C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80221530: bne         $a3, $at, L_8022156C
    if (ctx->r7 != ctx->r1) {
        // 0x80221534: sh          $zero, 0x34($sp)
        MEM_H(0X34, ctx->r29) = 0;
            goto L_8022156C;
    }
    // 0x80221534: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x80221538: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8022153C: sh          $t2, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r10;
    // 0x80221540: lw          $t3, 0x30($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X30);
    // 0x80221544: lbu         $t9, 0x31($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X31);
    // 0x80221548: sll         $t5, $t3, 9
    ctx->r13 = S32(ctx->r11 << 9);
    // 0x8022154C: srl         $t4, $t5, 30
    ctx->r12 = S32(U32(ctx->r13) >> 30);
    // 0x80221550: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80221554: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80221558: andi        $t8, $t7, 0x60
    ctx->r24 = ctx->r15 & 0X60;
    // 0x8022155C: andi        $t0, $t9, 0xFF9F
    ctx->r8 = ctx->r25 & 0XFF9F;
    // 0x80221560: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80221564: b           L_80221678
    // 0x80221568: sb          $t1, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r9;
        goto L_80221678;
    // 0x80221568: sb          $t1, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r9;
L_8022156C:
    // 0x8022156C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80221570: bne         $a3, $at, L_802215A0
    if (ctx->r7 != ctx->r1) {
        // 0x80221574: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_802215A0;
    }
    // 0x80221574: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80221578: lhu         $t3, 0x22($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X22);
    // 0x8022157C: addiu       $t6, $zero, 0x1800
    ctx->r14 = ADD32(0, 0X1800);
    // 0x80221580: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x80221584: andi        $t5, $t3, 0x10
    ctx->r13 = ctx->r11 & 0X10;
    // 0x80221588: beq         $t5, $zero, L_80221598
    if (ctx->r13 == 0) {
        // 0x8022158C: nop
    
            goto L_80221598;
    }
    // 0x8022158C: nop

    // 0x80221590: b           L_80221678
    // 0x80221594: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
        goto L_80221678;
    // 0x80221594: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
L_80221598:
    // 0x80221598: b           L_80221678
    // 0x8022159C: sh          $t6, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r14;
        goto L_80221678;
    // 0x8022159C: sh          $t6, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r14;
L_802215A0:
    // 0x802215A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x802215A4: bne         $a3, $at, L_802215D4
    if (ctx->r7 != ctx->r1) {
        // 0x802215A8: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_802215D4;
    }
    // 0x802215A8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x802215AC: lhu         $t9, 0x22($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X22);
    // 0x802215B0: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x802215B4: addiu       $t0, $zero, 0x1800
    ctx->r8 = ADD32(0, 0X1800);
    // 0x802215B8: andi        $t8, $t9, 0x10
    ctx->r24 = ctx->r25 & 0X10;
    // 0x802215BC: beq         $t8, $zero, L_802215CC
    if (ctx->r24 == 0) {
        // 0x802215C0: nop
    
            goto L_802215CC;
    }
    // 0x802215C0: nop

    // 0x802215C4: b           L_80221678
    // 0x802215C8: sh          $t0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r8;
        goto L_80221678;
    // 0x802215C8: sh          $t0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r8;
L_802215CC:
    // 0x802215CC: b           L_80221678
    // 0x802215D0: sh          $t1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r9;
        goto L_80221678;
    // 0x802215D0: sh          $t1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r9;
L_802215D4:
    // 0x802215D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x802215D8: beq         $a3, $at, L_802215F4
    if (ctx->r7 == ctx->r1) {
        // 0x802215DC: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_802215F4;
    }
    // 0x802215DC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x802215E0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x802215E4: beq         $a3, $at, L_802215F4
    if (ctx->r7 == ctx->r1) {
        // 0x802215E8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_802215F4;
    }
    // 0x802215E8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x802215EC: bnel        $a3, $at, L_8022162C
    if (ctx->r7 != ctx->r1) {
        // 0x802215F0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8022162C;
    }
    goto skip_11;
    // 0x802215F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_11:
L_802215F4:
    // 0x802215F4: lhu         $t3, 0x22($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X22);
    // 0x802215F8: andi        $t5, $t3, 0x10
    ctx->r13 = ctx->r11 & 0X10;
    // 0x802215FC: beql        $t5, $zero, L_8022161C
    if (ctx->r13 == 0) {
        // 0x80221600: lbu         $t8, 0x31($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0X31);
            goto L_8022161C;
    }
    goto skip_12;
    // 0x80221600: lbu         $t8, 0x31($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X31);
    skip_12:
    // 0x80221604: lbu         $t4, 0x31($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X31);
    // 0x80221608: andi        $t6, $t4, 0xFF9F
    ctx->r14 = ctx->r12 & 0XFF9F;
    // 0x8022160C: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80221610: b           L_80221678
    // 0x80221614: sb          $t7, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r15;
        goto L_80221678;
    // 0x80221614: sb          $t7, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r15;
    // 0x80221618: lbu         $t8, 0x31($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X31);
L_8022161C:
    // 0x8022161C: ori         $t0, $t8, 0x60
    ctx->r8 = ctx->r24 | 0X60;
    // 0x80221620: b           L_80221678
    // 0x80221624: sb          $t0, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r8;
        goto L_80221678;
    // 0x80221624: sb          $t0, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r8;
    // 0x80221628: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_8022162C:
    // 0x8022162C: beq         $a3, $at, L_80221648
    if (ctx->r7 == ctx->r1) {
        // 0x80221630: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_80221648;
    }
    // 0x80221630: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80221634: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80221638: beq         $a3, $at, L_80221648
    if (ctx->r7 == ctx->r1) {
        // 0x8022163C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80221648;
    }
    // 0x8022163C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80221640: bnel        $a3, $at, L_8022167C
    if (ctx->r7 != ctx->r1) {
        // 0x80221644: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_8022167C;
    }
    goto skip_13;
    // 0x80221644: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_13:
L_80221648:
    // 0x80221648: lhu         $t2, 0x22($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X22);
    // 0x8022164C: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80221650: beql        $t3, $zero, L_8022166C
    if (ctx->r11 == 0) {
        // 0x80221654: lbu         $t7, 0x31($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X31);
            goto L_8022166C;
    }
    goto skip_14;
    // 0x80221654: lbu         $t7, 0x31($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X31);
    skip_14:
    // 0x80221658: lbu         $t4, 0x31($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X31);
    // 0x8022165C: ori         $t6, $t4, 0x60
    ctx->r14 = ctx->r12 | 0X60;
    // 0x80221660: b           L_80221678
    // 0x80221664: sb          $t6, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r14;
        goto L_80221678;
    // 0x80221664: sb          $t6, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r14;
    // 0x80221668: lbu         $t7, 0x31($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X31);
L_8022166C:
    // 0x8022166C: andi        $t9, $t7, 0xFF9F
    ctx->r25 = ctx->r15 & 0XFF9F;
    // 0x80221670: ori         $t8, $t9, 0x40
    ctx->r24 = ctx->r25 | 0X40;
    // 0x80221674: sb          $t8, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r24;
L_80221678:
    // 0x80221678: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8022167C:
    // 0x8022167C: lh          $t1, 0x34($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X34);
    // 0x80221680: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80221684: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x80221688: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8022168C: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x80221690: lh          $t3, 0x12($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X12);
    // 0x80221694: andi        $t5, $t3, 0x1FFF
    ctx->r13 = ctx->r11 & 0X1FFF;
    // 0x80221698: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x8022169C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x802216A0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x802216A4: beql        $t4, $zero, L_802216EC
    if (ctx->r12 == 0) {
        // 0x802216A8: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_802216EC;
    }
    goto skip_15;
    // 0x802216A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_15:
    // 0x802216AC: jal         0x802256E4
    // 0x802216B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_13;
    // 0x802216B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x802216B4: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x802216B8: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x802216BC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802216C0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x802216C4: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x802216C8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x802216CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x802216D0: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x802216D4: jal         0x8013A28C
    // 0x802216D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_14;
    // 0x802216D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_14:
    // 0x802216DC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802216E0: jal         0x80010550
    // 0x802216E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_15;
    // 0x802216E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x802216E8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_802216EC:
    // 0x802216EC: jal         0x80224E00
    // 0x802216F0: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80224E00)(rdram, ctx);
        goto after_16;
    // 0x802216F0: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    after_16:
    // 0x802216F4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802216F8: jal         0x80011198
    // 0x802216FC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_17;
    // 0x802216FC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_17:
    // 0x80221700: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221704: addiu       $a1, $a1, 0x1720
    ctx->r5 = ADD32(ctx->r5, 0X1720);
    // 0x80221708: jal         0x800058DC
    // 0x8022170C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x8022170C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_18:
L_80221710:
    // 0x80221710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221714:
    // 0x80221714: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80221718: jr          $ra
    // 0x8022171C: nop

    return;
    // 0x8022171C: nop

;}
RECOMP_FUNC void M10_FUN_80221720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221720: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80221724: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221728: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8022172C: lw          $t7, 0xDC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XDC);
    // 0x80221730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80221734: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80221738: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8022173C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80221740: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80221744: bne         $a0, $t7, L_80221758
    if (ctx->r4 != ctx->r15) {
        // 0x80221748: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_80221758;
    }
    // 0x80221748: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8022174C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221750: b           L_80221760
    // 0x80221754: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80221760;
    // 0x80221754: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80221758:
    // 0x80221758: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022175C: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80221760:
    // 0x80221760: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x80221764: lbu         $t8, 0x1031($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1031);
    // 0x80221768: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8022176C: beql        $t8, $at, L_802218C4
    if (ctx->r24 == ctx->r1) {
        // 0x80221770: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_802218C4;
    }
    goto skip_0;
    // 0x80221770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80221774: lbu         $t9, 0x2D8($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80221778: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8022177C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80221780: bne         $t9, $at, L_80221790
    if (ctx->r25 != ctx->r1) {
        // 0x80221784: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80221790;
    }
    // 0x80221784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80221788: b           L_802217A0
    // 0x8022178C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_802217A0;
    // 0x8022178C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80221790:
    // 0x80221790: jal         0x80224AC4
    // 0x80221794: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80224AC4)(rdram, ctx);
        goto after_0;
    // 0x80221794: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_0:
    // 0x80221798: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8022179C: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
L_802217A0:
    // 0x802217A0: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x802217A4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x802217A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x802217AC: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x802217B0: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x802217B4: bne         $t3, $zero, L_802217DC
    if (ctx->r11 != 0) {
        // 0x802217B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_802217DC;
    }
    // 0x802217B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802217BC: lbu         $t4, 0x2F9($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2F9);
    // 0x802217C0: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x802217C4: addiu       $t6, $t4, 0x2
    ctx->r14 = ADD32(ctx->r12, 0X2);
    // 0x802217C8: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x802217CC: andi        $t8, $t7, 0x60
    ctx->r24 = ctx->r15 & 0X60;
    // 0x802217D0: andi        $t1, $t9, 0xFF9F
    ctx->r9 = ctx->r25 & 0XFF9F;
    // 0x802217D4: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x802217D8: sb          $t2, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r10;
L_802217DC:
    // 0x802217DC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x802217E0: jal         0x802256E4
    // 0x802217E4: sb          $t0, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x802217E4: sb          $t0, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r8;
    after_1:
    // 0x802217E8: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x802217EC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x802217F0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x802217F4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x802217F8: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x802217FC: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x80221800: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80221804: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80221808: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8022180C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80221810: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80221814: jal         0x80011140
    // 0x80221818: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x80221818: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8022181C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80221820: beq         $v0, $zero, L_802218C0
    if (ctx->r2 == 0) {
        // 0x80221824: lbu         $t0, 0x3D($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X3D);
            goto L_802218C0;
    }
    // 0x80221824: lbu         $t0, 0x3D($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3D);
    // 0x80221828: bne         $t0, $zero, L_802218A8
    if (ctx->r8 != 0) {
        // 0x8022182C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802218A8;
    }
    // 0x8022182C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80221830: lbu         $v0, 0x2D8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80221834: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80221838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022183C: bne         $v0, $at, L_80221854
    if (ctx->r2 != ctx->r1) {
        // 0x80221840: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_80221854;
    }
    // 0x80221840: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221844: jal         0x800058DC
    // 0x80221848: addiu       $a1, $a1, 0x19F8
    ctx->r5 = ADD32(ctx->r5, 0X19F8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80221848: addiu       $a1, $a1, 0x19F8
    ctx->r5 = ADD32(ctx->r5, 0X19F8);
    after_3:
    // 0x8022184C: b           L_802218C4
    // 0x80221850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802218C4;
    // 0x80221850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80221854:
    // 0x80221854: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80221858: bne         $v0, $at, L_80221870
    if (ctx->r2 != ctx->r1) {
        // 0x8022185C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80221870;
    }
    // 0x8022185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80221860: jal         0x803628B8
    // 0x80221864: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x803628B8)(rdram, ctx);
        goto after_4;
    // 0x80221864: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80221868: b           L_802218C4
    // 0x8022186C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802218C4;
    // 0x8022186C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80221870:
    // 0x80221870: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80221874: bne         $v0, $at, L_80221894
    if (ctx->r2 != ctx->r1) {
        // 0x80221878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80221894;
    }
    // 0x80221878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022187C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221880: addiu       $a1, $a1, 0x1E9C
    ctx->r5 = ADD32(ctx->r5, 0X1E9C);
    // 0x80221884: jal         0x800058DC
    // 0x80221888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80221888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8022188C: b           L_802218C4
    // 0x80221890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802218C4;
    // 0x80221890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80221894:
    // 0x80221894: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221898: jal         0x800058DC
    // 0x8022189C: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x8022189C: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    after_6:
    // 0x802218A0: b           L_802218C4
    // 0x802218A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802218C4;
    // 0x802218A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802218A8:
    // 0x802218A8: jal         0x80224BEC
    // 0x802218AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x80224BEC)(rdram, ctx);
        goto after_7;
    // 0x802218AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x802218B0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802218B4: addiu       $a1, $a1, 0x18D4
    ctx->r5 = ADD32(ctx->r5, 0X18D4);
    // 0x802218B8: jal         0x800058DC
    // 0x802218BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x802218BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_802218C0:
    // 0x802218C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802218C4:
    // 0x802218C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802218C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x802218CC: jr          $ra
    // 0x802218D0: nop

    return;
    // 0x802218D0: nop

;}
RECOMP_FUNC void M10_FUN_802218d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802218D4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802218D8: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802218dc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802218dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802218DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802218E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802218E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x802218E8: bne         $a0, $t6, L_802218FC
    if (ctx->r4 != ctx->r14) {
        // 0x802218EC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_802218FC;
    }
    // 0x802218EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x802218F0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802218F4: b           L_80221904
    // 0x802218F8: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80221904;
    // 0x802218F8: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_802218FC:
    // 0x802218FC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221900: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80221904:
    // 0x80221904: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x80221908: lhu         $t7, 0x36($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X36);
    // 0x8022190C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x80221910: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80221914: bne         $t7, $at, L_80221924
    if (ctx->r15 != ctx->r1) {
        // 0x80221918: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80221924;
    }
    // 0x80221918: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8022191C: b           L_8022193C
    // 0x80221920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8022193C;
    // 0x80221920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80221924:
    // 0x80221924: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80221928: jal         0x80224F5C
    // 0x8022192C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80224F5C)(rdram, ctx);
        goto after_0;
    // 0x8022192C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80221930: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80221934: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80221938: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_8022193C:
    // 0x8022193C: bnel        $a0, $zero, L_802219EC
    if (ctx->r4 != 0) {
        // 0x80221940: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802219EC;
    }
    goto skip_0;
    // 0x80221940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80221944: lbu         $v0, 0x2D8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D8);
    // 0x80221948: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8022194C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80221950: bne         $v0, $at, L_80221968
    if (ctx->r2 != ctx->r1) {
        // 0x80221954: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_80221968;
    }
    // 0x80221954: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221958: jal         0x800058DC
    // 0x8022195C: addiu       $a1, $a1, 0x19F8
    ctx->r5 = ADD32(ctx->r5, 0X19F8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8022195C: addiu       $a1, $a1, 0x19F8
    ctx->r5 = ADD32(ctx->r5, 0X19F8);
    after_1:
    // 0x80221960: b           L_802219EC
    // 0x80221964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802219EC;
    // 0x80221964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221968:
    // 0x80221968: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8022196C: bne         $v0, $at, L_80221984
    if (ctx->r2 != ctx->r1) {
        // 0x80221970: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80221984;
    }
    // 0x80221970: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80221974: jal         0x803628B8
    // 0x80221978: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x803628B8)(rdram, ctx);
        goto after_2;
    // 0x80221978: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8022197C: b           L_802219EC
    // 0x80221980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802219EC;
    // 0x80221980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221984:
    // 0x80221984: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80221988: bne         $v0, $at, L_802219A8
    if (ctx->r2 != ctx->r1) {
        // 0x8022198C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_802219A8;
    }
    // 0x8022198C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80221990: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221994: addiu       $a1, $a1, 0x1E9C
    ctx->r5 = ADD32(ctx->r5, 0X1E9C);
    // 0x80221998: jal         0x800058DC
    // 0x8022199C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8022199C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x802219A0: b           L_802219EC
    // 0x802219A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802219EC;
    // 0x802219A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802219A8:
    // 0x802219A8: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x802219AC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802219B0: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x802219B4: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x802219B8: bne         $t0, $zero, L_802219E0
    if (ctx->r8 != 0) {
        // 0x802219BC: nop
    
            goto L_802219E0;
    }
    // 0x802219BC: nop

    // 0x802219C0: lbu         $t1, 0x2F9($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2F9);
    // 0x802219C4: lbu         $t6, 0x31($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X31);
    // 0x802219C8: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x802219CC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x802219D0: andi        $t5, $t4, 0x60
    ctx->r13 = ctx->r12 & 0X60;
    // 0x802219D4: andi        $t7, $t6, 0xFF9F
    ctx->r15 = ctx->r14 & 0XFF9F;
    // 0x802219D8: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x802219DC: sb          $t8, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r24;
L_802219E0:
    // 0x802219E0: jal         0x800058DC
    // 0x802219E4: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x802219E4: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    after_4:
    // 0x802219E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802219EC:
    // 0x802219EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802219F0: jr          $ra
    // 0x802219F4: nop

    return;
    // 0x802219F4: nop

;}
RECOMP_FUNC void M10_FUN_802219f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802219F8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x802219FC: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80221A00: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80221a04(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80221a04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221A04: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80221A08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80221A0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80221A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80221A14: bne         $a0, $v0, L_80221A28
    if (ctx->r4 != ctx->r2) {
        // 0x80221A18: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_80221A28;
    }
    // 0x80221A18: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80221A1C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221A20: b           L_80221A30
    // 0x80221A24: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80221A30;
    // 0x80221A24: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80221A28:
    // 0x80221A28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221A2C: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80221A30:
    // 0x80221A30: beq         $s0, $v0, L_80221A40
    if (ctx->r16 == ctx->r2) {
        // 0x80221A34: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80221A40;
    }
    // 0x80221A34: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221A38: b           L_80221A48
    // 0x80221A3C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80221A48;
    // 0x80221A3C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80221A40:
    // 0x80221A40: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221A44: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80221A48:
    // 0x80221A48: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x80221A4C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80221A50: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80221A54: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x80221A58: lbu         $t7, 0x1031($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1031);
    // 0x80221A5C: beql        $t7, $at, L_80221B98
    if (ctx->r15 == ctx->r1) {
        // 0x80221A60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80221B98;
    }
    goto skip_0;
    // 0x80221A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80221A64: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    // 0x80221A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80221A6C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221A70: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80221A74: bnel        $t9, $zero, L_80221A90
    if (ctx->r25 != 0) {
        // 0x80221A78: lbu         $v0, 0x2D9($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X2D9);
            goto L_80221A90;
    }
    goto skip_1;
    // 0x80221A78: lbu         $v0, 0x2D9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D9);
    skip_1:
    // 0x80221A7C: jal         0x800058DC
    // 0x80221A80: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80221A80: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    after_0:
    // 0x80221A84: b           L_80221B98
    // 0x80221A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80221B98;
    // 0x80221A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80221A8C: lbu         $v0, 0x2D9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2D9);
L_80221A90:
    // 0x80221A90: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80221A94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80221A98: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80221A9C: bne         $at, $zero, L_80221AB0
    if (ctx->r1 != 0) {
        // 0x80221AA0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80221AB0;
    }
    // 0x80221AA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80221AA4: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x80221AA8: sb          $t0, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r8;
    // 0x80221AAC: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
L_80221AB0:
    // 0x80221AB0: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x80221AB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80221AB8: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    // 0x80221ABC: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x80221AC0: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80221AC4: bne         $t3, $at, L_80221AD8
    if (ctx->r11 != ctx->r1) {
        // 0x80221AC8: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_80221AD8;
    }
    // 0x80221AC8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80221ACC: subu        $a3, $t4, $v0
    ctx->r7 = SUB32(ctx->r12, ctx->r2);
    // 0x80221AD0: andi        $a3, $a3, 0x7
    ctx->r7 = ctx->r7 & 0X7;
    // 0x80221AD4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_80221AD8:
    // 0x80221AD8: lhu         $t5, 0x36($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X36);
    // 0x80221ADC: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x80221AE0: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x80221AE4: bne         $t5, $at, L_80221B24
    if (ctx->r13 != ctx->r1) {
        // 0x80221AE8: addu        $a2, $a2, $a3
        ctx->r6 = ADD32(ctx->r6, ctx->r7);
            goto L_80221B24;
    }
    // 0x80221AE8: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x80221AEC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80221AF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80221AF4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80221AF8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x80221AFC: jal         0x802256E4
    // 0x80221B00: sb          $a3, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x80221B00: sb          $a3, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r7;
    after_1:
    // 0x80221B04: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x80221B08: lhu         $t6, 0x3E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3E);
    // 0x80221B0C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80221B10: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80221B14: bne         $at, $zero, L_80221B34
    if (ctx->r1 != 0) {
        // 0x80221B18: ori         $t7, $t6, 0x10
        ctx->r15 = ctx->r14 | 0X10;
            goto L_80221B34;
    }
    // 0x80221B18: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80221B1C: b           L_80221B34
    // 0x80221B20: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
        goto L_80221B34;
    // 0x80221B20: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
L_80221B24:
    // 0x80221B24: lbu         $a2, -0x3D80($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X3D80);
    // 0x80221B28: jal         0x802256E4
    // 0x80221B2C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_2;
    // 0x80221B2C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80221B30: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_80221B34:
    // 0x80221B34: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
    // 0x80221B38: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80221B3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80221B40: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80221B44: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80221B48: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80221B4C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80221B50: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80221B54: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80221B58: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80221B5C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x80221B60: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80221B64: jal         0x80011140
    // 0x80221B68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_3;
    // 0x80221B68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x80221B6C: beq         $v0, $zero, L_80221B94
    if (ctx->r2 == 0) {
        // 0x80221B70: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_80221B94;
    }
    // 0x80221B70: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80221B74: lbu         $t2, 0x32($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X32);
    // 0x80221B78: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221B7C: addiu       $a1, $a1, 0x1BA8
    ctx->r5 = ADD32(ctx->r5, 0X1BA8);
    // 0x80221B80: andi        $t3, $t2, 0xFF1F
    ctx->r11 = ctx->r10 & 0XFF1F;
    // 0x80221B84: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80221B88: sb          $t4, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r12;
    // 0x80221B8C: jal         0x800058DC
    // 0x80221B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80221B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80221B94:
    // 0x80221B94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80221B98:
    // 0x80221B98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80221B9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80221BA0: jr          $ra
    // 0x80221BA4: nop

    return;
    // 0x80221BA4: nop

;}
RECOMP_FUNC void M10_FUN_80221ba8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221BA8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221BAC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80221BB0: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80221bb4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80221bb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221BB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80221BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80221BBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80221BC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80221BC4: bne         $a0, $t6, L_80221BD8
    if (ctx->r4 != ctx->r14) {
        // 0x80221BC8: lw          $a3, 0x5C($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X5C);
            goto L_80221BD8;
    }
    // 0x80221BC8: lw          $a3, 0x5C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X5C);
    // 0x80221BCC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221BD0: b           L_80221BE0
    // 0x80221BD4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80221BE0;
    // 0x80221BD4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80221BD8:
    // 0x80221BD8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221BDC: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80221BE0:
    // 0x80221BE0: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x80221BE4: lbu         $t7, 0x1031($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1031);
    // 0x80221BE8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80221BEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80221BF0: beq         $t7, $at, L_80221C90
    if (ctx->r15 == ctx->r1) {
        // 0x80221BF4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80221C90;
    }
    // 0x80221BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80221BF8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80221BFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80221C00: jal         0x802237B0
    // 0x80221C04: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80221C04: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80221C08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80221C0C: jal         0x80010550
    // 0x80221C10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80221C10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80221C14: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80221C18: beq         $v0, $zero, L_80221C90
    if (ctx->r2 == 0) {
        // 0x80221C1C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80221C90;
    }
    // 0x80221C1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80221C20: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80221C24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80221C28: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221C2C: blez        $t8, L_80221C48
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80221C30: nop
    
            goto L_80221C48;
    }
    // 0x80221C30: nop

    // 0x80221C34: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x80221C38: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80221C3C: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x80221C40: beq         $t0, $zero, L_80221C58
    if (ctx->r8 == 0) {
        // 0x80221C44: sll         $t1, $v0, 9
        ctx->r9 = S32(ctx->r2 << 9);
            goto L_80221C58;
    }
    // 0x80221C44: sll         $t1, $v0, 9
    ctx->r9 = S32(ctx->r2 << 9);
L_80221C48:
    // 0x80221C48: jal         0x800058DC
    // 0x80221C4C: addiu       $a1, $a1, 0x2B08
    ctx->r5 = ADD32(ctx->r5, 0X2B08);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80221C4C: addiu       $a1, $a1, 0x2B08
    ctx->r5 = ADD32(ctx->r5, 0X2B08);
    after_2:
    // 0x80221C50: b           L_80221C94
    // 0x80221C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80221C94;
    // 0x80221C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221C58:
    // 0x80221C58: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80221C5C: bne         $t2, $zero, L_80221C84
    if (ctx->r10 != 0) {
        // 0x80221C60: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80221C84;
    }
    // 0x80221C60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80221C64: lbu         $t3, 0x2F9($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2F9);
    // 0x80221C68: lbu         $t8, 0x31($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X31);
    // 0x80221C6C: addiu       $t5, $t3, 0x2
    ctx->r13 = ADD32(ctx->r11, 0X2);
    // 0x80221C70: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80221C74: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x80221C78: andi        $t9, $t8, 0xFF9F
    ctx->r25 = ctx->r24 & 0XFF9F;
    // 0x80221C7C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80221C80: sb          $t0, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r8;
L_80221C84:
    // 0x80221C84: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221C88: jal         0x800058DC
    // 0x80221C8C: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80221C8C: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    after_3:
L_80221C90:
    // 0x80221C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80221C94:
    // 0x80221C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80221C98: jr          $ra
    // 0x80221C9C: nop

    return;
    // 0x80221C9C: nop

;}
RECOMP_FUNC void M10_FUN_80221ca0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221CA0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221CA4: lw          $v0, -0x4334($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4334);
    // 0x80221CA8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221CAC: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
    // 0x80221CB0: bne         $a0, $v0, L_80221CC4
    if (ctx->r4 != ctx->r2) {
        // 0x80221CB4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80221CC4;
    }
    // 0x80221CB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80221CB8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221CBC: b           L_80221CC4
    // 0x80221CC0: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80221CC4;
    // 0x80221CC0: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80221CC4:
    // 0x80221CC4: beq         $a0, $v0, L_80221CD4
    if (ctx->r4 == ctx->r2) {
        // 0x80221CC8: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80221CD4;
    }
    // 0x80221CC8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221CCC: b           L_80221CDC
    // 0x80221CD0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80221CDC;
    // 0x80221CD0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80221CD4:
    // 0x80221CD4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221CD8: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80221CDC:
    // 0x80221CDC: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x80221CE0: lbu         $a0, 0x2D8($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2D8);
    // 0x80221CE4: beql        $a0, $zero, L_80221D10
    if (ctx->r4 == 0) {
        // 0x80221CE8: lbu         $a0, 0x2D9($v0)
        ctx->r4 = MEM_BU(ctx->r2, 0X2D9);
            goto L_80221D10;
    }
    goto skip_0;
    // 0x80221CE8: lbu         $a0, 0x2D9($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2D9);
    skip_0:
    // 0x80221CEC: beq         $a0, $at, L_80221D0C
    if (ctx->r4 == ctx->r1) {
        // 0x80221CF0: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80221D0C;
    }
    // 0x80221CF0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80221CF4: beq         $a0, $at, L_80221D0C
    if (ctx->r4 == ctx->r1) {
        // 0x80221CF8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80221D0C;
    }
    // 0x80221CF8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80221CFC: beq         $a0, $at, L_80221D0C
    if (ctx->r4 == ctx->r1) {
        // 0x80221D00: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80221D0C;
    }
    // 0x80221D00: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80221D04: bne         $a0, $at, L_80221E90
    if (ctx->r4 != ctx->r1) {
            // 0x80221D08: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80221E90)(rdram, ctx);
    return;
    }
    // 0x80221D08: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_80221D0C:
    // 0x80221D0C: lbu         $a0, 0x2D9($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2D9);
L_80221D10:
    // 0x80221D10: slti        $at, $a0, 0x53
    ctx->r1 = SIGNED(ctx->r4) < 0X53 ? 1 : 0;
    // 0x80221D14: bne         $at, $zero, L_80221D34
    if (ctx->r1 != 0) {
        // 0x80221D18: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_80221D34;
    }
    // 0x80221D18: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80221D1C: beq         $a0, $at, L_80221E3C
    if (ctx->r4 == ctx->r1) {
        // 0x80221D20: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_80221E3C;
    }
    // 0x80221D20: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80221D24: beql        $a0, $at, L_80221E4C
    if (ctx->r4 == ctx->r1) {
        // 0x80221D28: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80221E4C;
    }
    goto skip_1;
    // 0x80221D28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_1:
    // 0x80221D2C: b           L_80221E4C
    // 0x80221D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80221E4C;
    // 0x80221D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80221D34:
    // 0x80221D34: slti        $at, $a0, 0x25
    ctx->r1 = SIGNED(ctx->r4) < 0X25 ? 1 : 0;
    // 0x80221D38: bne         $at, $zero, L_80221D50
    if (ctx->r1 != 0) {
        // 0x80221D3C: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80221D50;
    }
    // 0x80221D3C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80221D40: beql        $a0, $at, L_80221D74
    if (ctx->r4 == ctx->r1) {
        // 0x80221D44: lw          $t7, 0x30($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X30);
            goto L_80221D74;
    }
    goto skip_2;
    // 0x80221D44: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    skip_2:
    // 0x80221D48: b           L_80221E4C
    // 0x80221D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80221E4C;
    // 0x80221D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80221D50:
    // 0x80221D50: sltiu       $at, $a0, 0x25
    ctx->r1 = ctx->r4 < 0X25 ? 1 : 0;
    // 0x80221D54: beq         $at, $zero, L_80221E48
    if (ctx->r1 == 0) {
        // 0x80221D58: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80221E48;
    }
    // 0x80221D58: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80221D5C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80221D60: addu        $at, $at, $t6
    gpr jr_addend_80221D68 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80221D64: lw          $t6, -0x13BC($at)
    ctx->r14 = ADD32(ctx->r1, -0X13BC);
    // 0x80221D68: jr          $t6
    // 0x80221D6C: nop

    switch (jr_addend_80221D68 >> 2) {
        case 0: goto L_80221E3C; break;
        case 1: goto L_80221E3C; break;
        case 2: goto L_80221E3C; break;
        case 3: goto L_80221E3C; break;
        case 4: goto L_80221E3C; break;
        case 5: goto L_80221E3C; break;
        case 6: goto L_80221E3C; break;
        case 7: goto L_80221E3C; break;
        case 8: goto L_80221E48; break;
        case 9: goto L_80221E48; break;
        case 10: goto L_80221E48; break;
        case 11: goto L_80221E48; break;
        case 12: goto L_80221E48; break;
        case 13: goto L_80221E48; break;
        case 14: goto L_80221E18; break;
        case 15: goto L_80221DF4; break;
        case 16: goto L_80221E24; break;
        case 17: goto L_80221E00; break;
        case 18: goto L_80221E30; break;
        case 19: goto L_80221E0C; break;
        case 20: goto L_80221E3C; break;
        case 21: goto L_80221E3C; break;
        case 22: goto L_80221E48; break;
        case 23: goto L_80221E48; break;
        case 24: goto L_80221E30; break;
        case 25: goto L_80221E0C; break;
        case 26: goto L_80221E3C; break;
        case 27: goto L_80221E3C; break;
        case 28: goto L_80221E48; break;
        case 29: goto L_80221E48; break;
        case 30: goto L_80221E30; break;
        case 31: goto L_80221E0C; break;
        case 32: goto L_80221DF4; break;
        case 33: goto L_80221E18; break;
        case 34: goto L_80221E48; break;
        case 35: goto L_80221D9C; break;
        case 36: goto L_80221DC8; break;
        default: switch_error(__func__, 0x80221D68, 0x8023EC44);
    }
    // 0x80221D6C: nop

    // 0x80221D70: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
L_80221D74:
    // 0x80221D74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80221D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80221D7C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80221D80: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80221D84: bne         $t9, $at, L_80221D94
    if (ctx->r25 != ctx->r1) {
        // 0x80221D88: nop
    
            goto L_80221D94;
    }
    // 0x80221D88: nop

    // 0x80221D8C: b           L_80221E50
    // 0x80221D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80221E50;
    // 0x80221D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80221D94:
    // 0x80221D94: b           L_80221E50
    // 0x80221D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80221E50;
    // 0x80221D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80221D9C:
    // 0x80221D9C: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x80221DA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80221DA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80221DA8: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x80221DAC: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80221DB0: bne         $t2, $at, L_80221DC0
    if (ctx->r10 != ctx->r1) {
        // 0x80221DB4: nop
    
            goto L_80221DC0;
    }
    // 0x80221DB4: nop

    // 0x80221DB8: b           L_80221E50
    // 0x80221DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80221E50;
    // 0x80221DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80221DC0:
    // 0x80221DC0: b           L_80221E50
    // 0x80221DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80221E50;
    // 0x80221DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80221DC8:
    // 0x80221DC8: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x80221DCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80221DD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221DD4: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80221DD8: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x80221DDC: bne         $t5, $at, L_80221DEC
    if (ctx->r13 != ctx->r1) {
        // 0x80221DE0: nop
    
            goto L_80221DEC;
    }
    // 0x80221DE0: nop

    // 0x80221DE4: b           L_80221E50
    // 0x80221DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80221E50;
    // 0x80221DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80221DEC:
    // 0x80221DEC: b           L_80221E50
    // 0x80221DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80221E50;
    // 0x80221DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80221DF4:
    // 0x80221DF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80221DF8: b           L_80221E50
    // 0x80221DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80221E50;
    // 0x80221DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80221E00:
    // 0x80221E00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221E04: b           L_80221E50
    // 0x80221E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80221E50;
    // 0x80221E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80221E0C:
    // 0x80221E0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80221E10: b           L_80221E50
    // 0x80221E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80221E50;
    // 0x80221E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80221E18:
    // 0x80221E18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80221E1C: b           L_80221E50
    // 0x80221E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80221E50;
    // 0x80221E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80221E24:
    // 0x80221E24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80221E28: b           L_80221E50
    // 0x80221E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80221E50;
    // 0x80221E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80221E30:
    // 0x80221E30: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80221E34: b           L_80221E50
    // 0x80221E38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80221E50;
    // 0x80221E38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80221E3C:
    // 0x80221E3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80221E40: b           L_80221E50
    // 0x80221E44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80221E50;
    // 0x80221E44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80221E48:
    // 0x80221E48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80221E4C:
    // 0x80221E4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80221E50:
    // 0x80221E50: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80221E54: beq         $at, $zero, L_80221E7C
    if (ctx->r1 == 0) {
        // 0x80221E58: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80221E7C;
    }
    // 0x80221E58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80221E5C: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x80221E60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80221E64: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80221E68: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80221E6C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80221E70: bnel        $t8, $at, L_80221E80
    if (ctx->r24 != ctx->r1) {
        // 0x80221E74: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80221E80;
    }
    goto skip_3;
    // 0x80221E74: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    skip_3:
    // 0x80221E78: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
L_80221E7C:
    // 0x80221E7C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
L_80221E80:
    // 0x80221E80: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80221E84: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80221E88: jr          $ra
    // 0x80221E8C: sb          $t0, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r8;
    return;
    // 0x80221E8C: sb          $t0, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80221e90(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80221e90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221E90: sb          $t1, 0x2D9($v1)
    MEM_B(0X2D9, ctx->r3) = ctx->r9;
    // 0x80221E94: jr          $ra
    // 0x80221E98: nop

    return;
    // 0x80221E98: nop

;}
RECOMP_FUNC void M10_FUN_80221e9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221E9C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80221EA0: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80221EA4: lw          $v1, 0xDC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80221ea8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80221ea8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221EA8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80221EAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80221EB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80221EB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80221EB8: bne         $a0, $v1, L_80221ECC
    if (ctx->r4 != ctx->r3) {
        // 0x80221EBC: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_80221ECC;
    }
    // 0x80221EBC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80221EC0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221EC4: b           L_80221ED4
    // 0x80221EC8: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80221ED4;
    // 0x80221EC8: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80221ECC:
    // 0x80221ECC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80221ED0: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80221ED4:
    // 0x80221ED4: beq         $s0, $v1, L_80221EE4
    if (ctx->r16 == ctx->r3) {
        // 0x80221ED8: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80221EE4;
    }
    // 0x80221ED8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221EDC: b           L_80221EEC
    // 0x80221EE0: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80221EEC;
    // 0x80221EE0: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80221EE4:
    // 0x80221EE4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80221EE8: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80221EEC:
    // 0x80221EEC: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x80221EF0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80221EF4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80221EF8: sb          $zero, 0x392($v0)
    MEM_B(0X392, ctx->r2) = 0;
    // 0x80221EFC: lbu         $t7, 0x1031($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1031);
    // 0x80221F00: beql        $t7, $at, L_80221FE0
    if (ctx->r15 == ctx->r1) {
        // 0x80221F04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80221FE0;
    }
    goto skip_0;
    // 0x80221F04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80221F08: lbu         $t8, 0x30($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X30);
    // 0x80221F0C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80221F10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80221F14: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80221F18: bnel        $t9, $zero, L_80221F3C
    if (ctx->r25 != 0) {
        // 0x80221F1C: lw          $t0, 0x30($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X30);
            goto L_80221F3C;
    }
    goto skip_1;
    // 0x80221F1C: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    skip_1:
    // 0x80221F20: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221F24: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    // 0x80221F28: jal         0x800058DC
    // 0x80221F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80221F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80221F30: b           L_80221FE0
    // 0x80221F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80221FE0;
    // 0x80221F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80221F38: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
L_80221F3C:
    // 0x80221F3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80221F40: sb          $zero, 0x2F1($v0)
    MEM_B(0X2F1, ctx->r2) = 0;
    // 0x80221F44: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x80221F48: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80221F4C: sb          $zero, 0x365($v0)
    MEM_B(0X365, ctx->r2) = 0;
    // 0x80221F50: swc1        $f0, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f0.u32l;
    // 0x80221F54: swc1        $f0, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f0.u32l;
    // 0x80221F58: bne         $t2, $zero, L_80221F80
    if (ctx->r10 != 0) {
        // 0x80221F5C: swc1        $f0, 0x368($v0)
        MEM_W(0X368, ctx->r2) = ctx->f0.u32l;
            goto L_80221F80;
    }
    // 0x80221F5C: swc1        $f0, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f0.u32l;
    // 0x80221F60: lbu         $t3, 0x2F9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2F9);
    // 0x80221F64: lbu         $t8, 0x31($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X31);
    // 0x80221F68: addiu       $t5, $t3, 0x2
    ctx->r13 = ADD32(ctx->r11, 0X2);
    // 0x80221F6C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80221F70: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x80221F74: andi        $t9, $t8, 0xFF9F
    ctx->r25 = ctx->r24 & 0XFF9F;
    // 0x80221F78: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80221F7C: sb          $t0, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r8;
L_80221F80:
    // 0x80221F80: jal         0x802256E4
    // 0x80221F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x80221F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80221F88: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x80221F8C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80221F90: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80221F94: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80221F98: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x80221F9C: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x80221FA0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80221FA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80221FA8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80221FAC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80221FB0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80221FB4: jal         0x80011140
    // 0x80221FB8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x80221FB8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_2:
    // 0x80221FBC: beql        $v0, $zero, L_80221FE0
    if (ctx->r2 == 0) {
        // 0x80221FC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80221FE0;
    }
    goto skip_2;
    // 0x80221FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80221FC4: jal         0x80221CA0
    // 0x80221FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80221CA0)(rdram, ctx);
        goto after_3;
    // 0x80221FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80221FCC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80221FD0: addiu       $a1, $a1, 0x1FF0
    ctx->r5 = ADD32(ctx->r5, 0X1FF0);
    // 0x80221FD4: jal         0x800058DC
    // 0x80221FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80221FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80221FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80221FE0:
    // 0x80221FE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80221FE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80221FE8: jr          $ra
    // 0x80221FEC: nop

    return;
    // 0x80221FEC: nop

;}
RECOMP_FUNC void M10_FUN_80221ff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221FF0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80221FF4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80221FF8: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80221ffc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80221ffc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80221FFC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80222000: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80222004: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80222008: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8022200C: bne         $a0, $v0, L_80222020
    if (ctx->r4 != ctx->r2) {
        // 0x80222010: sw          $a1, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r5;
            goto L_80222020;
    }
    // 0x80222010: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80222014: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222018: b           L_80222028
    // 0x8022201C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80222028;
    // 0x8022201C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80222020:
    // 0x80222020: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222024: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80222028:
    // 0x80222028: beq         $s0, $v0, L_80222038
    if (ctx->r16 == ctx->r2) {
        // 0x8022202C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80222038;
    }
    // 0x8022202C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222030: b           L_80222040
    // 0x80222034: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80222040;
    // 0x80222034: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80222038:
    // 0x80222038: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022203C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80222040:
    // 0x80222040: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x80222044: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80222048: addiu       $t7, $t7, -0x3D64
    ctx->r15 = ADD32(ctx->r15, -0X3D64);
    // 0x8022204C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80222050: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80222054: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80222058: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8022205C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80222060: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80222064: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80222068: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x8022206C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80222070: sw          $t9, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r25;
    // 0x80222074: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80222078: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
    // 0x8022207C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80222080: sw          $t9, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r25;
    // 0x80222084: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80222088: sw          $t8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r24;
    // 0x8022208C: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80222090: sw          $t9, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r25;
    // 0x80222094: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80222098: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x8022209C: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x802220A0: lbu         $t0, 0x1031($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X1031);
    // 0x802220A4: beql        $t0, $at, L_80222200
    if (ctx->r8 == ctx->r1) {
        // 0x802220A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80222200;
    }
    goto skip_0;
    // 0x802220A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x802220AC: lbu         $t1, 0x30($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X30);
    // 0x802220B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802220B4: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x802220B8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x802220BC: bne         $t2, $zero, L_802220D8
    if (ctx->r10 != 0) {
        // 0x802220C0: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_802220D8;
    }
    // 0x802220C0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x802220C4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802220C8: jal         0x800058DC
    // 0x802220CC: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802220CC: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    after_0:
    // 0x802220D0: b           L_80222200
    // 0x802220D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80222200;
    // 0x802220D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802220D8:
    // 0x802220D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802220DC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x802220E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x802220E4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x802220E8: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x802220EC: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x802220F0: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x802220F4: nop

    // 0x802220F8: bc1fl       L_80222108
    if (!c1cs) {
        // 0x802220FC: lbu         $t6, 0x2D9($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X2D9);
            goto L_80222108;
    }
    goto skip_1;
    // 0x802220FC: lbu         $t6, 0x2D9($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2D9);
    skip_1:
    // 0x80222100: sb          $t5, 0x2F1($v1)
    MEM_B(0X2F1, ctx->r3) = ctx->r13;
    // 0x80222104: lbu         $t6, 0x2D9($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2D9);
L_80222108:
    // 0x80222108: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8022210C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80222110: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80222114: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80222118: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8022211C: jal         0x80225664
    // 0x80222120: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80225664)(rdram, ctx);
        goto after_1;
    // 0x80222120: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80222124: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80222128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022212C: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80222130: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80222134: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80222138: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8022213C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80222140: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80222144: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80222148: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8022214C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80222150: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80222154: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80222158: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8022215C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x80222160: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80222164: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80222168: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8022216C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80222170: nop

    // 0x80222174: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80222178: beql        $t3, $zero, L_802221C8
    if (ctx->r11 == 0) {
        // 0x8022217C: mfc1        $t3, $f18
        ctx->r11 = (int32_t)ctx->f18.u32l;
            goto L_802221C8;
    }
    goto skip_2;
    // 0x8022217C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x80222180: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80222184: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80222188: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8022218C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80222190: nop

    // 0x80222194: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80222198: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8022219C: nop

    // 0x802221A0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x802221A4: bne         $t3, $zero, L_802221BC
    if (ctx->r11 != 0) {
        // 0x802221A8: nop
    
            goto L_802221BC;
    }
    // 0x802221A8: nop

    // 0x802221AC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x802221B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802221B4: b           L_802221D4
    // 0x802221B8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_802221D4;
    // 0x802221B8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_802221BC:
    // 0x802221BC: b           L_802221D4
    // 0x802221C0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_802221D4;
    // 0x802221C0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x802221C4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
L_802221C8:
    // 0x802221C8: nop

    // 0x802221CC: bltz        $t3, L_802221BC
    if (SIGNED(ctx->r11) < 0) {
        // 0x802221D0: nop
    
            goto L_802221BC;
    }
    // 0x802221D0: nop

L_802221D4:
    // 0x802221D4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x802221D8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x802221DC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x802221E0: jal         0x80011140
    // 0x802221E4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x802221E4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_2:
    // 0x802221E8: beq         $v0, $zero, L_802221FC
    if (ctx->r2 == 0) {
        // 0x802221EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802221FC;
    }
    // 0x802221EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802221F0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802221F4: jal         0x800058DC
    // 0x802221F8: addiu       $a1, $a1, 0x2210
    ctx->r5 = ADD32(ctx->r5, 0X2210);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x802221F8: addiu       $a1, $a1, 0x2210
    ctx->r5 = ADD32(ctx->r5, 0X2210);
    after_3:
L_802221FC:
    // 0x802221FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80222200:
    // 0x80222200: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80222204: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80222208: jr          $ra
    // 0x8022220C: nop

    return;
    // 0x8022220C: nop

;}
RECOMP_FUNC void M10_FUN_80222210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222210: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80222214: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x80222218: lw          $v1, 0xDC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022221c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022221c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022221C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80222220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80222224: bne         $a0, $v1, L_80222238
    if (ctx->r4 != ctx->r3) {
        // 0x80222228: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80222238;
    }
    // 0x80222228: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8022222C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222230: b           L_80222240
    // 0x80222234: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80222240;
    // 0x80222234: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80222238:
    // 0x80222238: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022223C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80222240:
    // 0x80222240: beq         $a0, $v1, L_80222254
    if (ctx->r4 == ctx->r3) {
        // 0x80222244: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_80222254;
    }
    // 0x80222244: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80222248: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022224C: b           L_80222258
    // 0x80222250: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_80222258;
    // 0x80222250: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_80222254:
    // 0x80222254: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_80222258:
    // 0x80222258: sb          $zero, 0x392($v0)
    MEM_B(0X392, ctx->r2) = 0;
    // 0x8022225C: lbu         $t6, 0x1031($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1031);
    // 0x80222260: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80222264: beql        $t6, $at, L_80222364
    if (ctx->r14 == ctx->r1) {
        // 0x80222268: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80222364;
    }
    goto skip_0;
    // 0x80222268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8022226C: lbu         $t7, 0x32($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X32);
    // 0x80222270: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80222274: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222278: andi        $t8, $t7, 0xFF1F
    ctx->r24 = ctx->r15 & 0XFF1F;
    // 0x8022227C: blez        $t9, L_80222298
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80222280: sb          $t8, 0x32($v0)
        MEM_B(0X32, ctx->r2) = ctx->r24;
            goto L_80222298;
    }
    // 0x80222280: sb          $t8, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r24;
    // 0x80222284: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80222288: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x8022228C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80222290: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80222294: beq         $t2, $zero, L_802222B4
    if (ctx->r10 == 0) {
        // 0x80222298: addiu       $a1, $a1, 0x2B08
        ctx->r5 = ADD32(ctx->r5, 0X2B08);
            goto L_802222B4;
    }
L_80222298:
    // 0x80222298: addiu       $a1, $a1, 0x2B08
    ctx->r5 = ADD32(ctx->r5, 0X2B08);
    // 0x8022229C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x802222A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x802222A4: jal         0x800058DC
    // 0x802222A8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x802222A8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x802222AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x802222B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_802222B4:
    // 0x802222B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x802222B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802222BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x802222C0: jal         0x80367460
    // 0x802222C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80367460)(rdram, ctx);
        goto after_1;
    // 0x802222C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x802222C8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x802222CC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x802222D0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x802222D4: lbu         $v1, 0x2D8($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2D8);
    // 0x802222D8: beq         $v1, $at, L_802222E8
    if (ctx->r3 == ctx->r1) {
        // 0x802222DC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_802222E8;
    }
    // 0x802222DC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x802222E0: bnel        $v1, $at, L_80222300
    if (ctx->r3 != ctx->r1) {
        // 0x802222E4: lbu         $t4, 0x30($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X30);
            goto L_80222300;
    }
    goto skip_1;
    // 0x802222E4: lbu         $t4, 0x30($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X30);
    skip_1:
L_802222E8:
    // 0x802222E8: lbu         $t3, 0x375($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X375);
    // 0x802222EC: blezl       $t3, L_80222364
    if (SIGNED(ctx->r11) <= 0) {
        // 0x802222F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80222364;
    }
    goto skip_2;
    // 0x802222F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x802222F4: b           L_8022230C
    // 0x802222F8: sb          $zero, 0x2F1($v0)
    MEM_B(0X2F1, ctx->r2) = 0;
        goto L_8022230C;
    // 0x802222F8: sb          $zero, 0x2F1($v0)
    MEM_B(0X2F1, ctx->r2) = 0;
    // 0x802222FC: lbu         $t4, 0x30($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X30);
L_80222300:
    // 0x80222300: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80222304: bnel        $t5, $zero, L_80222364
    if (ctx->r13 != 0) {
        // 0x80222308: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80222364;
    }
    goto skip_3;
    // 0x80222308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_8022230C:
    // 0x8022230C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80222310: jal         0x80225540
    // 0x80222314: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80225540)(rdram, ctx);
        goto after_2;
    // 0x80222314: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80222318: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8022231C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222320: addiu       $a1, $a1, 0x2370
    ctx->r5 = ADD32(ctx->r5, 0X2370);
    // 0x80222324: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80222328: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8022232C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80222330: bne         $t8, $zero, L_80222358
    if (ctx->r24 != 0) {
        // 0x80222334: nop
    
            goto L_80222358;
    }
    // 0x80222334: nop

    // 0x80222338: lbu         $t9, 0x2F9($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2F9);
    // 0x8022233C: lbu         $t4, 0x31($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X31);
    // 0x80222340: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x80222344: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80222348: andi        $t3, $t2, 0x60
    ctx->r11 = ctx->r10 & 0X60;
    // 0x8022234C: andi        $t5, $t4, 0xFF9F
    ctx->r13 = ctx->r12 & 0XFF9F;
    // 0x80222350: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80222354: sb          $t6, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r14;
L_80222358:
    // 0x80222358: jal         0x800058DC
    // 0x8022235C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8022235C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80222360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222364:
    // 0x80222364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80222368: jr          $ra
    // 0x8022236C: nop

    return;
    // 0x8022236C: nop

;}
RECOMP_FUNC void M10_FUN_80222370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222370: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80222374: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x80222378: lw          $t6, 0xDC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022237c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022237c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022237C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80222380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80222384: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80222388: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8022238C: bne         $a0, $t6, L_802223A0
    if (ctx->r4 != ctx->r14) {
        // 0x80222390: lw          $v0, 0x5C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X5C);
            goto L_802223A0;
    }
    // 0x80222390: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80222394: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222398: b           L_802223A8
    // 0x8022239C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_802223A8;
    // 0x8022239C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_802223A0:
    // 0x802223A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802223A4: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_802223A8:
    // 0x802223A8: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x802223AC: lbu         $t7, 0x1031($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1031);
    // 0x802223B0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x802223B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x802223B8: beq         $t7, $at, L_80222440
    if (ctx->r15 == ctx->r1) {
        // 0x802223BC: addiu       $a1, $v0, 0x22
        ctx->r5 = ADD32(ctx->r2, 0X22);
            goto L_80222440;
    }
    // 0x802223BC: addiu       $a1, $v0, 0x22
    ctx->r5 = ADD32(ctx->r2, 0X22);
    // 0x802223C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x802223C4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x802223C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x802223CC: jal         0x80011258
    // 0x802223D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80011258)(rdram, ctx);
        goto after_0;
    // 0x802223D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x802223D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x802223D8: jal         0x800113D0
    // 0x802223DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_1;
    // 0x802223DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x802223E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x802223E4: jal         0x80010550
    // 0x802223E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x802223E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x802223EC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x802223F0: beq         $v0, $zero, L_80222440
    if (ctx->r2 == 0) {
        // 0x802223F4: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80222440;
    }
    // 0x802223F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x802223F8: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x802223FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80222400: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222404: blez        $t8, L_80222420
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80222408: nop
    
            goto L_80222420;
    }
    // 0x80222408: nop

    // 0x8022240C: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x80222410: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80222414: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80222418: beq         $t1, $zero, L_80222430
    if (ctx->r9 == 0) {
        // 0x8022241C: nop
    
            goto L_80222430;
    }
    // 0x8022241C: nop

L_80222420:
    // 0x80222420: jal         0x800058DC
    // 0x80222424: addiu       $a1, $a1, 0x2B08
    ctx->r5 = ADD32(ctx->r5, 0X2B08);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80222424: addiu       $a1, $a1, 0x2B08
    ctx->r5 = ADD32(ctx->r5, 0X2B08);
    after_3:
    // 0x80222428: b           L_80222444
    // 0x8022242C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222444;
    // 0x8022242C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222430:
    // 0x80222430: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222434: addiu       $a1, $a1, 0x2708
    ctx->r5 = ADD32(ctx->r5, 0X2708);
    // 0x80222438: jal         0x800058DC
    // 0x8022243C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8022243C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
L_80222440:
    // 0x80222440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222444:
    // 0x80222444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80222448: jr          $ra
    // 0x8022244C: nop

    return;
    // 0x8022244C: nop

;}
RECOMP_FUNC void M10_FUN_80222450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222450: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80222454: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80222458: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x8022245C: lw          $v0, 0xDC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XDC);
    // 0x80222460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80222464: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80222468: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8022246C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80222470: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80222474: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80222478: bne         $a0, $v0, L_8022248C
    if (ctx->r4 != ctx->r2) {
        // 0x8022247C: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8022248C;
    }
    // 0x8022247C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80222480: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222484: b           L_80222494
    // 0x80222488: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80222494;
    // 0x80222488: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_8022248C:
    // 0x8022248C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222490: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80222494:
    // 0x80222494: beq         $s0, $v0, L_802224A8
    if (ctx->r16 == ctx->r2) {
        // 0x80222498: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_802224A8;
    }
    // 0x80222498: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022249C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x802224A0: b           L_802224AC
    // 0x802224A4: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_802224AC;
    // 0x802224A4: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_802224A8:
    // 0x802224A8: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_802224AC:
    // 0x802224AC: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
    // 0x802224B0: lbu         $t7, 0x1031($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1031);
    // 0x802224B4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x802224B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802224BC: beq         $t7, $at, L_802226F4
    if (ctx->r15 == ctx->r1) {
        // 0x802224C0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_802226F4;
    }
    // 0x802224C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802224C4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x802224C8: jal         0x802237B0
    // 0x802224CC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x802224CC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x802224D0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x802224D4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x802224D8: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    // 0x802224DC: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x802224E0: sb          $zero, 0x2F1($v1)
    MEM_B(0X2F1, ctx->r3) = 0;
    // 0x802224E4: andi        $t9, $t8, 0xFF1F
    ctx->r25 = ctx->r24 & 0XFF1F;
    // 0x802224E8: sb          $t9, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r25;
    // 0x802224EC: sb          $zero, 0x391($v1)
    MEM_B(0X391, ctx->r3) = 0;
    // 0x802224F0: sb          $zero, 0x393($v1)
    MEM_B(0X393, ctx->r3) = 0;
    // 0x802224F4: blez        $t0, L_80222510
    if (SIGNED(ctx->r8) <= 0) {
        // 0x802224F8: sb          $zero, 0x328($v1)
        MEM_B(0X328, ctx->r3) = 0;
            goto L_80222510;
    }
    // 0x802224F8: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
    // 0x802224FC: lw          $a0, 0x30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X30);
    // 0x80222500: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80222504: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80222508: beql        $t2, $zero, L_80222528
    if (ctx->r10 == 0) {
        // 0x8022250C: lhu         $t3, 0x30($v1)
        ctx->r11 = MEM_HU(ctx->r3, 0X30);
            goto L_80222528;
    }
    goto skip_0;
    // 0x8022250C: lhu         $t3, 0x30($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X30);
    skip_0:
L_80222510:
    // 0x80222510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80222514: jal         0x802233B0
    // 0x80222518: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x802233B0)(rdram, ctx);
        goto after_1;
    // 0x80222518: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x8022251C: b           L_802226F8
    // 0x80222520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802226F8;
    // 0x80222520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80222524: lhu         $t3, 0x30($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X30);
L_80222528:
    // 0x80222528: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022252C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80222530: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x80222534: bne         $t4, $at, L_8022254C
    if (ctx->r12 != ctx->r1) {
        // 0x80222538: srl         $v0, $v0, 28
        ctx->r2 = S32(U32(ctx->r2) >> 28);
            goto L_8022254C;
    }
    // 0x80222538: srl         $v0, $v0, 28
    ctx->r2 = S32(U32(ctx->r2) >> 28);
    // 0x8022253C: jal         0x8022397C
    // 0x80222540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8022397C)(rdram, ctx);
        goto after_2;
    // 0x80222540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80222544: b           L_802226F8
    // 0x80222548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802226F8;
    // 0x80222548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8022254C:
    // 0x8022254C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80222550: bnel        $v0, $at, L_80222590
    if (ctx->r2 != ctx->r1) {
        // 0x80222554: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80222590;
    }
    goto skip_1;
    // 0x80222554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x80222558: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
    // 0x8022255C: blezl       $t5, L_80222590
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80222560: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80222590;
    }
    goto skip_2;
    // 0x80222560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_2:
    // 0x80222564: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x80222568: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8022256C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80222570: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80222574: bnel        $t8, $zero, L_80222590
    if (ctx->r24 != 0) {
        // 0x80222578: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80222590;
    }
    goto skip_3;
    // 0x80222578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_3:
    // 0x8022257C: jal         0x80366B30
    // 0x80222580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80366B30)(rdram, ctx);
        goto after_3;
    // 0x80222580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80222584: b           L_802226F8
    // 0x80222588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802226F8;
    // 0x80222588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8022258C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80222590:
    // 0x80222590: bne         $v0, $at, L_802225CC
    if (ctx->r2 != ctx->r1) {
        // 0x80222594: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_802225CC;
    }
    // 0x80222594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80222598: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x8022259C: blezl       $t9, L_802225D0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x802225A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_802225D0;
    }
    goto skip_4;
    // 0x802225A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_4:
    // 0x802225A4: lw          $t0, 0x30($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X30);
    // 0x802225A8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x802225AC: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x802225B0: bnel        $t2, $zero, L_802225D0
    if (ctx->r10 != 0) {
        // 0x802225B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_802225D0;
    }
    goto skip_5;
    // 0x802225B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_5:
    // 0x802225B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802225BC: jal         0x803667C4
    // 0x802225C0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x803667C4)(rdram, ctx);
        goto after_4;
    // 0x802225C0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x802225C4: b           L_802226F8
    // 0x802225C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802226F8;
    // 0x802225C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802225CC:
    // 0x802225CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_802225D0:
    // 0x802225D0: bne         $v0, $at, L_802225E8
    if (ctx->r2 != ctx->r1) {
        // 0x802225D4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_802225E8;
    }
    // 0x802225D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802225D8: lbu         $t3, 0x30($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X30);
    // 0x802225DC: andi        $t4, $t3, 0xFFE1
    ctx->r12 = ctx->r11 & 0XFFE1;
    // 0x802225E0: sb          $t4, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r12;
    // 0x802225E4: lw          $a0, 0x30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X30);
L_802225E8:
    // 0x802225E8: sll         $t5, $a0, 9
    ctx->r13 = S32(ctx->r4 << 9);
    // 0x802225EC: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x802225F0: bne         $t6, $zero, L_80222618
    if (ctx->r14 != 0) {
        // 0x802225F4: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80222618;
    }
    // 0x802225F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x802225F8: lbu         $t7, 0x2F9($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2F9);
    // 0x802225FC: lbu         $t2, 0x31($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X31);
    // 0x80222600: addiu       $t9, $t7, 0x2
    ctx->r25 = ADD32(ctx->r15, 0X2);
    // 0x80222604: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80222608: andi        $t1, $t0, 0x60
    ctx->r9 = ctx->r8 & 0X60;
    // 0x8022260C: andi        $t3, $t2, 0xFF9F
    ctx->r11 = ctx->r10 & 0XFF9F;
    // 0x80222610: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80222614: sb          $t4, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r12;
L_80222618:
    // 0x80222618: jal         0x802256E4
    // 0x8022261C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_5;
    // 0x8022261C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_5:
    // 0x80222620: lhu         $t5, 0x36($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X36);
    // 0x80222624: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x80222628: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8022262C: bne         $t5, $at, L_80222660
    if (ctx->r13 != ctx->r1) {
        // 0x80222630: addiu       $t2, $sp, 0x30
        ctx->r10 = ADD32(ctx->r29, 0X30);
            goto L_80222660;
    }
    // 0x80222630: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80222634: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x80222638: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x8022263C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80222640: beql        $t8, $zero, L_80222664
    if (ctx->r24 == 0) {
        // 0x80222644: lw          $t3, 0x0($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X0);
            goto L_80222664;
    }
    goto skip_6;
    // 0x80222644: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    skip_6:
    // 0x80222648: lbu         $t9, 0x390($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X390);
    // 0x8022264C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80222650: lui         $t0, 0x191
    ctx->r8 = S32(0X191 << 16);
    // 0x80222654: bne         $t9, $at, L_80222660
    if (ctx->r25 != ctx->r1) {
        // 0x80222658: ori         $t0, $t0, 0x9E
        ctx->r8 = ctx->r8 | 0X9E;
            goto L_80222660;
    }
    // 0x80222658: ori         $t0, $t0, 0x9E
    ctx->r8 = ctx->r8 | 0X9E;
    // 0x8022265C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_80222660:
    // 0x80222660: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
L_80222664:
    // 0x80222664: lhu         $t4, 0x52($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X52);
    // 0x80222668: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8022266C: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x80222670: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x80222674: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80222678: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8022267C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80222680: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80222684: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80222688: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8022268C: jal         0x80011140
    // 0x80222690: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_6;
    // 0x80222690: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_6:
    // 0x80222694: beq         $v0, $zero, L_802226F0
    if (ctx->r2 == 0) {
        // 0x80222698: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_802226F0;
    }
    // 0x80222698: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8022269C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802226A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x802226A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802226A8: jal         0x8013C7F8
    // 0x802226AC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8013C7F8)(rdram, ctx);
        goto after_7;
    // 0x802226AC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_7:
    // 0x802226B0: lhu         $t5, 0x36($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X36);
    // 0x802226B4: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x802226B8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x802226BC: beq         $t5, $at, L_802226D8
    if (ctx->r13 == ctx->r1) {
        // 0x802226C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802226D8;
    }
    // 0x802226C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802226C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x802226C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x802226CC: jal         0x8013C6FC
    // 0x802226D0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8013C6FC)(rdram, ctx);
        goto after_8;
    // 0x802226D0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_8:
    // 0x802226D4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_802226D8:
    // 0x802226D8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802226DC: addiu       $a1, $a1, 0x27A4
    ctx->r5 = ADD32(ctx->r5, 0X27A4);
    // 0x802226E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802226E4: jal         0x800058DC
    // 0x802226E8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x802226E8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_9:
    // 0x802226EC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_802226F0:
    // 0x802226F0: sb          $zero, 0x392($v1)
    MEM_B(0X392, ctx->r3) = 0;
L_802226F4:
    // 0x802226F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802226F8:
    // 0x802226F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802226FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80222700: jr          $ra
    // 0x80222704: nop

    return;
    // 0x80222704: nop

;}
RECOMP_FUNC void M10_FUN_80222708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222708: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8022270C: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80222710(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80222710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80222714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80222718: bne         $a0, $t6, L_8022272C
    if (ctx->r4 != ctx->r14) {
        // 0x8022271C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8022272C;
    }
    // 0x8022271C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80222720: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222724: b           L_80222734
    // 0x80222728: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80222734;
    // 0x80222728: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_8022272C:
    // 0x8022272C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222730: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80222734:
    // 0x80222734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80222738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8022273C: jal         0x802237B0
    // 0x80222740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80222740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80222744: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80222748: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8022274C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80222750: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x80222754: lbu         $t3, 0x38($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X38);
    // 0x80222758: lbu         $t1, 0x31($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X31);
    // 0x8022275C: andi        $t9, $t7, 0xFF7F
    ctx->r25 = ctx->r15 & 0XFF7F;
    // 0x80222760: andi        $t5, $t3, 0xFF7F
    ctx->r13 = ctx->r11 & 0XFF7F;
    // 0x80222764: andi        $t7, $t5, 0xEF
    ctx->r15 = ctx->r13 & 0XEF;
    // 0x80222768: sb          $t5, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r13;
    // 0x8022276C: andi        $t0, $t9, 0xFE
    ctx->r8 = ctx->r25 & 0XFE;
    // 0x80222770: andi        $t8, $t7, 0x9F
    ctx->r24 = ctx->r15 & 0X9F;
    // 0x80222774: sb          $t9, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r25;
    // 0x80222778: sb          $t7, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r15;
    // 0x8022277C: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x80222780: sb          $t0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r8;
    // 0x80222784: sb          $t2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r10;
    // 0x80222788: sb          $t8, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r24;
    // 0x8022278C: jal         0x80222450
    // 0x80222790: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80222450)(rdram, ctx);
        goto after_1;
    // 0x80222790: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80222794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80222798: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8022279C: jr          $ra
    // 0x802227A0: nop

    return;
    // 0x802227A0: nop

;}
