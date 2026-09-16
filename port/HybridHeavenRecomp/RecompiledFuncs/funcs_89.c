#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_801fca4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCA4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FCA50: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FCA54: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801FCA58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FCA5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801FCA60: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801FCA64: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801FCA68: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801FCA6C: lw          $a3, 0x30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X30);
    // 0x801FCA70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801FCA74: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801FCA78: jal         0x8012FFDC
    // 0x801FCA7C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012FFDC)(rdram, ctx);
        goto after_0;
    // 0x801FCA7C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801FCA80: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801FCA84: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FCA88: ldc1        $f8, -0x7088($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X7088);
    // 0x801FCA8C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801FCA90: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    // 0x801FCA94: div.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x801FCA98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801FCA9C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801FCAA0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801FCAA4: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x801FCAA8: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801FCAAC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x801FCAB0: nop

    // 0x801FCAB4: slti        $at, $v1, -0xFF
    ctx->r1 = SIGNED(ctx->r3) < -0XFF ? 1 : 0;
    // 0x801FCAB8: beql        $at, $zero, L_801FCAC8
    if (ctx->r1 == 0) {
        // 0x801FCABC: sll         $a2, $v1, 16
        ctx->r6 = S32(ctx->r3 << 16);
            goto L_801FCAC8;
    }
    goto skip_0;
    // 0x801FCABC: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
    skip_0:
    // 0x801FCAC0: addiu       $v1, $zero, -0xFF
    ctx->r3 = ADD32(0, -0XFF);
    // 0x801FCAC4: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
L_801FCAC8:
    // 0x801FCAC8: jal         0x8002096C
    // 0x801FCACC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8002096C)(rdram, ctx);
        goto after_1;
    // 0x801FCACC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_1:
    // 0x801FCAD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FCAD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FCAD8: jr          $ra
    // 0x801FCADC: nop

    return;
    // 0x801FCADC: nop

;}
RECOMP_FUNC void M9_FUN_801fcae0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCAE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FCAE4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801FCAE8: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801FCAEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FCAF0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801FCAF4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801FCAF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801FCAFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801FCB00: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801FCB04: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801FCB08: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FCB0C: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801FCB10: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FCB14: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801FCB18: jal         0x8001EF38
    // 0x801FCB1C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801FCB1C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x801FCB20: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801FCB24: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801FCB28: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x801FCB2C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801FCB30: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801FCB34: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801FCB38: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801FCB3C: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801FCB40: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801FCB44: jal         0x8001EF38
    // 0x801FCB48: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801FCB48: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x801FCB4C: lh          $t8, 0x18($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X18);
    // 0x801FCB50: subu        $a0, $t8, $v0
    ctx->r4 = SUB32(ctx->r24, ctx->r2);
    // 0x801FCB54: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FCB58: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FCB5C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801FCB60: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FCB64: jal         0x8001EAD0
    // 0x801FCB68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801FCB68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x801FCB6C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x801FCB70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FCB74: lhu         $a0, 0x2E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2E);
    // 0x801FCB78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801FCB7C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801FCB80: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801FCB84: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801FCB88: nop

    // 0x801FCB8C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FCB90: jal         0x8002096C
    // 0x801FCB94: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8002096C)(rdram, ctx);
        goto after_3;
    // 0x801FCB94: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_3:
    // 0x801FCB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FCB9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FCBA0: jr          $ra
    // 0x801FCBA4: nop

    return;
    // 0x801FCBA4: nop

;}
RECOMP_FUNC void M9_FUN_801fcba8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCBA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FCBAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FCBB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FCBB4: jal         0x80020DAC
    // 0x801FCBB8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_0;
    // 0x801FCBB8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x801FCBBC: bnel        $v0, $zero, L_801FCBD0
    if (ctx->r2 != 0) {
        // 0x801FCBC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FCBD0;
    }
    goto skip_0;
    // 0x801FCBC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FCBC4: jal         0x800208C4
    // 0x801FCBC8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801FCBC8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x801FCBCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FCBD0:
    // 0x801FCBD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FCBD4: jr          $ra
    // 0x801FCBD8: nop

    return;
    // 0x801FCBD8: nop

;}
RECOMP_FUNC void M9_FUN_801fcbdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCBDC: nop

;}
RECOMP_FUNC void M9_FUN_801fcbe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FCBE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FCBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FCBEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FCBF0: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x801FCBF4: jal         0x80126CC0
    // 0x801FCBF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x801FCBF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801FCBFC: beq         $v0, $zero, L_801FCD3C
    if (ctx->r2 == 0) {
        // 0x801FCC00: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_801FCD3C;
    }
    // 0x801FCC00: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801FCC04: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
    // 0x801FCC08: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x801FCC0C: srl         $a1, $a1, 16
    ctx->r5 = S32(U32(ctx->r5) >> 16);
    // 0x801FCC10: bne         $a1, $zero, L_801FCC2C
    if (ctx->r5 != 0) {
        // 0x801FCC14: andi        $v1, $a1, 0xFFFF
        ctx->r3 = ctx->r5 & 0XFFFF;
            goto L_801FCC2C;
    }
    // 0x801FCC14: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x801FCC18: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x801FCC1C: srl         $v1, $a0, 8
    ctx->r3 = S32(U32(ctx->r4) >> 8);
    // 0x801FCC20: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801FCC24: b           L_801FCC30
    // 0x801FCC28: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_801FCC30;
    // 0x801FCC28: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_801FCC2C:
    // 0x801FCC2C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
L_801FCC30:
    // 0x801FCC30: srl         $t7, $a0, 16
    ctx->r15 = S32(U32(ctx->r4) >> 16);
    // 0x801FCC34: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x801FCC38: beql        $t8, $zero, L_801FCC74
    if (ctx->r24 == 0) {
        // 0x801FCC3C: lw          $v0, 0x38($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X38);
            goto L_801FCC74;
    }
    goto skip_0;
    // 0x801FCC3C: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
    skip_0:
    // 0x801FCC40: beq         $v1, $zero, L_801FCC70
    if (ctx->r3 == 0) {
        // 0x801FCC44: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_801FCC70;
    }
    // 0x801FCC44: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801FCC48: jal         0x80133A24
    // 0x801FCC4C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_1;
    // 0x801FCC4C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x801FCC50: beq         $v0, $zero, L_801FCC70
    if (ctx->r2 == 0) {
        // 0x801FCC54: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_801FCC70;
    }
    // 0x801FCC54: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801FCC58: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FCC5C: addiu       $a1, $a1, -0x30EC
    ctx->r5 = ADD32(ctx->r5, -0X30EC);
    // 0x801FCC60: jal         0x800058DC
    // 0x801FCC64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FCC64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x801FCC68: b           L_801FCD40
    // 0x801FCC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FCD40;
    // 0x801FCC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FCC70:
    // 0x801FCC70: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
L_801FCC74:
    // 0x801FCC74: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801FCC78: sb          $t9, 0x90($a2)
    MEM_B(0X90, ctx->r6) = ctx->r25;
    // 0x801FCC7C: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x801FCC80: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801FCC84: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801FCC88: srl         $t1, $t0, 24
    ctx->r9 = S32(U32(ctx->r8) >> 24);
    // 0x801FCC8C: sb          $t1, 0x91($a2)
    MEM_B(0X91, ctx->r6) = ctx->r9;
    // 0x801FCC90: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x801FCC94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801FCC98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801FCC9C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801FCCA0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FCCA4: addiu       $a1, $a1, -0x32B4
    ctx->r5 = ADD32(ctx->r5, -0X32B4);
    // 0x801FCCA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801FCCAC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801FCCB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801FCCB4: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801FCCB8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801FCCBC: swc1        $f16, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f16.u32l;
    // 0x801FCCC0: lh          $t3, 0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X8);
    // 0x801FCCC4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x801FCCC8: nop

    // 0x801FCCCC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801FCCD0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801FCCD4: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801FCCD8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801FCCDC: swc1        $f10, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->f10.u32l;
    // 0x801FCCE0: lh          $t4, 0xA($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XA);
    // 0x801FCCE4: sh          $zero, 0xA0($a2)
    MEM_H(0XA0, ctx->r6) = 0;
    // 0x801FCCE8: swc1        $f2, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f2.u32l;
    // 0x801FCCEC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x801FCCF0: swc1        $f2, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f2.u32l;
    // 0x801FCCF4: swc1        $f2, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f2.u32l;
    // 0x801FCCF8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801FCCFC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801FCD00: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801FCD04: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801FCD08: swc1        $f8, 0x9C($a2)
    MEM_W(0X9C, ctx->r6) = ctx->f8.u32l;
    // 0x801FCD0C: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x801FCD10: sh          $zero, 0xA4($a2)
    MEM_H(0XA4, ctx->r6) = 0;
    // 0x801FCD14: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x801FCD18: sh          $zero, 0x92($a2)
    MEM_H(0X92, ctx->r6) = 0;
    // 0x801FCD1C: sh          $zero, 0xA6($a2)
    MEM_H(0XA6, ctx->r6) = 0;
    // 0x801FCD20: sh          $t5, 0xA2($a2)
    MEM_H(0XA2, ctx->r6) = ctx->r13;
    // 0x801FCD24: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x801FCD28: srl         $t8, $t6, 16
    ctx->r24 = S32(U32(ctx->r14) >> 16);
    // 0x801FCD2C: sb          $t8, 0xAC($a2)
    MEM_B(0XAC, ctx->r6) = ctx->r24;
    // 0x801FCD30: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x801FCD34: jal         0x800058DC
    // 0x801FCD38: sw          $t9, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801FCD38: sw          $t9, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = ctx->r25;
    after_3:
L_801FCD3C:
    // 0x801FCD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FCD40:
    // 0x801FCD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FCD44: jr          $ra
    // 0x801FCD48: nop

    return;
    // 0x801FCD48: nop

;}
RECOMP_FUNC void M9_FUN_801fcd4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCD4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FCD50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FCD54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FCD58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FCD5C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801FCD60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FCD64: bne         $t6, $zero, L_801FCD90
    if (ctx->r14 != 0) {
        // 0x801FCD68: nop
    
            goto L_801FCD90;
    }
    // 0x801FCD68: nop

    // 0x801FCD6C: jal         0x80005C70
    // 0x801FCD70: nop

    LOOKUP_FUNC(0x80005C70)(rdram, ctx);
        goto after_0;
    // 0x801FCD70: nop

    after_0:
    // 0x801FCD74: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // 0x801FCD78: beq         $at, $zero, L_801FCD90
    if (ctx->r1 == 0) {
        // 0x801FCD7C: nop
    
            goto L_801FCD90;
    }
    // 0x801FCD7C: nop

    // 0x801FCD80: jal         0x80005700
    // 0x801FCD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FCD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FCD88: b           L_801FCDFC
    // 0x801FCD8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801FCDFC;
    // 0x801FCD8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FCD90:
    // 0x801FCD90: jal         0x8001F74C
    // 0x801FCD94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_2;
    // 0x801FCD94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801FCD98: lbu         $v0, 0x91($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X91);
    // 0x801FCD9C: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FCDA0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801FCDA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801FCDA8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801FCDAC: lw          $v1, 0x7434($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7434);
    // 0x801FCDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FCDB4: beq         $v1, $zero, L_801FCDCC
    if (ctx->r3 == 0) {
        // 0x801FCDB8: nop
    
            goto L_801FCDCC;
    }
    // 0x801FCDB8: nop

    // 0x801FCDBC: lbu         $t7, -0x43F3($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X43F3);
    // 0x801FCDC0: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x801FCDC4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x801FCDC8: sb          $t9, 0xB0($s0)
    MEM_B(0XB0, ctx->r16) = ctx->r25;
L_801FCDCC:
    // 0x801FCDCC: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FCDD0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801FCDD4: lw          $v1, 0x7150($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7150);
    // 0x801FCDD8: beq         $v1, $zero, L_801FCDE8
    if (ctx->r3 == 0) {
        // 0x801FCDDC: nop
    
            goto L_801FCDE8;
    }
    // 0x801FCDDC: nop

    // 0x801FCDE0: jalr        $v1
    // 0x801FCDE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x801FCDE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
L_801FCDE8:
    // 0x801FCDE8: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FCDEC: addiu       $a1, $a1, -0x31F4
    ctx->r5 = ADD32(ctx->r5, -0X31F4);
    // 0x801FCDF0: jal         0x800058DC
    // 0x801FCDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801FCDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801FCDF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FCDFC:
    // 0x801FCDFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FCE00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FCE04: jr          $ra
    // 0x801FCE08: nop

    return;
    // 0x801FCE08: nop

;}
RECOMP_FUNC void M9_FUN_801fce0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCE0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FCE10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FCE14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FCE18: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x801FCE1C: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FCE20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FCE24: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FCE28: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801FCE2C: lw          $v0, 0x71F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71F0);
    // 0x801FCE30: beql        $v0, $zero, L_801FCF04
    if (ctx->r2 == 0) {
        // 0x801FCE34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FCF04;
    }
    goto skip_0;
    // 0x801FCE34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801FCE38: jalr        $v0
    // 0x801FCE3C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801FCE3C: nop

    after_0:
    // 0x801FCE40: bnel        $v0, $zero, L_801FCE80
    if (ctx->r2 != 0) {
        // 0x801FCE44: lwc1        $f12, 0x94($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
            goto L_801FCE80;
    }
    goto skip_1;
    // 0x801FCE44: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    skip_1:
    // 0x801FCE48: lhu         $t8, 0x36($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X36);
    // 0x801FCE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FCE50: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FCE54: bne         $t8, $zero, L_801FCE6C
    if (ctx->r24 != 0) {
        // 0x801FCE58: nop
    
            goto L_801FCE6C;
    }
    // 0x801FCE58: nop

    // 0x801FCE5C: jal         0x80005700
    // 0x801FCE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FCE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FCE64: b           L_801FCF04
    // 0x801FCE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801FCF04;
    // 0x801FCE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FCE6C:
    // 0x801FCE6C: jal         0x800058DC
    // 0x801FCE70: addiu       $a1, $a1, -0x30EC
    ctx->r5 = ADD32(ctx->r5, -0X30EC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FCE70: addiu       $a1, $a1, -0x30EC
    ctx->r5 = ADD32(ctx->r5, -0X30EC);
    after_2:
    // 0x801FCE74: b           L_801FCF04
    // 0x801FCE78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801FCF04;
    // 0x801FCE78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FCE7C: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
L_801FCE80:
    // 0x801FCE80: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FCE84: jal         0x801FD5BC
    // 0x801FCE88: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    LOOKUP_FUNC(0x801FD5BC)(rdram, ctx);
        goto after_3;
    // 0x801FCE88: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    after_3:
    // 0x801FCE8C: beq         $v0, $zero, L_801FCEC0
    if (ctx->r2 == 0) {
        // 0x801FCE90: nop
    
            goto L_801FCEC0;
    }
    // 0x801FCE90: nop

    // 0x801FCE94: lhu         $t9, 0x36($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X36);
    // 0x801FCE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FCE9C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FCEA0: bne         $t9, $zero, L_801FCEB8
    if (ctx->r25 != 0) {
        // 0x801FCEA4: nop
    
            goto L_801FCEB8;
    }
    // 0x801FCEA4: nop

    // 0x801FCEA8: jal         0x80005700
    // 0x801FCEAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801FCEAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801FCEB0: b           L_801FCEC0
    // 0x801FCEB4: nop

        goto L_801FCEC0;
    // 0x801FCEB4: nop

L_801FCEB8:
    // 0x801FCEB8: jal         0x800058DC
    // 0x801FCEBC: addiu       $a1, $a1, -0x30EC
    ctx->r5 = ADD32(ctx->r5, -0X30EC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801FCEBC: addiu       $a1, $a1, -0x30EC
    ctx->r5 = ADD32(ctx->r5, -0X30EC);
    after_5:
L_801FCEC0:
    // 0x801FCEC0: jal         0x80150584
    // 0x801FCEC4: nop

    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_6;
    // 0x801FCEC4: nop

    after_6:
    // 0x801FCEC8: bnel        $v0, $zero, L_801FCF04
    if (ctx->r2 != 0) {
        // 0x801FCECC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FCF04;
    }
    goto skip_2;
    // 0x801FCECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801FCED0: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FCED4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801FCED8: lwc1        $f10, 0x98($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FCEDC: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801FCEE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801FCEE4: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801FCEE8: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x801FCEEC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801FCEF0: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x801FCEF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801FCEF8: swc1        $f18, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f18.u32l;
    // 0x801FCEFC: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x801FCF00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FCF04:
    // 0x801FCF04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FCF08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FCF0C: jr          $ra
    // 0x801FCF10: nop

    return;
    // 0x801FCF10: nop

;}
RECOMP_FUNC void M9_FUN_801fcf14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCF14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FCF18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FCF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FCF20: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FCF24: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x801FCF28: jal         0x800058DC
    // 0x801FCF2C: addiu       $a1, $a1, -0x30C0
    ctx->r5 = ADD32(ctx->r5, -0X30C0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FCF2C: addiu       $a1, $a1, -0x30C0
    ctx->r5 = ADD32(ctx->r5, -0X30C0);
    after_0:
    // 0x801FCF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FCF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FCF38: jr          $ra
    // 0x801FCF3C: nop

    return;
    // 0x801FCF3C: nop

;}
RECOMP_FUNC void M9_FUN_801fcf40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FCF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FCF48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FCF4C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801FCF50: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801FCF54: slti        $v1, $v0, 0x1E
    ctx->r3 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x801FCF58: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801FCF5C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FCF60: beq         $v1, $zero, L_801FCF88
    if (ctx->r3 == 0) {
        // 0x801FCF64: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_801FCF88;
    }
    // 0x801FCF64: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801FCF68: lbu         $t7, -0x428F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X428F);
    // 0x801FCF6C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FCF70: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x801FCF74: bnel        $t7, $zero, L_801FCF8C
    if (ctx->r15 != 0) {
        // 0x801FCF78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FCF8C;
    }
    goto skip_0;
    // 0x801FCF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801FCF7C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x801FCF80: jal         0x800058DC
    // 0x801FCF84: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FCF84: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    after_0:
L_801FCF88:
    // 0x801FCF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FCF8C:
    // 0x801FCF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FCF90: jr          $ra
    // 0x801FCF94: nop

    return;
    // 0x801FCF94: nop

;}
RECOMP_FUNC void M9_FUN_801fcf98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FCF98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801FCF9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FCFA0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801FCFA4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801FCFA8: beql        $v0, $zero, L_801FD0E4
    if (ctx->r2 == 0) {
        // 0x801FCFAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801FD0E4;
    }
    goto skip_0;
    // 0x801FCFAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801FCFB0: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x801FCFB4: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    // 0x801FCFB8: bnel        $a0, $zero, L_801FCFDC
    if (ctx->r4 != 0) {
        // 0x801FCFBC: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_801FCFDC;
    }
    goto skip_1;
    // 0x801FCFBC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x801FCFC0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x801FCFC4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801FCFC8: srl         $t0, $v1, 8
    ctx->r8 = S32(U32(ctx->r3) >> 8);
    // 0x801FCFCC: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x801FCFD0: b           L_801FCFF8
    // 0x801FCFD4: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
        goto L_801FCFF8;
    // 0x801FCFD4: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // 0x801FCFD8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_801FCFDC:
    // 0x801FCFDC: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x801FCFE0: srl         $a2, $v1, 8
    ctx->r6 = S32(U32(ctx->r3) >> 8);
    // 0x801FCFE4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801FCFE8: bne         $a2, $zero, L_801FCFF8
    if (ctx->r6 != 0) {
        // 0x801FCFEC: andi        $a3, $a2, 0xFF
        ctx->r7 = ctx->r6 & 0XFF;
            goto L_801FCFF8;
    }
    // 0x801FCFEC: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
    // 0x801FCFF0: b           L_801FCFF8
    // 0x801FCFF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_801FCFF8;
    // 0x801FCFF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_801FCFF8:
    // 0x801FCFF8: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x801FCFFC: beq         $t6, $zero, L_801FD0D0
    if (ctx->r14 == 0) {
        // 0x801FD000: nop
    
            goto L_801FD0D0;
    }
    // 0x801FD000: nop

    // 0x801FD004: beq         $t0, $zero, L_801FD040
    if (ctx->r8 == 0) {
        // 0x801FD008: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_801FD040;
    }
    // 0x801FD008: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x801FD00C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x801FD010: sb          $a3, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r7;
    // 0x801FD014: jal         0x80133A24
    // 0x801FD018: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801FD018: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801FD01C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801FD020: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
    // 0x801FD024: beq         $v0, $zero, L_801FD040
    if (ctx->r2 == 0) {
        // 0x801FD028: lhu         $t0, 0x2C($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X2C);
            goto L_801FD040;
    }
    // 0x801FD028: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x801FD02C: lw          $t7, 0x38($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X38);
    // 0x801FD030: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801FD034: srl         $t1, $t8, 16
    ctx->r9 = S32(U32(ctx->r24) >> 16);
    // 0x801FD038: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x801FD03C: bne         $t2, $zero, L_801FD0D0
    if (ctx->r10 != 0) {
        // 0x801FD040: lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
            goto L_801FD0D0;
    }
L_801FD040:
    // 0x801FD040: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801FD044: lbu         $t3, -0x43F3($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X43F3);
    // 0x801FD048: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801FD04C: slt         $at, $a3, $t4
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x801FD050: bne         $at, $zero, L_801FD0D0
    if (ctx->r1 != 0) {
        // 0x801FD054: nop
    
            goto L_801FD0D0;
    }
    // 0x801FD054: nop

    // 0x801FD058: lw          $v0, 0x38($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X38);
    // 0x801FD05C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801FD060: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x801FD064: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x801FD068: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801FD06C: bne         $a0, $zero, L_801FD0A8
    if (ctx->r4 != 0) {
        // 0x801FD070: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_801FD0A8;
    }
    // 0x801FD070: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801FD074: lwc1        $f12, 0x94($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X94);
    // 0x801FD078: lwc1        $f14, 0x98($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X98);
    // 0x801FD07C: lw          $a2, 0x9C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X9C);
    // 0x801FD080: lh          $a3, 0xA2($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XA2);
    // 0x801FD084: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x801FD088: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801FD08C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801FD090: jal         0x8014ADB4
    // 0x801FD094: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8014ADB4)(rdram, ctx);
        goto after_1;
    // 0x801FD094: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801FD098: jal         0x8014B36C
    // 0x801FD09C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8014B36C)(rdram, ctx);
        goto after_2;
    // 0x801FD09C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x801FD0A0: b           L_801FD0D0
    // 0x801FD0A4: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
        goto L_801FD0D0;
    // 0x801FD0A4: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
L_801FD0A8:
    // 0x801FD0A8: lwc1        $f12, 0x94($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X94);
    // 0x801FD0AC: lwc1        $f14, 0x98($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X98);
    // 0x801FD0B0: lw          $a2, 0x9C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X9C);
    // 0x801FD0B4: lh          $a3, 0xA2($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XA2);
    // 0x801FD0B8: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x801FD0BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801FD0C0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801FD0C4: jal         0x8014ADB4
    // 0x801FD0C8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8014ADB4)(rdram, ctx);
        goto after_3;
    // 0x801FD0C8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    after_3:
    // 0x801FD0CC: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
L_801FD0D0:
    // 0x801FD0D0: beql        $t0, $zero, L_801FD0E4
    if (ctx->r8 == 0) {
        // 0x801FD0D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801FD0E4;
    }
    goto skip_2;
    // 0x801FD0D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801FD0D8: jal         0x80133980
    // 0x801FD0DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_4;
    // 0x801FD0DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x801FD0E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801FD0E4:
    // 0x801FD0E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801FD0E8: jr          $ra
    // 0x801FD0EC: nop

    return;
    // 0x801FD0EC: nop

;}
RECOMP_FUNC void M9_FUN_801fd0f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FD0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FD0F8: jal         0x80005700
    // 0x801FD0FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801FD0FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801FD100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FD104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FD108: jr          $ra
    // 0x801FD10C: nop

    return;
    // 0x801FD10C: nop

;}
RECOMP_FUNC void M9_FUN_801fd110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FD114: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801FD118: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801FD11C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FD120: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FD124: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801FD128: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x801FD12C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FD130: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801FD134: addiu       $t9, $v0, 0xC
    ctx->r25 = ADD32(ctx->r2, 0XC);
    // 0x801FD138: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801FD13C: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x801FD140: jal         0x8013E5C4
    // 0x801FD144: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    LOOKUP_FUNC(0x8013E5C4)(rdram, ctx);
        goto after_0;
    // 0x801FD144: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    after_0:
    // 0x801FD148: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FD14C: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    // 0x801FD150: jal         0x800058DC
    // 0x801FD154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FD154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801FD158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FD15C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FD160: jr          $ra
    // 0x801FD164: nop

    return;
    // 0x801FD164: nop

;}
RECOMP_FUNC void M9_FUN_801fd168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD168: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FD16C: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801FD170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FD174: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801FD178: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801FD17C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801FD180: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801FD184: addiu       $t6, $t6, 0x72A4
    ctx->r14 = ADD32(ctx->r14, 0X72A4);
    // 0x801FD188: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801FD18C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801FD190: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801FD194: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801FD198: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801FD19C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FD1A0: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801FD1A4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801FD1A8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801FD1AC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FD1B0: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801FD1B4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801FD1B8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FD1BC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FD1C0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801FD1C4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FD1C8: jal         0x8012C4D0
    // 0x801FD1CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FD1CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FD1D0: beq         $v0, $zero, L_801FD24C
    if (ctx->r2 == 0) {
        // 0x801FD1D4: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_801FD24C;
    }
    // 0x801FD1D4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801FD1D8: sb          $t0, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r8;
    // 0x801FD1DC: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x801FD1E0: sb          $t1, 0x91($v0)
    MEM_B(0X91, ctx->r2) = ctx->r9;
    // 0x801FD1E4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801FD1E8: swc1        $f4, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f4.u32l;
    // 0x801FD1EC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801FD1F0: swc1        $f6, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f6.u32l;
    // 0x801FD1F4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801FD1F8: swc1        $f8, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f8.u32l;
    // 0x801FD1FC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801FD200: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
    // 0x801FD204: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801FD208: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x801FD20C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801FD210: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x801FD214: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x801FD218: sh          $t2, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = ctx->r10;
    // 0x801FD21C: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x801FD220: sh          $t3, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r11;
    // 0x801FD224: lh          $t4, 0x4A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X4A);
    // 0x801FD228: sh          $zero, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = 0;
    // 0x801FD22C: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x801FD230: sh          $zero, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = 0;
    // 0x801FD234: sh          $t4, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r12;
    // 0x801FD238: lbu         $t5, 0x53($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X53);
    // 0x801FD23C: sb          $t5, 0xAC($v0)
    MEM_B(0XAC, ctx->r2) = ctx->r13;
    // 0x801FD240: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x801FD244: b           L_801FD250
    // 0x801FD248: sw          $t6, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r14;
        goto L_801FD250;
    // 0x801FD248: sw          $t6, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r14;
L_801FD24C:
    // 0x801FD24C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FD250:
    // 0x801FD250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FD254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801FD258: jr          $ra
    // 0x801FD25C: nop

    return;
    // 0x801FD25C: nop

;}
RECOMP_FUNC void M9_FUN_801fd260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD260: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801FD264: lui         $t9, 0x8020
    ctx->r25 = S32(0X8020 << 16);
    // 0x801FD268: addiu       $t9, $t9, -0x2F10
    ctx->r25 = ADD32(ctx->r25, -0X2F10);
    // 0x801FD26C: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x801FD270: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801FD274: lhu         $t8, 0x72($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X72);
    // 0x801FD278: sw          $t9, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r25;
    // 0x801FD27C: jr          $ra
    // 0x801FD280: sh          $t8, 0x72($a0)
    MEM_H(0X72, ctx->r4) = ctx->r24;
    return;
    // 0x801FD280: sh          $t8, 0x72($a0)
    MEM_H(0X72, ctx->r4) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd284(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD284: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FD288: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FD28C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801FD290: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FD294: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD298: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FD29C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801FD2A0: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x801FD2A4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FD2A8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801FD2AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD2B0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FD2B4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801FD2B8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801FD2BC: beq         $at, $zero, L_801FD358
    if (ctx->r1 == 0) {
            // 0x801FD2C0: subu        $v1, $a0, $a1
    ctx->r3 = SUB32(ctx->r4, ctx->r5);
    LOOKUP_FUNC(0x801FD358)(rdram, ctx);
    return;
    }
    // 0x801FD2C0: subu        $v1, $a0, $a1
    ctx->r3 = SUB32(ctx->r4, ctx->r5);
    // 0x801FD2C4: subu        $v1, $a1, $a0
    ctx->r3 = SUB32(ctx->r5, ctx->r4);
    // 0x801FD2C8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD2CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FD2D0: slti        $at, $v1, 0x1000
    ctx->r1 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // 0x801FD2D4: beq         $at, $zero, L_801FD318
    if (ctx->r1 == 0) {
            // 0x801FD2D8: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x801FD318)(rdram, ctx);
    return;
    }
    // 0x801FD2D8: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x801FD2DC: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x801FD2E0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801FD2E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FD2E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801FD2EC: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801FD2F0: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801FD2F4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801FD2F8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801FD2FC: nop

    // 0x801FD300: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD304: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD308: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x801FD30C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD310: jr          $ra
    // 0x801FD314: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x801FD314: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd318(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD318: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x801FD31C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801FD320: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x801FD324: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801FD328: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FD32C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801FD330: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801FD334: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801FD338: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x801FD33C: nop

    // 0x801FD340: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD344: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD348: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x801FD34C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD350: jr          $ra
    // 0x801FD354: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x801FD354: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd358(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD358: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD35C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FD360: slti        $at, $v1, 0x1000
    ctx->r1 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // 0x801FD364: beq         $at, $zero, L_801FD3A8
    if (ctx->r1 == 0) {
            // 0x801FD368: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x801FD3A8)(rdram, ctx);
    return;
    }
    // 0x801FD368: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x801FD36C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x801FD370: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x801FD374: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801FD378: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801FD37C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801FD380: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801FD384: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801FD388: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x801FD38C: nop

    // 0x801FD390: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD394: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD398: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x801FD39C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD3A0: jr          $ra
    // 0x801FD3A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x801FD3A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd3a8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd3a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD3A8: subu        $t2, $t1, $v1
    ctx->r10 = SUB32(ctx->r9, ctx->r3);
    // 0x801FD3AC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x801FD3B0: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x801FD3B4: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801FD3B8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801FD3BC: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801FD3C0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801FD3C4: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801FD3C8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x801FD3CC: nop

    // 0x801FD3D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD3D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD3D8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x801FD3DC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD3E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD3E4: jr          $ra
    // 0x801FD3E8: nop

    return;
    // 0x801FD3E8: nop

;}
RECOMP_FUNC void M9_FUN_801fd3ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD3EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FD3F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FD3F4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801FD3F8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FD3FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD400: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FD404: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801FD408: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x801FD40C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FD410: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801FD414: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801FD418: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD41C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FD420: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FD424: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801FD428: beq         $at, $zero, L_801FD490
    if (ctx->r1 == 0) {
            // 0x801FD42C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x801FD490)(rdram, ctx);
    return;
    }
    // 0x801FD42C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801FD430: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x801FD434: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD438: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD43C: slti        $at, $v0, 0x1000
    ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x801FD440: beq         $at, $zero, L_801FD464
    if (ctx->r1 == 0) {
        // 0x801FD444: subu        $v1, $a0, $a2
        ctx->r3 = SUB32(ctx->r4, ctx->r6);
            goto L_801FD464;
    }
    // 0x801FD444: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
    // 0x801FD448: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
    // 0x801FD44C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD450: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FD454: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x801FD458: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD45C: b           L_801FD478
    // 0x801FD460: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801FD478;
    // 0x801FD460: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_801FD464:
    // 0x801FD464: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD468: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FD46C: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x801FD470: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD474: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_801FD478:
    // 0x801FD478: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801FD47C: beq         $at, $zero, L_801FD4EC
    if (ctx->r1 == 0) {
        // 0x801FD480: nop
    
        LOOKUP_FUNC(0x801FD4EC)(rdram, ctx);
        return;
    }
    // 0x801FD480: nop

    // 0x801FD484: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x801FD488: jr          $ra
    // 0x801FD48C: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    return;
    // 0x801FD48C: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd490(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD490: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x801FD494: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FD498: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FD49C: slti        $at, $v0, 0x1000
    ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x801FD4A0: beq         $at, $zero, L_801FD4C4
    if (ctx->r1 == 0) {
        // 0x801FD4A4: addu        $v1, $a0, $a2
        ctx->r3 = ADD32(ctx->r4, ctx->r6);
            goto L_801FD4C4;
    }
    // 0x801FD4A4: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
    // 0x801FD4A8: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
    // 0x801FD4AC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD4B0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FD4B4: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x801FD4B8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD4BC: b           L_801FD4D8
    // 0x801FD4C0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801FD4D8;
    // 0x801FD4C0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_801FD4C4:
    // 0x801FD4C4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD4C8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801FD4CC: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x801FD4D0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801FD4D4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_801FD4D8:
    // 0x801FD4D8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801FD4DC: beq         $at, $zero, L_801FD4EC
    if (ctx->r1 == 0) {
        // 0x801FD4E0: nop
    
            goto L_801FD4EC;
    }
    // 0x801FD4E0: nop

    // 0x801FD4E4: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x801FD4E8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_801FD4EC:
    // 0x801FD4EC: jr          $ra
    // 0x801FD4F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801FD4F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd4f4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd4f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD4F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FD4F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FD4FC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801FD500: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FD504: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD508: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FD50C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801FD510: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x801FD514: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FD518: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801FD51C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801FD520: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD524: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FD528: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FD52C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801FD530: beq         $at, $zero, L_801FD574
    if (ctx->r1 == 0) {
        // 0x801FD534: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_801FD574;
    }
    // 0x801FD534: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801FD538: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x801FD53C: slti        $at, $v0, 0x1000
    ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x801FD540: beq         $at, $zero, L_801FD55C
    if (ctx->r1 == 0) {
        // 0x801FD544: addiu       $t6, $zero, 0x2000
        ctx->r14 = ADD32(0, 0X2000);
            goto L_801FD55C;
    }
    // 0x801FD544: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x801FD548: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801FD54C: bnel        $at, $zero, L_801FD5B4
    if (ctx->r1 != 0) {
        // 0x801FD550: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FD5B4;
    }
    goto skip_0;
    // 0x801FD550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801FD554: jr          $ra
    // 0x801FD558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FD55C:
    // 0x801FD55C: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x801FD560: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801FD564: bnel        $at, $zero, L_801FD5B4
    if (ctx->r1 != 0) {
        // 0x801FD568: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FD5B4;
    }
    goto skip_1;
    // 0x801FD568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801FD56C: jr          $ra
    // 0x801FD570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FD574:
    // 0x801FD574: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x801FD578: slti        $at, $v0, 0x1000
    ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x801FD57C: beq         $at, $zero, L_801FD598
    if (ctx->r1 == 0) {
        // 0x801FD580: addiu       $t8, $zero, 0x2000
        ctx->r24 = ADD32(0, 0X2000);
            goto L_801FD598;
    }
    // 0x801FD580: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x801FD584: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801FD588: bnel        $at, $zero, L_801FD5B4
    if (ctx->r1 != 0) {
        // 0x801FD58C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FD5B4;
    }
    goto skip_2;
    // 0x801FD58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801FD590: jr          $ra
    // 0x801FD594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FD598:
    // 0x801FD598: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x801FD59C: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801FD5A0: bnel        $at, $zero, L_801FD5B4
    if (ctx->r1 != 0) {
        // 0x801FD5A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FD5B4;
    }
    goto skip_3;
    // 0x801FD5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x801FD5A8: jr          $ra
    // 0x801FD5AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD5AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801FD5B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FD5B4:
    // 0x801FD5B4: jr          $ra
    // 0x801FD5B8: nop

    return;
    // 0x801FD5B8: nop

;}
RECOMP_FUNC void M9_FUN_801fd55c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD55C: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x801FD560: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801FD564: bnel        $at, $zero, L_801FD5B4
    if (ctx->r1 != 0) {
        // 0x801FD568: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
        LOOKUP_FUNC(0x801FD5B4)(rdram, ctx);
        return;
    }
    goto skip_0;
    // 0x801FD568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801FD56C: jr          $ra
    // 0x801FD570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd574(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD574: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x801FD578: slti        $at, $v0, 0x1000
    ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x801FD57C: beq         $at, $zero, L_801FD598
    if (ctx->r1 == 0) {
        // 0x801FD580: addiu       $t8, $zero, 0x2000
        ctx->r24 = ADD32(0, 0X2000);
        LOOKUP_FUNC(0x801FD598)(rdram, ctx);
        return;
    }
    // 0x801FD580: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x801FD584: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801FD588: bnel        $at, $zero, L_801FD5B4
    if (ctx->r1 != 0) {
        // 0x801FD58C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
        LOOKUP_FUNC(0x801FD5B4)(rdram, ctx);
        return;
    }
    goto skip_0;
    // 0x801FD58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801FD590: jr          $ra
    // 0x801FD594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void M9_FUN_801fd5bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD5BC: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x801FD5C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801FD5C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801FD5C8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801FD5CC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801FD5D0: nop

    // 0x801FD5D4: bc1t        L_801FD634
    if (c1cs) {
        // 0x801FD5D8: nop
    
            goto L_801FD634;
    }
    // 0x801FD5D8: nop

    // 0x801FD5DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801FD5E0: nop

    // 0x801FD5E4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801FD5E8: nop

    // 0x801FD5EC: bc1t        L_801FD634
    if (c1cs) {
        // 0x801FD5F0: nop
    
            goto L_801FD634;
    }
    // 0x801FD5F0: nop

    // 0x801FD5F4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x801FD5F8: nop

    // 0x801FD5FC: bc1t        L_801FD634
    if (c1cs) {
        // 0x801FD600: nop
    
            goto L_801FD634;
    }
    // 0x801FD600: nop

    // 0x801FD604: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x801FD608: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x801FD60C: bc1t        L_801FD634
    if (c1cs) {
        // 0x801FD610: nop
    
            goto L_801FD634;
    }
    // 0x801FD610: nop

    // 0x801FD614: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801FD618: nop

    // 0x801FD61C: bc1t        L_801FD634
    if (c1cs) {
        // 0x801FD620: nop
    
            goto L_801FD634;
    }
    // 0x801FD620: nop

    // 0x801FD624: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x801FD628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FD62C: bc1f        L_801FD63C
    if (!c1cs) {
            // 0x801FD630: nop

    LOOKUP_FUNC(0x801FD63C)(rdram, ctx);
    return;
    }
    // 0x801FD630: nop

L_801FD634:
    // 0x801FD634: jr          $ra
    // 0x801FD638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801FD638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd63c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd63c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD63C: jr          $ra
    // 0x801FD640: nop

    return;
    // 0x801FD640: nop

;}
RECOMP_FUNC void M9_FUN_801fd644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FD648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FD64C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801FD650: jal         0x801C80CC
    // 0x801FD654: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801C80CC)(rdram, ctx);
        goto after_0;
    // 0x801FD654: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x801FD658: beq         $v0, $zero, L_801FD678
    if (ctx->r2 == 0) {
        // 0x801FD65C: lh          $a0, 0x2A($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X2A);
            goto L_801FD678;
    }
    // 0x801FD65C: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x801FD660: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801FD664: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801FD668: jal         0x8037BB4C
    // 0x801FD66C: lh          $a3, 0x36($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X36);
    LOOKUP_FUNC(0x8037BB4C)(rdram, ctx);
        goto after_1;
    // 0x801FD66C: lh          $a3, 0x36($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X36);
    after_1:
    // 0x801FD670: b           L_801FD67C
    // 0x801FD674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FD67C;
    // 0x801FD674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FD678:
    // 0x801FD678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FD67C:
    // 0x801FD67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FD680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FD684: jr          $ra
    // 0x801FD688: nop

    return;
    // 0x801FD688: nop

;}
RECOMP_FUNC void M9_FUN_801fd68c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD68C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801FD690: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FD694: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801FD698: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801FD69C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FD6A0: lhu         $v0, 0xA2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA2);
    // 0x801FD6A4: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x801FD6A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FD6AC: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x801FD6B0: lui         $s1, 0x8021
    ctx->r17 = S32(0X8021 << 16);
    // 0x801FD6B4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801FD6B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FD6BC: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x801FD6C0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801FD6C4: lw          $s1, 0x7434($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X7434);
    // 0x801FD6C8: jal         0x8001EAD0
    // 0x801FD6CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801FD6CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801FD6D0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801FD6D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD6D8: jal         0x8001EB64
    // 0x801FD6DC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801FD6DC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801FD6E0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801FD6E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD6E8: jal         0x8001EB64
    // 0x801FD6EC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801FD6EC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x801FD6F0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801FD6F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FD6F8: jal         0x8001EAD0
    // 0x801FD6FC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801FD6FC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x801FD700: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801FD704: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801FD708: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801FD70C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801FD710: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801FD714: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FD718: lw          $a3, 0x10($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X10);
    // 0x801FD71C: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801FD720: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FD724: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801FD728: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801FD72C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801FD730: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801FD734: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801FD738: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801FD73C: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801FD740: lwc1        $f6, 0x9C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x801FD744: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801FD748: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801FD74C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801FD750: jal         0x801FDB90
    // 0x801FD754: nop

    LOOKUP_FUNC(0x801FDB90)(rdram, ctx);
        goto after_4;
    // 0x801FD754: nop

    after_4:
    // 0x801FD758: beq         $v0, $zero, L_801FD768
    if (ctx->r2 == 0) {
        // 0x801FD75C: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_801FD768;
    }
    // 0x801FD75C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FD760: b           L_801FD770
    // 0x801FD764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801FD770;
    // 0x801FD764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801FD768:
    // 0x801FD768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FD76C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801FD770:
    // 0x801FD770: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801FD774: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801FD778: jr          $ra
    // 0x801FD77C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801FD77C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd780(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD780: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FD784: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801FD788: lbu         $t7, -0x43F3($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X43F3);
    // 0x801FD78C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801FD790: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801FD794: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801FD798: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801FD79C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801FD7A0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801FD7A4: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801FD7A8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801FD7AC: jr          $ra
    // 0x801FD7B0: lwc1        $f0, 0x74D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74D4);
    return;
    // 0x801FD7B0: lwc1        $f0, 0x74D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74D4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fd7b4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fd7b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD7B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801FD7B8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801FD7BC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801FD7C0: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x801FD7C4: lwc1        $f14, 0x94($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801FD7C8: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801FD7CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801FD7D0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FD7D4: lwc1        $f4, -0x6DD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6DD4);
    // 0x801FD7D8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FD7DC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FD7E0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801FD7E4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FD7E8: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x801FD7EC: addiu       $t1, $zero, -0x4
    ctx->r9 = ADD32(0, -0X4);
    // 0x801FD7F0: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x801FD7F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801FD7F8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801FD7FC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801FD800: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801FD804: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801FD808: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x801FD80C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801FD810: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801FD814: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801FD818: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801FD81C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801FD820: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801FD824: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801FD828: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801FD82C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801FD830: jal         0x80129FB8
    // 0x801FD834: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_0;
    // 0x801FD834: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801FD838: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801FD83C: addiu       $t3, $zero, 0x3A8
    ctx->r11 = ADD32(0, 0X3A8);
    // 0x801FD840: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x801FD844: lwc1        $f12, 0x90($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801FD848: lwc1        $f14, 0x94($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801FD84C: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x801FD850: jal         0x801FC830
    // 0x801FD854: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_1;
    // 0x801FD854: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x801FD858: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801FD85C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801FD860: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FD864: addiu       $a1, $a1, -0x277C
    ctx->r5 = ADD32(ctx->r5, -0X277C);
    // 0x801FD868: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x801FD86C: jal         0x800058DC
    // 0x801FD870: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FD870: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x801FD874: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801FD878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801FD87C: jr          $ra
    // 0x801FD880: nop

    return;
    // 0x801FD880: nop

;}
RECOMP_FUNC void M9_FUN_801fd884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD884: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801FD888: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FD88C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801FD890: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801FD894: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x801FD898: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801FD89C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801FD8A0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801FD8A4: swc1        $f6, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f6.u32l;
    // 0x801FD8A8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801FD8AC: lwc1        $f10, 0x94($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801FD8B0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801FD8B4: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x801FD8B8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801FD8BC: swc1        $f6, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f6.u32l;
    // 0x801FD8C0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x801FD8C4: lwc1        $f10, 0x98($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X98);
    // 0x801FD8C8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801FD8CC: lwc1        $f8, 0xA0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801FD8D0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801FD8D4: lwc1        $f10, 0x9C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x801FD8D8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FD8DC: swc1        $f6, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f6.u32l;
    // 0x801FD8E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FD8E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FD8E8: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
    // 0x801FD8EC: lwc1        $f6, 0xA0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801FD8F0: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x801FD8F4: nop

    // 0x801FD8F8: bc1t        L_801FD964
    if (c1cs) {
        // 0x801FD8FC: nop
    
            goto L_801FD964;
    }
    // 0x801FD8FC: nop

    // 0x801FD900: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FD904: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801FD908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FD90C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801FD910: lwc1        $f0, 0x90($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801FD914: lwc1        $f2, 0x94($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801FD918: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801FD91C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FD920: lwc1        $f16, 0x98($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X98);
    // 0x801FD924: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801FD928: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801FD92C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801FD930: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x801FD934: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801FD938: sub.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x801FD93C: sub.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801FD940: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801FD944: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x801FD948: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801FD94C: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801FD950: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801FD954: jal         0x80108590
    // 0x801FD958: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80108590)(rdram, ctx);
        goto after_0;
    // 0x801FD958: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801FD95C: beq         $v0, $zero, L_801FD96C
    if (ctx->r2 == 0) {
        // 0x801FD960: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801FD96C;
    }
    // 0x801FD960: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_801FD964:
    // 0x801FD964: jal         0x801FDB3C
    // 0x801FD968: nop

    LOOKUP_FUNC(0x801FDB3C)(rdram, ctx);
        goto after_1;
    // 0x801FD968: nop

    after_1:
L_801FD96C:
    // 0x801FD96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FD970: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801FD974: jr          $ra
    // 0x801FD978: nop

    return;
    // 0x801FD978: nop

;}
RECOMP_FUNC void M9_FUN_801fd97c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FD97C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801FD980: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801FD984: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801FD988: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801FD98C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801FD990: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801FD994: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801FD998: lui         $s3, 0x8021
    ctx->r19 = S32(0X8021 << 16);
    // 0x801FD99C: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801FD9A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801FD9A4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801FD9A8: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x801FD9AC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x801FD9B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801FD9B4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801FD9B8: addiu       $s4, $s4, -0x4400
    ctx->r20 = ADD32(ctx->r20, -0X4400);
    // 0x801FD9BC: addiu       $s3, $s3, 0x72B8
    ctx->r19 = ADD32(ctx->r19, 0X72B8);
    // 0x801FD9C0: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x801FD9C4: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801FD9C8: lw          $t6, 0x20C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20C);
L_801FD9CC:
    // 0x801FD9CC: bnel        $t6, $zero, L_801FDB10
    if (ctx->r14 != 0) {
        // 0x801FD9D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801FDB10;
    }
    goto skip_0;
    // 0x801FD9D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x801FD9D4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x801FD9D8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801FD9DC: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x801FD9E0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801FD9E4: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x801FD9E8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FD9EC: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801FD9F0: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x801FD9F4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FD9F8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801FD9FC: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
    // 0x801FDA00: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FDA04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FDA08: lw          $t8, 0x10($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X10);
    // 0x801FDA0C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FDA10: jal         0x8012C4D0
    // 0x801FDA14: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FDA14: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FDA18: beq         $v0, $zero, L_801FDB0C
    if (ctx->r2 == 0) {
        // 0x801FDA1C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_801FDB0C;
    }
    // 0x801FDA1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801FDA20: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801FDA24: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801FDA28: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801FDA2C: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801FDA30: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801FDA34: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801FDA38: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801FDA3C: jal         0x8001EF38
    // 0x801FDA40: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801FDA40: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x801FDA44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801FDA48: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FDA4C: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x801FDA50: jal         0x8001EAD0
    // 0x801FDA54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801FDA54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x801FDA58: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801FDA5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801FDA60: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801FDA64: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801FDA68: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801FDA6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FDA70: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801FDA74: swc1        $f4, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f4.u32l;
    // 0x801FDA78: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801FDA7C: jal         0x8001EB64
    // 0x801FDA80: swc1        $f6, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801FDA80: swc1        $f6, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f6.u32l;
    after_3:
    // 0x801FDA84: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801FDA88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801FDA8C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801FDA90: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801FDA94: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801FDA98: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801FDA9C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801FDAA0: swc1        $f18, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f18.u32l;
    // 0x801FDAA4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801FDAA8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801FDAAC: nop

    // 0x801FDAB0: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801FDAB4: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801FDAB8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801FDABC: jal         0x8002FC20
    // 0x801FDAC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x801FDAC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x801FDAC4: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801FDAC8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801FDACC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801FDAD0: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801FDAD4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801FDAD8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801FDADC: swc1        $f6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f6.u32l;
    // 0x801FDAE0: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801FDAE4: div.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801FDAE8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801FDAEC: swc1        $f10, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f10.u32l;
    // 0x801FDAF0: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801FDAF4: swc1        $f2, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f2.u32l;
    // 0x801FDAF8: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801FDAFC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801FDB00: swc1        $f6, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f6.u32l;
    // 0x801FDB04: b           L_801FDB1C
    // 0x801FDB08: sw          $s1, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->r17;
        goto L_801FDB1C;
    // 0x801FDB08: sw          $s1, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->r17;
L_801FDB0C:
    // 0x801FDB0C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_801FDB10:
    // 0x801FDB10: bnel        $s0, $s4, L_801FD9CC
    if (ctx->r16 != ctx->r20) {
        // 0x801FDB14: lw          $t6, 0x20C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X20C);
            goto L_801FD9CC;
    }
    goto skip_1;
    // 0x801FDB14: lw          $t6, 0x20C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20C);
    skip_1:
    // 0x801FDB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FDB1C:
    // 0x801FDB1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801FDB20: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801FDB24: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801FDB28: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801FDB2C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801FDB30: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801FDB34: jr          $ra
    // 0x801FDB38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801FDB38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fdb3c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fdb3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDB3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FDB40: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801FDB44: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801FDB48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FDB4C: addiu       $v1, $v1, -0x4400
    ctx->r3 = ADD32(ctx->r3, -0X4400);
    // 0x801FDB50: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801FDB54: lw          $t6, 0x20C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20C);
L_801FDB58:
    // 0x801FDB58: bnel        $a0, $t6, L_801FDB74
    if (ctx->r4 != ctx->r14) {
        // 0x801FDB5C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_801FDB74;
    }
    goto skip_0;
    // 0x801FDB5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x801FDB60: jal         0x80005700
    // 0x801FDB64: sw          $zero, 0x20C($v0)
    MEM_W(0X20C, ctx->r2) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801FDB64: sw          $zero, 0x20C($v0)
    MEM_W(0X20C, ctx->r2) = 0;
    after_0:
    // 0x801FDB68: b           L_801FDB80
    // 0x801FDB6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FDB80;
    // 0x801FDB6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801FDB70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_801FDB74:
    // 0x801FDB74: bnel        $v0, $v1, L_801FDB58
    if (ctx->r2 != ctx->r3) {
        // 0x801FDB78: lw          $t6, 0x20C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X20C);
            goto L_801FDB58;
    }
    goto skip_1;
    // 0x801FDB78: lw          $t6, 0x20C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20C);
    skip_1:
    // 0x801FDB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FDB80:
    // 0x801FDB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FDB84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FDB88: jr          $ra
    // 0x801FDB8C: nop

    return;
    // 0x801FDB8C: nop

;}
RECOMP_FUNC void M9_FUN_801fdb90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDB90: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801FDB94: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x801FDB98: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x801FDB9C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801FDBA0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801FDBA4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801FDBA8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801FDBAC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801FDBB0: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801FDBB4: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x801FDBB8: mtc1        $a3, $f28
    ctx->f28.u32l = ctx->r7;
    // 0x801FDBBC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x801FDBC0: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x801FDBC4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801FDBC8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x801FDBCC: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x801FDBD0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801FDBD4: addiu       $s3, $s3, -0x4400
    ctx->r19 = ADD32(ctx->r19, -0X4400);
    // 0x801FDBD8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x801FDBDC: lw          $s0, 0x20C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X20C);
L_801FDBE0:
    // 0x801FDBE0: beql        $s0, $zero, L_801FDC94
    if (ctx->r16 == 0) {
        // 0x801FDBE4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801FDC94;
    }
    goto skip_0;
    // 0x801FDBE4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x801FDBE8: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FDBEC: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FDBF0: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FDBF4: sub.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x801FDBF8: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x801FDBFC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801FDC00: sub.s       $f2, $f6, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f26.fl;
    // 0x801FDC04: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801FDC08: sub.s       $f14, $f8, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x801FDC0C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801FDC10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801FDC14: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801FDC18: cvt.d.s     $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f6.d = CVT_D_S(ctx->f28.fl);
    // 0x801FDC1C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801FDC20: add.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = ctx->f6.d + ctx->f8.d;
    // 0x801FDC24: jal         0x8002FC20
    // 0x801FDC28: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801FDC28: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x801FDC2C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801FDC30: c.le.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d <= ctx->f20.d;
    // 0x801FDC34: nop

    // 0x801FDC38: bc1fl       L_801FDC94
    if (!c1cs) {
        // 0x801FDC3C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801FDC94;
    }
    goto skip_1;
    // 0x801FDC3C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_1:
    // 0x801FDC40: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801FDC44: jal         0x8001EF38
    // 0x801FDC48: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801FDC48: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_1:
    // 0x801FDC4C: lwc1        $f20, 0xA4($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801FDC50: lwc1        $f18, 0xAC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x801FDC54: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x801FDC58: sub.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x801FDC5C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801FDC60: jal         0x8001EF38
    // 0x801FDC64: sub.s       $f14, $f24, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801FDC64: sub.s       $f14, $f24, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f18.fl;
    after_2:
    // 0x801FDC68: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801FDC6C: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x801FDC70: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801FDC74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801FDC78: jal         0x801FD4F4
    // 0x801FDC7C: addiu       $a2, $zero, 0x555
    ctx->r6 = ADD32(0, 0X555);
    LOOKUP_FUNC(0x801FD4F4)(rdram, ctx);
        goto after_3;
    // 0x801FDC7C: addiu       $a2, $zero, 0x555
    ctx->r6 = ADD32(0, 0X555);
    after_3:
    // 0x801FDC80: beql        $v0, $zero, L_801FDC94
    if (ctx->r2 == 0) {
        // 0x801FDC84: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801FDC94;
    }
    goto skip_2;
    // 0x801FDC84: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_2:
    // 0x801FDC88: b           L_801FDCA0
    // 0x801FDC8C: lw          $v0, 0x20C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20C);
        goto L_801FDCA0;
    // 0x801FDC8C: lw          $v0, 0x20C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20C);
    // 0x801FDC90: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_801FDC94:
    // 0x801FDC94: bnel        $s1, $s3, L_801FDBE0
    if (ctx->r17 != ctx->r19) {
        // 0x801FDC98: lw          $s0, 0x20C($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X20C);
            goto L_801FDBE0;
    }
    goto skip_3;
    // 0x801FDC98: lw          $s0, 0x20C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X20C);
    skip_3:
    // 0x801FDC9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FDCA0:
    // 0x801FDCA0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801FDCA4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801FDCA8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801FDCAC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801FDCB0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801FDCB4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801FDCB8: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x801FDCBC: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801FDCC0: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x801FDCC4: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x801FDCC8: jr          $ra
    // 0x801FDCCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801FDCCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fdcd0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fdcd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDCD0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801FDCD4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801FDCD8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x801FDCDC: lh          $t6, 0x66($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X66);
    // 0x801FDCE0: lh          $t7, 0x6A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6A);
    // 0x801FDCE4: lbu         $t4, 0x73($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X73);
    // 0x801FDCE8: lbu         $t5, 0x77($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X77);
    // 0x801FDCEC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801FDCF0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x801FDCF4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x801FDCF8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801FDCFC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801FDD00: lw          $v0, 0x2578($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2578);
    // 0x801FDD04: sh          $t0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r8;
    // 0x801FDD08: sh          $t9, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r25;
    // 0x801FDD0C: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
    // 0x801FDD10: sh          $t1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r9;
    // 0x801FDD14: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x801FDD18: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x801FDD1C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801FDD20: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801FDD24: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FDD28: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FDD2C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801FDD30: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FDD34: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801FDD38: addiu       $t1, $zero, 0x66
    ctx->r9 = ADD32(0, 0X66);
    // 0x801FDD3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FDD40: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x801FDD44: sh          $t3, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r11;
    // 0x801FDD48: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
    // 0x801FDD4C: sb          $a3, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r7;
    // 0x801FDD50: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    // 0x801FDD54: sb          $t9, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r25;
    // 0x801FDD58: sb          $t8, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r24;
    // 0x801FDD5C: sb          $t7, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r15;
    // 0x801FDD60: sb          $t0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r8;
    // 0x801FDD64: sh          $t1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r9;
    // 0x801FDD68: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x801FDD6C: sb          $t4, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r12;
    // 0x801FDD70: sb          $t5, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r13;
    // 0x801FDD74: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801FDD78: lbu         $t5, 0x7B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X7B);
    // 0x801FDD7C: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801FDD80: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x801FDD84: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801FDD88: addiu       $a1, $a1, 0x76C0
    ctx->r5 = ADD32(ctx->r5, 0X76C0);
    // 0x801FDD8C: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x801FDD90: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x801FDD94: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x801FDD98: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x801FDD9C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x801FDDA0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801FDDA4: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x801FDDA8: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // 0x801FDDAC: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x801FDDB0: jal         0x80146088
    // 0x801FDDB4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x801FDDB4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FDDB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FDDBC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801FDDC0: jr          $ra
    // 0x801FDDC4: nop

    return;
    // 0x801FDDC4: nop

;}
RECOMP_FUNC void M9_FUN_801fddc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDDC8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801FDDCC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x801FDDD0: lh          $t6, 0x62($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X62);
    // 0x801FDDD4: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x801FDDD8: lh          $t7, 0x6A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6A);
    // 0x801FDDDC: lbu         $t9, 0x73($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X73);
    // 0x801FDDE0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801FDDE4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x801FDDE8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x801FDDEC: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x801FDDF0: lbu         $t0, 0x77($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X77);
    // 0x801FDDF4: lbu         $t1, 0x7B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7B);
    // 0x801FDDF8: lbu         $t2, 0x7F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7F);
    // 0x801FDDFC: lbu         $t3, 0x87($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X87);
    // 0x801FDE00: lbu         $t4, 0x8B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X8B);
    // 0x801FDE04: lbu         $t6, 0x93($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X93);
    // 0x801FDE08: lbu         $t5, 0x8F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X8F);
    // 0x801FDE0C: lhu         $t8, 0x82($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X82);
    // 0x801FDE10: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801FDE14: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801FDE18: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x801FDE1C: sb          $t9, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r25;
    // 0x801FDE20: addiu       $a1, $a1, 0x76C0
    ctx->r5 = ADD32(ctx->r5, 0X76C0);
    // 0x801FDE24: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801FDE28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FDE2C: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x801FDE30: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x801FDE34: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x801FDE38: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    // 0x801FDE3C: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x801FDE40: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x801FDE44: sb          $t0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r8;
    // 0x801FDE48: sb          $t1, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r9;
    // 0x801FDE4C: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    // 0x801FDE50: sb          $t3, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r11;
    // 0x801FDE54: sb          $t4, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r12;
    // 0x801FDE58: sb          $t6, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r14;
    // 0x801FDE5C: sb          $t5, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r13;
    // 0x801FDE60: jal         0x80146088
    // 0x801FDE64: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x801FDE64: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FDE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FDE6C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801FDE70: jr          $ra
    // 0x801FDE74: nop

    return;
    // 0x801FDE74: nop

;}
RECOMP_FUNC void M9_FUN_801fde78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDE78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FDE7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FDE80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FDE84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801FDE88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FDE8C: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    // 0x801FDE90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801FDE94:
    // 0x801FDE94: jal         0x80002BAC
    // 0x801FDE98: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_0;
    // 0x801FDE98: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x801FDE9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FDEA0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801FDEA4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801FDEA8: bne         $at, $zero, L_801FDE94
    if (ctx->r1 != 0) {
        // 0x801FDEAC: nop
    
            goto L_801FDE94;
    }
    // 0x801FDEAC: nop

    // 0x801FDEB0: jal         0x80020718
    // 0x801FDEB4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x801FDEB4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_1:
    // 0x801FDEB8: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FDEBC: addiu       $a1, $a1, -0x2124
    ctx->r5 = ADD32(ctx->r5, -0X2124);
    // 0x801FDEC0: jal         0x800058DC
    // 0x801FDEC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FDEC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801FDEC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FDECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FDED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FDED4: jr          $ra
    // 0x801FDED8: nop

    return;
    // 0x801FDED8: nop

;}
RECOMP_FUNC void M9_FUN_801fdedc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDEDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FDEE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FDEE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FDEE8: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FDEEC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FDEF0: slti        $v1, $v0, 0x1F
    ctx->r3 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x801FDEF4: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801FDEF8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FDEFC: beq         $v1, $zero, L_801FDF0C
    if (ctx->r3 == 0) {
        // 0x801FDF00: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801FDF0C;
    }
    // 0x801FDF00: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801FDF04: jal         0x800058DC
    // 0x801FDF08: addiu       $a1, $a1, -0x20E4
    ctx->r5 = ADD32(ctx->r5, -0X20E4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FDF08: addiu       $a1, $a1, -0x20E4
    ctx->r5 = ADD32(ctx->r5, -0X20E4);
    after_0:
L_801FDF0C:
    // 0x801FDF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FDF10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FDF14: jr          $ra
    // 0x801FDF18: nop

    return;
    // 0x801FDF18: nop

;}
RECOMP_FUNC void M9_FUN_801fdf1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDF1C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801FDF20: addiu       $v1, $v1, -0x225C
    ctx->r3 = ADD32(ctx->r3, -0X225C);
    // 0x801FDF24: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fdf28(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fdf28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FDF28: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801FDF2C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801FDF30: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801FDF34: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x801FDF38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FDF3C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801FDF40: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801FDF44: beq         $at, $zero, L_801FDFAC
    if (ctx->r1 == 0) {
        // 0x801FDF48: sb          $zero, 0x57($sp)
        MEM_B(0X57, ctx->r29) = 0;
            goto L_801FDFAC;
    }
    // 0x801FDF48: sb          $zero, 0x57($sp)
    MEM_B(0X57, ctx->r29) = 0;
    // 0x801FDF4C: jal         0x80151BC4
    // 0x801FDF50: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_0;
    // 0x801FDF50: nop

    after_0:
    // 0x801FDF54: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801FDF58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801FDF5C: beq         $v0, $at, L_801FDFAC
    if (ctx->r2 == ctx->r1) {
        // 0x801FDF60: addiu       $v1, $v1, -0x225C
        ctx->r3 = ADD32(ctx->r3, -0X225C);
            goto L_801FDFAC;
    }
    // 0x801FDF60: addiu       $v1, $v1, -0x225C
    ctx->r3 = ADD32(ctx->r3, -0X225C);
    // 0x801FDF64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801FDF68: addiu       $a0, $a0, -0x2284
    ctx->r4 = ADD32(ctx->r4, -0X2284);
    // 0x801FDF6C: lbu         $v0, 0x16($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X16);
    // 0x801FDF70: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801FDF74: beq         $v0, $zero, L_801FDF90
    if (ctx->r2 == 0) {
        // 0x801FDF78: nop
    
            goto L_801FDF90;
    }
    // 0x801FDF78: nop

    // 0x801FDF7C: beq         $v0, $zero, L_801FDFAC
    if (ctx->r2 == 0) {
        // 0x801FDF80: nop
    
            goto L_801FDFAC;
    }
    // 0x801FDF80: nop

    // 0x801FDF84: lbu         $t7, 0x17($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X17);
    // 0x801FDF88: beq         $t7, $zero, L_801FDFAC
    if (ctx->r15 == 0) {
        // 0x801FDF8C: nop
    
            goto L_801FDFAC;
    }
    // 0x801FDF8C: nop

L_801FDF90:
    // 0x801FDF90: lhu         $t8, -0x43E4($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X43E4);
    // 0x801FDF94: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801FDF98: beq         $t8, $at, L_801FDFAC
    if (ctx->r24 == ctx->r1) {
        // 0x801FDF9C: nop
    
            goto L_801FDFAC;
    }
    // 0x801FDF9C: nop

    // 0x801FDFA0: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x801FDFA4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801FDFA8: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_801FDFAC:
    // 0x801FDFAC: jal         0x8013C8E0
    // 0x801FDFB0: nop

    LOOKUP_FUNC(0x8013C8E0)(rdram, ctx);
        goto after_1;
    // 0x801FDFB0: nop

    after_1:
    // 0x801FDFB4: jal         0x8013C8E0
    // 0x801FDFB8: nop

    LOOKUP_FUNC(0x8013C8E0)(rdram, ctx);
        goto after_2;
    // 0x801FDFB8: nop

    after_2:
    // 0x801FDFBC: jal         0x80116E80
    // 0x801FDFC0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_3;
    // 0x801FDFC0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_3:
    // 0x801FDFC4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FDFC8: sb          $t1, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r9;
    // 0x801FDFCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801FDFD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801FDFD4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801FDFD8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801FDFDC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801FDFE0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801FDFE4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801FDFE8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801FDFEC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801FDFF0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801FDFF4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801FDFF8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801FDFFC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801FE000: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801FE004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE008: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    // 0x801FE00C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FE010: jal         0x801FDDC8
    // 0x801FE014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801FDDC8)(rdram, ctx);
        goto after_4;
    // 0x801FE014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801FE018: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x801FE01C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x801FE020: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FE024: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801FE028: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FE02C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801FE030: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801FE034: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801FE038: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801FE03C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801FE040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE044: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    // 0x801FE048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FE04C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801FE050: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801FE054: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801FE058: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801FE05C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801FE060: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801FE064: jal         0x801FDDC8
    // 0x801FE068: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    LOOKUP_FUNC(0x801FDDC8)(rdram, ctx);
        goto after_5;
    // 0x801FE068: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_5:
    // 0x801FE06C: jal         0x80006214
    // 0x801FE070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x801FE070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801FE074: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE078: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x801FE07C: addiu       $a1, $a1, -0x1F5C
    ctx->r5 = ADD32(ctx->r5, -0X1F5C);
    // 0x801FE080: jal         0x800058DC
    // 0x801FE084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801FE084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801FE088: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801FE08C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801FE090: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801FE094: jr          $ra
    // 0x801FE098: nop

    return;
    // 0x801FE098: nop

;}
RECOMP_FUNC void M9_FUN_801fe09c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE09C: jr          $ra
    // 0x801FE0A0: nop

    return;
    // 0x801FE0A0: nop

;}
RECOMP_FUNC void M9_FUN_801fe0a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE0A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FE0A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FE0AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FE0B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FE0B4: lh          $v1, 0xB0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE0B8: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x801FE0BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FE0C0: bnel        $v1, $at, L_801FE0E0
    if (ctx->r3 != ctx->r1) {
        // 0x801FE0C4: slti        $at, $v1, 0x35
        ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
            goto L_801FE0E0;
    }
    goto skip_0;
    // 0x801FE0C4: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    skip_0:
    // 0x801FE0C8: jal         0x80126E88
    // 0x801FE0CC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x801FE0CC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x801FE0D0: jal         0x80126E88
    // 0x801FE0D4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x801FE0D4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_1:
    // 0x801FE0D8: lh          $v1, 0xB0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB0);
    // 0x801FE0DC: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
L_801FE0E0:
    // 0x801FE0E0: bnel        $at, $zero, L_801FE110
    if (ctx->r1 != 0) {
        // 0x801FE0E4: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_801FE110;
    }
    goto skip_1;
    // 0x801FE0E4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_1:
    // 0x801FE0E8: lbu         $t6, 0xAA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XAA);
    // 0x801FE0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE0F0: addiu       $a1, $zero, 0x128
    ctx->r5 = ADD32(0, 0X128);
    // 0x801FE0F4: bnel        $t6, $zero, L_801FE110
    if (ctx->r14 != 0) {
        // 0x801FE0F8: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_801FE110;
    }
    goto skip_2;
    // 0x801FE0F8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_2:
    // 0x801FE0FC: jal         0x80126A0C
    // 0x801FE100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_2;
    // 0x801FE100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801FE104: sb          $v0, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = ctx->r2;
    // 0x801FE108: lh          $v1, 0xB0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB0);
    // 0x801FE10C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
L_801FE110:
    // 0x801FE110: bnel        $v1, $at, L_801FE124
    if (ctx->r3 != ctx->r1) {
        // 0x801FE114: lbu         $t8, 0xAB($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0XAB);
            goto L_801FE124;
    }
    goto skip_3;
    // 0x801FE114: lbu         $t8, 0xAB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XAB);
    skip_3:
    // 0x801FE118: jal         0x80020718
    // 0x801FE11C: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_3;
    // 0x801FE11C: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_3:
    // 0x801FE120: lbu         $t8, 0xAB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XAB);
L_801FE124:
    // 0x801FE124: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801FE128: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801FE12C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801FE130: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801FE134: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801FE138: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE13C: addiu       $a1, $a1, -0x1DB0
    ctx->r5 = ADD32(ctx->r5, -0X1DB0);
    // 0x801FE140: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FE144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE148: lbu         $t3, 0xB($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XB);
    // 0x801FE14C: bnel        $t3, $at, L_801FE168
    if (ctx->r11 != ctx->r1) {
        // 0x801FE150: lh          $v1, 0xB0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XB0);
            goto L_801FE168;
    }
    goto skip_4;
    // 0x801FE150: lh          $v1, 0xB0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB0);
    skip_4:
    // 0x801FE154: jal         0x800058DC
    // 0x801FE158: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801FE158: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    after_4:
    // 0x801FE15C: b           L_801FE240
    // 0x801FE160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801FE240;
    // 0x801FE160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FE164: lh          $v1, 0xB0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB0);
L_801FE168:
    // 0x801FE168: sll         $a0, $v1, 6
    ctx->r4 = S32(ctx->r3 << 6);
    // 0x801FE16C: bgez        $a0, L_801FE178
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801FE170: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_801FE178;
    }
    // 0x801FE170: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x801FE174: addiu       $at, $a0, 0x3
    ctx->r1 = ADD32(ctx->r4, 0X3);
L_801FE178:
    // 0x801FE178: sra         $a0, $at, 2
    ctx->r4 = S32(SIGNED(ctx->r1) >> 2);
    // 0x801FE17C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801FE180: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x801FE184: sh          $t4, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r12;
    // 0x801FE188: jal         0x8001EAD0
    // 0x801FE18C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x801FE18C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x801FE190: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801FE194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FE198: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801FE19C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801FE1A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801FE1A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801FE1A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801FE1AC: nop

    // 0x801FE1B0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801FE1B4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801FE1B8: nop

    // 0x801FE1BC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801FE1C0: beql        $t6, $zero, L_801FE210
    if (ctx->r14 == 0) {
        // 0x801FE1C4: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_801FE210;
    }
    goto skip_5;
    // 0x801FE1C4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x801FE1C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FE1CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801FE1D0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801FE1D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801FE1D8: nop

    // 0x801FE1DC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801FE1E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801FE1E4: nop

    // 0x801FE1E8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801FE1EC: bne         $t6, $zero, L_801FE204
    if (ctx->r14 != 0) {
        // 0x801FE1F0: nop
    
            goto L_801FE204;
    }
    // 0x801FE1F0: nop

    // 0x801FE1F4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801FE1F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801FE1FC: b           L_801FE21C
    // 0x801FE200: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801FE21C;
    // 0x801FE200: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801FE204:
    // 0x801FE204: b           L_801FE21C
    // 0x801FE208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801FE21C;
    // 0x801FE208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801FE20C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_801FE210:
    // 0x801FE210: nop

    // 0x801FE214: bltz        $t6, L_801FE204
    if (SIGNED(ctx->r14) < 0) {
        // 0x801FE218: nop
    
            goto L_801FE204;
    }
    // 0x801FE218: nop

L_801FE21C:
    // 0x801FE21C: lbu         $t7, 0xAB($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAB);
    // 0x801FE220: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801FE224: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801FE228: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801FE22C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801FE230: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801FE234: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FE238: sb          $t6, 0xB($t2)
    MEM_B(0XB, ctx->r10) = ctx->r14;
    // 0x801FE23C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FE240:
    // 0x801FE240: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FE244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FE248: jr          $ra
    // 0x801FE24C: nop

    return;
    // 0x801FE24C: nop

;}
RECOMP_FUNC void M9_FUN_801fe250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE250: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801FE254: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801FE258: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801FE25C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801FE260: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801FE264: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    // 0x801FE268: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE26C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FE270: addiu       $s1, $sp, 0x3F
    ctx->r17 = ADD32(ctx->r29, 0X3F);
    // 0x801FE274: slti        $v1, $v0, 0x21
    ctx->r3 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801FE278: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801FE27C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FE280: beq         $v1, $zero, L_801FE5DC
    if (ctx->r3 == 0) {
        // 0x801FE284: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801FE5DC;
    }
    // 0x801FE284: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801FE288: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FE28C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801FE290: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801FE294: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FE298: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801FE29C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FE2A0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801FE2A4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE2A8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE2AC: jal         0x801FDCD0
    // 0x801FE2B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_0;
    // 0x801FE2B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x801FE2B4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801FE2B8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FE2BC: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x801FE2C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801FE2C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801FE2C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801FE2CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE2D0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801FE2D4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE2D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE2DC: jal         0x801FDCD0
    // 0x801FE2E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_1;
    // 0x801FE2E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_1:
    // 0x801FE2E4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FE2E8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801FE2EC: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801FE2F0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801FE2F4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801FE2F8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801FE2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE300: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x801FE304: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE308: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE30C: jal         0x801FDCD0
    // 0x801FE310: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_2;
    // 0x801FE310: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_2:
    // 0x801FE314: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FE318: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FE31C: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x801FE320: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801FE324: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FE328: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FE32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE330: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801FE334: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE338: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE33C: jal         0x801FDCD0
    // 0x801FE340: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_3;
    // 0x801FE340: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_3:
    // 0x801FE344: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FE348: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801FE34C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x801FE350: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801FE354: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801FE358: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801FE35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE360: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801FE364: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE368: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE36C: jal         0x801FDCD0
    // 0x801FE370: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_4;
    // 0x801FE370: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_4:
    // 0x801FE374: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801FE378: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FE37C: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x801FE380: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801FE384: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801FE388: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801FE38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE390: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x801FE394: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE398: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE39C: jal         0x801FDCD0
    // 0x801FE3A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_5;
    // 0x801FE3A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_5:
    // 0x801FE3A4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801FE3A8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FE3AC: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x801FE3B0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801FE3B4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801FE3B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801FE3BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE3C0: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x801FE3C4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE3C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE3CC: jal         0x801FDCD0
    // 0x801FE3D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_6;
    // 0x801FE3D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_6:
    // 0x801FE3D4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801FE3D8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FE3DC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x801FE3E0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801FE3E4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801FE3E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FE3EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE3F0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801FE3F4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE3F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE3FC: jal         0x801FDCD0
    // 0x801FE400: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_7;
    // 0x801FE400: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_7:
    // 0x801FE404: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FE408: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801FE40C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801FE410: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801FE414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE418: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801FE41C: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE420: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE424: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801FE428: jal         0x801FDCD0
    // 0x801FE42C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_8;
    // 0x801FE42C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_8:
    // 0x801FE430: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FE434: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801FE438: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801FE43C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801FE440: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801FE444: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801FE448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE44C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801FE450: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE454: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE458: jal         0x801FDCD0
    // 0x801FE45C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_9;
    // 0x801FE45C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_9:
    // 0x801FE460: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FE464: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FE468: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801FE46C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801FE470: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FE474: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FE478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE47C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x801FE480: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE484: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE488: jal         0x801FDCD0
    // 0x801FE48C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_10;
    // 0x801FE48C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_10:
    // 0x801FE490: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FE494: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801FE498: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801FE49C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801FE4A0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801FE4A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801FE4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE4AC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801FE4B0: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE4B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE4B8: jal         0x801FDCD0
    // 0x801FE4BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_11;
    // 0x801FE4BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_11:
    // 0x801FE4C0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801FE4C4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FE4C8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801FE4CC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801FE4D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801FE4D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801FE4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE4DC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801FE4E0: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE4E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE4E8: jal         0x801FDCD0
    // 0x801FE4EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_12;
    // 0x801FE4EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_12:
    // 0x801FE4F0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801FE4F4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FE4F8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801FE4FC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801FE500: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801FE504: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801FE508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE50C: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x801FE510: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE514: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE518: jal         0x801FDCD0
    // 0x801FE51C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_13;
    // 0x801FE51C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_13:
    // 0x801FE520: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801FE524: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FE528: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x801FE52C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801FE530: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801FE534: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FE538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE53C: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x801FE540: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE544: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE548: jal         0x801FDCD0
    // 0x801FE54C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_14;
    // 0x801FE54C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_14:
    // 0x801FE550: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FE554: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801FE558: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801FE55C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801FE560: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801FE564: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801FE568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE56C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801FE570: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x801FE574: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801FE578: jal         0x801FDCD0
    // 0x801FE57C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x801FDCD0)(rdram, ctx);
        goto after_15;
    // 0x801FE57C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_15:
    // 0x801FE580: jal         0x80006214
    // 0x801FE584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_16;
    // 0x801FE584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801FE588: lbu         $t5, 0xAB($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XAB);
    // 0x801FE58C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x801FE590: addiu       $t4, $zero, 0x140
    ctx->r12 = ADD32(0, 0X140);
    // 0x801FE594: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801FE598: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x801FE59C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801FE5A0: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x801FE5A4: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x801FE5A8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801FE5AC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE5B0: addiu       $a1, $a1, -0x1A10
    ctx->r5 = ADD32(ctx->r5, -0X1A10);
    // 0x801FE5B4: sh          $t4, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r12;
    // 0x801FE5B8: lbu         $t1, 0xAB($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XAB);
    // 0x801FE5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FE5C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801FE5C4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x801FE5C8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801FE5CC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801FE5D0: sh          $t0, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r8;
    // 0x801FE5D4: jal         0x800058DC
    // 0x801FE5D8: sh          $t7, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x801FE5D8: sh          $t7, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r15;
    after_17:
L_801FE5DC:
    // 0x801FE5DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801FE5E0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801FE5E4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801FE5E8: jr          $ra
    // 0x801FE5EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801FE5EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fe5f0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fe5f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE5F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FE5F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FE5F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801FE5FC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_801FE600:
    // 0x801FE600: lbu         $t6, 0xAB($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE604: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x801FE608: lbu         $v0, 0xB1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB1);
    // 0x801FE60C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FE610: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801FE614: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801FE618: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801FE61C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801FE620: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801FE624: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FE628: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x801FE62C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801FE630: sb          $v0, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r2;
    // 0x801FE634: lbu         $t2, 0xAB($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE638: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801FE63C: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x801FE640: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x801FE644: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801FE648: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FE64C: sb          $v0, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r2;
    // 0x801FE650: lbu         $t8, 0xAB($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE654: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801FE658: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x801FE65C: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x801FE660: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801FE664: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801FE668: sb          $v0, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r2;
    // 0x801FE66C: lbu         $t4, 0xAB($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE670: lbu         $v0, 0xB1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB1);
    // 0x801FE674: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801FE678: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x801FE67C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x801FE680: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801FE684: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801FE688: sb          $v0, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r2;
    // 0x801FE68C: lbu         $t0, 0xAB($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE690: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801FE694: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x801FE698: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x801FE69C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801FE6A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FE6A4: sb          $v0, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r2;
    // 0x801FE6A8: lbu         $t6, 0xAB($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE6AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FE6B0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801FE6B4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801FE6B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801FE6BC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FE6C0: bne         $at, $zero, L_801FE600
    if (ctx->r1 != 0) {
        // 0x801FE6C4: sb          $v0, 0xC($t1)
        MEM_B(0XC, ctx->r9) = ctx->r2;
            goto L_801FE600;
    }
    // 0x801FE6C4: sb          $v0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r2;
    // 0x801FE6C8: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE6CC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE6D0: addiu       $a1, $a1, -0x1900
    ctx->r5 = ADD32(ctx->r5, -0X1900);
    // 0x801FE6D4: bne         $v0, $zero, L_801FE6EC
    if (ctx->r2 != 0) {
        // 0x801FE6D8: addiu       $t2, $v0, -0x4
        ctx->r10 = ADD32(ctx->r2, -0X4);
            goto L_801FE6EC;
    }
    // 0x801FE6D8: addiu       $t2, $v0, -0x4
    ctx->r10 = ADD32(ctx->r2, -0X4);
    // 0x801FE6DC: jal         0x800058DC
    // 0x801FE6E0: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FE6E0: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    after_0:
    // 0x801FE6E4: b           L_801FE6F4
    // 0x801FE6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FE6F4;
    // 0x801FE6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FE6EC:
    // 0x801FE6EC: sh          $t2, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r10;
    // 0x801FE6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FE6F4:
    // 0x801FE6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FE6F8: jr          $ra
    // 0x801FE6FC: nop

    return;
    // 0x801FE6FC: nop

;}
RECOMP_FUNC void M9_FUN_801fe700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FE704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FE708: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE70C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801FE710: slti        $v1, $v0, 0x6
    ctx->r3 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801FE714: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FE718: beq         $v1, $zero, L_801FE76C
    if (ctx->r3 == 0) {
        // 0x801FE71C: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801FE76C;
    }
    // 0x801FE71C: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801FE720: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801FE724: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_801FE728:
    // 0x801FE728: lbu         $t7, 0xAB($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XAB);
    // 0x801FE72C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x801FE730: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801FE734: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801FE738: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x801FE73C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801FE740: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801FE744: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801FE748: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x801FE74C: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801FE750: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801FE754: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x801FE758: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801FE75C: bne         $at, $zero, L_801FE728
    if (ctx->r1 != 0) {
        // 0x801FE760: sh          $t4, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r12;
            goto L_801FE728;
    }
    // 0x801FE760: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x801FE764: b           L_801FE784
    // 0x801FE768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FE784;
    // 0x801FE768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FE76C:
    // 0x801FE76C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE770: sh          $zero, 0xB0($a2)
    MEM_H(0XB0, ctx->r6) = 0;
    // 0x801FE774: addiu       $a1, $a1, -0x1870
    ctx->r5 = ADD32(ctx->r5, -0X1870);
    // 0x801FE778: jal         0x800058DC
    // 0x801FE77C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FE77C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x801FE780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FE784:
    // 0x801FE784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FE788: jr          $ra
    // 0x801FE78C: nop

    return;
    // 0x801FE78C: nop

;}
RECOMP_FUNC void M9_FUN_801fe790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FE794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FE798: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE79C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801FE7A0: addiu       $t7, $zero, 0xF8
    ctx->r15 = ADD32(0, 0XF8);
    // 0x801FE7A4: slti        $v1, $v0, 0x8
    ctx->r3 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x801FE7A8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FE7AC: beq         $v1, $zero, L_801FE81C
    if (ctx->r3 == 0) {
        // 0x801FE7B0: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801FE81C;
    }
    // 0x801FE7B0: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801FE7B4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801FE7B8: lhu         $t7, -0x43E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X43E0);
    // 0x801FE7BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801FE7C0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801FE7C4: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x801FE7C8: mfhi        $t8
    ctx->r24 = hi;
    // 0x801FE7CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801FE7D0: bnel        $t8, $zero, L_801FE834
    if (ctx->r24 != 0) {
        // 0x801FE7D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801FE834;
    }
    goto skip_0;
    // 0x801FE7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_801FE7D8:
    // 0x801FE7D8: lbu         $t9, 0xAB($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XAB);
    // 0x801FE7DC: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x801FE7E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801FE7E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801FE7E8: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x801FE7EC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801FE7F0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801FE7F4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801FE7F8: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x801FE7FC: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801FE800: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801FE804: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x801FE808: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801FE80C: bne         $at, $zero, L_801FE7D8
    if (ctx->r1 != 0) {
        // 0x801FE810: sh          $t6, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r14;
            goto L_801FE7D8;
    }
    // 0x801FE810: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x801FE814: b           L_801FE834
    // 0x801FE818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FE834;
    // 0x801FE818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FE81C:
    // 0x801FE81C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE820: sh          $t7, 0xB0($a2)
    MEM_H(0XB0, ctx->r6) = ctx->r15;
    // 0x801FE824: addiu       $a1, $a1, -0x17C0
    ctx->r5 = ADD32(ctx->r5, -0X17C0);
    // 0x801FE828: jal         0x800058DC
    // 0x801FE82C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FE82C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x801FE830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FE834:
    // 0x801FE834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FE838: jr          $ra
    // 0x801FE83C: nop

    return;
    // 0x801FE83C: nop

;}
RECOMP_FUNC void M9_FUN_801fe840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FE844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FE848: lbu         $t6, 0xAB($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE84C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801FE850: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801FE854: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FE858: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801FE85C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801FE860: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FE864: addiu       $a1, $a1, -0x15FC
    ctx->r5 = ADD32(ctx->r5, -0X15FC);
    // 0x801FE868: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801FE86C: lbu         $t0, 0xB($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XB);
    // 0x801FE870: beq         $t0, $zero, L_801FE9E4
    if (ctx->r8 == 0) {
        // 0x801FE874: nop
    
            goto L_801FE9E4;
    }
    // 0x801FE874: nop

    // 0x801FE878: lh          $t1, 0xB0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE87C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801FE880: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801FE884: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801FE888: sb          $t2, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r10;
L_801FE88C:
    // 0x801FE88C: lbu         $t6, 0xAB($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE890: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x801FE894: lh          $t3, 0xB0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE898: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FE89C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x801FE8A0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801FE8A4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801FE8A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801FE8AC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801FE8B0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FE8B4: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x801FE8B8: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x801FE8BC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x801FE8C0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801FE8C4: bne         $at, $zero, L_801FE88C
    if (ctx->r1 != 0) {
        // 0x801FE8C8: sb          $t5, 0x8($t2)
        MEM_B(0X8, ctx->r10) = ctx->r13;
            goto L_801FE88C;
    }
    // 0x801FE8C8: sb          $t5, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r13;
    // 0x801FE8CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801FE8D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_801FE8D4:
    // 0x801FE8D4: lbu         $t6, 0xAB($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE8D8: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x801FE8DC: lh          $t3, 0xB0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE8E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FE8E4: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x801FE8E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x801FE8EC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801FE8F0: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x801FE8F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801FE8F8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FE8FC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801FE900: slti        $at, $a1, 0x12
    ctx->r1 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x801FE904: sb          $t4, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r12;
    // 0x801FE908: lbu         $t3, 0xAB($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE90C: lh          $t5, 0xB0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE910: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801FE914: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801FE918: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x801FE91C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801FE920: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801FE924: subu        $t2, $v1, $t5
    ctx->r10 = SUB32(ctx->r3, ctx->r13);
    // 0x801FE928: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FE92C: sb          $t2, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r10;
    // 0x801FE930: lbu         $t5, 0xAB($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE934: lh          $t4, 0xB0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE938: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x801FE93C: addu        $t6, $a3, $t3
    ctx->r14 = ADD32(ctx->r7, ctx->r11);
    // 0x801FE940: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801FE944: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801FE948: subu        $t1, $v1, $t4
    ctx->r9 = SUB32(ctx->r3, ctx->r12);
    // 0x801FE94C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801FE950: bne         $at, $zero, L_801FE8D4
    if (ctx->r1 != 0) {
        // 0x801FE954: sb          $t1, 0xE($t9)
        MEM_B(0XE, ctx->r25) = ctx->r9;
            goto L_801FE8D4;
    }
    // 0x801FE954: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x801FE958: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801FE95C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_801FE960:
    // 0x801FE960: lbu         $t2, 0xAB($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE964: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x801FE968: lh          $v1, 0xB0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE96C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801FE970: addu        $t4, $a3, $t0
    ctx->r12 = ADD32(ctx->r7, ctx->r8);
    // 0x801FE974: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x801FE978: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x801FE97C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x801FE980: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801FE984: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x801FE988: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801FE98C: slti        $at, $a1, 0x12
    ctx->r1 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x801FE990: sb          $v1, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r3;
    // 0x801FE994: lbu         $t7, 0xAB($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE998: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801FE99C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801FE9A0: addu        $t1, $a3, $t8
    ctx->r9 = ADD32(ctx->r7, ctx->r24);
    // 0x801FE9A4: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x801FE9A8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x801FE9AC: lw          $t0, 0x30($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X30);
    // 0x801FE9B0: sb          $v1, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r3;
    // 0x801FE9B4: lbu         $t4, 0xAB($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XAB);
    // 0x801FE9B8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801FE9BC: addu        $t3, $a3, $t5
    ctx->r11 = ADD32(ctx->r7, ctx->r13);
    // 0x801FE9C0: addu        $t6, $t3, $v0
    ctx->r14 = ADD32(ctx->r11, ctx->r2);
    // 0x801FE9C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801FE9C8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FE9CC: bne         $at, $zero, L_801FE960
    if (ctx->r1 != 0) {
        // 0x801FE9D0: sb          $v1, 0xC($t8)
        MEM_B(0XC, ctx->r24) = ctx->r3;
            goto L_801FE960;
    }
    // 0x801FE9D0: sb          $v1, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r3;
    // 0x801FE9D4: lh          $t1, 0xB0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XB0);
    // 0x801FE9D8: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x801FE9DC: b           L_801FE9EC
    // 0x801FE9E0: sh          $t9, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r25;
        goto L_801FE9EC;
    // 0x801FE9E0: sh          $t9, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r25;
L_801FE9E4:
    // 0x801FE9E4: jal         0x800058DC
    // 0x801FE9E8: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FE9E8: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    after_0:
L_801FE9EC:
    // 0x801FE9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FE9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FE9F4: jr          $ra
    // 0x801FE9F8: nop

    return;
    // 0x801FE9F8: nop

;}
RECOMP_FUNC void M9_FUN_801fe9fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FE9FC: jr          $ra
    // 0x801FEA00: nop

    return;
    // 0x801FEA00: nop

;}
RECOMP_FUNC void M9_FUN_801fea04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEA04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FEA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FEA0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FEA10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FEA14: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FEA18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FEA1C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801FEA20: slti        $v1, $v0, 0x1F
    ctx->r3 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x801FEA24: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801FEA28: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FEA2C: beq         $v1, $zero, L_801FEA60
    if (ctx->r3 == 0) {
        // 0x801FEA30: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801FEA60;
    }
    // 0x801FEA30: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801FEA34: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801FEA38: ori         $a0, $a0, 0xC00
    ctx->r4 = ctx->r4 | 0XC00;
    // 0x801FEA3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801FEA40: jal         0x80002364
    // 0x801FEA44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_0;
    // 0x801FEA44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801FEA48: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FEA4C: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x801FEA50: sb          $zero, 0x90($s0)
    MEM_B(0X90, ctx->r16) = 0;
    // 0x801FEA54: addiu       $a1, $a1, -0x158C
    ctx->r5 = ADD32(ctx->r5, -0X158C);
    // 0x801FEA58: jal         0x800058DC
    // 0x801FEA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FEA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_801FEA60:
    // 0x801FEA60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FEA64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FEA68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FEA6C: jr          $ra
    // 0x801FEA70: nop

    return;
    // 0x801FEA70: nop

;}
RECOMP_FUNC void M9_FUN_801fea74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEA74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FEA78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FEA7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FEA80: lh          $v0, 0xB0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB0);
    // 0x801FEA84: slti        $v1, $v0, 0x33
    ctx->r3 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x801FEA88: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801FEA8C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FEA90: beq         $v1, $zero, L_801FEAC4
    if (ctx->r3 == 0) {
        // 0x801FEA94: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801FEAC4;
    }
    // 0x801FEA94: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801FEA98: jal         0x80020744
    // 0x801FEA9C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x801FEA9C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x801FEAA0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801FEAA4: jal         0x800023EC
    // 0x801FEAA8: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_1;
    // 0x801FEAA8: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    after_1:
    // 0x801FEAAC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x801FEAB0: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801FEAB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801FEAB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801FEABC: jal         0x8012FE50
    // 0x801FEAC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x801FEAC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
L_801FEAC4:
    // 0x801FEAC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FEAC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FEACC: jr          $ra
    // 0x801FEAD0: nop

    return;
    // 0x801FEAD0: nop

;}
RECOMP_FUNC void M9_FUN_801fead4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEAD4: nop

    // 0x801FEAD8: nop

    // 0x801FEADC: nop

;}
