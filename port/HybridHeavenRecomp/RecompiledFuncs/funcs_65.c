#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801ed038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED038: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED03C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED040: jr          $ra
    // 0x801ED044: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801ED044: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed048(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED048: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED04C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED050: jr          $ra
    // 0x801ED054: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801ED054: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed058(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED05C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED068: lui         $a1, 0x2A5
    ctx->r5 = S32(0X2A5 << 16);
    // 0x801ED06C: ori         $a1, $a1, 0x7D80
    ctx->r5 = ctx->r5 | 0X7D80;
    // 0x801ED070: jal         0x801C0B8C
    // 0x801ED074: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED074: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED078: beq         $v0, $zero, L_801ED0A8
    if (ctx->r2 == 0) {
        // 0x801ED07C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801ED0A8;
    }
    // 0x801ED07C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED080: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801ED084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED088: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ED08C: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x801ED090: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED094: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ED098: jal         0x801CC470
    // 0x801ED09C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED09C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801ED0A0: b           L_801ED0AC
    // 0x801ED0A4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801ED0AC;
    // 0x801ED0A4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801ED0A8:
    // 0x801ED0A8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801ED0AC:
    // 0x801ED0AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED0B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED0B4: jr          $ra
    // 0x801ED0B8: nop

    return;
    // 0x801ED0B8: nop

;}
RECOMP_FUNC void M25_FUN_801ed0bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ED0C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801ED0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ED0C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ED0CC: lui         $a1, 0x2F1
    ctx->r5 = S32(0X2F1 << 16);
    // 0x801ED0D0: ori         $a1, $a1, 0xC8C0
    ctx->r5 = ctx->r5 | 0XC8C0;
    // 0x801ED0D4: jal         0x801C0B8C
    // 0x801ED0D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED0D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED0DC: beql        $v0, $zero, L_801ED0F8
    if (ctx->r2 == 0) {
        // 0x801ED0E0: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_801ED0F8;
    }
    goto skip_0;
    // 0x801ED0E0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    skip_0:
    // 0x801ED0E4: jal         0x801D1258
    // 0x801ED0E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D1258)(rdram, ctx);
        goto after_1;
    // 0x801ED0E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801ED0EC: b           L_801ED0F8
    // 0x801ED0F0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801ED0F8;
    // 0x801ED0F0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801ED0F4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801ED0F8:
    // 0x801ED0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ED0FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801ED100: jr          $ra
    // 0x801ED104: nop

    return;
    // 0x801ED104: nop

;}
RECOMP_FUNC void M25_FUN_801ed108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED10C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED110: jr          $ra
    // 0x801ED114: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801ED114: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed118(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED11C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED124: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED128: lui         $a1, 0x34B
    ctx->r5 = S32(0X34B << 16);
    // 0x801ED12C: ori         $a1, $a1, 0xCFA0
    ctx->r5 = ctx->r5 | 0XCFA0;
    // 0x801ED130: jal         0x801C0B8C
    // 0x801ED134: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED134: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED138: beq         $v0, $zero, L_801ED1D4
    if (ctx->r2 == 0) {
        // 0x801ED13C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801ED1D4;
    }
    // 0x801ED13C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED140: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801ED144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED148: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ED14C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED150: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ED154: jal         0x801CC470
    // 0x801ED158: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED158: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801ED15C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801ED160: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ED164: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ED168: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801ED16C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED174: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801ED178: jal         0x801CC4D8
    // 0x801ED17C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC4D8)(rdram, ctx);
        goto after_2;
    // 0x801ED17C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801ED180: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801ED184: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801ED188: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801ED18C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801ED190: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED194: lui         $at, 0x3A00
    ctx->r1 = S32(0X3A00 << 16);
    // 0x801ED198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED19C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED1A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED1A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801ED1A8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED1AC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED1B0: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x801ED1B4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801ED1B8: nop

    // 0x801ED1BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801ED1C0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801ED1C4: nop

    // 0x801ED1C8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801ED1CC: b           L_801ED1D8
    // 0x801ED1D0: swc1        $f6, -0x2B88($at)
    MEM_W(-0X2B88, ctx->r1) = ctx->f6.u32l;
        goto L_801ED1D8;
    // 0x801ED1D0: swc1        $f6, -0x2B88($at)
    MEM_W(-0X2B88, ctx->r1) = ctx->f6.u32l;
L_801ED1D4:
    // 0x801ED1D4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801ED1D8:
    // 0x801ED1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED1E0: jr          $ra
    // 0x801ED1E4: nop

    return;
    // 0x801ED1E4: nop

;}
RECOMP_FUNC void M25_FUN_801ed1e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED1EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED1F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED1F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED1F8: lui         $a1, 0x35B
    ctx->r5 = S32(0X35B << 16);
    // 0x801ED1FC: ori         $a1, $a1, 0x11E0
    ctx->r5 = ctx->r5 | 0X11E0;
    // 0x801ED200: jal         0x801C0B8C
    // 0x801ED204: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED204: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED208: beq         $v0, $zero, L_801ED244
    if (ctx->r2 == 0) {
        // 0x801ED20C: lui         $v1, 0x8020
        ctx->r3 = S32(0X8020 << 16);
            goto L_801ED244;
    }
    // 0x801ED20C: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801ED210: jal         0x801D1258
    // 0x801ED214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D1258)(rdram, ctx);
        goto after_1;
    // 0x801ED214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801ED218: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801ED21C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED220: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ED224: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801ED228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED22C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801ED230: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801ED234: jal         0x801CC470
    // 0x801ED238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801ED238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801ED23C: b           L_801ED2A4
    // 0x801ED240: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801ED2A4;
    // 0x801ED240: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801ED244:
    // 0x801ED244: addiu       $v1, $v1, -0x2B88
    ctx->r3 = ADD32(ctx->r3, -0X2B88);
    // 0x801ED248: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED24C: lwc1        $f8, -0x3768($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3768);
    // 0x801ED250: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801ED254: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801ED258: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ED25C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801ED260: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801ED264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ED268: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801ED26C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801ED270: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801ED274: lw          $t8, -0x54EC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X54EC);
    // 0x801ED278: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801ED27C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801ED280: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801ED284: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801ED288: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801ED28C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801ED290: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801ED294: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801ED298: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x801ED29C: nop

    // 0x801ED2A0: sh          $t7, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r15;
L_801ED2A4:
    // 0x801ED2A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED2A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED2AC: jr          $ra
    // 0x801ED2B0: nop

    return;
    // 0x801ED2B0: nop

;}
RECOMP_FUNC void M25_FUN_801ed2b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED2B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED2B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED2BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED2C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED2C4: lui         $a1, 0x392
    ctx->r5 = S32(0X392 << 16);
    // 0x801ED2C8: ori         $a1, $a1, 0x60
    ctx->r5 = ctx->r5 | 0X60;
    // 0x801ED2CC: jal         0x801C0B8C
    // 0x801ED2D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED2D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED2D4: beq         $v0, $zero, L_801ED388
    if (ctx->r2 == 0) {
        // 0x801ED2D8: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801ED388;
    }
    // 0x801ED2D8: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801ED2DC: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801ED2E0: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801ED2E4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801ED2E8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801ED2EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED2F0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED2F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ED2F8: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x801ED2FC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED300: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ED304: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801ED308: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED30C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ED310: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ED314: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED318: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801ED31C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED320: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801ED324: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801ED328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED32C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801ED330: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED334: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ED338: addiu       $t3, $zero, 0x1800
    ctx->r11 = ADD32(0, 0X1800);
    // 0x801ED33C: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ED340: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ED344: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x801ED348: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801ED34C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED350: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801ED354: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x801ED358: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801ED35C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801ED360: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x801ED364: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801ED368: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801ED36C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801ED370: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801ED374: sh          $t3, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r11;
    // 0x801ED378: jal         0x801CC470
    // 0x801ED37C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED37C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ED380: b           L_801ED3B8
    // 0x801ED384: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801ED3B8;
    // 0x801ED384: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801ED388:
    // 0x801ED388: addiu       $t0, $t0, -0x54EC
    ctx->r8 = ADD32(ctx->r8, -0X54EC);
    // 0x801ED38C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x801ED390: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED394: lwc1        $f18, -0x3764($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3764);
    // 0x801ED398: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801ED39C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x801ED3A0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ED3A4: lw          $t4, 0x24($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X24);
    // 0x801ED3A8: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x801ED3AC: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801ED3B0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801ED3B4: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
L_801ED3B8:
    // 0x801ED3B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED3BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED3C0: jr          $ra
    // 0x801ED3C4: nop

    return;
    // 0x801ED3C4: nop

;}
RECOMP_FUNC void M25_FUN_801ed3c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED3C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED3CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED3D0: jr          $ra
    // 0x801ED3D4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801ED3D4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed3d8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed3d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED3D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED3DC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED3E0: jr          $ra
    // 0x801ED3E4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x801ED3E4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed3e8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed3e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED3E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED3EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED3F0: jr          $ra
    // 0x801ED3F4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x801ED3F4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed3f8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed3f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED3F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED3FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED400: jr          $ra
    // 0x801ED404: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x801ED404: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed408(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED408: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED40C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED414: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED418: lui         $a1, 0x40D
    ctx->r5 = S32(0X40D << 16);
    // 0x801ED41C: ori         $a1, $a1, 0x9900
    ctx->r5 = ctx->r5 | 0X9900;
    // 0x801ED420: jal         0x801C0B8C
    // 0x801ED424: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED424: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED428: beq         $v0, $zero, L_801ED4D8
    if (ctx->r2 == 0) {
        // 0x801ED42C: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801ED4D8;
    }
    // 0x801ED42C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801ED430: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801ED434: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED438: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED43C: lwc1        $f4, -0x3760($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3760);
    // 0x801ED440: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED444: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ED448: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED44C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED450: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ED454: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801ED458: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED45C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED460: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED464: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED468: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801ED46C: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801ED470: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801ED474: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ED478: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801ED47C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED480: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801ED484: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801ED488: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801ED48C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED490: lwc1        $f8, -0x375C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X375C);
    // 0x801ED494: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801ED498: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED49C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ED4A0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED4A4: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED4A8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED4AC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801ED4B0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801ED4B4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED4B8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ED4BC: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ED4C0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ED4C4: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801ED4C8: jal         0x801CC470
    // 0x801ED4CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED4CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ED4D0: b           L_801ED4DC
    // 0x801ED4D4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801ED4DC;
    // 0x801ED4D4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801ED4D8:
    // 0x801ED4D8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801ED4DC:
    // 0x801ED4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED4E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED4E4: jr          $ra
    // 0x801ED4E8: nop

    return;
    // 0x801ED4E8: nop

;}
RECOMP_FUNC void M25_FUN_801ed4ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED4EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED4F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED4F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED4F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED4FC: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801ED500: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801ED504: jal         0x801C0B8C
    // 0x801ED508: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED508: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED50C: beq         $v0, $zero, L_801ED5BC
    if (ctx->r2 == 0) {
        // 0x801ED510: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801ED5BC;
    }
    // 0x801ED510: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801ED514: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801ED518: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED51C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED520: lwc1        $f4, -0x3758($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3758);
    // 0x801ED524: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED528: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ED52C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED530: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED534: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801ED538: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    // 0x801ED53C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED540: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED548: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED54C: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801ED550: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801ED554: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801ED558: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ED55C: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801ED560: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED564: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801ED568: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801ED56C: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801ED570: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED574: lwc1        $f8, -0x3754($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3754);
    // 0x801ED578: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801ED57C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ED584: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED588: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED58C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED590: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801ED594: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801ED598: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED59C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ED5A0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ED5A4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ED5A8: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801ED5AC: jal         0x801CC470
    // 0x801ED5B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED5B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ED5B4: b           L_801ED5C0
    // 0x801ED5B8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_801ED5C0;
    // 0x801ED5B8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801ED5BC:
    // 0x801ED5BC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801ED5C0:
    // 0x801ED5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED5C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED5C8: jr          $ra
    // 0x801ED5CC: nop

    return;
    // 0x801ED5CC: nop

;}
RECOMP_FUNC void M25_FUN_801ed5d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED5D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED5D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED5D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED5DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED5E0: lui         $a1, 0x4FF
    ctx->r5 = S32(0X4FF << 16);
    // 0x801ED5E4: ori         $a1, $a1, 0xB42A
    ctx->r5 = ctx->r5 | 0XB42A;
    // 0x801ED5E8: jal         0x801C0B8C
    // 0x801ED5EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED5EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED5F0: beq         $v0, $zero, L_801ED6A0
    if (ctx->r2 == 0) {
        // 0x801ED5F4: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801ED6A0;
    }
    // 0x801ED5F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801ED5F8: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801ED5FC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED600: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED604: lwc1        $f4, -0x3750($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3750);
    // 0x801ED608: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED60C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ED610: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED614: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED618: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ED61C: ori         $a1, $a1, 0x17
    ctx->r5 = ctx->r5 | 0X17;
    // 0x801ED620: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED62C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801ED634: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801ED638: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801ED63C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ED640: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801ED644: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED648: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801ED64C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801ED650: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801ED654: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED658: lwc1        $f8, -0x374C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X374C);
    // 0x801ED65C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ED660: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ED668: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED66C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED670: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED674: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801ED678: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801ED67C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED680: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ED684: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ED688: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ED68C: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801ED690: jal         0x801CC470
    // 0x801ED694: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED694: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ED698: b           L_801ED6A4
    // 0x801ED69C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801ED6A4;
    // 0x801ED69C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801ED6A0:
    // 0x801ED6A0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801ED6A4:
    // 0x801ED6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED6AC: jr          $ra
    // 0x801ED6B0: nop

    return;
    // 0x801ED6B0: nop

;}
RECOMP_FUNC void M25_FUN_801ed6b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED6B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ED6B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801ED6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ED6C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ED6C4: lui         $a1, 0x54C
    ctx->r5 = S32(0X54C << 16);
    // 0x801ED6C8: ori         $a1, $a1, 0xC2BA
    ctx->r5 = ctx->r5 | 0XC2BA;
    // 0x801ED6CC: jal         0x801C0B8C
    // 0x801ED6D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED6D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED6D4: beq         $v0, $zero, L_801ED760
    if (ctx->r2 == 0) {
        // 0x801ED6D8: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801ED760;
    }
    // 0x801ED6D8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801ED6DC: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801ED6E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801ED6E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED6E8: lwc1        $f4, -0x3748($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3748);
    // 0x801ED6EC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED6F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ED6F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED6F8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED6FC: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801ED700: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED704: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED708: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801ED70C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801ED710: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ED714: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801ED718: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED71C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801ED720: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801ED724: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801ED728: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801ED72C: lwc1        $f8, -0x3744($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3744);
    // 0x801ED730: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED734: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED738: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED73C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED740: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801ED744: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801ED748: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED74C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ED750: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ED754: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ED758: b           L_801ED764
    // 0x801ED75C: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
        goto L_801ED764;
    // 0x801ED75C: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
L_801ED760:
    // 0x801ED760: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801ED764:
    // 0x801ED764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ED768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801ED76C: jr          $ra
    // 0x801ED770: nop

    return;
    // 0x801ED770: nop

;}
RECOMP_FUNC void M25_FUN_801ed774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ED778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801ED77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ED780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ED784: lui         $a1, 0x57A
    ctx->r5 = S32(0X57A << 16);
    // 0x801ED788: ori         $a1, $a1, 0x897A
    ctx->r5 = ctx->r5 | 0X897A;
    // 0x801ED78C: jal         0x801C0B8C
    // 0x801ED790: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED790: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED794: beq         $v0, $zero, L_801ED7A4
    if (ctx->r2 == 0) {
        // 0x801ED798: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801ED7A4;
    }
    // 0x801ED798: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801ED79C: b           L_801ED7B4
    // 0x801ED7A0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_801ED7B4;
    // 0x801ED7A0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_801ED7A4:
    // 0x801ED7A4: lui         $a1, 0x54C
    ctx->r5 = S32(0X54C << 16);
    // 0x801ED7A8: jal         0x801C0B8C
    // 0x801ED7AC: ori         $a1, $a1, 0xC2BA
    ctx->r5 = ctx->r5 | 0XC2BA;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801ED7AC: ori         $a1, $a1, 0xC2BA
    ctx->r5 = ctx->r5 | 0XC2BA;
    after_1:
    // 0x801ED7B0: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_801ED7B4:
    // 0x801ED7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ED7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801ED7BC: jr          $ra
    // 0x801ED7C0: nop

    return;
    // 0x801ED7C0: nop

;}
RECOMP_FUNC void M25_FUN_801ed7c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED7C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED7C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED7CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED7D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED7D4: lui         $a1, 0x5BF
    ctx->r5 = S32(0X5BF << 16);
    // 0x801ED7D8: ori         $a1, $a1, 0x339A
    ctx->r5 = ctx->r5 | 0X339A;
    // 0x801ED7DC: jal         0x801C0B8C
    // 0x801ED7E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED7E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED7E4: beq         $v0, $zero, L_801ED894
    if (ctx->r2 == 0) {
        // 0x801ED7E8: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801ED894;
    }
    // 0x801ED7E8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801ED7EC: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801ED7F0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED7F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED7F8: lwc1        $f4, -0x3740($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3740);
    // 0x801ED7FC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED800: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ED804: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801ED808: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED80C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ED810: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x801ED814: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED818: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED820: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED824: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801ED828: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801ED82C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801ED830: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801ED834: addiu       $t1, $zero, 0x1800
    ctx->r9 = ADD32(0, 0X1800);
    // 0x801ED838: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED83C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801ED840: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801ED844: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801ED848: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801ED84C: lwc1        $f8, -0x373C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X373C);
    // 0x801ED850: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ED854: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801ED858: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ED85C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801ED860: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801ED864: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801ED868: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801ED86C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801ED870: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801ED874: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801ED878: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801ED87C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801ED880: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801ED884: jal         0x801CC470
    // 0x801ED888: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED888: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801ED88C: b           L_801ED898
    // 0x801ED890: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_801ED898;
    // 0x801ED890: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_801ED894:
    // 0x801ED894: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_801ED898:
    // 0x801ED898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED89C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED8A0: jr          $ra
    // 0x801ED8A4: nop

    return;
    // 0x801ED8A4: nop

;}
RECOMP_FUNC void M25_FUN_801ed8a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED8A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ED8AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801ED8B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ED8B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ED8B8: lui         $a1, 0x650
    ctx->r5 = S32(0X650 << 16);
    // 0x801ED8BC: ori         $a1, $a1, 0x28FA
    ctx->r5 = ctx->r5 | 0X28FA;
    // 0x801ED8C0: jal         0x801C0B8C
    // 0x801ED8C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED8C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED8C8: beq         $v0, $zero, L_801ED8F8
    if (ctx->r2 == 0) {
        // 0x801ED8CC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801ED8F8;
    }
    // 0x801ED8CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801ED8D0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801ED8D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ED8D8: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801ED8DC: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x801ED8E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801ED8E4: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801ED8E8: jal         0x801CC470
    // 0x801ED8EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801ED8EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801ED8F0: b           L_801ED8FC
    // 0x801ED8F4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_801ED8FC;
    // 0x801ED8F4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801ED8F8:
    // 0x801ED8F8: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_801ED8FC:
    // 0x801ED8FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ED900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ED904: jr          $ra
    // 0x801ED908: nop

    return;
    // 0x801ED908: nop

;}
RECOMP_FUNC void M25_FUN_801ed90c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED90C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801ED910: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801ED914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ED918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801ED91C: lui         $a1, 0x739
    ctx->r5 = S32(0X739 << 16);
    // 0x801ED920: ori         $a1, $a1, 0x9E9A
    ctx->r5 = ctx->r5 | 0X9E9A;
    // 0x801ED924: jal         0x801C0B8C
    // 0x801ED928: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801ED928: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801ED92C: beq         $v0, $zero, L_801ED93C
    if (ctx->r2 == 0) {
        // 0x801ED930: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801ED93C;
    }
    // 0x801ED930: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801ED934: b           L_801ED994
    // 0x801ED938: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_801ED994;
    // 0x801ED938: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_801ED93C:
    // 0x801ED93C: lui         $a1, 0x71E
    ctx->r5 = S32(0X71E << 16);
    // 0x801ED940: jal         0x801C0B8C
    // 0x801ED944: ori         $a1, $a1, 0x275A
    ctx->r5 = ctx->r5 | 0X275A;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801ED944: ori         $a1, $a1, 0x275A
    ctx->r5 = ctx->r5 | 0X275A;
    after_1:
    // 0x801ED948: beq         $v0, $zero, L_801ED958
    if (ctx->r2 == 0) {
        // 0x801ED94C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801ED958;
    }
    // 0x801ED94C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801ED950: b           L_801ED994
    // 0x801ED954: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_801ED994;
    // 0x801ED954: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801ED958:
    // 0x801ED958: lui         $a1, 0x6FF
    ctx->r5 = S32(0X6FF << 16);
    // 0x801ED95C: jal         0x801C0B8C
    // 0x801ED960: ori         $a1, $a1, 0xA2DA
    ctx->r5 = ctx->r5 | 0XA2DA;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801ED960: ori         $a1, $a1, 0xA2DA
    ctx->r5 = ctx->r5 | 0XA2DA;
    after_2:
    // 0x801ED964: beq         $v0, $zero, L_801ED974
    if (ctx->r2 == 0) {
        // 0x801ED968: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801ED974;
    }
    // 0x801ED968: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801ED96C: b           L_801ED994
    // 0x801ED970: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_801ED994;
    // 0x801ED970: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801ED974:
    // 0x801ED974: lui         $a1, 0x6D9
    ctx->r5 = S32(0X6D9 << 16);
    // 0x801ED978: jal         0x801C0B8C
    // 0x801ED97C: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801ED97C: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    after_3:
    // 0x801ED980: beql        $v0, $zero, L_801ED994
    if (ctx->r2 == 0) {
        // 0x801ED984: addiu       $v0, $zero, 0x19
        ctx->r2 = ADD32(0, 0X19);
            goto L_801ED994;
    }
    goto skip_0;
    // 0x801ED984: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    skip_0:
    // 0x801ED988: b           L_801ED994
    // 0x801ED98C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_801ED994;
    // 0x801ED98C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x801ED990: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801ED994:
    // 0x801ED994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801ED998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801ED99C: jr          $ra
    // 0x801ED9A0: nop

    return;
    // 0x801ED9A0: nop

;}
RECOMP_FUNC void M25_FUN_801ed9a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED9A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED9A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED9AC: jr          $ra
    // 0x801ED9B0: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x801ED9B0: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed9b4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed9b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED9B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED9B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED9BC: jr          $ra
    // 0x801ED9C0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x801ED9C0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed9c4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed9c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED9C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED9C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED9CC: jr          $ra
    // 0x801ED9D0: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x801ED9D0: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed9d4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed9d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED9D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801ED9D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801ED9DC: jr          $ra
    // 0x801ED9E0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x801ED9E0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ed9e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ed9e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ED9E4: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801ED9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801ED9EC: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801ED9F0: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801ED9F4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801ED9F8: jal         0x801BF628
    // 0x801ED9FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801ED9FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801EDA00: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801EDA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EDA08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801EDA0C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801EDA10: bne         $at, $zero, L_801EDA20
    if (ctx->r1 != 0) {
        // 0x801EDA14: nop
    
            goto L_801EDA20;
    }
    // 0x801EDA14: nop

    // 0x801EDA18: b           L_801EDA20
    // 0x801EDA1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801EDA20;
    // 0x801EDA1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EDA20:
    // 0x801EDA20: jr          $ra
    // 0x801EDA24: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801EDA24: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eda28(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eda28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDA28: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EDA2C: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eda30(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eda30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDA30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EDA34: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EDA38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EDA3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EDA40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EDA44: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDA48: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x801EDA4C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EDA50: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDA54: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDA58: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EDA5C: beql        $t0, $zero, L_801EDBAC
    if (ctx->r8 == 0) {
        // 0x801EDA60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801EDBAC;
    }
    goto skip_0;
    // 0x801EDA60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801EDA64: jal         0x801C0B8C
    // 0x801EDA68: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDA68: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    after_0:
    // 0x801EDA6C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EDA70: beq         $v0, $zero, L_801EDB2C
    if (ctx->r2 == 0) {
        // 0x801EDA74: addiu       $v1, $v1, -0x54EC
        ctx->r3 = ADD32(ctx->r3, -0X54EC);
            goto L_801EDB2C;
    }
    // 0x801EDA74: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EDA78: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EDA7C: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EDA80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDA84: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EDA88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801EDA8C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EDA90: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EDA94: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EDA98: ori         $a1, $a1, 0x11
    ctx->r5 = ctx->r5 | 0X11;
    // 0x801EDA9C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EDAA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EDAA8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EDAAC: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801EDAB0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EDAB4: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x801EDAB8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801EDABC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDAC0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDAC4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EDAC8: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x801EDACC: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EDAD0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EDAD4: swc1        $f0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f0.u32l;
    // 0x801EDAD8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EDADC: lwc1        $f6, -0x3738($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3738);
    // 0x801EDAE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EDAE4: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EDAE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EDAEC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EDAF0: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EDAF4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EDAF8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EDAFC: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x801EDB00: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801EDB04: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EDB08: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EDB0C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EDB10: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801EDB14: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801EDB18: sh          $t9, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r25;
    // 0x801EDB1C: jal         0x801CC470
    // 0x801EDB20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EDB20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801EDB24: b           L_801EDBAC
    // 0x801EDB28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EDBAC;
    // 0x801EDB28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EDB2C:
    // 0x801EDB2C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EDB30: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EDB34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EDB38: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDB3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801EDB40: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDB44: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801EDB48: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EDB4C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EDB50: swc1        $f10, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f10.u32l;
    // 0x801EDB54: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EDB58: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EDB5C: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x801EDB60: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x801EDB64: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EDB68: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EDB6C: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x801EDB70: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EDB74: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801EDB78: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EDB7C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EDB80: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EDB84: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EDB88: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801EDB8C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EDB90: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x801EDB94: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EDB98: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDB9C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EDBA0: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801EDBA4: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x801EDBA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EDBAC:
    // 0x801EDBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EDBB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EDBB4: jr          $ra
    // 0x801EDBB8: nop

    return;
    // 0x801EDBB8: nop

;}
RECOMP_FUNC void M25_FUN_801edbbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDBBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EDBC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EDBC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EDBC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EDBCC: lui         $a1, 0x205
    ctx->r5 = S32(0X205 << 16);
    // 0x801EDBD0: ori         $a1, $a1, 0x45E0
    ctx->r5 = ctx->r5 | 0X45E0;
    // 0x801EDBD4: jal         0x801C0B8C
    // 0x801EDBD8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDBD8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EDBDC: beq         $v0, $zero, L_801EDC0C
    if (ctx->r2 == 0) {
        // 0x801EDBE0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801EDC0C;
    }
    // 0x801EDBE0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDBE4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EDBE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDBEC: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EDBF0: ori         $a1, $a1, 0x12
    ctx->r5 = ctx->r5 | 0X12;
    // 0x801EDBF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EDBF8: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EDBFC: jal         0x801CC470
    // 0x801EDC00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EDC00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EDC04: b           L_801EDC10
    // 0x801EDC08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801EDC10;
    // 0x801EDC08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EDC0C:
    // 0x801EDC0C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EDC10:
    // 0x801EDC10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EDC14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EDC18: jr          $ra
    // 0x801EDC1C: nop

    return;
    // 0x801EDC1C: nop

;}
RECOMP_FUNC void M25_FUN_801edc20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDC20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EDC24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EDC28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EDC2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EDC30: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801EDC34: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801EDC38: jal         0x801C0B8C
    // 0x801EDC3C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDC3C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EDC40: beq         $v0, $zero, L_801EDCA4
    if (ctx->r2 == 0) {
        // 0x801EDC44: lui         $t7, 0x801E
        ctx->r15 = S32(0X801E << 16);
            goto L_801EDCA4;
    }
    // 0x801EDC44: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801EDC48: lw          $t7, -0x54EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X54EC);
    // 0x801EDC4C: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x801EDC50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EDC54: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDC58: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDC5C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EDC60: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EDC64: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EDC68: jal         0x801CFD34
    // 0x801EDC6C: sh          $t6, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r14;
    LOOKUP_FUNC(0x801CFD34)(rdram, ctx);
        goto after_1;
    // 0x801EDC6C: sh          $t6, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r14;
    after_1:
    // 0x801EDC70: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EDC74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDC78: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EDC7C: ori         $a1, $a1, 0x9
    ctx->r5 = ctx->r5 | 0X9;
    // 0x801EDC80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDC84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EDC88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EDC8C: jal         0x801CC470
    // 0x801EDC90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_2;
    // 0x801EDC90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801EDC94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EDC98: sw          $zero, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = 0;
    // 0x801EDC9C: b           L_801EDCA8
    // 0x801EDCA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801EDCA8;
    // 0x801EDCA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EDCA4:
    // 0x801EDCA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EDCA8:
    // 0x801EDCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EDCAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EDCB0: jr          $ra
    // 0x801EDCB4: nop

    return;
    // 0x801EDCB4: nop

;}
RECOMP_FUNC void M25_FUN_801edcb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDCB8: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EDCBC: lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A5C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801edcc0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801edcc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDCC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EDCC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EDCC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EDCCC: beq         $v0, $zero, L_801EDCE8
    if (ctx->r2 == 0) {
        // 0x801EDCD0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801EDCE8;
    }
    // 0x801EDCD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EDCD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801EDCD8: beq         $v0, $at, L_801EDD38
    if (ctx->r2 == ctx->r1) {
        // 0x801EDCDC: nop
    
            goto L_801EDD38;
    }
    // 0x801EDCDC: nop

    // 0x801EDCE0: b           L_801EDD74
    // 0x801EDCE4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801EDD74;
    // 0x801EDCE4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EDCE8:
    // 0x801EDCE8: lui         $a1, 0x4FF
    ctx->r5 = S32(0X4FF << 16);
    // 0x801EDCEC: ori         $a1, $a1, 0xB42A
    ctx->r5 = ctx->r5 | 0XB42A;
    // 0x801EDCF0: jal         0x801C0B8C
    // 0x801EDCF4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDCF4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EDCF8: beq         $v0, $zero, L_801EDD70
    if (ctx->r2 == 0) {
        // 0x801EDCFC: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801EDD70;
    }
    // 0x801EDCFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDD00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EDD04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDD08: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EDD0C: ori         $a1, $a1, 0xA
    ctx->r5 = ctx->r5 | 0XA;
    // 0x801EDD10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EDD14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EDD18: jal         0x801CC470
    // 0x801EDD1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EDD1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EDD20: jal         0x8038D28C
    // 0x801EDD24: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_2;
    // 0x801EDD24: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_2:
    // 0x801EDD28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801EDD2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EDD30: b           L_801EDD70
    // 0x801EDD34: sw          $t6, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r14;
        goto L_801EDD70;
    // 0x801EDD34: sw          $t6, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r14;
L_801EDD38:
    // 0x801EDD38: jal         0x801CFD50
    // 0x801EDD3C: nop

    LOOKUP_FUNC(0x801CFD50)(rdram, ctx);
        goto after_3;
    // 0x801EDD3C: nop

    after_3:
    // 0x801EDD40: beq         $v0, $zero, L_801EDD70
    if (ctx->r2 == 0) {
        // 0x801EDD44: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801EDD70;
    }
    // 0x801EDD44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDD48: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801EDD4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EDD50: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EDD54: ori         $a1, $a1, 0x1E
    ctx->r5 = ctx->r5 | 0X1E;
    // 0x801EDD58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EDD5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EDD60: jal         0x801CC470
    // 0x801EDD64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_4;
    // 0x801EDD64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801EDD68: b           L_801EDD74
    // 0x801EDD6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EDD74;
    // 0x801EDD6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EDD70:
    // 0x801EDD70: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EDD74:
    // 0x801EDD74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EDD78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EDD7C: jr          $ra
    // 0x801EDD80: nop

    return;
    // 0x801EDD80: nop

;}
RECOMP_FUNC void M25_FUN_801edd84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDD84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EDD88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EDD8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EDD90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EDD94: lui         $a1, 0x517
    ctx->r5 = S32(0X517 << 16);
    // 0x801EDD98: ori         $a1, $a1, 0x5ADA
    ctx->r5 = ctx->r5 | 0X5ADA;
    // 0x801EDD9C: jal         0x801C0B8C
    // 0x801EDDA0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDDA0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EDDA4: beq         $v0, $zero, L_801EDE48
    if (ctx->r2 == 0) {
        // 0x801EDDA8: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EDE48;
    }
    // 0x801EDDA8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EDDAC: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EDDB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EDDB4: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EDDB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDDBC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDDC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EDDC4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EDDC8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDDCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EDDD0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDDD4: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EDDD8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EDDDC: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801EDDE0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801EDDE4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EDDE8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EDDEC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EDDF0: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x801EDDF4: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EDDF8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EDDFC: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x801EDE00: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EDE04: lwc1        $f8, -0x3734($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3734);
    // 0x801EDE08: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDE0C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EDE10: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EDE14: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EDE18: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EDE1C: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801EDE20: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801EDE24: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EDE28: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDE2C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDE30: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EDE34: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EDE38: jal         0x801CFD34
    // 0x801EDE3C: sh          $t4, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r12;
    LOOKUP_FUNC(0x801CFD34)(rdram, ctx);
        goto after_1;
    // 0x801EDE3C: sh          $t4, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r12;
    after_1:
    // 0x801EDE40: b           L_801EDE4C
    // 0x801EDE44: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EDE4C;
    // 0x801EDE44: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EDE48:
    // 0x801EDE48: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EDE4C:
    // 0x801EDE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EDE50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EDE54: jr          $ra
    // 0x801EDE58: nop

    return;
    // 0x801EDE58: nop

;}
RECOMP_FUNC void M25_FUN_801ede5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDE5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EDE60: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EDE64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDE68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EDE6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EDE70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EDE74: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EDE78: ori         $a1, $a1, 0x21
    ctx->r5 = ctx->r5 | 0X21;
    // 0x801EDE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDE80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EDE84: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801EDE88: jal         0x801CC470
    // 0x801EDE8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801EDE8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801EDE90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EDE94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EDE98: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801EDE9C: jr          $ra
    // 0x801EDEA0: nop

    return;
    // 0x801EDEA0: nop

;}
RECOMP_FUNC void M25_FUN_801edea4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDEA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EDEA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EDEAC: jr          $ra
    // 0x801EDEB0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801EDEB0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801edeb4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801edeb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDEB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EDEB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EDEBC: jr          $ra
    // 0x801EDEC0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801EDEC0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801edec4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801edec4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDEC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EDEC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EDECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EDED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EDED4: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801EDED8: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801EDEDC: jal         0x801C0B8C
    // 0x801EDEE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDEE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EDEE4: beq         $v0, $zero, L_801EDEF4
    if (ctx->r2 == 0) {
        // 0x801EDEE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EDEF4;
    }
    // 0x801EDEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EDEEC: b           L_801EDEF8
    // 0x801EDEF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801EDEF8;
    // 0x801EDEF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801EDEF4:
    // 0x801EDEF4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801EDEF8:
    // 0x801EDEF8: jr          $ra
    // 0x801EDEFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EDEFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801edf00(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801edf00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDF00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EDF04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EDF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EDF0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EDF10: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801EDF14: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801EDF18: jal         0x801C0B8C
    // 0x801EDF1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EDF1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EDF20: beq         $v0, $zero, L_801EDFE0
    if (ctx->r2 == 0) {
        // 0x801EDF24: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EDFE0;
    }
    // 0x801EDF24: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EDF28: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EDF2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EDF30: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EDF34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EDF38: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDF3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EDF40: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EDF44: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDF48: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EDF4C: ori         $a1, $a1, 0x1D
    ctx->r5 = ctx->r5 | 0X1D;
    // 0x801EDF50: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDF54: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EDF58: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x801EDF5C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EDF60: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EDF64: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EDF68: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801EDF6C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801EDF70: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EDF74: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EDF78: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EDF7C: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x801EDF80: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EDF84: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EDF88: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x801EDF8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EDF90: lwc1        $f8, -0x3730($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3730);
    // 0x801EDF94: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801EDF98: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EDF9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EDFA0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EDFA4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EDFA8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EDFAC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EDFB0: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801EDFB4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801EDFB8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EDFBC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EDFC0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EDFC4: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EDFC8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EDFCC: sh          $t4, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r12;
    // 0x801EDFD0: jal         0x801CC470
    // 0x801EDFD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EDFD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EDFD8: b           L_801EDFE4
    // 0x801EDFDC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801EDFE4;
    // 0x801EDFDC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801EDFE0:
    // 0x801EDFE0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801EDFE4:
    // 0x801EDFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EDFE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EDFEC: jr          $ra
    // 0x801EDFF0: nop

    return;
    // 0x801EDFF0: nop

;}
RECOMP_FUNC void M25_FUN_801edff4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EDFF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EDFF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EDFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EE004: lui         $a1, 0x622
    ctx->r5 = S32(0X622 << 16);
    // 0x801EE008: ori         $a1, $a1, 0x623A
    ctx->r5 = ctx->r5 | 0X623A;
    // 0x801EE00C: jal         0x801C0B8C
    // 0x801EE010: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE010: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE014: beq         $v0, $zero, L_801EE024
    if (ctx->r2 == 0) {
        // 0x801EE018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EE024;
    }
    // 0x801EE018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE01C: b           L_801EE028
    // 0x801EE020: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801EE028;
    // 0x801EE020: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801EE024:
    // 0x801EE024: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801EE028:
    // 0x801EE028: jr          $ra
    // 0x801EE02C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EE02C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee030(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE034: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801EE038: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE03C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE048: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EE04C: ori         $a1, $a1, 0x1D
    ctx->r5 = ctx->r5 | 0X1D;
    // 0x801EE050: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EE054: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE058: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EE05C: jal         0x801CC470
    // 0x801EE060: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801EE060: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801EE064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE06C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x801EE070: jr          $ra
    // 0x801EE074: nop

    return;
    // 0x801EE074: nop

;}
RECOMP_FUNC void M25_FUN_801ee078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE07C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE080: jr          $ra
    // 0x801EE084: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x801EE084: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee088(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE088: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE08C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE090: jr          $ra
    // 0x801EE094: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801EE094: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee098(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE098: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE09C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE0A0: jr          $ra
    // 0x801EE0A4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x801EE0A4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee0a8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee0a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EE0AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EE0B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE0B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EE0B8: lui         $a1, 0x667
    ctx->r5 = S32(0X667 << 16);
    // 0x801EE0BC: ori         $a1, $a1, 0xC5A
    ctx->r5 = ctx->r5 | 0XC5A;
    // 0x801EE0C0: jal         0x801C0B8C
    // 0x801EE0C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE0C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE0C8: beq         $v0, $zero, L_801EE0D8
    if (ctx->r2 == 0) {
        // 0x801EE0CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EE0D8;
    }
    // 0x801EE0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE0D0: b           L_801EE0DC
    // 0x801EE0D4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801EE0DC;
    // 0x801EE0D4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801EE0D8:
    // 0x801EE0D8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801EE0DC:
    // 0x801EE0DC: jr          $ra
    // 0x801EE0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EE0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee0e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee0e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE0E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE0E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE0EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE0F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE0F4: lui         $a1, 0x667
    ctx->r5 = S32(0X667 << 16);
    // 0x801EE0F8: ori         $a1, $a1, 0xC5A
    ctx->r5 = ctx->r5 | 0XC5A;
    // 0x801EE0FC: jal         0x801C0B8C
    // 0x801EE100: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE100: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE104: beq         $v0, $zero, L_801EE1C4
    if (ctx->r2 == 0) {
        // 0x801EE108: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EE1C4;
    }
    // 0x801EE108: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EE10C: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EE110: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EE114: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EE118: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE11C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE120: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EE124: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE128: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE12C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EE130: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x801EE134: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE138: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EE13C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE140: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EE144: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EE148: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EE14C: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801EE150: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801EE154: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE158: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE15C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE160: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x801EE164: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EE168: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EE16C: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x801EE170: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EE174: lwc1        $f8, -0x372C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X372C);
    // 0x801EE178: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EE17C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE180: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EE184: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE188: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE18C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EE190: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EE194: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801EE198: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801EE19C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE1A0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE1A4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE1A8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EE1AC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EE1B0: sh          $t4, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r12;
    // 0x801EE1B4: jal         0x801CC470
    // 0x801EE1B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EE1B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EE1BC: b           L_801EE1C8
    // 0x801EE1C0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_801EE1C8;
    // 0x801EE1C0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801EE1C4:
    // 0x801EE1C4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801EE1C8:
    // 0x801EE1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE1CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE1D0: jr          $ra
    // 0x801EE1D4: nop

    return;
    // 0x801EE1D4: nop

;}
RECOMP_FUNC void M25_FUN_801ee1d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE1D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE1DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE1E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE1E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE1E8: lui         $a1, 0x6D9
    ctx->r5 = S32(0X6D9 << 16);
    // 0x801EE1EC: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    // 0x801EE1F0: jal         0x801C0B8C
    // 0x801EE1F4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE1F4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE1F8: beq         $v0, $zero, L_801EE2BC
    if (ctx->r2 == 0) {
        // 0x801EE1FC: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EE2BC;
    }
    // 0x801EE1FC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EE200: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EE204: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EE208: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE20C: lwc1        $f4, -0x3728($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3728);
    // 0x801EE210: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE214: lui         $at, 0xC178
    ctx->r1 = S32(0XC178 << 16);
    // 0x801EE218: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EE21C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE220: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE224: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EE228: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE22C: ori         $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 | 0X1F;
    // 0x801EE230: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EE234: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EE238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE23C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EE240: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EE244: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801EE248: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801EE24C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE250: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE254: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE258: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x801EE25C: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801EE260: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801EE264: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x801EE268: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EE26C: lwc1        $f8, -0x3724($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3724);
    // 0x801EE270: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EE274: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE278: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EE27C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE280: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE284: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EE288: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EE28C: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801EE290: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801EE294: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE298: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE29C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE2A0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EE2A4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EE2A8: sh          $t4, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r12;
    // 0x801EE2AC: jal         0x801CC470
    // 0x801EE2B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EE2B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EE2B4: b           L_801EE2C0
    // 0x801EE2B8: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801EE2C0;
    // 0x801EE2B8: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801EE2BC:
    // 0x801EE2BC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801EE2C0:
    // 0x801EE2C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE2C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE2C8: jr          $ra
    // 0x801EE2CC: nop

    return;
    // 0x801EE2CC: nop

;}
RECOMP_FUNC void M25_FUN_801ee2d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EE2D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EE2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EE2E0: lui         $a1, 0x70E
    ctx->r5 = S32(0X70E << 16);
    // 0x801EE2E4: ori         $a1, $a1, 0xE51A
    ctx->r5 = ctx->r5 | 0XE51A;
    // 0x801EE2E8: jal         0x801C0B8C
    // 0x801EE2EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE2EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE2F0: beq         $v0, $zero, L_801EE324
    if (ctx->r2 == 0) {
        // 0x801EE2F4: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801EE324;
    }
    // 0x801EE2F4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801EE2F8: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801EE2FC: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EE300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE304: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE308: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x801EE30C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE310: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE314: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EE318: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EE31C: b           L_801EE328
    // 0x801EE320: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
        goto L_801EE328;
    // 0x801EE320: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
L_801EE324:
    // 0x801EE324: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801EE328:
    // 0x801EE328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EE330: jr          $ra
    // 0x801EE334: nop

    return;
    // 0x801EE334: nop

;}
RECOMP_FUNC void M25_FUN_801ee338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE338: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE33C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE340: jr          $ra
    // 0x801EE344: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801EE344: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee348(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE348: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801EE34C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE350: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801EE354: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801EE358: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801EE35C: jal         0x801BF628
    // 0x801EE360: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801EE360: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801EE364: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801EE368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE36C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801EE370: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801EE374: bne         $at, $zero, L_801EE384
    if (ctx->r1 != 0) {
        // 0x801EE378: nop
    
            goto L_801EE384;
    }
    // 0x801EE378: nop

    // 0x801EE37C: b           L_801EE384
    // 0x801EE380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801EE384;
    // 0x801EE380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EE384:
    // 0x801EE384: jr          $ra
    // 0x801EE388: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801EE388: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee38c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee38c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE38C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EE390: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee394(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE398: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EE39C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE3A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE3A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE3A8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE3AC: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x801EE3B0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EE3B4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE3B8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE3BC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE3C0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EE3C4: beql        $t1, $zero, L_801EE540
    if (ctx->r9 == 0) {
        // 0x801EE3C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801EE540;
    }
    goto skip_0;
    // 0x801EE3C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801EE3CC: jal         0x801C0B8C
    // 0x801EE3D0: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE3D0: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    after_0:
    // 0x801EE3D4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EE3D8: beq         $v0, $zero, L_801EE4A4
    if (ctx->r2 == 0) {
        // 0x801EE3DC: addiu       $v1, $v1, -0x54EC
        ctx->r3 = ADD32(ctx->r3, -0X54EC);
            goto L_801EE4A4;
    }
    // 0x801EE3DC: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EE3E0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EE3E4: lui         $at, 0xC33E
    ctx->r1 = S32(0XC33E << 16);
    // 0x801EE3E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE3EC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE3F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EE3F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE3F8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE3FC: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EE400: ori         $a1, $a1, 0x13
    ctx->r5 = ctx->r5 | 0X13;
    // 0x801EE404: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE408: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EE40C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE410: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE414: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801EE418: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EE41C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EE420: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801EE424: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EE428: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE42C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE430: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE434: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE438: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801EE43C: addiu       $t3, $zero, 0x1182
    ctx->r11 = ADD32(0, 0X1182);
    // 0x801EE440: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801EE444: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801EE448: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EE44C: lwc1        $f8, -0x3720($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3720);
    // 0x801EE450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EE454: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE458: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EE45C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE460: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE464: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE468: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EE46C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EE470: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801EE474: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EE478: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE47C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE480: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE484: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE488: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EE48C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EE490: sh          $t3, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r11;
    // 0x801EE494: jal         0x801CC470
    // 0x801EE498: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EE498: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EE49C: b           L_801EE540
    // 0x801EE4A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EE540;
    // 0x801EE4A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EE4A4:
    // 0x801EE4A4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EE4A8: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EE4AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EE4B0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE4B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801EE4B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE4BC: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801EE4C0: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE4C4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE4C8: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EE4CC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EE4D0: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x801EE4D4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EE4D8: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x801EE4DC: lw          $t0, 0x8($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X8);
    // 0x801EE4E0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE4E4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE4E8: lw          $t4, 0x24($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X24);
    // 0x801EE4EC: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x801EE4F0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801EE4F4: swc1        $f18, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f18.u32l;
    // 0x801EE4F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EE4FC: lwc1        $f4, -0x371C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X371C);
    // 0x801EE500: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE504: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE508: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE50C: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x801EE510: lw          $t0, 0x24($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X24);
    // 0x801EE514: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EE518: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x801EE51C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EE520: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE524: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE528: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE52C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE530: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EE534: lw          $t3, 0x2C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X2C);
    // 0x801EE538: sh          $t2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r10;
    // 0x801EE53C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EE540:
    // 0x801EE540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE548: jr          $ra
    // 0x801EE54C: nop

    return;
    // 0x801EE54C: nop

;}
