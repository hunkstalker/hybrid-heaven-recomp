#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80147598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147598: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014759C: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x801475A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801475A4: beq         $v0, $at, L_801475B4
    if (ctx->r2 == ctx->r1) {
        // 0x801475A8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_801475B4;
    }
    // 0x801475A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801475AC: bnel        $v0, $at, L_801475C0
    if (ctx->r2 != ctx->r1) {
        // 0x801475B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801475C0;
    }
    goto skip_0;
    // 0x801475B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_801475B4:
    // 0x801475B4: jr          $ra
    // 0x801475B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801475B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801475BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801475C0:
    // 0x801475C0: jr          $ra
    // 0x801475C4: nop

    return;
    // 0x801475C4: nop

;}
RECOMP_FUNC void M7_FUN_801475c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801475C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801475CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801475D0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801475D4: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801475D8: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801475DC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801475E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801475E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801475E8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801475EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801475F0: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801475F4: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801475F8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x801475FC: nop

    // 0x80147600: bc1tl       L_801476B8
    if (c1cs) {
        // 0x80147604: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_801476B8;
    }
    goto skip_0;
    // 0x80147604: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80147608: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014760C: nop

    // 0x80147610: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x80147614: nop

    // 0x80147618: bc1tl       L_801476B8
    if (c1cs) {
        // 0x8014761C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_801476B8;
    }
    goto skip_1;
    // 0x8014761C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80147620: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80147624: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80147628: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x8014762C: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80147630: nop

    // 0x80147634: bc1fl       L_80147670
    if (!c1cs) {
        // 0x80147638: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_80147670;
    }
    goto skip_2;
    // 0x80147638: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_2:
    // 0x8014763C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80147640: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80147644: jal         0x8002FC20
    // 0x80147648: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80147648: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8014764C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80147650: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80147654: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80147658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014765C: c.eq.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d == ctx->f6.d;
    // 0x80147660: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80147664: bc1tl       L_8014768C
    if (c1cs) {
        // 0x80147668: lwc1        $f10, 0x0($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8014768C;
    }
    goto skip_3;
    // 0x80147668: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x8014766C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80147670:
    // 0x80147670: jal         0x8002FC20
    // 0x80147674: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x80147674: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80147678: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014767C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80147680: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80147684: div.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80147688: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
L_8014768C:
    // 0x8014768C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80147690: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80147694: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80147698: nop

    // 0x8014769C: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x801476A0: nop

    // 0x801476A4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x801476A8: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x801476AC: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x801476B0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x801476B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_801476B8:
    // 0x801476B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801476BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801476C0: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    // 0x801476C4: nop

    // 0x801476C8: bc1f        L_801476D8
    if (!c1cs) {
        // 0x801476CC: nop
    
            goto L_801476D8;
    }
    // 0x801476CC: nop

    // 0x801476D0: b           L_801476D8
    // 0x801476D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801476D8;
    // 0x801476D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801476D8:
    // 0x801476D8: jr          $ra
    // 0x801476DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801476DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801476e0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801476e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801476E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801476E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801476E8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801476EC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801476F0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801476F4: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801476F8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801476FC: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80147700: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80147704: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80147708: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8014770C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80147710: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80147714: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80147718: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8014771C: jal         0x8002FC20
    // 0x80147720: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80147720: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80147724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014772C: jr          $ra
    // 0x80147730: nop

    return;
    // 0x80147730: nop

;}
RECOMP_FUNC void M7_FUN_80147734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147734: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80147738: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8014773C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80147740: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80147744: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80147748: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8014774C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80147750: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x80147754: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80147758: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8014775C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80147760: jr          $ra
    // 0x80147764: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x80147764: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147768(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147768: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014776c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014776c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014776C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80147778: jal         0x801475C8
    // 0x8014777C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x801475C8)(rdram, ctx);
        goto after_0;
    // 0x8014777C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80147780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80147784: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80147788: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8014778C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80147790: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80147794: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80147798: nop

    // 0x8014779C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801477A0: nop

    // 0x801477A4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801477A8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x801477AC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x801477B0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x801477B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801477B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801477BC: jr          $ra
    // 0x801477C0: nop

    return;
    // 0x801477C0: nop

;}
RECOMP_FUNC void M7_FUN_801477c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801477C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801477C8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801477CC: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801477D0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801477D4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801477D8: nop

    // 0x801477DC: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801477E0: nop

    // 0x801477E4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801477E8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x801477EC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x801477F0: jr          $ra
    // 0x801477F4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x801477F4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801477f8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801477f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801477F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801477FC: bne         $a0, $zero, L_80147820
    if (ctx->r4 != 0) {
        // 0x80147800: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_80147820;
    }
    // 0x80147800: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80147808: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8014780C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80147810:
    // 0x80147810: bnel        $v0, $v1, L_80147810
    if (ctx->r2 != ctx->r3) {
        // 0x80147814: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80147810;
    }
    goto skip_0;
    // 0x80147814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_80147818:
    // 0x80147818: b           L_80147818
    pause_self(rdram);
    // 0x8014781C: nop

L_80147820:
    // 0x80147820: jr          $ra
    // 0x80147824: nop

    return;
    // 0x80147824: nop

;}
RECOMP_FUNC void M7_FUN_80147828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147828: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8014782C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80147830: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80147834: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80147838: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8014783C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80147840: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x80147844: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80147848: beq         $a0, $zero, L_801478C4
    if (ctx->r4 == 0) {
        // 0x8014784C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801478C4;
    }
    // 0x8014784C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80147850: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x80147854: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80147858: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8014785C: beq         $v1, $zero, L_801478BC
    if (ctx->r3 == 0) {
        // 0x80147860: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_801478BC;
    }
    // 0x80147860: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80147864: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80147868: addiu       $a2, $a2, 0x16B0
    ctx->r6 = ADD32(ctx->r6, 0X16B0);
    // 0x8014786C: addiu       $t1, $t1, -0x4898
    ctx->r9 = ADD32(ctx->r9, -0X4898);
    // 0x80147870: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
L_80147874:
    // 0x80147874: bne         $a0, $v0, L_80147894
    if (ctx->r4 != ctx->r2) {
        // 0x80147878: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80147894;
    }
    // 0x80147878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014787C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80147880: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80147884: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80147888: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x8014788C: or          $t9, $t8, $a3
    ctx->r25 = ctx->r24 | ctx->r7;
    // 0x80147890: sw          $t9, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r25;
L_80147894:
    // 0x80147894: bnel        $t0, $a1, L_801478AC
    if (ctx->r8 != ctx->r5) {
        // 0x80147898: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_801478AC;
    }
    goto skip_0;
    // 0x80147898: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x8014789C: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    // 0x801478A0: or          $t3, $t1, $a3
    ctx->r11 = ctx->r9 | ctx->r7;
    // 0x801478A4: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x801478A8: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_801478AC:
    // 0x801478AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801478B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801478B4: bne         $v1, $zero, L_80147874
    if (ctx->r3 != 0) {
        // 0x801478B8: nop
    
            goto L_80147874;
    }
    // 0x801478B8: nop

L_801478BC:
    // 0x801478BC: b           L_801478C8
    // 0x801478C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801478C8;
    // 0x801478C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801478C4:
    // 0x801478C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801478C8:
    // 0x801478C8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x801478CC: jr          $ra
    // 0x801478D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801478D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801478d4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801478d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801478D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801478D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801478DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801478E0: beq         $a0, $zero, L_80147910
    if (ctx->r4 == 0) {
        // 0x801478E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80147910;
    }
    // 0x801478E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801478E8: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801478EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801478F0: lhu         $a3, 0xC($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0XC);
    // 0x801478F4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x801478F8: jal         0x80147828
    // 0x801478FC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x80147828)(rdram, ctx);
        goto after_0;
    // 0x801478FC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80147900: beql        $v0, $zero, L_80147914
    if (ctx->r2 == 0) {
        // 0x80147904: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80147914;
    }
    goto skip_0;
    // 0x80147904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80147908: b           L_80147914
    // 0x8014790C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147914;
    // 0x8014790C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80147910:
    // 0x80147910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147914:
    // 0x80147914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014791C: jr          $ra
    // 0x80147920: nop

    return;
    // 0x80147920: nop

;}
RECOMP_FUNC void M7_FUN_80147924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147924: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147928: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8014792C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80147930: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80147934: beq         $a0, $zero, L_8014799C
    if (ctx->r4 == 0) {
            // 0x80147938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x8014799C)(rdram, ctx);
    return;
    }
    // 0x80147938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014793C: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x80147940: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80147944: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80147948: beq         $v1, $zero, L_80147994
    if (ctx->r3 == 0) {
        // 0x8014794C: lui         $t0, 0x4000
        ctx->r8 = S32(0X4000 << 16);
            goto L_80147994;
    }
    // 0x8014794C: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x80147950: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80147954: addiu       $a2, $a2, -0x4898
    ctx->r6 = ADD32(ctx->r6, -0X4898);
L_80147958:
    // 0x80147958: bne         $a0, $v0, L_8014796C
    if (ctx->r4 != ctx->r2) {
        // 0x8014795C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8014796C;
    }
    // 0x8014795C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80147960: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x80147964: or          $t6, $a2, $t0
    ctx->r14 = ctx->r6 | ctx->r8;
    // 0x80147968: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_8014796C:
    // 0x8014796C: bnel        $a3, $a1, L_80147984
    if (ctx->r7 != ctx->r5) {
        // 0x80147970: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_80147984;
    }
    goto skip_0;
    // 0x80147970: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x80147974: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x80147978: or          $t8, $a2, $t0
    ctx->r24 = ctx->r6 | ctx->r8;
    // 0x8014797C: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x80147980: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_80147984:
    // 0x80147984: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80147988: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8014798C: bne         $v1, $zero, L_80147958
    if (ctx->r3 != 0) {
        // 0x80147990: nop
    
            goto L_80147958;
    }
    // 0x80147990: nop

L_80147994:
    // 0x80147994: jr          $ra
    // 0x80147998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80147998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014799c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014799c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014799C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801479A0: jr          $ra
    // 0x801479A4: nop

    return;
    // 0x801479A4: nop

;}
RECOMP_FUNC void M7_FUN_801479a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801479A8: beq         $a0, $zero, L_801479D8
    if (ctx->r4 == 0) {
            // 0x801479AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x801479D8)(rdram, ctx);
    return;
    }
    // 0x801479AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801479B0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x801479B4: beq         $v0, $zero, L_801479D0
    if (ctx->r2 == 0) {
        // 0x801479B8: nop
    
            goto L_801479D0;
    }
    // 0x801479B8: nop

    // 0x801479BC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
L_801479C0:
    // 0x801479C0: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x801479C4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801479C8: bnel        $v0, $zero, L_801479C0
    if (ctx->r2 != 0) {
        // 0x801479CC: lw          $t6, 0x2C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X2C);
            goto L_801479C0;
    }
    goto skip_0;
    // 0x801479CC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    skip_0:
L_801479D0:
    // 0x801479D0: jr          $ra
    // 0x801479D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801479D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801479d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801479d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801479D8: jr          $ra
    // 0x801479DC: nop

    return;
    // 0x801479DC: nop

;}
RECOMP_FUNC void M7_FUN_801479e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801479E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801479E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801479E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801479EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801479F0: addiu       $t6, $t6, 0x1A70
    ctx->r14 = ADD32(ctx->r14, 0X1A70);
    // 0x801479F4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801479F8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801479FC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80147A00: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80147A04: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80147A08: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80147A0C: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x80147A10: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80147A14: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80147A18: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80147A1C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x80147A20: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80147A24: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80147A28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80147A2C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80147A30: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80147A34: jal         0x8012C4D0
    // 0x80147A38: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x80147A38: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x80147A3C: beq         $v0, $zero, L_80147A58
    if (ctx->r2 == 0) {
        // 0x80147A40: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_80147A58;
    }
    // 0x80147A40: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80147A44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80147A48: sw          $t0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r8;
    // 0x80147A4C: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x80147A50: b           L_80147A5C
    // 0x80147A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147A5C;
    // 0x80147A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80147A58:
    // 0x80147A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147A5C:
    // 0x80147A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80147A60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80147A64: jr          $ra
    // 0x80147A68: nop

    return;
    // 0x80147A68: nop

;}
RECOMP_FUNC void M7_FUN_80147a6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147A74: jal         0x800058B8
    // 0x80147A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800058B8)(rdram, ctx);
        goto after_0;
    // 0x80147A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80147A7C: beq         $v0, $zero, L_80147A94
    if (ctx->r2 == 0) {
        // 0x80147A80: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80147A94;
    }
    // 0x80147A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80147A84: jal         0x80005700
    // 0x80147A88: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80147A88: nop

    after_1:
    // 0x80147A8C: b           L_80147A98
    // 0x80147A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147A98;
    // 0x80147A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80147A94:
    // 0x80147A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147A98:
    // 0x80147A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147AA0: jr          $ra
    // 0x80147AA4: nop

    return;
    // 0x80147AA4: nop

;}
RECOMP_FUNC void M7_FUN_80147aa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147AA8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80147AAC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80147AB0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80147AB4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80147AB8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80147ABC: addiu       $t7, $t7, 0x1590
    ctx->r15 = ADD32(ctx->r15, 0X1590);
    // 0x80147AC0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80147AC4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80147AC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147ACC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147AD0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80147AD4: sb          $a1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r5;
    // 0x80147AD8: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80147ADC: sb          $a2, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r6;
    // 0x80147AE0: sb          $a2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r6;
    // 0x80147AE4: sb          $a3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r7;
    // 0x80147AE8: jr          $ra
    // 0x80147AEC: sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    return;
    // 0x80147AEC: sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147af0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147af0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147AF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80147AF4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80147AF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80147AFC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80147B00: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80147B04: addiu       $t7, $t7, 0x1590
    ctx->r15 = ADD32(ctx->r15, 0X1590);
    // 0x80147B08: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80147B0C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80147B10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147B14: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147B18: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80147B1C: sb          $a1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r5;
    // 0x80147B20: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x80147B24: sb          $a2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r6;
    // 0x80147B28: sb          $a2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r6;
    // 0x80147B2C: sb          $a3, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r7;
    // 0x80147B30: jr          $ra
    // 0x80147B34: sb          $a3, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r7;
    return;
    // 0x80147B34: sb          $a3, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r7;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147b38(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147b38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147B38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80147B3C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80147B40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80147B44: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80147B48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80147B4C: addiu       $t7, $t7, 0x1590
    ctx->r15 = ADD32(ctx->r15, 0X1590);
    // 0x80147B50: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80147B54: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80147B58: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80147B5C: lbu         $t1, 0x5($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X5);
    // 0x80147B60: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x80147B64: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147B68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147B6C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80147B70: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80147B74: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80147B78: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80147B7C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80147B80: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80147B84: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80147B88: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x80147B8C: addu        $t3, $t1, $a2
    ctx->r11 = ADD32(ctx->r9, ctx->r6);
    // 0x80147B90: addu        $t6, $t4, $a3
    ctx->r14 = ADD32(ctx->r12, ctx->r7);
    // 0x80147B94: sb          $t0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r8;
    // 0x80147B98: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80147B9C: sb          $t3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r11;
    // 0x80147BA0: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    // 0x80147BA4: sb          $t6, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r14;
    // 0x80147BA8: jr          $ra
    // 0x80147BAC: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    return;
    // 0x80147BAC: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147bb0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147bb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147BB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80147BB4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80147BB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80147BBC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80147BC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80147BC4: addiu       $t7, $t7, 0x1590
    ctx->r15 = ADD32(ctx->r15, 0X1590);
    // 0x80147BC8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80147BCC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80147BD0: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x80147BD4: lbu         $t1, 0xD($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XD);
    // 0x80147BD8: lbu         $t4, 0xE($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XE);
    // 0x80147BDC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147BE0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147BE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80147BE8: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80147BEC: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80147BF0: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80147BF4: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80147BF8: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80147BFC: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80147C00: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x80147C04: addu        $t3, $t1, $a2
    ctx->r11 = ADD32(ctx->r9, ctx->r6);
    // 0x80147C08: addu        $t6, $t4, $a3
    ctx->r14 = ADD32(ctx->r12, ctx->r7);
    // 0x80147C0C: sb          $t0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r8;
    // 0x80147C10: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x80147C14: sb          $t3, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r11;
    // 0x80147C18: sb          $t3, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r11;
    // 0x80147C1C: sb          $t6, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r14;
    // 0x80147C20: jr          $ra
    // 0x80147C24: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    return;
    // 0x80147C24: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147c28(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147c28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147C28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80147C2C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80147C30: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80147C34: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80147C38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80147C3C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147C40: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147C44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80147C48: addiu       $t7, $t7, 0x1590
    ctx->r15 = ADD32(ctx->r15, 0X1590);
    // 0x80147C4C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80147C50: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80147C54: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80147C58: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80147C5C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80147C60: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80147C64: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80147C68: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80147C6C: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x80147C70: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    // 0x80147C74: jr          $ra
    // 0x80147C78: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    return;
    // 0x80147C78: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147c7c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147c7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147C7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80147C80: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80147C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80147C88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80147C8C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80147C90: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80147C94: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80147C98: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80147C9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80147CA0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80147CA4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80147CA8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80147CAC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80147CB0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80147CB4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80147CB8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80147CBC: lw          $t9, 0x90($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X90);
    // 0x80147CC0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80147CC4: jal         0x80005E44
    // 0x80147CC8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80147CC8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x80147CCC: jal         0x80006214
    // 0x80147CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80147CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80147CD4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80147CD8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80147CDC: addiu       $t1, $t1, 0x15F0
    ctx->r9 = ADD32(ctx->r9, 0X15F0);
    // 0x80147CE0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80147CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147CE8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80147CEC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80147CF0: sw          $t1, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r9;
    // 0x80147CF4: lw          $t5, 0x90($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X90);
    // 0x80147CF8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80147CFC: jal         0x80005E44
    // 0x80147D00: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x80147D00: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_2:
    // 0x80147D04: jal         0x80006214
    // 0x80147D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80147D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80147D0C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80147D10: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80147D14: addiu       $t7, $t7, -0x4898
    ctx->r15 = ADD32(ctx->r15, -0X4898);
    // 0x80147D18: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80147D1C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80147D20: addiu       $a1, $a1, 0x7D48
    ctx->r5 = ADD32(ctx->r5, 0X7D48);
    // 0x80147D24: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80147D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147D2C: jal         0x800058DC
    // 0x80147D30: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80147D30: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
    after_4:
    // 0x80147D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80147D38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80147D3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80147D40: jr          $ra
    // 0x80147D44: nop

    return;
    // 0x80147D44: nop

;}
RECOMP_FUNC void M7_FUN_80147d48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147D48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80147D4C: jr          $ra
    // 0x80147D50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80147D50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147d54(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147d54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147D54: nop

    // 0x80147D58: nop

    // 0x80147D5C: nop

;}
RECOMP_FUNC void M7_FUN_80147d60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147D60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80147D64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80147D68: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x80147D6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80147D70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80147D74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80147D78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80147D7C: blez        $s1, L_80147DB4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80147D80: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80147DB4;
    }
    // 0x80147D80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80147D84: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x80147D88: addiu       $s2, $s2, -0x660
    ctx->r18 = ADD32(ctx->r18, -0X660);
    // 0x80147D8C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80147D90:
    // 0x80147D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80147D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80147D98: jal         0x8001B204
    // 0x80147D9C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80147D9C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_0:
    // 0x80147DA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80147DA4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80147DA8: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80147DAC: bnel        $at, $zero, L_80147D90
    if (ctx->r1 != 0) {
        // 0x80147DB0: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80147D90;
    }
    goto skip_0;
    // 0x80147DB0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
L_80147DB4:
    // 0x80147DB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80147DB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80147DBC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80147DC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80147DC4: jr          $ra
    // 0x80147DC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80147DC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147dcc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147dcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147DCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80147DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80147DD4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80147DD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80147DDC: slti        $at, $a0, 0x1C
    ctx->r1 = SIGNED(ctx->r4) < 0X1C ? 1 : 0;
    // 0x80147DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80147DE4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80147DE8: beq         $at, $zero, L_80147E20
    if (ctx->r1 == 0) {
        // 0x80147DEC: andi        $s0, $a0, 0xFF
        ctx->r16 = ctx->r4 & 0XFF;
            goto L_80147E20;
    }
    // 0x80147DEC: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x80147DF0: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80147DF4: addiu       $s1, $s1, -0x65C
    ctx->r17 = ADD32(ctx->r17, -0X65C);
    // 0x80147DF8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80147DFC:
    // 0x80147DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80147E00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80147E04: jal         0x8001B204
    // 0x80147E08: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80147E08: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
    // 0x80147E0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80147E10: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80147E14: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
    // 0x80147E18: bnel        $at, $zero, L_80147DFC
    if (ctx->r1 != 0) {
        // 0x80147E1C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80147DFC;
    }
    goto skip_0;
    // 0x80147E1C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
L_80147E20:
    // 0x80147E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80147E24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80147E28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80147E2C: jr          $ra
    // 0x80147E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80147E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147e34(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147e34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147E34: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80147E38: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80147E3C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80147E40: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80147E44: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80147E48: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80147E4C: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x80147E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147E54: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80147E58: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80147E5C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80147E60: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80147E64: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80147E68: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80147E6C: lbu         $t2, 0xA3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XA3);
    // 0x80147E70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80147E74: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80147E78: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80147E7C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x80147E80: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x80147E84: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    // 0x80147E88: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80147E8C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80147E90: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80147E94: bne         $t3, $t2, L_80147EA8
    if (ctx->r11 != ctx->r10) {
        // 0x80147E98: swc1        $f6, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
            goto L_80147EA8;
    }
    // 0x80147E98: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80147E9C: addiu       $t4, $zero, 0x902
    ctx->r12 = ADD32(0, 0X902);
    // 0x80147EA0: b           L_80147EB0
    // 0x80147EA4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_80147EB0;
    // 0x80147EA4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_80147EA8:
    // 0x80147EA8: addiu       $t5, $zero, 0x102
    ctx->r13 = ADD32(0, 0X102);
    // 0x80147EAC: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
L_80147EB0:
    // 0x80147EB0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80147EB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80147EB8: ori         $t6, $t6, 0x900
    ctx->r14 = ctx->r14 | 0X900;
    // 0x80147EBC: sh          $t0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r8;
    // 0x80147EC0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80147EC4: sh          $t1, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r9;
    // 0x80147EC8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80147ECC: beq         $v1, $t2, L_80147ED8
    if (ctx->r3 == ctx->r10) {
        // 0x80147ED0: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_80147ED8;
    }
    // 0x80147ED0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80147ED4: bne         $t3, $t2, L_80147F0C
    if (ctx->r11 != ctx->r10) {
        // 0x80147ED8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80147F0C;
    }
L_80147ED8:
    // 0x80147ED8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80147EDC: lwc1        $f0, -0x4AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4AC);
    // 0x80147EE0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80147EE4: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x80147EE8: addiu       $t9, $zero, 0x198
    ctx->r25 = ADD32(0, 0X198);
    // 0x80147EEC: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x80147EF0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80147EF4: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x80147EF8: sh          $t9, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r25;
    // 0x80147EFC: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80147F00: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80147F04: b           L_80147F80
    // 0x80147F08: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
        goto L_80147F80;
    // 0x80147F08: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_80147F0C:
    // 0x80147F0C: bne         $t2, $zero, L_80147F80
    if (ctx->r10 != 0) {
        // 0x80147F10: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80147F80;
    }
    // 0x80147F10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80147F14: lwc1        $f0, -0x4A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4A8);
    // 0x80147F18: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80147F1C: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x80147F20: sh          $t4, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r12;
    // 0x80147F24: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80147F28: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80147F2C: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80147F30: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x80147F34: lb          $v0, 0x91($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X91);
    // 0x80147F38: addiu       $t6, $zero, 0xAAA
    ctx->r14 = ADD32(0, 0XAAA);
    // 0x80147F3C: addiu       $t9, $zero, 0x266
    ctx->r25 = ADD32(0, 0X266);
    // 0x80147F40: bne         $v1, $v0, L_80147F50
    if (ctx->r3 != ctx->r2) {
        // 0x80147F44: nop
    
            goto L_80147F50;
    }
    // 0x80147F44: nop

    // 0x80147F48: b           L_80147F7C
    // 0x80147F4C: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
        goto L_80147F7C;
    // 0x80147F4C: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
L_80147F50:
    // 0x80147F50: bne         $t3, $v0, L_80147F78
    if (ctx->r11 != ctx->r2) {
        // 0x80147F54: addiu       $t8, $zero, 0x400
        ctx->r24 = ADD32(0, 0X400);
            goto L_80147F78;
    }
    // 0x80147F54: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80147F58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80147F5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80147F60: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80147F64: addiu       $t7, $zero, 0x471
    ctx->r15 = ADD32(0, 0X471);
    // 0x80147F68: sh          $t7, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r15;
    // 0x80147F6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80147F70: b           L_80147F7C
    // 0x80147F74: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
        goto L_80147F7C;
    // 0x80147F74: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_80147F78:
    // 0x80147F78: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
L_80147F7C:
    // 0x80147F7C: sh          $t9, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r25;
L_80147F80:
    // 0x80147F80: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80147F84: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
    // 0x80147F88: sh          $t4, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r12;
    // 0x80147F8C: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80147F90: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80147F94: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80147F98: jal         0x80005E44
    // 0x80147F9C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80147F9C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_0:
    // 0x80147FA0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80147FA4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80147FA8: bne         $v0, $zero, L_80147FC8
    if (ctx->r2 != 0) {
        // 0x80147FAC: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80147FC8;
    }
    // 0x80147FAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80147FB0: jal         0x80005700
    // 0x80147FB4: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80147FB4: nop

    after_1:
    // 0x80147FB8: jal         0x801170DC
    // 0x80147FBC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_2;
    // 0x80147FBC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x80147FC0: b           L_80148034
    // 0x80147FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80148034;
    // 0x80147FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80147FC8:
    // 0x80147FC8: jal         0x80006214
    // 0x80147FCC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80147FCC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_3:
    // 0x80147FD0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80147FD4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80147FD8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80147FDC: bne         $t3, $t2, L_80148010
    if (ctx->r11 != ctx->r10) {
        // 0x80147FE0: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80148010;
    }
    // 0x80147FE0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80147FE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80147FE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80147FEC: addiu       $t6, $t6, 0x1CA8
    ctx->r14 = ADD32(ctx->r14, 0X1CA8);
    // 0x80147FF0: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x80147FF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80147FF8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80147FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80148000: jal         0x801451C0
    // 0x80148004: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_4;
    // 0x80148004: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    after_4:
    // 0x80148008: b           L_80148034
    // 0x8014800C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80148034;
    // 0x8014800C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148010:
    // 0x80148010: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80148014: addiu       $t9, $t9, 0x1C40
    ctx->r25 = ADD32(ctx->r25, 0X1C40);
    // 0x80148018: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8014801C: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x80148020: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80148024: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80148028: jal         0x801451C0
    // 0x8014802C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_5;
    // 0x8014802C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80148030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148034:
    // 0x80148034: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80148038: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8014803C: jr          $ra
    // 0x80148040: nop

    return;
    // 0x80148040: nop

;}
RECOMP_FUNC void M7_FUN_80148044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148044: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80148048: lhu         $t6, -0x43E4($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X43E4);
    // 0x8014804C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80148050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80148054: bne         $t6, $at, L_80148064
    if (ctx->r14 != ctx->r1) {
            // 0x80148058: nop

    LOOKUP_FUNC(0x80148064)(rdram, ctx);
    return;
    }
    // 0x80148058: nop

    // 0x8014805C: jr          $ra
    // 0x80148060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80148060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148064(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148064: jr          $ra
    // 0x80148068: nop

    return;
    // 0x80148068: nop

;}
RECOMP_FUNC void M7_FUN_8014806c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014806C: jr          $ra
    // 0x80148070: nop

    return;
    // 0x80148070: nop

;}
RECOMP_FUNC void M7_FUN_80148074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148078: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8014807C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80148080: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80148084: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80148088: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8014808C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80148090: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80148094: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80148098: lw          $s2, -0x12E4($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X12E4);
    // 0x8014809C: lw          $s1, -0x12E8($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X12E8);
    // 0x801480A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801480A4:
    // 0x801480A4: lbu         $t6, 0xA2($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0XA2);
    // 0x801480A8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x801480AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801480B0: bne         $s0, $t6, L_801480D8
    if (ctx->r16 != ctx->r14) {
        // 0x801480B4: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_801480D8;
    }
    // 0x801480B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801480B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801480BC: jal         0x80145310
    // 0x801480C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x801480C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x801480C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801480C8: jal         0x801451C0
    // 0x801480CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_1;
    // 0x801480CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801480D0: b           L_801480F0
    // 0x801480D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_801480F0;
    // 0x801480D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801480D8:
    // 0x801480D8: jal         0x80145310
    // 0x801480DC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x801480DC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_2:
    // 0x801480E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801480E4: jal         0x801451C0
    // 0x801480E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_3;
    // 0x801480E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x801480EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801480F0:
    // 0x801480F0: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x801480F4: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x801480F8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801480FC: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x80148100: bne         $at, $zero, L_801480A4
    if (ctx->r1 != 0) {
        // 0x80148104: lw          $s2, 0x10($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X10);
            goto L_801480A4;
    }
    // 0x80148104: lw          $s2, 0x10($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X10);
    // 0x80148108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014810C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80148110: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80148114: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80148118: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8014811C: jr          $ra
    // 0x80148120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80148120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148124(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148124: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80148128: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8014812C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80148130: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80148134: jr          $ra
    // 0x80148138: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x80148138: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014813c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014813c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014813C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80148140: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80148144: lbu         $v1, 0x4F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4F);
    // 0x80148148: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8014814C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80148150: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80148154: mfhi        $t9
    ctx->r25 = hi;
    // 0x80148158: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8014815C: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x80148160: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80148164: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80148168: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8014816C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80148170: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80148174: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80148178: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8014817C: addiu       $t4, $zero, 0x21C
    ctx->r12 = ADD32(0, 0X21C);
    // 0x80148180: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80148184: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80148188: sb          $zero, 0x47($sp)
    MEM_B(0X47, ctx->r29) = 0;
    // 0x8014818C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80148190: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80148194: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80148198: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8014819C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801481A0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801481A4: lh          $a3, 0x52($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X52);
    // 0x801481A8: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x801481AC: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x801481B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801481B4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x801481B8: jal         0x80146208
    // 0x801481BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x801481BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801481C0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x801481C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801481C8: lh          $a3, 0x52($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X52);
    // 0x801481CC: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x801481D0: mflo        $t0
    ctx->r8 = lo;
    // 0x801481D4: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x801481D8: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x801481DC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801481E0: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x801481E4: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801481E8: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x801481EC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801481F0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x801481F4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801481F8: addiu       $t2, $zero, 0x21C
    ctx->r10 = ADD32(0, 0X21C);
    // 0x801481FC: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80148200: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80148204: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80148208: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8014820C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80148210: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80148214: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80148218: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8014821C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80148220: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80148224: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x80148228: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8014822C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80148230: jal         0x80146208
    // 0x80148234: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x80148234: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80148238: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8014823C: bnel        $t0, $zero, L_80148264
    if (ctx->r8 != 0) {
        // 0x80148240: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80148264;
    }
    goto skip_0;
    // 0x80148240: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80148244: jal         0x80006214
    // 0x80148248: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80148248: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8014824C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80148250: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80148254: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80148258: lw          $t5, -0x257C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X257C);
    // 0x8014825C: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    // 0x80148260: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80148264:
    // 0x80148264: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80148268: jr          $ra
    // 0x8014826C: nop

    return;
    // 0x8014826C: nop

;}
RECOMP_FUNC void M7_FUN_80148270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148270: lb          $t6, 0x91($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X91);
    // 0x80148274: lb          $t8, 0x90($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X90);
    // 0x80148278: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8014827C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80148280: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80148284: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80148288: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8014828C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80148290: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80148294: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80148298: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8014829C: lbu         $t1, 0x1ABD($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1ABD);
    // 0x801482A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801482A4: bne         $t1, $zero, L_801482B4
    if (ctx->r9 != 0) {
            // 0x801482A8: nop

    LOOKUP_FUNC(0x801482B4)(rdram, ctx);
    return;
    }
    // 0x801482A8: nop

    // 0x801482AC: jr          $ra
    // 0x801482B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801482B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801482b4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801482b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801482B4: jr          $ra
    // 0x801482B8: nop

    return;
    // 0x801482B8: nop

;}
RECOMP_FUNC void M7_FUN_801482bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801482BC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801482C0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801482C4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801482C8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801482CC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801482D0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801482D4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801482D8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801482DC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801482E0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801482E4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801482E8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801482EC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801482F0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801482F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801482F8: jal         0x80006214
    // 0x801482FC: lw          $s1, 0x98($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X98);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801482FC: lw          $s1, 0x98($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X98);
    after_0:
    // 0x80148300: addiu       $t6, $s1, -0x44C
    ctx->r14 = ADD32(ctx->r17, -0X44C);
    // 0x80148304: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x80148308: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8014830C: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x80148310: addiu       $s5, $s5, 0x1ABC
    ctx->r21 = ADD32(ctx->r21, 0X1ABC);
    // 0x80148314: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80148318: sb          $zero, 0x7F($sp)
    MEM_B(0X7F, ctx->r29) = 0;
    // 0x8014831C: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
L_80148320:
    // 0x80148320: lb          $v1, 0x7F($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X7F);
    // 0x80148324: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80148328: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8014832C: addiu       $t7, $v0, 0x3B
    ctx->r15 = ADD32(ctx->r2, 0X3B);
    // 0x80148330: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80148334: addiu       $fp, $v0, 0x41
    ctx->r30 = ADD32(ctx->r2, 0X41);
    // 0x80148338: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8014833C: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x80148340: andi        $s7, $v1, 0xFF
    ctx->r23 = ctx->r3 & 0XFF;
    // 0x80148344: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80148348: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
L_8014834C:
    // 0x8014834C: jal         0x80148124
    // 0x80148350: andi        $a1, $s7, 0xFF
    ctx->r5 = ctx->r23 & 0XFF;
    LOOKUP_FUNC(0x80148124)(rdram, ctx);
        goto after_1;
    // 0x80148350: andi        $a1, $s7, 0xFF
    ctx->r5 = ctx->r23 & 0XFF;
    after_1:
    // 0x80148354: sb          $v0, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r2;
    // 0x80148358: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8014835C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80148360: addiu       $t9, $t9, -0x4410
    ctx->r25 = ADD32(ctx->r25, -0X4410);
    // 0x80148364: bne         $t8, $t9, L_80148374
    if (ctx->r24 != ctx->r25) {
        // 0x80148368: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80148374;
    }
    // 0x80148368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014836C: b           L_80148374
    // 0x80148370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80148374;
    // 0x80148370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148374:
    // 0x80148374: lb          $t3, 0x90($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X90);
    // 0x80148378: lb          $t0, 0x91($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X91);
    // 0x8014837C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80148380: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80148384: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80148388: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8014838C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80148390: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x80148394: mflo        $t4
    ctx->r12 = lo;
    // 0x80148398: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8014839C: jal         0x8013D4A0
    // 0x801483A0: lbu         $a0, 0x1($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X1);
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_2;
    // 0x801483A0: lbu         $a0, 0x1($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X1);
    after_2:
    // 0x801483A4: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x801483A8: jal         0x80006214
    // 0x801483AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801483AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801483B0: lb          $t9, 0x90($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X90);
    // 0x801483B4: sll         $s2, $s3, 5
    ctx->r18 = S32(ctx->r19 << 5);
    // 0x801483B8: addiu       $t1, $s2, 0x2A
    ctx->r9 = ADD32(ctx->r18, 0X2A);
    // 0x801483BC: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801483C0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801483C4: lb          $t6, 0x91($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X91);
    // 0x801483C8: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x801483CC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801483D0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801483D4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801483D8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801483DC: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x801483E0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801483E4: mflo        $t0
    ctx->r8 = lo;
    // 0x801483E8: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x801483EC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801483F0: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x801483F4: lbu         $a2, 0x4($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X4);
    // 0x801483F8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801483FC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80148400: jal         0x80147E34
    // 0x80148404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80147E34)(rdram, ctx);
        goto after_4;
    // 0x80148404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80148408: addiu       $a2, $s2, 0x32
    ctx->r6 = ADD32(ctx->r18, 0X32);
    // 0x8014840C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80148410: sll         $a3, $fp, 16
    ctx->r7 = S32(ctx->r30 << 16);
    // 0x80148414: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80148418: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8014841C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148420: jal         0x8014813C
    // 0x80148424: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8014813C)(rdram, ctx);
        goto after_5;
    // 0x80148424: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_5:
    // 0x80148428: beql        $s1, $zero, L_80148444
    if (ctx->r17 == 0) {
        // 0x8014842C: lw          $t3, 0x84($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X84);
            goto L_80148444;
    }
    goto skip_0;
    // 0x8014842C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x80148430: jal         0x80148270
    // 0x80148434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148270)(rdram, ctx);
        goto after_6;
    // 0x80148434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80148438: bnel        $v0, $zero, L_8014847C
    if (ctx->r2 != 0) {
        // 0x8014843C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8014847C;
    }
    goto skip_1;
    // 0x8014843C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80148440: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
L_80148444:
    // 0x80148444: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80148448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014844C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80148450: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
L_80148454:
    // 0x80148454: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80148458: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8014845C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80148460: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80148464: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80148468: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8014846C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80148470: bne         $at, $zero, L_80148454
    if (ctx->r1 != 0) {
        // 0x80148474: sb          $zero, 0x22($t6)
        MEM_B(0X22, ctx->r14) = 0;
            goto L_80148454;
    }
    // 0x80148474: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x80148478: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8014847C:
    // 0x8014847C: sll         $s3, $s3, 24
    ctx->r19 = S32(ctx->r19 << 24);
    // 0x80148480: sra         $s3, $s3, 24
    ctx->r19 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80148484: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x80148488: bnel        $at, $zero, L_8014834C
    if (ctx->r1 != 0) {
        // 0x8014848C: andi        $a0, $s3, 0xFF
        ctx->r4 = ctx->r19 & 0XFF;
            goto L_8014834C;
    }
    goto skip_2;
    // 0x8014848C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    skip_2:
    // 0x80148490: lb          $t7, 0x7F($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X7F);
    // 0x80148494: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80148498: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x8014849C: sra         $t0, $t8, 24
    ctx->r8 = S32(SIGNED(ctx->r24) >> 24);
    // 0x801484A0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x801484A4: bne         $at, $zero, L_80148320
    if (ctx->r1 != 0) {
        // 0x801484A8: sb          $t9, 0x7F($sp)
        MEM_B(0X7F, ctx->r29) = ctx->r25;
            goto L_80148320;
    }
    // 0x801484A8: sb          $t9, 0x7F($sp)
    MEM_B(0X7F, ctx->r29) = ctx->r25;
    // 0x801484AC: lbu         $t3, 0x7D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7D);
    // 0x801484B0: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x801484B4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801484B8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x801484BC: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x801484C0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801484C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801484C8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801484CC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801484D0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801484D4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801484D8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801484DC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801484E0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801484E4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801484E8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801484EC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801484F0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801484F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801484F8: jr          $ra
    // 0x801484FC: sw          $t5, -0x12DC($at)
    MEM_W(-0X12DC, ctx->r1) = ctx->r13;
    return;
    // 0x801484FC: sw          $t5, -0x12DC($at)
    MEM_W(-0X12DC, ctx->r1) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148500(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148500: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80148504: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80148508: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8014850C: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x80148510: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80148514: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x80148518: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x8014851C: bne         $v0, $t7, L_8014852C
    if (ctx->r2 != ctx->r15) {
        // 0x80148520: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8014852C;
    }
    // 0x80148520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80148524: b           L_80148530
    // 0x80148528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80148530;
    // 0x80148528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014852C:
    // 0x8014852C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80148530:
    // 0x80148530: lb          $t8, 0x91($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X91);
    // 0x80148534: lb          $t0, 0x90($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X90);
    // 0x80148538: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014853C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80148540: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80148544: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80148548: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8014854C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80148550: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80148554: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80148558: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8014855C: lbu         $a0, 0x1ABD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1ABD);
    // 0x80148560: jal         0x8013D4A0
    // 0x80148564: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_0;
    // 0x80148564: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_0:
    // 0x80148568: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x8014856C: lb          $t5, 0x90($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X90);
    // 0x80148570: lb          $t3, 0x91($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X91);
    // 0x80148574: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80148578: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8014857C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80148580: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80148584: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80148588: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8014858C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80148590: lui         $at, 0x42B0
    ctx->r1 = S32(0X42B0 << 16);
    // 0x80148594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80148598: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014859C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x801485A0: addiu       $t8, $t8, 0x1ABC
    ctx->r24 = ADD32(ctx->r24, 0X1ABC);
    // 0x801485A4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801485A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801485AC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801485B0: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x801485B4: lbu         $a2, 0x4($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X4);
    // 0x801485B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801485BC: lui         $a3, 0x4361
    ctx->r7 = S32(0X4361 << 16);
    // 0x801485C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801485C4: jal         0x80147E34
    // 0x801485C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80147E34)(rdram, ctx);
        goto after_1;
    // 0x801485C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801485CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801485D0: sw          $v0, 0x1D5C($at)
    MEM_W(0X1D5C, ctx->r1) = ctx->r2;
    // 0x801485D4: lb          $t2, 0x90($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X90);
    // 0x801485D8: lb          $t9, 0x91($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X91);
    // 0x801485DC: lui         $at, 0x42B0
    ctx->r1 = S32(0X42B0 << 16);
    // 0x801485E0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801485E4: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x801485E8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801485EC: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x801485F0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801485F4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801485F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x801485FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80148600: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80148604: addiu       $t4, $t4, 0x1ABC
    ctx->r12 = ADD32(ctx->r12, 0X1ABC);
    // 0x80148608: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x8014860C: addu        $v1, $t5, $t4
    ctx->r3 = ADD32(ctx->r13, ctx->r12);
    // 0x80148610: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80148614: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80148618: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x8014861C: lbu         $a2, 0x5($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X5);
    // 0x80148620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148624: lui         $a3, 0x4361
    ctx->r7 = S32(0X4361 << 16);
    // 0x80148628: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8014862C: jal         0x80147E34
    // 0x80148630: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80147E34)(rdram, ctx);
        goto after_2;
    // 0x80148630: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80148634: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80148638: addiu       $a1, $a1, 0x1D60
    ctx->r5 = ADD32(ctx->r5, 0X1D60);
    // 0x8014863C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80148640: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80148644: lw          $t7, 0x1D5C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1D5C);
    // 0x80148648: lh          $v1, 0xA0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XA0);
    // 0x8014864C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80148650: sh          $v1, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r3;
    // 0x80148654: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80148658: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x8014865C: sh          $v1, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r3;
    // 0x80148660: lbu         $t2, 0x33($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X33);
    // 0x80148664: beq         $t2, $zero, L_80148680
    if (ctx->r10 == 0) {
        // 0x80148668: nop
    
            goto L_80148680;
    }
    // 0x80148668: nop

    // 0x8014866C: jal         0x80148270
    // 0x80148670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148270)(rdram, ctx);
        goto after_3;
    // 0x80148670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80148674: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80148678: bne         $v0, $zero, L_80148694
    if (ctx->r2 != 0) {
        // 0x8014867C: addiu       $a1, $a1, 0x1D60
        ctx->r5 = ADD32(ctx->r5, 0X1D60);
            goto L_80148694;
    }
    // 0x8014867C: addiu       $a1, $a1, 0x1D60
    ctx->r5 = ADD32(ctx->r5, 0X1D60);
L_80148680:
    // 0x80148680: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80148684: lw          $t1, 0x1D5C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1D5C);
    // 0x80148688: sb          $zero, 0x22($t1)
    MEM_B(0X22, ctx->r9) = 0;
    // 0x8014868C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80148690: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
L_80148694:
    // 0x80148694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80148698: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8014869C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801486A0: jr          $ra
    // 0x801486A4: nop

    return;
    // 0x801486A4: nop

;}
RECOMP_FUNC void M7_FUN_801486a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801486A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801486AC: lh          $t6, 0xA0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA0);
    // 0x801486B0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801486B4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801486B8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801486BC: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x801486C0: addiu       $a2, $a2, 0x1D5C
    ctx->r6 = ADD32(ctx->r6, 0X1D5C);
    // 0x801486C4: sh          $t7, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = ctx->r15;
    // 0x801486C8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801486CC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801486D0: addiu       $v1, $v1, 0x1D60
    ctx->r3 = ADD32(ctx->r3, 0X1D60);
    // 0x801486D4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801486D8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801486DC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801486E0: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801486E4: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801486E8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801486EC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801486F0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801486F4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801486F8: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801486FC: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x80148700: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80148704: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80148708: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014870C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80148710: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80148714: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x80148718: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8014871C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80148720: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80148724: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80148728: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x8014872C: sh          $t2, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r10;
    // 0x80148730: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80148734: lh          $v0, 0xA0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XA0);
    // 0x80148738: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014873C: sh          $v0, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r2;
    // 0x80148740: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80148744: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80148748: sh          $v0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r2;
    // 0x8014874C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80148750: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80148754: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80148758: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8014875C: lh          $t1, 0x14($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X14);
    // 0x80148760: jr          $ra
    // 0x80148764: sh          $t1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r9;
    return;
    // 0x80148764: sh          $t1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148768(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148768: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8014876C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80148770: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80148774: addiu       $a1, $a1, 0x1ABC
    ctx->r5 = ADD32(ctx->r5, 0X1ABC);
    // 0x80148778: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8014877C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80148780:
    // 0x80148780: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80148784: mflo        $t6
    ctx->r14 = lo;
    // 0x80148788: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8014878C: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80148790: beq         $v0, $t8, L_801487AC
    if (ctx->r2 == ctx->r24) {
        // 0x80148794: nop
    
            goto L_801487AC;
    }
    // 0x80148794: nop

    // 0x80148798: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8014879C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801487A0: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x801487A4: bne         $at, $zero, L_80148780
    if (ctx->r1 != 0) {
        // 0x801487A8: nop
    
            goto L_80148780;
    }
    // 0x801487A8: nop

L_801487AC:
    // 0x801487AC: jr          $ra
    // 0x801487B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801487B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801487b4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801487b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801487B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801487B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801487BC: slti        $at, $a0, 0x23
    ctx->r1 = SIGNED(ctx->r4) < 0X23 ? 1 : 0;
    // 0x801487C0: bne         $at, $zero, L_801487D0
    if (ctx->r1 != 0) {
        // 0x801487C4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801487D0;
    }
    // 0x801487C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801487C8: slti        $at, $a0, 0x26
    ctx->r1 = SIGNED(ctx->r4) < 0X26 ? 1 : 0;
    // 0x801487CC: bne         $at, $zero, L_801487DC
    if (ctx->r1 != 0) {
        // 0x801487D0: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_801487DC;
    }
L_801487D0:
    // 0x801487D0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801487D4: bnel        $v0, $at, L_801487E8
    if (ctx->r2 != ctx->r1) {
        // 0x801487D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801487E8;
    }
    goto skip_0;
    // 0x801487D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_801487DC:
    // 0x801487DC: jr          $ra
    // 0x801487E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801487E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801487E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801487E8:
    // 0x801487E8: jr          $ra
    // 0x801487EC: nop

    return;
    // 0x801487EC: nop

;}
RECOMP_FUNC void M7_FUN_801487f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801487F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801487F4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801487F8: slti        $at, $a0, 0x14
    ctx->r1 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x801487FC: bne         $at, $zero, L_80148818
    if (ctx->r1 != 0) {
            // 0x80148800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x80148818)(rdram, ctx);
    return;
    }
    // 0x80148800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80148804: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x80148808: beq         $at, $zero, L_80148818
    if (ctx->r1 == 0) {
            // 0x8014880C: nop

    LOOKUP_FUNC(0x80148818)(rdram, ctx);
    return;
    }
    // 0x8014880C: nop

    // 0x80148810: jr          $ra
    // 0x80148814: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80148814: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148818(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148818: jr          $ra
    // 0x8014881C: nop

    return;
    // 0x8014881C: nop

;}
RECOMP_FUNC void M7_FUN_80148820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148820: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148828: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x8014882C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80148830: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80148834: lw          $t7, 0x9C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C);
    // 0x80148838: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8014883C: lb          $t0, 0x90($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X90);
    // 0x80148840: lb          $t8, 0x91($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X91);
    // 0x80148844: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80148848: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8014884C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80148850: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80148854: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80148858: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8014885C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80148860: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80148864: lbu         $t3, 0x1ABD($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X1ABD);
    // 0x80148868: jal         0x80148044
    // 0x8014886C: sb          $t3, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80148044)(rdram, ctx);
        goto after_0;
    // 0x8014886C: sb          $t3, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r11;
    after_0:
    // 0x80148870: beq         $v0, $zero, L_80148880
    if (ctx->r2 == 0) {
        // 0x80148874: nop
    
            goto L_80148880;
    }
    // 0x80148874: nop

    // 0x80148878: b           L_80148948
    // 0x8014887C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80148948;
    // 0x8014887C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148880:
    // 0x80148880: jal         0x80126944
    // 0x80148884: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x80148884: nop

    after_1:
    // 0x80148888: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014888C: bne         $v0, $at, L_80148944
    if (ctx->r2 != ctx->r1) {
        // 0x80148890: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80148944;
    }
    // 0x80148890: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80148894: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80148898: lbu         $t4, 0x1030($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1030);
    // 0x8014889C: bnel        $t4, $zero, L_801488B0
    if (ctx->r12 != 0) {
        // 0x801488A0: lw          $a0, 0xEC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XEC);
            goto L_801488B0;
    }
    goto skip_0;
    // 0x801488A0: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    skip_0:
    // 0x801488A4: b           L_801488B0
    // 0x801488A8: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
        goto L_801488B0;
    // 0x801488A8: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    // 0x801488AC: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_801488B0:
    // 0x801488B0: jal         0x802242D0
    // 0x801488B4: nop

    LOOKUP_FUNC(0x802242D0)(rdram, ctx);
        goto after_2;
    // 0x801488B4: nop

    after_2:
    // 0x801488B8: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x801488BC: jal         0x801487B4
    // 0x801488C0: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x801487B4)(rdram, ctx);
        goto after_3;
    // 0x801488C0: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    after_3:
    // 0x801488C4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801488C8: bne         $v0, $zero, L_801488E4
    if (ctx->r2 != 0) {
        // 0x801488CC: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_801488E4;
    }
    // 0x801488CC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801488D0: jal         0x801487F0
    // 0x801488D4: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x801487F0)(rdram, ctx);
        goto after_4;
    // 0x801488D4: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    after_4:
    // 0x801488D8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801488DC: beq         $v0, $zero, L_80148944
    if (ctx->r2 == 0) {
        // 0x801488E0: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_80148944;
    }
    // 0x801488E0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_801488E4:
    // 0x801488E4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x801488E8: addiu       $t6, $v1, 0x44C
    ctx->r14 = ADD32(ctx->r3, 0X44C);
    // 0x801488EC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801488F0: bnel        $t5, $t6, L_80148908
    if (ctx->r13 != ctx->r14) {
        // 0x801488F4: lw          $t8, 0xEC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XEC);
            goto L_80148908;
    }
    goto skip_1;
    // 0x801488F4: lw          $t8, 0xEC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XEC);
    skip_1:
    // 0x801488F8: lw          $t7, 0xDC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XDC);
    // 0x801488FC: b           L_8014890C
    // 0x80148900: lw          $v0, 0x5C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X5C);
        goto L_8014890C;
    // 0x80148900: lw          $v0, 0x5C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X5C);
    // 0x80148904: lw          $t8, 0xEC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XEC);
L_80148908:
    // 0x80148908: lw          $v0, 0x5C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X5C);
L_8014890C:
    // 0x8014890C: lbu         $t0, 0x9C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X9C);
    // 0x80148910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80148914: bnel        $t0, $at, L_80148928
    if (ctx->r8 != ctx->r1) {
        // 0x80148918: lb          $t2, 0x33($t9)
        ctx->r10 = MEM_B(ctx->r25, 0X33);
            goto L_80148928;
    }
    goto skip_2;
    // 0x80148918: lb          $t2, 0x33($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X33);
    skip_2:
    // 0x8014891C: b           L_80148948
    // 0x80148920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80148948;
    // 0x80148920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80148924: lb          $t2, 0x33($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X33);
L_80148928:
    // 0x80148928: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x8014892C: bltz        $t2, L_8014893C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80148930: nop
    
            goto L_8014893C;
    }
    // 0x80148930: nop

    // 0x80148934: bnel        $t3, $zero, L_80148948
    if (ctx->r11 != 0) {
        // 0x80148938: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80148948;
    }
    goto skip_3;
    // 0x80148938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
L_8014893C:
    // 0x8014893C: b           L_80148948
    // 0x80148940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80148948;
    // 0x80148940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148944:
    // 0x80148944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80148948:
    // 0x80148948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014894C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80148950: jr          $ra
    // 0x80148954: nop

    return;
    // 0x80148954: nop

;}
RECOMP_FUNC void M7_FUN_80148958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148958: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014895C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80148960: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80148964: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x80148968: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8014896C: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x80148970: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x80148974: bne         $v0, $t7, L_80148984
    if (ctx->r2 != ctx->r15) {
        // 0x80148978: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80148984;
    }
    // 0x80148978: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014897C: b           L_80148988
    // 0x80148980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80148988;
    // 0x80148980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148984:
    // 0x80148984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80148988:
    // 0x80148988: lb          $t8, 0x91($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X91);
    // 0x8014898C: lb          $t0, 0x90($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X90);
    // 0x80148990: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80148994: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80148998: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8014899C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801489A0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801489A4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801489A8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801489AC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801489B0: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x801489B4: lbu         $a0, 0x1ABD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1ABD);
    // 0x801489B8: jal         0x8013D4A0
    // 0x801489BC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_0;
    // 0x801489BC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_0:
    // 0x801489C0: beq         $v0, $zero, L_80148B10
    if (ctx->r2 == 0) {
        // 0x801489C4: sb          $v0, 0x2B($sp)
        MEM_B(0X2B, ctx->r29) = ctx->r2;
            goto L_80148B10;
    }
    // 0x801489C4: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x801489C8: jal         0x80148270
    // 0x801489CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148270)(rdram, ctx);
        goto after_1;
    // 0x801489CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801489D0: beq         $v0, $zero, L_80148B10
    if (ctx->r2 == 0) {
        // 0x801489D4: nop
    
            goto L_80148B10;
    }
    // 0x801489D4: nop

    // 0x801489D8: lb          $t3, 0x91($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X91);
    // 0x801489DC: lb          $t5, 0x90($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X90);
    // 0x801489E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801489E4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x801489E8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801489EC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801489F0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801489F4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801489F8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801489FC: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80148A00: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80148A04: jal         0x8013D5F4
    // 0x80148A08: lbu         $a0, 0x1ABD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1ABD);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_2;
    // 0x80148A08: lbu         $a0, 0x1ABD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1ABD);
    after_2:
    // 0x80148A0C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80148A10: addiu       $a3, $a3, -0x640
    ctx->r7 = ADD32(ctx->r7, -0X640);
    // 0x80148A14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80148A18: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x80148A1C: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    // 0x80148A20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80148A24: jal         0x8001B204
    // 0x80148A28: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x80148A28: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x80148A2C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80148A30: addiu       $a3, $a3, -0x638
    ctx->r7 = ADD32(ctx->r7, -0X638);
    // 0x80148A34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80148A38: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80148A3C: addiu       $a2, $zero, 0xA3
    ctx->r6 = ADD32(0, 0XA3);
    // 0x80148A40: jal         0x8001B204
    // 0x80148A44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x80148A44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80148A48: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x80148A4C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80148A50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80148A54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80148A58: addiu       $a3, $a3, -0x634
    ctx->r7 = ADD32(ctx->r7, -0X634);
    // 0x80148A5C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80148A60: addiu       $a1, $zero, 0x104
    ctx->r5 = ADD32(0, 0X104);
    // 0x80148A64: addiu       $a2, $zero, 0xA3
    ctx->r6 = ADD32(0, 0XA3);
    // 0x80148A68: jal         0x8001B204
    // 0x80148A6C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x80148A6C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x80148A70: lb          $t1, 0x91($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X91);
    // 0x80148A74: lb          $t3, 0x90($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X90);
    // 0x80148A78: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80148A7C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80148A80: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80148A84: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80148A88: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80148A8C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80148A90: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80148A94: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80148A98: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80148A9C: lbu         $t6, 0x1ABC($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1ABC);
    // 0x80148AA0: lb          $t9, 0x92($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X92);
    // 0x80148AA4: and         $t7, $t9, $t6
    ctx->r15 = ctx->r25 & ctx->r14;
    // 0x80148AA8: beq         $t7, $zero, L_80148AE4
    if (ctx->r15 == 0) {
        // 0x80148AAC: nop
    
            goto L_80148AE4;
    }
    // 0x80148AAC: nop

    // 0x80148AB0: jal         0x80148820
    // 0x80148AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148820)(rdram, ctx);
        goto after_6;
    // 0x80148AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80148AB8: beq         $v0, $zero, L_80148AE4
    if (ctx->r2 == 0) {
        // 0x80148ABC: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80148AE4;
    }
    // 0x80148ABC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80148AC0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80148AC4: addiu       $a3, $a3, -0x62C
    ctx->r7 = ADD32(ctx->r7, -0X62C);
    // 0x80148AC8: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80148ACC: addiu       $a2, $zero, 0xB9
    ctx->r6 = ADD32(0, 0XB9);
    // 0x80148AD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80148AD4: jal         0x8001B204
    // 0x80148AD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x80148AD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x80148ADC: b           L_80148B1C
    // 0x80148AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80148B1C;
    // 0x80148AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80148AE4:
    // 0x80148AE4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80148AE8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80148AEC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80148AF0: addiu       $a3, $a3, -0x620
    ctx->r7 = ADD32(ctx->r7, -0X620);
    // 0x80148AF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80148AF8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x80148AFC: addiu       $a2, $zero, 0xB9
    ctx->r6 = ADD32(0, 0XB9);
    // 0x80148B00: jal         0x8001B204
    // 0x80148B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x80148B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80148B08: b           L_80148B1C
    // 0x80148B0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80148B1C;
    // 0x80148B0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80148B10:
    // 0x80148B10: jal         0x80147DCC
    // 0x80148B14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_9;
    // 0x80148B14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x80148B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80148B1C:
    // 0x80148B1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80148B20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80148B24: jr          $ra
    // 0x80148B28: nop

    return;
    // 0x80148B28: nop

;}
RECOMP_FUNC void M7_FUN_80148b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148B2C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80148B30: lw          $t6, -0x12E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X12E0);
    // 0x80148B34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80148B38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80148B3C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80148B40: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80148B44: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80148B48: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80148B4C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80148B50: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x80148B54: sll         $t9, $a1, 5
    ctx->r25 = S32(ctx->r5 << 5);
    // 0x80148B58: addiu       $t8, $t7, 0x1B
    ctx->r24 = ADD32(ctx->r15, 0X1B);
    // 0x80148B5C: addiu       $t0, $t9, 0x2C
    ctx->r8 = ADD32(ctx->r25, 0X2C);
    // 0x80148B60: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80148B64: jr          $ra
    // 0x80148B68: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    return;
    // 0x80148B68: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148b6c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148b6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148B6C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80148B70: lw          $t6, -0x12E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X12E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148b74(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148b74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148B74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148B7C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80148B80: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80148B84: lh          $a0, 0x1DA4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1DA4);
    // 0x80148B88: jal         0x8001EAD0
    // 0x80148B8C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80148B8C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80148B90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80148B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80148B98: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80148B9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80148BA0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80148BA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80148BA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80148BAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80148BB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80148BB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80148BB8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80148BBC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80148BC0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80148BC4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80148BC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80148BCC: nop

    // 0x80148BD0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80148BD4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80148BD8: nop

    // 0x80148BDC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80148BE0: beql        $t9, $zero, L_80148C30
    if (ctx->r25 == 0) {
        // 0x80148BE4: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_80148C30;
    }
    goto skip_0;
    // 0x80148BE4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80148BE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80148BEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80148BF0: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80148BF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80148BF8: nop

    // 0x80148BFC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80148C00: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80148C04: nop

    // 0x80148C08: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80148C0C: bne         $t9, $zero, L_80148C24
    if (ctx->r25 != 0) {
        // 0x80148C10: nop
    
            goto L_80148C24;
    }
    // 0x80148C10: nop

    // 0x80148C14: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80148C18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80148C1C: b           L_80148C3C
    // 0x80148C20: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80148C3C;
    // 0x80148C20: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80148C24:
    // 0x80148C24: b           L_80148C3C
    // 0x80148C28: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80148C3C;
    // 0x80148C28: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80148C2C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_80148C30:
    // 0x80148C30: nop

    // 0x80148C34: bltz        $t9, L_80148C24
    if (SIGNED(ctx->r25) < 0) {
        // 0x80148C38: nop
    
            goto L_80148C24;
    }
    // 0x80148C38: nop

L_80148C3C:
    // 0x80148C3C: sb          $t9, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r25;
    // 0x80148C40: lh          $t1, 0x1DA4($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1DA4);
    // 0x80148C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148C48: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80148C4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80148C50: addiu       $t2, $t1, 0x200
    ctx->r10 = ADD32(ctx->r9, 0X200);
    // 0x80148C54: sh          $t2, 0x1DA4($at)
    MEM_H(0X1DA4, ctx->r1) = ctx->r10;
    // 0x80148C58: jr          $ra
    // 0x80148C5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80148C5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148c60(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148c60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148C60: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80148C64: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80148C68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80148C6C: blez        $v1, L_80148CA8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80148C70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80148CA8;
    }
    // 0x80148C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80148C74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80148C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80148C7C:
    // 0x80148C7C: lb          $t6, 0x91($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X91);
    // 0x80148C80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80148C84: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80148C88: bne         $a0, $t6, L_80148C98
    if (ctx->r4 != ctx->r14) {
        // 0x80148C8C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80148C98;
    }
    // 0x80148C8C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80148C90: b           L_80148C9C
    // 0x80148C94: sb          $a2, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r6;
        goto L_80148C9C;
    // 0x80148C94: sb          $a2, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r6;
L_80148C98:
    // 0x80148C98: sb          $zero, 0x22($a1)
    MEM_B(0X22, ctx->r5) = 0;
L_80148C9C:
    // 0x80148C9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80148CA0: bne         $at, $zero, L_80148C7C
    if (ctx->r1 != 0) {
        // 0x80148CA4: lw          $a1, 0x10($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X10);
            goto L_80148C7C;
    }
    // 0x80148CA4: lw          $a1, 0x10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X10);
L_80148CA8:
    // 0x80148CA8: jr          $ra
    // 0x80148CAC: nop

    return;
    // 0x80148CAC: nop

;}
RECOMP_FUNC void M7_FUN_80148cb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148CB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148CB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80148CBC: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    // 0x80148CC0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80148CC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80148CC8: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x80148CCC: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80148CD0: andi        $t6, $a2, 0x10
    ctx->r14 = ctx->r6 & 0X10;
    // 0x80148CD4: bne         $t6, $zero, L_80148CE4
    if (ctx->r14 != 0) {
        // 0x80148CD8: andi        $t7, $a2, 0x2000
        ctx->r15 = ctx->r6 & 0X2000;
            goto L_80148CE4;
    }
    // 0x80148CD8: andi        $t7, $a2, 0x2000
    ctx->r15 = ctx->r6 & 0X2000;
    // 0x80148CDC: beq         $t7, $zero, L_80148D58
    if (ctx->r15 == 0) {
        // 0x80148CE0: nop
    
            goto L_80148D58;
    }
    // 0x80148CE0: nop

L_80148CE4:
    // 0x80148CE4: jal         0x80020744
    // 0x80148CE8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80148CE8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80148CEC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80148CF0: jal         0x801471DC
    // 0x80148CF4: lw          $a0, -0x12DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12DC);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_1;
    // 0x80148CF4: lw          $a0, -0x12DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12DC);
    after_1:
    // 0x80148CF8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80148CFC: lb          $t8, 0x91($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X91);
    // 0x80148D00: lb          $t1, 0x93($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X93);
    // 0x80148D04: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80148D08: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80148D0C: sb          $t9, 0x91($a3)
    MEM_B(0X91, ctx->r7) = ctx->r25;
    // 0x80148D10: lb          $t0, 0x91($a3)
    ctx->r8 = MEM_B(ctx->r7, 0X91);
    // 0x80148D14: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x80148D18: mfhi        $t2
    ctx->r10 = hi;
    // 0x80148D1C: sb          $t2, 0x91($a3)
    MEM_B(0X91, ctx->r7) = ctx->r10;
    // 0x80148D20: bne         $t1, $zero, L_80148D2C
    if (ctx->r9 != 0) {
        // 0x80148D24: nop
    
            goto L_80148D2C;
    }
    // 0x80148D24: nop

    // 0x80148D28: break       7
    do_break(2148830504);
L_80148D2C:
    // 0x80148D2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80148D30: bne         $t1, $at, L_80148D44
    if (ctx->r9 != ctx->r1) {
        // 0x80148D34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80148D44;
    }
    // 0x80148D34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80148D38: bne         $t0, $at, L_80148D44
    if (ctx->r8 != ctx->r1) {
        // 0x80148D3C: nop
    
            goto L_80148D44;
    }
    // 0x80148D3C: nop

    // 0x80148D40: break       6
    do_break(2148830528);
L_80148D44:
    // 0x80148D44: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80148D48: jal         0x801482BC
    // 0x80148D4C: nop

    LOOKUP_FUNC(0x801482BC)(rdram, ctx);
        goto after_2;
    // 0x80148D4C: nop

    after_2:
    // 0x80148D50: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80148D54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80148D58:
    // 0x80148D58: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80148D5C: lbu         $a2, 0x93($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X93);
    // 0x80148D60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80148D64: lw          $a1, -0x12D8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12D8);
    // 0x80148D68: jal         0x80148C60
    // 0x80148D6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80148C60)(rdram, ctx);
        goto after_3;
    // 0x80148D6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80148D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148D74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80148D78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80148D7C: jr          $ra
    // 0x80148D80: nop

    return;
    // 0x80148D80: nop

;}
RECOMP_FUNC void M7_FUN_80148d84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148D84: lb          $v0, 0x95($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X95);
    // 0x80148D88: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80148D8C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80148D90: bgezl       $v0, L_80148DA4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80148D94: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80148DA4;
    }
    goto skip_0;
    // 0x80148D94: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_0:
    // 0x80148D98: sb          $t6, 0x95($a0)
    MEM_B(0X95, ctx->r4) = ctx->r14;
    // 0x80148D9C: lb          $v0, 0x95($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X95);
    // 0x80148DA0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_80148DA4:
    // 0x80148DA4: bnel        $at, $zero, L_80148DB4
    if (ctx->r1 != 0) {
        // 0x80148DA8: lb          $v0, 0x96($a0)
        ctx->r2 = MEM_B(ctx->r4, 0X96);
            goto L_80148DB4;
    }
    goto skip_1;
    // 0x80148DA8: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
    skip_1:
    // 0x80148DAC: sb          $zero, 0x95($a0)
    MEM_B(0X95, ctx->r4) = 0;
    // 0x80148DB0: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
L_80148DB4:
    // 0x80148DB4: bgezl       $v0, L_80148DC8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80148DB8: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_80148DC8;
    }
    goto skip_2;
    // 0x80148DB8: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    skip_2:
    // 0x80148DBC: sb          $t7, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r15;
    // 0x80148DC0: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
    // 0x80148DC4: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
L_80148DC8:
    // 0x80148DC8: bne         $at, $zero, L_80148DD4
    if (ctx->r1 != 0) {
        // 0x80148DCC: nop
    
            goto L_80148DD4;
    }
    // 0x80148DCC: nop

    // 0x80148DD0: sb          $zero, 0x96($a0)
    MEM_B(0X96, ctx->r4) = 0;
L_80148DD4:
    // 0x80148DD4: jr          $ra
    // 0x80148DD8: nop

    return;
    // 0x80148DD8: nop

;}
