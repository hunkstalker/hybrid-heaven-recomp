#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801d2088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D208C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D2090: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801D2094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D209C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801D20A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x801D20A4: jal         0x8012C6B4
    // 0x801D20A8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801D20A8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x801D20AC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D20B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801D20B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D20B8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D20BC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x801D20C0: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801D20C4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801D20C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D20CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D20D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D20D4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D20D8: sub.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d - ctx->f16.d;
    // 0x801D20DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801D20E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D20E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801D20E8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x801D20EC: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x801D20F0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D20F4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D20F8: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x801D20FC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801D2100: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801D2104: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801D2108: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x801D210C: add.d       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d + ctx->f14.d;
    // 0x801D2110: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x801D2114: nop

    // 0x801D2118: bc1fl       L_801D2134
    if (!c1cs) {
        // 0x801D211C: sub.d       $f12, $f2, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d - ctx->f14.d;
            goto L_801D2134;
    }
    goto skip_0;
    // 0x801D211C: sub.d       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d - ctx->f14.d;
    skip_0:
    // 0x801D2120: cvt.s.d     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f10.fl = CVT_S_D(ctx->f12.d);
    // 0x801D2124: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x801D2128: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801D212C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801D2130: sub.d       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d - ctx->f14.d;
L_801D2134:
    // 0x801D2134: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x801D2138: nop

    // 0x801D213C: bc1f        L_801D214C
    if (!c1cs) {
        // 0x801D2140: nop
    
            goto L_801D214C;
    }
    // 0x801D2140: nop

    // 0x801D2144: cvt.s.d     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f6.fl = CVT_S_D(ctx->f12.d);
    // 0x801D2148: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
L_801D214C:
    // 0x801D214C: jal         0x8012C6B4
    // 0x801D2150: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D2150: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x801D2154: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D2158: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801D215C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D2160: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D2164: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x801D2168: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801D216C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801D2170: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D2174: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D2178: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D217C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D2180: sub.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d - ctx->f16.d;
    // 0x801D2184: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801D2188: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D218C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801D2190: div.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x801D2194: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801D2198: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D219C: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x801D21A0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801D21A4: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801D21A8: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801D21AC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801D21B0: add.d       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d + ctx->f14.d;
    // 0x801D21B4: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x801D21B8: nop

    // 0x801D21BC: bc1fl       L_801D21D8
    if (!c1cs) {
        // 0x801D21C0: sub.d       $f12, $f2, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d - ctx->f14.d;
            goto L_801D21D8;
    }
    goto skip_1;
    // 0x801D21C0: sub.d       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d - ctx->f14.d;
    skip_1:
    // 0x801D21C4: cvt.s.d     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f6.fl = CVT_S_D(ctx->f12.d);
    // 0x801D21C8: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
    // 0x801D21CC: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801D21D0: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x801D21D4: sub.d       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = ctx->f2.d - ctx->f14.d;
L_801D21D8:
    // 0x801D21D8: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x801D21DC: nop

    // 0x801D21E0: bc1fl       L_801D21F4
    if (!c1cs) {
        // 0x801D21E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D21F4;
    }
    goto skip_2;
    // 0x801D21E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801D21E8: cvt.s.d     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f10.fl = CVT_S_D(ctx->f12.d);
    // 0x801D21EC: swc1        $f10, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f10.u32l;
    // 0x801D21F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D21F4:
    // 0x801D21F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D21F8: jr          $ra
    // 0x801D21FC: nop

    return;
    // 0x801D21FC: nop

;}
RECOMP_FUNC void M8_FUN_801d2200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D2204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2208: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D220C: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
    // 0x801D2210: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    // 0x801D2214: jal         0x801CE0E8
    // 0x801D2218: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D2218: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D221C: bne         $v0, $zero, L_801D22A4
    if (ctx->r2 != 0) {
        // 0x801D2220: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_801D22A4;
    }
    // 0x801D2220: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801D2224: lbu         $t6, 0x94($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X94);
    // 0x801D2228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D222C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D2230: blez        $t6, L_801D2294
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D2234: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_801D2294;
    }
    // 0x801D2234: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801D2238: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D223C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D2240: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x801D2244: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
L_801D2248:
    // 0x801D2248: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x801D224C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801D2250: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801D2254: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D2258: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x801D225C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801D2260: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801D2264: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x801D2268: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D226C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D2270: sh          $a2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r6;
    // 0x801D2274: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D2278: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801D227C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D2280: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801D2284: lbu         $t9, 0x94($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X94);
    // 0x801D2288: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801D228C: bnel        $at, $zero, L_801D2248
    if (ctx->r1 != 0) {
        // 0x801D2290: addiu       $v1, $a1, 0x1
        ctx->r3 = ADD32(ctx->r5, 0X1);
            goto L_801D2248;
    }
    goto skip_0;
    // 0x801D2290: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    skip_0:
L_801D2294:
    // 0x801D2294: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2298: addiu       $a1, $a1, 0x22B4
    ctx->r5 = ADD32(ctx->r5, 0X22B4);
    // 0x801D229C: jal         0x800058DC
    // 0x801D22A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D22A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
L_801D22A4:
    // 0x801D22A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D22A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D22AC: jr          $ra
    // 0x801D22B0: nop

    return;
    // 0x801D22B0: nop

;}
RECOMP_FUNC void M8_FUN_801d22b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D22B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801D22B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801D22BC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x801D22C0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x801D22C4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x801D22C8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x801D22CC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801D22D0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801D22D4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D22D8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D22DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D22E0: lbu         $a2, 0x94($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X94);
    // 0x801D22E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D22E8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D22EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D22F0: blez        $a2, L_801D23F4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x801D22F4: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_801D23F4;
    }
    // 0x801D22F4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801D22F8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D22FC: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D2300: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D2304: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D2308: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D230C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D2310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D2314: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x801D2318: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_801D231C:
    // 0x801D231C: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D2320: lhu         $t6, 0x92($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X92);
    // 0x801D2324: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x801D2328: addu        $v0, $s5, $t7
    ctx->r2 = ADD32(ctx->r21, ctx->r15);
    // 0x801D232C: mflo        $v1
    ctx->r3 = lo;
    // 0x801D2330: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D2334: bnel        $at, $zero, L_801D23E4
    if (ctx->r1 != 0) {
        // 0x801D2338: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801D23E4;
    }
    goto skip_0;
    // 0x801D2338: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x801D233C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D2340: sb          $s4, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r20;
    // 0x801D2344: lhu         $t9, 0x92($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X92);
    // 0x801D2348: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801D234C: subu        $a3, $t9, $v1
    ctx->r7 = SUB32(ctx->r25, ctx->r3);
    // 0x801D2350: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801D2354: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801D2358: slti        $at, $a3, 0xB
    ctx->r1 = SIGNED(ctx->r7) < 0XB ? 1 : 0;
    // 0x801D235C: beq         $at, $zero, L_801D23C8
    if (ctx->r1 == 0) {
        // 0x801D2360: lw          $s0, 0x30($t0)
        ctx->r16 = MEM_W(ctx->r8, 0X30);
            goto L_801D23C8;
    }
    // 0x801D2360: lw          $s0, 0x30($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X30);
    // 0x801D2364: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x801D2368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D236C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D2370: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D2374: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D2378: div.d       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f24.d);
    // 0x801D237C: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x801D2380: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D2384: jal         0x801CD5E0
    // 0x801D2388: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_0;
    // 0x801D2388: nop

    after_0:
    // 0x801D238C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D2390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2394: jal         0x801CD728
    // 0x801D2398: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_1;
    // 0x801D2398: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801D239C: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x801D23A0: lwc1        $f16, 0x60($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X60);
    // 0x801D23A4: sub.d       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f22.d - ctx->f4.d;
    // 0x801D23A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D23AC: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x801D23B0: sub.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f8.d - ctx->f22.d;
    // 0x801D23B4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801D23B8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D23BC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D23C0: b           L_801D23D8
    // 0x801D23C4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
        goto L_801D23D8;
    // 0x801D23C4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_801D23C8:
    // 0x801D23C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D23CC: lw          $a1, 0x6C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X6C);
    // 0x801D23D0: jal         0x801D2088
    // 0x801D23D4: lw          $a2, 0x74($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X74);
    LOOKUP_FUNC(0x801D2088)(rdram, ctx);
        goto after_2;
    // 0x801D23D4: lw          $a2, 0x74($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X74);
    after_2:
L_801D23D8:
    // 0x801D23D8: lbu         $a2, 0x94($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X94);
    // 0x801D23DC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801D23E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_801D23E4:
    // 0x801D23E4: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x801D23E8: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801D23EC: bne         $at, $zero, L_801D231C
    if (ctx->r1 != 0) {
        // 0x801D23F0: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_801D231C;
    }
    // 0x801D23F0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801D23F4:
    // 0x801D23F4: lhu         $t1, 0x92($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X92);
    // 0x801D23F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D23FC: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D2400: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801D2404: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D2408: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D240C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D2410: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D2414: bgez        $t1, L_801D242C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801D2418: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801D242C;
    }
    // 0x801D2418: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D241C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D2420: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D2424: nop

    // 0x801D2428: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_801D242C:
    // 0x801D242C: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x801D2430: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D2434: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D2438: div.d       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f24.d);
    // 0x801D243C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x801D2440: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801D2444: bgez        $a2, L_801D2458
    if (SIGNED(ctx->r6) >= 0) {
        // 0x801D2448: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801D2458;
    }
    // 0x801D2448: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D244C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D2450: nop

    // 0x801D2454: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801D2458:
    // 0x801D2458: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D245C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D2460: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x801D2464: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801D2468: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D246C: c.le.d      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.d <= ctx->f10.d;
    // 0x801D2470: nop

    // 0x801D2474: bc1fl       L_801D2488
    if (!c1cs) {
        // 0x801D2478: mfc1        $a3, $f0
        ctx->r7 = (int32_t)ctx->f0.u32l;
            goto L_801D2488;
    }
    goto skip_1;
    // 0x801D2478: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x801D247C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801D2480: nop

    // 0x801D2484: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_801D2488:
    // 0x801D2488: jal         0x801CD924
    // 0x801D248C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_3;
    // 0x801D248C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_3:
    // 0x801D2490: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x801D2494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2498: lhu         $t3, 0x4C($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4C);
    // 0x801D249C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x801D24A0: beql        $t4, $zero, L_801D24CC
    if (ctx->r12 == 0) {
        // 0x801D24A4: lhu         $v0, 0x92($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X92);
            goto L_801D24CC;
    }
    goto skip_2;
    // 0x801D24A4: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    skip_2:
    // 0x801D24A8: jal         0x801CE5B0
    // 0x801D24AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_4;
    // 0x801D24AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x801D24B0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D24B4: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D24B8: jal         0x800058DC
    // 0x801D24BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801D24BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801D24C0: b           L_801D2504
    // 0x801D24C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_801D2504;
    // 0x801D24C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801D24C8: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
L_801D24CC:
    // 0x801D24CC: lhu         $t5, 0x90($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X90);
    // 0x801D24D0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801D24D4: slt         $v1, $t5, $v0
    ctx->r3 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D24D8: beq         $v1, $zero, L_801D2500
    if (ctx->r3 == 0) {
        // 0x801D24DC: sh          $t6, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r14;
            goto L_801D2500;
    }
    // 0x801D24DC: sh          $t6, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r14;
    // 0x801D24E0: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x801D24E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D24E8: addiu       $a1, $a1, 0x2530
    ctx->r5 = ADD32(ctx->r5, 0X2530);
    // 0x801D24EC: lhu         $t7, 0x4C($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4C);
    // 0x801D24F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D24F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801D24F8: jal         0x800058DC
    // 0x801D24FC: sh          $t8, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D24FC: sh          $t8, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r24;
    after_6:
L_801D2500:
    // 0x801D2500: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801D2504:
    // 0x801D2504: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D2508: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D250C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D2510: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801D2514: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801D2518: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801D251C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x801D2520: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x801D2524: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x801D2528: jr          $ra
    // 0x801D252C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801D252C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d2530(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d2530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2530: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D2534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D2538: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801D253C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801D2540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D2544: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D2548: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D254C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801D2550: blez        $t6, L_801D258C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D2554: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801D258C;
    }
    // 0x801D2554: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801D2558: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_801D255C:
    // 0x801D255C: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801D2560: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D2564: lw          $a1, 0x6C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X6C);
    // 0x801D2568: lw          $a2, 0x74($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X74);
    // 0x801D256C: jal         0x801D2088
    // 0x801D2570: lw          $a0, 0x30($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x801D2088)(rdram, ctx);
        goto after_0;
    // 0x801D2570: lw          $a0, 0x30($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X30);
    after_0:
    // 0x801D2574: lbu         $t0, 0x94($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X94);
    // 0x801D2578: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801D257C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801D2580: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D2584: bnel        $at, $zero, L_801D255C
    if (ctx->r1 != 0) {
        // 0x801D2588: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801D255C;
    }
    goto skip_0;
    // 0x801D2588: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_0:
L_801D258C:
    // 0x801D258C: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x801D2590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2594: lhu         $v0, 0x4C($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4C);
    // 0x801D2598: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x801D259C: beq         $t2, $zero, L_801D25C4
    if (ctx->r10 == 0) {
        // 0x801D25A0: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_801D25C4;
    }
    // 0x801D25A0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801D25A4: jal         0x801CE5B0
    // 0x801D25A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D25A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x801D25AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D25B0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D25B4: jal         0x800058DC
    // 0x801D25B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D25B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801D25BC: b           L_801D2624
    // 0x801D25C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D2624;
    // 0x801D25C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D25C4:
    // 0x801D25C4: bne         $at, $zero, L_801D2620
    if (ctx->r1 != 0) {
        // 0x801D25C8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801D2620;
    }
    // 0x801D25C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D25CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D25D0: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x801D25D4: sh          $zero, 0x92($s1)
    MEM_H(0X92, ctx->r17) = 0;
    // 0x801D25D8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801D25DC: nop

    // 0x801D25E0: bc1f        L_801D2608
    if (!c1cs) {
        // 0x801D25E4: nop
    
            goto L_801D2608;
    }
    // 0x801D25E4: nop

    // 0x801D25E8: jal         0x80020718
    // 0x801D25EC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_3;
    // 0x801D25EC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_3:
    // 0x801D25F0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D25F4: addiu       $a1, $a1, 0x2638
    ctx->r5 = ADD32(ctx->r5, 0X2638);
    // 0x801D25F8: jal         0x800058DC
    // 0x801D25FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D25FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801D2600: b           L_801D2624
    // 0x801D2604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D2624;
    // 0x801D2604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D2608:
    // 0x801D2608: jal         0x80020718
    // 0x801D260C: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x801D260C: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    after_5:
    // 0x801D2610: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2614: addiu       $a1, $a1, 0x277C
    ctx->r5 = ADD32(ctx->r5, 0X277C);
    // 0x801D2618: jal         0x800058DC
    // 0x801D261C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D261C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_801D2620:
    // 0x801D2620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D2624:
    // 0x801D2624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D2628: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801D262C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801D2630: jr          $ra
    // 0x801D2634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801D2634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d2638(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d2638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D263C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2640: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801D2644: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D2648: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D264C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D2650: bgez        $t6, L_801D2664
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D2654: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D2664;
    }
    // 0x801D2654: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D2658: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D265C: nop

    // 0x801D2660: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801D2664:
    // 0x801D2664: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801D2668: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D266C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D2670: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D2674: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801D2678: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D267C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D2680: lbu         $t7, 0x94($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X94);
    // 0x801D2684: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2688: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D268C: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x801D2690: blez        $t7, L_801D26EC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801D2694: cvt.s.d     $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
            goto L_801D26EC;
    }
    // 0x801D2694: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x801D2698: ldc1        $f10, 0x3628($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3628);
    // 0x801D269C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x801D26A0: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801D26A4: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x801D26A8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_801D26AC:
    // 0x801D26AC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x801D26B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D26B4: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x801D26B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D26BC: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801D26C0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x801D26C4: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D26C8: lwc1        $f18, 0x74($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801D26CC: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801D26D0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801D26D4: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801D26D8: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x801D26DC: lbu         $t1, 0x94($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X94);
    // 0x801D26E0: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801D26E4: bnel        $at, $zero, L_801D26AC
    if (ctx->r1 != 0) {
        // 0x801D26E8: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_801D26AC;
    }
    goto skip_0;
    // 0x801D26E8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    skip_0:
L_801D26EC:
    // 0x801D26EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D26F0: ldc1        $f6, 0x3630($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3630);
    // 0x801D26F4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801D26F8: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x801D26FC: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801D2700: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801D2704: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801D2708: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801D270C: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801D2710: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801D2714: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801D2718: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x801D271C: lhu         $t5, 0x4C($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X4C);
    // 0x801D2720: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801D2724: bnel        $t6, $zero, L_801D274C
    if (ctx->r14 != 0) {
        // 0x801D2728: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_801D274C;
    }
    goto skip_1;
    // 0x801D2728: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x801D272C: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    // 0x801D2730: slti        $v1, $v0, 0x15
    ctx->r3 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x801D2734: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801D2738: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D273C: beq         $v1, $zero, L_801D276C
    if (ctx->r3 == 0) {
        // 0x801D2740: sh          $t7, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r15;
            goto L_801D276C;
    }
    // 0x801D2740: sh          $t7, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r15;
    // 0x801D2744: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x801D2748: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_801D274C:
    // 0x801D274C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801D2750: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x801D2754: jal         0x801CE5B0
    // 0x801D2758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_0;
    // 0x801D2758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D275C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D2764: jal         0x800058DC
    // 0x801D2768: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2768: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_1:
L_801D276C:
    // 0x801D276C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D2770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2774: jr          $ra
    // 0x801D2778: nop

    return;
    // 0x801D2778: nop

;}
RECOMP_FUNC void M8_FUN_801d277c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D277C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D2780: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D2784: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x801D2788: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x801D278C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x801D2790: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x801D2794: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D2798: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D279C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D27A0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D27A4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D27A8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801D27AC: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x801D27B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D27B4: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801D27B8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D27BC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801D27C0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D27C4: bgez        $t6, L_801D27DC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D27C8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D27DC;
    }
    // 0x801D27C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D27CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D27D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D27D4: nop

    // 0x801D27D8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801D27DC:
    // 0x801D27DC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801D27E0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D27E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D27E8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D27EC: lbu         $t7, 0x94($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X94);
    // 0x801D27F0: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801D27F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D27F8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x801D27FC: sub.d       $f4, $f28, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f28.d - ctx->f18.d;
    // 0x801D2800: blez        $t7, L_801D2888
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801D2804: cvt.s.d     $f24, $f4
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
            goto L_801D2888;
    }
    // 0x801D2804: cvt.s.d     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
    // 0x801D2808: cvt.d.s     $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f22.d = CVT_D_S(ctx->f24.fl);
    // 0x801D280C: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x801D2810: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D2814: sub.d       $f26, $f28, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.d); NAN_CHECK(ctx->f22.d); 
    ctx->f26.d = ctx->f28.d - ctx->f22.d;
    // 0x801D2818: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_801D281C:
    // 0x801D281C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801D2820: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D2824: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D2828: jal         0x801CD5E0
    // 0x801D282C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_0;
    // 0x801D282C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801D2830: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801D2834: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D2838: jal         0x801CD728
    // 0x801D283C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_1;
    // 0x801D283C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801D2840: lwc1        $f8, 0x60($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X60);
    // 0x801D2844: c.le.d      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.d <= ctx->f20.d;
    // 0x801D2848: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801D284C: add.d       $f10, $f6, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f26.d); 
    ctx->f10.d = ctx->f6.d + ctx->f26.d;
    // 0x801D2850: sub.d       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = ctx->f10.d - ctx->f28.d;
    // 0x801D2854: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x801D2858: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D285C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D2860: bc1f        L_801D2870
    if (!c1cs) {
        // 0x801D2864: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_801D2870;
    }
    // 0x801D2864: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D2868: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801D286C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
L_801D2870:
    // 0x801D2870: lbu         $t0, 0x94($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X94);
    // 0x801D2874: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D2878: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801D287C: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D2880: bnel        $at, $zero, L_801D281C
    if (ctx->r1 != 0) {
        // 0x801D2884: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_801D281C;
    }
    goto skip_0;
    // 0x801D2884: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_0:
L_801D2888:
    // 0x801D2888: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801D288C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x801D2890: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801D2894: jal         0x801CD924
    // 0x801D2898: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_2;
    // 0x801D2898: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_2:
    // 0x801D289C: lhu         $v0, 0x92($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X92);
    // 0x801D28A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D28A4: slti        $v1, $v0, 0x15
    ctx->r3 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x801D28A8: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801D28AC: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x801D28B0: bne         $v1, $zero, L_801D28CC
    if (ctx->r3 != 0) {
        // 0x801D28B4: sh          $t1, 0x92($s3)
        MEM_H(0X92, ctx->r19) = ctx->r9;
            goto L_801D28CC;
    }
    // 0x801D28B4: sh          $t1, 0x92($s3)
    MEM_H(0X92, ctx->r19) = ctx->r9;
    // 0x801D28B8: lw          $t2, 0xC($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XC);
    // 0x801D28BC: lhu         $t3, 0x4C($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4C);
    // 0x801D28C0: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x801D28C4: beql        $t4, $zero, L_801D28E8
    if (ctx->r12 == 0) {
        // 0x801D28C8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D28E8;
    }
    goto skip_1;
    // 0x801D28C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
L_801D28CC:
    // 0x801D28CC: jal         0x801CE5B0
    // 0x801D28D0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D28D0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x801D28D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D28D8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D28DC: jal         0x800058DC
    // 0x801D28E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D28E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x801D28E4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D28E8:
    // 0x801D28E8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D28EC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D28F0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D28F4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D28F8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D28FC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x801D2900: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801D2904: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x801D2908: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x801D290C: jr          $ra
    // 0x801D2910: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801D2910: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d2914(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d2914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2914: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D2918: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801D291C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801D2920: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D2924: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801D2928: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D292C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801D2930: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801D2934: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801D2938: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801D293C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D2940: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D2944: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D2948: sb          $zero, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = 0;
    // 0x801D294C: jal         0x801CE0E8
    // 0x801D2950: addiu       $a1, $sp, 0x5D
    ctx->r5 = ADD32(ctx->r29, 0X5D);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D2950: addiu       $a1, $sp, 0x5D
    ctx->r5 = ADD32(ctx->r29, 0X5D);
    after_0:
    // 0x801D2954: beq         $v0, $zero, L_801D2970
    if (ctx->r2 == 0) {
        // 0x801D2958: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801D2970;
    }
    // 0x801D2958: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D295C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2960: jal         0x800058DC
    // 0x801D2964: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2964: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_1:
    // 0x801D2968: b           L_801D2A78
    // 0x801D296C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_801D2A78;
    // 0x801D296C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D2970:
    // 0x801D2970: lbu         $t6, 0x94($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X94);
    // 0x801D2974: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D2978: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D297C: blez        $t6, L_801D2A64
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D2980: nop
    
            goto L_801D2A64;
    }
    // 0x801D2980: nop

    // 0x801D2984: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D2988: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801D298C: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D2990: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801D2994: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D2998: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D299C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D29A0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D29A4: nop

L_801D29A8:
    // 0x801D29A8: jal         0x8012C6B4
    // 0x801D29AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801D29AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x801D29B0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D29B4: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x801D29B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D29BC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D29C0: div.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f22.d);
    // 0x801D29C4: add.d       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = ctx->f10.d + ctx->f24.d;
    // 0x801D29C8: jal         0x8012C6B4
    // 0x801D29CC: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D29CC: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    after_3:
    // 0x801D29D0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x801D29D4: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x801D29D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D29DC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x801D29E0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x801D29E4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x801D29E8: jal         0x8012C6B4
    // 0x801D29EC: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D29EC: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_4:
    // 0x801D29F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801D29F4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D29F8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x801D29FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D2A00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D2A04: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801D2A08: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D2A0C: div.d       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f26.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f26.d);
    // 0x801D2A10: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x801D2A14: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x801D2A18: jal         0x8001EB64
    // 0x801D2A1C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x801D2A1C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x801D2A20: mul.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x801D2A24: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D2A28: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x801D2A2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D2A30: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801D2A34: jal         0x8001EAD0
    // 0x801D2A38: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801D2A38: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x801D2A3C: mul.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x801D2A40: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D2A44: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D2A48: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801D2A4C: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801D2A50: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801D2A54: lbu         $t0, 0x94($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X94);
    // 0x801D2A58: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D2A5C: bne         $at, $zero, L_801D29A8
    if (ctx->r1 != 0) {
        // 0x801D2A60: nop
    
            goto L_801D29A8;
    }
    // 0x801D2A60: nop

L_801D2A64:
    // 0x801D2A64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2A68: addiu       $a1, $a1, 0x2AA4
    ctx->r5 = ADD32(ctx->r5, 0X2AA4);
    // 0x801D2A6C: jal         0x800058DC
    // 0x801D2A70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801D2A70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x801D2A74: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D2A78:
    // 0x801D2A78: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D2A7C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D2A80: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D2A84: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801D2A88: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801D2A8C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801D2A90: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801D2A94: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801D2A98: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801D2A9C: jr          $ra
    // 0x801D2AA0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801D2AA0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d2aa4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d2aa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2AA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2AAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D2AB0: jal         0x801CD878
    // 0x801D2AB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D2AB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D2AB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D2ABC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801D2AC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D2AC4: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D2AC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2ACC: blezl       $t6, L_801D2B74
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D2AD0: lhu         $v0, 0x92($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X92);
            goto L_801D2B74;
    }
    goto skip_0;
    // 0x801D2AD0: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    skip_0:
    // 0x801D2AD4: ldc1        $f16, 0x3638($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X3638);
    // 0x801D2AD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2ADC: ldc1        $f0, 0x3640($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X3640);
    // 0x801D2AE0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_801D2AE4:
    // 0x801D2AE4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D2AE8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D2AEC: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x801D2AF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D2AF4: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D2AF8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D2AFC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D2B00: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D2B04: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x801D2B08: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x801D2B0C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D2B10: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x801D2B14: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x801D2B18: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x801D2B1C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D2B20: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x801D2B24: lwc1        $f4, 0x74($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801D2B28: sub.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x801D2B2C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D2B30: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x801D2B34: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801D2B38: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x801D2B3C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D2B40: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x801D2B44: mul.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801D2B48: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x801D2B4C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801D2B50: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801D2B54: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801D2B58: swc1        $f14, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f14.u32l;
    // 0x801D2B5C: swc1        $f14, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f14.u32l;
    // 0x801D2B60: lbu         $t0, 0x94($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X94);
    // 0x801D2B64: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D2B68: bnel        $at, $zero, L_801D2AE4
    if (ctx->r1 != 0) {
        // 0x801D2B6C: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_801D2AE4;
    }
    goto skip_1;
    // 0x801D2B6C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_1:
    // 0x801D2B70: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
L_801D2B74:
    // 0x801D2B74: lhu         $t1, 0x90($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X90);
    // 0x801D2B78: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801D2B7C: slt         $v1, $t1, $v0
    ctx->r3 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D2B80: bne         $v1, $zero, L_801D2B9C
    if (ctx->r3 != 0) {
        // 0x801D2B84: sh          $t2, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r10;
            goto L_801D2B9C;
    }
    // 0x801D2B84: sh          $t2, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r10;
    // 0x801D2B88: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x801D2B8C: lhu         $t4, 0x4C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4C);
    // 0x801D2B90: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x801D2B94: beql        $t5, $zero, L_801D2BB8
    if (ctx->r13 == 0) {
        // 0x801D2B98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D2BB8;
    }
    goto skip_2;
    // 0x801D2B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_801D2B9C:
    // 0x801D2B9C: jal         0x801CE5B0
    // 0x801D2BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D2BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D2BA4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D2BAC: jal         0x800058DC
    // 0x801D2BB0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D2BB0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D2BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2BB8:
    // 0x801D2BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2BBC: jr          $ra
    // 0x801D2BC0: nop

    return;
    // 0x801D2BC0: nop

;}
RECOMP_FUNC void M8_FUN_801d2bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2BC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2BCC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D2BD0: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801D2BD4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801D2BD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D2BDC: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    // 0x801D2BE0: lwc1        $f4, 0x80($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X80);
    // 0x801D2BE4: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x801D2BE8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x801D2BEC: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x801D2BF0: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x801D2BF4: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D2BF8: swc1        $f8, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f8.u32l;
    // 0x801D2BFC: jal         0x801CE0E8
    // 0x801D2C00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D2C00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D2C04: bne         $v0, $zero, L_801D2C18
    if (ctx->r2 != 0) {
        // 0x801D2C08: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D2C18;
    }
    // 0x801D2C08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D2C0C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2C10: jal         0x800058DC
    // 0x801D2C14: addiu       $a1, $a1, 0x2C28
    ctx->r5 = ADD32(ctx->r5, 0X2C28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2C14: addiu       $a1, $a1, 0x2C28
    ctx->r5 = ADD32(ctx->r5, 0X2C28);
    after_1:
L_801D2C18:
    // 0x801D2C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D2C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D2C20: jr          $ra
    // 0x801D2C24: nop

    return;
    // 0x801D2C24: nop

;}
RECOMP_FUNC void M8_FUN_801d2c28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2C28: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x801D2C2C: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x801D2C30: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x801D2C34: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x801D2C38: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x801D2C3C: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x801D2C40: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x801D2C44: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x801D2C48: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x801D2C4C: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x801D2C50: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x801D2C54: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x801D2C58: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x801D2C5C: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x801D2C60: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x801D2C64: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x801D2C68: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801D2C6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D2C70: lbu         $t6, 0x7C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7C);
    // 0x801D2C74: beql        $t6, $zero, L_801D2CC4
    if (ctx->r14 == 0) {
        // 0x801D2C78: lbu         $t7, 0x94($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X94);
            goto L_801D2CC4;
    }
    goto skip_0;
    // 0x801D2C78: lbu         $t7, 0x94($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X94);
    skip_0:
    // 0x801D2C7C: lw          $a0, 0x90($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X90);
    // 0x801D2C80: jal         0x80006214
    // 0x801D2C84: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D2C84: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    after_0:
    // 0x801D2C88: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x801D2C8C: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x801D2C90: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x801D2C94: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801D2C98: jal         0x8013A334
    // 0x801D2C9C: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_1;
    // 0x801D2C9C: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_1:
    // 0x801D2CA0: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801D2CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2CA8: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    // 0x801D2CAC: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801D2CB0: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    // 0x801D2CB4: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801D2CB8: jal         0x80006214
    // 0x801D2CBC: swc1        $f8, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D2CBC: swc1        $f8, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f8.u32l;
    after_2:
    // 0x801D2CC0: lbu         $t7, 0x94($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X94);
L_801D2CC4:
    // 0x801D2CC4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801D2CC8: lw          $s2, 0xEC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XEC);
    // 0x801D2CCC: blez        $t7, L_801D2EDC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801D2CD0: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D2EDC;
    }
    // 0x801D2CD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2CD4: lwc1        $f30, 0x3648($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X3648);
    // 0x801D2CD8: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x801D2CDC: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801D2CE0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D2CE4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801D2CE8: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801D2CEC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801D2CF0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801D2CF4: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x801D2CF8: lhu         $t9, 0x92($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X92);
L_801D2CFC:
    // 0x801D2CFC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x801D2D00: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801D2D04: div         $zero, $t9, $s4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r20)));
    // 0x801D2D08: mfhi        $v0
    ctx->r2 = hi;
    // 0x801D2D0C: addiu       $a0, $v0, -0x4
    ctx->r4 = ADD32(ctx->r2, -0X4);
    // 0x801D2D10: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D2D14: bne         $s4, $zero, L_801D2D20
    if (ctx->r20 != 0) {
        // 0x801D2D18: nop
    
            goto L_801D2D20;
    }
    // 0x801D2D18: nop

    // 0x801D2D1C: break       7
    do_break(2149395740);
L_801D2D20:
    // 0x801D2D20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D2D24: bne         $s4, $at, L_801D2D38
    if (ctx->r20 != ctx->r1) {
        // 0x801D2D28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D2D38;
    }
    // 0x801D2D28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D2D2C: bne         $t9, $at, L_801D2D38
    if (ctx->r25 != ctx->r1) {
        // 0x801D2D30: nop
    
            goto L_801D2D38;
    }
    // 0x801D2D30: nop

    // 0x801D2D34: break       6
    do_break(2149395764);
L_801D2D38:
    // 0x801D2D38: bgezl       $a0, L_801D2D4C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801D2D3C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_801D2D4C;
    }
    goto skip_1;
    // 0x801D2D3C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_1:
    // 0x801D2D40: b           L_801D2D4C
    // 0x801D2D44: subu        $v1, $t1, $v0
    ctx->r3 = SUB32(ctx->r9, ctx->r2);
        goto L_801D2D4C;
    // 0x801D2D44: subu        $v1, $t1, $v0
    ctx->r3 = SUB32(ctx->r9, ctx->r2);
    // 0x801D2D48: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_801D2D4C:
    // 0x801D2D4C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x801D2D50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2D54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D2D58: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D2D5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D2D60: mul.d       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f28.d);
    // 0x801D2D64: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    // 0x801D2D68: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D2D6C: jal         0x801CD5E0
    // 0x801D2D70: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_3;
    // 0x801D2D70: nop

    after_3:
    // 0x801D2D74: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D2D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2D7C: jal         0x801CD728
    // 0x801D2D80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_4;
    // 0x801D2D80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x801D2D84: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
    // 0x801D2D88: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D2D8C: lwc1        $f10, 0x58($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X58);
    // 0x801D2D90: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D2D94: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801D2D98: lwc1        $f18, 0x5C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x801D2D9C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D2DA0: sub.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801D2DA4: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801D2DA8: sub.s       $f24, $f18, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801D2DAC: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801D2DB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801D2DB4: mul.s       $f16, $f24, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x801D2DB8: jal         0x8002FC20
    // 0x801D2DBC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_5;
    // 0x801D2DBC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_5:
    // 0x801D2DC0: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x801D2DC4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801D2DC8: bc1f        L_801D2DFC
    if (!c1cs) {
        // 0x801D2DCC: nop
    
            goto L_801D2DFC;
    }
    // 0x801D2DCC: nop

    // 0x801D2DD0: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x801D2DD4: sb          $s6, 0x7D($t2)
    MEM_B(0X7D, ctx->r10) = ctx->r22;
    // 0x801D2DD8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x801D2DDC: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
    // 0x801D2DE0: lwc1        $f18, 0x54($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X54);
    // 0x801D2DE4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801D2DE8: lwc1        $f4, 0x58($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X58);
    // 0x801D2DEC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801D2DF0: lwc1        $f6, 0x5C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x801D2DF4: b           L_801D2E38
    // 0x801D2DF8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_801D2E38;
    // 0x801D2DF8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_801D2DFC:
    // 0x801D2DFC: mul.s       $f10, $f26, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x801D2E00: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D2E04: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D2E08: mul.s       $f6, $f26, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x801D2E0C: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801D2E10: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D2E14: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801D2E18: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D2E1C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801D2E20: mul.s       $f18, $f26, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x801D2E24: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801D2E28: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801D2E2C: div.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801D2E30: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801D2E34: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_801D2E38:
    // 0x801D2E38: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801D2E3C: bgez        $v0, L_801D2E50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D2E40: andi        $t4, $v0, 0x1
        ctx->r12 = ctx->r2 & 0X1;
            goto L_801D2E50;
    }
    // 0x801D2E40: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x801D2E44: beq         $t4, $zero, L_801D2E50
    if (ctx->r12 == 0) {
        // 0x801D2E48: nop
    
            goto L_801D2E50;
    }
    // 0x801D2E48: nop

    // 0x801D2E4C: addiu       $t4, $t4, -0x2
    ctx->r12 = ADD32(ctx->r12, -0X2);
L_801D2E50:
    // 0x801D2E50: xor         $v1, $s5, $t4
    ctx->r3 = ctx->r21 ^ ctx->r12;
    // 0x801D2E54: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x801D2E58: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801D2E5C: beq         $v1, $zero, L_801D2EC4
    if (ctx->r3 == 0) {
        // 0x801D2E60: sh          $t5, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r13;
            goto L_801D2EC4;
    }
    // 0x801D2E60: sh          $t5, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r13;
    // 0x801D2E64: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D2E68: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x801D2E6C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x801D2E70: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801D2E74: lbu         $v0, 0x78($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X78);
    // 0x801D2E78: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801D2E7C: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x801D2E80: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x801D2E84: lbu         $v1, 0x79($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X79);
    // 0x801D2E88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2E8C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x801D2E90: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801D2E94: lbu         $t0, 0x7A($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X7A);
    // 0x801D2E98: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801D2E9C: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x801D2EA0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801D2EA4: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x801D2EA8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801D2EAC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801D2EB0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801D2EB4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x801D2EB8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801D2EBC: jal         0x801CE330
    // 0x801D2EC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801CE330)(rdram, ctx);
        goto after_6;
    // 0x801D2EC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_6:
L_801D2EC4:
    // 0x801D2EC4: lbu         $t9, 0x94($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X94);
    // 0x801D2EC8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801D2ECC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801D2ED0: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801D2ED4: bnel        $at, $zero, L_801D2CFC
    if (ctx->r1 != 0) {
        // 0x801D2ED8: lhu         $t9, 0x92($s1)
        ctx->r25 = MEM_HU(ctx->r17, 0X92);
            goto L_801D2CFC;
    }
    goto skip_2;
    // 0x801D2ED8: lhu         $t9, 0x92($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X92);
    skip_2:
L_801D2EDC:
    // 0x801D2EDC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x801D2EE0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801D2EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2EE8: lhu         $t1, 0x4C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4C);
    // 0x801D2EEC: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x801D2EF0: beql        $t2, $zero, L_801D2F20
    if (ctx->r10 == 0) {
        // 0x801D2EF4: lbu         $t3, 0x7D($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X7D);
            goto L_801D2F20;
    }
    goto skip_3;
    // 0x801D2EF4: lbu         $t3, 0x7D($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X7D);
    skip_3:
    // 0x801D2EF8: sb          $s6, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r22;
    // 0x801D2EFC: jal         0x801CE5B0
    // 0x801D2F00: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_7;
    // 0x801D2F00: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    after_7:
    // 0x801D2F04: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2F08: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D2F0C: jal         0x800058DC
    // 0x801D2F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801D2F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x801D2F14: b           L_801D2F3C
    // 0x801D2F18: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
        goto L_801D2F3C;
    // 0x801D2F18: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x801D2F1C: lbu         $t3, 0x7D($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X7D);
L_801D2F20:
    // 0x801D2F20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D2F24: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2F28: beql        $t3, $zero, L_801D2F3C
    if (ctx->r11 == 0) {
        // 0x801D2F2C: lw          $ra, 0x9C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X9C);
            goto L_801D2F3C;
    }
    goto skip_4;
    // 0x801D2F2C: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    skip_4:
    // 0x801D2F30: jal         0x800058DC
    // 0x801D2F34: addiu       $a1, $a1, 0x2F78
    ctx->r5 = ADD32(ctx->r5, 0X2F78);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801D2F34: addiu       $a1, $a1, 0x2F78
    ctx->r5 = ADD32(ctx->r5, 0X2F78);
    after_9:
    // 0x801D2F38: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
L_801D2F3C:
    // 0x801D2F3C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801D2F40: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x801D2F44: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x801D2F48: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x801D2F4C: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x801D2F50: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x801D2F54: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x801D2F58: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x801D2F5C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x801D2F60: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x801D2F64: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x801D2F68: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x801D2F6C: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x801D2F70: jr          $ra
    // 0x801D2F74: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x801D2F74: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d2f78(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d2f78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2F78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2F80: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D2F84: lhu         $t7, 0x4C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4C);
    // 0x801D2F88: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801D2F8C: bne         $t8, $zero, L_801D2FA8
    if (ctx->r24 != 0) {
        // 0x801D2F90: nop
    
            goto L_801D2FA8;
    }
    // 0x801D2F90: nop

    // 0x801D2F94: lhu         $t9, 0x4C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4C);
    // 0x801D2F98: lhu         $t0, 0x4E($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X4E);
    // 0x801D2F9C: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D2FA0: bnel        $at, $zero, L_801D2FC4
    if (ctx->r1 != 0) {
        // 0x801D2FA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D2FC4;
    }
    goto skip_0;
    // 0x801D2FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_801D2FA8:
    // 0x801D2FA8: jal         0x801CE5B0
    // 0x801D2FAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_0;
    // 0x801D2FAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D2FB0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D2FB8: jal         0x800058DC
    // 0x801D2FBC: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D2FBC: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_1:
    // 0x801D2FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2FC4:
    // 0x801D2FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2FC8: jr          $ra
    // 0x801D2FCC: nop

    return;
    // 0x801D2FCC: nop

;}
RECOMP_FUNC void M8_FUN_801d2fd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2FD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2FD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D2FDC: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801D2FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D2FE4: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D2FE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D2FEC: jal         0x801CE0E8
    // 0x801D2FF0: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D2FF0: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x801D2FF4: bne         $v0, $zero, L_801D3008
    if (ctx->r2 != 0) {
        // 0x801D2FF8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D3008;
    }
    // 0x801D2FF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D2FFC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3000: jal         0x800058DC
    // 0x801D3004: addiu       $a1, $a1, -0x8A8
    ctx->r5 = ADD32(ctx->r5, -0X8A8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D3004: addiu       $a1, $a1, -0x8A8
    ctx->r5 = ADD32(ctx->r5, -0X8A8);
    after_1:
L_801D3008:
    // 0x801D3008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D300C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D3010: jr          $ra
    // 0x801D3014: nop

    return;
    // 0x801D3014: nop

;}
RECOMP_FUNC void M8_FUN_801d3018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D301C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D3020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D3024: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801D3028: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D302C: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D3030: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D3034: jal         0x801CE0E8
    // 0x801D3038: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D3038: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x801D303C: bne         $v0, $zero, L_801D3050
    if (ctx->r2 != 0) {
        // 0x801D3040: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D3050;
    }
    // 0x801D3040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D3044: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3048: jal         0x800058DC
    // 0x801D304C: addiu       $a1, $a1, 0x12FC
    ctx->r5 = ADD32(ctx->r5, 0X12FC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D304C: addiu       $a1, $a1, 0x12FC
    ctx->r5 = ADD32(ctx->r5, 0X12FC);
    after_1:
L_801D3050:
    // 0x801D3050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D3054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D3058: jr          $ra
    // 0x801D305C: nop

    return;
    // 0x801D305C: nop

;}
RECOMP_FUNC void M8_FUN_801d3060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3060: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801D3064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D3068: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801D306C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801D3070: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x801D3074: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    // 0x801D3078: jal         0x8012C6B4
    // 0x801D307C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801D307C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_0:
    // 0x801D3080: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x801D3084: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801D3088: beq         $at, $zero, L_801D30C8
    if (ctx->r1 == 0) {
        // 0x801D308C: andi        $a3, $v0, 0xFFFF
        ctx->r7 = ctx->r2 & 0XFFFF;
            goto L_801D30C8;
    }
    // 0x801D308C: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x801D3090: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D3094: addiu       $t8, $t8, 0x1448
    ctx->r24 = ADD32(ctx->r24, 0X1448);
    // 0x801D3098: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801D309C: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x801D30A0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801D30A4: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x801D30A8: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x801D30AC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801D30B0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x801D30B4: jal         0x8012C6B4
    // 0x801D30B8: sh          $t0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r8;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D30B8: sh          $t0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r8;
    after_1:
    // 0x801D30BC: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x801D30C0: addu        $a3, $sp, $t1
    ctx->r7 = ADD32(ctx->r29, ctx->r9);
    // 0x801D30C4: lhu         $a3, 0x1C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X1C);
L_801D30C8:
    // 0x801D30C8: sll         $t2, $a3, 1
    ctx->r10 = S32(ctx->r7 << 1);
    // 0x801D30CC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801D30D0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801D30D4: lhu         $t3, -0x4384($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4384);
    // 0x801D30D8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x801D30DC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x801D30E0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x801D30E4: jal         0x8013A334
    // 0x801D30E8: sh          $t3, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801D30E8: sh          $t3, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r11;
    after_2:
    // 0x801D30EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x801D30F0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x801D30F4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x801D30F8: jal         0x8013A334
    // 0x801D30FC: lhu         $a3, 0x28($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_3;
    // 0x801D30FC: lhu         $a3, 0x28($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X28);
    after_3:
    // 0x801D3100: jal         0x8012C6B4
    // 0x801D3104: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D3104: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_4:
    // 0x801D3108: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D310C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801D3110: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801D3114: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D3118: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D311C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D3120: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801D3124: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801D3128: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D312C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801D3130: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D3134: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D3138: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801D313C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D3140: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801D3144: jal         0x8012C6B4
    // 0x801D3148: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D3148: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x801D314C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D3150: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801D3154: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801D3158: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D315C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D3160: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D3164: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801D3168: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x801D316C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D3170: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801D3174: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D3178: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D317C: div.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801D3180: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801D3184: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801D3188: jal         0x8012C6B4
    // 0x801D318C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801D318C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x801D3190: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801D3194: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801D3198: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801D319C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D31A0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D31A4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801D31A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D31AC: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x801D31B0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801D31B4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x801D31B8: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801D31BC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D31C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801D31C4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D31C8: div.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x801D31CC: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x801D31D0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D31D4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x801D31D8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801D31DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801D31E0: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801D31E4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x801D31E8: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801D31EC: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x801D31F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D31F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801D31F8: jr          $ra
    // 0x801D31FC: nop

    return;
    // 0x801D31FC: nop

;}
RECOMP_FUNC void M8_FUN_801d3200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3200: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801D3204: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801D3208: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x801D320C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x801D3210: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801D3214: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801D3218: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D321C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D3220: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D3224: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D3228: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D322C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D3230: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801D3234: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D3238: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D323C: addiu       $a1, $sp, 0x5B
    ctx->r5 = ADD32(ctx->r29, 0X5B);
    // 0x801D3240: lw          $s6, 0xC($t6)
    ctx->r22 = MEM_W(ctx->r14, 0XC);
    // 0x801D3244: jal         0x801CE0E8
    // 0x801D3248: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D3248: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    after_0:
    // 0x801D324C: bnel        $v0, $zero, L_801D334C
    if (ctx->r2 != 0) {
        // 0x801D3250: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801D334C;
    }
    goto skip_0;
    // 0x801D3250: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801D3254: lbu         $t7, 0x94($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X94);
    // 0x801D3258: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801D325C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D3260: blez        $t7, L_801D3338
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801D3264: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_801D3338;
    }
    // 0x801D3264: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D3268: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D326C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D3270: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x801D3274: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D3278: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D327C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D3280: addiu       $s5, $s5, -0x2578
    ctx->r21 = ADD32(ctx->r21, -0X2578);
    // 0x801D3284: addiu       $s7, $sp, 0x5C
    ctx->r23 = ADD32(ctx->r29, 0X5C);
L_801D3288:
    // 0x801D3288: jal         0x80006214
    // 0x801D328C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801D328C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x801D3290: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801D3294: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x801D3298: jal         0x801D3060
    // 0x801D329C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    LOOKUP_FUNC(0x801D3060)(rdram, ctx);
        goto after_2;
    // 0x801D329C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
    // 0x801D32A0: jal         0x80006214
    // 0x801D32A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801D32A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x801D32A8: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x801D32AC: addu        $s1, $s5, $t8
    ctx->r17 = ADD32(ctx->r21, ctx->r24);
    // 0x801D32B0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801D32B4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801D32B8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801D32BC: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    // 0x801D32C0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801D32C4: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801D32C8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801D32CC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801D32D0: jal         0x8012C6B4
    // 0x801D32D4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D32D4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x801D32D8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801D32DC: lwc1        $f4, 0x60($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X60);
    // 0x801D32E0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801D32E4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801D32E8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D32EC: add.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = ctx->f16.d + ctx->f20.d;
    // 0x801D32F0: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x801D32F4: div.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f22.d);
    // 0x801D32F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801D32FC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D3300: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D3304: jal         0x8012C6B4
    // 0x801D3308: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D3308: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x801D330C: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x801D3310: bne         $at, $zero, L_801D3320
    if (ctx->r1 != 0) {
        // 0x801D3314: sb          $v0, 0x3B($s0)
        MEM_B(0X3B, ctx->r16) = ctx->r2;
            goto L_801D3320;
    }
    // 0x801D3314: sb          $v0, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r2;
    // 0x801D3318: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801D331C: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
L_801D3320:
    // 0x801D3320: lbu         $t1, 0x94($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X94);
    // 0x801D3324: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801D3328: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801D332C: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801D3330: bne         $at, $zero, L_801D3288
    if (ctx->r1 != 0) {
        // 0x801D3334: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_801D3288;
    }
    // 0x801D3334: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_801D3338:
    // 0x801D3338: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D333C: addiu       $a1, $a1, 0x337C
    ctx->r5 = ADD32(ctx->r5, 0X337C);
    // 0x801D3340: jal         0x800058DC
    // 0x801D3344: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D3344: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x801D3348: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801D334C:
    // 0x801D334C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D3350: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D3354: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D3358: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D335C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D3360: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D3364: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801D3368: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801D336C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x801D3370: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x801D3374: jr          $ra
    // 0x801D3378: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801D3378: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d337c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d337c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D337C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801D3380: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801D3384: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x801D3388: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x801D338C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801D3390: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801D3394: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801D3398: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801D339C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801D33A0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801D33A4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801D33A8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D33AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D33B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D33B4: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801D33B8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D33BC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x801D33C0: jal         0x8012D7A8
    // 0x801D33C4: lw          $s6, 0xC($t6)
    ctx->r22 = MEM_W(ctx->r14, 0XC);
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x801D33C4: lw          $s6, 0xC($t6)
    ctx->r22 = MEM_W(ctx->r14, 0XC);
    after_0:
    // 0x801D33C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801D33CC: jal         0x801CD878
    // 0x801D33D0: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_1;
    // 0x801D33D0: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    after_1:
    // 0x801D33D4: lw          $t7, 0xC($s5)
    ctx->r15 = MEM_W(ctx->r21, 0XC);
    // 0x801D33D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D33DC: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x801D33E0: lhu         $t8, 0x3E($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X3E);
    // 0x801D33E4: bnel        $t8, $at, L_801D33F8
    if (ctx->r24 != ctx->r1) {
        // 0x801D33E8: lbu         $t0, 0x94($s5)
        ctx->r8 = MEM_BU(ctx->r21, 0X94);
            goto L_801D33F8;
    }
    goto skip_0;
    // 0x801D33E8: lbu         $t0, 0x94($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X94);
    skip_0:
    // 0x801D33EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D33F0: sh          $t9, 0x92($s5)
    MEM_H(0X92, ctx->r21) = ctx->r25;
    // 0x801D33F4: lbu         $t0, 0x94($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X94);
L_801D33F8:
    // 0x801D33F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D33FC: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x801D3400: blez        $t0, L_801D3538
    if (SIGNED(ctx->r8) <= 0) {
        // 0x801D3404: lui         $at, 0x4034
        ctx->r1 = S32(0X4034 << 16);
            goto L_801D3538;
    }
    // 0x801D3404: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801D3408: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D340C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D3410: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D3414: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801D3418: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D341C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D3420: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D3424: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D3428: addiu       $fp, $sp, 0x7C
    ctx->r30 = ADD32(ctx->r29, 0X7C);
    // 0x801D342C: lhu         $t1, 0x92($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X92);
L_801D3430:
    // 0x801D3430: bgez        $s2, L_801D3440
    if (SIGNED(ctx->r18) >= 0) {
        // 0x801D3434: sra         $t2, $s2, 1
        ctx->r10 = S32(SIGNED(ctx->r18) >> 1);
            goto L_801D3440;
    }
    // 0x801D3434: sra         $t2, $s2, 1
    ctx->r10 = S32(SIGNED(ctx->r18) >> 1);
    // 0x801D3438: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x801D343C: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_801D3440:
    // 0x801D3440: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801D3444: div         $zero, $t3, $s7
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r23)));
    // 0x801D3448: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801D344C: mfhi        $s3
    ctx->r19 = hi;
    // 0x801D3450: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801D3454: bne         $s7, $zero, L_801D3460
    if (ctx->r23 != 0) {
        // 0x801D3458: nop
    
            goto L_801D3460;
    }
    // 0x801D3458: nop

    // 0x801D345C: break       7
    do_break(2149397596);
L_801D3460:
    // 0x801D3460: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D3464: bne         $s7, $at, L_801D3478
    if (ctx->r23 != ctx->r1) {
        // 0x801D3468: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D3478;
    }
    // 0x801D3468: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D346C: bne         $t3, $at, L_801D3478
    if (ctx->r11 != ctx->r1) {
        // 0x801D3470: nop
    
            goto L_801D3478;
    }
    // 0x801D3470: nop

    // 0x801D3474: break       6
    do_break(2149397620);
L_801D3478:
    // 0x801D3478: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x801D347C: bne         $s3, $zero, L_801D34C8
    if (ctx->r19 != 0) {
        // 0x801D3480: lw          $s0, 0x30($v0)
        ctx->r16 = MEM_W(ctx->r2, 0X30);
            goto L_801D34C8;
    }
    // 0x801D3480: lw          $s0, 0x30($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X30);
    // 0x801D3484: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D3488: sb          $t4, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r12;
    // 0x801D348C: jal         0x80006214
    // 0x801D3490: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D3490: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x801D3494: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x801D3498: addiu       $a2, $a2, -0x2578
    ctx->r6 = ADD32(ctx->r6, -0X2578);
    // 0x801D349C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x801D34A0: jal         0x801D3060
    // 0x801D34A4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(0x801D3060)(rdram, ctx);
        goto after_3;
    // 0x801D34A4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_3:
    // 0x801D34A8: jal         0x80006214
    // 0x801D34AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801D34AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x801D34B0: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801D34B4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801D34B8: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801D34BC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801D34C0: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801D34C4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_801D34C8:
    // 0x801D34C8: slti        $at, $s4, 0xA
    ctx->r1 = SIGNED(ctx->r20) < 0XA ? 1 : 0;
    // 0x801D34CC: beql        $at, $zero, L_801D3524
    if (ctx->r1 == 0) {
        // 0x801D34D0: lbu         $t5, 0x94($s5)
        ctx->r13 = MEM_BU(ctx->r21, 0X94);
            goto L_801D3524;
    }
    goto skip_1;
    // 0x801D34D0: lbu         $t5, 0x94($s5)
    ctx->r13 = MEM_BU(ctx->r21, 0X94);
    skip_1:
    // 0x801D34D4: lwc1        $f10, 0x60($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X60);
    // 0x801D34D8: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x801D34DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D34E0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D34E4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D34E8: mul.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x801D34EC: bgezl       $s3, L_801D3508
    if (SIGNED(ctx->r19) >= 0) {
        // 0x801D34F0: div.d       $f10, $f6, $f24
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f24.d);
            goto L_801D3508;
    }
    goto skip_2;
    // 0x801D34F0: div.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f24.d);
    skip_2:
    // 0x801D34F4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D34F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D34FC: nop

    // 0x801D3500: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
    // 0x801D3504: div.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f24.d);
L_801D3508:
    // 0x801D3508: add.d       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f22.d + ctx->f10.d;
    // 0x801D350C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x801D3510: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x801D3514: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D3518: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D351C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D3520: lbu         $t5, 0x94($s5)
    ctx->r13 = MEM_BU(ctx->r21, 0X94);
L_801D3524:
    // 0x801D3524: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D3528: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801D352C: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D3530: bnel        $at, $zero, L_801D3430
    if (ctx->r1 != 0) {
        // 0x801D3534: lhu         $t1, 0x92($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X92);
            goto L_801D3430;
    }
    goto skip_3;
    // 0x801D3534: lhu         $t1, 0x92($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X92);
    skip_3:
L_801D3538:
    // 0x801D3538: lhu         $v0, 0x92($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X92);
    // 0x801D353C: lhu         $t6, 0x90($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X90);
    // 0x801D3540: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801D3544: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D3548: slt         $v1, $t6, $v0
    ctx->r3 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D354C: bne         $v1, $zero, L_801D3568
    if (ctx->r3 != 0) {
        // 0x801D3550: sh          $t7, 0x92($s5)
        MEM_H(0X92, ctx->r21) = ctx->r15;
            goto L_801D3568;
    }
    // 0x801D3550: sh          $t7, 0x92($s5)
    MEM_H(0X92, ctx->r21) = ctx->r15;
    // 0x801D3554: lw          $t8, 0xC($s5)
    ctx->r24 = MEM_W(ctx->r21, 0XC);
    // 0x801D3558: lhu         $t9, 0x4C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4C);
    // 0x801D355C: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801D3560: beql        $t0, $zero, L_801D3584
    if (ctx->r8 == 0) {
        // 0x801D3564: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801D3584;
    }
    goto skip_4;
    // 0x801D3564: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_4:
L_801D3568:
    // 0x801D3568: jal         0x801CE5B0
    // 0x801D356C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_5;
    // 0x801D356C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    after_5:
    // 0x801D3570: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3574: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D3578: jal         0x800058DC
    // 0x801D357C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D357C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x801D3580: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801D3584:
    // 0x801D3584: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D3588: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D358C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D3590: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801D3594: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801D3598: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801D359C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801D35A0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801D35A4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x801D35A8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x801D35AC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x801D35B0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x801D35B4: jr          $ra
    // 0x801D35B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801D35B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d35bc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d35bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D35BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D35C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801D35C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x801D35C8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x801D35CC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801D35D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801D35D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801D35D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801D35DC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801D35E0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D35E4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D35E8: addiu       $a1, $sp, 0x3B
    ctx->r5 = ADD32(ctx->r29, 0X3B);
    // 0x801D35EC: lw          $s4, 0xC($t6)
    ctx->r20 = MEM_W(ctx->r14, 0XC);
    // 0x801D35F0: jal         0x801CE0E8
    // 0x801D35F4: sb          $zero, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = 0;
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D35F4: sb          $zero, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = 0;
    after_0:
    // 0x801D35F8: bnel        $v0, $zero, L_801D36A0
    if (ctx->r2 != 0) {
        // 0x801D35FC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801D36A0;
    }
    goto skip_0;
    // 0x801D35FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801D3600: lbu         $t7, 0x94($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X94);
    // 0x801D3604: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801D3608: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D360C: blez        $t7, L_801D368C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801D3610: addiu       $s5, $sp, 0x3C
        ctx->r21 = ADD32(ctx->r29, 0X3C);
            goto L_801D368C;
    }
    // 0x801D3610: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
    // 0x801D3614: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x801D3618: addiu       $s2, $s2, -0x2578
    ctx->r18 = ADD32(ctx->r18, -0X2578);
L_801D361C:
    // 0x801D361C: jal         0x80006214
    // 0x801D3620: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801D3620: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x801D3624: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801D3628: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801D362C: jal         0x801D3060
    // 0x801D3630: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    LOOKUP_FUNC(0x801D3060)(rdram, ctx);
        goto after_2;
    // 0x801D3630: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x801D3634: jal         0x80006214
    // 0x801D3638: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801D3638: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x801D363C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x801D3640: addu        $a0, $s2, $t8
    ctx->r4 = ADD32(ctx->r18, ctx->r24);
    // 0x801D3644: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801D3648: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801D364C: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x801D3650: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x801D3654: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x801D3658: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801D365C: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x801D3660: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801D3664: bne         $at, $zero, L_801D3674
    if (ctx->r1 != 0) {
        // 0x801D3668: swc1        $f8, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
            goto L_801D3674;
    }
    // 0x801D3668: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x801D366C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801D3670: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
L_801D3674:
    // 0x801D3674: lbu         $t1, 0x94($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X94);
    // 0x801D3678: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801D367C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801D3680: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801D3684: bne         $at, $zero, L_801D361C
    if (ctx->r1 != 0) {
        // 0x801D3688: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_801D361C;
    }
    // 0x801D3688: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_801D368C:
    // 0x801D368C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3690: addiu       $a1, $a1, 0x36C0
    ctx->r5 = ADD32(ctx->r5, 0X36C0);
    // 0x801D3694: jal         0x800058DC
    // 0x801D3698: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D3698: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x801D369C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801D36A0:
    // 0x801D36A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801D36A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801D36A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801D36AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801D36B0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801D36B4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801D36B8: jr          $ra
    // 0x801D36BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801D36BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d36c0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d36c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D36C0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801D36C4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801D36C8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801D36CC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801D36D0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801D36D4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801D36D8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801D36DC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801D36E0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801D36E4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801D36E8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801D36EC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801D36F0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D36F4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D36F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D36FC: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x801D3700: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D3704: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D3708: jal         0x801CD878
    // 0x801D370C: lw          $s4, 0xC($t6)
    ctx->r20 = MEM_W(ctx->r14, 0XC);
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D370C: lw          $s4, 0xC($t6)
    ctx->r20 = MEM_W(ctx->r14, 0XC);
    after_0:
    // 0x801D3710: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
    // 0x801D3714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D3718: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x801D371C: lhu         $t8, 0x3E($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X3E);
    // 0x801D3720: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x801D3724: addiu       $s7, $s7, -0x2578
    ctx->r23 = ADD32(ctx->r23, -0X2578);
    // 0x801D3728: bne         $t8, $at, L_801D3734
    if (ctx->r24 != ctx->r1) {
        // 0x801D372C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801D3734;
    }
    // 0x801D372C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D3730: sh          $fp, 0x92($s3)
    MEM_H(0X92, ctx->r19) = ctx->r30;
L_801D3734:
    // 0x801D3734: lbu         $t9, 0x94($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X94);
    // 0x801D3738: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x801D373C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D3740: blez        $t9, L_801D38C8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x801D3744: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_801D38C8;
    }
    // 0x801D3744: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801D3748: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D374C: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x801D3750: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D3754: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3758: ldc1        $f22, 0x3650($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X3650);
    // 0x801D375C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D3760: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D3764: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D3768: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D376C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D3770: addiu       $s6, $sp, 0x84
    ctx->r22 = ADD32(ctx->r29, 0X84);
    // 0x801D3774: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x801D3778: lhu         $v0, 0x92($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X92);
L_801D377C:
    // 0x801D377C: bgez        $s2, L_801D378C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x801D3780: sra         $t0, $s2, 1
        ctx->r8 = S32(SIGNED(ctx->r18) >> 1);
            goto L_801D378C;
    }
    // 0x801D3780: sra         $t0, $s2, 1
    ctx->r8 = S32(SIGNED(ctx->r18) >> 1);
    // 0x801D3784: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x801D3788: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_801D378C:
    // 0x801D378C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x801D3790: div         $zero, $t1, $s5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r21)));
    // 0x801D3794: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x801D3798: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x801D379C: mfhi        $v1
    ctx->r3 = hi;
    // 0x801D37A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801D37A4: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x801D37A8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D37AC: bne         $s5, $zero, L_801D37B8
    if (ctx->r21 != 0) {
        // 0x801D37B0: nop
    
            goto L_801D37B8;
    }
    // 0x801D37B0: nop

    // 0x801D37B4: break       7
    do_break(2149398452);
L_801D37B8:
    // 0x801D37B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D37BC: bne         $s5, $at, L_801D37D0
    if (ctx->r21 != ctx->r1) {
        // 0x801D37C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D37D0;
    }
    // 0x801D37C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D37C4: bne         $t1, $at, L_801D37D0
    if (ctx->r9 != ctx->r1) {
        // 0x801D37C8: nop
    
            goto L_801D37D0;
    }
    // 0x801D37C8: nop

    // 0x801D37CC: break       6
    do_break(2149398476);
L_801D37D0:
    // 0x801D37D0: lw          $s0, 0x30($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X30);
    // 0x801D37D4: bnel        $v1, $zero, L_801D3820
    if (ctx->r3 != 0) {
        // 0x801D37D8: lwc1        $f10, 0x8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
            goto L_801D3820;
    }
    goto skip_0;
    // 0x801D37D8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x801D37DC: sb          $fp, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r30;
    // 0x801D37E0: jal         0x80006214
    // 0x801D37E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801D37E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x801D37E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801D37EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801D37F0: jal         0x801D3060
    // 0x801D37F4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    LOOKUP_FUNC(0x801D3060)(rdram, ctx);
        goto after_2;
    // 0x801D37F4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_2:
    // 0x801D37F8: jal         0x80006214
    // 0x801D37FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801D37FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x801D3800: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801D3804: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801D3808: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801D380C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801D3810: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801D3814: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801D3818: lhu         $v0, 0x92($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X92);
    // 0x801D381C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
L_801D3820:
    // 0x801D3820: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801D3824: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D3828: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D382C: bgez        $v0, L_801D3840
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D3830: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801D3840;
    }
    // 0x801D3830: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D3834: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D3838: nop

    // 0x801D383C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801D3840:
    // 0x801D3840: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D3844: lh          $t5, 0x14($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X14);
    // 0x801D3848: mul.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f22.d);
    // 0x801D384C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D3850: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x801D3854: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D3858: sub.d       $f18, $f20, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f20.d - ctx->f10.d;
    // 0x801D385C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D3860: add.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d + ctx->f18.d;
    // 0x801D3864: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D3868: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801D386C: lbu         $t6, 0x94($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X94);
    // 0x801D3870: bgez        $t6, L_801D3880
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D3874: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_801D3880;
    }
    // 0x801D3874: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x801D3878: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x801D387C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_801D3880:
    // 0x801D3880: subu        $t8, $s2, $t7
    ctx->r24 = SUB32(ctx->r18, ctx->r15);
    // 0x801D3884: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801D3888: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x801D388C: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801D3890: sub.d       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f26.d); 
    ctx->f6.d = ctx->f18.d - ctx->f26.d;
    // 0x801D3894: mul.d       $f4, $f24, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f24.d, ctx->f6.d);
    // 0x801D3898: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801D389C: trunc.w.d   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801D38A0: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x801D38A4: nop

    // 0x801D38A8: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    // 0x801D38AC: lh          $t1, 0x14($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X14);
    // 0x801D38B0: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x801D38B4: sh          $t2, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r10;
    // 0x801D38B8: lbu         $t3, 0x94($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X94);
    // 0x801D38BC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801D38C0: bnel        $at, $zero, L_801D377C
    if (ctx->r1 != 0) {
        // 0x801D38C4: lhu         $v0, 0x92($s3)
        ctx->r2 = MEM_HU(ctx->r19, 0X92);
            goto L_801D377C;
    }
    goto skip_1;
    // 0x801D38C4: lhu         $v0, 0x92($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X92);
    skip_1:
L_801D38C8:
    // 0x801D38C8: lhu         $v0, 0x92($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X92);
    // 0x801D38CC: lhu         $t4, 0x90($s3)
    ctx->r12 = MEM_HU(ctx->r19, 0X90);
    // 0x801D38D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D38D4: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801D38D8: slt         $v1, $t4, $v0
    ctx->r3 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D38DC: bne         $v1, $zero, L_801D38F8
    if (ctx->r3 != 0) {
        // 0x801D38E0: sh          $t5, 0x92($s3)
        MEM_H(0X92, ctx->r19) = ctx->r13;
            goto L_801D38F8;
    }
    // 0x801D38E0: sh          $t5, 0x92($s3)
    MEM_H(0X92, ctx->r19) = ctx->r13;
    // 0x801D38E4: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x801D38E8: lhu         $t7, 0x4C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4C);
    // 0x801D38EC: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801D38F0: beql        $t8, $zero, L_801D3914
    if (ctx->r24 == 0) {
        // 0x801D38F4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801D3914;
    }
    goto skip_2;
    // 0x801D38F4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
L_801D38F8:
    // 0x801D38F8: jal         0x801CE5B0
    // 0x801D38FC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_4;
    // 0x801D38FC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    after_4:
    // 0x801D3900: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3904: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D3908: jal         0x800058DC
    // 0x801D390C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801D390C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x801D3910: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801D3914:
    // 0x801D3914: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D3918: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D391C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D3920: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801D3924: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801D3928: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801D392C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801D3930: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801D3934: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801D3938: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801D393C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801D3940: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801D3944: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801D3948: jr          $ra
    // 0x801D394C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801D394C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d3950(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d3950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3950: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D3954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D3958: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D395C: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801D3960: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D3964: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D3968: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D396C: jal         0x801CE0E8
    // 0x801D3970: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D3970: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x801D3974: bne         $v0, $zero, L_801D3988
    if (ctx->r2 != 0) {
        // 0x801D3978: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D3988;
    }
    // 0x801D3978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D397C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3980: jal         0x800058DC
    // 0x801D3984: addiu       $a1, $a1, 0x3998
    ctx->r5 = ADD32(ctx->r5, 0X3998);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D3984: addiu       $a1, $a1, 0x3998
    ctx->r5 = ADD32(ctx->r5, 0X3998);
    after_1:
L_801D3988:
    // 0x801D3988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D398C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D3990: jr          $ra
    // 0x801D3994: nop

    return;
    // 0x801D3994: nop

;}
RECOMP_FUNC void M8_FUN_801d3998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D399C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D39A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D39A4: jal         0x801CD878
    // 0x801D39A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D39A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D39AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D39B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801D39B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D39B8: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D39BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D39C0: blezl       $t6, L_801D3B28
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D39C4: lhu         $v0, 0x92($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X92);
            goto L_801D3B28;
    }
    goto skip_0;
    // 0x801D39C4: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    skip_0:
    // 0x801D39C8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801D39CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D39D0: nop

    // 0x801D39D4: lhu         $t0, 0x92($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X92);
L_801D39D8:
    // 0x801D39D8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801D39DC: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D39E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D39E4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801D39E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801D39EC: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x801D39F0: bgez        $t0, L_801D3A08
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D39F4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D3A08;
    }
    // 0x801D39F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D39F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D39FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D3A00: nop

    // 0x801D3A04: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801D3A08:
    // 0x801D3A08: lhu         $t1, 0x90($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X90);
    // 0x801D3A0C: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x801D3A10: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D3A14: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801D3A18: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x801D3A1C: bgez        $t1, L_801D3A34
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801D3A20: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_801D3A34;
    }
    // 0x801D3A20: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801D3A24: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D3A28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D3A2C: nop

    // 0x801D3A30: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_801D3A34:
    // 0x801D3A34: div.d       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x801D3A38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D3A3C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x801D3A40: nop

    // 0x801D3A44: bc1fl       L_801D3A5C
    if (!c1cs) {
        // 0x801D3A48: sub.d       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f2.d - ctx->f12.d;
            goto L_801D3A5C;
    }
    goto skip_1;
    // 0x801D3A48: sub.d       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f2.d - ctx->f12.d;
    skip_1:
    // 0x801D3A4C: sub.d       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f2.d - ctx->f12.d;
    // 0x801D3A50: b           L_801D3A5C
    // 0x801D3A54: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
        goto L_801D3A5C;
    // 0x801D3A54: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
    // 0x801D3A58: sub.d       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f2.d - ctx->f12.d;
L_801D3A5C:
    // 0x801D3A5C: lbu         $t2, 0x7B($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X7B);
    // 0x801D3A60: sub.d       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f12.d - ctx->f0.d;
    // 0x801D3A64: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801D3A68: bgez        $t2, L_801D3A80
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801D3A6C: cvt.d.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
            goto L_801D3A80;
    }
    // 0x801D3A6C: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D3A70: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D3A74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D3A78: nop

    // 0x801D3A7C: add.d       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f16.d + ctx->f4.d;
L_801D3A80:
    // 0x801D3A80: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x801D3A84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D3A88: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D3A8C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D3A90: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D3A94: nop

    // 0x801D3A98: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x801D3A9C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D3AA0: nop

    // 0x801D3AA4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D3AA8: beql        $t4, $zero, L_801D3AFC
    if (ctx->r12 == 0) {
        // 0x801D3AAC: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_801D3AFC;
    }
    goto skip_2;
    // 0x801D3AAC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x801D3AB0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801D3AB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D3AB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D3ABC: sub.d       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f10.d - ctx->f18.d;
    // 0x801D3AC0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D3AC4: nop

    // 0x801D3AC8: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x801D3ACC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D3AD0: nop

    // 0x801D3AD4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D3AD8: bne         $t4, $zero, L_801D3AF0
    if (ctx->r12 != 0) {
        // 0x801D3ADC: nop
    
            goto L_801D3AF0;
    }
    // 0x801D3ADC: nop

    // 0x801D3AE0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801D3AE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D3AE8: b           L_801D3B08
    // 0x801D3AEC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D3B08;
    // 0x801D3AEC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D3AF0:
    // 0x801D3AF0: b           L_801D3B08
    // 0x801D3AF4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D3B08;
    // 0x801D3AF4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D3AF8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_801D3AFC:
    // 0x801D3AFC: nop

    // 0x801D3B00: bltz        $t4, L_801D3AF0
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D3B04: nop
    
            goto L_801D3AF0;
    }
    // 0x801D3B04: nop

L_801D3B08:
    // 0x801D3B08: sb          $t4, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r12;
    // 0x801D3B0C: lbu         $t5, 0x94($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X94);
    // 0x801D3B10: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801D3B14: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D3B18: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D3B1C: bnel        $at, $zero, L_801D39D8
    if (ctx->r1 != 0) {
        // 0x801D3B20: lhu         $t0, 0x92($a0)
        ctx->r8 = MEM_HU(ctx->r4, 0X92);
            goto L_801D39D8;
    }
    goto skip_3;
    // 0x801D3B20: lhu         $t0, 0x92($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X92);
    skip_3:
    // 0x801D3B24: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
L_801D3B28:
    // 0x801D3B28: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x801D3B2C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D3B30: slt         $v1, $t6, $v0
    ctx->r3 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D3B34: bne         $v1, $zero, L_801D3B50
    if (ctx->r3 != 0) {
        // 0x801D3B38: sh          $t7, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r15;
            goto L_801D3B50;
    }
    // 0x801D3B38: sh          $t7, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r15;
    // 0x801D3B3C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x801D3B40: lhu         $t9, 0x4C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4C);
    // 0x801D3B44: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801D3B48: beql        $t0, $zero, L_801D3B6C
    if (ctx->r8 == 0) {
        // 0x801D3B4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D3B6C;
    }
    goto skip_4;
    // 0x801D3B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
L_801D3B50:
    // 0x801D3B50: jal         0x801CE5B0
    // 0x801D3B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D3B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D3B58: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D3B60: jal         0x800058DC
    // 0x801D3B64: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D3B64: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D3B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D3B6C:
    // 0x801D3B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D3B70: jr          $ra
    // 0x801D3B74: nop

    return;
    // 0x801D3B74: nop

;}
RECOMP_FUNC void M8_FUN_801d3b78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3B78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D3B7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D3B80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D3B84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D3B88: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801D3B8C: jal         0x8012C6B4
    // 0x801D3B90: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801D3B90: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x801D3B94: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D3B98: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D3B9C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D3BA0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D3BA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D3BA8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801D3BAC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801D3BB0: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801D3BB4: lwc1        $f16, 0x70($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X70);
    // 0x801D3BB8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D3BBC: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801D3BC0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801D3BC4: jal         0x8012C6B4
    // 0x801D3BC8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D3BC8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x801D3BCC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D3BD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3BD4: ldc1        $f10, 0x3658($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3658);
    // 0x801D3BD8: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D3BDC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D3BE0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D3BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D3BE8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801D3BEC: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x801D3BF0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801D3BF4: lwc1        $f8, 0x6C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x801D3BF8: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801D3BFC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801D3C00: add.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f6.d + ctx->f16.d;
    // 0x801D3C04: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D3C08: jal         0x8012C6B4
    // 0x801D3C0C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801D3C0C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x801D3C10: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D3C14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3C18: ldc1        $f6, 0x3660($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3660);
    // 0x801D3C1C: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D3C20: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D3C24: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D3C28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D3C2C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x801D3C30: sub.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d - ctx->f6.d;
    // 0x801D3C34: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x801D3C38: lwc1        $f4, 0x74($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X74);
    // 0x801D3C3C: div.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x801D3C40: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D3C44: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x801D3C48: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x801D3C4C: jal         0x8012C6B4
    // 0x801D3C50: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D3C50: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x801D3C54: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x801D3C58: jal         0x8012C6B4
    // 0x801D3C5C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D3C5C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_4:
    // 0x801D3C60: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // 0x801D3C64: jal         0x8012C6B4
    // 0x801D3C68: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D3C68: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_5:
    // 0x801D3C6C: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x801D3C70: jal         0x8012C6B4
    // 0x801D3C74: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801D3C74: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_6:
    // 0x801D3C78: addiu       $t9, $v0, 0x32
    ctx->r25 = ADD32(ctx->r2, 0X32);
    // 0x801D3C7C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801D3C80: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801D3C84: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801D3C88: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D3C8C: lwc1        $f18, 0x60($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X60);
    // 0x801D3C90: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D3C94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D3C98: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801D3C9C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801D3CA0: div.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f16.d);
    // 0x801D3CA4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801D3CA8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D3CAC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D3CB0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D3CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3CB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D3CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D3CC0: jr          $ra
    // 0x801D3CC4: nop

    return;
    // 0x801D3CC4: nop

;}
RECOMP_FUNC void M8_FUN_801d3cc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3CC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801D3CCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801D3CD0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801D3CD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D3CD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801D3CDC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D3CE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D3CE4: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    // 0x801D3CE8: jal         0x801CE0E8
    // 0x801D3CEC: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D3CEC: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    after_0:
    // 0x801D3CF0: bnel        $v0, $zero, L_801D3D48
    if (ctx->r2 != 0) {
        // 0x801D3CF4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D3D48;
    }
    goto skip_0;
    // 0x801D3CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801D3CF8: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801D3CFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801D3D00: blez        $t6, L_801D3D34
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D3D04: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801D3D34;
    }
    // 0x801D3D04: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_801D3D08:
    // 0x801D3D08: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801D3D0C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D3D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D3D14: jal         0x801D3B78
    // 0x801D3D18: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x801D3B78)(rdram, ctx);
        goto after_1;
    // 0x801D3D18: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    after_1:
    // 0x801D3D1C: lbu         $t0, 0x94($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X94);
    // 0x801D3D20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801D3D24: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801D3D28: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801D3D2C: bnel        $at, $zero, L_801D3D08
    if (ctx->r1 != 0) {
        // 0x801D3D30: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801D3D08;
    }
    goto skip_1;
    // 0x801D3D30: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_1:
L_801D3D34:
    // 0x801D3D34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3D38: addiu       $a1, $a1, 0x3D5C
    ctx->r5 = ADD32(ctx->r5, 0X3D5C);
    // 0x801D3D3C: jal         0x800058DC
    // 0x801D3D40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D3D40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801D3D44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D3D48:
    // 0x801D3D48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D3D4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3D50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801D3D54: jr          $ra
    // 0x801D3D58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801D3D58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d3d5c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d3d5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3D5C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801D3D60: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801D3D64: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x801D3D68: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801D3D6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D3D70: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801D3D74: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801D3D78: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801D3D7C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801D3D80: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x801D3D84: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x801D3D88: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801D3D8C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D3D90: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D3D94: jal         0x801CD878
    // 0x801D3D98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D3D98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x801D3D9C: lbu         $v1, 0x94($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X94);
    // 0x801D3DA0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D3DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D3DA8: blez        $v1, L_801D3F60
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801D3DAC: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D3F60;
    }
    // 0x801D3DAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3DB0: lwc1        $f30, 0x3668($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X3668);
    // 0x801D3DB4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801D3DB8: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801D3DBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3DC0: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801D3DC4: mtc1        $zero, $f27
    ctx->f_odd[(27 - 1) * 2] = 0;
    // 0x801D3DC8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D3DCC: ldc1        $f24, 0x3670($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X3670);
    // 0x801D3DD0: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_801D3DD4:
    // 0x801D3DD4: div         $zero, $v1, $s3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r19)));
    // 0x801D3DD8: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x801D3DDC: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x801D3DE0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D3DE4: mflo        $t0
    ctx->r8 = lo;
    // 0x801D3DE8: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x801D3DEC: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D3DF0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x801D3DF4: lh          $t9, 0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10);
    // 0x801D3DF8: bne         $s3, $zero, L_801D3E04
    if (ctx->r19 != 0) {
        // 0x801D3DFC: nop
    
            goto L_801D3E04;
    }
    // 0x801D3DFC: nop

    // 0x801D3E00: break       7
    do_break(2149400064);
L_801D3E04:
    // 0x801D3E04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D3E08: bne         $s3, $at, L_801D3E1C
    if (ctx->r19 != ctx->r1) {
        // 0x801D3E0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D3E1C;
    }
    // 0x801D3E0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D3E10: bne         $v1, $at, L_801D3E1C
    if (ctx->r3 != ctx->r1) {
        // 0x801D3E14: nop
    
            goto L_801D3E1C;
    }
    // 0x801D3E14: nop

    // 0x801D3E18: break       6
    do_break(2149400088);
L_801D3E1C:
    // 0x801D3E1C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x801D3E20: sh          $t3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r11;
    // 0x801D3E24: lh          $t4, 0x10($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X10);
    // 0x801D3E28: lh          $t6, 0x12($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X12);
    // 0x801D3E2C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D3E30: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x801D3E34: sh          $t5, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r13;
    // 0x801D3E38: lbu         $t7, 0x94($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X94);
    // 0x801D3E3C: lh          $t4, 0x14($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X14);
    // 0x801D3E40: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D3E44: bgez        $t7, L_801D3E54
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D3E48: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_801D3E54;
    }
    // 0x801D3E48: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x801D3E4C: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x801D3E50: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801D3E54:
    // 0x801D3E54: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x801D3E58: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x801D3E5C: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x801D3E60: sh          $t9, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r25;
    // 0x801D3E64: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x801D3E68: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801D3E6C: sh          $t3, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r11;
    // 0x801D3E70: lbu         $t5, 0x94($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X94);
    // 0x801D3E74: bgez        $t5, L_801D3E84
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801D3E78: sra         $t7, $t5, 2
        ctx->r15 = S32(SIGNED(ctx->r13) >> 2);
            goto L_801D3E84;
    }
    // 0x801D3E78: sra         $t7, $t5, 2
    ctx->r15 = S32(SIGNED(ctx->r13) >> 2);
    // 0x801D3E7C: addiu       $at, $t5, 0x3
    ctx->r1 = ADD32(ctx->r13, 0X3);
    // 0x801D3E80: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_801D3E84:
    // 0x801D3E84: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x801D3E88: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x801D3E8C: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x801D3E90: sh          $t6, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r14;
    // 0x801D3E94: lh          $t1, 0x14($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X14);
    // 0x801D3E98: andi        $t9, $t1, 0x1FFF
    ctx->r25 = ctx->r9 & 0X1FFF;
    // 0x801D3E9C: sh          $t9, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r25;
    // 0x801D3EA0: lwc1        $f6, 0x6C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x801D3EA4: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801D3EA8: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D3EAC: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801D3EB0: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801D3EB4: nop

    // 0x801D3EB8: mul.s       $f18, $f22, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801D3EBC: jal         0x8002FC20
    // 0x801D3EC0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801D3EC0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x801D3EC4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D3EC8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801D3ECC: c.le.d      $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f4.d <= ctx->f26.d;
    // 0x801D3ED0: nop

    // 0x801D3ED4: bc1fl       L_801D3EE4
    if (!c1cs) {
        // 0x801D3ED8: cvt.d.s     $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
            goto L_801D3EE4;
    }
    goto skip_0;
    // 0x801D3ED8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    skip_0:
    // 0x801D3EDC: mov.s       $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    ctx->f2.fl = ctx->f30.fl;
    // 0x801D3EE0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
L_801D3EE4:
    // 0x801D3EE4: c.lt.d      $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f28.d < ctx->f6.d;
    // 0x801D3EE8: nop

    // 0x801D3EEC: bc1fl       L_801D3F0C
    if (!c1cs) {
        // 0x801D3EF0: div.s       $f20, $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
            goto L_801D3F0C;
    }
    goto skip_1;
    // 0x801D3EF0: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    skip_1:
    // 0x801D3EF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D3EF8: jal         0x801D3B78
    // 0x801D3EFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D3B78)(rdram, ctx);
        goto after_2;
    // 0x801D3EFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801D3F00: b           L_801D3F4C
    // 0x801D3F04: lbu         $v1, 0x94($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X94);
        goto L_801D3F4C;
    // 0x801D3F04: lbu         $v1, 0x94($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X94);
    // 0x801D3F08: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
L_801D3F0C:
    // 0x801D3F0C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D3F10: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D3F14: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D3F18: div.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f2.fl);
    // 0x801D3F1C: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x801D3F20: mul.d       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f24.d);
    // 0x801D3F24: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801D3F28: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801D3F2C: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x801D3F30: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801D3F34: mul.d       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f24.d);
    // 0x801D3F38: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x801D3F3C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801D3F40: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801D3F44: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801D3F48: lbu         $v1, 0x94($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X94);
L_801D3F4C:
    // 0x801D3F4C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D3F50: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801D3F54: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D3F58: bne         $at, $zero, L_801D3DD4
    if (ctx->r1 != 0) {
        // 0x801D3F5C: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_801D3DD4;
    }
    // 0x801D3F5C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801D3F60:
    // 0x801D3F60: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801D3F64: lhu         $t2, 0x90($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X90);
    // 0x801D3F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D3F6C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801D3F70: slt         $v1, $t2, $v0
    ctx->r3 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D3F74: bne         $v1, $zero, L_801D3F90
    if (ctx->r3 != 0) {
        // 0x801D3F78: sh          $t3, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r11;
            goto L_801D3F90;
    }
    // 0x801D3F78: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    // 0x801D3F7C: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x801D3F80: lhu         $t7, 0x4C($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X4C);
    // 0x801D3F84: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801D3F88: beql        $t8, $zero, L_801D3FAC
    if (ctx->r24 == 0) {
        // 0x801D3F8C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801D3FAC;
    }
    goto skip_2;
    // 0x801D3F8C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
L_801D3F90:
    // 0x801D3F90: jal         0x801CE5B0
    // 0x801D3F94: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D3F94: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x801D3F98: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D3F9C: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D3FA0: jal         0x800058DC
    // 0x801D3FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D3FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801D3FA8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801D3FAC:
    // 0x801D3FAC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D3FB0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D3FB4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D3FB8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801D3FBC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x801D3FC0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x801D3FC4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801D3FC8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801D3FCC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801D3FD0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801D3FD4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801D3FD8: jr          $ra
    // 0x801D3FDC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801D3FDC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d3fe0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d3fe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3FE0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x801D3FE4: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801D3FE8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D3FEC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801D3FF0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801D3FF4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D3FF8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801D3FFC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801D4000: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801D4004: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801D4008: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801D400C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D4010: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D4014: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D4018: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D401C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D4020: sb          $zero, 0x8D($sp)
    MEM_B(0X8D, ctx->r29) = 0;
    // 0x801D4024: jal         0x801CE0E8
    // 0x801D4028: addiu       $a1, $sp, 0x8D
    ctx->r5 = ADD32(ctx->r29, 0X8D);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D4028: addiu       $a1, $sp, 0x8D
    ctx->r5 = ADD32(ctx->r29, 0X8D);
    after_0:
    // 0x801D402C: bnel        $v0, $zero, L_801D4284
    if (ctx->r2 != 0) {
        // 0x801D4030: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801D4284;
    }
    goto skip_0;
    // 0x801D4030: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x801D4034: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4038: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D403C: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x801D4040: blez        $v0, L_801D4270
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801D4044: nop
    
            goto L_801D4270;
    }
    // 0x801D4044: nop

    // 0x801D4048: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x801D404C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D4050: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801D4054: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D4058: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D405C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801D4060: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801D4064: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D4068: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_801D406C:
    // 0x801D406C: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x801D4070: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D4074: bgez        $s1, L_801D408C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801D4078: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D408C;
    }
    // 0x801D4078: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D407C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D4080: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D4084: nop

    // 0x801D4088: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D408C:
    // 0x801D408C: add.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f6.d + ctx->f24.d;
    // 0x801D4090: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D4094: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D4098: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801D409C: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D40A0: bgez        $v0, L_801D40B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D40A4: cvt.d.s     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
            goto L_801D40B8;
    }
    // 0x801D40A4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D40A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D40AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D40B0: nop

    // 0x801D40B4: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_801D40B8:
    // 0x801D40B8: add.d       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f8.d + ctx->f24.d;
    // 0x801D40BC: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x801D40C0: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x801D40C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D40C8: div.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f10.d);
    // 0x801D40CC: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D40D0: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D40D4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D40D8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D40DC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D40E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D40E4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D40E8: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x801D40EC: cvt.d.s     $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f22.d = CVT_D_S(ctx->f2.fl);
    // 0x801D40F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D40F4: mul.d       $f8, $f30, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = MUL_D(ctx->f30.d, ctx->f22.d);
    // 0x801D40F8: add.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f6.d + ctx->f8.d;
    // 0x801D40FC: mul.d       $f0, $f22, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f22.d, ctx->f16.d);
    // 0x801D4100: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x801D4104: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801D4108: c.lt.d      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.d < ctx->f28.d;
    // 0x801D410C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x801D4110: bc1f        L_801D4124
    if (!c1cs) {
        // 0x801D4114: trunc.w.s   $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
            goto L_801D4124;
    }
    // 0x801D4114: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801D4118: sub.d       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f28.d); 
    ctx->f20.d = ctx->f0.d - ctx->f28.d;
    // 0x801D411C: b           L_801D4128
    // 0x801D4120: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
        goto L_801D4128;
    // 0x801D4120: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_801D4124:
    // 0x801D4124: sub.d       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f28.d); 
    ctx->f20.d = ctx->f0.d - ctx->f28.d;
L_801D4128:
    // 0x801D4128: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x801D412C: nop

    // 0x801D4130: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801D4134: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801D4138: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D413C: jal         0x8001EAD0
    // 0x801D4140: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D4140: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D4144: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4148: ldc1        $f18, 0x3678($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X3678);
    // 0x801D414C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D4150: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D4154: mul.d       $f10, $f20, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f18.d);
    // 0x801D4158: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D415C: add.d       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = ctx->f10.d + ctx->f24.d;
    // 0x801D4160: cvt.s.d     $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f26.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4164: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x801D4168: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D416C: jal         0x8001EB64
    // 0x801D4170: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D4170: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x801D4174: mul.s       $f10, $f26, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x801D4178: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D417C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4180: sll         $t0, $s3, 8
    ctx->r8 = S32(ctx->r19 << 8);
    // 0x801D4184: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D4188: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D418C: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801D4190: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x801D4194: lwc1        $f4, 0x60($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X60);
    // 0x801D4198: ldc1        $f18, 0x3680($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X3680);
    // 0x801D419C: sh          $t0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r8;
    // 0x801D41A0: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x801D41A4: lh          $t1, 0x12($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X12);
    // 0x801D41A8: sub.d       $f16, $f24, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f24.d - ctx->f22.d;
    // 0x801D41AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D41B0: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x801D41B4: sh          $t2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r10;
    // 0x801D41B8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D41BC: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D41C0: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x801D41C4: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x801D41C8: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x801D41CC: ldc1        $f4, 0x3688($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X3688);
    // 0x801D41D0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D41D4: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x801D41D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D41DC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D41E0: nop

    // 0x801D41E4: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x801D41E8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D41EC: nop

    // 0x801D41F0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D41F4: beql        $t4, $zero, L_801D4248
    if (ctx->r12 == 0) {
        // 0x801D41F8: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_801D4248;
    }
    goto skip_1;
    // 0x801D41F8: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801D41FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D4200: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D4204: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D4208: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x801D420C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D4210: nop

    // 0x801D4214: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x801D4218: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D421C: nop

    // 0x801D4220: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D4224: bne         $t4, $zero, L_801D423C
    if (ctx->r12 != 0) {
        // 0x801D4228: nop
    
            goto L_801D423C;
    }
    // 0x801D4228: nop

    // 0x801D422C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x801D4230: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D4234: b           L_801D4254
    // 0x801D4238: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D4254;
    // 0x801D4238: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D423C:
    // 0x801D423C: b           L_801D4254
    // 0x801D4240: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D4254;
    // 0x801D4240: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D4244: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_801D4248:
    // 0x801D4248: nop

    // 0x801D424C: bltz        $t4, L_801D423C
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D4250: nop
    
            goto L_801D423C;
    }
    // 0x801D4250: nop

L_801D4254:
    // 0x801D4254: sb          $t4, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r12;
    // 0x801D4258: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x801D425C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D4260: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D4264: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D4268: bne         $at, $zero, L_801D406C
    if (ctx->r1 != 0) {
        // 0x801D426C: or          $s3, $s1, $zero
        ctx->r19 = ctx->r17 | 0;
            goto L_801D406C;
    }
    // 0x801D426C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_801D4270:
    // 0x801D4270: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4274: addiu       $a1, $a1, 0x42BC
    ctx->r5 = ADD32(ctx->r5, 0X42BC);
    // 0x801D4278: jal         0x800058DC
    // 0x801D427C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D427C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x801D4280: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801D4284:
    // 0x801D4284: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D4288: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D428C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D4290: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D4294: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D4298: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801D429C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801D42A0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801D42A4: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801D42A8: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801D42AC: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801D42B0: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801D42B4: jr          $ra
    // 0x801D42B8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x801D42B8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d42bc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d42bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D42BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D42C0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801D42C4: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801D42C8: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801D42CC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801D42D0: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801D42D4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801D42D8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801D42DC: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801D42E0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801D42E4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801D42E8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D42EC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D42F0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D42F4: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    // 0x801D42F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D42FC: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D4300: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D4304: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D4308: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D430C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D4310: lhu         $a2, 0x90($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X90);
    // 0x801D4314: bgez        $v0, L_801D4330
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D4318: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D4330;
    }
    // 0x801D4318: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D431C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D4320: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D4324: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D4328: nop

    // 0x801D432C: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D4330:
    // 0x801D4330: add.d       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f6.d + ctx->f22.d;
    // 0x801D4334: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x801D4338: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D433C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801D4340: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D4344: bgez        $a2, L_801D435C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x801D4348: cvt.d.s     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
            goto L_801D435C;
    }
    // 0x801D4348: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D434C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D4350: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D4354: nop

    // 0x801D4358: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_801D435C:
    // 0x801D435C: add.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f8.d + ctx->f22.d;
    // 0x801D4360: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D4364: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4368: div.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f10.d);
    // 0x801D436C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4370: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x801D4374: lbu         $v1, 0x94($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X94);
    // 0x801D4378: blezl       $v1, L_801D45A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801D437C: slt         $v1, $a2, $v0
        ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_801D45A4;
    }
    goto skip_0;
    // 0x801D437C: slt         $v1, $a2, $v0
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x801D4380: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x801D4384: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D4388: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D438C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801D4390: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D4394: addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
    // 0x801D4398: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
L_801D439C:
    // 0x801D439C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D43A0: bgez        $s1, L_801D43B8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801D43A4: cvt.d.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
            goto L_801D43B8;
    }
    // 0x801D43A4: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D43A8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801D43AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D43B0: nop

    // 0x801D43B4: add.d       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f8.d + ctx->f18.d;
L_801D43B8:
    // 0x801D43B8: add.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f8.d + ctx->f22.d;
    // 0x801D43BC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x801D43C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D43C4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801D43C8: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D43CC: bgez        $v1, L_801D43E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801D43D0: cvt.d.s     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
            goto L_801D43E4;
    }
    // 0x801D43D0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D43D4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D43D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D43DC: nop

    // 0x801D43E0: add.d       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f18.d + ctx->f8.d;
L_801D43E4:
    // 0x801D43E4: add.d       $f10, $f18, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f18.d + ctx->f22.d;
    // 0x801D43E8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x801D43EC: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x801D43F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D43F4: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x801D43F8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x801D43FC: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    // 0x801D4400: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D4404: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x801D4408: lh          $t9, 0x12($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X12);
    // 0x801D440C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801D4410: nop

    // 0x801D4414: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D4418: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D441C: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4420: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801D4424: cvt.d.s     $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.d = CVT_D_S(ctx->f2.fl);
    // 0x801D4428: mul.d       $f0, $f24, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.d); NAN_CHECK(ctx->f30.d); 
    ctx->f0.d = MUL_D(ctx->f24.d, ctx->f30.d);
    // 0x801D442C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801D4430: c.lt.d      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d < ctx->f26.d;
    // 0x801D4434: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801D4438: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801D443C: nop

    // 0x801D4440: sh          $t1, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r9;
    // 0x801D4444: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x801D4448: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801D444C: bc1f        L_801D4460
    if (!c1cs) {
        // 0x801D4450: sh          $t3, 0x12($s0)
        MEM_H(0X12, ctx->r16) = ctx->r11;
            goto L_801D4460;
    }
    // 0x801D4450: sh          $t3, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r11;
    // 0x801D4454: sub.d       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f20.d = ctx->f0.d - ctx->f26.d;
    // 0x801D4458: b           L_801D4464
    // 0x801D445C: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
        goto L_801D4464;
    // 0x801D445C: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_801D4460:
    // 0x801D4460: sub.d       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f26.d); 
    ctx->f20.d = ctx->f0.d - ctx->f26.d;
L_801D4464:
    // 0x801D4464: mul.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801D4468: lhu         $t4, 0x92($s3)
    ctx->r12 = MEM_HU(ctx->r19, 0X92);
    // 0x801D446C: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D4470: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801D4474: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801D4478: mflo        $t7
    ctx->r15 = lo;
    // 0x801D447C: addu        $s2, $t7, $t1
    ctx->r18 = ADD32(ctx->r15, ctx->r9);
    // 0x801D4480: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801D4484: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801D4488: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D448C: jal         0x8001EAD0
    // 0x801D4490: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801D4490: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801D4494: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4498: ldc1        $f4, 0x3690($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X3690);
    // 0x801D449C: lwc1        $f18, 0x6C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x801D44A0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D44A4: mul.d       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x801D44A8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D44AC: add.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f10.d + ctx->f22.d;
    // 0x801D44B0: cvt.s.d     $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f28.fl = CVT_S_D(ctx->f16.d);
    // 0x801D44B4: mul.s       $f6, $f0, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x801D44B8: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x801D44BC: jal         0x8001EB64
    // 0x801D44C0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801D44C0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x801D44C4: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x801D44C8: lwc1        $f10, 0x74($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X74);
    // 0x801D44CC: sub.d       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f24.d); 
    ctx->f6.d = ctx->f22.d - ctx->f24.d;
    // 0x801D44D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D44D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D44D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D44DC: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801D44E0: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x801D44E4: ldc1        $f18, 0x3698($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X3698);
    // 0x801D44E8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D44EC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x801D44F0: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801D44F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801D44F8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801D44FC: nop

    // 0x801D4500: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x801D4504: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801D4508: nop

    // 0x801D450C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801D4510: beql        $a0, $zero, L_801D4564
    if (ctx->r4 == 0) {
        // 0x801D4514: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801D4564;
    }
    goto skip_1;
    // 0x801D4514: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801D4518: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D451C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D4520: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D4524: sub.d       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f8.d - ctx->f4.d;
    // 0x801D4528: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801D452C: nop

    // 0x801D4530: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x801D4534: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801D4538: nop

    // 0x801D453C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801D4540: bne         $a0, $zero, L_801D4558
    if (ctx->r4 != 0) {
        // 0x801D4544: nop
    
            goto L_801D4558;
    }
    // 0x801D4544: nop

    // 0x801D4548: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801D454C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D4550: b           L_801D4570
    // 0x801D4554: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801D4570;
    // 0x801D4554: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801D4558:
    // 0x801D4558: b           L_801D4570
    // 0x801D455C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801D4570;
    // 0x801D455C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801D4560: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801D4564:
    // 0x801D4564: nop

    // 0x801D4568: bltz        $a0, L_801D4558
    if (SIGNED(ctx->r4) < 0) {
        // 0x801D456C: nop
    
            goto L_801D4558;
    }
    // 0x801D456C: nop

L_801D4570:
    // 0x801D4570: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801D4574: jal         0x801CD500
    // 0x801D4578: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_2;
    // 0x801D4578: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_2:
    // 0x801D457C: sb          $v0, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r2;
    // 0x801D4580: lbu         $v1, 0x94($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X94);
    // 0x801D4584: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D4588: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D458C: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D4590: bnel        $at, $zero, L_801D439C
    if (ctx->r1 != 0) {
        // 0x801D4594: mtc1        $s1, $f6
        ctx->f6.u32l = ctx->r17;
            goto L_801D439C;
    }
    goto skip_2;
    // 0x801D4594: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    skip_2:
    // 0x801D4598: lhu         $v0, 0x92($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X92);
    // 0x801D459C: lhu         $a2, 0x90($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0X90);
    // 0x801D45A0: slt         $v1, $a2, $v0
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_801D45A4:
    // 0x801D45A4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801D45A8: bne         $v1, $zero, L_801D45C0
    if (ctx->r3 != 0) {
        // 0x801D45AC: sh          $t3, 0x92($s3)
        MEM_H(0X92, ctx->r19) = ctx->r11;
            goto L_801D45C0;
    }
    // 0x801D45AC: sh          $t3, 0x92($s3)
    MEM_H(0X92, ctx->r19) = ctx->r11;
    // 0x801D45B0: lw          $t4, 0xC($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XC);
    // 0x801D45B4: lhu         $t5, 0x4C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4C);
    // 0x801D45B8: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801D45BC: beq         $t6, $zero, L_801D45DC
    if (ctx->r14 == 0) {
        // 0x801D45C0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801D45DC;
    }
L_801D45C0:
    // 0x801D45C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D45C4: jal         0x801CE5B0
    // 0x801D45C8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D45C8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x801D45CC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D45D0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D45D4: jal         0x800058DC
    // 0x801D45D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D45D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
L_801D45DC:
    // 0x801D45DC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801D45E0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D45E4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D45E8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D45EC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801D45F0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801D45F4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801D45F8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801D45FC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801D4600: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801D4604: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801D4608: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801D460C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801D4610: jr          $ra
    // 0x801D4614: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801D4614: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d4618(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d4618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4618: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801D461C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801D4620: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801D4624: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801D4628: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801D462C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D4630: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801D4634: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801D4638: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801D463C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D4640: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D4644: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D4648: sb          $zero, 0x59($sp)
    MEM_B(0X59, ctx->r29) = 0;
    // 0x801D464C: jal         0x801CE0E8
    // 0x801D4650: addiu       $a1, $sp, 0x59
    ctx->r5 = ADD32(ctx->r29, 0X59);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D4650: addiu       $a1, $sp, 0x59
    ctx->r5 = ADD32(ctx->r29, 0X59);
    after_0:
    // 0x801D4654: bnel        $v0, $zero, L_801D47B8
    if (ctx->r2 != 0) {
        // 0x801D4658: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801D47B8;
    }
    goto skip_0;
    // 0x801D4658: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801D465C: lbu         $v1, 0x94($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4660: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D4664: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D4668: blez        $v1, L_801D47A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801D466C: nop
    
            goto L_801D47A4;
    }
    // 0x801D466C: nop

    // 0x801D4670: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D4674: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D4678: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D467C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4680: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D4684: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D4688: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D468C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D4690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D4694: sll         $t6, $a1, 13
    ctx->r14 = S32(ctx->r5 << 13);
L_801D4698:
    // 0x801D4698: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x801D469C: mflo        $s1
    ctx->r17 = lo;
    // 0x801D46A0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x801D46A4: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x801D46A8: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x801D46AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D46B0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x801D46B4: bne         $v1, $zero, L_801D46C0
    if (ctx->r3 != 0) {
        // 0x801D46B8: nop
    
            goto L_801D46C0;
    }
    // 0x801D46B8: nop

    // 0x801D46BC: break       7
    do_break(2149402300);
L_801D46C0:
    // 0x801D46C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D46C4: bne         $v1, $at, L_801D46D8
    if (ctx->r3 != ctx->r1) {
        // 0x801D46C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D46D8;
    }
    // 0x801D46C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D46CC: bne         $t6, $at, L_801D46D8
    if (ctx->r14 != ctx->r1) {
        // 0x801D46D0: nop
    
            goto L_801D46D8;
    }
    // 0x801D46D0: nop

    // 0x801D46D4: break       6
    do_break(2149402324);
L_801D46D8:
    // 0x801D46D8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x801D46DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D46E0: jal         0x8001EAD0
    // 0x801D46E4: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D46E4: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_1:
    // 0x801D46E8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D46EC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D46F0: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x801D46F4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x801D46F8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D46FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D4700: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D4704: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4708: jal         0x8001EB64
    // 0x801D470C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D470C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x801D4710: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4714: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D4718: mul.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x801D471C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D4720: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D4724: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D4728: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D472C: jal         0x8012C6B4
    // 0x801D4730: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D4730: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x801D4734: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D4738: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D473C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801D4740: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D4744: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D4748: div.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f22.d);
    // 0x801D474C: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801D4750: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D4754: jal         0x8012C6B4
    // 0x801D4758: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D4758: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x801D475C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801D4760: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D4764: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D4768: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D476C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801D4770: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801D4774: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D4778: add.d       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f18.d = ctx->f16.d + ctx->f24.d;
    // 0x801D477C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801D4780: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801D4784: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x801D4788: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D478C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D4790: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x801D4794: lbu         $v1, 0x94($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4798: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D479C: bnel        $at, $zero, L_801D4698
    if (ctx->r1 != 0) {
        // 0x801D47A0: sll         $t6, $a1, 13
        ctx->r14 = S32(ctx->r5 << 13);
            goto L_801D4698;
    }
    goto skip_1;
    // 0x801D47A0: sll         $t6, $a1, 13
    ctx->r14 = S32(ctx->r5 << 13);
    skip_1:
L_801D47A4:
    // 0x801D47A4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D47A8: addiu       $a1, $a1, 0x47E0
    ctx->r5 = ADD32(ctx->r5, 0X47E0);
    // 0x801D47AC: jal         0x800058DC
    // 0x801D47B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801D47B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x801D47B4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801D47B8:
    // 0x801D47B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D47BC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D47C0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D47C4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801D47C8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801D47CC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801D47D0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801D47D4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801D47D8: jr          $ra
    // 0x801D47DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801D47DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d47e0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d47e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D47E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D47E4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D47E8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801D47EC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801D47F0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D47F4: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x801D47F8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801D47FC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801D4800: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801D4804: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801D4808: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801D480C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D4810: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D4814: jal         0x801CD878
    // 0x801D4818: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D4818: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x801D481C: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4820: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D4824: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D4828: blez        $v0, L_801D4974
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801D482C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_801D4974;
    }
    // 0x801D482C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801D4830: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D4834: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x801D4838: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D483C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4840: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D4844: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D4848: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D484C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D4850: addiu       $s5, $zero, 0x180
    ctx->r21 = ADD32(0, 0X180);
    // 0x801D4854: lhu         $t6, 0x92($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X92);
L_801D4858:
    // 0x801D4858: sll         $t8, $s2, 13
    ctx->r24 = S32(ctx->r18 << 13);
    // 0x801D485C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x801D4860: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D4864: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x801D4868: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801D486C: lw          $s0, 0x30($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X30);
    // 0x801D4870: mflo        $t7
    ctx->r15 = lo;
    // 0x801D4874: nop

    // 0x801D4878: nop

    // 0x801D487C: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x801D4880: mflo        $t9
    ctx->r25 = lo;
    // 0x801D4884: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
    // 0x801D4888: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x801D488C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x801D4890: bne         $v0, $zero, L_801D489C
    if (ctx->r2 != 0) {
        // 0x801D4894: nop
    
            goto L_801D489C;
    }
    // 0x801D4894: nop

    // 0x801D4898: break       7
    do_break(2149402776);
L_801D489C:
    // 0x801D489C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D48A0: bne         $v0, $at, L_801D48B4
    if (ctx->r2 != ctx->r1) {
        // 0x801D48A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D48B4;
    }
    // 0x801D48A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D48A8: bne         $t8, $at, L_801D48B4
    if (ctx->r24 != ctx->r1) {
        // 0x801D48AC: nop
    
            goto L_801D48B4;
    }
    // 0x801D48AC: nop

    // 0x801D48B0: break       6
    do_break(2149402800);
L_801D48B4:
    // 0x801D48B4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x801D48B8: jal         0x8001EAD0
    // 0x801D48BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D48BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D48C0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D48C4: lwc1        $f8, 0x6C($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X6C);
    // 0x801D48C8: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801D48CC: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x801D48D0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D48D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D48D8: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D48DC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D48E0: jal         0x8001EB64
    // 0x801D48E4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D48E4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x801D48E8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D48EC: lwc1        $f6, 0x74($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X74);
    // 0x801D48F0: mul.d       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801D48F4: lh          $t3, 0x14($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X14);
    // 0x801D48F8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D48FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D4900: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801D4904: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D4908: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D490C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D4910: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4914: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x801D4918: lbu         $t4, 0x94($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X94);
    // 0x801D491C: bgez        $t4, L_801D492C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801D4920: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_801D492C;
    }
    // 0x801D4920: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x801D4924: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x801D4928: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_801D492C:
    // 0x801D492C: subu        $t6, $s2, $t5
    ctx->r14 = SUB32(ctx->r18, ctx->r13);
    // 0x801D4930: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801D4934: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x801D4938: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D493C: sub.d       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = ctx->f10.d - ctx->f24.d;
    // 0x801D4940: mul.d       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f22.d, ctx->f16.d);
    // 0x801D4944: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x801D4948: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x801D494C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801D4950: nop

    // 0x801D4954: sh          $t7, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r15;
    // 0x801D4958: lh          $t9, 0x14($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X14);
    // 0x801D495C: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801D4960: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    // 0x801D4964: lbu         $v0, 0x94($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4968: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D496C: bnel        $at, $zero, L_801D4858
    if (ctx->r1 != 0) {
        // 0x801D4970: lhu         $t6, 0x92($s4)
        ctx->r14 = MEM_HU(ctx->r20, 0X92);
            goto L_801D4858;
    }
    goto skip_0;
    // 0x801D4970: lhu         $t6, 0x92($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X92);
    skip_0:
L_801D4974:
    // 0x801D4974: lhu         $v0, 0x92($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X92);
    // 0x801D4978: lhu         $t1, 0x90($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0X90);
    // 0x801D497C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801D4980: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801D4984: slt         $v1, $t1, $v0
    ctx->r3 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D4988: bne         $v1, $zero, L_801D49A4
    if (ctx->r3 != 0) {
        // 0x801D498C: sh          $t2, 0x92($s4)
        MEM_H(0X92, ctx->r20) = ctx->r10;
            goto L_801D49A4;
    }
    // 0x801D498C: sh          $t2, 0x92($s4)
    MEM_H(0X92, ctx->r20) = ctx->r10;
    // 0x801D4990: lw          $t3, 0xC($s4)
    ctx->r11 = MEM_W(ctx->r20, 0XC);
    // 0x801D4994: lhu         $t4, 0x4C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4C);
    // 0x801D4998: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x801D499C: beql        $t5, $zero, L_801D49C0
    if (ctx->r13 == 0) {
        // 0x801D49A0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D49C0;
    }
    goto skip_1;
    // 0x801D49A0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
L_801D49A4:
    // 0x801D49A4: jal         0x801CE5B0
    // 0x801D49A8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D49A8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_3:
    // 0x801D49AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D49B0: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D49B4: jal         0x800058DC
    // 0x801D49B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D49B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x801D49BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D49C0:
    // 0x801D49C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D49C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D49C8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D49CC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801D49D0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801D49D4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801D49D8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801D49DC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801D49E0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x801D49E4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x801D49E8: jr          $ra
    // 0x801D49EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801D49EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d49f0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d49f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D49F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D49F4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801D49F8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801D49FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801D4A00: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801D4A04: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801D4A08: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D4A0C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D4A10: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D4A14: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D4A18: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D4A1C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D4A20: sb          $zero, 0x49($sp)
    MEM_B(0X49, ctx->r29) = 0;
    // 0x801D4A24: jal         0x801CE0E8
    // 0x801D4A28: addiu       $a1, $sp, 0x49
    ctx->r5 = ADD32(ctx->r29, 0X49);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D4A28: addiu       $a1, $sp, 0x49
    ctx->r5 = ADD32(ctx->r29, 0X49);
    after_0:
    // 0x801D4A2C: bnel        $v0, $zero, L_801D4B40
    if (ctx->r2 != 0) {
        // 0x801D4A30: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801D4B40;
    }
    goto skip_0;
    // 0x801D4A30: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801D4A34: lbu         $t6, 0x94($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4A38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D4A3C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D4A40: blez        $t6, L_801D4B2C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D4A44: nop
    
            goto L_801D4B2C;
    }
    // 0x801D4A44: nop

    // 0x801D4A48: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D4A4C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4A50: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D4A54: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D4A58: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D4A5C: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_801D4A60:
    // 0x801D4A60: jal         0x8012C6B4
    // 0x801D4A64: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D4A64: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_1:
    // 0x801D4A68: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x801D4A6C: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x801D4A70: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D4A74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D4A78: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D4A7C: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x801D4A80: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D4A84: jal         0x8001EAD0
    // 0x801D4A88: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801D4A88: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    after_2:
    // 0x801D4A8C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4A90: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D4A94: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x801D4A98: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801D4A9C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D4AA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D4AA4: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D4AA8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4AAC: jal         0x8001EB64
    // 0x801D4AB0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801D4AB0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x801D4AB4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4AB8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801D4ABC: mul.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x801D4AC0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D4AC4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D4AC8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D4ACC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4AD0: jal         0x8012C6B4
    // 0x801D4AD4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D4AD4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x801D4AD8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D4ADC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D4AE0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801D4AE4: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D4AE8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D4AEC: div.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f22.d);
    // 0x801D4AF0: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801D4AF4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D4AF8: jal         0x8012C6B4
    // 0x801D4AFC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D4AFC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x801D4B00: lhu         $t0, 0x3E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X3E);
    // 0x801D4B04: sb          $v0, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r2;
    // 0x801D4B08: sb          $s3, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = ctx->r19;
    // 0x801D4B0C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801D4B10: sh          $t1, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r9;
    // 0x801D4B14: lbu         $t2, 0x94($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X94);
    // 0x801D4B18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D4B1C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D4B20: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801D4B24: bne         $at, $zero, L_801D4A60
    if (ctx->r1 != 0) {
        // 0x801D4B28: nop
    
            goto L_801D4A60;
    }
    // 0x801D4B28: nop

L_801D4B2C:
    // 0x801D4B2C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4B30: addiu       $a1, $a1, 0x4B68
    ctx->r5 = ADD32(ctx->r5, 0X4B68);
    // 0x801D4B34: jal         0x800058DC
    // 0x801D4B38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801D4B38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x801D4B3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801D4B40:
    // 0x801D4B40: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D4B44: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D4B48: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D4B4C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D4B50: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4B54: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D4B58: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801D4B5C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801D4B60: jr          $ra
    // 0x801D4B64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801D4B64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d4b68(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d4b68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4B68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D4B6C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D4B70: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801D4B74: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801D4B78: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D4B7C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801D4B80: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801D4B84: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801D4B88: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801D4B8C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801D4B90: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D4B94: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D4B98: jal         0x8012D7A8
    // 0x801D4B9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x801D4B9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x801D4BA0: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801D4BA4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D4BA8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801D4BAC: blezl       $t6, L_801D4D00
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D4BB0: lhu         $v0, 0x92($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X92);
            goto L_801D4D00;
    }
    goto skip_0;
    // 0x801D4BB0: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    skip_0:
    // 0x801D4BB4: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801D4BB8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D4BBC: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D4BC0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4BC4: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D4BC8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801D4BCC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D4BD0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D4BD4: nop

    // 0x801D4BD8: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
L_801D4BDC:
    // 0x801D4BDC: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x801D4BE0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D4BE4: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    // 0x801D4BE8: lbu         $v1, 0x3B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3B);
    // 0x801D4BEC: bnel        $v1, $zero, L_801D4C9C
    if (ctx->r3 != 0) {
        // 0x801D4BF0: mtc1        $v1, $f6
        ctx->f6.u32l = ctx->r3;
            goto L_801D4C9C;
    }
    goto skip_1;
    // 0x801D4BF0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    skip_1:
    // 0x801D4BF4: lbu         $t0, 0x3C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3C);
    // 0x801D4BF8: beql        $t0, $zero, L_801D4C9C
    if (ctx->r8 == 0) {
        // 0x801D4BFC: mtc1        $v1, $f6
        ctx->f6.u32l = ctx->r3;
            goto L_801D4C9C;
    }
    goto skip_2;
    // 0x801D4BFC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    skip_2:
    // 0x801D4C00: jal         0x8012C6B4
    // 0x801D4C04: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D4C04: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_1:
    // 0x801D4C08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D4C0C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D4C10: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x801D4C14: jal         0x8001EAD0
    // 0x801D4C18: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801D4C18: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x801D4C1C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4C20: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x801D4C24: mul.d       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f22.d);
    // 0x801D4C28: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x801D4C2C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D4C30: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D4C34: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D4C38: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4C3C: jal         0x8001EB64
    // 0x801D4C40: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801D4C40: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x801D4C44: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4C48: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801D4C4C: mul.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f22.d);
    // 0x801D4C50: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801D4C54: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D4C58: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D4C5C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4C60: jal         0x8012C6B4
    // 0x801D4C64: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D4C64: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x801D4C68: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D4C6C: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x801D4C70: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801D4C74: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D4C78: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D4C7C: div.d       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f24.d);
    // 0x801D4C80: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x801D4C84: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D4C88: jal         0x8012C6B4
    // 0x801D4C8C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801D4C8C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x801D4C90: sb          $v0, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r2;
    // 0x801D4C94: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801D4C98: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
L_801D4C9C:
    // 0x801D4C9C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D4CA0: bgez        $v1, L_801D4CB8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801D4CA4: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_801D4CB8;
    }
    // 0x801D4CA4: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D4CA8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D4CAC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D4CB0: nop

    // 0x801D4CB4: add.d       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f10.d + ctx->f8.d;
L_801D4CB8:
    // 0x801D4CB8: mul.d       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f26.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f26.d);
    // 0x801D4CBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D4CC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D4CC4: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4CC8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D4CCC: jal         0x801CD5E0
    // 0x801D4CD0: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_6;
    // 0x801D4CD0: nop

    after_6:
    // 0x801D4CD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D4CD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D4CDC: jal         0x801CD728
    // 0x801D4CE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_7;
    // 0x801D4CE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x801D4CE4: lbu         $t1, 0x94($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X94);
    // 0x801D4CE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D4CEC: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801D4CF0: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801D4CF4: bnel        $at, $zero, L_801D4BDC
    if (ctx->r1 != 0) {
        // 0x801D4CF8: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_801D4BDC;
    }
    goto skip_3;
    // 0x801D4CF8: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    skip_3:
    // 0x801D4CFC: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
L_801D4D00:
    // 0x801D4D00: lhu         $t2, 0x90($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X90);
    // 0x801D4D04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D4D08: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801D4D0C: slt         $v1, $t2, $v0
    ctx->r3 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D4D10: bne         $v1, $zero, L_801D4D2C
    if (ctx->r3 != 0) {
        // 0x801D4D14: sh          $t3, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r11;
            goto L_801D4D2C;
    }
    // 0x801D4D14: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    // 0x801D4D18: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x801D4D1C: lhu         $t5, 0x4C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4C);
    // 0x801D4D20: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801D4D24: beql        $t6, $zero, L_801D4D48
    if (ctx->r14 == 0) {
        // 0x801D4D28: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D4D48;
    }
    goto skip_4;
    // 0x801D4D28: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_4:
L_801D4D2C:
    // 0x801D4D2C: jal         0x801CE5B0
    // 0x801D4D30: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_8;
    // 0x801D4D30: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_8:
    // 0x801D4D34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4D38: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D4D3C: jal         0x800058DC
    // 0x801D4D40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801D4D40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x801D4D44: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D4D48:
    // 0x801D4D48: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D4D4C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D4D50: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D4D54: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801D4D58: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801D4D5C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801D4D60: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801D4D64: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801D4D68: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801D4D6C: jr          $ra
    // 0x801D4D70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801D4D70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d4d74(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d4d74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4D74: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D4D78: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x801D4D7C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x801D4D80: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801D4D84: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801D4D88: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D4D8C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x801D4D90: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801D4D94: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801D4D98: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801D4D9C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801D4DA0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801D4DA4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801D4DA8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D4DAC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D4DB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D4DB4: sb          $zero, 0x61($sp)
    MEM_B(0X61, ctx->r29) = 0;
    // 0x801D4DB8: jal         0x801CE0E8
    // 0x801D4DBC: addiu       $a1, $sp, 0x61
    ctx->r5 = ADD32(ctx->r29, 0X61);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D4DBC: addiu       $a1, $sp, 0x61
    ctx->r5 = ADD32(ctx->r29, 0X61);
    after_0:
    // 0x801D4DC0: bnel        $v0, $zero, L_801D4F50
    if (ctx->r2 != 0) {
        // 0x801D4DC4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801D4F50;
    }
    goto skip_0;
    // 0x801D4DC4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801D4DC8: lbu         $t6, 0x94($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X94);
    // 0x801D4DCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D4DD0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801D4DD4: blez        $t6, L_801D4F3C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D4DD8: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_801D4F3C;
    }
    // 0x801D4DD8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D4DDC: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D4DE0: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801D4DE4: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D4DE8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4DEC: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801D4DF0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D4DF4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D4DF8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801D4DFC: addiu       $s7, $zero, 0x18
    ctx->r23 = ADD32(0, 0X18);
    // 0x801D4E00: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
L_801D4E04:
    // 0x801D4E04: jal         0x8012C6B4
    // 0x801D4E08: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801D4E08: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_1:
    // 0x801D4E0C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x801D4E10: addu        $s2, $fp, $t7
    ctx->r18 = ADD32(ctx->r30, ctx->r15);
    // 0x801D4E14: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x801D4E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D4E1C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D4E20: andi        $s5, $v0, 0xFFFF
    ctx->r21 = ctx->r2 & 0XFFFF;
    // 0x801D4E24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D4E28: jal         0x8001EAD0
    // 0x801D4E2C: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801D4E2C: lw          $s0, 0x30($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X30);
    after_2:
    // 0x801D4E30: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4E34: lwc1        $f8, 0x6C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x801D4E38: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801D4E3C: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x801D4E40: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D4E44: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D4E48: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D4E4C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4E50: jal         0x8001EB64
    // 0x801D4E54: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801D4E54: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x801D4E58: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D4E5C: lwc1        $f6, 0x74($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X74);
    // 0x801D4E60: mul.d       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801D4E64: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801D4E68: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D4E6C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D4E70: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D4E74: jal         0x8012C6B4
    // 0x801D4E78: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D4E78: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x801D4E7C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801D4E80: lwc1        $f16, 0x70($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X70);
    // 0x801D4E84: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D4E88: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D4E8C: sub.d       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f6.d - ctx->f22.d;
    // 0x801D4E90: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x801D4E94: div.d       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f24.d);
    // 0x801D4E98: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801D4E9C: bgez        $s1, L_801D4EB8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801D4EA0: add.d       $f4, $f10, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
            goto L_801D4EB8;
    }
    // 0x801D4EA0: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801D4EA4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D4EA8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D4EAC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D4EB0: nop

    // 0x801D4EB4: add.d       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f8.d + ctx->f16.d;
L_801D4EB8:
    // 0x801D4EB8: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801D4EBC: lhu         $t9, 0x3E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X3E);
    // 0x801D4EC0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D4EC4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801D4EC8: sh          $t0, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r8;
    // 0x801D4ECC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801D4ED0: lbu         $t1, 0x94($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X94);
    // 0x801D4ED4: multu       $t1, $s6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D4ED8: mflo        $t2
    ctx->r10 = lo;
    // 0x801D4EDC: nop

    // 0x801D4EE0: nop

    // 0x801D4EE4: div         $zero, $t2, $s7
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r23)));
    // 0x801D4EE8: mflo        $t3
    ctx->r11 = lo;
    // 0x801D4EEC: sb          $t3, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = ctx->r11;
    // 0x801D4EF0: bne         $s7, $zero, L_801D4EFC
    if (ctx->r23 != 0) {
        // 0x801D4EF4: nop
    
            goto L_801D4EFC;
    }
    // 0x801D4EF4: nop

    // 0x801D4EF8: break       7
    do_break(2149404408);
L_801D4EFC:
    // 0x801D4EFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D4F00: bne         $s7, $at, L_801D4F14
    if (ctx->r23 != ctx->r1) {
        // 0x801D4F04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D4F14;
    }
    // 0x801D4F04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D4F08: bne         $t2, $at, L_801D4F14
    if (ctx->r10 != ctx->r1) {
        // 0x801D4F0C: nop
    
            goto L_801D4F14;
    }
    // 0x801D4F0C: nop

    // 0x801D4F10: break       6
    do_break(2149404432);
L_801D4F14:
    // 0x801D4F14: blezl       $s4, L_801D4F28
    if (SIGNED(ctx->r20) <= 0) {
        // 0x801D4F18: lbu         $t5, 0x94($s3)
        ctx->r13 = MEM_BU(ctx->r19, 0X94);
            goto L_801D4F28;
    }
    goto skip_1;
    // 0x801D4F18: lbu         $t5, 0x94($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X94);
    skip_1:
    // 0x801D4F1C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x801D4F20: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
    // 0x801D4F24: lbu         $t5, 0x94($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X94);
L_801D4F28:
    // 0x801D4F28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D4F2C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D4F30: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D4F34: bne         $at, $zero, L_801D4E04
    if (ctx->r1 != 0) {
        // 0x801D4F38: or          $s4, $s1, $zero
        ctx->r20 = ctx->r17 | 0;
            goto L_801D4E04;
    }
    // 0x801D4F38: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
L_801D4F3C:
    // 0x801D4F3C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4F40: addiu       $a1, $a1, 0x4F88
    ctx->r5 = ADD32(ctx->r5, 0X4F88);
    // 0x801D4F44: jal         0x800058DC
    // 0x801D4F48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801D4F48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x801D4F4C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801D4F50:
    // 0x801D4F50: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D4F54: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D4F58: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D4F5C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801D4F60: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801D4F64: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801D4F68: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801D4F6C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801D4F70: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x801D4F74: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x801D4F78: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x801D4F7C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x801D4F80: jr          $ra
    // 0x801D4F84: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801D4F84: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d4f88(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d4f88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4F88: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D4F8C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D4F90: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x801D4F94: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x801D4F98: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x801D4F9C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x801D4FA0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x801D4FA4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x801D4FA8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801D4FAC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801D4FB0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801D4FB4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D4FB8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D4FBC: lbu         $v1, 0x94($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X94);
    // 0x801D4FC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D4FC4: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x801D4FC8: blez        $v1, L_801D5140
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801D4FCC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801D5140;
    }
    // 0x801D4FCC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D4FD0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801D4FD4: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801D4FD8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801D4FDC: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D4FE0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801D4FE4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D4FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D4FEC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801D4FF0: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
    // 0x801D4FF4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_801D4FF8:
    // 0x801D4FF8: lhu         $t6, 0x92($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X92);
    // 0x801D4FFC: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x801D5000: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801D5004: beq         $at, $zero, L_801D512C
    if (ctx->r1 == 0) {
        // 0x801D5008: addu        $v0, $s7, $t7
        ctx->r2 = ADD32(ctx->r23, ctx->r15);
            goto L_801D512C;
    }
    // 0x801D5008: addu        $v0, $s7, $t7
    ctx->r2 = ADD32(ctx->r23, ctx->r15);
    // 0x801D500C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D5010: sb          $s4, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r20;
    // 0x801D5014: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D5018: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    // 0x801D501C: lbu         $v1, 0x3B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3B);
    // 0x801D5020: bnel        $s5, $v1, L_801D50D4
    if (ctx->r21 != ctx->r3) {
        // 0x801D5024: mtc1        $v1, $f8
        ctx->f8.u32l = ctx->r3;
            goto L_801D50D4;
    }
    goto skip_0;
    // 0x801D5024: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    skip_0:
    // 0x801D5028: lbu         $t0, 0x3C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3C);
    // 0x801D502C: bnel        $s6, $t0, L_801D50D4
    if (ctx->r22 != ctx->r8) {
        // 0x801D5030: mtc1        $v1, $f8
        ctx->f8.u32l = ctx->r3;
            goto L_801D50D4;
    }
    goto skip_1;
    // 0x801D5030: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    skip_1:
    // 0x801D5034: jal         0x8012C6B4
    // 0x801D5038: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801D5038: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_0:
    // 0x801D503C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D5040: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801D5044: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x801D5048: jal         0x8001EAD0
    // 0x801D504C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D504C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D5050: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D5054: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x801D5058: mul.d       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f22.d);
    // 0x801D505C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x801D5060: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D5064: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D5068: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D506C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D5070: jal         0x8001EB64
    // 0x801D5074: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D5074: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x801D5078: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D507C: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801D5080: mul.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f22.d);
    // 0x801D5084: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D5088: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D508C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D5090: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D5094: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801D5098: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D509C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x801D50A0: lbu         $t1, 0x94($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X94);
    // 0x801D50A4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801D50A8: bgez        $t1, L_801D50C0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801D50AC: cvt.d.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
            goto L_801D50C0;
    }
    // 0x801D50AC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D50B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D50B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D50B8: nop

    // 0x801D50BC: add.d       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f10.d + ctx->f16.d;
L_801D50C0:
    // 0x801D50C0: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x801D50C4: lbu         $v1, 0x3B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3B);
    // 0x801D50C8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D50CC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801D50D0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_801D50D4:
    // 0x801D50D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D50D8: bgez        $v1, L_801D50F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801D50DC: cvt.d.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
            goto L_801D50F0;
    }
    // 0x801D50DC: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D50E0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D50E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D50E8: nop

    // 0x801D50EC: add.d       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f16.d + ctx->f6.d;
L_801D50F0:
    // 0x801D50F0: mul.d       $f10, $f16, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f24.d);
    // 0x801D50F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D50F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D50FC: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x801D5100: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D5104: jal         0x801CD5E0
    // 0x801D5108: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_3;
    // 0x801D5108: nop

    after_3:
    // 0x801D510C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D5110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D5114: jal         0x801CD728
    // 0x801D5118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_4;
    // 0x801D5118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x801D511C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D5120: jal         0x8012D40C
    // 0x801D5124: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    LOOKUP_FUNC(0x8012D40C)(rdram, ctx);
        goto after_5;
    // 0x801D5124: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_5:
    // 0x801D5128: lbu         $v1, 0x94($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X94);
L_801D512C:
    // 0x801D512C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D5130: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801D5134: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D5138: bne         $at, $zero, L_801D4FF8
    if (ctx->r1 != 0) {
        // 0x801D513C: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_801D4FF8;
    }
    // 0x801D513C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801D5140:
    // 0x801D5140: lhu         $v0, 0x92($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X92);
    // 0x801D5144: lhu         $t2, 0x90($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X90);
    // 0x801D5148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D514C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x801D5150: slt         $v1, $t2, $v0
    ctx->r3 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D5154: bne         $v1, $zero, L_801D5170
    if (ctx->r3 != 0) {
        // 0x801D5158: sh          $t3, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r11;
            goto L_801D5170;
    }
    // 0x801D5158: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    // 0x801D515C: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x801D5160: lhu         $t5, 0x4C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4C);
    // 0x801D5164: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801D5168: beql        $t6, $zero, L_801D518C
    if (ctx->r14 == 0) {
        // 0x801D516C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D518C;
    }
    goto skip_2;
    // 0x801D516C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
L_801D5170:
    // 0x801D5170: jal         0x801CE5B0
    // 0x801D5174: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_6;
    // 0x801D5174: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_6:
    // 0x801D5178: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D517C: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D5180: jal         0x800058DC
    // 0x801D5184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801D5184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801D5188: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D518C:
    // 0x801D518C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D5190: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D5194: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801D5198: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801D519C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801D51A0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801D51A4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x801D51A8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x801D51AC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x801D51B0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x801D51B4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x801D51B8: jr          $ra
    // 0x801D51BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801D51BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d51c0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d51c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D51C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D51C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D51CC: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x801D51D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D51D4: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D51D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D51DC: jal         0x801CE0E8
    // 0x801D51E0: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D51E0: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x801D51E4: bne         $v0, $zero, L_801D51F8
    if (ctx->r2 != 0) {
        // 0x801D51E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D51F8;
    }
    // 0x801D51E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D51EC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D51F0: jal         0x800058DC
    // 0x801D51F4: addiu       $a1, $a1, 0x5208
    ctx->r5 = ADD32(ctx->r5, 0X5208);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D51F4: addiu       $a1, $a1, 0x5208
    ctx->r5 = ADD32(ctx->r5, 0X5208);
    after_1:
L_801D51F8:
    // 0x801D51F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D51FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D5200: jr          $ra
    // 0x801D5204: nop

    return;
    // 0x801D5204: nop

;}
RECOMP_FUNC void M8_FUN_801d5208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D520C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D5214: jal         0x801CD878
    // 0x801D5218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D5218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D521C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D5220: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801D5224: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801D5228: lbu         $t6, 0x94($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X94);
    // 0x801D522C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5230: blezl       $t6, L_801D52AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801D5234: lhu         $v0, 0x92($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X92);
            goto L_801D52AC;
    }
    goto skip_0;
    // 0x801D5234: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
    skip_0:
    // 0x801D5238: ldc1        $f2, 0x36A0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X36A0);
    // 0x801D523C: lwc1        $f8, 0x60($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
L_801D5240:
    // 0x801D5240: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801D5244: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801D5248: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D524C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D5250: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D5254: mul.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801D5258: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D525C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D5260: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801D5264: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x801D5268: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D526C: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x801D5270: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801D5274: sh          $t1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r9;
    // 0x801D5278: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x801D527C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D5280: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801D5284: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x801D5288: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801D528C: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801D5290: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801D5294: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801D5298: lbu         $t4, 0x94($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X94);
    // 0x801D529C: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x801D52A0: bnel        $at, $zero, L_801D5240
    if (ctx->r1 != 0) {
        // 0x801D52A4: lwc1        $f8, 0x60($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
            goto L_801D5240;
    }
    goto skip_1;
    // 0x801D52A4: lwc1        $f8, 0x60($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
    skip_1:
    // 0x801D52A8: lhu         $v0, 0x92($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X92);
L_801D52AC:
    // 0x801D52AC: lhu         $t5, 0x90($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X90);
    // 0x801D52B0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801D52B4: slt         $v1, $t5, $v0
    ctx->r3 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D52B8: bne         $v1, $zero, L_801D52D4
    if (ctx->r3 != 0) {
        // 0x801D52BC: sh          $t6, 0x92($a0)
        MEM_H(0X92, ctx->r4) = ctx->r14;
            goto L_801D52D4;
    }
    // 0x801D52BC: sh          $t6, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r14;
    // 0x801D52C0: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x801D52C4: lhu         $t8, 0x4C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4C);
    // 0x801D52C8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x801D52CC: beql        $t9, $zero, L_801D52F0
    if (ctx->r25 == 0) {
        // 0x801D52D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D52F0;
    }
    goto skip_2;
    // 0x801D52D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_801D52D4:
    // 0x801D52D4: jal         0x801CE5B0
    // 0x801D52D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_1;
    // 0x801D52D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D52DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D52E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D52E4: jal         0x800058DC
    // 0x801D52E8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D52E8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    after_2:
    // 0x801D52EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D52F0:
    // 0x801D52F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D52F4: jr          $ra
    // 0x801D52F8: nop

    return;
    // 0x801D52F8: nop

;}
RECOMP_FUNC void M8_FUN_801d52fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D52FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D5300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5304: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D5308: sb          $zero, 0x19($sp)
    MEM_B(0X19, ctx->r29) = 0;
    // 0x801D530C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D5310: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x801D5314: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D5318: jal         0x801CE0E8
    // 0x801D531C: addiu       $a1, $sp, 0x19
    ctx->r5 = ADD32(ctx->r29, 0X19);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D531C: addiu       $a1, $sp, 0x19
    ctx->r5 = ADD32(ctx->r29, 0X19);
    after_0:
    // 0x801D5320: bne         $v0, $zero, L_801D5370
    if (ctx->r2 != 0) {
        // 0x801D5324: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801D5370;
    }
    // 0x801D5324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D5328: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D532C: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x801D5330: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5334: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D5338: lwc1        $f4, 0x6C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X6C);
    // 0x801D533C: addiu       $a1, $a1, 0x5380
    ctx->r5 = ADD32(ctx->r5, 0X5380);
    // 0x801D5340: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D5344: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D5348: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x801D534C: lhu         $t2, 0x3E($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X3E);
    // 0x801D5350: lwc1        $f6, 0x70($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X70);
    // 0x801D5354: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801D5358: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801D535C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x801D5360: lwc1        $f8, 0x74($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X74);
    // 0x801D5364: sh          $t3, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = ctx->r11;
    // 0x801D5368: jal         0x800058DC
    // 0x801D536C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D536C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    after_1:
L_801D5370:
    // 0x801D5370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D5374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D5378: jr          $ra
    // 0x801D537C: nop

    return;
    // 0x801D537C: nop

;}
RECOMP_FUNC void M8_FUN_801d5380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5380: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801D5384: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D5388: lbu         $t6, -0x33DF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DF);
    // 0x801D538C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D5390: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D5394: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801D5398: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D539C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801D53A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801D53A4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D53A8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D53AC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D53B0: beq         $t6, $at, L_801D54D4
    if (ctx->r14 == ctx->r1) {
        // 0x801D53B4: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_801D54D4;
    }
    // 0x801D53B4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D53B8: jal         0x801CD878
    // 0x801D53BC: nop

    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D53BC: nop

    after_0:
    // 0x801D53C0: lbu         $t7, 0x94($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X94);
    // 0x801D53C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D53C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801D53CC: blezl       $t7, L_801D548C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801D53D0: lhu         $v0, 0x92($s2)
        ctx->r2 = MEM_HU(ctx->r18, 0X92);
            goto L_801D548C;
    }
    goto skip_0;
    // 0x801D53D0: lhu         $v0, 0x92($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X92);
    skip_0:
    // 0x801D53D4: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D53D8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D53DC: nop

    // 0x801D53E0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
L_801D53E4:
    // 0x801D53E4: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x801D53E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D53EC: lw          $t1, 0xC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0XC);
    // 0x801D53F0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D53F4: lw          $s0, 0x30($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X30);
    // 0x801D53F8: lwc1        $f4, 0x6C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x801D53FC: lbu         $t4, 0x3B($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3B);
    // 0x801D5400: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801D5404: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x801D5408: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801D540C: lwc1        $f6, 0x70($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X70);
    // 0x801D5410: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801D5414: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801D5418: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x801D541C: lwc1        $f8, 0x74($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X74);
    // 0x801D5420: bgez        $t4, L_801D5438
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801D5424: swc1        $f8, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
            goto L_801D5438;
    }
    // 0x801D5424: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801D5428: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801D542C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D5430: nop

    // 0x801D5434: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_801D5438:
    // 0x801D5438: mul.d       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f22.d);
    // 0x801D543C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D5440: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D5444: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    // 0x801D5448: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D544C: jal         0x801CD5E0
    // 0x801D5450: nop

    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801D5450: nop

    after_1:
    // 0x801D5454: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D5458: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D545C: jal         0x801CD728
    // 0x801D5460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801D5460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801D5464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D5468: jal         0x8012D40C
    // 0x801D546C: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8012D40C)(rdram, ctx);
        goto after_3;
    // 0x801D546C: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_3:
    // 0x801D5470: lbu         $t5, 0x94($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X94);
    // 0x801D5474: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D5478: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D547C: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D5480: bnel        $at, $zero, L_801D53E4
    if (ctx->r1 != 0) {
        // 0x801D5484: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_801D53E4;
    }
    goto skip_1;
    // 0x801D5484: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    skip_1:
    // 0x801D5488: lhu         $v0, 0x92($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X92);
L_801D548C:
    // 0x801D548C: lhu         $t6, 0x90($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X90);
    // 0x801D5490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D5494: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D5498: slt         $v1, $t6, $v0
    ctx->r3 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D549C: beq         $v1, $zero, L_801D54A8
    if (ctx->r3 == 0) {
        // 0x801D54A0: sh          $t7, 0x92($s2)
        MEM_H(0X92, ctx->r18) = ctx->r15;
            goto L_801D54A8;
    }
    // 0x801D54A0: sh          $t7, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r15;
    // 0x801D54A4: sh          $zero, 0x92($s2)
    MEM_H(0X92, ctx->r18) = 0;
L_801D54A8:
    // 0x801D54A8: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x801D54AC: lhu         $t9, 0x4C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4C);
    // 0x801D54B0: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801D54B4: beql        $t0, $zero, L_801D54D8
    if (ctx->r8 == 0) {
        // 0x801D54B8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801D54D8;
    }
    goto skip_2;
    // 0x801D54B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x801D54BC: jal         0x801CE5B0
    // 0x801D54C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_4;
    // 0x801D54C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x801D54C4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D54C8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D54CC: jal         0x800058DC
    // 0x801D54D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801D54D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
L_801D54D4:
    // 0x801D54D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801D54D8:
    // 0x801D54D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D54DC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D54E0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D54E4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D54E8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D54EC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D54F0: jr          $ra
    // 0x801D54F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801D54F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d54f8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d54f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D54F8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D54FC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801D5500: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801D5504: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801D5508: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801D550C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801D5510: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801D5514: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801D5518: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801D551C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801D5520: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801D5524: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D5528: sb          $zero, 0x57($sp)
    MEM_B(0X57, ctx->r29) = 0;
    // 0x801D552C: jal         0x801CE0E8
    // 0x801D5530: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_0;
    // 0x801D5530: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    after_0:
    // 0x801D5534: bnel        $v0, $zero, L_801D563C
    if (ctx->r2 != 0) {
        // 0x801D5538: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801D563C;
    }
    goto skip_0;
    // 0x801D5538: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801D553C: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x801D5540: lbu         $v0, 0x94($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X94);
    // 0x801D5544: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801D5548: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801D554C: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x801D5550: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D5554: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801D5558: blez        $v0, L_801D5628
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801D555C: lw          $s4, 0x2C($t8)
        ctx->r20 = MEM_W(ctx->r24, 0X2C);
            goto L_801D5628;
    }
    // 0x801D555C: lw          $s4, 0x2C($t8)
    ctx->r20 = MEM_W(ctx->r24, 0X2C);
    // 0x801D5560: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D5564: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D5568: addiu       $s5, $zero, 0x800
    ctx->r21 = ADD32(0, 0X800);
    // 0x801D556C: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
L_801D5570:
    // 0x801D5570: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D5574: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D5578: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D557C: bgez        $v0, L_801D5590
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D5580: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D5590;
    }
    // 0x801D5580: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D5584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D5588: nop

    // 0x801D558C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_801D5590:
    // 0x801D5590: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801D5594: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801D5598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D559C: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    // 0x801D55A0: sh          $s5, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r21;
    // 0x801D55A4: lh          $t0, 0x12($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X12);
    // 0x801D55A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D55AC: sh          $t0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r8;
    // 0x801D55B0: lwc1        $f18, 0x60($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X60);
    // 0x801D55B4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801D55B8: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x801D55BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D55C0: sub.d       $f16, $f22, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f22.d - ctx->f8.d;
    // 0x801D55C4: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x801D55C8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801D55CC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D55D0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D55D4: jal         0x801CD5E0
    // 0x801D55D8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801D55D8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x801D55DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D55E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801D55E4: jal         0x801CD728
    // 0x801D55E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801D55E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801D55EC: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x801D55F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801D55F4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801D55F8: lwc1        $f10, 0x6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x801D55FC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801D5600: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x801D5604: lwc1        $f18, 0x70($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X70);
    // 0x801D5608: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801D560C: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x801D5610: lwc1        $f8, 0x74($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X74);
    // 0x801D5614: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801D5618: lbu         $v0, 0x94($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X94);
    // 0x801D561C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D5620: bnel        $at, $zero, L_801D5570
    if (ctx->r1 != 0) {
        // 0x801D5624: mtc1        $s2, $f4
        ctx->f4.u32l = ctx->r18;
            goto L_801D5570;
    }
    goto skip_1;
    // 0x801D5624: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    skip_1:
L_801D5628:
    // 0x801D5628: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D562C: addiu       $a1, $a1, 0x5664
    ctx->r5 = ADD32(ctx->r5, 0X5664);
    // 0x801D5630: jal         0x800058DC
    // 0x801D5634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D5634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801D5638: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801D563C:
    // 0x801D563C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D5640: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801D5644: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801D5648: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801D564C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5650: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801D5654: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801D5658: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801D565C: jr          $ra
    // 0x801D5660: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801D5660: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d5664(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d5664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5664: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801D5668: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D566C: lbu         $t6, -0x33DF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DF);
    // 0x801D5670: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801D5674: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801D5678: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801D567C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801D5680: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801D5684: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801D5688: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801D568C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801D5690: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801D5694: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D5698: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D569C: beq         $t6, $at, L_801D588C
    if (ctx->r14 == ctx->r1) {
        // 0x801D56A0: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_801D588C;
    }
    // 0x801D56A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D56A4: jal         0x801CD878
    // 0x801D56A8: nop

    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_0;
    // 0x801D56A8: nop

    after_0:
    // 0x801D56AC: lhu         $v1, 0x92($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X92);
    // 0x801D56B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D56B4: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D56B8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801D56BC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D56C0: lhu         $a0, 0x90($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X90);
    // 0x801D56C4: bgez        $v1, L_801D56E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801D56C8: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D56E0;
    }
    // 0x801D56C8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D56CC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D56D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D56D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D56D8: nop

    // 0x801D56DC: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D56E0:
    // 0x801D56E0: add.d       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f6.d + ctx->f22.d;
    // 0x801D56E4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801D56E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D56EC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801D56F0: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D56F4: bgez        $a0, L_801D570C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801D56F8: cvt.d.s     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
            goto L_801D570C;
    }
    // 0x801D56F8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D56FC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D5700: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D5704: nop

    // 0x801D5708: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_801D570C:
    // 0x801D570C: add.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f8.d + ctx->f22.d;
    // 0x801D5710: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x801D5714: lbu         $v0, 0x94($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X94);
    // 0x801D5718: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D571C: div.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f10.d);
    // 0x801D5720: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801D5724: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801D5728: lw          $s3, 0x2C($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X2C);
    // 0x801D572C: blez        $v0, L_801D5848
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801D5730: cvt.s.d     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
            goto L_801D5848;
    }
    // 0x801D5730: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x801D5734: cvt.d.s     $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.d = CVT_D_S(ctx->f0.fl);
    // 0x801D5738: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
L_801D573C:
    // 0x801D573C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801D5740: bgez        $s1, L_801D575C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801D5744: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D575C;
    }
    // 0x801D5744: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D5748: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D574C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D5750: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D5754: nop

    // 0x801D5758: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D575C:
    // 0x801D575C: add.d       $f18, $f6, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = ctx->f6.d + ctx->f22.d;
    // 0x801D5760: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D5764: bgez        $v0, L_801D577C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801D5768: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_801D577C;
    }
    // 0x801D5768: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801D576C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D5770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D5774: nop

    // 0x801D5778: add.d       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f16.d + ctx->f4.d;
L_801D577C:
    // 0x801D577C: add.d       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f16.d + ctx->f22.d;
    // 0x801D5780: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x801D5784: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x801D5788: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801D578C: div.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f8.d);
    // 0x801D5790: lwc1        $f8, 0x60($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X60);
    // 0x801D5794: lw          $s0, 0x30($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X30);
    // 0x801D5798: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D579C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801D57A0: add.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f6.d + ctx->f24.d;
    // 0x801D57A4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801D57A8: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x801D57AC: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x801D57B0: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x801D57B4: nop

    // 0x801D57B8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801D57BC: nop

    // 0x801D57C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D57C4: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x801D57C8: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801D57CC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D57D0: sub.d       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f22.d - ctx->f10.d;
    // 0x801D57D4: mul.d       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801D57D8: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x801D57DC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801D57E0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D57E4: jal         0x801CD5E0
    // 0x801D57E8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    LOOKUP_FUNC(0x801CD5E0)(rdram, ctx);
        goto after_1;
    // 0x801D57E8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x801D57EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D57F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D57F4: jal         0x801CD728
    // 0x801D57F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CD728)(rdram, ctx);
        goto after_2;
    // 0x801D57F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801D57FC: lh          $t5, 0x12($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X12);
    // 0x801D5800: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D5804: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D5808: sh          $t5, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r13;
    // 0x801D580C: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x801D5810: lwc1        $f18, 0x6C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x801D5814: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801D5818: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x801D581C: lwc1        $f8, 0x70($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X70);
    // 0x801D5820: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801D5824: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x801D5828: lwc1        $f10, 0x74($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X74);
    // 0x801D582C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x801D5830: lbu         $v0, 0x94($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X94);
    // 0x801D5834: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801D5838: bnel        $at, $zero, L_801D573C
    if (ctx->r1 != 0) {
        // 0x801D583C: mtc1        $s1, $f4
        ctx->f4.u32l = ctx->r17;
            goto L_801D573C;
    }
    goto skip_0;
    // 0x801D583C: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    skip_0:
    // 0x801D5840: lhu         $v1, 0x92($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X92);
    // 0x801D5844: lhu         $a0, 0x90($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X90);
L_801D5848:
    // 0x801D5848: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D584C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801D5850: beq         $v0, $zero, L_801D585C
    if (ctx->r2 == 0) {
        // 0x801D5854: sh          $t9, 0x92($s2)
        MEM_H(0X92, ctx->r18) = ctx->r25;
            goto L_801D585C;
    }
    // 0x801D5854: sh          $t9, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r25;
    // 0x801D5858: sh          $zero, 0x92($s2)
    MEM_H(0X92, ctx->r18) = 0;
L_801D585C:
    // 0x801D585C: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x801D5860: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D5864: lhu         $t1, 0x4C($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4C);
    // 0x801D5868: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x801D586C: beql        $t2, $zero, L_801D5890
    if (ctx->r10 == 0) {
        // 0x801D5870: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801D5890;
    }
    goto skip_1;
    // 0x801D5870: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x801D5874: jal         0x801CE5B0
    // 0x801D5878: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_3;
    // 0x801D5878: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x801D587C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5880: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D5884: jal         0x800058DC
    // 0x801D5888: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D5888: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_801D588C:
    // 0x801D588C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801D5890:
    // 0x801D5890: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D5894: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D5898: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D589C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801D58A0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801D58A4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801D58A8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801D58AC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801D58B0: jr          $ra
    // 0x801D58B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801D58B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d58b8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d58b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D58B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D58BC: ldc1        $f4, 0x36A8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X36A8);
    // 0x801D58C0: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x801D58C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801D58C8: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d58cc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d58cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D58CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D58D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D58D4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D58D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801D58DC: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801D58E0: nop

    // 0x801D58E4: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x801D58E8: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801D58EC: nop

    // 0x801D58F0: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801D58F4: beql        $v1, $zero, L_801D5948
    if (ctx->r3 == 0) {
        // 0x801D58F8: mfc1        $v1, $f8
        ctx->r3 = (int32_t)ctx->f8.u32l;
            goto L_801D5948;
    }
    goto skip_0;
    // 0x801D58F8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801D58FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D5900: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D5904: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801D5908: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x801D590C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801D5910: nop

    // 0x801D5914: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x801D5918: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801D591C: nop

    // 0x801D5920: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801D5924: bne         $v1, $zero, L_801D593C
    if (ctx->r3 != 0) {
        // 0x801D5928: nop
    
            goto L_801D593C;
    }
    // 0x801D5928: nop

    // 0x801D592C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x801D5930: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5934: b           L_801D5954
    // 0x801D5938: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_801D5954;
    // 0x801D5938: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_801D593C:
    // 0x801D593C: b           L_801D5954
    // 0x801D5940: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_801D5954;
    // 0x801D5940: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801D5944: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
L_801D5948:
    // 0x801D5948: nop

    // 0x801D594C: bltz        $v1, L_801D593C
    if (SIGNED(ctx->r3) < 0) {
        // 0x801D5950: nop
    
            goto L_801D593C;
    }
    // 0x801D5950: nop

L_801D5954:
    // 0x801D5954: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5958: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801D595C: ldc1        $f10, 0x36B0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X36B0);
    // 0x801D5960: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D5964: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D5968: sub.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d - ctx->f10.d;
    // 0x801D596C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x801D5970: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x801D5974: nop

    // 0x801D5978: bc1fl       L_801D5998
    if (!c1cs) {
        // 0x801D597C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D5998;
    }
    goto skip_1;
    // 0x801D597C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801D5980: jal         0x801D58B8
    // 0x801D5984: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801D58B8)(rdram, ctx);
        goto after_0;
    // 0x801D5984: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_0:
    // 0x801D5988: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x801D598C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801D5990: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D5994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D5998:
    // 0x801D5998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D599C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801D59A0: jr          $ra
    // 0x801D59A4: nop

    return;
    // 0x801D59A4: nop

;}
RECOMP_FUNC void M8_FUN_801d59a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D59A8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801D59AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801D59B0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801D59B4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D59B8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x801D59BC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x801D59C0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x801D59C4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801D59C8: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801D59CC: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x801D59D0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801D59D4: lwc1        $f26, 0xA4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x801D59D8: lwc1        $f28, 0xA0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801D59DC: lwc1        $f30, 0xA8($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801D59E0: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x801D59E4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801D59E8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x801D59EC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x801D59F0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x801D59F4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x801D59F8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801D59FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801D5A00: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801D5A04: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801D5A08: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801D5A0C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801D5A10: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
L_801D5A14:
    // 0x801D5A14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5A18: ldc1        $f8, 0x36B8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X36B8);
    // 0x801D5A1C: cvt.d.s     $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f4.d = CVT_D_S(ctx->f24.fl);
    // 0x801D5A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801D5A24: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x801D5A28: mov.d       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = ctx->f4.d;
    // 0x801D5A2C: sdc1        $f4, 0x70($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X70, ctx->r29);
    // 0x801D5A30: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D5A34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801D5A38: lbu         $s2, 0x9B($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X9B);
    // 0x801D5A3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D5A40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801D5A44: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801D5A48: nop

    // 0x801D5A4C: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x801D5A50: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801D5A54: nop

    // 0x801D5A58: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801D5A5C: beql        $v0, $zero, L_801D5AB0
    if (ctx->r2 == 0) {
        // 0x801D5A60: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_801D5AB0;
    }
    goto skip_0;
    // 0x801D5A60: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801D5A64: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801D5A68: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D5A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801D5A70: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x801D5A74: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801D5A78: nop

    // 0x801D5A7C: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x801D5A80: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801D5A84: nop

    // 0x801D5A88: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801D5A8C: bne         $v0, $zero, L_801D5AA4
    if (ctx->r2 != 0) {
        // 0x801D5A90: nop
    
            goto L_801D5AA4;
    }
    // 0x801D5A90: nop

    // 0x801D5A94: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x801D5A98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5A9C: b           L_801D5ABC
    // 0x801D5AA0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801D5ABC;
    // 0x801D5AA0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801D5AA4:
    // 0x801D5AA4: b           L_801D5ABC
    // 0x801D5AA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801D5ABC;
    // 0x801D5AA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801D5AAC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_801D5AB0:
    // 0x801D5AB0: nop

    // 0x801D5AB4: bltz        $v0, L_801D5AA4
    if (SIGNED(ctx->r2) < 0) {
        // 0x801D5AB8: nop
    
            goto L_801D5AA4;
    }
    // 0x801D5AB8: nop

L_801D5ABC:
    // 0x801D5ABC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801D5AC0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801D5AC4: beq         $v1, $zero, L_801D5C60
    if (ctx->r3 == 0) {
        // 0x801D5AC8: andi        $s7, $v0, 0xFF
        ctx->r23 = ctx->r2 & 0XFF;
            goto L_801D5C60;
    }
    // 0x801D5AC8: andi        $s7, $v0, 0xFF
    ctx->r23 = ctx->r2 & 0XFF;
    // 0x801D5ACC: blez        $v1, L_801D5C28
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801D5AD0: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_801D5C28;
    }
    // 0x801D5AD0: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
L_801D5AD4:
    // 0x801D5AD4: lbu         $t8, 0x94($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X94);
    // 0x801D5AD8: addu        $t7, $s2, $s1
    ctx->r15 = ADD32(ctx->r18, ctx->r17);
    // 0x801D5ADC: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x801D5AE0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801D5AE4: beq         $at, $zero, L_801D5C60
    if (ctx->r1 == 0) {
        // 0x801D5AE8: sll         $t0, $s2, 2
        ctx->r8 = S32(ctx->r18 << 2);
            goto L_801D5C60;
    }
    // 0x801D5AE8: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x801D5AEC: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x801D5AF0: div         $zero, $t5, $s6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r22)));
    // 0x801D5AF4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801D5AF8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x801D5AFC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801D5B00: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801D5B04: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x801D5B08: addiu       $t7, $t6, 0x32
    ctx->r15 = ADD32(ctx->r14, 0X32);
    // 0x801D5B0C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801D5B10: lw          $s0, 0x30($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X30);
    // 0x801D5B14: mflo        $a0
    ctx->r4 = lo;
    // 0x801D5B18: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D5B1C: swc1        $f26, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f26.u32l;
    // 0x801D5B20: bne         $s6, $zero, L_801D5B2C
    if (ctx->r22 != 0) {
        // 0x801D5B24: nop
    
            goto L_801D5B2C;
    }
    // 0x801D5B24: nop

    // 0x801D5B28: break       7
    do_break(2149407528);
L_801D5B2C:
    // 0x801D5B2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D5B30: bne         $s6, $at, L_801D5B44
    if (ctx->r22 != ctx->r1) {
        // 0x801D5B34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D5B44;
    }
    // 0x801D5B34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5B38: bne         $t5, $at, L_801D5B44
    if (ctx->r13 != ctx->r1) {
        // 0x801D5B3C: nop
    
            goto L_801D5B44;
    }
    // 0x801D5B3C: nop

    // 0x801D5B40: break       6
    do_break(2149407552);
L_801D5B44:
    // 0x801D5B44: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x801D5B48: bgez        $a0, L_801D5B54
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801D5B4C: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_801D5B54;
    }
    // 0x801D5B4C: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x801D5B50: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
L_801D5B54:
    // 0x801D5B54: sra         $a0, $at, 1
    ctx->r4 = S32(SIGNED(ctx->r1) >> 1);
    // 0x801D5B58: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5B5C: ldc1        $f18, 0x36C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X36C0);
    // 0x801D5B60: mul.d       $f20, $f18, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f20.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x801D5B64: jal         0x8012C6B4
    // 0x801D5B68: nop

    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801D5B68: nop

    after_0:
    // 0x801D5B6C: sll         $t8, $s1, 13
    ctx->r24 = S32(ctx->r17 << 13);
    // 0x801D5B70: div         $zero, $t8, $s6
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r22)));
    // 0x801D5B74: mflo        $t9
    ctx->r25 = lo;
    // 0x801D5B78: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x801D5B7C: sll         $s5, $v1, 16
    ctx->r21 = S32(ctx->r3 << 16);
    // 0x801D5B80: bne         $s6, $zero, L_801D5B8C
    if (ctx->r22 != 0) {
        // 0x801D5B84: nop
    
            goto L_801D5B8C;
    }
    // 0x801D5B84: nop

    // 0x801D5B88: break       7
    do_break(2149407624);
L_801D5B8C:
    // 0x801D5B8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801D5B90: bne         $s6, $at, L_801D5BA4
    if (ctx->r22 != ctx->r1) {
        // 0x801D5B94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801D5BA4;
    }
    // 0x801D5B94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5B98: bne         $t8, $at, L_801D5BA4
    if (ctx->r24 != ctx->r1) {
        // 0x801D5B9C: nop
    
            goto L_801D5BA4;
    }
    // 0x801D5B9C: nop

    // 0x801D5BA0: break       6
    do_break(2149407648);
L_801D5BA4:
    // 0x801D5BA4: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x801D5BA8: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x801D5BAC: jal         0x8001EAD0
    // 0x801D5BB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D5BB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801D5BB4: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x801D5BB8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x801D5BBC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801D5BC0: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x801D5BC4: jal         0x8001EB64
    // 0x801D5BC8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D5BC8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x801D5BCC: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x801D5BD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801D5BD4: add.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x801D5BD8: jal         0x8012C6B4
    // 0x801D5BDC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801D5BDC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x801D5BE0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801D5BE4: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D5BE8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801D5BEC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D5BF0: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801D5BF4: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x801D5BF8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x801D5BFC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D5C00: add.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f10.d + ctx->f22.d;
    // 0x801D5C04: mul.d       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f20.d, ctx->f16.d);
    // 0x801D5C08: div.d       $f18, $f4, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f22.d);
    // 0x801D5C0C: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x801D5C10: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D5C14: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x801D5C18: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D5C1C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801D5C20: bne         $at, $zero, L_801D5AD4
    if (ctx->r1 != 0) {
        // 0x801D5C24: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_801D5AD4;
    }
    // 0x801D5C24: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_801D5C28:
    // 0x801D5C28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5C2C: ldc1        $f4, 0x36C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X36C8);
    // 0x801D5C30: ldc1        $f16, 0x70($sp)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r29, 0X70);
    // 0x801D5C34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D5C38: lbu         $t0, 0x9B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X9B);
    // 0x801D5C3C: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x801D5C40: addu        $t1, $t0, $s7
    ctx->r9 = ADD32(ctx->r8, ctx->r23);
    // 0x801D5C44: cvt.s.d     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f24.fl = CVT_S_D(ctx->f6.d);
    // 0x801D5C48: c.lt.s      $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl < ctx->f24.fl;
    // 0x801D5C4C: nop

    // 0x801D5C50: bc1fl       L_801D5C64
    if (!c1cs) {
        // 0x801D5C54: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_801D5C64;
    }
    goto skip_1;
    // 0x801D5C54: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_1:
    // 0x801D5C58: b           L_801D5A14
    // 0x801D5C5C: sb          $t1, 0x9B($sp)
    MEM_B(0X9B, ctx->r29) = ctx->r9;
        goto L_801D5A14;
    // 0x801D5C5C: sb          $t1, 0x9B($sp)
    MEM_B(0X9B, ctx->r29) = ctx->r9;
L_801D5C60:
    // 0x801D5C60: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_801D5C64:
    // 0x801D5C64: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801D5C68: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801D5C6C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801D5C70: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801D5C74: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x801D5C78: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x801D5C7C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801D5C80: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801D5C84: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801D5C88: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801D5C8C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801D5C90: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801D5C94: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801D5C98: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x801D5C9C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x801D5CA0: jr          $ra
    // 0x801D5CA4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801D5CA4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d5ca8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d5ca8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5CA8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801D5CAC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D5CB0: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x801D5CB4: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x801D5CB8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x801D5CBC: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x801D5CC0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x801D5CC4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x801D5CC8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801D5CCC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801D5CD0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801D5CD4: sb          $zero, 0x59($sp)
    MEM_B(0X59, ctx->r29) = 0;
    // 0x801D5CD8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D5CDC: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x801D5CE0: jal         0x801D58B8
    // 0x801D5CE4: lwc1        $f12, 0x88($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X88);
    LOOKUP_FUNC(0x801D58B8)(rdram, ctx);
        goto after_0;
    // 0x801D5CE4: lwc1        $f12, 0x88($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X88);
    after_0:
    // 0x801D5CE8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801D5CEC: bne         $t6, $zero, L_801D5D0C
    if (ctx->r14 != 0) {
        // 0x801D5CF0: sb          $v0, 0x94($s3)
        MEM_B(0X94, ctx->r19) = ctx->r2;
            goto L_801D5D0C;
    }
    // 0x801D5CF0: sb          $v0, 0x94($s3)
    MEM_B(0X94, ctx->r19) = ctx->r2;
    // 0x801D5CF4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5CF8: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D5CFC: jal         0x800058DC
    // 0x801D5D00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D5D00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x801D5D04: b           L_801D5EA4
    // 0x801D5D08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_801D5EA4;
    // 0x801D5D08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D5D0C:
    // 0x801D5D0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D5D10: jal         0x801CE0E8
    // 0x801D5D14: addiu       $a1, $sp, 0x59
    ctx->r5 = ADD32(ctx->r29, 0X59);
    LOOKUP_FUNC(0x801CE0E8)(rdram, ctx);
        goto after_2;
    // 0x801D5D14: addiu       $a1, $sp, 0x59
    ctx->r5 = ADD32(ctx->r29, 0X59);
    after_2:
    // 0x801D5D18: bnel        $v0, $zero, L_801D5EA4
    if (ctx->r2 != 0) {
        // 0x801D5D1C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801D5EA4;
    }
    goto skip_0;
    // 0x801D5D1C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801D5D20: lwc1        $f4, 0x6C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x801D5D24: lw          $a3, 0x88($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X88);
    // 0x801D5D28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D5D2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801D5D30: lwc1        $f6, 0x70($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X70);
    // 0x801D5D34: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x801D5D38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5D3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801D5D40: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x801D5D44: jal         0x801D59A8
    // 0x801D5D48: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801D59A8)(rdram, ctx);
        goto after_3;
    // 0x801D5D48: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x801D5D4C: lbu         $t7, 0x97($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X97);
    // 0x801D5D50: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801D5D54: bne         $t7, $at, L_801D5E8C
    if (ctx->r15 != ctx->r1) {
        // 0x801D5D58: nop
    
            goto L_801D5E8C;
    }
    // 0x801D5D58: nop

    // 0x801D5D5C: lbu         $t8, 0x94($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X94);
    // 0x801D5D60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801D5D64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5D68: blez        $t8, L_801D5E8C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801D5D6C: addiu       $s6, $zero, 0x40
        ctx->r22 = ADD32(0, 0X40);
            goto L_801D5E8C;
    }
    // 0x801D5D6C: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x801D5D70: ldc1        $f20, 0x36D0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X36D0);
    // 0x801D5D74: addiu       $s5, $zero, 0xA5
    ctx->r21 = ADD32(0, 0XA5);
    // 0x801D5D78: addiu       $s4, $zero, 0x2F
    ctx->r20 = ADD32(0, 0X2F);
    // 0x801D5D7C: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x801D5D80: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
L_801D5D84:
    // 0x801D5D84: addu        $t0, $s7, $t9
    ctx->r8 = ADD32(ctx->r23, ctx->r25);
    // 0x801D5D88: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D5D8C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801D5D90: jal         0x8012C6B4
    // 0x801D5D94: lw          $s0, 0x30($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X30);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801D5D94: lw          $s0, 0x30($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X30);
    after_4:
    // 0x801D5D98: sb          $v0, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r2;
    // 0x801D5D9C: lbu         $t2, 0x95($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X95);
    // 0x801D5DA0: bnel        $s4, $t2, L_801D5E78
    if (ctx->r20 != ctx->r10) {
        // 0x801D5DA4: lbu         $t7, 0x94($s3)
        ctx->r15 = MEM_BU(ctx->r19, 0X94);
            goto L_801D5E78;
    }
    goto skip_1;
    // 0x801D5DA4: lbu         $t7, 0x94($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X94);
    skip_1:
    // 0x801D5DA8: lwc1        $f10, 0x88($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X88);
    // 0x801D5DAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D5DB0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801D5DB4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D5DB8: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x801D5DBC: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x801D5DC0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D5DC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D5DC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D5DCC: nop

    // 0x801D5DD0: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x801D5DD4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D5DD8: nop

    // 0x801D5DDC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D5DE0: beql        $t4, $zero, L_801D5E34
    if (ctx->r12 == 0) {
        // 0x801D5DE4: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_801D5E34;
    }
    goto skip_2;
    // 0x801D5DE4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x801D5DE8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D5DEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D5DF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D5DF4: sub.d       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f18.d - ctx->f4.d;
    // 0x801D5DF8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D5DFC: nop

    // 0x801D5E00: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x801D5E04: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D5E08: nop

    // 0x801D5E0C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D5E10: bne         $t4, $zero, L_801D5E28
    if (ctx->r12 != 0) {
        // 0x801D5E14: nop
    
            goto L_801D5E28;
    }
    // 0x801D5E14: nop

    // 0x801D5E18: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801D5E1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5E20: b           L_801D5E40
    // 0x801D5E24: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D5E40;
    // 0x801D5E24: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D5E28:
    // 0x801D5E28: b           L_801D5E40
    // 0x801D5E2C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D5E40;
    // 0x801D5E2C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D5E30: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_801D5E34:
    // 0x801D5E34: nop

    // 0x801D5E38: bltz        $t4, L_801D5E28
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D5E3C: nop
    
            goto L_801D5E28;
    }
    // 0x801D5E3C: nop

L_801D5E40:
    // 0x801D5E40: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801D5E44: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801D5E48: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D5E4C: bnel        $at, $zero, L_801D5E78
    if (ctx->r1 != 0) {
        // 0x801D5E50: lbu         $t7, 0x94($s3)
        ctx->r15 = MEM_BU(ctx->r19, 0X94);
            goto L_801D5E78;
    }
    goto skip_3;
    // 0x801D5E50: lbu         $t7, 0x94($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X94);
    skip_3:
    // 0x801D5E54: bnel        $t6, $zero, L_801D5E78
    if (ctx->r14 != 0) {
        // 0x801D5E58: lbu         $t7, 0x94($s3)
        ctx->r15 = MEM_BU(ctx->r19, 0X94);
            goto L_801D5E78;
    }
    goto skip_4;
    // 0x801D5E58: lbu         $t7, 0x94($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X94);
    skip_4:
    // 0x801D5E5C: sb          $s2, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r18;
    // 0x801D5E60: sb          $s2, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r18;
    // 0x801D5E64: sb          $s2, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r18;
    // 0x801D5E68: sb          $s2, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r18;
    // 0x801D5E6C: sb          $s5, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r21;
    // 0x801D5E70: sb          $s6, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r22;
    // 0x801D5E74: lbu         $t7, 0x94($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X94);
L_801D5E78:
    // 0x801D5E78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801D5E7C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801D5E80: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801D5E84: bnel        $at, $zero, L_801D5D84
    if (ctx->r1 != 0) {
        // 0x801D5E88: sll         $t9, $s1, 2
        ctx->r25 = S32(ctx->r17 << 2);
            goto L_801D5D84;
    }
    goto skip_5;
    // 0x801D5E88: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    skip_5:
L_801D5E8C:
    // 0x801D5E8C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5E90: sh          $zero, 0x92($s3)
    MEM_H(0X92, ctx->r19) = 0;
    // 0x801D5E94: addiu       $a1, $a1, 0x5ED0
    ctx->r5 = ADD32(ctx->r5, 0X5ED0);
    // 0x801D5E98: jal         0x800058DC
    // 0x801D5E9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801D5E9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x801D5EA0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801D5EA4:
    // 0x801D5EA4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801D5EA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5EAC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801D5EB0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801D5EB4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x801D5EB8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x801D5EBC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x801D5EC0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x801D5EC4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x801D5EC8: jr          $ra
    // 0x801D5ECC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801D5ECC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d5ed0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d5ed0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5ED0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801D5ED4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801D5ED8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801D5EDC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801D5EE0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801D5EE4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801D5EE8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801D5EEC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801D5EF0: jal         0x8012D7A8
    // 0x801D5EF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x801D5EF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D5EF8: lhu         $v0, 0x90($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X90);
    // 0x801D5EFC: lhu         $v1, 0x92($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X92);
    // 0x801D5F00: addiu       $t6, $v0, -0xA
    ctx->r14 = ADD32(ctx->r2, -0XA);
    // 0x801D5F04: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D5F08: beq         $at, $zero, L_801D5F84
    if (ctx->r1 == 0) {
        // 0x801D5F0C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_801D5F84;
    }
    // 0x801D5F0C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801D5F10: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
    // 0x801D5F14: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x801D5F18: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801D5F1C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D5F20: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D5F24: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D5F28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D5F2C: lbu         $t9, 0x94($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X94);
    // 0x801D5F30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801D5F34: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801D5F38: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801D5F3C: blez        $t9, L_801D5F84
    if (SIGNED(ctx->r25) <= 0) {
        // 0x801D5F40: cvt.s.d     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
            goto L_801D5F84;
    }
    // 0x801D5F40: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x801D5F44: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
L_801D5F48:
    // 0x801D5F48: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801D5F4C: lbu         $a0, 0x7B($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X7B);
    // 0x801D5F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D5F54: jal         0x801CD500
    // 0x801D5F58: lw          $s2, 0x30($t0)
    ctx->r18 = MEM_W(ctx->r8, 0X30);
    LOOKUP_FUNC(0x801CD500)(rdram, ctx);
        goto after_1;
    // 0x801D5F58: lw          $s2, 0x30($t0)
    ctx->r18 = MEM_W(ctx->r8, 0X30);
    after_1:
    // 0x801D5F5C: sb          $v0, 0x4B($s2)
    MEM_B(0X4B, ctx->r18) = ctx->r2;
    // 0x801D5F60: lbu         $t1, 0x94($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X94);
    // 0x801D5F64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801D5F68: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801D5F6C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801D5F70: bnel        $at, $zero, L_801D5F48
    if (ctx->r1 != 0) {
        // 0x801D5F74: lw          $t0, 0x0($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X0);
            goto L_801D5F48;
    }
    goto skip_0;
    // 0x801D5F74: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801D5F78: lhu         $v1, 0x92($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X92);
    // 0x801D5F7C: lhu         $v0, 0x90($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X90);
    // 0x801D5F80: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_801D5F84:
    // 0x801D5F84: slt         $a1, $v0, $a0
    ctx->r5 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801D5F88: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x801D5F8C: bne         $a1, $zero, L_801D5FA4
    if (ctx->r5 != 0) {
        // 0x801D5F90: sh          $t2, 0x92($s3)
        MEM_H(0X92, ctx->r19) = ctx->r10;
            goto L_801D5FA4;
    }
    // 0x801D5F90: sh          $t2, 0x92($s3)
    MEM_H(0X92, ctx->r19) = ctx->r10;
    // 0x801D5F94: lw          $t3, 0xC($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XC);
    // 0x801D5F98: lhu         $t4, 0x4C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4C);
    // 0x801D5F9C: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x801D5FA0: beq         $t5, $zero, L_801D5FC0
    if (ctx->r13 == 0) {
        // 0x801D5FA4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801D5FC0;
    }
L_801D5FA4:
    // 0x801D5FA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801D5FA8: jal         0x801CE5B0
    // 0x801D5FAC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x801CE5B0)(rdram, ctx);
        goto after_2;
    // 0x801D5FAC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x801D5FB0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5FB4: addiu       $a1, $a1, -0x1768
    ctx->r5 = ADD32(ctx->r5, -0X1768);
    // 0x801D5FB8: jal         0x800058DC
    // 0x801D5FBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D5FBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
L_801D5FC0:
    // 0x801D5FC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5FC4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801D5FC8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801D5FCC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801D5FD0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801D5FD4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801D5FD8: jr          $ra
    // 0x801D5FDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801D5FDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d5fe0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d5fe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D5FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5FE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D5FEC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801D5FF0: lbu         $t6, 0x63($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X63);
    // 0x801D5FF4: beql        $t6, $zero, L_801D6018
    if (ctx->r14 == 0) {
        // 0x801D5FF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6018;
    }
    goto skip_0;
    // 0x801D5FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D5FFC: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801D6000: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D6004: beql        $t7, $zero, L_801D6018
    if (ctx->r15 == 0) {
        // 0x801D6008: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6018;
    }
    goto skip_1;
    // 0x801D6008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801D600C: jal         0x800058DC
    // 0x801D6010: addiu       $a1, $a1, 0x6024
    ctx->r5 = ADD32(ctx->r5, 0X6024);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801D6010: addiu       $a1, $a1, 0x6024
    ctx->r5 = ADD32(ctx->r5, 0X6024);
    after_0:
    // 0x801D6014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6018:
    // 0x801D6018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D601C: jr          $ra
    // 0x801D6020: nop

    return;
    // 0x801D6020: nop

;}
RECOMP_FUNC void M8_FUN_801d6024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D6028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D602C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D6030: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801D6034: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801D6038: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D603C: lw          $a3, 0x5C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X5C);
    // 0x801D6040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D6044: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x801D6048: addiu       $a1, $a1, 0x14B4
    ctx->r5 = ADD32(ctx->r5, 0X14B4);
    // 0x801D604C: jal         0x80005E44
    // 0x801D6050: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801D6050: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D6054: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801D6058: bne         $v0, $zero, L_801D6070
    if (ctx->r2 != 0) {
        // 0x801D605C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_801D6070;
    }
    // 0x801D605C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x801D6060: jal         0x80005700
    // 0x801D6064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801D6064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D6068: b           L_801D6270
    // 0x801D606C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D6270;
    // 0x801D606C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D6070:
    // 0x801D6070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6074: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x801D6078: jal         0x80006214
    // 0x801D607C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D607C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x801D6080: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801D6084: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6088: lwc1        $f0, 0x3704($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3704);
    // 0x801D608C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801D6090: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x801D6094: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x801D6098: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801D609C: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
    // 0x801D60A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D60A4: sh          $t7, 0x2C($t9)
    MEM_H(0X2C, ctx->r25) = ctx->r15;
    // 0x801D60A8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x801D60AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D60B0: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801D60B4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D60B8: ori         $a1, $a1, 0xA00
    ctx->r5 = ctx->r5 | 0XA00;
    // 0x801D60BC: sb          $t0, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r8;
    // 0x801D60C0: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x801D60C4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801D60C8: sb          $zero, 0x4A($t4)
    MEM_B(0X4A, ctx->r12) = 0;
    // 0x801D60CC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x801D60D0: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x801D60D4: lbu         $a0, 0x4A($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X4A);
    // 0x801D60D8: sb          $a0, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r4;
    // 0x801D60DC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801D60E0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801D60E4: sb          $a0, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r4;
    // 0x801D60E8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801D60EC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801D60F0: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x801D60F4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x801D60F8: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801D60FC: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x801D6100: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    // 0x801D6104: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801D6108: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D610C: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x801D6110: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x801D6114: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801D6118: addiu       $t3, $t3, 0x14C8
    ctx->r11 = ADD32(ctx->r11, 0X14C8);
    // 0x801D611C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801D6120: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x801D6124: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x801D6128: swc1        $f2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f2.u32l;
    // 0x801D612C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801D6130: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D6134: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801D6138: swc1        $f2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f2.u32l;
    // 0x801D613C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801D6140: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801D6144: swc1        $f2, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f2.u32l;
    // 0x801D6148: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801D614C: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801D6150: sw          $t1, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r9;
    // 0x801D6154: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x801D6158: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801D615C: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x801D6160: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x801D6164: lw          $t7, 0x24($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X24);
    // 0x801D6168: lbu         $t9, 0x22($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X22);
    // 0x801D616C: bnel        $t9, $zero, L_801D6184
    if (ctx->r25 != 0) {
        // 0x801D6170: lw          $t2, 0x0($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X0);
            goto L_801D6184;
    }
    goto skip_0;
    // 0x801D6170: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x801D6174: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801D6178: b           L_801D618C
    // 0x801D617C: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
        goto L_801D618C;
    // 0x801D617C: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x801D6180: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
L_801D6184:
    // 0x801D6184: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D6188: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D618C:
    // 0x801D618C: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
    // 0x801D6190: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x801D6194: jal         0x800062F8
    // 0x801D6198: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_3;
    // 0x801D6198: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D619C: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x801D61A0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x801D61A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D61A8: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x801D61AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D61B0: lbu         $t4, 0x22($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X22);
    // 0x801D61B4: bnel        $t4, $zero, L_801D6208
    if (ctx->r12 != 0) {
        // 0x801D61B8: lwc1        $f6, 0x68($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X68);
            goto L_801D6208;
    }
    goto skip_1;
    // 0x801D61B8: lwc1        $f6, 0x68($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X68);
    skip_1:
    // 0x801D61BC: lwc1        $f6, 0xB0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XB0);
    // 0x801D61C0: lwc1        $f8, 0xBC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XBC);
    // 0x801D61C4: lui         $at, 0x4012
    ctx->r1 = S32(0X4012 << 16);
    // 0x801D61C8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D61CC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801D61D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D61D4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D61D8: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x801D61DC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D61E0: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
    // 0x801D61E4: lwc1        $f8, 0xC4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x801D61E8: lwc1        $f6, 0xB8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x801D61EC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801D61F0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D61F4: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x801D61F8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D61FC: b           L_801D6264
    // 0x801D6200: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
        goto L_801D6264;
    // 0x801D6200: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x801D6204: lwc1        $f6, 0x68($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X68);
L_801D6208:
    // 0x801D6208: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D620C: ldc1        $f10, 0x3708($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3708);
    // 0x801D6210: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x801D6214: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6218: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x801D621C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801D6220: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D6224: swc1        $f18, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f18.u32l;
    // 0x801D6228: lwc1        $f6, 0x70($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X70);
    // 0x801D622C: lwc1        $f4, 0x6C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x801D6230: ldc1        $f16, 0x3710($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X3710);
    // 0x801D6234: lwc1        $f2, 0xA0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x801D6238: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D623C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D6240: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801D6244: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801D6248: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x801D624C: lwc1        $f6, 0xA4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801D6250: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x801D6254: nop

    // 0x801D6258: bc1f        L_801D6264
    if (!c1cs) {
        // 0x801D625C: nop
    
            goto L_801D6264;
    }
    // 0x801D625C: nop

    // 0x801D6260: swc1        $f2, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f2.u32l;
L_801D6264:
    // 0x801D6264: jal         0x800058DC
    // 0x801D6268: addiu       $a1, $a1, 0x6280
    ctx->r5 = ADD32(ctx->r5, 0X6280);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801D6268: addiu       $a1, $a1, 0x6280
    ctx->r5 = ADD32(ctx->r5, 0X6280);
    after_4:
    // 0x801D626C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D6270:
    // 0x801D6270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D6274: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D6278: jr          $ra
    // 0x801D627C: nop

    return;
    // 0x801D627C: nop

;}
RECOMP_FUNC void M8_FUN_801d6280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6280: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x801D6284: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D6288: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801D628C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801D6290: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x801D6294: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801D6298: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x801D629C: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x801D62A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D62A4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801D62A8: beq         $v1, $zero, L_801D6AB0
    if (ctx->r3 == 0) {
        // 0x801D62AC: lw          $t0, 0x5C($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X5C);
            goto L_801D6AB0;
    }
    // 0x801D62AC: lw          $t0, 0x5C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X5C);
    // 0x801D62B0: lbu         $t4, 0x63($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X63);
    // 0x801D62B4: beql        $t4, $zero, L_801D6AB4
    if (ctx->r12 == 0) {
        // 0x801D62B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D6AB4;
    }
    goto skip_0;
    // 0x801D62B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801D62BC: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    // 0x801D62C0: bnel        $t8, $zero, L_801D62D8
    if (ctx->r24 != 0) {
        // 0x801D62C4: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_801D62D8;
    }
    goto skip_1;
    // 0x801D62C4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x801D62C8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801D62CC: b           L_801D62E0
    // 0x801D62D0: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
        goto L_801D62E0;
    // 0x801D62D0: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x801D62D4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_801D62D8:
    // 0x801D62D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D62DC: sb          $t6, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r14;
L_801D62E0:
    // 0x801D62E0: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x801D62E4: lw          $t3, 0xDC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XDC);
    // 0x801D62E8: bnel        $t3, $v0, L_801D630C
    if (ctx->r11 != ctx->r2) {
        // 0x801D62EC: lw          $t9, 0x24($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X24);
            goto L_801D630C;
    }
    goto skip_2;
    // 0x801D62EC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    skip_2:
    // 0x801D62F0: jal         0x80126944
    // 0x801D62F4: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801D62F4: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_0:
    // 0x801D62F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D62FC: bne         $v0, $at, L_801D6528
    if (ctx->r2 != ctx->r1) {
        // 0x801D6300: lw          $t0, 0xBC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XBC);
            goto L_801D6528;
    }
    // 0x801D6300: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801D6304: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x801D6308: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
L_801D630C:
    // 0x801D630C: lw          $t5, 0x2C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X2C);
    // 0x801D6310: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    // 0x801D6314: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x801D6318: jal         0x8001EAD0
    // 0x801D631C: sh          $a0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D631C: sh          $a0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D6320: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x801D6324: jal         0x8001EB64
    // 0x801D6328: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D6328: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x801D632C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801D6330: lui         $at, 0x4012
    ctx->r1 = S32(0X4012 << 16);
    // 0x801D6334: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D6338: lwc1        $f2, 0xB0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0XB0);
    // 0x801D633C: lwc1        $f12, 0xBC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XBC);
    // 0x801D6340: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D6344: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801D6348: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x801D634C: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x801D6350: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D6354: div.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x801D6358: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D635C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D6360: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D6364: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801D6368: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x801D636C: lwc1        $f16, 0xC4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x801D6370: lwc1        $f14, 0xB8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XB8);
    // 0x801D6374: sub.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x801D6378: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D637C: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801D6380: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801D6384: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D6388: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D638C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D6390: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D6394: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x801D6398: mul.d       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x801D639C: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x801D63A0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D63A4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x801D63A8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D63AC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D63B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D63B4: nop

    // 0x801D63B8: mul.d       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x801D63BC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801D63C0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D63C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D63C8: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x801D63CC: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x801D63D0: lw          $t8, 0x24($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X24);
    // 0x801D63D4: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D63D8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801D63DC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801D63E0: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801D63E4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801D63E8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801D63EC: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801D63F0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801D63F4: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801D63F8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801D63FC: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x801D6400: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D6404: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x801D6408: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801D640C: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801D6410: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801D6414: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D6418: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801D641C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801D6420: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x801D6424: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x801D6428: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x801D642C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801D6430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D6434: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801D6438: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x801D643C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x801D6440: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x801D6444: nop

    // 0x801D6448: bc1fl       L_801D6474
    if (!c1cs) {
        // 0x801D644C: mtc1        $at, $f3
        ctx->f_odd[(3 - 1) * 2] = ctx->r1;
            goto L_801D6474;
    }
    goto skip_3;
    // 0x801D644C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    skip_3:
    // 0x801D6450: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801D6454: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801D6458: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D645C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801D6460: sub.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d - ctx->f2.d;
    // 0x801D6464: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D6468: b           L_801D64A4
    // 0x801D646C: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
        goto L_801D64A4;
    // 0x801D646C: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
    // 0x801D6470: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
L_801D6474:
    // 0x801D6474: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D6478: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801D647C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x801D6480: nop

    // 0x801D6484: bc1fl       L_801D64A4
    if (!c1cs) {
        // 0x801D6488: swc1        $f4, 0xA0($s0)
        MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
            goto L_801D64A4;
    }
    goto skip_4;
    // 0x801D6488: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
    skip_4:
    // 0x801D648C: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x801D6490: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x801D6494: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D6498: b           L_801D64A4
    // 0x801D649C: swc1        $f10, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f10.u32l;
        goto L_801D64A4;
    // 0x801D649C: swc1        $f10, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f10.u32l;
    // 0x801D64A0: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
L_801D64A4:
    // 0x801D64A4: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801D64A8: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x801D64AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801D64B0: sub.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x801D64B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D64B8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801D64BC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x801D64C0: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x801D64C4: nop

    // 0x801D64C8: bc1fl       L_801D64F4
    if (!c1cs) {
        // 0x801D64CC: mtc1        $at, $f13
        ctx->f_odd[(13 - 1) * 2] = ctx->r1;
            goto L_801D64F4;
    }
    goto skip_5;
    // 0x801D64CC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    skip_5:
    // 0x801D64D0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801D64D4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801D64D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D64DC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D64E0: sub.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d - ctx->f12.d;
    // 0x801D64E4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D64E8: b           L_801D66AC
    // 0x801D64EC: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
        goto L_801D66AC;
    // 0x801D64EC: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x801D64F0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
L_801D64F4:
    // 0x801D64F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D64F8: nop

    // 0x801D64FC: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x801D6500: nop

    // 0x801D6504: bc1f        L_801D6520
    if (!c1cs) {
        // 0x801D6508: nop
    
            goto L_801D6520;
    }
    // 0x801D6508: nop

    // 0x801D650C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D6510: add.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d + ctx->f12.d;
    // 0x801D6514: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D6518: b           L_801D66AC
    // 0x801D651C: swc1        $f10, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f10.u32l;
        goto L_801D66AC;
    // 0x801D651C: swc1        $f10, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f10.u32l;
L_801D6520:
    // 0x801D6520: b           L_801D66AC
    // 0x801D6524: swc1        $f14, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f14.u32l;
        goto L_801D66AC;
    // 0x801D6524: swc1        $f14, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f14.u32l;
L_801D6528:
    // 0x801D6528: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x801D652C: lw          $t6, 0x24($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X24);
    // 0x801D6530: lw          $t2, 0x2C($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X2C);
    // 0x801D6534: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801D6538: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x801D653C: jal         0x8001EAD0
    // 0x801D6540: sh          $a0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801D6540: sh          $a0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r4;
    after_3:
    // 0x801D6544: lh          $a0, 0x62($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X62);
    // 0x801D6548: jal         0x8001EB64
    // 0x801D654C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x801D654C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x801D6550: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801D6554: lui         $at, 0x4012
    ctx->r1 = S32(0X4012 << 16);
    // 0x801D6558: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D655C: lwc1        $f2, 0xB0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0XB0);
    // 0x801D6560: lwc1        $f12, 0xBC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XBC);
    // 0x801D6564: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D6568: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801D656C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x801D6570: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x801D6574: lw          $t9, 0xDC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XDC);
    // 0x801D6578: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D657C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801D6580: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D6584: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D6588: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D658C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801D6590: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x801D6594: lwc1        $f16, 0xC4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x801D6598: lwc1        $f14, 0xB8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XB8);
    // 0x801D659C: sub.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x801D65A0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D65A4: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x801D65A8: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x801D65AC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D65B0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D65B4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D65B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D65BC: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x801D65C0: mul.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801D65C4: add.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x801D65C8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D65CC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801D65D0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D65D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D65D8: nop

    // 0x801D65DC: mul.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801D65E0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801D65E4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x801D65E8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x801D65EC: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x801D65F0: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x801D65F4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801D65F8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801D65FC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801D6600: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801D6604: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801D6608: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801D660C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801D6610: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801D6614: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x801D6618: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D661C: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x801D6620: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801D6624: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801D6628: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801D662C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801D6630: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801D6634: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D6638: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801D663C: bne         $t9, $v0, L_801D6658
    if (ctx->r25 != ctx->r2) {
        // 0x801D6640: swc1        $f8, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
            goto L_801D6658;
    }
    // 0x801D6640: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801D6644: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x801D6648: nop

    // 0x801D664C: bc1fl       L_801D665C
    if (!c1cs) {
        // 0x801D6650: lwc1        $f12, 0xA0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XA0);
            goto L_801D665C;
    }
    goto skip_6;
    // 0x801D6650: lwc1        $f12, 0xA0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA0);
    skip_6:
    // 0x801D6654: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
L_801D6658:
    // 0x801D6658: lwc1        $f12, 0xA0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA0);
L_801D665C:
    // 0x801D665C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801D6660: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801D6664: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801D6668: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x801D666C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D6670: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801D6674: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x801D6678: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D667C: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801D6680: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D6684: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D6688: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D668C: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
    // 0x801D6690: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801D6694: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801D6698: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D669C: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801D66A0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801D66A4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801D66A8: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
L_801D66AC:
    // 0x801D66AC: lw          $t5, 0xDC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XDC);
    // 0x801D66B0: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x801D66B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D66B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801D66BC: bne         $t5, $t4, L_801D66D4
    if (ctx->r13 != ctx->r12) {
        // 0x801D66C0: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_801D66D4;
    }
    // 0x801D66C0: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801D66C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801D66C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801D66CC: b           L_801D66E0
    // 0x801D66D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
        goto L_801D66E0;
    // 0x801D66D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_801D66D4:
    // 0x801D66D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801D66D8: nop

    // 0x801D66DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_801D66E0:
    // 0x801D66E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D66E4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D66E8: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801D66EC: add.d       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f10.d + ctx->f4.d;
    // 0x801D66F0: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801D66F4: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801D66F8: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x801D66FC: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x801D6700: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801D6704: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801D6708: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801D670C: jal         0x8010843C
    // 0x801D6710: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_5;
    // 0x801D6710: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x801D6714: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801D6718: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D671C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801D6720: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x801D6724: beq         $v0, $zero, L_801D6A80
    if (ctx->r2 == 0) {
        // 0x801D6728: lw          $t0, 0xBC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XBC);
            goto L_801D6A80;
    }
    // 0x801D6728: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801D672C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801D6730: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801D6734: lwc1        $f8, 0x384($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X384);
    // 0x801D6738: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    // 0x801D673C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801D6740: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801D6744: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D6748: beql        $t8, $zero, L_801D6788
    if (ctx->r24 == 0) {
        // 0x801D674C: c.lt.s      $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
            goto L_801D6788;
    }
    goto skip_7;
    // 0x801D674C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    skip_7:
    // 0x801D6750: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D6754: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D6758: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D675C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D6760: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x801D6764: nop

    // 0x801D6768: bc1fl       L_801D6780
    if (!c1cs) {
        // 0x801D676C: sb          $t7, 0x22($v1)
        MEM_B(0X22, ctx->r3) = ctx->r15;
            goto L_801D6780;
    }
    goto skip_8;
    // 0x801D676C: sb          $t7, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r15;
    skip_8:
    // 0x801D6770: sb          $zero, 0x22($v1)
    MEM_B(0X22, ctx->r3) = 0;
    // 0x801D6774: b           L_801D6784
    // 0x801D6778: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
        goto L_801D6784;
    // 0x801D6778: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801D677C: sb          $t7, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r15;
L_801D6780:
    // 0x801D6780: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_801D6784:
    // 0x801D6784: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
L_801D6788:
    // 0x801D6788: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801D678C: bc1fl       L_801D67A0
    if (!c1cs) {
        // 0x801D6790: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_801D67A0;
    }
    goto skip_9;
    // 0x801D6790: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_9:
    // 0x801D6794: b           L_801D67AC
    // 0x801D6798: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_801D67AC;
    // 0x801D6798: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801D679C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_801D67A0:
    // 0x801D67A0: nop

    // 0x801D67A4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801D67A8: add.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f2.fl;
L_801D67AC:
    // 0x801D67AC: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x801D67B0: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x801D67B4: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x801D67B8: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801D67BC: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    // 0x801D67C0: lwc1        $f8, 0xA4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801D67C4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801D67C8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801D67CC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D67D0: swc1        $f10, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f10.u32l;
    // 0x801D67D4: lwc1        $f6, 0x384($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X384);
    // 0x801D67D8: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801D67DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801D67E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D67E4: lw          $t5, 0x30($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X30);
    // 0x801D67E8: swc1        $f8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f8.u32l;
    // 0x801D67EC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801D67F0: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801D67F4: lw          $t8, 0x30($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X30);
    // 0x801D67F8: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x801D67FC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801D6800: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801D6804: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801D6808: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x801D680C: lwc1        $f6, 0x35C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X35C);
    // 0x801D6810: lwc1        $f8, 0x360($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X360);
    // 0x801D6814: lwc1        $f10, 0x364($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X364);
    // 0x801D6818: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // 0x801D681C: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x801D6820: sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // 0x801D6824: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x801D6828: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x801D682C: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x801D6830: jal         0x80130F74
    // 0x801D6834: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80130F74)(rdram, ctx);
        goto after_6;
    // 0x801D6834: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x801D6838: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x801D683C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x801D6840: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x801D6844: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801D6848: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D684C: lw          $t9, 0x2C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X2C);
    // 0x801D6850: lh          $a3, 0x12($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X12);
    // 0x801D6854: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801D6858: sra         $a3, $a3, 3
    ctx->r7 = S32(SIGNED(ctx->r7) >> 3);
    // 0x801D685C: jal         0x801311F8
    // 0x801D6860: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    LOOKUP_FUNC(0x801311F8)(rdram, ctx);
        goto after_7;
    // 0x801D6860: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    after_7:
    // 0x801D6864: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6868: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x801D686C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801D6870: ldc1        $f0, 0x3718($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X3718);
    // 0x801D6874: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801D6878:
    // 0x801D6878: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x801D687C: addu        $v0, $a0, $t5
    ctx->r2 = ADD32(ctx->r4, ctx->r13);
    // 0x801D6880: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x801D6884: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801D6888: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801D688C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801D6890: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D6894: bgez        $t4, L_801D68AC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801D6898: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801D68AC;
    }
    // 0x801D6898: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801D689C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801D68A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D68A4: nop

    // 0x801D68A8: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801D68AC:
    // 0x801D68AC: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x801D68B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D68B4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801D68B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801D68BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801D68C0: nop

    // 0x801D68C4: cvt.w.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_D(ctx->f10.d);
    // 0x801D68C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801D68CC: nop

    // 0x801D68D0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801D68D4: beql        $t7, $zero, L_801D6928
    if (ctx->r15 == 0) {
        // 0x801D68D8: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_801D6928;
    }
    goto skip_10;
    // 0x801D68D8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_10:
    // 0x801D68DC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D68E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D68E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D68E8: sub.d       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f10.d - ctx->f4.d;
    // 0x801D68EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801D68F0: nop

    // 0x801D68F4: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x801D68F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801D68FC: nop

    // 0x801D6900: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801D6904: bne         $t7, $zero, L_801D691C
    if (ctx->r15 != 0) {
        // 0x801D6908: nop
    
            goto L_801D691C;
    }
    // 0x801D6908: nop

    // 0x801D690C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801D6910: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D6914: b           L_801D6934
    // 0x801D6918: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801D6934;
    // 0x801D6918: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801D691C:
    // 0x801D691C: b           L_801D6934
    // 0x801D6920: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801D6934;
    // 0x801D6920: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801D6924: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_801D6928:
    // 0x801D6928: nop

    // 0x801D692C: bltz        $t7, L_801D691C
    if (SIGNED(ctx->r15) < 0) {
        // 0x801D6930: nop
    
            goto L_801D691C;
    }
    // 0x801D6930: nop

L_801D6934:
    // 0x801D6934: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801D6938: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x801D693C: bne         $at, $zero, L_801D6878
    if (ctx->r1 != 0) {
        // 0x801D6940: sh          $t7, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r15;
            goto L_801D6878;
    }
    // 0x801D6940: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x801D6944: lhu         $t6, 0xA0($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XA0);
    // 0x801D6948: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D694C: ldc1        $f0, 0x3720($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X3720);
    // 0x801D6950: addiu       $t2, $t6, 0x10E
    ctx->r10 = ADD32(ctx->r14, 0X10E);
    // 0x801D6954: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x801D6958: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801D695C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D6960: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D6964: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801D6968: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D696C: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801D6970: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x801D6974: nop

    // 0x801D6978: sh          $t9, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r25;
    // 0x801D697C: lhu         $t8, 0xA2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XA2);
    // 0x801D6980: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801D6984: bgez        $t8, L_801D699C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801D6988: cvt.d.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
            goto L_801D699C;
    }
    // 0x801D6988: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x801D698C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801D6990: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D6994: nop

    // 0x801D6998: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
L_801D699C:
    // 0x801D699C: div.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D69A0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801D69A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D69A8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D69AC: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x801D69B0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801D69B4: nop

    // 0x801D69B8: sh          $t6, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r14;
    // 0x801D69BC: lhu         $t5, 0xA4($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XA4);
    // 0x801D69C0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801D69C4: bgez        $t5, L_801D69DC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801D69C8: cvt.d.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
            goto L_801D69DC;
    }
    // 0x801D69C8: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x801D69CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801D69D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D69D4: nop

    // 0x801D69D8: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
L_801D69DC:
    // 0x801D69DC: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D69E0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801D69E4: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x801D69E8: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801D69EC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801D69F0: nop

    // 0x801D69F4: sh          $t4, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r12;
    // 0x801D69F8: jal         0x80126944
    // 0x801D69FC: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_8;
    // 0x801D69FC: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_8:
    // 0x801D6A00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D6A04: bne         $v0, $at, L_801D6A6C
    if (ctx->r2 != ctx->r1) {
        // 0x801D6A08: lw          $t0, 0xBC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XBC);
            goto L_801D6A6C;
    }
    // 0x801D6A08: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801D6A0C: lbu         $t2, 0x9C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X9C);
    // 0x801D6A10: beql        $t2, $zero, L_801D6A70
    if (ctx->r10 == 0) {
        // 0x801D6A14: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_801D6A70;
    }
    goto skip_11;
    // 0x801D6A14: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_11:
    // 0x801D6A18: jal         0x80006214
    // 0x801D6A1C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_9;
    // 0x801D6A1C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_9:
    // 0x801D6A20: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801D6A24: lw          $t6, -0x2574($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2574);
    // 0x801D6A28: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801D6A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6A30: lw          $t3, 0x2C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X2C);
    // 0x801D6A34: lbu         $t5, 0x4B($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X4B);
    // 0x801D6A38: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x801D6A3C: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x801D6A40: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x801D6A44: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x801D6A48: mflo        $t8
    ctx->r24 = lo;
    // 0x801D6A4C: sb          $t8, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r24;
    // 0x801D6A50: jal         0x80006214
    // 0x801D6A54: nop

    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x801D6A54: nop

    after_10:
    // 0x801D6A58: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801D6A5C: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x801D6A60: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x801D6A64: b           L_801D6AB0
    // 0x801D6A68: sb          $t4, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r12;
        goto L_801D6AB0;
    // 0x801D6A68: sb          $t4, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r12;
L_801D6A6C:
    // 0x801D6A6C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_801D6A70:
    // 0x801D6A70: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x801D6A74: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801D6A78: b           L_801D6AB0
    // 0x801D6A7C: sb          $t6, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r14;
        goto L_801D6AB0;
    // 0x801D6A7C: sb          $t6, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r14;
L_801D6A80:
    // 0x801D6A80: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801D6A84: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801D6A88: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x801D6A8C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801D6A90: lw          $t4, 0x30($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X30);
    // 0x801D6A94: sh          $t8, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r24;
    // 0x801D6A98: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801D6A9C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D6AA0: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801D6AA4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801D6AA8: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801D6AAC: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
L_801D6AB0:
    // 0x801D6AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D6AB4:
    // 0x801D6AB4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801D6AB8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801D6ABC: jr          $ra
    // 0x801D6AC0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x801D6AC0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d6ac4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d6ac4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6AC4: nop

    // 0x801D6AC8: nop

    // 0x801D6ACC: nop

;}
RECOMP_FUNC void M8_FUN_801d6ad0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6AD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6AD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D6AD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D6ADC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D6AE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D6AE4: jal         0x80133A24
    // 0x801D6AE8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6AE8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x801D6AEC: beq         $v0, $zero, L_801D6B04
    if (ctx->r2 == 0) {
        // 0x801D6AF0: nop
    
            goto L_801D6B04;
    }
    // 0x801D6AF0: nop

    // 0x801D6AF4: jal         0x80133A24
    // 0x801D6AF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_1;
    // 0x801D6AF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x801D6AFC: beql        $v0, $zero, L_801D6B18
    if (ctx->r2 == 0) {
        // 0x801D6B00: lbu         $t6, 0x90($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X90);
            goto L_801D6B18;
    }
    goto skip_0;
    // 0x801D6B00: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    skip_0:
L_801D6B04:
    // 0x801D6B04: jal         0x80133A24
    // 0x801D6B08: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_2;
    // 0x801D6B08: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x801D6B0C: beql        $v0, $zero, L_801D6B44
    if (ctx->r2 == 0) {
        // 0x801D6B10: lbu         $t8, 0x90($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X90);
            goto L_801D6B44;
    }
    goto skip_1;
    // 0x801D6B10: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    skip_1:
    // 0x801D6B14: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
L_801D6B18:
    // 0x801D6B18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6B1C: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6B20: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D6B24: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D6B28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D6B2C: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801D6B30: jal         0x8012C97C
    // 0x801D6B34: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_3;
    // 0x801D6B34: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    after_3:
    // 0x801D6B38: b           L_801D6B68
    // 0x801D6B3C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
        goto L_801D6B68;
    // 0x801D6B3C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801D6B40: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
L_801D6B44:
    // 0x801D6B44: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6B48: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6B4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D6B50: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801D6B54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D6B58: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x801D6B5C: jal         0x8012C97C
    // 0x801D6B60: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_4;
    // 0x801D6B60: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    after_4:
    // 0x801D6B64: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_801D6B68:
    // 0x801D6B68: jal         0x80133A24
    // 0x801D6B6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_5;
    // 0x801D6B6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x801D6B70: beq         $v0, $zero, L_801D6BB0
    if (ctx->r2 == 0) {
        // 0x801D6B74: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_801D6BB0;
    }
    // 0x801D6B74: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6B78: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x801D6B7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D6B80: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6B84: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D6B88: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801D6B8C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D6B90: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x801D6B94: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801D6B98: jal         0x8012C97C
    // 0x801D6B9C: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_6;
    // 0x801D6B9C: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    after_6:
    // 0x801D6BA0: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801D6BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6BA8: jal         0x80150314
    // 0x801D6BAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_7;
    // 0x801D6BAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
L_801D6BB0:
    // 0x801D6BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D6BB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D6BB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6BBC: jr          $ra
    // 0x801D6BC0: nop

    return;
    // 0x801D6BC0: nop

;}
RECOMP_FUNC void M8_FUN_801d6bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6BC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6BC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D6BCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D6BD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D6BD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D6BD8: jal         0x80133A24
    // 0x801D6BDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6BDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801D6BE0: beql        $v0, $zero, L_801D6C18
    if (ctx->r2 == 0) {
        // 0x801D6BE4: lbu         $t8, 0x90($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X90);
            goto L_801D6C18;
    }
    goto skip_0;
    // 0x801D6BE4: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    skip_0:
    // 0x801D6BE8: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x801D6BEC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6BF0: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6BF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D6BF8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D6BFC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D6C00: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801D6C04: jal         0x8012C97C
    // 0x801D6C08: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_1;
    // 0x801D6C08: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    after_1:
    // 0x801D6C0C: b           L_801D6C3C
    // 0x801D6C10: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
        goto L_801D6C3C;
    // 0x801D6C10: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801D6C14: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
L_801D6C18:
    // 0x801D6C18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6C1C: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6C20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D6C24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801D6C28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D6C2C: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x801D6C30: jal         0x8012C97C
    // 0x801D6C34: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_2;
    // 0x801D6C34: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    after_2:
    // 0x801D6C38: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_801D6C3C:
    // 0x801D6C3C: jal         0x80133A24
    // 0x801D6C40: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_3;
    // 0x801D6C40: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x801D6C44: beq         $v0, $zero, L_801D6C84
    if (ctx->r2 == 0) {
        // 0x801D6C48: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_801D6C84;
    }
    // 0x801D6C48: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6C4C: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x801D6C50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D6C54: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6C58: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D6C5C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801D6C60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D6C64: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x801D6C68: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801D6C6C: jal         0x8012C97C
    // 0x801D6C70: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_4;
    // 0x801D6C70: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    after_4:
    // 0x801D6C74: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801D6C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6C7C: jal         0x80150314
    // 0x801D6C80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_5;
    // 0x801D6C80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_801D6C84:
    // 0x801D6C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D6C88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D6C8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6C90: jr          $ra
    // 0x801D6C94: nop

    return;
    // 0x801D6C94: nop

;}
RECOMP_FUNC void M8_FUN_801d6c98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6C98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6C9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D6CA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D6CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D6CA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D6CAC: jal         0x80133A24
    // 0x801D6CB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6CB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801D6CB4: beql        $v0, $zero, L_801D6D00
    if (ctx->r2 == 0) {
        // 0x801D6CB8: lbu         $t8, 0x90($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X90);
            goto L_801D6D00;
    }
    goto skip_0;
    // 0x801D6CB8: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    skip_0:
    // 0x801D6CBC: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x801D6CC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6CC4: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6CC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D6CCC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D6CD0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D6CD4: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801D6CD8: jal         0x8012C97C
    // 0x801D6CDC: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_1;
    // 0x801D6CDC: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    after_1:
    // 0x801D6CE0: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801D6CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6CE8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801D6CEC: jal         0x8012D844
    // 0x801D6CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D6CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x801D6CF4: b           L_801D6D38
    // 0x801D6CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D6D38;
    // 0x801D6CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D6CFC: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
L_801D6D00:
    // 0x801D6D00: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D6D04: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D6D08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D6D0C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801D6D10: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D6D14: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x801D6D18: jal         0x8012C97C
    // 0x801D6D1C: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_3;
    // 0x801D6D1C: lhu         $a1, 0x295C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295C);
    after_3:
    // 0x801D6D20: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801D6D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6D28: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801D6D2C: jal         0x8012D844
    // 0x801D6D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D6D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801D6D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D6D38:
    // 0x801D6D38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D6D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6D40: jr          $ra
    // 0x801D6D44: nop

    return;
    // 0x801D6D44: nop

;}
RECOMP_FUNC void M8_FUN_801d6d48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6D50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6D54: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801D6D58: jal         0x8012D844
    // 0x801D6D5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D6D5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x801D6D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D6D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6D68: jr          $ra
    // 0x801D6D6C: nop

    return;
    // 0x801D6D6C: nop

;}
